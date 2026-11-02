#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100808e0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ByteVectorCopyExceptionHandlerFunctionInfo;

// Shared raw byte-vector/storage helpers; prefix+0 and original template ownership remain opaque.

// Releases current storage at owner+4, then clears begin/end/capacity while retaining the opaque prefix.
// R6GameService.dll @ 100340c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall ReleaseAndResetStorageAt04(int ownerAddress)
{
  __asm {
    // Cache owner in ESI; free sees original current begin, no EH and no pre-free clearing.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch1
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch1:
    // Only after free returns, reset+4/+8/+c through cached owner; retain+0 and raw free EAX (or null EAX0).
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],0x0
    mov    DWORD PTR [esi+0xc],0x0
    pop    esi
    ret
  }
}

// Moves a raw byte range through memmove and returns its raw result plus the cached modular byte count.
// R6GameService.dll @ 100340f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall MoveRangeAndReturnEnd(void *unusedVector,void *sourceBegin,void *sourceEnd,void *destination)
{
  __asm {
    // Incoming ECX unused; cache end-begin modulo32 across memmove, including zero or wrapped counts.
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    sub    esi,eax
    push   esi
    push   eax
    mov    eax,DWORD PTR [esp+0x18]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_memmoveSlot
    add    esp,0xc
    // Use memmove returned EAX rather than reloading destination; RET0xc consumes exactly three arguments.
    add    eax,esi
    pop    esi
    ret    0xc
  }
}

// Copies bytes forward while testing each current destination for null and returns the advanced raw cursor.
// R6GameService.dll @ 10034120 : complete native control/access order and raw ABI retained.
byte * __cdecl CopyByteRangeAndReturnEnd(
    byte *sourceBegin,byte *sourceEnd,byte *destination,uint unusedCallerWord4,uint unusedCallerWord5)
{
  uint output = reinterpret_cast<uint>(destination);
  while (sourceBegin != sourceEnd) {
    if (output != 0) *reinterpret_cast<byte *>(output) = *sourceBegin;
    ++output;
    ++sourceBegin;
  }
  return reinterpret_cast<byte *>(output);
}

// Pops four trailing bytes into a big-endian word, retaining native end publications and argument-slot scratch writes.
// R6GameService.dll @ 10034550 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl PopTrailingBigEndianDword(void *vector)
{
  __asm {
    // Cache vector in ECX and begin in EDX; null begin bypasses end access, short unsigned span returns zero.
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [ecx+0x4]
    test   edx,edx
    push   ebp
    push   esi
    je     Branch5
    mov    ebp,DWORD PTR [ecx+0x8]
    mov    esi,ebp
    sub    esi,edx
    cmp    esi,0x4
    jae    Branch6
  Branch5:
    pop    esi
    xor    eax,eax
    pop    ebp
    ret
  Branch6:
    // Initial span>=4; each byte load precedes the current end!=cached-begin publication guard.
    xor    eax,eax
    mov    al,BYTE PTR [ebp-0x1]
    push   edi
    and    eax,0xff
    test   esi,esi
    mov    edi,eax
    je     Branch7
    dec    ebp
    mov    DWORD PTR [ecx+0x8],ebp
  Branch7:
    // Reload end for each successive byte; begin remains cached across all four steps.
    mov    esi,DWORD PTR [ecx+0x8]
    xor    eax,eax
    mov    ah,BYTE PTR [esi-0x1]
    or     edi,eax
    mov    eax,esi
    sub    eax,edx
    // Overwrite original stack argument slot (entryESP+4) with current length after first pop.
    mov    DWORD PTR [esp+0x10],eax
    je     Branch8
    dec    esi
    mov    DWORD PTR [ecx+0x8],esi
  Branch8:
    mov    esi,DWORD PTR [ecx+0x8]
    xor    eax,eax
    mov    al,BYTE PTR [esi-0x1]
    and    eax,0xff
    shl    eax,0x10
    or     edi,eax
    mov    eax,esi
    sub    eax,edx
    // Same argument slot receives length after second pop; it no longer contains the vector pointer.
    mov    DWORD PTR [esp+0x10],eax
    je     Branch9
    dec    esi
    mov    DWORD PTR [ecx+0x8],esi
  Branch9:
    mov    eax,DWORD PTR [ecx+0x8]
    movsx  esi,BYTE PTR [eax-0x1]
    shl    esi,0x18
    or     edi,esi
    mov    esi,eax
    sub    esi,edx
    // Final argument scratch is length before fourth pop; preserve sign-extended high byte shifted by24.
    mov    DWORD PTR [esp+0x10],esi
    je     Branch10
    dec    eax
    mov    DWORD PTR [ecx+0x8],eax
  Branch10:
    // Return assembled EAX; retain cached vector ECX/begin EDX and restore saved registers, cdecl/plain RET.
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebp
    ret
  }
}

// Constructs a byte-vector copy with cached allocation size, late source reloads and native partial-publication timing.
// R6GameService.dll @ 10034610 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyByteVector(void *destination,const void *sourceVector)
{
  __asm {
    // EBP-based EH: save destination at EBP-14, cache source EBX and modular byte count EDI.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::ByteVectorCopyExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebx+0x4]
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    cmp    eax,ecx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],esi
    jne    Branch11
    xor    edi,edi
    jmp    Branch12
  Branch11:
    mov    edi,DWORD PTR [ebx+0x8]
    sub    edi,eax
  Branch12:
    // Clear destination+4/+8/+c before allocation, preserving+0; source may alias destination.
    cmp    edi,ecx
    mov    DWORD PTR [esi+0x4],ecx
    mov    DWORD PTR [esi+0x8],ecx
    mov    DWORD PTR [esi+0xc],ecx
    je     Branch14
    // Unsigned count>UINT_MAX branch is unreachable normally; retain native comparison and throw edge.
    cmp    edi,0xffffffff
    jbe    Branch13
    mov    ecx,esi
    call   R6GameServiceAddresses::ThrowVectorLengthException
  Branch13:
    // Allocation runs in state-1. Reload original source argument for ignored fifth copy word after callback.
    push   edi
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    mov    edx,DWORD PTR [ebp+0x8]
    push   edx
    lea    ecx,[eax+edi*1]
    push   esi
    // Publish begin/end/capacity before state0; source range reloads through cached EBX, not modified argument slot.
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],ecx
    mov    ecx,DWORD PTR [ebx+0x8]
    mov    ebx,DWORD PTR [ebx+0x4]
    push   eax
    push   ecx
    push   ebx
    mov    DWORD PTR [ebp-0x4],0x0
    // Actual forward-copy helper34120, with two ignored owner words; cdecl cleanup includes allocation size word.
    call   R6GameServiceAddresses::CopyByteRangeAndReturnEnd
    add    esp,0x18
    mov    DWORD PTR [esi+0x8],eax
  Branch14:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Releases and resets the saved failed copy destination, then forwards the active exception without returning.
// R6GameService.dll @ 100346ab : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleaseFailedByteVectorCopy(void)
{
  __asm {
    // Catchall inherited EBP: reload saved destination, perform actual340c0 cleanup, noreturn33a16(0,0).
    mov    ecx,DWORD PTR [ebp-0x14]
    call   R6GameServiceAddresses::ReleaseAndResetStorageAt04
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects copy-constructor metadata with its manual cleanup catchall and null unwind actions.
// R6GameService.dll @ 10066470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ByteVectorCopyExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ByteVectorCopyExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reloads the fill byte for each forward store in a raw half-open range and returns its end.
// R6GameService.dll @ 10034080 : complete native control/access order and raw ABI retained.
byte * __cdecl FillByteRange(byte *first,byte *last,const byte *fillByte)
{
  while (first != last) {
    *first++ = *fillByte;
  }
  return first;
}

// Reloads a supplied byte for each counted store and returns destination plus count modulo32.
// R6GameService.dll @ 10034360 : complete native control/access order and raw ABI retained.
__declspec(naked) byte * __thiscall FillRepeatedByte(void *unusedVector,byte *destination,uint count,const byte *fillByte)
{
  __asm {
    // Incoming ECX unused for filling; count0 leaves its incoming value, otherwise loop leaves ECX0.
    push   ebp
    mov    ebp,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    test   edi,edi
    mov    eax,ebp
    jbe    Branch18
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    mov    ecx,edi
  Branch17:
    mov    dl,BYTE PTR [esi]
    mov    BYTE PTR [eax],dl
    inc    eax
    dec    ecx
    jne    Branch17
    pop    esi
  Branch18:
    // Raw EAX=original destination+count modulo32; RETc consumes three explicit words.
    lea    eax,[edi+ebp*1]
    pop    edi
    pop    ebp
    ret    0xc
  }
}

// Inserts cached fill bytes with native capacity growth, three insertion paths and caller-slot publication effects.
// R6GameService.dll @ 10034390 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall InsertRepeatedByte(void *vector,byte *position,uint count,const byte *fillByteAddress)
{
  __asm {
    // No EH frame. Initial ECX save at entryESP-4 doubles as capacity scratch.
    push   ecx
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    push   esi
    mov    esi,ecx
    // Read fill even for count0, then replace low byte of original third argument slot at entryESP+c.
    mov    cl,BYTE PTR [eax]
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    mov    BYTE PTR [esp+0x18],cl
    jne    Branch19
    xor    ecx,ecx
    jmp    Branch20
  Branch19:
    // Nonnull begin publishes capacity into saved ECX word; null/count0 retains original ECX there.
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    mov    DWORD PTR [esp+0x8],ecx
  Branch20:
    mov    ebx,DWORD PTR [esp+0x14]
    test   ebx,ebx
    je     Branch38
    test   eax,eax
    jne    Branch21
    xor    edx,edx
    jmp    Branch22
  Branch21:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch22:
    // Reject count>UINT_MAX-liveSize through actual length-error helper; keep cached count in EBX.
    push   edi
    or     edi,0xffffffff
    sub    edi,edx
    cmp    edi,ebx
    jae    Branch23
    mov    ecx,esi
    call   R6GameServiceAddresses::ThrowVectorLengthException
  Branch23:
    test   eax,eax
    jne    Branch24
    xor    edx,edx
    jmp    Branch25
  Branch24:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch25:
    add    edx,ebx
    cmp    ecx,edx
    push   ebp
    jae    Branch36
    // Grow by capacity+floor(capacity/2), fallback0 on overflow, then at least liveSize+count.
    mov    edx,ecx
    shr    edx,1
    or     edi,0xffffffff
    sub    edi,edx
    cmp    edi,ecx
    jae    Branch26
    mov    DWORD PTR [esp+0x10],0x0
    mov    ecx,DWORD PTR [esp+0x10]
    jmp    Branch27
  Branch26:
    add    ecx,edx
    mov    DWORD PTR [esp+0x10],ecx
  Branch27:
    test   eax,eax
    jne    Branch28
    xor    edx,edx
    jmp    Branch29
  Branch28:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch29:
    add    edx,ebx
    cmp    ecx,edx
    jae    Branch32
    test   eax,eax
    jne    Branch30
    xor    ecx,ecx
    jmp    Branch31
  Branch30:
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
  Branch31:
    add    ecx,ebx
    mov    DWORD PTR [esp+0x10],ecx
  Branch32:
    // Allocate before loading position; allocation callback can change original position argument.
    push   ecx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    mov    ebp,DWORD PTR [esp+0x1c]
    mov    ecx,eax
    // Reload current begin after allocation, cache prefix count; memmove returned EAX feeds fill start.
    mov    eax,DWORD PTR [esi+0x4]
    mov    edi,ebp
    sub    edi,eax
    push   edi
    push   eax
    push   ecx
    mov    DWORD PTR [esp+0x2c],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_memmoveSlot
    add    esp,0x10
    // Fill helpers read cached byte from original argument word, not from original fillByteAddress.
    lea    edx,[esp+0x20]
    push   edx
    add    eax,edi
    push   ebx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::FillRepeatedByte
    // Reload current end after fill; suffix source uses cached position, destination uses fill return.
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,ebp
    push   ecx
    push   ebp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_memmoveSlot
    // Reload current begin/size after suffix move, cache new size before optional old-storage free.
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0xc
    test   eax,eax
    jne    Branch33
    xor    ecx,ecx
    jmp    Branch34
  Branch33:
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
  Branch34:
    add    ebx,ecx
    test   eax,eax
    je     Branch35
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch35:
    // After free, publish new capacity/end/begin in that order; saved ECX word returns computed capacity.
    mov    eax,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x10]
    pop    ebp
    lea    ecx,[eax+edx*1]
    lea    edx,[eax+ebx*1]
    pop    edi
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esi+0x8],edx
    mov    DWORD PTR [esi+0x4],eax
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  Branch36:
    // In-place path caches current end/position; split on unsigned trailingBytes<count.
    mov    edi,DWORD PTR [esi+0x8]
    mov    ebp,DWORD PTR [esp+0x18]
    mov    eax,edi
    sub    eax,ebp
    cmp    eax,ebx
    jae    Branch37
    // Short tail: move tail, fill beyond end, publish new end, then fill original gap.
    lea    ecx,[ebx+ebp*1]
    push   ecx
    push   edi
    push   ebp
    mov    ecx,esi
    call   R6GameServiceAddresses::MoveRangeAndReturnEnd
    mov    eax,DWORD PTR [esi+0x8]
    mov    ecx,ebp
    sub    ecx,eax
    lea    edx,[esp+0x20]
    push   edx
    add    ecx,ebx
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::FillRepeatedByte
    mov    ecx,DWORD PTR [esi+0x8]
    add    ecx,ebx
    mov    DWORD PTR [esi+0x8],ecx
    mov    esi,ecx
    lea    edx,[esp+0x20]
    push   edx
    sub    esi,ebx
    push   esi
    push   ebp
    call   R6GameServiceAddresses::FillByteRange
    add    esp,0xc
    pop    ebp
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  Branch37:
    // Long/equal tail: copy final count bytes, publish moved-end return, move remaining tail, fill gap.
    push   edi
    mov    eax,edi
    push   edi
    sub    eax,ebx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::MoveRangeAndReturnEnd
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,edi
    sub    eax,ebp
    sub    eax,ebx
    push   eax
    sub    edi,eax
    push   ebp
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_memmoveSlot
    lea    ecx,[esp+0x2c]
    push   ecx
    lea    edx,[ebx+ebp*1]
    push   edx
    push   ebp
    call   R6GameServiceAddresses::FillByteRange
    add    esp,0x18
    pop    ebp
    pop    edi
  Branch38:
    // Count0 returns original begin EAX; other in-place raw EAX comes from final fill. ECX pops capacity scratch.
    pop    esi
    pop    ebx
    pop    ecx
    ret    0xc
  }
}

// Initializes byte storage, allocates a nonzero count and reloads the supplied byte for every fill store.
// R6GameService.dll @ 10035f60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall InitializeFilledByteVector(void *vector,uint count,const byte *fillByte)
{
  __asm {
    // No local EH; preserve prefix +0. Zero all three fields before reading the original fill argument.
    push   ebx
    push   esi
    xor    ebx,ebx
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    edi,ebx
    mov    esi,ecx
    mov    DWORD PTR [esi+0x4],ebx
    mov    DWORD PTR [esi+0x8],ebx
    mov    DWORD PTR [esi+0xc],ebx
    je     Branch42
    // Keep the native unsigned count <= UINT_MAX gate, including its unreachable length-error edge.
    cmp    edi,0xffffffff
    jbe    Branch39
    call   R6GameServiceAddresses::ThrowVectorLengthException
  Branch39:
    push   edi
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    // Publish capacity, begin and empty end before filling; allocation failure is unchecked.
    lea    ecx,[eax+edi*1]
    add    esp,0x4
    cmp    edi,ebx
    mov    DWORD PTR [esi+0xc],ecx
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    mov    ecx,eax
    jbe    Branch41
    // Reload current fill pointer after allocation, cache pointer once, then reload its byte for each store.
    mov    edx,DWORD PTR [esp+0x14]
    push   ebp
    mov    ebp,edi
  Branch40:
    mov    bl,BYTE PTR [edx]
    mov    BYTE PTR [ecx],bl
    inc    ecx
    dec    ebp
    jne    Branch40
    pop    ebp
  Branch41:
    add    eax,edi
    mov    DWORD PTR [esi+0x8],eax
  Branch42:
    // RET 8; zero count preserves incoming EAX, otherwise EAX is allocation + cached count.
    pop    edi
    pop    esi
    pop    ebx
    ret    0x8
  }
}
