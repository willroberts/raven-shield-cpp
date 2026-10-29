#include "native_symbols.hpp"
// Native config-file parsing/serialization: map +0, Dirty +14 and NoSave +18 in the selected 28-byte object.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include "launch_runtime.hpp"

class FFileManager;
extern FFileManager *GFileManager;
extern int32_t __cdecl appSaveStringToFile(const FString &text, const uint16_t *filename, FFileManager *fileManager);
extern void __cdecl appUnwindf(const uint16_t *format, ...);

// RavenShield.exe data @ 10917d64 : g_configFileWriteGuardName
const char16_t g_configFileWriteGuardName[] = u"FConfigFile::Write";
// RavenShield.exe data @ 10917d8c : g_configEntryFormat
const char16_t g_configEntryFormat[] = u"%s=%s\r\n";
// RavenShield.exe data @ 10917d9c : g_configSectionFormat
const char16_t g_configSectionFormat[] = u"[%s]\r\n";
// RavenShield.exe data @ 10914ea0 : g_configSectionBreakFormat
extern const char16_t g_configSectionBreakFormat[] = u"\r\n";

// RavenShield.exe @ 1090f420 : FConfigFile::Write
// Serialize dirty, save-enabled files in pair order; clear Dirty before construction and return the raw save result.
int32_t FConfigFile::Write(const uint16_t *filename)
{
  auto *object = reinterpret_cast<uint8_t *>(this);
  const int32_t dirtyOnEntry = *reinterpret_cast<const int32_t *>(object + 0x14); // Before guard state zero.
  try
  {
    if (dirtyOnEntry == 0 || *reinterpret_cast<const int32_t *>(object + 0x18) != 0) return 1;
    *reinterpret_cast<int32_t *>(object + 0x14) = 0;
    FString text;
    using SectionMap = TMapBase<FString, FConfigSection>;
    using EntryMap = TMapBase<FString, FString>;
    {
      for (SectionMap::TIterator section(*reinterpret_cast<SectionMap *>(this)); section; ++section)
      {
        text += FString::Printf(reinterpret_cast<const uint16_t *>(g_configSectionFormat), *section.Key());
        {
          auto *entries = reinterpret_cast<EntryMap *>(&section.Value());
          for (EntryMap::TIterator entry(*entries); entry; ++entry)
          {
            const uint16_t *value = *entry.Value(); // Native evaluates value text before key text.
            const uint16_t *key = *entry.Key();
            text += FString::Printf(reinterpret_cast<const uint16_t *>(g_configEntryFormat), key, value);
          }
        }
        text += FString::Printf(reinterpret_cast<const uint16_t *>(g_configSectionBreakFormat));
      }
    }
    return appSaveStringToFile(text, filename, GFileManager); // Capture result before automatic text destruction.
  }
  // RavenShield.exe @ 1090f5f5 : RethrowConfigFileWritePointer
  // Copy-throw the caught unsigned-short pointer after local string/iterator cleanup.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090f609 : UnwindConfigFileWriteFailure
  // Append the writer guard name and rethrow the active non-pointer exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configFileWriteGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912ca0 : UnwindConfigFileWriteText
// Destroy the completed output string at parent EBP-24.
__declspec(naked) void UnwindConfigFileWriteText()
{
  __asm {
    lea ecx, [ebp-24h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912ca9 : UnwindConfigFileWriteSectionIterator
// Destroy the writer's outer section iterator at parent EBP-58.
__declspec(naked) void UnwindConfigFileWriteSectionIterator()
{
  __asm {
    lea ecx, [ebp-58h]
    jmp NativeEntry_TMapBase_FString_FConfigSection_TIterator_DestroyTIterator
  }
}

// RavenShield.exe @ 10912cb1 : UnwindConfigFileWriteSectionText
// Destroy the completed section-header format temporary at parent EBP-30.
__declspec(naked) void UnwindConfigFileWriteSectionText()
{
  __asm {
    lea ecx, [ebp-30h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912cba : UnwindConfigFileWriteEntryIterator
// Destroy the writer's inner key/value iterator at parent EBP-68.
__declspec(naked) void UnwindConfigFileWriteEntryIterator()
{
  __asm {
    lea ecx, [ebp-68h]
    jmp NativeEntry_TMapBase_FString_FString_TIterator_DestroyTIterator
  }
}

// RavenShield.exe @ 10912cc2 : UnwindConfigFileWriteEntryText
// Destroy the completed key/value-line format temporary at parent EBP-3c.
__declspec(naked) void UnwindConfigFileWriteEntryText()
{
  __asm {
    lea ecx, [ebp-3ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912ccb : UnwindConfigFileWriteSectionBreak
// Destroy the completed blank-line format temporary at parent EBP-48.
__declspec(naked) void UnwindConfigFileWriteSectionBreak()
{
  __asm {
    lea ecx, [ebp-48h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091a92c : g_configFileWriteUnwind
const NativeCppUnwindEntry g_configFileWriteUnwind[8] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigFileWriteText)},            // UnwindConfigFileWriteText
    {1, NativeAddress(NativeEntry_UnwindConfigFileWriteSectionIterator)}, // UnwindConfigFileWriteSectionIterator
    {2, NativeAddress(NativeEntry_UnwindConfigFileWriteSectionText)},     // UnwindConfigFileWriteSectionText
    {2, NativeAddress(NativeEntry_UnwindConfigFileWriteEntryIterator)},   // UnwindConfigFileWriteEntryIterator
    {4, NativeAddress(NativeEntry_UnwindConfigFileWriteEntryText)},       // UnwindConfigFileWriteEntryText
    {2, NativeAddress(NativeEntry_UnwindConfigFileWriteSectionBreak)},    // UnwindConfigFileWriteSectionBreak
    {-1, 0},
};

// RavenShield.exe data @ 1091a96c : g_configFileWriteCatches
const NativeCppCatchHandler g_configFileWriteCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x18, 0x1090f5f5}, // RethrowConfigFileWritePointer
    {0, 0, 0, 0x1090f609},                                               // UnwindConfigFileWriteFailure
};

// RavenShield.exe data @ 1091a98c : g_configFileWriteTryBlocks
const NativeCppTryBlock g_configFileWriteTryBlocks[1] = {
    {0, 6, 7, 2, NativeAddress(g_configFileWriteCatches)},
};

// RavenShield.exe data @ 1091a9a0 : g_configFileWriteExceptionInfo
const NativeCppFunctionInfo g_configFileWriteExceptionInfo = {
    0x19930520, 8, NativeAddress(g_configFileWriteUnwind), 1, NativeAddress(g_configFileWriteTryBlocks), 0, 0};

// RavenShield.exe @ 10912cd4 : HandleConfigFileWriteException
// Supply the writer's eight-state local cleanup and typed/catch-all guard metadata.
__declspec(naked) void HandleConfigFileWriteException()
{
  __asm {
    mov eax, offset g_configFileWriteExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10910300 : FConfigFile::FConfigFile
// Build the section map first, then clear Dirty and NoSave; failed hash construction unwinds only its pair array.
FConfigFile::FConfigFile() : TMap<FString, FConfigSection>(), Dirty(0), NoSave(0)
{
  // The inlined map constructor shares handler 10912da8 with map destruction and file copy construction.
}

// RavenShield.exe @ 109103e0 : FConfigFile::operator=
// Assign the section pairs, copy/rebuild the hash, then copy Dirty/NoSave; rehashing also occurs on self-assignment.
FConfigFile &FConfigFile::operator=(const FConfigFile &other)
{
  using SectionMap = TMapBase<FString, FConfigSection>;
  auto *destination = reinterpret_cast<SectionMap *>(this);
  const auto *source = reinterpret_cast<const SectionMap *>(&other);
  destination->Pairs = source->Pairs; // Native specialized array assignment 10910410 handles its own self-test.
  destination->HashCount = source->HashCount;
  destination->Rehash();
  Dirty = other.Dirty;
  NoSave = other.NoSave;
  return *this;
}

// RavenShield.exe @ 109105f0 : FConfigFile::FConfigFile
// Copy the section array and rebuild a separate hash before copying Dirty and NoSave.
FConfigFile::FConfigFile(const FConfigFile &other)
    : TMap<FString, FConfigSection>(other), Dirty(other.Dirty), NoSave(other.NoSave)
{
  // Rehash failure destroys completed section pairs through the shared map-construction handler 10912da8.
}

extern int32_t __cdecl appLoadFileToString(FString &text, const uint16_t *filename, FFileManager *fileManager);
extern int32_t __cdecl appStrlen(const uint16_t *text);
extern uint16_t *__cdecl appStrstr(const uint16_t *text, const uint16_t *substring);

// RavenShield.exe data @ 10917e34 : g_configFileReadGuardName
const char16_t g_configFileReadGuardName[] = u"FConfigFile::Read";
// RavenShield.exe data @ 10917e58 : g_configEntrySeparator
const char16_t g_configEntrySeparator[] = u"=";

// RavenShield.exe @ 1090fc00 : FConfigFile::Read
// Replace sections before loading; split lines in place, reuse repeated sections, and append every key/value pair.
void FConfigFile::Read(const uint16_t *filename)
{
  try
  {
    using SectionMap = TMapBase<FString, FConfigSection>;
    using EntryMap = TMapBase<FString, FString>;
    auto *sections = reinterpret_cast<SectionMap *>(this);
    sections->Empty(); // Dirty and NoSave are retained, including load failure or an exception.
    FString text;
    if (appLoadFileToString(text, filename, GFileManager) != 0)
    {
      uint16_t *cursor = const_cast<uint16_t *>(*text);
      FConfigSection *currentSection = nullptr;
      int32_t done = 0;
      while (done == 0)
      {
        while (*cursor == '\r' || *cursor == '\n') ++cursor;
        uint16_t *line = cursor;
        while (*cursor != 0 && *cursor != '\r' && *cursor != '\n') ++cursor;
        if (*cursor == 0) done = 1;
        *cursor++ = 0; // The final NUL line is processed before Done ends the loop.
        if (*line == '[' && line[appStrlen(line) - 1] == ']')
        {
          uint16_t *sectionName = line + 1;
          sectionName[appStrlen(sectionName) - 1] = 0;
          {
            FString key(sectionName);
            currentSection = sections->Find(key);
          }
          if (currentSection == nullptr)
          {
            FConfigSection emptySection;
            currentSection = &sections->Set(sectionName, emptySection);
          }
        }
        else if (currentSection != nullptr && *line != 0)
        {
          uint16_t *separator = appStrstr(line, reinterpret_cast<const uint16_t *>(g_configEntrySeparator));
          if (separator != nullptr)
          {
            *separator = 0;
            uint16_t *value = separator + 1;
            if (*value == '"' && value[appStrlen(value) - 1] == '"')
            {
              ++value;
              value[appStrlen(value) - 1] = 0;
            }
            reinterpret_cast<EntryMap *>(currentSection)->Add(line, value);
          }
        }
      }
    }
  }
  // RavenShield.exe @ 1090fe52 : RethrowConfigFileReadPointer
  // Copy-throw the caught unsigned-short pointer from EBP-20 into the new throw object at EBP-1c.
  catch (uint16_t *error)
  {
    throw error;
  }
  // RavenShield.exe @ 1090fe66 : UnwindConfigFileReadFailure
  // Append the Read guard after local cleanup and rethrow the active exception.
  catch (...)
  {
    appUnwindf(reinterpret_cast<const uint16_t *>(g_unwindContextFormat),
               reinterpret_cast<const uint16_t *>(g_configFileReadGuardName));
    throw;
  }
}

// RavenShield.exe @ 10912d20 : UnwindConfigFileReadText
// Destroy the completed input FString at parent EBP-2c.
__declspec(naked) void UnwindConfigFileReadText()
{
  __asm {
    lea ecx, [ebp-2ch]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912d29 : UnwindConfigFileReadSectionKey
// Destroy the completed section-key FString at parent EBP-38.
__declspec(naked) void UnwindConfigFileReadSectionKey()
{
  __asm {
    lea ecx, [ebp-38h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe @ 10912d32 : UnwindConfigFileReadPartialSectionPairs
// Destroy only the completed temporary entry array if initial hash construction fails.
__declspec(naked) void UnwindConfigFileReadPartialSectionPairs()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray
  }
}

// RavenShield.exe @ 10912d3a : UnwindConfigFileReadSection
// Destroy the completed temporary section through its canonical map forwarding thunk.
__declspec(naked) void UnwindConfigFileReadSection()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp NativeEntry_ForwardFStringMapDestruction
  }
}

// RavenShield.exe @ 10912d42 : UnwindConfigFileReadSectionPairs
// Destroy the temporary entry array if freeing its completed hash throws.
__declspec(naked) void UnwindConfigFileReadSectionPairs()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray
  }
}

// RavenShield.exe @ 10912d4a : UnwindConfigFileReadSectionArrayBase
// Free the temporary raw FArray base if destroying one of its pairs throws.
__declspec(naked) void UnwindConfigFileReadSectionArrayBase()
{
  __asm {
    lea ecx, [ebp-4ch]
    jmp dword ptr [NativeImport_FArrayDestroy]
  }
}

// RavenShield.exe data @ 1091aa94 : g_configFileReadUnwind
const NativeCppUnwindEntry g_configFileReadUnwind[8] = {
    {-1, 0},
    {0, NativeAddress(NativeEntry_UnwindConfigFileReadText)},                // UnwindConfigFileReadText
    {1, NativeAddress(NativeEntry_UnwindConfigFileReadSectionKey)},          // UnwindConfigFileReadSectionKey
    {1, NativeAddress(NativeEntry_UnwindConfigFileReadPartialSectionPairs)}, // UnwindConfigFileReadPartialSectionPairs
    {1, NativeAddress(NativeEntry_UnwindConfigFileReadSection)},             // UnwindConfigFileReadSection
    {1, NativeAddress(NativeEntry_UnwindConfigFileReadSectionPairs)},        // UnwindConfigFileReadSectionPairs
    {1, NativeAddress(NativeEntry_UnwindConfigFileReadSectionArrayBase)},    // UnwindConfigFileReadSectionArrayBase
    {-1, 0},
};

// RavenShield.exe data @ 1091aad4 : g_configFileReadCatches
const NativeCppCatchHandler g_configFileReadCatches[2] = {
    {0, NativeAddress(g_utf16PointerTypeDescriptor), -0x20, 0x1090fe52}, // RethrowConfigFileReadPointer
    {0, 0, 0, 0x1090fe66},                                               // UnwindConfigFileReadFailure
};

// RavenShield.exe data @ 1091aaf4 : g_configFileReadTryBlocks
const NativeCppTryBlock g_configFileReadTryBlocks[1] = {
    {0, 6, 7, 2, NativeAddress(g_configFileReadCatches)},
};

// RavenShield.exe data @ 1091ab08 : g_configFileReadExceptionInfo
const NativeCppFunctionInfo g_configFileReadExceptionInfo = {
    0x19930520, 8, NativeAddress(g_configFileReadUnwind), 1, NativeAddress(g_configFileReadTryBlocks), 0, 0};

// RavenShield.exe @ 10912d53 : HandleConfigFileReadException
// Supply eight states for input/key strings and the temporary section's construction/destruction, plus both catches.
__declspec(naked) void HandleConfigFileReadException()
{
  __asm {
    mov eax, offset g_configFileReadExceptionInfo
    jmp DispatchExecutableCppException
  }
}
