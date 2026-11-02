#include "native_addresses.h"

// Shared selected-module cycle clock; the original out-of-line helper identifier is unavailable.

// Converts both unsigned RDTSC halves to scaled seconds plus16777216, retaining inherited x87 precision and rounding.
// R6GameService.dll @ 10005220 : complete native control/access order and raw ABI retained.
__declspec(naked) float10 ReadCycleTimeSeconds(void)
{
  __asm {
    sub    esp,0x8
    rdtsc
    mov    DWORD PTR [esp+0x4],eax
    mov    DWORD PTR [esp],edx
    fild   DWORD PTR [esp]
    mov    eax,DWORD PTR [esp]
    test   eax,eax
    jge    Branch1
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch1:
    mov    ecx,DWORD PTR [esp+0x4]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   ecx,ecx
    fild   DWORD PTR [esp+0x4]
    jge    Branch2
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch2:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    fmul   QWORD PTR [edx]
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    add    esp,0x8
    ret
  }
}
