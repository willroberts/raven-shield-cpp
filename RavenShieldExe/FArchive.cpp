#include "native_symbols.hpp"
// Executable tail-forwarding bodies for the imported Core archive base interface.
#include <cstdint>

class FArchive;
class FLazyLoader;
class FName;
class UObject;

// RavenShield.exe @ 10911b6c : FArchive::GetError
// Preserve the receiver and full signed error-word result through the imported base getter.
__declspec(naked) int32_t FArchive::GetError()
{
  __asm jmp dword ptr [NativeImport_FArchive_GetError]
}

// RavenShield.exe @ 10911b72 : FArchive::Flush
// Tail-forward the inherited flush slot without adding file-writer flush behavior.
__declspec(naked) void FArchive::Flush()
{
  __asm jmp dword ptr [NativeImport_FArchive_Flush]
}

// RavenShield.exe @ 10911b78 : FArchive::DetachLazyLoader
// Preserve the receiver and lazy-loader pointer through the imported detach operation.
__declspec(naked) void FArchive::DetachLazyLoader(FLazyLoader *loader)
{
  __asm jmp dword ptr [NativeImport_FArchive_DetachLazyLoader]
}

// RavenShield.exe @ 10911b7e : FArchive::AttachLazyLoader
// Preserve the receiver and lazy-loader pointer through the imported attach operation.
__declspec(naked) void FArchive::AttachLazyLoader(FLazyLoader *loader)
{
  __asm jmp dword ptr [NativeImport_FArchive_AttachLazyLoader]
}

// RavenShield.exe @ 10911b84 : FArchive::SetStopper
// Tail-forward the signed stopper value without changing the receiver or stack argument.
__declspec(naked) void FArchive::SetStopper(int32_t stopper)
{
  __asm jmp dword ptr [NativeImport_FArchive_SetStopper]
}

// RavenShield.exe @ 10911b8a : FArchive::AtStopper
// Tail-forward the inherited stopper query and preserve its full signed result.
__declspec(naked) int32_t FArchive::AtStopper()
{
  __asm jmp dword ptr [NativeImport_FArchive_AtStopper]
}

// RavenShield.exe @ 10911b90 : FArchive::AtEnd
// Tail-forward the inherited end query without replacing its imported virtual-call behavior.
__declspec(naked) int32_t FArchive::AtEnd()
{
  __asm jmp dword ptr [NativeImport_FArchive_AtEnd]
}

// RavenShield.exe @ 10911b96 : FArchive::MapObject
// Preserve the object-pointer mapping argument and full signed result through the base import.
__declspec(naked) int32_t FArchive::MapObject(UObject *object)
{
  __asm jmp dword ptr [NativeImport_FArchive_MapObject]
}

// RavenShield.exe @ 10911b9c : FArchive::MapName
// Preserve the name-pointer mapping argument and full signed result through the base import.
__declspec(naked) int32_t FArchive::MapName(FName *name)
{
  __asm jmp dword ptr [NativeImport_FArchive_MapName]
}

// RavenShield.exe @ 10911ba2 : FArchive::operator<<(FName&)
// Tail-forward name-reference serialization and retain the returned archive reference in EAX.
__declspec(naked) FArchive &FArchive::operator<<(FName &name)
{
  __asm jmp dword ptr [NativeImport_FArchiveSerializeName]
}

// RavenShield.exe @ 10911ba8 : FArchive::operator<<(UObject*&)
// Tail-forward object-pointer-reference serialization and retain the returned archive reference in EAX.
__declspec(naked) FArchive &FArchive::operator<<(UObject *&object)
{
  __asm jmp dword ptr [NativeImport_FArchiveSerializeObject]
}

// RavenShield.exe @ 10911bae : FArchive::CountBytes
// Preserve both unsigned 32-bit byte-count arguments through the imported base operation.
__declspec(naked) void FArchive::CountBytes(uint32_t count, uint32_t maximum)
{
  __asm jmp dword ptr [NativeImport_FArchive_CountBytes]
}

// RavenShield.exe @ 10911bb4 : FArchive::Preload
// Tail-forward the inherited preload slot with its object pointer unchanged.
__declspec(naked) void FArchive::Preload(UObject *object)
{
  __asm jmp dword ptr [NativeImport_FArchive_Preload]
}

// RavenShield.exe @ 10911bba : FArchive::SerializeInt
// Preserve the DWORD reference and unsigned maximum through imported integer serialization.
__declspec(naked) void FArchive::SerializeInt(uint32_t &value, uint32_t maximum)
{
  __asm jmp dword ptr [NativeImport_FArchive_SerializeInt]
}

// RavenShield.exe @ 10911bc0 : FArchive::SerializeBits
// Preserve the data pointer and signed bit count through imported bit serialization.
__declspec(naked) void FArchive::SerializeBits(void *data, int32_t bitCount)
{
  __asm jmp dword ptr [NativeImport_FArchive_SerializeBits]
}

// RavenShield.exe @ 10911bc6 : FArchive::Precache
// Tail-forward the inherited precache slot without substituting the file-reader refill method.
__declspec(naked) void FArchive::Precache(int32_t hintCount)
{
  __asm jmp dword ptr [NativeImport_FArchive_Precache]
}

// RavenShield.exe @ 10911bcc : FArchive::TotalSize
// Tail-forward the inherited size query without substituting the shared receiver-plus-48 getter.
__declspec(naked) int32_t FArchive::TotalSize()
{
  __asm jmp dword ptr [NativeImport_FArchive_TotalSize]
}
