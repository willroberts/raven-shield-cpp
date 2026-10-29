#include "native_symbols.hpp"
// Shared executable ASCII case folding, string hashing, substring search and UTF-16 log-byte narrowing.
#include "allocation_support.hpp"

extern uint32_t GCRCTable[256]; // Core.dll imported array, not a pointer variable to load again.

// RavenShield.exe @ 10902500 : UppercaseAsciiUtf16
// Uppercase ASCII a-z only and return the low input word zero-extended through full EAX.
uint32_t __cdecl UppercaseAsciiUtf16(uint16_t character)
{
  return character >= 'a' && character <= 'z' ? static_cast<uint32_t>(character) - 0x20 : character;
}

// RavenShield.exe @ 10905e20 : LowercaseAsciiUtf16
// Lowercase ASCII A-Z only and return the low input word zero-extended through full EAX.
uint32_t __cdecl LowercaseAsciiUtf16(uint16_t character)
{
  return character >= 'A' && character <= 'Z' ? static_cast<uint32_t>(character) + 0x20 : character;
}

// RavenShield.exe @ 10903280 : NarrowUtf16ToLogByte
// Preserve code units below 256 and map every larger unit to 0x7f, retaining the native zero-extended EAX result.
uint32_t __cdecl NarrowUtf16ToLogByte(uint16_t character)
{
  return character < 0x100 ? character : 0x7f;
}

// RavenShield.exe @ 10902520 : HashCaseInsensitiveUtf16
// Fold ASCII a-z only, then hash each UTF-16 low/high byte with seed zero and no final complement.
uint32_t __cdecl HashCaseInsensitiveUtf16(const uint16_t *text)
{
  uint16_t character = *text;
  uint32_t hash = 0;
  if (character == 0) return hash;
  const uint32_t *table = GCRCTable;
  do
  {
    if (character >= 'a' && character <= 'z') character = static_cast<uint16_t>(character - 0x20);
    ++text;
    hash = (hash >> 8) ^ table[(hash ^ (character & 0xff)) & 0xff];
    hash = (hash >> 8) ^ table[(hash ^ (character >> 8)) & 0xff];
    character = *text;
  } while (character != 0);
  return hash;
}

extern "C" int32_t __cdecl tolower(int32_t character);
extern "C" int32_t __cdecl toupper(int32_t character);
extern "C" char *__cdecl strstr(const char *text, const char *pattern);
extern "C" int32_t __cdecl _strnicmp(const char *left, const char *right, uint32_t count);

// RavenShield.exe @ 1090f1b0 : FindCaseInsensitiveAnsiSubstring
// Find the earliest lower/upper first-byte candidate matching the whole needle; null/empty needles return text.
const char *__cdecl FindCaseInsensitiveAnsiSubstring(const char *text, const char *needle)
{
  char lower[2] = {'x', 0};
  char upper[2] = {'X', 0};
  const char *firstLower = nullptr;
  if (text == nullptr || needle == nullptr || *needle == 0) return text;
  const char *end = needle;
  while (*end != 0) ++end;
  const uint32_t length = reinterpret_cast<uint32_t>(end) - reinterpret_cast<uint32_t>(needle);
  lower[0] = static_cast<char>(tolower(static_cast<int32_t>(static_cast<int8_t>(*needle))));
  const char *candidate = text;
  do
  {
    candidate = strstr(candidate, lower);
    if (candidate == nullptr) break;
    if (_strnicmp(candidate, needle, length) == 0) firstLower = candidate;
    ++candidate;
  } while (firstLower == nullptr);
  upper[0] = static_cast<char>(toupper(static_cast<int32_t>(static_cast<int8_t>(*needle))));
  if (lower[0] != upper[0])
  {
    for (candidate = strstr(text, upper); candidate != nullptr; candidate = strstr(candidate + 1, upper))
    {
      if (_strnicmp(candidate, needle, length) == 0)
      {
        if (firstLower == nullptr || reinterpret_cast<uint32_t>(candidate) < reinterpret_cast<uint32_t>(firstLower))
          return candidate;
        return firstLower;
      }
    }
  }
  return firstLower;
}
