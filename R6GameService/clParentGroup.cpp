#include "native_addresses.h"

// clParentGroup name is recovered from typed list RTTI; constructor/allocation/insertion flow supports placement.
// Nonvirtual method/local identifiers are descriptive; no missing layout or declarations are invented.

// Optionally install offset table76d1c(0,3c), store4/8, then copy33 text bytes/clamp byte2c.
// Late end/start words store34/end-start modulo32 at38/start at30, in that order. RET24/owner EAX.
// ECX reloads current zero-initialized scratch; no own EH. Original field/member identifiers inferred.
// R6GameService.dll @ 10031c40 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeParsedServiceRecord(
    void *owner,uint field04,uint field08,const char *text,uint startWord,uint endWord,uint initializeBase)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x1c]
    push   esi
    test   eax,eax
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    je     Branch1
    mov    DWORD PTR [esi],0x10076d1c
  Branch1:
    mov    edx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x14]
    lea    edi,[esi+0xc]
    push   0x21
    push   edx
    push   edi
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],ecx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    test   al,al
    je     Branch2
    mov    BYTE PTR [edi+0x20],0x0
  Branch2:
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x34],eax
    sub    eax,ecx
    mov    DWORD PTR [esi+0x38],eax
    mov    DWORD PTR [esi+0x30],ecx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ecx
    ret    0x18
  }
}

// Optionally install76d1c, clear4/8, copy current global33 bytes/clamp2c, then clear30/34/38.
// Padding2d..2f remains; RET4/owner EAX/current zero-initialized ECX scratch, no own guard.
// R6GameService.dll @ 10031cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeEmptyParsedServiceRecord(void *owner,uint initializeBase)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   ebx
    xor    ebx,ebx
    push   esi
    cmp    eax,ebx
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0xc],ebx
    je     Branch3
    mov    DWORD PTR [esi],0x10076d1c
  Branch3:
    lea    edi,[esi+0xc]
    push   0x21
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    mov    DWORD PTR [esi+0x4],ebx
    mov    DWORD PTR [esi+0x8],ebx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch4
    mov    BYTE PTR [edi+0x20],bl
  Branch4:
    mov    DWORD PTR [esi+0x30],ebx
    mov    DWORD PTR [esi+0x34],ebx
    mov    DWORD PTR [esi+0x38],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Sequentially copy4/8, bounded text33/clamp2c, then late30/34/38; table/padding untouched.
// Source and destination may alias; no snapshot/memmove repair or own EH. RET4/owner EAX.
// R6GameService.dll @ 10031d00 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyParsedServiceRecord(void *owner,const void *source)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,ecx
    push   0x21
    mov    eax,DWORD PTR [edi+0x4]
    lea    edx,[edi+0xc]
    mov    DWORD PTR [esi+0x4],eax
    mov    ecx,DWORD PTR [edi+0x8]
    lea    ebx,[esi+0xc]
    push   edx
    push   ebx
    mov    DWORD PTR [esi+0x8],ecx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [ebx+0x20]
    add    esp,0xc
    test   al,al
    je     Branch5
    mov    BYTE PTR [ebx+0x20],0x0
  Branch5:
    mov    eax,DWORD PTR [edi+0x30]
    mov    DWORD PTR [esi+0x30],eax
    mov    ecx,DWORD PTR [edi+0x34]
    mov    DWORD PTR [esi+0x34],ecx
    mov    edx,DWORD PTR [edi+0x38]
    mov    DWORD PTR [esi+0x38],edx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  }
}
