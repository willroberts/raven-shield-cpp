#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080194 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo SimpleMessageConstructionExceptionHandlerFunctionInfo;

// Constructs clSimpleMessage, serializes its source and optionally transforms it through a cached codec.
// R6GameService.dll @ 1002ce30 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall InitializeTaggedPayload(void *object,byte tag,void *codec,void *source,int initializeSecondaryTable)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SimpleMessageConstructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    // Load fourth argument as secondary-table flag; entry locals flags-14, receiver-10, EH-c/-8/-4.
    mov    edx,DWORD PTR [esp+0x24]
    push   ebx
    push   ebp
    push   esi
    xor    eax,eax
    mov    esi,ecx
    cmp    edx,eax
    push   edi
    mov    DWORD PTR [esp+0x14],esi
    mov    DWORD PTR [esp+0x10],eax
    mov    ecx,0x1
    je Branch1
    mov    DWORD PTR [esi+0x4],0x10076c00
    mov    DWORD PTR [esp+0x10],ecx
  Branch1:
    // Cache source and codec, enter state1, then initialize tag/codec/data/size and the clSimpleMessage table.
    mov    ebx,DWORD PTR [esp+0x30]
    mov    edi,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [esp+0x20],ecx
    mov    cl,BYTE PTR [esp+0x28]
    lea    ebp,[esi+0x14]
    cmp    ebx,eax
    mov    BYTE PTR [esi+0x8],cl
    mov    DWORD PTR [esi+0xc],edi
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [ebp+0x0],eax
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSimpleMessageVTable
    je Branch4
    // Original tag argument becomes mutable serialization size; original fourth argument later becomes temporary buffer.
    lea    edx,[esp+0x28]
    mov    ecx,ebx
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x30],eax
    call   R6GameServiceAddresses::SerializeClDataListToBuffer
    mov    eax,DWORD PTR [esp+0x28]
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0x34],eax
    push   ecx
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::SerializeClDataListToBuffer
    // Require serialization AL exactly one; a null codec discards the temporary bytes without creating owned payload.
    cmp    al,0x1
    jne Branch2
    test   edi,edi
    je Branch2
    // Ignore codec size-query status; cache the current temporary buffer and use object+14 as mutable capacity/size.
    mov    eax,DWORD PTR [esp+0x28]
    mov    ebx,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [edi]
    push   ebp
    push   0x0
    push   eax
    push   ebx
    mov    ecx,edi
    call   DWORD PTR [edx+0xc]
    mov    ecx,DWORD PTR [ebp+0x0]
    push   ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Publish allocation before reloading codec table and source size; actual conversion accepts any nonzero AL.
    push   ebp
    mov    DWORD PTR [esi+0x10],eax
    mov    edx,DWORD PTR [edi]
    push   eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,edi
    push   eax
    push   ebx
    call   DWORD PTR [edx+0xc]
    test   al,al
    jne Branch3
    // On conversion failure, release the current object payload and clear pointer/size only after release returns.
    mov    ecx,DWORD PTR [esi+0x10]
    push   ecx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    DWORD PTR [esi+0x10],0x0
    mov    DWORD PTR [ebp+0x0],0x0
    jmp Branch3
  Branch2:
    mov    ebx,DWORD PTR [esp+0x34]
  Branch3:
    // Release cached temporary buffer with state1 still live; no extra temporary-buffer unwind action exists.
    push   ebx
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch4:
    // Restore previous FS and return the saved receiver; retain native ECX residue.
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x10
  }
}

// Destroys clSimpleMessage fields and conditionally releases receiver storage for flag bit zero.
// R6GameService.dll @ 1002cf40 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall DeleteTaggedPayload(void *object,byte flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyTaggedPayloadFields
    test   BYTE PTR [esp+0x8],0x1
    je Branch5
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch5:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Initializes clSimpleMessage and copies a matching tagged record only when its byte count exceeds five.
// R6GameService.dll @ 1002cf60 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall ParseTaggedPayload(void *object,byte tag,void *codec,byte *bytes,uint byteCount,int initializeSecondaryTable)
{
  __asm {
    // Clear saved ECX scratch; optional secondary-table initialization is controlled by the fifth stack argument.
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,ecx
    mov    ecx,DWORD PTR [esp+0x20]
    xor    eax,eax
    push   esi
    cmp    ecx,eax
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    je Branch6
    mov    DWORD PTR [ebp+0x4],0x10076c00
  Branch6:
    mov    esi,DWORD PTR [esp+0x20]
    mov    cl,BYTE PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x1c]
    cmp    esi,eax
    mov    BYTE PTR [ebp+0x8],cl
    mov    DWORD PTR [ebp+0xc],edx
    mov    DWORD PTR [ebp+0x10],eax
    mov    DWORD PTR [ebp+0x14],eax
    mov    DWORD PTR [ebp+0x0],R6GameServiceAddresses::clSimpleMessageVTable
    je Branch7
    mov    edi,DWORD PTR [esp+0x24]
    cmp    edi,0x5
    jbe Branch7
    // Load unaligned length and cache tag before imported decode; compare the current object tag after that call.
    mov    eax,DWORD PTR [esi+0x1]
    mov    bl,BYTE PTR [esi]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_ntohlSlot
    add    edi,0xfffffffb
    cmp    edi,eax
    jne Branch7
    cmp    BYTE PTR [ebp+0x8],bl
    jne Branch7
    // Publish decoded size before allocation, reload size afterward, then copy dwords followed by remaining bytes.
    push   eax
    mov    DWORD PTR [ebp+0x14],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebp+0x14]
    mov    DWORD PTR [ebp+0x10],eax
    mov    edi,eax
    mov    eax,ecx
    add    esi,0x5
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
  Branch7:
    // Return receiver and pop the cleared ECX scratch slot; no local EH or failure rollback is added.
    pop    edi
    mov    eax,ebp
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x14
  }
}

// Releases owned payload without clearing its fields, then installs the allocator-override base table.
// R6GameService.dll @ 1002cff0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __fastcall DestroyTaggedPayloadFields(void *object)
{
  __asm {
    // Cache payload before installing derived table; free may alter fields but the final base-table write still occurs.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clSimpleMessageVTable
    test   eax,eax
    je Branch8
    push   eax
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch8:
    mov    DWORD PTR [esi],R6GameServiceAddresses::clExtalloc_Override_BaseclassVTable
    pop    esi
    ret
  }
}

// Writes tag, network length and current payload when capacity fits, retaining raw EAX and late field reloads.
// R6GameService.dll @ 1002d010 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __thiscall SerializeTaggedPayload(void *object,byte *output,uint *capacityAndSize)
{
  __asm {
    // Cache size pointer before receiver checks; null size pointer returns incoming upper EAX with AL zero.
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    push   edi
    test   ebp,ebp
    mov    ebx,ecx
    je Branch11
    mov    eax,DWORD PTR [ebx+0x10]
    test   eax,eax
    jne Branch9
    mov    DWORD PTR [ebp+0x0],0x0
    pop    edi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x8
  Branch9:
    mov    edi,DWORD PTR [esp+0x10]
    test   edi,edi
    je Branch10
    mov    eax,DWORD PTR [ebx+0x14]
    mov    ecx,DWORD PTR [ebp+0x0]
    add    eax,0x5
    cmp    ecx,eax
    jb Branch10
    // Write tag before imported length conversion; reload payload length/pointer after that call.
    mov    cl,BYTE PTR [ebx+0x8]
    push   esi
    mov    BYTE PTR [edi],cl
    mov    edx,DWORD PTR [ebx+0x14]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::WS2_32_htonlSlot
    mov    DWORD PTR [edi+0x1],eax
    mov    ecx,DWORD PTR [ebx+0x14]
    mov    esi,DWORD PTR [ebx+0x10]
    mov    eax,ecx
    add    edi,0x5
    shr    ecx,0x2
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    mov    al,0x1
    and    ecx,0x3
    rep movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    // Reload object size after copying before final publication; success upper EAX retains the copied count.
    mov    ecx,DWORD PTR [ebx+0x14]
    pop    esi
    add    ecx,0x5
    pop    edi
    mov    DWORD PTR [ebp+0x0],ecx
    pop    ebp
    pop    ebx
    ret    0x8
  Branch10:
    // Failure size publication reloads current object length; preserve upper EAX from the prior guard path.
    mov    edx,DWORD PTR [ebx+0x14]
    add    edx,0x5
    mov    DWORD PTR [ebp+0x0],edx
  Branch11:
    pop    edi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x8
  }
}

// Parses payload bytes into a destination list, optionally decoding through the configured codec first.
// R6GameService.dll @ 1002d0a0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) uint __thiscall DecodeTaggedPayloadToList(void *object,void *destinationList)
{
  __asm {
    // Cache destination in EBP; null destination and null payload have distinct native upper-EAX residues.
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    xor    ebx,ebx
    push   esi
    cmp    ebp,ebx
    mov    esi,ecx
    jne Branch12
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x4
  Branch12:
    mov    eax,DWORD PTR [esi+0x10]
    cmp    eax,ebx
    jne Branch13
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    ret    0x4
  Branch13:
    mov    ecx,DWORD PTR [esi+0xc]
    cmp    ecx,ebx
    je Branch15
    // Original destination argument becomes one shared mutable codec sizing/conversion length slot, initialized once.
    push   edi
    lea    edi,[esp+0x14]
    push   edi
    mov    edi,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esp+0x18],ebx
    mov    edx,DWORD PTR [ecx]
    push   0x0
    push   edi
    push   eax
    call   DWORD PTR [edx+0x10]
    mov    eax,DWORD PTR [esp+0x14]
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    // Reload codec, payload and size for the second call; reuse the sizing result without resetting its word.
    mov    ecx,DWORD PTR [esi+0xc]
    mov    edi,eax
    lea    eax,[esp+0x14]
    mov    edx,DWORD PTR [ecx]
    push   eax
    mov    eax,DWORD PTR [esi+0x14]
    push   edi
    push   eax
    mov    eax,DWORD PTR [esi+0x10]
    push   eax
    call   DWORD PTR [edx+0x10]
    // Require decoder AL exactly one before parsing; cached EBP remains the destination despite argument-slot reuse.
    cmp    al,0x1
    jne Branch14
    mov    ecx,DWORD PTR [esp+0x14]
    push   ecx
    push   edi
    mov    ecx,ebp
    call   R6GameServiceAddresses::ParseClDataListBytes
    mov    bl,al
  Branch14:
    // Release decoded temporary and return free upper EAX with parser raw AL, or zero AL when decoding did not succeed.
    push   edi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    pop    edi
    pop    esi
    mov    al,bl
    pop    ebp
    pop    ebx
    ret    0x4
  Branch15:
    // Without a codec, forward the complete list-parser EAX unchanged.
    mov    edx,DWORD PTR [esi+0x14]
    mov    ecx,ebp
    push   edx
    push   eax
    call   R6GameServiceAddresses::ParseClDataListBytes
    mov    bl,al
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x4
  }
}

// Forwards saved receiver+0x18 to empty cleanup when constructor flag bit zero is set.
// R6GameService.dll @ 10065db0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl CleanupSimpleMessageAllocationContext(void)
{
  __asm {
    // Inherited EBP: flags-14 and saved receiver-10; only bit0 gates the empty allocator-context cleanup.
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test   eax,eax
    je Branch16
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch16:
    ret
  }
}

// Resets the constructing saved receiver to its allocator-override base table.
// R6GameService.dll @ 10065dca : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl ResetSimpleMessageAllocatorBase(void)
{
  __asm {
    // Inherited EBP: saved receiver-10 tail-forwards base-table reset37840, without releasing payload fields.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyExtallocOverrideBase
  }
}

// Selects the simple-message constructor two-state exception metadata for the shared C++ handler.
// R6GameService.dll @ 10065dd2 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl SimpleMessageConstructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SimpleMessageConstructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: clSimpleMessageVTable
// R6GameService.dll data @ 10076bfc : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clSimpleMessageVTableRecord {
  R6GameServiceNative::Address DeleteTaggedPayload; // +0x00
};
const clSimpleMessageVTableRecord clSimpleMessageVTable = {R6GameServiceAddresses::DeleteTaggedPayload};
