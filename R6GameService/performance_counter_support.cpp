#include "native_addresses.h"

// Shared native timer storage; names follow API destinations and paired low/high reads.
// R6GameService.dll data @ 10093c04 : native storage identity retained.
longlong GPerformanceCounterBaseline = 0;
// R6GameService.dll data @ 10093c0c : native storage identity retained.
longlong GPerformanceCounterFrequency = 0;
// R6GameService.dll data @ 1008e07c : native storage identity retained.
byte GPerformanceCounterNeedsBaseline = 1;

// Refreshes baseline then frequency and clears initialization only after both API calls succeed.
// R6GameService.dll @ 1002cd90 : complete native access/register/control flow and raw ABI retained.
__declspec(naked) uint __cdecl RefreshPerformanceCounterBaseline(void)
{
  __asm {
    // Query writes baseline before frequency; failure does not roll back either API-written global or clear the byte guard.
    push   R6GameServiceAddresses::GPerformanceCounterBaseline
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_QueryPerformanceCounterSlot
    test   eax,eax
    jne Branch1
    xor    al,al
    ret
  Branch1:
    push   R6GameServiceAddresses::GPerformanceCounterFrequency
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_QueryPerformanceFrequencySlot
    test   eax,eax
    jne Branch2
    xor    al,al
    ret
  Branch2:
    // Retain frequency API upper EAX while replacing AL with one; neither API success is normalized before testing.
    mov    BYTE PTR ds:R6GameServiceAddresses::GPerformanceCounterNeedsBaseline,0x0
    mov    al,0x1
    ret
  }
}

// Returns low32 signed elapsed milliseconds, retaining unchecked sampling, wrapped arithmetic and final refresh.
// R6GameService.dll @ 1002cdc0 : complete native access/register/control flow and raw ABI retained.
__declspec(naked) uint __cdecl GetElapsedMilliseconds(void)
{
  __asm {
    // Optional initialization is driven by the byte guard; its refresh status is ignored.
    mov    al,ds:R6GameServiceAddresses::GPerformanceCounterNeedsBaseline
    sub    esp,0x10
    test   al,al
    je Branch3
    call   R6GameServiceAddresses::RefreshPerformanceCounterBaseline
  Branch3:
    // Sample into entry-0x10 without initializing its bytes or checking API status.
    lea    eax,[esp+0x0]
    push   esi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_QueryPerformanceCounterSlot
    // Load current global baseline after sampling; subtract low/high with borrow modulo64.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GPerformanceCounterBaseline
    mov    eax,ds:R6GameServiceAddresses::GPerformanceCounterBaseline+0x4
    mov    ecx,DWORD PTR [esp+0x4]
    push   0x0
    sub    ecx,edx
    mov    edx,DWORD PTR [esp+0xc]
    sbb    edx,eax
    push   0x3e8
    push   edx
    push   ecx
    // Multiply the wrapped difference by1000 modulo64 before loading current divisor words.
    call   R6GameServiceAddresses::Multiply64LowBits
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPerformanceCounterFrequency+0x4
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPerformanceCounterFrequency
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::SignedDivide64
    // Save quotient low in ESI; high is written to dead entry-4 scratch, then refresh clobbers volatile EDX.
    mov    esi,eax
    mov    DWORD PTR [esp+0x10],edx
    call   R6GameServiceAddresses::RefreshPerformanceCounterBaseline
    // Restore only quotient low to EAX, retaining final refresh ECX/EDX; no local exception frame or error guard is added.
    mov    eax,esi
    pop    esi
    add    esp,0x10
    ret
  }
}
