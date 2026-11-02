#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080814 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo VectorLengthThrowExceptionHandlerFunctionInfo;

// Free vector-length throw helper and its native temporary/partial-base lifetime actions.
// Exact native diagnostic bytes; alignment padding after its terminator is not part of this array.
// R6GameService.dll data @ 100770ec : native storage identity retained.
const char GVectorLengthDiagnostic[] = "vector<T> too long";

// Builds the vector length diagnostic and throws the native std::length_error object through exact ThrowInfo.
// R6GameService.dll @ 10033fa0 : complete native control/access order and raw ABI retained.
__declspec(naked) [[noreturn]] void ThrowVectorLengthException(void)
{
  __asm {
    // ESP-based EH66432: message entryESP-50, thrown object -34/message -28, exact literal770ec.
    push   0xffffffff
    push   R6GameServiceAddresses::VectorLengthThrowExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x44
    push   offset GVectorLengthDiagnostic
    lea    ecx,[esp+0x4]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot
    // State0 starts after temporary string ctor. Default CRT exception ctor runs before state1.
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x4c],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__ConstructexceptionSlot
    // State1 owns partial CRT exception base while copying diagnostic into object+c; base vtable770dc is published.
    lea    eax,[esp]
    push   eax
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x20],offset GLogicErrorVtable
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2
    // Lower to state0, install derived770e4, pass object entryESP-34 and exact ThrowInfo807f4 to noreturn33a16.
    push   0x100807f4
    lea    ecx,[esp+0x20]
    push   ecx
    mov    BYTE PTR [esp+0x54],0x0
    mov    DWORD PTR [esp+0x24],offset GLengthErrorVtable
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the throw helper parent-frame temporary diagnostic string.
// R6GameService.dll @ 10066420 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyVectorLengthMessageOnUnwind(void)
{
  __asm {
    // Inherited throw-helper parent-50 narrow string; current CRT destructor IAT retained.
    lea    ecx,[ebp-0x50]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys only the partial throw-object CRT exception base during message-copy failure.
// R6GameService.dll @ 10066429 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyPartialLengthErrorBaseOnUnwind(void)
{
  __asm {
    // Inherited parent-34 receives only CRT exception destructor, not the complete derived or message destructor.
    lea    ecx,[ebp-0x34]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCR71__DestroyexceptionSlot
  }
}

// Selects the diagnostic-message and partial-base unwind states for the length_error throw helper.
// R6GameService.dll @ 10066432 : complete native control/access order and raw ABI retained.
__declspec(naked) void VectorLengthThrowExceptionHandler(void)
{
  __asm {
    // FuncInfo80814/map80804=(-1,66420),(0,66429), no catches. Actual throw runs in state0.
    mov    eax,R6GameServiceAddresses::VectorLengthThrowExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
