#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080790 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo LogicErrorBaseLifetimeExceptionHandlerFunctionInfo;

// std::logic_error ownership is established by selected catchable-type metadata and native vtable/copy links.
// Vtable770dc is {scalar-delete33f20, what33f10}; message is CRT narrow string at +c.
// Native read-only function-address words; the names are descriptive, not exported symbols.
// R6GameService.dll data @ 100770dc : native storage identity retained.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct GLogicErrorVtableRecord {
  R6GameServiceNative::Address ScalarDeletingLogicError; // +0x00
  R6GameServiceNative::Address std_logic_error_what; // +0x04
};
const GLogicErrorVtableRecord GLogicErrorVtable = {
  R6GameServiceAddresses::ScalarDeletingLogicError,
  R6GameServiceAddresses::std_logic_error_what,
};

// Restores the logic_error vtable, destroys its message string, then destroys the CRT exception base.
// R6GameService.dll @ 10033eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall std::logic_error::~logic_error(void)
{
  __asm {
    // ESP-based pooled EH66409: cache receiver ESI and saved binding entryESP-10 before publishing base vtable.
    push   0xffffffff
    push   R6GameServiceAddresses::LogicErrorBaseLifetimeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],offset GLogicErrorVtable
    // Message at +c; state0 covers its destructor. The pooled action destroys only the CRT exception base.
    lea    ecx,[esi+0xc]
    mov    DWORD PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    // Lower to state -1 before current imported base destructor; retain raw EAX and restore current saved FS.
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__DestroyexceptionSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Returns the inline or heap message pointer; the same native body serves logic_error and length_error.
// R6GameService.dll @ 10033f10 : complete native control/access order and raw ABI retained.
__declspec(naked) const char * __thiscall std::logic_error::what(void) const
{
  __asm {
    // String capacity +24 selects inline +10 below16 or heap pointer +10 otherwise; no null/length check.
    cmp    DWORD PTR [ecx+0x24],0x10
    jb     Branch1
    mov    eax,DWORD PTR [ecx+0x10]
    ret
  Branch1:
    lea    eax,[ecx+0x10]
    ret
  }
}

// Destroys logic_error, tests the current flag byte and optionally frees the cached object.
// R6GameService.dll @ 10033f20 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ScalarDeletingLogicError(void *object,byte flags)
{
  __asm {
    // Cache object before actual destructor; load original flag byte only afterward, retain unrelated flag bits.
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::std_logic_error__logic_error
    test   BYTE PTR [esp+0x8],0x1
    je     Branch2
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Copies the CRT exception base, installs the logic_error vtable and copy-constructs the message string.
// R6GameService.dll @ 10034020 : complete native control/access order and raw ABI retained.
__declspec(naked) __thiscall std::logic_error::logic_error(const std::logic_error &source)
{
  __asm {
    // ESP-based pooled EH66409; cache original source EDI/destination ESI, save destination at entryESP-10.
    push   0xffffffff
    push   R6GameServiceAddresses::LogicErrorBaseLifetimeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__ConstructexceptionSlot2
    // Reload neither source nor destination after imported base copy; source+c is computed from cached EDI.
    add    edi,0xc
    push   edi
    lea    ecx,[esi+0xc]
    // State0/base vtable precede message copy. Normal return keeps state0 until FS restoration; EAX=cached receiver.
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esi],offset GLogicErrorVtable
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Destroys the CRT exception subobject bound in the shared logic_error parent-frame slot.
// R6GameService.dll @ 10066400 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyLogicErrorExceptionBaseOnUnwind(void)
{
  __asm {
    // Inherited ESP-parent base; current binding at parent-10 may differ from normal cached receiver.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__DestroyexceptionSlot
  }
}

// Selects the shared logic_error copy/destruction exception-base lifetime map.
// R6GameService.dll @ 10066409 : complete native control/access order and raw ABI retained.
__declspec(naked) void LogicErrorBaseLifetimeExceptionHandler(void)
{
  __asm {
    // FuncInfo80790/map80788=(-1,66400), no catches; same selector is installed by destructor33eb0 and copy34020.
    mov    eax,R6GameServiceAddresses::LogicErrorBaseLifetimeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Constructs the imported exception base and copies a late message into256 bytes.
// Forces the final diagnostic byte zero and installs the _STL::logic_error table.
// R6GameService.dll @ 100171c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructException75c10(void *owner,uint *message)
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
    mov    DWORD PTR [esi],R6GameServiceAddresses::logic_error__STLVTable
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Copies the imported exception base, then256 diagnostic bytes as forward DWORDs and installs the derived table.
// Source pointer caches before the base call; source data reloads after it, and overlap retains native copy order.
// R6GameService.dll @ 100172d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopySTLLogicError(void *owner,void *source)
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
    mov    DWORD PTR [ebx],R6GameServiceAddresses::logic_error__STLVTable
    pop    esi
    pop    ebx
    ret    0x4
  }
}
