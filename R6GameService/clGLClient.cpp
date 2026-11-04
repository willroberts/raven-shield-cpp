#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100811e4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo GLClientConstructExceptionHandlerFunctionInfo;

// Identified native class: clGLClient, type descriptor1008e598, primary COL1007997c/table10077bd8.
// Callback bases: clLoginCallbacks+0, clFriendsCallbacks+4, clLobbyCallbacks+8,
// clPersistentCallbacks+0x0c and clLadderQueryCallbacks+0x10; owned service pointer+0x14.
// Constructor frame: EntryESP-0x10 staged allocation, -0x0c previous FS, -8 selector, -4 unwind state.
// Byte10094580 is a lifetime flag, not a reference count; destruction clears it without clearing the child slot.
// R6GameService.dll data @ 10094580 : native storage identity retained.
extern byte GGLClientLifetimeFlag;

// Installs five callback interfaces, constructs the service state and attaches each callback in native order.
// R6GameService.dll @ 1003ef00 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) void * __fastcall ConstructGLClient(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::GLClientConstructExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    lea    edi,[esi+0x4]
    lea    ebx,[esi+0x8]
    lea    ebp,[esi+0xc]
    mov    DWORD PTR [edi],R6GameServiceAddresses::clFriendsCallbacksVTable
    mov    DWORD PTR [ebx],R6GameServiceAddresses::clLobbyCallbacksVTable
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clPersistentCallbacksVTable
    mov    DWORD PTR [esi+0x10],R6GameServiceAddresses::clLadderQueryCallbacksVTable
    mov    DWORD PTR [esi],R6GameServiceAddresses::clGLClientVTable
    mov    DWORD PTR [edi],R6GameServiceAddresses::clGLClientVTableAdjusted4
    mov    DWORD PTR [ebx],R6GameServiceAddresses::clGLClientVTableAdjusted8
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clGLClientVTableAdjusted12
    mov    DWORD PTR [esi+0x10],R6GameServiceAddresses::clGLClientVTableAdjusted16
    mov    al,BYTE PTR [GGLClientLifetimeFlag]
    test   al,al
    jne Branch1
    mov    BYTE PTR [GGLClientLifetimeFlag],0x1
  Branch1:
    push   0x1ac
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],0x0
    je Branch2
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructServiceState
    jmp Branch3
  Branch2:
    xor    eax,eax
  Branch3:
    push   esi
    mov    ecx,eax
    mov    DWORD PTR [esp+0x20],0xffffffff
    mov    DWORD PTR [esi+0x14],eax
    call   R6GameServiceAddresses::SetPrimaryCallbackPointer
    mov    ecx,DWORD PTR [esi+0x14]
    push   edi
    call   R6GameServiceAddresses::SetSecondaryCallbackPointer
    mov    ecx,DWORD PTR [esi+0x14]
    push   ebx
    call   R6GameServiceAddresses::SetTertiaryCallbackPointer
    mov    ecx,DWORD PTR [esi+0x14]
    push   ebp
    call   R6GameServiceAddresses::InstallCallbackPointerAndReturnTrue
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esi+0x10]
    push   eax
    call   R6GameServiceAddresses::InstallSecondCallbackPointer
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys the client, frees it for flags bit0, and returns the original receiver.
// R6GameService.dll @ 1003eff0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) void * __thiscall DeleteGLClient(void *owner,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyGLClient
    test   BYTE PTR [esp+0x8],0x1
    je Branch4
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch4:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore five callback tables, clear a nonzero lifetime flag, then destroy/free the captured child without clearing14.
// Ordinary callers discard native lifetime/allocator EAX residue through their pointer-returning deleting wrappers.
// R6GameService.dll @ 1003f010 : inferred void cleanup; ECX receiver, RET0, no local guard or child retry.
void __fastcall DestroyGLClient(void *owner)
{
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::clGLClientVTable;
  *(uint *)(base + 4) = R6GameServiceAddresses::clGLClientVTableAdjusted4;
  *(uint *)(base + 8) = R6GameServiceAddresses::clGLClientVTableAdjusted8;
  *(uint *)(base + 0xc) = R6GameServiceAddresses::clGLClientVTableAdjusted12;
  *(uint *)(base + 0x10) = R6GameServiceAddresses::clGLClientVTableAdjusted16;
  byte lifetime = GGLClientLifetimeFlag;
  if (lifetime != 0) GGLClientLifetimeFlag = 0;
  void *child = *(void **)(base + 0x14);
  if (child != nullptr) {
    DestroyServiceState(child);
    TailFreeThroughGlobalAllocator(child);
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f060 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall PollTransportAndDispatchQueuedRecords(
    void *this,uint interval,uint dispatchBudget)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::PollAndDispatchQueuedRecords
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0a0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall SendStringTupleSelector66ViaOffset14(
     void *this,char *firstString,char *secondString,char *thirdString,uint enabledFlag)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ecx+0x14]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::SendStringTupleSelector66
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0b0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall SendStringSelector4dViaOffset14(void *this,char *inputString)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::SendStringSelector4d
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0c0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __fastcall SendSelector5dViaOffset14(void *this)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ForwardSelector5dToTransportSubobject
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0d0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall SendSelector13StringViaOffset14(void *this,char *text)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ForwardSelector13ToTransportSubobject
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0e0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall PollAndDispatchCallbackQueueViaSubobject(
     void *this,uint sourceBudgetMs,uint dispatchBudgetMs)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::PollAndDispatchCallbackQueue
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f0f0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __fastcall SendSelector5cViaNestedOffsets(void *this)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::SendSelector5cViaOffset154
  }
}

// Tail-forward the service receiver+14 with both original whole-word arguments shared with the target.
// The request-publication caller discards the sender result before returning AL1; byte is an inferred AL view.
// R6GameService.dll @ 1003f100 : ECX receiver, RET8, no argument copy or local guard in the native tail.
byte __thiscall SendBytePairSelector4eViaOffset14(void *owner,uint firstByte,uint secondByte)
{
  void *service = *(void **)((uint)owner + 0x14);
  using SendABI = byte (__thiscall *)(void *,uint,uint);
  return ((SendABI)R6GameServiceAddresses::SendWordPairSelector4e)(service,firstByte,secondByte);
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f110 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall ProcessPendingCallbackEventsThroughSubobject(
     void *this,uint recordDrainBudget,uint callbackBudget)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ProcessPendingCallbackEvents
  }
}

// Capture/rewrite word3 then word2 around the service+14 load, then tail-forward the three shared argument words.
// Request text remains a late target formal; the enable caller consumes only AL and keeps no upper EAX result.
// R6GameService.dll @ 1003f120 : inferred AL thiscall RET12 view, with native argument read/store order retained.
byte __thiscall PrepareAndSendTransportRequestThroughSubobject(
    void *owner,char *requestText,uint byteFieldValue,uint wordValue)
{
  uint capturedWord = wordValue;
  uint capturedByteField = byteFieldValue;
  void *service = *(void **)((uint)owner + 0x14);
  wordValue = capturedWord;
  byteFieldValue = capturedByteField;
  using PrepareABI = byte (__thiscall *)(void *,char *,uint,uint);
  return ((PrepareABI)R6GameServiceAddresses::PrepareAndSendTransportRequest)(
      service,requestText,byteFieldValue,wordValue);
}

// Tail-forward current service14 and incoming EAX through the dispatcher158/owner10 processing chain.
// R6GameService.dll @ 1003f140 : ECX/EAX register-input view; native RET0, no stack arguments.
uint ProcessTransportRecordsViaNestedOffsets(
    [[r6abi::register_input("ecx")]] void *owner,[[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  void *service = *(void **)((uint)owner + 0x14);
  return ProcessTransportRecordsViaOffset158(service,eaxAtEntry);
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f150 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall DispatchRequest18ByKeyThroughSubobject(
    void *this,undefined4 value,int key,
     char *primaryText,undefined4 flagWord,char *trailingText,undefined4 trailingValue)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [ecx+0x14]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::DispatchRequest18ByKey
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f160 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall ForwardTwoArgumentBooleanViaNestedOffsets(
    void *this,undefined4 param_1, undefined ***param_2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ForwardRequest8ViaOffset158
  }
}

// Forward full scalar words through owner+0x14 and return the raw dispatcher result; parameter names are inferred.
// R6GameService.dll @ 1003f170 : ECX receiver; native stack words and raw registers retained.
uint __thiscall ForwardSelector9ThroughOptionalChannel(void *owner,uint value,uint key,uint extraValue)
{
  void *dispatcher = *(void **)((uint)owner + 0x14);
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchSelector9ThroughOptionalChannel)(
      dispatcher,value,key,extraValue);
}

// Forward full scalar words through owner+0x14 and return the raw dispatcher result; parameter names are inferred.
// R6GameService.dll @ 1003f180 : ECX receiver; native stack words and raw registers retained.
uint __thiscall ForwardSelector2eThroughOptionalChannel(void *owner,uint value,uint key)
{
  void *dispatcher = *(void **)((uint)owner + 0x14);
  using DispatchABI = uint (__thiscall *)(void *,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchSelector2eThroughOptionalChannel)(dispatcher,value,key);
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f190 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall CreateServiceRecordListViaNestedOffsets(void *this,undefined4 param_1)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::CreateServiceRecordList
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1a0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall UpdateServiceRecordByKeyViaNestedOffsets(
    void *this,char *key,uint keyLength, undefined4 value)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::UpdateServiceRecordByKey
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1b0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall BuildAndDispatchStoredRequestViaNestedOffsets(
    void *this,undefined4 requestWord, int contextValue)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::BuildAndDispatchStoredRecordRequest
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1c0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __fastcall DestroyServiceRecordListViaOffset14(void *this)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::DestroyServiceRecordList
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1d0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets(
    void *this,undefined4 param_1, undefined ***param_2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ForwardRequest2cViaOffset158
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1e0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets2(
    void *this,undefined4 param_1, undefined ***param_2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::ForwardRequest46ViaOffset158
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f1f0 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall ForwardSelector22ThroughOptionalChannel(
    void *this,undefined4 param_1,undefined ***param_2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::DispatchSelector22ThroughOptionalChannel
  }
}

// Tail-forwards the service receiver at +0x14 and preserves the target raw return and native argument words.
// R6GameService.dll @ 1003f200 : ECX receiver; native stack words and raw registers retained.
__declspec(naked) uint __thiscall ForwardSelector2aThroughOptionalChannel(
    void *this,undefined1 *param_1,undefined1 *param_2)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x14]
    jmp    R6GameServiceAddresses::DispatchSelector2aThroughOptionalChannel
  }
}

// Frees the staged service allocation from parent EBP-0x10 during constructor unwind.
// R6GameService.dll @ 10066ba0 : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl ReleaseGLClientServiceAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selects the single-state service-allocation unwind map for the client constructor.
// R6GameService.dll @ 10066baa : inherited parent EBP; native cleanup/selector ABI.
__declspec(naked) void __cdecl GLClientConstructExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::GLClientConstructExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Mask caller port word to16 bits in place, then tail-forward service receiver+14 to primary connection open.
// R6GameService.dll @ 1003f070 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenPrimaryConnectionThroughSubobject(
    void *owner,const char *endpointText,uint portWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [ecx+0x14]
    and    eax,0xffff
    mov    DWORD PTR [esp+0x8],eax
    jmp    R6GameServiceAddresses::OpenPrimaryConnection
  }
}

// Tail-forward the current service+14 receiver with incoming EAX unchanged, retaining the complete target word.
// R6GameService.dll @ 1003f090 : raw register view; ECX owner/EAX input, native RET0, no stack arguments.
uint DisconnectPrimaryConnectionViaOffset14(
    [[r6abi::register_input("ecx")]] void *owner,[[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  void *service = *(void **)((uint)owner + 0x14);
  return DisconnectPrimaryConnectionIfActive(service,eaxAtEntry);
}

// Native virtual-table prefix: clGLClientVTableAdjusted16
// R6GameService.dll data @ 10077abc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGLClientVTableAdjusted16Record {
  R6GameServiceNative::Address _purecall; // +0x00
};
const clGLClientVTableAdjusted16Record clGLClientVTableAdjusted16 = {R6GameServiceAddresses::_purecall};

// Native virtual-table prefix: clGLClientVTableAdjusted12
// R6GameService.dll data @ 10077ac4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGLClientVTableAdjusted12Record {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
};
const clGLClientVTableAdjusted12Record clGLClientVTableAdjusted12 = {
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};

// Native virtual-table prefix: clGLClientVTableAdjusted8
// R6GameService.dll data @ 10077adc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGLClientVTableAdjusted8Record {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
  R6GameServiceNative::Address _purecall5; // +0x10
  R6GameServiceNative::Address _purecall6; // +0x14
  R6GameServiceNative::Address _purecall7; // +0x18
  R6GameServiceNative::Address _purecall8; // +0x1c
  R6GameServiceNative::Address _purecall9; // +0x20
  R6GameServiceNative::Address _purecall10; // +0x24
  R6GameServiceNative::Address _purecall11; // +0x28
  R6GameServiceNative::Address _purecall12; // +0x2c
  R6GameServiceNative::Address _purecall13; // +0x30
  R6GameServiceNative::Address _purecall14; // +0x34
  R6GameServiceNative::Address _purecall15; // +0x38
  R6GameServiceNative::Address _purecall16; // +0x3c
  R6GameServiceNative::Address _purecall17; // +0x40
  R6GameServiceNative::Address _purecall18; // +0x44
  R6GameServiceNative::Address _purecall19; // +0x48
  R6GameServiceNative::Address _purecall20; // +0x4c
  R6GameServiceNative::Address _purecall21; // +0x50
  R6GameServiceNative::Address _purecall22; // +0x54
  R6GameServiceNative::Address _purecall23; // +0x58
  R6GameServiceNative::Address _purecall24; // +0x5c
  R6GameServiceNative::Address _purecall25; // +0x60
  R6GameServiceNative::Address _purecall26; // +0x64
  R6GameServiceNative::Address _purecall27; // +0x68
  R6GameServiceNative::Address _purecall28; // +0x6c
  R6GameServiceNative::Address _purecall29; // +0x70
  R6GameServiceNative::Address _purecall30; // +0x74
  R6GameServiceNative::Address _purecall31; // +0x78
  R6GameServiceNative::Address _purecall32; // +0x7c
  R6GameServiceNative::Address _purecall33; // +0x80
  R6GameServiceNative::Address _purecall34; // +0x84
  R6GameServiceNative::Address _purecall35; // +0x88
  R6GameServiceNative::Address _purecall36; // +0x8c
  R6GameServiceNative::Address _purecall37; // +0x90
  R6GameServiceNative::Address _purecall38; // +0x94
  R6GameServiceNative::Address _purecall39; // +0x98
  R6GameServiceNative::Address _purecall40; // +0x9c
  R6GameServiceNative::Address _purecall41; // +0xa0
  R6GameServiceNative::Address _purecall42; // +0xa4
  R6GameServiceNative::Address _purecall43; // +0xa8
  R6GameServiceNative::Address _purecall44; // +0xac
};
const clGLClientVTableAdjusted8Record clGLClientVTableAdjusted8 = {
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

// Native virtual-table prefix: clGLClientVTableAdjusted4
// R6GameService.dll data @ 10077b94 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGLClientVTableAdjusted4Record {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
  R6GameServiceNative::Address _purecall5; // +0x10
  R6GameServiceNative::Address _purecall6; // +0x14
  R6GameServiceNative::Address _purecall7; // +0x18
  R6GameServiceNative::Address _purecall8; // +0x1c
  R6GameServiceNative::Address _purecall9; // +0x20
  R6GameServiceNative::Address _purecall10; // +0x24
  R6GameServiceNative::Address _purecall11; // +0x28
  R6GameServiceNative::Address _purecall12; // +0x2c
  R6GameServiceNative::Address _purecall13; // +0x30
  R6GameServiceNative::Address _purecall14; // +0x34
  R6GameServiceNative::Address _purecall15; // +0x38
  R6GameServiceNative::Address _purecall16; // +0x3c
};
const clGLClientVTableAdjusted4Record clGLClientVTableAdjusted4 = {
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
  R6GameServiceAddresses::_purecall,
};

// Native virtual-table prefix: clGLClientVTable
// R6GameService.dll data @ 10077bd8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGLClientVTableRecord {
  R6GameServiceNative::Address _purecall; // +0x00
  R6GameServiceNative::Address _purecall2; // +0x04
  R6GameServiceNative::Address _purecall3; // +0x08
  R6GameServiceNative::Address _purecall4; // +0x0c
  R6GameServiceNative::Address _purecall5; // +0x10
  R6GameServiceNative::Address _purecall6; // +0x14
  R6GameServiceNative::Address _purecall7; // +0x18
  R6GameServiceNative::Address _purecall8; // +0x1c
  R6GameServiceNative::Address _purecall9; // +0x20
  R6GameServiceNative::Address DeleteGLClient; // +0x24
};
const clGLClientVTableRecord clGLClientVTable = {
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::DeleteGLClient,
};
