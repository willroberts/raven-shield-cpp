#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007e734 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry ServerPing_PingManagerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007e744 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GPollPingManagerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -52,
  R6GameServiceAddresses::ServerPing_ServerPingCatch6},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ServerPing_ServerPingCatch7},
};
// R6GameService.dll data @ 1007e764 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock ServerPing_PingManagerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GPollPingManagerHandlers},
};
// R6GameService.dll data @ 1007e778 : selected guard/cleanup records.
// R6GameService.dll data @ 1007e734 : native storage identity retained.
const R6GameServiceNative::FuncInfo ServerPing_PingManagerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ServerPing_PingManagerUnwindMap,
  0x1,
  R6GameServiceAddresses::ServerPing_PingManagerTryMap,
  0x0,
  0x0,
};

// Starts at most five requests and scans replies until ten unsigned ticks elapse; singleResult limits this to one scan.
// Server records take output precedence. ID-matched invalid replies complete with ping1000 without setting success.
// Timeout uses the cached starting tick (>2000); valid replies subtract their embedded tick. No receive-length check.
// Request offsets: host+0x10c, socket+0x118, sent+0x11c, done+0x120, full ID+0x124, alternate flag+0x128.
// R6GameService.dll @ 10014440 : two stack arguments/RET8; native scratch preserves callback-visible locals.
__declspec(naked) uint __thiscall ServerPing::PingManager(FArray *serverRecords,int *singleResult)
{
  byte *nativeFrame;
  ServerPing *receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ServerPing_PingManagerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x438
    mov    nativeFrame,ebp
    mov    receiver,ecx
  }
  FArray *initialServers = *(FArray **)(nativeFrame + 8);
  __asm {
    push   ebx
    push   esi
    xor    esi,esi
  }
  __asm {
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
  }
  *(uint *)(nativeFrame - 4) = 0;
  *(int *)(nativeFrame - 0x28) = 16;
  bool empty = initialServers == 0 && *(int **)(nativeFrame + 0xc) == 0;
  if (!empty) {
    int initialCount = *(int *)((byte *)receiver + 4);
    *(uint *)(nativeFrame - 0x1c) = 0;
    empty = initialCount == 0;
  }
  if (empty) {
    __asm {
      xor    eax,eax
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret    0x8
    }
  }
  using SendABI = void (__thiscall *)(void *,int);
  using TickABI = uint (__stdcall *)(void);
  using EqualABI = int (__thiscall *)(const FString *,const FString *);
  using ReceiveABI = int (__stdcall *)(uint,void *,int,int,void *,int *);
  using CloseABI = int (__stdcall *)(uint);
  using ProcessABI = uint (__stdcall *)(void);
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using CopyABI = FString * (__thiscall *)(FString *,const FString *);
  using RequestABI = void (__thiscall *)(void *,uint,uint,uint,const char *,uint);
  using RemoveABI = void (__thiscall *)(void *,int,int);
  int index = 0;
  int started = 0;
  while (index < *(int *)((byte *)receiver + 4) && started < 5) {
    byte *data = *(byte **)receiver;
    uint offset = (uint)index * 300;
    if (*(uint *)(data + offset + 0x11c) == 0) {
      ((SendABI)R6GameServiceAddresses::ServerPing_SendPingToServer)(receiver,index);
      ++started;
    }
    index = (int)((uint)index + 1);
  }
  *(uint *)(nativeFrame - 0x20) = (*(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
  int stop = 0;
  while (true) {
    uint now = (*(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
    if (now - *(uint *)(nativeFrame - 0x20) >= 10) break;
    if (stop != 0) break;
    *(uint *)(nativeFrame - 0x30) = *(int **)(nativeFrame + 0xc) != 0;
    index = 0;
    while (true) {
      int count = *(int *)((byte *)receiver + 4);
      *(int *)(nativeFrame - 0x24) = index;
      if (index >= count) break;
      byte *data = *(byte **)receiver;
      uint offset = (uint)index * 300;
      bool loadedNext = false;
      int nextIndex;
      do {
        if (*(uint *)(data + offset + 0x11c) == 0) break;
        FArray *servers = *(FArray **)(nativeFrame + 8);
        if (servers != 0) {
          *(uint *)(nativeFrame - 0x14) = 0;
          uint found = 0;
          int serverIndex = 0;
          while (true) {
            servers = *(FArray **)(nativeFrame + 8);
            int serverCount = *(int *)((byte *)servers + 4);
            if (serverIndex >= serverCount) break;
            if (found != 0) break;
            bool matched = false;
            data = *(byte **)receiver;
            byte *request = data + offset;
            if (*(uint *)(request + 0x128) != 0) {
              byte *serverData = *(byte **)servers;
              int same = (*(EqualABI *)R6GameServiceAddresses::Core__8FStringSlot)
                  ((const FString *)(serverData + (uint)serverIndex * 220 + 0x1c),
                   (const FString *)(request + 0x10c));
              if (same != 0) matched = true;
              else servers = *(FArray **)(nativeFrame + 8);
            }
            if (!matched) {
              data = *(byte **)receiver;
              request = data + offset;
              if (*(uint *)(request + 0x128) == 0) {
                byte *serverData = *(byte **)servers;
                matched = (*(EqualABI *)R6GameServiceAddresses::Core__8FStringSlot)
                    ((const FString *)(serverData + (uint)serverIndex * 220 + 0x10),
                     (const FString *)(request + 0x10c)) != 0;
              }
            }
            if (matched) {
              *(uint *)(nativeFrame - 0x14) = 1;
              *(int *)(nativeFrame - 0x18) = serverIndex;
            }
            found = *(uint *)(nativeFrame - 0x14);
            serverIndex = (int)((uint)serverIndex + 1);
          }
          if (found == 0) break;
        }
        byte *packet = nativeFrame - 0x444;
        for (uint word = 0; word != 256; ++word) *(uint *)(packet + word * 4) = 0;
        data = *(byte **)receiver;
        uint socket = *(uint *)(data + offset + 0x118);
        int received = (*(ReceiveABI *)R6GameServiceAddresses::WS2_32_recvfromSlot)
            (socket,packet,1024,0,nativeFrame - 0x44,(int *)(nativeFrame - 0x28));
        if (received == -1) {
          data = *(byte **)receiver;
          uint age = *(uint *)(nativeFrame - 0x20) - *(uint *)(data + offset + 0x11c);
          if (age <= 2000) break;
          servers = *(FArray **)(nativeFrame + 8);
          if (servers != 0) {
            uint serverOffset = *(uint *)(nativeFrame - 0x18) * 220;
            byte *serverData = *(byte **)servers;
            *(uint *)(serverData + serverOffset + 0xc) = 1000;
            data = *(byte **)receiver;
            socket = *(uint *)(data + offset + 0x118);
            (*(CloseABI *)R6GameServiceAddresses::WS2_32_closesocketSlot)(socket);
            data = *(byte **)receiver;
            *(uint *)(data + offset + 0x120) = 1;
            data = *(byte **)receiver;
            uint alternate = *(uint *)(data + offset + 0x128);
            *(uint *)(nativeFrame - 0x1c) = 1;
            if (alternate == 0) {
              servers = *(FArray **)(nativeFrame + 8);
              serverData = *(byte **)servers;
              FString *alternateAddress = (FString *)(serverData + serverOffset + 0x1c);
              int length = *(int *)((byte *)alternateAddress + 4);
              if (length != 0 && (int)((uint)length - 1) > 0) {
                const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(alternateAddress);
                const char *ansi = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wide);
                servers = *(FArray **)(nativeFrame + 8);
                serverData = *(byte **)servers;
                uint transferred[3];
                *(uint **)(nativeFrame - 0x14) = transferred;
                (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)
                    ((FString *)transferred,(const FString *)(serverData + serverOffset + 0x5c));
                ((RequestABI)R6GameServiceAddresses::ServerPing_NewPingRequest)
                    (receiver,transferred[0],transferred[1],transferred[2],ansi,1);
              }
            }
            // Fallback creation can move Data or change the alternate flag; both are read again.
            data = *(byte **)receiver;
            if (*(uint *)(data + offset + 0x128) != 0) {
              servers = *(FArray **)(nativeFrame + 8);
              byte *serverData = *(byte **)servers;
              uint value = *(uint *)(serverData + serverOffset + 0x28);
              nextIndex = *(int *)(nativeFrame - 0x24);
              loadedNext = true;
              *(uint *)(serverData + serverOffset + 0x28) = value | 1;
            }
          } else {
            **(uint **)(nativeFrame + 0xc) = 1000;
            data = *(byte **)receiver;
            socket = *(uint *)(data + offset + 0x118);
            (*(CloseABI *)R6GameServiceAddresses::WS2_32_closesocketSlot)(socket);
            data = *(byte **)receiver;
            *(uint *)(data + offset + 0x120) = 1;
            nextIndex = *(int *)(nativeFrame - 0x24);
            loadedNext = true;
            *(uint *)(nativeFrame - 0x1c) = 1;
          }
          break;
        }
        data = *(byte **)receiver;
        uint echoOffset = (packet[0] & 15) * 4;
        uint identifier = *(ushort *)(packet + echoOffset + 6);
        uint expected = *(uint *)(data + offset + 0x124);
        byte *echo = packet + echoOffset;
        *(byte **)(nativeFrame - 0x14) = echo;
        if (identifier != expected) break;
        bool valid = false;
        if (echo[0] == 0) {
          uint processId = (*(ProcessABI *)R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot)();
          valid = *(ushort *)(echo + 4) == (ushort)processId;
        }
        if (valid) {
          servers = *(FArray **)(nativeFrame + 8);
          if (servers != 0) {
            uint serverOffset = *(uint *)(nativeFrame - 0x18) * 220;
            byte *serverData = *(byte **)servers;
            byte *destination = serverData + serverOffset;
            now = (*(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
            byte *savedEcho = *(byte **)(nativeFrame - 0x14);
            *(uint *)(destination + 0xc) = now - *(uint *)(savedEcho + 8);
          } else {
            now = (*(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
            uint elapsed = now - *(uint *)(echo + 8);
            **(uint **)(nativeFrame + 0xc) = elapsed;
          }
          data = *(byte **)receiver;
          socket = *(uint *)(data + offset + 0x118);
          (*(CloseABI *)R6GameServiceAddresses::WS2_32_closesocketSlot)(socket);
          data = *(byte **)receiver;
          *(uint *)(data + offset + 0x120) = 1;
          *(uint *)(nativeFrame - 0x1c) = 1;
          servers = *(FArray **)(nativeFrame + 8);
          if (servers != 0) {
            data = *(byte **)receiver;
            if (*(uint *)(data + offset + 0x128) != 0) {
              uint serverOffset = *(uint *)(nativeFrame - 0x18) * 220;
              byte *serverData = *(byte **)servers;
              uint value = *(uint *)(serverData + serverOffset + 0x28);
              nextIndex = *(int *)(nativeFrame - 0x24);
              loadedNext = true;
              *(uint *)(serverData + serverOffset + 0x28) = value | 1;
            }
          }
        } else {
          servers = *(FArray **)(nativeFrame + 8);
          if (servers != 0) {
            uint serverIndex = *(uint *)(nativeFrame - 0x18);
            byte *serverData = *(byte **)servers;
            *(uint *)(serverData + serverIndex * 220 + 0xc) = 1000;
          } else {
            **(uint **)(nativeFrame + 0xc) = 1000;
          }
          data = *(byte **)receiver;
          socket = *(uint *)(data + offset + 0x118);
          (*(CloseABI *)R6GameServiceAddresses::WS2_32_closesocketSlot)(socket);
          data = *(byte **)receiver;
          *(uint *)(data + offset + 0x120) = 1;
        }
      } while (false);
      if (!loadedNext) nextIndex = *(int *)(nativeFrame - 0x24);
      index = (int)((uint)nextIndex + 1);
    }
    index = 0;
    while (index < *(int *)((byte *)receiver + 4)) {
      byte *data = *(byte **)receiver;
      uint offset = (uint)index * 300;
      if (*(uint *)(data + offset + 0x120) != 0)
        ((RemoveABI)R6GameServiceAddresses::RemovePingRecordRange)(receiver,index,1);
      else
        index = (int)((uint)index + 1);
    }
    stop = *(int *)(nativeFrame - 0x30);
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp-0x1c]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Forwards the caught unsigned-short pointer from parent EBP-0x34 to-0x2c.
// R6GameService.dll @ 10014846 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x34]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x2c]
    push   ecx
    mov    DWORD PTR [ebp-0x2c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports ServerPing::PingManager context and rethrows the active exception.
// R6GameService.dll @ 1001485a : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch7(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextServerPingPingManager
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state ping-manager guard, without request rollback or socket cleanup actions.
// R6GameService.dll @ 10064510 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_PingManagerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServerPing_PingManagerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e66c : native exception records.
const R6GameServiceNative::UnwindEntry ServerPing_NewPingRequestUnwindMap[3] = {
  {-1, R6GameServiceAddresses::ServerPing_NewPingRequestUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007e684 : native exception records.
const R6GameServiceNative::CatchHandler ServerPingGPingRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::ServerPing_ServerPingCatch2},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ServerPing_ServerPingCatch3},
};
// R6GameService.dll data @ 1007e6a4 : native exception records.
const R6GameServiceNative::TryBlock ServerPing_NewPingRequestTryMap[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::ServerPingGPingRequestHandlers},
};
// R6GameService.dll data @ 1007e6b8 : native exception records.
// R6GameService.dll data @ 1007e66c : native storage identity retained.
const R6GameServiceNative::FuncInfo ServerPing_NewPingRequestExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ServerPing_NewPingRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::ServerPing_NewPingRequestTryMap,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007e6d4 : native exception records.
const R6GameServiceNative::UnwindEntry ServerPing_SendPingToServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007e6e4 : native exception records.
const R6GameServiceNative::CatchHandler ServerPingGPingRequestHandlers2[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -44,
  R6GameServiceAddresses::ServerPing_ServerPingCatch4},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ServerPing_ServerPingCatch5},
};
// R6GameService.dll data @ 1007e704 : native exception records.
const R6GameServiceNative::TryBlock ServerPing_SendPingToServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::ServerPingGPingRequestHandlers2},
};
// R6GameService.dll data @ 1007e718 : native exception records.
// R6GameService.dll data @ 1007e6d4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ServerPing_SendPingToServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ServerPing_SendPingToServerUnwindMap,
  0x1,
  R6GameServiceAddresses::ServerPing_SendPingToServerTryMap,
  0x0,
  0x0,
};

// Appends a zeroed 300-byte request, assigns its strings/flag, copies its host and destroys the owned input FString.
// R6GameService.dll @ 100140b0 : this is the array header; owns FString value, RET20; record names inferred.
__declspec(naked) void __thiscall ServerPing::NewPingRequest(FString payloadText,const char *ansiAddress,uint flag)
{
  byte *nativeFrame;
  ServerPing *receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ServerPing_NewPingRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
    mov    receiver,ecx
  }
  using AddABI = int (__thiscall *)(void *,int,int);
  using AssignABI = FString * (__thiscall *)(FString *,const FString *);
  using FromAnsiABI = const TCHAR * (__cdecl *)(const char *);
  using AssignWideABI = FString * (__thiscall *)(FString *,const TCHAR *);
  using FindABI = char * (__cdecl *)(const char *,const char *);
  using CopyABI = char * (__cdecl *)(char *,const char *,uint);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame - 4) = 0;
  *(byte *)(nativeFrame - 4) = 1;
  int index = (*(AddABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(receiver,300,1);
  byte *data = *(byte **)receiver;
  uint offset = (uint)index * 300;
  *(int *)(nativeFrame - 0x18) = index;
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)
      ((FString *)(data + offset),(const FString *)(nativeFrame + 8));
  data = *(byte **)receiver;
  const char *ansiText = *(const char **)(nativeFrame + 0x14);
  byte *record = data + offset;
  *(byte **)(nativeFrame - 0x14) = record;
  const TCHAR *wideAddress = (*(FromAnsiABI *)R6GameServiceAddresses::Core__appFromAnsiSlot)(ansiText);
  record = *(byte **)(nativeFrame - 0x14);
  (*(AssignWideABI *)R6GameServiceAddresses::Core__4FStringSlot2)((FString *)(record + 0x10c),wideAddress);
  data = *(byte **)receiver;
  uint requestFlag = *(uint *)(nativeFrame + 0x18);
  *(uint *)(data + offset + 0x128) = requestFlag;
  const char *colon = (*(FindABI *)R6GameServiceAddresses::MSVCR71_strstrSlot)
      (ansiText,(const char *)R6GameServiceAddresses::WideTextPunctuation6);
  if (colon != 0) {
    *(byte **)(nativeFrame + 0x14) = *(byte **)receiver + offset;
    colon = (*(FindABI *)R6GameServiceAddresses::MSVCR71_strstrSlot)
        (ansiText,(const char *)R6GameServiceAddresses::WideTextPunctuation6);
    uint count = (uint)colon - (uint)ansiText;
    byte *destination = *(byte **)(nativeFrame + 0x14) + 0xc;
    (*(CopyABI *)R6GameServiceAddresses::MSVCR71_strncpySlot)((char *)destination,ansiText,count);
  } else {
    char *destination = (char *)(*(byte **)receiver + offset + 0xc);
    char character;
    do {
      character = *ansiText++;
      *destination++ = character;
    } while (character != 0);
  }
  uint finalIndex = *(uint *)(nativeFrame - 0x18);
  data = *(byte **)receiver;
  uint finalOffset = finalIndex * 300;
  *(uint *)(data + finalOffset + 0x11c) = 0;
  data = *(byte **)receiver;
  *(uint *)(data + finalOffset + 0x120) = 0;
  *(uint *)(nativeFrame - 4) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame + 8));
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x14
  }
}

// Forwards the caught pointer from parent EBP-0x20 through-0x1c.
// R6GameService.dll @ 100141c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x1c]
    push   ecx
    mov    DWORD PTR [ebp-0x1c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports NewPingRequest context and rethrows the active exception.
// R6GameService.dll @ 100141d4 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch3(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextServerPingNewPingRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the owned input FString at parent EBP+8.
// R6GameService.dll @ 100644e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_NewPingRequestUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state request guard with owned-input cleanup and typed/context catches.
// R6GameService.dll @ 100644e9 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_NewPingRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServerPing_NewPingRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Creates/configures a raw ICMP socket, builds a 44-byte packet, publishes tick/ID and sends despite API errors.
// R6GameService.dll @ 10014200 : this is the array header; native frame preserves unchecked packet overlap.
__declspec(naked) void __thiscall ServerPing::SendPingToServer(int index)
{
  byte *nativeFrame;
  ServerPing *receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ServerPing_SendPingToServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x420
    push   ebx
    push   esi
    mov    nativeFrame,ebp
    mov    receiver,ecx
  }
  uint offset = *(uint *)(nativeFrame + 8);
  __asm {
    push   edi
  }
  offset *= 300;
  __asm {
    mov    DWORD PTR [ebp-0x10],esp
  }
  using SocketABI = uint (__stdcall *)(int,int,int,void *,uint,uint);
  using OptionABI = int (__stdcall *)(uint,int,int,const void *,int);
  using IoctlABI = int (__stdcall *)(uint,uint,uint *);
  using AddressABI = uint (__stdcall *)(const char *);
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using SendABI = int (__stdcall *)(uint,const void *,int,int,const void *,int);
  byte *socketRecord = *(byte **)receiver;
  *(uint *)(nativeFrame - 4) = 0;
  *(uint *)(nativeFrame - 0x14) = 1000;
  socketRecord += offset;
  uint socket = (*(SocketABI *)R6GameServiceAddresses::WS2_32_WSASocketWSlot)(2,3,1,0,0,0);
  *(uint *)(socketRecord + 0x118) = socket;
  byte *data = *(byte **)receiver;
  socket = *(uint *)(data + offset + 0x118);
  OptionABI setOption = *(OptionABI *)R6GameServiceAddresses::WS2_32_setsockoptSlot;
  setOption(socket,0xffff,0x1006,nativeFrame - 0x14,4);
  data = *(byte **)receiver;
  socket = *(uint *)(data + offset + 0x118);
  setOption(socket,0xffff,0x1005,nativeFrame - 0x14,4);
  data = *(byte **)receiver;
  *(uint *)(nativeFrame + 8) = 1;
  socket = *(uint *)(data + offset + 0x118);
  (*(IoctlABI *)R6GameServiceAddresses::WS2_32_ioctlsocketSlot)(socket,0x8004667e,(uint *)(nativeFrame + 8));
  data = *(byte **)receiver;
  byte *endpoint = nativeFrame - 0x28;
  *(uint *)endpoint = 0;
  *(uint *)(endpoint + 4) = 0;
  *(uint *)(endpoint + 8) = 0;
  *(uint *)(endpoint + 12) = 0;
  uint destination = (*(AddressABI *)R6GameServiceAddresses::WS2_32_inet_addrSlot)((const char *)(data + offset + 0xc));
  *(uint *)(endpoint + 4) = destination;
  byte *packet = nativeFrame - 0x42c;
  for (uint word = 0; word != 256; ++word) *(uint *)(packet + word * 4) = 0;
  data = *(byte **)receiver;
  *(ushort *)endpoint = 2;
  const TCHAR *widePayload = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)((const FString *)(data + offset));
  const char *payload = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(widePayload);
  BuildPingPacket(packet,44,payload);
  data = *(byte **)receiver;
  uint sentAt = *(uint *)(packet + 8);
  *(uint *)(data + offset + 0x11c) = sentAt;
  uint identifier = *(ushort *)(packet + 6);
  data = *(byte **)receiver;
  *(uint *)(data + offset + 0x124) = identifier;
  data = *(byte **)receiver;
  socket = *(uint *)(data + offset + 0x118);
  (*(SendABI *)R6GameServiceAddresses::WS2_32_sendtoSlot)(socket,packet,44,0,endpoint,16);
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Forwards the caught pointer from parent EBP-0x2c through-0x18.
// R6GameService.dll @ 10014363 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x2c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x18]
    push   ecx
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports SendPingToServer context and rethrows the active exception.
// R6GameService.dll @ 10014377 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch5(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextServerPingSendPingToServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the send guard without socket cleanup or publication rollback actions.
// R6GameService.dll @ 10064500 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_SendPingToServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServerPing_SendPingToServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e5e8 : native exception records.
const R6GameServiceNative::UnwindEntry ServerPing_GetPingTimeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007e5f8 : native exception records.
const R6GameServiceNative::CatchHandler ServerPingGPingExchangeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -68, R6GameServiceAddresses::ServerPingCatch},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ServerPing_ServerPingCatch},
};
// R6GameService.dll data @ 1007e618 : native exception records.
const R6GameServiceNative::TryBlock ServerPing_GetPingTimeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::ServerPingGPingExchangeHandlers},
};
// R6GameService.dll data @ 1007e62c : native exception records.
// R6GameService.dll data @ 1007e5e8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ServerPing_GetPingTimeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ServerPing_GetPingTimeUnwindMap,
  0x1,
  R6GameServiceAddresses::ServerPing_GetPingTimeTryMap,
  0x0,
  0x0,
};

// Performs a raw ICMP exchange with counted sleeps; normal paths free buffers/close sockets, guard paths do not.
// Context supports the class/method name; cdecl/static shape follows callers and absence of an ECX receiver.
// R6GameService.dll @ 10013dd0 : cdecl uint(const char *); no instance data or exception cleanup actions.
uint __cdecl ServerPing::GetPingTime(const char *address)
{
  using StartupABI = int (__stdcall *)(uint,void *);
  using SocketABI = uint (__stdcall *)(int,int,int,void *,uint,uint);
  using OptionABI = int (__stdcall *)(uint,int,int,const void *,int);
  using IoctlABI = int (__stdcall *)(uint,uint,uint *);
  using AddressABI = uint (__stdcall *)(const char *);
  using TextAddressABI = char * (__stdcall *)(uint);
  using AllocateABI = void * (__thiscall *)(void *,uint,const TCHAR *);
  using FreeABI = void (__thiscall *)(void *,void *);
  using SendABI = int (__stdcall *)(uint,const void *,int,int,const void *,int);
  using ReceiveABI = int (__stdcall *)(uint,void *,int,int,void *,int *);
  using TickABI = uint (__stdcall *)(void);
  using ErrorABI = int (__stdcall *)(void);
  using SleepABI = void (__stdcall *)(uint);
  using CloseABI = int (__stdcall *)(uint);
  using CleanupABI = int (__stdcall *)(void);
  // Scratch base corresponds to EBP-1e4: WSADATA, sender at +190, endpoint at +1a4 and live option/counter words.
  byte scratch[0x1d8];
  int &timeout = *(int *)(scratch + 0x1cc);
  uint &ping = *(uint *)(scratch + 0x1c0);
  int &senderLength = *(int *)(scratch + 0x1b4);
  int &receiveResult = *(int *)(scratch + 0x1c4);
  void *&incoming = *(void **)(scratch + 0x1d0);
  uint &elapsed = *(uint *)(scratch + 0x1c8);
  timeout = 1000;
  ping = 1000;
  try {
    senderLength = 16;
    int startup = (*(StartupABI *)R6GameServiceAddresses::WS2_32_WSAStartupSlot)(0x102,scratch);
    if (startup == 0) {
      uint socket = (*(SocketABI *)R6GameServiceAddresses::WS2_32_WSASocketWSlot)(2,3,1,0,0,0);
      if (socket != 0xffffffff) {
        OptionABI setOption = *(OptionABI *)R6GameServiceAddresses::WS2_32_setsockoptSlot;
        if (setOption(socket,0xffff,0x1006,&timeout,4) != -1
            && setOption(socket,0xffff,0x1005,&timeout,4) != -1) {
          uint &nonblocking = *(uint *)(scratch + 0x1bc);
          nonblocking = 1;
          receiveResult = (*(IoctlABI *)R6GameServiceAddresses::WS2_32_ioctlsocketSlot)
              (socket,0x8004667e,&nonblocking);
          if (receiveResult != -1) {
            byte *endpoint = scratch + 0x1a4;
            *(uint *)endpoint = 0;
            *(uint *)(endpoint + 4) = 0;
            *(uint *)(endpoint + 8) = 0;
            *(uint *)(endpoint + 12) = 0;
            uint destination = (*(AddressABI *)R6GameServiceAddresses::WS2_32_inet_addrSlot)(address);
            *(uint *)(endpoint + 4) = destination;
            *(ushort *)endpoint = 2;
            (*(TextAddressABI *)R6GameServiceAddresses::WS2_32_inet_ntoaSlot)(destination);
            void *allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
            uint *table = *(uint **)allocator;
            byte *outgoing = (byte *)((AllocateABI)table[0])
                (allocator,1024,(const TCHAR *)R6GameServiceAddresses::WideTextGAMESERVICE);
            allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
            table = *(uint **)allocator;
            void *incomingToFree = ((AllocateABI)table[0])
                (allocator,1024,(const TCHAR *)R6GameServiceAddresses::WideTextGAMESERVICE);
            incoming = incomingToFree;
            if (outgoing != 0) {
              for (uint index = 0; index != 256; ++index) *(uint *)(outgoing + index * 4) = 0;
              BuildPingPacket(outgoing,44,address);
              *(ushort *)(outgoing + 2) = 0;
              *(uint *)(outgoing + 8) = (*(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot)();
              *(ushort *)(outgoing + 6) = 0;
              *(ushort *)(outgoing + 2) = (ushort)PingChecksum(outgoing,44);
              int sent = (*(SendABI *)R6GameServiceAddresses::WS2_32_sendtoSlot)
                  (socket,outgoing,44,0,endpoint,16);
              if (sent != -1) {
                elapsed = 0;
                ReceiveABI receive = *(ReceiveABI *)R6GameServiceAddresses::WS2_32_recvfromSlot;
                bool parseReply = true;
                while ((int)elapsed < timeout) {
                  receiveResult = receive(socket,incoming,1024,0,scratch + 0x190,&senderLength);
                  if (receiveResult != -1) break;
                  int error = (*(ErrorABI *)R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot)();
                  if (error != 10035) {
                    parseReply = false;
                    break;
                  }
                  (*(SleepABI *)R6GameServiceAddresses::KERNEL32_SleepSlot)(5);
                  elapsed += 5;
                }
                // Exhaustion still parses the last status and uninitialized/stale buffer; only other receive errors skip it.
                if (parseReply) ping = ReadPingReply((const byte *)incoming,receiveResult,scratch + 0x190);
              }
              allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
              table = *(uint **)allocator;
              ((FreeABI)table[2])(allocator,outgoing);
              incomingToFree = incoming;
            }
            if (incomingToFree != 0) {
              allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
              table = *(uint **)allocator;
              ((FreeABI)table[2])(allocator,incomingToFree);
            }
          }
        }
        (*(CloseABI *)R6GameServiceAddresses::WS2_32_closesocketSlot)(socket);
      }
    }
    (*(CleanupABI *)R6GameServiceAddresses::WS2_32_WSACleanupSlot)();
    return ping;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextServerPingGetPingTime);
    throw;
  }
}

// Forwards the caught pointer from inherited EBP-0x44 through-0x2c.
// R6GameService.dll @ 10014004 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPingCatch(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x44]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x2c]
    push   ecx
    mov    DWORD PTR [ebp-0x2c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports GetPingTime context and rethrows the active exception.
// R6GameService.dll @ 10014018 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_ServerPingCatch(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextServerPingGetPingTime
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state exchange guard without buffer/socket cleanup actions.
// R6GameService.dll @ 100644b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void ServerPing_GetPingTimeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ServerPing_GetPingTimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
