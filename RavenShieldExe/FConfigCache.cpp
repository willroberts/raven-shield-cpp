#include "native_symbols.hpp"
// Native abstract configuration-cache base support.
#include "allocation_support.hpp"

// RavenShield.exe data @ 10914ad8 : g_configCacheBaseVtable
// Native abstract primary table: 24 pure-virtual entries followed by the base deleting-destructor entry.
const uint32_t g_configCacheBaseVtable[25] = {
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +000 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +004 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +008 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +00c ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +010 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +014 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +018 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +01c ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +020 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +024 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +028 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +02c ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +030 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +034 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +038 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +03c ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +040 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +044 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +048 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +04c ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +050 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +054 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +058 ForwardExecutablePureCall
    NativeAddress(NativeEntry_ForwardExecutablePureCall),             // +05c ForwardExecutablePureCall
    NativeAddress(NativeEntry_FConfigCache_ScalarDeletingDestructor), // +060 FConfigCache::ScalarDeletingDestructor
};

// RavenShield.exe @ 10901ed0 : FConfigCache::~FConfigCache
// Restore the base pure-virtual table without freeing or clearing the derived object's storage.
FConfigCache::~FConfigCache() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_configCacheBaseVtable;
}

// RavenShield.exe @ 109044e0 : FConfigCache::ScalarDeletingDestructor
// Select the abstract base table, optionally free through the current allocator, and return the saved receiver.
FConfigCache *FConfigCache::ScalarDeletingDestructor(uint32_t flags)
{
  const bool freeStorage = (static_cast<uint8_t>(flags) & 1u) != 0; // Native tests the low byte before the table store.
  FConfigCache *object = this;
  object->FConfigCache::~FConfigCache(); // The native body inlines this table-only base destructor.
  if (freeStorage) FreeExecutableAllocation(object);
  return object;
} // Native RET 4 consumes flags; EAX retains the original receiver, even after freeing it. No local SEH guard.
