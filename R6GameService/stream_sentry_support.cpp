#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ade8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo StreamSentryExceptionHandlerFunctionInfo;

// Shared wide-stream sentry and mutex roles; original template/helper spellings are not recovered.

// Resolves the stored stream and tail-unlocks its current buffer mutex when a buffer is present.
// R6GameService.dll @ 10001bb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall UnlockMutexIfPresent(int *ownerStorage)
{
  __asm {
    // Owner storage contains a stream pointer; vbtable+4 resolves ios, whose+0x28 is a nullable streambuf.
    mov    eax,DWORD PTR [ecx]
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x28]
    test   eax,eax
    je     Branch1
    // Tail ABI: mutex is streambuf+4. Null path returns EAX0; no pointer or vbtable guard is added.
    lea    ecx,[eax+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71__Mutex__UnlockSlot
  Branch1:
    ret
  }
}

// Stores the stream, locks its buffer mutex, optionally flushes its tie and records current stream readiness.
// R6GameService.dll @ 10002470 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructWideStreamSentry(void *sentry,int *stream)
{
  __asm {
    // ESP-based EH: nominal inherited parent EBP is entryESP; state-1 covers the lock call.
    push   0xffffffff
    push   R6GameServiceAddresses::StreamSentryExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    push   edi
    mov    edi,ecx
    // Cache original stream in ESI and sentry in EDI; callbacks may change sentry[0] independently.
    mov    DWORD PTR [edi],esi
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [ecx+esi*1+0x28]
    // Save sentry at parentEBP-0x10 before optional lock. A throwing lock has no local unwind action.
    test   eax,eax
    mov    DWORD PTR [esp+0x8],edi
    je     Branch2
    lea    ecx,[eax+0x4]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__Mutex__LockSlot
  Branch2:
    // Reload cached stream vbtable after lock; state0 owns mutex cleanup before optional tie flush.
    mov    edx,DWORD PTR [esi]
    mov    eax,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [eax+esi*1+0x8]
    add    eax,esi
    test   ecx,ecx
    mov    DWORD PTR [esp+0x14],0x0
    jne    Branch3
    mov    eax,DWORD PTR [eax+0x2c]
    test   eax,eax
    je     Branch3
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_ostream_flushSlot
  Branch3:
    // Reload current cached-stream state after flush; store only sentry+4 byte, preserving adjacent storage.
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+esi*1+0x8]
    mov    ecx,DWORD PTR [esp+0xc]
    test   eax,eax
    sete   al
    mov    BYTE PTR [edi+0x4],al
    // Return original sentry regardless callback EAX or changes to saved owner; restore FS and saved registers.
    mov    eax,edi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Runs the wide-stream suffix unless an exception is active, then unlocks the currently resolved buffer mutex.
// R6GameService.dll @ 10002500 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyWideStreamSentry(int *sentry)
{
  __asm {
    // Same ESP-based FuncInfo as constructor; save sentry at parentEBP-0x10, enter state0.
    push   0xffffffff
    push   R6GameServiceAddresses::StreamSentryExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esp+0x10],0x0
    // Only low AL of uncaught_exception suppresses suffix; sentry readiness byte is never consulted.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_uncaught_exceptionSlot
    test   al,al
    jne    Branch4
    mov    ecx,DWORD PTR [esi]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__basic_ostream__OsfxSlot
  Branch4:
    // Reload sentry[0], vbtable and buffer after callbacks; saved original lock target is not retained.
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x28]
    test   eax,eax
    // Lower state to-1 before optional mutex unlock so a throwing unlock cannot repeat this action.
    mov    DWORD PTR [esp+0x10],0xffffffff
    pop    esi
    je     Branch5
    lea    ecx,[eax+0x4]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__Mutex__UnlockSlot
  Branch5:
    // Null-buffer EAX0 or raw unlock EAX survives; ECX restores previous FS.
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-unlocks the current stream through the sentry pointer saved in the parent frame.
// R6GameService.dll @ 10063230 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnlockSavedStreamSentry(void)
{
  __asm {
    // Load saved sentry pointer from inherited parentEBP-0x10; helper reloads its current stream/buffer.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::UnlockMutexIfPresent
  }
}

// Selects the shared constructor/destructor metadata for sentry mutex cleanup.
// R6GameService.dll @ 10063238 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl StreamSentryExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::StreamSentryExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
