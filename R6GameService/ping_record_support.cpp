#include "native_addresses.h"
#include "native_records.h"

// Unassigned 0x12c-byte ping record lifetime/range helpers; original class/template names are unavailable.

// R6GameService.dll data @ 1007e648 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry DestroyPingRecordUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyPingRecordUnwind1},
};
// R6GameService.dll data @ 1007e650 : selected guard/cleanup records.
const R6GameServiceNative::FuncInfo DestroyPingRecordExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyPingRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroys record strings at+0x10c then+0; socket ownership and original record class remain unassigned.
// R6GameService.dll @ 10014050 : ECX record; saved record remains live for the private unwind action.
__declspec(naked) void __fastcall DestroyPingRecord(void *record)
{
  byte *nativeFrame;
  void *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyPingRecordSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame + 0x10) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)((byte *)receiver + 0x10c));
  *(uint *)(nativeFrame + 0x10) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)receiver);
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys the first string through the current record saved at parent EBP-0x10.
// R6GameService.dll @ 100644c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyPingRecordUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the record destructor map protecting the first string during second-string destruction.
// R6GameService.dll @ 100644c9 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyPingRecordSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyPingRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Checks a signed wrapped range, destroys records through live Data, then forwards late count to FArray::Remove.
// R6GameService.dll @ 100143a0 : ECX array/RET8; cached range and live Data/count match the native template body.
void __thiscall RemovePingRecordRange(FArray *records,int firstIndex,int count)
{
  int first = firstIndex;
  using AssertABI = void (__cdecl *)(const char *,const char *,int);
  AssertABI assertion = *(AssertABI *)R6GameServiceAddresses::Core__appFailAssertSlot;
  if (first < 0)
    assertion((const char *)R6GameServiceAddresses::TextIndex0,
        (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x201);
  if (first > *(int *)((byte *)records + 4))
    assertion((const char *)R6GameServiceAddresses::TextIndexArrayNum,
        (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x202);
  uint end = (uint)first + (uint)count;
  if ((int)end > *(int *)((byte *)records + 4))
    assertion((const char *)R6GameServiceAddresses::TextIndexCountArrayNum,
        (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x203);
  if (first < (int)end) {
    uint offset = (uint)first * 300;
    uint remaining = end - (uint)first;
    do {
      DestroyPingRecord((void *)((uint)*(byte **)records + offset));
      offset += 300;
    } while (--remaining != 0);
  }
  using RemoveABI = void (__thiscall *)(void *,int,int,int);
  (*(RemoveABI *)R6GameServiceAddresses::Core_FArray_RemoveSlot)(records,first,count,300);
}

// R6GameService.dll data @ 1007e794 : native exception records.
const R6GameServiceNative::UnwindEntry DestroyPingRequestArrayUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyPingRequestArrayUnwind1},
};
// R6GameService.dll data @ 1007e79c : native exception records.
const R6GameServiceNative::FuncInfo DestroyPingRequestArrayExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyPingRequestArrayUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007e7b8 : native exception records.
const R6GameServiceNative::UnwindEntry InitializePingRequestArrayUnwindMap[3] = {
  {-1, R6GameServiceAddresses::InitializePingRequestArrayUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007e7d0 : native exception records.
const R6GameServiceNative::FuncInfo InitializePingRequestArrayExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::InitializePingRequestArrayUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007e7ec : native exception records.
const R6GameServiceNative::UnwindEntry CleanupWinsockAndPingRequestsUnwindMap[3] = {
  {-1, R6GameServiceAddresses::CleanupWinsockAndPingRequestsUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007e804 : native exception records.
const R6GameServiceNative::FuncInfo CleanupWinsockAndPingRequestsExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::CleanupWinsockAndPingRequestsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Removes the current record range then destroys backing storage, protecting storage while record cleanup runs.
// R6GameService.dll @ 100148a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyPingRequestArray(FArray *requests)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyPingRequestArraySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemovePingRecordRange
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys backing FArray storage through parent EBP-0x10.
// R6GameService.dll @ 10064520 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyPingRequestArrayUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
  }
}

// Selects the one-state array destructor map protecting storage while records are destroyed.
// R6GameService.dll @ 10064529 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyPingRequestArraySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyPingRequestArrayExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Zeros the array header and requests Winsock 1.2, ignoring its status; the native frame stays unarmed.
// R6GameService.dll @ 100148f0 : complete native control/access order and raw ABI retained.
__declspec(naked) FArray *__fastcall InitializePingRequestArray(FArray *requests)
{
  __asm {
    mov    eax,fs:0x0
    push   0xffffffff
    push   R6GameServiceAddresses::InitializePingRequestArraySelectExceptionInfo
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x198
    xor    eax,eax
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    lea    eax,[esp+0x8]
    push   eax
    push   0x102
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAStartupSlot
    mov    ecx,DWORD PTR [esp+0x19c]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1a4
    ret
  }
}

// Tail-destroys the array pointer in inherited EBP-0x1a4; ordinary initializer never arms this action.
// R6GameService.dll @ 10064540 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializePingRequestArrayUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1a4]
    jmp    R6GameServiceAddresses::DestroyPingRequestArray
  }
}

// Selects the initializer map, whose ordinary entry retains state -1 throughout.
// R6GameService.dll @ 1006454b : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializePingRequestArraySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializePingRequestArrayExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Calls Winsock cleanup before actual array destruction; failures do not arm the outer saved-pointer action.
// R6GameService.dll @ 10014940 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall CleanupWinsockAndPingRequests(FArray *requests)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CleanupWinsockAndPingRequestsSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   esi
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSACleanupSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x14],0xffffffff
    call   R6GameServiceAddresses::DestroyPingRequestArray
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Tail-destroys the saved pointer at inherited EBP-0x14; ordinary cleanup never arms this action.
// R6GameService.dll @ 10064560 : complete native control/access order and raw ABI retained.
__declspec(naked) void CleanupWinsockAndPingRequestsUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyPingRequestArray
  }
}

// Selects the cleanup map, with no ordinary state transition arming its saved-pointer action.
// R6GameService.dll @ 10064568 : complete native control/access order and raw ABI retained.
__declspec(naked) void CleanupWinsockAndPingRequestsSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CleanupWinsockAndPingRequestsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
