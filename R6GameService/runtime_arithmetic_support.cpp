#include "native_addresses.h"
#include "native_import_bindings.h"

// Divides signed64 operands toward zero, retaining normalization, correction, stack mutations and native DIV faults.
// R6GameService.dll @ 10033cd0 : complete native access/register/control flow and raw ABI retained.
__declspec(naked) longlong __stdcall SignedDivide64(uint dividendLow,uint dividendHigh,uint divisorLow,uint divisorHigh)
{
  __asm {
    // Count operand signs in EDI; convert negative dividend in its original stack words, including INT64_MIN bits.
    push   edi
    push   esi
    push   ebx
    xor    edi,edi
    mov    eax,DWORD PTR [esp+0x14]
    or     eax,eax
    jge Branch1
    inc    edi
    mov    edx,DWORD PTR [esp+0x10]
    neg    eax
    neg    edx
    sbb    eax,0x0
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x10],edx
  Branch1:
    // Normalize negative divisor in its original stack words and retain total sign count.
    mov    eax,DWORD PTR [esp+0x1c]
    or     eax,eax
    jge Branch2
    inc    edi
    mov    edx,DWORD PTR [esp+0x18]
    neg    eax
    neg    edx
    sbb    eax,0x0
    mov    DWORD PTR [esp+0x1c],eax
    mov    DWORD PTR [esp+0x18],edx
  Branch2:
    // Zero high divisor uses two unsigned32 divisions; zero divisor reaches the native DIV exception.
    or     eax,eax
    jne Branch3
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x14]
    xor    edx,edx
    div    ecx
    mov    ebx,eax
    mov    eax,DWORD PTR [esp+0x10]
    div    ecx
    mov    edx,ebx
    jmp Branch7
  Branch3:
    // Large divisor shifts paired numerator/divisor until divisor high becomes zero, retaining each carry bit.
    mov    ebx,eax
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
  Branch4:
    shr    ebx,1
    rcr    ecx,1
    shr    edx,1
    rcr    eax,1
    or     ebx,ebx
    jne Branch4
    // Estimate quotient with DIV, multiply it back, then reduce a one-too-large estimate by one.
    div    ecx
    mov    esi,eax
    mul    DWORD PTR [esp+0x1c]
    mov    ecx,eax
    mov    eax,DWORD PTR [esp+0x18]
    mul    esi
    add    edx,ecx
    jb Branch5
    cmp    edx,DWORD PTR [esp+0x14]
    ja Branch5
    jb Branch6
    cmp    eax,DWORD PTR [esp+0x10]
    jbe Branch6
  Branch5:
    dec    esi
  Branch6:
    xor    edx,edx
    mov    eax,esi
  Branch7:
    // Negate only when sign count was one; INT64_MIN divided by-1 returns its wrapped64 bits.
    dec    edi
    jne Branch8
    neg    edx
    neg    eax
    sbb    edx,0x0
  Branch8:
    pop    ebx
    pop    esi
    pop    edi
    ret    0x10
  }
}

// Returns low64 product bits using native low-word and cross-word multiplication with RET16.
// R6GameService.dll @ 10033d80 : complete native access/register/control flow and raw ABI retained.
__declspec(naked) ulonglong __stdcall Multiply64LowBits(uint leftLow,uint leftHigh,uint rightLow,uint rightHigh)
{
  __asm {
    // If both high words are zero, use one unsigned32 MUL for the full64 product.
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esp+0x10]
    or     ecx,eax
    mov    ecx,DWORD PTR [esp+0xc]
    jne Branch9
    mov    eax,DWORD PTR [esp+0x4]
    mul    ecx
    ret    0x10
  Branch9:
    // Otherwise sum the two low cross-products into the high word and retain low*low product bits.
    push   ebx
    mul    ecx
    mov    ebx,eax
    mov    eax,DWORD PTR [esp+0x8]
    mul    DWORD PTR [esp+0x14]
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x8]
    mul    ecx
    add    edx,ebx
    pop    ebx
    ret    0x10
  }
}

// Shifts EDX:EAX by CL;32..63 move high to low,64..255 clear both. Plain RET; original low word arrives in EAX.
// R6GameService.dll @ 100622b0 : native control/access order and raw ABI retained.
__declspec(naked) ulonglong __fastcall __aullshr(byte shiftCount,uint highWord)
{
  __asm {
    cmp    cl,0x40
    jae    Branch11
    cmp    cl,0x20
    jae    Branch10
    shrd   eax,edx,cl
    shr    edx,cl
    ret
  Branch10:
    mov    eax,edx
    xor    edx,edx
    and    cl,0x1f
    shr    eax,cl
    ret
  Branch11:
    xor    eax,eax
    xor    edx,edx
    ret
  }
}

namespace R6GameServiceImports {
// Bind the current conversion entry; its input remains in ST(0), with no added stack operand or wrapper frame.
// R6GameService.dll @ 100622a2 : six-byte compiler import tail; live x87 ABI entry reference.
Ftol &ftol{*reinterpret_cast<Ftol *>(R6GameServiceAddresses::MSVCR71__ftolSlot)};
}
