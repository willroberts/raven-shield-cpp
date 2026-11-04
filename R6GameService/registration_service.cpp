#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1008036c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo LoginRequestExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 100803d0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo D9RequestExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1008047c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RegistrationD5ExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 100804a0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RegistrationRecordReplyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080508 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo LobbyLoginExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1008058c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo OptionalRegistrationExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080624 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RegistrationMatchExceptionHandlerFunctionInfo;

// Singleton slot used by the registration-service API; constructor2f460 identifies CRegisterServerCB.
// R6GameService.dll data @ 10093d14 : native storage identity retained.
extern void *GRegistrationServiceSingleton;

// Allocates and constructs the singleton once; AL remains 1 even when allocation returns null.
// R6GameService.dll @ 1002f220 : cdecl, no arguments, RET; returns pointer-derived upper EAX residue.
uint __cdecl InitializeRegistrationServiceSingleton(void)
{
  void *service = GRegistrationServiceSingleton;
  if (service == nullptr) {
    void *memory = (void *)AllocateGameServiceBytes(0x178);
    service = memory == nullptr ? nullptr : ConstructRegistrationService(memory,1);
    GRegistrationServiceSingleton = service;
  }
  return ((uint)service & 0xffffff00) | 1;
}

// Delete the captured registration singleton if present, clear the current global slot, then report success.
// The sole selected-image caller discards upper EAX immediately; the native return width is AL.
// R6GameService.dll @ 1002f260 : inferred bool result; cdecl RET0, no owned-local guard.
bool __cdecl UninitializeRegistrationService(void)
{
  void *service = GRegistrationServiceSingleton;
  if (service != nullptr) {
    uint table = *(uint *)service;
    using DeleteABI = void (__thiscall *)(void *,uint);
    (*(DeleteABI *)table)(service,1);
  }
  GRegistrationServiceSingleton = nullptr;
  return true;
}

// Pumps registration-service callbacks through the singleton.
// R6GameService.dll @ 1002f280 : native singleton tail adapter to 0x1002f960; no added null guard.
__declspec(naked) void __cdecl ProcessRegistrationServiceCallbacks(void)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::PumpRegistrationMessages
  }
}

// Forwards endpoint connection after zero-extending the port word in its argument slot.
// R6GameService.dll @ 1002f290 : native singleton tail adapter to 0x1002f870; no added null guard.
__declspec(naked) uint __stdcall ConnectRegistrationEndpoint(const char *address,uint port)
{
  __asm {
    mov eax,dword ptr [esp+8]
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    and eax,0xffff
    mov dword ptr [esp+8],eax
    jmp R6GameServiceAddresses::registration_service_ConnectRegistrationEndpoint
  }
}

// Forwards the router-disconnect request through the singleton.
// R6GameService.dll @ 1002f2b0 : native singleton tail adapter to 0x1002fb00; no added null guard.
__declspec(naked) uint __cdecl SendRouterDisconnect(void)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendRouterDisconnectIfAvailable
  }
}

// Forwards the three login text arguments through the singleton.
// R6GameService.dll @ 1002f2c0 : native singleton tail adapter to 0x1002fb20; no added null guard.
__declspec(naked) uint __stdcall SendRouterLogin(char *text0,char *text1,char *text2)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendRouterLoginRequest
  }
}

// Forwards the parent-group request text through the singleton.
// R6GameService.dll @ 1002f2d0 : native singleton tail adapter to 0x1002fca0; no added null guard.
__declspec(naked) uint __stdcall RequestParentGroupOnLobby(char *request)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendOpcodeD9TextRequest
  }
}

// Forwards all nineteen registration stack words without narrowing the reloaded fields.
// R6GameService.dll @ 1002f2e0 : native singleton tail adapter to 0x1002fde0; no added null guard.
__declspec(naked) uint __stdcall RegisterServerOnLobby(int option0,int option1,char *text0,char *text1,uint value0,
    uint value1,uint value2,char *text2,byte *bytes0,uint byteCount0,byte *bytes1,uint byteCount1,
    byte *bytes2,uint byteCount2,uint value3,char *text3,char *text4,uint byteValue0Word,uint byteValue1Word)
{
  __asm {
    mov ecx,dword ptr [esp+0x48]
    mov eax,dword ptr [esp+0x4c]
    mov edx,dword ptr [esp+0x14]
    mov dword ptr [esp+0x48],ecx
    mov ecx,dword ptr [esp+0x3c]
    mov dword ptr [esp+0x4c],eax
    mov dword ptr [esp+0x3c],ecx
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    mov dword ptr [esp+0x14],edx
    jmp R6GameServiceAddresses::SendServerRegistrationOpcodeD5
  }
}

// Forwards the match-start word through the singleton.
// R6GameService.dll @ 1002f310 : native singleton tail adapter to 0x10030e50; no added null guard.
__declspec(naked) uint __stdcall SendMatchStart(int matchId)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendRegistrationMatchStart
  }
}

// Forwards the match-finish request through the singleton.
// R6GameService.dll @ 1002f320 : native singleton tail adapter to 0x10030fe0; no added null guard.
__declspec(naked) uint __cdecl SendMatchFinish(void)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendRegistrationMatchFinish
  }
}

// Tail-forwards original callback word to singleton slot+134; no singleton null guard.
// R6GameService.dll @ 1002f330 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall SetRegistrationCallback(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x134
  }
}

// Tail-forwards original callback word to singleton slot+138; no singleton null guard.
// R6GameService.dll @ 1002f340 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x138
  }
}

// Tail-forwards original callback word to singleton slot+13c; no singleton null guard.
// R6GameService.dll @ 1002f350 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback2(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x13c
  }
}

// Tail-forwards original callback word to singleton slot+140; no singleton null guard.
// R6GameService.dll @ 1002f360 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback3(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x140
  }
}

// Tail-forwards original callback word to singleton slot+144; no singleton null guard.
// R6GameService.dll @ 1002f370 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback4(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x144
  }
}

// Tail-forwards original callback word to singleton slot+148; no singleton null guard.
// R6GameService.dll @ 1002f380 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback5(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x148
  }
}

// Tail-forwards original callback word to singleton slot+14c; no singleton null guard.
// R6GameService.dll @ 1002f390 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback6(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x14c
  }
}

// Forwards five lobby-connection words, retaining both complete port argument slots.
// R6GameService.dll @ 1002f3a0 : native singleton tail adapter to 0x100307e0; no added null guard.
__declspec(naked) uint __stdcall ConnectToLobbyServer
    (void *connectionValue,uint localPort,uint serverPort,uint option0,uint option1)
{
  __asm {
    mov edx,dword ptr [esp+0xc]
    mov eax,dword ptr [esp+8]
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    mov dword ptr [esp+0xc],edx
    mov dword ptr [esp+8],eax
    jmp R6GameServiceAddresses::ConnectLobbyServerTransport
  }
}

// Close through the captured registration singleton without adding a singleton null guard.
// The selected outer caller immediately discards EAX; byte is an inferred AL view, not a recovered declaration.
// R6GameService.dll @ 1002f3c0 : cdecl RET0; native tail receiver adjustment, no argument or result normalization.
byte __cdecl CloseLobbyServerConnection(void)
{
  void *service = GRegistrationServiceSingleton;
  using CloseABI = byte (__fastcall *)(void *);
  return ((CloseABI)R6GameServiceAddresses::CloseLobbyServerTransport)(service);
}

// Forwards the lobby-login text and value through the singleton.
// R6GameService.dll @ 1002f3d0 : native singleton tail adapter to 0x100308e0; no added null guard.
__declspec(naked) uint __stdcall SendLobbyServerLogin(char *loginText,uint loginValue)
{
  __asm {
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    jmp R6GameServiceAddresses::SendLobbyServerLoginRequest
  }
}

// Forwards all fourteen update stack words without modifying the reloaded values.
// R6GameService.dll @ 1002f3e0 : native singleton tail adapter to 0x10030a10; no added null guard.
__declspec(naked) uint __stdcall SendOptionalFieldsThroughSecondaryService
    (uint groupId,uint option0Word,uint option1Word,uint option2Word,
    int value0,int value1,char *text,byte *bytes0,int length0,byte *bytes1,int length1,byte *bytes2,
    int length2,uint lowWordValue)
{
  __asm {
    mov eax,dword ptr [esp+0x38]
    mov ecx,dword ptr [esp+0x10]
    mov edx,dword ptr [esp+0xc]
    mov dword ptr [esp+0x38],eax
    mov eax,dword ptr [esp+8]
    mov dword ptr [esp+0x10],ecx
    mov ecx,dword ptr ds:[R6GameServiceAddresses::GRegistrationServiceSingleton]
    mov dword ptr [esp+0xc],edx
    mov dword ptr [esp+8],eax
    jmp R6GameServiceAddresses::SendOptionalRegistrationFields
  }
}

// Tail-forwards original callback word to singleton slot+150; no singleton null guard.
// R6GameService.dll @ 1002f410 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback7(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x150
  }
}

// Tail-forwards original callback word to singleton slot+158; no singleton null guard.
// R6GameService.dll @ 1002f420 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback8(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x158
  }
}

// Tail-forwards original callback word to singleton slot+15c; no singleton null guard.
// R6GameService.dll @ 1002f430 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __stdcall registration_service_SetRegistrationCallback9(void *callback)
{
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GRegistrationServiceSingleton
    jmp    R6GameServiceAddresses::StoreCallbackAtOffset_0x15c
  }
}

// Stores callback word at receiver+13c and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f6f0 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x13c(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x13c) = callback;
  return callback;
}

// Stores callback word at receiver+140 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f700 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x140(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x140) = callback;
  return callback;
}

// Stores callback word at receiver+14c and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f710 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x14c(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x14c) = callback;
  return callback;
}

// Stores callback word at receiver+150 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f720 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x150(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x150) = callback;
  return callback;
}

// Stores callback word at receiver+158 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f730 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x158(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x158) = callback;
  return callback;
}

// Stores callback word at receiver+15c and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 1002f740 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x15c(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x15c) = callback;
  return callback;
}

// Performs no callback work and removes 7 argument words, preserving native registers and flags.
// R6GameService.dll @ 1002f440 : private callback entry, RET 0x1c; argument meanings are unresolved.
__declspec(naked) void __stdcall NoOpRegistrationCallbackRet1C
    (uint argumentWord0,uint argumentWord1,uint argumentWord2,uint argumentWord3,uint argumentWord4,
    uint argumentWord5,uint argumentWord6)
{
  __asm {
    ret 0x1c
  }
}

// Performs no callback work and removes 21 argument words, preserving native registers and flags.
// R6GameService.dll @ 1002f450 : private callback entry, RET 0x54; argument meanings are unresolved.
__declspec(naked) void __stdcall NoOpRegistrationCallbackRet54
    (uint argumentWord0,uint argumentWord1,uint argumentWord2,uint argumentWord3,uint argumentWord4,
    uint argumentWord5,uint argumentWord6,uint argumentWord7,uint argumentWord8,uint argumentWord9,
    uint argumentWord10,uint argumentWord11,uint argumentWord12,uint argumentWord13,uint argumentWord14,
    uint argumentWord15,uint argumentWord16,uint argumentWord17,uint argumentWord18,uint argumentWord19,
    uint argumentWord20)
{
  __asm {
    ret 0x54
  }
}

// Dispatches queued 0x26/0x27 replies, retaining the opcode byte when indexed decoding fails.
// R6GameService.dll @ 1002f960 : RET0; initial ECX word is persistent opcode scratch and is popped into ECX on exit.
__declspec(naked) uint __fastcall PumpRegistrationMessages(void *service)
{
  byte *nativeFrame;
  void *receiver;
  __asm {
    push   ecx
    push   esi
    push   edi
    mov    edi,ecx
    mov    nativeFrame,esp
    mov    receiver,edi
  }
  uint rawEax = ((uint (__thiscall *)(void *))R6GameServiceAddresses::UpdateRegistrationState)(receiver);
  byte active = *((byte *)receiver + 0x9b);
  rawEax = (rawEax & 0xffffff00) | active;
  if (active != 0) {
    using TakeABI = void * (__thiscall *)(void *);
    void *transport = *(void **)((byte *)receiver + 0x120);
    void *message = ((TakeABI)R6GameServiceAddresses::TakeNextTransportMessage)(transport);
    while (message != nullptr) {
      byte category = *((byte *)message + 4);
      uint decodedEcx,decodedEdx;
      if (category >= 0x26 && category <= 0x27) {
        void *payload = *(void **)((byte *)message + 8);
        // Failed decoding leaves the previous opcode byte, initially the low byte of the service pointer.
        __asm {
          mov    ecx,payload
          push   0
          lea    eax,[esp+0xc]
          push   1
          push   eax
          call   R6GameServiceAddresses::CopyIndexedBytesExact
          mov    decodedEcx,ecx
          mov    decodedEdx,edx
        }
      } else *(byte *)(nativeFrame + 8) = 0;
      uint opcode = *(uint *)(nativeFrame + 8) & 0xff;
      using DispatchABI = uint (__thiscall *)(void *,uint,void *);
      if (opcode == 0x66) {
        uint replyWord = *((byte *)message + 4);
        void *payload = *(void **)((byte *)message + 8);
        ((DispatchABI)R6GameServiceAddresses::DispatchParsedOpcode26Or27)(receiver,replyWord,payload);
      } else if (opcode == 0xd5) {
        uint replyWord = (decodedEcx & 0xffff0000) | *((byte *)message + 4);
        void *payload = *(void **)((byte *)message + 8);
        ((DispatchABI)R6GameServiceAddresses::DispatchParsedOpcode26Or27Strings)(receiver,replyWord,payload);
      } else if (opcode == 0xd9) {
        uint replyWord = (decodedEdx & 0xffff0000) | *((byte *)message + 4);
        void *payload = *(void **)((byte *)message + 8);
        ((DispatchABI)R6GameServiceAddresses::DispatchParsedOpcode26Or27RecordList)(receiver,replyWord,payload);
      }
      ((void (__thiscall *)(void *))R6GameServiceAddresses::DeleteOwnedObjectAtOffset8)(message);
      ((void (__stdcall *)(void *))R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(message);
      transport = *(void **)((byte *)receiver + 0x120);
      message = ((TakeABI)R6GameServiceAddresses::TakeNextTransportMessage)(transport);
    }
    rawEax = 0;
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    pop    ecx
    ret
  }
}

// Checks active providers in order and tail-dispatches secondary failure after clearing that provider.
// R6GameService.dll @ 1002fa30 : RET0; primary callbacks can change the secondary state inspected afterward.
__declspec(naked) uint __thiscall UpdateRegistrationState(void *service)
{
  void *receiver;
  uint rawEax;
  __asm {
    push   esi
    mov    esi,ecx
    mov    receiver,esi
    mov    rawEax,eax
  }
  byte active = *((byte *)receiver + 0x9b);
  rawEax = (rawEax & 0xffffff00) | active;
  if (active != 0) {
    void *transport = *(void **)((byte *)receiver + 0x120);
    rawEax = ((uint (__thiscall *)(void *))R6GameServiceAddresses::IsTransportConnected)(transport);
    if ((byte)rawEax == 0)
      rawEax = ((uint (__thiscall *)(void *))R6GameServiceAddresses::DropRegistrationTransport)(receiver);
  }
  byte secondaryActive = *((byte *)receiver + 0x9a);
  rawEax = (rawEax & 0xffffff00) | secondaryActive;
  if (secondaryActive != 0) {
    rawEax = ((uint (__thiscall *)(void *))R6GameServiceAddresses::PollSecondaryRegistrationService)(receiver);
    if ((byte)rawEax == 0) {
      ((uint (__thiscall *)(void *))R6GameServiceAddresses::ClearSecondaryServiceState)(receiver);
      byte *table = *(byte **)receiver;
      __asm {
        mov    eax,table
        mov    ecx,receiver
        pop    esi
        jmp    DWORD PTR [eax+0x1c]
      }
    }
  }
  __asm {
    mov    eax,rawEax
    pop    esi
    ret
  }
}

// Destroys and frees the transport, clears its fields, then tail-calls the owner even when transport was absent.
// R6GameService.dll @ 1002fa80 : RET0 tail callback; current table is captured before clearing provider fields.
__declspec(naked) uint __fastcall DropRegistrationTransport(void *service)
{
  void *receiver,*transport;
  __asm {
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esi+0x120]
    mov    receiver,esi
    mov    transport,edi
  }
  if (transport != nullptr) {
    ((void (__thiscall *)(void *))R6GameServiceAddresses::CConnectionDestroyProvider)(transport);
    ((void (__stdcall *)(void *))R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(transport);
  }
  byte *table = *(byte **)receiver;
  *(uint *)((byte *)receiver + 0x120) = 0;
  *((byte *)receiver + 0x9b) = 0;
  __asm {
    mov    eax,table
    mov    ecx,esi
    pop    edi
    pop    esi
    jmp    DWORD PTR [eax+8]
  }
}

// Deletes the secondary provider through its first virtual slot, then clears its state fields.
// R6GameService.dll @ 1002fac0 : RET0; secondary state fields are cleared only after the provider destructor returns.
__declspec(naked) uint __thiscall ClearSecondaryServiceState(void *service)
{
  void *receiver;
  uint rawEax;
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ebx,ebx
    mov    receiver,esi
    mov    rawEax,eax
  }
  void *provider = *(void **)((byte *)receiver + 0x124);
  if (provider != nullptr) {
    byte *table = *(byte **)provider;
    using DeleteABI = uint (__thiscall *)(void *,uint);
    rawEax = (*(DeleteABI *)table)(provider,1);
  }
  *(uint *)((byte *)receiver + 0x124) = 0;
  *(uint *)((byte *)receiver + 0x128) = 0;
  *(uint *)((byte *)receiver + 0x12c) = 0;
  *((byte *)receiver + 0x9a) = 0;
  __asm {
    mov    eax,rawEax
    pop    esi
    pop    ebx
    ret
  }
}

// Tail-forwards disconnect through the transport, or clears only AL when no transport exists.
// R6GameService.dll @ 1002fb00 : ECX service, RET; returns raw EAX including incoming upper bits on absence.
__declspec(naked) uint __fastcall SendRouterDisconnectIfAvailable(void *service)
{
  __asm {
    mov ecx,dword ptr [ecx+0x120]
    test ecx,ecx
    jnz registration_disconnect_forward
    xor al,al
    ret
  registration_disconnect_forward:
    jmp R6GameServiceAddresses::CConnectionCloseProvider
  }
}

// Opens the cached or newly allocated registration transport and returns its current status byte in raw EAX.
// R6GameService.dll @ 1002f870 : ECX service, RET 8; explicit SEH frame and raw EAX return.
__declspec(naked) uint __thiscall registration_service_ConnectRegistrationEndpoint(void *service,const char *address,uint port)
{
  __asm {
    // ESI retains the service; [ESP+4] is the pending allocation while unwind state is 0.
    push   0xffffffff
    push   R6GameServiceAddresses::SharedRegistrationAllocationExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    dword ptr fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    ecx,dword ptr [esi+0x120]
    test   ecx,ecx
    je registration_connect_allocate
    mov    eax,dword ptr [esp+0x1c]
    mov    edx,dword ptr [esp+0x18]
    push   0x0
    push   0x0
    push   0x0
    push   0x1
    push   eax
    push   edx
    // ConnectAddressTransport: address, port, 1, 0, 0, 0.
    call   R6GameServiceAddresses::ConnectAddressTransport
    test   al,al
    mov    byte ptr [esi+0x9b],al
    je registration_connect_return
    mov    eax,dword ptr [esi+0x120]
    mov    ecx,dword ptr [eax+0x4]
    // WaitForTransportReady on the live provider.
    call   R6GameServiceAddresses::WaitForTransportReady
    jmp registration_connect_return
  registration_connect_allocate:
    push   0x98
    // Allocate native storage.
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    dword ptr [esp+0x4],eax
    test   eax,eax
    mov    dword ptr [esp+0x10],0x0
    je registration_connect_allocation_failed
    push   0x1
    mov    ecx,eax
    // InitializeTransportState with flag 1.
    call   R6GameServiceAddresses::InitializeTransportState
    jmp registration_connect_publish
  registration_connect_allocation_failed:
    xor    eax,eax
  registration_connect_publish:
    mov    ecx,dword ptr [esp+0x1c]
    mov    edx,dword ptr [esp+0x18]
    push   0x0
    push   0x0
    push   0x0
    push   0x1
    push   ecx
    push   edx
    mov    ecx,eax
    mov    dword ptr [esp+0x28],0xffffffff
    mov    dword ptr [esi+0x120],eax
    // ConnectAddressTransport: address, port, 1, 0, 0, 0.
    call   R6GameServiceAddresses::ConnectAddressTransport
    test   al,al
    mov    byte ptr [esi+0x9b],al
    je registration_connect_recheck
    mov    eax,dword ptr [esi+0x120]
    mov    ecx,dword ptr [eax+0x4]
    // WaitForTransportReady on the live provider.
    call   R6GameServiceAddresses::WaitForTransportReady
  registration_connect_recheck:
    mov    eax,dword ptr [esi+0x120]
    test   eax,eax
    jne registration_connect_return
    mov    ecx,esi
    // DropRegistrationTransport; callback return remains in EAX.
    call   R6GameServiceAddresses::DropRegistrationTransport
  registration_connect_return:
    mov    ecx,dword ptr [esp+0x8]
    mov    al,byte ptr [esi+0x9b]
    pop    esi
    mov    dword ptr fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Caches 16 bytes of text0, builds three text fields, and reports whether a transport was present for submission.
// R6GameService.dll @ 1002fb20 : ECX service, RET 0xc; explicit descriptor/SEH frame and raw EAX return.
__declspec(naked) uint __thiscall SendRouterLoginRequest(void *service,char *text0,char *text1,char *text2)
{
  __asm {
    // ESI is service, EDI is text0; descriptor begins at [ESP+0x18] after the saved registers.
    push   0xffffffff
    push   R6GameServiceAddresses::LoginRequestExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    dword ptr fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    dword ptr [esp+0xc],0x0
    mov    edi,dword ptr [esp+0x44]
    push   0x10
    lea    eax,[esi+0x8]
    push   edi
    push   eax
    // strncpy(service+8, text0, 16), without forcing a final NUL.
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    mov    dword ptr [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    dword ptr [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    dword ptr [esp+0xc],0x1
    mov    dword ptr [esp+0x20],0x3
    mov    dword ptr [esp+0x18],R6GameServiceAddresses::PTR_LAB
    lea    ecx,[esp+0x24]
    lea    edx,[esp+0x28]
    mov    dword ptr [esp+0x10],ecx
    mov    dword ptr [esp+0x14],edx
    lea    eax,[esp+0x44]
    lea    ecx,[esp+0x28]
    push   eax
    mov    dword ptr [esp+0x40],0x4
    // Construct the circular-list storage; one argument word is consumed.
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    mov    dword ptr [esp+0x18],ebx
    push   edi
    lea    ecx,[esp+0x1c]
    mov    dword ptr [esp+0x40],0x5
    // Append the next text field to the descriptor.
    call   R6GameServiceAddresses::AppendClDataListString
    mov    ecx,dword ptr [esp+0x48]
    push   ecx
    lea    ecx,[esp+0x1c]
    // Append the next text field to the descriptor.
    call   R6GameServiceAddresses::AppendClDataListString
    mov    edx,dword ptr [esp+0x4c]
    lea    ecx,[esp+0x18]
    push   edx
    // Append the next text field to the descriptor.
    call   R6GameServiceAddresses::AppendClDataListString
    mov    ecx,dword ptr [esi+0x120]
    test   ecx,ecx
    jne registration_login_submit
    mov    dword ptr [esp+0x18],ebx
    mov    ebx,0x6
    lea    eax,[esp+0x24]
    mov    dword ptr [esp+0x3c],ebx
    mov    dword ptr [esp+0x44],eax
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    byte ptr [esp+0x3c],0x7
    // Destroy contents through their current virtual table.
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    byte ptr [esp+0x3c],bl
    // Release nodes and sentinel; upper EAX survives into the final AL result.
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,dword ptr [esp+0x28]
    mov    dword ptr fs:0x0,ecx
    add    esp,0x34
    ret    0xc
  registration_login_submit:
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   0x66
    // SendConnectedTransportPayload(transport, 0x66, 1, descriptor); result ignored.
    call   R6GameServiceAddresses::SendConnectedTransportPayload
    mov    dword ptr [esp+0x18],ebx
    mov    ebx,0x8
    lea    eax,[esp+0x24]
    mov    dword ptr [esp+0x3c],ebx
    mov    dword ptr [esp+0x44],eax
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    byte ptr [esp+0x3c],0x9
    // Destroy contents through their current virtual table.
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    byte ptr [esp+0x3c],bl
    // Release nodes and sentinel; upper EAX survives into the final AL result.
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,dword ptr [esp+0x34]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    dword ptr fs:0x0,ecx
    add    esp,0x34
    ret    0xc
  }
}

// For saved flag bit 0, forwards the frame-local virtual-base context to the empty cleanup target.
// R6GameService.dll @ 10065f50 : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl CleanupLoginConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x34]
    and    eax,0x1
    test   eax,eax
    je registration_login_flag_cleanup_done
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  registration_login_flag_cleanup_done:
    ret
  }
}

// Resets the partially constructed descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 10065f67 : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl ResetLoginDescriptorBase(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Passes inherited parent EBP+4 to the empty constructor-argument cleanup target.
// R6GameService.dll @ 10065f6f : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl CleanupLoginConstructorArgument(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the constructed descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 10065f77 : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl DestroyLoginDescriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets the descriptor base during missing-transport cleanup.
// R6GameService.dll @ 10065f7f : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl ResetLoginMissingTransportDescriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Releases the missing-transport descriptor storage through the saved contents-subobject pointer.
// R6GameService.dll @ 10065f87 : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl ReleaseLoginMissingTransportStorage(void)
{
  __asm {
    cmp    dword ptr [ebp+0x4],0x0
    je registration_login_missing_storage_null
    mov    eax,dword ptr [ebp+0x4]
    add    eax,0x4
    mov    dword ptr [ebp-0x40],eax
    jmp registration_login_missing_storage_release
  registration_login_missing_storage_null:
    mov    dword ptr [ebp-0x40],0x0
  registration_login_missing_storage_release:
    mov    ecx,dword ptr [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets the descriptor base during submitted-request cleanup.
// R6GameService.dll @ 10065fae : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl ResetLoginSubmittedDescriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Releases submitted-request descriptor storage through the saved contents-subobject pointer.
// R6GameService.dll @ 10065fb6 : private unwind ABI; inherited parent EBP and native tail/register effects retained.
__declspec(naked) void __cdecl ReleaseLoginSubmittedStorage(void)
{
  __asm {
    cmp    dword ptr [ebp+0x4],0x0
    je registration_login_submitted_storage_null
    mov    eax,dword ptr [ebp+0x4]
    add    eax,0x4
    mov    dword ptr [ebp-0x48],eax
    jmp registration_login_submitted_storage_release
  registration_login_submitted_storage_null:
    mov    dword ptr [ebp-0x48],0x0
  registration_login_submitted_storage_release:
    mov    ecx,dword ptr [ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Dispatches router-login construction and destruction cleanup through FuncInfo 0x1008036c.
// R6GameService.dll @ 10065fdd : private exception-handler ABI; installs FuncInfo in EAX and tail-transfers.
__declspec(naked) void __cdecl LoginRequestExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::LoginRequestExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Sends descriptor fields 12 and text as opcode d9, calls the record-list method, then destroys the request.
// R6GameService.dll @ 1002fca0 : ECX service, RET 4; explicit native frame and raw EAX result.
__declspec(naked) uint __thiscall SendOpcodeD9TextRequest(void *service,char *text)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::D9RequestExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    dword ptr fs:0x0,esp
    sub    esp,0x30
    push   esi
    mov    dword ptr [esp+0x8],0x0
    mov    esi,ecx
    mov    dword ptr [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    dword ptr [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    dword ptr [esp+0x8],0x1
    mov    dword ptr [esp+0x20],0x3
    mov    dword ptr [esp+0x18],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x24]
    lea    ecx,[esp+0x28]
    mov    dword ptr [esp+0xc],eax
    mov    dword ptr [esp+0x10],ecx
    lea    edx,[esp+0x7]
    lea    ecx,[esp+0x28]
    push   edx
    mov    dword ptr [esp+0x40],0x4
    // Construct descriptor sentinel storage.
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    dword ptr [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x8]
    lea    ecx,[esp+0x18]
    push   eax
    mov    dword ptr [esp+0x40],0x5
    mov    dword ptr [esp+0xc],0xc
    // Append signed integer 12.
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,dword ptr [esp+0x44]
    push   ecx
    lea    ecx,[esp+0x1c]
    // Append the supplied text.
    call   R6GameServiceAddresses::AppendClDataListString
    mov    ecx,dword ptr [esi+0x120]
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   0xd9
    // SendTransportPayload(service transport, d9, 1, descriptor); result ignored.
    call   R6GameServiceAddresses::SendTransportPayload
    mov    ecx,dword ptr [esi+0x4]
    mov    eax,dword ptr [ecx]
    call   dword ptr [eax+0x4]
    mov    dword ptr [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x24]
    mov    dword ptr [esp+0x3c],0x6
    mov    dword ptr [esp+0x44],ecx
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    byte ptr [esp+0x3c],0x7
    // Destroy descriptor contents.
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x28]
    mov    dword ptr [esp+0x14],edx
    lea    ecx,[esp+0x28]
    mov    byte ptr [esp+0x3c],0x8
    // Clear list nodes, retaining the sentinel for the following release.
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,dword ptr [esp+0x28]
    push   0x1
    push   eax
    lea    ecx,[esp+0x30]
    // Free the sentinel; upper EAX is retained when AL is set to 1.
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,dword ptr [esp+0x34]
    mov    al,0x1
    pop    esi
    mov    dword ptr fs:0x0,ecx
    add    esp,0x3c
    ret    0x4
  }
}

// For saved flag bit 0, forwards the virtual-base context to empty cleanup.
// R6GameService.dll @ 10065ff0 : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl CleanupD9ConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x38]
    and    eax,0x1
    test   eax,eax
    je d9_flag_cleanup_done
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  d9_flag_cleanup_done:
    ret
  }
}

// Resets the partially constructed descriptor at parent EBP-0x28.
// R6GameService.dll @ 10066007 : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl ResetD9DescriptorBase(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forwards the local sentinel-construction argument at parent EBP-0x39 to empty cleanup.
// R6GameService.dll @ 1006600f : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl CleanupD9ConstructorArgument(void)
{
  __asm {
    lea    ecx,[ebp-0x39]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the completed descriptor at parent EBP-0x28.
// R6GameService.dll @ 10066017 : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl DestroyD9Descriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets the descriptor base during normal destruction.
// R6GameService.dll @ 1006601f : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl ResetD9CleanupDescriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Releases storage using the saved contents pointer, after writing the adjusted pointer into parent EBP-0x2c.
// R6GameService.dll @ 10066027 : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl ReleaseD9DescriptorStorage(void)
{
  __asm {
    cmp    dword ptr [ebp+0x4],0x0
    je d9_storage_null
    mov    eax,dword ptr [ebp+0x4]
    add    eax,0x4
    mov    dword ptr [ebp-0x2c],eax
    jmp d9_storage_release
  d9_storage_null:
    mov    dword ptr [ebp-0x2c],0x0
  d9_storage_release:
    mov    ecx,dword ptr [ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Forwards the saved storage context at parent EBP-0x2c to empty cleanup.
// R6GameService.dll @ 1006604e : private unwind ABI; inherited parent EBP and native tail effects retained.
__declspec(naked) void __cdecl CleanupD9ReleasedStorage(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x2c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Dispatches the d9 descriptor cleanup graph through FuncInfo 0x100803d0.
// R6GameService.dll @ 10066056 : private exception-handler ABI; FuncInfo in EAX and shared frame-handler tail transfer.
__declspec(naked) void __cdecl D9RequestExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::D9RequestExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Constructs the lobby provider when absent, opens it, and polls until state 4 or failure.
// R6GameService.dll @ 100307e0 : ECX service, RET 0x14; explicit native frame and raw EAX result.
__declspec(naked) uint __thiscall ConnectLobbyServerTransport(void *service,uint openWord0,
    uint openWord1,uint openWord2,uint constructorWord0,uint constructorWord1)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SharedRegistrationAllocationExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    dword ptr fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    eax,dword ptr [esi+0x124]
    test   eax,eax
    jne lobby_provider_check_active
    push   0x6c
    // Allocate 0x6c bytes for the lobby provider.
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    dword ptr [esp+0x4],eax
    test   eax,eax
    mov    dword ptr [esp+0x10],0x0
    je lobby_provider_allocation_failed
    mov    ecx,dword ptr [esp+0x28]
    mov    edx,dword ptr [esp+0x24]
    push   0x1
    push   ecx
    push   0xc
    push   0x8
    push   edx
    mov    ecx,eax
    // Construct provider(constructorWord0, 8, 0xc, constructorWord1, 1).
    call   R6GameServiceAddresses::clSRPGSClientConstruct
    jmp lobby_provider_publish
  lobby_provider_allocation_failed:
    xor    eax,eax
  lobby_provider_publish:
    mov    dword ptr [esp+0x10],0xffffffff
    mov    dword ptr [esi+0x124],eax
  lobby_provider_check_active:
    mov    al,byte ptr [esi+0x9a]
    test   al,al
    jne lobby_provider_success
    mov    edx,dword ptr [esp+0x20]
    mov    ecx,dword ptr [esi+0x124]
    push   edx
    mov    edx,dword ptr [esp+0x20]
    mov    eax,dword ptr [ecx]
    push   edx
    mov    edx,dword ptr [esp+0x20]
    push   edx
    call   dword ptr [eax+0x4]
    test   al,al
    jne lobby_provider_poll
  lobby_provider_fail:
    mov    ecx,esi
    // Clear secondary state on open/poll failure.
    call   R6GameServiceAddresses::ClearSecondaryServiceState
    xor    al,al
    pop    esi
    mov    ecx,dword ptr [esp+0x4]
    mov    dword ptr fs:0x0,ecx
    add    esp,0x10
    ret    0x14
  lobby_provider_poll:
    mov    ecx,dword ptr [esi+0x124]
    // Process/check the current provider; only AL is tested.
    call   R6GameServiceAddresses::DispatchProviderReceiveState
    test   al,al
    je lobby_provider_fail
    mov    ecx,dword ptr [esi+0x124]
    // Test provider state against 4; only AL is tested.
    call   R6GameServiceAddresses::ReadAssociatedProviderReady
    test   al,al
    je lobby_provider_poll
    mov    byte ptr [esi+0x9a],0x1
  lobby_provider_success:
    mov    ecx,dword ptr [esp+0x8]
    mov    al,0x1
    pop    esi
    mov    dword ptr fs:0x0,ecx
    add    esp,0x10
    ret    0x14
  }
}

// Return AL0 for a missing provider, otherwise forward its slot+8 result byte without normalizing it.
// Upper EAX residue is unconsumed by the sole ordinary route; the service pointer itself remains unchecked.
// R6GameService.dll @ 100308c0 : inferred AL return view; ECX service, RET0, no local guard.
byte __fastcall CloseLobbyServerTransport(void *service)
{
  void *provider = *(void **)((uint)service + 0x124);
  if (provider == nullptr) return 0;
  uint table = *(uint *)provider;
  using CloseABI = byte (__thiscall *)(void *);
  return (*(CloseABI *)(table + 8))(provider);
}

// Native allocation guard record: its saved pointer precedes the three-word FS exception-chain record.
struct RegistrationAllocationFrame {
  void *pendingAllocation;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Native local frame, from parent EBP-0xe8 through EBP-4; each array retains observed descriptor words.
struct RegistrationD5Frame {
  uint scratchWord; // Construction bits initially; later reused for individual serialized integers.
  uint optionBits;
  uint payload[7];
  uint envelope[7];
  uint binary0[8];
  uint binary2[8];
  uint binary1[8];
  uint fallbackRecord[15];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Builds a nested D5 registration request, replacing both parent words from the greatest record if either is zero.
// R6GameService.dll @ 1002fde0 : ECX service, nineteen stack words, RET 0x4c; only low bytes select option bits.
uint __thiscall SendServerRegistrationOpcodeD5(void *service,int parentWord0,int parentWord1,char *text0,
    char *text1,uint word16_0,int scalar0,int scalar1,char *text2,byte *bytes0,uint byteCount0,byte *bytes1,
    uint byteCount1,byte *bytes2,uint byteCount2,uint word16_1,char *text3,char *text4,uint option0800Word,
    uint option4000Word)
{
  RegistrationD5Frame frame;
  uint cleanupResult;
  uint sendResult;
  frame.state = 0xffffffff;
  frame.scratchWord = 0;
  frame.handler = (void *)RegistrationD5ExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  frame.payload[1] = (uint)&ClDataListBaseOffsets;
  frame.payload[5] = (uint)&ClDataListInnerBaseOffsets;
  frame.scratchWord = 1;
  frame.state = 0;
  ExceptionList = &frame.previousExceptionList;
  InitializeClDataFields(&frame.payload[0],3,0);
  frame.state = 1;
  ConstructClDataPointerList((frame.payload + 3),0);
  frame.payload[0] = (uint)&clDataListPTR_FUN;
  frame.payload[3] = (uint)&clDataListPTR_LAB;
  frame.state = 2;
  frame.envelope[1] = (uint)&ClDataListBaseOffsets;
  frame.envelope[5] = (uint)&ClDataListInnerBaseOffsets;
  frame.scratchWord = 3;
  frame.state = 3;
  InitializeClDataFields(&frame.envelope[0],3,0);
  frame.state = 4;
  ConstructClDataPointerList((frame.envelope + 3),0);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.envelope[3] = (uint)&clDataListPTR_LAB;
  frame.binary0[1] = (uint)&ClDataBinOwnerBaseOffsets;
  frame.binary0[6] = (uint)&ClDataBinBaseOffsets;
  frame.scratchWord = 7;
  frame.state = ((frame.state & 0xffffff00) | 6);
  InitializeClDataFields(&frame.binary0[0],2,0);
  frame.state = 7;
  InitializeEmptyByteBufferTriplet((frame.binary0 + 3),0);
  frame.binary0[0] = (uint)&clDataBinPTR_FUN;
  frame.binary1[1] = (uint)&ClDataBinOwnerBaseOffsets;
  frame.binary1[6] = (uint)&ClDataBinBaseOffsets;
  frame.scratchWord = 0xf;
  frame.state = ((frame.state & 0xffffff00) | 9);
  InitializeClDataFields(&frame.binary1[0],2,0);
  frame.state = 10;
  InitializeEmptyByteBufferTriplet((frame.binary1 + 3),0);
  frame.binary1[0] = (uint)&clDataBinPTR_FUN;
  frame.binary2[1] = (uint)&ClDataBinOwnerBaseOffsets;
  frame.binary2[6] = (uint)&ClDataBinBaseOffsets;
  frame.scratchWord = 0x1f;
  frame.state = ((frame.state & 0xffffff00) | 0xc);
  InitializeClDataFields(&frame.binary2[0],2,0);
  frame.state = 0xd;
  InitializeEmptyByteBufferTriplet((frame.binary2 + 3),0);
  frame.binary2[0] = (uint)&clDataBinPTR_FUN;
  frame.state = (frame.state & 0xffffff00) | 0xe;
  if ((parentWord0 == 0) || (parentWord1 == 0)) {
    InitializeEmptyParsedServiceRecord(frame.fallbackRecord,1);
    frame.state = (frame.state & 0xffffff00) | 0xf;
    cleanupResult = CopyGreatestParsedServiceRecord(*(void **)((int)service + 4),frame.fallbackRecord);
    if ((char)cleanupResult == '\0') {
      frame.state = (frame.state & 0xffffff00) | 0xe;
      ((void (__thiscall *)(void *))list_node_support_NoOp)(frame.fallbackRecord);
      frame.state = (frame.state & 0xffffff00) | 0xb;
      DestroyClDataBin(&frame.binary2[0]);
      frame.state = (frame.state & 0xffffff00) | 8;
      DestroyClDataBin(&frame.binary1[0]);
      frame.state = (frame.state & 0xffffff00) | 5;
      DestroyClDataBin(&frame.binary0[0]);
      frame.state = ((frame.state & 0xffffff00) | 2);
      DestroyClDataList(&frame.envelope[0]);
      frame.state = 0xffffffff;
      sendResult = DestroyClDataList(&frame.payload[0]);
      ExceptionList = frame.previousExceptionList;
      return sendResult & 0xffffff00;
    }
    parentWord0 = frame.fallbackRecord[1];
    parentWord1 = frame.fallbackRecord[2];
    ((void (__cdecl *)(const char *,int,int))list_node_support_NoOp)(
        (const char *)R6GameServiceAddresses::TextRandomParentGroupDD,parentWord0,parentWord1);
    frame.state = (frame.state & 0xffffff00) | 0xe;
    ((void (__thiscall *)(void *))list_node_support_NoOp)(frame.fallbackRecord);
  }
  frame.optionBits = 0x2010;
  if ((byte)option0800Word != 0) {
    frame.optionBits = 0x2810;
  }
  if ((byte)option4000Word != 0) {
    frame.optionBits = frame.optionBits | 0x4000;
  }
  ReplaceClDataBinBytes(&frame.binary0[0],bytes0,byteCount0);
  ReplaceClDataBinBytes(&frame.binary1[0],bytes1,byteCount1);
  ReplaceClDataBinBytes(&frame.binary2[0],bytes2,byteCount2);
  AppendClDataListString(&frame.payload[0],(char *)((int)service + 8));
  AppendClDataListSignedDecimal(&frame.payload[0],&parentWord1);
  AppendClDataListString(&frame.payload[0],text0);
  AppendClDataListString(&frame.payload[0],text1);
  frame.scratchWord = word16_0 & 0xffff;
  AppendClDataListSignedDecimal(&frame.payload[0],&frame.scratchWord);
  AppendClDataListSignedDecimal(&frame.payload[0],&scalar0);
  AppendClDataListSignedDecimal(&frame.payload[0],&scalar1);
  AppendClDataListBinaryCopy(&frame.payload[0],&frame.binary0[0]);
  AppendClDataListBinaryCopy(&frame.payload[0],&frame.binary2[0]);
  AppendClDataListString(&frame.payload[0],text2);
  AppendClDataListString(&frame.payload[0],text3);
  AppendClDataListString(&frame.payload[0],text4);
  AppendClDataListSignedDecimal(&frame.payload[0],&frame.optionBits);
  QueryProviderPeerEndpoint(*(void **)((int)service + 0x120),(char *)((int)service + 0x9c));
  AppendClDataListString(&frame.payload[0],(char *)((int)service + 0x9c));
  frame.scratchWord = word16_1 & 0xffff;
  AppendClDataListSignedDecimal(&frame.payload[0],&frame.scratchWord);
  AppendClDataListBinaryCopy(&frame.payload[0],&frame.binary1[0]);
  frame.scratchWord = 0xc;
  AppendClDataListSignedDecimal(&frame.envelope[0],&frame.scratchWord);
  AppendClDataListSignedDecimal(&frame.envelope[0],&parentWord0);
  AppendClDataListCopy(&frame.envelope[0],&frame.payload[0]);
  sendResult = SendTransportPayload(*(void **)((int)service + 0x120),0xd5,1,(const void *)&frame.envelope[0],(uint)&frame.envelope[0]);
  frame.binary2[0] = (uint)&clDataBinPTR_FUN;
  frame.state = (frame.state & 0xffffff00) | 0x10;
  ReleaseNonNullFirstWordBuffer((frame.binary2 + 3));
  frame.binary2[0] = (uint)&PTR_LAB;
  frame.state = (frame.state & 0xffffff00) | 8;
  DestroyClDataBin(&frame.binary1[0]);
  frame.binary0[0] = (uint)&clDataBinPTR_FUN;
  frame.state = (frame.state & 0xffffff00) | 0x11;
  ReleaseNonNullFirstWordBuffer((frame.binary0 + 3));
  frame.binary0[0] = (uint)&PTR_LAB;
  frame.state = ((frame.state & 0xffffff00) | 2);
  DestroyClDataList(&frame.envelope[0]);
  frame.state = 0xffffffff;
  cleanupResult = DestroyClDataList(&frame.payload[0]);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | (byte)sendResult;
}

// Tests mask 0x1 in the construction flags and tail-forwards the payload virtual-base context to empty cleanup.
// R6GameService.dll @ 10066060 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5PayloadConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0xe8]
    and    eax,0x1
    test   eax,eax
    je Branch1
    lea    ecx,[ebp-0xc8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch1:
    ret
  }
}

// Resets the inner payload descriptor at parent EBP-0xe0.
// R6GameService.dll @ 1006607d : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5PayloadBase(void)
{
  __asm {
    lea    ecx,[ebp-0xe0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the completed inner payload descriptor at parent EBP-0xe0.
// R6GameService.dll @ 10066088 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyD5Payload(void)
{
  __asm {
    lea    ecx,[ebp-0xe0]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Tests mask 0x2 and tail-forwards the envelope virtual-base context to empty cleanup.
// R6GameService.dll @ 10066093 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5EnvelopeConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0xe8]
    and    eax,0x2
    test   eax,eax
    je Branch2
    lea    ecx,[ebp-0xac]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch2:
    ret
  }
}

// Resets the outer envelope descriptor at parent EBP-0xc4.
// R6GameService.dll @ 100660b0 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5EnvelopeBase(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the completed outer envelope at parent EBP-0xc4.
// R6GameService.dll @ 100660bb : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyD5Envelope(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Tests mask 0x4 and tail-forwards the first binary virtual-base context to empty cleanup.
// R6GameService.dll @ 100660c6 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5Binary0ConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0xe8]
    and    eax,0x4
    test   eax,eax
    je Branch3
    lea    ecx,[ebp-0x8c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch3:
    ret
  }
}

// Resets binary descriptor 0 at parent EBP-0xa8.
// R6GameService.dll @ 100660e3 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5Binary0Base(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys binary descriptor 0 through its cleanup alias.
// R6GameService.dll @ 100660ee : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyD5Binary0(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tests mask 0x8 and tail-forwards the second binary virtual-base context to empty cleanup.
// R6GameService.dll @ 100660f9 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5Binary1ConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0xe8]
    and    eax,0x8
    test   eax,eax
    je Branch4
    lea    ecx,[ebp-0x4c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Resets binary descriptor 1 at parent EBP-0x68.
// R6GameService.dll @ 10066113 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5Binary1Base(void)
{
  __asm {
    lea    ecx,[ebp-0x68]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys binary descriptor 1 through its cleanup alias.
// R6GameService.dll @ 1006611b : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyD5Binary1(void)
{
  __asm {
    lea    ecx,[ebp-0x68]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tests mask 0x10 and tail-forwards the third binary virtual-base context to empty cleanup.
// R6GameService.dll @ 10066123 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5Binary2ConstructionFlag(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0xe8]
    and    eax,0x10
    test   eax,eax
    je Branch5
    lea    ecx,[ebp-0x6c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch5:
    ret
  }
}

// Resets binary descriptor 2 at parent EBP-0x88.
// R6GameService.dll @ 1006613d : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5Binary2Base(void)
{
  __asm {
    lea    ecx,[ebp-0x88]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys binary descriptor 2 through its cleanup alias.
// R6GameService.dll @ 10066148 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyD5Binary2(void)
{
  __asm {
    lea    ecx,[ebp-0x88]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tail-forwards the fallback record at parent EBP-0x48 to its empty cleanup alias.
// R6GameService.dll @ 10066153 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupD5FallbackRecord(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ForwardToNoOp
  }
}

// Resets binary descriptor 2 after its buffer-release stage.
// R6GameService.dll @ 1006615b : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5ReleasedBinary2Base(void)
{
  __asm {
    lea    ecx,[ebp-0x88]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets binary descriptor 0 after its buffer-release stage.
// R6GameService.dll @ 10066166 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetD5ReleasedBinary0Base(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Installs D5 FuncInfo 0x1008047c and tail-transfers to the shared frame handler.
// R6GameService.dll @ 10066171 : private exception-handler ABI; FuncInfo in EAX.
__declspec(naked) void __cdecl RegistrationD5ExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RegistrationD5ExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Resets the partially constructed lobby-login descriptor at parent EBP-0x24.
// R6GameService.dll @ 100661a0 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetLobbyLoginDescriptorBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail-forwards the local byte argument at parent EBP-0x29 to empty cleanup.
// R6GameService.dll @ 100661a8 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl CleanupLobbyLoginConstructorArgument(void)
{
  __asm {
    lea    ecx,[ebp-0x29]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys the completed lobby-login descriptor at parent EBP-0x24.
// R6GameService.dll @ 100661b0 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl DestroyLobbyLoginDescriptor(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets the lobby-login descriptor during normal cleanup.
// R6GameService.dll @ 100661b8 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ResetLobbyLoginCleanupBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Stores the adjusted saved contents pointer at parent EBP-0x44 and tail-releases storage.
// R6GameService.dll @ 100661c0 : private unwind ABI; inherited EBP and native tail/register operands retained.
__declspec(naked) void __cdecl ReleaseLobbyLoginStorage(void)
{
  __asm {
    cmp    dword ptr [ebp+0x4],0x0
    je Branch6
    mov    eax,dword ptr [ebp+0x4]
    add    eax,0x4
    mov    dword ptr [ebp-0x44],eax
    jmp Branch7
  Branch6:
    mov    dword ptr [ebp-0x44],0x0
  Branch7:
    mov    ecx,dword ptr [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Installs lobby-login FuncInfo 0x10080508 and tail-transfers to the shared frame handler.
// R6GameService.dll @ 100661e7 : private exception-handler ABI; FuncInfo in EAX.
__declspec(naked) void __cdecl LobbyLoginExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::LobbyLoginExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Queues lobby-login opcode d2 from text and one integer, or clears unavailable provider state.
// R6GameService.dll @ 100308e0 : ECX service, RET 8; retains queue AL and final cleanup upper EAX.
__declspec(naked) uint __thiscall SendLobbyServerLoginRequest(void *service,char *loginText,int value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::LobbyLoginExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    dword ptr fs:0x0,esp
    sub    esp,0x20
    push   esi
    mov    esi,ecx
    mov    dword ptr [esp+0x8],0x0
    mov    eax,dword ptr [esi+0x124]
    test   eax,eax
    je lobby_login_unavailable
    mov    al,byte ptr [esi+0x9a]
    test   al,al
    jne lobby_login_construct
  lobby_login_unavailable:
    mov    ecx,esi
    call   R6GameServiceAddresses::ClearSecondaryServiceState
    xor    al,al
    pop    esi
    mov    ecx,dword ptr [esp+0x20]
    mov    dword ptr fs:0x0,ecx
    add    esp,0x2c
    ret    0x8
  lobby_login_construct:
    push   ebx
    mov    dword ptr [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    dword ptr [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    dword ptr [esp+0x18],0x3
    mov    dword ptr [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0xb]
    lea    ecx,[esp+0x20]
    push   eax
    mov    dword ptr [esp+0x34],0x1
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    dword ptr [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    dword ptr [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,dword ptr [esp+0x38]
    mov    dword ptr [esp+0x30],0x2
    push   ecx
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::AppendClDataListString
    lea    edx,[esp+0x3c]
    lea    ecx,[esp+0x10]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,dword ptr [esi+0x124]
    lea    eax,[esp+0x10]
    push   eax
    push   0xd2
    call   R6GameServiceAddresses::QueueRecordUsingStoredHeaderFields
    mov    bl,al
    mov    dword ptr [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    dword ptr [esp+0x30],0x3
    mov    dword ptr [esp+0x38],ecx
    mov    dword ptr [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    byte ptr [esp+0x30],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    byte ptr [esp+0x30],0x3
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,dword ptr [esp+0x28]
    mov    al,bl
    pop    ebx
    pop    esi
    mov    dword ptr fs:0x0,ecx
    add    esp,0x2c
    ret    0x8
  }
}

// Native local frame from logical parent EBP-0x4c through EBP-4; argument 2 supplies separate allocation scratch.
struct OptionalRegistrationFrame {
  uint presenceMask;
  uint optionBits;
  void *savedService;
  uint envelope[6];
  uint binary[7];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Queues only supplied registration fields, wrapping the heap payload under opcode 0x1f inside message 0xd1.
// R6GameService.dll @ 10030a10 : ECX service, fourteen argument words, RET 0x38; raw cleanup-upper/queue-low EAX.
uint __thiscall SendOptionalRegistrationFields(void *service,uint groupId,uint option0Word,uint option1Word,
    uint option2Word,int value0,int value1,char *text,byte *bytes0,int length0,byte *bytes1,int length1,
    byte *bytes2,int length2,uint lowWordValue)
{
  OptionalRegistrationFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)OptionalRegistrationExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.optionBits = 0;
  frame.savedService = service;
  if (*(void **)((byte *)service + 0x124) == nullptr || *((byte *)service + 0x9a) == 0) {
    uint failureResult;
    __asm {
      mov ecx,service
      call R6GameServiceAddresses::ClearSecondaryServiceState
      mov failureResult,eax
    }
    ExceptionList = frame.previousExceptionList;
    return failureResult & 0xffffff00;
  }
  frame.presenceMask = 0;
  frame.envelope[1] = (uint)&ClDataListBaseOffsets;
  frame.envelope[5] = (uint)&ClDataListInnerBaseOffsets;
  frame.envelope[2] = 3;
  frame.envelope[0] = (uint)&PTR_LAB;
  frame.state = 0;
  ConstructClDataPointerList(frame.envelope + 3,0);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.envelope[3] = (uint)&clDataListPTR_LAB;
  frame.state = 1;
  frame.optionBits = 0;
  signed char option0 = (signed char)(byte)option0Word;
  signed char option1 = (signed char)(byte)option1Word;
  signed char option2 = (signed char)(byte)option2Word;
  if (option0 >= 0) {
    frame.presenceMask |= 2;
    if (option0 != 0) frame.optionBits = 0x10;
  }
  if (option1 >= 0) {
    frame.presenceMask |= 4;
    if (option1 != 0) frame.optionBits |= 0x800;
  }
  if (option2 >= 0) {
    frame.presenceMask |= 0x200;
    if (option2 != 0) frame.optionBits |= 0x4000;
  }
  if (value0 != -1) frame.presenceMask |= 8;
  if (value1 != -1) frame.presenceMask |= 0x10;
  if (text != nullptr) frame.presenceMask |= 0x20;
  if (bytes0 != nullptr && length0 >= 0) frame.presenceMask |= 0x40;
  if (bytes1 != nullptr && length1 >= 0) frame.presenceMask |= 0x400;
  if (bytes2 != nullptr && length2 >= 0) frame.presenceMask |= 0x80;
  if ((ushort)lowWordValue != 0) frame.presenceMask |= 0x100;
  uint *payload = (uint *)AllocateGameServiceBytes(0x18);
  option0Word = (uint)payload; // The pending-allocation action reads original argument 2 at parent EBP+8.
  if (payload != nullptr) {
    payload[1] = (uint)&ClDataListBaseOffsets;
    payload[5] = (uint)&ClDataListInnerBaseOffsets;
    payload[2] = 3;
    payload[0] = (uint)&PTR_LAB;
    frame.state = 3;
    ConstructClDataPointerList(payload + 3,0);
    payload[0] = (uint)&clDataListPTR_FUN;
    payload[3] = (uint)&clDataListPTR_LAB;
  }
  frame.state = 1;
  AppendClDataListSignedDecimal(payload,&groupId);
  AppendClDataListSignedDecimal(payload,&frame.presenceMask);
  if ((frame.presenceMask & 0x206) != 0) {
    AppendClDataListSignedDecimal(payload,&frame.optionBits);
  }
  if ((frame.presenceMask & 8) != 0) AppendClDataListSignedDecimal(payload,&value0);
  if ((frame.presenceMask & 0x10) != 0) AppendClDataListSignedDecimal(payload,&value1);
  if ((frame.presenceMask & 0x20) != 0) AppendClDataListString(payload,text);
  if ((frame.presenceMask & 0x40) != 0) {
    frame.binary[1] = (uint)&ClDataBinOwnerBaseOffsets;
    frame.binary[6] = (uint)&ClDataBinBaseOffsets;
    frame.binary[2] = 2;
    frame.binary[0] = (uint)&PTR_LAB;
    frame.state = 4;
    InitializeEmptyByteBufferTriplet(frame.binary + 3,0);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 5;
    ReplaceClDataBinBytes(frame.binary,bytes0,(uint)length0);
    AppendClDataListBinaryCopy(payload,frame.binary);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 6;
    ReleaseNonNullFirstWordBuffer(frame.binary + 3);
    frame.state = 1;
  }
  if ((frame.presenceMask & 0x400) != 0) {
    frame.binary[1] = (uint)&ClDataBinOwnerBaseOffsets;
    frame.binary[6] = (uint)&ClDataBinBaseOffsets;
    frame.binary[2] = 2;
    frame.binary[0] = (uint)&PTR_LAB;
    frame.state = 7;
    InitializeEmptyByteBufferTriplet(frame.binary + 3,0);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 8;
    ReplaceClDataBinBytes(frame.binary,bytes1,(uint)length1);
    AppendClDataListBinaryCopy(payload,frame.binary);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 9;
    ReleaseNonNullFirstWordBuffer(frame.binary + 3);
    frame.state = 1;
  }
  if ((frame.presenceMask & 0x80) != 0) {
    frame.binary[1] = (uint)&ClDataBinOwnerBaseOffsets;
    frame.binary[6] = (uint)&ClDataBinBaseOffsets;
    InitializeClDataFields(frame.binary,2,0);
    frame.state = 10;
    InitializeEmptyByteBufferTriplet(frame.binary + 3,0);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 11;
    ReplaceClDataBinBytes(frame.binary,bytes2,(uint)length2);
    AppendClDataListBinaryCopy(payload,frame.binary);
    frame.binary[0] = (uint)&clDataBinPTR_FUN;
    frame.state = 12;
    ReleaseNonNullFirstWordBuffer(frame.binary + 3);
    frame.state = 1;
  }
  if ((frame.presenceMask & 0x100) != 0) {
    option0Word = lowWordValue & 0xffff;
    AppendClDataListSignedDecimal(payload,&option0Word);
  }
  option0Word = 0x1f;
  AppendClDataListSignedDecimal(frame.envelope,&option0Word);
  AppendClDataListPointer(frame.envelope,payload);
  uint queueResult = QueueRecordUsingStoredHeaderFields(
      *(void **)((byte *)frame.savedService + 0x124),0xd1,frame.envelope);
  frame.state = 0xffffffff;
  uint cleanupResult = DestroyClDataList(frame.envelope);
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | (byte)queueResult;
}

// Resets the partially constructed envelope at inherited parent EBP-0x40.
// R6GameService.dll @ 10066200 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalEnvelopeBase(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the completed envelope at inherited parent EBP-0x40.
// R6GameService.dll @ 10066208 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl DestroyOptionalEnvelope(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Frees the pending payload allocation saved in argument 2 at parent EBP+8.
// R6GameService.dll @ 10066210 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl FreeOptionalPendingPayload(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Resets the pending heap payload using the saved pointer in argument 2.
// R6GameService.dll @ 1006621a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalPendingPayloadBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp+0x8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the first optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 10066222 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalBinary0Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the first optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 1006622a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl DestroyOptionalBinary0(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the first binary descriptor after its buffer-release stage.
// R6GameService.dll @ 10066232 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalReleasedBinary0Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the second optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 1006623a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalBinary1Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the second optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 10066242 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl DestroyOptionalBinary1(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the second binary descriptor after its buffer-release stage.
// R6GameService.dll @ 1006624a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalReleasedBinary1Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the third optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 10066252 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalBinary2Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the third optional binary descriptor at inherited parent EBP-0x28.
// R6GameService.dll @ 1006625a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl DestroyOptionalBinary2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Resets the third binary descriptor after its buffer-release stage.
// R6GameService.dll @ 10066262 : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl ResetOptionalReleasedBinary2Base(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Installs optional-request FuncInfo 0x1008058c and tail-transfers to the shared frame handler.
// R6GameService.dll @ 1006626a : private inherited-frame ABI; native receiver and tail/register effects retained.
__declspec(naked) void __cdecl OptionalRegistrationExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::OptionalRegistrationExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Observed scalar-reply locals preserve the 0x81-byte text buffer and trailing stack padding.
struct RegistrationScalarReplyLocals {
  void *nestedList;
  uint scalarStatus;
  char text[0x81];
  byte padding[3];
};

// Parses type 0x26 text or type 0x27 status and forwards the full original reply word through owner slot +4.
// R6GameService.dll @ 10030310 : ECX service, RET 8; callback upper EAX survives with AL set to 1.
uint __thiscall DispatchParsedOpcode26Or27(void *service,uint replyWord,void *message)
{
  RegistrationScalarReplyLocals frame;
  frame.text[0] = GRegistrationEmptyText;
  memset(frame.text + 1,0,0x80);
  frame.scalarStatus = 0;
  uint replyType = replyWord & 0xffff;
  uint parseResult;
  if (replyType == 0x26) {
    parseResult = GetIndexedClDataList(message,(int *)&frame.nestedList,1);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = CopyIndexedStringBounded(frame.nestedList,frame.text,0,0x81);
    if ((byte)parseResult == 0) return parseResult;
  } else {
    uint invalidTypeResult = replyType - 0x27;
    if (invalidTypeResult != 0) return invalidTypeResult & 0xffffff00;
    parseResult = GetIndexedClDataList(message,(int *)&frame.nestedList,1);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = CopyIndexedBytesExact(frame.nestedList,&frame.scalarStatus,4,0);
    if ((byte)parseResult == 0) return parseResult;
  }
  typedef uint (__thiscall *ReplyCallback)(void *,uint,uint,char *);
  ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 4);
  uint callbackResult = callback(service,replyWord,frame.scalarStatus,frame.text);
  return (callbackResult & 0xffffff00) | 1;
}

// Observed text-reply stack order; unbounded short-text copying can overwrite the following long-text storage.
struct RegistrationTextReplyLocals {
  void *nestedList;
  int integerValue;
  uint scalarStatus;
  uint lowWordValue;
  char shortText[0x21];
  byte padding0[3];
  char longText[0x81];
  byte padding1[3];
};

// Parses type 0x26 strings/word/integer or type 0x27 status, retaining the unchecked first list lookup on type 0x26.
// R6GameService.dll @ 10030410 : ECX service, RET 8; full reply word is forwarded to owner slot +0x0c.
uint __thiscall DispatchParsedOpcode26Or27Strings(void *service,uint replyWord,void *message)
{
  RegistrationTextReplyLocals frame;
  byte initialTextByte = GRegistrationEmptyText;
  frame.shortText[0] = initialTextByte;
  memset(frame.shortText + 1,0,0x20);
  frame.longText[0] = initialTextByte;
  memset(frame.longText + 1,0,0x80);
  frame.scalarStatus = 0;
  frame.integerValue = 0;
  frame.lowWordValue = 0;
  uint replyType = replyWord & 0xffff;
  uint parseResult;
  if (replyType == 0x26) {
    GetIndexedClDataList(message,(int *)&frame.nestedList,1);
    parseResult = CopyIndexedClDataString(frame.nestedList,(int)frame.longText,0);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = ReadIndexedWord(frame.nestedList,(undefined2 *)&frame.lowWordValue,1);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = ReadIndexedInt32(frame.nestedList,&frame.integerValue,2);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = CopyIndexedClDataString(frame.nestedList,(int)frame.shortText,3);
    if ((byte)parseResult == 0) return parseResult;
  } else {
    uint invalidTypeResult = replyType - 0x27;
    if (invalidTypeResult != 0) return invalidTypeResult & 0xffffff00;
    parseResult = GetIndexedClDataList(message,(int *)&frame.nestedList,1);
    if ((byte)parseResult == 0) return parseResult;
    parseResult = CopyIndexedBytesExact(frame.nestedList,&frame.scalarStatus,4,0);
    if ((byte)parseResult == 0) return parseResult;
  }
  typedef uint (__thiscall *ReplyCallback)(void *,uint,uint,int,char *,uint,char *);
  ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x0c);
  uint callbackResult = callback(service,replyWord,frame.scalarStatus,frame.integerValue,frame.longText,
                                 frame.lowWordValue,frame.shortText);
  return (callbackResult & 0xffffff00) | 1;
}

// Native record-reply locals from logical parent EBP-0x50 through EBP-4; the text buffer occupies 0x21 bytes.
struct RegistrationRecordReplyFrame {
  int recordWord34;
  int recordWord30;
  int parentWord1;
  int parentWord0;
  uint scalarStatus;
  void *record;
  int *insertionAnchor;
  void *pendingAllocation;
  char text[0x21];
  byte padding[3];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Links and reports each type 0x26 record, then reports completion; type 0x27 reports a four-byte status.
// R6GameService.dll @ 10030580 : ECX service, RET 8; argument 1 becomes the list pointer and argument 2 the current record.
uint __thiscall DispatchParsedOpcode26Or27RecordList(void *service,uint replyWord,void *messageOrRecord)
{
  RegistrationRecordReplyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistrationRecordReplyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  uint replyType = replyWord & 0xffff;
  uint parseResult;
  typedef uint (__thiscall *RecordCallback)(void *,uint,uint,int,int,char *,int,int);
  if (replyType == 0x26) {
    parseResult = GetIndexedClDataList(messageOrRecord,(int *)&replyWord,1);
    if ((byte)parseResult == 0) {
      ExceptionList = frame.previousExceptionList;
      return parseResult;
    }
    uint nextIndex = 1;
    parseResult = GetIndexedClDataList((void *)replyWord,(int *)&messageOrRecord,0);
    while ((byte)parseResult != 0) {
      parseResult = ReadIndexedInt32(messageOrRecord,&frame.parentWord0,0);
      if ((byte)parseResult == 0) {
        ExceptionList = frame.previousExceptionList;
        return parseResult & 0xffffff00;
      }
      parseResult = ReadIndexedInt32(messageOrRecord,&frame.parentWord1,1);
      if ((byte)parseResult == 0) {
        ExceptionList = frame.previousExceptionList;
        return parseResult & 0xffffff00;
      }
      parseResult = CopyIndexedStringBounded(messageOrRecord,frame.text,2,0x21);
      if ((byte)parseResult == 0) {
        ExceptionList = frame.previousExceptionList;
        return parseResult & 0xffffff00;
      }
      parseResult = ReadIndexedInt32(messageOrRecord,&frame.recordWord30,3);
      if ((byte)parseResult == 0) {
        ExceptionList = frame.previousExceptionList;
        return parseResult & 0xffffff00;
      }
      parseResult = ReadIndexedInt32(messageOrRecord,&frame.recordWord34,4);
      if ((byte)parseResult == 0) frame.recordWord34 = 0x3e9;
      frame.pendingAllocation = (void *)AllocateGameServiceBytes(0x3c);
      frame.state = 0;
      frame.record = frame.pendingAllocation == nullptr ? nullptr :
          InitializeParsedServiceRecord(frame.pendingAllocation,frame.parentWord0,frame.parentWord1,frame.text,
                                        frame.recordWord30,frame.recordWord34,1);
      void *recordList = *(void **)((byte *)service + 4);
      frame.state = 0xffffffff;
      CopyListHeadSlot((byte *)recordList + 4,(undefined4 *)&frame.insertionAnchor);
      int *node = (int *)AllocateListPayloadNode((undefined4 *)&frame.record);
      int *previous = (int *)frame.insertionAnchor[1];
      node[0] = (int)frame.insertionAnchor;
      node[1] = (int)previous;
      previous[0] = (int)node;
      frame.insertionAnchor[1] = (int)node;
      RecordCallback callback = *(RecordCallback *)(*(byte **)service + 0x10);
      callback(service,0x26,0,frame.parentWord0,frame.parentWord1,frame.text,frame.recordWord30,frame.recordWord34);
      uint index = nextIndex++;
      parseResult = GetIndexedClDataList((void *)replyWord,(int *)&messageOrRecord,index);
    }
    RecordCallback callback = *(RecordCallback *)(*(byte **)service + 0x10);
    uint callbackResult = callback(service,0x26,0,0,0,(char *)&GRegistrationEmptyText,0,0);
    ExceptionList = frame.previousExceptionList;
    return (callbackResult & 0xffffff00) | 1;
  }
  parseResult = replyType - 0x27;
  if (parseResult != 0) {
    ExceptionList = frame.previousExceptionList;
    return parseResult & 0xffffff00;
  }
  parseResult = GetIndexedClDataList(messageOrRecord,(int *)&replyWord,1);
  if ((byte)parseResult == 0) {
    ExceptionList = frame.previousExceptionList;
    return parseResult;
  }
  parseResult = CopyIndexedBytesExact((void *)replyWord,&frame.scalarStatus,4,0);
  if ((byte)parseResult == 0) {
    ExceptionList = frame.previousExceptionList;
    return parseResult;
  }
  RecordCallback callback = *(RecordCallback *)(*(byte **)service + 0x10);
  uint callbackResult = callback(service,0x27,frame.scalarStatus,-1,0,(char *)&GRegistrationEmptyText,0,0);
  ExceptionList = frame.previousExceptionList;
  return (callbackResult & 0xffffff00) | 1;
}

// Releases only the pending record allocation at inherited parent EBP-0x34 when construction unwinds.
// R6GameService.dll @ 10066180 : private unwind ABI; CALL allocator tail wrapper, then RET.
__declspec(naked) void __cdecl FreePendingRegistrationReplyRecord(void)
{
  __asm {
    mov eax,dword ptr [ebp-0x34]
    push eax
    call R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Installs the record-reply allocation FuncInfo and tail-transfers to the shared C++ frame handler.
// R6GameService.dll @ 1006618a : private exception-handler ABI; EAX=0x100804a0.
__declspec(naked) void __cdecl RegistrationRecordReplyExceptionHandler(void)
{
  __asm {
    mov eax,R6GameServiceAddresses::RegistrationRecordReplyExceptionHandlerFunctionInfo
    jmp R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native local words shared by match start and finish, from logical parent EBP-0x28 through EBP-4.
struct RegistrationMatchFrame {
  uint scratchWord; // Pending payload pointer, then opcode integer, then contents pointer during cleanup.
  uint envelope[6];
  void *previousExceptionList;
  void *handler;
  uint state;
};

// The sentinel-release helper leaves allocator residue in EAX despite its semantic void declaration.
typedef uint (__fastcall *MatchStorageReleaseStatus)(int *);

// Queues match start from the cached group identifier and supplied match identifier.
// R6GameService.dll @ 10030e50 : ECX service, RET 4; raw cleanup-upper/queue-low EAX.
uint __thiscall SendRegistrationMatchStart(void *service,int matchId)
{
  RegistrationMatchFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistrationMatchExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.scratchWord = 0;
  if (*(void **)((byte *)service + 0x124) == nullptr || *((byte *)service + 0x9a) == 0) {
    uint failureResult;
    __asm {
      xor eax,eax
      mov ecx,service
      call R6GameServiceAddresses::ClearSecondaryServiceState
      mov failureResult,eax
    }
    ExceptionList = frame.previousExceptionList;
    return failureResult & 0xffffff00;
  }
  frame.envelope[1] = (uint)&ClDataListBaseOffsets;
  frame.envelope[5] = (uint)&ClDataListInnerBaseOffsets;
  frame.envelope[2] = 3;
  frame.envelope[0] = (uint)&PTR_LAB;
  frame.state = 0;
  InitializePayloadListSentinel(frame.envelope + 4,0);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.envelope[3] = (uint)&clDataListPTR_LAB;
  frame.state = 1;
  uint *payload = (uint *)AllocateGameServiceBytes(0x18);
  frame.scratchWord = (uint)payload;
  if (payload != nullptr) {
    payload[1] = (uint)&ClDataListBaseOffsets;
    payload[5] = (uint)&ClDataListInnerBaseOffsets;
    payload[2] = 3;
    payload[0] = (uint)&PTR_LAB;
    frame.state = 3;
    InitializePayloadListSentinel(payload + 4,0);
    payload[3] = (uint)&clDataListPTR_FUN2;
    payload[0] = (uint)&clDataListPTR_FUN;
    payload[3] = (uint)&clDataListPTR_LAB;
  }
  frame.state = 1;
  AppendClDataListSignedDecimal(payload,(byte *)service + 0x12c);
  AppendClDataListSignedDecimal(payload,&matchId);
  frame.scratchWord = 0x11;
  AppendClDataListSignedDecimal(frame.envelope,&frame.scratchWord);
  AppendClDataListPointer(frame.envelope,payload);
  uint queueResult = QueueRecordUsingStoredHeaderFields(
      *(void **)((byte *)service + 0x124),0xd1,frame.envelope);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.state = 4;
  frame.scratchWord = (uint)(frame.envelope + 3);
  frame.envelope[3] = (uint)&clDataListPTR_FUN2;
  frame.state = 5;
  InvokePointerListClearRange((int *)(frame.envelope + 3));
  frame.state = 4;
  MatchStorageReleaseStatus releaseStorage =
      (MatchStorageReleaseStatus)ReleaseNodesAndSentinel;
  uint cleanupResult = releaseStorage((int *)(frame.envelope + 4));
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | (byte)queueResult;
}

// Queues match finish from the cached group identifier.
// R6GameService.dll @ 10030fe0 : ECX service, RET; raw cleanup-upper/queue-low EAX.
uint __thiscall SendRegistrationMatchFinish(void *service)
{
  RegistrationMatchFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)RegistrationMatchExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.scratchWord = 0;
  if (*(void **)((byte *)service + 0x124) == nullptr || *((byte *)service + 0x9a) == 0) {
    uint failureResult;
    __asm {
      xor eax,eax
      mov ecx,service
      call R6GameServiceAddresses::ClearSecondaryServiceState
      mov failureResult,eax
    }
    ExceptionList = frame.previousExceptionList;
    return failureResult & 0xffffff00;
  }
  frame.envelope[1] = (uint)&ClDataListBaseOffsets;
  frame.envelope[5] = (uint)&ClDataListInnerBaseOffsets;
  frame.envelope[2] = 3;
  frame.envelope[0] = (uint)&PTR_LAB;
  frame.state = 0;
  InitializePayloadListSentinel(frame.envelope + 4,0);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.envelope[3] = (uint)&clDataListPTR_LAB;
  frame.state = 1;
  uint *payload = (uint *)AllocateGameServiceBytes(0x18);
  frame.scratchWord = (uint)payload;
  if (payload != nullptr) {
    payload[1] = (uint)&ClDataListBaseOffsets;
    payload[5] = (uint)&ClDataListInnerBaseOffsets;
    payload[2] = 3;
    payload[0] = (uint)&PTR_LAB;
    frame.state = 3;
    InitializePayloadListSentinel(payload + 4,0);
    payload[3] = (uint)&clDataListPTR_FUN2;
    payload[0] = (uint)&clDataListPTR_FUN;
    payload[3] = (uint)&clDataListPTR_LAB;
  }
  frame.state = 1;
  AppendClDataListSignedDecimal(payload,(byte *)service + 0x12c);
  frame.scratchWord = 0x2d;
  AppendClDataListSignedDecimal(frame.envelope,&frame.scratchWord);
  AppendClDataListPointer(frame.envelope,payload);
  uint queueResult = QueueRecordUsingStoredHeaderFields(
      *(void **)((byte *)service + 0x124),0xd1,frame.envelope);
  frame.envelope[0] = (uint)&clDataListPTR_FUN;
  frame.state = 4;
  frame.scratchWord = (uint)(frame.envelope + 3);
  frame.envelope[3] = (uint)&clDataListPTR_FUN2;
  frame.state = 5;
  InvokePointerListClearRange((int *)(frame.envelope + 3));
  frame.state = 4;
  MatchStorageReleaseStatus releaseStorage =
      (MatchStorageReleaseStatus)ReleaseNodesAndSentinel;
  uint cleanupResult = releaseStorage((int *)(frame.envelope + 4));
  ExceptionList = frame.previousExceptionList;
  return (cleanupResult & 0xffffff00) | (byte)queueResult;
}

// Checks provider/status gates, processes provider work, and drains messages only on nonzero provider AL.
// R6GameService.dll @ 10031160 : ECX service, RET; absent/inactive cleanup differs from provider-processing failure.
__declspec(naked) uint __thiscall PollSecondaryRegistrationService(void *service)
{
  __asm {
    push esi
    mov esi,ecx
    mov ecx,dword ptr [esi+0x124]
    test ecx,ecx
    jz registration_secondary_clear
    mov al,byte ptr [esi+0x9a]
    test al,al
    jnz registration_secondary_poll
  registration_secondary_clear:
    mov ecx,esi
    call R6GameServiceAddresses::ClearSecondaryServiceState
  registration_secondary_failed:
    xor al,al
    pop esi
    ret
  registration_secondary_poll:
    call R6GameServiceAddresses::DispatchProviderReceiveState
    test al,al
    jz registration_secondary_failed
    mov ecx,esi
    call R6GameServiceAddresses::DrainSecondaryRegistrationMessages
    mov al,1
    pop esi
    ret
  }
}

// Eight bytes of native drain scratch; the word's upper half is not initialized before its low-half parser write.
struct SecondaryRegistrationDrainLocals {
  void *nestedList;
  uint nestedTypeWord;
};

// Native internal-block target table at 100312b0, indexed by the selector map in DrainSecondaryRegistrationMessages.
// R6GameService.dll data @ 100312b0 : native storage identity retained.
static const uint GSecondaryRegistrationDispatchTargets[8] = {
  R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase1, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase2, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase3, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase4,
  R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase5, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase6, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase7, R6GameServiceAddresses::GSecondaryRegistrationDispatchTargetsCase8
};

// Native selector map at 100312d0 for low-word values 0x26 through 0x45; target 7 performs common cleanup.
// R6GameService.dll data @ 100312d0 : native storage identity retained.
static const byte GSecondaryRegistrationSelectorMap[32] = {
  0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 2, 7, 7,
  3, 7, 7, 4, 7, 7, 7, 7, 7, 7, 7, 7, 5, 7, 7, 6
};

// Dequeues and routes records, preserving direct-reply fall-through to envelope decoding and live provider reloads.
// R6GameService.dll @ 100311a0 : ECX service, RET; every normal exit retains the terminal null dequeue EAX=0.
uint __fastcall DrainSecondaryRegistrationMessages(void *service)
{
  SecondaryRegistrationDrainLocals locals;
  typedef void *(__thiscall *TakeRecord)(void *);
  typedef void (__thiscall *DeleteRecord)(void *,uint);
  void *provider = *(void **)((byte *)service + 0x124);
  TakeRecord takeRecord = *(TakeRecord *)(*(byte **)provider + 0x0c);
  void *record = takeRecord(provider);
  while (record != nullptr) {
    byte recordType = *((byte *)record + 0x0d);
    if (recordType == 0x26 || recordType == 0x27) {
      uint directReplyWord = ((uint)record & 0xffffff00) | recordType;
      RouteSecondaryRegistrationReply(service,directReplyWord,*(void **)((byte *)record + 0x14));
    }
    if (recordType == 0xd1 || recordType == 0x26 || recordType == 0x27) {
      uint parseResult = ReadIndexedWord(*(void **)((byte *)record + 0x14),(undefined2 *)&locals.nestedTypeWord,0);
      if ((byte)parseResult != 0) {
        parseResult = GetIndexedClDataList(*(void **)((byte *)record + 0x14),(int *)&locals.nestedList,1);
        if ((byte)parseResult != 0) {
          switch (locals.nestedTypeWord & 0xffff) {
          case 0x26:
          case 0x27:
            RouteSecondaryRegistrationReply(service,locals.nestedTypeWord,locals.nestedList);
            break;
          case 0x32:
            DispatchSecondaryPayloadNotification(service,locals.nestedList);
            break;
          case 0x33:
            DispatchSecondaryTextNotification(service,locals.nestedList);
            break;
          case 0x36:
            DispatchTwentyFieldNotification(service,locals.nestedList);
            break;
          case 0x39:
            DispatchSecondaryIntegerPair(service,locals.nestedList);
            break;
          case 0x42:
            DispatchSecondaryBinaryTextNotification(service,locals.nestedList);
            break;
          case 0x45:
            DispatchSecondaryTextAndWord(service,locals.nestedList);
            break;
          }
        }
      }
    }
    DeleteRecord deleteRecord = *(DeleteRecord *)*(void **)record;
    deleteRecord(record,1);
    provider = *(void **)((byte *)service + 0x124);
    takeRecord = *(TakeRecord *)(*(byte **)provider + 0x0c);
    record = takeRecord(provider);
  }
  return 0;
}

// Resets the partially constructed match envelope at inherited parent EBP-0x24.
// R6GameService.dll @ 10066280 : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl ResetMatchEnvelopeBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys the completed match envelope at inherited parent EBP-0x24.
// R6GameService.dll @ 10066288 : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl DestroyMatchEnvelope(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Frees the pending heap payload saved at inherited parent EBP-0x28.
// R6GameService.dll @ 10066290 : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl FreeMatchPendingPayload(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x28]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Resets the heap payload through its saved pointer at parent EBP-0x28.
// R6GameService.dll @ 1006629a : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl ResetMatchPendingPayloadBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets the envelope base during staged normal destruction.
// R6GameService.dll @ 100662a2 : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl ResetMatchCleanupEnvelopeBase(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Adjusts the saved contents pointer and tail-releases storage during contents-cleanup unwinding.
// R6GameService.dll @ 100662aa : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl ReleaseMatchEnvelopeStorage(void)
{
  __asm {
    cmp    dword ptr [ebp-0x28],0x0
    je match_cleanup_storage_null
    mov    eax,dword ptr [ebp-0x28]
    add    eax,0x4
    mov    dword ptr [ebp-0x54],eax
    jmp match_cleanup_storage_release
  match_cleanup_storage_null:
    mov    dword ptr [ebp-0x54],0x0
  match_cleanup_storage_release:
    mov    ecx,dword ptr [ebp-0x54]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Installs shared match FuncInfo 0x10080624 and tail-transfers to the C++ frame handler.
// R6GameService.dll @ 100662d1 : private inherited-frame ABI; native stack/receiver and tail operands retained.
__declspec(naked) void __cdecl RegistrationMatchExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RegistrationMatchExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native nested-reply internal-block targets at 100313a0; selector-map index 4 returns without delegation.
// R6GameService.dll data @ 100313a0 : native storage identity retained.
static const uint GNestedRegistrationReplyTargets[5] = {
  R6GameServiceAddresses::GNestedRegistrationReplyTargetsCase1, R6GameServiceAddresses::GNestedRegistrationReplyTargetsCase2, R6GameServiceAddresses::GNestedRegistrationReplyTargetsCase3, R6GameServiceAddresses::GNestedRegistrationReplyTargetsCase4, R6GameServiceAddresses::GNestedRegistrationReplyTargetsCase5
};

// Native selector map at 100313b4 for decoded low-word operations 0x11 through 0xd2 inclusive.
// R6GameService.dll data @ 100313b4 : native storage identity retained.
static const byte GNestedRegistrationReplySelectorMap[0xc2] = {
  0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 3
};

// Routes the decoded nested operation, substituting null payload when nested-list retrieval fails.
// R6GameService.dll @ 100312f0 : ECX service, RET 8; scratch starts with the service pointer before a low-word write.
void __thiscall RouteSecondaryRegistrationReply(void *service,uint replyWord,void *message)
{
  uint operationWord = (uint)service;
  uint parseResult = ReadIndexedWord(message,(undefined2 *)&operationWord,0);
  if ((byte)parseResult == 0) return;
  parseResult = GetIndexedClDataList(message,(int *)&message,1);
  if ((byte)parseResult == 0) message = nullptr;
  switch (operationWord & 0xffff) {
  case 0x11:
    DispatchRegistrationMatchStartReply(service,replyWord,message);
    return;
  case 0x1f:
    DispatchRegistrationUpdateReply(service,replyWord,message);
    return;
  case 0x2d:
    DispatchRegistrationMatchFinishReply(service,replyWord,message);
    return;
  case 0xd2:
    DispatchSecondaryRegistrationLoginReply(service,replyWord,message);
    return;
  }
}

// Reports an update value/status pair; other reply types still report the full reply word with zero values.
// R6GameService.dll @ 10031480 : ECX service, RET 8; null payload returns before parsing or owner slot +0x18.
void __thiscall DispatchRegistrationUpdateReply(void *service,uint replyWord,void *message)
{
  int statusWord = 0;
  int valueWord = 0;
  if (message == nullptr) return;
  uint parseResult;
  if ((byte)replyWord == 0x26) {
    parseResult = ReadIndexedInt32(message,&valueWord,0);
    if ((byte)parseResult == 0) return;
  } else if ((byte)replyWord == 0x27) {
    parseResult = ReadIndexedInt32(message,&statusWord,0);
    if ((byte)parseResult == 0) return;
    parseResult = ReadIndexedInt32(message,&valueWord,1);
    if ((byte)parseResult == 0) return;
  }
  typedef void (__thiscall *ReplyCallback)(void *,uint,int,int);
  ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x18);
  callback(service,replyWord,statusWord,valueWord);
}

// Stores/reports lobby-server and group identifiers on type 0x26; type 0x27 reports status and parsed/default IDs.
// R6GameService.dll @ 100314f0 : ECX service, RET 8; type 0x26 reads are unchecked and vtable loads precede stores.
void __thiscall DispatchSecondaryRegistrationLoginReply(void *service,uint replyWord,void *message)
{
  int lobbyServerId = 0;
  int groupId = 0;
  typedef void (__thiscall *ReplyCallback)(void *,uint,uint,int,int);
  if ((byte)replyWord == 0x26) {
    ReadIndexedInt32(message,&lobbyServerId,0);
    ReadIndexedInt32(message,&groupId,1);
    byte *callbackTable = *(byte **)service;
    *(int *)((byte *)service + 0x12c) = groupId;
    *(int *)((byte *)service + 0x128) = lobbyServerId;
    ReplyCallback callback = *(ReplyCallback *)(callbackTable + 0x14);
    callback(service,0x26,0,lobbyServerId,groupId);
  } else if ((byte)replyWord == 0x27) {
    uint parseResult = ReadIndexedInt32(message,(int *)&replyWord,0);
    if ((byte)parseResult == 0) return;
    ReadIndexedInt32(message,&lobbyServerId,1);
    ReadIndexedInt32(message,&groupId,2);
    ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x14);
    callback(service,0x27,replyWord,lobbyServerId,groupId);
  }
}

// Reports match-start value/status while forwarding the original full reply word to owner slot +0x24.
// R6GameService.dll @ 100316d0 : ECX service, RET 8; only type 0x27 field 0 gates its callback.
void __thiscall DispatchRegistrationMatchStartReply(void *service,uint replyWord,void *message)
{
  int valueWord = 0;
  uint originalReplyWord = replyWord;
  typedef void (__thiscall *ReplyCallback)(void *,uint,uint,int);
  if ((byte)replyWord == 0x26) {
    ReadIndexedInt32(message,&valueWord,0);
    ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x24);
    callback(service,originalReplyWord,0,valueWord);
  } else if ((byte)replyWord == 0x27) {
    replyWord = 0;
    uint parseResult = ReadIndexedInt32(message,(int *)&replyWord,0);
    if ((byte)parseResult == 0) return;
    ReadIndexedInt32(message,&valueWord,1);
    ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x24);
    callback(service,originalReplyWord,replyWord,valueWord);
  }
}

// Reports match finish using normalized type 0x26/0x27 constants and parsed/default value words.
// R6GameService.dll @ 10031790 : ECX service, RET 8; type 0x27 field 0 gates the owner slot +0x2c callback.
void __thiscall DispatchRegistrationMatchFinishReply(void *service,uint replyWord,void *message)
{
  int valueWord = 0;
  typedef void (__thiscall *ReplyCallback)(void *,uint,uint,int);
  if ((byte)replyWord == 0x26) {
    ReadIndexedInt32(message,&valueWord,0);
    ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x2c);
    callback(service,0x26,0,valueWord);
  } else if ((byte)replyWord == 0x27) {
    replyWord = 0;
    uint parseResult = ReadIndexedInt32(message,(int *)&replyWord,0);
    if ((byte)parseResult == 0) return;
    ReadIndexedInt32(message,&valueWord,1);
    ReplyCallback callback = *(ReplyCallback *)(*(byte **)service + 0x2c);
    callback(service,0x27,replyWord,valueWord);
  }
}

// Reports indexed text only when it fits the native sixteen-byte stack buffer, including its terminator.
// R6GameService.dll @ 10031760 : ECX service, RET 4; bounded field 0 text reaches owner slot +0x28.
void __thiscall DispatchSecondaryTextNotification(void *service,void *message)
{
  char text[0x10];
  if (!(byte)CopyIndexedStringBounded(message,text,0,0x10)) return;
  typedef void (__thiscall *TextCallback)(void *,char *);
  TextCallback callback = *(TextCallback *)(*(byte **)service + 0x28);
  callback(service,text);
}

// Reports the second parsed integer before the first; failed field 0 leaves its original input-pointer word.
// R6GameService.dll @ 10031810 : ECX service, RET 4; only the field 1 parse result gates owner slot +0x30.
void __thiscall DispatchSecondaryIntegerPair(void *service,void *messageOrFirstWord)
{
  void *sourceMessage = messageOrFirstWord;
  uint secondWord = (uint)service;
  ReadIndexedInt32(sourceMessage,(int *)&messageOrFirstWord,0);
  uint parseResult = ReadIndexedInt32(sourceMessage,(int *)&secondWord,1);
  if ((byte)parseResult == 0) return;
  typedef void (__thiscall *PairCallback)(void *,uint,uint);
  PairCallback callback = *(PairCallback *)(*(byte **)service + 0x30);
  callback(service,secondWord,(uint)messageOrFirstWord);
}

// Copies unbounded field 0 text, then overwrites only the input word's low half before reporting both fields.
// R6GameService.dll @ 10031850 : ECX service, RET 4; sixteen-byte text buffer and full mutated word reach slot +0x34.
void __thiscall DispatchSecondaryTextAndWord(void *service,void *messageOrWord)
{
  void *sourceMessage = messageOrWord;
  char text[0x10];
  uint parseResult = CopyIndexedClDataString(sourceMessage,(int)text,0);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedWord(sourceMessage,(undefined2 *)&messageOrWord,1);
  if ((byte)parseResult == 0) return;
  typedef void (__thiscall *TextWordCallback)(void *,char *,uint);
  TextWordCallback callback = *(TextWordCallback *)(*(byte **)service + 0x34);
  callback(service,text,(uint)messageOrWord);
}

// Native lobby-login globals: reply byte is zero-extended; ID roles follow selected callback logs.
// R6GameService.dll data @ 10093b0c : native storage identity retained.
extern uint GSecondaryLobbyLoginReplyType;
// R6GameService.dll data @ 10093b34 : native storage identity retained.
extern int GSecondaryLobbyServerId;
// R6GameService.dll data @ 10093b18 : native storage identity retained.
extern int GSecondaryGroupId;

// Tail-forwards four login-result words to the currently installed callback, retaining the native EDX reload/store.
// R6GameService.dll @ 1002f620 : ECX service; stack cleanup is delegated to the callback at service +0x144.
__declspec(naked) void __thiscall ForwardSecondaryLobbyLoginResults(
    void *service,uint replyWord,uint reason,int lobbyServerId,int groupId)
{
  __asm {
    mov edx,dword ptr [esp+4]
    mov dword ptr [esp+4],edx
    jmp dword ptr [ecx+0x144]
  }
}

// Saves lobby-login reply type and identifiers, optionally logs the IDs, and always logs type-0x27 failure reason.
// R6GameService.dll @ 10013210 : RET16; cached reply/log target, current failure reason and physical EAX result.
__declspec(naked) uint __stdcall ReceiveSecondaryLobbyLoginResults(uint replyWord,uint reason,int lobbyServerId,int groupId)
{
  byte *nativeFrame;
  uint logging,reply,group;
  __asm {
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    movzx  eax,bl
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    nativeFrame,esp
    mov    logging,ecx
    mov    reply,eax
    mov    group,esi
  }
  *(uint *)R6GameServiceAddresses::GSecondaryLobbyLoginReplyType = reply;
  uint lobby = *(uint *)(nativeFrame + 0x14);
  __asm {
    push   edi
  }
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  *(uint *)R6GameServiceAddresses::GSecondaryLobbyServerId = lobby;
  *(uint *)R6GameServiceAddresses::GSecondaryGroupId = group;
  uint rawEax = lobby;
  if (logging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerLoginResultsILobbyServerIDI,lobby);
    device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerLoginResultsIGroupIDI,group);
  }
  if (reply == 0x27) {
    uint currentReason = *(uint *)(nativeFrame + 0x10);
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = logger(device,
        (const TCHAR *)R6GameServiceAddresses::WideTextCallbackRegServerRcvLobbyServerLoginResultsFailedReasonI,currentReason);
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    pop    ebx
    ret    0x10
  }
}

// Native 0x128-byte local region: ushort outputs occupy whole uninitialized words and text buffers retain padding.
struct SecondaryPayloadNotificationLocals {
  uint byteCount;
  void *binary;
  uint field1Word;
  uint field6Word;
  char text0[0x10];
  char text4[0x81];
  byte padding4[3];
  char text3[0x81];
  byte padding3[3];
};

// Parses six selected fields, copies binary field 5 with a trailing zero, and reports seven callback arguments.
// R6GameService.dll @ 100315b0 : ECX service, RET 4; ushort readers leave upper output halves untouched.
void __thiscall DispatchSecondaryPayloadNotification(void *service,void *message)
{
  SecondaryPayloadNotificationLocals frame;
  void *buffer = nullptr;
  frame.binary = nullptr;
  frame.byteCount = 0;
  if (!(byte)CopyIndexedStringBounded(message,frame.text0,0,0x10)) return;
  uint parseResult = ReadIndexedWord(message,(undefined2 *)&frame.field1Word,1);
  if ((byte)parseResult == 0) return;
  if (!(byte)CopyIndexedStringBounded(message,frame.text3,3,0x81)) return;
  if (!(byte)CopyIndexedStringBounded(message,frame.text4,4,0x81)) return;
  parseResult = GetIndexedClDataBin(message,(int *)&frame.binary,5);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedWord(message,(undefined2 *)&frame.field6Word,6);
  if ((byte)parseResult == 0) return;
  typedef uint (__thiscall *ByteCountMethod)(void *);
  typedef uint (__thiscall *CopyBytesMethod)(void *,void *,uint *);
  ByteCountMethod byteCount = *(ByteCountMethod *)(*(byte **)frame.binary + 0x14);
  frame.byteCount = byteCount(frame.binary);
  if (frame.byteCount != 0) {
    buffer = (void *)AllocateGameServiceBytes(frame.byteCount + 1);
    CopyBytesMethod copyBytes = *(CopyBytesMethod *)(*(byte **)frame.binary + 0x18);
    copyBytes(frame.binary,buffer,&frame.byteCount);
    *((byte *)buffer + frame.byteCount) = 0;
  }
  typedef void (__thiscall *NotificationCallback)(void *,char *,uint,char *,char *,void *,uint,uint);
  NotificationCallback callback = *(NotificationCallback *)(*(byte **)service + 0x20);
  callback(service,frame.text0,frame.field1Word,frame.text3,frame.text4,buffer,frame.byteCount,frame.field6Word);
  TailFreeThroughGlobalAllocator(buffer);
}

// Native 0x204-byte local region, including saved receiver, parser outputs and contiguous text storage.
struct SecondaryTwentyFieldLocals {
  uint byteCount;
  void *binary;
  int field4;
  int field2;
  int field15;
  uint field0Word;
  int field13;
  void *savedReceiver;
  int field11;
  int field3;
  int field5;
  int field14;
  uint field6Word;
  int field12;
  char text7[0x10];
  char text8[0x24];
  char text17[0x24];
  char text1[0x24];
  char text9[0x24];
  char text16[0x24];
  char text19[0x84];
  char text18[0x84];
};

// Parses fields 0..19, copies binary field 10, and substitutes text18 when text19 equals the live default text.
// R6GameService.dll @ 100318a0 : ECX receiver, RET 4; twenty fields become twenty-one owner slot +0x38 arguments.
void __thiscall DispatchTwentyFieldNotification(void *receiver,void *message)
{
  SecondaryTwentyFieldLocals frame;
  void *buffer = nullptr;
  frame.savedReceiver = receiver;
  frame.binary = nullptr;
  frame.byteCount = 0;
  uint parseResult = ReadIndexedWord(message,(undefined2 *)&frame.field0Word,0);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text1,1);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field2,2);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field3,3);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field4,4);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field5,5);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedWord(message,(undefined2 *)&frame.field6Word,6);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text7,7);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text8,8);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text9,9);
  if ((byte)parseResult == 0) return;
  parseResult = GetIndexedClDataBin(message,(int *)&frame.binary,10);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field11,11);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field12,12);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field13,13);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field14,14);
  if ((byte)parseResult == 0) return;
  parseResult = ReadIndexedInt32(message,&frame.field15,15);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text16,16);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text17,17);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text18,18);
  if ((byte)parseResult == 0) return;
  parseResult = CopyIndexedClDataString(message,(int)frame.text19,19);
  if ((byte)parseResult == 0) return;
  typedef uint (__thiscall *ByteCountMethod)(void *);
  typedef uint (__thiscall *CopyBytesMethod)(void *,void *,uint *);
  ByteCountMethod byteCount = *(ByteCountMethod *)(*(byte **)frame.binary + 0x14);
  frame.byteCount = byteCount(frame.binary);
  if (frame.byteCount != 0) {
    buffer = (void *)AllocateGameServiceBytes(frame.byteCount + 1);
    CopyBytesMethod copyBytes = *(CopyBytesMethod *)(*(byte **)frame.binary + 0x18);
    copyBytes(frame.binary,buffer,&frame.byteCount);
    *((byte *)buffer + frame.byteCount) = 0;
  }
  if (strcmp(frame.text19,(const char *)&GRegistrationEmptyText) == 0) strncpy(frame.text19,frame.text18,0x81);
  typedef void (__thiscall *NotificationCallback)(void *,uint,char *,int,int,int,int,uint,char *,char *,char *,
      void *,uint,int,int,int,int,int,char *,char *,char *,char *);
  NotificationCallback callback = *(NotificationCallback *)(*(byte **)frame.savedReceiver + 0x38);
  callback(frame.savedReceiver,frame.field0Word,frame.text1,frame.field2,frame.field3,frame.field4,frame.field5,
           frame.field6Word,frame.text7,frame.text8,frame.text9,buffer,frame.byteCount,frame.field11,frame.field12,
           frame.field13,frame.field14,frame.field15,frame.text16,frame.text17,frame.text18,frame.text19);
  TailFreeThroughGlobalAllocator(buffer);
}

// Native 0x14-byte local region; the original message argument separately becomes the payload count/output slot.
struct SecondaryBinaryTextLocals {
  void *binary;
  char text0[0x10];
};

// Reports bounded field 0 text and a zero-terminated copy of field 1 binary data through owner slot +0x3c.
// R6GameService.dll @ 10031bb0 : ECX service, RET 4; copy status is ignored and the updated count supplies the terminator.
void __thiscall DispatchSecondaryBinaryTextNotification(void *service,void *messageOrLength)
{
  SecondaryBinaryTextLocals frame;
  void *buffer = nullptr;
  if (!(byte)CopyIndexedStringBounded(messageOrLength,frame.text0,0,0x10)) return;
  uint parseResult = GetIndexedClDataBin(messageOrLength,(int *)&frame.binary,1);
  if ((byte)parseResult == 0) return;
  typedef uint (__thiscall *ByteCountMethod)(void *);
  typedef uint (__thiscall *CopyBytesMethod)(void *,void *,uint *);
  ByteCountMethod byteCount = *(ByteCountMethod *)(*(byte **)frame.binary + 0x14);
  messageOrLength = (void *)byteCount(frame.binary);
  if (messageOrLength != nullptr) {
    buffer = (void *)AllocateGameServiceBytes((uint)messageOrLength + 1);
    CopyBytesMethod copyBytes = *(CopyBytesMethod *)(*(byte **)frame.binary + 0x18);
    copyBytes(frame.binary,buffer,(uint *)&messageOrLength);
    *((byte *)buffer + (uint)messageOrLength) = 0;
  }
  typedef void (__thiscall *NotificationCallback)(void *,char *,void *,uint);
  NotificationCallback callback = *(NotificationCallback *)(*(byte **)service + 0x3c);
  callback(service,frame.text0,buffer,(uint)messageOrLength);
  TailFreeThroughGlobalAllocator(buffer);
}

// Relocated CRegisterServerCB member 1002f460: CRegisterServerCB.cpp.

// Relocated CRegisterServerCB member 1002f580: CRegisterServerCB.cpp.

// Relocated CRegisterServerCB member 1002f5b0: CRegisterServerCB.cpp.

// Relocated CRegisterServer member 1002f760: CRegisterServer.cpp.

// Relocated CRegisterServer member 1002f820: CRegisterServer.cpp.

// Relocated CRegisterServer member 1002f840: CRegisterServer.cpp.

// For inherited construction bitmap mask1, forwards saved owner+170 to shared native no-op; other flags remain.
// R6GameService.dll @ 10065ee0 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindRegistrationBaseFlag1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch15
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x170
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch15:
    ret
  }
}

// For inherited construction bitmap mask2, resets saved owner+170 allocation-base table; otherwise returns masked EAX.
// R6GameService.dll @ 10065efd : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindRegistrationBaseFlag2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x2
    test   eax,eax
    je     Branch16
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x170
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  Branch16:
    ret
  }
}

// Selects the two-state registration base-construction map and tail-transfers to external frame dispatch.
// R6GameService.dll @ 10065f1a : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRegistrationConstructionLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructRegistrationServiceExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Releases allocation saved at inherited EBP-10 through actual shared release tail; no ownership slot clear.
// R6GameService.dll @ 10065f30 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseRegistrationPendingAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects shared one-state pending-allocation map and tail-transfers to external frame dispatch.
// R6GameService.dll @ 10065f3a : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SharedRegistrationAllocationExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::registration_serviceSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 100802a8 : exact lifetime map/info words for the associated native registration/list body.
const R6GameServiceNative::UnwindEntry ConstructRegistrationServiceUnwindMap[2] = {
  {-1, R6GameServiceAddresses::UnwindRegistrationBaseFlag1},
  {0x0, R6GameServiceAddresses::UnwindRegistrationBaseFlag2},
};

// R6GameService.dll data @ 100802b8 : exact lifetime map/info words for the associated native registration/list body.
// R6GameService.dll data @ 100802a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructRegistrationServiceExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ConstructRegistrationServiceUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 100802d4 : exact lifetime map/info words for the associated native registration/list body.
const R6GameServiceNative::UnwindEntry registration_serviceSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ReleaseRegistrationPendingAllocation},
};

// R6GameService.dll data @ 100802dc : exact lifetime map/info words for the associated native registration/list body.
// R6GameService.dll data @ 100802d4 : native storage identity retained.
const R6GameServiceNative::FuncInfo registration_serviceSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::registration_serviceSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 10076ccc : nonfunction virtual-base offset table, allocation base at owner+170.
const R6GameServiceNative::BaseOffsets<2> GRegistrationBaseOffsets = {-0x130, {0x40, 0x40}};

// R6GameService.dll data @ 10076cc4 : nonfunction secondary virtual-base offset table.
const R6GameServiceNative::BaseOffsets<1> GRegistrationSecondaryOffsets = {-4, {-4}};

// Installs ten registration callbacks through unguarded singleton adapters in order; returns final callback word residue.
// R6GameService.dll @ 100136d0 : no rollback; each singleton adapter reloads its current service receiver.
uint __cdecl InstallRegistrationServiceCallbacks(void)
{
  using SetABI = uint (__stdcall *)(void *);
  ((SetABI)R6GameServiceAddresses::SetRegistrationCallback)
      ((void *)R6GameServiceAddresses::RegServerRcv_LoginRouterResult);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback)
      ((void *)R6GameServiceAddresses::RegServerRcv_LoginDisconnection);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback2)
      ((void *)R6GameServiceAddresses::RegServerRcv_RegisterServerResult);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback3)
      ((void *)R6GameServiceAddresses::RegServerRcv_RequestParentGroupResult);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback4)
      ((void *)R6GameServiceAddresses::ReceiveSecondaryLobbyLoginResults);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback6)
      ((void *)R6GameServiceAddresses::RegServerRcv_LobbyServerDisconnection);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback7)
      ((void *)R6GameServiceAddresses::RegServerRcv_LobbyServerNewMember);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback5)
      ((void *)R6GameServiceAddresses::RegServerRcv_LobbyServerUpdateGroupSettingsResults);
  ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback8)
      ((void *)R6GameServiceAddresses::RegServerRcv_LobbyServerMatchStartReply);
  return ((SetABI)R6GameServiceAddresses::registration_service_SetRegistrationCallback9)
      ((void *)R6GameServiceAddresses::RegServerRcv_LobbyServerMatchFinishReply);
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f5d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardRegistrationCallback(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x134]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f5e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback(void *receiver)
{
  __asm {
    jmp DWORD PTR [ecx+0x138]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f5f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback2(void *receiver)
{
  __asm {
    mov edx,DWORD PTR [esp+0x14]
    mov DWORD PTR [esp+0x14],edx
    mov edx,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],edx
    jmp DWORD PTR [ecx+0x13c]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f610 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback3(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x140]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f630 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback4(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x148]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f640 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback5(void *receiver)
{
  __asm {
    jmp DWORD PTR [ecx+0x14c]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f650 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback6(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x1c]
    mov edx,DWORD PTR [esp+0x8]
    mov DWORD PTR [esp+0x1c],eax
    mov DWORD PTR [esp+0x8],edx
    jmp DWORD PTR [ecx+0x150]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f670 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback7(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x158]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f680 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback8(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x15c]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f690 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback9(void *receiver)
{
  __asm {
    jmp DWORD PTR [ecx+0x154]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f6a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback10(void *receiver)
{
  __asm {
    jmp DWORD PTR [ecx+0x160]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f6b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback11(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x8]
    mov DWORD PTR [esp+0x8],eax
    jmp DWORD PTR [ecx+0x164]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f6c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback12(void *receiver)
{
  __asm {
    mov eax,DWORD PTR [esp+0x1c]
    mov DWORD PTR [esp+0x1c],eax
    mov eax,DWORD PTR [esp+0x4]
    mov DWORD PTR [esp+0x4],eax
    jmp DWORD PTR [ecx+0x168]
  }
}

// Tail-forward current registration callback slot, retaining native stack-word self-load/stores and volatile residue.
// No null callback gate or own frame; callback owns argument cleanup/return convention. Event identifier unresolved.
// R6GameService.dll @ 1002f6e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall registration_service_ForwardRegistrationCallback13(void *receiver)
{
  __asm {
    jmp DWORD PTR [ecx+0x16c]
  }
}

// Subtract170 from adjusted registration-service receiver, then tail-transfer to canonical deleting destructor2f580.
// Preserve caller flag/return address; target owns lifetime and return. No extra destructor is invoked.
// R6GameService.dll @ 1002f750 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DeleteRegistrationServiceFromAdjustedBase(void *receiver)
{
  __asm {
    sub ecx,0x170
    jmp R6GameServiceAddresses::DeleteRegistrationService
  }
}

// Native virtual-table prefix: CRegisterServerCBVTableAdjusted368
// R6GameService.dll data @ 10076c7c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CRegisterServerCBVTableAdjusted368Record {
  R6GameServiceNative::Address DeleteRegistrationServiceFromAdjustedBase; // +0x00
};
const CRegisterServerCBVTableAdjusted368Record CRegisterServerCBVTableAdjusted368 = {
  R6GameServiceAddresses::DeleteRegistrationServiceFromAdjustedBase,
};

// Native virtual-table prefix: CRegisterServerCBVTable
// R6GameService.dll data @ 10076c84 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CRegisterServerCBVTableRecord {
  R6GameServiceNative::Address DeleteRegistrationService; // +0x00
  R6GameServiceNative::Address ForwardRegistrationCallback; // +0x04
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback; // +0x08
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback2; // +0x0c
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback3; // +0x10
  R6GameServiceNative::Address ForwardSecondaryLobbyLoginResults; // +0x14
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback4; // +0x18
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback5; // +0x1c
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback6; // +0x20
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback7; // +0x24
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback9; // +0x28
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback8; // +0x2c
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback10; // +0x30
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback11; // +0x34
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback12; // +0x38
  R6GameServiceNative::Address registration_service_ForwardRegistrationCallback13; // +0x3c
};
const CRegisterServerCBVTableRecord CRegisterServerCBVTable = {
  R6GameServiceAddresses::DeleteRegistrationService,
  R6GameServiceAddresses::ForwardRegistrationCallback,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback2,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback3,
  R6GameServiceAddresses::ForwardSecondaryLobbyLoginResults,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback4,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback5,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback6,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback7,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback9,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback8,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback10,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback11,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback12,
  R6GameServiceAddresses::registration_service_ForwardRegistrationCallback13,
};

// Native virtual-table prefix: CRegisterServerVTable
// R6GameService.dll data @ 10076cdc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CRegisterServerVTableRecord {
  R6GameServiceNative::Address DeleteRegistrationServiceState; // +0x00
  R6GameServiceNative::Address _purecall; // +0x04
  R6GameServiceNative::Address _purecall2; // +0x08
  R6GameServiceNative::Address _purecall3; // +0x0c
  R6GameServiceNative::Address _purecall4; // +0x10
  R6GameServiceNative::Address _purecall5; // +0x14
  R6GameServiceNative::Address _purecall6; // +0x18
  R6GameServiceNative::Address _purecall7; // +0x1c
  R6GameServiceNative::Address _purecall8; // +0x20
  R6GameServiceNative::Address _purecall9; // +0x24
  R6GameServiceNative::Address _purecall10; // +0x28
  R6GameServiceNative::Address _purecall11; // +0x2c
  R6GameServiceNative::Address _purecall12; // +0x30
  R6GameServiceNative::Address _purecall13; // +0x34
  R6GameServiceNative::Address _purecall14; // +0x38
  R6GameServiceNative::Address _purecall15; // +0x3c
};
const CRegisterServerVTableRecord CRegisterServerVTable = {
  R6GameServiceAddresses::DeleteRegistrationServiceState,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};
