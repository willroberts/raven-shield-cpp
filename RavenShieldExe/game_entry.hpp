#pragma once
#include <cstdint>

class UEngine;
class WLog;
// Native four-word stdcall entry; only instance is read before the OS-wide command line replaces its stack slot.
int32_t __stdcall GameWinMain(uint32_t instance, uint32_t previousInstance, char *commandLine, int32_t showWindow);
UEngine *__cdecl InitEngine();
void __cdecl MainLoop(UEngine *engine);
void ConstructLaunchLogInline(WLog *storage, uint32_t nameWord);
