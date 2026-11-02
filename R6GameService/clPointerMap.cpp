#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007ef5c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CCDKeyProcessMapDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080e88 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo HashAlgorithmMapDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080ed8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PRNGAlgorithmMapDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080f28 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CryptoAlgorithmMapDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080f78 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PKCAlgorithmMapDestroyExceptionHandlerFunctionInfo;

// Identified specialization: native COL10078804/type1008dc48 names clPointerMap<void *, CCDKeyProcess *>.
struct CCDKeyProcessMapDestroyFrame {
  uint *savedOwner;
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the identified pointer-map specialization and optionally releases its object storage, returning the owner.
// R6GameService.dll @ 10023660 : ECX owner, flags stack word, RET4; primary vtable100769ac slot0.
void * __thiscall DeleteCCDKeyProcessPointerMap(void *owner,byte flags)
{
  DestroyCCDKeyProcessPointerMap((int *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Installs the map vtable, dispatches value-range destruction, then frees remaining tree nodes and its header.
// R6GameService.dll @ 10023680 : ECX owner, no stack arguments; EAX=header-free raw result.
uint __fastcall DestroyCCDKeyProcessPointerMap(int *owner)
{
  CCDKeyProcessMapDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CCDKeyProcessMapDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  owner[0] = R6GameServiceAddresses::clPointerMap_PAXPAVCCDKeyProcessVTable;
  int *tree = owner + 1;
  uint pastLast = tree[0];
  uint first = pastLast;
  uint vtable = owner[0];
  frame.state = 0;
  ReadOrderedTreeLeftmostLink(tree,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 1;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseTreeNodeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Deletes each visited owned value before structurally removing a half-open map range, returning the visit count.
// R6GameService.dll @ 10023890 : ECX identified map, first/last stack words, RET8; primary vtable slot0x0c.
uint __thiscall EraseCCDKeyProcessPointerMapRange(void *owner,char *firstNode,char *pastLastNode)
{
  uint stop = (uint)pastLastNode;
  uint removedCount = 0;
  uint visited = (uint)firstNode;
  while (visited != stop && visited != *(uint *)((byte *)owner + 4)) {
    uint value = *(uint *)(visited + 0x14);
    if (value != 0) {
      typedef void (__thiscall *DeleteValue)(void *,uint);
      (*(DeleteValue *)*(uint *)value)((void *)value,1);
    }
    uint incremented = removedCount + 1;
    *(uint *)(visited + 0x14) = 0;
    removedCount = incremented;
    visited = (uint)OrderedTreeSuccessor((int)visited);
  }
  uint iteratorCopy;
  CopyFirstWord(&iteratorCopy,(uint *)&firstNode);
  CopyFirstWord(&pastLastNode,&iteratorCopy);
  int *tree = (int *)((byte *)owner + 4);
  uint header = tree[0];
  uint cursor = (uint)pastLastNode;
  if (cursor == *(uint *)(header + 8) && stop == header) {
    if (tree[1] != 0) {
      uint node = *(uint *)(header + 4);
      while (node != 0) {
        ReleaseTreeNodeBranch(tree,*(int *)(node + 0x0c));
        uint next = *(uint *)(node + 8);
        ReleaseMemoryIgnoringSize((void *)node,1);
        node = next;
      }
      header = tree[0];
      *(uint *)(header + 8) = header;
      header = tree[0];
      *(uint *)(header + 4) = 0;
      header = tree[0];
      *(uint *)(header + 0x0c) = header;
      tree[1] = 0;
    }
  } else {
    while (cursor != stop) {
      uint next = *(uint *)(cursor + 0x0c);
      if (next != 0) {
        uint left = *(uint *)(next + 8);
        while (left != 0) {
          next = left;
          left = *(uint *)(next + 8);
        }
      } else {
        next = cursor;
        uint parent = *(uint *)(cursor + 4);
        while (next == *(uint *)(parent + 0x0c)) {
          next = parent;
          parent = *(uint *)(parent + 4);
        }
        if (*(uint *)(next + 0x0c) != parent) next = parent;
      }
      pastLastNode = (char *)next;
      header = tree[0];
      char *detached = RemoveOrderedTreeNode(
          (char *)cursor,(int *)(header + 4),(uint *)(header + 8),(uint *)(header + 0x0c));
      TailFreeThroughGlobalAllocator(detached);
      ((uint *)tree)[1] = ((uint *)tree)[1] - 1;
      cursor = (uint)pastLastNode;
    }
  }
  return removedCount;
}

// Adjusts the saved map receiver to its embedded tree slot and invokes full structural destruction on unwind.
// R6GameService.dll @ 10064be0 : inherited EBP; conditional [EBP-0x14]+4 -> [EBP-0x10], JMP10023740.
__declspec(naked) void __cdecl DestroyCCDKeyProcessMapTreeOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_owner
    mov    eax,dword ptr [ebp-0x14]
    add    eax,0x4
    mov    dword ptr [ebp-0x10],eax
    jmp    adjusted_owner
  null_owner:
    mov    dword ptr [ebp-0x10],0
  adjusted_owner:
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyTreeContents
  }
}

// Releases the saved tree header after the destructor has entered its structural-release phase.
// R6GameService.dll @ 10064c07 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleaseCCDKeyProcessMapHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the identified map destructor's two-state exception metadata.
// R6GameService.dll @ 10064c0f : EAX=1007ef5c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl CCDKeyProcessMapDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CCDKeyProcessMapDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Identified specialization: native COL100794a0/type1008e9e8 names clPointerMap<void *, PRNGAlgorithm *>.
struct PRNGAlgorithmMapDestroyFrame {
  uint *savedOwner;
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the identified pointer-map specialization and optionally releases its object storage, returning the owner.
// R6GameService.dll @ 10038390 : ECX owner, flags stack word, RET4; primary vtable10077968 slot0.
void * __thiscall DeletePRNGAlgorithmPointerMap(void *owner,byte flags)
{
  DestroyPRNGAlgorithmPointerMap((int *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Installs the map vtable, dispatches value-range destruction, then frees remaining tree nodes and its header.
// R6GameService.dll @ 100386d0 : ECX owner, no stack arguments; EAX=header-free raw result.
uint __fastcall DestroyPRNGAlgorithmPointerMap(int *owner)
{
  PRNGAlgorithmMapDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PRNGAlgorithmMapDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  owner[0] = R6GameServiceAddresses::clPointerMap_PAXPAVPRNGAlgorithmVTable;
  int *tree = owner + 1;
  uint pastLast = tree[0];
  uint first = pastLast;
  uint vtable = owner[0];
  frame.state = 0;
  ReadOrderedTreeLeftmostLink(tree,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 1;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleasePRNGMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Deletes each visited owned value before structurally removing a half-open map range, returning the visit count.
// R6GameService.dll @ 10038820 : ECX identified map, first/last stack words, RET8; primary vtable slot0x0c.
uint __thiscall ErasePRNGAlgorithmPointerMapRange(void *owner,char *firstNode,char *pastLastNode)
{
  uint stop = (uint)pastLastNode;
  uint removedCount = 0;
  uint visited = (uint)firstNode;
  while (visited != stop && visited != *(uint *)((byte *)owner + 4)) {
    uint value = *(uint *)(visited + 0x14);
    if (value != 0) {
      typedef void (__thiscall *DeleteValue)(void *,uint);
      (*(DeleteValue *)*(uint *)value)((void *)value,1);
    }
    uint incremented = removedCount + 1;
    *(uint *)(visited + 0x14) = 0;
    removedCount = incremented;
    visited = (uint)OrderedTreeSuccessor((int)visited);
  }
  uint iteratorCopy;
  CopyFirstWord(&iteratorCopy,(uint *)&firstNode);
  CopyFirstWord(&pastLastNode,&iteratorCopy);
  int *tree = (int *)((byte *)owner + 4);
  uint header = tree[0];
  uint cursor = (uint)pastLastNode;
  if (cursor == *(uint *)(header + 8) && stop == header) {
    if (tree[1] != 0) {
      uint node = *(uint *)(header + 4);
      while (node != 0) {
        ReleasePRNGMapTreeBranch(tree,*(int *)(node + 0x0c));
        uint next = *(uint *)(node + 8);
        ReleaseMemoryIgnoringSize((void *)node,1);
        node = next;
      }
      header = tree[0];
      *(uint *)(header + 8) = header;
      header = tree[0];
      *(uint *)(header + 4) = 0;
      header = tree[0];
      *(uint *)(header + 0x0c) = header;
      tree[1] = 0;
    }
  } else {
    while (cursor != stop) {
      uint next = *(uint *)(cursor + 0x0c);
      if (next != 0) {
        uint left = *(uint *)(next + 8);
        while (left != 0) {
          next = left;
          left = *(uint *)(next + 8);
        }
      } else {
        next = cursor;
        uint parent = *(uint *)(cursor + 4);
        while (next == *(uint *)(parent + 0x0c)) {
          next = parent;
          parent = *(uint *)(parent + 4);
        }
        if (*(uint *)(next + 0x0c) != parent) next = parent;
      }
      pastLastNode = (char *)next;
      header = tree[0];
      char *detached = RemoveOrderedTreeNode(
          (char *)cursor,(int *)(header + 4),(uint *)(header + 8),(uint *)(header + 0x0c));
      TailFreeThroughGlobalAllocator(detached);
      ((uint *)tree)[1] = ((uint *)tree)[1] - 1;
      cursor = (uint)pastLastNode;
    }
  }
  return removedCount;
}

// Adjusts the saved map receiver to its embedded tree slot and invokes full structural destruction on unwind.
// R6GameService.dll @ 100668e0 : inherited EBP; conditional [EBP-0x14]+4 -> [EBP-0x10], JMP10038790.
__declspec(naked) void __cdecl DestroyPRNGAlgorithmMapTreeOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_owner
    mov    eax,dword ptr [ebp-0x14]
    add    eax,0x4
    mov    dword ptr [ebp-0x10],eax
    jmp    adjusted_owner
  null_owner:
    mov    dword ptr [ebp-0x10],0
  adjusted_owner:
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyPRNGMapTree
  }
}

// Releases the saved tree header after the destructor has entered its structural-release phase.
// R6GameService.dll @ 10066907 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleasePRNGAlgorithmMapHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the identified map destructor's two-state exception metadata.
// R6GameService.dll @ 1006690f : EAX=10080ed8, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PRNGAlgorithmMapDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PRNGAlgorithmMapDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Identified specialization: native COL10079420/type1008e8e8 names clPointerMap<void *, HashAlgorithm *>.
struct HashAlgorithmMapDestroyFrame {
  uint *savedOwner;
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the identified pointer-map specialization and optionally releases its object storage, returning the owner.
// R6GameService.dll @ 10038370 : ECX owner, flags stack word, RET4; primary vtable10077948 slot0.
void * __thiscall DeleteHashAlgorithmPointerMap(void *owner,byte flags)
{
  DestroyHashAlgorithmPointerMap((int *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Installs the map vtable, dispatches value-range destruction, then frees remaining tree nodes and its header.
// R6GameService.dll @ 100383f0 : ECX owner, no stack arguments; EAX=header-free raw result.
uint __fastcall DestroyHashAlgorithmPointerMap(int *owner)
{
  HashAlgorithmMapDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)HashAlgorithmMapDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  owner[0] = R6GameServiceAddresses::clPointerMap_PAXPAVHashAlgorithmVTable;
  int *tree = owner + 1;
  uint pastLast = tree[0];
  uint first = pastLast;
  uint vtable = owner[0];
  frame.state = 0;
  ReadOrderedTreeLeftmostLink(tree,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 1;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseHashMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Deletes each visited owned value before structurally removing a half-open map range, returning the visit count.
// R6GameService.dll @ 10038540 : ECX identified map, first/last stack words, RET8; primary vtable slot0x0c.
uint __thiscall EraseHashAlgorithmPointerMapRange(void *owner,char *firstNode,char *pastLastNode)
{
  uint stop = (uint)pastLastNode;
  uint removedCount = 0;
  uint visited = (uint)firstNode;
  while (visited != stop && visited != *(uint *)((byte *)owner + 4)) {
    uint value = *(uint *)(visited + 0x14);
    if (value != 0) {
      typedef void (__thiscall *DeleteValue)(void *,uint);
      (*(DeleteValue *)*(uint *)value)((void *)value,1);
    }
    uint incremented = removedCount + 1;
    *(uint *)(visited + 0x14) = 0;
    removedCount = incremented;
    visited = (uint)OrderedTreeSuccessor((int)visited);
  }
  uint iteratorCopy;
  CopyFirstWord(&iteratorCopy,(uint *)&firstNode);
  CopyFirstWord(&pastLastNode,&iteratorCopy);
  int *tree = (int *)((byte *)owner + 4);
  uint header = tree[0];
  uint cursor = (uint)pastLastNode;
  if (cursor == *(uint *)(header + 8) && stop == header) {
    if (tree[1] != 0) {
      uint node = *(uint *)(header + 4);
      while (node != 0) {
        ReleaseHashMapTreeBranch(tree,*(int *)(node + 0x0c));
        uint next = *(uint *)(node + 8);
        ReleaseMemoryIgnoringSize((void *)node,1);
        node = next;
      }
      header = tree[0];
      *(uint *)(header + 8) = header;
      header = tree[0];
      *(uint *)(header + 4) = 0;
      header = tree[0];
      *(uint *)(header + 0x0c) = header;
      tree[1] = 0;
    }
  } else {
    while (cursor != stop) {
      uint next = *(uint *)(cursor + 0x0c);
      if (next != 0) {
        uint left = *(uint *)(next + 8);
        while (left != 0) {
          next = left;
          left = *(uint *)(next + 8);
        }
      } else {
        next = cursor;
        uint parent = *(uint *)(cursor + 4);
        while (next == *(uint *)(parent + 0x0c)) {
          next = parent;
          parent = *(uint *)(parent + 4);
        }
        if (*(uint *)(next + 0x0c) != parent) next = parent;
      }
      pastLastNode = (char *)next;
      header = tree[0];
      char *detached = RemoveOrderedTreeNode(
          (char *)cursor,(int *)(header + 4),(uint *)(header + 8),(uint *)(header + 0x0c));
      TailFreeThroughGlobalAllocator(detached);
      ((uint *)tree)[1] = ((uint *)tree)[1] - 1;
      cursor = (uint)pastLastNode;
    }
  }
  return removedCount;
}

// Adjusts the saved map receiver to its embedded tree slot and invokes full structural destruction on unwind.
// R6GameService.dll @ 100668a0 : inherited EBP; conditional [EBP-0x14]+4 -> [EBP-0x10], JMP100384b0.
__declspec(naked) void __cdecl DestroyHashAlgorithmMapTreeOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_owner
    mov    eax,dword ptr [ebp-0x14]
    add    eax,0x4
    mov    dword ptr [ebp-0x10],eax
    jmp    adjusted_owner
  null_owner:
    mov    dword ptr [ebp-0x10],0
  adjusted_owner:
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyHashMapTree
  }
}

// Releases the saved tree header after the destructor has entered its structural-release phase.
// R6GameService.dll @ 100668c7 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleaseHashAlgorithmMapHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the identified map destructor's two-state exception metadata.
// R6GameService.dll @ 100668cf : EAX=10080e88, inherited-frame JMP10033906.
__declspec(naked) void __cdecl HashAlgorithmMapDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HashAlgorithmMapDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Identified specialization: native COL10079520/type1008eaf0 names clPointerMap<void *, CryptoAlgorithm *>.
struct CryptoAlgorithmMapDestroyFrame {
  uint *savedOwner;
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the identified pointer-map specialization and optionally releases its object storage, returning the owner.
// R6GameService.dll @ 100383b0 : ECX owner, flags stack word, RET4; primary vtable10077988 slot0.
void * __thiscall DeleteCryptoAlgorithmPointerMap(void *owner,byte flags)
{
  DestroyCryptoAlgorithmPointerMap((int *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Installs the map vtable, dispatches value-range destruction, then frees remaining tree nodes and its header.
// R6GameService.dll @ 10038960 : ECX owner, no stack arguments; EAX=header-free raw result.
uint __fastcall DestroyCryptoAlgorithmPointerMap(int *owner)
{
  CryptoAlgorithmMapDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)CryptoAlgorithmMapDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  owner[0] = R6GameServiceAddresses::clPointerMap_PAXPAVCryptoAlgorithmVTable;
  int *tree = owner + 1;
  uint pastLast = tree[0];
  uint first = pastLast;
  uint vtable = owner[0];
  frame.state = 0;
  ReadOrderedTreeLeftmostLink(tree,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 1;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleaseCryptoMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Deletes each visited owned value before structurally removing a half-open map range, returning the visit count.
// R6GameService.dll @ 10038ab0 : ECX identified map, first/last stack words, RET8; primary vtable slot0x0c.
uint __thiscall EraseCryptoAlgorithmPointerMapRange(void *owner,char *firstNode,char *pastLastNode)
{
  uint stop = (uint)pastLastNode;
  uint removedCount = 0;
  uint visited = (uint)firstNode;
  while (visited != stop && visited != *(uint *)((byte *)owner + 4)) {
    uint value = *(uint *)(visited + 0x14);
    if (value != 0) {
      typedef void (__thiscall *DeleteValue)(void *,uint);
      (*(DeleteValue *)*(uint *)value)((void *)value,1);
    }
    uint incremented = removedCount + 1;
    *(uint *)(visited + 0x14) = 0;
    removedCount = incremented;
    visited = (uint)OrderedTreeSuccessor((int)visited);
  }
  uint iteratorCopy;
  CopyFirstWord(&iteratorCopy,(uint *)&firstNode);
  CopyFirstWord(&pastLastNode,&iteratorCopy);
  int *tree = (int *)((byte *)owner + 4);
  uint header = tree[0];
  uint cursor = (uint)pastLastNode;
  if (cursor == *(uint *)(header + 8) && stop == header) {
    if (tree[1] != 0) {
      uint node = *(uint *)(header + 4);
      while (node != 0) {
        ReleaseCryptoMapTreeBranch(tree,*(int *)(node + 0x0c));
        uint next = *(uint *)(node + 8);
        ReleaseMemoryIgnoringSize((void *)node,1);
        node = next;
      }
      header = tree[0];
      *(uint *)(header + 8) = header;
      header = tree[0];
      *(uint *)(header + 4) = 0;
      header = tree[0];
      *(uint *)(header + 0x0c) = header;
      tree[1] = 0;
    }
  } else {
    while (cursor != stop) {
      uint next = *(uint *)(cursor + 0x0c);
      if (next != 0) {
        uint left = *(uint *)(next + 8);
        while (left != 0) {
          next = left;
          left = *(uint *)(next + 8);
        }
      } else {
        next = cursor;
        uint parent = *(uint *)(cursor + 4);
        while (next == *(uint *)(parent + 0x0c)) {
          next = parent;
          parent = *(uint *)(parent + 4);
        }
        if (*(uint *)(next + 0x0c) != parent) next = parent;
      }
      pastLastNode = (char *)next;
      header = tree[0];
      char *detached = RemoveOrderedTreeNode(
          (char *)cursor,(int *)(header + 4),(uint *)(header + 8),(uint *)(header + 0x0c));
      TailFreeThroughGlobalAllocator(detached);
      ((uint *)tree)[1] = ((uint *)tree)[1] - 1;
      cursor = (uint)pastLastNode;
    }
  }
  return removedCount;
}

// Adjusts the saved map receiver to its embedded tree slot and invokes full structural destruction on unwind.
// R6GameService.dll @ 10066920 : inherited EBP; conditional [EBP-0x14]+4 -> [EBP-0x10], JMP10038a20.
__declspec(naked) void __cdecl DestroyCryptoAlgorithmMapTreeOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_owner
    mov    eax,dword ptr [ebp-0x14]
    add    eax,0x4
    mov    dword ptr [ebp-0x10],eax
    jmp    adjusted_owner
  null_owner:
    mov    dword ptr [ebp-0x10],0
  adjusted_owner:
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyCryptoMapTree
  }
}

// Releases the saved tree header after the destructor has entered its structural-release phase.
// R6GameService.dll @ 10066947 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleaseCryptoAlgorithmMapHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the identified map destructor's two-state exception metadata.
// R6GameService.dll @ 1006694f : EAX=10080f28, inherited-frame JMP10033906.
__declspec(naked) void __cdecl CryptoAlgorithmMapDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CryptoAlgorithmMapDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Identified specialization: native COL100795a0/type1008ebec names clPointerMap<void *, PKCAlgorithm *>.
struct PKCAlgorithmMapDestroyFrame {
  uint *savedOwner;
  uint *savedTree;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Destroys the identified pointer-map specialization and optionally releases its object storage, returning the owner.
// R6GameService.dll @ 100383d0 : ECX owner, flags stack word, RET4; primary vtable100779a8 slot0.
void * __thiscall DeletePKCAlgorithmPointerMap(void *owner,byte flags)
{
  DestroyPKCAlgorithmPointerMap((int *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Installs the map vtable, dispatches value-range destruction, then frees remaining tree nodes and its header.
// R6GameService.dll @ 10038bf0 : ECX owner, no stack arguments; EAX=header-free raw result.
uint __fastcall DestroyPKCAlgorithmPointerMap(int *owner)
{
  PKCAlgorithmMapDestroyFrame frame;
  frame.state = 0xffffffff;
  frame.handler = (void *)PKCAlgorithmMapDestroyExceptionHandler;
  frame.previousExceptionList = ExceptionList;
  ExceptionList = &frame.previousExceptionList;
  frame.savedOwner = (uint *)owner;
  owner[0] = R6GameServiceAddresses::clPointerMap_PAXPAVPKCAlgorithmVTable;
  int *tree = owner + 1;
  uint pastLast = tree[0];
  uint first = pastLast;
  uint vtable = owner[0];
  frame.state = 0;
  ReadOrderedTreeLeftmostLink(tree,&first);
  typedef uint (__thiscall *EraseRange)(void *,uint,uint);
  (*(EraseRange *)(vtable + 0x0c))(owner,first,pastLast);
  frame.savedTree = (uint *)tree;
  uint count = tree[1];
  frame.state = 1;
  if (count != 0) {
    uint header = tree[0];
    uint node = *(uint *)(header + 4);
    while (node != 0) {
      ReleasePKCMapTreeBranch(tree,*(int *)(node + 0x0c));
      uint next = *(uint *)(node + 8);
      TailFreeThroughGlobalAllocator((void *)node);
      node = next;
    }
    header = tree[0];
    *(uint *)(header + 8) = header;
    header = tree[0];
    *(uint *)(header + 4) = 0;
    header = tree[0];
    *(uint *)(header + 0x0c) = header;
    tree[1] = 0;
  }
  uint result = TailFreeThroughGlobalAllocator((void *)tree[0]);
  ExceptionList = frame.previousExceptionList;
  return result;
}

// Deletes each visited owned value before structurally removing a half-open map range, returning the visit count.
// R6GameService.dll @ 10038d40 : ECX identified map, first/last stack words, RET8; primary vtable slot0x0c.
uint __thiscall ErasePKCAlgorithmPointerMapRange(void *owner,char *firstNode,char *pastLastNode)
{
  uint stop = (uint)pastLastNode;
  uint removedCount = 0;
  uint visited = (uint)firstNode;
  while (visited != stop && visited != *(uint *)((byte *)owner + 4)) {
    uint value = *(uint *)(visited + 0x14);
    if (value != 0) {
      typedef void (__thiscall *DeleteValue)(void *,uint);
      (*(DeleteValue *)*(uint *)value)((void *)value,1);
    }
    uint incremented = removedCount + 1;
    *(uint *)(visited + 0x14) = 0;
    removedCount = incremented;
    visited = (uint)OrderedTreeSuccessor((int)visited);
  }
  uint iteratorCopy;
  CopyFirstWord(&iteratorCopy,(uint *)&firstNode);
  CopyFirstWord(&pastLastNode,&iteratorCopy);
  int *tree = (int *)((byte *)owner + 4);
  uint header = tree[0];
  uint cursor = (uint)pastLastNode;
  if (cursor == *(uint *)(header + 8) && stop == header) {
    if (tree[1] != 0) {
      uint node = *(uint *)(header + 4);
      while (node != 0) {
        ReleasePKCMapTreeBranch(tree,*(int *)(node + 0x0c));
        uint next = *(uint *)(node + 8);
        ReleaseMemoryIgnoringSize((void *)node,1);
        node = next;
      }
      header = tree[0];
      *(uint *)(header + 8) = header;
      header = tree[0];
      *(uint *)(header + 4) = 0;
      header = tree[0];
      *(uint *)(header + 0x0c) = header;
      tree[1] = 0;
    }
  } else {
    while (cursor != stop) {
      uint next = *(uint *)(cursor + 0x0c);
      if (next != 0) {
        uint left = *(uint *)(next + 8);
        while (left != 0) {
          next = left;
          left = *(uint *)(next + 8);
        }
      } else {
        next = cursor;
        uint parent = *(uint *)(cursor + 4);
        while (next == *(uint *)(parent + 0x0c)) {
          next = parent;
          parent = *(uint *)(parent + 4);
        }
        if (*(uint *)(next + 0x0c) != parent) next = parent;
      }
      pastLastNode = (char *)next;
      header = tree[0];
      char *detached = RemoveOrderedTreeNode(
          (char *)cursor,(int *)(header + 4),(uint *)(header + 8),(uint *)(header + 0x0c));
      TailFreeThroughGlobalAllocator(detached);
      ((uint *)tree)[1] = ((uint *)tree)[1] - 1;
      cursor = (uint)pastLastNode;
    }
  }
  return removedCount;
}

// Adjusts the saved map receiver to its embedded tree slot and invokes full structural destruction on unwind.
// R6GameService.dll @ 10066960 : inherited EBP; conditional [EBP-0x14]+4 -> [EBP-0x10], JMP10038cb0.
__declspec(naked) void __cdecl DestroyPKCAlgorithmMapTreeOnUnwind(void)
{
  __asm {
    cmp    dword ptr [ebp-0x14],0
    je     null_owner
    mov    eax,dword ptr [ebp-0x14]
    add    eax,0x4
    mov    dword ptr [ebp-0x10],eax
    jmp    adjusted_owner
  null_owner:
    mov    dword ptr [ebp-0x10],0
  adjusted_owner:
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyPKCMapTree
  }
}

// Releases the saved tree header after the destructor has entered its structural-release phase.
// R6GameService.dll @ 10066987 : inherited EBP; MOV ECX,[EBP-0x10], JMP10041530.
__declspec(naked) void __cdecl ReleasePKCAlgorithmMapHeaderOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Selects the identified map destructor's two-state exception metadata.
// R6GameService.dll @ 1006698f : EAX=10080f78, inherited-frame JMP10033906.
__declspec(naked) void __cdecl PKCAlgorithmMapDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PKCAlgorithmMapDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native COL10078498/type1008c390 identifies this specialization as clPointerMap<void *, CHttpDownload *>.
// Destroys the HTTP registry map, then tests the current low deletion bit before freeing and returning its owner.
// R6GameService.dll @ 10014d10 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteHttpDownloadPointerMap(void *owner,uint deletionFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyHttpDownloadPointerMap
    test   BYTE PTR [esp+0x8],0x1
    je     Branch1
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch1:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Erases [leftmost,saved header), then structurally releases any remaining nodes and the live header.
// State0 guards the whole embedded tree; state1 guards its header. The final free supplies raw EAX.
// R6GameService.dll @ 10014d30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyHttpDownloadPointerMap(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyHttpDownloadPointerMapSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerMap_PAXPAVCHttpDownloadVTable
    push   ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push   ecx
    push   esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,edi
    call   DWORD PTR [ebx+0xc]
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x1c],0x1
    test   eax,eax
    je     Branch4
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax+0x4]
    test   edi,edi
    je     Branch3
  Branch2:
    mov    ecx,DWORD PTR [edi+0xc]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::ReleaseServiceTreeNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test   ebx,ebx
    mov    edi,ebx
    jne    Branch2
  Branch3:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch4:
    mov    eax,DWORD PTR [esi]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Deletes values before unlinking [first,last), clearing each value only after successful deletion.
// The stop/header checks reload the live header; copied incoming first/last slots drive structural erasure.
// Whole-tree reset reloads the header for each store; partial erasure caches the successor before removing/freeing.
// R6GameService.dll @ 10014e80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EraseHttpDownloadPointerMapRange(void *owner,void *first,void *last)
{
  __asm {
    sub    esp,0x8
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    xor    ebp,ebp
    push   edi
    cmp    esi,ebx
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    je     Branch7
  Branch5:
    cmp    esi,DWORD PTR [edi+0x4]
    je     Branch7
    mov    ecx,DWORD PTR [esi+0x14]
    cmp    ecx,ebp
    je     Branch6
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch6:
    mov    eax,DWORD PTR [esp+0x10]
    push   esi
    inc    eax
    mov    DWORD PTR [esi+0x14],ebp
    mov    DWORD PTR [esp+0x14],eax
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    esi,eax
    add    esp,0x4
    cmp    esi,ebx
    jne    Branch5
  Branch7:
    lea    ecx,[esp+0x1c]
    push   ecx
    lea    ecx,[esp+0x18]
    call   R6GameServiceAddresses::CopyFirstWord
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x20]
    push   edx
    lea    esi,[edi+0x4]
    call   R6GameServiceAddresses::CopyFirstWord
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0x20]
    cmp    eax,DWORD PTR [ecx+0x8]
    jne    Branch10
    cmp    ebx,ecx
    jne    Branch10
    cmp    DWORD PTR [esi+0x4],ebp
    je     Branch17
    mov    edi,DWORD PTR [ecx+0x4]
    cmp    edi,ebp
    je     Branch9
  Branch8:
    mov    eax,DWORD PTR [edi+0xc]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::ReleaseServiceTreeNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push   0x1
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    ebx,ebp
    mov    edi,ebx
    jne    Branch8
  Branch9:
    mov    eax,DWORD PTR [esi]
    pop    edi
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x4],ebp
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch10:
    cmp    eax,ebx
    je     Branch17
  Branch11:
    mov    ecx,DWORD PTR [eax+0xc]
    mov    edx,eax
    cmp    ecx,ebp
    je     Branch13
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    je     Branch16
  Branch12:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    jne    Branch12
    jmp    Branch16
  Branch13:
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    jne    Branch15
  Branch14:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch14
  Branch15:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch16
    mov    eax,ecx
  Branch16:
    mov    DWORD PTR [esp+0x20],eax
    mov    eax,DWORD PTR [esi]
    lea    ecx,[eax+0xc]
    push   ecx
    lea    ecx,[eax+0x8]
    add    eax,0x4
    push   ecx
    push   eax
    push   edx
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esp+0x20]
    dec    edx
    cmp    eax,ebx
    mov    DWORD PTR [esi+0x4],edx
    jne    Branch11
  Branch17:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Publishes saved owner+4 (or null) at frame-0x10 and tail-destroys that embedded tree without deleting values.
// R6GameService.dll @ 100645c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyHttpDownloadPointerMapUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je     Branch18
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch19
  Branch18:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch19:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseCountedTreeAndHeader
  }
}

// Releases the live header through the saved embedded-tree slot at frame-0x10.
// R6GameService.dll @ 100645e7 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyHttpDownloadPointerMapUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// R6GameService.dll data @ 1007e864 : native HTTP lifetime records.
const R6GameServiceNative::UnwindEntry DestroyHttpDownloadPointerMapUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyHttpDownloadPointerMapUnwind1},
  {-1, R6GameServiceAddresses::DestroyHttpDownloadPointerMapUnwind2},
};
// R6GameService.dll data @ 1007e874 : native HTTP lifetime records.
const R6GameServiceNative::FuncInfo DestroyHttpDownloadPointerMapExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyHttpDownloadPointerMapUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Selects the two-state HTTP pointer-map destructor guard.
// R6GameService.dll @ 100645ef : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyHttpDownloadPointerMapSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyHttpDownloadPointerMapExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroy this RTTI pointer-map specialization, then test CURRENT low flag bit0 and optionally free owner.
// Return captured owner regardless of child/free EAX; no wrapper EH or rollback. RET4.
// RTTI: clPointerMap<unsigned int, CLadderResults *>; class ownership is recovered, field names remain descriptive.
// R6GameService.dll @ 10041960 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteLadderResultPointerMap(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainer
    test    BYTE PTR [esp+0x8],0x1
    je    Branch20
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch20:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroy this RTTI pointer-map specialization, then test CURRENT low flag bit0 and optionally free owner.
// Return captured owner regardless of child/free EAX; no wrapper EH or rollback. RET4.
// RTTI: clPointerMap<unsigned int, clDataList *>; class ownership is recovered, field names remain descriptive.
// R6GameService.dll @ 10041980 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteDataListPointerMap(void *owner,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyServiceTreeContainerVariant
    test    BYTE PTR [esp+0x8],0x1
    je    Branch21
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch21:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Tail exact container destructor with unchanged receiver/stack/raw result.
// R6GameService.dll @ 10041910 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyServiceTreeContainer(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainer
  }
}

// Tail exact container destructor with unchanged receiver/stack/raw result.
// R6GameService.dll @ 10041920 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyServiceTreeContainerVariant(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyServiceTreeContainerVariant
  }
}

// Install RTTI map table, visit/delete values through native range method, then clear CURRENT nodes/head.
// Entry S: ownerS-14/treeS-10/stateS-4. State0 drains nodes without value retry; state1 releases only head.
// Preserve captured table/owner, late count/header loads, partial effects and full raw final free EAX.
// RTTI specialization: clPointerMap<unsigned int, CLadderResults *>.
// R6GameService.dll @ 100426e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clPointerMap_DestroyServiceTreeContainer(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectLadderPointerMapDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerMap_IPAVCLadderResultsVTable
    push    ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,edi
    call    DWORD PTR [ebx+0xc]
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x1c],0x1
    test    eax,eax
    je    Branch24
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax+0x4]
    test    edi,edi
    je    Branch23
  Branch22:
    mov    ecx,DWORD PTR [edi+0xc]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    edi,ebx
    jne    Branch22
  Branch23:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch24:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Install RTTI map table, visit/delete values through native range method, then clear CURRENT nodes/head.
// Entry S: ownerS-14/treeS-10/stateS-4. State0 drains nodes without value retry; state1 releases only head.
// Preserve captured table/owner, late count/header loads, partial effects and full raw final free EAX.
// RTTI specialization: clPointerMap<unsigned int, clDataList *>.
// R6GameService.dll @ 10042970 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyServiceTreeContainerVariant(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectDataListPointerMapDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push    ebx
    push    esi
    push    edi
    mov    edi,ecx
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [edi],R6GameServiceAddresses::clPointerMap_IPAVclDataListVTable
    push    ecx
    mov    ecx,DWORD PTR [edi+0x4]
    lea    esi,[edi+0x4]
    mov    eax,esp
    push    ecx
    push    esp
    mov    DWORD PTR [eax],ecx
    mov    ebx,DWORD PTR [edi]
    mov    ecx,esi
    mov    DWORD PTR [esp+0x28],0x0
    call    R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    ecx,edi
    call    DWORD PTR [ebx+0xc]
    mov    DWORD PTR [esp+0x10],esi
    mov    eax,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x1c],0x1
    test    eax,eax
    je    Branch27
    mov    eax,DWORD PTR [esi]
    mov    edi,DWORD PTR [eax+0x4]
    test    edi,edi
    je    Branch26
  Branch25:
    mov    ecx,DWORD PTR [edi+0xc]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes2
    mov    ebx,DWORD PTR [edi+0x8]
    push    edi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    test    ebx,ebx
    mov    edi,ebx
    jne    Branch25
  Branch26:
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],0x0
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [esi+0x4],0x0
  Branch27:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Delete each visited nonNULL node value, then clear that value slot and advance with native successor.
// Erase original range via full-tree or native RB path; preserve current-header checks/count/raw effects. RET8.
// RTTI specialization: clPointerMap<unsigned int, CLadderResults *>.
// R6GameService.dll @ 100427a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EraseOrderedTreeRangeAndDetachValues(
    void *owner,void *firstNode,void *pastLast)
{
  __asm {
    sub    esp,0x8
    push    ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    xor    ebp,ebp
    push    edi
    cmp    esi,ebx
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    je    Branch30
  Branch28:
    cmp    esi,DWORD PTR [edi+0x4]
    je    Branch30
    mov    ecx,DWORD PTR [esi+0x14]
    cmp    ecx,ebp
    je    Branch29
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch29:
    mov    eax,DWORD PTR [esp+0x10]
    push    esi
    inc    eax
    mov    DWORD PTR [esi+0x14],ebp
    mov    DWORD PTR [esp+0x14],eax
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    mov    esi,eax
    add    esp,0x4
    cmp    esi,ebx
    jne    Branch28
  Branch30:
    lea    ecx,[esp+0x1c]
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyFirstWord
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x20]
    push    edx
    lea    esi,[edi+0x4]
    call    R6GameServiceAddresses::CopyFirstWord
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0x20]
    cmp    eax,DWORD PTR [ecx+0x8]
    jne    Branch33
    cmp    ebx,ecx
    jne    Branch33
    cmp    DWORD PTR [esi+0x4],ebp
    je    Branch40
    mov    edi,DWORD PTR [ecx+0x4]
    cmp    edi,ebp
    je    Branch32
  Branch31:
    mov    eax,DWORD PTR [edi+0xc]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes
    mov    ebx,DWORD PTR [edi+0x8]
    push    0x1
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    ebx,ebp
    mov    edi,ebx
    jne    Branch31
  Branch32:
    mov    eax,DWORD PTR [esi]
    pop    edi
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x4],ebp
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch33:
    cmp    eax,ebx
    je    Branch40
  Branch34:
    mov    ecx,DWORD PTR [eax+0xc]
    mov    edx,eax
    cmp    ecx,ebp
    je    Branch36
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    je    Branch39
  Branch35:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    jne    Branch35
    jmp    Branch39
  Branch36:
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    jne    Branch38
  Branch37:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch37
  Branch38:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch39
    mov    eax,ecx
  Branch39:
    mov    DWORD PTR [esp+0x20],eax
    mov    eax,DWORD PTR [esi]
    lea    ecx,[eax+0xc]
    push    ecx
    lea    ecx,[eax+0x8]
    add    eax,0x4
    push    ecx
    push    eax
    push    edx
    call    R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esp+0x20]
    dec    edx
    cmp    eax,ebx
    mov    DWORD PTR [esi+0x4],edx
    jne    Branch34
  Branch40:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Delete each visited nonNULL node value, then clear that value slot and advance with native successor.
// Erase original range via full-tree or native RB path; preserve current-header checks/count/raw effects. RET8.
// RTTI specialization: clPointerMap<unsigned int, clDataList *>.
// R6GameService.dll @ 10042a30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EraseAlternateOrderedTreeRangeAndDetachValues(
    void *owner,void *firstNode,void *pastLast)
{
  __asm {
    sub    esp,0x8
    push    ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push    ebp
    push    esi
    mov    esi,DWORD PTR [esp+0x18]
    xor    ebp,ebp
    push    edi
    cmp    esi,ebx
    mov    edi,ecx
    mov    DWORD PTR [esp+0x10],ebp
    je    Branch43
  Branch41:
    cmp    esi,DWORD PTR [edi+0x4]
    je    Branch43
    mov    ecx,DWORD PTR [esi+0x14]
    cmp    ecx,ebp
    je    Branch42
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch42:
    mov    eax,DWORD PTR [esp+0x10]
    push    esi
    inc    eax
    mov    DWORD PTR [esi+0x14],ebp
    mov    DWORD PTR [esp+0x14],eax
    call    R6GameServiceAddresses::OrderedTreeSuccessor
    mov    esi,eax
    add    esp,0x4
    cmp    esi,ebx
    jne    Branch41
  Branch43:
    lea    ecx,[esp+0x1c]
    push    ecx
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::CopyFirstWord
    lea    edx,[esp+0x14]
    lea    ecx,[esp+0x20]
    push    edx
    lea    esi,[edi+0x4]
    call    R6GameServiceAddresses::CopyFirstWord
    mov    ecx,DWORD PTR [esi]
    mov    eax,DWORD PTR [esp+0x20]
    cmp    eax,DWORD PTR [ecx+0x8]
    jne    Branch46
    cmp    ebx,ecx
    jne    Branch46
    cmp    DWORD PTR [esi+0x4],ebp
    je    Branch53
    mov    edi,DWORD PTR [ecx+0x4]
    cmp    edi,ebp
    je    Branch45
  Branch44:
    mov    eax,DWORD PTR [edi+0xc]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::ordered_tree_support_ReleaseTreeNodes2
    mov    ebx,DWORD PTR [edi+0x8]
    push    0x1
    push    edi
    mov    ecx,esi
    call    R6GameServiceAddresses::ReleaseMemoryIgnoringSize
    cmp    ebx,ebp
    mov    edi,ebx
    jne    Branch44
  Branch45:
    mov    eax,DWORD PTR [esi]
    pop    edi
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [ecx+0x4],ebp
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esi+0x4],ebp
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  Branch46:
    cmp    eax,ebx
    je    Branch53
  Branch47:
    mov    ecx,DWORD PTR [eax+0xc]
    mov    edx,eax
    cmp    ecx,ebp
    je    Branch49
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    je    Branch52
  Branch48:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebp
    jne    Branch48
    jmp    Branch52
  Branch49:
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    jne    Branch51
  Branch50:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je    Branch50
  Branch51:
    cmp    DWORD PTR [eax+0xc],ecx
    je    Branch52
    mov    eax,ecx
  Branch52:
    mov    DWORD PTR [esp+0x20],eax
    mov    eax,DWORD PTR [esi]
    lea    ecx,[eax+0xc]
    push    ecx
    lea    ecx,[eax+0x8]
    add    eax,0x4
    push    ecx
    push    eax
    push    edx
    call    R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    edx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esp+0x20]
    dec    edx
    cmp    eax,ebx
    mov    DWORD PTR [esi+0x4],edx
    jne    Branch47
  Branch53:
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Drain nodes through CURRENT saved owner+4 or free CURRENT saved tree first word; preserve NULL/scratch.
// R6GameService.dll @ 10067120 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clPointerMap_DestroyServiceTreeContainerUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch54
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch55
  Branch54:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch55:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ClearOrderedTreeStorage
  }
}

// Drain nodes through CURRENT saved owner+4 or free CURRENT saved tree first word; preserve NULL/scratch.
// R6GameService.dll @ 10067147 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clPointerMap_DestroyServiceTreeContainerUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Drain nodes through CURRENT saved owner+4 or free CURRENT saved tree first word; preserve NULL/scratch.
// R6GameService.dll @ 10067160 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceTreeContainerVariantUnwind1(void)
{
  __asm {
    cmp    DWORD PTR [ebp-0x14],0x0
    je    Branch56
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x4
    mov    DWORD PTR [ebp-0x10],eax
    jmp    Branch57
  Branch56:
    mov    DWORD PTR [ebp-0x10],0x0
  Branch57:
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyServiceSubtreeContainer
  }
}

// Drain nodes through CURRENT saved owner+4 or free CURRENT saved tree first word; preserve NULL/scratch.
// R6GameService.dll @ 10067187 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceTreeContainerVariantUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseFirstWordBuffer
  }
}

// Select exact inherited destruction FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 1006714f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectLadderPointerMapDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select exact inherited destruction FuncInfo and tail CRT dispatch.
// R6GameService.dll @ 1006718f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectDataListPointerMapDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceTreeContainerVariantExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 1008181c : native storage identity retained.
const R6GameServiceNative::UnwindEntry clPointerMap_DestroyServiceTreeContainerUnwindMap[2] = {
  {-1, R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainerUnwind1},
  {-1, R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainerUnwind2},
};

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 1008182c : native storage identity retained.
const R6GameServiceNative::FuncInfo clPointerMap_DestroyServiceTreeContainerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::clPointerMap_DestroyServiceTreeContainerUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 1008186c : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyServiceTreeContainerVariantUnwindMap[2] = {
  {-1, R6GameServiceAddresses::DestroyServiceTreeContainerVariantUnwind1},
  {-1, R6GameServiceAddresses::DestroyServiceTreeContainerVariantUnwind2},
};

// Literal destruction map/FuncInfo; entered value/node cleanup is not repeated.
// R6GameService.dll data @ 1008187c : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceTreeContainerVariantExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::DestroyServiceTreeContainerVariantUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clPointerMap_PAXPAVCHttpDownloadVTable
// R6GameService.dll data @ 10075b9c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVCHttpDownloadVTableRecord {
  R6GameServiceNative::Address DeleteHttpDownloadPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseHttpDownloadPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVCHttpDownloadVTableRecord clPointerMap_PAXPAVCHttpDownloadVTable = {
  R6GameServiceAddresses::DeleteHttpDownloadPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseHttpDownloadPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_PAXPAVCCDKeyProcessVTable
// R6GameService.dll data @ 100769ac : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVCCDKeyProcessVTableRecord {
  R6GameServiceNative::Address DeleteCCDKeyProcessPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseCCDKeyProcessPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVCCDKeyProcessVTableRecord clPointerMap_PAXPAVCCDKeyProcessVTable = {
  R6GameServiceAddresses::DeleteCCDKeyProcessPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseCCDKeyProcessPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_PAXPAVHashAlgorithmVTable
// R6GameService.dll data @ 10077948 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVHashAlgorithmVTableRecord {
  R6GameServiceNative::Address DeleteHashAlgorithmPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseHashAlgorithmPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVHashAlgorithmVTableRecord clPointerMap_PAXPAVHashAlgorithmVTable = {
  R6GameServiceAddresses::DeleteHashAlgorithmPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseHashAlgorithmPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_PAXPAVPRNGAlgorithmVTable
// R6GameService.dll data @ 10077968 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVPRNGAlgorithmVTableRecord {
  R6GameServiceNative::Address DeletePRNGAlgorithmPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address ErasePRNGAlgorithmPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVPRNGAlgorithmVTableRecord clPointerMap_PAXPAVPRNGAlgorithmVTable = {
  R6GameServiceAddresses::DeletePRNGAlgorithmPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::ErasePRNGAlgorithmPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_PAXPAVCryptoAlgorithmVTable
// R6GameService.dll data @ 10077988 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVCryptoAlgorithmVTableRecord {
  R6GameServiceNative::Address DeleteCryptoAlgorithmPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseCryptoAlgorithmPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVCryptoAlgorithmVTableRecord clPointerMap_PAXPAVCryptoAlgorithmVTable = {
  R6GameServiceAddresses::DeleteCryptoAlgorithmPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseCryptoAlgorithmPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_PAXPAVPKCAlgorithmVTable
// R6GameService.dll data @ 100779a8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_PAXPAVPKCAlgorithmVTableRecord {
  R6GameServiceNative::Address DeletePKCAlgorithmPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address ErasePKCAlgorithmPointerMapRange; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_PAXPAVPKCAlgorithmVTableRecord clPointerMap_PAXPAVPKCAlgorithmVTable = {
  R6GameServiceAddresses::DeletePKCAlgorithmPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::ErasePKCAlgorithmPointerMapRange,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_IPAVclDataListVTable
// R6GameService.dll data @ 10077da8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_IPAVclDataListVTableRecord {
  R6GameServiceNative::Address DeleteDataListPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseAlternateOrderedTreeRangeAndDetachValues; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_IPAVclDataListVTableRecord clPointerMap_IPAVclDataListVTable = {
  R6GameServiceAddresses::DeleteDataListPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseAlternateOrderedTreeRangeAndDetachValues,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};

// Native virtual-table prefix: clPointerMap_IPAVCLadderResultsVTable
// R6GameService.dll data @ 10077dc8 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clPointerMap_IPAVCLadderResultsVTableRecord {
  R6GameServiceNative::Address DeleteLadderResultPointerMap; // +0x00
  R6GameServiceNative::Address DispatchMapFullRangeErase; // +0x04
  R6GameServiceNative::Address DispatchOwnedMapKeyErase; // +0x08
  R6GameServiceNative::Address EraseOrderedTreeRangeAndDetachValues; // +0x0c
  R6GameServiceNative::Address EraseOwnedPointerMapNode; // +0x10
};
const clPointerMap_IPAVCLadderResultsVTableRecord clPointerMap_IPAVCLadderResultsVTable = {
  R6GameServiceAddresses::DeleteLadderResultPointerMap,
  R6GameServiceAddresses::DispatchMapFullRangeErase,
  R6GameServiceAddresses::DispatchOwnedMapKeyErase,
  R6GameServiceAddresses::EraseOrderedTreeRangeAndDetachValues,
  R6GameServiceAddresses::EraseOwnedPointerMapNode,
};
