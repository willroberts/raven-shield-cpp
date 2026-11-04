#include "native_addresses.h"
#include "native_records.h"

// Identified allocation base class: native COL100784c8/type1008c3c4 names clExtalloc_Override_Baseclass.

// Restores the allocation base table without releasing storage; this destructor produces no return value.
// R6GameService.dll @ 10037840 : inferred void cleanup, ECX owner; native EAX remains unchanged.
void __fastcall DestroyExtallocOverrideBase(uint *owner)
{
  *owner = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
}

// Captures the low deletion bit before resetting the base table, optionally frees storage and returns the owner.
// R6GameService.dll @ 10016230 : ECX owner, physical flag word, RET4; low byte is read before the table store.
void * __thiscall DeleteExtallocOverrideBase(void *owner,uint deletionFlags)
{
  byte capturedFlags = (byte)deletionFlags;
  void *savedOwner = owner;
  *(uint *)savedOwner = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  if ((capturedFlags & 1) != 0) TailFreeThroughGlobalAllocator(savedOwner);
  return savedOwner;
}

// Native virtual-table prefix: clExtalloc_Override_BaseclassVTable
// R6GameService.dll data @ 10075bdc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clExtalloc_Override_BaseclassVTableRecord {
  R6GameServiceNative::Address DeleteExtallocOverrideBase; // +0x00
};
const clExtalloc_Override_BaseclassVTableRecord clExtalloc_Override_BaseclassVTable = {
  R6GameServiceAddresses::DeleteExtallocOverrideBase,
};
