#include "native_addresses.h"
#include "native_records.h"

// clProxyMessage payload role follows proxy-message-list RTTI and all four typed destruction callers.
// The original destructor spelling/layout remains inferred; only embedded descriptor8 and its actual operations are represented.

// Destroy embedded descriptor at+8 via captured generic range, CURRENT links/head, then reset only its base table.
// Preserve prefix bytes, outer allocation and state1 head-only/state0 base-only cleanup. Raw final free EAX.
// R6GameService.dll @ 10062aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyPerNodeLinkedListContainer(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectProxyMessageEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push    ebx
    push    ebp
    lea    ebp,[ecx+0x8]
    push    esi
    push    edi
    mov    DWORD PTR [esp+0x10],ebp
    lea    esi,[ebp+0xc]
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x24],0x0
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN2
    push    ecx
    mov    ecx,DWORD PTR [esi+0x4]
    lea    edi,[esi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [esi]
    mov    ecx,edi
    mov    BYTE PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x20]
    mov    ecx,esi
    push    eax
    call    DWORD PTR [ebx+0x10]
    mov    ecx,edi
    mov    BYTE PTR [esp+0x24],0x0
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    ecx,DWORD PTR [edi]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x1c]
    pop    edi
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::PTR_LAB
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x18
    ret
  }
}

// Reset only the embedded descriptor base at CURRENT saved descriptor pointer; do not retry list release.
// R6GameService.dll @ 1006a050 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPerNodeLinkedListContainerUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release nodes/head through CURRENT saved embedded list interface, preserving NULL/context scratch.
// R6GameService.dll @ 1006a058 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPerNodeLinkedListContainerUnwind2(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch1
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x1c],eax
    jmp    Branch2
  Branch1:
    mov    DWORD PTR [ebp-0x1c],0x0
  Branch2:
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the exact two-state embedded descriptor cleanup map and tail CRT dispatch.
// R6GameService.dll @ 1006a07f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectProxyMessageEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyPerNodeLinkedListContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native proxy-message list/payload cleanup records.
// R6GameService.dll data @ 10084b80 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyPerNodeLinkedListContainerUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwind1},
  {0x0, R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwind2},
};
// R6GameService.dll data @ 10084b90 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyPerNodeLinkedListContainerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyPerNodeLinkedListContainerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
