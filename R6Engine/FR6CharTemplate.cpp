#include "native_text_data.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// External native storage views; names describe roles rather than recovered original identifiers.
__declspec(naked) void __thiscall DestroyArrayPairAt40And4c(void* record);

__declspec(naked) void __cdecl ArrayPairState0Cleanup(void);

__declspec(naked) void __cdecl ArrayPairExceptionHandler(void);

// R6Engine.dll data @ 1005456c : nativeTextDot
// Native UTF-16 dot separator,including terminator.
extern const ushort nativeTextDot[2];

// R6Engine.dll data @ 10054494 : nativeText03dS
extern const ushort nativeText03dS[9];

// R6Engine.dll data @ 10054430 : nativeTextClassSInTemplateSDoesnTExist
extern const ushort nativeTextClassSInTemplateSDoesnTExist[39];

// R6Engine.dll data @ 10054630 : nativeTextErrorUnknowTypeOfTemplateInS
extern const ushort nativeTextErrorUnknowTypeOfTemplateInS[37];

// R6Engine.dll data @ 10054178 : nativeTextFR6CharTemplateGetAttachmentType
extern const ushort nativeTextFR6CharTemplateGetAttachmentType[35];

// R6Engine.dll data @ 100543e8 : nativeTextFR6CharTemplateGetClassAndChance
extern const ushort nativeTextFR6CharTemplateGetClassAndChance[35];

// R6Engine.dll data @ 100540ec : nativeTextFR6CharTemplateGetGadget
extern const ushort nativeTextFR6CharTemplateGetGadget[27];

// R6Engine.dll data @ 10054570 : nativeTextFR6CharTemplateGetGrenade
extern const ushort nativeTextFR6CharTemplateGetGrenade[28];

// R6Engine.dll data @ 10054218 : nativeTextFR6CharTemplateGetHostagePersonality
extern const ushort nativeTextFR6CharTemplateGetHostagePersonality[39];

// R6Engine.dll data @ 100544f8 : nativeTextFR6CharTemplateGetPawnClass
extern const ushort nativeTextFR6CharTemplateGetPawnClass[30];

// R6Engine.dll data @ 100544a8 : nativeTextFR6CharTemplateGetRandomClassFromList
extern const ushort nativeTextFR6CharTemplateGetRandomClassFromList[40];

// R6Engine.dll data @ 100540b8 : nativeTextFR6CharTemplateGetSkill
extern const ushort nativeTextFR6CharTemplateGetSkill[26];

// R6Engine.dll data @ 10054268 : nativeTextFR6CharTemplateGetStartingPosition
extern const ushort nativeTextFR6CharTemplateGetStartingPosition[39];

// R6Engine.dll data @ 100541c0 : nativeTextFR6CharTemplateGetTerroristPersonality
extern const ushort nativeTextFR6CharTemplateGetTerroristPersonality[41];

// R6Engine.dll data @ 10054534 : nativeTextFR6CharTemplateGetWeapon
extern const ushort nativeTextFR6CharTemplateGetWeapon[27];

// R6Engine.dll data @ 10054600 : nativeTextFR6CharTemplateInit
extern const ushort nativeTextFR6CharTemplateInit[22];

// R6Engine.dll data @ 10054884 : nativeTextFlashlight
extern const ushort nativeTextFlashlight[12];

// R6Engine.dll data @ 10054874 : nativeTextHostage
extern const ushort nativeTextHostage[8];

// R6Engine.dll data @ 10054970 : nativeTextModsSTemplate
extern const ushort nativeTextModsSTemplate[21];

// R6Engine.dll data @ 100548b8 : nativeTextNbOfGrenade
extern const ushort nativeTextNbOfGrenade[13];

// R6Engine.dll data @ 10054900 : nativeTextNbOfPawn
extern const ushort nativeTextNbOfPawn[10];

// R6Engine.dll data @ 100548d4 : nativeTextNbOfWeapon
extern const ushort nativeTextNbOfWeapon[12];

// R6Engine.dll data @ 10054480 : nativeTextNoneNone
extern const ushort nativeTextNoneNone[10];

// R6Engine.dll data @ 10054128 : nativeTextR6WeaponGadgetsR6TacticalLightGadget
extern const ushort nativeTextR6WeaponGadgetsR6TacticalLightGadget[38];

// R6Engine.dll data @ 1005489c : nativeTextRndVariation
extern const ushort nativeTextRndVariation[14];

// R6Engine.dll data @ 10054850 : nativeTextStartAsCivilian
extern const ushort nativeTextStartAsCivilian[17];

// R6Engine.dll data @ 1005499c : nativeTextTemplate
extern const ushort nativeTextTemplate[13];

// R6Engine.dll data @ 10054934 : nativeTextTemplateSSDoesnTExist
extern const ushort nativeTextTemplateSSDoesnTExist[29];

// R6Engine.dll data @ 100548ec : nativeTextTerrorist
extern const ushort nativeTextTerrorist[10];

// R6Engine.dll data @ 100546e8 : nativeTextTotalGadgetChanceIsDInTemplateS
extern const ushort nativeTextTotalGadgetChanceIsDInTemplateS[43];

// R6Engine.dll data @ 100547f8 : nativeTextTotalGrenadeChanceIsDInTemplateS
extern const ushort nativeTextTotalGrenadeChanceIsDInTemplateS[44];

// R6Engine.dll data @ 10054740 : nativeTextTotalPersonalityChanceIsDInTemplateS
extern const ushort nativeTextTotalPersonalityChanceIsDInTemplateS[48];

// R6Engine.dll data @ 10054680 : nativeTextTotalStartingPosChanceIsDInTemplateS
extern const ushort nativeTextTotalStartingPosChanceIsDInTemplateS[49];

// R6Engine.dll data @ 100547a0 : nativeTextTotalWeaponChanceIsDInTemplateS
extern const ushort nativeTextTotalWeaponChanceIsDInTemplateS[43];

// R6Engine.dll data @ 100549b8 : nativeTextTph
extern const ushort nativeTextTph[5];

// R6Engine.dll data @ 100549c4 : nativeTextTpt
extern const ushort nativeTextTpt[5];

// R6Engine.dll data @ 10054914 : nativeTextType
extern const ushort nativeTextType[6];

// R6Engine.dll data @ 10054920 : nativeTextVersion
extern const ushort nativeTextVersion[9];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateClassAndChanceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateClassAndChanceCatchPointer(void);
__declspec(naked) void __cdecl CharTemplateDestructorState0Cleanup(void);
__declspec(naked) void __cdecl CharTemplateDestructorState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetAttachmentTypeCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetAttachmentTypeCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetDataCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetDataCatchPointer(void);
__declspec(naked) void __cdecl CharTemplateGetDataState1Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGetDataState2Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGetDataState3Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGetDataState4Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGetDataState5Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetGadgetCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetGadgetCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetHostagePersonalityCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetHostagePersonalityCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetSkillCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetSkillCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetStartingPositionCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetStartingPositionCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetTerroristPersonalityCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetTerroristPersonalityCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGrenadeCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGrenadeCatchPointer(void);
__declspec(naked) void __cdecl CharTemplateGrenadeState0Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGrenadeState2Cleanup(void);
__declspec(naked) void __cdecl CharTemplateGrenadeState3Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplatePawnClassCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplatePawnClassCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateRandomClassCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateRandomClassCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateWeaponCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateWeaponCatchPointer(void);
__declspec(naked) void __cdecl CharTemplateWeaponState0Cleanup(void);
__declspec(naked) void __cdecl CharTemplateWeaponState2Cleanup(void);
__declspec(naked) void __cdecl CharTemplateWeaponState3Cleanup(void);
void __thiscall FR6CharTemplate_GetClassAndChance(
    FR6CharTemplate* charTemplate, uint* chanceAndClass, const ushort* row);
uint __stdcall FR6CharTemplate_GetRandomClassFromList(const int* classList);

// R6Engine.dll data @ 10053d78 : charTemplateTerroristPersonalityKeyRows
// Native UTF16 key rows occupy sixteen characters each, including zero-filled tails.
const wchar_t charTemplateTerroristPersonalityKeyRows[6][16] = {
    L"Coward=",
    L"DeskJockey=",
    L"Normal=",
    L"Hardened=",
    L"SuicideBomber=",
    L"PSniper="
};

// R6Engine.dll data @ 10053e38 : charTemplateHostagePersonalityKeyRows
// Native UTF16 key rows occupy sixteen characters each, including zero-filled tails.
const wchar_t charTemplateHostagePersonalityKeyRows[4][16] = {
    L"Coward=",
    L"Normal=",
    L"Brave=",
    L"Bait="
};

// R6Engine.dll data @ 10053eb8 : charTemplatePositionKeyRows
// Native UTF16 key rows occupy sixteen characters each, including zero-filled tails.
const wchar_t charTemplatePositionKeyRows[2][16] = {
    L"Kneeling=",
    L"Standing="
};

// R6Engine.dll data @ 10053ef8 : charTemplateSkillKeyRows
// Native UTF16 key rows occupy sixteen characters each, including zero-filled tails.
const wchar_t charTemplateSkillKeyRows[8][16] = {
    L"Assault=",
    L"Demolitions=",
    L"Electronics=",
    L"SSniper=",
    L"Stealth=",
    L"SelfControl=",
    L"Leadership=",
    L"Observation="
};

// R6Engine.dll data @ 10053ff8 : charTemplateAttachmentKeyRows
// Native UTF16 key rows occupy sixteen characters each, including zero-filled tails.
const wchar_t charTemplateAttachmentKeyRows[3][16] = {
    L"Glasses=",
    L"Sunglasses=",
    L"Helmet="
};

// R6Engine.dll data @ 100592bc : charTemplateDestructorUnwindMap
// Retains the native predecessor states and destructor cleanup entries.
const NativeUnwindEntry charTemplateDestructorUnwindMap[2] = {
    { -1, ((uint)&CharTemplateDestructorState0Cleanup) },
    { 0, ((uint)&CharTemplateDestructorState1Cleanup) }
};

// R6Engine.dll data @ 100592cc : charTemplateDestructorFuncInfo
// Binds cleanup states with no typed or catch-all handlers.
const NativeFunctionInfoPrefix charTemplateDestructorFuncInfo = { 0x19930520, 0x2,
    ((uint)&charTemplateDestructorUnwindMap), 0, 0, 0 };

// Routes destruction through its selected cleanup-only exception metadata.
__declspec(naked) void __cdecl CharTemplateDestructorExceptionHandler(void);

// R6Engine.dll data @ 1005dbdc : charTemplateGetSkillUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetSkillUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dbec : charTemplateGetSkillCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetSkillCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetSkillCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetSkillCatchContext) }
};

// R6Engine.dll data @ 1005dc0c : charTemplateGetSkillTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetSkillTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetSkillCatchMap) }
};

// R6Engine.dll data @ 1005dc20 : charTemplateGetSkillFuncInfo
// Binds GetSkill to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetSkillFuncInfo = { 0x19930520, 0x2, ((uint)&charTemplateGetSkillUnwindMap),
    0x1, ((uint)&charTemplateGetSkillTryMap), 0 };

// R6Engine.dll data @ 1005dc3c : charTemplateGetGadgetUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetGadgetUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dc4c : charTemplateGetGadgetCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetGadgetCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetGadgetCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetGadgetCatchContext) }
};

// R6Engine.dll data @ 1005dc6c : charTemplateGetGadgetTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetGadgetTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetGadgetCatchMap) }
};

// R6Engine.dll data @ 1005dc80 : charTemplateGetGadgetFuncInfo
// Binds GetGadget to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetGadgetFuncInfo = { 0x19930520, 0x2,
    ((uint)&charTemplateGetGadgetUnwindMap), 0x1, ((uint)&charTemplateGetGadgetTryMap), 0 };

// R6Engine.dll data @ 1005dc9c : charTemplateGetAttachmentTypeUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetAttachmentTypeUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dcac : charTemplateGetAttachmentTypeCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetAttachmentTypeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetAttachmentTypeCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetAttachmentTypeCatchContext) }
};

// R6Engine.dll data @ 1005dccc : charTemplateGetAttachmentTypeTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetAttachmentTypeTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetAttachmentTypeCatchMap) }
};

// R6Engine.dll data @ 1005dce0 : charTemplateGetAttachmentTypeFuncInfo
// Binds GetAttachmentType to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetAttachmentTypeFuncInfo = {
    0x19930520, 0x2, ((uint)&charTemplateGetAttachmentTypeUnwindMap), 0x1, ((uint)&charTemplateGetAttachmentTypeTryMap),
        0
};

// R6Engine.dll data @ 1005dcfc : charTemplateGetTerroristPersonalityUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetTerroristPersonalityUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dd0c : charTemplateGetTerroristPersonalityCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetTerroristPersonalityCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetTerroristPersonalityCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetTerroristPersonalityCatchContext) }
};

// R6Engine.dll data @ 1005dd2c : charTemplateGetTerroristPersonalityTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetTerroristPersonalityTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetTerroristPersonalityCatchMap) }
};

// R6Engine.dll data @ 1005dd40 : charTemplateGetTerroristPersonalityFuncInfo
// Binds GetTerroristPersonality to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetTerroristPersonalityFuncInfo = {
    0x19930520, 0x2, ((uint)&charTemplateGetTerroristPersonalityUnwindMap), 0x1,
        ((uint)&charTemplateGetTerroristPersonalityTryMap), 0
};

// R6Engine.dll data @ 1005dd5c : charTemplateGetHostagePersonalityUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetHostagePersonalityUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005dd6c : charTemplateGetHostagePersonalityCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetHostagePersonalityCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetHostagePersonalityCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetHostagePersonalityCatchContext) }
};

// R6Engine.dll data @ 1005dd8c : charTemplateGetHostagePersonalityTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetHostagePersonalityTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetHostagePersonalityCatchMap) }
};

// R6Engine.dll data @ 1005dda0 : charTemplateGetHostagePersonalityFuncInfo
// Binds GetHostagePersonality to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetHostagePersonalityFuncInfo = {
    0x19930520, 0x2, ((uint)&charTemplateGetHostagePersonalityUnwindMap), 0x1,
        ((uint)&charTemplateGetHostagePersonalityTryMap), 0
};

// R6Engine.dll data @ 1005ddbc : charTemplateGetStartingPositionUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGetStartingPositionUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005ddcc : charTemplateGetStartingPositionCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGetStartingPositionCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateGetStartingPositionCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetStartingPositionCatchContext) }
};

// R6Engine.dll data @ 1005ddec : charTemplateGetStartingPositionTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGetStartingPositionTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateGetStartingPositionCatchMap) }
};

// R6Engine.dll data @ 1005de00 : charTemplateGetStartingPositionFuncInfo
// Binds GetStartingPosition to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGetStartingPositionFuncInfo = {
    0x19930520, 0x2, ((uint)&charTemplateGetStartingPositionUnwindMap), 0x1,
        ((uint)&charTemplateGetStartingPositionTryMap), 0
};

// Routes GetSkill through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetSkillExceptionHandler(void);
// Routes GetGadget through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetGadgetExceptionHandler(void);
// Routes GetAttachmentType through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetAttachmentTypeExceptionHandler(void);
// Routes GetTerroristPersonality through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetTerroristPersonalityExceptionHandler(void);
// Routes GetHostagePersonality through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetHostagePersonalityExceptionHandler(void);
// Routes GetStartingPosition through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetStartingPositionExceptionHandler(void);

// R6Engine.dll data @ 1005e07c : charTemplateClassAndChanceUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateClassAndChanceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e08c : charTemplateClassAndChanceCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateClassAndChanceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&CharTemplateClassAndChanceCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateClassAndChanceCatchContext) }
};

// R6Engine.dll data @ 1005e0ac : charTemplateClassAndChanceTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateClassAndChanceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateClassAndChanceCatchMap) }
};

// R6Engine.dll data @ 1005e0c0 : charTemplateClassAndChanceFuncInfo
// Binds GetClassAndChance to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateClassAndChanceFuncInfo = { 0x19930520, 0x2,
    ((uint)&charTemplateClassAndChanceUnwindMap), 0x1, ((uint)&charTemplateClassAndChanceTryMap), 0 };

// R6Engine.dll data @ 1005e0dc : charTemplateRandomClassUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateRandomClassUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e0ec : charTemplateRandomClassCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateRandomClassCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplateRandomClassCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateRandomClassCatchContext) }
};

// R6Engine.dll data @ 1005e10c : charTemplateRandomClassTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateRandomClassTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplateRandomClassCatchMap) }
};

// R6Engine.dll data @ 1005e120 : charTemplateRandomClassFuncInfo
// Binds GetRandomClassFromList to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateRandomClassFuncInfo = { 0x19930520, 0x2,
    ((uint)&charTemplateRandomClassUnwindMap), 0x1, ((uint)&charTemplateRandomClassTryMap), 0 };

// R6Engine.dll data @ 1005e13c : charTemplatePawnClassUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplatePawnClassUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e14c : charTemplatePawnClassCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplatePawnClassCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CharTemplatePawnClassCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplatePawnClassCatchContext) }
};

// R6Engine.dll data @ 1005e16c : charTemplatePawnClassTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplatePawnClassTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&charTemplatePawnClassCatchMap) }
};

// R6Engine.dll data @ 1005e180 : charTemplatePawnClassFuncInfo
// Binds GetPawnClass to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplatePawnClassFuncInfo = { 0x19930520, 0x2,
    ((uint)&charTemplatePawnClassUnwindMap), 0x1, ((uint)&charTemplatePawnClassTryMap), 0 };

// R6Engine.dll data @ 1005e19c : charTemplateWeaponUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateWeaponUnwindMap[5] = {
    { -1, ((uint)&CharTemplateWeaponState0Cleanup) },
    { 0, 0 },
    { 0x1, ((uint)&CharTemplateWeaponState2Cleanup) },
    { 0x2, ((uint)&CharTemplateWeaponState3Cleanup) },
    { 0, 0 }
};

// R6Engine.dll data @ 1005e1c4 : charTemplateWeaponCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateWeaponCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&CharTemplateWeaponCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateWeaponCatchContext) }
};

// R6Engine.dll data @ 1005e1e4 : charTemplateWeaponTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateWeaponTryMap[1] = {
    { 0x1, 0x3, 0x4, 0x2, ((uint)&charTemplateWeaponCatchMap) }
};

// R6Engine.dll data @ 1005e1f8 : charTemplateWeaponFuncInfo
// Binds GetWeapon to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateWeaponFuncInfo = { 0x19930520, 0x5, ((uint)&charTemplateWeaponUnwindMap),
    0x1, ((uint)&charTemplateWeaponTryMap), 0 };

// R6Engine.dll data @ 1005e214 : charTemplateGrenadeUnwindMap
// Retains prior-state/cleanup pairs, including the native empty transitions.
const NativeUnwindEntry charTemplateGrenadeUnwindMap[5] = {
    { -1, ((uint)&CharTemplateGrenadeState0Cleanup) },
    { 0, 0 },
    { 0x1, ((uint)&CharTemplateGrenadeState2Cleanup) },
    { 0x2, ((uint)&CharTemplateGrenadeState3Cleanup) },
    { 0, 0 }
};

// R6Engine.dll data @ 1005e23c : charTemplateGrenadeCatchMap
// Retains exact four-word pointer/catch-all records and the signed caught-pointer frame displacement.
const NativeCatchEntry charTemplateGrenadeCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&CharTemplateGrenadeCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGrenadeCatchContext) }
};

// R6Engine.dll data @ 1005e25c : charTemplateGrenadeTryMap
// Bounds the guarded states and their two private handlers.
const NativeTryBlock charTemplateGrenadeTryMap[1] = {
    { 0x1, 0x3, 0x4, 0x2, ((uint)&charTemplateGrenadeCatchMap) }
};

// R6Engine.dll data @ 1005e270 : charTemplateGrenadeFuncInfo
// Binds GetGrenade to its exact selected MSVC state and handler maps.
const NativeFunctionInfoPrefix charTemplateGrenadeFuncInfo = { 0x19930520, 0x5, ((uint)&charTemplateGrenadeUnwindMap),
    0x1, ((uint)&charTemplateGrenadeTryMap), 0 };

// Routes GetClassAndChance through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetClassAndChanceExceptionHandler(void);
// Routes GetRandomClassFromList through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetRandomClassFromListExceptionHandler(void);
// Routes GetPawnClass through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetPawnClassExceptionHandler(void);
// Routes GetWeapon through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetWeaponExceptionHandler(void);
// Routes GetGrenade through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetGrenadeExceptionHandler(void);

// R6Engine.dll data @ 1005e38c : charTemplateGetDataUnwindMap
// Maps private states to prior states and cleanup entries; zero actions retain native empty transitions.
const NativeUnwindEntry charTemplateGetDataUnwindMap[7] = {
    { -1, 0 },
    { 0, ((uint)&CharTemplateGetDataState1Cleanup) },
    { 0x1, ((uint)&CharTemplateGetDataState2Cleanup) },
    { 0x1, ((uint)&CharTemplateGetDataState3Cleanup) },
    { 0x1, ((uint)&CharTemplateGetDataState4Cleanup) },
    { 0x4, ((uint)&CharTemplateGetDataState5Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e3c4 : charTemplateGetDataCatchMap
// Retains four-word unsigned-short-pointer and catch-all handler records with signed frame displacements.
const NativeCatchEntry charTemplateGetDataCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -108, ((uint)&CharTemplateGetDataCatchPointer) },
    { 0, 0, 0, ((uint)&CharTemplateGetDataCatchContext) }
};

// R6Engine.dll data @ 1005e3e4 : charTemplateGetDataTryMap
// Bounds the guarded private states and their two catch handlers.
const NativeTryBlock charTemplateGetDataTryMap[1] = {
    { 0, 0x5, 0x6, 0x2, ((uint)&charTemplateGetDataCatchMap) }
};

// R6Engine.dll data @ 1005e3f8 : charTemplateGetDataFuncInfo
// Binds the selected MSVC exception dispatcher to its exact state, try and catch maps.
const NativeFunctionInfoPrefix charTemplateGetDataFuncInfo = { 0x19930520, 0x7, ((uint)&charTemplateGetDataUnwindMap),
    0x1, ((uint)&charTemplateGetDataTryMap), 0 };

// Routes the parent method through its selected C++ exception metadata.
__declspec(naked) void __cdecl CharTemplateGetDataExceptionHandler(void);

// R6Engine.dll data @ 10059170 : arrayPairUnwindMap
// Retains the native predecessor states and destructor cleanup entries.
const NativeUnwindEntry arrayPairUnwindMap[1] = {
    { -1, ((uint)&ArrayPairState0Cleanup) }
};

// R6Engine.dll data @ 10059178 : arrayPairFuncInfo
// Binds cleanup states with no typed or catch-all handlers.
const NativeFunctionInfoPrefix arrayPairFuncInfo = { 0x19930520, 0x1, ((uint)&arrayPairUnwindMap), 0, 0, 0 };

// R6Engine.dll @ 10018be0 : DestroyCharTemplate
// Destroys arrays at +0x64, +0x58 and +0x0c before the leading string, preserving partial-unwind lifetimes.
void __thiscall DestroyCharTemplate(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Native ESP-relative receiver/registration slots; cleanup entries remain canonical.
        uint savedEsi;
        FR6CharTemplate* object;
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateDestructorExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    frame.object = charTemplate;
    frame.state = 1;
    DestroyArrayPairAt40And4c(reinterpret_cast<byte*>(charTemplate) + 0x18);
    *(byte*)&frame.state = 0;
    DestroyEightByteArrayStorageWithOwnGuard(reinterpret_cast<byte*>(charTemplate) + 0xc);
    frame.state = -1;
    FString::~FString(reinterpret_cast<FString*>(charTemplate));
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1003e0b0 : FR6CharTemplate::GetSkill
// Returns x87-scaled signed skill plus a wrapping random remainder, preserving the native divisor and fault behavior.
float10 __thiscall FR6CharTemplate_GetSkill(FR6CharTemplate* charTemplate, int skillIndex)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetSkillExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int random = appRand();
    uint divisorBits = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(charTemplate) + 0x30) + 1U;
    int remainder;
    // Keep x86 zero-divisor/INT_MIN divided by -1 faults; do not replace them with C++ undefined division.
    __asm {
        mov eax,random
        mov ecx,divisorBits
        cdq
        idiv ecx
        mov remainder,edx
    }
    uint skill = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(charTemplate) + 0x34 + (uint)skillIndex * 4U);
    uint sum = static_cast<uint>(remainder) + skill;
    reinterpret_cast<uint&>(skillIndex) = sum;
    float10 scaled;
    __asm { fild dword ptr skillIndex }
    ExceptionList = frame.previousExceptionList;
    // ST(0) is the signed wrapped sum; multiply after unlinking and preserve its extended result without a float32 spill.
    __asm {
        fmul dword ptr [nativeFloat0Point01]
        fstp tbyte ptr scaled
    }
    return scaled;
}

// R6Engine.dll @ 1003e10f : CharTemplateGetSkillCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetSkillCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e140 : FR6CharTemplate::GetGadget
// Constructs the tactical-light path when the signed remainder is below +0x70, otherwise constructs empty output.
FString* __thiscall FR6CharTemplate_GetGadget(FR6CharTemplate* charTemplate, FString* result)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetGadgetExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    *reinterpret_cast<uint*>(nativeFrame - 0x18) = 0;
    frame.state = 0;
    int remainder = appRand() % 100;
    int chance = *reinterpret_cast<int*>(reinterpret_cast<byte*>(charTemplate) + 0x70);
    FString* output = result;
    const ushort* text = remainder < chance ? nativeTextR6WeaponGadgetsR6TacticalLightGadget : nativeEmptyText;
    FString::FString(output, text);
    ExceptionList = frame.previousExceptionList;
    return output;
}

// R6Engine.dll @ 1003e1b2 : CharTemplateGetGadgetCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetGadgetCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e1f0 : FR6CharTemplate::GetAttachmentType
// Returns the first of three +0x74 threshold indexes that exceeds the signed random remainder, defaulting to three.
int __thiscall FR6CharTemplate_GetAttachmentType(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetAttachmentTypeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int random = appRand();
    int remainder = random % 100; // Signed IDIV remainder; thresholds are read after the random callback.
    int selected = 3;
    for (int index = 0; index < 3; ++index) {
        int threshold = *reinterpret_cast<int*>(reinterpret_cast<byte*>(charTemplate) + 0x74 + index * 4U);
        if (remainder < threshold) { selected = index; break; }
    }
    ExceptionList = frame.previousExceptionList;
    return selected;
}

// R6Engine.dll @ 1003e253 : CharTemplateGetAttachmentTypeCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetAttachmentTypeCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e290 : FR6CharTemplate::GetTerroristPersonality
// Selects the first of six +0x18 personality thresholds exceeding the signed remainder, defaulting to two.
int __thiscall FR6CharTemplate_GetTerroristPersonality(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetTerroristPersonalityExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int random = appRand();
    int remainder = random % 100; // Signed IDIV remainder; thresholds are read after the random callback.
    int selected = 2;
    for (int index = 0; index < 6; ++index) {
        int threshold = *reinterpret_cast<int*>(reinterpret_cast<byte*>(charTemplate) + 0x18 + index * 4U);
        if (remainder < threshold) { selected = index; break; }
    }
    ExceptionList = frame.previousExceptionList;
    return selected;
}

// R6Engine.dll @ 1003e2f4 : CharTemplateGetTerroristPersonalityCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetTerroristPersonalityCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e330 : FR6CharTemplate::GetHostagePersonality
// Selects the first of four +0x80 personality thresholds exceeding the signed remainder, defaulting to one.
int __thiscall FR6CharTemplate_GetHostagePersonality(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetHostagePersonalityExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int random = appRand();
    int remainder = random % 100; // Signed IDIV remainder; thresholds are read after the random callback.
    int selected = 1;
    for (int index = 0; index < 4; ++index) {
        int threshold = *reinterpret_cast<int*>(reinterpret_cast<byte*>(charTemplate) + 0x80 + index * 4U);
        if (remainder < threshold) { selected = index; break; }
    }
    ExceptionList = frame.previousExceptionList;
    return selected;
}

// R6Engine.dll @ 1003e397 : CharTemplateGetHostagePersonalityCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetHostagePersonalityCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e3d0 : FR6CharTemplate::GetStartingPosition
// Scans both +0x90 thresholds as needed and returns whether index zero was selected, with full EAX zero or one.
uint __thiscall FR6CharTemplate_GetStartingPosition(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetStartingPositionExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int random = appRand();
    int remainder = random % 100; // Signed IDIV remainder; thresholds are read after the random callback.
    int selected = 2;
    for (int index = 0; index < 2; ++index) {
        int threshold = *reinterpret_cast<int*>(reinterpret_cast<byte*>(charTemplate) + 0x90 + index * 4U);
        if (remainder < threshold) { selected = index; break; }
    }
    ExceptionList = frame.previousExceptionList;
    return selected == 0;
}

// R6Engine.dll @ 1003e43b : CharTemplateGetStartingPositionCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetStartingPositionCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003e9f0 : FR6CharTemplate::GetClassAndChance
// Parses a chance/class row, preserves the None.None sentinel and stores class before chance after load validation.
void __thiscall FR6CharTemplate_GetClassAndChance(
    FR6CharTemplate* charTemplate, uint* chanceAndClass, const ushort* row)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x114];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetClassAndChanceExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    const ushort* input = row;
    int& chance = *reinterpret_cast<int*>(nativeFrame - 0x18);
    ushort* classPath = reinterpret_cast<ushort*>(nativeFrame - 0x120);
    frame.state = 0;
    using Scan = int (__cdecl*)(const ushort*, const ushort*, ...);
    reinterpret_cast<Scan&>(CrtSwscanfImport)(input, nativeText03dS, &chance, classPath);
    // Scan result is ignored; malformed rows retain uninitialized chance/path and the unbounded %s destination.
    uint selected;
    if (appStrcmp(classPath, nativeTextNoneNone) == 0) {
        selected = 0xffffffffU;
    } else {
        UClass* required = reinterpret_cast<UClass*>(UClassPrivateStaticClassImport);
        using Load = UObject* (__cdecl*)(UClass*, UObject*, const ushort*, const ushort*, uint, void*);
        UObject* loaded = reinterpret_cast<Load&>(UObjectStaticLoadObjectImport)(required, nullptr, classPath, nullptr, 2, nullptr);
        selected = 0;
        if (loaded) {
            UClass* cursor = loaded->Class;
            required = reinterpret_cast<UClass*>(UClassPrivateStaticClassImport);
            while (cursor && cursor != required) cursor = cursor->GetSuperClass();
            if (cursor == required) selected = reinterpret_cast<uint>(loaded); // Null required type accepts exhausted chain.
        }
        *reinterpret_cast<uint*>(nativeFrame - 0x14) = selected;
        if (!selected) {
            const ushort* templateName = **reinterpret_cast<FString*>(charTemplate);
            appMsgf(0, nativeTextClassSInTemplateSDoesnTExist, classPath, templateName);
            selected = *reinterpret_cast<uint*>(nativeFrame - 0x14);
        }
    }
    uint* output = chanceAndClass;
    uint savedChance = reinterpret_cast<uint&>(chance);
    output[1] = selected;
    output[0] = savedChance; // Capture chance before class-first stores, including when output aliases parser storage.
    ExceptionList = frame.previousExceptionList;
}

// R6Engine.dll @ 1003eaec : CharTemplateClassAndChanceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x20 by value through EBP-0x1c.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateClassAndChanceCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003eb20 : FR6CharTemplate::GetRandomClassFromList
// Returns the raw class word at the first signed threshold exceeding appRand() % 100, or zero.
uint __stdcall FR6CharTemplate_GetRandomClassFromList(const int* classList)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetRandomClassFromListExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    frame.state = 0;
    int remainder = appRand() % 100;
    const byte* list = reinterpret_cast<const byte*>(classList);
    uint index = 0;
    while (static_cast<int>(index) < *reinterpret_cast<const int*>(list + 4)) {
        const byte* entries = *reinterpret_cast<const byte* const*>(list);
        int threshold = *reinterpret_cast<const int*>(entries + index * 8U);
        if (remainder < threshold) break;
        ++index;
    }
    uint selected = 0;
    if (static_cast<int>(index) < *reinterpret_cast<const int*>(list + 4)) {
        const byte* entries = *reinterpret_cast<const byte* const*>(list);
        selected = *reinterpret_cast<const uint*>(entries + index * 8U + 4);
    }
    ExceptionList = frame.previousExceptionList;
    return selected; // Zero and minus-one class words are not filtered here.
}

// R6Engine.dll @ 1003eba2 : CharTemplateRandomClassCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateRandomClassCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ebe0 : FR6CharTemplate::GetPawnClass
// Forwards the +0x0c list to selection and preserves its returned class word, including zero or minus one.
UClass* __thiscall FR6CharTemplate_GetPawnClass(FR6CharTemplate* charTemplate)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0xc];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetPawnClassExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    const int* list = reinterpret_cast<const int*>(reinterpret_cast<byte*>(charTemplate) + 0xc);
    frame.state = 0;
    uint selected = FR6CharTemplate_GetRandomClassFromList(list);
    ExceptionList = frame.previousExceptionList;
    return reinterpret_cast<UClass*>(selected);
}

// R6Engine.dll @ 1003ec22 : CharTemplatePawnClassCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplatePawnClassCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ec60 : FR6CharTemplate::GetWeapon
// Selects from +0x58 and builds outer-name dot object-name, or constructs empty output for zero/minus one.
FString* __thiscall FR6CharTemplate_GetWeapon(FR6CharTemplate* charTemplate, FString* result)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x28];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetWeaponExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    const int* list = reinterpret_cast<const int*>(reinterpret_cast<byte*>(charTemplate) + 0x58);
    uint& outputLifetime = *reinterpret_cast<uint*>(nativeFrame - 0x14);
    outputLifetime = 0;
    frame.state = 1;
    uint selected = FR6CharTemplate_GetRandomClassFromList(list);
    FString* output;
    if (selected != 0 && selected != 0xffffffffU) {
        UObject* object = reinterpret_cast<UObject*>(selected);
        UObject* outer = object->Outer; // No additional outer null check.
        const ushort* outerName = outer->UObject::GetName();
        FString* outerStorage = reinterpret_cast<FString*>(nativeFrame - 0x34);
        using Construct = FString* (__thiscall*)(FString*, const ushort*);
        FString* outerValue = reinterpret_cast<Construct&>(FStringConstructorImport)(outerStorage, outerName);
        FString* prefixStorage = reinterpret_cast<FString*>(nativeFrame - 0x28);
        *(byte*)&frame.state = 2;
        using AddText = FString* (__thiscall*)(FString*, FString*, const ushort*);
        FString* prefix = reinterpret_cast<AddText&>(FStringAddTextImport)(outerValue, prefixStorage, nativeTextDot);
        *(byte*)&frame.state = 3;
        const ushort* objectName = object->UObject::GetName();
        output = result;
        reinterpret_cast<AddText&>(FStringAddTextImport)(prefix, output, objectName);
        outputLifetime = 1;
        *(byte*)&frame.state = 2;
        FString::~FString(prefixStorage);
        *(byte*)&frame.state = 1;
        FString::~FString(outerStorage);
    } else {
        output = result;
        FString::FString(output, nativeEmptyText); // Native returns without arming the output flag on this path.
    }
    ExceptionList = frame.previousExceptionList;
    return output;
}

// R6Engine.dll @ 1003ed2e : CharTemplateWeaponCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateWeaponCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003ed60 : FR6CharTemplate::GetGrenade
// Selects from +0x64 and builds outer-name dot object-name, or constructs empty output for zero/minus one.
FString* __thiscall FR6CharTemplate_GetGrenade(
    FR6CharTemplate* charTemplate, FString* result)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x28];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetGrenadeExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    const int* list = reinterpret_cast<const int*>(reinterpret_cast<byte*>(charTemplate) + 0x64);
    uint& outputLifetime = *reinterpret_cast<uint*>(nativeFrame - 0x14);
    outputLifetime = 0;
    frame.state = 1;
    uint selected = FR6CharTemplate_GetRandomClassFromList(list);
    FString* output;
    if (selected != 0 && selected != 0xffffffffU) {
        UObject* object = reinterpret_cast<UObject*>(selected);
        UObject* outer = object->Outer; // No additional outer null check.
        const ushort* outerName = outer->UObject::GetName();
        FString* outerStorage = reinterpret_cast<FString*>(nativeFrame - 0x34);
        using Construct = FString* (__thiscall*)(FString*, const ushort*);
        FString* outerValue = reinterpret_cast<Construct&>(FStringConstructorImport)(outerStorage, outerName);
        FString* prefixStorage = reinterpret_cast<FString*>(nativeFrame - 0x28);
        *(byte*)&frame.state = 2;
        using AddText = FString* (__thiscall*)(FString*, FString*, const ushort*);
        FString* prefix = reinterpret_cast<AddText&>(FStringAddTextImport)(outerValue, prefixStorage, nativeTextDot);
        *(byte*)&frame.state = 3;
        const ushort* objectName = object->UObject::GetName();
        output = result;
        reinterpret_cast<AddText&>(FStringAddTextImport)(prefix, output, objectName);
        outputLifetime = 1;
        *(byte*)&frame.state = 2;
        FString::~FString(prefixStorage);
        *(byte*)&frame.state = 1;
        FString::~FString(outerStorage);
    } else {
        output = result;
        FString::FString(output, nativeEmptyText); // Native returns without arming the output flag on this path.
    }
    ExceptionList = frame.previousExceptionList;
    return output;
}

// R6Engine.dll @ 1003ee2e : CharTemplateGrenadeCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c by value through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGrenadeCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003efe0 : FR6CharTemplate::GetData
// Searches base/current/extra-mod paths, appends declared rows and replaces loaded chances with wrapped prefix sums.
uint __thiscall FR6CharTemplate_GetData(
    FR6CharTemplate* charTemplate, const ushort* baseName, int fileKind)
{
    struct NativeFrameView { // Explicit native slots; saved registers and inherited-frame handlers remain separate.
        uint savedEdi, savedEsi, savedEbx;
        byte locals[0x8a0];
        void* previousExceptionList;
        void* handler;
        int state;
    } frame;
    frame.state = -1;
    frame.handler = (void*)&CharTemplateGetDataExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte* nativeFrame = reinterpret_cast<byte*>(&frame.state) + 4;
    *reinterpret_cast<void**>(nativeFrame - 0x10) = &frame.savedEdi;
    byte* data = reinterpret_cast<byte*>(charTemplate);
    const ushort* originalBase = baseName;
    frame.state = 0;
    *reinterpret_cast<FString*>(data) = originalBase;
    ushort* extension = reinterpret_cast<ushort*>(nativeFrame - 0xac);
    if (fileKind == 1) appStrcpy(extension, nativeTextTpt);
    else if (fileKind == 2) appStrcpy(extension, nativeTextTph); // Other kinds retain uninitialized extension storage.
    void* file = nativeFrame - 0x68;
    FTextFile_Construct(file, originalBase, nativeTextTemplate, extension);
    *(byte*)&frame.state = 1;
    FTextFile_CreateFileReader(file);
    FString* temporary = reinterpret_cast<FString*>(nativeFrame - 0x1c);
    auto isOpen = [&]() { return *reinterpret_cast<uint*>(reinterpret_cast<byte*>(file) + 0xc) != 0; };
    if (!isOpen()) {
        byte** managerSlot = *reinterpret_cast<byte***>(&EngineGModMgrImport);
        byte* manager = *managerSlot;
        byte* mod = *reinterpret_cast<byte**>(manager + 0x34);
        const ushort* keyword = **reinterpret_cast<FString*>(mod + 0x94);
        using Format = FString* (__cdecl*)(FString*, const ushort*, ...);
        Format format = reinterpret_cast<Format&>(FStringPrintfImport);
        FString* directory = format(temporary, nativeTextModsSTemplate, keyword);
        *(byte*)&frame.state = 2;
        const ushort* directoryText = **directory;
        FTextFile_Init(file, originalBase, directoryText, extension);
        *(byte*)&frame.state = 1;
        FString::~FString(temporary);
        FTextFile_CreateFileReader(file);
        uint modIndex = 0;
        while (!isOpen()) {
            managerSlot = *reinterpret_cast<byte***>(&EngineGModMgrImport);
            manager = *managerSlot;
            mod = *reinterpret_cast<byte**>(manager + 0x34);
            int count = *reinterpret_cast<int*>(mod + 0x80);
            if (static_cast<int>(modIndex) >= count) break;
            manager = *managerSlot; // Reload the global object independently for the extra-mod data lookup.
            mod = *reinterpret_cast<byte**>(manager + 0x34);
            byte** extraMods = *reinterpret_cast<byte***>(mod + 0x7c);
            byte* extra = extraMods[modIndex];
            keyword = **reinterpret_cast<FString*>(extra + 0x94);
            directory = format(temporary, nativeTextModsSTemplate, keyword);
            *(byte*)&frame.state = 3;
            directoryText = **directory;
            const ushort* currentBase = baseName;
            FTextFile_Init(file, currentBase, directoryText, extension);
            *(byte*)&frame.state = 1;
            FString::~FString(temporary);
            FTextFile_CreateFileReader(file);
            if (isOpen()) break;
            ++modIndex;
        }
    }
    if (!isOpen()) {
        appMsgf(0, nativeTextTemplateSSDoesnTExist, baseName, extension);
        *(byte*)&frame.state = 0;
        FTextFile_Destroy(file);
        ExceptionList = frame.previousExceptionList;
        return 0;
    }
    FTextFile_ReadInt(file, nativeTextVersion); // Version value is ignored; the reader cursor still advances.
    FString* type = reinterpret_cast<FString*>(nativeFrame - 0x28);
    FString::FString(type);
    *(byte*)&frame.state = 4;
    FString* typeValue = FTextFile_ReadString(file, temporary, nativeTextType);
    *(byte*)&frame.state = 5;
    *type = *typeValue;
    *(byte*)&frame.state = 4;
    FString::~FString(temporary);
    uint* pair = reinterpret_cast<uint*>(nativeFrame - 0x18); // Chance/class overlaps the destroyed result storage.
    ushort* line = reinterpret_cast<ushort*>(nativeFrame - 0x8ac);
    int& declaredRows = fileKind; // Native reuses the incoming words after completing filename search.
    uint& rowIndex = reinterpret_cast<uint&>(baseName);
    auto readRows = [&](uint arrayOffset, const ushort* key) {
        declaredRows = FTextFile_ReadInt(file, key);
        rowIndex = 0;
        while (static_cast<int>(rowIndex) < declaredRows) {
            FTextFile_ReadLine(file, line, 0x400); // Status ignored, including premature EOF.
            FR6CharTemplate_GetClassAndChance(charTemplate, pair, line);
            uint selectedClass = pair[1];
            if (selectedClass) {
                FArray* array = reinterpret_cast<FArray*>(data + arrayOffset);
                int added = array->Add(1, 8);
                byte* entries = *reinterpret_cast<byte**>(array);
                uint chance = pair[0]; // Read after Add; retain the class captured before that provider.
                *reinterpret_cast<uint*>(entries + static_cast<uint>(added) * 8U) = chance;
                *reinterpret_cast<uint*>(entries + static_cast<uint>(added) * 8U + 4) = selectedClass;
            }
            ++rowIndex;
        }
    };
    readRows(0xc, nativeTextNbOfPawn);
    using Equal = int (__thiscall*)(const FString*, const ushort*);
    auto typeIs = [&](const ushort* text) { return reinterpret_cast<Equal&>(FStringEqualImport)(type, text) != 0; };
    auto readWords = [&](const void* keyRows, uint count, uint destination) {
        for (uint index = 0; index < count; ++index) {
            const ushort* key = reinterpret_cast<const ushort*>(reinterpret_cast<const byte*>(keyRows) + index * 32U);
            int value = FTextFile_ReadInt(file, key);
            *reinterpret_cast<int*>(data + destination + index * 4U) = value;
        }
    };
    if (typeIs(nativeTextTerrorist)) {
        *reinterpret_cast<uint*>(data + 0x9c) = 1;
        readRows(0x58, nativeTextNbOfWeapon);
        readRows(0x64, nativeTextNbOfGrenade);
        readWords(charTemplateTerroristPersonalityKeyRows, 6, 0x18);
        int variation = FTextFile_ReadInt(file, nativeTextRndVariation);
        *reinterpret_cast<int*>(data + 0x30) = variation;
        readWords(charTemplateSkillKeyRows, 8, 0x34);
        int flashlight = FTextFile_ReadInt(file, nativeTextFlashlight);
        *reinterpret_cast<int*>(data + 0x70) = flashlight;
        readWords(charTemplateAttachmentKeyRows, 3, 0x74);
    } else if (typeIs(nativeTextHostage)) {
        *reinterpret_cast<uint*>(data + 0x9c) = 2;
        readWords(charTemplateHostagePersonalityKeyRows, 4, 0x80);
        readWords(charTemplatePositionKeyRows, 2, 0x90);
        int civilian = FTextFile_ReadInt(file, nativeTextStartAsCivilian);
        *reinterpret_cast<int*>(data + 0x98) = civilian;
    } else {
        const ushort* name = **reinterpret_cast<FString*>(data);
        appMsgf(0, nativeTextErrorUnknowTypeOfTemplateInS, name);
        *(byte*)&frame.state = 1;
        FString::~FString(type);
        *(byte*)&frame.state = 0;
        FTextFile_Destroy(file);
        ExceptionList = frame.previousExceptionList;
        return 0; // Previously published filename, pawn rows and parser/provider side effects remain.
    }
    auto accumulateArray = [&](uint offset) {
        uint total = 0;
        for (uint index = 0; static_cast<int>(index) < *reinterpret_cast<int*>(data + offset + 4); ++index) {
            byte* entries = *reinterpret_cast<byte**>(data + offset);
            uint* chance = reinterpret_cast<uint*>(entries + index * 8U);
            total += *chance;
            *chance = total;
        }
        return total;
    };
    auto accumulateWords = [&](uint offset, uint count) {
        uint total = 0;
        for (uint index = 0; index < count; ++index) {
            uint* chance = reinterpret_cast<uint*>(data + offset + index * 4U);
            total += *chance;
            *chance = total;
        }
        return total;
    };
    uint pawnTotal = accumulateArray(0xc); // Includes old rows from previous loads, with modulo-32-bit addition.
    using Message = int (__cdecl*)(int, const ushort*, ...);
    Message message;
    if (pawnTotal != 100) {
        const ushort* name = **reinterpret_cast<FString*>(data);
        message = reinterpret_cast<Message&>(CoreAppMsgfImport);
        message(0, nativeTextTotalGrenadeChanceIsDInTemplateS, pawnTotal, name); // Native pawn-total diagnostic says grenade.
    } else {
        message = reinterpret_cast<Message&>(CoreAppMsgfImport);
    }
    auto report = [&](uint total, const ushort* text) {
        const ushort* name = **reinterpret_cast<FString*>(data);
        message(0, text, total, name);
    };
    if (typeIs(nativeTextTerrorist)) { // Recheck after warning/name callbacks; do not cache the earlier type decision.
        uint total = accumulateArray(0x58);
        if (total != 100) report(total, nativeTextTotalWeaponChanceIsDInTemplateS);
        total = accumulateArray(0x64);
        if (total != 100) report(total, nativeTextTotalGrenadeChanceIsDInTemplateS);
        total = accumulateWords(0x18, 6);
        if (total != 100) report(total, nativeTextTotalPersonalityChanceIsDInTemplateS);
        total = accumulateWords(0x74, 3);
        if (static_cast<int>(total) > 100) report(total, nativeTextTotalGadgetChanceIsDInTemplateS);
    } else {
        uint total = accumulateWords(0x80, 4);
        if (total != 100) report(total, nativeTextTotalPersonalityChanceIsDInTemplateS);
        total = accumulateWords(0x90, 2);
        if (total != 100) report(total, nativeTextTotalStartingPosChanceIsDInTemplateS);
    }
    *(byte*)&frame.state = 1;
    FString::~FString(type);
    *(byte*)&frame.state = 0;
    FTextFile_Destroy(file);
    ExceptionList = frame.previousExceptionList;
    return 1;
}

// R6Engine.dll @ 1003f651 : CharTemplateGetDataCatchPointer
// Throws the caught unsigned-short pointer by value through the inherited GetData frame.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetDataCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x6c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x2c]
        push ecx
        mov dword ptr [ebp-0x2c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003f690 : InitializeCharTemplate
// Constructs the leading string, clears only the three array headers and leaves threshold/skill storage untouched.
FR6CharTemplate* __thiscall InitializeCharTemplate(FR6CharTemplate* charTemplate)
{
    FString::FString((FString*)charTemplate);
    byte* templateBytes = (byte*)charTemplate;
    *(uint*)(templateBytes + 0x0c) = 0;
    *(uint*)(templateBytes + 0x10) = 0;
    *(uint*)(templateBytes + 0x14) = 0;
    *(uint*)(templateBytes + 0x58) = 0;
    *(uint*)(templateBytes + 0x5c) = 0;
    *(uint*)(templateBytes + 0x60) = 0;
    *(uint*)(templateBytes + 0x64) = 0;
    *(uint*)(templateBytes + 0x68) = 0;
    *(uint*)(templateBytes + 0x6c) = 0;
    return charTemplate;
}

// R6Engine.dll @ 10043f30 : CharTemplateDestructorState0Cleanup
// Destroys the template leading string through the receiver saved at dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl CharTemplateDestructorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10043f39 : CharTemplateDestructorState1Cleanup
// Destroys the template array at +0x0c through the receiver saved at dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl CharTemplateDestructorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xc
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 100452b0 : CharTemplateWeaponState2Cleanup
// Destroys outer-name storage at EBP-0x34 through the inherited private frame.
__declspec(naked) void __cdecl CharTemplateWeaponState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100452b9 : CharTemplateWeaponState3Cleanup
// Destroys path-prefix storage at EBP-0x28 through the inherited private frame.
__declspec(naked) void __cdecl CharTemplateWeaponState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100452c2 : CharTemplateWeaponState0Cleanup
// Clears only output lifetime bit0 before destroying the hidden FString result, or returns when clear.
__declspec(naked) void __cdecl CharTemplateWeaponState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x1
        je CharTemplateWeaponState0CleanupBranch0
        and dword ptr [ebp-0x14],0xfffffffe
        mov ecx,dword ptr [ebp+0x8]
        jmp dword ptr [FStringDestructorImport]
    CharTemplateWeaponState0CleanupBranch0:
        ret
    }
}

// R6Engine.dll @ 100452f0 : CharTemplateGrenadeState2Cleanup
// Destroys outer-name storage at EBP-0x34 through the inherited private frame.
__declspec(naked) void __cdecl CharTemplateGrenadeState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x34]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100452f9 : CharTemplateGrenadeState3Cleanup
// Destroys path-prefix storage at EBP-0x28 through the inherited private frame.
__declspec(naked) void __cdecl CharTemplateGrenadeState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10045302 : CharTemplateGrenadeState0Cleanup
// Clears only output lifetime bit0 before destroying the hidden FString result, or returns when clear.
__declspec(naked) void __cdecl CharTemplateGrenadeState0Cleanup(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14]
        and eax,0x1
        je CharTemplateGrenadeState0CleanupBranch0
        and dword ptr [ebp-0x14],0xfffffffe
        mov ecx,dword ptr [ebp+0x8]
        jmp dword ptr [FStringDestructorImport]
    CharTemplateGrenadeState0CleanupBranch0:
        ret
    }
}

// R6Engine.dll @ 100453b0 : CharTemplateGetDataState1Cleanup
// Destroys GetData's live text-file storage at EBP-0x68.
__declspec(naked) void __cdecl CharTemplateGetDataState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x68]
        jmp FTextFile_Destroy
    }
}

// R6Engine.dll @ 100453b8 : CharTemplateGetDataState2Cleanup
// Releases GetData's current-mod directory temporary at EBP-0x1c.
__declspec(naked) void __cdecl CharTemplateGetDataState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100453c1 : CharTemplateGetDataState3Cleanup
// Releases GetData's extra-mod directory temporary at EBP-0x1c.
__declspec(naked) void __cdecl CharTemplateGetDataState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100453ca : CharTemplateGetDataState4Cleanup
// Releases GetData's live Type string at EBP-0x28.
__declspec(naked) void __cdecl CharTemplateGetDataState4Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100453d3 : CharTemplateGetDataState5Cleanup
// Releases GetData's temporary parsed Type string before unwinding its outer Type lifetime.
__declspec(naked) void __cdecl CharTemplateGetDataState5Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x1c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100453dc : CharTemplateGetDataExceptionHandler
// Supplies GetData's selected FuncInfo to the shared frame handler, preserving the dispatcher's frame.
__declspec(naked) void __cdecl CharTemplateGetDataExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetDataFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003f665 : CharTemplateGetDataCatchContext
// Reports the native FR6CharTemplate::Init label for GetData and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetDataCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateInit
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003eb00 : CharTemplateClassAndChanceCatchContext
// Reports FR6CharTemplate::GetClassAndChance and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateClassAndChanceCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetClassAndChance
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045280 : CharTemplateGetClassAndChanceExceptionHandler
// Supplies GetClassAndChance exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetClassAndChanceExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateClassAndChanceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003ebb6 : CharTemplateRandomClassCatchContext
// Reports FR6CharTemplate::GetRandomClassFromList and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateRandomClassCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetRandomClassFromList
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045290 : CharTemplateGetRandomClassFromListExceptionHandler
// Supplies GetRandomClassFromList exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetRandomClassFromListExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateRandomClassFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003ec36 : CharTemplatePawnClassCatchContext
// Reports FR6CharTemplate::GetPawnClass and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplatePawnClassCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetPawnClass
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100452a0 : CharTemplateGetPawnClassExceptionHandler
// Supplies GetPawnClass exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetPawnClassExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplatePawnClassFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003ed42 : CharTemplateWeaponCatchContext
// Reports FR6CharTemplate::GetWeapon and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateWeaponCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetWeapon
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100452dc : CharTemplateGetWeaponExceptionHandler
// Supplies GetWeapon exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetWeaponExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateWeaponFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003ee42 : CharTemplateGrenadeCatchContext
// Reports FR6CharTemplate::GetGrenade and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGrenadeCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetGrenade
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004531c : CharTemplateGetGrenadeExceptionHandler
// Supplies GetGrenade exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetGrenadeExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGrenadeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e123 : CharTemplateGetSkillCatchContext
// Reports FR6CharTemplate::GetSkill and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetSkillCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetSkill
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045190 : CharTemplateGetSkillExceptionHandler
// Supplies GetSkill exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetSkillExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetSkillFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e1c6 : CharTemplateGetGadgetCatchContext
// Reports FR6CharTemplate::GetGadget and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetGadgetCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetGadget
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451a0 : CharTemplateGetGadgetExceptionHandler
// Supplies GetGadget exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetGadgetExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetGadgetFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e267 : CharTemplateGetAttachmentTypeCatchContext
// Reports FR6CharTemplate::GetAttachmentType and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetAttachmentTypeCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetAttachmentType
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451b0 : CharTemplateGetAttachmentTypeExceptionHandler
// Supplies GetAttachmentType exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetAttachmentTypeExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetAttachmentTypeFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e308 : CharTemplateGetTerroristPersonalityCatchContext
// Reports FR6CharTemplate::GetTerroristPersonality and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetTerroristPersonalityCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetTerroristPersonality
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451c0 : CharTemplateGetTerroristPersonalityExceptionHandler
// Supplies GetTerroristPersonality exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetTerroristPersonalityExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetTerroristPersonalityFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e3ab : CharTemplateGetHostagePersonalityCatchContext
// Reports FR6CharTemplate::GetHostagePersonality and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetHostagePersonalityCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetHostagePersonality
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451d0 : CharTemplateGetHostagePersonalityExceptionHandler
// Supplies GetHostagePersonality exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetHostagePersonalityExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetHostagePersonalityFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003e44f : CharTemplateGetStartingPositionCatchContext
// Reports FR6CharTemplate::GetStartingPosition() and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CharTemplateGetStartingPositionCatchContext(void)
{
    __asm {
        push offset nativeTextFR6CharTemplateGetStartingPosition
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100451e0 : CharTemplateGetStartingPositionExceptionHandler
// Supplies GetStartingPosition exception metadata without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl CharTemplateGetStartingPositionExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateGetStartingPositionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043f44 : CharTemplateDestructorExceptionHandler
// Supplies cleanup-only exception metadata without changing the native dispatcher frame.
__declspec(naked) void __cdecl CharTemplateDestructorExceptionHandler(void)
{
    __asm {
        mov eax,offset charTemplateDestructorFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100188d0 : DestroyArrayPairAt40And4c
// Destroys the array at +0x4c before +0x40, retaining cleanup of the earlier member if the first call throws.
__declspec(naked) void __thiscall DestroyArrayPairAt40And4c(void* record)
{
    __asm {
        push -1
        push offset ArrayPairExceptionHandler
        mov eax,dword ptr fs:[0]
        push eax
        mov dword ptr fs:[0],esp
        push ecx
        push esi
        mov esi,ecx
        mov dword ptr [esp+0x4],esi
        // Destroy later member +0x4c first while cleanup still protects +0x40.
        lea ecx,[esi+0x4c]
        mov dword ptr [esp+0x10],0x0
        call DestroyEightByteArrayStorageWithOwnGuard
        lea ecx,[esi+0x40]
        // Disable cleanup before entering the normal +0x40 destruction.
        mov dword ptr [esp+0x10],0xffffffff
        call DestroyEightByteArrayStorageWithOwnGuard
        mov ecx,dword ptr [esp+0x8]
        pop esi
        mov dword ptr fs:[0],ecx
        add esp,0x10
        ret
    }
}

// R6Engine.dll @ 10043ed0 : ArrayPairState0Cleanup
// Destroys the array at saved receiver +0x40 through dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl ArrayPairState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x40
        jmp DestroyEightByteArrayStorageWithOwnGuard
    }
}

// R6Engine.dll @ 10043edb : ArrayPairExceptionHandler
// Supplies cleanup-only exception metadata without changing the native dispatcher frame.
__declspec(naked) void __cdecl ArrayPairExceptionHandler(void)
{
    __asm {
        mov eax,offset arrayPairFuncInfo
        jmp __CxxFrameHandler
    }
}

