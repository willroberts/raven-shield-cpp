// Reference-only PE32 word notation: a literal or a relocation to the named code/data symbol.
// Address fields occupy four bytes with four-byte alignment, independently of host pointer encodings.
// These declarations describe selected native records, not recovered game types or portable C++ storage.
struct NativeImageWord32;

// Names an existing native code entry for metadata; it is neither callable C++ nor additional storage.
// Construct-backed entries map to their sole lifetime effect in the module's final-source-review.json.
struct NativeCodeLabel;

// Seven-word MSVC frame prefix only; no trailing fields are inferred from adjacent data.
struct NativeCxxFramePrefix {
  uint magic;
  int unwindCount;
  NativeImageWord32 unwindMap;
  uint tryCount;
  NativeImageWord32 tryMap;
  uint ipCount;
  NativeImageWord32 ipMap;
};
struct NativeCxxUnwindEntry {
  int previousState;
  NativeImageWord32 cleanup;
};
struct NativeCxxTryEntry {
  int lowState;
  int highState;
  int catchHighState;
  uint handlerCount;
  NativeImageWord32 handlers;
};
struct NativeCxxCatchEntry {
  uint attributes;
  NativeImageWord32 typeDescriptor;
  int frameDisplacement;
  NativeImageWord32 handler;
};
struct NativeSehScope {
  int enclosingState;
  NativeImageWord32 filter;
  NativeImageWord32 handler;
};
struct NativeThrowInfo {
  uint attributes;
  NativeImageWord32 destructor;
  NativeImageWord32 compatibilityHook;
  NativeImageWord32 catchableTypes;
};
struct NativePointerAdjustment {
  int memberDisplacement;
  int vbtableDisplacement;
  int displacementInVbtable;
};
struct NativeCatchableType {
  uint properties;
  NativeImageWord32 typeDescriptor;
  NativePointerAdjustment adjustment;
  int valueSize;
  NativeImageWord32 copyFunction;
};
struct NativePointerCatchableTypes {
  int count;
  NativeImageWord32 types[2];
};

// Native dispatch prefixes; each entry is a four-byte code address, never a host member pointer.
struct NativeUObjectVTable {
  NativeImageWord32 QueryInterface; // +0x000.
  NativeImageWord32 AddRef; // +0x004.
  NativeImageWord32 Release; // +0x008.
  NativeImageWord32 VectorDeletingDestructor; // +0x00c.
  NativeImageWord32 ProcessEvent; // +0x010.
  NativeImageWord32 ProcessDelegate; // +0x014.
  NativeImageWord32 ProcessState; // +0x018.
  NativeImageWord32 ProcessRemoteFunction; // +0x01c.
  NativeImageWord32 Modify; // +0x020.
  NativeImageWord32 PostLoad; // +0x024.
  NativeImageWord32 Destroy; // +0x028.
  NativeImageWord32 Serialize; // +0x02c.
  NativeImageWord32 IsPendingKill; // +0x030.
  NativeImageWord32 GotoState; // +0x034.
  NativeImageWord32 GotoLabel; // +0x038.
  NativeImageWord32 InitExecution; // +0x03c.
  NativeImageWord32 ShutdownAfterError; // +0x040.
  NativeImageWord32 PostEditChange; // +0x044.
  NativeImageWord32 CallFunction; // +0x048.
  NativeImageWord32 ScriptConsoleExec; // +0x04c.
  NativeImageWord32 Register; // +0x050.
  NativeImageWord32 LanguageChange; // +0x054.
  NativeImageWord32 IsPendingDelete; // +0x058.
  NativeImageWord32 GetPropertiesSize; // +0x05c.
  NativeImageWord32 NetDirty; // +0x060.
};
struct NativeActorVTable {
  NativeUObjectVTable object; // +0x000..+0x060.
  NativeImageWord32 GetOptimizedRepList; // +0x064.
  NativeImageWord32 GetPlayerPawn; // +0x068.
  NativeImageWord32 GetPawnOrColBoxOwner; // +0x06c.
  NativeImageWord32 IsBlockedBy; // +0x070.
  NativeImageWord32 GetNetPriority; // +0x074.
  NativeImageWord32 WorldLightRadius; // +0x078.
  NativeImageWord32 Tick; // +0x07c.
  NativeImageWord32 PostEditMove; // +0x080.
  NativeImageWord32 PostEditLoad; // +0x084.
  NativeImageWord32 PreRaytrace; // +0x088.
  NativeImageWord32 PostRaytrace; // +0x08c.
  NativeImageWord32 Spawned; // +0x090.
  NativeImageWord32 PreNetReceive; // +0x094.
  NativeImageWord32 PostNetReceive; // +0x098.
  NativeImageWord32 PostNetReceiveLocation; // +0x09c.
  NativeImageWord32 GetSkin; // +0x0a0.
  NativeImageWord32 ToLocal; // +0x0a4.
  NativeImageWord32 ToWorld; // +0x0a8.
  NativeImageWord32 LocalToWorld; // +0x0ac.
  NativeImageWord32 WorldToLocal; // +0x0b0.
  NativeImageWord32 UpdateColBox; // +0x0b4.
  NativeImageWord32 PostScriptDestroyed; // +0x0b8.
  NativeImageWord32 ShouldTrace; // +0x0bc.
  NativeImageWord32 GetPrimitive; // +0x0c0.
  NativeImageWord32 BeginTouch; // +0x0c4.
  NativeImageWord32 IsMovingBrush; // +0x0c8.
  NativeImageWord32 NotifyBump; // +0x0cc.
  NativeImageWord32 SetBase; // +0x0d0.
  NativeImageWord32 GetViewRotation; // +0x0d4.
  NativeImageWord32 NotifyAnimEnd; // +0x0d8.
  NativeImageWord32 UpdateAnimation; // +0x0dc.
  NativeImageWord32 StartAnimPoll; // +0x0e0.
  NativeImageWord32 CheckAnimFinished; // +0x0e4.
  NativeImageWord32 UpdateTimers; // +0x0e8.
  NativeImageWord32 CheckOwnerUpdated; // +0x0ec.
  NativeImageWord32 TickAuthoritative; // +0x0f0.
  NativeImageWord32 TickSimulated; // +0x0f4.
  NativeImageWord32 TickSpecial; // +0x0f8.
  NativeImageWord32 PlayerControlled; // +0x0fc.
  NativeImageWord32 IsNetRelevantFor; // +0x100.
  NativeImageWord32 RenderEditorInfo; // +0x104.
  NativeImageWord32 RenderEditorSelected; // +0x108.
  NativeImageWord32 SetZone; // +0x10c.
  NativeImageWord32 SetVolumesFromArray; // +0x110.
  NativeImageWord32 SetVolumesNoArgs; // +0x114.
  NativeImageWord32 PostBeginPlay; // +0x118.
  NativeImageWord32 setPhysics; // +0x11c.
  NativeImageWord32 performPhysics; // +0x120.
  NativeImageWord32 BoundProjectileVelocity; // +0x124.
  NativeImageWord32 processHitWall; // +0x128.
  NativeImageWord32 processLanded; // +0x12c.
  NativeImageWord32 physFalling; // +0x130.
  NativeImageWord32 FindSlopeRotation; // +0x134.
  NativeImageWord32 SmoothHitWall; // +0x138.
  NativeImageWord32 stepUp; // +0x13c.
  NativeImageWord32 getKModel; // +0x140.
  NativeImageWord32 physKarma; // +0x144.
  NativeImageWord32 preKarmaStep; // +0x148.
  NativeImageWord32 postKarmaStep; // +0x14c.
  NativeImageWord32 KMP2DynKarmaInterface; // +0x150.
  NativeImageWord32 AddMyMarker; // +0x154.
  NativeImageWord32 AssociatedLevelGeometry; // +0x158.
  NativeImageWord32 HasAssociatedLevelGeometry; // +0x15c.
  NativeImageWord32 PlayAnim; // +0x160.
  NativeImageWord32 IsRelevantToPawnRadar; // +0x164.
  NativeImageWord32 IsRelevantToPawnHeatVision; // +0x168.
  NativeImageWord32 IsRelevantToPawnHeartBeat; // +0x16c.
  NativeImageWord32 TickThisFrame; // +0x170.
  NativeImageWord32 CheckForErrors; // +0x174.
  NativeImageWord32 PrePath; // +0x178.
  NativeImageWord32 PostPath; // +0x17c.
  NativeImageWord32 GetProjectorBase; // +0x180.
};

// Only the deletion slot of the CRT type_info table is supported.
struct NativeTypeInfoVTable {
  NativeImageWord32 VectorDeletingDestructor;
};

// R6Abstract.dll data @ 10007194 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix sharedUObjectLifetimeMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &sharedUObjectLifetimeUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 1000718c : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry sharedUObjectLifetimeUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindSharedUObjectLifetimeBase},
};

// R6Abstract.dll data @ 100070b4 : C++ frame metadata prefix: magic, unwind count/map, try count/map, IP count/map
const NativeCxxFramePrefix sharedActorDestructionMetadata = {
  .magic = 0x19930520,
  .unwindCount = 0x00000001,
  .unwindMap = &sharedActorDestructionUnwindMap,
  .tryCount = 0x00000000,
  .tryMap = 0x00000000,
  .ipCount = 0x00000000,
  .ipMap = 0x00000000,
};

// R6Abstract.dll data @ 100070ac : C++ unwind entries: previous state, cleanup code address
const NativeCxxUnwindEntry sharedActorDestructionUnwindMap[1] = {
  {.previousState = -1, .cleanup = &UnwindSharedActorDestructionBase},
};

// R6Abstract.dll data @ 10006d24 : typed wide-string pointer ThrowInfo: attributes, destructor, compatibility hook,
// catchable array
const NativeThrowInfo wideStringPointerThrowInfo = {
  .attributes = 0x00000000,
  .destructor = 0x00000000,
  .compatibilityHook = 0x00000000,
  .catchableTypes = &wideStringPointerCatchableTypes,
};

// R6Abstract.dll data @ 10006d18 : catchable type count and unsigned-short/void pointer descriptor addresses
const NativePointerCatchableTypes wideStringPointerCatchableTypes = {
  .count = 0x00000002, .types = {&wideStringPointerCatchableType, &voidPointerCatchableType},
};

// Address carrier for compiler frame entries; naked helpers preserve their actual EAX/stack ABI.
using NativeExceptionHandler = void(__cdecl *)(void);

// R6Abstract.dll @ 10001af0 : return supplied memory for the shared class placement-allocation overloads
// All thirteen module classes export this same placement allocator.
void *__cdecl AR6AbstractBullet::operator_new(uint allocationSize, EInternal *objectMemory) {
  return objectMemory;
}

// Accepts the native selector and by-value FVector, then returns without action. R6Abstract.dll @ 100028d0 : RET 0x10.
// Shared with UR6AbstractGameService::GameServiceManager(int, int, int, int).
void __thiscall AR6AbstractCorpse::AddImpulseToBone(AR6AbstractCorpse *this, int boneSelector, FVector impulse) {
  return;
}

// R6Abstract.dll @ 10002920 : assign the AActor base and return this object
// Shared by AR6AbstractBullet and AR6AbstractCorpse assignment.
AR6AbstractBullet *__thiscall AR6AbstractBullet::operator=(AR6AbstractBullet *this, const AR6AbstractBullet * source) {
  AActor::operator=(this, source);
  return this;
}

// R6Abstract.dll @ 10002d20 : return without action and consume one four-byte argument
// Shared with Corpse::RenderBones and GameService::GSClientPostMessage, ProcessIsLobbyDisconnect,
// ProcessIsRouterDisconnect, ProcessJoinServer, RequestModCDKeyProcess, ServerRoundStart, SetGSGameState,
// SetGameServiceRequestState, SetLoginRegServer, SetOwnSvrPort and SetRegServerLoginRequest.
void __thiscall AR6AbstractCorpse::FirstInit(AR6AbstractCorpse *this, AR6AbstractPawn *unusedPawn) {
  return;
}

// R6Abstract.dll @ 10003090 : assign the UObject base and return this object
// Shared by UR6AbstractEviLPatchService and UR6AbstractNoiseMgr assignment.
UR6AbstractEviLPatchService *__thiscall UR6AbstractEviLPatchService::operator=(
    UR6AbstractEviLPatchService *this, const UR6AbstractEviLPatchService * source) {
  UObject::operator=(this, source);
  return this;
}

// R6Abstract.dll @ 10004250 : destroy AActor during either Corpse or Bullet destructor unwind parentFrame exposes
// inherited EBP, not a native stack argument; both destructors share this body.
void UnwindSharedActorDestructionBase(const byte *parentFrame) {
  AActor *object = *(AActor *const *)(parentFrame - 0x10);
  AActor::~AActor(object); // Native tail jump.
}

// R6Abstract.dll @ 10004290 : destroy UObject during shared constructor/destructor unwind Used by both GameService
// constructors and the NoiseMgr/PatchService destructors. parentFrame exposes inherited EBP, not a native stack
// argument.
void UnwindSharedUObjectLifetimeBase(const byte *parentFrame) {
  UObject *object = *(UObject *const *)(parentFrame - 0x10);
  UObject::~UObject(object); // Native tail jump.
}

// R6Abstract.dll @ 10004259 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleSharedActorDestructionFrame(void) {
  __asm {
    mov eax, offset sharedActorDestructionMetadata
    jmp __CxxFrameHandler
  }
}

// R6Abstract.dll @ 10004299 : supply this frame's exception metadata to the CRT handler Compiler-generated EAX/stack
// contract; the carrier declaration does not describe a normal C call.
__declspec(naked) void HandleSharedUObjectLifetimeFrame(void) {
  __asm {
    mov eax, offset sharedUObjectLifetimeMetadata
    jmp __CxxFrameHandler
  }
}
