#include "native_symbols.hpp"
// Windows buffered writer methods; explicit offsets retain the native archive layout.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"
#include "allocation_support.hpp"

class FOutputDevice;
using WriterOutputLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);
class FArchiveFileWriter;
using WriterFlush = void(__thiscall *)(FArchiveFileWriter *);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();
extern const char16_t g_feedbackLocalizationPackage[];
extern const uint16_t *__cdecl LocalizeError(const char *key, const uint16_t *package, const uint16_t *language);
extern "C" uint32_t __stdcall SetFilePointer(uint32_t handle, int32_t distance, int32_t *highDistance, uint32_t origin);
extern "C" int32_t __stdcall CloseHandle(uint32_t handle);
extern "C" int32_t __stdcall WriteFile(uint32_t handle, const void *buffer, uint32_t size, uint32_t *written,
                                       void *overlapped);

// RavenShield.exe data @ 10915c70 : g_archiveWriterVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
extern const uint32_t g_archiveWriterVtable[22] = {
    NativeAddress(
        NativeEntry_FArchiveFileWriter_ScalarDeletingDestructor), // +000 FArchiveFileWriter::ScalarDeletingDestructor
    NativeAddress(NativeEntry_FArchiveFileWriter_Serialize),      // +004 FArchiveFileWriter::Serialize
    NativeAddress(NativeEntry_FArchive_SerializeBits),            // +008 FArchive::SerializeBits
    NativeAddress(NativeEntry_FArchive_SerializeInt),             // +00c FArchive::SerializeInt
    NativeAddress(NativeEntry_FArchive_Preload),                  // +010 FArchive::Preload
    NativeAddress(NativeEntry_FArchive_CountBytes),               // +014 FArchive::CountBytes
    NativeAddress(NativeEntry_FArchive_Serialize_UObject),        // +018 FArchive::operator<<(UObject*&)
    NativeAddress(NativeEntry_FArchive_Serialize_FName),          // +01c FArchive::operator<<(FName&)
    NativeAddress(NativeEntry_FArchive_MapName),                  // +020 FArchive::MapName
    NativeAddress(NativeEntry_FArchive_MapObject),                // +024 FArchive::MapObject
    NativeAddress(NativeEntry_ReadSharedArchiveOffset48),         // +028 ReadSharedArchiveOffset48
    NativeAddress(NativeEntry_FArchive_TotalSize),                // +02c FArchive::TotalSize
    NativeAddress(NativeEntry_FArchive_AtEnd),                    // +030 FArchive::AtEnd
    NativeAddress(NativeEntry_FArchive_AtStopper),                // +034 FArchive::AtStopper
    NativeAddress(NativeEntry_FArchive_SetStopper),               // +038 FArchive::SetStopper
    NativeAddress(NativeEntry_FArchiveFileWriter_Seek),           // +03c FArchiveFileWriter::Seek
    NativeAddress(NativeEntry_FArchive_AttachLazyLoader),         // +040 FArchive::AttachLazyLoader
    NativeAddress(NativeEntry_FArchive_DetachLazyLoader),         // +044 FArchive::DetachLazyLoader
    NativeAddress(NativeEntry_FArchive_Precache),                 // +048 FArchive::Precache
    NativeAddress(NativeEntry_FArchiveFileWriter_Flush),          // +04c FArchiveFileWriter::Flush
    NativeAddress(NativeEntry_FArchiveFileWriter_Close),          // +050 FArchiveFileWriter::Close
    NativeAddress(NativeEntry_FArchive_GetError),                 // +054 FArchive::GetError
};

// RavenShield.exe data @ 10915d20 : g_fileWriterSeekFailedKey
const char g_fileWriterSeekFailedKey[] = "SeekFailed";
// RavenShield.exe data @ 10915d2c : g_fileWriterWriteFailedKey
const char g_fileWriterWriteFailedKey[] = "WriteFailed";

// RavenShield.exe @ 109065e0 : FArchiveFileWriter::Seek
// Flush through the current virtual slot, seek and publish the requested position even after returning failure logging.
void FArchiveFileWriter::Seek(int32_t position)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t table = *reinterpret_cast<const uint32_t *>(object);
  auto flush = *reinterpret_cast<WriterFlush *>(table + 0x4c);
  flush(this);
  if (SetFilePointer(*reinterpret_cast<const uint32_t *>(object + 0x40), position, nullptr, 0) == 0xffffffff)
  {
    *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
    const uint16_t *message = LocalizeError(g_fileWriterSeekFailedKey,
                                            reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr);
    FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
    const auto logf = *reinterpret_cast<const WriterOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    logf(error, message);
  }
  *reinterpret_cast<int32_t *>(object + 0x48) = position;
}

// RavenShield.exe @ 10906670 : FArchiveFileWriter::Close
// Flush, flag and report a failed nonzero-handle close, then clear the handle and return the inverse sticky error word.
int32_t FArchiveFileWriter::Close()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const uint32_t table = *reinterpret_cast<const uint32_t *>(object);
  auto flush = *reinterpret_cast<WriterFlush *>(table + 0x4c);
  flush(this);
  if (*reinterpret_cast<const uint32_t *>(object + 0x40) != 0 &&
      !CloseHandle(*reinterpret_cast<const uint32_t *>(object + 0x40)))
  {
    *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
    const uint16_t *message = LocalizeError(g_fileWriterWriteFailedKey,
                                            reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr);
    FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
    const auto logf = *reinterpret_cast<const WriterOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    logf(error, message);
  }
  *reinterpret_cast<uint32_t *>(object + 0x40) = 0;
  return *reinterpret_cast<const uint32_t *>(object + 0x30) == 0 ? 1 : 0;
}

// RavenShield.exe @ 109066f0 : FArchiveFileWriter::Serialize
// Advance logical position first, fill and virtually flush overflow chunks, then retain an exactly full final buffer.
void FArchiveFileWriter::Serialize(void *data, int32_t length)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  uint32_t remaining = static_cast<uint32_t>(length);
  *reinterpret_cast<uint32_t *>(object + 0x48) += remaining;
  for (;;)
  {
    const uint32_t copy = 0x1000u - *reinterpret_cast<const uint32_t *>(object + 0x4c);
    if (static_cast<int32_t>(remaining) <= static_cast<int32_t>(copy)) break;
    CopyExecutableMemory(object + 0x50 + *reinterpret_cast<const uint32_t *>(object + 0x4c), data, copy);
    *reinterpret_cast<uint32_t *>(object + 0x4c) += copy;
    remaining -= copy;
    data = reinterpret_cast<void *>(reinterpret_cast<uint32_t>(data) + copy);
    const uint32_t table = *reinterpret_cast<const uint32_t *>(object);
    auto flush = *reinterpret_cast<WriterFlush *>(table + 0x4c);
    flush(this);
  }
  if (remaining != 0)
  {
    CopyExecutableMemory(object + 0x50 + *reinterpret_cast<const uint32_t *>(object + 0x4c), data, remaining);
    *reinterpret_cast<uint32_t *>(object + 0x4c) += remaining;
  }
}

// RavenShield.exe @ 109067b0 : FArchiveFileWriter::Flush
// Write buffered bytes once, ignore successful short writes and discard the buffered count after returning logging.
void FArchiveFileWriter::Flush()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  if (*reinterpret_cast<const uint32_t *>(object + 0x4c) != 0)
  {
    uint32_t written = 0;
    if (!WriteFile(*reinterpret_cast<const uint32_t *>(object + 0x40), object + 0x50,
                   *reinterpret_cast<const uint32_t *>(object + 0x4c), &written, nullptr))
    {
      *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
      const uint16_t *message = LocalizeError(
          g_fileWriterWriteFailedKey, reinterpret_cast<const uint16_t *>(g_feedbackLocalizationPackage), nullptr);
      FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
      const auto logf = *reinterpret_cast<const WriterOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
      logf(error, message);
    }
  }
  *reinterpret_cast<uint32_t *>(object + 0x4c) = 0;
}

// RavenShield.exe data @ 10916068 : g_fileWriterDestructorGuardName
const char16_t g_fileWriterDestructorGuardName[] = u"FArchiveFileWriter::~FArchiveFileWriter";

// RavenShield.exe @ 10907520 : FArchiveFileWriter::~FArchiveFileWriter
// Guard a direct Close for a live handle and its final clear, then automatically destroy the imported archive base.
FArchiveFileWriter::~FArchiveFileWriter() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_archiveWriterVtable;
  try
  {
    if (*reinterpret_cast<const uint32_t *>(object + 0x40) != 0) FArchiveFileWriter::Close();
    *reinterpret_cast<uint32_t *>(object + 0x40) = 0;
  }
  // RavenShield.exe @ 10907576 : RethrowFileWriterDestructorPointer
  // Copy-throw the pointer at parent EBP-14 through EBP-18 before automatic base cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090758a : UnwindFileWriterDestructorFailure
  // Append the destructor guard and rethrow; the imported base is destroyed outside these catches.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileWriterDestructorGuardName));
    throw;
  }
}

// RavenShield.exe @ 109074f0 : FArchiveFileWriter::ScalarDeletingDestructor
// Destroy directly, free only for flags bit zero and return the original address even after freeing it.
void *FArchiveFileWriter::ScalarDeletingDestructor(uint32_t flags)
{
  FArchiveFileWriter *object = this;
  object->FArchiveFileWriter::~FArchiveFileWriter();
  if ((flags & 1) != 0) FreeExecutableAllocation(object);
  return object;
}

// RavenShield.exe @ 10912490 : DestroyFileWriterBaseAfterDestructorFailure
// Load saved this from parent EBP-1c and tail-transfer to the imported archive-base destructor.
__declspec(naked) void DestroyFileWriterBaseAfterDestructorFailure()
{
  __asm {
    mov ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FArchiveDestroy]
  }
}

// RavenShield.exe data @ 1091948c : g_fileWriterDestructorUnwind
const NativeCppUnwindEntry g_fileWriterDestructorUnwind[3] = {
    {-1, NativeAddress(
             NativeEntry_DestroyFileWriterBaseAfterDestructorFailure)}, // DestroyFileWriterBaseAfterDestructorFailure
    {0, 0},
    {0, 0},
};

// RavenShield.exe data @ 109194a4 : g_fileWriterDestructorCatches
const NativeCppCatchHandler g_fileWriterDestructorCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10907576}, // RethrowFileWriterDestructorPointer
    {0, 0, 0, 0x1090758a},                                               // UnwindFileWriterDestructorFailure
};

// RavenShield.exe data @ 109194c4 : g_fileWriterDestructorTryBlocks
const NativeCppTryBlock g_fileWriterDestructorTryBlocks[1] = {
    {1, 1, 2, 2, NativeAddress(g_fileWriterDestructorCatches)},
};

// RavenShield.exe data @ 109194d8 : g_fileWriterDestructorExceptionInfo
const NativeCppFunctionInfo g_fileWriterDestructorExceptionInfo = {
    0x19930520, 3, NativeAddress(g_fileWriterDestructorUnwind), 1, NativeAddress(g_fileWriterDestructorTryBlocks),
    0,          0};

// RavenShield.exe @ 10912499 : HandleFileWriterDestructorException
// Dispatch the three-state destructor guard with base cleanup after the named catches.
__declspec(naked) void HandleFileWriterDestructorException()
{
  __asm {
    mov eax, offset g_fileWriterDestructorExceptionInfo
    jmp DispatchExecutableCppException
  }
}
