#include "native_addresses.h"
#include "native_records.h"

// Retail RTTI: primary76c84 -> COL78e94/type8e36c, .?AVCRegisterServerCB@@.
// Secondary76c7c -> COL78f2c, offset170, same type. Other class layout/names remain unresolved.

// Optionally installs virtual-base offset tables, constructs state, then callbacks and final primary/base tables.
// Construction bitmap and EH state are separate; cached offset-table pointer and raw receiver/RET4 are retained.
// R6GameService.dll @ 1002f460 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructRegistrationService(void *service,int initializeBaseVtables)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectRegistrationConstructionLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x18]
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    test   eax,eax
    mov    DWORD PTR [esp+0x8],esi
    je     Branch8
    mov    DWORD PTR [esi+0x130],R6GameServiceAddresses::GRegistrationBaseOffsets
    mov    DWORD PTR [esi+0x174],R6GameServiceAddresses::GRegistrationSecondaryOffsets
    mov    DWORD PTR [esi+0x170],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    mov    DWORD PTR [esp+0x4],0x3
    mov    DWORD PTR [esp+0x14],0x1
  Branch8:
    mov    ecx,esi
    call   R6GameServiceAddresses::InitializeRegistrationServiceState
    mov    eax,DWORD PTR [esi+0x130]
    mov    DWORD PTR [esi+0x134],R6GameServiceAddresses::NoOpServiceCallbackRet0C
    mov    DWORD PTR [esi+0x138],R6GameServiceAddresses::list_node_support_NoOp
    mov    DWORD PTR [esi+0x13c],R6GameServiceAddresses::NoOpServiceCallbackRet18
    mov    DWORD PTR [esi+0x140],R6GameServiceAddresses::NoOpRegistrationCallbackRet1C
    mov    DWORD PTR [esi+0x144],R6GameServiceAddresses::NoOpServiceCallbackRet10
    mov    DWORD PTR [esi+0x148],R6GameServiceAddresses::NoOpServiceCallbackRet0C
    mov    DWORD PTR [esi+0x14c],R6GameServiceAddresses::list_node_support_NoOp
    mov    DWORD PTR [esi+0x150],R6GameServiceAddresses::NoOpRegistrationCallbackRet1C
    mov    DWORD PTR [esi+0x154],R6GameServiceAddresses::shared_native_NoOp
    mov    DWORD PTR [esi+0x15c],R6GameServiceAddresses::NoOpServiceCallbackRet0C
    mov    DWORD PTR [esi+0x160],R6GameServiceAddresses::NoOp
    mov    DWORD PTR [esi+0x164],R6GameServiceAddresses::NoOp
    mov    DWORD PTR [esi+0x168],R6GameServiceAddresses::NoOpRegistrationCallbackRet54
    mov    DWORD PTR [esi+0x16c],R6GameServiceAddresses::NoOpServiceCallbackRet0C
    mov    DWORD PTR [esi],R6GameServiceAddresses::CRegisterServerCBVTable
    mov    ecx,DWORD PTR [eax+0x8]
    mov    eax,esi
    mov    DWORD PTR [ecx+esi*1+0x130],R6GameServiceAddresses::CRegisterServerCBVTableAdjusted368
    mov    ecx,DWORD PTR [esp+0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Destroy state, capture the late deleting byte, reset the allocation base and optionally release the saved owner.
// The deleting byte is sampled before the +170 table store; callbacks may already have changed its original slot.
// R6GameService.dll @ 1002f580 : native control/access order and raw ABI retained.
void * __thiscall DeleteRegistrationService(void *service,uint deleteFlags)
{
  void *savedService = service;
  DestroyRegistrationService(savedService);
  byte flags = (byte)deleteFlags;
  *(uint *)((byte *)savedService + 0x170) = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(savedService);
  return savedService;
}

// Restore the primary and dynamically located allocation-base tables, then destroy the registration state.
// Capture the offset-table pointer before primary publication, but read its offset word after that store.
// R6GameService.dll @ 1002f5b0 : native control/access order and raw ABI retained.
void __fastcall DestroyRegistrationService(void *service)
{
  uint base = (uint)service;
  uint offsetTable = *(uint *)(base + 0x130);
  *(uint *)base = R6GameServiceAddresses::CRegisterServerCBVTable;
  uint offset = *(uint *)(offsetTable + 8);
  *(uint *)(base + offset + 0x130) = R6GameServiceAddresses::CRegisterServerCBVTableAdjusted368;
  DestroyRegistrationServiceState(service);
}
