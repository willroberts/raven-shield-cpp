#include "native_addresses.h"
#include "native_records.h"

// clSRProtocol: RTTI-backed native class; original declarations and member spellings remain inferred.

// Build base storage, byte queues, two record vectors and segmented words; install protocol table and seed defaults.
// ENTRY ESP S: bitsS-1c/ownerS-18/member scratchS-14,S-10/stateS-4; supplied flagS+4 supplies unused cookie bytes by address.
// Preserve current word reloads after constructors, uninitialized cookie bytes, fifteen-state guards and RET4/owner EAX.
// R6GameService.dll @ 1005cee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeLargeRecordOwnerState(void *owner,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSRProtocolCtorEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push    ebx
    push    esi
    push    edi
    xor    edi,edi
    mov    DWORD PTR [esp+0xc],edi
    mov    eax,DWORD PTR [esp+0x2c]
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x10],esi
    je    Branch1
    mov    edi,0x1
    mov    DWORD PTR [esi+0x4],0x100782c4
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [esp+0x24],ebx
  Branch1:
    push    ebx
    mov    ecx,esi
    call    R6GameServiceAddresses::InitializeRecordOwnerStorage
    push    0x1
    lea    ecx,[esi+0x188]
    mov    DWORD PTR [esp+0x28],0x1
    mov    DWORD PTR [esi+0x16c],0x3c
    mov    DWORD PTR [esi+0x170],0x12c
    mov    DWORD PTR [esi+0x178],0x37
    mov    DWORD PTR [esi+0x180],0xf
    call    R6GameServiceAddresses::ConstructCircularList
    push    0x1
    lea    ecx,[esi+0x19c]
    mov    BYTE PTR [esp+0x28],0x2
    call    R6GameServiceAddresses::ConstructCircularList
    lea    eax,[esi+0x1d8]
    mov    WORD PTR [esi+0x1b0],0xa
    mov    WORD PTR [esi+0x1b6],0x224
    mov    DWORD PTR [esi+0x1c8],ebx
    mov    DWORD PTR [esi+0x1cc],0x40140000
    mov    WORD PTR [esi+0x1d0],0x18
    mov    WORD PTR [esi+0x1d2],0x2
    mov    BYTE PTR [esi+0x1d4],bl
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [eax],0x100782bc
    or    edi,0x2
    mov    WORD PTR [eax+0x4],bx
    mov    WORD PTR [eax+0x6],bx
    mov    WORD PTR [eax+0x8],bx
    mov    WORD PTR [eax+0xa],bx
    mov    WORD PTR [eax+0xc],bx
    add    eax,0x10
    or    edi,0x4
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [eax+0xc],0x100782b4
    mov    DWORD PTR [esp+0xc],edi
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x24],0x6
    push    ecx
    mov    ecx,eax
    call    R6GameServiceAddresses::InitializePointerTriplet
    lea    eax,[esi+0x1f8]
    or    edi,0x8
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [eax],0x100782bc
    mov    WORD PTR [eax+0x4],bx
    mov    WORD PTR [eax+0x6],bx
    mov    WORD PTR [eax+0x8],bx
    mov    WORD PTR [eax+0xa],bx
    mov    WORD PTR [eax+0xc],bx
    add    eax,0x10
    or    edi,0x10
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [eax+0xc],0x100782b4
    mov    DWORD PTR [esp+0xc],edi
    lea    edx,[esp+0x2c]
    mov    ecx,eax
    push    edx
    mov    DWORD PTR [esp+0x28],0xa
    call    R6GameServiceAddresses::InitializePointerTriplet
    lea    ecx,[esi+0x218]
    or    edi,0x20
    mov    DWORD PTR [esp+0x18],ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [ecx+0x28],0x100782ac
    mov    DWORD PTR [esp+0x24],0xd
    push    ebx
    lea    eax,[esp+0x30]
    push    eax
    call    R6GameServiceAddresses::InitializeSegmentedWords
    mov    cx,WORD PTR [esi+0x1b6]
    mov    dx,WORD PTR [esi+0x1d0]
    sub    cx,0xc
    push    ebx
    mov    DWORD PTR [esp+0x28],0xe
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRProtocolVTable
    mov    WORD PTR [esi+0x1b8],cx
    mov    WORD PTR [esi+0x1c0],dx
    call    R6GameServiceAddresses::time
    lea    eax,[eax+esi*1+0x1b2]
    add    esp,0x4
    mov    ecx,esi
    mov    WORD PTR [esi+0x1b2],ax
    call    R6GameServiceAddresses::ClearOwnerQueuesAndReset
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x1ac],0x1f4
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  }
}

// Destroy protocol then test current full flag low-byte bit0 for cached-owner free; return cached owner/RET4.
// R6GameService.dll @ 1005d0f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteObject(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyLargeRecordOwner
    test    BYTE PTR [esp+0x8],0x1
    je    Branch2
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Signed states2..5 inclusive invoke current adjusted member callback, then destroy segmented/vector/queue/base storage.
// ENTRY ESP S: savedownerS-10/stateS-4; disarm each member before its cleanup, keep native raw EAX/no field clearing.
// R6GameService.dll @ 1005d200 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyLargeRecordOwner(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSRProtocolDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRProtocolVTable
    mov    eax,DWORD PTR [esi+0x134]
    mov    DWORD PTR [esp+0x10],0x5
    cmp    eax,0x2
    jl    Branch3
    cmp    eax,0x5
    jg    Branch3
    mov    eax,DWORD PTR [esi+0x14c]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [eax+ecx*1]
    mov    eax,DWORD PTR [esi+0x148]
    add    edx,eax
    lea    ecx,[edx+esi*1+0x4]
    call    DWORD PTR [esi+0x144]
  Branch3:
    push    R6GameServiceAddresses::TextDeleteSRProtocol
    call    R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    lea    ecx,[esi+0x218]
    mov    BYTE PTR [esp+0x10],0x4
    call    R6GameServiceAddresses::ReleaseSegmentedWordStorage
    lea    ecx,[esi+0x208]
    mov    BYTE PTR [esp+0x10],0x3
    call    R6GameServiceAddresses::DestroyOwnedRecordVector
    lea    ecx,[esi+0x1e8]
    mov    BYTE PTR [esp+0x10],0x2
    call    R6GameServiceAddresses::DestroyOwnedRecordVector
    lea    ecx,[esi+0x19c]
    mov    BYTE PTR [esp+0x10],0x1
    call    R6GameServiceAddresses::DestroyCircularList
    lea    ecx,[esi+0x188]
    mov    BYTE PTR [esp+0x10],0x0
    call    R6GameServiceAddresses::DestroyCircularList
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call    R6GameServiceAddresses::DestroyRecordOwnerStorage
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    test    eax,eax
    je    Branch4
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x248
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069a6d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::DestroyRecordOwnerStorage
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069a75 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x188
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069a83 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x19c
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069a91 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x2
    test    eax,eax
    je    Branch5
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch5:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069aab : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind6(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x4
    test    eax,eax
    je    Branch6
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch6:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069ac5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind7(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069acd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1d8
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedOwnedRecords
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069adb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x8
    test    eax,eax
    je    Branch7
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch7:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069af5 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind10(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x10
    test    eax,eax
    je    Branch8
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch8:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069b0f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind11(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069b17 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind12(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1f8
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedOwnedRecords
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069b25 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind13(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x20
    test    eax,eax
    je    Branch9
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x2c
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch9:
    ret
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069b3f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind14(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Release only map-selected construction context from inherited frame; preserve saved member pointers and bit gates.
// R6GameService.dll @ 10069b47 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeLargeRecordOwnerStateUnwind15(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x218
    jmp    R6GameServiceAddresses::ForwardSegmentedWordDestroy
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069b80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyRecordOwnerStorage
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069b88 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x188
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069b96 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x19c
    jmp    R6GameServiceAddresses::ForwardToCircularListDestructor
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069ba4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1d8
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedOwnedRecords
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069bb2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1f8
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedOwnedRecords
  }
}

// Load current parent saved owner, adjust to remaining member, then tail-clean without retrying active cleanup.
// R6GameService.dll @ 10069bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyLargeRecordOwnerUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x218
    jmp    R6GameServiceAddresses::ForwardSegmentedWordDestroy
  }
}

// Select exact native FuncInfo then tail-forward to CRT exception dispatch.
// R6GameService.dll @ 10069b55 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSRProtocolCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeLargeRecordOwnerStateExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact native FuncInfo then tail-forward to CRT exception dispatch.
// R6GameService.dll @ 10069bce : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSRProtocolDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyLargeRecordOwnerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 100844f0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry InitializeLargeRecordOwnerStateUnwindMap[15] = {
  {-1, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind1},
  {0x0, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind2},
  {0x1, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind3},
  {0x2, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind4},
  {0x3, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind5},
  {0x4, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind6},
  {0x5, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind7},
  {0x3, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind8},
  {0x7, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind9},
  {0x8, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind10},
  {0x9, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind11},
  {0x7, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind12},
  {0xb, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind13},
  {0xc, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind14},
  {0xb, R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwind15},
};

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 100844f0 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeLargeRecordOwnerStateExceptionInfo = {
  0x19930520,
  0xf,
  R6GameServiceAddresses::InitializeLargeRecordOwnerStateUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 100845a8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyLargeRecordOwnerUnwindMap[6] = {
  {-1, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind1},
  {0x0, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind2},
  {0x1, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind3},
  {0x2, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind4},
  {0x3, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind5},
  {0x4, R6GameServiceAddresses::DestroyLargeRecordOwnerUnwind6},
};

// Literal native exception map/FuncInfo preserves exact parent cleanup states.
// R6GameService.dll data @ 100845a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyLargeRecordOwnerExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::DestroyLargeRecordOwnerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Genuine protocol-table stub: clear only AL, preserve incoming upper EAX, discard full physical argument words.
// R6GameService.dll @ 10059730 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RejectSRProtocolCall(void *owner,uint unused0,uint unused1,uint unused2,uint unused3)
{
  __asm {
    xor    al,al
    ret    0x10
  }
}

// Genuine protocol-table stub: clear only AL, preserve incoming upper EAX, discard full physical argument words.
// R6GameService.dll @ 10059740 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clSRProtocol_RejectSRProtocolCall(void *owner,uint unused0)
{
  __asm {
    xor    al,al
    ret    0x4
  }
}

// Genuine protocol-table stub: clear only AL, preserve incoming upper EAX, discard full physical argument words.
// R6GameService.dll @ 10059750 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clSRProtocol_RejectSRProtocolCall2(void *owner,uint unused0,uint unused1)
{
  __asm {
    xor    al,al
    ret    0x8
  }
}

// Set state0, clear FIFO19c/188, delete/reset vector1e8/208 record pointers, resize both rings, then clear base members.
// Preserve cached slot versus CURRENT end/count fields, physical resize argument upper bits and partial effects; no own EH.
// Install inactive member-pointer triplets only after base clear returns. No stack words; raw EAX is1005d380.
// R6GameService.dll @ 1005e890 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearOwnerQueuesAndReset(void *owner)
{
  __asm {
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    xor    ebp,ebp
    push    edi
    lea    ecx,[esi+0x19c]
    mov    DWORD PTR [esi+0x134],ebp
    call    R6GameServiceAddresses::ClearBlockQueue
    lea    ecx,[esi+0x188]
    call    R6GameServiceAddresses::ClearBlockQueue
    mov    ebx,DWORD PTR [esi+0x1e8]
    mov    eax,DWORD PTR [esi+0x1ec]
    lea    edi,[esi+0x1d8]
    cmp    ebx,eax
    mov    WORD PTR [edi+0x8],bp
    mov    WORD PTR [edi+0xa],bp
    mov    WORD PTR [edi+0xc],bp
    je    Branch12
  Branch10:
    mov    ecx,DWORD PTR [ebx]
    cmp    ecx,ebp
    je    Branch11
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch11:
    mov    DWORD PTR [ebx],ebp
    mov    eax,DWORD PTR [edi+0x14]
    add    ebx,0xc
    cmp    ebx,eax
    jne    Branch10
  Branch12:
    mov    eax,DWORD PTR [esi+0x20c]
    lea    ebx,[esi+0x1f8]
    mov    WORD PTR [ebx+0x8],bp
    mov    WORD PTR [ebx+0xa],bp
    mov    WORD PTR [ebx+0xc],bp
    mov    ebp,DWORD PTR [ebx+0x10]
    cmp    ebp,eax
    je    Branch15
  Branch13:
    mov    ecx,DWORD PTR [ebp+0x0]
    test    ecx,ecx
    je    Branch14
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch14:
    mov    DWORD PTR [ebp+0x0],0x0
    mov    eax,DWORD PTR [ebx+0x14]
    add    ebp,0xc
    cmp    ebp,eax
    jne    Branch13
  Branch15:
    mov    ax,WORD PTR [esi+0x1b0]
    mov    ecx,edi
    push    eax
    call    R6GameServiceAddresses::ResizeOwnedRecordArray
    mov    cx,WORD PTR [esi+0x1b0]
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ResetOwnedRecordRing
    mov    dx,WORD PTR [esi+0x1d0]
    xor    edi,edi
    mov    ecx,esi
    mov    WORD PTR [esi+0x90],di
    mov    WORD PTR [esi+0x1b4],di
    mov    WORD PTR [esi+0x1c0],dx
    call    R6GameServiceAddresses::ClearRecordOwnerMembers
    lea    ebx,[esi+0x15c]
    mov    eax,R6GameServiceAddresses::RejectOwnerPendingBytes
    xor    ecx,ecx
    xor    edx,edx
    mov    DWORD PTR [ebx],eax
    mov    eax,R6GameServiceAddresses::list_node_support_NoOp
    pop    edi
    mov    DWORD PTR [ebx+0x4],ecx
    mov    DWORD PTR [ebx+0x8],edx
    lea    ebx,[esi+0x138]
    mov    DWORD PTR [esi+0x138],eax
    mov    eax,R6GameServiceAddresses::ResetProtocolCallback
    mov    DWORD PTR [ebx+0x4],ecx
    mov    DWORD PTR [ebx+0x8],edx
    lea    ebx,[esi+0x144]
    add    esi,0x150
    mov    DWORD PTR [ebx],eax
    mov    eax,R6GameServiceAddresses::ReturnOwnerInactive
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [ebx+0x4],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [ebx+0x8],edx
    mov    DWORD PTR [esi+0x8],edx
    pop    esi
    pop    ebp
    pop    ebx
    ret
  }
}

// Publish state4/deadline168=0, sample time twice and add CURRENT178/170 intervals modulo32, then install active callbacks.
// No local EH/rollback; return last callback address1005d360, preserving separate sample/field/store order.
// R6GameService.dll @ 1005e9d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall EnterOwnerActiveState(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    push    edi
    push    0x0
    mov    DWORD PTR [esi+0x134],0x4
    mov    DWORD PTR [esi+0x168],0x0
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x178]
    push    0x0
    add    eax,ecx
    mov    DWORD PTR [esi+0x17c],eax
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x170]
    lea    edi,[esi+0x15c]
    add    eax,ecx
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x174],eax
    mov    eax,R6GameServiceAddresses::AppendOwnerPendingBytes
    mov    DWORD PTR [edi],eax
    xor    edx,edx
    mov    eax,R6GameServiceAddresses::RestartOwnerProcessing
    add    esp,0x8
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x138]
    mov    DWORD PTR [esi+0x138],eax
    mov    eax,R6GameServiceAddresses::SendTripleControlRecordAndResetDeadline
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x144]
    add    esi,0x150
    mov    DWORD PTR [edi],eax
    mov    eax,R6GameServiceAddresses::ProcessOwnerQueues
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    pop    edi
    mov    DWORD PTR [esi+0x8],edx
    pop    esi
    ret
  }
}

// Only initial state0 transitions to2; sample time before CURRENT180 interval and install state2 callbacks.
// Reject any nonzero state with only AL cleared; success EAX1005d301 retains callback-address upper24 bits.
// R6GameService.dll @ 1005ea70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall BeginOwnerStateTwo(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x134]
    test    eax,eax
    je    Branch16
    xor    al,al
    pop    esi
    ret
  Branch16:
    push    edi
    push    0x0
    mov    DWORD PTR [esi+0x134],0x2
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x180]
    lea    edi,[esi+0x15c]
    add    eax,ecx
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x184],eax
    mov    eax,R6GameServiceAddresses::RejectOwnerPendingBytes
    mov    DWORD PTR [edi],eax
    xor    edx,edx
    mov    eax,R6GameServiceAddresses::RestartOwnerProcessing
    add    esp,0x4
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x138]
    mov    DWORD PTR [esi+0x138],eax
    mov    eax,R6GameServiceAddresses::SendTripleControlRecordAndResetDeadline
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x144]
    add    esi,0x150
    mov    DWORD PTR [edi],eax
    mov    eax,R6GameServiceAddresses::ProcessOwnerDeadline
    mov    DWORD PTR [esi],eax
    mov    al,0x1
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    pop    edi
    mov    DWORD PTR [esi+0x8],edx
    pop    esi
    ret
  }
}

// Inactive callback tail-forwards the original registers/stack into protocol reset.
// R6GameService.dll @ 1005e5c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetProtocolCallback(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::ClearOwnerQueuesAndReset
  }
}

// Build owned record28/payload12: owner8/WORD8e, payload WORD90/0/3049/ffff, with WORD1b4 as checksum seed.
// Tail bytes10/11 remain allocator contents. Sum signed odd-leading byte then little-endian words, fold twice and complement.
// Send same record THREE times through CURRENT120, ignore statuses, delete through CURRENT table, call e810, then clear168.
// No local EH or payload NULL guard; initial record NULL returns0 immediately. Return helper raw EAX; saved ECX slot is0.
// R6GameService.dll @ 1005e5d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendTripleControlRecordAndResetDeadline(void *owner)
{
  __asm {
    push    ecx
    push    esi
    push    edi
    push    0x1c
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],0x0
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    test    esi,esi
    je    Branch22
    push    ebx
    push    0xc
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    mov    DWORD PTR [esi+0x14],0xc
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x18],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPSegmentVTable
    mov    ax,WORD PTR [edi+0x8e]
    mov    cx,WORD PTR [edi+0x90]
    mov    edx,DWORD PTR [edi+0x8]
    mov    WORD PTR [esi+0xc],ax
    mov    eax,DWORD PTR [esi+0x18]
    mov    DWORD PTR [esi+0x8],edx
    mov    WORD PTR [eax+0x2],cx
    mov    WORD PTR [eax+0x6],0x3049
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x4],0x0
    mov    ecx,DWORD PTR [esi+0x18]
    xor    eax,eax
    mov    WORD PTR [ecx+0x8],0xffff
    mov    edx,DWORD PTR [esi+0x18]
    mov    bx,WORD PTR [edi+0x1b4]
    mov    ecx,DWORD PTR [esi+0x14]
    mov    WORD PTR [edx],bx
    mov    edx,DWORD PTR [esi+0x14]
    sar    ecx,1
    and    edx,0x80000001
    jns    Branch17
    dec    edx
    or    edx,0xfffffffe
    inc    edx
  Branch17:
    mov    edx,DWORD PTR [esi+0x10]
    je    Branch18
    movsx    eax,BYTE PTR [edx]
    inc    edx
  Branch18:
    test    ecx,ecx
    jle    Branch20
  Branch19:
    xor    ebx,ebx
    mov    bx,WORD PTR [edx]
    add    edx,0x2
    add    eax,ebx
    dec    ecx
    jne    Branch19
  Branch20:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    mov    ebx,0x3
    mov    eax,ecx
    shr    eax,0x10
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x18]
    not    eax
    mov    WORD PTR [ecx],ax
  Branch21:
    mov    ecx,DWORD PTR [edi+0x120]
    push    esi
    call    R6GameServiceAddresses::SendKeyedRecordPayload
    dec    ebx
    jne    Branch21
    mov    edx,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [edx]
    mov    ecx,edi
    call    R6GameServiceAddresses::ConfigureOwnerStateFive
    mov    DWORD PTR [edi+0x168],0x0
    pop    ebx
  Branch22:
    pop    edi
    pop    esi
    pop    ecx
    ret
  }
}

// Sample time(0), add CURRENT full interval16c modulo32 and publish deadline168 before state5/callback triplets.
// Install15c=5d340,138=59130,144=5e5d0,150=5d3e0 with zero context words; return raw EAX5d3e0. No gate or EH.
// R6GameService.dll @ 1005e810 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ConfigureOwnerStateFive(void *owner)
{
  __asm {
    push    esi
    push    edi
    push    0x0
    mov    esi,ecx
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x16c]
    lea    edi,[esi+0x15c]
    add    eax,ecx
    xor    ecx,ecx
    mov    DWORD PTR [esi+0x168],eax
    mov    eax,R6GameServiceAddresses::RejectOwnerPendingBytes
    mov    DWORD PTR [edi],eax
    xor    edx,edx
    mov    eax,R6GameServiceAddresses::list_node_support_NoOp
    mov    DWORD PTR [esi+0x134],0x5
    mov    DWORD PTR [edi+0x4],ecx
    add    esp,0x4
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x138]
    mov    DWORD PTR [esi+0x138],eax
    mov    eax,R6GameServiceAddresses::SendTripleControlRecordAndResetDeadline
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    lea    edi,[esi+0x144]
    add    esi,0x150
    mov    DWORD PTR [edi],eax
    mov    eax,R6GameServiceAddresses::ProcessOwnerConditionalQueues
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [edi+0x4],ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [edi+0x8],edx
    pop    edi
    mov    DWORD PTR [esi+0x8],edx
    pop    esi
    ret
  }
}

// Enter state5, then set current recovery byte1d4=1 and tail to status-record queue; retain queue raw EAX/no local EH.
// R6GameService.dll @ 1005e5a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall RestartOwnerProcessing(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::ConfigureOwnerStateFive
    mov    BYTE PTR [esi+0x1d4],0x1
    mov    ecx,esi
    pop    esi
    jmp    R6GameServiceAddresses::QueueOwnerStatusRecord
  }
}

// Read record18 payload BYTE6 bit3 BEFORE restarting. Set deadline168=0 if set, otherwise queue status record.
// Do not reread flags after time callback; return restart/queue raw EAX, consume record argument with RET4, no deletion.
// R6GameService.dll @ 1005e6e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall HandleOwnerRecordStatus(void *owner,void *record)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    al,BYTE PTR [ecx+0x6]
    mov    ecx,esi
    test    al,0x8
    je    Branch23
    call    R6GameServiceAddresses::ConfigureOwnerStateFive
    mov    DWORD PTR [esi+0x168],0x0
    pop    esi
    ret    0x4
  Branch23:
    call    R6GameServiceAddresses::ConfigureOwnerStateFive
    mov    ecx,esi
    call    R6GameServiceAddresses::QueueOwnerStatusRecord
    pop    esi
    ret    0x4
  }
}

// Allocate clSRPSegment28/payload12 and fill status3041 before testing unsigned ring count<capacity.
// Full ring leaves the new record allocated and returns its current payload pointer; NULL record returns0.
// Otherwise cache slot, delete old segment, publish record/zero words, then use CURRENT index/modulus/count for WORD advance.
// Preserve partial constructor publication, untouched payload/padding, zero saved ECX, raw quotient EAX and no local EH.
// R6GameService.dll @ 1005e720 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall QueueOwnerStatusRecord(void *owner)
{
  __asm {
    push    ecx
    push    ebp
    push    esi
    push    edi
    xor    ebp,ebp
    push    0x1c
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    cmp    esi,ebp
    je    Branch25
    push    0xc
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    mov    DWORD PTR [esi+0x14],0xc
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0x18],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPSegmentVTable
    mov    ax,WORD PTR [edi+0x8e]
    mov    cx,WORD PTR [edi+0x90]
    mov    edx,DWORD PTR [edi+0x8]
    mov    WORD PTR [esi+0xc],ax
    mov    eax,DWORD PTR [esi+0x18]
    mov    DWORD PTR [esi+0x8],edx
    mov    WORD PTR [eax+0x2],cx
    mov    WORD PTR [eax+0x6],0x3041
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x4],bp
    mov    cx,WORD PTR [edi+0x1e0]
    cmp    cx,WORD PTR [edi+0x1dc]
    jae    Branch25
    mov    edx,DWORD PTR [esi+0x18]
    mov    ax,WORD PTR [edi+0x1e2]
    push    ebx
    mov    WORD PTR [edx+0x8],ax
    mov    edx,DWORD PTR [edi+0x1e8]
    xor    eax,eax
    mov    ax,WORD PTR [edi+0x1e2]
    lea    ecx,[eax+eax*2]
    lea    ebx,[edx+ecx*4]
    mov    ecx,DWORD PTR [edx+ecx*4]
    cmp    ecx,ebp
    je    Branch24
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch24:
    mov    DWORD PTR [ebx],esi
    mov    DWORD PTR [ebx+0x4],ebp
    mov    DWORD PTR [ebx+0x8],ebp
    mov    ax,WORD PTR [edi+0x1e2]
    xor    ecx,ecx
    inc    ax
    mov    cx,WORD PTR [edi+0x1de]
    and    eax,0xffff
    cdq
    idiv    ecx
    inc    WORD PTR [edi+0x1e0]
    pop    ebx
    mov    WORD PTR [edi+0x1e2],dx
  Branch25:
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret
  }
}

// Signed compare requested count with CURRENT194; failure clears only AL of request. Low preserve BYTE selects copy/consume.
// Forward full cached count and destination to embedded FIFO188; return helper raw EAX unchanged, RET12, no local EH.
// R6GameService.dll @ 1005d2e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadOwnerQueueBytes(
    void *owner,void *destination,uint byteCount,uint preserveWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    edx,DWORD PTR [ecx+0x194]
    cmp    eax,edx
    jle    Branch26
    xor    al,al
    ret    0xc
  Branch26:
    mov    dl,BYTE PTR [esp+0xc]
    add    ecx,0x188
    test    dl,dl
    mov    edx,DWORD PTR [esp+0x4]
    push    edx
    push    eax
    je    Branch27
    call    R6GameServiceAddresses::CopyBlockQueuePrefix
    ret    0xc
  Branch27:
    call    R6GameServiceAddresses::ConsumeBlockQueueBytes
    ret    0xc
  }
}

// Append to embedded FIFO19c using original source/count; return cached full requested count iff helper AL!=0, else full0.
// Keep NEG AL/SBB mask and count cached across call; RET8, no local EH.
// R6GameService.dll @ 1005d320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall AppendOwnerPendingBytes(void *owner,const void *source,uint byteCount)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    add    ecx,0x19c
    push    esi
    push    eax
    call    R6GameServiceAddresses::AppendBytesToBlockQueue
    neg    al
    sbb    eax,eax
    and    eax,esi
    pop    esi
    ret    0x8
  }
}

// Genuine pending-byte reject callback: full EAX0, consume both physical arguments with RET8, no effects.
// R6GameService.dll @ 1005d340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RejectOwnerPendingBytes(
    void *owner,const void *unusedSource,uint unusedByteCount)
{
  __asm {
    xor    eax,eax
    ret    0x8
  }
}

// Process input/state, then build pending records unconditionally on cached owner; ignore first result and force only AL1.
// R6GameService.dll @ 1005d360 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerQueues(void *owner)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::ProcessOwnerInputWithStateUpdate
    mov    ecx,esi
    call    R6GameServiceAddresses::BuildPendingOwnerRecords
    mov    al,0x1
    pop    esi
    ret
  }
}

// Genuine inactive callback: clear only AL, retaining entry EAX upper24; no stack arguments or effects.
// R6GameService.dll @ 1005d380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReturnOwnerInactive(void *unusedOwner)
{
  __asm {
    xor    al,al
    ret
  }
}

// Sample time0, compare CURRENT184 as unsigned; strictly expired calls CURRENT144 with adjusted member receiver.
// Receiver=owner+4+CURRENT148+DWORD[CURRENT owner4+CURRENT14c] modulo32; callback raw EAX with AL0.
// Otherwise process negotiation on cached owner and set only AL1. No own cleanup frame or state/deadline writes.
// R6GameService.dll @ 1005d390 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerDeadline(void *owner)
{
  __asm {
    push    esi
    push    0x0
    mov    esi,ecx
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x184]
    add    esp,0x4
    cmp    eax,ecx
    jbe    Branch28
    mov    eax,DWORD PTR [esi+0x14c]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [eax+ecx*1]
    mov    eax,DWORD PTR [esi+0x148]
    add    edx,eax
    lea    ecx,[edx+esi*1+0x4]
    call    DWORD PTR [esi+0x144]
    xor    al,al
    pop    esi
    ret
  Branch28:
    mov    ecx,esi
    call    R6GameServiceAddresses::ProcessOwnerInputWithNegotiation
    mov    al,0x1
    pop    esi
    ret
  }
}

// Sample time0 then compare CURRENT168 unsigned; strictly expired resets cached owner and clears only AL.
// Otherwise process input/close state, build pending records iff its AL!=0, then force only AL1. No local EH.
// R6GameService.dll @ 1005d3e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerConditionalQueues(void *owner)
{
  __asm {
    push    esi
    push    0x0
    mov    esi,ecx
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x168]
    add    esp,0x4
    cmp    eax,ecx
    mov    ecx,esi
    jbe    Branch29
    call    R6GameServiceAddresses::ClearOwnerQueuesAndReset
    xor    al,al
    pop    esi
    ret
  Branch29:
    call    R6GameServiceAddresses::ProcessOwnerInputWithCloseState
    test    al,al
    je    Branch30
    mov    ecx,esi
    call    R6GameServiceAddresses::BuildPendingOwnerRecords
  Branch30:
    mov    al,0x1
    pop    esi
    ret
  }
}

// While pending count nonzero and unsigned ring capacity remains, clamp signed chunk to WORD1bc and build
// segment28/storage1ba.
// Ignore consume status, fill3040 header, recheck capacity, cache slot/delete old segment, publish and advance
// CURRENT WORD index/count.
// Preserve orphan on second capacity failure, divide-before-count, no own EH; always run submit then word reports,
// force only AL1/ECX0.
// R6GameService.dll @ 1005d420 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall BuildPendingOwnerRecords(void *owner)
{
  __asm {
    push    ecx
    push    ebx
    push    ebp
    push    esi
    xor    ebp,ebp
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],ebp
  Branch31:
    mov    ebx,DWORD PTR [edi+0x1a8]
    test    ebx,ebx
    je    Branch34
    mov    ax,WORD PTR [edi+0x1e0]
    cmp    ax,WORD PTR [edi+0x1dc]
    jae    Branch34
    xor    eax,eax
    mov    ax,WORD PTR [edi+0x1bc]
    cmp    ebx,eax
    jle    Branch32
    mov    ebx,eax
  Branch32:
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    test    esi,esi
    je    Branch34
    xor    eax,eax
    or    ebp,0x1
    mov    ax,WORD PTR [edi+0x1ba]
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    push    eax
    mov    DWORD PTR [esi+0x14],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSegmentVTable
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,eax
    mov    DWORD PTR [esi+0x10],eax
    add    ecx,0xc
    mov    DWORD PTR [esi+0x18],eax
    push    ecx
    push    ebx
    lea    ecx,[edi+0x19c]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPSegmentVTable
    call    R6GameServiceAddresses::ConsumeBlockQueueBytes
    mov    ax,WORD PTR [edi+0x8e]
    mov    cx,WORD PTR [edi+0x90]
    mov    edx,DWORD PTR [edi+0x8]
    mov    WORD PTR [esi+0xc],ax
    mov    eax,DWORD PTR [esi+0x18]
    mov    DWORD PTR [esi+0x8],edx
    mov    WORD PTR [eax+0x2],cx
    mov    WORD PTR [eax+0x6],0x3040
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x4],bx
    mov    cx,WORD PTR [edi+0x1e0]
    cmp    cx,WORD PTR [edi+0x1dc]
    jae    Branch31
    mov    edx,DWORD PTR [esi+0x18]
    mov    ax,WORD PTR [edi+0x1e2]
    mov    WORD PTR [edx+0x8],ax
    mov    edx,DWORD PTR [edi+0x1e8]
    xor    eax,eax
    mov    ax,WORD PTR [edi+0x1e2]
    lea    ecx,[eax+eax*2]
    lea    ebx,[edx+ecx*4]
    mov    ecx,DWORD PTR [edx+ecx*4]
    test    ecx,ecx
    je    Branch33
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch33:
    xor    eax,eax
    mov    DWORD PTR [ebx],esi
    mov    DWORD PTR [ebx+0x4],eax
    mov    DWORD PTR [ebx+0x8],eax
    mov    ax,WORD PTR [edi+0x1e2]
    xor    ecx,ecx
    mov    cx,WORD PTR [edi+0x1de]
    inc    ax
    and    eax,0xffff
    cdq
    idiv    ecx
    inc    WORD PTR [edi+0x1e0]
    mov    WORD PTR [edi+0x1e2],dx
    jmp    Branch31
  Branch34:
    mov    ecx,edi
    call    R6GameServiceAddresses::SubmitExpiredOwnerRecords
    mov    ecx,edi
    call    R6GameServiceAddresses::SendOwnerWordReports
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    pop    ecx
    ret
  }
}

// Sample time once, scan CURRENT circular oldest/tail range with cached next modulo index; eligible nonnull slot
// requires now>deadline.
// Attach/pop one queued WORD before send, seed/checksum CURRENT segment bytes, submit through CURRENT association;
// failure stops without undo.
// Success stores captured time and time+CURRENT delay into cached slot; preserve raw EAX, current fields and no
// local EH.
// R6GameService.dll @ 1005d570 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SubmitExpiredOwnerRecords(void *owner)
{
  __asm {
    sub    esp,0x8
    push    ebx
    push    ebp
    push    esi
    push    edi
    push    0x0
    mov    esi,ecx
    call    R6GameServiceAddresses::time
    mov    bx,WORD PTR [esi+0x1e4]
    mov    ecx,eax
    add    esp,0x4
    mov    DWORD PTR [esp+0x14],ecx
  Branch35:
    mov    bp,WORD PTR [esi+0x1e2]
  Branch36:
    mov    ax,WORD PTR [esi+0x1e4]
    cmp    ax,bp
    ja    Branch37
    cmp    bx,ax
    jb    Branch47
    cmp    bx,bp
    jmp    Branch38
  Branch37:
    cmp    bx,bp
    jb    Branch39
    cmp    bx,ax
    jb    Branch47
    cmp    bx,WORD PTR [esi+0x1de]
  Branch38:
    jae    Branch47
  Branch39:
    mov    edx,DWORD PTR [esi+0x1e8]
    mov    eax,ebx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    lea    edi,[edx+eax*4]
    xor    eax,eax
    mov    ax,WORD PTR [esi+0x1de]
    mov    DWORD PTR [esp+0x10],eax
    lea    eax,[ebx+0x1]
    mov    ebx,DWORD PTR [esp+0x10]
    and    eax,0xffff
    cdq
    idiv    ebx
    cmp    DWORD PTR [edi+0x8],ecx
    mov    ebx,edx
    jae    Branch36
    cmp    DWORD PTR [edi],0x0
    je    Branch36
    mov    eax,DWORD PTR [esi+0x234]
    mov    ebp,DWORD PTR [esi+0x224]
    mov    ecx,DWORD PTR [esi+0x228]
    mov    edx,DWORD PTR [esi+0x22c]
    sub    eax,ebp
    sub    ecx,edx
    mov    edx,DWORD PTR [esi+0x220]
    sar    eax,0x2
    dec    eax
    shl    eax,0x6
    sar    ecx,1
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x218]
    sub    edx,ecx
    sar    edx,1
    add    eax,edx
    je    Branch42
    mov    eax,DWORD PTR [edi]
    mov    dx,WORD PTR [ecx]
    mov    eax,DWORD PTR [eax+0x18]
    or    BYTE PTR [eax+0x6],0x4
    mov    WORD PTR [eax+0xa],dx
    mov    ecx,DWORD PTR [esi+0x220]
    mov    eax,DWORD PTR [esi+0x218]
    sub    ecx,0x2
    cmp    eax,ecx
    je    Branch40
    add    eax,0x2
    jmp    Branch41
  Branch40:
    mov    edx,DWORD PTR [esi+0x21c]
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x224]
    add    eax,0x4
    mov    DWORD PTR [esi+0x224],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [esi+0x21c],eax
    add    eax,0x80
    mov    DWORD PTR [esi+0x220],eax
    mov    eax,DWORD PTR [esi+0x21c]
  Branch41:
    mov    DWORD PTR [esi+0x218],eax
  Branch42:
    mov    edx,DWORD PTR [edi]
    mov    bp,WORD PTR [esi+0x1b4]
    xor    eax,eax
    mov    ecx,DWORD PTR [edx+0x14]
    sar    ecx,1
    mov    DWORD PTR [esp+0x10],ecx
    mov    ecx,DWORD PTR [edx+0x18]
    mov    WORD PTR [ecx],bp
    mov    ecx,DWORD PTR [edx+0x14]
    and    ecx,0x80000001
    jns    Branch43
    dec    ecx
    or    ecx,0xfffffffe
    inc    ecx
  Branch43:
    mov    ecx,DWORD PTR [edx+0x10]
    je    Branch44
    movsx    eax,BYTE PTR [ecx]
    inc    ecx
  Branch44:
    mov    ebp,DWORD PTR [esp+0x10]
    test    ebp,ebp
    jle    Branch46
    mov    DWORD PTR [esp+0x10],ebp
  Branch45:
    xor    ebp,ebp
    mov    bp,WORD PTR [ecx]
    add    ecx,0x2
    add    eax,ebp
    mov    ebp,DWORD PTR [esp+0x10]
    dec    ebp
    mov    DWORD PTR [esp+0x10],ebp
    jne    Branch45
  Branch46:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    mov    eax,ecx
    shr    eax,0x10
    add    eax,ecx
    mov    ecx,DWORD PTR [edx+0x18]
    not    eax
    mov    WORD PTR [ecx],ax
    mov    eax,DWORD PTR [edi]
    mov    ecx,DWORD PTR [esi+0x120]
    push    eax
    call    R6GameServiceAddresses::SendKeyedRecordPayload
    test    al,al
    je    Branch47
    mov    ecx,DWORD PTR [esp+0x14]
    xor    eax,eax
    mov    ax,WORD PTR [esi+0x1c0]
    mov    DWORD PTR [edi+0x4],ecx
    add    eax,ecx
    mov    DWORD PTR [edi+0x8],eax
    jmp    Branch35
  Branch47:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret
  }
}

// For each queued WORD build segment28/payload12, attach3044 header/indexffff, seed/checksum and send through
// CURRENT association.
// Consume WORD only after send AL success, then current virtual delete; failure deletes record but retains WORD and
// returns delete raw EAX.
// Raw-allocation state0 protects constructor only at savedS-10; no completed-record rollback. Empty returns raw0,
// NULL record returns0.
// R6GameService.dll @ 1005d750 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall SendOwnerWordReports(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOwnerWordReportEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x10],ebx
    mov    eax,DWORD PTR [edi+0x234]
    mov    ebp,DWORD PTR [edi+0x224]
    mov    ecx,DWORD PTR [edi+0x228]
    mov    edx,DWORD PTR [edi+0x220]
    sub    eax,ebp
    mov    ebp,DWORD PTR [edi+0x22c]
    sar    eax,0x2
    sub    ecx,ebp
    mov    ebp,DWORD PTR [edi+0x218]
    dec    eax
    sub    edx,ebp
    shl    eax,0x6
    sar    ecx,1
    add    eax,ecx
    sar    edx,1
    add    eax,edx
    je    Branch58
  Branch48:
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x14],esi
    cmp    esi,ebx
    mov    DWORD PTR [esp+0x20],ebx
    je    Branch49
    mov    edx,DWORD PTR [esp+0x10]
    push    ebx
    or    edx,0x1
    push    0xc
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    mov    DWORD PTR [esp+0x18],edx
    call    R6GameServiceAddresses::InitializeOwnedByteRecord
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSRPSegmentVTable
    jmp    Branch50
  Branch49:
    xor    esi,esi
  Branch50:
    cmp    esi,ebx
    mov    DWORD PTR [esp+0x20],0xffffffff
    je    Branch58
    mov    ax,WORD PTR [edi+0x8e]
    mov    cx,WORD PTR [edi+0x90]
    mov    edx,DWORD PTR [edi+0x8]
    mov    WORD PTR [esi+0xc],ax
    mov    eax,DWORD PTR [esi+0x18]
    mov    DWORD PTR [esi+0x8],edx
    mov    WORD PTR [eax+0x2],cx
    mov    WORD PTR [eax+0x6],0x3040
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x4],bx
    mov    ecx,DWORD PTR [edi+0x218]
    mov    eax,DWORD PTR [esi+0x18]
    mov    dx,WORD PTR [ecx]
    or    BYTE PTR [eax+0x6],0x4
    mov    WORD PTR [eax+0xa],dx
    mov    eax,DWORD PTR [esi+0x18]
    mov    WORD PTR [eax+0x8],0xffff
    mov    edx,DWORD PTR [esi+0x18]
    mov    bp,WORD PTR [edi+0x1b4]
    mov    ecx,DWORD PTR [esi+0x14]
    mov    WORD PTR [edx],bp
    mov    edx,DWORD PTR [esi+0x14]
    xor    eax,eax
    sar    ecx,1
    and    edx,0x80000001
    jns    Branch51
    dec    edx
    or    edx,0xfffffffe
    inc    edx
  Branch51:
    mov    edx,DWORD PTR [esi+0x10]
    je    Branch52
    movsx    eax,BYTE PTR [edx]
    inc    edx
  Branch52:
    cmp    ecx,ebx
    jle    Branch54
  Branch53:
    xor    ebp,ebp
    mov    bp,WORD PTR [edx]
    add    edx,0x2
    add    eax,ebp
    dec    ecx
    jne    Branch53
  Branch54:
    mov    ecx,eax
    and    eax,0xffff
    shr    ecx,0x10
    add    ecx,eax
    push    esi
    mov    eax,ecx
    shr    eax,0x10
    add    eax,ecx
    mov    ecx,DWORD PTR [esi+0x18]
    not    eax
    mov    WORD PTR [ecx],ax
    mov    ecx,DWORD PTR [edi+0x120]
    call    R6GameServiceAddresses::SendKeyedRecordPayload
    test    al,al
    je    Branch57
    mov    edx,DWORD PTR [edi+0x220]
    mov    eax,DWORD PTR [edi+0x218]
    sub    edx,0x2
    cmp    eax,edx
    je    Branch55
    add    eax,0x2
    mov    DWORD PTR [edi+0x218],eax
    jmp    Branch56
  Branch55:
    mov    eax,DWORD PTR [edi+0x21c]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [edi+0x224]
    add    eax,0x4
    mov    DWORD PTR [edi+0x224],eax
    mov    eax,DWORD PTR [eax]
    mov    DWORD PTR [edi+0x21c],eax
    mov    ecx,DWORD PTR [edi+0x21c]
    add    eax,0x80
    mov    DWORD PTR [edi+0x218],ecx
    mov    DWORD PTR [edi+0x220],eax
  Branch56:
    mov    edx,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [edx]
    mov    eax,DWORD PTR [edi+0x234]
    mov    ebp,DWORD PTR [edi+0x224]
    mov    ecx,DWORD PTR [edi+0x228]
    mov    edx,DWORD PTR [edi+0x220]
    sub    eax,ebp
    mov    ebp,DWORD PTR [edi+0x22c]
    sar    eax,0x2
    sub    ecx,ebp
    mov    ebp,DWORD PTR [edi+0x218]
    dec    eax
    sub    edx,ebp
    shl    eax,0x6
    sar    ecx,1
    add    eax,ecx
    sar    edx,1
    add    eax,edx
    jne    Branch48
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  Branch57:
    mov    eax,DWORD PTR [esi]
    push    0x1
    mov    ecx,esi
    call    DWORD PTR [eax]
  Branch58:
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// Word-report state0: release CURRENT saved raw segment allocationS-10 through allocator alias; no member destruction.
// R6GameService.dll @ 10069be0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl SendOwnerWordReportsUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select exact one-state word-report map845f4/FuncInfo845fc and tail CRT dispatch.
// R6GameService.dll @ 10069bea : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOwnerWordReportEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendOwnerWordReportsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal word-report constructor cleanup map and FuncInfo.
// R6GameService.dll data @ 100845f4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendOwnerWordReportsUnwindMap[1] = {
  {-1, R6GameServiceAddresses::SendOwnerWordReportsUnwind1},
};

// Exact one-state constructor guard metadata.
// R6GameService.dll data @ 100845f4 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendOwnerWordReportsExceptionInfo = {
  0x19930520,
  1,
  R6GameServiceAddresses::SendOwnerWordReportsUnwindMap,
  0,
  0,
  0,
  0,
};

// Receive/update deadlines, detach each input node, validate class/length/checksum and restore original checksum
// through current18.
// Retire accepted acknowledgements, advance current oldest across cached ring/modulus, update delay with native x87
// store/retained sum.
// Handle status, place in current receive window with old-record deletion, then pop/ack/append payload until signed
// FIFO limit stops.
// Preserve cached records/slots versus live fields, partial effects, raw upper EAX/AL1, aligned frame and no local
// EH.
// R6GameService.dll @ 1005d990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerInputWithStateUpdate(void *owner)
{
  __asm {
    push    ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    sub    esp,0x18
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x120]
    call    R6GameServiceAddresses::ReceiveAndQueueKeyedDatagrams
    mov    ecx,edi
    call    R6GameServiceAddresses::UpdateOwnerDeadlines
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    je    Branch69
  Branch59:
    mov    eax,DWORD PTR [ecx]
    push    ecx
    mov    edx,DWORD PTR [eax]
    mov    eax,esp
    mov    ebx,DWORD PTR [edx+0x8]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x18],ebx
    mov    edx,DWORD PTR [edx]
    mov    DWORD PTR [eax],edx
    lea    eax,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::EraseCircularNode
    mov    eax,DWORD PTR [ebx+0x18]
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+0x6]
    and    ecx,0xffff0fc0
    cmp    ecx,0x40
    jne    Branch67
    cmp    DWORD PTR [ebx+0x14],0xc
    jl    Branch67
    mov    cx,WORD PTR [edi+0x1b2]
    mov    si,WORD PTR [eax]
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ComputeSeededRecordChecksum
    mov    edx,DWORD PTR [ebx+0x18]
    cmp    si,ax
    sete    al
    test    al,al
    mov    WORD PTR [edx],si
    je    Branch67
    mov    eax,DWORD PTR [ebx+0x18]
    test    BYTE PTR [eax+0x6],0x4
    je    Branch65
    mov    bx,WORD PTR [eax+0xa]
    lea    esi,[edi+0x1d8]
    push    ebx
    mov    ecx,esi
    call    R6GameServiceAddresses::IsOwnerRecordIndexAccepted
    test    al,al
    je    Branch64
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,ebx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    mov    edx,DWORD PTR [ecx+eax*4+0x4]
    lea    ebp,[ecx+eax*4]
    mov    DWORD PTR [esp+0x18],edx
    mov    ecx,DWORD PTR [ebp+0x0]
    test    ecx,ecx
    je    Branch60
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch60:
    mov    DWORD PTR [ebp+0x0],0x0
    cmp    bx,WORD PTR [esi+0xc]
    jne    Branch62
    mov    ebx,DWORD PTR [esi+0x10]
    xor    ecx,ecx
    mov    cx,WORD PTR [esi+0x6]
  Branch61:
    mov    ax,WORD PTR [esi+0xc]
    dec    WORD PTR [esi+0x8]
    inc    ax
    and    eax,0xffff
    cdq
    idiv    ecx
    mov    eax,edx
    mov    WORD PTR [esi+0xc],dx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    cmp    DWORD PTR [ebx+eax*4],0x0
    jne    Branch62
    cmp    dx,WORD PTR [esi+0xa]
    jne    Branch61
  Branch62:
    push    0x0
    call    R6GameServiceAddresses::time
    mov    esi,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x28],0x0
    sub    eax,esi
    add    esp,0x4
    mov    DWORD PTR [esp+0x20],eax
    fild    QWORD PTR [esp+0x20]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_1
    fld    QWORD PTR [edi+0x1c8]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_9
    faddp    st(1),st
    fst    QWORD PTR [edi+0x1c8]
    fadd    st(0),st
    call    R6GameServiceAddresses::ftol
    mov    cx,WORD PTR [edi+0x1d0]
    mov    WORD PTR [edi+0x1c0],ax
    cmp    ax,cx
    ja    Branch63
    mov    cx,WORD PTR [edi+0x1d2]
    cmp    ax,cx
    jae    Branch64
  Branch63:
    mov    WORD PTR [edi+0x1c0],cx
  Branch64:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    mov    eax,DWORD PTR [ecx+0x18]
    cmp    WORD PTR [eax+0x8],0xffff
    je    Branch67
  Branch65:
    test    BYTE PTR [eax+0x6],0x1
    je    Branch66
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::HandleOwnerRecordStatus
  Branch66:
    mov    edx,DWORD PTR [ebx+0x18]
    mov    cx,WORD PTR [edi+0x204]
    mov    ax,WORD PTR [edx+0x8]
    mov    dx,WORD PTR [edi+0x202]
    cmp    cx,dx
    ja    Branch73
    cmp    ax,cx
    jb    Branch67
    cmp    ax,dx
    jb    Branch74
  Branch67:
    mov    eax,DWORD PTR [ebx]
    push    0x1
    mov    ecx,ebx
    call    DWORD PTR [eax]
  Branch68:
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    jne    Branch59
  Branch69:
    mov    ecx,DWORD PTR [edi+0x194]
    mov    eax,DWORD PTR [edi+0x198]
    lea    esi,[edi+0x188]
    cmp    ecx,eax
    jg    Branch72
    lea    ebx,[edi+0x1f8]
  Branch70:
    lea    edx,[esp+0x14]
    mov    ecx,ebx
    push    edx
    call    R6GameServiceAddresses::PopOwnedRingRecord
    test    al,al
    je    Branch72
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x18]
    push    eax
    mov    dx,WORD PTR [ecx+0x8]
    lea    ecx,[edi+0x218]
    mov    DWORD PTR [esp+0x1c],edx
    call    R6GameServiceAddresses::AppendSegmentedWord
    mov    eax,DWORD PTR [esp+0x14]
    xor    edx,edx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    eax,DWORD PTR [eax+0x10]
    add    eax,0xc
    mov    dx,WORD PTR [ecx+0x4]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendBytesToBlockQueue
    mov    ecx,DWORD PTR [esp+0x14]
    test    ecx,ecx
    je    Branch71
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch71:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jle    Branch70
  Branch72:
    pop    edi
    mov    al,0x1
    pop    esi
    pop    ebp
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch73:
    cmp    ax,dx
    jb    Branch74
    cmp    ax,cx
    jb    Branch67
    cmp    ax,WORD PTR [edi+0x1fe]
    jae    Branch67
  Branch74:
    mov    ecx,DWORD PTR [edi+0x208]
    and    eax,0xffff
    xor    ebp,ebp
    lea    eax,[eax+eax*2]
    lea    esi,[ecx+eax*4]
    mov    ecx,DWORD PTR [ecx+eax*4]
    cmp    ecx,ebp
    je    Branch75
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch75:
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],ebp
    mov    DWORD PTR [esi+0x8],ebp
    jmp    Branch68
  }
}

// Detach/validate incoming records; mask02 calls negotiation loader only in current state2, then clears current
// header length regardless.
// Preserve native ACK retirement/x87 delay, status/window replacement and signed FIFO transfer, raw AL1 and aligned
// frame.
// No initial deadline update, completed-record rollback or local EH; all later packet/owner reads retain native
// timing.
// R6GameService.dll @ 1005dca0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerInputWithNegotiation(void *owner)
{
  __asm {
    push    ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    sub    esp,0x18
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x120]
    call    R6GameServiceAddresses::ReceiveAndQueueKeyedDatagrams
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    je    Branch88
  Branch76:
    mov    eax,DWORD PTR [ecx]
    push    ecx
    mov    edx,DWORD PTR [eax]
    mov    eax,esp
    mov    ebx,DWORD PTR [edx+0x8]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x18],ebx
    mov    edx,DWORD PTR [edx]
    mov    DWORD PTR [eax],edx
    lea    eax,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::EraseCircularNode
    mov    eax,DWORD PTR [ebx+0x18]
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+0x6]
    and    ecx,0xffff0fc0
    cmp    ecx,0x40
    jne    Branch86
    cmp    DWORD PTR [ebx+0x14],0xc
    jl    Branch86
    mov    cx,WORD PTR [edi+0x1b2]
    mov    si,WORD PTR [eax]
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ComputeSeededRecordChecksum
    mov    edx,DWORD PTR [ebx+0x18]
    cmp    si,ax
    sete    al
    test    al,al
    mov    WORD PTR [edx],si
    je    Branch86
    mov    eax,DWORD PTR [ebx+0x18]
    test    BYTE PTR [eax+0x6],0x2
    je    Branch78
    cmp    DWORD PTR [edi+0x134],0x2
    jne    Branch77
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::LoadOwnerNegotiationParameters
  Branch77:
    mov    ecx,DWORD PTR [ebx+0x18]
    mov    WORD PTR [ecx+0x4],0x0
  Branch78:
    mov    eax,DWORD PTR [ebx+0x18]
    test    BYTE PTR [eax+0x6],0x4
    je    Branch84
    mov    bx,WORD PTR [eax+0xa]
    lea    esi,[edi+0x1d8]
    push    ebx
    mov    ecx,esi
    call    R6GameServiceAddresses::IsOwnerRecordIndexAccepted
    test    al,al
    je    Branch83
    mov    eax,ebx
    and    eax,0xffff
    lea    edx,[eax+eax*2]
    mov    eax,DWORD PTR [esi+0x10]
    mov    ecx,DWORD PTR [eax+edx*4+0x4]
    lea    ebp,[eax+edx*4]
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,DWORD PTR [ebp+0x0]
    test    ecx,ecx
    je    Branch79
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch79:
    mov    DWORD PTR [ebp+0x0],0x0
    cmp    bx,WORD PTR [esi+0xc]
    jne    Branch81
    mov    ebx,DWORD PTR [esi+0x10]
    xor    ecx,ecx
    mov    cx,WORD PTR [esi+0x6]
  Branch80:
    mov    ax,WORD PTR [esi+0xc]
    dec    WORD PTR [esi+0x8]
    inc    ax
    and    eax,0xffff
    cdq
    idiv    ecx
    mov    eax,edx
    mov    WORD PTR [esi+0xc],dx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    cmp    DWORD PTR [ebx+eax*4],0x0
    jne    Branch81
    cmp    dx,WORD PTR [esi+0xa]
    jne    Branch80
  Branch81:
    push    0x0
    call    R6GameServiceAddresses::time
    mov    esi,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x28],0x0
    sub    eax,esi
    add    esp,0x4
    mov    DWORD PTR [esp+0x20],eax
    fild    QWORD PTR [esp+0x20]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_1
    fld    QWORD PTR [edi+0x1c8]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_9
    faddp    st(1),st
    fst    QWORD PTR [edi+0x1c8]
    fadd    st(0),st
    call    R6GameServiceAddresses::ftol
    mov    cx,WORD PTR [edi+0x1d0]
    mov    WORD PTR [edi+0x1c0],ax
    cmp    ax,cx
    ja    Branch82
    mov    cx,WORD PTR [edi+0x1d2]
    cmp    ax,cx
    jae    Branch83
  Branch82:
    mov    WORD PTR [edi+0x1c0],cx
  Branch83:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    ebx,ecx
    mov    eax,DWORD PTR [ecx+0x18]
    cmp    WORD PTR [eax+0x8],0xffff
    je    Branch86
  Branch84:
    test    BYTE PTR [eax+0x6],0x1
    je    Branch85
    push    ebx
    mov    ecx,edi
    call    R6GameServiceAddresses::HandleOwnerRecordStatus
  Branch85:
    mov    edx,DWORD PTR [ebx+0x18]
    mov    cx,WORD PTR [edi+0x204]
    mov    ax,WORD PTR [edx+0x8]
    mov    dx,WORD PTR [edi+0x202]
    cmp    cx,dx
    ja    Branch92
    cmp    ax,cx
    jb    Branch86
    cmp    ax,dx
    jb    Branch93
  Branch86:
    mov    eax,DWORD PTR [ebx]
    push    0x1
    mov    ecx,ebx
    call    DWORD PTR [eax]
  Branch87:
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    jne    Branch76
  Branch88:
    mov    ecx,DWORD PTR [edi+0x194]
    mov    eax,DWORD PTR [edi+0x198]
    lea    esi,[edi+0x188]
    cmp    ecx,eax
    jg    Branch91
    lea    ebx,[edi+0x1f8]
  Branch89:
    lea    edx,[esp+0x14]
    mov    ecx,ebx
    push    edx
    call    R6GameServiceAddresses::PopOwnedRingRecord
    test    al,al
    je    Branch91
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [eax+0x18]
    lea    eax,[esp+0x18]
    push    eax
    mov    dx,WORD PTR [ecx+0x8]
    lea    ecx,[edi+0x218]
    mov    DWORD PTR [esp+0x1c],edx
    call    R6GameServiceAddresses::AppendSegmentedWord
    mov    eax,DWORD PTR [esp+0x14]
    xor    edx,edx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    eax,DWORD PTR [eax+0x10]
    add    eax,0xc
    mov    dx,WORD PTR [ecx+0x4]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendBytesToBlockQueue
    mov    ecx,DWORD PTR [esp+0x14]
    test    ecx,ecx
    je    Branch90
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch90:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jle    Branch89
  Branch91:
    pop    edi
    mov    al,0x1
    pop    esi
    pop    ebp
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch92:
    cmp    ax,dx
    jb    Branch93
    cmp    ax,cx
    jb    Branch86
    cmp    ax,WORD PTR [edi+0x1fe]
    jae    Branch86
  Branch93:
    mov    ecx,DWORD PTR [edi+0x208]
    and    eax,0xffff
    xor    ebp,ebp
    lea    eax,[eax+eax*2]
    lea    esi,[ecx+eax*4]
    mov    ecx,DWORD PTR [ecx+eax*4]
    cmp    ecx,ebp
    je    Branch94
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch94:
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],ebp
    mov    DWORD PTR [esi+0x8],ebp
    jmp    Branch87
  }
}

// Cache retired header mask01 only for nonnull old record; otherwise retain scratch BYTE A-0x15, A=(entryESP-4)&~7.
// If that byte and current recovery0, call adjusted CURRENT144 before timing update; keep retained/uninitialized bytes.
// Incoming mask01 restarts/clears deadline or samples time, clears recovery and stores time+2*CURRENT upper delay.
// Then replace current receive slot and pop/ACK/append payload under signed FIFO gate; raw AL1, aligned frame, no
// local EH.
// R6GameService.dll @ 1005e020 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ProcessOwnerInputWithCloseState(void *owner)
{
  __asm {
    push    ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    sub    esp,0x18
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x120]
    call    R6GameServiceAddresses::ReceiveAndQueueKeyedDatagrams
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    je    Branch108
  Branch95:
    mov    eax,DWORD PTR [ecx]
    push    ecx
    mov    edx,DWORD PTR [eax]
    mov    eax,esp
    mov    ebx,DWORD PTR [edx+0x8]
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x18],ebx
    mov    edx,DWORD PTR [edx]
    mov    DWORD PTR [eax],edx
    lea    eax,[esp+0x20]
    push    eax
    call    R6GameServiceAddresses::EraseCircularNode
    mov    eax,DWORD PTR [ebx+0x18]
    xor    ecx,ecx
    mov    cx,WORD PTR [eax+0x6]
    and    ecx,0xffff0fc0
    cmp    ecx,0x40
    jne    Branch106
    cmp    DWORD PTR [ebx+0x14],0xc
    jl    Branch106
    mov    cx,WORD PTR [edi+0x1b2]
    mov    si,WORD PTR [eax]
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::ComputeSeededRecordChecksum
    mov    edx,DWORD PTR [ebx+0x18]
    cmp    si,ax
    sete    al
    test    al,al
    mov    WORD PTR [edx],si
    je    Branch106
    mov    eax,DWORD PTR [ebx+0x18]
    test    BYTE PTR [eax+0x6],0x4
    je    Branch102
    mov    bx,WORD PTR [eax+0xa]
    lea    esi,[edi+0x1d8]
    push    ebx
    mov    ecx,esi
    call    R6GameServiceAddresses::IsOwnerRecordIndexAccepted
    test    al,al
    je    Branch101
    mov    ecx,DWORD PTR [esi+0x10]
    mov    eax,ebx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    mov    edx,DWORD PTR [ecx+eax*4+0x4]
    lea    ebp,[ecx+eax*4]
    mov    DWORD PTR [esp+0x18],edx
    mov    ecx,DWORD PTR [ebp+0x0]
    test    ecx,ecx
    je    Branch97
    mov    eax,DWORD PTR [ecx+0x18]
    mov    al,BYTE PTR [eax+0x6]
    and    al,0x1
    test    ecx,ecx
    mov    BYTE PTR [esp+0x13],al
    je    Branch96
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch96:
    mov    DWORD PTR [ebp+0x0],0x0
  Branch97:
    cmp    bx,WORD PTR [esi+0xc]
    jne    Branch99
    mov    ebp,DWORD PTR [esi+0x10]
    xor    ecx,ecx
    mov    cx,WORD PTR [esi+0x6]
  Branch98:
    mov    ax,WORD PTR [esi+0xc]
    dec    WORD PTR [esi+0x8]
    inc    ax
    and    eax,0xffff
    cdq
    idiv    ecx
    mov    eax,edx
    mov    WORD PTR [esi+0xc],dx
    and    eax,0xffff
    lea    eax,[eax+eax*2]
    cmp    DWORD PTR [ebp+eax*4+0x0],0x0
    jne    Branch99
    cmp    dx,WORD PTR [esi+0xa]
    jne    Branch98
  Branch99:
    mov    al,BYTE PTR [esp+0x13]
    test    al,al
    je    Branch100
    mov    al,BYTE PTR [edi+0x1d4]
    test    al,al
    jne    Branch100
    mov    ecx,DWORD PTR [edi+0x14c]
    mov    edx,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [ecx+edx*1]
    mov    ecx,DWORD PTR [edi+0x148]
    add    eax,ecx
    lea    ecx,[eax+edi*1+0x4]
    call    DWORD PTR [edi+0x144]
  Branch100:
    push    0x0
    call    R6GameServiceAddresses::time
    mov    esi,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esp+0x28],0x0
    sub    eax,esi
    add    esp,0x4
    mov    DWORD PTR [esp+0x20],eax
    fild    QWORD PTR [esp+0x20]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_1
    fld    QWORD PTR [edi+0x1c8]
    fmul    QWORD PTR ds:R6GameServiceAddresses::NativeDouble0_9
    faddp    st(1),st
    fst    QWORD PTR [edi+0x1c8]
    fadd    st(0),st
    call    R6GameServiceAddresses::ftol
    mov    cx,WORD PTR [edi+0x1d0]
    mov    WORD PTR [edi+0x1c0],ax
    cmp    ax,cx
    jbe    Branch103
    mov    WORD PTR [edi+0x1c0],cx
  Branch101:
    mov    ebx,DWORD PTR [esp+0x14]
  Branch102:
    mov    ecx,DWORD PTR [ebx+0x18]
    test    BYTE PTR [ecx+0x6],0x1
    je    Branch105
    mov    al,BYTE PTR [edi+0x1d4]
    test    al,al
    je    Branch104
    push    0x0
    call    R6GameServiceAddresses::time
    add    esp,0x4
    xor    edx,edx
    mov    dx,WORD PTR [edi+0x1d0]
    mov    BYTE PTR [edi+0x1d4],0x0
    lea    eax,[eax+edx*2]
    mov    DWORD PTR [edi+0x168],eax
    jmp    Branch105
  Branch103:
    mov    cx,WORD PTR [edi+0x1d2]
    mov    ebx,DWORD PTR [esp+0x14]
    cmp    ax,cx
    jae    Branch102
    mov    WORD PTR [edi+0x1c0],cx
    jmp    Branch102
  Branch104:
    mov    ecx,edi
    call    R6GameServiceAddresses::ConfigureOwnerStateFive
    mov    DWORD PTR [edi+0x168],0x0
  Branch105:
    mov    ecx,DWORD PTR [ebx+0x18]
    mov    dx,WORD PTR [edi+0x202]
    mov    ax,WORD PTR [ecx+0x8]
    mov    cx,WORD PTR [edi+0x204]
    cmp    cx,dx
    ja    Branch112
    cmp    ax,cx
    jb    Branch106
    cmp    ax,dx
    jb    Branch113
  Branch106:
    mov    edx,DWORD PTR [ebx]
    push    0x1
    mov    ecx,ebx
    call    DWORD PTR [edx]
  Branch107:
    mov    eax,DWORD PTR [edi+0x124]
    lea    ecx,[edi+0x124]
    cmp    DWORD PTR [eax],eax
    jne    Branch95
  Branch108:
    mov    eax,DWORD PTR [edi+0x194]
    mov    ecx,DWORD PTR [edi+0x198]
    lea    esi,[edi+0x188]
    cmp    eax,ecx
    jg    Branch111
    lea    ebx,[edi+0x1f8]
  Branch109:
    lea    ecx,[esp+0x14]
    push    ecx
    mov    ecx,ebx
    call    R6GameServiceAddresses::PopOwnedRingRecord
    test    al,al
    je    Branch111
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [edx+0x18]
    lea    edx,[esp+0x18]
    push    edx
    mov    cx,WORD PTR [eax+0x8]
    mov    DWORD PTR [esp+0x1c],ecx
    lea    ecx,[edi+0x218]
    call    R6GameServiceAddresses::AppendSegmentedWord
    mov    eax,DWORD PTR [esp+0x14]
    xor    edx,edx
    mov    ecx,DWORD PTR [eax+0x18]
    mov    eax,DWORD PTR [eax+0x10]
    add    eax,0xc
    mov    dx,WORD PTR [ecx+0x4]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendBytesToBlockQueue
    mov    ecx,DWORD PTR [esp+0x14]
    test    ecx,ecx
    je    Branch110
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch110:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    cmp    eax,ecx
    jle    Branch109
  Branch111:
    pop    edi
    mov    al,0x1
    pop    esi
    pop    ebp
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch112:
    cmp    ax,dx
    jb    Branch113
    cmp    ax,cx
    jb    Branch106
    cmp    ax,WORD PTR [edi+0x1fe]
    jae    Branch106
  Branch113:
    and    eax,0xffff
    push    ebx
    lea    edx,[eax+eax*2]
    mov    eax,DWORD PTR [edi+0x208]
    lea    ecx,[eax+edx*4]
    call    R6GameServiceAddresses::ReplaceOwnedRecordObject
    jmp    Branch107
  }
}

// Require current header mask04, otherwise return header pointer upper24/AL0. Read negotiation values through
// record10+12.
// Publish owner header/seed/window/chunk fields, resize sender/rx rings, ensure current association capacity, then
// enter active state.
// Keep full physical words and native upper-register residues; failed ensure returns raw result without rollback.
// RET4.
// R6GameService.dll @ 1005e350 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall LoadOwnerNegotiationParameters(void *owner,void *record)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx+0x18]
    test    BYTE PTR [eax+0x6],0x4
    jne    Branch114
    xor    al,al
    pop    esi
    ret    0x4
  Branch114:
    mov    eax,DWORD PTR [ecx+0x10]
    add    eax,0xc
    mov    dx,WORD PTR [eax+0x2]
    mov    WORD PTR [esi+0x90],dx
    mov    dx,WORD PTR [eax+0x4]
    mov    WORD PTR [esi+0x1b4],dx
    mov    dx,WORD PTR [eax]
    mov    WORD PTR [esi+0x1be],dx
    mov    cx,WORD PTR [ecx+0xc]
    mov    dx,WORD PTR [esi+0x1b0]
    mov    WORD PTR [esi+0x8e],cx
    mov    ax,WORD PTR [eax+0x6]
    push    edx
    mov    WORD PTR [esi+0x1bc],ax
    add    eax,0xc
    lea    ecx,[esi+0x1d8]
    mov    WORD PTR [esi+0x1ba],ax
    call    R6GameServiceAddresses::ResizeOwnedRecordArray
    mov    ax,WORD PTR [esi+0x1be]
    lea    ecx,[esi+0x1f8]
    push    eax
    call    R6GameServiceAddresses::ResetOwnedRecordRing
    mov    cx,WORD PTR [esi+0x1ba]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x120]
    call    R6GameServiceAddresses::EnsureReceiveBufferCapacity
    test    al,al
    jne    Branch115
    pop    esi
    ret    0x4
  Branch115:
    mov    ecx,esi
    call    R6GameServiceAddresses::EnterOwnerActiveState
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Sample time; nonempty current input refreshes both deadlines with current full intervals. Empty checks probe then
// hard expiry unsigned.
// Hard expiry invokes adjusted CURRENT144; probe expiry refreshes probe then allocates3040 only if current ring
// count is0.
// Build before capacity gate, cache slot/delete old, publish/advance current WORD counters; retain orphan/NULL/raw
// return quirks.
// Return captured time, callback, payload pointer or quotient by path; restore zeroed saved ECX. No local EH.
// R6GameService.dll @ 1005e430 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall UpdateOwnerDeadlines(void *owner)
{
  __asm {
    push    ecx
    push    ebp
    push    esi
    xor    ebp,ebp
    push    edi
    push    ebp
    mov    esi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    call    R6GameServiceAddresses::time
    mov    ecx,DWORD PTR [esi+0x124]
    add    esp,0x4
    cmp    DWORD PTR [ecx],ecx
    je    Branch116
    mov    ecx,DWORD PTR [esi+0x170]
    mov    edx,DWORD PTR [esi+0x178]
    add    ecx,eax
    add    edx,eax
    mov    DWORD PTR [esi+0x174],ecx
    mov    DWORD PTR [esi+0x17c],edx
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret
  Branch116:
    cmp    eax,DWORD PTR [esi+0x17c]
    jbe    Branch119
    cmp    eax,DWORD PTR [esi+0x174]
    jbe    Branch117
    mov    eax,DWORD PTR [esi+0x14c]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [eax+ecx*1]
    mov    eax,DWORD PTR [esi+0x148]
    add    edx,eax
    lea    ecx,[edx+esi*1+0x4]
    call    DWORD PTR [esi+0x144]
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret
  Branch117:
    mov    ecx,DWORD PTR [esi+0x178]
    add    ecx,eax
    cmp    WORD PTR [esi+0x1e0],bp
    mov    DWORD PTR [esi+0x17c],ecx
    jne    Branch119
    push    0x1c
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    cmp    edi,ebp
    je    Branch119
    push    0xc
    mov    DWORD PTR [edi+0x4],R6GameServiceAddresses::ClSRPSegmentVTable
    mov    DWORD PTR [edi+0x14],0xc
    mov    DWORD PTR [edi],R6GameServiceAddresses::clSegmentVTable
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [edi+0x10],eax
    mov    DWORD PTR [edi+0x18],eax
    mov    DWORD PTR [edi],R6GameServiceAddresses::clSRPSegmentVTable
    mov    ax,WORD PTR [esi+0x8e]
    mov    cx,WORD PTR [esi+0x90]
    mov    edx,DWORD PTR [esi+0x8]
    mov    WORD PTR [edi+0xc],ax
    mov    eax,DWORD PTR [edi+0x18]
    mov    DWORD PTR [edi+0x8],edx
    mov    WORD PTR [eax+0x2],cx
    mov    WORD PTR [eax+0x6],0x3040
    mov    eax,DWORD PTR [edi+0x18]
    mov    WORD PTR [eax+0x4],bp
    mov    cx,WORD PTR [esi+0x1e0]
    cmp    cx,WORD PTR [esi+0x1dc]
    jae    Branch119
    mov    edx,DWORD PTR [edi+0x18]
    mov    ax,WORD PTR [esi+0x1e2]
    push    ebx
    mov    WORD PTR [edx+0x8],ax
    mov    edx,DWORD PTR [esi+0x1e8]
    xor    eax,eax
    mov    ax,WORD PTR [esi+0x1e2]
    lea    ecx,[eax+eax*2]
    lea    ebx,[edx+ecx*4]
    mov    ecx,DWORD PTR [edx+ecx*4]
    cmp    ecx,ebp
    je    Branch118
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch118:
    mov    DWORD PTR [ebx],edi
    mov    DWORD PTR [ebx+0x4],ebp
    mov    DWORD PTR [ebx+0x8],ebp
    mov    ax,WORD PTR [esi+0x1e2]
    xor    ecx,ecx
    inc    ax
    mov    cx,WORD PTR [esi+0x1de]
    and    eax,0xffff
    cdq
    idiv    ecx
    inc    WORD PTR [esi+0x1e0]
    pop    ebx
    mov    WORD PTR [esi+0x1e2],dx
  Branch119:
    pop    edi
    pop    esi
    pop    ebp
    pop    ecx
    ret
  }
}

// Native virtual-table prefix: clSRProtocolVTable
// R6GameService.dll data @ 10078294 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSRProtocolVTableRecord {
  R6GameServiceNative::Address DeleteObject; // +0x00
  R6GameServiceNative::Address AppendOwnedRecord; // +0x04
  R6GameServiceNative::Address RejectSRProtocolCall; // +0x08
  R6GameServiceNative::Address clSRProtocol_RejectSRProtocolCall; // +0x0c
  R6GameServiceNative::Address clSRProtocol_RejectSRProtocolCall2; // +0x10
  R6GameServiceNative::Address ReturnZero; // +0x14
};
const clSRProtocolVTableRecord clSRProtocolVTable = {
  R6GameServiceAddresses::DeleteObject,
  R6GameServiceAddresses::AppendOwnedRecord,
  R6GameServiceAddresses::RejectSRProtocolCall,
  R6GameServiceAddresses::clSRProtocol_RejectSRProtocolCall,
  R6GameServiceAddresses::clSRProtocol_RejectSRProtocolCall2,
  R6GameServiceAddresses::ReturnZero,
};
