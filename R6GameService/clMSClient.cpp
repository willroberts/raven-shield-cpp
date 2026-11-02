#include "native_addresses.h"
#include "native_records.h"

// RTTI-backed clMSClient members; hidden virtual-base flag is represented as one physical word.

// Construct the MS callback client and zero its thirteen callback/state words after the class base returns.
// RTTI: clMSClient table77014/COL791a0/type8e5d4; class base0, virtual ExtAlloc::OverrideAllocOperators.
// Nonzero hidden flag installs vbtable77070 at+118; saved construction flag1/state0 protect only that base.
// The sole action computes this+150 and tail-calls genuine RET-only59130; no completed client-base destruction.
// State stays-1 for zero flag. Vtables install last; partial base/derived writes and provider storage persist.
// R6GameService.dll @ 10032a00 : complete native control/access order and raw ABI retained.
__declspec(naked) clMSClient::clMSClient(uint constructVirtualBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::clMSClient_clMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x18]
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    cmp    eax,edi
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],edi
    je     Branch1
    mov    DWORD PTR [esi+0x118],0x10077070
    mov    DWORD PTR [esp+0x8],0x1
    mov    DWORD PTR [esp+0x18],edi
  Branch1:
    mov    ecx,esi
    call   R6GameServiceAddresses::clMSClientClass_clMSClientClass
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x11c],edi
    mov    DWORD PTR [esi+0x124],edi
    mov    DWORD PTR [esi+0x128],edi
    mov    DWORD PTR [esi+0x134],edi
    mov    DWORD PTR [esi+0x12c],edi
    mov    DWORD PTR [esi+0x130],edi
    mov    DWORD PTR [esi+0x138],edi
    mov    DWORD PTR [esi+0x13c],edi
    mov    DWORD PTR [esi+0x140],edi
    mov    DWORD PTR [esi+0x144],edi
    mov    DWORD PTR [esi+0x148],edi
    mov    DWORD PTR [esi+0x120],edi
    mov    DWORD PTR [esi+0x14c],edi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMSClientVTable
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::clMSClientVTableAdjusted4
    mov    DWORD PTR [esi+0x8],R6GameServiceAddresses::clMSClientVTableAdjusted8
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clMSClientVTableAdjusted12
    mov    DWORD PTR [esi+0x10],R6GameServiceAddresses::clMSClientVTableAdjusted16
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// If inherited construction flag bit0 is set, adjust the saved receiver to its trivial virtual allocator base.
// Inherited runtime EBP equals constructor entry ESP; saved flag at-14 and receiver at-10; pointee untouched.
// R6GameService.dll @ 10066390 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clMSClient_clMSClientUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch2
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x150
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch2:
    ret
  }
}

// Select constructor metadata and tail-enter the CRT frame handler.
// R6GameService.dll @ 100663ad : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clMSClient_clMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clMSClient_clMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native MS client constructor unwind record; literal states and addresses.
// R6GameService.dll data @ 10080720 : native storage identity retained.
const R6GameServiceNative::UnwindEntry clMSClient_clMSClientUnwindMap[1] = {
  {-1, R6GameServiceAddresses::clMSClient_clMSClientUnwind1},
};

// Native MS client constructor info record; literal states and addresses.
// R6GameService.dll data @ 10080720 : native storage identity retained.
const R6GameServiceNative::FuncInfo clMSClient_clMSClientExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::clMSClient_clMSClientUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroy the extended client, then conditionally free its saved receiver through the current allocator tail.
// One full physical flag word/RET4; BYTE bit0 reloads after destruction; returns original receiver/no own guard.
// R6GameService.dll @ 10032ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteExtendedServiceClient(void *client,uint deleteFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyExtendedServiceClient
    test   BYTE PTR [esp+0x8],0x1
    je     Branch3
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore derived callback tables and tail-enter the shared class destructor on the same receiver.
// Raw uint view preserves tail result/exception behavior; no additional guard, fields or virtual-base cleanup.
// R6GameService.dll @ 10032af0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DestroyExtendedServiceClient(void *client)
{
  __asm {
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clMSClientVTable
    mov    DWORD PTR [ecx+0x4],R6GameServiceAddresses::clMSClientVTableAdjusted4
    mov    DWORD PTR [ecx+0x8],R6GameServiceAddresses::clMSClientVTableAdjusted8
    mov    DWORD PTR [ecx+0xc],R6GameServiceAddresses::clMSClientVTableAdjusted12
    mov    DWORD PTR [ecx+0x10],R6GameServiceAddresses::clMSClientVTableAdjusted16
    jmp    R6GameServiceAddresses::DestroyServiceClient
  }
}

// Tail-forward19 physical words through callback+11c, or return EAX0/RET76 when absent.
// Derived primary slot+28; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument3 and its ECX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt11c(
    uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,uint word9,uint word10,
    uint word11,uint word12,uint word13,uint word14,uint word15,uint word16,uint word17,uint word18,uint word19)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x11c]
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0xc],ecx
    jmp    eax
  Branch4:
    ret    0x4c
  }
}

// Tail-forward4 physical words through callback+120, or return EAX0/RET16 when absent.
// Derived primary slot+44; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032be0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt120(
    uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x120]
    test   eax,eax
    je     Branch5
    jmp    eax
  Branch5:
    ret    0x10
  }
}

// Tail-forward3 physical words through callback+124, or return EAX0/RET12 when absent.
// Derived primary slot+2c; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032bf0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt124(uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x124]
    test   eax,eax
    je     Branch6
    jmp    eax
  Branch6:
    ret    0xc
  }
}

// Tail-forward3 physical words through callback+128, or return EAX0/RET12 when absent.
// Derived primary slot+30; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument1 and its ECX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt128(uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x128]
    test   eax,eax
    je     Branch7
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch7:
    ret    0xc
  }
}

// Tail-forward0 physical words through callback+12c, or return EAX0/RET0 when absent.
// Derived primary slot+34; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt12c(void)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x12c]
    test   eax,eax
    je     Branch8
    jmp    eax
  Branch8:
    ret
  }
}

// Tail-forward0 physical words through callback+130, or return EAX0/RET0 when absent.
// Derived primary slot+38; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt130(void)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x130]
    test   eax,eax
    je     Branch9
    jmp    eax
  Branch9:
    ret
  }
}

// Tail-forward0 physical words through callback+134, or return EAX0/RET0 when absent.
// Derived primary slot+3c; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt134(void)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x134]
    test   eax,eax
    je     Branch10
    jmp    eax
  Branch10:
    ret
  }
}

// Tail-forward7 physical words through callback+138, or return EAX0/RET28 when absent.
// Derived primary slot+40; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument7 and its ECX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt138(
    uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x138]
    test   eax,eax
    je     Branch11
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x1c],ecx
    jmp    eax
  Branch11:
    ret    0x1c
  }
}

// Tail-forward2 physical words through callback+13c, or return EAX0/RET8 when absent.
// Derived primary slot+48; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument1 and its EDX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt13c(uint word1,uint word2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x13c]
    test   eax,eax
    je     Branch12
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch12:
    ret    0x8
  }
}

// Tail-forward2 physical words through callback+140, or return EAX0/RET8 when absent.
// Derived primary slot+4c; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument1 and its EDX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032c90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt140(uint word1,uint word2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x140]
    test   eax,eax
    je     Branch13
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch13:
    ret    0x8
  }
}

// Tail-forward3 physical words through callback+144, or return EAX0/RET12 when absent.
// Derived primary slot+50; callback target is captured before argument access. No own guard or ownership.
// Incoming ECX/EDX and argument words are untouched until the target; raw target EAX survives.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt144(uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x144]
    test   eax,eax
    je     Branch14
    jmp    eax
  Branch14:
    ret    0xc
  }
}

// Tail-forward3 physical words through callback+148, or return EAX0/RET12 when absent.
// Derived primary slot+54; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument1 and its ECX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032cc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt148(uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x148]
    test   eax,eax
    je     Branch15
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch15:
    ret    0xc
  }
}

// Tail-forward4 physical words through callback+14c, or return EAX0/RET16 when absent.
// Derived primary slot+58; callback target is captured before argument access. No own guard or ownership.
// Preserve the full-word read/store of argument1 and its EDX clobber before the tail transfer.
// Method/formal names and uint result are descriptive register views, not recovered original declarations.
// R6GameService.dll @ 10032ce0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClient::DispatchCallbackAt14c(
    uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x14c]
    test   eax,eax
    je     Branch16
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch16:
    ret    0x10
  }
}

// Stores one word at receiver+11c and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b20 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x11c(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x11c) = value;
  return value;
}

// Stores one word at receiver+120 and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b30 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x120(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x120) = value;
  return value;
}

// Stores one word at receiver+124 and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b40 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x124(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x124) = value;
  return value;
}

// Stores one word at receiver+128 and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b50 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x128(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x128) = value;
  return value;
}

// Stores one word at receiver+12c and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b60 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x12c(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x12c) = value;
  return value;
}

// Stores one word at receiver+130 and leaves that word in EAX; no receiver validation.
// R6GameService.dll @ 10032b70 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall StoreValueAtOffset_0x130(void *service,uint value)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(service) + 0x130) = value;
  return value;
}

// Native virtual-table prefix: clMSClientVTableAdjusted16
// R6GameService.dll data @ 10076ef4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientVTableAdjusted16Record {
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x00
};
const clMSClientVTableAdjusted16Record clMSClientVTableAdjusted16 = {R6GameServiceAddresses::NoOpServiceCallbackRet0C};

// Native virtual-table prefix: clMSClientVTableAdjusted12
// R6GameService.dll data @ 10076efc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientVTableAdjusted12Record {
  R6GameServiceNative::Address NoOp; // +0x00
  R6GameServiceNative::Address list_node_support_NoOp; // +0x04
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x08
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x0c
};
const clMSClientVTableAdjusted12Record clMSClientVTableAdjusted12 = {
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::list_node_support_NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
};

// Native virtual-table prefix: clMSClientVTableAdjusted8
// R6GameService.dll data @ 10076f14 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientVTableAdjusted8Record {
  R6GameServiceNative::Address NotifySelector27; // +0x00
  R6GameServiceNative::Address CompleteCurrentThenNotify; // +0x04
  R6GameServiceNative::Address NotifyAndReset; // +0x08
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x0c
  R6GameServiceNative::Address StoreCurrentRecordWord; // +0x10
  R6GameServiceNative::Address NotifySelector27AndRunHelper; // +0x14
  R6GameServiceNative::Address ForwardServerAndSetDeadline; // +0x18
  R6GameServiceNative::Address QueueProviderCallbackRecord; // +0x1c
  R6GameServiceNative::Address ForwardEmbeddedCallback; // +0x20
  R6GameServiceNative::Address RetainDiagnosticArguments; // +0x24
  R6GameServiceNative::Address TailNotifyOne; // +0x28
  R6GameServiceNative::Address NoOp; // +0x2c
  R6GameServiceNative::Address NoOpServiceCallbackRet30; // +0x30
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x34
  R6GameServiceNative::Address NoOpServiceCallbackRet10; // +0x38
  R6GameServiceNative::Address NoOpServiceCallbackRet142; // +0x3c
  R6GameServiceNative::Address NoOpServiceCallbackRet143; // +0x40
  R6GameServiceNative::Address NoOpServiceCallbackRet102; // +0x44
  R6GameServiceNative::Address NoOpServiceCallbackRet0C2; // +0x48
  R6GameServiceNative::Address NoOpServiceCallbackRet144; // +0x4c
  R6GameServiceNative::Address NoOpServiceCallbackRet145; // +0x50
  R6GameServiceNative::Address DispatchSelector26Words; // +0x54
  R6GameServiceNative::Address NoOpServiceCallbackRet103; // +0x58
  R6GameServiceNative::Address NoOpServiceCallbackRet0C3; // +0x5c
  R6GameServiceNative::Address ForwardSwappedPair; // +0x60
  R6GameServiceNative::Address NoOpServiceCallbackRet104; // +0x64
  R6GameServiceNative::Address TailSubmitWords; // +0x68
  R6GameServiceNative::Address NoOpServiceCallbackRet105; // +0x6c
  R6GameServiceNative::Address NoOpServiceCallbackRet106; // +0x70
  R6GameServiceNative::Address NoOpServiceCallbackRet107; // +0x74
  R6GameServiceNative::Address ForwardSevenThenSetFlag; // +0x78
  R6GameServiceNative::Address NoOpServiceCallbackRet108; // +0x7c
  R6GameServiceNative::Address NoOpServiceCallbackRet109; // +0x80
  R6GameServiceNative::Address NoOpServiceCallbackRet146; // +0x84
  R6GameServiceNative::Address NoOpServiceCallbackRet147; // +0x88
  R6GameServiceNative::Address NoOpServiceCallbackRet0C4; // +0x8c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C5; // +0x90
  R6GameServiceNative::Address NoOp2; // +0x94
  R6GameServiceNative::Address shared_native_NoOp; // +0x98
  R6GameServiceNative::Address NoOp3; // +0x9c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C6; // +0xa0
  R6GameServiceNative::Address NoOpServiceCallbackRet0C7; // +0xa4
  R6GameServiceNative::Address NoOp4; // +0xa8
  R6GameServiceNative::Address NoOpServiceCallbackRet148; // +0xac
};
const clMSClientVTableAdjusted8Record clMSClientVTableAdjusted8 = {
  R6GameServiceAddresses::NotifySelector27,
  R6GameServiceAddresses::CompleteCurrentThenNotify,
  R6GameServiceAddresses::NotifyAndReset,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::StoreCurrentRecordWord,
  R6GameServiceAddresses::NotifySelector27AndRunHelper,
  R6GameServiceAddresses::ForwardServerAndSetDeadline,
  R6GameServiceAddresses::QueueProviderCallbackRecord,
  R6GameServiceAddresses::ForwardEmbeddedCallback,
  R6GameServiceAddresses::RetainDiagnosticArguments,
  R6GameServiceAddresses::TailNotifyOne,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet30,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::DispatchSelector26Words,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::ForwardSwappedPair,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::TailSubmitWords,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::ForwardSevenThenSetFlag,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
};

// Native virtual-table prefix: clMSClientVTableAdjusted4
// R6GameService.dll data @ 10076fcc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientVTableAdjusted4Record {
  R6GameServiceNative::Address NoOp; // +0x00
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x04
  R6GameServiceNative::Address NoOpServiceCallbackRet0C2; // +0x08
  R6GameServiceNative::Address NoOp2; // +0x0c
  R6GameServiceNative::Address NoOp3; // +0x10
  R6GameServiceNative::Address shared_native_NoOp; // +0x14
  R6GameServiceNative::Address shared_native_NoOp2; // +0x18
  R6GameServiceNative::Address NoOpServiceCallbackRet0C3; // +0x1c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C4; // +0x20
  R6GameServiceNative::Address NoOpServiceCallbackRet0C5; // +0x24
  R6GameServiceNative::Address NoOpServiceCallbackRet0C6; // +0x28
  R6GameServiceNative::Address NoOp4; // +0x2c
  R6GameServiceNative::Address NoOp5; // +0x30
  R6GameServiceNative::Address NoOpServiceCallbackRet18; // +0x34
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x38
  R6GameServiceNative::Address NoOpServiceCallbackRet142; // +0x3c
};
const clMSClientVTableAdjusted4Record clMSClientVTableAdjusted4 = {
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet18,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
};

// Native virtual-table prefix: clMSClientVTable
// R6GameService.dll data @ 10077014 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientVTableRecord {
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26StringOrVirtual; // +0x00
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26OrVirtual; // +0x04
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26OrVirtual2; // +0x08
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26BufferOrVirtual; // +0x0c
  R6GameServiceNative::Address NoOp; // +0x10
  R6GameServiceNative::Address clMSClientClass_TailVirtual34; // +0x14
  R6GameServiceNative::Address clMSClientClass_NotifyVirtual48ThenResetProvider; // +0x18
  R6GameServiceNative::Address clMSClientClass_TailVirtual4c; // +0x1c
  R6GameServiceNative::Address clMSClientClass_TailVirtual58; // +0x20
  R6GameServiceNative::Address DeleteExtendedServiceClient; // +0x24
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt11c; // +0x28
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt124; // +0x2c
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt128; // +0x30
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt12c; // +0x34
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt130; // +0x38
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt134; // +0x3c
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt138; // +0x40
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt120; // +0x44
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt13c; // +0x48
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt140; // +0x4c
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt144; // +0x50
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt148; // +0x54
  R6GameServiceNative::Address clMSClient_DispatchCallbackAt14c; // +0x58
};
const clMSClientVTableRecord clMSClientVTable = {
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26StringOrVirtual,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26OrVirtual,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26OrVirtual2,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26BufferOrVirtual,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::clMSClientClass_TailVirtual34,
  R6GameServiceAddresses::clMSClientClass_NotifyVirtual48ThenResetProvider,
  R6GameServiceAddresses::clMSClientClass_TailVirtual4c,
  R6GameServiceAddresses::clMSClientClass_TailVirtual58,
  R6GameServiceAddresses::DeleteExtendedServiceClient,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt11c,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt124,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt128,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt12c,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt130,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt134,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt138,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt120,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt13c,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt140,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt144,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt148,
  R6GameServiceAddresses::clMSClient_DispatchCallbackAt14c,
};
