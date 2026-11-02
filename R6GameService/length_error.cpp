#include "native_addresses.h"
#include "native_records.h"

// std::length_error ownership is established by ThrowInfo807f4 and CatchableType807c8/TypeDescriptor8e760.
// Vtable770e4 is {scalar-delete33f40, shared logic_error::what33f10}; native complete object size is0x28.
// Native read-only function-address words; shared what() retains its one canonical logic_error definition.
// R6GameService.dll data @ 100770e4 : native storage identity retained.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct GLengthErrorVtableRecord {
  R6GameServiceNative::Address ScalarDeletingLengthError; // +0x00
  R6GameServiceNative::Address std_logic_error_what; // +0x04
};
const GLengthErrorVtableRecord GLengthErrorVtable = {
  R6GameServiceAddresses::ScalarDeletingLengthError,
  R6GameServiceAddresses::std_logic_error_what,
};

// Destroys length_error, tests the current flag byte and optionally frees the cached object.
// R6GameService.dll @ 10033f40 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ScalarDeletingLengthError(void *object,byte flags)
{
  __asm {
    // Late flag read follows derived/base destruction; return cached object regardless of free EAX.
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::std_length_error__length_error
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restores the length_error vtable and tail-forwards destruction to the logic_error base.
// R6GameService.dll @ 10033f60 : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall std::length_error::~length_error(void)
{
  __asm {
    // Native vtable writes occur derived770e4 then base770dc in the tail target, without an independent EH frame.
    mov    DWORD PTR [ecx],offset GLengthErrorVtable
    jmp    R6GameServiceAddresses::std_logic_error__logic_error
  }
}

// Copies logic_error then installs the derived length_error vtable on the cached destination.
// R6GameService.dll @ 100340a0 : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall std::length_error::length_error(const std::length_error &source)
{
  __asm {
    // Cache destination across actual34020; ignore its returned pointer and store derived vtable on cached receiver.
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   eax
    mov    esi,ecx
    call   R6GameServiceAddresses::std_logic_error_logic_error
    mov    DWORD PTR [esi],offset GLengthErrorVtable
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Constructs the imported exception base and copies a late message into256 bytes.
// Forces the final diagnostic byte zero and installs the _STL::length_error table.
// R6GameService.dll @ 10017200 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructException75c28(void *owner,uint *message)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::exception_exception2
    mov    eax,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi],R6GameServiceAddresses::Named_exception__STLVTable
    push   0x100
    lea    edx,[esi+0xc]
    mov    ecx,DWORD PTR [eax]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    mov    BYTE PTR [esi+0x10b],0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::length_error__STLVTable
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Copies the imported exception base, then256 diagnostic bytes as forward DWORDs and installs the derived table.
// Source pointer caches before the base call; source data reloads after it, and overlap retains native copy order.
// R6GameService.dll @ 10017300 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopySTLLengthError(void *owner,void *source)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    push   esi
    mov    ebx,ecx
    call   R6GameServiceAddresses::exception_exception
    add    esi,0xc
    lea    edi,[ebx+0xc]
    mov    ecx,0x40
    mov    eax,ebx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    pop    edi
    mov    DWORD PTR [ebx],R6GameServiceAddresses::length_error__STLVTable
    pop    esi
    pop    ebx
    ret    0x4
  }
}
