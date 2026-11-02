#include "native_addresses.h"
#include "native_records.h"

// CD-key service callbacks and shared diagnostic string cleanup; concrete callback owner remains unresolved.
// uint callback return views expose raw EAX; original callback return declaration is unavailable.
// Native formatter effects on FS and the delayed assignment-state arm remain unchanged.

// Append validation status/request/success/timeout/global ID before optionally logging the current record.
// Callback name is supported by native diagnostics; free-function scope and raw uint return view are inferred.
// Five DWORD arguments, RET20, unused incoming ECX and second/third arguments; no own EH or rollback.
// Queue93470 uses32-byte records: statusDWORD0, requestDWORD4, successDWORD8, timeoutDWORDc, ID16 at10.
// Success is the complete input byte4; timeout compares input WORD6 to1. Tail copies four forward DWORDs.
// Source response pointer is captured; queue data reloads for each field, then ID destination captures once.
// One debug gate; four current record/device diagnostics share cached Logf, followed by status0/1/2 label.
// Final label uses original full status; other status words skip it. Any callback failure retains prior writes.
// R6GameService.dll @ 1000ea60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RcvValidationResponse(const void *response,uint unusedSecond,uint unusedThird,
    uint status,const uchar *globalId)
{
  __asm {
    push   ebx
    push   esi
    push   0x1
    push   0x20
    mov    ecx,R6GameServiceAddresses::GServiceArray8
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ebx,DWORD PTR [esp+0x18]
    shl    eax,0x5
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8
    mov    DWORD PTR [esi+eax*1],ebx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esi+edx*1+0x4],ecx
    movzx  ecx,BYTE PTR [eax+0x4]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    DWORD PTR [esi+edx*1+0x8],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    xor    ecx,ecx
    cmp    WORD PTR [eax+0x6],0x1
    sete   cl
    mov    DWORD PTR [esi+edx*1+0xc],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [esp+0x1c]
    lea    ecx,[esi+eax*1+0x10]
    mov    eax,DWORD PTR [edx]
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0x8],eax
    mov    edx,DWORD PTR [edx+0xc]
    mov    DWORD PTR [ecx+0xc],edx
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch4
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8
    mov    ecx,DWORD PTR [esi+eax*1]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackRcvValidationResponseEStatusI
    push   eax
    call   edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [esi+ecx*1+0x4]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackRcvValidationResponseIReqIDI
    push   ecx
    call   edi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    eax,DWORD PTR [esi+edx*1+0x8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackRcvValidationResponseBSuceededI
    push   edx
    call   edi
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8
    mov    ecx,DWORD PTR [esi+eax*1+0xc]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackRcvValidationResponseBTimeoutI
    push   eax
    call   edi
    mov    eax,ebx
    add    esp,0x30
    sub    eax,0x0
    je     Branch2
    dec    eax
    je     Branch1
    dec    eax
    jne    Branch3
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERVALID
    push   edx
    call   edi
    add    esp,0x8
    pop    edi
    pop    esi
    pop    ebx
    ret    0x14
  Branch1:
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERINVALID
    push   ecx
    call   edi
    add    esp,0x8
    pop    edi
    pop    esi
    pop    ebx
    ret    0x14
  Branch2:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERUNKNOWN
    push   eax
    call   edi
    add    esp,0x8
  Branch3:
    pop    edi
  Branch4:
    pop    esi
    pop    ebx
    ret    0x14
  }
}

// Append validation status/request/success/timeout/global ID before optionally logging the current record.
// Callback name is supported by native diagnostics; free-function scope and raw uint return view are inferred.
// Five DWORD arguments, RET20, unused incoming ECX and second/third arguments; no own EH or rollback.
// Queue93464 uses32-byte records: statusDWORD0, requestDWORD4, successDWORD8, timeoutDWORDc, ID16 at10.
// Success is the complete input byte4; timeout compares input WORD6 to1. Tail copies four forward DWORDs.
// Source response pointer is captured; queue data reloads for each field, then ID destination captures once.
// One debug gate; four current record/device diagnostics share cached Logf, followed by status0/1/2 label.
// Final label uses original full status; other status words skip it. Any callback failure retains prior writes.
// R6GameService.dll @ 1000ebb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall RcvModValidationResponse(const void *response,uint unusedSecond,uint unusedThird,
    uint status,const uchar *globalId)
{
  __asm {
    push   ebx
    push   esi
    push   0x1
    push   0x20
    mov    ecx,R6GameServiceAddresses::GServiceArray7
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ebx,DWORD PTR [esp+0x18]
    shl    eax,0x5
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7
    mov    DWORD PTR [esi+eax*1],ebx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [esi+edx*1+0x4],ecx
    movzx  ecx,BYTE PTR [eax+0x4]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    DWORD PTR [esi+edx*1+0x8],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    xor    ecx,ecx
    cmp    WORD PTR [eax+0x6],0x1
    sete   cl
    mov    DWORD PTR [esi+edx*1+0xc],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7
    mov    edx,DWORD PTR [esp+0x1c]
    lea    ecx,[esi+eax*1+0x10]
    mov    eax,DWORD PTR [edx]
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0x8],eax
    mov    edx,DWORD PTR [edx+0xc]
    mov    DWORD PTR [ecx+0xc],edx
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch8
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7
    mov    ecx,DWORD PTR [esi+eax*1]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseEStatusI
    push   eax
    call   edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    edx,DWORD PTR [esi+ecx*1+0x4]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseIReqIDI
    push   ecx
    call   edi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    eax,DWORD PTR [esi+edx*1+0x8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseBSuceededI
    push   edx
    call   edi
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7
    mov    ecx,DWORD PTR [esi+eax*1+0xc]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseBTimeoutI
    push   eax
    call   edi
    mov    eax,ebx
    add    esp,0x30
    sub    eax,0x0
    je     Branch6
    dec    eax
    je     Branch5
    dec    eax
    jne    Branch7
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextRcvModValidationResponseCallbackCalledEPLAYERVALID
    push   edx
    call   edi
    add    esp,0x8
    pop    edi
    pop    esi
    pop    ebx
    ret    0x14
  Branch5:
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextRcvModValidationResponseCallbackCalledEPLAYERINVALID
    push   ecx
    call   edi
    add    esp,0x8
    pop    edi
    pop    esi
    pop    ebx
    ret    0x14
  Branch6:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRcvModValidationResponseCallbackCalledEPLAYERUNKNOWN
    push   eax
    call   edi
    add    esp,0x8
  Branch7:
    pop    edi
  Branch8:
    pop    esi
    pop    ebx
    ret    0x14
  }
}

// Appends a zeroed RS auth-ID string slot, formats and assigns its value, releases temporary, then optionally logs raw string words.
// R6GameService.dll @ 1000ed00 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall OnRSPlayerStatusRequest(void *callbackContext,const uchar *authId)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCDKeyStringTemporary
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   esi
    push   0x1
    push   0xc
    mov    ecx,R6GameServiceAddresses::GServiceString7
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    esi,eax
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    lea    ecx,[esp+0x8]
    push   ecx
    call   R6GameServiceAddresses::FormatAuthenticationIdHex
    add    esp,0x8
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString7
    lea    esi,[esi+esi*2]
    shl    esi,0x2
    push   eax
    lea    ecx,[esi+edx*1]
    mov    DWORD PTR [esp+0x1c],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[esp+0x4]
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch9
    mov    eax,ds:R6GameServiceAddresses::GServiceString7
    add    esi,eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x4]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRcvRSPlayerStatusRequestAuthidS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch9:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x18
    ret    0x8
  }
}

// Appends a zeroed Mod auth-ID string slot, formats and assigns its value, releases temporary, then optionally logs raw string words.
// R6GameService.dll @ 1000edc0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall OnModPlayerStatusRequest(void *callbackContext,const uchar *authId)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCDKeyStringTemporary
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   esi
    push   0x1
    push   0xc
    mov    ecx,R6GameServiceAddresses::GServiceString6
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    esi,eax
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    lea    ecx,[esp+0x8]
    push   ecx
    call   R6GameServiceAddresses::FormatAuthenticationIdHex
    add    esp,0x8
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString6
    lea    esi,[esi+esi*2]
    shl    esi,0x2
    push   eax
    lea    ecx,[esi+edx*1]
    mov    DWORD PTR [esp+0x1c],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[esp+0x4]
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch10
    mov    eax,ds:R6GameServiceAddresses::GServiceString6
    add    esi,eax
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esi+0x4]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCallbackRcvModPlayerStatusRequestAuthidS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch10:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x18
    ret    0x8
  }
}

// Tail-destroys inherited FString at EBP-18; shared by authentication callbacks and CD-key diagnostic parent.
// R6GameService.dll @ 100640c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl cdkey_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects shared one-state CD-key temporary-string map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 100640c9 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectCDKeyStringTemporary(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::cdkey_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d784 : native shared CD-key temporary unwind record.
const R6GameServiceNative::UnwindEntry cdkey_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::cdkey_supportSharedLifetimeUnwind1},
};

// R6GameService.dll data @ 1007d78c : native shared CD-key temporary unwind record.
// R6GameService.dll data @ 1007d784 : native storage identity retained.
const R6GameServiceNative::FuncInfo cdkey_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::cdkey_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Logs current RS/Mod request states with a phase FString, preserving raw three-word varargs, cached logger and live state reloads.
// R6GameService.dll @ 1000d9e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl LogCDKeyRequestDiagnostics(void *requestContext,int phase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCDKeyStringTemporary
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   esi
    push   edi
    lea    ecx,[esp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    mov    DWORD PTR [esp+0x1c],0x0
    lea    ecx,[esp+0x8]
    je     Branch11
    push   R6GameServiceAddresses::WideTextEXITFct
    jmp    Branch12
  Branch11:
    push   R6GameServiceAddresses::WideTextENTERFct
  Branch12:
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    mov    edi,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [edi+0x698]
    test   eax,eax
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch15
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextLogDebugProcessCDKeyRequestForRS
    push   ecx
    call   esi
    mov    eax,DWORD PTR [edi+0x698]
    add    esp,0x8
    dec    eax
    cmp    eax,0x3
    ja     Branch15
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GCDKeyDiagnosticSwitch]
    sub    esp,0xc
    mov    edx,esp
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ4
    jmp    Branch13
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ3
    push   eax
    jmp    Branch14
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0xc]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ2
    push   ecx
    jmp    Branch14
    sub    esp,0xc
    mov    edx,esp
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ
  Branch13:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   edx
  Branch14:
    call   esi
    add    esp,0x14
  Branch15:
    mov    eax,DWORD PTR [edi+0x6b4]
    test   eax,eax
    je     Branch18
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextLogDebugProcessCDKeyRequestForMOD
    push   ecx
    call   esi
    mov    edi,DWORD PTR [edi+0x6b4]
    lea    eax,[edi-0x1]
    add    esp,0x8
    cmp    eax,0x3
    ja     Branch18
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::cdkey_supportGCDKeyDiagnosticSwitch]
    sub    esp,0xc
    mov    edx,esp
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR4
    jmp    Branch16
    mov    ecx,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR3
    push   eax
    jmp    Branch17
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0xc]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR2
    push   ecx
    jmp    Branch17
    sub    esp,0xc
    mov    edx,esp
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR
  Branch16:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   edx
  Branch17:
    call   esi
    add    esp,0x14
  Branch18:
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x1c],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x18
    ret
  }
}

// R6GameService.dll data @ 1000dbdc : native diagnostic four-state branch table.
const uint GCDKeyDiagnosticSwitch[4] = {R6GameServiceAddresses::GCDKeyDiagnosticSwitchCase1,R6GameServiceAddresses::GCDKeyDiagnosticSwitchCase2,R6GameServiceAddresses::GCDKeyDiagnosticSwitchCase3,R6GameServiceAddresses::GCDKeyDiagnosticSwitchCase4};

// R6GameService.dll data @ 1000dbec : native diagnostic four-state branch table.
const uint cdkey_supportGCDKeyDiagnosticSwitch[4] = {R6GameServiceAddresses::cdkey_supportGCDKeyDiagnosticSwitchCase1,R6GameServiceAddresses::cdkey_supportGCDKeyDiagnosticSwitchCase2,R6GameServiceAddresses::cdkey_supportGCDKeyDiagnosticSwitchCase3,R6GameServiceAddresses::cdkey_supportGCDKeyDiagnosticSwitchCase4};
