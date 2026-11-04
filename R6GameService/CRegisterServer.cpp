#include "native_addresses.h"
#include "native_records.h"

// Retail RTTI: primary76cdc -> COL78f58/type8e34c, .?AVCRegisterServer@@; private field names remain inferred.

// Clears selected state fields, forward-copies live default bytes, allocates and constructs owned list.
// Pending allocation arms only after allocation; publication/return retain state0 and cached receiver.
// R6GameService.dll @ 1002f760 : native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall InitializeRegistrationServiceState(void *service)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SharedRegistrationAllocationExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    xor    ebx,ebx
    mov    ecx,0x20
    xor    eax,eax
    lea    edi,[esi+0x18]
    mov    DWORD PTR [esi],R6GameServiceAddresses::CRegisterServerVTable
    mov    DWORD PTR [esi+0x120],ebx
    rep    stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    lea    edx,[esi+0x8]
    mov    BYTE PTR [esi+0x99],bl
    mov    DWORD PTR [esi+0x124],ebx
    mov    BYTE PTR [esi+0x9a],bl
    sub    edx,eax
  Branch10:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    cmp    cl,bl
    jne    Branch10
    push   0xc
    mov    DWORD PTR [esi+0x128],ebx
    mov    DWORD PTR [esi+0x12c],ebx
    mov    BYTE PTR [esi+0x9b],bl
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0xc],eax
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x18],ebx
    je     Branch11
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructParsedServiceRecordList
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  Branch11:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi+0x4],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys state then tests late low deletion bit and optionally uses cdecl free, returning saved owner.
// R6GameService.dll @ 1002f820 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteRegistrationServiceState(void *service,uint deleteFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyRegistrationServiceState
    test   BYTE PTR [esp+0x8],0x1
    je     Branch12
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch12:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore the primary table, delete the captured secondary object, then reload and delete the current owned list.
// The secondary pointer is captured before table publication. Slots remain unchanged; no local cleanup or retry.
// R6GameService.dll @ 1002f840 : native control/access order and raw ABI retained.
void __fastcall DestroyRegistrationServiceState(void *service)
{
  void *savedService = service;
  void *secondary = *(void **)((byte *)savedService + 0x124);
  *(uint *)savedService = R6GameServiceAddresses::CRegisterServerVTable;
  using DeleteABI = void * (__thiscall *)(void *,uint);
  if (secondary != nullptr) {
    uint table = *(uint *)secondary;
    ((DeleteABI)*(uint *)table)(secondary,1);
  }
  void *currentList = *(void **)((byte *)savedService + 4);
  if (currentList != nullptr) {
    uint table = *(uint *)currentList;
    ((DeleteABI)*(uint *)table)(currentList,1);
  }
}
