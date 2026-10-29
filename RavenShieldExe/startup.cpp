// Reference reconstructions for startup helpers and the protected PE entry sequence.
#include <cstdint>

using byte = uint8_t;
using ushort = uint16_t;
using uint = uint32_t;

// RavenShield.exe @ 10942000 : FrameOnlyReturn_10942000
// Sets up and restores EBP, then returns with registers and flags preserved.
__declspec(naked) void FrameOnlyReturn_10942000()
{
  __asm {
    push ebp
    mov ebp, esp
    pop ebp
    ret
  }
}

// RavenShield.exe @ 10942005 : FindExportByName
// Locate a named PE export by validating headers, matching names case-insensitively, and
// translating the matching ordinal through the export address table.
uint32_t __cdecl FindExportByName(uint8_t *image, const char *name) {
  auto *dos = reinterpret_cast<uint16_t *>(image);
  if (*dos != 0x5a4d) return 0;
  auto *nt = reinterpret_cast<uint8_t *>(image + *reinterpret_cast<uint32_t *>(image + 0x3c));
  if (*reinterpret_cast<uint32_t *>(nt) != 0x4550 ||
      *reinterpret_cast<uint16_t *>(nt + 4) != 0x14c ||
      *reinterpret_cast<uint16_t *>(nt + 0x14) != 0xe0) return 0;
  auto *directory = nt + 0x78;
  if (*reinterpret_cast<uint32_t *>(directory + 4) == 0) return 0;
  uint32_t export_rva = *reinterpret_cast<uint32_t *>(directory);
  auto *exports = reinterpret_cast<uint8_t *>(image + export_rva);
  uint32_t name_count = *reinterpret_cast<uint32_t *>(exports + 0x18);
  uint32_t function_count = *reinterpret_cast<uint32_t *>(exports + 0x14);
  if (name_count == 0 || function_count == 0) return 0;
  uint32_t *name_rvas = reinterpret_cast<uint32_t *>(image + *reinterpret_cast<uint32_t *>(exports + 0x20));
  uint16_t *ordinals = reinterpret_cast<uint16_t *>(image + *reinterpret_cast<uint32_t *>(exports + 0x24));
  int ordinal = -1;
  for (uint32_t i = 0; i < name_count; ++i) {
    const auto *candidate = reinterpret_cast<const char *>(image + name_rvas[i]);
    const auto *wanted = name;
    bool mismatch = false;
    while (*candidate && *wanted) {
      auto a = static_cast<unsigned char>(*candidate++);
      auto b = static_cast<unsigned char>(*wanted++);
      if (a >= 'A' && a <= 'Z') a |= 0x20;
      if (b >= 'A' && b <= 'Z') b |= 0x20;
      if (a != b) { mismatch = true; break; }
    }
    if (!mismatch && *candidate == *wanted) { ordinal = ordinals[i]; break; }
  }
  // Native permits ordinal == function_count and adds the base even for a zero function RVA.
  if (ordinal < 0 || static_cast<uint32_t>(ordinal) > function_count) return 0;
  uint32_t function_rva = reinterpret_cast<uint32_t *>(image + *reinterpret_cast<uint32_t *>(exports + 0x1c))[ordinal];
  return reinterpret_cast<uint32_t>(image + function_rva);
}

// RavenShield.exe @ 10942201 : FormatUnsignedDecimal10
// Write a 32-bit unsigned integer as ten decimal digits, including leading zeroes.
char *__stdcall FormatUnsignedDecimal10(uint32_t value, char *out) {
  uint32_t place = 1000000000;
  for (int i = 0; i < 10; ++i) {
    uint32_t digit = value / place;
    out[i] = static_cast<char>('0' + digit);
    value -= digit * place;
    place /= 10;
  }
  out[10] = '\0';
  return out;
}

// RavenShield.exe @ 10942266 : UpdateChecksumMsbFirst
// Update a byte-wise checksum using the observed MSB-first polynomial 0x488781ed.
uint32_t __stdcall UpdateChecksumMsbFirst(const uint8_t *data, int length, uint32_t crc) {
  for (int i = 0; i < length; ++i) {
    crc ^= static_cast<uint32_t>(data[i]) << 24;
    for (int bit = 0; bit < 8; ++bit)
      crc = (crc & 0x80000000u) ? (crc << 1) ^ 0x488781edu : crc << 1;
  }
  return crc;
}

// Decrypt complete eight-byte payload blocks with the embedded 32-round TEA variant.
// Each plaintext pair is XOR-chained with the preceding ciphertext pair, starting at 0x55555555.
// Source abstraction of the inline loop at 0x10942c31–0x10942e01, not a separate native function.
void DecryptStartupPayloadBlocks(uint32_t *outputWords, const uint32_t *encryptedWords,
                                 uint32_t byteCount, const uint32_t *key) {
  uint32_t previousLeft = 0x55555555;
  uint32_t previousRight = 0x55555555;
  for (uint32_t block = 0; block < (byteCount >> 3); ++block) {
    uint32_t left = encryptedWords[block * 2];
    uint32_t right = encryptedWords[block * 2 + 1];
    const uint32_t encryptedLeft = left;
    const uint32_t encryptedRight = right;
    uint32_t sum = 0xc6ef3720;
    for (uint32_t round = 0; round < 32; ++round) {
      right -= (((left << 4) ^ (left >> 5)) + left) ^
               (sum + key[(sum >> 11) & 3]);
      sum += 0x61c88647;
      left -= (((right << 4) ^ (right >> 5)) + right) ^ (sum + key[sum & 3]);
    }
    outputWords[block * 2] = left ^ previousLeft;
    outputWords[block * 2 + 1] = right ^ previousRight;
    previousLeft = encryptedLeft;
    previousRight = encryptedRight;
  }
}

// RavenShield.exe @ 109422db : PrepareOuterFrameAndJumpToEntry_109422db
// Reserves an outer stack frame, saves nonvolatile registers, and jumps to the selected entry.
__declspec(naked) void PrepareOuterFrameAndJumpToEntry_109422db()
{
  __asm {
    push ebp
    mov ebp, esp
    sub esp, 0x0d30
    push ebx
    push esi
    push edi
    jmp 0x109422ed
  }
}

// Read the current thread's TEB pointer from the native x86 FS slot.
uint32_t ReadCurrentTebPointer()
{
  uint32_t teb;
  __asm {
    mov eax, fs:[0x18]
    mov teb, eax
  }
  return teb;
}

// Map sections, relocate/import the payload, run process attach, find its export and erase copied headers.
// Source abstraction of the inline region 0x10942e14–0x10943799, not a separate native function.
static uint32_t MapStartupPayloadImage(uint32_t decryptedImage, const char *exportName, const uint32_t *apiSlots)
{
  using VirtualAllocCall = uint32_t (__stdcall *)(uint32_t, uint32_t, uint32_t, uint32_t);
  using VirtualFreeCall = int32_t (__stdcall *)(uint32_t, uint32_t, uint32_t);
  using VirtualProtectCall = int32_t (__stdcall *)(uint32_t, uint32_t, uint32_t, uint32_t *);
  using IsBadReadPtrCall = int32_t (__stdcall *)(uint32_t, uint32_t);
  using LoadLibraryExACall = uint32_t (__stdcall *)(uint32_t, uint32_t, uint32_t);
  using GetProcAddressCall = uint32_t (__stdcall *)(uint32_t, uint32_t);
  using ProcessAttachCall = int32_t (__stdcall *)(uint32_t, uint32_t, uint32_t);
  // Keep native 32-bit address arithmetic and little-endian PE word accesses explicit.
  auto dword = [](uint32_t address) -> uint32_t & { return *reinterpret_cast<uint32_t *>(address); };
  auto word = [](uint32_t address) -> uint16_t & { return *reinterpret_cast<uint16_t *>(address); };
  if (word(decryptedImage) != 0x5a4d) return 0;
  const uint32_t sourceNtHeaders = decryptedImage + dword(decryptedImage + 0x3c);
  if (dword(sourceNtHeaders) != 0x4550) return 0;
  uint32_t reservedImage = reinterpret_cast<VirtualAllocCall>(apiSlots[1])(
      dword(sourceNtHeaders + 0x34), dword(sourceNtHeaders + 0x50), 0x2000, 4);
  if (reservedImage == 0) {
    reservedImage = reinterpret_cast<VirtualAllocCall>(apiSlots[1])(0, dword(sourceNtHeaders + 0x50), 0x2000, 4);
  }
  if (reservedImage == 0) return 0;
  // Native EBP-0x580..-0x4f1 holds the attach byte, image/header addresses, count and 32 module handles.
  uint32_t mappingWords[0x24];
  auto *mappingBytes = reinterpret_cast<byte *>(mappingWords);
  for (uint32_t i = 0; i < 0x90; ++i) mappingBytes[i] = 0;
  auto &processAttachSucceeded = mappingBytes[0];
  auto &mappedImage = mappingWords[1];
  auto &mappedNtHeaders = mappingWords[2];
  auto &importedModuleCount = *reinterpret_cast<int32_t *>(&mappingWords[3]);
  auto *importedModuleHandles = &mappingWords[4];
  mappedImage = reservedImage;
  const uint32_t committedHeaders = reinterpret_cast<VirtualAllocCall>(apiSlots[1])(
      reservedImage, dword(sourceNtHeaders + 0x50), 0x1000, 4);
  const uint32_t headerCopyBytes = dword(decryptedImage + 0x3c) + dword(sourceNtHeaders + 0x54);
  for (uint32_t i = 0; i < headerCopyBytes; ++i) {
    *reinterpret_cast<byte *>(committedHeaders + i) = *reinterpret_cast<byte *>(decryptedImage + i);
  }
  mappedNtHeaders = committedHeaders + dword(decryptedImage + 0x3c);
  dword(mappedNtHeaders + 0x34) = reservedImage;
  uint32_t section = mappedNtHeaders + 0x18 + word(mappedNtHeaders + 0x14);
  for (int32_t i = 0; i < word(mappedNtHeaders + 6); ++i, section += 0x28) {
    if (dword(section + 0x10) == 0) {
      // Zero-raw-data sections use the source SectionAlignment, regardless of their VirtualSize.
      const uint32_t zeroFillBytes = dword(sourceNtHeaders + 0x38);
      if (zeroFillBytes != 0) {
        const uint32_t sectionAddress = reinterpret_cast<VirtualAllocCall>(apiSlots[1])(
            mappedImage + dword(section + 0x0c), zeroFillBytes, 0x1000, 4);
        dword(section + 8) = sectionAddress;
        for (uint32_t j = 0; j < zeroFillBytes; ++j) *reinterpret_cast<byte *>(sectionAddress + j) = 0;
      }
    } else {
      const uint32_t sectionAddress = reinterpret_cast<VirtualAllocCall>(apiSlots[1])(
          mappedImage + dword(section + 0x0c), dword(section + 0x10), 0x1000, 4);
      const uint32_t rawBytes = dword(section + 0x10);
      const uint32_t rawSource = decryptedImage + dword(section + 0x14);
      for (uint32_t j = 0; j < rawBytes; ++j) {
        *reinterpret_cast<byte *>(sectionAddress + j) = *reinterpret_cast<byte *>(rawSource + j);
      }
      dword(section + 8) = sectionAddress;
    }
  }
  const uint32_t imageBaseDelta = reservedImage - dword(sourceNtHeaders + 0x34);
  if (imageBaseDelta != 0 && dword(mappedNtHeaders + 0xa4) != 0) {
    uint32_t block = mappedImage + dword(mappedNtHeaders + 0xa0);
    while (dword(block) != 0) {
      const uint32_t relocationPage = mappedImage + dword(block);
      uint32_t entry = block + 8;
      for (uint32_t i = 0; i < ((dword(block + 4) - 8u) >> 1); ++i, entry += 2) {
        const uint32_t type = word(entry) >> 12;
        const uint32_t offset = word(entry) & 0xfff;
        if (type == 3) dword(relocationPage + offset) += imageBaseDelta;
      }
      block += dword(block + 4);
    }
  }
  if (dword(mappedNtHeaders + 0x84) != 0) {
    uint32_t descriptor = mappedImage + dword(mappedNtHeaders + 0x80);
    // An unreadable descriptor terminates the import list successfully in this native loader.
    while (reinterpret_cast<IsBadReadPtrCall>(apiSlots[11])(descriptor, 0x14) == 0 &&
           dword(descriptor + 0x0c) != 0) {
      const uint32_t moduleName = mappedImage + dword(descriptor + 0x0c);
      const uint32_t module = reinterpret_cast<LoadLibraryExACall>(apiSlots[5])(moduleName, 0, 0);
      if (module == 0) return 0;
      if (importedModuleCount >= 32) return 0;
      importedModuleHandles[importedModuleCount++] = module;
      uint32_t names = mappedImage + dword(descriptor);
      uint32_t addresses = mappedImage + dword(descriptor + 0x10);
      if (dword(descriptor) == 0) names = mappedImage + dword(descriptor + 0x10);
      while (dword(names) != 0) {
        if ((dword(names) & 0x80000000u) != 0) {
          dword(addresses) = reinterpret_cast<GetProcAddressCall>(apiSlots[6])(module, dword(names) & 0xffff);
        } else {
          const uint32_t hintAndName = mappedImage + dword(names);
          dword(addresses) = reinterpret_cast<GetProcAddressCall>(apiSlots[6])(module, hintAndName + 2);
        }
        if (dword(addresses) == 0) return 0;
        names += 4;
        addresses += 4;
      }
      descriptor += 0x14;
    }
  }
  section = mappedNtHeaders + 0x18 + word(mappedNtHeaders + 0x14);
  const uint32_t protectionByFlags[8] = {1, 8, 2, 4, 0x10, 0x80, 0x20, 0x40};
  for (int32_t i = 0; i < word(mappedNtHeaders + 6); ++i, section += 0x28) {
    const uint32_t executable = (dword(section + 0x24) & 0x20000000u) != 0;
    const uint32_t readable = (dword(section + 0x24) & 0x40000000u) != 0;
    const uint32_t writable = (dword(section + 0x24) & 0x80000000u) != 0;
    if ((dword(section + 0x24) & 0x02000000) != 0) {
      reinterpret_cast<VirtualFreeCall>(apiSlots[2])(dword(section + 8), dword(section + 0x10), 0x4000);
    } else {
      uint32_t protection = protectionByFlags[executable * 4 + readable * 2 + writable];
      if ((dword(section + 0x24) & 0x04000000) != 0) protection |= 0x200;
      uint32_t protectionSizeGate = dword(section + 0x10);
      if (protectionSizeGate == 0) {
        if ((dword(section + 0x24) & 0x40) != 0) protectionSizeGate = dword(mappedNtHeaders + 0x20);
        else if ((dword(section + 0x24) & 0x80) != 0) protectionSizeGate = dword(mappedNtHeaders + 0x24);
      }
      // The fallback size gates the call, but the actual size argument is still SizeOfRawData.
      if (protectionSizeGate != 0) {
        uint32_t previousProtection;
        reinterpret_cast<VirtualProtectCall>(apiSlots[3])(
            dword(section + 8), dword(section + 0x10), protection, &previousProtection);
      }
    }
  }
  if (dword(mappedNtHeaders + 0x28) != 0) {
    const uint32_t processAttach = reservedImage + dword(mappedNtHeaders + 0x28);
    if (processAttach == 0) return 0;
    if (reinterpret_cast<ProcessAttachCall>(processAttach)(reservedImage, 1, 0) == 0) return 0;
    processAttachSucceeded = 1;
  }
  const uint32_t payloadExport = FindExportByName(reinterpret_cast<byte *>(mappedImage), exportName);
  const uint32_t headerEraseBytes = dword(decryptedImage + 0x3c) + 0xf8;
  for (uint32_t i = 0; i < headerEraseBytes; ++i) *reinterpret_cast<byte *>(committedHeaders + i) = 0;
  return payloadExport;
}

// Publish a startup request through Steam's mapping, wait for its reply, and return an ASCII result code.
// Source abstraction of inline regions 0x109428be–0x10942a79 and 0x10943e54–0x1094400f.
static char ExchangeStartupMapping(const uint32_t *apiSlots, const byte *bootstrap, uint32_t requestCode)
{
  using OpenNamedObjectCall = uint32_t (__stdcall *)(uint32_t, int32_t, const char *);
  using WaitForSingleObjectCall = uint32_t (__stdcall *)(uint32_t, uint32_t);
  using MapViewOfFileCall = uint32_t (__stdcall *)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
  using CreateEventCall = uint32_t (__stdcall *)(uint32_t, int32_t, int32_t, uint32_t);
  using GetCurrentProcessIdCall = uint32_t (__stdcall *)();
  using ReleaseObjectCall = int32_t (__stdcall *)(uint32_t);
  auto dword = [](const byte *address) -> uint32_t { return *reinterpret_cast<const uint32_t *>(address); };
  const uint32_t startupEvent = reinterpret_cast<OpenNamedObjectCall>(apiSlots[15])(
      0x100000, 0, reinterpret_cast<const char *>(bootstrap + 0x2c0));
  const uint32_t mapping = reinterpret_cast<OpenNamedObjectCall>(apiSlots[16])(
      2, 0, reinterpret_cast<const char *>(bootstrap + 0x2a0));
  // Native early failures leave any opened handles and mapped view unreleased.
  if (startupEvent == 0 || mapping == 0) return '5';
  if (reinterpret_cast<WaitForSingleObjectCall>(apiSlots[22])(startupEvent, 5000) != 0) return 'G';
  const uint32_t view = reinterpret_cast<MapViewOfFileCall>(apiSlots[17])(mapping, 2, 0, 0, 0);
  if (view == 0) return 'H';
  auto *sharedWords = reinterpret_cast<volatile uint32_t *>(view);
  if (sharedWords[0x90 / 4] != 2) return 'I';
  if (sharedWords[0x94 / 4] != 0) return 'J';
  const uint32_t replyEvent = reinterpret_cast<CreateEventCall>(apiSlots[23])(0, 0, 0, 0);
  sharedWords[0x98 / 4] = reinterpret_cast<GetCurrentProcessIdCall>(apiSlots[20])();
  sharedWords[0xa0 / 4] = dword(bootstrap + 0x28);
  sharedWords[0xa4 / 4] = dword(bootstrap + 0x1c);
  sharedWords[0xac / 4] = dword(bootstrap + 0x20);
  sharedWords[0xa8 / 4] = static_cast<int32_t>(*reinterpret_cast<const int8_t *>(bootstrap + 0x30));
  sharedWords[0x9c / 4] = replyEvent;
  sharedWords[0x94 / 4] = requestCode;
  const uint32_t replyWait = reinterpret_cast<WaitForSingleObjectCall>(apiSlots[22])(replyEvent, 5000);
  reinterpret_cast<ReleaseObjectCall>(apiSlots[18])(view);
  reinterpret_cast<ReleaseObjectCall>(apiSlots[19])(mapping);
  reinterpret_cast<ReleaseObjectCall>(apiSlots[19])(startupEvent);
  reinterpret_cast<ReleaseObjectCall>(apiSlots[19])(replyEvent);
  return replyWait == 0 ? '0' : 'L';
}

// Search parent directories for steam.exe and forward the application's ID and remaining command line.
// Source abstraction of the inline shell fallback at 0x10943948–0x10943e1f.
static bool LaunchSteamFallback(const uint32_t *apiSlots, const byte *bootstrap,
                               char *modulePath, char *steamPath, char *arguments)
{
  using GetModuleFileNameCall = uint32_t (__stdcall *)(uint32_t, char *, uint32_t);
  using GetFileAttributesCall = uint32_t (__stdcall *)(const char *);
  using LoadLibraryExCall = uint32_t (__stdcall *)(const char *, uint32_t, uint32_t);
  using GetProcAddressCall = uint32_t (__stdcall *)(uint32_t, const char *);
  using GetCommandLineCall = const char *(__stdcall *)();
  using ShellExecuteCall = uint32_t (__stdcall *)(uint32_t, const char *, const char *, const char *, const char *, int32_t);
  // The five native concatenations scan for NUL and copy without a capacity argument.
  auto append = [](char *destination, const char *source) {
    while (*destination != '\0') ++destination;
    while (*source != '\0') *destination++ = *source++;
    *destination = '\0';
  };
  modulePath[0] = '\0';
  steamPath[0] = '\0';
  if (reinterpret_cast<GetModuleFileNameCall>(apiSlots[8])(0, modulePath, 260) == 0) return false;
  for (;;) {
    bool foundParent = false;
    if (modulePath != nullptr && modulePath[0] != '\0') {
      uint32_t pathLength = 0;
      while (modulePath[pathLength] != '\0') ++pathLength;
      if (modulePath[pathLength - 1] == '\\') --pathLength;
      while (static_cast<int32_t>(pathLength) > 0) {
        if (modulePath[pathLength - 1] == '\\') {
          modulePath[pathLength] = '\0';
          foundParent = true;
          break;
        }
        --pathLength;
      }
    }
    if (!foundParent) break;
    append(steamPath, modulePath);
    append(steamPath, reinterpret_cast<const char *>(bootstrap + 0x2e8));
    if (reinterpret_cast<GetFileAttributesCall>(apiSlots[25])(steamPath) != 0xffffffff) break;
    steamPath[0] = '\0';
  }
  if (steamPath[0] == '\0') return false;
  const uint32_t shell32Module = reinterpret_cast<LoadLibraryExCall>(apiSlots[5])(
      reinterpret_cast<const char *>(bootstrap + 0x64), 0, 0);
  const uint32_t shellExecute = reinterpret_cast<GetProcAddressCall>(apiSlots[6])(
      shell32Module, reinterpret_cast<const char *>(bootstrap + 0x26c));
  if (shellExecute == 0) return false;
  arguments[0] = '\0';
  append(arguments, reinterpret_cast<const char *>(bootstrap + 0x330));
  append(arguments, reinterpret_cast<const char *>(bootstrap + 0x31));
  const char *commandLine = reinterpret_cast<GetCommandLineCall>(apiSlots[24])();
  if (commandLine != nullptr && commandLine[0] != '\0') {
    uint32_t argumentOffset = 0;
    if (commandLine[0] == '"') {
      argumentOffset = 1;
      while (commandLine[argumentOffset] != '\0' && commandLine[argumentOffset] != '"') ++argumentOffset;
      if (commandLine[argumentOffset] != '\0') ++argumentOffset;
    }
    while (commandLine[argumentOffset] != '\0' && commandLine[argumentOffset] != ' ') ++argumentOffset;
    if (commandLine[argumentOffset] == ' ') append(arguments, commandLine + argumentOffset);
  }
  return reinterpret_cast<ShellExecuteCall>(shellExecute)(0, nullptr, steamPath, arguments, nullptr, 1) > 32u;
}

// Source-only bridge metadata; these six words are outside the native frame and are not game fields.
struct StartupEntryOutcome {
  uint32_t jumpTarget;
  uint32_t nativeEsp;
  uint32_t returnedEax;
  uint32_t returnedEcx;
  uint32_t returnedEdx;
  uint32_t capturedFlags;
};

// Decode startup data, load the payload or report failure, and describe the native exit to the frame bridge.
// Source abstraction of 0x109422fb–0x109441a6; nativeFrame is the entry's saved-register EBP, not a native argument.
static void __cdecl RunProtectedStartupBody(uint32_t nativeFrame, StartupEntryOutcome *outcome)
{
  uint32_t nativeEsp = nativeFrame - 0x1000;
  auto &modulePathBuffer = *reinterpret_cast<char (*)[260]>(nativeFrame - 0xcb4);
  auto &parentExecutablePath = *reinterpret_cast<char (*)[260]>(nativeFrame - 0xbac);
  auto &shellArguments = *reinterpret_cast<char (*)[1024]>(nativeFrame - 0xaa4);
  auto &exitProcessCallback = *reinterpret_cast<uint32_t *>(nativeFrame - 0x40c);
  auto &savedErrorMessage = *reinterpret_cast<char (*)[40]>(nativeFrame - 0x400);
  auto &decryptedBootstrapWords = *reinterpret_cast<uint32_t (*)[0xd0]>(nativeFrame - 0x3c8);
  // Fields alias the decoded 0x340-byte block at native EBP-0x3c8.
  auto *bootstrapBytes = reinterpret_cast<byte *>(decryptedBootstrapWords);
  auto &getModuleHandleImportSlot = *reinterpret_cast<uint32_t **>(bootstrapBytes + 0x004);
  auto &getProcAddressImportSlot = *reinterpret_cast<uint32_t **>(bootstrapBytes + 0x008);
  auto &loadLibraryImportSlot = *reinterpret_cast<uint32_t **>(bootstrapBytes + 0x00c);
  auto &fallbackExportLookup = *reinterpret_cast<uint32_t *>(bootstrapBytes + 0x010);
  auto &checksumData = *reinterpret_cast<int *>(bootstrapBytes + 0x014);
  auto &checksumLength = *reinterpret_cast<int *>(bootstrapBytes + 0x018);
  auto &embeddedChecksum = *reinterpret_cast<uint *>(bootstrapBytes + 0x01c);
  auto &startupBlob = *reinterpret_cast<uint **>(bootstrapBytes + 0x020);
  auto &startupBlobSize = *reinterpret_cast<uint *>(bootstrapBytes + 0x024);
  auto &applicationId = *reinterpret_cast<uint32_t *>(bootstrapBytes + 0x028);
  auto &startupErrorCode = *reinterpret_cast<int *>(bootstrapBytes + 0x02c);
  auto &statusCode = *reinterpret_cast<char *>(bootstrapBytes + 0x030);
  auto &applicationIdText = *reinterpret_cast<char (*)[7]>(bootstrapBytes + 0x031);
  auto &payloadPointerFieldOffset = *reinterpret_cast<int *>(bootstrapBytes + 0x038);
  auto &payloadSizeFieldOffset = *reinterpret_cast<uint *>(bootstrapBytes + 0x03c);
  auto &payloadKeyOffset = *reinterpret_cast<int *>(bootstrapBytes + 0x040);
  auto &kernel32ModuleName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x044);
  auto &user32ModuleName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x054);
  auto &shell32ModuleName = *reinterpret_cast<char (*)[80]>(bootstrapBytes + 0x064);
  auto &loadLibraryExAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x0b4);
  auto &messageBoxAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x0c4);
  auto &getModuleFileNameAName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x0d4);
  auto &getModuleHandleAName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x0ec);
  auto &virtualProtectName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x104);
  auto &virtualQueryName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x114);
  auto &outputDebugStringAName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x124);
  auto &getLastErrorName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x13c);
  auto &exitProcessName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x14c);
  auto &virtualAllocName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x15c);
  auto &virtualFreeName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x16c);
  auto &getProcAddressName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x17c);
  auto &isBadReadPtrName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x18c);
  auto &getProcessHeapName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x19c);
  auto &heapAllocName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x1ac);
  auto &heapFreeName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x1bc);
  auto &openEventAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x1cc);
  auto &openFileMappingAName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x1dc);
  auto &mapViewOfFileName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x1f4);
  auto &unmapViewOfFileName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x204);
  auto &closeHandleName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x214);
  auto &getCurrentProcessIdName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x224);
  auto &sleepName = *reinterpret_cast<char (*)[8]>(bootstrapBytes + 0x23c);
  auto &waitForSingleObjectName = *reinterpret_cast<char (*)[24]>(bootstrapBytes + 0x244);
  auto &createEventAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x25c);
  auto &shellExecuteAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x26c);
  auto &getCommandLineAName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x27c);
  auto &getFileAttributesAName = *reinterpret_cast<char (*)[20]>(bootstrapBytes + 0x28c);
  auto &startupMappingName = *reinterpret_cast<char (*)[32]>(bootstrapBytes + 0x2a0);
  auto &startupEventName = *reinterpret_cast<char (*)[32]>(bootstrapBytes + 0x2c0);
  auto &exportName = *reinterpret_cast<byte (*)[8]>(bootstrapBytes + 0x2e0);
  auto &steamExecutableName = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x2e8);
  auto &errorCaptionTemplate = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x2f8);
  auto &errorMessageTemplate = *reinterpret_cast<char (*)[40]>(bootstrapBytes + 0x308);
  auto &steamLaunchPrefix = *reinterpret_cast<char (*)[16]>(bootstrapBytes + 0x330);
  auto &savedErrorCaption = *reinterpret_cast<char (*)[16]>(nativeFrame - 0x80);
  auto &resolvedApiTable = *reinterpret_cast<uint32_t (*)[26]>(nativeFrame - 0x70);
  // The resolver slots share the native zeroed/wiped 0x68-byte API block at EBP-0x70.
  auto &virtualQuery = resolvedApiTable[4];
  auto &loadLibraryExA = resolvedApiTable[5];
  auto &getProcAddress = resolvedApiTable[6];
  auto &getModuleHandleA = resolvedApiTable[7];
  auto &getModuleFileNameA = resolvedApiTable[8];
  auto &outputDebugStringA = resolvedApiTable[9];
  auto &getLastError = resolvedApiTable[10];
  auto &isBadReadPtr = resolvedApiTable[11];
  auto &getProcessHeap = resolvedApiTable[12];
  auto &heapAlloc = resolvedApiTable[13];
  auto &heapFree = resolvedApiTable[14];
  auto &openEventA = resolvedApiTable[15];
  auto &openFileMappingA = resolvedApiTable[16];
  auto &mapViewOfFile = resolvedApiTable[17];
  auto &unmapViewOfFile = resolvedApiTable[18];
  auto &closeHandle = resolvedApiTable[19];
  auto &getCurrentProcessId = resolvedApiTable[20];
  auto &sleepMilliseconds = resolvedApiTable[21];
  auto &waitForSingleObject = resolvedApiTable[22];
  auto &createEventA = resolvedApiTable[23];
  auto &getCommandLineA = resolvedApiTable[24];
  auto &getFileAttributesA = resolvedApiTable[25];

  uint32_t encodedWordAddress = 0x109441ac;
  uint32_t decodedWordAddress = reinterpret_cast<uint32_t>(bootstrapBytes);
  const uint32_t copyStep = (outcome->capturedFlags & 0x400) != 0 ? 0xfffffffcu : 4;
  // REP MOVSD honors the incoming direction flag; the later XOR loop always advances forward.
  for (uint32_t i = 0; i < 0xd0; ++i) {
    *reinterpret_cast<uint32_t *>(decodedWordAddress) = *reinterpret_cast<const uint32_t *>(encodedWordAddress);
    encodedWordAddress += copyStep;
    decodedWordAddress += copyStep;
  }
  uint32_t rollingXorKey = 0xc73d5294;
  for (uint32_t i = 0; i < 0xd0; ++i) {
    const uint32_t encodedWord = decryptedBootstrapWords[i];
    decryptedBootstrapWords[i] ^= rollingXorKey;
    rollingXorKey = encodedWord;
  }
  for (uint32_t i = 0; i < 0x10; ++i) savedErrorCaption[i] = errorCaptionTemplate[i];
  for (uint32_t i = 0; i < 0x28; ++i) savedErrorMessage[i] = errorMessageTemplate[i];
  const uint32_t storedChecksum = embeddedChecksum;
  embeddedChecksum = 0;
  uint32_t computedChecksum = UpdateChecksumMsbFirst(reinterpret_cast<const byte *>(checksumData), checksumLength, 0);
  computedChecksum = UpdateChecksumMsbFirst(bootstrapBytes, 0x340, computedChecksum);
  if (computedChecksum != storedChecksum) statusCode = '1';
  embeddedChecksum = storedChecksum;
  for (uint32_t i = 0; i < 0x68; ++i) reinterpret_cast<byte *>(resolvedApiTable)[i] = 0;
  using ModuleResolverCall = uint32_t (__stdcall *)(const char *);
  using GetProcAddressCall = uint32_t (__stdcall *)(uint32_t, const char *);
  if (getModuleHandleImportSlot == nullptr) {
    resolvedApiTable[0] = reinterpret_cast<ModuleResolverCall>(*loadLibraryImportSlot)(kernel32ModuleName);
  } else {
    resolvedApiTable[0] = reinterpret_cast<ModuleResolverCall>(*getModuleHandleImportSlot)(kernel32ModuleName);
  }
  if (getProcAddressImportSlot == nullptr) {
    const uint32_t nameArgument = reinterpret_cast<uint32_t>(getProcAddressName);
    const uint32_t moduleArgument = resolvedApiTable[0];
    const uint32_t walkerTarget = fallbackExportLookup;
    // Mirror the native argument/return words; measure cleanup without imposing a C++ calling convention.
    *reinterpret_cast<uint32_t *>(nativeEsp - 4) = nameArgument;
    *reinterpret_cast<uint32_t *>(nativeEsp - 8) = moduleArgument;
    *reinterpret_cast<uint32_t *>(nativeEsp - 12) = 0x10942554;
    uint32_t hostEspBefore, hostEspAfter, resolvedAddress;
    __asm {
      mov hostEspBefore, esp
      push nameArgument
      push moduleArgument
      call walkerTarget
      mov resolvedAddress, eax
      mov hostEspAfter, esp
      mov esp, hostEspBefore
    }
    nativeEsp += hostEspAfter - hostEspBefore;
    getProcAddress = resolvedAddress;
  } else {
    getProcAddress = *getProcAddressImportSlot;
  }
  exitProcessCallback = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], exitProcessName);
  resolvedApiTable[1] = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], virtualAllocName);
  resolvedApiTable[2] = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], virtualFreeName);
  resolvedApiTable[3] = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], virtualProtectName);
  virtualQuery = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], virtualQueryName);
  loadLibraryExA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], loadLibraryExAName);
  getModuleHandleA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getModuleHandleAName);
  getModuleFileNameA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getModuleFileNameAName);
  outputDebugStringA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], outputDebugStringAName);
  getLastError = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getLastErrorName);
  isBadReadPtr = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], isBadReadPtrName);
  getProcessHeap = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getProcessHeapName);
  heapAlloc = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], heapAllocName);
  heapFree = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], heapFreeName);
  openEventA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], openEventAName);
  openFileMappingA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], openFileMappingAName);
  mapViewOfFile = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], mapViewOfFileName);
  unmapViewOfFile = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], unmapViewOfFileName);
  closeHandle = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], closeHandleName);
  getCurrentProcessId = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getCurrentProcessIdName);
  sleepMilliseconds = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], sleepName);
  waitForSingleObject = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], waitForSingleObjectName);
  createEventA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], createEventAName);
  getCommandLineA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getCommandLineAName);
  getFileAttributesA = reinterpret_cast<GetProcAddressCall>(getProcAddress)(resolvedApiTable[0], getFileAttributesAName);
  const bool requiredApisPresent =
      resolvedApiTable[1] && resolvedApiTable[2] && resolvedApiTable[3] && virtualQuery && loadLibraryExA &&
      getModuleHandleA && waitForSingleObject && outputDebugStringA && getLastError && isBadReadPtr && getCurrentProcessId &&
      getProcessHeap && heapAlloc && heapFree && closeHandle && sleepMilliseconds && openEventA && openFileMappingA &&
      mapViewOfFile && unmapViewOfFile && createEventA && getCommandLineA && getFileAttributesA &&
      getModuleFileNameA;
  if (requiredApisPresent) {
    using GetCommandLineCall = const char *(__stdcall *)();
    reinterpret_cast<GetCommandLineCall>(getCommandLineA)();
    const char *commandLineCursor = reinterpret_cast<GetCommandLineCall>(getCommandLineA)();
    char commandLineStatus = '0';
    for (; *commandLineCursor != '\0'; ++commandLineCursor) {
      // Native reads a full dword at each byte and takes byte +5 after the literal "-drm".
      if (*reinterpret_cast<const uint32_t *>(commandLineCursor) == 0x6d72642d) {
        commandLineStatus = commandLineCursor[5];
        break;
      }
    }
    statusCode = commandLineStatus;
    if (commandLineStatus == '0') {
      const uint32_t currentTeb = ReadCurrentTebPointer();
      const bool tebRejected = currentTeb == 0 ||
          *reinterpret_cast<const uint32_t *>(currentTeb + 0x18) != currentTeb ||
          *reinterpret_cast<const uint32_t *>(currentTeb + 0x30) == 0 ||
          *reinterpret_cast<const byte *>(*reinterpret_cast<const uint32_t *>(currentTeb + 0x30) + 2) != 0;
      if (!tebRejected) {
        if (*startupBlob == embeddedChecksum) {
begin_payload_processing:
          {
            using GetProcessHeapCall = uint32_t (__stdcall *)();
            using HeapAllocCall = uint32_t (__stdcall *)(uint32_t, uint32_t, uint32_t);
            using HeapFreeCall = int32_t (__stdcall *)(uint32_t, uint32_t, uint32_t);
            // The native caller supplies two words and performs no cleanup after the export call.
            using PayloadExportCall = uint32_t (__stdcall *)(uint32_t, uint32_t);
            auto *apiSlots = reinterpret_cast<uint32_t *>(resolvedApiTable);
            const uint32_t blobCopyBytes = startupBlobSize;
            uint32_t processHeap = reinterpret_cast<GetProcessHeapCall>(apiSlots[12])();
            auto *copiedBlob = reinterpret_cast<uint32_t *>(
                reinterpret_cast<HeapAllocCall>(apiSlots[13])(processHeap, 0, blobCopyBytes));
            for (uint32_t i = 0; i < blobCopyBytes; ++i) {
              reinterpret_cast<byte *>(copiedBlob)[i] = reinterpret_cast<byte *>(startupBlob)[i];
            }
            // Leave the first checksum word intact; decode only complete subsequent words.
            uint32_t blobXorKey = embeddedChecksum;
            auto *encodedWord = copiedBlob + 1;
            for (int32_t remaining = (blobCopyBytes - 4u) >> 2; remaining > 0; --remaining, ++encodedWord) {
              const uint32_t ciphertext = *encodedWord;
              *encodedWord ^= blobXorKey;
              blobXorKey = ciphertext;
            }
            startupBlob = copiedBlob;
            const uint32_t encryptedPayload = *reinterpret_cast<uint32_t *>(
                reinterpret_cast<byte *>(copiedBlob) + payloadPointerFieldOffset);
            const uint32_t payloadBytes = *reinterpret_cast<uint32_t *>(
                reinterpret_cast<byte *>(copiedBlob) + payloadSizeFieldOffset);
            processHeap = reinterpret_cast<GetProcessHeapCall>(apiSlots[12])();
            const uint32_t decryptedImage = reinterpret_cast<HeapAllocCall>(apiSlots[13])(processHeap, 0, payloadBytes);
            const auto *payloadKey = reinterpret_cast<uint32_t *>(
                reinterpret_cast<byte *>(startupBlob) + payloadKeyOffset);
            DecryptStartupPayloadBlocks(reinterpret_cast<uint32_t *>(decryptedImage),
                                        reinterpret_cast<uint32_t *>(encryptedPayload), payloadBytes, payloadKey);
            const uint32_t payloadExport = MapStartupPayloadImage(
                decryptedImage, reinterpret_cast<const char *>(exportName), apiSlots);
            // Native erases the size-field OFFSET, not the decrypted allocation's byte count.
            const uint32_t decryptedEraseBytes = payloadSizeFieldOffset;
            for (uint32_t i = 0; i < decryptedEraseBytes; ++i) *reinterpret_cast<byte *>(decryptedImage + i) = 0;
            processHeap = reinterpret_cast<GetProcessHeapCall>(apiSlots[12])();
            reinterpret_cast<HeapFreeCall>(apiSlots[14])(processHeap, 0, decryptedImage);
            if (payloadExport == 0) {
              statusCode = 'B';
            } else {
              const uint32_t payloadEntryResult = reinterpret_cast<PayloadExportCall>(payloadExport)(
                  reinterpret_cast<uint32_t>(startupBlob), startupBlobSize);
              const uint32_t blobEraseBytes = startupBlobSize;
              for (uint32_t i = 0; i < blobEraseBytes; ++i) reinterpret_cast<byte *>(copiedBlob)[i] = 0;
              processHeap = reinterpret_cast<GetProcessHeapCall>(apiSlots[12])();
              reinterpret_cast<HeapFreeCall>(apiSlots[14])(processHeap, 0, reinterpret_cast<uint32_t>(copiedBlob));
              if (payloadEntryResult >= 0xff) {
                for (uint32_t i = 0; i < 0x340; ++i) bootstrapBytes[i] = 0;
                for (uint32_t i = 0; i < 0x68; ++i) reinterpret_cast<byte *>(apiSlots)[i] = 0;
                outcome->jumpTarget = payloadEntryResult;
                outcome->nativeEsp = nativeEsp;
                return;
              }
              statusCode = static_cast<char>(payloadEntryResult);
            }
          }
        }
        else {
          statusCode = ExchangeStartupMapping(reinterpret_cast<const uint32_t *>(resolvedApiTable), bootstrapBytes, 1);
          if (statusCode == '0') {
            if (*startupBlob == embeddedChecksum) goto begin_payload_processing;
            statusCode = 'M';
          }
        }
      }
      else {
        statusCode = 'T';
      }
    }
  }
  else {
    statusCode = 'E';
  }
  if (statusCode == '5' && LaunchSteamFallback(reinterpret_cast<const uint32_t *>(resolvedApiTable),
                                               bootstrapBytes, modulePathBuffer, parentExecutablePath, shellArguments)) {
    statusCode = '0';
  }
  if (statusCode != '0') {
    using GetLastErrorCall = uint32_t (__stdcall *)();
    if (startupErrorCode == 0) startupErrorCode = reinterpret_cast<GetLastErrorCall>(getLastError)();
    const char reportResult = ExchangeStartupMapping(
        reinterpret_cast<const uint32_t *>(resolvedApiTable), bootstrapBytes, 2);
    if (reportResult != '0') {
      using LoadLibraryExCall = uint32_t (__stdcall *)(const char *, uint32_t, uint32_t);
      using GetProcAddressCall = uint32_t (__stdcall *)(uint32_t, const char *);
      using MessageBoxCall = int32_t (__stdcall *)(uint32_t, const char *, const char *, uint32_t);
      const char savedStatusCode = statusCode;
      const uint32_t valueToFormat = static_cast<uint32_t>(startupErrorCode) + 0xff98u;
      const uint32_t user32Module = reinterpret_cast<LoadLibraryExCall>(loadLibraryExA)(
          reinterpret_cast<const char *>(user32ModuleName), 0, 0);
      const uint32_t messageBox = reinterpret_cast<GetProcAddressCall>(getProcAddress)(
          user32Module, reinterpret_cast<const char *>(messageBoxAName));
      for (uint32_t i = 0; i < 0x340; ++i) bootstrapBytes[i] = 0;
      for (uint32_t i = 0; i < 0x68; ++i) reinterpret_cast<byte *>(resolvedApiTable)[i] = 0;
      if (messageBox != 0) {
        savedErrorMessage[0x17] = savedStatusCode;
        FormatUnsignedDecimal10(valueToFormat, savedErrorMessage + 0x19);
        reinterpret_cast<MessageBoxCall>(messageBox)(0, savedErrorMessage, savedErrorCaption, 0x10);
      }
    }
  }
  for (uint32_t i = 0; i < 0x340; ++i) bootstrapBytes[i] = 0;
  for (uint32_t i = 0; i < 0x68; ++i) reinterpret_cast<byte *>(resolvedApiTable)[i] = 0;
  // ExitProcess normally does not return. Capture its actual volatile state if it unexpectedly does.
  const uint32_t exitTarget = exitProcessCallback;
  *reinterpret_cast<uint32_t *>(nativeEsp - 4) = 0;
  *reinterpret_cast<uint32_t *>(nativeEsp - 8) = 0x109441a7;
  uint32_t hostEspBefore, hostEspAfter, returnedEax, returnedEcx, returnedEdx, returnedFlags;
  __asm {
    mov hostEspBefore, esp
    push 0
    call exitTarget
    mov returnedEax, eax
    mov returnedEcx, ecx
    mov returnedEdx, edx
    pushfd
    pop returnedFlags
    mov hostEspAfter, esp
    mov esp, hostEspBefore
  }
  outcome->jumpTarget = 0;
  outcome->nativeEsp = nativeEsp + hostEspAfter - hostEspBefore;
  outcome->returnedEax = returnedEax;
  outcome->returnedEcx = returnedEcx;
  outcome->returnedEdx = returnedEdx;
  outcome->capturedFlags = returnedFlags;
}

// RavenShield.exe @ 109422ed : RunProtectedStartupEntry
// Save the entry registers, run startup against that frame, and perform its native jump or unexpected return.
__declspec(naked) void RunProtectedStartupEntry()
{
  __asm {
    push ebx
    push ecx
    push edx
    push esi
    push edi
    push ebp
    mov ebp, esp
    sub esp, 0x1000
    // Source-only scratch below the native frame and its retained resolver arguments.
    sub esp, 0x120
    mov esi, esp
    // Only DF from this initial snapshot is consumed by the source body.
    pushfd
    pop dword ptr [esi+0x14]
    push esi
    push ebp
    call RunProtectedStartupBody
    add esp, 8
    mov esi, esp
    cmp dword ptr [esi], 0
    je exit_process_returned
    mov eax, dword ptr [esi]
    mov esp, dword ptr [esi+4]
    // Native 0x1094392a–0x10943937; ADD also reproduces the arithmetic flags for this ESP path.
    add esp, 0x1000
    pop ebp
    pop edi
    pop esi
    pop edx
    pop ecx
    pop ebx
    jmp eax
  exit_process_returned:
    mov esp, dword ptr [esi+4]
    push dword ptr [esi+0x14]
    popfd
    mov eax, dword ptr [esi+8]
    mov ecx, dword ptr [esi+0x0c]
    mov edx, dword ptr [esi+0x10]
    // Native 0x109441a7–0x109441ab; these three pops consume the live frame-bottom words.
    pop edi
    pop esi
    pop ebx
    leave
    ret
  }
}
