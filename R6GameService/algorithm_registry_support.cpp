#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080db8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo HashAlgorithmFactoryExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080dec : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PRNGAlgorithmFactoryExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080e28 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CryptoAlgorithmFactoryExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080e5c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PKCAlgorithmFactoryExceptionHandlerFunctionInfo;

// Registry slot10094570 owns a clPointerMap<void*,HashAlgorithm*>; its tree starts at +4.
// R6GameService.dll data @ 10094570 : native storage identity retained.
uint *GHashAlgorithmRegistry;

// Logical parent EBP is the entry ESP; the caller's selector/raw-allocation word is at EBP+4.
struct HashAlgorithmFactoryFrame {
  byte padding[3];
  byte comparatorByte; // EBP-0x1d: intentionally uninitialized before the sentinel constructor copies it.
  uint constructionFlagsOrKey; // EBP-0x1c, followed by the registered pair's value word.
  uint registeredValue;
  uint registryStorage; // EBP-0x14, later reused as an insertion output.
  uint treeOrInsertionResult; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Creates selector0/MD5 or selector1/SHA1 and inserts its address/value pair into the lazily constructed owning map.
// R6GameService.dll @ 100379e0 : one stdcall selector word, RET4; EAX=created object or zero.
void * __stdcall CreateRegisteredHashAlgorithm(uint selectorWord)
{
  HashAlgorithmFactoryFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashAlgorithmFactoryExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.constructionFlagsOrKey = 0;
  uint selector = selectorWord;
  if (selector > 1) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  selectorWord = (uint)AllocateGameServiceBytes(selector == 0 ? 0x24 : 0x28);
  frame.state = selector;
  void *createdObject = 0;
  if (selectorWord != 0) {
    if (selector == 0) createdObject = ConstructHashModuleMD5((void *)selectorWord,1);
    else createdObject = ConstructHashModuleSHA1((void *)selectorWord,1);
  }
  frame.state = 0xffffffff;
  if (createdObject == 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  uint *registry = GHashAlgorithmRegistry;
  if (registry == 0) {
    registry = (uint *)AllocateGameServiceBytes(0x14);
    frame.registryStorage = (uint)registry;
    if (registry != 0) {
      registry[4] = 0x1007795c;
      frame.constructionFlagsOrKey = 1;
      frame.treeOrInsertionResult = (uint)(registry + 1);
      frame.state = 5;
      InitializeTreeSentinel((void *)frame.treeOrInsertionResult,&frame.comparatorByte,&selectorWord);
      registry[0] = R6GameServiceAddresses::clPointerMap_PAXPAVHashAlgorithmVTable;
    }
    frame.state = 0xffffffff;
    GHashAlgorithmRegistry = registry;
  }
  // Failed map allocation still reaches the native tree dereference; later failures do not delete createdObject.
  uint *tree = (uint *)((uint)registry + 4);
  frame.constructionFlagsOrKey = (uint)createdObject;
  frame.registeredValue = (uint)createdObject;
  uint header = *tree;
  uint parent = header;
  uint node = *(uint *)(header + 4);
  bool insertLeft = true;
  while (node != 0) {
    parent = node;
    insertLeft = (uint)createdObject < *(uint *)(node + 0x10);
    node = *(uint *)(node + (insertLeft ? 8 : 0x0c));
  }
  uint candidate = parent;
  uint *outputSlot;
  if (insertLeft && parent == *(uint *)(header + 8)) {
    outputSlot = &frame.treeOrInsertionResult;
  } else {
    if (insertLeft) candidate = OrderedTreePredecessor((char *)parent);
    if (*(uint *)(candidate + 0x10) >= frame.constructionFlagsOrKey) {
      ExceptionList = frame.previousExceptionList;
      return createdObject;
    }
    outputSlot = &frame.registryStorage;
  }
  InsertPairTreeNodeAtHint(tree,outputSlot,node,parent,&frame.constructionFlagsOrKey,0);
  ExceptionList = frame.previousExceptionList;
  return createdObject;
}

// Tail-forwards the selector word and factory result without changing the caller's stack.
// R6GameService.dll @ 10037340 : one stdcall word, JMP100379e0.
__declspec(naked) void * __stdcall CreateRegisteredHashAlgorithmThunk(uint selector)
{
  __asm { jmp R6GameServiceAddresses::CreateRegisteredHashAlgorithm }
}

// Removes one owned hash value, then destroys and clears an empty registry; preserves raw EAX on every branch.
// R6GameService.dll @ 10037b60 : one stdcall key word, RET4; count reload precedes the native null test.
__declspec(naked) uint __stdcall ReleaseRegisteredHashAlgorithm(uint key)
{
  __asm {
    mov    ecx,dword ptr [GHashAlgorithmRegistry]
    test   ecx,ecx
    jz     release_done
    mov    edx,dword ptr [esp+4]
    mov    eax,dword ptr [ecx]
    push   edx
    call   dword ptr [eax+8]
    mov    ecx,dword ptr [GHashAlgorithmRegistry]
    mov    eax,dword ptr [ecx+8]
    test   eax,eax
    jnz    release_done
    test   ecx,ecx
    jz     clear_registry
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
  clear_registry:
    mov    dword ptr [GHashAlgorithmRegistry],0
  release_done:
    ret    4
  }
}

// Deletes all registry-owned hash objects and clears the slot; an absent registry leaves incoming EAX intact.
// R6GameService.dll @ 10037ba0 : no stack arguments, plain RET; otherwise forwards deleting-destructor EAX.
__declspec(naked) uint __cdecl ClearHashAlgorithmRegistry(void)
{
  __asm {
    mov    ecx,dword ptr [GHashAlgorithmRegistry]
    test   ecx,ecx
    jz     clear_done
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
    mov    dword ptr [GHashAlgorithmRegistry],0
  clear_done:
    ret
  }
}

// Clears all hashes for a zero word, or tail-forwards a nonzero key to the individual release path.
// R6GameService.dll @ 10037380 : one stdcall word, RET4 or JMP10037b60; raw EAX forwarded.
__declspec(naked) uint __stdcall ReleaseHashAlgorithmOrRegistry(uint key)
{
  __asm {
    mov    eax,dword ptr [esp+4]
    test   eax,eax
    jnz    release_key
    call   R6GameServiceAddresses::ClearHashAlgorithmRegistry
    ret    4
  release_key:
    mov    dword ptr [esp+4],eax
    jmp    R6GameServiceAddresses::ReleaseRegisteredHashAlgorithm
  }
}

// Releases selector1's raw allocation if its constructor throws in factory state1.
// R6GameService.dll @ 100667c0 : inherited EBP+4 allocation word, allocator consumes one stack word.
__declspec(naked) void __cdecl ReleaseHashFactorySelector1Allocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases selector0's raw allocation if its constructor throws in factory state0.
// R6GameService.dll @ 100667ca : inherited EBP+4 allocation word, distinct native action body.
__declspec(naked) void __cdecl ReleaseHashFactorySelector0Allocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the registry allocation after the nested construction contexts unwind through state2.
// R6GameService.dll @ 100667d4 : inherited EBP-0x14 allocation word.
__declspec(naked) void __cdecl ReleaseHashFactoryRegistryAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// For an active construction flag, forwards the registry allocation's end address to the empty cleanup helper.
// R6GameService.dll @ 100667de : inherited EBP; EAX=flags&1, optional ECX=allocation+0x14.
__declspec(naked) void __cdecl CleanupHashFactoryRegistryContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x1c]
    and    eax,1
    test   eax,eax
    jz     cleanup_done
    mov    ecx,dword ptr [ebp-0x14]
    add    ecx,0x14
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  cleanup_done:
    ret
  }
}

// Forwards the original selector/raw-allocation word's address to the empty cleanup helper in state5.
// R6GameService.dll @ 100667f8 : inherited EBP+4 address in ECX, JMP10059130.
__declspec(naked) void __cdecl CleanupHashFactorySelectorContext(void)
{
  __asm {
    lea    ecx,[ebp+4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the factory's six-state unwind map, including the two distinct constructor-allocation actions.
// R6GameService.dll @ 10066800 : EAX=10080db8, inherited-frame JMP10033906.
__declspec(naked) void __cdecl HashAlgorithmFactoryExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HashAlgorithmFactoryExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Registry slot10094574 owns a clPointerMap<void*,PRNGAlgorithm*>; the object pointer is also its unsigned key.
// R6GameService.dll data @ 10094574 : native storage identity retained.
uint *GPRNGAlgorithmRegistry;

struct PRNGAlgorithmFactoryFrame {
  uint key; // EBP-0x14, initially zero and later followed by the registered value word.
  uint value;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Creates selector0's PRNG object from three context words and registers its pointer in the owning map.
// R6GameService.dll @ 10037c50 : four stdcall words, RET0x10; EAX=created object or zero.
void * __stdcall CreateRegisteredPRNGAlgorithm(
    uint selectorWord,uint contextWord,uint inputWord,uint lengthWord)
{
  PRNGAlgorithmFactoryFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PRNGAlgorithmFactoryExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.key = 0;
  if (selectorWord != 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  selectorWord = (uint)AllocateGameServiceBytes(0x2c);
  frame.state = 0;
  void *createdObject = 0;
  if (selectorWord != 0) {
    createdObject = ConstructPRNGModuleMGF1(
        (void *)selectorWord,contextWord,(const byte *)inputWord,lengthWord,1);
  }
  frame.state = 0xffffffff;
  if (createdObject == 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  uint *registry = GPRNGAlgorithmRegistry;
  if (registry == 0) {
    registry = (uint *)AllocateGameServiceBytes(0x14);
    inputWord = (uint)registry;
    frame.state = 1;
    if (registry != 0) {
      registry[4] = 0x1007797c;
      frame.state = (frame.state & 0xffffff00) | 2;
      InitializeTreeSentinel(registry + 1,(byte *)&lengthWord,&selectorWord);
      registry[0] = R6GameServiceAddresses::clPointerMap_PAXPAVPRNGAlgorithmVTable;
    }
    frame.state = 0xffffffff;
    GPRNGAlgorithmRegistry = registry;
  }
  // A null registry allocation still reaches address4; later failures do not delete the constructed PRNG object.
  uint *tree = (uint *)((uint)registry + 4);
  frame.key = (uint)createdObject;
  frame.value = (uint)createdObject;
  uint header = *tree;
  uint parent = header;
  uint node = *(uint *)(header + 4);
  bool insertLeft = true;
  while (node != 0) {
    parent = node;
    insertLeft = (uint)createdObject < *(uint *)(node + 0x10);
    node = *(uint *)(node + (insertLeft ? 8 : 0x0c));
  }
  uint candidate = parent;
  uint *output;
  if (insertLeft && parent == *(uint *)(header + 8)) {
    output = &inputWord;
  } else {
    if (insertLeft) candidate = OrderedTreePredecessor((char *)parent);
    if (*(uint *)(candidate + 0x10) >= frame.key) {
      ExceptionList = frame.previousExceptionList;
      return createdObject;
    }
    output = &contextWord;
  }
  InsertPairTreeNodeAtHint(tree,output,node,parent,&frame.key,0);
  ExceptionList = frame.previousExceptionList;
  return createdObject;
}

// Tail-forwards the four factory words and full result without changing the caller's stack.
// R6GameService.dll @ 100373a0 : four stdcall words, JMP10037c50.
__declspec(naked) void * __stdcall CreateRegisteredPRNGAlgorithmThunk(
    uint selector,uint contextWord,uint inputWord,uint lengthWord)
{
  __asm { jmp R6GameServiceAddresses::CreateRegisteredPRNGAlgorithm }
}

// Removes one owned PRNG value, then destroys and clears an empty registry; preserves raw EAX on every branch.
// R6GameService.dll @ 10037db0 : one stdcall key word, RET4; count reload precedes the native null test.
__declspec(naked) uint __stdcall ReleaseRegisteredPRNGAlgorithm(uint key)
{
  __asm {
    mov    ecx,dword ptr [GPRNGAlgorithmRegistry]
    test   ecx,ecx
    jz     release_done
    mov    edx,dword ptr [esp+4]
    mov    eax,dword ptr [ecx]
    push   edx
    call   dword ptr [eax+8]
    mov    ecx,dword ptr [GPRNGAlgorithmRegistry]
    mov    eax,dword ptr [ecx+8]
    test   eax,eax
    jnz    release_done
    test   ecx,ecx
    jz     clear_registry
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
  clear_registry:
    mov    dword ptr [GPRNGAlgorithmRegistry],0
  release_done:
    ret    4
  }
}

// Deletes all registry-owned PRNG objects and clears the slot; an absent registry leaves incoming EAX intact.
// R6GameService.dll @ 10037df0 : no stack arguments, plain RET; otherwise forwards deleting-destructor EAX.
__declspec(naked) uint __cdecl ClearPRNGAlgorithmRegistry(void)
{
  __asm {
    mov    ecx,dword ptr [GPRNGAlgorithmRegistry]
    test   ecx,ecx
    jz     clear_done
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
    mov    dword ptr [GPRNGAlgorithmRegistry],0
  clear_done:
    ret
  }
}

// Clears all PRNG objects for a zero word, or tail-forwards a nonzero key to the individual release path.
// R6GameService.dll @ 100373b0 : one stdcall word, RET4 or JMP10037db0; raw EAX forwarded.
__declspec(naked) uint __stdcall ReleasePRNGAlgorithmOrRegistry(uint key)
{
  __asm {
    mov    eax,dword ptr [esp+4]
    test   eax,eax
    jnz    release_key
    call   R6GameServiceAddresses::ClearPRNGAlgorithmRegistry
    ret    4
  release_key:
    mov    dword ptr [esp+4],eax
    jmp    R6GameServiceAddresses::ReleaseRegisteredPRNGAlgorithm
  }
}

// Releases the raw PRNG allocation when its constructor throws in factory state0.
// R6GameService.dll @ 10066810 : inherited EBP+4 allocation word, allocator consumes one stack word.
__declspec(naked) void __cdecl ReleasePRNGFactoryObjectAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the registry allocation saved over the third factory argument in state1.
// R6GameService.dll @ 1006681a : inherited EBP+0x0c allocation word.
__declspec(naked) void __cdecl ReleasePRNGFactoryRegistryAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+0xc]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards the original selector/allocation word's address to the empty cleanup helper in state2.
// R6GameService.dll @ 10066824 : inherited EBP+4 address in ECX, JMP10059130.
__declspec(naked) void __cdecl CleanupPRNGFactorySelectorContext(void)
{
  __asm {
    lea    ecx,[ebp+4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the PRNG factory's three-state object/registry allocation unwind map.
// R6GameService.dll @ 1006682c : EAX=10080dec, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PRNGAlgorithmFactoryExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PRNGAlgorithmFactoryExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Registry slot10094578 owns a clPointerMap<void*,CryptoAlgorithm*>.
// R6GameService.dll data @ 10094578 : native storage identity retained.
uint *GCryptoAlgorithmRegistry;

struct CryptoAlgorithmFactoryFrame {
  uint insertionOutput; // EBP-0x18, initially zero.
  uint key; // EBP-0x14, followed by the registered pair's value.
  uint value;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Creates selector0/1's crypto object from two context words and inserts its address/value pair into the owning map.
// R6GameService.dll @ 10037e50 : three stdcall words, RET0x0c; EAX=created object or zero.
void * __stdcall CreateRegisteredCryptoAlgorithm(uint selectorWord,uint contextWord,uint secondContextWord)
{
  CryptoAlgorithmFactoryFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CryptoAlgorithmFactoryExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.insertionOutput = 0;
  uint selector = selectorWord;
  if (selector > 1) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  selectorWord = (uint)AllocateGameServiceBytes(0x10);
  frame.state = selector;
  void *createdObject = 0;
  if (selectorWord != 0) {
    if (selector == 0) createdObject = ConstructCipherModuleBlowfish((void *)selectorWord,contextWord,secondContextWord,1);
    else createdObject = ConstructCipherModuleGSXor((void *)selectorWord,contextWord,secondContextWord,1);
  }
  frame.state = 0xffffffff;
  if (createdObject == 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  uint *registry = GCryptoAlgorithmRegistry;
  if (registry == 0) {
    registry = (uint *)AllocateGameServiceBytes(0x14);
    selectorWord = (uint)registry;
    frame.state = 2;
    if (registry != 0) {
      registry[4] = 0x1007799c;
      frame.state = (frame.state & 0xffffff00) | 3;
      InitializeTreeSentinel(registry + 1,(byte *)&contextWord,&secondContextWord);
      registry[0] = R6GameServiceAddresses::clPointerMap_PAXPAVCryptoAlgorithmVTable;
    }
    frame.state = 0xffffffff;
    GCryptoAlgorithmRegistry = registry;
  }
  // Map allocation failure still dereferences address4; later failures do not roll back the created crypto object.
  uint *tree = (uint *)((uint)registry + 4);
  frame.key = (uint)createdObject;
  frame.value = (uint)createdObject;
  uint header = *tree;
  uint parent = header;
  uint node = *(uint *)(header + 4);
  bool insertLeft = true;
  while (node != 0) {
    parent = node;
    insertLeft = (uint)createdObject < *(uint *)(node + 0x10);
    node = *(uint *)(node + (insertLeft ? 8 : 0x0c));
  }
  uint candidate = parent;
  uint *output;
  if (insertLeft && parent == *(uint *)(header + 8)) {
    output = &selectorWord;
  } else {
    if (insertLeft) candidate = OrderedTreePredecessor((char *)parent);
    if (*(uint *)(candidate + 0x10) >= frame.key) {
      ExceptionList = frame.previousExceptionList;
      return createdObject;
    }
    output = &frame.insertionOutput;
  }
  InsertPairTreeNodeAtHint(tree,output,node,parent,&frame.key,0);
  ExceptionList = frame.previousExceptionList;
  return createdObject;
}

// Tail-forwards all three crypto factory words and its full pointer result.
// R6GameService.dll @ 100373e0 : three stdcall words, JMP10037e50.
__declspec(naked) void * __stdcall CreateRegisteredCryptoAlgorithmThunk(
    uint selector,uint contextWord,uint secondContextWord)
{
  __asm { jmp R6GameServiceAddresses::CreateRegisteredCryptoAlgorithm }
}

// Removes one owned crypto value, then destroys and clears an empty registry; preserves raw EAX on every branch.
// R6GameService.dll @ 10037fd0 : one stdcall key word, RET4; count reload precedes the native null test.
__declspec(naked) uint __stdcall ReleaseRegisteredCryptoAlgorithm(uint key)
{
  __asm {
    mov    ecx,dword ptr [GCryptoAlgorithmRegistry]
    test   ecx,ecx
    jz     release_done
    mov    edx,dword ptr [esp+4]
    mov    eax,dword ptr [ecx]
    push   edx
    call   dword ptr [eax+8]
    mov    ecx,dword ptr [GCryptoAlgorithmRegistry]
    mov    eax,dword ptr [ecx+8]
    test   eax,eax
    jnz    release_done
    test   ecx,ecx
    jz     clear_registry
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
  clear_registry:
    mov    dword ptr [GCryptoAlgorithmRegistry],0
  release_done:
    ret    4
  }
}

// Deletes all registry-owned crypto objects and clears the slot; an absent registry leaves incoming EAX intact.
// R6GameService.dll @ 10038010 : no stack arguments, plain RET; otherwise forwards deleting-destructor EAX.
__declspec(naked) uint __cdecl ClearCryptoAlgorithmRegistry(void)
{
  __asm {
    mov    ecx,dword ptr [GCryptoAlgorithmRegistry]
    test   ecx,ecx
    jz     clear_done
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
    mov    dword ptr [GCryptoAlgorithmRegistry],0
  clear_done:
    ret
  }
}

// Clears all crypto objects for a zero word, or tail-forwards a nonzero key to the individual release path.
// R6GameService.dll @ 100373f0 : one stdcall word, RET4 or JMP10037fd0; raw EAX forwarded.
__declspec(naked) uint __stdcall ReleaseCryptoAlgorithmOrRegistry(uint key)
{
  __asm {
    mov    eax,dword ptr [esp+4]
    test   eax,eax
    jnz    release_key
    call   R6GameServiceAddresses::ClearCryptoAlgorithmRegistry
    ret    4
  release_key:
    mov    dword ptr [esp+4],eax
    jmp    R6GameServiceAddresses::ReleaseRegisteredCryptoAlgorithm
  }
}

// Releases selector1's raw object allocation if its constructor throws in state1.
// R6GameService.dll @ 10066840 : inherited EBP+4 allocation word; allocator consumes one stack word.
__declspec(naked) void __cdecl ReleaseCryptoFactorySelector1Allocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases selector0's raw object allocation if its constructor throws in state0.
// R6GameService.dll @ 1006684a : inherited EBP+4 allocation word; allocator consumes one stack word.
__declspec(naked) void __cdecl ReleaseCryptoFactorySelector0Allocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the registry allocation saved over the selector word in state2.
// R6GameService.dll @ 10066854 : inherited EBP+4 allocation word; allocator consumes one stack word.
__declspec(naked) void __cdecl ReleaseCryptoFactoryRegistryAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards the third argument word's address to the empty cleanup helper in state3.
// R6GameService.dll @ 1006685e : inherited EBP+0xc address in ECX, JMP10059130.
__declspec(naked) void __cdecl CleanupCryptoFactoryArgumentContext(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the crypto factory's four-state object/registry allocation unwind map.
// R6GameService.dll @ 10066866 : EAX=10080e28, inherited-frame JMP10033906.
__declspec(naked) void __cdecl CryptoAlgorithmFactoryExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CryptoAlgorithmFactoryExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Registry slot1009457c owns a clPointerMap<void*,PKCAlgorithm*>.
// R6GameService.dll data @ 1009457c : native storage identity retained.
uint *GPKCAlgorithmRegistry;

struct PKCAlgorithmFactoryFrame {
  byte padding[3];
  byte comparatorByte; // EBP-0x1d, uninitialized before the tree constructor copies it.
  uint registryStorage; // EBP-0x1c, initially zero and later reused as an insertion output.
  uint insertionOutput; // EBP-0x18.
  uint key; // EBP-0x14, followed by the registered value.
  uint value;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Creates selector0's PKC object and inserts its address/value pair into the lazily initialized owning map.
// R6GameService.dll @ 10038090 : one stdcall selector word, RET4; EAX=created object or zero.
void * __stdcall CreateRegisteredPKCAlgorithm(uint selectorWord)
{
  PKCAlgorithmFactoryFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PKCAlgorithmFactoryExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.registryStorage = 0;
  if (selectorWord != 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  selectorWord = (uint)AllocateGameServiceBytes(0x10);
  frame.state = 0;
  void *createdObject = 0;
  if (selectorWord != 0) createdObject = ConstructPKCModuleRSA((void *)selectorWord,1);
  frame.state = 0xffffffff;
  if (createdObject == 0) {
    ExceptionList = frame.previousExceptionList;
    return 0;
  }
  uint *registry = GPKCAlgorithmRegistry;
  if (registry == 0) {
    registry = (uint *)AllocateGameServiceBytes(0x14);
    frame.registryStorage = (uint)registry;
    frame.state = 1;
    if (registry != 0) {
      registry[4] = 0x100779bc;
      frame.state = (frame.state & 0xffffff00) | 2;
      InitializeTreeSentinel(registry + 1,&frame.comparatorByte,&selectorWord);
      registry[0] = R6GameServiceAddresses::clPointerMap_PAXPAVPKCAlgorithmVTable;
    }
    frame.state = 0xffffffff;
    GPKCAlgorithmRegistry = registry;
  }
  // A failed registry allocation still dereferences address4; the constructed PKC object has no later rollback.
  uint *tree = (uint *)((uint)registry + 4);
  frame.key = (uint)createdObject;
  frame.value = (uint)createdObject;
  uint header = *tree;
  uint parent = header;
  uint node = *(uint *)(header + 4);
  bool insertLeft = true;
  while (node != 0) {
    parent = node;
    insertLeft = (uint)createdObject < *(uint *)(node + 0x10);
    node = *(uint *)(node + (insertLeft ? 8 : 0x0c));
  }
  uint candidate = parent;
  uint *output;
  if (insertLeft && parent == *(uint *)(header + 8)) {
    output = &frame.registryStorage;
  } else {
    if (insertLeft) candidate = OrderedTreePredecessor((char *)parent);
    if (*(uint *)(candidate + 0x10) >= frame.key) {
      ExceptionList = frame.previousExceptionList;
      return createdObject;
    }
    output = &frame.insertionOutput;
  }
  InsertPairTreeNodeAtHint(tree,output,node,parent,&frame.key,0);
  ExceptionList = frame.previousExceptionList;
  return createdObject;
}

// Tail-forwards the PKC selector word and full pointer result.
// R6GameService.dll @ 10037430 : one stdcall word, JMP10038090.
__declspec(naked) void * __stdcall CreateRegisteredPKCAlgorithmThunk(uint selector)
{
  __asm { jmp R6GameServiceAddresses::CreateRegisteredPKCAlgorithm }
}

// Removes one owned PKC value, then destroys and clears an empty registry; preserves raw EAX on every branch.
// R6GameService.dll @ 100381e0 : one stdcall key word, RET4; count reload precedes the native null test.
__declspec(naked) uint __stdcall ReleaseRegisteredPKCAlgorithm(uint key)
{
  __asm {
    mov    ecx,dword ptr [GPKCAlgorithmRegistry]
    test   ecx,ecx
    jz     release_done
    mov    edx,dword ptr [esp+4]
    mov    eax,dword ptr [ecx]
    push   edx
    call   dword ptr [eax+8]
    mov    ecx,dword ptr [GPKCAlgorithmRegistry]
    mov    eax,dword ptr [ecx+8]
    test   eax,eax
    jnz    release_done
    test   ecx,ecx
    jz     clear_registry
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
  clear_registry:
    mov    dword ptr [GPKCAlgorithmRegistry],0
  release_done:
    ret    4
  }
}

// Deletes all registry-owned PKC objects and clears the slot; an absent registry leaves incoming EAX intact.
// R6GameService.dll @ 10038220 : no stack arguments, plain RET; otherwise forwards deleting-destructor EAX.
__declspec(naked) uint __cdecl ClearPKCAlgorithmRegistry(void)
{
  __asm {
    mov    ecx,dword ptr [GPKCAlgorithmRegistry]
    test   ecx,ecx
    jz     clear_done
    mov    eax,dword ptr [ecx]
    push   1
    call   dword ptr [eax]
    mov    dword ptr [GPKCAlgorithmRegistry],0
  clear_done:
    ret
  }
}

// Clears all PKC objects for a zero word, or tail-forwards a nonzero key to the individual release path.
// R6GameService.dll @ 10037440 : one stdcall word, RET4 or JMP100381e0; raw EAX forwarded.
__declspec(naked) uint __stdcall ReleasePKCAlgorithmOrRegistry(uint key)
{
  __asm {
    mov    eax,dword ptr [esp+4]
    test   eax,eax
    jnz    release_key
    call   R6GameServiceAddresses::ClearPKCAlgorithmRegistry
    ret    4
  release_key:
    mov    dword ptr [esp+4],eax
    jmp    R6GameServiceAddresses::ReleaseRegisteredPKCAlgorithm
  }
}

// Releases the raw PKC object allocation when its constructor throws in state0.
// R6GameService.dll @ 10066870 : inherited EBP+4 allocation word; allocator consumes one stack word.
__declspec(naked) void __cdecl ReleasePKCFactoryObjectAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp+4]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Releases the raw registry allocation saved in the parent frame in state1.
// R6GameService.dll @ 1006687a : inherited EBP-0x1c allocation word; allocator consumes one stack word.
__declspec(naked) void __cdecl ReleasePKCFactoryRegistryAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x1c]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards the selector/raw-allocation word's address to the empty cleanup helper in state2.
// R6GameService.dll @ 10066884 : inherited EBP+4 address in ECX, JMP10059130.
__declspec(naked) void __cdecl CleanupPKCFactorySelectorContext(void)
{
  __asm {
    lea    ecx,[ebp+4]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the PKC factory's three-state object/registry allocation unwind map.
// R6GameService.dll @ 1006688c : EAX=10080e5c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PKCAlgorithmFactoryExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PKCAlgorithmFactoryExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
