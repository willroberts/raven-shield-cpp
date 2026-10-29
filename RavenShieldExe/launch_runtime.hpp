#pragma once
#include <cstdint>

// Backing storage retains native x86 extents while class declarations remain partial.
class FMallocWindows;
class FFeedbackContextWindows;
class FOutputDeviceFile;
using ImportedBaseConstructor = void(__thiscall *)(void *);
using LaunchTerminationRoutine = void(__cdecl *)();
extern uint8_t g_launchAllocatorStorage[0x2069c];
extern uint8_t g_launchErrorStorage[0xc];
extern uint8_t g_launchFileLogStorage[0x810];
extern uint8_t g_launchFeedbackStorage[0x18];
extern uint8_t g_launchFileManagerStorage[4];
extern uint8_t g_launchExecHookStorage[12];
extern const char g_unEngineWinSourcePath[];
extern const char16_t g_unwindContextFormat[];
void __cdecl InitializeLaunchAllocator();
void __cdecl InitializeLaunchFileLog();
void __cdecl InitializeLaunchErrorDevice();
void __cdecl InitializeLaunchFeedback();
void __cdecl InitializeLaunchFileManager();
void __cdecl DestroyLaunchFileLog();
int32_t __cdecl RegisterExecutableAtExit(LaunchTerminationRoutine callback);
void ConstructLaunchExecHookInline(); // Source-only sequence in InitEngine, owned by FExecHook.
