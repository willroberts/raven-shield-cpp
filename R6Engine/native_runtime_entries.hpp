#pragma once

// Existing native runtime entry declarations; these preserve the definitions in runtime_support.cpp.
// Direct assembly transfers retain their compiler-specific register, stack and parent-frame contracts.
__declspec(naked) void __CxxFrameHandler(void);
__declspec(naked) void _CxxThrowException(void* exceptionObject, ThrowInfo* throwInfo);
__declspec(naked) void __stdcall _eh_vector_destructor_iterator_(void* elementCursor, uint elementSize,
    int remainingCount, void (__thiscall* destroyElement)(void*));
