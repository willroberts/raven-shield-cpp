#include "native_addresses.h"
#include "native_records.h"

// Unassigned RPC binding/process-handle helpers; names describe native roles without inventing an owning class.
// Cleanup return types expose raw EAX; original declarations are unrecovered. Wide literals use the selected 16-bit ABI.
// R6GameService.dll data @ 10077758 : native storage identity retained.
const char GRpcConnectError[] = "Error connecting to RPC server: ";
// R6GameService.dll data @ 10077780 : native storage identity retained.
const wchar_t GRpcBindingExceptionFormat[] = L"Error connecting to RPC server: 0x%lx = %ld\n";
// R6GameService.dll data @ 100777dc : native storage identity retained.
const char GRpcComposeError[] = "Error binding RPC string: ";
// R6GameService.dll data @ 100777f8 : native storage identity retained.
const wchar_t GLocalRpcProtocol[] = L"ncalrpc";
// R6GameService.dll data @ 10077808 : native storage identity retained.
const R6GameServiceNative::SehScope GRpcBindingScope[1] = {
  {-1, R6GameServiceAddresses::FilterRpcBindingException, R6GameServiceAddresses::HandleRpcBindingException},
};

// Clears the composed-string and handle-slot pointer words and returns the original state.
// R6GameService.dll @ 100368a0 : complete native control/access order and raw ABI retained.
void * __fastcall InitializeRpcBindingState(void *state)
{
  auto *words = static_cast<uint *>(state);
  words[0] = 0;
  words[1] = 0;
  return state;
}

// Releases the current handle through its retained slot address, then the current composed RPC string.
// R6GameService.dll @ 100368b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseRpcBindingState(void *state)
{
  __asm {
    // Cache owner ESI. Field+4 is a handle-slot address, not the handle value; no native clear of this field.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch1
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::RPCRT4_RpcBindingFreeSlot
  Branch1:
    // Read current composed string only after RpcBindingFree returns; RpcStringFreeW receives state address.
    cmp    DWORD PTR [esi],0x0
    je     Branch2
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::RPCRT4_RpcStringFreeWSlot
  Branch2:
    pop    esi
    ret
  }
}

// Composes a local RPC string, binds through the caller slot and retains native status/logging/exception behavior.
// R6GameService.dll @ 100368d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ComposeLocalRpcBinding(void *state,void **handleSlot,const unsigned short *endpoint)
{
  __asm {
    // Explicit SEH: saved receiver-24, status-1c, exception code-20. Clear only composed string before compose.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   offset GRpcBindingScope
    push   R6GameServiceAddresses::ForwardExceptHandler3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x24],esi
    mov    DWORD PTR [esi],0x0
    // RpcStringBindingComposeW(null,ncalrpc,null,endpoint,null,state). Existing field+4 remains live.
    push   esi
    push   0x0
    mov    eax,DWORD PTR [ebp+0xc]
    push   eax
    push   0x0
    push   offset GLocalRpcProtocol
    push   0x0
    call   DWORD PTR ds:R6GameServiceAddresses::RPCRT4_RpcStringBindingComposeWSlot
    mov    edi,eax
    mov    DWORD PTR [ebp-0x1c],edi
    test   edi,edi
    je     Branch3
    // Compose failure: cache current endl before log getter/insertion; status and text remain pending stack arguments.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    push   edi
    push   offset GRpcComposeError
    jmp    Branch5
  Branch3:
    // State0 covers only binding-from-string call, using current handle-slot argument/current composed string.
    mov    DWORD PTR [ebp-0x4],0x0
    mov    edx,DWORD PTR [ebp+0x8]
    push   edx
    mov    eax,DWORD PTR [esi]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::RPCRT4_RpcBindingFromStringBindingWSlot
    mov    edi,eax
    mov    DWORD PTR [ebp-0x1c],edi
    mov    DWORD PTR [ebp-0x4],0xffffffff
    jmp    Branch4
  Branch4:
    // Native shared result continuation @10036984, after separate filter/handler; EDI status may still be0 after exception.
    test   edi,edi
    je     Branch6
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    push   edi
    push   offset GRpcConnectError
  Branch5:
    // Insert ANSI label into returned wide stream, then signed LONG status and cached endl; ignore stream raw EAX.
    call   R6GameServiceAddresses::GetDirectoryLogFirstWord
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot4
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    mov    eax,edi
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  Branch6:
    // Success reloads current original handle-slot argument and stores its address into current cached receiver+4.
    mov    edx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esi+0x4],edx
    xor    eax,eax
    mov    ecx,DWORD PTR [ebp-0x10]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Stores the binding-call exception code and returns the constant native handler disposition.
// R6GameService.dll @ 10036951 : complete native control/access order and raw ABI retained.
__declspec(naked) int FilterRpcBindingException(void)
{
  __asm {
    // Inherited parent-14 exception pointers -> record -> code, save-20 and EAX1.
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edx]
    mov    DWORD PTR [ebp-0x20],eax
    mov    eax,0x1
    ret
  }
}

// Prints the saved exception code, reloads saved state/status and falls through the binding result continuation.
// R6GameService.dll @ 10036961 : complete native control/access order and raw ABI retained.
__declspec(naked) void HandleRpcBindingException(void)
{
  __asm {
    // Restore savedESP, wprintf(format,code,code) while native try state is still live until explicit lowering.
    mov    esp,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x20]
    push   eax
    push   eax
    push   offset GRpcBindingExceptionFormat
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_wprintfSlot
    add    esp,0xc
    // Lower state-1; reload receiver-24/status-1c, then native fallthrough36984. No failure status assignment.
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    esi,DWORD PTR [ebp-0x24]
    mov    edi,DWORD PTR [ebp-0x1c]
  }
}

// Allocates a zeroed four-byte process-handle slot, publishes it or null and returns the wrapper.
// R6GameService.dll @ 100369f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __fastcall AllocateProcessHandleSlot(void *wrapper)
{
  __asm {
    // Cache wrapper before allocator4. Nonnull slot is zeroed before wrapper publication, no local EH.
    push   esi
    push   0x4
    mov    esi,ecx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    add    esp,0x4
    test   eax,eax
    je     Branch7
    mov    DWORD PTR [eax],0x0
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret
  Branch7:
    xor    eax,eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    ret
  }
}

// Closes the cached slot handle when nonzero and frees the cached slot without clearing the wrapper.
// R6GameService.dll @ 10036a20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CloseAndFreeProcessHandleSlot(void *wrapper)
{
  __asm {
    // Cache allocated slot ESI; null slot preserves incoming EAX. Do not clear current wrapper field after free.
    push   esi
    mov    esi,DWORD PTR [ecx]
    test   esi,esi
    je     Branch9
    mov    eax,DWORD PTR [esi]
    test   eax,eax
    je     Branch8
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CloseHandleSlot
  Branch8:
    // Free cached slot after optional CloseHandle, even if callbacks changed slot/wrapper fields; raw free EAX survives.
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch9:
    pop    esi
    ret
  }
}
