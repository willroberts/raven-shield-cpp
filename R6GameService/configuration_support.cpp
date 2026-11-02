#include "native_addresses.h"
#include "native_records.h"

// Product/category and active configuration-service support; original free/helper declarations remain unresolved.
// uint return views expose raw EAX rather than recovering original semantic return types.

// Compares cached product text, reports category with a temporary FString, then assigns the selected display name to current mod manager.
// R6GameService.dll @ 10010830 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SetSelectedProductCategory(ushort *productName)
{
  __asm {
    mov    eax,fs:0x0
    push   0xffffffff
    push   R6GameServiceAddresses::SelectProductCategoryLifetime
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   esi
    mov    esi,DWORD PTR [esp+0x2c]
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appStricmpSlot
    push   R6GameServiceAddresses::WideTextR6RSATHENASWORD
    push   esi
    call   edi
    add    esp,0x8
    test   eax,eax
    jne    Branch1
    push   R6GameServiceAddresses::WideTextIsAnOfficialMod
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[esp+0x8]
    push   eax
    mov    DWORD PTR [esp+0x2c],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x28],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   R6GameServiceAddresses::WideTextAthenaSword
    jmp    Branch4
  Branch1:
    push   R6GameServiceAddresses::WideTextR6RSCRIMSONHAMMER
    push   esi
    call   edi
    add    esp,0x8
    test   eax,eax
    jne    Branch2
    push   R6GameServiceAddresses::WideTextIsAnOfficialMod
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[esp+0x8]
    push   eax
    mov    DWORD PTR [esp+0x2c],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x28],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   R6GameServiceAddresses::WideTextIronWrath
    jmp    Branch4
  Branch2:
    push   R6GameServiceAddresses::WideTextRAVENSHIELD
    push   esi
    call   edi
    add    esp,0x8
    test   eax,eax
    jne    Branch3
    push   R6GameServiceAddresses::WideTextIsRavenShield
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[esp+0x8]
    push   eax
    mov    DWORD PTR [esp+0x2c],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[esp+0x8]
    mov    DWORD PTR [esp+0x28],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   R6GameServiceAddresses::WideTextRavenshield
    jmp    Branch4
  Branch3:
    push   R6GameServiceAddresses::WideTextIsACustomMod
    lea    ecx,[esp+0x18]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[esp+0x14]
    push   eax
    mov    DWORD PTR [esp+0x2c],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[esp+0x14]
    mov    DWORD PTR [esp+0x28],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   R6GameServiceAddresses::WideTextCustomMod
  Branch4:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [edx]
    add    ecx,0x54
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    ecx,DWORD PTR [esp+0x20]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret
  }
}

// Acquires active config service/interface, invokes slots4/3c, captures callback word and releases current interface then service pointers.
// R6GameService.dll @ 10011a10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) code * __cdecl GetGameConfigCallback(void)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGameConfigLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    xor    ebx,ebx
    push   esi
    mov    DWORD PTR [esp+0x10],ebx
    mov    DWORD PTR [esp+0x8],ebx
    mov    DWORD PTR [esp+0x1c],ebx
    mov    DWORD PTR [esp+0xc],ebx
    lea    eax,[esp+0x8]
    push   eax
    push   ebx
    push   0x10073c54
    mov    BYTE PTR [esp+0x28],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_GetActiveObjectSlot
    cmp    eax,ebx
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    jge    Branch5
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch5
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextCannotFindTheGameConfigService
    push   edx
    call   esi
    add    esp,0x8
  Branch5:
    mov    ecx,DWORD PTR [esp+0x8]
    cmp    ecx,ebx
    je     Branch7
    mov    eax,DWORD PTR [ecx]
    lea    edx,[esp+0xc]
    push   edx
    push   0x10073bf0
    push   ecx
    call   DWORD PTR [eax]
    cmp    eax,ebx
    jge    Branch6
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch6
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCannotFindTheInterfaceForGameConfigService
    push   ecx
    call   esi
    add    esp,0x8
  Branch6:
    mov    ecx,DWORD PTR [esp+0x8]
  Branch7:
    mov    eax,DWORD PTR [esp+0xc]
    cmp    eax,ebx
    je     Branch8
    mov    edx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [edx+0x4]
    mov    eax,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [eax]
    lea    edx,[esp+0x10]
    push   edx
    push   eax
    call   DWORD PTR [ecx+0x3c]
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [esp+0xc]
  Branch8:
    cmp    eax,ebx
    mov    esi,DWORD PTR [esp+0x10]
    mov    BYTE PTR [esp+0x1c],bl
    je     Branch9
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x8]
    mov    ecx,DWORD PTR [esp+0x8]
  Branch9:
    cmp    ecx,ebx
    mov    DWORD PTR [esp+0x1c],0xffffffff
    je     Branch10
    mov    edx,DWORD PTR [ecx]
    push   ecx
    call   DWORD PTR [edx+0x8]
  Branch10:
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x18
    ret
  }
}

// Tail-destroys completed Athena category message at inherited EBP-24 through current string import.
// R6GameService.dll @ 10064260 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SetSelectedProductCategoryUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-destroys completed Crimson category message at inherited EBP-24 through current string import.
// R6GameService.dll @ 10064269 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SetSelectedProductCategoryUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-destroys completed Raven category message at inherited EBP-24 through current string import.
// R6GameService.dll @ 10064272 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SetSelectedProductCategoryUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-destroys completed custom category message at inherited EBP-18 through current string import.
// R6GameService.dll @ 1006427b : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SetSelectedProductCategoryUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Tail-releases current saved service pointer through actual held-object slot8 helper at inherited EBP-18.
// R6GameService.dll @ 10064310 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl GetGameConfigCallbackUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::CallThirdSlotForFirstWordObject
  }
}

// Tail-releases current saved interface pointer through actual held-object slot8 helper at inherited EBP-14.
// R6GameService.dll @ 10064318 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl GetGameConfigCallbackUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x14]
    jmp    R6GameServiceAddresses::CallThirdSlotForFirstWordObject
  }
}

// Selects four independent message lifetimes and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064284 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectProductCategoryLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SetSelectedProductCategoryExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects nested service/interface release map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064320 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectGameConfigLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::GetGameConfigCallbackExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007db74 : native product/configuration unwind record.
const R6GameServiceNative::UnwindEntry SetSelectedProductCategoryUnwindMap[4] = {
  {-1, R6GameServiceAddresses::SetSelectedProductCategoryUnwind1},
  {-1, R6GameServiceAddresses::SetSelectedProductCategoryUnwind2},
  {-1, R6GameServiceAddresses::SetSelectedProductCategoryUnwind3},
  {-1, R6GameServiceAddresses::SetSelectedProductCategoryUnwind4},
};

// R6GameService.dll data @ 1007db94 : native product/configuration unwind record.
// R6GameService.dll data @ 1007db74 : native storage identity retained.
const R6GameServiceNative::FuncInfo SetSelectedProductCategoryExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::SetSelectedProductCategoryUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007de08 : native product/configuration unwind record.
const R6GameServiceNative::UnwindEntry GetGameConfigCallbackUnwindMap[2] = {
  {-1, R6GameServiceAddresses::GetGameConfigCallbackUnwind1},
  {0x0, R6GameServiceAddresses::GetGameConfigCallbackUnwind2},
};

// R6GameService.dll data @ 1007de18 : native product/configuration unwind record.
// R6GameService.dll data @ 1007de08 : native storage identity retained.
const R6GameServiceNative::FuncInfo GetGameConfigCallbackExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::GetGameConfigCallbackUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
