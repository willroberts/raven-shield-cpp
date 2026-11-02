#include "native_addresses.h"
#include "native_records.h"

// Shared unsigned-short locale-facet helper; original template/function spelling remains unrecovered.

// Locks locale ID, checks locale facet/cached fallback, creates/publishes/increments/registers default when absent.
// Cached versus current imports/slots, outer-only unwind, publication gaps, bad_cast and raw ABI remain native.
// R6GameService.dll @ 10001c70 : native control/access order and raw ABI retained.
__declspec(naked) facet * __cdecl GetOrCreateUnsignedShortCtypeFacet(locale *locale)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectUnsignedShortCtypeLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_Construct_LockitSlot
    push   0x0
    lea    ecx,[esp+0x18]
    call   edi
    mov    eax,ds:R6GameServiceAddresses::GUnsignedShortCtypeFallback
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71__ctype_idSlot
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_Destroy_LockitSlot
    mov    DWORD PTR [esp+0xc],eax
    cmp    DWORD PTR [esi],0x0
    mov    DWORD PTR [esp+0x2c],0x0
    jne    Branch2
    push   0x0
    lea    ecx,[esp+0x14]
    call   edi
    cmp    DWORD PTR [esi],0x0
    jne    Branch1
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_id__Id_cntSlot
    inc    DWORD PTR [eax]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_id__Id_cntSlot
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esi],edx
  Branch1:
    lea    ecx,[esp+0x10]
    call   ebx
  Branch2:
    mov    esi,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esp+0x34]
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_locale__GetfacetSlot
    mov    esi,eax
    test   esi,esi
    jne    Branch4
    mov    esi,DWORD PTR [esp+0xc]
    test   esi,esi
    jne    Branch4
    lea    eax,[esp+0xc]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__ctype__GetcatSlot
    add    esp,0x4
    cmp    eax,0xffffffff
    jne    Branch3
    push   R6GameServiceAddresses::TextBadCast
    lea    ecx,[esp+0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__Constructbad_castSlot
    push   R6GameServiceAddresses::bad_castGBadCastThrowData3
    lea    ecx,[esp+0x1c]
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  Branch3:
    mov    ecx,DWORD PTR [esp+0xc]
    mov    esi,ecx
    mov    DWORD PTR ds:R6GameServiceAddresses::GUnsignedShortCtypeFallback,ecx
    mov    edi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_facet__IncrefSlot
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_facet__RegisterSlot
  Branch4:
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x2c],0xffffffff
    call   ebx
    mov    ecx,DWORD PTR [esp+0x24]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  }
}

// Unlocks inherited outer lock at EBP-1c through the current destructor import; no inner-lock cleanup is recorded.
// R6GameService.dll @ 10063170 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindUnsignedShortCtypeLock(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_Destroy_LockitSlot
  }
}

// Selects one-state unsigned-short facet lifetime metadata and tails to external Windows frame dispatch.
// R6GameService.dll @ 10063179 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectUnsignedShortCtypeLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::GetOrCreateUnsignedShortCtypeFacetExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007abf4 : exact outer-lock lifetime map/info.
const R6GameServiceNative::UnwindEntry GetOrCreateUnsignedShortCtypeFacetUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindUnsignedShortCtypeLock},
};

// R6GameService.dll data @ 1007abfc : exact outer-lock lifetime map/info.
// R6GameService.dll data @ 1007abf4 : native storage identity retained.
const R6GameServiceNative::FuncInfo GetOrCreateUnsignedShortCtypeFacetExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::GetOrCreateUnsignedShortCtypeFacetUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1009152c : initial zero fallback facet cache; runtime writes remain native.
uint GUnsignedShortCtypeFallback = 0;
