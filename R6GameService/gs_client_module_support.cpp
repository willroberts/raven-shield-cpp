#include "native_addresses.h"
#include "native_records.h"

// External loaded-code addresses; inferred slot names follow GetProcAddress strings in this module.
// Each slot is a live PE32 word, not a host function pointer; target implementations remain external.
// R6GameService.dll data @ 10093bc4 : address returned for _Connect.
extern unsigned int GLoadedGSClientConnectSlot;
// R6GameService.dll data @ 10093bc8 : address returned for _Disconnect.
extern unsigned int GLoadedGSClientDisconnectSlot;
// R6GameService.dll data @ 10093bcc : address returned for _DispatchMessage.
extern unsigned int GLoadedGSClientDispatchMessageSlot;
// R6GameService.dll data @ 10093bd0 : address returned for _GetMessage.
extern unsigned int GLoadedGSClientGetMessageSlot;
// R6GameService.dll data @ 10093bd4 : address returned for _GetMessageQueueNotEmptyEvent.
extern unsigned int GLoadedGSClientGetMessageQueueNotEmptyEventSlot;
// R6GameService.dll data @ 10093bd8 : address returned for _Initialize.
extern unsigned int GLoadedGSClientInitializeSlot;
// R6GameService.dll data @ 10093bdc : address returned for _MsgAlloc.
extern unsigned int GLoadedGSClientMsgAllocSlot;
// R6GameService.dll data @ 10093be0 : address returned for _MsgDelete.
extern unsigned int GLoadedGSClientMsgDeleteSlot;
// R6GameService.dll data @ 10093be4 : address returned for _Uninitialize.
extern unsigned int GLoadedGSClientUninitializeSlot;
// R6GameService.dll data @ 10093be8 : address returned for _PostMessage.
extern unsigned int GLoadedGSClientPostMessageSlot;
// R6GameService.dll data @ 10093bec : address returned for _MsgGetCopy.
extern unsigned int GLoadedGSClientMsgGetCopySlot;


// Registered GS-client loader and dispatch adapters; original free-wrapper identifiers are unavailable.

// Returns 0x80005001 when the GS module is absent, otherwise tail-forwards both raw words to loaded _GetMessage.
// R6GameService.dll @ 10018900 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall GetLoadedGSClientMessage(void **messageOut,uint word)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch1
    mov    eax,0x80005001
    ret    0x8
  Branch1:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientGetMessageSlot
  }
}

// Returns 0x80005001 when the GS module is absent, otherwise tail-forwards the raw message pointer to _DispatchMessage.
// R6GameService.dll @ 10018920 : complete native control/access order and raw ABI retained.
__declspec(naked) int __stdcall DispatchLoadedGSClientMessage(void *message)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch2
    mov    eax,0x80005001
    ret    0x4
  Branch2:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientDispatchMessageSlot
  }
}

// Loads registered GS client, resolves eleven exports and requires first eight before forwarding the late caller word.
// Retains registry handle/optional failure slots/installed module after initializer failure; no local cleanup frame.
// R6GameService.dll @ 10018650 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall LoadAndInitializeGSClient(uint initializationWord)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    xor    edi,edi
    cmp    eax,edi
    je     Branch3
    pop    edi
    pop    esi
    mov    eax,0x80005000
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch3:
    lea    eax,[esp+0x10]
    mov    DWORD PTR [esp+0x10],edi
    push   eax
    push   0xf003f
    push   edi
    push   R6GameServiceAddresses::TextSOFTWAREUbiSoftGameService
    push   0x80000002
    call   DWORD PTR ds:R6GameServiceAddresses::ADVAPI32_RegOpenKeyExASlot
    test   eax,eax
    je     Branch4
    pop    edi
    pop    esi
    mov    eax,0x82115002
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch4:
    mov    eax,DWORD PTR [esp+0x10]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::ADVAPI32_RegQueryValueExASlot
    lea    ecx,[esp+0xc]
    lea    edx,[esp+0x14]
    push   ecx
    push   edi
    push   edx
    push   edi
    push   R6GameServiceAddresses::TextGSClientSP
    push   eax
    mov    DWORD PTR [esp+0x2c],0x1
    mov    DWORD PTR [esp+0x24],edi
    call   ebx
    test   eax,eax
    je     Branch5
    pop    edi
    pop    esi
    mov    eax,0x82115002
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch5:
    mov    ecx,DWORD PTR [esp+0xc]
    push   ecx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    mov    esi,eax
    add    esp,0x4
    cmp    esi,edi
    jne    Branch6
    pop    edi
    pop    esi
    mov    eax,0x8217000e
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch6:
    mov    ecx,DWORD PTR [esp+0x10]
    lea    edx,[esp+0xc]
    push   edx
    lea    eax,[esp+0x18]
    push   esi
    push   eax
    push   edi
    push   R6GameServiceAddresses::TextGSClientSP
    push   ecx
    call   ebx
    test   eax,eax
    push   esi
    je     Branch7
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    mov    eax,0x80004005
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch7:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_LoadLibraryASlot
    cmp    eax,edi
    mov    ds:R6GameServiceAddresses::GGSClientModule,eax
    push   esi
    jne    Branch8
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    mov    eax,0x82115002
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch8:
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetProcAddressSlot
    add    esp,0x4
    push   R6GameServiceAddresses::TextInitialize
    push   edx
    call   esi
    mov    ds:R6GameServiceAddresses::GLoadedGSClientInitializeSlot,eax
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextUninitialize
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextConnect
    push   ecx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientUninitializeSlot,eax
    call   esi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextDisconnect
    push   edx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientConnectSlot,eax
    call   esi
    mov    ds:R6GameServiceAddresses::GLoadedGSClientDisconnectSlot,eax
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextGetMessage
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextDispatchMessage
    push   ecx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientGetMessageSlot,eax
    call   esi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextPostMessage
    push   edx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientDispatchMessageSlot,eax
    call   esi
    mov    ds:R6GameServiceAddresses::GLoadedGSClientPostMessageSlot,eax
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextGetMessageQueueNotEmptyEvent
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextMsgAlloc
    push   ecx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientGetMessageQueueNotEmptyEventSlot,eax
    call   esi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextMsgDelete
    push   edx
    mov    ds:R6GameServiceAddresses::GLoadedGSClientMsgAllocSlot,eax
    call   esi
    mov    ds:R6GameServiceAddresses::GLoadedGSClientMsgDeleteSlot,eax
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    push   R6GameServiceAddresses::TextMsgGetCopy
    push   eax
    call   esi
    mov    ds:R6GameServiceAddresses::GLoadedGSClientMsgGetCopySlot,eax
    mov    eax,ds:R6GameServiceAddresses::GLoadedGSClientInitializeSlot
    cmp    eax,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientUninitializeSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientConnectSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientDisconnectSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientGetMessageSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientDispatchMessageSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientPostMessageSlot,edi
    je     Branch9
    cmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientGetMessageQueueNotEmptyEventSlot,edi
    je     Branch9
    mov    ecx,DWORD PTR [esp+0x1c]
    push   ecx
    call   eax
    pop    edi
    pop    esi
    pop    ebx
    add    esp,0xc
    ret    0x4
  Branch9:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GGSClientModule
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_FreeLibrarySlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GGSClientModule,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientInitializeSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientUninitializeSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientConnectSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientDisconnectSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientGetMessageSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientDispatchMessageSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientPostMessageSlot,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientGetMessageQueueNotEmptyEventSlot,edi
    pop    edi
    pop    esi
    mov    eax,0x82115003
    pop    ebx
    add    esp,0xc
    ret    0x4
  }
}

// Returns unloaded status or tail-forwards original words through live _Connect slot; no target-pointer validation.
// R6GameService.dll @ 100188e0 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall ConnectLoadedGSClient(const void *descriptor,uint argumentWord)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch10
    mov    eax,0x80005001
    ret    0x8
  Branch10:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientConnectSlot
  }
}

// Returns unloaded status or tail-forwards original message word through live _PostMessage slot.
// R6GameService.dll @ 10018940 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall PostLoadedGSClientMessage(void *message)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch11
    mov    eax,0x80005001
    ret    0x4
  Branch11:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientPostMessageSlot
  }
}

// Returns unloaded status or tail-forwards original two words through optional live _MsgAlloc slot, even if NULL.
// R6GameService.dll @ 10018960 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall AllocateLoadedGSClientMessage(uint typeWord,void **messageOut)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch12
    mov    eax,0x80005001
    ret    0x8
  Branch12:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientMsgAllocSlot
  }
}

// Returns unloaded status or tail-forwards original message word through optional live _MsgDelete slot, even if NULL.
// R6GameService.dll @ 10018980 : native control/access order and raw ABI retained.
__declspec(naked) int __stdcall DeleteLoadedGSClientMessage(void *message)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientModule
    test   eax,eax
    jne    Branch13
    mov    eax,0x80005001
    ret    0x4
  Branch13:
    jmp    DWORD PTR ds:R6GameServiceAddresses::GLoadedGSClientMsgDeleteSlot
  }
}
