#include "native_import_slots.hpp"

// R6Engine.dll @ 100096c0 : FString::~FString import thunk
// Tail-enters imported FString destruction with the unchanged ECX receiver and caller return frame.
__declspec(naked) FString::~FString()
{
    __asm {
        jmp dword ptr [FStringDestructorImport]
    }
}
