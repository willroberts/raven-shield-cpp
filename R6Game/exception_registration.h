#pragma once

// Selected x86 C++ registration header at FS:[0]; addresses are DWORDs, not host pointer-sized fields.
// Saved EBP/ESP, local storage and funclet bindings remain specific to the enclosing native method.
struct NativeCppExceptionRegistration {
    unsigned int previousAddress; // +0x0: previous chain head.
    unsigned int handlerAddress; // +0x4: native handler code address; no C++ callable prototype is implied.
    int state; // +0x8: signed unwind/try state; -1 precedes entry to a protected scope.
};
