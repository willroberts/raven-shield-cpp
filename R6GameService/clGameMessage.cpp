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

// Allocate and copy an owned payload forward in DWORD/tail order, publishing its cached size only after copying.
// R6GameService.dll @ 1005b830 : source pointer is read after allocation; no local rollback or null-allocation guard.
void * __thiscall ConstructPayloadRecord(
    void *message,uint context,uint word18,uint byte0d,uint byte0e,void *payload,uint size,uint initializeBaseWord)
{
  if (initializeBaseWord != 0) *(uint *)((byte *)message + 4) = R6GameServiceAddresses::ClGameMessageBaseOffsets;
  uint contextValue = context;
  uint length = size;
  byte field0d = (byte)byte0d;
  byte field0e = (byte)byte0e;
  *(uint *)((byte *)message + 8) = contextValue;
  ushort field18 = (ushort)word18;
  *(uint *)message = R6GameServiceAddresses::PTR_FUN;
  *((byte *)message + 0xc) = 1;
  *((byte *)message + 0xd) = field0d;
  *((byte *)message + 0xe) = field0e;
  *(ushort *)((byte *)message + 0x18) = field18;
  uint destination = (uint)AllocateGameServiceBytes(length);
  uint source = (uint)payload;
  *(uint *)((byte *)message + 0x10) = destination;
  uint words = length >> 2;
  while (words != 0) {
    uint value = *(const uint *)source;
    *(uint *)destination = value;
    source += 4;
    destination += 4;
    --words;
  }
  uint tail = length & 3;
  while (tail != 0) {
    byte value = *(const byte *)source;
    *(byte *)destination = value;
    ++source;
    ++destination;
    --tail;
  }
  *(uint *)((byte *)message + 0x14) = length;
  return message;
}

// Destroy owned members, then inspect the current deletion flag and optionally free the cached message allocation.
// R6GameService.dll @ 1005b8b0 : flag bit 0 controls storage release; returns the original receiver.
void * __thiscall clGameMessageDelete(void *message,uint deleteFlags)
{
  using DestroyABI = uint (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::clGameMessageDestroy)(message);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(message);
  return message;
}

// Capture the owned buffer before restoring class identity; free it, then install the base table without clearing fields.
// R6GameService.dll @ 1005b990 : returns zero or raw allocator result; a failed free leaves the derived table installed.
uint __fastcall clGameMessageDestroy(void *message)
{
  uint result = *(uint *)((byte *)message + 0x10);
  *(uint *)message = R6GameServiceAddresses::PTR_FUN;
  if (result != 0) result = TailFreeThroughGlobalAllocator((void *)result);
  *(uint *)message = R6GameServiceAddresses::clMessageVTable;
  return result;
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
uint __stdcall CopyOrQueryPayloadBytes(const byte *source,uint count,byte *destination,uint *size)
{
  byte *out = destination;
  if (out == nullptr) {
    uint *sizeWord = size;
    uint reportedBytes = count;
    *sizeWord = reportedBytes;
    return (uint)sizeWord;
  }
  uint *sizeWord = size;
  uint copiedBytes = count;
  uint availableBytes = *sizeWord;
  if (availableBytes == copiedBytes) {
    const byte *first = source;
    uint words = availableBytes >> 2;
    while (words != 0) {
      uint word = *(const uint *)first;
      *(uint *)out = word;
      first += 4;
      out += 4;
      --words;
    }
    uint tailBytes = copiedBytes & 3;
    while (tailBytes != 0) {
      byte value = *first;
      *out = value;
      ++first;
      ++out;
      --tailBytes;
    }
  }
  return copiedBytes;
}

// Require unsigned size>=7 and exact decoded size, then publish header fields and query the current virtual codec.
// Allocate the queried size without freeing the old buffer; capture the second table before publishing the new buffer.
// R6GameService.dll @ 1005bae0 : ECX/EAX input view, two native stack words/thiscall RET8; no local guard.
uint ParseHeaderAndPayload(
    [[r6abi::register_input("ecx")]] void *message,const byte *input,uint sizeWord,
    [[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  uint size = sizeWord;
  if (size < 7) return eaxAtEntry & 0xffffff00;
  uint base = (uint)message;
  const byte *header = input;
  uint decodedSize = ReadHeaderSize24(header);
  if (decodedSize != size) return decodedSize & 0xffffff00;
  byte lowBits = (byte)ReadHeaderByte3LowBits(header);
  *(byte *)(base + 0xe) = lowBits;
  byte byte4 = (byte)ReadHeaderByte4(header);
  *(byte *)(base + 0xd) = byte4;
  ushort word5 = (ushort)ReadHeaderWord5(header);
  uint *sizeSlot = (uint *)(base + 0x14);
  uint payloadBytes = decodedSize - 7;
  *(ushort *)(base + 0x18) = word5;
  uint firstTable = *(uint *)base;
  const byte *payload = (const byte *)((uint)header + 7);
  using CodecABI = uint (__thiscall *)(void *,const byte *,uint,void *,uint *);
  (*(CodecABI *)(firstTable + 0x18))(message,payload,payloadBytes,nullptr,sizeSlot);
  uint allocationBytes = *sizeSlot;
  uint allocation = (uint)AllocateGameServiceBytes(allocationBytes);
  uint secondTable = *(uint *)base;
  *(uint *)(base + 0x10) = allocation;
  uint result = (*(CodecABI *)(secondTable + 0x18))(message,payload,payloadBytes,(void *)allocation,sizeSlot);
  return (result & 0xffffff00) | 1;
}

// Queries current slot14, transforms payload bytes and prepends a seven-byte header built from current owner fields.
// Reported-size scratch begins with the receiver word; original output argument becomes the late result slot.
// Copies DWORDs then bytes forward, frees cached temporaries without a parent guard and restores scratch in native ECX.
// Header writers consume only the supplied low BYTE/WORD; unused native argument high bits are not semantic inputs.
// R6GameService.dll @ 1005b9b0 : complete native control/access order and raw ABI retained.
void * __thiscall SerializeRawPayloadRecord(void *message,uint *sizeOutput)
{
  void *savedMessage = message;
  uint reportedBytes = (uint)message;
  using CodecABI = uint (__thiscall *)(void *,const byte *,uint,byte *,uint *);
  uint inputBytes = *(uint *)((byte *)savedMessage + 0x14);
  uint table = *(uint *)savedMessage;
  const byte *input = *(const byte **)((byte *)savedMessage + 0x10);
  (*(CodecABI *)(table + 0x14))(savedMessage,input,inputBytes,nullptr,&reportedBytes);
  uint allocationBytes = reportedBytes;
  byte *transformed = (byte *)AllocateGameServiceBytes(allocationBytes);
  inputBytes = *(uint *)((byte *)savedMessage + 0x14);
  table = *(uint *)savedMessage;
  input = *(const byte **)((byte *)savedMessage + 0x10);
  (*(CodecABI *)(table + 0x14))(savedMessage,input,inputBytes,transformed,&reportedBytes);
  uint totalBytes = reportedBytes + 7;
  uint *totalCell = sizeOutput;
  *totalCell = totalBytes;
  byte *header = (byte *)AllocateGameServiceBytes(7);
  *(uint *)header = 0;
  *(ushort *)(header + 4) = 0;
  header[6] = 0;
  WriteHeaderSize24(header,*totalCell);
  WriteHeaderByte3HighBits(header,*((byte *)savedMessage + 0xc));
  SetHeaderByte3Bit5(header,*((byte *)savedMessage + 0xe));
  WriteHeaderByte4(header,*((byte *)savedMessage + 0xd));
  WriteHeaderWord5(header,*(ushort *)((byte *)savedMessage + 0x18));
  byte *packet = (byte *)AllocateGameServiceBytes(*totalCell);
  sizeOutput = (uint *)packet;
  byte *out = packet + 7;
  uint firstWord = *(uint *)header;
  *(uint *)packet = firstWord;
  ushort middleWord = *(ushort *)(header + 4);
  *(ushort *)(packet + 4) = middleWord;
  const byte *first = transformed;
  byte lastByte = header[6];
  packet[6] = lastByte;
  uint copyBytes = reportedBytes;
  uint words = copyBytes >> 2;
  while (words != 0) {
    uint word = *(const uint *)first;
    *(uint *)out = word;
    first += 4;
    out += 4;
    --words;
  }
  uint tailBytes = copyBytes & 3;
  while (tailBytes != 0) {
    byte value = *first;
    *out = value;
    ++first;
    ++out;
    --tailBytes;
  }
  TailFreeThroughGlobalAllocator(header);
  TailFreeThroughGlobalAllocator(transformed);
  return sizeOutput;
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
