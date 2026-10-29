#include "native_symbols.hpp"
// Compiler-generated vector destruction preserves the shared SEH frame and live parent-slot callback protocol.
#include "vector_runtime.hpp"

// RavenShield.exe data @ 109182c0 : g_vectorUnwindScope
const uint32_t g_vectorUnwindScope[3] = {0xffffffffu, NativeAddress(NativeEntry_FilterExecutableVectorDestruction),
                                         NativeAddress(NativeEntry_ResumeExecutableVectorDestruction)};
// RavenShield.exe data @ 109182d0 : g_vectorDestructorScope
const uint32_t g_vectorDestructorScope[3] = {0xffffffffu, 0,
                                             NativeAddress(NativeEntry_FinishExecutableVectorDestruction)};

// RavenShield.exe @ 10911eab : UnwindExecutableVectorDestruction
// Destroy preceding elements using live cursor/stride/count/callback slots; terminate on cleanup C++ exceptions.
__declspec(naked) void __stdcall UnwindExecutableVectorDestruction(void *cursor, uint32_t stride, int32_t remaining,
                                                                   ExecutableElementDestructor destructor)
{
  __asm {
    push 14h
    push offset g_vectorUnwindScope
    call EstablishExecutableSehFrame
    and dword ptr [ebp-4], 0
  nextElement:
    dec dword ptr [ebp+10h] // Wrapped subtraction precedes the signed-negative gate, including INT_MIN overflow.
    js finished
    mov ecx, [ebp+8]
    sub ecx, [ebp+0ch]
    mov [ebp+8], ecx // Publish the preceding element before calling the current parent callback slot.
    call dword ptr [ebp+14h]
    jmp nextElement
  finished: // Native continuation 10911ece also receives the registered handler's tail transfer.
    or dword ptr [ebp-4], -1
    call RestoreExecutableSehFrame
    ret 10h
  }
} // The shared SEH prolog saves ESP at parent EBP-18; locals occupy 14h bytes.

// RavenShield.exe @ 10911eda : FilterExecutableVectorDestruction
// Continue searching for non-C++ faults; terminate for e06d7363 using the parent exception-pointer chain.
__declspec(naked) int32_t FilterExecutableVectorDestruction()
{
  __asm {
    mov eax, [ebp-14h]
    mov [ebp-1ch], eax
    mov eax, [ebp-1ch]
    mov eax, [eax]
    mov [ebp-20h], eax
    mov eax, [ebp-20h]
    cmp dword ptr [eax], 0e06d7363h
    je cppException
    mov dword ptr [ebp-24h], 0
    mov eax, [ebp-24h]
    ret
  cppException: // Native 10911f03..10911f08 lies after the separate resume handler; it belongs to this filter.
    call TerminateExecutableCppFailure
    int 3 // Preserve the native trap if the imported termination routine unexpectedly returns.
  }
}

// RavenShield.exe @ 10911efe : ResumeExecutableVectorDestruction
// Restore the saved parent stack and enter the array-unwind epilogue without a separate handler return frame.
__declspec(naked) void ResumeExecutableVectorDestruction()
{
  __asm {
    mov esp, [ebp-18h]
    jmp VectorUnwindEpilogue
  }
}

// RavenShield.exe @ 10911f09 : DestroyExecutableVector
// Destroy an array backward with a cached stride and a finally action for the unfinished preceding elements.
__declspec(naked) void __stdcall DestroyExecutableVector(void *array, uint32_t stride, int32_t count,
                                                         ExecutableElementDestructor destructor)
{
  __asm {
    push 0ch
    push offset g_vectorDestructorScope
    call EstablishExecutableSehFrame
    and dword ptr [ebp-1ch], 0 // Completion is initially false; it changes only after the normal loop exits.
    mov esi, [ebp+0ch]
    mov eax, esi
    imul eax, [ebp+10h]
    add [ebp+8], eax // Native 32-bit product/add wrap before the first signed count test.
    and dword ptr [ebp-4], 0
  nextElement:
    dec dword ptr [ebp+10h]
    js finished
    sub [ebp+8], esi // Cached ESI stride differs from the unwind helper's per-iteration stride reload.
    mov ecx, [ebp+8]
    call dword ptr [ebp+14h]
    jmp nextElement
  finished:
    mov dword ptr [ebp-1ch], 1
    or dword ptr [ebp-4], -1
    call FinishExecutableVectorDestruction
    call RestoreExecutableSehFrame
    ret 10h
  }
} // Neither helper declares a meaningful return value; raw callback/prolog EAX residue is not normalized.

// RavenShield.exe @ 10911f51 : FinishExecutableVectorDestruction
// Unwind the live preceding-element range only when the parent iterator has not completed normally.
__declspec(naked) void FinishExecutableVectorDestruction()
{
  __asm {
    cmp dword ptr [ebp-1ch], 0
    jne finished
    push dword ptr [ebp+14h]
    push dword ptr [ebp+10h]
    push dword ptr [ebp+0ch]
    push dword ptr [ebp+8]
    call UnwindExecutableVectorDestruction
  finished:
    ret
  }
} // Scope table uses this inherited-EBP entry during unwind; normal parent code calls the same single body.
