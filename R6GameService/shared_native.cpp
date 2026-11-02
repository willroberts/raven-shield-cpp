#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080d6c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo CipherModuleDestroyExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10081068 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo HashModuleDestroyExceptionHandlerFunctionInfo;

// Imported Core allocator variable; the PE32 IAT slot at 1006b170 addresses its live pointer cell.
extern __declspec(dllimport) FMalloc *GMalloc;

// Returns the supplied placement pointer for five class-facing aliases; ignores requested allocation size.
// R6GameService.dll @ 100015d0 : complete native control/access order and raw ABI retained.
void * __cdecl UR6GSServers::operator new(uint size,EInternal *memory)
{
  return memory;
}

// Discards two stack arguments without other effects, retaining incoming EAX.
// R6GameService.dll @ 1002b6e0 : shared empty callback; RET 8.
void __stdcall NoOp(uint unusedWord0,uint unusedWord1)
{
  return;
}

// Stores second full argument through receiver, leaving EAX receiver and ECX value; first argument word is unread.
// R6GameService.dll @ 100561b0 : complete native operations and raw ABI; descriptive helper name.
void * __thiscall StoreFirstWordIgnoringContext(void *receiver,uint unusedWord,uint valueWord)
{
  *static_cast<uint *>(receiver) = valueWord;
  return receiver;
}





// Resets a trivial scalar descriptor to the base vtable and optionally frees it, returning the saved receiver.
// R6GameService.dll @ 1002aff0 : shared by vtables10076ad4/10076af8/10076b1c; ECX object, flags stack word, RET4.
void * __thiscall DeleteTrivialScalarDescriptor(void *object,byte flags)
{
  ResetClDataVtable((undefined4 *)object);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(object);
  return object;
}

// Returns the original stack word and consumes it, retaining ECX and all other general registers.
// R6GameService.dll @ 100561a0 : MOV EAX,[ESP+4]/RET4; ECX context is ignored.
uint __stdcall ForwardStackWord(uint word)
{
  return word;
}

// Returns full zero while retaining ECX and the caller's argument words.
// R6GameService.dll @ 1005d350 : XOR EAX,EAX/RET; no stack arguments are consumed.
uint __cdecl ReturnZero(void)
{
  return 0;
}

// Replaces AL with ECX's high byte, retaining incoming EAX's upper three bytes and the original ECX.
// R6GameService.dll @ 10028810 : ECX context, no stack arguments; PUSH ECX/MOV AL,[ESP+3]/POP ECX/RET.
__declspec(naked) uint __fastcall SelectContextHighByteIntoAL(uint contextWord)
{
  __asm {
    push   ecx
    mov    al,byte ptr [esp+0x3]
    pop    ecx
    ret
  }
}

// Stores the target pointer's low byte through that pointer; EAX returns the pointer and CL retains its low byte.
// R6GameService.dll @ 10028820 : three stack words, RET0xc; ECX's upper three bytes and EDX remain unchanged.
__declspec(naked) uint __stdcall StoreArgumentLowByteAtAddress(
    undefined1 *target,uint unusedWord1,uint unusedWord2)
{
  __asm {
    mov    eax,dword ptr [esp+0x4]
    mov    cl,byte ptr [esp+0x4]
    mov    byte ptr [eax],cl
    ret    0xc
  }
}

// Copies one source word into the receiver, returning the receiver and retaining source/copied word in ECX/EDX.
// R6GameService.dll @ 10059100 : ECX destination, source-slot stack word, RET4; EAX=destination.
void * __thiscall CopyFirstWord(void *destination,undefined4 *source)
{
  *static_cast<undefined4 *>(destination) = *source;
  return destination;
}

// Releases the first stack-word pointer, ignores the size word and retains the allocator's raw EAX.
// R6GameService.dll @ 10061d00 : two stdcall stack words, RET8; ECX context is ignored before CALL6390.
__declspec(naked) uint __stdcall ReleaseMemoryIgnoringSize(void *memory,uint unusedSize)
{
  __asm {
    mov    eax,dword ptr [esp+0x4]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    ret    0x8
  }
}

// Shared native frame for CipherModule_Blowfish and CipherModule_GSXor destruction.
struct CipherModuleDestroyFrame {
  uint *savedOwner; // EBP-0x10.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Restores the saved receiver's allocation base table if either cipher module's owned-state deletion throws.
// R6GameService.dll @ 100667a0 : inherited EBP-0x10 receiver, JMP10037840; one shared action body.
__declspec(naked) void __cdecl ResetCipherModuleBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the one-state base-reset map shared by the Blowfish and GSXor module destructors.
// R6GameService.dll @ 100667a8 : EAX=10080d6c, inherited-frame JMP10033906.
__declspec(naked) void __cdecl CipherModuleDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CipherModuleDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Restores the allocation base table and optionally frees storage; shared by the CGSXor and RSA deleting slots.
// R6GameService.dll @ 1003ce90 : ECX receiver, flags stack word, RET4; EAX=original receiver.
void * __thiscall DeleteExtallocBaseObject(void *owner,byte flags)
{
  DestroyExtallocOverrideBase((uint *)owner);
  if ((flags & 1) != 0) TailFreeThroughGlobalAllocator(owner);
  return owner;
}

// Shared cache formatter literal, native address1008fcbc; each call writes two digits and a terminator.
extern const char GHashModuleHexFormat[] = "%02x";

// Shared native frame for HashModule_SHA1 and HashModule_MD5 destruction.
struct HashModuleDestroyFrame {
  uint *savedOwner; // EBP-0x10, followed by chain/handler/state at-0x0c/-8/-4.
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Restores the allocation base table when either hash wrapper's child deletion throws.
// R6GameService.dll @ 10066a40 : inherited parent EBP, no stack words; tail-forwards saved receiver to base reset.
__declspec(naked) void __cdecl ResetHashModuleBaseOnUnwind(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the one-state base-reset unwind map shared by both hash wrapper destructors.
// R6GameService.dll @ 10066a48 : EAX selects native FuncInfo; inherited-frame tail jump to10033906.
__declspec(naked) void __cdecl HashModuleDestroyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::HashModuleDestroyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Deletes the first payload, reloads the current first node after the callback, then unlinks and frees it.
// R6GameService.dll @ 10026f50 : native accesses, callback ordering and raw register results retained.
__declspec(naked) uint __thiscall DestroyFirstListNode(void *list)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    cmp    DWORD PTR [eax],eax
    je Branch2
    mov    ecx,DWORD PTR [eax]
    mov    ecx,DWORD PTR [ecx+0x8]
    test   ecx,ecx
    je Branch1
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx]
    // The payload callback may replace the head or first node; reload both.
  Branch1:
    mov    eax,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [eax]
    push   eax
    mov    edx,DWORD PTR [eax+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [ecx+0x4],edx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    pop    esi
    ret
  }
}

// Deletes a nonsentinel payload, unlinks and frees the supplied node, then writes its saved next link.
// R6GameService.dll @ 10026f80 : native accesses, callback ordering and raw register results retained.
__declspec(naked) uint * __thiscall DestroyListNodeAndReturnNext(void *list,uint *nextOut,uint *node)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x4]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,eax
    je Branch3
    mov    ecx,DWORD PTR [edi+0x8]
    test   ecx,ecx
    je Branch3
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    // Sentinel suppresses only payload deletion; the node is still unlinked and freed.
  Branch3:
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,DWORD PTR [edi]
    push   edi
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [esi+0x4],eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    // Load the output pointer after freeing, but retain the next link saved before freeing.
    mov    eax,DWORD PTR [esp+0xc]
    pop    edi
    mov    DWORD PTR [eax],esi
    pop    esi
    ret    0x8
  }
}

// Optionally installs the +4 vbtable, zeros the head slot, and installs an unchecked self-linked sentinel.
// R6GameService.dll @ 10026fc0 : native accesses, callback ordering and raw register results retained.
__declspec(naked) void * __thiscall InitializePayloadListSentinel(
    void *headSlot,uint initializeVirtualBaseWord)
{
  __asm {
    push   ecx
    mov    eax,DWORD PTR [esp+0x8]
    push   esi
    test   eax,eax
    mov    esi,ecx
    // Saved ECX becomes zero; POP ECX returns that zero on normal completion.
    mov    DWORD PTR [esp+0x4],0x0
    je Branch4
    mov    DWORD PTR [esi+0x4],0x10076aa0
  Branch4:
    push   0xc
    mov    DWORD PTR [esi],0x0
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Allocation failure faults here; payload word +8 stays untouched.
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Allocates the saved byte count, then reloads/copies the actual source range and returns the allocation base.
// R6GameService.dll @ 1002bbc0 : complete native accesses, scratch/argument order and raw register results.
__declspec(naked) void * __stdcall AllocateAndCopyByteRange(uint allocationBytes,void *first,void *last)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Load first/last after allocation; allocation size stays the earlier captured word and does not clamp the copy.
    mov    ecx,DWORD PTR [esp+0xc]
    mov    esi,eax
    mov    eax,DWORD PTR [esp+0x10]
    cmp    eax,ecx
    je Branch5
    sub    eax,ecx
    push   eax
    push   ecx
    push   esi
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch5:
    mov    eax,esi
    pop    esi
    ret    0xc
  }
}

// Returns without effects, consuming24 native argument bytes and preserving raw registers.
// R6GameService.dll @ 100329e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall NoOpServiceCallbackRet18(uint word0,uint word1,uint word2,uint word3,uint word4,uint word5)
{
  __asm {
    ret    0x18
  }
}

// Returns without effects, consuming12 native argument bytes and preserving raw registers.
// R6GameService.dll @ 100329f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall NoOpServiceCallbackRet0C(uint word0,uint word1,uint word2)
{
  __asm {
    ret    0xc
  }
}

// Compares the descriptor byte range with a NUL-terminated string after an exact length check.
// Returns normalized EAX0/1, retaining native REP comparison cursor/count residues and cdecl stack words.
// R6GameService.dll @ 100178c0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __cdecl ByteStringEqualsAnsi(uint *descriptor,char *text)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    mov    edi,edx
    or     ecx,0xffffffff
    xor    eax,eax
    repnz  scas al,BYTE PTR es:[edi]
    mov    eax,DWORD PTR [esp+0xc]
    not    ecx
    mov    esi,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    dec    ecx
    sub    eax,esi
    cmp    eax,ecx
    jne    Branch6
    mov    edi,edx
    xor    edx,edx
    repz   cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
    jne    Branch6
    pop    edi
    mov    eax,0x1
    pop    esi
    ret
  Branch6:
    pop    edi
    xor    eax,eax
    pop    esi
    ret
  }
}

// Searches four bytes per iteration then the short tail, returning the first matching byte or end.
// Only the low needle byte is used; the fourth stack word is unused but consumed, with raw EDX/count effects.
// R6GameService.dll @ 10018100 : complete native control/access order and raw ABI retained.
__declspec(naked) char * __stdcall FindByteInRange(char *begin,char *end,char value,void *unusedWord)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    mov    dl,BYTE PTR [esp+0x14]
    mov    ecx,esi
    sub    ecx,eax
    sar    ecx,0x2
    test   ecx,ecx
    jle    Branch8
  Branch7:
    cmp    BYTE PTR [eax],dl
    je     Branch12
    mov    bl,BYTE PTR [eax+0x1]
    inc    eax
    cmp    bl,dl
    je     Branch12
    mov    bl,BYTE PTR [eax+0x1]
    inc    eax
    cmp    bl,dl
    je     Branch12
    mov    bl,BYTE PTR [eax+0x1]
    inc    eax
    cmp    bl,dl
    je     Branch12
    inc    eax
    dec    ecx
    test   ecx,ecx
    jg     Branch7
  Branch8:
    mov    ecx,esi
    sub    ecx,eax
    dec    ecx
    je     Branch10
    dec    ecx
    je     Branch9
    dec    ecx
    jne    Branch11
    cmp    BYTE PTR [eax],dl
    je     Branch12
    inc    eax
  Branch9:
    cmp    BYTE PTR [eax],dl
    je     Branch12
    inc    eax
  Branch10:
    cmp    BYTE PTR [eax],dl
    je     Branch12
  Branch11:
    mov    eax,esi
  Branch12:
    pop    esi
    pop    ebx
    ret    0x10
  }
}

// Tail-forwards the original receiver to the shared circular-list destructor.
// R6GameService.dll @ 1002e610 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ForwardToCircularListDestructor(void *list)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyCircularList
  }
}

// Tail-forwards to genuine empty allocator/context cleanup, retaining raw registers.
// R6GameService.dll @ 1002e690 : native control/access order and raw ABI retained.
__declspec(naked) void __fastcall ForwardToNoOp(void *context)
{
  __asm {
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Loads current receiver first word, includingNULL, then frees it through global allocator and retains raw EAX.
// R6GameService.dll @ 10041530 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ReleaseFirstWordBuffer(void *ownerAddress)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    ret
  }
}

// Loads imported allocator receiver and current allocation slot, forwards size and new tag; returns raw pointer with cdecl word intact.
// R6GameService.dll @ 10001160 : native control/access order and raw ABI retained.
void * __cdecl AllocateTaggedBytesCdecl(uint byteCount)
{
  FMalloc *allocator = GMalloc;
  return allocator->Malloc(byteCount,reinterpret_cast<const TCHAR *>(R6GameServiceAddresses::WideTextNew));
}

// Copies original memory word to allocator release call, preserving raw EAX and original cdecl argument.
// R6GameService.dll @ 10001180 : native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl FreeThroughGlobalAllocator(void *memory)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x8]
    ret
  }
}

// Forwards full byte-count word and GAME_SERVICE tag through current allocator slot0; returns raw EAX/RET4.
// R6GameService.dll @ 10006350 : native control/access order and raw ABI retained.
void * __stdcall AllocateGameServiceBytes(uint byteCount)
{
  FMalloc *allocator = GMalloc;
  return allocator->Malloc(byteCount,reinterpret_cast<const TCHAR *>(R6GameServiceAddresses::WideTextGAMESERVICE));
}

// Forwards original memory/size words and GAME_SERVICE tag through allocator resize slot4; raw EAX/RET8.
// R6GameService.dll @ 10006370 : native control/access order and raw ABI retained.
void * __stdcall ResizeGameServiceBytes(void *memory,uint byteCount)
{
  FMalloc *allocator = GMalloc;
  return allocator->Realloc(
      memory,byteCount,reinterpret_cast<const TCHAR *>(R6GameServiceAddresses::WideTextGAMESERVICE));
}

// Loads imported allocator receiver/vtable then tail-forwards existing memory word to current release slot8.
// R6GameService.dll @ 10006390 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall TailFreeThroughGlobalAllocator(void *memory)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    jmp    DWORD PTR [edx+0x8]
  }
}

// Advances the live head before each cached CRT free call, then reloads it; retains raw EAX and dangling node links.
// R6GameService.dll @ 10007d50 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall FreeLinkedAllocations(void **head)
{
  __asm {
    push   esi
    mov    esi,ecx
    cmp    DWORD PTR [esi],0x0
    je     Branch14
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freeSlot
    nop
  Branch13:
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [eax]
    push   eax
    mov    DWORD PTR [esi],ecx
    call   edi
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    test   eax,eax
    jne    Branch13
    pop    edi
  Branch14:
    pop    esi
    ret
  }
}

// Clears three consecutive words in order, returning the receiver in EAX and zero in ECX.
// R6GameService.dll @ 10007d80 : complete native operations and raw ABI; descriptive helper name.
undefined4 * __fastcall InitializeThreeWords(undefined4 *words)
{
  words[0] = 0;
  words[1] = 0;
  words[2] = 0;
  return words;
}

// Passes a nonnull held object as one callee-cleaned word through slot8, with its vtable in ECX; null returns zero.
// R6GameService.dll @ 10007ea0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall CallThirdSlotForFirstWordObject(int *ownerWords)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    test   eax,eax
    je     Branch15
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x8]
  Branch15:
    ret
  }
}

// Clears the receiver first word and returns that receiver in EAX.
// R6GameService.dll @ 1000aaf0 : complete native operations and raw ABI; descriptive helper name.
undefined4 * __fastcall ClearFirstWord(undefined4 *address)
{
  *address = 0;
  return address;
}

// Tail-forwards the original caller frame to the imported Engine shutdown query; no recursive local call.
// R6GameService.dll @ 10014a10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) int __cdecl getGameShutDown(void)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::Engine__getGameShutDownSlot
  }
}

// Return without effects, preserving EAX and discarding one argument word.
// R6GameService.dll @ 1005c140 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __stdcall shared_native_NoOp(uint ignored)
{
  __asm {
    ret    0x4
  }
}

// Genuine shared empty callback: pop return address and discard12 words, preserving registers/flags.
// No argument/context access or resource action; one canonical body serves every class-facing slot.
// R6GameService.dll @ 100328a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall NoOpServiceCallbackRet30(
    uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,uint word9,uint word10,
    uint word11,uint word12)
{
  __asm {
    ret    0x30
  }
}

// Genuine shared empty callback: pop return address and discard5 words, preserving registers/flags.
// No argument/context access or resource action; one canonical body serves every class-facing slot.
// R6GameService.dll @ 10032920 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall NoOpServiceCallbackRet14(
    uint word1,uint word2,uint word3,uint word4,uint word5)
{
  __asm {
    ret    0x14
  }
}

// Genuine shared empty callback: pop return address and discard4 words, preserving registers/flags.
// No argument/context access or resource action; one canonical body serves every class-facing slot.
// R6GameService.dll @ 10032930 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall NoOpServiceCallbackRet10(uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    ret    0x10
  }
}

// Shared saved-raw allocation guard: selected parents4c450,4c540 and4c9e0 use original ENTRY ESP-10.

// Free CURRENT raw allocation at inherited original ENTRY ESP-10 through the genuine allocator tail.
// R6GameService.dll @ 10068220 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl shared_nativeSharedLifetimeUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x10]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}


// Select the shared one-state raw-allocation guard and tail current CRT frame dispatch.
// R6GameService.dll @ 1006822a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectConnectionAllocationEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::shared_nativeSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}


// R6GameService.dll data @ 10082c08: shared connection raw-allocation map or FuncInfo.
const R6GameServiceNative::UnwindEntry shared_nativeSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::shared_nativeSharedLifetimeUnwind1},
};

// R6GameService.dll data @ 10082c10: shared connection raw-allocation map or FuncInfo.
// R6GameService.dll data @ 10082c08 : native storage identity retained.
const R6GameServiceNative::FuncInfo shared_nativeSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::shared_nativeSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clDataRefVTable
// R6GameService.dll data @ 10076ad4 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clDataRefVTableRecord {
  R6GameServiceNative::Address DeleteTrivialScalarDescriptor; // +0x00
  R6GameServiceNative::Address ForwardDataPayloadVirtual; // +0x04
  R6GameServiceNative::Address data_virtual_support_ForwardDataPayloadVirtual; // +0x08
  R6GameServiceNative::Address data_virtual_support_ForwardDataPayloadVirtual3; // +0x0c
  R6GameServiceNative::Address data_virtual_support_ForwardDataPayloadVirtual2; // +0x10
  R6GameServiceNative::Address data_virtual_support_ForwardDataPayloadVirtual4; // +0x14
};
const clDataRefVTableRecord clDataRefVTable = {
  R6GameServiceAddresses::DeleteTrivialScalarDescriptor,
  R6GameServiceAddresses::ForwardDataPayloadVirtual,
  R6GameServiceAddresses::data_virtual_support_ForwardDataPayloadVirtual,
  R6GameServiceAddresses::data_virtual_support_ForwardDataPayloadVirtual3,
  R6GameServiceAddresses::data_virtual_support_ForwardDataPayloadVirtual2,
  R6GameServiceAddresses::data_virtual_support_ForwardDataPayloadVirtual4,
};

// Native virtual-table prefix: CGSXorVTable
// R6GameService.dll data @ 10077918 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CGSXorVTableRecord {
  R6GameServiceNative::Address DeleteExtallocBaseObject; // +0x00
};
const CGSXorVTableRecord CGSXorVTable = {R6GameServiceAddresses::DeleteExtallocBaseObject};
