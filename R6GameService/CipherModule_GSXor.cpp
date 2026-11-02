#include "native_addresses.h"
#include "native_records.h"

// Identified native class: CipherModule_GSXor, COL10079354/type1008e7e0, primary table10077928.
// The +0x0c allocation is CGSXor, COL100793a0/type1008e804; its constructor is inlined here.

// Destroys the GSXor module and conditionally releases storage, returning the original receiver.
// R6GameService.dll @ 10037850 : ECX receiver, flags stack word, RET4; primary table10077928 slot0.
void * __thiscall DeleteCipherModuleGSXor(void *owner,byte flags)
{
  DestroyCipherModuleGSXor((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Constructs the GSXor module and its eight-byte CGSXor state, ignoring both supplied key words.
// R6GameService.dll @ 10037870 : ECX receiver, ignored key/length and virtual-base words, RET0x0c; EAX=receiver.
void * __thiscall ConstructCipherModuleGSXor(
    void *owner,uint unusedKeyWord,uint unusedLengthWord,uint initializeBase)
{
  if (initializeBase != 0) *(uint *)((uint)owner + 4) = 0x1007793c;
  *(uint *)((uint)owner + 8) = 1;
  *(uint *)owner = R6GameServiceAddresses::CipherModule_GSXorVTable;
  uint *state = (uint *)AllocateGameServiceBytes(8);
  if (state != 0) {
    state[1] = 0x1007791c;
    state[0] = R6GameServiceAddresses::CGSXorVTable;
  }
  *(uint **)((uint)owner + 0x0c) = state;
  return owner;
}

// Deletes CGSXor state, clears +0x0c and restores the base table using the shared native destructor unwind map.
// R6GameService.dll @ 100378d0 : ECX receiver, plain RET; EAX=old chain if no state, otherwise virtual-delete residue.
uint __fastcall DestroyCipherModuleGSXor(uint *owner)
{
  CipherModuleDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CipherModuleDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = owner;
  owner[0] = R6GameServiceAddresses::CipherModule_GSXorVTable;
  void *state = (void *)owner[3];
  frame.state = 0;
  uint result = (uint)frame.previousExceptionList;
  if (state != 0) {
    void **table = *(void ***)state;
    result = ((uint (__thiscall *)(void *,uint))table[0])(state,1);
  }
  owner[3] = 0;
  owner[0] = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Accepts any key without accessing receiver or arguments; sets only AL to one.
// R6GameService.dll @ 10037930 : ECX unused, two ignored stack words, RET8; high EAX bits preserved.
__declspec(naked) uint __thiscall AcceptCipherModuleGSXorKey(void *owner,uint keyWord,uint lengthWord)
{
  __asm {
    mov    al,1
    ret    8
  }
}

// Requires exact capacity, copies in native word/byte groups, then masks and transposes the output in place.
// R6GameService.dll @ 10037940 : ECX receiver, four stack words, RET0x10; sets only AL after helper or failure.
__declspec(naked) uint __thiscall EncodeCipherModuleGSXorBuffer(
    void *owner,const byte *source,uint byteCount,byte *destination,uint *destinationByteCount)
{
  __asm {
    mov    eax,dword ptr [esp+0xc]
    mov    edx,dword ptr [esp+0x10]
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0x10]
    mov    ebx,ecx
    test   eax,eax
    jz     capacity_mismatch
    mov    ecx,dword ptr [edx]
    cmp    ecx,esi
    jne    capacity_mismatch
    mov    esi,dword ptr [esp+0xc]
    push   ebp
    mov    ebp,ecx
    push   edi
    mov    edi,eax
    shr    ecx,2
    rep movsd
    mov    ecx,ebp
    and    ecx,3
    rep movsb
    mov    ecx,dword ptr [edx]
    push   ecx
    mov    ecx,dword ptr [ebx+0xc]
    push   eax
    call   R6GameServiceAddresses::EncodeMaskedSquareTransposition
    pop    edi
    pop    ebp
    pop    esi
    mov    al,1
    pop    ebx
    ret    0x10
  capacity_mismatch:
    mov    dword ptr [edx],esi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x10
  }
}

// Requires exact capacity, copies in native word/byte groups, then reverses transposition and masking in place.
// R6GameService.dll @ 10037990 : ECX receiver, four stack words, RET0x10; sets only AL after helper or failure.
__declspec(naked) uint __thiscall DecodeCipherModuleGSXorBuffer(
    void *owner,const byte *source,uint byteCount,byte *destination,uint *destinationByteCount)
{
  __asm {
    mov    eax,dword ptr [esp+0xc]
    mov    edx,dword ptr [esp+0x10]
    push   ebx
    push   esi
    mov    esi,dword ptr [esp+0x10]
    mov    ebx,ecx
    test   eax,eax
    jz     capacity_mismatch
    mov    ecx,dword ptr [edx]
    cmp    ecx,esi
    jne    capacity_mismatch
    mov    esi,dword ptr [esp+0xc]
    push   ebp
    mov    ebp,ecx
    push   edi
    mov    edi,eax
    shr    ecx,2
    rep movsd
    mov    ecx,ebp
    and    ecx,3
    rep movsb
    mov    ecx,dword ptr [edx]
    push   ecx
    mov    ecx,dword ptr [ebx+0xc]
    push   eax
    call   R6GameServiceAddresses::DecodeMaskedSquareTransposition
    pop    edi
    pop    ebp
    pop    esi
    mov    al,1
    pop    ebx
    ret    0x10
  capacity_mismatch:
    mov    dword ptr [edx],esi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x10
  }
}

// Native virtual-table prefix: CipherModule_GSXorVTable
// R6GameService.dll data @ 10077928 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CipherModule_GSXorVTableRecord {
  R6GameServiceNative::Address DeleteCipherModuleGSXor; // +0x00
  R6GameServiceNative::Address AcceptCipherModuleGSXorKey; // +0x04
  R6GameServiceNative::Address list_node_support_NoOp; // +0x08
  R6GameServiceNative::Address EncodeCipherModuleGSXorBuffer; // +0x0c
  R6GameServiceNative::Address DecodeCipherModuleGSXorBuffer; // +0x10
};
const CipherModule_GSXorVTableRecord CipherModule_GSXorVTable = {
  R6GameServiceAddresses::DeleteCipherModuleGSXor,
  R6GameServiceAddresses::AcceptCipherModuleGSXorKey,
  R6GameServiceAddresses::list_node_support_NoOp,
  R6GameServiceAddresses::EncodeCipherModuleGSXorBuffer,
  R6GameServiceAddresses::DecodeCipherModuleGSXorBuffer,
};
