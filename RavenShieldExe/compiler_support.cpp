#include "native_symbols.hpp"
// Original executable compiler helpers retain their native register and stack contracts.

// RavenShield.exe @ 10911be0 : __chkstk
// Probe each crossed 4 KiB stack page and allocate the EAX byte count; preserve ECX and relocate the return address.
__declspec(naked) void __chkstk()
{
  __asm {
    cmp eax, 1000h
    jae probePages
    neg eax
    add eax, esp
    add eax, 4
    test dword ptr [eax], eax
    xchg esp, eax
    mov eax, [eax]
    push eax
    ret
  probePages:
    push ecx
    lea ecx, [esp+8]
  nextPage:
    sub ecx, 1000h
    sub eax, 1000h
    test dword ptr [ecx], eax
    cmp eax, 1000h
    jae nextPage
    sub ecx, eax
    mov eax, esp
    test dword ptr [ecx], eax
    mov esp, ecx
    mov ecx, [eax]
    mov eax, [eax+4]
    push eax
    ret
  }
}
