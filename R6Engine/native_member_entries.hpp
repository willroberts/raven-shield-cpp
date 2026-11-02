#pragma once

// Address-only native code labels, each aliasing its existing canonical member body.
// These are descriptive external labels, not recovered C++ functions or additional implementations.
// Never invoke these declarations with C++ call syntax. Assembly transfers and typed native packets retain
// the canonical register/stack contracts; the void declarations provide code-symbol identity only.
// This avoids taking C++ constructor, destructor or member-function pointers as raw PE32 code addresses.

extern "C" {
// R6Engine.dll code alias @ 100074a0 : AR6Door::AR6Door
__declspec(naked) void AR6DoorConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100072f0 : AR6Stairs::AR6Stairs
__declspec(naked) void AR6StairsConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100098e0 : AR6DZonePathNode::AR6DZonePathNode
__declspec(naked) void AR6DZonePathNodeConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10009360 : AR6StairOrientation::AR6StairOrientation
__declspec(naked) void AR6StairOrientationConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10007a00 : AR6StairVolume::AR6StairVolume
__declspec(naked) void AR6StairVolumeConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10007160 : AR6CoverSpot::AR6CoverSpot
__declspec(naked) void AR6CoverSpotConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10006f90 : AR6ClimbablePoint::AR6ClimbablePoint
__declspec(naked) void AR6ClimbablePointConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100129f0 : AR6DZoneRandomPoints::AR6DZoneRandomPoints
__declspec(naked) void AR6DZoneRandomPointsConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012e30 : AR6DZonePath::AR6DZonePath
__declspec(naked) void AR6DZonePathConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10002bd0 : AR6Pawn::AR6Pawn
__declspec(naked) void AR6PawnCopyConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015030 : AMP2IOKarma::AMP2IOKarma
__declspec(naked) void AMP2IOKarmaConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10014fb0 : AMP2IOKarma::~AMP2IOKarma
__declspec(naked) void AMP2IOKarmaDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000c0e0 : AR6AIController::CanHear
__declspec(naked) void AR6AIControllerCanHearNativeEntry(void);

// R6Engine.dll code alias @ 1000c710 : AR6AIController::CanWalkTo
__declspec(naked) void AR6AIControllerCanWalkToNativeEntry(void);

// R6Engine.dll code alias @ 10007f30 : AR6AIController::AR6AIController
__declspec(naked) void AR6AIControllerConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10007ed0 : AR6AIController::~AR6AIController
__declspec(naked) void AR6AIControllerDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000b2b0 : AR6AIController::FindNearestActionSpot
__declspec(naked) void AR6AIControllerFindNearestActionSpotNativeEntry(void);

// R6Engine.dll code alias @ 1000bff0 : AR6AIController::HearingCheck
__declspec(naked) void AR6AIControllerHearingCheckNativeEntry(void);

// R6Engine.dll code alias @ 10008c80 : AR6ClimbableObject::AR6ClimbableObject
__declspec(naked) void AR6ClimbableObjectConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10008c20 : AR6ClimbableObject::~AR6ClimbableObject
__declspec(naked) void AR6ClimbableObjectDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10006f30 : AR6ClimbablePoint::~AR6ClimbablePoint
__declspec(naked) void AR6ClimbablePointDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10007100 : AR6CoverSpot::~AR6CoverSpot
__declspec(naked) void AR6CoverSpotDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10012fd0 : AR6DZoneCircle::AR6DZoneCircle
__declspec(naked) void AR6DZoneCircleConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012f80 : AR6DZoneCircle::~AR6DZoneCircle
__declspec(naked) void AR6DZoneCircleDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1001a090 : AR6DZonePath::DeleteANode
__declspec(naked) void AR6DZonePathDeleteANodeNativeEntry(void);

// R6Engine.dll code alias @ 10012dd0 : AR6DZonePath::~AR6DZonePath
__declspec(naked) void AR6DZonePathDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10009880 : AR6DZonePathNode::~AR6DZonePathNode
__declspec(naked) void AR6DZonePathNodeDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10012cc0 : AR6DZonePoint::AR6DZonePoint
__declspec(naked) void AR6DZonePointConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012c70 : AR6DZonePoint::~AR6DZonePoint
__declspec(naked) void AR6DZonePointDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100094f0 : AR6DZoneRandomPointNode::AR6DZoneRandomPointNode
__declspec(naked) void AR6DZoneRandomPointNodeConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10009490 : AR6DZoneRandomPointNode::~AR6DZoneRandomPointNode
__declspec(naked) void AR6DZoneRandomPointNodeDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10012970 : AR6DZoneRandomPoints::~AR6DZoneRandomPoints
__declspec(naked) void AR6DZoneRandomPointsDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10012ba0 : AR6DZoneRectangle::AR6DZoneRectangle
__declspec(naked) void AR6DZoneRectangleConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012b50 : AR6DZoneRectangle::~AR6DZoneRectangle
__declspec(naked) void AR6DZoneRectangleDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10012600 : AR6DeploymentZone::AR6DeploymentZone
__declspec(naked) void AR6DeploymentZoneConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012520 : AR6DeploymentZone::~AR6DeploymentZone
__declspec(naked) void AR6DeploymentZoneDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10017ae0 : AR6DeploymentZone::HavePlaceForPawnAt
__declspec(naked) void AR6DeploymentZoneHavePlaceForPawnAtNativeEntry(void);

// R6Engine.dll code alias @ 10017e90 : AR6DeploymentZone::InitHostageAI
__declspec(naked) void AR6DeploymentZoneInitHostageAINativeEntry(void);

// R6Engine.dll code alias @ 10007440 : AR6Door::~AR6Door
__declspec(naked) void AR6DoorDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10009b10 : AR6EnvironmentNode::AR6EnvironmentNode
__declspec(naked) void AR6EnvironmentNodeConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10009ab0 : AR6EnvironmentNode::~AR6EnvironmentNode
__declspec(naked) void AR6EnvironmentNodeDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10016030 : AR6FalseHeartBeat::AR6FalseHeartBeat
__declspec(naked) void AR6FalseHeartBeatConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015fe0 : AR6FalseHeartBeat::~AR6FalseHeartBeat
__declspec(naked) void AR6FalseHeartBeatDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10001a20 : AR6GameReplicationInfo::AR6GameReplicationInfo
__declspec(naked) void AR6GameReplicationInfoConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10001870 : AR6GameReplicationInfo::~AR6GameReplicationInfo
__declspec(naked) void AR6GameReplicationInfoDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015df0 : AR6GenericHB::AR6GenericHB
__declspec(naked) void AR6GenericHBConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015da0 : AR6GenericHB::~AR6GenericHB
__declspec(naked) void AR6GenericHBDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10011910 : AR6HostageAI::AR6HostageAI
__declspec(naked) void AR6HostageAIConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100118b0 : AR6HostageAI::~AR6HostageAI
__declspec(naked) void AR6HostageAIDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10004d40 : AR6Hostage::AR6Hostage
__declspec(naked) void AR6HostageConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10004cd0 : AR6Hostage::~AR6Hostage
__declspec(naked) void AR6HostageDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015350 : AR6IActionObject::AR6IActionObject
__declspec(naked) void AR6IActionObjectConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015300 : AR6IActionObject::~AR6IActionObject
__declspec(naked) void AR6IActionObjectDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015a70 : AR6IOBomb::AR6IOBomb
__declspec(naked) void AR6IOBombConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100159c0 : AR6IOBomb::~AR6IOBomb
__declspec(naked) void AR6IOBombDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015830 : AR6IOObject::AR6IOObject
__declspec(naked) void AR6IOObjectConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100157e0 : AR6IOObject::~AR6IOObject
__declspec(naked) void AR6IOObjectDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015480 : AR6IORotatingDoor::AR6IORotatingDoor
__declspec(naked) void AR6IORotatingDoorConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015420 : AR6IORotatingDoor::~AR6IORotatingDoor
__declspec(naked) void AR6IORotatingDoorDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100091f0 : AR6IOSound::AR6IOSound
__declspec(naked) void AR6IOSoundConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10009190 : AR6IOSound::~AR6IOSound
__declspec(naked) void AR6IOSoundDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10014c00 : AR6InteractiveObject::AR6InteractiveObject
__declspec(naked) void AR6InteractiveObjectConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10014b60 : AR6InteractiveObject::~AR6InteractiveObject
__declspec(naked) void AR6InteractiveObjectDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10006d80 : AR6Ladder::AR6Ladder
__declspec(naked) void AR6LadderConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10006d20 : AR6Ladder::~AR6Ladder
__declspec(naked) void AR6LadderDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100076f0 : AR6LadderVolume::AR6LadderVolume
__declspec(naked) void AR6LadderVolumeConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10007690 : AR6LadderVolume::~AR6LadderVolume
__declspec(naked) void AR6LadderVolumeDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100055d0 : AR6MatineeHostage::AR6MatineeHostage
__declspec(naked) void AR6MatineeHostageConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10005580 : AR6MatineeHostage::~AR6MatineeHostage
__declspec(naked) void AR6MatineeHostageDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100061d0 : AR6MatineeRainbow::AR6MatineeRainbow
__declspec(naked) void AR6MatineeRainbowConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10006180 : AR6MatineeRainbow::~AR6MatineeRainbow
__declspec(naked) void AR6MatineeRainbowDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10006b90 : AR6MatineeTerrorist::AR6MatineeTerrorist
__declspec(naked) void AR6MatineeTerroristConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10006b40 : AR6MatineeTerrorist::~AR6MatineeTerrorist
__declspec(naked) void AR6MatineeTerroristDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1002b5c0 : AR6Pawn::actorReachableFromLocation
__declspec(naked) void AR6PawnActorReachableFromLocationNativeEntry(void);

// R6Engine.dll code alias @ 10002bb0 : AR6Pawn::AR6Pawn
__declspec(naked) void AR6PawnConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10002b50 : AR6Pawn::~AR6Pawn
__declspec(naked) void AR6PawnDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100025b0 : AR6Pawn::eventEndOfGrenadeEffect
__declspec(naked) void AR6PawnEventEndOfGrenadeEffectNativeEntry(void);

// R6Engine.dll code alias @ 1000db50 : AR6Pawn::eventGetFiringStartPoint
__declspec(naked) void AR6PawnEventGetFiringStartPointNativeEntry(void);

// R6Engine.dll code alias @ 1002bbc0 : AR6Pawn::GetHeadLocation
__declspec(naked) void AR6PawnGetHeadLocationNativeEntry(void);

// R6Engine.dll code alias @ 10022ac0 : AR6Pawn::GetPeekingRatioNorm
__declspec(naked) void AR6PawnGetPeekingRatioNormNativeEntry(void);

// R6Engine.dll code alias @ 10029b20 : AR6Pawn::UpdateColBoxPeeking
__declspec(naked) void AR6PawnUpdateColBoxPeekingNativeEntry(void);

// R6Engine.dll code alias @ 10010db0 : AR6PlayerController::AR6PlayerController
__declspec(naked) void AR6PlayerControllerConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10010ce0 : AR6PlayerController::~AR6PlayerController
__declspec(naked) void AR6PlayerControllerDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10007bb0 : AR6PlayerController::eventClientPlayVoices
__declspec(naked) void AR6PlayerControllerEventClientPlayVoicesNativeEntry(void);

// R6Engine.dll code alias @ 10031010 : AR6PlayerController::UpdateReticule
__declspec(naked) void AR6PlayerControllerUpdateReticuleNativeEntry(void);

// R6Engine.dll code alias @ 10012400 : AR6RagDoll::AR6RagDoll
__declspec(naked) void AR6RagDollConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10012390 : AR6RagDoll::~AR6RagDoll
__declspec(naked) void AR6RagDollDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10008520 : AR6RainbowAI::AR6RainbowAI
__declspec(naked) void AR6RainbowAIConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100084d0 : AR6RainbowAI::~AR6RainbowAI
__declspec(naked) void AR6RainbowAIDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10005830 : AR6Rainbow::AR6Rainbow
__declspec(naked) void AR6RainbowConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10005740 : AR6Rainbow::~AR6Rainbow
__declspec(naked) void AR6RainbowDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10013100 : AR6RainbowTeam::AR6RainbowTeam
__declspec(naked) void AR6RainbowTeamConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10013090 : AR6RainbowTeam::~AR6RainbowTeam
__declspec(naked) void AR6RainbowTeamDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10015f30 : AR6SAHeartBeatJammer::AR6SAHeartBeatJammer
__declspec(naked) void AR6SAHeartBeatJammerConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10015ee0 : AR6SAHeartBeatJammer::~AR6SAHeartBeatJammer
__declspec(naked) void AR6SAHeartBeatJammerDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a2d0 : AR6SoundReplicationInfo::AR6SoundReplicationInfo
__declspec(naked) void AR6SoundReplicationInfoConstructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a270 : AR6SoundReplicationInfo::~AR6SoundReplicationInfo
__declspec(naked) void AR6SoundReplicationInfoDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10009300 : AR6StairOrientation::~AR6StairOrientation
__declspec(naked) void AR6StairOrientationDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100079a0 : AR6StairVolume::~AR6StairVolume
__declspec(naked) void AR6StairVolumeDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10007290 : AR6Stairs::~AR6Stairs
__declspec(naked) void AR6StairsDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10009dd0 : AR6TeamMemberReplicationInfo::AR6TeamMemberReplicationInfo
__declspec(naked) void AR6TeamMemberReplicationInfoConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10009d20 : AR6TeamMemberReplicationInfo::~AR6TeamMemberReplicationInfo
__declspec(naked) void AR6TeamMemberReplicationInfoDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10011eb0 : AR6TerroristAI::AR6TerroristAI
__declspec(naked) void AR6TerroristAIConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10011e30 : AR6TerroristAI::~AR6TerroristAI
__declspec(naked) void AR6TerroristAIDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000de90 : AR6TerroristAI::eventGotoPointAndSearch
__declspec(naked) void AR6TerroristAIEventGotoPointAndSearchNativeEntry(void);

// R6Engine.dll code alias @ 10006520 : AR6Terrorist::AR6Terrorist
__declspec(naked) void AR6TerroristConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10006480 : AR6Terrorist::~AR6Terrorist
__declspec(naked) void AR6TerroristDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100096c0 : FString::~FString
__declspec(naked) void FStringDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000ab80 : UR6MatineeAttach::UR6MatineeAttach
__declspec(naked) void UR6MatineeAttachConstructorNativeEntry(void);

// R6Engine.dll code alias @ 1000ab20 : UR6MatineeAttach::~UR6MatineeAttach
__declspec(naked) void UR6MatineeAttachDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a8e0 : UR6PlayAnim::UR6PlayAnim
__declspec(naked) void UR6PlayAnimConstructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a880 : UR6PlayAnim::~UR6PlayAnim
__declspec(naked) void UR6PlayAnimDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100137d0 : UR6SubActionAnimSequence::UR6SubActionAnimSequence
__declspec(naked) void UR6SubActionAnimSequenceConstructorNativeEntry(void);

// R6Engine.dll code alias @ 10013770 : UR6SubActionAnimSequence::~UR6SubActionAnimSequence
__declspec(naked) void UR6SubActionAnimSequenceDestructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a6b0 : UR6SubActionLookAt::UR6SubActionLookAt
__declspec(naked) void UR6SubActionLookAtConstructorNativeEntry(void);

// R6Engine.dll code alias @ 1000a650 : UR6SubActionLookAt::~UR6SubActionLookAt
__declspec(naked) void UR6SubActionLookAtDestructorNativeEntry(void);

// R6Engine.dll code alias @ 100138f0 : UR6TerroristMgr::UR6TerroristMgr
__declspec(naked) void UR6TerroristMgrConstructorNativeEntry(void);

// R6Engine.dll code alias @ 100109d0 : UR6TerroristMgr::~UR6TerroristMgr
__declspec(naked) void UR6TerroristMgrDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10042b84 : type_info::~type_info
__declspec(naked) void type_infoDestructorNativeEntry(void);

// R6Engine.dll code alias @ 10016c70 : AR6DeploymentZone::CheckForErrors
__declspec(naked) void AR6DeploymentZoneCheckSettingsNativeEntry(void);

// R6Engine.dll code alias @ 10018c40 : AR6DeploymentZone::SpawnAHostage
__declspec(naked) void AR6DeploymentZoneSpawnAHostageNativeEntry(void);

// R6Engine.dll code alias @ 10018e60 : AR6DeploymentZone::SpawnATerrorist
__declspec(naked) void AR6DeploymentZoneSpawnATerroristNativeEntry(void);
}
