#include "native_symbols.hpp"
// Shared native wizard-page exception actions used by several page classes.
#include "cpp_exception_metadata.hpp"
#include "container_support.hpp"
#include "allocation_support.hpp"

// RavenShield.exe @ 10912500 : UnwindWizardCallbackString
// Destroy the completed callback-local FString at parent EBP-18 during exception cleanup.
__declspec(naked) void UnwindWizardCallbackString()
{
  __asm {
    lea ecx, [ebp-18h]
    jmp dword ptr [NativeImport_FStringDestroy]
  }
}

// RavenShield.exe data @ 109195e8 : g_wizardCallbackStringUnwind
const NativeCppUnwindEntry g_wizardCallbackStringUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindWizardCallbackString)}, // UnwindWizardCallbackString
};

// RavenShield.exe data @ 109195f0 : g_wizardCallbackStringExceptionInfo
const NativeCppFunctionInfo g_wizardCallbackStringExceptionInfo = {
    0x19930520, 1, NativeAddress(g_wizardCallbackStringUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 10912509 : HandleWizardCallbackStringException
// Dispatch one completed callback-local string for renderer selection and driver initialization.
__declspec(naked) void HandleWizardCallbackStringException()
{
  __asm {
    mov eax, offset g_wizardCallbackStringExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 109127d0 : UnwindWizardPageBase
// Destroy the completed WWizardPage base from the caller's saved parent EBP-10 receiver.
__declspec(naked) void UnwindWizardPageBase()
{
  __asm {
    mov ecx, [ebp-10h]
    jmp dword ptr [NativeImport_WWizardPageDestroy]
  }
}

// RavenShield.exe data @ 10919cac : g_wizardPageBaseUnwind
const NativeCppUnwindEntry g_wizardPageBaseUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindWizardPageBase)}, // UnwindWizardPageBase
};

// RavenShield.exe data @ 10919cb4 : g_wizardPageBaseExceptionInfo
const NativeCppFunctionInfo g_wizardPageBaseExceptionInfo = {0x19930520, 1, NativeAddress(g_wizardPageBaseUnwind), 0, 0,
                                                             0,          0};

// RavenShield.exe @ 109127d9 : HandleWizardPageBaseException
// Dispatch base cleanup for detail construction and first-time page destruction.
__declspec(naked) void HandleWizardPageBaseException()
{
  __asm {
    mov eax, offset g_wizardPageBaseExceptionInfo
    jmp DispatchExecutableCppException
  }
}

// RavenShield.exe @ 109128d0 : UnwindWizardPageAllocation
// Free the page allocation saved at parent EBP-14 after its constructor fails.
__declspec(naked) void UnwindWizardPageAllocation()
{
  __asm {
    mov eax, [ebp-14h]
    push eax
    call FreeExecutableAllocation
    pop ecx
    ret
  }
}

// RavenShield.exe data @ 10919d8c : g_wizardPageAllocationUnwind
const NativeCppUnwindEntry g_wizardPageAllocationUnwind[1] = {
    {-1, NativeAddress(NativeEntry_UnwindWizardPageAllocation)}, // UnwindWizardPageAllocation
};

// RavenShield.exe data @ 10919d94 : g_wizardPageAllocationExceptionInfo
const NativeCppFunctionInfo g_wizardPageAllocationExceptionInfo = {
    0x19930520, 1, NativeAddress(g_wizardPageAllocationUnwind), 0, 0, 0, 0};

// RavenShield.exe @ 109128db : HandleWizardPageAllocationException
// Dispatch the shared allocation cleanup used by safe-mode page opening and driver/detail next-page creation.
__declspec(naked) void HandleWizardPageAllocationException()
{
  __asm {
    mov eax, offset g_wizardPageAllocationExceptionInfo
    jmp DispatchExecutableCppException
  }
}
