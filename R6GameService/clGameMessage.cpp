#include "native_addresses.h"

// Initializes kind-one message metadata and selected header/buffer fields, leaving byte count +14 untouched.
// R6GameService.dll @ 1005b950 : ECX message, context/virtual-base flag stack words, RET 8; EAX=message.
void * __thiscall InitializeClGameMessageFields(void *message,uint contextWord,int initializeVirtualBase)
{
  if (initializeVirtualBase != 0) *(uint *)((byte *)message + 4) = (uint)&ClGameMessageBaseOffsets;
  *(uint *)message = (uint)&PTR_FUN;
  *(uint *)((byte *)message + 8) = contextWord;
  *(byte *)((byte *)message + 0x0c) = 1;
  *(byte *)((byte *)message + 0x0d) = 0;
  *(byte *)((byte *)message + 0x0e) = 0;
  *(ushort *)((byte *)message + 0x18) = 0;
  *(uint *)((byte *)message + 0x10) = 0;
  return message;
}

// Install clGameMessage/header fields, cache full size BEFORE allocation, then reload CURRENT payload pointer and copy forward.
// Retain7 full physical words/RET28, partial WORD/BYTE stores, unchecked allocation, size+14 publication only after complete copy.
// No own EH: outer allocation guard does not release a partially copied owned payload.
// R6GameService.dll @ 1005b830 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructPayloadRecord(void *message,uint context,uint word18,uint byte0d,uint byte0e,void *payload,uint size,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0x20]
    push    ebx
    push    ebp
    push    esi
    test    eax,eax
    push    edi
    mov    ebx,ecx
    mov    DWORD PTR [esp+0x10],0x0
    je    Branch1
    mov    DWORD PTR [ebx+0x4],R6GameServiceAddresses::ClGameMessageBaseOffsets
  Branch1:
    mov    eax,DWORD PTR [esp+0x18]
    mov    ebp,DWORD PTR [esp+0x2c]
    mov    cl,BYTE PTR [esp+0x20]
    mov    dl,BYTE PTR [esp+0x24]
    mov    DWORD PTR [ebx+0x8],eax
    mov    ax,WORD PTR [esp+0x1c]
    push    ebp
    mov    DWORD PTR [ebx],R6GameServiceAddresses::PTR_FUN
    mov    BYTE PTR [ebx+0xc],0x1
    mov    BYTE PTR [ebx+0xd],cl
    mov    BYTE PTR [ebx+0xe],dl
    mov    WORD PTR [ebx+0x18],ax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,DWORD PTR [esp+0x28]
    mov    ecx,ebp
    mov    edx,ecx
    mov    edi,eax
    shr    ecx,0x2
    mov    DWORD PTR [ebx+0x10],eax
    mov    eax,ebx
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    mov    DWORD PTR [ebx+0x14],ebp
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x1c
  }
}

// Destroy owned payload, then read CURRENT full flag low-byte bit0 for optional cached-message free; return cached message/RET4.
// R6GameService.dll @ 1005b8b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clGameMessageDelete(void *message,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::clGameMessageDestroy
    test    BYTE PTR [esp+0x8],0x1
    je    Branch2
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch2:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Cache payload+10 before class table restore, free non-NULL, then install clMessage base table.
// Retain dangling payload/size fields and raw free or NULL EAX; failed free leaves clGameMessage table/no local guard.
// R6GameService.dll @ 1005b990 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall clGameMessageDestroy(void *message)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x10]
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_FUN
    test    eax,eax
    je    Branch3
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch3:
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMessageVTable
    pop    esi
    ret
  }
}

// Copy clGameMessage metadata and publish source size BEFORE allocation; copy CURRENT destination size from late source payload pointer.
// Source object is cached, original pointer argument may change; allocation callbacks can change destination length/source buffer.
// Forward DWORD/tail copy, no own cleanup, preserve padding/optional table and raw physical flag. RET8/message EAX.
// R6GameService.dll @ 1005b8d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall clGameMessageCopyConstruct(void *message,const void *source,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0xc]
    push    ebx
    push    esi
    push    edi
    test    eax,eax
    mov    ebx,ecx
    mov    DWORD PTR [esp+0xc],0x0
    je    Branch4
    mov    DWORD PTR [ebx+0x4],R6GameServiceAddresses::ClGameMessageBaseOffsets
  Branch4:
    mov    esi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ebx+0x8],eax
    mov    cl,BYTE PTR [esi+0xc]
    mov    BYTE PTR [ebx+0xc],cl
    mov    dl,BYTE PTR [esi+0xd]
    mov    BYTE PTR [ebx+0xd],dl
    mov    al,BYTE PTR [esi+0xe]
    mov    BYTE PTR [ebx+0xe],al
    mov    DWORD PTR [ebx],R6GameServiceAddresses::PTR_FUN
    mov    cx,WORD PTR [esi+0x18]
    mov    WORD PTR [ebx+0x18],cx
    mov    eax,DWORD PTR [esi+0x14]
    push    eax
    mov    DWORD PTR [ebx+0x14],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebx+0x14]
    mov    DWORD PTR [ebx+0x10],eax
    mov    esi,DWORD PTR [esi+0x10]
    mov    edx,ecx
    mov    edi,eax
    mov    eax,ebx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    edi
    pop    esi
    pop    ebx
    pop    ecx
    ret    0x8
  }
}

// One shared clGameMessage slot14/18 body; incoming ECX unused. NULL destination stores count and returns size pointer.
// Otherwise copy only when *size==count, using cached count and forward DWORD/BYTE REP; return count even on mismatch.
// RET16.
// R6GameService.dll @ 1005baa0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall CopyOrQueryPayloadBytes(
    const byte *source,uint count,byte *destination,uint *size)
{
  __asm {
    push    edi
    mov    edi,DWORD PTR [esp+0x10]
    test    edi,edi
    jne    Branch5
    mov    eax,DWORD PTR [esp+0x14]
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    DWORD PTR [eax],ecx
    ret    0x10
  Branch5:
    mov    edx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [edx]
    cmp    ecx,eax
    jne    Branch6
    mov    eax,ecx
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    pop    esi
  Branch6:
    pop    edi
    ret    0x10
  }
}

// Unsigned size>=7 and exact three-byte size equality gate header BYTEe/d and little-endian WORD18 updates.
// Query CURRENT slot18 into owner14, allocate reported size, publish owner10 before second CURRENT slot18, then set
// only AL1.
// Keep old buffer/partial effects, raw upper EAX and unconditional success after second return; no parent EH/NULL
// repair. RET8.
// R6GameService.dll @ 1005bae0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseHeaderAndPayload(void *message,const byte *input,uint sizeWord)
{
  __asm {
    push    ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push    esi
    cmp    ebx,0x7
    push    edi
    mov    esi,ecx
    jae    Branch7
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x8
  Branch7:
    mov    edi,DWORD PTR [esp+0x10]
    push    edi
    call    R6GameServiceAddresses::ReadHeaderSize24
    mov    ecx,eax
    cmp    ecx,ebx
    je    Branch8
    pop    edi
    pop    esi
    xor    al,al
    pop    ebx
    ret    0x8
  Branch8:
    push    ebp
    push    edi
    call    R6GameServiceAddresses::ReadHeaderByte3LowBits
    push    edi
    mov    BYTE PTR [esi+0xe],al
    call    R6GameServiceAddresses::ReadHeaderByte4
    push    edi
    mov    BYTE PTR [esi+0xd],al
    call    R6GameServiceAddresses::ReadHeaderWord5
    lea    ebx,[esi+0x14]
    lea    ebp,[ecx-0x7]
    push    ebx
    mov    WORD PTR [esi+0x18],ax
    mov    eax,DWORD PTR [esi]
    add    edi,0x7
    push    0x0
    push    ebp
    push    edi
    mov    ecx,esi
    call    DWORD PTR [eax+0x18]
    mov    ecx,DWORD PTR [ebx]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esi]
    push    ebx
    push    eax
    push    ebp
    push    edi
    mov    ecx,esi
    mov    DWORD PTR [esi+0x10],eax
    call    DWORD PTR [edx+0x18]
    pop    ebp
    pop    edi
    pop    esi
    mov    al,0x1
    pop    ebx
    ret    0x8
  }
}

// Query/current slot14 then allocate transformed bytes and reload current owner10/14 for output call, ignoring raw
// status.
// Build cleared seven-byte header from current owner fields, use current total/copy counts and reuse original output
// argument for result.
// LocalS-4 begins saved incoming ECX, not zero. Free cached header/transformed allocations and return saved result.
// POP ECX restores current reported-size scratch. No
// parent EH. RET4.
// R6GameService.dll @ 1005b9b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall SerializeRawPayloadRecord(void *message,uint *sizeOutput)
{
  __asm {
    push    ecx
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    lea    ecx,[esp+0xc]
    push    edi
    mov    edx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [esi]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push    0x0
    push    edx
    push    ecx
    mov    ecx,esi
    call    DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esi+0x14]
    lea    ecx,[esp+0x10]
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    push    ecx
    mov    ecx,DWORD PTR [esi+0x10]
    push    ebp
    push    edx
    push    ecx
    mov    ecx,esi
    call    DWORD PTR [eax+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x18]
    add    edx,0x7
    push    0x7
    mov    DWORD PTR [edi],edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    xor    eax,eax
    mov    ecx,ebx
    mov    DWORD PTR [ecx],eax
    mov    WORD PTR [ecx+0x4],ax
    mov    BYTE PTR [ecx+0x6],al
    mov    edx,DWORD PTR [edi]
    push    edx
    push    ebx
    call    R6GameServiceAddresses::WriteHeaderSize24
    mov    al,BYTE PTR [esi+0xc]
    push    eax
    push    ebx
    call    R6GameServiceAddresses::WriteHeaderByte3HighBits
    mov    cl,BYTE PTR [esi+0xe]
    push    ecx
    push    ebx
    call    R6GameServiceAddresses::SetHeaderByte3Bit5
    mov    dl,BYTE PTR [esi+0xd]
    push    edx
    push    ebx
    call    R6GameServiceAddresses::WriteHeaderByte4
    mov    ax,WORD PTR [esi+0x18]
    push    eax
    push    ebx
    call    R6GameServiceAddresses::WriteHeaderWord5
    mov    ecx,DWORD PTR [edi]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,ebx
    mov    ecx,eax
    mov    DWORD PTR [esp+0x18],eax
    lea    edi,[eax+0x7]
    mov    esi,DWORD PTR [edx]
    mov    DWORD PTR [ecx],esi
    mov    si,WORD PTR [edx+0x4]
    mov    WORD PTR [ecx+0x4],si
    mov    esi,ebp
    mov    dl,BYTE PTR [edx+0x6]
    mov    BYTE PTR [ecx+0x6],dl
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    ebp
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Read CURRENT payload10 BYTE0 without consulting count14; dispatch event label or zero-extended decimal fallback.
// Preserve native two-word literal/three-word numeric sprintf calls and raw imported EAX/RET4.
// R6GameService.dll @ 1005bc10 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall FormatPayloadEvent(void *message,char *output)
{
  __asm {
    mov    eax,DWORD PTR [ecx+0x10]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax]
    lea    eax,[ecx-0xef]
    cmp    eax,0xb
    ja    Branch9
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GGameDiagnosticTargets]
    mov    ecx,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTREGISTER
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    edx,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTOWNID
    push    edx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    eax,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTNEWPLAYER
    push    eax
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    ecx,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTPLAYERLEFT
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    edx,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTNEWMASTER
    push    edx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    eax,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTSERVERTIME
    push    eax
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
    mov    ecx,DWORD PTR [esp+0x4]
    push    R6GameServiceAddresses::TextEVENTPLAYERINFOS
    push    ecx
    call    R6GameServiceAddresses::sprintf
    add    esp,0x8
    ret    0x4
  Branch9:
    mov    edx,DWORD PTR [esp+0x4]
    push    ecx
    push    R6GameServiceAddresses::TextSignedDecimalFormat
    push    edx
    call    R6GameServiceAddresses::sprintf
    add    esp,0xc
    ret    0x4
  }
}

// Print current send/event labels, signed WORD18 sender, then unsigned bytes with trailing dashes and final newline.
// Reload current payload10/count14 each iteration; keep printf batching/raw final EAX and no local guard. ECX-only.
// R6GameService.dll @ 1005bd10 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PrintPayloadRecordDiagnostic(void *message)
{
  __asm {
    sub    esp,0x80
    lea    eax,[esp+0x0]
    push    esi
    mov    esi,ecx
    push    edi
    push    eax
    mov    cl,BYTE PTR [esi+0xd]
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatSendTarget
    lea    edx,[esp+0x8]
    push    edx
    push    R6GameServiceAddresses::TextS7
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    lea    eax,[esp+0x8]
    mov    ecx,esi
    push    eax
    call    R6GameServiceAddresses::FormatPayloadEvent
    lea    ecx,[esp+0x8]
    push    ecx
    push    R6GameServiceAddresses::TextS6
    call    R6GameServiceAddresses::printf
    movsx    edx,WORD PTR [esi+0x18]
    push    edx
    push    R6GameServiceAddresses::TextSenderD
    call    R6GameServiceAddresses::printf
    push    R6GameServiceAddresses::TextMessage
    call    R6GameServiceAddresses::printf
    mov    eax,DWORD PTR [esi+0x14]
    add    esp,0x14
    xor    edi,edi
    test    eax,eax
    jbe    Branch11
  Branch10:
    mov    eax,DWORD PTR [esi+0x10]
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+edi*1]
    push    ecx
    push    R6GameServiceAddresses::TextD2
    call    R6GameServiceAddresses::printf
    mov    eax,DWORD PTR [esi+0x14]
    add    esp,0x8
    inc    edi
    cmp    edi,eax
    jb    Branch10
  Branch11:
    push    R6GameServiceAddresses::WideTextPunctuation8
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    pop    edi
    pop    esi
    add    esp,0x80
    ret
  }
}

// Append native send/event/signed-sender/unsigned-payload diagnostic with exact scans and retained BYTE tag copies.
// EntryS: tagsS-a2/a1, decimalS-a0, labelS-80; cache destination after first label/scan and reload payload10/count14 in
// loop.
// Preserve no parent guard/rollback and raw final append EAX (normally destination)/RET4.
// R6GameService.dll @ 1005bdb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendPayloadRecordDiagnostic(void *message,void *destination)
{
  __asm {
    sub    esp,0xa4
    push    ebx
    push    ebp
    mov    ebp,ecx
    push    esi
    lea    eax,[esp+0x30]
    push    edi
    mov    cl,BYTE PTR [ebp+0xd]
    push    eax
    push    ecx
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatSendTarget
    lea    eax,[esp+0x13]
    lea    edi,[esp+0x34]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x16]
    repnz    scas al,BYTE PTR es:[edi]
    mov    esi,DWORD PTR [esp+0xbc]
    mov    BYTE PTR [esp+0x17],dl
    not    ecx
    dec    ecx
    lea    edx,[esp+0x38]
    lea    ecx,[esp+ecx*1+0x38]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x12]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextPunctuation10
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextPunctuation10
    push    ecx
    push    R6GameServiceAddresses::WideTextPunctuation10
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    lea    edx,[esp+0x34]
    mov    ecx,ebp
    push    edx
    call    R6GameServiceAddresses::FormatPayloadEvent
    mov    al,BYTE PTR [esp+0x12]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    lea    edi,[esp+0x38]
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x38]
    lea    edx,[esp+ecx*1+0x38]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    cl,BYTE PTR [esp+0x12]
    mov    edi,R6GameServiceAddresses::TextPunctuation7
    mov    BYTE PTR [esp+0x13],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x13]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextPunctuation7
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation7
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x12]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextSender
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextSender
    push    ecx
    push    R6GameServiceAddresses::TextSender
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    movsx    edx,WORD PTR [ebp+0x18]
    push    edx
    lea    eax,[esp+0x18]
    push    R6GameServiceAddresses::TextSignedDecimalFormat
    push    eax
    call    R6GameServiceAddresses::sprintf
    add    esp,0xc
    lea    ecx,[esp+0x13]
    lea    edi,[esp+0x14]
    xor    eax,eax
    push    ecx
    or    ecx,0xffffffff
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x18]
    lea    edx,[esp+ecx*1+0x18]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    cl,BYTE PTR [esp+0x12]
    mov    edi,R6GameServiceAddresses::TextMessage
    mov    BYTE PTR [esp+0x12],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x12]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextMessage
    push    ecx
    push    R6GameServiceAddresses::TextMessage
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    eax,DWORD PTR [ebp+0x14]
    xor    ebx,ebx
    test    eax,eax
    jbe    Branch13
  Branch12:
    mov    eax,DWORD PTR [ebp+0x10]
    xor    ecx,ecx
    lea    edx,[esp+0x14]
    mov    cl,BYTE PTR [eax+ebx*1]
    push    ecx
    push    R6GameServiceAddresses::TextSignedDecimalFormat
    push    edx
    call    R6GameServiceAddresses::sprintf
    mov    al,BYTE PTR [esp+0x1e]
    add    esp,0xc
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    lea    edi,[esp+0x18]
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x18]
    lea    edx,[esp+ecx*1+0x18]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    cl,BYTE PTR [esp+0x12]
    mov    edi,R6GameServiceAddresses::WideTextPunctuation9
    mov    BYTE PTR [esp+0x13],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x13]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::WideTextPunctuation9
    push    ecx
    push    R6GameServiceAddresses::WideTextPunctuation9
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    eax,DWORD PTR [ebp+0x14]
    inc    ebx
    cmp    ebx,eax
    jb    Branch12
  Branch13:
    mov    al,BYTE PTR [esp+0x12]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextPunctuation8
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextPunctuation8
    push    ecx
    push    R6GameServiceAddresses::WideTextPunctuation8
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xa4
    ret    0x4
  }
}

// Literal native diagnostic formatter dispatch table.
// R6GameService.dll data @ 1005bcd8 : native storage identity retained.
const uint GGameDiagnosticTargets[12] = {
    R6GameServiceAddresses::GGameDiagnosticTargetsCase1,R6GameServiceAddresses::GGameDiagnosticTargetsCase2,R6GameServiceAddresses::GGameDiagnosticTargetsCase3,R6GameServiceAddresses::GGameDiagnosticTargetsCase4,R6GameServiceAddresses::GGameDiagnosticTargetsCase5,R6GameServiceAddresses::clGameMessageBranch9,
    R6GameServiceAddresses::clGameMessageBranch9,R6GameServiceAddresses::clGameMessageBranch9,R6GameServiceAddresses::clGameMessageBranch9,R6GameServiceAddresses::clGameMessageBranch9,R6GameServiceAddresses::GGameDiagnosticTargetsCase11,R6GameServiceAddresses::GGameDiagnosticTargetsCase12
};
