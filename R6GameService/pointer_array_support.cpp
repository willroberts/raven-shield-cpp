#include "native_addresses.h"

// Shared three-DWORD pointer-array allocation/copy/insertion helpers; original container class unresolved.

// For positive signed byte difference, memmove to destinationEnd-bytes and return its raw result; otherwise return destinationEnd. RET12.
// R6GameService.dll @ 100610d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __stdcall MoveByteRangeToEnd(const void *first,const void *last,void *destinationEnd)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x8]
    mov    ecx,DWORD PTR [esp+0x4]
    sub    eax,ecx
    test    eax,eax
    jle    Branch1
    push    eax
    push    ecx
    mov    ecx,DWORD PTR [esp+0x14]
    sub    ecx,eax
    push    ecx
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
    ret    0xc
  Branch1:
    mov    eax,DWORD PTR [esp+0xc]
    ret    0xc
  }
}

// Grow only if unsigned signed-distance capacity is insufficient; clone old span, free CURRENT old begin before publishing.
// Preserve initial size/requested capacity, stale unused bytes and raw EAX: old begin if unchanged, malloc or free result if grown. RET4.
// R6GameService.dll @ 10061680 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EnsurePointerArrayCapacity(void *array,uint requestedCapacity)
{
  __asm {
    push    ebp
    push    esi
    mov    ebp,DWORD PTR [esp+0xc]
    mov    esi,ecx
    mov    eax,DWORD PTR [esi]
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
    sar    ecx,0x2
    cmp    ecx,ebp
    jae    Branch4
    mov    ecx,DWORD PTR [esi+0x4]
    push    ebx
    mov    ebx,ecx
    push    edi
    sub    ebx,eax
    sar    ebx,0x2
    test    eax,eax
    je    Branch2
    push    ecx
    push    eax
    push    ebp
    mov    ecx,esi
    call    R6GameServiceAddresses::ClonePointerArrayAllocation
    mov    edx,DWORD PTR [esi]
    mov    edi,eax
    push    edx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    jmp    Branch3
  Branch2:
    lea    eax,[ebp*4+0x0]
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
  Branch3:
    mov    DWORD PTR [esi],edi
    lea    ecx,[edi+ebx*4]
    lea    edx,[edi+ebp*4]
    pop    edi
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],edx
    pop    ebx
  Branch4:
    pop    esi
    pop    ebp
    ret    0x4
  }
}

// Insert repeated DWORDs: in-place snapshots value before calls; growth rereads value per iteration after allocation/prefix copy.
// Retain two-step overlap shifts/end publication, original argument rewrites and current old-end/begin reloads.
// Growth rewrites count argument to new begin and saved ECX to capacity bytes; in-place rewrites position/count/value words.
// Capacity=size+max(size,count), publish after free; count0 retains EAX and receiver. RET12, no local EH.
// R6GameService.dll @ 100616e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall InsertRepeatedPointerValue(
    void *array,uint *position,uint count,const uint *value)
{
  __asm {
    push    ecx
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    test    edi,edi
    je    Branch19
    mov    eax,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
    sar    ecx,0x2
    cmp    ecx,edi
    jb    Branch12
    mov    ebp,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x20]
    mov    ebx,DWORD PTR [esi+0x4]
    sub    eax,ebp
    mov    ecx,DWORD PTR [edx]
    sar    eax,0x2
    mov    edx,eax
    mov    DWORD PTR [esp+0x20],ecx
    cmp    edx,edi
    mov    DWORD PTR [esp+0x1c],edx
    jbe    Branch8
    lea    eax,[edi*4+0x0]
    mov    edi,ebx
    sub    edi,eax
    mov    DWORD PTR [esp+0x18],eax
    cmp    ebx,edi
    je    Branch5
    mov    edx,ebx
    sub    edx,edi
    push    edx
    push    edi
    push    ebx
    call    R6GameServiceAddresses::memmove
    mov    eax,DWORD PTR [esp+0x24]
    add    esp,0xc
  Branch5:
    mov    ecx,DWORD PTR [esi+0x4]
    sub    edi,ebp
    add    ecx,eax
    test    edi,edi
    mov    DWORD PTR [esi+0x4],ecx
    jle    Branch6
    push    edi
    sub    ebx,edi
    push    ebp
    push    ebx
    call    R6GameServiceAddresses::memmove
    mov    eax,DWORD PTR [esp+0x24]
    add    esp,0xc
  Branch6:
    add    eax,ebp
    cmp    ebp,eax
    je    Branch19
    mov    ecx,DWORD PTR [esp+0x20]
  Branch7:
    mov    DWORD PTR [ebp+0x0],ecx
    add    ebp,0x4
    cmp    ebp,eax
    jne    Branch7
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  Branch8:
    mov    ecx,edi
    sub    ecx,edx
    mov    DWORD PTR [esp+0x18],ecx
    je    Branch9
    mov    eax,DWORD PTR [esp+0x20]
    mov    edi,ebx
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,DWORD PTR [esp+0x18]
  Branch9:
    mov    edi,DWORD PTR [esi+0x4]
    lea    eax,[ecx*4+0x0]
    add    edi,eax
    cmp    ebx,ebp
    mov    DWORD PTR [esi+0x4],edi
    mov    eax,edi
    je    Branch10
    mov    ecx,ebx
    sub    ecx,ebp
    push    ecx
    push    ebp
    push    eax
    call    R6GameServiceAddresses::memmove
    mov    edx,DWORD PTR [esp+0x28]
    add    esp,0xc
  Branch10:
    mov    ecx,DWORD PTR [esi+0x4]
    shl    edx,0x2
    add    ecx,edx
    cmp    ebp,ebx
    mov    DWORD PTR [esi+0x4],ecx
    je    Branch19
  Branch11:
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [ebp+0x0],eax
    add    ebp,0x4
    cmp    ebp,ebx
    jne    Branch11
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  Branch12:
    mov    ebx,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x1c],edi
    sub    eax,ebx
    lea    ecx,[esp+0x1c]
    sar    eax,0x2
    cmp    eax,edi
    mov    DWORD PTR [esp+0x10],eax
    jb    Branch13
    lea    ecx,[esp+0x10]
  Branch13:
    mov    ecx,DWORD PTR [ecx]
    add    ecx,eax
    shl    ecx,0x2
    push    ecx
    mov    DWORD PTR [esp+0x14],ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,DWORD PTR [esp+0x18]
    mov    ecx,eax
    mov    eax,DWORD PTR [esi]
    mov    DWORD PTR [esp+0x1c],ecx
    cmp    ebp,eax
    jne    Branch14
    mov    eax,ecx
    jmp    Branch15
  Branch14:
    mov    ebx,ebp
    sub    ebx,eax
    push    ebx
    push    eax
    push    ecx
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebx
  Branch15:
    test    edi,edi
    jbe    Branch17
    mov    ecx,DWORD PTR [esp+0x20]
  Branch16:
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [eax],edx
    add    eax,0x4
    dec    edi
    jne    Branch16
  Branch17:
    mov    ebx,DWORD PTR [esi+0x4]
    mov    edi,eax
    cmp    ebx,ebp
    je    Branch18
    sub    ebx,ebp
    push    ebx
    push    ebp
    push    eax
    call    R6GameServiceAddresses::memmove
    mov    edi,eax
    add    esp,0xc
    add    edi,ebx
  Branch18:
    mov    eax,DWORD PTR [esi]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x10]
    add    ecx,eax
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],edi
    mov    DWORD PTR [esi+0x8],ecx
  Branch19:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Allocate size+max(size,count), copy prefix, fill from current pointed-to DWORD each iteration, optionally copy current suffix.
// After a nonempty prefix copy reload count argument; otherwise retain initial count. Only suppression lowBYTE is used.
// Free CURRENT old begin before publishing new triplet; raw EAX is final free result. Extra third word unread; RET20, no local EH.
// R6GameService.dll @ 10061b50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RebuildPointerArrayWithRepeatedValue(
    void *array,uint *position,const uint *value,uint unusedWord,uint count,uint suppressTailWord)
{
  __asm {
    sub    esp,0x8
    push    ebx
    mov    ebx,ecx
    push    ebp
    push    esi
    mov    ecx,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    sub    ecx,esi
    mov    esi,DWORD PTR [esp+0x24]
    sar    ecx,0x2
    cmp    ecx,esi
    push    edi
    mov    DWORD PTR [esp+0x10],ecx
    lea    eax,[esp+0x28]
    jb    Branch20
    lea    eax,[esp+0x10]
  Branch20:
    mov    eax,DWORD PTR [eax]
    add    eax,ecx
    shl    eax,0x2
    push    eax
    mov    DWORD PTR [esp+0x18],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    edi,eax
    mov    eax,DWORD PTR [ebx]
    mov    DWORD PTR [esp+0x10],edi
    cmp    ebp,eax
    jne    Branch21
    mov    eax,edi
    jmp    Branch22
  Branch21:
    mov    esi,ebp
    sub    esi,eax
    push    esi
    push    eax
    push    edi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,esi
    mov    esi,DWORD PTR [esp+0x28]
  Branch22:
    test    esi,esi
    jbe    Branch24
    mov    edx,DWORD PTR [esp+0x20]
    mov    ecx,esi
  Branch23:
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [eax],esi
    add    eax,0x4
    dec    ecx
    jne    Branch23
  Branch24:
    mov    cl,BYTE PTR [esp+0x2c]
    mov    esi,eax
    test    cl,cl
    jne    Branch25
    mov    ecx,DWORD PTR [ebx+0x4]
    cmp    ecx,ebp
    je    Branch25
    mov    edi,ecx
    sub    edi,ebp
    push    edi
    push    ebp
    push    eax
    call    R6GameServiceAddresses::memmove
    mov    esi,eax
    add    esp,0xc
    add    esi,edi
    mov    edi,DWORD PTR [esp+0x10]
  Branch25:
    mov    eax,DWORD PTR [ebx]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    ecx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [ebx],edi
    add    ecx,edi
    mov    DWORD PTR [ebx+0x4],esi
    pop    edi
    pop    esi
    mov    DWORD PTR [ebx+0x8],ecx
    pop    ebp
    pop    ebx
    add    esp,0x8
    ret    0x14
  }
}

// Allocate capacity*4 bytes, then reload current original source arguments and memmove nonempty byte span; return allocation.
// Receiver is unread; no source release, spare initialization or local EH. RET12.
// R6GameService.dll @ 10061de0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ClonePointerArrayAllocation(
    void *unusedOwner,uint capacity,const void *first,const void *last)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push    esi
    lea    ecx,[eax*4+0x0]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0xc]
    mov    esi,eax
    mov    eax,DWORD PTR [esp+0x10]
    cmp    eax,ecx
    je    Branch26
    sub    eax,ecx
    push    eax
    push    ecx
    push    esi
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch26:
    mov    eax,esi
    pop    esi
    ret    0xc
  }
}

// Fill count DWORDs with a freshly reloaded pointed-to value each iteration; zero count skips value read. Return advanced pointer/RET12.
// R6GameService.dll @ 10061e20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint * __stdcall FillRepeatedDword(uint *destination,uint count,const uint *value)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0x4]
    test    ecx,ecx
    jbe    Branch28
    mov    edx,DWORD PTR [esp+0xc]
    push    esi
  Branch27:
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [eax],esi
    add    eax,0x4
    dec    ecx
    jne    Branch27
    pop    esi
  Branch28:
    ret    0xc
  }
}

// Signed slot-distance gate skips key dereference for nonpositive span; otherwise cache key and use unsigned lower_bound.
// Last two physical words unread; return first qualifying address or end, RET20.
// R6GameService.dll @ 10061e40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint * __stdcall LowerBoundUnsignedDwords(
    uint first,uint last,const uint *key,void *unusedContext,uint unusedWord)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0x4]
    sub    edx,eax
    sar    edx,0x2
    test    edx,edx
    jle    Branch32
    mov    ecx,DWORD PTR [esp+0xc]
    push    esi
    push    edi
    mov    esi,DWORD PTR [ecx]
  Branch29:
    mov    ecx,edx
    sar    ecx,1
    cmp    DWORD PTR [eax+ecx*4],esi
    jae    Branch30
    or    edi,0xffffffff
    lea    eax,[eax+ecx*4+0x4]
    sub    edi,ecx
    add    edx,edi
    jmp    Branch31
  Branch30:
    mov    edx,ecx
  Branch31:
    test    edx,edx
    jg    Branch29
    pop    edi
    pop    esi
  Branch32:
    ret    0x14
  }
}

// Clear three buffer fields, malloc count*4 bytes, then publish begin=end=allocation/capacity=allocation+bytes.
// Cache byte count before malloc, leave allocation bytes untouched, ignore second full word; return buffer/RET8. No local EH.
// R6GameService.dll @ 10061d40 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall InitializeDwordBufferWithCapacity(void *buffer,uint count,uint unusedWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    xor    eax,eax
    push    edi
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [esp+0xc]
    lea    edi,[eax*4+0x0]
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    add    edi,eax
    mov    DWORD PTR [esi],eax
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],edi
    mov    eax,esi
    pop    edi
    pop    esi
    ret    0x8
  }
}
