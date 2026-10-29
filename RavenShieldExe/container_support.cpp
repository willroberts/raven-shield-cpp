#include "native_symbols.hpp"
// Shared native map-pair/array exception bodies and assertion literals.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"

// RavenShield.exe data @ 10916100 : g_arrayRemoveEndExpression
extern const char g_arrayRemoveEndExpression[] = "Index+Count<=ArrayNum";

// RavenShield.exe data @ 10916118 : g_arrayRemoveIndexExpression
extern const char g_arrayRemoveIndexExpression[] = "Index<=ArrayNum";

// RavenShield.exe data @ 10916128 : g_arrayRemoveNonnegativeExpression
extern const char g_arrayRemoveNonnegativeExpression[] = "Index>=0";

// RavenShield.exe data @ 10916134 : g_arrayTemplateSourcePath
extern const char g_arrayTemplateSourcePath[] = "d:\\ravenshield\\412\\core\\inc\\UnTemplate.h";

// RavenShield.exe @ 10912d60 : UnwindMapPairStringKey
// Destroy a completed key if pair value construction or destruction throws.
__declspec(naked) void UnwindMapPairStringKey()
{
  __asm {
    mov ecx, [ebp-10h]
    add ecx, 4
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 1091ab24 : g_mapPairDestructionUnwind
const NativeCppUnwindEntry g_mapPairDestructionUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindMapPairStringKey)}, // UnwindMapPairStringKey
};

// RavenShield.exe data @ 1091ab2c : g_mapPairDestructionExceptionInfo
const NativeCppFunctionInfo g_mapPairDestructionExceptionInfo = {
    0x19930520, 1, NativeAddress(g_mapPairDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912d6c : HandleMapPairDestructionException
// Dispatch shared key cleanup for reviewed map-pair construction, copying and destruction.
__declspec(naked) void HandleMapPairDestructionException()
{
  __asm {
    mov eax, offset g_mapPairDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 10912660 : UnwindArrayBase
// Release the completed FArray base after destruction or construction of a derived array fails.
__declspec(naked) void UnwindArrayBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_FArrayDestroy]
  }
}

// RavenShield.exe data @ 10919b20 : g_arrayDestructionUnwind
const NativeCppUnwindEntry g_arrayDestructionUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindArrayBase)}, // UnwindArrayBase
};

// RavenShield.exe data @ 10919b28 : g_arrayDestructionExceptionInfo
const NativeCppFunctionInfo g_arrayDestructionExceptionInfo = {
    0x19930520, 1, NativeAddress(g_arrayDestructionUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912669 : HandleArrayDestructionException
// Dispatch the shared base-array cleanup state used by the reviewed array specializations.
__declspec(naked) void HandleArrayDestructionException()
{
  __asm {
    mov eax, offset g_arrayDestructionExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe data @ 10916160 : g_configMapHashTag
extern const char16_t g_configMapHashTag[] = u"HashMapHash";

// RavenShield.exe @ 109041c0 : ConstructSharedArray
// Forward shared array default construction to FArray and return the original ECX object pointer.
__declspec(naked) void ConstructSharedArray()
{
  __asm {
    push esi
    mov esi, ecx
    call dword ptr [NativeImport_FArrayConstructEmpty]
    mov eax, esi
    pop esi
    ret
  }
}
