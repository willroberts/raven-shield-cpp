#include "native_symbols.hpp"
// Windows buffered reader and lifetime methods; explicit offsets retain the native archive layout.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"
#include "allocation_support.hpp"

class FOutputDevice;
using ReaderOutputLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);
class FArchiveFileReader;
using ReaderPrecache = void(__thiscall *)(FArchiveFileReader *, int32_t);
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern const uint16_t *__cdecl appGetSystemErrorMessage(int32_t error);
extern "C" uint32_t __stdcall SetFilePointer(uint32_t handle, int32_t distance, int32_t *highDistance, uint32_t origin);
extern "C" int32_t __stdcall CloseHandle(uint32_t handle);
extern "C" int32_t __stdcall ReadFile(uint32_t handle, void *buffer, uint32_t size, uint32_t *read, void *overlapped);
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 10915b08 : g_archiveReaderVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_archiveReaderVtable[22] = {
    NativeAddress(
        NativeEntry_FArchiveFileReader_ScalarDeletingDestructor), // +000 FArchiveFileReader::ScalarDeletingDestructor
    NativeAddress(NativeEntry_FArchiveFileReader_Serialize),      // +004 FArchiveFileReader::Serialize
    NativeAddress(NativeEntry_FArchive_SerializeBits),            // +008 FArchive::SerializeBits
    NativeAddress(NativeEntry_FArchive_SerializeInt),             // +00c FArchive::SerializeInt
    NativeAddress(NativeEntry_FArchive_Preload),                  // +010 FArchive::Preload
    NativeAddress(NativeEntry_FArchive_CountBytes),               // +014 FArchive::CountBytes
    NativeAddress(NativeEntry_FArchive_Serialize_UObject),        // +018 FArchive::operator<<(UObject*&)
    NativeAddress(NativeEntry_FArchive_Serialize_FName),          // +01c FArchive::operator<<(FName&)
    NativeAddress(NativeEntry_FArchive_MapName),                  // +020 FArchive::MapName
    NativeAddress(NativeEntry_FArchive_MapObject),                // +024 FArchive::MapObject
    NativeAddress(NativeEntry_FArchiveFileReader_Tell),           // +028 FArchiveFileReader::Tell
    NativeAddress(NativeEntry_ReadSharedArchiveOffset48),         // +02c ReadSharedArchiveOffset48
    NativeAddress(NativeEntry_FArchive_AtEnd),                    // +030 FArchive::AtEnd
    NativeAddress(NativeEntry_FArchive_AtStopper),                // +034 FArchive::AtStopper
    NativeAddress(NativeEntry_FArchive_SetStopper),               // +038 FArchive::SetStopper
    NativeAddress(NativeEntry_FArchiveFileReader_Seek),           // +03c FArchiveFileReader::Seek
    NativeAddress(NativeEntry_FArchive_AttachLazyLoader),         // +040 FArchive::AttachLazyLoader
    NativeAddress(NativeEntry_FArchive_DetachLazyLoader),         // +044 FArchive::DetachLazyLoader
    NativeAddress(NativeEntry_FArchiveFileReader_Precache),       // +048 FArchiveFileReader::Precache
    NativeAddress(NativeEntry_FArchive_Flush),                    // +04c FArchive::Flush
    NativeAddress(NativeEntry_FArchiveFileReader_Close),          // +050 FArchiveFileReader::Close
    NativeAddress(NativeEntry_FArchive_GetError),                 // +054 FArchive::GetError
};

// RavenShield.exe data @ 10915ab8 : g_fileReaderConstructorGuardName
const char16_t g_fileReaderConstructorGuardName[] = u"FArchiveFileReader::FArchiveFileReader";
// RavenShield.exe data @ 10915b60 : g_fileReaderSeekGuardName
const char16_t g_fileReaderSeekGuardName[] = u"FArchiveFileReader::Seek";
// RavenShield.exe data @ 10915b98 : g_fileReaderSeekFailureFormat
const char16_t g_fileReaderSeekFailureFormat[] = u"SetFilePointer Failed %i/%i: %i %s";
// RavenShield.exe data @ 10915be0 : g_fileReaderSeekMaximumExpression
const char g_fileReaderSeekMaximumExpression[] = "InPos<=Size";
// RavenShield.exe data @ 10915bec : g_fileReaderSeekMinimumExpression
const char g_fileReaderSeekMinimumExpression[] = "InPos>=0";
// RavenShield.exe data @ 10915bf8 : g_windowsFileManagerSourcePath
const char g_windowsFileManagerSourcePath[] = "..\\..\\Core\\Inc\\FFileManagerWindows.h";

// RavenShield.exe @ 10906050 : FArchiveFileReader::FArchiveFileReader
// Construct the imported base and reader fields, then guard only publication of persistent/loading flags.
FArchiveFileReader::FArchiveFileReader(uint32_t handle, FOutputDevice *error, int32_t size) : FArchive()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_archiveReaderVtable;
  *reinterpret_cast<uint32_t *>(object + 0x40) = handle;
  *reinterpret_cast<FOutputDevice **>(object + 0x44) = error;
  *reinterpret_cast<int32_t *>(object + 0x48) = size;
  *reinterpret_cast<uint32_t *>(object + 0x4c) = 0;
  *reinterpret_cast<uint32_t *>(object + 0x50) = 0;
  *reinterpret_cast<uint32_t *>(object + 0x54) = 0;
  try
  {
    *reinterpret_cast<uint32_t *>(object + 0x20) = 1;
    *reinterpret_cast<uint32_t *>(object + 0x14) = 1;
  }
  // RavenShield.exe @ 109060e1 : RethrowFileReaderConstructorPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109060f5 : UnwindFileReaderConstructorFailure
  // Append the constructor guard and rethrow; automatic base cleanup does not close the stored OS handle.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileReaderConstructorGuardName));
    throw;
  }
}

// RavenShield.exe @ 109123d0 : DestroyFileReaderBaseOnUnwind
// Destroy only the constructed FArchive base, loading the reader pointer saved at parent EBP-1c.
__declspec(naked) void DestroyFileReaderBaseOnUnwind()
{
  __asm {
    mov ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FArchiveDestroy]
  }
}

// RavenShield.exe data @ 109190bc : g_fileReaderConstructorUnwind
const NativeCppUnwindEntry g_fileReaderConstructorUnwind[3] = {
    {-1, NativeAddress(NativeEntry_DestroyFileReaderBaseOnUnwind)}, // DestroyFileReaderBaseOnUnwind
    {0, 0},
    {0, 0},
};

// RavenShield.exe data @ 109190d4 : g_fileReaderConstructorCatches
const NativeCppCatchHandler g_fileReaderConstructorCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x109060e1}, // RethrowFileReaderConstructorPointer
    {0, 0, 0, 0x109060f5},                                               // UnwindFileReaderConstructorFailure
};

// RavenShield.exe data @ 109190f4 : g_fileReaderConstructorTryBlocks
const NativeCppTryBlock g_fileReaderConstructorTryBlocks[1] = {
    {1, 1, 2, 2, NativeAddress(g_fileReaderConstructorCatches)},
};

// RavenShield.exe data @ 10919108 : g_fileReaderConstructorExceptionInfo
const NativeCppFunctionInfo g_fileReaderConstructorExceptionInfo = {
    0x19930520, 3, NativeAddress(g_fileReaderConstructorUnwind), 1, NativeAddress(g_fileReaderConstructorTryBlocks),
    0,          0};

// RavenShield.exe @ 109123d9 : HandleFileReaderConstructorException
// Supply the three-state constructor guard with imported FArchive-base cleanup outside its named catches.
__declspec(naked) void HandleFileReaderConstructorException()
{
  __asm {
    mov eax, offset g_fileReaderConstructorExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10906140 : FArchiveFileReader::Seek
// Assert the signed bounds, attempt the OS seek and update logical/buffer positions even after a logged failure.
void FArchiveFileReader::Seek(int32_t position)
{
  try
  {
    auto *object = reinterpret_cast<uint8_t *>(this);
    if (position < 0) appFailAssert(g_fileReaderSeekMinimumExpression, g_windowsFileManagerSourcePath, 0x3b);
    if (position > *reinterpret_cast<const int32_t *>(object + 0x48))
      appFailAssert(g_fileReaderSeekMaximumExpression, g_windowsFileManagerSourcePath, 0x3c);
    if (SetFilePointer(*reinterpret_cast<const uint32_t *>(object + 0x40), position, nullptr, 0) == 0xffffffff)
    {
      *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
      const uint16_t *systemError = appGetSystemErrorMessage(0);
      const int32_t oldPosition = *reinterpret_cast<const int32_t *>(object + 0x4c);
      const int32_t size = *reinterpret_cast<const int32_t *>(object + 0x48);
      FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
      const auto logf = *reinterpret_cast<const ReaderOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
      logf(error, reinterpret_cast<const uint16_t *>(g_fileReaderSeekFailureFormat), position, size, oldPosition,
           systemError);
    }
    *reinterpret_cast<int32_t *>(object + 0x4c) = position;
    *reinterpret_cast<uint32_t *>(object + 0x50) = *reinterpret_cast<const uint32_t *>(object + 0x4c);
    *reinterpret_cast<uint32_t *>(object + 0x54) = 0;
  }
  // RavenShield.exe @ 10906225 : RethrowFileReaderSeekPointer
  // Copy-throw the caught pointer from parent EBP-14 into a new throw object at EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10906239 : UnwindFileReaderSeekFailure
  // Append the Seek guard and rethrow without resetting the sticky error flag or reversing any completed effects.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileReaderSeekGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919124 : g_fileReaderSeekUnwind
const NativeCppUnwindEntry g_fileReaderSeekUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919134 : g_fileReaderSeekCatches
const NativeCppCatchHandler g_fileReaderSeekCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10906225}, // RethrowFileReaderSeekPointer
    {0, 0, 0, 0x10906239},                                               // UnwindFileReaderSeekFailure
};

// RavenShield.exe data @ 10919154 : g_fileReaderSeekTryBlocks
const NativeCppTryBlock g_fileReaderSeekTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_fileReaderSeekCatches)},
};

// RavenShield.exe data @ 10919168 : g_fileReaderSeekExceptionInfo
const NativeCppFunctionInfo g_fileReaderSeekExceptionInfo = {
    0x19930520, 2, NativeAddress(g_fileReaderSeekUnwind), 1, NativeAddress(g_fileReaderSeekTryBlocks), 0, 0};

// RavenShield.exe @ 109123f0 : HandleFileReaderSeekException
// Supply Seek's two-state pointer/catch-all guard without ownership cleanup actions.
__declspec(naked) void HandleFileReaderSeekException()
{
  __asm {
    mov eax, offset g_fileReaderSeekExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10906270 : FArchiveFileReader::Tell
// Return the full signed logical position at +4c.
int32_t FArchiveFileReader::Tell()
{
  return *reinterpret_cast<const int32_t *>(reinterpret_cast<const uint8_t *>(this) + 0x4c);
}

// RavenShield.exe @ 10906290 : FArchiveFileReader::Close
// Attempt to close any nonzero handle, clear it regardless of OS result and return the inverse existing error flag.
int32_t FArchiveFileReader::Close()
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  if (*reinterpret_cast<const uint32_t *>(object + 0x40) != 0)
    CloseHandle(*reinterpret_cast<const uint32_t *>(object + 0x40));
  *reinterpret_cast<uint32_t *>(object + 0x40) = 0;
  return *reinterpret_cast<const uint32_t *>(object + 0x30) == 0 ? 1 : 0;
}

// RavenShield.exe data @ 10916018 : g_fileReaderDestructorGuardName
const char16_t g_fileReaderDestructorGuardName[] = u"FArchiveFileReader::~FArchiveFileReader";

// RavenShield.exe @ 10907430 : FArchiveFileReader::~FArchiveFileReader
// Guard the inlined close with both native handle tests, then automatically destroy the imported archive base.
FArchiveFileReader::~FArchiveFileReader() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_archiveReaderVtable;
  try
  {
    if (*reinterpret_cast<const uint32_t *>(object + 0x40) != 0)
    {
      if (*reinterpret_cast<const uint32_t *>(object + 0x40) != 0)
        CloseHandle(*reinterpret_cast<const uint32_t *>(object + 0x40));
      *reinterpret_cast<uint32_t *>(object + 0x40) = 0;
    }
  }
  // RavenShield.exe @ 10907494 : RethrowFileReaderDestructorPointer
  // Copy-throw the pointer at parent EBP-14 through EBP-18 before automatic base cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109074a8 : UnwindFileReaderDestructorFailure
  // Append the destructor guard and rethrow; the imported base is destroyed outside these catches.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileReaderDestructorGuardName));
    throw;
  }
}

// RavenShield.exe @ 10907400 : FArchiveFileReader::ScalarDeletingDestructor
// Destroy directly, free only for flags bit zero and return the original address even after freeing it.
void *FArchiveFileReader::ScalarDeletingDestructor(uint32_t flags)
{
  FArchiveFileReader *object = this;
  object->FArchiveFileReader::~FArchiveFileReader();
  if ((flags & 1) != 0) FreeExecutableAllocation(object);
  return object;
}

// RavenShield.exe @ 10912470 : DestroyFileReaderBaseAfterDestructorFailure
// Load saved this from parent EBP-1c and tail-transfer to the imported archive-base destructor.
__declspec(naked) void DestroyFileReaderBaseAfterDestructorFailure()
{
  __asm {
    mov ecx, [ebp-1ch]
    jmp dword ptr [NativeImport_FArchiveDestroy]
  }
}

// RavenShield.exe data @ 10919424 : g_fileReaderDestructorUnwind
const NativeCppUnwindEntry g_fileReaderDestructorUnwind[3] = {
    {-1, NativeAddress(
             NativeEntry_DestroyFileReaderBaseAfterDestructorFailure)}, // DestroyFileReaderBaseAfterDestructorFailure
    {0, 0},
    {0, 0},
};

// RavenShield.exe data @ 1091943c : g_fileReaderDestructorCatches
const NativeCppCatchHandler g_fileReaderDestructorCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10907494}, // RethrowFileReaderDestructorPointer
    {0, 0, 0, 0x109074a8},                                               // UnwindFileReaderDestructorFailure
};

// RavenShield.exe data @ 1091945c : g_fileReaderDestructorTryBlocks
const NativeCppTryBlock g_fileReaderDestructorTryBlocks[1] = {
    {1, 1, 2, 2, NativeAddress(g_fileReaderDestructorCatches)},
};

// RavenShield.exe data @ 10919470 : g_fileReaderDestructorExceptionInfo
const NativeCppFunctionInfo g_fileReaderDestructorExceptionInfo = {
    0x19930520, 3, NativeAddress(g_fileReaderDestructorUnwind), 1, NativeAddress(g_fileReaderDestructorTryBlocks),
    0,          0};

// RavenShield.exe @ 10912479 : HandleFileReaderDestructorException
// Dispatch the three-state destructor guard with base cleanup after the named catches.
__declspec(naked) void HandleFileReaderDestructorException()
{
  __asm {
    mov eax, offset g_fileReaderDestructorExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915f18 : g_fileReaderPrecacheFailureFormat
const char16_t g_fileReaderPrecacheFailureFormat[] = u"ReadFile failed: Count=%i BufferCount=%i Error=%s";
// RavenShield.exe data @ 10915f7c : g_fileReaderBeyondEofFormat
const char16_t g_fileReaderBeyondEofFormat[] = u"ReadFile beyond EOF %i+%i/%i";
// RavenShield.exe data @ 10915fb8 : g_fileReaderDirectReadFailureFormat
const char16_t g_fileReaderDirectReadFailureFormat[] = u"ReadFile failed: Count=%i Length=%i Error=%s";

// RavenShield.exe @ 109071b0 : FArchiveFileReader::Precache
// Read up to the hint, next 1024-byte boundary and remaining size; retain requested count after a short read.
void FArchiveFileReader::Precache(int32_t hintCount)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<uint32_t *>(object + 0x50) = *reinterpret_cast<const uint32_t *>(object + 0x4c);
  const uint32_t remaining =
      *reinterpret_cast<const uint32_t *>(object + 0x48) - *reinterpret_cast<const uint32_t *>(object + 0x4c);
  const int32_t boundary = static_cast<int32_t>(0x400u - (*reinterpret_cast<const uint32_t *>(object + 0x4c) & 0x3ffu));
  const int32_t hinted = MinSigned(hintCount, boundary);
  *reinterpret_cast<int32_t *>(object + 0x54) = MinSigned(hinted, static_cast<int32_t>(remaining));
  uint32_t read = 0;
  ReadFile(*reinterpret_cast<const uint32_t *>(object + 0x40), object + 0x58,
           *reinterpret_cast<const uint32_t *>(object + 0x54), &read, nullptr);
  if (read != *reinterpret_cast<const uint32_t *>(object + 0x54))
  {
    *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
    const uint16_t *systemError = appGetSystemErrorMessage(0);
    const int32_t requested = *reinterpret_cast<const int32_t *>(object + 0x54);
    FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
    const auto logf = *reinterpret_cast<const ReaderOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
    logf(error, reinterpret_cast<const uint16_t *>(g_fileReaderPrecacheFailureFormat), static_cast<int32_t>(read),
         requested, systemError);
  }
}

// RavenShield.exe @ 10907270 : FArchiveFileReader::Serialize
// Consume cached bytes, read large misses directly or refill small misses; preserve native short-read position effects.
void FArchiveFileReader::Serialize(void *data, int32_t length)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  uint32_t remaining = static_cast<uint32_t>(length);
  while (static_cast<int32_t>(remaining) > 0)
  {
    uint32_t available = *reinterpret_cast<const uint32_t *>(object + 0x50) +
                         *reinterpret_cast<const uint32_t *>(object + 0x54) -
                         *reinterpret_cast<const uint32_t *>(object + 0x4c);
    int32_t copy = MinSigned(static_cast<int32_t>(remaining), static_cast<int32_t>(available));
    if (copy == 0)
    {
      if (remaining >= 0x400u)
      {
        uint32_t read = 0;
        ReadFile(*reinterpret_cast<const uint32_t *>(object + 0x40), data, remaining, &read, nullptr);
        if (read != remaining)
        {
          *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
          const uint16_t *systemError = appGetSystemErrorMessage(0);
          FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
          const auto logf = *reinterpret_cast<const ReaderOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
          logf(error, reinterpret_cast<const uint16_t *>(g_fileReaderDirectReadFailureFormat),
               static_cast<int32_t>(read), static_cast<int32_t>(remaining), systemError);
        }
        *reinterpret_cast<uint32_t *>(object + 0x4c) += remaining;
        *reinterpret_cast<uint32_t *>(object + 0x50) += remaining;
        return;
      }
      const uint32_t table = *reinterpret_cast<const uint32_t *>(object);
      const auto precache = *reinterpret_cast<const ReaderPrecache *>(table + 0x48);
      precache(this, 0x7fffffff);
      available = *reinterpret_cast<const uint32_t *>(object + 0x50) +
                  *reinterpret_cast<const uint32_t *>(object + 0x54) -
                  *reinterpret_cast<const uint32_t *>(object + 0x4c);
      copy = MinSigned(static_cast<int32_t>(remaining), static_cast<int32_t>(available));
      if (copy <= 0)
      {
        *reinterpret_cast<uint32_t *>(object + 0x30) = 1;
        const int32_t size = *reinterpret_cast<const int32_t *>(object + 0x48);
        const int32_t position = *reinterpret_cast<const int32_t *>(object + 0x4c);
        FOutputDevice *error = *reinterpret_cast<FOutputDevice **>(object + 0x44);
        const auto logf = *reinterpret_cast<const ReaderOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
        logf(error, reinterpret_cast<const uint16_t *>(g_fileReaderBeyondEofFormat), position,
             static_cast<int32_t>(remaining), size);
      }
      if (*reinterpret_cast<const uint32_t *>(object + 0x30) != 0) return;
    }
    const uint32_t source = reinterpret_cast<uint32_t>(object) + 0x58u +
                            *reinterpret_cast<const uint32_t *>(object + 0x4c) -
                            *reinterpret_cast<const uint32_t *>(object + 0x50);
    CopyExecutableMemory(data, reinterpret_cast<const void *>(source), static_cast<uint32_t>(copy));
    *reinterpret_cast<uint32_t *>(object + 0x4c) += static_cast<uint32_t>(copy);
    remaining -= static_cast<uint32_t>(copy);
    data = reinterpret_cast<void *>(reinterpret_cast<uint32_t>(data) + static_cast<uint32_t>(copy));
  }
}
