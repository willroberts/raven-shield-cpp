#include "native_addresses.h"
#include "exception_registration.h"
#include "import_bindings.h"

// Native exception metadata uses preferred-VA DWORD snapshots; pointer cells retain PE HIGHLOW relocations.

// R6Game.dll data @ 1001b75c : native C++ unwind-state transitions
const unsigned int BuildRotationMatrixFromAnglesUnwindMap[10] = {
    0xffffffff, R6GameAddresses::BuildRotationMatrixFromAnglesUnwind, // State 0: previous state, cleanup action.
    0x0, R6GameAddresses::BuildRotationMatrixFromAnglesUnwind1, // State 1: previous state, cleanup action.
    0x1, R6GameAddresses::BuildRotationMatrixFromAnglesUnwind2, // State 2: previous state, cleanup action.
    0x2, R6GameAddresses::BuildRotationMatrixFromAnglesUnwind3, // State 3: previous state, cleanup action.
    0x3, R6GameAddresses::BuildRotationMatrixFromAnglesUnwind4, // State 4: previous state, cleanup action.
};

// R6Game.dll data @ 1001b784 : native C++ exception function descriptor
const unsigned int BuildRotationMatrixFromAnglesExceptionInfo[7] = {
    0x19930520, 0x5, R6GameAddresses::BuildRotationMatrixFromAnglesUnwindMap, // Magic, state count, unwind map.
    0x0, 0x0, // Try-block count and map.
    0x0, 0x0, // No IP map.
};

// R6Game.dll @ 1000b600 : AbsFloat
// Negates negative or unordered float inputs and preserves all other values.
float10 __cdecl AbsFloat(float value)
{
    if (!(value >= 0.0f))
        return -(float10)value;
    return (float10)value;
}

// R6Game.dll @ 1000b620 : ClampFloat
// Returns the lower bound, value, or upper bound through two ordered comparisons.
float10 __cdecl ClampFloat(float value, float lowerBound, float upperBound)
{
    if (value < lowerBound)
        return (float10)lowerBound;
    if (value < upperBound)
        return (float10)value;
    return (float10)upperBound;
}

// R6Game.dll @ 10007fe0 : intersect an infinite line with a plane
// Uses ((planePoint - lineStart) dot planeNormal) / ((lineEnd - lineStart) dot planeNormal).
FVector* __cdecl IntersectLineWithPlane(FVector* intersection, const FVector* lineStart, const FVector* lineEnd,
    const FVector* planePoint, const FVector* planeNormal)
{
    float direction[3], savedDirection[3], argumentDirectionZ;
    FVector* output;
    // Keep the native float spills, extended numerator/ratio and final Z/Y/X sums in their x87 order.
    __asm {
        mov eax,lineStart
        mov ecx,planePoint
        lea edx,direction
        lea esi,savedDirection
        fld dword ptr [ecx]
        fsub dword ptr [eax]
        fld dword ptr [ecx+0x4]
        fsub dword ptr [eax+0x4]
        fld dword ptr [ecx+0x8]
        mov ecx,lineEnd
        fsub dword ptr [eax+0x8]
        fld dword ptr [ecx]
        fsub dword ptr [eax]
        fst dword ptr [edx]
        fld dword ptr [ecx+0x4]
        fsub dword ptr [eax+0x4]
        fst dword ptr [edx+0x4]
        fld dword ptr [ecx+0x8]
        fsub dword ptr [eax+0x8]
        fst dword ptr argumentDirectionZ
        fstp dword ptr [edx+0x8]
        mov ecx,dword ptr argumentDirectionZ
        fxch st(1)
        mov dword ptr [esi+0x8],ecx
        fstp dword ptr [esi]
        mov ecx,planeNormal
        fstp dword ptr [esi+0x4]
        fmul dword ptr [ecx+0x8]
        fxch st(1)
        fmul dword ptr [ecx+0x4]
        faddp st(1),st
        fxch st(1)
        fmul dword ptr [ecx]
        faddp st(1),st
        fld dword ptr [edx+0x8]
        fmul dword ptr [ecx+0x8]
        fld dword ptr [edx+0x4]
        fmul dword ptr [ecx+0x4]
        faddp st(1),st
        fld dword ptr [edx]
        fmul dword ptr [ecx]
        faddp st(1),st
        fdivp st(1),st
        fld dword ptr [esi]
        fmul st,st(1)
        fstp dword ptr [edx]
        fld dword ptr [esi+0x4]
        fmul st,st(1)
        fstp dword ptr [edx+0x4]
        fmul dword ptr [esi+0x8]
        fadd dword ptr [eax+0x8]
        fld dword ptr [edx+0x4]
        fadd dword ptr [eax+0x4]
        fld dword ptr [edx]
        fadd dword ptr [eax]
        mov eax,intersection
        mov output,eax
        fstp dword ptr [eax]
        fstp dword ptr [eax+0x4]
        fstp dword ptr [eax+0x8]
    }
    return output;
}

// R6Game.dll @ 1000b340 : build a matrix from pitch, yaw, and roll
// Builds table-quantized axis matrices and computes identity * roll * pitch * yaw.
FMatrix* __thiscall BuildRotationMatrixFromAngles(FMatrix* destination, int pitch, int yaw, int roll)
{
    NativeCppExceptionRegistration exceptionRegistration;
    exceptionRegistration.state = -1;
    exceptionRegistration.handlerAddress = (uint)&MatrixExceptionHandler;
    exceptionRegistration.previousAddress = __readfsdword(0);
    __writefsdword(0, (uint)&exceptionRegistration);
    // Fixed unwind destinations: yaw -0x8c, pitch -0x14c, roll -0x10c, products -0xcc/-0x4c.
    alignas(4) byte yawStorage[64], pitchStorage[64], rollStorage[64];
    alignas(4) byte rolledStorage[64], pitchedStorage[64];
    // Plain packets represent outgoing words without FPlane/FMatrix argument lifetimes.
    struct PlaneOperand { uint words[4]; };
    struct MatrixOperand { uint words[16]; };
    using MatrixConstructor = FMatrix* (__thiscall *)(FMatrix*, PlaneOperand, PlaneOperand, PlaneOperand, PlaneOperand);
    using MatrixProduct = FMatrix* (__thiscall *)(const FMatrix*, FMatrix*, MatrixOperand);
    PlaneOperand planes[4];
    uint gMathSlotAddress = R6GameImports::Core_GMathSlot;
    int* unwindState = &exceptionRegistration.state;
    planes[3].words[0] = 0; planes[3].words[1] = 0; planes[3].words[2] = 0;
    planes[3].words[3] = 0x3f800000;
    planes[2].words[0] = 0; planes[2].words[1] = 0; planes[2].words[2] = 0x3f800000; planes[2].words[3] = 0;
    const byte* yawMath = *(const byte**)gMathSlotAddress;
    uint yawAngle = (uint)yaw;
    FMatrix* matrixDestination = destination;
    uint yawSinOffset = 0x8cU + ((yawAngle >> 2) & 0x3fffU) * 4U;
    uint yawCosOffset = 0x8cU + (((yawAngle + 0x4000U) >> 2) & 0x3fffU) * 4U;
    __asm {
        mov eax,yawMath
        mov ecx,yawCosOffset
        mov edx,yawSinOffset
        fld dword ptr [eax+ecx]
        fld dword ptr [eax+edx]
        fchs
        lea edi,planes
        fstp dword ptr [edi+0x10]
        mov dword ptr [edi+0x18],0
        mov dword ptr [edi+0x1c],0
        fstp dword ptr [edi+0x14]
        mov eax,gMathSlotAddress
        mov eax,dword ptr [eax]
        fld dword ptr [eax+edx]
        fld dword ptr [eax+ecx]
        fstp dword ptr [edi]
        fstp dword ptr [edi+0x4]
        mov dword ptr [edi+0x8],0
        mov dword ptr [edi+0xc],0
    }
    FMatrix* yawMatrix = (*(MatrixConstructor*)R6GameImports::Core_FMatrix_ConstructorSlot)((FMatrix*)yawStorage,
        planes[0], planes[1], planes[2], planes[3]);
    planes[3].words[0] = 0; planes[3].words[1] = 0; planes[3].words[2] = 0; planes[3].words[3] = 0x3f800000;
    uint pitchAngle = (uint)pitch;
    const byte* pitchMath = *(const byte**)gMathSlotAddress;
    uint pitchSinOffset = 0x8cU + ((pitchAngle >> 2) & 0x3fffU) * 4U;
    uint pitchCosOffset = 0x8cU + (((pitchAngle + 0x4000U) >> 2) & 0x3fffU) * 4U;
    __asm {
        mov eax,pitchMath
        mov ecx,pitchCosOffset
        mov edx,pitchSinOffset
        fld dword ptr [eax+ecx]
        mov eax,gMathSlotAddress
        mov eax,dword ptr [eax]
        fld dword ptr [eax+edx]
        fchs
        lea edi,planes
        fstp dword ptr [edi+0x20]
        mov eax,unwindState
        mov dword ptr [eax],0
        fstp dword ptr [edi+0x28]
        mov dword ptr [edi+0x24],0
        mov dword ptr [edi+0x2c],0
        mov dword ptr [edi+0x10],0
        mov dword ptr [edi+0x14],0x3f800000
        mov dword ptr [edi+0x18],0
        mov dword ptr [edi+0x1c],0
        mov eax,gMathSlotAddress
        mov eax,dword ptr [eax]
        fld dword ptr [eax+edx]
        fld dword ptr [eax+ecx]
        fstp dword ptr [edi]
        fstp dword ptr [edi+0x8]
        mov dword ptr [edi+0x4],0
        mov dword ptr [edi+0xc],0
    }
    FMatrix* pitchMatrix = (*(MatrixConstructor*)R6GameImports::Core_FMatrix_ConstructorSlot)((FMatrix*)pitchStorage,
        planes[0], planes[1], planes[2], planes[3]);
    planes[3].words[0] = 0; planes[3].words[1] = 0; planes[3].words[2] = 0; planes[3].words[3] = 0x3f800000;
    const byte* rollMath = *(const byte**)gMathSlotAddress;
    uint rollAngle = (uint)roll;
    uint rollSinOffset = 0x8cU + ((rollAngle >> 2) & 0x3fffU) * 4U;
    uint rollCosOffset = 0x8cU + (((rollAngle + 0x4000U) >> 2) & 0x3fffU) * 4U;
    __asm {
        mov eax,rollMath
        mov ecx,rollCosOffset
        mov edx,rollSinOffset
        fld dword ptr [eax+ecx]
        mov eax,gMathSlotAddress
        mov eax,dword ptr [eax]
        fld dword ptr [eax+edx]
        lea edi,planes
        fstp dword ptr [edi+0x24]
        mov dword ptr [edi+0x20],0
        mov dword ptr [edi+0x2c],0
        fstp dword ptr [edi+0x28]
        mov eax,gMathSlotAddress
        mov eax,dword ptr [eax]
        fld dword ptr [eax+edx]
        fld dword ptr [eax+ecx]
        fstp dword ptr [edi+0x14]
        mov dword ptr [edi+0x10],0
        mov dword ptr [edi+0x1c],0
        fchs
        fstp dword ptr [edi+0x18]
        mov eax,unwindState
        mov byte ptr [eax],1
        mov dword ptr [edi],0x3f800000
        mov dword ptr [edi+0x4],0
        mov dword ptr [edi+0x8],0
        mov dword ptr [edi+0xc],0
    }
    FMatrix* rollMatrix = (*(MatrixConstructor*)R6GameImports::Core_FMatrix_ConstructorSlot)((FMatrix*)rollStorage,
        planes[0], planes[1], planes[2], planes[3]);
    MatrixOperand rightOperand;
    // Preserve the three native raw string copies, including their direction-flag behavior.
    __asm {
        mov esi,rollMatrix
        lea edi,rightOperand
        mov ecx,16
        rep movsd
    }
    const FMatrix* identity = *(const FMatrix**)R6GameImports::Core_FMatrix_IdentitySlot;
    *(byte*)&exceptionRegistration.state = 2;
    FMatrix* rolled = (*(MatrixProduct*)R6GameImports::Core_FMatrix_OperatorMultiplySlot)(identity,
        (FMatrix*)rolledStorage, rightOperand);
    __asm {
        mov esi,pitchMatrix
        lea edi,rightOperand
        mov ecx,16
        rep movsd
    }
    *(byte*)&exceptionRegistration.state = 3;
    FMatrix* pitched = (*(MatrixProduct*)R6GameImports::Core_FMatrix_OperatorMultiplySlot)(rolled,
        (FMatrix*)pitchedStorage, rightOperand);
    __asm {
        mov esi,yawMatrix
        lea edi,rightOperand
        mov ecx,16
        rep movsd
    }
    *(byte*)&exceptionRegistration.state = 4;
    (*(MatrixProduct*)R6GameImports::Core_FMatrix_OperatorMultiplySlot)(pitched, matrixDestination, rightOperand);
    // Selected Core's FMatrix destructor is empty; normal return has no destructor calls.
    uint previousChain = exceptionRegistration.previousAddress;
    __writefsdword(0, previousChain);
    return matrixDestination;
}

// R6Game.dll @ 10014100 : destroy the rotation builder's yaw matrix
__declspec(naked) void BuildRotationMatrixFromAnglesUnwind(void)
{
    __asm {
        lea ecx,[ebp-0x8c]
        jmp dword ptr ds:R6GameAddresses::Core_FMatrix_DestructorSlot // FMatrix destructor.
    }
}

// R6Game.dll @ 1001410c : destroy the rotation builder's pitch matrix
__declspec(naked) void BuildRotationMatrixFromAnglesUnwind1(void)
{
    __asm {
        lea ecx,[ebp-0x14c]
        jmp dword ptr ds:R6GameAddresses::Core_FMatrix_DestructorSlot // FMatrix destructor.
    }
}

// R6Game.dll @ 10014118 : destroy the rotation builder's roll matrix
__declspec(naked) void BuildRotationMatrixFromAnglesUnwind2(void)
{
    __asm {
        lea ecx,[ebp-0x10c]
        jmp dword ptr ds:R6GameAddresses::Core_FMatrix_DestructorSlot // FMatrix destructor.
    }
}

// R6Game.dll @ 10014124 : destroy the rotation builder's identity/roll product
__declspec(naked) void BuildRotationMatrixFromAnglesUnwind3(void)
{
    __asm {
        lea ecx,[ebp-0xcc]
        jmp dword ptr ds:R6GameAddresses::Core_FMatrix_DestructorSlot // FMatrix destructor.
    }
}

// R6Game.dll @ 10014130 : destroy the rotation builder's pitch product
__declspec(naked) void BuildRotationMatrixFromAnglesUnwind4(void)
{
    __asm {
        lea ecx,[ebp-0x4c]
        jmp dword ptr ds:R6GameAddresses::Core_FMatrix_DestructorSlot // FMatrix destructor.
    }
}

// R6Game.dll @ 10014139 : dispatch the rotation builder's five cleanup states
__declspec(naked) void MatrixExceptionHandler(void)
{
    __asm { mov eax, offset BuildRotationMatrixFromAnglesExceptionInfo }
    __asm { jmp R6GameAddresses::CxxFrameHandler }
}
