#include "native_addresses.h"

// Native MS service delegate names are supported by diagnostics; original free/static class scope is unresolved.
// Raw uint return views retain EAX effects; original callback return declarations are not claimed.

// Log the saved full error word, then map unsigned0..20 through native tables into pending MS state.
// Error0/5,6,7/11 store91bfc=0/3/2 and91be0=0x27. Error1 sets91bf8=1;20 sets91bf0=1.
// Other values leave state unchanged; arguments2/3 unused. RET12; raw EAX is debug0 or logger result.
// Log precedes state writes, so a throwing logger leaves its effects and skips those writes.
// R6GameService.dll @ 10006c90 : complete native control/access order and raw ABI retained.
uint __stdcall MSError(uint error,uint unused2,uint unused3)
{
  const uint savedError = error;
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSErrorI), savedError);
  }
  switch (savedError) {
  case 0: *reinterpret_cast<int*>(0x10091bfc) = 0; *reinterpret_cast<int*>(0x10091be0) = 39; break;
  case 5: case 6: case 7:
    *reinterpret_cast<int*>(0x10091bfc) = 3; *reinterpret_cast<int*>(0x10091be0) = 39; break;
  case 11: *reinterpret_cast<int*>(0x10091bfc) = 2; *reinterpret_cast<int*>(0x10091be0) = 39; break;
  case 1: *reinterpret_cast<int*>(0x10091bf8) = 1; break;
  case 20: *reinterpret_cast<int*>(0x10091bf0) = 1; break;
  default: break;
  }
  return returnValue;
}

// Native MSError dispatch targets, including the shared default-return path.
// R6GameService.dll data @ 10006d2c : native storage identity retained.
const uint GMSErrorTargets[6] = {R6GameServiceAddresses::GMSErrorTargetsCase1,R6GameServiceAddresses::GMSErrorTargetsCase2,R6GameServiceAddresses::GMSErrorTargetsCase3,R6GameServiceAddresses::GMSErrorTargetsCase4,R6GameServiceAddresses::GMSErrorTargetsCase5,R6GameServiceAddresses::ms_service_callbacksBranch2};

// Native MSError byte dispatch map for unsigned error values0 through20.
// R6GameService.dll data @ 10006d44 : native storage identity retained.
const uchar GMSErrorCases[21] = {0,1,5,5,5,2,2,2,5,5,5,3,5,5,5,5,5,5,5,5,4};

// Publish low result-kind BYTE, then copy account ID for0x26 or save the full failure word for every other kind.
// The0x26 path forward-copies bytes through NUL into91d48 without bounds checks; accountId is borrowed.
// Result word is captured before copy/log, debug gate is read afterward; publication/partial copy survive faults.
// RET12; incoming ECX unused, raw EAX is late debug0 or current logger result; no guard/ownership/rollback.
// R6GameService.dll @ 10006d60 : complete native control/access order and raw ABI retained.
uint __stdcall MSInitFinished(uint resultKind,uint resultWord,const char *accountId)
{
  const byte kind = static_cast<byte>(resultKind);
  const uint savedResult = resultWord;
  *reinterpret_cast<uint*>(0x10091c10) = kind;
  if (kind == 38) {
    char* destination = reinterpret_cast<char*>(0x10091d48);
    const char* source = accountId;
    byte copied;
    do { copied = *source++; *destination++ = copied; } while (copied);
  } else {
    *reinterpret_cast<uint*>(0x10091d2c) = savedResult;
  }
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSInitFinishedI), savedResult);
  }
  return returnValue;
}

// Optionally log, then set request-finished DWORD91bf8 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no input, ownership, own guard or normalization.
// R6GameService.dll @ 10006dc0 : complete native control/access order and raw ABI retained.
uint __stdcall MSRequestFinished(void)
{
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...); // Captures incidental native EAX.
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSRequestFinished));
  }
  *reinterpret_cast<uint*>(0x10091bf8) = 1;
  return returnValue;
}

// Optionally log, then publish join result-kind DWORD91be0=0x26. Seven words unused, RET28.
// A throwing logger prevents publication; raw EAX/debug gate retained, no own guard or input ownership.
// R6GameService.dll @ 10006df0 : complete native control/access order and raw ABI retained.
uint __stdcall MSJoinFinished(
    uint unused1,uint unused2,uint unused3,uint unused4,uint unused5,uint unused6,uint unused7)
{
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...); // Captures incidental native EAX.
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSJoinFinished));
  }
  *reinterpret_cast<uint*>(0x10091be0) = 38;
  return returnValue;
}

// Optionally log, then set login-disconnect DWORD91c08 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no own guard or resource ownership.
// R6GameService.dll @ 10006e20 : complete native control/access order and raw ABI retained.
uint __stdcall MSLoginDisconnect(void)
{
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...); // Captures incidental native EAX.
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSLoginDisconnect));
  }
  *reinterpret_cast<uint*>(0x10091c08) = 1;
  return returnValue;
}

// Optionally log, then set lobby-disconnect DWORD91bf0 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no own guard or resource ownership.
// R6GameService.dll @ 10006e50 : complete native control/access order and raw ABI retained.
uint __stdcall MSLobbyDisconnect(void)
{
  uint returnValue = *reinterpret_cast<uint*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (returnValue) {
    using RawLogCall = uint (__cdecl *)(FOutputDevice*, const TCHAR*, ...); // Captures incidental native EAX.
    RawLogCall log = *reinterpret_cast<RawLogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    returnValue = log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSLobbyDisconnect));
  }
  *reinterpret_cast<uint*>(0x10091bf0) = 1;
  return returnValue;
}

// Append a raw838-byte server record, copy an optional payload and eight NUL-terminated byte strings.
// Diagnostic name supported; nineteen physical words/RET76, incoming ECX unused, original prototype unresolved.
// Queue923e8 stores arg2 groupID at108, arg1 lobby-serverID at10c, sign-extended low WORD arg3 at4.
// Arg5 ->114, args13..16 ->624..630, arg19 ->834; untouched bytes remain raw Add storage.
// Consumer/package map text4 to server name, text9 to version, text17/18 to IPs and word14 to player count.
// Signed-positive arg12 allocates payload61c; old record captures before allocation, current data reloads
// payload pointer afterward. Source arg11 loads late; forward DWORD/remainder copies have no NULL guard.
// Full captured length ->620; eight strings copy unbounded. Current data reloads between strings, not per byte.
// Debug counter updates/logs precede Add; Logf is cached across both logs, ANSI source/device load later.
// EBX/EBP/ESI restore before the final byte loop; faults retain that native epilogue timing.
// Alignment LEAs9c5d/9c9d/9cdd are dead padding after jumps; reachable alignment remains.
// Final EAX retains last data pointer upper bits with AL0; no local guard, rollback or failed-copy deallocation.
// R6GameService.dll @ 10009aa0 : complete native control/access order and raw ABI retained.
uint __stdcall MSGameServer(uint lobbyServerId,uint groupId,uint word3,const char *serverName,
    uint word5,const char *text6,const char *text7,const char *text8,const char *gameVersion,const char *text10,
    const void *payload,uint payloadSize,uint word13,uint playerCount,uint word15,uint word16,
    const char *ipAddress,const char *altIpAddress,uint word19)
{
  FArray* queue = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray3);
  if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
    const int queued = *reinterpret_cast<int*>(reinterpret_cast<byte*>(queue) + 4);
    uint counter = queued == 0 ? 0 : *reinterpret_cast<uint*>(0x100933c0);
    using LogCall = void (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
    LogCall log = *reinterpret_cast<LogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    ++counter;
    *reinterpret_cast<uint*>(0x100933c0) = counter;
    log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextAddAServerInTheListTotalWillBeD), counter);
    const TCHAR* name = appFromAnsi(serverName);
    log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSGameServerS), name);
  }
  const int added = queue->Add(1, 0x838); // Raw storage: untouched record bytes are not initialized.
  byte* data = *reinterpret_cast<byte**>(queue);
  const uint size = payloadSize;
  const uint offset = static_cast<uint>(added) * 0x838U;
  *reinterpret_cast<uint*>(data + offset + 0x108) = groupId;
  data = *reinterpret_cast<byte**>(queue);
  const uint server = lobbyServerId;
  const int lowWord = static_cast<short>(word3);
  *reinterpret_cast<uint*>(data + offset + 0x10c) = server;
  data = *reinterpret_cast<byte**>(queue);
  const uint fifth = word5;
  *reinterpret_cast<int*>(data + offset + 4) = lowWord;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x114) = fifth;
  data = *reinterpret_cast<byte**>(queue);
  if (static_cast<int>(size) > 0) {
    byte* savedRow = data + offset;
    void* allocated = GMalloc->Malloc(size,
        reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextGAMESERVICE));
    *reinterpret_cast<void**>(savedRow + 0x61c) = allocated;
    data = *reinterpret_cast<byte**>(queue);
    void* destination = *reinterpret_cast<void**>(data + offset + 0x61c);
    const void* source = payload; // Late argument read after allocation/current queue reload.
    // Retained forward DWORD/remainder kernel: borrowed source, current destination, full captured byte count.
    // It inherits DF, has no null guard, and preserves overlap/order effects that a generic memcpy contract would lose.
    __asm {
      mov esi,source
      mov edi,destination
      mov ecx,size
      mov eax,ecx
      shr ecx,0x2
      rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
      mov ecx,eax
      and ecx,0x3
      rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    }
  } else {
    *reinterpret_cast<void**>(data + offset + 0x61c) = nullptr;
  }
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x620) = size;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x624) = word13;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x628) = playerCount;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x62c) = word15;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x630) = word16;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0x834) = word19;
  auto copyText = [&](const char* source, uint field) {
    char* destination = reinterpret_cast<char*>(*reinterpret_cast<byte**>(queue) + offset + field);
    byte copied;
    do { copied = *source++; *destination++ = copied; } while (copied);
  };
  copyText(serverName, 8);
  copyText(text6, 0x11c);
  copyText(text7, 0x21c);
  copyText(text8, 0x31c);
  copyText(gameVersion, 0x41c);
  copyText(text10, 0x51c);
  copyText(ipAddress, 0x634);
  byte* finalData = *reinterpret_cast<byte**>(queue);
  const char* source = altIpAddress;
  char* destination = reinterpret_cast<char*>(finalData + offset + 0x734);
  byte copied;
  do { copied = *source++; *destination++ = copied; } while (copied);
  // The callback's original return declaration is unknown; preserve native EAX's data-pointer high bytes and final AL=0.
  return reinterpret_cast<uint>(finalData) & 0xffffff00U;
}

// Append a16-byte alternate-info record and copy its signed-positive-sized payload after allocation.
// Diagnostic name supported; four physical words/RET16, incoming ECX unused; original declaration unresolved.
// Optional log precedes91e74=0 and Add(1,16) on923c4; store arg1 lobby-serverID at4, arg2 groupID at0, size atc.
// Capture old record for allocated pointer+8; reload current data/payload pointer after allocator returns.
// Payload source is argument3, read after allocation; argument1 is never a payload source despite decompilation.
// Nonpositive sizes store pointer0 and return raw current data EAX; positive path returns captured full size.
// Forward DWORD/remainder copy, no bounds/NULL check, own guard or failed-copy deallocation; prefixes persist.
// R6GameService.dll @ 10009d10 : complete native control/access order and raw ABI retained.
uint __stdcall MSAlternateInfo(uint lobbyServerId,uint groupId,const void *payload,uint payloadSize)
{
  if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging))
    GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackMSAlternateInfo));
  FArray* queue = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray2);
  *reinterpret_cast<int*>(R6GameServiceAddresses::GCreateLobbyRequested) = 0;
  const int added = queue->Add(1, 16);
  byte* data = *reinterpret_cast<byte**>(queue);
  const uint size = payloadSize;
  const uint offset = static_cast<uint>(added) * 16U;
  *reinterpret_cast<uint*>(data + offset + 4) = lobbyServerId;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset) = groupId;
  *reinterpret_cast<uint*>(*reinterpret_cast<byte**>(queue) + offset + 0xc) = size;
  data = *reinterpret_cast<byte**>(queue);
  if (static_cast<int>(size) > 0) {
    byte* savedRow = data + offset;
    void* allocated = GMalloc->Malloc(size,
        reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextGAMESERVICE));
    *reinterpret_cast<void**>(savedRow + 8) = allocated;
    data = *reinterpret_cast<byte**>(queue);
    void* destination = *reinterpret_cast<void**>(data + offset + 8);
    const void* source = payload;
    // Retained forward DWORD/remainder kernel: borrowed source, current destination, full captured byte count.
    // It inherits DF, has no null guard, and preserves overlap/order effects that a generic memcpy contract would lose.
    __asm {
      mov esi,source
      mov edi,destination
      mov ecx,size
      mov eax,ecx
      shr ecx,0x2
      rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
      mov ecx,eax
      and ecx,0x3
      rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    }
    return size;
  }
  *reinterpret_cast<void**>(data + offset + 8) = nullptr;
  return reinterpret_cast<uint>(data);
}

// Publish match IDs and initialize result submission when the current context permits it; retry AL0 once.
// Three physical words/RET12; incoming ECX unused. Logf caches before the first gate; later gates/devices are live.
// IDs snapshot before logging and publish before flag+2c mask0x4 test. First match-start result uses only AL.
// Init result zeroextends AL into saved ESI; AL0 clears result storage and retries with the original match word.
// No gate recheck or ownership guard. Raw EAX follows native log/gate/retry residue rather than a bool result.
// R6GameService.dll @ 10006e80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSMatchStartedCB(uint lobbyServerId,uint groupId,uint matchId)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    mov    ebx,DWORD PTR [esp+0x10]
    push   ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   esi
    mov    esi,DWORD PTR [esp+0x14]
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    je     Branch26
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   ebx
    push   esi
    push   edi
    push   R6GameServiceAddresses::WideTextCallbackMSMatchStartedCBCallBackLobbyIdDRoomIdDAndUiMatchIDD
    push   ecx
    call   ebp
    add    esp,0x14
  Branch26:
    mov    edx,DWORD PTR ds:0x10091c18
    mov    DWORD PTR ds:0x10091e4c,edi
    mov    DWORD PTR ds:0x10091d44,esi
    test   BYTE PTR [edx+0x2c],0x4
    je     Branch30
    push   esi
    push   edi
    call   R6GameServiceAddresses::ForwardMSClientOperation5
    test   al,al
    jne    Branch27
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch27
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientMatchStartedReturnedFalseBigProblemHere
    push   ecx
    call   ebp
    add    esp,0x8
  Branch27:
    push   ebx
    call   R6GameServiceAddresses::ForwardMSClientOperation6
    movzx  esi,al
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch28
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   R6GameServiceAddresses::WideTextMSClientInitMatchResultReturnedX
    push   eax
    call   ebp
    add    esp,0xc
  Branch28:
    test   esi,esi
    jne    Branch31
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch29
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextRetrying
    push   edx
    call   ebp
    add    esp,0x8
  Branch29:
    call   R6GameServiceAddresses::DispatchSingletonSubobject3f1c0
    push   ebx
    call   R6GameServiceAddresses::ForwardMSClientOperation6
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    movzx  eax,al
    je     Branch31
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientInitMatchResultReturnedX
    push   ecx
    call   ebp
    add    esp,0xc
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  Branch30:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch31
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSMatchStartedCBThisClientWillNotBeSubmitingScores
    push   eax
    call   ebp
    add    esp,0x8
  Branch31:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Finish result submission when enabled, dispatch EndOfRoundDataSent, then clear the current submit flag.
// Three physical words/RET12; arguments affect diagnostic selection only; return raw current context pointer.
// No-submit/no-log retains initial ECX; every helper/log path reloads context before event lookup.
// Event receiver/vtable cache before FindFunctionChecked; function/NULL params/NULL result go to ProcessEvent.
// Context/flags reload after event; failures retain prior effects and skip the late bit clear. No own guard.
// R6GameService.dll @ 10006fa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSSubmitMatchCB(uint resultKind,uint reasonWord,uint matchId)
{
  __asm {
    mov    ecx,DWORD PTR ds:0x10091c18
    test   BYTE PTR [ecx+0x2c],0x4
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    je     Branch35
    test   eax,eax
    je     Branch34
    cmp    BYTE PTR [esp+0x4],0x27
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    jne    Branch32
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackMSSubmitMatchCBCallBackErrorReasonIdD
    jmp    Branch33
  Branch32:
    mov    eax,DWORD PTR [esp+0xc]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackMSSubmitMatchCBCallBackSuccessUiMatchIDD
  Branch33:
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch34:
    call   R6GameServiceAddresses::DispatchSingletonSubobject3f1c0
    mov    eax,ds:0x10091d44
    mov    ecx,DWORD PTR ds:0x10091e4c
    push   eax
    push   ecx
    call   R6GameServiceAddresses::DispatchSingletonSubobject3f1e0
    jmp    Branch36
  Branch35:
    test   eax,eax
    je     Branch37
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSSubmitMatchCBThisClientIsNotSubmitingScores
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch36:
    mov    ecx,DWORD PTR ds:0x10091c18
  Branch37:
    mov    edx,DWORD PTR ds:0x10092e54
    push   esi
    push   edi
    mov    edi,DWORD PTR [ecx]
    push   0x0
    push   0x0
    push   0x0
    push   edx
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    mov    eax,ds:0x10091c18
    mov    ecx,DWORD PTR [eax+0x2c]
    and    ecx,0xfffffffb
    pop    edi
    mov    DWORD PTR [eax+0x2c],ecx
    pop    esi
    ret    0xc
  }
}
