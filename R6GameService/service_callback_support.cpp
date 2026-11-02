#include "native_addresses.h"

// Shared callback stores and forwarding bodies retain one canonical definition for multiple receiver classes.

// Stores callback word at receiver+134 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 10032b80 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x134(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x134) = callback;
  return callback;
}

// Stores callback word at receiver+138 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 10032b90 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x138(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x138) = callback;
  return callback;
}

// Stores callback word at receiver+144 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 10032ba0 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x144(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x144) = callback;
  return callback;
}

// Stores callback word at receiver+148 and returns it in EAX; shared native body remains canonical.
// R6GameService.dll @ 10032bb0 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreCallbackAtOffset_0x148(void *service,void *callback)
{
  *reinterpret_cast<void **>(static_cast<byte *>(service) + 0x148) = callback;
  return callback;
}

// Tail-forward owner+18 callback with 2 stack words; NULL returns EAX0/RET8.
// Preserve redundant argument stores and register changes; raw callback EAX passes through.
// R6GameService.dll @ 1004bbc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSharedCallback18(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x18]
    test    eax,eax
    je    Branch1
    jmp    eax
  Branch1:
    ret    0x8
  }
}

// If flag+1c is zero and old+18 nonNULL, invoke its adjusted virtual slot0(1); then load late replacement.
// Store flag1 BEFORE pointer+18; preserve incoming/callback upper EAX, force AL1. No own EH; RET4.
// R6GameService.dll @ 1004fcd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetPointerAndFlag(void *owner,void *replacement)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x1c]
    test    al,al
    jne    Branch2
    mov    eax,DWORD PTR [esi+0x18]
    test    eax,eax
    je    Branch2
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch2:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x1c],0x1
    mov    DWORD PTR [esi+0x18],ecx
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// If flag+24 is zero and old+20 nonNULL, invoke its adjusted virtual slot0(1); then load late replacement.
// Store flag1 BEFORE pointer+20; preserve incoming/callback upper EAX, force AL1. No own EH; RET4.
// R6GameService.dll @ 1004fd10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall service_callback_support_SetPointerAndFlag(void *owner,void *replacement)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x24]
    test    al,al
    jne    Branch3
    mov    eax,DWORD PTR [esi+0x20]
    test    eax,eax
    je    Branch3
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch3:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x24],0x1
    mov    DWORD PTR [esi+0x20],ecx
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Capture replacement before loading current owner+15c; invoke first setter, then force only AL1. RET4.
// R6GameService.dll @ 100413b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InstallCallbackPointerAndReturnTrue(void *owner,void *replacement)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [ecx+0x15c]
    push    eax
    call    R6GameServiceAddresses::SetPointerAndFlag
    mov    al,0x1
    ret    0x4
  }
}

// Load current owner+15c and tail second setter with the original argument slot/raw return. RET4.
// R6GameService.dll @ 100413d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InstallSecondCallbackPointer(void *owner,void *replacement)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x15c]
    jmp    R6GameServiceAddresses::service_callback_support_SetPointerAndFlag
  }
}

// Shared clFriendsCB/clPersistentCB callback; retain native register/stack rewrite and tail ABI.
// R6GameService.dll @ 1004b910 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSharedCallback08(void *owner,uint arg1,uint arg2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x8]
    test    eax,eax
    je    Branch4
    mov    edx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],edx
    jmp    eax
  Branch4:
    ret    0x8
  }
}

// Shared clFriendsCB/clPersistentCB callback; retain native register/stack rewrite and tail ABI.
// R6GameService.dll @ 1004b950 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSharedCallback10(void *owner,uint arg1,uint arg2,uint arg3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x10]
    test    eax,eax
    je    Branch5
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esp+0x4],ecx
    jmp    eax
  Branch5:
    ret    0xc
  }
}
