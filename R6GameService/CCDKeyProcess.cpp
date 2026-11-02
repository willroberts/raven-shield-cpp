#include "native_addresses.h"
#include "native_records.h"

// Identified CCDKeyProcess members and associated cleanup; original full layout remains unresolved.

// Constructs containers, clears native byte ranges and publishes hash/message owners with exact lifetime gaps.
// R6GameService.dll @ 10023a00 : C++ construction with native bitmap/state slots and reused incoming argument.
__declspec(naked) void * __thiscall ConstructCCDKeyProcess
    (void *owner,uint localPortWord,uint initializeSecondaryBaseWord)
{
  byte *entryFrame;
  byte *nativeFrame;
  byte *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCCDKeyConstruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    entryFrame,esp
    mov    receiver,ecx
  }
  uint bitmap = 0;
  *(uint *)(entryFrame + 0x10) = bitmap;
  uint initializeBase = *(uint *)(entryFrame + 0x30);
  *(byte **)(entryFrame + 0x14) = receiver;
  if (initializeBase != 0) {
    *(uint *)(receiver + 4) = 0x10076a00;
    bitmap = 1;
  }
  __asm {
    push   ebp
    mov    nativeFrame,esp
  }
  using ListABI = void (__thiscall *)(void *,byte *,uint *);
  using CircularABI = void (__thiscall *)(void *);
  using ReleaseABI = uint (__thiscall *)(void *,uint);
  using MessageABI = void * (__thiscall *)(void *,uint,uint);
  *(uint *)receiver = R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable;
  void *member = receiver + 8;
  bitmap |= 4;
  *(void **)(nativeFrame + 0x1c) = member;
  *(uint *)(nativeFrame + 0x14) = bitmap;
  *(uint *)((byte *)member + 0xc) = 0x100769f8;
  *(uint *)(nativeFrame + 0x28) = 3;
  ((ListABI)R6GameServiceAddresses::InitializeThirtyByteListStorage)
      (member,nativeFrame + 0x13,(uint *)(nativeFrame + 0x34));
  member = receiver + 0x18;
  bitmap |= 8;
  *(void **)(nativeFrame + 0x1c) = member;
  *(uint *)(nativeFrame + 0x14) = bitmap;
  *(uint *)((byte *)member + 0xc) = 0x100769f0;
  *(uint *)(nativeFrame + 0x28) = 6;
  ((ListABI)R6GameServiceAddresses::InitializeTreeSentinel)
      (member,nativeFrame + 0x13,(uint *)(nativeFrame + 0x34));
  member = receiver + 0x28;
  bitmap |= 0x10;
  *(void **)(nativeFrame + 0x1c) = member;
  *(uint *)(nativeFrame + 0x14) = bitmap;
  *(uint *)((byte *)member + 0xc) = 0x100769e8;
  *(uint *)(nativeFrame + 0x28) = 9;
  ((ListABI)R6GameServiceAddresses::InitializeTreeSentinel)
      (member,nativeFrame + 0x13,(uint *)(nativeFrame + 0x34));
  member = receiver + 0x38;
  bitmap |= 0x20;
  *(void **)(nativeFrame + 0x1c) = member;
  *(uint *)(nativeFrame + 0x14) = bitmap;
  *(uint *)((byte *)member + 0xc) = 0x100769e0;
  *(uint *)(nativeFrame + 0x28) = 0xc;
  ((ListABI)R6GameServiceAddresses::InitializeTreeSentinel)
      (member,nativeFrame + 0x13,(uint *)(nativeFrame + 0x34));
  *(uint *)(nativeFrame + 0x28) = 0xa;
  byte *lastMember = receiver + 0x48;
  bitmap |= 0x40;
  *(uint *)(nativeFrame + 0x14) = bitmap;
  // This incoming full flag word becomes scratch; earlier initializers see it before the overwrite.
  *(byte **)(nativeFrame + 0x34) = lastMember;
  *(uint *)(lastMember + 0xc) = 0x100769d8;
  *(byte *)(nativeFrame + 0x28) = 0xe;
  ((CircularABI)R6GameServiceAddresses::InitializeCircularListStorage)(lastMember);
  ushort port = *(ushort *)(nativeFrame + 0x30);
  *(uint *)receiver = R6GameServiceAddresses::CCDKeyProcessVTable;
  *(uint *)(receiver + 0xd8) = 0;
  *(uint *)(receiver + 0xc8) = 0;
  *(uint *)(receiver + 0xcc) = 0;
  *(uint *)(receiver + 0xd0) = 0;
  *(uint *)(receiver + 0xd4) = 0;
  *(ushort *)(receiver + 0x5c) = port;
  *(byte *)(receiver + 0x5e) = 0;
  uint lastCount = *(uint *)(lastMember + 4);
  *(uint *)(nativeFrame + 0x28) = 0xf;
  if (lastCount != 0) {
    uint head = *(uint *)lastMember;
    uint root = *(uint *)(head + 4);
    ((ReleaseABI)R6GameServiceAddresses::ReleaseFirstWordPayloadTreeNodes)(lastMember,root);
    head = *(uint *)lastMember;
    *(uint *)(head + 8) = head;
    head = *(uint *)lastMember;
    *(uint *)(head + 4) = 0;
    head = *(uint *)lastMember;
    *(uint *)(head + 0xc) = head;
    *(uint *)(lastMember + 4) = 0;
  }
  __asm {
    push   0x1
  }
  for (uint word = 0; word < 0xe; ++word) *(uint *)(receiver + 0x64 + word * 4) = 0;
  *(byte *)(receiver + 0x9c) = 0;
  for (uint word = 0; word < 0xa; ++word) *(uint *)(receiver + 0x9d + word * 4) = 0;
  void *hash;
  __asm {
    call   R6GameServiceAddresses::CreateRegisteredHashAlgorithmThunk
    push   0x20
    mov    hash,eax
  }
  *(void **)(receiver + 0x60) = hash;
  void *pendingMessage;
  __asm {
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    pendingMessage,eax
  }
  *(void **)(nativeFrame + 0x34) = pendingMessage;
  *(byte *)(nativeFrame + 0x28) = 0x10;
  __asm {
    pop    ebp
  }
  if (pendingMessage != nullptr) {
    uint currentPort = *(uint *)(entryFrame + 0x2c);
    void *message = ((MessageABI)R6GameServiceAddresses::ConstructCMessageBuffer)(pendingMessage,currentPort,1);
    *(void **)(receiver + 0x58) = message;
  } else {
    *(uint *)(receiver + 0x58) = 0;
  }
  __asm {
    mov    esi,receiver
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x8
  }
}

// Runs the separate destructor body, tests late low deletion bit, optionally releases storage and returns cached owner.
// R6GameService.dll @ 10023bf0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void * __thiscall DestroyCCDKeyProcess(void *owner,uint deletingFlagWord)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyServiceObject
    test   BYTE PTR [esp+0x8],0x1
    je     Branch5
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch5:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Deletes current message owner, frees payload words through ordered traversal, releases hash and containers, then restores base table.
// R6GameService.dll @ 10023f30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall DestroyServiceObject(undefined4 *service)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCCDKeyDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::CCDKeyProcessVTable
    mov    ecx,DWORD PTR [esi+0x58]
    mov    DWORD PTR [esp+0x20],0x5
    test   ecx,ecx
    je     Branch6
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch6:
    lea    ecx,[esi+0x8]
    mov    DWORD PTR [esi+0x58],0x0
    call   R6GameServiceAddresses::ClearBufferedRecordTree
    lea    ecx,[esi+0x18]
    call   R6GameServiceAddresses::ClearRecordTreeVariantOne
    mov    eax,DWORD PTR [esi+0x28]
    lea    ebx,[esi+0x28]
    mov    edi,DWORD PTR [eax+0x8]
    cmp    edi,eax
    je     Branch8
  Branch7:
    mov    eax,DWORD PTR [edi+0x14]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    push   edi
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    edi,eax
    mov    eax,DWORD PTR [ebx]
    add    esp,0x8
    cmp    edi,eax
    jne    Branch7
  Branch8:
    mov    ecx,ebx
    call   R6GameServiceAddresses::ClearRecordTreeVariantTwo
    mov    eax,DWORD PTR [esi+0x38]
    lea    edi,[esi+0x38]
    mov    ebp,DWORD PTR [eax+0x8]
    cmp    ebp,eax
    je     Branch10
  Branch9:
    mov    eax,DWORD PTR [ebp+0x10]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    push   ebp
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebp,eax
    mov    eax,DWORD PTR [edi]
    add    esp,0x8
    cmp    ebp,eax
    jne    Branch9
  Branch10:
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebp,ebp
    cmp    eax,ebp
    je     Branch11
    mov    ecx,DWORD PTR [edi]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,edi
    push   edx
    call   R6GameServiceAddresses::ordered_tree_support_ReleasePlainTreeNodes2
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x4],ebp
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],ebp
  Branch11:
    mov    eax,DWORD PTR [esi+0x4c]
    lea    ebp,[esi+0x48]
    test   eax,eax
    je     Branch12
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    edx,DWORD PTR [ecx+0x4]
    mov    ecx,ebp
    push   edx
    call   R6GameServiceAddresses::ReleaseFirstWordPayloadTreeNodes
    mov    eax,DWORD PTR [ebp+0x0]
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [eax+0x4],ecx
    mov    eax,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [ebp+0x4],ecx
  Branch12:
    mov    ecx,DWORD PTR [esi+0x60]
    push   ecx
    call   R6GameServiceAddresses::ReleaseHashAlgorithmOrRegistry
    mov    DWORD PTR [esp+0x14],ebp
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x20],0x6
    call   R6GameServiceAddresses::ClearFirstWordBufferedTree
    mov    ecx,ebp
    mov    BYTE PTR [esp+0x20],0x4
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x7
    call   R6GameServiceAddresses::ClearRecordTreeVariantThree
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x3
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    edi,ebx
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x8
    call   R6GameServiceAddresses::ClearRecordTreeVariantTwo
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x2
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    edi,[esi+0x18]
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x9
    call   R6GameServiceAddresses::ClearRecordTreeVariantOne
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x1
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    edi,[esi+0x8]
    mov    DWORD PTR [esp+0x14],edi
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0xa
    call   R6GameServiceAddresses::ClearBufferedRecordTree
    mov    ecx,edi
    mov    BYTE PTR [esp+0x20],0x0
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret
  }
}

// For construction bit1, forwards saved owner+0xdc to genuine no-op; otherwise returns the masked zero.
// R6GameService.dll @ 10064c40 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessUnwind(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x1
    test   eax,eax
    je     Branch13
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0xdc
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch13:
    ret
  }
}

// Restores the saved owner first word to allocator-base table0x10075bdc through the shared reset body.
// R6GameService.dll @ 10064c5d : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// For construction bit4, forwards current saved subobject+0x10 to genuine no-op, retaining bitmap bits.
// R6GameService.dll @ 10064c65 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x4
    test   eax,eax
    je     Branch14
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch14:
    ret
  }
}

// Forwards the address of original second argument slot to genuine no-op.
// R6GameService.dll @ 10064c7f : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind3(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-destroys the completed member at saved owner+8.
// R6GameService.dll @ 10064c87 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::TailForwardTreeCleanup
  }
}

// For construction bit8, forwards current saved subobject+0x10 to genuine no-op, retaining bitmap bits.
// R6GameService.dll @ 10064c92 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x8
    test   eax,eax
    je     Branch15
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch15:
    ret
  }
}

// Forwards the address of original second argument slot to genuine no-op.
// R6GameService.dll @ 10064cac : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind6(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-destroys the completed member at saved owner+0x18.
// R6GameService.dll @ 10064cb4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup
  }
}

// For construction bit0x10, forwards current saved subobject+0x10 to genuine no-op.
// R6GameService.dll @ 10064cbf : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x10
    test   eax,eax
    je     Branch16
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch16:
    ret
  }
}

// Forwards the address of original second argument slot to genuine no-op.
// R6GameService.dll @ 10064cd9 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind9(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-destroys the completed member at saved owner+0x28.
// R6GameService.dll @ 10064ce1 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x28
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup2
  }
}

// For construction bit0x20, forwards current saved subobject+0x10 to genuine no-op.
// R6GameService.dll @ 10064cec : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind11(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x20
    test   eax,eax
    je     Branch17
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch17:
    ret
  }
}

// Forwards the address of original second argument slot to genuine no-op.
// R6GameService.dll @ 10064d06 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind12(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Tail-destroys the completed member at saved owner+0x38.
// R6GameService.dll @ 10064d0e : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind13(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x38
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup3
  }
}

// For construction bit0x40, forwards current second argument value+0x10 to genuine no-op.
// R6GameService.dll @ 10064d19 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind14(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    and    eax,0x40
    test   eax,eax
    je     Branch18
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch18:
    ret
  }
}

// Tail-destroys the completed member at saved owner+0x48.
// R6GameService.dll @ 10064d33 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind15(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x48
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup4
  }
}

// Releases pending allocation from the reused original second argument through the actual shared release tail.
// R6GameService.dll @ 10064d3e : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind16(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Restores saved owner first word through the actual shared allocator-base reset.
// R6GameService.dll @ 10064d80 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind17(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Tail-destroys completed member at saved owner+0x8.
// R6GameService.dll @ 10064d88 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind18(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::TailForwardTreeCleanup
  }
}

// Tail-destroys completed member at saved owner+0x18.
// R6GameService.dll @ 10064d93 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind19(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup
  }
}

// Tail-destroys completed member at saved owner+0x28.
// R6GameService.dll @ 10064d9e : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind20(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x28
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup2
  }
}

// Tail-destroys completed member at saved owner+0x38.
// R6GameService.dll @ 10064da9 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind21(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x38
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup3
  }
}

// Tail-destroys completed member at saved owner+0x48.
// R6GameService.dll @ 10064db4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind22(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x48
    jmp    R6GameServiceAddresses::ordered_tree_support_TailForwardTreeCleanup4
  }
}

// Releases the first word of current inherited scratch object through actual shared header release.
// R6GameService.dll @ 10064dbf : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind23(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the first word of current inherited scratch object through actual shared header release.
// R6GameService.dll @ 10064dc7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind24(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the first word of current inherited scratch object through actual shared header release.
// R6GameService.dll @ 10064dcf : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind25(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the first word of current inherited scratch object through actual shared header release.
// R6GameService.dll @ 10064dd7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind26(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases the first word of current inherited scratch object through actual shared header release.
// R6GameService.dll @ 10064ddf : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_CCDKeyProcessUnwind27(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects17-state CCDKeyProcess construction map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064d48 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectCCDKeyConstruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructCCDKeyProcessExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects11-state CCDKeyProcess destruction map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064de7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectCCDKeyDestruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceObjectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ef9c : native CCDKeyProcess lifetime record.
const R6GameServiceNative::UnwindEntry ConstructCCDKeyProcessUnwindMap[17] = {
  {-1, R6GameServiceAddresses::CCDKeyProcessUnwind},
  {0x0, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind},
  {0x1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind2},
  {0x2, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind3},
  {0x1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind4},
  {0x4, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind5},
  {0x5, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind6},
  {0x4, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind7},
  {0x7, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind8},
  {0x8, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind9},
  {0x7, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind10},
  {0xa, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind11},
  {0xb, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind12},
  {0xa, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind13},
  {0xd, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind14},
  {0xd, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind15},
  {0xf, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind16},
};

// R6GameService.dll data @ 1007f024 : native CCDKeyProcess lifetime record.
// R6GameService.dll data @ 1007ef9c : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructCCDKeyProcessExceptionInfo = {
  0x19930520,
  0x11,
  R6GameServiceAddresses::ConstructCCDKeyProcessUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007f0f4 : native CCDKeyProcess lifetime record.
const R6GameServiceNative::UnwindEntry DestroyServiceObjectUnwindMap[11] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind17},
  {0x0, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind18},
  {0x1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind19},
  {0x2, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind20},
  {0x3, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind21},
  {0x4, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind22},
  {0x4, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind23},
  {0x3, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind24},
  {0x2, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind25},
  {0x1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind26},
  {0x0, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind27},
};

// R6GameService.dll data @ 1007f14c : native CCDKeyProcess lifetime record.
// R6GameService.dll data @ 1007f0f4 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceObjectExceptionInfo = {
  0x19930520,
  0xb,
  R6GameServiceAddresses::DestroyServiceObjectUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Stores one callback word at owner+c8 and leaves that full word in EAX; no receiver guard.
// R6GameService.dll @ 10026df0 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall CCDKeyProcessSetCallback1(void *owner,uint callbackWord)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(owner) + 0xc8) = callbackWord;
  return callbackWord;
}

// Tail-forwards 4 original argument words through current callback slot+c8, or returns zero with native cleanup.
// R6GameService.dll @ 10026e30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InvokeFourWordCallback(void *owner,uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xc8]
    test   eax,eax
    je     Branch19
    jmp    eax
  Branch19:
    ret    0x10
  }
}

// Stores one callback word at owner+cc and leaves that full word in EAX; no receiver guard.
// R6GameService.dll @ 10026e00 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall CCDKeyProcessSetCallback2(void *owner,uint callbackWord)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(owner) + 0xcc) = callbackWord;
  return callbackWord;
}

// Tail-forwards 3 original argument words through current callback slot+cc, or returns zero with native cleanup.
// R6GameService.dll @ 10026e40 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InvokeThreeWordCallback(void *owner,uint word0,uint word1,uint word2)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xcc]
    test   eax,eax
    je     Branch20
    jmp    eax
  Branch20:
    ret    0xc
  }
}

// Stores one callback word at owner+d0 and leaves that full word in EAX; no receiver guard.
// R6GameService.dll @ 10026e10 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall CCDKeyProcessSetCallback3(void *owner,uint callbackWord)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(owner) + 0xd0) = callbackWord;
  return callbackWord;
}

// Tail-forwards 5 original argument words through current callback slot+d0, or returns zero with native cleanup.
// R6GameService.dll @ 10026e50 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InvokeFiveWordCallback(void *owner,uint word0,uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xd0]
    test   eax,eax
    je     Branch21
    jmp    eax
  Branch21:
    ret    0x14
  }
}

// Stores one callback word at owner+d4 and leaves that full word in EAX; no receiver guard.
// R6GameService.dll @ 10026e20 : complete native operations and raw ABI; descriptive helper name.
uint __thiscall CCDKeyProcessSetCallback4(void *owner,uint callbackWord)
{
  *reinterpret_cast<uint *>(static_cast<byte *>(owner) + 0xd4) = callbackWord;
  return callbackWord;
}

// Tail-forwards 2 original argument words through current callback slot+d4, or returns zero with native cleanup.
// R6GameService.dll @ 10026e60 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InvokeTwoWordCallback(void *owner,uint word0,uint word1)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0xd4]
    test   eax,eax
    je     Branch22
    jmp    eax
  Branch22:
    ret    0x8
  }
}

// Optionally snapshots, flushes, receives/dispatches below captured unsigned elapsed limit, expires records and releases temporary list; raw AL/EAX retained.
// R6GameService.dll @ 100240f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ProcessInputWithinTimeLimit(void *owner,uint elapsedLimitWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectInputLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xac
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    al,BYTE PTR [esi+0x5e]
    test   al,al
    je     Branch23
    call   R6GameServiceAddresses::SendPeriodicCollectionSnapshot
  Branch23:
    mov    ecx,DWORD PTR [esi+0x58]
    call   R6GameServiceAddresses::FlushPendingDatagrams
    test   al,al
    je     Branch26
    push   edi
    call   R6GameServiceAddresses::RefreshPerformanceCounterBaseline
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0xb]
    lea    ecx,[esp+0x20]
    push   eax
    mov    DWORD PTR [esp+0xc0],0x1
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0xbc],0x2
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    mov    edi,DWORD PTR [esp+0xc4]
    cmp    eax,edi
    jae    Branch25
  Branch24:
    lea    ecx,[esp+0x10]
    lea    edx,[esp+0xc]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x58]
    lea    eax,[esp+0x34]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReceiveAndDecodeTaggedPayload
    test   al,al
    je     Branch25
    mov    edx,DWORD PTR [esp+0xc]
    lea    ecx,[esp+0x10]
    push   ecx
    lea    eax,[esp+0x34]
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::DispatchParsedInputRecord
    call   R6GameServiceAddresses::GetElapsedMilliseconds
    cmp    eax,edi
    jb     Branch24
  Branch25:
    mov    ecx,esi
    call   R6GameServiceAddresses::ProcessExpiredInputRecords
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0xbc],0x3
    mov    DWORD PTR [esp+0x28],ecx
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0xbc],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0x2c],edx
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0xbc],0x5
    call   R6GameServiceAddresses::ReleaseListNodesRetainHeader
    mov    eax,DWORD PTR [esp+0x20]
    push   0x1
    push   eax
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    al,0x1
    pop    edi
  Branch26:
    mov    ecx,DWORD PTR [esp+0xb0]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xb8
    ret    0x4
  }
}

// Reserves sequence, builds4/2 descriptor with20 key bytes/text, records metadata, sends and releases two native temporaries.
// R6GameService.dll @ 10024260 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendDescriptorWithText(void *owner,uint recordWord,uint keyWord,uint textWord,uint auxiliaryWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectDescriptorLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    push   edi
    mov    DWORD PTR [esp+0x14],ecx
    mov    eax,ds:0x10093bfc
    inc    eax
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    ds:0x10093bfc,eax
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],edi
    mov    DWORD PTR [esp+0x38],0x3
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x50],ecx
    push   ecx
    lea    ecx,[esp+0x44]
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],ebx
    mov    DWORD PTR [esp+0x50],0x1
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x54],0x2
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],ebx
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   eax
    mov    BYTE PTR [esp+0x54],0x3
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x14],0x4
    push   ecx
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x18]
    push   edx
    mov    DWORD PTR [esp+0x18],0x2
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    edi,DWORD PTR [esp+0x5c]
    push   0x14
    push   edi
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::AppendClDataListBinary
    mov    eax,DWORD PTR [esp+0x60]
    lea    ecx,[esp+0x30]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListString
    lea    ecx,[esp+0x30]
    push   ecx
    lea    ecx,[esp+0x1c]
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    edx,DWORD PTR [esp+0x10]
    push   edi
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertFiveWordRecordById
    mov    edi,DWORD PTR [esp+0x58]
    mov    ecx,DWORD PTR [esp+0x64]
    mov    edx,DWORD PTR [esp+0x10]
    mov    ax,WORD PTR [edi+0x82]
    push   eax
    push   edi
    push   ecx
    push   0x4
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::StoreTimestampedDescriptorRecord
    mov    cx,WORD PTR [edi+0x82]
    lea    eax,[esp+0x18]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esi+0x58]
    push   edi
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    esi,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],ebx
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x50],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x30],ebp
    mov    ebx,0x5
    lea    edx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x5c],edx
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x50],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x50],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x48]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x10
  }
}

// Reserves sequence, builds6/1 descriptor with20 key bytes, sends and releases two native temporaries.
// R6GameService.dll @ 10024430 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendDescriptorWithValue(void *owner,uint recordWord,uint keyWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectDescriptorLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    mov    DWORD PTR [esp+0xc],ecx
    mov    eax,ds:0x10093bfc
    inc    eax
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    push   edi
    mov    ds:0x10093bfc,eax
    mov    DWORD PTR [esp+0xc],eax
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x4c],ecx
    push   ecx
    lea    ecx,[esp+0x40]
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x4c],0x1
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],ebx
    push   0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x50],0x2
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0xc]
    lea    ecx,[esp+0x14]
    push   eax
    mov    BYTE PTR [esp+0x50],0x3
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x10],0x6
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x14],0x1
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    push   0x14
    push   eax
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::AppendClDataListBinary
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    eax,DWORD PTR [esp+0x54]
    lea    edx,[esp+0x14]
    push   edx
    mov    cx,WORD PTR [eax+0x82]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x58]
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    esi,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [esp+0x2c],edi
    mov    ebx,0x5
    mov    DWORD PTR [esp+0x4c],ebx
    lea    edx,[esp+0x38]
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esp+0x58],edx
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x4c],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x44]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x44
    ret    0x8
  }
}

// Consumes keyed lookup result, builds nested5/1/26 decimal descriptor on nonzero, queues and destroys three temporaries.
// R6GameService.dll @ 100245d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendCompoundDescriptor(void *owner,uint recordWord,uint keyWord,uint trailingWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCompoundLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x4c
    push   ebx
    push   esi
    xor    esi,esi
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x8],esi
    mov    eax,DWORD PTR [esp+0x68]
    push   eax
    call   R6GameServiceAddresses::TakeOwnedValueForKey
    cmp    eax,esi
    mov    DWORD PTR [esp+0x68],eax
    jne    Branch27
    pop    esi
    xor    eax,eax
    pop    ebx
    mov    ecx,DWORD PTR [esp+0x4c]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0xc
  Branch27:
    push   ebp
    mov    ebp,R6GameServiceAddresses::PTR_LAB
    push   edi
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x58],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x4c],0x3
    mov    DWORD PTR [esp+0x44],ebp
    push   esi
    lea    ecx,[esp+0x54]
    mov    DWORD PTR [esp+0x68],esi
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    esi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x44],edi
    mov    DWORD PTR [esp+0x50],esi
    mov    DWORD PTR [esp+0x64],0x1
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],ebp
    push   0x0
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x68],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x38],esi
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],ebp
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],esi
    lea    ecx,[esp+0x70]
    mov    BYTE PTR [esp+0x64],0x5
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x14],0x5
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   eax
    mov    DWORD PTR [esp+0x14],0x1
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,DWORD PTR [esp+0x74]
    lea    edx,[esp+0x74]
    mov    DWORD PTR [esp+0x74],ecx
    push   edx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x74]
    lea    ecx,[esp+0x44]
    push   eax
    mov    DWORD PTR [esp+0x78],0x26
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x48]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    edx,[esp+0x44]
    lea    ecx,[esp+0x14]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    eax,[esp+0x14]
    push   eax
    mov    eax,DWORD PTR [esp+0x70]
    mov    cx,WORD PTR [eax+0x82]
    push   ecx
    mov    ecx,DWORD PTR [ebx+0x58]
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    ebx,DWORD PTR [esp+0x70]
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],esi
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x64],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x2c],edi
    mov    DWORD PTR [esp+0x38],esi
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x64],0x7
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x44],edi
    mov    DWORD PTR [esp+0x50],esi
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x64],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x5c]
    pop    edi
    pop    ebp
    mov    eax,ebx
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x58
    ret    0xc
  }
}

// Reserves a sequence, converts32 and23 signed input bytes into owner+64/+85, then sends kind2 using late original words.
// R6GameService.dll @ 100247e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall UppercaseAndDispatchRanges(void *owner,uint messageDataWord,uint rangesWord,uint payloadWord)
{
  __asm {
    push   ecx
    mov    eax,ds:0x10093bfc
    push   ebx
    push   ebp
    push   esi
    push   edi
    inc    eax
    push   0x2
    push   eax
    mov    ebx,ecx
    mov    ds:0x10093bfc,eax
    mov    DWORD PTR [esp+0x18],eax
    call   R6GameServiceAddresses::InsertKindRecordById
    mov    edi,DWORD PTR [esp+0x1c]
    lea    eax,[ebx+0x64]
    mov    esi,edi
    lea    ebp,[edi+0x20]
    cmp    edi,ebp
    je     Branch29
    sub    eax,edi
    mov    DWORD PTR [esp+0x1c],eax
  Branch28:
    movsx  eax,BYTE PTR [esi]
    push   eax
    call   R6GameServiceAddresses::toupper
    mov    ecx,DWORD PTR [esp+0x20]
    add    esp,0x4
    mov    BYTE PTR [ecx+esi*1],al
    inc    esi
    cmp    esi,ebp
    jne    Branch28
  Branch29:
    lea    esi,[edi+0x21]
    add    edi,0x38
    cmp    esi,edi
    lea    ebp,[ebx+0x85]
    je     Branch31
    sub    ebp,esi
  Branch30:
    movsx  edx,BYTE PTR [esi]
    push   edx
    call   R6GameServiceAddresses::toupper
    add    esp,0x4
    mov    BYTE PTR [esi+ebp*1],al
    inc    esi
    cmp    esi,edi
    jne    Branch30
  Branch31:
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x18]
    mov    esi,DWORD PTR [esp+0x10]
    push   eax
    push   0x2
    push   ecx
    push   esi
    mov    ecx,ebx
    call   R6GameServiceAddresses::SendTag11Descriptor
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Reserves a sequence, copies four ordered words to owner+9d, converts23 signed bytes at+ad, then sends kind3.
// R6GameService.dll @ 10024880 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall CopyAndDispatchRecordFields(void *owner,uint messageDataWord,uint recordWord,uint payloadWord)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR ds:0x10093bfc
    push   esi
    push   edi
    inc    ebp
    push   0x3
    push   ebp
    mov    edi,ecx
    mov    DWORD PTR ds:0x10093bfc,ebp
    call   R6GameServiceAddresses::InsertKindRecordById
    mov    eax,DWORD PTR [esp+0x18]
    lea    ecx,[edi+0x9d]
    mov    edx,eax
    lea    ebx,[eax+0x27]
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [ecx],esi
    mov    esi,DWORD PTR [edx+0x4]
    mov    DWORD PTR [ecx+0x4],esi
    mov    esi,DWORD PTR [edx+0x8]
    mov    DWORD PTR [ecx+0x8],esi
    lea    esi,[eax+0x10]
    mov    edx,DWORD PTR [edx+0xc]
    cmp    esi,ebx
    mov    DWORD PTR [ecx+0xc],edx
    lea    ecx,[edi+0xad]
    je     Branch33
    sub    ecx,esi
    mov    DWORD PTR [esp+0x18],ecx
  Branch32:
    movsx  eax,BYTE PTR [esi]
    push   eax
    call   R6GameServiceAddresses::toupper
    mov    ecx,DWORD PTR [esp+0x1c]
    add    esp,0x4
    mov    BYTE PTR [ecx+esi*1],al
    inc    esi
    cmp    esi,ebx
    jne    Branch32
  Branch33:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x14]
    push   edx
    push   0x3
    push   eax
    push   ebp
    mov    ecx,edi
    call   R6GameServiceAddresses::SendTag11Descriptor
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    ret    0xc
  }
}

// Resets incomplete input descriptor at parent-b0.
// R6GameService.dll @ 10064e00 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind28(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Passes input construction scratch byte at parent-b5 to native no-op.
// R6GameService.dll @ 10064e0b : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind29(void)
{
  __asm {
    lea    ecx,[ebp-0xb5]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys completed input descriptor at parent-b0 through native list alias.
// R6GameService.dll @ 10064e16 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind30(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets input descriptor during normal member cleanup.
// R6GameService.dll @ 10064e21 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind31(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Loads current saved list pointer at parent-98, preserves null or adds4, then releases nodes/header through current cell.
// R6GameService.dll @ 10064e2c : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind32(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x98],0x0
    je     Branch34
    mov    eax,DWORD PTR [ebp-0x98]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x94],eax
    jmp    Branch35
  Branch34:
    mov    DWORD PTR [ebp-0x94],0x0
  Branch35:
    mov    ecx,DWORD PTR [ebp-0x94]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Loads current saved head-cell pointer at parent-94 and tail-forwards to native no-op.
// R6GameService.dll @ 10064e62 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind33(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x94]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Resets first descriptor at parent-24.
// R6GameService.dll @ 10064e80 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind34(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys first completed descriptor at parent-24 through its native alias.
// R6GameService.dll @ 10064e88 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind35(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets second descriptor at parent-3c.
// R6GameService.dll @ 10064e90 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind36(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys second completed descriptor at parent-3c through its native alias.
// R6GameService.dll @ 10064e98 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind37(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets second descriptor after its normal destructor has entered.
// R6GameService.dll @ 10064ea0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind38(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets first descriptor after normal member cleanup has entered.
// R6GameService.dll @ 10064ea8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind39(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads parent argument2 as current list pointer, preserves null or adds4 and releases nodes/header through that cell.
// R6GameService.dll @ 10064eb0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind40(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch36
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x68],eax
    jmp    Branch37
  Branch36:
    mov    DWORD PTR [ebp-0x68],0x0
  Branch37:
    mov    ecx,DWORD PTR [ebp-0x68]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets first descriptor at parent-24.
// R6GameService.dll @ 10064ef0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind41(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys first completed descriptor at parent-24.
// R6GameService.dll @ 10064ef8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind42(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets second descriptor at parent-3c.
// R6GameService.dll @ 10064f00 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind43(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys second completed descriptor at parent-3c.
// R6GameService.dll @ 10064f08 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind44(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets third descriptor at parent-54.
// R6GameService.dll @ 10064f10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind45(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys third completed descriptor at parent-54.
// R6GameService.dll @ 10064f18 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind46(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets third descriptor after normal member destruction has entered.
// R6GameService.dll @ 10064f20 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind47(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets second descriptor after normal member destruction has entered.
// R6GameService.dll @ 10064f28 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind48(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets first descriptor after normal member destruction has entered.
// R6GameService.dll @ 10064f30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind49(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Shared descriptor unwind states and native selector metadata.
// R6GameService.dll data @ 1007f1b4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CCDKeyProcessSharedLifetimeUnwindMap[7] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind34},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind35},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind36},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind37},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind38},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind39},
  {0x00000005, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind40},
};

// Shared descriptor unwind states and native selector metadata.
// R6GameService.dll data @ 1007f1ec : native storage identity retained.
const R6GameServiceNative::FuncInfo CCDKeyProcessSharedLifetimeExceptionInfo = {
  0x19930520,
  0x00000007,
  R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Selects the shared seven-state lifetime record for both descriptor builders.
// R6GameService.dll @ 10064ed7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectDescriptorLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CCDKeyProcessSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Extracts ID/kind/flag/child fields, gates by tracked ID, copies128-byte address/late port, routes kinds1..5 and preserves native AL status/cleanup.
// R6GameService.dll @ 10024910 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall DispatchParsedInputRecord(void *owner,uint sourceAddressWord,uint sourcePortWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectParsedLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xac
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0x28],ebx
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0xc],ebx
    mov    DWORD PTR [esp+0x2c],ebx
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0xc4],ebx
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    mov    edi,DWORD PTR [esp+0xd0]
    lea    eax,[esp+0xc]
    push   ebx
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0xc8],0x1
    mov    BYTE PTR [esp+0x1b],bl
    call   R6GameServiceAddresses::ReadIndexedInt32
    test   al,al
    je     Branch41
    lea    ecx,[esp+0x2c]
    push   0x1
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReadIndexedWord
    test   al,al
    je     Branch41
    lea    edx,[esp+0x13]
    push   0x2
    push   edx
    mov    ecx,edi
    call   R6GameServiceAddresses::ReadIndexedByte
    test   al,al
    je     Branch41
    lea    eax,[esp+0x14]
    push   0x3
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je     Branch41
    mov    ebx,0x5
    cmp    WORD PTR [esp+0x2c],bx
    je     Branch38
    mov    edi,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x8]
    lea    edx,[esp+0xc]
    push   edx
    call   R6GameServiceAddresses::OrderedTreeFind
    cmp    eax,edi
    jne    Branch38
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0xc0],0x3
    mov    DWORD PTR [esp+0x30],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0xc0],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xc0],0x3
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
    jmp    Branch43
  Branch38:
    mov    ecx,DWORD PTR [esp+0xc8]
    push   0x80
    lea    edx,[esp+0x38]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::strncpy
    mov    ecx,DWORD PTR [esp+0x38]
    mov    ax,WORD PTR [esp+0xd8]
    and    ecx,0xffff
    mov    WORD PTR [esp+0xc2],ax
    add    esp,0xc
    lea    eax,[ecx-0x1]
    cmp    eax,0x4
    ja     Branch40
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4]
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x34]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTypeOneInputRecord
    jmp    Branch39
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::EraseRecordsForId
    mov    edx,DWORD PTR [esp+0xc]
    lea    eax,[esp+0x14]
    lea    ecx,[esp+0x34]
    push   eax
    push   ecx
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTypeTwoInputRecord
    jmp    Branch39
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::EraseRecordsForId
    mov    eax,DWORD PTR [esp+0xc]
    lea    ecx,[esp+0x14]
    lea    edx,[esp+0x34]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTypeThreeInputRecord
    jmp    Branch39
    mov    ecx,DWORD PTR [esp+0xc]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::EraseRecordsForId
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x34]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTypeFourInputRecord
    jmp    Branch39
    mov    ecx,DWORD PTR [esp+0xc]
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x34]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ParseTypeFiveInputRecord
  Branch39:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x7
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0xc0],ebx
    mov    DWORD PTR [esp+0x30],edx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0xc0],0x8
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xc0],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    al,0x1
    jmp    Branch43
  Branch40:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0xc0],ebx
    mov    DWORD PTR [esp+0x30],eax
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0xc0],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xc0],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    jmp    Branch42
  Branch41:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0xc0],0x2
    call   R6GameServiceAddresses::DestroyClDataPointerList
  Branch42:
    xor    al,al
  Branch43:
    mov    ecx,DWORD PTR [esp+0xb8]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xb8
    ret    0xc
  }
}

// Reads20 payload bytes, reports kind5/status5 on failure or stores payload and calls D4 gate; releases temporary list and returns raw final free EAX.
// R6GameService.dll @ 100257e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ParseTypeFiveInputRecord(void *owner,uint recordIdWord,uint endpointWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CCDKeyProcess_SelectParsedLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],0x0
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x28],0x3
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x7]
    lea    ecx,[esp+0x30]
    push   eax
    mov    DWORD PTR [esp+0x44],0x1
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_LAB
    xor    ecx,ecx
    lea    edx,[esp+0xc]
    mov    DWORD PTR [esp+0xc],ecx
    mov    DWORD PTR [esp+0x40],0x2
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x14],ecx
    mov    DWORD PTR [esp+0x18],ecx
    push   ecx
    mov    DWORD PTR [esp+0x20],ecx
    mov    ecx,DWORD PTR [esp+0x54]
    push   0x14
    push   edx
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne    Branch44
    mov    eax,DWORD PTR [esp+0x48]
    mov    ecx,DWORD PTR [esp+0x4c]
    push   0x5
    push   0x5
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::SendMalformedRecordResponse
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN
    lea    edx,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],0x3
    mov    DWORD PTR [esp+0x48],edx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x40],0x4
    call   R6GameServiceAddresses::InvokePointerListClearRange
    mov    BYTE PTR [esp+0x40],0x3
    jmp    Branch45
  Branch44:
    mov    ecx,DWORD PTR [esp+0x48]
    lea    eax,[esp+0xc]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertTwentyByteKey
    mov    eax,DWORD PTR [esp+0x4c]
    lea    edx,[esp+0xc]
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InvokeTwoWordCallback
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x40],0x5
    mov    DWORD PTR [esp+0x48],ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x40],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    mov    BYTE PTR [esp+0x40],0x5
  Branch45:
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x38]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0xc
  }
}

// Builds response from record ID, low16 kind and unchecked byte mapping, low16 status and27, then queues and cleans three temporaries.
// R6GameService.dll @ 10026b90 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendMalformedRecordResponse(void *owner,uint recordWord,uint recordIdWord,uint kindWord,uint statusWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectCompoundLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x50
    push   ebx
    push   ebp
    push   esi
    xor    eax,eax
    mov    esi,0x3
    mov    ebp,R6GameServiceAddresses::PTR_LAB
    push   edi
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x5c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x50],esi
    mov    DWORD PTR [esp+0x48],ebp
    push   eax
    lea    ecx,[esp+0x58]
    mov    DWORD PTR [esp+0x6c],eax
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x54],edi
    mov    DWORD PTR [esp+0x68],0x1
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],esi
    mov    DWORD PTR [esp+0x30],ebp
    push   0x0
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x6c],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],esi
    mov    DWORD PTR [esp+0x18],ebp
    push   0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x6c],0x4
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x24],edi
    lea    eax,[esp+0x74]
    lea    ecx,[esp+0x18]
    push   eax
    mov    BYTE PTR [esp+0x6c],0x5
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    esi,DWORD PTR [esp+0x78]
    lea    ecx,[esp+0x78]
    and    esi,0xffff
    push   ecx
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x7c],esi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    xor    edx,edx
    lea    eax,[esp+0x78]
    mov    dl,BYTE PTR [esi+0x100769c8]
    push   eax
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x7c],edx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    ecx,DWORD PTR [esp+0x7c]
    lea    edx,[esp+0x78]
    and    ecx,0xffff
    push   edx
    mov    DWORD PTR [esp+0x7c],ecx
    lea    ecx,[esp+0x34]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x78]
    lea    ecx,[esp+0x48]
    push   eax
    mov    DWORD PTR [esp+0x7c],0x27
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x30]
    push   ecx
    lea    ecx,[esp+0x4c]
    call   R6GameServiceAddresses::AppendClDataListCopy
    lea    edx,[esp+0x48]
    lea    ecx,[esp+0x18]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    edx,DWORD PTR [esp+0x10]
    lea    eax,[esp+0x18]
    push   eax
    mov    eax,DWORD PTR [esp+0x74]
    mov    cx,WORD PTR [eax+0x82]
    push   ecx
    mov    ecx,DWORD PTR [edx+0x58]
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x6
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],edi
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x68],0x7
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x54],edi
    lea    ecx,[esp+0x54]
    mov    DWORD PTR [esp+0x68],0x8
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    ecx,DWORD PTR [esp+0x60]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x10
  }
}

// Resets incomplete dispatcher descriptor at parent-b0.
// R6GameService.dll @ 10064f50 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind50(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys completed dispatcher descriptor at parent-b0.
// R6GameService.dll @ 10064f5b : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind51(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets dispatcher base after normal malformed-extraction member cleanup entered.
// R6GameService.dll @ 10065029 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind58(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Resets dispatcher descriptor during unknown-ID cleanup.
// R6GameService.dll @ 10064f66 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind52(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-94, preserves null or adds4 through scratch-d0, then releases current header.
// R6GameService.dll @ 10064f71 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind53(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x94],0x0
    je     Branch46
    mov    eax,DWORD PTR [ebp-0x94]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xd0],eax
    jmp    Branch47
  Branch46:
    mov    DWORD PTR [ebp-0xd0],0x0
  Branch47:
    mov    ecx,DWORD PTR [ebp-0xd0]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets dispatcher descriptor during invalid-kind cleanup.
// R6GameService.dll @ 10064fe8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind56(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-94, preserves null or adds4 through scratch-d8, then releases current header.
// R6GameService.dll @ 10064ff3 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind57(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x94],0x0
    je     Branch48
    mov    eax,DWORD PTR [ebp-0x94]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xd8],eax
    jmp    Branch49
  Branch48:
    mov    DWORD PTR [ebp-0xd8],0x0
  Branch49:
    mov    ecx,DWORD PTR [ebp-0xd8]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets dispatcher descriptor after recognized-kind member cleanup entered.
// R6GameService.dll @ 10064fa7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind54(void)
{
  __asm {
    lea    ecx,[ebp-0xb0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-94, preserves null or adds4 through scratch-e0, then releases current header.
// R6GameService.dll @ 10064fb2 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind55(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x94],0x0
    je     Branch50
    mov    eax,DWORD PTR [ebp-0x94]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xe0],eax
    jmp    Branch51
  Branch50:
    mov    DWORD PTR [ebp-0xe0],0x0
  Branch51:
    mov    ecx,DWORD PTR [ebp-0xe0]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets incomplete type-five descriptor at parent-24.
// R6GameService.dll @ 10065350 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind96(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Passes construction scratch byte at parent-3d to native no-op.
// R6GameService.dll @ 10065358 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind97(void)
{
  __asm {
    lea    ecx,[ebp-0x3d]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys completed type-five descriptor at parent-24.
// R6GameService.dll @ 10065360 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind98(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets type-five descriptor on malformed-payload cleanup.
// R6GameService.dll @ 10065368 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind99(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg1 as current list pointer, preserves null or adds4 through scratch-50, then releases current header.
// R6GameService.dll @ 10065370 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind100(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je     Branch52
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x50],eax
    jmp    Branch53
  Branch52:
    mov    DWORD PTR [ebp-0x50],0x0
  Branch53:
    mov    ecx,DWORD PTR [ebp-0x50]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-five descriptor on successful-payload cleanup.
// R6GameService.dll @ 10065397 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind101(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg1 as current list pointer, preserves null or adds4 through scratch-58, then releases current header.
// R6GameService.dll @ 1006539f : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind102(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x4],0x0
    je     Branch54
    mov    eax,DWORD PTR [ebp+0x4]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x58],eax
    jmp    Branch55
  Branch54:
    mov    DWORD PTR [ebp-0x58],0x0
  Branch55:
    mov    ecx,DWORD PTR [ebp-0x58]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects shared nine-state compound/response descriptor lifetime record.
// R6GameService.dll @ 10064f38 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectCompoundLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CCDKeyProcessSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Shared compound/response descriptor unwind record.
// R6GameService.dll data @ 1007f25c : native storage identity retained.
const R6GameServiceNative::UnwindEntry CCDKeyProcessSharedLifetimeUnwindMap2[9] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind41},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind42},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind43},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind44},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind45},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind46},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind47},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind48},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind49},
};

// Shared compound/response descriptor unwind record.
// R6GameService.dll data @ 1007f2a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo CCDKeyProcessSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x00000009,
  R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwindMap2,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Selects six-state input descriptor/header lifetime record.
// R6GameService.dll @ 10064e6d : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectInputLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessInputWithinTimeLimitExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Input descriptor/header unwind state map and selector metadata.
// R6GameService.dll data @ 1007f168 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessInputWithinTimeLimitUnwindMap[6] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind28},
  {0x00000000, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind29},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind30},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind31},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind32},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind33},
};

// Input descriptor/header unwind state map and selector metadata.
// R6GameService.dll data @ 1007f198 : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessInputWithinTimeLimitExceptionInfo = {
  0x19930520,
  0x00000006,
  R6GameServiceAddresses::ProcessInputWithinTimeLimitUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Extracts byte/child, consumes kind2/3 routing, copies variable payload and applies native digest/send/callback branches, preserving unguarded allocation lifetime and raw cleanup.
// R6GameService.dll @ 10024c20 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ParseTypeOneInputRecord(void *owner,uint recordIdWord,uint endpointWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectType14Lifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x94
    push   ebx
    push   ebp
    push   esi
    push   edi
    xor    edi,edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x34],edi
    mov    BYTE PTR [esp+0x13],0x0
    mov    DWORD PTR [esp+0x34],edi
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x24],0x3
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::PTR_LAB
    lea    eax,[esp+0x3b]
    lea    ecx,[esp+0x2c]
    push   eax
    mov    DWORD PTR [esp+0xb0],0x1
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_LAB
    xor    ecx,ecx
    xor    edx,edx
    mov    DWORD PTR [esp+0x6c],ecx
    mov    DWORD PTR [esp+0x90],edx
    mov    DWORD PTR [esp+0x70],ecx
    mov    DWORD PTR [esp+0x94],edx
    mov    DWORD PTR [esp+0x74],ecx
    mov    DWORD PTR [esp+0x98],edx
    xor    eax,eax
    mov    DWORD PTR [esp+0x78],ecx
    mov    DWORD PTR [esp+0x9c],edx
    mov    ebp,DWORD PTR [esp+0xb4]
    mov    DWORD PTR [esp+0x5c],eax
    mov    DWORD PTR [esp+0x48],ecx
    mov    DWORD PTR [esp+0xa0],edx
    mov    DWORD PTR [esp+0x60],eax
    mov    DWORD PTR [esp+0x4c],ecx
    mov    DWORD PTR [esp+0x7c],edx
    mov    DWORD PTR [esp+0x64],eax
    mov    DWORD PTR [esp+0x50],ecx
    mov    DWORD PTR [esp+0x80],edx
    mov    DWORD PTR [esp+0x68],eax
    mov    DWORD PTR [esp+0x54],ecx
    mov    DWORD PTR [esp+0x84],edx
    push   edi
    mov    edi,DWORD PTR [esp+0xc0]
    lea    eax,[esp+0x17]
    mov    DWORD PTR [esp+0x5c],ecx
    mov    DWORD PTR [esp+0x8c],edx
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0xb4],0x2
    mov    DWORD PTR [esp+0x1c],ebp
    mov    DWORD PTR [esp+0x94],edx
    call   R6GameServiceAddresses::ReadIndexedByte
    test   al,al
    je     Branch66
    mov    ebx,0x1
    lea    ecx,[esp+0x1c]
    push   ebx
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je     Branch66
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::RemoveKindRecordById
    and    eax,0xffff
    sub    eax,0x2
    je     Branch59
    dec    eax
    jne    Branch65
    mov    al,BYTE PTR [esp+0x13]
    lea    ecx,[esp+0x1c]
    cmp    al,0x27
    push   0x0
    jne    Branch56
    lea    edx,[esp+0x38]
    mov    BYTE PTR [esp+0x1c],0x0
    push   edx
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    ax,WORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esp+0xb8]
    lea    ecx,[esp+0x90]
    mov    WORD PTR [esp+0x1a],ax
    push   ecx
    lea    eax,[esp+0x18]
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InvokeThreeWordCallback
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::EraseRecordsForId
    jmp    Branch65
  Branch56:
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::GetIndexedPayload
    mov    edx,DWORD PTR [eax]
    mov    ecx,eax
    call   DWORD PTR [edx+0x14]
    mov    ebx,eax
    push   ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    push   0x0
    push   ebx
    push   ebp
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne    Branch57
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x7
    lea    eax,[esp+0x28]
    mov    DWORD PTR [esp+0xac],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0xac],0x8
    jmp    Branch67
  Branch57:
    lea    ecx,[esp+0x48]
    lea    edx,[esi+0xad]
    push   ecx
    mov    edi,edx
    or     ecx,0xffffffff
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push   ecx
    push   edx
    push   ebx
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::CCDKeyProcessFeedAndFinalize
    test   al,al
    jne    Branch58
    mov    BYTE PTR [esp+0x18],al
    mov    eax,DWORD PTR [esp+0xb8]
    lea    edx,[esp+0x90]
    lea    ecx,[esp+0x14]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esi
    mov    WORD PTR [esp+0x26],0x5
    call   R6GameServiceAddresses::InvokeThreeWordCallback
    mov    edx,DWORD PTR [esp+0xb4]
    push   edx
    jmp    Branch63
  Branch58:
    mov    edx,DWORD PTR [esp+0xb8]
    lea    eax,[esp+0x48]
    lea    ecx,[esi+0x9d]
    push   eax
    mov    eax,DWORD PTR [esp+0xb8]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::SendTag31Descriptor
    jmp    Branch64
  Branch59:
    mov    al,BYTE PTR [esp+0x13]
    push   0x0
    cmp    al,0x27
    jne    Branch60
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x1c],0x0
    push   ecx
    lea    ecx,[esp+0x24]
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    dx,WORD PTR [esp+0x34]
    lea    eax,[esp+0x5c]
    mov    WORD PTR [esp+0x1a],dx
    mov    edx,DWORD PTR [esp+0xb8]
    lea    ecx,[esp+0x6c]
    push   eax
    push   ecx
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InvokeFourWordCallback
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::EraseRecordsForId
    jmp    Branch65
  Branch60:
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::GetIndexedPayload
    mov    edx,DWORD PTR [eax]
    mov    ecx,eax
    call   DWORD PTR [edx+0x14]
    mov    ebx,eax
    push   ebx
    mov    DWORD PTR [esp+0x48],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    push   0x0
    push   ebx
    push   ebp
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne    Branch61
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x5
    lea    eax,[esp+0x28]
    mov    DWORD PTR [esp+0xac],ebx
    mov    DWORD PTR [esp+0x3c],eax
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0xac],0x6
    jmp    Branch67
  Branch61:
    lea    ecx,[esp+0x48]
    lea    ebx,[esi+0x85]
    push   ecx
    mov    edi,ebx
    or     ecx,0xffffffff
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    mov    edx,DWORD PTR [esp+0x48]
    not    ecx
    dec    ecx
    push   ecx
    push   ebx
    push   edx
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::CCDKeyProcessFeedAndFinalize
    test   al,al
    je     Branch62
    lea    eax,[esp+0x7c]
    mov    edi,ebx
    push   eax
    or     ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esi+0x64]
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    edi,edx
    push   ecx
    or     ecx,0xffffffff
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push   ebx
    push   ecx
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CCDKeyProcessFeedAndFinalize
    test   al,al
    je     Branch62
    mov    eax,DWORD PTR [esp+0xb8]
    lea    ecx,[esp+0x48]
    lea    edx,[esp+0x7c]
    push   ecx
    mov    ecx,DWORD PTR [esp+0xb8]
    push   edx
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::SendTag22Descriptor
    jmp    Branch64
  Branch62:
    mov    ecx,DWORD PTR [esp+0xb8]
    lea    edx,[esp+0x5c]
    lea    eax,[esp+0x6c]
    push   edx
    push   eax
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x28],0x0
    mov    WORD PTR [esp+0x2a],0x5
    call   R6GameServiceAddresses::InvokeFourWordCallback
    mov    eax,DWORD PTR [esp+0xb4]
    push   eax
  Branch63:
    mov    ecx,esi
    call   R6GameServiceAddresses::EraseRecordsForId
  Branch64:
    test   ebp,ebp
    je     Branch65
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch65:
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x9
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0xac],ebx
    mov    DWORD PTR [esp+0x3c],ecx
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    edx,DWORD PTR [esp+0x2c]
    push   ecx
    mov    eax,esp
    push   ecx
    push   esp
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0xb8],0xa
    mov    DWORD PTR [eax],edx
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    edx,DWORD PTR [esp+0x30]
    lea    eax,[esp+0x48]
    push   eax
    lea    ecx,[esp+0x34]
    call   DWORD PTR [edx+0x10]
    jmp    Branch68
  Branch66:
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x3
    lea    eax,[esp+0x28]
    mov    DWORD PTR [esp+0xac],ebx
    mov    DWORD PTR [esp+0x40],eax
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0xac],0x4
  Branch67:
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::InvokePointerListClearRange
  Branch68:
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0xac],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0xa4]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0xa0
    ret    0xc
  }
}

// Extracts tag/child, builds native ID-flag-word status, notifies C8 with two16-byte buffers or silently skips malformed headers, then releases temporary.
// R6GameService.dll @ 100250e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ParseTypeTwoInputRecord(void *owner,uint recordIdWord,uint endpointWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectType23Lifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0xc],ebx
    push   edi
    mov    esi,ecx
    mov    BYTE PTR [esp+0xf],bl
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x50],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x44],0x3
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x60],ebx
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_LAB
    mov    eax,DWORD PTR [esp+0x64]
    mov    edi,DWORD PTR [esp+0x6c]
    xor    ecx,ecx
    xor    edx,edx
    mov    DWORD PTR [esp+0x2c],ecx
    mov    DWORD PTR [esp+0x1c],edx
    mov    DWORD PTR [esp+0x30],ecx
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x34],ecx
    mov    DWORD PTR [esp+0x20],edx
    lea    eax,[esp+0xf]
    mov    DWORD PTR [esp+0x38],ecx
    mov    DWORD PTR [esp+0x24],edx
    push   ebx
    push   eax
    mov    ecx,edi
    mov    DWORD PTR [esp+0x64],0x1
    mov    WORD PTR [esp+0x22],bx
    mov    DWORD PTR [esp+0x30],edx
    call   R6GameServiceAddresses::ReadIndexedByte
    test   al,al
    je     Branch72
    lea    ecx,[esp+0x3c]
    push   0x1
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je     Branch72
    mov    al,BYTE PTR [esp+0xf]
    lea    ecx,[esp+0x3c]
    cmp    al,0x27
    push   ebx
    jne    Branch69
    lea    edx,[esp+0x14]
    mov    BYTE PTR [esp+0x1c],bl
    push   edx
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    ax,WORD PTR [esp+0x10]
    mov    WORD PTR [esp+0x1a],ax
    jmp    Branch70
  Branch69:
    lea    edx,[esp+0x30]
    push   0x10
    push   edx
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    je     Branch71
    push   0x1
    lea    eax,[esp+0x20]
    push   0x10
    push   eax
    lea    ecx,[esp+0x48]
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    je     Branch71
    mov    BYTE PTR [esp+0x18],0x1
  Branch70:
    mov    eax,DWORD PTR [esp+0x68]
    lea    ecx,[esp+0x1c]
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::InvokeFourWordCallback
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x6
    lea    edx,[esp+0x48]
    mov    DWORD PTR [esp+0x5c],ebx
    mov    DWORD PTR [esp+0x68],edx
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x5c],0x7
    jmp    Branch73
  Branch71:
    mov    edx,DWORD PTR [esp+0x68]
    lea    eax,[esp+0x1c]
    lea    ecx,[esp+0x2c]
    push   eax
    push   ecx
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    mov    ecx,esi
    mov    WORD PTR [esp+0x2a],0x5
    mov    BYTE PTR [esp+0x28],bl
    call   R6GameServiceAddresses::InvokeFourWordCallback
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x4
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x5c],ebx
    mov    DWORD PTR [esp+0x68],ecx
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x5c],0x5
    jmp    Branch73
  Branch72:
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x2
    lea    edx,[esp+0x48]
    mov    DWORD PTR [esp+0x5c],ebx
    mov    DWORD PTR [esp+0x68],edx
    mov    DWORD PTR [esp+0x48],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x5c],0x3
  Branch73:
    lea    ecx,[esp+0x48]
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x4c]
    mov    BYTE PTR [esp+0x5c],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x54]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret    0xc
  }
}

// Extracts tag/child, builds native ID-flag-word status, notifies CC with20 bytes or silently skips malformed headers, then releases temporary.
// R6GameService.dll @ 100252f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ParseTypeThreeInputRecord(void *owner,uint recordIdWord,uint endpointWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CCDKeyProcess_SelectType23Lifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x3c
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0xc],ebx
    push   edi
    mov    esi,ecx
    mov    BYTE PTR [esp+0xf],bl
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],0x3
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x44]
    mov    DWORD PTR [esp+0x54],ebx
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_LAB
    xor    ecx,ecx
    mov    edi,DWORD PTR [esp+0x60]
    mov    eax,DWORD PTR [esp+0x58]
    mov    DWORD PTR [esp+0x1c],ecx
    mov    DWORD PTR [esp+0x20],ecx
    lea    edx,[esp+0xf]
    mov    DWORD PTR [esp+0x24],ecx
    push   ebx
    mov    DWORD PTR [esp+0x2c],ecx
    push   edx
    mov    DWORD PTR [esp+0x34],ecx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x58],0x1
    mov    DWORD PTR [esp+0x1c],eax
    mov    WORD PTR [esp+0x22],bx
    call   R6GameServiceAddresses::ReadIndexedByte
    test   al,al
    je     Branch77
    lea    eax,[esp+0x30]
    push   0x1
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    je     Branch77
    mov    al,BYTE PTR [esp+0xf]
    push   ebx
    cmp    al,0x27
    jne    Branch74
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0x1c],bl
    push   ecx
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    dx,WORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x5c]
    lea    eax,[esp+0x1c]
    mov    WORD PTR [esp+0x1a],dx
    push   eax
    lea    edx,[esp+0x18]
    push   ecx
    push   edx
    jmp    Branch76
  Branch74:
    lea    eax,[esp+0x20]
    push   0x14
    push   eax
    lea    ecx,[esp+0x3c]
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne    Branch75
    mov    edx,DWORD PTR [esp+0x5c]
    lea    ecx,[esp+0x1c]
    push   ecx
    lea    eax,[esp+0x18]
    push   edx
    push   eax
    mov    ecx,esi
    mov    WORD PTR [esp+0x26],0x5
    mov    BYTE PTR [esp+0x24],bl
    call   R6GameServiceAddresses::InvokeThreeWordCallback
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x4
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x5c],ecx
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x50],0x5
    jmp    Branch78
  Branch75:
    mov    eax,DWORD PTR [esp+0x5c]
    lea    edx,[esp+0x1c]
    push   edx
    lea    ecx,[esp+0x18]
    push   eax
    mov    BYTE PTR [esp+0x20],0x1
    push   ecx
  Branch76:
    mov    ecx,esi
    call   R6GameServiceAddresses::InvokeThreeWordCallback
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x6
    lea    edx,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x5c],edx
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x50],0x7
    jmp    Branch78
  Branch77:
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x2
    lea    eax,[esp+0x3c]
    mov    DWORD PTR [esp+0x50],ebx
    mov    DWORD PTR [esp+0x5c],eax
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    BYTE PTR [esp+0x50],0x3
  Branch78:
    lea    ecx,[esp+0x3c]
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0x50],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x48]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x48
    ret    0xc
  }
}

// Consumes20-byte lookup, emits nonterminal error callbacks, records endpoint and arms periodic work, then emits native terminal/error continuation callbacks and cleans temporaries.
// R6GameService.dll @ 100254e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ParseTypeFourInputRecord(void *owner,uint recordIdWord,uint endpointWord,uint descriptorWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::CCDKeyProcess_SelectType14Lifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x70
    push   ebx
    xor    ebx,ebx
    push   ebp
    push   esi
    mov    DWORD PTR [esp+0x10],ebx
    mov    esi,ecx
    mov    BYTE PTR [esp+0xf],bl
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x68],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x78],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x6c],0x3
    mov    DWORD PTR [esp+0x64],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x74]
    mov    DWORD PTR [esp+0x88],ebx
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x64],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x70],R6GameServiceAddresses::clDataListPTR_LAB
    xor    ecx,ecx
    mov    eax,DWORD PTR [esp+0x8c]
    mov    DWORD PTR [esp+0x50],ecx
    xor    edx,edx
    mov    DWORD PTR [esp+0x54],ecx
    mov    DWORD PTR [esp+0x30],edx
    mov    DWORD PTR [esp+0x58],ecx
    mov    DWORD PTR [esp+0x34],edx
    mov    DWORD PTR [esp+0x5c],ecx
    mov    DWORD PTR [esp+0x38],edx
    mov    DWORD PTR [esp+0x60],ecx
    lea    ecx,[esp+0x50]
    push   ecx
    push   eax
    mov    ecx,esi
    mov    DWORD PTR [esp+0x8c],0x1
    mov    DWORD PTR [esp+0x1c],eax
    mov    WORD PTR [esp+0x22],bx
    mov    DWORD PTR [esp+0x44],edx
    call   R6GameServiceAddresses::RemoveFiveWordRecordById
    mov    ebp,DWORD PTR [esp+0x90]
    test   al,al
    jne    Branch79
    lea    edx,[esp+0x30]
    lea    eax,[esp+0x50]
    push   edx
    push   ebx
    push   eax
    lea    ecx,[esp+0x20]
    push   ebp
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x2c],bl
    mov    WORD PTR [esp+0x2e],0x5
    call   R6GameServiceAddresses::InvokeFiveWordCallback
  Branch79:
    mov    ecx,DWORD PTR [esp+0x94]
    lea    edx,[esp+0xf]
    push   ebx
    push   edx
    call   R6GameServiceAddresses::ReadIndexedByte
    test   al,al
    je     Branch80
    mov    ecx,DWORD PTR [esp+0x94]
    lea    eax,[esp+0x64]
    push   0x1
    push   eax
    call   R6GameServiceAddresses::CopyIndexedClDataList
    test   al,al
    jne    Branch81
  Branch80:
    lea    ecx,[esp+0x30]
    lea    edx,[esp+0x50]
    push   ecx
    push   ebx
    push   edx
    lea    eax,[esp+0x20]
    push   ebp
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [esp+0x2c],bl
    mov    WORD PTR [esp+0x2e],0x5
    call   R6GameServiceAddresses::InvokeFiveWordCallback
  Branch81:
    push   edi
    lea    ecx,[esp+0x98]
    push   ebx
    push   ecx
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x90],0x2
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x34],ebx
    call   R6GameServiceAddresses::StoreFirstWordIgnoringContext
    mov    edi,ebp
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR [esp+0x88],0x3
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,ebp
    push   ecx
    push   ebp
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::InitializeStringRange
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0x44]
    push   edx
    mov    BYTE PTR [esp+0x8c],0x4
    call   R6GameServiceAddresses::ConstructHeapByteString
    mov    ax,WORD PTR [ebp+0x82]
    mov    WORD PTR [esp+0x50],ax
    lea    ecx,[esp+0x44]
    lea    edx,[esp+0x20]
    push   ecx
    push   edx
    lea    ecx,[esi+0x48]
    mov    BYTE PTR [esp+0x90],0x5
    call   R6GameServiceAddresses::FindOrInsertByteDescriptorTreeEntry
    lea    ecx,[esp+0x44]
    mov    BYTE PTR [esp+0x88],0x6
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    mov    ecx,DWORD PTR [esp+0x30]
    mov    eax,DWORD PTR [esp+0x28]
    sub    ecx,eax
    mov    BYTE PTR [esp+0x88],0x7
    push   ecx
    push   eax
    lea    ecx,[esp+0x38]
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    mov    al,BYTE PTR [esp+0x13]
    pop    edi
    cmp    al,0x27
    mov    BYTE PTR [esp+0x84],0x1
    mov    BYTE PTR [esi+0x5e],0x1
    push   ebx
    jne    Branch82
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x68]
    push   edx
    mov    BYTE PTR [esp+0x20],bl
    call   R6GameServiceAddresses::ReadIndexedWord
    mov    ax,WORD PTR [esp+0x10]
    lea    ecx,[esp+0x30]
    push   ecx
    mov    WORD PTR [esp+0x1e],ax
    push   ebx
    jmp    Branch85
  Branch82:
    lea    ecx,[esp+0x98]
    mov    DWORD PTR [esp+0x98],ebx
    push   ecx
    lea    ecx,[esp+0x6c]
    call   R6GameServiceAddresses::ReadIndexedInt32
    test   al,al
    je     Branch83
    push   0x1
    lea    edx,[esp+0x34]
    push   0x10
    push   edx
    lea    ecx,[esp+0x70]
    call   R6GameServiceAddresses::CopyIndexedBytesExact
    test   al,al
    jne    Branch84
  Branch83:
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x50]
    push   eax
    push   ebx
    push   ecx
    lea    edx,[esp+0x20]
    push   ebp
    push   edx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x2c],bl
    mov    WORD PTR [esp+0x2e],0x5
    call   R6GameServiceAddresses::InvokeFiveWordCallback
  Branch84:
    mov    ecx,DWORD PTR [esp+0x94]
    lea    eax,[esp+0x30]
    push   eax
    mov    BYTE PTR [esp+0x1c],0x1
    push   ecx
  Branch85:
    lea    edx,[esp+0x58]
    lea    eax,[esp+0x1c]
    push   edx
    push   ebp
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::InvokeFiveWordCallback
    mov    DWORD PTR [esp+0x64],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x8
    lea    ecx,[esp+0x70]
    mov    DWORD PTR [esp+0x84],ebx
    mov    DWORD PTR [esp+0x94],ecx
    mov    DWORD PTR [esp+0x70],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x70]
    mov    BYTE PTR [esp+0x84],0x9
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x74]
    mov    BYTE PTR [esp+0x84],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x7c]
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x7c
    ret    0xc
  }
}

// Prewalks equal-ID range then clears whole tree or erases records individually, preserving destructor/free/count ordering and raw branch result.
// R6GameService.dll @ 100260b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall EraseRecordsForId(void *owner,uint recordIdWord)
{
  __asm {
    sub    esp,0xc
    push   ebx
    push   esi
    lea    esi,[ecx+0x8]
    lea    eax,[esp+0x18]
    push   edi
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::FindStrictUpperBoundCandidate
    lea    ecx,[esp+0x1c]
    mov    edi,eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::OrderedTreeLowerBound
    mov    ebx,edi
    cmp    eax,edi
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x14],ebx
    je     Branch87
  Branch86:
    push   eax
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ebx,DWORD PTR [esp+0x18]
    add    esp,0x4
    cmp    eax,ebx
    jne    Branch86
  Branch87:
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0xc]
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0xc]
    cmp    eax,DWORD PTR [ecx+0x8]
    jne    Branch90
    cmp    ebx,ecx
    jne    Branch90
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch92
    mov    edi,DWORD PTR [ecx+0x4]
    test   edi,edi
    je     Branch89
  Branch88:
    mov    eax,DWORD PTR [edi+0xc]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::ReleaseTreeNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push   0x0
    lea    ecx,[edi+0x10]
    call   R6GameServiceAddresses::DeleteEmbeddedBufferDescriptor
    push   0x1
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    test   ebx,ebx
    mov    edi,ebx
    jne    Branch88
  Branch89:
    mov    eax,DWORD PTR [esi]
    pop    edi
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch90:
    cmp    eax,ebx
    je     Branch92
  Branch91:
    push   eax
    mov    edi,eax
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,DWORD PTR [esi]
    lea    edx,[eax+0xc]
    lea    ecx,[eax+0x8]
    push   edx
    add    eax,0x4
    push   ecx
    push   eax
    push   edi
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    mov    edi,eax
    add    esp,0x14
    lea    ecx,[edi+0x10]
    call   R6GameServiceAddresses::ReturnEmbeddedBuffer
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esp+0xc]
    dec    edx
    cmp    eax,ebx
    mov    DWORD PTR [esi+0x4],edx
    jne    Branch91
  Branch92:
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x4
  }
}

// Resets incomplete type-one descriptor at parent-94.
// R6GameService.dll @ 10065040 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind59(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Passes construction scratch at parent-75 to native no-op.
// R6GameService.dll @ 1006504b : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind60(void)
{
  __asm {
    lea    ecx,[ebp-0x75]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Destroys completed type-one descriptor at parent-94.
// R6GameService.dll @ 10065053 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind61(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets type-one descriptor after malformed header cleanup entered.
// R6GameService.dll @ 1006510f : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind68(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-70, preserves null or adds4 through scratch-b0, then releases current header.
// R6GameService.dll @ 1006511a : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind69(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x70],0x0
    je     Branch93
    mov    eax,DWORD PTR [ebp-0x70]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xb0],eax
    jmp    Branch94
  Branch93:
    mov    DWORD PTR [ebp-0xb0],0x0
  Branch94:
    mov    ecx,DWORD PTR [ebp-0xb0]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-one descriptor after kind2 byte-copy failure cleanup entered.
// R6GameService.dll @ 10065099 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind64(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-74, preserves null or adds4 through scratch-b8, then releases current header.
// R6GameService.dll @ 100650a4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind65(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x74],0x0
    je     Branch95
    mov    eax,DWORD PTR [ebp-0x74]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xb8],eax
    jmp    Branch96
  Branch95:
    mov    DWORD PTR [ebp-0xb8],0x0
  Branch96:
    mov    ecx,DWORD PTR [ebp-0xb8]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-one descriptor after kind3 byte-copy failure cleanup entered.
// R6GameService.dll @ 1006505e : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind62(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-74, preserves null or adds4 through scratch-c0, then releases current header.
// R6GameService.dll @ 10065069 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind63(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x74],0x0
    je     Branch97
    mov    eax,DWORD PTR [ebp-0x74]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xc0],eax
    jmp    Branch98
  Branch97:
    mov    DWORD PTR [ebp-0xc0],0x0
  Branch98:
    mov    ecx,DWORD PTR [ebp-0xc0]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-one descriptor after general cleanup entered.
// R6GameService.dll @ 100650d4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind66(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads saved member at parent-74, preserves null or adds4 through scratch-dc, then releases current header.
// R6GameService.dll @ 100650df : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind67(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x74],0x0
    je     Branch99
    mov    eax,DWORD PTR [ebp-0x74]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xdc],eax
    jmp    Branch100
  Branch99:
    mov    DWORD PTR [ebp-0xdc],0x0
  Branch100:
    mov    ecx,DWORD PTR [ebp-0xdc]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets incomplete type-two descriptor at parent-24.
// R6GameService.dll @ 10065160 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind70(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys completed type-two descriptor at parent-24.
// R6GameService.dll @ 10065168 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind71(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets type-two descriptor after malformed header cleanup entered.
// R6GameService.dll @ 100651ce : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind76(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-60, then releases current header.
// R6GameService.dll @ 100651d6 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind77(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch101
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch102
  Branch101:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch102:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-two descriptor after malformed payload cleanup entered.
// R6GameService.dll @ 1006519f : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind74(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-68, then releases current header.
// R6GameService.dll @ 100651a7 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind75(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch103
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x68],eax
    jmp    Branch104
  Branch103:
    mov    DWORD PTR [ebp-0x68],0x0
  Branch104:
    mov    ecx,DWORD PTR [ebp-0x68]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-two descriptor after completed callback path cleanup entered.
// R6GameService.dll @ 10065170 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind72(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-70, then releases current header.
// R6GameService.dll @ 10065178 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind73(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch105
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x70],eax
    jmp    Branch106
  Branch105:
    mov    DWORD PTR [ebp-0x70],0x0
  Branch106:
    mov    ecx,DWORD PTR [ebp-0x70]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets incomplete type-three descriptor at parent-24.
// R6GameService.dll @ 10065210 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind78(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys completed type-three descriptor at parent-24.
// R6GameService.dll @ 10065218 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind79(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Resets type-three descriptor after malformed header cleanup entered.
// R6GameService.dll @ 1006527e : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind84(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-50, then releases current header.
// R6GameService.dll @ 10065286 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind85(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch107
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x50],eax
    jmp    Branch108
  Branch107:
    mov    DWORD PTR [ebp-0x50],0x0
  Branch108:
    mov    ecx,DWORD PTR [ebp-0x50]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-three descriptor after malformed payload cleanup entered.
// R6GameService.dll @ 10065220 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind80(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-58, then releases current header.
// R6GameService.dll @ 10065228 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind81(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch109
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x58],eax
    jmp    Branch110
  Branch109:
    mov    DWORD PTR [ebp-0x58],0x0
  Branch110:
    mov    ecx,DWORD PTR [ebp-0x58]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets type-three descriptor after completed callback path cleanup entered.
// R6GameService.dll @ 1006524f : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind82(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg2 as current list pointer, preserves null or adds4 through scratch-60, then releases current header.
// R6GameService.dll @ 10065257 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind83(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch111
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch112
  Branch111:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch112:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Resets incomplete type-four descriptor at parent-24.
// R6GameService.dll @ 100652c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind86(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroys completed type-four descriptor at parent-24.
// R6GameService.dll @ 100652c8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind87(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Passes original descriptor argument address to native no-op.
// R6GameService.dll @ 100652d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind88(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases first endpoint string at parent-64 during range construction.
// R6GameService.dll @ 100652d8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind89(void)
{
  __asm {
    lea    ecx,[ebp-0x64]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases first endpoint string at parent-64 during later copy/store cleanup.
// R6GameService.dll @ 100652e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind90(void)
{
  __asm {
    lea    ecx,[ebp-0x64]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Releases copied endpoint record buffer at parent-48.
// R6GameService.dll @ 100652e8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind91(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Passes copied-record capacity-word address at parent-40 to native no-op.
// R6GameService.dll @ 100652f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind92(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Passes initial-string capacity-word address at parent-5c to native no-op.
// R6GameService.dll @ 100652f8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind93(void)
{
  __asm {
    lea    ecx,[ebp-0x5c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Resets type-four descriptor after normal member cleanup entered.
// R6GameService.dll @ 10065300 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind94(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reloads original arg3 as current list pointer, preserves null or adds4 through scratch-90, then releases current header.
// R6GameService.dll @ 10065308 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CCDKeyProcess_CCDKeyProcessUnwind95(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0xc],0x0
    je     Branch113
    mov    eax,DWORD PTR [ebp+0xc]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x90],eax
    jmp    Branch114
  Branch113:
    mov    DWORD PTR [ebp-0x90],0x0
  Branch114:
    mov    ecx,DWORD PTR [ebp-0x90]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects nine-state parsed-record dispatcher descriptor lifetime.
// R6GameService.dll @ 10065034 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectParsedLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DispatchParsedInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects seven-state type-five payload/parser lifetime.
// R6GameService.dll @ 100653c6 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_SelectParsedLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseTypeFiveInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Parsed-record native lifetime record or recognized-kind dispatch table.
// R6GameService.dll data @ 1007f2c0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DispatchParsedInputRecordUnwindMap[9] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind50},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind51},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind58},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind52},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind53},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind56},
  {0x00000005, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind57},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind54},
  {0x00000007, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind55},
};

// Parsed-record native lifetime record or recognized-kind dispatch table.
// R6GameService.dll data @ 1007f308 : native storage identity retained.
const R6GameServiceNative::FuncInfo DispatchParsedInputRecordExceptionInfo = {
  0x19930520,
  0x00000009,
  R6GameServiceAddresses::DispatchParsedInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Parsed-record native lifetime record or recognized-kind dispatch table.
// R6GameService.dll data @ 1007f4bc : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseTypeFiveInputRecordUnwindMap[7] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind96},
  {0x00000000, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind97},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind98},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind99},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind100},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind101},
  {0x00000005, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind102},
};

// Parsed-record native lifetime record or recognized-kind dispatch table.
// R6GameService.dll data @ 1007f4f4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseTypeFiveInputRecordExceptionInfo = {
  0x19930520,
  0x00000007,
  R6GameServiceAddresses::ParseTypeFiveInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Parsed-record native lifetime record or recognized-kind dispatch table.
// R6GameService.dll data @ 10024c08 : native storage identity retained.
const uint CCDKeyProcessGParsedLifetimeData4[5] = {
  R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4Case1, R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4Case2, R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4Case3, R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4Case4,
  R6GameServiceAddresses::CCDKeyProcessGParsedLifetimeData4Case5
};

// Selects eight-state type-two parser descriptor lifetime.
// R6GameService.dll @ 100651fd : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectType23Lifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseTypeTwoInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects eight-state type-three parser descriptor lifetime.
// R6GameService.dll @ 100652ad : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_SelectType23Lifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseTypeThreeInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Type-two/type-three parser unwind state map or selector metadata.
// R6GameService.dll data @ 1007f398 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseTypeTwoInputRecordUnwindMap[8] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind70},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind71},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind76},
  {0x00000002, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind77},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind74},
  {0x00000004, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind75},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind72},
  {0x00000006, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind73},
};

// Type-two/type-three parser unwind state map or selector metadata.
// R6GameService.dll data @ 1007f3d8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseTypeTwoInputRecordExceptionInfo = {
  0x19930520,
  0x00000008,
  R6GameServiceAddresses::ParseTypeTwoInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Type-two/type-three parser unwind state map or selector metadata.
// R6GameService.dll data @ 1007f3f4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseTypeThreeInputRecordUnwindMap[8] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind78},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind79},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind84},
  {0x00000002, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind85},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind80},
  {0x00000004, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind81},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind82},
  {0x00000006, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind83},
};

// Type-two/type-three parser unwind state map or selector metadata.
// R6GameService.dll data @ 1007f434 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseTypeThreeInputRecordExceptionInfo = {
  0x19930520,
  0x00000008,
  R6GameServiceAddresses::ParseTypeThreeInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Consumes found kind-tree node and returns cached low16 kind with current decremented count upper16; miss clears only AX of head pointer.
// R6GameService.dll @ 100266a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall RemoveKindRecordById(void *owner,uint recordIdWord)
{
  __asm {
    push   esi
    lea    esi,[ecx+0x18]
    lea    eax,[esp+0x8]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::OrderedTreeFind
    cmp    eax,DWORD PTR [esi]
    jne    Branch115
    xor    ax,ax
    pop    esi
    ret    0x4
  Branch115:
    mov    ecx,DWORD PTR [esi]
    push   edi
    mov    di,WORD PTR [eax+0x14]
    lea    edx,[ecx+0xc]
    push   edx
    lea    edx,[ecx+0x8]
    add    ecx,0x4
    push   edx
    push   ecx
    push   eax
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    dec    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    ax,di
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Copies five forward DWORDs from found payload, reloads payload for free, erases node and returns AL1/current count upper24; miss clears only AL of head pointer.
// R6GameService.dll @ 10026800 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall RemoveFiveWordRecordById(void *owner,uint recordIdWord,uint outputWord)
{
  __asm {
    push   ebx
    lea    ebx,[ecx+0x28]
    lea    eax,[esp+0x8]
    push   ebp
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::OrderedTreeFind
    mov    ebp,eax
    mov    eax,DWORD PTR [ebx]
    cmp    ebp,eax
    jne    Branch116
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x8
  Branch116:
    push   esi
    mov    esi,DWORD PTR [ebp+0x14]
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    ecx,0x5
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,DWORD PTR [ebp+0x14]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx]
    lea    edx,[eax+0xc]
    lea    ecx,[eax+0x8]
    push   edx
    add    eax,0x4
    push   ecx
    push   eax
    push   ebp
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [ebx+0x4]
    pop    edi
    dec    eax
    pop    esi
    mov    DWORD PTR [ebx+0x4],eax
    pop    ebp
    mov    al,0x1
    pop    ebx
    ret    0x8
  }
}

// Reset the current context, feed two inputs, finalize on success, then reset again after ordinary completion.
// R6GameService.dll @ 10026d80 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall CCDKeyProcessFeedAndFinalize(void *owner,uint first,uint firstSize,uint second,uint secondSize,uint output)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    mov    bl,0x1
    mov    eax,DWORD PTR [esi+0x60]
    push   eax
    call   R6GameServiceAddresses::ResetHashAlgorithmThunk
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [esi+0x60]
    push   0x1
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::RepeatHashInputThunk
    test   al,al
    je     Branch117
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esi+0x60]
    push   0x1
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::RepeatHashInputThunk
    test   al,al
    je     Branch117
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esi+0x60]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::FinalizeAndCopyHashDigestThunk
    test   al,al
    jne    Branch118
  Branch117:
    xor    bl,bl
  Branch118:
    mov    eax,DWORD PTR [esi+0x60]
    push   eax
    call   R6GameServiceAddresses::ResetHashAlgorithmThunk
    mov    al,bl
    pop    esi
    pop    ebx
    ret    0x14
  }
}

// Build integer fields ID/2/2 and two20-byte fields, queue a datagram and release both descriptors.
// R6GameService.dll @ 10025ad0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendTag22Descriptor(void *owner,uint id,uint endpoint,uint first,uint second)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSendPairLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    xor    eax,eax
    mov    ebx,R6GameServiceAddresses::PTR_LAB
    push   esi
    mov    DWORD PTR [esp+0x8],eax
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],0x3
    mov    DWORD PTR [esp+0x28],ebx
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x4c],eax
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],0x3
    mov    DWORD PTR [esp+0x10],ebx
    mov    ebx,0x2
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x4c],bl
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x50]
    lea    ecx,[esp+0x10]
    push   eax
    mov    BYTE PTR [esp+0x4c],0x3
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0xc],ebx
    push   ecx
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0xc]
    lea    ecx,[esp+0x10]
    push   edx
    mov    DWORD PTR [esp+0x10],ebx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    push   0x14
    push   eax
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListBinary
    mov    ecx,DWORD PTR [esp+0x5c]
    push   0x14
    push   ecx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListBinary
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0x10]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    eax,DWORD PTR [esp+0x50]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::shared_native_NoOp
    mov    eax,DWORD PTR [esp+0x54]
    lea    ecx,[esp+0x10]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x58]
    mov    dx,WORD PTR [eax+0x82]
    push   edx
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    ebx,0x5
    lea    eax,[esp+0x34]
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x58],eax
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x48],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Build integer fields ID/3/1 and16-/20-byte fields, queue a datagram and release both descriptors.
// R6GameService.dll @ 10025c70 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendTag31Descriptor(void *owner,uint id,uint endpoint,uint first,uint second)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSendPairLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    xor    eax,eax
    mov    ebx,0x3
    push   esi
    mov    DWORD PTR [esp+0x8],eax
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esp+0x4c],eax
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    edi,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    DWORD PTR [esp+0x48],0x1
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x18],ebx
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x4c],0x2
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    eax,[esp+0x50]
    lea    ecx,[esp+0x10]
    push   eax
    mov    BYTE PTR [esp+0x4c],bl
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0xc],ebx
    push   ecx
    lea    ecx,[esp+0x14]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0xc]
    lea    ecx,[esp+0x10]
    push   edx
    mov    DWORD PTR [esp+0x10],0x1
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    mov    eax,DWORD PTR [esp+0x58]
    push   0x10
    push   eax
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListBinary
    mov    ecx,DWORD PTR [esp+0x5c]
    push   0x14
    push   ecx
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::AppendClDataListBinary
    lea    edx,[esp+0x28]
    lea    ecx,[esp+0x10]
    push   edx
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    eax,DWORD PTR [esp+0x50]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::shared_native_NoOp
    mov    eax,DWORD PTR [esp+0x54]
    lea    ecx,[esp+0x10]
    push   ecx
    mov    ecx,DWORD PTR [esi+0x58]
    mov    dx,WORD PTR [eax+0x82]
    push   edx
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    DWORD PTR [esp+0x10],edi
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x48],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x10],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],edi
    mov    ebx,0x5
    lea    eax,[esp+0x34]
    mov    DWORD PTR [esp+0x48],ebx
    mov    DWORD PTR [esp+0x58],eax
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x34]
    mov    BYTE PTR [esp+0x48],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x48],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Reset descriptor at parent-frame minus24 during send cleanup.
// R6GameService.dll @ 10065440 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy descriptor at parent-frame minus24 during send cleanup.
// R6GameService.dll @ 10065448 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor at parent-frame minus3c during send cleanup.
// R6GameService.dll @ 10065450 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy descriptor at parent-frame minus3c during send cleanup.
// R6GameService.dll @ 10065458 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor at parent-frame minus3c during send cleanup.
// R6GameService.dll @ 10065460 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor at parent-frame minus24 during send cleanup.
// R6GameService.dll @ 10065468 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release the current saved inner-list header through parent argument3, preserving NULL before adjustment.
// R6GameService.dll @ 10065470 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcessSharedLifetimeUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0xc],0x0
    je     Branch119
    mov    eax,DWORD PTR [ebp+0xc]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch120
  Branch119:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch120:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Selects type-one parser native descriptor/string lifetime record.
// R6GameService.dll @ 1006514a : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectType14Lifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseTypeOneInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects type-four parser native descriptor/string lifetime record.
// R6GameService.dll @ 10065338 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl CCDKeyProcess_SelectType14Lifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ParseTypeFourInputRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Type-one/type-four parser native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f324 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseTypeOneInputRecordUnwindMap[11] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind59},
  {0x00000000, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind60},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind61},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind68},
  {0x00000003, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind69},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind64},
  {0x00000005, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind65},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind62},
  {0x00000007, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind63},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind66},
  {0x00000009, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind67},
};

// Type-one/type-four parser native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f37c : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseTypeOneInputRecordExceptionInfo = {
  0x19930520,
  0x0000000b,
  R6GameServiceAddresses::ParseTypeOneInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Type-one/type-four parser native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f450 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ParseTypeFourInputRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind86},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind87},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind88},
  {0x00000002, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind89},
  {0x00000002, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind90},
  {0x00000004, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind91},
  {0x00000004, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind92},
  {0x00000002, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind93},
  {-1, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind94},
  {0x00000008, R6GameServiceAddresses::CCDKeyProcess_CCDKeyProcessUnwind95},
};

// Type-one/type-four parser native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f4a0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ParseTypeFourInputRecordExceptionInfo = {
  0x19930520,
  0x0000000a,
  R6GameServiceAddresses::ParseTypeFourInputRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Select the shared seven-state send descriptor lifetime record.
// R6GameService.dll @ 10065497 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectSendPairLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CCDKeyProcessSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Shared send-pair native descriptor unwind state map or selector metadata.
// R6GameService.dll data @ 1007f564 : native storage identity retained.
const R6GameServiceNative::UnwindEntry CCDKeyProcessSharedLifetimeUnwindMap3[7] = {
  {-1, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind1},
  {-1, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind2},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind3},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind4},
  {0x00000001, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind5},
  {-1, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind6},
  {0x00000005, R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwind7},
};

// Shared send-pair native descriptor unwind state map or selector metadata.
// R6GameService.dll data @ 1007f59c : native storage identity retained.
const R6GameServiceNative::FuncInfo CCDKeyProcessSharedLifetimeExceptionInfo3 = {
  0x19930520,
  0x00000007,
  R6GameServiceAddresses::CCDKeyProcessSharedLifetimeUnwindMap3,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Build ID/1/1 fields, store timestamped metadata, queue through the current socket and release descriptors.
// R6GameService.dll @ 10025940 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendTag11Descriptor(void *owner,uint id,uint endpoint,uint kind,uint value)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSend11Lifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    push   ebp
    xor    eax,eax
    push   esi
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    mov    edi,ecx
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x34],0x3
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::PTR_LAB
    push   eax
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x50],eax
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x38],ebx
    mov    esi,0x1
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x4c],esi
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push   0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0x50],0x2
    call   R6GameServiceAddresses::InitializePayloadListSentinel
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],ebx
    lea    eax,[esp+0x54]
    lea    ecx,[esp+0x14]
    push   eax
    mov    BYTE PTR [esp+0x50],0x3
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x10],esi
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x14],esi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x2c]
    lea    ecx,[esp+0x14]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    esi,DWORD PTR [esp+0x58]
    mov    edx,DWORD PTR [esp+0x60]
    mov    eax,DWORD PTR [esp+0x5c]
    mov    cx,WORD PTR [esi+0x82]
    push   ecx
    mov    ecx,DWORD PTR [esp+0x58]
    push   esi
    push   edx
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::StoreTimestampedDescriptorRecord
    mov    ax,WORD PTR [esi+0x82]
    mov    ecx,DWORD PTR [edi+0x58]
    lea    edx,[esp+0x14]
    push   edx
    push   eax
    push   esi
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    DWORD PTR [esp+0x14],ebp
    mov    DWORD PTR [esp+0x20],ebx
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x4c],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x2c],ebp
    mov    ebx,0x5
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0x4c],ebx
    mov    DWORD PTR [esp+0x58],ecx
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0x4c],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x4c],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    ecx,DWORD PTR [esp+0x44]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x40
    ret    0x10
  }
}

// Insert a unique unsigned ID and low16 kind in owner+18, preserving duplicate payloads and native raw returns.
// R6GameService.dll @ 100266f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InsertKindRecordById(void *owner,uint id,uint kind)
{
  __asm {
    sub    esp,0x8
    mov    dx,WORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    push   ebx
    push   ebp
    lea    ebp,[ecx+0x18]
    mov    WORD PTR [esp+0xc],dx
    push   esi
    mov    DWORD PTR [esp+0xc],eax
    mov    edx,DWORD PTR [ebp+0x0]
    push   edi
    mov    edi,edx
    mov    cl,0x1
    mov    esi,DWORD PTR [edx+0x4]
    test   esi,esi
    je     Branch124
  Branch121:
    mov    ecx,DWORD PTR [esi+0x10]
    mov    edi,esi
    cmp    eax,ecx
    setb   cl
    test   cl,cl
    je     Branch122
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch123
  Branch122:
    mov    esi,DWORD PTR [esi+0xc]
  Branch123:
    test   esi,esi
    jne    Branch121
  Branch124:
    test   cl,cl
    mov    ebx,edi
    je     Branch129
    cmp    edi,DWORD PTR [edx+0x8]
    jne    Branch128
    cmp    edi,edx
    je     Branch125
    test   esi,esi
    jne    Branch125
    cmp    eax,DWORD PTR [edi+0x10]
    jb     Branch125
    lea    eax,[esp+0x10]
    mov    ecx,ebp
    push   eax
    call   R6GameServiceAddresses::AllocateKeyedPairNode
    mov    DWORD PTR [edi+0xc],eax
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    edi,DWORD PTR [ecx+0xc]
    jne    Branch127
    mov    DWORD PTR [ecx+0xc],eax
    jmp    Branch127
  Branch125:
    lea    ecx,[esp+0x10]
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::AllocateKeyedPairNode
    mov    DWORD PTR [edi+0x8],eax
    mov    ecx,DWORD PTR [ebp+0x0]
    cmp    edi,ecx
    jne    Branch126
    mov    DWORD PTR [ecx+0x4],eax
    mov    edx,DWORD PTR [ebp+0x0]
    mov    DWORD PTR [edx+0xc],eax
    jmp    Branch127
  Branch126:
    cmp    edi,DWORD PTR [ecx+0x8]
    jne    Branch127
    mov    DWORD PTR [ecx+0x8],eax
  Branch127:
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x4],edi
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,0x4
    push   ecx
    push   eax
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [ebp+0x4]
    add    esp,0x8
    inc    eax
    pop    edi
    mov    DWORD PTR [ebp+0x4],eax
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch128:
    push   edi
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    ebx,eax
  Branch129:
    mov    edx,DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esp+0x10]
    cmp    edx,eax
    jae    Branch130
    lea    eax,[esp+0x10]
    push   0x0
    push   eax
    push   edi
    lea    ecx,[esp+0x2c]
    push   esi
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::InsertUnsignedKeyTreeNodeAtHint
  Branch130:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Allocate20 bytes, insert a unique unsigned ID, then copy five words; duplicate IDs free only the new buffer.
// R6GameService.dll @ 10026870 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InsertFiveWordRecordById(void *owner,uint id,uint source)
{
  __asm {
    sub    esp,0xc
    push   ebx
    push   ebp
    push   esi
    push   edi
    push   0x14
    mov    esi,ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esi+0x28]
    lea    edi,[esi+0x28]
    mov    ecx,eax
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x14],eax
    mov    DWORD PTR [esp+0x18],ecx
    mov    esi,DWORD PTR [edx+0x4]
    mov    DWORD PTR [esp+0x10],ecx
    test   esi,esi
    mov    ebp,edx
    mov    cl,0x1
    je     Branch134
  Branch131:
    mov    ecx,DWORD PTR [esi+0x10]
    mov    ebp,esi
    cmp    eax,ecx
    setb   cl
    test   cl,cl
    je     Branch132
    mov    esi,DWORD PTR [esi+0x8]
    jmp    Branch133
  Branch132:
    mov    esi,DWORD PTR [esi+0xc]
  Branch133:
    test   esi,esi
    jne    Branch131
  Branch134:
    test   cl,cl
    mov    ebx,ebp
    je     Branch139
    cmp    ebp,DWORD PTR [edx+0x8]
    jne    Branch138
    cmp    ebp,edx
    je     Branch135
    test   esi,esi
    jne    Branch135
    cmp    eax,DWORD PTR [ebp+0x10]
    jb     Branch135
    lea    eax,[esp+0x14]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    DWORD PTR [ebp+0xc],eax
    mov    ecx,DWORD PTR [edi]
    cmp    ebp,DWORD PTR [ecx+0xc]
    jne    Branch137
    mov    DWORD PTR [ecx+0xc],eax
    jmp    Branch137
  Branch135:
    lea    ecx,[esp+0x14]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    DWORD PTR [ebp+0x8],eax
    mov    ecx,DWORD PTR [edi]
    cmp    ebp,ecx
    jne    Branch136
    mov    DWORD PTR [ecx+0x4],eax
    mov    edx,DWORD PTR [edi]
    mov    DWORD PTR [edx+0xc],eax
    jmp    Branch137
  Branch136:
    cmp    ebp,DWORD PTR [ecx+0x8]
    jne    Branch137
    mov    DWORD PTR [ecx+0x8],eax
  Branch137:
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x4],ebp
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    ecx,DWORD PTR [edi]
    add    ecx,0x4
    push   ecx
    push   eax
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [esp+0x2c]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [edi+0x4],eax
    mov    edi,DWORD PTR [esp+0x10]
    mov    ecx,0x5
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch138:
    push   ebp
    call   R6GameServiceAddresses::OrderedTreePredecessor
    add    esp,0x4
    mov    ebx,eax
  Branch139:
    mov    edx,DWORD PTR [ebx+0x10]
    mov    eax,DWORD PTR [esp+0x14]
    cmp    edx,eax
    jae    Branch140
    lea    eax,[esp+0x14]
    push   0x0
    push   eax
    push   ebp
    lea    ecx,[esp+0x2c]
    push   esi
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::InsertPairTreeNodeAtHint
    mov    esi,DWORD PTR [esp+0x24]
    mov    edi,DWORD PTR [esp+0x10]
    mov    ecx,0x5
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch140:
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// Find a20-byte key, cache its full record value, free the key, detach/free the node and decrement current count.
// R6GameService.dll @ 100269c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall TakeOwnedValueForKey(void *owner,uint key)
{
  __asm {
    push   ebx
    push   esi
    lea    esi,[ecx+0x38]
    lea    eax,[esp+0xc]
    push   edi
    push   eax
    mov    ecx,esi
    xor    ebx,ebx
    call   R6GameServiceAddresses::FindTwentyByteKeyNode
    mov    edi,eax
    mov    eax,DWORD PTR [esi]
    cmp    edi,eax
    je     Branch141
    mov    ecx,DWORD PTR [edi+0x10]
    mov    ebx,DWORD PTR [edi+0x14]
    push   ecx
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi]
    lea    edx,[eax+0xc]
    lea    ecx,[eax+0x8]
    push   edx
    add    eax,0x4
    push   ecx
    push   eax
    push   edi
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x14
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    dec    DWORD PTR [esi+0x4]
  Branch141:
    pop    edi
    mov    eax,ebx
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Copy20 bytes before lookup, insert a unique lexical key with its value, or free the duplicate copy.
// R6GameService.dll @ 10026a10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall InsertTwentyByteKey(void *owner,uint value,uint source)
{
  __asm {
    sub    esp,0xc
    push   ebx
    push   ebp
    push   esi
    push   edi
    push   0x14
    mov    ebx,ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,DWORD PTR [esp+0x24]
    mov    ecx,0x5
    mov    edi,eax
    mov    DWORD PTR [esp+0x14],eax
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x18],ecx
    lea    ecx,[ebx+0x38]
    mov    DWORD PTR [esp+0x24],ecx
    mov    dl,0x1
    mov    ebx,DWORD PTR [ecx]
    mov    ebp,DWORD PTR [ebx+0x4]
    test   ebp,ebp
    je     Branch146
  Branch142:
    mov    edi,DWORD PTR [ebp+0x10]
    mov    ecx,0x14
    mov    esi,eax
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    mov    ebx,ebp
    je     Branch143
    sbb    edx,edx
    sbb    edx,0xffffffff
  Branch143:
    test   edx,edx
    setl   dl
    test   dl,dl
    je     Branch144
    mov    ebp,DWORD PTR [ebp+0x8]
    jmp    Branch145
  Branch144:
    mov    ebp,DWORD PTR [ebp+0xc]
  Branch145:
    test   ebp,ebp
    jne    Branch142
    mov    ecx,DWORD PTR [esp+0x24]
  Branch146:
    test   dl,dl
    mov    esi,ebx
    je     Branch152
    mov    edx,DWORD PTR [ecx]
    cmp    ebx,DWORD PTR [edx+0x8]
    jne    Branch151
    cmp    ebx,edx
    je     Branch148
    test   ebp,ebp
    jne    Branch148
    mov    edi,DWORD PTR [ebx+0x10]
    mov    esi,eax
    mov    ecx,0x14
    xor    eax,eax
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch147
    sbb    eax,eax
    sbb    eax,0xffffffff
  Branch147:
    mov    ecx,DWORD PTR [esp+0x24]
    test   eax,eax
    jl     Branch148
    lea    edx,[esp+0x14]
    push   edx
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    ecx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [ebx+0xc],eax
    mov    ecx,DWORD PTR [ecx]
    cmp    ebx,DWORD PTR [ecx+0xc]
    jne    Branch150
    mov    DWORD PTR [ecx+0xc],eax
    jmp    Branch150
  Branch148:
    lea    edx,[esp+0x14]
    push   edx
    call   R6GameServiceAddresses::AllocatePairTreeNode
    mov    edx,DWORD PTR [esp+0x24]
    mov    DWORD PTR [ebx+0x8],eax
    mov    ecx,DWORD PTR [edx]
    cmp    ebx,ecx
    jne    Branch149
    mov    DWORD PTR [ecx+0x4],eax
    mov    ecx,DWORD PTR [edx]
    mov    DWORD PTR [ecx+0xc],eax
    jmp    Branch150
  Branch149:
    cmp    ebx,DWORD PTR [ecx+0x8]
    jne    Branch150
    mov    DWORD PTR [ecx+0x8],eax
  Branch150:
    mov    esi,DWORD PTR [esp+0x24]
    xor    ecx,ecx
    mov    DWORD PTR [eax+0x4],ebx
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    mov    edx,DWORD PTR [esi]
    add    edx,0x4
    push   edx
    push   eax
    call   R6GameServiceAddresses::RebalanceOrderedTreeAfterInsertion
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x8
    inc    eax
    mov    DWORD PTR [esi+0x4],eax
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch151:
    push   ebx
    call   R6GameServiceAddresses::OrderedTreePredecessor
    mov    esi,eax
    mov    eax,DWORD PTR [esp+0x14]
    add    esp,0x4
  Branch152:
    mov    edi,DWORD PTR [esp+0x14]
    mov    esi,DWORD PTR [esi+0x10]
    mov    ecx,0x14
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    je     Branch153
    sbb    edx,edx
    sbb    edx,0xffffffff
  Branch153:
    test   edx,edx
    jge    Branch154
    lea    eax,[esp+0x14]
    push   0x0
    push   eax
    push   ebx
    lea    ecx,[esp+0x30]
    push   ebp
    push   ecx
    mov    ecx,DWORD PTR [esp+0x38]
    call   R6GameServiceAddresses::InsertTwentyByteKeyTreeNodeAtHint
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch154:
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// Reset descriptor at parent-frame minus24 during tag11 cleanup.
// R6GameService.dll @ 100653d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy descriptor at parent-frame minus24 during tag11 cleanup.
// R6GameService.dll @ 100653d8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor at parent-frame minus3c during tag11 cleanup.
// R6GameService.dll @ 100653e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy descriptor at parent-frame minus3c during tag11 cleanup.
// R6GameService.dll @ 100653e8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset descriptor at parent-frame minus3c during tag11 cleanup.
// R6GameService.dll @ 100653f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset descriptor at parent-frame minus24 during tag11 cleanup.
// R6GameService.dll @ 100653f8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release the current saved inner-list header through original endpoint argument, preserving NULL before adjustment.
// R6GameService.dll @ 10065400 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendTag11DescriptorUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp+0x8],0x0
    je     Branch155
    mov    eax,DWORD PTR [ebp+0x8]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x60],eax
    jmp    Branch156
  Branch155:
    mov    DWORD PTR [ebp-0x60],0x0
  Branch156:
    mov    ecx,DWORD PTR [ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the tag11 send method seven-state descriptor lifetime record.
// R6GameService.dll @ 10065427 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectSend11Lifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendTag11DescriptorExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tag11 send native descriptor unwind state map or selector metadata.
// R6GameService.dll data @ 1007f510 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendTag11DescriptorUnwindMap[7] = {
  {-1, R6GameServiceAddresses::SendTag11DescriptorUnwind1},
  {-1, R6GameServiceAddresses::SendTag11DescriptorUnwind2},
  {0x00000001, R6GameServiceAddresses::SendTag11DescriptorUnwind3},
  {0x00000001, R6GameServiceAddresses::SendTag11DescriptorUnwind4},
  {0x00000001, R6GameServiceAddresses::SendTag11DescriptorUnwind5},
  {-1, R6GameServiceAddresses::SendTag11DescriptorUnwind6},
  {0x00000005, R6GameServiceAddresses::SendTag11DescriptorUnwind7},
};

// Tag11 send native descriptor unwind state map or selector metadata.
// R6GameService.dll data @ 1007f548 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendTag11DescriptorExceptionInfo = {
  0x19930520,
  0x00000007,
  R6GameServiceAddresses::SendTag11DescriptorUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Storage-parent locals span logical EBP-0x70..-4: iterator, input fields, insertion pair, first pair, EH chain.
struct TimestampedDescriptorStoreFrame {
  int insertionResult[2];
  TimestampedDescriptorFields inputFields;
  TimestampedDescriptorPair insertionPair;
  TimestampedDescriptorPair firstPair;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Capture timed metadata, copy three address views, attempt ID-keyed insertion and release all temporary buffers.
// R6GameService.dll @ 10025e10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall StoreTimestampedDescriptorRecord(
    void *owner,uint recordId,uint descriptorTypeWord,uint intervalWord,const char *endpointAddress,uint endpointPortWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::TimestampedDescriptorStoreExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x64
    push   ebx
    push   esi
    mov    ebx,ecx
    push   edi
    lea    ecx,[esp+0x20]
    call   R6GameServiceAddresses::InitializePooledBufferDescriptor
    push   0x0
    mov    DWORD PTR [esp+0x7c],0x0
    call   R6GameServiceAddresses::time
    mov    cx,WORD PTR [esp+0x8c]
    mov    edx,DWORD PTR [esp+0x90]
    mov    DWORD PTR [esp+0x1c],eax
    mov    ax,WORD PTR [esp+0x88]
    mov    WORD PTR [esp+0x18],ax
    mov    WORD PTR [esp+0x20],cx
    mov    edi,edx
    or     ecx,0xffffffff
    xor    eax,eax
    add    esp,0x4
    repnz  scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,edx
    push   ecx
    push   edx
    lea    ecx,[esp+0x28]
    call   R6GameServiceAddresses::AssignPooledByteStringRange
    mov    dx,WORD PTR [esp+0x90]
    lea    eax,[esp+0x14]
    mov    WORD PTR [esp+0x2c],dx
    lea    ecx,[esp+0x80]
    push   eax
    lea    edx,[esp+0x54]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::ConstructTimestampedDescriptorPair
    add    esp,0xc
    mov    esi,eax
    mov    eax,DWORD PTR [esi]
    mov    BYTE PTR [esp+0x78],0x1
    mov    DWORD PTR [esp+0x30],eax
    mov    cx,WORD PTR [esi+0x4]
    mov    WORD PTR [esp+0x34],cx
    mov    edx,DWORD PTR [esi+0x8]
    lea    ecx,[esi+0x10]
    mov    DWORD PTR [esp+0x38],edx
    mov    ax,WORD PTR [esi+0xc]
    push   ecx
    lea    ecx,[esp+0x44]
    mov    WORD PTR [esp+0x40],ax
    call   R6GameServiceAddresses::ConstructPooledByteStringFromTriplet
    mov    dx,WORD PTR [esi+0x1c]
    mov    WORD PTR [esp+0x4c],dx
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0xc]
    push   eax
    push   ecx
    lea    ecx,[ebx+0x8]
    mov    BYTE PTR [esp+0x80],0x2
    call   R6GameServiceAddresses::FindOrInsertUnsignedKeyTreeEntry
    lea    edx,[esp+0x40]
    mov    DWORD PTR [esp+0x84],edx
    mov    ecx,DWORD PTR [esp+0x48]
    mov    eax,DWORD PTR [esp+0x40]
    sub    ecx,eax
    mov    BYTE PTR [esp+0x78],0x3
    push   ecx
    push   eax
    lea    ecx,[esp+0x50]
    call   R6GameServiceAddresses::ReturnBlockToPoolOrAllocator
    lea    edx,[esp+0x60]
    mov    DWORD PTR [esp+0x84],edx
    mov    eax,DWORD PTR [esp+0x68]
    mov    ecx,DWORD PTR [esp+0x60]
    mov    BYTE PTR [esp+0x78],0x4
    sub    eax,ecx
    push   eax
    push   ecx
    lea    ecx,[esp+0x70]
    call   R6GameServiceAddresses::ReturnBlockToPoolOrAllocator
    lea    eax,[esp+0x20]
    mov    DWORD PTR [esp+0x84],eax
    mov    ecx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x20]
    sub    ecx,eax
    mov    DWORD PTR [esp+0x78],0x5
    push   ecx
    push   eax
    lea    ecx,[esp+0x30]
    call   R6GameServiceAddresses::ReturnBlockToPoolOrAllocator
    mov    ecx,DWORD PTR [esp+0x70]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x70
    ret    0x14
  }
}

// Release input fields at parent EBP-0x68.
// R6GameService.dll @ 100654b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl ReleaseTimestampedInputFields(void)
{
  __asm {
    lea    ecx,[ebp-0x68]
    jmp    R6GameServiceAddresses::ReturnCachedAllocation
  }
}

// Release the first copied pair at parent EBP-0x2c.
// R6GameService.dll @ 100654b8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl ReleaseTimestampedFirstPair(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ReturnEmbeddedBuffer
  }
}

// Release the insertion pair at parent EBP-0x4c.
// R6GameService.dll @ 100654c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl ReleaseTimestampedInsertionPair(void)
{
  __asm {
    lea    ecx,[ebp-0x4c]
    jmp    R6GameServiceAddresses::ReturnEmbeddedBuffer
  }
}

// Forward current original argument2 plus8 to the empty insertion-capacity cleanup.
// R6GameService.dll @ 100654c8 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CleanupTimestampedInsertionCapacity(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Forward current original argument2 plus8 to the empty first-pair capacity cleanup.
// R6GameService.dll @ 100654d3 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CleanupTimestampedFirstPairCapacity(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Forward current original argument2 plus8 to the empty input-capacity cleanup.
// R6GameService.dll @ 100654de : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl CleanupTimestampedInputCapacity(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select the metadata store six-state lifetime record.
// R6GameService.dll @ 100654e9 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) void __cdecl TimestampedDescriptorStoreExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::StoreTimestampedDescriptorRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Build expiry descriptors; skip initial zero intervals and dispatch strictly overdue records before advancing and erasing.
// R6GameService.dll @ 100261c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall ProcessExpiredInputRecords(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectExpiryLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc0
    push   esi
    push   edi
    mov    esi,ecx
    xor    edi,edi
    mov    DWORD PTR [esp+0x8],edi
    mov    DWORD PTR [esp+0xc],esi
    cmp    DWORD PTR [esi+0xc],edi
    je     Branch172
    push   ebx
    push   edi
    call   R6GameServiceAddresses::time
    add    esp,0x4
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [esi+0x8]
    mov    ebx,R6GameServiceAddresses::ClDataListBaseOffsets
    push   edi
    push   0x3
    mov    esi,DWORD PTR [eax+0x8]
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x24],ebx
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call   R6GameServiceAddresses::InitializeClDataFields
    push   edi
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0xd8],edi
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_LAB
    mov    edi,0x1
    push   0x0
    push   0x3
    lea    ecx,[esp+0x38]
    mov    DWORD PTR [esp+0xdc],edi
    mov    DWORD PTR [esp+0x3c],ebx
    mov    DWORD PTR [esp+0x4c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call   R6GameServiceAddresses::InitializeClDataFields
    push   0x0
    lea    ecx,[esp+0x40]
    mov    BYTE PTR [esp+0xd8],0x2
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebx,R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x30],ebx
    lea    ecx,[esp+0x14]
    mov    BYTE PTR [esp+0xd4],0x3
    push   ecx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x18],edi
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x18]
    push   edx
    mov    DWORD PTR [esp+0x18],0x27
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    eax,[esp+0x30]
    lea    ecx,[esp+0x18]
    push   eax
    call   R6GameServiceAddresses::AppendClDataListCopy
    mov    ecx,0x20
    xor    eax,eax
    lea    edi,[esp+0x48]
    rep    stos DWORD PTR es:[edi],eax
    stos   BYTE PTR es:[edi],al
    mov    edi,DWORD PTR [esp+0x10]
    mov    WORD PTR [esp+0xca],0x0
    cmp    esi,DWORD PTR [edi+0x8]
    je     Branch171
  Branch157:
    cmp    WORD PTR [esi+0x1c],0x0
    je     Branch165
    mov    ecx,DWORD PTR [esi+0x18]
    mov    edx,DWORD PTR [esp+0xc]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::difftime
    xor    eax,eax
    add    esp,0x8
    mov    ax,WORD PTR [esi+0x1c]
    mov    DWORD PTR [esp+0x10],eax
    fild   DWORD PTR [esp+0x10]
    fcompp
    fnstsw ax
    test   ah,0x5
    jp     Branch165
    mov    ecx,DWORD PTR [esi+0x20]
    lea    edx,[esp+0x48]
  Branch158:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch158
    mov    cx,WORD PTR [esi+0x2c]
    xor    eax,eax
    mov    WORD PTR [esp+0xca],cx
    mov    ax,WORD PTR [esi+0x14]
    dec    eax
    cmp    eax,0x3
    ja     Branch159
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GExpiryNativeData]
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0x18]
    lea    eax,[esp+0x48]
    push   edx
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseTypeOneInputRecord
    jmp    Branch159
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0x18]
    lea    eax,[esp+0x48]
    push   edx
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseTypeTwoInputRecord
    jmp    Branch159
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0x18]
    lea    eax,[esp+0x48]
    push   edx
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseTypeThreeInputRecord
    jmp    Branch159
    mov    ecx,DWORD PTR [esi+0x10]
    lea    edx,[esp+0x18]
    lea    eax,[esp+0x48]
    push   edx
    push   eax
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseTypeFourInputRecord
  Branch159:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,esi
    test   eax,eax
    je     Branch161
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    je     Branch164
  Branch160:
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    jne    Branch160
    mov    edx,DWORD PTR [ecx+0x10]
    mov    ecx,edi
    push   edx
    call   R6GameServiceAddresses::EraseRecordsForId
    jmp    Branch170
  Branch161:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch163
  Branch162:
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    je     Branch162
  Branch163:
    cmp    DWORD PTR [esi+0xc],eax
    je     Branch164
    mov    esi,eax
  Branch164:
    mov    edx,DWORD PTR [ecx+0x10]
    mov    ecx,edi
    push   edx
    call   R6GameServiceAddresses::EraseRecordsForId
    jmp    Branch170
  Branch165:
    mov    eax,DWORD PTR [esi+0xc]
    test   eax,eax
    je     Branch167
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    je     Branch170
  Branch166:
    mov    esi,eax
    mov    eax,DWORD PTR [esi+0x8]
    test   eax,eax
    jne    Branch166
    jmp    Branch170
  Branch167:
    mov    eax,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    jne    Branch169
  Branch168:
    mov    esi,eax
    mov    eax,DWORD PTR [eax+0x4]
    cmp    esi,DWORD PTR [eax+0xc]
    je     Branch168
  Branch169:
    cmp    DWORD PTR [esi+0xc],eax
    je     Branch170
    mov    esi,eax
  Branch170:
    cmp    esi,DWORD PTR [edi+0x8]
    jne    Branch157
  Branch171:
    mov    DWORD PTR [esp+0x30],ebx
    mov    DWORD PTR [esp+0x3c],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0xd4],0x4
    call   R6GameServiceAddresses::DestroyClDataPointerList
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x18],ebx
    mov    ebx,0x5
    lea    eax,[esp+0x24]
    mov    DWORD PTR [esp+0xd4],ebx
    mov    DWORD PTR [esp+0xc],eax
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN2
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xd4],0x6
    call   R6GameServiceAddresses::InvokePointerListClearRange
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xd4],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    pop    ebx
  Branch172:
    mov    ecx,DWORD PTR [esp+0xc8]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xcc
    ret
  }
}

// After a strict25-second gate, publish current time and send0/7 descriptors to current in-order endpoint records.
// R6GameService.dll @ 100264d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall SendPeriodicCollectionSnapshot(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSnapshotLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xa0
    push   ebx
    push   ebp
    mov    ebp,ecx
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x8],ebx
    push   esi
    mov    eax,DWORD PTR [ebp+0x48]
    push   edi
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch180
    push   ebx
    call   R6GameServiceAddresses::time
    mov    edi,eax
    mov    eax,DWORD PTR [ebp+0xd8]
    push   eax
    push   edi
    call   R6GameServiceAddresses::difftime
    fcomp  QWORD PTR ds:R6GameServiceAddresses::NativeDouble25_0
    add    esp,0xc
    fnstsw ax
    and    eax,0x4100
    jne    Branch180
    mov    DWORD PTR [ebp+0xd8],edi
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x1c],0x3
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::PTR_LAB
    push   ebx
    lea    ecx,[esp+0x24]
    mov    DWORD PTR [esp+0xbc],ebx
    call   R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_LAB
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0xb8],0x1
    push   ecx
    lea    ecx,[esp+0x18]
    mov    DWORD PTR [esp+0x14],ebx
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    lea    edx,[esp+0x10]
    lea    ecx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x14],0x7
    call   R6GameServiceAddresses::AppendClDataListSignedDecimal
    cmp    esi,DWORD PTR [ebp+0x48]
    je     Branch179
  Branch173:
    mov    ecx,0x20
    xor    eax,eax
    lea    edi,[esp+0x30]
    push   0x7f
    rep    stos DWORD PTR es:[edi],eax
    mov    eax,DWORD PTR [esi+0x10]
    push   eax
    lea    eax,[esp+0x38]
    push   eax
    call   R6GameServiceAddresses::strncpy
    mov    dx,WORD PTR [esi+0x1c]
    add    esp,0xc
    lea    ecx,[esp+0x14]
    lea    eax,[esp+0x30]
    push   ecx
    mov    ecx,DWORD PTR [ebp+0x58]
    push   edx
    push   eax
    call   R6GameServiceAddresses::QueueSerializedDatagram
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    cmp    ecx,ebx
    je     Branch175
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebx
    je     Branch178
  Branch174:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebx
    jne    Branch174
    jmp    Branch178
  Branch175:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch177
  Branch176:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch176
  Branch177:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch178
    mov    eax,ecx
  Branch178:
    mov    ecx,DWORD PTR [ebp+0x48]
    mov    esi,eax
    cmp    eax,ecx
    jne    Branch173
  Branch179:
    mov    DWORD PTR [esp+0x14],R6GameServiceAddresses::clDataListPTR_FUN
    mov    ebx,0x2
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0xb8],ebx
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    edx,DWORD PTR [esp+0x24]
    push   ecx
    mov    eax,esp
    push   ecx
    push   esp
    lea    ecx,[esp+0x30]
    mov    BYTE PTR [esp+0xc4],0x3
    mov    DWORD PTR [eax],edx
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    edx,DWORD PTR [esp+0x28]
    lea    eax,[esp+0x34]
    push   eax
    lea    ecx,[esp+0x2c]
    call   DWORD PTR [edx+0x10]
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xb8],bl
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
  Branch180:
    mov    ecx,DWORD PTR [esp+0xb0]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0xac
    ret
  }
}

// Reset the expiry descriptor at parent EBP-0xc0.
// R6GameService.dll @ 10065520 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0xc0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the expiry descriptor at parent EBP-0xc0.
// R6GameService.dll @ 1006552b : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0xc0]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the expiry descriptor at parent EBP-0xa8.
// R6GameService.dll @ 10065536 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the expiry descriptor at parent EBP-0xa8.
// R6GameService.dll @ 10065541 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the expiry descriptor at parent EBP-0xa8.
// R6GameService.dll @ 1006554c : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset the expiry descriptor at parent EBP-0xc0.
// R6GameService.dll @ 10065557 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0xc0]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release the header through the current saved member at EBP-0xcc; preserve NULL before adding 4.
// R6GameService.dll @ 10065562 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl ProcessExpiredInputRecordsUnwind7(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0xcc],0x0
    je     Branch181
    mov    eax,DWORD PTR [ebp-0xcc]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10c],eax
    jmp    Branch182
  Branch181:
    mov    DWORD PTR [ebp-0x10c],0x0
  Branch182:
    mov    ecx,DWORD PTR [ebp-0x10c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Reset the snapshot descriptor at parent-frame minusa8.
// R6GameService.dll @ 100655b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendPeriodicCollectionSnapshotUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy the completed snapshot descriptor at parent-frame minusa8.
// R6GameService.dll @ 100655bb : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendPeriodicCollectionSnapshotUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset the snapshot descriptor after member cleanup begins.
// R6GameService.dll @ 100655c6 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendPeriodicCollectionSnapshotUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0xa8]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Release the header through the current parent saved pointer, preserving NULL before adding4.
// R6GameService.dll @ 100655d1 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SendPeriodicCollectionSnapshotUnwind4(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0xac],0x0
    je     Branch183
    mov    eax,DWORD PTR [ebp-0xac]
    add    eax,0x4
    mov    DWORD PTR [ebp-0xec],eax
    jmp    Branch184
  Branch183:
    mov    DWORD PTR [ebp-0xec],0x0
  Branch184:
    mov    ecx,DWORD PTR [ebp-0xec]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinel
  }
}

// Select the snapshot method four-state descriptor lifetime record.
// R6GameService.dll @ 10065607 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectSnapshotLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SendPeriodicCollectionSnapshotExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Periodic snapshot native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f718 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SendPeriodicCollectionSnapshotUnwindMap[4] = {
  {-1, R6GameServiceAddresses::SendPeriodicCollectionSnapshotUnwind1},
  {-1, R6GameServiceAddresses::SendPeriodicCollectionSnapshotUnwind2},
  {-1, R6GameServiceAddresses::SendPeriodicCollectionSnapshotUnwind3},
  {0x00000002, R6GameServiceAddresses::SendPeriodicCollectionSnapshotUnwind4},
};

// Periodic snapshot native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f738 : native storage identity retained.
const R6GameServiceNative::FuncInfo SendPeriodicCollectionSnapshotExceptionInfo = {
  0x19930520,
  0x00000004,
  R6GameServiceAddresses::SendPeriodicCollectionSnapshotUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Select expiry processing seven-state descriptor lifetime metadata.
// R6GameService.dll @ 10065598 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectExpiryLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessExpiredInputRecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Expiry kind dispatch or native descriptor unwind metadata.
// R6GameService.dll data @ 100264bc : native storage identity retained.
const uint GExpiryNativeData[4] = {
  R6GameServiceAddresses::GExpiryNativeDataCase1, R6GameServiceAddresses::GExpiryNativeDataCase2, R6GameServiceAddresses::GExpiryNativeDataCase3, R6GameServiceAddresses::GExpiryNativeDataCase4
};

// Expiry kind dispatch or native descriptor unwind metadata.
// R6GameService.dll data @ 1007f6c4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessExpiredInputRecordsUnwindMap[7] = {
  {-1, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind1},
  {-1, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind2},
  {0x00000001, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind3},
  {0x00000001, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind4},
  {0x00000001, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind5},
  {-1, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind6},
  {0x00000005, R6GameServiceAddresses::ProcessExpiredInputRecordsUnwind7},
};

// Expiry kind dispatch or native descriptor unwind metadata.
// R6GameService.dll data @ 1007f6fc : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessExpiredInputRecordsExceptionInfo = {
  0x19930520,
  0x00000007,
  R6GameServiceAddresses::ProcessExpiredInputRecordsUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Metadata store native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f60c : native storage identity retained.
const R6GameServiceNative::UnwindEntry StoreTimestampedDescriptorRecordUnwindMap[6] = {
  {-1, R6GameServiceAddresses::ReleaseTimestampedInputFields},
  {0x00000000, R6GameServiceAddresses::ReleaseTimestampedFirstPair},
  {0x00000001, R6GameServiceAddresses::ReleaseTimestampedInsertionPair},
  {0x00000001, R6GameServiceAddresses::CleanupTimestampedInsertionCapacity},
  {0x00000000, R6GameServiceAddresses::CleanupTimestampedFirstPairCapacity},
  {-1, R6GameServiceAddresses::CleanupTimestampedInputCapacity},
};

// Metadata store native unwind state map or selector metadata.
// R6GameService.dll data @ 1007f63c : native storage identity retained.
const R6GameServiceNative::FuncInfo StoreTimestampedDescriptorRecordExceptionInfo = {
  0x19930520,
  0x00000006,
  R6GameServiceAddresses::StoreTimestampedDescriptorRecordUnwindMap,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
};

// Native virtual-table prefix: CCDKeyProcessVTable
// R6GameService.dll data @ 100769d4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CCDKeyProcessVTableRecord {
  R6GameServiceNative::Address DestroyCCDKeyProcess; // +0x00
};
const CCDKeyProcessVTableRecord CCDKeyProcessVTable = {R6GameServiceAddresses::DestroyCCDKeyProcess};
