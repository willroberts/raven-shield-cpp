#include "native_addresses.h"
#include "native_records.h"

// Framed receive/send-drain helpers share a provider prefix; whole-owner class and original member names unresolved.

// Count current send list, call adjusted associate+15c with first payload words+8/+c, remove accepted front and recount.
// Count traversals capture their head; first-payload/removal/recount reload current heads/slots around callbacks.
// Callback success tests full EAX; count store is WORD+38 modulo16. Final AL1 retains sentinel or rejected EAX upper bits.
// No local EH or rollback; whole-owner class remains unresolved despite its shared provider prefix.
// R6GameService.dll @ 10059390 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DrainProviderSendQueue(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
  Branch1:
    mov    ecx,DWORD PTR [esi+0x30]
    xor    edx,edx
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je    Branch5
  Branch2:
    mov    eax,DWORD PTR [eax]
    inc    edx
    cmp    eax,ecx
    jne    Branch2
    test    edx,edx
    je    Branch5
    mov    eax,DWORD PTR [esi+0x30]
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [ecx+0x8]
    mov    ecx,DWORD PTR [eax+0xc]
    mov    edx,DWORD PTR [eax+0x8]
    mov    eax,DWORD PTR [esi+0x68]
    push    ecx
    push    edx
    mov    edx,DWORD PTR [eax+0x164]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [edx+ecx*1]
    mov    ecx,DWORD PTR [eax+0x160]
    add    edx,ecx
    lea    ecx,[edx+eax*1+0x4]
    call    DWORD PTR [eax+0x15c]
    test    eax,eax
    je    Branch5
    mov    eax,DWORD PTR [esi+0x2c]
    lea    ecx,[esi+0x2c]
    call    DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR [esi+0x30]
    xor    edx,edx
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ecx
    je    Branch4
  Branch3:
    mov    eax,DWORD PTR [eax]
    inc    edx
    cmp    eax,ecx
    jne    Branch3
  Branch4:
    mov    WORD PTR [esi+0x38],dx
    jmp    Branch1
  Branch5:
    mov    al,0x1
    pop    esi
    ret
  }
}

// Peek7, read declared24-bit frame, build kind0/1 message, parse and append it to current saved provider's receive queue.
// ENTRY ESP S: DWORD countS-24/kind byteS-20/saved providerS-1c/raw messageS-18/header7 atS-14/stateS-4.
// Process at most101 reads accepted by helpers, not a kind-byte loop. Preserve missing/partial read AL1 versus failures AL0.
// States0/1 free only CURRENT raw message scratch; disarm before parser, leaving raw frame and later detached message unguarded.
// Preserve constructor-return pointer, late context/provider reloads, unchecked NULL/short sizes and partial EAX.
// R6GameService.dll @ 10059410 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DecodeProviderReceiveFrames(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectFramedReceiveEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esp+0xc],0x0
  Branch6:
    mov    ecx,DWORD PTR [esi+0x68]
    push    0x1
    lea    eax,[esp+0x20]
    push    0x7
    push    eax
    call    R6GameServiceAddresses::ReadOwnerQueueBytes
    test    al,al
    je    Branch13
    lea    ecx,[esp+0x1c]
    push    ecx
    call    R6GameServiceAddresses::ReadHeaderSize24
    mov    ebx,eax
    push    ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi+0x68]
    mov    edi,eax
    push    0x0
    push    ebx
    push    edi
    call    R6GameServiceAddresses::ReadOwnerQueueBytes
    test    al,al
    push    edi
    je    Branch15
    inc    DWORD PTR [esp+0x10]
    call    R6GameServiceAddresses::ReadHeaderByte3HighBits
    mov    BYTE PTR [esp+0x10],al
    mov    eax,DWORD PTR [esp+0x10]
    and    eax,0xff
    sub    eax,0x0
    je    Branch9
    dec    eax
    jne    Branch17
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x18],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x2c],0x1
    je    Branch7
    mov    edx,DWORD PTR [esi+0x4c]
    push    0x1
    push    edx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeClGameMessageFields
    mov    esi,eax
    jmp    Branch8
  Branch7:
    xor    esi,esi
  Branch8:
    mov    eax,DWORD PTR [esi]
    push    ebx
    push    edi
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0xffffffff
    call    DWORD PTR [eax+0x10]
    test    al,al
    jne    Branch12
    push    R6GameServiceAddresses::TextErrorDecodingMessage
    call    R6GameServiceAddresses::list_node_support_NoOp
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    mov    ecx,esi
    push    0x1
    call    DWORD PTR [eax]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  Branch9:
    push    0x18
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x18],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x2c],0x0
    je    Branch10
    mov    ecx,DWORD PTR [esi+0x4c]
    push    0x1
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeClGSMessageFields
    mov    esi,eax
    jmp    Branch11
  Branch10:
    xor    esi,esi
  Branch11:
    mov    edx,DWORD PTR [esi]
    push    ebx
    push    edi
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0xffffffff
    call    DWORD PTR [edx+0x10]
    test    al,al
    je    Branch14
  Branch12:
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    lea    ecx,[esi+0x3c]
    call    R6GameServiceAddresses::AttachCompactRecord
    test    al,al
    je    Branch16
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    DWORD PTR [esp+0xc],0x64
    jbe    Branch6
  Branch13:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  Branch14:
    push    R6GameServiceAddresses::TextErrorDecodingMessage
    call    R6GameServiceAddresses::list_node_support_NoOp
    mov    edx,DWORD PTR [esi]
    add    esp,0x4
    mov    ecx,esi
    push    0x1
    call    DWORD PTR [edx]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  Branch15:
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  Branch16:
    push    R6GameServiceAddresses::TextErrorDecodingMessage
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
  Branch17:
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  }
}

// Free CURRENT raw kind1 message allocation from inherited parent entry ESP-18; frame buffer has no parent guard.
// R6GameService.dll @ 10069810 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodeProviderReceiveFramesUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Free CURRENT raw kind0 message allocation from inherited parent entry ESP-18; frame buffer has no parent guard.
// R6GameService.dll @ 1006981a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodeProviderReceiveFramesUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select exact two-state pending-message FuncInfo and tail-forward to CRT exception dispatch.
// R6GameService.dll @ 10069824 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectFramedReceiveEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DecodeProviderReceiveFramesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native pending-message unwind map/FuncInfo; neither state owns the raw frame buffer.
// R6GameService.dll data @ 100842f0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DecodeProviderReceiveFramesUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DecodeProviderReceiveFramesUnwind1},
  {-1, R6GameServiceAddresses::DecodeProviderReceiveFramesUnwind2},
};

// Literal native pending-message unwind map/FuncInfo; neither state owns the raw frame buffer.
// R6GameService.dll data @ 100842f0 : native storage identity retained.
const R6GameServiceNative::FuncInfo DecodeProviderReceiveFramesExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DecodeProviderReceiveFramesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Capture associated pointer once; compare current signed/raw state+134 with4, set AL only and retain pointer upper bits.
// R6GameService.dll @ 10059340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReadAssociatedProviderReady(void *owner)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x68]
    cmp    DWORD PTR [eax+0x134],0x4
    sete    al
    ret
  }
}

// On state-check AL0 call CURRENT slot8, then clear only AL; otherwise drain, reload association and tail dispatch.
// Tail receiver is A+4+[A+154]+[[A+4]+[A+158]], target CURRENT[A+150], raw EAX retained. No local EH.
// Whole-owner class is unresolved; the shared prefix and neighboring class entries do not establish ownership.
// R6GameService.dll @ 100592c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DispatchProviderReceiveState(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DecodeProviderReceiveFrames
    test   al,al
    mov    ecx,esi
    jne    Branch18
    mov    eax,DWORD PTR [esi]
    call   DWORD PTR [eax+0x8]
    xor    al,al
    pop    esi
    ret
  Branch18:
    call   R6GameServiceAddresses::DrainProviderSendQueue
    mov    eax,DWORD PTR [esi+0x68]
    pop    esi
    mov    ecx,DWORD PTR [eax+0x158]
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [ecx+edx*1]
    mov    edx,DWORD PTR [eax+0x154]
    add    ecx,edx
    lea    ecx,[ecx+eax*1+0x4]
    jmp    DWORD PTR [eax+0x150]
  }
}

// Reject initial nonready connection; concatenate while current countWORD and saved sendAL permit, discard only success.
// Reload connection/count output per batch; absent connection drops batch. Free captured bytes and return AL1 even after send failure.
// R6GameService.dll @ 10057f00 : inferred provider fields; initial owner/count scratch maps to native saved ECX S-4.
uint __fastcall DrainQueuedTransportPayloads(uint providerAddress)
{
  uint base = providerAddress;
  uint result = *(uint *)(base + 0x14);
  if (result != 0 && *(byte *)(result + 0x44) == 0) return result & 0xffffff00;
  uint batchByteCount = base;
  byte sendStatus = 1;
  using ConcatABI = uint (__thiscall *)(void *,uint,uint *);
  using SendABI = char (__thiscall *)(void *,int,uint);
  using DiscardABI = uint (__thiscall *)(void *,uint);
  using FreeABI = uint (__stdcall *)(void *);
  while (*(ushort *)(base + 0x38) != 0 && sendStatus != 0) {
    void *queue = (void *)(base + 0x2c);
    uint bytes = ((ConcatABI)R6GameServiceAddresses::ConcatenateCompactPayloadsThroughLimit)(
        queue,1000,&batchByteCount);
    void *connection = *(void **)(base + 0x14);
    if (connection != 0) {
      uint currentCount = batchByteCount;
      sendStatus = (byte)((SendABI)R6GameServiceAddresses::SendOrQueueConnectionBytes)(
          connection,(int)bytes,currentCount);
    }
    if (sendStatus != 0) {
      uint currentCount = batchByteCount;
      ((DiscardABI)R6GameServiceAddresses::DiscardConsumedCompactPayloads)(queue,currentCount);
    }
    result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)((void *)bytes);
  }
  return (result & 0xffffff00) | 1;
}

// R6GameService.dll @ 10058460 : ReceiveMatchingTransportRecord
// Reads and decodes one transport record, keeps matching +0x58 records, and suppresses class 1/tag 0xed.
// Native 10058460: +0x64 is updated for every matching record, including the suppressed control record.
int * __fastcall ReceiveMatchingTransportRecord(int receiver)
{
  void *transport = *(void **)(receiver + 0x18);
  if (transport == (void *)0)
    return (int *)0;
  undefined1 transportScratch[4];
  ushort transportWord; // Native stack word is not initialized before the transport call.
  uint byteCount;
  undefined4 *bytes = datagram_socket_support_ReceiveDatagramWithIPv4Sender(transport,transportScratch,&transportWord,&byteCount);
  if (bytes == (undefined4 *)0)
    return (int *)0;
  undefined4 decodedValue; // The decoder writes this output only for its class-one record branch.
  int *record = DecodeTransportRecordByHeaderClass(
      (byte *)bytes,byteCount,&decodedValue,*(undefined4 **)(receiver + 0x4c));
  if (record == (int *)0)
    return (int *)0;
  if (decodedValue == *(undefined4 *)(receiver + 0x58)) {
    *(ushort *)(receiver + 0x64) = transportWord;
    if (*(byte *)((int)record + 0xc) != 1 || *(byte *)((int)record + 0xd) != 0xed)
      return record;
  }
  (**(code **)*record)(1);
  return (int *)0;
}

// R6GameService.dll @ 100584d0 : ReceiveRecordWithSource
// Returns one queued or transport record and reports which source was tried through a byte output.
// Native 100584d0: RET 4; both branches preserve the selected record pointer in EAX.
undefined4 * __thiscall ReceiveRecordWithSource(void *receiver,byte *sourceOut)
{
  *sourceOut = 2;
  undefined4 *record = PopAndDispatchControlRecord(receiver);
  if (record != (undefined4 *)0)
    return record;
  *sourceOut = 8;
  return (undefined4 *)ReceiveMatchingTransportRecord((int)receiver);
}

// Receive through584d0 with tag output atS-1 inside saved ECX; POP ECX retains low24 and replaces its highBYTE.
// Return the raw selected pointer/EAX unchanged; no own guard or output normalization.
// R6GameService.dll @ 10059010 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall ReceiveRecordWithSourceThunk(void *owner)
{
  __asm {
    push    ecx
    lea    eax,[esp+0x3]
    push    eax
    call    R6GameServiceAddresses::ReceiveRecordWithSource
    pop    ecx
    ret
  }
}
