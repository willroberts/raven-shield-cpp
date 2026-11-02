#include "native_addresses.h"

// Native SHA1 compression has an explicit state pointer and unused ECX; unique original class ownership is unassigned.
// The 0x4c-byte frame has three spills at EntryESP-0x4c..-0x44 and a 16-word schedule at EntryESP-0x40..-4.

// Executes 80 SHA1 rounds with native lazy message reads, ring updates, argument-slot spills and ordered feed-forward.
// R6GameService.dll @ 1003a270 : ECX unused, state/message stack words, RET8; EAX=updated fifth state word.
__declspec(naked) uint __thiscall CompressSha1Block(
    void *unusedContext,uint *state,const uint *messageWords)
{
  __asm {
    sub    esp,0x4c
    mov    eax,DWORD PTR [esp+0x54]
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x5c]
    mov    edx,DWORD PTR [eax]
    push   edi
    mov    DWORD PTR [esp+0x1c],edx
    mov    edi,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esi+0xc]
    mov    ebx,DWORD PTR [esi+0x4]
    mov    edx,edi
    mov    ebp,edi
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esi+0x8]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esi+0xc]
    and    ecx,ebx
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esi+0x10]
    add    ebp,edx
    mov    edx,DWORD PTR [esp+0x1c]
    add    ecx,ebp
    // Rounds 0..19 use choose and constant 0x5a827999.
    lea    ecx,[ecx+edx*1+0x5a827999]
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [esp+0x20],ebx
    mov    ebx,ecx
    mov    ebp,ecx
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,DWORD PTR [esi+0x8]
    xor    ebp,edx
    and    ebp,edi
    mov    edi,DWORD PTR [esi+0x8]
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x20]
    add    edi,ebx
    mov    ebx,DWORD PTR [esi]
    add    ebp,edi
    mov    edi,DWORD PTR [esi+0xc]
    lea    ebp,[edi+ebp*1+0x5a827999]
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [esp+0x24],ebx
    mov    ebx,ebp
    mov    DWORD PTR [esp+0x10],ebp
    mov    DWORD PTR [esp+0x60],edi
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,edx
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x24]
    and    ebp,ecx
    add    edi,ebx
    xor    ebp,edx
    mov    ebx,ecx
    add    ebp,edi
    mov    edi,DWORD PTR [esi+0x8]
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [eax+0xc]
    lea    edi,[edi+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x28],ecx
    mov    ecx,edi
    mov    ebp,edi
    shr    ecx,0x1b
    shl    ebp,0x5
    mov    DWORD PTR [esp+0x14],ebx
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    add    ebp,ecx
    add    ebx,ebp
    lea    edx,[edx+ebx*1+0x5a827999]
    mov    ebx,DWORD PTR [esp+0x10]
    mov    ecx,ebx
    mov    ebp,edx
    shl    ecx,0x1e
    shr    ebx,0x2
    or     ecx,ebx
    mov    ebx,DWORD PTR [eax+0x10]
    mov    DWORD PTR [esp+0x2c],ebx
    mov    ebx,edx
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,DWORD PTR [esp+0x14]
    xor    ebp,ecx
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    and    ebp,edi
    xor    ebp,ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    add    ecx,ebx
    mov    ebx,edi
    add    ebp,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [eax+0x14]
    lea    ecx,[ecx+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x30],edi
    mov    edi,ecx
    mov    ebp,ecx
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebx,DWORD PTR [esp+0x10]
    and    ebp,edx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x14]
    add    ebp,ebx
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [eax+0x18]
    lea    edi,[edi+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x34],edx
    mov    edx,edi
    mov    ebp,edi
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x18]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebx,DWORD PTR [esp+0x18]
    and    ebp,ecx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x34]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x10]
    add    ebp,ebx
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    lea    edx,[edx+ebp*1+0x5a827999]
    or     ebx,ecx
    mov    ecx,DWORD PTR [eax+0x1c]
    mov    ebp,edx
    mov    DWORD PTR [esp+0x38],ecx
    mov    ecx,edx
    shr    ecx,0x1b
    shl    ebp,0x5
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x64]
    and    ebp,edi
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x38]
    add    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    add    ebp,ebx
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [eax+0x20]
    lea    ecx,[ecx+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x3c],edi
    mov    ebp,ecx
    mov    edi,ecx
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x14],ebx
    xor    ebx,edi
    and    ebx,edx
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x3c]
    add    edi,ebp
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    lea    edi,[edi+ebx*1+0x5a827999]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [eax+0x24]
    mov    DWORD PTR [esp+0x40],edx
    mov    edx,edi
    mov    ebp,edi
    mov    DWORD PTR [esp+0x10],ebx
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x14]
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    and    ebp,ecx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x40]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x60]
    add    ebp,ebx
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [eax+0x28]
    lea    edx,[edx+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x44],ecx
    mov    ecx,edx
    mov    ebp,edx
    shr    ecx,0x1b
    shl    ebp,0x5
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebx,DWORD PTR [esp+0x10]
    and    ebp,edi
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    add    ebx,ecx
    add    ebp,ebx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [eax+0x2c]
    lea    ecx,[ecx+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x48],edi
    mov    edi,ecx
    mov    ebp,ecx
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x18]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebx,DWORD PTR [esp+0x18]
    and    ebp,edx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x10]
    add    ebp,ebx
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [eax+0x30]
    lea    edi,[edi+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x4c],edx
    mov    edx,edi
    mov    ebp,edi
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x64]
    and    ebp,ecx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x4c]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x18]
    add    ebp,ebx
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [eax+0x34]
    lea    edx,[edx+ebp*1+0x5a827999]
    mov    DWORD PTR [esp+0x50],ecx
    mov    ebp,edx
    mov    ecx,edx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x14],ebx
    xor    ebx,ecx
    and    ebx,edi
    xor    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x50]
    add    ecx,ebp
    add    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    lea    ebp,[ecx+ebx*1+0x5a827999]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,ebp
    mov    DWORD PTR [esp+0x64],ebp
    mov    ecx,DWORD PTR [eax+0x38]
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x14]
    xor    ebp,ebx
    mov    DWORD PTR [esp+0x10],ebx
    and    ebp,edx
    mov    ebx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [eax+0x3c]
    xor    ebp,ebx
    mov    ebx,ecx
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x60]
    add    ebp,ebx
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    lea    edi,[edi+ebp*1+0x5a827999]
    or     ebx,edx
    mov    ebp,DWORD PTR [esp+0x64]
    mov    edx,edi
    mov    DWORD PTR [esp+0x60],edi
    mov    DWORD PTR [esp+0x18],ebx
    shr    edx,0x1b
    shl    edi,0x5
    or     edx,edi
    mov    edi,DWORD PTR [esp+0x10]
    xor    edi,ebx
    and    edi,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    edi,ebp
    mov    ebp,eax
    add    ebp,edx
    mov    edx,DWORD PTR [esp+0x14]
    add    edi,ebp
    lea    ebp,[edx+edi*1+0x5a827999]
    mov    edx,DWORD PTR [esp+0x64]
    mov    edi,edx
    mov    DWORD PTR [esp+0x14],ebp
    shl    edi,0x1e
    shr    edx,0x2
    or     edi,edx
    mov    edx,DWORD PTR [esp+0x3c]
    mov    DWORD PTR [esp+0x64],edi
    // W16 = ROL1(W13 ^ W8 ^ W2 ^ W0); subsequent words reuse the ring and live register slots.
    mov    edi,DWORD PTR [esp+0x50]
    xor    edi,edx
    mov    edx,DWORD PTR [esp+0x24]
    xor    edi,edx
    mov    edx,DWORD PTR [esp+0x1c]
    xor    edi,edx
    mov    edx,edi
    add    edi,edi
    shr    edx,0x1f
    or     edx,edi
    mov    edi,ebp
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    and    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x18]
    xor    ebx,ebp
    mov    ebp,edx
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    lea    edi,[edi+ebx*1+0x5a827999]
    mov    DWORD PTR [esp+0x10],edi
    mov    edi,DWORD PTR [esp+0x60]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,ecx
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    DWORD PTR [esp+0x20],ebp
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebp,edi
    shl    edi,0x5
    shr    ebp,0x1b
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    and    edi,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x20]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    lea    edi,[ebx+edi*1+0x5a827999]
    mov    DWORD PTR [esp+0x18],edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,eax
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x24],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x10]
    and    ebx,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x24]
    add    edi,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    lea    edi,[edi+ebx*1+0x5a827999]
    mov    DWORD PTR [esp+0x64],edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x48]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x10],ebx
    xor    edi,edx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x28],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    and    edi,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x28]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    edi,[ebx+edi*1+0x5a827999]
    mov    DWORD PTR [esp+0x60],edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x4c]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x2c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    // Rounds 20..39 use parity and constant 0x6ed9eba1.
    lea    edi,[ebx+edi*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x14],edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x50]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x30],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    add    ebx,ebp
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+edi*1+0x6ed9eba1]
    mov    edi,DWORD PTR [esp+0x60]
    mov    ebx,edi
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x34]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x28]
    xor    edi,ebx
    mov    ebx,edi
    add    edi,edi
    shr    ebx,0x1f
    or     ebx,edi
    mov    edi,ebp
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x34],ebx
    mov    ebx,DWORD PTR [esp+0x14]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    lea    edi,[edi+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x18],edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,eax
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x38],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x38]
    add    edi,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    lea    edi,[edi+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x64],edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x44]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x10],ebx
    xor    edi,edx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x3c],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    edi,[ebx+edi*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x60],edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x48]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x40],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x40]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    edi,[ebx+edi*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x14],edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x4c]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x44],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    add    ebx,ebp
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+edi*1+0x6ed9eba1]
    mov    edi,DWORD PTR [esp+0x60]
    mov    ebx,edi
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x50]
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x48]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x28]
    xor    edi,ebx
    mov    ebx,edi
    add    edi,edi
    shr    ebx,0x1f
    or     ebx,edi
    mov    edi,ebp
    shr    edi,0x1b
    shl    ebp,0x5
    or     edi,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x48],ebx
    mov    ebx,DWORD PTR [esp+0x14]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    lea    edi,[edi+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x18],edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,ecx
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x4c],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x4c]
    add    edi,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    add    ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    lea    edi,[edi+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x64],edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebx,edi
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,eax
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x50],ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    add    ebx,ebp
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    ebp,[ebx+edi*1+0x6ed9eba1]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    edi,ebx
    mov    DWORD PTR [esp+0x60],ebp
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x34]
    xor    ecx,ebx
    mov    DWORD PTR [esp+0x18],edi
    xor    ecx,edx
    mov    ebx,ecx
    shr    ecx,0x1f
    add    ebx,ebx
    or     ecx,ebx
    mov    ebx,ebp
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    xor    ebp,edi
    mov    edi,ecx
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    lea    ebp,[edi+ebp*1+0x6ed9eba1]
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x4c]
    xor    eax,ebx
    mov    ebx,DWORD PTR [esp+0x38]
    xor    eax,ebx
    mov    ebx,DWORD PTR [esp+0x20]
    xor    eax,ebx
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebx,eax
    mov    DWORD PTR [esp+0x64],edi
    shr    eax,0x1f
    add    ebx,ebx
    or     eax,ebx
    mov    ebx,ebp
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,DWORD PTR [esp+0x18]
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebp,edi
    mov    edi,eax
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    lea    ebp,[edi+ebp*1+0x6ed9eba1]
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [esp+0x60],edi
    mov    edi,DWORD PTR [esp+0x3c]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x24]
    xor    ebx,edi
    mov    DWORD PTR [esp+0x10],ebp
    xor    ebx,edx
    mov    edi,ebx
    lea    edx,[ebx+ebx*1]
    shr    edi,0x1f
    mov    ebx,DWORD PTR [esp+0x14]
    or     edi,edx
    mov    edx,ebp
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,edi
    add    ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    lea    edx,[edx+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x18],edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,ecx
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x20],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x10]
    xor    ebx,edx
    mov    edx,DWORD PTR [esp+0x60]
    xor    ebx,edx
    mov    edx,DWORD PTR [esp+0x20]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x64]
    lea    edx,[edx+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x64],edx
    mov    edx,DWORD PTR [esp+0x10]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,eax
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x24],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x14]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x24]
    add    ebx,ebp
    add    edx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    mov    ebp,DWORD PTR [esp+0x30]
    lea    edx,[ebx+edx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x60],edx
    mov    edx,DWORD PTR [esp+0x18]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x48]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x18],ebx
    xor    edx,edi
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x28],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x10]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x28]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    edx,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    edx,[ebx+edx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x14],edx
    mov    edx,DWORD PTR [esp+0x64]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x4c]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x2c]
    add    ebx,ebp
    add    edx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+edx*1+0x6ed9eba1]
    mov    edx,DWORD PTR [esp+0x60]
    mov    ebx,edx
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x38]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x24]
    xor    edx,ebx
    mov    ebx,edx
    add    edx,edx
    shr    ebx,0x1f
    or     ebx,edx
    mov    edx,ebp
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x30],ebx
    mov    ebx,DWORD PTR [esp+0x14]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    add    ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    lea    edx,[edx+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x18],edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,ecx
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x34],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x10]
    xor    ebx,edx
    mov    edx,DWORD PTR [esp+0x60]
    xor    ebx,edx
    mov    edx,DWORD PTR [esp+0x34]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x64]
    lea    edx,[edx+ebx*1+0x6ed9eba1]
    mov    DWORD PTR [esp+0x64],edx
    mov    edx,DWORD PTR [esp+0x10]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,eax
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    edx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edx,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,edx
    add    edx,edx
    shr    ebp,0x1f
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x38],ebp
    mov    ebp,edx
    shr    ebp,0x1b
    shl    edx,0x5
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x14]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x38]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    edx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    edx,[ebx+edx*1+0x6ed9eba1]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x60],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x18],edx
    xor    ebx,edi
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x3c],ebp
    mov    ebp,edx
    or     ebp,ebx
    and    edx,ebx
    and    ebp,DWORD PTR [esp+0x10]
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x60]
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x3c]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x14]
    // Rounds 40..59 use majority and constant 0x8f1bbcdc.
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x14],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x64],edx
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x40],ebp
    mov    ebp,edx
    or     ebp,ebx
    and    edx,ebx
    and    ebp,DWORD PTR [esp+0x18]
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x14]
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x40]
    add    edx,ebp
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x10]
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x10],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    DWORD PTR [esp+0x60],edx
    mov    ebx,DWORD PTR [esp+0x4c]
    mov    ebp,DWORD PTR [esp+0x44]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ebx,ebp
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x44],ebp
    mov    ebp,ebx
    or     ebp,edx
    and    ebx,edx
    and    ebp,DWORD PTR [esp+0x64]
    mov    edx,DWORD PTR [esp+0x10]
    or     ebp,ebx
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x44]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x18]
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x18],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x14],edx
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x48],ebp
    mov    ebp,edx
    or     ebp,ebx
    and    edx,ebx
    and    ebp,DWORD PTR [esp+0x60]
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x48]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x64]
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x64],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,ecx
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x10],edx
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x4c],ebp
    mov    ebp,edx
    and    edx,ebx
    or     ebp,ebx
    and    ebp,DWORD PTR [esp+0x14]
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x64]
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x4c]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x50]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x60]
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x60],edx
    mov    edx,ebx
    shl    edx,0x1e
    shr    ebx,0x2
    or     edx,ebx
    mov    ebx,eax
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x18],edx
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x50],ebp
    mov    ebp,edx
    or     ebp,ebx
    and    edx,ebx
    and    ebp,DWORD PTR [esp+0x10]
    or     ebp,edx
    mov    edx,DWORD PTR [esp+0x60]
    mov    ebx,edx
    shr    ebx,0x1b
    shl    edx,0x5
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x50]
    add    edx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    add    ebx,edx
    mov    edx,DWORD PTR [esp+0x14]
    lea    edx,[edx+ebx*1-0x70e44324]
    mov    DWORD PTR [esp+0x14],edx
    mov    edx,DWORD PTR [esp+0x64]
    mov    ebx,edx
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x48]
    xor    ecx,edx
    mov    DWORD PTR [esp+0x64],ebx
    xor    ecx,ebp
    mov    ebp,ebx
    xor    ecx,edi
    mov    edx,ecx
    add    ecx,ecx
    shr    edx,0x1f
    or     edx,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    or     ebp,ecx
    and    ebx,ecx
    and    ebp,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    or     ebp,ebx
    mov    ebx,ecx
    shr    ebx,0x1b
    shl    ecx,0x5
    or     ebx,ecx
    mov    ecx,edx
    add    ecx,ebp
    add    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    ebp,DWORD PTR [esp+0x38]
    lea    ecx,[ecx+ebx*1-0x70e44324]
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,DWORD PTR [esp+0x60]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x4c]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esp+0x20]
    xor    eax,ebp
    mov    DWORD PTR [esp+0x60],ebx
    xor    eax,ecx
    mov    ecx,eax
    add    eax,eax
    shr    ecx,0x1f
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    ebp,eax
    and    eax,ebx
    or     ebp,ebx
    and    ebp,DWORD PTR [esp+0x64]
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    ebx,eax
    shr    ebx,0x1b
    shl    eax,0x5
    or     ebx,eax
    mov    eax,ecx
    add    eax,ebp
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x18]
    lea    eax,[eax+ebx*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x14]
    mov    ebp,ebx
    shl    ebp,0x1e
    shr    ebx,0x2
    or     ebp,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    mov    DWORD PTR [esp+0x14],ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ebx,ebp
    xor    ebx,edi
    mov    edi,ebx
    add    ebx,ebx
    shr    edi,0x1f
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x1c],edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebp,ebx
    and    ebx,edi
    or     ebp,edi
    mov    edi,eax
    and    ebp,DWORD PTR [esp+0x60]
    shr    edi,0x1b
    or     ebp,ebx
    mov    ebx,eax
    shl    ebx,0x5
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    lea    edi,[ebx+edi*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x64],edi
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,edx
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esp+0x10],edi
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ebx,ebp
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,edi
    mov    DWORD PTR [esp+0x20],ebp
    mov    ebp,DWORD PTR [esp+0x14]
    or     ebx,eax
    and    edi,eax
    and    ebx,ebp
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x20]
    add    edi,ebx
    mov    ebx,eax
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    shl    ebx,0x1e
    shr    eax,0x2
    or     ebx,eax
    lea    edi,[edi+ebp*1-0x70e44324]
    mov    ebp,DWORD PTR [esp+0x44]
    mov    eax,ecx
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    eax,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,eax
    add    eax,eax
    shr    ebp,0x1f
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x24],ebp
    mov    ebp,ebx
    or     ebp,eax
    and    ebx,eax
    and    ebp,DWORD PTR [esp+0x10]
    mov    eax,edi
    shr    eax,0x1b
    or     ebp,ebx
    mov    ebx,edi
    shl    ebx,0x5
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x24]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    add    eax,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    eax,[ebx+eax*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,ebx
    shl    eax,0x1e
    shr    ebx,0x2
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x1c]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x64],eax
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,eax
    mov    DWORD PTR [esp+0x28],ebp
    mov    ebp,DWORD PTR [esp+0x18]
    or     ebx,edi
    and    ebx,ebp
    and    eax,edi
    or     ebx,eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    ebp,eax
    shr    ebp,0x1b
    shl    eax,0x5
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x28]
    add    eax,ebx
    mov    ebx,edi
    add    ebp,eax
    mov    eax,DWORD PTR [esp+0x10]
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x4c]
    lea    eax,[eax+ebp*1-0x70e44324]
    mov    ebp,DWORD PTR [esp+0x34]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebp,edi
    add    edi,edi
    shr    ebp,0x1f
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebp,edi
    or     ebp,ebx
    and    edi,ebx
    and    ebp,DWORD PTR [esp+0x64]
    mov    ebx,eax
    shl    ebx,0x5
    or     ebp,edi
    mov    edi,eax
    shr    edi,0x1b
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x2c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    lea    edi,[ebx+edi*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x18],edi
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x14],edi
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,edi
    mov    DWORD PTR [esp+0x30],ebp
    mov    ebp,DWORD PTR [esp+0x60]
    or     ebx,eax
    and    edi,eax
    and    ebx,ebp
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x30]
    add    edi,ebx
    mov    ebx,eax
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x64]
    shl    ebx,0x1e
    lea    edi,[edi+ebp*1-0x70e44324]
    mov    ebp,DWORD PTR [esp+0x3c]
    shr    eax,0x2
    or     ebx,eax
    mov    eax,edx
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    eax,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,eax
    add    eax,eax
    shr    ebp,0x1f
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x34],ebp
    mov    ebp,ebx
    or     ebp,eax
    and    ebx,eax
    and    ebp,DWORD PTR [esp+0x14]
    mov    eax,edi
    shr    eax,0x1b
    or     ebp,ebx
    mov    ebx,edi
    shl    ebx,0x5
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x34]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    eax,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    eax,[ebx+eax*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x60],eax
    mov    eax,ebx
    shl    eax,0x1e
    shr    ebx,0x2
    or     eax,ebx
    mov    ebx,ecx
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x18],eax
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,eax
    mov    DWORD PTR [esp+0x38],ebp
    mov    ebp,DWORD PTR [esp+0x10]
    or     ebx,edi
    and    eax,edi
    and    ebx,ebp
    or     ebx,eax
    mov    eax,DWORD PTR [esp+0x60]
    mov    ebp,eax
    shr    ebp,0x1b
    shl    eax,0x5
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x38]
    add    eax,ebx
    mov    ebx,edi
    add    ebp,eax
    mov    eax,DWORD PTR [esp+0x14]
    shl    ebx,0x1e
    shr    edi,0x2
    lea    eax,[eax+ebp*1-0x70e44324]
    mov    ebp,DWORD PTR [esp+0x3c]
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x44]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    edi,ebp
    mov    ebp,DWORD PTR [esp+0x1c]
    xor    edi,ebp
    mov    DWORD PTR [esp+0x64],ebx
    mov    ebp,edi
    shr    ebp,0x1f
    add    edi,edi
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x3c],ebp
    mov    ebp,ebx
    or     ebp,edi
    and    ebx,edi
    and    ebp,DWORD PTR [esp+0x18]
    mov    edi,eax
    shr    edi,0x1b
    or     ebp,ebx
    mov    ebx,eax
    shl    ebx,0x5
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    edi,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    edi,[ebx+edi*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x10],edi
    mov    edi,ebx
    shl    edi,0x1e
    shr    ebx,0x2
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x60],edi
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,eax
    mov    DWORD PTR [esp+0x40],ebp
    mov    ebp,DWORD PTR [esp+0x64]
    or     ebx,edi
    and    ebx,ebp
    mov    ebp,eax
    and    ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    or     ebx,ebp
    mov    ebp,edi
    shr    ebp,0x1b
    shl    edi,0x5
    or     ebp,edi
    mov    edi,DWORD PTR [esp+0x40]
    add    edi,ebx
    mov    ebx,eax
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    shl    ebx,0x1e
    shr    eax,0x2
    lea    edi,[edi+ebp*1-0x70e44324]
    mov    ebp,DWORD PTR [esp+0x44]
    or     ebx,eax
    mov    eax,DWORD PTR [esp+0x4c]
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    eax,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,eax
    add    eax,eax
    shr    ebp,0x1f
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x44],ebp
    mov    ebp,ebx
    or     ebp,eax
    and    ebx,eax
    and    ebp,DWORD PTR [esp+0x60]
    mov    eax,edi
    shr    eax,0x1b
    or     ebp,ebx
    mov    ebx,edi
    shl    ebx,0x5
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    add    eax,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    lea    eax,[ebx+eax*1-0x70e44324]
    mov    ebx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x64],eax
    mov    eax,ebx
    shl    eax,0x1e
    shr    ebx,0x2
    or     eax,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ebx,ebp
    mov    DWORD PTR [esp+0x10],eax
    mov    ebp,ebx
    add    ebx,ebx
    shr    ebp,0x1f
    or     ebp,ebx
    mov    ebx,eax
    mov    DWORD PTR [esp+0x48],ebp
    mov    ebp,DWORD PTR [esp+0x14]
    or     ebx,edi
    and    eax,edi
    and    ebx,ebp
    or     ebx,eax
    mov    eax,DWORD PTR [esp+0x64]
    mov    ebp,eax
    shr    ebp,0x1b
    shl    eax,0x5
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x48]
    add    eax,ebx
    mov    ebx,edi
    add    ebp,eax
    mov    eax,DWORD PTR [esp+0x60]
    shl    ebx,0x1e
    shr    edi,0x2
    lea    ebp,[eax+ebp*1-0x70e44324]
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x4c]
    mov    eax,edx
    xor    eax,edi
    mov    edi,DWORD PTR [esp+0x40]
    xor    eax,edi
    mov    edi,DWORD PTR [esp+0x2c]
    xor    eax,edi
    mov    DWORD PTR [esp+0x60],ebp
    mov    edi,eax
    add    eax,eax
    shr    edi,0x1f
    or     edi,eax
    mov    eax,ebp
    shr    eax,0x1b
    shl    ebp,0x5
    or     eax,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x18],ebx
    xor    ebp,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    ebp,ebx
    mov    ebx,edi
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x14]
    add    ebp,ebx
    // Rounds 60..79 use parity and constant 0xca62c1d6.
    lea    eax,[eax+ebp*1-0x359d3e2a]
    mov    ebp,DWORD PTR [esp+0x50]
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esp+0x64]
    mov    ebx,eax
    shl    ebx,0x1e
    shr    eax,0x2
    or     ebx,eax
    mov    eax,ecx
    mov    DWORD PTR [esp+0x64],ebx
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    xor    ecx,edi
    xor    eax,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    eax,ebp
    mov    ebp,eax
    add    eax,eax
    shr    ebp,0x1f
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x50],ebp
    mov    ebp,eax
    shr    ebp,0x1b
    shl    eax,0x5
    or     ebp,eax
    mov    eax,DWORD PTR [esp+0x18]
    xor    eax,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    eax,ebx
    mov    ebx,DWORD PTR [esp+0x50]
    add    ebx,ebp
    add    eax,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+eax*1-0x359d3e2a]
    mov    eax,DWORD PTR [esp+0x60]
    mov    ebx,eax
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    eax,0x2
    or     ebx,eax
    mov    eax,DWORD PTR [esp+0x48]
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x34]
    xor    edx,eax
    mov    eax,DWORD PTR [esp+0x1c]
    xor    edx,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    xor    edx,eax
    mov    eax,edx
    add    edx,edx
    shr    eax,0x1f
    or     eax,edx
    mov    edx,ebp
    shr    edx,0x1b
    shl    ebp,0x5
    or     edx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,eax
    add    ebp,edx
    mov    edx,DWORD PTR [esp+0x18]
    add    ebx,ebp
    lea    ebp,[edx+ebx*1-0x359d3e2a]
    mov    edx,DWORD PTR [esp+0x14]
    mov    ebx,edx
    mov    DWORD PTR [esp+0x18],ebp
    shl    ebx,0x1e
    shr    edx,0x2
    or     ebx,edx
    mov    edx,DWORD PTR [esp+0x38]
    xor    ecx,edx
    mov    edx,DWORD PTR [esp+0x20]
    xor    ecx,edx
    mov    DWORD PTR [esp+0x14],ebx
    mov    edx,ecx
    add    ecx,ecx
    shr    edx,0x1f
    or     edx,ecx
    mov    ecx,ebp
    shr    ecx,0x1b
    shl    ebp,0x5
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,edx
    add    ebp,ecx
    add    ebx,ebp
    mov    ecx,DWORD PTR [esp+0x64]
    mov    ebp,DWORD PTR [esp+0x3c]
    lea    ecx,[ecx+ebx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x64],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    shr    ecx,0x2
    shl    ebx,0x1e
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x50]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x1c]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x1c],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x60],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,eax
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x20],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x20]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,edx
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    mov    DWORD PTR [esp+0x64],ebx
    xor    ecx,ebp
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x24],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x24]
    add    ebx,ebp
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+ecx*1-0x359d3e2a]
    mov    ecx,DWORD PTR [esp+0x60]
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x30]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x28]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    xor    ecx,ebx
    mov    ebx,ecx
    add    ecx,ecx
    shr    ebx,0x1f
    or     ebx,ecx
    mov    ecx,ebp
    shr    ecx,0x1b
    shl    ebp,0x5
    mov    DWORD PTR [esp+0x28],ebx
    mov    ebx,DWORD PTR [esp+0x14]
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    add    ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    lea    ecx,[ecx+ebx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,edi
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    xor    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    xor    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    add    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    lea    ecx,[ecx+ebx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x64],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x50]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x30]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x30],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x60],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,eax
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x34],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x34]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,edx
    mov    DWORD PTR [esp+0x64],ebx
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x2c]
    xor    ecx,ebp
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x38],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x38]
    add    ebx,ebp
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x10]
    lea    ebp,[ebx+ecx*1-0x359d3e2a]
    mov    ecx,DWORD PTR [esp+0x60]
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x44]
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x3c]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x1c]
    xor    ecx,ebx
    mov    ebx,ecx
    add    ecx,ecx
    shr    ebx,0x1f
    or     ebx,ecx
    mov    ecx,ebp
    shr    ecx,0x1b
    shl    ebp,0x5
    mov    DWORD PTR [esp+0x3c],ebx
    mov    ebx,DWORD PTR [esp+0x14]
    or     ecx,ebp
    mov    ebp,DWORD PTR [esp+0x64]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    add    ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x40]
    lea    ecx,[ecx+ebx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x48]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x34]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x20]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x14],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x40],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    xor    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    xor    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x40]
    add    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x44]
    add    ebx,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    lea    ecx,[ecx+ebx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x64],ecx
    mov    ecx,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,edi
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x38]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x24]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x44],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x14]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    add    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x48]
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x60]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    DWORD PTR [esp+0x60],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    ebx,ecx
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x50]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x3c]
    xor    ecx,ebp
    mov    ebp,DWORD PTR [esp+0x28]
    xor    ecx,ebp
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebp,ecx
    add    ecx,ecx
    shr    ebp,0x1f
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x60]
    mov    DWORD PTR [esp+0x48],ebp
    mov    ebp,ecx
    shr    ebp,0x1b
    shl    ecx,0x5
    or     ebp,ecx
    mov    ecx,DWORD PTR [esp+0x10]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x64]
    xor    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x48]
    add    ebx,ebp
    add    ecx,ebx
    mov    ebx,DWORD PTR [esp+0x14]
    lea    ecx,[ebx+ecx*1-0x359d3e2a]
    mov    ebx,DWORD PTR [esp+0x64]
    mov    ebp,ebx
    shl    ebp,0x1e
    shr    ebx,0x2
    or     ebp,ebx
    mov    ebx,eax
    mov    DWORD PTR [esp+0x64],ebp
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x40]
    xor    ebx,edi
    mov    edi,DWORD PTR [esp+0x2c]
    xor    ebx,edi
    mov    edi,ebx
    add    ebx,ebx
    shr    edi,0x1f
    or     edi,ebx
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x4c],edi
    mov    edi,ecx
    shr    edi,0x1b
    shl    ebx,0x5
    or     edi,ebx
    mov    ebx,DWORD PTR [esp+0x18]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x60]
    xor    ebx,ebp
    mov    ebp,DWORD PTR [esp+0x4c]
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x10]
    add    ebx,ebp
    lea    ebp,[edi+ebx*1-0x359d3e2a]
    mov    edi,DWORD PTR [esp+0x60]
    mov    ebx,edi
    mov    DWORD PTR [esp+0x10],ebp
    shl    ebx,0x1e
    shr    edi,0x2
    or     ebx,edi
    mov    edi,edx
    mov    DWORD PTR [esp+0x60],ebx
    mov    ebx,DWORD PTR [esp+0x50]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x44]
    xor    edi,ebx
    mov    ebx,DWORD PTR [esp+0x30]
    xor    edi,ebx
    mov    ebx,edi
    add    edi,edi
    shr    ebx,0x1f
    or     ebx,edi
    mov    edi,DWORD PTR [esp+0x64]
    mov    DWORD PTR [esp+0x50],ebx
    mov    ebx,ebp
    shr    ebx,0x1b
    shl    ebp,0x5
    or     ebx,ebp
    mov    ebp,ecx
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x60]
    xor    ebp,edi
    mov    edi,DWORD PTR [esp+0x50]
    add    edi,ebx
    mov    ebx,ecx
    add    ebp,edi
    mov    edi,DWORD PTR [esp+0x18]
    shl    ebx,0x1e
    shr    ecx,0x2
    or     ebx,ecx
    mov    ecx,DWORD PTR [esp+0x48]
    lea    edi,[edi+ebp*1-0x359d3e2a]
    mov    ebp,DWORD PTR [esp+0x34]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    xor    eax,ebp
    mov    ebp,ebx
    xor    eax,ecx
    mov    ecx,eax
    add    eax,eax
    shr    ecx,0x1f
    or     ecx,eax
    mov    eax,edi
    mov    DWORD PTR [esp+0x54],ecx
    mov    ecx,edi
    shr    ecx,0x1b
    shl    eax,0x5
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x10]
    xor    ebp,eax
    mov    eax,DWORD PTR [esp+0x60]
    xor    ebp,eax
    mov    eax,DWORD PTR [esp+0x54]
    add    eax,ecx
    mov    ecx,DWORD PTR [esp+0x64]
    add    ebp,eax
    mov    eax,DWORD PTR [esp+0x10]
    lea    ebp,[ecx+ebp*1-0x359d3e2a]
    mov    ecx,eax
    shl    ecx,0x1e
    shr    eax,0x2
    or     ecx,eax
    mov    eax,DWORD PTR [esp+0x4c]
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,DWORD PTR [esp+0x38]
    xor    edx,eax
    mov    eax,DWORD PTR [esp+0x20]
    xor    edx,ecx
    mov    ecx,ebp
    xor    edx,eax
    mov    eax,edx
    add    edx,edx
    shr    eax,0x1f
    or     eax,edx
    mov    edx,ebp
    shr    ecx,0x1b
    shl    edx,0x5
    or     ecx,edx
    mov    edx,ebx
    xor    edx,DWORD PTR [esp+0x10]
    add    eax,ecx
    xor    edx,edi
    add    edx,eax
    mov    eax,DWORD PTR [esp+0x60]
    lea    ecx,[eax+edx*1-0x359d3e2a]
    // Reload and add each original state word in order; EAX retains the updated fifth word.
    mov    eax,DWORD PTR [esi]
    add    eax,ecx
    mov    edx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esi],eax
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,edi
    add    eax,ebp
    shl    ecx,0x1e
    shr    edi,0x2
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,DWORD PTR [esi+0x8]
    or     ecx,edi
    pop    edi
    add    ecx,eax
    mov    eax,DWORD PTR [esi+0xc]
    add    eax,edx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],eax
    mov    eax,DWORD PTR [esi+0x10]
    add    eax,ebx
    mov    DWORD PTR [esi+0x10],eax
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x4c
    ret    0x8
  }
}
