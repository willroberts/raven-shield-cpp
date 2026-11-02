#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080938 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CollectedByteBuilderExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080c5c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo AdapterAddressCollectorExceptionHandlerFunctionInfo;

// Collected-data byte construction; original free/helper identifiers and concrete vector templates remain inferred.

// Prints each collected string and copies its unterminated bytes into a separately owned result vector.
// R6GameService.dll @ 10034890 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl BuildByteVectorFromCollectedStrings(void *outputVector)
{
  __asm {
    // ESP-based EH: result flag entryESP-30, strings-2c, temporary bytes-1c; opaque prefixes stay untouched.
    push   0xffffffff
    push   R6GameServiceAddresses::CollectedByteBuilderExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    edi,edi
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x20],edi
    mov    DWORD PTR [esp+0x24],edi
    lea    eax,[esp+0x18]
    push   eax
    // String ownership is active before collection. Ignore collector return; state2 starts after byte fields initialize.
    mov    DWORD PTR [esp+0x44],0x1
    call   R6GameServiceAddresses::CollectNetworkAdapterMacAddresses
    xor    ebx,ebx
    add    esp,0x4
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x30],edi
    mov    DWORD PTR [esp+0x34],edi
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esp+0x40],0x2
    mov    DWORD PTR [esp+0x10],edi
    xor    ebp,ebp
  Branch1:
    cmp    ecx,edi
    je     Branch11
    // Native signed32 division by0x1c, then unsigned index comparison; keep live begin/end and cached byte offset.
    mov    esi,DWORD PTR [esp+0x20]
    sub    esi,ecx
    mov    eax,0x92492493
    imul   esi
    add    edx,esi
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
    cmp    DWORD PTR [esp+0x10],eax
    jae    Branch11
    cmp    DWORD PTR [ecx+ebp*1+0x18],0x10
    jb     Branch2
    mov    ecx,DWORD PTR [ecx+ebp*1+0x4]
    jmp    Branch3
  Branch2:
    lea    ecx,[ecx+ebp*1+0x4]
  Branch3:
    push   ecx
    push   R6GameServiceAddresses::TextS
    // Print format is " %s\n". Reload string begin/length after printf; concatenate length bytes, including embedded zeros.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_printfSlot
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [ecx+ebp*1+0x14]
    add    esp,0x8
    test   eax,eax
    jbe    Branch10
  Branch4:
    // Recheck current length before access; retain actual _Xran import and inline/heap threshold16.
    mov    eax,DWORD PTR [ecx+ebp*1+0x14]
    cmp    eax,edi
    lea    esi,[ecx+ebp*1]
    ja     Branch5
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__String_base__XranSlot
  Branch5:
    cmp    DWORD PTR [esi+0x18],0x10
    jb     Branch6
    mov    esi,DWORD PTR [esi+0x4]
    jmp    Branch7
  Branch6:
    add    esi,0x4
  Branch7:
    // EBX caches temporary begin across direct appends; reload it only after insertion. Reload source begin/length each byte.
    test   ebx,ebx
    lea    edx,[esi+edi*1]
    mov    esi,DWORD PTR [esp+0x30]
    je     Branch8
    mov    ecx,DWORD PTR [esp+0x34]
    mov    eax,esi
    sub    eax,ebx
    sub    ecx,ebx
    cmp    eax,ecx
    jae    Branch8
    mov    cl,BYTE PTR [edx]
    mov    BYTE PTR [esi],cl
    inc    esi
    mov    DWORD PTR [esp+0x30],esi
    jmp    Branch9
  Branch8:
    push   edx
    push   0x1
    push   esi
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::InsertRepeatedByte
    mov    ebx,DWORD PTR [esp+0x2c]
  Branch9:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [ecx+ebp*1+0x14]
    inc    edi
    cmp    edi,eax
    jb     Branch4
  Branch10:
    mov    edx,DWORD PTR [esp+0x10]
    inc    edx
    add    ebp,0x1c
    mov    DWORD PTR [esp+0x10],edx
    xor    edi,edi
    jmp    Branch1
  Branch11:
    // Load hidden result pointer late, cache in EBP and copy temporary via actual34610; ignore copy returned EAX.
    mov    ebp,DWORD PTR [esp+0x48]
    lea    edx,[esp+0x28]
    push   edx
    mov    ecx,ebp
    call   R6GameServiceAddresses::CopyByteVector
    // Set result guard only after copy returns. Free cached EBX while state2/temporary fields remain live.
    cmp    ebx,edi
    mov    DWORD PTR [esp+0x14],0x1
    je     Branch12
    push   ebx
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch12:
    // Lower to state0 before string cleanup; cache endpoints, reload begin after nonempty destructor traversal.
    mov    esi,DWORD PTR [esp+0x1c]
    cmp    esi,edi
    mov    BYTE PTR [esp+0x40],0x0
    je     Branch15
    mov    edi,DWORD PTR [esp+0x20]
    cmp    esi,edi
    je     Branch14
  Branch13:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch13
    mov    esi,DWORD PTR [esp+0x1c]
  Branch14:
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch15:
    // Leave local fields/result flag live; return cached hidden pointer and restore saved FS registration.
    mov    ecx,DWORD PTR [esp+0x38]
    pop    edi
    pop    esi
    mov    eax,ebp
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  }
}

// Destroys the builder parent-frame narrow-string vector through its shared cleanup thunk.
// R6GameService.dll @ 10066480 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyCollectedStringsOnUnwind(void)
{
  __asm {
    // Inherited EBP denotes builder entryESP, not a frame created by this tail action.
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyStringVectorThunk
  }
}

// Releases and resets the builder parent-frame temporary byte vector.
// R6GameService.dll @ 10066488 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCollectedBytesOnUnwind(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Clears the completed-result guard before releasing the current hidden result pointer.
// R6GameService.dll @ 10066490 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCollectedResultOnUnwind(void)
{
  __asm {
    // Guard bit0 is independent of state; clear it before loading current parent argument and entering cleanup.
    mov    eax,DWORD PTR [ebp-0x30]
    and    eax,0x1
    je     Branch16
    and    DWORD PTR [ebp-0x30],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  Branch16:
    ret
  }
}

// Selects the three-state builder unwind map for result, collected strings and temporary bytes.
// R6GameService.dll @ 100664a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void CollectedByteBuilderExceptionHandler(void)
{
  __asm {
    // FuncInfo80938, unwind80920: state0->(-1,result66490), state1->(0,strings66480), state2->(1,bytes66488); no catches.
    mov    eax,R6GameServiceAddresses::CollectedByteBuilderExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Appends uppercase adapter hardware-address strings and returns success only in AL, preserving upper EAX residue.
// R6GameService.dll @ 10036420 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl CollectNetworkAdapterMacAddresses(void *stringVector)
{
  __asm {
    // Keep original EBP for arguments and align ESP to 8. Unwind parent A is aligned pre-EH ESP, not original EBP.
    push   ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    push   0xffffffff
    push   R6GameServiceAddresses::AdapterAddressCollectorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x150
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    push   esi
    push   edi
    // Cookie at A-14; query size A-150, zero fill A-155, vector A-14c, string A-13c, text A-118.
    mov    DWORD PTR [esp+0x154],eax
    lea    eax,[esp+0x18]
    xor    edi,edi
    push   eax
    push   edi
    mov    DWORD PTR [esp+0x20],edi
    call   R6GameServiceAddresses::GetAdaptersInfo
    // Accept only initial API status 0 or 0x6f; any other status returns with low byte cleared.
    cmp    eax,edi
    je     Branch17
    cmp    eax,0x6f
    jne    Branch18
  Branch17:
    mov    edx,DWORD PTR [esp+0x18]
    lea    ecx,[esp+0x13]
    push   ecx
    push   edx
    lea    ecx,[esp+0x24]
    // Vector construction has no outer ownership until it returns. Publish state 0 before the second API query.
    mov    BYTE PTR [esp+0x1b],0x0
    call   R6GameServiceAddresses::InitializeFilledByteVector
    mov    esi,DWORD PTR [esp+0x20]
    lea    eax,[esp+0x18]
    push   eax
    push   esi
    mov    DWORD PTR [esp+0x16c],edi
    call   R6GameServiceAddresses::GetAdaptersInfo
    // On query failure free cached ESI if nonzero; leave state/fields live and clear only returned AL.
    cmp    eax,edi
    je     Branch19
    cmp    esi,edi
    je     Branch18
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch18:
    xor    al,al
    jmp    Branch26
  Branch19:
    cmp    esi,edi
    mov    ebx,esi
    je     Branch25
    lea    ebx,[ebx+0x0]
  Branch20:
    // Zero the complete 256-byte address text plus selected byte scratch. No address-length/output-capacity guard.
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x49],ecx
    mov    BYTE PTR [esp+0x50],cl
    mov    BYTE PTR [esp+0x4d],cl
    xor    eax,eax
    mov    ecx,0x3f
    lea    edi,[esp+0x51]
    rep stos DWORD PTR es:[edi],eax
    stos   WORD PTR es:[edi],ax
    mov    BYTE PTR [esp+0x48],0x0
    stos   BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [ebx+0x190]
    test   eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    jbe    Branch24
    jmp    Branch21
    lea    esp,[esp+0x0]
    mov    edi,edi
  Branch21:
    // Reload current address byte/length; sprintf uses exact literal "%.2X" and a zero-extended byte.
    mov    edx,DWORD PTR [esp+0x14]
    movzx  eax,BYTE PTR [ebx+edx*1+0x194]
    push   eax
    lea    ecx,[esp+0x4c]
    push   R6GameServiceAddresses::Text2X
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_sprintfSlot
    // Scan formatted scratch including terminator, locate current text terminator, then copy DWORDs and trailing bytes.
    lea    eax,[esp+0x54]
    add    esp,0xc
    mov    ecx,eax
  Branch22:
    mov    dl,BYTE PTR [eax]
    inc    eax
    test   dl,dl
    jne    Branch22
    lea    edi,[esp+0x50]
    sub    eax,ecx
    mov    esi,ecx
    dec    edi
  Branch23:
    mov    cl,BYTE PTR [edi+0x1]
    inc    edi
    test   cl,cl
    jne    Branch23
    mov    ecx,eax
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    mov    eax,DWORD PTR [esp+0x14]
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    ecx,DWORD PTR [ebx+0x190]
    inc    eax
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x14],eax
    jb     Branch21
    // Only a nonempty formatted address reloads query-vector begin into ESI for eventual free.
    mov    esi,DWORD PTR [esp+0x20]
  Branch24:
    // Construct temporary string from text before state 1; load current original-frame output argument after ctor.
    lea    edx,[esp+0x50]
    push   edx
    lea    ecx,[esp+0x30]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot
    mov    ecx,DWORD PTR [ebp+0x8]
    lea    eax,[esp+0x2c]
    push   eax
    mov    BYTE PTR [esp+0x168],0x1
    call   R6GameServiceAddresses::AppendStdStringToVector
    // Lower state to 0 before destructor; read current adapter next only after destructor returns.
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x164],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    mov    ebx,DWORD PTR [ebx]
    test   ebx,ebx
    jne    Branch20
    // Free retained ESI unconditionally after nonnull-list traversal, even if a current-begin reload changed it to null.
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch25:
    // Only AL becomes success 1; retain upper EAX. Normal free leaves query vector state/fields live.
    mov    al,0x1
  Branch26:
    // Restore saved FS before the actual security-cookie check; then restore original unaligned stack via EBP.
    mov    ecx,DWORD PTR [esp+0x15c]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [esp+0x154]
    call   R6GameServiceAddresses::__security_check_cookie
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Tail-forwards the adapter buffer and size pointer through the selected GetAdaptersInfo import.
// R6GameService.dll @ 100371f4 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall GetAdaptersInfo(void *adapterInfo,uint *bufferSize)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::iphlpapi_GetAdaptersInfoSlot
  }
}

// Releases the collector aligned parent-frame byte-vector storage through shared cleanup.
// R6GameService.dll @ 10066690 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseAdapterQueryBufferOnUnwind(void)
{
  __asm {
    // Inherited EBP is aligned EH parent A: vector at A-14c, not original function EBP-14c.
    lea    ecx,[ebp-0x14c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Destroys the live collector address string using the current narrow CRT destructor import.
// R6GameService.dll @ 1006669b : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyAdapterAddressStringOnUnwind(void)
{
  __asm {
    // State 1 owns this temporary at aligned parent A-13c; current import target is retained.
    lea    ecx,[ebp-0x13c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects the collector two-state unwind map for its query buffer and temporary narrow string.
// R6GameService.dll @ 100666a7 : complete native control/access order and raw ABI retained.
__declspec(naked) void AdapterAddressCollectorExceptionHandler(void)
{
  __asm {
    // FuncInfo80c5c, map80c4c: state0 -> (-1,66690), state1 -> (0,6669b); no catches.
    mov    eax,R6GameServiceAddresses::AdapterAddressCollectorExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
