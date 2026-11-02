#include "native_addresses.h"
#include "native_records.h"

// Datagram-owner methods and associated lifetime actions; original concrete class spelling remains unresolved.

// Optionally installs base-offset table, initializes socket+c, then publishes receive/send sizes in native order.
// Three stack words, RETc; optional flag/state and empty-base exceptional cleanup remain explicit.
// R6GameService.dll @ 1002eb30 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructDatagramSocketOwner(
    void *owner,int sendBufferSize,int receiveBufferSize,uint initializeBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ConstructDatagramSocketOwnerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x24]
    xor    eax,eax
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x8],esi
    mov    DWORD PTR [esp+0x4],eax
    je     Branch1
    mov    DWORD PTR [esi],R6GameServiceAddresses::GDatagramOwnerData
    mov    DWORD PTR [esp+0x4],0x1
    mov    DWORD PTR [esp+0x14],eax
  Branch1:
    push   0x1
    lea    ecx,[esi+0xc]
    call   R6GameServiceAddresses::InitializeSocketContext
    mov    ecx,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x8],ecx
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0xc
  }
}

// Closes socket+c, lowers lifetime state, then invokes genuine empty cleanup; raw close EAX survives.
// Exceptional cleanup forwards current saved owner+c to empty target without retrying close.
// R6GameService.dll @ 1002eba0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyDatagramSocketOwner(int owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyDatagramSocketOwnerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    DWORD PTR [esp+0x4],ecx
    lea    esi,[ecx+0xc]
    mov    DWORD PTR [esp+0x10],0x0
    mov    ecx,esi
    call   R6GameServiceAddresses::CloseSocketAndReset
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Creates/configures/binds a datagram socket, ignoring all pre-bind status results.
// Current signed-positive buffer sizes, late flags/address/port, sticky owner error and bind AL status retain native order.
// R6GameService.dll @ 1002ebf0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenDatagramSocket(
    void *owner,uint address,uint port,char broadcast,char reuse)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    lea    esi,[edi+0xc]
    mov    ecx,esi
    call   R6GameServiceAddresses::CreateIPv4DatagramSocket
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketNonblocking
    mov    al,BYTE PTR [esp+0x18]
    test   al,al
    je     Branch2
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketReuseAddress
  Branch2:
    mov    al,BYTE PTR [esp+0x14]
    test   al,al
    je     Branch3
    push   0x1
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketBroadcast
  Branch3:
    mov    eax,DWORD PTR [edi+0x4]
    test   eax,eax
    jle    Branch4
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketSendBufferSize
  Branch4:
    mov    eax,DWORD PTR [edi+0x8]
    test   eax,eax
    jle    Branch5
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::SetSocketReceiveBufferSize
  Branch5:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xc]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::BindIPv4Socket
    test   al,al
    jne    Branch6
    push   R6GameServiceAddresses::TextUdpBindError
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [edi+0x1c],eax
    pop    edi
    xor    al,al
    pop    esi
    ret    0x10
  Branch6:
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x10
  }
}

// Closes socket+c then forces AL1, preserving close upper EAX and leaving owner error untouched.
// R6GameService.dll @ 1002ec90 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CloseDatagramSocket(int owner)
{
  __asm {
    add    ecx,0xc
    call   R6GameServiceAddresses::CloseSocketAndReset
    mov    al,0x1
    ret
  }
}

// Sends through socket+c and compares full result to cached requested count; only AL changes to equality status.
// R6GameService.dll @ 1002eca0 : native control/access order and raw ABI retained.
__declspec(naked) bool __thiscall SendDatagramToResolvedIPv4(
    void *owner,uint bytes,int byteCount,int hostName,uint port)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   esi
    push   eax
    add    ecx,0xc
    call   R6GameServiceAddresses::SendSocketBytesToResolvedIPv4
    cmp    eax,esi
    pop    esi
    sete   al
    ret    0x10
  }
}

// Sends through socket+c and compares full result to cached requested count; only AL changes to equality status.
// R6GameService.dll @ 1002ecd0 : native control/access order and raw ABI retained.
__declspec(naked) bool __thiscall SendDatagramToIPv4(
    void *owner,void *bytes,int byteCount,uint address,uint port)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   esi
    push   eax
    add    ecx,0xc
    call   R6GameServiceAddresses::SendSocketBytesToIPv4
    cmp    eax,esi
    pop    esi
    sete   al
    ret    0x10
  }
}

// Receives into an initial1024-byte growable temporary, publishes count/error, then copies positive current count to new storage.
// Count/output/local reloads, unchecked allocations/forward copies and current temporary release have no local EH guard.
// R6GameService.dll @ 1002ed00 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall datagram_socket_support_ReceiveDatagramWithTextSender(
    void *owner,char *addressText,ushort *port,uint *received)
{
  __asm {
    push   ecx
    push   ebx
    push   esi
    push   edi
    push   0x400
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[esi+0xc]
    push   eax
    push   ecx
    lea    edx,[esp+0x14]
    push   0x400
    push   edx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReceiveDatagramWithTextSender
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    ecx,edi
    mov    DWORD PTR [ebx],eax
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [esi+0x1c],eax
    mov    eax,DWORD PTR [ebx]
    test   eax,eax
    jle    Branch8
    push   ebp
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebx]
    mov    esi,DWORD PTR [esp+0x10]
    mov    ebp,eax
    mov    eax,ecx
    mov    edi,ebp
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    eax,DWORD PTR [esp+0x10]
    test   eax,eax
    je     Branch7
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch7:
    mov    eax,ebp
    pop    ebp
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  Branch8:
    mov    eax,DWORD PTR [esp+0xc]
    test   eax,eax
    je     Branch9
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch9:
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Receives into an initial1024-byte growable temporary, publishes count/error, then copies positive current count to new storage.
// Count/output/local reloads, unchecked allocations/forward copies and current temporary release have no local EH guard.
// R6GameService.dll @ 1002eda0 : native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall datagram_socket_support_ReceiveDatagramWithIPv4Sender(
    void *owner,uint *address,ushort *port,uint *received)
{
  __asm {
    push   ecx
    push   ebx
    push   esi
    push   edi
    push   0x400
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[esi+0xc]
    push   eax
    push   ecx
    lea    edx,[esp+0x14]
    push   0x400
    push   edx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReceiveDatagramWithIPv4Sender
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    ecx,edi
    mov    DWORD PTR [ebx],eax
    call   R6GameServiceAddresses::GetSocketLastError
    mov    DWORD PTR [esi+0x1c],eax
    mov    eax,DWORD PTR [ebx]
    test   eax,eax
    jle    Branch11
    push   ebp
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebx]
    mov    esi,DWORD PTR [esp+0x10]
    mov    ebp,eax
    mov    eax,ecx
    mov    edi,ebp
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    eax,DWORD PTR [esp+0x10]
    test   eax,eax
    je     Branch10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch10:
    mov    eax,ebp
    pop    ebp
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  Branch11:
    mov    eax,DWORD PTR [esp+0xc]
    test   eax,eax
    je     Branch12
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    pop    edi
    pop    esi
    xor    eax,eax
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// When the current saved flag mask1 is set, forwards saved owner+20 to genuine empty base cleanup.
// R6GameService.dll @ 10065e50 : native control/access order and raw ABI retained.
__declspec(naked) void ConstructDatagramSocketOwnerUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch13
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch13:
    ret
  }
}

// Selects datagram-owner constructor one-state conditional empty-base cleanup record.
// R6GameService.dll @ 10065e6a : native control/access order and raw ABI retained.
__declspec(naked) void ConstructDatagramSocketOwnerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructDatagramSocketOwnerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Forwards current saved owner+c through shared empty socket-context cleanup without close or release.
// R6GameService.dll @ 10065e80 : native control/access order and raw ABI retained.
__declspec(naked) void DestroyDatagramSocketOwnerUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::ForwardToNoOp
  }
}

// Selects datagram-owner destructor one-state empty socket-context cleanup record.
// R6GameService.dll @ 10065e8b : native control/access order and raw ABI retained.
__declspec(naked) void DestroyDatagramSocketOwnerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyDatagramSocketOwnerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10076c28 : native datagram-owner base-offset table.
const R6GameServiceNative::BaseOffsets<1> GDatagramOwnerData = {0x0, {0x20}};

// R6GameService.dll data @ 10080218 : native datagram-owner lifetime record.
const R6GameServiceNative::UnwindEntry ConstructDatagramSocketOwnerUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ConstructDatagramSocketOwnerUnwind1},
};

// R6GameService.dll data @ 10080220 : native datagram-owner lifetime record.
// R6GameService.dll data @ 10080218 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructDatagramSocketOwnerExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ConstructDatagramSocketOwnerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1008023c : native datagram-owner lifetime record.
const R6GameServiceNative::UnwindEntry DestroyDatagramSocketOwnerUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyDatagramSocketOwnerUnwind1},
};

// R6GameService.dll data @ 10080244 : native datagram-owner lifetime record.
// R6GameService.dll data @ 1008023c : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyDatagramSocketOwnerExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyDatagramSocketOwnerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
