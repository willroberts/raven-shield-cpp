#include "native_addresses.h"
#include "native_records.h"

// Shared crypto helper instance16 and global PRNG/PKC/crypto/table state; original whole-class declaration unresolved.

// Publish mode, clear local buffer, initialize shared PRNG/PKC/crypto handles/tables on initial count0, optionally build mode1 state.
// ENTRY ESP S: bitsS-34/ownerS-30/zeroed32-byte seedS-2c/stateS-4; optional base table78230 is an offset table.
// Seed is zero-extended time32+1 with carry, formatted as literal %lld; retain current globals across callbacks.
// Only empty-base cleanup is guarded. Partial globals/instance allocations survive failure; count increments late. RET8/owner.
// R6GameService.dll @ 1005c170 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructSharedCryptoContext(void *owner,uint mode,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSharedCryptoCtorEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    mov    eax,DWORD PTR [esp+0x3c]
    push    ebx
    push    esi
    xor    ebx,ebx
    mov    esi,ecx
    cmp    eax,ebx
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esp+0x8],ebx
    je    Branch1
    mov    DWORD PTR [esi],0x10078230
    mov    DWORD PTR [esp+0x8],0x1
    mov    DWORD PTR [esp+0x38],ebx
  Branch1:
    mov    eax,DWORD PTR [esp+0x40]
    mov    ds:0x100945ac,eax
    mov    DWORD PTR [esi+0x8],ebx
    mov    DWORD PTR [esi+0xc],ebx
    mov    eax,ds:0x10094598
    cmp    eax,ebx
    jne    Branch2
    push    edi
    push    R6GameServiceAddresses::TextGlobalInitialization
    call    R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,0x8
    xor    eax,eax
    lea    edi,[esp+0x18]
    push    ebx
    rep    stos DWORD PTR es:[edi],eax
    call    R6GameServiceAddresses::time
    xor    ecx,ecx
    add    eax,0x1
    adc    ecx,ebx
    push    ecx
    push    eax
    push    R6GameServiceAddresses::TextLld
    lea    ecx,[esp+0x28]
    push    0x1f
    push    ecx
    call    R6GameServiceAddresses::_snprintf
    lea    edi,[esp+0x30]
    or    ecx,0xffffffff
    xor    eax,eax
    add    esp,0x1c
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    edx,[esp+0x14]
    push    ecx
    push    edx
    push    0x1
    push    ebx
    call    R6GameServiceAddresses::CreateRegisteredPRNGAlgorithmThunk
    push    ebx
    mov    ds:0x10094590,eax
    call    R6GameServiceAddresses::CreateRegisteredPKCAlgorithmThunk
    push    ebx
    push    R6GameServiceAddresses::GRegistrationEmptyText
    push    0x1
    mov    ds:0x1009458c,eax
    call    R6GameServiceAddresses::CreateRegisteredCryptoAlgorithmThunk
    mov    ecx,esi
    mov    ds:0x10094594,eax
    call    R6GameServiceAddresses::InitializeSharedServiceTables
    pop    edi
  Branch2:
    mov    DWORD PTR [esi+0x4],ebx
    mov    eax,ds:0x100945ac
    dec    eax
    jne    Branch3
    push    0x10
    mov    ecx,esi
    call    R6GameServiceAddresses::ResizeSharedContextBuffer
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x8]
    push    eax
    push    ecx
    push    ebx
    call    R6GameServiceAddresses::CreateRegisteredCryptoAlgorithmThunk
    mov    DWORD PTR [esi+0x4],eax
    mov    eax,ds:0x10094598
    cmp    eax,ebx
    jne    Branch3
    mov    ecx,esi
    call    R6GameServiceAddresses::PollAndForwardSharedRecords
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCryptoMetadata
    mov    ecx,esi
    mov    DWORD PTR [edx],0x200
    mov    eax,ds:R6GameServiceAddresses::GCryptoMetadata
    mov    DWORD PTR [eax+0x4],ebx
    call    R6GameServiceAddresses::FinalizeSharedContextTables
  Branch3:
    mov    eax,ds:0x10094598
    mov    ecx,DWORD PTR [esp+0x30]
    inc    eax
    mov    DWORD PTR fs:0x0,ecx
    mov    ds:0x10094598,eax
    mov    eax,esi
    pop    esi
    pop    ebx
    add    esp,0x34
    ret    0x8
  }
}

// Decrement shared count modulo32 BEFORE cleanup; free current buffer, clear8/c, release current handle4 without nulling.
// Recheck live count for global table/crypto/PKC/PRNG shutdown; handles stay populated, no local guard/rollback.
// R6GameService.dll @ 1005c2c0 : void inferred from its sole retail caller, which discards EAX.
void __fastcall DestroySharedCryptoContext(void *owner)
{
  uint count = *(uint *)0x10094598 - 1;
  uint base = (uint)owner;
  *(uint *)0x10094598 = count;
  void *buffer = *(void **)(base + 8);
  if (buffer != 0) TailFreeThroughGlobalAllocator(buffer);
  uint handle = *(uint *)(base + 4);
  *(uint *)(base + 8) = 0;
  *(uint *)(base + 0xc) = 0;
  using ReleaseABI = void (__stdcall *)(uint);
  if (handle != 0) ((ReleaseABI)R6GameServiceAddresses::ReleaseCryptoAlgorithmOrRegistry)(handle);
  uint result = *(uint *)0x10094598;
  if (result != 0) return;
  using EmptyABI = void (__cdecl *)(const char *);
  ((EmptyABI)R6GameServiceAddresses::list_node_support_NoOp)(
      (const char *)R6GameServiceAddresses::TextGlobalUninitialization);
  using TablesABI = uint (__cdecl *)(void);
  ((TablesABI)R6GameServiceAddresses::FreeSharedContextBuffers)();
  uint crypto = *(uint *)0x10094594;
  ((ReleaseABI)R6GameServiceAddresses::ReleaseCryptoAlgorithmOrRegistry)(crypto);
  uint pkc = *(uint *)0x1009458c;
  ((ReleaseABI)R6GameServiceAddresses::ReleasePKCAlgorithmOrRegistry)(pkc);
  uint prng = *(uint *)0x10094590;
  ((ReleaseABI)R6GameServiceAddresses::ReleasePRNGAlgorithmOrRegistry)(prng);
}

// Free prior tables, publish all four allocations28/104/2c4/8 without early NULL exit, then test live pointers and return AL.
// Upper EAX is final allocation; partial publication survives failure, no own guard.
// R6GameService.dll @ 1005c500 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl InitializeSharedServiceTables(void)
{
  __asm {
    call    R6GameServiceAddresses::FreeSharedContextBuffers
    push    0x28
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    0x104
    mov    ds:R6GameServiceAddresses::GCryptoHeaderTable,eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    0x2c4
    mov    ds:R6GameServiceAddresses::GCryptoKeyBuffer,eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    0x8
    mov    ds:R6GameServiceAddresses::GCryptoSecondaryKeyBuffer,eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    ds:R6GameServiceAddresses::GCryptoMetadata,eax
    test    ecx,ecx
    je    Branch7
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCryptoKeyBuffer
    test    ecx,ecx
    je    Branch7
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCryptoSecondaryKeyBuffer
    test    ecx,ecx
    je    Branch7
    test    eax,eax
    je    Branch7
    mov    al,0x1
    ret
  Branch7:
    xor    al,al
    ret
  }
}

// Reload/free each CURRENT shared table in order, then clear all four slots only after every release returns.
// A failed release leaves earlier slots dangling; never retry or invent per-slot early nulling. Raw final EAX.
// R6GameService.dll @ 1005c570 : complete native control/access order and raw ABI retained.
uint __cdecl FreeSharedContextBuffers(void)
{
  void *header = *(void **)R6GameServiceAddresses::GCryptoHeaderTable;
  if (header != 0) TailFreeThroughGlobalAllocator(header);
  void *key = *(void **)R6GameServiceAddresses::GCryptoKeyBuffer;
  if (key != 0) TailFreeThroughGlobalAllocator(key);
  void *secondary = *(void **)R6GameServiceAddresses::GCryptoSecondaryKeyBuffer;
  if (secondary != 0) TailFreeThroughGlobalAllocator(secondary);
  uint result = *(uint *)R6GameServiceAddresses::GCryptoMetadata;
  if (result != 0) result = TailFreeThroughGlobalAllocator((void *)result);
  *(uint *)R6GameServiceAddresses::GCryptoHeaderTable = 0;
  *(uint *)R6GameServiceAddresses::GCryptoKeyBuffer = 0;
  *(uint *)R6GameServiceAddresses::GCryptoSecondaryKeyBuffer = 0;
  *(uint *)R6GameServiceAddresses::GCryptoMetadata = 0;
  return result;
}

// Time first; unsigned sizes below16 return timer EAX with AL0. Else free old, allocate/publish requested buffer/size,
// seed through current global PRNG and return final timer upper bits/AL1. NULL and partial effects are unchecked.
// R6GameService.dll @ 1005c5d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ResizeSharedContextBuffer(void *owner,uint requestedBytes)
{
  __asm {
    push    esi
    push    edi
    mov    esi,ecx
    call    R6GameServiceAddresses::GetElapsedMilliseconds
    mov    edi,DWORD PTR [esp+0xc]
    cmp    edi,0x10
    jae    Branch12
    pop    edi
    xor    al,al
    pop    esi
    ret    0x4
  Branch12:
    mov    eax,DWORD PTR [esi+0x8]
    test    eax,eax
    je    Branch13
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch13:
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    push    edi
    mov    DWORD PTR [esi+0x8],eax
    mov    DWORD PTR [esi+0xc],edi
    push    eax
    mov    eax,ds:0x10094590
    push    eax
    call    R6GameServiceAddresses::FillPRNGBytesThunk
    call    R6GameServiceAddresses::GetElapsedMilliseconds
    pop    edi
    mov    al,0x1
    pop    esi
    ret    0x4
  }
}

// Snapshot current table/PKC words after timing, generate records, then reload PKC/header for random-state clear.
// Return saved generator AL with final timer upper EAX; neither later status is a success gate.
// R6GameService.dll @ 1005c620 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl FinalizeSharedContextTables(void)
{
  __asm {
    push    ebx
    call    R6GameServiceAddresses::GetElapsedMilliseconds
    mov    eax,ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCryptoMetadata
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCryptoSecondaryKeyBuffer
    push    eax
    mov    eax,ds:R6GameServiceAddresses::GCryptoKeyBuffer
    push    ecx
    mov    ecx,DWORD PTR ds:0x1009458c
    push    edx
    push    eax
    push    ecx
    call    R6GameServiceAddresses::GeneratePKCKeyRecordsThunk
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    bl,al
    mov    eax,ds:0x1009458c
    push    edx
    push    eax
    call    R6GameServiceAddresses::ClearPKCRandomStateThunk
    call    R6GameServiceAddresses::GetElapsedMilliseconds
    mov    al,bl
    pop    ebx
    ret
  }
}

// Poll required byte count, allocate/seed/forward each buffer, poll NEXT count BEFORE freeing current buffer, repeat until0.
// Reload globals and current stack count around each call; no parent guard or NULL repair. Tail-return final timer EAX.
// R6GameService.dll @ 1005c670 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl PollAndForwardSharedRecords(void)
{
  __asm {
    push    ecx
    call    R6GameServiceAddresses::GetElapsedMilliseconds
    mov    eax,ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    ecx,DWORD PTR ds:0x1009458c
    push    eax
    push    ecx
    call    R6GameServiceAddresses::InitializePKCRandomStateThunk
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    ecx,DWORD PTR ds:0x1009458c
    lea    eax,[esp+0x0]
    push    edx
    push    eax
    push    ecx
    mov    DWORD PTR [esp+0xc],0x0
    call    R6GameServiceAddresses::ReadPKCSeedBytesNeededLowByte
    mov    eax,DWORD PTR [esp+0x0]
    test    eax,eax
    je    Branch15
    push    esi
  Branch14:
    push    eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edx,DWORD PTR [esp+0x4]
    mov    esi,eax
    mov    eax,ds:0x10094590
    push    edx
    push    esi
    push    eax
    call    R6GameServiceAddresses::FillPRNGBytesThunk
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    eax,ds:0x1009458c
    push    ecx
    push    esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::UpdatePKCRandomSeedThunk
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    eax,ds:0x1009458c
    lea    edx,[esp+0x4]
    push    ecx
    push    edx
    push    eax
    call    R6GameServiceAddresses::ReadPKCSeedBytesNeededLowByte
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x4]
    test    eax,eax
    jne    Branch14
    pop    esi
  Branch15:
    add    esp,0x4
    jmp    R6GameServiceAddresses::GetElapsedMilliseconds
  }
}

// Only construction bit0 invokes the genuine no-op for current saved owner+10; no resource release belongs here.
// R6GameService.dll @ 10069a20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructSharedCryptoContextUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x34]
    and    eax,0x1
    test    eax,eax
    je    Branch16
    mov    ecx,DWORD PTR [ebp-0x30]
    add    ecx,0x10
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch16:
    ret
  }
}

// Select single empty-base cleanup FuncInfo844d4, then tail CRT exception dispatch.
// R6GameService.dll @ 10069a3a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSharedCryptoCtorEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructSharedCryptoContextExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native empty-base map/FuncInfo does not own published crypto/table/buffer resources.
// R6GameService.dll data @ 100844cc : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructSharedCryptoContextUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ConstructSharedCryptoContextUnwind1},
};

// Literal native empty-base map/FuncInfo does not own published crypto/table/buffer resources.
// R6GameService.dll data @ 100844d4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructSharedCryptoContextExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::ConstructSharedCryptoContextUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Inferred two-word source view: borrowed bytes pointer and requested byte count.
struct BufferDescriptor {
  const undefined1 *data;
  uint byteCount;
};

// Poll shared state first, then forward CURRENT arguments/header/PKC to encode37470; return raw result/RET20.
// R6GameService.dll @ 1005c340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchSharedSlot8(const void *input,uint context8,uint contextC,void *output,uint *outputSize)
{
  __asm {
    call    R6GameServiceAddresses::PollAndForwardSharedRecords
    mov    eax,ds:R6GameServiceAddresses::GCryptoHeaderTable
    mov    ecx,DWORD PTR [esp+0x4]
    mov    edx,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,DWORD PTR [esp+0x14]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x14]
    push    edx
    mov    edx,DWORD PTR [esp+0x14]
    push    eax
    mov    eax,ds:0x1009458c
    push    ecx
    push    edx
    push    eax
    call    R6GameServiceAddresses::EncodePKCType2BlockThunk
    ret    0x14
  }
}

// Forward CURRENT input/size/output/size-pointer with shared PKC and table945a4 to decode37480; raw EAX/RET16.
// R6GameService.dll @ 1005c380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall DispatchSharedSlot14(const void *input,uint inputSize,void *output,uint *outputSize)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GCryptoSecondaryKeyBuffer
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    push    eax
    mov    eax,DWORD PTR [esp+0xc]
    push    ecx
    mov    ecx,DWORD PTR [esp+0xc]
    push    edx
    mov    edx,DWORD PTR ds:0x1009458c
    push    eax
    push    ecx
    push    edx
    call    R6GameServiceAddresses::DecodePKCType2BlockThunk
    ret    0x10
  }
}

// Free old buffer, reload CURRENT source argument, publish size before allocation, then copy CURRENT helper+c bytes from late source pointer.
// Size can change during allocation. Forward DWORDs then bytes, unchecked NULL/overlap; mode1 refreshes live handle4 after copy.
// No own EH/rollback; return mode-1 residue when mode differs, new crypto handle otherwise. RET4.
// R6GameService.dll @ 1005c490 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceSharedByteBuffer(void *helper,const BufferDescriptor *source)
{
  __asm {
    push    ebx
    mov    ebx,ecx
    mov    eax,DWORD PTR [ebx+0x8]
    test    eax,eax
    je    Branch17
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch17:
    push    esi
    mov    esi,DWORD PTR [esp+0xc]
    push    edi
    mov    eax,DWORD PTR [esi+0x4]
    push    eax
    mov    DWORD PTR [ebx+0xc],eax
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [ebx+0xc]
    mov    DWORD PTR [ebx+0x8],eax
    mov    esi,DWORD PTR [esi]
    mov    edi,eax
    mov    eax,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,eax
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    mov    eax,ds:0x100945ac
    pop    edi
    dec    eax
    pop    esi
    jne    Branch18
    mov    ecx,DWORD PTR [ebx+0x4]
    push    ecx
    call    R6GameServiceAddresses::ReleaseCryptoAlgorithmOrRegistry
    mov    edx,DWORD PTR [ebx+0xc]
    mov    eax,DWORD PTR [ebx+0x8]
    push    edx
    push    eax
    push    0x0
    call    R6GameServiceAddresses::CreateRegisteredCryptoAlgorithmThunk
    mov    DWORD PTR [ebx+0x4],eax
  Branch18:
    pop    ebx
    ret    0x4
  }
}

// Selector2 tries instance+4; other nonzero selectors try shared94594; zero/null falls back to mode945ac==1 instance.
// Rewrite original five stack words to handle/word0/word1/word2/word3, then tail-dispatch slot+0c. No local EH.
// R6GameService.dll @ 1005c3b0 : complete native control/access order and raw ABI retained.
uint __thiscall DispatchThroughSelectedSlot0C(
    void *selectorState,uint word0,uint word1,uint word2,uint word3,uint selector)
{
  uint requested = selector;
  uint shared = *(uint *)0x10094594;
  uint selected = 0;
  if (requested != 0) {
    selected = requested == 2 ? *(uint *)((uint)selectorState + 4) : shared;
  }
  if (selected == 0) {
    uint mode = *(uint *)0x100945ac;
    selected = mode == 1 ? *(uint *)((uint)selectorState + 4) : shared;
  }
  uint last = word3;
  uint third = word2;
  selector = last;
  uint second = word1;
  word3 = third;
  uint first = word0;
  word2 = second;
  word1 = first;
  word0 = selected;
  using DispatchABI = uint (__stdcall *)(void *,const byte *,uint,byte *,uint *);
  return ((DispatchABI)R6GameServiceAddresses::EncodeCryptoBufferThunk)(
      (void *)word0,(const byte *)word1,word2,(byte *)word3,(uint *)selector);
}

// Selector2 tries instance+4; other nonzero selectors try shared94594; zero/null falls back to mode945ac==1 instance.
// Rewrite original five stack words to handle/word0/word1/word2/word3, then tail-dispatch slot+10. No local EH.
// R6GameService.dll @ 1005c410 : complete native control/access order and raw ABI retained.
uint __thiscall DispatchThroughSelectedSlot10(
    void *selectorState,uint word0,uint word1,uint word2,uint word3,uint selector)
{
  uint requested = selector;
  uint shared = *(uint *)0x10094594;
  uint selected = 0;
  if (requested != 0) {
    selected = requested == 2 ? *(uint *)((uint)selectorState + 4) : shared;
  }
  if (selected == 0) {
    uint mode = *(uint *)0x100945ac;
    selected = mode == 1 ? *(uint *)((uint)selectorState + 4) : shared;
  }
  uint last = word3;
  uint third = word2;
  selector = last;
  uint second = word1;
  word3 = third;
  uint first = word0;
  word2 = second;
  word1 = first;
  word0 = selected;
  using DispatchABI = uint (__stdcall *)(void *,const byte *,uint,byte *,uint *);
  return ((DispatchABI)R6GameServiceAddresses::DecodeCryptoBufferThunk)(
      (void *)word0,(const byte *)word1,word2,(byte *)word3,(uint *)selector);
}

// Copy65 DWORDs forward from the shared table945a0; source is captured once, overlapping ranges retain REP order.
// Preserve EAX and caller ESI/EDI, leave ECX0, RET4; caller58500 sends the resulting260-byte record.
// R6GameService.dll @ 1005c470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall CopyGlobalWordTablePrefix(undefined4 *destination)
{
  __asm {
    push    esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::GCryptoKeyBuffer
    push    edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    ecx,0x41
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    pop    edi
    pop    esi
    ret    0x4
  }
}
