#include "native_addresses.h"
#include "native_records.h"

// Shared _STL named-exception bodies; derived tables retain one canonical deletion/what implementation.

// Calls the imported base destructor through its real thunk, reloads the deletion flag and optionally frees owner.
// Shared by four _STL tables; one canonical body returns the owner regardless of allocator EAX.
// R6GameService.dll @ 10017240 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroyExceptionAndMaybeFree(void *owner,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::MsvcExceptionDestructor
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

// Tail-forwards the unchanged receiver to the imported exception destructor, without another body or local frame.
// R6GameService.dll @ 10017260 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall MsvcExceptionDestructor(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::exception__exception
  }
}

// Returns owner+12 as the inline diagnostic address; one shared body serves the four _STL exception tables.
// R6GameService.dll @ 100171b0 : complete native control/access order and raw ABI retained.
char * __fastcall STLNamedExceptionWhat(void *owner)
{
  return static_cast<char *>(owner) + 0x0c;
}

// Native virtual-table prefix: out_of_range__STLVTable
// R6GameService.dll data @ 10075c04 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct out_of_range__STLVTableRecord {
  R6GameServiceNative::Address DestroyExceptionAndMaybeFree; // +0x00
  R6GameServiceNative::Address STLNamedExceptionWhat; // +0x04
};
const out_of_range__STLVTableRecord out_of_range__STLVTable = {
  R6GameServiceAddresses::DestroyExceptionAndMaybeFree,
  R6GameServiceAddresses::STLNamedExceptionWhat,
};

// Native virtual-table prefix: logic_error__STLVTable
// R6GameService.dll data @ 10075c10 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct logic_error__STLVTableRecord {
  R6GameServiceNative::Address DestroyExceptionAndMaybeFree; // +0x00
  R6GameServiceNative::Address STLNamedExceptionWhat; // +0x04
};
const logic_error__STLVTableRecord logic_error__STLVTable = {
  R6GameServiceAddresses::DestroyExceptionAndMaybeFree,
  R6GameServiceAddresses::STLNamedExceptionWhat,
};

// Native virtual-table prefix: Named_exception__STLVTable
// R6GameService.dll data @ 10075c1c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct Named_exception__STLVTableRecord {
  R6GameServiceNative::Address DestroyExceptionAndMaybeFree; // +0x00
  R6GameServiceNative::Address STLNamedExceptionWhat; // +0x04
};
const Named_exception__STLVTableRecord Named_exception__STLVTable = {
  R6GameServiceAddresses::DestroyExceptionAndMaybeFree,
  R6GameServiceAddresses::STLNamedExceptionWhat,
};

// Native virtual-table prefix: length_error__STLVTable
// R6GameService.dll data @ 10075c28 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct length_error__STLVTableRecord {
  R6GameServiceNative::Address DestroyExceptionAndMaybeFree; // +0x00
  R6GameServiceNative::Address STLNamedExceptionWhat; // +0x04
};
const length_error__STLVTableRecord length_error__STLVTable = {
  R6GameServiceAddresses::DestroyExceptionAndMaybeFree,
  R6GameServiceAddresses::STLNamedExceptionWhat,
};
