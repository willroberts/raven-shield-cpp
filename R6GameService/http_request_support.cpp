#include "native_addresses.h"
#include "native_records.h"

// Shared embedded HTTP string-record lifetime support; no containing class is inferred.

// Tail-forwards the unchanged embedded string-record range to its shared destructor.
// R6GameService.dll @ 100157b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyStringRecordRange(void *range)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyStringRecordRange
  }
}

// Destroys cached 12-byte record bounds, then frees the range begin reloaded after the element loop.
// Each element lowers its state before the empty trailing-word cleanup; range slots remain dangling.
// R6GameService.dll @ 100157c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyStringRecordRange(void *range)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyStringRecordRangeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebp
    mov    ebp,ecx
    push   esi
    push   edi
    mov    DWORD PTR [esp+0x10],ebp
    mov    edi,DWORD PTR [ebp+0x4]
    mov    esi,DWORD PTR [ebp+0x0]
    cmp    esi,edi
    mov    DWORD PTR [esp+0x1c],0x0
    mov    DWORD PTR [esp+0xc],esi
    je     Branch2
  Branch1:
    mov    ecx,esi
    mov    BYTE PTR [esp+0x1c],0x1
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esi+0x8]
    mov    BYTE PTR [esp+0x1c],0x0
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esi,0xc
    cmp    esi,edi
    mov    DWORD PTR [esp+0xc],esi
    jne    Branch1
  Branch2:
    mov    ebp,DWORD PTR [ebp+0x0]
    test   ebp,ebp
    je     Branch3
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Releases a nonnull range begin through the saved range receiver at frame-0x10.
// R6GameService.dll @ 100646b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyStringRecordRangeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Passes saved current record+8 to genuine empty cleanup during element failure.
// R6GameService.dll @ 100646b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyStringRecordRangeUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the exact request or string-record lifetime metadata for the inherited frame.
// R6GameService.dll @ 100646c3 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyStringRecordRangeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyStringRecordRangeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007e910 : native request lifetime records.
const R6GameServiceNative::UnwindEntry DestroyStringRecordRangeUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyStringRecordRangeUnwind1},
  {0x0, R6GameServiceAddresses::DestroyStringRecordRangeUnwind2},
};

// R6GameService.dll data @ 1007e920 : native request lifetime records.
const R6GameServiceNative::FuncInfo DestroyStringRecordRangeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyStringRecordRangeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Maps200 to0,400/401/403/404 to7/8/9/10, and every other status to11 through the native two-stage tables.
// R6GameService.dll @ 10016ed0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MapHttpStatusToRequestError(uint status)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    add    eax,0xffffff38
    cmp    eax,0xcc
    ja     Branch4
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::GHttpStatusIndex]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::GHttpStatusTargets]
    xor    eax,eax
    ret    0x4
    mov    eax,0x7
    ret    0x4
    mov    eax,0x8
    ret    0x4
    mov    eax,0x9
    ret    0x4
    mov    eax,0xa
    ret    0x4
  Branch4:
    mov    eax,0xb
    ret    0x4
  }
}

// R6GameService.dll data @ 10016f1c : native HTTP dispatch table.
const uint GHttpStatusTargets[6] = {
  R6GameServiceAddresses::GHttpStatusTargetsCase1,R6GameServiceAddresses::GHttpStatusTargetsCase2,R6GameServiceAddresses::GHttpStatusTargetsCase3,R6GameServiceAddresses::GHttpStatusTargetsCase4,R6GameServiceAddresses::GHttpStatusTargetsCase5,R6GameServiceAddresses::http_request_supportBranch4
};

// R6GameService.dll data @ 10016f34 : native HTTP dispatch table.
const byte GHttpStatusIndex[205] = {
  0x0,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,0x5,
  0x1,0x2,0x5,0x3,0x4
};

// Parses a case-insensitive HTTP scheme into host+0, path+0x81 and numeric WORD port+0x182.
// Defaults to port80/path slash; first colon and slash are searched independently, without URL validation.
// Native ten-state string lifetimes, unbounded uppercase scratch and partial output/raw EAX remain explicit.
// R6GameService.dll @ 10016a80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ParseHttpUrlIntoRequestFields(char *url,void *output)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x444
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x460]
    push   edi
    mov    edi,esi
    or     ecx,0xffffffff
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x28],ebx
    je     Branch17
    mov    ecx,0x100
    lea    edi,[esp+0x50]
    rep    stos DWORD PTR es:[edi],eax
    add    ebx,esi
    stos   BYTE PTR es:[edi],al
    cmp    esi,ebx
    mov    edi,esi
    je     Branch6
    lea    ebp,[esp+0x50]
    sub    ebp,esi
  Branch5:
    movsx  eax,BYTE PTR [edi]
    push   eax
    call   R6GameServiceAddresses::toupper
    add    esp,0x4
    mov    BYTE PTR [edi+ebp*1],al
    inc    edi
    cmp    edi,ebx
    jne    Branch5
  Branch6:
    lea    ecx,[esp+0x27]
    mov    DWORD PTR [esp+0x45c],0x0
    push   ecx
    lea    ecx,[esp+0x48]
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    or     ebp,0xffffffff
    mov    edi,esi
    mov    ecx,ebp
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x45c],0x1
    add    ecx,esi
    push   ecx
    push   esi
    lea    ecx,[esp+0x4c]
    call   R6GameServiceAddresses::InitializeStringRange
    lea    edx,[esp+0x13]
    lea    ecx,[esp+0x38]
    push   edx
    mov    BYTE PTR [esp+0x460],0x4
    call   R6GameServiceAddresses::InitializeEmptyByteBufferTripletWithContext
    lea    edi,[esp+0x50]
    mov    ecx,ebp
    xor    eax,eax
    mov    BYTE PTR [esp+0x45c],0x5
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+ecx*1+0x50]
    lea    ecx,[esp+0x50]
    push   eax
    push   ecx
    lea    ecx,[esp+0x40]
    call   R6GameServiceAddresses::InitializeStringRange
    push   0x7
    lea    edx,[esp+0x30]
    push   0x0
    push   edx
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x468],0x7
    call   R6GameServiceAddresses::CopyByteStringRange
    push   R6GameServiceAddresses::TextHTTP
    push   eax
    mov    BYTE PTR [esp+0x464],0x8
    call   R6GameServiceAddresses::ByteStringEqualsAnsi
    add    esp,0x8
    lea    ecx,[esp+0x2c]
    test   al,al
    sete   bl
    mov    BYTE PTR [esp+0x45c],0x7
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    test   bl,bl
    je     Branch7
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x45c],0x3
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x45c],ebp
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    jmp    Branch17
  Branch7:
    mov    eax,DWORD PTR [esp+0x28]
    lea    ecx,[esp+0x14]
    add    eax,0xfffffff9
    push   eax
    push   0x7
    push   ecx
    lea    ecx,[esp+0x50]
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,ecx
    mov    BYTE PTR [esp+0x45c],0x9
    sub    eax,edx
    je     Branch8
    mov    al,BYTE PTR [esp+0x13]
    mov    BYTE PTR [esp+0x20],0x3a
    mov    BYTE PTR [esp+0x12],al
    lea    eax,[esp+0x12]
    push   eax
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::FindByteInRange
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    cmp    eax,ecx
    je     Branch8
    sub    eax,edx
    mov    ebp,eax
  Branch8:
    mov    eax,ecx
    sub    eax,edx
    je     Branch9
    mov    al,BYTE PTR [esp+0x13]
    mov    BYTE PTR [esp+0x20],0x2f
    mov    BYTE PTR [esp+0x12],al
    lea    eax,[esp+0x12]
    push   eax
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    push   ecx
    push   edx
    call   R6GameServiceAddresses::FindByteInRange
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    cmp    eax,ecx
    je     Branch9
    sub    eax,edx
    mov    esi,eax
    jmp    Branch10
  Branch9:
    or     esi,0xffffffff
  Branch10:
    test   ebp,ebp
    jge    Branch11
    mov    edi,DWORD PTR [esp+0x468]
    mov    WORD PTR [edi+0x182],0x50
    jmp    Branch12
  Branch11:
    mov    ecx,esi
    lea    edx,[ebp+0x1]
    sub    ecx,ebp
    lea    eax,[esp+0x2c]
    dec    ecx
    push   ecx
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    eax,DWORD PTR [eax]
    push   eax
    call   R6GameServiceAddresses::atoi
    mov    edi,DWORD PTR [esp+0x46c]
    add    esp,0x4
    lea    ecx,[esp+0x2c]
    mov    WORD PTR [edi+0x182],ax
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
  Branch12:
    test   esi,esi
    jge    Branch13
    sub    ecx,edx
    mov    BYTE PTR [edi+0x81],0x2f
    mov    BYTE PTR [edi+0x82],0x0
    mov    esi,ecx
    jmp    Branch14
  Branch13:
    mov    eax,DWORD PTR [esp+0x28]
    lea    ecx,[esp+0x2c]
    sub    eax,esi
    push   eax
    push   esi
    push   ecx
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    eax,DWORD PTR [eax]
    push   0xff
    lea    edx,[edi+0x81]
    push   eax
    push   edx
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
  Branch14:
    test   ebp,ebp
    jge    Branch15
    mov    ebp,esi
  Branch15:
    test   ebp,ebp
    lea    ecx,[esp+0x14]
    jle    Branch16
    push   ebp
    lea    eax,[esp+0x30]
    push   0x0
    push   eax
    call   R6GameServiceAddresses::CopyByteStringRange
    mov    eax,DWORD PTR [eax]
    push   0x80
    push   eax
    push   edi
    call   R6GameServiceAddresses::strncpy
    add    esp,0xc
    lea    ecx,[esp+0x2c]
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x45c],0x7
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x45c],0x3
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x45c],0xffffffff
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    al,0x1
    jmp    Branch18
  Branch16:
    mov    BYTE PTR [esp+0x45c],0x7
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x45c],0x3
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x45c],0xffffffff
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
  Branch17:
    xor    al,al
  Branch18:
    mov    ecx,DWORD PTR [esp+0x454]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x450
    ret    0x8
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup.
// R6GameService.dll @ 10064840 : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x439]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 1006484b : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x41c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 10064856 : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x41c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Passes the exact inherited-frame local address to genuine empty cleanup.
// R6GameService.dll @ 10064861 : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x44d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 1006486c : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x428]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 10064877 : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x428]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 10064882 : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x434]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the current temporary string through its exact inherited-frame local slot.
// R6GameService.dll @ 1006488d : complete native control/access order and raw ABI retained.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x44c]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the shared URL parser's ten-state lifetime record for the inherited frame.
// R6GameService.dll @ 10064898 : EAX1007ead8, JMP10033906.
__declspec(naked) void ParseHttpUrlIntoRequestFieldsSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ea88 : native shared URL lifetime record.
const R6GameServiceNative::UnwindEntry ParseHttpUrlIntoRequestFieldsUnwindMap[10] = {
  {-1, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind1},
  {0x0, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind2},
  {0x0, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind3},
  {-1, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind3},
  {0x3, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind5},
  {0x4, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind6},
  {0x4, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind7},
  {0x3, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind7},
  {0x7, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind9},
  {0x7, R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwind10},
};

// R6GameService.dll data @ 1007ead8 : native shared URL lifetime record.
const R6GameServiceNative::FuncInfo ParseHttpUrlIntoRequestFieldsExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::ParseHttpUrlIntoRequestFieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
