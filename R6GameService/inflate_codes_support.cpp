#include "native_addresses.h"
#include "native_records.h"

namespace R6GameServiceNative {
// Eight-byte decoder entry: operation byte, consumed-bit byte, padding and value/subtable offset.
struct InflateLookup {
  unsigned char operation;
  unsigned char bits;
  unsigned short reserved;
  unsigned int base;
};

// Fixed decoder root widths; these are separate from the following lookup records.
struct InflateRootWidths {
  unsigned int literalBits;
  unsigned int distanceBits;
};
} // namespace R6GameServiceNative

// Shared inflater code-state controller and fixed lookup data; names/types are inferred.
// Explicit offsets, cached state, original argument scratch and raw stdcall ABI retain native operations.

// Internal targets for code states 0..9; not additional native bodies.
// R6GameService.dll data @ 10022598
static const uint InflateCodeTargets[10] = {
  R6GameServiceAddresses::inflate_codes_supportBranch4, R6GameServiceAddresses::inflate_codes_supportBranch8, R6GameServiceAddresses::inflate_codes_supportBranch15, R6GameServiceAddresses::inflate_codes_supportBranch18, R6GameServiceAddresses::inflate_codes_supportBranch22, R6GameServiceAddresses::inflate_codes_supportBranch25, R6GameServiceAddresses::inflate_codes_supportBranch42, R6GameServiceAddresses::inflate_codes_supportBranch56,
  R6GameServiceAddresses::inflate_codes_supportBranch59, R6GameServiceAddresses::inflate_codes_supportBranch60,
};

// Fixed literal/distance root widths.
// R6GameService.dll data @ 1008c940
static const R6GameServiceNative::InflateRootWidths FixedRootWidths = {0x00000009, 0x00000005};

// Eight-byte literal/length records: operation, consumed bits, native padding and base value.
// R6GameService.dll data @ 1008c948
static const R6GameServiceNative::InflateLookup FixedLiteralLookup[512] = {
  {0x60, 7, 0, 0x00000100},
  {0x00, 8, 0, 0x00000050},
  {0x00, 8, 0, 0x00000010},
  {0x54, 8, 0, 0x00000073},
  {0x52, 7, 0, 0x0000001f},
  {0x00, 8, 0, 0x00000070},
  {0x00, 8, 0, 0x00000030},
  {0x00, 9, 0, 0x000000c0},
  {0x50, 7, 0, 0x0000000a},
  {0x00, 8, 0, 0x00000060},
  {0x00, 8, 0, 0x00000020},
  {0x00, 9, 0, 0x000000a0},
  {0x00, 8, 0, 0x00000000},
  {0x00, 8, 0, 0x00000080},
  {0x00, 8, 0, 0x00000040},
  {0x00, 9, 0, 0x000000e0},
  {0x50, 7, 0, 0x00000006},
  {0x00, 8, 0, 0x00000058},
  {0x00, 8, 0, 0x00000018},
  {0x00, 9, 0, 0x00000090},
  {0x53, 7, 0, 0x0000003b},
  {0x00, 8, 0, 0x00000078},
  {0x00, 8, 0, 0x00000038},
  {0x00, 9, 0, 0x000000d0},
  {0x51, 7, 0, 0x00000011},
  {0x00, 8, 0, 0x00000068},
  {0x00, 8, 0, 0x00000028},
  {0x00, 9, 0, 0x000000b0},
  {0x00, 8, 0, 0x00000008},
  {0x00, 8, 0, 0x00000088},
  {0x00, 8, 0, 0x00000048},
  {0x00, 9, 0, 0x000000f0},
  {0x50, 7, 0, 0x00000004},
  {0x00, 8, 0, 0x00000054},
  {0x00, 8, 0, 0x00000014},
  {0x55, 8, 0, 0x000000e3},
  {0x53, 7, 0, 0x0000002b},
  {0x00, 8, 0, 0x00000074},
  {0x00, 8, 0, 0x00000034},
  {0x00, 9, 0, 0x000000c8},
  {0x51, 7, 0, 0x0000000d},
  {0x00, 8, 0, 0x00000064},
  {0x00, 8, 0, 0x00000024},
  {0x00, 9, 0, 0x000000a8},
  {0x00, 8, 0, 0x00000004},
  {0x00, 8, 0, 0x00000084},
  {0x00, 8, 0, 0x00000044},
  {0x00, 9, 0, 0x000000e8},
  {0x50, 7, 0, 0x00000008},
  {0x00, 8, 0, 0x0000005c},
  {0x00, 8, 0, 0x0000001c},
  {0x00, 9, 0, 0x00000098},
  {0x54, 7, 0, 0x00000053},
  {0x00, 8, 0, 0x0000007c},
  {0x00, 8, 0, 0x0000003c},
  {0x00, 9, 0, 0x000000d8},
  {0x52, 7, 0, 0x00000017},
  {0x00, 8, 0, 0x0000006c},
  {0x00, 8, 0, 0x0000002c},
  {0x00, 9, 0, 0x000000b8},
  {0x00, 8, 0, 0x0000000c},
  {0x00, 8, 0, 0x0000008c},
  {0x00, 8, 0, 0x0000004c},
  {0x00, 9, 0, 0x000000f8},
  {0x50, 7, 0, 0x00000003},
  {0x00, 8, 0, 0x00000052},
  {0x00, 8, 0, 0x00000012},
  {0x55, 8, 0, 0x000000a3},
  {0x53, 7, 0, 0x00000023},
  {0x00, 8, 0, 0x00000072},
  {0x00, 8, 0, 0x00000032},
  {0x00, 9, 0, 0x000000c4},
  {0x51, 7, 0, 0x0000000b},
  {0x00, 8, 0, 0x00000062},
  {0x00, 8, 0, 0x00000022},
  {0x00, 9, 0, 0x000000a4},
  {0x00, 8, 0, 0x00000002},
  {0x00, 8, 0, 0x00000082},
  {0x00, 8, 0, 0x00000042},
  {0x00, 9, 0, 0x000000e4},
  {0x50, 7, 0, 0x00000007},
  {0x00, 8, 0, 0x0000005a},
  {0x00, 8, 0, 0x0000001a},
  {0x00, 9, 0, 0x00000094},
  {0x54, 7, 0, 0x00000043},
  {0x00, 8, 0, 0x0000007a},
  {0x00, 8, 0, 0x0000003a},
  {0x00, 9, 0, 0x000000d4},
  {0x52, 7, 0, 0x00000013},
  {0x00, 8, 0, 0x0000006a},
  {0x00, 8, 0, 0x0000002a},
  {0x00, 9, 0, 0x000000b4},
  {0x00, 8, 0, 0x0000000a},
  {0x00, 8, 0, 0x0000008a},
  {0x00, 8, 0, 0x0000004a},
  {0x00, 9, 0, 0x000000f4},
  {0x50, 7, 0, 0x00000005},
  {0x00, 8, 0, 0x00000056},
  {0x00, 8, 0, 0x00000016},
  {0xc0, 8, 0, 0x00000000},
  {0x53, 7, 0, 0x00000033},
  {0x00, 8, 0, 0x00000076},
  {0x00, 8, 0, 0x00000036},
  {0x00, 9, 0, 0x000000cc},
  {0x51, 7, 0, 0x0000000f},
  {0x00, 8, 0, 0x00000066},
  {0x00, 8, 0, 0x00000026},
  {0x00, 9, 0, 0x000000ac},
  {0x00, 8, 0, 0x00000006},
  {0x00, 8, 0, 0x00000086},
  {0x00, 8, 0, 0x00000046},
  {0x00, 9, 0, 0x000000ec},
  {0x50, 7, 0, 0x00000009},
  {0x00, 8, 0, 0x0000005e},
  {0x00, 8, 0, 0x0000001e},
  {0x00, 9, 0, 0x0000009c},
  {0x54, 7, 0, 0x00000063},
  {0x00, 8, 0, 0x0000007e},
  {0x00, 8, 0, 0x0000003e},
  {0x00, 9, 0, 0x000000dc},
  {0x52, 7, 0, 0x0000001b},
  {0x00, 8, 0, 0x0000006e},
  {0x00, 8, 0, 0x0000002e},
  {0x00, 9, 0, 0x000000bc},
  {0x00, 8, 0, 0x0000000e},
  {0x00, 8, 0, 0x0000008e},
  {0x00, 8, 0, 0x0000004e},
  {0x00, 9, 0, 0x000000fc},
  {0x60, 7, 0, 0x00000100},
  {0x00, 8, 0, 0x00000051},
  {0x00, 8, 0, 0x00000011},
  {0x55, 8, 0, 0x00000083},
  {0x52, 7, 0, 0x0000001f},
  {0x00, 8, 0, 0x00000071},
  {0x00, 8, 0, 0x00000031},
  {0x00, 9, 0, 0x000000c2},
  {0x50, 7, 0, 0x0000000a},
  {0x00, 8, 0, 0x00000061},
  {0x00, 8, 0, 0x00000021},
  {0x00, 9, 0, 0x000000a2},
  {0x00, 8, 0, 0x00000001},
  {0x00, 8, 0, 0x00000081},
  {0x00, 8, 0, 0x00000041},
  {0x00, 9, 0, 0x000000e2},
  {0x50, 7, 0, 0x00000006},
  {0x00, 8, 0, 0x00000059},
  {0x00, 8, 0, 0x00000019},
  {0x00, 9, 0, 0x00000092},
  {0x53, 7, 0, 0x0000003b},
  {0x00, 8, 0, 0x00000079},
  {0x00, 8, 0, 0x00000039},
  {0x00, 9, 0, 0x000000d2},
  {0x51, 7, 0, 0x00000011},
  {0x00, 8, 0, 0x00000069},
  {0x00, 8, 0, 0x00000029},
  {0x00, 9, 0, 0x000000b2},
  {0x00, 8, 0, 0x00000009},
  {0x00, 8, 0, 0x00000089},
  {0x00, 8, 0, 0x00000049},
  {0x00, 9, 0, 0x000000f2},
  {0x50, 7, 0, 0x00000004},
  {0x00, 8, 0, 0x00000055},
  {0x00, 8, 0, 0x00000015},
  {0x50, 8, 0, 0x00000102},
  {0x53, 7, 0, 0x0000002b},
  {0x00, 8, 0, 0x00000075},
  {0x00, 8, 0, 0x00000035},
  {0x00, 9, 0, 0x000000ca},
  {0x51, 7, 0, 0x0000000d},
  {0x00, 8, 0, 0x00000065},
  {0x00, 8, 0, 0x00000025},
  {0x00, 9, 0, 0x000000aa},
  {0x00, 8, 0, 0x00000005},
  {0x00, 8, 0, 0x00000085},
  {0x00, 8, 0, 0x00000045},
  {0x00, 9, 0, 0x000000ea},
  {0x50, 7, 0, 0x00000008},
  {0x00, 8, 0, 0x0000005d},
  {0x00, 8, 0, 0x0000001d},
  {0x00, 9, 0, 0x0000009a},
  {0x54, 7, 0, 0x00000053},
  {0x00, 8, 0, 0x0000007d},
  {0x00, 8, 0, 0x0000003d},
  {0x00, 9, 0, 0x000000da},
  {0x52, 7, 0, 0x00000017},
  {0x00, 8, 0, 0x0000006d},
  {0x00, 8, 0, 0x0000002d},
  {0x00, 9, 0, 0x000000ba},
  {0x00, 8, 0, 0x0000000d},
  {0x00, 8, 0, 0x0000008d},
  {0x00, 8, 0, 0x0000004d},
  {0x00, 9, 0, 0x000000fa},
  {0x50, 7, 0, 0x00000003},
  {0x00, 8, 0, 0x00000053},
  {0x00, 8, 0, 0x00000013},
  {0x55, 8, 0, 0x000000c3},
  {0x53, 7, 0, 0x00000023},
  {0x00, 8, 0, 0x00000073},
  {0x00, 8, 0, 0x00000033},
  {0x00, 9, 0, 0x000000c6},
  {0x51, 7, 0, 0x0000000b},
  {0x00, 8, 0, 0x00000063},
  {0x00, 8, 0, 0x00000023},
  {0x00, 9, 0, 0x000000a6},
  {0x00, 8, 0, 0x00000003},
  {0x00, 8, 0, 0x00000083},
  {0x00, 8, 0, 0x00000043},
  {0x00, 9, 0, 0x000000e6},
  {0x50, 7, 0, 0x00000007},
  {0x00, 8, 0, 0x0000005b},
  {0x00, 8, 0, 0x0000001b},
  {0x00, 9, 0, 0x00000096},
  {0x54, 7, 0, 0x00000043},
  {0x00, 8, 0, 0x0000007b},
  {0x00, 8, 0, 0x0000003b},
  {0x00, 9, 0, 0x000000d6},
  {0x52, 7, 0, 0x00000013},
  {0x00, 8, 0, 0x0000006b},
  {0x00, 8, 0, 0x0000002b},
  {0x00, 9, 0, 0x000000b6},
  {0x00, 8, 0, 0x0000000b},
  {0x00, 8, 0, 0x0000008b},
  {0x00, 8, 0, 0x0000004b},
  {0x00, 9, 0, 0x000000f6},
  {0x50, 7, 0, 0x00000005},
  {0x00, 8, 0, 0x00000057},
  {0x00, 8, 0, 0x00000017},
  {0xc0, 8, 0, 0x00000000},
  {0x53, 7, 0, 0x00000033},
  {0x00, 8, 0, 0x00000077},
  {0x00, 8, 0, 0x00000037},
  {0x00, 9, 0, 0x000000ce},
  {0x51, 7, 0, 0x0000000f},
  {0x00, 8, 0, 0x00000067},
  {0x00, 8, 0, 0x00000027},
  {0x00, 9, 0, 0x000000ae},
  {0x00, 8, 0, 0x00000007},
  {0x00, 8, 0, 0x00000087},
  {0x00, 8, 0, 0x00000047},
  {0x00, 9, 0, 0x000000ee},
  {0x50, 7, 0, 0x00000009},
  {0x00, 8, 0, 0x0000005f},
  {0x00, 8, 0, 0x0000001f},
  {0x00, 9, 0, 0x0000009e},
  {0x54, 7, 0, 0x00000063},
  {0x00, 8, 0, 0x0000007f},
  {0x00, 8, 0, 0x0000003f},
  {0x00, 9, 0, 0x000000de},
  {0x52, 7, 0, 0x0000001b},
  {0x00, 8, 0, 0x0000006f},
  {0x00, 8, 0, 0x0000002f},
  {0x00, 9, 0, 0x000000be},
  {0x00, 8, 0, 0x0000000f},
  {0x00, 8, 0, 0x0000008f},
  {0x00, 8, 0, 0x0000004f},
  {0x00, 9, 0, 0x000000fe},
  {0x60, 7, 0, 0x00000100},
  {0x00, 8, 0, 0x00000050},
  {0x00, 8, 0, 0x00000010},
  {0x54, 8, 0, 0x00000073},
  {0x52, 7, 0, 0x0000001f},
  {0x00, 8, 0, 0x00000070},
  {0x00, 8, 0, 0x00000030},
  {0x00, 9, 0, 0x000000c1},
  {0x50, 7, 0, 0x0000000a},
  {0x00, 8, 0, 0x00000060},
  {0x00, 8, 0, 0x00000020},
  {0x00, 9, 0, 0x000000a1},
  {0x00, 8, 0, 0x00000000},
  {0x00, 8, 0, 0x00000080},
  {0x00, 8, 0, 0x00000040},
  {0x00, 9, 0, 0x000000e1},
  {0x50, 7, 0, 0x00000006},
  {0x00, 8, 0, 0x00000058},
  {0x00, 8, 0, 0x00000018},
  {0x00, 9, 0, 0x00000091},
  {0x53, 7, 0, 0x0000003b},
  {0x00, 8, 0, 0x00000078},
  {0x00, 8, 0, 0x00000038},
  {0x00, 9, 0, 0x000000d1},
  {0x51, 7, 0, 0x00000011},
  {0x00, 8, 0, 0x00000068},
  {0x00, 8, 0, 0x00000028},
  {0x00, 9, 0, 0x000000b1},
  {0x00, 8, 0, 0x00000008},
  {0x00, 8, 0, 0x00000088},
  {0x00, 8, 0, 0x00000048},
  {0x00, 9, 0, 0x000000f1},
  {0x50, 7, 0, 0x00000004},
  {0x00, 8, 0, 0x00000054},
  {0x00, 8, 0, 0x00000014},
  {0x55, 8, 0, 0x000000e3},
  {0x53, 7, 0, 0x0000002b},
  {0x00, 8, 0, 0x00000074},
  {0x00, 8, 0, 0x00000034},
  {0x00, 9, 0, 0x000000c9},
  {0x51, 7, 0, 0x0000000d},
  {0x00, 8, 0, 0x00000064},
  {0x00, 8, 0, 0x00000024},
  {0x00, 9, 0, 0x000000a9},
  {0x00, 8, 0, 0x00000004},
  {0x00, 8, 0, 0x00000084},
  {0x00, 8, 0, 0x00000044},
  {0x00, 9, 0, 0x000000e9},
  {0x50, 7, 0, 0x00000008},
  {0x00, 8, 0, 0x0000005c},
  {0x00, 8, 0, 0x0000001c},
  {0x00, 9, 0, 0x00000099},
  {0x54, 7, 0, 0x00000053},
  {0x00, 8, 0, 0x0000007c},
  {0x00, 8, 0, 0x0000003c},
  {0x00, 9, 0, 0x000000d9},
  {0x52, 7, 0, 0x00000017},
  {0x00, 8, 0, 0x0000006c},
  {0x00, 8, 0, 0x0000002c},
  {0x00, 9, 0, 0x000000b9},
  {0x00, 8, 0, 0x0000000c},
  {0x00, 8, 0, 0x0000008c},
  {0x00, 8, 0, 0x0000004c},
  {0x00, 9, 0, 0x000000f9},
  {0x50, 7, 0, 0x00000003},
  {0x00, 8, 0, 0x00000052},
  {0x00, 8, 0, 0x00000012},
  {0x55, 8, 0, 0x000000a3},
  {0x53, 7, 0, 0x00000023},
  {0x00, 8, 0, 0x00000072},
  {0x00, 8, 0, 0x00000032},
  {0x00, 9, 0, 0x000000c5},
  {0x51, 7, 0, 0x0000000b},
  {0x00, 8, 0, 0x00000062},
  {0x00, 8, 0, 0x00000022},
  {0x00, 9, 0, 0x000000a5},
  {0x00, 8, 0, 0x00000002},
  {0x00, 8, 0, 0x00000082},
  {0x00, 8, 0, 0x00000042},
  {0x00, 9, 0, 0x000000e5},
  {0x50, 7, 0, 0x00000007},
  {0x00, 8, 0, 0x0000005a},
  {0x00, 8, 0, 0x0000001a},
  {0x00, 9, 0, 0x00000095},
  {0x54, 7, 0, 0x00000043},
  {0x00, 8, 0, 0x0000007a},
  {0x00, 8, 0, 0x0000003a},
  {0x00, 9, 0, 0x000000d5},
  {0x52, 7, 0, 0x00000013},
  {0x00, 8, 0, 0x0000006a},
  {0x00, 8, 0, 0x0000002a},
  {0x00, 9, 0, 0x000000b5},
  {0x00, 8, 0, 0x0000000a},
  {0x00, 8, 0, 0x0000008a},
  {0x00, 8, 0, 0x0000004a},
  {0x00, 9, 0, 0x000000f5},
  {0x50, 7, 0, 0x00000005},
  {0x00, 8, 0, 0x00000056},
  {0x00, 8, 0, 0x00000016},
  {0xc0, 8, 0, 0x00000000},
  {0x53, 7, 0, 0x00000033},
  {0x00, 8, 0, 0x00000076},
  {0x00, 8, 0, 0x00000036},
  {0x00, 9, 0, 0x000000cd},
  {0x51, 7, 0, 0x0000000f},
  {0x00, 8, 0, 0x00000066},
  {0x00, 8, 0, 0x00000026},
  {0x00, 9, 0, 0x000000ad},
  {0x00, 8, 0, 0x00000006},
  {0x00, 8, 0, 0x00000086},
  {0x00, 8, 0, 0x00000046},
  {0x00, 9, 0, 0x000000ed},
  {0x50, 7, 0, 0x00000009},
  {0x00, 8, 0, 0x0000005e},
  {0x00, 8, 0, 0x0000001e},
  {0x00, 9, 0, 0x0000009d},
  {0x54, 7, 0, 0x00000063},
  {0x00, 8, 0, 0x0000007e},
  {0x00, 8, 0, 0x0000003e},
  {0x00, 9, 0, 0x000000dd},
  {0x52, 7, 0, 0x0000001b},
  {0x00, 8, 0, 0x0000006e},
  {0x00, 8, 0, 0x0000002e},
  {0x00, 9, 0, 0x000000bd},
  {0x00, 8, 0, 0x0000000e},
  {0x00, 8, 0, 0x0000008e},
  {0x00, 8, 0, 0x0000004e},
  {0x00, 9, 0, 0x000000fd},
  {0x60, 7, 0, 0x00000100},
  {0x00, 8, 0, 0x00000051},
  {0x00, 8, 0, 0x00000011},
  {0x55, 8, 0, 0x00000083},
  {0x52, 7, 0, 0x0000001f},
  {0x00, 8, 0, 0x00000071},
  {0x00, 8, 0, 0x00000031},
  {0x00, 9, 0, 0x000000c3},
  {0x50, 7, 0, 0x0000000a},
  {0x00, 8, 0, 0x00000061},
  {0x00, 8, 0, 0x00000021},
  {0x00, 9, 0, 0x000000a3},
  {0x00, 8, 0, 0x00000001},
  {0x00, 8, 0, 0x00000081},
  {0x00, 8, 0, 0x00000041},
  {0x00, 9, 0, 0x000000e3},
  {0x50, 7, 0, 0x00000006},
  {0x00, 8, 0, 0x00000059},
  {0x00, 8, 0, 0x00000019},
  {0x00, 9, 0, 0x00000093},
  {0x53, 7, 0, 0x0000003b},
  {0x00, 8, 0, 0x00000079},
  {0x00, 8, 0, 0x00000039},
  {0x00, 9, 0, 0x000000d3},
  {0x51, 7, 0, 0x00000011},
  {0x00, 8, 0, 0x00000069},
  {0x00, 8, 0, 0x00000029},
  {0x00, 9, 0, 0x000000b3},
  {0x00, 8, 0, 0x00000009},
  {0x00, 8, 0, 0x00000089},
  {0x00, 8, 0, 0x00000049},
  {0x00, 9, 0, 0x000000f3},
  {0x50, 7, 0, 0x00000004},
  {0x00, 8, 0, 0x00000055},
  {0x00, 8, 0, 0x00000015},
  {0x50, 8, 0, 0x00000102},
  {0x53, 7, 0, 0x0000002b},
  {0x00, 8, 0, 0x00000075},
  {0x00, 8, 0, 0x00000035},
  {0x00, 9, 0, 0x000000cb},
  {0x51, 7, 0, 0x0000000d},
  {0x00, 8, 0, 0x00000065},
  {0x00, 8, 0, 0x00000025},
  {0x00, 9, 0, 0x000000ab},
  {0x00, 8, 0, 0x00000005},
  {0x00, 8, 0, 0x00000085},
  {0x00, 8, 0, 0x00000045},
  {0x00, 9, 0, 0x000000eb},
  {0x50, 7, 0, 0x00000008},
  {0x00, 8, 0, 0x0000005d},
  {0x00, 8, 0, 0x0000001d},
  {0x00, 9, 0, 0x0000009b},
  {0x54, 7, 0, 0x00000053},
  {0x00, 8, 0, 0x0000007d},
  {0x00, 8, 0, 0x0000003d},
  {0x00, 9, 0, 0x000000db},
  {0x52, 7, 0, 0x00000017},
  {0x00, 8, 0, 0x0000006d},
  {0x00, 8, 0, 0x0000002d},
  {0x00, 9, 0, 0x000000bb},
  {0x00, 8, 0, 0x0000000d},
  {0x00, 8, 0, 0x0000008d},
  {0x00, 8, 0, 0x0000004d},
  {0x00, 9, 0, 0x000000fb},
  {0x50, 7, 0, 0x00000003},
  {0x00, 8, 0, 0x00000053},
  {0x00, 8, 0, 0x00000013},
  {0x55, 8, 0, 0x000000c3},
  {0x53, 7, 0, 0x00000023},
  {0x00, 8, 0, 0x00000073},
  {0x00, 8, 0, 0x00000033},
  {0x00, 9, 0, 0x000000c7},
  {0x51, 7, 0, 0x0000000b},
  {0x00, 8, 0, 0x00000063},
  {0x00, 8, 0, 0x00000023},
  {0x00, 9, 0, 0x000000a7},
  {0x00, 8, 0, 0x00000003},
  {0x00, 8, 0, 0x00000083},
  {0x00, 8, 0, 0x00000043},
  {0x00, 9, 0, 0x000000e7},
  {0x50, 7, 0, 0x00000007},
  {0x00, 8, 0, 0x0000005b},
  {0x00, 8, 0, 0x0000001b},
  {0x00, 9, 0, 0x00000097},
  {0x54, 7, 0, 0x00000043},
  {0x00, 8, 0, 0x0000007b},
  {0x00, 8, 0, 0x0000003b},
  {0x00, 9, 0, 0x000000d7},
  {0x52, 7, 0, 0x00000013},
  {0x00, 8, 0, 0x0000006b},
  {0x00, 8, 0, 0x0000002b},
  {0x00, 9, 0, 0x000000b7},
  {0x00, 8, 0, 0x0000000b},
  {0x00, 8, 0, 0x0000008b},
  {0x00, 8, 0, 0x0000004b},
  {0x00, 9, 0, 0x000000f7},
  {0x50, 7, 0, 0x00000005},
  {0x00, 8, 0, 0x00000057},
  {0x00, 8, 0, 0x00000017},
  {0xc0, 8, 0, 0x00000000},
  {0x53, 7, 0, 0x00000033},
  {0x00, 8, 0, 0x00000077},
  {0x00, 8, 0, 0x00000037},
  {0x00, 9, 0, 0x000000cf},
  {0x51, 7, 0, 0x0000000f},
  {0x00, 8, 0, 0x00000067},
  {0x00, 8, 0, 0x00000027},
  {0x00, 9, 0, 0x000000af},
  {0x00, 8, 0, 0x00000007},
  {0x00, 8, 0, 0x00000087},
  {0x00, 8, 0, 0x00000047},
  {0x00, 9, 0, 0x000000ef},
  {0x50, 7, 0, 0x00000009},
  {0x00, 8, 0, 0x0000005f},
  {0x00, 8, 0, 0x0000001f},
  {0x00, 9, 0, 0x0000009f},
  {0x54, 7, 0, 0x00000063},
  {0x00, 8, 0, 0x0000007f},
  {0x00, 8, 0, 0x0000003f},
  {0x00, 9, 0, 0x000000df},
  {0x52, 7, 0, 0x0000001b},
  {0x00, 8, 0, 0x0000006f},
  {0x00, 8, 0, 0x0000002f},
  {0x00, 9, 0, 0x000000bf},
  {0x00, 8, 0, 0x0000000f},
  {0x00, 8, 0, 0x0000008f},
  {0x00, 8, 0, 0x0000004f},
  {0x00, 9, 0, 0x000000ff},
};

// Eight-byte distance records with the same operation/bit/base layout.
// R6GameService.dll data @ 1008d948
static const R6GameServiceNative::InflateLookup FixedDistanceLookup[32] = {
  {0x50, 5, 0, 0x00000001},
  {0x57, 5, 0, 0x00000101},
  {0x53, 5, 0, 0x00000011},
  {0x5b, 5, 0, 0x00001001},
  {0x51, 5, 0, 0x00000005},
  {0x59, 5, 0, 0x00000401},
  {0x55, 5, 0, 0x00000041},
  {0x5d, 5, 0, 0x00004001},
  {0x50, 5, 0, 0x00000003},
  {0x58, 5, 0, 0x00000201},
  {0x54, 5, 0, 0x00000021},
  {0x5c, 5, 0, 0x00002001},
  {0x52, 5, 0, 0x00000009},
  {0x5a, 5, 0, 0x00000801},
  {0x56, 5, 0, 0x00000081},
  {0xc0, 5, 0, 0x00006001},
  {0x50, 5, 0, 0x00000002},
  {0x57, 5, 0, 0x00000181},
  {0x53, 5, 0, 0x00000019},
  {0x5b, 5, 0, 0x00001801},
  {0x51, 5, 0, 0x00000007},
  {0x59, 5, 0, 0x00000601},
  {0x55, 5, 0, 0x00000061},
  {0x5d, 5, 0, 0x00006001},
  {0x50, 5, 0, 0x00000004},
  {0x58, 5, 0, 0x00000301},
  {0x54, 5, 0, 0x00000031},
  {0x5c, 5, 0, 0x00003001},
  {0x52, 5, 0, 0x0000000d},
  {0x5a, 5, 0, 0x00000c01},
  {0x56, 5, 0, 0x000000c1},
  {0xc0, 5, 0, 0x00006001},
};

// Low-bit masks indexed by the native unchecked bit width.
// R6GameService.dll data @ 1008db38
static const uint InflateLowBitMasks[17] = {
  0x00000000, 0x00000001, 0x00000003, 0x00000007, 0x0000000f, 0x0000001f, 0x0000003f, 0x0000007f,
  0x000000ff, 0x000001ff, 0x000003ff, 0x000007ff, 0x00000fff, 0x00001fff, 0x00003fff, 0x00007fff,
  0x0000ffff,
};

// Decode literals and matches through resumable code states, preserving native bit/input/output publication order.
// R6GameService.dll @ 10021ee0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall InflateHuffmanCodes(void *state,void *stream,uint status)
{
  __asm {
    sub    esp,0x10
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x20]
    push   edi
    mov    edi,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esi+0x20]
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [edi+0x4]
    mov    ebp,DWORD PTR [edi]
    mov    ebx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esp+0x28],ecx
    mov    ecx,DWORD PTR [esi+0x30]
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,DWORD PTR [esi+0x34]
    mov    DWORD PTR [esp+0x10],eax
    cmp    edx,ecx
    jae    Branch1
    sub    ecx,edx
    dec    ecx
    jmp    Branch2
  Branch1:
    mov    ecx,DWORD PTR [esi+0x2c]
    sub    ecx,edx
  Branch2:
    mov    DWORD PTR [esp+0x14],ecx
  Branch3:
    mov    ecx,DWORD PTR [eax]
    cmp    ecx,0x9
    ja     Branch61
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::InflateCodeTargets]
  Branch4:
    cmp    DWORD PTR [esp+0x14],0x102
    jb     Branch7
    cmp    DWORD PTR [esp+0x28],0xa
    jb     Branch7
    mov    eax,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esi+0x20],eax
    mov    DWORD PTR [esi+0x1c],ebx
    mov    ebx,DWORD PTR [edi+0x8]
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,DWORD PTR [edi]
    mov    eax,ebp
    sub    eax,ecx
    mov    DWORD PTR [edi],ebp
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [edi+0x8],ebx
    mov    DWORD PTR [esi+0x34],edx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    edx,DWORD PTR [eax+0x14]
    push   edi
    push   esi
    push   ecx
    push   edx
    xor    ecx,ecx
    xor    edx,edx
    mov    cl,BYTE PTR [eax+0x11]
    mov    dl,BYTE PTR [eax+0x10]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::DecodeHuffmanFastPath
    mov    ecx,DWORD PTR [edi+0x4]
    mov    edx,DWORD PTR [esi+0x20]
    mov    ebp,DWORD PTR [edi]
    mov    ebx,DWORD PTR [esi+0x1c]
    mov    DWORD PTR [esp+0x28],ecx
    mov    ecx,DWORD PTR [esi+0x30]
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,DWORD PTR [esi+0x34]
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x2c],eax
    jae    Branch5
    sub    ecx,edx
    dec    ecx
    jmp    Branch6
  Branch5:
    mov    ecx,DWORD PTR [esi+0x2c]
    sub    ecx,edx
  Branch6:
    test   eax,eax
    mov    DWORD PTR [esp+0x14],ecx
    je     Branch7
    xor    ecx,ecx
    cmp    eax,0x1
    mov    eax,DWORD PTR [esp+0x10]
    setne  cl
    lea    ecx,[ecx+ecx*1+0x7]
    mov    DWORD PTR [eax],ecx
    jmp    Branch3
  Branch7:
    mov    eax,DWORD PTR [esp+0x10]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+0x10]
    mov    DWORD PTR [eax],0x1
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x14]
    mov    DWORD PTR [eax+0x8],ecx
  Branch8:
    mov    eax,DWORD PTR [eax+0xc]
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x18],eax
    jae    Branch10
  Branch9:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch54
    dec    eax
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x28],eax
    xor    eax,eax
    mov    al,BYTE PTR [ebp+0x0]
    add    ebx,0x8
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x2c],0x0
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    inc    ebp
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x24],ecx
    jb     Branch9
  Branch10:
    mov    ecx,DWORD PTR [eax*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    eax,DWORD PTR [esp+0x24]
    and    ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [eax+0x8]
    lea    eax,[eax+ecx*8]
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x18],eax
    mov    cl,BYTE PTR [eax+0x1]
    mov    eax,DWORD PTR [esp+0x24]
    shr    eax,cl
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x24],eax
    mov    eax,ecx
    sub    ebx,eax
    mov    eax,DWORD PTR [esp+0x18]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax]
    test   ecx,ecx
    jne    Branch11
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax],0x6
    jmp    Branch3
  Branch11:
    test   cl,0x10
    je     Branch12
    mov    eax,DWORD PTR [esp+0x10]
    and    ecx,0xf
    mov    DWORD PTR [eax+0x8],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax],0x2
    mov    DWORD PTR [eax+0x4],ecx
    jmp    Branch3
  Branch12:
    test   cl,0x40
    jne    Branch14
  Branch13:
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax+0xc],ecx
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [eax+0x4]
    lea    ecx,[eax+ecx*8]
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax+0x8],ecx
    jmp    Branch3
  Branch14:
    mov    eax,DWORD PTR [esp+0x10]
    test   cl,0x20
    je     Branch53
    mov    DWORD PTR [eax],0x7
    jmp    Branch3
  Branch15:
    mov    eax,DWORD PTR [eax+0x8]
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x18],eax
    jae    Branch17
  Branch16:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch54
    dec    eax
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x28],eax
    xor    eax,eax
    mov    al,BYTE PTR [ebp+0x0]
    add    ebx,0x8
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x2c],0x0
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    inc    ebp
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x24],ecx
    jb     Branch16
  Branch17:
    mov    ecx,DWORD PTR [eax*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    eax,DWORD PTR [esp+0x24]
    and    ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    add    DWORD PTR [eax+0x4],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x24]
    shr    eax,cl
    mov    DWORD PTR [esp+0x24],eax
    mov    eax,ecx
    sub    ebx,eax
    mov    eax,DWORD PTR [esp+0x10]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+0x11]
    mov    DWORD PTR [eax],0x3
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    DWORD PTR [eax+0x8],ecx
  Branch18:
    mov    eax,DWORD PTR [eax+0xc]
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x18],eax
    jae    Branch20
  Branch19:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch54
    dec    eax
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x28],eax
    xor    eax,eax
    mov    al,BYTE PTR [ebp+0x0]
    add    ebx,0x8
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x2c],0x0
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    inc    ebp
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x24],ecx
    jb     Branch19
  Branch20:
    mov    ecx,DWORD PTR [eax*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    eax,DWORD PTR [esp+0x24]
    and    ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [eax+0x8]
    lea    eax,[eax+ecx*8]
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x18],eax
    mov    cl,BYTE PTR [eax+0x1]
    mov    eax,DWORD PTR [esp+0x24]
    shr    eax,cl
    mov    DWORD PTR [esp+0x1c],ecx
    sub    ebx,ecx
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x24],eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    cl,BYTE PTR [eax]
    test   cl,0x10
    je     Branch21
    mov    eax,DWORD PTR [esp+0x10]
    and    ecx,0xf
    mov    DWORD PTR [eax+0x8],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax],0x4
    mov    DWORD PTR [eax+0xc],ecx
    jmp    Branch3
  Branch21:
    test   cl,0x40
    je     Branch13
    mov    eax,DWORD PTR [esp+0x10]
    push   0xfffffffd
    mov    DWORD PTR [eax],0x9
    mov    DWORD PTR [edi+0x18],R6GameServiceAddresses::TextInvalidDistanceCode
    jmp    Branch62
  Branch22:
    mov    eax,DWORD PTR [eax+0x8]
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x18],eax
    jae    Branch24
  Branch23:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch54
    dec    eax
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x28],eax
    xor    eax,eax
    mov    al,BYTE PTR [ebp+0x0]
    add    ebx,0x8
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x2c],0x0
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    inc    ebp
    cmp    ebx,eax
    mov    DWORD PTR [esp+0x24],ecx
    jb     Branch23
  Branch24:
    mov    ecx,DWORD PTR [eax*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    eax,DWORD PTR [esp+0x24]
    and    ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    add    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x24]
    shr    eax,cl
    mov    DWORD PTR [esp+0x24],eax
    mov    eax,ecx
    sub    ebx,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],0x5
  Branch25:
    mov    ecx,edx
    sub    ecx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [esi+0x28]
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x18],ecx
    jae    Branch28
    mov    ecx,DWORD PTR [esi+0x2c]
    sub    ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x1c],ecx
    jmp    Branch27
  Branch26:
    mov    ecx,DWORD PTR [esp+0x1c]
  Branch27:
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    eax,ecx
    jb     Branch26
    mov    DWORD PTR [esp+0x18],eax
  Branch28:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [eax+0x4]
    test   ecx,ecx
    je     Branch41
  Branch29:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    jne    Branch39
    mov    eax,DWORD PTR [esi+0x2c]
    cmp    edx,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch32
    mov    eax,DWORD PTR [esi+0x30]
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    eax,ecx
    je     Branch32
    mov    edx,ecx
    cmp    edx,eax
    jae    Branch30
    sub    eax,edx
    dec    eax
    jmp    Branch31
  Branch30:
    mov    eax,DWORD PTR [esp+0x1c]
    sub    eax,edx
  Branch31:
    test   eax,eax
    mov    DWORD PTR [esp+0x14],eax
    jne    Branch38
  Branch32:
    mov    DWORD PTR [esi+0x34],edx
    mov    edx,DWORD PTR [esp+0x2c]
    push   edx
    push   edi
    push   esi
    call   R6GameServiceAddresses::CommitInflaterOutput
    mov    edx,DWORD PTR [esi+0x34]
    mov    DWORD PTR [esp+0x2c],eax
    mov    eax,DWORD PTR [esi+0x30]
    cmp    edx,eax
    jae    Branch33
    mov    ecx,eax
    sub    ecx,edx
    dec    ecx
    jmp    Branch34
  Branch33:
    mov    ecx,DWORD PTR [esi+0x2c]
    sub    ecx,edx
  Branch34:
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esi+0x2c]
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x1c],ecx
    jne    Branch37
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    eax,ecx
    je     Branch37
    mov    edx,ecx
    cmp    edx,eax
    jae    Branch35
    sub    eax,edx
    dec    eax
    jmp    Branch36
  Branch35:
    mov    eax,DWORD PTR [esp+0x1c]
    sub    eax,edx
  Branch36:
    mov    DWORD PTR [esp+0x14],eax
  Branch37:
    mov    eax,DWORD PTR [esp+0x14]
    test   eax,eax
    je     Branch55
  Branch38:
    mov    eax,DWORD PTR [esp+0x10]
  Branch39:
    mov    ecx,DWORD PTR [esp+0x18]
    inc    edx
    mov    DWORD PTR [esp+0x2c],0x0
    mov    cl,BYTE PTR [ecx]
    mov    BYTE PTR [edx-0x1],cl
    mov    ecx,DWORD PTR [esp+0x18]
    inc    ecx
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    dec    ecx
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    cmp    ecx,DWORD PTR [esi+0x2c]
    jne    Branch40
    mov    ecx,DWORD PTR [esi+0x28]
    mov    DWORD PTR [esp+0x18],ecx
  Branch40:
    mov    ecx,DWORD PTR [eax+0x4]
    dec    ecx
    mov    DWORD PTR [eax+0x4],ecx
    jne    Branch29
  Branch41:
    mov    DWORD PTR [eax],0x0
    jmp    Branch3
  Branch42:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    jne    Branch52
    mov    eax,DWORD PTR [esi+0x2c]
    cmp    edx,eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch45
    mov    eax,DWORD PTR [esi+0x30]
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    eax,ecx
    je     Branch45
    mov    edx,ecx
    cmp    edx,eax
    jae    Branch43
    sub    eax,edx
    dec    eax
    jmp    Branch44
  Branch43:
    mov    eax,DWORD PTR [esp+0x1c]
    sub    eax,edx
  Branch44:
    test   eax,eax
    mov    DWORD PTR [esp+0x14],eax
    jne    Branch51
  Branch45:
    mov    DWORD PTR [esi+0x34],edx
    mov    edx,DWORD PTR [esp+0x2c]
    push   edx
    push   edi
    push   esi
    call   R6GameServiceAddresses::CommitInflaterOutput
    mov    edx,DWORD PTR [esi+0x34]
    mov    DWORD PTR [esp+0x2c],eax
    mov    eax,DWORD PTR [esi+0x30]
    cmp    edx,eax
    jae    Branch46
    mov    ecx,eax
    sub    ecx,edx
    dec    ecx
    jmp    Branch47
  Branch46:
    mov    ecx,DWORD PTR [esi+0x2c]
    sub    ecx,edx
  Branch47:
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esi+0x2c]
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x1c],ecx
    jne    Branch50
    mov    ecx,DWORD PTR [esi+0x28]
    cmp    eax,ecx
    je     Branch50
    mov    edx,ecx
    cmp    edx,eax
    jae    Branch48
    sub    eax,edx
    dec    eax
    jmp    Branch49
  Branch48:
    mov    eax,DWORD PTR [esp+0x1c]
    sub    eax,edx
  Branch49:
    mov    DWORD PTR [esp+0x14],eax
  Branch50:
    mov    eax,DWORD PTR [esp+0x14]
    test   eax,eax
    je     Branch55
  Branch51:
    mov    eax,DWORD PTR [esp+0x10]
  Branch52:
    mov    cl,BYTE PTR [eax+0x8]
    mov    DWORD PTR [esp+0x2c],0x0
    mov    BYTE PTR [edx],cl
    mov    ecx,DWORD PTR [esp+0x14]
    inc    edx
    dec    ecx
    mov    DWORD PTR [eax],0x0
    jmp    Branch2
  Branch53:
    mov    DWORD PTR [eax],0x9
    mov    DWORD PTR [edi+0x18],R6GameServiceAddresses::TextInvalidLiteralLengthCode
    push   0xfffffffd
    jmp    Branch62
  Branch54:
    mov    eax,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esi+0x1c],ebx
    mov    DWORD PTR [esi+0x20],eax
    mov    ebx,DWORD PTR [edi]
    mov    eax,DWORD PTR [edi+0x8]
    mov    ecx,ebp
    sub    ecx,ebx
    mov    DWORD PTR [edi+0x4],0x0
    add    eax,ecx
    mov    DWORD PTR [edi],ebp
    mov    DWORD PTR [edi+0x8],eax
    mov    DWORD PTR [esi+0x34],edx
    mov    edx,DWORD PTR [esp+0x2c]
    push   edx
    push   edi
    push   esi
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x10
    ret    0xc
  Branch55:
    mov    eax,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esi+0x20],eax
    mov    DWORD PTR [esi+0x1c],ebx
    mov    ebx,DWORD PTR [edi+0x8]
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,DWORD PTR [edi]
    mov    eax,ebp
    sub    eax,ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    add    ebx,eax
    push   ecx
    jmp    Branch64
  Branch56:
    cmp    ebx,0x7
    jbe    Branch57
    mov    ecx,DWORD PTR [esp+0x28]
    sub    ebx,0x8
    inc    ecx
    dec    ebp
    mov    DWORD PTR [esp+0x28],ecx
  Branch57:
    mov    DWORD PTR [esi+0x34],edx
    mov    edx,DWORD PTR [esp+0x2c]
    push   edx
    push   edi
    push   esi
    call   R6GameServiceAddresses::CommitInflaterOutput
    mov    edx,DWORD PTR [esi+0x34]
    mov    ecx,DWORD PTR [esi+0x30]
    cmp    ecx,edx
    je     Branch58
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esi+0x1c],ebx
    mov    DWORD PTR [esi+0x20],ecx
    mov    ecx,DWORD PTR [esp+0x28]
    mov    ebx,DWORD PTR [edi]
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,ebp
    push   eax
    sub    ecx,ebx
    jmp    Branch63
  Branch58:
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],0x8
  Branch59:
    push   0x1
    jmp    Branch62
  Branch60:
    mov    eax,DWORD PTR [esp+0x24]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esi+0x20],eax
    mov    DWORD PTR [esi+0x1c],ebx
    mov    ebx,DWORD PTR [edi+0x8]
    mov    DWORD PTR [edi+0x4],ecx
    mov    ecx,DWORD PTR [edi]
    mov    eax,ebp
    sub    eax,ecx
    push   0xfffffffd
    add    ebx,eax
    jmp    Branch64
  Branch61:
    push   0xfffffffe
  Branch62:
    mov    ecx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [esi+0x1c],ebx
    mov    DWORD PTR [esi+0x20],ecx
    mov    DWORD PTR [edi+0x4],eax
    mov    eax,DWORD PTR [edi]
    mov    ecx,ebp
    sub    ecx,eax
  Branch63:
    mov    ebx,DWORD PTR [edi+0x8]
    add    ebx,ecx
  Branch64:
    push   edi
    mov    DWORD PTR [edi],ebp
    mov    DWORD PTR [edi+0x8],ebx
    push   esi
    mov    DWORD PTR [esi+0x34],edx
    call   R6GameServiceAddresses::CommitInflaterOutput
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x10
    ret    0xc
  }
}

// Publish fixed widths and table pointers in native order; the fifth argument is unused.
// R6GameService.dll @ 10022cb0 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall GetFixedHuffmanTables(
  uint *literalBits,uint *distanceBits,const void **literalTable,const void **distanceTable,void *stream)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::FixedRootWidths
    mov    edx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [eax],ecx
    mov    eax,ds:R6GameServiceAddresses::FixedRootWidths+0x4
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR [edx],eax
    mov    edx,DWORD PTR [esp+0x10]
    xor    eax,eax
    mov    DWORD PTR [ecx],R6GameServiceAddresses::FixedLiteralLookup
    mov    DWORD PTR [edx],R6GameServiceAddresses::FixedDistanceLookup
    ret    0x14
  }
}

// Decode lookahead literals/matches into one output segment and return whole unused input bytes before publication.
// R6GameService.dll @ 10022e10 : complete native operations/raw ABI; descriptive shared helper name.
__declspec(naked) uint __stdcall DecodeHuffmanFastPath(
  uint literalBits,uint distanceBits,const void *literalTable,const void *distanceTable,void *state,void *stream)
{
  __asm {
    sub    esp,0x10
    mov    eax,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x24]
    push   ebx
    push   ebp
    mov    ebx,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    mov    ebp,DWORD PTR [ecx+0x34]
    mov    edx,DWORD PTR [ecx+0x30]
    push   esi
    mov    esi,DWORD PTR [ecx+0x20]
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [ecx+0x1c]
    cmp    ebp,edx
    push   edi
    mov    DWORD PTR [esp+0x14],ebx
    jae    Branch65
    sub    edx,ebp
    dec    edx
    mov    DWORD PTR [esp+0x18],edx
    jmp    Branch66
  Branch65:
    mov    ecx,DWORD PTR [ecx+0x2c]
    sub    ecx,ebp
    mov    DWORD PTR [esp+0x18],ecx
  Branch66:
    mov    ecx,DWORD PTR [esp+0x24]
    mov    edx,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    ecx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esp+0x1c],edx
    mov    edx,DWORD PTR [ecx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    DWORD PTR [esp+0x28],edx
  Branch67:
    cmp    eax,0x14
    jae    Branch69
  Branch68:
    mov    ecx,DWORD PTR [esp+0x10]
    dec    ecx
    mov    DWORD PTR [esp+0x10],ecx
    xor    ecx,ecx
    mov    cl,BYTE PTR [ebx]
    mov    edx,ecx
    mov    ecx,eax
    shl    edx,cl
    add    eax,0x8
    or     esi,edx
    inc    ebx
    cmp    eax,0x14
    jb     Branch68
    mov    DWORD PTR [esp+0x14],ebx
  Branch69:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x2c]
    and    ecx,esi
    lea    edi,[edx+ecx*8]
    xor    edx,edx
    mov    dl,BYTE PTR [edi]
    test   edx,edx
    jne    Branch70
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+0x1]
    shr    esi,cl
    sub    eax,ecx
    mov    cl,BYTE PTR [edi+0x4]
    mov    BYTE PTR [ebp+0x0],cl
    jmp    Branch71
  Branch70:
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+0x1]
    shr    esi,cl
    sub    eax,ecx
    mov    DWORD PTR [esp+0x24],ecx
    test   dl,0x10
    jne    Branch73
    test   dl,0x40
    jne    Branch91
    mov    edx,DWORD PTR [edx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    ecx,DWORD PTR [edi+0x4]
    and    edx,esi
    add    edx,ecx
    lea    edi,[edi+edx*8]
    xor    edx,edx
    mov    dl,BYTE PTR [edi]
    test   edx,edx
    jne    Branch70
    mov    dl,BYTE PTR [edi+0x4]
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+0x1]
    mov    BYTE PTR [ebp+0x0],dl
    shr    esi,cl
    sub    eax,ecx
  Branch71:
    mov    ecx,DWORD PTR [esp+0x18]
    inc    ebp
    dec    ecx
    mov    DWORD PTR [esp+0x18],ecx
  Branch72:
    cmp    DWORD PTR [esp+0x18],0x102
    jb     Branch89
    cmp    DWORD PTR [esp+0x10],0xa
    jae    Branch67
    jmp    Branch89
  Branch73:
    and    edx,0xf
    sub    eax,edx
    mov    ecx,DWORD PTR [edx*4+R6GameServiceAddresses::InflateLowBitMasks]
    and    ecx,esi
    add    ecx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x24],ecx
    mov    ecx,edx
    shr    esi,cl
    cmp    eax,0xf
    jae    Branch75
  Branch74:
    mov    ecx,DWORD PTR [esp+0x10]
    dec    ecx
    mov    DWORD PTR [esp+0x10],ecx
    xor    ecx,ecx
    mov    cl,BYTE PTR [ebx]
    mov    edx,ecx
    mov    ecx,eax
    shl    edx,cl
    add    eax,0x8
    or     esi,edx
    inc    ebx
    cmp    eax,0xf
    jb     Branch74
    mov    DWORD PTR [esp+0x14],ebx
  Branch75:
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x30]
    and    ecx,esi
    lea    ebx,[edx+ecx*8]
  Branch76:
    xor    ecx,ecx
    xor    edx,edx
    mov    cl,BYTE PTR [ebx+0x1]
    mov    dl,BYTE PTR [ebx]
    shr    esi,cl
    sub    eax,ecx
    test   dl,0x10
    jne    Branch77
    test   dl,0x40
    jne    Branch87
    mov    ecx,DWORD PTR [edx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    edx,DWORD PTR [ebx+0x4]
    and    ecx,esi
    add    ecx,edx
    lea    ebx,[ebx+ecx*8]
    jmp    Branch76
  Branch77:
    and    edx,0xf
    cmp    eax,edx
    jae    Branch79
  Branch78:
    mov    edi,DWORD PTR [esp+0x10]
    xor    ecx,ecx
    dec    edi
    mov    DWORD PTR [esp+0x10],edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    cl,BYTE PTR [edi]
    mov    edi,ecx
    mov    ecx,eax
    shl    edi,cl
    mov    ecx,DWORD PTR [esp+0x14]
    add    eax,0x8
    or     esi,edi
    inc    ecx
    cmp    eax,edx
    mov    DWORD PTR [esp+0x14],ecx
    jb     Branch78
  Branch79:
    mov    edi,DWORD PTR [edx*4+R6GameServiceAddresses::InflateLowBitMasks]
    mov    ecx,DWORD PTR [ebx+0x4]
    and    edi,esi
    mov    ebx,DWORD PTR [esp+0x34]
    add    edi,ecx
    mov    ecx,edx
    shr    esi,cl
    mov    ecx,DWORD PTR [esp+0x18]
    sub    eax,edx
    mov    edx,DWORD PTR [esp+0x24]
    sub    ecx,edx
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,ebp
    sub    ecx,edi
    mov    edi,DWORD PTR [ebx+0x28]
    cmp    ecx,edi
    jae    Branch85
    mov    ebx,DWORD PTR [ebx+0x2c]
    mov    DWORD PTR [esp+0x24],ebx
    sub    ebx,edi
  Branch80:
    add    ecx,ebx
    cmp    ecx,edi
    jb     Branch80
    mov    edi,DWORD PTR [esp+0x24]
    sub    edi,ecx
    cmp    edx,edi
    jbe    Branch83
    sub    edx,edi
  Branch81:
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [ebp+0x0],bl
    inc    ebp
    inc    ecx
    dec    edi
    jne    Branch81
    mov    ecx,DWORD PTR [esp+0x34]
    mov    edi,DWORD PTR [ecx+0x28]
  Branch82:
    mov    cl,BYTE PTR [edi]
    mov    BYTE PTR [ebp+0x0],cl
    inc    ebp
    inc    edi
    dec    edx
    jne    Branch82
    mov    ebx,DWORD PTR [esp+0x14]
    jmp    Branch72
  Branch83:
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [ebp+0x0],bl
    mov    bl,BYTE PTR [ecx+0x1]
    inc    ebp
    inc    ecx
    mov    BYTE PTR [ebp+0x0],bl
    inc    ebp
    inc    ecx
    sub    edx,0x2
  Branch84:
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [ebp+0x0],bl
    inc    ebp
    inc    ecx
    dec    edx
    jne    Branch84
    mov    ebx,DWORD PTR [esp+0x14]
    jmp    Branch72
  Branch85:
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [ebp+0x0],bl
    mov    bl,BYTE PTR [ecx+0x1]
    inc    ebp
    inc    ecx
    mov    BYTE PTR [ebp+0x0],bl
    inc    ebp
    inc    ecx
    sub    edx,0x2
  Branch86:
    mov    bl,BYTE PTR [ecx]
    mov    BYTE PTR [ebp+0x0],bl
    inc    ebp
    inc    ecx
    dec    edx
    jne    Branch86
    mov    ebx,DWORD PTR [esp+0x14]
    jmp    Branch72
  Branch87:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    edi,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [ecx+0x18],R6GameServiceAddresses::TextInvalidDistanceCode
    sub    edx,edi
    mov    edi,eax
    shr    edi,0x3
    cmp    edi,edx
    jae    Branch88
    mov    edx,edi
  Branch88:
    mov    ebx,DWORD PTR [esp+0x34]
    mov    edi,DWORD PTR [esp+0x14]
    sub    edi,edx
    mov    DWORD PTR [ebx+0x20],esi
    lea    esi,[edx*8+0x0]
    sub    eax,esi
    mov    DWORD PTR [ebx+0x1c],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [ecx]
    add    edx,eax
    mov    eax,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,edi
    mov    DWORD PTR [ecx],edi
    sub    edx,esi
    pop    edi
    add    eax,edx
    pop    esi
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [ebx+0x34],ebp
    pop    ebp
    mov    eax,0xfffffffd
    pop    ebx
    add    esp,0x10
    ret    0x18
  Branch89:
    mov    edx,DWORD PTR [esp+0x38]
    mov    edi,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [edx+0x4]
    sub    ecx,edi
    mov    edi,eax
    shr    edi,0x3
    cmp    edi,ecx
    jae    Branch90
    mov    ecx,edi
  Branch90:
    mov    edi,DWORD PTR [esp+0x34]
    sub    ebx,ecx
    mov    DWORD PTR [edi+0x20],esi
    lea    esi,[ecx*8+0x0]
    sub    eax,esi
    mov    DWORD PTR [edi+0x1c],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [edx]
    add    ecx,eax
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,ebx
    mov    DWORD PTR [edx],ebx
    sub    ecx,esi
    add    eax,ecx
    mov    DWORD PTR [edx+0x8],eax
    mov    DWORD PTR [edi+0x34],ebp
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0x10
    ret    0x18
  Branch91:
    mov    edi,DWORD PTR [esp+0x10]
    test   dl,0x20
    je     Branch93
    mov    edx,DWORD PTR [esp+0x38]
    mov    ecx,DWORD PTR [edx+0x4]
    sub    ecx,edi
    mov    edi,eax
    shr    edi,0x3
    cmp    edi,ecx
    jae    Branch92
    mov    ecx,edi
  Branch92:
    mov    edi,DWORD PTR [esp+0x34]
    sub    ebx,ecx
    mov    DWORD PTR [edi+0x20],esi
    lea    esi,[ecx*8+0x0]
    sub    eax,esi
    mov    DWORD PTR [edi+0x1c],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [edx]
    add    ecx,eax
    mov    eax,DWORD PTR [edx+0x8]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,ebx
    mov    DWORD PTR [edx],ebx
    sub    ecx,esi
    add    eax,ecx
    mov    DWORD PTR [edx+0x8],eax
    mov    DWORD PTR [edi+0x34],ebp
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x1
    pop    ebx
    add    esp,0x10
    ret    0x18
  Branch93:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [ecx+0x18],R6GameServiceAddresses::TextInvalidLiteralLengthCode
    sub    edx,edi
    mov    DWORD PTR [esp+0x24],edx
    mov    edx,eax
    mov    edi,DWORD PTR [esp+0x24]
    shr    edx,0x3
    cmp    edx,edi
    jb     Branch94
    mov    edx,edi
  Branch94:
    mov    edi,DWORD PTR [esp+0x34]
    sub    ebx,edx
    mov    DWORD PTR [edi+0x20],esi
    lea    esi,[edx*8+0x0]
    sub    eax,esi
    mov    DWORD PTR [edi+0x1c],eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [ecx]
    add    edx,eax
    mov    eax,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,ebx
    mov    DWORD PTR [ecx],ebx
    sub    edx,esi
    add    eax,edx
    mov    DWORD PTR [ecx+0x8],eax
    mov    DWORD PTR [edi+0x34],ebp
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0xfffffffd
    pop    ebx
    add    esp,0x10
    ret    0x18
  }
}
