#pragma once
#include <cstdint>

extern uint16_t g_systemDirectory[256];
extern uint16_t g_windowsDirectory[256];
extern uint16_t g_moduleFilename[256];
void __cdecl InitializeSystemDirectories();
