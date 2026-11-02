#include "native_addresses.h"
#include "native_records.h"

// Native CHttpRequest: primary75bcc/COL7852c/type8c3f0. Layout/member names remain offset-based.

// Initializes a request, its string-record range and TCP child, then copies URL, output path and optional headers.
// The native eight-state guard, incoming argument scratch and dead self-subtraction branch remain explicit.
// Completed TCP child has no later-constructor guard; argument fields reload after allocation/copy callbacks.
// R6GameService.dll @ 100154d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeHttpRequestRecord(
    void *owner,uint kind,uint optionWord,char *url,uint eventCallback,uint dataCallback,uint context,
    char *headers,char *fileName,uint buffer,uint bufferLimit,uint installVirtualBase)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::InitializeHttpRequestRecordSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   ebp
    xor    ebp,ebp
    push   esi
    mov    DWORD PTR [esp+0xc],ebp
    mov    eax,DWORD PTR [esp+0x50]
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [esp+0x14],esi
    je     Branch1
    mov    DWORD PTR [esi+0x4],0x10075be0
    mov    ebp,0x1
  Branch1:
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    lea    eax,[esi+0x198]
    or     ebp,0x4
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [eax+0xc],0x10075bd0
    lea    ecx,[esp+0x54]
    push   ebx
    push   ecx
    lea    ecx,[eax+0x8]
    mov    DWORD PTR [esp+0x2c],0x3
    mov    DWORD PTR [eax],ebx
    mov    DWORD PTR [eax+0x4],ebx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    DWORD PTR [esp+0x24],0x1
    push   0x54
    mov    DWORD PTR [esi],R6GameServiceAddresses::CHttpRequestVTable
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x18],edi
    cmp    edi,ebx
    je     Branch2
    or     ebp,0x8
    mov    DWORD PTR [edi+0x4],0x10075bc0
    mov    DWORD PTR [esp+0x10],ebp
    push   ebx
    mov    ecx,edi
    mov    BYTE PTR [esp+0x28],0x6
    call   R6GameServiceAddresses::ConstructQueuedConnection
    mov    DWORD PTR [edi],R6GameServiceAddresses::clTCPClientVTable
    mov    DWORD PTR [esp+0x24],0x5
    jmp    Branch3
  Branch2:
    xor    edi,edi
  Branch3:
    mov    DWORD PTR [esi+0x8],edi
    lea    edi,[esi+0x5c6]
    mov    ecx,0x100
    xor    eax,eax
    rep    stos DWORD PTR es:[edi],eax
    lea    ebp,[esi+0x9c6]
    mov    ecx,0x20
    mov    edi,ebp
    lea    edx,[esi+0x1c5]
    rep    stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    mov    ecx,0x100
    xor    eax,eax
    mov    edi,edx
    push   0x400
    rep    stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [esp+0x38]
    mov    BYTE PTR [esp+0x28],0x4
    push   eax
    push   edx
    call   R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0x54]
    add    esp,0xc
    cmp    eax,ebx
    je     Branch4
    push   0x80
    push   eax
    push   ebp
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
  Branch4:
    mov    eax,DWORD PTR [esp+0x44]
    cmp    eax,ebx
    je     Branch5
    push   0x3ff
    push   eax
    lea    eax,[esi+0x5c6]
    push   eax
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
  Branch5:
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    dl,BYTE PTR [esp+0x30]
    mov    eax,DWORD PTR [esp+0x3c]
    mov    DWORD PTR [esi+0x1b0],ecx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    BYTE PTR [esi+0x1c4],dl
    mov    edx,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esi+0x1b4],ebx
    mov    DWORD PTR [esi+0x1b8],eax
    mov    DWORD PTR [esi+0x1bc],ecx
    mov    DWORD PTR [esi+0x1c0],edx
    mov    eax,DWORD PTR [esi+0x19c]
    mov    ecx,eax
    mov    edi,eax
    sub    ecx,eax
    mov    eax,0x2aaaaaab
    imul   ecx
    sar    edx,1
    mov    ebp,DWORD PTR [esi+0x198]
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    cmp    edx,ebx
    jle    Branch8
    mov    DWORD PTR [esp+0x34],edx
  Branch6:
    cmp    edi,ebp
    je     Branch7
    mov    eax,DWORD PTR [edi+0x4]
    mov    ecx,DWORD PTR [edi]
    lea    edx,[esp+0x30]
    push   edx
    push   eax
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AppendByteRange
  Branch7:
    mov    eax,DWORD PTR [esp+0x34]
    add    edi,0xc
    add    ebp,0xc
    dec    eax
    mov    DWORD PTR [esp+0x34],eax
    jne    Branch6
  Branch8:
    mov    eax,DWORD PTR [esi+0x19c]
    mov    edi,ebp
    cmp    ebp,eax
    mov    DWORD PTR [esp+0x34],eax
    mov    DWORD PTR [esp+0x30],edi
    je     Branch10
  Branch9:
    mov    eax,DWORD PTR [edi+0x4]
    mov    ecx,DWORD PTR [edi]
    inc    eax
    mov    BYTE PTR [esp+0x24],0x7
    push   eax
    push   ecx
    call   R6GameServiceAddresses::NoOp
    mov    ecx,edi
    mov    BYTE PTR [esp+0x24],0x4
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    eax,DWORD PTR [esp+0x34]
    add    edi,0xc
    cmp    edi,eax
    mov    DWORD PTR [esp+0x30],edi
    jne    Branch9
  Branch10:
    mov    edx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [esi+0x19c],ebp
    mov    ecx,0x61
    xor    eax,eax
    lea    edi,[esi+0xc]
    mov    DWORD PTR [esi+0xa48],0xffffffff
    mov    DWORD PTR [esi+0xa4c],ebx
    mov    DWORD PTR [esi+0xa50],ebx
    mov    DWORD PTR [esi+0xa54],ebx
    rep    stos DWORD PTR es:[edi],eax
    mov    eax,DWORD PTR [esp+0x50]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0xa68],eax
    mov    BYTE PTR [esi+0x194],bl
    mov    BYTE PTR [esi+0xa47],bl
    mov    BYTE PTR [esi+0xa70],bl
    mov    DWORD PTR [esi+0xa60],edx
    mov    DWORD PTR [esi+0xa64],ebx
    mov    DWORD PTR [esi+0xa74],ebx
    mov    DWORD PTR [esi+0xa78],ebx
    mov    DWORD PTR [esi+0xa7c],ebx
    mov    DWORD PTR [esi+0xa80],ebx
    mov    DWORD PTR [esi+0x1a8],ebx
    mov    DWORD PTR [esi+0x1ac],ebx
    mov    DWORD PTR [esi+0xa58],ebx
    mov    DWORD PTR [esi+0xa5c],ebx
    mov    DWORD PTR [esi+0xa6c],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x2c
  }
}

// Destroys CHttpRequest, then reloads the low deletion flag before optionally freeing and returning its owner.
// R6GameService.dll @ 10015790 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyRecordAndOptionallyFree(void *owner,uint deletionFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyServiceObjectMembers
    test   BYTE PTR [esp+0x8],0x1
    je     Branch11
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch11:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Closes file/connection, releases selected buffers and TCP child, then destroys the string-record range.
// Optional resource loads remain late; record bounds cache before iteration, while final range begin reloads.
// State1 guards range then base; state2 guards range storage then base. Fields remain dangling on release.
// R6GameService.dll @ 10015840 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceObjectMembers(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyServiceObjectMembersSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::CHttpRequestVTable
    mov    DWORD PTR [esp+0x20],0x1
    call   R6GameServiceAddresses::CHttpRequestCloseOutput
    mov    ecx,esi
    call   R6GameServiceAddresses::CHttpRequestCloseTcp
    mov    eax,DWORD PTR [esi+0xa74]
    test   eax,eax
    je     Branch12
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch12:
    mov    eax,DWORD PTR [esi+0xa7c]
    test   eax,eax
    je     Branch13
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch13:
    mov    al,BYTE PTR [esi+0xa70]
    test   al,al
    je     Branch14
    mov    eax,DWORD PTR [esi+0xa60]
    test   eax,eax
    je     Branch14
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch14:
    mov    eax,DWORD PTR [esi+0x1a8]
    test   eax,eax
    je     Branch15
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch15:
    mov    eax,DWORD PTR [esi+0xa50]
    test   eax,eax
    je     Branch16
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch16:
    mov    ecx,DWORD PTR [esi+0x8]
    test   ecx,ecx
    je     Branch17
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch17:
    mov    eax,DWORD PTR [esi+0xa58]
    test   eax,eax
    je     Branch18
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch18:
    lea    ebp,[esi+0x198]
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebx,DWORD PTR [ebp+0x4]
    mov    edi,DWORD PTR [ebp+0x0]
    cmp    edi,ebx
    mov    BYTE PTR [esp+0x20],0x2
    je     Branch20
  Branch19:
    mov    ecx,edi
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    add    edi,0xc
    cmp    edi,ebx
    jne    Branch19
  Branch20:
    mov    ebp,DWORD PTR [ebp+0x0]
    test   ebp,ebp
    je     Branch21
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch21:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Returns AL1 for an active connection, otherwise connects using the cached child, host and partial-register port.
// Native AX port load preserves the incoming upper EAX word; the returned AL is stored without normalization.
// R6GameService.dll @ 10015940 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestOpenTcp(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0xa47]
    test   al,al
    je     Branch22
    mov    al,0x1
    pop    esi
    ret
  Branch22:
    mov    ax,WORD PTR [esi+0x18e]
    lea    ecx,[esi+0xc]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::ConnectResolvedQueuedConnection
    mov    BYTE PTR [esi+0xa47],al
    pop    esi
    ret
  }
}

// Closes a flagged TCP connection, clears its flag after success, and returns AL1 with native upper EAX.
// R6GameService.dll @ 10015970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestCloseTcp(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0xa47]
    test   al,al
    je     Branch23
    mov    ecx,DWORD PTR [esi+0x8]
    call   R6GameServiceAddresses::CloseConnectionAndClearSendQueue
    mov    BYTE PTR [esi+0xa47],0x0
  Branch23:
    mov    al,0x1
    pop    esi
    ret
  }
}

// Appends a positive header read through unchecked realloc, then scans for any four consecutive CR/LF bytes.
// Cached total and late append offset can differ after allocation; zero/error reads never rescan existing bytes.
// R6GameService.dll @ 10015990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestAccumulateHeader(void *owner)
{
  __asm {
    sub    esp,0x400
    lea    eax,[esp+0x0]
    push   ebx
    push   ebp
    mov    ebx,ecx
    push   esi
    push   0x400
    push   eax
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    DWORD PTR [ebx+0xa80],0x0
    call   R6GameServiceAddresses::ReceiveConnectionBytes
    mov    esi,eax
    test   esi,esi
    jle    Branch29
    mov    ebp,DWORD PTR [ebx+0xa5c]
    mov    ecx,DWORD PTR [ebx+0xa58]
    add    ebp,esi
    push   edi
    push   ebp
    push   ecx
    call   R6GameServiceAddresses::ResizeGameServiceBytes
    mov    edi,DWORD PTR [ebx+0xa5c]
    mov    ecx,esi
    mov    edx,ecx
    lea    esi,[esp+0x10]
    add    edi,eax
    mov    DWORD PTR [ebx+0xa58],eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    cmp    ebp,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    DWORD PTR [ebx+0xa5c],ebp
    mov    DWORD PTR [ebx+0xa6c],ebp
    pop    edi
    jbe    Branch29
    mov    ebx,DWORD PTR [ebx+0xa58]
    mov    ecx,0x3
    add    ebx,0x2
  Branch24:
    mov    al,BYTE PTR [ebx-0x2]
    cmp    al,0xd
    je     Branch25
    cmp    al,0xa
    jne    Branch28
  Branch25:
    mov    al,BYTE PTR [ebx-0x1]
    cmp    al,0xd
    je     Branch26
    cmp    al,0xa
    jne    Branch28
  Branch26:
    mov    al,BYTE PTR [ebx]
    cmp    al,0xd
    je     Branch27
    cmp    al,0xa
    jne    Branch28
  Branch27:
    mov    al,BYTE PTR [ebx+0x1]
    cmp    al,0xd
    je     Branch30
    cmp    al,0xa
    je     Branch30
  Branch28:
    inc    ebx
    inc    ecx
    cmp    ecx,ebp
    jb     Branch24
  Branch29:
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0x400
    ret
  Branch30:
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0x400
    ret
  }
}

// Receives body bytes, optionally copies a capacity-limited prefix, then publishes a full received chunk.
// Zero read returns AL1; negative read or full destination returns AL0. The chunk and accepted counters may differ.
// Old chunk is freed before unchecked allocation; current receive-buffer/counter slots reload at native points.
// R6GameService.dll @ 10015a70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestAcceptBodyChunk(void *owner)
{
  __asm {
    push   ebx
    mov    ebx,ecx
    push   ebp
    push   esi
    mov    eax,DWORD PTR [ebx+0xa78]
    mov    ecx,DWORD PTR [ebx+0xa74]
    push   edi
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    DWORD PTR [ebx+0xa80],0x0
    call   R6GameServiceAddresses::ReceiveConnectionBytes
    mov    ebp,eax
    test   ebp,ebp
    jne    Branch31
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    ret
  Branch31:
    jle    Branch36
    mov    edi,DWORD PTR [ebx+0xa60]
    test   edi,edi
    je     Branch33
    mov    eax,DWORD PTR [ebx+0xa68]
    mov    edx,DWORD PTR [ebx+0xa6c]
    cmp    eax,edx
    jbe    Branch36
    sub    eax,edx
    cmp    eax,ebp
    jb     Branch32
    mov    eax,ebp
  Branch32:
    mov    esi,DWORD PTR [ebx+0xa74]
    mov    ecx,eax
    add    edi,edx
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edx,DWORD PTR [ebx+0xa6c]
    mov    ecx,DWORD PTR [ebx+0xa64]
    add    edx,eax
    add    ecx,eax
    mov    DWORD PTR [ebx+0xa6c],edx
    mov    DWORD PTR [ebx+0xa64],ecx
    jmp    Branch34
  Branch33:
    add    DWORD PTR [ebx+0xa64],ebp
  Branch34:
    mov    eax,DWORD PTR [ebx+0xa7c]
    test   eax,eax
    je     Branch35
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch35:
    push   ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,DWORD PTR [ebx+0xa74]
    mov    ecx,ebp
    mov    DWORD PTR [ebx+0xa7c],eax
    mov    edi,eax
    mov    eax,ecx
    mov    DWORD PTR [ebx+0xa80],ebp
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    mov    al,0x1
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret
  Branch36:
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    ret
  }
}

// Uppercases/appends header lines, extracts retained status/length, and allocates header, chunk and receive storage.
// Every line ending skips two bytes; the scan has inclusive/end lookahead and no local line-length guard.
// New owned body storage copies the entire current chunk; caller storage clips to capacity.
// The fifteen-state lifetime map, raw partial returns, late fields and native stale/leaked buffers remain explicit.
// R6GameService.dll @ 10015b60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestParseHeader(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CHttpRequestParseHeaderSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x458
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    ebp,ecx
    mov    ecx,0x100
    xor    eax,eax
    lea    edi,[esp+0x68]
    xor    esi,esi
    xor    ebx,ebx
    rep    stos DWORD PTR es:[edi],eax
    mov    DWORD PTR [esp+0x24],esi
  Branch37:
    mov    eax,DWORD PTR [ebp+0xa58]
    add    eax,ebx
    mov    cl,BYTE PTR [eax]
    cmp    cl,0xd
    je     Branch38
    cmp    cl,0xa
    jne    Branch41
  Branch38:
    mov    dl,BYTE PTR [eax+0x1]
    cmp    dl,0xd
    je     Branch39
    cmp    dl,0xa
    jne    Branch41
  Branch39:
    mov    dl,BYTE PTR [eax+0x2]
    cmp    dl,0xd
    je     Branch40
    cmp    dl,0xa
    jne    Branch41
  Branch40:
    mov    al,BYTE PTR [eax+0x3]
    cmp    al,0xd
    je     Branch49
    cmp    al,0xa
    je     Branch49
  Branch41:
    cmp    cl,0xd
    je     Branch42
    cmp    cl,0xa
    je     Branch42
    mov    BYTE PTR [esp+esi*1+0x68],cl
    inc    esi
    mov    DWORD PTR [esp+0x24],esi
    jmp    Branch48
  Branch42:
    lea    edi,[esp+esi*1+0x68]
    lea    ecx,[esp+0x68]
    cmp    ecx,edi
    lea    esi,[esp+0x68]
    mov    BYTE PTR [edi],0x0
    je     Branch44
  Branch43:
    movsx  edx,BYTE PTR [esi]
    push   edx
    call   R6GameServiceAddresses::toupper
    add    esp,0x4
    mov    BYTE PTR [esi],al
    inc    esi
    cmp    esi,edi
    jne    Branch43
  Branch44:
    xor    eax,eax
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x1c],eax
    push   eax
    lea    eax,[esp+0x16]
    push   eax
    mov    DWORD PTR [esp+0x478],0x5
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    lea    edi,[esp+0x68]
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x68]
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x470],0x6
    lea    ecx,[esp+ecx*1+0x68]
    push   ecx
    push   edx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::InitializeStringRange
    mov    eax,DWORD PTR [ebp+0x19c]
    mov    ecx,DWORD PTR [ebp+0x1a0]
    lea    esi,[ebp+0x198]
    cmp    eax,ecx
    mov    BYTE PTR [esp+0x470],0x7
    je     Branch46
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x28],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x470],0x8
    je     Branch45
    lea    ecx,[esp+0x18]
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructHeapByteString
  Branch45:
    add    DWORD PTR [esi+0x4],0xc
    jmp    Branch47
  Branch46:
    push   0x1
    lea    edx,[esp+0x17]
    push   0x1
    lea    ecx,[esp+0x20]
    push   edx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::RebuildThreeWordArray
  Branch47:
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x470],0x9
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x24]
    xor    eax,eax
    mov    edx,ecx
    lea    edi,[esp+0x68]
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    mov    DWORD PTR [esp+0x24],0x0
    mov    esi,DWORD PTR [esp+0x24]
    and    ecx,0x3
    mov    DWORD PTR [esp+0x470],0xffffffff
    inc    ebx
    rep    stos BYTE PTR es:[edi],al
  Branch48:
    mov    eax,DWORD PTR [ebp+0xa6c]
    inc    ebx
    cmp    ebx,eax
    jbe    Branch37
    jmp    Branch55
  Branch49:
    lea    edi,[esp+esi*1+0x68]
    lea    eax,[esp+0x68]
    cmp    eax,edi
    mov    DWORD PTR [esp+0x14],ebx
    mov    BYTE PTR [edi],0x0
    lea    esi,[esp+0x68]
    je     Branch51
  Branch50:
    movsx  ecx,BYTE PTR [esi]
    push   ecx
    call   R6GameServiceAddresses::toupper
    add    esp,0x4
    mov    BYTE PTR [esi],al
    inc    esi
    cmp    esi,edi
    jne    Branch50
  Branch51:
    xor    eax,eax
    lea    edx,[esp+0x13]
    push   eax
    push   edx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x478],eax
    mov    DWORD PTR [esp+0x20],eax
    mov    DWORD PTR [esp+0x24],eax
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    lea    edi,[esp+0x68]
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x470],0x1
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+ecx*1+0x68]
    lea    ecx,[esp+0x68]
    push   eax
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::InitializeStringRange
    mov    eax,DWORD PTR [ebp+0x19c]
    mov    ecx,DWORD PTR [ebp+0x1a0]
    lea    esi,[ebp+0x198]
    cmp    eax,ecx
    mov    BYTE PTR [esp+0x470],0x2
    je     Branch53
    mov    DWORD PTR [esp+0x28],eax
    mov    DWORD PTR [esp+0x14],eax
    test   eax,eax
    mov    BYTE PTR [esp+0x470],0x3
    je     Branch52
    lea    edx,[esp+0x18]
    mov    ecx,eax
    push   edx
    call   R6GameServiceAddresses::ConstructHeapByteString
  Branch52:
    add    DWORD PTR [esi+0x4],0xc
    jmp    Branch54
  Branch53:
    push   0x1
    lea    ecx,[esp+0x16]
    push   0x1
    lea    edx,[esp+0x20]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::RebuildThreeWordArray
  Branch54:
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x470],0x4
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x24]
    xor    eax,eax
    mov    edx,ecx
    lea    edi,[esp+0x68]
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    mov    DWORD PTR [esp+0x470],0xffffffff
    and    ecx,0x3
    add    ebx,0x4
    rep    stos BYTE PTR es:[edi],al
  Branch55:
    push   ebx
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [ebp+0x1ac],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0x1ac]
    mov    esi,DWORD PTR [ebp+0xa58]
    mov    DWORD PTR [ebp+0x1a8],eax
    mov    edi,eax
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ebx,DWORD PTR [ebp+0x198]
    mov    eax,DWORD PTR [ebp+0x19c]
    cmp    ebx,eax
    je     Branch63
  Branch56:
    push   0x9
    lea    ecx,[esp+0x3c]
    push   0x0
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    edx,eax
    mov    edi,R6GameServiceAddresses::TextHTTP11
    or     ecx,0xffffffff
    xor    eax,eax
    mov    esi,DWORD PTR [edx]
    mov    edx,DWORD PTR [edx+0x4]
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    sub    edx,esi
    cmp    edx,ecx
    jne    Branch57
    mov    edi,R6GameServiceAddresses::TextHTTP11
    xor    eax,eax
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    mov    BYTE PTR [esp+0x12],0x1
    je     Branch58
  Branch57:
    mov    BYTE PTR [esp+0x12],0x0
  Branch58:
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x470],0xa
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    al,BYTE PTR [esp+0x12]
    or     esi,0xffffffff
    test   al,al
    mov    DWORD PTR [esp+0x470],esi
    je     Branch59
    push   0xb
    lea    ecx,[esp+0x60]
    push   0x9
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    eax,DWORD PTR [eax]
    push   eax
    call   R6GameServiceAddresses::atoi
    add    esp,0x4
    mov    DWORD PTR [ebp+0xa4c],eax
    lea    ecx,[esp+0x5c]
    mov    DWORD PTR [esp+0x470],0xb
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    edx,DWORD PTR [ebx+0x4]
    mov    eax,DWORD PTR [ebx]
    sub    edx,eax
    lea    eax,[esp+0x44]
    sub    edx,0xd
    mov    ecx,ebx
    push   edx
    push   0xd
    push   eax
    mov    DWORD PTR [esp+0x47c],esi
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [eax]
    sub    ecx,edx
    mov    DWORD PTR [ebp+0xa54],ecx
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x470],0xc
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    eax,DWORD PTR [ebp+0xa54]
    mov    DWORD PTR [esp+0x470],esi
    test   eax,eax
    je     Branch68
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0xa54]
    mov    edi,eax
    mov    edx,ecx
    xor    eax,eax
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0xa50],edi
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [ebx+0x4]
    mov    edx,DWORD PTR [ebx]
    sub    eax,edx
    lea    ecx,[esp+0x18]
    sub    eax,0xd
    push   eax
    push   0xd
    push   ecx
    mov    ecx,ebx
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    ecx,DWORD PTR [ebp+0xa54]
    mov    eax,DWORD PTR [eax]
    mov    edi,DWORD PTR [ebp+0xa50]
    mov    edx,ecx
    mov    esi,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [esp+0x18]
    sub    ecx,eax
    mov    DWORD PTR [esp+0x470],0xd
    push   ecx
    push   eax
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    DWORD PTR [esp+0x470],0xffffffff
    or     esi,0xffffffff
  Branch59:
    mov    eax,DWORD PTR [ebp+0xa4c]
    test   eax,eax
    je     Branch68
    push   0x10
    lea    edx,[esp+0x30]
    push   0x0
    push   edx
    mov    ecx,ebx
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    edx,eax
    mov    edi,R6GameServiceAddresses::TextCONTENTLENGTH
    mov    ecx,esi
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    mov    esi,DWORD PTR [edx]
    mov    eax,DWORD PTR [edx+0x4]
    not    ecx
    dec    ecx
    sub    eax,esi
    cmp    eax,ecx
    jne    Branch60
    mov    edi,R6GameServiceAddresses::TextCONTENTLENGTH
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    mov    BYTE PTR [esp+0x12],0x1
    je     Branch61
  Branch60:
    mov    BYTE PTR [esp+0x12],0x0
  Branch61:
    mov    ecx,DWORD PTR [esp+0x34]
    mov    eax,DWORD PTR [esp+0x2c]
    sub    ecx,eax
    mov    DWORD PTR [esp+0x470],0xe
    push   ecx
    push   eax
    lea    ecx,[esp+0x3c]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    al,BYTE PTR [esp+0x12]
    mov    DWORD PTR [esp+0x470],0xffffffff
    test   al,al
    je     Branch62
    mov    edx,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    sub    edx,esi
    lea    eax,[esp+0x50]
    sub    edx,0x10
    mov    ecx,ebx
    push   edx
    push   0x10
    push   eax
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    eax,DWORD PTR [eax]
    push   eax
    call   R6GameServiceAddresses::atoi
    mov    ecx,DWORD PTR [esp+0x54]
    add    esp,0x4
    mov    DWORD PTR [ebp+0xa48],eax
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch62:
    mov    eax,DWORD PTR [ebp+0x19c]
    add    ebx,0xc
    cmp    ebx,eax
    jne    Branch56
  Branch63:
    mov    ebx,DWORD PTR [ebp+0xa6c]
    mov    edi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [ebp+0xa7c]
    sub    ebx,edi
    test   eax,eax
    je     Branch64
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch64:
    test   ebx,ebx
    je     Branch65
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,DWORD PTR [ebp+0xa58]
    mov    ecx,ebx
    mov    edx,ecx
    add    esi,edi
    mov    edi,eax
    mov    DWORD PTR [ebp+0xa7c],eax
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0xa80],ebx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch65:
    mov    eax,DWORD PTR [ebp+0x1b0]
    mov    DWORD PTR [ebp+0xa64],ebx
    test   eax,eax
    je     Branch66
    cmp    eax,0x1
    jne    Branch70
  Branch66:
    cmp    DWORD PTR [ebp+0xa4c],0xc8
    jne    Branch70
    mov    eax,DWORD PTR [ebp+0xa48]
    test   eax,eax
    jle    Branch70
    mov    edi,DWORD PTR [ebp+0xa60]
    test   edi,edi
    je     Branch69
    mov    ecx,DWORD PTR [ebp+0xa68]
    xor    eax,eax
    mov    edx,ecx
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [ebp+0xa68]
    cmp    eax,ebx
    jae    Branch67
    mov    ebx,eax
  Branch67:
    mov    esi,DWORD PTR [ebp+0xa7c]
    mov    edi,DWORD PTR [ebp+0xa60]
    mov    ecx,ebx
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    DWORD PTR [ebp+0xa6c],ebx
    mov    BYTE PTR [ebp+0xa70],0x0
    jmp    Branch70
  Branch68:
    xor    al,al
    jmp    Branch71
  Branch69:
    push   eax
    mov    DWORD PTR [ebp+0xa68],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0xa48]
    mov    edi,eax
    mov    edx,ecx
    xor    eax,eax
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0xa60],edi
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    ecx,DWORD PTR [ebp+0xa80]
    mov    esi,DWORD PTR [ebp+0xa7c]
    mov    edi,DWORD PTR [ebp+0xa60]
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [ebp+0xa80]
    mov    BYTE PTR [ebp+0xa70],0x1
    mov    DWORD PTR [ebp+0xa6c],ecx
  Branch70:
    mov    ebx,DWORD PTR [ebp+0xa48]
    xor    eax,eax
    cmp    ebx,0x2800
    setle  al
    dec    eax
    and    eax,0x1000
    add    eax,0x400
    push   eax
    mov    DWORD PTR [ebp+0xa78],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [ebp+0xa74],eax
    mov    al,0x1
  Branch71:
    mov    ecx,DWORD PTR [esp+0x468]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x464
    ret
  }
}

// Formats GET into a cleared512-byte stack buffer with limit511, scans its length and submits it to TCP.
// The optional-header test checks owner+0x5c6 as an address, not its first byte; snprintf status is ignored.
// Send result controls only AL, retaining its raw upper24 bits.
// R6GameService.dll @ 10016250 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestSubmitGet(void *owner)
{
  __asm {
    sub    esp,0x200
    xor    eax,eax
    lea    edx,[esp+0x0]
    push   esi
    push   edi
    mov    esi,ecx
    mov    ecx,0x80
    lea    edi,[esp+0x8]
    rep    stos DWORD PTR es:[edi],eax
    lea    eax,[esi+0x5c6]
    lea    ecx,[esi+0x8d]
    test   eax,eax
    je     Branch72
    push   eax
    lea    eax,[esi+0xc]
    push   eax
    push   ecx
    push   R6GameServiceAddresses::TextGETSHTTP11HostSUserAgentUbiComConnectionCloseS
    push   0x1ff
    push   edx
    call   R6GameServiceAddresses::_snprintf
    add    esp,0x18
    jmp    Branch73
  Branch72:
    lea    eax,[esi+0xc]
    push   eax
    push   ecx
    push   R6GameServiceAddresses::TextGETSHTTP11HostSUserAgentUbiComConnectionClose
    push   0x1ff
    push   edx
    call   R6GameServiceAddresses::_snprintf
    add    esp,0x14
  Branch73:
    lea    edi,[esp+0x8]
    or     ecx,0xffffffff
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x8]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    call   R6GameServiceAddresses::SendConnectionBytes
    test   eax,eax
    pop    edi
    pop    esi
    setne  al
    add    esp,0x200
    ret
  }
}

// Scans the output filename, truncates it once, then reopens it for append and publishes setup flag1.
// Empty filename wins over the setup flag; a failed append reopen still returns AL1 with its raw upper EAX.
// R6GameService.dll @ 100162e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestOpenOutput(void *owner)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    or     ecx,0xffffffff
    xor    eax,eax
    lea    ebx,[esi+0x9c6]
    mov    edi,ebx
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    jne    Branch74
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret
  Branch74:
    mov    al,BYTE PTR [esi+0x194]
    test   al,al
    je     Branch75
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret
  Branch75:
    push   R6GameServiceAddresses::WideTextW
    push   ebx
    call   R6GameServiceAddresses::fopen
    add    esp,0x8
    mov    DWORD PTR [esi+0x190],eax
    test   eax,eax
    jne    Branch76
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret
  Branch76:
    push   eax
    call   R6GameServiceAddresses::fclose
    push   R6GameServiceAddresses::TextAb
    push   ebx
    call   R6GameServiceAddresses::fopen
    add    esp,0xc
    mov    DWORD PTR [esi+0x190],eax
    mov    al,0x1
    mov    BYTE PTR [esi+0x194],al
    pop    edi
    pop    esi
    pop    ebx
    ret
  }
}

// Closes a flagged nonnull output handle and clears the handle slot, retaining the setup flag and raw upper EAX.
// R6GameService.dll @ 10016360 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CHttpRequestCloseOutput(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x194]
    test   al,al
    je     Branch78
    mov    eax,DWORD PTR [esi+0x190]
    test   eax,eax
    je     Branch77
    push   eax
    call   R6GameServiceAddresses::fclose
    add    esp,0x4
  Branch77:
    mov    DWORD PTR [esi+0x190],0x0
  Branch78:
    mov    al,0x1
    pop    esi
    ret
  }
}

// Calls the completion callback, optionally frees its current owned buffer, then clears the buffer slot.
// With no callback neither free nor clear occurs. The boolean argument retains the context word's upper24 bits.
// Callback-time ownership/buffer changes control release; signed expected-size comparison may force event2.
// R6GameService.dll @ 10016390 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CHttpRequestNotifyCompletion(void *owner,uint requestId,uint eventCode)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x1bc]
    test   eax,eax
    je     Branch81
    mov    ecx,DWORD PTR [esi+0xa64]
    mov    edx,DWORD PTR [esi+0xa48]
    push   edi
    cmp    edx,ecx
    mov    edi,0x2
    jg     Branch79
    mov    edi,DWORD PTR [esp+0x10]
  Branch79:
    mov    edx,DWORD PTR [esi+0x1c0]
    push   edx
    mov    dl,BYTE PTR [esi+0xa70]
    test   dl,dl
    sete   dl
    push   edx
    mov    edx,DWORD PTR [esp+0x14]
    push   ecx
    mov    ecx,DWORD PTR [esi+0xa60]
    push   ecx
    push   edi
    push   edx
    call   eax
    mov    al,BYTE PTR [esi+0xa70]
    pop    edi
    test   al,al
    je     Branch80
    mov    eax,DWORD PTR [esi+0xa60]
    test   eax,eax
    je     Branch80
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch80:
    mov    DWORD PTR [esi+0xa60],0x0
  Branch81:
    pop    esi
    ret    0x8
  }
}

// Optionally writes the current data chunk on event5, then calls the current seven-word data callback.
// File writes ignore setup state and write result; callback pointer/data fields reload after the write.
// R6GameService.dll @ 10016410 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CHttpRequestDeliverData(void *owner,uint requestId,uint eventCode)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,ecx
    cmp    edi,0x5
    jne    Branch83
    mov    eax,DWORD PTR [esi+0x1b0]
    cmp    eax,0x2
    je     Branch82
    cmp    eax,0x3
    jne    Branch83
  Branch82:
    mov    ecx,DWORD PTR [esi+0xa80]
    test   ecx,ecx
    je     Branch83
    mov    eax,DWORD PTR [esi+0x190]
    test   eax,eax
    je     Branch83
    push   eax
    mov    eax,DWORD PTR [esi+0xa7c]
    push   ecx
    push   0x1
    push   eax
    call   R6GameServiceAddresses::fwrite
    add    esp,0x10
  Branch83:
    mov    eax,DWORD PTR [esi+0x1b8]
    test   eax,eax
    je     Branch84
    mov    ecx,DWORD PTR [esi+0x1c0]
    mov    edx,DWORD PTR [esi+0xa48]
    push   ecx
    mov    ecx,DWORD PTR [esi+0xa64]
    push   edx
    mov    edx,DWORD PTR [esi+0xa80]
    push   ecx
    mov    ecx,DWORD PTR [esi+0xa7c]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   ecx
    push   edi
    push   edx
    call   eax
  Branch84:
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Tests saved flags bit1 and, when set, tail-calls empty cleanup on saved owner+0xa84.
// R6GameService.dll @ 10064620 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test   eax,eax
    je     Branch85
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xa84
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch85:
    ret
  }
}

// Restores the allocator base table through the saved complete request owner.
// R6GameService.dll @ 1006463d : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Tests saved flags bit4 and, when set, tail-calls empty cleanup on saved embedded range+0x10.
// R6GameService.dll @ 10064645 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x4
    test   eax,eax
    je     Branch86
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch86:
    ret
  }
}

// Passes the original final argument slot address to genuine empty cleanup.
// R6GameService.dll @ 1006465f : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp+0x2c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-destroys the saved request owner's embedded string-record range at +0x198.
// R6GameService.dll @ 10064667 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x198
    jmp    R6GameServiceAddresses::thunk_DestroyStringRecordRange
  }
}

// Releases the unfinished TCP child allocation saved at inherited frame-0x10.
// R6GameService.dll @ 10064675 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Tests saved flags bit8 and, when set, passes the unfinished TCP child+0x54 to empty cleanup.
// R6GameService.dll @ 1006467f : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind7(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x8
    test   eax,eax
    je     Branch87
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x54
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch87:
    ret
  }
}

// Releases the first word of the record whose pointer occupies the reused second incoming argument slot.
// R6GameService.dll @ 10064699 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Restores the allocator base table through the saved complete request owner.
// R6GameService.dll @ 100646d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyServiceObjectMembersUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Tail-destroys the string-record range at saved complete request owner+0x198.
// R6GameService.dll @ 100646d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyServiceObjectMembersUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x198
    jmp    R6GameServiceAddresses::thunk_DestroyStringRecordRange
  }
}

// Releases nonnull range storage through the saved embedded range receiver at frame-0x10.
// R6GameService.dll @ 100646e6 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyServiceObjectMembersUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 10064700 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x462]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the current temporary string through its inherited-frame slot at -0x45c.
// R6GameService.dll @ 1006470b : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x45c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its inherited-frame slot at -0x45c.
// R6GameService.dll @ 10064716 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x45c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Loads both saved record words in their native order, calls genuine empty cleanup and discards two words.
// R6GameService.dll @ 10064721 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x460]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x44c]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 10064738 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x454]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 10064743 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x461]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the current temporary string through its inherited-frame slot at -0x45c.
// R6GameService.dll @ 1006474e : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x45c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its inherited-frame slot at -0x45c.
// R6GameService.dll @ 10064759 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x45c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Loads both saved record words in their native order, calls genuine empty cleanup and discards two words.
// R6GameService.dll @ 10064764 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x44c]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x460]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 1006477b : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x454]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 10064786 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind11(void)
{
  __asm {
    lea    ecx,[ebp-0x434]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 10064791 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x410]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 1006479c : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind13(void)
{
  __asm {
    lea    ecx,[ebp-0x428]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 100647a7 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x454]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup, retaining native register effects.
// R6GameService.dll @ 100647b2 : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderUnwind15(void)
{
  __asm {
    lea    ecx,[ebp-0x440]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the exact request or string-record lifetime metadata for the inherited frame.
// R6GameService.dll @ 100646a1 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeHttpRequestRecordSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeHttpRequestRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the exact request or string-record lifetime metadata for the inherited frame.
// R6GameService.dll @ 100646ee : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyServiceObjectMembersSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceObjectMembersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e8b4 : native request lifetime records.
const R6GameServiceNative::UnwindEntry InitializeHttpRequestRecordUnwindMap[8] = {
  {-1, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind1},
  {0x0, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind2},
  {0x1, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind3},
  {0x2, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind4},
  {0x1, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind5},
  {0x4, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind6},
  {0x5, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind7},
  {0x4, R6GameServiceAddresses::InitializeHttpRequestRecordUnwind8},
};

// R6GameService.dll data @ 1007e8f4 : native request lifetime records.
const R6GameServiceNative::FuncInfo InitializeHttpRequestRecordExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::InitializeHttpRequestRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007e93c : native request lifetime records.
const R6GameServiceNative::UnwindEntry DestroyServiceObjectMembersUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyServiceObjectMembersUnwind1},
  {0x0, R6GameServiceAddresses::DestroyServiceObjectMembersUnwind2},
  {0x0, R6GameServiceAddresses::DestroyServiceObjectMembersUnwind3},
};

// R6GameService.dll data @ 1007e954 : native request lifetime records.
const R6GameServiceNative::FuncInfo DestroyServiceObjectMembersExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::DestroyServiceObjectMembersUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Selects the fifteen-state header-parser lifetime record.
// R6GameService.dll @ 100647bd : complete native control/access order and raw ABI retained.
__declspec(naked) void CHttpRequestParseHeaderSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CHttpRequestParseHeaderExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e970 : native request parser lifetime records.
const R6GameServiceNative::UnwindEntry CHttpRequestParseHeaderUnwindMap[15] = {
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind1},
  {0x0, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind2},
  {0x0, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind3},
  {0x2, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind4},
  {0x0, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind5},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind6},
  {0x5, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind7},
  {0x5, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind8},
  {0x7, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind9},
  {0x5, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind10},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind11},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind12},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind13},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind14},
  {-1, R6GameServiceAddresses::CHttpRequestParseHeaderUnwind15},
};

// R6GameService.dll data @ 1007e9e8 : native request parser lifetime records.
const R6GameServiceNative::FuncInfo CHttpRequestParseHeaderExceptionInfo = {
  0x19930520,
  0xf,
  R6GameServiceAddresses::CHttpRequestParseHeaderUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: CHttpRequestVTable
// R6GameService.dll data @ 10075bcc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CHttpRequestVTableRecord {
  R6GameServiceNative::Address DestroyRecordAndOptionallyFree; // +0x00
};
const CHttpRequestVTableRecord CHttpRequestVTable = {R6GameServiceAddresses::DestroyRecordAndOptionallyFree};
