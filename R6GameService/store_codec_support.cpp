#include "native_addresses.h"

// Shared serialized-store tag and cursor codec helpers; original class/template ownership remains unresolved.

// Returns status02130000 for low nibbleE,02130001 otherwise, and82170057 for null input; ECX is unused.
// R6GameService.dll @ 10019120 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CheckStoreBlobTagE(const byte *input)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    test   eax,eax
    jne    Branch1
    mov    eax,0x82170057
    ret    0x4
  Branch1:
    mov    al,BYTE PTR [eax]
    xor    ecx,ecx
    and    al,0xf
    cmp    al,0xe
    setne  cl
    add    ecx,0x2130000
    mov    eax,ecx
    ret    0x4
  }
}

// Reads markerF and selector-sized byte/entry counts plus key addend, publishing optional outputs in native order.
// Cursor/mask stores and original argument scratch retain aliases; invalid marker advances first and returns failure.
// R6GameService.dll @ 1001d0c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DecodeSerializedStoreHeader(
    uint *cursor,byte *mask,uint *bytes,uint *entries,byte *tag,uint *addend)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x1c]
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    test   edi,edi
    je     Branch5
    test   esi,esi
    je     Branch5
    mov    ebp,DWORD PTR [edi]
    mov    al,BYTE PTR [esi]
    cmp    al,0x1
    mov    bl,BYTE PTR [ebp+0x0]
    jne    Branch2
    mov    al,bl
    jmp    Branch6
  Branch2:
    xor    edx,edx
    shr    al,1
    je     Branch4
  Branch3:
    inc    edx
    shr    al,1
    jne    Branch3
  Branch4:
    mov    al,BYTE PTR [ebp+0x1]
    mov    ecx,0x8
    sub    ecx,edx
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    jmp    Branch6
  Branch5:
    xor    al,al
  Branch6:
    test   edi,edi
    je     Branch9
    test   esi,esi
    je     Branch9
    mov    cl,BYTE PTR [esi]
    shr    cl,1
    je     Branch8
  Branch7:
    shr    cl,1
    jne    Branch7
  Branch8:
    mov    ecx,DWORD PTR [edi]
    inc    ecx
    mov    DWORD PTR [edi],ecx
    mov    cl,BYTE PTR [esi]
    mov    BYTE PTR [esi],cl
  Branch9:
    mov    dl,al
    and    dl,0xf
    cmp    dl,0xf
    je     Branch10
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x82136202
    pop    ebx
    add    esp,0x8
    ret    0x18
  Branch10:
    mov    ebp,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    shr    al,0x4
    mov    BYTE PTR [esp+0x1c],al
    mov    al,BYTE PTR [ebp+0x0]
    xor    ebx,ebx
    test   dl,al
    mov    al,dl
    mov    DWORD PTR [esp+0x20],ebx
    seta   BYTE PTR [esp+0x10]
    shr    al,1
    je     Branch12
  Branch11:
    inc    ebx
    shr    al,1
    jne    Branch11
  Branch12:
    mov    ecx,0x7
    sub    ecx,ebx
    cmp    ecx,0x1
    jae    Branch13
    neg    ecx
    mov    al,0x1
    inc    ebp
    shl    al,cl
    mov    DWORD PTR [edi],ebp
    mov    BYTE PTR [esi],al
    jmp    Branch14
  Branch13:
    add    dl,dl
    mov    BYTE PTR [esi],dl
  Branch14:
    mov    ecx,DWORD PTR [edi]
    mov    bl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    dl,BYTE PTR [ecx]
    mov    cl,BYTE PTR [esp+0x18]
    test   bl,dl
    seta   al
    add    al,al
    push   edi
    or     cl,al
    mov    BYTE PTR [esp+0x1c],cl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x10]
    and    eax,0xff
    cmp    eax,0x3
    ja     Branch16
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GStoreSelectorTargets]
    lea    ecx,[esp+0x20]
    push   0x1
    push   ecx
    push   0x1
    jmp    Branch15
    lea    edx,[esp+0x20]
    push   0x1
    push   edx
    push   0x2
    jmp    Branch15
    lea    eax,[esp+0x20]
    push   0x1
    push   eax
    push   0x3
    jmp    Branch15
    lea    ecx,[esp+0x20]
    push   0x1
    push   ecx
    push   0x4
  Branch15:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    DWORD PTR [esp+0x20],eax
  Branch16:
    mov    ebp,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    xor    ebx,ebx
    mov    al,BYTE PTR [ebp+0x0]
    mov    DWORD PTR [esp+0x10],ebx
    test   dl,al
    mov    al,dl
    seta   BYTE PTR [esp+0x14]
    shr    al,1
    je     Branch18
  Branch17:
    inc    ebx
    shr    al,1
    jne    Branch17
  Branch18:
    mov    ecx,0x7
    sub    ecx,ebx
    cmp    ecx,0x1
    jae    Branch19
    inc    ebp
    mov    dl,0x1
    neg    ecx
    mov    DWORD PTR [edi],ebp
    shl    dl,cl
    jmp    Branch20
  Branch19:
    add    dl,dl
  Branch20:
    mov    BYTE PTR [esi],dl
    mov    eax,DWORD PTR [edi]
    push   0x1
    push   esi
    mov    cl,BYTE PTR [eax]
    mov    al,dl
    test   al,cl
    mov    cl,BYTE PTR [esp+0x1c]
    push   edi
    seta   dl
    add    dl,dl
    or     cl,dl
    mov    BYTE PTR [esp+0x20],cl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x14]
    and    eax,0xff
    cmp    eax,0x3
    ja     Branch22
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets]
    lea    eax,[esp+0x14]
    push   0x1
    push   eax
    push   0x1
    jmp    Branch21
    lea    ecx,[esp+0x14]
    push   0x1
    push   ecx
    push   0x2
    jmp    Branch21
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    push   0x3
    jmp    Branch21
    lea    eax,[esp+0x14]
    push   0x1
    push   eax
    push   0x4
  Branch21:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    DWORD PTR [esp+0x10],eax
  Branch22:
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreSelectorInteger
    mov    ecx,DWORD PTR [esp+0x24]
    test   ecx,ecx
    je     Branch23
    mov    edx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [ecx],edx
  Branch23:
    mov    ecx,DWORD PTR [esp+0x28]
    test   ecx,ecx
    je     Branch24
    mov    edx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [ecx],edx
  Branch24:
    mov    ecx,DWORD PTR [esp+0x2c]
    test   ecx,ecx
    je     Branch25
    mov    dl,BYTE PTR [esp+0x1c]
    mov    BYTE PTR [ecx],dl
  Branch25:
    mov    ecx,DWORD PTR [esp+0x30]
    test   ecx,ecx
    je     Branch26
    mov    DWORD PTR [ecx],eax
  Branch26:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x2130000
    pop    ebx
    add    esp,0x8
    ret    0x18
  }
}

// Reads a two-bit selector and one through four little-endian bytes, then publishes selector byte and consumed bits.
// Argument/output aliases and raw byte-mask/cursor reloads retain native order; no bounds validation is added.
// R6GameService.dll @ 1001d300 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReadStoreSelectorInteger(uint *cursor,byte *mask,byte *selector,uint *bits)
{
  __asm {
    sub    esp,0x8
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x1c]
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    al,BYTE PTR [esi]
    xor    edx,edx
    mov    ebx,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x10],edx
    xor    ebp,ebp
    mov    cl,BYTE PTR [ebx]
    mov    DWORD PTR [esp+0x14],ebp
    test   cl,al
    mov    cl,al
    seta   BYTE PTR [esp+0x1c]
    shr    cl,1
    je     Branch28
  Branch27:
    inc    ebp
    shr    cl,1
    jne    Branch27
  Branch28:
    mov    ecx,0x7
    sub    ecx,ebp
    cmp    ecx,0x1
    jae    Branch29
    inc    ebx
    mov    al,0x1
    neg    ecx
    mov    DWORD PTR [edi],ebx
    shl    al,cl
    jmp    Branch30
  Branch29:
    add    al,al
  Branch30:
    mov    BYTE PTR [esi],al
    mov    ebp,DWORD PTR [edi]
    mov    bl,al
    mov    al,BYTE PTR [esp+0x1c]
    test   BYTE PTR [ebp+0x0],bl
    seta   cl
    add    cl,cl
    or     al,cl
    xor    ecx,ecx
    mov    BYTE PTR [esp+0x1c],al
    mov    al,bl
    shr    al,1
    mov    DWORD PTR [esp+0x20],ecx
    je     Branch32
  Branch31:
    inc    ecx
    shr    al,1
    jne    Branch31
    mov    DWORD PTR [esp+0x20],ecx
  Branch32:
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,0x7
    sub    ecx,eax
    cmp    ecx,0x1
    jae    Branch33
    neg    ecx
    mov    al,0x1
    inc    ebp
    shl    al,cl
    mov    DWORD PTR [edi],ebp
    mov    BYTE PTR [esi],al
    jmp    Branch34
  Branch33:
    add    bl,bl
    mov    BYTE PTR [esi],bl
  Branch34:
    mov    eax,DWORD PTR [esp+0x1c]
    and    eax,0xff
    cmp    eax,0x3
    ja     Branch50
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets2]
    mov    ebp,DWORD PTR [edi]
    mov    al,BYTE PTR [esi]
    cmp    al,0x1
    mov    bl,BYTE PTR [ebp+0x0]
    jne    Branch35
    mov    BYTE PTR [esp+0x20],bl
    jmp    Branch38
  Branch35:
    xor    edx,edx
    shr    al,1
    je     Branch37
  Branch36:
    inc    edx
    shr    al,1
    jne    Branch36
  Branch37:
    mov    al,BYTE PTR [ebp+0x1]
    mov    ecx,0x8
    sub    ecx,edx
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [esp+0x20],al
  Branch38:
    mov    ebx,DWORD PTR [esp+0x20]
    push   0x8
    push   esi
    push   edi
    and    ebx,0xff
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,0x8
    mov    eax,ebx
    jmp    Branch51
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x20],ebp
  Branch39:
    mov    eax,DWORD PTR [edi]
    mov    bl,BYTE PTR [eax]
    mov    al,BYTE PTR [esi]
    cmp    al,0x1
    jne    Branch40
    mov    BYTE PTR [esp+0x14],bl
    jmp    Branch43
  Branch40:
    xor    edx,edx
    shr    al,1
    je     Branch42
  Branch41:
    inc    edx
    shr    al,1
    jne    Branch41
  Branch42:
    mov    eax,DWORD PTR [edi]
    mov    ecx,0x8
    sub    ecx,edx
    mov    al,BYTE PTR [eax+0x1]
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [esp+0x14],al
  Branch43:
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,ebp
    and    edx,0xff
    push   0x8
    shl    edx,cl
    mov    ecx,DWORD PTR [esp+0x24]
    push   esi
    push   edi
    or     ecx,edx
    mov    DWORD PTR [esp+0x2c],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,0x10
    add    ebp,0x8
    cmp    ebp,edx
    mov    DWORD PTR [esp+0x10],edx
    jb     Branch39
    mov    eax,DWORD PTR [esp+0x20]
    jmp    Branch51
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x20],ebp
  Branch44:
    mov    eax,DWORD PTR [edi]
    mov    bl,BYTE PTR [eax]
    mov    al,BYTE PTR [esi]
    cmp    al,0x1
    jne    Branch45
    mov    BYTE PTR [esp+0x14],bl
    jmp    Branch48
  Branch45:
    xor    edx,edx
    shr    al,1
    je     Branch47
  Branch46:
    inc    edx
    shr    al,1
    jne    Branch46
  Branch47:
    mov    eax,DWORD PTR [edi]
    mov    ecx,0x8
    sub    ecx,edx
    mov    al,BYTE PTR [eax+0x1]
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [esp+0x14],al
  Branch48:
    mov    edx,DWORD PTR [esp+0x14]
    mov    ecx,ebp
    and    edx,0xff
    push   0x8
    shl    edx,cl
    mov    ecx,DWORD PTR [esp+0x24]
    push   esi
    push   edi
    or     ecx,edx
    mov    DWORD PTR [esp+0x2c],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,0x18
    add    ebp,0x8
    cmp    ebp,edx
    mov    DWORD PTR [esp+0x10],edx
    jb     Branch44
    mov    eax,DWORD PTR [esp+0x20]
    jmp    Branch51
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x20],ebp
  Branch49:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,ebp
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x20]
    push   0x8
    push   esi
    push   edi
    or     ecx,eax
    mov    DWORD PTR [esp+0x2c],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,0x20
    add    ebp,0x8
    cmp    ebp,edx
    mov    DWORD PTR [esp+0x10],edx
    jb     Branch49
    mov    eax,DWORD PTR [esp+0x20]
    jmp    Branch51
  Branch50:
    mov    eax,DWORD PTR [esp+0x14]
  Branch51:
    mov    esi,DWORD PTR [esp+0x24]
    test   esi,esi
    je     Branch52
    mov    cl,BYTE PTR [esp+0x1c]
    mov    BYTE PTR [esi],cl
  Branch52:
    mov    ecx,DWORD PTR [esp+0x28]
    pop    edi
    pop    esi
    pop    ebp
    test   ecx,ecx
    pop    ebx
    je     Branch53
    add    edx,0x2
    mov    DWORD PTR [ecx],edx
  Branch53:
    add    esp,0x8
    ret    0x10
  }
}

// Reads across the current highest mask bit without advancing; semantic byte and raw upper EAX remain explicit.
// Zero/nonunit masks still read the following byte; missing slots clear AL only where the native branch does.
// R6GameService.dll @ 10019cd0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReadCursorByte(uint *cursor,byte *mask)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    push   ebx
    test   ecx,ecx
    push   esi
    je     Branch57
    mov    eax,DWORD PTR [esp+0x10]
    test   eax,eax
    je     Branch57
    mov    esi,DWORD PTR [ecx]
    mov    al,BYTE PTR [eax]
    cmp    al,0x1
    mov    bl,BYTE PTR [esi]
    jne    Branch54
    mov    al,bl
    pop    esi
    pop    ebx
    ret    0x8
  Branch54:
    xor    edx,edx
    shr    al,1
    je     Branch56
  Branch55:
    inc    edx
    shr    al,1
    jne    Branch55
  Branch56:
    mov    al,BYTE PTR [esi+0x1]
    mov    ecx,0x8
    sub    ecx,edx
    pop    esi
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    pop    ebx
    ret    0x8
  Branch57:
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x8
  }
}

// Advances from the current mask highest bit, retaining noncanonical masks, aliases and modulo arithmetic.
// R6GameService.dll @ 10019900 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall AdvanceBitCursor(uint *cursor,byte *mask,uint count)
{
  __asm {
    push   ebp
    mov    ebp,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    test   ebp,ebp
    je     Branch61
    mov    edi,DWORD PTR [esp+0x14]
    test   edi,edi
    je     Branch61
    mov    eax,DWORD PTR [esp+0x18]
    push   ebx
    mov    bl,BYTE PTR [edi]
    mov    edx,eax
    and    eax,0x7
    mov    ecx,eax
    xor    eax,eax
    shr    edx,0x3
    shr    bl,1
    je     Branch59
  Branch58:
    inc    eax
    shr    bl,1
    jne    Branch58
  Branch59:
    mov    esi,0x7
    pop    ebx
    sub    esi,eax
    cmp    esi,ecx
    jae    Branch60
    mov    eax,DWORD PTR [ebp+0x0]
    inc    edx
    add    eax,edx
    sub    ecx,esi
    mov    DWORD PTR [ebp+0x0],eax
    dec    ecx
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [edi],al
    pop    edi
    pop    esi
    pop    ebp
    ret    0xc
  Branch60:
    mov    esi,DWORD PTR [ebp+0x0]
    add    esi,edx
    mov    DWORD PTR [ebp+0x0],esi
    mov    al,BYTE PTR [edi]
    shl    al,cl
    mov    BYTE PTR [edi],al
  Branch61:
    pop    edi
    pop    esi
    pop    ebp
    ret    0xc
  }
}

// Reads fixed little-endian bytes or a zero-width sentinel bit code using the native cursor and scratch words.
// Fixed shifts wrap32 bits; low mode byte controls extra terminator consumption, with live optional count outputs.
// R6GameService.dll @ 10019d20 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReadStoreBitCodeValue(uint *cursor,byte *mask,uint bytes,uint *bits,uint mode)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    sub    esp,0xc
    xor    eax,eax
    push   ebx
    push   ebp
    push   esi
    cmp    edx,eax
    push   edi
    jne    Branch75
    mov    esi,DWORD PTR [esp+0x24]
    mov    ebx,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x10],eax
    lea    eax,[esp+0x18]
    mov    BYTE PTR [esp+0x28],0x1
    mov    DWORD PTR [esp+0x14],eax
  Branch62:
    mov    edi,DWORD PTR [ebx]
    mov    dl,BYTE PTR [esi]
    test   BYTE PTR [edi],dl
    seta   BYTE PTR [esp+0x24]
    mov    al,dl
    xor    ebp,ebp
    shr    al,1
    je     Branch64
  Branch63:
    inc    ebp
    shr    al,1
    jne    Branch63
  Branch64:
    mov    ecx,0x7
    sub    ecx,ebp
    cmp    ecx,0x1
    jae    Branch65
    inc    edi
    mov    dl,0x1
    neg    ecx
    mov    DWORD PTR [ebx],edi
    shl    dl,cl
    jmp    Branch66
  Branch65:
    add    dl,dl
  Branch66:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    al,BYTE PTR [esp+0x24]
    inc    ecx
    mov    BYTE PTR [esi],dl
    test   al,al
    mov    DWORD PTR [esp+0x10],ecx
    jne    Branch67
    mov    eax,DWORD PTR [ebx]
    mov    cl,BYTE PTR [eax]
    test   dl,cl
    seta   al
    test   al,al
    mov    BYTE PTR [esp+0x24],al
    jne    Branch68
    push   0x1
    push   esi
    push   ebx
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    DWORD PTR [esp+0x10]
  Branch67:
    mov    edx,DWORD PTR [esp+0x24]
    push   0x1
    lea    eax,[esp+0x2c]
    push   edx
    lea    ecx,[esp+0x1c]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::WriteCursorBits
    lea    edx,[esp+0x28]
    push   0x1
    lea    eax,[esp+0x18]
    push   edx
    push   eax
    call   R6GameServiceAddresses::AdvanceBitCursor
    jmp    Branch62
  Branch68:
    mov    al,BYTE PTR [esp+0x30]
    test   al,al
    jne    Branch73
    mov    dl,BYTE PTR [esi]
    xor    edi,edi
    mov    al,dl
    shr    al,1
    je     Branch70
  Branch69:
    inc    edi
    shr    al,1
    jne    Branch69
  Branch70:
    mov    ecx,0x7
    sub    ecx,edi
    cmp    ecx,0x1
    jae    Branch71
    mov    edi,DWORD PTR [ebx]
    mov    dl,0x1
    inc    edi
    neg    ecx
    mov    DWORD PTR [ebx],edi
    shl    dl,cl
    jmp    Branch72
  Branch71:
    add    dl,dl
  Branch72:
    mov    eax,DWORD PTR [esp+0x10]
    mov    BYTE PTR [esi],dl
    inc    eax
    mov    DWORD PTR [esp+0x10],eax
  Branch73:
    mov    eax,DWORD PTR [esp+0x2c]
    test   eax,eax
    je     Branch74
    mov    ecx,DWORD PTR [esp+0x10]
    mov    DWORD PTR [eax],ecx
  Branch74:
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x14
  Branch75:
    cmp    edx,eax
    mov    DWORD PTR [esp+0x14],eax
    jbe    Branch86
    mov    ebp,DWORD PTR [esp+0x24]
    mov    edi,DWORD PTR [esp+0x20]
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x18],edx
  Branch76:
    test   edi,edi
    je     Branch80
    test   ebp,ebp
    je     Branch80
    mov    esi,DWORD PTR [edi]
    mov    cl,BYTE PTR [ebp+0x0]
    cmp    cl,0x1
    mov    al,BYTE PTR [esi]
    jne    Branch77
    mov    BYTE PTR [esp+0x30],al
    jmp    Branch81
  Branch77:
    xor    edx,edx
    shr    cl,1
    je     Branch79
  Branch78:
    inc    edx
    shr    cl,1
    jne    Branch78
  Branch79:
    mov    bl,BYTE PTR [esi+0x1]
    mov    ecx,0x8
    sub    ecx,edx
    shl    bl,cl
    mov    cl,dl
    mov    edx,DWORD PTR [esp+0x28]
    shr    al,cl
    or     bl,al
    mov    BYTE PTR [esp+0x30],bl
    jmp    Branch81
  Branch80:
    mov    BYTE PTR [esp+0x30],0x0
  Branch81:
    mov    eax,DWORD PTR [esp+0x30]
    mov    ecx,DWORD PTR [esp+0x10]
    and    eax,0xff
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x14]
    or     ecx,eax
    test   edi,edi
    mov    DWORD PTR [esp+0x14],ecx
    je     Branch84
    test   ebp,ebp
    je     Branch84
    mov    al,BYTE PTR [ebp+0x0]
    shr    al,1
    je     Branch83
  Branch82:
    shr    al,1
    jne    Branch82
  Branch83:
    mov    eax,DWORD PTR [edi]
    inc    eax
    mov    DWORD PTR [edi],eax
    mov    cl,BYTE PTR [ebp+0x0]
    mov    BYTE PTR [ebp+0x0],cl
  Branch84:
    mov    eax,DWORD PTR [esp+0x2c]
    test   eax,eax
    je     Branch85
    lea    ecx,[edx*8+0x0]
    mov    DWORD PTR [eax],ecx
  Branch85:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0x18]
    add    ecx,0x8
    dec    eax
    mov    DWORD PTR [esp+0x10],ecx
    mov    DWORD PTR [esp+0x18],eax
    jne    Branch76
  Branch86:
    mov    eax,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x14
  }
}

// R6GameService.dll data @ 1001d2dc : selected store selector dispatch.
const uint GStoreSelectorTargets[4] = {R6GameServiceAddresses::GStoreSelectorTargetsCase1,R6GameServiceAddresses::GStoreSelectorTargetsCase2,R6GameServiceAddresses::GStoreSelectorTargetsCase3,R6GameServiceAddresses::GStoreSelectorTargetsCase4};

// R6GameService.dll data @ 1001d2ec : selected store selector dispatch.
const uint store_codec_supportGStoreSelectorTargets[4] = {R6GameServiceAddresses::store_codec_supportGStoreSelectorTargetsCase1,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargetsCase2,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargetsCase3,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargetsCase4};

// R6GameService.dll data @ 1001d550 : selected store selector dispatch.
const uint store_codec_supportGStoreSelectorTargets2[4] = {R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets2Case1,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets2Case2,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets2Case3,R6GameServiceAddresses::store_codec_supportGStoreSelectorTargets2Case4};

// Initializes a56-byte inflater descriptor, finishes once and releases initialized state.
// Stream end publishes total_out before release and returns release status; zero progress maps to minus5.
// R6GameService.dll @ 1001dae0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall InflateBuffer(
    void *destination,uint *destinationSize,const void *source,uint sourceSize)
{
  __asm {
    sub    esp,0x38
    mov    ecx,DWORD PTR [esp+0x48]
    mov    eax,DWORD PTR [esp+0x44]
    mov    edx,DWORD PTR [esp+0x3c]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x48]
    mov    DWORD PTR [esp+0xc],ecx
    mov    DWORD PTR [esp+0x8],eax
    mov    eax,DWORD PTR [edi]
    push   0x38
    lea    ecx,[esp+0xc]
    push   R6GameServiceAddresses::Text114
    push   ecx
    mov    DWORD PTR [esp+0x20],edx
    mov    DWORD PTR [esp+0x24],eax
    mov    DWORD PTR [esp+0x34],0x0
    mov    DWORD PTR [esp+0x38],0x0
    call   R6GameServiceAddresses::InflateInit
    test   eax,eax
    jne    Branch88
    lea    edx,[esp+0x8]
    push   0x4
    push   edx
    call   R6GameServiceAddresses::InflateStream
    mov    esi,eax
    cmp    esi,0x1
    je     Branch87
    lea    eax,[esp+0x8]
    push   eax
    call   R6GameServiceAddresses::ReleaseInflaterState
    test   esi,esi
    mov    eax,0xfffffffb
    je     Branch88
    mov    eax,esi
    pop    edi
    pop    esi
    add    esp,0x38
    ret    0x10
  Branch87:
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    edx,[esp+0x8]
    push   edx
    mov    DWORD PTR [edi],ecx
    call   R6GameServiceAddresses::ReleaseInflaterState
  Branch88:
    pop    edi
    pop    esi
    add    esp,0x38
    ret    0x10
  }
}

// Initializes a56-byte deflater descriptor at the requested level, finishes once and releases initialized state.
// Only stream end publishes total_out before release; init/step errors and raw release return retain native order.
// R6GameService.dll @ 1001db80 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DeflateBuffer(
    void *destination,uint *destinationSize,const void *source,uint sourceSize,int level)
{
  __asm {
    sub    esp,0x38
    mov    ecx,DWORD PTR [esp+0x48]
    mov    edx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [esp+0x44]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x44]
    push   esi
    mov    DWORD PTR [esp+0xc],ecx
    mov    ecx,DWORD PTR [esp+0x54]
    mov    DWORD PTR [esp+0x14],edx
    push   0x38
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [ebx]
    push   R6GameServiceAddresses::Text114
    lea    edx,[esp+0x10]
    push   ecx
    push   edx
    mov    DWORD PTR [esp+0x28],eax
    mov    DWORD PTR [esp+0x38],0x0
    mov    DWORD PTR [esp+0x3c],0x0
    mov    DWORD PTR [esp+0x40],0x0
    call   R6GameServiceAddresses::DeflateInit
    test   eax,eax
    jne    Branch90
    lea    eax,[esp+0x8]
    push   0x4
    push   eax
    call   R6GameServiceAddresses::DeflateStreamStep
    mov    esi,eax
    cmp    esi,0x1
    je     Branch89
    lea    ecx,[esp+0x8]
    push   ecx
    call   R6GameServiceAddresses::EndDeflateStream
    test   esi,esi
    mov    eax,0xfffffffb
    je     Branch90
    mov    eax,esi
    pop    esi
    pop    ebx
    add    esp,0x38
    ret    0x14
  Branch89:
    mov    edx,DWORD PTR [esp+0x1c]
    lea    eax,[esp+0x8]
    push   eax
    mov    DWORD PTR [ebx],edx
    call   R6GameServiceAddresses::EndDeflateStream
  Branch90:
    pop    esi
    pop    ebx
    add    esp,0x38
    ret    0x14
  }
}

// Writes minimal little-endian bytes or low-to-high00/1 bits and a selected terminator, advancing the cursor.
// Four-byte output reports24 bits; cached fields, late output/terminal words and argument scratch remain native.
// R6GameService.dll @ 10019490 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall WriteStoreInteger(
    uint *cursor,byte *mask,uint value,uint mode,uint *bits,uint terminalMode)
{
  __asm {
    push   ecx
    mov    al,BYTE PTR [esp+0x14]
    push   ebx
    push   ebp
    push   esi
    test   al,al
    push   edi
    je     Branch97
    mov    eax,DWORD PTR [esp+0x20]
    lea    ecx,[esp+0x10]
    push   eax
    mov    DWORD PTR [esp+0x14],eax
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x24],ecx
    mov    BYTE PTR [esp+0x28],0x1
    call   R6GameServiceAddresses::HighestSetBitIndex
    inc    eax
    mov    esi,DWORD PTR [esp+0x1c]
    mov    edi,DWORD PTR [esp+0x18]
    je     Branch94
    mov    DWORD PTR [esp+0x1c],eax
  Branch91:
    mov    edx,DWORD PTR [esp+0x20]
    mov    al,BYTE PTR [esp+0x24]
    push   0x1
    mov    cl,BYTE PTR [edx]
    lea    edx,[esp+0x24]
    test   al,cl
    lea    ecx,[esp+0x28]
    seta   bl
    push   ecx
    push   edx
    mov    BYTE PTR [esp+0x24],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    test   bl,bl
    jne    Branch92
    push   0x2
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x2
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x2
    jmp    Branch93
  Branch92:
    mov    eax,DWORD PTR [esp+0x18]
    push   0x1
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x1
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    ebp
  Branch93:
    mov    eax,DWORD PTR [esp+0x1c]
    dec    eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch91
  Branch94:
    mov    al,BYTE PTR [esp+0x2c]
    test   al,al
    je     Branch95
    push   0x1
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x1
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    ebp
    jmp    Branch96
  Branch95:
    push   0x2
    push   0x2
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x2
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x2
  Branch96:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch123
    pop    edi
    mov    DWORD PTR [eax],ebp
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x18
  Branch97:
    mov    ebx,DWORD PTR [esp+0x20]
    cmp    ebx,0xff
    ja     Branch104
    mov    edi,DWORD PTR [esp+0x18]
    test   edi,edi
    je     Branch103
    mov    edx,DWORD PTR [esp+0x1c]
    test   edx,edx
    je     Branch103
    mov    al,BYTE PTR [edx]
    xor    esi,esi
    shr    al,1
    je     Branch99
  Branch98:
    inc    esi
    shr    al,1
    jne    Branch98
  Branch99:
    mov    ebp,DWORD PTR [edi]
    or     al,0xff
    mov    ecx,esi
    shl    al,cl
    mov    cl,BYTE PTR [ebp+0x0]
    not    al
    and    cl,al
    mov    al,bl
    mov    BYTE PTR [ebp+0x0],cl
    mov    ebp,DWORD PTR [edi]
    mov    ecx,esi
    shl    al,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,al
    test   esi,esi
    mov    BYTE PTR [ebp+0x0],cl
    je     Branch100
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,esi
    mov    esi,DWORD PTR [edi]
    sar    edx,cl
    mov    al,BYTE PTR [esi+0x1]
    shr    bl,cl
    not    dl
    and    al,dl
    mov    edx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [esi+0x1],al
    mov    eax,DWORD PTR [edi]
    or     BYTE PTR [eax+0x1],bl
  Branch100:
    mov    al,BYTE PTR [edx]
    shr    al,1
    je     Branch102
  Branch101:
    shr    al,1
    jne    Branch101
  Branch102:
    mov    eax,DWORD PTR [edi]
    inc    eax
    mov    DWORD PTR [edi],eax
    mov    al,BYTE PTR [edx]
    mov    BYTE PTR [edx],al
  Branch103:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch123
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],0x8
    pop    ebx
    pop    ecx
    ret    0x18
  Branch104:
    cmp    ebx,0xffff
    ja     Branch117
    mov    esi,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x1c]
    test   esi,esi
    je     Branch110
    test   edx,edx
    je     Branch110
    mov    al,BYTE PTR [edx]
    xor    edi,edi
    shr    al,1
    je     Branch106
  Branch105:
    inc    edi
    shr    al,1
    jne    Branch105
  Branch106:
    mov    ebp,DWORD PTR [esi]
    or     al,0xff
    mov    ecx,edi
    shl    al,cl
    mov    cl,BYTE PTR [ebp+0x0]
    not    al
    and    cl,al
    mov    al,bl
    mov    BYTE PTR [ebp+0x0],cl
    mov    ebp,DWORD PTR [esi]
    mov    ecx,edi
    shl    al,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,al
    test   edi,edi
    mov    BYTE PTR [ebp+0x0],cl
    je     Branch107
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,edi
    mov    edi,DWORD PTR [esi]
    sar    edx,cl
    mov    al,BYTE PTR [edi+0x1]
    not    dl
    and    al,dl
    mov    edx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [edi+0x1],al
    mov    edi,DWORD PTR [esi]
    mov    al,bl
    shr    al,cl
    or     BYTE PTR [edi+0x1],al
  Branch107:
    mov    al,BYTE PTR [edx]
    shr    al,1
    je     Branch109
  Branch108:
    shr    al,1
    jne    Branch108
  Branch109:
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    cl,BYTE PTR [edx]
    mov    BYTE PTR [edx],cl
  Branch110:
    shr    ebx,0x8
    test   esi,esi
    je     Branch116
    test   edx,edx
    je     Branch116
    mov    al,BYTE PTR [edx]
    xor    edi,edi
    shr    al,1
    je     Branch112
  Branch111:
    inc    edi
    shr    al,1
    jne    Branch111
  Branch112:
    mov    ebp,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,edi
    mov    al,BYTE PTR [ebp+0x0]
    shl    dl,cl
    not    dl
    and    al,dl
    mov    BYTE PTR [ebp+0x0],al
    mov    ebp,DWORD PTR [esi]
    mov    al,bl
    shl    al,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,al
    test   edi,edi
    mov    BYTE PTR [ebp+0x0],cl
    je     Branch113
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,edi
    mov    edi,DWORD PTR [esi]
    sar    edx,cl
    mov    al,BYTE PTR [edi+0x1]
    shr    bl,cl
    not    dl
    and    al,dl
    mov    BYTE PTR [edi+0x1],al
    mov    eax,DWORD PTR [esi]
    or     BYTE PTR [eax+0x1],bl
  Branch113:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    al,BYTE PTR [ecx]
    shr    al,1
    je     Branch115
  Branch114:
    shr    al,1
    jne    Branch114
  Branch115:
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    al,BYTE PTR [ecx]
    mov    BYTE PTR [ecx],al
  Branch116:
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch123
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [eax],0x10
    pop    ebx
    pop    ecx
    ret    0x18
  Branch117:
    cmp    ebx,0xffffff
    ja     Branch121
    mov    esi,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [esp+0x1c]
    test   esi,esi
    je     Branch120
    test   ebp,ebp
    je     Branch120
    mov    al,BYTE PTR [ebp+0x0]
    xor    edi,edi
    shr    al,1
    je     Branch119
  Branch118:
    inc    edi
    shr    al,1
    jne    Branch118
  Branch119:
    mov    eax,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,edi
    shl    dl,cl
    mov    cl,BYTE PTR [eax]
    not    dl
    and    cl,dl
    mov    dl,bl
    mov    BYTE PTR [eax],cl
    mov    eax,DWORD PTR [esi]
    mov    ecx,edi
    shl    dl,cl
    mov    cl,BYTE PTR [eax]
    or     cl,dl
    test   edi,edi
    mov    BYTE PTR [eax],cl
    je     Branch120
    mov    ecx,0x8
    mov    eax,0xff
    sub    ecx,edi
    mov    edi,DWORD PTR [esi]
    sar    eax,cl
    mov    dl,BYTE PTR [edi+0x1]
    not    al
    and    dl,al
    mov    BYTE PTR [edi+0x1],dl
    mov    edi,DWORD PTR [esi]
    mov    dl,bl
    mov    al,BYTE PTR [edi+0x1]
    shr    dl,cl
    or     al,dl
    mov    BYTE PTR [edi+0x1],al
  Branch120:
    push   0x8
    push   ebp
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebx,0x8
    push   ebx
    push   ebp
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   ebp
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebx,0x8
    push   ebx
    push   ebp
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   ebp
    push   esi
    jmp    Branch122
  Branch121:
    mov    esi,DWORD PTR [esp+0x1c]
    mov    edi,DWORD PTR [esp+0x18]
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebx,0x8
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebx,0x8
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebx,0x8
    push   ebx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   esi
    push   edi
  Branch122:
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x28]
    test   eax,eax
    je     Branch123
    mov    DWORD PTR [eax],0x18
  Branch123:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x18
  }
}

// Returns the highest set bit index by scanning the stacked value bytes, or minus1 for zero.
// R6GameService.dll @ 10019850 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall HighestSetBitIndex(uint value)
{
  __asm {
    push   esi
    lea    edx,[esp+0xb]
    mov    esi,0x4
  Branch124:
    mov    cl,BYTE PTR [edx]
    dec    edx
    test   cl,cl
    je     Branch126
  Branch125:
    mov    al,cl
    neg    al
    and    al,cl
    xor    cl,al
    jne    Branch125
    test   al,al
    jne    Branch127
  Branch126:
    dec    esi
    jne    Branch124
    or     eax,0xffffffff
    pop    esi
    ret    0x4
  Branch127:
    dec    esi
    xor    ecx,ecx
    shr    al,1
    je     Branch129
  Branch128:
    inc    ecx
    shr    al,1
    jne    Branch128
  Branch129:
    lea    eax,[ecx+esi*8]
    pop    esi
    ret    0x4
  }
}

// Replaces eight bits without advancing, preserving surrounding bits and reloading the cursor after each store.
// R6GameService.dll @ 10019890 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall WriteCursorByte(uint *cursor,byte *mask,uint value)
{
  __asm {
    push   ebx
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    test   esi,esi
    je     Branch132
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch132
    mov    cl,BYTE PTR [ecx]
    xor    eax,eax
    shr    cl,1
    je     Branch131
  Branch130:
    inc    eax
    shr    cl,1
    jne    Branch130
  Branch131:
    mov    edi,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    not    dl
    and    cl,dl
    mov    dl,BYTE PTR [esp+0x18]
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [esi]
    mov    bl,dl
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edi]
    or     cl,bl
    test   eax,eax
    mov    BYTE PTR [edi],cl
    je     Branch132
    mov    edi,DWORD PTR [esi]
    mov    ecx,0x8
    sub    ecx,eax
    mov    eax,0xff
    mov    bl,BYTE PTR [edi+0x1]
    sar    eax,cl
    shr    dl,cl
    not    al
    and    bl,al
    mov    BYTE PTR [edi+0x1],bl
    mov    esi,DWORD PTR [esi]
    or     BYTE PTR [esi+0x1],dl
  Branch132:
    pop    edi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Replaces a width-limited bit field without advancing, reloading cursor after stores.
// Width limits clearing only; unmasked low input byte can set bits outside the requested field.
// R6GameService.dll @ 10019970 : native control/access order and raw ABI retained.
__declspec(naked) void __stdcall WriteCursorBits(uint *cursor,byte *mask,uint value,uint width)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    test   edi,edi
    je     Branch135
    mov    eax,DWORD PTR [esp+0x14]
    test   eax,eax
    je     Branch135
    mov    al,BYTE PTR [eax]
    xor    esi,esi
    shr    al,1
    je     Branch134
  Branch133:
    inc    esi
    shr    al,1
    jne    Branch133
  Branch134:
    mov    cl,BYTE PTR [esp+0x1c]
    mov    al,0x1
    shl    al,cl
    mov    ecx,esi
    push   ebp
    mov    ebp,DWORD PTR [edi]
    dec    al
    mov    bl,BYTE PTR [ebp+0x0]
    mov    dl,al
    shl    dl,cl
    not    dl
    and    bl,dl
    mov    BYTE PTR [ebp+0x0],bl
    mov    bl,BYTE PTR [esp+0x1c]
    mov    ebp,DWORD PTR [edi]
    mov    dl,bl
    shl    dl,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,dl
    mov    BYTE PTR [ebp+0x0],cl
    pop    ebp
    test   esi,esi
    je     Branch135
    mov    edx,0x8
    sub    edx,esi
    mov    esi,DWORD PTR [edi]
    mov    cl,dl
    shr    al,cl
    mov    cl,BYTE PTR [esi+0x1]
    not    al
    and    cl,al
    mov    BYTE PTR [esi+0x1],cl
    mov    edi,DWORD PTR [edi]
    mov    cl,dl
    mov    al,BYTE PTR [edi+0x1]
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [edi+0x1],al
  Branch135:
    pop    edi
    pop    esi
    pop    ebx
    ret    0x10
  }
}

// Decodes nine tagged entry forms, publishing key/length/allocation before payload and optional type/bit count.
// Cursor/output aliases, late allocation fields, unchecked lengths and partial failure ownership retain native order.
// R6GameService.dll @ 1001c2c0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DecodeSerializedStoreEntry(
    uint *cursor,byte *mask,uint *key,void **payload,uint *bytes,uint *type,uint *bits)
{
  __asm {
    sub    esp,0xc
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x20]
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    dl,BYTE PTR [esi]
    mov    ebp,DWORD PTR [edi]
    cmp    dl,0x1
    mov    DWORD PTR [esp+0x18],ebp
    mov    BYTE PTR [esp+0x24],dl
    mov    bl,BYTE PTR [ebp+0x0]
    jne    Branch136
    mov    al,bl
    jmp    Branch139
  Branch136:
    mov    al,dl
    xor    ecx,ecx
    shr    al,1
    mov    DWORD PTR [esp+0x20],ecx
    je     Branch138
  Branch137:
    inc    ecx
    shr    al,1
    jne    Branch137
    mov    DWORD PTR [esp+0x20],ecx
  Branch138:
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,0x8
    sub    ecx,eax
    mov    al,BYTE PTR [ebp+0x1]
    shl    al,cl
    mov    cl,BYTE PTR [esp+0x20]
    shr    bl,cl
    or     al,bl
  Branch139:
    and    al,0x1f
    xor    ecx,ecx
    mov    BYTE PTR [esp+0x10],al
    mov    al,dl
    shr    al,1
    mov    BYTE PTR [esp+0x20],al
    je     Branch141
  Branch140:
    inc    ecx
    shr    al,1
    jne    Branch140
  Branch141:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x5
    jae    Branch142
    mov    ecx,0x4
    inc    ebp
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    DWORD PTR [edi],ebp
    mov    BYTE PTR [esi],al
    jmp    Branch143
  Branch142:
    shl    dl,0x5
    mov    BYTE PTR [esi],dl
  Branch143:
    mov    ecx,DWORD PTR [esp+0x10]
    and    ecx,0xff
    lea    eax,[ecx-0x1]
    cmp    eax,0x10
    ja     Branch196
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::GStoreDecodeTagMap]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GStoreDecodeTargets]
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    xor    ebp,ebp
    push   0x1
    mov    cl,BYTE PTR [eax]
    push   esi
    test   dl,cl
    push   edi
    seta   bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [edi]
    mov    cl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    al,BYTE PTR [edx]
    push   edi
    test   cl,al
    seta   cl
    add    cl,cl
    or     bl,cl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [edi]
    mov    cl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    al,BYTE PTR [edx]
    push   edi
    test   cl,al
    seta   cl
    shl    cl,0x2
    or     bl,cl
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [esp+0x10]
    and    edx,0xff
    lea    eax,[edx-0x1]
    cmp    eax,0x6
    ja     Branch146
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets]
    xor    ebp,ebp
    jmp    Branch146
    lea    eax,[esp+0x10]
    push   0x1
    push   eax
    push   0x1
    jmp    Branch145
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    push   0x2
    jmp    Branch145
    lea    edx,[esp+0x10]
    push   0x1
    push   edx
    push   0x3
    jmp    Branch145
    lea    eax,[esp+0x10]
    push   0x1
    push   eax
    push   0x4
    jmp    Branch145
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    jmp    Branch144
    lea    edx,[esp+0x10]
    push   0x0
    push   edx
  Branch144:
    push   0x0
  Branch145:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    ebp,eax
  Branch146:
    mov    eax,DWORD PTR [esp+0x28]
    push   0x1
    push   esi
    push   edi
    mov    DWORD PTR [eax],ebp
    mov    ecx,DWORD PTR [edi]
    mov    bl,BYTE PTR [esi]
    xor    ebp,ebp
    mov    dl,BYTE PTR [ecx]
    test   bl,dl
    seta   bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    cl,BYTE PTR [eax]
    push   edi
    test   dl,cl
    seta   dl
    add    dl,dl
    or     bl,dl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    cl,BYTE PTR [eax]
    push   edi
    test   dl,cl
    seta   dl
    shl    dl,0x2
    or     bl,dl
    mov    BYTE PTR [esp+0x34],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x28]
    and    eax,0xff
    dec    eax
    cmp    eax,0x6
    ja     Branch149
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2]
    xor    ebp,ebp
    jmp    Branch149
    lea    ecx,[esp+0x28]
    push   0x1
    push   ecx
    push   0x1
    jmp    Branch148
    lea    edx,[esp+0x28]
    push   0x1
    push   edx
    push   0x2
    jmp    Branch148
    lea    eax,[esp+0x28]
    push   0x1
    push   eax
    push   0x3
    jmp    Branch148
    lea    ecx,[esp+0x28]
    push   0x1
    push   ecx
    push   0x4
    jmp    Branch148
    lea    edx,[esp+0x28]
    push   0x1
    push   edx
    jmp    Branch147
    lea    eax,[esp+0x28]
    push   0x0
    push   eax
  Branch147:
    push   0x0
  Branch148:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    ebp,eax
  Branch149:
    mov    ebx,DWORD PTR [esp+0x30]
    push   ebp
    mov    DWORD PTR [ebx],ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebp,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebp+0x0],eax
    jne    Branch150
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch150:
    mov    cl,BYTE PTR [esi]
    xor    eax,eax
    shr    cl,1
    je     Branch152
  Branch151:
    inc    eax
    shr    cl,1
    jne    Branch151
  Branch152:
    neg    al
    and    eax,0x7
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [ebx]
    mov    ebx,DWORD PTR [ebp+0x0]
    test   eax,eax
    jbe    Branch154
    mov    DWORD PTR [esp+0x28],eax
  Branch153:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    push   0x8
    push   esi
    mov    BYTE PTR [ebx],al
    push   edi
    inc    ebx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x28]
    dec    eax
    mov    DWORD PTR [esp+0x28],eax
    jne    Branch153
  Branch154:
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x0
    jmp    Branch185
    mov    ecx,DWORD PTR [edi]
    mov    bl,BYTE PTR [esi]
    xor    ebp,ebp
    push   0x1
    mov    dl,BYTE PTR [ecx]
    push   esi
    test   bl,dl
    push   edi
    seta   bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    cl,BYTE PTR [eax]
    push   edi
    test   dl,cl
    seta   dl
    add    dl,dl
    or     bl,dl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    cl,BYTE PTR [eax]
    push   edi
    test   dl,cl
    seta   dl
    shl    dl,0x2
    or     bl,dl
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x10]
    and    eax,0xff
    dec    eax
    cmp    eax,0x6
    ja     Branch157
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3]
    xor    ebp,ebp
    jmp    Branch157
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    push   0x1
    jmp    Branch156
    lea    edx,[esp+0x10]
    push   0x1
    push   edx
    push   0x2
    jmp    Branch156
    lea    eax,[esp+0x10]
    push   0x1
    push   eax
    push   0x3
    jmp    Branch156
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    push   0x4
    jmp    Branch156
    lea    edx,[esp+0x10]
    push   0x1
    push   edx
    jmp    Branch155
    lea    eax,[esp+0x10]
    push   0x0
    push   eax
  Branch155:
    push   0x0
  Branch156:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    ebp,eax
  Branch157:
    mov    ecx,DWORD PTR [esp+0x28]
    push   0x1
    push   esi
    push   edi
    mov    DWORD PTR [ecx],ebp
    mov    edx,DWORD PTR [edi]
    mov    cl,BYTE PTR [esi]
    xor    ebp,ebp
    mov    al,BYTE PTR [edx]
    test   cl,al
    seta   bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    ecx,DWORD PTR [edi]
    mov    al,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    dl,BYTE PTR [ecx]
    push   edi
    test   al,dl
    seta   al
    add    al,al
    or     bl,al
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    ecx,DWORD PTR [edi]
    mov    al,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    dl,BYTE PTR [ecx]
    push   edi
    test   al,dl
    seta   al
    shl    al,0x2
    or     bl,al
    mov    BYTE PTR [esp+0x34],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    ecx,DWORD PTR [esp+0x28]
    and    ecx,0xff
    lea    eax,[ecx-0x1]
    cmp    eax,0x6
    ja     Branch160
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4]
    xor    ebp,ebp
    jmp    Branch160
    lea    edx,[esp+0x28]
    push   0x1
    push   edx
    push   0x1
    jmp    Branch159
    lea    eax,[esp+0x28]
    push   0x1
    push   eax
    push   0x2
    jmp    Branch159
    lea    ecx,[esp+0x28]
    push   0x1
    push   ecx
    push   0x3
    jmp    Branch159
    lea    edx,[esp+0x28]
    push   0x1
    push   edx
    push   0x4
    jmp    Branch159
    lea    eax,[esp+0x28]
    push   0x1
    push   eax
    jmp    Branch158
    lea    ecx,[esp+0x28]
    push   0x0
    push   ecx
  Branch158:
    push   0x0
  Branch159:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    ebp,eax
  Branch160:
    mov    ebx,DWORD PTR [esp+0x30]
    mov    DWORD PTR [ebx],ebp
    inc    ebp
    push   ebp
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebp,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebp+0x0],eax
    jne    Branch161
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch161:
    mov    edx,DWORD PTR [ebx]
    mov    BYTE PTR [eax+edx*1],0x0
    mov    cl,BYTE PTR [esi]
    xor    eax,eax
    shr    cl,1
    je     Branch163
  Branch162:
    inc    eax
    shr    cl,1
    jne    Branch162
  Branch163:
    neg    al
    and    eax,0x7
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [ebx]
    mov    ecx,DWORD PTR [ebp+0x0]
    test   eax,eax
    lea    edx,[eax+0x1]
    mov    DWORD PTR [ebx],edx
    mov    ebx,ecx
    jbe    Branch165
    mov    DWORD PTR [esp+0x28],eax
  Branch164:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    push   0x8
    push   esi
    mov    BYTE PTR [ebx],al
    push   edi
    inc    ebx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x28]
    dec    eax
    mov    DWORD PTR [esp+0x28],eax
    jne    Branch164
  Branch165:
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x1
    jmp    Branch185
    mov    eax,DWORD PTR [edi]
    mov    dl,BYTE PTR [esi]
    xor    ebp,ebp
    push   0x1
    mov    cl,BYTE PTR [eax]
    push   esi
    test   dl,cl
    push   edi
    seta   bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [edi]
    mov    cl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    al,BYTE PTR [edx]
    push   edi
    test   cl,al
    seta   cl
    add    cl,cl
    or     bl,cl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [edi]
    mov    cl,BYTE PTR [esi]
    push   0x1
    push   esi
    mov    al,BYTE PTR [edx]
    push   edi
    test   cl,al
    seta   cl
    shl    cl,0x2
    or     bl,cl
    mov    BYTE PTR [esp+0x1c],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    edx,DWORD PTR [esp+0x10]
    and    edx,0xff
    lea    eax,[edx-0x1]
    cmp    eax,0x6
    ja     Branch168
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5]
    xor    ebp,ebp
    jmp    Branch168
    lea    eax,[esp+0x10]
    push   0x1
    push   eax
    push   0x1
    jmp    Branch167
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    push   0x2
    jmp    Branch167
    lea    edx,[esp+0x10]
    push   0x1
    push   edx
    push   0x3
    jmp    Branch167
    lea    eax,[esp+0x10]
    push   0x1
    push   eax
    push   0x4
    jmp    Branch167
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    jmp    Branch166
    lea    edx,[esp+0x10]
    push   0x0
    push   edx
  Branch166:
    push   0x0
  Branch167:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
    mov    ebp,eax
  Branch168:
    mov    eax,DWORD PTR [esp+0x28]
    lea    ecx,[esp+0x14]
    push   ecx
    push   0x0
    push   esi
    push   edi
    mov    DWORD PTR [eax],ebp
    mov    DWORD PTR [esp+0x24],0x0
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   eax
    mov    ebx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [ebx],eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebp,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebp+0x0],eax
    jne    Branch169
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch169:
    mov    cl,BYTE PTR [esi]
    xor    eax,eax
    shr    cl,1
    je     Branch171
  Branch170:
    inc    eax
    shr    cl,1
    jne    Branch170
  Branch171:
    neg    al
    and    eax,0x7
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [ebx]
    mov    ebx,DWORD PTR [ebp+0x0]
    test   eax,eax
    jbe    Branch173
    mov    DWORD PTR [esp+0x28],eax
  Branch172:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    push   0x8
    push   esi
    mov    BYTE PTR [ebx],al
    push   edi
    inc    ebx
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x28]
    dec    eax
    mov    DWORD PTR [esp+0x28],eax
    jne    Branch172
  Branch173:
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x2
    jmp    Branch185
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    mov    DWORD PTR [esp+0x14],0x0
    mov    edx,DWORD PTR [esp+0x28]
    mov    DWORD PTR [edx],eax
    lea    eax,[esp+0x14]
    push   eax
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    mov    ebx,DWORD PTR [esp+0x30]
    mov    DWORD PTR [ebx],eax
    inc    eax
    push   eax
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebp,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebp+0x0],eax
    jne    Branch174
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch174:
    mov    ecx,DWORD PTR [ebx]
    mov    BYTE PTR [eax+ecx*1],0x0
    mov    cl,BYTE PTR [esi]
    xor    eax,eax
    shr    cl,1
    je     Branch176
  Branch175:
    inc    eax
    shr    cl,1
    jne    Branch175
  Branch176:
    neg    al
    and    eax,0x7
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [ebx]
    push   eax
    lea    edx,[eax+0x1]
    mov    DWORD PTR [ebx],edx
    mov    eax,DWORD PTR [ebp+0x0]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::CopyStoreCursorBytes
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x6
    jmp    Branch185
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   0x4
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esp+0x34]
    mov    DWORD PTR [ecx],eax
    mov    DWORD PTR [edx],0x4
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebx],eax
    jne    Branch177
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch177:
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    mov    ecx,DWORD PTR [ebx]
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x4
    jmp    Branch185
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   0x4
    mov    edx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x34]
    mov    DWORD PTR [eax],0x4
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebx],eax
    jne    Branch178
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch178:
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    jmp    Branch180
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   0x4
    mov    edx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x34]
    mov    DWORD PTR [eax],0x4
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ebx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ebx],eax
    jne    Branch179
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch179:
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    neg    eax
  Branch180:
    mov    ecx,DWORD PTR [ebx]
    mov    DWORD PTR [ecx],eax
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch185
    mov    DWORD PTR [eax],0x3
    jmp    Branch185
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   0x1
    mov    edx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x34]
    mov    DWORD PTR [eax],0x1
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ecx],eax
    jne    Branch181
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch181:
    mov    BYTE PTR [eax],0x1
    jmp    Branch183
    push   0x0
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreCompactInteger
    push   0x1
    mov    edx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [esp+0x34]
    mov    DWORD PTR [eax],0x1
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    test   eax,eax
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    DWORD PTR [ecx],eax
    jne    Branch182
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8007000e
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch182:
    mov    BYTE PTR [eax],0x0
  Branch183:
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    je     Branch184
    mov    DWORD PTR [eax],0x5
  Branch184:
    push   esi
    push   edi
    call   R6GameServiceAddresses::AlignStoreBitCursor
  Branch185:
    mov    ebp,DWORD PTR [esp+0x38]
    test   ebp,ebp
    je     Branch195
    mov    edi,DWORD PTR [edi]
    mov    ebx,DWORD PTR [esp+0x18]
    mov    cl,BYTE PTR [esp+0x24]
    sub    edi,ebx
    shl    edi,0x3
    mov    DWORD PTR [ebp+0x0],edi
    mov    al,BYTE PTR [esi]
    cmp    cl,al
    jb     Branch190
    mov    cl,BYTE PTR [esp+0x20]
    xor    edx,edx
    test   cl,cl
    je     Branch187
  Branch186:
    inc    edx
    shr    cl,1
    jne    Branch186
  Branch187:
    xor    ecx,ecx
    shr    al,1
    je     Branch189
  Branch188:
    inc    ecx
    shr    al,1
    jne    Branch188
  Branch189:
    sub    ecx,edx
    add    ecx,edi
    pop    edi
    mov    DWORD PTR [ebp+0x0],ecx
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch190:
    xor    ecx,ecx
    shr    al,1
    je     Branch192
  Branch191:
    inc    ecx
    shr    al,1
    jne    Branch191
  Branch192:
    mov    dl,BYTE PTR [esp+0x20]
    xor    eax,eax
    test   dl,dl
    je     Branch194
  Branch193:
    inc    eax
    shr    dl,1
    jne    Branch193
  Branch194:
    sub    ecx,eax
    add    ecx,edi
    mov    DWORD PTR [ebp+0x0],ecx
  Branch195:
    pop    edi
    pop    esi
    pop    ebp
    xor    eax,eax
    pop    ebx
    add    esp,0xc
    ret    0x1c
  Branch196:
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,0x8000620d
    pop    ebx
    add    esp,0xc
    ret    0x1c
  }
}

// Advances by minus the highest mask bit modulo8 and returns that count; mask is required even for NULL cursor.
// R6GameService.dll @ 1001cc20 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall AlignStoreBitCursor(uint *cursor,byte *mask)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    eax,eax
    push   esi
    push   edi
    mov    dl,BYTE PTR [ebp+0x0]
    shr    dl,1
    mov    cl,dl
    je     Branch198
  Branch197:
    inc    eax
    shr    cl,1
    jne    Branch197
  Branch198:
    mov    edi,DWORD PTR [esp+0x14]
    neg    al
    and    al,0x7
    mov    BYTE PTR [esp+0x18],al
    mov    eax,DWORD PTR [esp+0x18]
    and    eax,0xff
    test   edi,edi
    je     Branch202
    mov    esi,eax
    mov    ecx,eax
    shr    esi,0x3
    and    ecx,0x7
    xor    ebx,ebx
    test   dl,dl
    je     Branch200
  Branch199:
    inc    ebx
    shr    dl,1
    jne    Branch199
  Branch200:
    mov    edx,0x7
    sub    edx,ebx
    mov    ebx,DWORD PTR [edi]
    cmp    edx,ecx
    jae    Branch201
    inc    esi
    sub    ecx,edx
    add    ebx,esi
    dec    ecx
    mov    dl,0x1
    mov    DWORD PTR [edi],ebx
    shl    dl,cl
    pop    edi
    pop    esi
    mov    BYTE PTR [ebp+0x0],dl
    pop    ebp
    pop    ebx
    ret    0x8
  Branch201:
    add    ebx,esi
    mov    DWORD PTR [edi],ebx
    mov    dl,BYTE PTR [ebp+0x0]
    shl    dl,cl
    mov    BYTE PTR [ebp+0x0],dl
  Branch202:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Copies cursor bytes one at a time, or writes zero when cursor/mask slots are NULL.
// Destination/count use original argument scratch; each byte precedes cursor advance and raw EAX ends zero.
// R6GameService.dll @ 1001cca0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CopyStoreCursorBytes(uint *cursor,byte *mask,byte *destination,uint bytes)
{
  __asm {
    mov    eax,DWORD PTR [esp+0xc]
    mov    DWORD PTR [esp+0xc],eax
    mov    eax,DWORD PTR [esp+0x10]
    test   eax,eax
    jbe    Branch212
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    DWORD PTR [esp+0x20],eax
  Branch203:
    test   ebp,ebp
    je     Branch207
    test   edi,edi
    je     Branch207
    mov    esi,DWORD PTR [ebp+0x0]
    mov    al,BYTE PTR [edi]
    cmp    al,0x1
    mov    dl,BYTE PTR [esi]
    jne    Branch204
    mov    al,dl
    jmp    Branch208
  Branch204:
    xor    ebx,ebx
    shr    al,1
    je     Branch206
  Branch205:
    inc    ebx
    shr    al,1
    jne    Branch205
  Branch206:
    mov    al,BYTE PTR [esi+0x1]
    mov    ecx,0x8
    sub    ecx,ebx
    shl    al,cl
    mov    cl,bl
    shr    dl,cl
    or     al,dl
    jmp    Branch208
  Branch207:
    xor    al,al
  Branch208:
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    BYTE PTR [ecx],al
    inc    ecx
    test   ebp,ebp
    mov    DWORD PTR [esp+0x1c],ecx
    je     Branch211
    test   edi,edi
    je     Branch211
    mov    al,BYTE PTR [edi]
    shr    al,1
    je     Branch210
  Branch209:
    shr    al,1
    jne    Branch209
  Branch210:
    mov    eax,DWORD PTR [ebp+0x0]
    inc    eax
    mov    DWORD PTR [ebp+0x0],eax
    mov    cl,BYTE PTR [edi]
    mov    BYTE PTR [edi],cl
  Branch211:
    mov    eax,DWORD PTR [esp+0x20]
    dec    eax
    mov    DWORD PTR [esp+0x20],eax
    jne    Branch203
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
  Branch212:
    ret    0x10
  }
}

// Reads a three-bit selector and zero/fixed/sentinel value, then optional selector byte before consumed-bit count.
// Original argument scratch, low-byte optional output and late count-pointer reload retain alias effects.
// R6GameService.dll @ 1001cd40 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall ReadStoreCompactInteger(uint *cursor,byte *mask,byte *selector,uint *bits)
{
  __asm {
    push   ecx
    push   ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR [esp+0x18]
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    mov    dl,BYTE PTR [esi]
    xor    ebx,ebx
    mov    ebp,DWORD PTR [edi]
    mov    DWORD PTR [esp+0x10],ebx
    xor    eax,eax
    test   BYTE PTR [ebp+0x0],dl
    mov    cl,dl
    seta   BYTE PTR [esp+0x18]
    shr    cl,1
    je     Branch214
  Branch213:
    inc    ebx
    shr    cl,1
    jne    Branch213
  Branch214:
    mov    ecx,0x7
    sub    ecx,ebx
    cmp    ecx,0x1
    jae    Branch215
    inc    ebp
    mov    dl,0x1
    neg    ecx
    mov    DWORD PTR [edi],ebp
    shl    dl,cl
    jmp    Branch216
  Branch215:
    add    dl,dl
  Branch216:
    mov    BYTE PTR [esi],dl
    mov    ebp,DWORD PTR [edi]
    mov    bl,BYTE PTR [esp+0x18]
    test   BYTE PTR [ebp+0x0],dl
    seta   cl
    add    cl,cl
    or     bl,cl
    mov    cl,dl
    mov    BYTE PTR [esp+0x18],bl
    xor    ebx,ebx
    shr    cl,1
    je     Branch218
  Branch217:
    inc    ebx
    shr    cl,1
    jne    Branch217
  Branch218:
    mov    ecx,0x7
    sub    ecx,ebx
    cmp    ecx,0x1
    jae    Branch219
    inc    ebp
    mov    dl,0x1
    neg    ecx
    mov    DWORD PTR [edi],ebp
    shl    dl,cl
    jmp    Branch220
  Branch219:
    add    dl,dl
  Branch220:
    mov    BYTE PTR [esi],dl
    mov    ebp,DWORD PTR [edi]
    mov    bl,BYTE PTR [esp+0x18]
    test   BYTE PTR [ebp+0x0],dl
    seta   cl
    shl    cl,0x2
    or     bl,cl
    mov    cl,dl
    mov    BYTE PTR [esp+0x18],bl
    xor    ebx,ebx
    shr    cl,1
    je     Branch222
  Branch221:
    inc    ebx
    shr    cl,1
    jne    Branch221
  Branch222:
    mov    ecx,0x7
    sub    ecx,ebx
    cmp    ecx,0x1
    jae    Branch223
    inc    ebp
    mov    dl,0x1
    neg    ecx
    mov    DWORD PTR [edi],ebp
    shl    dl,cl
    jmp    Branch224
  Branch223:
    add    dl,dl
  Branch224:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    BYTE PTR [esi],dl
    and    ecx,0xff
    dec    ecx
    cmp    ecx,0x6
    ja     Branch233
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6]
    xor    eax,eax
    jmp    Branch233
    mov    ebp,DWORD PTR [edi]
    mov    al,BYTE PTR [esi]
    cmp    al,0x1
    mov    bl,BYTE PTR [ebp+0x0]
    jne    Branch225
    mov    BYTE PTR [esp+0x1c],bl
    jmp    Branch228
  Branch225:
    xor    edx,edx
    shr    al,1
    je     Branch227
  Branch226:
    inc    edx
    shr    al,1
    jne    Branch226
  Branch227:
    mov    al,BYTE PTR [ebp+0x1]
    mov    ecx,0x8
    sub    ecx,edx
    shl    al,cl
    mov    cl,dl
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [esp+0x1c],al
  Branch228:
    mov    ebx,DWORD PTR [esp+0x1c]
    push   0x8
    push   esi
    push   edi
    and    ebx,0xff
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,ebx
    mov    DWORD PTR [esp+0x10],0x8
    jmp    Branch233
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x1c],ebp
  Branch229:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,ebp
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x1c]
    push   0x8
    push   esi
    push   edi
    or     ecx,eax
    mov    DWORD PTR [esp+0x28],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x8
    cmp    ebp,0x10
    mov    DWORD PTR [esp+0x10],0x10
    jb     Branch229
    mov    eax,DWORD PTR [esp+0x1c]
    jmp    Branch233
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x1c],ebp
  Branch230:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,ebp
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x1c]
    push   0x8
    push   esi
    push   edi
    or     ecx,eax
    mov    DWORD PTR [esp+0x28],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x8
    cmp    ebp,0x18
    mov    DWORD PTR [esp+0x10],0x18
    jb     Branch230
    mov    eax,DWORD PTR [esp+0x1c]
    jmp    Branch233
    xor    ebp,ebp
    mov    DWORD PTR [esp+0x1c],ebp
  Branch231:
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadCursorByte
    and    eax,0xff
    mov    ecx,ebp
    shl    eax,cl
    mov    ecx,DWORD PTR [esp+0x1c]
    push   0x8
    push   esi
    push   edi
    or     ecx,eax
    mov    DWORD PTR [esp+0x28],ecx
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x8
    cmp    ebp,0x20
    mov    DWORD PTR [esp+0x10],0x20
    jb     Branch231
    mov    eax,DWORD PTR [esp+0x1c]
    jmp    Branch233
    lea    ecx,[esp+0x10]
    push   0x1
    push   ecx
    jmp    Branch232
    lea    edx,[esp+0x10]
    push   0x0
    push   edx
  Branch232:
    push   0x0
    push   esi
    push   edi
    call   R6GameServiceAddresses::ReadStoreBitCodeValue
  Branch233:
    mov    ecx,DWORD PTR [esp+0x20]
    pop    edi
    pop    esi
    pop    ebp
    test   ecx,ecx
    pop    ebx
    je     Branch234
    mov    dl,BYTE PTR [esp+0x8]
    mov    BYTE PTR [ecx],dl
  Branch234:
    mov    ecx,DWORD PTR [esp+0x14]
    test   ecx,ecx
    je     Branch235
    mov    edx,DWORD PTR [esp+0x0]
    add    edx,0x3
    mov    DWORD PTR [ecx],edx
  Branch235:
    pop    ecx
    ret    0x10
  }
}

// R6GameService.dll data @ 1001cb54 : entry/compact integer dispatch.
const uint GStoreDecodeTargets[10] = {
  R6GameServiceAddresses::GStoreDecodeTargetsCase1,R6GameServiceAddresses::GStoreDecodeTargetsCase2,R6GameServiceAddresses::GStoreDecodeTargetsCase3,R6GameServiceAddresses::GStoreDecodeTargetsCase4,R6GameServiceAddresses::GStoreDecodeTargetsCase5,R6GameServiceAddresses::GStoreDecodeTargetsCase6,R6GameServiceAddresses::GStoreDecodeTargetsCase7,R6GameServiceAddresses::GStoreDecodeTargetsCase8,R6GameServiceAddresses::GStoreDecodeTargetsCase9,R6GameServiceAddresses::store_codec_supportBranch196
};

// R6GameService.dll data @ 1001cb90 : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargetsCase7
};

// R6GameService.dll data @ 1001cbac : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets2[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets2Case7
};

// R6GameService.dll data @ 1001cbc8 : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets3[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets3Case7
};

// R6GameService.dll data @ 1001cbe4 : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets4[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets4Case7
};

// R6GameService.dll data @ 1001cc00 : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets5[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets5Case7
};

// R6GameService.dll data @ 1001cf78 : entry/compact integer dispatch.
const uint store_codec_supportGStoreDecodeTargets6[7] = {
  R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case1,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case2,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case3,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case4,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case5,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case6,R6GameServiceAddresses::store_codec_supportGStoreDecodeTargets6Case7
};

// R6GameService.dll data @ 1001cb7c : tag to branch index.
const byte GStoreDecodeTagMap[17] = {0x0,0x9,0x1,0x9,0x2,0x9,0x3,0x9,0x4,0x9,0x5,0x9,0x6,0x9,0x7,0x9,0x8};

// Overwrites eight bits with1, advances by the padding to a byte boundary and returns that padding count.
// Mask is required even for NULL cursor; pointer reloads and noncanonical masks retain native order.
// R6GameService.dll @ 1001b910 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall PadStoreBitCursor(uint *cursor,byte *mask)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    xor    eax,eax
    push   esi
    push   edi
    mov    cl,BYTE PTR [ebp+0x0]
    shr    cl,1
    mov    dl,cl
    je     Branch237
  Branch236:
    inc    eax
    shr    dl,1
    jne    Branch236
  Branch237:
    mov    edx,DWORD PTR [esp+0x14]
    neg    al
    and    al,0x7
    test   edx,edx
    mov    BYTE PTR [esp+0x18],al
    je     Branch240
    xor    esi,esi
    test   cl,cl
    je     Branch239
  Branch238:
    inc    esi
    shr    cl,1
    jne    Branch238
  Branch239:
    mov    edi,DWORD PTR [edx]
    or     al,0xff
    mov    ecx,esi
    shl    al,cl
    mov    cl,BYTE PTR [edi]
    not    al
    and    cl,al
    mov    al,0x1
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [edx]
    mov    ecx,esi
    shl    al,cl
    mov    cl,BYTE PTR [edi]
    or     cl,al
    test   esi,esi
    mov    BYTE PTR [edi],cl
    je     Branch240
    mov    edi,0x8
    mov    eax,0xff
    sub    edi,esi
    mov    esi,DWORD PTR [edx]
    mov    ecx,edi
    mov    bl,BYTE PTR [esi+0x1]
    sar    eax,cl
    not    al
    and    bl,al
    mov    eax,0x1
    mov    BYTE PTR [esi+0x1],bl
    mov    esi,DWORD PTR [edx]
    sar    eax,cl
    or     BYTE PTR [esi+0x1],al
  Branch240:
    mov    esi,DWORD PTR [esp+0x18]
    and    esi,0xff
    test   edx,edx
    je     Branch244
    mov    al,BYTE PTR [ebp+0x0]
    mov    edi,esi
    mov    ecx,esi
    xor    ebx,ebx
    shr    edi,0x3
    and    ecx,0x7
    shr    al,1
    je     Branch242
  Branch241:
    inc    ebx
    shr    al,1
    jne    Branch241
  Branch242:
    mov    eax,0x7
    sub    eax,ebx
    mov    ebx,DWORD PTR [edx]
    cmp    eax,ecx
    jae    Branch243
    inc    edi
    sub    ecx,eax
    add    ebx,edi
    dec    ecx
    mov    DWORD PTR [edx],ebx
    mov    dl,0x1
    shl    dl,cl
    mov    eax,esi
    pop    edi
    pop    esi
    mov    BYTE PTR [ebp+0x0],dl
    pop    ebp
    pop    ebx
    ret    0x8
  Branch243:
    add    ebx,edi
    mov    DWORD PTR [edx],ebx
    mov    al,BYTE PTR [ebp+0x0]
    shl    al,cl
    mov    BYTE PTR [ebp+0x0],al
  Branch244:
    mov    eax,esi
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Emits low-first00/1 significant-value bits and either0 or01 terminator, optionally publishing consumed bits.
// Highest bit caches a copy; bit reads use the original value argument, mask word is scratch and EAX is bits pointer.
// R6GameService.dll @ 1001b9f0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall EmitStoreSentinelBits(uint *cursor,byte *mask,uint value,uint *bits,uint terminalMode)
{
  __asm {
    sub    esp,0x10
    mov    ecx,DWORD PTR [esp+0x1c]
    push   ebx
    push   ebp
    lea    eax,[esp+0x24]
    mov    bl,0x1
    push   esi
    push   edi
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esp+0x18],eax
    mov    BYTE PTR [esp+0x13],bl
    mov    DWORD PTR [esp+0x1c],ecx
    lea    edx,[esp+0x1f]
    mov    esi,0x4
  Branch245:
    mov    cl,BYTE PTR [edx]
    dec    edx
    test   cl,cl
    je     Branch247
  Branch246:
    mov    al,cl
    neg    al
    and    al,cl
    xor    cl,al
    jne    Branch246
    test   al,al
    jne    Branch249
  Branch247:
    dec    esi
    jne    Branch245
    or     eax,0xffffffff
  Branch248:
    mov    ebp,DWORD PTR [esp+0x28]
    mov    esi,DWORD PTR [esp+0x24]
    inc    eax
    test   eax,eax
    je     Branch274
    mov    DWORD PTR [esp+0x28],eax
    jmp    Branch253
  Branch249:
    dec    esi
    xor    ecx,ecx
    shr    al,1
    je     Branch251
  Branch250:
    inc    ecx
    shr    al,1
    jne    Branch250
  Branch251:
    lea    eax,[ecx+esi*8]
    jmp    Branch248
  Branch252:
    mov    bl,BYTE PTR [esp+0x13]
  Branch253:
    mov    edx,DWORD PTR [esp+0x18]
    test   BYTE PTR [edx],bl
    seta   dl
    mov    al,bl
    xor    edi,edi
    shr    al,1
    je     Branch255
  Branch254:
    inc    edi
    shr    al,1
    jne    Branch254
  Branch255:
    mov    ecx,0x7
    sub    ecx,edi
    cmp    ecx,0x1
    jae    Branch256
    mov    eax,DWORD PTR [esp+0x18]
    inc    eax
    mov    DWORD PTR [esp+0x18],eax
    mov    al,0x1
    neg    ecx
    shl    al,cl
    mov    BYTE PTR [esp+0x13],al
    jmp    Branch257
  Branch256:
    add    bl,bl
    mov    BYTE PTR [esp+0x13],bl
  Branch257:
    test   dl,dl
    jne    Branch265
    test   esi,esi
    je     Branch264
    test   ebp,ebp
    je     Branch264
    mov    al,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    shr    al,1
    je     Branch259
  Branch258:
    inc    ecx
    shr    al,1
    jne    Branch258
  Branch259:
    mov    eax,DWORD PTR [esi]
    mov    dl,0x3
    shl    dl,cl
    mov    bl,BYTE PTR [eax]
    not    dl
    and    bl,dl
    xor    dl,dl
    mov    BYTE PTR [eax],bl
    mov    eax,DWORD PTR [esi]
    shl    dl,cl
    mov    bl,BYTE PTR [eax]
    or     bl,dl
    test   ecx,ecx
    mov    BYTE PTR [eax],bl
    je     Branch260
    mov    eax,0x8
    mov    edi,DWORD PTR [esi]
    sub    eax,ecx
    mov    dl,0x3
    mov    bl,BYTE PTR [edi+0x1]
    mov    cl,al
    shr    dl,cl
    not    dl
    and    bl,dl
    mov    BYTE PTR [edi+0x1],bl
    mov    edx,DWORD PTR [esi]
    xor    bl,bl
    mov    al,BYTE PTR [edx+0x1]
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [edx+0x1],al
  Branch260:
    mov    dl,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    mov    al,dl
    shr    al,1
    je     Branch262
  Branch261:
    inc    ecx
    shr    al,1
    jne    Branch261
  Branch262:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch263
    mov    ebx,DWORD PTR [esi]
    mov    ecx,0x1
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    inc    ebx
    mov    DWORD PTR [esi],ebx
    mov    BYTE PTR [ebp+0x0],al
    mov    eax,DWORD PTR [esp+0x14]
    add    eax,0x2
    jmp    Branch273
  Branch263:
    shl    dl,0x2
    mov    BYTE PTR [ebp+0x0],dl
  Branch264:
    mov    eax,DWORD PTR [esp+0x14]
    add    eax,0x2
    jmp    Branch273
  Branch265:
    test   esi,esi
    je     Branch272
    test   ebp,ebp
    je     Branch272
    mov    al,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    shr    al,1
    je     Branch267
  Branch266:
    inc    ecx
    shr    al,1
    jne    Branch266
  Branch267:
    mov    edi,DWORD PTR [esi]
    mov    al,0x1
    shl    al,cl
    mov    bl,BYTE PTR [edi]
    not    al
    and    bl,al
    mov    al,dl
    mov    BYTE PTR [edi],bl
    mov    edi,DWORD PTR [esi]
    shl    al,cl
    mov    bl,BYTE PTR [edi]
    or     bl,al
    test   ecx,ecx
    mov    BYTE PTR [edi],bl
    je     Branch268
    mov    eax,0x8
    mov    edi,DWORD PTR [esi]
    sub    eax,ecx
    mov    bl,0x1
    mov    cl,al
    shr    bl,cl
    mov    cl,BYTE PTR [edi+0x1]
    not    bl
    and    cl,bl
    mov    BYTE PTR [edi+0x1],cl
    mov    edi,DWORD PTR [esi]
    mov    cl,al
    mov    al,BYTE PTR [edi+0x1]
    shr    dl,cl
    or     al,dl
    mov    BYTE PTR [edi+0x1],al
  Branch268:
    mov    bl,BYTE PTR [ebp+0x0]
    xor    edx,edx
    mov    al,bl
    shr    al,1
    je     Branch270
  Branch269:
    inc    edx
    shr    al,1
    jne    Branch269
  Branch270:
    mov    ecx,0x7
    sub    ecx,edx
    cmp    ecx,0x1
    jae    Branch271
    mov    edi,DWORD PTR [esi]
    mov    dl,0x1
    neg    ecx
    inc    edi
    shl    dl,cl
    mov    DWORD PTR [esi],edi
    mov    BYTE PTR [ebp+0x0],dl
    jmp    Branch272
  Branch271:
    add    bl,bl
    mov    BYTE PTR [ebp+0x0],bl
  Branch272:
    mov    eax,DWORD PTR [esp+0x14]
    inc    eax
  Branch273:
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esp+0x28]
    dec    eax
    mov    DWORD PTR [esp+0x28],eax
    jne    Branch252
  Branch274:
    mov    al,BYTE PTR [esp+0x34]
    test   al,al
    je     Branch282
    test   esi,esi
    je     Branch281
    test   ebp,ebp
    je     Branch281
    mov    al,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    shr    al,1
    je     Branch276
  Branch275:
    inc    ecx
    shr    al,1
    jne    Branch275
  Branch276:
    mov    eax,DWORD PTR [esi]
    mov    dl,0x1
    shl    dl,cl
    mov    bl,BYTE PTR [eax]
    not    dl
    and    bl,dl
    xor    dl,dl
    mov    BYTE PTR [eax],bl
    mov    eax,DWORD PTR [esi]
    shl    dl,cl
    mov    bl,BYTE PTR [eax]
    or     bl,dl
    test   ecx,ecx
    mov    BYTE PTR [eax],bl
    je     Branch277
    mov    eax,0x8
    mov    edi,DWORD PTR [esi]
    sub    eax,ecx
    mov    dl,0x1
    mov    bl,BYTE PTR [edi+0x1]
    mov    cl,al
    shr    dl,cl
    not    dl
    and    bl,dl
    mov    BYTE PTR [edi+0x1],bl
    mov    edx,DWORD PTR [esi]
    xor    bl,bl
    mov    al,BYTE PTR [edx+0x1]
    shr    bl,cl
    or     al,bl
    mov    BYTE PTR [edx+0x1],al
  Branch277:
    mov    bl,BYTE PTR [ebp+0x0]
    xor    edx,edx
    mov    al,bl
    shr    al,1
    je     Branch279
  Branch278:
    inc    edx
    shr    al,1
    jne    Branch278
  Branch279:
    mov    ecx,0x7
    sub    ecx,edx
    cmp    ecx,0x1
    jae    Branch280
    mov    edi,DWORD PTR [esi]
    mov    al,0x1
    neg    ecx
    shl    al,cl
    inc    edi
    mov    DWORD PTR [esi],edi
    mov    BYTE PTR [ebp+0x0],al
    mov    eax,DWORD PTR [esp+0x14]
    inc    eax
    jmp    Branch288
  Branch280:
    add    bl,bl
    mov    BYTE PTR [ebp+0x0],bl
  Branch281:
    mov    eax,DWORD PTR [esp+0x14]
    inc    eax
    jmp    Branch288
  Branch282:
    push   0x2
    push   0x2
    push   ebp
    push   esi
    call   R6GameServiceAddresses::WriteCursorBits
    test   esi,esi
    je     Branch287
    test   ebp,ebp
    je     Branch287
    mov    dl,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    mov    al,dl
    shr    al,1
    je     Branch284
  Branch283:
    inc    ecx
    shr    al,1
    jne    Branch283
  Branch284:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x2
    jae    Branch285
    mov    edi,DWORD PTR [esi]
    mov    ecx,0x1
    inc    edi
    sub    ecx,eax
    mov    dl,0x1
    mov    DWORD PTR [esi],edi
    shl    dl,cl
    jmp    Branch286
  Branch285:
    shl    dl,0x2
  Branch286:
    mov    BYTE PTR [ebp+0x0],dl
  Branch287:
    mov    eax,DWORD PTR [esp+0x14]
    add    eax,0x2
  Branch288:
    mov    DWORD PTR [esp+0x14],eax
    mov    eax,DWORD PTR [esp+0x30]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    test   eax,eax
    je     Branch289
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR [eax],ecx
  Branch289:
    add    esp,0x10
    ret    0x14
  }
}

// Measures sentinel versus minimal bytes, publishing the smaller count and semantic AL1 only for strict savings.
// Zero publishes count0 with AL1; raw upper EAX, late original value/output words and null dummy writes stay native.
// R6GameService.dll @ 1001bd20 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall MeasureStoreIntegerEncoding(uint value,uint *bits,uint terminalMode)
{
  __asm {
    sub    esp,0xc
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    DWORD PTR [esp+0x14],eax
    xor    ebp,ebp
    lea    edi,[esp+0x14]
    mov    bl,0x1
    mov    DWORD PTR [esp+0x18],eax
    lea    edx,[esp+0x1b]
    mov    esi,0x4
  Branch290:
    mov    cl,BYTE PTR [edx]
    dec    edx
    test   cl,cl
    je     Branch292
  Branch291:
    mov    al,cl
    neg    al
    and    al,cl
    xor    cl,al
    jne    Branch291
    test   al,al
    jne    Branch297
  Branch292:
    dec    esi
    jne    Branch290
    or     eax,0xffffffff
  Branch293:
    inc    eax
    test   eax,eax
    je     Branch304
    mov    esi,eax
  Branch294:
    mov    dl,BYTE PTR [edi]
    mov    al,bl
    test   bl,dl
    seta   BYTE PTR [esp+0x13]
    xor    edx,edx
    shr    al,1
    je     Branch296
  Branch295:
    inc    edx
    shr    al,1
    jne    Branch295
  Branch296:
    mov    ecx,0x7
    sub    ecx,edx
    cmp    ecx,0x1
    jae    Branch300
    neg    ecx
    mov    bl,0x1
    inc    edi
    shl    bl,cl
    jmp    Branch301
  Branch297:
    dec    esi
    xor    ecx,ecx
    shr    al,1
    je     Branch299
  Branch298:
    inc    ecx
    shr    al,1
    jne    Branch298
  Branch299:
    lea    eax,[ecx+esi*8]
    jmp    Branch293
  Branch300:
    add    bl,bl
  Branch301:
    mov    al,BYTE PTR [esp+0x13]
    test   al,al
    jne    Branch302
    add    ebp,0x2
    jmp    Branch303
  Branch302:
    inc    ebp
  Branch303:
    dec    esi
    jne    Branch294
  Branch304:
    mov    al,BYTE PTR [esp+0x28]
    test   al,al
    je     Branch305
    push   0x1
    push   0x0
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x1
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    ebp
    jmp    Branch306
  Branch305:
    push   0x2
    push   0x2
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x2
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    ebp,0x2
  Branch306:
    mov    eax,DWORD PTR [esp+0x20]
    test   eax,eax
    jne    Branch308
    mov    eax,DWORD PTR [esp+0x24]
    test   eax,eax
    je     Branch307
    mov    DWORD PTR [eax],0x0
  Branch307:
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch308:
    cmp    eax,0xff
    ja     Branch310
    mov    eax,DWORD PTR [esp+0x24]
    cmp    ebp,0x8
    jae    Branch309
    test   eax,eax
    je     Branch315
    pop    edi
    mov    DWORD PTR [eax],ebp
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch309:
    test   eax,eax
    je     Branch317
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x8
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch310:
    cmp    eax,0xffff
    ja     Branch312
    mov    eax,DWORD PTR [esp+0x24]
    cmp    ebp,0x10
    jae    Branch311
    test   eax,eax
    je     Branch315
    pop    edi
    mov    DWORD PTR [eax],ebp
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch311:
    test   eax,eax
    je     Branch317
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x10
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch312:
    cmp    eax,0xffffff
    mov    eax,DWORD PTR [esp+0x24]
    ja     Branch314
    cmp    ebp,0x18
    jae    Branch313
    test   eax,eax
    je     Branch315
    pop    edi
    mov    DWORD PTR [eax],ebp
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch313:
    test   eax,eax
    je     Branch317
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x18
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch314:
    cmp    ebp,0x20
    jae    Branch316
    test   eax,eax
    je     Branch315
    mov    DWORD PTR [eax],ebp
  Branch315:
    pop    edi
    pop    esi
    pop    ebp
    mov    al,0x1
    pop    ebx
    add    esp,0xc
    ret    0xc
  Branch316:
    test   eax,eax
    je     Branch317
    mov    DWORD PTR [eax],0x20
  Branch317:
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0xc
    ret    0xc
  }
}

// Copies source bytes into the bit cursor, reading source even when NULL cursor/mask suppresses output.
// Original source/count argument words become remaining count/running source; each output precedes cursor advance.
// R6GameService.dll @ 1001bf00 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CopyBytesToStoreBitCursor(uint *cursor,byte *mask,const byte *source,uint bytes)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0xc]
    test   eax,eax
    jbe    Branch325
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    push   edi
    mov    DWORD PTR [esp+0x1c],eax
  Branch318:
    mov    dl,BYTE PTR [ecx]
    inc    ecx
    test   esi,esi
    mov    DWORD PTR [esp+0x20],ecx
    je     Branch324
    test   ebp,ebp
    je     Branch324
    mov    cl,BYTE PTR [ebp+0x0]
    xor    eax,eax
    shr    cl,1
    je     Branch320
  Branch319:
    inc    eax
    shr    cl,1
    jne    Branch319
  Branch320:
    mov    edi,DWORD PTR [esi]
    or     bl,0xff
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edi]
    not    bl
    and    cl,bl
    mov    bl,dl
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [esi]
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edi]
    or     cl,bl
    test   eax,eax
    mov    BYTE PTR [edi],cl
    je     Branch321
    mov    edi,DWORD PTR [esi]
    mov    ecx,0x8
    sub    ecx,eax
    mov    eax,0xff
    mov    bl,BYTE PTR [edi+0x1]
    sar    eax,cl
    shr    dl,cl
    not    al
    and    bl,al
    mov    BYTE PTR [edi+0x1],bl
    mov    eax,DWORD PTR [esi]
    or     BYTE PTR [eax+0x1],dl
  Branch321:
    mov    al,BYTE PTR [ebp+0x0]
    shr    al,1
    je     Branch323
  Branch322:
    shr    al,1
    jne    Branch322
  Branch323:
    mov    eax,DWORD PTR [esi]
    inc    eax
    mov    DWORD PTR [esi],eax
    mov    cl,BYTE PTR [ebp+0x0]
    mov    BYTE PTR [ebp+0x0],cl
    mov    ecx,DWORD PTR [esp+0x20]
  Branch324:
    mov    eax,DWORD PTR [esp+0x1c]
    dec    eax
    mov    DWORD PTR [esp+0x1c],eax
    jne    Branch318
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
  Branch325:
    ret    0x10
  }
}

// Returns a semantic selector byte: zero3, fixed widths1/6/4/2, or sentinel5/7 when its count wins.
// Compact count is capped at minimal bytes; ties select fixed width, and raw upper EAX remains explicit.
// R6GameService.dll @ 1001bfc0 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall SelectStoreIntegerEncoding(uint value,uint compactMode,uint terminalMode)
{
  __asm {
    sub    esp,0x8
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    test   edi,edi
    jne    Branch326
    pop    edi
    mov    al,0x3
    pop    esi
    add    esp,0x8
    ret    0xc
  Branch326:
    mov    al,BYTE PTR [esp+0x18]
    test   al,al
    je     Branch336
    lea    eax,[esp+0x8]
    push   edi
    mov    DWORD PTR [esp+0xc],edi
    xor    esi,esi
    mov    DWORD PTR [esp+0x18],eax
    mov    BYTE PTR [esp+0x1c],0x1
    call   R6GameServiceAddresses::HighestSetBitIndex
    inc    eax
    je     Branch330
    push   ebx
    push   ebp
    mov    ebp,eax
  Branch327:
    mov    edx,DWORD PTR [esp+0x1c]
    mov    cl,BYTE PTR [esp+0x20]
    lea    eax,[esp+0x20]
    push   0x1
    mov    bl,BYTE PTR [edx]
    push   eax
    test   cl,bl
    lea    ecx,[esp+0x24]
    seta   bl
    push   ecx
    mov    BYTE PTR [esp+0x20],bl
    call   R6GameServiceAddresses::AdvanceBitCursor
    test   bl,bl
    jne    Branch328
    push   0x2
    push   0x0
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x2
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    esi,0x2
    jmp    Branch329
  Branch328:
    mov    edx,DWORD PTR [esp+0x14]
    push   0x1
    push   edx
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x1
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    esi
  Branch329:
    dec    ebp
    jne    Branch327
    pop    ebp
    pop    ebx
  Branch330:
    mov    al,BYTE PTR [esp+0x1c]
    test   al,al
    je     Branch331
    push   0x1
    push   0x0
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x1
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    inc    esi
    jmp    Branch332
  Branch331:
    push   0x2
    push   0x2
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::WriteCursorBits
    push   0x2
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::AdvanceBitCursor
    add    esi,0x2
  Branch332:
    cmp    edi,0xff
    ja     Branch333
    cmp    esi,0x8
    jb     Branch340
    mov    esi,0x8
    jmp    Branch340
  Branch333:
    cmp    edi,0xffff
    ja     Branch334
    cmp    esi,0x10
    jb     Branch340
    mov    esi,0x10
    jmp    Branch340
  Branch334:
    cmp    edi,0xffffff
    ja     Branch335
    cmp    esi,0x18
    jb     Branch340
    mov    esi,0x18
    jmp    Branch340
  Branch335:
    cmp    esi,0x20
    jb     Branch340
    mov    esi,0x20
    jmp    Branch340
  Branch336:
    cmp    edi,0xff
    ja     Branch337
    mov    eax,0x1
    jmp    Branch339
  Branch337:
    cmp    edi,0xffff
    ja     Branch338
    mov    eax,0x2
    jmp    Branch339
  Branch338:
    mov    eax,0xffffff
    cmp    eax,edi
    sbb    eax,eax
    neg    eax
    add    eax,0x3
  Branch339:
    lea    esi,[eax*8+0x0]
  Branch340:
    add    esi,0xfffffff8
    cmp    esi,0x18
    ja     Branch341
    xor    ecx,ecx
    mov    cl,BYTE PTR [esi+R6GameServiceAddresses::GStoreEncodeWidthMap]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::GStoreEncodeSelectorTargets]
    pop    edi
    mov    al,0x1
    pop    esi
    add    esp,0x8
    ret    0xc
    pop    edi
    mov    al,0x6
    pop    esi
    add    esp,0x8
    ret    0xc
    pop    edi
    mov    al,0x4
    pop    esi
    add    esp,0x8
    ret    0xc
    pop    edi
    mov    al,0x2
    pop    esi
    add    esp,0x8
    ret    0xc
  Branch341:
    mov    cl,BYTE PTR [esp+0x1c]
    xor    eax,eax
    test   cl,cl
    sete   al
    pop    edi
    pop    esi
    lea    eax,[eax+eax*1+0x5]
    add    esp,0x8
    ret    0xc
  }
}

// R6GameService.dll data @ 1001c178 : selected compact widths.
const uint GStoreEncodeSelectorTargets[5] = {R6GameServiceAddresses::GStoreEncodeSelectorTargetsCase1,R6GameServiceAddresses::GStoreEncodeSelectorTargetsCase2,R6GameServiceAddresses::GStoreEncodeSelectorTargetsCase3,R6GameServiceAddresses::GStoreEncodeSelectorTargetsCase4,R6GameServiceAddresses::store_codec_supportBranch341};

// R6GameService.dll data @ 1001c18c : bit count minus8 to branch index.
const byte GStoreEncodeWidthMap[25] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x3
};

// Writes one of seven entry forms using native selector choices, padding and live source/argument scratch.
// Buffer return adds bytes to bit counts; optional output gets raw EAX, with late arguments and byte reloads retained.
// With zero padding, an even first payload byte can overwrite the mode1 length terminator lookahead.
// R6GameService.dll @ 1001aa70 : native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall EncodeStoreEntry(
    uint *cursor,byte *mask,uint type,uint keyDelta,uint *payload,uint bytes,uint *reported)
{
  __asm {
    sub    esp,0x14
    mov    ecx,DWORD PTR [esp+0x20]
    push   ebx
    and    ecx,0xff
    push   ebp
    add    ecx,0xfffffffd
    xor    eax,eax
    push   esi
    cmp    ecx,0x6
    push   edi
    mov    DWORD PTR [esp+0x10],eax
    mov    BYTE PTR [esp+0x1c],0x1
    mov    DWORD PTR [esp+0x14],eax
    ja     Branch445
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::GStoreEntryEncodeTargets]
    mov    esi,DWORD PTR [esp+0x28]
    mov    edi,DWORD PTR [esp+0x2c]
    xor    ebx,ebx
    cmp    esi,ebx
    je     Branch348
    cmp    edi,ebx
    je     Branch348
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    shr    cl,1
    je     Branch343
  Branch342:
    inc    eax
    shr    cl,1
    jne    Branch342
  Branch343:
    mov    ebp,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [ebp+0x0]
    not    dl
    and    cl,dl
    mov    dl,0x1
    mov    BYTE PTR [ebp+0x0],cl
    mov    ebp,DWORD PTR [esi]
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,dl
    cmp    eax,ebx
    mov    BYTE PTR [ebp+0x0],cl
    je     Branch344
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,eax
    mov    eax,DWORD PTR [esi]
    sar    edx,cl
    not    dl
    and    BYTE PTR [eax+0x1],dl
    mov    eax,DWORD PTR [esi]
    mov    edx,0x1
    sar    edx,cl
    or     BYTE PTR [eax+0x1],dl
  Branch344:
    mov    dl,BYTE PTR [edi]
    xor    ecx,ecx
    mov    al,dl
    shr    al,1
    je     Branch346
  Branch345:
    inc    ecx
    shr    al,1
    jne    Branch345
  Branch346:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x5
    jae    Branch347
    mov    ecx,DWORD PTR [esi]
    inc    ecx
    mov    DWORD PTR [esi],ecx
    mov    ecx,0x4
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [edi],al
    jmp    Branch348
  Branch347:
    shl    dl,0x5
    mov    BYTE PTR [edi],dl
  Branch348:
    mov    ebp,DWORD PTR [esp+0x3c]
    lea    ecx,[esp+0x2c]
    push   0x1
    push   ecx
    push   ebp
    push   ebx
    push   ebx
    mov    DWORD PTR [esp+0x40],ebx
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    cmp    ebp,ebx
    jne    Branch351
    mov    DWORD PTR [esp+0x14],ebx
    mov    BYTE PTR [esp+0x30],0x1
  Branch349:
    mov    BYTE PTR [esp+0x18],0x1
  Branch350:
    mov    ebx,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [esp+0x34]
    lea    edx,[esp+0x2c]
    push   ebx
    push   edx
    push   ebp
    push   0x0
    push   0x0
    mov    DWORD PTR [esp+0x40],0x0
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    test   ebp,ebp
    jne    Branch356
    mov    DWORD PTR [esp+0x10],ebp
    mov    BYTE PTR [esp+0x28],0x1
    mov    bl,0x3
    jmp    Branch363
  Branch351:
    mov    eax,DWORD PTR [esp+0x2c]
    cmp    ebp,0xff
    ja     Branch352
    cmp    eax,0x8
    jb     Branch355
    mov    DWORD PTR [esp+0x14],0x8
    mov    BYTE PTR [esp+0x30],0x0
    jmp    Branch349
  Branch352:
    cmp    ebp,0xffff
    ja     Branch353
    cmp    eax,0x10
    jb     Branch355
    mov    DWORD PTR [esp+0x14],0x10
    mov    BYTE PTR [esp+0x30],0x0
    mov    BYTE PTR [esp+0x18],0x0
    jmp    Branch350
  Branch353:
    cmp    ebp,0xffffff
    ja     Branch354
    cmp    eax,0x18
    jb     Branch355
    mov    DWORD PTR [esp+0x14],0x18
    mov    BYTE PTR [esp+0x30],0x0
    mov    BYTE PTR [esp+0x18],0x0
    jmp    Branch350
  Branch354:
    cmp    eax,0x20
    jb     Branch355
    mov    DWORD PTR [esp+0x14],0x20
    mov    BYTE PTR [esp+0x30],0x0
    mov    BYTE PTR [esp+0x18],0x0
    jmp    Branch350
  Branch355:
    cmp    eax,0x10
    mov    DWORD PTR [esp+0x14],eax
    mov    BYTE PTR [esp+0x30],0x1
    jb     Branch349
    mov    BYTE PTR [esp+0x18],0x0
    jmp    Branch350
  Branch356:
    mov    eax,DWORD PTR [esp+0x2c]
    cmp    ebp,0xff
    ja     Branch357
    cmp    eax,0x8
    jb     Branch360
    mov    DWORD PTR [esp+0x10],0x8
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch361
  Branch357:
    cmp    ebp,0xffff
    ja     Branch358
    cmp    eax,0x10
    jb     Branch360
    mov    DWORD PTR [esp+0x10],0x10
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch361
  Branch358:
    cmp    ebp,0xffffff
    ja     Branch359
    cmp    eax,0x18
    jb     Branch360
    mov    DWORD PTR [esp+0x10],0x18
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch361
  Branch359:
    cmp    eax,0x20
    jb     Branch360
    mov    DWORD PTR [esp+0x10],0x20
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch361
  Branch360:
    mov    DWORD PTR [esp+0x10],eax
    mov    BYTE PTR [esp+0x28],0x1
  Branch361:
    lea    eax,[esp+0x34]
    push   ebx
    push   eax
    push   ebp
    mov    DWORD PTR [esp+0x40],0x0
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ecx,DWORD PTR [esp+0x34]
    lea    eax,[ecx-0x8]
    cmp    eax,0x18
    ja     Branch362
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::GStoreEntryEncodeWidthMap]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets]
    mov    bl,0x1
    jmp    Branch363
    mov    bl,0x6
    jmp    Branch363
    mov    bl,0x4
    jmp    Branch363
    mov    bl,0x2
    jmp    Branch363
  Branch362:
    mov    al,BYTE PTR [esp+0x18]
    test   al,al
    sete   bl
    lea    ebx,[ebx+ebx*1+0x5]
  Branch363:
    test   esi,esi
    mov    BYTE PTR [esp+0x2c],bl
    je     Branch371
    test   edi,edi
    je     Branch371
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    shr    cl,1
    je     Branch365
  Branch364:
    inc    eax
    shr    cl,1
    jne    Branch364
  Branch365:
    mov    edx,DWORD PTR [esi]
    or     bl,0xff
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edx]
    not    bl
    and    cl,bl
    mov    bl,BYTE PTR [esp+0x2c]
    mov    BYTE PTR [edx],cl
    mov    edx,DWORD PTR [esi]
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edx]
    or     cl,bl
    test   eax,eax
    mov    BYTE PTR [edx],cl
    je     Branch366
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,eax
    mov    eax,DWORD PTR [esi]
    sar    edx,cl
    mov    bl,BYTE PTR [eax+0x1]
    not    dl
    and    bl,dl
    mov    BYTE PTR [eax+0x1],bl
    mov    bl,BYTE PTR [esp+0x2c]
    mov    eax,DWORD PTR [esi]
    mov    dl,bl
    shr    dl,cl
    or     BYTE PTR [eax+0x1],dl
    jmp    Branch367
  Branch366:
    mov    bl,BYTE PTR [esp+0x2c]
  Branch367:
    mov    dl,BYTE PTR [edi]
    xor    ecx,ecx
    mov    al,dl
    shr    al,1
    je     Branch369
  Branch368:
    inc    ecx
    shr    al,1
    jne    Branch368
  Branch369:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x3
    jae    Branch370
    mov    ecx,DWORD PTR [esi]
    inc    ecx
    mov    DWORD PTR [esi],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [edi],al
    jmp    Branch371
  Branch370:
    shl    dl,0x3
    mov    BYTE PTR [edi],dl
  Branch371:
    cmp    bl,0x3
    je     Branch376
    mov    al,BYTE PTR [esp+0x28]
    test   al,al
    je     Branch372
    mov    ecx,DWORD PTR [esp+0x18]
    push   ecx
    push   0x0
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    jmp    Branch376
  Branch372:
    cmp    ebp,0xff
    jbe    Branch375
    cmp    ebp,0xffff
    jbe    Branch374
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    ebp,0xffffff
    jbe    Branch373
    shr    ebp,0x8
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
  Branch373:
    shr    ebp,0x8
  Branch374:
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
  Branch375:
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
  Branch376:
    mov    eax,DWORD PTR [esp+0x3c]
    test   eax,eax
    jne    Branch377
    mov    dl,0x3
    jmp    Branch379
  Branch377:
    lea    edx,[esp+0x34]
    push   0x1
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x40],0x0
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    eax,DWORD PTR [esp+0x34]
    add    eax,0xfffffff8
    cmp    eax,0x18
    ja     Branch378
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeWidthMap]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets2]
    mov    dl,0x1
    jmp    Branch379
    mov    dl,0x6
    jmp    Branch379
    mov    dl,0x4
    jmp    Branch379
    mov    dl,0x2
    jmp    Branch379
  Branch378:
    mov    dl,0x5
  Branch379:
    test   esi,esi
    je     Branch386
    test   edi,edi
    je     Branch386
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    shr    cl,1
    je     Branch381
  Branch380:
    inc    eax
    shr    cl,1
    jne    Branch380
  Branch381:
    mov    ebp,DWORD PTR [esi]
    or     bl,0xff
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [ebp+0x0]
    not    bl
    and    cl,bl
    mov    bl,dl
    mov    BYTE PTR [ebp+0x0],cl
    mov    ebp,DWORD PTR [esi]
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [ebp+0x0]
    or     cl,bl
    test   eax,eax
    mov    BYTE PTR [ebp+0x0],cl
    je     Branch382
    mov    ecx,0x8
    mov    ebx,0xff
    sub    ecx,eax
    mov    eax,DWORD PTR [esi]
    sar    ebx,cl
    not    bl
    and    BYTE PTR [eax+0x1],bl
    mov    eax,DWORD PTR [esi]
    mov    bl,dl
    shr    bl,cl
    or     BYTE PTR [eax+0x1],bl
  Branch382:
    mov    bl,BYTE PTR [edi]
    xor    ecx,ecx
    mov    al,bl
    shr    al,1
    je     Branch384
  Branch383:
    inc    ecx
    shr    al,1
    jne    Branch383
  Branch384:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x3
    jae    Branch385
    mov    ecx,DWORD PTR [esi]
    inc    ecx
    mov    DWORD PTR [esi],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [edi],al
    jmp    Branch386
  Branch385:
    shl    bl,0x3
    mov    BYTE PTR [edi],bl
  Branch386:
    cmp    dl,0x3
    je     Branch391
    mov    al,BYTE PTR [esp+0x30]
    test   al,al
    je     Branch387
    mov    ecx,DWORD PTR [esp+0x3c]
    push   0x1
    push   0x0
    push   ecx
    push   edi
    push   esi
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    jmp    Branch391
  Branch387:
    mov    ebp,DWORD PTR [esp+0x3c]
    cmp    ebp,0xff
    jbe    Branch390
    cmp    ebp,0xffff
    jbe    Branch389
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    ebp,0xffffff
    jbe    Branch388
    shr    ebp,0x8
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
  Branch388:
    shr    ebp,0x8
  Branch389:
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    shr    ebp,0x8
  Branch390:
    push   ebp
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
  Branch391:
    mov    cl,BYTE PTR [edi]
    xor    eax,eax
    shr    cl,1
    je     Branch393
  Branch392:
    inc    eax
    shr    cl,1
    jne    Branch392
  Branch393:
    neg    al
    push   0x1
    and    al,0x7
    push   edi
    push   esi
    mov    BYTE PTR [esp+0x40],al
    call   R6GameServiceAddresses::WriteCursorByte
    mov    ebx,DWORD PTR [esp+0x34]
    and    ebx,0xff
    push   ebx
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x3c]
    mov    ebp,DWORD PTR [esp+0x38]
    test   eax,eax
    jbe    Branch395
    mov    edx,eax
    mov    DWORD PTR [esp+0x34],edx
  Branch394:
    mov    al,BYTE PTR [ebp+0x0]
    inc    ebp
    push   eax
    push   edi
    push   esi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x8
    push   edi
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    eax,DWORD PTR [esp+0x34]
    dec    eax
    mov    DWORD PTR [esp+0x34],eax
    jne    Branch394
  Branch395:
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0x3c]
    add    ebx,eax
    mov    eax,DWORD PTR [esp+0x10]
    add    ebx,eax
    lea    eax,[ebx+ecx*1+0xb]
    jmp    Branch445
    mov    ebx,DWORD PTR [esp+0x3c]
    test   ebx,ebx
    je     Branch396
    dec    ebx
    mov    DWORD PTR [esp+0x3c],ebx
  Branch396:
    mov    esi,DWORD PTR [esp+0x28]
    mov    ebp,DWORD PTR [esp+0x2c]
    test   esi,esi
    je     Branch403
    test   ebp,ebp
    je     Branch403
    mov    cl,BYTE PTR [ebp+0x0]
    xor    eax,eax
    shr    cl,1
    je     Branch398
  Branch397:
    inc    eax
    shr    cl,1
    jne    Branch397
  Branch398:
    mov    edi,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    not    dl
    and    cl,dl
    mov    dl,0x3
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [esi]
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    or     cl,dl
    test   eax,eax
    mov    BYTE PTR [edi],cl
    je     Branch399
    mov    ecx,0x8
    mov    edx,0xff
    sub    ecx,eax
    mov    eax,DWORD PTR [esi]
    sar    edx,cl
    not    dl
    and    BYTE PTR [eax+0x1],dl
    mov    eax,DWORD PTR [esi]
    mov    edx,0x3
    sar    edx,cl
    or     BYTE PTR [eax+0x1],dl
  Branch399:
    mov    cl,BYTE PTR [ebp+0x0]
    xor    edx,edx
    mov    al,cl
    shr    al,1
    je     Branch401
  Branch400:
    inc    edx
    shr    al,1
    jne    Branch400
  Branch401:
    mov    eax,0x7
    sub    eax,edx
    cmp    eax,0x5
    jae    Branch402
    mov    ecx,DWORD PTR [esi]
    inc    ecx
    mov    DWORD PTR [esi],ecx
    mov    ecx,0x4
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [ebp+0x0],al
    jmp    Branch403
  Branch402:
    shl    cl,0x5
    mov    BYTE PTR [ebp+0x0],cl
  Branch403:
    test   ebx,ebx
    je     Branch404
    mov    ecx,DWORD PTR [esp+0x38]
    mov    al,BYTE PTR [ecx]
    and    al,0x1
    mov    BYTE PTR [esp+0x1c],al
  Branch404:
    mov    edx,DWORD PTR [esp+0x1c]
    lea    eax,[esp+0x28]
    push   edx
    push   eax
    push   ebx
    push   0x0
    push   0x0
    mov    DWORD PTR [esp+0x3c],0x0
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    test   ebx,ebx
    mov    edi,0x10
    mov    ebp,0x20
    jne    Branch407
    mov    DWORD PTR [esp+0x14],ebx
    mov    BYTE PTR [esp+0x30],0x1
  Branch405:
    mov    bl,0x1
  Branch406:
    mov    eax,DWORD PTR [esp+0x34]
    mov    BYTE PTR [esp+0x18],bl
    mov    ecx,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x28]
    push   ecx
    push   edx
    push   eax
    push   0x0
    push   0x0
    mov    DWORD PTR [esp+0x3c],0x0
    call   R6GameServiceAddresses::EmitStoreSentinelBits
    mov    eax,DWORD PTR [esp+0x34]
    test   eax,eax
    jne    Branch412
    mov    DWORD PTR [esp+0x10],0x0
    mov    BYTE PTR [esp+0x28],0x1
    mov    dl,0x3
    jmp    Branch419
  Branch407:
    mov    eax,DWORD PTR [esp+0x28]
    cmp    ebx,0xff
    ja     Branch408
    cmp    eax,0x8
    jb     Branch411
    mov    DWORD PTR [esp+0x14],0x8
    mov    BYTE PTR [esp+0x30],0x0
    jmp    Branch405
  Branch408:
    cmp    ebx,0xffff
    ja     Branch409
    cmp    eax,edi
    jb     Branch411
    mov    DWORD PTR [esp+0x14],edi
    mov    BYTE PTR [esp+0x30],0x0
    xor    bl,bl
    jmp    Branch406
  Branch409:
    cmp    ebx,0xffffff
    ja     Branch410
    cmp    eax,0x18
    jb     Branch411
    mov    DWORD PTR [esp+0x14],0x18
    mov    BYTE PTR [esp+0x30],0x0
    xor    bl,bl
    jmp    Branch406
  Branch410:
    cmp    eax,ebp
    jb     Branch411
    mov    DWORD PTR [esp+0x14],ebp
    mov    BYTE PTR [esp+0x30],0x0
    xor    bl,bl
    jmp    Branch406
  Branch411:
    cmp    eax,edi
    mov    DWORD PTR [esp+0x14],eax
    mov    BYTE PTR [esp+0x30],0x1
    jb     Branch405
    xor    bl,bl
    jmp    Branch406
  Branch412:
    mov    eax,DWORD PTR [esp+0x34]
    cmp    eax,0xff
    ja     Branch413
    mov    eax,DWORD PTR [esp+0x28]
    cmp    eax,0x8
    jb     Branch416
    mov    DWORD PTR [esp+0x10],0x8
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch417
  Branch413:
    cmp    eax,0xffff
    ja     Branch414
    mov    eax,DWORD PTR [esp+0x28]
    cmp    eax,edi
    jb     Branch416
    mov    DWORD PTR [esp+0x10],edi
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch417
  Branch414:
    cmp    eax,0xffffff
    mov    eax,DWORD PTR [esp+0x28]
    ja     Branch415
    cmp    eax,0x18
    jb     Branch416
    mov    DWORD PTR [esp+0x10],0x18
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch417
  Branch415:
    cmp    eax,ebp
    jb     Branch416
    mov    DWORD PTR [esp+0x10],ebp
    mov    BYTE PTR [esp+0x28],0x0
    jmp    Branch417
  Branch416:
    mov    DWORD PTR [esp+0x10],eax
    mov    BYTE PTR [esp+0x28],0x1
  Branch417:
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,DWORD PTR [esp+0x34]
    lea    edx,[esp+0x20]
    push   ecx
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x2c],0x0
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ecx,DWORD PTR [esp+0x20]
    lea    eax,[ecx-0x8]
    cmp    eax,0x18
    ja     Branch418
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeWidthMap2]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets3]
    mov    dl,0x1
    jmp    Branch419
    mov    dl,0x6
    jmp    Branch419
    mov    dl,0x4
    jmp    Branch419
    mov    dl,0x2
    jmp    Branch419
  Branch418:
    test   bl,bl
    sete   dl
    lea    edx,[edx+edx*1+0x5]
  Branch419:
    mov    ebp,DWORD PTR [esp+0x2c]
    test   esi,esi
    je     Branch426
    test   ebp,ebp
    je     Branch426
    mov    cl,BYTE PTR [ebp+0x0]
    xor    eax,eax
    shr    cl,1
    je     Branch421
  Branch420:
    inc    eax
    shr    cl,1
    jne    Branch420
  Branch421:
    mov    edi,DWORD PTR [esi]
    or     bl,0xff
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edi]
    not    bl
    and    cl,bl
    mov    bl,dl
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [esi]
    mov    ecx,eax
    shl    bl,cl
    mov    cl,BYTE PTR [edi]
    or     cl,bl
    test   eax,eax
    mov    BYTE PTR [edi],cl
    je     Branch422
    mov    ecx,0x8
    mov    ebx,0xff
    sub    ecx,eax
    mov    eax,DWORD PTR [esi]
    sar    ebx,cl
    not    bl
    and    BYTE PTR [eax+0x1],bl
    mov    eax,DWORD PTR [esi]
    mov    bl,dl
    shr    bl,cl
    or     BYTE PTR [eax+0x1],bl
  Branch422:
    mov    bl,BYTE PTR [ebp+0x0]
    xor    ecx,ecx
    mov    al,bl
    shr    al,1
    je     Branch424
  Branch423:
    inc    ecx
    shr    al,1
    jne    Branch423
  Branch424:
    mov    eax,0x7
    sub    eax,ecx
    cmp    eax,0x3
    jae    Branch425
    mov    ecx,DWORD PTR [esi]
    inc    ecx
    mov    DWORD PTR [esi],ecx
    mov    ecx,0x2
    sub    ecx,eax
    mov    al,0x1
    shl    al,cl
    mov    BYTE PTR [ebp+0x0],al
    jmp    Branch426
  Branch425:
    shl    bl,0x3
    mov    BYTE PTR [ebp+0x0],bl
  Branch426:
    cmp    dl,0x3
    je     Branch427
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x34]
    push   ecx
    push   0x0
    push   edx
    push   eax
    push   ebp
    push   esi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch427:
    mov    eax,DWORD PTR [esp+0x3c]
    test   eax,eax
    jne    Branch428
    mov    bl,0x3
    jmp    Branch430
  Branch428:
    mov    ecx,DWORD PTR [esp+0x1c]
    lea    edx,[esp+0x34]
    push   ecx
    push   edx
    push   eax
    mov    DWORD PTR [esp+0x40],0x0
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    eax,DWORD PTR [esp+0x34]
    add    eax,0xfffffff8
    cmp    eax,0x18
    ja     Branch429
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeWidthMap3]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets4]
    mov    bl,0x1
    jmp    Branch430
    mov    bl,0x6
    jmp    Branch430
    mov    bl,0x4
    jmp    Branch430
    mov    bl,0x2
    jmp    Branch430
  Branch429:
    mov    al,BYTE PTR [esp+0x1c]
    test   al,al
    sete   bl
    lea    ebx,[ebx+ebx*1+0x5]
  Branch430:
    test   esi,esi
    je     Branch433
    test   ebp,ebp
    je     Branch433
    mov    cl,BYTE PTR [ebp+0x0]
    xor    eax,eax
    shr    cl,1
    je     Branch432
  Branch431:
    inc    eax
    shr    cl,1
    jne    Branch431
  Branch432:
    mov    edi,DWORD PTR [esi]
    or     dl,0xff
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    not    dl
    and    cl,dl
    mov    dl,bl
    mov    BYTE PTR [edi],cl
    mov    edi,DWORD PTR [esi]
    mov    ecx,eax
    shl    dl,cl
    mov    cl,BYTE PTR [edi]
    or     cl,dl
    test   eax,eax
    mov    BYTE PTR [edi],cl
    je     Branch433
    mov    edi,DWORD PTR [esi]
    mov    ecx,0x8
    sub    ecx,eax
    mov    eax,0xff
    mov    dl,BYTE PTR [edi+0x1]
    sar    eax,cl
    not    al
    and    dl,al
    mov    BYTE PTR [edi+0x1],dl
    mov    edi,DWORD PTR [esi]
    mov    dl,bl
    mov    al,BYTE PTR [edi+0x1]
    shr    dl,cl
    or     al,dl
    mov    BYTE PTR [edi+0x1],al
  Branch433:
    push   0x3
    push   ebp
    push   esi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch434
    mov    eax,DWORD PTR [esp+0x1c]
    mov    ecx,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x3c]
    push   eax
    push   0x0
    push   ecx
    push   edx
    push   ebp
    push   esi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch434:
    push   ebp
    push   esi
    call   R6GameServiceAddresses::PadStoreBitCursor
    mov    edi,eax
    mov    ebx,DWORD PTR [esp+0x3c]
    mov    eax,DWORD PTR [esp+0x38]
    push   ebx
    push   eax
    push   ebp
    push   esi
    call   R6GameServiceAddresses::CopyBytesToStoreBitCursor
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
    add    edi,ecx
    add    edi,eax
    lea    eax,[edi+ebx*1+0xb]
    jmp    Branch445
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edi,DWORD PTR [esp+0x28]
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    mov    ebp,DWORD PTR [esp+0x3c]
    jmp    Branch436
    mov    ebp,DWORD PTR [esp+0x3c]
    test   ebp,ebp
    je     Branch435
    dec    ebp
  Branch435:
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edi,DWORD PTR [esp+0x28]
    push   0x11
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
  Branch436:
    lea    edx,[esp+0x14]
    push   0x1
    push   edx
    push   ebp
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ebx,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x10]
    cmp    ebx,0x10
    mov    BYTE PTR [esp+0x30],al
    setb   al
    mov    BYTE PTR [esp+0x18],al
    mov    eax,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [esp+0x18]
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x34]
    push   ecx
    push   0x1
    push   edx
    mov    BYTE PTR [esp+0x34],al
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x2c],bl
    mov    eax,DWORD PTR [esp+0x2c]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch437
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x34]
    push   ecx
    push   0x0
    push   edx
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch437:
    push   0x1
    push   0x1
    push   ebp
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x34],bl
    mov    ecx,DWORD PTR [esp+0x34]
    push   ecx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch438
    mov    edx,DWORD PTR [esp+0x30]
    push   0x1
    push   0x0
    push   edx
    push   ebp
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch438:
    push   esi
    push   edi
    call   R6GameServiceAddresses::PadStoreBitCursor
    mov    ebx,eax
    push   ebp
    mov    eax,DWORD PTR [esp+0x3c]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::CopyBytesToStoreBitCursor
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x10]
    add    ebx,ecx
    add    ebx,eax
    lea    eax,[ebx+ebp*1+0xb]
    jmp    Branch445
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edi,DWORD PTR [esp+0x28]
    push   0xb
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    lea    edx,[esp+0x3c]
    push   0x1
    mov    eax,DWORD PTR [esp+0x3c]
    push   edx
    mov    DWORD PTR [esp+0x44],0x0
    mov    ecx,DWORD PTR [eax]
    push   ecx
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    and    eax,0xff
    mov    ecx,DWORD PTR [esp+0x3c]
    mov    DWORD PTR [esp+0x30],eax
    cmp    ecx,0x10
    mov    ecx,DWORD PTR [esp+0x34]
    setb   dl
    mov    BYTE PTR [esp+0x18],dl
    lea    eax,[esp+0x10]
    mov    ebp,DWORD PTR [esp+0x18]
    push   ebp
    push   eax
    push   ecx
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    push   ebp
    push   0x1
    mov    edx,DWORD PTR [esp+0x3c]
    mov    BYTE PTR [esp+0x30],al
    push   edx
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x2c],bl
    mov    eax,DWORD PTR [esp+0x2c]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch439
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esp+0x34]
    push   ebp
    push   0x0
    push   ecx
    push   edx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch439:
    mov    ebp,DWORD PTR [esp+0x38]
    push   0x1
    push   0x1
    mov    eax,DWORD PTR [ebp+0x0]
    push   eax
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x34],bl
    mov    ecx,DWORD PTR [esp+0x34]
    push   ecx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch440
    mov    edx,DWORD PTR [esp+0x30]
    mov    eax,DWORD PTR [ebp+0x0]
    push   0x1
    push   0x0
    push   edx
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch440:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x3c]
    lea    eax,[edx+ecx*1+0xb]
    jmp    Branch445
    mov    eax,DWORD PTR [esp+0x38]
    mov    eax,DWORD PTR [eax]
    test   eax,eax
    mov    ebp,eax
    jge    Branch441
    neg    ebp
    test   eax,eax
  Branch441:
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edi,DWORD PTR [esp+0x28]
    setl   cl
    lea    ecx,[ecx+ecx*1+0x7]
    push   ecx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    lea    edx,[esp+0x3c]
    push   0x1
    push   edx
    push   ebp
    mov    DWORD PTR [esp+0x48],0x0
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ebx,DWORD PTR [esp+0x3c]
    and    eax,0xff
    cmp    ebx,0x10
    mov    DWORD PTR [esp+0x38],eax
    setb   al
    mov    BYTE PTR [esp+0x18],al
    mov    eax,DWORD PTR [esp+0x34]
    mov    ecx,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x10]
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x34]
    push   ecx
    push   0x1
    push   edx
    mov    BYTE PTR [esp+0x34],al
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x2c],bl
    mov    eax,DWORD PTR [esp+0x2c]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch442
    mov    ecx,DWORD PTR [esp+0x18]
    mov    edx,DWORD PTR [esp+0x28]
    mov    eax,DWORD PTR [esp+0x34]
    push   ecx
    push   0x0
    push   edx
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch442:
    push   0x1
    push   0x1
    push   ebp
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x34],bl
    mov    ecx,DWORD PTR [esp+0x34]
    push   ecx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch443
    mov    edx,DWORD PTR [esp+0x38]
    push   0x1
    push   0x0
    push   edx
    push   ebp
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch443:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x3c]
    lea    eax,[ecx+eax*1+0xb]
    jmp    Branch445
    mov    edx,DWORD PTR [esp+0x38]
    mov    esi,DWORD PTR [esp+0x2c]
    mov    edi,DWORD PTR [esp+0x28]
    cmp    BYTE PTR [edx],0x0
    sete   al
    lea    eax,[eax+eax*1+0xd]
    push   eax
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x5
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    lea    ecx,[esp+0x10]
    push   0x1
    mov    ebp,DWORD PTR [esp+0x38]
    push   ecx
    push   ebp
    call   R6GameServiceAddresses::MeasureStoreIntegerEncoding
    push   0x1
    push   0x1
    push   ebp
    mov    BYTE PTR [esp+0x34],al
    call   R6GameServiceAddresses::SelectStoreIntegerEncoding
    mov    bl,al
    mov    BYTE PTR [esp+0x2c],bl
    mov    edx,DWORD PTR [esp+0x2c]
    push   edx
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteCursorByte
    push   0x3
    push   esi
    push   edi
    call   R6GameServiceAddresses::AdvanceBitCursor
    cmp    bl,0x3
    je     Branch444
    mov    eax,DWORD PTR [esp+0x28]
    push   0x1
    push   0x0
    push   eax
    push   ebp
    push   esi
    push   edi
    call   R6GameServiceAddresses::WriteStoreInteger
  Branch444:
    push   esi
    push   edi
    call   R6GameServiceAddresses::PadStoreBitCursor
    mov    ecx,DWORD PTR [esp+0x10]
    lea    eax,[eax+ecx*1+0x8]
  Branch445:
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebp
    test   ecx,ecx
    pop    ebx
    je     Branch446
    mov    DWORD PTR [ecx],eax
  Branch446:
    add    esp,0x14
    ret    0x1c
  }
}

// R6GameService.dll data @ 1001b82c : entry encoder dispatch.
const uint GStoreEntryEncodeTargets[7] = {
  R6GameServiceAddresses::GStoreEntryEncodeTargetsCase1,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase2,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase3,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase4,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase5,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase6,R6GameServiceAddresses::GStoreEntryEncodeTargetsCase7
};

// R6GameService.dll data @ 1001b848 : entry encoder dispatch.
const uint store_codec_supportGStoreEntryEncodeTargets[5] = {
  R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargetsCase1,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargetsCase2,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargetsCase3,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargetsCase4,R6GameServiceAddresses::store_codec_supportBranch362
};

// R6GameService.dll data @ 1001b878 : entry encoder dispatch.
const uint store_codec_supportGStoreEntryEncodeTargets2[5] = {
  R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets2Case1,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets2Case2,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets2Case3,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets2Case4,R6GameServiceAddresses::store_codec_supportBranch378
};

// R6GameService.dll data @ 1001b8a8 : entry encoder dispatch.
const uint store_codec_supportGStoreEntryEncodeTargets3[5] = {
  R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets3Case1,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets3Case2,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets3Case3,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets3Case4,R6GameServiceAddresses::store_codec_supportBranch418
};

// R6GameService.dll data @ 1001b8d8 : entry encoder dispatch.
const uint store_codec_supportGStoreEntryEncodeTargets4[5] = {
  R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets4Case1,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets4Case2,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets4Case3,R6GameServiceAddresses::store_codec_supportGStoreEntryEncodeTargets4Case4,R6GameServiceAddresses::store_codec_supportBranch429
};

// R6GameService.dll data @ 1001b85c : measured bits minus8 to branch index.
const byte GStoreEntryEncodeWidthMap[25] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x3
};

// R6GameService.dll data @ 1001b88c : measured bits minus8 to branch index.
const byte store_codec_supportGStoreEntryEncodeWidthMap[25] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x3
};

// R6GameService.dll data @ 1001b8bc : measured bits minus8 to branch index.
const byte store_codec_supportGStoreEntryEncodeWidthMap2[25] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x3
};

// R6GameService.dll data @ 1001b8ec : measured bits minus8 to branch index.
const byte store_codec_supportGStoreEntryEncodeWidthMap3[25] = {
  0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x1,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,
  0x3
};
