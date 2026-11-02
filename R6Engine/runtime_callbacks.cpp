#include "native_exception_records.hpp"

// External native storage views; names describe roles rather than recovered original identifiers.
// Native one-entry SEH3 scope tables; these data do not add exception operations.
// Address-only private labels retain their canonical body and inherited register/stack contracts.
// These labels are never invoked with ordinary C++ call syntax and add no implementations.
// R6Engine.dll code alias @ 10042c1b : within canonical body 10042c1b
__declspec(naked) void RtcInitializeExceptionFilterNativeEntry(void);
// R6Engine.dll code alias @ 10042c1f : within canonical body 10042c1f
__declspec(naked) void RtcInitializeExceptionHandlerNativeEntry(void);
// R6Engine.dll code alias @ 10042c5f : within canonical body 10042c5f
__declspec(naked) void RtcTerminateExceptionFilterNativeEntry(void);
// R6Engine.dll code alias @ 10042c63 : within canonical body 10042c63
__declspec(naked) void RtcTerminateExceptionHandlerNativeEntry(void);

// R6Engine.dll data @ 10056148 : rtcInitializationSehScope
const NativeSehScope rtcInitializationSehScope[1] = {
    { -1, ((uint)&RtcInitializeExceptionFilterNativeEntry), ((uint)&RtcInitializeExceptionHandlerNativeEntry) }
};

// R6Engine.dll data @ 10056158 : rtcTerminationSehScope
const NativeSehScope rtcTerminationSehScope[1] = {
    { -1, ((uint)&RtcTerminateExceptionFilterNativeEntry), ((uint)&RtcTerminateExceptionHandlerNativeEntry) }
};

// R6Engine.dll data @ 10056768 : rtcInitializeCallbackBoundary
// Empty selected RTC initialization callback range boundary.
extern const uint rtcInitializeCallbackBoundary;

// R6Engine.dll data @ 10056770 : rtcTerminateCallbackBoundary
// Empty selected RTC termination callback range boundary.
extern const uint rtcTerminateCallbackBoundary;

// R6Engine.dll @ 10042bee : __RTC_Initialize
// Visits the selected empty RTC callback range while preserving its native SEH frame and embedded handlers.
__declspec(naked) void __cdecl __RTC_Initialize(void)
{
    __asm {
        push 0xc
        push offset rtcInitializationSehScope
        call __SEH_prolog
        mov dword ptr [ebp-0x1c],offset rtcInitializeCallbackBoundary
    check_callback:
        // Begin equals end in this selected image, so the loop is normally skipped.
        cmp dword ptr [ebp-0x1c],offset rtcInitializeCallbackBoundary
        jae callbacks_complete
        and dword ptr [ebp-4],0
        mov eax,dword ptr [ebp-0x1c]
        mov eax,dword ptr [eax]
        test eax,eax
        je advance_callback
        call eax
        jmp advance_callback
// R6Engine.dll @ 10042c1b : __RTC_Initialize exception filter
// Embedded inherited-frame filter selects execution of the handler for every exception.
    callback_exception_filter:
        xor eax,eax
        inc eax
        ret
// R6Engine.dll @ 10042c1f : __RTC_Initialize exception handler
// Embedded handler restores the stack and falls into the callback cursor's normal advance path.
    callback_exception_handler:
        mov esp,dword ptr [ebp-0x18]
    advance_callback:
        or dword ptr [ebp-4],0xffffffff
        add dword ptr [ebp-0x1c],4
        jmp check_callback
    callbacks_complete:
        call __SEH_epilog
        ret
    }
}

// R6Engine.dll @ 10042c32 : RunCrtTerminationCallbacks
// Visits the selected empty RTC callback range while preserving its native SEH frame and embedded handlers.
__declspec(naked) void __cdecl RunCrtTerminationCallbacks(void)
{
    __asm {
        push 0xc
        push offset rtcTerminationSehScope
        call __SEH_prolog
        mov dword ptr [ebp-0x1c],offset rtcTerminateCallbackBoundary
    check_callback:
        // Begin equals end in this selected image, so the loop is normally skipped.
        cmp dword ptr [ebp-0x1c],offset rtcTerminateCallbackBoundary
        jae callbacks_complete
        and dword ptr [ebp-4],0
        mov eax,dword ptr [ebp-0x1c]
        mov eax,dword ptr [eax]
        test eax,eax
        je advance_callback
        call eax
        jmp advance_callback
// R6Engine.dll @ 10042c5f : RunCrtTerminationCallbacks exception filter
// Embedded inherited-frame filter selects execution of the handler for every exception.
    callback_exception_filter:
        xor eax,eax
        inc eax
        ret
// R6Engine.dll @ 10042c63 : RunCrtTerminationCallbacks exception handler
// Embedded handler restores the stack and falls into the callback cursor's normal advance path.
    callback_exception_handler:
        mov esp,dword ptr [ebp-0x18]
    advance_callback:
        or dword ptr [ebp-4],0xffffffff
        add dword ptr [ebp-0x1c],4
        jmp check_callback
    callbacks_complete:
        call __SEH_epilog
        ret
    }
}
