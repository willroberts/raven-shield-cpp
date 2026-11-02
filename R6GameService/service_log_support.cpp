#include "native_addresses.h"
#include "native_records.h"

// Original class ownership is unresolved; descriptive names retain the existing native bodies.

// Build timestamp/context/selected-label/message only above signed severity gate, after unconditional string allocation.
// Rotate before current file check; fprintf zero reopens, every nonzero flushes current stream; console uses current BYTE.
// Preserve live scan/tag bytes, one-state first-word cleanup, RET14 and AL0/1 with cleanup upperEAX.
// R6GameService.dll @ 10062b40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteServiceLogMessage(void *owner,int severity,char *primaryLabel,char *fallbackLabel,char *contextText,char *message)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectServiceLogMessageEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x98
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0xc]
    call   R6GameServiceAddresses::InitializeEmptyByteString
    mov    eax,DWORD PTR [esp+0xac]
    mov    ecx,DWORD PTR [esi+0x118]
    cmp    eax,ecx
    mov    DWORD PTR [esp+0xa4],0x0
    jge    Branch1
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0xa4],0xffffffff
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    xor    al,al
    jmp    Branch6
  Branch1:
    push   ebx
    mov    ebx,DWORD PTR [esp+0xb4]
    push   ebp
    push   edi
    cmp    BYTE PTR [ebx],0x0
    jne    Branch2
    mov    ebx,DWORD PTR [esp+0xc0]
  Branch2:
    lea    ecx,[esp+0x28]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::FormatUtcLogTimestamp
    mov    edx,eax
    or     ecx,0xffffffff
    mov    edi,edx
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x27]
    add    ecx,edx
    push   eax
    push   ecx
    push   edx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x10]
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push   edx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push   ecx
    push   R6GameServiceAddresses::WideTextSpace2
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    edi,R6GameServiceAddresses::WideTextOpenBracket
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x15]
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    push   edx
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x19],al
    add    ecx,R6GameServiceAddresses::WideTextOpenBracket
    push   ecx
    push   R6GameServiceAddresses::WideTextOpenBracket
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    ebp,DWORD PTR [esp+0xc4]
    or     ecx,0xffffffff
    mov    edi,ebp
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    lea    edx,[esp+0x16]
    not    ecx
    dec    ecx
    push   edx
    add    ecx,ebp
    mov    BYTE PTR [esp+0x1a],al
    push   ecx
    push   ebp
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    edi,R6GameServiceAddresses::TextPunctuation8
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x13]
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    push   edx
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x17],al
    add    ecx,R6GameServiceAddresses::TextPunctuation8
    push   ecx
    push   R6GameServiceAddresses::TextPunctuation8
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    edi,ebx
    or     ecx,0xffffffff
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    lea    edx,[esp+0x14]
    not    ecx
    dec    ecx
    push   edx
    add    ecx,ebx
    mov    BYTE PTR [esp+0x18],al
    push   ecx
    push   ebx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    edi,R6GameServiceAddresses::TextPunctuation8
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x17]
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    push   edx
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x1b],al
    add    ecx,R6GameServiceAddresses::TextPunctuation8
    push   ecx
    push   R6GameServiceAddresses::TextPunctuation8
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    edx,DWORD PTR [esp+0xc8]
    or     ecx,0xffffffff
    mov    edi,edx
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    mov    al,BYTE PTR [esp+0x10]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x11],al
    lea    eax,[esp+0x11]
    add    ecx,edx
    push   eax
    push   ecx
    push   edx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    or     ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x10]
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x12]
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push   eax
    push   ecx
    push   R6GameServiceAddresses::TextCloseBracketLine
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x1e],dl
    call   R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    ecx,esi
    call   R6GameServiceAddresses::RotateExpiredLogFile
    mov    eax,DWORD PTR [esi+0x120]
    pop    edi
    pop    ebp
    pop    ebx
    test   eax,eax
    je    Branch4
    mov    ecx,DWORD PTR [esp+0xc]
    push   ecx
    push   R6GameServiceAddresses::TextTextFormat
    push   eax
    call   R6GameServiceAddresses::fprintf
    add    esp,0xc
    test   eax,eax
    jne    Branch3
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::ReopenConfiguredLogFile
    jmp    Branch4
  Branch3:
    mov    edx,DWORD PTR [esi+0x120]
    push   edx
    call   R6GameServiceAddresses::fflush
    add    esp,0x4
  Branch4:
    mov    al,BYTE PTR [esi+0x124]
    test   al,al
    je    Branch5
    mov    eax,DWORD PTR [esp+0xc]
    push   eax
    push   R6GameServiceAddresses::TextTextFormat
    call   R6GameServiceAddresses::printf
    add    esp,0x8
  Branch5:
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0xa4],0xffffffff
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    al,0x1
  Branch6:
    mov    ecx,DWORD PTR [esp+0x9c]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xa4
    ret    0x14
  }
}

// Format current UTC tm fields through unbounded sprintf; add1900/year and1/month, return captured output, RET4.
// R6GameService.dll @ 10062de0 : complete native control/access order and raw ABI retained.
__declspec(naked) char * __thiscall FormatUtcLogTimestamp(void *owner,char *outputBuffer)
{
  __asm {
    push   ecx
    push   esi
    push   0x0
    call   R6GameServiceAddresses::time
    mov    DWORD PTR [esp+0x8],eax
    lea    eax,[esp+0x8]
    push   eax
    call   R6GameServiceAddresses::gmtime
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [eax+0x4]
    push   ecx
    mov    ecx,DWORD PTR [eax+0x8]
    push   edx
    mov    edx,DWORD PTR [eax+0x14]
    mov    esi,DWORD PTR [esp+0x1c]
    push   ecx
    mov    ecx,DWORD PTR [eax+0x10]
    add    edx,0x76c
    push   edx
    mov    edx,DWORD PTR [eax+0xc]
    inc    ecx
    push   ecx
    push   edx
    push   R6GameServiceAddresses::Text2d2d2d2d2d2d
    push   esi
    call   R6GameServiceAddresses::sprintf
    add    esp,0x28
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Close captured stream then clear current slot, compare current path with sentinel, open only differing path and modeBYTE0/1.
// R6GameService.dll @ 10062e30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ReopenConfiguredLogFile(void *owner,char mode)
{
  __asm {
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x120]
    test   eax,eax
    je    Branch7
    push   eax
    call   R6GameServiceAddresses::fclose
    add    esp,0x4
    mov    DWORD PTR [edi+0x120],0x0
  Branch7:
    lea    ebp,[edi+0x4]
    mov    esi,R6GameServiceAddresses::GRegistrationEmptyText
    mov    eax,ebp
    push   ebx
  Branch8:
    mov    dl,BYTE PTR [eax]
    mov    bl,BYTE PTR [esi]
    mov    cl,dl
    cmp    dl,bl
    jne    Branch10
    test   cl,cl
    je    Branch9
    mov    dl,BYTE PTR [eax+0x1]
    mov    bl,BYTE PTR [esi+0x1]
    mov    cl,dl
    cmp    dl,bl
    jne    Branch10
    add    eax,0x2
    add    esi,0x2
    test   cl,cl
    jne    Branch8
  Branch9:
    xor    eax,eax
    jmp    Branch11
  Branch10:
    sbb    eax,eax
    sbb    eax,0xffffffff
  Branch11:
    test   eax,eax
    pop    ebx
    je    Branch14
    mov    eax,DWORD PTR [esp+0x10]
    and    eax,0xff
    sub    eax,0x0
    je    Branch12
    dec    eax
    jne    Branch14
    push   R6GameServiceAddresses::WideTextW
    jmp    Branch13
  Branch12:
    push   R6GameServiceAddresses::WideTextA3
  Branch13:
    push   ebp
    call   R6GameServiceAddresses::fopen
    add    esp,0x8
    mov    DWORD PTR [edi+0x120],eax
  Branch14:
    pop    edi
    pop    esi
    pop    ebp
    ret    0x4
  }
}

// If unsigned current time exceeds deadline, rotate5 backups with exact stack scratch, reopen and add12h modulo32.
// Preserve unchecked formatting, CURRENT stream/path reads, ignored CRT results and partial effects on interruption.
// R6GameService.dll @ 10062ed0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall RotateExpiredLogFile(void *owner)
{
  __asm {
    sub    esp,0x300
    push   ebp
    push   0x0
    mov    ebp,ecx
    call   R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [ebp+0x104]
    add    esp,0x4
    cmp    eax,ecx
    jbe    Branch25
    push   esi
    push   edi
    lea    edi,[ebp+0x4]
    mov    esi,R6GameServiceAddresses::GRegistrationEmptyText
    mov    eax,edi
  Branch15:
    mov    dl,BYTE PTR [eax]
    mov    cl,dl
    cmp    dl,BYTE PTR [esi]
    jne    Branch17
    test   cl,cl
    je    Branch16
    mov    dl,BYTE PTR [eax+0x1]
    mov    cl,dl
    cmp    dl,BYTE PTR [esi+0x1]
    jne    Branch17
    add    eax,0x2
    add    esi,0x2
    test   cl,cl
    jne    Branch15
  Branch16:
    xor    eax,eax
    jmp    Branch18
  Branch17:
    sbb    eax,eax
    sbb    eax,0xffffffff
  Branch18:
    test   eax,eax
    je    Branch24
    mov    eax,DWORD PTR [ebp+0x120]
    test   eax,eax
    je    Branch19
    push   eax
    call   R6GameServiceAddresses::fclose
    add    esp,0x4
    mov    DWORD PTR [ebp+0x120],0x0
  Branch19:
    push   0x5
    push   edi
    lea    eax,[esp+0x114]
    push   R6GameServiceAddresses::TextSI2
    push   eax
    call   R6GameServiceAddresses::sprintf
    lea    ecx,[esp+0x11c]
    push   ecx
    call   R6GameServiceAddresses::remove
    add    esp,0x14
    mov    esi,0x4
  Branch20:
    lea    edx,[esi+0x1]
    lea    eax,[esp+0x20c]
    push   edx
    push   edi
    push   R6GameServiceAddresses::TextSI2
    push   eax
    call   R6GameServiceAddresses::sprintf
    add    esp,0x10
    test   esi,esi
    jne    Branch22
    mov    eax,DWORD PTR [ebp+0x120]
    test   eax,eax
    je    Branch21
    push   eax
    call   R6GameServiceAddresses::fclose
    add    esp,0x4
  Branch21:
    push   0x100
    lea    ecx,[esp+0x10]
    push   edi
    push   ecx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esp+0x117]
    add    esp,0xc
    test   al,al
    je    Branch23
    mov    BYTE PTR [esp+0x10b],0x0
    jmp    Branch23
  Branch22:
    push   esi
    push   edi
    lea    edx,[esp+0x14]
    push   R6GameServiceAddresses::TextSI2
    push   edx
    call   R6GameServiceAddresses::sprintf
    add    esp,0x10
  Branch23:
    lea    eax,[esp+0x20c]
    lea    ecx,[esp+0xc]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::rename
    add    esp,0x8
    dec    esi
    jns    Branch20
  Branch24:
    push   0x0
    mov    ecx,ebp
    call   R6GameServiceAddresses::ReopenConfiguredLogFile
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    add    eax,0xa8c0
    mov    DWORD PTR [ebp+0x104],eax
    pop    edi
    pop    esi
  Branch25:
    pop    ebp
    add    esp,0x300
    ret
  }
}

// Release CURRENT first buffer word at inherited EBP-9c; leave published triplet unchanged.
// R6GameService.dll @ 1006a090 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl WriteServiceLogMessageUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x9c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select service-log message one-state FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 1006a09b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectServiceLogMessageEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::WriteServiceLogMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal service-log message cleanup map and FuncInfo.
// R6GameService.dll data @ 10084bac : native storage identity retained.
const R6GameServiceNative::UnwindEntry WriteServiceLogMessageUnwindMap[1] = {
  {-1, R6GameServiceAddresses::WriteServiceLogMessageUnwind1},
};
// R6GameService.dll data @ 10084bb4 : native storage identity retained.
const R6GameServiceNative::FuncInfo WriteServiceLogMessageExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::WriteServiceLogMessageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
