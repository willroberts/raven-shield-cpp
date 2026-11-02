#pragma once

// Partial MSVC PE32 exception metadata views; address fields retain raw four-byte native words.
// These records describe existing tables, not host-sized pointers or new C++ exception implementations.
struct NativeUnwindEntry
{
    int previousState; // +0
    uint cleanupAddress; // +4
};

struct NativeCatchEntry
{
    uint adjectives; // +0
    uint typeDescriptorAddress; // +4
    int caughtObjectOffset; // +8, relative to the native frame
    uint handlerAddress; // +12
};

struct NativeTryBlock
{
    int tryLow; // +0
    int tryHigh; // +4
    int catchHigh; // +8
    uint catchCount; // +12
    uint catchMapAddress; // +16
};

// Only the six source-represented words are declared; this is not a complete runtime FuncInfo layout.
struct NativeFunctionInfoPrefix
{
    uint magic; // +0
    int unwindStateCount; // +4
    uint unwindMapAddress; // +8
    uint tryBlockCount; // +12
    uint tryMapAddress; // +16
    uint word20; // +20, retained without assigning an unsupported role
};

// One native SEH3 scope entry; a zero filter address denotes its finally action.
struct NativeSehScope
{
    int enclosingLevel; // +0
    uint filterAddress; // +4
    uint handlerAddress; // +8
};
