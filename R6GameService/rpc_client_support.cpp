#include "native_addresses.h"
#include "native_records.h"

namespace R6GameServiceNative {
// RPC UUID and version fields in native little-endian storage order.
struct RpcSyntaxIdentifier {
  unsigned int uuidData1;
  unsigned short uuidData2;
  unsigned short uuidData3;
  unsigned char uuidData4[8];
  unsigned short majorVersion;
  unsigned short minorVersion;
};

// RPC_CLIENT_INTERFACE, exactly the selected 0x44-byte x86 record.
struct RpcClientInterface {
  unsigned int length;
  RpcSyntaxIdentifier interfaceId;
  RpcSyntaxIdentifier transferSyntax;
  Address dispatchTable;
  unsigned int endpointCount;
  Address endpoints;
  unsigned int reserved;
  Address interpreterInfo;
  unsigned int flags;
};

// Selected 0x50-byte MIDL_STUB_DESC; callback and handle fields are PE32 address words.
struct MidlStubDescriptor {
  Address rpcInterface;
  Address allocate;
  Address free;
  Address implicitHandle;
  Address rundownRoutines;
  Address genericBindingRoutines;
  Address expressionEvaluators;
  Address transmitAsRoutines;
  Address formatTypes;
  int checkBounds;
  unsigned int ndrVersion;
  Address mallocFreeStruct;
  unsigned int midlVersion;
  Address commFaultOffsets;
  Address userMarshalRoutines;
  Address notifyRoutines;
  unsigned int flags;
  Address codeSetRoutines;
  Address proxyServerInfo;
  Address expressionInfo;
};
} // namespace R6GameServiceNative

// Free RPC client wrappers and native MIDL bridges; object/service class ownership is not presumed.
// Selected 32-bit RPC records retain DWORD pointer words and documented SDK field names.
// Interface a5fd402b-7e0b-4758-a173-aa3c8047f340 v1.0; transfer syntax8a885d04-1ceb-11c9-9fe8-08002b104860 v2.0.
// R6GameService.dll data @ 10077650 : native storage identity retained.
const R6GameServiceNative::RpcClientInterface GUpdateServiceRpcInterface = {
  0x44,
  {0xa5fd402b, 0x7e0b, 0x4758, {0xa1, 0x73, 0xaa, 0x3c, 0x80, 0x47, 0xf3, 0x40}, 1, 0},
  {0x8a885d04, 0x1ceb, 0x11c9, {0x9f, 0xe8, 0x08, 0x00, 0x2b, 0x10, 0x48, 0x60}, 2, 0},
  0,
  0,
  0,
  0,
  0,
  0,
};
// These arrays cover referenced descriptors; they do not assert the original generated array declarations.
// -Oi headers use implicit primitive handle32, flags48, RPC flags0, procedure number and x86 stack-byte count.
// Context bytes are local wrapper gates; count/return uint views preserve raw32-bit words of wire FC_LONG values.
// Procedure0, four stack bytes for the FC_LONG return, no input arguments.
// R6GameService.dll data @ 1007769a : native storage identity retained.
const unsigned char GUpdateStateFormat[12] = {
  0x32,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00, // handle, flags, rpcFlags, procedure, stackBytes
  0x53,0x08 // FC_RETURN_PARAM_BASETYPE, FC_LONG
};
// Procedure1, four stack bytes for the FC_LONG return, no input arguments.
// R6GameService.dll data @ 100776a6 : native storage identity retained.
const unsigned char GUpdateExitFormat[12] = {
  0x32,0x48,0x00,0x00,0x00,0x00,0x01,0x00,0x04,0x00, // handle, flags, rpcFlags, procedure, stackBytes
  0x53,0x08 // FC_RETURN_PARAM_BASETYPE, FC_LONG
};
// Procedure2, eight output pointer words (32bytes), no return descriptor.
// R6GameService.dll data @ 100776b2 : native storage identity retained.
const unsigned char GUpdateProgressFormat[44] = {
  0x32,0x48,0x00,0x00,0x00,0x00,0x02,0x00,0x20,0x00, // handle, flags, rpcFlags, procedure, stackBytes
  0x51,0x01,0x02,0x00, // out pointer0, one stack word, type offset2
  0x51,0x01,0x02,0x00, // out pointer1, one stack word, type offset2
  0x51,0x01,0x02,0x00, // out pointer2, one stack word, type offset2
  0x51,0x01,0x02,0x00, // out pointer3, one stack word, type offset2
  0x51,0x01,0x06,0x00, // out pointer4, one stack word, type offset6
  0x51,0x01,0x06,0x00, // out pointer5, one stack word, type offset6
  0x51,0x01,0x0a,0x00, // out pointer6, one stack word, type offseta
  0x51,0x01,0x0a,0x00, // out pointer7, one stack word, type offseta
  0x5b,0x5c // FC_END, FC_PAD
};
// Procedure3, zero stack bytes and no return descriptor.
// R6GameService.dll data @ 100776de : native storage identity retained.
const unsigned char GUpdateAbortFormat[12] = {
  0x32,0x48,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00, // handle, flags, rpcFlags, procedure, stackBytes
  0x5b,0x5c // FC_END, FC_PAD
};
// Type offsets2/6 are simple reference pointers to DOUBLE/LONG; offseta is a fixed 65-byte char string.
// R6GameService.dll data @ 100776ee : native storage identity retained.
const unsigned char GUpdateServiceRpcTypes[14] = {
  0,0, // Unreferenced prefix
  0x11,0x08,0x0c,0x5c, // +02 FC_RP, FC_SIMPLE_POINTER, FC_DOUBLE, FC_PAD
  0x11,0x08,0x08,0x5c, // +06 FC_RP, FC_SIMPLE_POINTER, FC_LONG, FC_PAD
  0x26,0x5c,0x41,0x00 // +0a FC_CSTRING, FC_PAD, size65
};
// R6GameService.dll data @ 10077708 : native storage identity retained.
const R6GameServiceNative::MidlStubDescriptor GUpdateServiceStubDesc = {
  R6GameServiceAddresses::GUpdateServiceRpcInterface,
  R6GameServiceAddresses::AllocateMidlBuffer,
  R6GameServiceAddresses::FreeMidlBuffer,
  R6GameServiceAddresses::GUpdateServiceRpcHandle,
  0,
  0,
  0,
  0,
  R6GameServiceAddresses::GUpdateServiceRpcTypes,
  1,
  0x00010001,
  0,
  0x06000169,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
};

// Exact one-record SEH scopes and shared read-only binary64 zero.
// R6GameService.dll data @ 10077108 : native storage identity retained.
const R6GameServiceNative::SehScope GRpcStateScope[1] = {
  {-1, R6GameServiceAddresses::FilterRpcServiceStateException, R6GameServiceAddresses::HandleRpcServiceStateException},
};
// R6GameService.dll data @ 10077118 : native storage identity retained.
const R6GameServiceNative::SehScope GRpcExitCauseScope[1] = {
  {-1, R6GameServiceAddresses::FilterRpcExitCauseException, R6GameServiceAddresses::HandleRpcExitCauseException},
};
// R6GameService.dll data @ 10077128 : native storage identity retained.
const R6GameServiceNative::SehScope GRpcProgressScope[1] = {
  {-1, R6GameServiceAddresses::FilterRpcProgressException, R6GameServiceAddresses::HandleRpcProgressException},
};
// R6GameService.dll data @ 10077138 : native storage identity retained.
const R6GameServiceNative::SehScope GRpcAbortScope[1] = {
  {-1, R6GameServiceAddresses::FilterRpcAbortException, R6GameServiceAddresses::HandleRpcAbortException},
};
// R6GameService.dll data @ 1006bbf0 : native storage identity retained.
const double GSharedDoubleZero = 0.0;

// Selects native hexadecimal radix flags and returns the original ios receiver.
// R6GameService.dll @ 10034ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ApplyHexRadixManipulator(void *iosBase)
{
  __asm {
    // Native flags+10: clear0600/set0800; keep raw register/frame operations and original EAX receiver.
    push   ebp
    mov    ebp,esp
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [eax+0x10]
    and    ecx,0xfffff9ff
    or     ecx,0x800
    mov    DWORD PTR [eax+0x10],ecx
    pop    ebp
    ret
  }
}

// Calls the state RPC when enabled, writes the raw result through the current output pointer and retains native SEH behavior.
// R6GameService.dll @ 10034f00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl RpcGetServiceState(uint *resultOut,byte *contextByte)
{
  __asm {
    // Explicit EBP SEH frame: savedESP-18, exception code-1c, saved result-20 initially0; gate read occurs in state-1.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   offset GRpcStateScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x20],esi
    mov    eax,DWORD PTR [ebp+0xc]
    cmp    BYTE PTR [eax],0x0
    je     Branch1
    // State0 covers actual MIDL helper and subsequent current result-pointer store, not only RPC transport.
    mov    DWORD PTR [ebp-0x4],esi
    call   R6GameServiceAddresses::InvokeStateMidlCall
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch1:
    // Native disabled continuation @10034f97 after separate filter/handler; returnFFFFFFFF without output write.
    or     esi,0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Saves the parent exception code and returns the constant execute-handler disposition.
// R6GameService.dll @ 10034f5a : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRpcServiceStateException(void)
{
  __asm {
    // Inherited parent-14 -> exception pointers -> record code; store parent-1c, return EAX1.
    mov    edx,DWORD PTR [ebp-0x14]
    mov    eax,DWORD PTR [edx]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [ebp-0x1c],ecx
    mov    eax,0x1
    ret
  }
}

// Updates the current context byte from the saved exception code, restores saved result and returns through the parent frame.
// R6GameService.dll @ 10034f6a : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleRpcServiceStateException(void)
{
  __asm {
    // Inherited parent continuation restores ESP; context argument reloads after SETE, byte=(saved code==0).
    mov    esp,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x1c]
    test   eax,eax
    sete   dl
    mov    eax,DWORD PTR [ebp+0xc]
    mov    BYTE PTR [eax],dl
    mov    DWORD PTR [ebp-0x4],0xffffffff
    // Reload parent saved result-20 (normally0), not RPC EAX; own handler epilogue restores FS/nonvolatile/frame.
    mov    esi,DWORD PTR [ebp-0x20]
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Calls the exit-cause RPC when enabled and stores its raw result through the current output pointer.
// R6GameService.dll @ 10034fb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl RpcGetServiceExitCause(uint *resultOut,byte *contextByte)
{
  __asm {
    // Same explicit frame/gate/result contract as state wrapper, with independent exact scope/handler.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   offset GRpcExitCauseScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x20],esi
    mov    eax,DWORD PTR [ebp+0xc]
    cmp    BYTE PTR [eax],0x0
    je     Branch2
    mov    DWORD PTR [ebp-0x4],esi
    call   R6GameServiceAddresses::InvokeExitCauseMidlCall
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch2:
    // Native disabled continuation @10035047; no scalar output clearing.
    or     esi,0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Captures the exit-cause wrapper exception code and selects its native handler.
// R6GameService.dll @ 1003500a : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRpcExitCauseException(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x14]
    mov    eax,DWORD PTR [edx]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [ebp-0x1c],ecx
    mov    eax,0x1
    ret
  }
}

// Updates the current exit-cause context byte and restores the parent saved result/frame.
// R6GameService.dll @ 1003501a : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleRpcExitCauseException(void)
{
  __asm {
    mov    esp,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x1c]
    test   eax,eax
    sete   dl
    mov    eax,DWORD PTR [ebp+0xc]
    mov    BYTE PTR [eax],dl
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    esi,DWORD PTR [ebp-0x20]
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Forwards eight progress outputs when enabled, or resets them in native order when disabled.
// R6GameService.dll @ 10035060 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl RpcGetDownloadProgress(double *progressA,double *progressB,double *progressC,double *progressD,uint *countA,uint *countB,byte *textA,byte *textB,byte *contextByte)
{
  __asm {
    // Gate uses ninth pointer; disabled fallback outside try writes outputs sequentially. Preserve x87 waits and state timing.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   offset GRpcProgressScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x20],esi
    mov    eax,DWORD PTR [ebp+0x28]
    cmp    BYTE PTR [eax],0x0
    je     Branch3
    // First FWAIT is state-1, before try publication; pending x87 policy is not hidden by a high-level try block.
    fwait
    mov    DWORD PTR [ebp-0x4],esi
    // Copy eight original pointer words in native reverse-push order; actual36860 receives contiguous outgoing block.
    mov    ecx,DWORD PTR [ebp+0x24]
    push   ecx
    mov    edx,DWORD PTR [ebp+0x20]
    push   edx
    mov    eax,DWORD PTR [ebp+0x1c]
    push   eax
    mov    ecx,DWORD PTR [ebp+0x18]
    push   ecx
    mov    edx,DWORD PTR [ebp+0x14]
    push   edx
    mov    eax,DWORD PTR [ebp+0x10]
    push   eax
    mov    ecx,DWORD PTR [ebp+0xc]
    push   ecx
    mov    edx,DWORD PTR [ebp+0x8]
    push   edx
    call   R6GameServiceAddresses::InvokeProgressMidlCall
    add    esp,0x20
    // Second FWAIT remains state0 after RPC/stack cleanup, then state lowers-1.
    fwait
    mov    DWORD PTR [ebp-0x4],0xffffffff
    jmp    Branch4
  Branch3:
    // Disabled continuation @100350f5; after separate handler, shared postlude tests saved ESI result.
    or     esi,0xffffffff
  Branch4:
    test   esi,esi
    je     Branch5
    // Four separate FLD/FSTP zero stores reload pointer arguments; then DWORD counts, then byte text starts.
    fld    QWORD PTR [GSharedDoubleZero]
    mov    edx,DWORD PTR [ebp+0x8]
    fstp   QWORD PTR [edx]
    fld    QWORD PTR [GSharedDoubleZero]
    mov    eax,DWORD PTR [ebp+0xc]
    fstp   QWORD PTR [eax]
    fld    QWORD PTR [GSharedDoubleZero]
    mov    ecx,DWORD PTR [ebp+0x10]
    fstp   QWORD PTR [ecx]
    fld    QWORD PTR [GSharedDoubleZero]
    mov    edx,DWORD PTR [ebp+0x14]
    fstp   QWORD PTR [edx]
    mov    eax,DWORD PTR [ebp+0x18]
    mov    DWORD PTR [eax],0x0
    mov    ecx,DWORD PTR [ebp+0x1c]
    mov    DWORD PTR [ecx],0x0
    mov    edx,DWORD PTR [ebp+0x20]
    mov    BYTE PTR [edx],0x0
    mov    eax,DWORD PTR [ebp+0x24]
    mov    BYTE PTR [eax],0x0
  Branch5:
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Stores the progress wrapper exception code and returns the native constant handler disposition.
// R6GameService.dll @ 100350c9 : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRpcProgressException(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [ebp-0x1c],edx
    mov    eax,0x1
    ret
  }
}

// Updates the current progress context byte and branches to the shared saved-result continuation.
// R6GameService.dll @ 100350d9 : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleRpcProgressException(void)
{
  __asm {
    // Handler updates context from code==0, lowers state, reloads saved ESI and jumps shared postlude350f8.
    mov    esp,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x1c]
    test   eax,eax
    sete   al
    mov    ecx,DWORD PTR [ebp+0x28]
    mov    BYTE PTR [ecx],al
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    esi,DWORD PTR [ebp-0x20]
    jmp    R6GameServiceAddresses::rpc_client_supportBranch4
  }
}

// Calls the abort RPC when enabled and preserves native disabled/exception result behavior.
// R6GameService.dll @ 10035160 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl RpcAbortUpdateService(byte *contextByte)
{
  __asm {
    // Context gate in state-1; actual abort call state0, return saved0 regardless imported EAX.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   offset GRpcAbortScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x20],esi
    mov    eax,DWORD PTR [ebp+0x8]
    cmp    BYTE PTR [eax],0x0
    je     Branch6
    mov    DWORD PTR [ebp-0x4],esi
    call   R6GameServiceAddresses::InvokeAbortMidlCall
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch6:
    // Disabled continuation @100351f2 after separate filter/handler, returnFFFFFFFF.
    or     esi,0xffffffff
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Captures the abort wrapper exception code and returns execute-handler disposition.
// R6GameService.dll @ 100351b5 : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRpcAbortException(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edx]
    mov    DWORD PTR [ebp-0x1c],eax
    mov    eax,0x1
    ret
  }
}

// Updates the current abort context byte and returns the parent saved result after native frame restoration.
// R6GameService.dll @ 100351c5 : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleRpcAbortException(void)
{
  __asm {
    // Context argument reload occurs after code/SETE; own parent return preserves saved local result-20.
    mov    esp,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x1c]
    test   eax,eax
    sete   cl
    mov    edx,DWORD PTR [ebp+0x8]
    mov    BYTE PTR [edx],cl
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    esi,DWORD PTR [ebp-0x20]
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Passes the shared MIDL descriptor, first format and null argument block to the RPC import.
// R6GameService.dll @ 10036820 : complete native control/access order and raw ABI retained.
__declspec(naked) LONG __cdecl InvokeStateMidlCall(void)
{
  __asm {
    // Exact descriptor77708/format7769a/null block. Caller cleans three words and retains the raw32-bit RPC result in EAX.
    push   0x0
    push   offset GUpdateStateFormat
    push   offset GUpdateServiceStubDesc
    call   R6GameServiceAddresses::NdrClientCall
    add    esp,0xc
    ret
  }
}

// Passes the shared MIDL descriptor, second format and null argument block without normalizing the return.
// R6GameService.dll @ 10036840 : complete native control/access order and raw ABI retained.
__declspec(naked) LONG __cdecl InvokeExitCauseMidlCall(void)
{
  __asm {
    // Exact descriptor77708/format776a6/null block; no extra caller arguments are synthesized.
    push   0x0
    push   offset GUpdateExitFormat
    push   offset GUpdateServiceStubDesc
    call   R6GameServiceAddresses::NdrClientCall
    add    esp,0xc
    ret
  }
}

// Passes the original first stack-argument address as the MIDL parameter block.
// R6GameService.dll @ 10036860 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InvokeProgressMidlCall(double *progressA,double *progressB,double *progressC,double *progressD,LONG *countA,LONG *countB,char *textA,char *textB)
{
  __asm {
    // EBP+8 addresses eight original output-pointer words; text extents65. Void protocol leaves raw Ndr EAX observable.
    push   ebp
    mov    ebp,esp
    lea    eax,[ebp+0x8]
    push   eax
    push   offset GUpdateProgressFormat
    push   offset GUpdateServiceStubDesc
    call   R6GameServiceAddresses::NdrClientCall
    add    esp,0xc
    pop    ebp
    ret
  }
}

// Passes the abort format and null argument block to the shared RPC client import.
// R6GameService.dll @ 10036880 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InvokeAbortMidlCall(void)
{
  __asm {
    // Exact descriptor77708/format776de/null block for void abort. Raw Ndr EAX survives without a declared return value.
    push   0x0
    push   offset GUpdateAbortFormat
    push   offset GUpdateServiceStubDesc
    call   R6GameServiceAddresses::NdrClientCall
    add    esp,0xc
    ret
  }
}

// Tail-forwards the original variadic MIDL call to the current RPCRT4 NdrClientCall import.
// R6GameService.dll @ 10037120 : complete native control/access order and raw ABI retained.
__declspec(naked) CLIENT_CALL_RETURN __cdecl NdrClientCall(const void *stubDescriptor,const byte *procedureFormat,...)
{
  __asm {
    // Selected IAT6b534 is RPCRT4 NdrClientCall, not NdrClientCall2; imported marshalling/binding policy is external.
    jmp    DWORD PTR ds:R6GameServiceAddresses::RPCRT4_NdrClientCallSlot
  }
}

// Adapts the MIDL callee-clean allocation callback to the CRT caller-clean allocator.
// R6GameService.dll @ 100370f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall AllocateMidlBuffer(uint byteCount)
{
  __asm {
    // Original size argument copied to CRT malloc6b384, caller-cleans temporary word, callback RET4; no added checks.
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_mallocSlot
    add    esp,0x4
    ret    0x4
  }
}

// Adapts the MIDL callee-clean free callback to the CRT and retains native volatile-register effects.
// R6GameService.dll @ 10037110 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall FreeMidlBuffer(void *buffer)
{
  __asm {
    // Original pointer copied to CRT free6b414 even null; POP ECX retains buffer word, raw CRT EAX survives, RET4.
    mov    eax,DWORD PTR [esp+0x4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    pop    ecx
    ret    0x4
  }
}
