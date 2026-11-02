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

// Run shared message destruction, then test CURRENT original flag lowBYTE bit0 and optionally free receiver. Return
// receiver/RET4.
// R6GameService.dll @ 1005c060 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteClGSEncryptMessage(void *message,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyClGSEncryptMessage
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

// Tail shared clGSMessage destruction with original receiver/stack, retaining full raw EAX; no derived vtable
// write/guard.
// R6GameService.dll @ 1005c080 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyClGSEncryptMessage(void *message)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyClGSMessage
  }
}

// Optionally install derived virtual-base table, initialize base fields with flag0, then publish derived table/kind2;
// ECX0/RET8.
// R6GameService.dll @ 1005c090 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeClGSEncryptMessageFields(
        void *message,uint contextWord,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    eax,DWORD PTR [esp+0xc]
    push    esi
    test    eax,eax
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],0x0
    je    Branch3
    mov    DWORD PTR [esi+0x4],0x10078228
  Branch3:
    mov    eax,DWORD PTR [esp+0xc]
    push    0x0
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::InitializeClGSMessageFields
    mov    DWORD PTR [esi],R6GameServiceAddresses::clGSEncryptMessageVTable
    mov    BYTE PTR [esi+0xc],0x2
    mov    eax,esi
    pop    esi
    pop    ecx
    ret    0x8
  }
}

// Load CURRENT helper8 and forward four full words/literal selector2 through shared slot0c dispatch; raw EAX/RET16.
// R6GameService.dll @ 1005c0d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchEncryptedMessageSlot0C(
        void *message,uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    0x2
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    eax
    push    edx
    call    R6GameServiceAddresses::DispatchThroughSelectedSlot0C
    ret    0x10
  }
}

// Load CURRENT helper8 and forward four full words/literal selector2 through shared slot10 dispatch; raw EAX/RET16.
// R6GameService.dll @ 1005c100 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchEncryptedMessageSlot10(
        void *message,uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    0x2
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    eax
    push    edx
    call    R6GameServiceAddresses::DispatchThroughSelectedSlot10
    ret    0x10
  }
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
