#include "native_addresses.h"
#include "native_records.h"

// Native primary76c1c/COL78d8c/type8c40c names clTCPProtocol; no full layout or original member spelling inferred.

// R6GameService.dll data @ 100801b0 : native TCP protocol lifetime record.
const R6GameServiceNative::UnwindEntry ConstructQueuedConnectionUnwindMap[3] = {
  {-1, R6GameServiceAddresses::ConstructQueuedConnectionUnwind1},
  {0x0, R6GameServiceAddresses::ConstructQueuedConnectionUnwind2},
  {0x1, R6GameServiceAddresses::ConstructQueuedConnectionUnwind3},
};

// R6GameService.dll data @ 100801c8 : native TCP protocol lifetime record.
const R6GameServiceNative::FuncInfo ConstructQueuedConnectionExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ConstructQueuedConnectionUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 100801e4 : native TCP protocol lifetime record.
const R6GameServiceNative::UnwindEntry DestroyQueuedConnectionMembersUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyQueuedConnectionMembersUnwind1},
  {0x0, R6GameServiceAddresses::DestroyQueuedConnectionMembersUnwind2},
  {0x1, R6GameServiceAddresses::DestroyQueuedConnectionMembersUnwind3},
};

// R6GameService.dll data @ 100801fc : native TCP protocol lifetime record.
const R6GameServiceNative::FuncInfo DestroyQueuedConnectionMembersExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::DestroyQueuedConnectionMembersUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Constructs two lists/socket context, installs protocol table and initializes status plus two separate time samples.
// Optional base initialization, saved receiver/flag and exact three-state cleanup retain native publication order.
// R6GameService.dll @ 1002e540 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructQueuedConnection(void *owner,uint initializeBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ConstructQueuedConnectionSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x18]
    push   ebx
    push   esi
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],ebx
    je     Branch1
    mov    DWORD PTR [esi+0x4],0x10076c20
    mov    DWORD PTR [esp+0x8],0x1
    mov    DWORD PTR [esp+0x18],ebx
  Branch1:
    push   0x1
    lea    ecx,[esi+0x8]
    call   R6GameServiceAddresses::ConstructCircularList
    push   0x1
    lea    ecx,[esi+0x1c]
    mov    DWORD PTR [esp+0x1c],0x1
    call   R6GameServiceAddresses::ConstructCircularList
    push   0x1
    lea    ecx,[esi+0x30]
    mov    BYTE PTR [esp+0x1c],0x2
    call   R6GameServiceAddresses::InitializeSocketContext
    push   ebx
    mov    DWORD PTR [esi],R6GameServiceAddresses::clTCPProtocolVTable
    mov    DWORD PTR [esi+0x40],ebx
    mov    DWORD PTR [esi+0x50],ebx
    call   R6GameServiceAddresses::time
    push   ebx
    mov    DWORD PTR [esi+0x48],eax
    call   R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esp+0x18]
    add    esp,0x8
    mov    DWORD PTR [esi+0x4c],eax
    mov    BYTE PTR [esi+0x44],bl
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Destroys members, then reloads low deletion flag and optionally frees cached owner, returning that owner.
// R6GameService.dll @ 1002e5f0 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteQueuedConnection(void *owner,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyQueuedConnectionMembers
    test   BYTE PTR [esp+0x8],0x1
    je     Branch2
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Reinstalls protocol table, closes the connection and destroys socket context and two lists in reverse order.
// State lowers before each destructor; final list return survives and interrupted current cleanup is not retried.
// R6GameService.dll @ 1002e620 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyQueuedConnectionMembers(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyQueuedConnectionMembersSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clTCPProtocolVTable
    mov    DWORD PTR [esp+0x10],0x2
    call   R6GameServiceAddresses::CloseConnectionAndClearSendQueue
    lea    ecx,[esi+0x30]
    mov    BYTE PTR [esp+0x10],0x1
    call   R6GameServiceAddresses::list_node_support_NoOp
    lea    ecx,[esi+0x1c]
    mov    BYTE PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::DestroyCircularList
    lea    ecx,[esi+0x8]
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   R6GameServiceAddresses::DestroyCircularList
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Clears ready/send queue, closes embedded socket and publishes socket error only when close returns AL0.
// Returns semantic AL1/0 with raw upper EAX from close/error helper; queue result is ignored.
// R6GameService.dll @ 1002e910 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CloseConnectionAndClearSendQueue(int owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   edi
    lea    ecx,[esi+0x1c]
    mov    BYTE PTR [esi+0x44],0x0
    call   R6GameServiceAddresses::ClearBlockQueue
    lea    edi,[esi+0x30]
    mov    ecx,edi
    call   R6GameServiceAddresses::CloseSocketAndReset
    test   al,al
    jne    Branch3
    mov    ecx,edi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [esi+0x40],eax
    pop    edi
    xor    al,al
    pop    esi
    ret
  Branch3:
    pop    edi
    mov    al,0x1
    pop    esi
    ret
  }
}

// If saved flag bit0 is set, forwards current saved owner+54 to empty cleanup.
// R6GameService.dll @ 10065de0 : native control/access order and raw ABI retained.
__declspec(naked) void ConstructQueuedConnectionUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x54
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Destroys the first list at current saved owner+8 during construction unwind.
// R6GameService.dll @ 10065dfa : native control/access order and raw ABI retained.
__declspec(naked) void ConstructQueuedConnectionUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Destroys the second list at current saved owner+1c during construction unwind.
// R6GameService.dll @ 10065e05 : native control/access order and raw ABI retained.
__declspec(naked) void ConstructQueuedConnectionUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Destroys the first list at current saved owner+8 during destruction unwind.
// R6GameService.dll @ 10065e20 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyQueuedConnectionMembersUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Destroys the second list at current saved owner+1c during destruction unwind.
// R6GameService.dll @ 10065e2b : native control/access order and raw ABI retained.
__declspec(naked) void DestroyQueuedConnectionMembersUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Forwards current saved owner+30 through the genuine empty socket-context cleanup alias.
// R6GameService.dll @ 10065e36 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyQueuedConnectionMembersUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x30
    jmp    R6GameServiceAddresses::ForwardToNoOp
  }
}

// Selects the constructor three-state list/base lifetime map.
// R6GameService.dll @ 10065e10 : native control/access order and raw ABI retained.
__declspec(naked) void ConstructQueuedConnectionSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructQueuedConnectionExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the destructor three-state list/socket-context lifetime map.
// R6GameService.dll @ 10065e41 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyQueuedConnectionMembersSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyQueuedConnectionMembersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Stores idle seconds at+50 and returns argument upper EAX with AL1.
// R6GameService.dll @ 1002e6a0 : native control/access order and raw ABI retained.
uint __thiscall SetReceiveIdleLimit(void *connection,uint idleSeconds)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(connection) + 0x50) = idleSeconds;
  return (idleSeconds & 0xffffff00) | 1;
}

// Receives1000-byte chunks into the FIFO and timestamps positive counts even when append rejects them.
// Unsigned idle timeout sets97; current socket error can override it. Sticky owner error determines final AL.
// R6GameService.dll @ 1002e6b0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall PumpConnectionReceiveQueue(int connection)
{
  __asm {
    sub    esp,0x3e8
    push   ebx
    push   edi
    mov    edi,ecx
    push   esi
    lea    ebx,[edi+0x30]
  Branch5:
    lea    eax,[esp+0xc]
    push   0x3e8
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::ReceiveSocketBytes
    mov    esi,eax
    test   esi,esi
    jle    Branch6
    lea    ecx,[esp+0xc]
    push   esi
    push   ecx
    lea    ecx,[edi+0x8]
    call   R6GameServiceAddresses::AppendBytesToBlockQueue
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    mov    DWORD PTR [edi+0x4c],eax
  Branch6:
    cmp    esi,0x3e8
    je     Branch5
    push   0x0
    call   R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [edi+0x50]
    add    esp,0x4
    test   ecx,ecx
    jbe    Branch7
    mov    edx,DWORD PTR [edi+0x4c]
    mov    esi,eax
    sub    esi,edx
    cmp    esi,ecx
    jbe    Branch7
    push   edx
    push   eax
    push   R6GameServiceAddresses::TextTimeoutDD
    mov    DWORD PTR [edi+0x40],0x97
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0xc
  Branch7:
    mov    ecx,ebx
    call   R6GameServiceAddresses::GetSocketLastError
    test   eax,eax
    pop    esi
    je     Branch8
    mov    ecx,ebx
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [edi+0x40],eax
  Branch8:
    mov    eax,DWORD PTR [edi+0x40]
    pop    edi
    test   eax,eax
    sete   al
    pop    ebx
    add    esp,0x3e8
    ret
  }
}

// Peeks/sends with signed1000-byte cap, consumes positive provider counts and timestamps even rejected consumption.
// Prefix/consume results are ignored; a stopped send leaves socket error separate from sticky owner error.
// R6GameService.dll @ 1002e760 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall FlushConnectionSendQueue(int connection)
{
  __asm {
    sub    esp,0x3e8
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
  Branch9:
    mov    ebx,DWORD PTR [esi+0x28]
    test   ebx,ebx
    je     Branch11
    cmp    ebx,0x3e8
    jle    Branch10
    mov    ebx,0x3e8
  Branch10:
    lea    eax,[esp+0xc]
    lea    edi,[esi+0x1c]
    push   eax
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyBlockQueuePrefix
    lea    ecx,[esp+0xc]
    push   ebx
    push   ecx
    lea    ecx,[esi+0x30]
    call   R6GameServiceAddresses::SendSocketBytes
    test   eax,eax
    jle    Branch11
    lea    edx,[esp+0xc]
    mov    ecx,edi
    push   edx
    push   eax
    call   R6GameServiceAddresses::ConsumeBlockQueueBytes
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    mov    DWORD PTR [esi+0x48],eax
    jmp    Branch9
  Branch11:
    mov    eax,DWORD PTR [esi+0x40]
    pop    edi
    test   eax,eax
    pop    esi
    pop    ebx
    sete   al
    add    esp,0x3e8
    ret
  }
}

// Sends directly only with empty queue; queues a suffix after prior progress, or appends immediately to an existing queue.
// Append status is ignored; late original source/length and mutable progress byte retain native alias/raw EAX effects.
// R6GameService.dll @ 1002e7d0 : native control/access order and raw ABI retained.
__declspec(naked) char __thiscall SendOrQueueConnectionBytes(void *connection,int source,uint byteCount)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,ecx
    xor    al,al
    push   esi
    push   edi
    mov    ecx,DWORD PTR [ebp+0x28]
    mov    BYTE PTR [esp+0x13],al
    test   ecx,ecx
    jne    Branch16
    mov    ecx,DWORD PTR [esp+0x1c]
    xor    edi,edi
    test   ecx,ecx
    mov    ebx,ecx
    mov    esi,0x1
    jle    Branch17
  Branch12:
    test   esi,esi
    jle    Branch15
    cmp    ebx,0x3e8
    mov    eax,0x3e8
    jg     Branch13
    mov    eax,ebx
  Branch13:
    push   eax
    mov    eax,DWORD PTR [esp+0x1c]
    lea    ecx,[edi+eax*1]
    push   ecx
    lea    ecx,[ebp+0x30]
    call   R6GameServiceAddresses::SendSocketBytes
    mov    esi,eax
    test   esi,esi
    jle    Branch14
    push   0x0
    sub    ebx,esi
    add    edi,esi
    mov    BYTE PTR [esp+0x17],0x1
    call   R6GameServiceAddresses::time
    add    esp,0x4
    mov    DWORD PTR [ebp+0x48],eax
  Branch14:
    mov    al,BYTE PTR [esp+0x13]
    mov    ecx,DWORD PTR [esp+0x1c]
    test   ebx,ebx
    jg     Branch12
  Branch15:
    test   al,al
    je     Branch17
    test   ebx,ebx
    je     Branch17
    mov    edx,DWORD PTR [esp+0x18]
    sub    ecx,edi
    add    edi,edx
    push   ecx
    push   edi
    lea    ecx,[ebp+0x1c]
    call   R6GameServiceAddresses::AppendBytesToBlockQueue
    mov    al,BYTE PTR [esp+0x13]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  Branch16:
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x18]
    push   eax
    push   ecx
    lea    ecx,[ebp+0x1c]
    call   R6GameServiceAddresses::AppendBytesToBlockQueue
    mov    al,0x1
  Branch17:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// Sends through socket+30, copying a nonzero current socket error through a second load and preserving full send result.
// R6GameService.dll @ 1002e890 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall SendConnectionBytes(void *connection,uint source,uint byteCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    push   eax
    push   ecx
    lea    esi,[edi+0x30]
    mov    ecx,esi
    call   R6GameServiceAddresses::SendSocketBytes
    mov    ecx,esi
    mov    ebx,eax
    call   R6GameServiceAddresses::GetSocketLastError
    test   eax,eax
    je     Branch18
    mov    ecx,esi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [edi+0x40],eax
  Branch18:
    pop    edi
    mov    eax,ebx
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Receives through socket+30, copying a nonzero current socket error through a second load and preserving full result.
// R6GameService.dll @ 1002e8d0 : native control/access order and raw ABI retained.
__declspec(naked) int __thiscall ReceiveConnectionBytes(void *connection,uint destination,uint byteCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    push   eax
    push   ecx
    lea    esi,[edi+0x30]
    mov    ecx,esi
    call   R6GameServiceAddresses::ReceiveSocketBytes
    mov    ecx,esi
    mov    ebx,eax
    call   R6GameServiceAddresses::GetSocketLastError
    test   eax,eax
    je     Branch19
    mov    ecx,esi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [edi+0x40],eax
  Branch19:
    pop    edi
    mov    eax,ebx
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Queries socket+30 peer endpoint, then forces AL1 even on query failure while retaining upper EAX.
// R6GameService.dll @ 1002e950 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueryPeerEndpointAlwaysSuccess(void *owner,char *addressTextOut,ushort *portOut)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    push   edx
    add    ecx,0x30
    call   R6GameServiceAddresses::GetSocketPeerIPv4Endpoint
    mov    al,0x1
    ret    0x8
  }
}

// Queries socket+30 local endpoint, then forces AL1 even on query failure while retaining upper EAX.
// R6GameService.dll @ 1002e970 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueryLocalEndpointAlwaysSuccess(void *owner,uint *addressOut,ushort *portOut)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x4]
    push   eax
    push   edx
    add    ecx,0x30
    call   R6GameServiceAddresses::GetSocketLocalIPv4Endpoint
    mov    al,0x1
    ret    0x8
  }
}

// Creates/binds/configures/connects socket, then publishes separate send/receive clocks and connected byte.
// Failure captures socket error and clears send queue/connected state through full protocol close; no local guard.
// R6GameService.dll @ 1002e990 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectResolvedQueuedConnection(void *connection,int hostName,uint port)
{
  __asm {
    push   esi
    mov    esi,ecx
    push   edi
    lea    edi,[esi+0x30]
    mov    ecx,edi
    call   R6GameServiceAddresses::CreateIPv4StreamSocket
    test   al,al
    je     Branch20
    push   0x0
    push   0x0
    mov    ecx,edi
    call   R6GameServiceAddresses::BindIPv4Socket
    test   al,al
    je     Branch20
    push   0x1
    mov    ecx,edi
    call   R6GameServiceAddresses::SetSocketNonblocking
    test   al,al
    je     Branch20
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xc]
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ConnectResolvedIPv4
    test   al,al
    je     Branch20
    push   0x1
    mov    ecx,edi
    call   R6GameServiceAddresses::SetTcpNoDelay
    test   al,al
    jne    Branch21
  Branch20:
    mov    ecx,edi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    ecx,esi
    mov    DWORD PTR [esi+0x40],eax
    call   R6GameServiceAddresses::CloseConnectionAndClearSendQueue
    pop    edi
    xor    al,al
    pop    esi
    ret    0x8
  Branch21:
    push   0x0
    mov    DWORD PTR [esi+0x40],0x0
    call   R6GameServiceAddresses::time
    push   0x0
    mov    DWORD PTR [esi+0x48],eax
    call   R6GameServiceAddresses::time
    add    esp,0x8
    mov    DWORD PTR [esi+0x4c],eax
    mov    BYTE PTR [esi+0x44],0x1
    mov    al,0x1
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Creates/binds/configures/connects socket, then publishes separate clocks and connected byte.
// Failure closes only socket and formats the cached numeric address locally, retaining queues/flag and formatter upper EAX.
// R6GameService.dll @ 1002ea30 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConnectNumericQueuedConnection(void *connection,uint address,uint port)
{
  __asm {
    sub    esp,0x88
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    lea    esi,[edi+0x30]
    mov    ecx,esi
    call   R6GameServiceAddresses::CreateIPv4StreamSocket
    mov    ebx,DWORD PTR [esp+0x98]
    test   al,al
    je     Branch22
    push   0x0
    push   0x0
    mov    ecx,esi
    call   R6GameServiceAddresses::BindIPv4Socket
    test   al,al
    je     Branch22
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketNonblocking
    test   al,al
    je     Branch22
    mov    eax,DWORD PTR [esp+0x9c]
    mov    ecx,esi
    push   eax
    push   ebx
    call   R6GameServiceAddresses::ConnectIPv4
    test   al,al
    je     Branch22
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::SetTcpNoDelay
    test   al,al
    jne    Branch23
  Branch22:
    mov    ecx,esi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    ecx,esi
    mov    DWORD PTR [edi+0x40],eax
    call   R6GameServiceAddresses::CloseSocketAndReset
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohlSlot
    mov    DWORD PTR [esp+0xc],eax
    mov    ecx,DWORD PTR [esp+0xd]
    mov    edx,DWORD PTR [esp+0xe]
    and    eax,0xff
    push   eax
    mov    eax,DWORD PTR [esp+0x13]
    and    ecx,0xff
    and    edx,0xff
    push   ecx
    and    eax,0xff
    push   edx
    push   eax
    push   R6GameServiceAddresses::TextDDDD
    lea    ecx,[esp+0x28]
    push   0x10
    push   ecx
    call   R6GameServiceAddresses::_snprintf
    add    esp,0x1c
    xor    al,al
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x88
    ret    0x8
  Branch23:
    push   0x0
    mov    DWORD PTR [edi+0x40],0x0
    call   R6GameServiceAddresses::time
    push   0x0
    mov    DWORD PTR [edi+0x48],eax
    call   R6GameServiceAddresses::time
    add    esp,0x8
    mov    DWORD PTR [edi+0x4c],eax
    mov    BYTE PTR [edi+0x44],0x1
    mov    al,0x1
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x88
    ret    0x8
  }
}

// Native virtual-table prefix: clTCPProtocolVTable
// R6GameService.dll data @ 10076c1c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clTCPProtocolVTableRecord {
  R6GameServiceNative::Address DeleteQueuedConnection; // +0x00
};
const clTCPProtocolVTableRecord clTCPProtocolVTable = {R6GameServiceAddresses::DeleteQueuedConnection};
