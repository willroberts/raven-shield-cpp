#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007b208 : predecessor/action pairs.
const R6GameServiceNative::UnwindEntry UR6LanServers_UR6LanServersUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UnwindLanServersBase},
};
// R6GameService.dll data @ 1007b210 : one armed server-list base action.
// R6GameService.dll data @ 1007b208 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6LanServers_UR6LanServersExceptionInfo = {
  0x19930520,
  1,
  R6GameServiceAddresses::UR6LanServers_UR6LanServersUnwindMap,
  0,
  0,
  0,
  0,
};

// Returns the relocated UR6LanServers class object.
// R6GameService.dll @ 100013c0 : complete native control/access order and raw ABI retained.
UClass * __cdecl UR6LanServers::StaticClass(void)
{
  return reinterpret_cast<UClass *>(0x10092eb0);
}

// Forwards class, outer/name/flags, current GError and zero optional arguments to StaticAllocateObject.
// R6GameService.dll @ 100013d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl UR6LanServers::operator new(uint allocationSize,UObject *outer,FName name,ulong flags)
{
  __asm {
    // Requested allocation-size word is unused; retain caller-clean parameter slots and raw allocation result.
    mov    eax,ds:R6GameServiceAddresses::Core__GErrorSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    push   0x0
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [esp+0x14]
    push   0x0
    push   edx
    push   eax
    push   ecx
    push   0x10092eb0
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_StaticAllocateObjectSlot
    add    esp,0x20
    ret
  }
}

// Assigns the server-list base, two scalar tail words and only mask1 of the last LAN flag word.
// R6GameService.dll @ 10003870 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6LanServers * __thiscall UR6LanServers::operator=(UR6LanServers *object,const UR6LanServers *source)
{
  __asm {
    // No derived self guard or local EH; higher destination flag bits survive.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   edi
    mov    esi,ecx
    call   R6GameServiceAddresses::UR6ServerList_operator
    mov    eax,DWORD PTR [edi+0x174]
    mov    DWORD PTR [esi+0x174],eax
    mov    ecx,DWORD PTR [edi+0x178]
    mov    DWORD PTR [esi+0x178],ecx
    mov    edx,DWORD PTR [edi+0x17c]
    mov    edi,DWORD PTR [esi+0x17c]
    xor    edx,edi
    mov    eax,edi
    and    edx,0x1
    xor    eax,edx
    mov    DWORD PTR [esi+0x17c],eax
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Installs the LAN vtable, calls ConditionalDestroy under base cleanup, then destroys the server-list base.
// R6GameService.dll @ 10003db0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6LanServers::~UR6LanServers(UR6LanServers *object)
{
  __asm {
    // The actual base destructor performs its own ConditionalDestroy; preserve both calls and ignored statuses.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectLanServersDestructorInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6LanServersDispatchTable
    mov    DWORD PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   R6GameServiceAddresses::UR6ServerList__UR6ServerList
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Constructs the server-list base and publishes the LAN vtable without initializing the three derived tail words.
// R6GameService.dll @ 10003e00 : receiver in ECX; derived tail storage is untouched.
UR6LanServers::UR6LanServers(void)
{
  UR6LanServers *object = this;
  using ConstructABI = void (__thiscall *)(void *);
  ((ConstructABI)R6GameServiceAddresses::UR6ServerList_UR6ServerList)(object);
  *(uint *)object = R6GameServiceAddresses::UR6LanServersDispatchTable;
}

// Copy-constructs the base, publishes the LAN table and transfers two words plus mask1 of the last flag word.
// R6GameService.dll @ 10003e20 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6LanServers * __thiscall UR6LanServers::UR6LanServers(UR6LanServers *object,const UR6LanServers *source)
{
  __asm {
    // No local cleanup is armed for faults in derived scalar accesses after base construction.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   edi
    mov    esi,ecx
    call   R6GameServiceAddresses::UR6ServerList_UR6ServerList2
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6LanServersDispatchTable
    mov    eax,DWORD PTR [edi+0x174]
    mov    DWORD PTR [esi+0x174],eax
    mov    ecx,DWORD PTR [edi+0x178]
    mov    DWORD PTR [esi+0x178],ecx
    mov    edx,DWORD PTR [edi+0x17c]
    mov    edi,DWORD PTR [esi+0x17c]
    xor    edx,edi
    mov    eax,edi
    and    edx,0x1
    xor    eax,edx
    mov    DWORD PTR [esi+0x17c],eax
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroys one LAN object or a cookie-counted array and optionally frees it, returning object or cookie pointer.
// R6GameService.dll @ 10003e70 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteUR6LanServers(UR6LanServers *object,uint flags)
{
  __asm {
    // Cached low flag byte controls vector mask2/free mask1; stride180; current GMalloc only on vector free.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je    Branch2
    mov    eax,DWORD PTR [esi-0x4]
    push   edi
    push   R6GameServiceAddresses::UR6LanServers__UR6LanServers
    lea    edi,[esi-0x4]
    push   eax
    push   0x180
    push   esi
    call   R6GameServiceAddresses::_eh_vector_destructor_iterator_
    test   bl,0x1
    je    Branch1
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   edi
    call   DWORD PTR [edx+0x8]
  Branch1:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch2:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6LanServers__UR6LanServers
    test   bl,0x1
    je    Branch3
    push   0x180
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__3UObjectSlot
    add    esp,0x8
  Branch3:
    mov    eax,esi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Constructs a LAN server list in nonnull supplied storage; null storage has no effect.
// R6GameService.dll @ 100042f0 : caller-clean placement-construction wrapper; no allocation or result value.
void __cdecl UR6LanServers::InternalConstructor(void *objectMemory)
{
  if (objectMemory != nullptr) {
    using ConstructABI = void (__thiscall *)(void *);
    ((ConstructABI)R6GameServiceAddresses::UR6LanServers_UR6LanServers)(objectMemory);
  }
}

// Reloads the saved LAN receiver and tail-forwards the actual server-list destructor.
// R6GameService.dll @ 10063410 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindLanServersBase(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::UR6ServerList__UR6ServerList
  }
}

// Selects the one-state LAN destructor map and forwards the current exception frame.
// R6GameService.dll @ 10063418 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectLanServersDestructorInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6LanServers_UR6LanServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll @ 1006ac50 : destroy UR6LanServers class metadata
void DestroyUR6LanServersClassMetadata(void)
{
  UClass::~UClass(&UR6LanServers::PrivateStaticClass);
  return;
}

// Publishes this class's metadata address in its exported autoclass pointer slot.
// R6GameService.dll @ 1006a280 : cdecl startup entry; pointer slot 0x10091e7c.
void __cdecl InitializeAutoclassUR6LanServers(void)
{
  *(UClass **)0x10091e7c = &UR6LanServers::PrivateStaticClass;
}

// Constructs class metadata with its selected native size and registers class-metadata cleanup.
// R6GameService.dll @ 1006a200 : cdecl startup entry; no local EH guard.
void __cdecl InitializeUR6LanServersClassMetadata(void)
{
  UClass *withinClass = *(UClass **)R6GameServiceAddresses::Core_UObject_PrivateStaticClassSlot;
  code *staticConstructor = *(code **)R6GameServiceAddresses::Core_UObject_StaticConstructorSlot;
  code *nativeConstructor = UR6LanServers::InternalConstructor;
  ushort *configName = UObject::StaticConfigName();
  UClass::UClass(&UR6LanServers::PrivateStaticClass,0,0x180,4,&UR6ServerList::PrivateStaticClass,withinClass,
                 0,0,0,0,L"R6LanServers",GPackage,configName,0x4084004,nativeConstructor,staticConstructor);
  _atexit(DestroyUR6LanServersClassMetadata);
}

// Native virtual-table prefix: UR6LanServersDispatchTable
// R6GameService.dll data @ 1006b918 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct UR6LanServersDispatchTableRecord {
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember22; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember21; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember20; // +0x08
  R6GameServiceNative::Address DeleteUR6LanServers; // +0x0c
  R6GameServiceNative::Address UObject_ProcessEvent; // +0x10
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember19; // +0x14
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember18; // +0x18
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember17; // +0x1c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember16; // +0x20
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember15; // +0x24
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember14; // +0x28
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember13; // +0x2c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember12; // +0x30
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember11; // +0x34
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember10; // +0x38
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember9; // +0x3c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember8; // +0x40
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember7; // +0x44
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember6; // +0x48
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember5; // +0x4c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember4; // +0x50
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember3; // +0x54
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember2; // +0x58
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember; // +0x5c
  R6GameServiceNative::Address core_import_supportTailImportedMember; // +0x60
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember55; // +0x64
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember54; // +0x68
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember53; // +0x6c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember52; // +0x70
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember51; // +0x74
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember50; // +0x78
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember49; // +0x7c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember48; // +0x80
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember47; // +0x84
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember46; // +0x88
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember45; // +0x8c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember44; // +0x90
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember43; // +0x94
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember42; // +0x98
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember41; // +0x9c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember40; // +0xa0
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember39; // +0xa4
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember38; // +0xa8
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember37; // +0xac
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember36; // +0xb0
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember35; // +0xb4
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember34; // +0xb8
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember33; // +0xbc
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember32; // +0xc0
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember31; // +0xc4
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember30; // +0xc8
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember29; // +0xcc
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember28; // +0xd0
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember27; // +0xd4
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember26; // +0xd8
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember25; // +0xdc
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember24; // +0xe0
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember23; // +0xe4
  R6GameServiceNative::Address UR6ServerList_SetOwnSvrPort; // +0xe8
  R6GameServiceNative::Address UR6ServerList_GetLobbyID; // +0xec
  R6GameServiceNative::Address UR6ServerList_GetGroupID; // +0xf0
};
const UR6LanServersDispatchTableRecord UR6LanServersDispatchTable = {
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember22,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember21,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember20,
  R6GameServiceAddresses::DeleteUR6LanServers,
  R6GameServiceAddresses::UObject_ProcessEvent,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember19,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember18,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember17,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember16,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember15,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember14,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember13,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember12,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember11,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember10,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember9,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember8,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember7,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember6,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember5,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember4,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember3,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember2,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember,
  R6GameServiceAddresses::core_import_supportTailImportedMember,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember55,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember54,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember53,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember52,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember51,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember50,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember49,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember48,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember47,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember46,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember45,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember44,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember43,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember42,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember41,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember40,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember39,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember38,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember37,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember36,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember35,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember34,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember33,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember32,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember31,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember30,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember29,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember28,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember27,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember26,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember25,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember24,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember23,
  R6GameServiceAddresses::UR6ServerList_SetOwnSvrPort,
  R6GameServiceAddresses::UR6ServerList_GetLobbyID,
  R6GameServiceAddresses::UR6ServerList_GetGroupID,
};
