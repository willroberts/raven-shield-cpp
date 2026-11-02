#pragma once

// Partial physical records for the selected PE32/MSVC image; names describe evidenced native roles.
// Address is a four-byte preferred-image word, never a host pointer or C++ member-function pointer.
// These declarations do not change exception implementations, vtable dispatch or object lifetimes.
// Compiler bodies remain separate definitions; metadata references identify their state/handler roles.
// The machinery section of notes/R6GameService/post-processing-records.json maps every such use, shared
// selector/parent and reviewed virtual slot. Internal native labels retain their existing enclosing body.
namespace R6GameServiceNative {
using Address = unsigned int;
#pragma pack(push, 4)

// VC6 seven-word function metadata; IP fields remain present even when zero.
struct FuncInfo {
  unsigned int magic;
  int stateCount;
  Address unwindMap;
  unsigned int tryBlockCount;
  Address tryBlockMap;
  unsigned int ipMapCount;
  Address ipToStateMap;
};

// One predecessor/action pair, indexed by native construction state.
struct UnwindEntry {
  int previousState;
  Address action;
};

// Inclusive try/catch state ranges and their handler-array address.
struct TryBlock {
  int tryLow;
  int tryHigh;
  int catchHigh;
  unsigned int catchCount;
  Address handlers;
};

// One typed catch or catch-all; displacement is relative to the established native frame.
struct CatchHandler {
  unsigned int adjectives;
  Address typeDescriptor;
  int catchObjectDisplacement;
  Address handler;
};

// One CRT SEH scope entry; a zero filter identifies an unconditional termination action.
struct SehScope {
  int enclosingLevel;
  Address filter;
  Address handler;
};

// VC6 catch conversion: signed PMD displacements retain the native no-vbtable sentinel.
struct CatchableType {
  unsigned int properties;
  Address typeDescriptor;
  int memberDisplacement;
  int vbtableDisplacement;
  int virtualBaseDisplacement;
  int sizeOrOffset;
  Address copyFunction;
};

// VC6 throw descriptor; addresses retain raw compiler entry contracts.
struct ThrowInfo {
  unsigned int attributes;
  Address unwind;
  Address forwardCompatibility;
  Address catchableTypes;
};

// Counted compiler arrays have only the number of address words evidenced at each definition.
template<unsigned int Count> struct CatchableTypeArray {
  unsigned int count;
  Address types[Count];
};

// Signed offsets relative to the vbptr location; duplicate offsets describe distinct native base slots.
template<unsigned int Count> struct BaseOffsets {
  int offsetToTop;
  int baseDisplacements[Count];
};
#pragma pack(pop)
} // namespace R6GameServiceNative
