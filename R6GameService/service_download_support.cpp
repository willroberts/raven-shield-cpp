#include "native_addresses.h"
#include "native_records.h"

// Service-download callback/adapters and global wrapper-registry release; original free identifiers are unavailable.

// Publishes whether callback status word two is zero, then optionally logs selected callback words/low byte.
// R6GameService.dll @ 100065c0 : complete native control/access order and raw ABI retained.
void __stdcall ReportServiceDownload(
    uint word0,uint status,uint word2,uint word3,uint byteWord,uint word5)
{
  const uint savedStatus = status;
  *reinterpret_cast<int*>(0x10091be8) = savedStatus == 0;
  if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
    FOutputDevice* firstLogger = GLog;
    using LogCall = void (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
    LogCall log = *reinterpret_cast<LogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    const TCHAR* wordFormat = reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackHttpCompletedI);
    log(firstLogger, wordFormat, word0);
    log(GLog, wordFormat, savedStatus);
    log(GLog, wordFormat, word3);
    log(GLog, wordFormat, static_cast<byte>(byteWord));
    log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCallbackHttpCompleted));
  }
}

// Tail-forwards the no-argument allocation/registration call and its raw wrapper return.
// R6GameService.dll @ 10014ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl TailForwardServiceWrapperRegistration(void)
{
  __asm {
    jmp    R6GameServiceAddresses::CreateRegisteredServiceWrapper
  }
}

// Removes a nonnull wrapper registration, or unconditionally releases the global registry for a zero word.
// R6GameService.dll @ 10014af0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall ReleaseRegisteredServiceWrapper(uint wrapperWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je     Branch2
    mov    DWORD PTR [esp+0x4],eax
    jmp    R6GameServiceAddresses::RemoveServiceWrapperRegistration
  Branch2:
    call   R6GameServiceAddresses::ReleaseServiceWrapperRegistry
    ret    0x4
  }
}

// Returns zero for a null wrapper; otherwise tail-forwards all six untouched request words.
// R6GameService.dll @ 10014b10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall QueueServiceDownload(
    void *wrapper,const char *remotePath,const char *localPath,uint optionWord,uint callback,uint callbackWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    jne    Branch3
    ret    0x18
  Branch3:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x4],eax
    mov    DWORD PTR [esp+0x10],ecx
    jmp    R6GameServiceAddresses::DispatchServiceDownload
  }
}

// Removes one registration, then inspects the current registry and deletes/clears it if its current count is zero.
// The reloaded registry count is read before its later null test; a callback-cleared pointer is not repaired.
// R6GameService.dll @ 10014c70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall RemoveServiceWrapperRegistration(uint wrapperWord)
{
  __asm {
    mov    ecx,DWORD PTR ds:0x10093b6c
    test   ecx,ecx
    je     Branch5
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x8]
    mov    ecx,DWORD PTR ds:0x10093b6c
    mov    eax,DWORD PTR [ecx+0x8]
    test   eax,eax
    jne    Branch5
    test   ecx,ecx
    je     Branch4
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch4:
    mov    DWORD PTR ds:0x10093b6c,0x0
  Branch5:
    ret    0x4
  }
}

// Deletes the current nonnull registry with flag1, then clears the global even if the deletion callback replaced it.
// R6GameService.dll @ 10014cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseServiceWrapperRegistry(void)
{
  __asm {
    mov    ecx,DWORD PTR ds:0x10093b6c
    test   ecx,ecx
    je     Branch6
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR ds:0x10093b6c,0x0
  Branch6:
    ret
  }
}

// Returns zero for a null wrapper, else calls its request method with five unchanged words and returns full EAX.
// R6GameService.dll @ 10014cd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchServiceDownload(
    void *wrapper,const char *remotePath,const char *localPath,uint optionWord,uint callback,uint callbackWord)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    jne    Branch7
    xor    eax,eax
    ret    0x18
  Branch7:
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    push   eax
    mov    eax,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   eax
    mov    eax,DWORD PTR [esp+0x14]
    push   edx
    push   eax
    call   R6GameServiceAddresses::QueueHttpRequest
    ret    0x18
  }
}

// R6GameService.dll data @ 1007e820 : native HTTP lifetime records.
const R6GameServiceNative::UnwindEntry CreateRegisteredServiceWrapperUnwindMap[5] = {
  {-1, R6GameServiceAddresses::CreateRegisteredServiceWrapperUnwind1},
  {-1, R6GameServiceAddresses::CreateRegisteredServiceWrapperUnwind2},
  {0x1, R6GameServiceAddresses::CreateRegisteredServiceWrapperUnwind3},
  {0x2, 0x0},
  {0x3, R6GameServiceAddresses::CreateRegisteredServiceWrapperUnwind5},
};
// R6GameService.dll data @ 1007e848 : native HTTP lifetime records.
const R6GameServiceNative::FuncInfo CreateRegisteredServiceWrapperExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::CreateRegisteredServiceWrapperUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Allocates a CHttpDownload, lazily constructs its pointer registry, then inserts an unsigned wrapper-key pair.
// R6GameService.dll @ 10014b30 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl CreateRegisteredServiceWrapper(void)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CreateRegisteredServiceWrapperSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   edi
    xor    edi,edi
    push   0x1c
    mov    DWORD PTR [esp+0x14],edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,edi
    mov    DWORD PTR [esp+0x28],edi
    je     Branch8
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructCHttpDownload
    mov    ebp,eax
    jmp    Branch9
  Branch8:
    xor    ebp,ebp
  Branch9:
    or     ebx,0xffffffff
    cmp    ebp,edi
    mov    DWORD PTR [esp+0x28],ebx
    jne    Branch10
    pop    edi
    pop    ebp
    xor    eax,eax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret
  Branch10:
    mov    eax,ds:0x10093b6c
    push   esi
    cmp    eax,edi
    jne    Branch13
    push   0x14
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x1c],esi
    cmp    esi,edi
    je     Branch11
    mov    DWORD PTR [esi+0x10],0x10075bb0
    mov    DWORD PTR [esp+0x14],0x1
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [esp+0x20],ecx
    lea    eax,[esp+0x12]
    lea    edx,[esp+0x13]
    push   eax
    push   edx
    mov    DWORD PTR [esp+0x34],0x4
    call   R6GameServiceAddresses::InitializeTreeSentinel
    mov    DWORD PTR [esi],R6GameServiceAddresses::clPointerMap_PAXPAVCHttpDownloadVTable
    jmp    Branch12
  Branch11:
    xor    esi,esi
  Branch12:
    mov    eax,esi
    mov    DWORD PTR [esp+0x2c],ebx
    mov    ds:0x10093b6c,eax
  Branch13:
    lea    ebx,[eax+0x4]
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x18],ebp
    mov    cl,0x1
    mov    edx,DWORD PTR [ebx]
    mov    edi,edx
    mov    esi,DWORD PTR [edx+0x4]
    test   esi,esi
    je     Branch17
  Branch14:
    mov    ecx,DWORD PTR [esi+0x10]
    mov    edi,esi
    cmp    ebp,ecx
    setb   cl
    test   cl,cl
    je     Branch15
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch16
  Branch15:
    mov    esi,DWORD PTR [esi+0xc]
  Branch16:
    test   esi,esi
    jne    Branch14
  Branch17:
    test   cl,cl
    mov    eax,edi
    je     Branch19
    cmp    edi,DWORD PTR [edx+0x8]
    jne    Branch18
    lea    ecx,[esp+0x20]
    jmp    Branch20
  Branch18:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
  Branch19:
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [eax+0x10]
    cmp    ecx,edx
    jae    Branch21
    lea    ecx,[esp+0x1c]
  Branch20:
    lea    eax,[esp+0x14]
    push   0x0
    push   eax
    push   edi
    push   esi
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
  Branch21:
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    mov    eax,ebp
    pop    edi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret
  }
}

// Tail-forwards the memory word through the selected allocator release entry, retaining RET4 and raw return.
// R6GameService.dll @ 10014d00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall ForwardToAllocatorTail(void *memory)
{
  __asm {
    jmp    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  }
}

// Frees the unfinished download saved at virtual frame-0x1c.
// R6GameService.dll @ 10064580 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreateRegisteredServiceWrapperUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Frees the unfinished registry allocation saved at virtual frame-0x14.
// R6GameService.dll @ 1006458a : complete native control/access order and raw ABI retained.
__declspec(naked) void CreateRegisteredServiceWrapperUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// When saved flag bit0 is set, tail-calls the empty allocator-base destructor at saved registry+0x14.
// R6GameService.dll @ 10064594 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreateRegisteredServiceWrapperUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    test   eax,eax
    je     Branch22
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch22:
    ret
  }
}

// Tail-calls the empty allocator cleanup with inherited virtual frame-0x1e.
// R6GameService.dll @ 100645ae : complete native control/access order and raw ABI retained.
__declspec(naked) void CreateRegisteredServiceWrapperUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x1e]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the five-state download/registry construction map.
// R6GameService.dll @ 100645b6 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreateRegisteredServiceWrapperSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CreateRegisteredServiceWrapperExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
