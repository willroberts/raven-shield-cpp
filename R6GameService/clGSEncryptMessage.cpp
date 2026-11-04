#include "native_addresses.h"
#include "native_records.h"

// Optionally install derived virtual-base table; forward six full words and literal base flag0, then publish derived
// table/kind2.
// Preserve zeroed local/ECX0, original receiver return/RET28; no derived cleanup frame.
// R6GameService.dll @ 1005c000 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructClGSEncryptMessage(
    void *message,uint contextWord,uint codeWord,uint byte0eWord,uint byte10Word,uint byte11Word,
    uint     sourceWord,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0x20]
    push    esi
    test    eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je    Branch1
    mov    DWORD PTR [esi+0x4],0x10078228
  Branch1:
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edx,DWORD PTR [esp+0x18]
    push    0x0
    push    eax
    mov    eax,DWORD PTR [esp+0x1c]
    push    ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    push    edx
    mov    edx,DWORD PTR [esp+0x1c]
    push    eax
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::ConstructClGSMessage
    mov    DWORD PTR [esi],R6GameServiceAddresses::clGSEncryptMessageVTable
    mov    BYTE PTR [esi+0xc],0x2
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x1c
  }
}

// Destroy owned members, then inspect the current deletion flag and optionally free the cached message allocation.
// R6GameService.dll @ 1005c060 : flag bit 0 controls storage release; returns the original receiver.
void * __thiscall DeleteClGSEncryptMessage(void *message,uint deleteFlags)
{
  using DestroyABI = void (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyClGSEncryptMessage)(message);
  if ((deleteFlags & 1) != 0) TailFreeThroughGlobalAllocator(message);
  return message;
}

// Forward shared destruction with its inferred void ABI; the deleting caller replaces native EAX residue.
// R6GameService.dll @ 1005c080 : native tail alias; no additional derived-table publication.
void __fastcall DestroyClGSEncryptMessage(void *message)
{
  using DestroyABI = void (__fastcall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::DestroyClGSMessage)(message);
}

// Initialize shared message fields with base initialization disabled, then install encrypted identity and kind two.
// R6GameService.dll @ 1005c090 : optional derived base-offset table precedes context sampling and base initialization.
void * __thiscall InitializeClGSEncryptMessageFields(void *message,uint contextWord,uint initializeBaseWord)
{
  if (initializeBaseWord != 0) *(uint *)((byte *)message + 4) = 0x10078228;
  uint context = contextWord;
  using InitializeABI = void * (__thiscall *)(void *,uint,uint);
  ((InitializeABI)R6GameServiceAddresses::InitializeClGSMessageFields)(message,context,0);
  *(uint *)message = R6GameServiceAddresses::clGSEncryptMessageVTable;
  *((byte *)message + 0xc) = 2;
  return message;
}

// Forward four words through the current helper using the encrypted-family selector two.
// R6GameService.dll @ 1005c0d0 : helper at +8 is sampled between the high and low argument pairs.
uint __thiscall DispatchEncryptedMessageSlot0C(void *message,uint word0,uint word1,uint word2,uint word3)
{
  uint last = word3;
  uint third = word2;
  void *helper = *(void **)((byte *)message + 8);
  uint second = word1;
  uint first = word0;
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchThroughSelectedSlot0C)(helper,first,second,third,last,2);
}

// Forward four words through the current helper using the encrypted-family selector two.
// R6GameService.dll @ 1005c100 : helper at +8 is sampled between the high and low argument pairs.
uint __thiscall DispatchEncryptedMessageSlot10(void *message,uint word0,uint word1,uint word2,uint word3)
{
  uint last = word3;
  uint third = word2;
  void *helper = *(void **)((byte *)message + 8);
  uint second = word1;
  uint first = word0;
  using DispatchABI = uint (__thiscall *)(void *,uint,uint,uint,uint,uint);
  return ((DispatchABI)R6GameServiceAddresses::DispatchThroughSelectedSlot10)(helper,first,second,third,last,2);
}

// Native virtual-table prefix: clGSEncryptMessageVTable
// R6GameService.dll data @ 1007820c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGSEncryptMessageVTableRecord {
  R6GameServiceNative::Address DeleteClGSEncryptMessage; // +0x00
  R6GameServiceNative::Address SerializePayloadRecord; // +0x04
  R6GameServiceNative::Address AppendDecodedRecordText; // +0x08
  R6GameServiceNative::Address PrintDecodedRecord; // +0x0c
  R6GameServiceNative::Address DecodePayloadRecord; // +0x10
  R6GameServiceNative::Address DispatchEncryptedMessageSlot0C; // +0x14
  R6GameServiceNative::Address DispatchEncryptedMessageSlot10; // +0x18
};
const clGSEncryptMessageVTableRecord clGSEncryptMessageVTable = {
  R6GameServiceAddresses::DeleteClGSEncryptMessage,
  R6GameServiceAddresses::SerializePayloadRecord,
  R6GameServiceAddresses::AppendDecodedRecordText,
  R6GameServiceAddresses::PrintDecodedRecord,
  R6GameServiceAddresses::DecodePayloadRecord,
  R6GameServiceAddresses::DispatchEncryptedMessageSlot0C,
  R6GameServiceAddresses::DispatchEncryptedMessageSlot10,
};
