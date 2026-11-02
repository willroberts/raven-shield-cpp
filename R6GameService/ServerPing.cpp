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
// R6GameService.dll @ 10014440 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ServerPing::PingManager(FArray *requests,int *serverRecords,int *singleResult)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ServerPing_PingManagerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x438
    mov    eax,DWORD PTR [ebp+0x8]
    push   ebx
    push   esi
    xor    esi,esi
    cmp    eax,esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    ebx,ecx
    mov    DWORD PTR [ebp-0x4],esi
    mov    DWORD PTR [ebp-0x28],0x10
    jne    Branch2
    cmp    DWORD PTR [ebp+0xc],esi
    jne    Branch2
  Branch1:
    xor    eax,eax
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  Branch2:
    cmp    DWORD PTR [ebx+0x4],esi
    mov    DWORD PTR [ebp-0x1c],esi
    je     Branch1
    xor    edi,edi
    lea    ecx,[ecx+0x0]
  Branch3:
    cmp    esi,DWORD PTR [ebx+0x4]
    jge    Branch5
    cmp    edi,0x5
    jge    Branch5
    mov    ecx,DWORD PTR [ebx]
    mov    eax,esi
    imul   eax,eax,0x12c
    mov    edx,DWORD PTR [eax+ecx*1+0x11c]
    test   edx,edx
    jne    Branch4
    push   esi
    mov    ecx,ebx
    call   R6GameServiceAddresses::ServerPing_SendPingToServer
    inc    edi
  Branch4:
    inc    esi
    jmp    Branch3
  Branch5:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    mov    DWORD PTR [ebp-0x20],eax
    xor    esi,esi
  Branch6:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    sub    eax,DWORD PTR [ebp-0x20]
    cmp    eax,0xa
    jae    Branch27
    test   esi,esi
    jne    Branch27
    mov    eax,DWORD PTR [ebp+0xc]
    xor    edx,edx
    test   eax,eax
    setne  dl
    mov    DWORD PTR [ebp-0x30],edx
  Branch7:
    cmp    esi,DWORD PTR [ebx+0x4]
    mov    DWORD PTR [ebp-0x24],esi
    jge    Branch23
    mov    eax,DWORD PTR [ebx]
    imul   esi,esi,0x12c
    mov    ecx,DWORD PTR [esi+eax*1+0x11c]
    test   ecx,ecx
    je     Branch22
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch13
    xor    eax,eax
    mov    DWORD PTR [ebp-0x14],eax
    xor    edi,edi
  Branch8:
    mov    ecx,DWORD PTR [ebp+0x8]
    cmp    edi,DWORD PTR [ecx+0x4]
    jge    Branch12
    test   eax,eax
    jne    Branch13
    mov    edx,DWORD PTR [ebx]
    lea    eax,[esi+edx*1]
    mov    edx,DWORD PTR [eax+0x128]
    test   edx,edx
    je     Branch9
    mov    ecx,DWORD PTR [ecx]
    add    eax,0x10c
    push   eax
    mov    eax,edi
    imul   eax,eax,0xdc
    lea    ecx,[eax+ecx*1+0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    jne    Branch10
    mov    ecx,DWORD PTR [ebp+0x8]
  Branch9:
    mov    edx,DWORD PTR [ebx]
    lea    eax,[esi+edx*1]
    mov    edx,DWORD PTR [eax+0x128]
    test   edx,edx
    jne    Branch11
    mov    ecx,DWORD PTR [ecx]
    add    eax,0x10c
    push   eax
    mov    eax,edi
    imul   eax,eax,0xdc
    lea    ecx,[eax+ecx*1+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch11
  Branch10:
    mov    DWORD PTR [ebp-0x14],0x1
    mov    DWORD PTR [ebp-0x18],edi
  Branch11:
    mov    eax,DWORD PTR [ebp-0x14]
    inc    edi
    jmp    Branch8
  Branch12:
    test   eax,eax
    je     Branch22
  Branch13:
    xor    eax,eax
    mov    ecx,0x100
    lea    edi,[ebp-0x444]
    rep    stos DWORD PTR es:[edi],eax
    lea    edx,[ebp-0x28]
    push   edx
    mov    edx,DWORD PTR [ebx]
    lea    eax,[ebp-0x44]
    push   eax
    mov    eax,DWORD PTR [esi+edx*1+0x118]
    push   0x0
    push   0x400
    lea    ecx,[ebp-0x444]
    push   ecx
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvfromSlot
    cmp    eax,0xffffffff
    jne    Branch16
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [ebp-0x20]
    sub    edx,DWORD PTR [esi+ecx*1+0x11c]
    cmp    edx,0x7d0
    jbe    Branch22
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch15
    mov    edi,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [eax]
    imul   edi,edi,0xdc
    mov    DWORD PTR [edi+eax*1+0xc],0x3e8
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    mov    eax,DWORD PTR [ebx]
    mov    edx,0x1
    mov    DWORD PTR [esi+eax*1+0x120],edx
    mov    ecx,DWORD PTR [ebx]
    mov    eax,DWORD PTR [esi+ecx*1+0x128]
    test   eax,eax
    mov    DWORD PTR [ebp-0x1c],edx
    jne    Branch14
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [edi+ecx*1+0x20]
    test   eax,eax
    lea    ecx,[edi+ecx*1+0x1c]
    je     Branch14
    dec    eax
    test   eax,eax
    jle    Branch14
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    edx,DWORD PTR [ebp+0x8]
    add    esp,0x4
    push   eax
    mov    eax,DWORD PTR [edx]
    sub    esp,0xc
    lea    edx,[edi+eax*1+0x5c]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x14],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,ebx
    call   R6GameServiceAddresses::ServerPing_NewPingRequest
  Branch14:
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esi+eax*1+0x128]
    test   ecx,ecx
    je     Branch22
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edi+edx*1+0x28]
    mov    esi,DWORD PTR [ebp-0x24]
    lea    edi,[edi+edx*1+0x28]
    or     eax,0x1
    mov    DWORD PTR [edi],eax
    inc    esi
    jmp    Branch7
  Branch15:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [eax],0x3e8
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    mov    ecx,DWORD PTR [ebx]
    mov    eax,0x1
    mov    DWORD PTR [esi+ecx*1+0x120],eax
    mov    esi,DWORD PTR [ebp-0x24]
    mov    DWORD PTR [ebp-0x1c],eax
    inc    esi
    jmp    Branch7
  Branch16:
    mov    eax,DWORD PTR [ebx]
    xor    edx,edx
    mov    dl,BYTE PTR [ebp-0x444]
    and    edx,0xf
    shl    edx,0x2
    movzx  edi,dx
    movzx  ecx,WORD PTR [ebp+edi*1-0x43e]
    cmp    ecx,DWORD PTR [esi+eax*1+0x124]
    lea    edi,[ebp+edi*1-0x444]
    mov    DWORD PTR [ebp-0x14],edi
    jne    Branch22
    cmp    BYTE PTR [edi],0x0
    jne    Branch19
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot
    cmp    WORD PTR [edi+0x4],ax
    jne    Branch19
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch17
    mov    edi,DWORD PTR [ebp-0x18]
    mov    edx,DWORD PTR [eax]
    imul   edi,edi,0xdc
    add    edi,edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    mov    edx,DWORD PTR [ebp-0x14]
    sub    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edi+0xc],eax
    jmp    Branch18
  Branch17:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    sub    eax,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ecx],eax
  Branch18:
    mov    edx,DWORD PTR [ebx]
    mov    eax,DWORD PTR [esi+edx*1+0x118]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    mov    ecx,DWORD PTR [ebx]
    mov    eax,0x1
    mov    DWORD PTR [esi+ecx*1+0x120],eax
    mov    DWORD PTR [ebp-0x1c],eax
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch22
    mov    edx,DWORD PTR [ebx]
    mov    eax,DWORD PTR [esi+edx*1+0x128]
    test   eax,eax
    je     Branch22
    mov    eax,DWORD PTR [ebp-0x18]
    mov    ecx,DWORD PTR [ebp+0x8]
    imul   eax,eax,0xdc
    mov    edx,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [eax+edx*1+0x28]
    mov    esi,DWORD PTR [ebp-0x24]
    lea    eax,[eax+edx*1+0x28]
    or     ecx,0x1
    mov    DWORD PTR [eax],ecx
    inc    esi
    jmp    Branch7
  Branch19:
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch20
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    edx,DWORD PTR [eax]
    imul   ecx,ecx,0xdc
    mov    DWORD PTR [ecx+edx*1+0xc],0x3e8
    jmp    Branch21
  Branch20:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [eax],0x3e8
  Branch21:
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [esi+eax*1+0x120],0x1
  Branch22:
    mov    esi,DWORD PTR [ebp-0x24]
    inc    esi
    jmp    Branch7
  Branch23:
    xor    esi,esi
    nop
  Branch24:
    cmp    esi,DWORD PTR [ebx+0x4]
    jge    Branch26
    mov    edx,DWORD PTR [ebx]
    mov    ecx,esi
    imul   ecx,ecx,0x12c
    mov    eax,DWORD PTR [ecx+edx*1+0x120]
    test   eax,eax
    je     Branch25
    push   0x1
    push   esi
    mov    ecx,ebx
    call   R6GameServiceAddresses::RemovePingRecordRange
    jmp    Branch24
    // Native continuation @10014876 is part of this method, beyond the physical catch bodies.
  Branch25:
    inc    esi
    jmp    Branch24
  Branch26:
    mov    esi,DWORD PTR [ebp-0x30]
    jmp    Branch6
  Branch27:
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
// R6GameService.dll @ 100140b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ServerPing::NewPingRequest(FArray *requests,FString address,char *ansiAddress,uint flag)
{
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
    mov    esi,ecx
    push   0x1
    mov    DWORD PTR [ebp-0x4],0x0
    push   0x12c
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ecx,DWORD PTR [esi]
    mov    ebx,eax
    imul   ebx,ebx,0x12c
    mov    DWORD PTR [ebp-0x18],eax
    lea    eax,[ebp+0x8]
    push   eax
    add    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [ebp+0x14]
    add    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x14],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR [ebp-0x14]
    add    esp,0x4
    push   eax
    add    ecx,0x10c
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR [ebp+0x18]
    push   R6GameServiceAddresses::WideTextPunctuation6
    push   edi
    mov    DWORD PTR [ebx+ecx*1+0x128],edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strstrSlot
    add    esp,0x8
    test   eax,eax
    je     Branch28
    mov    eax,DWORD PTR [esi]
    add    eax,ebx
    push   R6GameServiceAddresses::WideTextPunctuation6
    push   edi
    mov    DWORD PTR [ebp+0x14],eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strstrSlot
    sub    eax,edi
    push   eax
    mov    eax,DWORD PTR [ebp+0x14]
    add    eax,0xc
    push   edi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strncpySlot
    add    esp,0x14
    jmp    Branch30
  Branch28:
    mov    ecx,DWORD PTR [esi]
    lea    ecx,[ebx+ecx*1+0xc]
  Branch29:
    mov    al,BYTE PTR [edi]
    inc    edi
    mov    BYTE PTR [ecx],al
    inc    ecx
    test   al,al
    jne    Branch29
  Branch30:
    mov    eax,DWORD PTR [ebp-0x18]
    mov    edx,DWORD PTR [esi]
    imul   eax,eax,0x12c
    xor    ecx,ecx
    mov    DWORD PTR [eax+edx*1+0x11c],ecx
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [eax+edx*1+0x120],ecx
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll @ 10014200 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ServerPing::SendPingToServer(FArray *requests,int index)
{
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
    mov    esi,DWORD PTR [ebp+0x8]
    push   edi
    imul   esi,esi,0x12c
    mov    DWORD PTR [ebp-0x10],esp
    push   0x0
    push   0x0
    push   0x0
    push   0x1
    mov    ebx,ecx
    mov    edi,DWORD PTR [ebx]
    push   0x3
    push   0x2
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x14],0x3e8
    add    edi,esi
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSASocketWSlot
    mov    DWORD PTR [edi+0x118],eax
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    push   0x4
    lea    eax,[ebp-0x14]
    push   eax
    push   0x1006
    push   0xffff
    push   edx
    call   edi
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   0x4
    lea    eax,[ebp-0x14]
    push   eax
    push   0x1005
    push   0xffff
    push   edx
    call   edi
    mov    ecx,DWORD PTR [ebx]
    lea    eax,[ebp+0x8]
    push   eax
    mov    DWORD PTR [ebp+0x8],0x1
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   0x8004667e
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ioctlsocketSlot
    mov    ecx,DWORD PTR [ebx]
    xor    eax,eax
    mov    DWORD PTR [ebp-0x28],eax
    mov    DWORD PTR [ebp-0x24],eax
    lea    edx,[esi+ecx*1+0xc]
    mov    DWORD PTR [ebp-0x20],eax
    push   edx
    mov    DWORD PTR [ebp-0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    mov    DWORD PTR [ebp-0x24],eax
    xor    eax,eax
    mov    ecx,0x100
    lea    edi,[ebp-0x42c]
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,DWORD PTR [ebx]
    add    ecx,esi
    mov    WORD PTR [ebp-0x28],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    lea    eax,[ebp-0x42c]
    push   0x2c
    push   eax
    call   R6GameServiceAddresses::BuildPingPacket
    mov    ecx,DWORD PTR [ebx]
    mov    edx,DWORD PTR [ebp-0x424]
    mov    DWORD PTR [esi+ecx*1+0x11c],edx
    movzx  eax,WORD PTR [ebp-0x426]
    mov    ecx,DWORD PTR [ebx]
    add    esp,0xc
    mov    DWORD PTR [esi+ecx*1+0x124],eax
    push   0x10
    lea    edx,[ebp-0x28]
    mov    ecx,DWORD PTR [ebx]
    push   edx
    mov    edx,DWORD PTR [esi+ecx*1+0x118]
    push   0x0
    push   0x2c
    lea    eax,[ebp-0x42c]
    push   eax
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_sendtoSlot
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
// R6GameService.dll @ 10013dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ServerPing::GetPingTime(const char *address)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ServerPing_GetPingTimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1d8
    push   ebx
    push   esi
    mov    eax,0x3e8
    push   edi
    mov    DWORD PTR [ebp-0x18],eax
    mov    DWORD PTR [ebp-0x24],eax
    mov    DWORD PTR [ebp-0x10],esp
    lea    eax,[ebp-0x1e4]
    push   eax
    push   0x102
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x30],0x10
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAStartupSlot
    test   eax,eax
    jne    Branch38
    push   eax
    push   eax
    push   eax
    push   0x1
    push   0x3
    push   0x2
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSASocketWSlot
    mov    ebx,eax
    cmp    ebx,0xffffffff
    je     Branch38
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::WS2_32_setsockoptSlot
    push   0x4
    lea    ecx,[ebp-0x18]
    push   ecx
    push   0x1006
    push   0xffff
    push   ebx
    call   esi
    cmp    eax,0xffffffff
    je     Branch37
    push   0x4
    lea    edx,[ebp-0x18]
    push   edx
    push   0x1005
    push   0xffff
    push   ebx
    call   esi
    cmp    eax,0xffffffff
    je     Branch37
    lea    eax,[ebp-0x28]
    push   eax
    push   0x8004667e
    push   ebx
    mov    DWORD PTR [ebp-0x28],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ioctlsocketSlot
    cmp    eax,0xffffffff
    mov    DWORD PTR [ebp-0x20],eax
    je     Branch37
    mov    edx,DWORD PTR [ebp+0x8]
    xor    ecx,ecx
    mov    DWORD PTR [ebp-0x40],ecx
    mov    DWORD PTR [ebp-0x3c],ecx
    mov    DWORD PTR [ebp-0x38],ecx
    push   edx
    mov    DWORD PTR [ebp-0x34],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    push   eax
    mov    DWORD PTR [ebp-0x3c],eax
    mov    WORD PTR [ebp-0x40],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   0x400
    call   DWORD PTR [edx]
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   0x400
    call   DWORD PTR [edx]
    test   esi,esi
    mov    DWORD PTR [ebp-0x14],eax
    je     Branch36
    xor    eax,eax
    mov    ecx,0x100
    mov    edi,esi
    rep    stos DWORD PTR es:[edi],eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    push   0x2c
    push   esi
    call   R6GameServiceAddresses::BuildPingPacket
    xor    edi,edi
    add    esp,0xc
    mov    WORD PTR [esi+0x2],di
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    push   0x2c
    push   esi
    mov    DWORD PTR [esi+0x8],eax
    mov    WORD PTR [esi+0x6],di
    call   R6GameServiceAddresses::PingChecksum
    add    esp,0x8
    push   0x10
    lea    ecx,[ebp-0x40]
    push   ecx
    push   edi
    push   0x2c
    push   esi
    push   ebx
    mov    WORD PTR [esi+0x2],ax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_sendtoSlot
    cmp    eax,0xffffffff
    je     Branch34
    mov    DWORD PTR [ebp-0x1c],edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::WS2_32_recvfromSlot
    lea    esp,[esp+0x0]
  Branch31:
    mov    edx,DWORD PTR [ebp-0x1c]
    cmp    edx,DWORD PTR [ebp-0x18]
    jge    Branch32
    mov    edx,DWORD PTR [ebp-0x14]
    lea    eax,[ebp-0x30]
    push   eax
    lea    ecx,[ebp-0x54]
    push   ecx
    push   0x0
    push   0x400
    push   edx
    push   ebx
    call   edi
    cmp    eax,0xffffffff
    mov    DWORD PTR [ebp-0x20],eax
    jne    Branch33
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAGetLastErrorSlot
    cmp    eax,0x2733
    jne    Branch34
    push   0x5
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_SleepSlot
    add    DWORD PTR [ebp-0x1c],0x5
    jmp    Branch31
  Branch32:
    mov    eax,DWORD PTR [ebp-0x20]
  Branch33:
    mov    edx,DWORD PTR [ebp-0x14]
    lea    ecx,[ebp-0x54]
    push   ecx
    push   eax
    push   edx
    call   R6GameServiceAddresses::ReadPingReply
    add    esp,0xc
    mov    DWORD PTR [ebp-0x24],eax
  Branch34:
    test   esi,esi
    je     Branch35
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch35:
    mov    eax,DWORD PTR [ebp-0x14]
  Branch36:
    test   eax,eax
    je     Branch37
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x8]
  Branch37:
    cmp    ebx,0xffffffff
    je     Branch38
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_closesocketSlot
  Branch38:
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSACleanupSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp-0x24]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
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
