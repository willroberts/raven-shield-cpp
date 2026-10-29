// R6Weapons.dll data @ 1000c0ac : initialized signed step for rotation-rate accuracy bands
// GetMovingModifier reads this word twice at distinct points; the descriptive name does not imply immutability.
int rotationRateBandStep = 60;

// Aliases for existing PE32 IAT cells; each holds one four-byte imported address.
// R6Weapons.dll import @ 10006098 : Core.dll ??0FName@@QAE@PBGW4EFindName@@@Z
extern uint nameConstructorImport;

// R6Weapons.dll data @ 10007198 : UTF-16 native text
const char16_t weaponFiringStateContext[] = u"AR6Weapons::WeaponIsNotFiring";

// R6Weapons.dll data @ 100071d4 : UTF-16 native text
const char16_t weaponIsNotFiringText[] = u"NormalFire";

// R6Weapons.dll data @ 10007248 : UTF-16 native text
const char16_t weaponPreNetReceiveContext1[] = u"AR6Weapons::PreNetReceive";

// R6Weapons.dll data @ 1000727c : UTF-16 native text
const char16_t weaponPreNetReceiveContext2[] = u"AR6Weapons::PreNetReceive";

// R6Weapons.dll data @ 100073b4 : UTF-16 native text
const char16_t weaponProcessStateContext[] = u"AR6Weapons::ProcessState";

// R6Weapons.dll data @ 100073e8 : UTF-16 native text
const char16_t weaponAuthoritativeTickContext[] = u"AR6Weapons::TickAuthoritative";

// R6Weapons.dll data @ 10007428 : UTF-16 native text
const char16_t weaponParticlesContext[] = u"AR6Weapons::ShowWeaponParticles";

// R6Weapons.dll data @ 10007468 : UTF-16 native text
const char16_t weaponMovingAccuracyContext[] = u"AR6Weapons::GetMovingModifier";

// R6Weapons.dll data @ 100074d8 : UTF-16 native text
const char16_t weaponEffectiveAccuracyContext[] = u"AR6Weapons::ComputeEffectiveAccuracy";

// R6Weapons.dll data @ 10007530 : UTF-16 native text
const char16_t weaponPreNetReceiveContext3[] = u"AR6Weapons::PreNetReceive";

// R6Weapons.dll data @ 100075b4 : UTF-16 metadata-name storage; constructor uses the suffix after its leading A
const char16_t r6WeaponsClassNameStorage[] = u"AR6Weapons";

// R6Weapons.dll data @ 100074a8 : shared five-sample average and accuracy compression coefficient
const double accuracyOneFifth = 0.2;

// R6Weapons.dll data @ 100074b0 : full-turn value used to fold rotation differences
const float fullRotationDegrees = 360.0f;

// R6Weapons.dll data @ 100074b4 : half-turn threshold used to fold rotation differences
const float halfRotationDegrees = 180.0f;

// R6Weapons.dll data @ 100074b8 : rotation-unit conversion, exactly 360 divided by 65536
const double rotationUnitDegrees = 0.0054931640625;

// R6Weapons.dll data @ 100074c0 : ordinary prone accuracy multiplier
const float proneAccuracyMultiplier = 0.8f;

// R6Weapons.dll data @ 100074c4 : prone accuracy multiplier selected by weapon flag mask 2
const float alternateProneAccuracyMultiplier = 0.7f;

// R6Weapons.dll data @ 100074c8 : crouched accuracy multiplier
const float crouchedAccuracyMultiplier = 0.9f;

// R6Weapons.dll data @ 100074cc : accuracy multiplier selected by owner health value 1
const float injuredAccuracyMultiplier = 1.2f;

// R6Weapons.dll data @ 100074d0 : shared acceleration, rotation and recovery zero operand
const float accuracyZero = 0.0f;

// R6Weapons.dll data @ 10007524 : reticule recovery-time coefficient
const float reticuleRecoveryTimeScale = 0.25f;

// R6Weapons.dll data @ 10007528 : intercept of the skill-dependent recovery factor
const float recoveryFactorIntercept = 5.5f;

// R6Weapons.dll data @ 1000752c : skill coefficient of the recovery factor
const float recoverySkillScale = 5.0f;

// R6Weapons.dll data @ 100078a4 : weaponDestructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponDestructorUnwindMap[3] = {
    {.previousState = -1, .cleanup = &UnwindWeaponDestructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindWeaponDestructorReticuleClass},
    {.previousState = 0x00000001, .cleanup = &UnwindWeaponDestructorWithWeaponReticuleClass},
};

// R6Weapons.dll data @ 100078bc : weaponDestructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponDestructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000003,
    .unwindMap = &weaponDestructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100078d8 : weaponConstructor unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponConstructorUnwindMap[2] = {
    {.previousState = -1, .cleanup = &UnwindWeaponConstructorBase},
    {.previousState = 0x00000000, .cleanup = &UnwindWeaponConstructorReticuleClass},
};

// R6Weapons.dll data @ 100078e8 : weaponConstructor exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponConstructorFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponConstructorUnwindMap,
    .tryCount = 0x00000000,
    .tryMap = 0x00000000,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007be8 : weaponFiringState unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponFiringStateUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007bf8 : weaponFiringState typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponFiringStateCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -28,
        .handler = &RethrowWeaponFiringStateMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponFiringStateException,
    },
};

// R6Weapons.dll data @ 10007c18 : weaponFiringState protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponFiringStateTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponFiringStateCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007c2c : weaponFiringState exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponFiringStateFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponFiringStateUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponFiringStateTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007ca8 : weaponPreReceive unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponPreReceiveUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007cb8 : weaponPreReceive typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponPreReceiveCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponPreReceiveMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponPreReceiveException,
    },
};

// R6Weapons.dll data @ 10007cd8 : weaponPreReceive protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponPreReceiveTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponPreReceiveCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007cec : weaponPreReceive exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponPreReceiveFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponPreReceiveUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponPreReceiveTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007d08 : weaponBlocking unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponBlockingUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007d18 : weaponBlocking typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponBlockingCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponBlockingMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponBlockingException,
    },
};

// R6Weapons.dll data @ 10007d38 : weaponBlocking protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponBlockingTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponBlockingCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007d4c : weaponBlocking exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponBlockingFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponBlockingUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponBlockingTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007e88 : weaponProcessState unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponProcessStateUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007e98 : weaponProcessState typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponProcessStateCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponProcessStateMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponProcessStateException,
    },
};

// R6Weapons.dll data @ 10007eb8 : weaponProcessState protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponProcessStateTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponProcessStateCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007ecc : weaponProcessState exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponProcessStateFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponProcessStateUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponProcessStateTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007ee8 : weaponTick unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponTickUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007ef8 : weaponTick typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponTickCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -36,
        .handler = &RethrowWeaponTickMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponTickException,
    },
};

// R6Weapons.dll data @ 10007f18 : weaponTick protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponTickTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponTickCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007f2c : weaponTick exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponTickFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponTickUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponTickTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007f48 : weaponParticles unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponParticlesUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007f58 : weaponParticles typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponParticlesCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponParticlesMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponParticlesException,
    },
};

// R6Weapons.dll data @ 10007f78 : weaponParticles protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponParticlesTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponParticlesCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007f8c : weaponParticles exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponParticlesFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponParticlesUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponParticlesTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10007fa8 : weaponMovingAccuracy unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponMovingAccuracyUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10007fb8 : weaponMovingAccuracy typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponMovingAccuracyCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponMovingAccuracyMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponMovingAccuracyException,
    },
};

// R6Weapons.dll data @ 10007fd8 : weaponMovingAccuracy protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponMovingAccuracyTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponMovingAccuracyCatchHandlers,
    },
};

// R6Weapons.dll data @ 10007fec : weaponMovingAccuracy exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponMovingAccuracyFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponMovingAccuracyUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponMovingAccuracyTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10008008 : weaponEffectiveAccuracy unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponEffectiveAccuracyUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10008018 : weaponEffectiveAccuracy typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponEffectiveAccuracyCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -28,
        .handler = &RethrowWeaponEffectiveAccuracyMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponEffectiveAccuracyException,
    },
};

// R6Weapons.dll data @ 10008038 : weaponEffectiveAccuracy protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponEffectiveAccuracyTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponEffectiveAccuracyCatchHandlers,
    },
};

// R6Weapons.dll data @ 1000804c : weaponEffectiveAccuracy exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponEffectiveAccuracyFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponEffectiveAccuracyUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponEffectiveAccuracyTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 10008068 : weaponPostReceive unwind state transitions
// Pairs: signed predecessor state, cleanup entry address (zero means no cleanup).
const NativeCxxUnwindEntry weaponPostReceiveUnwindMap[2] = {
    {.previousState = -1, .cleanup = 0x00000000},
    {.previousState = -1, .cleanup = 0x00000000},
};

// R6Weapons.dll data @ 10008078 : weaponPostReceive typed-message and catch-all handlers
// Rows: flags, type descriptor (zero means catch-all), signed parent-EBP binding, catch entry.
const NativeCxxCatchEntry weaponPostReceiveCatchHandlers[2] = {
    {
        .attributes = 0x00000000,
        .typeDescriptor = &unsignedShortPointerTypeDescriptor,
        .frameDisplacement = -24,
        .handler = &RethrowWeaponPostReceiveMessage,
    },
    {
        .attributes = 0x00000000,
        .typeDescriptor = 0x00000000,
        .frameDisplacement = 0x00000000,
        .handler = &ReportWeaponPostReceiveException,
    },
};

// R6Weapons.dll data @ 10008098 : weaponPostReceive protected-state and catch range
// Words: first/last try state, last catch state, handler count, handler-array address.
const NativeCxxTryEntry weaponPostReceiveTryMap[1] = {
    {
        .lowState = 0x00000000,
        .highState = 0x00000000,
        .catchHighState = 0x00000001,
        .handlerCount = 0x00000002,
        .handlers = &weaponPostReceiveCatchHandlers,
    },
};

// R6Weapons.dll data @ 100080ac : weaponPostReceive exception frame metadata
// Words: magic, unwind-state count/map, try count/map, two native zero tail words.
const NativeCxxFramePrefix weaponPostReceiveFuncInfo = {
    .magic = 0x19930520,
    .unwindCount = 0x00000002,
    .unwindMap = &weaponPostReceiveUnwindMap,
    .tryCount = 0x00000001,
    .tryMap = &weaponPostReceiveTryMap,
    .ipCount = 0x00000000,
    .ipMap = 0x00000000,
};

// R6Weapons.dll data @ 100062f0 : exported AR6Weapons virtual dispatch table
// Preferred-image DWORD view; each slot has a native HIGHLOW relocation, not a replacement method declaration.
const NativeWeaponVTable AR6Weapons_vftable = {
    .actor =
        {
            .QueryInterface = &ForwardUObjectQueryInterface,
            .AddRef = &ForwardUObjectAddRef,
            .Release = &ForwardUObjectRelease,
            .VectorDeletingDestructor = &AR6Weapons::VectorDeletingDestructor,
            .ProcessEvent = &ForwardAActorProcessEvent,
            .ProcessDelegate = &ForwardUObjectProcessDelegate,
            .ProcessState = &AR6Weapons::ProcessState,
            .ProcessRemoteFunction = &ForwardAActorProcessRemoteFunction,
            .Modify = &ForwardUObjectModify,
            .PostLoad = &ForwardAActorPostLoad,
            .Destroy = &ForwardAActorDestroy,
            .Serialize = &ForwardAActorSerialize,
            .IsPendingKill = &ForwardAActorIsPendingKill,
            .GotoState = &ForwardUObjectGotoState,
            .GotoLabel = &ForwardUObjectGotoLabel,
            .InitExecution = &ForwardAActorInitExecution,
            .ShutdownAfterError = &ForwardUObjectShutdownAfterError,
            .PostEditChange = &ForwardAActorPostEditChange,
            .CallFunction = &ForwardUObjectCallFunction,
            .ScriptConsoleExec = &ForwardUObjectScriptConsoleExec,
            .Register = &ForwardUObjectRegister,
            .LanguageChange = &ForwardUObjectLanguageChange,
            .IsPendingDelete = &ForwardAActorIsPendingDelete,
            .GetPropertiesSize = &ForwardUObjectGetPropertiesSize,
            .NetDirty = &ForwardAActorNetDirty,
            .GetOptimizedRepList = &ForwardAActorGetOptimizedRepList,
            .GetPlayerPawn = &ForwardAActorGetPlayerPawn,
            .GetPawnOrColBoxOwner = &ForwardAActorGetPawnOrColBoxOwner,
            .IsBlockedBy = &AR6Weapons::IsBlockedBy,
            .GetNetPriority = &ForwardAActorGetNetPriority,
            .WorldLightRadius = &ForwardAActorWorldLightRadius,
            .Tick = &ForwardAActorTick,
            .PostEditMove = &ForwardAActorPostEditMove,
            .PostEditLoad = &ForwardAActorPostEditLoad,
            .PreRaytrace = &ForwardAActorPreRaytrace,
            .PostRaytrace = &ForwardAActorPostRaytrace,
            .Spawned = &ForwardAActorSpawned,
            .PreNetReceive = &AR6Weapons::PreNetReceive,
            .PostNetReceive = &AR6Weapons::PostNetReceive,
            .PostNetReceiveLocation = &ForwardAActorPostNetReceiveLocation,
            .GetSkin = &ForwardAActorGetSkin,
            .ToLocal = &ForwardAActorToLocal,
            .ToWorld = &ForwardAActorToWorld,
            .LocalToWorld = &ForwardAActorLocalToWorld,
            .WorldToLocal = &ForwardAActorWorldToLocal,
            .UpdateColBox = &ForwardAActorUpdateColBox,
            .PostScriptDestroyed = &ForwardAActorPostScriptDestroyed,
            .ShouldTrace = &ForwardAActorShouldTrace,
            .GetPrimitive = &ForwardAActorGetPrimitive,
            .BeginTouch = &ForwardAActorBeginTouch,
            .IsMovingBrush = &ForwardAActorIsMovingBrush,
            .NotifyBump = &ForwardAActorNotifyBump,
            .SetBase = &ForwardAActorSetBase,
            .GetViewRotation = &ForwardAActorGetViewRotation,
            .NotifyAnimEnd = &ForwardAActorNotifyAnimEnd,
            .UpdateAnimation = &ForwardAActorUpdateAnimation,
            .StartAnimPoll = &ForwardAActorStartAnimPoll,
            .CheckAnimFinished = &ForwardAActorCheckAnimFinished,
            .UpdateTimers = &ForwardAActorUpdateTimers,
            .CheckOwnerUpdated = &ForwardAActorCheckOwnerUpdated,
            .TickAuthoritative = &AR6Weapons::TickAuthoritative,
            .TickSimulated = &ForwardAActorTickSimulated,
            .TickSpecial = &ForwardAActorTickSpecial,
            .PlayerControlled = &ForwardAActorPlayerControlled,
            .IsNetRelevantFor = &ForwardAActorIsNetRelevantFor,
            .RenderEditorInfo = &ForwardAActorRenderEditorInfo,
            .RenderEditorSelected = &ForwardAActorRenderEditorSelected,
            .SetZone = &ForwardAActorSetZone,
            .SetVolumesFromArray = &ForwardAActorSetVolumesFromArray,
            .SetVolumes = &ForwardAActorSetVolumes,
            .PostBeginPlay = &ForwardAActorPostBeginPlay,
            .setPhysics = &ForwardAActorsetPhysics,
            .performPhysics = &ForwardAActorperformPhysics,
            .BoundProjectileVelocity = &ForwardAActorBoundProjectileVelocity,
            .processHitWall = &ForwardAActorprocessHitWall,
            .processLanded = &ForwardAActorprocessLanded,
            .physFalling = &ForwardAActorphysFalling,
            .FindSlopeRotation = &ForwardAActorFindSlopeRotation,
            .SmoothHitWall = &ForwardAActorSmoothHitWall,
            .stepUp = &ForwardAActorstepUp,
            .getKModel = &ForwardAActorgetKModel,
            .physKarma = &ForwardAActorphysKarma,
            .preKarmaStep = &ForwardAActorpreKarmaStep,
            .postKarmaStep = &ForwardAActorpostKarmaStep,
            .KMP2DynKarmaInterface = &ForwardAActorKMP2DynKarmaInterface,
            .AddMyMarker = &ForwardAActorAddMyMarker,
            .AssociatedLevelGeometry = &ForwardAActorAssociatedLevelGeometry,
            .HasAssociatedLevelGeometry = &ForwardAActorHasAssociatedLevelGeometry,
            .PlayAnim = &ForwardAActorPlayAnim,
            .IsRelevantToPawnRadar = &ForwardAActorIsRelevantToPawnRadar,
            .IsRelevantToPawnHeatVision = &ForwardAActorIsRelevantToPawnHeatVision,
            .IsRelevantToPawnHeartBeat = &ForwardAActorIsRelevantToPawnHeartBeat,
            .TickThisFrame = &ForwardAActorTickThisFrame,
            .CheckForErrors = &ForwardAActorCheckForErrors,
            .PrePath = &ForwardAActorPrePath,
            .PostPath = &ForwardAActorPostPath,
            .GetProjectorBase = &ForwardAActorGetProjectorBase,
        },
    .GetHeartBeatStatus = &AR6Weapons::GetHeartBeatStatus,
    .ShowWeaponParticles = &AR6Weapons::ShowWeaponParticles,
    .ComputeEffectiveAccuracy = &AR6Weapons::ComputeEffectiveAccuracy,
    .GetMovingModifier = &AR6Weapons::GetMovingModifier,
    .WeaponIsNotFiring = &AR6Weapons::WeaponIsNotFiring,
};

// R6Weapons.dll data @ 1000e460 : exported AR6Weapons::PrivateStaticClass initial storage
// The 0x508-byte UClass object is constructed by its explicit initializer; no default constructor is implied.
// The reference is a source address view of that storage, not an additional native reference variable.
alignas(8) byte AR6WeaponsClassMetadataStorage[0x508] = {};
UClass &AR6Weapons::PrivateStaticClass = *(UClass *)AR6WeaponsClassMetadataStorage;

// R6Weapons.dll @ 100011c0 : dispatch HideAttachment without parameters
// Snapshots the name before the vtable, resolves the function and dispatches through the saved actor slot.
void __thiscall AR6Weapons::eventHideAttachment(AR6Weapons *this) {
  FName eventName = R6WEAPONS_HideAttachment;
  const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
  UFunction *function = UObject::FindFunctionChecked((UObject *)this, eventName, 0);
  using EventDispatcher = void(__thiscall *)(AActor *, UFunction *, void *, void *);
  EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
  processEvent((AActor *)this, function, nullptr, nullptr);
}

// R6Weapons.dll @ 100011f0 : return the AR6Weapons class object
// Returns the class metadata object at native address 0x1000e460.
UClass *__cdecl AR6Weapons::StaticClass(void) {
  return &PrivateStaticClass;
}

// R6Weapons.dll @ 10001200 : allocate AR6Weapons using its class metadata
// Snapshots current GError, then forwards outer/name/flags; allocationSize is unused.
void *__cdecl AR6Weapons::operator_new(uint allocationSize, UObject *outer, FName objectName, ulong objectFlags) {
  FOutputDevice *errorDevice = *(FOutputDevice **)GError_exref;
  return UObject::StaticAllocateObject(&PrivateStaticClass, outer, objectName, objectFlags, nullptr, errorDevice,
                                       nullptr, 0);
}

// R6Weapons.dll @ 10001230 : destroy the object, its strings, and its base
// Runs conditional shutdown, destroys strings in reverse order, and destroys the base.
// FuncInfo 0x100078bc: states 2 -> 1 -> 0 -> -1 clean +0x620, +0x614, then the base.
void __thiscall AR6Weapons::~AR6Weapons(AR6Weapons *this) {
  int destructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponDestructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  *(const NativeWeaponVTable **)this = &AR6Weapons_vftable;
  destructionState = 2;
  UObject::ConditionalDestroy((UObject *)this);
  destructionState = 1;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szWithWeaponReticuleClass); // +0x620.
  destructionState = 0;
  FStringNoInit::~FStringNoInit((FStringNoInit *)&this->m_szReticuleClass); // +0x614.
  destructionState = -1;
  AR6AbstractWeapon::~AR6AbstractWeapon((AR6AbstractWeapon *)this);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 100012b0 : construct the abstract weapon base and two no-init strings
// Installs the weapon vtable and preserves existing string storage at +0x614/+0x620.
AR6Weapons *__thiscall AR6Weapons::AR6Weapons(AR6Weapons *this) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AR6AbstractWeapon::AR6AbstractWeapon((AR6AbstractWeapon *)this);
  constructionState = 0;
  *(const NativeWeaponVTable **)this = &AR6Weapons_vftable;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szReticuleClass); // +0x614; leaves storage unchanged.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szWithWeaponReticuleClass); // +0x620; preserves storage.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10001310 : report inactive heartbeat status for the base weapon
// Returns full-width zero without reading the receiver.
int __thiscall AR6Weapons::GetHeartBeatStatus(AR6Weapons *this) {
  return 0;
}

// R6Weapons.dll @ 10001320 : copy-construct the base and reflected members
// Copies inventory in five raw words, preserves scalar representations, merges five flag bits and constructs strings.
AR6Weapons *__thiscall AR6Weapons::AR6Weapons(AR6Weapons *this, const AR6Weapons *source) {
  int constructionState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponConstructorException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  uint *destinationFlags = (uint *)((byte *)this + 0x548);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x548);

  AR6AbstractWeapon::AR6AbstractWeapon((AR6AbstractWeapon *)this, (const AR6AbstractWeapon *)source);
  *(const NativeWeaponVTable **)this = &AR6Weapons_vftable;
  *(uint *)&this->m_aiNbOfBullets[0] = *(const uint *)&source->m_aiNbOfBullets[0];     // +0x50c.
  *(uint *)&this->m_aiNbOfBullets[4] = *(const uint *)&source->m_aiNbOfBullets[4];     // +0x510.
  *(uint *)&this->m_aiNbOfBullets[8] = *(const uint *)&source->m_aiNbOfBullets[8];     // +0x514.
  *(uint *)&this->m_aiNbOfBullets[12] = *(const uint *)&source->m_aiNbOfBullets[12];   // +0x518.
  *(uint *)&this->m_aiNbOfBullets[16] = *(const uint *)&source->m_aiNbOfBullets[16];   // +0x51c.
  *(byte *)&this->m_iNbOfRoundsInBurst = *(const byte *)&source->m_iNbOfRoundsInBurst; // +0x520.
  *(byte *)&this->m_eRateOfFire = *(const byte *)&source->m_eRateOfFire;               // +0x521.
  *(byte *)&this->m_wNbOfBounce = *(const byte *)&source->m_wNbOfBounce;               // +0x522.
  this->C_iMaxNbOfClips = source->C_iMaxNbOfClips;                                     // +0x524.
  this->m_iClipCapacity = source->m_iClipCapacity;                                     // +0x528.
  this->m_iNbOfClips = source->m_iNbOfClips;                                           // +0x52c.
  this->m_iNbOfExtraClips = source->m_iNbOfExtraClips;                                 // +0x530.
  this->m_iCurrentClip = source->m_iCurrentClip;                                       // +0x534.
  this->m_iNbOfRoundsToShoot = source->m_iNbOfRoundsToShoot;                           // +0x538.
  this->m_iCurrentNbOfClips = source->m_iCurrentNbOfClips;                             // +0x53c.
  const int currentAverage = source->m_iCurrentAverage;                                // +0x540.
  const uint earlyDestinationFlags = *destinationFlags; // Native snapshot precedes the next two stores.
  this->m_iCurrentAverage = currentAverage;
  const int nextReticule = source->m_iDbgNextReticule; // +0x544.
  this->m_iDbgNextReticule = nextReticule;
  const uint firstSourceFlags = *sourceFlags;
  uint copiedFlags = *destinationFlags; // Native reload follows the source-flags read in this constructor.
  copiedFlags ^= (firstSourceFlags ^ earlyDestinationFlags) & 0x1; // m_bPlayLoopingSound.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bSoundLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // bShowLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bFireOn.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bEmptyAllClips.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fMuzzleVelocity = *(const uint *)&source->m_fMuzzleVelocity; // +0x54c.
  *(uint *)&this->m_MuzzleScale = *(const uint *)&source->m_MuzzleScale;         // +0x550.
  const uint averageChangeBits = *(const uint *)&source->m_fAverageDegChanges;   // +0x554, read under state -1.
  constructionState = 0;
  *(uint *)&this->m_fAverageDegChanges = averageChangeBits;
  *(uint *)&this->m_fAverageDegTable[0] = *(const uint *)&source->m_fAverageDegTable[0]; // +0x558.
  *(uint *)&this->m_fAverageDegTable[1] = *(const uint *)&source->m_fAverageDegTable[1]; // +0x55c.
  *(uint *)&this->m_fAverageDegTable[2] = *(const uint *)&source->m_fAverageDegTable[2]; // +0x560.
  *(uint *)&this->m_fAverageDegTable[3] = *(const uint *)&source->m_fAverageDegTable[3]; // +0x564.
  *(uint *)&this->m_fAverageDegTable[4] = *(const uint *)&source->m_fAverageDegTable[4]; // +0x568.
  *(uint *)&this->m_fStablePercentage = *(const uint *)&source->m_fStablePercentage;     // +0x56c.
  *(uint *)&this->m_fWorstAccuracy = *(const uint *)&source->m_fWorstAccuracy;           // +0x570.
  *(uint *)&this->m_fOldWorstAccuracy = *(const uint *)&source->m_fOldWorstAccuracy;     // +0x574.
  *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&source->m_fEffectiveAccuracy;   // +0x578.
  *(uint *)&this->m_fDesiredAccuracy = *(const uint *)&source->m_fDesiredAccuracy;       // +0x57c.
  *(uint *)&this->m_fMaxAngleError = *(const uint *)&source->m_fMaxAngleError;           // +0x580.
  *(uint *)&this->m_fCurrentFireJump = *(const uint *)&source->m_fCurrentFireJump;       // +0x584.
  *(uint *)&this->m_fFireSoundRadius = *(const uint *)&source->m_fFireSoundRadius;       // +0x588.
  *(uint *)&this->m_fRateOfFire = *(const uint *)&source->m_fRateOfFire;                 // +0x58c.
  *(uint *)&this->m_fDisplayFOV = *(const uint *)&source->m_fDisplayFOV;                 // +0x590.
  this->m_WeaponIcon = source->m_WeaponIcon;                                             // +0x594.
  this->m_ReticuleInstance = source->m_ReticuleInstance;                                 // +0x598.
  this->m_pEmptyShellsEmitter = source->m_pEmptyShellsEmitter;                           // +0x59c.
  this->m_pMuzzleFlashEmitter = source->m_pMuzzleFlashEmitter;                           // +0x5a0.
  this->m_pBulletClass = source->m_pBulletClass;                                         // +0x5a4.
  this->m_pEmptyShells = source->m_pEmptyShells;                                         // +0x5a8.
  this->m_pMuzzleFlash = source->m_pMuzzleFlash;                                         // +0x5ac.
  this->m_stWeaponCaps.bSingle = source->m_stWeaponCaps.bSingle;                         // +0x5b0.
  this->m_stWeaponCaps.bThreeRound = source->m_stWeaponCaps.bThreeRound;                 // +0x5b4.
  this->m_stWeaponCaps.bFullAuto = source->m_stWeaponCaps.bFullAuto;                     // +0x5b8.
  this->m_stWeaponCaps.bCMag = source->m_stWeaponCaps.bCMag;                             // +0x5bc.
  this->m_stWeaponCaps.bSilencer = source->m_stWeaponCaps.bSilencer;                     // +0x5c0.
  this->m_stWeaponCaps.bLight = source->m_stWeaponCaps.bLight;                           // +0x5c4.
  this->m_stWeaponCaps.bMiniScope = source->m_stWeaponCaps.bMiniScope;                   // +0x5c8.
  this->m_stWeaponCaps.bHeatVision = source->m_stWeaponCaps.bHeatVision;                 // +0x5cc.
  this->m_rLastRotation.Pitch = source->m_rLastRotation.Pitch;                           // +0x5d0.
  this->m_rLastRotation.Yaw = source->m_rLastRotation.Yaw;                               // +0x5d4.
  this->m_rLastRotation.Roll = source->m_rLastRotation.Roll;                             // +0x5d8.
  this->m_rBuckFirstBullet.Pitch = source->m_rBuckFirstBullet.Pitch;                     // +0x5dc.
  this->m_rBuckFirstBullet.Yaw = source->m_rBuckFirstBullet.Yaw;                         // +0x5e0.
  this->m_rBuckFirstBullet.Roll = source->m_rBuckFirstBullet.Roll;                       // +0x5e4.
  *(uint *)&this->m_stAccuracyValues.fBaseAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fBaseAccuracy; // +0x5e8.
  *(uint *)&this->m_stAccuracyValues.fShuffleAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fShuffleAccuracy; // +0x5ec.
  *(uint *)&this->m_stAccuracyValues.fWalkingAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fWalkingAccuracy; // +0x5f0.
  *(uint *)&this->m_stAccuracyValues.fWalkingFastAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fWalkingFastAccuracy; // +0x5f4.
  *(uint *)&this->m_stAccuracyValues.fRunningAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fRunningAccuracy; // +0x5f8.
  *(uint *)&this->m_stAccuracyValues.fReticuleTime =
      *(const uint *)&source->m_stAccuracyValues.fReticuleTime; // +0x5fc.
  *(uint *)&this->m_stAccuracyValues.fAccuracyChange =
      *(const uint *)&source->m_stAccuracyValues.fAccuracyChange;                                          // +0x600.
  *(uint *)&this->m_stAccuracyValues.fWeaponJump = *(const uint *)&source->m_stAccuracyValues.fWeaponJump; // +0x604.
  *(uint *)&this->m_vPawnLocWhenKilled.X = *(const uint *)&source->m_vPawnLocWhenKilled.X;                 // +0x608.
  *(uint *)&this->m_vPawnLocWhenKilled.Y = *(const uint *)&source->m_vPawnLocWhenKilled.Y;                 // +0x60c.
  *(uint *)&this->m_vPawnLocWhenKilled.Z = *(const uint *)&source->m_vPawnLocWhenKilled.Z;                 // +0x610.
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szReticuleClass,
                               (const FStringNoInit *)&source->m_szReticuleClass); // +0x614.
  constructionState = 1;
  FStringNoInit::FStringNoInit((FStringNoInit *)&this->m_szWithWeaponReticuleClass,
                               (const FStringNoInit *)&source->m_szWithWeaponReticuleClass); // +0x620.
  ExceptionList = previousExceptionList;
  return this;
}

// R6Weapons.dll @ 10001660 : assign the base and reflected members
// Assigns inventory in twenty forward byte transfers, preserves raw scalar words and assigns both strings.
AR6Weapons *__thiscall AR6Weapons::operator=(AR6Weapons *this, const AR6Weapons * source) {
  uint *destinationFlags = (uint *)((byte *)this + 0x548);
  const uint *sourceFlags = (const uint *)((const byte *)source + 0x548);

  AR6AbstractWeapon::operator=((AR6AbstractWeapon *)this, (const AR6AbstractWeapon *)source);
  for (uint bulletIndex = 0; bulletIndex != 20; ++bulletIndex)
    this->m_aiNbOfBullets[bulletIndex] = source->m_aiNbOfBullets[bulletIndex];         // Byte storage +0x50c..+0x51f.
  *(byte *)&this->m_iNbOfRoundsInBurst = *(const byte *)&source->m_iNbOfRoundsInBurst; // +0x520.
  *(byte *)&this->m_eRateOfFire = *(const byte *)&source->m_eRateOfFire;               // +0x521.
  *(byte *)&this->m_wNbOfBounce = *(const byte *)&source->m_wNbOfBounce;               // +0x522.
  this->C_iMaxNbOfClips = source->C_iMaxNbOfClips;                                     // +0x524.
  this->m_iClipCapacity = source->m_iClipCapacity;                                     // +0x528.
  this->m_iNbOfClips = source->m_iNbOfClips;                                           // +0x52c.
  this->m_iNbOfExtraClips = source->m_iNbOfExtraClips;                                 // +0x530.
  this->m_iCurrentClip = source->m_iCurrentClip;                                       // +0x534.
  this->m_iNbOfRoundsToShoot = source->m_iNbOfRoundsToShoot;                           // +0x538.
  this->m_iCurrentNbOfClips = source->m_iCurrentNbOfClips;                             // +0x53c.
  const int currentAverage = source->m_iCurrentAverage;                                // +0x540.
  const uint earlyDestinationFlags = *destinationFlags; // Native snapshot precedes the next two stores.
  this->m_iCurrentAverage = currentAverage;
  const int nextReticule = source->m_iDbgNextReticule; // +0x544.
  uint copiedFlags = *destinationFlags;                // Assignment reloads before the +0x544 store.
  this->m_iDbgNextReticule = nextReticule;
  copiedFlags ^= (*sourceFlags ^ earlyDestinationFlags) & 0x1; // m_bPlayLoopingSound.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2; // m_bSoundLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4; // bShowLog.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8; // m_bFireOn.
  *destinationFlags = copiedFlags;
  copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x10; // m_bEmptyAllClips.
  *destinationFlags = copiedFlags;
  *(uint *)&this->m_fMuzzleVelocity = *(const uint *)&source->m_fMuzzleVelocity;         // +0x54c.
  *(uint *)&this->m_MuzzleScale = *(const uint *)&source->m_MuzzleScale;                 // +0x550.
  *(uint *)&this->m_fAverageDegChanges = *(const uint *)&source->m_fAverageDegChanges;   // +0x554.
  *(uint *)&this->m_fAverageDegTable[0] = *(const uint *)&source->m_fAverageDegTable[0]; // +0x558.
  *(uint *)&this->m_fAverageDegTable[1] = *(const uint *)&source->m_fAverageDegTable[1]; // +0x55c.
  *(uint *)&this->m_fAverageDegTable[2] = *(const uint *)&source->m_fAverageDegTable[2]; // +0x560.
  *(uint *)&this->m_fAverageDegTable[3] = *(const uint *)&source->m_fAverageDegTable[3]; // +0x564.
  *(uint *)&this->m_fAverageDegTable[4] = *(const uint *)&source->m_fAverageDegTable[4]; // +0x568.
  *(uint *)&this->m_fStablePercentage = *(const uint *)&source->m_fStablePercentage;     // +0x56c.
  *(uint *)&this->m_fWorstAccuracy = *(const uint *)&source->m_fWorstAccuracy;           // +0x570.
  *(uint *)&this->m_fOldWorstAccuracy = *(const uint *)&source->m_fOldWorstAccuracy;     // +0x574.
  *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&source->m_fEffectiveAccuracy;   // +0x578.
  *(uint *)&this->m_fDesiredAccuracy = *(const uint *)&source->m_fDesiredAccuracy;       // +0x57c.
  *(uint *)&this->m_fMaxAngleError = *(const uint *)&source->m_fMaxAngleError;           // +0x580.
  *(uint *)&this->m_fCurrentFireJump = *(const uint *)&source->m_fCurrentFireJump;       // +0x584.
  *(uint *)&this->m_fFireSoundRadius = *(const uint *)&source->m_fFireSoundRadius;       // +0x588.
  *(uint *)&this->m_fRateOfFire = *(const uint *)&source->m_fRateOfFire;                 // +0x58c.
  *(uint *)&this->m_fDisplayFOV = *(const uint *)&source->m_fDisplayFOV;                 // +0x590.
  this->m_WeaponIcon = source->m_WeaponIcon;                                             // +0x594.
  this->m_ReticuleInstance = source->m_ReticuleInstance;                                 // +0x598.
  this->m_pEmptyShellsEmitter = source->m_pEmptyShellsEmitter;                           // +0x59c.
  this->m_pMuzzleFlashEmitter = source->m_pMuzzleFlashEmitter;                           // +0x5a0.
  this->m_pBulletClass = source->m_pBulletClass;                                         // +0x5a4.
  this->m_pEmptyShells = source->m_pEmptyShells;                                         // +0x5a8.
  this->m_pMuzzleFlash = source->m_pMuzzleFlash;                                         // +0x5ac.
  this->m_stWeaponCaps.bSingle = source->m_stWeaponCaps.bSingle;                         // +0x5b0.
  this->m_stWeaponCaps.bThreeRound = source->m_stWeaponCaps.bThreeRound;                 // +0x5b4.
  this->m_stWeaponCaps.bFullAuto = source->m_stWeaponCaps.bFullAuto;                     // +0x5b8.
  this->m_stWeaponCaps.bCMag = source->m_stWeaponCaps.bCMag;                             // +0x5bc.
  this->m_stWeaponCaps.bSilencer = source->m_stWeaponCaps.bSilencer;                     // +0x5c0.
  this->m_stWeaponCaps.bLight = source->m_stWeaponCaps.bLight;                           // +0x5c4.
  this->m_stWeaponCaps.bMiniScope = source->m_stWeaponCaps.bMiniScope;                   // +0x5c8.
  this->m_stWeaponCaps.bHeatVision = source->m_stWeaponCaps.bHeatVision;                 // +0x5cc.
  this->m_rLastRotation.Pitch = source->m_rLastRotation.Pitch;                           // +0x5d0.
  this->m_rLastRotation.Yaw = source->m_rLastRotation.Yaw;                               // +0x5d4.
  this->m_rLastRotation.Roll = source->m_rLastRotation.Roll;                             // +0x5d8.
  this->m_rBuckFirstBullet.Pitch = source->m_rBuckFirstBullet.Pitch;                     // +0x5dc.
  this->m_rBuckFirstBullet.Yaw = source->m_rBuckFirstBullet.Yaw;                         // +0x5e0.
  this->m_rBuckFirstBullet.Roll = source->m_rBuckFirstBullet.Roll;                       // +0x5e4.
  *(uint *)&this->m_stAccuracyValues.fBaseAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fBaseAccuracy; // +0x5e8.
  *(uint *)&this->m_stAccuracyValues.fShuffleAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fShuffleAccuracy; // +0x5ec.
  *(uint *)&this->m_stAccuracyValues.fWalkingAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fWalkingAccuracy; // +0x5f0.
  *(uint *)&this->m_stAccuracyValues.fWalkingFastAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fWalkingFastAccuracy; // +0x5f4.
  *(uint *)&this->m_stAccuracyValues.fRunningAccuracy =
      *(const uint *)&source->m_stAccuracyValues.fRunningAccuracy; // +0x5f8.
  *(uint *)&this->m_stAccuracyValues.fReticuleTime =
      *(const uint *)&source->m_stAccuracyValues.fReticuleTime; // +0x5fc.
  *(uint *)&this->m_stAccuracyValues.fAccuracyChange =
      *(const uint *)&source->m_stAccuracyValues.fAccuracyChange;                                          // +0x600.
  *(uint *)&this->m_stAccuracyValues.fWeaponJump = *(const uint *)&source->m_stAccuracyValues.fWeaponJump; // +0x604.
  *(uint *)&this->m_vPawnLocWhenKilled.X = *(const uint *)&source->m_vPawnLocWhenKilled.X;                 // +0x608.
  *(uint *)&this->m_vPawnLocWhenKilled.Y = *(const uint *)&source->m_vPawnLocWhenKilled.Y;                 // +0x60c.
  *(uint *)&this->m_vPawnLocWhenKilled.Z = *(const uint *)&source->m_vPawnLocWhenKilled.Z;                 // +0x610.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szReticuleClass,
                           (const FStringNoInit *)&source->m_szReticuleClass); // +0x614.
  FStringNoInit::operator=((FStringNoInit *)&this->m_szWithWeaponReticuleClass,
                           (const FStringNoInit *)&source->m_szWithWeaponReticuleClass); // +0x620.
  return this;
}

// R6Weapons.dll @ 10001960 : destroy one weapon or a counted weapon array and optionally release its allocation
// Flag 2 selects array destruction; flag 1 releases memory. The array result includes its four-byte count prefix.
// VectorDeletingDestructor is a descriptive compiler-wrapper name; the vtable points here at +0x0c.
void *__thiscall AR6Weapons::VectorDeletingDestructor(AR6Weapons *this, uint deleteFlags) {
  byte flags = (byte)deleteFlags;
  if ((flags & 2) != 0) {
    int elementCount = *(int *)((byte *)this - 4);
    byte *allocation = (byte *)this - 4;
    using ElementDestructor = void(__thiscall *)(AR6Weapons *);
    using ArrayDestructorIterator = void(__stdcall *)(void *, uint, int, ElementDestructor);
    ArrayDestructorIterator destroyElements = (ArrayDestructorIterator)&_eh_vector_destructor_iterator_; // 0x100050f4.
    ElementDestructor destroyElement =
        reinterpret_cast<ElementDestructor>(&AR6Weapons::~AR6Weapons); // AR6Weapons::~AR6Weapons.
    destroyElements(this, 0x62c, elementCount, destroyElement);
    if ((flags & 1) != 0)
      FreeThroughGlobalAllocator(allocation);
    return allocation;
  }
  AR6Weapons::~AR6Weapons(this);
  if ((flags & 1) != 0)
    UObject::operator delete(this, 0x62c); // Imported sized overload at IAT 0x1000605c.
  return this;
}

// Module helpers
// R6Weapons.dll @ 10003950 : construct AR6Weapons in supplied nonnull storage
// Returns for null storage; otherwise native code tail-jumps to the default constructor without allocating.
void __cdecl AR6Weapons::InternalConstructor(void *objectMemory) {
  if (objectMemory != nullptr)
    AR6Weapons::AR6Weapons((AR6Weapons *)objectMemory);
}

// R6Weapons.dll @ 100039e0 : test whether the current state chain excludes NormalFire
// Loads the initial state before guard state zero, then constructs a fresh NormalFire FName on each iteration.
bool __thiscall AR6Weapons::WeaponIsNotFiring(AR6Weapons *this) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponFiringStateException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  FStateFrame *stateFrame = *(FStateFrame **)((byte *)this + 0x0c);
  UState *stateNode = *(UState **)((byte *)stateFrame + 0x1c); // No state-frame null guard.
  using NameConstructor = FName *(__thiscall *)(FName *, const ushort *, EFindName);
  NameConstructor constructName =
      reinterpret_cast<NameConstructor>(nameConstructorImport); // Cached imported FName constructor.
  uint normalFireNameIndex;
  guardState = 0;
  while (stateNode != nullptr) {
    constructName((FName *)&normalFireNameIndex, (const ushort *)weaponIsNotFiringText, (EFindName)1); // FNAME_Add.
    if (*(const uint *)((const byte *)stateNode + 0x20) == normalFireNameIndex) {
      ExceptionList = previousExceptionList;
      return false; // Native result is AL only.
    }
    stateNode = *(UState **)((byte *)stateNode + 0x2c);
  }
  ExceptionList = previousExceptionList;
  return true;
}

// R6Weapons.dll @ 10003a44 : throw the unsigned-short pointer caught by the WeaponFiringState guard
// Copies the catch slot to the throw temporary; parentFrameEBP represents inherited EBP, not a native stack argument.
__declspec(noreturn) void RethrowWeaponFiringStateMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x1c);
  *(ushort **)(parentFrameEBP - 0x18) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x18,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003a58 : report the WeaponFiringState context and rethrow the active exception
// Supplies the native method context to appUnwindf before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponFiringStateException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponFiringStateContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005650 : select the WeaponFiringState exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponFiringStateException(void) {
  __asm {
    mov eax, offset weaponFiringStateFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10003bb0 : snapshot ammunition after the abstract weapon's pre-receive hook
// Zero-extends the m_iNbBulletsInWeapon byte into the shared module snapshot.
void __thiscall AR6Weapons::PreNetReceive(AR6Weapons *this) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponPreReceiveException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AR6AbstractWeapon::PreNetReceive((AR6AbstractWeapon *)this);
  previousBulletCount = (uint) * (const byte *)&this->m_iNbBulletsInWeapon; // +0x396, zero-extended.
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003bfd : throw the unsigned-short pointer caught by the WeaponPreReceive guard
// Copies the parent catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowWeaponPreReceiveMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003c11 : report the WeaponPreReceive guard context and rethrow
// Adds method context, then rethrows the active exception with two null throw-helper arguments.
__declspec(noreturn) void ReportWeaponPreReceiveException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponPreNetReceiveContext1);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005670 : select the WeaponPreReceive exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponPreReceiveException(void) {
  __asm {
    mov eax, offset weaponPreReceiveFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10003c30 : ignore pawn-passable actors or forward to the const base blocking decision
// Reads the actor flags before entering guard state zero; native code has no null-actor check.
int __thiscall AR6Weapons::IsBlockedBy(const AR6Weapons *this, const AActor *otherActor) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponBlockingException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  const uint actorFlags = *(const uint *)((const byte *)otherActor + 0xa8);
  const bool permitsPawnPassage = (actorFlags & 0x20000) != 0; // m_bPawnGoThrough.
  guardState = 0;
  int blocked = 0;
  if (!permitsPawnPassage)
    blocked = AActor::IsBlockedBy((const AActor *)this, otherActor);
  ExceptionList = previousExceptionList;
  return blocked;
}

// R6Weapons.dll @ 10003c96 : throw the unsigned-short pointer caught by the WeaponBlocking guard
// Copies the parent catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowWeaponBlockingMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10003caa : report the WeaponBlocking guard context and rethrow
// Reports the native PreNetReceive context before rethrowing.
__declspec(noreturn) void ReportWeaponBlockingException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponPreNetReceiveContext2);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005680 : select the WeaponBlocking exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponBlockingException(void) {
  __asm {
    mov eax, offset weaponBlockingFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10003f40 : process actor state, then dispatch particles for a pawn owner
// A failed controller class test supplies null; a failed owner class test suppresses dispatch.
void __thiscall AR6Weapons::ProcessState(AR6Weapons *this, float deltaSeconds) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponProcessStateException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AActor::ProcessState((AActor *)this, deltaSeconds);
  AActor *owner = this->Owner; // +0x140, loaded after base processing.
  if (owner != nullptr) {
    const UClass *ownerClass = *(const UClass **)((byte *)owner + 0x24);
    const UClass *pawnClass = (const UClass *)AR6Pawn_PrivateStaticClass_exref;
    while (ownerClass != nullptr && ownerClass != pawnClass)
      ownerClass = *(const UClass **)((const byte *)ownerClass + 0x2c);
    if (ownerClass != nullptr || pawnClass == nullptr) { // Retains native null-target success on chain exhaustion.
      AR6Pawn *ownerPawn = (AR6Pawn *)owner;
      AController *controller = ownerPawn->Controller; // +0x4ec, only after the owner class test succeeds.
      AR6PlayerController *playerController = nullptr;
      if (controller != nullptr) {
        const UClass *controllerClass = *(const UClass **)((byte *)controller + 0x24);
        const UClass *playerClass = (const UClass *)AR6PlayerController_PrivateStaticClass_exref;
        while (controllerClass != nullptr && controllerClass != playerClass)
          controllerClass = *(const UClass **)((const byte *)controllerClass + 0x2c);
        if (controllerClass != nullptr || playerClass == nullptr)
          playerController = (AR6PlayerController *)controller;
      }
      using ParticleDispatcher = void(__thiscall *)(AR6Weapons *, AR6Pawn *, AR6PlayerController *);
      const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
      ParticleDispatcher showParticles = reinterpret_cast<ParticleDispatcher>(vtable->ShowWeaponParticles);
      showParticles(this, ownerPawn, playerController);
    }
  }
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10003ff3 : throw the unsigned-short pointer caught by the WeaponProcessState guard
// Copies the catch slot to the throw temporary; parentFrameEBP represents inherited EBP, not a native stack argument.
__declspec(noreturn) void RethrowWeaponProcessStateMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004007 : report the WeaponProcessState context and rethrow the active exception
// Supplies the native method context to appUnwindf before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponProcessStateException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponProcessStateContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100056c0 : select the WeaponProcessState exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponProcessStateException(void) {
  __asm {
    mov eax, offset weaponProcessStateFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004030 : update equipped-weapon accuracy, reticule state and zoom-scaled angle error
// Retains optional player-controller behavior, ordered accuracy calls, raw reload copies and x87 spill points.
void __thiscall AR6Weapons::TickAuthoritative(AR6Weapons *this, float deltaSeconds) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponTickException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AActor::TickAuthoritative((AActor *)this, deltaSeconds);
  do {
    AActor *owner = this->Owner;
    if (owner == nullptr)
      break;
    const UClass *ownerClass = *(const UClass **)((byte *)owner + 0x24);
    const UClass *pawnClass = (const UClass *)AR6Pawn_PrivateStaticClass_exref;
    while (ownerClass != nullptr && ownerClass != pawnClass)
      ownerClass = *(const UClass **)((const byte *)ownerClass + 0x2c);
    if (ownerClass == nullptr && pawnClass != nullptr)
      break;
    AR6Pawn *ownerPawn = (AR6Pawn *)owner;
    AController *controller = ownerPawn->Controller;
    AR6PlayerController *playerController = nullptr;
    if (controller != nullptr) {
      const UClass *controllerClass = *(const UClass **)((byte *)controller + 0x24);
      const UClass *playerClass = (const UClass *)AR6PlayerController_PrivateStaticClass_exref;
      while (controllerClass != nullptr && controllerClass != playerClass)
        controllerClass = *(const UClass **)((const byte *)controllerClass + 0x2c);
      if (controllerClass != nullptr || playerClass == nullptr)
        playerController = (AR6PlayerController *)controller;
    }
    if (ownerPawn->EngineWeapon != this || ownerPawn->Controller == nullptr)
      break;
    if (playerController != nullptr) {
      APawn *playerPawn = playerController->Pawn; // One native pointer load for both equipment checks.
      if (playerPawn == nullptr || playerPawn->EngineWeapon == nullptr)
        break;
    }
    if ((*(const uint *)((const byte *)ownerPawn + 0x6c4) & 0x40000) != 0) { // m_bReloadingWeapon.
      const byte weaponType = this->m_eWeaponType;
      const float *reloadAccuracy = weaponType == 3 ? &this->m_stAccuracyValues.fWalkingFastAccuracy
                                                    : &this->m_stAccuracyValues.fRunningAccuracy; // +0x5f4 or +0x5f8.
      const uint reloadAccuracyBits = *(const uint *)reloadAccuracy;
      *(uint *)&this->m_fDesiredAccuracy = reloadAccuracyBits; // Walking-fast for type 3, otherwise running accuracy.
      *(uint *)&this->m_fEffectiveAccuracy = reloadAccuracyBits;
    } else {
      const float stanceModifier = (float)AR6Pawn::eventGetStanceReticuleModifier(ownerPawn);
      float zoomFactor = 0.0f;
      if (playerController != nullptr)
        zoomFactor = (float)AR6PlayerController::eventGetZoomMultiplyFactor(playerController, this->m_fMaxZoom);
      using AccuracyMethod = float(__thiscall *)(AR6Weapons *, float, float);
      const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
      AccuracyMethod computeEffectiveAccuracy = reinterpret_cast<AccuracyMethod>(vtable->ComputeEffectiveAccuracy);
      const float effectiveSpill = (float)computeEffectiveAccuracy(this, deltaSeconds, stanceModifier);
      *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&effectiveSpill;
      // Reloaded after the effective-accuracy callback.
      vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
      AccuracyMethod getMovingModifier = reinterpret_cast<AccuracyMethod>(vtable->GetMovingModifier);
      const float desiredSpill =
          (float)getMovingModifier(this, deltaSeconds, playerController != nullptr ? zoomFactor : 1.0f);
      *(uint *)&this->m_fDesiredAccuracy = *(const uint *)&desiredSpill;
      if (ownerPawn->Controller != nullptr &&
          (playerController == nullptr || (*(const uint *)((const byte *)playerController + 0x838) & 0x200) == 0)) {
        const float10 scaledFireJump = (float10)stanceModifier * (float10)this->m_fCurrentFireJump;
        this->m_fCurrentFireJump = 0.0f; // Native multiply precedes this clear; the effective-accuracy load follows it.
        this->m_fEffectiveAccuracy = (float)(scaledFireJump + (float10)this->m_fEffectiveAccuracy);
      }
      const float10 effectiveForCap = (float10)this->m_fEffectiveAccuracy;
      if (effectiveForCap > (float10)this->m_stAccuracyValues.fRunningAccuracy)
        *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&this->m_stAccuracyValues.fRunningAccuracy;
    }
    AR6Reticule *reticule = this->m_ReticuleInstance;
    if (reticule != nullptr) {
      const uint accuracyWord = *(const uint *)&this->m_fEffectiveAccuracy;
      AR6Reticule::UpdateReticule(reticule, playerController, *(const float *)&accuracyWord);
    }
    const float10 accuracyForAngle = (float10)this->m_fEffectiveAccuracy; // Fresh after the reticule call.
    this->m_fMaxAngleError = (float)accuracyForAngle;
    if (playerController != nullptr) {
      float10 zoomAdjustment = (float10) * (const float *)GZoomAdjustment_exref;
      const byte weaponType = this->m_eWeaponType;
      if (weaponType == 4) {
        const uint controllerFlags = *(const uint *)((const byte *)playerController + 0x838);
        if ((controllerFlags & 1) != 0) { // m_bHelmetCameraOn, using the native reflected name.
          zoomAdjustment = (controllerFlags & 2) != 0 ? (float10) * (const float *)GZoomAdjustmentSniperZoom_exref
                                                      : (float10) * (const float *)GZoomAdjustmentSniperNoZoom_exref;
        }
      } else if ((*(const byte *)((const byte *)playerController + 0x838) & 4) != 0) { // m_bSniperMode.
        zoomAdjustment = (float10) * (const float *)GZoomAdjustmentSniperMode_exref;
      }
      this->m_fMaxAngleError = (float)(accuracyForAngle * zoomAdjustment);
    }
  } while (false);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 100042e5 : throw the unsigned-short pointer caught by the authoritative tick guard
// Copies the catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a native stack argument.
__declspec(noreturn) void RethrowWeaponTickMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x24);
  *(ushort **)(parentFrameEBP - 0x20) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x20,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 100042f9 : report authoritative weapon tick context and rethrow the active exception
// Adds the native TickAuthoritative context before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponTickException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponAuthoritativeTickContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100056d0 : select authoritative weapon tick exception metadata and tail-transfer to the CRT
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponTickException(void) {
  __asm {
    mov eax, offset weaponTickFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004320 : emit due weapon particles and update camera-dependent muzzle lighting
// Captures the pending count before guard state zero and reloads array/view/weapon data between callbacks.
void __thiscall AR6Weapons::ShowWeaponParticles(AR6Weapons *this, AR6Pawn *ownerPawn,
                                                AR6PlayerController *playerController) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponParticlesException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  const int pendingParticles = this->m_iNbParticlesToCreate; // +0x398, read while guard state is -1.
  guardState = 0;
  using ParticleSpawner = void(__thiscall *)(UParticleEmitter *, int);
  do {
    if (pendingParticles <= 0) {
      AEmitter *muzzleFlash = this->m_pMuzzleFlashEmitter;
      byte *muzzleBytes = (byte *)muzzleFlash;
      if (muzzleFlash != nullptr && *(const int *)(muzzleBytes + 0x39c) != 0) {
        const uint lightFlags = *(const uint *)(muzzleBytes + 0xa0) & ~0x100U;
        *(byte *)(muzzleBytes + 0x36) = 0;          // LightType.
        *(uint *)(muzzleBytes + 0xa0) = lightFlags; // Clear bDynamicLight only.
      }
      break;
    }
    ALevelInfo *level = this->Level; // +0x144.
    const float10 comparedTime = (float10)level->TimeSeconds;
    if (!(comparedTime >= (float10)this->m_fTimeDisplayParticule))
      break;
    const float10 rateOfFire = (float10)this->m_fRateOfFire;
    const float10 nextParticleTime = rateOfFire + (float10)level->TimeSeconds;
    this->m_iNbParticlesToCreate = pendingParticles - 1;
    this->m_fTimeDisplayParticule = (float)nextParticleTime; // x87 float32 spill after the count store.
    if (level->NetMode == 3) {
      uint weaponFlags = *(uint *)((byte *)this + 0x3a0);
      weaponFlags |= 0x10; // bFiredABullet.
      *(uint *)((byte *)this + 0x3a0) = weaponFlags;
      const uint pawnFlags = *(const uint *)((const byte *)ownerPawn + 0x3e0);
      if ((pawnFlags & 0x200) != 0 && (weaponFlags & 2) != 0) // m_bIsProne and captured m_bBipod.
        AR6Pawn::eventUpdateBipodPosture(ownerPawn);
      else
        APawn::eventPlayWeaponAnimation((APawn *)ownerPawn);
    }
    UEngine *engine = *(UEngine **)((byte *)this->XLevel + 0x44);
    UClient *client = engine->Client; // Engine +0x44.
    UPlayer **nativePlayers = *(UPlayer ***)((byte *)client + 0x30);
    AR6PlayerController *localController = (AR6PlayerController *)nativePlayers[0]->Actor; // Player +0x34.
    if (localController->Pawn != ownerPawn && localController->ViewTarget == ownerPawn &&
        (*(const byte *)((const byte *)localController + 0x524) & 0x20) == 0)
      break;

    AEmitter *muzzleFlash = this->m_pMuzzleFlashEmitter;
    byte *muzzleBytes = (byte *)muzzleFlash;
    // Emitters.Data is +0x398, Num is +0x39c. Native accepts any nonzero count for element zero.
    if (muzzleFlash != nullptr && *(const int *)(muzzleBytes + 0x39c) != 0) {
      if ((*(const byte *)((const byte *)this + 0x3a0) & 0x40) == 0) {          // m_bIsSilenced.
        const uint toggledFlags = *(const uint *)(muzzleBytes + 0xa0) ^ 0x100U; // bDynamicLight.
        *(uint *)(muzzleBytes + 0xa0) = (toggledFlags & ~0x800U) | 0x200U;
        *(byte *)(muzzleBytes + 0x36) = (byte)((toggledFlags >> 8) & 1); // LightType.
        muzzleFlash->LightBrightness = 192.0f;
        muzzleFlash->LightHue = 192;
        muzzleFlash->LightSaturation = 192;
        muzzleFlash->LightRadius = 10.0f;
      }
      {
        UParticleEmitter *particle = (*(UParticleEmitter ***)(muzzleBytes + 0x398))[0];
        if (particle != nullptr) {
          ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
          spawnParticles(particle, 1);
        }
      }
      if (*(const int *)(muzzleBytes + 0x39c) > 1) {
        UParticleEmitter *particle = (*(UParticleEmitter ***)(muzzleBytes + 0x398))[1];
        if (particle != nullptr) {
          ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
          spawnParticles(particle, 1);
        }
      }
      if ((*(const byte *)((const byte *)this + 0x3a0) & 0x40) == 0 && (playerController != localController ||
           (*(const byte *)((const byte *)playerController + 0x524) & 0x20) != 0)) {
        if (*(const int *)(muzzleBytes + 0x39c) > 2) {
          UParticleEmitter *particle = (*(UParticleEmitter ***)(muzzleBytes + 0x398))[2];
          if (particle != nullptr) {
            ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
            spawnParticles(particle, 1);
          }
        }
        if (*(const int *)(muzzleBytes + 0x39c) > 3) {
          UParticleEmitter *particle = (*(UParticleEmitter ***)(muzzleBytes + 0x398))[3];
          if (particle != nullptr) {
            ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
            spawnParticles(particle, 1);
          }
        }
      }
      if ((*(const byte *)((const byte *)this + 0x3a0) & 0x40) == 0 && playerController == localController &&
          (*(const byte *)((const byte *)playerController + 0x524) & 0x20) == 0 &&
          (*(const byte *)((const byte *)playerController + 0x838) & 4) == 0) {
        if (*(const int *)(muzzleBytes + 0x39c) > 4) {
          UParticleEmitter *particle = (*(UParticleEmitter ***)(muzzleBytes + 0x398))[4];
          if (particle != nullptr) {
            ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
            spawnParticles(particle, 1);
          }
        }
      }
    }
    AEmitter *emptyShells = this->m_pEmptyShellsEmitter; // Reloaded after all muzzle callbacks.
    byte *shellBytes = (byte *)emptyShells;
    if (emptyShells != nullptr && *(const int *)(shellBytes + 0x39c) != 0) {
      UParticleEmitter *particle = (*(UParticleEmitter ***)(shellBytes + 0x398))[0];
      if (particle != nullptr) {
        ParticleSpawner spawnParticles = *(ParticleSpawner *)(*(uint *)particle + 0x88);
        spawnParticles(particle, 1);
      }
    }
  } while (false);
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10004585 : throw the unsigned-short pointer caught by the weapon particle guard
// Copies the catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a native stack argument.
__declspec(noreturn) void RethrowWeaponParticlesMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004599 : report weapon particle context and rethrow the active exception
// Adds the native ShowWeaponParticles context before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponParticlesException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponParticlesContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100056e0 : select weapon particle exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponParticlesException(void) {
  __asm {
    mov eax, offset weaponParticlesFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004600 : calculate movement, posture and rotation-dependent worst accuracy
// Retains wrapped rotation differences, asymmetric conversions, unchecked history indexing and native store order.
float __thiscall AR6Weapons::GetMovingModifier(AR6Weapons *this, float deltaSeconds, float zoomFactor) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponMovingAccuracyException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  AR6Pawn *ownerPawn = (AR6Pawn *)this->Owner;
  void **ownerVtable = *(void ***)ownerPawn; // Native owner/vtable reads precede state zero; no null/class guard.
  FRotator rotationStorage;
  using RotationGetter = FRotator *(__thiscall *)(AActor *, FRotator *);
  guardState = 0;
  RotationGetter getViewRotation = *(RotationGetter *)((byte *)ownerVtable + 0xd4);
  FRotator *rotationResult = getViewRotation((AActor *)ownerPawn, &rotationStorage);
  const float10 accelerationY = ABS((float10)ownerPawn->Acceleration.Y);
  const int viewYaw = rotationResult->Yaw;
  const int viewPitch = rotationResult->Pitch;
  const int viewRoll = rotationResult->Roll;
  const float10 accelerationX = ABS((float10)ownerPawn->Acceleration.X);
  const float10 horizontalAcceleration = accelerationY + accelerationX;
  bool useFastMovementAccuracy = false;
  if (horizontalAcceleration > (float10)accuracyZero) {
    const uint movementFlags = *(const uint *)((const byte *)ownerPawn + 0x3e0);
    useFastMovementAccuracy = (movementFlags & (4 | 0x200)) == 0; // Neither walking nor prone.
  }
  if (useFastMovementAccuracy) {
    if (ownerPawn->m_ePawnType == 1)
      this->m_fWorstAccuracy = (float)(float10)this->m_stAccuracyValues.fWalkingFastAccuracy;
    else
      this->m_fWorstAccuracy = (float)(float10)this->m_stAccuracyValues.fRunningAccuracy;
  } else if (horizontalAcceleration > (float10)accuracyZero) {
    *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fWalkingAccuracy;
  } else {
    *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fBaseAccuracy;
  }
  if (ownerPawn->m_eHealth == 1)
    this->m_fWorstAccuracy = (float)((float10)this->m_fWorstAccuracy * (float10)injuredAccuracyMultiplier);
  const uint postureFlags = *(const uint *)((const byte *)ownerPawn + 0x3e0);
  if ((postureFlags & 0x20) != 0) { // bIsCrouched.
    this->m_fWorstAccuracy = (float)((float10)this->m_fWorstAccuracy * (float10)crouchedAccuracyMultiplier);
  } else if ((postureFlags & 0x200) != 0) { // m_bIsProne from the same flags snapshot.
    const byte weaponFlags = *(const byte *)((const byte *)this + 0x3a0);
    const float10 proneAccuracy = (float10)this->m_fWorstAccuracy;
    this->m_fWorstAccuracy = (float)(proneAccuracy * (float10)((weaponFlags & 2) != 0 ? alternateProneAccuracyMultiplier
                                                                                      : proneAccuracyMultiplier));
  }
  AController *controller = ownerPawn->Controller;
  AR6PlayerController *playerController = nullptr;
  if (controller != nullptr) {
    const UClass *controllerClass = *(const UClass **)((byte *)controller + 0x24);
    const UClass *playerClass = (const UClass *)AR6PlayerController_PrivateStaticClass_exref;
    while (controllerClass != nullptr && controllerClass != playerClass)
      controllerClass = *(const UClass **)((const byte *)controllerClass + 0x2c);
    if (controllerClass != nullptr || playerClass == nullptr)
      playerController = (AR6PlayerController *)controller;
  }
  const bool measureRotation = playerController != nullptr ||
                               (*(const byte *)((const byte *)ownerPawn + 0x3e8) & 0x10) != 0 ||
                               ownerPawn->m_ePawnType != 1;
  if (measureRotation) {
    int yawDifference;
    int pitchDifference;
    if (playerController != nullptr) {
      const uint shakeYaw = (uint)playerController->m_rCurrentShakeRotation.Yaw;
      yawDifference = (int)((uint)this->m_rLastRotation.Yaw - shakeYaw - (uint)viewYaw);
      if (yawDifference < 0)
        yawDifference = (int)(0U - (uint)yawDifference);
      const uint shakePitch = (uint)playerController->m_rCurrentShakeRotation.Pitch;
      pitchDifference = (int)((uint)this->m_rLastRotation.Pitch - shakePitch - (uint)viewPitch);
    } else {
      yawDifference = (int)((uint)this->m_rLastRotation.Yaw - (uint)viewYaw);
      if (yawDifference < 0)
        yawDifference = (int)(0U - (uint)yawDifference);
      pitchDifference = (int)((uint)this->m_rLastRotation.Pitch - (uint)viewPitch);
    }
    const float yawDelta = (float)(float10)yawDifference; // Native yaw is spilled to float32 before pitch's NEG.
    if (pitchDifference < 0)
      pitchDifference = (int)(0U - (uint)pitchDifference);
    const float10 pitchDelta = (float10)pitchDifference; // Native pitch remains in x87.
    if (yawDelta != accuracyZero || pitchDelta != (float10)accuracyZero) {
      float10 angleDelta = pitchDelta;
      if ((float10)yawDelta > pitchDelta)
        angleDelta = (float10)yawDelta;
      angleDelta *= (float10)rotationUnitDegrees; // Native double: 360 / 65536.
      if (angleDelta > (float10)halfRotationDegrees)
        angleDelta = (float10)fullRotationDegrees - angleDelta;
      const float10 scaledAngle = angleDelta * (float10)zoomFactor;
      const int sampleIndex = this->m_iCurrentAverage;
      const float10 sampleRate = scaledAngle / (float10)deltaSeconds;
      const uint sampleAddress = (uint)this + 0x558U + (uint)sampleIndex * 4U;
      *(float *)sampleAddress = (float)sampleRate; // Unchecked native 32-bit effective address.
      float10 sampleSum = (float10)this->m_fAverageDegTable[4];
      const int indexForAdvance = this->m_iCurrentAverage; // Fresh after the unchecked sample store.
      sampleSum += (float10)this->m_fAverageDegTable[3];
      const int nextIndex = (int)((uint)indexForAdvance + 1U) % 5;
      sampleSum += (float10)this->m_fAverageDegTable[2];
      sampleSum += (float10)this->m_fAverageDegTable[1];
      sampleSum += (float10)this->m_fAverageDegTable[0];
      const float averageRate = (float)(sampleSum * (float10)accuracyOneFifth); // Native double coefficient.
      const int firstThreshold = rotationRateBandStep;
      const bool belowFirstThreshold = (float10)firstThreshold > (float10)averageRate;
      this->m_iCurrentAverage = nextIndex; // Native first-threshold comparison precedes both output stores.
      *(uint *)&this->m_fAverageDegChanges = *(const uint *)&averageRate;
      int rotationBand;
      if (belowFirstThreshold) {
        rotationBand = 0;
      } else {
        const int thresholdStep = rotationRateBandStep; // Native second read is conditional.
        if ((float10)(int)((uint)thresholdStep * 2U) > (float10)averageRate)
          rotationBand = 1;
        else if ((float10)(int)((uint)thresholdStep * 4U) > (float10)averageRate)
          rotationBand = 2;
        else if ((float10)(int)((uint)thresholdStep * 6U) > (float10)averageRate)
          rotationBand = 3;
        else
          rotationBand = 4;
      }
      int movementBand;
      if (this->m_fWorstAccuracy <= this->m_stAccuracyValues.fBaseAccuracy)
        movementBand = 0;
      else if (this->m_fWorstAccuracy <= this->m_stAccuracyValues.fShuffleAccuracy)
        movementBand = 1;
      else if (this->m_fWorstAccuracy <= this->m_stAccuracyValues.fWalkingAccuracy)
        movementBand = 2;
      else if (this->m_fWorstAccuracy <= this->m_stAccuracyValues.fWalkingFastAccuracy)
        movementBand = 3;
      else
        movementBand = 4;
      int combinedBand = movementBand + rotationBand;
      if (combinedBand > 4)
        combinedBand = 4;
      switch (combinedBand) {
      case 0:
        *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fBaseAccuracy;
        break;
      case 1:
        *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fShuffleAccuracy;
        break;
      case 2:
        *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fWalkingAccuracy;
        break;
      case 3:
        *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fWalkingFastAccuracy;
        break;
      case 4:
        *(uint *)&this->m_fWorstAccuracy = *(const uint *)&this->m_stAccuracyValues.fRunningAccuracy;
        break;
      }
    }
  }
  this->m_rLastRotation.Pitch = viewPitch;
  this->m_rLastRotation.Yaw = viewYaw;
  this->m_rLastRotation.Roll = viewRoll;
  if ((*(const byte *)((const byte *)ownerPawn + 0x3e8) & 0x10) == 0 && ownerPawn->m_ePawnType == 1) {
    float10 compressedAccuracy = (float10)this->m_fWorstAccuracy - (float10)this->m_stAccuracyValues.fBaseAccuracy;
    compressedAccuracy *= (float10)accuracyOneFifth;
    compressedAccuracy += (float10)this->m_stAccuracyValues.fBaseAccuracy;
    this->m_fWorstAccuracy = (float)compressedAccuracy;
  }
  const float10 result = (float10)this->m_fWorstAccuracy; // Native return load still has the guard installed.
  ExceptionList = previousExceptionList;
  return result;
}

// R6Weapons.dll @ 10004a65 : throw the unsigned-short pointer caught by the WeaponMovingAccuracy guard
// Copies the catch slot into the throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowWeaponMovingAccuracyMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x1c) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x1c,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004a79 : report the WeaponMovingAccuracy context and rethrow the active exception
// Adds the native method context before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponMovingAccuracyException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponMovingAccuracyContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 100056f0 : select the WeaponMovingAccuracy exception metadata and tail-transfer to the CRT
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponMovingAccuracyException(void) {
  __asm {
    mov eax, offset weaponMovingAccuracyFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004aa0 : recover effective accuracy toward its desired target when firing state permits
// Captures the initial worst-value comparison before state zero and retains x87 recovery and raw-copy paths.
float __thiscall AR6Weapons::ComputeEffectiveAccuracy(AR6Weapons *this, float deltaSeconds, float stanceModifier) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponEffectiveAccuracyException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  const float10 oldWorst = (float10)this->m_fOldWorstAccuracy;
  const float10 currentWorst = (float10)this->m_fWorstAccuracy;
  const bool worstChanged = currentWorst != oldWorst; // Includes unordered; native FUCOMPP precedes state zero.
  guardState = 0;
  if (worstChanged) {
    const float10 effectiveForRaise = (float10)this->m_fEffectiveAccuracy;
    if (effectiveForRaise < (float10)this->m_fWorstAccuracy)
      *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&this->m_fWorstAccuracy;
    *(uint *)&this->m_fOldWorstAccuracy = *(const uint *)&this->m_fWorstAccuracy;
  }
  const float10 effectiveForEquality = (float10)this->m_fEffectiveAccuracy;
  const float10 desiredForEquality = (float10)this->m_fDesiredAccuracy;
  if (desiredForEquality != effectiveForEquality) {
    using FiringPredicate = bool(__thiscall *)(AR6Weapons *);
    FiringPredicate weaponIsNotFiring = *(FiringPredicate *)(*(uint *)this + 0x194);
    if (weaponIsNotFiring(this)) {
      const float10 effectiveForRecovery = (float10)this->m_fEffectiveAccuracy; // Reload after the predicate.
      if (!(effectiveForRecovery > (float10)this->m_fDesiredAccuracy)) {        // Less/equal/unordered assign directly.
        *(uint *)&this->m_fEffectiveAccuracy = *(const uint *)&this->m_fDesiredAccuracy;
      } else {
        const byte weaponType = this->m_eWeaponType;
        AR6AbstractPawn *skillOwner = (AR6AbstractPawn *)this->Owner;
        const byte skillIndex = weaponType == 4 ? 3 : 0;
        const float10 skill = (float10)AR6AbstractPawn::eventGetSkill(skillOwner, skillIndex);
        float skillScratch = (float)skill; // Native nonpopping FST; recovery keeps the extended return value.
        float10 recoveryFactor = skill * (float10)recoverySkillScale;
        recoveryFactor = (float10)recoveryFactorIntercept - recoveryFactor;
        if (recoveryFactor <= (float10)accuracyZero)
          recoveryFactor = (float10)accuracyZero; // Unordered factor is retained.
        const float10 runningAccuracy = (float10)this->m_stAccuracyValues.fRunningAccuracy;
        const uint desiredBits = *(const uint *)&this->m_fDesiredAccuracy;
        const float10 accuracySpan = runningAccuracy - (float10)this->m_stAccuracyValues.fBaseAccuracy;
        const float &desiredSnapshot = *(const float *)&desiredBits;
        float10 recoveryTime = (float10)this->m_stAccuracyValues.fReticuleTime * (float10)reticuleRecoveryTimeScale;
        recoveryTime *= recoveryFactor;
        recoveryTime /= (float10)stanceModifier;
        float10 recoveryAmount = accuracySpan / recoveryTime;
        recoveryAmount *= (float10)deltaSeconds;
        float10 recoveredAccuracy = (float10)this->m_fEffectiveAccuracy - recoveryAmount;
        if (!(recoveredAccuracy >= (float10)desiredSnapshot))
          recoveredAccuracy = (float10)desiredSnapshot;
        this->m_fEffectiveAccuracy = (float)recoveredAccuracy;
      }
    }
  }
  const float10 result = (float10)this->m_fEffectiveAccuracy;
  ExceptionList = previousExceptionList;
  return result;
}

// R6Weapons.dll @ 10004bfe : throw the unsigned-short pointer caught by the WeaponEffectiveAccuracy guard
// Copies the catch slot into the throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowWeaponEffectiveAccuracyMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x1c);
  *(ushort **)(parentFrameEBP - 0x18) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x18,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004c12 : report the WeaponEffectiveAccuracy context and rethrow the active exception
// Adds the native method context before the two-null-argument rethrow.
__declspec(noreturn) void ReportWeaponEffectiveAccuracyException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponEffectiveAccuracyContext);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005700 : select the WeaponEffectiveAccuracy exception metadata and tail-transfer to the CRT
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponEffectiveAccuracyException(void) {
  __asm {
    mov eax, offset weaponEffectiveAccuracyFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10004c30 : hide an emptied attachment and update bipod state after replication
// Reloads bipod flags after the optional attachment event, preserving that event's side effects.
void __thiscall AR6Weapons::PostNetReceive(AR6Weapons *this) {
  int guardState = -1;
  byte *exceptionHandler = (byte *)&DispatchWeaponPostReceiveException;
  void *previousExceptionList = ExceptionList;
  ExceptionList = &previousExceptionList;
  guardState = 0;
  AR6AbstractWeapon::PostNetReceive((AR6AbstractWeapon *)this);
  const byte bulletCount = *(const byte *)&this->m_iNbBulletsInWeapon; // +0x396, one post-base read.
  const uint previousCount = previousBulletCount;
  if (previousCount != (uint)bulletCount && bulletCount == 0) {
    UFunction *function = UObject::FindFunctionChecked((UObject *)this, R6WEAPONS_HideAttachment, 0);
    using EventDispatcher = void(__thiscall *)(UObject *, UFunction *, void *, void *);
    // Native loads this after FindFunctionChecked.
    const NativeWeaponVTable *vtable = *reinterpret_cast<const NativeWeaponVTable *const *>(this);
    EventDispatcher processEvent = reinterpret_cast<EventDispatcher>(vtable->actor.ProcessEvent);
    processEvent((UObject *)this, function, nullptr, nullptr);
  }
  uint weaponFlags = *(uint *)((byte *)this + 0x3a0);
  if (((weaponFlags >> 1) ^ weaponFlags) & 4) { // m_bDeployBipod differs from m_bBipodDeployed.
    weaponFlags ^= ((weaponFlags << 1) ^ weaponFlags) & 8;
    *(uint *)((byte *)this + 0x3a0) = weaponFlags;
    AR6EngineWeapon::eventDeployWeaponBipod((AR6EngineWeapon *)this, (ulong)((weaponFlags >> 3) & 1));
  }
  ExceptionList = previousExceptionList;
}

// R6Weapons.dll @ 10004cd4 : throw the unsigned-short pointer caught by the WeaponPostReceive guard
// Copies the parent catch slot into its throw temporary; parentFrameEBP represents inherited EBP, not a stack argument.
__declspec(noreturn) void RethrowWeaponPostReceiveMessage(byte *parentFrameEBP) {
  ushort *caughtMessage = *(ushort **)(parentFrameEBP - 0x18);
  *(ushort **)(parentFrameEBP - 0x14) = caughtMessage;
  _CxxThrowException(parentFrameEBP - 0x14,
                     reinterpret_cast<ThrowInfo *>(const_cast<NativeThrowInfo *>(&unsignedShortPointerThrowInfo)));
}

// R6Weapons.dll @ 10004ce8 : report the WeaponPostReceive guard context and rethrow
// Reports the native PreNetReceive context before rethrowing.
__declspec(noreturn) void ReportWeaponPostReceiveException(void) {
  appUnwindf((ushort *)unwindContextFormat, (const ushort *)weaponPreNetReceiveContext3);
  _CxxThrowException(nullptr, nullptr);
}

// R6Weapons.dll @ 10005710 : select the WeaponPostReceive exception metadata and tail-transfer to the CRT dispatcher
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponPostReceiveException(void) {
  __asm {
    mov eax, offset weaponPostReceiveFuncInfo
    jmp __CxxFrameHandler
  }
}

// These cleanup views take the dispatcher's inherited EBP explicitly; it is not a native stack argument.
// R6Weapons.dll @ 10005440 : destroy the base during AR6Weapons destructor unwinding
// Releases the base after the destructor's remaining string cleanups (state 0 -> -1).
void UnwindWeaponDestructorBase(byte *parentFrameEBP) {
  AR6AbstractWeapon *weapon = *(AR6AbstractWeapon **)(parentFrameEBP - 0x10);
  AR6AbstractWeapon::~AR6AbstractWeapon(weapon);
}

// R6Weapons.dll @ 10005449 : destroy the reticule-class string during AR6Weapons destructor unwinding
// Releases m_szReticuleClass before the base cleanup (state 1 -> 0).
void UnwindWeaponDestructorReticuleClass(byte *parentFrameEBP) {
  AR6Weapons *weapon = *(AR6Weapons **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&weapon->m_szReticuleClass); // +0x614.
}

// R6Weapons.dll @ 10005458 : destroy the with-weapon reticule string during AR6Weapons destructor unwinding
// Releases m_szWithWeaponReticuleClass if ConditionalDestroy throws (state 2 -> 1).
void UnwindWeaponDestructorWithWeaponReticuleClass(byte *parentFrameEBP) {
  AR6Weapons *weapon = *(AR6Weapons **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&weapon->m_szWithWeaponReticuleClass); // +0x620.
}

// R6Weapons.dll @ 10005480 : destroy the base during AR6Weapons constructor unwinding
// Releases the constructed base for both default and copy construction (state 0 -> -1).
void UnwindWeaponConstructorBase(byte *parentFrameEBP) {
  AR6AbstractWeapon *weapon = *(AR6AbstractWeapon **)(parentFrameEBP - 0x10);
  AR6AbstractWeapon::~AR6AbstractWeapon(weapon);
}

// R6Weapons.dll @ 10005489 : destroy the reticule-class string during AR6Weapons constructor unwinding
// Releases the first string if construction of the second throws (state 1 -> 0).
void UnwindWeaponConstructorReticuleClass(byte *parentFrameEBP) {
  AR6Weapons *weapon = *(AR6Weapons **)(parentFrameEBP - 0x10);
  FStringNoInit::~FStringNoInit((FStringNoInit *)&weapon->m_szReticuleClass); // +0x614.
}

// R6Weapons.dll @ 100058a0 : initialize AR6Weapons class metadata and register its destruction
// Snapshots imported class/static-constructor pointers before config lookup; supplies a zero GUID and native flags.
void InitializeAR6WeaponsClassMetadata(void) {
  code *staticConstructor = UObject_StaticConstructor_exref;
  UClass *withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  UClass *parentClass = (UClass *)AR6AbstractWeapon_PrivateStaticClass_exref;
  const ushort *configName = UObject::StaticConfigName();
  FGuid classGuid = {0, 0, 0, 0};
  UClass::UClass(&AR6Weapons::PrivateStaticClass, (ENativeConstructor)0, 0x62c, 0, parentClass, withinClass, classGuid,
                 (const ushort *)(r6WeaponsClassNameStorage + 1), GPackage, configName, 0x4084004,
                 AR6Weapons::InternalConstructor, staticConstructor);
  _atexit(DestroyAR6WeaponsClassMetadata);
}

// R6Weapons.dll @ 10005cf0 : destroy AR6Weapons class metadata
// Destroys the metadata object registered by the class initializer; native code tail-jumps to UClass's destructor.
void DestroyAR6WeaponsClassMetadata(void) {
  UClass::~UClass(&AR6Weapons::PrivateStaticClass);
}

// R6Weapons.dll @ 10005467 : dispatch WeaponDestructor exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponDestructorException(void) {
  __asm {
    mov eax, offset weaponDestructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll @ 10005498 : dispatch WeaponConstructor exceptions using the native FuncInfo
// Supplies FuncInfo in EAX without changing the exception-dispatch stack or other registers.
__declspec(naked) void DispatchWeaponConstructorException(void) {
  __asm {
    mov eax, offset weaponConstructorFuncInfo
    jmp __CxxFrameHandler
  }
}

// R6Weapons.dll data @ 1000df50 : exported class pointer autoclassAR6Weapons
UClass *autoclassAR6Weapons = nullptr;

// R6Weapons.dll @ 10005930 : bind the exported AR6Weapons class pointer to its metadata object
// Stores the metadata address after the corresponding class initializer; no new metadata is constructed.
void InitializeAR6WeaponsAutoClass(void) {
  autoclassAR6Weapons = &AR6Weapons::PrivateStaticClass;
}
