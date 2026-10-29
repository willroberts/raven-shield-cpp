#include "native_symbols.hpp"
// Executable type_info deletion wrappers; imported MSVCR71 owns the scalar destructor implementation.
#include "allocation_support.hpp"
#include "vector_runtime.hpp"
#include "type_metadata.hpp"

class type_info;

// RavenShield.exe data @ 1091f0e0 : g_typeInfoTypeDescriptor
NativeTypeDescriptor<16> g_typeInfoTypeDescriptor = {NativeAddress(g_typeInfoDeletingSlot), 0, ".?AVtype_info@@"};

// RavenShield.exe data @ 10918348 : g_typeInfoBaseDescriptor
const NativeRttiBaseDescriptor g_typeInfoBaseDescriptor = {NativeAddress(g_typeInfoTypeDescriptor), 0, {0, -1, 0}, 0};
// RavenShield.exe data @ 10918360 : g_typeInfoBaseArray
const uint32_t g_typeInfoBaseArray[1] = {NativeAddress(g_typeInfoBaseDescriptor)};
// RavenShield.exe data @ 10918368 : g_typeInfoHierarchy
const NativeRttiHierarchy g_typeInfoHierarchy = {0, 0, 1, NativeAddress(g_typeInfoBaseArray)};
// RavenShield.exe data @ 10918378 : g_typeInfoCompleteObjectLocator
const NativeRttiCompleteObjectLocator g_typeInfoCompleteObjectLocator = {
    0, 0, 0, NativeAddress(g_typeInfoTypeDescriptor), NativeAddress(g_typeInfoHierarchy)};
// RavenShield.exe data @ 109182a4 : g_typeInfoLocatorSlot
const uint32_t g_typeInfoLocatorSlot =
    NativeAddress(g_typeInfoCompleteObjectLocator); // Word before the vtable, not another virtual method.

// RavenShield.exe data @ 109182a8 : g_typeInfoDeletingSlot
const uint32_t g_typeInfoDeletingSlot =
    NativeAddress(NativeEntry_type_info_VectorDeletingDestructor); // Observed virtual slot; no larger table inferred.

// RavenShield.exe @ 10911c1d : type_info::VectorDeletingDestructor
// Destroy a scalar or count-prefixed array, optionally free it, and return the original object/allocation address.
void *type_info::VectorDeletingDestructor(uint32_t flags)
{
  const uint8_t savedFlags = static_cast<uint8_t>(flags); // Native caches BL before any destructor callback.
  type_info *object = this;
  if ((savedFlags & 2u) != 0)
  {
    auto *allocation = reinterpret_cast<uint8_t *>(reinterpret_cast<uintptr_t>(object) - 4u);
    const int32_t count = *reinterpret_cast<const int32_t *>(allocation);
    const auto destructor =
        reinterpret_cast<ExecutableElementDestructor>(NativeAddress(NativeEntry_type_info_Destroytype_info));
    DestroyExecutableVector(object, 0xc, count, destructor);
    if ((savedFlags & 1u) != 0) FreeExecutableAllocation(allocation);
    return allocation;
  }
  object->type_info::~type_info(); // Qualified call reaches the scalar thunk rather than virtual deletion.
  if ((savedFlags & 1u) != 0) FreeExecutableAllocation(object);
  return object;
} // Native ECX receiver, one flags word/RET 4 and complete EAX pointer; destructor failure skips deallocation.

// RavenShield.exe @ 10911f6a : type_info::~type_info
// Tail-forward the ECX object to the imported scalar destructor without adding local work or cleanup.
__declspec(naked) type_info::~type_info()
{
  __asm jmp dword ptr [NativeImport_type_infoDestroy]
}
