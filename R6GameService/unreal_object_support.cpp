#include "native_addresses.h"

// Unreal object-class traversal helpers; original template spelling remains unresolved.

// Walks object class+24/superclass+2c against imported UNetConnection static class; null target accepts only after traversal ends.
// R6GameService.dll @ 1000ea00 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) int __cdecl CastToUNetConnection(int object)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je     Branch3
    mov    ecx,DWORD PTR [eax+0x24]
    test   ecx,ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine_UNetConnection_PrivateStaticClassSlot
    je     Branch2
  Branch1:
    cmp    ecx,edx
    je     Branch4
    mov    ecx,DWORD PTR [ecx+0x2c]
    test   ecx,ecx
    jne    Branch1
  Branch2:
    xor    ecx,ecx
    test   edx,edx
    sete   cl
    test   ecx,ecx
    jne    Branch4
  Branch3:
    xor    eax,eax
  Branch4:
    ret
  }
}

// Walks object class+24/superclass+2c against imported UViewport static class; retains native null-target behavior.
// R6GameService.dll @ 1000ea30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) int __cdecl CastToUViewport(int object)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    je     Branch7
    mov    ecx,DWORD PTR [eax+0x24]
    test   ecx,ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine_UViewport_PrivateStaticClassSlot
    je     Branch6
  Branch5:
    cmp    ecx,edx
    je     Branch8
    mov    ecx,DWORD PTR [ecx+0x2c]
    test   ecx,ecx
    jne    Branch5
  Branch6:
    xor    ecx,ecx
    test   edx,edx
    sete   cl
    test   ecx,ecx
    jne    Branch8
  Branch7:
    xor    eax,eax
  Branch8:
    ret
  }
}
