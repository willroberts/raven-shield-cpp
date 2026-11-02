#include "native_addresses.h"
#include "native_records.h"

// Unassigned conversion/code-page helpers; original concrete scratch wrapper declarations remain unresolved.
// Scratch word0 points to inline storage at+4 or to allocated storage. Cleanup return views expose raw EAX.
UINT (__cdecl * GAnsiCodePageDispatch2)(void) = SelectAndInvokeAnsiCodePage;
// R6GameService.dll data @ 10080cc4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry text_conversion_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindAnsiWideScratch},
};
// R6GameService.dll data @ 10080ccc : native storage identity retained.
const R6GameServiceNative::FuncInfo text_conversion_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  1,
  R6GameServiceAddresses::text_conversion_supportSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Parses the thread locale ANSI code-page bytes, falling back to GetACP on failure, empty text or zero.
// R6GameService.dll @ 10001000 : complete native control/access order and raw ABI retained.
__declspec(naked) UINT __cdecl GetLegacyAnsiCodePage(void)
{
  __asm {
    // Eight-byte local buffer, GetThreadLocale/GetLocaleInfoA(locale,1004,buffer,7); API failure or empty text falls back.
    sub    esp,0x8
    push   esi
    xor    esi,esi
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetThreadLocaleSlot
    push   0x7
    lea    ecx,[esp+0x8]
    push   ecx
    push   0x1004
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetLocaleInfoASlot
    test   eax,eax
    je     Branch2
    mov    al,BYTE PTR [esp+0x4]
    test   al,al
    lea    ecx,[esp+0x4]
    je     Branch2
    nop
  Branch1:
    // Native signed-byte decimal accumulation has no digit/sign validation; preserve character-30 arithmetic.
    movsx  eax,al
    lea    edx,[esi+esi*4]
    inc    ecx
    lea    esi,[eax+edx*2-0x30]
    mov    al,BYTE PTR [ecx]
    test   al,al
    jne    Branch1
    // Parsed zero falls back; any other raw accumulated DWORD returns unchanged.
    test   esi,esi
    jne    Branch3
  Branch2:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetACPSlot
    pop    esi
    add    esp,0x8
    ret
  Branch3:
    mov    eax,esi
    pop    esi
    add    esp,0x8
    ret
  }
}

// Returns the raw thread ANSI code-page selector three.
// R6GameService.dll @ 10001060 : complete native control/access order and raw ABI retained.
UINT __cdecl GetThreadAnsiCodePageSelector(void)
{
  return 3;
}

// Selects and atomically publishes the platform code-page routine, then invokes the current published routine.
// R6GameService.dll @ 10001070 : complete native control/access order and raw ABI retained.
__declspec(naked) UINT __cdecl SelectAndInvokeAnsiCodePage(void)
{
  __asm {
    // Only OSVERSIONINFOW size114 initializes before GetVersionExW; its return is ignored, no zero fill or failure guard.
    sub    esp,0x114
    lea    eax,[esp]
    push   eax
    mov    DWORD PTR [esp+0x4],0x114
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetVersionExWSlot
    // NT platform2 and unsigned major>=5 selects01060; otherwise01000. Ignore minor/build fields.
    cmp    DWORD PTR [esp+0x10],0x2
    jne    Branch4
    cmp    DWORD PTR [esp+0x4],0x5
    mov    eax,R6GameServiceAddresses::GetThreadAnsiCodePageSelector
    jae    Branch5
  Branch4:
    mov    eax,R6GameServiceAddresses::GetLegacyAnsiCodePage
  Branch5:
    // InterlockedExchange publishes selected pointer; actual call reloads CURRENT slot after exchange, ignoring old/EAX target.
    push   eax
    push   offset GAnsiCodePageDispatch2
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_InterlockedExchangeSlot
    call   DWORD PTR [GAnsiCodePageDispatch2]
    add    esp,0x114
    ret
  }
}

// Frees the current scratch pointer unless it equals the inline buffer, leaving that pointer unchanged.
// R6GameService.dll @ 10036e60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseConversionScratch(void *scratch)
{
  __asm {
    // Compare current word0 to computed scratch+4; free even null when unequal, never clear pointer. No local EH.
    mov    eax,DWORD PTR [ecx]
    add    ecx,0x4
    cmp    eax,ecx
    je     Branch6
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    pop    ecx
  Branch6:
    ret
  }
}

// Converts terminated ANSI input into the current inline or allocated wide scratch buffer using the supplied code page.
// R6GameService.dll @ 10036e80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConvertAnsiIntoWideScratch(void *scratch,const char *text,UINT codePage)
{
  __asm {
    // Cache sourceEBX and scratchEDI; null input publishes0 and preserves incomingEAX, RET8.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   edi
    mov    edi,ecx
    jne    Branch7
    mov    DWORD PTR [edi],ebx
    pop    edi
    pop    ebx
    ret    0x8
  Branch7:
    // lstrlenA+1 is signed32 including terminator; allocate only when signed count>128, no overflow/range guard.
    push   esi
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_lstrlenASlot
    mov    esi,eax
    inc    esi
    cmp    esi,0x80
    jle    Branch8
    // malloc receives doubled count modulo32; publish returned pointer before null test/throw8007000e, no old-pointer free.
    lea    eax,[esi+esi*1]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_mallocSlot
    add    esp,0x4
    test   eax,eax
    mov    DWORD PTR [edi],eax
    jne    Branch8
    push   0x8007000e
    call   R6GameServiceAddresses::ThrowAtlStatus
  Branch8:
    // Current scratch pointer/current codePage argument load after allocator; original source remains cachedEBX.
    mov    ecx,DWORD PTR [edi]
    mov    edx,DWORD PTR [esp+0x14]
    push   esi
    push   ecx
    push   esi
    push   ebx
    push   0x0
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_MultiByteToWideCharSlot
    test   eax,eax
    jne    Branch9
    // Conversion failure throws current last error; no local scratch cleanup or rollback.
    call   R6GameServiceAddresses::RaiseWin32LastErrorAsHResult
  Branch9:
    pop    esi
    pop    edi
    pop    ebx
    ret    0x8
  }
}

// Constructs a CRT wide string from ANSI input using the current code-page routine and native scratch lifetime.
// R6GameService.dll @ 10036f60 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ConstructWideStringFromAnsi(void *destination,const char *text)
{
  __asm {
    // ESP lifetime base E=entryESP: stateE-4/FSnodeE-c, scratch pointerE-110, inline128wide bufferE-10c.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectAnsiWideScratchInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x108
    push   esi
    // Zero raw scratch DWORD E-114 and publish inline pointer; call current code-page slot while state-1.
    lea    eax,[esp+0xc]
    xor    esi,esi
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esp+0x8],eax
    call   DWORD PTR [GAnsiCodePageDispatch2]
    // Reload current text argument only after code-page callback; converter runs state-1, including heap publication/failure.
    mov    ecx,DWORD PTR [esp+0x120]
    push   eax
    push   ecx
    lea    ecx,[esp+0x10]
    call   R6GameServiceAddresses::ConvertAnsiIntoWideScratch
    // Only completed conversion publishes state0. Capture current buffer pointer then current destination intoESI.
    mov    edx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esp+0x114],esi
    mov    esi,DWORD PTR [esp+0x11c]
    push   edx
    mov    ecx,esi
    // CRT wide constructor(destination,currentbuffer), state0. Ignore its EAX; return cached destinationESI.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2
    // Reload CURRENT scratch pointer after constructor; free when not inline, including null. State remains0 during free.
    mov    eax,DWORD PTR [esp+0x8]
    lea    ecx,[esp+0xc]
    cmp    eax,ecx
    je     Branch10
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    add    esp,0x4
  Branch10:
    // Restore original FS and nonvolatile ESI; no explicit state lowering or scratch-pointer clear on normal exit.
    mov    ecx,DWORD PTR [esp+0x10c]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x114
    ret
  }
}

// Releases the inherited ANSI-to-wide scratch storage after its conversion has completed.
// R6GameService.dll @ 10066720 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindAnsiWideScratch(void)
{
  __asm {
    // Inherited unwind base EBP=E: scratch atEBP-110; actual cleanup36e60. Conversion-failure state-1 has no action.
    lea    ecx,[ebp-0x110]
    jmp    R6GameServiceAddresses::ReleaseConversionScratch
  }
}

// Selects the ANSI-to-wide scratch lifetime map and transfers to the native C++ frame handler.
// R6GameService.dll @ 1006672b : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectAnsiWideScratchInfo(void)
{
  __asm {
    // EAX exact FuncInfo80ccc, map80cc4=(-1,66720); native33906 routes to current CRT handler.
    mov    eax,offset text_conversion_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reverse conversion uses byte capacity twice the terminated wide count; it shares direction-neutral scratch release.
// R6GameService.dll data @ 10080ce8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry text_conversion_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::UnwindWideAnsiScratch},
};
// R6GameService.dll data @ 10080cf0 : native storage identity retained.
const R6GameServiceNative::FuncInfo text_conversion_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  1,
  R6GameServiceAddresses::text_conversion_supportSharedLifetimeUnwindMap2,
  0,
  0,
  0,
  0,
};

// Converts terminated wide text into the current or allocated narrow scratch buffer with native doubled capacity.
// R6GameService.dll @ 10036ef0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ConvertWideIntoAnsiScratch(void *scratch,const unsigned short *text,UINT codePage)
{
  __asm {
    // Cache scratchEBX and sourceEBP, preserving callerEBP as a nonvolatile register, not establishing a frame.
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    test   ebp,ebp
    mov    ebx,ecx
    jne    Branch11
    // Null source publishes0, no calls or old-pointer free; incoming EAX survives, RET8.
    mov    DWORD PTR [ebx],ebp
    pop    ebp
    pop    ebx
    ret    0x8
  Branch11:
    // lstrlenW+1 wrapsDWORD; byteCapacity=2*terminatedCount modulo32, signed capacity>128 gates malloc.
    push   esi
    push   edi
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_lstrlenWSlot
    mov    esi,eax
    inc    esi
    lea    edi,[esi+esi*1]
    cmp    edi,0x80
    jle    Branch12
    // Publish allocation before null test/throw8007000e; no old-pointer free, overflow guard or local EH.
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_mallocSlot
    add    esp,0x4
    test   eax,eax
    mov    DWORD PTR [ebx],eax
    jne    Branch12
    push   0x8007000e
    call   R6GameServiceAddresses::ThrowAtlStatus
  Branch12:
    // Reload current scratch pointer/current codePage after allocator; cached source/count/capacity stay fixed.
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esp+0x18]
    // WideCharToMultiByte(codepage,0,source,count,currentptr,byteCapacity,null,null); no default-character report.
    push   0x0
    push   0x0
    push   edi
    push   eax
    push   esi
    push   ebp
    push   0x0
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_WideCharToMultiByteSlot
    test   eax,eax
    jne    Branch13
    // Zero API result throws current last error via36e40. No cleanup/rollback here; nonzero raw API EAX returns.
    call   R6GameServiceAddresses::RaiseWin32LastErrorAsHResult
  Branch13:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Constructs a CRT narrow string from wide input using the current code-page routine and scratch lifetime.
// R6GameService.dll @ 10036ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ConstructNarrowStringFromWide(void *destination,const unsigned short *text)
{
  __asm {
    // ESP lifetime base E=entryESP: stateE-4/FSnodeE-c, rawzeroE-94, scratch pointerE-90/inline128bytesE-8c.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectWideAnsiScratchInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x88
    push   esi
    // Initialize raw scratch word and inline pointer, then current code-page dispatch while state-1.
    lea    eax,[esp+0xc]
    xor    esi,esi
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esp+0x8],eax
    call   DWORD PTR [GAnsiCodePageDispatch2]
    // Reload current wide argument after dispatch; conversion36ef0 including allocation/failure runs state-1.
    mov    ecx,DWORD PTR [esp+0xa0]
    push   eax
    push   ecx
    lea    ecx,[esp+0x10]
    call   R6GameServiceAddresses::ConvertWideIntoAnsiScratch
    // Only completed conversion publishes state0. Load current buffer, cache current destinationESI, call CRT narrow ctor.
    mov    edx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esp+0x94],esi
    mov    esi,DWORD PTR [esp+0x9c]
    push   edx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot
    // Ignore constructor EAX, reload CURRENT scratch pointer and free if not inline, includingnull; state0 remains live.
    mov    eax,DWORD PTR [esp+0x8]
    lea    ecx,[esp+0xc]
    cmp    eax,ecx
    je     Branch14
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    add    esp,0x4
  Branch14:
    // Return cached destinationESI, restore FS/ESI; no state lowering or pointer reset on normal exit.
    mov    ecx,DWORD PTR [esp+0x8c]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x94
    ret
  }
}

// Selects the wide string inline or heap data by capacity, then constructs the destination narrow string.
// R6GameService.dll @ 10037080 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl ConstructNarrowStringFromWideString(void *destination,const void *wideString)
{
  __asm {
    // Local DWORD initially spills ECX; capacityDWORD18 loads BEFORE local clears0. Unsigned capacity<8 selects inline.
    push   ecx
    mov    eax,DWORD PTR [esp+0xc]
    cmp    DWORD PTR [eax+0x18],0x8
    mov    DWORD PTR [esp],0x0
    jb     Branch15
    // Heap path takes current pointer at+4; cache destinationESI before cdecl conversion, preserving original arguments.
    mov    eax,DWORD PTR [eax+0x4]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   eax
    push   esi
    call   R6GameServiceAddresses::ConstructNarrowStringFromWide
    add    esp,0x8
    // Override callee EAX with cached destination; pop localDWORD into ECX (ordinarily0), retain native cdecl stack.
    mov    eax,esi
    pop    esi
    pop    ecx
    ret
  Branch15:
    // Inline path passes wideString+4, not a dereference; cache destination before conversion, no local EH/null guard.
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    add    eax,0x4
    push   eax
    push   esi
    call   R6GameServiceAddresses::ConstructNarrowStringFromWide
    add    esp,0x8
    // Same cached EAX and current localDWORD->ECX return on inline path.
    mov    eax,esi
    pop    esi
    pop    ecx
    ret
  }
}

// Releases the inherited wide-to-ANSI scratch storage after successful conversion.
// R6GameService.dll @ 10066740 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindWideAnsiScratch(void)
{
  __asm {
    // Inherited unwind base EBP=E: scratch pointer atEBP-90, inlineEBP-8c; tail shared cleanup36e60.
    lea    ecx,[ebp-0x90]
    jmp    R6GameServiceAddresses::ReleaseConversionScratch
  }
}

// Selects the wide-to-ANSI scratch lifetime map and transfers to the native C++ frame handler.
// R6GameService.dll @ 1006674b : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectWideAnsiScratchInfo(void)
{
  __asm {
    // EAX exact FuncInfo80cf0, map80ce8=(-1,66740); actual33906 routes to current CRT frame handler.
    mov    eax,offset text_conversion_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reads BSTR pointer from receiver first word and calls current SysFreeString import, leaving slot and raw residue unchanged.
// R6GameService.dll @ 10005210 : native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ReleaseStoredBstr(void *storedString)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysFreeStringSlot
    ret
  }
}

// Finds key then equals/value and CR before LF, copies signed length<=256 and appends NUL.
// Cached strstr target/value, late output word, missing-equals address1 and negative-length path remain unchecked.
// R6GameService.dll @ 100053e0 : native control/access order and raw ABI retained.
__declspec(naked) int __cdecl ExtractLineValue(char *text,char *key,char *output)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esp+0x4]
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strstrSlot
    push   eax
    push   ecx
    call   edi
    add    esp,0x8
    test   eax,eax
    je     Branch18
    push   esi
    push   R6GameServiceAddresses::WideTextPunctuation4
    push   eax
    call   edi
    mov    esi,eax
    inc    esi
    push   R6GameServiceAddresses::WideTextPunctuation3
    push   esi
    call   edi
    add    esp,0x10
    test   eax,eax
    jne    Branch17
    push   R6GameServiceAddresses::WideTextPunctuation2
    push   esi
    call   edi
    add    esp,0x8
    test   eax,eax
    jne    Branch17
  Branch16:
    pop    esi
    xor    eax,eax
    pop    edi
    ret
  Branch17:
    mov    edi,eax
    sub    edi,esi
    cmp    edi,0x100
    jg     Branch16
    push   edi
    push   esi
    mov    esi,DWORD PTR [esp+0x1c]
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strncpySlot
    add    esp,0xc
    mov    BYTE PTR [edi+esi*1],0x0
    pop    esi
    mov    eax,0x1
    pop    edi
    ret
  Branch18:
    xor    eax,eax
    pop    edi
    ret
  }
}

// Decode one hexadecimal byte through a cached strncmp target; invalid input returns zero.
// R6GameService.dll @ 10005760 : cdecl int(char *); trailing bytes are ignored.
int __cdecl HexDigitToValue(char *text)
{
  using CompareABI = int (__cdecl *)(const char *,const char *,uint);
  CompareABI compare = *(CompareABI *)R6GameServiceAddresses::MSVCR71_strncmpSlot;
  const uint digitText[22] = {
    R6GameServiceAddresses::WideText0, R6GameServiceAddresses::WideText1,
    R6GameServiceAddresses::WideText2, R6GameServiceAddresses::WideText3,
    R6GameServiceAddresses::WideText4, R6GameServiceAddresses::WideText5,
    R6GameServiceAddresses::WideText6, R6GameServiceAddresses::WideText7,
    R6GameServiceAddresses::WideText8, R6GameServiceAddresses::WideText9,
    R6GameServiceAddresses::WideTextA2, R6GameServiceAddresses::WideTextB2,
    R6GameServiceAddresses::WideTextC2, R6GameServiceAddresses::WideTextD2,
    R6GameServiceAddresses::WideTextE2, R6GameServiceAddresses::WideTextF2,
    R6GameServiceAddresses::WideTextA, R6GameServiceAddresses::WideTextB,
    R6GameServiceAddresses::WideTextC, R6GameServiceAddresses::WideTextD,
    R6GameServiceAddresses::WideTextE, R6GameServiceAddresses::WideTextF,
  };
  for (uint index = 0; index != 22; ++index) {
    if (compare(text,(const char *)digitText[index],1) == 0) return index < 16 ? index : index - 6;
  }
  return 0;
}

// Queries wide length, allocates BSTR, converts using the late source argument and frees on length mismatch.
// Count/codepage/length/result stay cached; chain initializes after codepage call, no local exception cleanup.
// R6GameService.dll @ 10007e00 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) LPWSTR __cdecl ConvertAnsiToBstr(LPCSTR source,int byteCount)
{
  __asm {
    push   ecx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    test   esi,esi
    push   edi
    je     Branch42
    mov    edi,DWORD PTR [esp+0x14]
    test   edi,edi
    je     Branch42
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::GAnsiCodePageDispatch
    push   0x0
    push   0x0
    push   edi
    push   esi
    mov    ebx,eax
    push   0x0
    push   ebx
    mov    DWORD PTR [esp+0x24],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_MultiByteToWideCharSlot
    cmp    edi,0xffffffff
    mov    esi,eax
    jne    Branch40
    lea    eax,[esi-0x1]
  Branch40:
    push   ebp
    push   eax
    push   0x0
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysAllocStringLenSlot
    mov    ebp,eax
    test   ebp,ebp
    je     Branch41
    mov    eax,DWORD PTR [esp+0x18]
    push   esi
    push   ebp
    push   edi
    push   eax
    push   0x0
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_MultiByteToWideCharSlot
    cmp    eax,esi
    je     Branch41
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysFreeStringSlot
    lea    ecx,[esp+0x10]
    call   R6GameServiceAddresses::FreeLinkedAllocations
    pop    ebp
    pop    ebx
    pop    edi
    xor    eax,eax
    pop    esi
    pop    ecx
    ret
  Branch41:
    lea    ecx,[esp+0x10]
    call   R6GameServiceAddresses::FreeLinkedAllocations
    mov    eax,ebp
    pop    ebp
    pop    ebx
    pop    edi
    pop    esi
    pop    ecx
    ret
  Branch42:
    pop    edi
    xor    eax,eax
    pop    esi
    pop    ecx
    ret
  }
}

// Formats twenty bytes through cached overlapping sprintf calls, builds output string and releases its temporary.
// Forty-byte text storage abuts saved FS link; native final terminator can change its low byte.
// R6GameService.dll @ 1000d020 : C++ formatter with native frame/exception boundaries for saved-link overwrite.
__declspec(naked) FString * __cdecl FormatAuthenticationIdHex(FString *result,const uchar *authenticationId)
{
  byte *nativeFrame;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectAuthenticationFormatterLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push   ebp
    push   esi
    xor    esi,esi
    push   edi
    mov    nativeFrame,esp
  }
  using EmptyABI = FString * (__thiscall *)(FString *);
  using FormatABI = int (__cdecl *)(char *,const char *,...);
  using FromAnsiABI = const TCHAR * (__cdecl *)(const char *);
  using AssignABI = FString * (__thiscall *)(FString *,const TCHAR *);
  using CopyABI = FString * (__thiscall *)(FString *,const FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame + 0xc) = 0;
  FString *temporary = (FString *)(nativeFrame + 0x10);
  (*(EmptyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(temporary);
  const byte *source = *(const byte **)(nativeFrame + 0x58);
  FormatABI format = *(FormatABI *)R6GameServiceAddresses::MSVCR71_sprintfSlot;
  char *text = (char *)(nativeFrame + 0x1c);
  for (uint index = 0; index != 9; ++index) *(uint *)(text + index * 4) = 0;
  *(uint *)(nativeFrame + 0x4c) = 1;
  *(uint *)(text + 36) = 0;
  for (uint index = 0; index != 20; ++index) {
    uint value = source[index];
    const char *pattern = (const char *)(value < 16
        ? R6GameServiceAddresses::TextS0X : R6GameServiceAddresses::TextS2x);
    // Source and destination overlap; text[40] overwrites the low byte of the saved FS predecessor.
    format(text,pattern,text,value);
  }
  const TCHAR *wideText = (*(FromAnsiABI *)R6GameServiceAddresses::Core__appFromAnsiSlot)(text);
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot2)(temporary,wideText);
  FString *output = *(FString **)(nativeFrame + 0x54);
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(output,temporary);
  *(uint *)(nativeFrame + 0xc) = 1;
  *(byte *)(nativeFrame + 0x4c) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(temporary);
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret
  }
}

// Tail-destroys formatter temporary at inherited EBP-40 through the current string destructor import.
// R6GameService.dll @ 10063f10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl FormatAuthenticationIdHexUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Clears inherited construction bit0 before tail-destroying the current output argument when that bit is set.
// R6GameService.dll @ 10063f19 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl FormatAuthenticationIdHexUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x44]
    and    eax,0x1
    je     Branch46
    and    DWORD PTR [ebp-0x44],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch46:
    ret
  }
}

// Selects two-state formatter temporary/output lifetime map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10063f33 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectAuthenticationFormatterLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::FormatAuthenticationIdHexExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d428 : native authentication formatter unwind record.
const R6GameServiceNative::UnwindEntry FormatAuthenticationIdHexUnwindMap[2] = {
  {-1, R6GameServiceAddresses::FormatAuthenticationIdHexUnwind1},
  {0x0, R6GameServiceAddresses::FormatAuthenticationIdHexUnwind2},
};

// R6GameService.dll data @ 1007d438 : native authentication formatter unwind record.
// R6GameService.dll data @ 1007d428 : native storage identity retained.
const R6GameServiceNative::FuncInfo FormatAuthenticationIdHexExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::FormatAuthenticationIdHexUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
