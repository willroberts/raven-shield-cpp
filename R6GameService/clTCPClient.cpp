#include "native_addresses.h"
#include "native_records.h"

// Native primary75bbc/COL785a8/type8c428 names clTCPClient; original destructor spellings are descriptive.

// Destroy the shared client base, then conditionally free the cached owner using the current low deletion bit.
// R6GameService.dll @ 10017010 : selected PE32 operations; helper/type names remain descriptive.
void * __thiscall DestroyHttpClient(void *owner,uint deletionFlags)
{
  using DestroyABI = void (__thiscall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyHttpClientBase)(owner);
  if ((deletionFlags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Forward the receiver to the canonical queued-connection destructor, retaining its raw result-word view.
// R6GameService.dll @ 10017030 : selected PE32 operations; helper/type names remain descriptive.
uint __fastcall DestroyHttpClientBase(void *owner)
{
  using DestroyABI = uint (__thiscall *)(void *);
  return ((DestroyABI)R6GameServiceAddresses::DestroyQueuedConnectionMembers)(owner);
}

// Native virtual-table prefix: clTCPClientVTable
// R6GameService.dll data @ 10075bbc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clTCPClientVTableRecord {
  R6GameServiceNative::Address DestroyHttpClient; // +0x00
};
const clTCPClientVTableRecord clTCPClientVTable = {R6GameServiceAddresses::DestroyHttpClient};
