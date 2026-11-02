#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080890 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideHexEncoderExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1008095c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo LocalByteVectorExceptionHandlerFunctionInfo;

// Shared low-nibble-first wide-hex codec; original free-template declarations remain unresolved.

// Descriptive name for native compiler switch target words at 10034328, for nibble values10..15.
// R6GameService.dll data @ 10034328 : native storage identity retained.
const uint GWideHexLowNibbleTargets[6] = {
  R6GameServiceAddresses::GWideHexLowNibbleTargetsCase1,R6GameServiceAddresses::GWideHexLowNibbleTargetsCase2,R6GameServiceAddresses::GWideHexLowNibbleTargetsCase3,R6GameServiceAddresses::GWideHexLowNibbleTargetsCase4,R6GameServiceAddresses::GWideHexLowNibbleTargetsCase5,R6GameServiceAddresses::GWideHexLowNibbleTargetsCase6
};

// Descriptive name for native compiler switch target words at 10034340, for nibble values10..15.
// R6GameService.dll data @ 10034340 : native storage identity retained.
const uint GWideHexHighNibbleTargets[6] = {
  R6GameServiceAddresses::GWideHexHighNibbleTargetsCase1,R6GameServiceAddresses::GWideHexHighNibbleTargetsCase2,R6GameServiceAddresses::GWideHexHighNibbleTargetsCase3,R6GameServiceAddresses::GWideHexHighNibbleTargetsCase4,R6GameServiceAddresses::GWideHexHighNibbleTargetsCase5,R6GameServiceAddresses::GWideHexHighNibbleTargetsCase6
};

// Encodes bytes as uppercase wide hex with the low nibble first, preserving per-digit input reloads and result lifetime.
// R6GameService.dll @ 10034150 : complete native control/access order and raw ABI retained.
__declspec(naked) std::basic_string<unsigned short> * __cdecl ConvertByteRangeToWideHexText(std::basic_string<unsigned short> *output,const void *sourceVector)
{
  __asm {
    // ESP-based EH: ownership flag-30, local CRT text-2c, saved cookie-10; nominal unwind EBP is entryESP.
    push   0xffffffff
    push   R6GameServiceAddresses::WideHexEncoderExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    push   edi
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x28],eax
    mov    DWORD PTR [esp+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    // Cache source-vector argument only after default constructor; state1 owns local text.
    mov    edi,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esp+0x34],0x1
    xor    esi,esi
  Branch1:
    mov    ecx,DWORD PTR [edi+0x4]
    test   ecx,ecx
    je     Branch7
    mov    eax,DWORD PTR [edi+0x8]
    sub    eax,ecx
    cmp    esi,eax
    jae    Branch7
    // Low nibble first. Numeric branch preserves raw EAX high16; native switch branches replace full EAX.
    mov    al,BYTE PTR [ecx+esi*1]
    and    al,0xf
    cmp    al,0xa
    jge    Branch2
    movsx  ax,al
    add    eax,0x30
    jmp    Branch4
  Branch2:
    movsx  eax,al
    add    eax,0xfffffff6
    cmp    eax,0x5
    ja     Branch3
    jmp    DWORD PTR [eax*4+GWideHexLowNibbleTargets]
    mov    eax,0x41
    jmp    Branch4
    mov    eax,0x42
    jmp    Branch4
    mov    eax,0x43
    jmp    Branch4
    mov    eax,0x44
    jmp    Branch4
    mov    eax,0x45
    jmp    Branch4
    mov    eax,0x46
    jmp    Branch4
  Branch3:
    mov    eax,0x30
  Branch4:
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    // Reload current begin before high nibble; first append callback can change this same byte.
    mov    eax,DWORD PTR [edi+0x4]
    add    eax,esi
    mov    al,BYTE PTR [eax]
    sar    al,0x4
    and    al,0xf
    cmp    al,0xa
    jge    Branch5
    movsx  ax,al
    lea    ecx,[esp+0xc]
    add    eax,0x30
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
  Branch5:
    movsx  eax,al
    add    eax,0xfffffff6
    cmp    eax,0x5
    ja     Branch6
    jmp    DWORD PTR [eax*4+GWideHexHighNibbleTargets]
    mov    eax,0x41
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
    mov    eax,0x42
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
    mov    eax,0x43
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
    mov    eax,0x44
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
    mov    eax,0x45
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
    mov    eax,0x46
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
  Branch6:
    mov    eax,0x30
    push   eax
    lea    ecx,[esp+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot
    inc    esi
    jmp    Branch1
  Branch7:
    // Load hidden result only after loop, copy local text and cache destination in ESI.
    mov    esi,DWORD PTR [esp+0x3c]
    lea    eax,[esp+0xc]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot
    // Publish owned result only after successful copy; lower state0 before destroying local text.
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x8],0x1
    mov    BYTE PTR [esp+0x34],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // Restore FS before actual cookie check, retaining its failure edge and cached ESI return.
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,esi
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    add    esp,0x30
    ret
  }
}

// Decodes low-first wide hex pairs, maps invalid digits to zero, drops an odd digit and copy-constructs the result.
// R6GameService.dll @ 10034710 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl DecodeWideHexToByteVector(void *outputVector,const std::basic_string<unsigned short> *encodedText)
{
  __asm {
    // ESP-based EH: temporary vector-1c, byte local-21; state0 owns temporary even while result is copied/freed.
    push   0xffffffff
    push   R6GameServiceAddresses::LocalByteVectorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebp
    push   esi
    xor    esi,esi
    xor    ebp,ebp
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x18],esi
    mov    DWORD PTR [esp+0x1c],esi
    // Cache unsigned length for each pair; empty/odd input reaches result construction without another character read.
    mov    edx,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [edx+0x14]
    cmp    ecx,esi
    mov    DWORD PTR [esp+0x28],esi
    jbe    Branch25
    push   ebx
    push   edi
    jmp    Branch9
  Branch8:
    mov    edx,DWORD PTR [esp+0x3c]
    lea    esp,[esp+0x0]
  Branch9:
    cmp    esi,ecx
    jae    Branch24
    // Cache capacity in EDI for both digits, but reload heap pointer for second character; first digit is low nibble.
    mov    edi,DWORD PTR [edx+0x18]
    add    edx,0x4
    cmp    edi,0x8
    jb     Branch10
    mov    eax,DWORD PTR [edx]
    jmp    Branch11
  Branch10:
    mov    eax,edx
  Branch11:
    mov    ax,WORD PTR [eax+esi*2]
    cmp    ax,0x30
    jb     Branch12
    cmp    ax,0x39
    ja     Branch12
    sub    al,0x30
    jmp    Branch15
  Branch12:
    cmp    ax,0x41
    jb     Branch13
    cmp    ax,0x46
    ja     Branch13
    sub    al,0x37
    jmp    Branch15
  Branch13:
    cmp    ax,0x61
    jb     Branch14
    cmp    ax,0x66
    ja     Branch14
    sub    al,0x57
    jmp    Branch15
  Branch14:
    xor    al,al
  Branch15:
    // Invalid UTF16 digits become zero; drop unmatched final first digit without appending.
    and    al,0xf
    inc    esi
    cmp    esi,ecx
    mov    bl,al
    jae    Branch24
    cmp    edi,0x8
    jb     Branch16
    mov    eax,DWORD PTR [edx]
    jmp    Branch17
  Branch16:
    mov    eax,edx
  Branch17:
    mov    ax,WORD PTR [eax+esi*2]
    cmp    ax,0x30
    jb     Branch18
    cmp    ax,0x39
    ja     Branch18
    sub    al,0x30
    jmp    Branch21
  Branch18:
    cmp    ax,0x41
    jb     Branch19
    cmp    ax,0x46
    ja     Branch19
    sub    al,0x37
    jmp    Branch21
  Branch19:
    cmp    ax,0x61
    jb     Branch20
    cmp    ax,0x66
    ja     Branch20
    sub    al,0x57
    jmp    Branch21
  Branch20:
    xor    al,al
  Branch21:
    // Second nibble goes high; form byte-local and advance source index by2.
    mov    edx,DWORD PTR [esp+0x20]
    shl    al,0x4
    or     bl,al
    inc    esi
    test   ebp,ebp
    mov    BYTE PTR [esp+0x13],bl
    je     Branch22
    mov    ecx,DWORD PTR [esp+0x24]
    mov    eax,edx
    sub    eax,ebp
    sub    ecx,ebp
    cmp    eax,ecx
    jae    Branch22
    mov    BYTE PTR [edx],bl
    inc    edx
    mov    DWORD PTR [esp+0x20],edx
    jmp    Branch23
  Branch22:
    // Slow byte insertion reloads cached begin afterward; direct path retains existing cached begin.
    lea    eax,[esp+0x13]
    push   eax
    push   0x1
    push   edx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::InsertRepeatedByte
    mov    ebp,DWORD PTR [esp+0x1c]
  Branch23:
    // Reload original encoded-text argument and length after a completed pair.
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    ecx,DWORD PTR [ecx+0x14]
    cmp    esi,ecx
    jb     Branch8
  Branch24:
    pop    edi
    pop    ebx
  Branch25:
    // Late-load output, execute copy constructor34610, then free cached temporary begin EBP with state0 still live.
    mov    esi,DWORD PTR [esp+0x30]
    lea    edx,[esp+0x10]
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyByteVector
    test   ebp,ebp
    je     Branch26
    push   ebp
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch26:
    mov    ecx,DWORD PTR [esp+0x20]
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  }
}

// Tail-destroys the encoder local CRT string at inherited parent EBP-0x2c.
// R6GameService.dll @ 10066440 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideHexEncoderText(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Clears ownership bit0 before tail-destroying the current hidden encoder result.
// R6GameService.dll @ 10066449 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyConstructedWideHexResult(void)
{
  __asm {
    // Clear bit0 at inherited EBP-30 before reloading hidden result EBP+4 and tail current CRT destructor.
    mov    eax,DWORD PTR [ebp-0x30]
    and    eax,0x1
    je     Branch27
    and    DWORD PTR [ebp-0x30],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  Branch27:
    ret
  }
}

// Selects encoder metadata for local text and guarded hidden-result lifetimes.
// R6GameService.dll @ 10066463 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WideHexEncoderExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WideHexEncoderExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-releases the local byte vector at inherited parent EBP-0x1c for decoder or checksum-builder cleanup.
// R6GameService.dll @ 100664c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroySharedLocalByteVector(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Selects the pooled local byte-vector metadata shared by decoding and checksum construction.
// R6GameService.dll @ 100664c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl LocalByteVectorExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::LocalByteVectorExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
