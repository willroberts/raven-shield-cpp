#include "native_addresses.h"
#include "native_records.h"

// Identified GSDataContainer::CDataContainer: table10075c3c/COL10078784/type1008c714.

// Initializes the36-byte container and optional16-byte tree wrapper with an unchecked24-byte sentinel allocation.
// Preserves padding and copies an uninitialized local byte into the wrapper tag, with no constructor unwind frame.
// R6GameService.dll @ 100189a0 : native control/access order and raw ABI retained.
__declspec(naked) undefined4 * __fastcall InitializeSerializedByteStore(undefined4 *owner)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    push   0x10
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [edi+0x8],ebx
    mov    DWORD PTR [edi+0xc],ebx
    mov    BYTE PTR [edi+0x10],bl
    mov    DWORD PTR [edi+0x14],ebx
    mov    DWORD PTR [edi+0x18],ebx
    mov    DWORD PTR [edi+0x1c],ebx
    mov    BYTE PTR [edi+0x20],bl
    mov    DWORD PTR [edi],R6GameServiceAddresses::CDataContainer_GSDataContainerVTable
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    cmp    esi,ebx
    je     Branch1
    push   0x18
    mov    DWORD PTR [esi+0xc],0x10075c30
    mov    DWORD PTR [esi],ebx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    cl,BYTE PTR [esp+0xf]
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],ebx
    mov    BYTE PTR [esi+0x8],cl
    mov    BYTE PTR [eax],bl
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+0x4],ebx
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0x8],eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],esi
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  Branch1:
    mov    DWORD PTR [edi+0x4],ebx
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  }
}

// Destroys the container, reloads the low deletion flag afterward and optionally frees it, returning cached owner.
// R6GameService.dll @ 10018a20 : native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DestroySerializedByteStore(void *owner,uint flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroySerializedByteStoreContents
    test   BYTE PTR [esp+0x8],0x1
    je     Branch2
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Installs the container table, resets payloads, then reloads and destroys the current tree wrapper.
// Header/map/buffer fields remain dangling on release; raw reset/free EAX is retained, with no outer guard.
// R6GameService.dll @ 10018a40 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroySerializedByteStoreContents(void *owner)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esi],R6GameServiceAddresses::CDataContainer_GSDataContainerVTable
    call   R6GameServiceAddresses::ResetSerializedByteStore
    mov    esi,DWORD PTR [esi+0x4]
    test   esi,esi
    je     Branch3
    mov    ecx,esi
    call   R6GameServiceAddresses::DestroyStoredValueTree
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    pop    esi
    ret
  }
}

// Requires a nonnull wrapper, resets both buffers then payload/node storage, and returns the native status word.
// R6GameService.dll @ 10018b00 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetSerializedByteStore(int storeAddress)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch4
    mov    eax,0x82135001
    pop    esi
    ret
  Branch4:
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    mov    ecx,esi
    call   R6GameServiceAddresses::ClearStoreValueTree
    mov    eax,0x2130000
    pop    esi
    ret
  }
}

// Releases the current+8 buffer, then clears its slot/length and flags+10/+20, preserving surrounding padding.
// R6GameService.dll @ 1001cfa0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetStoreBufferAt08(int storeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,ebx
    je     Branch5
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x8],ebx
  Branch5:
    mov    DWORD PTR [esi+0xc],ebx
    mov    BYTE PTR [esi+0x10],bl
    mov    BYTE PTR [esi+0x20],bl
    pop    esi
    mov    eax,0x2130000
    pop    ebx
    ret
  }
}

// Releases the current+14 buffer, then clears its slot/two lengths and flag+20; free failure precedes those clears.
// R6GameService.dll @ 1001cfd0 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ResetStoreBufferAt14(int storeAddress)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ebx,ebx
    mov    eax,DWORD PTR [esi+0x14]
    cmp    eax,ebx
    je     Branch6
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x14],ebx
  Branch6:
    mov    DWORD PTR [esi+0x18],ebx
    mov    DWORD PTR [esi+0x1c],ebx
    mov    BYTE PTR [esi+0x20],bl
    pop    esi
    mov    eax,0x2130000
    pop    ebx
    ret
  }
}

// Walks payloads in order, releasing each optional+0c buffer and payload, then frees nodes and resets header/count.
// Successor/header/next/payload loads retain native timing; no outer exception guard or partial-progress repair exists.
// R6GameService.dll @ 1001d000 : native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall ClearStoreValueTree(int storeAddress)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,ecx
    push   esi
    xor    ebx,ebx
    push   edi
    mov    eax,DWORD PTR [ebp+0x4]
    mov    DWORD PTR [esp+0x10],ebp
    mov    eax,DWORD PTR [eax]
    mov    esi,DWORD PTR [eax+0x8]
    cmp    esi,eax
    je     Branch14
  Branch7:
    mov    edi,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [edi+0xc]
    cmp    eax,ebx
    je     Branch8
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch8:
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esi+0xc]
    mov    eax,esi
    cmp    ecx,ebx
    je     Branch10
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebx
    je     Branch13
  Branch9:
    mov    eax,ecx
    mov    ecx,DWORD PTR [eax+0x8]
    cmp    ecx,ebx
    jne    Branch9
    jmp    Branch13
  Branch10:
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    esi,DWORD PTR [ecx+0xc]
    jne    Branch12
  Branch11:
    mov    eax,ecx
    mov    ecx,DWORD PTR [ecx+0x4]
    cmp    eax,DWORD PTR [ecx+0xc]
    je     Branch11
  Branch12:
    cmp    DWORD PTR [eax+0xc],ecx
    je     Branch13
    mov    eax,ecx
  Branch13:
    mov    ecx,DWORD PTR [ebp+0x4]
    mov    esi,eax
    cmp    eax,DWORD PTR [ecx]
    jne    Branch7
  Branch14:
    mov    edi,DWORD PTR [ebp+0x4]
    cmp    DWORD PTR [edi+0x4],ebx
    je     Branch17
    mov    edx,DWORD PTR [edi]
    mov    esi,DWORD PTR [edx+0x4]
    cmp    esi,ebx
    je     Branch16
  Branch15:
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,edi
    push   eax
    call   R6GameServiceAddresses::ReleaseOrderedTreeBranches
    mov    ebp,DWORD PTR [esi+0x8]
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    cmp    ebp,ebx
    mov    esi,ebp
    jne    Branch15
    mov    ebp,DWORD PTR [esp+0x10]
  Branch16:
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0x8],eax
    mov    ecx,DWORD PTR [edi]
    mov    DWORD PTR [ecx+0x4],ebx
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [eax+0xc],eax
    mov    DWORD PTR [edi+0x4],ebx
  Branch17:
    pop    edi
    mov    BYTE PTR [ebp+0x10],bl
    pop    esi
    pop    ebp
    mov    eax,0x2130000
    pop    ebx
    pop    ecx
    ret
  }
}

// Ensures primary serialization, then returns the current primary or prepared alternate pointer.
// Mode reloads after serialization; helper failures use signed EAX and all successful field loads remain late.
// R6GameService.dll @ 10018d30 : native control/access order and raw ABI retained.
__declspec(naked) byte * __thiscall GetStoredBytesPointer(void *owner,uint mode)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch18
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch18:
    mov    al,BYTE PTR [esi+0x10]
    test   al,al
    jne    Branch19
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    mov    ecx,esi
    call   R6GameServiceAddresses::SerializeStoredValuesToBuffer
    test   eax,eax
    jge    Branch19
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch19:
    mov    al,BYTE PTR [esp+0x8]
    test   al,al
    je     Branch21
    mov    ecx,esi
    call   R6GameServiceAddresses::PrepareAlternateStoreBuffer
    test   eax,eax
    jge    Branch20
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch20:
    mov    eax,DWORD PTR [esi+0x1c]
    pop    esi
    ret    0x4
  Branch21:
    mov    eax,DWORD PTR [esi+0x8]
    pop    esi
    ret    0x4
  }
}

// Ensures primary serialization, then returns its length or alternate size18-pointer1c+base14 modulo32.
// Only the low mode byte selects alternate storage; no pointer/extent normalization is added.
// R6GameService.dll @ 10018d90 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall GetStoredBytesLength(void *owner,uint mode)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch22
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch22:
    mov    al,BYTE PTR [esi+0x10]
    test   al,al
    jne    Branch23
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    mov    ecx,esi
    call   R6GameServiceAddresses::SerializeStoredValuesToBuffer
    test   eax,eax
    jge    Branch23
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch23:
    mov    al,BYTE PTR [esp+0x8]
    test   al,al
    je     Branch25
    mov    ecx,esi
    call   R6GameServiceAddresses::PrepareAlternateStoreBuffer
    test   eax,eax
    jge    Branch24
    xor    eax,eax
    pop    esi
    ret    0x4
  Branch24:
    mov    eax,DWORD PTR [esi+0x18]
    mov    edx,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [esi+0x14]
    sub    eax,edx
    add    eax,ecx
    pop    esi
    ret    0x4
  Branch25:
    mov    eax,DWORD PTR [esi+0xc]
    pop    esi
    ret    0x4
  }
}

// Returns zero for an absent wrapper, otherwise its unmodified32-bit entry count.
// R6GameService.dll @ 10018df0 : native control/access order and raw ABI retained.
uint __fastcall GetStoredValueCount(void *owner)
{
  uint storage = static_cast<const uint *>(owner)[1];
  return storage == 0 ? 0 : reinterpret_cast<const uint *>(storage)[1];
}

// Finds a keyed payload, publishes optional type, checks unsigned capacity and copies forward DWORDs then bytes.
// Aliases may change size/source before copying and returned size after it; no copy occurs for insufficient capacity.
// R6GameService.dll @ 10018e00 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadStoredValue(void *owner,uint key,void *destination,uint *bytes,uint *type)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    jne    Branch27
    pop    edi
    pop    esi
    mov    eax,0x82135001
    pop    ebx
    ret    0x10
  Branch27:
    mov    edi,DWORD PTR [esp+0x14]
    mov    ebx,DWORD PTR [esp+0x18]
    test   edi,edi
    je     Branch28
    test   ebx,ebx
    jne    Branch28
    pop    edi
    pop    esi
    mov    eax,0x82170057
    pop    ebx
    ret    0x10
  Branch28:
    lea    eax,[esp+0x10]
    push   eax
    call   R6GameServiceAddresses::OrderedTreeFind
    mov    ecx,DWORD PTR [esi+0x4]
    cmp    eax,DWORD PTR [ecx]
    jne    Branch29
    pop    edi
    pop    esi
    mov    eax,0x82136200
    pop    ebx
    ret    0x10
  Branch29:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [eax+0x14]
    test   ecx,ecx
    je     Branch30
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx],edx
  Branch30:
    test   ebx,ebx
    je     Branch33
    test   edi,edi
    je     Branch32
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [ebx]
    cmp    edx,ecx
    jae    Branch31
    pop    edi
    mov    DWORD PTR [ebx],ecx
    pop    esi
    mov    eax,0x2136201
    pop    ebx
    ret    0x10
  Branch31:
    mov    esi,DWORD PTR [eax+0xc]
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch32:
    mov    eax,DWORD PTR [eax+0x8]
    mov    DWORD PTR [ebx],eax
  Branch33:
    pop    edi
    pop    esi
    mov    eax,0x2130000
    pop    ebx
    ret    0x10
  }
}

// Forwards a four-byte local capacity and no type output to the reader, preserving raw status and restored ECX scratch.
// R6GameService.dll @ 10018ea0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadStoredWord(void *owner,uint key,void *destination)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0xc]
    lea    eax,[esp+0x0]
    push   0x0
    push   eax
    mov    eax,DWORD PTR [esp+0x10]
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x10],0x4
    call   R6GameServiceAddresses::ReadStoredValue
    pop    ecx
    ret    0x8
  }
}

// Forwards the current key/destination/size words with null type output, returning raw reader status.
// R6GameService.dll @ 10018ed0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReadStoredBytes(void *owner,uint key,void *destination,uint *bytes)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    mov    edx,DWORD PTR [esp+0x8]
    push   0x0
    push   eax
    mov    eax,DWORD PTR [esp+0xc]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReadStoredValue
    ret    0xc
  }
}

// Scans the captured ANSI pointer and forwards its size INCLUDING NUL with type1; key loads after the scan.
// No null/text-length guard is added; writer status and native pointer/count words remain raw.
// R6GameService.dll @ 100190b0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteStoredAnsiText(void *owner,uint key,const char *text)
{
  __asm {
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edx,ecx
    mov    edi,esi
    or     ecx,0xffffffff
    xor    eax,eax
    push   0x1
    repnz  scas al,BYTE PTR es:[edi]
    mov    eax,DWORD PTR [esp+0x10]
    not    ecx
    push   ecx
    push   esi
    push   eax
    mov    ecx,edx
    call   R6GameServiceAddresses::WriteStoredValue
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Forwards the original value-argument address and four-byte size/type3 to the writer, retaining raw status.
// R6GameService.dll @ 100190e0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteStoredWordType3(void *owner,uint key,uint value)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   0x3
    lea    eax,[esp+0xc]
    push   0x4
    push   eax
    push   edx
    call   R6GameServiceAddresses::WriteStoredValue
    ret    0x8
  }
}

// Forwards the original value-argument address and four-byte size/type5 to the writer, retaining raw status.
// R6GameService.dll @ 10019100 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteStoredWordType5(void *owner,uint key,uint value)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   0x5
    lea    eax,[esp+0xc]
    push   0x4
    push   eax
    push   edx
    call   R6GameServiceAddresses::WriteStoredValue
    ret    0x8
  }
}

// Releases payload/node storage, decrements the current wrapper count and invalidates primary bytes.
// Wrapper/count reload after payload release and unsigned underflow remain native; no rollback or local guard exists.
// R6GameService.dll @ 10018ef0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RemoveStoredValue(void *owner,uint key)
{
  __asm {
    push   ebx
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x4]
    test   ecx,ecx
    jne    Branch34
    pop    edi
    mov    eax,0x82135001
    pop    ebx
    ret    0x4
  Branch34:
    lea    eax,[esp+0xc]
    push   eax
    call   R6GameServiceAddresses::OrderedTreeFind
    mov    ecx,DWORD PTR [edi+0x4]
    mov    ebx,eax
    cmp    ebx,DWORD PTR [ecx]
    jne    Branch35
    pop    edi
    mov    eax,0x82136200
    pop    ebx
    ret    0x4
  Branch35:
    push   esi
    mov    esi,DWORD PTR [ebx+0x14]
    mov    eax,DWORD PTR [esi+0xc]
    test   eax,eax
    je     Branch36
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch36:
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    esi,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [esi]
    lea    edx,[eax+0xc]
    lea    ecx,[eax+0x8]
    push   edx
    add    eax,0x4
    push   ecx
    push   eax
    push   ebx
    call   R6GameServiceAddresses::RemoveOrderedTreeNode
    add    esp,0x10
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esi+0x4]
    dec    eax
    mov    DWORD PTR [esi+0x4],eax
    mov    BYTE PTR [edi+0x10],0x0
    pop    esi
    pop    edi
    mov    eax,0x2130000
    pop    ebx
    ret    0x4
  }
}

// Erases any existing key before allocating/copying a replacement record and inserting or replacing its tree payload.
// Ignores erase status; retains late key/type, cached source/count, forward copies and native failure ownership.
// R6GameService.dll @ 10018f70 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteStoredValue(void *owner,uint key,void *source,uint byteCount,uint type)
{
  __asm {
    sub    esp,0x8
    mov    eax,DWORD PTR [ecx+0x4]
    push   ebx
    push   ebp
    push   esi
    test   eax,eax
    push   edi
    mov    DWORD PTR [esp+0x10],ecx
    jne    Branch37
    mov    eax,0x82135001
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x10
  Branch37:
    mov    esi,DWORD PTR [esp+0x20]
    test   esi,esi
    je     Branch42
    mov    ebx,DWORD PTR [esp+0x24]
    test   ebx,ebx
    je     Branch42
    mov    eax,DWORD PTR [esp+0x1c]
    push   eax
    call   R6GameServiceAddresses::RemoveStoredValue
    push   0x10
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    test   ebp,ebp
    jne    Branch38
    mov    eax,0x8217000e
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x10
  Branch38:
    mov    edx,ebp
    xor    ecx,ecx
    push   ebx
    mov    DWORD PTR [edx],ecx
    mov    DWORD PTR [edx+0x4],ecx
    mov    DWORD PTR [edx+0x8],ecx
    mov    DWORD PTR [edx+0xc],ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [ebp+0xc],eax
    jne    Branch39
    push   ebp
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,0x8217000e
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x10
  Branch39:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [ebp+0x0],ecx
    mov    ecx,ebx
    mov    edi,eax
    mov    eax,ecx
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0x4],edx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    edi,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ebp+0x8],ebx
    lea    ecx,[esp+0x1c]
    mov    esi,DWORD PTR [edi+0x4]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::OrderedTreeLowerBound
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x20],eax
    cmp    eax,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    je     Branch40
    cmp    ecx,DWORD PTR [eax+0x10]
    jae    Branch41
  Branch40:
    lea    edx,[esp+0x20]
    mov    DWORD PTR [esp+0x10],ecx
    push   edx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::CopyFirstWord
    lea    eax,[esp+0x10]
    lea    edx,[esp+0x24]
    push   eax
    push   ecx
    mov    ecx,esp
    push   edx
    call   R6GameServiceAddresses::CopyFirstWord
    lea    eax,[esp+0x30]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::InsertOrFindOrderedTreeNode
    mov    eax,DWORD PTR [esp+0x28]
  Branch41:
    mov    DWORD PTR [eax+0x14],ebp
    mov    BYTE PTR [edi+0x10],0x0
    mov    eax,0x2130000
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x10
  Branch42:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x82170057
    pop    ebx
    add    esp,0x8
    ret    0x10
  }
}

// Resets the store, inflates tagE or copies raw serialized bytes, then imports and resets again only on import failure.
// Preserves cached input, mutable header count/argument scratch and raw negative helper statuses.
// R6GameService.dll @ 10018b30 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall LoadSerializedByteStore(void *owner,byte *input)
{
  __asm {
    sub    esp,0x8
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    eax,DWORD PTR [ebx+0x4]
    test   eax,eax
    jne    Branch43
    pop    esi
    mov    eax,0x82135001
    pop    ebx
    add    esp,0x8
    ret    0x4
  Branch43:
    mov    esi,DWORD PTR [esp+0x14]
    test   esi,esi
    jne    Branch44
    pop    esi
    mov    eax,0x82170057
    pop    ebx
    add    esp,0x8
    ret    0x4
  Branch44:
    mov    ecx,ebx
    call   R6GameServiceAddresses::ResetSerializedByteStore
    push   esi
    mov    ecx,ebx
    call   R6GameServiceAddresses::CheckStoreBlobTagE
    test   eax,0x8000ffff
    jne    Branch45
    push   esi
    mov    ecx,ebx
    call   R6GameServiceAddresses::InflateTaggedStoreBytes
    test   eax,eax
    jge    Branch47
    pop    esi
    pop    ebx
    add    esp,0x8
    ret    0x4
  Branch45:
    push   0x0
    push   0x0
    lea    eax,[esp+0x10]
    push   0x0
    lea    ecx,[esp+0x20]
    push   eax
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    mov    ecx,ebx
    mov    DWORD PTR [esp+0x24],esi
    mov    BYTE PTR [esp+0x2c],0x1
    mov    DWORD PTR [esp+0x20],0x0
    call   R6GameServiceAddresses::DecodeSerializedStoreHeader
    test   eax,eax
    jl     Branch49
    mov    eax,DWORD PTR [esp+0x8]
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [ebx+0x8],eax
    jne    Branch46
    pop    esi
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0x8
    ret    0x4
  Branch46:
    mov    ecx,DWORD PTR [esp+0x8]
    push   edi
    mov    DWORD PTR [ebx+0xc],ecx
    mov    edx,ecx
    mov    edi,eax
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
  Branch47:
    mov    ecx,ebx
    call   R6GameServiceAddresses::ImportSerializedStoreValues
    mov    esi,eax
    test   esi,esi
    jge    Branch48
    mov    ecx,ebx
    call   R6GameServiceAddresses::ResetSerializedByteStore
    mov    eax,esi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret    0x4
  Branch48:
    mov    eax,0x2130000
  Branch49:
    pop    esi
    pop    ebx
    add    esp,0x8
    ret    0x4
  }
}

// Clears/initializes a variant, prepares bytes, accesses an array and forward-copies current source fields.
// Array creation size precedes late mode/count reload; access failures leak the array and unaccess status is ignored.
// R6GameService.dll @ 10018c20 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CopyStoredBytesToVariant(void *owner,void *variant,uint mode)
{
  __asm {
    push   ebx
    push   ebp
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch50
    pop    esi
    pop    ebp
    mov    eax,0x82135001
    pop    ebx
    ret    0x8
  Branch50:
    mov    ebx,DWORD PTR [esp+0x10]
    test   ebx,ebx
    jne    Branch51
    pop    esi
    pop    ebp
    mov    eax,0x82170057
    pop    ebx
    ret    0x8
  Branch51:
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_VariantClearSlot
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_VariantInitSlot
    mov    al,BYTE PTR [esi+0x10]
    test   al,al
    jne    Branch52
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    mov    ecx,esi
    call   R6GameServiceAddresses::SerializeStoredValuesToBuffer
    test   eax,eax
    jl     Branch59
  Branch52:
    mov    al,BYTE PTR [esp+0x14]
    test   al,al
    je     Branch53
    mov    ecx,esi
    call   R6GameServiceAddresses::PrepareAlternateStoreBuffer
    test   eax,eax
    jl     Branch59
    mov    eax,DWORD PTR [esi+0x18]
    mov    edx,DWORD PTR [esi+0x1c]
    mov    ecx,DWORD PTR [esi+0x14]
    sub    eax,edx
    add    eax,ecx
    jmp    Branch54
  Branch53:
    mov    eax,DWORD PTR [esi+0xc]
  Branch54:
    push   eax
    push   0x0
    push   0x11
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SafeArrayCreateVectorSlot
    mov    ebp,eax
    test   ebp,ebp
    jne    Branch55
    pop    esi
    pop    ebp
    mov    eax,0x8217000e
    pop    ebx
    ret    0x8
  Branch55:
    lea    eax,[esp+0x10]
    mov    DWORD PTR [esp+0x10],0x0
    push   eax
    push   ebp
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SafeArrayAccessDataSlot
    test   eax,eax
    jge    Branch56
    pop    esi
    pop    ebp
    or     eax,0x2120000
    pop    ebx
    ret    0x8
  Branch56:
    mov    al,BYTE PTR [esp+0x14]
    push   edi
    test   al,al
    je     Branch57
    mov    ecx,DWORD PTR [esi+0x18]
    mov    edi,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [esi+0x1c]
    add    ecx,edi
    sub    ecx,eax
    mov    esi,eax
    jmp    Branch58
  Branch57:
    mov    ecx,DWORD PTR [esi+0xc]
    mov    esi,DWORD PTR [esi+0x8]
  Branch58:
    mov    edi,DWORD PTR [esp+0x14]
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    push   ebp
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SafeArrayUnaccessDataSlot
    mov    WORD PTR [ebx],0x2011
    mov    DWORD PTR [ebx+0x8],ebp
    mov    eax,0x2120000
    pop    edi
  Branch59:
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Decodes header/entries and writes wrapping keys, freeing each successful decoded payload before marking ready.
// Ignores header/writer status; accepts masked end status and resets other decode failures without another payload free.
// R6GameService.dll @ 1001c1b0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ImportSerializedStoreValues(void *owner)
{
  __asm {
    sub    esp,0x24
    push   ebp
    push   esi
    mov    esi,ecx
    push   edi
    xor    edi,edi
    mov    eax,DWORD PTR [esi+0x8]
    cmp    eax,edi
    jne    Branch60
    pop    edi
    pop    esi
    mov    eax,0x82134005
    pop    ebp
    add    esp,0x24
    ret
  Branch60:
    mov    DWORD PTR [esp+0x18],eax
    lea    eax,[esp+0x24]
    push   eax
    lea    ecx,[esp+0x14]
    push   edi
    lea    edx,[esp+0x34]
    push   ecx
    lea    eax,[esp+0x1b]
    push   edx
    lea    ecx,[esp+0x28]
    push   eax
    push   ecx
    mov    ecx,esi
    mov    BYTE PTR [esp+0x27],0x1
    mov    DWORD PTR [esp+0x44],edi
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0x28],edi
    call   R6GameServiceAddresses::DecodeSerializedStoreHeader
    mov    eax,DWORD PTR [esp+0x10]
    mov    DWORD PTR [esp+0x28],edi
    cmp    eax,edi
    mov    DWORD PTR [esp+0x14],edi
    mov    DWORD PTR [esp+0x20],edi
    mov    DWORD PTR [esp+0x1c],edi
    je     Branch63
  Branch61:
    mov    edx,DWORD PTR [esp+0x10]
    push   edi
    dec    edx
    lea    eax,[esp+0x24]
    mov    DWORD PTR [esp+0x14],edx
    lea    edx,[esp+0x20]
    push   edx
    lea    ecx,[esp+0x1c]
    push   eax
    lea    edx,[esp+0x34]
    push   ecx
    lea    eax,[esp+0x1f]
    push   edx
    lea    ecx,[esp+0x2c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::DecodeSerializedStoreEntry
    mov    ebp,eax
    cmp    ebp,edi
    jl     Branch64
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x28]
    push   eax
    mov    eax,DWORD PTR [esp+0x30]
    push   ecx
    add    eax,edx
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::WriteStoredValue
    mov    eax,DWORD PTR [esp+0x14]
    cmp    eax,edi
    je     Branch62
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esp+0x14],edi
  Branch62:
    cmp    DWORD PTR [esp+0x10],edi
    jne    Branch61
  Branch63:
    mov    edx,DWORD PTR [esp+0x2c]
    mov    BYTE PTR [esi+0x10],0x1
    mov    DWORD PTR [esi+0xc],edx
    pop    edi
    pop    esi
    mov    eax,0x2130001
    pop    ebp
    add    esp,0x24
    ret
  Branch64:
    mov    ecx,ebp
    and    ecx,0x8000ffff
    cmp    ecx,0x8000620d
    je     Branch63
    mov    ecx,esi
    call   R6GameServiceAddresses::ResetSerializedByteStore
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    add    esp,0x24
    ret
  }
}

// Builds alternate bytes by deflating, inflating back into primary storage and choosing raw or tagE output.
// Inflate status is ignored; selected errors reset, others retain allocation, and realloc results publish unchecked.
// Header width uses compressed+5; minimal length emission can leave a reserved byte untouched near width thresholds.
// R6GameService.dll @ 10019150 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PrepareAlternateStoreBuffer(void *owner)
{
  __asm {
    sub    esp,0x14
    push   ebx
    push   ebp
    mov    ebp,ecx
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch91
    mov    eax,DWORD PTR [ebp+0xc]
    lea    ebx,[ebp+0xc]
    test   eax,eax
    je     Branch91
    mov    al,BYTE PTR [ebp+0x20]
    test   al,al
    jne    Branch92
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    mov    ecx,DWORD PTR [ebx]
    mov    eax,0x10624dd3
    mul    ecx
    shr    edx,0x5
    lea    eax,[edx+ecx*1+0x11]
    push   eax
    mov    DWORD PTR [ebp+0x18],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [ebp+0x14],eax
    jne    Branch65
    pop    ebp
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0x14
    ret
  Branch65:
    mov    ecx,DWORD PTR [ebp+0x18]
    mov    edx,DWORD PTR [ebx]
    sub    ecx,0x5
    push   0x9
    mov    DWORD PTR [esp+0x14],ecx
    mov    ecx,DWORD PTR [ebp+0x8]
    push   edx
    lea    edx,[esp+0x18]
    push   ecx
    add    eax,0x5
    push   edx
    push   eax
    call   R6GameServiceAddresses::DeflateBuffer
    cmp    eax,0xfffffffb
    je     Branch90
    cmp    eax,0xfffffffc
    je     Branch89
    test   eax,eax
    je     Branch66
    pop    ebp
    mov    eax,0x8213ffff
    pop    ebx
    add    esp,0x14
    ret
  Branch66:
    mov    ecx,DWORD PTR [ebp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [ebp+0x8]
    push   esi
    push   edi
    add    ecx,0x5
    push   eax
    push   ecx
    push   ebx
    push   edx
    call   R6GameServiceAddresses::InflateBuffer
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [esp+0x18]
    cmp    ecx,eax
    jbe    Branch67
    push   eax
    mov    eax,DWORD PTR [ebp+0x14]
    push   eax
    call   R6GameServiceAddresses::ResizeGameServiceBytes
    mov    ecx,DWORD PTR [ebx]
    mov    esi,DWORD PTR [ebp+0x8]
    mov    edx,ecx
    mov    edi,eax
    shr    ecx,0x2
    mov    DWORD PTR [ebp+0x14],eax
    mov    DWORD PTR [ebp+0x1c],eax
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    eax,DWORD PTR [ebx]
    pop    edi
    mov    DWORD PTR [ebp+0x18],eax
    pop    esi
    mov    BYTE PTR [ebp+0x20],0x1
    pop    ebp
    mov    eax,0x2130000
    pop    ebx
    add    esp,0x14
    ret
  Branch67:
    lea    eax,[ecx+0x5]
    cmp    eax,0xff
    mov    DWORD PTR [ebp+0x18],eax
    ja     Branch68
    mov    ebx,0x1
    jmp    Branch70
  Branch68:
    cmp    eax,0xffff
    ja     Branch69
    mov    ebx,0x2
    jmp    Branch70
  Branch69:
    mov    ecx,0xffffff
    cmp    ecx,eax
    sbb    ebx,ebx
    neg    ebx
    add    ebx,0x3
  Branch70:
    mov    edx,DWORD PTR [ebp+0x14]
    mov    BYTE PTR [esp+0x13],0x1
    sub    edx,ebx
    xor    esi,esi
    mov    DWORD PTR [esp+0x1c],ebx
    lea    eax,[edx+0x4]
    mov    DWORD PTR [ebp+0x1c],eax
    mov    DWORD PTR [esp+0x14],eax
    mov    dl,BYTE PTR [eax]
    and    dl,0xf0
    mov    BYTE PTR [eax],dl
    mov    eax,DWORD PTR [esp+0x14]
    mov    cl,BYTE PTR [eax]
    or     cl,0xe
    mov    BYTE PTR [eax],cl
    mov    al,BYTE PTR [esp+0x13]
    mov    cl,al
    shr    cl,1
    je     Branch72
  Branch71:
    inc    esi
    shr    cl,1
    jne    Branch71
  Branch72:
    mov    edx,0x7
    sub    edx,esi
    cmp    edx,0x4
    jae    Branch73
    mov    edi,DWORD PTR [esp+0x14]
    mov    ecx,0x3
    inc    edi
    sub    ecx,edx
    mov    al,0x1
    mov    DWORD PTR [esp+0x14],edi
    shl    al,cl
    jmp    Branch74
  Branch73:
    shl    al,0x4
  Branch74:
    mov    BYTE PTR [esp+0x13],al
    xor    ecx,ecx
    shr    al,1
    je     Branch76
  Branch75:
    inc    ecx
    shr    al,1
    jne    Branch75
  Branch76:
    mov    esi,DWORD PTR [esp+0x14]
    mov    al,0x3
    shl    al,cl
    mov    dl,BYTE PTR [esi]
    not    al
    and    dl,al
    mov    BYTE PTR [esi],dl
    mov    eax,DWORD PTR [esp+0x14]
    xor    dl,dl
    shl    dl,cl
    or     BYTE PTR [eax],dl
    test   ecx,ecx
    je     Branch77
    mov    eax,0x8
    mov    esi,DWORD PTR [esp+0x14]
    sub    eax,ecx
    mov    dl,0x3
    mov    cl,al
    shr    dl,cl
    mov    cl,BYTE PTR [esi+0x1]
    not    dl
    and    cl,dl
    mov    BYTE PTR [esi+0x1],cl
    mov    edx,DWORD PTR [esp+0x14]
    xor    ecx,ecx
    mov    DWORD PTR [esp+0x20],ecx
    mov    ecx,eax
    mov    eax,DWORD PTR [esp+0x20]
    sar    eax,cl
    or     BYTE PTR [edx+0x1],al
  Branch77:
    mov    dl,BYTE PTR [esp+0x13]
    xor    ecx,ecx
    mov    al,dl
    shr    al,1
    je     Branch79
  Branch78:
    inc    ecx
    shr    al,1
    jne    Branch78
  Branch79:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch80
    mov    esi,DWORD PTR [esp+0x14]
    mov    ecx,0x1
    inc    esi
    sub    ecx,eax
    mov    dl,0x1
    mov    DWORD PTR [esp+0x14],esi
    shl    dl,cl
    jmp    Branch81
  Branch80:
    shl    dl,0x2
  Branch81:
    mov    al,bl
    mov    BYTE PTR [esp+0x13],dl
    dec    al
    xor    esi,esi
    shr    dl,1
    je     Branch83
  Branch82:
    inc    esi
    shr    dl,1
    jne    Branch82
  Branch83:
    mov    edi,DWORD PTR [esp+0x14]
    mov    dl,0x3
    mov    ecx,esi
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    not    dl
    and    cl,dl
    mov    dl,al
    mov    BYTE PTR [edi],cl
    mov    ecx,esi
    shl    dl,cl
    mov    ecx,DWORD PTR [esp+0x14]
    or     BYTE PTR [ecx],dl
    test   esi,esi
    je     Branch84
    mov    edx,0x8
    mov    bl,0x3
    sub    edx,esi
    mov    esi,DWORD PTR [esp+0x14]
    mov    cl,dl
    shr    bl,cl
    mov    cl,BYTE PTR [esi+0x1]
    not    bl
    and    cl,bl
    mov    ebx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esi+0x1],cl
    mov    esi,DWORD PTR [esp+0x14]
    mov    cl,dl
    shr    al,cl
    or     BYTE PTR [esi+0x1],al
  Branch84:
    mov    al,BYTE PTR [esp+0x13]
    xor    ecx,ecx
    shr    al,1
    je     Branch86
  Branch85:
    inc    ecx
    shr    al,1
    jne    Branch85
  Branch86:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch87
    mov    edi,DWORD PTR [esp+0x14]
    mov    ecx,0x1
    sub    ecx,eax
    inc    edi
    mov    al,0x1
    mov    DWORD PTR [esp+0x14],edi
    shl    al,cl
    jmp    Branch88
  Branch87:
    mov    al,BYTE PTR [esp+0x13]
    shl    al,0x2
  Branch88:
    mov    BYTE PTR [esp+0x13],al
    mov    eax,DWORD PTR [esp+0x18]
    push   0x1
    push   0x0
    lea    ecx,[eax+0x5]
    lea    edx,[ebx+eax*1+0x1]
    mov    DWORD PTR [ebp+0x18],ecx
    push   0x0
    lea    eax,[esp+0x1f]
    push   edx
    lea    ecx,[esp+0x24]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteStoreInteger
    mov    edx,DWORD PTR [ebp+0x18]
    mov    eax,DWORD PTR [ebp+0x14]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ResizeGameServiceBytes
    mov    DWORD PTR [ebp+0x14],eax
    sub    eax,ebx
    add    eax,0x4
    pop    edi
    mov    DWORD PTR [ebp+0x1c],eax
    pop    esi
    mov    BYTE PTR [ebp+0x20],0x1
    pop    ebp
    mov    eax,0x2130000
    pop    ebx
    add    esp,0x14
    ret
  Branch89:
    mov    ecx,ebp
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    pop    ebp
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0x14
    ret
  Branch90:
    mov    ecx,ebp
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    pop    ebp
    mov    eax,0x8213ffff
    pop    ebx
    add    esp,0x14
    ret
  Branch91:
    mov    ecx,ebp
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    mov    BYTE PTR [ebp+0x20],0x1
  Branch92:
    pop    ebp
    mov    eax,0x2130000
    pop    ebx
    add    esp,0x14
    ret
  }
}

// Decodes tagE length, inflates into three times the compressed extent and retains a copy of original encoded bytes.
// Status minus5 retries the SAME capacity without a bound; other failure/reset/publication paths remain distinct.
// R6GameService.dll @ 100199f0 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InflateTaggedStoreBytes(void *owner,byte *input)
{
  __asm {
    sub    esp,0x14
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x24]
    xor    ebp,ebp
    push   edi
    cmp    esi,ebp
    mov    ebx,ecx
    jne    Branch93
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x82134003
    pop    ebx
    add    esp,0x14
    ret    0x4
  Branch93:
    mov    DWORD PTR [esp+0x14],esi
    mov    BYTE PTR [esp+0x13],0x1
    mov    al,BYTE PTR [esi]
    and    al,0xf
    cmp    al,0xe
    je     Branch94
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x82136202
    pop    ebx
    add    esp,0x14
    ret    0x4
  Branch94:
    mov    DWORD PTR [esp+0x14],esi
    mov    BYTE PTR [esp+0x13],0x40
    mov    DWORD PTR [esp+0x20],ebp
    mov    al,BYTE PTR [esi]
    test   al,0x40
    seta   dl
    mov    DWORD PTR [esp+0x18],ebp
    xor    eax,eax
    mov    cl,0x20
  Branch95:
    inc    eax
    shr    cl,1
    jne    Branch95
    mov    ecx,0x7
    sub    ecx,eax
    cmp    ecx,0x1
    jae    Branch96
    neg    ecx
    mov    al,0x1
    lea    edi,[esi+0x1]
    shl    al,cl
    jmp    Branch97
  Branch96:
    mov    edi,esi
    mov    al,0x80
  Branch97:
    mov    DWORD PTR [esp+0x14],edi
    mov    BYTE PTR [esp+0x13],al
    test   BYTE PTR [edi],al
    seta   cl
    add    cl,cl
    or     dl,cl
    mov    cl,al
    mov    BYTE PTR [esp+0x1c],dl
    xor    edx,edx
    shr    cl,1
    je     Branch99
  Branch98:
    inc    edx
    shr    cl,1
    jne    Branch98
  Branch99:
    mov    ecx,0x7
    sub    ecx,edx
    cmp    ecx,0x1
    jae    Branch100
    neg    ecx
    mov    dl,0x1
    inc    edi
    shl    dl,cl
    mov    DWORD PTR [esp+0x14],edi
    mov    BYTE PTR [esp+0x13],dl
    jmp    Branch101
  Branch100:
    add    al,al
    mov    BYTE PTR [esp+0x13],al
  Branch101:
    mov    eax,DWORD PTR [esp+0x1c]
    and    eax,0xff
    cmp    eax,0x3
    ja     Branch104
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GStoreInflateTargets]
    lea    eax,[esp+0x13]
    lea    ecx,[esp+0x14]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    lea    edx,[esp+0x13]
    mov    edi,eax
    push   0x8
    lea    eax,[esp+0x18]
    push   edx
    push   eax
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    DWORD PTR [esp+0x18],edi
    jmp    Branch104
    xor    edi,edi
  Branch102:
    lea    ecx,[esp+0x13]
    lea    edx,[esp+0x14]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,edi
    shl    eax,cl
    push   0x8
    lea    ecx,[esp+0x18]
    or     ebp,eax
    lea    eax,[esp+0x17]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    edi,0x8
    mov    DWORD PTR [esp+0x20],0x10
    cmp    edi,0x10
    jb     Branch102
    mov    esi,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esp+0x18],ebp
    jmp    Branch104
    xor    edi,edi
  Branch103:
    lea    edx,[esp+0x13]
    lea    eax,[esp+0x14]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,edi
    shl    eax,cl
    lea    ecx,[esp+0x13]
    push   0x8
    lea    edx,[esp+0x18]
    push   ecx
    push   edx
    or     ebp,eax
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    edi,0x8
    mov    DWORD PTR [esp+0x20],0x18
    cmp    edi,0x18
    jb     Branch103
    mov    esi,DWORD PTR [esp+0x28]
    mov    DWORD PTR [esp+0x18],ebp
    jmp    Branch104
    lea    eax,[esp+0x20]
    push   0x1
    push   eax
    lea    ecx,[esp+0x1b]
    push   0x4
    lea    edx,[esp+0x20]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    DWORD PTR [esp+0x18],eax
  Branch104:
    mov    edi,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    sub    edi,ecx
    mov    DWORD PTR [esp+0x1c],0x0
    add    edi,esi
    lea    ebp,[edi+edi*2]
  Branch105:
    mov    ecx,ebx
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    push   ebp
    mov    DWORD PTR [ebx+0xc],ebp
    mov    DWORD PTR [esp+0x20],ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [ebx+0x8],eax
    je     Branch106
    mov    ecx,DWORD PTR [esp+0x14]
    push   edi
    lea    edx,[esp+0x20]
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::InflateBuffer
    lea    ecx,[eax+0x5]
    cmp    ecx,0x5
    ja     Branch108
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::CDataContainerGStoreInflateTargets]
    test   eax,eax
    jne    Branch105
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [ebx+0x8]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::ResizeGameServiceBytes
    mov    edx,DWORD PTR [esp+0x1c]
    mov    ecx,ebx
    mov    DWORD PTR [ebx+0x8],eax
    mov    DWORD PTR [ebx+0xc],edx
    call   R6GameServiceAddresses::ResetStoreBufferAt14
    mov    eax,DWORD PTR [esp+0x18]
    push   eax
    mov    DWORD PTR [ebx+0x18],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [ebx+0x14],eax
    mov    DWORD PTR [ebx+0x1c],eax
    jne    Branch107
  Branch106:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0x14
    ret    0x4
    mov    ecx,ebx
    call   R6GameServiceAddresses::ResetStoreBufferAt08
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0x14
    ret    0x4
  Branch107:
    mov    ecx,DWORD PTR [ebx+0x18]
    mov    edi,eax
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    mov    eax,0x2130000
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    mov    BYTE PTR [ebx+0x20],0x1
    pop    ebp
    pop    ebx
    add    esp,0x14
    ret    0x4
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x82170057
    pop    ebx
    add    esp,0x14
    ret    0x4
  Branch108:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8213ffff
    pop    ebx
    add    esp,0x14
    ret    0x4
  }
}

// R6GameService.dll data @ 10019ca0 : tagged inflate dispatch.
const uint GStoreInflateTargets[4] = {R6GameServiceAddresses::GStoreInflateTargetsCase1,R6GameServiceAddresses::GStoreInflateTargetsCase2,R6GameServiceAddresses::GStoreInflateTargetsCase3,R6GameServiceAddresses::GStoreInflateTargetsCase4};

// R6GameService.dll data @ 10019cb0 : tagged inflate dispatch.
const uint CDataContainerGStoreInflateTargets[6] = {R6GameServiceAddresses::CDataContainerGStoreInflateTargetsCase1,R6GameServiceAddresses::CDataContainerGStoreInflateTargetsCase2,R6GameServiceAddresses::CDataContainerGStoreInflateTargetsCase3,R6GameServiceAddresses::CDataContainerGStoreInflateTargetsCase3,R6GameServiceAddresses::CDataContainerBranch108,R6GameServiceAddresses::CDataContainerGStoreInflateTargetsCase1};

// Groups entries into seven temporary lists, writes the header and grouped payloads, then rewrites length and shrinks.
// Unsupported types are skipped but counted by the header; allocation/encoder statuses and list lifetimes stay native.
// R6GameService.dll @ 10019f10 : native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall SerializeStoredValuesToBuffer(void *owner)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SerializeStoredValuesToBufferSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x80
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,0x10075c40
    mov    eax,0x1
    mov    DWORD PTR [esp+0x20],0x0
    mov    esi,ecx
    mov    DWORD PTR [esp+0x88],edi
    mov    DWORD PTR [esp+0x20],eax
    mov    DWORD PTR [esp+0x98],eax
    lea    eax,[esp+0x11]
    push   eax
    lea    ecx,[esp+0x88]
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x7c],edi
    mov    DWORD PTR [esp+0x20],0x3
    lea    ecx,[esp+0x12]
    mov    DWORD PTR [esp+0x98],0x4
    push   ecx
    lea    ecx,[esp+0x7c]
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    eax,0x7
    mov    DWORD PTR [esp+0x70],edi
    mov    DWORD PTR [esp+0x20],eax
    lea    edx,[esp+0x13]
    lea    ecx,[esp+0x6c]
    push   edx
    mov    DWORD PTR [esp+0x9c],eax
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    ebp,0xf
    mov    DWORD PTR [esp+0x64],edi
    mov    DWORD PTR [esp+0x20],ebp
    lea    eax,[esp+0x14]
    mov    ebx,0xa
    push   eax
    lea    ecx,[esp+0x64]
    mov    DWORD PTR [esp+0x9c],ebx
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x58],edi
    mov    DWORD PTR [esp+0x20],0x1f
    lea    ecx,[esp+0x15]
    mov    DWORD PTR [esp+0x98],0xd
    push   ecx
    lea    ecx,[esp+0x58]
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x4c],edi
    mov    DWORD PTR [esp+0x20],0x3f
    lea    edx,[esp+0x16]
    lea    ecx,[esp+0x48]
    push   edx
    mov    DWORD PTR [esp+0x9c],0x10
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    DWORD PTR [esp+0x40],edi
    mov    DWORD PTR [esp+0x20],0x7f
    lea    eax,[esp+0x17]
    lea    ecx,[esp+0x3c]
    push   eax
    mov    DWORD PTR [esp+0x9c],0x13
    call   R6GameServiceAddresses::InitializePayloadListHeader
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x98],0x14
    mov    eax,DWORD PTR [ecx+0x4]
    test   eax,eax
    jne    Branch109
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esi+0xc],0x0
    mov    BYTE PTR [esi+0x10],0x1
    mov    BYTE PTR [esi+0x20],0x0
    mov    BYTE PTR [esp+0x98],0x11
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x98],0xe
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x98],0xb
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x60]
    mov    BYTE PTR [esp+0x98],0x8
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x6c]
    mov    BYTE PTR [esp+0x98],0x5
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x78]
    mov    BYTE PTR [esp+0x98],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x84]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    jmp    Branch173
  Branch109:
    lea    edx,[esp+0x1c]
    mov    DWORD PTR [esi+0xc],ebp
    push   edx
    or     edi,0xffffffff
    call   R6GameServiceAddresses::ReadOrderedTreeLeftmostLink
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    eax,ecx
    je     Branch115
  Branch110:
    mov    edx,DWORD PTR [eax+0x14]
    lea    ecx,[eax+0x14]
    mov    ebp,DWORD PTR [edx+0x4]
    cmp    ebp,0x6
    ja     Branch114
    jmp    DWORD PTR [ebp*4+R6GameServiceAddresses::GStoreSerializeRecord]
    mov    eax,DWORD PTR [edx+0x8]
    mov    ebp,DWORD PTR [esi+0xc]
    add    eax,ebx
    push   ecx
    add    ebp,eax
    push   ecx
    push   esp
    lea    ecx,[esp+0x60]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    ecx,[esp+0x28]
    push   ecx
    lea    ecx,[esp+0x60]
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    mov    eax,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [edx]
    jmp    Branch113
    mov    eax,DWORD PTR [edx+0x8]
    mov    ebp,DWORD PTR [esi+0xc]
    add    eax,0x9
    push   ecx
    add    ebp,eax
    push   ecx
    push   esp
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x48]
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    mov    eax,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [edx]
    jmp    Branch113
    mov    eax,DWORD PTR [edx+0x8]
    mov    ebp,DWORD PTR [esi+0xc]
    add    eax,ebx
    push   ecx
    add    ebp,eax
    push   ecx
    push   esp
    lea    ecx,[esp+0x54]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    ecx,[esp+0x30]
    push   ecx
    lea    ecx,[esp+0x54]
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    mov    eax,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [edx]
    jmp    Branch113
    mov    ebp,DWORD PTR [esi+0xc]
    push   ecx
    add    ebp,ebx
    push   ecx
    push   esp
    lea    ecx,[esp+0x78]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x34]
    lea    ecx,[esp+0x74]
    jmp    Branch111
    mov    ebp,DWORD PTR [esi+0xc]
    push   ecx
    add    ebp,ebx
    push   ecx
    push   esp
    lea    ecx,[esp+0x84]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x38]
    lea    ecx,[esp+0x80]
    push   edx
    jmp    Branch112
    mov    ebp,DWORD PTR [esi+0xc]
    push   ecx
    add    ebp,0x5
    push   ecx
    push   esp
    lea    ecx,[esp+0x90]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    edx,[esp+0x3c]
    lea    ecx,[esp+0x8c]
    push   edx
    jmp    Branch112
    mov    edx,DWORD PTR [edx+0x8]
    mov    ebp,DWORD PTR [esi+0xc]
    add    edx,0x9
    push   ecx
    add    ebp,edx
    push   ecx
    push   esp
    lea    ecx,[esp+0x6c]
    mov    DWORD PTR [esi+0xc],ebp
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    lea    eax,[esp+0x40]
    lea    ecx,[esp+0x68]
  Branch111:
    push   eax
  Branch112:
    call   R6GameServiceAddresses::InsertPayloadNodeBefore
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [eax+0x14]
    mov    ecx,DWORD PTR [ecx]
  Branch113:
    cmp    edi,ecx
    jbe    Branch114
    mov    edi,ecx
  Branch114:
    push   eax
    call   R6GameServiceAddresses::OrderedTreeSuccessor
    mov    ecx,DWORD PTR [esi+0x4]
    mov    DWORD PTR [esp+0x20],eax
    add    esp,0x4
    cmp    eax,DWORD PTR [ecx]
    jne    Branch110
  Branch115:
    mov    edx,DWORD PTR [esi+0xc]
    push   edx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    DWORD PTR [esi+0x8],eax
    jne    Branch116
    lea    ecx,[esp+0x3c]
    mov    BYTE PTR [esp+0x98],0x11
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x98],0xe
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x98],0xb
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x60]
    mov    BYTE PTR [esp+0x98],0x8
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x6c]
    mov    BYTE PTR [esp+0x98],0x5
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x78]
    mov    BYTE PTR [esp+0x98],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    lea    ecx,[esp+0x84]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call   R6GameServiceAddresses::ReleaseNodesAndSentinel
    mov    eax,0x8217000e
    jmp    Branch174
  Branch116:
    mov    DWORD PTR [esp+0x18],eax
    mov    BYTE PTR [esp+0x10],0x1
    mov    BYTE PTR [eax],0x0
    mov    eax,DWORD PTR [esp+0x18]
    mov    dl,BYTE PTR [eax]
    or     dl,0xf
    mov    BYTE PTR [eax],dl
    mov    dl,BYTE PTR [esp+0x10]
    mov    al,dl
    shr    al,1
    je     Branch118
  Branch117:
    shr    al,1
    jne    Branch117
  Branch118:
    mov    ebp,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esi+0xc]
    inc    ebp
    cmp    eax,0xff
    mov    DWORD PTR [esp+0x18],ebp
    mov    BYTE PTR [esp+0x10],dl
    ja     Branch119
    mov    eax,0x1
    jmp    Branch121
  Branch119:
    cmp    eax,0xffff
    ja     Branch120
    mov    eax,0x2
    jmp    Branch121
  Branch120:
    mov    ecx,0xffffff
    cmp    ecx,eax
    sbb    eax,eax
    neg    eax
    add    eax,0x3
  Branch121:
    dec    al
    xor    ecx,ecx
    shr    dl,1
    je     Branch123
  Branch122:
    inc    ecx
    shr    dl,1
    jne    Branch122
  Branch123:
    mov    bl,BYTE PTR [ebp+0x0]
    mov    dl,0x3
    shl    dl,cl
    not    dl
    and    bl,dl
    mov    dl,al
    mov    BYTE PTR [ebp+0x0],bl
    mov    ebp,DWORD PTR [esp+0x18]
    shl    dl,cl
    mov    bl,BYTE PTR [ebp+0x0]
    or     bl,dl
    test   ecx,ecx
    mov    BYTE PTR [ebp+0x0],bl
    je     Branch124
    mov    edx,0x8
    mov    ebp,DWORD PTR [esp+0x18]
    sub    edx,ecx
    mov    bl,0x3
    mov    cl,dl
    shr    bl,cl
    mov    cl,BYTE PTR [ebp+0x1]
    not    bl
    and    cl,bl
    mov    BYTE PTR [ebp+0x1],cl
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,dl
    shr    al,cl
    or     BYTE PTR [ebx+0x1],al
  Branch124:
    mov    al,BYTE PTR [esp+0x10]
    xor    ecx,ecx
    shr    al,1
    je     Branch126
  Branch125:
    inc    ecx
    shr    al,1
    jne    Branch125
  Branch126:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch127
    mov    ecx,DWORD PTR [esp+0x18]
    inc    ecx
    inc    eax
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    jmp    Branch128
  Branch127:
    mov    al,BYTE PTR [esp+0x10]
    shl    al,0x2
  Branch128:
    mov    ebp,DWORD PTR [esi+0xc]
    mov    BYTE PTR [esp+0x10],al
    cmp    ebp,0xff
    jbe    Branch132
    cmp    ebp,0xffff
    push   ebp
    ja     Branch129
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x1c]
    jmp    Branch130
  Branch129:
    lea    ecx,[esp+0x14]
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   0x8
    push   eax
    push   ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    ebp,0xffffff
    lea    eax,[esp+0x18]
    lea    edx,[esp+0x10]
    ja     Branch131
    shr    ebp,0x8
    push   ebp
  Branch130:
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteCursorByte
    lea    ecx,[esp+0x10]
    push   0x8
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
    lea    eax,[esp+0x10]
    push   ebp
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    edx,[esp+0x10]
    push   0x8
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    jmp    Branch133
  Branch131:
    shr    ebp,0x8
    push   ebp
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteCursorByte
    lea    ecx,[esp+0x10]
    push   0x8
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
    lea    eax,[esp+0x10]
    push   ebp
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    edx,[esp+0x10]
    push   0x8
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
  Branch132:
    lea    ecx,[esp+0x10]
    push   ebp
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    eax,[esp+0x10]
    push   0x8
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
  Branch133:
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    ecx,esi
    call   R6GameServiceAddresses::GetStoredValueCount
    cmp    eax,0xff
    ja     Branch134
    mov    eax,0x1
    jmp    Branch136
  Branch134:
    cmp    eax,0xffff
    ja     Branch135
    mov    eax,0x2
    jmp    Branch136
  Branch135:
    mov    edx,0xffffff
    cmp    edx,eax
    sbb    eax,eax
    neg    eax
    add    eax,0x3
  Branch136:
    mov    dl,BYTE PTR [esp+0x10]
    dec    al
    xor    ecx,ecx
    shr    dl,1
    je     Branch138
  Branch137:
    inc    ecx
    shr    dl,1
    jne    Branch137
  Branch138:
    mov    ebp,DWORD PTR [esp+0x18]
    mov    dl,0x3
    shl    dl,cl
    mov    bl,BYTE PTR [ebp+0x0]
    not    dl
    and    bl,dl
    mov    dl,al
    mov    BYTE PTR [ebp+0x0],bl
    mov    ebp,DWORD PTR [esp+0x18]
    shl    dl,cl
    mov    bl,BYTE PTR [ebp+0x0]
    or     bl,dl
    test   ecx,ecx
    mov    BYTE PTR [ebp+0x0],bl
    je     Branch139
    mov    edx,0x8
    mov    ebp,DWORD PTR [esp+0x18]
    sub    edx,ecx
    mov    bl,0x3
    mov    cl,dl
    shr    bl,cl
    mov    cl,BYTE PTR [ebp+0x1]
    not    bl
    and    cl,bl
    mov    BYTE PTR [ebp+0x1],cl
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,dl
    shr    al,cl
    or     BYTE PTR [ebx+0x1],al
  Branch139:
    mov    al,BYTE PTR [esp+0x10]
    xor    ecx,ecx
    shr    al,1
    je     Branch141
  Branch140:
    inc    ecx
    shr    al,1
    jne    Branch140
  Branch141:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch142
    mov    ecx,DWORD PTR [esp+0x18]
    inc    ecx
    inc    eax
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    jmp    Branch143
  Branch142:
    mov    al,BYTE PTR [esp+0x10]
    shl    al,0x2
  Branch143:
    mov    ecx,esi
    mov    BYTE PTR [esp+0x10],al
    call   R6GameServiceAddresses::GetStoredValueCount
    mov    ebp,eax
    cmp    ebp,0xff
    jbe    Branch147
    cmp    ebp,0xffff
    push   ebp
    ja     Branch144
    lea    edx,[esp+0x14]
    lea    eax,[esp+0x1c]
    jmp    Branch145
  Branch144:
    lea    ecx,[esp+0x14]
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    eax,[esp+0x10]
    lea    ecx,[esp+0x18]
    push   0x8
    push   eax
    push   ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    ebp,0xffffff
    lea    eax,[esp+0x18]
    lea    edx,[esp+0x10]
    ja     Branch146
    shr    ebp,0x8
    push   ebp
  Branch145:
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteCursorByte
    lea    ecx,[esp+0x10]
    push   0x8
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
    lea    eax,[esp+0x10]
    push   ebp
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    edx,[esp+0x10]
    push   0x8
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    jmp    Branch148
  Branch146:
    shr    ebp,0x8
    push   ebp
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteCursorByte
    lea    ecx,[esp+0x10]
    push   0x8
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
    lea    eax,[esp+0x10]
    push   ebp
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    edx,[esp+0x10]
    push   0x8
    lea    eax,[esp+0x1c]
    push   edx
    push   eax
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
  Branch147:
    lea    ecx,[esp+0x10]
    push   ebp
    lea    edx,[esp+0x1c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::WriteCursorByte
    lea    eax,[esp+0x10]
    push   0x8
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
  Branch148:
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    edi,0xff
    ja     Branch149
    mov    eax,0x1
    jmp    Branch151
  Branch149:
    cmp    edi,0xffff
    ja     Branch150
    mov    eax,0x2
    jmp    Branch151
  Branch150:
    mov    edx,0xffffff
    cmp    edx,edi
    sbb    eax,eax
    neg    eax
    add    eax,0x3
  Branch151:
    mov    dl,BYTE PTR [esp+0x10]
    dec    al
    xor    ecx,ecx
    shr    dl,1
    je     Branch153
  Branch152:
    inc    ecx
    shr    dl,1
    jne    Branch152
  Branch153:
    mov    ebp,DWORD PTR [esp+0x18]
    mov    dl,0x3
    shl    dl,cl
    mov    bl,BYTE PTR [ebp+0x0]
    not    dl
    and    bl,dl
    mov    dl,al
    mov    BYTE PTR [ebp+0x0],bl
    mov    ebp,DWORD PTR [esp+0x18]
    shl    dl,cl
    mov    bl,BYTE PTR [ebp+0x0]
    or     bl,dl
    test   ecx,ecx
    mov    BYTE PTR [ebp+0x0],bl
    je     Branch154
    mov    edx,0x8
    mov    ebp,DWORD PTR [esp+0x18]
    sub    edx,ecx
    mov    bl,0x3
    mov    cl,dl
    shr    bl,cl
    mov    cl,BYTE PTR [ebp+0x1]
    not    bl
    and    cl,bl
    mov    BYTE PTR [ebp+0x1],cl
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,dl
    shr    al,cl
    or     BYTE PTR [ebx+0x1],al
  Branch154:
    mov    al,BYTE PTR [esp+0x10]
    xor    ecx,ecx
    shr    al,1
    je     Branch156
  Branch155:
    inc    ecx
    shr    al,1
    jne    Branch155
  Branch156:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch157
    mov    ecx,DWORD PTR [esp+0x18]
    inc    ecx
    inc    eax
    mov    DWORD PTR [esp+0x18],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    jmp    Branch158
  Branch157:
    mov    al,BYTE PTR [esp+0x10]
    shl    al,0x2
  Branch158:
    mov    ebx,0x1
    lea    ecx,[esp+0x10]
    push   ebx
    push   0x0
    push   0x0
    push   edi
    lea    edx,[esp+0x28]
    push   ecx
    push   edx
    mov    BYTE PTR [esp+0x28],al
    call   R6GameServiceAddresses::WriteStoreInteger
    mov    eax,DWORD PTR [esp+0x84]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je     Branch160
  Branch159:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x9
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x84]
    cmp    ebp,eax
    jne    Branch159
  Branch160:
    mov    eax,DWORD PTR [esp+0x78]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je     Branch162
  Branch161:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x6
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x78]
    cmp    ebp,eax
    jne    Branch161
  Branch162:
    mov    eax,DWORD PTR [esp+0x6c]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je     Branch164
  Branch163:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x7
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x6c]
    cmp    ebp,eax
    jne    Branch163
  Branch164:
    mov    eax,DWORD PTR [esp+0x60]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je     Branch166
  Branch165:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x8
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x60]
    cmp    ebp,eax
    jne    Branch165
  Branch166:
    mov    eax,DWORD PTR [esp+0x54]
    mov    ebp,DWORD PTR [eax]
    cmp    ebp,eax
    je     Branch168
  Branch167:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x3
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x54]
    cmp    ebp,eax
    jne    Branch167
  Branch168:
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x48]
    push   eax
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    ebp,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x48]
    cmp    ebp,eax
    je     Branch170
  Branch169:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x5
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x48]
    cmp    ebp,eax
    jne    Branch169
  Branch170:
    lea    eax,[esp+0x38]
    lea    ecx,[esp+0x3c]
    push   eax
    call   R6GameServiceAddresses::ReadListFirstNodeFromHeadSlot
    mov    ebp,DWORD PTR [eax]
    mov    eax,DWORD PTR [esp+0x3c]
    cmp    ebp,eax
    je     Branch172
  Branch171:
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x0
    mov    ecx,DWORD PTR [eax+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    mov    eax,DWORD PTR [eax]
    push   ecx
    sub    eax,edi
    push   edx
    push   eax
    lea    ecx,[esp+0x20]
    push   0x4
    lea    edx,[esp+0x2c]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::EncodeStoreEntry
    mov    ebp,DWORD PTR [ebp+0x0]
    mov    eax,DWORD PTR [esp+0x3c]
    cmp    ebp,eax
    jne    Branch171
  Branch172:
    mov    eax,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esi+0x8]
    mov    ecx,eax
    push   0x2
    sub    ecx,edx
    mov    dl,BYTE PTR [esp+0x14]
    mov    DWORD PTR [esi+0xc],ecx
    mov    cl,BYTE PTR [eax]
    or     cl,dl
    lea    edx,[esp+0x1c]
    mov    BYTE PTR [eax],cl
    mov    edi,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x14]
    inc    edi
    inc    eax
    push   ecx
    push   edx
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esp+0x24],eax
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    push   ebx
    push   0x0
    push   0x0
    lea    eax,[esp+0x1c]
    push   edi
    lea    ecx,[esp+0x28]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteStoreInteger
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [esi+0x8]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ResizeGameServiceBytes
    lea    ecx,[esp+0x3c]
    mov    DWORD PTR [esi+0x8],eax
    mov    BYTE PTR [esi+0x10],bl
    mov    BYTE PTR [esi+0x20],0x0
    mov    BYTE PTR [esp+0x98],0x11
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x48]
    mov    BYTE PTR [esp+0x98],0xe
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x54]
    mov    BYTE PTR [esp+0x98],0xb
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x60]
    mov    BYTE PTR [esp+0x98],0x8
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x6c]
    mov    BYTE PTR [esp+0x98],0x5
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x78]
    mov    BYTE PTR [esp+0x98],0x2
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
    lea    ecx,[esp+0x84]
    mov    DWORD PTR [esp+0x98],0xffffffff
    call   R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  Branch173:
    mov    eax,0x2130000
  Branch174:
    mov    ecx,DWORD PTR [esp+0x90]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x8c
    ret
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 0.
// R6GameService.dll @ 10064a70 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x1
    test   eax,eax
    je     Branch175
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch175:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 0.
// R6GameService.dll @ 10064a87 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x8b]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 0 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064a92 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 1.
// R6GameService.dll @ 10064a9a : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x2
    test   eax,eax
    je     Branch176
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch176:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 1.
// R6GameService.dll @ 10064ab1 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x8a]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 1 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064abc : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 2.
// R6GameService.dll @ 10064ac4 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind7(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x4
    test   eax,eax
    je     Branch177
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch177:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 2.
// R6GameService.dll @ 10064adb : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x89]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 2 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064ae6 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 3.
// R6GameService.dll @ 10064aee : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind10(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x8
    test   eax,eax
    je     Branch178
    lea    ecx,[ebp-0x34]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch178:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 3.
// R6GameService.dll @ 10064b05 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind11(void)
{
  __asm {
    lea    ecx,[ebp-0x88]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 3 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064b10 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 4.
// R6GameService.dll @ 10064b18 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind13(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x10
    test   eax,eax
    je     Branch179
    lea    ecx,[ebp-0x40]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch179:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 4.
// R6GameService.dll @ 10064b2f : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x87]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 4 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064b3a : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind15(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 5.
// R6GameService.dll @ 10064b42 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind16(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x20
    test   eax,eax
    je     Branch180
    lea    ecx,[ebp-0x4c]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch180:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 5.
// R6GameService.dll @ 10064b59 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind17(void)
{
  __asm {
    lea    ecx,[ebp-0x86]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 5 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064b64 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind18(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Runs the flag-guarded empty allocator cleanup for temporary list 6.
// R6GameService.dll @ 10064b6c : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind19(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x7c]
    and    eax,0x40
    test   eax,eax
    je     Branch181
    lea    ecx,[ebp-0x58]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch181:
    ret
  }
}

// Runs the empty allocator cleanup at the saved temporary tag byte for list 6.
// R6GameService.dll @ 10064b83 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind20(void)
{
  __asm {
    lea    ecx,[ebp-0x85]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Releases temporary list 6 nodes and sentinel through its inherited frame slot.
// R6GameService.dll @ 10064b8e : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferUnwind21(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    R6GameServiceAddresses::ReleaseNodesAndSentinelThunk
  }
}

// Selects the serializer seven-list,21-state unwind map.
// R6GameService.dll @ 10064b96 : native control/access order and raw ABI retained.
__declspec(naked) void SerializeStoredValuesToBufferSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SerializeStoredValuesToBufferExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1001aa50 : stored type dispatch.
const uint GStoreSerializeRecord[7] = {
  R6GameServiceAddresses::GStoreSerializeRecordCase1,R6GameServiceAddresses::GStoreSerializeRecordCase2,R6GameServiceAddresses::GStoreSerializeRecordCase3,R6GameServiceAddresses::GStoreSerializeRecordCase4,R6GameServiceAddresses::GStoreSerializeRecordCase5,R6GameServiceAddresses::GStoreSerializeRecordCase6,R6GameServiceAddresses::GStoreSerializeRecordCase7
};

// R6GameService.dll data @ 1007ee44 : temporary-list unwind map.
const R6GameServiceNative::UnwindEntry SerializeStoredValuesToBufferUnwindMap[21] = {
  {-1, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind1},
  {0x0, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind2},
  {-1, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind3},
  {0x2, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind4},
  {0x3, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind5},
  {0x2, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind6},
  {0x5, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind7},
  {0x6, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind8},
  {0x5, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind9},
  {0x8, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind10},
  {0x9, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind11},
  {0x8, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind12},
  {0xb, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind13},
  {0xc, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind14},
  {0xb, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind15},
  {0xe, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind16},
  {0xf, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind17},
  {0xe, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind18},
  {0x11, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind19},
  {0x12, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind20},
  {0x11, R6GameServiceAddresses::SerializeStoredValuesToBufferUnwind21},
};

// R6GameService.dll data @ 1007eeec : serializer FuncInfo.
const R6GameServiceNative::FuncInfo SerializeStoredValuesToBufferExceptionInfo = {
  0x19930520,
  0x15,
  R6GameServiceAddresses::SerializeStoredValuesToBufferUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: CDataContainer_GSDataContainerVTable
// R6GameService.dll data @ 10075c3c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct CDataContainer_GSDataContainerVTableRecord {
  R6GameServiceNative::Address DestroySerializedByteStore; // +0x00
};
const CDataContainer_GSDataContainerVTableRecord CDataContainer_GSDataContainerVTable = {
  R6GameServiceAddresses::DestroySerializedByteStore,
};
