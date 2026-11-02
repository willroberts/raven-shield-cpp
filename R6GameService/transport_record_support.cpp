#include "native_addresses.h"
#include "native_records.h"

// Selected transport-record/cache helpers; original containing class and field spellings remain unresolved.

// Destroy/free captured current record+4, clear slot, then pop full selector through CURRENT queue+c and publish.
// Reload selector/queue after destruction; no parent EH guard or rollback.
// R6GameService.dll @ 1004ce30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceRecordBySelector(void *owner,uint selector)
{
  __asm {
    push    esi
    push    edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x4]
    test    esi,esi
    je    Branch1
    mov    ecx,esi
    call    R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [edi+0x4],0x0
  Branch1:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [edi+0xc]
    push    eax
    call    R6GameServiceAddresses::RemoveQueuedRecordBySelector
    mov    DWORD PTR [edi+0x4],eax
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Copy live source bytes forward through NUL without padding/bounds; RET8, EAX=advanced source/CL0.
// Retain destination-source EDX and overlap propagation; return is raw uint rather than void.
// R6GameService.dll @ 1004ce70 : complete native control/access order and raw ABI retained.
uint __stdcall CopyTerminatedBytesForward(char *destination,const char *source)
{
  char character;
  do {
    character = *source;
    *destination++ = character;
    ++source;
  } while (character != 0);
  return reinterpret_cast<uint>(source);
}

// Publish current tag26/27, read one byte into delimiter ARGUMENT SLOT, compare selector lowBYTE, then reread output.
// Quoted path builds descriptor and copies four bytes; selector argument becomes CURRENT cleanup context.
// Preserve ten-state cookie/base/full/entered-clear/head cleanup and raw upperEAX/AL.
// R6GameService.dll @ 1004ce90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadTransportSelectorRecord(
    void *owner,uint selector,byte *delimiterOut,void *fourBytesOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransportRecordEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    ebx
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    push    edi
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    je    Branch6
    mov    al,BYTE PTR [eax+0x4]
    mov    edi,DWORD PTR [esp+0x40]
    cmp    al,0x26
    mov    BYTE PTR [edi],al
    je    Branch3
    cmp    al,0x27
    jne    Branch6
  Branch3:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    ebx,0x1
    push    0x0
    lea    eax,[esp+0x44]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    ebx
    push    eax
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    je    Branch6
    mov    dl,BYTE PTR [esp+0x40]
    mov    al,BYTE PTR [esp+0x3c]
    cmp    dl,al
    jne    Branch6
    cmp    BYTE PTR [edi],0x27
    jne    Branch8
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x1c]
    push    0x0
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x40],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    ebx
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x3c],0x3
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch4
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x4
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x5
    jmp    Branch5
  Branch4:
    mov    ecx,DWORD PTR [esp+0x44]
    push    0x0
    push    0x4
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch7
    mov    ebx,0x6
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x7
  Branch5:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch6:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0xc
  Branch7:
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],0x8
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x34],0x9
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch8:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    mov    al,bl
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0xc
  }
}

// Refresh4e and parse current record; normalize only AL, retaining parser upperEAX/RET8.
// R6GameService.dll @ 1004d2b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4e(void *owner,byte *delimiterOut,void *fourBytesOut)
{
  __asm {
    push    esi
    push    0x4e
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x4e
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh4b/parse; nonquoted result fetches type1 item1 and copies raw string through NUL.
// Typed output reuses saved ECX; text destination is loaded afterward. Preserve raw failure/upperEAX/AL1.
// R6GameService.dll @ 1004d2e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4bText(
    void *owner,byte *delimiterOut,void *fourBytesOut,char *textOut)
{
  __asm {
    push    ecx
    push    esi
    push    edi
    push    0x4b
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [esp+0x10]
    push    eax
    push    edi
    push    0x4b
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch9
    pop    edi
    pop    esi
    pop    ecx
    ret    0xc
  Branch9:
    cmp    BYTE PTR [edi],0x27
    je    Branch11
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x8]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch10
    pop    edi
    pop    esi
    pop    ecx
    ret    0xc
  Branch10:
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [eax+0xc]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
  Branch11:
    pop    edi
    mov    al,0x1
    pop    esi
    pop    ecx
    ret    0xc
  }
}

// Refresh4c/parse; nonquoted result fetches type1 item1 and copies raw string through NUL.
// Typed output reuses saved ECX; text destination is loaded afterward. Preserve raw failure/upperEAX/AL1.
// R6GameService.dll @ 1004d350 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4cText(
    void *owner,byte *delimiterOut,void *fourBytesOut,char *textOut)
{
  __asm {
    push    ecx
    push    esi
    push    edi
    push    0x4c
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x14]
    mov    edi,DWORD PTR [esp+0x10]
    push    eax
    push    edi
    push    0x4c
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch12
    pop    edi
    pop    esi
    pop    ecx
    ret    0xc
  Branch12:
    cmp    BYTE PTR [edi],0x27
    je    Branch14
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x8]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch13
    pop    edi
    pop    esi
    pop    ecx
    ret    0xc
  Branch13:
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [eax+0xc]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
  Branch14:
    pop    edi
    mov    al,0x1
    pop    esi
    pop    ecx
    ret    0xc
  }
}

// If inherited cookie EBP-2c bit0 is set, pass EBP-10 to genuine no-op59130; otherwise return.
// R6GameService.dll @ 10068320 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x2c]
    and    eax,0x1
    test    eax,eax
    je    Branch15
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch15:
    ret
  }
}

// Reset parser descriptor EBP-28 base after constructor failure, then cookie predecessor0.
// R6GameService.dll @ 10068337 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy parser completed descriptor EBP-28 fully; no predecessor.
// R6GameService.dll @ 1006833f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset parser EBP-28 base after entered copy-failure head release; no predecessor.
// R6GameService.dll @ 10068347 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT selector argument EBP+4 plus4 via scratchEBP-38, then predecessor4 base.
// R6GameService.dll @ 1006834f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch16
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch17
  Branch16:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch17:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset parser EBP-28 base after entered four-byte-read failure head release; no predecessor.
// R6GameService.dll @ 10068376 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT selector argument EBP+4 plus4 via scratchEBP-40, then predecessor6 base.
// R6GameService.dll @ 1006837e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch18
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x40],eax
    jmp    Branch19
  Branch18:
    mov    DWORD PTR [ebp-0x40],0x0
  Branch19:
    mov    ecx,DWORD PTR [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset parser EBP-28 base after entered successful head release; no predecessor.
// R6GameService.dll @ 100683a5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT selector argument EBP+4 plus4 via scratchEBP-48, then predecessor8 base.
// R6GameService.dll @ 100683ad : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReadTransportSelectorRecordUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch20
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x48],eax
    jmp    Branch21
  Branch20:
    mov    DWORD PTR [ebp-0x48],0x0
  Branch21:
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact ten-state FuncInfo82d74/map82d24, including unarmed null-action state2.
// R6GameService.dll @ 100683d4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportRecordEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReadTransportSelectorRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal transport record parser unwind map/FuncInfo words.
// R6GameService.dll data @ 10082d24 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReadTransportSelectorRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind1},
  {0x0, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind2},
  {0x1, 0x0},
  {-1, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind4},
  {-1, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind5},
  {0x4, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind6},
  {-1, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind7},
  {0x6, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind8},
  {-1, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind9},
  {0x8, R6GameServiceAddresses::ReadTransportSelectorRecordUnwind10},
};

// Literal transport record parser unwind map/FuncInfo words.
// R6GameService.dll data @ 10082d74 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReadTransportSelectorRecordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::ReadTransportSelectorRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// If full field+8 is zero, store both supplied DWORDs+8/+c, including NULL, and return first-word upper24/AL1.
// Occupied field leaves both unchanged and returns old-word upper24/AL0; RET8, no own EH.
// R6GameService.dll @ 1004d050 : complete native control/access order and raw ABI retained.
uint __thiscall InstallTransportFieldsIfEmpty(void *owner,uint transportWord,uint queueWord)
{
  auto *words = static_cast<uint *>(owner);
  uint currentTransport = words[2];
  if (currentTransport != 0) return currentTransport & 0xffffff00;
  words[2] = transportWord;
  words[3] = queueWord;
  return (transportWord & 0xffffff00) | 1;
}

// Guard transport+8, construct empty descriptor and send5c/mode1 through CURRENT transport; ignore send result.
// Native pointer-list clear/node clear/header free supplies upperEAX/AL1; preserve six-state no-retry cleanup.
// R6GameService.dll @ 1004d070 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendSelector5cIfTransportAvailable(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransportSendersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch23
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch23:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x20]
    push    eax
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x30],0x2
    push    ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push    0x1
    push    0x5c
    call    R6GameServiceAddresses::SendTransportPayload
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x8],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0xc],eax
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    ecx,DWORD PTR [esp+0x20]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x28]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  }
}

// Guard transport+8, append FOUR raw bytes from each caller DWORD and send4e/mode1 through CURRENT transport.
// Ignore append/send status, then split pointer-list/node/header cleanup and return cleanup upperEAX/AL1.
// R6GameService.dll @ 1004d180 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSelector4eWordPair(void *owner,uint firstWord,uint secondWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransportSendersEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch24
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x8
  Branch24:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x20]
    push    eax
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x38]
    push    0x4
    push    ecx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x38],0x2
    call    R6GameServiceAddresses::AppendClDataListBinary
    lea    edx,[esp+0x3c]
    push    0x4
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::AppendClDataListBinary
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0x10]
    push    eax
    push    0x1
    push    0x4e
    call    R6GameServiceAddresses::SendTransportPayload
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x8],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0xc],edx
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x20]
    push    0x1
    push    eax
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x28]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret    0x8
  }
}

// Gate enabled BYTE148/parser pointer14c, drain queue168, reload parser/sender154/argument DWORDs and send4e.
// Installation status ignored; disabled retains incoming EAX upper24, NULL parser returns0, success raw sender EAX.
// R6GameService.dll @ 10040b40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendWordPairSelector4e(void *owner,uint firstWord,uint secondWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x148]
    test    al,al
    je    Branch25
    mov    eax,DWORD PTR [esi+0x14c]
    test    eax,eax
    je    Branch25
    push    edi
    lea    edi,[esi+0x168]
    mov    ecx,edi
    call    R6GameServiceAddresses::DrainCMsgQueue
    mov    eax,DWORD PTR [esi+0x14c]
    mov    ecx,DWORD PTR [esi+0x154]
    push    edi
    push    eax
    call    R6GameServiceAddresses::InstallTransportFieldsIfEmpty
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x154]
    push    edx
    call    R6GameServiceAddresses::SendSelector4eWordPair
    pop    edi
    pop    esi
    ret    0x8
  Branch25:
    xor    al,al
    pop    esi
    ret    0x8
  }
}

// Load sender POINTER owner+154 and tail-forward selector5c; preserve full raw EAX and original return address.
// R6GameService.dll @ 10040ba0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendSelector5cViaOffset154(void *owner)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x154]
    jmp    R6GameServiceAddresses::SendSelector5cIfTransportAvailable
  }
}

// Reset sender descriptor EBP-24 base after header constructor failure.
// R6GameService.dll @ 100683e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass incoming cookie EBP-2d to genuine no-op59130, then predecessor0 base reset.
// R6GameService.dll @ 100683e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy sender completed descriptor EBP-24 fully; no predecessor.
// R6GameService.dll @ 100683f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset sender EBP-24 base after entered pointer-list/header cleanup; no predecessor.
// R6GameService.dll @ 100683f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT local context EBP-2c plus4, save EBP-28, then predecessor3 base reset.
// R6GameService.dll @ 10068400 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x2c],0x0
    je    Branch26
    mov    eax,DWORD PTR [ebp-0x2c]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch27
  Branch26:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch27:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Load saved head-context EBP-28 and tail genuine no-op59130; predecessor3 without retry.
// R6GameService.dll @ 10068427 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select shared5c/4e sender six-state FuncInfo82e0c/map82ddc and tail CRT dispatch.
// R6GameService.dll @ 1006842f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportSendersEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_record_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared transport sender unwind map/FuncInfo words.
// R6GameService.dll data @ 10082ddc : native storage identity retained.
const R6GameServiceNative::UnwindEntry transport_record_supportSharedLifetimeUnwindMap[6] = {
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind1},
  {0x0, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind2},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind3},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind4},
  {0x3, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind5},
  {0x3, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind6},
};

// Literal shared transport sender unwind map/FuncInfo words.
// R6GameService.dll data @ 10082e0c : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_record_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh65, gate cached tag65, then query type1 items0/1/2 and copy each live string through NUL in order.
// Reload current payload/output pointers at each stage; preserve prior writes/raw failure or last-source upperEAX/AL1.
// R6GameService.dll @ 1004d3c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector65Strings(
    void *owner,char *firstOut,char *secondOut,char *thirdOut)
{
  __asm {
    sub    esp,0xc
    push    esi
    push    0x65
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    jne    Branch28
    xor    al,al
    pop    esi
    add    esp,0xc
    ret    0xc
  Branch28:
    cmp    BYTE PTR [eax+0x4],0x65
    je    Branch29
    xor    al,al
    pop    esi
    add    esp,0xc
    ret    0xc
  Branch29:
    lea    ecx,[esp+0x4]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch30
    pop    esi
    add    esp,0xc
    ret    0xc
  Branch30:
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [edx+0xc]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[esp+0x8]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch31
    pop    esi
    add    esp,0xc
    ret    0xc
  Branch31:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0xc]
    push    0x2
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch32
    pop    esi
    add    esp,0xc
    ret    0xc
  Branch32:
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [eax+0xc]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    al,0x1
    pop    esi
    add    esp,0xc
    ret    0xc
  }
}

// Build descriptor before refresh58/actual lower parser. Captured delimiter26 reads direct item1; others clone list1.
// Copy type1 item1 string through NUL, preserving current cache/late text destination and raw cleanup upperEAX/AL.
// Shared58/5b map keeps distinct entered destruction; nested success rewrites third argument as cleanup context.
// R6GameService.dll @ 1004d490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector58Fields(
    void *owner,char *delimiterOut,uint *fourBytesOut,char *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport58And5bEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    xor    eax,eax
    push    ebx
    push    esi
    mov    DWORD PTR [esp+0x8],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    push    0x58
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x3c]
    mov    ebx,DWORD PTR [esp+0x38]
    push    eax
    push    ebx
    push    0x58
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch33
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch33:
    mov    al,BYTE PTR [ebx]
    push    0x1
    cmp    al,0x26
    jne    Branch35
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch34
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch34:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0xc]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    jmp    Branch38
  Branch35:
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[esp+0x14]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch36
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch36:
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch37
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch37:
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,esi
    mov    eax,DWORD PTR [edx+0xc]
    push    eax
    mov    eax,DWORD PTR [esp+0x44]
    push    eax
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x7
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch38:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Reset shared58/5b descriptor EBP-24 base after constructor failure.
// R6GameService.dll @ 10068490 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy shared58/5b completed descriptor EBP-24 fully.
// R6GameService.dll @ 10068498 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind22(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared58/5b EBP-24 base after entered state2 pointer-list destruction.
// R6GameService.dll @ 100684a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind32(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared58/5b EBP-24 base after entered state3 pointer-list destruction.
// R6GameService.dll @ 100684a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind42(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared58/5b EBP-24 base after entered state4 pointer-list destruction.
// R6GameService.dll @ 100684b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind52(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared58/5b EBP-24 base after entered state5 pointer-list destruction.
// R6GameService.dll @ 100684b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind62(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared58/5b EBP-24 base after entered state6 pointer-list destruction.
// R6GameService.dll @ 100684c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared58/5b EBP-24 base after entered successful head release, without retry.
// R6GameService.dll @ 100684c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT third argument EBP+c plus4 via scratchEBP-3c, then predecessor7 base reset.
// R6GameService.dll @ 100684d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0xc],0x0
    je    Branch39
    mov    eax,DWORD PTR [ebp+0xc]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch40
  Branch39:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch40:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact nine-state FuncInfo82f30/map82ee8 shared by independently reviewed58/5b parents.
// R6GameService.dll @ 100684f7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport58And5bEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_record_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared58/5b unwind map/FuncInfo words.
// R6GameService.dll data @ 10082ee8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry transport_record_supportSharedLifetimeUnwindMap2[9] = {
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind12},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind22},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind32},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind42},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind52},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind62},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind7},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind8},
  {0x7, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind9},
};

// Literal shared58/5b unwind map/FuncInfo words.
// R6GameService.dll data @ 10082f30 : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_record_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Build outer descriptor, refresh5a, copy type1 item0 text, clone list1 and read exact DWORD count item0.
// Allocate exact live count, publish before payload item1 copy and reload count; failed copy retains allocation.
// Eight-state cleanup owns descriptor only; preserve late outputs, raw cleanup upperEAX/AL and RETc.
// R6GameService.dll @ 1004d6d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector5aOwnedBytes(
    void *owner,char *textOut,void **bufferOut,uint *countOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport5aEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    mov    DWORD PTR [esp+0x8],0x0
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x3
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    push    0x5a
    mov    ecx,esi
    mov    DWORD PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    jne    Branch41
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch41:
    cmp    BYTE PTR [eax+0x4],0x5a
    je    Branch42
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch42:
    lea    ecx,[esp+0x8]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch43
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch43:
    mov    edx,DWORD PTR [esp+0x8]
    mov    ecx,esi
    mov    eax,DWORD PTR [edx+0xc]
    push    eax
    mov    eax,DWORD PTR [esp+0x38]
    push    eax
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch44
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch44:
    mov    esi,DWORD PTR [esp+0x3c]
    push    0x0
    push    0x4
    push    esi
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch45
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch45:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x38]
    push    0x1
    mov    DWORD PTR [ecx],eax
    mov    edx,DWORD PTR [esi]
    push    edx
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch46
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],ebx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch46:
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x2c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Build descriptor before refresh5b/lower parser. Captured delimiter26 reads direct item1; other bytes clone list1.
// Copy borrowed type1 item1 string through NUL; preserve late outputs/raw cleanup and shared58/5b nine-state map.
// Nested success rewrites third argument as current list context; no rollback or extra delimiter validation. RETc.
// R6GameService.dll @ 1004d920 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector5bFields(
    void *owner,char *delimiterOut,uint *fourBytesOut,char *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport58And5bEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    xor    eax,eax
    push    ebx
    push    esi
    mov    DWORD PTR [esp+0x8],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    push    0x5b
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x3c]
    mov    ebx,DWORD PTR [esp+0x38]
    push    eax
    push    ebx
    push    0x5b
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch47
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch47:
    mov    al,BYTE PTR [ebx]
    push    0x1
    cmp    al,0x26
    jne    Branch49
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch48
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch48:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x40]
    mov    eax,DWORD PTR [eax+0xc]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    jmp    Branch52
  Branch49:
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[esp+0x14]
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch50
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch50:
    lea    ecx,[esp+0xc]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch51
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  Branch51:
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,esi
    mov    eax,DWORD PTR [edx+0xc]
    push    eax
    mov    eax,DWORD PTR [esp+0x44]
    push    eax
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x7
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch52:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0xc
  }
}

// Parse5a into incoming frame bytes and zeroed pointer cell; failure skips callback and free, retaining published heap.
// Load current callback slot24, capture payload, call text/payload/count, then free captured pointer even if NULL.
// Ignore callback result; return final free upperEAX/AL1. Callback interruption has no wrapper-owned heap guard.
// R6GameService.dll @ 1004e2c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedOwnedBuffer(void *owner)
{
  __asm {
    sub    esp,0x18
    push    esi
    mov    esi,ecx
    lea    eax,[esp+0x8]
    lea    ecx,[esp+0x4]
    push    eax
    lea    edx,[esp+0x10]
    push    ecx
    push    edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0x0
    call    R6GameServiceAddresses::ParseSelector5aOwnedBytes
    test    al,al
    je    Branch53
    mov    edx,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esi+0x10]
    mov    esi,DWORD PTR [esp+0x4]
    push    edx
    mov    eax,DWORD PTR [ecx]
    lea    edx,[esp+0x10]
    push    esi
    push    edx
    call    DWORD PTR [eax+0x24]
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  Branch53:
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  }
}

// Parse5b into incoming frame bytes, then invoke current callback slot28 with two FULL DWORDs and text address.
// Delimiter writes only lowBYTE; direct26 leaves second word untouched. Return callback upperEAX/AL1 or parse failure.
// R6GameService.dll @ 1004e320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot28(void *owner)
{
  __asm {
    sub    esp,0x18
    lea    eax,[esp+0x8]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector5bFields
    test    al,al
    je    Branch54
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0xc]
    push    edx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    DWORD PTR [eax+0x28]
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  Branch54:
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  }
}

// Reset descriptor EBP-24 base after constructor failure.
// R6GameService.dll @ 10068440 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed descriptor EBP-24 fully.
// R6GameService.dll @ 10068448 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor EBP-24 base after entered missing-cache destruction.
// R6GameService.dll @ 10068450 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor EBP-24 base after entered wrong-tag destruction.
// R6GameService.dll @ 10068458 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor EBP-24 base after entered typed-item failure destruction.
// R6GameService.dll @ 10068460 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor EBP-24 base after entered list-copy failure destruction.
// R6GameService.dll @ 10068468 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor EBP-24 base after entered count-read failure destruction.
// R6GameService.dll @ 10068470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor EBP-24 base after entered payload-read failure destruction.
// R6GameService.dll @ 10068478 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5aOwnedBytesUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact eight-state descriptor FuncInfo82ecc/map82e8c; output heap is absent from this cleanup map.
// R6GameService.dll @ 10068480 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport5aEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector5aOwnedBytesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal5a descriptor unwind map/FuncInfo; raw output heap has no action.
// R6GameService.dll data @ 10082e8c : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector5aOwnedBytesUnwindMap[8] = {
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind2},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind3},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind4},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind5},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind6},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind7},
  {-1, R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwind8},
};

// Literal5a descriptor unwind map/FuncInfo; raw output heap has no action.
// R6GameService.dll data @ 10082ecc : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector5aOwnedBytesExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::ParseSelector5aOwnedBytesUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh85 before loading current output argument pointers, then parse matching selector with actual lower reader.
// Preserve current cache, early delimiter/partial DWORD publication and lower upperEAX; normalize only AL. RET8.
// R6GameService.dll @ 1004db60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector85(void *owner,byte *delimiterOut,uint *fourBytesOut)
{
  __asm {
    push    esi
    push    0x85
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x85
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh51 before loading current output argument pointers, then parse matching selector with actual lower reader.
// Preserve current cache, early delimiter/partial DWORD publication and lower upperEAX; normalize only AL. RET8.
// R6GameService.dll @ 1004db90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector51(void *owner,byte *delimiterOut,uint *fourBytesOut)
{
  __asm {
    push    esi
    push    0x51
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x51
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Parse4e and gate AL before current callback slot00; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// R6GameService.dll @ 1004e140 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector4e(void *owner)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector4e
    test    al,al
    je    Branch55
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch55:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Parse4b and gate AL before current callback slot04; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// Pass incoming text region at entryW-10 even when quote27 skips its copy; no wrapper initialization or EH.
// R6GameService.dll @ 1004e180 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector4b(void *owner)
{
  __asm {
    sub    esp,0x18
    lea    eax,[esp+0x8]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector4bText
    test    al,al
    je    Branch56
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0xc]
    push    edx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    DWORD PTR [eax+0x4]
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  Branch56:
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  }
}

// Parse4c and gate AL before current callback slot08; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// Pass incoming text region at entryW-10 even when quote27 skips its copy; no wrapper initialization or EH.
// R6GameService.dll @ 1004e1d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector4c(void *owner)
{
  __asm {
    sub    esp,0x18
    lea    eax,[esp+0x8]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector4cText
    test    al,al
    je    Branch57
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0xc]
    push    edx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    DWORD PTR [eax+0x8]
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  Branch57:
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  }
}

// Parse65 into incoming stack regions at entryW-414/-404/-424, then pass those addresses to current callback slot1c.
// Sequential live copies have no per-region bounds and can overwrite earlier regions; preserve native address order.
// Failure skips callback; success returns callback upperEAX/AL1. No wrapper EH or region initialization.
// R6GameService.dll @ 1004e220 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot1c(void *owner)
{
  __asm {
    sub    esp,0x424
    lea    eax,[esp+0x0]
    lea    edx,[esp+0x10]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x24]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector65Strings
    test    al,al
    je    Branch58
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0x4]
    push    edx
    lea    edx,[esp+0x28]
    mov    eax,DWORD PTR [ecx]
    push    edx
    lea    edx,[esp+0x1c]
    push    edx
    call    DWORD PTR [eax+0x1c]
    mov    al,0x1
    pop    esi
    add    esp,0x424
    ret
  Branch58:
    xor    al,al
    pop    esi
    add    esp,0x424
    ret
  }
}

// Parse58 and gate AL before current callback slot20; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// Pass text at entryW-10 after direct or nested parser path; no wrapper initialization or EH.
// R6GameService.dll @ 1004e270 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot20(void *owner)
{
  __asm {
    sub    esp,0x18
    lea    eax,[esp+0x8]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector58Fields
    test    al,al
    je    Branch59
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0xc]
    push    edx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    DWORD PTR [eax+0x20]
    mov    al,0x1
    pop    esi
    add    esp,0x18
    ret
  Branch59:
    xor    al,al
    pop    esi
    add    esp,0x18
    ret
  }
}

// Parse85 and gate AL before current callback slot2c; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// R6GameService.dll @ 1004e370 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot2c(void *owner)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector85
    test    al,al
    je    Branch60
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x2c]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch60:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Parse51 and gate AL before current callback slot30; pass full retained output DWORDs.
// Delimiter sets lowBYTE only; direct26 leaves second word incoming. Preserve callback upperEAX/AL1 or failure AL0.
// R6GameService.dll @ 1004e3b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot30(void *owner)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector51
    test    al,al
    je    Branch61
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x30]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch61:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Refresh4a/tag gate; query/copy borrowed text0, exact DWORD1, borrowed text2, exact DWORD3/4, then indexed text5.
// Preserve staged writes/current payload/late outputs and full failed-reader EAX; text5 failure still succeeds.
// Fallback strncpy132 from93bf4 and clamp byte131; no bound on successful indexed/live copies or rollback. RET18.
// R6GameService.dll @ 1004dbc0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4aFields(
    void *owner,char *firstText,uint *firstValue,char *secondText,uint *secondValue,uint *thirdValue,char *lastText)
{
  __asm {
    sub    esp,0x8
    push    esi
    push    0x4a
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    jne    Branch62
    xor    al,al
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch62:
    cmp    BYTE PTR [eax+0x4],0x4a
    je    Branch63
    xor    al,al
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch63:
    lea    ecx,[esp+0x4]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch64
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch64:
    mov    edx,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [edx+0xc]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esp+0x14]
    push    0x1
    push    0x4
    mov    ecx,DWORD PTR [eax+0x8]
    push    edx
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch65
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch65:
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x8]
    push    0x2
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch66
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch66:
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [eax+0xc]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esp+0x1c]
    push    0x3
    push    0x4
    mov    ecx,DWORD PTR [ecx+0x8]
    push    eax
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch67
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch67:
    mov    eax,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esp+0x20]
    push    0x4
    push    0x4
    mov    ecx,DWORD PTR [eax+0x8]
    push    edx
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch68
    pop    esi
    add    esp,0x8
    ret    0x18
  Branch68:
    mov    ecx,DWORD PTR [esi+0x4]
    push    edi
    mov    edi,DWORD PTR [esp+0x28]
    push    0x5
    mov    ecx,DWORD PTR [ecx+0x8]
    push    edi
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch69
    push    0x84
    push    R6GameServiceAddresses::GRegistrationEmptyText
    push    edi
    call    R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x83]
    add    esp,0xc
    test    al,al
    je    Branch69
    mov    BYTE PTR [edi+0x83],0x0
  Branch69:
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret    0x18
  }
}

// Refresh08/lower parse with captured delimiter pointer; only current byte26 constructs extra descriptor/list1.
// Read text0, exact DWORD1, text2; failed text2 copies live fallback through NUL and succeeds, preserving later bytes.
// Outer S-24/listS-18/headS-14/stateS-4; entered split cleanup rewrites second argumentS+8. RET14.
// R6GameService.dll @ 1004dcf0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector08Fields(
    void *owner,byte *delimiterOut,uint *valueOut,char *textOut,uint *extraValueOut,char *lastText)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport08EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    push    edi
    push    0x8
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],0x0
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x3c]
    mov    edi,DWORD PTR [esp+0x38]
    push    eax
    push    edi
    push    0x8
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    je    Branch73
    cmp    BYTE PTR [edi],0x26
    jne    Branch77
    mov    ebx,0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch70
    mov    DWORD PTR [esp+0x10],edi
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch70:
    mov    ecx,DWORD PTR [esp+0x40]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch71
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x4
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x5
    jmp    Branch72
  Branch71:
    mov    eax,DWORD PTR [esp+0x44]
    push    0x1
    push    0x4
    push    eax
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch74
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x6
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x30],0x7
  Branch72:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch73:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch74:
    mov    esi,DWORD PTR [esp+0x48]
    push    0x2
    push    esi
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch76
    mov    eax,R6GameServiceAddresses::GRegistrationEmptyText
    mov    edx,esi
    sub    edx,eax
  Branch75:
    mov    cl,BYTE PTR [eax]
    mov    BYTE PTR [edx+eax*1],cl
    inc    eax
    test    cl,cl
    jne    Branch75
  Branch76:
    mov    DWORD PTR [esp+0x10],edi
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x8
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x9
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch77:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  }
}

// Refresh98/lower parse; only captured delimiter byte26 constructs extra descriptor and reads list1 text0/1/2.
// Failures retain prior/partial writes; direct early pointer-list and later split clear/head cleanup stay distinct.
// Nine-state map owns outerS-24; split paths rewrite second argumentS+8, other delimiter bytes skip outputs. RET14.
// R6GameService.dll @ 1004df10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector98Fields(
    void *owner,byte *delimiterOut,uint *valueOut,char *firstText,char *secondText,char *thirdText)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport98EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    push    edi
    xor    ebx,ebx
    push    0x98
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x3c]
    mov    edi,DWORD PTR [esp+0x38]
    push    eax
    push    edi
    push    0x98
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch78
    pop    edi
    pop    esi
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch78:
    cmp    BYTE PTR [edi],0x26
    jne    Branch83
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x38],0x1
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch79
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch79:
    mov    eax,DWORD PTR [esp+0x40]
    push    0x0
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch80
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch80:
    mov    ecx,DWORD PTR [esp+0x44]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch81
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch81:
    mov    edx,DWORD PTR [esp+0x48]
    push    0x2
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch82
    mov    ebx,0x5
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  Branch82:
    mov    ebx,0x7
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch83:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x14
  }
}

// Parse4a then current callback34(firstW-b8,wordW-c4,secondW-a8,wordW-c0,wordW-bc,lastW-84).
// Preserve incoming/partial frame bytes, unchecked string regions and callback upperEAX/AL1; failure skips callback.
// R6GameService.dll @ 1004e3f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot34(void *owner)
{
  __asm {
    sub    esp,0xc4
    lea    eax,[esp+0x40]
    lea    edx,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0xc]
    push    eax
    push    ecx
    lea    eax,[esp+0x28]
    push    edx
    lea    ecx,[esp+0x10]
    push    eax
    lea    edx,[esp+0x20]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector4aFields
    test    al,al
    je    Branch84
    lea    edx,[esp+0x44]
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx]
    push    edx
    lea    edx,[esp+0x2c]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    edx
    lea    edx,[esp+0x24]
    push    edx
    call    DWORD PTR [eax+0x34]
    mov    al,0x1
    pop    esi
    add    esp,0xc4
    ret
  Branch84:
    xor    al,al
    pop    esi
    add    esp,0xc4
    ret
  }
}

// Parse08 then current callback38(full wordW-a0,full wordW-98,textW-94,wordW-9c,lastW-84).
// Quote path leaves extra outputs incoming; preserve full retained DWORDs and raw upperEAX/AL, no initialization/EH.
// R6GameService.dll @ 1004e460 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot38(void *owner)
{
  __asm {
    sub    esp,0xa0
    lea    eax,[esp+0x1c]
    lea    edx,[esp+0xc]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push    eax
    push    ecx
    lea    eax,[esp+0x14]
    push    edx
    lea    ecx,[esp+0x10]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector08Fields
    test    al,al
    je    Branch85
    lea    eax,[esp+0x20]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    call    DWORD PTR [edx+0x38]
    mov    al,0x1
    pop    esi
    add    esp,0xa0
    ret
  Branch85:
    xor    al,al
    pop    esi
    add    esp,0xa0
    ret
  }
}

// Parse98 then current callback3c(full wordW-438,full wordW-43c,textW-434,textW-424,textW-400).
// Quote path forwards untouched text regions; preserve current receiver/full retained words and callback upperEAX/AL1.
// R6GameService.dll @ 1004e4d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSlot3c(void *owner)
{
  __asm {
    sub    esp,0x43c
    lea    eax,[esp+0x3c]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x1c]
    push    eax
    push    ecx
    lea    eax,[esp+0xc]
    push    edx
    lea    ecx,[esp+0x14]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector98Fields
    test    al,al
    je    Branch86
    lea    eax,[esp+0x40]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    lea    eax,[esp+0x20]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0x18]
    push    eax
    call    DWORD PTR [edx+0x3c]
    mov    al,0x1
    pop    esi
    add    esp,0x43c
    ret
  Branch86:
    xor    al,al
    pop    esi
    add    esp,0x43c
    ret
  }
}

// Reset08 descriptor EBP-24 base after constructor failure.
// R6GameService.dll @ 10068510 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy08 completed descriptor EBP-24 fully.
// R6GameService.dll @ 10068518 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset08 EBP-24 base after entered list-copy failure head release.
// R6GameService.dll @ 10068520 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release08 head through CURRENT second argument EBP+8 plus4 via scratchEBP-2c, preserving NULL; predecessor2.
// R6GameService.dll @ 10068528 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch87
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2c],eax
    jmp    Branch88
  Branch87:
    mov    DWORD PTR [ebp-0x2c],0x0
  Branch88:
    mov    ecx,DWORD PTR [ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset08 EBP-24 base after entered text0-failure head release.
// R6GameService.dll @ 1006854f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release08 head through CURRENT second argument EBP+8 plus4 via scratchEBP-34, preserving NULL; predecessor4.
// R6GameService.dll @ 10068557 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch89
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch90
  Branch89:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch90:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset08 EBP-24 base after entered DWORD1-failure head release.
// R6GameService.dll @ 1006857e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release08 head through CURRENT second argument EBP+8 plus4 via scratchEBP-3c, preserving NULL; predecessor6.
// R6GameService.dll @ 10068586 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch91
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch92
  Branch91:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch92:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset08 EBP-24 base after entered successful head release.
// R6GameService.dll @ 100685ad : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release08 head through CURRENT second argument EBP+8 plus4 via scratchEBP-44, preserving NULL; predecessor8.
// R6GameService.dll @ 100685b5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector08FieldsUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch93
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch94
  Branch93:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch94:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact08 FuncInfo82f9c/map82f4c; preserve distinct full/base/entered head cleanup states.
// R6GameService.dll @ 100685dc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport08EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector08FieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset98 descriptor EBP-24 base after constructor failure.
// R6GameService.dll @ 100685f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy98 completed descriptor EBP-24 fully.
// R6GameService.dll @ 100685f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset98 EBP-24 base after entered list-copy failure pointer-list destruction.
// R6GameService.dll @ 10068600 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset98 EBP-24 base after entered text0-failure pointer-list destruction.
// R6GameService.dll @ 10068608 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset98 EBP-24 base after entered text1-failure pointer-list destruction.
// R6GameService.dll @ 10068610 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset98 EBP-24 base after entered text2-failure head release.
// R6GameService.dll @ 10068618 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release98 head through CURRENT second argument EBP+8 plus4 via scratchEBP-2c, preserving NULL; predecessor5.
// R6GameService.dll @ 10068620 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch95
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x2c],eax
    jmp    Branch96
  Branch95:
    mov    DWORD PTR [ebp-0x2c],0x0
  Branch96:
    mov    ecx,DWORD PTR [ebp-0x2c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset98 EBP-24 base after entered successful head release.
// R6GameService.dll @ 10068647 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release98 head through CURRENT second argument EBP+8 plus4 via scratchEBP-34, preserving NULL; predecessor7.
// R6GameService.dll @ 1006864f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector98FieldsUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je    Branch97
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x34],eax
    jmp    Branch98
  Branch97:
    mov    DWORD PTR [ebp-0x34],0x0
  Branch98:
    mov    ecx,DWORD PTR [ebp-0x34]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact98 FuncInfo83000/map82fb8; preserve distinct full/base/entered head cleanup states.
// R6GameService.dll @ 10068676 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport98EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector98FieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal08/98 descriptor unwind map/FuncInfo words.
// R6GameService.dll data @ 10082f4c : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector08FieldsUnwindMap[10] = {
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind2},
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind3},
  {0x2, R6GameServiceAddresses::ParseSelector08FieldsUnwind4},
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind5},
  {0x4, R6GameServiceAddresses::ParseSelector08FieldsUnwind6},
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind7},
  {0x6, R6GameServiceAddresses::ParseSelector08FieldsUnwind8},
  {-1, R6GameServiceAddresses::ParseSelector08FieldsUnwind9},
  {0x8, R6GameServiceAddresses::ParseSelector08FieldsUnwind10},
};

// Literal08/98 descriptor unwind map/FuncInfo words.
// R6GameService.dll data @ 10082f9c : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector08FieldsExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::ParseSelector08FieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal08/98 descriptor unwind map/FuncInfo words.
// R6GameService.dll data @ 10082fb8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector98FieldsUnwindMap[9] = {
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind2},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind3},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind4},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind5},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind6},
  {0x5, R6GameServiceAddresses::ParseSelector98FieldsUnwind7},
  {-1, R6GameServiceAddresses::ParseSelector98FieldsUnwind8},
  {0x7, R6GameServiceAddresses::ParseSelector98FieldsUnwind9},
};

// Literal08/98 descriptor unwind map/FuncInfo words.
// R6GameService.dll data @ 10083000 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector98FieldsExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::ParseSelector98FieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Construct two descriptors before refresh4f/lower parse, clone list1, then select direct or quote27 nested text.
// Read bounded text item0 with count16; on success publish mapped code through late caller pointer before cleanup.
// EntryS: firstS-3c/secondS-24/valueS-40=0/delimiterS-41/stateS-4. Preserve partial text/raw cleanup EAX and RET8.
// Direct code02250000; quoted full DWORD13/14/other maps82256221/8225621a/82254005. No rollback.
// R6GameService.dll @ 1004e540 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4fCodeAndText(void *owner,uint *codeOut,char *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport4f50EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebx
    push    ebp
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    push    ebx
    mov    DWORD PTR [esp+0x18],ebx
    push    0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x54],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    ebx
    push    0x3
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x58],0x1
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x54],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    push    0x4f
    mov    ecx,esi
    mov    BYTE PTR [esp+0x54],0x3
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x13]
    push    eax
    push    ecx
    push    0x4f
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch99
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch102
  Branch99:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,0x1
    lea    edx,[esp+0x18]
    push    ebx
    mov    ecx,DWORD PTR [eax+0x8]
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch100
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch102
  Branch100:
    cmp    BYTE PTR [esp+0x13],0x27
    jne    Branch106
    lea    ecx,[esp+0x30]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    lea    ecx,[esp+0x30]
    jne    Branch101
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch102
  Branch101:
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x10
    push    0x0
    push    edx
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch103
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
  Branch102:
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x50],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch109
  Branch103:
    mov    eax,DWORD PTR [esp+0x14]
    sub    eax,0xd
    je    Branch105
    dec    eax
    je    Branch104
    mov    eax,DWORD PTR [esp+0x58]
    mov    DWORD PTR [eax],0x82254005
    jmp    Branch108
  Branch104:
    mov    ecx,DWORD PTR [esp+0x58]
    mov    DWORD PTR [ecx],0x8225621a
    jmp    Branch108
  Branch105:
    mov    edx,DWORD PTR [esp+0x58]
    mov    DWORD PTR [edx],0x82256221
    jmp    Branch108
  Branch106:
    mov    eax,DWORD PTR [esp+0x5c]
    push    0x10
    push    0x0
    push    eax
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch107
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch109
  Branch107:
    mov    ecx,DWORD PTR [esp+0x58]
    mov    DWORD PTR [ecx],0x2250000
  Branch108:
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,bl
  Branch109:
    mov    ecx,DWORD PTR [esp+0x48]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x8
  }
}

// Construct two descriptors before refresh50/lower parse, clone list1, then select direct or quote27 nested text.
// Read bounded text item0 with count16; on success publish mapped code through late caller pointer before cleanup.
// EntryS: firstS-3c/secondS-24/valueS-40=0/delimiterS-41/stateS-4. Preserve partial text/raw cleanup EAX and RET8.
// Direct code02250000; quoted full DWORD13/other maps82256221/82254005, including14. No rollback.
// R6GameService.dll @ 1004e770 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector50CodeAndText(void *owner,uint *codeOut,char *textOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport4f50EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebx
    push    ebp
    push    esi
    xor    ebx,ebx
    push    edi
    mov    esi,ecx
    push    ebx
    mov    DWORD PTR [esp+0x18],ebx
    push    0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x54],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    ebx
    push    0x3
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x58],0x1
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x54],0x2
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    push    0x50
    mov    ecx,esi
    mov    BYTE PTR [esp+0x54],0x3
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x13]
    push    eax
    push    ecx
    push    0x50
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    jne    Branch110
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],0x1
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch113
  Branch110:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,0x1
    lea    edx,[esp+0x18]
    push    ebx
    mov    ecx,DWORD PTR [eax+0x8]
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch111
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch113
  Branch111:
    cmp    BYTE PTR [esp+0x13],0x27
    jne    Branch115
    lea    ecx,[esp+0x30]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    lea    ecx,[esp+0x30]
    jne    Branch112
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch113
  Branch112:
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x10
    push    0x0
    push    edx
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch114
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
  Branch113:
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x50],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    xor    al,al
    jmp    Branch118
  Branch114:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x58]
    sub    eax,0xd
    neg    eax
    sbb    eax,eax
    and    eax,0xffffdde4
    add    eax,0x82256221
    mov    DWORD PTR [ecx],eax
    jmp    Branch117
  Branch115:
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x10
    push    0x0
    push    edx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch116
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    xor    al,al
    jmp    Branch118
  Branch116:
    mov    eax,DWORD PTR [esp+0x58]
    mov    DWORD PTR [eax],0x2250000
  Branch117:
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0x50],bl
    call    R6GameServiceAddresses::DestroyClDataList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x50],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,bl
  Branch118:
    mov    ecx,DWORD PTR [esp+0x48]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x8
  }
}

// Parse4f into code at entryW-14 and textW-10; on AL success call current owner+10 callback slot0c.
// Forward full code/text address and retain callback upperEAX/AL1; failure skips callback. No local EH/initialization.
// R6GameService.dll @ 1004ea40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector4f(void *owner)
{
  __asm {
    sub    esp,0x14
    lea    eax,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector4fCodeAndText
    test    al,al
    je    Branch119
    mov    ecx,DWORD PTR [esi+0x10]
    lea    eax,[esp+0x8]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0xc]
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret
  Branch119:
    xor    al,al
    pop    esi
    add    esp,0x14
    ret
  }
}

// Parse50 into code at entryW-14 and textW-10; on AL success call current owner+10 callback slot10.
// Forward full code/text address and retain callback upperEAX/AL1; failure skips callback. No local EH/initialization.
// R6GameService.dll @ 1004ea80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector50(void *owner)
{
  __asm {
    sub    esp,0x14
    lea    eax,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector50CodeAndText
    test    al,al
    je    Branch120
    mov    ecx,DWORD PTR [esi+0x10]
    lea    eax,[esp+0x8]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x10]
    mov    al,0x1
    pop    esi
    add    esp,0x14
    ret
  Branch120:
    xor    al,al
    pop    esi
    add    esp,0x14
    ret
  }
}

// Reset shared4f/50 first descriptor EBP-3c base after constructor failure.
// R6GameService.dll @ 10068680 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind13(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy shared4f/50 first completed descriptor EBP-3c fully.
// R6GameService.dll @ 10068688 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind23(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared4f/50 second descriptor EBP-24 base after constructor failure; predecessor1.
// R6GameService.dll @ 10068690 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind33(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy shared4f/50 second completed descriptor EBP-24 fully; predecessor1.
// R6GameService.dll @ 10068698 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind43(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset shared4f/50 second EBP-24 base after entered nested text-failure pointer-list destruction; predecessor1.
// R6GameService.dll @ 100686a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind53(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared4f/50 first EBP-3c base after entered direct text-failure pointer-list destruction.
// R6GameService.dll @ 100686a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind63(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset shared4f/50 first EBP-3c base after entered successful pointer-list destruction.
// R6GameService.dll @ 100686b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind72(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact seven-state FuncInfo830a8/map83070 shared by4f/50; preserve entered no-retry states4/5/6.
// R6GameService.dll @ 100686b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport4f50EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_record_supportSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared4f/50 unwind map/FuncInfo words.
// R6GameService.dll data @ 10083070 : native storage identity retained.
const R6GameServiceNative::UnwindEntry transport_record_supportSharedLifetimeUnwindMap3[7] = {
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind13},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind23},
  {0x1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind33},
  {0x1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind43},
  {0x1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind53},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind63},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind72},
};

// Literal shared4f/50 unwind map/FuncInfo words.
// R6GameService.dll data @ 100830a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_record_supportSharedLifetimeExceptionInfo3 = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwindMap3,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Refresh54/lower parse into incoming delimiterS-5 and full DWORDS-4, then publish through late output pointer.
// Quote27 full13/other maps82256221/82254005; partial DWORD retains incoming bytes. Direct code02250000.
// Quote success returns output-pointer upper24/AL1; direct retains lower-parser upper24; failure full lower EAX. RET4.
// R6GameService.dll @ 1004e990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector54EncodedValue(void *owner,uint *encodedOut)
{
  __asm {
    sub    esp,0x8
    push    esi
    push    0x54
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    lea    eax,[esp+0x8]
    lea    ecx,[esp+0x7]
    push    eax
    push    ecx
    push    0x54
    mov    ecx,esi
    call    R6GameServiceAddresses::ReadTransportSelectorRecord
    test    al,al
    pop    esi
    jne    Branch121
    add    esp,0x8
    ret    0x4
  Branch121:
    cmp    BYTE PTR [esp+0x3],0x27
    jne    Branch122
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [esp+0xc]
    sub    edx,0xd
    neg    edx
    sbb    edx,edx
    and    edx,0xffffdde4
    add    edx,0x82256221
    mov    DWORD PTR [eax],edx
    mov    al,0x1
    add    esp,0x8
    ret    0x4
  Branch122:
    mov    ecx,DWORD PTR [esp+0xc]
    mov    al,0x1
    mov    DWORD PTR [ecx],0x2250000
    add    esp,0x8
    ret    0x4
  }
}

// Refresh55, gate current cache/tag55, then copy indexed text0 through bounded API with count16.
// Missing/mismatched cache retains refresh-helper EAX upper24/AL0; copy result preserves upper24/normalizes AL. RET4.
// R6GameService.dll @ 1004ea00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CopySelector55Text(void *owner,char *textOut)
{
  __asm {
    push    esi
    push    0x55
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    esi,DWORD PTR [esi+0x4]
    test    esi,esi
    jne    Branch123
    xor    al,al
    pop    esi
    ret    0x4
  Branch123:
    cmp    BYTE PTR [esi+0x4],0x55
    je    Branch124
    xor    al,al
    pop    esi
    ret    0x4
  Branch124:
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esi+0x8]
    push    0x10
    push    0x0
    push    eax
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    setne    al
    pop    esi
    ret    0x4
  }
}

// Parse54 into saved ECX cell at entryW-4, then call current owner+10 slot14 with the full encoded word.
// Return callback upper24/AL1 and POP ECX from encoded cell; failure skips callback and restores original owner ECX.
// R6GameService.dll @ 1004eac0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector54(void *owner)
{
  __asm {
    push    ecx
    lea    eax,[esp+0x0]
    push    esi
    push    eax
    mov    esi,ecx
    call    R6GameServiceAddresses::ParseSelector54EncodedValue
    test    al,al
    je    Branch125
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,DWORD PTR [esp+0x4]
    push    eax
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x14]
    mov    al,0x1
    pop    esi
    pop    ecx
    ret
  Branch125:
    xor    al,al
    pop    esi
    pop    ecx
    ret
  }
}

// Copy55 into incoming text regionW-10 and pass its address to current owner+10 callback18 on AL success.
// Preserve partial bytes/raw upperEAX, force AL1 after callback or AL0 on failure; no own initialization/EH.
// R6GameService.dll @ 1004eaf0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchParsedSelector55Text(void *owner)
{
  __asm {
    sub    esp,0x10
    lea    eax,[esp+0x0]
    push    esi
    push    eax
    mov    esi,ecx
    call    R6GameServiceAddresses::CopySelector55Text
    test    al,al
    je    Branch126
    mov    ecx,DWORD PTR [esi+0x10]
    lea    eax,[esp+0x4]
    push    eax
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0x18]
    mov    al,0x1
    pop    esi
    add    esp,0x10
    ret
  Branch126:
    xor    al,al
    pop    esi
    add    esp,0x10
    ret
  }
}

// Publish cached tag before gating26/27, read index0 BYTE into arg2 pointer low byte and compare current arg1 lowBYTE.
// Retain original marker pointer in EDI; its current byte27 clones list1 then exact DWORD0, other bytes skip word.
// EntryS: cookieS-2c/outerS-28/listS-1c/headS-18/stateS-4; quote rewrites arg1 as CURRENT cleanup context.
// Preserve raw upperEAX/AL, partial outputs, null-action2/cookie-no-op0 and entered no-retry cleanup; RETc.
// R6GameService.dll @ 1004eb20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ValidateParserSelectorAndOptionalWord(
    void *owner,uint expectedSelector,char *markerOut,void *wordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOptionalTransportWordEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    ebx
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    push    edi
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    je    Branch130
    mov    al,BYTE PTR [eax+0x4]
    mov    edi,DWORD PTR [esp+0x40]
    cmp    al,0x26
    mov    BYTE PTR [edi],al
    je    Branch127
    cmp    al,0x27
    jne    Branch130
  Branch127:
    mov    ecx,DWORD PTR [esi+0x4]
    mov    ebx,0x1
    push    0x0
    lea    eax,[esp+0x44]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    ebx
    push    eax
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    je    Branch130
    mov    dl,BYTE PTR [esp+0x40]
    mov    al,BYTE PTR [esp+0x3c]
    cmp    dl,al
    jne    Branch130
    cmp    BYTE PTR [edi],0x27
    jne    Branch132
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x1c]
    push    0x0
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0x38],ebx
    mov    DWORD PTR [esp+0x40],eax
    call    R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],edi
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    ebx
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [esp+0x3c],0x3
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch128
    mov    DWORD PTR [esp+0x10],edi
    mov    ebx,0x4
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x5
    jmp    Branch129
  Branch128:
    mov    ecx,DWORD PTR [esp+0x44]
    push    0x0
    push    0x4
    push    ecx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    mov    DWORD PTR [esp+0x10],edi
    jne    Branch131
    mov    ebx,0x6
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x3c],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x34],0x7
  Branch129:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch130:
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0xc
  Branch131:
    lea    eax,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],0x8
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x34],0x9
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x34],0x8
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch132:
    mov    ecx,DWORD PTR [esp+0x2c]
    pop    edi
    mov    al,bl
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0xc
  }
}

// Refresh66 before late output-argument loads, then execute cached optional-word parser with expected66.
// Retain early marker/partial word output and parser upperEAX; normalize AL only, RET8. No local EH/rollback.
// R6GameService.dll @ 1004f970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RefreshSelector66Values(void *owner,char *markerOut,void *wordOut)
{
  __asm {
    push    esi
    push    0x66
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x66
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh4d before late output-argument loads, then execute cached optional-word parser with expected4d.
// Retain early marker/partial word output and parser upperEAX; normalize AL only, RET8. No local EH/rollback.
// R6GameService.dll @ 1004f9a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RefreshSelector4dValues(void *owner,char *markerOut,void *wordOut)
{
  __asm {
    push    esi
    push    0x4d
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x4d
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh01 before late output-argument loads, then execute cached optional-word parser with expected01.
// Retain early marker/partial word output and parser upperEAX; normalize AL only, RET8. No local EH/rollback.
// R6GameService.dll @ 1004fa50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RefreshSelector01Values(void *owner,char *markerOut,void *wordOut)
{
  __asm {
    push    esi
    push    0x1
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x1
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Refresh62 before late output-argument loads, then execute cached optional-word parser with expected62.
// Retain early marker/partial word output and parser upperEAX; normalize AL only, RET8. No local EH/rollback.
// R6GameService.dll @ 1004fa80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RefreshSelector62Values(void *owner,char *markerOut,void *wordOut)
{
  __asm {
    push    esi
    push    0x62
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esp+0x8]
    push    eax
    push    ecx
    push    0x62
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    setne    al
    pop    esi
    ret    0x8
  }
}

// Test construction mask1 at EBP-2c; if set pass EBP-10 to genuine no-op59130, preserving raw tested bit.
// R6GameService.dll @ 100686d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x2c]
    and    eax,0x1
    test    eax,eax
    je    Branch133
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch133:
    ret
  }
}

// Reset optional parser outer EBP-28 base; predecessor0 construction-bit action.
// R6GameService.dll @ 100686e7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy completed optional parser outer EBP-28 fully; predecessor-1.
// R6GameService.dll @ 100686ef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset optional parser EBP-28 base after entered list-copy-failure head release; predecessor-1.
// R6GameService.dll @ 100686f7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT arg1 EBP+4 plus4/NULL via scratchEBP-38; predecessor4 base reset.
// R6GameService.dll @ 100686ff : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch134
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch135
  Branch134:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch135:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset optional parser EBP-28 base after entered exact-DWORD-failure head release; predecessor-1.
// R6GameService.dll @ 10068726 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT arg1 EBP+4 plus4/NULL via scratchEBP-40; predecessor6 base reset.
// R6GameService.dll @ 1006872e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind8(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch136
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x40],eax
    jmp    Branch137
  Branch136:
    mov    DWORD PTR [ebp-0x40],0x0
  Branch137:
    mov    ecx,DWORD PTR [ebp-0x40]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset optional parser EBP-28 base after entered successful head release; predecessor-1.
// R6GameService.dll @ 10068755 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release head through CURRENT arg1 EBP+4 plus4/NULL via scratchEBP-48; predecessor8 base reset.
// R6GameService.dll @ 1006875d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ValidateParserSelectorAndOptionalWordUnwind10(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch138
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x48],eax
    jmp    Branch139
  Branch138:
    mov    DWORD PTR [ebp-0x48],0x0
  Branch139:
    mov    ecx,DWORD PTR [ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact ten-state FuncInfo83114/map830c4, including null-action2 and construction no-op0.
// R6GameService.dll @ 10068784 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOptionalTransportWordEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal optional-word unwind map/FuncInfo words; state2 action is genuinely NULL.
// R6GameService.dll data @ 100830c4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ValidateParserSelectorAndOptionalWordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind1},
  {0x0, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind2},
  {0x1, 0x0},
  {-1, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind4},
  {-1, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind5},
  {0x4, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind6},
  {-1, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind7},
  {0x6, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind8},
  {-1, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind9},
  {0x8, R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwind10},
};

// Literal optional-word unwind map/FuncInfo words; state2 action is genuinely NULL.
// R6GameService.dll data @ 10083114 : native storage identity retained.
const R6GameServiceNative::FuncInfo ValidateParserSelectorAndOptionalWordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::ValidateParserSelectorAndOptionalWordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Store full zero DWORDs at owner+8 then+c and return full1; no pointee destruction or other initialization.
// R6GameService.dll @ 1004ece0 : complete native control/access order and raw ABI retained.
uint __fastcall ClearTwoServiceStateWords(void *owner)
{
  auto *words = static_cast<uint *>(owner);
  words[2] = 0;
  words[3] = 0;
  return 1;
}

// If flagBYTE14 is0 and old pointer10 nonNULL, use old+4 vbtable displacement+8 to call adjusted vtable0(1).
// Load replacement AFTER release; set flag14=1 before pointer10. Release interruption leaves completed effects only.
// Return full release EAX on deletion,0 for oldNULL/flag0,or full replacement for nonzero flag; no own EH. RET4.
// R6GameService.dll @ 1004ecf0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StorePointerAndSetReleaseFlag(void *owner,void *replacement)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    al,BYTE PTR [esi+0x14]
    test    al,al
    jne    Branch141
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    je    Branch140
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
    mov    ecx,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x14],0x1
    mov    DWORD PTR [esi+0x10],ecx
    pop    esi
    ret    0x4
  Branch140:
    mov    edx,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x14],0x1
    mov    DWORD PTR [esi+0x10],edx
    pop    esi
    ret    0x4
  Branch141:
    mov    eax,DWORD PTR [esp+0x8]
    mov    BYTE PTR [esi+0x14],0x1
    mov    DWORD PTR [esi+0x10],eax
    pop    esi
    ret    0x4
  }
}

// Open nested CConnection+8 with full words(endpointText,portWord,1,30,0,0), gate only setup AL.
// On success reload CURRENT owner+8 then connection+4 provider and return raw WaitForTransportReady EAX.
// Missing connection clears only incoming AL; failed setup clears only its AL. No rollback/recheck/own EH. RET8.
// R6GameService.dll @ 1004ed40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenNestedConnectionAndWait(
    void *owner,const char *endpointText,uint portWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    test    ecx,ecx
    je    Branch142
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x8]
    push    0x0
    push    0x0
    push    0x1e
    push    0x1
    push    eax
    push    edx
    call    R6GameServiceAddresses::CConnectionReplaceAndStartProvider
    test    al,al
    je    Branch142
    mov    esi,DWORD PTR [esi+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    call    R6GameServiceAddresses::WaitForTransportReady
    pop    esi
    ret    0x8
  Branch142:
    xor    al,al
    pop    esi
    ret    0x8
  }
}

// Install full callback pointer through current owner+150 subobject, then force only AL1 of raw child result. RET4.
// R6GameService.dll @ 100404a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetPrimaryCallbackPointer(void *owner,void *callback)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [ecx+0x150]
    push    eax
    call    R6GameServiceAddresses::StorePointerAndSetReleaseFlag
    mov    al,0x1
    ret    0x4
  }
}

// Install full callback pointer through current owner+154 subobject, then force only AL1 of raw child result. RET4.
// R6GameService.dll @ 100408b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SetSecondaryCallbackPointer(void *owner,void *callback)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [ecx+0x154]
    push    eax
    call    R6GameServiceAddresses::StorePointerAndSetReleaseFlag
    mov    al,0x1
    ret    0x4
  }
}

// Existing metadata14c forwards open raw EAX without updating flag148; otherwise allocate/construct CConnection98.
// Disarm rawS-10/stateS-4 before publishing14c; install current150 fields with current164, ignoring install status.
// First-use failure destroys CURRENT14c via captured EDI, frees it, clears14c/current150 state and reloads status148.
// Preserve late args/current subobjects, partial publication/no rollback and final cleanup upperEAX; RET8.
// R6GameService.dll @ 100406e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall OpenPrimaryConnection(void *owner,const char *endpointText,uint portWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectPrimaryConnectionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x14c]
    test    eax,eax
    je    Branch143
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x18]
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x150]
    call    R6GameServiceAddresses::OpenNestedConnectionAndWait
    pop    esi
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  Branch143:
    push    0x98
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x4],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x10],0x0
    je    Branch144
    push    0x1
    mov    ecx,eax
    call    R6GameServiceAddresses::CConnectionConstruct
    jmp    Branch145
  Branch144:
    xor    eax,eax
  Branch145:
    mov    edx,DWORD PTR [esi+0x164]
    mov    ecx,DWORD PTR [esi+0x150]
    push    edx
    push    eax
    mov    DWORD PTR [esp+0x18],0xffffffff
    mov    DWORD PTR [esi+0x14c],eax
    call    R6GameServiceAddresses::InstallTransportFieldsIfEmpty
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x18]
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esi+0x150]
    call    R6GameServiceAddresses::OpenNestedConnectionAndWait
    test    al,al
    mov    BYTE PTR [esi+0x148],al
    jne    Branch147
    push    edi
    mov    edi,DWORD PTR [esi+0x14c]
    test    edi,edi
    je    Branch146
    mov    ecx,edi
    call    R6GameServiceAddresses::CConnectionDestroyProvider
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch146:
    mov    ecx,DWORD PTR [esi+0x150]
    mov    DWORD PTR [esi+0x14c],0x0
    call    R6GameServiceAddresses::ClearTwoServiceStateWords
    pop    edi
  Branch147:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    al,BYTE PTR [esi+0x148]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x8
  }
}

// Flag148==0 clears incoming AL; otherwise disconnect through current150 subobject and force only AL1.
// Do not clear active byte, free connection or normalize upper EAX; no own cleanup guard.
// R6GameService.dll @ 100407e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DisconnectPrimaryConnectionIfActive(void *owner)
{
  __asm {
    mov    al,BYTE PTR [ecx+0x148]
    test    al,al
    jne    Branch148
    xor    al,al
    ret
  Branch148:
    mov    ecx,DWORD PTR [ecx+0x150]
    call    R6GameServiceAddresses::ReleaseNestedTransportResource
    mov    al,0x1
    ret
  }
}

// Free CURRENT raw allocation at inherited frameEBP-10, including NULL; no destructor or publication rollback.
// R6GameService.dll @ 10066df0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl OpenPrimaryConnectionUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select single-state FuncInfo814bc/map814b4 for primary CConnection constructor allocation guard.
// R6GameService.dll @ 10066dfa : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectPrimaryConnectionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::OpenPrimaryConnectionExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// NULL nested connection+8 clears only incomingAL; otherwise call actual disconnect and normalize only AL.
// Preserve child upper EAX and normalize only AL; no own cleanup guard.
// R6GameService.dll @ 1004ed80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseNestedTransportResource(void *owner)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x8]
    test    ecx,ecx
    jne    Branch149
    xor    al,al
    ret
  Branch149:
    call    R6GameServiceAddresses::CConnectionCloseProvider
    test    al,al
    setne    al
    ret
  }
}

// Literal primary connection raw-allocation unwind map/FuncInfo.
// R6GameService.dll data @ 100814b4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry OpenPrimaryConnectionUnwindMap[1] = {
  {-1, R6GameServiceAddresses::OpenPrimaryConnectionUnwind1},
};

// Literal primary connection raw-allocation unwind map/FuncInfo.
// R6GameService.dll data @ 100814b4 : native storage identity retained.
const R6GameServiceNative::FuncInfo OpenPrimaryConnectionExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::OpenPrimaryConnectionUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Full enabled word represents the native ABI; original C++ scalar spelling remains unresolved.
// Guard initial transport8, build descriptor, normalize lowBYTE enabled word before three late string appends/one BYTE.
// Reload current transport; send66 through actual enabled-provider gate, ignore append/queue status, split clear/head.
// EntryS: descriptorS-24/listS-18/headS-14/flagS-28; clear rewrites arg4 as context,arg1 as head scratch. RET10.
// R6GameService.dll @ 1004eda0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSelector66StringTuple(
    void *owner,const char *firstText,const char *secondText,const char *thirdText,uint enabledWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTextSender66EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch150
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x10
  Branch150:
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x3
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x1c]
    push    eax
    mov    DWORD PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    mov    dl,BYTE PTR [esp+0x40]
    xor    ecx,ecx
    test    dl,dl
    mov    edx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [esp+0x2c],0x2
    setne    cl
    mov    DWORD PTR [esp+0x8],ecx
    push    edx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::AppendClDataListString
    mov    eax,DWORD PTR [esp+0x38]
    lea    ecx,[esp+0xc]
    push    eax
    call    R6GameServiceAddresses::AppendClDataListString
    mov    ecx,DWORD PTR [esp+0x3c]
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::AppendClDataListString
    lea    edx,[esp+0x8]
    push    0x1
    push    edx
    lea    ecx,[esp+0x14]
    call    R6GameServiceAddresses::AppendClDataListBinary
    mov    ecx,DWORD PTR [esi+0x8]
    lea    eax,[esp+0xc]
    push    eax
    push    0x1
    push    0x66
    call    R6GameServiceAddresses::SendConnectedTransportPayload
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x3
    mov    DWORD PTR [esp+0x40],ecx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x2c],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x34],edx
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x2c],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x1c]
    push    0x1
    push    eax
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x24]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x10
  }
}

// Guard transport8, construct descriptor/append text, then reload transport/send4d; ignore statuses.
// Split clear/head rewrites arg1 as list context and localS-28 as head scratch; preserve final free upperEAX/AL1. RET4.
// R6GameService.dll @ 1004eef0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSelector4dString(void *owner,const char *text)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTextSender4d13EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch151
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  Branch151:
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x3
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x1c]
    push    eax
    mov    DWORD PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [esp+0x2c],0x2
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::AppendClDataListString
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0xc]
    push    edx
    push    0x1
    push    0x4d
    call    R6GameServiceAddresses::SendTransportPayload
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    lea    eax,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x3
    mov    DWORD PTR [esp+0x34],eax
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x2c],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x2c],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edx,DWORD PTR [esp+0x1c]
    push    0x1
    push    edx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x24]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  }
}

// Guard transport8, construct empty descriptorS-24 and reload transport/send5d; ignore provider queue result.
// Split clear/head uses localS-2c context/localS-28 scratch; retain entered no-retry states/final free upperEAX.
// R6GameService.dll @ 1004f010 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendEmptySelector5d(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTextSender5dEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch152
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  Branch152:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x20]
    push    eax
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x30],0x2
    push    ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push    0x1
    push    0x5d
    call    R6GameServiceAddresses::SendTransportPayload
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x8],edx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0xc],eax
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    ecx,DWORD PTR [esp+0x20]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x28]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x28]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x30
    ret
  }
}

// Guard transport8, construct descriptor/append current text and reload transport/send13; ignore statuses.
// Shared4d/13 cleanup rewrites arg1 as list context/localS-28 scratch; return final free upperEAX/AL1. RET4.
// R6GameService.dll @ 1004f120 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendSelector13String(void *owner,const char *text)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTextSender4d13EH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    jne    Branch153
    xor    al,al
    pop    esi
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  Branch153:
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x3
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x1c]
    push    eax
    mov    DWORD PTR [esp+0x30],0x1
    call    R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ecx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [esp+0x2c],0x2
    push    ecx
    lea    ecx,[esp+0x10]
    call    R6GameServiceAddresses::AppendClDataListString
    mov    ecx,DWORD PTR [esi+0x8]
    lea    edx,[esp+0xc]
    push    edx
    push    0x1
    push    0x13
    call    R6GameServiceAddresses::SendTransportPayload
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::clDataListPTR_FUN
    lea    eax,[esp+0x18]
    mov    DWORD PTR [esp+0x2c],0x3
    mov    DWORD PTR [esp+0x34],eax
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x2c],0x4
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x8],ecx
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x2c],0x5
    call    R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    edx,DWORD PTR [esp+0x1c]
    push    0x1
    push    edx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    ecx,DWORD PTR [esp+0x24]
    mov    al,0x1
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x2c
    ret    0x4
  }
}

// Full enabled word represents the native ABI; original C++ scalar spelling remains unresolved.
// Cache exactly15/16/32 bytes at owner+4/+14/+25, retaining padding/truncation/gaps, then send ORIGINAL input pointers.
// Capture first before cache1; later pointers follow cache effects; enabled DWORD/current150 follow cache3. RET10.
// R6GameService.dll @ 10040800 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendStringTupleSelector66(
    void *owner,const char *firstText,const char *secondText,const char *thirdText,uint enabledWord)
{
  __asm {
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    push    edi
    mov    edi,DWORD PTR [esp+0x14]
    push    0xf
    lea    eax,[esi+0x4]
    push    edi
    push    eax
    call    R6GameServiceAddresses::strncpy
    mov    ebx,DWORD PTR [esp+0x24]
    push    0x10
    lea    ecx,[esi+0x14]
    push    ebx
    push    ecx
    call    R6GameServiceAddresses::strncpy
    mov    ebp,DWORD PTR [esp+0x34]
    push    0x20
    lea    edx,[esi+0x25]
    push    ebp
    push    edx
    call    R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esp+0x44]
    mov    ecx,DWORD PTR [esi+0x150]
    add    esp,0x24
    push    eax
    push    ebp
    push    ebx
    push    edi
    call    R6GameServiceAddresses::SendSelector66StringTuple
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x10
  }
}

// Cache16 bytes at owner+4, then send captured text pointer through current150; preserve full sender EAX. RET4.
// R6GameService.dll @ 10040860 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendStringSelector4d(void *owner,const char *text)
{
  __asm {
    push    esi
    mov    esi,ecx
    push    edi
    mov    edi,DWORD PTR [esp+0xc]
    push    0x10
    lea    eax,[esi+0x4]
    push    edi
    push    eax
    call    R6GameServiceAddresses::strncpy
    mov    ecx,DWORD PTR [esi+0x150]
    add    esp,0xc
    push    edi
    call    R6GameServiceAddresses::SendSelector4dString
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Tail-forward current service150 to empty5d sender, preserving raw result and original stack.
// R6GameService.dll @ 10040890 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardSelector5dToTransportSubobject(void *owner)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x150]
    jmp    R6GameServiceAddresses::SendEmptySelector5d
  }
}

// Tail-forward current service150 to13 sender, preserving text stack argument/raw result and target RET4.
// R6GameService.dll @ 100408a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSelector13ToTransportSubobject(void *owner,const char *text)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x150]
    jmp    R6GameServiceAddresses::SendSelector13String
  }
}

// Reset66 descriptor EBP-24 base after construction failure.
// R6GameService.dll @ 10068790 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass66 constructor cookie EBP-29 to genuine no-op59130; predecessor0 base reset.
// R6GameService.dll @ 10068798 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x29]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy66 completed descriptor EBP-24 fully; predecessor-1.
// R6GameService.dll @ 100687a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset66 EBP-24 base after entered pointer-list destruction; predecessor-1.
// R6GameService.dll @ 100687a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release66 head through CURRENT arg4 EBP+10 plus4/NULL, store arg1 EBP+4; predecessor3 base reset.
// R6GameService.dll @ 100687b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x10],0x0
    je    Branch154
    mov    eax,DWORD PTR [ebp+0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp+0x4],eax
    jmp    Branch155
  Branch154:
    mov    DWORD PTR [ebp+0x4],0x0
  Branch155:
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Pass66 CURRENT arg1 EBP+4 to genuine no-op59130 after entered node/head release; predecessor3.
// R6GameService.dll @ 100687d7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendSelector66StringTupleUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact66 six-state FuncInfo83160/map83130; full/base/entered/no-op identities remain distinct.
// R6GameService.dll @ 100687df : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTextSender66EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendSelector66StringTupleExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset4d13 descriptor EBP-24 base after construction failure.
// R6GameService.dll @ 100687f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass4d13 constructor cookie EBP-29 to genuine no-op59130; predecessor0 base reset.
// R6GameService.dll @ 100687f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind24(void)
{
  __asm {
    lea    ecx,[ebp-0x29]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy4d13 completed descriptor EBP-24 fully; predecessor-1.
// R6GameService.dll @ 10068800 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind34(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset4d13 EBP-24 base after entered pointer-list destruction; predecessor-1.
// R6GameService.dll @ 10068808 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind44(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release4d13 head through CURRENT arg1 EBP+4 plus4/NULL, store localEBP-28; predecessor3 base reset.
// R6GameService.dll @ 10068810 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind54(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je    Branch156
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch157
  Branch156:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch157:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Pass4d13 CURRENT localEBP-28 to genuine no-op59130 after entered node/head release; predecessor3.
// R6GameService.dll @ 10068837 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_supportSharedLifetimeUnwind64(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact4d13 six-state FuncInfo831ac/map8317c; full/base/entered/no-op identities remain distinct.
// R6GameService.dll @ 1006883f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTextSender4d13EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_record_supportSharedLifetimeExceptionInfo4
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset5d descriptor EBP-24 base after construction failure.
// R6GameService.dll @ 10068850 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Pass5d constructor cookie EBP-2d to genuine no-op59130; predecessor0 base reset.
// R6GameService.dll @ 10068858 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroy5d completed descriptor EBP-24 fully; predecessor-1.
// R6GameService.dll @ 10068860 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset5d EBP-24 base after entered pointer-list destruction; predecessor-1.
// R6GameService.dll @ 10068868 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release5d head through CURRENT localEBP-2c plus4/NULL, store localEBP-28; predecessor3 base reset.
// R6GameService.dll @ 10068870 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind5(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x2c],0x0
    je    Branch158
    mov    eax,DWORD PTR [ebp-0x2c]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x28],eax
    jmp    Branch159
  Branch158:
    mov    DWORD PTR [ebp-0x28],0x0
  Branch159:
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Pass5d CURRENT localEBP-28 to genuine no-op59130 after entered node/head release; predecessor3.
// R6GameService.dll @ 10068897 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendEmptySelector5dUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select exact5d six-state FuncInfo831f8/map831c8; full/base/entered/no-op identities remain distinct.
// R6GameService.dll @ 1006889f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTextSender5dEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendEmptySelector5dExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 10083130 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendSelector66StringTupleUnwindMap[6] = {
  {-1, R6GameServiceAddresses::SendSelector66StringTupleUnwind1},
  {0x0, R6GameServiceAddresses::SendSelector66StringTupleUnwind2},
  {-1, R6GameServiceAddresses::SendSelector66StringTupleUnwind3},
  {-1, R6GameServiceAddresses::SendSelector66StringTupleUnwind4},
  {0x3, R6GameServiceAddresses::SendSelector66StringTupleUnwind5},
  {0x3, R6GameServiceAddresses::SendSelector66StringTupleUnwind6},
};

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 10083160 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendSelector66StringTupleExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::SendSelector66StringTupleUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 1008317c : native storage identity retained.
const R6GameServiceNative::UnwindEntry transport_record_supportSharedLifetimeUnwindMap4[6] = {
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind14},
  {0x0, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind24},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind34},
  {-1, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind44},
  {0x3, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind54},
  {0x3, R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwind64},
};

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 100831ac : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_record_supportSharedLifetimeExceptionInfo4 = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::transport_record_supportSharedLifetimeUnwindMap4,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 100831c8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendEmptySelector5dUnwindMap[6] = {
  {-1, R6GameServiceAddresses::SendEmptySelector5dUnwind1},
  {0x0, R6GameServiceAddresses::SendEmptySelector5dUnwind2},
  {-1, R6GameServiceAddresses::SendEmptySelector5dUnwind3},
  {-1, R6GameServiceAddresses::SendEmptySelector5dUnwind4},
  {0x3, R6GameServiceAddresses::SendEmptySelector5dUnwind5},
  {0x3, R6GameServiceAddresses::SendEmptySelector5dUnwind6},
};

// Literal text sender unwind map/FuncInfo; shared4d/13 record represented once.
// R6GameService.dll data @ 100831f8 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendEmptySelector5dExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::SendEmptySelector5dUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Parses selector 0x66 and dispatches its two decoded values through handler vtable slot 2.
// Refresh/parse into retained full scratch words; on parser AL success dispatch CURRENT handler10 with both full words.
// Preserve partial/unwritten lanes and parser/callback upperEAX with normalized AL; no own EH or null guard.
// R6GameService.dll @ 1004f340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector66AndDispatchSlot08(void *owner)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::RefreshSelector66Values
    test   al,al
    je    Branch160
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x8]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch160:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Parses selector 0x4d and dispatches its two decoded values through handler vtable slot 3.
// Refresh/parse into retained full scratch words; on parser AL success dispatch CURRENT handler10 with both full words.
// Preserve partial/unwritten lanes and parser/callback upperEAX with normalized AL; no own EH or null guard.
// R6GameService.dll @ 1004f380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector4dAndDispatchSlot0c(void *owner)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::RefreshSelector4dValues
    test   al,al
    je    Branch161
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0xc]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch161:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Refresh/parse into retained full scratch words; on AL success invoke CURRENT handler10 slot18.
// Preserve partial/untouched output bytes, callback read order and raw upperEAX; no local EH.
// R6GameService.dll @ 1004f410 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector01AndDispatchSlot18(void *receiver)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::RefreshSelector01Values
    test   al,al
    je    Branch162
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x18]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch162:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Refresh/parse into retained full scratch words; on AL success invoke CURRENT handler10 slot1c.
// Preserve partial/untouched output bytes, callback read order and raw upperEAX; no local EH.
// R6GameService.dll @ 1004f450 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector62AndDispatchSlot1c(void *receiver)
{
  __asm {
    sub    esp,0x8
    lea    eax,[esp+0x0]
    push   esi
    mov    esi,ecx
    lea    ecx,[esp+0x8]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::RefreshSelector62Values
    test   al,al
    je    Branch163
    mov    eax,DWORD PTR [esp+0x4]
    mov    ecx,DWORD PTR [esi+0x10]
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x1c]
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret
  Branch163:
    xor    al,al
    pop    esi
    add    esp,0x8
    ret
  }
}

// Replace selectorFFFFFFFF, ignore its status, then call CURRENT handler10 slot14; force AL1, retaining upperEAX.
// R6GameService.dll @ 1004f4f0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceSelectionAndDispatchSlot14(void *receiver)
{
  __asm {
    push   esi
    push   0xffffffff
    mov    esi,ecx
    call   R6GameServiceAddresses::ReplaceRecordBySelector
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,DWORD PTR [ecx]
    call   DWORD PTR [eax+0x14]
    mov    al,0x1
    pop    esi
    ret
  }
}

// Refresh b5; exact item0 writes four bytes before CURRENT payload item1 lookup and live unbounded NUL copy.
// Preserve partial writes/raw failure EAX, late text argument and advanced-source upper EAX/AL1; RET8.
// R6GameService.dll @ 1004f9d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelectorB5RecordIntoOutputs(void *owner,void *fourBytesOut,char *textOut)
{
  __asm {
    push    ecx
    push    esi
    push    0xb5
    mov    esi,ecx
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    jne    Branch164
    xor    al,al
    pop    esi
    pop    ecx
    ret    0x8
  Branch164:
    cmp    BYTE PTR [eax+0x4],0xb5
    je    Branch165
    xor    al,al
    pop    esi
    pop    ecx
    ret    0x8
  Branch165:
    mov    ecx,DWORD PTR [esp+0xc]
    push    0x0
    push    0x4
    push    ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch166
    pop    esi
    pop    ecx
    ret    0x8
  Branch166:
    mov    eax,DWORD PTR [esi+0x4]
    lea    edx,[esp+0x4]
    push    0x1
    push    edx
    mov    ecx,DWORD PTR [eax+0x8]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch167
    pop    esi
    pop    ecx
    ret    0x8
  Branch167:
    mov    ecx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [ecx+0xc]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    al,0x1
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Parse into incoming wordS-408/textS-404, then pass full word and text address to CURRENT callback slot10.
// Text stack region is1028 bytes, with no native copy bound; preserve raw failure/callback upper EAX and AL.
// R6GameService.dll @ 1004f3c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelectorB5AndDispatchSlot10(void *owner)
{
  __asm {
    sub    esp,0x408
    lea    eax,[esp+0x4]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelectorB5RecordIntoOutputs
    test    al,al
    je    Branch168
    mov    ecx,DWORD PTR [esi+0x10]
    lea    eax,[esp+0x8]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    call    DWORD PTR [edx+0x10]
    mov    al,0x1
    pop    esi
    add    esp,0x408
    ret
  Branch168:
    xor    al,al
    pop    esi
    add    esp,0x408
    ret
  }
}

// Construct descriptor before refresh5d/optional-word parse; captured marker27 skips extra fields.
// Else copy CURRENT payload list1, copy borrowed item0 through NUL, then exact DWORD item1; retain partial writes.
// Entry S: descriptorS-24/listS-18/headS-14/stateS-4. Success reuses arg4S+10 as cleanup context; RET10.
// R6GameService.dll @ 1004f750 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector5dRecordIntoOutputs(
    void *owner,char *markerOut,char *textOut,void *valueOut,void *optionalWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport5dFieldEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    xor    eax,eax
    push    ebx
    push    esi
    mov    DWORD PTR [esp+0x8],eax
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    eax
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],ebx
    push    0x5d
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x44]
    mov    edi,DWORD PTR [esp+0x38]
    push    eax
    push    edi
    push    0x5d
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    jne    Branch169
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch169:
    cmp    BYTE PTR [edi],0x27
    jne    Branch170
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    jmp    Branch174
  Branch170:
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch171
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x4
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch171:
    lea    eax,[esp+0xc]
    push    0x0
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::GetIndexedTypeOnePayload
    test    al,al
    jne    Branch172
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch172:
    mov    ecx,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [ecx+0xc]
    mov    ecx,esi
    push    eax
    push    edx
    call    R6GameServiceAddresses::CopyTerminatedBytesForward
    mov    eax,DWORD PTR [esp+0x40]
    push    0x1
    push    0x4
    push    eax
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    mov    DWORD PTR [esp+0x10],ebx
    jne    Branch173
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch173:
    mov    ebx,0x7
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x44],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x30],0x8
    call    R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x30],bl
    call    R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch174:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  }
}

// Parse into incoming markerS-8c/textS-84/valueS-90/optionalS-88; CURRENT callback slot4 gets full words.
// Quote path leaves text/value incoming; preserve cleanup/callback upper EAX with AL-only status.
// R6GameService.dll @ 1004f2e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector5dAndDispatchSlot04(void *owner)
{
  __asm {
    sub    esp,0x90
    lea    eax,[esp+0x8]
    lea    edx,[esp+0xc]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0x4]
    push    eax
    push    ecx
    lea    eax,[esp+0x10]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector5dRecordIntoOutputs
    test    al,al
    je    Branch175
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x18]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    call    DWORD PTR [edx+0x4]
    mov    al,0x1
    pop    esi
    add    esp,0x90
    ret
  Branch175:
    xor    al,al
    pop    esi
    add    esp,0x90
    ret
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 100688e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 100688e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 100688f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 100688f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 10068900 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 10068908 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 10068910 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 10068918 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset inherited descriptor or release head through CURRENT fourth argument, retaining NULL/context scratch.
// R6GameService.dll @ 10068920 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector5dRecordIntoOutputsUnwind9(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x10],0x0
    je    Branch176
    mov    eax,DWORD PTR [ebp+0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch177
  Branch176:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch177:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact nine-state field-parser cleanup FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10068947 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport5dFieldEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal nine-state cleanup map/FuncInfo; entered pointer-list cleanup is not retried.
// R6GameService.dll data @ 1008329c : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector5dRecordIntoOutputsUnwindMap[9] = {
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind2},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind3},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind4},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind5},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind6},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind7},
  {-1, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind8},
  {0x7, R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwind9},
};

// Literal nine-state cleanup map/FuncInfo; entered pointer-list cleanup is not retried.
// R6GameService.dll data @ 100832e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector5dRecordIntoOutputsExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::ParseSelector5dRecordIntoOutputsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Construct descriptor before refreshde; missing cache fails before optional-word parse.
// Reload marker argument after parsing; current BYTE27 skips text, otherwise copy current payload list1/text0/text1.
// Each text reader gets513 bytes; retain staged/partial writes and distinct entered cleanup states2..8. RET10.
// R6GameService.dll @ 1004fab0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelectorDETextFields(
    void *owner,char *markerOut,char *text0Out,char *text1Out,void *optionalWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransportDEFieldEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push    ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0xc],0x0
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x0
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    push    0xde
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esi+0x4]
    test    eax,eax
    jne    Branch178
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x2
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch178:
    mov    eax,DWORD PTR [esp+0x44]
    mov    ecx,DWORD PTR [esp+0x38]
    push    eax
    push    ecx
    push    0xde
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    jne    Branch179
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x3
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch179:
    mov    edx,DWORD PTR [esp+0x38]
    cmp    BYTE PTR [edx],0x27
    jne    Branch180
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x30],0x4
    jmp    Branch184
  Branch180:
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    mov    ecx,DWORD PTR [ecx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    jne    Branch181
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x5
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch181:
    mov    edx,DWORD PTR [esp+0x3c]
    push    0x201
    push    0x0
    push    edx
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    jne    Branch182
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x6
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch182:
    mov    eax,DWORD PTR [esp+0x40]
    push    0x201
    push    0x1
    push    eax
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    test    al,al
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x10],ebx
    jne    Branch183
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  Branch183:
    mov    DWORD PTR [esp+0x30],0x8
  Branch184:
    lea    ecx,[esp+0x1c]
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret    0x10
  }
}

// Parse into incoming markerS-410/optionalS-40c/text0S-204/text1S-408, then invoke CURRENT callback slot20.
// Each physical text region516 bytes; full incoming/partially written scalar words and raw upper EAX survive.
// R6GameService.dll @ 1004f490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelectorDEAndDispatchSlot20(void *owner)
{
  __asm {
    sub    esp,0x410
    lea    eax,[esp+0x4]
    lea    edx,[esp+0x20c]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0xc]
    push    eax
    push    ecx
    lea    eax,[esp+0xc]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelectorDETextFields
    test    al,al
    je    Branch185
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esi+0x10]
    push    eax
    lea    eax,[esp+0x10]
    mov    edx,DWORD PTR [ecx]
    push    eax
    lea    eax,[esp+0x218]
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    eax
    call    DWORD PTR [edx+0x20]
    mov    al,0x1
    pop    esi
    add    esp,0x410
    ret
  Branch185:
    xor    al,al
    pop    esi
    add    esp,0x410
    ret
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068960 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068968 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068970 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068978 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068980 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068988 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 10068998 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy full inherited descriptor at EBP-24 or reset its base after entered pointer-list cleanup.
// R6GameService.dll @ 100689a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelectorDETextFieldsUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact nine-state field-parser cleanup FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 100689a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportDEFieldEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelectorDETextFieldsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal nine-state cleanup map/FuncInfo; entered pointer-list cleanup is not retried.
// R6GameService.dll data @ 10083300 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelectorDETextFieldsUnwindMap[9] = {
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind1},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind2},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind3},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind4},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind5},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind6},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind7},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind8},
  {-1, R6GameServiceAddresses::ParseSelectorDETextFieldsUnwind9},
};

// Literal nine-state cleanup map/FuncInfo; entered pointer-list cleanup is not retried.
// R6GameService.dll data @ 10083348 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelectorDETextFieldsExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::ParseSelectorDETextFieldsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Construct list and unused binary temporary before refresh13/optional-word parse; captured marker27 skips strings.
// Copy CURRENT payload list1; indexed strings0..6 target fields5/0/1/2/3/4/6 through late arguments.
// Entry S: list descriptorS-40/binaryS-28/stateS-4; preserve destructor entries/raw cleanup upper EAX. RET24.
// R6GameService.dll @ 1004f510 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector13RecordIntoOutputs(
    void *owner,char *markerOut,char *field0,char *field1,char *field2,char *field3,
    char *field4,char *field5,char *field6,void *optionalWordOut)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransport13FieldEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    mov    esi,ecx
    push    edi
    push    0x3
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x50],edi
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    ebx,0x1
    push    edi
    push    0x2
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x54],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataBinBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    edi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x50],0x2
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataBinPTR_FUN
    push    0x13
    mov    ecx,esi
    mov    BYTE PTR [esp+0x50],0x3
    call    R6GameServiceAddresses::ReplaceRecordBySelector
    mov    eax,DWORD PTR [esp+0x74]
    mov    edi,DWORD PTR [esp+0x54]
    push    eax
    push    edi
    push    0x13
    mov    ecx,esi
    call    R6GameServiceAddresses::ValidateParserSelectorAndOptionalWord
    test    al,al
    jne    Branch187
  Branch186:
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataBin
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x24
  Branch187:
    cmp    BYTE PTR [edi],0x27
    jne    Branch188
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x4c],bl
    call    R6GameServiceAddresses::DestroyClDataBin
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataList
    jmp    Branch192
  Branch188:
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esp+0x10]
    push    ebx
    push    ecx
    mov    ecx,DWORD PTR [edx+0x8]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch186
    mov    eax,DWORD PTR [esp+0x6c]
    push    0x0
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch186
    mov    ecx,DWORD PTR [esp+0x58]
    push    ebx
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch186
    mov    edx,DWORD PTR [esp+0x5c]
    push    0x2
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch186
    mov    eax,DWORD PTR [esp+0x60]
    push    0x3
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch186
    mov    ecx,DWORD PTR [esp+0x64]
    push    0x4
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    je    Branch186
    mov    edx,DWORD PTR [esp+0x68]
    push    0x5
    push    edx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    jne    Branch189
    mov    BYTE PTR [esp+0x4c],bl
    lea    ecx,[esp+0x28]
    jmp    Branch190
  Branch189:
    mov    eax,DWORD PTR [esp+0x70]
    push    0x6
    push    eax
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyIndexedClDataString
    test    al,al
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x4c],bl
    jne    Branch191
  Branch190:
    call    R6GameServiceAddresses::DestroyClDataBinAlias
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataListAlias
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x38]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x24
  Branch191:
    call    R6GameServiceAddresses::DestroyClDataBinAlias
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataListAlias
  Branch192:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    mov    al,bl
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x24
  }
}

// Forward full incoming markerS-1b8/optionalS-1b4 and seven text addresses through CURRENT callback slot0.
// Text fields0..6 startS-1a4/-170/-194/-14c/-84/-1b0/-108; no initialization or copy bounds are added.
// R6GameService.dll @ 1004f240 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseSelector13AndDispatchSlot00(void *owner)
{
  __asm {
    sub    esp,0x1b8
    lea    eax,[esp+0x4]
    lea    edx,[esp+0x8]
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0xb4]
    push    eax
    push    ecx
    lea    eax,[esp+0x140]
    push    edx
    lea    ecx,[esp+0x7c]
    push    eax
    lea    edx,[esp+0x38]
    push    ecx
    lea    eax,[esp+0x60]
    push    edx
    lea    ecx,[esp+0x30]
    push    eax
    lea    edx,[esp+0x20]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ParseSelector13RecordIntoOutputs
    test    al,al
    je    Branch193
    mov    edx,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esi+0x10]
    push    edx
    lea    edx,[esp+0xb8]
    push    edx
    lea    edx,[esp+0x14]
    push    edx
    lea    edx,[esp+0x144]
    push    edx
    lea    edx,[esp+0x80]
    push    edx
    lea    edx,[esp+0x3c]
    mov    eax,DWORD PTR [ecx]
    push    edx
    lea    edx,[esp+0x64]
    push    edx
    lea    edx,[esp+0x34]
    push    edx
    mov    edx,DWORD PTR [esp+0x24]
    push    edx
    call    DWORD PTR [eax]
    mov    al,0x1
    pop    esi
    add    esp,0x1b8
    ret
  Branch193:
    xor    al,al
    pop    esi
    add    esp,0x1b8
    ret
  }
}

// Reset or destroy inherited list/binary storage at its exact parent-frame offset.
// R6GameService.dll @ 100688b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector13RecordIntoOutputsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset or destroy inherited list/binary storage at its exact parent-frame offset.
// R6GameService.dll @ 100688b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector13RecordIntoOutputsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset or destroy inherited list/binary storage at its exact parent-frame offset.
// R6GameService.dll @ 100688c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector13RecordIntoOutputsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset or destroy inherited list/binary storage at its exact parent-frame offset.
// R6GameService.dll @ 100688c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ParseSelector13RecordIntoOutputsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Select exact four-state list/binary field-parser FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 100688d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransport13FieldEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseSelector13RecordIntoOutputsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal four-state cleanup map/FuncInfo; binary states inherit full list state1.
// R6GameService.dll data @ 10083260 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseSelector13RecordIntoOutputsUnwindMap[4] = {
  {-1, R6GameServiceAddresses::ParseSelector13RecordIntoOutputsUnwind1},
  {-1, R6GameServiceAddresses::ParseSelector13RecordIntoOutputsUnwind2},
  {0x1, R6GameServiceAddresses::ParseSelector13RecordIntoOutputsUnwind3},
  {0x1, R6GameServiceAddresses::ParseSelector13RecordIntoOutputsUnwind4},
};

// Literal four-state cleanup map/FuncInfo; binary states inherit full list state1.
// R6GameService.dll data @ 10083280 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseSelector13RecordIntoOutputsExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ParseSelector13RecordIntoOutputsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Install optional prefix table and embedded tree; allocate/init state block, then publish flags and original owner.
// Preserve full mode/lowBYTE tree tag, six-state cleanup, current contexts/caller allocation slot and untouched bytes.
// R6GameService.dll @ 10042ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructServiceProtocolDispatcher(void *owner,uint initializeMode)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDispatcherConstructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push    ebx
    xor    eax,eax
    push    ebp
    mov    ebp,ecx
    mov    DWORD PTR [esp+0x8],eax
    mov    ecx,DWORD PTR [esp+0x24]
    xor    ebx,ebx
    mov    DWORD PTR [esp+0xc],ebp
    cmp    ecx,ebx
    je    Branch194
    mov    DWORD PTR [ebp+0x0],0x10077df4
    mov    eax,0x1
  Branch194:
    push    esi
    lea    esi,[ebp+0x24]
    or    al,0x2
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esi+0xc],0x10077dec
    mov    DWORD PTR [esp+0xc],eax
    lea    eax,[esp+0x28]
    push    ebx
    push    eax
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x2
    call    R6GameServiceAddresses::StoreFirstWordIgnoringContext
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi],eax
    mov    cl,BYTE PTR [esp+0x28]
    mov    BYTE PTR [esp+0x20],0x3
    mov    BYTE PTR [esi+0x8],cl
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],ebx
    call    R6GameServiceAddresses::InitializeServiceTreeHeader
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x20],0x4
    cmp    eax,ebx
    je    Branch197
    mov    edx,DWORD PTR [esi]
    push    edi
    mov    edi,DWORD PTR [edx+0x4]
    cmp    edi,ebx
    je    Branch196
  Branch195:
    mov    eax,DWORD PTR [edi+0xc]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::FreeNestedListNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push    0x0
    lea    ecx,[edi+0x10]
    call    R6GameServiceAddresses::ReleaseHeapByteStringAndMaybeOwner
    push    0x1
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test    ebx,ebx
    mov    edi,ebx
    jne    Branch195
  Branch196:
    mov    eax,DWORD PTR [esi]
    pop    edi
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0x4],ebx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],ebx
  Branch197:
    push    0xc0
    mov    DWORD PTR [ebp+0x8],ebx
    mov    DWORD PTR [ebp+0xc],ebx
    mov    DWORD PTR [ebp+0x10],ebx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x28],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x20],0x5
    pop    esi
    je    Branch198
    push    0x1
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializeServiceStateBlock
    jmp    Branch199
  Branch198:
    xor    eax,eax
  Branch199:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebp+0x14],eax
    mov    BYTE PTR [ebp+0x18],0x0
    mov    BYTE PTR [ebp+0x19],0x0
    mov    BYTE PTR [ebp+0x1a],0x1
    mov    WORD PTR [ebp+0x1c],bx
    mov    eax,ebp
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret    0x4
  }
}

// R6GameService.dll @ 10043010 : tail-jump to the shared dispatcher-tree cleanup body at 0x10043020.
__declspec(naked) uint __fastcall ClearProtocolDispatcherTreeThunk(void *treeOwner)
{
  __asm {
    jmp R6GameServiceAddresses::ClearProtocolDispatcherTree
  }
}

// Nonzero count drains right subtrees then cached left chain, releasing each string/node before CURRENT head reset.
// Count0 skips live links; always free CURRENT head under armed state0, with current-head-only unwind. Raw EAX.
// R6GameService.dll @ 10043020 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearProtocolDispatcherTree(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDispatcherTreeEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x4],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x10],0x0
    test    eax,eax
    je    Branch202
    mov    eax,DWORD PTR [edi]
    push    esi
    mov    esi,DWORD PTR [eax+0x4]
    test    esi,esi
    je    Branch201
    push    ebx
  Branch200:
    mov    ecx,DWORD PTR [esi+0xc]
    push    ecx
    mov    ecx,edi
    call    R6GameServiceAddresses::FreeNestedListNodes
    mov    ebx,DWORD PTR [esi+0x8]
    push    0x0
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::ReleaseHeapByteStringAndMaybeOwner
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    esi,ebx
    jne    Branch200
    pop    ebx
  Branch201:
    mov    eax,DWORD PTR [edi]
    pop    esi
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],0x0
  Branch202:
    mov    eax,DWORD PTR [edi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x8]
    pop    edi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Release captured queue record, CURRENT callback and conditionally adjusted state; clear fields only after return.
// State0 owns full embedded tree, state1 only its CURRENT head; retain raw EAX and saved-context/count-read gap.
// The saved context changes to owner+24 before count read/state1, so a fault there applies state0 to owner+48.
// R6GameService.dll @ 100430b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceProtocolDispatcher(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDispatcherDestructionEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebx
    push    esi
    mov    esi,ecx
    push    edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x8]
    xor    ebx,ebx
    cmp    edi,ebx
    mov    DWORD PTR [esp+0x18],ebx
    je    Branch203
    mov    ecx,edi
    call    R6GameServiceAddresses::DeleteOwnedObjectAtOffset8
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x8],ebx
  Branch203:
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    ecx,ebx
    je    Branch204
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
    mov    DWORD PTR [esi+0x10],ebx
  Branch204:
    cmp    BYTE PTR [esi+0x18],bl
    jne    Branch206
    mov    eax,DWORD PTR [esi+0x14]
    cmp    eax,ebx
    je    Branch205
    mov    ecx,DWORD PTR [eax+0x4]
    push    0x1
    mov    edx,DWORD PTR [ecx+0x8]
    lea    ecx,[edx+eax*1+0x4]
    mov    eax,DWORD PTR [edx+eax*1+0x4]
    call    DWORD PTR [eax]
  Branch205:
    mov    DWORD PTR [esi+0x14],ebx
  Branch206:
    lea    edi,[esi+0x24]
    mov    DWORD PTR [esp+0xc],edi
    mov    eax,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esp+0x18],0x1
    cmp    eax,ebx
    je    Branch209
    mov    ecx,DWORD PTR [edi]
    mov    esi,DWORD PTR [ecx+0x4]
    cmp    esi,ebx
    je    Branch208
    push    ebp
  Branch207:
    mov    edx,DWORD PTR [esi+0xc]
    mov    ecx,edi
    push    edx
    call    R6GameServiceAddresses::FreeNestedListNodes
    mov    ebp,DWORD PTR [esi+0x8]
    push    ebx
    lea    ecx,[esi+0x10]
    call    R6GameServiceAddresses::ReleaseHeapByteStringAndMaybeOwner
    push    0x1
    push    esi
    mov    ecx,edi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    ebp,ebx
    mov    esi,ebp
    jne    Branch207
    pop    ebp
  Branch208:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],ebx
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],ebx
  Branch209:
    mov    ecx,DWORD PTR [edi]
    push    ecx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// R6GameService.dll @ 100431a0
// Services pending records on the owned queue and returns the callee's AL truth value.
bool __fastcall ServicePendingRecordsForDispatcher(void *dispatcher)
{
  void *queueOwner = *(void **)((byte *)dispatcher + 0x10);
  if (queueOwner == nullptr) {
    return false;
  }
  return (byte)ServicePendingRecordsAndExpireIdleKeys(queueOwner) != 0;
}

// R6GameService.dll @ 100431c0
// Builds a record from the owned queue head or fallback, returning null when no queue owner exists.
void * __fastcall BuildNextDispatcherRecord(void *dispatcher)
{
  void *queueOwner = *(void **)((byte *)dispatcher + 0x10);
  if (queueOwner == nullptr) {
    return nullptr;
  }
  return BuildRecordFromQueueHeadOrFallback(queueOwner);
}

// Require captured transport/first text; existing record returns raw pointer upper24 with AL1. RET14.
// Otherwise reuse transport argS+4 for raw allocation, construct/publish record, then copy16/129/129 bytes.
// Later destinations/text/context reload; captured transport/first text persist. State0 stays armed after publication.
// R6GameService.dll @ 10043de0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InitializeTransportRecordIfAbsent(void *owner,void *transport,void *requestContext,
    char *textAtBcSource,char *textAtCcSource,char *textAt14dSource)
{
  __asm {
    mov    eax,fs:0x0
    push    0xffffffff
    push    R6GameServiceAddresses::SelectTransportRecordConstructionEH
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ebx
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    test    edi,edi
    je    Branch213
    mov    ebx,DWORD PTR [esp+0x24]
    test    ebx,ebx
    je    Branch213
    mov    eax,DWORD PTR [esi+0x10]
    test    eax,eax
    je    Branch210
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x14
  Branch210:
    push    0x1dc
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x1c],eax
    test    eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je    Branch211
    push    0x1
    push    edi
    mov    ecx,eax
    call    R6GameServiceAddresses::CLobbySrvConnectionListConstruct
    jmp    Branch212
  Branch211:
    xor    eax,eax
  Branch212:
    mov    DWORD PTR [esi+0x10],eax
    push    0x10
    add    eax,0xbc
    push    ebx
    push    eax
    call    R6GameServiceAddresses::strncpy
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,DWORD PTR [esp+0x34]
    push    0x81
    add    ecx,0xcc
    push    eax
    push    ecx
    call    R6GameServiceAddresses::strncpy
    mov    eax,DWORD PTR [esi+0x10]
    mov    edx,DWORD PTR [esp+0x44]
    push    0x81
    add    eax,0x14d
    push    edx
    push    eax
    call    R6GameServiceAddresses::strncpy
    mov    ecx,DWORD PTR [esp+0x44]
    add    esp,0x24
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esi+0x20],ecx
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x14
  Branch213:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    xor    al,al
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0xc
    ret    0x14
  }
}

// Delete1 current record, clear only after return, then clear c/20 and force AL1; no own EH.
// R6GameService.dll @ 10043ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetTransportRecordState(void *recordOwner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi+0x10]
    test   ecx,ecx
    je    Branch214
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [esi+0x10],0x0
  Branch214:
    mov    DWORD PTR [esi+0xc],0x0
    mov    DWORD PTR [esi+0x20],0x0
    mov    al,0x1
    pop    esi
    ret
  }
}

// Construct before owner gate, refresh13, copy item1/read item0 and remove through CURRENT owner10.
// Preserve retained key, raw AL gates, table-store order and distinct entered-destruction states2..7.
// R6GameService.dll @ 10043f10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall HandleSelector13RecordRemoval(void *dispatcherState)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSelector13RemovalEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push   ebx
    push   esi
    mov    DWORD PTR [esp+0x8],0x0
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x34],0x0
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x30],0x1
    test   eax,eax
    jne    Branch215
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x30],0x2
    jmp    Branch220
  Branch215:
    push   0x13
    mov    ecx,esi
    call   R6GameServiceAddresses::ReplaceCachedRecordBySelector
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    jne    Branch216
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x30],0x3
    jmp    Branch220
  Branch216:
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    mov    ecx,DWORD PTR [eax+0x8]
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    jne    Branch217
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x30],0x4
    jmp    Branch220
  Branch217:
    lea    edx,[esp+0xc]
    push   0x0
    push   edx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::ReadIndexedInt32
    test   al,al
    jne    Branch218
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x30],0x5
    jmp    Branch220
  Branch218:
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    push   eax
    call   R6GameServiceAddresses::RemoveIndexedRecordAndQueueNotifications
    test   al,al
    mov    DWORD PTR [esp+0x1c],edi
    mov    DWORD PTR [esp+0x10],ebx
    je    Branch219
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x30],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret
  Branch219:
    mov    DWORD PTR [esp+0x30],0x7
  Branch220:
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x28
    ret
  }
}

// Build two descriptors before scanning captured text, optionally update names, then store late WORD/BYTE fields.
// Reuse byte argument for21; send through CURRENT c, ignore append statuses and retain distinct cleanup routes.
// R6GameService.dll @ 10044080 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SendTransportRequestPayload(
    void *transportState,char *requestText,uint byteFieldValue,uint wordValue)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectTransportRequestEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    eax,eax
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    ebx,0x3
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],edi
    mov    DWORD PTR [esp+0x34],ebx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],ebp
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x50],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],ebp
    mov    BYTE PTR [esp+0x4c],bl
    mov    ebx,DWORD PTR [esp+0x54]
    mov    edi,ebx
    or     ecx,0xffffffff
    xor    eax,eax
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    je    Branch221
    push   ebx
    mov    ecx,esi
    call   R6GameServiceAddresses::ReplaceServiceTreeNamesFromDelimitedText
  Branch221:
    mov    cx,WORD PTR [esp+0x5c]
    mov    al,BYTE PTR [esp+0x58]
    mov    WORD PTR [esi+0x1c],cx
    push   ebx
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esi+0x1a],al
    call   R6GameServiceAddresses::AppendClDataListString
    lea    edx,[esp+0x58]
    lea    ecx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x5c],0x15
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x2c]
    lea    ecx,[esp+0x14]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    ecx,[esp+0x14]
    push   ecx
    mov    ecx,DWORD PTR [esi+0xc]
    push   0x1
    push   0xd1
    call   R6GameServiceAddresses::SendTransportPayload
    test   al,al
    mov    DWORD PTR [esp+0x20],ebp
    je    Branch222
    mov    esi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],esi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],esi
    mov    DWORD PTR [esp+0x38],ebp
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],0x5
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    al,0x1
    jmp    Branch223
  Branch222:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x4c],0xffffffff
    call   R6GameServiceAddresses::DestroyClDataList
    xor    al,al
  Branch223:
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Read current owner10; missing preserves entry upperEAX/AL0, otherwise process and force AL1; no own EH.
// R6GameService.dll @ 10044220 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessTransportRecordsIfPresent(void *dispatcherState)
{
  __asm {
    mov    ecx,DWORD PTR [ecx+0x10]
    test   ecx,ecx
    jne    Branch224
    xor    al,al
    ret
  Branch224:
    call   R6GameServiceAddresses::ProcessIndexedRecordsInKeyOrder
    mov    al,0x1
    ret
  }
}

// Build decimal/text/decimal/lowBYTE-flag/text, ignoring append statuses, then clone and dispatch to CURRENT owner10.
// Flag caller slot becomes clone destination then cleanup context; preserve entered clear/head-only states and raw AL.
// R6GameService.dll @ 10044240 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall transport_record_support_DispatchRequest18ByKey(void *dispatcherState,uint value,int key,
    char *primaryText,uint flagWord,char *trailingText,uint trailingValue)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectRequest18EH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push   esi
    mov    esi,ecx
    xor    eax,eax
    mov    ecx,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esp+0x4],eax
    cmp    ecx,eax
    je    Branch226
    mov    DWORD PTR [esp+0xc],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x10],0x3
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x2c],eax
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x8]
    push   eax
    mov    DWORD PTR [esp+0x2c],0x1
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,DWORD PTR [esp+0x38]
    push   ecx
    lea    ecx,[esp+0xc]
    call   R6GameServiceAddresses::AppendClDataListString
    lea    edx,[esp+0x44]
    lea    ecx,[esp+0x8]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    cl,BYTE PTR [esp+0x3c]
    xor    eax,eax
    test   cl,cl
    lea    ecx,[esp+0x3c]
    setne  al
    push   ecx
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x40],eax
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    edx,DWORD PTR [esp+0x40]
    lea    ecx,[esp+0x8]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListString
    sub    esp,0x18
    lea    eax,[esp+0x20]
    mov    ecx,esp
    mov    DWORD PTR [esp+0x54],esp
    push   0x1
    push   eax
    call   R6GameServiceAddresses::CopyConstructClDataList
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    edx,DWORD PTR [esp+0x48]
    push   0x2
    push   0x18
    push   ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push   edx
    call   R6GameServiceAddresses::ApplyIndexedKeyUpdate
    test   al,al
    mov    DWORD PTR [esp+0x8],R6GameServiceAddresses::clDataListPTR_FUN
    je    Branch225
    lea    eax,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x2
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x3
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x18
  Branch225:
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0x4
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x28],0x5
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x4
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch226:
    mov    ecx,DWORD PTR [esp+0x20]
    xor    al,al
    mov    DWORD PTR fs:0x0,ecx
    pop    esi
    add    esp,0x28
    ret    0x18
  }
}

// Test construction bit1; if set pass CURRENT saved owner+34 to the genuine no-op, retaining raw registers.
// R6GameService.dll @ 100671e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test    eax,eax
    je    Branch227
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x34
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch227:
    ret
  }
}

// Test construction bit2; if set pass CURRENT saved tree context+10 to the genuine no-op.
// R6GameService.dll @ 100671fa : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x2
    test    eax,eax
    je    Branch228
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch228:
    ret
  }
}

// Pass the address of the reused caller argument at parentS+4 to the genuine no-op.
// R6GameService.dll @ 10067214 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind3(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Free first word through CURRENT saved tree context under partially constructed state3.
// R6GameService.dll @ 1006721c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Destroy full embedded tree at CURRENT saved owner+24 under state4, without retrying state allocation.
// R6GameService.dll @ 10067224 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x24
    jmp    R6GameServiceAddresses::ClearProtocolDispatcherTreeThunk
  }
}

// Free CURRENT allocation in reused callerS+4 before continuing to full embedded-tree cleanup.
// R6GameService.dll @ 1006722f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructServiceProtocolDispatcherUnwind6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Free CURRENT raw allocation in reused callerS+4, without destroying record children or clearing published slot.
// R6GameService.dll @ 10067470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordIfAbsentUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x4]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 10067490 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 state1 destroys CURRENT descriptor at inherited EBP-24.
// R6GameService.dll @ 10067498 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Selector13 base/entered cleanup resets only descriptor table at inherited EBP-24.
// R6GameService.dll @ 100674c8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl HandleSelector13RecordRemovalUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact nine-state selector13 FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 100674d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSelector13RemovalEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HandleSelector13RecordRemovalExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Request sender inherited cleanup: base-only reset at EBP-24.
// R6GameService.dll @ 100674e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Request sender inherited cleanup: full descriptor at EBP-24.
// R6GameService.dll @ 100674e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Request sender inherited cleanup: base-only reset at EBP-3c.
// R6GameService.dll @ 100674f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Request sender inherited cleanup: full descriptor at EBP-3c.
// R6GameService.dll @ 100674f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Request sender inherited cleanup: base-only reset at EBP-3c.
// R6GameService.dll @ 10067500 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Request sender inherited cleanup: base-only reset at EBP-24.
// R6GameService.dll @ 10067508 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Request sender inherited cleanup: base-only reset at EBP-3c.
// R6GameService.dll @ 10067510 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SendTransportRequestPayloadUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact eight-state two-descriptor request FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 10067518 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportRequestEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendTransportRequestPayloadExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reset base descriptor at inherited EBP-24 during construction failure.
// R6GameService.dll @ 10067530 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy CURRENT full descriptor at inherited EBP-24 before entered normal destruction.
// R6GameService.dll @ 10067538 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base descriptor at inherited EBP-24 after successful entered clear/head release.
// R6GameService.dll @ 10067540 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten flag argument twice; pass pointer+4 or explicit null to head-only cleanup; scratch EBP-3c.
// R6GameService.dll @ 10067548 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x10],0x0
    je    Branch229
    mov    eax,DWORD PTR [ebp+0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x3c],eax
    jmp    Branch230
  Branch229:
    mov    DWORD PTR [ebp-0x3c],0x0
  Branch230:
    mov    ecx,DWORD PTR [ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset base descriptor at inherited EBP-24 after failed-result entered clear/head release.
// R6GameService.dll @ 1006756f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Read CURRENT rewritten flag argument twice; pass pointer+4 or explicit null to head-only cleanup; scratch EBP-44.
// R6GameService.dll @ 10067577 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl transport_record_support_DispatchRequest18ByKeyUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x10],0x0
    je    Branch231
    mov    eax,DWORD PTR [ebp+0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x44],eax
    jmp    Branch232
  Branch231:
    mov    DWORD PTR [ebp-0x44],0x0
  Branch232:
    mov    ecx,DWORD PTR [ebp-0x44]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select exact eight-state keyed-request FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 1006759e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRequest18EH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Free the first word through CURRENT saved tree owner; do not repeat node/string destruction.
// R6GameService.dll @ 10067250 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ClearProtocolDispatcherTreeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Destroy tree at CURRENT saved dispatcher+24 through its canonical tail alias.
// R6GameService.dll @ 10067270 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceProtocolDispatcherUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x24
    jmp    R6GameServiceAddresses::ClearProtocolDispatcherTreeThunk
  }
}

// Free the first word through CURRENT saved embedded-tree context after entering inline destruction.
// R6GameService.dll @ 1006727b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceProtocolDispatcherUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select the exact single-state dispatcher tree lifetime map and tail CRT dispatch.
// R6GameService.dll @ 10067258 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDispatcherTreeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClearProtocolDispatcherTreeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the exact two-state dispatcher destruction map and tail CRT dispatch.
// R6GameService.dll @ 10067283 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDispatcherDestructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceProtocolDispatcherExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal dispatcher tree/destruction cleanup record.
// R6GameService.dll data @ 1008192c : native storage identity retained.
const R6GameServiceNative::UnwindEntry ClearProtocolDispatcherTreeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ClearProtocolDispatcherTreeUnwind1},
};

// Literal dispatcher tree/destruction cleanup record.
// R6GameService.dll data @ 1008192c : native storage identity retained.
const R6GameServiceNative::FuncInfo ClearProtocolDispatcherTreeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ClearProtocolDispatcherTreeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal dispatcher tree/destruction cleanup record.
// R6GameService.dll data @ 10081950 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyServiceProtocolDispatcherUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyServiceProtocolDispatcherUnwind1},
  {-1, R6GameServiceAddresses::DestroyServiceProtocolDispatcherUnwind2},
};

// Literal dispatcher tree/destruction cleanup record.
// R6GameService.dll data @ 10081950 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceProtocolDispatcherExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyServiceProtocolDispatcherUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Select exact six-state dispatcher construction FuncInfo and tail CRT exception dispatch.
// R6GameService.dll @ 10067239 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDispatcherConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructServiceProtocolDispatcherExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal six-state construction cleanup map/FuncInfo.
// R6GameService.dll data @ 100818e0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructServiceProtocolDispatcherUnwindMap[6] = {
  {-1, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind1},
  {0x0, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind2},
  {0x1, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind3},
  {0x2, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind4},
  {0x0, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind5},
  {0x4, R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwind6},
};

// Literal six-state construction cleanup map/FuncInfo.
// R6GameService.dll data @ 100818e0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructServiceProtocolDispatcherExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::ConstructServiceProtocolDispatcherUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Select exact one-state raw-allocation construction FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 1006747a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectTransportRecordConstructionEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeTransportRecordIfAbsentExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal raw-allocation cleanup map/FuncInfo.
// R6GameService.dll data @ 10081b30 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeTransportRecordIfAbsentUnwindMap[1] = {
  {-1, R6GameServiceAddresses::InitializeTransportRecordIfAbsentUnwind1},
};

// Literal raw-allocation cleanup map/FuncInfo.
// R6GameService.dll data @ 10081b30 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeTransportRecordIfAbsentExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::InitializeTransportRecordIfAbsentUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal selector13 cleanup map; state8 has no action and is not assigned by this parent.
// R6GameService.dll data @ 10081b54 : native storage identity retained.
const R6GameServiceNative::UnwindEntry HandleSelector13RecordRemovalUnwindMap[9] = {
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind1},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind2},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind3},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind4},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind5},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind6},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind7},
  {-1, R6GameServiceAddresses::HandleSelector13RecordRemovalUnwind8},
  {-1, 0x0},
};

// Literal selector13 FuncInfo.
// R6GameService.dll data @ 10081b54 : native storage identity retained.
const R6GameServiceNative::FuncInfo HandleSelector13RecordRemovalExceptionInfo = {
  0x19930520,
  0x9,
  R6GameServiceAddresses::HandleSelector13RecordRemovalUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal request cleanup map; unused state7 retains predecessor1 and no action.
// R6GameService.dll data @ 10081bb8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendTransportRequestPayloadUnwindMap[8] = {
  {-1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind1},
  {-1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind2},
  {0x1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind3},
  {0x1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind4},
  {0x1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind5},
  {-1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind6},
  {0x1, R6GameServiceAddresses::SendTransportRequestPayloadUnwind7},
  {0x1, 0x0},
};

// Literal request FuncInfo.
// R6GameService.dll data @ 10081bb8 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendTransportRequestPayloadExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::SendTransportRequestPayloadUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal keyed-request cleanup map; states6/7 are unused predecessor-only entries.
// R6GameService.dll data @ 10081c14 : native storage identity retained.
const R6GameServiceNative::UnwindEntry transport_record_support_DispatchRequest18ByKeyUnwindMap[8] = {
  {-1, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind1},
  {-1, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind2},
  {-1, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind3},
  {0x2, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind4},
  {-1, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind5},
  {0x4, R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwind6},
  {-1, 0x0},
  {0x6, 0x0},
};

// Literal keyed-request FuncInfo.
// R6GameService.dll data @ 10081c14 : native storage identity retained.
const R6GameServiceNative::FuncInfo transport_record_support_DispatchRequest18ByKeyExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::transport_record_support_DispatchRequest18ByKeyUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
