#include "native_addresses.h"

// Service message dispatcher; original record/interface declarations remain unresolved and accesses stay offset-based.

// Routes current native message words, copies byte fields forward to session globals, and emits diagnostics with cached logger/converter.
// Message and logging reloads, unchecked byte loops and deferred cdecl stack cleanup remain native; second argument unused.
// R6GameService.dll @ 10011b10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall DispatcherProc(void *record,void *unusedContext)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    push   ebx
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    je     Branch1
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMDwMsgIDI
    push   edx
    call   ebx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0xc
  Branch1:
    mov    eax,DWORD PTR [esi]
    mov    ds:0x100938c8,eax
    mov    eax,DWORD PTR [esi]
    cmp    eax,0x10100
    ja     Branch10
    je     Branch9
    sub    eax,0x10001
    cmp    eax,0x4
    ja     Branch13
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GDispatcherMessageSwitch]
    mov    ecx,DWORD PTR [esi+0x1c]
    mov    edx,0x100936c8
    lea    ebx,[ebx+0x0]
  Branch2:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch2
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,0x100937c8
  Branch3:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch3
    mov    ecx,DWORD PTR [esi+0x20]
    mov    edx,0x100935c0
  Branch4:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch4
    call   R6GameServiceAddresses::GetGameConfigCallback
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ds:0x100938cc,eax
    mov    ecx,DWORD PTR [esi+0x14]
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecondaryLobbyServerId,ecx
    mov    edx,DWORD PTR [esi+0x18]
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecondaryGroupId,edx
    mov    eax,DWORD PTR [esi+0x10]
    push   eax
    call   edi
    push   eax
    call   R6GameServiceAddresses::SetSelectedProductCategory
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x8
    test   eax,eax
    je     Branch13
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSCHSTAINITMASTERSESSION
    push   edx
    call   ebx
    mov    eax,DWORD PTR [esi+0x10]
    push   eax
    call   edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzGameNameS
    push   edx
    call   ebx
    mov    eax,DWORD PTR [esi+0x8]
    push   eax
    call   edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzUserNameS
    push   edx
    call   ebx
    mov    eax,DWORD PTR [esi+0x20]
    push   eax
    call   edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzRoomPasswordS
    push   edx
    call   ebx
    mov    eax,DWORD PTR [esi+0x14]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMNLobbyServerIDI
    push   edx
    call   ebx
    mov    eax,DWORD PTR [esi+0x18]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    add    esp,0x44
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMNGroupIDI
    push   edx
    call   ebx
    add    esp,0xc
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
    mov    ecx,DWORD PTR [esi+0x28]
    mov    edx,0x100934c0
    nop
  Branch5:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch5
    mov    ecx,DWORD PTR [esi+0x2c]
    mov    edx,0x100938d0
  Branch6:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch6
    mov    ecx,DWORD PTR [esi+0x8]
    mov    edx,0x100937c8
  Branch7:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch7
    mov    eax,DWORD PTR [esi+0x30]
    mov    ds:0x100939d0,eax
    mov    ecx,DWORD PTR [esi+0x20]
    mov    edx,0x100935c0
    mov    edi,edi
  Branch8:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch8
    mov    ecx,DWORD PTR [esi+0x10]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   ecx
    call   edi
    push   eax
    call   R6GameServiceAddresses::SetSelectedProductCategory
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x8
    test   eax,eax
    je     Branch13
    mov    edx,DWORD PTR [esi+0x8]
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzUserNameS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0xc]
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzUserPasswordS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x10]
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzGameNameS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x14]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMNLobbyServerIDI
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x18]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMNGroupIDI
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x1c]
    add    esp,0x48
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzRoomNameS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x20]
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzRoomPasswordS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x24]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMUnMaxPlayerI
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x28]
    push   edx
    call   edi
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzPrimaryGameServerIPS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x2c]
    push   edx
    call   edi
    add    esp,0x40
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMCzSecondaryGameServerIPS
    push   ecx
    call   ebx
    mov    edx,DWORD PTR [esi+0x30]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMDwGamePortI
    push   ecx
    call   ebx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSCHSTAINITCLIENTSESSION
    push   eax
    call   ebx
    add    esp,0x20
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
    test   ecx,ecx
    je     Branch13
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSCHSTAMASTERSESSION
    jmp    Branch12
    test   ecx,ecx
    je     Branch13
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSCHSTACLIENTSESSION
    push   ecx
    call   ebx
    add    esp,0x8
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
    test   ecx,ecx
    je     Branch13
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSCHSTATERMINATE
    push   eax
    call   ebx
    add    esp,0x8
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch9:
    test   ecx,ecx
    je     Branch13
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSSWITCHTOGSAK
    jmp    Branch12
  Branch10:
    cmp    eax,0x10200
    je     Branch11
    cmp    eax,0x11000
    jne    Branch13
    test   ecx,ecx
    mov    eax,DWORD PTR [esi+0xc]
    mov    ds:0x100936c0,eax
    je     Branch13
    mov    ecx,DWORD PTR [esi+0xc]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSERRORI
    push   eax
    call   ebx
    add    esp,0xc
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
  Branch11:
    test   ecx,ecx
    je     Branch13
    push   R6GameServiceAddresses::WideTextCallbackDispatcherProcMSGFGSREADYTORECEIVECONNECTIONSAK
  Branch12:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   edx
    call   ebx
    add    esp,0x8
  Branch13:
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    ret    0x8
  }
}

// R6GameService.dll data @ 10011eac : native five-message dispatch table.
const uint GDispatcherMessageSwitch[5] = {R6GameServiceAddresses::GDispatcherMessageSwitchCase1,R6GameServiceAddresses::GDispatcherMessageSwitchCase2,R6GameServiceAddresses::GDispatcherMessageSwitchCase3,R6GameServiceAddresses::GDispatcherMessageSwitchCase4,R6GameServiceAddresses::GDispatcherMessageSwitchCase5};
