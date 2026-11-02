#include "native_addresses.h"

// CConnection payload identity follows clPointerList<CConnection*> RTTI77ed0 and its typed payload lifecycle.

// Delete the initially loaded provider at+4 when nonnull, then unconditionally clear the CURRENT receiver slot.
// Preserve raw incoming/deleting-call EAX; failure skips the clear and there is no own guard.
// R6GameService.dll @ 1004c430 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CConnectionDestroyProvider(void *connection)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    je     Branch1
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
  Branch1:
    mov    DWORD PTR [esi+0x4],0x0
    pop    esi
    ret
  }
}

// Initialize optional offset table, clear provider, copy global text including NUL, then clear port/key/context words.
// Keep unbounded forward copy, untouched bytes, full flag DWORD and receiver EAX/RET4; no own guard.
// R6GameService.dll @ 1004c3e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall CConnectionConstruct(void *connection,uint initializeVirtualBase)
{
  __asm {
    push   ecx
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je     Branch2
    mov    DWORD PTR [eax],0x10077ec4
  Branch2:
    push   ebx
    push   esi
    mov    edx,R6GameServiceAddresses::GRegistrationEmptyText
    lea    esi,[eax+0x10]
    mov    DWORD PTR [eax+0x4],ecx
    sub    esi,edx
  Branch3:
    mov    bl,BYTE PTR [edx]
    mov    BYTE PTR [esi+edx*1],bl
    inc    edx
    cmp    bl,cl
    jne    Branch3
    pop    esi
    mov    DWORD PTR [eax+0x94],ecx
    mov    DWORD PTR [eax+0x8],ecx
    mov    DWORD PTR [eax+0xc],ecx
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Delete old provider, allocate104 bytes, construct with eight physical words and publish constructor return.
// Original ENTRY ESP S: saved rawS-10/stateS-4. Only state0 during provider construction owns that raw block.
// Cache text/port after construction, invoke provider slot4, and on AL!=0 copy cached text then store live key/context.
// Preserve full six argument words, raw backend EAX, low16 port storage, no failed-start rollback and RET24.
// R6GameService.dll @ 1004c450 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CConnectionReplaceAndStartProvider(void *connection,const char *text,uint portWord,uint argument3,
    uint argument4,uint key,uint connectionWord)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectionAllocationEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    edi,ecx
    xor    esi,esi
    mov    ecx,DWORD PTR [edi+0x4]
    cmp    ecx,esi
    je     Branch4
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [edi+0x4],esi
  Branch4:
    push   0x68
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,esi
    mov    DWORD PTR [esp+0x1c],esi
    je     Branch5
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    edx,DWORD PTR [esp+0x30]
    push   0x1
    push   esi
    push   esi
    push   0xb4
    push   ecx
    push   0x4
    push   edx
    push   0x22
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeTransportRecord
    jmp    Branch6
  Branch5:
    xor    eax,eax
  Branch6:
    cmp    eax,esi
    mov    DWORD PTR [esp+0x1c],0xffffffff
    mov    DWORD PTR [edi+0x4],eax
    jne    Branch7
    xor    al,al
    jmp    Branch9
  Branch7:
    mov    ebx,DWORD PTR [esp+0x28]
    mov    ebp,DWORD PTR [esp+0x24]
    mov    edx,DWORD PTR [eax]
    push   esi
    push   ebx
    push   ebp
    mov    ecx,eax
    call   DWORD PTR [edx+0x4]
    test   al,al
    je     Branch9
    lea    esi,[edi+0x10]
    mov    ecx,ebp
    sub    esi,ebp
  Branch8:
    mov    dl,BYTE PTR [ecx]
    mov    BYTE PTR [esi+ecx*1],dl
    inc    ecx
    test   dl,dl
    jne    Branch8
    mov    ecx,DWORD PTR [esp+0x34]
    mov    edx,DWORD PTR [esp+0x38]
    and    ebx,0xffff
    mov    DWORD PTR [edi+0x8],ecx
    mov    DWORD PTR [edi+0x94],ebx
    mov    DWORD PTR [edi+0xc],edx
  Branch9:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x18
  }
}

// Delete initially loaded provider when present, clear its slot only after return, then set AL1 on raw EAX.
// Null provider preserves incoming upper EAX; no own guard or replacement-provider deletion.
// R6GameService.dll @ 1004c520 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall CConnectionCloseProvider(void *connection)
{
  __asm {
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi+0x4]
    test   ecx,ecx
    je     Branch10
    mov    eax,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [eax]
    mov    DWORD PTR [esi+0x4],0x0
  Branch10:
    mov    al,0x1
    pop    esi
    ret
  }
}

// Pop one provider message, allocate28-byte output and construct its copied payload before deleting popped message.
// ENTRY ESP S: saved rawS-10/stateS-4. Read current connection key/message fields after allocation; preserve
// mixed first argument (key upper24/message byte), constructor result and state-1 before message deletion.
// NULL allocation still deletes the message; thrown allocation/construction does not add a message cleanup.
// R6GameService.dll @ 1004c540 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__fastcall CConnectionPopCopiedMessage(void *connection)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectConnectionAllocationEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [edi+0x4]
    test   ecx,ecx
    je     Branch13
    call   R6GameServiceAddresses::PopAndDispatchControlRecord
    mov    esi,eax
    test   esi,esi
    je     Branch13
    push   0x1c
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [esp+0x8],eax
    test   eax,eax
    mov    DWORD PTR [esp+0x14],0x0
    je     Branch11
    mov    edx,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR [esi+0x14]
    push   0x1
    push   edx
    mov    dl,BYTE PTR [esi+0xd]
    push   ecx
    push   edx
    mov    ecx,eax
    call   R6GameServiceAddresses::ConstructQueuedPayloadRecord
    mov    edi,eax
    jmp    Branch12
  Branch11:
    xor    edi,edi
  Branch12:
    mov    eax,DWORD PTR [esi]
    push   0x1
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR [eax]
    mov    eax,edi
    pop    edi
    pop    esi
    mov    ecx,DWORD PTR [esp+0x4]
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  Branch13:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    xor    eax,eax
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}
