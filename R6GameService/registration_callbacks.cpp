#include "native_addresses.h"

// Shared service callbacks. Diagnostic spellings identify registration roles; physical uint return views expose EAX residue.
// Original callback declarations and private reply layouts remain incomplete; retain explicit offsets and native widths.

// When logging is enabled, report match-start callback, then read current low replyBYTE and log reason on27.
// Cached Logf target/current logger; all three physical words remain in stdcall pop, unused third word untouched.
// R6GameService.dll @ 10013060 : RET12; disabled logging avoids all argument reads.
__declspec(naked) uint __stdcall RegServerRcv_LobbyServerMatchStartReply(uint word0,uint word1,uint word2)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    __asm {
      push   esi
    }
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerMatchStartReply);
    byte reply = *(byte *)(nativeFrame + 4);
    rawEax = (rawEax & 0xffffff00) | reply;
    if (reply == 0x27) {
      uint reason = *(uint *)(nativeFrame + 8);
      device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,
          (const TCHAR *)R6GameServiceAddresses::WideTextRegServerRcvLobbyServerMatchStartReplyFailedIReasonD,reason);
    }
    __asm {
      pop    esi
    }
  }
  __asm {
    mov    eax,rawEax
    ret    0xc
  }
}

// Optionally log match-finish callback; ignore three physical argument words and preserve raw log/gate EAX.
// R6GameService.dll @ 100130b0 : raw EAX diagnostic result; stdcall pops 12 bytes.
uint __stdcall RegServerRcv_LobbyServerMatchFinishReply(uint word0,uint word1,uint word2)
{
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerMatchFinishReply);
  }
  return rawEax;
}

// Optionally log router login/reason, then publish captured low replyBYTE as DWORD at93b10.
// Capture Logf before gates, read reply after first log, recheck current logging for27 reason; store follows diagnostics.
// R6GameService.dll @ 100130e0 : RET12; reply is sampled after the first diagnostic and published after restoring ESI.
__declspec(naked) uint __stdcall RegServerRcv_LoginRouterResult(uint word0,uint word1,uint word2)
{
  byte *nativeFrame;
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  __asm {
    push   ebx
    push   esi
    mov    nativeFrame,esp
  }
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginRouterResult);
  }
  uint reply = *(byte *)(nativeFrame + 0xc);
  if (reply == 0x27) {
    rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
    if (rawEax != 0) {
      uint reason = *(uint *)(nativeFrame + 0x10);
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,
          (const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginRouterResultFailedReasonI,reason);
    }
  } else rawEax = reply;
  __asm {
    pop    esi
  }
  *(uint *)0x10093b10 = reply;
  __asm {
    mov    eax,rawEax
    pop    ebx
    ret    0xc
  }
}

// Optionally log router login disconnection; no status publication or arguments.
// R6GameService.dll @ 10013160 : raw EAX diagnostic result; stdcall pops 0 bytes.
uint __stdcall RegServerRcv_LoginDisconnection(void)
{
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLoginDisconnection);
  }
  return rawEax;
}

// Publish low replyBYTE, low portWORD and full groupID, then copy ANSI address including terminator without a capacity gate.
// Optional conversion/log uses captured string/port/group; CURRENT replyBYTE27 logs reason even when logging disabled.
// R6GameService.dll @ 10013180 : RET24; bytewise address copy has no capacity bound and failure logging is unconditional.
__declspec(naked) uint __stdcall RegServerRcv_RegisterServerResult(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5)
{
  byte *nativeFrame;
  uint reply,group,port;
  const char *address;
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
    mov    nativeFrame,esp
    mov    reply,eax
    mov    group,ebx
    mov    port,esi
    mov    address,edi
  }
  *(uint *)0x10093b00 = reply;
  *(uint *)0x10093b28 = port;
  *(uint *)0x10093b1c = group;
  uint cursor = (uint)address;
  uint displacement = 0x100939f0 - (uint)address;
  byte value;
  do {
    value = *(byte *)cursor;
    *(byte *)(displacement + cursor) = value;
    ++cursor;
  } while (value != 0);
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  if (rawEax != 0) {
    // Port and group remain below the ANSI conversion argument and become trailing Logf arguments.
    __asm {
      push   ebx
      push   esi
    }
    using ConvertABI = const TCHAR * (__cdecl *)(const char *);
    const TCHAR *wide = (*(ConvertABI *)R6GameServiceAddresses::Core__appFromAnsiSlot)(address);
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    __asm {
      mov    eax,wide
      mov    edx,device
      mov    ebp,logger
      push   eax
      push   R6GameServiceAddresses::WideTextCallbackRegServerRcvRegisterServerResultSII
      push   edx
      call   ebp
      add    esp,0x14
      mov    rawEax,eax
    }
  }
  if (*(byte *)(nativeFrame + 0x14) == 0x27) {
    uint reason = *(uint *)(nativeFrame + 0x18);
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = logger(device,
        (const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvRegisterServerResultFailedReasonI,reason);
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x18
  }
}

// Publish low replyBYTE as DWORD at93b30, then optionally log current second word; third physical word unused.
// R6GameService.dll @ 10013290 : stdcall/RET12; publication precedes the current logging gate and reason read.
uint __stdcall RegServerRcv_LobbyServerUpdateGroupSettingsResults(uint word0,uint word1,uint word2)
{
  uint reply = (byte)word0;
  *(uint *)0x10093b30 = reply;
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    uint reason = word1;
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerUpdateGroupSettingsResultsI,reason);
  }
  return rawEax;
}

// Capture logging gate, set disconnection DWORD93b04 to1, then optionally log; no arguments.
// R6GameService.dll @ 100132d0 : raw EAX diagnostic result; stdcall pops 0 bytes.
uint __stdcall RegServerRcv_LobbyServerDisconnection(void)
{
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  *(uint *)0x10093b04 = 1;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerDisconnection);
  }
  return rawEax;
}

// When logging is enabled, convert first ANSI pointer and log new-member diagnostic; all seven physical words are popped.
// Other words are ignored and conversion/log return residue remains; no null/length validation or own EH.
// R6GameService.dll @ 10013300 : stdcall/RET28; unused words stay unread and the ANSI conversion result is borrowed.
uint __stdcall RegServerRcv_LobbyServerNewMember(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6)
{
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    const char *name = (const char *)word0;
    using ConvertABI = const TCHAR * (__cdecl *)(const char *);
    const TCHAR *wide = (*(ConvertABI *)R6GameServiceAddresses::Core__appFromAnsiSlot)(name);
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerNewMemberS,wide);
  }
  return rawEax;
}

// Capture full lobby/group IDs, optionally log both, then CURRENT replyBYTE27 publishes status27.
// Nonzero captured group always appends(group,lobby) through current array bases; zero group/non27 publishes26. No own EH.
// R6GameService.dll @ 10013640 : RET28; nonzero group appends through two independent current array-base loads.
__declspec(naked) uint __stdcall RegServerRcv_RequestParentGroupResult(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6)
{
  uint logging,lobby,group;
  byte *nativeFrame;
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    mov    ebx,DWORD PTR [esp+0x10]
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    logging,eax
    mov    lobby,ebx
    mov    group,esi
    mov    nativeFrame,esp
  }
  if (logging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    __asm {
      push   edi
    }
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvRequestParentGroupResultILobbySrvIDI,lobby);
    device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvRequestParentGroupResultIGroupIDI,group);
    __asm {
      pop    edi
    }
  }
  byte reply = *(byte *)(nativeFrame + 0xc);
  uint rawEax = 0x27;
  if (reply == 0x27) *(uint *)0x10093b20 = rawEax;
  if (group != 0) {
    using AddABI = uint (__thiscall *)(void *,uint,uint);
    rawEax = (*(AddABI *)R6GameServiceAddresses::Core_FArray_AddSlot)
        ((void *)R6GameServiceAddresses::GServiceArray10,1,8);
    uint base = *(uint *)R6GameServiceAddresses::GServiceArray10;
    *(uint *)(base + rawEax * 8) = group;
    base = *(uint *)R6GameServiceAddresses::GServiceArray10;
    *(uint *)(base + rawEax * 8 + 4) = lobby;
  } else if (reply != 0x27) {
    __asm {
      pop    esi
    }
    *(uint *)0x10093b20 = 0x26;
    __asm {
      mov    eax,rawEax
      pop    ebx
      ret    0x1c
    }
  }
  __asm {
    mov    eax,rawEax
    pop    esi
    pop    ebx
    ret    0x1c
  }
}
