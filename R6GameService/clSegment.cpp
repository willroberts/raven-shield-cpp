#include "native_addresses.h"
#include "native_records.h"

// clSegment: RTTI-backed native class; original member spellings and full declarations remain unresolved.

// clSegment scalar deleting destructor: cache buffer10 before installing base vptr782d8; always free cached buffer.
// Test CURRENT original lowBYTE delete flag bit0 after buffer release, optionally free cached receiver, return receiver/RET4.
// R6GameService.dll @ 1005df90 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteClSegment(void *segment,uint deleteWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    BYTE PTR [esp+0x8],0x1
    je    Branch1
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Second physical word gates optional offset782f8 at4; FIRST word supplies stored size14 and malloc request.
// Install base primary782d8 before allocation, publish literal result at10/18 and return original receiver/RET8 with ECX0. No local EH.
// R6GameService.dll @ 1005dc60 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeOwnedByteRecord(
    void *record,uint storageBytes,uint initializeSharedWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0xc]
    push    esi
    test    eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je    Branch2
    mov    DWORD PTR [esi+0x4],0x100782f8
  Branch2:
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    push    eax
    mov    DWORD PTR [esi+0x14],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x18],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Native virtual-table prefix: clSegmentVTable
// R6GameService.dll data @ 100782d8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSegmentVTableRecord {
  R6GameServiceNative::Address DeleteClSegment; // +0x00
};
const clSegmentVTableRecord clSegmentVTable = {R6GameServiceAddresses::DeleteClSegment};
