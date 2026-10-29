#pragma once
#include <cstdint>

// Compiler-runtime callbacks receive the element in ECX with no stack arguments; shared helpers consume four words.
using ExecutableElementDestructor = void(__thiscall *)(void *element);
void __stdcall UnwindExecutableVectorDestruction(void *cursor, uint32_t stride, int32_t remaining,
                                                 ExecutableElementDestructor destructor);
void __stdcall DestroyExecutableVector(void *array, uint32_t stride, int32_t count,
                                       ExecutableElementDestructor destructor);
// Inherited-EBP action: called normally and by the iterator's registered SEH finally scope.
void FinishExecutableVectorDestruction();
// Address-only anchor for native continuation 10911ece within UnwindExecutableVectorDestruction, not another body.
extern "C" void VectorUnwindEpilogue();
extern "C" void EstablishExecutableSehFrame();
extern "C" void RestoreExecutableSehFrame();
extern "C" void __cdecl TerminateExecutableCppFailure();
