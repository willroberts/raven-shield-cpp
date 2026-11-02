#include "native_addresses.h"
#include "native_records.h"

// Unassigned record helpers: imported FStringNoInit identity and member offsets are established, containing types are not.
// R6GameService.dll data @ 1007ab7c : state0 destroys the saved first string; no catch blocks.
const R6GameServiceNative::UnwindEntry string_record_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroySavedFirstRecordString},
};
// R6GameService.dll data @ 1007ab84 : shared FuncInfo for four record copy/destruction entries.
const R6GameServiceNative::FuncInfo string_record_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  1,
  R6GameServiceAddresses::string_record_supportSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Copy-constructs two strings at +0/+c, arming first-string cleanup only before the second constructor.
// R6GameService.dll @ 10001a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyStringPairRecord18(void *destination,const void *source)
{
  __asm {
    // Receiver/source cached in ESI/EDI; first-string owner saved at inherited parent EBP-10.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectStringRecordExceptionInfo
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    add    edi,0xc
    push   edi
    lea    ecx,[esi+0xc]
    mov    DWORD PTR [esp+0x18],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Copies strings at +0/+20 and five intervening words; scalar copies precede arming first-string cleanup.
// R6GameService.dll @ 10001ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyStringRecord2C(void *destination,const void *source)
{
  __asm {
    // Interleaved scalar loads/stores preserve overlap and callback mutations; state remains-1 until second string.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectStringRecordExceptionInfo
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    eax,DWORD PTR [edi+0xc]
    mov    DWORD PTR [esi+0xc],eax
    mov    ecx,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],ecx
    mov    edx,DWORD PTR [edi+0x14]
    mov    DWORD PTR [esi+0x14],edx
    mov    eax,DWORD PTR [edi+0x18]
    mov    DWORD PTR [esi+0x18],eax
    mov    ecx,DWORD PTR [edi+0x1c]
    add    edi,0x20
    mov    DWORD PTR [esi+0x1c],ecx
    push   edi
    lea    ecx,[esi+0x20]
    mov    DWORD PTR [esp+0x18],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Destroys the +c string under first-string cleanup, then disarms cleanup and destroys +0.
// R6GameService.dll @ 10001bd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DestroyStringPairRecord18(void *record)
{
  __asm {
    // Raw final imported destructor EAX survives; the uint view does not assert an original C++ destructor return type.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectStringRecordExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    lea    ecx,[esi+0xc]
    mov    DWORD PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys the +20 string under first-string cleanup, then disarms cleanup and destroys +0.
// R6GameService.dll @ 10001c20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DestroyStringRecord2C(void *record)
{
  __asm {
    // Raw final imported destructor EAX survives; the uint view does not assert an original C++ destructor return type.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectStringRecordExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    lea    ecx,[esi+0x20]
    mov    DWORD PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-forwards the current saved first-string pointer from inherited parent EBP-10 to its destructor.
// R6GameService.dll @ 10063150 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroySavedFirstRecordString(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the shared one-state record FuncInfo and tail-forwards to the native C++ frame handler.
// R6GameService.dll @ 10063159 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectStringRecordExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::string_record_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys current 0x18-byte records with live data/count reloads, then clears count and reallocates to the late hint.
// R6GameService.dll @ 10002760 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ResetStringPairArray18(void *array,uint capacityHint)
{
  __asm {
    // No outer EH guard; an element failure leaves array header reset/reallocation pending.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    xor    edi,edi
    test   eax,eax
    jle    Branch2
    push   ebx
    xor    ebx,ebx
  Branch1:
    mov    ecx,DWORD PTR [esi]
    add    ecx,ebx
    call   R6GameServiceAddresses::DestroyStringPairRecord18
    mov    eax,DWORD PTR [esi+0x4]
    inc    edi
    add    ebx,0x18
    cmp    edi,eax
    jl    Branch1
    pop    ebx
  Branch2:
    mov    eax,DWORD PTR [esp+0xc]
    push   0x18
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Destroys current 0x2c-byte records with live data/count reloads, then clears count and reallocates to the late hint.
// R6GameService.dll @ 100027b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ResetStringRecordArray2C(void *array,uint capacityHint)
{
  __asm {
    // No outer EH guard; an element failure leaves array header reset/reallocation pending.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    xor    edi,edi
    test   eax,eax
    jle    Branch4
    push   ebx
    xor    ebx,ebx
  Branch3:
    mov    ecx,DWORD PTR [esi]
    add    ecx,ebx
    call   R6GameServiceAddresses::DestroyStringRecord2C
    mov    eax,DWORD PTR [esi+0x4]
    inc    edi
    add    ebx,0x2c
    cmp    edi,eax
    jl    Branch3
    pop    ebx
  Branch4:
    mov    eax,DWORD PTR [esp+0xc]
    push   0x2c
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Checks a range, destroys its cached extent of 0x18-byte records and forwards the late original count to removal.
// R6GameService.dll @ 10002af0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall RemoveStringPairRange18(void *array,int firstIndex,int count)
{
  __asm {
    // Signed gates use wrapped index+count; data reloads per element, but loop extent is cached before destruction.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   edi
    mov    ebp,ecx
    jge    Branch5
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   esi
    add    esp,0xc
  Branch5:
    cmp    ebx,DWORD PTR [ebp+0x4]
    jle    Branch6
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   esi
    add    esp,0xc
  Branch6:
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[ebx+eax*1]
    cmp    edi,DWORD PTR [ebp+0x4]
    jle    Branch7
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   esi
    add    esp,0xc
  Branch7:
    cmp    ebx,edi
    jge    Branch9
    lea    esi,[ebx+ebx*2]
    shl    esi,0x3
    sub    edi,ebx
    lea    ecx,[ecx+0x0]
  Branch8:
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,esi
    call   R6GameServiceAddresses::DestroyStringPairRecord18
    add    esi,0x18
    dec    edi
    jne    Branch8
  Branch9:
    mov    ecx,DWORD PTR [esp+0x18]
    push   0x18
    push   ecx
    push   ebx
    mov    ecx,ebp
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Skips self-assignment; otherwise resets destination and copies live source records through Add and record construction.
// R6GameService.dll @ 10002b90 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyStringPairArray18(void *destination,const void *source)
{
  __asm {
    // Source count/data and destination data reload around callbacks; no outer rollback or full-array EH guard.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    esi,edi
    je    Branch13
    mov    eax,DWORD PTR [edi+0x4]
    push   ebx
    push   eax
    call   R6GameServiceAddresses::ResetStringPairArray18
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebx,ebx
    test   eax,eax
    jle    Branch12
    push   ebp
    xor    ebp,ebp
  Branch10:
    push   0x18
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    edx,DWORD PTR [esi]
    lea    ecx,[eax+eax*2]
    lea    ecx,[edx+ecx*8]
    test   ecx,ecx
    je    Branch11
    mov    eax,DWORD PTR [edi]
    add    eax,ebp
    push   eax
    call   R6GameServiceAddresses::CopyStringPairRecord18
  Branch11:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0x18
    cmp    ebx,eax
    jl    Branch10
    pop    ebp
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch12:
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch13:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Checks a range, destroys its cached extent of 0x2c-byte records and forwards the late original count to removal.
// R6GameService.dll @ 10002c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall RemoveStringRecordRange2C(void *array,int firstIndex,int count)
{
  __asm {
    // Signed gates use wrapped index+count; data reloads per element, but loop extent is cached before destruction.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   edi
    mov    ebp,ecx
    jge    Branch14
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   esi
    add    esp,0xc
  Branch14:
    cmp    ebx,DWORD PTR [ebp+0x4]
    jle    Branch15
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   esi
    add    esp,0xc
  Branch15:
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[ebx+eax*1]
    cmp    edi,DWORD PTR [ebp+0x4]
    jle    Branch16
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   esi
    add    esp,0xc
  Branch16:
    cmp    ebx,edi
    jge    Branch18
    mov    esi,ebx
    imul   esi,esi,0x2c
    sub    edi,ebx
    lea    esp,[esp+0x0]
  Branch17:
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,esi
    call   R6GameServiceAddresses::DestroyStringRecord2C
    add    esi,0x2c
    dec    edi
    jne    Branch17
  Branch18:
    mov    ecx,DWORD PTR [esp+0x18]
    push   0x2c
    push   ecx
    push   ebx
    mov    ecx,ebp
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Skips self-assignment; otherwise resets destination and copies live source records through Add and record construction.
// R6GameService.dll @ 10002ca0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyStringRecordArray2C(void *destination,const void *source)
{
  __asm {
    // Source count/data and destination data reload around callbacks; no outer rollback or full-array EH guard.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    esi,edi
    je    Branch22
    mov    eax,DWORD PTR [edi+0x4]
    push   ebx
    push   eax
    call   R6GameServiceAddresses::ResetStringRecordArray2C
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebx,ebx
    test   eax,eax
    jle    Branch21
    push   ebp
    xor    ebp,ebp
  Branch19:
    push   0x2c
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x2c
    add    eax,DWORD PTR [esi]
    je    Branch20
    mov    ecx,DWORD PTR [edi]
    add    ecx,ebp
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyStringRecord2C
  Branch20:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0x2c
    cmp    ebx,eax
    jl    Branch19
    pop    ebp
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch21:
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch22:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroys an FString at receiver+4 through the current import; the containing wrapper type remains unresolved.
// R6GameService.dll @ 10001570 : complete native receiver adjustment and tail ABI retained.
__declspec(naked) void __fastcall DestroyFStringAt04(int ownerAddress)
{
  __asm {
    add    ecx,0x4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Shared twelve-byte owning string records; original template/class spelling remains unrecovered.

// Clones twelve-byte descriptors in order, publishing each allocated string before moving to the next record.
// Source/end argument slots reload each iteration; destination clearing precedes source reads, retaining alias effects.
// The fourth word is unused; partial construction and catch-all cleanup retain the exact native frame.
// R6GameService.dll @ 10017900 : native control/access order and raw ABI retained.
__declspec(naked) undefined4 * __stdcall CopyStringRecordRange(
    undefined4 *first,undefined4 *last,undefined4 *destination,undefined4 unusedWord)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::CopyStringRecordRangeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x10]
    push   edi
    xor    edi,edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],edi
  Branch23:
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebp+0xc]
    cmp    ebx,eax
    mov    DWORD PTR [ebp-0x18],esi
    je     Branch25
    mov    DWORD PTR [ebp-0x1c],esi
    cmp    esi,edi
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch24
    lea    eax,[ebp-0x12]
    mov    ecx,ebx
    push   eax
    call   R6GameServiceAddresses::ForwardStackWord
    mov    DWORD PTR [esi],edi
    mov    DWORD PTR [esi+0x4],edi
    mov    DWORD PTR [esi+0x8],edi
    mov    edi,DWORD PTR [ebx+0x4]
    mov    ebx,DWORD PTR [ebx]
    mov    eax,edi
    mov    ecx,esi
    sub    eax,ebx
    mov    BYTE PTR [ebp-0x4],0x2
    inc    eax
    push   eax
    call   R6GameServiceAddresses::InitializeHeapByteString
    mov    eax,DWORD PTR [esi]
    mov    cl,BYTE PTR [ebp+0xb]
    lea    edx,[ebp-0x11]
    mov    BYTE PTR [ebp-0x11],cl
    push   edx
    push   eax
    push   edi
    push   ebx
    call   R6GameServiceAddresses::CopyByteRange
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    xor    edi,edi
  Branch24:
    add    ebx,0xc
    mov    BYTE PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp+0x8],ebx
    add    esi,0xc
    jmp    Branch23
  Branch25:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x10
  }
}

// Releases the range from the CURRENT original destination argument to the saved current cursor, then rethrows.
// Inherited EBP and raw free-size words remain explicit; the current partial record is handled by unwind state2.
// R6GameService.dll @ 1001799c : native control/access order and raw ABI retained.
__declspec(naked) void string_record_support_string_record_supportCatch(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp+0x10]
    mov    edi,DWORD PTR [ebp-0x18]
    cmp    esi,edi
    je     Branch27
  Branch26:
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x8]
    sub    edx,eax
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    add    esi,0xc
    cmp    esi,edi
    jne    Branch26
  Branch27:
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Clones one descriptor repeatedly using an unsigned count reloaded and decremented in its original argument slot.
// Source pointer reloads each iteration; clear-before-read, null-first-record skip and late count bytes remain native.
// R6GameService.dll @ 100179e0 : native control/access order and raw ABI retained.
__declspec(naked) undefined4 * __stdcall RepeatStringRecord(
    undefined4 *destination,uint count,undefined4 *source,undefined4 unusedWord)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::RepeatStringRecordSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    push   edi
    xor    edi,edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],edi
  Branch28:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ebp-0x18],esi
    cmp    eax,edi
    jbe    Branch30
    mov    DWORD PTR [ebp-0x1c],esi
    cmp    esi,edi
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch29
    mov    ebx,DWORD PTR [ebp+0x10]
    lea    eax,[ebp-0x12]
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::ForwardStackWord
    mov    DWORD PTR [esi],edi
    mov    DWORD PTR [esi+0x4],edi
    mov    DWORD PTR [esi+0x8],edi
    mov    edi,DWORD PTR [ebx+0x4]
    mov    ebx,DWORD PTR [ebx]
    mov    eax,edi
    mov    ecx,esi
    sub    eax,ebx
    mov    BYTE PTR [ebp-0x4],0x2
    inc    eax
    push   eax
    call   R6GameServiceAddresses::InitializeHeapByteString
    mov    eax,DWORD PTR [esi]
    mov    cl,BYTE PTR [ebp+0xf]
    lea    edx,[ebp-0x11]
    mov    BYTE PTR [ebp-0x11],cl
    push   edx
    push   eax
    push   edi
    push   ebx
    call   R6GameServiceAddresses::CopyByteRange
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [eax],0x0
    xor    edi,edi
  Branch29:
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    BYTE PTR [ebp-0x4],0x0
    dec    ecx
    add    esi,0xc
    mov    DWORD PTR [ebp+0xc],ecx
    jmp    Branch28
  Branch30:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,esi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x10
  }
}

// Releases completed records from the CURRENT original destination word to the saved cursor, then rethrows.
// R6GameService.dll @ 10017a7a : native control/access order and raw ABI retained.
__declspec(naked) void string_record_support_string_record_supportCatch2(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp+0x8]
    mov    edi,DWORD PTR [ebp-0x18]
    cmp    esi,edi
    je     Branch32
  Branch31:
    mov    eax,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x8]
    sub    edx,eax
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    add    esi,0xc
    cmp    esi,edi
    jne    Branch31
  Branch32:
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Passes saved current/start words to the genuine empty allocator cleanup; preserves inherited frame and stack.
// R6GameService.dll @ 10064980 : native control/access order and raw ABI retained.
__declspec(naked) void CopyStringRecordRangeUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Releases the currently constructing descriptor through the saved receiver at inherited EBP-1c.
// R6GameService.dll @ 10064991 : native control/access order and raw ABI retained.
__declspec(naked) void CopyStringRecordRangeUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Passes saved current/start words to the genuine empty allocator cleanup; preserves inherited frame and stack.
// R6GameService.dll @ 100649b0 : native control/access order and raw ABI retained.
__declspec(naked) void RepeatStringRecordUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Releases the currently constructing descriptor through the saved receiver at inherited EBP-1c.
// R6GameService.dll @ 100649c1 : native control/access order and raw ABI retained.
__declspec(naked) void RepeatStringRecordUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the four-state range-copy lifetime and catch-all record.
// R6GameService.dll @ 10064999 : native control/access order and raw ABI retained.
__declspec(naked) void CopyStringRecordRangeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CopyStringRecordRangeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the four-state repeated-copy lifetime and catch-all record.
// R6GameService.dll @ 100649c9 : native control/access order and raw ABI retained.
__declspec(naked) void RepeatStringRecordSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RepeatStringRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ecdc : native owning-record lifetime/catch record.
const R6GameServiceNative::UnwindEntry CopyStringRecordRangeUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::CopyStringRecordRangeUnwind2},
  {0x1, R6GameServiceAddresses::CopyStringRecordRangeUnwind3},
  {-1, 0x0},
};

// R6GameService.dll data @ 1007ecfc : native owning-record lifetime/catch record.
const R6GameServiceNative::CatchHandler string_record_supportGStringRecordEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::string_record_support_string_record_supportCatch},
};

// R6GameService.dll data @ 1007ed0c : native owning-record lifetime/catch record.
const R6GameServiceNative::TryBlock CopyStringRecordRangeTryMap[1] = {
  {0x0, 0x2, 0x3, 0x1, R6GameServiceAddresses::string_record_supportGStringRecordEH},
};

// R6GameService.dll data @ 1007ed20 : native owning-record lifetime/catch record.
const R6GameServiceNative::FuncInfo CopyStringRecordRangeExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::CopyStringRecordRangeUnwindMap,
  0x1,
  R6GameServiceAddresses::CopyStringRecordRangeTryMap,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007ed3c : native owning-record lifetime/catch record.
const R6GameServiceNative::UnwindEntry RepeatStringRecordUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::RepeatStringRecordUnwind2},
  {0x1, R6GameServiceAddresses::RepeatStringRecordUnwind3},
  {-1, 0x0},
};

// R6GameService.dll data @ 1007ed5c : native owning-record lifetime/catch record.
const R6GameServiceNative::CatchHandler string_record_supportGStringRecordEH5[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::string_record_support_string_record_supportCatch2},
};

// R6GameService.dll data @ 1007ed6c : native owning-record lifetime/catch record.
const R6GameServiceNative::TryBlock RepeatStringRecordTryMap[1] = {
  {0x0, 0x2, 0x3, 0x1, R6GameServiceAddresses::string_record_supportGStringRecordEH5},
};

// R6GameService.dll data @ 1007ed80 : native owning-record lifetime/catch record.
const R6GameServiceNative::FuncInfo RepeatStringRecordExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::RepeatStringRecordUnwindMap,
  0x1,
  R6GameServiceAddresses::RepeatStringRecordTryMap,
  0x0,
  0x0,
};

// Rebuilds twelve-byte records with a prefix, repeated insertion and optional suffix, then releases old storage.
// Signed distance/12 feeds unsigned capacity selection; late argument/header loads and unchecked wrap remain native.
// Disabling the guard before old destruction preserves leaks on later failure. EAX returns raw replacement begin.
// R6GameService.dll @ 100173c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RebuildThreeWordArray(
    void *array,void *position,void *source,uint unusedWord,uint count,uint suppressSuffixWord)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::RebuildThreeWordArraySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi]
    sub    ecx,eax
    mov    eax,0x2aaaaaab
    imul   ecx
    sar    edx,1
    mov    eax,edx
    shr    eax,0x1f
    add    edx,eax
    mov    eax,DWORD PTR [ebp+0x14]
    cmp    edx,eax
    mov    DWORD PTR [ebp-0x1c],edx
    lea    eax,[ebp+0x14]
    jb     Branch33
    lea    eax,[ebp-0x1c]
  Branch33:
    mov    edi,DWORD PTR [eax]
    add    edi,edx
    lea    ecx,[edi+edi*2]
    shl    ecx,0x2
    push   ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esi]
    lea    edx,[ebp-0x11]
    push   edx
    mov    DWORD PTR [ebp-0x1c],eax
    mov    DWORD PTR [ebp-0x18],eax
    push   eax
    mov    eax,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0x0
    push   eax
    push   ecx
    call   R6GameServiceAddresses::CopyStringRecordRange
    mov    ebx,eax
    mov    eax,DWORD PTR [ebp+0x14]
    cmp    eax,0x1
    mov    DWORD PTR [ebp-0x18],ebx
    jne    Branch35
    mov    DWORD PTR [ebp-0x20],ebx
    test   ebx,ebx
    mov    BYTE PTR [ebp-0x4],al
    je     Branch34
    mov    ecx,DWORD PTR [ebp+0xc]
    lea    edx,[ebp+0x17]
    push   edx
    call   R6GameServiceAddresses::ForwardStackWord
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    mov    eax,DWORD PTR [ebp+0xc]
    mov    BYTE PTR [ebp-0x4],0x2
    mov    ecx,DWORD PTR [eax+0x4]
    mov    edx,DWORD PTR [eax]
    push   ecx
    push   edx
    mov    ecx,ebx
    call   R6GameServiceAddresses::InitializeStringRange
  Branch34:
    mov    BYTE PTR [ebp-0x4],0x0
    add    ebx,0xc
    jmp    Branch36
  Branch35:
    mov    edx,DWORD PTR [ebp+0xc]
    lea    ecx,[ebp+0x17]
    push   ecx
    push   edx
    push   eax
    push   ebx
    call   R6GameServiceAddresses::RepeatStringRecord
    mov    ebx,eax
  Branch36:
    mov    al,BYTE PTR [ebp+0x18]
    mov    DWORD PTR [ebp-0x18],ebx
    test   al,al
    jne    Branch37
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [ebp+0x8]
    lea    eax,[ebp+0x1b]
    push   eax
    push   ebx
    push   ecx
    push   edx
    call   R6GameServiceAddresses::CopyStringRecordRange
    mov    ebx,eax
  Branch37:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi]
    cmp    ecx,eax
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    DWORD PTR [ebp+0xc],eax
    mov    DWORD PTR [ebp+0x14],ecx
    je     Branch40
    jmp    Branch39
  Branch38:
    mov    ecx,DWORD PTR [ebp+0x14]
  Branch39:
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    eax,DWORD PTR [ebp+0x14]
    mov    ecx,DWORD PTR [ebp+0xc]
    add    eax,0xc
    cmp    eax,ecx
    mov    DWORD PTR [ebp+0x14],eax
    jne    Branch38
  Branch40:
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebp-0x1c]
    lea    ecx,[edi+edi*2]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],ebx
    lea    edx,[eax+ecx*4]
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR [esi+0x8],edx
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x14
  }
}

// Destroys completed replacement records, frees their backing storage and rethrows using the inherited parent frame.
// The original count argument becomes the cleanup cursor; state4 protects each destructor with genuine empty cleanup.
// R6GameService.dll @ 1001750c : native control/access order and raw ABI retained.
__declspec(naked) void string_record_supportCatch(void)
{
  __asm {
    mov    esi,DWORD PTR [ebp-0x1c]
    mov    edi,DWORD PTR [ebp-0x18]
    cmp    esi,edi
    mov    DWORD PTR [ebp+0x14],esi
    je     Branch42
    mov    bl,0x3
  Branch41:
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x4
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    add    esi,0xc
    mov    BYTE PTR [ebp-0x4],bl
    cmp    esi,edi
    mov    DWORD PTR [ebp+0x14],esi
    jne    Branch41
    mov    esi,DWORD PTR [ebp-0x1c]
  Branch42:
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Passes saved insertion receiver/current-prefix end to genuine empty allocator cleanup with inherited frame intact.
// R6GameService.dll @ 10064920 : native control/access order and raw ABI retained.
__declspec(naked) void RebuildThreeWordArrayUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    mov    ecx,DWORD PTR [ebp-0x20]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Releases the partially constructing insertion descriptor saved at inherited EBP-20.
// R6GameService.dll @ 10064931 : native control/access order and raw ABI retained.
__declspec(naked) void RebuildThreeWordArrayUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Forwards current catch cursor plus8 to genuine empty cleanup; no destructor/free retry is added.
// R6GameService.dll @ 10064939 : native control/access order and raw ABI retained.
__declspec(naked) void RebuildThreeWordArrayUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the five-state rebuild/catch cleanup map for the inherited parent frame.
// R6GameService.dll @ 10064944 : native control/access order and raw ABI retained.
__declspec(naked) void RebuildThreeWordArraySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RebuildThreeWordArrayExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ec40 : native owning-record lifetime/catch record.
const R6GameServiceNative::UnwindEntry RebuildThreeWordArrayUnwindMap[5] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::RebuildThreeWordArrayUnwind2},
  {0x1, R6GameServiceAddresses::RebuildThreeWordArrayUnwind3},
  {-1, 0x0},
  {0x3, R6GameServiceAddresses::RebuildThreeWordArrayUnwind5},
};

// R6GameService.dll data @ 1007ec68 : native owning-record lifetime/catch record.
const R6GameServiceNative::CatchHandler string_record_supportGStringRecordEH9[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::string_record_supportCatch},
};

// R6GameService.dll data @ 1007ec78 : native owning-record lifetime/catch record.
const R6GameServiceNative::TryBlock RebuildThreeWordArrayTryMap[1] = {
  {0x0, 0x2, 0x4, 0x1, R6GameServiceAddresses::string_record_supportGStringRecordEH9},
};

// R6GameService.dll data @ 1007ec8c : native owning-record lifetime/catch record.
const R6GameServiceNative::FuncInfo RebuildThreeWordArrayExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::RebuildThreeWordArrayUnwindMap,
  0x1,
  R6GameServiceAddresses::RebuildThreeWordArrayTryMap,
  0x0,
  0x0,
};
