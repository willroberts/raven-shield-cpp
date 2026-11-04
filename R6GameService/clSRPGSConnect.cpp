#include "native_addresses.h"
#include "native_records.h"

// clSRPGSConnect: primary78140 -> COL7a354 -> type907f4, .?AVclSRPGSConnect@@; member spellings inferred.
// Native hierarchy includes clConnectElem and OverrideAllocOperators; source declarations/layouts remain unresolved.

// Build the base with seven full physical words, caching identifier/idle while supplied base fields stay live.
// Publish CURRENT original associate pointer+68, store cached identifier at associate+178, then reload +68 for +170.
// Preserve overlap, early saved-FS capture, optional offset table and one-state empty-base cleanup. RET24/owner EAX.
// R6GameService.dll @ 10059180 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clSRPGSConnectConstruct(
    void *owner,int associatedOwner,uint identifier,uint field0c,uint field0d,uint idleLimit,uint initializeBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSRPGSConnectCtorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x34]
    xor    eax,eax
    push   edi
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esp+0xc],eax
    je     Branch1
    mov    DWORD PTR [esi+0x4],0x10078150
    mov    DWORD PTR [esp+0xc],0x1
    mov    DWORD PTR [esp+0x1c],eax
  Branch1:
    mov    edi,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x2c]
    mov    ebx,DWORD PTR [esp+0x28]
    push   eax
    push   edi
    push   ecx
    push   edx
    push   ebx
    push   eax
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnection
    mov    eax,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPGSConnectVTable
    mov    DWORD PTR [esi+0x68],eax
    mov    DWORD PTR [eax+0x178],ebx
    mov    eax,DWORD PTR [esi+0x68]
    mov    DWORD PTR [eax+0x170],edi
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x18
  }
}

// Retain saved owner for base cleanup until explicit base destruction; association effects do not roll back.
struct SRPGSConnectDestructionCleanup {
  void *savedOwner;
  int state;
  bool armed;
  // The native derived state owns only base destruction, never a separate association retry.
  ~SRPGSConnectDestructionCleanup() noexcept(false)
  {
    if (armed && state == 0) {
      state = -1;
      DestroyTransportRecordMembers(savedOwner);
    }
  }
};

// Destroy derived/base members, then optionally free the cached owner using the current flag low-byte bit0.
// R6GameService.dll @ 10059220 : full physical DWORD flag, RET4 and cached owner EAX.
void * __thiscall clSRPGSConnectDelete(void *owner,uint deleteFlags)
{
  void *savedOwner = owner;
  clSRPGSConnectDestroy(savedOwner);
  if (((byte)deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(savedOwner);
  return savedOwner;
}

// Invoke the associated member with its virtual-base adjustment, delete the current association, then destroy the base.
// The initial association is unchecked; preserve late target/association reads and raw base return.
// R6GameService.dll @ 10059240 : complete native control/access order and raw ABI retained.
uint __fastcall clSRPGSConnectDestroy(void *owner)
{
  SRPGSConnectDestructionCleanup cleanup{owner,-1,true};
  uint base = (uint)owner;
  *(uint *)base = R6GameServiceAddresses::clSRPGSConnectVTable;
  uint association = *(uint *)(base + 0x68);
  cleanup.state = 0;
  uint displacement = *(uint *)(association + 0x14c);
  uint virtualBaseTable = *(uint *)(association + 4);
  uint virtualOffset = *(uint *)(virtualBaseTable + displacement);
  uint adjustment = *(uint *)(association + 0x148);
  uint receiver = virtualOffset + adjustment + association + 4;
  using MemberABI = void (__thiscall *)(void *);
  ((MemberABI)*(uint *)(association + 0x144))((void *)receiver);
  uint currentAssociation = *(uint *)(base + 0x68);
  if (currentAssociation != 0) {
    uint table = *(uint *)currentAssociation;
    using DeleteABI = uint (__thiscall *)(void *,uint);
    ((DeleteABI)*(uint *)table)((void *)currentAssociation,1);
  }
  cleanup.state = -1;
  cleanup.armed = false;
  return DestroyTransportRecordMembers((void *)base);
}

// Apply exact inherited derived frame cleanup through saved owner/bit words and native target.
// R6GameService.dll @ 100697c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clSRPGSConnectConstructUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x6c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Apply exact inherited derived frame cleanup through saved owner/bit words and native target.
// R6GameService.dll @ 100697f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clSRPGSConnectDestroyUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyTransportRecordMembers
  }
}

// Select the associated one-state FuncInfo and tail current CRT dispatch.
// R6GameService.dll @ 100697da : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSRPGSConnectCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clSRPGSConnectConstructExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the associated one-state FuncInfo and tail current CRT dispatch.
// R6GameService.dll @ 100697f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSRPGSConnectDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clSRPGSConnectDestroyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 100842a8: exact derived provider unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry clSRPGSConnectConstructUnwindMap[1] = {
  {-1, R6GameServiceAddresses::clSRPGSConnectConstructUnwind1},
};

// R6GameService.dll data @ 100842b0: exact derived provider unwind map or FuncInfo.
// R6GameService.dll data @ 100842a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo clSRPGSConnectConstructExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::clSRPGSConnectConstructUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 100842cc: exact derived provider unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry clSRPGSConnectDestroyUnwindMap[1] = {
  {-1, R6GameServiceAddresses::clSRPGSConnectDestroyUnwind1},
};

// R6GameService.dll data @ 100842d4: exact derived provider unwind map or FuncInfo.
// R6GameService.dll data @ 100842cc : native storage identity retained.
const R6GameServiceNative::FuncInfo clSRPGSConnectDestroyExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::clSRPGSConnectDestroyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Detach one compact receive message; return it unchanged unless class byte0/tag db dispatches its current payload.
// Dispatch precedes reloading original message's virtual delete slot; consume with full flag1, then return full0.
// No local EH: dispatch/delete failure leaves detached message without parent cleanup; no next-message retry.
// R6GameService.dll @ 10059350 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__fastcall clSRPGSConnectTakeMessage(void *owner)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    lea    ecx,[edi+0x3c]
    call   R6GameServiceAddresses::RemoveFirstCompactRecord
    mov    esi,eax
    test   esi,esi
    je    Branch5
    mov    al,BYTE PTR [esi+0xc]
    test   al,al
    jne    Branch5
    cmp    BYTE PTR [esi+0xd],0xdb
    jne    Branch5
    mov    eax,DWORD PTR [esi+0x14]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::DispatchProviderControlPayload
    mov    edx,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR [edx]
    pop    edi
    xor    eax,eax
    pop    esi
    ret
  Branch5:
    mov    eax,esi
    pop    edi
    pop    esi
    ret
  }
}

// Invoke associated target+138 with receiver A+4+[A+13c]+[[A+4]+[A+140]], then force AL1.
// Preserve raw callback upper EAX and unchecked association/descriptor accesses; no stack arguments or local EH.
// R6GameService.dll @ 10059300 : complete native control/access order and raw ABI retained.
uint __fastcall CloseAssociatedOwner(void *owner)
{
  uint associated = *(uint *)((uint)owner + 0x68);
  uint displacement = *(uint *)(associated + 0x140);
  uint table = *(uint *)(associated + 4);
  uint adjustment = *(uint *)(table + displacement);
  uint fixedAdjustment = *(uint *)(associated + 0x13c);
  void *receiver = (void *)(adjustment + fixedAdjustment + associated + 4);
  using CloseABI = uint (__fastcall *)(void *);
  uint result = (*(CloseABI *)(associated + 0x138))(receiver);
  return (result & 0xffffff00u) | 1;
}

// Genuine native slot4 stub: clear AL only and discard three physical argument words; retain incoming upper EAX.
// R6GameService.dll @ 10059330 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RejectChannelStart(
    void *owner,uint unusedAddress,uint unusedPort,uint unusedWord)
{
  __asm {
    xor    al,al
    ret    0xc
  }
}

// Native virtual-table prefix: clSRPGSConnectVTable
// R6GameService.dll data @ 10078140 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSRPGSConnectVTableRecord {
  R6GameServiceNative::Address clSRPGSConnectDelete; // +0x00
  R6GameServiceNative::Address RejectChannelStart; // +0x04
  R6GameServiceNative::Address CloseAssociatedOwner; // +0x08
  R6GameServiceNative::Address clSRPGSConnectTakeMessage; // +0x0c
};
const clSRPGSConnectVTableRecord clSRPGSConnectVTable = {
  R6GameServiceAddresses::clSRPGSConnectDelete,
  R6GameServiceAddresses::RejectChannelStart,
  R6GameServiceAddresses::CloseAssociatedOwner,
  R6GameServiceAddresses::clSRPGSConnectTakeMessage,
};
