#include "native_addresses.h"

// Offset-based ping packet helpers; original function names and declarations are unavailable.

// Folds a wrapped DWORD sum of little-endian words and an odd byte, then returns its full complement.
// R6GameService.dll @ 10013cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl PingChecksum(const void *data,int byteCount)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    xor    eax,eax
    cmp    esi,0x1
    jle    Branch2
    lea    edx,[esi-0x2]
    shr    edx,1
    inc    edx
    mov    ecx,edx
    neg    ecx
    lea    esi,[esi+ecx*2]
    mov    ecx,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,edi
  Branch1:
    movzx  edi,WORD PTR [ecx]
    add    eax,edi
    add    ecx,0x2
    dec    edx
    jne    Branch1
    pop    edi
    jmp    Branch3
  Branch2:
    mov    ecx,DWORD PTR [esp+0x8]
  Branch3:
    test   esi,esi
    pop    esi
    je     Branch4
    movzx  edx,BYTE PTR [ecx]
    add    eax,edx
  Branch4:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    mov    eax,ecx
    shr    eax,0x10
    add    eax,ecx
    not    eax
    ret
  }
}

// Writes an echo header/sequence/tick, fills E bytes, copies an unchecked NUL payload and checksums existing bytes.
// R6GameService.dll @ 10013d10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl BuildPingPacket(void *packet,int byteCount,const char *payload)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    push   edi
    mov    BYTE PTR [esi],0x8
    mov    BYTE PTR [esi+0x1],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot
    mov    WORD PTR [esi+0x4],ax
    mov    eax,ds:0x10093b68
    mov    WORD PTR [esi+0x6],ax
    inc    eax
    mov    ds:0x10093b68,eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    mov    ebx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi+0x8],eax
    lea    ecx,[ebx-0xc]
    mov    ebp,ecx
    shr    ecx,0x2
    lea    edx,[esi+0xc]
    mov    edi,edx
    mov    eax,0x45454545
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,ebp
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [esp+0x1c]
    sub    edx,eax
  Branch5:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test   cl,cl
    jne    Branch5
    push   ebx
    push   esi
    call   R6GameServiceAddresses::PingChecksum
    add    esp,0x8
    pop    edi
    mov    WORD PTR [esi+0x2],ax
    pop    esi
    pop    ebp
    pop    ebx
    ret
  }
}

// Checks type and low process word at the header-derived offset, returning elapsed ticks or 1000 without length checks.
// Native caller supplies receive result/sender words, but only packet is read; parameter names are descriptive.
// R6GameService.dll @ 10013d90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ReadPingReply(const byte *packet,int receiveResult,const void *sender)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax]
    push   esi
    and    ecx,0xf
    shl    ecx,0x2
    movzx  esi,cx
    add    esi,eax
    cmp    BYTE PTR [esi],0x0
    jne    Branch6
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetCurrentProcessIdSlot
    cmp    WORD PTR [esi+0x4],ax
    je     Branch7
  Branch6:
    mov    eax,0x3e8
    pop    esi
    ret
  Branch7:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    sub    eax,DWORD PTR [esi+0x8]
    pop    esi
    ret
  }
}
