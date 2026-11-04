#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080890 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo WideHexEncoderExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080954 : shared decoder/checksum local-vector cleanup.
const R6GameServiceNative::UnwindEntry LocalByteVectorUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroySharedLocalByteVector},
};
// R6GameService.dll data @ 1008095c : one owned local vector, with no try/catch map.
const R6GameServiceNative::FuncInfo LocalByteVectorExceptionHandlerFunctionInfo = {
  0x19930520, 1, R6GameServiceAddresses::LocalByteVectorUnwindMap, 0, 0, 0, 0,
};

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

// Inferred state0 cleanup for the decoder's local descriptor; normal free retains ownership until it returns.
struct WideHexVectorCleanup {
  uint *vector;
  bool armed;
  ~WideHexVectorCleanup() noexcept(false) {
    if (armed) ReleaseAndResetStorageAt04((int)vector);
  }
};

// Decodes low-first wide hex pairs, maps invalid digits to zero, drops an odd digit and copy-constructs the result.
// R6GameService.dll @ 10034710 : cdecl result/input words; returns the result pointer captured after decoding.
void *__cdecl DecodeWideHexToByteVector(void *outputVector,const std::basic_string<unsigned short> *encodedText)
{
  uint temporary[4];
  temporary[1] = 0;
  temporary[2] = 0;
  temporary[3] = 0;
  uint index = 0;
  uint cachedBegin = 0;
  byte *input = (byte *)encodedText;
  uint length = *(uint *)(input + 0x14);
  WideHexVectorCleanup cleanup{temporary, true};
  auto nibble = [](ushort unit) -> byte {
    if (unit >= '0' && unit <= '9') return (byte)(unit - '0');
    if (unit >= 'A' && unit <= 'F') return (byte)(unit - 'A' + 10);
    if (unit >= 'a' && unit <= 'f') return (byte)(unit - 'a' + 10);
    return 0;
  };
  if (length != 0) {
    while (index < length) {
      uint capacity = *(uint *)(input + 0x18);
      byte *storage = input + 4;
      const ushort *characters = capacity < 8 ? (const ushort *)storage : *(const ushort **)storage;
      byte low = nibble(characters[index]) & 0xf;
      ++index;
      if (index >= length) break;
      characters = capacity < 8 ? (const ushort *)storage : *(const ushort **)storage;
      byte high = nibble(characters[index]);
      uint end = temporary[2];
      byte value = low | (byte)(high << 4);
      ++index;
      bool direct = false;
      if (cachedBegin != 0) {
        uint limit = temporary[3];
        direct = end - cachedBegin < limit - cachedBegin;
      }
      if (direct) {
        *(byte *)end = value;
        temporary[2] = end + 1;
      } else {
        InsertRepeatedByte(temporary,(byte *)end,1,&value);
        cachedBegin = temporary[1];
      }
      byte *currentInput = (byte *)encodedText;
      length = *(uint *)(currentInput + 0x14);
      if (index >= length) break;
      input = (byte *)encodedText;
    }
  }
  void *output = outputVector;
  CopyByteVector(output,temporary);
  if (cachedBegin != 0) FreeThroughGlobalAllocator((void *)cachedBegin);
  cleanup.armed = false;
  return output;
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
