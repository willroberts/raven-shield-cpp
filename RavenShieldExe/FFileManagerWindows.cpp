#include "native_symbols.hpp"
// Windows file-manager construction, guarded factories and file/directory operations.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"
#include "allocation_support.hpp"
#include "file_manager_support.hpp"
#include "container_support.hpp"
#include <malloc.h>
#include <new>

// RavenShield.exe data @ 109159dc : g_windowsFileManagerVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_windowsFileManagerVtable[14] = {
    NativeAddress(NativeEntry_FFileManager_Init),                       // +000 FFileManager::Init
    NativeAddress(NativeEntry_FFileManagerWindows_CreateFileReader),    // +004 FFileManagerWindows::CreateFileReader
    NativeAddress(NativeEntry_FFileManagerWindows_CreateFileWriter),    // +008 FFileManagerWindows::CreateFileWriter
    NativeAddress(NativeEntry_FFileManagerWindows_FileSize),            // +00c FFileManagerWindows::FileSize
    NativeAddress(NativeEntry_FFileManagerWindows_Delete),              // +010 FFileManagerWindows::Delete
    NativeAddress(NativeEntry_FFileManagerWindows_Copy),                // +014 FFileManagerWindows::Copy
    NativeAddress(NativeEntry_FFileManagerWindows_Move),                // +018 FFileManagerWindows::Move
    NativeAddress(NativeEntry_FFileManagerWindows_GetGlobalTime),       // +01c FFileManagerWindows::GetGlobalTime
    NativeAddress(NativeEntry_FFileManagerWindows_SetGlobalTime),       // +020 FFileManagerWindows::SetGlobalTime
    NativeAddress(NativeEntry_FFileManagerWindows_MakeDirectory),       // +024 FFileManagerWindows::MakeDirectory
    NativeAddress(NativeEntry_FFileManagerWindows_DeleteDirectory),     // +028 FFileManagerWindows::DeleteDirectory
    NativeAddress(NativeEntry_FFileManagerWindows_FindFiles),           // +02c FFileManagerWindows::FindFiles
    NativeAddress(NativeEntry_FFileManagerWindows_SetDefaultDirectory), // +030 FFileManagerWindows::SetDefaultDirectory
    NativeAddress(NativeEntry_FFileManagerWindows_GetDefaultDirectory), // +034 FFileManagerWindows::GetDefaultDirectory
};

// RavenShield.exe data @ 109405f0 : g_launchFileManagerStorage
alignas(4) uint8_t g_launchFileManagerStorage[4] = {};

// RavenShield.exe @ 10913020 : InitializeLaunchFileManager
// Construct the static file manager and select the Windows implementation table before appInit.
void __cdecl InitializeLaunchFileManager()
{
  const auto constructBase =
      *reinterpret_cast<const ImportedBaseConstructor *>(NativeAddress(NativeImport_FFileManagerConstruct));
  constructBase(g_launchFileManagerStorage); // Core.dll FFileManager::FFileManager.
  *reinterpret_cast<const uint32_t **>(g_launchFileManagerStorage) = g_windowsFileManagerVtable;
}

class FFileManagerGeneric;
class FString;
class FArchive;
class FArchiveFileReader;
extern const uint32_t g_archiveWriterVtable[22];
class FOutputDevice;
class FOutputDeviceError;
extern FOutputDeviceError *GError;
extern FOutputDevice *GLog;
using FileManagerLogf = void(__cdecl *)(FOutputDevice *, const uint16_t *, ...);
using FileManagerEventLogf = void(__cdecl *)(FOutputDevice *, int32_t, const uint16_t *, ...);
extern int32_t GUnicodeOS;
extern int32_t __cdecl winGetSizeANSI(const uint16_t *text);
extern char *__cdecl winToANSI(char *buffer, const uint16_t *text, int32_t count);
extern int32_t __cdecl winGetSizeUNICODE(const char *text);
extern uint16_t *__cdecl winToUNICODE(uint16_t *buffer, const char *text, int32_t count);
extern int32_t __cdecl appStricmp(const uint16_t *left, const uint16_t *right);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern "C" void DispatchExecutableCppException();
extern "C" uint32_t __stdcall CreateFileW(const uint16_t *filename, uint32_t access, uint32_t share, void *security,
                                          uint32_t creation, uint32_t attributes, uint32_t templateHandle);
extern "C" uint32_t __stdcall CreateFileA(const char *filename, uint32_t access, uint32_t share, void *security,
                                          uint32_t creation, uint32_t attributes, uint32_t templateHandle);
extern "C" int32_t __stdcall SetFileAttributesW(const uint16_t *filename, uint32_t attributes);
extern "C" int32_t __stdcall SetFileAttributesA(const char *filename, uint32_t attributes);
extern "C" int32_t __stdcall DeleteFileW(const uint16_t *filename);
extern "C" int32_t __stdcall DeleteFileA(const char *filename);
extern "C" int32_t __stdcall MoveFileW(const uint16_t *source, const uint16_t *destination);
extern "C" int32_t __stdcall MoveFileA(const char *source, const char *destination);
extern "C" int32_t __stdcall CreateDirectoryW(const uint16_t *path, void *security);
extern "C" int32_t __stdcall CreateDirectoryA(const char *path, void *security);
extern "C" int32_t __stdcall RemoveDirectoryW(const uint16_t *path);
extern "C" int32_t __stdcall RemoveDirectoryA(const char *path);
extern "C" int32_t __stdcall CopyFileW(const uint16_t *source, const uint16_t *destination, int32_t failIfExists);
extern "C" int32_t __stdcall CopyFileA(const char *source, const char *destination, int32_t failIfExists);
extern "C" uint32_t __stdcall GetLastError();
// Native FILETIME output consists of low/high DWORDs at offsets zero/four.
struct FileManagerFileTimeX86
{
  uint32_t low;
  uint32_t high;
};
extern "C" int32_t __stdcall GetFileTime(uint32_t handle, FileManagerFileTimeX86 *creation,
                                         FileManagerFileTimeX86 *access, FileManagerFileTimeX86 *write);
extern "C" uint32_t __stdcall GetFileSize(uint32_t handle, uint32_t *highSize);
extern "C" int32_t __stdcall CloseHandle(uint32_t handle);
extern "C" int32_t __stdcall SetCurrentDirectoryW(const uint16_t *directory);
extern "C" int32_t __stdcall SetCurrentDirectoryA(const char *directory);
extern "C" uint32_t __stdcall GetCurrentDirectoryW(uint32_t capacity, uint16_t *directory);
extern "C" uint32_t __stdcall GetCurrentDirectoryA(uint32_t capacity, char *directory);
extern const uint16_t *__cdecl appFromAnsi(const char *text);
extern const char16_t g_configEmptyString[];
extern "C" uint32_t __stdcall SetFilePointer(uint32_t handle, int32_t distance, int32_t *highDistance, uint32_t origin);

// RavenShield.exe data @ 10915a18 : g_createFileReaderGuardName
const char16_t g_createFileReaderGuardName[] = u"FFileManagerWindows::CreateFileReader";
// RavenShield.exe data @ 10915a64 : g_windowsFileReaderAllocationTag
const char16_t g_windowsFileReaderAllocationTag[] = u"WindowsFileReader";
// RavenShield.exe data @ 10915a88 : g_createFileReaderFailureFormat
const char16_t g_createFileReaderFailureFormat[] = u"Failed to read file: %s";
// RavenShield.exe data @ 10915c20 : g_createFileWriterGuardName
const char16_t g_createFileWriterGuardName[] = u"FFileManagerWindows::CreateFileWriter";
// RavenShield.exe data @ 10915cc8 : g_windowsFileWriterAllocationTag
const char16_t g_windowsFileWriterAllocationTag[] = u"WindowsFileWriter";
// RavenShield.exe data @ 10915cec : g_createFileWriterFailureFormat
const char16_t g_createFileWriterFailureFormat[] = u"Failed to create file: %s";

// RavenShield.exe @ 10905e40 : FFileManagerWindows::CreateFileReader
// Open an existing shared-read file, optionally report failure globally, then allocate and construct its reader.
FArchive *FFileManagerWindows::CreateFileReader(const uint16_t *filename, uint32_t flags, FOutputDevice *error)
{
  try
  {
    uint32_t handle;
    if (GUnicodeOS != 0)
    {
      handle = CreateFileW(filename, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(filename) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(filename);
      char *converted = winToANSI(buffer, filename, count);
      handle = CreateFileA(converted, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    if (handle == 0xffffffff)
    {
      if ((flags & 1) != 0)
      {
        FOutputDevice *output = reinterpret_cast<FOutputDevice *>(GError);
        const auto logf = *reinterpret_cast<const FileManagerLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
        logf(output, reinterpret_cast<const uint16_t *>(g_createFileReaderFailureFormat), filename);
      }
      return nullptr;
    }
    void *storage =
        AllocateTaggedExecutableBytes(0x458, reinterpret_cast<const uint16_t *>(g_windowsFileReaderAllocationTag));
    if (storage == nullptr) return nullptr; // The opened handle is not closed on allocation failure.
    const int32_t size = static_cast<int32_t>(GetFileSize(handle, nullptr)); // No high word or failure check.
    return new (storage) FArchiveFileReader(handle, error, size); // No heap/handle rollback if construction throws.
  }
  // RavenShield.exe @ 10905fd6 : RethrowCreateFileReaderPointer
  // Copy-throw the caught pointer from parent EBP-24 into a new throw object at EBP-2c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10905fea : UnwindCreateFileReaderFailure
  // Append the factory guard and rethrow without closing handles or freeing allocated reader storage.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_createFileReaderGuardName));
    throw;
  }
}

// RavenShield.exe data @ 1091905c : g_createFileReaderUnwind
const NativeCppUnwindEntry g_createFileReaderUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091906c : g_createFileReaderCatches
const NativeCppCatchHandler g_createFileReaderCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x24, 0x10905fd6}, // RethrowCreateFileReaderPointer
    {0, 0, 0, 0x10905fea},                                               // UnwindCreateFileReaderFailure
};

// RavenShield.exe data @ 1091908c : g_createFileReaderTryBlocks
const NativeCppTryBlock g_createFileReaderTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_createFileReaderCatches)},
};

// RavenShield.exe data @ 109190a0 : g_createFileReaderExceptionInfo
const NativeCppFunctionInfo g_createFileReaderExceptionInfo = {
    0x19930520, 2, NativeAddress(g_createFileReaderUnwind), 1, NativeAddress(g_createFileReaderTryBlocks), 0, 0};

// RavenShield.exe @ 109123c0 : HandleCreateFileReaderException
// Supply CreateFileReader's two-state pointer/catch-all guard without ownership cleanup actions.
__declspec(naked) void HandleCreateFileReaderException()
{
  __asm {
    mov eax, offset g_createFileReaderExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 109062d0 : FFileManagerWindows::CreateFileWriter
// Apply native file flags, open or append, then perform the selected build's inlined writer construction.
FArchive *FFileManagerWindows::CreateFileWriter(const uint16_t *filename, uint32_t flags, FOutputDevice *error)
{
  try
  {
    if ((flags & 4) != 0)
    {
      if (GUnicodeOS != 0)
      {
        SetFileAttributesW(filename, 0); // Native does not query existence or inspect the result.
      }
      else
      {
        char *buffer = nullptr;
        if (winGetSizeANSI(filename) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
          bytes = (bytes + 3) & 0xfffffffc;
          buffer = reinterpret_cast<char *>(_alloca(bytes));
        }
        const int32_t count = winGetSizeANSI(filename);
        char *converted = winToANSI(buffer, filename, count);
        SetFileAttributesA(converted, 0);
      }
    }
    const uint32_t share = (flags & 0x20) != 0 ? 1 : 0;
    const uint32_t creation = (flags & 0x10) != 0 ? 4 : 2u - ((flags & 2) != 0 ? 1u : 0u);
    uint32_t handle;
    if (GUnicodeOS != 0)
    {
      handle = CreateFileW(filename, 0x40000000, share, nullptr, creation, 0x80, 0);
    }
    else
    {
      char *buffer = nullptr; // Separate native conversion/allocation from the optional attribute call above.
      if (winGetSizeANSI(filename) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(filename);
      char *converted = winToANSI(buffer, filename, count);
      handle = CreateFileA(converted, 0x40000000, share, nullptr, creation, 0x80, 0);
    }
    int32_t position = 0;
    if (handle == 0xffffffff)
    {
      if ((flags & 1) != 0)
      {
        FOutputDevice *output = reinterpret_cast<FOutputDevice *>(GError);
        const auto logf = *reinterpret_cast<const FileManagerLogf *>(NativeAddress(NativeImport_FOutputDeviceLogf));
        logf(output, reinterpret_cast<const uint16_t *>(g_createFileWriterFailureFormat), filename);
      }
      return nullptr;
    }
    if ((flags & 0x10) != 0) position = static_cast<int32_t>(SetFilePointer(handle, 0, nullptr, 2));
    auto *writer = reinterpret_cast<uint8_t *>(
        AllocateTaggedExecutableBytes(0x1050, reinterpret_cast<const uint16_t *>(g_windowsFileWriterAllocationTag)));
    if (writer == nullptr) return nullptr; // Native leaves the handle open and any append seek unchecked.
    const auto constructBase =
        *reinterpret_cast<const ImportedBaseConstructor *>(NativeAddress(NativeImport_FArchiveConstruct));
    constructBase(writer); // Inlined FArchiveFileWriter construction; no independent constructor body established.
    *reinterpret_cast<const uint32_t **>(writer) = g_archiveWriterVtable;
    *reinterpret_cast<uint32_t *>(writer + 0x40) = handle;
    *reinterpret_cast<FOutputDevice **>(writer + 0x44) = error;
    *reinterpret_cast<int32_t *>(writer + 0x48) = position;
    *reinterpret_cast<uint32_t *>(writer + 0x4c) = 0;
    *reinterpret_cast<uint32_t *>(writer + 0x20) = 1; // ArIsPersistent, before ArIsSaving at +18.
    *reinterpret_cast<uint32_t *>(writer + 0x18) = 1;
    return reinterpret_cast<FArchive *>(writer);
  }
  // RavenShield.exe @ 1090658c : RethrowCreateFileWriterPointer
  // Copy-throw the caught pointer from parent EBP-28 into a new throw object at EBP-30.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 109065a0 : UnwindCreateFileWriterFailure
  // Append the factory guard and rethrow without handle, allocation or partial-base cleanup.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_createFileWriterGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919184 : g_createFileWriterUnwind
const NativeCppUnwindEntry g_createFileWriterUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919194 : g_createFileWriterCatches
const NativeCppCatchHandler g_createFileWriterCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x28, 0x1090658c}, // RethrowCreateFileWriterPointer
    {0, 0, 0, 0x109065a0},                                               // UnwindCreateFileWriterFailure
};

// RavenShield.exe data @ 109191b4 : g_createFileWriterTryBlocks
const NativeCppTryBlock g_createFileWriterTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_createFileWriterCatches)},
};

// RavenShield.exe data @ 109191c8 : g_createFileWriterExceptionInfo
const NativeCppFunctionInfo g_createFileWriterExceptionInfo = {
    0x19930520, 2, NativeAddress(g_createFileWriterUnwind), 1, NativeAddress(g_createFileWriterTryBlocks), 0, 0};

// RavenShield.exe @ 10912400 : HandleCreateFileWriterException
// Supply CreateFileWriter's two-state pointer/catch-all guard with no construction cleanup callbacks.
__declspec(naked) void HandleCreateFileWriterException()
{
  __asm {
    mov eax, offset g_createFileWriterExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10906f10 : FFileManagerWindows::SetGlobalTime
// Return full 32-bit failure without reading the filename or changing any state; native slot +20 is a genuine stub.
int32_t FFileManagerWindows::SetGlobalTime(const uint16_t *filename)
{
  return 0;
}

// RavenShield.exe data @ 10915d38 : g_fileManagerFileSizeGuardName
const char16_t g_fileManagerFileSizeGuardName[] = u"FFileManagerWindows::FileSize";
// RavenShield.exe data @ 10915e68 : g_fileManagerSetDirectoryGuardName
const char16_t g_fileManagerSetDirectoryGuardName[] = u"FFileManagerWindows::SetDefaultDirectory";

// RavenShield.exe @ 10906830 : FFileManagerWindows::FileSize
// Open a shared-read file, return its raw low size word and ignore close failure; only invalid open returns -1 early.
int32_t FFileManagerWindows::FileSize(const uint16_t *filename)
{
  try
  {
    uint32_t handle;
    if (GUnicodeOS != 0)
    {
      handle = CreateFileW(filename, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(filename) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(filename);
      char *converted = winToANSI(buffer, filename, count);
      handle = CreateFileA(converted, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    if (handle == 0xffffffff) return -1;
    const uint32_t size = GetFileSize(handle, nullptr);
    CloseHandle(handle);
    return static_cast<int32_t>(size);
  }
  // RavenShield.exe @ 1090694f : RethrowFileSizePointer
  // Copy-throw the caught pointer from parent EBP-1c through EBP-20 without adding handle cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10906963 : UnwindFileSizeFailure
  // Append the FileSize guard and rethrow without changing the native open/size/close effects.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerFileSizeGuardName));
    throw;
  }
}

// RavenShield.exe data @ 109191e4 : g_fileSizeUnwind
const NativeCppUnwindEntry g_fileSizeUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109191f4 : g_fileSizeCatches
const NativeCppCatchHandler g_fileSizeCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x1c, 0x1090694f}, // RethrowFileSizePointer
    {0, 0, 0, 0x10906963},                                               // UnwindFileSizeFailure
};

// RavenShield.exe data @ 10919214 : g_fileSizeTryBlocks
const NativeCppTryBlock g_fileSizeTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_fileSizeCatches)},
};

// RavenShield.exe data @ 10919228 : g_fileSizeExceptionInfo
const NativeCppFunctionInfo g_fileSizeExceptionInfo = {
    0x19930520, 2, NativeAddress(g_fileSizeUnwind), 1, NativeAddress(g_fileSizeTryBlocks), 0, 0};

// RavenShield.exe @ 10912410 : HandleFileSizeException
// Dispatch the FileSize pointer/catch-all guard with no ownership cleanup action.
__declspec(naked) void HandleFileSizeException()
{
  __asm {
    mov eax, offset g_fileSizeExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10906f20 : FFileManagerWindows::SetDefaultDirectory
// Select the wide or parent-frame ANSI API and return full normalized success from its raw BOOL.
int32_t FFileManagerWindows::SetDefaultDirectory(const uint16_t *directory)
{
  try
  {
    int32_t result;
    if (GUnicodeOS != 0)
    {
      result = SetCurrentDirectoryW(directory);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(directory) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(directory)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(directory);
      char *converted = winToANSI(buffer, directory, count);
      result = SetCurrentDirectoryA(converted);
    }
    return result != 0 ? 1 : 0;
  }
  // RavenShield.exe @ 10906ff7 : RethrowSetDefaultDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090700b : UnwindSetDefaultDirectoryFailure
  // Append the directory-setting guard and rethrow without restoring an earlier process directory.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerSetDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919364 : g_setDefaultDirectoryUnwind
const NativeCppUnwindEntry g_setDefaultDirectoryUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919374 : g_setDefaultDirectoryCatches
const NativeCppCatchHandler g_setDefaultDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10906ff7}, // RethrowSetDefaultDirectoryPointer
    {0, 0, 0, 0x1090700b},                                               // UnwindSetDefaultDirectoryFailure
};

// RavenShield.exe data @ 10919394 : g_setDefaultDirectoryTryBlocks
const NativeCppTryBlock g_setDefaultDirectoryTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_setDefaultDirectoryCatches)},
};

// RavenShield.exe data @ 109193a8 : g_setDefaultDirectoryExceptionInfo
const NativeCppFunctionInfo g_setDefaultDirectoryExceptionInfo = {
    0x19930520, 2, NativeAddress(g_setDefaultDirectoryUnwind), 1, NativeAddress(g_setDefaultDirectoryTryBlocks), 0, 0};

// RavenShield.exe @ 10912450 : HandleSetDefaultDirectoryException
// Dispatch the directory setter's pointer/catch-all guard with no cleanup action.
__declspec(naked) void HandleSetDefaultDirectoryException()
{
  __asm {
    mov eax, offset g_setDefaultDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915d74 : g_fileManagerDeleteGuardName
const char16_t g_fileManagerDeleteGuardName[] = u"FFileManagerWindows::Delete";

// RavenShield.exe @ 109069a0 : FFileManagerWindows::Delete
// Optionally normalize attributes, attempt deletion and accept a missing file only when existence is not required.
int32_t FFileManagerWindows::Delete(const uint16_t *filename, int32_t requireExists, int32_t evenReadOnly)
{
  try
  {
    if (evenReadOnly != 0)
    {
      if (GUnicodeOS != 0)
      {
        SetFileAttributesW(filename, 0x80);
      }
      else
      {
        char *attributeBuffer = nullptr;
        if (winGetSizeANSI(filename) != 0)
        {
          uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
          bytes = (bytes + 3) & 0xfffffffc;
          attributeBuffer = reinterpret_cast<char *>(_alloca(bytes));
        }
        const int32_t count = winGetSizeANSI(filename);
        char *converted = winToANSI(attributeBuffer, filename, count);
        SetFileAttributesA(converted, 0x80);
      }
    }
    int32_t deleted;
    if (GUnicodeOS != 0)
    {
      deleted = DeleteFileW(filename);
    }
    else
    {
      char *deleteBuffer = nullptr;
      if (winGetSizeANSI(filename) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        deleteBuffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(filename);
      char *converted = winToANSI(deleteBuffer, filename, count);
      deleted = DeleteFileA(converted);
    }
    if (deleted != 0) return 1;
    if (requireExists != 0) return 0;
    return GetLastError() == 2 ? 1 : 0;
  }
  // RavenShield.exe @ 10906b4d : RethrowDeleteFilePointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10906b61 : UnwindDeleteFileFailure
  // Append the deletion guard and rethrow without restoring any attributes already changed.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerDeleteGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919244 : g_deleteFileUnwind
const NativeCppUnwindEntry g_deleteFileUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919254 : g_deleteFileCatches
const NativeCppCatchHandler g_deleteFileCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10906b4d}, // RethrowDeleteFilePointer
    {0, 0, 0, 0x10906b61},                                               // UnwindDeleteFileFailure
};

// RavenShield.exe data @ 10919274 : g_deleteFileTryBlocks
const NativeCppTryBlock g_deleteFileTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_deleteFileCatches)},
};

// RavenShield.exe data @ 10919288 : g_deleteFileExceptionInfo
const NativeCppFunctionInfo g_deleteFileExceptionInfo = {
    0x19930520, 2, NativeAddress(g_deleteFileUnwind), 1, NativeAddress(g_deleteFileTryBlocks), 0, 0};

// RavenShield.exe @ 10912420 : HandleDeleteFileException
// Dispatch deletion's pointer/catch-all guard without an ownership or attribute rollback cleanup.
__declspec(naked) void HandleDeleteFileException()
{
  __asm {
    mov eax, offset g_deleteFileExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915dac : g_fileManagerMoveGuardName
const char16_t g_fileManagerMoveGuardName[] = u"FFileManagerWindows::Move";
// RavenShield.exe data @ 10915de0 : g_fileManagerMoveFailureFormat
const char16_t g_fileManagerMoveFailureFormat[] = u"Error moving file '%s' to '%s'";

// RavenShield.exe @ 10906ba0 : FFileManagerWindows::Move
// Attempt virtual destination deletion before moving, ignore replace/attribute flags and warn on a failed move.
int32_t FFileManagerWindows::Move(const uint16_t *destination, const uint16_t *source, int32_t replace,
                                  int32_t evenReadOnly, int32_t attributes)
{
  try
  {
    const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
    using DeleteFile = int32_t(__thiscall *)(FFileManagerWindows *, const uint16_t *, int32_t, int32_t);
    const auto remove = *reinterpret_cast<const DeleteFile *>(table + 0x10);
    remove(this, destination, 0, evenReadOnly);
    int32_t result;
    if (GUnicodeOS != 0)
    {
      result = MoveFileW(source, destination);
    }
    else
    {
      char *destinationBuffer = nullptr;
      if (winGetSizeANSI(destination) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(destination)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        destinationBuffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      char *sourceBuffer = nullptr;
      if (winGetSizeANSI(source) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(source)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        sourceBuffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t destinationCount = winGetSizeANSI(destination);
      char *convertedDestination = winToANSI(destinationBuffer, destination, destinationCount);
      const int32_t sourceCount = winGetSizeANSI(source);
      char *convertedSource = winToANSI(sourceBuffer, source, sourceCount);
      result = MoveFileA(convertedSource, convertedDestination);
    }
    if (result == 0)
    {
      FOutputDevice *log = GLog;
      const auto logf =
          *reinterpret_cast<const FileManagerEventLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
      logf(log, 0x2ff, reinterpret_cast<const uint16_t *>(g_fileManagerMoveFailureFormat), source, destination);
    }
    return result != 0 ? 1 : 0;
  }
  // RavenShield.exe @ 10906d3c : RethrowMoveFilePointer
  // Copy-throw the caught pointer from parent EBP-18 through EBP-1c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10906d50 : UnwindMoveFileFailure
  // Append the move guard and rethrow without restoring a deleted destination or completed move.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerMoveGuardName));
    throw;
  }
}

// RavenShield.exe data @ 109192a4 : g_moveFileUnwind
const NativeCppUnwindEntry g_moveFileUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109192b4 : g_moveFileCatches
const NativeCppCatchHandler g_moveFileCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x10906d3c}, // RethrowMoveFilePointer
    {0, 0, 0, 0x10906d50},                                               // UnwindMoveFileFailure
};

// RavenShield.exe data @ 109192d4 : g_moveFileTryBlocks
const NativeCppTryBlock g_moveFileTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_moveFileCatches)},
};

// RavenShield.exe data @ 109192e8 : g_moveFileExceptionInfo
const NativeCppFunctionInfo g_moveFileExceptionInfo = {
    0x19930520, 2, NativeAddress(g_moveFileUnwind), 1, NativeAddress(g_moveFileTryBlocks), 0, 0};

// RavenShield.exe @ 10912430 : HandleMoveFileException
// Dispatch Move's pointer/catch-all guard without file-operation rollback cleanup.
__declspec(naked) void HandleMoveFileException()
{
  __asm {
    mov eax, offset g_moveFileExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915e20 : g_fileManagerGetTimeGuardName
const char16_t g_fileManagerGetTimeGuardName[] = u"FFileManagerWindows::GetGlobalTime";

// RavenShield.exe @ 10906d90 : FFileManagerWindows::GetGlobalTime
// Return raw last-write bits after querying and closing; a failed time query leaves its opened handle unclosed.
int64_t FFileManagerWindows::GetGlobalTime(const uint16_t *filename)
{
  try
  {
    uint32_t handle;
    if (GUnicodeOS != 0)
    {
      handle = CreateFileW(filename, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(filename) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(filename)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(filename);
      char *converted = winToANSI(buffer, filename, count);
      handle = CreateFileA(converted, 0x80000000, 1, nullptr, 3, 0x80, 0);
    }
    FileManagerFileTimeX86 creation, access, write;
    if (handle == 0xffffffff || !GetFileTime(handle, &creation, &access, &write)) return 0;
    CloseHandle(handle);
    const uint32_t low = write.low;
    const uint32_t high = write.high;
    return static_cast<int64_t>((static_cast<uint64_t>(high) << 32) | low);
  }
  // RavenShield.exe @ 10906ebe : RethrowGetGlobalTimePointer
  // Copy-throw the caught pointer from parent EBP-30 through EBP-34.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10906ed2 : UnwindGetGlobalTimeFailure
  // Append the timestamp-query guard and rethrow without closing a handle opened before failure.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerGetTimeGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919304 : g_getGlobalTimeUnwind
const NativeCppUnwindEntry g_getGlobalTimeUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919314 : g_getGlobalTimeCatches
const NativeCppCatchHandler g_getGlobalTimeCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x30, 0x10906ebe}, // RethrowGetGlobalTimePointer
    {0, 0, 0, 0x10906ed2},                                               // UnwindGetGlobalTimeFailure
};

// RavenShield.exe data @ 10919334 : g_getGlobalTimeTryBlocks
const NativeCppTryBlock g_getGlobalTimeTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_getGlobalTimeCatches)},
};

// RavenShield.exe data @ 10919348 : g_getGlobalTimeExceptionInfo
const NativeCppFunctionInfo g_getGlobalTimeExceptionInfo = {
    0x19930520, 2, NativeAddress(g_getGlobalTimeUnwind), 1, NativeAddress(g_getGlobalTimeTryBlocks), 0, 0};

// RavenShield.exe @ 10912440 : HandleGetGlobalTimeException
// Dispatch the time query's pointer/catch-all guard without handle cleanup.
__declspec(naked) void HandleGetGlobalTimeException()
{
  __asm {
    mov eax, offset g_getGlobalTimeExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// Native adjacent buffers at parent EBP-c10 and EBP-810; only the selected array is initialized.
struct FileManagerDirectoryScratchX86
{
  char ansi[0x400];
  uint16_t wide[0x400];
};

// RavenShield.exe data @ 10914802 : g_fileManagerEmptyAnsiUnit
extern const char g_fileManagerEmptyAnsiUnit = '\0';
// RavenShield.exe data @ 10915ec0 : g_fileManagerGetDirectoryGuardName
const char16_t g_fileManagerGetDirectoryGuardName[] = u"FFileManagerWindows::GetDefaultDirectory";

// RavenShield.exe @ 10907050 : FFileManagerWindows::GetDefaultDirectory
// Query into the selected zero-filled buffer, ignore required length and construct the caller-owned result directly.
FString FFileManagerWindows::GetDefaultDirectory()
{
  FileManagerDirectoryScratchX86 buffers;
  try
  {
    if (GUnicodeOS != 0)
    {
      buffers.wide[0] = static_cast<uint16_t>(g_configEmptyString[0]);
      for (uint32_t i = 1; i < 0x400; ++i) buffers.wide[i] = 0;
      GetCurrentDirectoryW(0x400, buffers.wide);
      return FString(buffers.wide);
    }
    buffers.ansi[0] = g_fileManagerEmptyAnsiUnit;
    for (uint32_t i = 1; i < 0x400; ++i) buffers.ansi[i] = 0;
    GetCurrentDirectoryA(0x400, buffers.ansi);
    const uint16_t *converted = appFromAnsi(buffers.ansi);
    return FString(converted);
  }
  // RavenShield.exe @ 10907158 : RethrowGetDefaultDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-c14 through EBP-c18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10907175 : UnwindGetDefaultDirectoryFailure
  // Append the directory-query guard and rethrow without destroying an unconstructed caller result.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerGetDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe data @ 109193c4 : g_getDefaultDirectoryUnwind
const NativeCppUnwindEntry g_getDefaultDirectoryUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 109193d4 : g_getDefaultDirectoryCatches
const NativeCppCatchHandler g_getDefaultDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0xc14, 0x10907158}, // RethrowGetDefaultDirectoryPointer
    {0, 0, 0, 0x10907175},                                                // UnwindGetDefaultDirectoryFailure
};

// RavenShield.exe data @ 109193f4 : g_getDefaultDirectoryTryBlocks
const NativeCppTryBlock g_getDefaultDirectoryTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_getDefaultDirectoryCatches)},
};

// RavenShield.exe data @ 10919408 : g_getDefaultDirectoryExceptionInfo
const NativeCppFunctionInfo g_getDefaultDirectoryExceptionInfo = {
    0x19930520, 2, NativeAddress(g_getDefaultDirectoryUnwind), 1, NativeAddress(g_getDefaultDirectoryTryBlocks), 0, 0};

// RavenShield.exe @ 10912460 : HandleGetDefaultDirectoryException
// Dispatch the directory query's pointer/catch-all guard without local string cleanup.
__declspec(naked) void HandleGetDefaultDirectoryException()
{
  __asm {
    mov eax, offset g_getDefaultDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 109160b8 : g_fileManagerMakeDirectoryGuardName
const char16_t g_fileManagerMakeDirectoryGuardName[] = u"FFileManagerWindows::MakeDirectory";

// RavenShield.exe @ 10907860 : FFileManagerWindows::MakeDirectory
// Delegate tree creation; otherwise create one directory and accept the existing-object error without a type check.
int32_t FFileManagerWindows::MakeDirectory(const uint16_t *path, int32_t tree)
{
  try
  {
    if (tree != 0) return FFileManagerGeneric::MakeDirectory(path, tree);
    int32_t result;
    if (GUnicodeOS != 0)
    {
      result = CreateDirectoryW(path, nullptr);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(path) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(path)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(path);
      char *converted = winToANSI(buffer, path, count);
      result = CreateDirectoryA(converted, nullptr);
    }
    if (result != 0) return 1;
    return GetLastError() == 0xb7 ? 1 : 0;
  }
  // RavenShield.exe @ 1090797a : RethrowMakeDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090798e : UnwindMakeDirectoryFailure
  // Append the Windows directory-creation guard and rethrow without removing completed directories.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerMakeDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe data @ 109194f4 : g_makeDirectoryUnwind
const NativeCppUnwindEntry g_makeDirectoryUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919504 : g_makeDirectoryCatches
const NativeCppCatchHandler g_makeDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x1090797a}, // RethrowMakeDirectoryPointer
    {0, 0, 0, 0x1090798e},                                               // UnwindMakeDirectoryFailure
};

// RavenShield.exe data @ 10919524 : g_makeDirectoryTryBlocks
const NativeCppTryBlock g_makeDirectoryTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_makeDirectoryCatches)},
};

// RavenShield.exe data @ 10919538 : g_makeDirectoryExceptionInfo
const NativeCppFunctionInfo g_makeDirectoryExceptionInfo = {
    0x19930520, 2, NativeAddress(g_makeDirectoryUnwind), 1, NativeAddress(g_makeDirectoryTryBlocks), 0, 0};

// RavenShield.exe @ 109124b0 : HandleMakeDirectoryException
// Dispatch the Windows directory creator's pointer/catch-all guard without rollback cleanup.
__declspec(naked) void HandleMakeDirectoryException()
{
  __asm {
    mov eax, offset g_makeDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 109075d0 : FFileManagerWindows::Copy
// Clear attributes, delegate progress copies or call CopyFile, then conditionally clear destination attributes.
uint32_t FFileManagerWindows::Copy(const uint16_t *destination, const uint16_t *source, int32_t replace,
                                   int32_t evenReadOnly, int32_t attributes, FileCopyProgress progress)
{
  if (evenReadOnly != 0)
  {
    if (GUnicodeOS != 0)
    {
      SetFileAttributesW(destination, 0);
    }
    else
    {
      char *attributeBuffer = nullptr;
      if (winGetSizeANSI(destination) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(destination)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        attributeBuffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(destination);
      char *converted = winToANSI(attributeBuffer, destination, count);
      SetFileAttributesA(converted, 0);
    }
  }
  uint32_t result;
  if (progress != nullptr)
  {
    result = FFileManagerGeneric::Copy(destination, source, replace, evenReadOnly, attributes, progress);
  }
  else if (GUnicodeOS != 0)
  {
    result = CopyFileW(source, destination, replace == 0 ? 1 : 0) != 0 ? 1 : 0;
  }
  else
  {
    char *destinationBuffer = nullptr;
    if (winGetSizeANSI(destination) != 0)
    {
      uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(destination)) + 7) & 0xfffffff8;
      bytes = (bytes + 3) & 0xfffffffc;
      destinationBuffer = reinterpret_cast<char *>(_alloca(bytes));
    }
    char *sourceBuffer = nullptr;
    if (winGetSizeANSI(source) != 0)
    {
      uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(source)) + 7) & 0xfffffff8;
      bytes = (bytes + 3) & 0xfffffffc;
      sourceBuffer = reinterpret_cast<char *>(_alloca(bytes));
    }
    const int32_t failIfExists = replace == 0 ? 1 : 0;
    const int32_t destinationCount = winGetSizeANSI(destination);
    char *convertedDestination = winToANSI(destinationBuffer, destination, destinationCount);
    const int32_t sourceCount = winGetSizeANSI(source);
    char *convertedSource = winToANSI(sourceBuffer, source, sourceCount);
    result = CopyFileA(convertedSource, convertedDestination, failIfExists) != 0 ? 1 : 0;
  }
  if (result != 0 && attributes == 0)
  {
    if (GUnicodeOS != 0)
    {
      SetFileAttributesW(destination, 0);
    }
    else
    {
      char *finalAttributeBuffer = nullptr;
      if (winGetSizeANSI(destination) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(destination)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        finalAttributeBuffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(destination);
      char *converted = winToANSI(finalAttributeBuffer, destination, count);
      SetFileAttributesA(converted, 0);
    }
  }
  return result;
}

// RavenShield.exe data @ 10916880 : g_fileManagerDeleteDirectoryGuardName
const char16_t g_fileManagerDeleteDirectoryGuardName[] = u"FFileManagerWindows::DeleteDirectory";

// RavenShield.exe @ 1090a6a0 : FFileManagerWindows::DeleteDirectory
// Delegate recursive deletion; shallow removal accepts error 2 only when existence is not required.
int32_t FFileManagerWindows::DeleteDirectory(const uint16_t *path, int32_t requireExists, int32_t tree)
{
  try
  {
    if (tree != 0) return FFileManagerGeneric::DeleteDirectory(path, requireExists, tree);
    int32_t result;
    if (GUnicodeOS != 0)
    {
      result = RemoveDirectoryW(path);
    }
    else
    {
      char *buffer = nullptr;
      if (winGetSizeANSI(path) != 0)
      {
        uint32_t bytes = (static_cast<uint32_t>(winGetSizeANSI(path)) + 7) & 0xfffffff8;
        bytes = (bytes + 3) & 0xfffffffc;
        buffer = reinterpret_cast<char *>(_alloca(bytes));
      }
      const int32_t count = winGetSizeANSI(path);
      char *converted = winToANSI(buffer, path, count);
      result = RemoveDirectoryA(converted);
    }
    if (result != 0) return 1;
    if (requireExists != 0) return 0;
    return GetLastError() == 2 ? 1 : 0;
  }
  // RavenShield.exe @ 1090a7bd : RethrowDeleteDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090a7d1 : UnwindDeleteDirectoryFailure
  // Append the Windows directory-removal guard and rethrow without undoing completed removals.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerDeleteDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10919a2c : g_deleteDirectoryUnwind
const NativeCppUnwindEntry g_deleteDirectoryUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10919a3c : g_deleteDirectoryCatches
const NativeCppCatchHandler g_deleteDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x1090a7bd}, // RethrowDeleteDirectoryPointer
    {0, 0, 0, 0x1090a7d1},                                               // UnwindDeleteDirectoryFailure
};

// RavenShield.exe data @ 10919a5c : g_deleteDirectoryTryBlocks
const NativeCppTryBlock g_deleteDirectoryTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_deleteDirectoryCatches)},
};

// RavenShield.exe data @ 10919a70 : g_deleteDirectoryExceptionInfo
const NativeCppFunctionInfo g_deleteDirectoryExceptionInfo = {
    0x19930520, 2, NativeAddress(g_deleteDirectoryUnwind), 1, NativeAddress(g_deleteDirectoryTryBlocks), 0, 0};

// RavenShield.exe @ 10912610 : HandleDeleteDirectoryException
// Dispatch Windows directory removal's pointer/catch-all guard without rollback cleanup.
__declspec(naked) void HandleDeleteDirectoryException()
{
  __asm {
    mov eax, offset g_deleteDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// Native FindFirst/NextFile records have attributes at +0 and the primary filename at +2c.
struct FileManagerFindDataWX86
{
  uint32_t attributes;
  uint8_t metadata[0x28];
  uint16_t filename[260];
  uint16_t alternateFilename[14];
};
struct FileManagerFindDataAX86
{
  uint32_t attributes;
  uint8_t metadata[0x28];
  char filename[260];
  char alternateFilename[14];
};
extern "C" uint32_t __stdcall FindFirstFileW(const uint16_t *pattern, FileManagerFindDataWX86 *data);
extern "C" uint32_t __stdcall FindFirstFileA(const char *pattern, FileManagerFindDataAX86 *data);
extern "C" int32_t __stdcall FindNextFileW(uint32_t handle, FileManagerFindDataWX86 *data);
extern "C" int32_t __stdcall FindNextFileA(uint32_t handle, FileManagerFindDataAX86 *data);
extern "C" int32_t __stdcall FindClose(uint32_t handle);

// RavenShield.exe data @ 109168cc : g_fileManagerFindFilesGuardName
const char16_t g_fileManagerFindFilesGuardName[] = u"FFileManagerWindows::FindFiles";
// RavenShield.exe data @ 10916194 : g_fileManagerCurrentDirectoryName
extern const char16_t g_fileManagerCurrentDirectoryName[] = u".";
// RavenShield.exe data @ 1091690c : g_fileManagerParentDirectoryName
const char16_t g_fileManagerParentDirectoryName[] = u"..";

// RavenShield.exe @ 1090a810 : FFileManagerWindows::FindFiles
// Enumerate selected filenames, skip dot entries, close on normal paths and deep-copy the local list into the result.
TArray<FString> FFileManagerWindows::FindFiles(const uint16_t *pattern, int32_t files, int32_t directories)
{
  try
  {
    TArray<FString> list; // Shared default-construction body 109041c0 forwards to Core FArray.
    uint32_t handle = 0;
    if (GUnicodeOS != 0)
    {
      FileManagerFindDataWX86 data;
      handle = FindFirstFileW(pattern, &data);
      if (handle != 0xffffffffu)
      {
        do
        {
          if (appStricmp(data.filename, reinterpret_cast<const uint16_t *>(g_fileManagerCurrentDirectoryName)) != 0 &&
              appStricmp(data.filename, reinterpret_cast<const uint16_t *>(g_fileManagerParentDirectoryName)) != 0 &&
              ((data.attributes & 0x10u) != 0 ? directories : files) != 0)
          {
            void *slot = AllocateStringArraySlot(12, &list);
            if (slot != nullptr) new (slot) FString(data.filename);
          }
        } while (FindNextFileW(handle, &data) != 0);
      }
    }
    else
    {
      char *scratch = nullptr;
      if (winGetSizeANSI(pattern) != 0)
      {
        const uint32_t rounded = (static_cast<uint32_t>(winGetSizeANSI(pattern)) + 7u) & ~7u;
        scratch = static_cast<char *>(_alloca((rounded + 3u) & ~3u));
      }
      const int32_t count = winGetSizeANSI(pattern);
      const char *converted = winToANSI(scratch, pattern, count);
      FileManagerFindDataAX86 data;
      uint16_t filename[260]; // Native conversion scratch is uninitialized and reused between entries.
      handle = FindFirstFileA(converted, &data);
      if (handle != 0xffffffffu)
      {
        do
        {
          const int32_t units = MinSigned(260, winGetSizeUNICODE(data.filename));
          winToUNICODE(filename, data.filename, units); // Return ignored; no separate terminator is written here.
          if (appStricmp(filename, reinterpret_cast<const uint16_t *>(g_fileManagerCurrentDirectoryName)) != 0 &&
              appStricmp(filename, reinterpret_cast<const uint16_t *>(g_fileManagerParentDirectoryName)) != 0 &&
              ((data.attributes & 0x10u) != 0 ? directories : files) != 0)
          {
            void *slot = AllocateStringArraySlot(12, &list);
            if (slot != nullptr) new (slot) FString(filename);
          }
        } while (FindNextFileA(handle, &data) != 0);
      }
    }
    if (handle != 0xffffffffu) FindClose(handle); // Ignored result; exceptions do not close the search handle.
    return TArray<FString>(list);                 // Force native deep copy 1090ac10 before local-list destruction.
  }
  // RavenShield.exe @ 1090abac : RethrowFindFilesPointer
  // Copy-throw the caught pointer from parent EBP-5bc through EBP-5c8 after local-list cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090abc9 : UnwindFindFilesFailure
  // Append the enumeration guard and rethrow without closing a live search handle.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_fileManagerFindFilesGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912620 : UnwindFindFilesList
// Destroy the local enumeration array at parent EBP-20.
__declspec(naked) void UnwindFindFilesList()
{
  __asm {
    lea ecx, [ebp-20h]
    jmp NativeEntry_TArray_FString_DestroyTArray
  }
}

// RavenShield.exe @ 10912628 : UnwindFindFilesResult
// Clear the completed-return flag and destroy the caller's result array if return-path unwinding reaches it.
__declspec(naked) void UnwindFindFilesResult()
{
  __asm {
    mov eax, [ebp-5cch]
    and eax, 1
    jz noResult
    and dword ptr [ebp-5cch], 0fffffffeh
    mov ecx, [ebp+8]
    jmp NativeEntry_TArray_FString_DestroyTArray
  noResult:
    ret
  }
}

// RavenShield.exe data @ 10919a8c : g_findFilesUnwind
const NativeCppUnwindEntry g_findFilesUnwind[4] = {
    {-1, NativeAddress(NativeEntry_UnwindFindFilesResult)}, // UnwindFindFilesResult
    {0, 0},
    {1, NativeAddress(NativeEntry_UnwindFindFilesList)}, // UnwindFindFilesList
    {0, 0},
};

// RavenShield.exe data @ 10919aac : g_findFilesCatches
const NativeCppCatchHandler g_findFilesCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x5bc, 0x1090abac}, // RethrowFindFilesPointer
    {0, 0, 0, 0x1090abc9},                                                // UnwindFindFilesFailure
};

// RavenShield.exe data @ 10919acc : g_findFilesTryBlocks
const NativeCppTryBlock g_findFilesTryBlocks[1] = {
    {1, 2, 3, 2, NativeAddress(g_findFilesCatches)},
};

// RavenShield.exe data @ 10919ae0 : g_findFilesExceptionInfo
const NativeCppFunctionInfo g_findFilesExceptionInfo = {
    0x19930520, 4, NativeAddress(g_findFilesUnwind), 1, NativeAddress(g_findFilesTryBlocks), 0, 0};

// RavenShield.exe @ 10912647 : HandleFindFilesException
// Dispatch the local-list, returned-array and typed/catch-all guard states without handle cleanup.
__declspec(naked) void HandleFindFilesException()
{
  __asm {
    mov eax, offset g_findFilesExceptionInfo
    jmp DispatchExecutableCppException
  }
}
