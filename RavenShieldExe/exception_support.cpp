#include "native_symbols.hpp"
// Shared original executable exception support; absolute operands identify native metadata/import slots.
#include <cstdint>

// RavenShield.exe @ 10911c68 : ThrowExecutableCppException
// Tail-forward an exception object/type descriptor to MSVCR71; two null arguments rethrow the active exception.
extern "C" __declspec(naked) void __stdcall ThrowExecutableCppException(void *object, const void *throwInfo)
{
  __asm jmp dword ptr [NativeImport_CxxThrowException]
}

// RavenShield.exe @ 10911bd2 : DispatchExecutableCppException
// Forward to MSVCR71's __CxxFrameHandler without changing EAX (FuncInfo), the stack or the return address.
extern "C" __declspec(naked) void DispatchExecutableCppException()
{
  __asm jmp dword ptr [NativeImport_CxxFrameHandler]
}

extern "C" void DispatchExecutableSehException();

// RavenShield.exe @ 10912028 : EstablishExecutableSehFrame
// Consume the caller's scope-table/size words, save registers and link an exception frame into FS:[0].
extern "C" __declspec(naked) void EstablishExecutableSehFrame()
{
  __asm {
    push offset DispatchExecutableSehException
    mov eax, fs:[0]
    push eax
    mov eax, [esp+10h] // Allocation size supplied below the helper return address and scope table.
    mov [esp+10h], ebp
    lea ebp, [esp+10h]
    sub esp, eax
    push ebx
    push esi
    push edi
    mov eax, [ebp-8] // Original helper return address, before its slot becomes the scope-table pointer.
    mov [ebp-18h], esp
    push eax
    mov eax, [ebp-4]
    mov dword ptr [ebp-4], -1 // Inactive try level until the caller enters a protected scope.
    mov [ebp-8], eax
    lea eax, [ebp-10h]
    mov fs:[0], eax
    ret
  }
}

// RavenShield.exe @ 10912063 : RestoreExecutableSehFrame
// Unlink the active SEH frame, restore callee-saved registers and EBP, then return to the helper's caller.
extern "C" __declspec(naked) void RestoreExecutableSehFrame()
{
  __asm {
    mov ecx, [ebp-10h]
    mov fs:[0], ecx
    pop ecx // Preserve this helper's return address while dismantling the parent frame.
    pop edi
    pop esi
    pop ebx
    leave
    push ecx
    ret
  }
}

// RavenShield.exe @ 10912074 : DispatchExecutableSehException
// Forward structured-exception dispatch to MSVCR71's _except_handler3 with the native arguments intact.
extern "C" __declspec(naked) void DispatchExecutableSehException()
{
  __asm jmp dword ptr [NativeImport_except_handler3]
}

// RavenShield.exe @ 1091207a : TerminateExecutableCppFailure
// Tail-forward to MSVCR71 terminate without adding a frame or changing imported termination policy.
extern "C" __declspec(naked) void __cdecl TerminateExecutableCppFailure()
{
  __asm jmp dword ptr [NativeImport_terminate]
}

// RavenShield.exe @ 10911c6e : ForwardExecutablePureCall
// Tail-forward a pure-virtual dispatch failure to MSVCR71 without altering its receiver, stack or imported result.
extern "C" __declspec(naked) int32_t __cdecl ForwardExecutablePureCall()
{
  __asm jmp dword ptr [NativeImport_purecall]
}
