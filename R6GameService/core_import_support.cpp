#include "native_addresses.h"

// Shared native virtual/import dispatch; original wrapper class identities remain unresolved.

// Tail-forward through current Core.dll IAT 0x1006b010: ?NetDirty@UObject@@UAEXPAVUProperty@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014980 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_supportTailImportedMember(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_NetDirtySlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b014: ?GetPropertiesSize@UObject@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014986 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetPropertiesSizeSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b018: ?IsPendingDelete@UObject@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 1001498c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember2(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_IsPendingDeleteSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b01c: ?LanguageChange@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014992 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember3(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_LanguageChangeSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b020: ?Register@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014998 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember4(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_RegisterSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b024: ?ScriptConsoleExec@UObject@@UAEHPBGAAVFOutputDevice@@PAV1@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 1001499e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember5(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ScriptConsoleExecSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b028: ?CallFunction@UObject@@UAEXAAUFFrame@@QAXPAVUFunction@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149a4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember6(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_CallFunctionSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b02c: ?PostEditChange@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149aa : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember7(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_PostEditChangeSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b030: ?ShutdownAfterError@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember8(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ShutdownAfterErrorSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b034: ?InitExecution@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149b6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember9(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_InitExecutionSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b038: ?GotoLabel@UObject@@UAEHVFName@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149bc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember10(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GotoLabelSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b03c: ?GotoState@UObject@@UAE?AW4EGotoState@@VFName@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149c2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember11(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GotoStateSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b040: ?IsPendingKill@UObject@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember12(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_IsPendingKillSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b044: ?Serialize@UObject@@UAEXAAVFArchive@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149ce : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember13(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_SerializeSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b048: ?Destroy@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149d4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember14(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_DestroySlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b04c: ?PostLoad@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149da : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember15(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_PostLoadSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b050: ?Modify@UObject@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember16(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ModifySlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b054: ?ProcessRemoteFunction@UObject@@UAEHPAVUFunction@@PAXPAUFFrame@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149e6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember17(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ProcessRemoteFunctionSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b058: ?ProcessState@UObject@@UAEXM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149ec : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember18(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ProcessStateSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b05c: ?ProcessDelegate@UObject@@UAEXVFName@@PAUFScriptDelegate@@PAX2@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149f2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember19(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ProcessDelegateSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b064: ?Release@UObject@@UAGKXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100149fe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember20(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ReleaseSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b068: ?AddRef@UObject@@UAGKXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a04 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember21(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_AddRefSlot
  }
}

// Tail-forward through current Core.dll IAT 0x1006b06c: ?QueryInterface@UObject@@UAGKABVFGuid@@PAPAX@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a0a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember22(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::Core_UObject_QueryInterfaceSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b490: ?IsServerJoined@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a16 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember23(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_IsServerJoinedSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b48c: ?GetLoggedInUbiDotCom@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a1c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember24(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetLoggedInUbiDotComSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b488: ?IsMSClientIsInRequest@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a22 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember25(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_IsMSClientIsInRequestSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b484: ?MSCLientLeaveServer@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a28 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember26(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_MSCLientLeaveServerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b480: ?GSClientPostMessage@UR6AbstractGameService@@UAEXE@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a2e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember27(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GSClientPostMessageSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b47c: ?GetGSGameState@UR6AbstractGameService@@UAEEXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a34 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember28(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetGSGameStateSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4a0: ?SetGSGameState@UR6AbstractGameService@@UAEXE@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a3a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember29(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SetGSGameStateSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4a4: ?SetGSClientComInterface@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember30(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SetGSClientComInterfaceSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4a8: ?InitGSClient@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a46 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember31(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_InitGSClientSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4ac: ?GetAuthID@UR6AbstractGameService@@UAE?AVFString@@H@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a4c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember32(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetAuthIDSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4b0: ?ResetAuthId@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a52 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember33(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ResetAuthIdSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4b4: ?RequestGSCDKeyAuthID@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a58 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember34(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_RequestGSCDKeyAuthIDSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4b8: ?RequestModCDKeyProcess@UR6AbstractGameService@@UAEXH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a5e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember35(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_RequestModCDKeyProcessSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4bc: ?MasterServerManager@UR6AbstractGameService@@UAEXPAVAR6AbstractGameInfo@@PAVALevelInfo@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a64 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember36(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_MasterServerManagerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4c0: ?ProcessJoinServer@UR6AbstractGameService@@UAEXPAM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a6a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember37(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ProcessJoinServerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4c4: ?ProcessIsLobbyDisconnect@UR6AbstractGameService@@UAEXPAM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember38(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ProcessIsLobbyDisconnectSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4c8: ?ProcessIsRouterDisconnect@UR6AbstractGameService@@UAEXPAM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a76 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember39(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ProcessIsRouterDisconnectSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4cc: ?ProcessUbiComJoinServer@UR6AbstractGameService@@UAEXHHVFString@@PAM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a7c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember40(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ProcessUbiComJoinServerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4d0: ?ProcessLoginMasterSrv@UR6AbstractGameService@@UAEXHPAM@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a82 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember41(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ProcessLoginMasterSrvSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4d4: ?GameServiceManager@UR6AbstractGameService@@UAEXHHHH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a88 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember42(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GameServiceManagerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4d8: ?CDKeyDisconnecUser@UR6AbstractGameService@@UAEXVFString@@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a8e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember43(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_CDKeyDisconnecUserSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b520: ?DisconnectAllCDKeyPlayers@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a94 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember44(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_DisconnectAllCDKeyPlayersSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b51c: ?SubmitMatchResult@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014a9a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember45(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SubmitMatchResultSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b518: ?ServerRoundFinish@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember46(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ServerRoundFinishSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b514: ?ServerRoundStart@UR6AbstractGameService@@UAEXH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014aa6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember47(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_ServerRoundStartSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b510: ?GetServerRegistered@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014aac : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember48(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetServerRegisteredSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b50c: ?GetLoginRegServer@UR6AbstractGameService@@UAEEXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014ab2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember49(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetLoginRegServerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b508: ?SetLoginRegServer@UR6AbstractGameService@@UAEXE@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014ab8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember50(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SetLoginRegServerSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b504: ?SetRegServerLoginRequest@UR6AbstractGameService@@UAEXE@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014abe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember51(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SetRegServerLoginRequestSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b500: ?SetGameServiceRequestState@UR6AbstractGameService@@UAEXE@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014ac4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember52(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_SetGameServiceRequestStateSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4fc: ?GetRegServerInitialized@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014aca : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember53(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_GetRegServerInitializedSlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4f8: ?InitGSCDKey@UR6AbstractGameService@@UAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember54(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_InitGSCDKeySlot
  }
}

// Tail-forward through current R6Abstract.dll IAT 0x1006b4f4: ?Created@UR6AbstractGameService@@UAEXXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10014ad6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember55(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractGameService_CreatedSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b340: ?imbue@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEXABVlocale@2@@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100372f2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember56(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_imbueSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b33c: ?setbuf@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEPAV12@PAGH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100372f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember57(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_setbufSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b338: ?seekpos@?$basic_stringbuf@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@MAE?AV?$fpos@H@2@V32@H@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 100372fe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember58(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_seekposSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b334: ?seekoff@?$basic_stringbuf@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@MAE?AV?$fpos@H@2@JHH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10037304 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember59(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_seekoffSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b324: ?xsputn@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEHPBGH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 1003730a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember60(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_xsputnSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b320: ?xsgetn@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEHPAGH@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10037310 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember61(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_xsgetnSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b31c: ?uflow@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEGXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10037316 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember62(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_uflowSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b318: ?underflow@?$basic_stringbuf@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@MAEGXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 1003731c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember63(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_underflowSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b314: ?showmanyc@?$basic_streambuf@GU?$char_traits@G@std@@@std@@MAEHXZ.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10037322 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember64(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_streambuf_showmanycSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b310: ?pbackfail@?$basic_stringbuf@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@MAEGG@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 10037328 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember65(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_pbackfailSlot
  }
}

// Tail-forward through current MSVCP71.dll IAT 0x1006b30c: ?overflow@?$basic_stringbuf@GU?$char_traits@G@std@@V?$allocator@G@2@@std@@MAEGG@Z.
// Private import thunk: preserve all registers, caller stack/return address and target-owned convention; no local guard.
// R6GameService.dll @ 1003732e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl core_import_support_core_import_supportTailImportedMember66(void)
{
  __asm {
    jmp DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_stringbuf_overflowSlot
  }
}
