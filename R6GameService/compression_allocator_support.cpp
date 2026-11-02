#include "native_addresses.h"

// Shared compression allocator callbacks; stream context is unused and concrete library source types remain inferred.

// Forward raw count/size to current CRT calloc; ignore context and return the raw allocation result with RET 0xc.
// R6GameService.dll @ 10020430 : complete native operations/raw ABI; descriptive callback name.
__declspec(naked) void * __stdcall InflateAllocator(void *opaque,uint count,uint size)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::calloc
    add    esp,0x8
    ret    0xc
  }
}

// Forward allocation to current CRT free; retain raw EAX, POP current pushed word into ECX and return with RET 8.
// R6GameService.dll @ 10020450 : complete native operations/raw ABI; descriptive callback name.
__declspec(naked) uint __stdcall InflateFree(void *opaque,void *allocation)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::free
    pop    ecx
    ret    0x8
  }
}
