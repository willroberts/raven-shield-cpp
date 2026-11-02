#include "native_addresses.h"
#include "native_records.h"

// CD-key service callbacks and shared diagnostic string cleanup; concrete callback owner remains unresolved.
// uint callback return views expose raw EAX; original callback return declaration is unavailable.
// Native formatter effects on FS and the delayed assignment-state arm remain unchanged.

// Appends a 32-byte SDK validation record, then logs live record fields through one cached Logf target.
// R6GameService.dll @ 1000ea60 : stdcall/RET20; response names/types and the raw uint return view are inferred.
uint __stdcall RcvValidationResponse(const void *response,uint unusedSecond,uint unusedThird,
    uint status,const uchar *globalId)
{
  FArray *queue = (FArray *)R6GameServiceAddresses::GServiceArray8;
  using AddZeroedABI = int (__thiscall *)(FArray *,int,int);
  uint recordOffset = (uint)(*(AddZeroedABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(queue,0x20,1) << 5;
  uint originalStatus = status;
  *(uint *)(*(byte **)queue + recordOffset) = originalStatus;
  byte *data = *(byte **)queue;
  const byte *header = (const byte *)response;
  uint requestId = *(const uint *)header;
  *(uint *)(data + recordOffset + 4) = requestId;
  uint success = header[4]; // Preserve the entire response byte, not just bit 0.
  *(uint *)(*(byte **)queue + recordOffset + 8) = success;
  data = *(byte **)queue;
  uint timeout = *(const ushort *)(header + 6) == 1;
  *(uint *)(data + recordOffset + 0xc) = timeout;
  uint *destinationId = (uint *)(*(byte **)queue + recordOffset + 0x10);
  const uint *sourceId = (const uint *)globalId;
  destinationId[0] = sourceId[0];
  destinationId[1] = sourceId[1];
  destinationId[2] = sourceId[2];
  destinationId[3] = sourceId[3];
  uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (verbose == 0)
    return verbose;
  uint field = *(uint *)(*(byte **)queue + recordOffset);
  FOutputDevice *device = GLog;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...); // Physical EAX view of void Logf.
  LogABI log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  log(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvValidationResponseEStatusI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 4);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvValidationResponseIReqIDI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 8);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvValidationResponseBSuceededI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 0xc);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvValidationResponseBTimeoutI,field);
  // The terminal diagnostic uses the captured full status, even if a logging callback changed the queued record.
  if (originalStatus == 0)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERUNKNOWN);
  if (originalStatus == 1)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERINVALID);
  if (originalStatus == 2)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextRcvValidationResponseCallbackCalledEPLAYERVALID);
  return originalStatus - 2; // Native EAX residue after the unrecognized-status comparisons.
}

// Appends a 32-byte SDK validation record, then logs live record fields through one cached Logf target.
// R6GameService.dll @ 1000ebb0 : stdcall/RET20; response names/types and the raw uint return view are inferred.
uint __stdcall RcvModValidationResponse(const void *response,uint unusedSecond,uint unusedThird,
    uint status,const uchar *globalId)
{
  FArray *queue = (FArray *)R6GameServiceAddresses::GServiceArray7;
  using AddZeroedABI = int (__thiscall *)(FArray *,int,int);
  uint recordOffset = (uint)(*(AddZeroedABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(queue,0x20,1) << 5;
  uint originalStatus = status;
  *(uint *)(*(byte **)queue + recordOffset) = originalStatus;
  byte *data = *(byte **)queue;
  const byte *header = (const byte *)response;
  uint requestId = *(const uint *)header;
  *(uint *)(data + recordOffset + 4) = requestId;
  uint success = header[4]; // Preserve the entire response byte, not just bit 0.
  *(uint *)(*(byte **)queue + recordOffset + 8) = success;
  data = *(byte **)queue;
  uint timeout = *(const ushort *)(header + 6) == 1;
  *(uint *)(data + recordOffset + 0xc) = timeout;
  uint *destinationId = (uint *)(*(byte **)queue + recordOffset + 0x10);
  const uint *sourceId = (const uint *)globalId;
  destinationId[0] = sourceId[0];
  destinationId[1] = sourceId[1];
  destinationId[2] = sourceId[2];
  destinationId[3] = sourceId[3];
  uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (verbose == 0)
    return verbose;
  uint field = *(uint *)(*(byte **)queue + recordOffset);
  FOutputDevice *device = GLog;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...); // Physical EAX view of void Logf.
  LogABI log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  log(device,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseEStatusI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 4);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseIReqIDI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 8);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseBSuceededI,field);
  field = *(uint *)(*(byte **)queue + recordOffset + 0xc);
  log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvModValidationResponseBTimeoutI,field);
  // The terminal diagnostic uses the captured full status, even if a logging callback changed the queued record.
  if (originalStatus == 0)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::
        WideTextRcvModValidationResponseCallbackCalledEPLAYERUNKNOWN);
  if (originalStatus == 1)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::
        WideTextRcvModValidationResponseCallbackCalledEPLAYERINVALID);
  if (originalStatus == 2)
    return log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextRcvModValidationResponseCallbackCalledEPLAYERVALID);
  return originalStatus - 2; // Native EAX residue after the unrecognized-status comparisons.
}

// Reconstruction-only scope owner: native callbacks arm string cleanup after loading the queue destination.
// This helper has no distinct native class/body identity.
struct CDKeyCallbackStringScope {
  FString *value;
  // Destroys the completed temporary during normal scope exit or assignment unwinding.
  ~CDKeyCallbackStringScope() noexcept(false) { value->~FString(); }
};

// Appends a RS auth-ID slot, formats and assigns the ID, destroys the temporary, then optionally logs borrowed words.
// R6GameService.dll @ 1000ed00 : stdcall/RET8; callbackContext is unused, and failed formatting leaves the zeroed slot.
uint __stdcall OnRSPlayerStatusRequest(void *callbackContext,const uchar *authId)
{
  FArray *queue = (FArray *)R6GameServiceAddresses::GServiceString7;
  using AddZeroedABI = int (__thiscall *)(FArray *,int,int);
  uint index = (uint)(*(AddZeroedABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(queue,0xc,1);
  uint temporaryWords[3];
  FString *temporary = (FString *)temporaryWords;
  FString *formatted = FormatAuthenticationIdHex(temporary,authId);
  byte *data = *(byte **)queue;
  uint recordOffset = index * 12;
  FString *destination = (FString *)(data + recordOffset);
  {
    // A fault before this point has no native temporary cleanup action; the formatter remains a separate ABI boundary.
    CDKeyCallbackStringScope lifetime = {temporary};
    *destination = *formatted;
  }
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    const uint *recordWords = (const uint *)(*(byte **)queue + recordOffset);
    uint dataWord = recordWords[0];
    uint countWord = recordWords[1];
    uint capacityWord = recordWords[2];
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvRSPlayerStatusRequestAuthidS,
         dataWord,countWord,capacityWord);
  }
  return rawEax;
}

// Appends a Mod auth-ID slot, formats and assigns the ID, destroys the temporary, then optionally logs borrowed words.
// R6GameService.dll @ 1000edc0 : stdcall/RET8; callbackContext is unused, and failed formatting leaves the zeroed slot.
uint __stdcall OnModPlayerStatusRequest(void *callbackContext,const uchar *authId)
{
  FArray *queue = (FArray *)R6GameServiceAddresses::GServiceString6;
  using AddZeroedABI = int (__thiscall *)(FArray *,int,int);
  uint index = (uint)(*(AddZeroedABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(queue,0xc,1);
  uint temporaryWords[3];
  FString *temporary = (FString *)temporaryWords;
  FString *formatted = FormatAuthenticationIdHex(temporary,authId);
  byte *data = *(byte **)queue;
  uint recordOffset = index * 12;
  FString *destination = (FString *)(data + recordOffset);
  {
    // A fault before this point has no native temporary cleanup action; the formatter remains a separate ABI boundary.
    CDKeyCallbackStringScope lifetime = {temporary};
    *destination = *formatted;
  }
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    const uint *recordWords = (const uint *)(*(byte **)queue + recordOffset);
    uint dataWord = recordWords[0];
    uint countWord = recordWords[1];
    uint capacityWord = recordWords[2];
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextCallbackRcvModPlayerStatusRequestAuthidS,
         dataWord,countWord,capacityWord);
  }
  return rawEax;
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
// R6GameService.dll @ 1000d9e0 : cdecl; raw FString words are varargs, not an owned by-value copy.
__declspec(naked) uint __cdecl LogCDKeyRequestDiagnostics(void *requestContext,int phase)
{
  byte *nativeStack;
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
    mov    nativeStack,esp
  }
  FString *temporary = (FString *)(nativeStack + 8);
  using DefaultABI = FString * (__thiscall *)(FString *);
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(temporary);
  uint currentPhase = *(uint *)(nativeStack + 0x28);
  *(uint *)(nativeStack + 0x1c) = 0;
  const TCHAR *phaseText = (const TCHAR *)(currentPhase == 0 ? R6GameServiceAddresses::WideTextENTERFct :
      R6GameServiceAddresses::WideTextEXITFct);
  using AssignABI = FString& (__thiscall *)(FString *,const TCHAR *);
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot2)(temporary,phaseText);
  byte *context = *(byte **)(nativeStack + 0x24);
  uint rs = *(uint *)(context + 0x698);
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  if (rs != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextLogDebugProcessCDKeyRequestForRS);
    rs = *(uint *)(context + 0x698);
    const TCHAR *diagnostic = nullptr;
    switch (rs) {
    case 1: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ4; break;
    case 2: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ3; break;
    case 3: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ2; break;
    case 4: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ; break;
    }
    if (diagnostic != nullptr) {
      uint data = *(uint *)(nativeStack + 8);
      uint count = *(uint *)(nativeStack + 0xc);
      uint capacity = *(uint *)(nativeStack + 0x10);
      device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      logger(device,diagnostic,data,count,capacity);
    }
  }
  uint mod = *(uint *)(context + 0x6b4);
  if (mod != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextLogDebugProcessCDKeyRequestForMOD);
    mod = *(uint *)(context + 0x6b4);
    const TCHAR *diagnostic = nullptr;
    switch (mod) {
    case 1: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR4; break;
    case 2: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR3; break;
    case 3: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR2; break;
    case 4: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR; break;
    }
    if (diagnostic != nullptr) {
      uint data = *(uint *)(nativeStack + 8);
      uint count = *(uint *)(nativeStack + 0xc);
      uint capacity = *(uint *)(nativeStack + 0x10);
      device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      logger(device,diagnostic,data,count,capacity);
    }
  }
  *(uint *)(nativeStack + 0x1c) = 0xffffffff;
  using DestroyABI = uint (__thiscall *)(FString *);
  uint rawEax = (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(temporary);
  __asm {
    mov    eax,rawEax
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
