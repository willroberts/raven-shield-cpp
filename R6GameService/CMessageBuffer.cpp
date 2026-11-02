#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007f99c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MessageBufferConstructionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007f9e0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MessageBufferDestructionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fa0c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MessageBufferReceiveExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007fa30 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo MessageBufferQueueExceptionHandlerFunctionInfo;

// Constructs two queue heads and a socket with staged cleanup, retaining raw port and open-status behavior.
// R6GameService.dll @ 10028830 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall ConstructCMessageBuffer(void *object,ushort localPort,int initializeSecondaryTable)
{
  __asm {
    // Frame locals: construction flags-0x18, saved receiver-0x14, staged queue-0x10, EH-c/-8/-4.
    push   0xffffffff
    push   R6GameServiceAddresses::MessageBufferConstructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x4],ebx
    mov    eax,DWORD PTR [esp+0x24]
    push   esi
    mov    esi,ecx
    test   eax,eax
    push   edi
    mov    DWORD PTR [esp+0x10],esi
    je Branch1
    mov    DWORD PTR [esi+0x4],0x10076ac0
    mov    ebx,0x1
  Branch1:
    // Install allocator base and stage first queue; flag4 and state3 protect its initializer/tag and sentinel allocation.
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    lea    edi,[esi+0x10]
    or     ebx,0x4
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [edi+0x4],0x10076ab8
    lea    eax,[esp+0x2c]
    push   0x0
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],0x3
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    // Stage send queue and flag8/state6; completed first queue remains covered by state4.
    lea    edi,[esi+0x18]
    or     ebx,0x8
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [edi+0x4],0x10076ab8
    lea    ecx,[esp+0x2c]
    push   0x0
    push   ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x28],0x6
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push   0xc
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [edi],eax
    // Enter state4, load original port late and publish primary table before socket allocation.
    mov    DWORD PTR [esp+0x20],0x4
    mov    dx,WORD PTR [esp+0x28]
    push   0x20
    mov    DWORD PTR [esi],R6GameServiceAddresses::CMessageBufferVTable
    mov    WORD PTR [esi+0xe],dx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Original port argument becomes raw socket allocation; only low state byte changes to8 around construction.
    mov    DWORD PTR [esp+0x28],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x20],0x8
    je Branch2
    push   0x1
    push   0x0
    push   0x0
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructDatagramSocketOwner
    jmp Branch3
  Branch2:
    xor    eax,eax
  Branch3:
    // Preserve upper ECX while replacing CX with port; lower state byte to7 before socket publication/open.
    mov    cx,WORD PTR [esi+0xe]
    push   0x0
    push   0x0
    push   ecx
    push   0x0
    mov    ecx,eax
    mov    BYTE PTR [esp+0x30],0x7
    mov    DWORD PTR [esi+0x8],eax
    call   R6GameServiceAddresses::OpenDatagramSocket
    // Publish raw open AL, restore previous FS and return saved receiver without normalizing socket status.
    mov    ecx,DWORD PTR [esp+0x18]
    mov    BYTE PTR [esi+0xc],al
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x8
  }
}

// Destroys message-buffer members and conditionally frees the saved receiver for deletion flag bit zero.
// R6GameService.dll @ 10028960 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall DeleteCMessageBuffer(void *object,byte flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyCMessageBufferFields
    test   BYTE PTR [esp+0x8],0x1
    je Branch4
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch4:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Releases socket, queued packets and queue heads in native order, leaving the final free residue in EAX.
// R6GameService.dll @ 10028980 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall DestroyCMessageBufferFields(void *object)
{
  __asm {
    // Frame locals: saved receiver-0x14 and staged queue-0x10; all socket/packet cleanup initially runs in state2.
    push   0xffffffff
    push   R6GameServiceAddresses::MessageBufferDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x8],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::CMessageBufferVTable
    mov    edi,DWORD PTR [esi+0x8]
    mov    DWORD PTR [esp+0x18],0x2
    test   edi,edi
    je Branch5
    // Destroy/free the cached socket; clear object+8 only after both calls return.
    mov    ecx,edi
    call   R6GameServiceAddresses::DestroyDatagramSocketOwner
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch5:
    mov    ecx,esi
    mov    DWORD PTR [esi+0x8],0x0
    call   R6GameServiceAddresses::ClearMessageBufferQueues
    // After clearing both packet queues, stage send queue/state3, clear residual nodes and reload/free its head.
    lea    edi,[esi+0x18]
    mov    DWORD PTR [esp+0xc],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x18],0x3
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edi,DWORD PTR [edi]
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    // Stage first queue/state4 and reload/free its sentinel; retain dangling queue slots and final free EAX.
    lea    edi,[esi+0x10]
    mov    DWORD PTR [esp+0xc],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x18],0x4
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Sends every pending datagram and clears the queue regardless of send status, preserving native reloads and raw return.
// R6GameService.dll @ 10028a20 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall FlushPendingDatagrams(void *object)
{
  __asm {
    // Cache receiver in ESI; unopened port replaces only AX, retaining incoming EAX high word.
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0xc]
    test   al,al
    jne Branch6
    mov    ax,WORD PTR [esi+0xe]
    mov    ecx,DWORD PTR [esi+0x8]
    push   0x1
    push   0x0
    push   eax
    push   0x0
    call   R6GameServiceAddresses::OpenDatagramSocket
    test   al,al
    mov    BYTE PTR [esi+0xc],al
    jne Branch6
    pop    esi
    ret
  Branch6:
    // Reload send head and traverse current nodes; each port replaces only CX before loading socket receiver.
    mov    eax,DWORD PTR [esi+0x18]
    push   edi
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je Branch8
  Branch7:
    mov    eax,DWORD PTR [edi+0x8]
    mov    cx,WORD PTR [eax+0x82]
    mov    edx,DWORD PTR [eax+0x88]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    mov    eax,DWORD PTR [eax+0x84]
    push   edx
    push   eax
    call   R6GameServiceAddresses::SendDatagramToResolvedIPv4
    // Ignore send status; reload node payload for buffer free, reload payload again for record free, then read next.
    mov    ecx,DWORD PTR [edi+0x8]
    mov    edx,DWORD PTR [ecx+0x84]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [edi+0x8]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edi,DWORD PTR [edi]
    mov    eax,DWORD PTR [esi+0x18]
    cmp    edi,eax
    jne Branch7
  Branch8:
    // Restart node pass from reloaded owner head; cache next before each node free, reload head afterward.
    mov    eax,DWORD PTR [esi+0x18]
    mov    edi,DWORD PTR [eax]
    cmp    edi,eax
    je Branch10
  Branch9:
    mov    eax,edi
    mov    edi,DWORD PTR [edi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    edi,DWORD PTR [esi+0x18]
    jne Branch9
  Branch10:
    // Reset next and previous through separate head loads; return first head upper EAX with AL1.
    mov    eax,DWORD PTR [esi+0x18]
    pop    edi
    mov    DWORD PTR [eax],eax
    mov    esi,DWORD PTR [esi+0x18]
    mov    al,0x1
    mov    DWORD PTR [esi+0x4],esi
    pop    esi
    ret
  }
}

// Receives and decodes a D3 message into a destination list, preserving raw status, socket recovery and cleanup.
// R6GameService.dll @ 10028ac0 : complete native frame/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReceiveAndDecodeTaggedPayload(void *object,char *senderAddress,ushort *senderPort,void *destinationList)
{
  __asm {
    // Frame: size/socket-0xb8/-0xb4, CD-key message-0xb0, record address-0x98, port-0x16, copy/size-0x14/-0x10.
    mov    eax,fs:0x0
    push   0xffffffff
    push   R6GameServiceAddresses::MessageBufferReceiveExceptionHandler
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xac
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    al,BYTE PTR [esi+0xc]
    test   al,al
    jne Branch11
    // Replace only AX with local port; preserve upper EAX from the previous FS value when forwarding the stack word.
    mov    ax,WORD PTR [esi+0xe]
    mov    ecx,DWORD PTR [esi+0x8]
    push   0x1
    push   0x0
    push   eax
    push   0x0
    call   R6GameServiceAddresses::OpenDatagramSocket
    test   al,al
    mov    BYTE PTR [esi+0xc],al
    je Branch17
  Branch11:
    // Load original sender argument slots after optional open; cache port pointer in EBX and initialize received size.
    mov    ebx,DWORD PTR [esp+0xd0]
    mov    edx,DWORD PTR [esp+0xcc]
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x10],0x0
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   ebx
    push   edx
    call   R6GameServiceAddresses::datagram_socket_support_ReceiveDatagramWithTextSender
    mov    ebp,eax
    test   ebp,ebp
    je Branch13
    // Reload received size after unchecked allocation; copy dwords/bytes, retaining frame copy pointer and size.
    mov    eax,DWORD PTR [esp+0x10]
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x10]
    mov    esi,ebp
    mov    DWORD PTR [esp+0xb8],ecx
    mov    edx,ecx
    mov    edi,eax
    mov    DWORD PTR [esp+0xb4],eax
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    push   ebp
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    // Release received storage before copying128 address bytes; no receive-side record terminator is added.
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0xcc]
    push   0x80
    lea    ecx,[esp+0x34]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0xc4]
    mov    ecx,DWORD PTR [esp+0xc0]
    mov    dx,WORD PTR [ebx]
    add    esp,0xc
    mov    WORD PTR [esp+0xb2],dx
    push   0x1
    push   eax
    push   ecx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::InitializeSerializedPayload
    // Reload destination argument after constructing message; enter state0 only after construction returns.
    mov    edx,DWORD PTR [esp+0xd4]
    lea    ecx,[esp+0x18]
    push   edx
    mov    DWORD PTR [esp+0xc8],0x0
    call   R6GameServiceAddresses::DecodeTaggedPayloadToList
    // Retain raw decoder AL in BL; release current frame copy pointer if nonnull before lowering cleanup state.
    mov    bl,al
    mov    eax,DWORD PTR [esp+0xb4]
    test   eax,eax
    je Branch12
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    // Lower state, publish CD-key table, clean actual message fields, then replace only AL with saved decoder byte.
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0xc4],0xffffffff
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clCDKeyMessageVTable
    call   R6GameServiceAddresses::DestroyTaggedPayloadFields
    mov    al,bl
    jmp Branch18
  Branch13:
    // Dereference current socket+0x1c before its null test; recover only for exact status0x2746.
    mov    edi,DWORD PTR [esi+0x8]
    cmp    DWORD PTR [edi+0x1c],0x2746
    jne Branch17
    test   edi,edi
    je Branch14
    mov    ecx,edi
    call   R6GameServiceAddresses::DestroyDatagramSocketOwner
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch14:
    // Stage raw replacement at frame-0xb4 and enter state1 around construction, retaining null-allocation behavior.
    push   0x20
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x14],eax
    test   eax,eax
    mov    DWORD PTR [esp+0xc4],0x1
    je Branch15
    push   0x1
    push   0x0
    push   0x0
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructDatagramSocketOwner
    jmp Branch16
  Branch15:
    xor    eax,eax
  Branch16:
    // Replace only CX with port; lower state before publishing new socket and reopening with last flag zero.
    mov    cx,WORD PTR [esi+0xe]
    push   0x0
    push   0x0
    push   ecx
    push   0x0
    mov    ecx,eax
    mov    DWORD PTR [esp+0xd4],0xffffffff
    mov    DWORD PTR [esi+0x8],eax
    call   R6GameServiceAddresses::OpenDatagramSocket
    mov    BYTE PTR [esi+0xc],al
  Branch17:
    // Only clear AL on false paths; upper EAX comes from native open/receive/recovery path.
    xor    al,al
  Branch18:
    mov    ecx,DWORD PTR [esp+0xbc]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xb8
    ret    0xc
  }
}

// Serializes a source list into a queued datagram record, preserving raw padding and ownership transitions.
// R6GameService.dll @ 10028c80 : complete native frame/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueSerializedDatagram(void *object,const char *address,ushort port,void *sourceList)
{
  __asm {
    // Frame record begins-0x98 and spans0x8c bytes; message-0xb0, serialized pointer/size-0x14/-0x10.
    push   0xffffffff
    push   R6GameServiceAddresses::MessageBufferQueueExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xac
    mov    ax,WORD PTR [esp+0xc0]
    push   ebp
    mov    ebp,ecx
    mov    ecx,DWORD PTR [esp+0xc0]
    push   0x80
    lea    edx,[esp+0x28]
    push   ecx
    push   edx
    mov    WORD PTR [esp+0xb2],ax
    call   R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0xd4]
    add    esp,0xc
    // Terminate only record offset0x81; offset0x80 remains untouched stack padding and port is at0x82.
    lea    ecx,[esp+0xc]
    mov    BYTE PTR [esp+0xa5],0x0
    push   0x1
    push   eax
    call   R6GameServiceAddresses::InitializeCodecBackedPayload
    // Enter state0 after construction; size query status is ignored and its frame size word is not preinitialized.
    lea    ecx,[esp+0xac]
    mov    DWORD PTR [esp+0xb8],0x0
    push   ecx
    push   0x0
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::SerializeTaggedPayload
    mov    edx,DWORD PTR [esp+0xac]
    push   edx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[esp+0xac]
    mov    DWORD PTR [esp+0xa8],eax
    push   ecx
    push   eax
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::SerializeTaggedPayload
    // Test any nonzero serializer AL; failure conditionally frees frame buffer, then cleans message with state-1.
    test   al,al
    jne Branch20
    mov    eax,DWORD PTR [esp+0xa8]
    test   eax,eax
    je Branch19
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch19:
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0xb8],0xffffffff
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clCDKeyMessageVTable
    call   R6GameServiceAddresses::DestroyTaggedPayloadFields
    xor    al,al
    jmp Branch21
  Branch20:
    // Allocate0x8c unchecked and copy35 dwords, including padding, port, buffer pointer and size.
    push   esi
    push   edi
    push   0x8c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,0x23
    lea    esi,[esp+0x2c]
    mov    edi,eax
    mov    DWORD PTR [esp+0x10],eax
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    // Cache queue-slot address, copy sentinel and pass saved packet pointer by address to actual node allocation.
    lea    esi,[ebp+0x18]
    lea    edx,[esp+0xc]
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    eax,[esp+0x10]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::AllocateListPayloadNode
    // Reload saved sentinel after allocation; lower state before publishing links, retaining packet ownership in queue.
    mov    esi,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0xc0],0xffffffff
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    // Destroy only temporary message fields after linking; return its upper EAX with AL1.
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clCDKeyMessageVTable
    call   R6GameServiceAddresses::DestroyTaggedPayloadFields
    pop    edi
    mov    al,0x1
    pop    esi
  Branch21:
    mov    ecx,DWORD PTR [esp+0xb0]
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xb8
    ret    0xc
  }
}

// Clears the first queue then tail-forwards the send-queue clear, retaining its complete native return.
// R6GameService.dll @ 10028de0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall ClearMessageBufferQueues(void *object)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ClearMessageBufferFirstQueue
    mov    ecx,esi
    pop    esi
    jmp    R6GameServiceAddresses::ClearMessageBufferSendQueue
  }
}

// Releases first-queue buffers and records, then nodes, and resets reloaded sentinel links.
// R6GameService.dll @ 10028df0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall ClearMessageBufferFirstQueue(void *object)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x10]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je Branch23
  Branch22:
    // Free current buffer, then reload payload for record free and next after both calls; head reload controls traversal.
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x84]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x8]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [edi+0x10]
    cmp    esi,eax
    jne Branch22
  Branch23:
    // Restart node-only pass; load next before release and reset links through separate final head reloads.
    mov    eax,DWORD PTR [edi+0x10]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je Branch25
  Branch24:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi+0x10]
    jne Branch24
  Branch25:
    mov    eax,DWORD PTR [edi+0x10]
    mov    DWORD PTR [eax],eax
    mov    edi,DWORD PTR [edi+0x10]
    mov    DWORD PTR [edi+0x4],edi
    pop    edi
    pop    esi
    ret
  }
}

// Releases send-queue buffers and records, then nodes, and resets reloaded sentinel links.
// R6GameService.dll @ 10028e50 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall ClearMessageBufferSendQueue(void *object)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x18]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je Branch27
  Branch26:
    // Free current buffer, then reload payload for record free and next after both calls; head reload controls traversal.
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [eax+0x84]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x8]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    esi,DWORD PTR [esi]
    mov    eax,DWORD PTR [edi+0x18]
    cmp    esi,eax
    jne Branch26
  Branch27:
    // Restart node-only pass; load next before release and reset links through separate final head reloads.
    mov    eax,DWORD PTR [edi+0x18]
    mov    esi,DWORD PTR [eax]
    cmp    esi,eax
    je Branch29
  Branch28:
    mov    eax,esi
    mov    esi,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    esi,DWORD PTR [edi+0x18]
    jne Branch28
  Branch29:
    mov    eax,DWORD PTR [edi+0x18]
    mov    DWORD PTR [eax],eax
    mov    edi,DWORD PTR [edi+0x18]
    mov    DWORD PTR [edi+0x4],edi
    pop    edi
    pop    esi
    ret
  }
}

// Forwards saved receiver+0x20 to empty cleanup when constructor flag bit zero is set.
// R6GameService.dll @ 10065770 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferAllocationContext(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test   eax,eax
    je Branch30
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch30:
    ret
  }
}

// Tail-resets the constructing saved receiver to the allocator-override base table.
// R6GameService.dll @ 1006578a : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBufferConstructionBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Forwards staged queue+8 to empty cleanup when constructor flag bit two is set.
// R6GameService.dll @ 10065792 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferFirstQueueContext(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x4
    test   eax,eax
    je Branch31
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch31:
    ret
  }
}

// Tail-forwards the original secondary-table argument address to empty first-queue tag cleanup.
// R6GameService.dll @ 100657ac : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferFirstQueueTag(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-releases nodes and sentinel for the constructing receiver first queue at+0x10.
// R6GameService.dll @ 100657b4 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ReleaseMessageBufferFirstQueue(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Forwards staged queue+8 to empty cleanup when constructor flag bit three is set.
// R6GameService.dll @ 100657bf : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferSendQueueContext(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x8
    test   eax,eax
    je Branch32
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch32:
    ret
  }
}

// Tail-forwards the original secondary-table argument address to empty send-queue tag cleanup.
// R6GameService.dll @ 100657d9 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferSendQueueTag(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-releases nodes and sentinel for the constructing receiver send queue at+0x18.
// R6GameService.dll @ 100657e1 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ReleaseMessageBufferSendQueue(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Releases the raw socket allocation staged in the original local-port argument.
// R6GameService.dll @ 100657ec : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ReleaseMessageBufferSocketAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the CMessageBuffer constructor nine-state exception metadata.
// R6GameService.dll @ 100657f6 : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageBufferConstructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MessageBufferConstructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-resets the saved destruction receiver to the allocator-override base table.
// R6GameService.dll @ 10065800 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBufferDestructionBase(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Tail-releases the saved receiver first queue during destructor unwind.
// R6GameService.dll @ 10065808 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferFirstQueueOnDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Tail-releases the saved receiver send queue during destructor unwind.
// R6GameService.dll @ 10065813 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferSendQueueOnDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Tail-forwards the staged destructor queue pointer to empty cleanup.
// R6GameService.dll @ 1006581e : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferSavedQueueOnDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-forwards the staged destructor queue pointer to the distinct final empty cleanup entry.
// R6GameService.dll @ 10065826 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageBufferSavedFirstQueueOnDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the CMessageBuffer destructor five-state exception metadata.
// R6GameService.dll @ 1006582e : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageBufferDestructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MessageBufferDestructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-cleans the received temporary CD-key message at parent frame-0xb0.
// R6GameService.dll @ 10065840 : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl CleanupReceivedCDKeyMessage(void)
{
  __asm {
    // Inherited EBP-0xb0 is the message receiver; receive state0 transitions directly to-1.
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::DestroyClCDKeyMessageAlias
  }
}

// Releases the raw replacement socket allocation saved at parent frame-0xb4.
// R6GameService.dll @ 1006584b : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseReplacementDatagramSocket(void)
{
  __asm {
    // Inherited EBP-0xb4 holds raw socket allocation; receive state1 also transitions directly to-1.
    mov    eax,DWORD PTR [ebp-0xb4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the receive method two-state exception metadata for the shared C++ handler.
// R6GameService.dll @ 10065858 : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageBufferReceiveExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MessageBufferReceiveExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-cleans the queued temporary CD-key message at parent frame-0xb0.
// R6GameService.dll @ 10065870 : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl CleanupQueuedCDKeyMessage(void)
{
  __asm {
    // Inherited EBP-0xb0 is the message receiver; queue state0 transitions to-1.
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::DestroyClCDKeyMessageAlias
  }
}

// Selects the queue method one-state exception metadata for the shared C++ handler.
// R6GameService.dll @ 1006587b : complete native frame/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageBufferQueueExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MessageBufferQueueExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: CMessageBufferVTable
// R6GameService.dll data @ 10076ab4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CMessageBufferVTableRecord {
  R6GameServiceNative::Address DeleteCMessageBuffer; // +0x00
};
const CMessageBufferVTableRecord CMessageBufferVTable = {R6GameServiceAddresses::DeleteCMessageBuffer};
