#include "native_scalar_data.hpp"
#include "native_import_slots.hpp"

// Private names and float10 return views describe native roles; original source spellings are unknown.

// R6Engine.dll @ 100017a0 : NegateNegativeOrUnordered
// Negates negative or unordered inputs while preserving either zero sign and returning live ST0.
float10 __cdecl NegateNegativeOrUnordered(float value)
{
    bool negate = !((float10)value >= (float10)nativeFloatZero);
    float10 result = (float10)value; // Native reload follows the comparison.
    if (negate) result = -result;
    return result;
}
