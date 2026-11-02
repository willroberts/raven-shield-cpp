#include "native_addresses.h"

// Descriptive names for native full32 checksum storage; selected PE .data zero-fill establishes initial zeros.
// R6GameService.dll data @ 10093d28 : native storage identity retained.
uint GReflectedChecksumTable[256] = {};
// R6GameService.dll data @ 10094128 : native storage identity retained.
uint GForwardChecksumTable[256] = {};
// R6GameService.dll data @ 10094528 : native storage identity retained.
byte GForwardChecksumReady = 0;
// R6GameService.dll data @ 10094529 : native storage identity retained.
byte GReflectedChecksumReady = 0;

// Checksums the builder returned vector, frees separately owned local storage and preserves the computed word.
// R6GameService.dll @ 10034a30 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl ComputeCollectedStringsChecksum(void)
{
  __asm {
    // ESP-based pooled EH664c8: hidden local vector at entryESP-1c, distinct from builder returned EAX.
    push   0xffffffff
    push   R6GameServiceAddresses::LocalByteVectorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    lea    eax,[esp]
    push   esi
    push   eax
    call   R6GameServiceAddresses::BuildByteVectorFromCollectedStrings
    // Checksum uses raw returned vector; cleanup still owns local storage. State0 covers checksum and normal free.
    push   eax
    mov    DWORD PTR [esp+0x24],0x0
    call   R6GameServiceAddresses::checksum_support_UpdateChecksumFromBuffer
    mov    esi,eax
    // Read local begin after checksum callbacks; leave fields/state live during free, cache checksum in ESI.
    mov    eax,DWORD PTR [esp+0x10]
    add    esp,0x8
    test   eax,eax
    je     Branch1
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch1:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret
  }
}

// Appends the collected checksum most-significant byte first, retaining native argument-slot byte scratch.
// R6GameService.dll @ 10034a90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AppendCollectedStringsChecksumBytes(void *byteVector)
{
  __asm {
    // Compute checksum before loading vector argument; preserve full word in EDI and duplicate local entryESP-4.
    sub    esp,0x8
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::ComputeCollectedStringsChecksum
    mov    esi,DWORD PTR [esp+0x18]
    mov    edi,eax
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x18
    test   eax,eax
    mov    DWORD PTR [esp+0x10],edi
    mov    BYTE PTR [esp+0xf],bl
    jne    Branch2
    xor    edx,edx
    jmp    Branch3
  Branch2:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch3:
    test   eax,eax
    je     Branch4
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch4
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch5
  Branch4:
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0xf]
    push   ecx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch5:
    // Bytes2/3/4 overwrite low byte of original argument word at entryESP+4; cached ESI remains receiver.
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x10
    test   eax,eax
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch6
    xor    edx,edx
    jmp    Branch7
  Branch6:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch7:
    test   eax,eax
    je     Branch8
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch8
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch9
  Branch8:
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch9:
    mov    eax,DWORD PTR [esi+0x4]
    mov    ebx,edi
    shr    ebx,0x8
    test   eax,eax
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch10
    xor    edx,edx
    jmp    Branch11
  Branch10:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,eax
  Branch11:
    test   eax,eax
    je     Branch12
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,eax
    cmp    edx,ecx
    jae    Branch12
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    mov    DWORD PTR [esi+0x8],eax
    jmp    Branch13
  Branch12:
    mov    eax,DWORD PTR [esi+0x8]
    lea    ecx,[esp+0x18]
    push   ecx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
  Branch13:
    // Final byte reloads saved checksum local, not EDI low byte; each append reloads current vector fields.
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    mov    bl,BYTE PTR [esp+0x10]
    mov    BYTE PTR [esp+0x18],bl
    jne    Branch14
    xor    edx,edx
    jmp    Branch15
  Branch14:
    mov    edx,DWORD PTR [esi+0x8]
    sub    edx,ecx
  Branch15:
    test   ecx,ecx
    je     Branch16
    mov    eax,DWORD PTR [esi+0xc]
    sub    eax,ecx
    cmp    edx,eax
    jae    Branch16
    mov    eax,DWORD PTR [esi+0x8]
    mov    BYTE PTR [eax],bl
    inc    eax
    pop    edi
    mov    DWORD PTR [esi+0x8],eax
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  Branch16:
    mov    eax,DWORD PTR [esi+0x8]
    lea    edx,[esp+0x18]
    push   edx
    push   0x1
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::InsertRepeatedByte
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0x8
    ret
  }
}

// Updates full32 reflected state, publishing the shifted intermediate before loading each table word.
// R6GameService.dll @ 100365d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UpdateReflectedTableChecksum(uint *state,const byte *begin,const byte *end)
{
  __asm {
    // Unsigned begin<end gate avoids state/table reads for empty or reversed ranges; RET8.
    mov    edx,DWORD PTR [esp+0x4]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    cmp    edx,edi
    jae    Branch18
    push   ebx
    push   esi
    nop
  Branch17:
    // Read source byte, state low byte and full state separately; publish shift before table lookup.
    mov    al,BYTE PTR [edx]
    mov    bl,BYTE PTR [ecx]
    mov    esi,DWORD PTR [ecx]
    xor    al,bl
    shr    esi,0x8
    movzx  eax,al
    mov    DWORD PTR [ecx],esi
    mov    eax,DWORD PTR [eax*4+GReflectedChecksumTable]
    xor    eax,esi
    inc    edx
    cmp    edx,edi
    mov    DWORD PTR [ecx],eax
    jb     Branch17
    pop    esi
    pop    ebx
  Branch18:
    pop    edi
    ret    0x8
  }
}

// Updates full32 forward state with polynomial-table words and intermediate-before-lookup publication.
// R6GameService.dll @ 10036610 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UpdateForwardChecksumState(uint *state,const byte *begin,const byte *end)
{
  __asm {
    // Full32 state; high-byte index and left8 shift, with no16-bit truncation or final XOR.
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    esi,edi
    jae    Branch20
    push   ebx
    nop
  Branch19:
    mov    edx,DWORD PTR [ecx]
    mov    bl,BYTE PTR [esi]
    mov    eax,edx
    shr    eax,0x18
    xor    al,bl
    shl    edx,0x8
    movzx  eax,al
    // Intermediate state store precedes lookup, preserving alias/partial-publication effects.
    mov    DWORD PTR [ecx],edx
    mov    eax,DWORD PTR [eax*4+GForwardChecksumTable]
    xor    eax,edx
    inc    esi
    cmp    esi,edi
    mov    DWORD PTR [ecx],eax
    jb     Branch19
    pop    ebx
  Branch20:
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Lazily builds 256 full32 forward checksum words using native polynomial0x1021.
// R6GameService.dll @ 10036650 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeForwardChecksumTable(void)
{
  __asm {
    // Any nonzero raw ready byte skips work. No lock/atomic guard; readiness is stored only after all256 words.
    mov    al,BYTE PTR [GForwardChecksumReady]
    test   al,al
    jne    Branch26
    push   esi
    xor    dl,dl
    mov    esi,R6GameServiceAddresses::GForwardChecksumTable
  Branch21:
    xor    eax,eax
    mov    cl,0x80
  Branch22:
    test   dl,cl
    je     Branch23
    xor    eax,0x80000000
  Branch23:
    test   eax,eax
    jns    Branch24
    add    eax,eax
    xor    eax,0x1021
    jmp    Branch25
  Branch24:
    shl    eax,1
  Branch25:
    shr    cl,1
    test   cl,cl
    jne    Branch22
    // Forward table uses ascending byte index; gate publication follows the wrapping8-bit counter.
    mov    DWORD PTR [esi],eax
    inc    dl
    add    esi,0x4
    test   dl,dl
    jne    Branch21
    mov    BYTE PTR [GForwardChecksumReady],0x1
    pop    esi
  Branch26:
    ret
  }
}

// Lazily builds reflected full32 checksum words from native polynomial0x1025 and reversed byte indices.
// R6GameService.dll @ 100366a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl InitializeReflectedChecksumTable(void)
{
  __asm {
    // Polynomial0x1025 stays native; reverse32 each remainder and reverse8 each destination index.
    mov    al,BYTE PTR [GReflectedChecksumReady]
    test   al,al
    jne    Branch42
    push   ebx
    push   esi
    push   edi
    xor    bl,bl
  Branch27:
    xor    eax,eax
    mov    cl,0x80
  Branch28:
    test   bl,cl
    je     Branch29
    xor    eax,0x80000000
  Branch29:
    test   eax,eax
    jns    Branch30
    add    eax,eax
    xor    eax,0x1025
    jmp    Branch31
  Branch30:
    shl    eax,1
  Branch31:
    shr    cl,1
    test   cl,cl
    jne    Branch28
    mov    edx,eax
    xor    esi,esi
    xor    eax,eax
    lea    ebx,[ebx+0x0]
  Branch32:
    test   dl,0x1
    je     Branch33
    mov    ecx,0x1f
    sub    ecx,eax
    mov    edi,0x1
    shl    edi,cl
    or     esi,edi
  Branch33:
    inc    eax
    shr    edx,1
    cmp    eax,0x20
    jb     Branch32
    xor    cl,cl
    test   bl,0x1
    je     Branch34
    mov    cl,0x80
  Branch34:
    mov    al,bl
    shr    al,1
    test   al,0x1
    je     Branch35
    or     cl,0x40
  Branch35:
    shr    al,1
    test   al,0x1
    je     Branch36
    or     cl,0x20
  Branch36:
    shr    al,1
    test   al,0x1
    je     Branch37
    or     cl,0x10
  Branch37:
    shr    al,1
    test   al,0x1
    je     Branch38
    or     cl,0x8
  Branch38:
    shr    al,1
    test   al,0x1
    je     Branch39
    or     cl,0x4
  Branch39:
    shr    al,1
    test   al,0x1
    je     Branch40
    or     cl,0x2
  Branch40:
    test   al,0x2
    je     Branch41
    or     cl,0x1
  Branch41:
    // INC BL zero flag terminates after256 entries despite intervening MOVZX/table store.
    inc    bl
    movzx  eax,cl
    mov    DWORD PTR [eax*4+GReflectedChecksumTable],esi
    jne    Branch27
    pop    edi
    pop    esi
    mov    BYTE PTR [GReflectedChecksumReady],0x1
    pop    ebx
  Branch42:
    ret
  }
}

// Initializes forward state to0xffff, updates the live byte range and stores/returns the destination.
// R6GameService.dll @ 10036770 : complete native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall UpdateChecksumFromBuffer(uint *destination,const void *byteVector)
{
  __asm {
    // Initial ECX save becomes local state0xffff; final POP ECX exposes computed full32 state, not receiver.
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0xffff
    call   R6GameServiceAddresses::InitializeForwardChecksumTable
    mov    ecx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx+0x4]
    test   eax,eax
    jne    Branch43
    xor    ecx,ecx
    jmp    Branch44
  Branch43:
    mov    ecx,DWORD PTR [ecx+0x8]
    sub    ecx,eax
  Branch44:
    // Null begin forces zero endpoints; unsigned updater receives raw begin/end otherwise.
    add    ecx,eax
    push   ecx
    push   eax
    lea    ecx,[esp+0xc]
    call   R6GameServiceAddresses::UpdateForwardChecksumState
    mov    eax,DWORD PTR [esp+0x4]
    mov    DWORD PTR [esi],eax
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x4
  }
}

// Initializes reflected state to0xffffffff, updates the unsigned byte range and returns it without final XOR.
// R6GameService.dll @ 100367b0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl checksum_support_UpdateChecksumFromBuffer(const void *byteVector)
{
  __asm {
    // Retain native bit-reversal loop of0xffffffff before table initialization, without simplifying control flow.
    push   ecx
    push   ebx
    or     ebx,0xffffffff
    xor    edx,edx
    push   esi
    xor    eax,eax
    lea    ebx,[ebx+0x0]
  Branch45:
    test   bl,0x1
    je     Branch46
    mov    ecx,0x1f
    sub    ecx,eax
    mov    esi,0x1
    shl    esi,cl
    or     edx,esi
  Branch46:
    inc    eax
    shr    ebx,1
    cmp    eax,0x20
    jb     Branch45
    mov    DWORD PTR [esp+0x8],edx
    call   R6GameServiceAddresses::InitializeReflectedChecksumTable
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [ecx+0x4]
    test   eax,eax
    pop    esi
    pop    ebx
    jne    Branch47
    // Null begin bypasses end field read; returned EAX and popped ECX both hold final raw state.
    xor    ecx,ecx
    mov    ecx,eax
    push   ecx
    push   eax
    lea    ecx,[esp+0x8]
    call   R6GameServiceAddresses::UpdateReflectedTableChecksum
    mov    eax,DWORD PTR [esp]
    pop    ecx
    ret
  Branch47:
    mov    ecx,DWORD PTR [ecx+0x8]
    sub    ecx,eax
    add    ecx,eax
    push   ecx
    push   eax
    lea    ecx,[esp+0x8]
    call   R6GameServiceAddresses::UpdateReflectedTableChecksum
    mov    eax,DWORD PTR [esp]
    pop    ecx
    ret
  }
}
