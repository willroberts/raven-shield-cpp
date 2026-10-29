#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"
#include "module_data.h"

// R6Game.dll data @ 100241a8 : shared score-submission gate
int ScoreSubmissionGate = 0;

// R6Game.dll data @ 100241ac : shared active score-submission state
int ScoreSubmissionActive = 0;

// R6Game.dll data @ 100240f0 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execSetController.
unsigned int intAR6GameInfoexecSetController = R6GameAddresses::AR6GameInfo_execSetController;

// R6Game.dll data @ 100240f4 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execNativeLogout.
unsigned int intAR6GameInfoexecNativeLogout = R6GameAddresses::AR6GameInfo_execNativeLogout;

// R6Game.dll data @ 100240f8 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execGetSystemUserName.
unsigned int intAR6GameInfoexecGetSystemUserName = R6GameAddresses::AR6GameInfo_execGetSystemUserName;

// R6Game.dll data @ 100240fc : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execInitScoreSubmission.
unsigned int intAR6GameInfoexecInitScoreSubmission = R6GameAddresses::AR6GameInfo_execInitScoreSubmission;

// R6Game.dll data @ 10024100 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execSubmissionSrvRoundStart.
unsigned int intAR6GameInfoexecSubmissionSrvRoundStart = R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStart;

// R6Game.dll data @ 10024104 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execSubmissionNotifySendStartMatch.
unsigned int intAR6GameInfoexecSubmissionNotifySendStartMatch = R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatch;

// R6Game.dll data @ 10024108 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execSubmissionSrvRoundFinish.
unsigned int intAR6GameInfoexecSubmissionSrvRoundFinish = R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinish;

// R6Game.dll data @ 1002410c : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execLogoutUpdatePlayersCtrlInfo.
unsigned int intAR6GameInfoexecLogoutUpdatePlayersCtrlInfo = R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfo;

// R6Game.dll data @ 10024110 : native exec pointer word
// Writable native-member-pointer DWORD with a loader HIGHLOW relocation to AR6GameInfo::execSubmissionUpdateLadderStat.
unsigned int intAR6GameInfoexecSubmissionUpdateLadderStat = R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStat;

// R6Game.dll data @ 100241b0 : auto-class pointer
UClass* autoclassAR6GameInfo = nullptr;

// R6Game.dll data @ 100241b4 : native registration result byte
unsigned char AR6GameInfoexecInitScoreSubmissionRegistrationResult = 0;

// R6Game.dll data @ 100241b5 : native registration result byte
unsigned char AR6GameInfoexecNativeLogoutRegistrationResult = 0;

// R6Game.dll data @ 100241b6 : native registration result byte
unsigned char AR6GameInfoexecSubmissionUpdateLadderStatRegistrationResult = 0;

// R6Game.dll data @ 100241b8 : class metadata storage
// Backing storage for AR6GameInfo::PrivateStaticClass; construction and cleanup are explicit below.
alignas(8) unsigned char AR6GameInfoClassMetadataStorage[0x508] = {};

// R6Game.dll data @ 100246c0 : native registration result byte
unsigned char AR6GameInfoexecSubmissionNotifySendStartMatchRegistrationResult = 0;

// R6Game.dll data @ 100246c1 : native registration result byte
unsigned char AR6GameInfoexecLogoutUpdatePlayersCtrlInfoRegistrationResult = 0;

// R6Game.dll data @ 100246c2 : native registration result byte
unsigned char AR6GameInfoexecGetSystemUserNameRegistrationResult = 0;

// R6Game.dll data @ 100246c3 : native registration result byte
unsigned char AR6GameInfoexecSetControllerRegistrationResult = 0;

// R6Game.dll data @ 100246c4 : native registration result byte
unsigned char AR6GameInfoexecSubmissionSrvRoundFinishRegistrationResult = 0;

// R6Game.dll data @ 100246c5 : native registration result byte
unsigned char AR6GameInfoexecSubmissionSrvRoundStartRegistrationResult = 0;

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 10019d94 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_MasterServerManagerUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 10019da4 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_MasterServerManagerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_MasterServerManagerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_MasterServerManagerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019dc4 : native C++ try-block ranges
const unsigned int AR6GameInfo_MasterServerManagerTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_MasterServerManagerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019dd8 : native C++ exception function descriptor
const unsigned int AR6GameInfo_MasterServerManagerExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_MasterServerManagerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_MasterServerManagerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10019df4 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execNativeLogoutUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 10019e04 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execNativeLogoutCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6GameInfo_execNativeLogoutCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execNativeLogoutCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019e24 : native C++ try-block ranges
const unsigned int AR6GameInfo_execNativeLogoutTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execNativeLogoutCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019e38 : native C++ exception function descriptor
const unsigned int AR6GameInfo_execNativeLogoutExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execNativeLogoutUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execNativeLogoutTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10019e54 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execGetSystemUserNameUnwindMap[6] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6GameInfo_execGetSystemUserNameUnwind1, // State 1: previous state, cleanup action.
    0xffffffff, 0x0, // State 2: previous state, cleanup action.
};

// R6Game.dll data @ 10019e6c : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execGetSystemUserNameCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_execGetSystemUserNameCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execGetSystemUserNameCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019e8c : native C++ try-block ranges
const unsigned int AR6GameInfo_execGetSystemUserNameTryMap[5] = {
    0x0, 0x1, 0x2, 0x2, R6GameAddresses::AR6GameInfo_execGetSystemUserNameCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019ea0 : native C++ exception function descriptor
const unsigned int AR6GameInfo_execGetSystemUserNameExceptionInfo[7] = {
    0x19930520, 0x3, R6GameAddresses::AR6GameInfo_execGetSystemUserNameUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execGetSystemUserNameTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10019ebc : native C++ unwind-state transitions
const unsigned int AR6GameInfo_AbortScoreSubmissionUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 10019ecc : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_AbortScoreSubmissionCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_AbortScoreSubmissionCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_AbortScoreSubmissionCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019eec : native C++ try-block ranges
const unsigned int AR6GameInfo_AbortScoreSubmissionTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_AbortScoreSubmissionCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019f00 : native C++ exception function descriptor
const unsigned int AR6GameInfo_AbortScoreSubmissionExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_AbortScoreSubmissionUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_AbortScoreSubmissionTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10019f1c : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execSubmissionSrvRoundStartUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 10019f2c : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execSubmissionSrvRoundStartCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019f4c : native C++ try-block ranges
const unsigned int AR6GameInfo_execSubmissionSrvRoundStartTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019f60 : native C++ exception function descriptor
const unsigned int AR6GameInfo_execSubmissionSrvRoundStartExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10019f7c : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execSubmissionSrvRoundFinishUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 10019f8c : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execSubmissionSrvRoundFinishCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 10019fac : native C++ try-block ranges
const unsigned int AR6GameInfo_execSubmissionSrvRoundFinishTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 10019fc0 : native C++ exception function descriptor
const unsigned int AR6GameInfo_execSubmissionSrvRoundFinishExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a148 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_InitGameInfoGameServiceUnwindMap[8] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceUnwind2, // State 2: previous state, cleanup action.
    0xffffffff, 0x0, // State 3: previous state, cleanup action.
};

// R6Game.dll data @ 1001a168 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_InitGameInfoGameServiceCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe8, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a188 : native C++ try-block ranges
const unsigned int AR6GameInfo_InitGameInfoGameServiceTryMap[5] = {
    0x0, 0x2, 0x3, 0x2, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a19c : native C++ exception function descriptor
const unsigned int AR6GameInfo_InitGameInfoGameServiceExceptionInfo[7] = {
    0x19930520, 0x4, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a1b8 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execSetControllerUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a1c8 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execSetControllerCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6GameInfo_execSetControllerCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execSetControllerCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a1e8 : native C++ try-block ranges
const unsigned int AR6GameInfo_execSetControllerTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execSetControllerCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a1fc : native C++ exception function descriptor
const unsigned int AR6GameInfo_execSetControllerExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execSetControllerUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execSetControllerTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a218 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execInitScoreSubmissionUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a228 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execInitScoreSubmissionCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::AR6GameInfo_execInitScoreSubmissionCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execInitScoreSubmissionCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a248 : native C++ try-block ranges
const unsigned int AR6GameInfo_execInitScoreSubmissionTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execInitScoreSubmissionCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a25c : native C++ exception function descriptor
const unsigned int AR6GameInfo_execInitScoreSubmissionExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execInitScoreSubmissionUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execInitScoreSubmissionTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a278 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execSubmissionNotifySendStartMatchUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a288 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execSubmissionNotifySendStartMatchCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a2a8 : native C++ try-block ranges
const unsigned int AR6GameInfo_execSubmissionNotifySendStartMatchTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a2bc : native C++ exception function descriptor
const unsigned int AR6GameInfo_execSubmissionNotifySendStartMatchExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a2d8 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execLogoutUpdatePlayersCtrlInfoUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a2e8 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe0, R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a308 : native C++ try-block ranges
const unsigned int AR6GameInfo_execLogoutUpdatePlayersCtrlInfoTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a31c : native C++ exception function descriptor
const unsigned int AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a338 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_execSubmissionUpdateLadderStatUnwindMap[4] = {
    0xffffffff, 0x0, // State 0: previous state, cleanup action.
    0xffffffff, 0x0, // State 1: previous state, cleanup action.
};

// R6Game.dll data @ 1001a348 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_execSubmissionUpdateLadderStatCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffdc, R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001a368 : native C++ try-block ranges
const unsigned int AR6GameInfo_execSubmissionUpdateLadderStatTryMap[5] = {
    0x0, 0x0, 0x1, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001a37c : native C++ exception function descriptor
const unsigned int AR6GameInfo_execSubmissionUpdateLadderStatExceptionInfo[7] = {
    0x19930520, 0x2, R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a890 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_DestructUnwindMap[24] = {
    0xffffffff, R6GameAddresses::AR6GameInfo_DestructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6GameInfo_DestructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6GameInfo_DestructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6GameInfo_DestructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6GameInfo_DestructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6GameInfo_DestructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6GameInfo_DestructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::AR6GameInfo_DestructUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::AR6GameInfo_DestructUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::AR6GameInfo_DestructUnwind9, // State 9: previous state, cleanup action.
    0x9, R6GameAddresses::AR6GameInfo_DestructUnwind10, // State 10: previous state, cleanup action.
    0xa, R6GameAddresses::AR6GameInfo_DestructUnwind11, // State 11: previous state, cleanup action.
};

// R6Game.dll data @ 1001a8f0 : native C++ exception function descriptor
const unsigned int AR6GameInfo_DestructExceptionInfo[7] = {
    0x19930520, 0xc, R6GameAddresses::AR6GameInfo_DestructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001a90c : native C++ unwind-state transitions
const unsigned int AR6GameInfo_CopyConstructUnwindMap[22] = {
    0xffffffff, R6GameAddresses::AR6GameInfo_CopyConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6GameInfo_CopyConstructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6GameInfo_CopyConstructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6GameInfo_CopyConstructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6GameInfo_CopyConstructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6GameInfo_CopyConstructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6GameInfo_CopyConstructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::AR6GameInfo_CopyConstructUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::AR6GameInfo_CopyConstructUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::AR6GameInfo_CopyConstructUnwind9, // State 9: previous state, cleanup action.
    0x9, R6GameAddresses::AR6GameInfo_CopyConstructUnwind10, // State 10: previous state, cleanup action.
};

// R6Game.dll data @ 1001a964 : native C++ exception function descriptor
const unsigned int AR6GameInfo_CopyConstructExceptionInfo[7] = {
    0x19930520, 0xb, R6GameAddresses::AR6GameInfo_CopyConstructUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 1001ac94 : native C++ unwind-state transitions
const unsigned int AR6GameInfo_ConstructUnwindMap[28] = {
    0xffffffff, R6GameAddresses::AR6GameInfo_ConstructUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::AR6GameInfo_ConstructUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::AR6GameInfo_ConstructUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::AR6GameInfo_ConstructUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::AR6GameInfo_ConstructUnwind4, // State 4: previous state, cleanup action.
    0x4, R6GameAddresses::AR6GameInfo_ConstructUnwind5, // State 5: previous state, cleanup action.
    0x5, R6GameAddresses::AR6GameInfo_ConstructUnwind6, // State 6: previous state, cleanup action.
    0x6, R6GameAddresses::AR6GameInfo_ConstructUnwind7, // State 7: previous state, cleanup action.
    0x7, R6GameAddresses::AR6GameInfo_ConstructUnwind8, // State 8: previous state, cleanup action.
    0x8, R6GameAddresses::AR6GameInfo_ConstructUnwind9, // State 9: previous state, cleanup action.
    0x9, R6GameAddresses::AR6GameInfo_ConstructUnwind10, // State 10: previous state, cleanup action.
    0xa, R6GameAddresses::AR6GameInfo_ConstructUnwind11, // State 11: previous state, cleanup action.
    0xb, 0x0, // State 12: previous state, cleanup action.
    0xb, 0x0, // State 13: previous state, cleanup action.
};

// R6Game.dll data @ 1001ad04 : native typed-pointer and catch-all handler pair
const unsigned int AR6GameInfo_ConstructCatchHandlers[8] = {
    0x0, R6GameAddresses::UnsignedShortPointerTypeDescriptor, 0xffffffe4, R6GameAddresses::AR6GameInfo_ConstructCatchPointer, // Typed: adjectives, type, signed frame offset, action.
    0x0, 0x0, 0x0, R6GameAddresses::AR6GameInfo_ConstructCatchContext, // Catch-all: adjectives, type, signed frame offset, action.
};

// R6Game.dll data @ 1001ad24 : native C++ try-block ranges
const unsigned int AR6GameInfo_ConstructTryMap[5] = {
    0xc, 0xc, 0xd, 0x2, R6GameAddresses::AR6GameInfo_ConstructCatchHandlers, // Try 0: low/high/catch-high state, count, handler array.
};

// R6Game.dll data @ 1001ad38 : native C++ exception function descriptor
const unsigned int AR6GameInfo_ConstructExceptionInfo[7] = {
    0x19930520, 0xe, R6GameAddresses::AR6GameInfo_ConstructUnwindMap, // Magic, state count, unwind map.
    0x1, R6GameAddresses::AR6GameInfo_ConstructTryMap, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll data @ 10017790 : AR6GameInfo virtual-function table
// Preferred-VA code-pointer DWORDs; every native slot has a PE HIGHLOW relocation.
extern const uint AR6GameInfo_vftable[100] = {
    R6GameAddresses::ForwardImported_UObject_QueryInterface, // +0x0: UObject::QueryInterface
    R6GameAddresses::ForwardImported_UObject_AddRef, // +0x4: UObject::AddRef
    R6GameAddresses::ForwardImported_UObject_Release, // +0x8: UObject::Release
    R6GameAddresses::AR6GameInfo_VectorDeletingDestructor, // +0xc: AR6GameInfo::VectorDeletingDestructor
    R6GameAddresses::ForwardImported_AActor_ProcessEvent, // +0x10: AActor::ProcessEvent
    R6GameAddresses::ForwardImported_UObject_ProcessDelegate, // +0x14: UObject::ProcessDelegate
    R6GameAddresses::ForwardImported_AActor_ProcessState, // +0x18: AActor::ProcessState
    R6GameAddresses::ForwardImported_AActor_ProcessRemoteFunction, // +0x1c: AActor::ProcessRemoteFunction
    R6GameAddresses::ForwardImported_UObject_Modify, // +0x20: UObject::Modify
    R6GameAddresses::ForwardImported_AActor_PostLoad, // +0x24: AActor::PostLoad
    R6GameAddresses::ForwardImported_AActor_Destroy, // +0x28: AActor::Destroy
    R6GameAddresses::ForwardImported_AActor_Serialize, // +0x2c: AActor::Serialize
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
    R6GameAddresses::ForwardImported_AActor_Spawned, // +0x90: AActor::Spawned
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
    R6GameAddresses::AR6GameInfo_PostBeginPlay, // +0x118: PostBeginPlay
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
    R6GameAddresses::AR6GameInfo_InitGameInfoGameService, // +0x184: InitGameInfoGameService
    R6GameAddresses::AR6GameInfo_MasterServerManager, // +0x188: AR6GameInfo::MasterServerManager
    R6GameAddresses::AR6GameInfo_AbortScoreSubmission, // +0x18c: AbortScoreSubmission
};

// R6Game.dll @ 10001200 : MasterServerManager
// Dispatches master-server management with the game and current level information.
void __thiscall AR6GameInfo::MasterServerManager(AR6GameInfo* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_MasterServerManagerExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    const bool hadGameService = this->m_GameService != nullptr;
    exceptionRegistration.state = 0; // FuncInfo 0x10019dd8 has no local cleanup actions.
    if (!hadGameService) {
        FOutputDevice* log = *(FOutputDevice**)ImportedGLogAddress;
        FOutputDevice::Logf(log, L"The engine should crash, gameinfo gameservice is not valid");
    } else {
        ALevelInfo* levelInfo = ULevel::GetLevelInfo(this->XLevel);
        UR6GSServers* service = this->m_GameService;
        auto manageServer = *(void (__thiscall**)(UR6GSServers*, AR6AbstractGameInfo*, ALevelInfo*))
            (*(byte**)service + 0xb0);
        manageServer(service, (AR6AbstractGameInfo*)this, levelInfo);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10001288 : rethrow MasterServerManager's caught four-byte value
__declspec(naked) void AR6GameInfo_MasterServerManagerCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000129c : report MasterServerManager context and rethrow the active exception
__declspec(naked) void AR6GameInfo_MasterServerManagerCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6GameInfo_MasterServerManagerExceptionContext // L"AR6GameInfo::MasterServerManager"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100012e0 : execNativeLogout
// Sends the exiting player's authorization ID to the service outside pending level transitions.
void __thiscall AR6GameInfo::execNativeLogout(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execNativeLogoutExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* argumentCode = *codeCursor;
    APlayerController* exiting = nullptr;
    byte opcode = *argumentCode;
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* receiver = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    nativeTable[opcode](receiver, stack, &exiting);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        receiver = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](receiver, stack, nullptr);
    }
    if (this->Level->NetMode != 0) {
        APlayerController* exitingController = exiting;
        if (exitingController != nullptr &&
            (*(uint*)((byte*)this + 0x3b4) & 0x200000U) == 0) { // m_bPendingLevelExists.
            const FString* authorizationSource =
                (const FString*)&exitingController->m_stPlayerVerCDKeyStatus.m_szAuthorizationID; // +0x69c.
            // Construct directly in the outgoing 12-byte value; slot +0x94 consumes and owns that same FString.
            __asm {
                mov eax,authorizationSource
                sub esp,0xc
                mov ecx,esp
                mov dword ptr [ebp-0x1c],esp // Native temporary argument-storage binding.
                push eax
                call dword ptr ds:R6GameAddresses::Core_FString_CopyConstructorSlot // FString const-reference copy constructor.
                mov eax,this
                mov ecx,dword ptr [eax+0x5c8] // Reload m_GameService after construction.
                mov edx,dword ptr [ecx]
                call dword ptr [edx+0x94] // CDKeyDisconnecUser; callee removes the three FString words.
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100013a3 : rethrow execNativeLogout's caught four-byte value
__declspec(naked) void AR6GameInfo_execNativeLogoutCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 100013b7 : report execNativeLogout's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execNativeLogoutCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execNativeLogoutExceptionContext // L"AR6GameInfo::execNativeLogout"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10001410 : execGetSystemUserName
// Assigns the system username to the evaluated string reference and releases fallback storage.
void __thiscall AR6GameInfo::execGetSystemUserName(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execGetSystemUserNameExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    exceptionRegistration.state = 0;
    alignas(4) byte fallbackStorage[12];
    FString* fallback = (FString*)fallbackStorage;
    FString::FString(fallback);
    byte** propertyAddress = (byte**)ImportedGPropAddrAddress;
    FFrame* evaluationFrame = stack;
    *propertyAddress = nullptr;
    byte** codeCursor = (byte**)((byte*)evaluationFrame + 0xc);
    byte* argumentCode = *codeCursor;
    byte opcode = *argumentCode;
    UObject *receiver = *(UObject **)((byte *)evaluationFrame + 8);
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    *(byte*)&exceptionRegistration.state = 1; // FuncInfo 0x10019ea0 unwinds fallback at EBP-0x24 through 0x100134a0.
    nativeTable[opcode](receiver, evaluationFrame, fallback);
    UObject* propertyObject = *(UObject**)ImportedGPropObjectAddress;
    if (propertyObject != nullptr) {
        UProperty* property = *(UProperty**)ImportedGPropertyAddress;
        auto markDirty = *(void (__thiscall**)(UObject*, UProperty*))(*(byte**)propertyObject + 0x60);
        markDirty(propertyObject, property); // NetDirty.
    }
    // Captures the post-NetDirty destination before DebugInfo and appUserName can change global references.
    FString* szUserName = *(FString**)ImportedGPropAddrAddress;
    if (szUserName == nullptr)
        szUserName = fallback;
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        receiver = *(UObject **)((byte *)evaluationFrame + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative debugInfo = ((ScriptNative *)ImportedGNativesAddress)[0x42];
        debugInfo(receiver, evaluationFrame, nullptr);
    }
    const ushort* systemUserName = appUserName();
    FString::operator=(szUserName, systemUserName);
    *(byte*)&exceptionRegistration.state = 0;
    FString::~FString(fallback);
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100014ea : rethrow execGetSystemUserName's caught four-byte value
__declspec(naked) void AR6GameInfo_execGetSystemUserNameCatchPointer(void)
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

// R6Game.dll @ 100014fe : report execGetSystemUserName's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execGetSystemUserNameCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execGetSystemUserNameExceptionContext // L"AR6GameInfo::execGetSystemUserName"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10001550 : abort an active score submission through the persistent service
// Clears the submission gate before calling persistent-service slot +0x88; the native call has no null guard.
void __thiscall AR6GameInfo::AbortScoreSubmission(AR6GameInfo* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_AbortScoreSubmissionExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // The handler saves native ESP at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    const bool hadActiveSubmission = ScoreSubmissionActive != 0;
    exceptionRegistration.state = 0;
    if (hadActiveSubmission) {
        ScoreSubmissionActive = 0;
        UR6GSServers* service = this->m_PersistantGameService;
        auto finishRound = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x88);
        finishRound(service); // ServerRoundFinish.
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100015aa : rethrow AbortScoreSubmission's caught four-byte value
__declspec(naked) void AR6GameInfo_AbortScoreSubmissionCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100015be : report AbortScoreSubmission context and rethrow the active exception
__declspec(naked) void AR6GameInfo_AbortScoreSubmissionCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6GameInfo_AbortScoreSubmissionExceptionContext // L"AR6GameInfo::AbortScoreSubmission"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100015e0 : execSubmissionSrvRoundStart
// Applies submission gates, dispatches slot +0x84 with the game mode, and conditionally logs afterward.
// Native ABI is RET 8.
void __thiscall AR6GameInfo::execSubmissionSrvRoundStart(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execSubmissionSrvRoundStartExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    bool hasDebugInfo = *nextCode == 0x42;
    exceptionRegistration.state = 0;
    if (hasDebugInfo) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    if (ScoreSubmissionGate != 0 && (*(uint*)((byte*)this + 0x3b4) & 0x20000U) != 0) { // m_bCompilingStats.
        UClass* actorClass = *(UClass**)R6GameImports::Engine_AActor_PrivateStaticClassSlot;
        AActor* defaultActor = UClass::GetDefaultActor(actorClass);
        bool submissionAllowed = AActor::NativeStartedByGSClient(defaultActor) != 0;
        if (!submissionAllowed) {
            UR6GSServers* service = this->m_PersistantGameService;
            auto isRegistered = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x80);
            submissionAllowed = isRegistered(service) != 0;
        }
        if (submissionAllowed) {
            UR6GSServers* service = this->m_PersistantGameService;
            int gameMode = this->m_iUbiComGameMode; // +0x58c.
            auto startRound = *(void (__thiscall**)(UR6GSServers*, int))(*(byte**)service + 0x84);
            startRound(service, gameMode);
            if ((*(byte*)((byte*)this + 0x590) & 1U) != 0) { // bShowLog.
                FOutputDevice* log = *(FOutputDevice**)ImportedGLogAddress;
                FOutputDevice::Logf(log,
                    L"We need to wait for score submission synchro, going to state GSClientWaitForRoundStart");
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100016b4 : rethrow execSubmissionSrvRoundStart's caught four-byte value
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundStartCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100016c8 : report execSubmissionSrvRoundStart's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundStartCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundStartExceptionContext // L"AR6GameInfo::execSubmissionSrvRoundStart"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10001720 : execSubmissionSrvRoundFinish
// Tests GS-client status, falls back to service registration, and clears the gate before slot +0x88.
// Native ABI is RET 8.
void __thiscall AR6GameInfo::execSubmissionSrvRoundFinish(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execSubmissionSrvRoundFinishExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    bool hasDebugInfo = *nextCode == 0x42;
    exceptionRegistration.state = 0;
    if (hasDebugInfo) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    if ((*(byte*)((byte*)this + 0x4e4) & 0x10U) != 0 && ScoreSubmissionActive != 0) { // m_bInternetSvr.
        UClass* actorClass = *(UClass**)R6GameImports::Engine_AActor_PrivateStaticClassSlot;
        AActor* defaultActor = UClass::GetDefaultActor(actorClass);
        bool submissionAllowed = AActor::NativeStartedByGSClient(defaultActor) != 0;
        if (!submissionAllowed) {
            UR6GSServers* service = this->m_PersistantGameService;
            auto isRegistered = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x80);
            submissionAllowed = isRegistered(service) != 0;
        }
        if (submissionAllowed) {
            ScoreSubmissionActive = 0;
            UR6GSServers* service = this->m_PersistantGameService;
            auto finishRound = *(void (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x88);
            finishRound(service);
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100017cd : rethrow execSubmissionSrvRoundFinish's caught four-byte value
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundFinishCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100017e1 : report execSubmissionSrvRoundFinish's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundFinishCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execSubmissionSrvRoundFinishExceptionContext // L"AR6GameInfo::execSubmissionSrvRoundFinish"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov eax,dword ptr [esi+0xc]
        mov edx,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub eax,edx // Bytecode offset modulo 32 bits.
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100018c0 : return the AR6GameInfo class object
UClass* __cdecl AR6GameInfo::StaticClass(void)
{
    return (UClass*)AR6GameInfoClassMetadataStorage;
}

// R6Game.dll @ 100018d0 : allocate an object using this class and the supplied outer, name and flags
void* __cdecl AR6GameInfo::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    // Native code ignores allocationSize; the class metadata supplies the object size.
    FOutputDevice* error = *(FOutputDevice**)ImportedGErrorAddress;
    return UObject::StaticAllocateObject((UClass*)AR6GameInfoClassMetadataStorage, outer, objectName, objectFlags,
        nullptr, error, nullptr, 0);
}

// R6Game.dll @ 10002f50 : update multiplayer service login state after play begins
// Sets service login flags for multiplayer games with nonzero group and lobby identifiers.
void __thiscall AR6GameInfo::PostBeginPlay(AR6GameInfo* this)
{
    if (this->m_GameService == nullptr)
        return;
    UClass* classCursor = *(UClass**)((byte*)this + 0x24);
    while (classCursor != nullptr && classCursor != (UClass*)AR6MultiPlayerGameInfoClassMetadataStorage)
        classCursor = *(UClass**)((byte*)classCursor + 0x2c);
    if (classCursor == nullptr)
        return;
    UR6GSServers* service = this->m_GameService;
    auto getGroupId = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xf0);
    if (getGroupId(service) == 0)
        return;
    service = this->m_GameService;
    auto getLobbyId = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0xec);
    if (getLobbyId(service) == 0)
        return;
    service = this->m_GameService;
    auto setLoginRegServer = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0x78);
    setLoginRegServer(service, 2);
    service = this->m_GameService;
    auto setRegServerLoginRequest = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0x74);
    setRegServerLoginRequest(service, 0);
}

// R6Game.dll @ 10002fc0 : InitGameInfoGameService
// Constructs the game-info service and initializes its dedicated-server and multiplayer registration state.
void __thiscall AR6GameInfo::InitGameInfoGameService(AR6GameInfo* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_InitGameInfoGameServiceExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    UClass* requiredBase = (UClass*)ImportedUR6AbstractGameServiceClass;
    exceptionRegistration.state = 0;
    UClass* serviceClass = UObject::StaticLoadClass(requiredBase, nullptr,
        (ushort*)L"R6GameService.R6GSServers", nullptr, 1, nullptr);
    UClass* assertedBase = (UClass*)ImportedUR6AbstractGameServiceClass;
    if (UStruct::IsChildOf((UStruct*)serviceClass, (UStruct*)assertedBase) == 0)
        appFailAssert("Class->IsChildOf(T::StaticClass())", R"(d:\ravenshield\412\core\inc\UnObjBas.h)", 0x476);
    UPackage* outer = UObject::GetTransientPackage();
    UR6GSServers* constructedService = (UR6GSServers*)UObject::StaticConstructObject(serviceClass, outer,
        FName(0), 0, nullptr, *(FOutputDevice**)ImportedGErrorAddress, 0);
    this->m_GameService = constructedService;
    if (constructedService == nullptr) {
        using LogfCall = void (__cdecl *)(FOutputDevice*, const ushort*, ...);
        ((LogfCall)FOutputDevice::Logf)(*(FOutputDevice**)ImportedGLogAddress,
            (const ushort*)L"Unable to initialize the gameservice inside gameinfo");
        __writefsdword(0, exceptionRegistration.previousAddress);
        return;
    }
    UEngine* engine = *(UEngine**)Importedg_pEngineAddress;
    if (engine != nullptr) {
        UClient* client = engine->Client;
        if (client != nullptr) {
            UPlayer* firstPlayer = **(UPlayer***)((byte*)client + 0x30);
            if (firstPlayer != nullptr) {
                UInteraction* console = firstPlayer->Console;
                if (console != nullptr && (*(byte*)((byte*)console + 0x4c) & 0xe0U) != 0) {
                    auto initCDKey = *(int (__thiscall**)(UR6GSServers*))(*(byte**)constructedService + 0x68);
                    initCDKey(constructedService);
                }
            }
        }
    }
    byte netMode = this->Level->NetMode;
    UR6GSServers* service = this->m_GameService;
    uint* serverFlags = (uint*)((byte*)service + 0x48);
    uint oldServerFlags = *serverFlags;
    *serverFlags = oldServerFlags ^ (((netMode == 1 ? 1U : 0U) ^ oldServerFlags) & 1U); // m_bDedicatedServer.
    UClass* cursor = *(UClass**)((byte*)this + 0x24);
    while (cursor != nullptr && cursor != (UClass*)AR6MultiPlayerGameInfoClassMetadataStorage)
        cursor = *(UClass**)((byte*)cursor + 0x2c);
    if (cursor != nullptr) {
        service = this->m_GameService;
        auto isRegistrationInitialized = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x6c);
        if (isRegistrationInitialized(service) == 0) {
            service = this->m_GameService;
            auto setRequestState = *(void (__thiscall**)(UR6GSServers*, byte))(*(byte**)service + 0x70);
            setRequestState(service, 1);
        }
        service = this->m_GameService;
        *(uint*)((byte*)service + 0x194) |= 0x40U; // m_bInitGame.
        ULevel* level = this->XLevel;
        const ushort* host = FString::operator*(&level->URL.Host);
        int port = level->URL.Port;
        alignas(4) byte endpointStorage[12], suffixStorage[12];
        FString* endpoint = (FString*)endpointStorage;
        FString* suffix = (FString*)suffixStorage;
        using PrintfCall = FString* (__cdecl *)(FString*, const ushort*, ...);
        PrintfCall formatEndpoint = *(PrintfCall*)R6GameImports::Core_FString_PrintfSlot;
        formatEndpoint(endpoint, (const ushort*)L"%s:%i", host, port);
        *(byte*)&exceptionRegistration.state = 1;
        int colonIndex = FString::InStr(endpoint, (ushort*)L":", 0);
        using MidCall = FString* (__thiscall *)(FString*, FString*, int, int);
        MidCall getSuffix = *(MidCall*)R6GameImports::Core_FString_MidSlot;
        FString* portText = getSuffix(endpoint, suffix, (int)((uint)colonIndex + 1U), 0x7fffffff);
        *(byte*)&exceptionRegistration.state = 2;
        FString::operator=(endpoint, portText);
        *(byte*)&exceptionRegistration.state = 1;
        FString::~FString(suffix);
        int parsedPort = appAtoi(FString::operator*(endpoint));
        service = this->m_GameService;
        auto setOwnServerPort = *(void (__thiscall**)(UR6GSServers*, int))(*(byte**)service + 0xe8);
        setOwnServerPort(service, parsedPort);
        *(byte*)&exceptionRegistration.state = 0;
        FString::~FString(endpoint);
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100031cd : rethrow InitGameInfoGameService's caught four-byte value
__declspec(naked) void AR6GameInfo_InitGameInfoGameServiceCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100031e1 : report InitGameInfoGameService context and rethrow the active exception
__declspec(naked) void AR6GameInfo_InitGameInfoGameServiceCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6GameInfo_InitGameInfoGameServiceExceptionContext // L"AR6GameInfo::InitGameInfoGameService"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003200 : execSetController
// Attaches the player and controller, initializes viewport input, and fills missing render defaults.
void __thiscall AR6GameInfo::execSetController(AR6GameInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execSetControllerExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10; this is unused.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* controllerCode = *codeCursor;
    UObject* controllerContext = *(UObject**)((byte*)stack + 8);
    APlayerController* PController = nullptr;
    byte controllerOpcode = *controllerCode;
    *codeCursor = (byte*)((uint)controllerCode + 1U);
    ScriptNative* controllerNatives = (ScriptNative*)ImportedGNativesAddress;
    exceptionRegistration.state = 0;
    controllerNatives[controllerOpcode](controllerContext, stack, &PController);
    byte* playerCode = *codeCursor;
    UObject* playerContext = *(UObject**)((byte*)stack + 8);
    UPlayer* pPlayer = nullptr;
    byte playerOpcode = *playerCode;
    *codeCursor = (byte*)((uint)playerCode + 1U);
    ScriptNative* playerNatives = (ScriptNative*)ImportedGNativesAddress;
    playerNatives[playerOpcode](playerContext, stack, &pPlayer);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    APlayerController* attachedController = PController;
    if (attachedController != nullptr) {
        UPlayer* attachedPlayer = pPlayer;
        if (attachedPlayer != nullptr) {
            attachedController->Player = attachedPlayer; // +0x5b4.
            UPlayer* actorPlayer = pPlayer;
            APlayerController* actorController = PController;
            actorPlayer->Actor = actorController; // +0x34.
            UPlayer* viewportPlayer = pPlayer;
            APlayerController* renderController;
            if (CastToUViewport((int)viewportPlayer) != 0) {
                APlayerController* inputController = PController;
                APlayerController::eventInitInputSystem(inputController);
                APlayerController* levelController = PController;
                if (levelController->Level->NetMode != 0) {
                    APlayerController::eventInitMultiPlayerOptions(levelController);
                    renderController = PController;
                } else {
                    renderController = levelController;
                }
            } else {
                renderController = PController;
            }
            if (renderController->ShowFlags == 0) {
                renderController->ShowFlags = 0x234cc80c;
                renderController = PController;
            }
            if (renderController->RendMap == 0)
                renderController->RendMap = 5;
            *(uint*)result = 0;
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003317 : rethrow execSetController's caught four-byte value
__declspec(naked) void AR6GameInfo_execSetControllerCatchPointer(void)
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

// R6Game.dll @ 1000332b : report execSetController's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execSetControllerCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execSetControllerExceptionContext // L"AR6GameInfo::execSetController"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003380 : execInitScoreSubmission
// Clears eligibility first, then gates on network settings and the first qualifying game-type record.
// The scan stops at that record even if the Raven Shield predicate returns zero; native ABI is RET 8.
void __thiscall AR6GameInfo::execInitScoreSubmission(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execInitScoreSubmissionExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* argumentCode = *codeCursor;
    uint _bStatsSetting = 0;
    byte opcode = *argumentCode;
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* context = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    nativeTable[opcode](context, stack, &_bStatsSetting);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    ScoreSubmissionGate = 0;
    // m_bInternetSvr occupies bit 4 of the byte at +0x4e4.
    if (this->Level->NetMode != 0 &&
        (*(byte*)((byte*)this + 0x4e4) & 0x10U) != 0 && _bStatsSetting != 0) {
        for (int entryIndex = 0; ; ++entryIndex) {
            ALevelInfo* level = this->Level;
            int entryCount = *(int*)((byte*)&level->m_aGameTypeInfo + 4);
            if (entryIndex >= entryCount)
                break;
            uint entryOffset = (uint)entryIndex * 0x98U;
            byte* gameTypeData = *(byte**)&level->m_aGameTypeInfo;
            byte* entry = (byte*)((uint)gameTypeData + entryOffset);
            FString* gameTypeName = (FString*)entry; // GameTypeInfo.m_szGameType, +0.
            if (FString::operator==(gameTypeName, (const FString*)&this->m_szGameTypeFlag) != 0) {
                level = this->Level;
                gameTypeData = *(byte**)&level->m_aGameTypeInfo;
                entry = (byte*)((uint)gameTypeData + entryOffset);
                byte gameMode = entry[0x18]; // m_eGameModeInfo.
                if (gameMode == 3 || (entry[0x1c] & 1U) != 0) { // m_bTeamAdversarial.
                    uint isRavenShield = UR6ModMgr::eventIsRavenShield(*(UR6ModMgr**)ImportedGModMgrAddress);
                    if (isRavenShield != 0)
                        ScoreSubmissionGate = 1;
                    break;
                }
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003492 : rethrow execInitScoreSubmission's caught four-byte value
__declspec(naked) void AR6GameInfo_execInitScoreSubmissionCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 100034a6 : report execInitScoreSubmission's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execInitScoreSubmissionCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execInitScoreSubmissionExceptionContext // L"AR6GameInfo::execInitScoreSubmission"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003500 : execSubmissionNotifySendStartMatch
// Starts player notifications or reports whether the ordered x87 five-second reply deadline is still ahead.
// Sets active and clears eligibility before traversing live controller links; native ABI is RET 8.
void __thiscall AR6GameInfo::execSubmissionNotifySendStartMatch(AR6GameInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execSubmissionNotifySendStartMatchExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    bool hasDebugInfo = *nextCode == 0x42;
    exceptionRegistration.state = 0;
    if (hasDebugInfo) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    int eligibility = ScoreSubmissionGate;
    uint waitingForReply = 0; // Native EDI result value.
    uint notificationResult = 0; // Native EBP-0x18 mirror, reloaded after the controller walk.
    if (eligibility != 0 && (*(uint*)((byte*)this + 0x3b4) & 0x20000U) != 0) { // m_bCompilingStats.
        UClass* actorClass = *(UClass**)R6GameImports::Engine_AActor_PrivateStaticClassSlot;
        AActor* defaultActor = UClass::GetDefaultActor(actorClass);
        bool submissionAllowed = AActor::NativeStartedByGSClient(defaultActor) != 0;
        if (!submissionAllowed) {
            UR6GSServers* service = this->m_PersistantGameService;
            auto isRegistered = *(int (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x80);
            submissionAllowed = isRegistered(service) != 0;
        }
        if (submissionAllowed) {
            UR6GSServers* service = this->m_PersistantGameService;
            if ((*(byte*)((byte*)service + 0x2c) & 1U) == 0) { // m_bServerWaitMatchStartReply.
                ScoreSubmissionActive = 1;
                ScoreSubmissionGate = 0;
                for (AController* controller = this->Level->ControllerList; controller != nullptr;
                    controller = controller->nextController) {
                    AR6PlayerController* player = (AR6PlayerController*)CastToAR6PlayerController((int)controller);
                    if (player != nullptr &&
                        APlayerController::eventIsPlayerPassiveSpectator((APlayerController*)player) == 0) {
                        uint* playerFlags = (uint*)((byte*)player->PlayerReplicationInfo + 0x3ec);
                        *playerFlags |= 0x1000U; // m_bClientWillSubmitResult.
                        AR6PlayerController::eventClientNotifySendStartMatch(player);
                    }
                }
                waitingForReply = notificationResult;
            } else {
                ushort deadlineStatus;
                // Retain x87 precision, exception behavior and the native load/add/ordered-compare sequence.
                __asm {
                    mov eax,this
                    fld dword ptr [eax+0x5a4] // m_fInGameStartTime.
                    mov edx,dword ptr [eax+0x144] // Level, captured before the add.
                    fadd dword ptr [NativeFloatFive]
                    fcomp dword ptr [edx+0x45c] // Level.TimeSeconds.
                    fnstsw ax
                    mov deadlineStatus,ax
                }
                if ((deadlineStatus & 0x4100U) == 0) // Native test AH,0x41 rejects less/equal/unordered.
                    waitingForReply = 1;
            }
        }
    }
    uint* output = (uint*)result;
    uint previousExceptionAddress = exceptionRegistration.previousAddress;
    *output = waitingForReply;
    __writefsdword(0, previousExceptionAddress);
}

// R6Game.dll @ 1000362b : rethrow execSubmissionNotifySendStartMatch's caught four-byte value
__declspec(naked) void AR6GameInfo_execSubmissionNotifySendStartMatchCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset UnsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Game.dll @ 1000363f : report execSubmissionNotifySendStartMatch's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execSubmissionNotifySendStartMatchCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execSubmissionNotifySendStartMatchExceptionContext // L"AR6GameInfo::execSubmissionNotifySendStartMatch"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100036b0 : execLogoutUpdatePlayersCtrlInfo
// Shares the departing player's round statistics and aborts affected kick votes.
void __thiscall AR6GameInfo::execLogoutUpdatePlayersCtrlInfo(AR6GameInfo* this, FFrame* stack, void* unusedResult)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* argumentCode = *codeCursor;
    AController* Exiting = nullptr;
    byte inputOpcode = *argumentCode;
    *codeCursor = (byte*)((uint)argumentCode + 1U);
    ScriptNative* nativeTable = (ScriptNative*)ImportedGNativesAddress;
    UObject* context = *(UObject**)((byte*)stack + 8);
    exceptionRegistration.state = 0;
    nativeTable[inputOpcode](context, stack, &Exiting);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    *codeCursor = nextCode;
    if (*nextCode == 0x42) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    AController* currentExiting = Exiting;
    if (currentExiting != nullptr) {
        ALevelInfo* level = this->Level;
        AController* controller;
        uint elapsedBits; // Native binary32 argument word at EBP-0x18, not a numeric integer conversion.
        __asm {
            mov eax,level
            fld dword ptr [eax+0x45c] // Level.TimeSeconds.
            mov ecx,dword ptr [eax+0x4d4] // ControllerList is read before the subtraction.
            mov controller,ecx
            mov eax,this
            fsub dword ptr [eax+0x594] // m_fRoundStartTime.
            fstp dword ptr [elapsedBits]
        }
        for (; controller != nullptr; controller = controller->nextController) {
            UClass* cursor = *(UClass**)((byte*)controller + 0x24);
            UClass* targetClass = ImportedAR6PlayerControllerClass;
            while (cursor != nullptr && cursor != targetClass)
                cursor = *(UClass**)((byte*)cursor + 0x2c);
            AR6PlayerController* recipient = cursor == targetClass ? (AR6PlayerController*)controller : nullptr;
            if (controller != currentExiting && recipient != nullptr && recipient->m_TeamSelection != 4) {
                UR6GSServers* service = this->m_GameService;
                auto getLoginState = *(byte (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x7c);
                byte loginState = getLoginState(service);
                // m_bGameOver is bit 0x10000 of the packed DWORD at +0x3b4.
                if (loginState == 2 && (*(byte*)((byte*)this + 0x3b6) & 1U) == 0 && ScoreSubmissionActive != 0) {
                    currentExiting = Exiting;
                    if (((APlayerController*)currentExiting)->m_TeamSelection != 4) {
                        APlayerReplicationInfo* comparisonInfo = currentExiting->PlayerReplicationInfo;
                        ushort deathsStatus;
                        __asm {
                            mov eax,comparisonInfo
                            fld dword ptr [eax+0x3f4] // Deaths, including native NaN/exception behavior.
                            fcomp dword ptr [eax+0x3f8] // m_iBackUpDeaths is also binary32.
                            fnstsw ax
                            mov deathsStatus,ax
                        }
                        APlayerReplicationInfo* submittedInfo = currentExiting->PlayerReplicationInfo;
                        uint elapsedArgument = elapsedBits;
                        int killCount = submittedInfo->m_iRoundKillCount;
                        int didDie = (deathsStatus & 0x4100U) == 0 ? 1 : 0;
                        const FString* userId = &submittedInfo->m_szUbiUserID;
                        // The last stack word is the stored float's bits; forward it without another FP operation.
                        using UpdateStatABI = void (__thiscall *)(AR6PlayerController*, const FString*, int, int, uint);
                        UpdateStatABI updateStats = *(UpdateStatABI*)
                            R6GameImports::R6Engine_AR6PlayerController_eventClientUpdateLadderStatSlot;
                        updateStats(recipient, userId, killCount, didDie, elapsedArgument);
                        currentExiting = Exiting;
                    }
                } else {
                    currentExiting = Exiting;
                }
            }
            if (recipient != nullptr && currentExiting == this->m_PlayerKick) {
                AR6PlayerController::eventClientVoteSessionAbort(recipient,
                    &currentExiting->PlayerReplicationInfo->PlayerName);
                currentExiting = Exiting;
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003825 : rethrow execLogoutUpdatePlayersCtrlInfo's caught four-byte value
__declspec(naked) void AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x20]
        push offset UnsignedShortPointerThrowInfo
        lea edx,[ebp-0x1c]
        push edx
        mov dword ptr [ebp-0x1c],ecx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003839 : report execLogoutUpdatePlayersCtrlInfo's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execLogoutUpdatePlayersCtrlInfoCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionContext // L"AR6GameInfo::execLogoutUpdatePlayersCtrlInfo"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov eax,dword ptr [esi+0xc]
        mov edx,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub eax,edx // Bytecode offset modulo 32 bits.
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 100038a0 : execSubmissionUpdateLadderStat
// Sends eligible players the round statistics, requests submission, and returns the login predicate.
void __thiscall AR6GameInfo::execSubmissionUpdateLadderStat(AR6GameInfo* this, FFrame* stack, void* result)
{
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    byte** codeCursor = (byte**)((byte*)stack + 0xc);
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfo_execSubmissionUpdateLadderStatExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    byte* nextCode = (byte*)((uint)*codeCursor + 1U);
    AR6GameInfo* gameInfo = this;
    *codeCursor = nextCode;
    bool hasDebugInfo = *nextCode == 0x42;
    AR6GameInfo* savedGameInfo = gameInfo; // Native EBP-0x1c, restored after contributor traversal.
    exceptionRegistration.state = 0;
    if (hasDebugInfo) {
        UObject* debugContext = *(UObject**)((byte*)stack + 8);
        *codeCursor = (byte*)((uint)nextCode + 1U);
        ScriptNative* debugNatives = (ScriptNative*)ImportedGNativesAddress;
        debugNatives[0x42](debugContext, stack, nullptr);
    }
    UR6GSServers* service = gameInfo->m_GameService;
    auto getLoginState = *(byte (__thiscall**)(UR6GSServers*))(*(byte**)service + 0x7c);
    byte loginState = getLoginState(service);
    uint loggedIntoGS; // Native DWORD at EBP-0x14.
    if (loginState == 2) {
        loggedIntoGS = 1;
    } else {
        UClass* actorClass = *(UClass**)R6GameImports::Engine_AActor_PrivateStaticClassSlot;
        AActor* defaultActor = UClass::GetDefaultActor(actorClass);
        int startedByClient = AActor::NativeStartedByGSClient(defaultActor);
        loggedIntoGS = 0;
        if (startedByClient != 0)
            loggedIntoGS = 1;
    }
    if ((*(byte*)((byte*)gameInfo + 0x590) & 1U) != 0) { // bShowLog.
        uint loggedForMessage = loggedIntoGS;
        FOutputDevice* log = *(FOutputDevice**)ImportedGLogAddress;
        using LogfCall = void (__cdecl *)(FOutputDevice*, const ushort*, ...);
        ((LogfCall)FOutputDevice::Logf)(log,
            (const ushort*)L"We should be sending ClientNotifySendMatchResults() bLoggedIntoGS = %d", loggedForMessage);
    }
    ALevelInfo* level = gameInfo->Level;
    AController* controller;
    UClass* targetClass;
    uint elapsedBits; // Binary32 local at EBP-0x18.
    __asm {
        mov eax,level
        fld dword ptr [eax+0x45c] // Level.TimeSeconds.
        mov ecx,dword ptr [eax+0x4d4] // Head is read before round-start subtraction.
        mov controller,ecx
        mov eax,gameInfo
        fsub dword ptr [eax+0x594] // m_fRoundStartTime.
        mov ecx,dword ptr ds:R6GameAddresses::R6Engine_AR6PlayerController_PrivateStaticClassSlot // Imported AR6PlayerController class, before FSTP.
        mov targetClass,ecx
        fstp dword ptr [elapsedBits]
    }
    uint elapsedArgument = elapsedBits; // Captured in native EBX for every subsequent event.
    for (; controller != nullptr; controller = controller->nextController) {
        UClass* cursor = *(UClass**)((byte*)controller + 0x24);
        while (cursor != nullptr && cursor != targetClass)
            cursor = *(UClass**)((byte*)cursor + 0x2c);
        if (cursor == targetClass && (*(byte*)((byte*)gameInfo + 0x4e4) & 2U) == 0 && loggedIntoGS != 0 &&
            (*(uint*)((byte*)controller->PlayerReplicationInfo + 0x3ec) & 0x1000U) != 0) {
            AR6PlayerController* recipient = (AR6PlayerController*)controller;
            if (APlayerController::eventIsPlayerPassiveSpectator((APlayerController*)recipient) == 0) {
                for (AController* contributor = gameInfo->Level->ControllerList; contributor != nullptr;
                    contributor = contributor->nextController) {
                    AR6PlayerController* player =
                        (AR6PlayerController*)CastToAR6PlayerController((int)contributor);
                    if (player != nullptr && player->m_TeamSelection != 4) {
                        APlayerReplicationInfo* playerInfo = player->PlayerReplicationInfo;
                        uint playerFlags = *(uint*)((byte*)playerInfo + 0x3ec);
                        if ((playerFlags & 0x1000U) != 0) { // m_bClientWillSubmitResult.
                            ushort deathsStatus;
                            __asm {
                                mov eax,playerInfo
                                fld dword ptr [eax+0x3f4] // Deaths.
                                fcomp dword ptr [eax+0x3f8] // m_iBackUpDeaths, also binary32.
                                fnstsw ax
                                mov deathsStatus,ax
                            }
                            int didDie = (deathsStatus & 0x4100U) == 0 ? 1 : 0;
                            int killCount = playerInfo->m_iRoundKillCount;
                            const FString* userId = &playerInfo->m_szUbiUserID;
                            // Forward the captured float word without a numeric integer conversion or another FP load.
                            using UpdateStatABI = void (__thiscall *)(AR6PlayerController*, const FString*, int, int, uint);
                            UpdateStatABI updateStats = *(UpdateStatABI*)
                                R6GameImports::R6Engine_AR6PlayerController_eventClientUpdateLadderStatSlot;
                            updateStats(recipient, userId, killCount, didDie, elapsedArgument);
                        }
                    }
                }
                AR6PlayerController::eventClientNotifySendMatchResults(recipient);
                gameInfo = savedGameInfo;
            }
            targetClass = ImportedAR6PlayerControllerClass;
        }
    }
    *(uint*)result = loggedIntoGS;
    __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 10003a87 : rethrow execSubmissionUpdateLadderStat's caught four-byte value
__declspec(naked) void AR6GameInfo_execSubmissionUpdateLadderStatCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x24]
        push offset UnsignedShortPointerThrowInfo
        lea eax,[ebp-0x20]
        push eax
        mov dword ptr [ebp-0x20],edx
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003a9b : report execSubmissionUpdateLadderStat's script frame and rethrow the active exception
__declspec(naked) void AR6GameInfo_execSubmissionUpdateLadderStatCatchContext(void)
{
    __asm {
        mov edi,dword ptr ds:R6GameAddresses::Core_appUnwindfSlot
        push R6GameAddresses::AR6GameInfo_execSubmissionUpdateLadderStatExceptionContext // L"AR6GameInfo::execSubmissionUpdateLadderStat"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call edi
        mov esi,dword ptr [ebp+0x8] // Inherited parent FFrame*.
        mov ecx,dword ptr [esi+0x4]
        mov edx,dword ptr [esi+0xc]
        mov eax,dword ptr [ecx+0x4c]
        mov ebx,dword ptr ds:R6GameAddresses::Core_UObject_GetFullNameSlot
        add esp,0x8
        sub edx,eax // Bytecode offset modulo 32 bits.
        push edx
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        mov ecx,dword ptr [esi+0x8]
        push eax
        push 0x0
        call ebx // UObject::GetFullName with a null output buffer.
        push eax
        push R6GameAddresses::ScriptExceptionLocationFormat // L"(%s @ %s : %04X)"
        call edi
        add esp,0x10
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10003fb0 : assign inherited state and members
// Assigns inherited state, member values, and owned resources.
AR6GameInfo * __thiscall AR6GameInfo::operator=(AR6GameInfo *this, const AR6GameInfo *source)
{
    const AR6GameInfo* copiedSource = source; // Native EDI retains the source through every assignment call.
    uint *destinationFlags = (uint *)((byte *)this + 0x590);
    const uint *sourceFlags = (const uint *)((const byte *)copiedSource + 0x590);
    uint copiedFlags; // Merges retain cached destination bits and reread the source word.

    AR6AbstractGameInfo::operator=((AR6AbstractGameInfo *)this, (const AR6AbstractGameInfo *)copiedSource);
    this->R6DefaultWeaponInput = copiedSource->R6DefaultWeaponInput; // +0x524.
    this->m_eEndGameWidgetID = copiedSource->m_eEndGameWidgetID; // +0x525.
    this->m_bCurrentFemaleId = copiedSource->m_bCurrentFemaleId; // +0x526.
    this->m_bCurrentMaleId = copiedSource->m_bCurrentMaleId; // +0x527.
    // Copy only the thirty face bytes; padding +0x546..+0x547 is untouched.
    for (int face = 0; face < 30; ++face)
        this->m_bRainbowFaces[face] = copiedSource->m_bRainbowFaces[face];
    this->m_iCurrentID = copiedSource->m_iCurrentID; // +0x548.
    this->m_iMaxOperatives = copiedSource->m_iMaxOperatives; // +0x54c.
    this->m_iJumpMapIndex = copiedSource->m_iJumpMapIndex; // +0x550.
    this->m_iRoundsPerMatch = copiedSource->m_iRoundsPerMatch; // +0x554.
    this->m_iDeathCameraMode = copiedSource->m_iDeathCameraMode; // +0x558.
    this->m_iSubMachineGunsResMask = copiedSource->m_iSubMachineGunsResMask; // +0x55c.
    this->m_iShotGunResMask = copiedSource->m_iShotGunResMask; // +0x560.
    this->m_iAssRifleResMask = copiedSource->m_iAssRifleResMask; // +0x564.
    this->m_iMachGunResMask = copiedSource->m_iMachGunResMask; // +0x568.
    this->m_iSnipRifleResMask = copiedSource->m_iSnipRifleResMask; // +0x56c.
    this->m_iPistolResMask = copiedSource->m_iPistolResMask; // +0x570.
    this->m_iMachPistolResMask = copiedSource->m_iMachPistolResMask; // +0x574.
    this->m_iGadgPrimaryResMask = copiedSource->m_iGadgPrimaryResMask; // +0x578.
    this->m_iGadgSecondaryResMask = copiedSource->m_iGadgSecondaryResMask; // +0x57c.
    this->m_iGadgMiscResMask = copiedSource->m_iGadgMiscResMask; // +0x580.
    this->m_iNbOfRestart = copiedSource->m_iNbOfRestart; // +0x584.
    int voicesId = copiedSource->m_iIDVoicesMgr;
    uint firstMergeFlags = *destinationFlags;
    this->m_iIDVoicesMgr = voicesId; // +0x588.
    int gameMode = copiedSource->m_iUbiComGameMode;
    uint initialDestinationFlags = *destinationFlags;
    this->m_iUbiComGameMode = gameMode; // +0x58c.
    copiedFlags = initialDestinationFlags ^ ((*sourceFlags ^ firstMergeFlags) & 0x1U); // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // bNoRestart.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bServerAllowRadarRep.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bRepAllowRadarOption.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bIsRadarAllowed.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bIsWritableMapAllowed.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bUsingPlayerCampaign.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bUsingCampaignBriefing.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bUnlockAllDoors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200; // m_bJumpingMaps.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bAutoBalance.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800; // m_bTKPenalty.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000; // m_bPWSubMachGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000; // m_bPWShotGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000; // m_bPWAssRifleRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000; // m_bPWMachGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000; // m_bPWSnipRifleRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000; // m_bSWPistolRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000; // m_bSWMachPistolRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000; // m_bGadgPrimaryRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100000; // m_bGadgSecondayRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200000; // m_bGadgMiscRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400000; // m_bShowNames.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800000; // m_bFFPWeapon.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000000; // m_bAdminPasswordReq.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000000; // m_bAIBkp.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000000; // m_bRotateMap.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000000; // m_bFadeStarted.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000000; // m_bFeedbackHostageKilled.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000000; // m_bFeedbackHostageExtracted.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000000; // m_bStopPostBetweenRoundCountdown.
    *destinationFlags = copiedFlags;
    *(uint*)&this->m_fRoundStartTime = *(const uint*)&copiedSource->m_fRoundStartTime; // +0x594.
    *(uint*)&this->m_fRoundEndTime = *(const uint*)&copiedSource->m_fRoundEndTime; // +0x598.
    *(uint*)&this->m_fPausedAtTime = *(const uint*)&copiedSource->m_fPausedAtTime; // +0x59c.
    *(uint*)&this->m_fBombTime = *(const uint*)&copiedSource->m_fBombTime; // +0x5a0.
    *(uint*)&this->m_fInGameStartTime = *(const uint*)&copiedSource->m_fInGameStartTime; // +0x5a4.
    this->m_CommonRainbowPlayerVoicesMgr = copiedSource->m_CommonRainbowPlayerVoicesMgr; // +0x5a8.
    this->m_CommonRainbowMemberVoicesMgr = copiedSource->m_CommonRainbowMemberVoicesMgr; // +0x5ac.
    this->m_RainbowPlayerVoicesMgr = copiedSource->m_RainbowPlayerVoicesMgr; // +0x5b0.
    this->m_RainbowMemberVoicesMgr = copiedSource->m_RainbowMemberVoicesMgr; // +0x5b4.
    this->m_MultiCoopMemberVoicesMgr = copiedSource->m_MultiCoopMemberVoicesMgr; // +0x5b8.
    this->m_PreRecordedMsgVoicesMgr = copiedSource->m_PreRecordedMsgVoicesMgr; // +0x5bc.
    this->m_MultiCommonVoicesMgr = copiedSource->m_MultiCommonVoicesMgr; // +0x5c0.
    this->LastStartSpot = copiedSource->LastStartSpot; // +0x5c4.
    this->m_GameService = copiedSource->m_GameService; // +0x5c8.
    this->m_PersistantGameService = copiedSource->m_PersistantGameService; // +0x5cc.
    this->DefaultFaceTexture = copiedSource->DefaultFaceTexture; // +0x5d0.
    this->m_HudClass = copiedSource->m_HudClass; // +0x5d4.
    AssignFourByteFArray((FArray *)&this->m_RainbowOtherTeamVoicesMgr,
        (const FArray *)&copiedSource->m_RainbowOtherTeamVoicesMgr);
    AssignFourByteFArray((FArray *)&this->m_MultiCoopPlayerVoicesMgr,
        (const FArray *)&copiedSource->m_MultiCoopPlayerVoicesMgr);
    AssignFourByteFArray((FArray *)&this->m_TerroristVoicesMgr, (const FArray *)&copiedSource->m_TerroristVoicesMgr);
    AssignFourByteFArray((FArray *)&this->m_HostageVoicesMaleMgr, (const FArray *)&copiedSource->m_HostageVoicesMaleMgr);
    AssignFourByteFArray((FArray *)&this->m_HostageVoicesFemaleMgr, (const FArray *)&copiedSource->m_HostageVoicesFemaleMgr);
    AssignFourByteFArray((FArray *)&this->m_listAllTerrorists, (const FArray *)&copiedSource->m_listAllTerrorists);
    AssignFourByteFArray((FArray *)&this->m_RainbowAIBackup, (const FArray *)&copiedSource->m_RainbowAIBackup);
    AssignFStringArray((FArray *)&this->m_mapList, (const FArray *)&copiedSource->m_mapList);
    AssignFStringArray((FArray *)&this->m_gameModeList, (const FArray *)&copiedSource->m_gameModeList);
    ((uint*)&this->DefaultFaceCoords)[0] = ((const uint*)&copiedSource->DefaultFaceCoords)[0]; // +0x644.
    ((uint*)&this->DefaultFaceCoords)[1] = ((const uint*)&copiedSource->DefaultFaceCoords)[1]; // +0x648.
    ((uint*)&this->DefaultFaceCoords)[2] = ((const uint*)&copiedSource->DefaultFaceCoords)[2]; // +0x64c.
    ((uint*)&this->DefaultFaceCoords)[3] = ((const uint*)&copiedSource->DefaultFaceCoords)[3]; // +0x650.
    FStringNoInit::operator=((FStringNoInit *)&this->m_szMessageOfDay,
            (const FStringNoInit *)&copiedSource->m_szMessageOfDay); // +0x654.
    FStringNoInit::operator=((FStringNoInit *)&this->m_szSvrName,
            (const FStringNoInit *)&copiedSource->m_szSvrName); // +0x660.
    return this;
}

// R6Game.dll @ 100054b0 : destroy owned resources and inherited state
// Runs conditional shutdown, destroys owned members in reverse order, and destroys the base.
void __thiscall AR6GameInfo::~AR6GameInfo(AR6GameInfo *this)
{
  NativeCppExceptionRegistration exceptionRegistration;
  exceptionRegistration.state = -1;
  exceptionRegistration.handlerAddress = (uint)&AR6GameInfoDestructorExceptionHandler;
  exceptionRegistration.previousAddress = __readfsdword(0);
  __writefsdword(0, (uint)&exceptionRegistration);
  *(const uint**)this = AR6GameInfo_vftable;
  // Native EBP-0x10 saves this for the twelve-state reverse member cleanup map.
  exceptionRegistration.state = 11;
  UObject::ConditionalDestroy((UObject *)this);
  *(byte*)&exceptionRegistration.state = 10;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szSvrName); // +0x660.
  *(byte*)&exceptionRegistration.state = 9;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szMessageOfDay); // +0x654.
  *(byte*)&exceptionRegistration.state = 8;
  DestroyFStringArray((FArray *)&this->m_gameModeList); // +0x638.
  *(byte*)&exceptionRegistration.state = 7;
  DestroyFStringArray((FArray *)&this->m_mapList); // +0x62c.
  *(byte*)&exceptionRegistration.state = 6;
  DestroyFourByteFArray((FArray *)&this->m_RainbowAIBackup); // +0x620.
  *(byte*)&exceptionRegistration.state = 5;
  DestroyFourByteFArray((FArray *)&this->m_listAllTerrorists); // +0x614.
  *(byte*)&exceptionRegistration.state = 4;
  DestroyFourByteFArray((FArray *)&this->m_HostageVoicesFemaleMgr); // +0x608.
  *(byte*)&exceptionRegistration.state = 3;
  DestroyFourByteFArray((FArray *)&this->m_HostageVoicesMaleMgr); // +0x5fc.
  *(byte*)&exceptionRegistration.state = 2;
  DestroyFourByteFArray((FArray *)&this->m_TerroristVoicesMgr); // +0x5f0.
  *(byte*)&exceptionRegistration.state = 1;
  DestroyFourByteFArray((FArray *)&this->m_MultiCoopPlayerVoicesMgr); // +0x5e4.
  *(byte*)&exceptionRegistration.state = 0;
  DestroyFourByteFArray((FArray *)&this->m_RainbowOtherTeamVoicesMgr); // +0x5d8.
  exceptionRegistration.state = -1;
  AR6AbstractGameInfo::~AR6AbstractGameInfo((AR6AbstractGameInfo *)this);
  __writefsdword(0, exceptionRegistration.previousAddress);
}

// R6Game.dll @ 100055c0 : copy-construct inherited state and members
// Copy-constructs inherited state, member values, and owned resources.
AR6GameInfo * __thiscall AR6GameInfo::AR6GameInfo(AR6GameInfo *this, const AR6GameInfo *source)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfoCopyExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    AR6GameInfo* savedObject = this; // Native ECX spill at frame -0x10, used by unwind actions.
    const AR6GameInfo* copiedSource = source; // Native EBP holds the captured source.
    savedObject = this; // Native rewrites the same saved-receiver word before the base call.
    uint *destinationFlags = (uint *)((byte *)this + 0x590);
    const uint *sourceFlags = (const uint *)((const byte *)copiedSource + 0x590);
    uint copiedFlags; // Merges retain cached destination bits and reread the source word.

    AR6AbstractGameInfo::AR6AbstractGameInfo((AR6AbstractGameInfo *)this, (const AR6AbstractGameInfo *)copiedSource);
    *(const uint**)this = AR6GameInfo_vftable;
    this->R6DefaultWeaponInput = copiedSource->R6DefaultWeaponInput; // +0x524.
    this->m_eEndGameWidgetID = copiedSource->m_eEndGameWidgetID; // +0x525.
    this->m_bCurrentFemaleId = copiedSource->m_bCurrentFemaleId; // +0x526.
    this->m_bCurrentMaleId = copiedSource->m_bCurrentMaleId; // +0x527.
    // Native REP MOVSD copies seven words, then MOVSW copies two bytes, leaving padding untouched.
    *(uint*)(&this->m_bRainbowFaces[0]) = *(const uint*)(&copiedSource->m_bRainbowFaces[0]); // +0x528.
    *(uint*)(&this->m_bRainbowFaces[4]) = *(const uint*)(&copiedSource->m_bRainbowFaces[4]); // +0x52c.
    *(uint*)(&this->m_bRainbowFaces[8]) = *(const uint*)(&copiedSource->m_bRainbowFaces[8]); // +0x530.
    *(uint*)(&this->m_bRainbowFaces[12]) = *(const uint*)(&copiedSource->m_bRainbowFaces[12]); // +0x534.
    *(uint*)(&this->m_bRainbowFaces[16]) = *(const uint*)(&copiedSource->m_bRainbowFaces[16]); // +0x538.
    *(uint*)(&this->m_bRainbowFaces[20]) = *(const uint*)(&copiedSource->m_bRainbowFaces[20]); // +0x53c.
    *(uint*)(&this->m_bRainbowFaces[24]) = *(const uint*)(&copiedSource->m_bRainbowFaces[24]); // +0x540.
    *(ushort*)(&this->m_bRainbowFaces[28]) = *(const ushort*)(&copiedSource->m_bRainbowFaces[28]); // +0x544.
    this->m_iCurrentID = copiedSource->m_iCurrentID; // +0x548.
    this->m_iMaxOperatives = copiedSource->m_iMaxOperatives; // +0x54c.
    this->m_iJumpMapIndex = copiedSource->m_iJumpMapIndex; // +0x550.
    this->m_iRoundsPerMatch = copiedSource->m_iRoundsPerMatch; // +0x554.
    this->m_iDeathCameraMode = copiedSource->m_iDeathCameraMode; // +0x558.
    this->m_iSubMachineGunsResMask = copiedSource->m_iSubMachineGunsResMask; // +0x55c.
    this->m_iShotGunResMask = copiedSource->m_iShotGunResMask; // +0x560.
    this->m_iAssRifleResMask = copiedSource->m_iAssRifleResMask; // +0x564.
    this->m_iMachGunResMask = copiedSource->m_iMachGunResMask; // +0x568.
    this->m_iSnipRifleResMask = copiedSource->m_iSnipRifleResMask; // +0x56c.
    this->m_iPistolResMask = copiedSource->m_iPistolResMask; // +0x570.
    this->m_iMachPistolResMask = copiedSource->m_iMachPistolResMask; // +0x574.
    this->m_iGadgPrimaryResMask = copiedSource->m_iGadgPrimaryResMask; // +0x578.
    int secondaryMask = copiedSource->m_iGadgSecondaryResMask;
    uint initialDestinationFlags = *destinationFlags;
    this->m_iGadgSecondaryResMask = secondaryMask; // +0x57c.
    this->m_iGadgMiscResMask = copiedSource->m_iGadgMiscResMask; // +0x580.
    this->m_iNbOfRestart = copiedSource->m_iNbOfRestart; // +0x584.
    int voicesId = copiedSource->m_iIDVoicesMgr;
    uint firstMergeFlags = *destinationFlags;
    this->m_iIDVoicesMgr = voicesId; // +0x588.
    this->m_iUbiComGameMode = copiedSource->m_iUbiComGameMode; // +0x58c.
    copiedFlags = initialDestinationFlags ^ ((*sourceFlags ^ firstMergeFlags) & 0x1U); // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // bNoRestart.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // m_bServerAllowRadarRep.
    *destinationFlags = copiedFlags;
    uint radarOptionSource = *sourceFlags; // Native read precedes activation of base cleanup.
    exceptionRegistration.state = 0;
    copiedFlags ^= (radarOptionSource ^ copiedFlags) & 0x8; // m_bRepAllowRadarOption.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bIsRadarAllowed.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20; // m_bIsWritableMapAllowed.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40; // m_bUsingPlayerCampaign.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80; // m_bUsingCampaignBriefing.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100; // m_bUnlockAllDoors.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200; // m_bJumpingMaps.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400; // m_bAutoBalance.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800; // m_bTKPenalty.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000; // m_bPWSubMachGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000; // m_bPWShotGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000; // m_bPWAssRifleRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000; // m_bPWMachGunRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000; // m_bPWSnipRifleRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000; // m_bSWPistolRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000; // m_bSWMachPistolRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x80000; // m_bGadgPrimaryRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x100000; // m_bGadgSecondayRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x200000; // m_bGadgMiscRes.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x400000; // m_bShowNames.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x800000; // m_bFFPWeapon.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x1000000; // m_bAdminPasswordReq.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2000000; // m_bAIBkp.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4000000; // m_bRotateMap.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8000000; // m_bFadeStarted.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10000000; // m_bFeedbackHostageKilled.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x20000000; // m_bFeedbackHostageExtracted.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x40000000; // m_bStopPostBetweenRoundCountdown.
    *destinationFlags = copiedFlags;
    *(uint*)&this->m_fRoundStartTime = *(const uint*)&copiedSource->m_fRoundStartTime; // +0x594.
    *(uint*)&this->m_fRoundEndTime = *(const uint*)&copiedSource->m_fRoundEndTime; // +0x598.
    *(uint*)&this->m_fPausedAtTime = *(const uint*)&copiedSource->m_fPausedAtTime; // +0x59c.
    *(uint*)&this->m_fBombTime = *(const uint*)&copiedSource->m_fBombTime; // +0x5a0.
    *(uint*)&this->m_fInGameStartTime = *(const uint*)&copiedSource->m_fInGameStartTime; // +0x5a4.
    this->m_CommonRainbowPlayerVoicesMgr = copiedSource->m_CommonRainbowPlayerVoicesMgr; // +0x5a8.
    this->m_CommonRainbowMemberVoicesMgr = copiedSource->m_CommonRainbowMemberVoicesMgr; // +0x5ac.
    this->m_RainbowPlayerVoicesMgr = copiedSource->m_RainbowPlayerVoicesMgr; // +0x5b0.
    this->m_RainbowMemberVoicesMgr = copiedSource->m_RainbowMemberVoicesMgr; // +0x5b4.
    this->m_MultiCoopMemberVoicesMgr = copiedSource->m_MultiCoopMemberVoicesMgr; // +0x5b8.
    this->m_PreRecordedMsgVoicesMgr = copiedSource->m_PreRecordedMsgVoicesMgr; // +0x5bc.
    this->m_MultiCommonVoicesMgr = copiedSource->m_MultiCommonVoicesMgr; // +0x5c0.
    this->LastStartSpot = copiedSource->LastStartSpot; // +0x5c4.
    this->m_GameService = copiedSource->m_GameService; // +0x5c8.
    this->m_PersistantGameService = copiedSource->m_PersistantGameService; // +0x5cc.
    this->DefaultFaceTexture = copiedSource->DefaultFaceTexture; // +0x5d0.
    this->m_HudClass = copiedSource->m_HudClass; // +0x5d4.
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_RainbowOtherTeamVoicesMgr,
        (const FArray *)&copiedSource->m_RainbowOtherTeamVoicesMgr);
    *(byte*)&exceptionRegistration.state = 1;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_MultiCoopPlayerVoicesMgr,
        (const FArray *)&copiedSource->m_MultiCoopPlayerVoicesMgr);
    *(byte*)&exceptionRegistration.state = 2;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_TerroristVoicesMgr,
        (const FArray *)&copiedSource->m_TerroristVoicesMgr);
    *(byte*)&exceptionRegistration.state = 3;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_HostageVoicesMaleMgr,
        (const FArray *)&copiedSource->m_HostageVoicesMaleMgr);
    *(byte*)&exceptionRegistration.state = 4;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_HostageVoicesFemaleMgr,
        (const FArray *)&copiedSource->m_HostageVoicesFemaleMgr);
    *(byte*)&exceptionRegistration.state = 5;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_listAllTerrorists,
        (const FArray *)&copiedSource->m_listAllTerrorists);
    *(byte*)&exceptionRegistration.state = 6;
    ConstructFourByteFArrayCopyWithAdd((FArray *)&this->m_RainbowAIBackup,
        (const FArray *)&copiedSource->m_RainbowAIBackup);
    *(byte*)&exceptionRegistration.state = 7;
    ConstructFStringArrayCopy((FArray *)&this->m_mapList, (const FArray *)&copiedSource->m_mapList);
    *(byte*)&exceptionRegistration.state = 8;
    ConstructFStringArrayCopy((FArray *)&this->m_gameModeList, (const FArray *)&copiedSource->m_gameModeList);
    ((uint*)&this->DefaultFaceCoords)[0] = ((const uint*)&copiedSource->DefaultFaceCoords)[0]; // +0x644.
    ((uint*)&this->DefaultFaceCoords)[1] = ((const uint*)&copiedSource->DefaultFaceCoords)[1]; // +0x648.
    ((uint*)&this->DefaultFaceCoords)[2] = ((const uint*)&copiedSource->DefaultFaceCoords)[2]; // +0x64c.
    ((uint*)&this->DefaultFaceCoords)[3] = ((const uint*)&copiedSource->DefaultFaceCoords)[3]; // +0x650.
    *(byte*)&exceptionRegistration.state = 9;
    FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szMessageOfDay,
            (const FStringNoInit *)&copiedSource->m_szMessageOfDay); // +0x654.
    *(byte*)&exceptionRegistration.state = 10;
    FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szSvrName,
            (const FStringNoInit *)&copiedSource->m_szSvrName); // +0x660.
    __writefsdword(0, exceptionRegistration.previousAddress);
    return this;
}

// R6Game.dll @ 10006c00 : construct game-info members and initialize startup-team planning
// Creates planning for all three teams only when the first team's planning pointer is null.
AR6GameInfo* __thiscall AR6GameInfo::AR6GameInfo(AR6GameInfo* this)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&AR6GameInfoConstructorExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    // Native ESP is saved separately at frame -0x10.
    __writefsdword(0, (uint)&exceptionRegistration);
    AR6GameInfo* constructedObject = this;
    AR6GameInfo* savedObject = this; // Native EBP-0x14, shared with the unwind actions.
    AR6AbstractGameInfo::AR6AbstractGameInfo((AR6AbstractGameInfo*)this);
    // The constructor does not explicitly initialize the nine array headers.
    exceptionRegistration.state = 0;
    *(const uint**)this = AR6GameInfo_vftable;
    *(byte*)&exceptionRegistration.state = 9;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMessageOfDay);
    *(byte*)&exceptionRegistration.state = 10;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szSvrName);
    UEngine** engineSlot = (UEngine**)Importedg_pEngineAddress;
    ScoreSubmissionActive = 0;
    UClient* client = (*engineSlot)->Client; // Engine +0x44.
    *(byte*)&exceptionRegistration.state = 12;
    if (client != nullptr) {
        UPlayer* firstPlayer = **(UPlayer***)((byte*)client + 0x30);
        AR6StartGameInfo* startGameInfo = firstPlayer->Console->Master->m_StartGameInfo;
        if (startGameInfo->m_TeamInfo[0]->m_pPlanning == nullptr) {
            auto getTransientPackage = *(UPackage* (__cdecl**)(void))R6GameImports::Core_UObject_GetTransientPackageSlot;
            using AllocateObject = UObject* (__cdecl*)(UClass*, UObject*, FName, uint, UObject*,
                    FOutputDevice*, UObject*, int);
            AllocateObject allocateObject;
            for (int teamIndex = 0; teamIndex < 3; ++teamIndex) {
                UPackage* transientPackage = getTransientPackage();
                FOutputDevice* errorDevice = *(FOutputDevice**)ImportedGErrorAddress;
                if (teamIndex == 0)
                    allocateObject = *(AllocateObject*)R6GameImports::Core_UObject_StaticAllocateObjectSlot;
                UObject* planningMemory = allocateObject((UClass*)UR6PlanningInfoClassMetadataStorage, transientPackage,
                        FName(0), 0, nullptr, errorDevice, nullptr, 0);
                UR6PlanningInfo* planning = nullptr;
                if (planningMemory != nullptr)
                    planning = UR6PlanningInfo::UR6PlanningInfo((UR6PlanningInfo*)planningMemory);
                // Reload the entire chain after each constructor, including the imported engine slot.
                client = (*(UEngine**)Importedg_pEngineAddress)->Client;
                firstPlayer = **(UPlayer***)((byte*)client + 0x30);
                startGameInfo = firstPlayer->Console->Master->m_StartGameInfo;
                AR6TeamStartInfo* team = startGameInfo->m_TeamInfo[teamIndex];
                if (teamIndex == 2)
                    constructedObject = savedObject; // Native reload precedes the final planning-pointer store.
                team->m_pPlanning = planning;
            }
        }
    }
    __writefsdword(0, exceptionRegistration.previousAddress);
    return constructedObject;
}

// R6Game.dll @ 10006da8 : rethrow the constructor's caught four-byte value
__declspec(naked) void AR6GameInfo_ConstructCatchPointer(void)
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

// R6Game.dll @ 10006dbc : report constructor context and rethrow the active exception
__declspec(naked) void AR6GameInfo_ConstructCatchContext(void)
{
    __asm {
        push R6GameAddresses::AR6GameInfo_AR6GameInfoExceptionContext // L"AR6GameInfo::AR6GameInfo"
        push R6GameAddresses::ExceptionContextFormat // L"%s"
        call dword ptr ds:R6GameAddresses::Core_appUnwindfSlot // appUnwindf.
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Game.dll @ 10006de0 : construct AR6GameInfo in supplied memory when it is nonnull
void __cdecl AR6GameInfo::InternalConstructor(void* objectMemory)
{
  if (objectMemory != nullptr)
    AR6GameInfo::AR6GameInfo((AR6GameInfo*)objectMemory);
}

// R6Game.dll @ 100134a0 : destroy the username bridge's fallback string while unwinding state one
__declspec(naked) void AR6GameInfo_execGetSystemUserNameUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100135e0 : destroy the formatted endpoint if service initialization unwinds
__declspec(naked) void AR6GameInfo_InitGameInfoGameServiceUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x24]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 100135e9 : destroy the port suffix if service initialization unwinds
__declspec(naked) void AR6GameInfo_InitGameInfoGameServiceUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr ds:R6GameAddresses::Core_FString_DestructorSlot // FString destructor.
    }
}

// R6Game.dll @ 10013840 : destroy base while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractGameInfo_DestructorSlot // AR6AbstractGameInfo destructor.
    }
}

// R6Game.dll @ 10013849 : destroy m_RainbowOtherTeamVoicesMgr while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5d8 // m_RainbowOtherTeamVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013857 : destroy m_MultiCoopPlayerVoicesMgr while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5e4 // m_MultiCoopPlayerVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013865 : destroy m_TerroristVoicesMgr while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5f0 // m_TerroristVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013873 : destroy m_HostageVoicesMaleMgr while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5fc // m_HostageVoicesMaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013881 : destroy m_HostageVoicesFemaleMgr while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x608 // m_HostageVoicesFemaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001388f : destroy m_listAllTerrorists while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x614 // m_listAllTerrorists.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001389d : destroy m_RainbowAIBackup while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x620 // m_RainbowAIBackup.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 100138ab : destroy m_mapList while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x62c // m_mapList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 100138b9 : destroy m_gameModeList while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x638 // m_gameModeList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 100138c7 : destroy m_szMessageOfDay while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind10(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x654 // m_szMessageOfDay.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100138d6 : destroy m_szSvrName while unwinding the destructor
__declspec(naked) void AR6GameInfo_DestructUnwind11(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x660 // m_szSvrName.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 100138f0 : destroy base while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractGameInfo_DestructorSlot // AR6AbstractGameInfo destructor.
    }
}

// R6Game.dll @ 100138f9 : destroy m_RainbowOtherTeamVoicesMgr while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5d8 // m_RainbowOtherTeamVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013907 : destroy m_MultiCoopPlayerVoicesMgr while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5e4 // m_MultiCoopPlayerVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013915 : destroy m_TerroristVoicesMgr while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5f0 // m_TerroristVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013923 : destroy m_HostageVoicesMaleMgr while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x5fc // m_HostageVoicesMaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013931 : destroy m_HostageVoicesFemaleMgr while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x608 // m_HostageVoicesFemaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001393f : destroy m_listAllTerrorists while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x614 // m_listAllTerrorists.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001394d : destroy m_RainbowAIBackup while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x620 // m_RainbowAIBackup.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 1001395b : destroy m_mapList while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x62c // m_mapList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013969 : destroy m_gameModeList while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x638 // m_gameModeList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013977 : destroy m_szMessageOfDay while unwinding the copy constructor
__declspec(naked) void AR6GameInfo_CopyConstructUnwind10(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x654 // m_szMessageOfDay.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013ce0 : destroy base while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        jmp dword ptr ds:R6GameAddresses::R6Abstract_AR6AbstractGameInfo_DestructorSlot // AR6AbstractGameInfo destructor.
    }
}

// R6Game.dll @ 10013ce9 : destroy m_RainbowOtherTeamVoicesMgr while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind1(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x5d8 // m_RainbowOtherTeamVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013cf7 : destroy m_MultiCoopPlayerVoicesMgr while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind2(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x5e4 // m_MultiCoopPlayerVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d05 : destroy m_TerroristVoicesMgr while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind3(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x5f0 // m_TerroristVoicesMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d13 : destroy m_HostageVoicesMaleMgr while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind4(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x5fc // m_HostageVoicesMaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d21 : destroy m_HostageVoicesFemaleMgr while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind5(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x608 // m_HostageVoicesFemaleMgr.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d2f : destroy m_listAllTerrorists while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind6(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x614 // m_listAllTerrorists.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d3d : destroy m_RainbowAIBackup while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind7(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x620 // m_RainbowAIBackup.
        jmp R6GameAddresses::ForwardToFourByteArrayDestructor // ForwardToFourByteArrayDestructor.
    }
}

// R6Game.dll @ 10013d4b : destroy m_mapList while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind8(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x62c // m_mapList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013d59 : destroy m_gameModeList while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind9(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x638 // m_gameModeList.
        jmp R6GameAddresses::ForwardToFStringArrayDestructor // ForwardToFStringArrayDestructor.
    }
}

// R6Game.dll @ 10013d67 : destroy m_szMessageOfDay while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind10(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x654 // m_szMessageOfDay.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10013d76 : destroy m_szSvrName while unwinding the default constructor
__declspec(naked) void AR6GameInfo_ConstructUnwind11(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x14]
        add ecx,0x660 // m_szSvrName.
        jmp dword ptr ds:R6GameAddresses::Core_FStringNoInit_DestructorSlot // FStringNoInit destructor.
    }
}

// R6Game.dll @ 10014410 : initialize AR6GameInfo class metadata and register its cleanup
void InitializeAR6GameInfoClassMetadata(void)
{
  auto staticConstructor = ImportedUObjectStaticConstructorAddress;
  UClass* withinClass = (UClass*)ImportedUObjectClass;
  UClass* parentClass = (UClass*)ImportedAR6AbstractGameInfoClass;
  const ushort* configName = UObject::StaticConfigName();
  UClass::UClass((UClass*)AR6GameInfoClassMetadataStorage, 0, 0x66c, 4, parentClass, withinClass, FGuid(0, 0, 0, 0),
      L"R6GameInfo", GPackage, configName, 0x4084004, AR6GameInfo::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6GameInfoClassMetadata);
}

// R6Game.dll @ 100150a0 : destroy AR6GameInfo class metadata
void DestroyAR6GameInfoClassMetadata(void)
{
  UClass::~UClass((UClass*)AR6GameInfoClassMetadataStorage);
}

// R6Game.dll @ 100138e5 : dispatch the game-info destructor exception states
__declspec(naked) void AR6GameInfoDestructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_DestructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013986 : dispatch the game-info copy exception states
__declspec(naked) void AR6GameInfoCopyExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_CopyConstructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013d85 : dispatch the game-info constructor exception states
__declspec(naked) void AR6GameInfoConstructorExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_ConstructExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100144a0 : bind the exported game-info auto-class pointer to its metadata
void InitializeAR6GameInfoAutoClassPointer(void)
{
  autoclassAR6GameInfo = (UClass*)AR6GameInfoClassMetadataStorage; // Exported slot at 0x100241b0.
}

// R6Game.dll @ 10005bb0 : destroy one game-info object or an array, optionally releasing its storage
// Compiler-generated deleting destructor at vtable +0x0c; the method name is descriptive.
void* __thiscall AR6GameInfo::VectorDeletingDestructor(AR6GameInfo* this, uint deletionFlags)
{
    byte flags = (byte)deletionFlags;
    if ((flags & 2) != 0) {
        byte* allocation = (byte*)this - 4;
        int elementCount = *(int*)allocation;
        _eh_vector_destructor_iterator_(this, 0x66c, elementCount,
            (_func_void_void_ptr*)AR6GameInfo::~AR6GameInfo);
        if ((flags & 1) != 0) {
            FMalloc* allocator = *(FMalloc**)ImportedGMallocAddress;
            auto freeAllocation = *(void (__thiscall**)(FMalloc*, void*))(*(byte**)allocator + 8);
            freeAllocation(allocator, allocation);
        }
        return allocation;
    }
    AR6GameInfo::~AR6GameInfo(this);
    if ((flags & 1) != 0)
        UObject::operator_delete(this, 0x66c);
    return this;
}
// R6Game.dll @ 10013480 : dispatch MasterServerManager's exception states
__declspec(naked) void AR6GameInfo_MasterServerManagerExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_MasterServerManagerExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013490 : dispatch execNativeLogout's exception states
__declspec(naked) void AR6GameInfo_execNativeLogoutExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execNativeLogoutExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100134a9 : dispatch execGetSystemUserName's exception states
__declspec(naked) void AR6GameInfo_execGetSystemUserNameExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execGetSystemUserNameExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100134c0 : dispatch AbortScoreSubmission's exception states
__declspec(naked) void AR6GameInfo_AbortScoreSubmissionExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_AbortScoreSubmissionExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100134d0 : dispatch execSubmissionSrvRoundStart's exception states
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundStartExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execSubmissionSrvRoundStartExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100134e0 : dispatch execSubmissionSrvRoundFinish's exception states
__declspec(naked) void AR6GameInfo_execSubmissionSrvRoundFinishExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execSubmissionSrvRoundFinishExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100135f2 : dispatch InitGameInfoGameService's exception states
__declspec(naked) void AR6GameInfo_InitGameInfoGameServiceExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_InitGameInfoGameServiceExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013600 : dispatch execSetController's exception states
__declspec(naked) void AR6GameInfo_execSetControllerExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execSetControllerExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013610 : dispatch execInitScoreSubmission's exception states
__declspec(naked) void AR6GameInfo_execInitScoreSubmissionExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execInitScoreSubmissionExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013620 : dispatch execSubmissionNotifySendStartMatch's exception states
__declspec(naked) void AR6GameInfo_execSubmissionNotifySendStartMatchExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execSubmissionNotifySendStartMatchExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013630 : dispatch execLogoutUpdatePlayersCtrlInfo's exception states
__declspec(naked) void AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 10013640 : dispatch execSubmissionUpdateLadderStat's exception states
__declspec(naked) void AR6GameInfo_execSubmissionUpdateLadderStatExceptionHandler(void)
{
  __asm { mov eax, offset AR6GameInfo_execSubmissionUpdateLadderStatExceptionInfo }
  __asm { jmp R6GameAddresses::CxxFrameHandler }
}

// R6Game.dll @ 100144b0 : register AR6GameInfo::execSetController at native index 2010
void InitializeAR6GameInfoNativeSetController(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecSetController;
    byte& nativeRegistrationResult = AR6GameInfoexecSetControllerRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(2010, nativeExecPointerWord);
}

// R6Game.dll @ 100144d0 : register AR6GameInfo::execNativeLogout at native index 1502
void InitializeAR6GameInfoNativeNativeLogout(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecNativeLogout;
    byte& nativeRegistrationResult = AR6GameInfoexecNativeLogoutRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1502, nativeExecPointerWord);
}

// R6Game.dll @ 100144f0 : register AR6GameInfo::execGetSystemUserName at native index 1504
void InitializeAR6GameInfoNativeGetSystemUserName(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecGetSystemUserName;
    byte& nativeRegistrationResult = AR6GameInfoexecGetSystemUserNameRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1504, nativeExecPointerWord);
}

// R6Game.dll @ 10014510 : register AR6GameInfo::execInitScoreSubmission at native index 1240
void InitializeAR6GameInfoNativeInitScoreSubmission(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecInitScoreSubmission;
    byte& nativeRegistrationResult = AR6GameInfoexecInitScoreSubmissionRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1240, nativeExecPointerWord);
}

// R6Game.dll @ 10014530 : register AR6GameInfo::execSubmissionSrvRoundStart at native index 1241
void InitializeAR6GameInfoNativeSubmissionSrvRoundStart(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecSubmissionSrvRoundStart;
    byte& nativeRegistrationResult = AR6GameInfoexecSubmissionSrvRoundStartRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1241, nativeExecPointerWord);
}

// R6Game.dll @ 10014550 : register AR6GameInfo::execSubmissionNotifySendStartMatch at native index 1242
void InitializeAR6GameInfoNativeSubmissionNotifySendStartMatch(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecSubmissionNotifySendStartMatch;
    byte& nativeRegistrationResult = AR6GameInfoexecSubmissionNotifySendStartMatchRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1242, nativeExecPointerWord);
}

// R6Game.dll @ 10014570 : register AR6GameInfo::execSubmissionSrvRoundFinish at native index 1243
void InitializeAR6GameInfoNativeSubmissionSrvRoundFinish(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecSubmissionSrvRoundFinish;
    byte& nativeRegistrationResult = AR6GameInfoexecSubmissionSrvRoundFinishRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1243, nativeExecPointerWord);
}

// R6Game.dll @ 10014590 : register AR6GameInfo::execLogoutUpdatePlayersCtrlInfo at native index 1244
void InitializeAR6GameInfoNativeLogoutUpdatePlayersCtrlInfo(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecLogoutUpdatePlayersCtrlInfo;
    byte& nativeRegistrationResult = AR6GameInfoexecLogoutUpdatePlayersCtrlInfoRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1244, nativeExecPointerWord);
}

// R6Game.dll @ 100145b0 : register AR6GameInfo::execSubmissionUpdateLadderStat at native index 1245
void InitializeAR6GameInfoNativeSubmissionUpdateLadderStat(void)
{
    // The selected native-member-pointer cell is one DWORD passed by reference.
    using RegisterNativeCall = byte (__cdecl *)(int, const uint&);
    const uint& nativeExecPointerWord = intAR6GameInfoexecSubmissionUpdateLadderStat;
    byte& nativeRegistrationResult = AR6GameInfoexecSubmissionUpdateLadderStatRegistrationResult;
    nativeRegistrationResult = (*(RegisterNativeCall*)R6GameImports::Core_GRegisterNativeSlot)(1245, nativeExecPointerWord);
}
