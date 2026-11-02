#include "native_addresses.h"
#include "native_records.h"

// Public CD-key context callback registration adapters; class-owned callback slots live in CCDKeyProcess.cpp.
// uint results preserve raw EAX; guarded adapters define success only in AL.

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232c0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtC8(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtC8
  }
}

// Stores a callback at +c8 and sets AL to1; null clears only AL without reading the callback word.
// R6GameService.dll @ 100235e0 : C++ guarded callback store; null clears only AL without a callback read.
__declspec(naked) uint __stdcall SetContextCallbackAtC8(void *context,uint callbackWord)
{
  byte *nativeFrame;
  uint entryEax;
  __asm {
    mov    nativeFrame,esp
    mov    entryEax,eax
  }
  void *owner = *(void **)(nativeFrame + 4);
  uint output = entryEax & 0xffffff00;
  if (owner != nullptr) {
    uint callback = *(uint *)(nativeFrame + 8);
    using StoreABI = uint (__thiscall *)(void *,uint);
    uint stored = ((StoreABI)R6GameServiceAddresses::CCDKeyProcessSetCallback1)(owner,callback);
    output = (stored & 0xffffff00) | 1;
  }
  __asm {
    mov    eax,output
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtCC(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtCC
  }
}

// Stores a callback at +cc and sets AL to1; null clears only AL without reading the callback word.
// R6GameService.dll @ 10023600 : C++ guarded callback store; null clears only AL without a callback read.
__declspec(naked) uint __stdcall SetContextCallbackAtCC(void *context,uint callbackWord)
{
  byte *nativeFrame;
  uint entryEax;
  __asm {
    mov    nativeFrame,esp
    mov    entryEax,eax
  }
  void *owner = *(void **)(nativeFrame + 4);
  uint output = entryEax & 0xffffff00;
  if (owner != nullptr) {
    uint callback = *(uint *)(nativeFrame + 8);
    using StoreABI = uint (__thiscall *)(void *,uint);
    uint stored = ((StoreABI)R6GameServiceAddresses::CCDKeyProcessSetCallback2)(owner,callback);
    output = (stored & 0xffffff00) | 1;
  }
  __asm {
    mov    eax,output
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232e0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtD0(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtD0
  }
}

// Stores a callback at +d0 and sets AL to1; null clears only AL without reading the callback word.
// R6GameService.dll @ 10023620 : C++ guarded callback store; null clears only AL without a callback read.
__declspec(naked) uint __stdcall SetContextCallbackAtD0(void *context,uint callbackWord)
{
  byte *nativeFrame;
  uint entryEax;
  __asm {
    mov    nativeFrame,esp
    mov    entryEax,eax
  }
  void *owner = *(void **)(nativeFrame + 4);
  uint output = entryEax & 0xffffff00;
  if (owner != nullptr) {
    uint callback = *(uint *)(nativeFrame + 8);
    using StoreABI = uint (__thiscall *)(void *,uint);
    uint stored = ((StoreABI)R6GameServiceAddresses::CCDKeyProcessSetCallback3)(owner,callback);
    output = (stored & 0xffffff00) | 1;
  }
  __asm {
    mov    eax,output
    ret    0x8
  }
}

// Tail-forwards the untouched original context/callback argument words to its guarded entry.
// R6GameService.dll @ 100232f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_SetContextCallbackAtD4(void *context,uint callbackWord)
{
  __asm {
    jmp    R6GameServiceAddresses::SetContextCallbackAtD4
  }
}

// Stores a callback at +d4 and sets AL to1; null clears only AL without reading the callback word.
// R6GameService.dll @ 10023640 : C++ guarded callback store; null clears only AL without a callback read.
__declspec(naked) uint __stdcall SetContextCallbackAtD4(void *context,uint callbackWord)
{
  byte *nativeFrame;
  uint entryEax;
  __asm {
    mov    nativeFrame,esp
    mov    entryEax,eax
  }
  void *owner = *(void **)(nativeFrame + 4);
  uint output = entryEax & 0xffffff00;
  if (owner != nullptr) {
    uint callback = *(uint *)(nativeFrame + 8);
    using StoreABI = uint (__thiscall *)(void *,uint);
    uint stored = ((StoreABI)R6GameServiceAddresses::CCDKeyProcessSetCallback4)(owner,callback);
    output = (stored & 0xffffff00) | 1;
  }
  __asm {
    mov    eax,output
    ret    0x8
  }
}

// Creates/tracks a context and returns it only when nested status AL is nonzero; failed validation adds no rollback.
// R6GameService.dll @ 10023210 : C++ stdcall factory/status gate; failed status does not roll back tracking.
void * __stdcall CreateValidatedCDKeyContext(uint portWord)
{
  using AllocateABI = void * (__stdcall *)(uint);
  using StatusABI = uint (__stdcall *)(void *);
  void *context = ((AllocateABI)R6GameServiceAddresses::AllocateAndTrackContext)(portWord);
  if (context == nullptr) return nullptr;
  uint status = ((StatusABI)R6GameServiceAddresses::ReadCDKeyContextStatus)(context);
  if ((byte)status == 0) return nullptr;
  return context;
}

// Calls full registry deletion for NULL context, otherwise tail-forwards original word to registry removal.
// R6GameService.dll @ 10023240 : C++ routing with raw EAX seed and original-frame registry-removal tail.
__declspec(naked) uint __stdcall RemoveCDKeyContextOrRegistry(uint contextWord)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  uint context = *(uint *)(nativeFrame + 4);
  if (context == 0) {
    __asm {
      xor    eax,eax
      call   R6GameServiceAddresses::DeleteCurrentCDKeyRegistry
      ret    0x4
    }
  }
  *(uint *)(nativeFrame + 4) = context;
  __asm {
    mov    eax,context
    jmp    R6GameServiceAddresses::ReleaseEmptyCDKeyRegistry
  }
}

// Constructs/tracks a context in its lazy pointer registry, preserving allocation and unwind gaps.
// R6GameService.dll @ 10023300 : C++ allocation/tracking with native construction slots and two exit frames.
__declspec(naked) void * __stdcall AllocateAndTrackContext(uint portWord)
{
  byte *entryFrame;
  byte *nativeFrame;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectContextFactoryLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   ebp
    push   edi
    xor    edi,edi
    mov    entryFrame,esp
  }
  using AllocateABI = void * (__stdcall *)(uint);
  using ConstructABI = void * (__thiscall *)(void *,uint,uint);
  using TreeABI = void (__thiscall *)(void *,byte *,uint *);
  using PredecessorABI = uint (__cdecl *)(uint);
  using InsertABI = void * (__thiscall *)(void *,void *,uint,uint,const void *,uint);
  *(uint *)(entryFrame + 0x10) = 0;
  void *allocation = ((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(0xdc);
  *(void **)(entryFrame + 0x10) = allocation;
  *(uint *)(entryFrame + 0x28) = 0;
  void *context = nullptr;
  if (allocation != nullptr) {
    uint port = *(uint *)(entryFrame + 0x30);
    context = ((ConstructABI)R6GameServiceAddresses::ConstructCCDKeyProcess)(allocation,port,1);
  }
  *(uint *)(entryFrame + 0x28) = 0xffffffff;
  if (context == nullptr) {
    __asm {
      pop    edi
      pop    ebp
      xor    eax,eax
      pop    ebx
      mov    ecx,DWORD PTR [esp+0x14]
      mov    DWORD PTR fs:0x0,ecx
      add    esp,0x20
      ret    0x4
    }
  }
  byte *registry = *(byte **)0x10093bf8;
  __asm {
    push   esi
    mov    nativeFrame,esp
  }
  if (registry == nullptr) {
    byte *pendingRegistry = (byte *)((AllocateABI)R6GameServiceAddresses::AllocateGameServiceBytes)(0x14);
    *(byte **)(nativeFrame + 0x1c) = pendingRegistry;
    if (pendingRegistry != nullptr) {
      *(uint *)(pendingRegistry + 0x10) = 0x100769c0;
      *(uint *)(nativeFrame + 0x14) = 1;
      void *tree = pendingRegistry + 4;
      *(void **)(nativeFrame + 0x20) = tree;
      *(uint *)(nativeFrame + 0x2c) = 4;
      ((TreeABI)R6GameServiceAddresses::InitializeTreeSentinel)
          (tree,nativeFrame + 0x13,(uint *)(nativeFrame + 0x34));
      *(uint *)pendingRegistry = R6GameServiceAddresses::clPointerMap_PAXPAVCCDKeyProcessVTable;
    }
    registry = pendingRegistry;
    *(uint *)(nativeFrame + 0x2c) = 0xffffffff;
    *(byte **)0x10093bf8 = registry;
  }
  // A failed registry allocation still publishes null, then enters the same unchecked tree accesses.
  byte *tree = (byte *)((uint)registry + 4);
  *(void **)(nativeFrame + 0x14) = context;
  *(void **)(nativeFrame + 0x18) = context;
  bool left = true;
  uint head = *(uint *)tree;
  uint parent = head;
  uint node = *(uint *)(head + 4);
  while (node != 0) {
    uint key = *(uint *)(node + 0x10);
    parent = node;
    left = (uint)context < key;
    node = *(uint *)(node + (left ? 8 : 0xc));
  }
  uint candidate = parent;
  bool insertAtLeftmost = false;
  if (left) {
    if (parent == *(uint *)(head + 8)) insertAtLeftmost = true;
    else candidate = ((PredecessorABI)R6GameServiceAddresses::OrderedTreePredecessor)(parent);
  }
  if (insertAtLeftmost) {
    ((InsertABI)R6GameServiceAddresses::InsertPairTreeNodeAtHint)
        (tree,nativeFrame + 0x20,node,parent,nativeFrame + 0x14,0);
  } else {
    uint currentKey = *(uint *)(nativeFrame + 0x14);
    uint candidateKey = *(uint *)(candidate + 0x10);
    if (candidateKey < currentKey)
      ((InsertABI)R6GameServiceAddresses::InsertPairTreeNodeAtHint)
          (tree,nativeFrame + 0x1c,node,parent,nativeFrame + 0x14,0);
  }
  __asm {
    mov    ebp,context
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    mov    eax,ebp
    pop    edi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x4
  }
}

// Calls current registry slot8, reloads current registry/count and deletes/clears it only when that word is zero.
// R6GameService.dll @ 10023460 : C++ registry removal/count gate with original argument and raw return lane.
__declspec(naked) uint __stdcall ReleaseEmptyCDKeyRegistry(uint contextWord)
{
  byte *nativeFrame;
  uint output;
  __asm {
    mov    nativeFrame,esp
    mov    output,eax
  }
  byte *registry = *(byte **)0x10093bf8;
  if (registry != nullptr) {
    uint context = *(uint *)(nativeFrame + 4);
    byte *table = *(byte **)registry;
    using RemoveABI = uint (__thiscall *)(void *,uint);
    (*(RemoveABI *)(table + 8))(registry,context);
    registry = *(byte **)0x10093bf8;
    // The count read precedes the redundant pointer test, retaining a null replacement's native fault.
    output = *(uint *)(registry + 8);
    if (output == 0) {
      if (registry != nullptr) {
        table = *(byte **)registry;
        output = (*(RemoveABI *)table)(registry,1);
      }
      *(uint *)0x10093bf8 = 0;
    }
  }
  __asm {
    mov    eax,output
    ret    0x4
  }
}

// Calls nonnull current registry deleting slot with flag1, then clears global regardless of callback replacement.
// R6GameService.dll @ 100234a0 : C++ deleting dispatch, retaining incoming EAX when no registry exists.
__declspec(naked) uint __cdecl DeleteCurrentCDKeyRegistry()
{
  uint output;
  __asm {
    mov    output,eax
  }
  byte *registry = *(byte **)0x10093bf8;
  if (registry != nullptr) {
    using DeleteABI = uint (__thiscall *)(void *,uint);
    byte *table = *(byte **)registry;
    output = (*(DeleteABI *)table)(registry,1);
    *(uint *)0x10093bf8 = 0;
  }
  __asm {
    mov    eax,output
    ret
  }
}

// Reads nested byte+c through context+58, retaining pointer upper EAX; NULL context returns zero with no nested access.
// R6GameService.dll @ 100234c0 : C++ nested status read with pointer upper bits retained in EAX.
uint __stdcall ReadCDKeyContextStatus(void *context)
{
  if (context == nullptr) return 0;
  uint nested = *(uint *)((byte *)context + 0x58);
  byte status = *(byte *)(nested + 0xc);
  return (nested & 0xffffff00) | status;
}

// Releases current pending context allocation from inherited EBP-1c through actual shared free tail.
// R6GameService.dll @ 10064ba0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases current pending registry allocation from inherited EBP-14 through actual shared free tail.
// R6GameService.dll @ 10064baa : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For inherited construction bit1, forwards pending registry+14 to genuine no-op; retains bitmap word.
// R6GameService.dll @ 10064bb4 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    test   eax,eax
    je     Branch25
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch25:
    ret
  }
}

// Forwards address of original port argument to genuine no-op.
// R6GameService.dll @ 10064bce : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl AllocateAndTrackContextUnwind5(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects five-state context/registry allocation map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064bd6 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectContextFactoryLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::AllocateAndTrackContextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ef08 : native context factory unwind record.
const R6GameServiceNative::UnwindEntry AllocateAndTrackContextUnwindMap[5] = {
  {-1, R6GameServiceAddresses::AllocateAndTrackContextUnwind1},
  {-1, R6GameServiceAddresses::AllocateAndTrackContextUnwind2},
  {0x1, R6GameServiceAddresses::AllocateAndTrackContextUnwind3},
  {0x2, 0x0},
  {0x3, R6GameServiceAddresses::AllocateAndTrackContextUnwind5},
};

// R6GameService.dll data @ 1007ef30 : native context factory unwind record.
// R6GameService.dll data @ 1007ef08 : native storage identity retained.
const R6GameServiceNative::FuncInfo AllocateAndTrackContextExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::AllocateAndTrackContextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023260 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation1(uint word0,uint word1)
{
  __asm {
    jmp    R6GameServiceAddresses::InvokeOptionalCDKeyContextAL
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 10023270 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation2(uint word0,uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x14]
    mov    DWORD PTR [esp+0x14],eax
    jmp    R6GameServiceAddresses::InvokeOptionalCDKeyContextWord
  }
}

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023280 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_ForwardValueDescriptorThroughContext(uint word0,uint word1,uint word2)
{
  __asm {
    jmp    R6GameServiceAddresses::ForwardValueDescriptorThroughContext
  }
}

// Tail-forwards the original argument frame to the guarded context operation.
// R6GameService.dll @ 10023290 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall thunk_ForwardCompoundDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    jmp    R6GameServiceAddresses::ForwardCompoundDescriptorThroughContext
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 100232a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation5(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::DispatchRangeDescriptorThroughContext
  }
}

// Reads and self-stores the final argument word before tail-forwarding the original frame.
// R6GameService.dll @ 100232b0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall ForwardGuardedCDKeyContextOperation6(uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x10],eax
    jmp    R6GameServiceAddresses::DispatchRecordThroughContext
  }
}

// For a nonnull context, forwards the remaining words and raw EAX; null clears only AL.
// R6GameService.dll @ 100234e0 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall InvokeOptionalCDKeyContextAL(uint word0,uint word1)
{
  byte *nativeFrame;
  uint entryEax;
  __asm {
    mov    nativeFrame,esp
    mov    entryEax,eax
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = (entryEax & 0xffffff00);
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::ProcessInputWithinTimeLimit)
        (context,argument1);
  }
  __asm {
    mov    eax,output
    ret    0x8
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023500 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall InvokeOptionalCDKeyContextWord(uint word0,uint word1,uint word2,uint word3,uint word4)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = 0;
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint,uint,uint,uint);
    uint argument4 = *(uint *)(nativeFrame + 0x14);
    uint argument3 = *(uint *)(nativeFrame + 0x10);
    uint argument2 = *(uint *)(nativeFrame + 0xc);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::SendDescriptorWithText)
        (context,argument1,argument2,argument3,argument4);
  }
  __asm {
    mov    eax,output
    ret    0x14
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023530 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall ForwardValueDescriptorThroughContext(uint word0,uint word1,uint word2)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = 0;
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint,uint);
    uint argument2 = *(uint *)(nativeFrame + 0xc);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::SendDescriptorWithValue)
        (context,argument1,argument2);
  }
  __asm {
    mov    eax,output
    ret    0xc
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023550 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall ForwardCompoundDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = 0;
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint,uint,uint);
    uint argument3 = *(uint *)(nativeFrame + 0x10);
    uint argument2 = *(uint *)(nativeFrame + 0xc);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::SendCompoundDescriptor)
        (context,argument1,argument2,argument3);
  }
  __asm {
    mov    eax,output
    ret    0x10
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 10023580 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall DispatchRangeDescriptorThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = 0;
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint,uint,uint);
    uint argument3 = *(uint *)(nativeFrame + 0x10);
    uint argument2 = *(uint *)(nativeFrame + 0xc);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::UppercaseAndDispatchRanges)
        (context,argument1,argument2,argument3);
  }
  __asm {
    mov    eax,output
    ret    0x10
  }
}

// For a nonnull context, forwards the remaining full words and raw EAX; null returns zero.
// R6GameService.dll @ 100235b0 : C++ guarded forwarding; native incoming slots and return width.
__declspec(naked) uint __stdcall DispatchRecordThroughContext(uint word0,uint word1,uint word2,uint word3)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  void *context = *(void **)(nativeFrame + 4);
  uint output = 0;
  if (context != nullptr) {
    using MemberABI = uint (__thiscall *)(void *,uint,uint,uint);
    uint argument3 = *(uint *)(nativeFrame + 0x10);
    uint argument2 = *(uint *)(nativeFrame + 0xc);
    uint argument1 = *(uint *)(nativeFrame + 0x8);
    output = ((MemberABI)R6GameServiceAddresses::CopyAndDispatchRecordFields)
        (context,argument1,argument2,argument3);
  }
  __asm {
    mov    eax,output
    ret    0x10
  }
}
