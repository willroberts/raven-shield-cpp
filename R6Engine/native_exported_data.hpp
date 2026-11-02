#pragma once

#include "native_object_tables.hpp"

// Shared native data identities established by selected exports.
// Vtables remain external raw PE32 address words; no complete table/class layout or member pointers are invented.

// R6Engine.dll data @ 1004e1a0 : AR6IActionObjectVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6IActionObject::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6IActionObjectVirtualTable;

// R6Engine.dll data @ 100802d8 : R6ENGINE_AttackTimer
extern FName R6ENGINE_AttackTimer;

// R6Engine.dll data @ 1007a194 : R6ENGINE_CanOpenDoor
extern FName R6ENGINE_CanOpenDoor;

// R6Engine.dll data @ 1007d9f0 : R6ENGINE_EndCrawl
extern FName R6ENGINE_EndCrawl;

// R6Engine.dll data @ 10081c48 : R6ENGINE_FinishInitialization
extern FName R6ENGINE_FinishInitialization;

// R6Engine.dll data @ 1007c56c : R6ENGINE_GotoPointAndSearch
extern FName R6ENGINE_GotoPointAndSearch;

// R6Engine.dll data @ 1007f388 : R6ENGINE_GotoPointToAttack
extern FName R6ENGINE_GotoPointToAttack;

// R6Engine.dll data @ 1007da08 : R6ENGINE_GotoStateEngageByThreat
extern FName R6ENGINE_GotoStateEngageByThreat;

// R6Engine.dll data @ 1007e944 : R6ENGINE_IsFullPeekingOver
extern FName R6ENGINE_IsFullPeekingOver;

// R6Engine.dll data @ 10082174 : R6ENGINE_OpenDoorFailed
extern FName R6ENGINE_OpenDoorFailed;

// R6Engine.dll data @ 10080808 : R6ENGINE_PlaySurfaceSwitch
extern FName R6ENGINE_PlaySurfaceSwitch;

// R6Engine.dll data @ 10081738 : R6ENGINE_PotentialOpenDoor
extern FName R6ENGINE_PotentialOpenDoor;

// R6Engine.dll data @ 1007df1c : R6ENGINE_R6SetMovement
extern FName R6ENGINE_R6SetMovement;

// R6Engine.dll data @ 1008269c : R6ENGINE_ReinitSimulation
extern FName R6ENGINE_ReinitSimulation;

// R6Engine.dll data @ 10076490 : R6ENGINE_RemovePotentialOpenDoor
extern FName R6ENGINE_RemovePotentialOpenDoor;

// R6Engine.dll data @ 1007e958 : R6ENGINE_RequestFormationChange
extern FName R6ENGINE_RequestFormationChange;

// R6Engine.dll data @ 10078d44 : R6ENGINE_SetNewDamageState
extern FName R6ENGINE_SetNewDamageState;

// R6Engine.dll data @ 1007ca8c : R6ENGINE_SetPeekingInfo
extern FName R6ENGINE_SetPeekingInfo;

// R6Engine.dll data @ 1007df24 : R6ENGINE_SetRotationOffset
extern FName R6ENGINE_SetRotationOffset;

// R6Engine.dll data @ 1007abe8 : R6ENGINE_StartSimulation
extern FName R6ENGINE_StartSimulation;

// R6Engine.dll data @ 10078318 : R6ENGINE_StopAttack
extern FName R6ENGINE_StopAttack;

// R6Engine.dll data @ 1007d4c0 : R6ENGINE_StopSimulation
extern FName R6ENGINE_StopSimulation;

// R6Engine.dll data @ 1007fdb8 : R6ENGINE_ZDRSetDamageState
extern FName R6ENGINE_ZDRSetDamageState;
