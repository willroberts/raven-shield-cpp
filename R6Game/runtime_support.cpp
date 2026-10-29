#include "native_addresses.h"
#include "import_bindings.h"

// R6Game.dll data @ 100241a0 : PE load-configuration security-cookie DWORD
unsigned int ModuleSecurityCookie = 0xbb40e64e;

// Fixed-width view of the selected 0x48-byte PE32 load-configuration record.
struct NativePeLoadConfiguration {
    unsigned int size;
    unsigned int timeDateStamp;
    unsigned short majorVersion;
    unsigned short minorVersion;
    unsigned int globalFlagsClear;
    unsigned int globalFlagsSet;
    unsigned int criticalSectionDefaultTimeout;
    unsigned int deCommitFreeBlockThreshold;
    unsigned int deCommitTotalFreeThreshold;
    unsigned int lockPrefixTable;
    unsigned int maximumAllocationSize;
    unsigned int virtualMemoryThreshold;
    unsigned int processHeapFlags;
    unsigned int processAffinityMask;
    unsigned short csdVersion;
    unsigned short reservedAt36;
    unsigned int editList;
    unsigned int securityCookieAddress;
    unsigned int sehTableAddress;
    unsigned int sehHandlerCount;
};

// R6Game.dll data @ 10019b60 : read-only PE32 load configuration
const NativePeLoadConfiguration NativeLoadConfiguration = {
    0x48, // Size.
    0x0, // TimeDateStamp.
    0x0, 0x0, // MajorVersion and MinorVersion.
    0x0, // GlobalFlagsClear.
    0x0, // GlobalFlagsSet.
    0x0, // CriticalSectionDefaultTimeout.
    0x0, // DeCommitFreeBlockThreshold.
    0x0, // DeCommitTotalFreeThreshold.
    0x0, // LockPrefixTable.
    0x0, // MaximumAllocationSize.
    0x0, // VirtualMemoryThreshold.
    0x0, // ProcessHeapFlags.
    0x0, // ProcessAffinityMask.
    0x0, 0x0, // CSDVersion and reserved word +0x36.
    0x0, // EditList.
    R6GameAddresses::ModuleSecurityCookie, // ModuleSecurityCookie address.
    R6GameAddresses::SafeSehHandlerRvas, // SafeSehHandlerRvas address.
    0x50, // SafeSEH entry count.
};

// R6Game.dll data @ 10019bf0 : read-only SafeSEH handler RVA table
const unsigned int SafeSehHandlerRvas[80] = {
    0x133e0, // ExceptionHandler3.
    0x13480, // AR6GameInfo_MasterServerManagerExceptionHandler.
    0x13490, // AR6GameInfo_execNativeLogoutExceptionHandler.
    0x134a9, // AR6GameInfo_execGetSystemUserNameExceptionHandler.
    0x134c0, // AR6GameInfo_AbortScoreSubmissionExceptionHandler.
    0x134d0, // AR6GameInfo_execSubmissionSrvRoundStartExceptionHandler.
    0x134e0, // AR6GameInfo_execSubmissionSrvRoundFinishExceptionHandler.
    0x134f9, // AR6PlanningCtrlExceptionDispatcher.
    0x13519, // AR6ActionPointExceptionDispatcher.
    0x13542, // UR6GameManagerExceptionDispatcher.
    0x13559, // UR6PlanningInfoExceptionDispatcher.
    0x13579, // FileManagerDestructionExceptionDispatcher.
    0x135b1, // Shared_UR6PlayerCampaignExceptionDispatcher1.
    0x135d5, // Shared_UR6PlayerCampaignExceptionDispatcher2.
    0x135f2, // AR6GameInfo_InitGameInfoGameServiceExceptionHandler.
    0x13600, // AR6GameInfo_execSetControllerExceptionHandler.
    0x13610, // AR6GameInfo_execInitScoreSubmissionExceptionHandler.
    0x13620, // AR6GameInfo_execSubmissionNotifySendStartMatchExceptionHandler.
    0x13630, // AR6GameInfo_execLogoutUpdatePlayersCtrlInfoExceptionHandler.
    0x13640, // AR6GameInfo_execSubmissionUpdateLadderStatExceptionHandler.
    0x13659, // ArrayExceptionHandler.
    0x13695, // AR6SoundVolumeDestructorExceptionHandler.
    0x136a8, // SoundVolumeDerivedDestructorExceptionHandler.
    0x137e5, // Shared_UR6OperativeExceptionDispatcher1.
    0x1380f, // CustomMissionDestructionExceptionHandler.
    0x13834, // CustomMissionCopyExceptionHandler.
    0x138e5, // AR6GameInfoDestructorExceptionHandler.
    0x13986, // AR6GameInfoCopyExceptionHandler.
    0x13998, // AR6MultiPlayerGameInfoDestructorExceptionHandler.
    0x139c7, // AR6SoundVolumeCopyExceptionHandler.
    0x13a76, // AR6HUDDestructorExceptionHandler.
    0x13b07, // AR6HUDConstructorExceptionHandler.
    0x13b73, // AR6HUDCopyExceptionHandler.
    0x13c96, // Shared_UR6OperativeExceptionDispatcher2.
    0x13cb4, // Shared_UR6MissionRosterExceptionDispatcher1.
    0x13cc9, // Shared_UR6MissionRosterExceptionDispatcher2.
    0x13d85, // AR6GameInfoConstructorExceptionHandler.
    0x13d90, // InstructionSoundUseSoundExceptionHandler.
    0x13da0, // UR6PlanningInfo::execAddToTeamExceptionHandler.
    0x13db0, // UR6PlanningInfo::NoStairsBetweenPointsExceptionHandler.
    0x13e3e, // Shared_UR6FileManagerPlanning_ExceptionHandler1.
    0x13eb3, // Shared_UR6FileManagerPlanning_ExceptionHandler2.
    0x13ef6, // Shared_UR6FileManagerPlanning_ExceptionHandler3.
    0x13f00, // Shared_UR6OperativeExceptionDispatcher3.
    0x13f10, // AR6PlanningCtrl::PlanningTraceExceptionHandler.
    0x13f38, // AR6PlanningCtrl::GetXYPointExceptionHandler.
    0x13f68, // AR6PlanningCtrl::GetClickResultExceptionHandler.
    0x13f80, // UR6PlanningInfo::execInsertToTeamExceptionHandler.
    0x13f90, // AR6ActionPoint_ExceptionHandler.
    0x13fa0, // UR6PlanningInfo::AddPointExceptionHandler.
    0x13fb0, // UR6PlanningInfo::execFindPathToNextPointExceptionHandler.
    0x13fc0, // UR6PlanningInfo::TransferFileExceptionHandler.
    0x13fd0, // SerializeFArray_ExceptionHandler.
    0x13fe0, // UR6PlanningInfo::execDeletePointExceptionHandler.
    0x14026, // UR6MissionRoster_ExceptionHandler.
    0x14093, // Shared_UR6FileManagerCampaign_ExceptionHandler1.
    0x140d6, // Shared_UR6FileManagerCampaign_ExceptionHandler2.
    0x140e0, // AR6HUD_HudStepExceptionHandler.
    0x140f0, // AR6HUD_DestroyExceptionHandler.
    0x14139, // MatrixExceptionHandler.
    0x14150, // AR6HUD_SpawnedExceptionHandler.
    0x14169, // AR6HUD_DrawSingleCharacterInfoExceptionHandler.
    0x14180, // AR6HUD_DrawCharacterInfoExceptionHandler.
    0x14190, // AR6HUD_DisplayOtherTeamInfoExceptionHandler.
    0x141a0, // GlobalTempObjectsAddExceptionHandler.
    0x1421c, // AR6HUD::DrawNativeHUDExceptionHandler.
    0x1423c, // AR6HUD_DrawRadarExceptionHandler.
    0x14294, // AR6HUD::DrawInGameMapExceptionHandler.
    0x142a0, // Shared_UR6GameManager_ExceptionHandler1.
    0x142d4, // Shared_UR6GameManager_ExceptionHandler2.
    0x142fb, // Shared_UR6GameManager_ExceptionHandler3.
    0x14310, // Shared_UR6GameManager_ExceptionHandler4.
    0x14320, // Shared_UR6GameManager_ExceptionHandler5.
    0x14330, // Shared_UR6GameManager_ExceptionHandler6.
    0x14349, // Shared_UR6GameManager_ExceptionHandler7.
    0x14360, // Shared_UR6GameManager_ExceptionHandler8.
    0x14370, // Shared_UR6GameManager_ExceptionHandler9.
    0x143ad, // Shared_UR6GameManager_ExceptionHandler10.
    0x143ed, // Shared_UR6GameManager_ExceptionHandler11.
    0x14400, // Shared_UR6GameManager_ExceptionHandler12.
};

using CrtExitCallback = void (__cdecl *)(void);
using CrtNotificationHook = int (__stdcall *)(void*, unsigned int, void*);

// R6Game.dll data @ 100246c8 : CRT/DLL mutable state
void* R6GameModuleHandle = nullptr;

// R6Game.dll data @ 100292d8 : CRT/DLL mutable state
unsigned int CrtAttachCount = 0;

// R6Game.dll data @ 100292dc : CRT/DLL mutable state
unsigned int CrtAdjustFdivSnapshot = 0;

// R6Game.dll data @ 100292e0 : CRT/DLL mutable state
CrtNotificationHook CrtRawNotificationHook = nullptr;

// R6Game.dll data @ 100292e4 : CRT/DLL mutable state
CrtExitCallback* CrtExitCallbackEnd = nullptr;

// R6Game.dll data @ 100292e8 : CRT/DLL mutable state
CrtExitCallback* CrtExitCallbackBegin = nullptr;

// R6Game.dll data @ 10019b30 : three-DWORD SEH scope record
const unsigned int runtime_support_ExceptionScopeRecord5[3] = {
    0xffffffff, R6GameAddresses::DllEntrySehFilter, R6GameAddresses::DllEntrySehHandler, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10019b40 : three-DWORD SEH scope record
const unsigned int runtime_support_ExceptionScopeRecord6[3] = {
    0xffffffff, R6GameAddresses::RuntimeInitializationSehFilter, R6GameAddresses::RuntimeInitializationSehHandler, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10019b50 : three-DWORD SEH scope record
const unsigned int runtime_support_ExceptionScopeRecord7[3] = {
    0xffffffff, R6GameAddresses::RuntimeTerminationSehFilter, R6GameAddresses::RuntimeTerminationSehHandler, // Previous state, filter (zero for finally), handler.
};

// R6Game.dll data @ 10024000 : writable startup initializer range
unsigned int CrtStartupInitializerWords[57] = {
    0x0, // Null leading initializer.
    R6GameAddresses::InitializeAR6GameInfoClassMetadata, // InitializeAR6GameInfoClassMetadata
    R6GameAddresses::InitializeAR6GameInfoAutoClassPointer, // InitializeAR6GameInfoAutoClassPointer
    R6GameAddresses::InitializeAR6GameInfoNativeSetController, // InitializeAR6GameInfoNativeSetController
    R6GameAddresses::InitializeAR6GameInfoNativeNativeLogout, // InitializeAR6GameInfoNativeNativeLogout
    R6GameAddresses::InitializeAR6GameInfoNativeGetSystemUserName, // InitializeAR6GameInfoNativeGetSystemUserName
    R6GameAddresses::InitializeAR6GameInfoNativeInitScoreSubmission, // InitializeAR6GameInfoNativeInitScoreSubmission
    R6GameAddresses::InitializeAR6GameInfoNativeSubmissionSrvRoundStart, // InitializeAR6GameInfoNativeSubmissionSrvRoundStart
    R6GameAddresses::InitializeAR6GameInfoNativeSubmissionNotifySendStartMatch, // InitializeAR6GameInfoNativeSubmissionNotifySendStartMatch
    R6GameAddresses::InitializeAR6GameInfoNativeSubmissionSrvRoundFinish, // InitializeAR6GameInfoNativeSubmissionSrvRoundFinish
    R6GameAddresses::InitializeAR6GameInfoNativeLogoutUpdatePlayersCtrlInfo, // InitializeAR6GameInfoNativeLogoutUpdatePlayersCtrlInfo
    R6GameAddresses::InitializeAR6GameInfoNativeSubmissionUpdateLadderStat, // InitializeAR6GameInfoNativeSubmissionUpdateLadderStat
    R6GameAddresses::InitializeUR6PlayerCustomMissionClassMetadata, // InitializeUR6PlayerCustomMissionClassMetadata
    R6GameAddresses::InitializeUR6PlayerCustomMissionAutoClassPointer, // InitializeUR6PlayerCustomMissionAutoClassPointer
    R6GameAddresses::InitializeAR6ActionPointClassMetadata, // InitializeAR6ActionPointClassMetadata
    R6GameAddresses::InitializeAR6ActionPointAutoClassPointer, // InitializeAR6ActionPointAutoClassPointer
    R6GameAddresses::InitializeAR6PlanningCtrlClassMetadata, // InitializeAR6PlanningCtrlClassMetadata
    R6GameAddresses::InitializeAR6PlanningCtrlAutoClassPointer, // InitializeAR6PlanningCtrlAutoClassPointer
    R6GameAddresses::InitializeUR6PlanningInfoClassMetadata, // InitializeUR6PlanningInfoClassMetadata
    R6GameAddresses::InitializeUR6PlanningInfoAutoClassPointer, // InitializeUR6PlanningInfoAutoClassPointer
    R6GameAddresses::InitializeUR6FileManagerPlanningClassMetadata, // InitializeUR6FileManagerPlanningClassMetadata
    R6GameAddresses::InitializeUR6FileManagerPlanningAutoClassPointer, // InitializeUR6FileManagerPlanningAutoClassPointer
    R6GameAddresses::InitializeUR6FileManagerCampaignClassMetadata, // InitializeUR6FileManagerCampaignClassMetadata
    R6GameAddresses::InitializeUR6FileManagerCampaignAutoClassPointer, // InitializeUR6FileManagerCampaignAutoClassPointer
    R6GameAddresses::InitializeUR6PlayerCampaignClassMetadata, // InitializeUR6PlayerCampaignClassMetadata
    R6GameAddresses::InitializeUR6PlayerCampaignAutoClassPointer, // InitializeUR6PlayerCampaignAutoClassPointer
    R6GameAddresses::InitializeUR6MissionRosterClassMetadata, // InitializeUR6MissionRosterClassMetadata
    R6GameAddresses::InitializeUR6MissionRosterAutoClassPointer, // InitializeUR6MissionRosterAutoClassPointer
    R6GameAddresses::InitializeAR6SoundVolumeClassMetadata, // InitializeAR6SoundVolumeClassMetadata
    R6GameAddresses::InitializeAR6SoundVolumeAutoClassPointer, // InitializeAR6SoundVolumeAutoClassPointer
    R6GameAddresses::InitializeAR6InstructionSoundVolumeClassMetadata, // InitializeAR6InstructionSoundVolumeClassMetadata
    R6GameAddresses::InitializeAR6InstructionSoundVolumeAutoClassPointer, // InitializeAR6InstructionSoundVolumeAutoClassPointer
    R6GameAddresses::InitializeAR6WaterVolumeClassMetadata, // InitializeAR6WaterVolumeClassMetadata
    R6GameAddresses::InitializeAR6WaterVolumeAutoClassPointer, // InitializeAR6WaterVolumeAutoClassPointer
    R6GameAddresses::InitializeUR6OperativeClassMetadata, // InitializeUR6OperativeClassMetadata
    R6GameAddresses::InitializeUR6OperativeAutoClassPointer, // InitializeUR6OperativeAutoClassPointer
    R6GameAddresses::InitializeAR6MultiPlayerGameInfoClassMetadata, // InitializeAR6MultiPlayerGameInfoClassMetadata
    R6GameAddresses::InitializeAR6MultiPlayerGameInfoAutoClassPointer, // InitializeAR6MultiPlayerGameInfoAutoClassPointer
    R6GameAddresses::InitializeUR6GameManagerClassMetadata, // InitializeUR6GameManagerClassMetadata
    R6GameAddresses::InitializeUR6GameManagerAutoClassPointer, // InitializeUR6GameManagerAutoClassPointer
    R6GameAddresses::InitializeAR6InstructionSoundVolumeNativeUseSound, // InitializeAR6InstructionSoundVolumeNativeUseSound
    R6GameAddresses::InitializeAR6PlanningCtrlNativeGetClickResult, // InitializeAR6PlanningCtrlNativeGetClickResult
    R6GameAddresses::InitializeAR6PlanningCtrlNativeGetXYPoint, // InitializeAR6PlanningCtrlNativeGetXYPoint
    R6GameAddresses::InitializeAR6PlanningCtrlNativePlanningTrace, // InitializeAR6PlanningCtrlNativePlanningTrace
    R6GameAddresses::InitializeUR6PlanningInfoNativeAddToTeam, // InitializeUR6PlanningInfoNativeAddToTeam
    R6GameAddresses::InitializeUR6PlanningInfoNativeInsertToTeam, // InitializeUR6PlanningInfoNativeInsertToTeam
    R6GameAddresses::InitializeUR6PlanningInfoNativeDeletePoint, // InitializeUR6PlanningInfoNativeDeletePoint
    R6GameAddresses::InitializeUR6PlanningInfoNativeFindPathToNextPoint, // InitializeUR6PlanningInfoNativeFindPathToNextPoint
    R6GameAddresses::InitializeUR6FileManagerPlanningNativeLoadPlanning, // InitializeUR6FileManagerPlanningNativeLoadPlanning
    R6GameAddresses::InitializeUR6FileManagerPlanningNativeSavePlanning, // InitializeUR6FileManagerPlanningNativeSavePlanning
    R6GameAddresses::InitializeUR6FileManagerPlanningNativeGetNumberOfFiles, // InitializeUR6FileManagerPlanningNativeGetNumberOfFiles
    R6GameAddresses::InitializeUR6FileManagerCampaignNativeLoadCampaign, // InitializeUR6FileManagerCampaignNativeLoadCampaign
    R6GameAddresses::InitializeUR6FileManagerCampaignNativeSaveCampaign, // InitializeUR6FileManagerCampaignNativeSaveCampaign
    R6GameAddresses::InitializeAR6HUDClassMetadata, // InitializeAR6HUDClassMetadata
    R6GameAddresses::InitializeAR6HUDAutoClassPointer, // InitializeAR6HUDAutoClassPointer
    R6GameAddresses::InitializeAR6HUDNativeDrawNativeHUD, // InitializeAR6HUDNativeDrawNativeHUD
    R6GameAddresses::InitializeAR6HUDNativeHudStep, // InitializeAR6HUDNativeHudStep
};

// R6Game.dll @ 10007fc0 : remember the DLL module handle for every notification
int __stdcall _DllMain_12(void* moduleHandle, uint reason, void* reserved)
{
    void*& dllModuleHandle = R6GameModuleHandle;
    dllModuleHandle = moduleHandle;
    return 1;
}

// R6Game.dll @ 10012f52 : forward the C++ frame-handler register and stack context unchanged
__declspec(naked) void __CxxFrameHandler(void)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71___CxxFrameHandlerSlot] }
}

// R6Game.dll @ 10012f60 : forward the exception object and throw descriptor to the CRT
__declspec(naked) void _CxxThrowException(void* exceptionObject, ThrowInfo* throwInfo)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71__CxxThrowExceptionSlot] }
}

// R6Game.dll @ 100130ec : register an exit callback in the DLL table or tail-forward to the process CRT
__declspec(naked) _onexit_t __cdecl __onexit(_onexit_t callback)
{
    __asm {
        cmp dword ptr [CrtExitCallbackBegin], 0xffffffff
        jne useLocalExitTable
        jmp dword ptr [R6GameAddresses::MSVCR71__onexitSlot]
    useLocalExitTable:
        push offset CrtExitCallbackEnd
        push offset CrtExitCallbackBegin
        push dword ptr [esp+0xc]
        call __dllonexit
        add esp, 0xc
        ret
    }
}

// R6Game.dll @ 10013112 : convert successful exit-callback registration to zero, failure to -1
int __cdecl _atexit(void (__cdecl *callback)(void))
{
    _onexit_t registeredCallback = __onexit((_onexit_t)callback);
    return registeredCallback != nullptr ? 0 : -1;
}

// R6Game.dll @ 1001338e : forward termination to the CRT without changing the call frame
__declspec(naked) void __cdecl terminate(void)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71_terminateSlot] }
}

// R6Game.dll @ 10013394 : Installs the caller's SEH record and saves its frame and nonvolatile registers.
__declspec(naked) void __SEH_prolog(void)
{
    __asm {
        push R6GameAddresses::ExceptionHandler3 // Local thunk to imported _except_handler3.
        mov eax,fs:[0]
        push eax
        mov eax,dword ptr [esp+0x10]
        mov dword ptr [esp+0x10],ebp
        lea ebp,[esp+0x10]
        sub esp,eax
        push ebx
        push esi
        push edi
        mov eax,dword ptr [ebp-0x8]
        mov dword ptr [ebp-0x18],esp
        push eax
        mov eax,dword ptr [ebp-0x4]
        mov dword ptr [ebp-0x4],0xffffffff
        mov dword ptr [ebp-0x8],eax
        lea eax,[ebp-0x10]
        mov fs:[0],eax
        ret
    }
}

// R6Game.dll @ 100133cf : Restores the enclosing SEH chain, saved registers, frame, and continuation.
__declspec(naked) void __SEH_epilog(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        mov dword ptr fs:[0],ecx
        pop ecx
        pop edi
        pop esi
        pop ebx
        leave
        push ecx
        ret
    }
}

// R6Game.dll @ 100133e0 : forward the native SEH registration context to the CRT handler
__declspec(naked) void ExceptionHandler3(void)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71__except_handler3Slot] }
}

// R6Game.dll @ 100133e6 : forward the callback and DLL table-pointer pair to the CRT
__declspec(naked) _onexit_t __cdecl __dllonexit(_onexit_t callback, _onexit_t** begin, _onexit_t** end)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71___dllonexitSlot] }
}

// R6Game.dll @ 100133ec : forward the initializer range to the CRT with its caller's stack intact
__declspec(naked) void __cdecl initterm(void (__cdecl **begin)(void), void (__cdecl **end)(void))
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71__inittermSlot] }
}

// R6Game.dll @ 100133f2 : walk the selected empty CRT callback range with per-callback SEH
void __RTC_Initialize(void)
{
    using RuntimeCallback = void (__cdecl *)(void);
    // Scope 0 at 0x10019b40: filter 0x1001341f returns 1; handler 0x10013423 resumes iteration.
    // Native cursor is frame -0x1c; SEH state is -1 outside the callback load/call, 0 inside it.
    uint callbackCursor = R6GameAddresses::EmptyRuntimeInitializationRange;
    while (callbackCursor < R6GameAddresses::EmptyRuntimeInitializationRange) {
        __try {
            RuntimeCallback callback = *(RuntimeCallback*)callbackCursor;
            if (callback != nullptr) callback();
        }
        __except (1) {
            // The CRT restores saved ESP and continues after the failed callback.
        }
        callbackCursor += 4;
    }
}

// R6Game.dll @ 10013436 : walk the selected empty CRT callback range with per-callback SEH
void RunCrtTerminationCallbacks(void)
{
    using RuntimeCallback = void (__cdecl *)(void);
    // Scope 0 at 0x10019b50: filter 0x10013463 returns 1; handler 0x10013467 resumes iteration.
    // Native cursor is frame -0x1c; SEH state is -1 outside the callback load/call, 0 inside it.
    uint callbackCursor = R6GameAddresses::EmptyRuntimeTerminationRange;
    while (callbackCursor < R6GameAddresses::EmptyRuntimeTerminationRange) {
        __try {
            RuntimeCallback callback = *(RuntimeCallback*)callbackCursor;
            if (callback != nullptr) callback();
        }
        __except (1) {
            // The CRT restores saved ESP and continues after the failed callback.
        }
        callbackCursor += 4;
    }
}

// R6Game.dll @ 1001347a : forward the exception code and exception pointers to the CRT entry filter
__declspec(naked) int __cdecl __CppXcptFilter(uint exceptionCode, void* exceptionPointers)
{
    __asm { jmp dword ptr [R6GameAddresses::MSVCR71___CppXcptFilterSlot] }
}

// R6Game.dll @ 10013130 : __chkstk
// Probes EAX bytes, preserves ECX, moves ESP and leaves the native return address in EAX.
__declspec(naked) void __chkstk(void)
{
    __asm {
        cmp eax,0x1000
        jae probeWholePages
        neg eax
        add eax,esp
        add eax,0x4
        test DWORD PTR [eax],eax
        xchg esp,eax
        mov eax,DWORD PTR [eax]
        push eax
        ret
    probeWholePages:
        push ecx
        lea ecx,[esp+0x8]
    probeNextPage:
        sub ecx,0x1000
        sub eax,0x1000
        test DWORD PTR [ecx],eax
        cmp eax,0x1000
        jae probeNextPage
        sub ecx,eax
        mov eax,esp
        test DWORD PTR [ecx],eax
        mov esp,ecx
        mov ecx,DWORD PTR [eax]
        mov eax,DWORD PTR [eax+0x4]
        push eax
        ret
    }
}

// R6Game.dll @ 10013170 : ConvertX87ToSigned64
// Converts ST0 to EDX:EAX with active-mode integer rounding followed by sign-bit correction.
// Leaves the x87 control word unchanged; rounded zero/INT64_MIN bypass correction and drain both x87 values.
__declspec(naked) long long ConvertX87ToSigned64(void)
{
    __asm {
        push ebp
        mov ebp,esp
        sub esp,0x20
        and esp,0xfffffff0
        fld st(0)
        fst DWORD PTR [esp+0x18]
        fistp QWORD PTR [esp+0x10]
        fild QWORD PTR [esp+0x10]
        mov edx,DWORD PTR [esp+0x18]
        mov eax,DWORD PTR [esp+0x10]
        test eax,eax
        je roundedLowWordZero
    correctRoundedResult:
        fsubp st(1),st
        test edx,edx
        jns subtractRoundingCorrection
        fstp DWORD PTR [esp]
        mov ecx,DWORD PTR [esp]
        xor ecx,0x80000000
        add ecx,0x7fffffff
        adc eax,0x0
        mov edx,DWORD PTR [esp+0x14]
        adc edx,0x0
        jmp conversionComplete
    subtractRoundingCorrection:
        fstp DWORD PTR [esp]
        mov ecx,DWORD PTR [esp]
        add ecx,0x7fffffff
        sbb eax,0x0
        mov edx,DWORD PTR [esp+0x14]
        sbb edx,0x0
        jmp conversionComplete
    roundedLowWordZero:
        mov edx,DWORD PTR [esp+0x14]
        test edx,0x7fffffff
        jne correctRoundedResult
        fstp DWORD PTR [esp+0x18]
        fstp DWORD PTR [esp+0x18]
    conversionComplete:
        leave
        ret
    }
}

// R6Game.dll @ 100131e5 : initialize CRT callbacks or release them in reverse order for DLL notifications
int __stdcall __CRT_INIT_12(void* unusedModuleHandle, uint reason, void* unusedReserved)
{
    using ExitCallback = void (__cdecl *)(void);
    uint& attachCount = CrtAttachCount;
    uint& fdivSnapshot = CrtAdjustFdivSnapshot;
    ExitCallback*& callbackEnd = CrtExitCallbackEnd;
    ExitCallback*& callbackBegin = CrtExitCallbackBegin;
    uint currentReason = reason;
    if (currentReason == 0) {
        if ((int)attachCount <= 0) return 0;
        --attachCount;
    }
    bool processAttach = currentReason == 1;
    fdivSnapshot = **(uint**)R6GameImports::MSVCR71__adjust_fdivSlot; // Selected MSVCR71 _adjust_fdiv data import.
    if (processAttach) {
        using Allocate = void* (__cdecl *)(uint);
        ExitCallback* allocation = (ExitCallback*)(*(Allocate*)R6GameImports::MSVCR71_mallocSlot)(0x80);
        callbackBegin = allocation;
        if (allocation == nullptr) return 0;
        *(volatile uint*)allocation &= 0U;
        callbackEnd = callbackBegin;
        __RTC_Initialize();
        _atexit(RunCrtTerminationCallbacks); // Registration failure is ignored, as in the native caller.
        initterm((ExitCallback*)CrtStartupInitializerWords, (ExitCallback*)(CrtStartupInitializerWords + 57));
        ++attachCount; // Native DWORD increment wraps and uses the post-initializer value.
    } else if (currentReason == 0) {
        ExitCallback* tableBase = callbackBegin;
        if (tableBase != nullptr) {
            for (;;) {
                callbackEnd = (ExitCallback*)((uint)callbackEnd - 4U);
                if ((uint)callbackEnd < (uint)tableBase) break;
                ExitCallback callback = *callbackEnd;
                if (callback != nullptr) {
                    callback();
                    tableBase = callbackBegin; // Null slots retain the previously captured base.
                }
            }
            using Release = void (__cdecl *)(void*);
            (*(Release*)R6GameImports::MSVCR71_freeSlot)(tableBase);
            *(volatile uint*)&callbackBegin &= 0U; // callbackEnd is deliberately left at the terminal cursor.
        }
    }
    return 1;
}

// R6Game.dll @ 100132a3 : sequence raw DLL hooks, CRT state and the DLL callback under the CRT exception filter
int __stdcall entry(void* moduleHandle, uint reason, void* reserved)
{
    using NotificationHook = int (__stdcall *)(void*, uint, void*);
    uint& attachCount = CrtAttachCount;
    NotificationHook& rawHook = CrtRawNotificationHook;
    int notificationResult = 1; // Native frame -0x1c is initialized before scope 0.
    // Scope 0x10019b30: filter 0x10013365 calls __CppXcptFilter; handler 0x10013376 restores ESP and returns zero.
    __try {
        uint notificationReason = reason; // Native ESI is captured after entering the guard.
        if (notificationReason == 0 && attachCount == 0) return 0;
        if (notificationReason == 1 || notificationReason == 2) {
            NotificationHook attachHook = rawHook;
            if (attachHook != nullptr)
                notificationResult = attachHook(moduleHandle, notificationReason, reserved);
            if (notificationResult == 0) return 0;
            notificationResult = __CRT_INIT_12(moduleHandle, notificationReason, reserved);
            if (notificationResult == 0) return 0;
        }
        void* notificationReserved = reserved; // Native EBX capture follows the pre-attach callbacks.
        notificationResult = _DllMain_12(moduleHandle, notificationReason, notificationReserved);
        if (notificationReason == 1 && notificationResult == 0)
            __CRT_INIT_12(moduleHandle, 0, notificationReserved);
        if (notificationReason == 0 || notificationReason == 3) {
            if (__CRT_INIT_12(moduleHandle, notificationReason, notificationReserved) == 0)
                notificationResult = 0;
            if (notificationResult != 0) {
                NotificationHook detachHook = rawHook;
                if (detachHook != nullptr)
                    notificationResult = detachHook(moduleHandle, notificationReason, notificationReserved);
            }
        }
        return notificationResult;
    }
    __except (__CppXcptFilter(GetExceptionCode(), GetExceptionInformation())) {
        return 0;
    }
}
