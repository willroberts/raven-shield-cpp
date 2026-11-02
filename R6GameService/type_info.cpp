#include "native_addresses.h"

// Selected native type_info deletion members; complete imported class layout remains outside these body views.
// Known first vtable word only; this declaration does not presume the full table extent.
// R6GameService.dll data @ 100770a8 : native storage identity retained.
const uint GTypeInfoDeletingDestructorSlot = R6GameServiceAddresses::VectorDeletingTypeInfo;

// Destroys scalar or counted-array type_info storage and optionally frees the cached allocation address.
// R6GameService.dll @ 100339ca : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall VectorDeletingTypeInfo(type_info *object,byte flags)
{
  __asm {
    // Cache flag low byte in BL before any destructor. Bit1 selects array, bit0 requests free.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je     Branch2
    // Array count DWORD is at object-4, stride0xc and actual type_info dtor thunk33e0c; return allocation header.
    push   edi
    push   R6GameServiceAddresses::type_info__type_info
    lea    edi,[esi-0x4]
    push   DWORD PTR [edi]
    push   0xc
    push   esi
    call   R6GameServiceAddresses::_eh_vector_destructor_iterator_
    test   bl,0x1
    je     Branch1
    push   edi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
  Branch1:
    mov    eax,edi
    pop    edi
    jmp    Branch4
  Branch2:
    // Scalar path returns cached object; array path returns cached header even when no free is requested.
    mov    ecx,esi
    call   R6GameServiceAddresses::type_info__type_info
    test   bl,0x1
    je     Branch3
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
  Branch3:
    mov    eax,esi
  Branch4:
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Tail-forwards the ECX type_info object to its current imported destructor.
// R6GameService.dll @ 10033e0c : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall type_info::~type_info(void)
{
  __asm {
    // Import6b394 is MSVCR71 type_info destructor; imported body is outside selected native reconstruction scope.
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__Destroytype_infoSlot
  }
}
