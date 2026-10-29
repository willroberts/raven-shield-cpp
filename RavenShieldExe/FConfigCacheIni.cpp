#include "native_symbols.hpp"
// Native configuration-cache lifecycle, lookup and access; offsets retain the selected four-string layout.
#include "cpp_exception_metadata.hpp"
#include "allocation_support.hpp"
#include "container_support.hpp"
#include "launch_runtime.hpp"
#include <malloc.h>

class FConfigCache;
class FConfigCacheIni;
using NativeConfigFlush = void(__thiscall *)(FConfigCacheIni *, int32_t, const uint16_t *);
class FString;
class FConfigFile;
template <class Key, class Value> class TMap;
template <class Key, class Value> class TMapBase;
template <class Key, class Value> class TMultiMap;
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();
extern "C" void HandleConfigCacheFactoryException();

// RavenShield.exe data @ 10917898 : g_configCacheIniVtable
// Native derived cache slots preserve the complete abstract interface order and class-specific deleting entry.
const uint32_t g_configCacheIniVtable[25] = {
    NativeAddress(NativeEntry_FConfigCacheIni_GetBool),             // +000 FConfigCacheIni::GetBool
    NativeAddress(NativeEntry_FConfigCacheIni_GetInt),              // +004 FConfigCacheIni::GetInt
    NativeAddress(NativeEntry_FConfigCacheIni_GetFloat),            // +008 FConfigCacheIni::GetFloat
    NativeAddress(NativeEntry_FConfigCacheIni_GetStringIntoString), // +00c FConfigCacheIni::GetString
    NativeAddress(NativeEntry_FConfigCacheIni_GetStringIntoBuffer), // +010 FConfigCacheIni::GetString
    NativeAddress(NativeEntry_FConfigCacheIni_GetStr),              // +014 FConfigCacheIni::GetStr
    NativeAddress(NativeEntry_FConfigCacheIni_GetSection),          // +018 FConfigCacheIni::GetSection
    NativeAddress(NativeEntry_FConfigCacheIni_GetSectionPrivate),   // +01c FConfigCacheIni::GetSectionPrivate
    NativeAddress(NativeEntry_FConfigCacheIni_EmptySection),        // +020 FConfigCacheIni::EmptySection
    NativeAddress(NativeEntry_FConfigCacheIni_SetBool),             // +024 FConfigCacheIni::SetBool
    NativeAddress(NativeEntry_FConfigCacheIni_SetInt),              // +028 FConfigCacheIni::SetInt
    NativeAddress(NativeEntry_FConfigCacheIni_SetFloat),            // +02c FConfigCacheIni::SetFloat
    NativeAddress(NativeEntry_FConfigCacheIni_SetString),           // +030 FConfigCacheIni::SetString
    NativeAddress(NativeEntry_FConfigCacheIni_Flush),               // +034 FConfigCacheIni::Flush
    NativeAddress(NativeEntry_FConfigCacheIni_Cancel),              // +038 FConfigCacheIni::Cancel
    NativeAddress(NativeEntry_FConfigCacheIni_Init),                // +03c FConfigCacheIni::Init
    NativeAddress(NativeEntry_FConfigCacheIni_InitUser),            // +040 FConfigCacheIni::InitUser
    NativeAddress(NativeEntry_FConfigCacheIni_InitServer),          // +044 FConfigCacheIni::InitServer
    NativeAddress(NativeEntry_FConfigCacheIni_GetUserIni),          // +048 FConfigCacheIni::GetUserIni
    NativeAddress(NativeEntry_FConfigCacheIni_GetServerIni),        // +04c FConfigCacheIni::GetServerIni
    NativeAddress(NativeEntry_FConfigCacheIni_Exit),                // +050 FConfigCacheIni::Exit
    NativeAddress(NativeEntry_FConfigCacheIni_Dump),                // +054 FConfigCacheIni::Dump
    NativeAddress(NativeEntry_FConfigCacheIni_PBfindKey),           // +058 FConfigCacheIni::PBfindKey
    NativeAddress(NativeEntry_FConfigCacheIni_PBgetSection),        // +05c FConfigCacheIni::PBgetSection
    NativeAddress(
        NativeEntry_FConfigCacheIni_ScalarDeletingDestructor), // +060 FConfigCacheIni::ScalarDeletingDestructor
};

// RavenShield.exe data @ 109178fc : g_configCacheInitGuardName
const char16_t g_configCacheInitGuardName[] = u"FConfigCacheIni::Init";
// RavenShield.exe data @ 10917f98 : g_configCacheDestructorGuardName
const char16_t g_configCacheDestructorGuardName[] = u"FConfigCacheIni::~FConfigCacheIni";
// RavenShield.exe data @ 10917d34 : g_configCacheFlushGuardName
const char16_t g_configCacheFlushGuardName[] = u"FConfigCacheIni::Flush";

// RavenShield.exe @ 1090de60 : FConfigCacheIni::FConfigCacheIni
// Construct the map and four strings in order; completed bases/members unwind automatically on a later failure.
FConfigCacheIni::FConfigCacheIni()
    : FConfigCache(), TMap<FString, FConfigFile>(), SystemIni(), UserIni(), ServerIni(), UserIniPrefix()
{
  // Base table 10914ad8 precedes map construction; derived table 10917898 precedes string construction.
  // Map +4; SystemIni +18, UserIni +24, ServerIni +30, and UserIniPrefix +3c precedes UserIni in generic-name lookup.
}

// RavenShield.exe @ 10912ad0 : UnwindConfigCacheBase
// Destroy the completed abstract base from the constructor's runtime parent-frame object slot.
__declspec(naked) void UnwindConfigCacheBase()
{
  __asm {
    mov ecx, [ebp-14h]
    jmp FConfigCache::~FConfigCache
  }
}

// RavenShield.exe @ 10912ad8 : UnwindConfigCachePairs
// Destroy only the completed pair array when map construction has not yet completed.
__declspec(naked) void UnwindConfigCachePairs()
{
  __asm {
    mov ecx, [ebp-10h]
    // Specialized config-file pair array; ECX already points to cache +4.
    jmp NativeEntry_TArray_TMapBase_FString_FConfigFile_TPair_DestroyTArray
  }
}

// RavenShield.exe @ 10912ae0 : UnwindConfigCacheMap
// Destroy the completed map base at object +4 after a later string-construction failure.
__declspec(naked) void UnwindConfigCacheMap()
{
  __asm {
    mov ecx, [ebp-14h]
    add ecx, 4
    jmp NativeEntry_DestroyConfigFileMapThunk // Forwarding map-destructor thunk.
  }
}

// RavenShield.exe @ 10912aeb : UnwindConfigCacheSystemIni
// Destroy the completed string at object +18 while unwinding a later construction state.
__declspec(naked) void UnwindConfigCacheSystemIni()
{
  __asm {
    mov ecx, [ebp-14h]
    add ecx, 18h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912af7 : UnwindConfigCacheUserIni
// Destroy the completed string at object +24 while unwinding a later construction state.
__declspec(naked) void UnwindConfigCacheUserIni()
{
  __asm {
    mov ecx, [ebp-14h]
    add ecx, 24h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912b03 : UnwindConfigCacheString30
// Destroy the completed ServerIni at object +30 if construction of the final string fails.
__declspec(naked) void UnwindConfigCacheString30()
{
  __asm {
    mov ecx, [ebp-14h]
    add ecx, 30h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091a188 : g_configCacheConstructionUnwind
const NativeCppUnwindEntry g_configCacheConstructionUnwind[6] = {
    {-1, NativeAddress(NativeEntry_UnwindConfigCacheBase)},     // UnwindConfigCacheBase
    {0, NativeAddress(NativeEntry_UnwindConfigCachePairs)},     // UnwindConfigCachePairs
    {0, NativeAddress(NativeEntry_UnwindConfigCacheMap)},       // UnwindConfigCacheMap
    {2, NativeAddress(NativeEntry_UnwindConfigCacheSystemIni)}, // UnwindConfigCacheSystemIni
    {3, NativeAddress(NativeEntry_UnwindConfigCacheUserIni)},   // UnwindConfigCacheUserIni
    {4, NativeAddress(NativeEntry_UnwindConfigCacheString30)},  // UnwindConfigCacheString30
};

// RavenShield.exe data @ 1091a1b8 : g_configCacheConstructionExceptionInfo
const NativeCppFunctionInfo g_configCacheConstructionExceptionInfo = {
    0x19930520, 6, NativeAddress(g_configCacheConstructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912b0f : HandleConfigCacheConstructionException
// Dispatch the constructor's six partial-construction states; member offsets remain explicit in its unwind map.
__declspec(naked) void HandleConfigCacheConstructionException()
{
  __asm {
    mov eax, offset g_configCacheConstructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10910d70 : FConfigCacheIni::Factory
// Allocate 48h bytes, construct only on success, and register allocation cleanup for a constructor exception.
__declspec(naked) FConfigCache *__cdecl FConfigCacheIni::Factory()
{
  __asm {
    push -1
    push offset HandleConfigCacheFactoryException
    mov eax, fs:[0]
    push eax
    mov fs:[0], esp
    push ecx // Native allocation-pointer slot; this is not a fastcall argument.
    mov eax, dword ptr [NativeImport_GMalloc] // IAT address of Core.dll GMalloc pointer variable.
    mov ecx, [eax]
    mov edx, [ecx]
    push offset g_executableAllocationTag
    push 48h
    call dword ptr [edx]
    mov [esp], eax
    test eax, eax
    mov dword ptr [esp+0ch], 0
    je allocationFailed
    mov ecx, eax
    call FConfigCacheIni::FConfigCacheIni
    mov ecx, [esp+4]
    mov fs:[0], ecx
    add esp, 10h
    ret
  allocationFailed:
    mov ecx, [esp+4]
    xor eax, eax
    mov fs:[0], ecx
    add esp, 10h
    ret
  }
}

// RavenShield.exe @ 10912e90 : FreeFailedConfigCacheAllocation
// Free the failed factory allocation from the runtime-supplied parent frame's EBP-10 slot.
__declspec(naked) void FreeFailedConfigCacheAllocation()
{
  __asm {
    mov eax, [ebp-10h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 1091aedc : g_configCacheFactoryUnwind
const NativeCppUnwindEntry g_configCacheFactoryUnwind[1] = {
    {-1, NativeAddress(NativeEntry_FreeFailedConfigCacheAllocation)}, // FreeFailedConfigCacheAllocation
};

// RavenShield.exe data @ 1091aee4 : g_configCacheFactoryExceptionInfo
const NativeCppFunctionInfo g_configCacheFactoryExceptionInfo = {
    0x19930520, 1, NativeAddress(g_configCacheFactoryUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912e9b : HandleConfigCacheFactoryException
// Dispatch factory state zero through its one-entry allocation unwind map.
extern "C" __declspec(naked) void HandleConfigCacheFactoryException()
{
  __asm {
    mov eax, offset g_configCacheFactoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090df10 : FConfigCacheIni::Init
// Assign the system/user filename strings, ignoring the third word; preserve typed-pointer and catch-all guards.
void FConfigCacheIni::Init(const uint16_t *systemIni, const uint16_t *userIni, int32_t requireConfig)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    reinterpret_cast<FString *>(object + 0x18)->operator=(systemIni);
    reinterpret_cast<FString *>(object + 0x24)->operator=(userIni);
  }
  // RavenShield.exe @ 1090df67 : RethrowConfigCacheInitPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090df7b : UnwindConfigCacheInitFailure
  // Annotate the active error with the Init guard name and rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheInitGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a1d4 : g_configCacheInitUnwind
const NativeCppUnwindEntry g_configCacheInitUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a1e4 : g_configCacheInitCatches
const NativeCppCatchHandler g_configCacheInitCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090df67}, // RethrowConfigCacheInitPointer
    {0, 0, 0, 0x1090df7b},                                               // UnwindConfigCacheInitFailure
};

// RavenShield.exe data @ 1091a204 : g_configCacheInitTryBlocks
const NativeCppTryBlock g_configCacheInitTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheInitCatches)},
};

// RavenShield.exe data @ 1091a218 : g_configCacheInitExceptionInfo
const NativeCppFunctionInfo g_configCacheInitExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheInitUnwind), 1, NativeAddress(g_configCacheInitTryBlocks), 0, 0};

// RavenShield.exe @ 10912b20 : HandleConfigCacheInitException
// Supply Init's typed/catch-all FuncInfo and preserve the runtime's exception arguments.
__declspec(naked) void HandleConfigCacheInitException()
{
  __asm {
    mov eax, offset g_configCacheInitExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10910e00 : FConfigCacheIni::~FConfigCacheIni
// Guard the direct Flush(1,nullptr) call, then destroy all four strings and bases in reverse order.
FConfigCacheIni::~FConfigCacheIni() noexcept(false)
{
  *reinterpret_cast<const uint32_t **>(this) = g_configCacheIniVtable;
  try
  {
    FConfigCacheIni::Flush(1, nullptr);
  }
  // RavenShield.exe @ 10910e9a : RethrowConfigCacheDestructorPointer
  // Throw a copy of the caught unsigned-short pointer before automatic member/base cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10910eae : UnwindConfigCacheDestructorFailure
  // Annotate a failed Flush call and rethrow; member destruction failures are outside this guard.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheDestructorGuardName));
    throw;
  }
} // UserIniPrefix, ServerIni, UserIni, SystemIni, map and abstract base also unwind after a Flush failure.

// RavenShield.exe @ 10910dd0 : FConfigCacheIni::ScalarDeletingDestructor
// Destroy the object, free it only for flags bit zero, then return the original address even after freeing it.
void *FConfigCacheIni::ScalarDeletingDestructor(uint32_t flags)
{
  FConfigCacheIni *object = this;
  object->FConfigCacheIni::~FConfigCacheIni();
  if ((flags & 1) != 0) FreeExecutableAllocation(object);
  return object;
}

// RavenShield.exe @ 10912eb0 : UnwindDestroyedConfigCacheBase
// Destroy the abstract base from the destructor's saved object slot after other subobjects have unwound.
__declspec(naked) void UnwindDestroyedConfigCacheBase()
{
  __asm {
    mov ecx, [ebp-18h]
    jmp FConfigCache::~FConfigCache
  }
}

// RavenShield.exe @ 10912eb8 : UnwindDestroyedConfigCacheMap
// Adjust a nonnull saved object by four, preserve null, then tail-transfer to the map destruction thunk.
__declspec(naked) void UnwindDestroyedConfigCacheMap()
{
  __asm {
    cmp dword ptr [ebp-18h], 0
    je nullMapBase
    mov eax, [ebp-18h]
    add eax, 4
    mov [ebp-20h], eax
    jmp destroyMapBase
  nullMapBase:
    mov dword ptr [ebp-20h], 0
  destroyMapBase:
    mov ecx, [ebp-20h]
    jmp NativeEntry_DestroyConfigFileMapThunk
  }
}

// RavenShield.exe @ 10912edf : UnwindDestroyedConfigCacheSystemIni
// Destroy the saved object's string at +18 while unwinding cache destruction.
__declspec(naked) void UnwindDestroyedConfigCacheSystemIni()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 18h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912eeb : UnwindDestroyedConfigCacheUserIni
// Destroy the saved object's string at +24 while unwinding cache destruction.
__declspec(naked) void UnwindDestroyedConfigCacheUserIni()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 24h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912ef7 : UnwindDestroyedConfigCacheString30
// Destroy the saved object's string at +30 while unwinding cache destruction.
__declspec(naked) void UnwindDestroyedConfigCacheString30()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 30h
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912f03 : UnwindDestroyedConfigCacheString3c
// Destroy the saved object's final string at +3c when its Flush call propagates an error.
__declspec(naked) void UnwindDestroyedConfigCacheString3c()
{
  __asm {
    mov ecx, [ebp-18h]
    add ecx, 3ch
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091af00 : g_configCacheDestructionUnwind
const NativeCppUnwindEntry g_configCacheDestructionUnwind[8] = {
    {-1, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheBase)},     // UnwindDestroyedConfigCacheBase
    {0, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheMap)},       // UnwindDestroyedConfigCacheMap
    {1, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheSystemIni)}, // UnwindDestroyedConfigCacheSystemIni
    {2, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheUserIni)},   // UnwindDestroyedConfigCacheUserIni
    {3, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheString30)},  // UnwindDestroyedConfigCacheString30
    {4, NativeAddress(NativeEntry_UnwindDestroyedConfigCacheString3c)},  // UnwindDestroyedConfigCacheString3c
    {5, 0},
    {5, 0},
};

// RavenShield.exe data @ 1091af40 : g_configCacheDestructionCatches
const NativeCppCatchHandler g_configCacheDestructionCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x10910e9a}, // RethrowConfigCacheDestructorPointer
    {0, 0, 0, 0x10910eae},                                               // UnwindConfigCacheDestructorFailure
};

// RavenShield.exe data @ 1091af60 : g_configCacheDestructionTryBlocks
const NativeCppTryBlock g_configCacheDestructionTryBlocks[1] = {
    {6, 6, 7, 2, NativeAddress(g_configCacheDestructionCatches)},
};

// RavenShield.exe data @ 1091af74 : g_configCacheDestructionExceptionInfo
const NativeCppFunctionInfo g_configCacheDestructionExceptionInfo = {
    0x19930520, 8, NativeAddress(g_configCacheDestructionUnwind), 1, NativeAddress(g_configCacheDestructionTryBlocks),
    0,          0};

// RavenShield.exe @ 10912f0f : HandleConfigCacheDestructionException
// Supply the destructor's eight-state FuncInfo, including its two guarded-Flush catch entries.
__declspec(naked) void HandleConfigCacheDestructionException()
{
  __asm {
    mov eax, offset g_configCacheDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090f2c0 : FConfigCacheIni::Flush
// Write matching cached files, finish iteration, then optionally remove matching entries or empty the whole map.
void FConfigCacheIni::Flush(int32_t read, const uint16_t *filename)
{
  try
  {
    using FileMap = TMapBase<FString, FConfigFile>;
    auto *map = this == nullptr ? nullptr : reinterpret_cast<FileMap *>(reinterpret_cast<uint8_t *>(this) + 4);
    {
      for (FileMap::TIterator it(*map); it; ++it)
      {
        if (filename == nullptr || it.Key() == filename)
        {
          FConfigFile &file = it.Value();
          const uint16_t *storedFilename = *it.Key();
          file.Write(storedFilename); // Return is not tested; no default-file lookup is performed here.
        }
      }
    } // Iterator destruction precedes every read-triggered Remove/Empty, including an exception from either.
    if (read != 0)
    {
      if (filename != nullptr)
        map->Remove(filename);
      else
        map->Empty();
    }
  }
  // RavenShield.exe @ 1090f3e3 : RethrowConfigCacheFlushPointer
  // Copy-throw the caught unsigned-short pointer from the guarded write/removal operation.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090f3f7 : UnwindConfigCacheFlushFailure
  // Append the Flush method name and rethrow the active non-pointer exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheFlushGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912c80 : UnwindConfigCacheFlushIterator
// Destroy the iterator at parent EBP-2c when a guarded Flush loop operation throws.
__declspec(naked) void UnwindConfigCacheFlushIterator()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp NativeEntry_TMapBase_FString_FConfigFile_TIterator_DestroyTIterator
  }
}

// RavenShield.exe data @ 1091a8c4 : g_configCacheFlushUnwind
const NativeCppUnwindEntry g_configCacheFlushUnwind[3] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheFlushIterator)}, // UnwindConfigCacheFlushIterator
    {-1, 0},
};

// RavenShield.exe data @ 1091a8dc : g_configCacheFlushCatches
const NativeCppCatchHandler g_configCacheFlushCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x1090f3e3}, // RethrowConfigCacheFlushPointer
    {0, 0, 0, 0x1090f3f7},                                               // UnwindConfigCacheFlushFailure
};

// RavenShield.exe data @ 1091a8fc : g_configCacheFlushTryBlocks
const NativeCppTryBlock g_configCacheFlushTryBlocks[1] = {
    {0, 1, 2, 2, NativeAddress(g_configCacheFlushCatches)},
};

// RavenShield.exe data @ 1091a910 : g_configCacheFlushExceptionInfo
const NativeCppFunctionInfo g_configCacheFlushExceptionInfo = {
    0x19930520, 3, NativeAddress(g_configCacheFlushUnwind), 1, NativeAddress(g_configCacheFlushTryBlocks), 0, 0};

// RavenShield.exe @ 10912c88 : HandleConfigCacheFlushException
// Supply Flush's iterator-unwind and typed/catch-all guard metadata to shared C++ dispatch.
__declspec(naked) void HandleConfigCacheFlushException()
{
  __asm {
    mov eax, offset g_configCacheFlushExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10914c30 : g_configEmptyString
extern const char16_t g_configEmptyString[] = u"";

// RavenShield.exe data @ 10917928 : g_configCacheInitUserGuardName
const char16_t g_configCacheInitUserGuardName[] = u"FConfigCacheIni::InitUser";

// RavenShield.exe @ 1090dfa0 : FConfigCacheIni::InitUser
// Flush the nonempty old user file before independently assigning either nonnull filename argument.
void FConfigCacheIni::InitUser(const uint16_t *userIniPrefix, const uint16_t *userIni)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    auto *oldUserIni = reinterpret_cast<FString *>(object + 0x24);
    if (*oldUserIni != reinterpret_cast<const uint16_t *>(g_configEmptyString))
    {
      const uint16_t *previousFilename = **oldUserIni; // Borrowed from the current filename string.
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto flush = *reinterpret_cast<const NativeConfigFlush *>(table + 0x34);
      flush(this, 1, previousFilename);
    }
    if (userIni != nullptr) *oldUserIni = userIni;
    if (userIniPrefix != nullptr) *reinterpret_cast<FString *>(object + 0x3c) = userIniPrefix;
  }
  // RavenShield.exe @ 1090e024 : RethrowConfigCacheInitUserPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e038 : UnwindConfigCacheInitUserFailure
  // Annotate the active exception with the method guard name, then rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheInitUserGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a234 : g_configCacheInitUserUnwind
const NativeCppUnwindEntry g_configCacheInitUserUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a244 : g_configCacheInitUserCatches
const NativeCppCatchHandler g_configCacheInitUserCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e024}, // RethrowConfigCacheInitUserPointer
    {0, 0, 0, 0x1090e038},                                               // UnwindConfigCacheInitUserFailure
};

// RavenShield.exe data @ 1091a264 : g_configCacheInitUserTryBlocks
const NativeCppTryBlock g_configCacheInitUserTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheInitUserCatches)},
};

// RavenShield.exe data @ 1091a278 : g_configCacheInitUserExceptionInfo
const NativeCppFunctionInfo g_configCacheInitUserExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheInitUserUnwind), 1, NativeAddress(g_configCacheInitUserTryBlocks), 0, 0};

// RavenShield.exe @ 10912b30 : HandleConfigCacheInitUserException
// Dispatch the two-state guard map; neither state owns a local cleanup action.
__declspec(naked) void HandleConfigCacheInitUserException()
{
  __asm {
    mov eax, offset g_configCacheInitUserExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 1091795c : g_configCacheGetUserIniGuardName
const char16_t g_configCacheGetUserIniGuardName[] = u"FConfigCacheIni::GetUserIni";

// RavenShield.exe @ 1090e060 : FConfigCacheIni::GetUserIni
// Return a copy of UserIni; the native hidden result pointer is returned in EAX and popped with RET 4.
FString FConfigCacheIni::GetUserIni()
{
  try
  {
    return FString(*reinterpret_cast<const FString *>(reinterpret_cast<const uint8_t *>(this) + 0x24));
  }
  // RavenShield.exe @ 1090e0b3 : RethrowConfigCacheGetUserIniPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e0c7 : UnwindConfigCacheGetUserIniFailure
  // Annotate the active exception with the method guard name, then rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetUserIniGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a294 : g_configCacheGetUserIniUnwind
const NativeCppUnwindEntry g_configCacheGetUserIniUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a2a4 : g_configCacheGetUserIniCatches
const NativeCppCatchHandler g_configCacheGetUserIniCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e0b3}, // RethrowConfigCacheGetUserIniPointer
    {0, 0, 0, 0x1090e0c7},                                               // UnwindConfigCacheGetUserIniFailure
};

// RavenShield.exe data @ 1091a2c4 : g_configCacheGetUserIniTryBlocks
const NativeCppTryBlock g_configCacheGetUserIniTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetUserIniCatches)},
};

// RavenShield.exe data @ 1091a2d8 : g_configCacheGetUserIniExceptionInfo
const NativeCppFunctionInfo g_configCacheGetUserIniExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetUserIniUnwind), 1, NativeAddress(g_configCacheGetUserIniTryBlocks),
    0,          0};

// RavenShield.exe @ 10912b40 : HandleConfigCacheGetUserIniException
// Dispatch the two-state guard map; neither state owns a local cleanup action.
__declspec(naked) void HandleConfigCacheGetUserIniException()
{
  __asm {
    mov eax, offset g_configCacheGetUserIniExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917994 : g_configCacheInitServerGuardName
const char16_t g_configCacheInitServerGuardName[] = u"FConfigCacheIni::InitServer";

// RavenShield.exe @ 1090e0f0 : FConfigCacheIni::InitServer
// Flush the nonempty old server file, then pass the new pointer unconditionally to FString assignment.
void FConfigCacheIni::InitServer(const uint16_t *serverIni)
{
  try
  {
    auto *oldServerIni = reinterpret_cast<FString *>(reinterpret_cast<uint8_t *>(this) + 0x30);
    if (*oldServerIni != reinterpret_cast<const uint16_t *>(g_configEmptyString))
    {
      const uint16_t *previousFilename = **oldServerIni; // Borrowed from the current filename string.
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto flush = *reinterpret_cast<const NativeConfigFlush *>(table + 0x34);
      flush(this, 1, previousFilename);
    }
    *oldServerIni = serverIni;
  }
  // RavenShield.exe @ 1090e15f : RethrowConfigCacheInitServerPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e173 : UnwindConfigCacheInitServerFailure
  // Annotate the active exception with the method guard name, then rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheInitServerGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a2f4 : g_configCacheInitServerUnwind
const NativeCppUnwindEntry g_configCacheInitServerUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a304 : g_configCacheInitServerCatches
const NativeCppCatchHandler g_configCacheInitServerCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e15f}, // RethrowConfigCacheInitServerPointer
    {0, 0, 0, 0x1090e173},                                               // UnwindConfigCacheInitServerFailure
};

// RavenShield.exe data @ 1091a324 : g_configCacheInitServerTryBlocks
const NativeCppTryBlock g_configCacheInitServerTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheInitServerCatches)},
};

// RavenShield.exe data @ 1091a338 : g_configCacheInitServerExceptionInfo
const NativeCppFunctionInfo g_configCacheInitServerExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheInitServerUnwind), 1, NativeAddress(g_configCacheInitServerTryBlocks),
    0,          0};

// RavenShield.exe @ 10912b50 : HandleConfigCacheInitServerException
// Dispatch the two-state guard map; neither state owns a local cleanup action.
__declspec(naked) void HandleConfigCacheInitServerException()
{
  __asm {
    mov eax, offset g_configCacheInitServerExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 109179cc : g_configCacheGetServerIniGuardName
const char16_t g_configCacheGetServerIniGuardName[] = u"FConfigCacheIni::GetServerIni";

// RavenShield.exe @ 1090e190 : FConfigCacheIni::GetServerIni
// Return a copy of ServerIni with the same hidden-result ABI as GetUserIni.
FString FConfigCacheIni::GetServerIni()
{
  try
  {
    return FString(*reinterpret_cast<const FString *>(reinterpret_cast<const uint8_t *>(this) + 0x30));
  }
  // RavenShield.exe @ 1090e1e3 : RethrowConfigCacheGetServerIniPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e1f7 : UnwindConfigCacheGetServerIniFailure
  // Annotate the active exception with the method guard name, then rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetServerIniGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a354 : g_configCacheGetServerIniUnwind
const NativeCppUnwindEntry g_configCacheGetServerIniUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a364 : g_configCacheGetServerIniCatches
const NativeCppCatchHandler g_configCacheGetServerIniCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e1e3}, // RethrowConfigCacheGetServerIniPointer
    {0, 0, 0, 0x1090e1f7},                                               // UnwindConfigCacheGetServerIniFailure
};

// RavenShield.exe data @ 1091a384 : g_configCacheGetServerIniTryBlocks
const NativeCppTryBlock g_configCacheGetServerIniTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetServerIniCatches)},
};

// RavenShield.exe data @ 1091a398 : g_configCacheGetServerIniExceptionInfo
const NativeCppFunctionInfo g_configCacheGetServerIniExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetServerIniUnwind), 1, NativeAddress(g_configCacheGetServerIniTryBlocks),
    0,          0};

// RavenShield.exe @ 10912b60 : HandleConfigCacheGetServerIniException
// Dispatch the two-state guard map; neither state owns a local cleanup action.
__declspec(naked) void HandleConfigCacheGetServerIniException()
{
  __asm {
    mov eax, offset g_configCacheGetServerIniExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917a08 : g_configCacheExitGuardName
const char16_t g_configCacheExitGuardName[] = u"FConfigCacheIni::Exit";

// RavenShield.exe @ 1090e220 : FConfigCacheIni::Exit
// Flush and discard all cached files through virtual slot +34, preserving both guard catches.
void FConfigCacheIni::Exit()
{
  const uint32_t tableOnEntry = *reinterpret_cast<const uint32_t *>(this); // Native read before guard state zero.
  try
  {
    const auto flush = *reinterpret_cast<const NativeConfigFlush *>(tableOnEntry + 0x34);
    flush(this, 1, nullptr);
  }
  // RavenShield.exe @ 1090e262 : RethrowConfigCacheExitPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e276 : UnwindConfigCacheExitFailure
  // Annotate the active exception with the method guard name, then rethrow it.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheExitGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a3b4 : g_configCacheExitUnwind
const NativeCppUnwindEntry g_configCacheExitUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a3c4 : g_configCacheExitCatches
const NativeCppCatchHandler g_configCacheExitCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e262}, // RethrowConfigCacheExitPointer
    {0, 0, 0, 0x1090e276},                                               // UnwindConfigCacheExitFailure
};

// RavenShield.exe data @ 1091a3e4 : g_configCacheExitTryBlocks
const NativeCppTryBlock g_configCacheExitTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheExitCatches)},
};

// RavenShield.exe data @ 1091a3f8 : g_configCacheExitExceptionInfo
const NativeCppFunctionInfo g_configCacheExitExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheExitUnwind), 1, NativeAddress(g_configCacheExitTryBlocks), 0, 0};

// RavenShield.exe @ 10912b70 : HandleConfigCacheExitException
// Dispatch the two-state guard map; neither state owns a local cleanup action.
__declspec(naked) void HandleConfigCacheExitException()
{
  __asm {
    mov eax, offset g_configCacheExitExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FFileManager;
extern FFileManager *GFileManager;
extern uint16_t *__cdecl appStrcpy(uint16_t *destination, const uint16_t *source);
extern uint16_t *__cdecl appStrcat(uint16_t *destination, const uint16_t *source);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern int32_t __cdecl appStricmp(const uint16_t *left, const uint16_t *right);

// RavenShield.exe data @ 10917dac : g_configCacheCancelGuardName
const char16_t g_configCacheCancelGuardName[] = u"FConfigCacheIni::Cancel";
// RavenShield.exe data @ 10917ddc : g_configCacheFindGuardName
const char16_t g_configCacheFindGuardName[] = u"FConfigCacheIni::Find";
// RavenShield.exe data @ 10917e08 : g_genericSystemIni
const char16_t g_genericSystemIni[] = u"System.ini";
// RavenShield.exe data @ 10917e20 : g_genericUserIni
const char16_t g_genericUserIni[] = u"User.ini";
// RavenShield.exe data @ 10914b50 : g_configIniExtension
extern const char16_t g_configIniExtension[] = u".ini";

// RavenShield.exe @ 1090f910 : FConfigCacheIni::Cancel
// Load or create the requested file, then suppress its later writes by setting NoSave at +18.
void FConfigCacheIni::Cancel(const uint16_t *filename)
{
  try
  {
    if (FConfigFile *file = FConfigCacheIni::Find(filename, 1))
      *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(file) + 0x18) = 1;
  }
  // RavenShield.exe @ 1090f961 : RethrowConfigCacheCancelPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090f975 : UnwindConfigCacheCancelFailure
  // Append the native Cancel guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheCancelGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a9bc : g_configCacheCancelUnwind
const NativeCppUnwindEntry g_configCacheCancelUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a9cc : g_configCacheCancelCatches
const NativeCppCatchHandler g_configCacheCancelCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090f961}, // RethrowConfigCacheCancelPointer
    {0, 0, 0, 0x1090f975},                                               // UnwindConfigCacheCancelFailure
};

// RavenShield.exe data @ 1091a9ec : g_configCacheCancelTryBlocks
const NativeCppTryBlock g_configCacheCancelTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheCancelCatches)},
};

// RavenShield.exe data @ 1091aa00 : g_configCacheCancelExceptionInfo
const NativeCppFunctionInfo g_configCacheCancelExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheCancelUnwind), 1, NativeAddress(g_configCacheCancelTryBlocks), 0, 0};

// RavenShield.exe @ 10912ce0 : HandleConfigCacheCancelException
// Supply Cancel's two-state typed-pointer/catch-all guard to shared exception dispatch.
__declspec(naked) void HandleConfigCacheCancelException()
{
  __asm {
    mov eax, offset g_configCacheCancelExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090f9a0 : FConfigCacheIni::Find
// Resolve generic filenames, return cached files, or insert/read a file when creation or its native size permits.
FConfigFile *FConfigCacheIni::Find(const uint16_t *inFilename, int32_t createIfNotFound)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    uint16_t filename[256]; // Native unbounded string operations retain the fixed stack buffer.
    appStrcpy(filename, inFilename != nullptr ? inFilename : **reinterpret_cast<FString *>(object + 0x18));
    const int32_t length = appStrlen(filename);
    if (length < 5 || (filename[length - 4] != '.' && filename[length - 5] != '.'))
      appStrcat(filename, reinterpret_cast<const uint16_t *>(g_configIniExtension));
    if (appStricmp(filename, reinterpret_cast<const uint16_t *>(g_genericUserIni)) == 0)
    {
      FString translated = *reinterpret_cast<FString *>(object + 0x3c) + *reinterpret_cast<FString *>(object + 0x24);
      appStrcpy(filename, *translated);
    }
    else if (appStricmp(filename, reinterpret_cast<const uint16_t *>(g_genericSystemIni)) == 0)
    {
      appStrcpy(filename, **reinterpret_cast<FString *>(object + 0x18));
    }
    using FileMap = TMapBase<FString, FConfigFile>;
    auto *map = reinterpret_cast<FileMap *>(object + 4);
    FConfigFile *result;
    {
      FString key(filename);
      result = map->Find(key);
    }
    if (result == nullptr && (createIfNotFound != 0 || GFileManager->FileSize(filename) >= 0))
    {
      {
        FConfigFile emptyFile;
        result = &map->Set(filename, emptyFile);
      }
      result->Read(filename); // The inserted entry remains cached if reading fails or throws.
    }
    return result;
  }
  // RavenShield.exe @ 1090fb52 : RethrowConfigCacheFindPointer
  // Copy-throw the caught pointer from parent EBP-24 into a new throw object at EBP-14.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090fb66 : UnwindConfigCacheFindFailure
  // Append Find's guard after local cleanup and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheFindGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912cf0 : UnwindConfigCacheFindTranslatedName
// Destroy the completed user-name concatenation temporary at parent EBP-20.
__declspec(naked) void UnwindConfigCacheFindTranslatedName()
{
  __asm {
    lea ecx, [ebp-20h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912cf9 : UnwindConfigCacheFindKey
// Destroy the completed lookup key in the reused parent EBP-20 slot.
__declspec(naked) void UnwindConfigCacheFindKey()
{
  __asm {
    lea ecx, [ebp-20h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912d02 : UnwindConfigCacheFindEmptyFile
// Destroy the completed empty-file temporary at parent EBP-40 through the canonical map forwarding thunk.
__declspec(naked) void UnwindConfigCacheFindEmptyFile()
{
  __asm {
    lea ecx, [ebp-40h]
    jmp NativeEntry_ForwardFConfigSectionMapDestruction
  }
}

// RavenShield.exe data @ 1091aa1c : g_configCacheFindUnwind
const NativeCppUnwindEntry g_configCacheFindUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheFindTranslatedName)}, // UnwindConfigCacheFindTranslatedName
    {0, NativeAddress(NativeEntry_UnwindConfigCacheFindKey)},            // UnwindConfigCacheFindKey
    {0, NativeAddress(NativeEntry_UnwindConfigCacheFindEmptyFile)},      // UnwindConfigCacheFindEmptyFile
    {-1, 0},
};

// RavenShield.exe data @ 1091aa44 : g_configCacheFindCatches
const NativeCppCatchHandler g_configCacheFindCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x24, 0x1090fb52}, // RethrowConfigCacheFindPointer
    {0, 0, 0, 0x1090fb66},                                               // UnwindConfigCacheFindFailure
};

// RavenShield.exe data @ 1091aa64 : g_configCacheFindTryBlocks
const NativeCppTryBlock g_configCacheFindTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_configCacheFindCatches)},
};

// RavenShield.exe data @ 1091aa78 : g_configCacheFindExceptionInfo
const NativeCppFunctionInfo g_configCacheFindExceptionInfo = {
    0x19930520, 5, NativeAddress(g_configCacheFindUnwind), 1, NativeAddress(g_configCacheFindTryBlocks), 0, 0};

// RavenShield.exe @ 10912d0a : HandleConfigCacheFindException
// Supply Find's five-state temporary cleanup map and typed-pointer/catch-all guard metadata.
__declspec(naked) void HandleConfigCacheFindException()
{
  __asm {
    mov eax, offset g_configCacheFindExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern uint16_t *__cdecl appStaticString1024();
extern int32_t __cdecl appAtoi(const uint16_t *text);
extern float __cdecl appAtof(const uint16_t *text);
extern uint16_t *__cdecl appStrncpy(uint16_t *destination, const uint16_t *source, int32_t count);
using NativeConfigBufferGetter = int32_t(__thiscall *)(FConfigCacheIni *, const uint16_t *, const uint16_t *,
                                                       uint16_t *, int32_t, const uint16_t *);

// RavenShield.exe data @ 10917b34 : g_configTrueText
const char16_t g_configTrueText[] = u"True";

// RavenShield.exe data @ 10917a34 : g_configCacheGetStringGuardName
const char16_t g_configCacheGetStringGuardName[] = u"FConfigCacheIni::GetString";

// RavenShield.exe @ 1090e2a0 : FConfigCacheIni::GetString
// Assign the fully zero-initialized 4096-unit buffer even on failed lookup, returning the raw virtual getter result.
int32_t FConfigCacheIni::GetString(const uint16_t *section, const uint16_t *key, FString &value,
                                   const uint16_t *filename)
{
  uint16_t text[4096] = {}; // Native stack probe and initialization precede guard state zero.
  const uint32_t tableOnEntry = *reinterpret_cast<const uint32_t *>(this); // Native table read also precedes the guard.
  try
  {
    const auto getString = *reinterpret_cast<const NativeConfigBufferGetter *>(tableOnEntry + 0x10);
    const int32_t result = getString(this, section, key, text, 4096, filename);
    value = text;
    return result;
  }
  // RavenShield.exe @ 1090e332 : RethrowConfigCacheGetStringPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e346 : UnwindConfigCacheGetStringFailure
  // Append the method guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetStringGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a414 : g_configCacheGetStringUnwind
const NativeCppUnwindEntry g_configCacheGetStringUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a424 : g_configCacheGetStringCatches
const NativeCppCatchHandler g_configCacheGetStringCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e332}, // RethrowConfigCacheGetStringPointer
    {0, 0, 0, 0x1090e346},                                               // UnwindConfigCacheGetStringFailure
};

// RavenShield.exe data @ 1091a444 : g_configCacheGetStringTryBlocks
const NativeCppTryBlock g_configCacheGetStringTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetStringCatches)},
};

// RavenShield.exe data @ 1091a458 : g_configCacheGetStringExceptionInfo
const NativeCppFunctionInfo g_configCacheGetStringExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetStringUnwind), 1, NativeAddress(g_configCacheGetStringTryBlocks),
    0,          0};

// RavenShield.exe @ 10912b80 : HandleConfigCacheGetStringException
// Supply the getter's two-state typed-pointer/catch-all guard map; neither state owns a cleanup action.
__declspec(naked) void HandleConfigCacheGetStringException()
{
  __asm {
    mov eax, offset g_configCacheGetStringExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917a6c : g_configCacheGetStrGuardName
const char16_t g_configCacheGetStrGuardName[] = u"FConfigCacheIni::GetStr";

// RavenShield.exe @ 1090e370 : FConfigCacheIni::GetStr
// Return the borrowed rotating 1024-unit Core buffer after virtual lookup, ignoring the lookup result.
const uint16_t *FConfigCacheIni::GetStr(const uint16_t *section, const uint16_t *key, const uint16_t *filename)
{
  try
  {
    uint16_t *result = appStaticString1024();
    GetString(section, key, result, 1024, filename);
    return result;
  }
  // RavenShield.exe @ 1090e3d0 : RethrowConfigCacheGetStrPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e3e4 : UnwindConfigCacheGetStrFailure
  // Append the method guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetStrGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a474 : g_configCacheGetStrUnwind
const NativeCppUnwindEntry g_configCacheGetStrUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a484 : g_configCacheGetStrCatches
const NativeCppCatchHandler g_configCacheGetStrCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e3d0}, // RethrowConfigCacheGetStrPointer
    {0, 0, 0, 0x1090e3e4},                                               // UnwindConfigCacheGetStrFailure
};

// RavenShield.exe data @ 1091a4a4 : g_configCacheGetStrTryBlocks
const NativeCppTryBlock g_configCacheGetStrTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetStrCatches)},
};

// RavenShield.exe data @ 1091a4b8 : g_configCacheGetStrExceptionInfo
const NativeCppFunctionInfo g_configCacheGetStrExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetStrUnwind), 1, NativeAddress(g_configCacheGetStrTryBlocks), 0, 0};

// RavenShield.exe @ 10912b90 : HandleConfigCacheGetStrException
// Supply the getter's two-state typed-pointer/catch-all guard map; neither state owns a cleanup action.
__declspec(naked) void HandleConfigCacheGetStrException()
{
  __asm {
    mov eax, offset g_configCacheGetStrExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917a9c : g_configCacheGetIntGuardName
const char16_t g_configCacheGetIntGuardName[] = u"FConfigCacheIni::GetInt";

// RavenShield.exe @ 1090e410 : FConfigCacheIni::GetInt
// Convert successful 80-unit virtual string lookups with appAtoi; retain the caller value on lookup failure.
int32_t FConfigCacheIni::GetInt(const uint16_t *section, const uint16_t *key, int32_t &value, const uint16_t *filename)
{
  const uint32_t tableOnEntry = *reinterpret_cast<const uint32_t *>(this); // Native read before guard state zero.
  try
  {
    uint16_t text[80];
    const auto getString = *reinterpret_cast<const NativeConfigBufferGetter *>(tableOnEntry + 0x10);
    if (getString(this, section, key, text, 80, filename) == 0) return 0;
    value = appAtoi(text);
    return 1;
  }
  // RavenShield.exe @ 1090e49b : RethrowConfigCacheGetIntPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e4af : UnwindConfigCacheGetIntFailure
  // Append the method guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetIntGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a4d4 : g_configCacheGetIntUnwind
const NativeCppUnwindEntry g_configCacheGetIntUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a4e4 : g_configCacheGetIntCatches
const NativeCppCatchHandler g_configCacheGetIntCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e49b}, // RethrowConfigCacheGetIntPointer
    {0, 0, 0, 0x1090e4af},                                               // UnwindConfigCacheGetIntFailure
};

// RavenShield.exe data @ 1091a504 : g_configCacheGetIntTryBlocks
const NativeCppTryBlock g_configCacheGetIntTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetIntCatches)},
};

// RavenShield.exe data @ 1091a518 : g_configCacheGetIntExceptionInfo
const NativeCppFunctionInfo g_configCacheGetIntExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetIntUnwind), 1, NativeAddress(g_configCacheGetIntTryBlocks), 0, 0};

// RavenShield.exe @ 10912ba0 : HandleConfigCacheGetIntException
// Supply the getter's two-state typed-pointer/catch-all guard map; neither state owns a cleanup action.
__declspec(naked) void HandleConfigCacheGetIntException()
{
  __asm {
    mov eax, offset g_configCacheGetIntExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917acc : g_configCacheGetFloatGuardName
const char16_t g_configCacheGetFloatGuardName[] = u"FConfigCacheIni::GetFloat";

// RavenShield.exe @ 1090e4d0 : FConfigCacheIni::GetFloat
// Store the appAtof single-precision result only on lookup success; return a full-word success indicator.
int32_t FConfigCacheIni::GetFloat(const uint16_t *section, const uint16_t *key, float &value, const uint16_t *filename)
{
  const uint32_t tableOnEntry = *reinterpret_cast<const uint32_t *>(this); // Native read before guard state zero.
  try
  {
    uint16_t text[80];
    const auto getString = *reinterpret_cast<const NativeConfigBufferGetter *>(tableOnEntry + 0x10);
    if (getString(this, section, key, text, 80, filename) == 0) return 0;
    value = appAtof(text); // Native ST(0) is stored as a 32-bit float.
    return 1;
  }
  // RavenShield.exe @ 1090e55e : RethrowConfigCacheGetFloatPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e572 : UnwindConfigCacheGetFloatFailure
  // Append the method guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetFloatGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a534 : g_configCacheGetFloatUnwind
const NativeCppUnwindEntry g_configCacheGetFloatUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a544 : g_configCacheGetFloatCatches
const NativeCppCatchHandler g_configCacheGetFloatCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e55e}, // RethrowConfigCacheGetFloatPointer
    {0, 0, 0, 0x1090e572},                                               // UnwindConfigCacheGetFloatFailure
};

// RavenShield.exe data @ 1091a564 : g_configCacheGetFloatTryBlocks
const NativeCppTryBlock g_configCacheGetFloatTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetFloatCatches)},
};

// RavenShield.exe data @ 1091a578 : g_configCacheGetFloatExceptionInfo
const NativeCppFunctionInfo g_configCacheGetFloatExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetFloatUnwind), 1, NativeAddress(g_configCacheGetFloatTryBlocks), 0, 0};

// RavenShield.exe @ 10912bb0 : HandleConfigCacheGetFloatException
// Supply the getter's two-state typed-pointer/catch-all guard map; neither state owns a cleanup action.
__declspec(naked) void HandleConfigCacheGetFloatException()
{
  __asm {
    mov eax, offset g_configCacheGetFloatExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917b00 : g_configCacheGetBoolGuardName
const char16_t g_configCacheGetBoolGuardName[] = u"FConfigCacheIni::GetBool";

// RavenShield.exe @ 1090e590 : FConfigCacheIni::GetBool
// Treat case-insensitive True or appAtoi(text)==1 as true; retain the caller value when lookup fails.
int32_t FConfigCacheIni::GetBool(const uint16_t *section, const uint16_t *key, int32_t &value, const uint16_t *filename)
{
  const uint32_t tableOnEntry = *reinterpret_cast<const uint32_t *>(this); // Native read before guard state zero.
  try
  {
    uint16_t text[80];
    const auto getString = *reinterpret_cast<const NativeConfigBufferGetter *>(tableOnEntry + 0x10);
    if (getString(this, section, key, text, 80, filename) == 0) return 0;
    if (appStricmp(text, reinterpret_cast<const uint16_t *>(g_configTrueText)) == 0)
      value = 1;
    else
      value = appAtoi(text) == 1;
    return 1;
  }
  // RavenShield.exe @ 1090e647 : RethrowConfigCacheGetBoolPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e65b : UnwindConfigCacheGetBoolFailure
  // Append the method guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetBoolGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a594 : g_configCacheGetBoolUnwind
const NativeCppUnwindEntry g_configCacheGetBoolUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a5a4 : g_configCacheGetBoolCatches
const NativeCppCatchHandler g_configCacheGetBoolCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e647}, // RethrowConfigCacheGetBoolPointer
    {0, 0, 0, 0x1090e65b},                                               // UnwindConfigCacheGetBoolFailure
};

// RavenShield.exe data @ 1091a5c4 : g_configCacheGetBoolTryBlocks
const NativeCppTryBlock g_configCacheGetBoolTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheGetBoolCatches)},
};

// RavenShield.exe data @ 1091a5d8 : g_configCacheGetBoolExceptionInfo
const NativeCppFunctionInfo g_configCacheGetBoolExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheGetBoolUnwind), 1, NativeAddress(g_configCacheGetBoolTryBlocks), 0, 0};

// RavenShield.exe @ 10912bc0 : HandleConfigCacheGetBoolException
// Supply the getter's two-state typed-pointer/catch-all guard map; neither state owns a cleanup action.
__declspec(naked) void HandleConfigCacheGetBoolException()
{
  __asm {
    mov eax, offset g_configCacheGetBoolExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917e5c : g_configCacheBufferGetStringGuardName
const char16_t g_configCacheBufferGetStringGuardName[] = u"FConfigCacheIni::GetString";

// RavenShield.exe @ 109106e0 : FConfigCacheIni::GetString
// Clear the first output unit, find existing file/section/key, and bounded-copy the first hash-chain match.
int32_t FConfigCacheIni::GetString(const uint16_t *section, const uint16_t *key, uint16_t *value, int32_t size,
                                   const uint16_t *filename)
{
  try
  {
    value[0] = 0; // Native store occurs even for size <= 0 and before filename resolution.
    FConfigFile *file = FConfigCacheIni::Find(filename, 0);
    if (file == nullptr) return 0;
    FConfigSection *foundSection;
    {
      FString sectionKey(section);
      foundSection = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file)->Find(sectionKey);
    }
    if (foundSection == nullptr) return 0;
    FString *foundValue;
    {
      FString entryKey(key);
      foundValue = reinterpret_cast<TMapBase<FString, FString> *>(foundSection)->Find(entryKey);
    }
    if (foundValue == nullptr) return 0;
    appStrncpy(value, **foundValue, size);
    return 1;
  }
  // RavenShield.exe @ 109107bc : RethrowConfigCacheBufferGetStringPointer
  // Throw a copy of the caught unsigned-short pointer value after local key cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109107d0 : UnwindConfigCacheBufferGetStringFailure
  // Append the native buffer-getter guard name and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheBufferGetStringGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912dc0 : UnwindConfigCacheBufferGetStringSectionKey
// Destroy the completed section-key FString at parent EBP-24.
__declspec(naked) void UnwindConfigCacheBufferGetStringSectionKey()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912dc9 : UnwindConfigCacheBufferGetStringEntryKey
// Destroy the completed entry-key FString at parent EBP-30.
__declspec(naked) void UnwindConfigCacheBufferGetStringEntryKey()
{
  __asm {
    lea ecx, [ebp-30h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091ac78 : g_configCacheBufferGetStringUnwind
const NativeCppUnwindEntry g_configCacheBufferGetStringUnwind[4] = {
    {-1, 0},
    {0, NativeAddress(
            NativeEntry_UnwindConfigCacheBufferGetStringSectionKey)}, // UnwindConfigCacheBufferGetStringSectionKey
    {0,
     NativeAddress(NativeEntry_UnwindConfigCacheBufferGetStringEntryKey)}, // UnwindConfigCacheBufferGetStringEntryKey
    {-1, 0},
};

// RavenShield.exe data @ 1091ac98 : g_configCacheBufferGetStringCatches
const NativeCppCatchHandler g_configCacheBufferGetStringCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x109107bc}, // RethrowConfigCacheBufferGetStringPointer
    {0, 0, 0, 0x109107d0},                                               // UnwindConfigCacheBufferGetStringFailure
};

// RavenShield.exe data @ 1091acb8 : g_configCacheBufferGetStringTryBlocks
const NativeCppTryBlock g_configCacheBufferGetStringTryBlocks[1] = {
    {0, 2, 3, 2, NativeAddress(g_configCacheBufferGetStringCatches)},
};

// RavenShield.exe data @ 1091accc : g_configCacheBufferGetStringExceptionInfo
const NativeCppFunctionInfo g_configCacheBufferGetStringExceptionInfo = {
    0x19930520,
    4,
    NativeAddress(g_configCacheBufferGetStringUnwind),
    1,
    NativeAddress(g_configCacheBufferGetStringTryBlocks),
    0,
    0};

// RavenShield.exe @ 10912dd2 : HandleConfigCacheBufferGetStringException
// Supply the getter's four-state key cleanup map and typed-pointer/catch-all guard metadata.
__declspec(naked) void HandleConfigCacheBufferGetStringException()
{
  __asm {
    mov eax, offset g_configCacheBufferGetStringExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern int32_t __cdecl appSprintf(uint16_t *destination, const uint16_t *format, ...);
extern int32_t __cdecl appStrcmp(const uint16_t *left, const uint16_t *right);

// RavenShield.exe data @ 10917b70 : g_configIntegerFormat
const char16_t g_configIntegerFormat[] = u"%i";
// RavenShield.exe data @ 10917bac : g_configFloatFormat
const char16_t g_configFloatFormat[] = u"%f";
// RavenShield.exe data @ 10916fd8 : g_configFalseText
extern const char16_t g_configFalseText[] = u"False";

// RavenShield.exe data @ 10917b40 : g_configCacheSetIntGuardName
const char16_t g_configCacheSetIntGuardName[] = u"FConfigCacheIni::SetInt";

// RavenShield.exe @ 1090e680 : FConfigCacheIni::SetInt
// Format the signed integer with %i into the native 30-unit buffer, then virtually dispatch SetString.
void FConfigCacheIni::SetInt(const uint16_t *section, const uint16_t *key, int32_t value, const uint16_t *filename)
{
  try
  {
    uint16_t text[30];
    appSprintf(text, reinterpret_cast<const uint16_t *>(g_configIntegerFormat), value);
    SetString(section, key, text, filename);
  }
  // RavenShield.exe @ 1090e6ea : RethrowConfigCacheSetIntPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e6fe : UnwindConfigCacheSetIntFailure
  // Append the method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheSetIntGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a5f4 : g_configCacheSetIntUnwind
const NativeCppUnwindEntry g_configCacheSetIntUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a604 : g_configCacheSetIntCatches
const NativeCppCatchHandler g_configCacheSetIntCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e6ea}, // RethrowConfigCacheSetIntPointer
    {0, 0, 0, 0x1090e6fe},                                               // UnwindConfigCacheSetIntFailure
};

// RavenShield.exe data @ 1091a624 : g_configCacheSetIntTryBlocks
const NativeCppTryBlock g_configCacheSetIntTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheSetIntCatches)},
};

// RavenShield.exe data @ 1091a638 : g_configCacheSetIntExceptionInfo
const NativeCppFunctionInfo g_configCacheSetIntExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheSetIntUnwind), 1, NativeAddress(g_configCacheSetIntTryBlocks), 0, 0};

// RavenShield.exe @ 10912bd0 : HandleConfigCacheSetIntException
// Supply the setter's two-state typed-pointer/catch-all guard map with no local cleanup actions.
__declspec(naked) void HandleConfigCacheSetIntException()
{
  __asm {
    mov eax, offset g_configCacheSetIntExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917b78 : g_configCacheSetFloatGuardName
const char16_t g_configCacheSetFloatGuardName[] = u"FConfigCacheIni::SetFloat";

// RavenShield.exe @ 1090e720 : FConfigCacheIni::SetFloat
// Promote the float to double, format %f into the native 30-unit buffer, then virtually dispatch SetString.
void FConfigCacheIni::SetFloat(const uint16_t *section, const uint16_t *key, float value, const uint16_t *filename)
{
  const double promotedValue = static_cast<double>(value); // Native FLD/FSTP promotion precedes guard state zero.
  try
  {
    uint16_t text[30];
    appSprintf(text, reinterpret_cast<const uint16_t *>(g_configFloatFormat), promotedValue);
    SetString(section, key, text, filename);
  }
  // RavenShield.exe @ 1090e78f : RethrowConfigCacheSetFloatPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e7a3 : UnwindConfigCacheSetFloatFailure
  // Append the method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheSetFloatGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a654 : g_configCacheSetFloatUnwind
const NativeCppUnwindEntry g_configCacheSetFloatUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a664 : g_configCacheSetFloatCatches
const NativeCppCatchHandler g_configCacheSetFloatCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e78f}, // RethrowConfigCacheSetFloatPointer
    {0, 0, 0, 0x1090e7a3},                                               // UnwindConfigCacheSetFloatFailure
};

// RavenShield.exe data @ 1091a684 : g_configCacheSetFloatTryBlocks
const NativeCppTryBlock g_configCacheSetFloatTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheSetFloatCatches)},
};

// RavenShield.exe data @ 1091a698 : g_configCacheSetFloatExceptionInfo
const NativeCppFunctionInfo g_configCacheSetFloatExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheSetFloatUnwind), 1, NativeAddress(g_configCacheSetFloatTryBlocks), 0, 0};

// RavenShield.exe @ 10912be0 : HandleConfigCacheSetFloatException
// Supply the setter's two-state typed-pointer/catch-all guard map with no local cleanup actions.
__declspec(naked) void HandleConfigCacheSetFloatException()
{
  __asm {
    mov eax, offset g_configCacheSetFloatExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917bb4 : g_configCacheSetBoolGuardName
const char16_t g_configCacheSetBoolGuardName[] = u"FConfigCacheIni::SetBool";

// RavenShield.exe @ 1090e7c0 : FConfigCacheIni::SetBool
// Select True for every nonzero input or False for zero, then virtually dispatch SetString.
void FConfigCacheIni::SetBool(const uint16_t *section, const uint16_t *key, int32_t value, const uint16_t *filename)
{
  try
  {
    const uint16_t *text = reinterpret_cast<const uint16_t *>(value != 0 ? g_configTrueText : g_configFalseText);
    SetString(section, key, text, filename);
  }
  // RavenShield.exe @ 1090e81e : RethrowConfigCacheSetBoolPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e832 : UnwindConfigCacheSetBoolFailure
  // Append the method guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheSetBoolGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a6b4 : g_configCacheSetBoolUnwind
const NativeCppUnwindEntry g_configCacheSetBoolUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a6c4 : g_configCacheSetBoolCatches
const NativeCppCatchHandler g_configCacheSetBoolCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e81e}, // RethrowConfigCacheSetBoolPointer
    {0, 0, 0, 0x1090e832},                                               // UnwindConfigCacheSetBoolFailure
};

// RavenShield.exe data @ 1091a6e4 : g_configCacheSetBoolTryBlocks
const NativeCppTryBlock g_configCacheSetBoolTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheSetBoolCatches)},
};

// RavenShield.exe data @ 1091a6f8 : g_configCacheSetBoolExceptionInfo
const NativeCppFunctionInfo g_configCacheSetBoolExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheSetBoolUnwind), 1, NativeAddress(g_configCacheSetBoolTryBlocks), 0, 0};

// RavenShield.exe @ 10912bf0 : HandleConfigCacheSetBoolException
// Supply the setter's two-state typed-pointer/catch-all guard map with no local cleanup actions.
__declspec(naked) void HandleConfigCacheSetBoolException()
{
  __asm {
    mov eax, offset g_configCacheSetBoolExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917f20 : g_configCacheSetStringGuardName
const char16_t g_configCacheSetStringGuardName[] = u"FConfigCacheIni::SetString";

// RavenShield.exe @ 10910a90 : FConfigCacheIni::SetString
// Create missing file/section/key entries; ignore case-only value changes and retain the native Dirty overwrite order.
void FConfigCacheIni::SetString(const uint16_t *section, const uint16_t *key, const uint16_t *value,
                                const uint16_t *filename)
{
  try
  {
    using SectionMap = TMapBase<FString, FConfigSection>;
    using EntryMap = TMapBase<FString, FString>;
    FConfigFile *file = FConfigCacheIni::Find(filename, 1);
    auto *sections = reinterpret_cast<SectionMap *>(file); // Native has no null-result gate here.
    FConfigSection *foundSection;
    {
      FString sectionKey(section);
      foundSection = sections->Find(sectionKey);
    }
    if (foundSection == nullptr)
    {
      FConfigSection emptySection;
      foundSection = &sections->Set(section, emptySection);
    }
    auto *entries = reinterpret_cast<EntryMap *>(foundSection);
    FString *foundValue;
    {
      FString entryKey(key);
      foundValue = entries->Find(entryKey);
    }
    auto *dirty = reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(file) + 0x14);
    if (foundValue == nullptr)
    {
      entries->Add(key, value);
      *dirty = 1; // Failed insertion leaves the earlier Dirty value intact.
    }
    else if (appStricmp(**foundValue, value) != 0)
    {
      *dirty = appStrcmp(**foundValue, value) != 0; // Overwrite before assignment; do not OR with the previous flag.
      *foundValue = value;
    }
  }
  // RavenShield.exe @ 10910bc5 : RethrowConfigCacheSetStringPointer
  // Throw a copy of the caught unsigned-short pointer after temporary cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10910bd9 : UnwindConfigCacheSetStringFailure
  // Append SetString's guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheSetStringGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912e30 : UnwindConfigCacheSetStringSectionKey
// Destroy the completed section-key FString at parent EBP-24.
__declspec(naked) void UnwindConfigCacheSetStringSectionKey()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912e39 : UnwindConfigCacheSetStringSection
// Destroy the completed temporary section map at parent EBP-44.
__declspec(naked) void UnwindConfigCacheSetStringSection()
{
  __asm {
    lea ecx, [ebp-44h]
    jmp NativeEntry_ForwardFStringMapDestruction
  }
}

// RavenShield.exe @ 10912e41 : UnwindConfigCacheSetStringEntryKey
// Destroy the completed entry-key FString at parent EBP-30.
__declspec(naked) void UnwindConfigCacheSetStringEntryKey()
{
  __asm {
    lea ecx, [ebp-30h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091add0 : g_configCacheSetStringUnwind
const NativeCppUnwindEntry g_configCacheSetStringUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheSetStringSectionKey)}, // UnwindConfigCacheSetStringSectionKey
    {0, NativeAddress(NativeEntry_UnwindConfigCacheSetStringSection)},    // UnwindConfigCacheSetStringSection
    {0, NativeAddress(NativeEntry_UnwindConfigCacheSetStringEntryKey)},   // UnwindConfigCacheSetStringEntryKey
    {-1, 0},
};

// RavenShield.exe data @ 1091adf8 : g_configCacheSetStringCatches
const NativeCppCatchHandler g_configCacheSetStringCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x10910bc5}, // RethrowConfigCacheSetStringPointer
    {0, 0, 0, 0x10910bd9},                                               // UnwindConfigCacheSetStringFailure
};

// RavenShield.exe data @ 1091ae18 : g_configCacheSetStringTryBlocks
const NativeCppTryBlock g_configCacheSetStringTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_configCacheSetStringCatches)},
};

// RavenShield.exe data @ 1091ae2c : g_configCacheSetStringExceptionInfo
const NativeCppFunctionInfo g_configCacheSetStringExceptionInfo = {
    0x19930520, 5, NativeAddress(g_configCacheSetStringUnwind), 1, NativeAddress(g_configCacheSetStringTryBlocks),
    0,          0};

// RavenShield.exe @ 10912e4a : HandleConfigCacheSetStringException
// Supply SetString's five-state key/section cleanup map and typed-pointer/catch-all guard metadata.
__declspec(naked) void HandleConfigCacheSetStringException()
{
  __asm {
    mov eax, offset g_configCacheSetStringExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10917e94 : g_configCacheGetSectionGuardName
const char16_t g_configCacheGetSectionGuardName[] = u"FConfigCacheIni::GetSection";
// RavenShield.exe data @ 10917ecc : g_configSectionEntryFormat
const char16_t g_configSectionEntryFormat[] = u"%s=%s";
// RavenShield.exe data @ 10917ed8 : g_configCacheGetSectionPrivateGuardName
const char16_t g_configCacheGetSectionPrivateGuardName[] = u"FConfigCacheIni::GetSectionPrivate";
// RavenShield.exe data @ 10917f58 : g_configCacheEmptySectionGuardName
const char16_t g_configCacheEmptySectionGuardName[] = u"FConfigCacheIni::EmptySection";

// RavenShield.exe @ 109107f0 : FConfigCacheIni::GetSection
// Emit NUL-separated key=value pairs; preserve the key-only capacity test and success after a capacity break.
int32_t FConfigCacheIni::GetSection(const uint16_t *section, uint16_t *result, int32_t size, const uint16_t *filename)
{
  try
  {
    result[0] = 0;
    FConfigFile *file = FConfigCacheIni::Find(filename, 0);
    if (file == nullptr) return 0;
    FConfigSection *foundSection;
    {
      FString sectionKey(section);
      foundSection = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file)->Find(sectionKey);
    }
    if (foundSection == nullptr) return 0;
    using EntryMap = TMapBase<FString, FString>;
    auto *entries = reinterpret_cast<EntryMap *>(foundSection);
    uint16_t *cursor = result;
    const uint32_t baseAddress = reinterpret_cast<uint32_t>(result);
    {
      for (EntryMap::TIterator it(*entries); it; ++it)
      {
        const int32_t keyLength = appStrlen(*it.Key());
        const uint32_t byteOffset = reinterpret_cast<uint32_t>(cursor) - baseAddress;
        const int32_t used = static_cast<int32_t>(byteOffset) >> 1; // Native SAR after wrapped pointer subtraction.
        const int32_t required =
            static_cast<int32_t>(static_cast<uint32_t>(used) + static_cast<uint32_t>(keyLength) + 1);
        if (required >= size) break; // Native omits value length, equals sign and the final extra NUL from this gate.
        FString &storedKey = it.Key();
        const uint16_t *valueText = *it.Value(); // Preserve value-text evaluation before key-text evaluation.
        const uint16_t *keyText = *storedKey;
        const int32_t written =
            appSprintf(cursor, reinterpret_cast<const uint16_t *>(g_configSectionEntryFormat), keyText, valueText);
        const uint32_t next = reinterpret_cast<uint32_t>(cursor) + static_cast<uint32_t>(written) * 2 + 2;
        cursor = reinterpret_cast<uint16_t *>(next);
      }
    }
    *cursor = 0; // Iterator cleanup precedes the final list terminator, including capacity-break paths.
    return 1;
  }
  // RavenShield.exe @ 10910936 : RethrowConfigCacheGetSectionPointer
  // Throw a copy of the caught unsigned-short pointer after local cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1091094a : UnwindConfigCacheGetSectionFailure
  // Append GetSection's guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetSectionGuardName));
    throw;
  }
}

// RavenShield.exe @ 10910970 : FConfigCacheIni::GetSectionPrivate
// Optionally create and return the stored section map; forced or non-const access marks a returned file dirty.
TMultiMap<FString, FString> *FConfigCacheIni::GetSectionPrivate(const uint16_t *section, int32_t force,
                                                                int32_t constAccess, const uint16_t *filename)
{
  try
  {
    FConfigFile *file = FConfigCacheIni::Find(filename, force);
    if (file == nullptr) return nullptr;
    auto *sections = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file);
    FConfigSection *foundSection;
    {
      FString sectionKey(section);
      foundSection = sections->Find(sectionKey);
    }
    if (foundSection == nullptr && force != 0)
    {
      FConfigSection emptySection;
      foundSection = &sections->Set(section, emptySection);
    }
    if (foundSection != nullptr && (force != 0 || constAccess == 0))
      *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(file) + 0x14) = 1;
    return reinterpret_cast<TMultiMap<FString, FString> *>(foundSection); // Entry-map prefix is at section +0.
  }
  // RavenShield.exe @ 10910a5a : RethrowConfigCacheGetSectionPrivatePointer
  // Copy-throw the caught unsigned-short pointer after section/key cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10910a6e : UnwindConfigCacheGetSectionPrivateFailure
  // Append the private-section guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheGetSectionPrivateGuardName));
    throw;
  }
}

// RavenShield.exe @ 10910c50 : FConfigCacheIni::EmptySection
// Empty only an existing section with entries, retaining the section and marking Dirty after successful clearing.
void FConfigCacheIni::EmptySection(const uint16_t *section, const uint16_t *filename)
{
  try
  {
    FConfigFile *file = FConfigCacheIni::Find(filename, 0);
    if (file == nullptr) return;
    FConfigSection *foundSection;
    {
      FString sectionKey(section);
      foundSection = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file)->Find(sectionKey);
    }
    if (foundSection != nullptr)
    {
      using EntryMap = TMapBase<FString, FString>;
      auto *entries = reinterpret_cast<EntryMap *>(foundSection);
      int32_t hadEntries;
      {
        EntryMap::TIterator it(*entries);
        hadEntries = static_cast<int32_t>(it) != 0;
      }
      if (hadEntries != 0)
      {
        entries->Empty();
        *reinterpret_cast<int32_t *>(reinterpret_cast<uint8_t *>(file) + 0x14) = 1;
      }
    }
  }
  // RavenShield.exe @ 10910d3a : RethrowConfigCacheEmptySectionPointer
  // Copy-throw the caught pointer from EBP-20 into a throw object at EBP-1c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10910d4e : UnwindConfigCacheEmptySectionFailure
  // Append EmptySection's guard after conditional iterator/key cleanup and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheEmptySectionGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912de0 : UnwindConfigCacheGetSectionKey
// Destroy GetSection's completed section key at parent EBP-24.
__declspec(naked) void UnwindConfigCacheGetSectionKey()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912de9 : UnwindConfigCacheGetSectionIterator
// Destroy GetSection's completed entry iterator at parent EBP-28.
__declspec(naked) void UnwindConfigCacheGetSectionIterator()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp NativeEntry_TMapBase_FString_FString_TIterator_DestroyTIterator
  }
}

// RavenShield.exe @ 10912e00 : UnwindConfigCacheGetSectionPrivateKey
// Destroy the private-section getter's completed key at parent EBP-24.
__declspec(naked) void UnwindConfigCacheGetSectionPrivateKey()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912e09 : UnwindConfigCacheGetSectionPrivatePairs
// Destroy only the completed entry array when temporary section hash construction fails.
__declspec(naked) void UnwindConfigCacheGetSectionPrivatePairs()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray
  }
}

// RavenShield.exe @ 10912e11 : UnwindConfigCacheGetSectionPrivateMap
// Destroy the private-section getter's completed temporary section map at parent EBP-2c.
__declspec(naked) void UnwindConfigCacheGetSectionPrivateMap()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp NativeEntry_ForwardFStringMapDestruction
  }
}

// RavenShield.exe @ 10912e60 : UnwindConfigCacheEmptySectionKey
// Destroy EmptySection's completed section key at parent EBP-2c.
__declspec(naked) void UnwindConfigCacheEmptySectionKey()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912e69 : UnwindConfigCacheEmptySectionIterator
// Clear the constructed-iterator bit at parent EBP-14 before conditionally destroying the iterator at EBP-30.
__declspec(naked) void UnwindConfigCacheEmptySectionIterator()
{
  __asm {
    mov eax, [ebp-14h]
    and eax, 1
    je iteratorAbsent
    and dword ptr [ebp-14h], 0fffffffeh
    lea ecx, [ebp-30h]
    jmp NativeEntry_TMapBase_FString_FString_TIterator_DestroyTIterator
  iteratorAbsent:
    ret
  }
}

// RavenShield.exe data @ 1091ace8 : g_configCacheGetSectionUnwind
const NativeCppUnwindEntry g_configCacheGetSectionUnwind[4] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheGetSectionKey)},      // UnwindConfigCacheGetSectionKey
    {0, NativeAddress(NativeEntry_UnwindConfigCacheGetSectionIterator)}, // UnwindConfigCacheGetSectionIterator
    {-1, 0},
};

// RavenShield.exe data @ 1091ad08 : g_configCacheGetSectionCatches
const NativeCppCatchHandler g_configCacheGetSectionCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x10910936}, // RethrowConfigCacheGetSectionPointer
    {0, 0, 0, 0x1091094a},                                               // UnwindConfigCacheGetSectionFailure
};

// RavenShield.exe data @ 1091ad28 : g_configCacheGetSectionTryBlocks
const NativeCppTryBlock g_configCacheGetSectionTryBlocks[1] = {
    {0, 2, 3, 2, NativeAddress(g_configCacheGetSectionCatches)},
};

// RavenShield.exe data @ 1091ad3c : g_configCacheGetSectionExceptionInfo
const NativeCppFunctionInfo g_configCacheGetSectionExceptionInfo = {
    0x19930520, 4, NativeAddress(g_configCacheGetSectionUnwind), 1, NativeAddress(g_configCacheGetSectionTryBlocks),
    0,          0};

// RavenShield.exe @ 10912df1 : HandleConfigCacheGetSectionException
// Supply the method's local cleanup/typed-pointer/catch-all metadata to shared C++ exception dispatch.
__declspec(naked) void HandleConfigCacheGetSectionException()
{
  __asm {
    mov eax, offset g_configCacheGetSectionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 1091ad58 : g_configCacheGetSectionPrivateUnwind
const NativeCppUnwindEntry g_configCacheGetSectionPrivateUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheGetSectionPrivateKey)},   // UnwindConfigCacheGetSectionPrivateKey
    {0, NativeAddress(NativeEntry_UnwindConfigCacheGetSectionPrivatePairs)}, // UnwindConfigCacheGetSectionPrivatePairs
    {0, NativeAddress(NativeEntry_UnwindConfigCacheGetSectionPrivateMap)},   // UnwindConfigCacheGetSectionPrivateMap
    {-1, 0},
};

// RavenShield.exe data @ 1091ad80 : g_configCacheGetSectionPrivateCatches
const NativeCppCatchHandler g_configCacheGetSectionPrivateCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x10910a5a}, // RethrowConfigCacheGetSectionPrivatePointer
    {0, 0, 0, 0x10910a6e},                                               // UnwindConfigCacheGetSectionPrivateFailure
};

// RavenShield.exe data @ 1091ada0 : g_configCacheGetSectionPrivateTryBlocks
const NativeCppTryBlock g_configCacheGetSectionPrivateTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_configCacheGetSectionPrivateCatches)},
};

// RavenShield.exe data @ 1091adb4 : g_configCacheGetSectionPrivateExceptionInfo
const NativeCppFunctionInfo g_configCacheGetSectionPrivateExceptionInfo = {
    0x19930520,
    5,
    NativeAddress(g_configCacheGetSectionPrivateUnwind),
    1,
    NativeAddress(g_configCacheGetSectionPrivateTryBlocks),
    0,
    0};

// RavenShield.exe @ 10912e19 : HandleConfigCacheGetSectionPrivateException
// Supply the method's local cleanup/typed-pointer/catch-all metadata to shared C++ exception dispatch.
__declspec(naked) void HandleConfigCacheGetSectionPrivateException()
{
  __asm {
    mov eax, offset g_configCacheGetSectionPrivateExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 1091ae6c : g_configCacheEmptySectionUnwind
const NativeCppUnwindEntry g_configCacheEmptySectionUnwind[4] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCacheEmptySectionKey)},      // UnwindConfigCacheEmptySectionKey
    {0, NativeAddress(NativeEntry_UnwindConfigCacheEmptySectionIterator)}, // UnwindConfigCacheEmptySectionIterator
    {-1, 0},
};

// RavenShield.exe data @ 1091ae8c : g_configCacheEmptySectionCatches
const NativeCppCatchHandler g_configCacheEmptySectionCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x20, 0x10910d3a}, // RethrowConfigCacheEmptySectionPointer
    {0, 0, 0, 0x10910d4e},                                               // UnwindConfigCacheEmptySectionFailure
};

// RavenShield.exe data @ 1091aeac : g_configCacheEmptySectionTryBlocks
const NativeCppTryBlock g_configCacheEmptySectionTryBlocks[1] = {
    {0, 2, 3, 2, NativeAddress(g_configCacheEmptySectionCatches)},
};

// RavenShield.exe data @ 1091aec0 : g_configCacheEmptySectionExceptionInfo
const NativeCppFunctionInfo g_configCacheEmptySectionExceptionInfo = {
    0x19930520, 4, NativeAddress(g_configCacheEmptySectionUnwind), 1, NativeAddress(g_configCacheEmptySectionTryBlocks),
    0,          0};

// RavenShield.exe @ 10912e82 : HandleConfigCacheEmptySectionException
// Supply the method's local cleanup/typed-pointer/catch-all metadata to shared C++ exception dispatch.
__declspec(naked) void HandleConfigCacheEmptySectionException()
{
  __asm {
    mov eax, offset g_configCacheEmptySectionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

class FOutputDevice;
extern int32_t __cdecl winGetSizeUNICODE(const char *text);
extern uint16_t *__cdecl winToUNICODE(uint16_t *destination, const char *text, int32_t count);
extern const char *__cdecl appToAnsi(const uint16_t *text);

// RavenShield.exe data @ 10917be8 : g_configCacheDumpGuardName
const char16_t g_configCacheDumpGuardName[] = u"FConfigCacheIni::Dump";
// RavenShield.exe data @ 10917c14 : g_configFilesMapHeading
const char16_t g_configFilesMapHeading[] = u"Files map:";
// RavenShield.exe data @ 10917cb4 : g_configCachePBfindKeyGuardName
const char16_t g_configCachePBfindKeyGuardName[] = u"FConfigCacheIni::PBfindKey";
// RavenShield.exe data @ 10917cf0 : g_configAnsiOpenQuote
const char g_configAnsiOpenQuote[] = "\"";
// RavenShield.exe data @ 10917cec : g_configAnsiQuotedFilenameEnd
const char g_configAnsiQuotedFilenameEnd[] = "\" ";

// Find the terminating NUL in the caller's existing ANSI buffer.
static inline char *FindConfigAnsiTerminator(char *text)
{
  while (*text != 0) ++text;
  return text;
}

// Count ANSI bytes with the native 32-bit pointer-difference wrap.
static inline uint32_t ConfigAnsiLength(const char *text)
{
  const char *end = text;
  while (*end != 0) ++end;
  return reinterpret_cast<uint32_t>(end) - reinterpret_cast<uint32_t>(text);
}

// Copy DWORD groups then remaining bytes forward, preserving the native overlap and access order.
static inline void CopyConfigAnsiBytesForward(char *destination, const char *source, uint32_t bytes)
{
  for (uint32_t words = bytes >> 2; words != 0; --words)
  {
    *reinterpret_cast<uint32_t *>(destination) = *reinterpret_cast<const uint32_t *>(source);
    destination += 4;
    source += 4;
  }
  for (uint32_t tail = bytes & 3; tail != 0; --tail) *destination++ = *source++;
}

// RavenShield.exe @ 1090e850 : FConfigCacheIni::Dump
// Log the native heading, then dump file-map bucket occupancy through its concrete map subobject at +4.
void FConfigCacheIni::Dump(FOutputDevice &output)
{
  try
  {
    output.Log(reinterpret_cast<const uint16_t *>(g_configFilesMapHeading));
    reinterpret_cast<TMapBase<FString, FConfigFile> *>(reinterpret_cast<uint8_t *>(this) + 4)->Dump(output);
  }
  // RavenShield.exe @ 1090e8a6 : RethrowConfigCacheDumpPointer
  // Throw a copy of the caught unsigned-short pointer value.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090e8ba : UnwindConfigCacheDumpFailure
  // Append the cache Dump guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCacheDumpGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091a714 : g_configCacheDumpUnwind
const NativeCppUnwindEntry g_configCacheDumpUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091a724 : g_configCacheDumpCatches
const NativeCppCatchHandler g_configCacheDumpCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090e8a6}, // RethrowConfigCacheDumpPointer
    {0, 0, 0, 0x1090e8ba},                                               // UnwindConfigCacheDumpFailure
};

// RavenShield.exe data @ 1091a744 : g_configCacheDumpTryBlocks
const NativeCppTryBlock g_configCacheDumpTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_configCacheDumpCatches)},
};

// RavenShield.exe data @ 1091a758 : g_configCacheDumpExceptionInfo
const NativeCppFunctionInfo g_configCacheDumpExceptionInfo = {
    0x19930520, 2, NativeAddress(g_configCacheDumpUnwind), 1, NativeAddress(g_configCacheDumpTryBlocks), 0, 0};

// RavenShield.exe @ 10912c00 : HandleConfigCacheDumpException
// Supply Dump's two-state typed-pointer/catch-all guard map to shared C++ exception dispatch.
__declspec(naked) void HandleConfigCacheDumpException()
{
  __asm {
    mov eax, offset g_configCacheDumpExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 1090e9a0 : FConfigCacheIni::PBfindKey
// Append quoted cached filenames containing the ANSI section/key, retaining existing output and the native size gate.
void FConfigCacheIni::PBfindKey(const char *section, const char *key, char *output)
{
  try
  {
    using FileMap = TMapBase<FString, FConfigFile>;
    auto *files = this == nullptr ? nullptr : reinterpret_cast<FileMap *>(reinterpret_cast<uint8_t *>(this) + 4);
    for (FileMap::TIterator it(*files); it; ++it)
    {
      FConfigFile &file = it.Value(); // Native captures the file value address before conversion calls.
      uint16_t *sectionBuffer = nullptr;
      if (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        sectionBuffer = reinterpret_cast<uint16_t *>(_alloca(bytes)); // Remains allocated until this method returns.
      }
      const int32_t sectionCount = winGetSizeUNICODE(section);
      uint16_t *sectionText = winToUNICODE(sectionBuffer, section, sectionCount);
      FConfigSection *foundSection;
      {
        FString sectionKey(sectionText);
        foundSection = reinterpret_cast<TMapBase<FString, FConfigSection> *>(&file)->Find(sectionKey);
      }
      if (foundSection == nullptr) continue;
      uint16_t *keyBuffer = nullptr;
      if (static_cast<uint32_t>(winGetSizeUNICODE(key)) * 2 != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(key)) * 2 + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        keyBuffer = reinterpret_cast<uint16_t *>(_alloca(bytes));
      }
      const int32_t keyCount = winGetSizeUNICODE(key);
      uint16_t *keyText = winToUNICODE(keyBuffer, key, keyCount);
      FString *foundValue;
      {
        FString entryKey(keyText);
        foundValue = reinterpret_cast<TMapBase<FString, FString> *>(foundSection)->Find(entryKey);
      }
      if (foundValue == nullptr) continue;
      const uint16_t *storedFilename = *reinterpret_cast<const uint16_t *const *>(&it.Key());
      const char *filename = appToAnsi(storedFilename); // Raw FString Data, without operator*'s empty fallback.
      while (*filename == ' ' || *filename == '\t') ++filename;
      const uint32_t filenameLength = ConfigAnsiLength(filename);
      const uint32_t outputLength = ConfigAnsiLength(output);
      if (filenameLength + outputLength + 3 < 0xff)
      {
        char *end = FindConfigAnsiTerminator(output);
        *reinterpret_cast<uint16_t *>(end) = *reinterpret_cast<const uint16_t *>(g_configAnsiOpenQuote);
        const uint32_t bytes = ConfigAnsiLength(filename) + 1; // Re-evaluate after writing the opening quote.
        end = FindConfigAnsiTerminator(output);
        CopyConfigAnsiBytesForward(end, filename, bytes);
        end = FindConfigAnsiTerminator(output);
        *reinterpret_cast<uint16_t *>(end) = *reinterpret_cast<const uint16_t *>(g_configAnsiQuotedFilenameEnd);
        end[2] = g_configAnsiQuotedFilenameEnd[2];
      }
    }
  }
  // RavenShield.exe @ 1090ebfa : RethrowConfigCachePBfindKeyPointer
  // Copy-throw the caught pointer from EBP-1c into the throw object at EBP-18 after iterator/key cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090ec0e : UnwindConfigCachePBfindKeyFailure
  // Append PBfindKey's guard and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCachePBfindKeyGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912c20 : UnwindConfigCachePBfindKeyIterator
// Destroy the completed file iterator at parent EBP-44.
__declspec(naked) void UnwindConfigCachePBfindKeyIterator()
{
  __asm {
    lea ecx, [ebp-44h]
    jmp NativeEntry_TMapBase_FString_FConfigFile_TIterator_DestroyTIterator
  }
}

// RavenShield.exe @ 10912c28 : UnwindConfigCachePBfindKeySectionKey
// Destroy the completed converted section-key string at parent EBP-28.
__declspec(naked) void UnwindConfigCachePBfindKeySectionKey()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912c31 : UnwindConfigCachePBfindKeyEntryKey
// Destroy the completed converted entry-key string at parent EBP-34.
__declspec(naked) void UnwindConfigCachePBfindKeyEntryKey()
{
  __asm {
    lea ecx, [ebp-34h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091a7d4 : g_configCachePBfindKeyUnwind
const NativeCppUnwindEntry g_configCachePBfindKeyUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigCachePBfindKeyIterator)},   // UnwindConfigCachePBfindKeyIterator
    {1, NativeAddress(NativeEntry_UnwindConfigCachePBfindKeySectionKey)}, // UnwindConfigCachePBfindKeySectionKey
    {1, NativeAddress(NativeEntry_UnwindConfigCachePBfindKeyEntryKey)},   // UnwindConfigCachePBfindKeyEntryKey
    {-1, 0},
};

// RavenShield.exe data @ 1091a7fc : g_configCachePBfindKeyCatches
const NativeCppCatchHandler g_configCachePBfindKeyCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x1090ebfa}, // RethrowConfigCachePBfindKeyPointer
    {0, 0, 0, 0x1090ec0e},                                               // UnwindConfigCachePBfindKeyFailure
};

// RavenShield.exe data @ 1091a81c : g_configCachePBfindKeyTryBlocks
const NativeCppTryBlock g_configCachePBfindKeyTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_configCachePBfindKeyCatches)},
};

// RavenShield.exe data @ 1091a830 : g_configCachePBfindKeyExceptionInfo
const NativeCppFunctionInfo g_configCachePBfindKeyExceptionInfo = {
    0x19930520, 5, NativeAddress(g_configCachePBfindKeyUnwind), 1, NativeAddress(g_configCachePBfindKeyTryBlocks),
    0,          0};

// RavenShield.exe @ 10912c3a : HandleConfigCachePBfindKeyException
// Supply the five-state file iterator/converted-key cleanup map and typed-pointer/catch-all guard metadata.
__declspec(naked) void HandleConfigCachePBfindKeyException()
{
  __asm {
    mov eax, offset g_configCachePBfindKeyExceptionInfo
    jmp DispatchExecutableCppException
  }
}

extern const char *__cdecl FindCaseInsensitiveAnsiSubstring(const char *text, const char *needle);
extern int32_t __cdecl RegisterExecutableAtExit(void(__cdecl *callback)());

// POD mirrors of the native iterator references/words; resets overwrite these fields without destroying old state.
template <class Value> struct ConfigQueryIteratorState
{
  TMapBase<FString, Value> *Map;
  FArray *Pairs;
  int32_t Index;
  int32_t Removed;
};

// RavenShield.exe data @ 10940608 : g_pbQueryEntryIterator
ConfigQueryIteratorState<FString> g_pbQueryEntryIterator = {};
// RavenShield.exe data @ 10940618 : g_pbQueryCurrentSection
FConfigSection *g_pbQueryCurrentSection = nullptr;
// RavenShield.exe data @ 1094061c : g_pbQueryFileIterator
ConfigQueryIteratorState<FConfigFile> g_pbQueryFileIterator = {};
// RavenShield.exe data @ 1094062c : g_pbQueryInitializationBits
uint32_t g_pbQueryInitializationBits = 0; // Bits 0/1/2: file iterator, cached section, entry iterator.
// RavenShield.exe data @ 10917cf4 : g_configCachePBgetSectionGuardName
const char16_t g_configCachePBgetSectionGuardName[] = u"FConfigCacheIni::PBgetSection";
// RavenShield.exe data @ 10917d30 : g_configAnsiFieldSeparator
const char g_configAnsiFieldSeparator[] = " ";

// RavenShield.exe @ 10913060 : DestroyPBgetSectionFileIterator
// At process exit, relax the saved file map only if the persistent iterator recorded removals.
void __cdecl DestroyPBgetSectionFileIterator()
{
  if (g_pbQueryFileIterator.Removed != 0) g_pbQueryFileIterator.Map->Relax();
}

// RavenShield.exe @ 10913080 : DestroyPBgetSectionEntryIterator
// At process exit, relax the saved entry map only if the persistent iterator recorded removals.
void __cdecl DestroyPBgetSectionEntryIterator()
{
  if (g_pbQueryEntryIterator.Removed != 0) g_pbQueryEntryIterator.Map->Relax();
}

// RavenShield.exe @ 10912c50 : ResetPBgetSectionInitialization
// Clear only the cached-section initialization bit when its conversion/lookup/temporary destruction fails.
__declspec(naked) void ResetPBgetSectionInitialization()
{
  __asm {
    mov eax, dword ptr [g_pbQueryInitializationBits]
    and eax, 0fffffffdh
    mov dword ptr [g_pbQueryInitializationBits], eax
    ret
  }
}

// RavenShield.exe @ 1090ed60 : FConfigCacheIni::PBgetSection
// Resume the shared file/entry cursors, return after one filtered entry, and reset only the file cursor at exhaustion.
void FConfigCacheIni::PBgetSection(const char *section, const char *filter, char *output)
{
  const uint8_t flagsOnEntry = static_cast<uint8_t>(g_pbQueryInitializationBits); // Before guard state zero.
  try
  {
    using FileMap = TMapBase<FString, FConfigFile>;
    using EntryMap = TMapBase<FString, FString>;
    auto &files = g_pbQueryFileIterator;
    auto &entries = g_pbQueryEntryIterator;
    if ((flagsOnEntry & 1) == 0)
    {
      g_pbQueryInitializationBits |= 1;
      files.Map = this == nullptr ? nullptr : reinterpret_cast<FileMap *>(reinterpret_cast<uint8_t *>(this) + 4);
      files.Pairs = reinterpret_cast<FArray *>(files.Map);
      files.Index = 0;
      files.Removed = 0;
      RegisterExecutableAtExit(DestroyPBgetSectionFileIterator); // Result ignored, bit retained.
    }
    int32_t sectionChanged = 0; // Sticky for the rest of this call after the first changed section pointer.
    for (;;)
    {
      const int32_t fileCount = files.Pairs->Num();
      if (files.Index >= fileCount)
      {
        files.Map = this == nullptr ? nullptr : reinterpret_cast<FileMap *>(reinterpret_cast<uint8_t *>(this) + 4);
        files.Pairs = reinterpret_cast<FArray *>(files.Map);
        files.Index = 0;
        files.Removed = 0;
        return; // Cached section, entry cursor, initialization bits and output are retained.
      }
      const uint32_t data = *reinterpret_cast<const uint32_t *>(files.Pairs);
      auto *file = reinterpret_cast<FConfigFile *>(data + static_cast<uint32_t>(files.Index) * 0x2c + 0x10);
      if ((g_pbQueryInitializationBits & 2) == 0)
      {
        g_pbQueryInitializationBits |= 2;
        try
        { // Model compiler initializer unwind action 10912c50 around conversion, lookup and key destruction.
          uint16_t *initialBuffer = nullptr;
          if (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 != 0)
          {
            uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 + 7) & 0xfffffff8;
            bytes = (bytes + 3) & 0xfffffffc;
            initialBuffer = reinterpret_cast<uint16_t *>(_alloca(bytes));
          }
          const int32_t initialCount = winGetSizeUNICODE(section);
          uint16_t *initialText = winToUNICODE(initialBuffer, section, initialCount);
          FString initialKey(initialText);
          auto *sections = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file);
          g_pbQueryCurrentSection = sections->Find(initialKey);
        }
        catch (...)
        {
          ResetPBgetSectionInitialization();
          throw;
        }
      }
      uint16_t *sectionBuffer = nullptr;
      if (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeUNICODE(section)) * 2 + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        sectionBuffer = reinterpret_cast<uint16_t *>(_alloca(bytes));
      }
      const int32_t sectionCount = winGetSizeUNICODE(section);
      uint16_t *sectionText = winToUNICODE(sectionBuffer, section, sectionCount);
      FConfigSection *foundSection;
      {
        FString sectionKey(sectionText);
        foundSection = reinterpret_cast<TMapBase<FString, FConfigSection> *>(file)->Find(sectionKey);
      }
      if (g_pbQueryCurrentSection != foundSection)
      {
        sectionChanged = 1;
        g_pbQueryCurrentSection = foundSection;
      }
      if (g_pbQueryCurrentSection != nullptr)
      {
        if ((g_pbQueryInitializationBits & 4) == 0)
        {
          g_pbQueryInitializationBits |= 4;
          entries.Map = reinterpret_cast<EntryMap *>(g_pbQueryCurrentSection);
          entries.Pairs = reinterpret_cast<FArray *>(entries.Map);
          entries.Index = 0;
          entries.Removed = 0;
          RegisterExecutableAtExit(DestroyPBgetSectionEntryIterator); // Result ignored.
        }
        if (sectionChanged != 0)
        {
          entries.Map = reinterpret_cast<EntryMap *>(g_pbQueryCurrentSection);
          entries.Pairs = reinterpret_cast<FArray *>(entries.Map);
          entries.Index = 0;
          entries.Removed = 0;
        }
        for (;;)
        {
          const int32_t entryCount = entries.Pairs->Num();
          if (entries.Index >= entryCount) break;
          uint32_t entryData = *reinterpret_cast<const uint32_t *>(entries.Pairs);
          uint32_t entryOffset = static_cast<uint32_t>(entries.Index) * 0x1c;
          const uint16_t *valueText = reinterpret_cast<FString *>(entryData + entryOffset + 0x10)->operator*();
          const char *ansiValue = appToAnsi(valueText);
          while (*ansiValue == ' ') ++ansiValue; // Value filtering trims spaces only, unlike filename trimming.
          if (FindCaseInsensitiveAnsiSubstring(ansiValue, filter) != nullptr)
          {
            const uint32_t fileData = *reinterpret_cast<const uint32_t *>(files.Pairs);
            const uint32_t fileOffset = static_cast<uint32_t>(files.Index) * 0x2c;
            const uint16_t *filenameData = *reinterpret_cast<const uint16_t *const *>(fileData + fileOffset + 4);
            const char *filename = appToAnsi(filenameData);
            while (*filename == ' ' || *filename == '\t') ++filename;
            entryData = *reinterpret_cast<const uint32_t *>(entries.Pairs);
            entryOffset = static_cast<uint32_t>(entries.Index) * 0x1c;
            const uint16_t *keyText = reinterpret_cast<FString *>(entryData + entryOffset + 4)->operator*();
            const char *ansiKey = appToAnsi(keyText);
            const uint32_t filenameLength = ConfigAnsiLength(filename);
            const uint32_t sectionLength = ConfigAnsiLength(section);
            const uint32_t keyLength = ConfigAnsiLength(ansiKey);
            const uint32_t length = filenameLength + sectionLength + keyLength;
            if (length < 0xfd)
            {
              const char *source = section;
              char *destination = output;
              char character;
              do
              {
                character = *source++;
                *destination++ = character;
              } while (character != 0);
              char *end = FindConfigAnsiTerminator(output);
              *reinterpret_cast<uint16_t *>(end) = *reinterpret_cast<const uint16_t *>(g_configAnsiFieldSeparator);
              uint32_t bytes = ConfigAnsiLength(ansiKey) + 1;
              end = FindConfigAnsiTerminator(output);
              CopyConfigAnsiBytesForward(end, ansiKey, bytes);
              end = FindConfigAnsiTerminator(output);
              *reinterpret_cast<uint16_t *>(end) = *reinterpret_cast<const uint16_t *>(g_configAnsiFieldSeparator);
              bytes = ConfigAnsiLength(filename) + 1;
              end = FindConfigAnsiTerminator(output);
              CopyConfigAnsiBytesForward(end, filename, bytes);
            }
            entries.Index = static_cast<int32_t>(static_cast<uint32_t>(entries.Index) + 1);
            return; // Advance past a matching entry even when the size gate leaves output unchanged.
          }
          entries.Index = static_cast<int32_t>(static_cast<uint32_t>(entries.Index) + 1);
        }
      }
      files.Index = static_cast<int32_t>(static_cast<uint32_t>(files.Index) + 1);
    }
  }
  // RavenShield.exe @ 1090f171 : RethrowConfigCachePBgetSectionPointer
  // Copy-throw the caught pointer from EBP-20 into the new throw object at EBP-1c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090f185 : UnwindConfigCachePBgetSectionFailure
  // Append PBgetSection's guard after initializer/key cleanup and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configCachePBgetSectionGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912c5e : UnwindPBgetSectionInitialKey
// Destroy the cached-section initializer's completed key at parent EBP-2c before clearing its initialization bit.
__declspec(naked) void UnwindPBgetSectionInitialKey()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912c67 : UnwindPBgetSectionRepeatedKey
// Destroy the ordinary section lookup's completed key at parent EBP-38 without resetting initialization state.
__declspec(naked) void UnwindPBgetSectionRepeatedKey()
{
  __asm {
    lea ecx, [ebp-38h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091a84c : g_configCachePBgetSectionUnwind
const NativeCppUnwindEntry g_configCachePBgetSectionUnwind[5] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_ResetPBgetSectionInitialization)}, // ResetPBgetSectionInitialization
    {1, NativeAddress(NativeEntry_UnwindPBgetSectionInitialKey)},    // UnwindPBgetSectionInitialKey
    {0, NativeAddress(NativeEntry_UnwindPBgetSectionRepeatedKey)},   // UnwindPBgetSectionRepeatedKey
    {-1, 0},
};

// RavenShield.exe data @ 1091a874 : g_configCachePBgetSectionCatches
const NativeCppCatchHandler g_configCachePBgetSectionCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x20, 0x1090f171}, // RethrowConfigCachePBgetSectionPointer
    {0, 0, 0, 0x1090f185},                                               // UnwindConfigCachePBgetSectionFailure
};

// RavenShield.exe data @ 1091a894 : g_configCachePBgetSectionTryBlocks
const NativeCppTryBlock g_configCachePBgetSectionTryBlocks[1] = {
    {0, 3, 4, 2, NativeAddress(g_configCachePBgetSectionCatches)},
};

// RavenShield.exe data @ 1091a8a8 : g_configCachePBgetSectionExceptionInfo
const NativeCppFunctionInfo g_configCachePBgetSectionExceptionInfo = {
    0x19930520, 5, NativeAddress(g_configCachePBgetSectionUnwind), 1, NativeAddress(g_configCachePBgetSectionTryBlocks),
    0,          0};

// RavenShield.exe @ 10912c70 : HandleConfigCachePBgetSectionException
// Supply five initializer/key cleanup states and typed-pointer/catch-all metadata to shared exception dispatch.
__declspec(naked) void HandleConfigCachePBgetSectionException()
{
  __asm {
    mov eax, offset g_configCachePBgetSectionExceptionInfo
    jmp DispatchExecutableCppException
  }
}
