#include "native_symbols.hpp"
// Selected executable compiler data identified directly by PE load-configuration metadata.
#include <cstdint>

// RavenShield.exe data @ 1091f0fc : g_executableSecurityCookie
// Supply the selected executable's initial 32-bit security-cookie word.
uint32_t g_executableSecurityCookie = 0xbb40e64e;
