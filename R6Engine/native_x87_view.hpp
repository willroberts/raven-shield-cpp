#pragma once

// Documentary machine intrinsics for noncompiled reference code, not new native functions or an x87 object layout.
// The receiver denotes the live eight-entry x87 stack, control/status/tag words and pending exceptions.
// Each operation has exactly the indicated instruction's rounding, stack and masked/unmasked exception behavior.
// No instruction changes the control word. Memory operands remain observable at the passed address.
namespace R6EngineNative {
struct X87Machine {
    // Duplicate ST0, including the native stack-overflow behavior.
    [[r6abi::instruction("fld st(0)")]] void DuplicateTop();
    // Round ST0 to binary32 at the destination, leaving ST0 in place.
    [[r6abi::instruction("fst m32real")]] void StoreFloat32(unsigned int *destination);
    // Round ST0 under the current RC to signed64 (masked invalid writes 8000000000000000), then pop.
    [[r6abi::instruction("fistp m64int")]] void StoreInteger64AndPop(unsigned long long *destination);
    // Load the signed interpretation of the full64 memory word exactly onto the stack.
    [[r6abi::instruction("fild m64int")]] void PushInteger64(const unsigned long long *source);
    // Replace ST1 with ST1-ST0 under current PC/RC and pop ST0.
    [[r6abi::instruction("fsubp st(1),st")]] void SubtractAndPop();
    // Round ST0 to binary32 at the destination and pop ST0.
    [[r6abi::instruction("fstp m32real")]] void StoreFloat32AndPop(unsigned int *destination);
};
}
