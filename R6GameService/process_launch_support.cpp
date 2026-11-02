#include "native_addresses.h"
#include "native_records.h"

// Update-host and process-launch views; original receiver/process-wrapper class identities remain unresolved.
// For the aligned process frame, A is the aligned ESP before lifetime pushes and B=A-360 after saved registers.
// R6GameService.dll data @ 100774c8 : native storage identity retained.
const wchar_t GUpdateNil[] = L"<nil>";
// R6GameService.dll data @ 100774c0 : native storage identity retained.
const wchar_t GUpdateCommandSuffix[] = L").";
// R6GameService.dll data @ 1007749c : native storage identity retained.
const wchar_t GUpdateCommandLabel[] = L" (command line: ";
// R6GameService.dll data @ 10077450 : native storage identity retained.
const wchar_t GUpdateProcessFailure[] = L"Could not start upgrade host process ";
// R6GameService.dll data @ 10077418 : native storage identity retained.
const wchar_t GUpdateSyncEventName[] = L"ubiUpdateServiceSyncEvent";
// R6GameService.dll data @ 10077368 : native storage identity retained.
const wchar_t GUpdateSyncTimeout[] = L"Timed out waiting for upgrade host synchronization event. RPC connection will not work.";
// R6GameService.dll data @ 10077344 : native storage identity retained.
const wchar_t GUpdateRpcEndpoint[] = L"ubiUpdateService";
// R6GameService.dll data @ 100772c8 : native storage identity retained.
const wchar_t GUpdateBindingFailure[] = L"Failed to connect to upgrade host's RPC server. RPC error 0x";
// R6GameService.dll data @ 10077278 : native storage identity retained.
const wchar_t GUpdateStartSuccess[] = L"Successfully started update service!";
// R6GameService.dll data @ 1007788c : native storage identity retained.
const wchar_t GProcessNoCommand[] = L"<none>";
// R6GameService.dll data @ 1007785c : native storage identity retained.
const wchar_t GProcessErrorCodeLabel[] = L"). Win32 error code: 0x";
// R6GameService.dll data @ 10077844 : native storage identity retained.
const wchar_t GProcessCommandLabel[] = L"(cmdLine: ";
// R6GameService.dll data @ 10077814 : native storage identity retained.
const wchar_t GProcessFailure[] = L"Error starting process ";
// R6GameService.dll data @ 100778a8 : native storage identity retained.
const char GProcessBeforeAnsi[] = "PROCESS! 1";
// R6GameService.dll data @ 1007789c : native storage identity retained.
const char GProcessAfterAnsi[] = "PROCESS! 2";
// R6GameService.dll data @ 100945c4 : native storage identity retained.
RPC_BINDING_HANDLE GUpdateServiceRpcHandle = 0;
// R6GameService.dll data @ 10080c78 : native storage identity retained.
const R6GameServiceNative::UnwindEntry process_launch_supportSharedLifetimeUnwindMap[6] = {
  {-1, R6GameServiceAddresses::UnwindProcessApplication},
  {0, R6GameServiceAddresses::UnwindProcessCommand},
  {1, R6GameServiceAddresses::UnwindProcessDirectory},
  {2, R6GameServiceAddresses::UnwindProcessExplicitDirectoryTemp},
  {2, R6GameServiceAddresses::UnwindProcessCurrentDirectoryWideTemp},
  {4, R6GameServiceAddresses::UnwindProcessCurrentDirectoryAnsiTemp},
};
// R6GameService.dll data @ 10080ca8 : native storage identity retained.
const R6GameServiceNative::FuncInfo process_launch_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  6,
  R6GameServiceAddresses::process_launch_supportSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Starts the update host, records and waits on its event, then attempts binding unless the wait timed out.
// R6GameService.dll @ 10035970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StartUpdateServiceProcessAndConnectRpc(void *receiver,const unsigned short *applicationName,unsigned short *commandLine,const unsigned short *currentDirectory)
{
  __asm {
    // Cache original applicationEBX/commandEDI and receiverESI; only AL from child creation decides success.
    push   ebp
    mov    ebp,esp
    mov    eax,DWORD PTR [ebp+0x10]
    push   ebx
    mov    ebx,DWORD PTR [ebp+0x8]
    push   esi
    push   edi
    mov    edi,DWORD PTR [ebp+0xc]
    push   eax
    mov    esi,ecx
    push   edi
    push   ebx
    lea    ecx,[esi+0x20]
    call   R6GameServiceAddresses::CreateProcessFromHandleSlot
    test   al,al
    jne    Branch3
    // Failure logs original cached pointers, substituting <nil> only for NULL; context/event fields remain unchanged.
    test   edi,edi
    jne    Branch1
    mov    edi,offset GUpdateNil
  Branch1:
    test   ebx,ebx
    mov    eax,ebx
    jne    Branch2
    mov    eax,offset GUpdateNil
  Branch2:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    push   offset GUpdateCommandSuffix
    push   edi
    push   offset GUpdateCommandLabel
    push   eax
    push   offset GUpdateProcessFailure
    call   R6GameServiceAddresses::GetServiceLogStream
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   edi
    add    esp,0x8
    push   eax
    call   edi
    add    esp,0x8
    push   eax
    call   edi
    add    esp,0x8
    push   eax
    call   edi
    add    esp,0x8
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // After logging set raw receiver1c=2, clear AL only; upper24bits remain finalstream EAX.
    pop    edi
    mov    DWORD PTR [esi+0x1c],0x2
    pop    esi
    xor    al,al
    pop    ebx
    pop    ebp
    ret    0xc
  Branch3:
    // CreateEventW(null,manualReset1,initial0,name), overwrite receiver38 without closing prior event, no NULL guard.
    push   offset GUpdateSyncEventName
    push   0x0
    push   0x1
    push   0x0
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CreateEventWSlot
    // Publish event38 and wait2500ms on returned handle; ONLY WAIT_TIMEOUT102 prevents binding.
    push   0x9c4
    push   eax
    mov    DWORD PTR [esi+0x38],eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_WaitForSingleObjectSlot
    cmp    eax,0x102
    // Cache wide insertion after wait, BEFORE timeout/binding callbacks, unlike failure-path cache after getter.
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    jne    Branch4
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    push   offset GUpdateSyncTimeout
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    mov    BYTE PTR [esi+0x2c],0x0
    jmp    Branch6
  Branch4:
    // All non-timeout results, including WAIT_FAILED, bind state24 through global handle-slot address945c4.
    push   offset GUpdateRpcEndpoint
    push   offset GUpdateServiceRpcHandle
    lea    ecx,[esi+0x24]
    call   R6GameServiceAddresses::ComposeLocalRpcBinding
    test   eax,eax
    je     Branch5
    // Binding failure logs actual signedLONG status through hex manipulator, then clears contextBYTE2c.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    push   eax
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GUpdateBindingFailure
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot4
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    mov    BYTE PTR [esi+0x2c],0x0
    jmp    Branch6
  Branch5:
    // Binding status0 enables context, including native binding handler saved-zero outcome.
    mov    BYTE PTR [esi+0x2c],0x1
  Branch6:
    // Always log startup success/return AL1 after process creation, even timeout/binding failure. Raw1c is not reset.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    push   offset GUpdateStartSuccess
    call   R6GameServiceAddresses::GetServiceLogStream
    push   eax
    call   edi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    pop    ebp
    ret    0xc
  }
}

// Builds the process command, selects ANSI or wide creation and publishes its handle with native cleanup and diagnostics.
// R6GameService.dll @ 10036a40 : complete native control/access order and raw ABI retained.
__declspec(naked) unsigned char __thiscall CreateProcessWithHandleOutput(void *processHandleOutput,const unsigned short *applicationName,unsigned short *commandLine,const unsigned short *currentDirectory)
{
  __asm {
    // Keep EBP=entryESP-4 for arguments; A=(entryESP-4)&~7, lifetime stateA-4/FSnodeA-c, B=A-360.
    push   ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    push   0xffffffff
    push   R6GameServiceAddresses::SelectProcessLaunchLifetimeInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x348
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    mov    ebx,DWORD PTR [ebp+0xc]
    test   ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0x348],eax
    push   edi
    // Save output pointerB+c. Empty command/currentDirectory become NULL; application is not normalized.
    mov    DWORD PTR [esp+0xc],ecx
    je     Branch7
    cmp    WORD PTR [ebx],0x0
    jne    Branch7
    xor    ebx,ebx
  Branch7:
    mov    esi,DWORD PTR [ebp+0x10]
    test   esi,esi
    je     Branch8
    cmp    WORD PTR [esi],0x0
    jne    Branch8
    xor    esi,esi
  Branch8:
    test   ebx,ebx
    mov    edi,DWORD PTR [ebp+0x8]
    je     Branch9
    test   edi,edi
    je     Branch9
    // Unchecked wide destinationB+140; cookie starts524bytes later. Original array bound is unresolved.
    lea    eax,[esp+0x140]
    push   edi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_wcscpySlot
    lea    ecx,[esp+0x148]
    push   R6GameServiceAddresses::WideTextSpace
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_wcscatSlot
    lea    edx,[esp+0x150]
    push   ebx
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_wcscatSlot
    add    esp,0x18
    lea    ebx,[esp+0x140]
  Branch9:
    // Cached version flag AL chooses API. This is independent of code-page dispatch used by conversion helpers.
    call   R6GameServiceAddresses::GetCachedWindowsVersionHighBit
    test   al,al
    je     Branch17
    // ANSI path substitutes shared empty wide6db18 for NULL application/command; three owning narrow strings.
    test   edi,edi
    jne    Branch10
    mov    edi,R6GameServiceAddresses::GEmptyWideText
  Branch10:
    lea    eax,[esp+0x124]
    push   edi
    push   eax
    call   R6GameServiceAddresses::ConstructNarrowStringFromWide
    add    esp,0x8
    test   ebx,ebx
    mov    DWORD PTR [esp+0x35c],0x0
    mov    eax,ebx
    jne    Branch11
    mov    eax,R6GameServiceAddresses::GEmptyWideText
  Branch11:
    push   eax
    lea    ecx,[esp+0x10c]
    push   ecx
    call   R6GameServiceAddresses::ConstructNarrowStringFromWide
    add    esp,0x8
    // After app/command construction states0/1, construct empty directory atB+ec then state2.
    lea    ecx,[esp+0xec]
    mov    BYTE PTR [esp+0x35c],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot3
    test   esi,esi
    mov    BYTE PTR [esp+0x35c],0x2
    je     Branch12
    // Explicit directory converts temporaryB+20, state3 around assignment, lower2 before temporary destruction.
    lea    edx,[esp+0x20]
    push   esi
    push   edx
    call   R6GameServiceAddresses::ConstructNarrowStringFromWide
    add    esp,0x8
    push   eax
    lea    ecx,[esp+0xf0]
    mov    BYTE PTR [esp+0x360],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x35c],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    jmp    Branch13
  Branch12:
    // No directory: current-wide temporaryB+3c state4, converted-ANSI tempB+20 state5; lower4 then2 before dtors.
    lea    eax,[esp+0x3c]
    push   eax
    call   R6GameServiceAddresses::ConstructCurrentDirectoryWideString
    push   eax
    lea    ecx,[esp+0x28]
    push   ecx
    mov    BYTE PTR [esp+0x368],0x4
    call   R6GameServiceAddresses::ConstructNarrowStringFromWideString
    add    esp,0xc
    push   eax
    lea    ecx,[esp+0xf0]
    mov    BYTE PTR [esp+0x360],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x35c],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x35c],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  Branch13:
    // ANSI-only PROCESS! 1 diagnostic precedes initialization/creation; retain current endl/imported wcout.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_wcoutSlot
    push   edx
    push   offset GProcessBeforeAnsi
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Zero17DWORD STARTUPINFOA bytes and4DWORD PI; cb remains0. Set flags1/showWindow4 only.
    mov    edx,DWORD PTR [esp+0xf0]
    xor    eax,eax
    mov    ecx,0x11
    lea    edi,[esp+0x58]
    rep stos DWORD PTR es:[edi],eax
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0x1c],ecx
    // CRT narrow data selection: unsigned capacity>=16 uses heap pointer+4, otherwise inline+4; never NULL substitute.
    mov    ecx,DWORD PTR [esp+0x104]
    mov    eax,0x10
    cmp    ecx,eax
    mov    DWORD PTR [esp+0x84],0x1
    mov    WORD PTR [esp+0x88],0x4
    jae    Branch14
    lea    edx,[esp+0xf0]
  Branch14:
    cmp    DWORD PTR [esp+0x120],eax
    mov    ecx,DWORD PTR [esp+0x10c]
    jae    Branch15
    lea    ecx,[esp+0x10c]
  Branch15:
    cmp    DWORD PTR [esp+0x13c],eax
    mov    eax,DWORD PTR [esp+0x128]
    jae    Branch16
    lea    eax,[esp+0x128]
  Branch16:
    // CreateProcessA(app,command,null,null,FALSE,0,null,directory,startup,PI). No extra flags/environment/security.
    lea    esi,[esp+0x10]
    push   esi
    lea    esi,[esp+0x5c]
    push   esi
    push   edx
    push   0x0
    push   0x0
    push   0x0
    push   0x0
    push   0x0
    push   ecx
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CreateProcessASlot
    // Cache BOOL resultESI before PROCESS! 2 diagnostic; it and subsequent dtors can change GetLastError.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   edx
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::MSVCP71_std_wcoutSlot
    push   offset GProcessAfterAnsi
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Reload saved output pointerB+c after log; cache PIthreadEDI BEFORE publishing PIprocess, including failure.
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    edi,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edx],ecx
    // Lower1/0/-1 before directory/command/application destruction. No handle-close actions exist in map.
    lea    ecx,[esp+0xec]
    mov    BYTE PTR [esp+0x35c],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esp+0x108]
    mov    BYTE PTR [esp+0x35c],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    lea    ecx,[esp+0x124]
    mov    DWORD PTR [esp+0x35c],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    jmp    Branch18
  Branch17:
    // Wide path zeroes STARTUPINFOW/PI, also leaves cb0, flags1/show4; original application argument reloads late.
    xor    eax,eax
    mov    ecx,0x11
    lea    edi,[esp+0xa0]
    rep stos DWORD PTR es:[edi],eax
    mov    DWORD PTR [esp+0x20],eax
    lea    ecx,[esp+0x20]
    push   ecx
    lea    edx,[esp+0xa4]
    push   edx
    push   esi
    mov    DWORD PTR [esp+0x30],eax
    mov    DWORD PTR [esp+0x34],eax
    push   eax
    push   eax
    push   eax
    push   eax
    push   eax
    mov    DWORD PTR [esp+0x4c],eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   ebx
    push   eax
    mov    DWORD PTR [esp+0xf4],0x1
    mov    WORD PTR [esp+0xf8],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CreateProcessWSlot
    // Cache PIthread before publication, rawBOOL ESI. Saved output pointer reloads current B+c.
    mov    ecx,DWORD PTR [esp+0x20]
    mov    edx,DWORD PTR [esp+0xc]
    mov    edi,DWORD PTR [esp+0x24]
    mov    esi,eax
    mov    DWORD PTR [edx],ecx
  Branch18:
    // Failure resets CURRENT saved output pointer to0. Thread/process handles are not cleaned on failure.
    test   esi,esi
    jne    Branch20
    test   ebx,ebx
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [eax],esi
    jne    Branch19
    mov    ebx,offset GProcessNoCommand
  Branch19:
    // Cache endl then late GetLastError, AFTER ANSI diagnostics/dtors; original apparg reload, no NULL app substitute.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetLastErrorSlot
    mov    edx,DWORD PTR [ebp+0x8]
    push   eax
    push   R6GameServiceAddresses::ApplyHexRadixManipulator
    push   offset GProcessErrorCodeLabel
    push   ebx
    push   offset GProcessCommandLabel
    push   edx
    push   offset GProcessFailure
    // Directory log tail reads reference93d20+4. Cache wide insertion only after getter; exact chain/unsignedDWORD error.
    call   R6GameServiceAddresses::GetDirectoryAccessTestLogStream
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_G__6GU_char_traitsSlot
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    push   eax
    call   esi
    add    esp,0x8
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot3
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot5
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    xor    al,al
    jmp    Branch21
  Branch20:
    // Success CloseHandle(cached thread), ignore result; process HANDLE remains output. AL1 preserves upper CloseHandleEAX.
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CloseHandleSlot
    mov    al,0x1
  Branch21:
    // Restore saved FS B+354 before actualcookie62281 with B+34c; restore registers/original EBP frame, RETc.
    mov    ecx,DWORD PTR [esp+0x354]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [esp+0x34c]
    call   R6GameServiceAddresses::__security_check_cookie
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  }
}

// Loads the process-handle output slot and tail-forwards the original three launch arguments.
// R6GameService.dll @ 10036e20 : complete native control/access order and raw ABI retained.
__declspec(naked) unsigned char __thiscall CreateProcessFromHandleSlot(void *wrapper,const unsigned short *applicationName,unsigned short *commandLine,const unsigned short *currentDirectory)
{
  __asm {
    // One unchecked ECX=[ECX] then raw tail36a40; preserve original three stack arguments and EDX.
    mov    ecx,DWORD PTR [ecx]
    jmp    R6GameServiceAddresses::CreateProcessWithHandleOutput
  }
}

// Destroys the ANSI application string.
// R6GameService.dll @ 100666c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessApplication(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x23c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the ANSI command string.
// R6GameService.dll @ 100666cc : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessCommand(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x258]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the ANSI directory string.
// R6GameService.dll @ 100666d8 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessDirectory(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x274]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the explicit-directory conversion temporary.
// R6GameService.dll @ 100666e4 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessExplicitDirectoryTemp(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x340]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the current-directory wide temporary.
// R6GameService.dll @ 100666f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessCurrentDirectoryWideTemp(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x324]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Destroys the current-directory ANSI temporary.
// R6GameService.dll @ 100666fc : complete native control/access order and raw ABI retained.
__declspec(naked) uint UnwindProcessCurrentDirectoryAnsiTemp(void)
{
  __asm {
    // Inherited unwind EBP=A. Exact temporary/string offset, tail imported dtor; state chain from map80c78.
    lea    ecx,[ebp-0x340]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects the aligned process-launch lifetime map and transfers to the native C++ frame handler.
// R6GameService.dll @ 10066708 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectProcessLaunchLifetimeInfo(void)
{
  __asm {
    // Inherited unwind EBP=A, distinct from parent argument EBP; EAX exact FuncInfo80ca8/map80c78, no catches.
    mov    eax,offset process_launch_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
