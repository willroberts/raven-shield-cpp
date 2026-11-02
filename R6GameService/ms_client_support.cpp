#include "native_addresses.h"

// Unassigned MS-client dispatch and callback helpers; argument meanings remain native words.
// Guarded wrapper uint results expose raw EAX; only AL is the success flag.

// Tail-forwards two untouched words through the current MS client, or clears only AL when it is absent.
// uint represents raw EAX; the absent-client path guarantees only zero AL. Original declaration is unavailable.
// R6GameService.dll @ 10032320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchMSClientState(uint firstWord,uint secondWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch1
    jmp    R6GameServiceAddresses::ProcessServiceClientState
  Branch1:
    xor    al,al
    ret    0x8
  }
}

// Polls fixed500/800 budgets, expires an unsigned deadline, then drains enabled callback paths with raw AL results.
// R6GameService.dll @ 10032940 : complete native control/access order and raw ABI retained.
uint __thiscall ProcessServiceClientState(void *client,uint unusedWord0,uint unusedWord1)
{
  byte* cachedClient = reinterpret_cast<byte*>(client);
  uint raw = PollTransportAndDispatchQueuedRecords(client, 500, 800);
  if (static_cast<byte>(raw) == 0) return raw;
  // Keep the original client across callback-producing calls; shutdown does not cause a global reload or stale-pointer guard.
  const byte pendingEnabled = *(cachedClient + 0x117);
  raw = (raw & 0xffffff00U) | pendingEnabled;
  if (pendingEnabled) {
    raw = *reinterpret_cast<uint*>(cachedClient + 0x100);
    if (raw) {
      raw = time(nullptr);
      if (*reinterpret_cast<uint*>(cachedClient + 0x100) < raw) {
        byte* table = *reinterpret_cast<byte**>(cachedClient);
        *reinterpret_cast<uint*>(cachedClient + 0x100) = 0;
        using ExpireCall = uint (__thiscall *)(void*);
        raw = (*reinterpret_cast<ExpireCall*>(table + 0x3c))(cachedClient);
        *(cachedClient + 0x114) = 0;
      }
    }
    raw = ProcessPendingCallbackEventsThroughSubobject(cachedClient, 500, 800);
    if (static_cast<byte>(raw) == 0) return raw;
  }
  const byte queueEnabled = *(cachedClient + 0x115);
  raw = (raw & 0xffffff00U) | queueEnabled;
  if (queueEnabled) raw = PollAndDispatchCallbackQueueViaSubobject(cachedClient, 500, 800);
  return (raw & 0xffffff00U) | 1U;
}

// Installs ten MS callbacks in order through independently guarded singleton wrappers; retains the last raw EAX.
// R6GameService.dll @ 1000acb0 : complete native operations and raw ABI; descriptive helper name.
uint __cdecl RegisterMSClientCallbacks(void)
{
  SetMSClientCallback1(R6GameServiceAddresses::MSGameServer);
  SetMSClientCallback3(R6GameServiceAddresses::MSError);
  SetMSClientCallback4(R6GameServiceAddresses::MSInitFinished);
  SetMSClientCallback7(R6GameServiceAddresses::MSRequestFinished);
  SetMSClientCallback8(R6GameServiceAddresses::MSJoinFinished);
  SetMSClientCallback5(R6GameServiceAddresses::MSLoginDisconnect);
  SetMSClientCallback6(R6GameServiceAddresses::MSLobbyDisconnect);
  SetMSClientCallback2(R6GameServiceAddresses::MSAlternateInfo);
  SetMSClientCallback9(R6GameServiceAddresses::MSMatchStartedCB);
  return SetMSClientCallback10(R6GameServiceAddresses::MSSubmitMatchCB);
  // Every setter reloads/guards its current singleton. Match callback implementations remain outside this lifecycle.
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 100324c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback1(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch6
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x11c
    mov    al,0x1
    ret    0x4
  Branch6:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 100324e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback2(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch7
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x120
    mov    al,0x1
    ret    0x4
  Branch7:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 10032500 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback3(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch8
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x124
    mov    al,0x1
    ret    0x4
  Branch8:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 10032520 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback4(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch9
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x128
    mov    al,0x1
    ret    0x4
  Branch9:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 10032540 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback5(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch10
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x12c
    mov    al,0x1
    ret    0x4
  Branch10:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 10032560 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback6(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch11
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreValueAtOffset_0x130
    mov    al,0x1
    ret    0x4
  Branch11:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 10032580 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback7(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch12
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreCallbackAtOffset_0x134
    mov    al,0x1
    ret    0x4
  Branch12:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 100325a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback8(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch13
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreCallbackAtOffset_0x138
    mov    al,0x1
    ret    0x4
  Branch13:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 100325c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback9(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch14
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreCallbackAtOffset_0x144
    mov    al,0x1
    ret    0x4
  Branch14:
    xor    al,al
    ret    0x4
  }
}

// Stores one word through the current MS singleton when present; sets only AL to success or failure.
// R6GameService.dll @ 100325e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall SetMSClientCallback10(uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch15
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::StoreCallbackAtOffset_0x148
    mov    al,0x1
    ret    0x4
  Branch15:
    xor    al,al
    ret    0x4
  }
}

// Invokes singleton slot+0x24 with1 if present, clears the current global after return, then sets only AL=1.
// R6GameService.dll @ 10032300 : raw EAX/AL boundary; original free/member declaration and client class unassigned.
uint __cdecl CloseMSClientSingleton(void)
{
  uint raw;
  __asm { mov raw,eax } // Absent-client path preserves incoming EAX high bytes; original return type is unrecovered.
  void* client = *reinterpret_cast<void**>(R6GameServiceAddresses::GMSClientSingleton);
  if (client) {
    byte* table = *reinterpret_cast<byte**>(client);
    using CloseCall = uint (__thiscall *)(void*, uint);
    raw = (*reinterpret_cast<CloseCall*>(table + 0x24))(client, 1);
  }
  *reinterpret_cast<void**>(R6GameServiceAddresses::GMSClientSingleton) = nullptr;
  return (raw & 0xffffff00U) | 1U;
}

// Forwards two untouched words to the current client request matcher, or clears only AL when absent.
// R6GameService.dll @ 100323c0 : raw EAX/AL boundary; original free/member declaration and client class unassigned.
__declspec(naked) uint __stdcall MatchMSClientStoredRequest(uint firstWord, uint secondWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch17
    jmp    R6GameServiceAddresses::CompleteStoredRequestIfMatched
  Branch17:
    xor    al,al
    ret    0x8
  }
}

// Matches both stored request words, dispatches payload, frees the current record, clears it and sends selector0x5c.
// R6GameService.dll @ 10033730 : raw EAX/AL boundary; original free/member declaration and client class unassigned.
__declspec(naked) uint __thiscall CompleteStoredRequestIfMatched(void *client, uint firstWord, uint secondWord)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x104]
    test   eax,eax
    je     Branch19
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [eax+0x4]
    cmp    edx,ecx
    jne    Branch19
    mov    edx,DWORD PTR [eax+0x8]
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edx,edi
    pop    edi
    jne    Branch19
    mov    BYTE PTR [esi+0x115],0x0
    mov    eax,DWORD PTR [eax+0xc]
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::ForwardTwoArgumentBooleanViaNestedOffsets
    mov    eax,DWORD PTR [esi+0x104]
    test   eax,eax
    je     Branch18
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch18:
    mov    ecx,esi
    mov    DWORD PTR [esi+0x104],0x0
    call   R6GameServiceAddresses::SendSelector5cViaNestedOffsets
    mov    al,0x1
    pop    esi
    ret    0x8
  Branch19:
    xor    al,al
    pop    esi
    ret    0x8
  }
}

// Allocate/publish the MS singleton, initialize it, and destroy its current replacement on failure.
// Raw EAX view: AL is0/1, upper bits retain native residue; original return declaration is unrecovered.
// Five untouched stack words/RET20. Existing singleton rejects without argument access; NULL allocation
// still reaches initialization with ECX0. No own guard/rollback, and failure reloads current singleton.
// R6GameService.dll @ 10032280 : complete native control/access order and raw ABI retained.
uint __stdcall CreateMSClientSingleton(char *router,uint port,char *user,char *password,char *globalText)
{
  uint raw = *reinterpret_cast<uint*>(R6GameServiceAddresses::GMSClientSingleton);
  if (raw) return raw & 0xffffff00U;
  void* block = AllocateGameServiceBytes(0x150);
  void* constructed = nullptr;
  if (block) {
    using ClientConstructor = void* (__thiscall *)(void*, uint);
    constructed = reinterpret_cast<ClientConstructor>(R6GameServiceAddresses::clMSClient_clMSClient)(block, 1);
  }
  // Read argument words only after allocation/construction; publish even a null construction result before initialization.
  char* finalGlobal = globalText;
  char* finalPassword = password;
  char* finalUser = user;
  uint finalPort = port;
  char* finalRouter = router;
  *reinterpret_cast<void**>(R6GameServiceAddresses::GMSClientSingleton) = constructed;
  raw = InitializeServiceClientFields(constructed, finalRouter, finalPort, finalUser, finalPassword, finalGlobal);
  if (static_cast<byte>(raw) != 0) return (raw & 0xffffff00U) | 1U;
  void* current = *reinterpret_cast<void**>(R6GameServiceAddresses::GMSClientSingleton);
  if (current) {
    byte* table = *reinterpret_cast<byte**>(current);
    using CloseCall = uint (__thiscall *)(void*, uint);
    raw = (*reinterpret_cast<CloseCall*>(table + 0x24))(current, 1);
  }
  *reinterpret_cast<void**>(R6GameServiceAddresses::GMSClientSingleton) = nullptr;
  return raw & 0xffffff00U;
}

// Copy fixed ANSI inputs, reset resource words/flags and return the chained backend raw EAX unchanged.
// Five physical words/RET20; original member declaration/type/field names unresolved, so ownership stays unassigned.
// Copies5a/129,18/16,28/16,39/33,de/33; each conditionally zeros its last byte after current strncpy.
// Port argument is read as WORD after the first copy, before the second call; source arguments reload in order.
// Resets100..110 DWORDs and114..117 bytes without releasing prior storage; no own guard or rollback.
// R6GameService.dll @ 100327a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeServiceClientFields(void *client,const char *field5a,
    uint portWord,const char *field18,const char *field28,const char *field39)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    push   0x81
    lea    edi,[esi+0x5a]
    push   eax
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x80]
    xor    ebx,ebx
    add    esp,0xc
    cmp    al,bl
    je     Branch25
    mov    BYTE PTR [edi+0x80],bl
  Branch25:
    mov    edx,DWORD PTR [esp+0x18]
    mov    cx,WORD PTR [esp+0x14]
    lea    edi,[esi+0x18]
    push   0x10
    push   edx
    push   edi
    mov    WORD PTR [esi+0xdc],cx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0xf]
    add    esp,0xc
    cmp    al,bl
    je     Branch26
    mov    BYTE PTR [edi+0xf],bl
  Branch26:
    mov    eax,DWORD PTR [esp+0x1c]
    lea    edi,[esi+0x28]
    push   0x10
    push   eax
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0xf]
    add    esp,0xc
    cmp    al,bl
    je     Branch27
    mov    BYTE PTR [edi+0xf],bl
  Branch27:
    mov    ecx,DWORD PTR [esp+0x20]
    lea    edi,[esi+0x39]
    push   0x21
    push   ecx
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch28
    mov    BYTE PTR [edi+0x20],bl
  Branch28:
    lea    edi,[esi+0xde]
    push   0x21
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch29
    mov    BYTE PTR [edi+0x20],bl
  Branch29:
    mov    ecx,esi
    mov    DWORD PTR [esi+0x100],ebx
    mov    DWORD PTR [esi+0x104],ebx
    mov    DWORD PTR [esi+0x108],ebx
    mov    DWORD PTR [esi+0x10c],ebx
    mov    DWORD PTR [esi+0x110],ebx
    mov    BYTE PTR [esi+0x114],bl
    mov    BYTE PTR [esi+0x115],bl
    mov    BYTE PTR [esi+0x116],bl
    mov    BYTE PTR [esi+0x117],bl
    call   R6GameServiceAddresses::CheckChainedProviderHelpers
    pop    edi
    pop    esi
    pop    ebx
    ret    0x14
  }
}

// Connect through the current provider, then submit three stored byte strings with full final word1.
// MOV AX preserves incoming upper EAX in the pushed port word; actual3f070 masks it to low16.
// First failure returns full raw EAX; second result normalizes only AL while retaining its upper bytes.
// No own resources/guard. Provider+14 reloads separately in the two actual clGLClient forwarding tails.
// R6GameService.dll @ 10032ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CheckChainedProviderHelpers(void *client)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    ax,WORD PTR [esi+0xdc]
    lea    ecx,[esi+0x5a]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::OpenPrimaryConnectionThroughSubobject
    test   al,al
    jne    Branch30
    pop    esi
    ret
  Branch30:
    lea    edx,[esi+0x39]
    push   0x1
    lea    eax,[esi+0x28]
    push   edx
    lea    ecx,[esi+0x18]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::SendStringTupleSelector66ViaOffset14
    test   al,al
    setne  al
    pop    esi
    ret
  }
}

// Free current104/108 buffers and captured110 list storage, reset live state, then reset the current provider.
// Only a nonnull108 clears10c. List container is saved before node/sentinel cleanup and freed via that pointer.
// Every clear follows its successful free; reset may republish resources, so later stages observe fresh fields.
// SET AL1 preserves upper provider EAX; no own EH, input ownership, rollback or retry.
// R6GameService.dll @ 100328b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReleaseServiceClientResources(void *client)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ebx,ebx
    push   edi
    mov    eax,DWORD PTR [esi+0x104]
    cmp    eax,ebx
    je     Branch31
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x104],ebx
  Branch31:
    mov    eax,DWORD PTR [esi+0x108]
    cmp    eax,ebx
    je     Branch32
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x108],ebx
    mov    DWORD PTR [esi+0x10c],ebx
  Branch32:
    mov    edi,DWORD PTR [esi+0x110]
    cmp    edi,ebx
    je     Branch33
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x110],ebx
  Branch33:
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetServiceClientState
    mov    ecx,esi
    call   R6GameServiceAddresses::DisconnectPrimaryConnectionViaOffset14
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret
  }
}

// Process current provider records, capture110, clear flags117/115/116/114 and deadline100, then free110/104.
// Captured list storage survives callbacks;104 reloads afterward.108/10c are untouched by this helper.
// Absent104 returns1; otherwise AL1 keeps the final free result upper bits. No own guard or rollback.
// R6GameService.dll @ 10033420 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResetServiceClientState(void *client)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    call   R6GameServiceAddresses::ProcessTransportRecordsViaNestedOffsets
    mov    edi,DWORD PTR [esi+0x110]
    xor    ebx,ebx
    cmp    edi,ebx
    mov    BYTE PTR [esi+0x117],bl
    mov    BYTE PTR [esi+0x115],bl
    mov    BYTE PTR [esi+0x116],bl
    mov    BYTE PTR [esi+0x114],bl
    mov    DWORD PTR [esi+0x100],ebx
    je     Branch34
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x110],ebx
  Branch34:
    mov    eax,DWORD PTR [esi+0x104]
    cmp    eax,ebx
    je     Branch35
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x104],ebx
  Branch35:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret
  }
}

// Tail-forward two untouched words through current MS singleton, or clear only AL when absent; RET8.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10032400 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation5(uint firstWord,uint secondWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch36
    jmp    R6GameServiceAddresses::ForwardProviderOperation3f1d0
  Branch36:
    xor    al,al
    ret    0x8
  }
}

// Tail-forward one untouched word through current MS singleton, or clear only AL when absent; RET4.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10032420 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation6(uint matchWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch37
    jmp    R6GameServiceAddresses::ForwardAdjustedProviderOperation
  Branch37:
    xor    al,al
    ret    0x4
  }
}

// Tail-clear current singleton result storage, or clear only AL when absent; RET0.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10032480 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl DispatchSingletonSubobject3f1c0(void)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch38
    jmp    R6GameServiceAddresses::DestroyEmbeddedServiceRecordList
  Branch38:
    xor    al,al
    ret
  }
}

// Tail-forward two untouched words through current MS singleton, or clear only AL when absent; RET8.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 100324a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchSingletonSubobject3f1e0(uint firstWord,uint secondWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch39
    jmp    R6GameServiceAddresses::ForwardProviderOperation3f1e0
  Branch39:
    xor    al,al
    ret    0x8
  }
}

// Tail-forward one full word to the GL adapter, preserving raw EAX and provider+14 timing; no own guard.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 100337c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardAdjustedProviderOperation(void *client,uint matchWord)
{
  __asm {
    jmp    R6GameServiceAddresses::CreateServiceRecordListViaNestedOffsets
  }
}

// Tail-forward result-store cleanup to the GL adapter with no arguments or own guard; raw EAX survives.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10033800 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DestroyEmbeddedServiceRecordList(void *client)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServiceRecordListViaOffset14
  }
}

// Reverse the two full words, call the GL adapter, then RET8 with its raw EAX; no own guard.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10033810 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProviderOperation3f1d0(void *client,uint firstWord,uint secondWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets
    ret    0x8
  }
}

// Reverse the two full words, call the GL adapter, then RET8 with its raw EAX; no own guard.
// Uint result exposes native register effects; original free/member declaration and formal types unresolved.
// R6GameService.dll @ 10033830 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProviderOperation3f1e0(void *client,uint firstWord,uint secondWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets2
    ret    0x8
  }
}

// Allocate 0x4c bytes for two links plus a 0x44-byte descriptor; receiver ECX is unused. Test allocation+8 modulo32, not allocation.
// Install literal offset table77080, copy full fields4/8/c, then bounded strings33/17 with final-byte clamps.
// Links and final two padding bytes stay unwritten; zero allocation still writes at8, fffffff8 skips copy.
// No own EH or failed-copy release; RET4 returns original allocation; ECX reloads the zero-initialized local scratch.
// R6GameService.dll @ 10033850 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CopyCallbackRecord(void *receiver,uint word1)
{
  __asm {
    push   ecx
    push   ebx
    push   esi
    push   0x4c
    mov    DWORD PTR [esp+0xc],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    lea    esi,[ebx+0x8]
    test   esi,esi
    je     Branch41
    push   ebp
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi],0x10077080
    lea    ebp,[esi+0x10]
    push   0x21
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],eax
    mov    ecx,DWORD PTR [edi+0x8]
    lea    eax,[edi+0x10]
    mov    DWORD PTR [esi+0x8],ecx
    mov    edx,DWORD PTR [edi+0xc]
    push   eax
    push   ebp
    mov    DWORD PTR [esi+0xc],edx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [ebp+0x20]
    add    esp,0xc
    test   al,al
    je     Branch40
    mov    BYTE PTR [ebp+0x20],0x0
  Branch40:
    add    edi,0x31
    add    esi,0x31
    push   0x11
    push   edi
    push   esi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esi+0x10]
    add    esp,0xc
    test   al,al
    pop    edi
    pop    ebp
    mov    eax,ebx
    je     Branch42
    mov    BYTE PTR [esi+0x10],0x0
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  Branch41:
    mov    eax,ebx
  Branch42:
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// MS nonvirtual state/request entries: declaring classes and original prototypes remain unresolved.
// Descriptive raw-entry views retain explicit complete receiver, physical stack words and EAX/AL effects.

// Read current MS singleton93d18; nonnull tail100334c0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET4, no own guard.
// R6GameService.dll @ 10032340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation1(const char *identity)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch43
    jmp    R6GameServiceAddresses::UpdateServiceIdentityAndReplayRecords
  Branch43:
    xor    al,al
    ret    0x4
  }
}

// Read current MS singleton93d18; nonnull tail10033590 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET8, no own guard.
// R6GameService.dll @ 10032360 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation2(uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch44
    jmp    R6GameServiceAddresses::DispatchKind64RecordWhenEnabled
  Branch44:
    xor    al,al
    ret    0x8
  }
}

// Read current MS singleton93d18; nonnull tail100335c0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET8, no own guard.
// R6GameService.dll @ 10032380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation3(uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch45
    jmp    R6GameServiceAddresses::DispatchRecordWhenEnabled
  Branch45:
    xor    al,al
    ret    0x8
  }
}

// Read current MS singleton93d18; nonnull tail100335f0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET28, no own guard.
// R6GameService.dll @ 100323a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall SetSingletonServiceRequest(
    uint word1,uint word2,const char *text17,const char *text33,const char *identity,
    const byte *payload,uint payloadSize)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch46
    jmp    R6GameServiceAddresses::SetServiceClientRequest
  Branch46:
    xor    al,al
    ret    0x1c
  }
}

// Read current MS singleton93d18; nonnull tail100337a0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET8, no own guard.
// R6GameService.dll @ 100323e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ForwardMSClientOperation4(uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch47
    jmp    R6GameServiceAddresses::ForwardProviderOperation3f1f0
  Branch47:
    xor    al,al
    ret    0x8
  }
}

// Read current MS singleton93d18; nonnull tail100337d0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET12, no own guard.
// R6GameService.dll @ 10032440 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchSingletonSubobject3f1a0(char *key,uint word2,uint word3)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch48
    jmp    R6GameServiceAddresses::ForwardProviderOperation3f1a0
  Branch48:
    xor    al,al
    ret    0xc
  }
}

// Read current MS singleton93d18; nonnull tail100337e0 with same stack/full raw EAX.
// NULL clears only AL, retains incoming upper EAX, reads no arguments; RET8, no own guard.
// R6GameService.dll @ 10032460 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchSingletonSubobject3f1b0(uint word1,uint word2)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientSingleton
    test   ecx,ecx
    je     Branch49
    jmp    R6GameServiceAddresses::ForwardProviderOperation3f1b0
  Branch49:
    xor    al,al
    ret    0x8
  }
}

// If117 is zero, send current stored identity via3f120(identity,1,1); zero AL returns raw backend EAX.
// Otherwise normalize117 and AL to1, keeping upper EAX residue; no own guard, receiver/type names inferred.
// R6GameService.dll @ 10033490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TryEnableServiceClient(void *client)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x117]
    test   al,al
    jne    Branch50
    push   0x1
    lea    eax,[esi+0xde]
    push   0x1
    push   eax
    call   R6GameServiceAddresses::PrepareAndSendTransportRequestThroughSubobject
    test   al,al
    jne    Branch50
    pop    esi
    ret
  Branch50:
    mov    BYTE PTR [esi+0x117],0x1
    mov    al,0x1
    pop    esi
    ret
  }
}

// Compare33 identity bytes; on change copy/clamp then actual reset. Capture117 BEFORE setting114=1.
// Inactive: time(NULL)+3 ->100 then enable using fresh117/provider; active/no list returns EAX0 without clock.
// Active/list: replay(node10,nodec,100hex), ignoring result; load current list BEFORE current node successor.
// Compare successor to current head, retain nodes; then time+3 ->100 and force AL1. RET4/no own guard.
// R6GameService.dll @ 100334c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall UpdateServiceIdentityAndReplayRecords(void *client,const char *identity)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    mov    edi,ecx
    push   0x21
    push   ebx
    lea    esi,[edi+0xde]
    push   esi
    call   R6GameServiceAddresses::strncmp
    add    esp,0xc
    test   eax,eax
    je     Branch52
    push   0x21
    push   ebx
    push   esi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esi+0x20]
    add    esp,0xc
    test   al,al
    je     Branch51
    mov    BYTE PTR [esi+0x20],0x0
  Branch51:
    mov    ecx,edi
    call   R6GameServiceAddresses::ResetServiceClientState
  Branch52:
    mov    al,BYTE PTR [edi+0x117]
    mov    BYTE PTR [edi+0x114],0x1
    test   al,al
    je     Branch56
    mov    eax,DWORD PTR [edi+0x110]
    test   eax,eax
    je     Branch55
    mov    eax,DWORD PTR [eax]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je     Branch54
  Branch53:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    push   0x100
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ForwardSelector9ThroughOptionalChannel
    mov    edx,DWORD PTR [edi+0x110]
    mov    esi,DWORD PTR [esi]
    cmp    esi,DWORD PTR [edx]
    jne    Branch53
  Branch54:
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    add    eax,0x3
    mov    DWORD PTR [edi+0x100],eax
    mov    al,0x1
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch55:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x4
  Branch56:
    push   0x0
    call   R6GameServiceAddresses::time
    add    eax,0x3
    add    esp,0x4
    mov    ecx,edi
    mov    DWORD PTR [edi+0x100],eax
    call   R6GameServiceAddresses::TryEnableServiceClient
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

//117 zero clears only AL without reading args; otherwise send(word2,word1,40hex) via current provider3f170.
// Any normal backend result becomes upper EAX|AL1; RET8, no flag store or local cleanup.
// R6GameService.dll @ 10033590 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchKind64RecordWhenEnabled(
    void *client,uint word1,uint word2)
{
  __asm {
    mov    al,BYTE PTR [ecx+0x117]
    test   al,al
    jne    Branch57
    xor    al,al
    ret    0x8
  Branch57:
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   0x40
    push   eax
    push   edx
    call   R6GameServiceAddresses::ForwardSelector9ThroughOptionalChannel
    mov    al,0x1
    ret    0x8
  }
}

//117 zero clears only AL without reading args; otherwise send(word2,word1) via current provider3f180.
// Any normal backend result becomes upper EAX|AL1; RET8, no flag store or local cleanup.
// R6GameService.dll @ 100335c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchRecordWhenEnabled(void *client,uint word1,uint word2)
{
  __asm {
    mov    al,BYTE PTR [ecx+0x117]
    test   al,al
    jne    Branch58
    xor    al,al
    ret    0x8
  Branch58:
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::ForwardSelector2eThroughOptionalChannel
    mov    al,0x1
    ret    0x8
  }
}

// Compare/copy/clamp identity word5; ALWAYS reset before enable. Failed enable returns raw EAX/AL0.
// After enable, free current104, allocate44hex descriptor with late words1/2, text33 word4 and text17 word3.
// Publish104 after copies even if allocation0; free current108, clear108/10c only when108 was nonzero.
// Any nonzero word7 allocates payload; reload10c and late source word6 AFTER allocator, publish108 before REP.
// Zero size may retain stale10c if108 absent. Set116 BEFORE provider3f100(7,0); then force AL1/RET28.
// No own EH/rollback/failed-copy free; final ECX reloads zero-initialized scratch, not incoming receiver.
// R6GameService.dll @ 100335f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetServiceClientRequest(
    void *client,uint word1,uint word2,const char *text17,const char *text33,const char *identity,
    const byte *payload,uint payloadSize)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    push   esi
    mov    ebp,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x28]
    lea    esi,[ebp+0xde]
    push   0x21
    xor    ebx,ebx
    push   edi
    push   esi
    mov    DWORD PTR [esp+0x1c],ebx
    call   R6GameServiceAddresses::strncmp
    add    esp,0xc
    test   eax,eax
    je     Branch59
    push   0x21
    push   edi
    push   esi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch59
    mov    BYTE PTR [esi+0x20],bl
  Branch59:
    mov    ecx,ebp
    call   R6GameServiceAddresses::ResetServiceClientState
    mov    ecx,ebp
    call   R6GameServiceAddresses::TryEnableServiceClient
    test   al,al
    jne    Branch60
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x1c
  Branch60:
    mov    eax,DWORD PTR [ebp+0x104]
    cmp    eax,ebx
    je     Branch61
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch61:
    push   0x44
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    cmp    esi,ebx
    je     Branch63
    mov    edx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    edi,[esi+0x10]
    push   0x21
    push   edx
    push   edi
    mov    DWORD PTR [esi],0x10077080
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ebx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch62
    mov    BYTE PTR [edi+0x20],bl
  Branch62:
    mov    eax,DWORD PTR [esp+0x20]
    lea    edi,[esi+0x31]
    push   0x11
    push   eax
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x10]
    add    esp,0xc
    cmp    al,bl
    je     Branch64
    mov    BYTE PTR [edi+0x10],bl
    jmp    Branch64
  Branch63:
    xor    esi,esi
  Branch64:
    mov    eax,DWORD PTR [ebp+0x108]
    mov    DWORD PTR [ebp+0x104],esi
    cmp    eax,ebx
    je     Branch65
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [ebp+0x108],ebx
    mov    DWORD PTR [ebp+0x10c],ebx
  Branch65:
    mov    eax,DWORD PTR [esp+0x30]
    cmp    eax,ebx
    je     Branch66
    push   eax
    mov    DWORD PTR [ebp+0x10c],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0x10c]
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edx,ecx
    mov    edi,eax
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0x108],eax
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch66:
    push   ebx
    push   0x7
    mov    ecx,ebp
    mov    BYTE PTR [ebp+0x116],0x1
    call   R6GameServiceAddresses::SendBytePairSelector4eViaOffset14
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret    0x1c
  }
}

// Forward(word2,word1) through actual GL3f1f0/current provider41370; RET8/raw full target EAX.
// Original void/member declaration is unproven; raw uint view retains native residue without bool normalization.
// R6GameService.dll @ 100337a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProviderOperation3f1f0(void *client,uint word1,uint word2)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::ForwardSelector22ThroughOptionalChannel
    ret    0x8
  }
}

// Tail GL3f1a0 with all three untouched words/current provider41200; full raw EAX, no own guard.
// R6GameService.dll @ 100337d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProviderOperation3f1a0(
    void *client,char *key,uint word2,uint word3)
{
  __asm {
    jmp    R6GameServiceAddresses::UpdateServiceRecordByKeyViaNestedOffsets
  }
}

// Forward(word2,word1) through actual GL3f1b0/current provider41230; RET8/full raw EAX, no normalization.
// R6GameService.dll @ 100337e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardProviderOperation3f1b0(void *client,uint word1,uint word2)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x8]
    push   eax
    push   edx
    call   R6GameServiceAddresses::BuildAndDispatchStoredRequestViaNestedOffsets
    ret    0x8
  }
}
