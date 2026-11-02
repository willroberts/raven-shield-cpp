#include "native_addresses.h"
#include "native_records.h"

// Constructs a D3-tagged clCDKeyMessage from a source list and the shared codec.
// R6GameService.dll @ 1002d1b0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall InitializeCodecBackedPayload(void *object,void *source,int initializeSecondaryTable)
{
  __asm {
    // Clear saved ECX scratch, optionally install CD-key secondary table, and stage source before shared-codec lookup.
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je Branch1
    mov    DWORD PTR [esi+0x4],0x10076c08
  Branch1:
    mov    eax,DWORD PTR [esp+0xc]
    push   0x0
    push   eax
    call   R6GameServiceAddresses::GetDefaultTaggedPayloadCodec
    // Call base constructor with tagD3 and secondary-table flag zero, then install CD-key primary table.
    push   eax
    push   0xd3
    mov    ecx,esi
    call   R6GameServiceAddresses::InitializeTaggedPayload
    mov    DWORD PTR [esi],R6GameServiceAddresses::clCDKeyMessageVTable
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Constructs a D3-tagged clCDKeyMessage from a matching serialized record and the shared codec.
// R6GameService.dll @ 1002d200 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall InitializeSerializedPayload(void *object,byte *bytes,uint byteCount,int initializeSecondaryTable)
{
  __asm {
    // Clear saved ECX scratch and stage cached input/count before shared-codec lookup.
    push   ecx
    mov    eax,DWORD PTR [esp+0x10]
    push   esi
    test   eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je Branch2
    mov    DWORD PTR [esi+0x4],0x10076c08
  Branch2:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xc]
    push   0x0
    push   eax
    push   ecx
    call   R6GameServiceAddresses::GetDefaultTaggedPayloadCodec
    // Call base record constructor with tagD3 and secondary-table flag zero, then install CD-key primary table.
    push   eax
    push   0xd3
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTaggedPayload
    mov    DWORD PTR [esi],R6GameServiceAddresses::clCDKeyMessageVTable
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0xc
  }
}

// Runs CD-key message cleanup and optionally releases receiver storage, returning the saved receiver.
// R6GameService.dll @ 10028eb0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall DeleteClCDKeyMessage(void *object,byte flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyClCDKeyMessage
    test   BYTE PTR [esp+0x8],0x1
    je Branch3
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Installs the CD-key message table and tail-forwards clSimpleMessage field cleanup.
// R6GameService.dll @ 10028ed0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall DestroyClCDKeyMessage(void *object)
{
  __asm {
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clCDKeyMessageVTable
    jmp    R6GameServiceAddresses::DestroyTaggedPayloadFields
  }
}

// Tail-forwards the canonical CD-key message destructor body without duplicating its implementation.
// R6GameService.dll @ 10028ee0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall DestroyClCDKeyMessageAlias(void *object)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClCDKeyMessage
  }
}

// Native virtual-table prefix: clCDKeyMessageVTable
// R6GameService.dll data @ 10076acc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clCDKeyMessageVTableRecord {
  R6GameServiceNative::Address DeleteClCDKeyMessage; // +0x00
};
const clCDKeyMessageVTableRecord clCDKeyMessageVTable = {R6GameServiceAddresses::DeleteClCDKeyMessage};
