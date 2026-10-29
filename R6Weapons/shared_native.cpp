// Reference-only PE32 word notation: a literal or a relocation to the named code/data symbol.
// Address fields occupy four bytes with four-byte alignment, independently of host pointer encodings.
// These declarations describe selected native records, not recovered game types or portable C++ storage.
struct NativeImageWord32;

// Names an existing native code entry for metadata; it is neither callable C++ nor additional storage.
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

// Native RTTI records use four-byte image references and signed PMD displacements.
struct NativeRttiBaseDescriptor {
  NativeImageWord32 typeDescriptor;
  uint containedBaseCount;
  NativePointerAdjustment adjustment;
  uint attributes;
};
struct NativeRttiClassHierarchy {
  uint signature;
  uint attributes;
  uint baseCount;
  NativeImageWord32 baseDescriptors;
};
struct NativeRttiCompleteObjectLocator {
  uint signature;
  uint objectOffset;
  uint constructionDisplacement;
  NativeImageWord32 typeDescriptor;
  NativeImageWord32 hierarchy;
};
struct NativePointerTypeDescriptor {
  NativeImageWord32 virtualTable;
  uint spare;
  char typeName[8];
};

// Native dispatch slots retain their PE32 widths, including imported methods with distinct calling contracts.
struct NativeActorVTable {
  NativeImageWord32 QueryInterface;             // +0x000.
  NativeImageWord32 AddRef;                     // +0x004.
  NativeImageWord32 Release;                    // +0x008.
  NativeImageWord32 VectorDeletingDestructor;   // +0x00c.
  NativeImageWord32 ProcessEvent;               // +0x010.
  NativeImageWord32 ProcessDelegate;            // +0x014.
  NativeImageWord32 ProcessState;               // +0x018.
  NativeImageWord32 ProcessRemoteFunction;      // +0x01c.
  NativeImageWord32 Modify;                     // +0x020.
  NativeImageWord32 PostLoad;                   // +0x024.
  NativeImageWord32 Destroy;                    // +0x028.
  NativeImageWord32 Serialize;                  // +0x02c.
  NativeImageWord32 IsPendingKill;              // +0x030.
  NativeImageWord32 GotoState;                  // +0x034.
  NativeImageWord32 GotoLabel;                  // +0x038.
  NativeImageWord32 InitExecution;              // +0x03c.
  NativeImageWord32 ShutdownAfterError;         // +0x040.
  NativeImageWord32 PostEditChange;             // +0x044.
  NativeImageWord32 CallFunction;               // +0x048.
  NativeImageWord32 ScriptConsoleExec;          // +0x04c.
  NativeImageWord32 Register;                   // +0x050.
  NativeImageWord32 LanguageChange;             // +0x054.
  NativeImageWord32 IsPendingDelete;            // +0x058.
  NativeImageWord32 GetPropertiesSize;          // +0x05c.
  NativeImageWord32 NetDirty;                   // +0x060.
  NativeImageWord32 GetOptimizedRepList;        // +0x064.
  NativeImageWord32 GetPlayerPawn;              // +0x068.
  NativeImageWord32 GetPawnOrColBoxOwner;       // +0x06c.
  NativeImageWord32 IsBlockedBy;                // +0x070.
  NativeImageWord32 GetNetPriority;             // +0x074.
  NativeImageWord32 WorldLightRadius;           // +0x078.
  NativeImageWord32 Tick;                       // +0x07c.
  NativeImageWord32 PostEditMove;               // +0x080.
  NativeImageWord32 PostEditLoad;               // +0x084.
  NativeImageWord32 PreRaytrace;                // +0x088.
  NativeImageWord32 PostRaytrace;               // +0x08c.
  NativeImageWord32 Spawned;                    // +0x090.
  NativeImageWord32 PreNetReceive;              // +0x094.
  NativeImageWord32 PostNetReceive;             // +0x098.
  NativeImageWord32 PostNetReceiveLocation;     // +0x09c.
  NativeImageWord32 GetSkin;                    // +0x0a0.
  NativeImageWord32 ToLocal;                    // +0x0a4.
  NativeImageWord32 ToWorld;                    // +0x0a8.
  NativeImageWord32 LocalToWorld;               // +0x0ac.
  NativeImageWord32 WorldToLocal;               // +0x0b0.
  NativeImageWord32 UpdateColBox;               // +0x0b4.
  NativeImageWord32 PostScriptDestroyed;        // +0x0b8.
  NativeImageWord32 ShouldTrace;                // +0x0bc.
  NativeImageWord32 GetPrimitive;               // +0x0c0.
  NativeImageWord32 BeginTouch;                 // +0x0c4.
  NativeImageWord32 IsMovingBrush;              // +0x0c8.
  NativeImageWord32 NotifyBump;                 // +0x0cc.
  NativeImageWord32 SetBase;                    // +0x0d0.
  NativeImageWord32 GetViewRotation;            // +0x0d4.
  NativeImageWord32 NotifyAnimEnd;              // +0x0d8.
  NativeImageWord32 UpdateAnimation;            // +0x0dc.
  NativeImageWord32 StartAnimPoll;              // +0x0e0.
  NativeImageWord32 CheckAnimFinished;          // +0x0e4.
  NativeImageWord32 UpdateTimers;               // +0x0e8.
  NativeImageWord32 CheckOwnerUpdated;          // +0x0ec.
  NativeImageWord32 TickAuthoritative;          // +0x0f0.
  NativeImageWord32 TickSimulated;              // +0x0f4.
  NativeImageWord32 TickSpecial;                // +0x0f8.
  NativeImageWord32 PlayerControlled;           // +0x0fc.
  NativeImageWord32 IsNetRelevantFor;           // +0x100.
  NativeImageWord32 RenderEditorInfo;           // +0x104.
  NativeImageWord32 RenderEditorSelected;       // +0x108.
  NativeImageWord32 SetZone;                    // +0x10c.
  NativeImageWord32 SetVolumesFromArray;        // +0x110.
  NativeImageWord32 SetVolumes;                 // +0x114.
  NativeImageWord32 PostBeginPlay;              // +0x118.
  NativeImageWord32 setPhysics;                 // +0x11c.
  NativeImageWord32 performPhysics;             // +0x120.
  NativeImageWord32 BoundProjectileVelocity;    // +0x124.
  NativeImageWord32 processHitWall;             // +0x128.
  NativeImageWord32 processLanded;              // +0x12c.
  NativeImageWord32 physFalling;                // +0x130.
  NativeImageWord32 FindSlopeRotation;          // +0x134.
  NativeImageWord32 SmoothHitWall;              // +0x138.
  NativeImageWord32 stepUp;                     // +0x13c.
  NativeImageWord32 getKModel;                  // +0x140.
  NativeImageWord32 physKarma;                  // +0x144.
  NativeImageWord32 preKarmaStep;               // +0x148.
  NativeImageWord32 postKarmaStep;              // +0x14c.
  NativeImageWord32 KMP2DynKarmaInterface;      // +0x150.
  NativeImageWord32 AddMyMarker;                // +0x154.
  NativeImageWord32 AssociatedLevelGeometry;    // +0x158.
  NativeImageWord32 HasAssociatedLevelGeometry; // +0x15c.
  NativeImageWord32 PlayAnim;                   // +0x160.
  NativeImageWord32 IsRelevantToPawnRadar;      // +0x164.
  NativeImageWord32 IsRelevantToPawnHeatVision; // +0x168.
  NativeImageWord32 IsRelevantToPawnHeartBeat;  // +0x16c.
  NativeImageWord32 TickThisFrame;              // +0x170.
  NativeImageWord32 CheckForErrors;             // +0x174.
  NativeImageWord32 PrePath;                    // +0x178.
  NativeImageWord32 PostPath;                   // +0x17c.
  NativeImageWord32 GetProjectorBase;           // +0x180.
};
struct NativeWeaponVTable {
  NativeActorVTable actor;                    // +0x000..+0x180.
  NativeImageWord32 GetHeartBeatStatus;       // +0x184.
  NativeImageWord32 ShowWeaponParticles;      // +0x188.
  NativeImageWord32 ComputeEffectiveAccuracy; // +0x18c.
  NativeImageWord32 GetMovingModifier;        // +0x190.
  NativeImageWord32 WeaponIsNotFiring;        // +0x194.
};

// R6Weapons.dll data @ 10007a04 : sharedGadgetCleanup unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry sharedGadgetCleanupUnwindMap[1] = {
    {.previousState = -1, .cleanup = &UnwindSharedGadgetBase},
};

// R6Weapons.dll data @ 10007a0c : sharedGadgetCleanup exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix sharedGadgetCleanupFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &sharedGadgetCleanupUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007b40 : sharedActorCleanup unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry sharedActorCleanupUnwindMap[1] = {
    {.previousState = -1, .cleanup = &UnwindSharedActorBase},
};

// R6Weapons.dll data @ 10007b48 : sharedActorCleanup exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix sharedActorCleanupFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000001,
    .unwindMap = &sharedActorCleanupUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll @ 10002e00 : return supplied memory for nine shared class placement-allocation overloads
// Exported under Bullet, DemolitionsGadget, Gadget, Grenade, GrenadeWeapon, HBSGadget, Reticule, SmokeCloud and
// Weapons. Ignores allocationSize and returns objectMemory unchanged, including null; Bullet is the representative
// alias.
void *__cdecl AR6Bullet::operator_new(uint allocationSize, EInternal *objectMemory) {
  return objectMemory;
}

// R6Weapons.dll @ 10005530 : unwind the gadget base during grenade-weapon or HBS-gadget destruction
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindSharedGadgetBase(byte *parentFrameEBP) {
  AR6Gadget *gadget = *(AR6Gadget **)(parentFrameEBP - 0x10);
  AR6Gadget::~AR6Gadget(gadget);
}

// R6Weapons.dll @ 10005538 : dispatch the shared gadget-base cleanup using the native FuncInfo
// Grenade-weapon and HBS-gadget destruction share this one-state map and dispatcher.
__declspec(naked) void DispatchSharedGadgetCleanupException(void) {
  __asm {
    mov eax, offset sharedGadgetCleanupFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005620 : unwind the actor base from the shared reticule-construction/smoke-destruction guard
// Uses inherited EBP-0x10; parentFrameEBP is a register view, not a native stack argument. Native code tail-jumps.
void UnwindSharedActorBase(byte *parentFrameEBP) {
  AActor *actor = *(AActor **)(parentFrameEBP - 0x10);
  AActor::~AActor(actor);
}

// R6Weapons.dll @ 10005629 : dispatch the shared actor-base cleanup using the native FuncInfo
// Reticule default/copy constructors and smoke-cloud destruction share this one-state map and dispatcher.
__declspec(naked) void DispatchSharedActorCleanupException(void) {
  __asm {
    mov eax, offset sharedActorCleanupFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 100011a0 : release supplied memory through the current global allocator
// Reads GMalloc, then its vtable+8 release slot; it adds no null guard or allocator ownership.
void __cdecl FreeThroughGlobalAllocator(void *memory) {
  FMalloc *allocator = *(FMalloc **)GMalloc_exref;
  void **vtable = *(void ***)allocator;
  using ReleaseMemory = void(__thiscall *)(FMalloc *, void *);
  ReleaseMemory releaseMemory = *(ReleaseMemory *)((byte *)vtable + 8);
  releaseMemory(allocator, memory);
}
