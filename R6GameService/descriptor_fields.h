#pragma once
#include "native_records.h"

// Narrow descriptor payload views, not declarations of complete classes or their unresolved prefixes.
// Every address field remains a PE32 word; reading a field does not cache it across callbacks.
namespace R6GameServiceNative {
// Three-word byte-buffer header, stored at clDataBin +0x0c; subtraction retains modulo-32 arithmetic.
struct ByteRange {
  Address begin;
  Address end;
  Address capacityEnd;
};
// clDataStr/clDataStrRef +0x0c: only the payload address used here, with no ownership claim for the reference.
struct StringPayload {
  Address text;
};
} // namespace R6GameServiceNative
