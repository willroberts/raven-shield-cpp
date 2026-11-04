#include "native_addresses.h"
#include "native_records.h"

// clSRPSegment: RTTI-backed native class; original member spellings and full declarations remain unresolved.

// clSRPSegment scalar deleting destructor: destroy owned bytes, then test CURRENT original flag lowBYTE bit0.
// Optional cached receiver free follows member destruction; return original receiver/RET4 without clearing fields.
// R6GameService.dll @ 1005e400 : complete native control/access order and raw ABI retained.
void *__thiscall DeleteClSRPSegment(void *segment,uint deleteWord)
{
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyClSRPSegment)(segment);
  if ((*(byte *)&deleteWord & 1) != 0) TailFreeThroughGlobalAllocator(segment);
  return segment;
}

// clSRPSegment destructor caches buffer10, installs clSegment vptr782d8, then frees cached buffer even if NULL.
// Keep stale buffer/mirror fields and raw allocator EAX; no local EH or derived-table installation.
// R6GameService.dll @ 1005e420 : complete native control/access order and raw ABI retained.
uint __fastcall DestroyClSRPSegment(void *segment)
{
  void *buffer = *(void **)((uint)segment + 0x10);
  *(uint *)segment = R6GameServiceAddresses::clSegmentVTable;
  return TailFreeThroughGlobalAllocator(buffer);
}

// Native virtual-table prefix: clSRPSegmentVTable
// R6GameService.dll data @ 100782d0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSRPSegmentVTableRecord {
  R6GameServiceNative::Address DeleteClSRPSegment; // +0x00
};
const clSRPSegmentVTableRecord clSRPSegmentVTable = {R6GameServiceAddresses::DeleteClSRPSegment};
