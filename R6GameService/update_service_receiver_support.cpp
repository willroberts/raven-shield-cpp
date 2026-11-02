#include "native_addresses.h"
#include "native_records.h"

// Service-receiver views; the original class and whether the first string is a base or member remain unresolved.
// Observed offsets: string0, rawDWORD1c, allocated slot20, binding24/28, contextBYTE2c, state30, exit34, HANDLE38,
// deadlines3c/40, interval44, progress storage48..6f, strings70/8c. No complete class layout is inferred.
// Cleanup returns expose raw EAX, not recovered declarations; wide literals follow the selected 16-bit ABI.
// R6GameService.dll data @ 1007714c : native storage identity retained.
const wchar_t GServiceResultSeparator[] = L";";
// R6GameService.dll data @ 10077150 : native storage identity retained.
const wchar_t GServiceRpcErrorPrefix[] = L"RPC error: 0x";
// R6GameService.dll data @ 1007716c : native storage identity retained.
const wchar_t GServiceRpcMessageSeparator[] = L", ";
// R6GameService.dll data @ 10077174 : native storage identity retained.
const wchar_t GServiceStateRequest[] = L"RPC request: GetState(): ";
// R6GameService.dll data @ 100771a8 : native storage identity retained.
const wchar_t GServiceExitRequest[] = L"RPC request: GetExitCause(): ";
// R6GameService.dll data @ 10080a50 : native storage identity retained.
const R6GameServiceNative::UnwindEntry update_service_receiver_supportSharedLifetimeUnwindMap[4] = {
  {-1, R6GameServiceAddresses::UnwindReceiverFirstString},
  {0, R6GameServiceAddresses::UnwindReceiverProcessSlot},
  {1, R6GameServiceAddresses::UnwindReceiverRpcBinding},
  {2, R6GameServiceAddresses::UnwindReceiverSecondString},
};
// R6GameService.dll data @ 10080a70 : native storage identity retained.
const R6GameServiceNative::FuncInfo update_service_receiver_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  4,
  R6GameServiceAddresses::update_service_receiver_supportSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Constructs three wide strings, the process slot and RPC state, leaving progress-cache storage untouched.
// R6GameService.dll @ 10035210 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall ConstructUpdateServiceReceiver(void *receiver)
{
  __asm {
    // Explicit EBP lifetime frame: saved receiver-10, FS node-c, state-4. First wide constructor runs at state-1.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectReceiverLifetimeInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    // Only after string0 completes: zero rawDWORD1c, allocate slot20 (allocation failure still allows construction).
    xor    ebx,ebx
    lea    ecx,[esi+0x20]
    mov    DWORD PTR [ebp-0x4],ebx
    mov    DWORD PTR [esi+0x1c],ebx
    call   R6GameServiceAddresses::AllocateProcessHandleSlot
    lea    ecx,[esi+0x24]
    // State1 owns slot20. Initialize binding24/28, then state2 owns it before the remaining scalar initialization.
    mov    BYTE PTR [ebp-0x4],0x1
    call   R6GameServiceAddresses::InitializeRpcBindingState
    lea    ecx,[esi+0x70]
    mov    BYTE PTR [ebp-0x4],0x2
    // Zero context byte and six DWORDs only; padding2d..2f and progress48..6f retain prior bytes.
    mov    BYTE PTR [esi+0x2c],bl
    mov    DWORD PTR [esi+0x30],ebx
    mov    DWORD PTR [esi+0x34],ebx
    mov    DWORD PTR [esi+0x38],ebx
    mov    DWORD PTR [esi+0x3c],ebx
    mov    DWORD PTR [esi+0x40],ebx
    mov    DWORD PTR [esi+0x44],ebx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    // State3 owns string70 while constructing string8c; no fifth state or string8c unwind action.
    lea    ecx,[esi+0x8c]
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    // Return cached receiver ESI, ignoring constructor helper EAX values; restore original FS registration.
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Closes the optional handle, then destroys the receiver strings, binding state and process slot in native order.
// R6GameService.dll @ 100352a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyUpdateServiceReceiver(void *receiver)
{
  __asm {
    // Explicit frame shares the constructor map and saves receiver-10; cleanup return is raw final string-dtor EAX.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectReceiverLifetimeInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esi
    // Optional HANDLE38 loads before state3 publication; close does not clear it. State3 also covers string8c dtor.
    mov    eax,DWORD PTR [esi+0x38]
    test   eax,eax
    mov    DWORD PTR [ebp-0x4],0x3
    je     Branch1
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CloseHandleSlot
  Branch1:
    lea    ecx,[esi+0x8c]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // Lower each state before destroying string70, binding24, slot20, then first string0.
    lea    ecx,[esi+0x70]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esi+0x24]
    mov    BYTE PTR [ebp-0x4],0x1
    call   R6GameServiceAddresses::ReleaseRpcBindingState
    lea    ecx,[esi+0x20]
    mov    BYTE PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::CloseAndFreeProcessHandleSlot
    mov    ecx,esi
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Returns cached state, refreshing and logging it when the unsigned tick deadline is reached unless state is five.
// R6GameService.dll @ 10035330 : complete native control/access order and raw ABI retained.
__declspec(naked) int __fastcall GetServiceStateIfRefreshDue(void *receiver)
{
  __asm {
    // Cookie-protected local message buffer at EBP-804; request-start tick at-808. Cache receiver EDI/state pointer EBX.
    push   ebp
    mov    ebp,esp
    sub    esp,0x808
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    push   edi
    mov    edi,ecx
    lea    ebx,[edi+0x30]
    mov    DWORD PTR [ebp-0x4],eax
    cmp    DWORD PTR [ebx],0x5
    jne    Branch2
    // Initial state5 returns literal5 without tick, RPC or logging, retaining actual native cookie check.
    pop    edi
    mov    eax,0x5
    pop    ebx
    mov    ecx,DWORD PTR [ebp-0x4]
    call   R6GameServiceAddresses::__security_check_cookie
    mov    esp,ebp
    pop    ebp
    ret
  Branch2:
    // Unsigned current tick vs current deadline3c; retain the request-start tick before any logging/RPC callbacks.
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    cmp    eax,DWORD PTR [edi+0x3c]
    mov    DWORD PTR [ebp-0x808],eax
    jb     Branch4
    // Cache current endl before getter. Cache wide insertion IAT only after getter; reuse it through the entire refresh.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   esi
    push   eax
    push   offset GServiceStateRequest
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Actual scalar RPC wrapper(out state30,context2c), cdecl. Failure does not reset cached state.
    lea    ecx,[edi+0x2c]
    push   ecx
    push   ebx
    call   R6GameServiceAddresses::RpcGetServiceState
    add    esp,0x8
    test   eax,eax
    je     Branch3
    cmp    eax,0xffffffff
    je     Branch3
    // For status other than0/-1, FormatMessageW(1000,null,status,400,buffer,400,null); ignore returned length.
    push   0x0
    push   0x400
    lea    edx,[ebp-0x804]
    push   edx
    push   0x400
    push   eax
    push   0x0
    push   0x1000
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_FormatMessageWSlot
    // Native error chain is prefix -> hex manipulator -> comma separator -> message -> endl: NO error-number insertion.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   eax
    lea    ecx,[ebp-0x804]
    push   ecx
    push   offset GServiceRpcMessageSeparator
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GServiceRpcErrorPrefix
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
  Branch3:
    // Snapshot state and current endl before getter; log signed state and semicolon through returned stream pointers.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    mov    eax,DWORD PTR [ebx]
    push   edx
    push   offset GServiceResultSeparator
    push   eax
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot2
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Deadline uses request-start tick plus CURRENT interval44, modulo32, after all logging; final return reloads state.
    mov    ecx,DWORD PTR [edi+0x44]
    add    ecx,DWORD PTR [ebp-0x808]
    mov    DWORD PTR [edi+0x3c],ecx
    pop    esi
  Branch4:
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [ebp-0x4]
    pop    edi
    pop    ebx
    call   R6GameServiceAddresses::__security_check_cookie
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Returns cached exit cause, requesting and logging it through RPC while the cached value is zero.
// R6GameService.dll @ 10035460 : complete native control/access order and raw ABI retained.
__declspec(naked) int __fastcall GetServiceExitCauseIfUnset(void *receiver)
{
  __asm {
    // Cookie-protected message buffer EBP-804; cached exit pointer EDI. Nonzero initial exit skips all requests/logging.
    push   ebp
    mov    ebp,esp
    sub    esp,0x804
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    mov    ebx,ecx
    push   edi
    lea    edi,[ebx+0x34]
    mov    DWORD PTR [ebp-0x4],eax
    mov    eax,DWORD PTR [edi]
    test   eax,eax
    jne    Branch6
    // Cache endl before getter and wide insertion after it, then reuse that insertion target through the request.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   esi
    push   eax
    push   offset GServiceExitRequest
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Actual scalar RPC wrapper(out exit34,context2c), cdecl; no deadline/tick access.
    add    ebx,0x2c
    push   ebx
    push   edi
    call   R6GameServiceAddresses::RpcGetServiceExitCause
    add    esp,0x8
    test   eax,eax
    je     Branch5
    cmp    eax,0xffffffff
    je     Branch5
    // Error FormatMessageW return is ignored; native buffer contents are passed through even on formatting failure.
    push   0x0
    push   0x400
    lea    ecx,[ebp-0x804]
    push   ecx
    push   0x400
    push   eax
    push   0x0
    push   0x1000
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_FormatMessageWSlot
    // Prefix, hex manipulator, comma separator, message, endl only; do not add an error-number insertion.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    lea    eax,[ebp-0x804]
    push   eax
    push   offset GServiceRpcMessageSeparator
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GServiceRpcErrorPrefix
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
  Branch5:
    // Snapshot exit/current endl before getter, but return a fresh exit load after the full log chain.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    mov    edx,DWORD PTR [edi]
    push   ecx
    push   offset GServiceResultSeparator
    push   edx
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot2
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    mov    eax,DWORD PTR [edi]
    pop    esi
  Branch6:
    mov    ecx,DWORD PTR [ebp-0x4]
    pop    edi
    pop    ebx
    call   R6GameServiceAddresses::__security_check_cookie
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Destroys the first wide string through the inherited receiver binding.
// R6GameService.dll @ 10066570 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindReceiverFirstString(void)
{
  __asm {
    // Inherited parent EBP-10 reload; each action exposes raw tail EAX and leaves receiver ownership unchanged.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Closes and frees the process slot through the inherited receiver binding.
// R6GameService.dll @ 10066579 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindReceiverProcessSlot(void)
{
  __asm {
    // The process-slot helper receives receiver+20, not the slot or HANDLE value.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::CloseAndFreeProcessHandleSlot
  }
}

// Releases the RPC binding through the inherited receiver binding.
// R6GameService.dll @ 10066584 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindReceiverRpcBinding(void)
{
  __asm {
    // The binding helper receives receiver+24; it reloads current fields during release.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x24
    jmp    R6GameServiceAddresses::ReleaseRpcBindingState
  }
}

// Destroys the wide string at receiver+70 through the inherited receiver binding.
// R6GameService.dll @ 1006658f : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindReceiverSecondString(void)
{
  __asm {
    // State3 unwinds string70; no action for string8c is present in this native map.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x70
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects the four-state receiver lifetime map and tail-transfers to the native C++ frame handler.
// R6GameService.dll @ 1006659b : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectReceiverLifetimeInfo(void)
{
  __asm {
    // EAX FuncInfo80a70, exact map80a50; native33906 forwards to the CRT frame handler.
    mov    eax,offset update_service_receiver_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Wrapper allocation owns only the raw receiver block until publication; no wrapper class declaration is inferred.
// R6GameService.dll data @ 10077144 : native storage identity retained.
const char GServiceStartDiagnostic[] = "START";
// R6GameService.dll data @ 10080ab8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry update_service_receiver_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::UnwindReceiverAllocation},
};
// R6GameService.dll data @ 10080ac0 : native storage identity retained.
const R6GameServiceNative::FuncInfo update_service_receiver_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  1,
  R6GameServiceAddresses::update_service_receiver_supportSharedLifetimeUnwindMap2,
  0,
  0,
  0,
  0,
};

// Allocates a receiver, constructs it when nonnull and publishes the returned receiver into the cached wrapper slot.
// R6GameService.dll @ 10035870 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall CreateServiceObjectInPointerSlot(void *objectSlot)
{
  __asm {
    // EBP SEH savedallocation-10/FSnode-c/state-4; cache destination ESI before allocator(a8), initially state-1.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectReceiverAllocationInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   0xa8
    mov    esi,ecx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    // Save raw allocation then publish state0, even for null. State0 also covers the destination write after construction.
    mov    DWORD PTR [ebp-0x10],eax
    test   eax,eax
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch7
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructUpdateServiceReceiver
    // Store constructor-returned EAX, return cached destination; saved allocation remains original allocator result.
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret
  Branch7:
    // Null allocation publishes0 without constructor, restoring original FS; no old receiver free or stronger guarantee.
    mov    ecx,DWORD PTR [ebp-0xc]
    xor    eax,eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Prints START and endl to cout, assigns the cached receiver string and sets only AL to one.
// R6GameService.dll @ 100358e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StoreWideStringAndPrintStart(void *wrapper,const unsigned short *wideText)
{
  __asm {
    // Cache current endl first and receiver before cout logging; this is CRT unsigned-short string assignment, not FString.
    push   ebp
    mov    ebp,esp
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot2
    push   esi
    mov    esi,DWORD PTR [ecx]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_coutSlot
    push   eax
    push   offset GServiceStartDiagnostic
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_D__6U_char_traitsSlot
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot
    // Reload current wideText stack argument after logging; receiver ESI stays cached even if wrapper changes.
    mov    edx,DWORD PTR [ebp+0x8]
    push   edx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot
    // Set AL only: upper24 bits remain from imported string assignment EAX. No local EH.
    mov    al,0x1
    pop    esi
    pop    ebp
    ret    0x4
  }
}

// Loads the stored receiver and tail-forwards to its state-cache getter.
// R6GameService.dll @ 10035920 : complete native control/access order and raw ABI retained.
__declspec(naked) int __fastcall GetServiceStateThroughStoredReceiver(void *wrapper)
{
  __asm {
    // Exactly one unchecked receiver load, raw tail35330; arguments, return address and EDX otherwise unchanged.
    mov    ecx,DWORD PTR [ecx]
    jmp    R6GameServiceAddresses::GetServiceStateIfRefreshDue
  }
}

// Loads the stored receiver and tail-forwards to its exit-cause cache getter.
// R6GameService.dll @ 10035930 : complete native control/access order and raw ABI retained.
__declspec(naked) int __fastcall GetServiceExitCauseThroughStoredReceiver(void *wrapper)
{
  __asm {
    // Exactly one unchecked receiver load, raw tail35460.
    mov    ecx,DWORD PTR [ecx]
    jmp    R6GameServiceAddresses::GetServiceExitCauseIfUnset
  }
}

// Loads the stored receiver and tail-forwards all eight progress-output pointer arguments unchanged.
// R6GameService.dll @ 10035940 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall GetDownloadProgressThroughStoredReceiver(void *wrapper,double *a,double *b,double *c,double *d,DWORD *countA,DWORD *countB,void *textA,void *textB)
{
  __asm {
    // Temporary EBP push/pop restores the caller frame before tail35560; eight pointer arguments are not rebuilt.
    push   ebp
    mov    ebp,esp
    mov    ecx,DWORD PTR [ecx]
    pop    ebp
    jmp    R6GameServiceAddresses::GetDownloadProgressWithCache
  }
}

// Loads the stored receiver and tail-forwards to its abort request.
// R6GameService.dll @ 10035950 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall RequestAbortUpdateServiceThroughStoredReceiver(void *wrapper)
{
  __asm {
    // Exactly one unchecked receiver load, raw tail357a0.
    mov    ecx,DWORD PTR [ecx]
    jmp    R6GameServiceAddresses::RequestAbortUpdateServiceWithLogging
  }
}

// Stores the raw interval DWORD at the stored receiver plus44 and retains that receiver in EAX.
// R6GameService.dll @ 10035960 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetServiceCacheInterval(void *wrapper,DWORD intervalMilliseconds)
{
  __asm {
    // EAX loads receiver before interval argument; only receiver+44 changes, no deadline reset or validation.
    push   ebp
    mov    ebp,esp
    mov    eax,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [eax+0x44],ecx
    pop    ebp
    ret    0x4
  }
}

// Destroys and frees the cached stored receiver when nonnull, leaving the wrapper pointer unchanged.
// R6GameService.dll @ 10035ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceObjectInPointerSlot(void *objectSlot)
{
  __asm {
    // Cache stored receiver ESI. Null preserves incoming EAX; otherwise call destructor352a0 then free1180.
    push   esi
    mov    esi,DWORD PTR [ecx]
    test   esi,esi
    je     Branch8
    mov    ecx,esi
    call   R6GameServiceAddresses::DestroyUpdateServiceReceiver
    // Free cached receiver even if earlier destructor changed wrapper; no wrapper clear, local EH or guaranteed free on throw.
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch8:
    pop    esi
    ret
  }
}

// Loads the stored receiver and tail-forwards all three update-host launch arguments unchanged.
// R6GameService.dll @ 10035af0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StartUpdateServiceThroughStoredReceiver(void *wrapper,unsigned short *applicationName,unsigned short *commandLine,const unsigned short *currentDirectory)
{
  __asm {
    // Restore caller EBP before tail35970; preserve exact launch argument addresses/order.
    push   ebp
    mov    ebp,esp
    mov    ecx,DWORD PTR [ecx]
    pop    ebp
    jmp    R6GameServiceAddresses::StartUpdateServiceProcessAndConnectRpc
  }
}

// Frees the allocation reloaded from the inherited parent frame without destroying receiver members.
// R6GameService.dll @ 100665e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindReceiverAllocation(void)
{
  __asm {
    // Inherited EBP-10 allocation reload; free1180 only. POP ECX caller cleanup leaves raw free EAX intact.
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Selects the receiver-allocation lifetime map and tail-transfers to the native C++ frame handler.
// R6GameService.dll @ 100665eb : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectReceiverAllocationInfo(void)
{
  __asm {
    // EAX exact FuncInfo80ac0, one-state map80ab8; actual33906 routes to imported CRT handler.
    mov    eax,offset update_service_receiver_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Progress text temporaries have independent states: each cleanup returns directly to state-1.
// R6GameService.dll data @ 100771e8 : native storage identity retained.
const wchar_t GServiceProgressRequest[] = L"RPC request: GetDownloadProgress()";
// R6GameService.dll data @ 10077230 : native storage identity retained.
const wchar_t GServiceAbortRequest[] = L"RPC request: AbortUpdateService()";
// R6GameService.dll data @ 10080a8c : native storage identity retained.
const R6GameServiceNative::UnwindEntry update_service_receiver_supportSharedLifetimeUnwindMap3[2] = {
  {-1, R6GameServiceAddresses::UnwindFirstProgressText},
  {-1, R6GameServiceAddresses::UnwindSecondProgressText},
};
// R6GameService.dll data @ 10080a9c : native storage identity retained.
const R6GameServiceNative::FuncInfo update_service_receiver_supportSharedLifetimeExceptionInfo3 = {
  0x19930520,
  2,
  R6GameServiceAddresses::update_service_receiver_supportSharedLifetimeUnwindMap3,
  0,
  0,
  0,
  0,
};

// Copies cached progress before its unsigned deadline, otherwise requests outputs, converts text and updates the cache.
// R6GameService.dll @ 10035560 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall GetDownloadProgressWithCache(void *receiver,double *a,double *b,double *c,double *d,DWORD *countA,DWORD *countB,void *textA,void *textB)
{
  __asm {
    // EBP frame: state-4/FSnode-c/cookie-10; temp strings-8d4/-8b8, tick-89c, message-898, ANSI outputs-54/-98.
    // RPC fixed-string extents65, local starts68bytes apart; original C-array declarations remain unresolved.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectProgressTextLifetimeInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8c8
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    mov    DWORD PTR [ebp-0x10],eax
    mov    esi,ecx
    // Unsigned current tick vs current deadline40; retain request-start tick before all callbacks. No state5 shortcut.
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    cmp    eax,DWORD PTR [esi+0x40]
    mov    DWORD PTR [ebp-0x89c],eax
    jb     Branch10
    // Cache endl before getter and wide insertion EDI only after getter; reuse insertion through request/error logs.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ebx
    push   edi
    push   eax
    push   offset GServiceProgressRequest
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Actual progress RPC35060 receives six caller output pointers, two local ANSI buffers and receiver context2c.
    lea    ecx,[esi+0x2c]
    push   ecx
    mov    ecx,DWORD PTR [ebp+0x1c]
    lea    edx,[ebp-0x98]
    push   edx
    mov    edx,DWORD PTR [ebp+0x18]
    lea    eax,[ebp-0x54]
    push   eax
    mov    eax,DWORD PTR [ebp+0x14]
    push   ecx
    mov    ecx,DWORD PTR [ebp+0x10]
    push   edx
    mov    edx,DWORD PTR [ebp+0xc]
    push   eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::RpcGetDownloadProgress
    add    esp,0x24
    test   eax,eax
    je     Branch9
    cmp    eax,0xffffffff
    je     Branch9
    // Only non0/nonFFFFFFFF status formats an error; buffer/return length are not checked or initialized here.
    push   0x0
    push   0x400
    lea    ecx,[ebp-0x898]
    push   ecx
    push   0x400
    push   eax
    push   0x0
    push   0x1000
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_FormatMessageWSlot
    // Error chain: prefix, hex manipulator, comma, message, endl; no numeric RPC error insertion.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    lea    eax,[ebp-0x898]
    push   eax
    push   offset GServiceRpcMessageSeparator
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GServiceRpcErrorPrefix
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    push   eax
    call   edi
    add    esp,0x8
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
  Branch9:
    // All statuses continue here. Convert ANSI A via36f60; returned temporary pointer is copied to current caller textA.
    lea    ecx,[ebp-0x54]
    push   ecx
    lea    edx,[ebp-0x8d4]
    push   edx
    call   R6GameServiceAddresses::ConstructWideStringFromAnsi
    add    esp,0x8
    mov    edi,DWORD PTR [ebp+0x20]
    push   eax
    mov    ecx,edi
    // Only assignment owns tempA in state0. Lower to-1 before its explicit destructor; no retry on destructor failure.
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
    lea    ecx,[ebp-0x8d4]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // Convert ANSI B, then cache current textB pointer EBX; state1 owns tempB independently of tempA.
    lea    eax,[ebp-0x98]
    push   eax
    lea    ecx,[ebp-0x8b8]
    push   ecx
    call   R6GameServiceAddresses::ConstructWideStringFromAnsi
    add    esp,0x8
    mov    ebx,DWORD PTR [ebp+0x24]
    push   eax
    mov    ecx,ebx
    mov    DWORD PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
    lea    ecx,[ebp-0x8b8]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // After both temporary destructors, reread caller scalar outputs with native x87 load/store order into cache.
    mov    edx,DWORD PTR [ebp+0x8]
    fld    QWORD PTR [edx]
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp+0x10]
    fstp   QWORD PTR [esi+0x48]
    fld    QWORD PTR [eax]
    mov    edx,DWORD PTR [ebp+0x14]
    mov    eax,DWORD PTR [ebp+0x18]
    fstp   QWORD PTR [esi+0x50]
    fld    QWORD PTR [ecx]
    // Retain cached textA EDI and textB EBX for cache string copies; current scalar pointer args reload as shown.
    push   edi
    fstp   QWORD PTR [esi+0x58]
    fld    QWORD PTR [edx]
    mov    edx,DWORD PTR [ebp+0x1c]
    fstp   QWORD PTR [esi+0x60]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x68],ecx
    mov    eax,DWORD PTR [edx]
    lea    ecx,[esi+0x70]
    mov    DWORD PTR [esi+0x6c],eax
    // Cache strings only after scalar writes; failures leave prior partial updates, state-1, deadline unchanged.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
    push   ebx
    lea    ecx,[esi+0x8c]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
    // Only after all copies: deadline40=request-start tick+CURRENT interval44 modulo32. No status-dependent rollback.
    mov    ecx,DWORD PTR [esi+0x44]
    add    ecx,DWORD PTR [ebp-0x89c]
    pop    edi
    mov    DWORD PTR [esi+0x40],ecx
    pop    ebx
    jmp    Branch11
  Branch10:
    // Cached path uses interleaved x87 loads/stores and argument reads; aliases can affect later source/pointer loads.
    fld    QWORD PTR [esi+0x48]
    mov    edx,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebp+0xc]
    fstp   QWORD PTR [edx]
    fld    QWORD PTR [esi+0x50]
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    edx,DWORD PTR [ebp+0x14]
    fstp   QWORD PTR [eax]
    fld    QWORD PTR [esi+0x58]
    fstp   QWORD PTR [ecx]
    mov    ecx,DWORD PTR [ebp+0x18]
    fld    QWORD PTR [esi+0x60]
    fstp   QWORD PTR [edx]
    mov    eax,DWORD PTR [esi+0x68]
    mov    DWORD PTR [ecx],eax
    mov    edx,DWORD PTR [esi+0x6c]
    mov    eax,DWORD PTR [ebp+0x1c]
    // Copy cached wide strings to current caller destinations in order; second destination reloads after first assignment.
    lea    ecx,[esi+0x70]
    push   ecx
    mov    ecx,DWORD PTR [ebp+0x20]
    mov    DWORD PTR [eax],edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
    mov    ecx,DWORD PTR [ebp+0x24]
    add    esi,0x8c
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_4_basic_stringSlot2
  Branch11:
    // Restore original FS before actual cookie check62281; raw final assignment EAX survives, RET20.
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [ebp-0x10]
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    mov    esp,ebp
    pop    ebp
    ret    0x20
  }
}

// Logs the abort request, calls its RPC wrapper and conditionally logs a formatted error.
// R6GameService.dll @ 100357a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall RequestAbortUpdateServiceWithLogging(void *receiver)
{
  __asm {
    // Cookie atEBP-4, message at-804; receiver cachedEDI before log getter. No local lifetime/catch frame.
    push   ebp
    mov    ebp,esp
    sub    esp,0x804
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    mov    DWORD PTR [ebp-0x4],eax
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edi
    push   eax
    push   offset GServiceAbortRequest
    mov    edi,ecx
    // Cache current endl before getter, wide insertion ESI after getter; exact returned-stream chain retained.
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Actual abort RPC35160(context2c), cdecl. No state/exit/progress/deadline cache reset.
    add    edi,0x2c
    push   edi
    call   R6GameServiceAddresses::RpcAbortUpdateService
    add    esp,0x4
    test   eax,eax
    je     Branch12
    cmp    eax,0xffffffff
    je     Branch12
    // Only status other than0/-1 formats/logs error; formatter failure still passes uninitialized/current buffer pointer.
    push   0x0
    push   0x400
    lea    ecx,[ebp-0x804]
    push   ecx
    push   0x400
    push   eax
    push   0x0
    push   0x1000
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_FormatMessageWSlot
    // Native prefix -> hex manipulator -> comma -> message -> endl, with no numeric status insertion.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    lea    eax,[ebp-0x804]
    push   eax
    push   offset GServiceRpcMessageSeparator
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GServiceRpcErrorPrefix
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
  Branch12:
    // Raw EAX is RPC status on0/-1 path, final stream result on logged error; cookie check preserves it.
    mov    ecx,DWORD PTR [ebp-0x4]
    pop    edi
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Destroys the first converted progress string in the inherited parent frame.
// R6GameService.dll @ 100665b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindFirstProgressText(void)
{
  __asm {
    // Inherited EBP-8d4 temporary, tail imported CRT wide-string destructor; state0 previous-1.
    lea    ecx,[ebp-0x8d4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the second converted progress string in the inherited parent frame.
// R6GameService.dll @ 100665bc : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindSecondProgressText(void)
{
  __asm {
    // Inherited EBP-8b8 temporary, tail imported CRT wide-string destructor; state1 previous-1.
    lea    ecx,[ebp-0x8b8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects the two independent progress-text cleanup states and transfers to the native C++ frame handler.
// R6GameService.dll @ 100665c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectProgressTextLifetimeInfo(void)
{
  __asm {
    // EAX exact FuncInfo80a9c; map80a8c owns each temporary separately, no catches; actual33906 -> CRT handler.
    mov    eax,offset update_service_receiver_supportSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
