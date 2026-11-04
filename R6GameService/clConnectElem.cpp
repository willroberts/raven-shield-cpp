#include "native_addresses.h"
#include "native_records.h"

// clConnectElem: primary780c8 -> COL7a1d0 -> type904c0, .?AVclConnectElem@@. Member spellings inferred.

// Construct three list headers and helper16, initialize configuration, and optionally construct stream/datagram owners.
// Eight physical DWORD arguments; feature/field bytes remain late reads of their original stack slots. RET32/owner EAX.
// ENTRY ESP S: bitsS-1c/ownerS-18/memberS-14/headslotS-10/stateS-4; scratch reuses original arguments.
// Preserve eleven-state cleanup, partial publication, global counter/seed timing and unguarded stream-limit call.
// R6GameService.dll @ 100571c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeTransportRecord(
    void *owner,uint featureMask,uint identifier,uint field0c,uint field0d,uint idleLimit,
    uint socketArgument0,uint socketArgument1,uint installOptionalBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectElemCtorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   ebp
    xor    ebp,ebp
    push   esi
    mov    DWORD PTR [esp+0xc],ebp
    mov    eax,DWORD PTR [esp+0x48]
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0x10],esi
    je     Branch1
    mov    DWORD PTR [esi+0x4],0x100780fc
    mov    ebp,0x1
  Branch1:
    push   edi
    lea    edi,[esi+0x20]
    or     ebp,0x2
    mov    DWORD PTR [esp+0x18],edi
    mov    DWORD PTR [edi+0x8],0x100780f4
    mov    DWORD PTR [esp+0x10],ebp
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [esp+0x1c],ecx
    lea    eax,[esp+0x4c]
    mov    DWORD PTR [esp+0x28],0x3
    push   eax
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerList_PAVclGameMessageVTable
    push   0x1
    lea    ecx,[esi+0x2c]
    mov    DWORD PTR [esp+0x2c],0x4
    call   R6GameServiceAddresses::clSendMsgQueue_InitializeCompactRecordList
    push   0x1
    lea    ecx,[esi+0x3c]
    mov    BYTE PTR [esp+0x2c],0x5
    call   R6GameServiceAddresses::InitializeCompactRecordList
    push   0x10
    mov    DWORD PTR [esi],R6GameServiceAddresses::clConnectElemVTable
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x4c],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x28],0x7
    je     Branch2
    push   0x1
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructSharedCryptoContext
    jmp    Branch3
  Branch2:
    xor    eax,eax
  Branch3:
    mov    edx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [esi+0x4c],eax
    mov    BYTE PTR [esi+0x50],bl
    mov    ecx,DWORD PTR ds:0x1009037c
    mov    al,BYTE PTR [esp+0x38]
    mov    DWORD PTR [esi+0x5c],ecx
    mov    ecx,DWORD PTR ds:0x1009037c
    mov    BYTE PTR [esp+0x28],0x6
    inc    ecx
    mov    DWORD PTR ds:0x1009037c,ecx
    mov    cl,BYTE PTR [esp+0x3c]
    mov    DWORD PTR [esi+0x8],edx
    mov    edx,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esi+0x60],ebx
    mov    WORD PTR [esi+0x64],bx
    mov    BYTE PTR [esi+0xc],al
    mov    BYTE PTR [esi+0xd],cl
    mov    DWORD PTR [esi+0x10],edx
    mov    DWORD PTR [esi+0x54],ebx
    mov    DWORD PTR [esi+0x58],ebx
    mov    al,ds:0x10094588
    cmp    al,bl
    jne    Branch4
    push   ebx
    call   R6GameServiceAddresses::time
    push   eax
    call   R6GameServiceAddresses::srand
    add    esp,0x8
    mov    BYTE PTR ds:0x10094588,0x1
  Branch4:
    test   BYTE PTR [esp+0x30],0x2
    je     Branch7
    push   0x54
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x38],edi
    cmp    edi,ebx
    je     Branch5
    or     ebp,0x8
    mov    DWORD PTR [edi+0x4],0x10075bc0
    mov    DWORD PTR [esp+0x10],ebp
    push   ebx
    mov    ecx,edi
    mov    BYTE PTR [esp+0x2c],0x9
    call   R6GameServiceAddresses::ConstructQueuedConnection
    mov    DWORD PTR [edi],R6GameServiceAddresses::clTCPClientVTable
    mov    DWORD PTR [esp+0x28],0x8
    mov    ecx,edi
    jmp    Branch6
  Branch5:
    xor    ecx,ecx
  Branch6:
    mov    eax,DWORD PTR [esi+0x10]
    mov    BYTE PTR [esp+0x28],0x6
    push   eax
    mov    DWORD PTR [esi+0x14],ecx
    call   R6GameServiceAddresses::SetReceiveIdleLimit
    jmp    Branch8
  Branch7:
    mov    DWORD PTR [esi+0x14],ebx
  Branch8:
    mov    al,BYTE PTR [esp+0x30]
    pop    edi
    test   al,0x8
    je     Branch10
    push   0x20
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x34],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x24],0xa
    je     Branch9
    mov    ecx,DWORD PTR [esp+0x44]
    mov    edx,DWORD PTR [esp+0x40]
    push   0x1
    push   ecx
    push   edx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructDatagramSocketOwner
    mov    DWORD PTR [esi+0x18],eax
    jmp    Branch11
  Branch9:
    xor    eax,eax
    mov    DWORD PTR [esi+0x18],eax
    jmp    Branch11
  Branch10:
    mov    DWORD PTR [esi+0x18],ebx
  Branch11:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    DWORD PTR [esi+0x1c],ebx
    mov    eax,esi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x20
  }
}

// Resolve into current +60, start optional stream then datagram, and retry rand until nonzero for datagram context.
// Resolver status and provider update status are ignored; stream/datagram AL0 returns raw failure EAX.
// Cache port after resolution, load datagram word after stream; write low16(port+1) only after update. RET12.
// R6GameService.dll @ 100578b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StartTransportChannels(
    void *owner,const char *address,uint port,uint datagramWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    lea    edi,[esi+0x60]
    push   edi
    push   eax
    call   R6GameServiceAddresses::ResolveIPv4Address
    mov    ecx,DWORD PTR [esi+0x14]
    mov    ebx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch12
    mov    edx,DWORD PTR [edi]
    push   ebx
    push   edx
    call   R6GameServiceAddresses::ConnectNumericQueuedConnection
    test   al,al
    jne    Branch12
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  Branch12:
    mov    ecx,DWORD PTR [esi+0x18]
    test   ecx,ecx
    je     Branch16
    mov    eax,DWORD PTR [esp+0x18]
    push   0x1
    push   0x0
    push   eax
    push   0x0
    call   R6GameServiceAddresses::OpenDatagramSocket
    test   al,al
    jne    Branch13
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  Branch13:
    call   R6GameServiceAddresses::rand
    test   eax,eax
    mov    DWORD PTR [esi+0x58],eax
    jne    Branch15
  Branch14:
    call   R6GameServiceAddresses::rand
    test   eax,eax
    mov    DWORD PTR [esi+0x58],eax
    je     Branch14
  Branch15:
    mov    ecx,DWORD PTR [esi+0x58]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::SendTransportControlRecordWithDecimalValue
    mov    ecx,esi
    call   R6GameServiceAddresses::UpdateTransportProvider
    inc    ebx
    mov    WORD PTR [esi+0x64],bx
  Branch16:
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0xc
  }
}

// Detach one receive-queue message; class0/tag6 or0xdb dispatch then CURRENT message deleting slot1 and return0.
// Other class/tag records remain caller-owned; dispatch failure leaves detached message unreleased. No local EH.
// R6GameService.dll @ 10058400 : complete native control/access order and raw ABI retained.
__declspec(naked) undefined4 *__fastcall PopAndDispatchControlRecord(void *owner)
{
  __asm {
    push   esi
    push   edi
    mov    edi,ecx
    lea    ecx,[edi+0x3c]
    call   R6GameServiceAddresses::RemoveFirstCompactRecord
    mov    esi,eax
    test   esi,esi
    je     Branch18
    mov    al,BYTE PTR [esi+0xc]
    test   al,al
    jne    Branch18
    mov    al,BYTE PTR [esi+0xd]
    cmp    al,0x6
    je     Branch17
    cmp    al,0xdb
    jne    Branch18
    mov    eax,DWORD PTR [esi+0x14]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::DispatchProviderControlPayload
    mov    edx,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR [edx]
    pop    edi
    xor    eax,eax
    pop    esi
    ret
  Branch17:
    mov    eax,DWORD PTR [esi+0x14]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::StoreControlValueAndAcknowledge
    mov    edx,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR [edx]
    pop    edi
    xor    eax,eax
    pop    esi
    ret
  Branch18:
    mov    eax,esi
    pop    edi
    pop    esi
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069300 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    test   eax,eax
    je     Branch19
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x68
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch19:
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 1006931a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x2
    test   eax,eax
    je     Branch20
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xc
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch20:
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069334 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp+0x20]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 1006933c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListOwnerAndSentinel
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069347 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x2c
    jmp    R6GameServiceAddresses::ForwardCompactPointerListDestroy
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069352 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x3c
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListAndSentinel
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 1006935d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x20]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069367 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0xc]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 10069371 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind10(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x8
    test   eax,eax
    je     Branch21
    mov    ecx,DWORD PTR [ebp+0xc]
    add    ecx,0x54
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch21:
    ret
  }
}

// Apply exact constructor cleanup using inherited original ENTRY ESP, saved bits/owner and live scratch words.
// R6GameService.dll @ 1006938b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordUnwind11(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0xc]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select clConnectElem constructor eleven-state metadata and tail current CRT dispatch.
// R6GameService.dll @ 10069395 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectElemCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeTransportRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083df8: exact clConnectElem constructor unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry InitializeTransportRecordUnwindMap[11] = {
  {-1, R6GameServiceAddresses::InitializeTransportRecordUnwind1},
  {0x0, R6GameServiceAddresses::InitializeTransportRecordUnwind2},
  {0x1, 0x0},
  {0x2, R6GameServiceAddresses::InitializeTransportRecordUnwind4},
  {0x0, R6GameServiceAddresses::InitializeTransportRecordUnwind5},
  {0x4, R6GameServiceAddresses::InitializeTransportRecordUnwind6},
  {0x5, R6GameServiceAddresses::InitializeTransportRecordUnwind7},
  {0x6, R6GameServiceAddresses::InitializeTransportRecordUnwind8},
  {0x6, R6GameServiceAddresses::InitializeTransportRecordUnwind9},
  {0x8, R6GameServiceAddresses::InitializeTransportRecordUnwind10},
  {0x6, R6GameServiceAddresses::InitializeTransportRecordUnwind11},
};

// R6GameService.dll data @ 10083e50: exact clConnectElem constructor unwind map or FuncInfo.
const R6GameServiceNative::FuncInfo InitializeTransportRecordExceptionInfo = {
  0x19930520,
  0xb,
  R6GameServiceAddresses::InitializeTransportRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Select the associated native FuncInfo and tail current CRT dispatch.
// R6GameService.dll @ 100693d3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectElemAlternateCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the associated native FuncInfo and tail current CRT dispatch.
// R6GameService.dll @ 10069486 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectElemDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyTransportRecordMembersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 10083eb4: exact associated unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry InitializeTransportRecordWithOptionalConnectionUnwindMap[5] = {
  {-1, R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwind1},
  {-1, R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwind2},
  {0x1, R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwind3},
  {0x2, R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwind4},
  {0x3, R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwind5},
};

// R6GameService.dll data @ 10083edc: exact associated unwind map or FuncInfo.
const R6GameServiceNative::FuncInfo InitializeTransportRecordWithOptionalConnectionExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::InitializeTransportRecordWithOptionalConnectionUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 10083ef8: exact associated unwind map or FuncInfo.
const R6GameServiceNative::UnwindEntry DestroyTransportRecordMembersUnwindMap[8] = {
  {-1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind1},
  {0x0, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind2},
  {0x1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind3},
  {0x1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind4},
  {0x1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind5},
  {0x0, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind6},
  {-1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind7},
  {-1, R6GameServiceAddresses::DestroyTransportRecordMembersUnwind8},
};

// R6GameService.dll data @ 10083f38: exact associated unwind map or FuncInfo.
const R6GameServiceNative::FuncInfo DestroyTransportRecordMembersExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::DestroyTransportRecordMembersUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Destroy members before sampling the current deletion flag; optionally release storage and return the cached receiver.
// R6GameService.dll @ 100573a0 : full physical flags word; only bit 0 controls storage ownership.
void * __thiscall DestroyTransportRecordAndMaybeFree(void *owner,uint deleteFlags)
{
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyTransportRecordMembers)(owner);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Update the provider, close current channels in order and clear datagram state only after its successful close.
// R6GameService.dll @ 10057940 : test only child AL; retain the last full result above the final success byte.
uint __fastcall ShutdownTransportChannels(void *owner)
{
  using OperationABI = uint (__fastcall *)(void *);
  uint result = ((OperationABI)R6GameServiceAddresses::UpdateTransportProvider)(owner);
  void *stream = *(void **)((byte *)owner + 0x14);
  if (stream != nullptr) {
    result = ((OperationABI)R6GameServiceAddresses::CloseConnectionAndClearSendQueue)(stream);
    if ((byte)result == 0) return result;
  }
  void *datagram = *(void **)((byte *)owner + 0x18);
  if (datagram != nullptr) {
    result = ((OperationABI)R6GameServiceAddresses::CloseDatagramSocket)(datagram);
    if ((byte)result == 0) return result;
    *(uint *)((byte *)owner + 0x54) = 0;
    *(uint *)((byte *)owner + 0x58) = 0;
  }
  return (result & 0xffffff00) | 1;
}

namespace {
// Inferred scope guard for the eight native member-destruction states; saved pointers remain live cleanup inputs.
struct TransportRecordDestructionCleanup {
  byte *savedOwner;
  byte *receiveList; // Reused as the later range-output word.
  byte *currentList;
  int state;
  // Continue only the native pending member cleanups, preserving entered no-retry states.
  ~TransportRecordDestructionCleanup() noexcept(false) {
    using CleanupABI = void (__fastcall *)(void *);
    while (state >= 0) {
      switch (state) {
      case 0:
        state = -1;
        ((CleanupABI)R6GameServiceAddresses::thunk_DestroyEmbeddedListOwnerAndSentinel)(
            (void *)((uint)savedOwner + 0x20));
        break;
      case 1:
        state = 0;
        ((CleanupABI)R6GameServiceAddresses::ForwardCompactPointerListDestroy)((void *)((uint)savedOwner + 0x2c));
        break;
      case 2:
        state = 1;
        ((CleanupABI)R6GameServiceAddresses::thunk_DestroyEmbeddedListAndSentinel)((void *)((uint)savedOwner + 0x3c));
        break;
      case 3:
        state = 1;
        currentList = receiveList == nullptr ? nullptr : receiveList + 4;
        ((CleanupABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(currentList);
        break;
      case 4:
        state = 1;
        ((CleanupABI)R6GameServiceAddresses::list_node_support_NoOp)(currentList);
        break;
      case 5: {
        state = 0;
        byte *headSlot = currentList == nullptr ? nullptr : currentList + 4;
        ((CleanupABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(headSlot);
        break;
      }
      case 6:
        state = -1;
        savedOwner = currentList == nullptr ? nullptr : currentList + 4;
        ((CleanupABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(savedOwner);
        break;
      case 7:
        state = -1;
        ((CleanupABI)R6GameServiceAddresses::list_node_support_NoOp)(savedOwner);
        break;
      }
    }
  }
};
}

// Shut down channels, release current resources, then destroy receive/send/game lists with native staged ownership.
// R6GameService.dll @ 100575f0 : eight cleanup states; dangling members and cached raw frees are preserved.
uint __fastcall DestroyTransportRecordMembers(void *owner)
{
  using OperationABI = uint (__fastcall *)(void *);
  using DeleteABI = uint (__thiscall *)(void *,uint);
  using FreeABI = uint (__stdcall *)(void *,uint);
  using FirstABI = uint * (__thiscall *)(void *,uint *);
  using RangeABI = uint * (__thiscall *)(void *,uint *,uint,uint);
  TransportRecordDestructionCleanup cleanup{(byte *)owner, nullptr, nullptr, -1};
  *(uint *)owner = R6GameServiceAddresses::clConnectElemVTable;
  cleanup.state = 2;
  ((OperationABI)R6GameServiceAddresses::ShutdownTransportChannels)(owner);
  void *stream = *(void **)((byte *)owner + 0x14);
  if (stream != nullptr) {
    byte *table = *(byte **)stream;
    (*(DeleteABI *)table)(stream,1);
  }
  void *datagram = *(void **)((byte *)owner + 0x18);
  if (datagram != nullptr) {
    ((OperationABI)R6GameServiceAddresses::DestroyDatagramSocketOwner)(datagram);
    TailFreeThroughGlobalAllocator(datagram);
  }
  void *helper = *(void **)((byte *)owner + 0x4c);
  if (helper != nullptr) {
    using CryptoDestroyABI = void (__fastcall *)(void *);
    ((CryptoDestroyABI)R6GameServiceAddresses::DestroySharedCryptoContext)(helper);
    TailFreeThroughGlobalAllocator(helper);
  }
  byte *receiveList = (byte *)owner + 0x3c;
  cleanup.receiveList = receiveList;
  *(uint *)receiveList = R6GameServiceAddresses::clPointerList_PAVclRcvElementVTable;
  *(byte *)&cleanup.state = 3;
  ((OperationABI)R6GameServiceAddresses::InvokePointerListClearRange)(receiveList);
  byte *receiveHeadSlot = receiveList + 4;
  cleanup.currentList = receiveHeadSlot;
  *(byte *)&cleanup.state = 4;
  ((OperationABI)R6GameServiceAddresses::ReleaseListNodesRetainHeader)(receiveHeadSlot);
  void *receiveHead = *(void **)receiveHeadSlot;
  ((FreeABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(receiveHead,1);
  byte *sendList = (byte *)owner + 0x2c;
  cleanup.currentList = sendList;
  *(uint *)sendList = R6GameServiceAddresses::clPointerList_PAVclSendElementVTable;
  uint sendEnd = *(uint *)(sendList + 4);
  byte *sendHeadSlot = sendList + 4;
  uint sendBegin = sendEnd;
  byte *sendTable = *(byte **)sendList;
  *(byte *)&cleanup.state = 5;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(sendHeadSlot,&sendBegin);
  (*(RangeABI *)(sendTable + 0x10))(sendList,(uint *)&cleanup.receiveList,sendBegin,sendEnd);
  *(byte *)&cleanup.state = 0;
  ((OperationABI)R6GameServiceAddresses::ReleaseNodesAndSentinel)(sendHeadSlot);
  byte *gameList = (byte *)owner + 0x20;
  cleanup.currentList = gameList;
  *(uint *)gameList = R6GameServiceAddresses::clPointerList_PAVclGameMessageVTable;
  uint gameEnd = *(uint *)(gameList + 4);
  byte *gameHeadSlot = gameList + 4;
  uint gameBegin = gameEnd;
  byte *gameTable = *(byte **)gameList;
  cleanup.state = 6;
  ((FirstABI)R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot)(gameHeadSlot,&gameBegin);
  (*(RangeABI *)(gameTable + 0x10))(gameList,(uint *)&cleanup.receiveList,gameBegin,gameEnd);
  cleanup.savedOwner = gameHeadSlot;
  cleanup.state = 7;
  ((OperationABI)R6GameServiceAddresses::ReleaseListNodesRetainHeader)(gameHeadSlot);
  void *gameHead = *(void **)gameHeadSlot;
  uint result = ((FreeABI)R6GameServiceAddresses::ReleaseMemoryIgnoringSize)(gameHead,1);
  cleanup.state = -1;
  return result;
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 100693e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListOwnerAndSentinel
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 100693eb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x2c
    jmp    R6GameServiceAddresses::ForwardCompactPointerListDestroy
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 100693f6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x3c
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListAndSentinel
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 10069401 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je     Branch29
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch30
  Branch29:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch30:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 10069428 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 10069430 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind6(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x10],0x0
    je     Branch31
    mov    eax,DWORD PTR [ebp-0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x38],eax
    jmp    Branch32
  Branch31:
    mov    DWORD PTR [ebp-0x38],0x0
  Branch32:
    mov    ecx,DWORD PTR [ebp-0x38]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 10069457 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x10],0x0
    je     Branch33
    mov    eax,DWORD PTR [ebp-0x10]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x18],eax
    jmp    Branch34
  Branch33:
    mov    DWORD PTR [ebp-0x18],0x0
  Branch34:
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Apply exact inherited destructor-frame cleanup, including current scratch writes and unconditional targets.
// R6GameService.dll @ 1006947e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyTransportRecordMembersUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Construct three headers/helper, then capture the supplied connection and idle limit AFTER seed initialization.
// Query endpoint into +60/local WORD and set captured idle before publishing connection/configuration fields.
// Keep +60 untouched for NULL connection; preserve late scalar/byte reads and cached connection/idle. RET28/owner EAX.
// ENTRY ESP S: saved ownerS-10/stateS-4; original argument7S+1c becomes helper raw scratch under five-state cleanup.
// R6GameService.dll @ 100574a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeTransportRecordWithOptionalConnection(
    void *owner,void *optionalConnection,uint reservedValue,uint identifier,uint field0c,uint field0d,
    uint idleLimit,uint initializeBaseWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectElemAlternateCtorEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    xor    ebx,ebx
    push   ebp
    mov    DWORD PTR [esp+0x8],ebx
    mov    eax,DWORD PTR [esp+0x38]
    push   esi
    mov    esi,ecx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [esp+0x14],esi
    je     Branch35
    mov    DWORD PTR [esi+0x4],0x100780fc
  Branch35:
    mov    DWORD PTR [esi+0x28],0x100780f4
    lea    ecx,[esi+0x24]
    lea    eax,[esp+0x40]
    mov    DWORD PTR [esp+0x20],ebx
    push   eax
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esi+0x20],R6GameServiceAddresses::clPointerList_PAVclGameMessageVTable
    push   0x1
    lea    ecx,[esi+0x2c]
    mov    DWORD PTR [esp+0x24],0x1
    call   R6GameServiceAddresses::clSendMsgQueue_InitializeCompactRecordList
    push   0x1
    lea    ecx,[esi+0x3c]
    mov    BYTE PTR [esp+0x24],0x2
    call   R6GameServiceAddresses::InitializeCompactRecordList
    push   0x10
    mov    DWORD PTR [esi],R6GameServiceAddresses::clConnectElemVTable
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x40],eax
    cmp    eax,ebx
    mov    BYTE PTR [esp+0x20],0x4
    je     Branch36
    push   0x1
    push   0x1
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructSharedCryptoContext
    jmp    Branch37
  Branch36:
    xor    eax,eax
  Branch37:
    mov    DWORD PTR [esi+0x4c],eax
    mov    BYTE PTR [esi+0x50],bl
    mov    ecx,DWORD PTR ds:0x1009037c
    mov    BYTE PTR [esp+0x20],0x3
    mov    DWORD PTR [esi+0x5c],ecx
    mov    ecx,DWORD PTR ds:0x1009037c
    mov    al,ds:0x10094588
    inc    ecx
    cmp    al,bl
    mov    DWORD PTR ds:0x1009037c,ecx
    jne    Branch38
    push   ebx
    call   R6GameServiceAddresses::time
    push   eax
    call   R6GameServiceAddresses::srand
    add    esp,0x8
    mov    BYTE PTR ds:0x10094588,0x1
  Branch38:
    mov    edi,DWORD PTR [esp+0x28]
    mov    ebp,DWORD PTR [esp+0x3c]
    cmp    edi,ebx
    je     Branch39
    lea    edx,[esp+0x10]
    lea    eax,[esi+0x60]
    push   edx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::QueryLocalEndpointAlwaysSuccess
    push   ebp
    mov    ecx,edi
    call   R6GameServiceAddresses::SetReceiveIdleLimit
  Branch39:
    mov    ecx,DWORD PTR [esp+0x30]
    mov    al,BYTE PTR [esp+0x38]
    mov    dl,BYTE PTR [esp+0x34]
    mov    DWORD PTR [esi+0x8],ecx
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    BYTE PTR [esi+0xd],al
    mov    DWORD PTR [esi+0x14],edi
    mov    WORD PTR [esi+0x64],bx
    mov    BYTE PTR [esi+0xc],dl
    mov    DWORD PTR [esi+0x10],ebp
    mov    DWORD PTR [esi+0x54],ebx
    mov    DWORD PTR [esi+0x58],ebx
    mov    DWORD PTR [esi+0x1c],ecx
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi+0x18],ebx
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x1c
  }
}

// Apply exact inherited alternate-constructor frame cleanup using current owner or original argument scratch.
// R6GameService.dll @ 100693a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordWithOptionalConnectionUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x1c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Apply exact inherited alternate-constructor frame cleanup using current owner or original argument scratch.
// R6GameService.dll @ 100693a8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordWithOptionalConnectionUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListOwnerAndSentinel
  }
}

// Apply exact inherited alternate-constructor frame cleanup using current owner or original argument scratch.
// R6GameService.dll @ 100693b3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordWithOptionalConnectionUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x2c
    jmp    R6GameServiceAddresses::ForwardCompactPointerListDestroy
  }
}

// Apply exact inherited alternate-constructor frame cleanup using current owner or original argument scratch.
// R6GameService.dll @ 100693be : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordWithOptionalConnectionUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x3c
    jmp    R6GameServiceAddresses::thunk_DestroyEmbeddedListAndSentinel
  }
}

// Apply exact inherited alternate-constructor frame cleanup using current owner or original argument scratch.
// R6GameService.dll @ 100693c9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeTransportRecordWithOptionalConnectionUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x1c]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Native virtual-table prefix: clConnectElemVTable
// R6GameService.dll data @ 100780c8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clConnectElemVTableRecord {
  R6GameServiceNative::Address DestroyTransportRecordAndMaybeFree; // +0x00
  R6GameServiceNative::Address StartTransportChannels; // +0x04
  R6GameServiceNative::Address ShutdownTransportChannels; // +0x08
  R6GameServiceNative::Address ReceiveRecordWithSourceThunk; // +0x0c
};
const clConnectElemVTableRecord clConnectElemVTable = {
  R6GameServiceAddresses::DestroyTransportRecordAndMaybeFree,
  R6GameServiceAddresses::StartTransportChannels,
  R6GameServiceAddresses::ShutdownTransportChannels,
  R6GameServiceAddresses::ReceiveRecordWithSourceThunk,
};
