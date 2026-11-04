#include "native_addresses.h"
#include "native_records.h"

// clSRPClient: RTTI-backed native class; original declarations and member spellings remain inferred.

// Destroy members before sampling the current deletion flag; optionally release storage and return the cached receiver.
// R6GameService.dll @ 10059760 : full physical flags word; only bit 0 controls storage ownership.
void * __thiscall clSRPClientDelete(void *owner,uint deleteFlags)
{
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::clSRPClientDestroy)(owner);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Restore the derived client identity before forwarding the receiver to shared base destruction.
// R6GameService.dll @ 10059780 : native tail alias; shared cleanup's full return word is retained.
uint __fastcall clSRPClientDestroy(void *owner)
{
  *(uint *)owner = R6GameServiceAddresses::clSRPClientVTable;
  using DestroyABI = uint (__fastcall *)(void *);
  return ((DestroyABI)R6GameServiceAddresses::DestroyLargeRecordOwner)(owner);
}

// Store08/full and8e/11a lowWORD; find/create association with full mode, publish120, then enter state2 and format
// current08.
// Build owned segment28/payload20; ignore capacity result, write negotiation bytes through cached allocation+12 and
// headers through current18.
// Inline seeded0 checksum uses signed parity/count and independent10/18 fields; submit through current120.
// Both send paths current-virtually delete record with full flag1, then set only AL status. Preserve partial setup,
// ECX0/RET16, no own EH.
// R6GameService.dll @ 1005eb00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeOwnerAndSendNegotiationRecord(
    void *owner,uint field08Word,uint field8eWord,uint field11aWord,uint modeWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0x8]
    push    ebp
    mov    dx,WORD PTR [esp+0x14]
    push    esi
    push    edi
    mov    edi,ecx
    mov    cx,WORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0xc],0x0
    mov    DWORD PTR [edi+0x8],eax
    mov    WORD PTR [edi+0x8e],cx
    mov    ecx,DWORD PTR [esp+0x20]
    lea    eax,[edi+0x11a]
    lea    ebp,[edi+0x11c]
    push    ecx
    mov    WORD PTR [eax],dx
    mov    edx,DWORD PTR [edi+0x94]
    push    edi
    push    ebp
    push    eax
    push    edx
    call    R6GameServiceAddresses::FindOrCreateKeyedRecord
    test    eax,eax
    mov    DWORD PTR [edi+0x120],eax
    jne    Branch2
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    pop    ecx
    ret    0x10
  Branch2:
    mov    ecx,edi
    call    R6GameServiceAddresses::BeginOwnerStateTwo
    test    al,al
    jne    Branch3
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret    0x10
  Branch3:
    mov    eax,DWORD PTR [edi+0x8]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::SetIPv4AddressAndFormatText
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    test    esi,esi
    je    Branch8
    push    0x14
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    mov    DWORD PTR [esi+0x14],0x14
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x18],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPSegmentVTable
    mov    cx,WORD PTR [edi+0x1b6]
    push    ebx
    mov    ebx,eax
    push    ecx
    mov    ecx,DWORD PTR [edi+0x120]
    add    ebx,0xc
    call    R6GameServiceAddresses::EnsureReceiveBufferCapacity
    mov    dx,WORD PTR [ebp+0x0]
    mov    WORD PTR [ebx+0x2],dx
    mov    ax,WORD PTR [edi+0x1b2]
    mov    WORD PTR [ebx+0x4],ax
    mov    cx,WORD PTR [edi+0x1b0]
    mov    WORD PTR [ebx],cx
    mov    dx,WORD PTR [edi+0x1b8]
    mov    WORD PTR [ebx+0x6],dx
    mov    ax,WORD PTR [edi+0x8e]
    mov    ecx,DWORD PTR [edi+0x8]
    mov    WORD PTR [esi+0xc],ax
    mov    eax,DWORD PTR [esi+0x18]
    xor    ebx,ebx
    mov    DWORD PTR [esi+0x8],ecx
    mov    WORD PTR [eax+0x2],bx
    mov    WORD PTR [eax+0x6],0x3042
    mov    edx,DWORD PTR [esi+0x18]
    mov    WORD PTR [edx+0x4],0x8
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x8],bx
    mov    edx,DWORD PTR [esi+0x18]
    mov    ecx,DWORD PTR [esi+0x14]
    xor    eax,eax
    mov    WORD PTR [edx],bx
    mov    edx,DWORD PTR [esi+0x14]
    sar    ecx,1
    and    edx,0x80000001
    jns    Branch4
    dec    edx
    or    edx,0xfffffffe
    inc    edx
  Branch4:
    mov    edx,DWORD PTR [esi+0x10]
    je    Branch5
    movsx    eax,BYTE PTR [edx]
    inc    edx
  Branch5:
    cmp    ecx,ebx
    jle    Branch7
  Branch6:
    xor    ebx,ebx
    mov    bx,WORD PTR [edx]
    add    edx,0x2
    add    eax,ebx
    dec    ecx
    jne    Branch6
  Branch7:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    push    esi
    mov    eax,ecx
    shr    eax,0x10
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x18]
    not    eax
    mov    WORD PTR [ecx],ax
    mov    ecx,DWORD PTR [edi+0x120]
    call    R6GameServiceAddresses::SendKeyedRecordPayload
    pop    ebx
    mov    ecx,esi
    test    al,al
    push    0x1
    jne    Branch9
    mov    edx,DWORD PTR [esi]
    call    DWORD PTR [edx]
  Branch8:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebp
    pop    ecx
    ret    0x10
  Branch9:
    mov    eax,DWORD PTR [esi]
    call    DWORD PTR [eax]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebp
    pop    ecx
    ret    0x10
  }
}

// Native virtual-table prefix: clSRPClientVTable
// R6GameService.dll data @ 10078170 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSRPClientVTableRecord {
  R6GameServiceNative::Address clSRPClientDelete; // +0x00
  R6GameServiceNative::Address AppendOwnedRecord; // +0x04
  R6GameServiceNative::Address InitializeOwnerAndSendNegotiationRecord; // +0x08
  R6GameServiceNative::Address clSRProtocol_RejectSRProtocolCall; // +0x0c
  R6GameServiceNative::Address clSRProtocol_RejectSRProtocolCall2; // +0x10
  R6GameServiceNative::Address ReturnZero; // +0x14
};
const clSRPClientVTableRecord clSRPClientVTable = {
  R6GameServiceAddresses::clSRPClientDelete,
  R6GameServiceAddresses::AppendOwnedRecord,
  R6GameServiceAddresses::InitializeOwnerAndSendNegotiationRecord,
  R6GameServiceAddresses::clSRProtocol_RejectSRProtocolCall,
  R6GameServiceAddresses::clSRProtocol_RejectSRProtocolCall2,
  R6GameServiceAddresses::ReturnZero,
};
