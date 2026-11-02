#include "native_addresses.h"

// Native MS service delegate names are supported by diagnostics; original free/static class scope is unresolved.
// Raw uint return views retain EAX effects; original callback return declarations are not claimed.

// Log the saved full error word, then map unsigned0..20 through native tables into pending MS state.
// Error0/5,6,7/11 store91bfc=0/3/2 and91be0=0x27. Error1 sets91bf8=1;20 sets91bf0=1.
// Other values leave state unchanged; arguments2/3 unused. RET12; raw EAX is debug0 or logger result.
// Log precedes state writes, so a throwing logger leaves its effects and skips those writes.
// R6GameService.dll @ 10006c90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSError(uint error,uint unused2,uint unused3)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    je     Branch1
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   esi
    push   R6GameServiceAddresses::WideTextCallbackMSErrorI
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch1:
    cmp    esi,0x14
    ja     Branch2
    movzx  edx,BYTE PTR [esi+R6GameServiceAddresses::GMSErrorCases]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GMSErrorTargets]
    mov    DWORD PTR ds:0x10091bf0,0x1
    pop    esi
    ret    0xc
    mov    DWORD PTR ds:0x10091bf8,0x1
    pop    esi
    ret    0xc
    mov    DWORD PTR ds:0x10091bfc,0x2
    mov    DWORD PTR ds:0x10091be0,0x27
    pop    esi
    ret    0xc
    mov    DWORD PTR ds:0x10091bfc,0x3
    mov    DWORD PTR ds:0x10091be0,0x27
    pop    esi
    ret    0xc
    mov    DWORD PTR ds:0x10091bfc,0x0
    mov    DWORD PTR ds:0x10091be0,0x27
  Branch2:
    pop    esi
    ret    0xc
  }
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
__declspec(naked) uint __stdcall MSInitFinished(uint resultKind,uint resultWord,const char *accountId)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    cmp    al,0x26
    movzx  ecx,al
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    mov    DWORD PTR ds:0x10091c10,ecx
    jne    Branch4
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,0x10091d48
    sub    edx,eax
  Branch3:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test   cl,cl
    jne    Branch3
    jmp    Branch5
  Branch4:
    mov    DWORD PTR ds:0x10091d2c,esi
  Branch5:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch6
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   R6GameServiceAddresses::WideTextCallbackMSInitFinishedI
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch6:
    pop    esi
    ret    0xc
  }
}

// Optionally log, then set request-finished DWORD91bf8 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no input, ownership, own guard or normalization.
// R6GameService.dll @ 10006dc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSRequestFinished(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch7
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSRequestFinished
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch7:
    mov    DWORD PTR ds:0x10091bf8,0x1
    ret
  }
}

// Optionally log, then publish join result-kind DWORD91be0=0x26. Seven words unused, RET28.
// A throwing logger prevents publication; raw EAX/debug gate retained, no own guard or input ownership.
// R6GameService.dll @ 10006df0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSJoinFinished(
    uint unused1,uint unused2,uint unused3,uint unused4,uint unused5,uint unused6,uint unused7)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch8
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSJoinFinished
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch8:
    mov    DWORD PTR ds:0x10091be0,0x26
    ret    0x1c
  }
}

// Optionally log, then set login-disconnect DWORD91c08 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no own guard or resource ownership.
// R6GameService.dll @ 10006e20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSLoginDisconnect(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch9
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSLoginDisconnect
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch9:
    mov    DWORD PTR ds:0x10091c08,0x1
    ret
  }
}

// Optionally log, then set lobby-disconnect DWORD91bf0 to1. RET0, raw EAX/debug gate retained.
// A throwing logger prevents the pending-state store; no own guard or resource ownership.
// R6GameService.dll @ 10006e50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSLobbyDisconnect(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch10
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSLobbyDisconnect
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch10:
    mov    DWORD PTR ds:0x10091bf0,0x1
    ret
  }
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
__declspec(naked) uint __stdcall MSGameServer(uint lobbyServerId,uint groupId,uint word3,const char *serverName,
    uint word5,const char *text6,const char *text7,const char *text8,const char *gameVersion,const char *text10,
    const void *payload,uint payloadSize,uint word13,uint playerCount,uint word15,uint word16,
    const char *ipAddress,const char *altIpAddress,uint word19)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    push   ebp
    push   esi
    je     Branch13
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3+0x4
    test   eax,eax
    jne    Branch11
    xor    eax,eax
    jmp    Branch12
  Branch11:
    mov    eax,ds:0x100933c0
  Branch12:
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    inc    eax
    push   eax
    mov    ds:0x100933c0,eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextAddAServerInTheListTotalWillBeD
    push   ecx
    call   esi
    mov    edx,DWORD PTR [esp+0x28]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSGameServerS
    push   ecx
    call   esi
    add    esp,0x1c
  Branch13:
    push   0x838
    push   0x1
    mov    ecx,R6GameServiceAddresses::GServiceArray3
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ebp,DWORD PTR [esp+0x3c]
    mov    ebx,eax
    mov    eax,DWORD PTR [esp+0x14]
    imul   ebx,ebx,0x838
    test   ebp,ebp
    mov    DWORD PTR [ebx+edx*1+0x108],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    edx,DWORD PTR [esp+0x10]
    movsx  eax,WORD PTR [esp+0x18]
    mov    DWORD PTR [ebx+ecx*1+0x10c],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    edx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [ebx+ecx*1+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    DWORD PTR [ebx+eax*1+0x114],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    jle    Branch14
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    push   edi
    lea    esi,[ebx+ecx*1]
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   ebp
    call   DWORD PTR [eax]
    mov    DWORD PTR [esi+0x61c],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    edi,DWORD PTR [ebx+edx*1+0x61c]
    mov    esi,DWORD PTR [esp+0x3c]
    mov    ecx,ebp
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    jmp    Branch15
  Branch14:
    mov    DWORD PTR [ebx+ecx*1+0x61c],0x0
  Branch15:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x40]
    mov    DWORD PTR [ebx+edx*1+0x620],ebp
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    DWORD PTR [ebx+eax*1+0x624],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    eax,DWORD PTR [esp+0x44]
    mov    DWORD PTR [ebx+edx*1+0x628],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    edx,DWORD PTR [esp+0x48]
    mov    DWORD PTR [ebx+ecx*1+0x62c],edx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [ebx+eax*1+0x630],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    eax,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [ebx+edx*1+0x834],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    lea    edx,[ebx+edx*1+0x8]
    lea    ebx,[ebx+0x0]
  Branch16:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch16
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x24]
    lea    edx,[ebx+eax*1+0x11c]
    lea    ebx,[ebx+0x0]
  Branch17:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch17
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x28]
    lea    edx,[ebx+edx*1+0x21c]
    jmp    Branch18
    lea    ecx,[ecx+0x0]
  Branch18:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch18
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x2c]
    lea    edx,[ebx+eax*1+0x31c]
    lea    ebx,[ebx+0x0]
  Branch19:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch19
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x30]
    lea    edx,[ebx+edx*1+0x41c]
    jmp    Branch20
    lea    ecx,[ecx+0x0]
  Branch20:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch20
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x34]
    lea    edx,[ebx+eax*1+0x51c]
    lea    ebx,[ebx+0x0]
  Branch21:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch21
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x50]
    lea    edx,[ebx+edx*1+0x634]
    jmp    Branch22
    lea    ecx,[ecx+0x0]
  Branch22:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch22
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [esp+0x54]
    pop    esi
    pop    ebp
    lea    edx,[ebx+eax*1+0x734]
    pop    ebx
    lea    ecx,[ecx+0x0]
  Branch23:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch23
    ret    0x4c
  }
}

// Append a16-byte alternate-info record and copy its signed-positive-sized payload after allocation.
// Diagnostic name supported; four physical words/RET16, incoming ECX unused; original declaration unresolved.
// Optional log precedes91e74=0 and Add(1,16) on923c4; store arg1 lobby-serverID at4, arg2 groupID at0, size atc.
// Capture old record for allocated pointer+8; reload current data/payload pointer after allocator returns.
// Payload source is argument3, read after allocation; argument1 is never a payload source despite decompilation.
// Nonpositive sizes store pointer0 and return raw current data EAX; positive path returns captured full size.
// Forward DWORD/remainder copy, no bounds/NULL check, own guard or failed-copy deallocation; prefixes persist.
// R6GameService.dll @ 10009d10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MSAlternateInfo(uint lobbyServerId,uint groupId,const void *payload,uint payloadSize)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    push   ebx
    xor    ebx,ebx
    cmp    eax,ebx
    push   esi
    push   edi
    je     Branch24
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackMSAlternateInfo
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch24:
    push   0x10
    push   0x1
    mov    ecx,R6GameServiceAddresses::GServiceArray2
    mov    DWORD PTR ds:R6GameServiceAddresses::GCreateLobbyRequested,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
    mov    esi,DWORD PTR [esp+0x1c]
    shl    eax,0x4
    cmp    esi,ebx
    mov    edi,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [edi+edx*1+0x4],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edi+ecx*1],edx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray2
    mov    DWORD PTR [edi+eax*1+0xc],esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
    jle    Branch25
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    lea    ebx,[edi+ecx*1]
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   esi
    call   DWORD PTR [eax]
    mov    DWORD PTR [ebx+0x8],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
    mov    edi,DWORD PTR [edi+edx*1+0x8]
    mov    ecx,esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebx
    ret    0x10
  Branch25:
    mov    DWORD PTR [edi+ecx*1+0x8],ebx
    pop    edi
    pop    esi
    pop    ebx
    ret    0x10
  }
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
