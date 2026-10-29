#pragma once
#include <cstdint>

class FString;

// Native x86 map-check packet: two scalar words followed by the 12-byte owned FString at +8.
struct MAPCHECK
{
  int32_t Type;
  void *Actor; // Opaque actor pointer in this sender; the UE2 declaration corroborates the field name.
  FString Message;
  ~MAPCHECK() noexcept(false);
};
