#include "native_addresses.h"
#include "native_records.h"

// Physical by-value Core FString argument; the callee consumes these three words.
struct NativeFStringArgument12 { uint words[3]; };

// Physical by-value MSVCP71 wide-string argument; raw storage avoids adding automatic C++ ownership.
struct NativeWideStringArgument28 { uint words[7]; };

// R6GameService.dll data @ 1007aa14 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo EncryptWrapperExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080988 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo EncryptWideHexExceptionHandlerFunctionInfo;

// R6GameService.dll data @ 1007aa30 : native key conversion lifetime/guard record.
const R6GameServiceNative::UnwindEntry DecryptWrapperUnwindMap[5] = {
  {-1, R6GameServiceAddresses::DestroyConstructedDecryptResult},
  {0x0, R6GameServiceAddresses::DestroyDecryptInputFString},
  {0x1, 0x0},
  {0x2, R6GameServiceAddresses::DestroyDecryptOutputWideString},
  {0x1, 0x0},
};
// R6GameService.dll data @ 1007aa58 : native key conversion lifetime/guard record.
const R6GameServiceNative::CatchHandler DecryptWrapperCatchHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32, R6GameServiceAddresses::ForwardDecryptWideError},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ReportDecryptException},
};
// R6GameService.dll data @ 1007aa78 : native key conversion lifetime/guard record.
const R6GameServiceNative::TryBlock DecryptWrapperTryMap[1] = {
  {0x2, 0x3, 0x4, 0x2, R6GameServiceAddresses::DecryptWrapperCatchHandlers},
};
// R6GameService.dll data @ 1007aa8c : native key conversion lifetime/guard record.
const R6GameServiceNative::FuncInfo DecryptWrapperExceptionHandlerFunctionInfo = {
  0x19930520, 0x5, R6GameServiceAddresses::DecryptWrapperUnwindMap,
  0x1, R6GameServiceAddresses::DecryptWrapperTryMap, 0x0, 0x0,
};
// R6GameService.dll data @ 1007aaa8 : native key conversion lifetime/guard record.
const R6GameServiceNative::UnwindEntry MachineValidationUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyValidationInputFString},
  {0x0, 0x0},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007aac0 : native key conversion lifetime/guard record.
const R6GameServiceNative::CatchHandler MachineValidationCatchHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
   R6GameServiceAddresses::ForwardMachineValidationWideError},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::ReportMachineValidationException},
};
// R6GameService.dll data @ 1007aae0 : native key conversion lifetime/guard record.
const R6GameServiceNative::TryBlock MachineValidationTryMap[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::MachineValidationCatchHandlers},
};
// R6GameService.dll data @ 1007aaf4 : native key conversion lifetime/guard record.
const R6GameServiceNative::FuncInfo MachineValidationExceptionHandlerFunctionInfo = {
  0x19930520, 0x3, R6GameServiceAddresses::MachineValidationUnwindMap,
  0x1, R6GameServiceAddresses::MachineValidationTryMap, 0x0, 0x0,
};
// R6GameService.dll data @ 100809a4 : native key conversion lifetime/guard record.
const R6GameServiceNative::UnwindEntry DecryptWideHexUnwindMap[5] = {
  {-1, R6GameServiceAddresses::DestroyConstructedDecryptWideResult},
  {0x0, R6GameServiceAddresses::DestroyDecryptEncodedInput},
  {0x1, R6GameServiceAddresses::DestroyDecryptPayloadBytes},
  {0x2, R6GameServiceAddresses::DestroyDecryptSeedBytes},
  {0x3, R6GameServiceAddresses::DestroyDecryptTemporaryText},
};
// R6GameService.dll data @ 100809cc : native key conversion lifetime/guard record.
const R6GameServiceNative::FuncInfo DecryptWideHexExceptionHandlerFunctionInfo = {
  0x19930520, 0x5, R6GameServiceAddresses::DecryptWideHexUnwindMap, 0x0, 0x0, 0x0, 0x0,
};
// R6GameService.dll data @ 100809e8 : native key conversion lifetime/guard record.
const R6GameServiceNative::UnwindEntry ValidateWideHexUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyWideValidationEncodedInput},
  {0x0, R6GameServiceAddresses::DestroyWideValidationPayload},
};
// R6GameService.dll data @ 100809f8 : native key conversion lifetime/guard record.
const R6GameServiceNative::FuncInfo ValidateWideHexExceptionHandlerFunctionInfo = {
  0x19930520, 0x2, R6GameServiceAddresses::ValidateWideHexUnwindMap, 0x0, 0x0, 0x0, 0x0,
};

// Wrappers reported under UeviLCore by their native exception context; original static declarations are unresolved.

// Converts an owned FString, encrypts through a local CRT string and constructs the hidden FString result.
// R6GameService.dll @ 100017d0 : complete native control/access order and raw ABI retained.
__declspec(naked) FString * __cdecl EncryptFStringWithUeviLCore(FString *hiddenResult,FString input)
{
  __asm {
    // Reported UeviLCore scope; explicit hidden result plus owned 12-byte input, cdecl/plain RET.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::EncryptWrapperExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    // Result ownership flag at EBP-14 starts0. State1 owns input; state2 is the guarded try region.
    mov    DWORD PTR [ebp-0x14],0x0
    mov    edi,0x1
    mov    DWORD PTR [ebp-0x4],edi
    lea    ecx,[ebp+0xc]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    // Construct local CRT input at-54 from raw FString operator* return. Constructor EAX goes to helper.
    push   eax
    lea    ecx,[ebp-0x54]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2
    // Helper34bc0 gets hidden local output-38 and returned input pointer; local cleanup still owns-54.
    push   eax
    lea    eax,[ebp-0x38]
    mov    bl,0x3
    push   eax
    mov    BYTE PTR [ebp-0x4],bl
    call   R6GameServiceAddresses::EncryptWideStringToHex
    add    esp,0x8
    // Select inline/heap data from helper returned EAX, independently of local output cleanup storage.
    cmp    DWORD PTR [eax+0x18],0x8
    mov    BYTE PTR [ebp-0x4],0x4
    jb     Branch1
    mov    eax,DWORD PTR [eax+0x4]
    jmp    Branch2
  Branch1:
    add    eax,0x4
  Branch2:
    mov    esi,DWORD PTR [ebp+0x8]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    // Own hidden FString result only after construction succeeds; lower state before each local/input destructor.
    lea    ecx,[ebp-0x38]
    mov    DWORD PTR [ebp-0x14],edi
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[ebp-0x54]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[ebp+0xc]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught wide-pointer value into throw storage and forwards it with the selected throw descriptor.
// R6GameService.dll @ 10001883 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ForwardEncryptWideError(void)
{
  __asm {
    // Inherited EBP; typed pointer catch offset-1c, forwarding storage-18, noreturn throw.
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UeviLCore::Encrypt context, then forwards the active exception through the native throw helper.
// R6GameService.dll @ 10001897 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReportEncryptException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLCoreEncrypt
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Inferred physical wrapper locals from EBP-3c: CRT text, caught pointer, outgoing slot, forwarded pointer and flags.
struct FStringDecryptionLocals {
  uint text[7];
  uint caught;
  uint outgoing;
  uint forwarded;
  uint resultBits;
};

// Retain incoming/result ownership and unwind only the active CRT temporary before entering the native catch range.
struct FStringDecryptionCleanup {
  FStringDecryptionLocals *frame;
  uint *incoming;
  FString **resultSlot;
  int state;
  bool armed;
  // Catch state4 bypasses the local CRT lifetime after the try range has released it.
  void enterCatch()
  {
    if (state == 3) {
      state = 2;
      using DestroyABI = uint (__thiscall *)(void *);
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(frame->text);
    }
    state = 4;
  }
  // Destroy current incoming/result storage in native order, clearing the result bit before its current pointer read.
  ~FStringDecryptionCleanup() noexcept(false)
  {
    if (!armed) return;
    using DestroyABI = void (__thiscall *)(void *);
    while (state >= 0) {
      if (state == 4) state = 1;
      else if (state == 3) {
        state = 2;
        (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(frame->text);
      } else if (state == 2) state = 1;
      else if (state == 1) {
        state = 0;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(incoming);
      } else {
        state = -1;
        if ((frame->resultBits & 1) != 0) {
          frame->resultBits &= 0xfffffffe;
          FString *result = *resultSlot;
          (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(result);
        }
      }
    }
  }
};

// Convert the owned FString through a transferred CRT string, then construct the explicit hidden FString result.
// Use returned CRT storage for text selection but destroy the distinct local output; retain native typed/error catches.
// R6GameService.dll @ 100018c0 : raw owned three-word FString argument, cdecl RET0 and cached hidden-result EAX.
FString * __cdecl DecryptFStringWithUeviLCore(FString *hiddenResult,NativeFStringArgument12 input)
{
  FStringDecryptionLocals frame;
  frame.resultBits = 0;
  FStringDecryptionCleanup cleanup{&frame,input.words,&hiddenResult,1,true};
  FString *output;
  using DataABI = const ushort * (__thiscall *)(const void *);
  using ConstructABI = void * (__thiscall *)(void *,const ushort *);
  using DestroyABI = void (__thiscall *)(void *);
  try {
    cleanup.state = 2;
    const ushort *text = (*(DataABI *)R6GameServiceAddresses::Core__DFStringSlot)(input.words);
    NativeWideStringArgument28 outgoing;
    frame.outgoing = (uint)&outgoing;
    (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2)(&outgoing,text);
    using DecryptABI = NativeWideStringArgument28 * (__cdecl *)(
        NativeWideStringArgument28 *,NativeWideStringArgument28);
    NativeWideStringArgument28 *returned = ((DecryptABI)R6GameServiceAddresses::DecryptHexToWideString)(
        (NativeWideStringArgument28 *)frame.text,outgoing);
    uint capacity = returned->words[6];
    cleanup.state = 3;
    const ushort *decoded = capacity < 8 ? (const ushort *)(returned->words + 1) : (const ushort *)returned->words[1];
    output = hiddenResult;
    (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)(output,decoded);
    frame.resultBits = 1;
    cleanup.state = 2;
    (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(frame.text);
  } catch (ushort *error) {
    cleanup.enterCatch();
    frame.caught = (uint)error;
    frame.forwarded = frame.caught;
    throw (ushort *)frame.forwarded;
  } catch (...) {
    cleanup.enterCatch();
    using ReportABI = void (__cdecl *)(const ushort *,...);
    (*(ReportABI *)R6GameServiceAddresses::Core__appUnwindfSlot)(
        (const ushort *)R6GameServiceAddresses::WideTextTextFormat,
        (const ushort *)R6GameServiceAddresses::WideTextUeviLCoreDecrypt);
    throw;
  }
  cleanup.state = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(input.words);
  cleanup.armed = false;
  return output;
}

// Copies the caught decryption wide pointer into throw storage and forwards it with the selected descriptor.
// R6GameService.dll @ 10001966 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ForwardDecryptWideError(void)
{
  __asm {
    // Inherited typed pointer catch offset-20, forwarding storage-18; noreturn throw.
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UeviLCore::Decrypt context, then forwards the active exception through the native throw helper.
// R6GameService.dll @ 1000197a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReportDecryptException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLCoreDecrypt
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Inferred validation-wrapper slots at EBP-1c/-18/-14 for catch/transfer/forwarded words.
struct FStringValidationLocals {
  uint caught;
  uint outgoing;
  uint forwarded;
};

// Empty try/catch states retain incoming FString ownership; entered incoming destruction is never retried.
struct FStringValidationCleanup {
  uint *incoming;
  int state;
  bool armed;
  // Collapse the native empty state1/2 actions before destroying the owned three-word input.
  ~FStringValidationCleanup() noexcept(false)
  {
    if (!armed) return;
    while (state >= 0) {
      if (state != 0) state = 0;
      else {
        state = -1;
        using DestroyABI = void (__thiscall *)(void *);
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(incoming);
      }
    }
  }
};

// Validate an owned FString through a transferred CRT string and return the helper's zero-extended raw AL.
// Native pointer catches forward their value; other errors report validation context before rethrowing.
// R6GameService.dll @ 100019a0 : raw owned three-word FString argument, cdecl RET0 and zero-extended byte EAX.
uint __cdecl IsCDKeyValidOnMachine(NativeFStringArgument12 input)
{
  FStringValidationLocals frame;
  FStringValidationCleanup cleanup{input.words,0,true};
  using DataABI = const ushort * (__thiscall *)(const void *);
  using ConstructABI = void * (__thiscall *)(void *,const ushort *);
  using DestroyABI = void (__thiscall *)(void *);
  uint output;
  try {
    cleanup.state = 1;
    const ushort *text = (*(DataABI *)R6GameServiceAddresses::Core__DFStringSlot)(input.words);
    NativeWideStringArgument28 outgoing;
    frame.outgoing = (uint)&outgoing;
    (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2)(&outgoing,text);
    using ValidateABI = uint (__cdecl *)(NativeWideStringArgument28);
    uint validated = ((ValidateABI)R6GameServiceAddresses::ValidateWideHexMachineChecksum)(outgoing);
    output = (byte)validated;
  } catch (ushort *error) {
    cleanup.state = 2;
    frame.caught = (uint)error;
    frame.forwarded = frame.caught;
    throw (ushort *)frame.forwarded;
  } catch (...) {
    cleanup.state = 2;
    using ReportABI = void (__cdecl *)(const ushort *,...);
    (*(ReportABI *)R6GameServiceAddresses::Core__appUnwindfSlot)(
        (const ushort *)R6GameServiceAddresses::WideTextTextFormat,
        (const ushort *)R6GameServiceAddresses::WideTextUeviLCoreIsCDKeyValidOnMachine);
    throw;
  }
  cleanup.state = -1;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(input.words);
  cleanup.armed = false;
  return output;
}

// Copies the caught validation wide pointer into throw storage and forwards it with the selected descriptor.
// R6GameService.dll @ 10001a12 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ForwardMachineValidationWideError(void)
{
  __asm {
    // Inherited typed pointer catch offset-1c, forwarding storage-14; noreturn throw.
    mov    eax,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UeviLCore::IsCDKeyValidOnMachine context, then forwards the active exception.
// R6GameService.dll @ 10001a26 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReportMachineValidationException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLCoreIsCDKeyValidOnMachine
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Tail-destroys the by-value encryption FString at inherited parent EBP+0xc.
// R6GameService.dll @ 100630b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEncryptInputFString(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-destroys the local encryption input CRT string at inherited parent EBP-0x54.
// R6GameService.dll @ 100630b9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEncryptInputWideString(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-destroys the local encryption output CRT string at inherited parent EBP-0x38.
// R6GameService.dll @ 100630c2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEncryptOutputWideString(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Clears result ownership bit0 before tail-destroying the current hidden encryption result.
// R6GameService.dll @ 100630cb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyConstructedEncryptResult(void)
{
  __asm {
    // Test low ownership bit at parentEBP-14, clear before tail call, then reload current hidden result at+8.
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    je     Branch5
    and    DWORD PTR [ebp-0x14],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch5:
    ret
  }
}

// Selects encryption wrapper metadata for local strings, owned input, guarded result and catches.
// R6GameService.dll @ 100630e5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EncryptWrapperExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::EncryptWrapperExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-destroys the by-value decryption FString at inherited parent EBP+0xc.
// R6GameService.dll @ 100630f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptInputFString(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-destroys the local decryption output CRT string at inherited parent EBP-0x3c.
// R6GameService.dll @ 100630f9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptOutputWideString(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Clears result ownership bit0 before tail-destroying the current hidden decryption result.
// R6GameService.dll @ 10063102 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyConstructedDecryptResult(void)
{
  __asm {
    // Preserve other flags while clearing bit0 before current hidden result destruction; clear-bit branch returns EAX0.
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    je     Branch6
    and    DWORD PTR [ebp-0x14],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch6:
    ret
  }
}

// Selects decryption wrapper metadata for owned input, local output, guarded result and catches.
// R6GameService.dll @ 1006311c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecryptWrapperExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DecryptWrapperExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-destroys the by-value machine-validation FString at inherited parent EBP+8.
// R6GameService.dll @ 10063130 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyValidationInputFString(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects machine-validation wrapper metadata for owned input and typed/context catches.
// R6GameService.dll @ 10063139 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl MachineValidationExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MachineValidationExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// XORs each current input code unit low byte with seeded rand output, appends the collected checksum and hex-encodes.
// R6GameService.dll @ 10034bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) std::basic_string<unsigned short> * __cdecl EncryptWideStringToHex(std::basic_string<unsigned short> *output,const std::basic_string<unsigned short> *input)
{
  __asm {
    // ESP-based EH: nominal inherited parent EBP is entryESP; seed vector-1c, payload vector-2c, checksum-30.
    push   0xffffffff
    push   R6GameServiceAddresses::EncryptWideHexExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   ebp
    push   esi
    lea    eax,[esp+0x24]
    push   edi
    xor    esi,esi
    push   eax
    mov    DWORD PTR [esp+0x18],esi
    call   R6GameServiceAddresses::BuildByteVectorFromCollectedStrings
    add    esp,0x4
    // State0 owns collected seed bytes; checksum36770 writes seed, srand mutates shared CRT PRNG state.
    lea    ecx,[esp+0x28]
    push   ecx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x44],esi
    call   R6GameServiceAddresses::UpdateChecksumFromBuffer
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_srandSlot
    xor    ebp,ebp
    add    esp,0x4
    // Initialize payload begin/end/capacity, state1; input pointer and length remain callback-sensitive.
    mov    DWORD PTR [esp+0x1c],esi
    mov    DWORD PTR [esp+0x20],ebp
    mov    DWORD PTR [esp+0x24],esi
    mov    edi,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [edi+0x14]
    xor    ebx,ebx
    cmp    eax,esi
    mov    BYTE PTR [esp+0x40],0x1
    jbe    Branch14
    jmp    Branch8
  Branch7:
    mov    edi,DWORD PTR [esp+0x4c]
  Branch8:
    // Bounds check uses current loop length; select inline/heap pointer before calling current rand import.
    cmp    eax,ebx
    ja     Branch9
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__String_base__XranSlot
  Branch9:
    cmp    DWORD PTR [edi+0x18],0x8
    jb     Branch10
    lea    eax,[edi+0x4]
    mov    edi,DWORD PTR [eax]
    jmp    Branch11
  Branch10:
    add    edi,0x4
  Branch11:
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_randSlot
    // Use only low byte of selected UTF-16 unit, loaded after rand callback; keep capacity check modulo32.
    xor    al,BYTE PTR [edi+ebx*2]
    test   esi,esi
    mov    BYTE PTR [esp+0x13],al
    je     Branch12
    mov    edx,DWORD PTR [esp+0x24]
    mov    ecx,ebp
    sub    ecx,esi
    sub    edx,esi
    cmp    ecx,edx
    jae    Branch12
    mov    BYTE PTR [ebp+0x0],al
    inc    ebp
    mov    DWORD PTR [esp+0x20],ebp
    jmp    Branch13
  Branch12:
    // Slow insertion receives vector, cached end, count1 and byte-local address; reload begin/end afterward.
    lea    eax,[esp+0x13]
    push   eax
    push   0x1
    push   ebp
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::InsertRepeatedByte
    mov    ebp,DWORD PTR [esp+0x20]
    mov    esi,DWORD PTR [esp+0x1c]
  Branch13:
    // Reload original input argument and length after every byte; input storage selection is per iteration.
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    eax,DWORD PTR [ecx+0x14]
    inc    ebx
    cmp    ebx,eax
    jb     Branch7
    xor    esi,esi
  Branch14:
    // Append collected checksum then encode into late-loaded hidden result; keep all three cdecl args staged.
    lea    edx,[esp+0x18]
    push   edx
    call   R6GameServiceAddresses::AppendCollectedStringsChecksumBytes
    mov    edi,DWORD PTR [esp+0x4c]
    lea    eax,[esp+0x1c]
    push   eax
    push   edi
    call   R6GameServiceAddresses::ConvertByteRangeToWideHexText
    // Reload current payload/seed begin pointers for normal frees; state1 stays live and fields are not reset here.
    mov    eax,DWORD PTR [esp+0x28]
    add    esp,0xc
    cmp    eax,esi
    je     Branch15
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch15:
    mov    eax,DWORD PTR [esp+0x2c]
    cmp    eax,esi
    je     Branch16
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch16:
    mov    ecx,DWORD PTR [esp+0x38]
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  }
}

// Inferred physical decryption locals from entry ESP-0x54 through ESP-0x10, including the saved security cookie.
struct WideDecryptionLocals {
  uint checksum;
  uint resultBits;
  uint seed[4];
  uint payload[4];
  uint text[7];
  uint cookie;
};

// Retain each current vector/string and the current hidden result only after its ownership bit is set.
struct WideDecryptionCleanup {
  WideDecryptionLocals *frame;
  uint *incoming;
  NativeWideStringArgument28 **resultSlot;
  int state;
  bool armed;
  // Normal entered destruction skips that object; result ownership is cleared before reloading its current pointer.
  ~WideDecryptionCleanup() noexcept(false)
  {
    if (!armed) return;
    using DestroyABI = uint (__thiscall *)(void *);
    while (state >= 0) {
      switch (state) {
      case 4:
        state = 3;
        (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(frame->text);
        break;
      case 3:
        state = 2;
        ReleaseAndResetStorageAt04((int)frame->seed);
        break;
      case 2:
        state = 1;
        ReleaseAndResetStorageAt04((int)frame->payload);
        break;
      case 1:
        state = 0;
        (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(incoming);
        break;
      case 0:
        state = -1;
        if ((frame->resultBits & 1) != 0) {
          frame->resultBits &= 0xfffffffe;
          void *result = *resultSlot;
          (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(result);
        }
        break;
      }
    }
  }
};

// Decode hex, discard its checksum, reverse the seeded byte XOR and sign-extend decoded bytes into wide characters.
// Preserve the cached payload/rand target, full append word, current hidden output and transferred input ownership.
// R6GameService.dll @ 10034d00 : raw seven-word CRT argument, explicit result/cookie ABI and native five-state cleanup.
NativeWideStringArgument28 * __cdecl DecryptHexToWideString(
    NativeWideStringArgument28 *hiddenResult,NativeWideStringArgument28 encodedInput)
{
  WideDecryptionLocals frame;
  frame.cookie = *(uint *)R6GameServiceAddresses::GSecurityCookie;
  frame.resultBits = 0;
  WideDecryptionCleanup cleanup{&frame,encodedInput.words,&hiddenResult,1,true};
  using DecodeABI = void * (__cdecl *)(void *,const void *);
  using VectorABI = void * (__cdecl *)(void *);
  using PopABI = uint (__cdecl *)(void *);
  using ChecksumABI = uint * (__thiscall *)(uint *,const void *);
  using SrandABI = void (__cdecl *)(uint);
  using RandABI = uint (__cdecl *)();
  using DefaultABI = void * (__thiscall *)(void *);
  using AppendABI = void * (__thiscall *)(void *,uint);
  using CopyABI = void * (__thiscall *)(void *,const void *);
  using DestroyABI = uint (__thiscall *)(void *);
  using FreeABI = void (__cdecl *)(void *);
  ((DecodeABI)R6GameServiceAddresses::DecodeWideHexToByteVector)(frame.payload,encodedInput.words);
  cleanup.state = 2;
  ((PopABI)R6GameServiceAddresses::PopTrailingBigEndianDword)(frame.payload);
  ((VectorABI)R6GameServiceAddresses::BuildByteVectorFromCollectedStrings)(frame.seed);
  cleanup.state = 3;
  ((ChecksumABI)R6GameServiceAddresses::UpdateChecksumFromBuffer)(&frame.checksum,frame.seed);
  (*(SrandABI *)R6GameServiceAddresses::MSVCR71_srandSlot)(frame.checksum);
  (*(DefaultABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3)(frame.text);
  uint payloadEnd = frame.payload[2];
  uint payloadBegin = frame.payload[1];
  RandABI random = *(RandABI *)R6GameServiceAddresses::MSVCR71_randSlot;
  cleanup.state = 4;
  for (uint index = 0; payloadBegin != 0 && index < payloadEnd - payloadBegin; ++index) {
    uint value = random();
    byte decoded = (byte)value ^ *(byte *)(payloadBegin + index);
    uint lowWord = decoded < 0x80 ? decoded : 0xff00 | decoded;
    (*(AppendABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot)(
        frame.text,(value & 0xffff0000) | lowWord);
  }
  NativeWideStringArgument28 *output = hiddenResult;
  (*(CopyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot)(output,frame.text);
  frame.resultBits = 1;
  cleanup.state = 3;
  (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(frame.text);
  void *seed = (void *)frame.seed[1];
  if (seed != nullptr) ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)(seed);
  frame.seed[1] = 0;
  frame.seed[2] = 0;
  frame.seed[3] = 0;
  if (payloadBegin != 0) ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)payloadBegin);
  cleanup.state = 0;
  (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(encodedInput.words);
  cleanup.armed = false;
  using CookieABI = void (__fastcall *)(uint);
  ((CookieABI)R6GameServiceAddresses::__security_check_cookie)(frame.cookie);
  return output;
}

// Retain decoded-vector cleanup until incoming destruction is entered; a throwing normal free leaves the vector live.
struct WideChecksumValidationCleanup {
  uint *payload;
  uint *incoming;
  int state;
  bool armed;
  // The vector action releases current storage before resetting fields; entered incoming destruction is not retried.
  ~WideChecksumValidationCleanup() noexcept(false)
  {
    if (!armed) return;
    if (state == 1) {
      state = 0;
      ReleaseAndResetStorageAt04((int)payload);
    }
    if (state == 0) {
      state = -1;
      using DestroyABI = uint (__thiscall *)(void *);
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(incoming);
    }
  }
};

// Compare the decoded trailing checksum with the current collected-string checksum and consume the owned CRT input.
// Preserve final destructor upper EAX with comparison AL; the normal free leaves vector words live.
// R6GameService.dll @ 10034e50 : raw seven-word CRT argument, cdecl RET0 and two native ownership states.
uint __cdecl ValidateWideHexMachineChecksum(NativeWideStringArgument28 encodedInput)
{
  uint payload[4];
  WideChecksumValidationCleanup cleanup{payload,encodedInput.words,0,true};
  using DecodeABI = void * (__cdecl *)(void *,const void *);
  using PopABI = uint (__cdecl *)(void *);
  using ChecksumABI = uint (__cdecl *)();
  using FreeABI = void (__cdecl *)(void *);
  using DestroyABI = uint (__thiscall *)(void *);
  ((DecodeABI)R6GameServiceAddresses::DecodeWideHexToByteVector)(payload,encodedInput.words);
  cleanup.state = 1;
  uint embedded = ((PopABI)R6GameServiceAddresses::PopTrailingBigEndianDword)(payload);
  uint current = ((ChecksumABI)R6GameServiceAddresses::ComputeCollectedStringsChecksum)();
  bool matches = embedded == current;
  void *allocation = (void *)payload[1];
  if (allocation != nullptr) ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)(allocation);
  cleanup.state = -1;
  uint residue = (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot)(
      encodedInput.words);
  cleanup.armed = false;
  return (residue & 0xffffff00) | (uint)matches;
}

// Tail-releases the encryption seed byte vector at inherited parent EBP-0x1c.
// R6GameService.dll @ 100664e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEncryptSeedBytes(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Tail-releases the encryption payload byte vector at inherited parent EBP-0x2c.
// R6GameService.dll @ 100664e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyEncryptPayloadBytes(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Selects the encryption helper metadata for its seed and payload vector lifetimes.
// R6GameService.dll @ 100664f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl EncryptWideHexExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::EncryptWideHexExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-destroys the decryption helper by-value CRT string at inherited parent EBP+8.
// R6GameService.dll @ 10066500 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptEncodedInput(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-releases decoded decryption payload bytes at inherited parent EBP-0x3c.
// R6GameService.dll @ 10066509 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptPayloadBytes(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Tail-releases decryption seed bytes at inherited parent EBP-0x4c.
// R6GameService.dll @ 10066511 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptSeedBytes(void)
{
  __asm {
    lea    ecx,[ebp-0x4c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Tail-destroys the decryption helper local CRT string at inherited parent EBP-0x2c.
// R6GameService.dll @ 10066519 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDecryptTemporaryText(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Clears result ownership bit0 before tail-destroying the current hidden decryption CRT result.
// R6GameService.dll @ 10066522 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyConstructedDecryptWideResult(void)
{
  __asm {
    // Test/clear ownership bit0 at inherited EBP-50 before reloading hidden output at+4 and tail destructor.
    mov    eax,DWORD PTR [ebp-0x50]
    and    eax,0x1
    je     Branch22
    and    DWORD PTR [ebp-0x50],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  Branch22:
    ret
  }
}

// Selects decryption helper metadata for the owned input, vectors, temporary text and guarded result.
// R6GameService.dll @ 1006653c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecryptWideHexExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DecryptWideHexExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail-destroys the validator by-value CRT string at inherited parent EBP+4.
// R6GameService.dll @ 10066550 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideValidationEncodedInput(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-releases the validator decoded byte vector at inherited parent EBP-0x1c.
// R6GameService.dll @ 10066559 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyWideValidationPayload(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Selects validator metadata for the owned input and decoded byte vector.
// R6GameService.dll @ 10066561 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateWideHexExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ValidateWideHexExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
