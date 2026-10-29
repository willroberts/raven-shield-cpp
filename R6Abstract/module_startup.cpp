// Imported _exref names denote resolved export addresses, not IAT-slot addresses. Pointer globals need a further load;
// imported class objects and GNatives already denote object/array storage. Selected contracts and dereference counts:
// notes/R6Abstract/import-data-contracts.json. R6Abstract.dll data @ 1000d0b0 : exported UTF-16 package name
// used by class construction
extern "C" ushort GPackage[] = {'R', '6', 'A', 'b', 's', 't', 'r', 'a', 'c', 't', 0};
// R6Abstract.dll data @ 1000d110 : module handle last supplied to the DLL callback
void *r6AbstractModuleHandle = nullptr;
// R6Abstract.dll data @ 10011304 : successful process-attach count
int crtAttachCount = 0;
// R6Abstract.dll data @ 10011308 : snapshot of imported CRT floating-point adjustment state
uint adjustFdivSnapshot = 0;
// R6Abstract.dll data @ 1001130c : optional raw DLL notification hook
int(__stdcall *rawDllNotificationHook)(void *, uint, void *) = nullptr;
// R6Abstract.dll data @ 10011310 : mutable exclusive end of the CRT exit callback table
void(__cdecl **exitCallbacksEnd)(void) = nullptr;
// R6Abstract.dll data @ 10011314 : mutable beginning of the CRT exit callback table
void(__cdecl **exitCallbacksBegin)(void) = nullptr;

// Selected PE32 script-native descriptor and CRT callback types.
using ScriptNativeMethod = void (UObject::*)(FFrame &, void *const);
using CrtInitializer = void(__cdecl *)(void);

// R6Abstract.dll data @ 1000d000 : CRT initializer range; end-exclusive native address is 1000d084
CrtInitializer crtInitializers[33] = {
    nullptr,                                                   // 0x1000d000 -> 0x0
    InitializeAR6AbstractPawnClassMetadata,                    // 0x1000d004 -> 0x10004360
    PublishAR6AbstractPawnClassMetadata,                       // 0x1000d008 -> 0x100043f0
    InitializeAR6AbstractWeaponClassMetadata,                  // 0x1000d00c -> 0x10004400
    PublishAR6AbstractWeaponClassMetadata,                     // 0x1000d010 -> 0x10004490
    InitializeAR6AbstractBulletClassMetadata,                  // 0x1000d014 -> 0x100044a0
    PublishAR6AbstractBulletClassMetadata,                     // 0x1000d018 -> 0x10004530
    InitializeAR6AbstractGameInfoClassMetadata,                // 0x1000d01c -> 0x10004540
    PublishAR6AbstractGameInfoClassMetadata,                   // 0x1000d020 -> 0x100045d0
    InitializeAR6AbstractCorpseClassMetadata,                  // 0x1000d024 -> 0x100045e0
    PublishAR6AbstractCorpseClassMetadata,                     // 0x1000d028 -> 0x10004670
    InitializeAR6AbstractGadgetClassMetadata,                  // 0x1000d02c -> 0x10004680
    PublishAR6AbstractGadgetClassMetadata,                     // 0x1000d030 -> 0x10004710
    InitializeAR6AbstractFirstPersonWeaponClassMetadata,       // 0x1000d034 ->
                                                               // 0x10004720
    PublishAR6AbstractFirstPersonWeaponClassMetadata,          // 0x1000d038 ->
                                                               // 0x100047b0
    InitializeUR6AbstractNoiseMgrClassMetadata,                // 0x1000d03c -> 0x100047c0
    PublishUR6AbstractNoiseMgrClassMetadata,                   // 0x1000d040 -> 0x10004840
    InitializeAR6AbstractInsertionZoneClassMetadata,           // 0x1000d044 -> 0x10004850
    PublishAR6AbstractInsertionZoneClassMetadata,              // 0x1000d048 -> 0x100048e0
    InitializeAR6AbstractExtractionZoneClassMetadata,          // 0x1000d04c ->
                                                               // 0x100048f0
    PublishAR6AbstractExtractionZoneClassMetadata,             // 0x1000d050 -> 0x10004980
    InitializeAR6AbstractHUDClassMetadata,                     // 0x1000d054 -> 0x10004990
    PublishAR6AbstractHUDClassMetadata,                        // 0x1000d058 -> 0x10004a20
    InitializeUR6AbstractGameServiceClassMetadata,             // 0x1000d05c -> 0x10004a30
    PublishUR6AbstractGameServiceClassMetadata,                // 0x1000d060 -> 0x10004ab0
    RegisterUR6AbstractEviLPatchServiceExecGetState,           // 0x1000d064 -> 0x10004ac0
    RegisterUR6AbstractGameServiceExecNativeSubmitMatchResult, // 0x1000d068 ->
                                                               // 0x10004ae0
    RegisterAR6AbstractCorpseExecAddImpulseToBone,             // 0x1000d06c -> 0x10004b00
    RegisterAR6AbstractCorpseExecFirstInit,                    // 0x1000d070 -> 0x10004b20
    RegisterAR6AbstractCorpseExecRenderBones,                  // 0x1000d074 -> 0x10004b40
    (CrtInitializer)&InitializeR6AbstractEventNamesAtStartup,  // 0x1000d078 ->
                                                               // 0x10004b60
    InitializeUR6AbstractEviLPatchServiceClassMetadata,        // 0x1000d07c ->
                                                               // 0x10004b70
    PublishUR6AbstractEviLPatchServiceClassMetadata,           // 0x1000d080 -> 0x10004bf0
};
