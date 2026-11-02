#include "native_addresses.h"

// Shared service callbacks. Diagnostic spellings identify registration roles; physical uint return views expose EAX residue.
// Original callback declarations and private reply layouts remain incomplete; retain explicit offsets and native widths.

// For active activation, optionally log reply reason, then copy two16-byte result blocks on nonzero replyBYTE4 or store failure WORD6.
// Inactive callbacks only optionally log. Success publishes state6 after copies; failure reason precedes state3. No own EH.
// R6GameService.dll @ 1000dc00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReceiveActivationReply(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GActivationState
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    jne    Branch1
    test   eax,eax
    je    Branch4
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackIgnoreResultsFromRcvActivationID
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    ret    0x10
  Branch1:
    test   eax,eax
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    je    Branch2
    movzx  edx,WORD PTR [esi+0x6]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackRcvActivationIDErrorI
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch2:
    mov    al,BYTE PTR [esi+0x4]
    test   al,al
    je    Branch3
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [edx]
    mov    ds:0x100933e4,eax
    mov    ecx,DWORD PTR [edx+0x4]
    mov    DWORD PTR ds:0x100933e8,ecx
    mov    eax,DWORD PTR [edx+0x8]
    mov    ds:0x100933ec,eax
    mov    ecx,DWORD PTR [edx+0xc]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR ds:0x100933f0,ecx
    mov    eax,DWORD PTR [edx]
    mov    ds:0x10093418,eax
    mov    ecx,DWORD PTR [edx+0x4]
    mov    DWORD PTR ds:0x1009341c,ecx
    mov    eax,DWORD PTR [edx+0x8]
    mov    ds:0x10093420,eax
    mov    ecx,DWORD PTR [edx+0xc]
    mov    DWORD PTR ds:0x10093424,ecx
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x6
    pop    esi
    ret    0x10
  Branch3:
    movzx  edx,WORD PTR [esi+0x6]
    mov    DWORD PTR ds:0x100933f4,edx
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x3
    pop    esi
  Branch4:
    ret    0x10
  }
}

// For active authorization, optionally log current status/reason, then publish state6 before copying20-byte result or state7 before failure reason.
// Preserve early activity/logging gates, late reply/pointer reads and raw return residue; no rollback or own EH.
// R6GameService.dll @ 1000dcd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReceiveAuthorizationReply(uint word0,uint word1,uint word2)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GAuthorizationState
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    jne    Branch5
    test   eax,eax
    je    Branch8
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackIgnoreResultsFromRcvAuthorizationID
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    ret    0xc
  Branch5:
    test   eax,eax
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    je    Branch6
    movzx  edx,WORD PTR [esi+0x6]
    movzx  eax,BYTE PTR [esi+0x4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   edx
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideText1CallbackRcvAuthorizationIDSuccessXErrorIdD
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
  Branch6:
    mov    al,BYTE PTR [esi+0x4]
    test   al,al
    je    Branch7
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x6
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR ds:0x10093428,ecx
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR ds:0x1009342c,edx
    mov    ecx,DWORD PTR [eax+0x8]
    mov    DWORD PTR ds:0x10093430,ecx
    mov    edx,DWORD PTR [eax+0xc]
    mov    DWORD PTR ds:0x10093434,edx
    mov    eax,DWORD PTR [eax+0x10]
    mov    ds:0x10093438,eax
    pop    esi
    ret    0xc
  Branch7:
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x7
    movzx  ecx,WORD PTR [esi+0x6]
    mov    DWORD PTR ds:0x10093414,ecx
    pop    esi
  Branch8:
    ret    0xc
  }
}
