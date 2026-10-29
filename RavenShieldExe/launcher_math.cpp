#include "native_symbols.hpp"
// Bounded launcher math; x87 bodies retain evaluation precision, unordered comparisons and return-stack behavior.
#include "launcher_math.hpp"

// RavenShield.exe @ 10904410 : ClampSigned
// Test the lower bound first, then the upper bound; reversed limits retain this native branch order.
int32_t __cdecl ClampSigned(int32_t value, int32_t lower, int32_t upper)
{
  if (value < lower) return lower;
  if (value >= upper) return upper;
  return value;
}

// RavenShield.exe @ 10904450 : MaxFloat
// Select the second float when first < second or unordered, otherwise the first, including equal signed zeros.
__declspec(naked) float __cdecl MaxFloat(float first, float second)
{
  __asm {
    fld dword ptr [esp+4]
    fcomp dword ptr [esp+8]
    fnstsw ax
    test ah, 1
    jne secondValue
    fld dword ptr [esp+4]
    ret
  secondValue:
    fld dword ptr [esp+8]
    ret
  }
}

// RavenShield.exe @ 10908f50 : FDist
// Compute appSqrt((dz*dz + dy*dy) + dx*dx), spilling only the sum to double before the imported square root.
// FVector references address three consecutive floats; x87 retains each difference and product until that spill.
__declspec(naked) float __cdecl FDist(const FVector &first, const FVector &second)
{
  __asm {
    mov eax, [esp+8]
    mov ecx, [esp+4]
    fld dword ptr [eax]
    fsub dword ptr [ecx]
    sub esp, 8
    fld dword ptr [eax+4]
    fsub dword ptr [ecx+4]
    fld dword ptr [eax+8]
    fsub dword ptr [ecx+8]
    fld st(0)
    fmul st, st(1)
    fld st(2)
    fmul st, st(3)
    faddp st(1), st
    fld st(3)
    fmul st, st(4)
    faddp st(1), st
    fstp qword ptr [esp]
    fstp st(0)
    fstp st(0)
    fstp st(0)
    call dword ptr [NativeImport_appSqrt]
    add esp, 8
    ret
  }
} // Return ST0 without a local float store; the observed callers perform their own float narrowing.
