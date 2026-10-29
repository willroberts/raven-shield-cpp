// PE32 load-configuration prefix; packed short pairs remain explicit four-byte words.
struct NativeImageLoadConfiguration {
  uint size;
  uint timestamp;
  uint packedVersions;
  uint globalFlagsClear;
  uint globalFlagsSet;
  uint criticalSectionTimeout;
  uint decommitFreeBlockThreshold;
  uint decommitTotalFreeThreshold;
  NativeImageWord32 lockPrefixTable;
  uint maximumAllocationSize;
  uint virtualMemoryThreshold;
  uint processHeapFlags;
  uint processAffinityMask;
  uint packedServiceVersionAndReserved;
  NativeImageWord32 editList;
  NativeImageWord32 securityCookie;
  NativeImageWord32 exceptionHandlerTable;
  uint exceptionHandlerCount;
};

// R6Weapons.dll data @ 1000c0d0 : writable security cookie named by the PE load configuration
// No local code reference or additional cookie initializer is inferred from this loader-facing address.
uint imageSecurityCookie = 0xbb40e64e;

// R6Weapons.dll data @ 100076d8 : PE load-configuration directory
const NativeImageLoadConfiguration imageLoadConfiguration = {
    .size = 0x48,
    .timestamp = 0,
    .packedVersions = 0,
    .globalFlagsClear = 0,
    .globalFlagsSet = 0,
    .criticalSectionTimeout = 0,
    .decommitFreeBlockThreshold = 0,
    .decommitTotalFreeThreshold = 0,
    .lockPrefixTable = 0,
    .maximumAllocationSize = 0,
    .virtualMemoryThreshold = 0,
    .processHeapFlags = 0,
    .processAffinityMask = 0,
    .packedServiceVersionAndReserved = 0,
    .editList = 0,
    .securityCookie = &imageSecurityCookie,
    .exceptionHandlerTable = &safeExceptionHandlerRVAs,
    .exceptionHandlerCount = 28,
};

// R6Weapons.dll data @ 1000c098 : exported UTF-16 package identifier GPackage
ushort GPackage[] = {'R', '6', 'W', 'e', 'a', 'p', 'o', 'n', 's', 0};
