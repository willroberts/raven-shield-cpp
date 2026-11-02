#include "native_addresses.h"
#include "native_records.h"

// clSRPGSClient: RTTI-backed native class; original declarations and member spellings remain inferred.

// Allocate/build clSRPClient248, then forward six full words to clSRPGSConnect and install client table.
// ENTRY ESP S: unused scratchS-10/stateS-4; allocation saved by overwriting physical flag at S+14.
// State0 owns CURRENT overwritten slot, including NULL. Disarm before base construction; base failure has no outer release.
// Preserve optional table write from original full flag, post-construction live parameter reloads and RET20/owner EAX.
// R6GameService.dll @ 100595f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clSRPGSClientConstruct(void *owner,uint identifier,uint field0c,uint field0d,uint idleLimit,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSRPGSClientEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    mov    eax,DWORD PTR [esp+0x24]
    push    esi
    push    edi
    mov    edi,ecx
    test    eax,eax
    mov    DWORD PTR [esp+0x8],0x0
    je    Branch1
    mov    DWORD PTR [edi+0x4],0x10078190
  Branch1:
    push    0x248
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x2c],esi
    test    esi,esi
    mov    DWORD PTR [esp+0x14],0x0
    je    Branch2
    push    0x0
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],0x10078188
    call    R6GameServiceAddresses::InitializeLargeRecordOwnerState
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPClientVTable
    jmp    Branch3
  Branch2:
    xor    esi,esi
  Branch3:
    mov    eax,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x24]
    mov    edx,DWORD PTR [esp+0x20]
    push    0x0
    push    eax
    mov    eax,DWORD PTR [esp+0x24]
    push    ecx
    push    edx
    push    eax
    push    esi
    mov    ecx,edi
    mov    DWORD PTR [esp+0x2c],0xffffffff
    call    R6GameServiceAddresses::clSRPGSConnectConstruct
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [edi],R6GameServiceAddresses::clSRPGSClientVTable
    mov    eax,edi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x14
  }
}

// Install client table before shared base cleanup; deleting wrapper reads CURRENT low-byte flag bit0 afterward.
// R6GameService.dll @ 100596a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clSRPGSClientDelete(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::clSRPGSClientDestroy
    test    BYTE PTR [esp+0x8],0x1
    je    Branch4
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch4:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Install client table before shared base cleanup; deleting wrapper reads CURRENT low-byte flag bit0 afterward.
// R6GameService.dll @ 100596c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clSRPGSClientDestroy(void *owner)
{
  __asm {
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clSRPGSClientVTable
    jmp    R6GameServiceAddresses::clSRPGSConnectDestroy
  }
}

// Resolve into owner+60 ignoring resolver status; open current associated slot8, then poll until ready or AL0 failure.
// No timeout or own EH; preserve current associated pointer, live field8e/field11a arguments and final raw upper EAX. RET12.
// R6GameService.dll @ 100596d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenSRPGSClient(void *owner,uint address,uint field8eWord,uint field11aWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    mov    esi,ecx
    push    edi
    lea    edi,[esi+0x60]
    push    edi
    push    eax
    call    R6GameServiceAddresses::ResolveIPv4Address
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esi+0x68]
    push    0x0
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [ecx]
    push    eax
    mov    eax,DWORD PTR [edi]
    push    eax
    call    DWORD PTR [edx+0x8]
    test    al,al
    jne    Branch6
  Branch5:
    pop    edi
    xor    al,al
    pop    esi
    ret    0xc
  Branch6:
    mov    ecx,esi
    call    R6GameServiceAddresses::DispatchProviderReceiveState
    test    al,al
    je    Branch5
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadAssociatedProviderReady
    test    al,al
    je    Branch6
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0xc
  }
}

// Free CURRENT raw associated allocation from inherited entry ESP+14; do not reload receiver+68.
// R6GameService.dll @ 10069830 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clSRPGSClientConstructUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x14]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select exact native FuncInfo then tail-forward to CRT exception dispatch.
// R6GameService.dll @ 1006983a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSRPGSClientEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clSRPGSClientConstructExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 1008431c : native storage identity retained.
const R6GameServiceNative::UnwindEntry clSRPGSClientConstructUnwindMap[1] = {
  {-1, R6GameServiceAddresses::clSRPGSClientConstructUnwind1},
};

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 1008431c : native storage identity retained.
const R6GameServiceNative::FuncInfo clSRPGSClientConstructExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::clSRPGSClientConstructUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clSRPGSClientVTable
// R6GameService.dll data @ 1007815c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSRPGSClientVTableRecord {
  R6GameServiceNative::Address clSRPGSClientDelete; // +0x00
  R6GameServiceNative::Address OpenSRPGSClient; // +0x04
  R6GameServiceNative::Address CloseAssociatedOwner; // +0x08
  R6GameServiceNative::Address clSRPGSConnectTakeMessage; // +0x0c
};
const clSRPGSClientVTableRecord clSRPGSClientVTable = {
  R6GameServiceAddresses::clSRPGSClientDelete,
  R6GameServiceAddresses::OpenSRPGSClient,
  R6GameServiceAddresses::CloseAssociatedOwner,
  R6GameServiceAddresses::clSRPGSConnectTakeMessage,
};
