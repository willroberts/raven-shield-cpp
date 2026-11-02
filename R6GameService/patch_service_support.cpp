#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080af4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo DirectoryProbeExceptionHandlerFunctionInfo;

// Logs ABORT CALLED with an early-cached endl manipulator, then tail-forwards through the current service slot.
// R6GameService.dll @ 10004b40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl LogAndAbortUpdateService(void)
{
  __asm {
    // Stage endl before accessor/insertion callbacks; the ostream operator target and service slot load later.
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   eax
    push   R6GameServiceAddresses::TextABORTCALLED
    call   R6GameServiceAddresses::GetDirectoryLogFirstWord
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Reload service after both logging callbacks; native tail JMP preserves the outer return address.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    test   ecx,ecx
    je Branch1
    jmp    R6GameServiceAddresses::RequestAbortUpdateServiceThroughStoredReceiver
  Branch1:
    ret
  }
}

// Copies the wide directory, probes testaccess creation/deletion and returns AL status with native upper EAX retained.
// R6GameService.dll @ 10035b00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall TestDirectoryCreateDeleteAccess(void *directory)
{
  __asm {
    // ESP-based EH frame; unwind parent EBP denotes entry ESP, not the incoming caller EBP register.
    push   0xffffffff
    push   R6GameServiceAddresses::DirectoryProbeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xd0
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   esi
    mov    esi,DWORD PTR [esp+0xe4]
    push   esi
    lea    ecx,[esp+0xb8]
    mov    DWORD PTR [esp+0xd4],eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot
    // Read source length/capacity after copy callback; choose source inline data for capacity<8.
    mov    eax,DWORD PTR [esi+0x14]
    cmp    eax,0x1
    mov    DWORD PTR [esp+0xdc],0x0
    jb Branch5
    push   edi
    lea    edi,[eax-0x1]
    cmp    eax,edi
    ja Branch2
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71__String_base__XranSlot
  Branch2:
    cmp    DWORD PTR [esi+0x18],0x8
    jb Branch3
    mov    esi,DWORD PTR [esi+0x4]
    jmp Branch4
  Branch3:
    add    esi,0x4
  Branch4:
    cmp    WORD PTR [esi+edi*2],0x5c
    pop    edi
    je Branch5
    // Append backslash only for nonempty source without trailing backslash; empty source gets no separator.
    push   R6GameServiceAddresses::WideTextPunctuation7
    lea    ecx,[esp+0xb8]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot2
  Branch5:
    // Append L"testaccess", convert wide path to narrow temporary with caller-cleaned arguments.
    push   R6GameServiceAddresses::WideTextTestaccess
    lea    ecx,[esp+0xb8]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Y_basic_stringSlot2
    lea    eax,[esp+0xb4]
    push   eax
    lea    ecx,[esp+0x9c]
    push   ecx
    call   R6GameServiceAddresses::ConstructNarrowStringFromWideString
    add    esp,0x8
    // Select narrow inline storage for capacity<16; stage hidden virtual-base flag1 with open mode2/protection0x1b6.
    mov    eax,DWORD PTR [esp+0xb0]
    mov    esi,0x10
    cmp    eax,esi
    mov    eax,DWORD PTR [esp+0x9c]
    mov    BYTE PTR [esp+0xdc],0x1
    jae Branch6
    lea    eax,[esp+0x9c]
  Branch6:
    push   0x1
    push   0x1b6
    push   0x2
    push   eax
    lea    ecx,[esp+0x14]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_ofstreamSlot
    // File+0x5c is the native open gate; state2 owns full ofstream before testing it.
    mov    eax,DWORD PTR [esp+0x60]
    test   eax,eax
    mov    BYTE PTR [esp+0xdc],0x2
    jne Branch7
    // Open failure logs through wide stream, then lowers to state1 before ofstream destruction.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    push   R6GameServiceAddresses::TextOpenFailed
    lea    eax,[esp+0xbc]
    push   eax
    push   R6GameServiceAddresses::TextTestDirAccess
    call   R6GameServiceAddresses::GetDirectoryAccessTestLogStream
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    push   eax
    call   R6GameServiceAddresses::InsertPaddedWideString
    add    esp,0x8
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    lea    ecx,[esp+0x4]
    mov    BYTE PTR [esp+0xdc],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits__D_basic_ofstreamSlot
    jmp Branch9
  Branch7:
    // These narrow ostream calls import const void* insertion: wide-literal addresses print as pointers, not text.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot2
    push   ecx
    push   R6GameServiceAddresses::WideTextThisFileIsUsedForTestingDirectoryAccess
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot2
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot2
    push   edx
    push   R6GameServiceAddresses::WideTextIfYouSeeThisFileTheDirectoryHasWriteAccessButDoesNotAllow
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot2
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_endlSlot2
    push   eax
    push   R6GameServiceAddresses::WideTextFilesToBeDeleted
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot2
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_6_basic_ostreamSlot
    // Destroy/close file before unlink; recompute current narrow inline/heap storage afterward.
    lea    ecx,[esp+0x4]
    mov    BYTE PTR [esp+0xdc],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits__D_basic_ofstreamSlot
    cmp    DWORD PTR [esp+0xb0],esi
    mov    eax,DWORD PTR [esp+0x9c]
    jae Branch8
    lea    eax,[esp+0x9c]
  Branch8:
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71__unlinkSlot
    add    esp,0x4
    test   eax,eax
    je Branch10
    // Nonzero unlink result logs failure through wide stream; statuses are not normalized beyond final AL.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    push   R6GameServiceAddresses::TextUnlinkFailed
    lea    edx,[esp+0xbc]
    push   edx
    push   R6GameServiceAddresses::TextTestDirAccess
    call   R6GameServiceAddresses::GetDirectoryAccessTestLogStream
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    push   eax
    call   R6GameServiceAddresses::InsertPaddedWideString
    add    esp,0x8
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
  Branch9:
    // Failure cleanup lowers state1->0 before narrow destruction, then to-1 before wide destruction; only AL clears.
    lea    ecx,[esp+0x98]
    mov    BYTE PTR [esp+0xdc],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esp+0xb4]
    mov    DWORD PTR [esp+0xdc],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    xor    al,al
    jmp Branch11
  Branch10:
    // Success performs the same staged cleanup and sets only AL=1 after final wide destructor.
    lea    ecx,[esp+0x98]
    mov    BYTE PTR [esp+0xdc],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esp+0xb4]
    mov    DWORD PTR [esp+0xdc],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    mov    al,0x1
  Branch11:
    // Restore FS, load saved security cookie and check it; preserve native raw upper EAX and stdcall RET4.
    mov    ecx,DWORD PTR [esp+0xd4]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [esp+0xd0]
    pop    esi
    call   R6GameServiceAddresses::__security_check_cookie
    add    esp,0xdc
    ret    0x4
  }
}

// Tail-destroys the probe wide path at inherited parent EBP-0x2c.
// R6GameService.dll @ 10066600 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDirectoryProbeWidePath(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-destroys the converted narrow path at inherited parent EBP-0x48.
// R6GameService.dll @ 10066609 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDirectoryProbeAnsiPath(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-destroys the probe ofstream including virtual bases at inherited parent EBP-0xdc.
// R6GameService.dll @ 10066612 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyDirectoryProbeFileStream(void)
{
  __asm {
    lea    ecx,[ebp-0xdc]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits__D_basic_ofstreamSlot
  }
}

// Selects native directory-probe metadata for its three staged string/file lifetimes.
// R6GameService.dll @ 1006661e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DirectoryProbeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DirectoryProbeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
