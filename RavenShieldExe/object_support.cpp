#include "native_symbols.hpp"
// Executable template wrappers around imported class loading and object construction.
#include "object_support.hpp"

// RavenShield.exe @ 10908ec0 : ParseClass
// Parse an object constrained to UClass, forwarding the destination by reference and returning Core's full result.
int32_t __cdecl ParseClass(const uint16_t *stream, const uint16_t *match, UClass *&result, UObject *outer)
{
  const auto staticClass = *reinterpret_cast<UClass *(__cdecl **)()>(NativeAddress(NativeImport_UClass_StaticClass));
  UClass *type = staticClass();
  const auto parse =
      *reinterpret_cast<int32_t(__cdecl **)(const uint16_t *, const uint16_t *, UClass *, UObject **, UObject *)>(
          NativeAddress(NativeImport_ParseObject));
  return parse(stream, match, type, reinterpret_cast<UObject **>(&result), outer);
}

class UPackage;
class FOutputDevice;
using NativeStaticClass = UClass *(__cdecl *)();
using NativeIsChildOf = int32_t(__thiscall *)(const void *, const void *);
using NativeTransientPackage = UPackage *(__cdecl *)();
using NativeLoadClass = UClass *(__cdecl *)(UClass *, UObject *, const uint16_t *, const uint16_t *, uint32_t,
                                            UPackageMap *);
// Native FName occupies one stack word; the selected import's final argument is an int, not a UObject pointer.
using NativeConstructObject = UObject *(__cdecl *)(UClass *, UObject *, uint32_t, uint32_t, UObject *, FOutputDevice *,
                                                   int32_t);
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);

// RavenShield.exe data @ 10915368 : g_constructObjectClassExpression
const char g_constructObjectClassExpression[] = "Class->IsChildOf(T::StaticClass())";
// RavenShield.exe data @ 1091538c : g_constructObjectSourcePath
const char g_constructObjectSourcePath[] = "d:\\ravenshield\\412\\core\\inc\\UnObjBas.h";

// RavenShield.exe @ 10904200 : LoadRenderDeviceClass
// Load a class derived from URenderDevice, forwarding all five caller words and returning Core's class pointer.
UClass *__cdecl LoadRenderDeviceClass(UObject *outer, const uint16_t *name, const uint16_t *filename,
                                      uint32_t loadFlags, UPackageMap *sandbox)
{
  const auto staticClass =
      *reinterpret_cast<const NativeStaticClass *>(NativeAddress(NativeImport_URenderDevice_StaticClass));
  UClass *base = staticClass();
  const auto load = *reinterpret_cast<const NativeLoadClass *>(NativeAddress(NativeImport_UObject_StaticLoadClass));
  return load(base, outer, name, filename, loadFlags, sandbox);
}

// RavenShield.exe @ 10904230 : ConstructRenderDevice
// Check render-device ancestry, resolve the sentinel outer and construct with the live error sink and zero defaults.
URenderDevice *__cdecl ConstructRenderDevice(UClass *type, UObject *outer, uint32_t nameWord, uint32_t flags)
{
  const auto staticClass =
      *reinterpret_cast<const NativeStaticClass *>(NativeAddress(NativeImport_URenderDevice_StaticClass));
  UClass *base = staticClass();
  const auto isChildOf = *reinterpret_cast<const NativeIsChildOf *>(NativeAddress(NativeImport_UStruct_IsChildOf));
  if (isChildOf(type, base) == 0) appFailAssert(g_constructObjectClassExpression, g_constructObjectSourcePath, 0x476);
  if (reinterpret_cast<uint32_t>(outer) == 0xffffffffu)
  {
    const auto transientPackage =
        *reinterpret_cast<const NativeTransientPackage *>(NativeAddress(NativeImport_UObject_GetTransientPackage));
    outer = reinterpret_cast<UObject *>(transientPackage());
  }
  const uint32_t errorSlot = *reinterpret_cast<const uint32_t *>(NativeAddress(NativeImport_GError));
  FOutputDevice *error = *reinterpret_cast<FOutputDevice *const *>(errorSlot);
  const auto construct =
      *reinterpret_cast<const NativeConstructObject *>(NativeAddress(NativeImport_UObject_StaticConstructObject));
  return reinterpret_cast<URenderDevice *>(construct(type, outer, nameWord, flags, nullptr, error, 0));
}

// RavenShield.exe @ 109042a0 : ConstructEngine
// Check engine ancestry, resolve only the sentinel outer, and forward construction without adding ownership cleanup.
UEngine *__cdecl ConstructEngine(UClass *type, UObject *outer, uint32_t nameWord, uint32_t flags)
{
  const auto staticClass =
      *reinterpret_cast<const NativeStaticClass *>(NativeAddress(NativeImport_UEngine_StaticClass));
  UClass *base = staticClass();
  const auto isChildOf = *reinterpret_cast<const NativeIsChildOf *>(NativeAddress(NativeImport_UStruct_IsChildOf));
  if (isChildOf(type, base) == 0) appFailAssert(g_constructObjectClassExpression, g_constructObjectSourcePath, 0x476);
  if (reinterpret_cast<uint32_t>(outer) == 0xffffffffu)
  {
    const auto transientPackage =
        *reinterpret_cast<const NativeTransientPackage *>(NativeAddress(NativeImport_UObject_GetTransientPackage));
    outer = reinterpret_cast<UObject *>(transientPackage());
  }
  const uint32_t errorSlot = *reinterpret_cast<const uint32_t *>(NativeAddress(NativeImport_GError));
  FOutputDevice *error = *reinterpret_cast<FOutputDevice *const *>(errorSlot);
  const auto construct =
      *reinterpret_cast<const NativeConstructObject *>(NativeAddress(NativeImport_UObject_StaticConstructObject));
  return reinterpret_cast<UEngine *>(construct(type, outer, nameWord, flags, nullptr, error, 0));
}
