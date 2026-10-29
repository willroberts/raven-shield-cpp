#include "native_symbols.hpp"
// Generic file-manager copying, directory creation/deletion and drive-prefix classification.
#include "cpp_exception_metadata.hpp"
#include <cstdint>
#include "allocation_support.hpp"
#include "file_manager_support.hpp"
#include "container_support.hpp"

class FFileManagerGeneric;
class FArchive;
class FOutputDevice;
extern FOutputDevice *GNull;
extern void __cdecl appFailAssert(const char *expression, const char *file, int32_t line);
extern void __cdecl appUnwindf(const uint16_t *format, ...);
extern int32_t __cdecl appStricmp(const uint16_t *left, const uint16_t *right);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern uint16_t *__cdecl appStrchr(const uint16_t *text, int32_t character);
extern uint32_t __cdecl UppercaseAsciiUtf16(uint16_t character);
extern uint32_t __cdecl LowercaseAsciiUtf16(uint16_t character);
extern const char16_t g_configEmptyString[];
extern const char16_t g_unwindContextFormat[];
extern "C" void DispatchExecutableCppException();

// RavenShield.exe data @ 10915910 : g_genericMakeDirectoryGuardName
const char16_t g_genericMakeDirectoryGuardName[] = u"FFileManagerGeneric::MakeDirectory";
// RavenShield.exe data @ 10915958 : g_fileManagerPathSeparator
const char16_t g_fileManagerPathSeparator[] = u"\\";
// RavenShield.exe data @ 1091595c : g_genericMakeDirectoryTreeExpression
const char g_genericMakeDirectoryTreeExpression[] = "Tree";
// RavenShield.exe data @ 10915964 : g_genericFileManagerSourcePath
const char g_genericFileManagerSourcePath[] = "d:\\ravenshield\\412\\core\\inc\\FFileManagerGeneric.h";

// RavenShield.exe @ 10905a80 : FFileManagerGeneric::MakeDirectory
// Build unchecked prefixes, skip the first boundary and drives, and count successful virtual creation calls.
int32_t FFileManagerGeneric::MakeDirectory(const uint16_t *path, int32_t tree)
{
  using MakeDirectoryCall = int32_t(__thiscall *)(FFileManagerGeneric *, const uint16_t *, int32_t);
  try
  {
    if (tree == 0) appFailAssert(g_genericMakeDirectoryTreeExpression, g_genericFileManagerSourcePath, 0x4c);
    uint32_t slashCount = 0;
    uint32_t createCount = 0;
    uint16_t full[0x100];
    full[0] = static_cast<uint16_t>(g_configEmptyString[0]);
    for (uint32_t i = 1; i < 0x100; ++i) full[i] = 0;
    uint16_t *cursor = full;
    for (;;)
    {
      if (*path == static_cast<uint16_t>(g_fileManagerPathSeparator[0]) || *path == 0)
      {
        const uint32_t previous = slashCount++;
        if (static_cast<int32_t>(previous) > 0 && !FFileManagerGeneric::IsDrive(full))
        {
          *cursor = 0;
          const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
          auto create = *reinterpret_cast<MakeDirectoryCall *>(table + 0x24);
          if (create(this, full, 0) == 0) return 0;
          ++createCount;
        }
      }
      if (*path == 0) break;
      *cursor = *path;
      ++cursor;
      ++path;
    }
    return createCount != 0 ? 1 : 0;
  }
  // RavenShield.exe @ 10905be1 : RethrowGenericMakeDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-220 through EBP-224.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10905bfe : UnwindGenericMakeDirectoryFailure
  // Append the generic creation guard and rethrow without removing any accepted prefixes.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_genericMakeDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918f9c : g_genericMakeDirectoryUnwind
const NativeCppUnwindEntry g_genericMakeDirectoryUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918fac : g_genericMakeDirectoryCatches
const NativeCppCatchHandler g_genericMakeDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x220, 0x10905be1}, // RethrowGenericMakeDirectoryPointer
    {0, 0, 0, 0x10905bfe},                                                // UnwindGenericMakeDirectoryFailure
};

// RavenShield.exe data @ 10918fcc : g_genericMakeDirectoryTryBlocks
const NativeCppTryBlock g_genericMakeDirectoryTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_genericMakeDirectoryCatches)},
};

// RavenShield.exe data @ 10918fe0 : g_genericMakeDirectoryExceptionInfo
const NativeCppFunctionInfo g_genericMakeDirectoryExceptionInfo = {
    0x19930520, 2, NativeAddress(g_genericMakeDirectoryUnwind), 1, NativeAddress(g_genericMakeDirectoryTryBlocks),
    0,          0};

// RavenShield.exe @ 109123a0 : HandleGenericMakeDirectoryException
// Dispatch the generic tree builder's pointer/catch-all guard without prefix rollback cleanup.
__declspec(naked) void HandleGenericMakeDirectoryException()
{
  __asm {
    mov eax, offset g_genericMakeDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10915998 : g_genericIsDriveGuardName
const char16_t g_genericIsDriveGuardName[] = u"FFileManagerGeneric::IsDrive";
// RavenShield.exe data @ 109159d4 : g_fileManagerDoubleSeparator
const char16_t g_fileManagerDoubleSeparator[] = u"\\\\";

// RavenShield.exe @ 10905c40 : FFileManagerGeneric::IsDrive
// Recognize empty, drive-letter, separator and shallow UNC prefixes with the native repeated searches.
int32_t FFileManagerGeneric::IsDrive(const uint16_t *path)
{
  try
  {
    if (appStricmp(path, reinterpret_cast<const uint16_t *>(g_configEmptyString)) == 0) return 1;
    const uint16_t lower = static_cast<uint16_t>(LowercaseAsciiUtf16(path[0]));
    const uint16_t upper = static_cast<uint16_t>(UppercaseAsciiUtf16(path[0]));
    if (upper != lower && path[1] == ':' && path[2] == 0) return 1;
    if (appStricmp(path, reinterpret_cast<const uint16_t *>(g_fileManagerPathSeparator)) == 0) return 1;
    if (appStricmp(path, reinterpret_cast<const uint16_t *>(g_fileManagerDoubleSeparator)) == 0) return 1;
    if (path[0] == '\\' && path[1] == '\\' && appStrchr(path + 2, '\\') == nullptr) return 1;
    if (path[0] == '\\' && path[1] == '\\' && appStrchr(path + 2, '\\') != nullptr)
    {
      const uint16_t *separator = appStrchr(path + 2, '\\');
      const auto *afterSeparator = reinterpret_cast<const uint16_t *>(reinterpret_cast<uint32_t>(separator) + 2u);
      if (appStrchr(afterSeparator, '\\') == nullptr) return 1;
    }
    return 0;
  }
  // RavenShield.exe @ 10905dd2 : RethrowIsDrivePointer
  // Copy-throw the caught pointer from parent EBP-14 through EBP-18.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10905de6 : UnwindIsDriveFailure
  // Append the drive-classifier guard and rethrow without changing the supplied path.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_genericIsDriveGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918ffc : g_isDriveUnwind
const NativeCppUnwindEntry g_isDriveUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091900c : g_isDriveCatches
const NativeCppCatchHandler g_isDriveCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x14, 0x10905dd2}, // RethrowIsDrivePointer
    {0, 0, 0, 0x10905de6},                                               // UnwindIsDriveFailure
};

// RavenShield.exe data @ 1091902c : g_isDriveTryBlocks
const NativeCppTryBlock g_isDriveTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_isDriveCatches)},
};

// RavenShield.exe data @ 10919040 : g_isDriveExceptionInfo
const NativeCppFunctionInfo g_isDriveExceptionInfo = {
    0x19930520, 2, NativeAddress(g_isDriveUnwind), 1, NativeAddress(g_isDriveTryBlocks), 0, 0};

// RavenShield.exe @ 109123b0 : HandleIsDriveException
// Dispatch the drive classifier's pointer/catch-all guard without ownership cleanup.
__declspec(naked) void HandleIsDriveException()
{
  __asm {
    mov eax, offset g_isDriveExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 109158dc : g_genericCopyGuardName
const char16_t g_genericCopyGuardName[] = u"FFileManagerGeneric::Copy";

// RavenShield.exe @ 10905720 : FFileManagerGeneric::Copy
// Copy chunks, report progress and release archives explicitly; guarded exceptions do not clean up raw pointers.
uint32_t FFileManagerGeneric::Copy(const uint16_t *destination, const uint16_t *source, int32_t replace,
                                   int32_t evenReadOnly, int32_t attributes, FileCopyProgress progress)
{
  using OpenArchive = FArchive *(__thiscall *)(FFileManagerGeneric *, const uint16_t *, uint32_t, FOutputDevice *);
  using ArchiveQuery = int32_t(__thiscall *)(FArchive *);
  using ArchiveSerialize = void(__thiscall *)(FArchive *, void *, int32_t);
  using ArchiveDelete = void *(__thiscall *)(FArchive *, uint32_t);
  using FileDelete = int32_t(__thiscall *)(FFileManagerGeneric *, const uint16_t *, int32_t, int32_t);
  try
  {
    uint32_t result = 0;
    if (progress != nullptr) progress(0.0f);
    FOutputDevice *readError = GNull;
    uint32_t table = *reinterpret_cast<const uint32_t *>(this);
    auto openReader = *reinterpret_cast<OpenArchive *>(table + 4);
    FArchive *reader = openReader(this, source, 0, readError);
    if (reader != nullptr)
    {
      table = *reinterpret_cast<const uint32_t *>(reader);
      auto totalSize = *reinterpret_cast<ArchiveQuery *>(table + 0x2c);
      const int32_t total = totalSize(reader);
      FOutputDevice *writeError = GNull;
      const uint32_t flags = (replace == 0 ? 2u : 0u) | (evenReadOnly != 0 ? 4u : 0u);
      table = *reinterpret_cast<const uint32_t *>(this);
      auto openWriter = *reinterpret_cast<OpenArchive *>(table + 8);
      FArchive *writer = openWriter(this, destination, flags, writeError);
      if (writer != nullptr)
      {
        uint8_t buffer[0x1000];
        for (uint32_t offset = 0; static_cast<int32_t>(offset) < total; offset += 0x1000u)
        {
          const int32_t count = MinSigned(static_cast<int32_t>(static_cast<uint32_t>(total) - offset), 0x1000);
          table = *reinterpret_cast<const uint32_t *>(reader);
          auto read = *reinterpret_cast<ArchiveSerialize *>(table + 4);
          read(reader, buffer, count);
          const auto readFailed = *reinterpret_cast<const ArchiveQuery *>(NativeAddress(NativeImport_FArchive_IsError));
          if (readFailed(reader) != 0) break;
          table = *reinterpret_cast<const uint32_t *>(writer);
          auto write = *reinterpret_cast<ArchiveSerialize *>(table + 4);
          write(writer, buffer, count);
          const auto writeFailed =
              *reinterpret_cast<const ArchiveQuery *>(NativeAddress(NativeImport_FArchive_IsError));
          if (writeFailed(writer) != 0) break;
          if (progress != nullptr)
          {
            const int32_t signedOffset = static_cast<int32_t>(offset);
            float fraction;
            __asm {
              fild total
              fidivr signedOffset
              fstp fraction
            }
            progress(fraction);
          }
        }
        table = *reinterpret_cast<const uint32_t *>(writer);
        auto closeWriter = *reinterpret_cast<ArchiveQuery *>(table + 0x50);
        result = static_cast<uint32_t>(closeWriter(writer));
        if (writer != nullptr)
        {
          table = *reinterpret_cast<const uint32_t *>(writer);
          auto destroyWriter = *reinterpret_cast<ArchiveDelete *>(table);
          destroyWriter(writer, 1);
        }
        if (result == 0)
        {
          table = *reinterpret_cast<const uint32_t *>(this);
          auto remove = *reinterpret_cast<FileDelete *>(table + 0x10);
          remove(this, destination, 0, 0);
        }
      }
      if (result != 0)
      {
        table = *reinterpret_cast<const uint32_t *>(reader);
        auto closeReader = *reinterpret_cast<ArchiveQuery *>(table + 0x50);
        result = closeReader(reader) != 0 ? 1u : 0u;
      }
      else
      {
        result = 0;
      }
      if (reader != nullptr)
      {
        table = *reinterpret_cast<const uint32_t *>(reader);
        auto destroyReader = *reinterpret_cast<ArchiveDelete *>(table);
        destroyReader(reader, 1);
      }
    }
    if (progress != nullptr) progress(1.0f);
    return result;
  }
  // RavenShield.exe @ 10905a1b : RethrowGenericCopyPointer
  // Copy-throw the caught pointer from parent EBP-102c through EBP-1040.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 10905a38 : UnwindGenericCopyFailure
  // Append the generic copy guard and rethrow without deleting archives or the destination on exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_genericCopyGuardName));
    throw;
  }
}

// RavenShield.exe data @ 10918f3c : g_genericCopyUnwind
const NativeCppUnwindEntry g_genericCopyUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 10918f4c : g_genericCopyCatches
const NativeCppCatchHandler g_genericCopyCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x102c, 0x10905a1b}, // RethrowGenericCopyPointer
    {0, 0, 0, 0x10905a38},                                                 // UnwindGenericCopyFailure
};

// RavenShield.exe data @ 10918f6c : g_genericCopyTryBlocks
const NativeCppTryBlock g_genericCopyTryBlocks[1] = {
    {0, 0, 1, 2, NativeAddress(g_genericCopyCatches)},
};

// RavenShield.exe data @ 10918f80 : g_genericCopyExceptionInfo
const NativeCppFunctionInfo g_genericCopyExceptionInfo = {
    0x19930520, 2, NativeAddress(g_genericCopyUnwind), 1, NativeAddress(g_genericCopyTryBlocks), 0, 0};

// RavenShield.exe @ 10912390 : HandleGenericCopyException
// Dispatch generic copy's pointer/catch-all guard without archive or file rollback actions.
__declspec(naked) void HandleGenericCopyException()
{
  __asm {
    mov eax, offset g_genericCopyExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10916830 : g_genericDeleteDirectoryGuardName
const char16_t g_genericDeleteDirectoryGuardName[] = u"FFileManagerGeneric::DeleteDirectory";
// RavenShield.exe data @ 1091687c : g_fileManagerWildcard
const char16_t g_fileManagerWildcard[] = u"*";

// RavenShield.exe @ 1090a1b0 : FFileManagerGeneric::DeleteDirectory
// Delete enumerated files, recurse through a replacement directory list, then remove the parent without recursion.
int32_t FFileManagerGeneric::DeleteDirectory(const uint16_t *path, int32_t requireExists, int32_t tree)
{
  // FindFiles returns its array through caller-owned storage before the three visible stack arguments.
  using FindFiles = TArray<FString>(__thiscall *)(FFileManagerGeneric *, const uint16_t *, int32_t, int32_t);
  using Remove = int32_t(__thiscall *)(FFileManagerGeneric *, const uint16_t *, int32_t, int32_t);
  try
  {
    if (tree == 0) appFailAssert(g_genericMakeDirectoryTreeExpression, g_genericFileManagerSourcePath, 0x64);
    if (appStrlen(path) == 0) return 0;
    FString pattern = FString(path) * reinterpret_cast<const uint16_t *>(g_fileManagerWildcard);
    const uint16_t *specification = *pattern;
    uint32_t table = *reinterpret_cast<const uint32_t *>(this);
    auto findFiles = *reinterpret_cast<FindFiles *>(table + 0x2c);
    TArray<FString> list = findFiles(this, specification, 1, 0);
    for (uint32_t index = 0; static_cast<int32_t>(index) < list.Num(); ++index)
    {
      bool failed;
      {
        FString base(path);
        FString child = base * list(static_cast<int32_t>(index));
        const uint16_t *childPath = *child;
        table = *reinterpret_cast<const uint32_t *>(this);
        auto removeFile = *reinterpret_cast<Remove *>(table + 0x10);
        failed = removeFile(this, childPath, 1, 1) == 0;
      }
      if (failed) return 0;
    }
    specification = *pattern;
    table = *reinterpret_cast<const uint32_t *>(this);
    findFiles = *reinterpret_cast<FindFiles *>(table + 0x2c);
    list = findFiles(this, specification, 0, 1); // Deep assignment precedes destruction of the returned temporary.
    for (uint32_t index = 0; static_cast<int32_t>(index) < list.Num(); ++index)
    {
      bool failed;
      {
        FString base(path);
        FString child = base * list(static_cast<int32_t>(index));
        const uint16_t *childPath = *child;
        table = *reinterpret_cast<const uint32_t *>(this);
        auto removeDirectory = *reinterpret_cast<Remove *>(table + 0x28);
        failed = removeDirectory(this, childPath, 1, 1) == 0;
      }
      if (failed) return 0;
    }
    table = *reinterpret_cast<const uint32_t *>(this);
    auto removeDirectory = *reinterpret_cast<Remove *>(table + 0x28);
    return removeDirectory(this, path, requireExists, 0); // Preserve raw EAX across list then pattern destruction.
  }
  // RavenShield.exe @ 1090a5a0 : RethrowGenericDeleteDirectoryPointer
  // Copy-throw the caught pointer from parent EBP-34 through EBP-94 after local cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090a5ba : UnwindGenericDeleteDirectoryFailure
  // Append the recursive deletion guard and rethrow after automatic string/array cleanup.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_genericDeleteDirectoryGuardName));
    throw;
  }
}

// RavenShield.exe @ 109125b0 : UnwindRecursiveDeletePatternBase
// Destroy the path temporary at parent EBP-40 when constructing the wildcard pattern fails.
__declspec(naked) void UnwindRecursiveDeletePatternBase()
{
  __asm {
    lea ecx, [ebp-40h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109125b9 : UnwindRecursiveDeletePattern
// Destroy the completed wildcard pattern at parent EBP-28.
__declspec(naked) void UnwindRecursiveDeletePattern()
{
  __asm {
    lea ecx, [ebp-28h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109125c2 : UnwindRecursiveDeleteList
// Destroy the active file/directory array at parent EBP-1c through its canonical destructor.
__declspec(naked) void UnwindRecursiveDeleteList()
{
  __asm {
    lea ecx, [ebp-1ch]
    jmp NativeEntry_TArray_FString_DestroyTArray
  }
}

// RavenShield.exe @ 109125ca : UnwindRecursiveDeleteFileBase
// Destroy the current file's base-path temporary at parent EBP-50.
__declspec(naked) void UnwindRecursiveDeleteFileBase()
{
  __asm {
    lea ecx, [ebp-50h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109125d3 : UnwindRecursiveDeleteFilePath
// Destroy the current joined file path at parent EBP-5c.
__declspec(naked) void UnwindRecursiveDeleteFilePath()
{
  __asm {
    lea ecx, [ebp-5ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109125dc : UnwindRecursiveDeleteReplacementList
// Destroy the directory-enumeration result at parent EBP-6c if deep assignment throws.
__declspec(naked) void UnwindRecursiveDeleteReplacementList()
{
  __asm {
    lea ecx, [ebp-6ch]
    jmp NativeEntry_TArray_FString_DestroyTArray
  }
}

// RavenShield.exe @ 109125e4 : UnwindRecursiveDeleteDirectoryBase
// Destroy the current subdirectory's base-path temporary at parent EBP-7c.
__declspec(naked) void UnwindRecursiveDeleteDirectoryBase()
{
  __asm {
    lea ecx, [ebp-7ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 109125ed : UnwindRecursiveDeleteDirectoryPath
// Destroy the current joined subdirectory path at parent EBP-88.
__declspec(naked) void UnwindRecursiveDeleteDirectoryPath()
{
  __asm {
    lea ecx, [ebp-88h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 10919984 : g_genericDeleteDirectoryUnwind
const NativeCppUnwindEntry g_genericDeleteDirectoryUnwind[11] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindRecursiveDeletePatternBase)},     // UnwindRecursiveDeletePatternBase
    {1, NativeAddress(NativeEntry_UnwindRecursiveDeletePattern)},         // UnwindRecursiveDeletePattern
    {0, NativeAddress(NativeEntry_UnwindRecursiveDeletePattern)},         // UnwindRecursiveDeletePattern
    {3, NativeAddress(NativeEntry_UnwindRecursiveDeleteList)},            // UnwindRecursiveDeleteList
    {4, NativeAddress(NativeEntry_UnwindRecursiveDeleteFileBase)},        // UnwindRecursiveDeleteFileBase
    {5, NativeAddress(NativeEntry_UnwindRecursiveDeleteFilePath)},        // UnwindRecursiveDeleteFilePath
    {4, NativeAddress(NativeEntry_UnwindRecursiveDeleteReplacementList)}, // UnwindRecursiveDeleteReplacementList
    {4, NativeAddress(NativeEntry_UnwindRecursiveDeleteDirectoryBase)},   // UnwindRecursiveDeleteDirectoryBase
    {8, NativeAddress(NativeEntry_UnwindRecursiveDeleteDirectoryPath)},   // UnwindRecursiveDeleteDirectoryPath
    {-1, 0},
};

// RavenShield.exe data @ 109199dc : g_genericDeleteDirectoryCatches
const NativeCppCatchHandler g_genericDeleteDirectoryCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x34, 0x1090a5a0}, // RethrowGenericDeleteDirectoryPointer
    {0, 0, 0, 0x1090a5ba},                                               // UnwindGenericDeleteDirectoryFailure
};

// RavenShield.exe data @ 109199fc : g_genericDeleteDirectoryTryBlocks
const NativeCppTryBlock g_genericDeleteDirectoryTryBlocks[1] = {
    {0, 9, 10, 2, NativeAddress(g_genericDeleteDirectoryCatches)},
};

// RavenShield.exe data @ 10919a10 : g_genericDeleteDirectoryExceptionInfo
const NativeCppFunctionInfo g_genericDeleteDirectoryExceptionInfo = {
    0x19930520, 11, NativeAddress(g_genericDeleteDirectoryUnwind), 1, NativeAddress(g_genericDeleteDirectoryTryBlocks),
    0,          0};

// RavenShield.exe @ 109125f9 : HandleGenericDeleteDirectoryException
// Dispatch eleven lifetime/guard states for recursive directory deletion.
__declspec(naked) void HandleGenericDeleteDirectoryException()
{
  __asm {
    mov eax, offset g_genericDeleteDirectoryExceptionInfo
    jmp DispatchExecutableCppException
  }
}
