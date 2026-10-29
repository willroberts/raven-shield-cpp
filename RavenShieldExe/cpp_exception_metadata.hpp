#pragma once
#include <cstdint>

// Source-only x86 C++ EH records: descriptive fields retain native states, displacements and absolute address words.
struct NativeCppUnwindEntry
{
  int32_t previousState;
  uint32_t actionWord;
};
struct NativeCppCatchHandler
{
  uint32_t adjectives, typeDescriptorWord;
  int32_t catchObjectOffset; // Signed displacement in the parent frame; zero for catch-all entries here.
  uint32_t handlerWord;
};
struct NativeCppTryBlock
{
  int32_t lowState, highState, catchHighState;
  uint32_t handlerCount, handlerArrayWord;
};
// The observed seven-word root view keeps its terminal zeros opaque rather than claiming original field meanings.
struct NativeCppFunctionInfo
{
  uint32_t magicWord;
  int32_t unwindStateCount;
  uint32_t unwindMapWord, tryBlockCount, tryBlockMapWord;
  uint32_t opaqueWord14, opaqueWord18; // +0x14/+0x18 are zero throughout this build; meanings are not asserted.
};
