#include "native_addresses.h"
#include "native_records.h"

// Unassigned payload-reference specializations; offsets do not establish a concrete class/layout.

// Release record+10 reference first, then read CURRENT deleting flag low byte/bit0 and optionally free record.
// RET4/record EAX regardless free result; no own guard or cleanup retry.
// R6GameService.dll @ 10042e20 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeletePayloadReferenceAt16(void *record,uint deletingFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ReleasePayloadReferenceAt16
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

// Decrement target+10/+14 modulo64 using ADD/ADC; only zero count reloads CURRENT record+10 for slot0(1).
// Clear record10/14 AFTER normal destructor return, even if reloadNULL. No clear on absent/nonzero/throw.
// Raw pointer/table/backend EAX retained; JB after TEST high is genuinely never taken, preserved verbatim.
// R6GameService.dll @ 10042e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleasePayloadReferenceAt16(int recordAddress)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x10]
    test   eax,eax
    je     Branch4
    mov    edx,DWORD PTR [eax+0x10]
    or     ecx,0xffffffff
    add    edx,ecx
    mov    DWORD PTR [eax+0x10],edx
    mov    edx,DWORD PTR [eax+0x14]
    adc    edx,ecx
    mov    ecx,edx
    mov    DWORD PTR [eax+0x14],edx
    test   ecx,ecx
    ja     Branch4
    jb     Branch2
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    ja     Branch4
  Branch2:
    mov    ecx,DWORD PTR [esi+0x10]
    test   ecx,ecx
    je     Branch3
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch3:
    mov    DWORD PTR [esi+0x10],0x0
    mov    DWORD PTR [esi+0x14],0x0
  Branch4:
    pop    esi
    ret
  }
}

// Same two-word count rule as42e40, using record+c/+10 source pair. Late pointer reload/destructor before clears.
// No own guard, atomic count or validation; raw EAX and native never-taken JB after TEST retained.
// R6GameService.dll @ 10042e90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleasePayloadReferenceAt12(int recordAddress)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0xc]
    test   eax,eax
    je     Branch7
    mov    edx,DWORD PTR [eax+0x10]
    or     ecx,0xffffffff
    add    edx,ecx
    mov    DWORD PTR [eax+0x10],edx
    mov    edx,DWORD PTR [eax+0x14]
    adc    edx,ecx
    mov    ecx,edx
    mov    DWORD PTR [eax+0x14],edx
    test   ecx,ecx
    ja     Branch7
    jb     Branch5
    mov    ecx,DWORD PTR [eax+0x10]
    test   ecx,ecx
    ja     Branch7
  Branch5:
    mov    ecx,DWORD PTR [esi+0xc]
    test   ecx,ecx
    je     Branch6
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch6:
    mov    DWORD PTR [esi+0xc],0x0
    mov    DWORD PTR [esi+0x10],0x0
  Branch7:
    pop    esi
    ret
  }
}

// Tail guarded reference release at42b80 with unchanged record/stack/raw result.
// R6GameService.dll @ 10042b70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_ReleasePayloadReferenceAt4(void *record)
{
  __asm {
    jmp    R6GameServiceAddresses::ReleasePayloadReferenceAt4
  }
}

// Decrement target at record+4 modulo64, reload CURRENT pointer for zero-count slot0(1), then clear pair4/8.
// Retain lowADD/highADC, post-TEST unsigned branches, late NULL, raw EAX and shared genuine no-op guard.
// R6GameService.dll @ 10042b80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleasePayloadReferenceAt4(void *record)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectCircularReferenceDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch10
    mov    edx,DWORD PTR [eax+0x10]
    or    ecx,0xffffffff
    add    edx,ecx
    mov    DWORD PTR [eax+0x10],edx
    mov    edx,DWORD PTR [eax+0x14]
    adc    edx,ecx
    mov    ecx,edx
    mov    DWORD PTR [eax+0x14],edx
    test    ecx,ecx
    ja    Branch10
    jb    Branch8
    mov    ecx,DWORD PTR [eax+0x10]
    test    ecx,ecx
    ja    Branch10
  Branch8:
    mov    ecx,DWORD PTR [esi+0x4]
    test    ecx,ecx
    je    Branch9
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch9:
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],0x0
  Branch10:
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Pass CURRENT saved list/record to genuine no-op cleanup; no allocation or reference retry.
// R6GameService.dll @ 100671c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl payload_reference_supportSharedLifetimeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact destruction FuncInfo and tail CRT dispatch; shared selector has one canonical definition.
// R6GameService.dll @ 100671c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectCircularReferenceDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::payload_reference_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destruction map/FuncInfo; preserve entered no-retry/no-op predecessor chains.
// R6GameService.dll data @ 100818bc : native storage identity retained.
const R6GameServiceNative::UnwindEntry payload_reference_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::payload_reference_supportSharedLifetimeUnwind1},
};

// Literal destruction map/FuncInfo; preserve entered no-retry/no-op predecessor chains.
// R6GameService.dll data @ 100818c4 : native storage identity retained.
const R6GameServiceNative::FuncInfo payload_reference_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::payload_reference_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
