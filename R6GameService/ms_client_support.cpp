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

// Invoke slot+24 on the captured singleton if present, then clear the current global slot and report success.
// Native AL1 is the consumed result: callers either discard EAX or zero-extend AL before returning.
// R6GameService.dll @ 10032300 : inferred bool cdecl RET0; a throwing close prevents the global clear.
bool __cdecl CloseMSClientSingleton(void)
{
  void *client = *(void **)R6GameServiceAddresses::GMSClientSingleton;
  if (client != nullptr) {
    uint table = *(uint *)client;
    using CloseABI = void (__thiscall *)(void *,uint);
    (*(CloseABI *)(table + 0x24))(client,1);
  }
  *(void **)R6GameServiceAddresses::GMSClientSingleton = nullptr;
  return true;
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
// R6GameService.dll @ 10033730 : C++ request matching, callback/current-record cleanup and raw AL result.
__declspec(naked) uint __thiscall CompleteStoredRequestIfMatched(void *client,uint firstWord,uint secondWord)
{
  byte *nativeFrame;
  byte *receiver;
  __asm {
    push   esi
    mov    esi,ecx
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  uint request = *(uint *)(receiver + 0x104);
  uint output = request & 0xffffff00;
  if (request != 0) {
    uint first = *(uint *)(nativeFrame + 8);
    uint storedFirst = *(uint *)(request + 4);
    if (storedFirst == first) {
      uint storedSecond = *(uint *)(request + 8);
      __asm {
        push   edi
      }
      uint second = *(uint *)(nativeFrame + 0xc);
      bool matched = storedSecond == second;
      __asm {
        pop    edi
      }
      if (matched) {
        *(byte *)(receiver + 0x115) = 0;
        uint payload = *(uint *)(request + 0xc);
        using PayloadABI = uint (__thiscall *)(void *,uint,uint);
        using FreeABI = uint (__stdcall *)(void *);
        using SendABI = uint (__fastcall *)(void *);
        ((PayloadABI)R6GameServiceAddresses::ForwardTwoArgumentBooleanViaNestedOffsets)(receiver,payload,first);
        void *current = *(void **)(receiver + 0x104);
        if (current != nullptr)
          ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(current);
        *(uint *)(receiver + 0x104) = 0;
        uint sent = ((SendABI)R6GameServiceAddresses::SendSelector5cViaNestedOffsets)(receiver);
        output = (sent & 0xffffff00) | 1;
      }
    }
  }
  __asm {
    mov    eax,output
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
uint __thiscall ReleaseServiceClientResources(void *client)
{
  uint base = (uint)client;
  using FreeABI = uint (__stdcall *)(void *);
  void *record = *(void **)(base + 0x104);
  if (record != 0) {
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(record);
    *(uint *)(base + 0x104) = 0;
  }
  void *payload = *(void **)(base + 0x108);
  if (payload != 0) {
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(payload);
    *(uint *)(base + 0x108) = 0;
    *(uint *)(base + 0x10c) = 0;
  }
  void *list = *(void **)(base + 0x110);
  if (list != 0) {
    using ReleaseABI = uint (__thiscall *)(void *);
    ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(list);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(list);
    *(uint *)(base + 0x110) = 0;
  }
  using MethodABI = uint (__thiscall *)(void *);
  uint resetResult = ((MethodABI)R6GameServiceAddresses::ResetServiceClientState)(client);
  uint result = DisconnectPrimaryConnectionViaOffset14(client,resetResult);
  return (result & 0xffffff00) | 1;
}

// Process current provider records, capture110, clear flags117/115/116/114 and deadline100, then free110/104.
// Captured list storage survives callbacks;104 reloads afterward.108/10c are untouched by this helper.
// Absent104 returns1; otherwise AL1 keeps the final free result upper bits. No own guard or rollback.
// R6GameService.dll @ 10033420 : inferred raw field/ABI views; callback-time accesses and partial effects retained.
uint __thiscall ResetServiceClientState(void *client)
{
  uint base = (uint)client;
  using ProcessABI = uint (__thiscall *)(void *);
  ((ProcessABI)R6GameServiceAddresses::ProcessTransportRecordsViaNestedOffsets)(client);
  void *list = *(void **)(base + 0x110);
  *(byte *)(base + 0x117) = 0;
  *(byte *)(base + 0x115) = 0;
  *(byte *)(base + 0x116) = 0;
  *(byte *)(base + 0x114) = 0;
  *(uint *)(base + 0x100) = 0;
  using FreeABI = uint (__stdcall *)(void *);
  if (list != 0) {
    using ReleaseABI = uint (__thiscall *)(void *);
    ((ReleaseABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(list);
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(list);
    *(uint *)(base + 0x110) = 0;
  }
  void *record = *(void **)(base + 0x104);
  uint result = 0;
  if (record != 0) {
    result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(record);
    *(uint *)(base + 0x104) = 0;
  }
  return (result & 0xffffff00) | 1;
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
// Return views distinguish consumed AL from full raw words; native receivers/stack words remain explicit.

// Forward identity replay through the captured MS singleton; absent singleton reads no identity argument.
// The ordinary caller discards EAX. This byte view preserves AL without assigning meaning to native upper residue.
// R6GameService.dll @ 10032340 : inferred AL stdcall RET4 view; no local ownership or guard.
byte __stdcall ForwardMSClientOperation1(const char *identity)
{
  void *client = *(void **)R6GameServiceAddresses::GMSClientSingleton;
  if (client == nullptr) return 0;
  using ReplayABI = byte (__thiscall *)(void *,const char *);
  return (byte)((ReplayABI)R6GameServiceAddresses::UpdateServiceIdentityAndReplayRecords)(client,identity);
}

// Forward the two words through the captured MS singleton, or return AL0 before reading either word.
// Native tail transfer shares the argument words; the inner active gate precedes both reads. Caller discards EAX.
// R6GameService.dll @ 10032360 : inferred AL stdcall RET8 view, no local guard.
byte __stdcall ForwardMSClientOperation2(uint word1,uint word2)
{
  void *client = *(void **)R6GameServiceAddresses::GMSClientSingleton;
  if (client == nullptr) return 0;
  using DispatchABI = byte (__thiscall *)(void *,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchKind64RecordWhenEnabled)(client,word1,word2);
}

// Forward alternate-info words through the captured singleton, or return AL0 before reading them when absent.
// Native tail transfer shares both words and the inner gate precedes reads; the script-facing void caller discards EAX.
// R6GameService.dll @ 10032380 : inferred AL stdcall RET8 view, no local guard.
byte __stdcall ForwardMSClientOperation3(uint word1,uint word2)
{
  void *client = *(void **)R6GameServiceAddresses::GMSClientSingleton;
  if (client == nullptr) return 0;
  using DispatchABI = byte (__thiscall *)(void *,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchRecordWhenEnabled)(client,word1,word2);
}

// Forward request setup through the captured singleton, or return AL0 without reading the seven arguments.
// Native tail transfer reuses the caller's seven words; request callbacks still observe the target's late formal reads.
// R6GameService.dll @ 100323a0 : inferred AL stdcall RET28 view; caller zero-extends AL and discards upper EAX.
byte __stdcall SetSingletonServiceRequest(
    uint word1,uint word2,const char *text17,const char *text33,const char *identity,
    const byte *payload,uint payloadSize)
{
  void *client = *(void **)R6GameServiceAddresses::GMSClientSingleton;
  if (client == nullptr) return 0;
  using RequestABI = byte (__thiscall *)(void *,uint,uint,const char *,const char *,const char *,const byte *,uint);
  return (byte)((RequestABI)R6GameServiceAddresses::SetServiceClientRequest)(
      client,word1,word2,text17,text33,identity,payload,payloadSize);
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

// Send stored identity only while117 is zero; a zero sender byte leaves the callback's flag changes untouched.
// Accepted or previously enabled state normalizes117 and AL to1. The two caller routes consume only AL.
// R6GameService.dll @ 10033490 : inferred AL thiscall RET0 view; no local ownership or rollback.
byte __thiscall TryEnableServiceClient(void *client)
{
  uint base = (uint)client;
  byte enabled = *(byte *)(base + 0x117);
  if (enabled == 0) {
    char *identity = (char *)(base + 0xde);
    using PrepareABI = byte (__thiscall *)(void *,char *,uint,uint);
    byte sent = ((PrepareABI)R6GameServiceAddresses::PrepareAndSendTransportRequestThroughSubobject)(
        client,identity,1,1);
    if (sent == 0) return 0;
  }
  *(byte *)(base + 0x117) = 1;
  return 1;
}

// Compare33 identity bytes; on change copy/clamp then actual reset. Capture117 BEFORE setting114=1.
// Inactive: time(NULL)+3 ->100 then enable using fresh117/provider; active/no list returns EAX0 without clock.
// Active/list: replay(node10,nodec,100hex), ignoring result; load current list BEFORE current node successor.
// Compare successor to current head, retain nodes; then time+3 ->100 and force AL1. RET4/no own guard.
// R6GameService.dll @ 100334c0 : inferred AL view; only the singleton wrapper consumes the result byte.
byte __thiscall UpdateServiceIdentityAndReplayRecords(void *client,const char *identity)
{
  const char *incomingIdentity = identity;
  uint base = (uint)client;
  char *storedIdentity = (char *)(base + 0xde);
  using CompareABI = int (__cdecl *)(const char *,const char *,uint);
  using CopyABI = char * (__cdecl *)(char *,const char *,uint);
  using MethodABI = uint (__thiscall *)(void *);
  int different = ((CompareABI)R6GameServiceAddresses::strncmp)(storedIdentity,incomingIdentity,33);
  if (different != 0) {
    ((CopyABI)R6GameServiceAddresses::strncpy)(storedIdentity,incomingIdentity,33);
    if (storedIdentity[32] != 0) storedIdentity[32] = 0;
    ((MethodABI)R6GameServiceAddresses::ResetServiceClientState)(client);
  }
  byte active = *(byte *)(base + 0x117);
  *(byte *)(base + 0x114) = 1;
  using TimeABI = uint (__cdecl *)(void *);
  if (active == 0) {
    uint now = ((TimeABI)R6GameServiceAddresses::time)(nullptr);
    uint deadline = now + 3;
    *(uint *)(base + 0x100) = deadline;
    using EnableABI = byte (__thiscall *)(void *);
    return ((EnableABI)R6GameServiceAddresses::TryEnableServiceClient)(client);
  }
  uint list = *(uint *)(base + 0x110);
  if (list == 0) return 0;
  uint head = *(uint *)list;
  uint node = *(uint *)head;
  using ReplayABI = uint (__thiscall *)(void *,uint,uint,uint);
  while (node != head) {
    uint second = *(uint *)(node + 0xc);
    uint first = *(uint *)(node + 0x10);
    ((ReplayABI)R6GameServiceAddresses::ForwardSelector9ThroughOptionalChannel)(client,first,second,0x100);
    list = *(uint *)(base + 0x110);
    node = *(uint *)node;
    head = *(uint *)list;
  }
  uint now = ((TimeABI)R6GameServiceAddresses::time)(nullptr);
  uint deadline = now + 3;
  *(uint *)(base + 0x100) = deadline;
  return 1;
}

// When117 is nonzero send reversed whole words with selector40, then report AL1 regardless of backend status.
// Disabled117 returns AL0 without reading either argument; backend exceptions skip the success return.
// R6GameService.dll @ 10033590 : inferred AL thiscall RET8 view; upper EAX is unconsumed by the ordinary route.
byte __thiscall DispatchKind64RecordWhenEnabled(void *client,uint word1,uint word2)
{
  byte enabled = *(byte *)((uint)client + 0x117);
  if (enabled == 0) return 0;
  uint first = word1;
  uint second = word2;
  using SendABI = uint (__thiscall *)(void *,uint,uint,uint);
  ((SendABI)R6GameServiceAddresses::ForwardSelector9ThroughOptionalChannel)(client,second,first,0x40);
  return 1;
}

// When117 is nonzero send reversed whole words, then report AL1 regardless of backend status; disabled reads no args.
// The singleton route discards upper EAX; partial backend effects survive a throw, with no local cleanup.
// R6GameService.dll @ 100335c0 : inferred AL thiscall RET8 view, no flag publication or local ownership.
byte __thiscall DispatchRecordWhenEnabled(void *client,uint word1,uint word2)
{
  byte enabled = *(byte *)((uint)client + 0x117);
  if (enabled == 0) return 0;
  uint first = word1;
  uint second = word2;
  using SendABI = uint (__thiscall *)(void *,uint,uint);
  ((SendABI)R6GameServiceAddresses::ForwardSelector2eThroughOptionalChannel)(client,second,first);
  return 1;
}

namespace {
// Inferred forward DWORD/tail view of the native request-payload copy; count and source are cached before publication.
inline void CopyServiceRequestPayloadForward(uint destination,uint source,uint count) {
  uint words = count >> 2;
  while (words != 0) {
    uint value = *(const uint *)source;
    *(uint *)destination = value;
    source += 4;
    destination += 4;
    --words;
  }
  uint tail = count & 3;
  while (tail != 0) {
    byte value = *(const byte *)source;
    *(byte *)destination = value;
    ++source;
    ++destination;
    --tail;
  }
}
}

// Compare/copy/clamp identity word5; ALWAYS reset before enable. Failed enable returns AL0.
// After enable, free current104, allocate44hex descriptor with late words1/2, text33 word4 and text17 word3.
// Publish104 after copies even if allocation0; free current108, clear108/10c only when108 was nonzero.
// Any nonzero word7 allocates payload; reload10c and late source word6 AFTER allocator, publish108 before REP.
// Zero size may retain stale10c if108 absent. Set116 BEFORE provider3f100(7,0); then force AL1/RET28.
// No own EH/rollback/failed-copy free; final ECX reloads zero-initialized scratch, not incoming receiver.
// R6GameService.dll @ 100335f0 : inferred AL view; native upper residue is discarded by the outer caller.
byte __thiscall SetServiceClientRequest(
    void *client,uint word1,uint word2,const char *text17,const char *text33,const char *identity,
    const byte *payload,uint payloadSize)
{
  uint base = (uint)client;
  const char *incomingIdentity = identity;
  char *storedIdentity = (char *)(base + 0xde);
  using CompareABI = int (__cdecl *)(const char *,const char *,uint);
  using CopyABI = char * (__cdecl *)(char *,const char *,uint);
  using MethodABI = uint (__thiscall *)(void *);
  int different = ((CompareABI)R6GameServiceAddresses::strncmp)(storedIdentity,incomingIdentity,33);
  if (different != 0) {
    ((CopyABI)R6GameServiceAddresses::strncpy)(storedIdentity,incomingIdentity,33);
    if (storedIdentity[32] != 0) storedIdentity[32] = 0;
  }
  ((MethodABI)R6GameServiceAddresses::ResetServiceClientState)(client);
  using EnableABI = byte (__thiscall *)(void *);
  byte enabled = ((EnableABI)R6GameServiceAddresses::TryEnableServiceClient)(client);
  if (enabled == 0) return 0;
  using FreeABI = uint (__stdcall *)(void *);
  void *oldRecord = *(void **)(base + 0x104);
  if (oldRecord != 0) ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(oldRecord);
  using AllocateABI = uint (__stdcall *)(uint);
  uint record = ((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(0x44);
  if (record != 0) {
    const char *source33 = text33;
    uint first = word1;
    uint second = word2;
    char *destination33 = (char *)(record + 0x10);
    *(uint *)record = 0x10077080;
    *(uint *)(record + 4) = first;
    *(uint *)(record + 8) = second;
    *(uint *)(record + 0xc) = 0;
    ((CopyABI)R6GameServiceAddresses::strncpy)(destination33,source33,33);
    if (destination33[32] != 0) destination33[32] = 0;
    const char *source17 = text17;
    char *destination17 = (char *)(record + 0x31);
    ((CopyABI)R6GameServiceAddresses::strncpy)(destination17,source17,17);
    if (destination17[16] != 0) destination17[16] = 0;
  }
  void *oldPayload = *(void **)(base + 0x108);
  *(uint *)(base + 0x104) = record;
  if (oldPayload != 0) {
    ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(oldPayload);
    *(uint *)(base + 0x108) = 0;
    *(uint *)(base + 0x10c) = 0;
  }
  uint requested = payloadSize;
  if (requested != 0) {
    *(uint *)(base + 0x10c) = requested;
    uint allocation = ((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(requested);
    uint count = *(uint *)(base + 0x10c);
    uint first = (uint)payload;
    *(uint *)(base + 0x108) = allocation;
    CopyServiceRequestPayloadForward(allocation,first,count);
  }
  *(byte *)(base + 0x116) = 1;
  using SendABI = byte (__thiscall *)(void *,uint,uint);
  ((SendABI)R6GameServiceAddresses::SendBytePairSelector4eViaOffset14)(client,7,0);
  return 1;
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
