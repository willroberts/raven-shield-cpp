#include "native_addresses.h"
#include "native_records.h"

// Native primary75bbc/COL785a8/type8c428 names clTCPClient; original destructor spellings are descriptive.

// Runs the shared base destructor, reloads the low deletion flag, optionally frees storage and returns the owner.
// R6GameService.dll @ 10017010 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyHttpClient(void *owner,uint deletionFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyHttpClientBase
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Tail-forwards the unchanged receiver to the separately represented shared base destructor, retaining its EAX.
// R6GameService.dll @ 10017030 : JMP1002e620 only; no duplicate expanded base body or local EH frame.
__declspec(naked) uint __fastcall DestroyHttpClientBase(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyQueuedConnectionMembers
  }
}

// Native virtual-table prefix: clTCPClientVTable
// R6GameService.dll data @ 10075bbc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clTCPClientVTableRecord {
  R6GameServiceNative::Address DestroyHttpClient; // +0x00
};
const clTCPClientVTableRecord clTCPClientVTable = {R6GameServiceAddresses::DestroyHttpClient};
