#include "native_symbols.hpp"
// Native timestamp reads and x87 cycle-to-seconds conversion used by engine initialization and the main loop.
#include "timing_support.hpp"

// RavenShield.exe data @ 10914988 : g_timestampSecondsBias
const double g_timestampSecondsBias = 16777216.0;
// RavenShield.exe data @ 10914990 : g_timestampWordScale
const double g_timestampWordScale = 4294967296.0;

// RavenShield.exe @ 109019d0 : ReadTimestampCounter
// Read the timestamp into EDX:EAX; both observed callers consume only the low EAX word.
__declspec(naked) uint64_t __cdecl ReadTimestampCounter()
{
  __asm {
    rdtsc
    ret
  }
}

// RavenShield.exe @ 109019e0 : ReadTimestampSeconds
// Convert unsigned timestamp halves in x87, multiply by imported GSecondsPerCycle, and add the fixed time bias.
__declspec(naked) double __cdecl ReadTimestampSeconds()
{
  __asm {
    sub esp, 8
    rdtsc
    mov [esp+4], eax
    mov [esp], edx
    fild dword ptr [esp]
    mov eax, [esp]
    test eax, eax
    jge highUnsigned
    fadd qword ptr [g_timestampWordScale]
  highUnsigned:
    mov ecx, [esp+4]
    fmul qword ptr [g_timestampWordScale]
    test ecx, ecx
    fild dword ptr [esp+4]
    jge lowUnsigned
    fadd qword ptr [g_timestampWordScale]
  lowUnsigned:
    mov edx, dword ptr [NativeImport_GSecondsPerCycle]
    faddp st(1), st
    fmul qword ptr [edx]
    fadd qword ptr [g_timestampSecondsBias]
    add esp, 8
    ret
  }
}
