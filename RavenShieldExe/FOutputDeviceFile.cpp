#include "native_symbols.hpp"
// File-log construction, serialization and destruction; offsets retain the selected x86 object layout.
#include "cpp_exception_metadata.hpp"
#include "launch_runtime.hpp"

class FArchive;
class FOutputDevice;
extern const uint16_t *__cdecl appTimestamp();
using ImportedOutputLogf = void(__cdecl *)(FOutputDevice *, int32_t, const uint16_t *, ...);
using ArchiveDeletingDestructor = void *(__thiscall *)(FArchive *, uint32_t);

// RavenShield.exe data @ 10914e60 : g_fileLogVtable
// Native x86 virtual-table words retain slot offsets and canonical targets without adding public class fields.
const uint32_t g_fileLogVtable[1] = {
    NativeAddress(NativeEntry_FOutputDeviceFile_Serialize), // +000 FOutputDeviceFile::Serialize
};

// RavenShield.exe data @ 1093fdc8 : g_launchFileLogStorage
alignas(4) uint8_t g_launchFileLogStorage[0x810] = {};

// RavenShield.exe data @ 10914e64 : g_fileLogClosureFormat
const char16_t g_fileLogClosureFormat[] = u"Log file closed, %s";

// RavenShield.exe @ 10912f90 : InitializeLaunchFileLog
// Construct the static file logger and register its destructor, ignoring registration failure.
void __cdecl InitializeLaunchFileLog()
{
  const auto constructBase =
      *reinterpret_cast<const ImportedBaseConstructor *>(NativeAddress(NativeImport_FOutputDeviceConstruct));
  auto *object = g_launchFileLogStorage;
  constructBase(object); // Core.dll FOutputDevice::FOutputDevice; derived construction is inlined here.
  *reinterpret_cast<const uint32_t **>(object) = g_fileLogVtable;
  *reinterpret_cast<uint32_t *>(object + 4) = 0;     // LogAr.
  *reinterpret_cast<uint32_t *>(object + 0x808) = 0; // Opened.
  *reinterpret_cast<uint32_t *>(object + 0x80c) = 0; // Dead.
  *reinterpret_cast<uint16_t *>(object + 8) = 0;     // Only Filename[0] is cleared by construction.
  RegisterExecutableAtExit(DestroyLaunchFileLog);
}

// RavenShield.exe @ 10902ec0 : FOutputDeviceFile::~FOutputDeviceFile
// Log closure when an archive exists, reload and virtually delete it, then clear the archive word.
FOutputDeviceFile::~FOutputDeviceFile() noexcept(false)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  *reinterpret_cast<const uint32_t **>(object) = g_fileLogVtable;
  uint32_t &archiveAddress = *reinterpret_cast<uint32_t *>(object + 4);
  if (archiveAddress != 0)
  {
    const uint16_t *timestamp = appTimestamp();
    const auto logf = *reinterpret_cast<const ImportedOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
    logf(reinterpret_cast<FOutputDevice *>(this), 0x2f8, reinterpret_cast<const uint16_t *>(g_fileLogClosureFormat),
         timestamp);                                                  // NAME_Log.
    FArchive *archive = reinterpret_cast<FArchive *>(archiveAddress); // Logging may have changed LogAr.
    if (archive != nullptr)
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(archive);
      const auto destroy = *reinterpret_cast<const ArchiveDeletingDestructor *>(table);
      destroy(archive, 1); // Scalar deleting destructor in virtual slot zero; return value is ignored.
    }
    archiveAddress = 0;
  }
}

// RavenShield.exe @ 10913040 : DestroyLaunchFileLog
// Destroy the static file logger without freeing its global backing storage.
void __cdecl DestroyLaunchFileLog()
{
  reinterpret_cast<FOutputDeviceFile *>(g_launchFileLogStorage)->~FOutputDeviceFile();
}

class FName;
class FFileManager;
extern FFileManager *GFileManager;
extern FOutputDevice *GNull;
extern FOutputDevice *GLogHook;
extern int32_t GIsCriticalError;
extern const uint16_t *__cdecl appBaseDir();
extern const uint16_t *__cdecl appCmdLine();
extern const uint16_t *__cdecl appPackage();
extern const char16_t g_configSectionBreakFormat[]; // Shared native CRLF, canonical in FConfigFile.cpp.
extern uint16_t *__cdecl appStrcpy(uint16_t *destination, const uint16_t *source);
extern uint16_t *__cdecl appStrcat(uint16_t *destination, const uint16_t *source);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern int32_t __cdecl Parse(const uint16_t *stream, const uint16_t *match, uint16_t *value, int32_t capacity);
extern int32_t __cdecl appSprintf(uint16_t *destination, const uint16_t *format, ...);
extern uint32_t __cdecl NarrowUtf16ToLogByte(uint16_t character);
extern "C" void DispatchExecutableCppException();
using FileLogCreateWriter = FArchive *(__thiscall *)(FFileManager *, const uint16_t *, uint32_t, FOutputDevice *);
using FileLogArchiveSerialize = void(__thiscall *)(FArchive *, void *, int32_t);
using FileLogOutputSerialize = void(__thiscall *)(FOutputDevice *, const uint16_t *, int32_t);

// Native adjacent scratch buffers at EBP-c10 and EBP-410; neither formatter nor narrowing loop has a size gate.
struct FileLogScratchX86
{
  uint16_t wide[0x400];
  uint8_t ansi[0x400];
};

// RavenShield.exe data @ 109405f4 : g_fileLogCriticalEntry
int32_t g_fileLogCriticalEntry = 0;
// RavenShield.exe data @ 10914e8c : g_fileLogLineFormat
const char16_t g_fileLogLineFormat[] = u"%s: %s%s";
// RavenShield.exe data @ 10914ea8 : g_fileLogOpenFormat
const char16_t g_fileLogOpenFormat[] = u"Log file open, %s";
// RavenShield.exe data @ 10914ecc : g_fileLogExtension
const char16_t g_fileLogExtension[] = u".log";
// RavenShield.exe data @ 10914ed8 : g_fileLogAbsoluteOption
const char16_t g_fileLogAbsoluteOption[] = u"ABSLOG=";
// RavenShield.exe data @ 10914ee8 : g_fileLogRelativeOption
const char16_t g_fileLogRelativeOption[] = u"LOG=";

// RavenShield.exe @ 10902f40 : FOutputDeviceFile::Serialize
// Lazily open the ANSI log, serialize unsuppressed non-title lines and forward the hook; retry critical calls guarded.
void FOutputDeviceFile::Serialize(const uint16_t *data, int32_t event)
{
  if (GIsCriticalError != 0 && g_fileLogCriticalEntry == 0)
  {
    g_fileLogCriticalEntry = 1;
    try
    {
      const uint32_t table = *reinterpret_cast<const uint32_t *>(this);
      const auto serialize = *reinterpret_cast<const FileLogOutputSerialize *>(table);
      serialize(reinterpret_cast<FOutputDevice *>(this), data, event); // Reenter through the live virtual slot.
    }
    // RavenShield.exe @ 10903250 : SwallowCriticalFileLogFailure
    // Discard a failure from critical-path virtual serialization and resume before clearing the shared entry flag.
    catch (...)
    {
    }
    g_fileLogCriticalEntry = 0;
    return;
  }
  if (FName::SafeSuppressed(event) != 0) return;
  auto *object = reinterpret_cast<uint8_t *>(this);
  auto *filename = reinterpret_cast<uint16_t *>(object + 8);
  if (*reinterpret_cast<const uint32_t *>(object + 4) == 0 && *reinterpret_cast<const uint32_t *>(object + 0x80c) == 0)
  {
    if (*filename == 0)
    {
      const uint16_t *baseDirectory = appBaseDir();
      appStrcpy(filename, baseDirectory);
      const int32_t firstLength = appStrlen(filename);
      const int32_t capacity = static_cast<int32_t>(0x400u - static_cast<uint32_t>(firstLength));
      const int32_t secondLength = appStrlen(filename);
      auto *tail =
          reinterpret_cast<uint16_t *>(reinterpret_cast<uint32_t>(filename) + static_cast<uint32_t>(secondLength) * 2);
      const uint16_t *commandLine = appCmdLine();
      if (Parse(commandLine, reinterpret_cast<const uint16_t *>(g_fileLogRelativeOption), tail, capacity) == 0)
      {
        const uint16_t *absoluteCommandLine = appCmdLine();
        if (Parse(absoluteCommandLine, reinterpret_cast<const uint16_t *>(g_fileLogAbsoluteOption), filename, 0x400) ==
            0)
        {
          const uint16_t *package = appPackage();
          appStrcat(filename, package);
          appStrcat(filename, reinterpret_cast<const uint16_t *>(g_fileLogExtension));
        }
      }
    }
    FOutputDevice *errorOutput = GNull;
    const uint32_t flags = 0x28u | (*reinterpret_cast<const uint32_t *>(object + 0x808) != 0 ? 0x10u : 0);
    FFileManager *receiver = GFileManager;
    FFileManager *dispatchManager = GFileManager;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchManager);
    const auto createWriter = *reinterpret_cast<const FileLogCreateWriter *>(table + 8);
    *reinterpret_cast<FArchive **>(object + 4) = createWriter(receiver, filename, flags, errorOutput);
    if (*reinterpret_cast<const uint32_t *>(object + 4) != 0)
    {
      *reinterpret_cast<uint32_t *>(object + 0x808) = 1;
      const uint16_t *timestamp = appTimestamp();
      const auto logf =
          *reinterpret_cast<const ImportedOutputLogf *>(NativeAddress(NativeImport_FOutputDeviceLogfEvent));
      logf(reinterpret_cast<FOutputDevice *>(this), 0x2f8, reinterpret_cast<const uint16_t *>(g_fileLogOpenFormat),
           timestamp);
    }
    else
    {
      *reinterpret_cast<uint32_t *>(object + 0x80c) = 1;
    }
  }
  if (*reinterpret_cast<const uint32_t *>(object + 4) != 0 && event != 0x314)
  { // NAME_Title skips only file output.
    alignas(4) FileLogScratchX86 scratch;
    const uint16_t *eventName = FName::SafeString(event);
    appSprintf(scratch.wide, reinterpret_cast<const uint16_t *>(g_fileLogLineFormat), eventName, data,
               reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat));
    const uint32_t wide = reinterpret_cast<uint32_t>(scratch.wide);
    const uint32_t ansi = reinterpret_cast<uint32_t>(scratch.ansi);
    uint32_t index = 0;
    while (*reinterpret_cast<const uint16_t *>(wide + index * 2) != 0)
    {
      const uint16_t character = *reinterpret_cast<const uint16_t *>(wide + index * 2);
      *reinterpret_cast<uint8_t *>(ansi + index) = static_cast<uint8_t>(NarrowUtf16ToLogByte(character));
      ++index;
    }
    *reinterpret_cast<uint8_t *>(ansi + index) = 0; // NUL is written locally but excluded from the archive length.
    FArchive *receiver = *reinterpret_cast<FArchive **>(object + 4);
    FArchive *dispatchArchive = *reinterpret_cast<FArchive **>(object + 4);
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchArchive);
    const auto serialize = *reinterpret_cast<const FileLogArchiveSerialize *>(table + 4);
    serialize(receiver, scratch.ansi, static_cast<int32_t>(index));
  }
  if (GLogHook != nullptr)
  {
    FOutputDevice *receiver = GLogHook;
    FOutputDevice *dispatchHook = GLogHook;
    const uint32_t table = *reinterpret_cast<const uint32_t *>(dispatchHook);
    const auto serialize = *reinterpret_cast<const FileLogOutputSerialize *>(table);
    serialize(receiver, data, event);
  }
}

// RavenShield.exe data @ 109187fc : g_fileLogSerializeUnwind
const NativeCppUnwindEntry g_fileLogSerializeUnwind[2] = {
    {-1, 0},
    {-1, 0},
};

// RavenShield.exe data @ 1091880c : g_fileLogSerializeCatches
const NativeCppCatchHandler g_fileLogSerializeCatches[1] = {
    {0, 0, 0, 0x10903250}, // SwallowCriticalFileLogFailure
};

// RavenShield.exe data @ 1091881c : g_fileLogSerializeTryBlocks
const NativeCppTryBlock g_fileLogSerializeTryBlocks[1] = {
    {0, 0, 1, 1, NativeAddress(g_fileLogSerializeCatches)},
};

// RavenShield.exe data @ 10918830 : g_fileLogSerializeExceptionInfo
const NativeCppFunctionInfo g_fileLogSerializeExceptionInfo = {
    0x19930520, 2, NativeAddress(g_fileLogSerializeUnwind), 1, NativeAddress(g_fileLogSerializeTryBlocks), 0, 0};

// RavenShield.exe @ 109121d0 : HandleFileLogSerializeException
// Supply the two-state single catch-all map protecting only the critical-error virtual retry.
__declspec(naked) void HandleFileLogSerializeException()
{
  __asm {
    mov eax, offset g_fileLogSerializeExceptionInfo
    jmp DispatchExecutableCppException
  }
}
