#include "native_addresses.h"
#include "native_records.h"

// Selected package record identity: R6GameService.R6ServerList.stGameServer.
// Generated C++ type/member spellings are unresolved; native helper names are descriptive, with no invented declaration.
// Selected layout: sizedc, strings10/1c/2c, flag word28 maskf, nested game data38 (sizea4).
// R6GameService.dll data @ 1007b020 : predecessor/action pairs for the three completed server strings.
const R6GameServiceNative::UnwindEntry stGameServerSharedLifetimeUnwindMap[3] = {
  {-1, R6GameServiceAddresses::UnwindGameServerIPAddress},
  {0, R6GameServiceAddresses::UnwindGameServerAltIPAddress},
  {1, R6GameServiceAddresses::UnwindGameServerOptions},
};
// R6GameService.dll data @ 1007b038 : shared by default/copy construction and destruction.
const R6GameServiceNative::FuncInfo stGameServerSharedLifetimeExceptionInfo = {
  0x19930520,
  3,
  R6GameServiceAddresses::stGameServerSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Assigns server scalars, three strings, four reflected flag bits and nested game data without adding a self guard.
// R6GameService.dll @ 10002f80 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall AssignSTGameServer(void *destination,const void *source)
{
  __asm {
    // Preserves high server flag bits and interleaved source loads; nested game-data assignment has no whole-object rollback.
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [esi],eax
    mov    ecx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],ecx
    mov    edx,DWORD PTR [edi+0x8]
    lea    ecx,[edi+0x10]
    mov    DWORD PTR [esi+0x8],edx
    mov    eax,DWORD PTR [edi+0xc]
    push   ecx
    lea    ecx,[esi+0x10]
    mov    DWORD PTR [esi+0xc],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    edx,[edi+0x1c]
    push   edx
    lea    ecx,[esi+0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    mov    ecx,DWORD PTR [edi+0x28]
    mov    eax,DWORD PTR [esi+0x28]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esi+0x28]
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi+0x28],ecx
    mov    eax,DWORD PTR [edi+0x28]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x28],eax
    mov    ecx,DWORD PTR [edi+0x28]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x28],ecx
    mov    edx,DWORD PTR [edi+0x28]
    xor    edx,ecx
    and    edx,0x8
    xor    edx,ecx
    lea    eax,[edi+0x2c]
    push   eax
    lea    ecx,[esi+0x2c]
    mov    DWORD PTR [esi+0x28],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    add    edi,0x38
    push   edi
    lea    ecx,[esi+0x38]
    call   R6GameServiceAddresses::AssignSTGameData
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroys nested game data followed by options and address strings under three staged parent cleanup states.
// R6GameService.dll @ 10003380 : RET0; exact member order and partial-construction cleanup states.
__declspec(naked) void __thiscall DestroySTGameServer(void *server)
{
  byte *nativeStack,*receiver;
  __asm {
    // The nested record owns its cleanup frame; parent state2 covers its call, then byte state1/0 precede the next strings.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGameServerExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    nativeStack,esp
    mov    receiver,esi
  }
  using MemberABI = uint (__thiscall *)(void *);
  *(uint *)(nativeStack + 0x10) = 2;
  ((MemberABI)R6GameServiceAddresses::DestroySTGameData)(receiver + 0x38);
  *(byte *)(nativeStack + 0x10) = 1;
  (*(MemberABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x2c);
  *(byte *)(nativeStack + 0x10) = 0;
  (*(MemberABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1c);
  *(uint *)(nativeStack + 0x10) = 0xffffffff;
  uint rawEax = (*(MemberABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x10);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Constructs three no-init server strings and nested game data, leaving other storage untouched.
// R6GameService.dll @ 100033f0 : RET0; exact member order and partial-construction cleanup states.
__declspec(naked) void * __thiscall ConstructServerInfo(void *server)
{
  byte *nativeStack,*receiver;
  __asm {
    // Parent state2 covers game-data construction, whose own map additionally accounts for its strings and untouched arrays.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGameServerExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    lea    ecx,[esi+0x10]
    mov    DWORD PTR [esp+0x4],esi
    mov    nativeStack,esp
    mov    receiver,esi
  }
  using MemberABI = uint (__thiscall *)(void *);
  (*(MemberABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x10);
  *(uint *)(nativeStack + 0x10) = 0;
  (*(MemberABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1c);
  *(byte *)(nativeStack + 0x10) = 1;
  (*(MemberABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x2c);
  *(byte *)(nativeStack + 0x10) = 2;
  ((MemberABI)R6GameServiceAddresses::ConstructServerGameData)(receiver + 0x38);
  __asm {
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Copy-constructs server scalars, reflected flag bits, strings and nested game data with three staged string actions.
// R6GameService.dll @ 10003460 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyConstructSTGameServer(void *destination,const void *source)
{
  __asm {
    // State1 is written before publishing the final flag word; first two strings/scalar transfers retain earlier states.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGameServerExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [edi]
    mov    DWORD PTR [esi],eax
    mov    ecx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],ecx
    mov    edx,DWORD PTR [edi+0x8]
    lea    ecx,[edi+0x10]
    mov    DWORD PTR [esi+0x8],edx
    mov    eax,DWORD PTR [edi+0xc]
    push   ecx
    lea    ecx,[esi+0x10]
    mov    DWORD PTR [esp+0xc],esi
    mov    DWORD PTR [esi+0xc],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x1c]
    push   edx
    lea    ecx,[esi+0x1c]
    mov    DWORD PTR [esp+0x18],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [edi+0x28]
    mov    eax,DWORD PTR [esi+0x28]
    xor    eax,ecx
    mov    ecx,DWORD PTR [esi+0x28]
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi+0x28],ecx
    mov    eax,DWORD PTR [edi+0x28]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x28],eax
    mov    ecx,DWORD PTR [edi+0x28]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x28],ecx
    mov    edx,DWORD PTR [edi+0x28]
    xor    edx,ecx
    and    edx,0x8
    xor    edx,ecx
    lea    eax,[edi+0x2c]
    push   eax
    lea    ecx,[esi+0x2c]
    mov    BYTE PTR [esp+0x18],0x1
    mov    DWORD PTR [esi+0x28],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    add    edi,0x38
    push   edi
    lea    ecx,[esi+0x38]
    mov    BYTE PTR [esp+0x18],0x2
    call   R6GameServiceAddresses::CopyConstructSTGameData
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Reloads the saved record pointer and forwards cleanup for its IPAddress member at +10.
// R6GameService.dll @ 100632f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameServerIPAddress(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x10
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its AltIPAddress member at +1c.
// R6GameService.dll @ 100632fc : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameServerAltIPAddress(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its Options member at +2c.
// R6GameService.dll @ 10063308 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameServerOptions(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x2c
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the three-state server FuncInfo and forwards the existing C++ exception frame.
// R6GameService.dll @ 10063314 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectGameServerExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::stGameServerSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
