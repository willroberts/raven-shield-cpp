#include "native_addresses.h"

// Shared service callbacks. Diagnostic spellings identify registration roles; physical uint return views expose EAX residue.
// Original callback declarations and private reply layouts remain incomplete; retain explicit offsets and native widths.

// When logging is enabled, report match-start callback, then read current low replyBYTE and log reason on27.
// Cached Logf target/current logger; all three physical words remain in stdcall pop, unused third word untouched.
// R6GameService.dll @ 10013060 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerMatchStartReply(uint word0,uint word1,uint word2)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch2
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerMatchStartReply
    push   ecx
    call   esi
    mov    al,BYTE PTR [esp+0x10]
    add    esp,0x8
    cmp    al,0x27
    jne    Branch1
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextRegServerRcvLobbyServerMatchStartReplyFailedIReasonD
    push   ecx
    call   esi
    add    esp,0xc
  Branch1:
    pop    esi
  Branch2:
    ret    0xc
  }
}

// Optionally log match-finish callback; ignore three physical argument words and preserve raw log/gate EAX.
// R6GameService.dll @ 100130b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerMatchFinishReply(uint word0,uint word1,uint word2)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch3
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerMatchFinishReply
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch3:
    ret    0xc
  }
}

// Optionally log router login/reason, then publish captured low replyBYTE as DWORD at93b10.
// Capture Logf before gates, read reply after first log, recheck current logging for27 reason; store follows diagnostics.
// R6GameService.dll @ 100130e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LoginRouterResult(uint word0,uint word1,uint word2)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je    Branch4
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginRouterResult
    push   ecx
    call   esi
    add    esp,0x8
  Branch4:
    mov    bl,BYTE PTR [esp+0xc]
    cmp    bl,0x27
    jne    Branch5
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch6
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginRouterResultFailedReasonI
    push   ecx
    call   esi
    add    esp,0xc
    movzx  edx,bl
    pop    esi
    mov    DWORD PTR ds:0x10093b10,edx
    pop    ebx
    ret    0xc
  Branch5:
    movzx  eax,bl
    pop    esi
    mov    ds:0x10093b10,eax
    pop    ebx
    ret    0xc
  Branch6:
    movzx  ecx,bl
    pop    esi
    mov    DWORD PTR ds:0x10093b10,ecx
    pop    ebx
    ret    0xc
  }
}

// Optionally log router login disconnection; no status publication or arguments.
// R6GameService.dll @ 10013160 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LoginDisconnection(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch7
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginDisconnection
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch7:
    ret
  }
}

// Publish low replyBYTE, low portWORD and full groupID, then copy ANSI address including terminator without a capacity gate.
// Optional conversion/log uses captured string/port/group; CURRENT replyBYTE27 logs reason even when logging disabled.
// R6GameService.dll @ 10013180 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_RegisterServerResult(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5)
{
  __asm {
    movzx  eax,BYTE PTR [esp+0x4]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x10]
    push   ebp
    push   esi
    movzx  esi,WORD PTR [esp+0x20]
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    edx,0x100939f0
    mov    ds:0x10093b00,eax
    mov    DWORD PTR ds:0x10093b28,esi
    mov    DWORD PTR ds:0x10093b1c,ebx
    mov    eax,edi
    sub    edx,edi
  Branch8:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test   cl,cl
    jne    Branch8
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je    Branch9
    push   ebx
    push   esi
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvRegisterServerResultSII
    push   edx
    call   ebp
    add    esp,0x14
  Branch9:
    cmp    BYTE PTR [esp+0x14],0x27
    jne    Branch10
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvRegisterServerResultFailedReasonI
    push   edx
    call   ebp
    add    esp,0xc
  Branch10:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x18
  }
}

// Publish low replyBYTE as DWORD at93b30, then optionally log current second word; third physical word unused.
// R6GameService.dll @ 10013290 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerUpdateGroupSettingsResults(uint word0,uint word1,uint word2)
{
  __asm {
    movzx  eax,BYTE PTR [esp+0x4]
    mov    ds:0x10093b30,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch11
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerUpdateGroupSettingsResultsI
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch11:
    ret    0xc
  }
}

// Capture logging gate, set disconnection DWORD93b04 to1, then optionally log; no arguments.
// R6GameService.dll @ 100132d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerDisconnection(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    DWORD PTR ds:0x10093b04,0x1
    je    Branch12
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerDisconnection
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch12:
    ret
  }
}

// When logging is enabled, convert first ANSI pointer and log new-member diagnostic; all seven physical words are popped.
// Other words are ignored and conversion/log return residue remains; no null/length validation or own EH.
// R6GameService.dll @ 10013300 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerNewMember(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch13
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerNewMemberS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
  Branch13:
    ret    0x1c
  }
}

// Capture full lobby/group IDs, optionally log both, then CURRENT replyBYTE27 publishes status27.
// Nonzero captured group always appends(group,lobby) through current array bases; zero group/non27 publishes26. No own EH.
// R6GameService.dll @ 10013640 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RegServerRcv_RequestParentGroupResult(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    mov    ebx,DWORD PTR [esp+0x10]
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    je    Branch14
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ebx
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvRequestParentGroupResultILobbySrvIDI
    push   ecx
    call   edi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   R6GameServiceAddresses::WideTextCallbackRegServerRcvRequestParentGroupResultIGroupIDI
    push   eax
    call   edi
    add    esp,0x18
    pop    edi
  Branch14:
    mov    cl,BYTE PTR [esp+0xc]
    mov    eax,0x27
    cmp    cl,al
    jne    Branch17
    test   esi,esi
    mov    ds:0x10093b20,eax
    je    Branch16
  Branch15:
    push   0x8
    push   0x1
    mov    ecx,R6GameServiceAddresses::GServiceArray10
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray10
    mov    DWORD PTR [ecx+eax*8],esi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray10
    mov    DWORD PTR [edx+eax*8+0x4],ebx
  Branch16:
    pop    esi
    pop    ebx
    ret    0x1c
  Branch17:
    test   esi,esi
    jne    Branch15
    pop    esi
    mov    DWORD PTR ds:0x10093b20,0x26
    pop    ebx
    ret    0x1c
  }
}
