#pragma once
#include <cstdint>

class FVector;
int32_t __cdecl ClampSigned(int32_t value, int32_t lower, int32_t upper);
float __cdecl MaxFloat(float first, float second);
float __cdecl FDist(const FVector &first, const FVector &second);
