#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007b22c : predecessor/action pairs.
const R6GameServiceNative::UnwindEntry UR6GSServers_UR6GSServersUnwindMap[11] = {
  {-1, R6GameServiceAddresses::UnwindGSServersDestructorBase},
  {0x0, R6GameServiceAddresses::UnwindGSServersDestructorString1},
  {0x1, R6GameServiceAddresses::UnwindGSServersDestructorString2},
  {0x2, R6GameServiceAddresses::UnwindGSServersDestructorString3},
  {0x3, R6GameServiceAddresses::UnwindGSServersDestructorString4},
  {0x4, R6GameServiceAddresses::UnwindGSServersDestructorString5},
  {0x5, R6GameServiceAddresses::UnwindGSServersDestructorString6},
  {0x6, R6GameServiceAddresses::UnwindGSServersDestructorString7},
  {0x7, R6GameServiceAddresses::UnwindGSServersDestructorString8},
  {0x8, R6GameServiceAddresses::UnwindGSServersDestructorString9},
  {0x9, R6GameServiceAddresses::UnwindGSServersDestructorString10},
};
// R6GameService.dll data @ 1007b284 : base plus ten owned strings.
const R6GameServiceNative::FuncInfo UR6GSServers_UR6GSServersExceptionInfo = {
  0x19930520,
  11,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersUnwindMap,
  0,
  0,
  0,
  0,
};
// R6GameService.dll data @ 1007b2a0 : predecessor/action pairs.
const R6GameServiceNative::UnwindEntry UR6GSServers_UR6GSServers_UR6GSServersUnwindMap[10] = {
  {-1, R6GameServiceAddresses::UnwindGSServersCopyConstructorBase},
  {0x0, R6GameServiceAddresses::UnwindGSServersCopyConstructorString1},
  {0x1, R6GameServiceAddresses::UnwindGSServersCopyConstructorString2},
  {0x2, R6GameServiceAddresses::UnwindGSServersCopyConstructorString3},
  {0x3, R6GameServiceAddresses::UnwindGSServersCopyConstructorString4},
  {0x4, R6GameServiceAddresses::UnwindGSServersCopyConstructorString5},
  {0x5, R6GameServiceAddresses::UnwindGSServersCopyConstructorString6},
  {0x6, R6GameServiceAddresses::UnwindGSServersCopyConstructorString7},
  {0x7, R6GameServiceAddresses::UnwindGSServersCopyConstructorString8},
  {0x8, R6GameServiceAddresses::UnwindGSServersCopyConstructorString9},
};
// R6GameService.dll data @ 1007b2f0 : base plus nine completed strings before constructing the tenth.
const R6GameServiceNative::FuncInfo UR6GSServers_UR6GSServers_UR6GSServersExceptionInfo = {
  0x19930520,
  10,
  R6GameServiceAddresses::UR6GSServers_UR6GSServers_UR6GSServersUnwindMap,
  0,
  0,
  0,
  0,
};

// Returns the relocated UR6GSServers class object.
// R6GameService.dll @ 10001520 : complete native control/access order and raw ABI retained.
UClass * __cdecl UR6GSServers::StaticClass(void)
{
  return reinterpret_cast<UClass *>(0x10092948);
}

// Forwards class, outer/name/flags, current GError and zero optional arguments to StaticAllocateObject.
// R6GameService.dll @ 10001530 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl UR6GSServers::operator new(uint allocationSize,UObject *outer,FName name,ulong flags)
{
  __asm {
    // Requested allocation-size word is unused; retain caller-clean slots and raw allocation result.
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
    push   0x10092948
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_StaticAllocateObjectSlot
    add    esp,0x20
    ret
  }
}

// Returns for null storage or tail-forwards its storage argument to the separately scoped GS default constructor.
// R6GameService.dll @ 10001560 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers::InternalConstructor(void *objectMemory)
{
  __asm {
    // Targetc4f0 retains its own full initialization/EH behavior; no extra frame or null result normalization.
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je    Branch1
    jmp    R6GameServiceAddresses::UR6GSServers_UR6GSServers2
  Branch1:
    ret
  }
}

// Assigns the base, sixteen activation bytes, scalar words, eleven flag bits and ten owned strings in native order.
// R6GameService.dll @ 100038c0 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6GSServers * __thiscall UR6GSServers::operator=(UR6GSServers *object,const UR6GSServers *source)
{
  __asm {
    // Preserve the byte loop and per-bit source flag reloads, interleaved destination flag loads and no local rollback.
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    push   edi
    mov    esi,ecx
    call   R6GameServiceAddresses::UR6ServerList_operator
    mov    ecx,edi
    lea    eax,[esi+0x174]
    sub    ecx,esi
    mov    ebp,0x10
    mov    edi,edi
  Branch2:
    mov    dl,BYTE PTR [ecx+eax*1]
    mov    BYTE PTR [eax],dl
    inc    eax
    dec    ebp
    jne    Branch2
    mov    eax,DWORD PTR [edi+0x184]
    mov    DWORD PTR [esi+0x184],eax
    mov    ecx,DWORD PTR [edi+0x188]
    mov    ebp,DWORD PTR [esi+0x194]
    mov    DWORD PTR [esi+0x188],ecx
    mov    edx,DWORD PTR [edi+0x18c]
    mov    ecx,DWORD PTR [esi+0x194]
    mov    DWORD PTR [esi+0x18c],edx
    mov    eax,DWORD PTR [edi+0x190]
    mov    DWORD PTR [esi+0x190],eax
    xor    ecx,DWORD PTR [edi+0x194]
    and    ecx,0x1
    xor    ebp,ecx
    mov    DWORD PTR [esi+0x194],ebp
    mov    eax,DWORD PTR [edi+0x194]
    mov    ecx,ebp
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x20
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x40
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x80
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x100
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x200
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    edx,DWORD PTR [edi+0x194]
    xor    edx,eax
    and    edx,0x400
    xor    edx,eax
    mov    DWORD PTR [esi+0x194],edx
    mov    eax,DWORD PTR [edi+0x198]
    mov    DWORD PTR [esi+0x198],eax
    mov    ecx,DWORD PTR [edi+0x19c]
    lea    edx,[edi+0x1a0]
    mov    DWORD PTR [esi+0x19c],ecx
    push   edx
    lea    ecx,[esi+0x1a0]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    eax,[edi+0x1ac]
    push   eax
    lea    ecx,[esi+0x1ac]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    ecx,[edi+0x1b8]
    push   ecx
    lea    ecx,[esi+0x1b8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    edx,[edi+0x1c4]
    push   edx
    lea    ecx,[esi+0x1c4]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    eax,[edi+0x1d0]
    push   eax
    lea    ecx,[esi+0x1d0]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    ecx,[edi+0x1dc]
    push   ecx
    lea    ecx,[esi+0x1dc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    edx,[edi+0x1e8]
    push   edx
    lea    ecx,[esi+0x1e8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    eax,[edi+0x1f4]
    push   eax
    lea    ecx,[esi+0x1f4]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    ecx,[edi+0x200]
    push   ecx
    lea    ecx,[esi+0x200]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    add    edi,0x20c
    push   edi
    lea    ecx,[esi+0x20c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebp
    ret    0x4
  }
}

// Calls ConditionalDestroy under eleven-state cleanup, destroys ten strings and then the server-list base.
// R6GameService.dll @ 10003ee0 : RET0; both derived and base ConditionalDestroy calls remain observable.
__declspec(naked) void __thiscall UR6GSServers::~UR6GSServers(void)
{
  byte *nativeStack,*receiver;
  __asm {
    // Derived and base ConditionalDestroy both run; byte state changes and final full state-1 retain exact lifetimes.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGSServersDestructorInfo
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
  *(uint *)receiver = R6GameServiceAddresses::UR6GSServersDispatchTable;
  *(uint *)(nativeStack + 0x10) = 10;
  using DestroyABI = uint (__thiscall *)(void *);
  (*(DestroyABI *)R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot)(receiver);
  *(byte *)(nativeStack + 0x10) = 9;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x20c);
  *(byte *)(nativeStack + 0x10) = 8;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x200);
  *(byte *)(nativeStack + 0x10) = 7;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1f4);
  *(byte *)(nativeStack + 0x10) = 6;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1e8);
  *(byte *)(nativeStack + 0x10) = 5;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1dc);
  *(byte *)(nativeStack + 0x10) = 4;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1d0);
  *(byte *)(nativeStack + 0x10) = 3;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1c4);
  *(byte *)(nativeStack + 0x10) = 2;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1b8);
  *(byte *)(nativeStack + 0x10) = 1;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1ac);
  *(byte *)(nativeStack + 0x10) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(receiver + 0x1a0);
  *(uint *)(nativeStack + 0x10) = 0xffffffff;
  uint rawEax = ((DestroyABI)R6GameServiceAddresses::UR6ServerList__UR6ServerList)(receiver);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Copy-constructs the base, four activation DWORDs, scalar/flag words and ten strings under staged cleanup.
// R6GameService.dll @ 10003fe0 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6GSServers * __thiscall UR6GSServers::UR6GSServers(UR6GSServers *object,const UR6GSServers *source)
{
  __asm {
    // State0 arms before publishing mask200, after its source load; preserve word copies and individual source flag reloads.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGSServersCopyInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    call   R6GameServiceAddresses::UR6ServerList_UR6ServerList2
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6GSServersDispatchTable
    lea    eax,[edi+0x174]
    mov    edx,DWORD PTR [eax]
    lea    ecx,[esi+0x174]
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [ecx+0x8],edx
    mov    eax,DWORD PTR [eax+0xc]
    mov    DWORD PTR [ecx+0xc],eax
    mov    ecx,DWORD PTR [edi+0x184]
    mov    DWORD PTR [esi+0x184],ecx
    mov    edx,DWORD PTR [edi+0x188]
    mov    DWORD PTR [esi+0x188],edx
    mov    eax,DWORD PTR [edi+0x18c]
    mov    edx,DWORD PTR [esi+0x194]
    mov    DWORD PTR [esi+0x18c],eax
    mov    ecx,DWORD PTR [edi+0x190]
    mov    DWORD PTR [esi+0x190],ecx
    xor    edx,DWORD PTR [edi+0x194]
    mov    eax,DWORD PTR [esi+0x194]
    and    edx,0x1
    xor    eax,edx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,eax
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x20
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x40
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x80
    xor    eax,ecx
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x100
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    eax,DWORD PTR [edi+0x194]
    xor    eax,ecx
    and    eax,0x200
    xor    eax,ecx
    mov    DWORD PTR [esp+0x14],0x0
    mov    DWORD PTR [esi+0x194],eax
    mov    ecx,DWORD PTR [edi+0x194]
    xor    ecx,eax
    and    ecx,0x400
    xor    ecx,eax
    mov    DWORD PTR [esi+0x194],ecx
    mov    edx,DWORD PTR [edi+0x198]
    lea    ecx,[edi+0x1a0]
    mov    DWORD PTR [esi+0x198],edx
    mov    eax,DWORD PTR [edi+0x19c]
    push   ecx
    lea    ecx,[esi+0x1a0]
    mov    DWORD PTR [esi+0x19c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x1ac]
    push   edx
    lea    ecx,[esi+0x1ac]
    mov    BYTE PTR [esp+0x18],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    eax,[edi+0x1b8]
    push   eax
    lea    ecx,[esi+0x1b8]
    mov    BYTE PTR [esp+0x18],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    ecx,[edi+0x1c4]
    push   ecx
    lea    ecx,[esi+0x1c4]
    mov    BYTE PTR [esp+0x18],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x1d0]
    push   edx
    lea    ecx,[esi+0x1d0]
    mov    BYTE PTR [esp+0x18],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    eax,[edi+0x1dc]
    push   eax
    lea    ecx,[esi+0x1dc]
    mov    BYTE PTR [esp+0x18],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    ecx,[edi+0x1e8]
    push   ecx
    lea    ecx,[esi+0x1e8]
    mov    BYTE PTR [esp+0x18],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x1f4]
    push   edx
    lea    ecx,[esi+0x1f4]
    mov    BYTE PTR [esp+0x18],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    eax,[edi+0x200]
    push   eax
    lea    ecx,[esi+0x200]
    mov    BYTE PTR [esp+0x18],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    add    edi,0x20c
    push   edi
    lea    ecx,[esi+0x20c]
    mov    BYTE PTR [esp+0x18],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Destroys one GS object or a cookie-counted array and optionally frees it, returning object or cookie pointer.
// R6GameService.dll @ 10004270 : RET4; cached low flag bits select vector/scalar destruction and optional free.
__declspec(naked) void * __thiscall DeleteUR6GSServers(UR6GSServers *object,uint flags)
{
  byte captured;
  byte *receiver;
  __asm {
    // Cached low flag byte controls vector mask2/free mask1; stride218; scalar UObject delete remains caller-clean.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    mov    captured,bl
    mov    receiver,esi
  }
  if ((captured & 2) != 0) {
    uint count = *(uint *)(receiver - 4);
    __asm {
      push   edi
    }
    byte *cookie = receiver - 4;
    using DestroyABI = void (__thiscall *)(void *);
    using IteratorABI = void (__stdcall *)(void *,uint,uint,DestroyABI);
    ((IteratorABI)R6GameServiceAddresses::_eh_vector_destructor_iterator_)
        (receiver,0x218,count,(DestroyABI)R6GameServiceAddresses::UR6GSServers__UR6GSServers);
    if ((captured & 1) != 0) {
      void *allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
      byte *table = *(byte **)allocator;
      (*(uint (__thiscall **)(void *,void *))(table + 8))(allocator,cookie);
    }
    __asm {
      mov    edi,cookie
      mov    eax,edi
      pop    edi
      pop    esi
      pop    ebx
      ret    0x4
    }
  }
  using DestroyABI = void (__thiscall *)(void *);
  ((DestroyABI)R6GameServiceAddresses::UR6GSServers__UR6GSServers)(receiver);
  if ((captured & 1) != 0) {
    using DeleteABI = void (__cdecl *)(void *,uint);
    (*(DeleteABI *)R6GameServiceAddresses::Core__3UObjectSlot)(receiver,0x218);
  }
  __asm {
    mov    eax,esi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for Base.
// R6GameService.dll @ 10063430 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorBase(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::UR6ServerList__UR6ServerList
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String1.
// R6GameService.dll @ 10063438 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString1(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1a0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String2.
// R6GameService.dll @ 10063447 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString2(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1ac
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String3.
// R6GameService.dll @ 10063456 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString3(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1b8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String4.
// R6GameService.dll @ 10063465 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString4(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String5.
// R6GameService.dll @ 10063474 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString5(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1d0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String6.
// R6GameService.dll @ 10063483 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString6(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1dc
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String7.
// R6GameService.dll @ 10063492 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString7(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1e8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String8.
// R6GameService.dll @ 100634a1 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString8(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1f4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String9.
// R6GameService.dll @ 100634b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString9(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x200
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards destructor cleanup for String10.
// R6GameService.dll @ 100634bf : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersDestructorString10(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x20c
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for Base.
// R6GameService.dll @ 100634e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorBase(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::UR6ServerList__UR6ServerList
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String1.
// R6GameService.dll @ 100634e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString1(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1a0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String2.
// R6GameService.dll @ 100634f7 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString2(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1ac
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String3.
// R6GameService.dll @ 10063506 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString3(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1b8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String4.
// R6GameService.dll @ 10063515 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString4(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1c4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String5.
// R6GameService.dll @ 10063524 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString5(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1d0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String6.
// R6GameService.dll @ 10063533 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString6(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1dc
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String7.
// R6GameService.dll @ 10063542 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString7(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1e8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String8.
// R6GameService.dll @ 10063551 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString8(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x1f4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved GS receiver and forwards copyconstructor cleanup for String9.
// R6GameService.dll @ 10063560 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGSServersCopyConstructorString9(void)
{
  __asm {
    // Inherited parent EBP-10 and current destructor import/tail are retained.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x200
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the eleven-state GS destructor map and forwards the current exception frame.
// R6GameService.dll @ 100634ce : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectGSServersDestructorInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_UR6GSServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the ten-state GS copy-constructor map and forwards the current exception frame.
// R6GameService.dll @ 1006356f : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectGSServersCopyInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_UR6GSServers_UR6GSServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Dispatches the level pointer from its argument slot through the cached receiver vtable.
// R6GameService.dll @ 10001400 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::eventHandleNewLobbyConnection(ALevelInfo *level)
{
  __asm {
    mov    edx,DWORD PTR ds:0x10092394
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    push   edi
    mov    esi,ecx
    mov    edi,DWORD PTR [esi]
    push   0x0
    lea    ecx,[esp+0x10]
    push   ecx
    push   0x0
    push   edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Dispatches EndOfRoundDataSent with null parameter and result buffers through the cached vtable.
// R6GameService.dll @ 10001440 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::eventEndOfRoundDataSent(void)
{
  __asm {
    mov    eax,ds:0x10092e54
    push   esi
    push   edi
    push   0x0
    push   0x0
    push   0x0
    mov    esi,ecx
    mov    edi,DWORD PTR [esi]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    pop    edi
    pop    esi
    ret
  }
}

// Dispatches game-info and level pointers in a two-word local buffer through the cached vtable.
// R6GameService.dll @ 10001470 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::eventFillCreateGameInfo(AGameInfo *gameInfo,ALevelInfo *level)
{
  __asm {
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    push   0x0
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    edi,DWORD PTR [esi]
    lea    edx,[esp+0xc]
    push   edx
    mov    DWORD PTR [esp+0x10],eax
    mov    eax,ds:0x10092940
    push   0x0
    mov    DWORD PTR [esp+0x18],ecx
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    pop    edi
    pop    esi
    add    esp,0x8
    ret    0x8
  }
}

// Initializes the one-word event result to zero, dispatches through the cached vtable and returns that word.
// R6GameService.dll @ 100014b0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::eventGetMaxAvailPorts(void)
{
  __asm {
    push   ecx
    push   esi
    push   edi
    push   0x0
    lea    eax,[esp+0xc]
    mov    esi,ecx
    mov    ecx,DWORD PTR ds:0x10092400
    mov    edi,DWORD PTR [esi]
    push   eax
    push   0x0
    push   ecx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    mov    eax,DWORD PTR [esp+0x8]
    pop    edi
    pop    esi
    pop    ecx
    ret
  }
}

// Caches the dispatch table before checked InitializeMod lookup and calls ProcessEvent with null buffers.
// R6GameService.dll @ 100014f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::eventInitializeMod(void)
{
  __asm {
    mov    eax,ds:0x10092e80
    push   esi
    push   edi
    push   0x0
    push   0x0
    push   0x0
    mov    esi,ecx
    mov    edi,DWORD PTR [esi]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    pop    edi
    pop    esi
    ret
  }
}

// R6GameService.dll data @ 1007ac44 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry eventIsGlobalIDBannedUnwindMap[1] = {
  {-1, R6GameServiceAddresses::eventIsGlobalIDBannedUnwind1},
};
// R6GameService.dll data @ 1007ac4c : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo eventIsGlobalIDBannedExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::eventIsGlobalIDBannedUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007ac68 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry eventProcessServerMsgUnwindMap[1] = {
  {-1, R6GameServiceAddresses::eventProcessServerMsgUnwind1},
};
// R6GameService.dll data @ 1007ac70 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo eventProcessServerMsgExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::eventProcessServerMsgUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007ac8c : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap[2] = {
  {-1, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind1},
  {0x0, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind2},
};
// R6GameService.dll data @ 1007ac9c : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007acb8 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry eventGetLocallyBoundIpAddrUnwindMap[2] = {
  {-1, R6GameServiceAddresses::eventGetLocallyBoundIpAddrUnwind1},
  {0x0, R6GameServiceAddresses::eventGetLocallyBoundIpAddrUnwind2},
};
// R6GameService.dll data @ 1007acc8 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo eventGetLocallyBoundIpAddrExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::eventGetLocallyBoundIpAddrUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Dispatches TempGetPBConnectStatus, copies the local string into hidden caller storage and releases the local.
// R6GameService.dll @ 10001d80 : C++ event operations with native frame, hidden-result ABI and unwind slots.
__declspec(naked) FString * __thiscall UR6GSServers::eventTempGetPBConnectStatus
    (FString *hiddenResult,APlayerController *controller)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServersSharedLifetimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebp
    push   esi
    mov    esi,ecx
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DefaultABI = FString * (__thiscall *)(FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  // FName occupies one native word; ProcessEvent uses slot +0x10 of the table captured before lookup.
  using FindABI = UFunction * (__thiscall *)(UR6GSServers *,uint,int);
  using EventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
  *(uint *)(nativeFrame + 8) = 0;
  FString *localString = (FString *)(nativeFrame + 0x10);
  // Default construction runs with state -1; failure does not destroy this local.
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(localString);
  uint eventName = *(uint *)0x100923d0;
  APlayerController *actor = *(APlayerController **)(nativeFrame + 0x30);
  byte *dispatchTable = *(byte **)receiver;
  *(uint *)(nativeFrame + 0x24) = 1;
  *(APlayerController **)(nativeFrame + 0xc) = actor;
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)
      (receiver,eventName,0);
  (*(EventABI *)(dispatchTable + 0x10))(receiver,function,nativeFrame + 0xc,nullptr);
  using CopyABI = FString * (__thiscall *)(FString *,const FString&);
  FString *output = *(FString **)(nativeFrame + 0x2c);
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(output,*localString);
  // Only a completed copy arms output destruction; lowering state changes just the low byte.
  *(uint *)(nativeFrame + 8) = 1;
  *(byte *)(nativeFrame + 0x24) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(localString);
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x8
  }
}

// Dispatches an owned global-ID string and returns the full four-byte event result cached before local cleanup.
// R6GameService.dll @ 10001e20 : C++ event operations with native frame, hidden-result ABI and unwind slots.
__declspec(naked) ulong __thiscall UR6GSServers::eventIsGlobalIDBanned(AR6AbstractGameInfo *gameInfo,const FString& globalID)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::eventIsGlobalIDBannedSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    mov    esi,ecx
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DefaultABI = FString * (__thiscall *)(FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  // FName occupies one native word; ProcessEvent uses slot +0x10 of the table captured before lookup.
  using FindABI = UFunction * (__thiscall *)(UR6GSServers *,uint,int);
  using EventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
  FString *localString = (FString *)(nativeFrame + 0xc);
  // Default construction runs with state -1; failure does not destroy this local.
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(localString);
  using AssignABI = FString& (__thiscall *)(FString *,const FString&);
  const FString *input = *(const FString **)(nativeFrame + 0x30);
  void *actor = *(void **)(nativeFrame + 0x2c);
  *(uint *)(nativeFrame + 0x24) = 0;
  *(uint *)(nativeFrame + 0x18) = 0;
  *(void **)(nativeFrame + 8) = actor;
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(localString,*input);
  uint eventName = *(uint *)0x10092e70;
  byte *dispatchTable = *(byte **)receiver;
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)
      (receiver,eventName,0);
  (*(EventABI *)(dispatchTable + 0x10))(receiver,function,nativeFrame + 0x8,nullptr);
  uint output = *(uint *)(nativeFrame + 0x18);
  *(uint *)(nativeFrame + 0x24) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(localString);
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x8
  }
}

// Copies the input message into an owned event string, dispatches ProcessServerMsg and releases that local.
// R6GameService.dll @ 10001ec0 : C++ event operations with native frame, hidden-result ABI and unwind slots.
__declspec(naked) void __thiscall UR6GSServers::eventProcessServerMsg(APlayerController *controller,const FString& messageKey)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::eventProcessServerMsgSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   esi
    mov    esi,ecx
    push   edi
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DefaultABI = FString * (__thiscall *)(FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  // FName occupies one native word; ProcessEvent uses slot +0x10 of the table captured before lookup.
  using FindABI = UFunction * (__thiscall *)(UR6GSServers *,uint,int);
  using EventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
  FString *localString = (FString *)(nativeFrame + 0xc);
  // Default construction runs with state -1; failure does not destroy this local.
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(localString);
  using AssignABI = FString& (__thiscall *)(FString *,const FString&);
  const FString *input = *(const FString **)(nativeFrame + 0x2c);
  void *actor = *(void **)(nativeFrame + 0x28);
  *(uint *)(nativeFrame + 0x20) = 0;
  *(void **)(nativeFrame + 8) = actor;
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(localString,*input);
  uint eventName = *(uint *)0x100923f8;
  byte *dispatchTable = *(byte **)receiver;
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)
      (receiver,eventName,0);
  (*(EventABI *)(dispatchTable + 0x10))(receiver,function,nativeFrame + 0x8,nullptr);
  *(uint *)(nativeFrame + 0x20) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(localString);
  __asm {
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x8
  }
}

// Dispatches GetConsoleStoreIP, copies the local string into hidden caller storage and releases the local.
// R6GameService.dll @ 10001f50 : C++ event operations with native frame, hidden-result ABI and unwind slots.
__declspec(naked) FString * __thiscall UR6GSServers::eventGetConsoleStoreIP
    (FString *hiddenResult,APlayerController *controller)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServersSharedLifetimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebp
    push   esi
    mov    esi,ecx
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DefaultABI = FString * (__thiscall *)(FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  // FName occupies one native word; ProcessEvent uses slot +0x10 of the table captured before lookup.
  using FindABI = UFunction * (__thiscall *)(UR6GSServers *,uint,int);
  using EventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
  *(uint *)(nativeFrame + 8) = 0;
  FString *localString = (FString *)(nativeFrame + 0x10);
  // Default construction runs with state -1; failure does not destroy this local.
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(localString);
  uint eventName = *(uint *)0x10092e5c;
  APlayerController *actor = *(APlayerController **)(nativeFrame + 0x30);
  byte *dispatchTable = *(byte **)receiver;
  *(uint *)(nativeFrame + 0x24) = 1;
  *(APlayerController **)(nativeFrame + 0xc) = actor;
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)
      (receiver,eventName,0);
  (*(EventABI *)(dispatchTable + 0x10))(receiver,function,nativeFrame + 0xc,nullptr);
  using CopyABI = FString * (__thiscall *)(FString *,const FString&);
  FString *output = *(FString **)(nativeFrame + 0x2c);
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(output,*localString);
  // Only a completed copy arms output destruction; lowering state changes just the low byte.
  *(uint *)(nativeFrame + 8) = 1;
  *(byte *)(nativeFrame + 0x24) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(localString);
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x20
    ret    0x8
  }
}

// Dispatches GetLocallyBoundIpAddr, copies the local string into hidden caller storage and releases the local.
// R6GameService.dll @ 10001ff0 : C++ event operations with native frame, hidden-result ABI and unwind slots.
__declspec(naked) FString * __thiscall UR6GSServers::eventGetLocallyBoundIpAddr(FString *hiddenResult)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::eventGetLocallyBoundIpAddrSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebp
    push   esi
    mov    esi,ecx
    mov    nativeFrame,esp
    mov    receiver,esi
  }
  using DefaultABI = FString * (__thiscall *)(FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  // FName occupies one native word; ProcessEvent uses slot +0x10 of the table captured before lookup.
  using FindABI = UFunction * (__thiscall *)(UR6GSServers *,uint,int);
  using EventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
  *(uint *)(nativeFrame + 8) = 0;
  FString *localString = (FString *)(nativeFrame + 0xc);
  // Default construction runs with state -1; failure does not destroy this local.
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(localString);
  uint eventName = *(uint *)0x10092408;
  byte *dispatchTable = *(byte **)receiver;
  *(uint *)(nativeFrame + 0x20) = 1;
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)
      (receiver,eventName,0);
  (*(EventABI *)(dispatchTable + 0x10))(receiver,function,nativeFrame + 0xc,nullptr);
  using CopyABI = FString * (__thiscall *)(FString *,const FString&);
  FString *output = *(FString **)(nativeFrame + 0x28);
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(output,*localString);
  // Only a completed copy arms output destruction; lowering state changes just the low byte.
  *(uint *)(nativeFrame + 8) = 1;
  *(byte *)(nativeFrame + 0x20) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(localString);
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [esp+0x18]
    mov    eax,esi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x4
  }
}

// Destroys IsGlobalIDBanned parameter string at parent EBP-0x1c through the +4 wrapper.
// R6GameService.dll @ 10063190 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventIsGlobalIDBannedUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x20]
    jmp    R6GameServiceAddresses::DestroyFStringAt04
  }
}

// Selects the one-state IsGlobalIDBanned parameter cleanup map.
// R6GameService.dll @ 10063198 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventIsGlobalIDBannedSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::eventIsGlobalIDBannedExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys ProcessServerMsg parameter string at parent EBP-0x18 through the +4 wrapper.
// R6GameService.dll @ 100631b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventProcessServerMsgUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::DestroyFStringAt04
  }
}

// Selects the one-state ProcessServerMsg parameter cleanup map.
// R6GameService.dll @ 100631b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventProcessServerMsgSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::eventProcessServerMsgExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the local return string shared by TempGetPBConnectStatus and GetConsoleStoreIP at parent EBP-0x18.
// R6GameService.dll @ 100631d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersSharedLifetimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::DestroyFStringAt04
  }
}

// Clears armed return flag bit0 before destroying the current hidden-output pointer at parent EBP+4.
// R6GameService.dll @ 100631d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersSharedLifetimeUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    and    eax,0x1
    je     Branch6
    and    DWORD PTR [ebp-0x20],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch6:
    ret
  }
}

// Selects the two-state local/hidden-output map shared by TempGetPBConnectStatus and GetConsoleStoreIP.
// R6GameService.dll @ 100631f2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersSharedLifetimeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys GetLocallyBoundIpAddr local return string at parent EBP-0x18 through the direct FString tail.
// R6GameService.dll @ 10063200 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventGetLocallyBoundIpAddrUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::FString__FString
  }
}

// Clears armed return flag bit0 before destroying GetLocallyBoundIpAddr current output pointer at EBP+4.
// R6GameService.dll @ 10063208 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventGetLocallyBoundIpAddrUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    and    eax,0x1
    je     Branch7
    and    DWORD PTR [ebp-0x1c],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch7:
    ret
  }
}

// Selects the two-state GetLocallyBoundIpAddr local/hidden-output cleanup map.
// R6GameService.dll @ 10063222 : complete native control/access order and raw ABI retained.
__declspec(naked) void eventGetLocallyBoundIpAddrSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::eventGetLocallyBoundIpAddrExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Runs patch, registration, MS client, and CD-key shutdown only when the game is shutting down, then destroys UObject.
// If game shutdown is nonzero, stop patch/registration/MS/CD-key services in order; always call current UObject::Destroy.
// Keep late MS/logging/logger reads, clear initialized flag before unconditional logged-off diagnostic and preserve child failures.
// R6GameService.dll @ 10005680 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::Destroy(UR6GSServers *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectManagerParentEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (getGameShutDown()) {
    UeviLPatchService::FinalDestroy();
    receiver->UnInitRegServer();
    if (*reinterpret_cast<int*>(0x10091e64)) {
      CloseMSClientSingleton();
      if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging))
        GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientUninitialize));
      // This clear precedes the unconditional log; the logger is reloaded after shutdown and optional logging.
      *reinterpret_cast<int*>(0x10091e64) = 0;
      GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextLoggedOffFromUbiComMSClientService));
    }
    receiver->UnInitCDKey();
  }
  receiver->UObject::Destroy();
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Select exact manager parent two-state/no-action unwind and typed/context catch records.
// R6GameService.dll @ 10063760 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectManagerParentEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_DestroyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b858 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_DestroyUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b868 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGManagerParentEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24, R6GameServiceAddresses::UR6GSServersCatch},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch},
};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b868 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_DestroyTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGManagerParentEH},
};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b858 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_DestroyExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_DestroyUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_DestroyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000572d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServersCatch(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Convert the second incoming string and submit a copied first string to the ping service.
// Exported nonvirtual void(FString,FString), incoming ECX unused/RET24. Both incoming values owned;
// state2 protects them while the outgoing copy constructs and the service receives string/ANSI/zero.
// The lower request owns that copy. Normal destruction lowers state before first, then second dtor;
// a failed destructor is not retried. Conversion pointer is borrowed and service pointer loads late.
// R6GameService.dll @ 10005980 : exported void(FString,FString), owns both values, RET24; receiver unused.
__declspec(naked) void __thiscall UR6GSServers::PingRequest(FString firstString,FString secondString)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_PingRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using CopyABI = FString * (__thiscall *)(FString *,const FString *);
  using RequestABI = void (__thiscall *)(void *,uint,uint,uint,const char *,uint);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame - 4) = 0;
  *(byte *)(nativeFrame - 4) = 2;
  const TCHAR *wideAddress = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((const FString *)(nativeFrame + 0x14));
  const char *address = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wideAddress);
  uint transferred[3];
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)
      ((FString *)transferred,(const FString *)(nativeFrame + 8));
  void *queue = *(void **)0x10091e50;
  // The three copied words become the callee-owned FString; this caller never arms its outgoing copy.
  ((RequestABI)R6GameServiceAddresses::ServerPing_NewPingRequest)
      (queue,transferred[0],transferred[1],transferred[2],address,0);
  *(uint *)(nativeFrame - 4) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame + 8));
  *(uint *)(nativeFrame - 4) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame + 0x14));
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x18
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10005a12 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::PingRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10005a26 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch3(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPingRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the second incoming ping string at inherited parent EBP+0x14.
// R6GameService.dll @ 10063770 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_PingRequestUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x14]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the first incoming ping string at inherited parent EBP+0x8.
// R6GameService.dll @ 10063779 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_PingRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select the ping/manager guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063782 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_PingRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_PingRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native ping/manager unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007b8b8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_PingRequestUnwindMap[4] = {
  {-1, R6GameServiceAddresses::UR6GSServers_PingRequestUnwind1},
  {0x0, R6GameServiceAddresses::UR6GSServers_PingRequestUnwind2},
  {0x1, 0x0},
  {0x1, 0x0},
};

// Native ping/manager handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007b8d8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GPingRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch2},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch3},
};

// Native ping/manager try record; addresses and states are literal.
// R6GameService.dll data @ 1007b8d8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_PingRequestTryMap[1] = {
  {0x2, 0x2, 0x3, 0x2, R6GameServiceAddresses::GPingRequestHandlers},
};

// Native ping/manager info record; addresses and states are literal.
// R6GameService.dll data @ 1007b8b8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_PingRequestExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::UR6GSServers_PingRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_PingRequestTryMap,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007b928 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry UR6GSServers_PollPingManagerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007b938 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GPollPingPollHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch4},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch5},
};
// R6GameService.dll data @ 1007b958 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock UR6GSServers_PollPingManagerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GPollPingPollHandlers},
};
// R6GameService.dll data @ 1007b96c : selected guard/cleanup records.
// R6GameService.dll data @ 1007b928 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_PollPingManagerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_PollPingManagerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_PollPingManagerTryMap,
  0x0,
  0x0,
};

// Polls against m_GameServerList+0x5c, stores completion, then reloads the queue for its remaining count.
// Raw EAX is the second-word accessor result when enabled, otherwise zero; the exported method is void.
// R6GameService.dll @ 10005a50 : exported void(int); queue roles inferred, server array offset corroborated by 1.60.
void __thiscall UR6GSServers::PollPingManager(int enabled)
{
  try {
    if (enabled != 0) {
      using PollABI = uint (__thiscall *)(void *,FArray *,int *);
      void *queue = *(void **)0x10091e50;
      uint completed = ((PollABI)R6GameServiceAddresses::ServerPing_PingManager)
          (queue,(FArray *)((byte *)this + 0x5c),0);
      queue = *(void **)0x10091e50;
      *(uint *)0x10091c20 = completed;
      uint remaining = ReadSecondWord(queue);
      *(uint *)0x10091d3c = remaining;
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersPollPingManager);
    throw;
  }
}

// Forwards the caught unsigned-short pointer from parent EBP-0x18 to-0x14.
// R6GameService.dll @ 10005ab8 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PollPingManager context and rethrows the active exception.
// R6GameService.dll @ 10005acc : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch5(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPollPingManager
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state ping-poll guard with no local cleanup actions.
// R6GameService.dll @ 10063790 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollPingManagerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_PollPingManagerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Consumes five live registration reply words, mapping26/27 to6/3 and retaining native read/clear/store order.
// R6GameService.dll @ 10013330 : implicit ECX receiver unused; RET4 and native EAX residue.
__declspec(naked) void __thiscall UR6GSServers::PollRegServerCallbacks(int enabled)
{
  uint initialized;
  byte *nativeFrame;
  __asm {
    mov    eax,ds:0x10093b08
    push   esi
    xor    esi,esi
    mov    initialized,eax
    mov    nativeFrame,esp
  }
  uint residue = initialized;
  if (initialized != 0 && *(uint *)(nativeFrame + 8) != 0) {
    ((void (__cdecl *)(void))R6GameServiceAddresses::ProcessRegistrationServiceCallbacks)();
    uint reply = *(uint *)0x10093b10;
    if (reply == 0x26) *(uint *)0x100939e8 = 6;
    else if (reply == 0x27) *(uint *)0x100939e8 = 3;
    reply = *(uint *)0x10093b20;
    *(uint *)0x10093b10 = 0;
    if (reply == 0x26) *(uint *)0x10093af4 = 6;
    else if (reply == 0x27) *(uint *)0x10093af4 = 3;
    reply = *(uint *)0x10093b00;
    *(uint *)0x10093b20 = 0;
    if (reply == 0x26) *(uint *)0x10093b14 = 6;
    else if (reply == 0x27) *(uint *)0x10093b14 = 3;
    reply = *(uint *)R6GameServiceAddresses::GSecondaryLobbyLoginReplyType;
    *(uint *)0x10093b00 = 0;
    if (reply == 0x26) {
      *(uint *)0x10093af0 = 6;
      *(uint *)0x100939ec = 1;
    } else if (reply == 0x27) *(uint *)0x10093af0 = 3;
    reply = *(uint *)0x10093b30;
    *(uint *)R6GameServiceAddresses::GSecondaryLobbyLoginReplyType = 0;
    residue = reply - 0x26;
    if (reply == 0x26) *(uint *)0x10093b2c = 6;
    else {
      --residue;
      if (reply == 0x27) {
        *(uint *)0x10093b30 = 0;
        *(uint *)0x10093b2c = 3;
        __asm {
          mov    eax,residue
          pop    esi
          ret    0x4
        }
      }
    }
    *(uint *)0x10093b30 = 0;
  }
  __asm {
    mov    eax,residue
    pop    esi
    ret    0x4
  }
}

// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// R6GameService.dll @ 100062b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execGetMaxUbiServerNameSize(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectSmallVMBridgeEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch23
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch23:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x20
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063820 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectSmallVMBridgeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execGetMaxUbiServerNameSizeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bbd8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execGetMaxUbiServerNameSizeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bbe8 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSmallVMBridgeEH2[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch10},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch11},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bbe8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execGetMaxUbiServerNameSizeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGSmallVMBridgeEH2},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bbd8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execGetMaxUbiServerNameSizeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execGetMaxUbiServerNameSizeUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execGetMaxUbiServerNameSizeTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10006318 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Compares an address with returned interface addresses/masks; the incoming FString is owned by this call.
// R6GameService.dll @ 10006450 : int(FString), thiscall/RET12; interface records are 0x4c bytes, address+8/mask+38.
int __thiscall UR6GSServers::OnSameSubNet(FString address)
{
  try {
    using AnsiABI = const char *(__cdecl *)(const TCHAR *);
    using ParseABI = uint (__stdcall *)(const char *);
    using TextABI = const char *(__stdcall *)(uint);
    using SocketABI = uint (__stdcall *)(int,int,int);
    using IoctlABI = int (__stdcall *)(uint,uint,void *,uint,void *,uint,uint *,void *,void *);
    const TCHAR *wideAddress = *address;
    const char *ansiAddress = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wideAddress);
    uint targetAddress = (*(ParseABI *)R6GameServiceAddresses::WS2_32_inet_addrSlot)(ansiAddress);
    uint socketHandle = (*(SocketABI *)R6GameServiceAddresses::WS2_32_socketSlot)(2,2,17);
    byte interfaces[0x5f0];
    uint bytesReturned; // Deliberately uninitialized if a successful provider does not publish the count.
    int ioctlResult = (*(IoctlABI *)R6GameServiceAddresses::WS2_32_WSAIoctlSlot)
        (socketHandle,0x4004747f,0,0,interfaces,0x5f0,&bytesReturned,0,0);
    // Only -1 fails. Native forwards INVALID_SOCKET and does not close the socket on any path.
    if (ioctlResult == -1)
      return 0;
    uint interfaceCount = bytesReturned / 0x4c;
    uint index = 0;
    bool differentSubnet = true;
    while (differentSubnet && index < interfaceCount) {
      uint recordOffset = index * 0x4c;
      uint maskWord = *(uint *)(interfaces + recordOffset + 0x38);
      const char *maskText = (*(TextABI *)R6GameServiceAddresses::WS2_32_inet_ntoaSlot)(maskWord);
      uint mask = (*(ParseABI *)R6GameServiceAddresses::WS2_32_inet_addrSlot)(maskText);
      uint addressWord = *(uint *)(interfaces + recordOffset + 8);
      const char *addressText = (*(TextABI *)R6GameServiceAddresses::WS2_32_inet_ntoaSlot)(addressWord);
      uint localAddress = (*(ParseABI *)R6GameServiceAddresses::WS2_32_inet_addrSlot)(addressText);
      differentSubnet = (localAddress & mask) != (mask & targetAddress);
      ++index;
    }
    // The result is fixed before the callee-owned argument is destroyed, outside the guarded body.
    return differentSubnet ? 0 : 1;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersOnSameSubNet);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10006582 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch12(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x24]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Clear client/request/login state, optionally log, then shut down the singleton and zero-extend its low result byte.
// R6GameService.dll @ 10006650 : pre-guard mutations and zero-extended low-byte result.
int __thiscall UR6GSServers::UnInitMSClient(void)
{
  *(uint *)0x10091e6c = 0;
  uint flags = *(uint *)((byte *)this + 0x194);
  flags &= 0xffffff7f;
  *(uint *)((byte *)this + 0x194) = flags;
  uint logging = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  try {
    *(uint *)R6GameServiceAddresses::GLoggedInUbiDotCom = 0;
    *(uint *)R6GameServiceAddresses::GJoinInProgress = 0;
    *(uint *)0x10091d30 = 0;
    *(uint *)0x10091d38 = 0;
    *(uint *)0x10091e68 = 0;
    *(uint *)0x10091e64 = 0;
    if (logging != 0) {
      using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextMSClientUninitialize);
    }
    uint raw = CloseMSClientSingleton();
    return (byte)raw;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecNativeUnInitMSClient);
    throw;
  }
}

// Selects UnInitMSClient's two-state guard and private typed/context catches; neither state has local cleanup.
// R6GameService.dll @ 10063860 : private exception selector; forwards literal FuncInfo through CRT thunk.
__declspec(naked) void __cdecl UnInitMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UnInitMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007bd00 : selected native guard record.
const R6GameServiceNative::UnwindEntry UnInitMSClientUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007bd10 : selected native guard record.
const R6GameServiceNative::CatchHandler GUnInitMSClientHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch14},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch15},
};
// R6GameService.dll data @ 1007bd30 : selected native guard record.
const R6GameServiceNative::TryBlock UnInitMSClientTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GUnInitMSClientHandlers},
};
// R6GameService.dll data @ 1007bd44 : selected native guard record.
// R6GameService.dll data @ 1007bd00 : native storage identity retained.
const R6GameServiceNative::FuncInfo UnInitMSClientExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UnInitMSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::UnInitMSClientTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100066e2 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch14(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeUnInitMSClient context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100066f6 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch15(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeUnInitMSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    eax,eax
    push   eax
    push   eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Consumes optional debug info on Stack.Object, shuts down the original receiver, then writes full DWORD result.
// R6GameService.dll @ 10006720 : exported FFrame&/void* bridge, RET8; matching package returns script Boolean.
__declspec(naked) void __thiscall UR6GSServers::execUnInitializeMSClient(FFrame &Stack, void * const Result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::execUnInitializeMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // Aliases below refer to the retained native frame; they do not define a new exception layout.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  FFrame* executionStack = *reinterpret_cast<FFrame**>(nativeFrame + 8);
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  byte* next = code + 1;
  code = next;
  const bool debugInfo = *next == 0x42;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (debugInfo) {
    UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
    code = next + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
    natives[0x42](context, executionStack, nullptr);
  }
  const int closed = receiver->UnInitMSClient();
  int* output = *reinterpret_cast<int**>(nativeFrame + 0xc);
  *output = closed;
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x8
  }
}

// Selects the shutdown script bridge's two-state guard and typed/context catches; no local cleanup actions.
// R6GameService.dll @ 10063870 : private exception selector; exact metadata register and CRT tail retained.
__declspec(naked) void __cdecl execUnInitializeMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execUnInitializeMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007bd60 : selected native guard record.
const R6GameServiceNative::UnwindEntry execUnInitializeMSClientUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007bd70 : selected native guard record.
const R6GameServiceNative::CatchHandler GExecUnInitializeMSClientHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch16},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch17},
};
// R6GameService.dll data @ 1007bd90 : selected native guard record.
// R6GameService.dll data @ 1007bd70 : native storage identity retained.
const R6GameServiceNative::TryBlock execUnInitializeMSClientTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GExecUnInitializeMSClientHandlers},
};
// R6GameService.dll data @ 1007bda4 : selected native guard record.
// R6GameService.dll data @ 1007bd60 : native storage identity retained.
const R6GameServiceNative::FuncInfo execUnInitializeMSClientExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execUnInitializeMSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::execUnInitializeMSClientTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000678d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch16(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execUnInitializeMSClient context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100067a1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch17(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecUnInitializeMSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// R6GameService.dll @ 100067c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeGetMSClientInitialized(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectSmallVMBridgeEH2
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch29
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch29:
    mov    ecx,DWORD PTR ds:0x10091e64
    mov    eax,DWORD PTR [ebp+0xc]
    pop    edi
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063880 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectSmallVMBridgeEH2(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeGetMSClientInitializedExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bdc0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeGetMSClientInitializedUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bdd0 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSmallVMBridgeEH6[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch18},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch19},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bdd0 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeGetMSClientInitializedTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGSmallVMBridgeEH6},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bdc0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeGetMSClientInitializedExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeGetMSClientInitializedUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeGetMSClientInitializedTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000682a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch18(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Return the nonzero request-state predicate as a full 32-bit zero or one.
// R6GameService.dll @ 10006860 : virtual int export; ECX becomes the global request word, RET0.
// Global role names are inferred.
int __thiscall UR6GSServers::IsMSClientIsInRequest(void)
{
  return *reinterpret_cast<const uint *>(0x10091c14) != 0;
}

// Return the full login word without normalization.
// R6GameService.dll @ 10006870 : virtual int export; unused ECX receiver, RET0; global role names inferred.
int __thiscall UR6GSServers::GetLoggedInUbiDotCom(void)
{
  return *reinterpret_cast<const int *>(0x10091e68);
}

// Finish VM parameters and report whether either full-width refresh flag is set.
// R6GameService.dll @ 10007050 : FFrame/result bridge; typed forwarding and context rethrow preserved.
void __thiscall UR6GSServers::execIsRefreshServersInProgress(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,frame,nullptr);
    }
    bool refreshingAll = *(int *)0x10091d38 != 0;
    int active = refreshingAll || *(int *)0x10091d30 != 0;
    *(int *)Result = active;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecIsRefreshServersInProgress);
    throw;
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063900 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectSmallVMBridgeEH3(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execIsRefreshServersInProgressExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bed8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execIsRefreshServersInProgressUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bee8 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSmallVMBridgeEH10[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch22},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch23},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bee8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execIsRefreshServersInProgressTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGSmallVMBridgeEH10},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bed8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execIsRefreshServersInProgressExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execIsRefreshServersInProgressUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execIsRefreshServersInProgressTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100070b2 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch22(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Finish VM parameters and clear the all-server and single-server refresh flags in that order.
// R6GameService.dll @ 10007100 : FFrame/result bridge; typed forwarding and context rethrow preserved.
void __thiscall UR6GSServers::execStopRefreshServers(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,frame,nullptr);
    }
    *(uint *)0x10091d38 = 0;
    *(uint *)0x10091d30 = 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecStopRefreshServers);
    throw;
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063910 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectSmallVMBridgeEH4(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execStopRefreshServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bf38 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execStopRefreshServersUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bf48 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSmallVMBridgeEH14[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch24},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch25},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bf48 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execStopRefreshServersTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGSmallVMBridgeEH14},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bf38 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execStopRefreshServersExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execStopRefreshServersUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execStopRefreshServersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007168 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch24(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Completes a matching stored request; zero AL preserves join globals only while the current logging gate is enabled.
// R6GameService.dll @ 100071a0 : C++ leave/matching/logging with native current gates and low-byte return.
__declspec(naked) int __thiscall UR6GSServers::MSCLientLeaveServer()
{
  byte *nativeFrame;
  uint group;
  uint lobby;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::MSCLientLeaveServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:R6GameServiceAddresses::GJoinGroupId
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GJoinLobbyId
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
    mov    group,eax
    mov    lobby,ecx
  }
  *(uint *)(nativeFrame - 4) = 0;
  using MatchABI = uint (__stdcall *)(uint,uint);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  uint raw = ((MatchABI)R6GameServiceAddresses::MatchMSClientStoredRequest)(lobby,group);
  uint output = (byte)raw;
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextMSClientLeaveGameServer);
  }
  if (output == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextMSClientLeaveGameServerFAILED);
    __asm {
      mov    esi,output
      mov    eax,esi
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  }
  uint predecessor = *(uint *)(nativeFrame - 0xc);
  *(uint *)R6GameServiceAddresses::GLoggedInUbiDotCom = 0;
  *(uint *)R6GameServiceAddresses::GJoinInProgress = 0;
  __asm {
    mov    ecx,predecessor
    mov    esi,output
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Selects MSCLientLeaveServer's two-state guard and private typed/context catches; neither state has local cleanup.
// R6GameService.dll @ 10063920 : private exception selector; forwards literal FuncInfo through CRT thunk.
__declspec(naked) void __cdecl MSCLientLeaveServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::MSCLientLeaveServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007bf98 : selected native guard record.
const R6GameServiceNative::UnwindEntry MSCLientLeaveServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007bfa8 : selected native guard record.
const R6GameServiceNative::CatchHandler GMSCLientLeaveServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch26},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch27},
};
// R6GameService.dll data @ 1007bfc8 : selected native guard record.
const R6GameServiceNative::TryBlock MSCLientLeaveServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GMSCLientLeaveServerHandlers},
};
// R6GameService.dll data @ 1007bfdc : selected native guard record.
// R6GameService.dll data @ 1007bf98 : native storage identity retained.
const R6GameServiceNative::FuncInfo MSCLientLeaveServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::MSCLientLeaveServerUnwindMap,
  0x1,
  R6GameServiceAddresses::MSCLientLeaveServerTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007230 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch26(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::MSCLientLeaveServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007244 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch27(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersMSCLientLeaveServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    edi,edi
    push   edi
    push   edi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 10007280 : start a service join and consume its password
// Starts one join request, converts its strings to ANSI, reports optional diagnostics, and destroys the password.
void __thiscall UR6GSServers::MSCLientJoinServer(
    UR6GSServers *this,int lobbyId,int groupId,ushort *passwordData,int passwordCount,int passwordCapacity)
{
    // Expanded x86 ABI view: the three adjacent password words form one owned incoming FString.
    FString *password = (FString *)&passwordData;
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &SelectInheritedFStringEH;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    int joinInProgress = GJoinInProgress;
    guardState = 0;
    guardState = 1; // FuncInfo 0x1007c044 links to state zero's incoming-password cleanup.
    using LogfCall = void (__cdecl *)(FOutputDevice *,const ushort *,...);
    if (joinInProgress != 0) {
        if (GServiceVerboseLogging != 0) {
            FOutputDevice *log = *(FOutputDevice **)GLog_exref;
            LogfCall logf = *(LogfCall *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
            logf(log,L"MSClient_JoinGameServer() already in progress");
        }
    } else {
        int capturedLobbyId = lobbyId;
        GJoinLobbyId = capturedLobbyId;
        GJoinGroupId = groupId;
        GJoinInProgress = 1;
        const ushort *globalText = FString::operator*((FString *)&GServiceString1);
        using ToAnsi = const char *(__cdecl *)(const ushort *);
        ToAnsi convert = *(ToAnsi *)R6GameServiceAddresses::Core__appToAnsiSlot;
        const char *globalAnsi = convert(globalText);
        const ushort *versionText = FString::operator*(&this->m_szGSVersion); // +0x1ac.
        const char *versionAnsi = convert(versionText);
        const ushort *passwordText = FString::operator*(password);
        const char *passwordAnsi = convert(passwordText);
        int requestGroupId = groupId;
        byte requested = SetSingletonServiceRequest(
            capturedLobbyId,requestGroupId,passwordAnsi,versionAnsi,globalAnsi,nullptr,0);

        LogfCall logf;
        if (GServiceVerboseLogging != 0) {
            FOutputDevice *log = *(FOutputDevice **)GLog_exref;
            logf = *(LogfCall *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
            logf(log,L"---> MSClient_JoinGameServer() iLobbyID = %i ",capturedLobbyId);
            log = *(FOutputDevice **)GLog_exref;
            logf(log,L"---> MSClient_JoinGameServer() iGroupID = %i ",requestGroupId);
        } else {
            logf = *(LogfCall *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
        }
        if (requested == 0 && GServiceVerboseLogging != 0) {
            FOutputDevice *log = *(FOutputDevice **)GLog_exref;
            logf(log,L"---> MSClient_JoinGameServer  FAILED");
        }
    }
    guardState = 0xffffffff;
    FString::~FString(password);
    ExceptionList = previousExceptionList;
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100073cd : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch28(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 10007400 : decode join IDs/password and dispatch the owned password copy
// Evaluates the join operands and optional DebugInfo, transfers a password copy, then destroys the decoded original.
void __thiscall UR6GSServers::execNativeMSCLientJoinServer(
    UR6GSServers *this,FFrame *stack,void *unusedResult)
{
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &UR6GSServers_SelectInheritedFStringEH;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    using ScriptNative = void (__thiscall *)(UObject *,FFrame *,void *);
    byte **codeCursor = (byte **)((byte *)stack + 0x0c);
    int lobbyId = 0;
    byte token = *(*codeCursor)++;
    ScriptNative evaluate = ((ScriptNative *)GNatives_exref)[token];
    UObject *receiver = *(UObject **)((byte *)stack + 8);
    guardState = 0;
    evaluate(receiver,stack,&lobbyId);

    receiver = *(UObject **)((byte *)stack + 8);
    int groupId = 0;
    token = *(*codeCursor)++;
    evaluate = ((ScriptNative *)GNatives_exref)[token];
    evaluate(receiver,stack,&groupId);
    uint passwordStorage[3];
    FString *password = (FString *)passwordStorage;
    FString::FString(password);
    token = **codeCursor;
    receiver = *(UObject **)((byte *)stack + 8);
    ++*codeCursor;
    evaluate = ((ScriptNative *)GNatives_exref)[token];
    guardState = 1; // FuncInfo 0x1007c0ac destroys the original password at EBP-0x2c via 0x10063950.
    evaluate(receiver,stack,password);
    ++*codeCursor;
    if (**codeCursor == 0x42) {
        receiver = *(UObject **)((byte *)stack + 8);
        ++*codeCursor;
        ScriptNative debugInfo = ((ScriptNative *)GNatives_exref)[0x42];
        debugInfo(receiver,stack,nullptr);
    }

    uint outgoingStorage[3];
    FString *outgoingPassword = (FString *)outgoingStorage;
    FString::FString(outgoingPassword,password);
    MSCLientJoinServer(this,lobbyId,groupId,*(ushort **)outgoingPassword,
        *(int *)((byte *)outgoingPassword + 4),*(int *)((byte *)outgoingPassword + 8));
    guardState = 0;
    FString::~FString(password);
    ExceptionList = previousExceptionList;
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100074ef : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch30(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x18]
    push   ecx
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 10007520 : int IsServerJoined(UR6GSServers * this)
// Returns the server-joined value from global word 0x10091c00.
/* public: virtual int __thiscall UR6GSServers::IsServerJoined(void) */
int __thiscall UR6GSServers::IsServerJoined(UR6GSServers *this)
{
                    /* 0x7520  78  ?IsServerJoined@UR6GSServers@@UAEHXZ */
  return GLoggedInUbiDotCom;
}

// R6GameService.dll @ 10007530 : notify the service that a client connected to a lobby/group
// Sends the connection notification and, when logging starts enabled, reports IDs and any failed result.
void __thiscall UR6GSServers::MSClientServerConnected(UR6GSServers *this,int lobbyId,int groupId)
{
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &UR6GSServers_SelectParentExceptionInfo;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    guardState = 0; // FuncInfo 0x1007c10c has no local cleanup actions.
    using NotifyConnected = byte (__stdcall *)(int,int);
    NotifyConnected notify = (NotifyConnected)R6GameServiceAddresses::ForwardMSClientOperation4;
    byte accepted = notify(lobbyId,groupId);
    if (GServiceVerboseLogging != 0) {
        FOutputDevice *log = *(FOutputDevice **)GLog_exref;
        using LogfCall = void (__cdecl *)(FOutputDevice *,const ushort *,...);
        LogfCall logf = *(LogfCall *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
        logf(log,L"---> MSClient_GameServerConnected() iLobbyID = %i ",lobbyId);
        log = *(FOutputDevice **)GLog_exref;
        logf(log,L"---> MSClient_GameServerConnected() iGroupID = %i ",groupId);
        if (accepted == 0) {
            log = *(FOutputDevice **)GLog_exref;
            logf(log,L"---> MSClient_GameServerConnected  FAILED");
        }
    }
    ExceptionList = previousExceptionList;
}

// Select UR6GSServers::MSClientServerConnected native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063970 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c0c8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap2[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c0d8 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo2[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch32},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch33},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c0d8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo2},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c0c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap2,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100075c8 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch32(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 10007600 : decode alternate-info request IDs and apply the shared request gate
// Evaluates lobby/group IDs and optional DebugInfo, then sends one request until the shared gate is reset.
void __thiscall UR6GSServers::execNativeMSClientReqAltInfo(UR6GSServers *this,FFrame *stack,void *unusedResult)
{
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &UR6GSServers_SelectParentExceptionInfo2;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    using ScriptNative = void (__thiscall *)(UObject *,FFrame *,void *);
    byte **codeCursor = (byte **)((byte *)stack + 0x0c);
    UObject *receiver = *(UObject **)((byte *)stack + 8);
    int lobbyId = 0;
    byte token = *(*codeCursor)++;
    ScriptNative evaluate = ((ScriptNative *)GNatives_exref)[token];
    guardState = 0; // FuncInfo 0x1007c16c has no local cleanup actions.
    evaluate(receiver,stack,&lobbyId);
    receiver = *(UObject **)((byte *)stack + 8);
    int groupId = 0;
    token = *(*codeCursor)++;
    evaluate = ((ScriptNative *)GNatives_exref)[token];
    evaluate(receiver,stack,&groupId);
    ++*codeCursor;
    if (**codeCursor == 0x42) {
        receiver = *(UObject **)((byte *)stack + 8);
        ++*codeCursor;
        ScriptNative debugInfo = ((ScriptNative *)GNatives_exref)[0x42];
        debugInfo(receiver,stack,nullptr);
    }
    if (GCreateLobbyRequested == 0) {
        GCreateLobbyRequested = 1;
        using RequestAltInfo = byte (__stdcall *)(int,int);
        RequestAltInfo request = (RequestAltInfo)R6GameServiceAddresses::ForwardMSClientOperation3;
        request(lobbyId,groupId);
        if (GServiceVerboseLogging != 0) {
            FOutputDevice *log = *(FOutputDevice **)GLog_exref;
            using LogfCall = void (__cdecl *)(FOutputDevice *,const ushort *,...);
            LogfCall logf = *(LogfCall *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
            logf(log,L"---> MSClient_RequestAlternateInfo()");
        }
    }
    ExceptionList = previousExceptionList;
}

// Select UR6GSServers::execNativeMSClientReqAltInfo native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063980 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo2(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo3
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c128 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap3[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c138 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo6[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch34},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch35},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c138 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap2[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo6},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c128 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo3 = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap3,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap2,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100076d7 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch34(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 10007790 : assign the decoded IP-address string to the shared last-server value
// Evaluates the address and optional DebugInfo, copies it to the shared value, and destroys the temporary.
void __thiscall UR6GSServers::execSetLastServerQueried(UR6GSServers *this,FFrame *stack,void *unusedResult)
{
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &UR6GSServers_SelectInheritedFStringEH2;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    uint addressStorage[3];
    FString *address = (FString *)addressStorage;
    guardState = 0;
    FString::FString(address);
    byte **codeCursor = (byte **)((byte *)stack + 0x0c);
    byte token = **codeCursor;
    UObject *receiver = *(UObject **)((byte *)stack + 8);
    ++*codeCursor;
    using ScriptNative = void (__thiscall *)(UObject *,FFrame *,void *);
    ScriptNative evaluate = ((ScriptNative *)GNatives_exref)[token];
    guardState = 1; // FuncInfo 0x1007c234 unwinds the address at EBP-0x24 through 0x100639a0.
    evaluate(receiver,stack,address);
    ++*codeCursor;
    if (**codeCursor == 0x42) {
        receiver = *(UObject **)((byte *)stack + 8);
        ++*codeCursor;
        ScriptNative debugInfo = ((ScriptNative *)GNatives_exref)[0x42];
        debugInfo(receiver,stack,nullptr);
    }
    FString::operator=((FString *)&GLastServerQueriedAddress,address);
    guardState = 0;
    FString::~FString(address);
    ExceptionList = previousExceptionList;
}

// Copy inherited unsigned-short pointer from EBP-18 to EBP-14, then typed throw; no pointee read/destructor.
// R6GameService.dll @ 10007835 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch36(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Report execSetLastServerQueried context through current Core import, then rethrow null exception/type.
// R6GameService.dll @ 10007849 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch37(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecSetLastServerQueried
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Starts/times out a pending join, or obtains IDs and reports connection success; message lifetimes are guarded.
// Global join-state/start-time and timeout field +0x198 roles are inferred.
// R6GameService.dll @ 10007870 : C++ join states and message lifetimes with native scratch/guard slots.
__declspec(naked) void __thiscall UR6GSServers::ProcessJoinServerRequest()
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo3
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x2c
    mov    eax,ds:R6GameServiceAddresses::GLoginRequested
    push   ebx
    xor    ebx,ebx
    push   esi
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],ebx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  using ConstructABI = FString * (__thiscall *)(FString *,const TCHAR *);
  using DestroyABI = void (__thiscall *)(FString *);
  using NotifyABI = void (__thiscall *)(void *,const FString *);
  using IDsABI = void (__thiscall *)(UR6GSServers *,int *,int *);
  using ConnectedABI = void (__thiscall *)(UR6GSServers *,int,int);
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x100933bc = (float)now;
    *(uint *)R6GameServiceAddresses::GLoginRequested = 2;
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x100933bc;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      FString *message = (FString *)(nativeFrame - 0x2c);
      (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
          (message,(const TCHAR *)R6GameServiceAddresses::WideTextLOGINFAILDEFAULT);
      void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
      void *manager = *managerSlot;
      *(byte *)(nativeFrame - 4) = 1;
      (*(NotifyABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)(manager,message);
      *(byte *)(nativeFrame - 4) = 0;
      (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(message);
      *(uint *)R6GameServiceAddresses::GLoginRequested = 3;
    }
  } else if (dispatchIndex == 5) {
    // Event output words retain incoming frame bytes until the event chooses to write them.
    ((IDsABI)R6GameServiceAddresses::UR6ServerList_eventGetLobbyAndGroupID)
        (receiver,(int *)(nativeFrame - 0x14),(int *)(nativeFrame - 0x18));
    int lobby = *(int *)(nativeFrame - 0x14);
    if (lobby != 0) {
      int group = *(int *)(nativeFrame - 0x18);
      if (group != 0) {
        ((ConnectedABI)R6GameServiceAddresses::UR6GSServers_MSClientServerConnected)(receiver,lobby,group);
        FString *message = (FString *)(nativeFrame - 0x38);
        (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
            (message,(const TCHAR *)R6GameServiceAddresses::WideTextJOINSERVERREQSUCCESS);
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        *(byte *)(nativeFrame - 4) = 2;
        (*(NotifyABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)(manager,message);
        *(byte *)(nativeFrame - 4) = 0;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(message);
      }
    }
  }
  if (dispatchIndex == 2 || dispatchIndex == 5) {
    uint predecessor = *(uint *)(nativeFrame - 0xc);
    __asm {
      pop    edi
      pop    esi
    }
    *(uint *)R6GameServiceAddresses::GLoginRequested = 0;
    __asm {
      mov    ecx,predecessor
      mov    DWORD PTR fs:0x0,ecx
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Native data @ 100079d0 : six destinations for state1..6; embedded table is not a function body.
// R6GameService.dll data @ 100079d0 : native storage identity retained.
static const unsigned int JoinRequestDispatch[6] = {
    R6GameServiceAddresses::UR6GSServersBranch36, R6GameServiceAddresses::UR6GSServersBranch38, R6GameServiceAddresses::UR6GSServersBranch40, R6GameServiceAddresses::UR6GSServersBranch37, R6GameServiceAddresses::UR6GSServersBranch37, R6GameServiceAddresses::UR6GSServersBranch39
};

// Destroys the constructed timeout message in the dispatcher-supplied parent frame.
// R6GameService.dll @ 100639c0 : private inherited-EBP cleanup; tail forwards to FString::~FString.
__declspec(naked) void __cdecl ProcessJoinServerRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed success message in the dispatcher-supplied parent frame.
// R6GameService.dll @ 100639c9 : private inherited-EBP cleanup; tail forwards to FString::~FString.
__declspec(naked) void __cdecl ProcessJoinServerRequestUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select UR6GSServers::ProcessJoinServerRequest native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 100639d2 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo3(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessJoinServerRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c250 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessJoinServerRequestUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::ProcessJoinServerRequestUnwind2},
  {0x0, R6GameServiceAddresses::ProcessJoinServerRequestUnwind3},
  {-1, 0x0},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c270 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo10[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch38},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch39},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c290 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessJoinServerRequestTryMap[1] = {
  {0x0, 0x2, 0x3, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo10},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c2a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessJoinServerRequestExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ProcessJoinServerRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::ProcessJoinServerRequestTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100079a0 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch38(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x1c]
    push   ecx
    mov    DWORD PTR [ebp-0x1c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll @ 100079f0 : process an eligible Ubi.com join and consume its password
// Starts a timed join when logged in, neither blocking global is set, and the shared threshold has elapsed.
void __thiscall UR6GSServers::ProcessUbiComJoinServer(
    UR6GSServers *this,int lobbyId,int groupId,ushort *passwordData,int passwordCount,int passwordCapacity,
    float *processValue)
{
    // Expanded x86 ABI view: these three adjacent incoming words form the callee-owned by-value FString.
    FString *password = (FString *)&passwordData;
    void *previousExceptionList = ExceptionList;
    undefined1 *exceptionHandler = &UR6GSServers_SelectInheritedFStringEH3;
    uint guardState = 0xffffffff;
    ExceptionList = &previousExceptionList;
    guardState = 0;
    byte loginFlags = *(byte *)((byte *)this + 0x194);
    guardState = 1; // FuncInfo 0x1007c30c: state 1 links to state 0's incoming-password cleanup.
    if ((loginFlags & 0x80U) != 0 && GLoggedInUbiDotCom == 0 && GJoinInProgress == 0) { // m_bLoggedInUbiDotCom
        float10 now = ReadCycleTimeSeconds();
        if (now > (float10)*processValue) {
            uint outgoingStorage[3];
            FString *outgoingPassword = (FString *)outgoingStorage;
            processValue = (float *)outgoingPassword; // Native reuses the incoming pointer word as saved outgoing ESP.
            FString::FString(outgoingPassword,password);
            using JoinServerABI = void (__thiscall *)(UR6GSServers *,int,int,ushort *,int,int);
            JoinServerABI joinServer = (JoinServerABI)R6GameServiceAddresses::UR6GSServers_MSCLientJoinServer; // MSCLientJoinServer takes another by-value FString.
            joinServer(this,lobbyId,groupId,*(ushort **)outgoingPassword,
                *(int *)((byte *)outgoingPassword + 4),*(int *)((byte *)outgoingPassword + 8));
            GLoginRequested = 1;
        }
    }
    guardState = 0xffffffff;
    FString::~FString(password);
    ExceptionList = previousExceptionList;
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007a99 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch40(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Writes the biased cycle time before shutdown, then clears flag0x20 only after shutdown returns.
// Flags at +0x2c and timestamp roles are inferred; bias constants remain explicit.
// R6GameService.dll @ 10007ad0 : C++ disconnect clock/flags with native pre-guard test and live timestamp argument.
__declspec(naked) void __thiscall UR6GSServers::ProcessIsRouterDisconnect(float *timestampOut)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  byte requested;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo4
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    mov    esi,ecx
    test   BYTE PTR [esi+0x2c],0x20
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    setnz  requested
    mov    nativeFrame,ebp
    mov    receiver,esi
  }
  if (requested != 0) {
    ulonglong counter = __rdtsc();
    *(uint *)(nativeFrame - 0x18) = (uint)counter;
    *(uint *)(nativeFrame - 0x14) = (uint)(counter >> 32);
    float10 highCycles = (float10)*(int *)(nativeFrame - 0x14);
    int highSign = *(int *)(nativeFrame - 0x14);
    if (highSign < 0) highCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    int lowSign = *(int *)(nativeFrame - 0x18);
    highCycles *= *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    float10 lowCycles = (float10)*(int *)(nativeFrame - 0x18);
    if (lowSign < 0) lowCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    const double *scale = *(const double **)R6GameServiceAddresses::Core__GSecondsPerCycleSlot;
    float10 value = highCycles + lowCycles;
    float *output = *(float **)(nativeFrame + 8);
    value *= *scale;
    value += *(double *)R6GameServiceAddresses::NativeDouble16777216_0;
    value += *(float *)R6GameServiceAddresses::NativeFloat5_0;
    *output = (float)value;
    using ShutdownABI = int (__thiscall *)(UR6GSServers *);
    ((ShutdownABI)R6GameServiceAddresses::UR6GSServers_UnInitMSClient)(receiver);
    *(uint *)((byte *)receiver + 0x2c) &= 0xffffffdf;
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Select UR6GSServers::ProcessIsRouterDisconnect native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063a00 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo4(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessIsRouterDisconnectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c328 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessIsRouterDisconnectUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c338 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo14[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch42},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch43},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c358 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessIsRouterDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo14},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c36c : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessIsRouterDisconnectExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ProcessIsRouterDisconnectUnwindMap,
  0x1,
  R6GameServiceAddresses::ProcessIsRouterDisconnectTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007b67 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch42(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x1c]
    push   edx
    mov    DWORD PTR [ebp-0x1c],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Finish VM parameters, notify an interrupted all-server refresh and handle router disconnect; the result is untouched.
// R6GameService.dll @ 10007ba0 : complete native control/access order and raw ABI retained.
void __thiscall UR6GSServers::execNativeIsRouterDisconnect(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,frame,nullptr);
    }
    if ((*((byte *)this + 0x2c) & 0x20) != 0) {
      if (*(uint *)0x10091d38 != 0) *(uint *)0x10091bf8 = 1;
      UnInitMSClient();
      *(uint *)((byte *)this + 0x2c) &= 0xffffffdf;
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecNativeIsRouterDisconnect);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007c25 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch44(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeIsRouterDisconnect context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007c39 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch45(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeIsRouterDisconnect
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select router-disconnect VM guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063a10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execNativeIsRouterDisconnectSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeIsRouterDisconnectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native router-disconnect VM unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007c388 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeIsRouterDisconnectUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native router-disconnect VM handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007c398 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecNativeIsRouterDisconnectHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch44},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch45},
};

// Native router-disconnect VM try record; addresses and states are literal.
// R6GameService.dll data @ 1007c398 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeIsRouterDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeIsRouterDisconnectHandlers},
};

// Native router-disconnect VM info record; addresses and states are literal.
// R6GameService.dll data @ 1007c388 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeIsRouterDisconnectExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeIsRouterDisconnectUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeIsRouterDisconnectTryMap,
  0x0,
  0x0,
};

// On flag0x10, optionally requests leave-server, clears the flag, then writes the biased cycle time.
// Flags at +0x2c and timestamp roles are inferred; bias constants remain explicit.
// R6GameService.dll @ 10007c60 : C++ disconnect clock/flags with native pre-guard test and live timestamp argument.
__declspec(naked) void __thiscall UR6GSServers::ProcessIsLobbyDisconnect(float *timestampOut)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  byte requested;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo5
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    mov    esi,ecx
    test   BYTE PTR [esi+0x2c],0x10
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    setnz  requested
    mov    nativeFrame,ebp
    mov    receiver,esi
  }
  if (requested != 0) {
    if (*(uint *)R6GameServiceAddresses::GLoggedInUbiDotCom != 0) {
      using LeaveABI = int (__thiscall *)(UR6GSServers *);
      byte *table = *(byte **)receiver;
      (*(LeaveABI *)(table + 0xd8))(receiver);
    }
    *(uint *)((byte *)receiver + 0x2c) &= 0xffffffef;
    ulonglong counter = __rdtsc();
    *(uint *)(nativeFrame - 0x1c) = (uint)counter;
    *(uint *)(nativeFrame - 0x18) = (uint)(counter >> 32);
    float10 highCycles = (float10)*(int *)(nativeFrame - 0x18);
    int highSign = *(int *)(nativeFrame - 0x18);
    if (highSign < 0) highCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    int lowSign = *(int *)(nativeFrame - 0x1c);
    highCycles *= *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    float10 lowCycles = (float10)*(int *)(nativeFrame - 0x1c);
    if (lowSign < 0) lowCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    const double *scale = *(const double **)R6GameServiceAddresses::Core__GSecondsPerCycleSlot;
    float10 value = highCycles + lowCycles;
    float *output = *(float **)(nativeFrame + 8);
    value *= *scale;
    value += *(double *)R6GameServiceAddresses::NativeDouble16777216_0;
    value += *(float *)R6GameServiceAddresses::NativeFloat5_0;
    *output = (float)value;
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Select UR6GSServers::ProcessIsLobbyDisconnect native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063a20 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo5(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ProcessIsLobbyDisconnectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c3e8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ProcessIsLobbyDisconnectUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c3f8 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo18[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch46},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch47},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c418 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessIsLobbyDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo18},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c42c : native storage identity retained.
const R6GameServiceNative::FuncInfo ProcessIsLobbyDisconnectExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ProcessIsLobbyDisconnectUnwindMap,
  0x1,
  R6GameServiceAddresses::ProcessIsLobbyDisconnectTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10007d01 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch46(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Genuine native join hook with no work.
// R6GameService.dll @ 10007d40 : virtual void export; ECX/EAX/EDX unchanged, RET4; parameter name inferred.
void __thiscall UR6GSServers::ProcessJoinServer(float *unusedValue)
{
  // Native empty method; the pointer argument is never read.
}

// R6GameService.dll data @ 1007c6a0 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry LogGSVersionUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::LogGSVersionUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007c6b8 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GGSVersionHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch50},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch51},
};
// R6GameService.dll data @ 1007c6d8 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock LogGSVersionTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GGSVersionHandlers},
};
// R6GameService.dll data @ 1007c6ec : selected guard/cleanup records.
const R6GameServiceNative::FuncInfo LogGSVersionExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::LogGSVersionUnwindMap,
  0x1,
  R6GameServiceAddresses::LogGSVersionTryMap,
  0x0,
  0x0,
};

// Logs the fixed GS version report once; exception cleanup owns the list and has no report-buffer action.
// R6GameService.dll @ 10009400 : RET0; sticky publication precedes construction; the report buffer has no unwind action.
__declspec(naked) void __thiscall UR6GSServers::LogGSVersion(void)
{
  byte *nativeFrame;
  uint alreadyLogged,rawEax;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::LogGSVersionSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    mov    eax,ds:0x1008c26c
    push   ebx
    push   esi
    push   edi
    xor    edi,edi
    cmp    eax,edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],edi
    mov    nativeFrame,ebp
    mov    alreadyLogged,eax
  }
  rawEax = alreadyLogged;
  if (alreadyLogged == 0) {
    *(uint *)0x1008c26c = 1;
    void *list = nativeFrame - 0x28;
    using InitializeABI = void * (__thiscall *)(void *);
    ((InitializeABI)R6GameServiceAddresses::InitializeGSModuleVersions)(list);
    *(byte *)(nativeFrame - 4) = 1;
    *(uint *)(nativeFrame - 0x14) = 0;
    using FormatABI = uint (__thiscall *)(void *,char *,uint *);
    rawEax = ((FormatABI)R6GameServiceAddresses::FormatModuleVersionList)
        (list,nullptr,(uint *)(nativeFrame - 0x14));
    uint bytes = *(uint *)(nativeFrame - 0x14);
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    if (bytes == 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextCouldNotFindTheUBIComGSVersionInfo);
    } else {
      void *allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
      byte *table = *(byte **)allocator;
      using AllocateABI = char * (__thiscall *)(void *,uint,const TCHAR *);
      char *report = (*(AllocateABI *)table)
          (allocator,bytes,(const TCHAR *)R6GameServiceAddresses::WideTextGAMESERVICE);
      if (report == nullptr) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (device,(const TCHAR *)R6GameServiceAddresses::WideTextCouldNotAllocateMemoryToRetrieveUBIComGSVersionInfo);
      } else {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (device,(const TCHAR *)R6GameServiceAddresses::WideTextUBIComGSVersionInfo);
        ((FormatABI)R6GameServiceAddresses::FormatModuleVersionList)(list,report,(uint *)(nativeFrame - 0x14));
        const TCHAR *wide;
        // Repeated size calls, wrapping stack-probe alignment and the conversion's raw result retain the native ABI.
        __asm {
          mov    esi,report
          mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__winGetSizeUNICODESlot
          push   esi
          call   ebx
          lea    edx,[eax+eax*1]
          add    esp,0x4
          test   edx,edx
          je     Branch56
          push   esi
          call   ebx
          lea    eax,[eax+eax*1+0x7]
          and    eax,0xfffffff8
          add    eax,0x3
          add    esp,0x4
          and    eax,0xfffffffc
          call   R6GameServiceAddresses::__chkstk
          mov    DWORD PTR [ebp-0x10],esp
          mov    edi,esp
        Branch56:
          push   esi
          call   ebx
          add    esp,0x4
          push   eax
          push   esi
          push   edi
          call   DWORD PTR ds:R6GameServiceAddresses::Core__winToUNICODESlot
          add    esp,0xc
          mov    wide,eax
        }
        device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (device,(const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,wide);
        allocator = **(void ***)R6GameServiceAddresses::Core__GMallocSlot;
        table = *(byte **)allocator;
        rawEax = (*(uint (__thiscall **)(void *,void *))(table + 8))(allocator,report);
      }
    }
    __asm {
      mov    eax,rawEax
      lea    ecx,[ebp-0x28]
      mov    BYTE PTR [ebp-0x4],0x0
      call   R6GameServiceAddresses::ClearModuleVersionList
      mov    rawEax,eax
    }
  }
  __asm {
    mov    eax,rawEax
    lea    esp,[ebp-0x34]
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Throws the caught unsigned-short pointer copied from parent EBP-0x1c to-0x18.
// R6GameService.dll @ 1000954a : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch50(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports LogGSVersion guard context and rethrows the active exception.
// R6GameService.dll @ 1000955e : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch51(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersLogGSVersion
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the completed module/version list at parent EBP-0x28; does not own the ANSI report buffer.
// R6GameService.dll @ 10063b00 : complete native control/access order and raw ABI retained.
__declspec(naked) void LogGSVersionUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    R6GameServiceAddresses::ClearModuleVersionList
  }
}

// Selects the three-state LogGSVersion guard and list-cleanup map.
// R6GameService.dll @ 10063b08 : complete native control/access order and raw ABI retained.
__declspec(naked) void LogGSVersionSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::LogGSVersionExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007c768 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry PlayerIsInIDListUnwindMap[4] = {
  {-1, R6GameServiceAddresses::PlayerIsInIDListUnwind1},
  {0x0, R6GameServiceAddresses::PlayerIsInIDListUnwind2},
  {0x1, 0x0},
  {0x1, 0x0},
};
// R6GameService.dll data @ 1007c788 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GIDPlayerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch52},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch53},
};
// R6GameService.dll data @ 1007c7a8 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock PlayerIsInIDListTryMap[1] = {
  {0x2, 0x2, 0x3, 0x2, R6GameServiceAddresses::GIDPlayerHandlers},
};
// R6GameService.dll data @ 1007c7bc : selected guard/cleanup records.
// R6GameService.dll data @ 1007c768 : native storage identity retained.
const R6GameServiceNative::FuncInfo PlayerIsInIDListExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::PlayerIsInIDListUnwindMap,
  0x1,
  R6GameServiceAddresses::PlayerIsInIDListTryMap,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007c7d8 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry GetGlobalIdFromPlayerIDListUnwindMap[4] = {
  {-1, R6GameServiceAddresses::GetGlobalIdFromPlayerIDListUnwind1},
  {0x0, R6GameServiceAddresses::GetGlobalIdFromPlayerIDListUnwind2},
  {0x1, 0x0},
  {0x1, 0x0},
};
// R6GameService.dll data @ 1007c7f8 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GIDGlobalHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch54},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch55},
};
// R6GameService.dll data @ 1007c818 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock GetGlobalIdFromPlayerIDListTryMap[1] = {
  {0x2, 0x2, 0x3, 0x2, R6GameServiceAddresses::GIDGlobalHandlers},
};
// R6GameService.dll data @ 1007c82c : selected guard/cleanup records.
// R6GameService.dll data @ 1007c7d8 : native storage identity retained.
const R6GameServiceNative::FuncInfo GetGlobalIdFromPlayerIDListExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::GetGlobalIdFromPlayerIDListUnwindMap,
  0x1,
  R6GameServiceAddresses::GetGlobalIdFromPlayerIDListTryMap,
  0x0,
  0x0,
};

// Finds the selected authorization ID/address pair in live 48-byte player records; both inputs are owned values.
// R6GameService.dll @ 10009640 : int(FString,FString,int), thiscall/RET28; ID slots are +c (RS) and +18 (Mod).
int __thiscall UR6GSServers::PlayerIsInIDList(FString candidate,FString recordKey,int selector)
{
  try {
    FArray *records = (FArray *)R6GameServiceAddresses::GServiceArray5;
    uint idOffset = selector != 0 ? 0x18 : 0xc;
    uint index = 0;
    bool found = false;
    while ((int)index < *(int *)((byte *)records + 4) && !found) {
      uint recordOffset = index * 0x30;
      if (candidate == *(FString *)(*(byte **)records + recordOffset + idOffset))
        found = recordKey == *(FString *)(*(byte **)records + recordOffset);
      else
        found = false;
      ++index;
    }
    // Native destroys candidate before recordKey, after fixing the full 0/1 return word.
    return found ? 1 : 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersPlayerIsInIDList);
    throw;
  }
}

// Copies the caught unsigned-short pointer from parent EBP-0x18 to-0x14 and throws it by value.
// R6GameService.dll @ 10009752 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch52(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PlayerIsInIDList guard context and rethrows the active exception.
// R6GameService.dll @ 10009766 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch53(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPlayerIsInIDList
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the second incoming owned FString at parent EBP+0x14.
// R6GameService.dll @ 10063b30 : complete native control/access order and raw ABI retained.
__declspec(naked) void PlayerIsInIDListUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x14]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the first incoming owned FString at parent EBP+0x8.
// R6GameService.dll @ 10063b39 : complete native control/access order and raw ABI retained.
__declspec(naked) void PlayerIsInIDListUnwind2(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the four-state PlayerIsInIDList argument ownership and guard map.
// R6GameService.dll @ 10063b42 : complete native control/access order and raw ABI retained.
__declspec(naked) void PlayerIsInIDListSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PlayerIsInIDListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Copies the first RS authorization-ID match's global ID, or an empty string, into the caller-owned return object.
// R6GameService.dll @ 10009790 : FString(FString), thiscall/RET16 including hidden result; input is callee-owned.
FString __thiscall UR6GSServers::GetGlobalIdFromPlayerIDList(FString authenticationId)
{
  try {
    FArray *records = (FArray *)R6GameServiceAddresses::GServiceArray5;
    uint index = 0;
    while ((int)index < *(int *)((byte *)records + 4)) {
      uint recordOffset = index * 0x30;
      if (*(FString *)(*(byte **)records + recordOffset + 0xc) == authenticationId)
        return *(FString *)(*(byte **)records + recordOffset + 0x24);
      ++index;
    }
    return FString((const TCHAR *)R6GameServiceAddresses::GEmptyWideText);
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersGetGlobalIdFromPlayerIDList);
    throw;
  }
}

// Copies the caught unsigned-short pointer from parent EBP-0x1c to-0x18 and throws it by value.
// R6GameService.dll @ 1000983e : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch54(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports GetGlobalIdFromPlayerIDList context, clears EBX and rethrows the active exception.
// R6GameService.dll @ 10009852 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch55(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersGetGlobalIdFromPlayerIDList
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the incoming owned lookup FString at parent EBP+0xc.
// R6GameService.dll @ 10063b50 : complete native control/access order and raw ABI retained.
__declspec(naked) void GetGlobalIdFromPlayerIDListUnwind2(void)
{
  __asm {
    lea    ecx,[ebp+0xc]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Clears armed result flag bit0 before destroying the current hidden output pointer at parent EBP+8.
// R6GameService.dll @ 10063b59 : complete native control/access order and raw ABI retained.
__declspec(naked) void GetGlobalIdFromPlayerIDListUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    je     Branch66
    and    DWORD PTR [ebp-0x14],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch66:
    ret
  }
}

// Selects the four-state global-ID lookup input/output ownership and guard map.
// R6GameService.dll @ 10063b73 : complete native control/access order and raw ABI retained.
__declspec(naked) void GetGlobalIdFromPlayerIDListSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::GetGlobalIdFromPlayerIDListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007c848 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry PollCallbacksUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007c858 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GMSClientPollHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch56},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch57},
};
// R6GameService.dll data @ 1007c878 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock PollCallbacksTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GMSClientPollHandlers},
};
// R6GameService.dll data @ 1007c88c : selected guard/cleanup records.
// R6GameService.dll data @ 1007c848 : native storage identity retained.
const R6GameServiceNative::FuncInfo PollCallbacksExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::PollCallbacksUnwindMap,
  0x1,
  R6GameServiceAddresses::PollCallbacksTryMap,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007c8a8 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry InitializeMSClientUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::InitializeMSClientUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007c8c0 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GMSClientInitializeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch58},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch59},
};
// R6GameService.dll data @ 1007c8e0 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock InitializeMSClientTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GMSClientInitializeHandlers},
};
// R6GameService.dll data @ 1007c8f4 : selected guard/cleanup records.
// R6GameService.dll data @ 1007c8a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitializeMSClientExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::InitializeMSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::InitializeMSClientTryMap,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007c910 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry execInitializeMSClientUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007c920 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GMSClientExecInitializeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch60},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch61},
};
// R6GameService.dll data @ 1007c940 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock execInitializeMSClientTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GMSClientExecInitializeHandlers},
};
// R6GameService.dll data @ 1007c954 : selected guard/cleanup records.
// R6GameService.dll data @ 1007c910 : native storage identity retained.
const R6GameServiceNative::FuncInfo execInitializeMSClientExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execInitializeMSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::execInitializeMSClientTryMap,
  0x0,
  0x0,
};

// Polls five subsystems in native order, retaining cached first/third inputs and later second/fourth loads.
// R6GameService.dll @ 10009870 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollCallbacks
    (UR6GSServers *this,int msClientAndPingInput,int cdKeyInput,int regServerInput,int gsClientInput)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PollCallbacksSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  const int msAndPing = *reinterpret_cast<int*>(nativeFrame + 8);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  receiver->PollMSClientCallbacks(msAndPing);
  const int registration = *reinterpret_cast<int*>(nativeFrame + 0x10);
  receiver->PollRegServerCallbacks(registration);
  // The CD-key and GS inputs are loaded after preceding callbacks; the MS and registration words stay cached.
  const int cdKey = *reinterpret_cast<int*>(nativeFrame + 0xc);
  receiver->PollClientCDKeyCallbacks(cdKey, msAndPing, registration);
  const int gsClient = *reinterpret_cast<int*>(nativeFrame + 0x14);
  receiver->PollGSClientCallbacks(gsClient);
  receiver->PollPingManager(msAndPing);
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x10
  }
}

// Copies the caught unsigned-short pointer from parent EBP-0x18 to-0x14 and throws it by value.
// R6GameService.dll @ 100098e1 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch56(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PollCallbacks guard context and rethrows the active exception.
// R6GameService.dll @ 100098f5 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch57(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPollCallbacks
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state polling guard, with no local cleanup actions.
// R6GameService.dll @ 10063b80 : complete native control/access order and raw ABI retained.
__declspec(naked) void PollCallbacksSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PollCallbacksExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Loads favorites before initialization checks, optionally bootstraps from an owned local-IP return, and reports failure.
// R6GameService.dll @ 10009920 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::InitializeMSClient(UR6GSServers *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::InitializeMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x1c
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  receiver->InitFavorites();
  if (!*reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized)) {
    // Hidden-result storage is also the outgoing by-value FString. Init owns and destroys that value.
    __asm {
      sub esp,0xc
      mov eax,esp
      mov DWORD PTR [ebp-0x18],esp
      push eax
      mov ecx,esi
      call R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
      mov ecx,esi
      call R6GameServiceAddresses::UR6GSServers_Init
    }
  }
  if (*reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized)) {
    *reinterpret_cast<int*>(0x10091c14) = 1;
  } else {
    FString* message = reinterpret_cast<FString*>(nativeFrame - 0x28);
    FString::FString(message, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextLOGINFAILDEFAULT));
    UR6AbstractGameManager* manager = GR6GameManager;
    *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
    manager->eventGMProcessMsg(*message);
    *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
    FString::~FString(message);
  }
  // Callback processing can replace this global; return the final full word rather than the earlier gate sample.
  const int returnValue = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized);
  __asm {
    mov eax,returnValue
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Copies the caught unsigned-short pointer from parent EBP-0x1c to-0x14 and throws it by value.
// R6GameService.dll @ 100099cb : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch58(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports InitializeMSClient guard context and rethrows the active exception.
// R6GameService.dll @ 100099df : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch59(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitializeMSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the completed LOGIN_FAIL_DEFAULT FString at parent EBP-0x28.
// R6GameService.dll @ 10063b90 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeMSClientUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state initialization guard and failure-message ownership map.
// R6GameService.dll @ 10063b99 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitializeMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitializeMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finishes the script token, invokes initialization, then writes its full return word through the late result pointer.
// R6GameService.dll @ 10009a00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execInitializeMSClient
    (UR6GSServers *this,FFrame *frame,int *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::execInitializeMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // Aliases below refer to the retained native frame; they do not define a new exception layout.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  FFrame* executionStack = *reinterpret_cast<FFrame**>(nativeFrame + 8);
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  byte* next = code + 1;
  code = next;
  const bool debugInfo = *next == 0x42;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (debugInfo) {
    UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
    code = next + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
    natives[0x42](context, executionStack, nullptr);
  }
  const int initialized = receiver->InitializeMSClient();
  int* output = *reinterpret_cast<int**>(nativeFrame + 0xc);
  *output = initialized;
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x8
  }
}

// Copies the caught unsigned-short pointer from parent EBP-0x18 to-0x14 and throws it by value.
// R6GameService.dll @ 10009a6d : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch60(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports execInitializeMSClient guard context and rethrows the active exception.
// R6GameService.dll @ 10009a81 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch61(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecInitializeMSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state script initialization guard, with no local cleanup action.
// R6GameService.dll @ 10063bb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void execInitializeMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execInitializeMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Read the mapped index before readiness gates, then publish refresh state and request the original input-index record.
// R6GameService.dll @ 10009dd0 : native effects and guarded lifetime order represented in C++.
void __thiscall UR6GSServers::RefreshOneServer(int serverIndex)
{
  const uint inputIndex = static_cast<uint>(serverIndex);
  byte* list = reinterpret_cast<byte*>(this);
  uint* display = *reinterpret_cast<uint**>(list + 0x80);
  const int mappedIndex = display[inputIndex]; // This unchecked lookup precedes all readiness gates.
  const int enabled = *reinterpret_cast<int*>(0x10091e6c);
  try {
    if (enabled && !*reinterpret_cast<int*>(0x10091d38) && !*reinterpret_cast<int*>(0x10091d30)) {
      *reinterpret_cast<float*>(R6GameServiceAddresses::NativeFloat0_0) = (float)ReadCycleTimeSeconds();
      *reinterpret_cast<int*>(0x10091bf8) = 0;
      *reinterpret_cast<int*>(0x10091d30) = 1;
      byte* records = *reinterpret_cast<byte**>(list + 0x5c);
      byte* record = records + inputIndex * 0xdcU;
      *reinterpret_cast<int*>(list + 0x44) = mappedIndex;
      const uint first = *reinterpret_cast<uint*>(record);
      const uint second = *reinterpret_cast<uint*>(record + 4);
      // Native uses the original input index for the request, although +0x44 stores its mapped display index.
      ForwardMSClientOperation2(second, first);
      if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging))
        GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientRefreshGameServers));
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersRefreshOneServer);
    throw;
  }
}

// Select UR6GSServers::RefreshOneServer native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063bc0 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo6(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RefreshOneServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c970 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RefreshOneServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c980 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo22[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch62},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch63},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c980 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RefreshOneServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo22},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c970 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RefreshOneServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_RefreshOneServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RefreshOneServerTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10009e8e : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch62(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Decode an initialized DWORD index, finish VM parameters and refresh that server without writing a script result.
// R6GameService.dll @ 10009ec0 : native effects and guarded lifetime order represented in C++.
void __thiscall UR6GSServers::execRefreshOneServer(FFrame &Stack,void *const Result)
{
  FFrame* executionStack = &Stack;
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  int index = 0;
  byte* operandCode = code;
  const byte opcode = *operandCode;
  code = operandCode + 1;
  using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
  ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
  UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
  try {
    natives[opcode](context, executionStack, &index);
    byte* next = code + 1;
    code = next;
    if (*next == 0x42) {
      context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
      code = next + 1;
      natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
      natives[0x42](context, executionStack, nullptr);
    }
    RefreshOneServer(index);
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecNativeRefreshServer);
    throw;
  }
}

// Select exported UR6GSServers::execRefreshOneServer native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063bd0 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo7(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execRefreshOneServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c9d0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execRefreshOneServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c9e0 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo26[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch64},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch65},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c9e0 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execRefreshOneServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo26},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c9d0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execRefreshOneServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execRefreshOneServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execRefreshOneServerTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10009f50 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch64(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Decode current VM string/two integers, then update match field through alternate dispatcher or GS COM slot3c.
// Keep per-operand current VM object/table, delayed scratch initialization and caller-slot BSTR publication.
// State2 includes normal captured-BSTR release; unwind frees CURRENT caller-slot BSTR, then FString. Result untouched.
// R6GameService.dll @ 10009f90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeSetMatchResult(UR6GSServers *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectMatchResultLifetime
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    xor    ebx,ebx
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    esi,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x2c]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR [eax+edx*4]
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ebp-0x18],ebx
    movzx  edx,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x18]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [ebp-0x14],ebx
    movzx  edx,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x14]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne    Branch73
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   ebx
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch73:
    mov    cl,BYTE PTR [edi+0x2c]
    mov    al,0x4
    test   al,cl
    je    Branch79
    test   BYTE PTR [edi+0x194],al
    lea    ecx,[ebp-0x2c]
    je    Branch78
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    cmp    eax,ebx
    je    Branch74
    push   0xffffffff
    push   eax
    call   R6GameServiceAddresses::ConvertAnsiToBstr
    mov    edi,eax
    add    esp,0x8
    cmp    edi,ebx
    mov    DWORD PTR [ebp+0x8],edi
    jne    Branch75
    push   0x8007000e
    call   R6GameServiceAddresses::ThrowAtlStatus
  Branch74:
    xor    edi,edi
    mov    DWORD PTR [ebp+0x8],edi
  Branch75:
    mov    edx,DWORD PTR [ebp-0x14]
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   edx
    mov    edx,DWORD PTR [ebp-0x18]
    push   edx
    push   edi
    push   eax
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR [ecx+0x3c]
    mov    esi,eax
    cmp    esi,ebx
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    jge    Branch76
    cmp    eax,ebx
    je    Branch77
    lea    ecx,[ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR [ebp-0x18]
    and    esi,0x8000ffff
    push   esi
    push   ecx
    push   edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientERRORSetMatchResultSDDReturnedX
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x18
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysFreeStringSlot
    jmp    Branch80
  Branch76:
    cmp    eax,ebx
    je    Branch77
    lea    ecx,[ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edx,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [ebp-0x18]
    push   edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   ecx
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientSetMatchResultSDDReturnedSuccess
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch77:
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysFreeStringSlot
    jmp    Branch80
  Branch78:
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR [ebp-0x18]
    add    esp,0x4
    push   ecx
    push   edx
    push   eax
    call   R6GameServiceAddresses::DispatchSingletonSubobject3f1a0
    movzx  esi,al
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je    Branch80
    lea    ecx,[ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR [ebp-0x18]
    push   esi
    push   ecx
    push   edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientSetMatchResultSDDReturnedD
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x18
    jmp    Branch80
  Branch79:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je    Branch80
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextExecNativeSetMatchResultNotSubmitingResults
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch80:
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000a1bc : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch66(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x1c]
    push   edx
    mov    DWORD PTR [ebp-0x1c],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Submits the current match result and records whether the reply must be awaited.
// Submit only for RavenShield: alternate adapter uses current IDs; GS interface failure clears bit8, success waits or handles reply.
// Preserve full signed status/mask, cached success logger/current gates, late globals/flags and existing no-action catch scope.
// R6GameService.dll @ 1000a1f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::SubmitMatchResult(UR6GSServers *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectManagerParentEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:R6GameServiceAddresses::Engine__GModMgrSlot
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ecx,DWORD PTR [eax]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    test   eax,eax
    je    Branch83
    test   BYTE PTR [edi+0x194],0x4
    je    Branch87
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceBstr
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   0x0
    push   eax
    call   DWORD PTR [ecx+0x38]
    mov    esi,eax
    test   esi,esi
    jl    Branch86
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je    Branch81
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientSubmitMatchResultReturnedSuccess
    push   ecx
    call   ebx
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x8
  Branch81:
    test   esi,0x8000ffff
    je    Branch84
    test   eax,eax
    je    Branch82
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextButWeNeedToWaitForMBWaitSubmitMatchReplyBeforeCallingProcessSubmitMatchR
    push   eax
    call   ebx
    add    esp,0x8
  Branch82:
    or     DWORD PTR [edi+0x2c],0x8
  Branch83:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch84:
    test   eax,eax
    je    Branch85
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNoNeedToWaitForMBWaitSubmitMatchReplyCallingProcessSubmitMatchResultRepl
    push   edx
    call   ebx
    add    esp,0x8
  Branch85:
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_ProcessSubmitMatchResultReply
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch86:
    and    DWORD PTR [edi+0x2c],0xfffffff7
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch83
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    and    esi,0x8000ffff
    push   esi
    push   R6GameServiceAddresses::WideTextGSClientSubmitMatchResultReturnedFailureCodeX
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch87:
    mov    edx,DWORD PTR ds:0x10091d44
    mov    eax,ds:0x10091e4c
    push   edx
    push   eax
    call   R6GameServiceAddresses::DispatchSingletonSubobject3f1b0
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    movzx  eax,al
    je    Branch83
    mov    ecx,DWORD PTR ds:0x10091d44
    mov    edx,DWORD PTR ds:0x10091e4c
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    push   ecx
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextMSClientSubmitMatchResultDDReturnedD
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    add    esp,0x14
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Select exact manager parent two-state/no-action unwind and typed/context catch records.
// R6GameService.dll @ 10063c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectManagerParentEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_SubmitMatchResultExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007caa0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_SubmitMatchResultUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cab0 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGManagerParentEH5[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch68},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch69},
};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cab0 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_SubmitMatchResultTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGManagerParentEH5},
};

// Literal manager parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007caa0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_SubmitMatchResultExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_SubmitMatchResultUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_SubmitMatchResultTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000a373 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch68(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Retries master-server login after the supplied deadline and advances its failure timer.
// State2 clears only; state3 clears state and publishes clock+5 to CURRENT deadline. Idle error retries only past ordered deadline.
// Preserve full state/status, x87 unordered/equal/less wait, current initialized/logging/pointer and partial effects.
// R6GameService.dll @ 1000a8c0 : C++ login/retry states with live deadline argument and ordered x87 comparison.
__declspec(naked) void __thiscall UR6GSServers::ProcessLoginMasterSrv(int loginResultCode,float *retryAtSeconds)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  uint state;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo8
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10091c0c
    push   ebx
    push   esi
    push   edi
    xor    edi,edi
    sub    eax,edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],edi
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    state,eax
  }
  using InitializeABI = void (__thiscall *)(UR6GSServers *);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  const TCHAR *diagnostic = nullptr;
  if (state == 3) {
    *(uint *)0x10091c0c = 0;
    float10 next = ReadCycleTimeSeconds();
    next += *(float *)R6GameServiceAddresses::NativeFloat5_0;
    float *deadline = *(float **)(nativeFrame + 0xc);
    *deadline = (float)next;
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextFailedToLogInToUbiCom;
  } else if (state == 2) {
    uint predecessor = *(uint *)(nativeFrame - 0xc);
    *(uint *)0x10091c0c = 0;
    __asm {
      mov    ecx,predecessor
      pop    edi
      pop    esi
      mov    DWORD PTR fs:0x0,ecx
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret    0x8
    }
  } else if (state == 0) {
    if (*(uint *)(nativeFrame + 8) != 0 && *(uint *)0x10091e64 == 0) {
      float10 now = ReadCycleTimeSeconds();
      float *deadline = *(float **)(nativeFrame + 0xc);
      if (now > (float10)*deadline) {
        ((InitializeABI)R6GameServiceAddresses::UR6GSServers_InitializeMSClient)(receiver);
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextRetry;
      }
    }
  }
  if (diagnostic != nullptr) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)(device,diagnostic);
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Select UR6GSServers::ProcessLoginMasterSrv native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063c40 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6GSServers_SelectParentExceptionInfo8(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessLoginMasterSrvExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cb78 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessLoginMasterSrvUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cb88 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGParentExceptionInfo30[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch70},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch71},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cba8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessLoginMasterSrvTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo30},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cbbc : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessLoginMasterSrvExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessLoginMasterSrvUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessLoginMasterSrvTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000a98f : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch70(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Runs Internet registration, initializes key support, validates controllers, then pumps authorization and services.
// R6GameService.dll @ 1000a9c0 : virtual void(game*,level*), RET8; field and cache names below are inferred.
void __thiscall UR6GSServers::MasterServerManager(AR6AbstractGameInfo *gameInfo,ALevelInfo *levelInfo)
{
  // The native flag read precedes entry into the guarded region.
  const bool internetServer = (*(byte *)((byte *)gameInfo + 0x4e4) & 0x10) != 0;
  try {
    if (internetServer)
      ProcessInternetSrv(gameInfo,levelInfo);
    uint &cachedInitialization = *(uint *)0x100933c4;
    if (cachedInitialization == 0) {
      using InitializeKeyABI = uint (__thiscall *)(UR6GSServers *);
      cachedInitialization = ((InitializeKeyABI)(*(uint **)this)[0x68 / 4])(this);
    }
    AController *controller = *(AController **)((byte *)levelInfo + 0x4d4);
    UClass *requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
    while (controller != 0) {
      UClass *candidateClass = *(UClass **)((byte *)controller + 0x24);
      while (candidateClass != 0 && candidateClass != requiredClass)
        candidateClass = *(UClass **)((byte *)candidateClass + 0x2c);
      // A null imported class accepts the chain after reaching its end, just as the native ancestry walk does.
      if (candidateClass == requiredClass) {
        ProcessPC_CDKeyRequest(gameInfo,levelInfo,(APlayerController *)controller,0);
        using IsRavenShieldABI = uint (__thiscall *)(void *);
        void **modManagerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
        uint isRavenShield = (*(IsRavenShieldABI *)R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot)
            (*modManagerSlot);
        if (isRavenShield == 0)
          ProcessPC_CDKeyRequest(gameInfo,levelInfo,(APlayerController *)controller,1);
        requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
      }
      controller = *(AController **)((byte *)controller + 0x3dc);
    }
    ProcessAuthIdRequest(*(AController **)((byte *)levelInfo + 0x4d4));
    using ServiceManagerABI = void (__thiscall *)(UR6GSServers *,int,int,int,int);
    ((ServiceManagerABI)(*(uint **)this)[0x98 / 4])(this,0,1,1,0);
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersMasterServerManager);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000aabd : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch72(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::MasterServerManager context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000aad1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch73(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersMasterServerManager
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select master-server manager guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063c50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_MasterServerManagerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_MasterServerManagerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native master-server manager unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007cbd8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_MasterServerManagerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native master-server manager handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007cbe8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GMasterServerManagerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch72},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch73},
};

// Native master-server manager try record; addresses and states are literal.
// R6GameService.dll data @ 1007cbe8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_MasterServerManagerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GMasterServerManagerHandlers},
};

// Native master-server manager info record; addresses and states are literal.
// R6GameService.dll data @ 1007cbd8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_MasterServerManagerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_MasterServerManagerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_MasterServerManagerTryMap,
  0x0,
  0x0,
};

// Reuses a selected ID/address match, reuses a mod global-ID/address match, or appends a zeroed 48-byte record.
// R6GameService.dll @ 1000ab00 : void(FString,FString,FString,int), thiscall/RET40; input copies are callee-owned.
void __thiscall UR6GSServers::AddPlayerToIDList(FString candidate,FString recordKey,FString globalId,int idSlotSelector)
{
  try {
    int lookupSelector = idSlotSelector;
    // Outgoing key then candidate copies transfer ownership to PlayerIsInIDList under the native x86 ABI.
    if (PlayerIsInIDList(candidate,recordKey,lookupSelector) == 0) {
      FArray *records = (FArray *)R6GameServiceAddresses::GServiceArray5;
      uint recordIndex = 0;
      bool reused = false;
      if (lookupSelector != 0) {
        uint index = 0;
        while ((int)index < *(int *)((byte *)records + 4) && !reused) {
          uint recordOffset = index * 0x30;
          if (globalId == *(FString *)(*(byte **)records + recordOffset + 0x24) &&
              recordKey == *(FString *)(*(byte **)records + recordOffset)) {
            recordIndex = index;
            reused = true;
          }
          ++index;
        }
      }
      using AssignABI = FStringNoInit *(__thiscall *)(FStringNoInit *,const FString *);
      if (!reused) {
        using AddZeroedABI = int (__thiscall *)(FArray *,int,int);
        recordIndex = (uint)(*(AddZeroedABI *)R6GameServiceAddresses::Core_FArray_AddZeroedSlot)(records,0x30,1);
        uint recordOffset = recordIndex * 0x30;
        (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
            ((FStringNoInit *)(*(byte **)records + recordOffset),&recordKey);
        (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
            ((FStringNoInit *)(*(byte **)records + recordOffset + 0x24),&globalId);
      }
      // Only the reuse gate used the saved selector; the final slot selection reads the current argument again.
      uint idOffset = idSlotSelector != 0 ? 0x18 : 0xc;
      (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
          ((FStringNoInit *)(*(byte **)records + recordIndex * 0x30 + idOffset),&candidate);
    }
    // Native input destruction order is candidate, recordKey, globalId, with no rollback of array writes.
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersAddPlayerToIDList);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000ac76 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch74(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::AddPlayerToIDList context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000ac8a : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch75(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersAddPlayerToIDList
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the third owned input string at inherited parent EBP+0x20.
// R6GameService.dll @ 10063c60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_AddPlayerToIDListUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x20]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the second owned input string at inherited parent EBP+0x14.
// R6GameService.dll @ 10063c69 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_AddPlayerToIDListUnwind2(void)
{
  __asm {
    lea    ecx,[ebp+0x14]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the first owned input string at inherited parent EBP+0x8.
// R6GameService.dll @ 10063c72 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_AddPlayerToIDListUnwind3(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed outgoing key copy through the saved pointer at inherited EBP-0x18.
// R6GameService.dll @ 10063c7b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_AddPlayerToIDListUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select player-ID insertion guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063c84 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_AddPlayerToIDListSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native player-ID insertion unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007cc38 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_AddPlayerToIDListUnwindMap[6] = {
  {-1, R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListUnwind1},
  {0x0, R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListUnwind2},
  {0x1, R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListUnwind3},
  {0x2, 0x0},
  {0x3, R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListUnwind5},
  {0x2, 0x0},
};

// Native player-ID insertion handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007cc68 : native storage identity retained.
const R6GameServiceNative::CatchHandler GAddPlayerToIDListHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch74},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch75},
};

// Native player-ID insertion try record; addresses and states are literal.
// R6GameService.dll data @ 1007cc68 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_AddPlayerToIDListTryMap[1] = {
  {0x3, 0x4, 0x5, 0x2, R6GameServiceAddresses::GAddPlayerToIDListHandlers},
};

// Native player-ID insertion info record; addresses and states are literal.
// R6GameService.dll data @ 1007cc38 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_AddPlayerToIDListExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListTryMap,
  0x0,
  0x0,
};

// Consume at most two incoming servers using captured signed queue count; return initial(count>0), RET0.
// Timestamp uses unsigned RDTSC halves, inherited x87 precision/rounding and current scale, then float store.
// Refresh mode matches captured input IDs to current server records; otherwise append index/zeroed dc-byte entry.
// Preserve cached destinations across ANSI conversion, late queue/data/allocator reloads, flag masks and favorites.
// Payload reads have individual signed-status gates, reused scratch/capacity and unconditional port formatting.
// Free current payload before assertions/current queue Remove; no rollback. State1 protects only game-type FString.
// Common normal epilogue b3bb follows private catch entries in the binary; those catches remain canonical below.
// R6GameService.dll @ 1000ad20 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::ReceiveServer(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectReceiveServerEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x338
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  byte* list = reinterpret_cast<byte*>(receiver);
  FArray* pending = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray3);
  const int queued = *reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  uint& bytes = *reinterpret_cast<uint*>(nativeFrame - 0x1c);
  bytes = 0x100;
  *reinterpret_cast<int*>(nativeFrame - 0x2c) = queued;
  *reinterpret_cast<int*>(nativeFrame - 0x34) = queued > 0;
  if (queued > 0) {
    // Hardware clock input and unsigned high/low conversion stay in the native x87 precision/order.
    __asm {
    rdtsc
    mov    DWORD PTR [ebp-0x24],eax
    mov    DWORD PTR [ebp-0x20],edx
    fild   DWORD PTR [ebp-0x20]
    mov    eax,DWORD PTR [ebp-0x20]
    test   eax,eax
    jge    Branch109
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch109:
    mov    edx,DWORD PTR [ebp-0x24]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   edx,edx
    fild   DWORD PTR [ebp-0x24]
    jge    Branch110
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch110:
    mov    eax,ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    fmul   QWORD PTR [eax]
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    fstp   DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
    }
  }
  int& consumed = *reinterpret_cast<int*>(nativeFrame - 0x24);
  consumed = 0;
  auto incoming = [&]() { return *reinterpret_cast<byte**>(pending); };
  auto serverData = [&]() { return *reinterpret_cast<byte**>(list + 0x5c); };
  auto store = [&]() { return *reinterpret_cast<void**>(R6GameServiceAddresses::GServerReplySerializedStore); };
  while (consumed < 2 && consumed < *reinterpret_cast<int*>(nativeFrame - 0x2c)) {
    const int refreshingOne = *reinterpret_cast<int*>(0x10091d30);
    int& selected = *reinterpret_cast<int*>(nativeFrame - 0x28);
    selected = *reinterpret_cast<int*>(list + 0x60);
    int& found = *reinterpret_cast<int*>(nativeFrame - 0x20);
    found = 0;
    byte* reply;
    if (refreshingOne) {
      reply = incoming(); // Kept through the match walk; record storage/count stay live.
      for (int i = 0; i < *reinterpret_cast<int*>(list + 0x60) && !found; ++i) {
        byte* row = serverData() + static_cast<uint>(i) * 0xdcU;
        if (*reinterpret_cast<uint*>(row + 4) == *reinterpret_cast<uint*>(reply + 0x10c) &&
            *reinterpret_cast<uint*>(row) == *reinterpret_cast<uint*>(reply + 0x108)) {
          const int stillRefreshing = *reinterpret_cast<int*>(0x10091d30);
          found = 1;
          selected = i;
          if (stillRefreshing && i == *reinterpret_cast<int*>(list + 0x44))
            *reinterpret_cast<int*>(0x10091d30) = 0;
        }
      }
    }
    if (!found) {
      FArray* display = reinterpret_cast<FArray*>(list + 0x80);
      const int displayIndex = display->AddZeroed(4, 1);
      uint* displayData = *reinterpret_cast<uint**>(display);
      displayData[displayIndex] = displayIndex;
      selected = reinterpret_cast<FArray*>(list + 0x5c)->AddZeroed(0xdc, 1);
      reply = incoming();
    }
    // Cache the byte offset, but reload the server array after every provider/assignment callback.
    const uint rowOffset = static_cast<uint>(selected) * 0xdcU;
    uint word = *reinterpret_cast<uint*>(reply + 0x108);
    *reinterpret_cast<uint*>(serverData() + rowOffset) = word;
    reply = incoming();
    byte* rows = serverData();
    word = *reinterpret_cast<uint*>(reply + 0x10c);
    *reinterpret_cast<uint*>(rows + rowOffset + 4) = word;
    auto assignIncomingText = [&](uint sourceOffset, uint destinationOffset) {
      byte* currentReply = incoming();
      byte* destination = serverData() + rowOffset;
      const TCHAR* text = appFromAnsi(reinterpret_cast<char*>(currentReply + sourceOffset));
      *reinterpret_cast<FStringNoInit*>(destination + destinationOffset) = text;
    };
    assignIncomingText(0x634, 0x10);
    assignIncomingText(0x734, 0x1c);
    *reinterpret_cast<uint*>(serverData() + rowOffset + 0x28) &= 0xfffffffe;
    *reinterpret_cast<uint*>(serverData() + rowOffset + 0x28) |= 2;
    *reinterpret_cast<int*>(serverData() + rowOffset + 0xc) = 1000;
    assignIncomingText(8, 0x5c);
    assignIncomingText(0x41c, 0xac);
    FString* version = reinterpret_cast<FString*>(serverData() + rowOffset + 0xac);
    const int sameVersion = *version == *reinterpret_cast<FString*>(list + 0x168);
    uint* versionFlags = reinterpret_cast<uint*>(serverData() + rowOffset + 0x28);
    *versionFlags ^= (*versionFlags ^ (static_cast<uint>(sameVersion) << 3)) & 8;
    reply = incoming();
    rows = serverData();
    word = *reinterpret_cast<uint*>(reply + 0x628);
    *reinterpret_cast<uint*>(rows + rowOffset + 0x78) = word;
    FArray* pingQueue = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray4);
    const int pingIndex = pingQueue->Add(1, 4);
    uint* pingData = *reinterpret_cast<uint**>(pingQueue);
    pingData[pingIndex] = *reinterpret_cast<uint*>(nativeFrame - 0x28);
    reply = incoming();
    if (*reinterpret_cast<int*>(reply + 0x620) > 0) {
      LoadSerializedByteStore(store(), *reinterpret_cast<byte**>(reply + 0x61c));
      char* textBuffer = reinterpret_cast<char*>(nativeFrame - 0x144);
      uint& value = *reinterpret_cast<uint*>(nativeFrame - 0x18); // Deliberately retains stale/uninitialized data.
      byte& flag = *reinterpret_cast<byte*>(nativeFrame - 0x11);
      auto readText = [&](uint key, uint offset, bool clearOnFailure) {
        bytes = 0x100;
        const int status = static_cast<int>(ReadStoredBytes(store(), key, textBuffer, &bytes));
        if (status >= 0) {
          byte* destination = serverData() + rowOffset;
          const TCHAR* text = appFromAnsi(textBuffer);
          *reinterpret_cast<FStringNoInit*>(destination + offset) = text;
        } else if (clearOnFailure) {
          *reinterpret_cast<FStringNoInit*>(serverData() + rowOffset + offset) =
              reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::GEmptyWideText);
        }
      };
      auto readWord = [&](uint key, uint offset) {
        if (static_cast<int>(ReadStoredWord(store(), key, &value)) >= 0)
          *reinterpret_cast<uint*>(serverData() + rowOffset + offset) = value;
      };
      auto readFlag = [&](uint key, uint offset, uint shift, uint mask) {
        if (static_cast<int>(ReadStoredWord(store(), key, &flag)) >= 0) {
          uint* bits = reinterpret_cast<uint*>(serverData() + rowOffset + offset);
          *bits ^= (*bits ^ (static_cast<uint>(flag) << shift)) & mask;
        }
      };
      readText(0xfd, 0x68, true);
      readText(0x64, 0x94, false);
      readWord(0x6d, 0x74);
      readFlag(0x66, 0x38, 0, 1);
      readFlag(0x67, 0x38, 1, 2);
      readWord(0x69, 0x3c);
      readFlag(0x6a, 0x4c, 2, 4);
      readText(0x65, 0x88, false);
      // Native reuses the byte count from selector 0x65 for this read rather than resetting it.
      if (static_cast<int>(ReadStoredBytes(store(), 0x68, &value, &bytes)) >= 0) {
        uint* bits = reinterpret_cast<uint*>(serverData() + rowOffset + 0x4c);
        *bits ^= (*bits ^ (static_cast<uint>(value == 0) << 6)) & 0x40;
      }
      readWord(0x6b, 0x58);
      TCHAR* portText = reinterpret_cast<TCHAR*>(nativeFrame - 0x344);
      // This uses value even when selector 0x6b failed. Formatting success, not the selector status, gates appends.
      if (appSprintf(portText, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextI), value) >= 0) {
        *reinterpret_cast<FString*>(serverData() + rowOffset + 0x10) += portText;
        *reinterpret_cast<FString*>(serverData() + rowOffset + 0x1c) += portText;
      }
      if (static_cast<int>(ReadStoredWord(store(), 0x6c, &value)) >= 0) {
        FString* gameType = reinterpret_cast<FString*>(nativeFrame - 0x44);
        using GameTypeCall = FString* (__thiscall *)(UR6ModMgr*, FString*, uint);
        GameTypeCall getName = *reinterpret_cast<GameTypeCall*>(
            R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeNameSlot);
        FString* returned = getName(GModMgr, gameType, value);
        byte* destination = serverData() + rowOffset;
        *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
        *reinterpret_cast<FStringNoInit*>(destination + 0x7c) = *returned;
        *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
        FString::~FString(gameType);
      }
      readWord(0xfc, 8);
      readFlag(0xff, 0x4c, 10, 0x400);
    }
    *reinterpret_cast<uint*>(serverData() + rowOffset + 0x28) &= 0xfffffffb;
    for (int favorite = 0; favorite < *reinterpret_cast<int*>(list + 0x54); ++favorite) {
      FString* favorites = *reinterpret_cast<FString**>(list + 0x50);
      FString* address = reinterpret_cast<FString*>(serverData() + rowOffset + 0x10);
      if (*address == favorites[favorite])
        *reinterpret_cast<uint*>(serverData() + rowOffset + 0x28) |= 4;
    }
    FMalloc* allocator = GMalloc; // Capture the allocator before the current pending-record pointer is read.
    reply = incoming();
    allocator->Free(*reinterpret_cast<void**>(reply + 0x61c));
    if (*reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4) < 0)
      appFailAssert(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexArrayNum),
          reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x202);
    if (*reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4) < 1)
      appFailAssert(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexCountArrayNum),
          reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x203);
    pending->Remove(0, 1, 0x838); // Queue storage is current after frees/assert callbacks; payload already freed.
    ++consumed;
  }
  const int returnValue = *reinterpret_cast<int*>(nativeFrame - 0x34);
  __asm {
    mov eax,returnValue
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000b38b : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch76(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x38]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x30]
    push   ecx
    mov    DWORD PTR [ebp-0x30],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ReceiveServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000b39f : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch77(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersReceiveServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy parent EBP-44 game-type FString during state1 unwind; current destructor import, no own guard.
// R6GameService.dll @ 10063c90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReceiveServerUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x44]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select ReceiveServer unwind/typed-pointer/context-catch metadata and tail-enter CRT dispatch.
// R6GameService.dll @ 10063c99 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectReceiveServerEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReceiveServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native ReceiveServer unwind record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ccb8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReceiveServerUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::ReceiveServerUnwind2},
  {-1, 0x0},
};

// Native ReceiveServer handlers record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ccd0 : native storage identity retained.
const R6GameServiceNative::CatchHandler GReceiveServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -56,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch76},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch77},
};

// Native ReceiveServer try record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ccd0 : native storage identity retained.
const R6GameServiceNative::TryBlock ReceiveServerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GReceiveServerHandlers},
};

// Native ReceiveServer info record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ccb8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReceiveServerExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ReceiveServerUnwindMap,
  0x1,
  R6GameServiceAddresses::ReceiveServerTryMap,
  0x0,
  0x0,
};

// Try current router records, ensure serialized storage after each attempt and install MS callbacks.
// Nonvirtual void(void)/RET0. Index EAX is sampled before state0; signed attempt/count test precedes
// success test. Record pointer is captured early; its port WORD reads after three borrowed conversions.
// Global9291c/password share converter cached after first dereference; user-ID conversion reloads the import.
// One debug gate selects five cached-Logf diagnostics with current data/devices and full DWORD port.
// Rotate current index before optional36-byte container creation; state1 frees only the saved outer block.
// Partial constructor allocations/published global effects are retained. Success sets initialized1;
// Failure sets request3 and clears91e68. Callback installation runs on every normal path, with no rollback.
// R6GameService.dll @ 1000b640 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::InitMSClient(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_InitMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  int routerIndex = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex);
  *reinterpret_cast<UR6GSServers**>(nativeFrame - 0x14) = receiver;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  uint& attempts = *reinterpret_cast<uint*>(nativeFrame - 0x18);
  attempts = 0;
  uint connected = 0;
  auto currentOwner = [&]() { return *reinterpret_cast<byte**>(nativeFrame - 0x14); };
  while (static_cast<int>(attempts) < *reinterpret_cast<int*>(R6GameServiceAddresses::GServiceArray1 + 4)) {
    if (connected) break;
    byte* routerData = *reinterpret_cast<byte**>(R6GameServiceAddresses::GServiceArray1);
    byte* router = routerData + static_cast<uint>(routerIndex) * 0x108U;
    const TCHAR* version = **reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString2);
    using ToAnsiCall = char* (__cdecl *)(const TCHAR*);
    ToAnsiCall toAnsi = *reinterpret_cast<ToAnsiCall*>(R6GameServiceAddresses::Core__appToAnsiSlot);
    char* versionAnsi = toAnsi(version);
    FString* password = reinterpret_cast<FString*>(currentOwner() + 0x1dc);
    const TCHAR* passwordText = **password;
    char* passwordAnsi = toAnsi(passwordText);
    const TCHAR* userText = **reinterpret_cast<FString*>(currentOwner() + 0x34);
    char* userAnsi = appToAnsi(userText); // This conversion reloads the import; the first two share the cached target.
    const uint port = *reinterpret_cast<ushort*>(router + 0x100);
    connected = static_cast<byte>(CreateMSClientSingleton(reinterpret_cast<char*>(router), port,
        userAnsi, passwordAnsi, versionAnsi));
    if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
      const int currentIndex = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex);
      FOutputDevice* logger = GLog;
      using LogCall = void (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
      LogCall log = *reinterpret_cast<LogCall*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
      log(logger, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitializeGIRouterIndexI),
          currentIndex);
      routerIndex = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex);
      routerData = *reinterpret_cast<byte**>(R6GameServiceAddresses::GServiceArray1);
      const TCHAR* routerName = appFromAnsi(reinterpret_cast<char*>(routerData + static_cast<uint>(routerIndex) * 0x108U));
      log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitializeSzNameS), routerName);
      routerIndex = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex);
      routerData = *reinterpret_cast<byte**>(R6GameServiceAddresses::GServiceArray1);
      const uint diagnosticPort = *reinterpret_cast<uint*>(routerData + static_cast<uint>(routerIndex) * 0x108U + 0x100);
      log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitializeIPortI), diagnosticPort);
      userText = **reinterpret_cast<FString*>(currentOwner() + 0x34);
      log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitializeMSzUserIDS), userText);
      passwordText = **reinterpret_cast<FString*>(currentOwner() + 0x1dc);
      log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitializeMSzPasswordS), passwordText);
    }
    uint advanced = *reinterpret_cast<uint*>(R6GameServiceAddresses::GMSRouterIndex) + 1U;
    const int count = *reinterpret_cast<int*>(R6GameServiceAddresses::GServiceArray1 + 4);
    *reinterpret_cast<uint*>(R6GameServiceAddresses::GMSRouterIndex) = advanced;
    if (static_cast<int>(advanced) >= count) {
      advanced = 0;
      *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex) = 0;
    }
    routerIndex = static_cast<int>(advanced);
    if (!*reinterpret_cast<void**>(R6GameServiceAddresses::GServerReplySerializedStore)) {
      void* block = GMalloc->Malloc(0x24, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextNew));
      *reinterpret_cast<void**>(nativeFrame - 0x20) = block;
      *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
      void* constructed = block ? InitializeSerializedByteStore(reinterpret_cast<uint*>(block)) : nullptr;
      *reinterpret_cast<void**>(R6GameServiceAddresses::GServerReplySerializedStore) = constructed;
      routerIndex = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex);
      *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
    }
    ++attempts;
  }
  const int logging = *reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging);
  if (connected) {
    *reinterpret_cast<int*>(0x10091e64) = 1;
    if (logging) GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientInitialized));
  } else {
    *reinterpret_cast<int*>(0x10091c14) = 3;
    *reinterpret_cast<int*>(0x10091e68) = 0;
    if (logging) GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSClientCouldNotConnectToServer));
  }
  RegisterMSClientCallbacks(); // Runs after either normal outcome, retaining already-published globals.
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000b896 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch78(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x24]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x1c]
    push   edx
    mov    DWORD PTR [ebp-0x1c],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitMSClient context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000b8aa : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch79(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitMSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Free only the saved outer container allocation through the current global allocator, then return.
// R6GameService.dll @ 10063cb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_InitMSClientUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Select MS initialization guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063cbb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_InitMSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_InitMSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native MS initialization unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007cd8c : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_InitMSClientUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_InitMSClientUnwind2},
  {-1, 0x0},
};

// Native MS initialization handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007cda4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GInitMSClientHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -36,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch78},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch79},
};

// Native MS initialization try record; addresses and states are literal.
// R6GameService.dll data @ 1007cda4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitMSClientTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GInitMSClientHandlers},
};

// Native MS initialization info record; addresses and states are literal.
// R6GameService.dll data @ 1007cd8c : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_InitMSClientExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_InitMSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_InitMSClientTryMap,
  0x0,
  0x0,
};

// Match/apply one queued alternate record; return1 once matched positive-length payload starts, else0, RET0.
// Stored scalar/flag reads ignore status and retain stale scratch on failure; current arrays/fields reload literally.
// Rebuild map/type pairs18 and player records2c with up to16 reads each; only first text gates each loop.
// Clear buffers for later strings, but retain stale numeric scratch; capture/reload row pointers at native sites.
// State1 protects game-type result; state2 destroys first player string if trailing-string destruction fails.
// Other destruction/append/free/dequeue effects remain partial; no whole-record rollback or extra read validation.
// R6GameService.dll @ 1000b8d0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::ReceiveAltInfo(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectReceiveAltInfoEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x138
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  byte* list = reinterpret_cast<byte*>(receiver);
  FArray* pending = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray2);
  const int queued = *reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  uint& bytes = *reinterpret_cast<uint*>(nativeFrame - 0x20);
  bytes = 0x100;
  *reinterpret_cast<int*>(nativeFrame - 0x30) = 0;
  if (queued > 0) {
    byte* reply = *reinterpret_cast<byte**>(pending);
    int& selected = *reinterpret_cast<int*>(nativeFrame - 0x28);
    bool found = false;
    for (int i = 0; i < *reinterpret_cast<int*>(list + 0x60) && !found; ++i) {
      byte* row = *reinterpret_cast<byte**>(list + 0x5c) + static_cast<uint>(i) * 0xdcU;
      if (*reinterpret_cast<uint*>(row + 4) == *reinterpret_cast<uint*>(reply + 4) &&
          *reinterpret_cast<uint*>(row) == *reinterpret_cast<uint*>(reply)) {
        found = true;
        selected = i;
      }
    }
    auto rows = [&]() { return *reinterpret_cast<byte**>(list + 0x5c); };
    auto store = [&]() { return *reinterpret_cast<void**>(R6GameServiceAddresses::GServerReplySerializedStore); };
    if (found && *reinterpret_cast<int*>(reply + 0xc) > 0) {
      byte* payload = *reinterpret_cast<byte**>(reply + 8);
      *reinterpret_cast<int*>(nativeFrame - 0x30) = 1;
      LoadSerializedByteStore(store(), payload);
      uint& value = *reinterpret_cast<uint*>(nativeFrame - 0x18);
      byte& flag = *reinterpret_cast<byte*>(nativeFrame - 0x11);
      // The native ignores every scalar-reader status here. Failed reads can propagate stale scratch contents.
      ReadStoredWord(store(), 0x6f, &value);
      uint rowOffset = static_cast<uint>(selected) * 0xdcU;
      *reinterpret_cast<uint*>(rows() + rowOffset + 0x40) = value;
      ReadStoredWord(store(), 0x70, &value);
      *reinterpret_cast<uint*>(rows() + rowOffset + 0x44) = value;
      ReadStoredWord(store(), 0x71, &value);
      *reinterpret_cast<uint*>(rows() + rowOffset + 0x48) = value;
      auto readFlag = [&](uint key, uint shift, uint mask) {
        ReadStoredWord(store(), key, &flag);
        uint* bits = reinterpret_cast<uint*>(rows() + rowOffset + 0x4c);
        const uint old = *bits;
        *bits = old ^ ((old ^ (static_cast<uint>(flag) << shift)) & mask);
      };
      readFlag(0x72, 0, 1);
      readFlag(0x73, 1, 2);
      readFlag(0x74, 3, 8);
      readFlag(0x75, 4, 0x10);
      readFlag(0x76, 5, 0x20);
      ReadStoredWord(store(), 0x77, &value);
      *reinterpret_cast<uint*>(rows() + rowOffset + 0x50) = value;
      ReadStoredWord(store(), 0x78, &value);
      *reinterpret_cast<uint*>(rows() + rowOffset + 0x54) = value;
      readFlag(0x79, 8, 0x100);
      readFlag(0x7a, 7, 0x80);
      readFlag(0x7b, 9, 0x200);
      ResetStringPairArray18(rows() + rowOffset + 0xb8, 0);
      uint& index = *reinterpret_cast<uint*>(nativeFrame - 0x1c);
      index = 0;
      char* textBuffer = reinterpret_cast<char*>(nativeFrame - 0x144);
      do {
        bytes = 0x100;
        textBuffer[0] = 0;
        const int status = static_cast<int>(ReadStoredBytes(store(), index + 0x7cU, textBuffer, &bytes));
        *reinterpret_cast<int*>(nativeFrame - 0x24) = status;
        if (status >= 0) {
          rowOffset = static_cast<uint>(selected) * 0xdcU;
          FArray* names = reinterpret_cast<FArray*>(rows() + rowOffset + 0xb8);
          const int added = names->AddZeroed(0x18, 1);
          byte* nameData = *reinterpret_cast<byte**>(rows() + rowOffset + 0xb8);
          const uint nameOffset = static_cast<uint>(added) * 0x18U;
          FStringNoInit* first = reinterpret_cast<FStringNoInit*>(nameData + nameOffset);
          *reinterpret_cast<FStringNoInit**>(nativeFrame - 0x2c) = first;
          const TCHAR* name = appFromAnsi(textBuffer);
          first = *reinterpret_cast<FStringNoInit**>(nativeFrame - 0x2c);
          *first = name;
          bytes = 0x100;
          textBuffer[0] = 0;
          ReadStoredWord(store(), index + 0x9cU, &value);
          FString* typeName = reinterpret_cast<FString*>(nativeFrame - 0x44);
          using GameTypeCall = FString* (__thiscall *)(UR6ModMgr*, FString*, uint);
          GameTypeCall getName = *reinterpret_cast<GameTypeCall*>(
              R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeNameSlot);
          FString* returned = getName(GModMgr, typeName, value);
          nameData = *reinterpret_cast<byte**>(rows() + rowOffset + 0xb8);
          *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
          *reinterpret_cast<FStringNoInit*>(nameData + nameOffset + 0xc) = *returned;
          *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
          FString::~FString(typeName);
        }
        ++index;
        if (*reinterpret_cast<int*>(nativeFrame - 0x24) < 0) break;
      } while (static_cast<int>(index) < 16);
      rowOffset = static_cast<uint>(selected) * 0xdcU;
      FArray* details = reinterpret_cast<FArray*>(rows() + rowOffset + 0xc4);
      index = 0;
      while (static_cast<int>(index) < *reinterpret_cast<int*>(reinterpret_cast<byte*>(details) + 4)) {
        byte* data = *reinterpret_cast<byte**>(details);
        byte* detail = data + index * 0x2cU;
        *reinterpret_cast<byte**>(nativeFrame - 0x24) = detail;
        *reinterpret_cast<byte*>(nativeFrame - 4) = 2;
        FStringNoInit::~FStringNoInit(reinterpret_cast<FStringNoInit*>(detail + 0x20));
        *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
        FStringNoInit::~FStringNoInit(reinterpret_cast<FStringNoInit*>(detail));
        ++index;
      }
      *reinterpret_cast<int*>(reinterpret_cast<byte*>(details) + 4) = 0;
      *reinterpret_cast<int*>(reinterpret_cast<byte*>(details) + 8) = 0;
      details->Realloc(0x2c);
      index = 0;
      do {
        bytes = 0x100;
        textBuffer[0] = 0;
        const int status = static_cast<int>(ReadStoredBytes(store(), index + 0xbcU, textBuffer, &bytes));
        *reinterpret_cast<int*>(nativeFrame - 0x2c) = status;
        if (status >= 0) {
          rowOffset = static_cast<uint>(selected) * 0xdcU;
          FArray* currentDetails = reinterpret_cast<FArray*>(rows() + rowOffset + 0xc4);
          const int added = currentDetails->AddZeroed(0x2c, 1);
          const uint detailOffset = static_cast<uint>(added) * 0x2cU;
          byte* data = *reinterpret_cast<byte**>(rows() + rowOffset + 0xc4);
          byte* detail = data + detailOffset;
          *reinterpret_cast<byte**>(nativeFrame - 0x24) = detail;
          const TCHAR* name = appFromAnsi(textBuffer);
          detail = *reinterpret_cast<byte**>(nativeFrame - 0x24);
          *reinterpret_cast<FStringNoInit*>(detail) = name;
          bytes = 0x100;
          textBuffer[0] = 0;
          ReadStoredBytes(store(), index + 0xccU, textBuffer, &bytes); // Status ignored; the zeroed buffer is still used.
          data = *reinterpret_cast<byte**>(rows() + rowOffset + 0xc4);
          detail = data + detailOffset;
          *reinterpret_cast<byte**>(nativeFrame - 0x24) = detail;
          const TCHAR* trailing = appFromAnsi(textBuffer);
          detail = *reinterpret_cast<byte**>(nativeFrame - 0x24);
          *reinterpret_cast<FStringNoInit*>(detail + 0x20) = trailing;
          bytes = 0x100;
          textBuffer[0] = 0;
          ReadStoredWord(store(), index + 0xdcU, &value);
          data = *reinterpret_cast<byte**>(rows() + rowOffset + 0xc4);
          *reinterpret_cast<uint*>(data + detailOffset + 0xc) = value;
          bytes = 0x100;
          textBuffer[0] = 0;
          ReadStoredWord(store(), index + 0xecU, &value);
          data = *reinterpret_cast<byte**>(rows() + rowOffset + 0xc4);
          *reinterpret_cast<uint*>(data + detailOffset + 0x18) = value;
        }
        ++index;
        if (*reinterpret_cast<int*>(nativeFrame - 0x2c) < 0) break;
      } while (static_cast<int>(index) < 16);
      reply = *reinterpret_cast<byte**>(pending); // Reload only after the populated-details path.
    }
    FMalloc* allocator = GMalloc;
    allocator->Free(*reinterpret_cast<void**>(reply + 8)); // Unmatched or empty replies are freed and removed too.
    if (*reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4) < 0)
      appFailAssert(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexArrayNum),
          reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x202);
    if (*reinterpret_cast<int*>(reinterpret_cast<byte*>(pending) + 4) < 1)
      appFailAssert(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexCountArrayNum),
          reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x203);
    pending->Remove(0, 1, 0x10);
  }
  const int returnValue = *reinterpret_cast<int*>(nativeFrame - 0x30);
  __asm {
    mov eax,returnValue
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000becf : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch80(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x38]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x34]
    push   ecx
    mov    DWORD PTR [ebp-0x34],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ReceiveAltInfo context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000bee3 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch81(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersReceiveAltInfo
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy parent EBP-44 game-type FString during state1 unwind; current destructor import, no own guard.
// R6GameService.dll @ 10063cd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReceiveAltInfoUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x44]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy first FStringNoInit at CURRENT parent EBP-24 row pointer after trailing-string failure in state2.
// R6GameService.dll @ 10063cd9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReceiveAltInfoUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Select ReceiveAltInfo unwind/typed-pointer/context-catch metadata and tail-enter CRT dispatch.
// R6GameService.dll @ 10063ce2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectReceiveAltInfoEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReceiveAltInfoExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native ReceiveAltInfo unwind record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007cdf4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReceiveAltInfoUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::ReceiveAltInfoUnwind2},
  {0x0, R6GameServiceAddresses::ReceiveAltInfoUnwind3},
  {-1, 0x0},
};

// Native ReceiveAltInfo handlers record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ce14 : native storage identity retained.
const R6GameServiceNative::CatchHandler GReceiveAltInfoHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -56,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch80},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch81},
};

// Native ReceiveAltInfo try record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007ce14 : native storage identity retained.
const R6GameServiceNative::TryBlock ReceiveAltInfoTryMap[1] = {
  {0x0, 0x2, 0x3, 0x2, R6GameServiceAddresses::GReceiveAltInfoHandlers},
};

// Native ReceiveAltInfo info record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007cdf4 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReceiveAltInfoExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::ReceiveAltInfoUnwindMap,
  0x1,
  R6GameServiceAddresses::ReceiveAltInfoTryMap,
  0x0,
  0x0,
};

// Advance sampled MS initialization state through initialization, timeout, shutdown or login notification.
// Nonvirtual void(void)/RET0, saved ECX. Full state samples before state0; unsigned(state-1)<=5 dispatch.
// State1 clock->float32 then request2/login0 BEFORE InitMSClient, preserving child failure publications.
// State2 current ordered strict x87 timeout sets3 without redispatch. State3 shuts down before late0/3.
// State6 publishes login flags/request0/login2 before constructing LOGIN_SUCCESS and passing it by const
// reference to current game manager. Local string is unprotected until state1 before event, lowered0
// before its destructor. State4/5/out-of-range no-op; failures retain committed publications.
// R6GameService.dll @ 1000bf00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessMSClientInitRequest(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  const uint request = *reinterpret_cast<uint*>(0x10091c14);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  switch (request) {
  case 1:
    __asm { call R6GameServiceAddresses::ReadCycleTimeSeconds }
    __asm { fstp DWORD PTR ds:0x100933c8 }
    *reinterpret_cast<int*>(0x10091c14) = 2;
    *reinterpret_cast<int*>(0x10091c0c) = 0;
    receiver->InitMSClient();
    break;
  case 2: {
    // ST(0) elapsed time is compared without a float spill. Unordered/equal do not time out.
    byte timedOut;
    __asm {
      call R6GameServiceAddresses::ReadCycleTimeSeconds
      fsub DWORD PTR ds:0x100933c8
      fcomp DWORD PTR [esi+0x198]
      fnstsw ax
      test ah,0x41
      sete timedOut
    }
    if (timedOut) *reinterpret_cast<int*>(0x10091c14) = 3;
    break;
  }
  case 3:
    receiver->UnInitMSClient();
    *reinterpret_cast<int*>(0x10091c14) = 0;
    *reinterpret_cast<int*>(0x10091c0c) = 3;
    break;
  case 6: {
    *reinterpret_cast<int*>(0x10091e6c) = 1;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x194) |= 0x80;
    *reinterpret_cast<int*>(0x10091c14) = 0;
    *reinterpret_cast<int*>(0x10091c0c) = 2;
    FString* message = reinterpret_cast<FString*>(nativeFrame - 0x24);
    FString::FString(message, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextLOGINSUCCESS));
    UR6AbstractGameManager* manager = GR6GameManager;
    *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
    manager->eventGMProcessMsg(*message);
    *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
    FString::~FString(message);
    break;
  }
  default:
    break; // States 4/5 and all out-of-range DWORDs do no work.
  }
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000c02d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch82(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessMSClientInitRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000c041 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch83(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessMSClientInitRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the completed LOGIN_SUCCESS local string at inherited parent EBP-0x24.
// R6GameService.dll @ 10063cf0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessMSClientInitRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select MS initialization guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063cf9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessMSClientInitRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native MS initialization switch record; addresses and states are literal.
// R6GameService.dll data @ 1000c060 : native storage identity retained.
const uint GProcessMSClientInitRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessMSClientInitRequestSwitchCase1,R6GameServiceAddresses::GProcessMSClientInitRequestSwitchCase2,R6GameServiceAddresses::GProcessMSClientInitRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch171,R6GameServiceAddresses::UR6GSServersBranch171,R6GameServiceAddresses::GProcessMSClientInitRequestSwitchCase6
};

// Native MS initialization unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007ce64 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessMSClientInitRequestUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequestUnwind2},
  {-1, 0x0},
};

// Native MS initialization handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007ce7c : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessMSClientInitRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch82},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch83},
};

// Native MS initialization try record; addresses and states are literal.
// R6GameService.dll data @ 1007ce7c : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessMSClientInitRequestTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GProcessMSClientInitRequestHandlers},
};

// Native MS initialization info record; addresses and states are literal.
// R6GameService.dll data @ 1007ce64 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessMSClientInitRequestExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequestTryMap,
  0x0,
  0x0,
};

// When service is enabled and both refresh flags are idle, publish time/state, clear both arrays and request servers.
// R6GameService.dll @ 1000c0d0 : native effects and guarded lifetime order represented in C++.
void __thiscall UR6GSServers::RefreshServers(void)
{
  const int serviceEnabled = *reinterpret_cast<int*>(0x10091e6c);
  try {
    if (serviceEnabled && !*reinterpret_cast<int*>(0x10091d30) && !*reinterpret_cast<int*>(0x10091d38)) {
      // The clock returns ST(0); the native single-precision spill precedes all refresh publications.
      *reinterpret_cast<float*>(R6GameServiceAddresses::NativeFloat0_0) = (float)ReadCycleTimeSeconds();
      *reinterpret_cast<int*>(0x10091d38) = 1;
      *reinterpret_cast<int*>(0x10091bf8) = 0;
      byte* list = reinterpret_cast<byte*>(this);
      RemoveSTGameServerRange(list + 0x5c, 0, *reinterpret_cast<int*>(list + 0x60));
      RemoveFourByteArrayElements(list + 0x80, 0, *reinterpret_cast<int*>(list + 0x84));
      FString* gameName = reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString1);
      ForwardMSClientOperation1(appToAnsi(**gameName));
      if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
        const TCHAR* currentName = **gameName;
        GLog->Logf(reinterpret_cast<const TCHAR*>(
            R6GameServiceAddresses::WideTextMSClientRequestGameServersMSzGameServiceGameNameS), currentName);
      }
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersRefreshServers);
    throw;
  }
}

// Select RefreshServers two-state/two-handler context catch metadata; neither unwind state has an action.
// R6GameService.dll @ 10063d30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRefreshServersEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RefreshServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal RefreshServers unwind/handler/try/FuncInfo records.
// R6GameService.dll data @ 1007cef0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RefreshServersUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007cf00 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGRefreshServersEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch84},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch85},
};
// R6GameService.dll data @ 1007cf20 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RefreshServersTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGRefreshServersEH},
};
// R6GameService.dll data @ 1007cef0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RefreshServersExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_RefreshServersUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RefreshServersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000c1b9 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch84(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Finish VM parameters and refresh the server list without writing a script result.
// R6GameService.dll @ 1000c1f0 : FFrame/result bridge; typed forwarding and context rethrow preserved.
void __thiscall UR6GSServers::execRefreshServers(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,frame,nullptr);
    }
    RefreshServers();
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecRefreshServers);
    throw;
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063d40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectSmallVMBridgeEH5(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execRefreshServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cf50 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execRefreshServersUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cf60 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSmallVMBridgeEH18[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch86},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch87},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cf60 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execRefreshServersTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGSmallVMBridgeEH18},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cf50 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execRefreshServersExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execRefreshServersUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execRefreshServersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000c258 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch86(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Poll service work, consume queued ping indices, finish refreshes and advance all request stages.
// Exported virtual void(int,int,int,int), saved ECX/RET16. Network DWORD sampled before state0.
// Receive results use full EAX; +48 flags OR current bits2/4. Signed queue count reloads per iteration,
// index/base reload between string copies. State1 protects only the first string during second construction;
// index/base faults before state1 leave that completed string unprotected.
// State0 before PingRequest transfers both values. Incoming argument slots+c/+14 hold scratch pointers.
// Final sampled count is removed even if assertion callbacks change it; assertion target is cached.
// Refresh timeout uses ordered strict x87 greater; global/index/flags accesses stay current and ordered.
// Third current argument gates validation, then all seven request stages run in fixed order.
// R6GameService.dll @ 1000c290 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::GameServiceManager(int msClientAndPingInput,
  int cdKeyInput,int regServerInput,int gsClientInput)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_GameServiceManagerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  const int networkInitialized = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (networkInitialized) {
    const int gsInput = *reinterpret_cast<int*>(nativeFrame + 0x14);
    const int regInput = *reinterpret_cast<int*>(nativeFrame + 0x10);
    const int keyInput = *reinterpret_cast<int*>(nativeFrame + 0xc);
    const int msInput = *reinterpret_cast<int*>(nativeFrame + 8);
    receiver->PollCallbacks(msInput, keyInput, regInput, gsInput);
    byte* list = reinterpret_cast<byte*>(receiver);
    if (receiver->ReceiveServer()) *reinterpret_cast<uint*>(list + 0x48) |= 2;
    if (receiver->ReceiveAltInfo()) *reinterpret_cast<uint*>(list + 0x48) |= 4;
    if (*reinterpret_cast<int*>(0x10091c20)) *reinterpret_cast<uint*>(list + 0x48) |= 2;
    FArray* pingQueue = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray4);
    uint ping = 0;
    int queued;
    for (;;) {
      queued = *reinterpret_cast<int*>(reinterpret_cast<byte*>(pingQueue) + 4);
      if (static_cast<int>(ping) >= queued) break;
      uint* pending = *reinterpret_cast<uint**>(pingQueue);
      const uint serverIndex = pending[ping];
      byte* servers = *reinterpret_cast<byte**>(list + 0x5c);
      FString* address = reinterpret_cast<FString*>(servers + serverIndex * 0xdcU + 0x10);
      // Two outgoing FString values transfer to PingRequest. State 1 protects only the first during the second copy.
      uint currentPing = ping;
      __asm {
        mov eax,address
        sub esp,0xc
        mov ecx,esp
        mov DWORD PTR [ebp+0x14],esp
        push eax
        call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
      }
      pending = *reinterpret_cast<uint**>(pingQueue);
      const uint refreshedIndex = pending[currentPing];
      servers = *reinterpret_cast<byte**>(list + 0x5c);
      FString* name = reinterpret_cast<FString*>(servers + refreshedIndex * 0xdcU + 0x5c);
      __asm {
        mov eax,name
        sub esp,0xc
        mov ecx,esp
        mov DWORD PTR [ebp+0xc],esp
        push eax
        mov BYTE PTR [ebp-0x4],0x1
        call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
        mov ecx,receiver
        mov BYTE PTR [ebp-0x4],0x0
        call R6GameServiceAddresses::UR6GSServers_PingRequest
      }
      ++ping;
    }
    const int removeCount = queued;
    if (queued < 0) {
      using AssertCall = void (__cdecl *)(const char*, const char*, int);
      AssertCall fail = *reinterpret_cast<AssertCall*>(R6GameServiceAddresses::Core__appFailAssertSlot);
      fail(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexArrayNum),
          reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x202);
      if (removeCount > *reinterpret_cast<int*>(reinterpret_cast<byte*>(pingQueue) + 4))
        fail(reinterpret_cast<const char*>(R6GameServiceAddresses::TextIndexCountArrayNum),
            reinterpret_cast<const char*>(R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH), 0x203);
    }
    pingQueue->Remove(0, removeCount, 4); // The captured count survives assertion callbacks.
    if (*reinterpret_cast<int*>(0x10091d38)) {
      bool completed = *reinterpret_cast<int*>(0x10091bf8) != 0;
      if (!completed) {
        byte expired;
        // Elapsed value remains extended; equal/unordered do not expire. Restore the clock's remaining ST(0).
        __asm {
          call R6GameServiceAddresses::ReadCycleTimeSeconds
          fld DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
          fsubr st,st(1)
          mov esi,receiver
          fcomp DWORD PTR [esi+0x198]
          fnstsw ax
          fstp st(0)
          test ah,0x41
          sete expired
        }
        completed = expired != 0;
      }
      if (completed && !*reinterpret_cast<int*>(0x10091d3c)) {
        *reinterpret_cast<int*>(0x10091d38) = 0;
        *reinterpret_cast<uint*>(list + 0x194) |= 0x400;
      }
    } else if (*reinterpret_cast<int*>(0x10091d30)) {
      bool completed = *reinterpret_cast<int*>(0x10091bf8) != 0;
      if (!completed) {
        byte expired;
        __asm {
          call R6GameServiceAddresses::ReadCycleTimeSeconds
          fld DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
          fsubr st,st(1)
          mov esi,receiver
          fcomp DWORD PTR [esi+0x198]
          fnstsw ax
          fstp st(0)
          test ah,0x41
          sete expired
        }
        completed = expired != 0;
      }
      if (completed) {
        *reinterpret_cast<int*>(0x10091d30) = 0;
        uint flags = *reinterpret_cast<uint*>(list + 0x194);
        const int serverIndex = *reinterpret_cast<int*>(list + 0x44);
        *reinterpret_cast<uint*>(list + 0x194) = flags | 0x400;
        RemoveSTGameServerRange(list + 0x5c, serverIndex, 1);
        const int currentIndex = *reinterpret_cast<int*>(list + 0x44);
        RemoveFourByteArrayElements(list + 0x80, currentIndex, 1);
      }
    }
    if (*reinterpret_cast<int*>(nativeFrame + 0x10)) receiver->ReceiveValidation();
    receiver->ProcessMSClientInitRequest();
    receiver->ProcessRegServerLoginRouterRequest();
    receiver->ProcessRegServerGetLobbiesRequest();
    receiver->ProcessRegServerRegOnLobbyRequest();
    receiver->ProcessRegServerLoginRequest();
    receiver->ProcessRegServerUpdateRequest();
    receiver->ProcessJoinServerRequest();
  }
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x10
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000c4be : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch88(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::GameServiceManager context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000c4d2 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch89(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersGameServiceManager
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the first completed outgoing ping string through its saved parent argument-slot pointer.
// R6GameService.dll @ 10063d50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GameServiceManagerUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x14]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select the ping/manager guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063d59 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GameServiceManagerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_GameServiceManagerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native ping/manager unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007cfb0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_GameServiceManagerUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_GameServiceManagerUnwind2},
  {-1, 0x0},
};

// Native ping/manager handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007cfc8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GGameServiceManagerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch88},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch89},
};

// Native ping/manager try record; addresses and states are literal.
// R6GameService.dll data @ 1007cfc8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_GameServiceManagerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GGameServiceManagerHandlers},
};

// Native ping/manager info record; addresses and states are literal.
// R6GameService.dll data @ 1007cfb0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_GameServiceManagerExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_GameServiceManagerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_GameServiceManagerTryMap,
  0x0,
  0x0,
};

// MSVC records: guard catches unsigned short * by value, then catch-all; cleanup actions retain parent EBP.
// R6GameService.dll data @ 1007d018 : selected constructor/throw metadata.
const R6GameServiceNative::UnwindEntry UR6GSServersUnwindMap[13] = {
  {-1, R6GameServiceAddresses::UR6GSServersUnwind1},
  {0x0, R6GameServiceAddresses::UR6GSServersUnwind2},
  {0x1, R6GameServiceAddresses::UR6GSServersUnwind3},
  {0x2, R6GameServiceAddresses::UR6GSServersUnwind4},
  {0x3, R6GameServiceAddresses::UR6GSServersUnwind5},
  {0x4, R6GameServiceAddresses::UR6GSServersUnwind6},
  {0x5, R6GameServiceAddresses::UR6GSServersUnwind7},
  {0x6, R6GameServiceAddresses::UR6GSServersUnwind8},
  {0x7, R6GameServiceAddresses::UR6GSServersUnwind9},
  {0x8, R6GameServiceAddresses::UR6GSServersUnwind10},
  {0x9, R6GameServiceAddresses::UR6GSServersUnwind11},
  {0xa, 0x0},
  {0xa, 0x0},
};
// R6GameService.dll data @ 1007d080 : selected constructor/throw metadata.
const R6GameServiceNative::CatchHandler GGSServersDefaultHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch90},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch91},
};
// R6GameService.dll data @ 1007d0a0 : selected constructor/throw metadata.
const R6GameServiceNative::TryBlock UR6GSServersTryMap[1] = {
  {0xb, 0xb, 0xc, 0x2, R6GameServiceAddresses::GGSServersDefaultHandlers},
};
// R6GameService.dll data @ 1007d0b4 : selected constructor/throw metadata.
const R6GameServiceNative::FuncInfo UR6GSServersExceptionInfo = {
  0x19930520,
  0xd,
  R6GameServiceAddresses::UR6GSServersUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServersTryMap,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007a95c : selected constructor/throw metadata.
const R6GameServiceNative::CatchableType GGSServersPointerVoidCatchable = {
  0x1,
  R6GameServiceAddresses::PAXTypeDescriptor,
  0x0,
  -1,
  0x0,
  0x4,
  0x0,
};
// R6GameService.dll data @ 1007a978 : selected constructor/throw metadata.
const R6GameServiceNative::CatchableType GGSServersPointerUShortCatchable = {
  0x1,
  R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor,
  0x0,
  -1,
  0x0,
  0x4,
  0x0,
};
// R6GameService.dll data @ 1007a994 : selected constructor/throw metadata.
// R6GameService.dll data @ 1007a95c : native storage identity retained.
const R6GameServiceNative::CatchableTypeArray<2> GGSServersPointerUShortTypes = {
  0x2,
  {R6GameServiceAddresses::GGSServersPointerUShortCatchable, R6GameServiceAddresses::GGSServersPointerVoidCatchable},
};
// R6GameService.dll data @ 1007a9a0 : selected constructor/throw metadata.
// R6GameService.dll data @ 1007a994 : native storage identity retained.
const R6GameServiceNative::ThrowInfo GGSServersPointerUShortThrow = {
  0x0,
  0x0,
  0x0,
  R6GameServiceAddresses::GGSServersPointerUShortTypes,
};

// Constructs the base and ten strings, restores the saved password/launch bit, then dispatches InitializeMod.
// R6GameService.dll @ 1000c4f0 : RET0; guard states11/12 unwind to all ten completed strings.
__declspec(naked) UR6GSServers * __thiscall UR6GSServers::UR6GSServers(void)
{
  byte *nativeFrame,*receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServersSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x18],esi
    mov    nativeFrame,ebp
    mov    receiver,esi
  }
  using ConstructABI = void * (__thiscall *)(void *);
  ((ConstructABI)R6GameServiceAddresses::UR6ServerList_UR6ServerList)(receiver);
  *(uint *)(nativeFrame - 4) = 0;
  *(uint *)receiver = R6GameServiceAddresses::UR6GSServersDispatchTable;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1a0);
  *(byte *)(nativeFrame - 4) = 1;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1ac);
  *(byte *)(nativeFrame - 4) = 2;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1b8);
  *(byte *)(nativeFrame - 4) = 3;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1c4);
  *(byte *)(nativeFrame - 4) = 4;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1d0);
  *(byte *)(nativeFrame - 4) = 5;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1dc);
  *(byte *)(nativeFrame - 4) = 6;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1e8);
  *(byte *)(nativeFrame - 4) = 7;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x1f4);
  *(byte *)(nativeFrame - 4) = 8;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x200);
  *(byte *)(nativeFrame - 4) = 9;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(receiver + 0x20c);
  *(byte *)(nativeFrame - 4) = 11;
  using MemberABI = uint (__thiscall *)(void *);
  ((MemberABI)R6GameServiceAddresses::UR6GSServers_CreatedCDKey)(receiver);
  ((MemberABI)R6GameServiceAddresses::UR6GSServers_LogGSVersion)(receiver);
  using AssignABI = void * (__thiscall *)(void *,const void *);
  (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot)(receiver + 0x1dc,receiver + 0x1c4);
  void *actorClass = *(void **)R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot;
  void *actor = (*(ConstructABI *)R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot)(actorClass);
  uint started = (*(MemberABI *)R6GameServiceAddresses::Engine_AActor_NativeStartedByGSClientSlot)(actor);
  uint flags = *(uint *)(receiver + 0x194);
  *(uint *)(receiver + 0x194) = flags ^ (((started << 2) ^ flags) & 4);
  uint name = *(uint *)0x10092e80;
  using FindABI = UFunction * (__thiscall *)(void *,uint,uint);
  UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)(receiver,name,0);
  byte *table = *(byte **)receiver;
  using EventABI = void (__thiscall *)(void *,UFunction *,void *,void *);
  (*(EventABI *)(table + 0x10))(receiver,function,nullptr,nullptr);
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Throws a copied unsigned-short pointer caught by value at parent EBP-0x1c (.PAG, four bytes).
// R6GameService.dll @ 1000c63f : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch90(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports the constructor guard context, then rethrows the active exception with null throw arguments.
// R6GameService.dll @ 1000c653 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch91(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersUR6GSServers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the server-list base through the saved parent receiver at EBP-0x18.
// R6GameService.dll @ 10063d70 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    R6GameServiceAddresses::UR6ServerList__UR6ServerList
  }
}

// Destroys the completed string at +0x1a0 through the saved parent receiver.
// R6GameService.dll @ 10063d78 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1a0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1ac through the saved parent receiver.
// R6GameService.dll @ 10063d87 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1ac
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1b8 through the saved parent receiver.
// R6GameService.dll @ 10063d96 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1b8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1c4 through the saved parent receiver.
// R6GameService.dll @ 10063da5 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind5(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1c4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1d0 through the saved parent receiver.
// R6GameService.dll @ 10063db4 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1d0
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1dc through the saved parent receiver.
// R6GameService.dll @ 10063dc3 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1dc
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1e8 through the saved parent receiver.
// R6GameService.dll @ 10063dd2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1e8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x1f4 through the saved parent receiver.
// R6GameService.dll @ 10063de1 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind9(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x1f4
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x200 through the saved parent receiver.
// R6GameService.dll @ 10063df0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x200
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the completed string at +0x20c through the saved parent receiver.
// R6GameService.dll @ 10063dff : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersUnwind11(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x20c
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the thirteen-state constructor map and its typed/catch-all guard handlers.
// R6GameService.dll @ 10063e0e : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServersSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d0d0 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry CreatedCDKeyUnwindMap[5] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::CreatedCDKeyUnwind2},
  {0x1, R6GameServiceAddresses::CreatedCDKeyUnwind3},
  {0x1, R6GameServiceAddresses::CreatedCDKeyUnwind4},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d0f8 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch92},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch93},
};
// R6GameService.dll data @ 1007d118 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock CreatedCDKeyTryMap[1] = {
  {0x0, 0x3, 0x4, 0x2, R6GameServiceAddresses::GCDKeyHandlers},
};
// R6GameService.dll data @ 1007d12c : selected guard/cleanup records.
// R6GameService.dll data @ 1007d0d0 : native storage identity retained.
const R6GameServiceNative::FuncInfo CreatedCDKeyExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::CreatedCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::CreatedCDKeyTryMap,
  0x0,
  0x0,
};

// Loads and validates the registry key, updates 0x10093488, then copies it to 0x10093494; failure clears bit0.
// R6GameService.dll @ 1000c670 : exported void(), thiscall; original registry status and flag semantics.
void __thiscall UR6GSServers::CreatedCDKey()
{
  try {
    FString encryptedKey;
    using RegGetABI = int (__cdecl *)(FString,FString,FString&);
    using DecryptABI = FString (__cdecl *)(FString);
    // This logical FString view transfers the same three words consumed by the raw native wrapper.
    using ValidateABI = uint (__cdecl *)(FString);
    // RegGet consumes both arguments; its status does not decide whether the output is validated.
    (*(RegGetABI *)R6GameServiceAddresses::Core__RegGetSlot)
        (FString((const TCHAR *)R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainmentRAVENSHIELD),
         FString((const TCHAR *)R6GameServiceAddresses::WideTextCDKey),encryptedKey);
    if (((ValidateABI)R6GameServiceAddresses::IsCDKeyValidOnMachine)(encryptedKey) != 0) {
      FString decrypted = ((DecryptABI)R6GameServiceAddresses::DecryptFStringWithUeviLCore)(encryptedKey);
      *(FString *)R6GameServiceAddresses::GServiceString8 = decrypted;
    } else {
      *(FString *)R6GameServiceAddresses::GServiceString8 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
      *(uint *)((byte *)this + 0x194) &= 0xfffffffe;
    }
    // The decrypted temporary is already gone; copy the cache before destroying the registry output.
    *(FString *)R6GameServiceAddresses::GServiceString9 = *(FString *)R6GameServiceAddresses::GServiceString8;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersCreatedCDKey);
    throw;
  }
}

// Copies the caught unsigned-short pointer at parent EBP-0x20 to-0x14 and throws it by value.
// R6GameService.dll @ 1000c77e : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch92(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports the CD-key initialization guard context and rethrows the active exception.
// R6GameService.dll @ 1000c792 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch93(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersCreatedCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the completed local string at parent EBP-0x2c.
// R6GameService.dll @ 10063e20 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreatedCDKeyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed outgoing key string through its saved parent EBP-0x18 pointer.
// R6GameService.dll @ 10063e29 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreatedCDKeyUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed local string at parent EBP-0x38.
// R6GameService.dll @ 10063e32 : complete native control/access order and raw ABI retained.
__declspec(naked) void CreatedCDKeyUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the exact CD-key initialization guard and temporary-string cleanup map.
// R6GameService.dll @ 10063e3b : complete native control/access order and raw ABI retained.
__declspec(naked) void CreatedCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CreatedCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Consumes the finish/debug tokens, invokes the current initialization virtual and writes all 32 result bits.
// R6GameService.dll @ 1000c920 : thiscall/RET8; token access precedes the guarded callback region.
void __thiscall UR6GSServers::execInitGSCDKey(FFrame &Stack,void *const Result)
{
  byte *code = *(byte **)((byte *)&Stack + 0xc) + 1;
  *(byte **)((byte *)&Stack + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)&Stack + 8);
      *(byte **)((byte *)&Stack + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,&Stack,0);
    }
    using InitABI = uint (__thiscall *)(UR6GSServers *);
    uint initialized = ((InitABI)(*(uint **)this)[0x68 / 4])(this);
    *(uint *)Result = initialized;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersExecInitGSCDKey);
    throw;
  }
}

// Selects execInitGSCDKey private catches; both guard states have no local cleanup actions.
// R6GameService.dll @ 10063e80 : private metadata selector; exact raw CRT forwarding ABI.
__declspec(naked) void __cdecl execInitGSCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execInitGSCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d1c8 : selected native guard record.
const R6GameServiceNative::UnwindEntry execInitGSCDKeyUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007d1d8 : selected native guard record.
const R6GameServiceNative::CatchHandler GexecInitGSCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch94},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch95},
};
// R6GameService.dll data @ 1007d1f8 : selected native guard record.
const R6GameServiceNative::TryBlock execInitGSCDKeyTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecInitGSCDKeyHandlers},
};
// R6GameService.dll data @ 1007d20c : selected native guard record.
// R6GameService.dll data @ 1007d1c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo execInitGSCDKeyExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execInitGSCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::execInitGSCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000c98d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch94(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execInitGSCDKey context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000c9a1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch95(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecInitGSCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Runs player disconnect, releases flagged contexts, then clears both readiness flags after all branches.
// R6GameService.dll @ 1000c9c0 : C++ shutdown, preserving vtable-before-guard and final readiness publication.
__declspec(naked) void __thiscall UR6GSServers::UnInitCDKey()
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UnInitCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    nativeFrame,ebp
    mov    receiver,ecx
  }
  byte *table = *(byte **)receiver;
  __asm {
    push   ebx
    push   esi
    push   edi
    xor    esi,esi
    mov    DWORD PTR [ebp-0x10],esp
  }
  *(uint *)(nativeFrame - 4) = 0;
  using DisconnectABI = void (__thiscall *)(UR6GSServers *);
  using ReleaseABI = uint (__stdcall *)(uint);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  (*(DisconnectABI *)(table + 0x90))(receiver);
  if (*(uint *)0x10093410 != 0) {
    ((ReleaseABI)R6GameServiceAddresses::RemoveCDKeyContextOrRegistry)
        (*(uint *)R6GameServiceAddresses::GBaseCDKeyContext);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextRSCDKeyGSCDKeyUninitialize);
    }
  }
  if (*(uint *)0x100933cc != 0) {
    ((ReleaseABI)R6GameServiceAddresses::RemoveCDKeyContextOrRegistry)
        (*(uint *)R6GameServiceAddresses::GModCDKeyContext);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextModCDKeyGSCDKeyUninitialize);
    }
  }
  uint predecessor = *(uint *)(nativeFrame - 0xc);
  __asm {
    pop    edi
  }
  *(uint *)0x10093410 = 0;
  *(uint *)0x100933cc = 0;
  __asm {
    mov    ecx,predecessor
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Selects UnInitCDKey's private catches; both guard states have no local cleanup actions.
// R6GameService.dll @ 10063e90 : private metadata selector, literal FuncInfo and raw CRT tail retained.
__declspec(naked) void __cdecl UnInitCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UnInitCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d228 : selected native guard record.
const R6GameServiceNative::UnwindEntry UnInitCDKeyUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007d238 : selected native guard record.
const R6GameServiceNative::CatchHandler GUnInitCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch96},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch97},
};
// R6GameService.dll data @ 1007d258 : selected native guard record.
const R6GameServiceNative::TryBlock UnInitCDKeyTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GUnInitCDKeyHandlers},
};
// R6GameService.dll data @ 1007d26c : selected native guard record.
// R6GameService.dll data @ 1007d228 : native storage identity retained.
const R6GameServiceNative::FuncInfo UnInitCDKeyExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UnInitCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::UnInitCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000ca71 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch96(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::UnInitCDKey context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000ca85 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch97(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersUnInitCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    esi,esi
    push   esi
    push   esi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Submit the selected product and a bounded key, substituting a literal when FString count exceeds 24.
// Exported nonvirtual void(FString,int), unused incoming ECX, owns 12-byte input, RET16; selector name inferred.
// Endpoint at EBP-f4 has 130 address bytes then WORD port. Payload at EBP-70 has key at +33, 23 copied bytes,
// untouched byte +56 and zero byte +57. Mod product copy is unbounded and can overwrite key/string scratch.
// State 4 bypasses the normally destroyed conditional literal; unwind state 2 clears its bit before destruction.
// Cached appToAnsi serves key and Mod product. Diagnostics forward the current global key triple.
// R6GameService.dll @ 1000cab0 : C++ operations with native frame/exception boundaries retained for unchecked overlap.
__declspec(naked) void __thiscall UR6GSServers::RequestActivation(FString key,int selector)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_RequestActivationSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xe8
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using CopyTextABI = char * (__cdecl *)(char *,const char *,uint);
  using SubmitABI = uint (__stdcall *)(void *,const void *,const void *,int);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using ConstructABI = FString * (__thiscall *)(FString *,const TCHAR *);
  using CopyABI = FString * (__thiscall *)(FString *,const FString *);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame - 0x14) = 0;
  *(uint *)(nativeFrame - 4) = 0;
  *(byte *)(nativeFrame - 4) = 1;
  const char *source = (const char *)0x10091c28;
  char *endpoint = (char *)(nativeFrame - 0xf4);
  char *destination = endpoint;
  char character;
  do {
    character = *source++;
    *destination++ = character;
  } while (character != 0);
  *(ushort *)(nativeFrame - 0x72) = *(ushort *)0x10091c04;
  uint count = *(uint *)(nativeFrame + 0xc);
  uint conditionalLiteral = 0;
  const FString *selected;
  if (count != 0 && count - 1 > 23) {
    selected = (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
        ((FString *)(nativeFrame - 0x34),(const TCHAR *)R6GameServiceAddresses::WideTextCDKEYNotValid);
    conditionalLiteral |= 1;
    *(byte *)(nativeFrame - 4) = 2;
    *(uint *)(nativeFrame - 0x14) = conditionalLiteral;
  } else {
    selected = (const FString *)(nativeFrame + 8);
  }
  FString *selectedKey = (FString *)(nativeFrame - 0x24);
  (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(selectedKey,selected);
  *(uint *)(nativeFrame - 4) = 4;
  if ((conditionalLiteral & 1) != 0)
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame - 0x34));
  const TCHAR *wideKey = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(selectedKey);
  AnsiABI toAnsi = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
  const char *keyText = toAnsi(wideKey);
  (*(CopyTextABI *)R6GameServiceAddresses::MSVCR71_strncpySlot)((char *)(nativeFrame - 0x4f),keyText,23);
  uint selectedProduct = *(uint *)(nativeFrame + 0x14);
  *(byte *)(nativeFrame - 0x37) = 0;
  char *payload = (char *)(nativeFrame - 0x70);
  void *context;
  if (selectedProduct != 0) {
    const TCHAR *product = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
        ((const FString *)R6GameServiceAddresses::GServiceString1);
    source = toAnsi(product);
    destination = payload;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
  } else {
    uint tail = *(uint *)R6GameServiceAddresses::TextELD;
    uint first = *(uint *)R6GameServiceAddresses::TextRAVENSHIELD;
    uint middle = *(uint *)R6GameServiceAddresses::TextNSHIELD;
    *(uint *)(payload + 8) = tail;
    context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
    *(uint *)payload = first;
    *(uint *)(payload + 4) = middle;
  }
  ((SubmitABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation5)(context,endpoint,payload,6);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    const uint *globalKey = (const uint *)R6GameServiceAddresses::GServiceString8;
    uint data = globalKey[0];
    uint count = globalKey[1];
    uint capacity = globalKey[2];
    FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (logger,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyRequestActivationS,data,count,capacity);
  }
  *(byte *)(nativeFrame - 4) = 1;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(selectedKey);
  *(uint *)(nativeFrame - 4) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame + 8));
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x10
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000cc45 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch98(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x28]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x18]
    push   ecx
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RequestActivation context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000cc59 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch99(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRequestActivation
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the owned incoming FString through the inherited parent frame.
// R6GameService.dll @ 10063ea0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RequestActivationUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Clear the conditional literal ownership bit before forwarding its destructor; otherwise return.
// R6GameService.dll @ 10063ea9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RequestActivationUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    je     Branch200
    and    DWORD PTR [ebp-0x14],0xfffffffe
    lea    ecx,[ebp-0x34]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch200:
    ret
  }
}

// Destroy the selected local FString through the inherited parent frame.
// R6GameService.dll @ 10063ec3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RequestActivationUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select activation guard metadata and tail-enter the CRT frame handler.
// R6GameService.dll @ 10063ecc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RequestActivationSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RequestActivationExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native activation unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007d288 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RequestActivationUnwindMap[6] = {
  {-1, R6GameServiceAddresses::UR6GSServers_RequestActivationUnwind1},
  {0x0, 0x0},
  {0x1, R6GameServiceAddresses::UR6GSServers_RequestActivationUnwind3},
  {0x2, R6GameServiceAddresses::UR6GSServers_RequestActivationUnwind4},
  {0x1, R6GameServiceAddresses::UR6GSServers_RequestActivationUnwind4},
  {0x0, 0x0},
};

// Native activation handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007d2b8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GRequestActivationHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -40,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch98},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch99},
};

// Native activation try record; addresses and states are literal.
// R6GameService.dll data @ 1007d2b8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RequestActivationTryMap[1] = {
  {0x1, 0x4, 0x5, 0x2, R6GameServiceAddresses::GRequestActivationHandlers},
};

// Native activation info record; addresses and states are literal.
// R6GameService.dll data @ 1007d288 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RequestActivationExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::UR6GSServers_RequestActivationUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RequestActivationTryMap,
  0x0,
  0x0,
};

// Clear activation reply, then mark activation requested.
// R6GameService.dll @ 1000cc80 : exported void member; unused receiver, inferred global roles.
void __thiscall UR6GSServers::RequestGSCDKeyActID(void)
{
  *(uint *)0x100933f4 = 0;
  *(uint *)R6GameServiceAddresses::GActivationState = 1;
}

// Clear activation reply, shared retry count and activation state in order.
// R6GameService.dll @ 1000cca0 : exported void member; unused receiver, inferred global roles.
void __thiscall UR6GSServers::CancelGSCDKeyActID(void)
{
  *(uint *)0x100933f4 = 0;
  *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
  *(uint *)R6GameServiceAddresses::GActivationState = 0;
}

// Submit saved activation bytes and bounded key text through the zero/nonzero selected client.
// Exported nonvirtual void(int), unused incoming ECX, RET4; selector and scratch names are inferred.
// Endpoint at EBP-c8 has 130 address bytes then WORD port; payload at EBP-44 copies 16 ID bytes and 23 key bytes.
// Payload+39 stays unwritten; +40 is zero. Both context slots are read for selector 0, Mod slot first.
// State 0 is published before the unbounded endpoint copy. No local or incoming FString ownership.
// Debug logging reloads the RS context even for Mod requests and forwards the three current key words.
// R6GameService.dll @ 1000ccc0 : C++ operations with native frame/exception boundaries retained for unchecked overlap.
__declspec(naked) void __thiscall UR6GSServers::RequestAuthorization(int selector)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_RequestAuthorizationSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xbc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using CopyTextABI = char * (__cdecl *)(char *,const char *,uint);
  using SubmitABI = uint (__stdcall *)(void *,const void *,const void *,int);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  *(uint *)(nativeFrame - 4) = 0;
  const char *source = (const char *)0x10091c28;
  char *endpoint = (char *)(nativeFrame - 0xc8);
  char *destination = endpoint;
  char character;
  do {
    character = *source++;
    *destination++ = character;
  } while (character != 0);
  *(ushort *)(nativeFrame - 0x46) = *(ushort *)0x10091c04;
  byte *payload = nativeFrame - 0x44;
  for (uint index = 0; index != 16; ++index) payload[index] = *(byte *)(0x100933f8 + index);
  const TCHAR *wideKey = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((const FString *)R6GameServiceAddresses::GServiceString8);
  const char *keyText = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wideKey);
  (*(CopyTextABI *)R6GameServiceAddresses::MSVCR71_strncpySlot)((char *)payload + 16,keyText,23);
  uint selectedProduct = *(uint *)(nativeFrame + 8);
  void *context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
  payload[40] = 0;
  if (selectedProduct == 0) context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
  ((SubmitABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation6)(context,endpoint,payload,6);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    uint baseContext = *(uint *)R6GameServiceAddresses::GBaseCDKeyContext;
    const uint *globalKey = (const uint *)R6GameServiceAddresses::GServiceString8;
    uint data = globalKey[0];
    uint count = globalKey[1];
    uint capacity = globalKey[2];
    FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (logger,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyRequestAuthorizationSD,
         data,count,capacity,baseContext);
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000cdc7 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch100(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RequestAuthorization context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000cddb : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch101(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRequestAuthorization
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select the authorization guard metadata and tail-enter the CRT frame handler.
// R6GameService.dll @ 10063ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RequestAuthorizationSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RequestAuthorizationExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native authorization unwind record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d308 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RequestAuthorizationUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native authorization handlers record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d318 : native storage identity retained.
const R6GameServiceNative::CatchHandler GRequestAuthorizationHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch100},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch101},
};

// Native authorization try record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d318 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RequestAuthorizationTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GRequestAuthorizationHandlers},
};

// Native authorization info record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d34c : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RequestAuthorizationExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_RequestAuthorizationUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RequestAuthorizationTryMap,
  0x0,
  0x0,
};

// Mark authorization requested without clearing its reply or the shared retry count.
// R6GameService.dll @ 1000ce00 : exported void member; unused receiver, inferred global roles.
void __thiscall UR6GSServers::RequestGSCDKeyAuthID(void)
{
  *(uint *)R6GameServiceAddresses::GAuthorizationState = 1;
}

// Clear shared retry count, authorization state and authorization reply in order.
// R6GameService.dll @ 1000ce10 : exported void member; unused receiver, inferred global roles.
void __thiscall UR6GSServers::CancelGSCDKeyAuthID(void)
{
  *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
  *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
  *(uint *)0x10093414 = 0;
}

// Clear the 20 binary authentication bytes with five ordered DWORD stores.
// R6GameService.dll @ 1000ce30 : exported void member; unused receiver, inferred global roles.
void __thiscall UR6GSServers::ResetAuthId(void)
{
  *(uint *)0x10093428 = 0;
  *(uint *)0x1009342c = 0;
  *(uint *)0x10093430 = 0;
  *(uint *)0x10093434 = 0;
  *(uint *)0x10093438 = 0;
}

// Copy the selected cached authentication string into caller-owned, initially unconstructed result storage.
// R6GameService.dll @ 1000ce50 : virtual FString(int), expanded hidden-result ABI, RET8; ECX is unused.
FString * __thiscall UR6GSServers::GetAuthID(FString *result,int selector)
{
  try {
    const FString *cachedId = (const FString *)(selector == 0
        ? R6GameServiceAddresses::GServiceString4 : R6GameServiceAddresses::GServiceString11);
    FString::FString(result,cachedId);
    return result;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersGetAuthID);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000ceb2 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch102(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::GetAuthID context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000cec6 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch103(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersGetAuthID
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select the cached-ID copy guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063ef0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GetAuthIDSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_GetAuthIDExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native cached-ID unwind record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d368 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_GetAuthIDUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native cached-ID handlers record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d378 : native storage identity retained.
const R6GameServiceNative::CatchHandler GGetAuthIDHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch102},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch103},
};

// Native cached-ID try record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d378 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_GetAuthIDTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GGetAuthIDHandlers},
};

// Native cached-ID info record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d368 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_GetAuthIDExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_GetAuthIDUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_GetAuthIDTryMap,
  0x0,
  0x0,
};

// Accepts the current Raven Shield identity or case-insensitive R6RSCUSTOM name; logging queries identity twice.
// R6GameService.dll @ 1000cef0 : exported nonvirtual int(void); unused receiver.
int __thiscall UR6GSServers::IsAuthIDSuccess(void)
{
  using IsRavenShieldABI = uint (__thiscall *)(void *);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using CompareABI = int (__cdecl *)(const TCHAR *,const TCHAR *);
  try {
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
      void *manager = *managerSlot;
      uint identity = (*(IsRavenShieldABI *)R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot)(manager);
      FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      LogABI log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      log(logger,(const TCHAR *)R6GameServiceAddresses::WideTextIsAuthIDSuccessIsRavenshieldD,identity);
      const uint *gameName = (const uint *)R6GameServiceAddresses::GServiceString3;
      uint data = gameName[0];
      uint count = gameName[1];
      uint capacity = gameName[2];
      logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      log(logger,(const TCHAR *)R6GameServiceAddresses::WideTextMSzGameServiceMODGameNameS,data,count,capacity);
    }
    void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
    void *manager = *managerSlot;
    uint identity = (*(IsRavenShieldABI *)R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot)(manager);
    if (identity != 0) return 1;
    const TCHAR *gameName = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
        ((const FString *)R6GameServiceAddresses::GServiceString3);
    return (*(CompareABI *)R6GameServiceAddresses::Core__appStricmpSlot)
        (gameName,(const TCHAR *)R6GameServiceAddresses::WideTextR6RSCUSTOM) == 0 ? 1 : 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersIsAuthIDSuccess);
    throw;
  }
}

// Selects IsAuthIDSuccess's private catches; both guard states have no local cleanup actions.
// R6GameService.dll @ 10063f00 : private metadata selector, literal FuncInfo and raw CRT tail retained.
__declspec(naked) void __cdecl IsAuthIDSuccessSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::IsAuthIDSuccessExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d3c8 : selected native guard record.
const R6GameServiceNative::UnwindEntry IsAuthIDSuccessUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007d3d8 : selected native guard record.
const R6GameServiceNative::CatchHandler GIsAuthIDSuccessHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch104},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch105},
};
// R6GameService.dll data @ 1007d3f8 : selected native guard record.
const R6GameServiceNative::TryBlock IsAuthIDSuccessTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GIsAuthIDSuccessHandlers},
};
// R6GameService.dll data @ 1007d40c : selected native guard record.
// R6GameService.dll data @ 1007d3c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo IsAuthIDSuccessExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::IsAuthIDSuccessUnwindMap,
  0x1,
  R6GameServiceAddresses::IsAuthIDSuccessTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000cfcd : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch104(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::IsAuthIDSuccess context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000cfe1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch105(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersIsAuthIDSuccess
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Copy16 bytes in ascending read/store order; overlap can propagate earlier stores into later reads.
// Nonvirtual void(byte*,byte*), unused incoming ECX/RET8. EAX ends at destination+16, ECX=source-destination;
// only DL changes in EDX, ESI is saved/restored. No guard, pointer validation or other ownership.
// R6GameService.dll @ 1000d000 : complete native control/access order and raw ABI retained.
void __thiscall UR6GSServers::CopyActivationIDInByteArray(uchar *source,uchar *destination)
{
  for (uint index = 0; index != 16; ++index) destination[index] = source[index];
}

// Decodes twenty authentication bytes and submits validation with the current endpoint and RS/Mod context.
// R6GameService.dll @ 1000d110 : int(FString,int,int), thiscall/RET20; receiver is unused, input string is owned.
int __thiscall UR6GSServers::CDKeyValidateUser(FString authenticationId,int validationMode,int modIndex)
{
  try {
    // Native local span EBP-d8..EBP-d: endpoint+0, port+82, ANSI text+84, decoded bytes+ac (hex offsets).
    // Text has only 40 bytes before decoded storage; retain both unbounded copies and reads beyond an early NUL.
    byte scratch[0xcc];
    char *endpoint = (char *)scratch;
    const char *source = (const char *)0x10091c28;
    char *destination = endpoint;
    char character;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    *(ushort *)(scratch + 0x82) = *(ushort *)0x10091c04;
    const TCHAR *wideId = *authenticationId;
    using AnsiABI = const char *(__cdecl *)(const TCHAR *);
    AnsiABI toAnsi = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
    source = toAnsi(wideId);
    char *text = (char *)scratch + 0x84;
    destination = text;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    byte *decoded = scratch + 0xac;
    for (uint index = 0; index < 0x28; index += 2) {
      int low = HexDigitToValue(text + index + 1);
      int high = HexDigitToValue(text + index);
      decoded[index / 2] = (byte)(((byte)high << 4) + (byte)low);
    }
    uint kind = validationMode == 0 ? 3 : 6;
    void *context;
    const char *product;
    if (modIndex != 0) {
      FString &modProduct = *(FString *)R6GameServiceAddresses::GServiceString1;
      const TCHAR *wideProduct = *modProduct;
      product = toAnsi(wideProduct);
      context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
    } else {
      context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
      product = (const char *)R6GameServiceAddresses::TextRAVENSHIELD;
    }
    using ValidateABI = int (__stdcall *)(void *,void *,byte *,const char *,uint);
    int requestId = ((ValidateABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation2)
        (context,endpoint,decoded,product,kind);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      const uint *words = (const uint *)&authenticationId;
      uint dataWord = words[0], countWord = words[1], capacityWord = words[2];
      using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyValidateUserS,dataWord,countWord,capacityWord);
    }
    return requestId;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersCDKeyValidateUser);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000d265 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch106(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::CDKeyValidateUser context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000d279 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch107(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersCDKeyValidateUser
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the owned incoming authentication string at inherited parent EBP+0x8.
// R6GameService.dll @ 10063f40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_CDKeyValidateUserUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select user-validation guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063f49 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_CDKeyValidateUserSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_CDKeyValidateUserExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native validation unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007d454 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_CDKeyValidateUserUnwindMap[3] = {
  {-1, R6GameServiceAddresses::UR6GSServers_CDKeyValidateUserUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};

// Native validation handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007d46c : native storage identity retained.
const R6GameServiceNative::CatchHandler GCDKeyValidateUserHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch106},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch107},
};

// Native validation try record; addresses and states are literal.
// R6GameService.dll data @ 1007d46c : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_CDKeyValidateUserTryMap[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::GCDKeyValidateUserHandlers},
};

// Native validation info record; addresses and states are literal.
// R6GameService.dll data @ 1007d454 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_CDKeyValidateUserExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_CDKeyValidateUserUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_CDKeyValidateUserTryMap,
  0x0,
  0x0,
};

// Submits a base/mod CD key when idle and persists its encrypted text; busy requests only emit diagnostics.
// R6GameService.dll @ 1000d2a0 : exported nonvirtual void(FString), owned12-byte value/RET12.
// Native guards preserve copied registry arguments, encryption return and incoming/local FString lifetimes.
// Offset+0x194 and m_ModGSInfo+0x3c mask0x1 select authorization for an unchanged valid activation key.
__declspec(naked) void __thiscall UR6GSServers::EnterCDKey(FString cdKey)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::EnterCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x3c
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    edi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GActivationState
    test   eax,eax
    mov    BYTE PTR [ebp-0x4],0x2
    jne    Branch228
    mov    eax,ds:R6GameServiceAddresses::GAuthorizationState
    test   eax,eax
    jne    Branch228
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    esi,DWORD PTR ds:0x10093408
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch219
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   esi
    push   R6GameServiceAddresses::WideTextEnterCDKeyYouReInBModProcessD
    push   ecx
    call   ebx
    add    esp,0xc
  Branch219:
    lea    ecx,[ebp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    test   esi,esi
    mov    esi,eax
    je     Branch224
    mov    ecx,R6GameServiceAddresses::GServiceString5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   esi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appStricmpSlot
    add    esp,0x8
    test   eax,eax
    jne    Branch220
    mov    edx,DWORD PTR [edi+0x19c]
    test   BYTE PTR [edx+0x3c],0x1
    je     Branch220
    mov    eax,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [eax+0xb8]
    jmp    Branch221
  Branch220:
    lea    ecx,[ebp+0x8]
    push   ecx
    mov    ecx,R6GameServiceAddresses::GServiceString5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_RequestGSCDKeyActID
  Branch221:
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   R6GameServiceAddresses::GServiceString5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    edx,[ebp-0x48]
    push   edx
    call   R6GameServiceAddresses::EncryptFStringWithUeviLCore
    add    esp,0x10
    push   eax
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x48]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch222
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString5
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString5+0x4
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString5+0x8
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextEnterCDKeyMSzMODCDKeyS
    push   eax
    call   ebx
    mov    edx,DWORD PTR [ebp-0x30]
    mov    eax,DWORD PTR [ebp-0x2c]
    add    esp,0x8
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [ebp-0x28]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextAndEncryptedCDKeyIsS
    push   ecx
    call   ebx
    add    esp,0x14
  Branch222:
    push   R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainment
    lea    ecx,[ebp-0x3c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    eax,DWORD PTR [edx]
    mov    ecx,DWORD PTR [eax+0x34]
    add    ecx,0x94
    push   ecx
    mov    bl,0x4
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot
    sub    esp,0xc
    lea    edx,[ebp-0x30]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   R6GameServiceAddresses::WideTextCDKey
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub    esp,0xc
    lea    eax,[ebp-0x3c]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x20],esp
    push   eax
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__RegSetSlot
    add    esp,0x24
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch223:
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  Branch224:
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   esi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appStricmpSlot
    add    esp,0x8
    test   eax,eax
    jne    Branch225
    test   BYTE PTR [edi+0x194],0x1
    je     Branch225
    mov    edx,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [edx+0xb8]
    jmp    Branch226
  Branch225:
    lea    eax,[ebp+0x8]
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    push   R6GameServiceAddresses::GServiceString8
    mov    ecx,R6GameServiceAddresses::GServiceString9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_RequestGSCDKeyActID
  Branch226:
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x20],esp
    push   R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[ebp-0x48]
    push   ecx
    call   R6GameServiceAddresses::EncryptFStringWithUeviLCore
    add    esp,0x10
    push   eax
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x48]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch227
    mov    eax,ds:R6GameServiceAddresses::GServiceString8
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString8+0x4
    sub    esp,0xc
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,ds:R6GameServiceAddresses::GServiceString8+0x8
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextEnterCDKeyGSzCDKeyS
    push   edx
    call   ebx
    mov    ecx,DWORD PTR [ebp-0x30]
    mov    edx,DWORD PTR [ebp-0x2c]
    add    esp,0x8
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [ebp-0x28]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextAndEncryptedCDKeyIsS
    push   eax
    call   ebx
    add    esp,0x14
  Branch227:
    sub    esp,0xc
    lea    edx,[ebp-0x30]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x20],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   R6GameServiceAddresses::WideTextCDKey
    mov    BYTE PTR [ebp-0x4],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainmentRAVENSHIELD
    mov    BYTE PTR [ebp-0x4],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__RegSetSlot
    add    esp,0x24
    jmp    Branch223
  Branch228:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch223
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextEnterCDKeyUnableToStartAnEnterCDKey
    push   ecx
    call   esi
    mov    eax,ds:R6GameServiceAddresses::GActivationState
    add    esp,0x8
    test   eax,eax
    je     Branch229
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextEnterCDKeyYouReAlreadyInAActIDRequest
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch223
  Branch229:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextEnterCDKeyYouReAlreadyInAAuthIDRequest
    push   edx
    call   esi
    add    esp,0x8
    jmp    Branch223
  }
}

// Destroys the callee-owned incoming CD-key value in the parent argument area.
// R6GameService.dll @ 10063f60 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed local encrypted-text FString.
// R6GameService.dll @ 10063f69 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the mod-path encryption return after successful construction.
// R6GameService.dll @ 10063f72 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed mod registry path.
// R6GameService.dll @ 10063f7b : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the copied encrypted registry value through its saved stack pointer.
// R6GameService.dll @ 10063f84 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed registry value-name argument through its saved stack pointer.
// R6GameService.dll @ 10063f8d : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind7(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the base-game encryption return after successful construction.
// R6GameService.dll @ 10063f96 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the base-game copied encrypted registry value through its saved stack pointer.
// R6GameService.dll @ 10063f9f : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind9(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the base-game constructed registry value-name argument through its saved stack pointer.
// R6GameService.dll @ 10063fa8 : private inherited-EBP FString destructor tail; no own frame or return.
__declspec(naked) void __cdecl EnterCDKeyUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the eleven-state incoming/local/argument FString ownership map for EnterCDKey.
// R6GameService.dll @ 10063fb1 : private exception selector; tail enters the imported CRT frame handler.
__declspec(naked) void __cdecl EnterCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::EnterCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d4bc : selected native exception record.
const R6GameServiceNative::UnwindEntry EnterCDKeyUnwindMap[11] = {
  {-1, R6GameServiceAddresses::EnterCDKeyUnwind1},
  {0x0, 0x0},
  {0x1, R6GameServiceAddresses::EnterCDKeyUnwind3},
  {0x2, R6GameServiceAddresses::EnterCDKeyUnwind4},
  {0x2, R6GameServiceAddresses::EnterCDKeyUnwind5},
  {0x4, R6GameServiceAddresses::EnterCDKeyUnwind6},
  {0x5, R6GameServiceAddresses::EnterCDKeyUnwind7},
  {0x2, R6GameServiceAddresses::EnterCDKeyUnwind8},
  {0x2, R6GameServiceAddresses::EnterCDKeyUnwind9},
  {0x8, R6GameServiceAddresses::EnterCDKeyUnwind10},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007d514 : selected native exception record.
const R6GameServiceNative::CatchHandler GEnterCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -36,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch108},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch109},
};
// R6GameService.dll data @ 1007d534 : selected native exception record.
const R6GameServiceNative::TryBlock EnterCDKeyTryMap[1] = {
  {0x1, 0x9, 0xa, 0x2, R6GameServiceAddresses::GEnterCDKeyHandlers},
};
// R6GameService.dll data @ 1007d548 : selected native exception record.
// R6GameService.dll data @ 1007d4bc : native storage identity retained.
const R6GameServiceNative::FuncInfo EnterCDKeyExceptionInfo = {
  0x19930520,
  0xb,
  R6GameServiceAddresses::EnterCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::EnterCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000d666 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch108(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x24]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::EnterCDKey context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000d67a : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch109(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersEnterCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Evaluates the script string on Stack.Object, consumes debug info, then passes an owned copy to EnterCDKey.
// R6GameService.dll @ 1000d6a0 : exported FFrame&/void* bridge, RET8; Result is not read or written.
// Parsing uses a guarded local; the copied12-byte native argument transfers to EnterCDKey for destruction.
__declspec(naked) void __thiscall UR6GSServers::execEnterCDKey(FFrame &Stack, void * const Result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::execEnterCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    lea    ecx,[ebp-0x24]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    esi,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x24]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR [eax+edx*4]
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne    Branch230
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   0x0
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch230:
    sub    esp,0xc
    lea    eax,[ebp-0x24]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_EnterCDKey
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Destroys the constructed script-argument FString in the dispatcher-supplied parent frame.
// R6GameService.dll @ 10063fc0 : private inherited-EBP cleanup; tail forwards to FString::~FString.
__declspec(naked) void __cdecl execEnterCDKeyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects execEnterCDKey's local argument cleanup and typed/context catch map.
// R6GameService.dll @ 10063fc9 : private exception selector; tail enters the imported CRT frame handler.
__declspec(naked) void __cdecl execEnterCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execEnterCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d564 : selected native exception record.
const R6GameServiceNative::UnwindEntry execEnterCDKeyUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::execEnterCDKeyUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d57c : selected native exception record.
const R6GameServiceNative::CatchHandler GExecEnterCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch110},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch111},
};
// R6GameService.dll data @ 1007d59c : selected native exception record.
const R6GameServiceNative::TryBlock execEnterCDKeyTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GExecEnterCDKeyHandlers},
};
// R6GameService.dll data @ 1007d5b0 : selected native exception record.
// R6GameService.dll data @ 1007d564 : native storage identity retained.
const R6GameServiceNative::FuncInfo execEnterCDKeyExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::execEnterCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::execEnterCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000d751 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch110(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execEnterCDKey context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000d765 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch111(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecEnterCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Loads the base/current-mod key, checks its machine binding, decrypts valid text and records the selected process.
// Nonzero selects the current mod, not a mod index. Successful decoding does not set either validity flag.
// R6GameService.dll @ 1000d790 : virtual void(int), thiscall/RET4; private cache names remain inferred.
void __thiscall UR6GSServers::RequestModCDKeyProcess(int modProcess)
{
  try {
    FString encryptedKey;
    const int selectedProcess = modProcess;
    if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextMODCDKEYREQUESTD,selectedProcess);
    }
    using RegGetABI = int (__cdecl *)(FString,FString,FString &);
    using DecryptABI = FString (__cdecl *)(FString);
    // This logical FString view transfers the same three words consumed by the raw native wrapper.
    using ValidateABI = uint (__cdecl *)(FString);
    if (selectedProcess == 0) {
      // RegGet owns both outgoing strings; its return status is ignored even if it leaves output empty.
      (*(RegGetABI *)R6GameServiceAddresses::Core__RegGetSlot)
          (FString((const TCHAR *)R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainmentRAVENSHIELD),
           FString((const TCHAR *)R6GameServiceAddresses::WideTextCDKey),encryptedKey);
      if (((ValidateABI)R6GameServiceAddresses::IsCDKeyValidOnMachine)(encryptedKey) != 0) {
        FString decrypted = ((DecryptABI)R6GameServiceAddresses::DecryptFStringWithUeviLCore)(encryptedKey);
        *(FString *)R6GameServiceAddresses::GServiceString8 = decrypted;
      } else {
        *(FString *)R6GameServiceAddresses::GServiceString8 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
        *(uint *)((byte *)this + 0x194) &= 0xfffffffe;
      }
    } else {
      FString registryPath((const TCHAR *)R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainment);
      void **modManagerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
      byte *currentMod = *(byte **)((byte *)*modManagerSlot + 0x34);
      registryPath += *(FString *)(currentMod + 0x94);
      (*(RegGetABI *)R6GameServiceAddresses::Core__RegGetSlot)
          (registryPath,FString((const TCHAR *)R6GameServiceAddresses::WideTextCDKey),encryptedKey);
      if (((ValidateABI)R6GameServiceAddresses::IsCDKeyValidOnMachine)(encryptedKey) != 0) {
        FString decrypted = ((DecryptABI)R6GameServiceAddresses::DecryptFStringWithUeviLCore)(encryptedKey);
        *(FString *)R6GameServiceAddresses::GServiceString5 = decrypted;
      } else {
        *(FString *)R6GameServiceAddresses::GServiceString5 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
        // This pointer reload follows validation and cache assignment; it can differ from the earlier current mod.
        byte *modState = *(byte **)((byte *)this + 0x19c);
        *(uint *)(modState + 0x3c) &= 0xfffffffe;
      }
    }
    // The mod path/decryption result is already destroyed; encryptedKey is destroyed after this publication.
    *(int *)0x10093408 = selectedProcess;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersRequestModCDKeyProcess);
    throw;
  }
}

// Destroys the constructed registry-output FString in the dispatcher-supplied parent frame.
// R6GameService.dll @ 10063fe0 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed base registry name argument through its saved pointer.
// R6GameService.dll @ 10063fe9 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed base decryption return before leaving its owning state.
// R6GameService.dll @ 10063ff2 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x34]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed current-mod registry path.
// R6GameService.dll @ 10063ffb : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x34]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the constructed mod registry name argument through its saved pointer.
// R6GameService.dll @ 10064004 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed mod decryption return before leaving its owning state.
// R6GameService.dll @ 1006400d : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl RequestModCDKeyProcessUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects RequestModCDKeyProcess's eight-state local/argument/decryption ownership and catch map.
// R6GameService.dll @ 10064016 : private exception selector; preserves literal metadata and CRT tail ABI.
__declspec(naked) void __cdecl RequestModCDKeyProcessSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::RequestModCDKeyProcessExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d5cc : selected native ownership/guard record.
const R6GameServiceNative::UnwindEntry RequestModCDKeyProcessUnwindMap[8] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::RequestModCDKeyProcessUnwind2},
  {0x1, R6GameServiceAddresses::RequestModCDKeyProcessUnwind3},
  {0x1, R6GameServiceAddresses::RequestModCDKeyProcessUnwind4},
  {0x1, R6GameServiceAddresses::RequestModCDKeyProcessUnwind5},
  {0x4, R6GameServiceAddresses::RequestModCDKeyProcessUnwind6},
  {0x4, R6GameServiceAddresses::RequestModCDKeyProcessUnwind7},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d60c : selected native ownership/guard record.
const R6GameServiceNative::CatchHandler GRequestModCDKeyProcessHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch112},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch113},
};
// R6GameService.dll data @ 1007d62c : selected native ownership/guard record.
// R6GameService.dll data @ 1007d60c : native storage identity retained.
const R6GameServiceNative::TryBlock RequestModCDKeyProcessTryMap[1] = {
  {0x0, 0x6, 0x7, 0x2, R6GameServiceAddresses::GRequestModCDKeyProcessHandlers},
};
// R6GameService.dll data @ 1007d640 : selected native ownership/guard record.
// R6GameService.dll data @ 1007d5cc : native storage identity retained.
const R6GameServiceNative::FuncInfo RequestModCDKeyProcessExceptionInfo = {
  0x19930520,
  0x8,
  R6GameServiceAddresses::RequestModCDKeyProcessUnwindMap,
  0x1,
  R6GameServiceAddresses::RequestModCDKeyProcessTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000d9a4 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch112(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RequestModCDKeyProcess context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000d9b8 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch113(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRequestModCDKeyProcess
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Drains RS replies before mod replies, appending seven-word snapshots before consuming each eight-word SDK record.
// R6GameService.dll @ 1000ee80 : void(void), thiscall; +68/+74 are the selected-build response arrays.
void __thiscall UR6GSServers::ReceiveValidation(void)
{
  using AssertABI = void (__cdecl *)(const char *,const char *,int);
  AssertABI assertion = *(AssertABI *)R6GameServiceAddresses::Core__appFailAssertSlot;
  using AddABI = int (__thiscall *)(FArray *,int,int);
  using RemoveABI = void (__thiscall *)(FArray *,int,int,int);
  try {
    { // RS: queue pointer/count and destination data remain live through append/assert/remove callbacks.
      FArray *queue = (FArray *)R6GameServiceAddresses::GServiceArray8;
      while (*(int *)((byte *)queue + 4) > 0) {
        FArray *destination = (FArray *)((byte *)this + 0x68);
        uint recordOffset = (uint)(*(AddABI *)R6GameServiceAddresses::Core_FArray_AddSlot)(destination,1,0x1c) * 0x1c;
        uint requestId = *(uint *)(*(byte **)queue + 4);
        *(uint *)(*(byte **)destination + recordOffset) = requestId;
        byte status = **(byte **)queue;
        *(byte *)(*(byte **)destination + recordOffset + 4) = status;
        byte *data = *(byte **)destination;
        uint success = *(uint *)(*(byte **)queue + 8);
        uint *flags = (uint *)(data + recordOffset + 8);
        uint changed = (success ^ *flags) & 1;
        *flags ^= changed;
        uint timeout = *(uint *)(*(byte **)queue + 0xc);
        flags = (uint *)(*(byte **)destination + recordOffset + 8);
        changed = ((timeout << 1) ^ *flags) & 2;
        *flags ^= changed;
        // Keep padding and upper flag bits; the ID is four forward DWORD transfers, preserving overlap effects.
        const uint *sourceId = (const uint *)(*(byte **)queue + 0x10);
        uint *destinationId = (uint *)(*(byte **)destination + recordOffset + 0xc);
        destinationId[0] = sourceId[0];
        destinationId[1] = sourceId[1];
        destinationId[2] = sourceId[2];
        destinationId[3] = sourceId[3];
        if (*(int *)((byte *)queue + 4) < 0)
          assertion((const char *)R6GameServiceAddresses::TextIndexArrayNum,
              (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x202);
        if (*(int *)((byte *)queue + 4) < 1)
          assertion((const char *)R6GameServiceAddresses::TextIndexCountArrayNum,
              (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x203);
        // The native retains a one-element empty destruction loop for this trivial SDK record.
        for (int discarded = 0; discarded < 1; ++discarded) {}
        (*(RemoveABI *)R6GameServiceAddresses::Core_FArray_RemoveSlot)(queue,0,1,0x20);
      }
    }
    { // Mod: queue pointer/count and destination data remain live through append/assert/remove callbacks.
      FArray *queue = (FArray *)R6GameServiceAddresses::GServiceArray7;
      while (*(int *)((byte *)queue + 4) > 0) {
        FArray *destination = (FArray *)((byte *)this + 0x74);
        uint recordOffset = (uint)(*(AddABI *)R6GameServiceAddresses::Core_FArray_AddSlot)(destination,1,0x1c) * 0x1c;
        uint requestId = *(uint *)(*(byte **)queue + 4);
        *(uint *)(*(byte **)destination + recordOffset) = requestId;
        byte status = **(byte **)queue;
        *(byte *)(*(byte **)destination + recordOffset + 4) = status;
        byte *data = *(byte **)destination;
        uint success = *(uint *)(*(byte **)queue + 8);
        uint *flags = (uint *)(data + recordOffset + 8);
        uint changed = (success ^ *flags) & 1;
        *flags ^= changed;
        uint timeout = *(uint *)(*(byte **)queue + 0xc);
        flags = (uint *)(*(byte **)destination + recordOffset + 8);
        changed = ((timeout << 1) ^ *flags) & 2;
        *flags ^= changed;
        // Keep padding and upper flag bits; the ID is four forward DWORD transfers, preserving overlap effects.
        const uint *sourceId = (const uint *)(*(byte **)queue + 0x10);
        uint *destinationId = (uint *)(*(byte **)destination + recordOffset + 0xc);
        destinationId[0] = sourceId[0];
        destinationId[1] = sourceId[1];
        destinationId[2] = sourceId[2];
        destinationId[3] = sourceId[3];
        if (*(int *)((byte *)queue + 4) < 0)
          assertion((const char *)R6GameServiceAddresses::TextIndexArrayNum,
              (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x202);
        if (*(int *)((byte *)queue + 4) < 1)
          assertion((const char *)R6GameServiceAddresses::TextIndexCountArrayNum,
              (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x203);
        // The native retains a one-element empty destruction loop for this trivial SDK record.
        for (int discarded = 0; discarded < 1; ++discarded) {}
        (*(RemoveABI *)R6GameServiceAddresses::Core_FArray_RemoveSlot)(queue,0,1,0x20);
      }
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersReceiveValidation);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000f08e : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch116(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ReceiveValidation context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000f0a2 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch117(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersReceiveValidation
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select validation-drain guard metadata and tail-enter the CRT frame handler.
// R6GameService.dll @ 100640e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ReceiveValidationSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ReceiveValidationExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native validation-drain unwind record; literal addresses and states.
// R6GameService.dll data @ 1007d7a8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ReceiveValidationUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native validation-drain handlers record; literal addresses and states.
// R6GameService.dll data @ 1007d7b8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GReceiveValidationHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch116},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch117},
};

// Native validation-drain try record; literal addresses and states.
// R6GameService.dll data @ 1007d7b8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ReceiveValidationTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GReceiveValidationHandlers},
};

// Native validation-drain info record; literal addresses and states.
// R6GameService.dll data @ 1007d7a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ReceiveValidationExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ReceiveValidationUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ReceiveValidationTryMap,
  0x0,
  0x0,
};

// Publishes callback context, then fills each nonnull SDK context callback set in native order.
// R6GameService.dll @ 1000f0d0 : C++ callback publication/installation with native argument timing and RET12.
__declspec(naked) void __thiscall UR6GSServers::registerCDKeySDKCallbacks
    (UR6GSServers *callbackContext,void *rsHandle,void *modHandle)
{
  byte *nativeFrame;
  __asm {
    mov    nativeFrame,esp
  }
  UR6GSServers *callbackOwner = *(UR6GSServers **)(nativeFrame + 4);
  __asm {
    push   esi
  }
  void *rsContext = *(void **)(nativeFrame + 8);
  *(UR6GSServers **)0x10091c18 = callbackOwner;
  using RegisterABI = uint (__stdcall *)(void *,uint);
  if (rsContext != nullptr) {
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtC8)
        (rsContext,R6GameServiceAddresses::ReceiveActivationReply);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtD0)
        (rsContext,R6GameServiceAddresses::RcvValidationResponse);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtCC)
        (rsContext,R6GameServiceAddresses::ReceiveAuthorizationReply);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtD4)
        (rsContext,R6GameServiceAddresses::OnRSPlayerStatusRequest);
  }
  void *modContext = *(void **)(nativeFrame + 0xc);
  if (modContext != nullptr) {
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtC8)
        (modContext,R6GameServiceAddresses::ReceiveActivationReply);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtD0)
        (modContext,R6GameServiceAddresses::RcvModValidationResponse);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtCC)
        (modContext,R6GameServiceAddresses::ReceiveAuthorizationReply);
    ((RegisterABI)R6GameServiceAddresses::thunk_SetContextCallbackAtD4)
        (modContext,R6GameServiceAddresses::OnModPlayerStatusRequest);
  }
  __asm {
    pop    esi
    ret    0xc
  }
}

// Tries consecutive full-width ports under the live signed retry budget, then installs SDK callbacks if RS is ready.
// R6GameService.dll @ 1000f1e0 : void(int,int), thiscall/RET8; flag and budget storage names are inferred.
void __thiscall UR6GSServers::InitCDKey(int rsStartingPort,int modStartingPort)
{
  uint initialRS = *(uint *)0x10093410;
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  try {
    if (initialRS == 0) {
      uint start = (uint)rsStartingPort;
      uint attempt = 0;
      while ((int)attempt < *(int *)0x100933d0 && *(uint *)0x10093410 == 0) {
        void *context = CreateValidatedCDKeyContext(start + attempt);
        *(void **)R6GameServiceAddresses::GBaseCDKeyContext = context;
        uint initialized = context != 0;
        uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
        *(uint *)0x10093410 = initialized;
        if (verbose != 0 && initialized != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyInitializeI,start + attempt);
        ++attempt;
      }
      if (*(void **)R6GameServiceAddresses::GBaseCDKeyContext == 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyInitializeFailed);
    }
    uint modReady = *(uint *)0x100933cc;
    if (modReady == 0) {
      uint start = (uint)modStartingPort;
      uint attempt = 0;
      // Unlike RS, this loop retains EAX's local status except after the success diagnostic.
      while ((int)attempt < *(int *)0x100933d0 && modReady == 0) {
        void *context = CreateValidatedCDKeyContext(start + attempt);
        uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
        uint initialized = context != 0;
        *(void **)R6GameServiceAddresses::GModCDKeyContext = context;
        modReady = initialized;
        *(uint *)0x100933cc = modReady;
        if (verbose != 0 && modReady != 0) {
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyInitializeI,start + attempt);
          modReady = *(uint *)0x100933cc;
        }
        ++attempt;
      }
      if (*(void **)R6GameServiceAddresses::GModCDKeyContext == 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyInitializeFailed);
    }
    if (*(uint *)0x10093410 != 0) {
      void *modContext = *(void **)R6GameServiceAddresses::GModCDKeyContext;
      void *rsContext = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
      registerCDKeySDKCallbacks(this,rsContext,modContext);
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersInitCDKeySDK);
    throw;
  }
}

// Selects InitCDKey private catches; both guard states have no local cleanup actions.
// R6GameService.dll @ 10064110 : private metadata selector; exact raw CRT forwarding ABI.
__declspec(naked) void __cdecl InitCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d82c : selected native guard record.
const R6GameServiceNative::UnwindEntry InitCDKeyUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007d83c : selected native guard record.
const R6GameServiceNative::CatchHandler GInitCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch118},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch119},
};
// R6GameService.dll data @ 1007d85c : selected native guard record.
const R6GameServiceNative::TryBlock InitCDKeyTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitCDKeyHandlers},
};
// R6GameService.dll data @ 1007d870 : selected native guard record.
// R6GameService.dll data @ 1007d82c : native storage identity retained.
const R6GameServiceNative::FuncInfo InitCDKeyExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::InitCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000f342 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch118(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitCDKeySDK context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000f356 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch119(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitCDKeySDK
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Gets the script port-search budget, initializes networking if needed, then requires both key contexts to be ready.
// R6GameService.dll @ 1000f380 : virtual int(void), thiscall; script event lookup precedes the vtable reload.
int __thiscall UR6GSServers::InitGSCDKey(void)
{
  uint eventName = *(uint *)0x10092400; // Exported R6GAMESERVICE_GetMaxAvailPorts FName word.
  try {
    int maxPorts = 0;
    using FindABI = UFunction *(__thiscall *)(UR6GSServers *,uint,int);
    UFunction *function = (*(FindABI *)R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot)(this,eventName,0);
    using ProcessEventABI = void (__thiscall *)(UR6GSServers *,UFunction *,void *,void *);
    ((ProcessEventABI)(*(uint **)this)[0x10 / 4])(this,function,&maxPorts,0);
    uint networkInitialized = *(uint *)R6GameServiceAddresses::GMSClientInitialized;
    *(int *)0x100933d0 = maxPorts;
    if (networkInitialized == 0) {
      // Construct the hidden result directly in the outgoing by-value argument; Init owns its destruction.
      using LocalIpABI = FString (__thiscall *)(UR6GSServers *);
      using InitABI = void (__thiscall *)(UR6GSServers *,FString);
      ((InitABI)R6GameServiceAddresses::UR6GSServers_Init)
          (this,((LocalIpABI)R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr)(this));
    }
    int modPort = *(int *)((byte *)this + 0x188);
    int rsPort = *(int *)((byte *)this + 0x184);
    InitCDKey(rsPort,modPort);
    if (*(uint *)0x10093410 == 0)
      return 0;
    return *(uint *)0x100933cc != 0 ? 1 : 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersInitGSCDKey);
    throw;
  }
}

// Selects InitGSCDKey private catches; both guard states have no local cleanup actions.
// R6GameService.dll @ 10064120 : private metadata selector; exact raw CRT forwarding ABI.
__declspec(naked) void __cdecl InitGSCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitGSCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d88c : selected native guard record.
const R6GameServiceNative::UnwindEntry InitGSCDKeyUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007d89c : selected native guard record.
const R6GameServiceNative::CatchHandler GInitGSCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch120},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch121},
};
// R6GameService.dll data @ 1007d8bc : selected native guard record.
const R6GameServiceNative::TryBlock InitGSCDKeyTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitGSCDKeyHandlers},
};
// R6GameService.dll data @ 1007d8d0 : selected native guard record.
// R6GameService.dll data @ 1007d88c : native storage identity retained.
const R6GameServiceNative::FuncInfo InitGSCDKeyExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::InitGSCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::InitGSCDKeyTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000f446 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch120(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x18]
    push   ecx
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitGSCDKey context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000f45a : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch121(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitGSCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Drains queued four-string player records through RS/optional Mod disconnects, destruction, removal and polling.
// R6GameService.dll @ 1000f480 : exported void(void); native frame preserves buffer overlap and record unwinding.
__declspec(naked) void __thiscall UR6GSServers::DisconnectAllCDKeyPlayers(void)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::DisconnectAllCDKeyPlayersSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10c
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using SendABI = uint (__stdcall *)(void *,void *,byte *);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using AssertABI = void (__cdecl *)(const char *,const char *,int);
  using DestroyABI = void (__thiscall *)(FStringNoInit *);
  using RemoveABI = void (__thiscall *)(void *,int,int,int);
  using PumpABI = uint (__stdcall *)(void *,int);
  *(uint *)(nativeFrame - 4) = 0;
  const char *source = (const char *)0x10091c28;
  char *endpoint = (char *)(nativeFrame - 0x118);
  char *destination = endpoint;
  char character;
  do {
    character = *source++;
    *destination++ = character;
  } while (character != 0);
  *(ushort *)(nativeFrame - 0x96) = *(ushort *)0x10091c04;
  if (*(uint *)0x10093410 != 0) {
    FArray *players = (FArray *)R6GameServiceAddresses::GServiceArray5;
    while (*(int *)((byte *)players + 4) > 0) {
      byte *data = *(byte **)players;
      const TCHAR *wideId = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
          ((const FString *)(data + 0xc));
      AnsiABI toAnsi = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
      source = toAnsi(wideId);
      char *rsText = (char *)(nativeFrame - 0x58);
      destination = rsText;
      do {
        character = *source++;
        *destination++ = character;
      } while (character != 0);
      byte *rsId = nativeFrame - 0x30;
      for (uint index = 0; index < 40; index += 2) {
        int low = HexDigitToValue(rsText + index + 1);
        int high = HexDigitToValue(rsText + index);
        rsId[index / 2] = (byte)(((byte)high << 4) + (byte)low);
      }
      void *context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
      ((SendABI)R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext)(context,endpoint,rsId);
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        const uint *idWords = (const uint *)(*(byte **)players + 0xc);
        uint text = idWords[0];
        uint count = idWords[1];
        uint capacity = idWords[2];
        FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (logger,(const TCHAR *)R6GameServiceAddresses::WideTextRSDisconnectAllCDKeyPlayersPucAuthIDS,
             text,count,capacity);
      }
      if (*(uint *)0x100933cc != 0) {
        data = *(byte **)players;
        wideId = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)((const FString *)(data + 0x18));
        source = toAnsi(wideId);
        char *modText = (char *)(nativeFrame - 0x80);
        destination = modText;
        do {
          character = *source++;
          *destination++ = character;
        } while (character != 0);
        byte *modId = nativeFrame - 0x94;
        for (uint index = 0; index < 40; index += 2) {
          int low = HexDigitToValue(rsText + index + 1);
          int high = HexDigitToValue(modText + index);
          modId[index / 2] = (byte)(((byte)high << 4) + (byte)low);
        }
        // The mixed Mod decode is discarded: its context receives the possibly overlapped RS buffer.
        context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
        ((SendABI)R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext)(context,endpoint,rsId);
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          const uint *idWords = (const uint *)(*(byte **)players + 0xc);
          uint text = idWords[0];
          uint count = idWords[1];
          uint capacity = idWords[2];
          FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
              (logger,(const TCHAR *)R6GameServiceAddresses::WideTextModDisconnectAllCDKeyPlayersPucAuthIDS,
               text,count,capacity);
        }
      }
      if (*(int *)((byte *)players + 4) < 0)
        (*(AssertABI *)R6GameServiceAddresses::Core__appFailAssertSlot)
            ((const char *)R6GameServiceAddresses::TextIndexArrayNum,
             (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x202);
      if (*(int *)((byte *)players + 4) < 1)
        (*(AssertABI *)R6GameServiceAddresses::Core__appFailAssertSlot)
            ((const char *)R6GameServiceAddresses::TextIndexCountArrayNum,
             (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x203);
      for (uint index = 0; index < 1; ++index) {
        byte *record = *(byte **)players + index * 48;
        *(byte **)(nativeFrame - 0x18) = record;
        *(byte *)(nativeFrame - 4) = 3;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)((FStringNoInit *)(record + 0x24));
        *(byte *)(nativeFrame - 4) = 2;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)((FStringNoInit *)(record + 0x18));
        *(byte *)(nativeFrame - 4) = 1;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)((FStringNoInit *)(record + 0xc));
        *(byte *)(nativeFrame - 4) = 0;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)((FStringNoInit *)record);
      }
      (*(RemoveABI *)R6GameServiceAddresses::Core_FArray_RemoveSlot)(players,0,1,48);
      context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
      uint pumped = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)(context,500);
      if ((byte)pumped == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (logger,(const TCHAR *)R6GameServiceAddresses::WideTextRSGSCDKeyEngineFAILED);
      }
      if (*(uint *)0x100933cc != 0) {
        context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
        pumped = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)(context,500);
        if ((byte)pumped == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
              (logger,(const TCHAR *)R6GameServiceAddresses::WideTextMODGSCDKeyEngineFAILED);
        }
      }
    }
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Destroys the remaining queue-record FStringNoInit at saved record+0x0 during partial destruction.
// R6GameService.dll @ 10064130 : private inherited-EBP/saved-pointer destructor tail; no own frame.
__declspec(naked) void __cdecl DisconnectAllCDKeyPlayersUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the remaining queue-record FStringNoInit at saved record+0xc during partial destruction.
// R6GameService.dll @ 10064139 : private inherited-EBP/saved-pointer destructor tail; no own frame.
__declspec(naked) void __cdecl DisconnectAllCDKeyPlayersUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0xc
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Destroys the remaining queue-record FStringNoInit at saved record+0x18 during partial destruction.
// R6GameService.dll @ 10064145 : private inherited-EBP/saved-pointer destructor tail; no own frame.
__declspec(naked) void __cdecl DisconnectAllCDKeyPlayersUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    add    ecx,0x18
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the queue record's three remaining-string cleanup states and typed/context catches.
// R6GameService.dll @ 10064151 : private exception metadata selector, exact CRT tail ABI.
__declspec(naked) void __cdecl DisconnectAllCDKeyPlayersSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DisconnectAllCDKeyPlayersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d8ec : selected native record-ownership/guard data.
const R6GameServiceNative::UnwindEntry DisconnectAllCDKeyPlayersUnwindMap[5] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::DisconnectAllCDKeyPlayersUnwind2},
  {0x1, R6GameServiceAddresses::DisconnectAllCDKeyPlayersUnwind3},
  {0x2, R6GameServiceAddresses::DisconnectAllCDKeyPlayersUnwind4},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d914 : selected native record-ownership/guard data.
const R6GameServiceNative::CatchHandler GDisconnectAllCDKeyPlayersHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch122},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch123},
};
// R6GameService.dll data @ 1007d934 : selected native record-ownership/guard data.
// R6GameService.dll data @ 1007d914 : native storage identity retained.
const R6GameServiceNative::TryBlock DisconnectAllCDKeyPlayersTryMap[1] = {
  {0x0, 0x3, 0x4, 0x2, R6GameServiceAddresses::GDisconnectAllCDKeyPlayersHandlers},
};
// R6GameService.dll data @ 1007d948 : selected native record-ownership/guard data.
// R6GameService.dll data @ 1007d8ec : native storage identity retained.
const R6GameServiceNative::FuncInfo DisconnectAllCDKeyPlayersExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::DisconnectAllCDKeyPlayersUnwindMap,
  0x1,
  R6GameServiceAddresses::DisconnectAllCDKeyPlayersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000f797 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch122(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::DisconnectAllCDKeyPlayers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000f7ab : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch123(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersDisconnectAllCDKeyPlayers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Removes every matching RS ID, retains the last Mod ID, then sends the requested RS/conditional Mod disconnects.
// R6GameService.dll @ 1000f7e0 : exported void(FString)/RET12; native frame preserves ID overlap and ownership.
__declspec(naked) void __thiscall UR6GSServers::CDKeyDisconnecUser(FString authId)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::CDKeyDisconnecUserSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x114
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using EmptyABI = FString * (__thiscall *)(FString *);
  using EqualABI = int (__thiscall *)(const FString *,const FString *);
  using AssignABI = FString * (__thiscall *)(FString *,const FString *);
  using RemoveABI = uint (__thiscall *)(void *,int,int);
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using SendABI = uint (__stdcall *)(void *,void *,byte *);
  using PumpABI = uint (__stdcall *)(void *,int);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using IdentityABI = uint (__thiscall *)(void *);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame - 4) = 0;
  FString *modAuthId = (FString *)(nativeFrame - 0x1c);
  *(byte *)(nativeFrame - 4) = 1;
  (*(EmptyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(modAuthId);
  *(byte *)(nativeFrame - 4) = 2;
  FArray *players = (FArray *)R6GameServiceAddresses::GServiceArray5;
  uint index = 0;
  bool found = false;
  while ((int)index < *(int *)((byte *)players + 4)) {
    byte *data = *(byte **)players;
    uint offset = index * 48;
    int same = (*(EqualABI *)R6GameServiceAddresses::Core__8FStringSlot)
        ((const FString *)(data + offset + 0xc),(const FString *)(nativeFrame + 8));
    if (same != 0) {
      data = *(byte **)players;
      (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)
          (modAuthId,(const FString *)(data + offset + 0x18));
      ((RemoveABI)R6GameServiceAddresses::RemoveStringRecordRange30)(players,(int)index,1);
      found = true;
    } else {
      ++index;
    }
  }
  if (found) {
    const char *source = (const char *)0x10091c28;
    char *endpoint = (char *)(nativeFrame - 0x120);
    char *destination = endpoint;
    char character;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    *(ushort *)(nativeFrame - 0x9e) = *(ushort *)0x10091c04;
    const TCHAR *wideId = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
        ((const FString *)(nativeFrame + 8));
    AnsiABI toAnsi = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
    source = toAnsi(wideId);
    char *rsText = (char *)(nativeFrame - 0x74);
    destination = rsText;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    byte *rsId = nativeFrame - 0x38;
    for (uint digit = 0; digit < 40; digit += 2) {
      int low = HexDigitToValue(rsText + digit + 1);
      int high = HexDigitToValue(rsText + digit);
      rsId[digit / 2] = (byte)(((byte)high << 4) + (byte)low);
    }
    void *context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
    ((SendABI)R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext)(context,endpoint,rsId);
    context = *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
    uint pumped = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)(context,500);
    if ((byte)pumped == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (logger,(const TCHAR *)R6GameServiceAddresses::WideTextRSGSCDKeyEngineFAILED);
    }
    void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
    void *manager = *managerSlot;
    uint isRavenShield = (*(IdentityABI *)R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot)(manager);
    do {
      if (isRavenShield == 0) {
        wideId = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(modAuthId);
        source = toAnsi(wideId);
        char *modText = (char *)(nativeFrame - 0x9c);
        destination = modText;
        do {
          character = *source++;
          *destination++ = character;
        } while (character != 0);
        byte *modId = nativeFrame - 0x4c;
        for (uint digit = 0; digit < 40; digit += 2) {
          int low = HexDigitToValue(modText + digit + 1);
          int high = HexDigitToValue(modText + digit);
          modId[digit / 2] = (byte)(((byte)high << 4) + (byte)low);
        }
        context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
        ((SendABI)R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext)(context,endpoint,modId);
        context = *(void **)R6GameServiceAddresses::GModCDKeyContext;
        pumped = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)(context,500);
        if ((byte)pumped == 0) {
          if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging == 0) break;
          FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
              (logger,(const TCHAR *)R6GameServiceAddresses::WideTextModGSCDKeyEngineFAILED);
        }
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging == 0) break;
        const uint *idWords = (const uint *)modAuthId;
        uint text = idWords[0];
        uint count = idWords[1];
        uint capacity = idWords[2];
        FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (logger,(const TCHAR *)R6GameServiceAddresses::WideTextCDKeyDisconnecUserModAuthIdS,text,count,capacity);
      }
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        const uint *idWords = (const uint *)(nativeFrame + 8);
        uint text = idWords[0];
        uint count = idWords[1];
        uint capacity = idWords[2];
        FOutputDevice *logger = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (logger,(const TCHAR *)R6GameServiceAddresses::WideTextCDKeyDisconnecUserPucAuthIDS,text,count,capacity);
      }
    } while (false);
  }
  *(byte *)(nativeFrame - 4) = 1;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(modAuthId);
  *(uint *)(nativeFrame - 4) = 0xffffffff;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((FString *)(nativeFrame + 8));
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  }
}

// Destroys the callee-owned incoming authentication-ID FString in the inherited argument area.
// R6GameService.dll @ 10064160 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl CDKeyDisconnecUserUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the last-match Mod authentication-ID FString saved in the inherited local frame.
// R6GameService.dll @ 10064169 : private inherited-EBP FString destructor tail; no own frame or validation.
__declspec(naked) void __cdecl CDKeyDisconnecUserUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects incoming/local FString ownership and typed/context catches for single-ID disconnect.
// R6GameService.dll @ 10064172 : private selector; exact metadata register and CRT tail retained.
__declspec(naked) void __cdecl CDKeyDisconnecUserSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::CDKeyDisconnecUserExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d964 : selected native incoming/local ownership record.
const R6GameServiceNative::UnwindEntry CDKeyDisconnecUserUnwindMap[4] = {
  {-1, R6GameServiceAddresses::CDKeyDisconnecUserUnwind1},
  {0x0, 0x0},
  {0x1, R6GameServiceAddresses::CDKeyDisconnecUserUnwind3},
  {0x0, 0x0},
};
// R6GameService.dll data @ 1007d984 : selected native incoming/local ownership record.
const R6GameServiceNative::CatchHandler GCDKeyDisconnecUserHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -36,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch124},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch125},
};
// R6GameService.dll data @ 1007d9a4 : selected native incoming/local ownership record.
// R6GameService.dll data @ 1007d984 : native storage identity retained.
const R6GameServiceNative::TryBlock CDKeyDisconnecUserTryMap[1] = {
  {0x1, 0x2, 0x3, 0x2, R6GameServiceAddresses::GCDKeyDisconnecUserHandlers},
};
// R6GameService.dll data @ 1007d9b8 : selected native incoming/local ownership record.
// R6GameService.dll data @ 1007d964 : native storage identity retained.
const R6GameServiceNative::FuncInfo CDKeyDisconnecUserExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::CDKeyDisconnecUserUnwindMap,
  0x1,
  R6GameServiceAddresses::CDKeyDisconnecUserTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000faac : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch124(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x24]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x20]
    push   ecx
    mov    DWORD PTR [ebp-0x20],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::CDKeyDisconnecUser context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000fac0 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch125(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersCDKeyDisconnecUser
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Sends the low-byte player status; unknown status also removes every matching RS authorization-ID record.
// R6GameService.dll @ 1000fae0 : void(FString,byte,int), thiscall/RET20; input string is callee-owned.
void __thiscall UR6GSServers::NativeCDKeyPlayerStatusReply(FString authId,byte status,int selector)
{
  try {
    // Preserve the native local layout and unchecked copies: endpoint+0, port+82, text+84, decoded ID+ac (hex).
    byte scratch[0xcc];
    char *endpoint = (char *)scratch;
    const char *source = (const char *)0x10091c28;
    char *destination = endpoint;
    char character;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    *(ushort *)(scratch + 0x82) = *(ushort *)0x10091c04;
    const TCHAR *wideId = *authId;
    using AnsiABI = const char *(__cdecl *)(const TCHAR *);
    source = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wideId);
    char *text = (char *)scratch + 0x84;
    destination = text;
    do {
      character = *source++;
      *destination++ = character;
    } while (character != 0);
    byte *decoded = scratch + 0xac;
    for (uint index = 0; index < 0x28; index += 2) {
      int low = HexDigitToValue(text + index + 1);
      int high = HexDigitToValue(text + index);
      decoded[index / 2] = (byte)(((byte)high << 4) + (byte)low);
    }
    int selected = selector;
    byte replyStatus = status;
    void *context = selected != 0 ? *(void **)R6GameServiceAddresses::GModCDKeyContext
                                 : *(void **)R6GameServiceAddresses::GBaseCDKeyContext;
    using SendABI = uint (__stdcall *)(void *,void *,byte *,uint);
    ((SendABI)R6GameServiceAddresses::thunk_ForwardCompoundDescriptorThroughContext)
        (context,endpoint,decoded,(uint)replyStatus);
    if (replyStatus == 0) {
      // This cleanup always searches RS IDs (+c), including replies sent through the mod context.
      FArray *records = (FArray *)R6GameServiceAddresses::GServiceArray5;
      uint index = 0;
      while ((int)index < *(int *)((byte *)records + 4)) {
        if (*(FString *)(*(byte **)records + index * 0x30 + 0xc) == authId) {
          using RemoveABI = void (__thiscall *)(FArray *,int,int);
          ((RemoveABI)R6GameServiceAddresses::RemoveStringRecordRange30)(records,(int)index,1);
        } else {
          ++index;
        }
      }
    }
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      const uint *words = (const uint *)&authId;
      uint dataWord = words[0], countWord = words[1], capacityWord = words[2];
      using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      if (replyStatus == 0)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::
             WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERUNKNOWNForAuthIdS,
             dataWord,countWord,capacityWord);
      else if (replyStatus == 1)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::
             WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERINVALIDForAuthIdS,
             dataWord,countWord,capacityWord);
      else if (replyStatus == 2)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERVALIDForAuthIdS,
             dataWord,countWord,capacityWord);
      else
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusIForAuthIdS,
             (uint)replyStatus,dataWord,countWord,capacityWord);
    }
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersNativeCDKeyPlayerStatusReply);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000fcf7 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch126(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::NativeCDKeyPlayerStatusReply context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000fd0b : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch127(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersNativeCDKeyPlayerStatusReply
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the owned incoming FString through the inherited parent frame.
// R6GameService.dll @ 10064180 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_NativeCDKeyPlayerStatusReplyUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select player-status guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064189 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_NativeCDKeyPlayerStatusReplySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReplyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native player-status unwind record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d9d4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_NativeCDKeyPlayerStatusReplyUnwindMap[3] = {
  {-1, R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReplyUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};

// Native player-status handlers record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d9ec : native storage identity retained.
const R6GameServiceNative::CatchHandler GPlayerStatusReplyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch126},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch127},
};

// Native player-status try record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d9ec : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_NativeCDKeyPlayerStatusReplyTryMap[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::GPlayerStatusReplyHandlers},
};

// Native player-status info record; addresses and state transitions are literal.
// R6GameService.dll data @ 1007d9d4 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_NativeCDKeyPlayerStatusReplyExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReplyUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReplyTryMap,
  0x0,
  0x0,
};

// Advances base-game or mod validation, preserving full native state/status words and delayed writeback.
// RS request fields are +698/+69c/+6a8/+6ac/+6b0; Mod fields are +6b4/+6b8/+6c4/+6c8/+6cc.
// R6GameService.dll @ 1000fd30 : void(gameInfo,level,playerController,int), thiscall/RET16.
void __thiscall UR6GSServers::ProcessPC_CDKeyRequest(
    AR6AbstractGameInfo *gameInfo,ALevelInfo *level,APlayerController *controller,int selector)
{
  // Snapshot field names are inferred; this is the observed seven-word record, not the 32-byte SDK queue record.
  struct ValidationReply {
    uint requestId;
    byte status;
    byte padding[3];
    uint flags;
    byte globalId[16];
  };
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using ControllerStringABI = FString (__thiscall *)(UR6GSServers *,APlayerController *);
  using NoInitAssignABI = FStringNoInit *(__thiscall *)(FStringNoInit *,const FString *);
  try {
    // Native construction/unwind order: address, rejection message, auth ID, snapshot, PB message.
    FString address;
    FString rejectionMessage;
    FString authenticationId;
    TArray<ValidationReply> replies;
    FString pbMessage;
    byte *player = (byte *)controller;
    if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
      LogCDKeyRequestDiagnostics(controller,0);
    uint state, requestId, secondTry, status;
    if (selector != 0) {
      state = *(uint *)(player + 0x6b4);
      authenticationId = *(FString *)(player + 0x6b8);
      requestId = *(uint *)(player + 0x6c4);
      secondTry = *(uint *)(player + 0x6c8);
      status = *(uint *)(player + 0x6cc);
    } else {
      state = *(uint *)(player + 0x698);
      authenticationId = *(FString *)(player + 0x69c);
      status = *(uint *)(player + 0x6b0);
      requestId = *(uint *)(player + 0x6a8);
      secondTry = *(uint *)(player + 0x6ac);
      if (state != 0)
        *(uint *)(player + 0x6b4) = 0;
    }
    int commitSelector;
    switch (state) {
    case 1: { // ECDKEY_FIRSTPASS
      LogABI firstPassLog;
      if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        using FullNameABI = const TCHAR *(__thiscall *)(UObject *,uint *);
        const TCHAR *name = (*(FullNameABI *)R6GameServiceAddresses::Core_UObject_GetFullNameSlot)(controller,0);
        FOutputDevice *device = GLog;
        firstPassLog = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
        firstPassLog(device,(const TCHAR *)R6GameServiceAddresses::WideTextECDKEYFIRSTPASSForS,name);
      } else {
        firstPassLog = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      }
      if (CastToUNetConnection(*(int *)(player + 0x5b4)) == 0) {
        FString result = ((ControllerStringABI)R6GameServiceAddresses::UR6GSServers_eventGetConsoleStoreIP)
            (this,controller);
        address = result;
      } else {
        using NetworkAddressABI = FString (__thiscall *)(APlayerController *);
        FString result = (*(NetworkAddressABI *)
            R6GameServiceAddresses::Engine_APlayerController_GetPlayerNetworkAddressSlot)(controller);
        address = result;
      }
      {
        FString host = address.Left(address.InStr((const TCHAR *)R6GameServiceAddresses::WideTextPunctuation5,0));
        (*(NoInitAssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
            ((FStringNoInit *)(player + 0x7cc),&host);
      }
      if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        // Logf receives borrowed FString words, without copy construction or ownership transfer.
        const uint *words = (const uint *)&authenticationId;
        firstPassLog(GLog,(const TCHAR *)R6GameServiceAddresses::
            WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMSzAuthorizationIDS,words[0],words[1],words[2]);
        words = (const uint *)(player + 0x7cc);
        firstPassLog(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextAPlayerControllerMSzIpAddrS,
            words[0],words[1],words[2]);
      }
      // Native constructs outgoing FString copies right-to-left; each callee owns its incoming values.
      if (PlayerIsInIDList(authenticationId,*(FString *)(player + 0x7cc),selector) != 0) {
        if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          firstPassLog(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerIsInIDList);
        if (selector == 0) {
          FString global = GetGlobalIdFromPlayerIDList(*(FString *)(player + 0x69c));
          (*(NoInitAssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
              ((FStringNoInit *)(player + 0x7c0),&global);
        }
        state = 4;
      } else {
        if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          firstPassLog(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSCDKeyValidateUser);
        requestId = CDKeyValidateUser(authenticationId,secondTry,selector);
        if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          firstPassLog(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMICDKeyReqIDD,requestId);
        state = 2;
      }
      break;
    }
    case 2: { // ECDKEY_WAITING_FOR_RESPONSE
      using ArrayCopyABI = void *(__thiscall *)(void *,const void *);
      ((ArrayCopyABI)R6GameServiceAddresses::CopySevenWordRecordArray)
          (&replies,(byte *)this + (selector != 0 ? 0x74 : 0x68));
      int index = 0;
      int replyCount;
      bool found = false;
      while (index < (replyCount = replies.Num()) && !found) {
        // Reload snapshot data after callbacks, retaining only the native record index/offset.
        auto reply = [&]() -> ValidationReply & { return ((ValidationReply *)*(void **)&replies)[index]; };
        if (requestId == reply().requestId) {
          uint flags = reply().flags;
          found = true;
          if ((flags & 1) != 0) {
            if (selector == 0) {
              using DefaultActorABI = AActor *(__thiscall *)(UClass *);
              UClass *actorClass = *(UClass **)R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot;
              AActor *defaultActor = (*(DefaultActorABI *)R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot)
                  (actorClass);
              {
                using GlobalTextABI = FString (__thiscall *)(AActor *,byte *);
                FString global = (*(GlobalTextABI *)R6GameServiceAddresses::Engine_AActor_GlobalIDToStringSlot)
                    (defaultActor,reply().globalId);
                (*(NoInitAssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
                    ((FStringNoInit *)(player + 0x7c0),&global);
              }
              using BanABI = uint (__thiscall *)(UR6GSServers *,AR6AbstractGameInfo *,const FString *);
              if (((BanABI)R6GameServiceAddresses::UR6GSServers_eventIsGlobalIDBanned)
                  (this,gameInfo,(const FString *)(player + 0x7c0)) != 0) {
                reply().status = 3;
              } else {
                {
                  FString result = ((ControllerStringABI)
                      R6GameServiceAddresses::UR6GSServers_eventTempGetPBConnectStatus)
                      (this,controller);
                  pbMessage = result;
                }
                if (pbMessage != (const TCHAR *)R6GameServiceAddresses::GEmptyWideText) {
                  reply().status = 4;
                  using KickABI = void (__thiscall *)(APlayerController *,const FString *);
                  (*(KickABI *)R6GameServiceAddresses::Engine_APlayerController_eventClientPBKickedOutMessageSlot)
                      (controller,&pbMessage);
                }
              }
            }
            status = reply().status;
            byte replyStatus = reply().status;
            if (replyStatus == 1 || replyStatus == 0 || replyStatus == 3 || replyStatus == 4) {
              if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
                (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
                    (GLog,(const TCHAR *)R6GameServiceAddresses::
                     WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE);
              state = 3;
            } else {
              if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
                (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
                    (GLog,(const TCHAR *)R6GameServiceAddresses::
                     WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE2);
              state = 4;
            }
          } else if ((flags & 2) != 0 && secondTry != 0) {
            if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
              (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
                  (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextTIMEOUTSecondAttempt);
            secondTry = 0;
            if (OnSameSubNet(*(FString *)(player + 0x7cc)) != 0 ||
                CastToUViewport(*(int *)(player + 0x5b4)) != 0) {
              state = 4;
            } else {
              state = 0;
              status = 0;
              FString timeoutMessage((const TCHAR *)R6GameServiceAddresses::WideTextServerAuthNotResponding);
              using MessageABI = void (__thiscall *)(UR6GSServers *,APlayerController *,const FString *);
              ((MessageABI)R6GameServiceAddresses::UR6GSServers_eventProcessServerMsg)(this,controller,&timeoutMessage);
            }
          } else if ((flags & 2) != 0) {
            if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
              (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
                  (GLog,(const TCHAR *)R6GameServiceAddresses::
                   WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSETIMEOUTFirstAttempt);
            state = 1;
            secondTry = 1;
          } else {
            state = 3;
          }
        }
        ++index;
      }
      // Remove the whole copied snapshot, including unmatched records. Preserve the cached signed count.
      if (replyCount < 0) {
        using AssertABI = void (__cdecl *)(const char *,const char *,int);
        AssertABI assertion = *(AssertABI *)R6GameServiceAddresses::Core__appFailAssertSlot;
        assertion((const char *)R6GameServiceAddresses::TextIndexArrayNum,
            (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x202);
        if (replyCount > replies.Num())
          assertion((const char *)R6GameServiceAddresses::TextIndexCountArrayNum,
              (const char *)R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH,0x203);
      }
      // The native retains an empty element-destruction loop for these trivial seven-word records.
      for (int discarded = 0; discarded < replyCount; ++discarded) {}
      using RemoveABI = void (__thiscall *)(FArray *,int,int,int);
      (*(RemoveABI *)R6GameServiceAddresses::Core_FArray_RemoveSlot)((FArray *)&replies,0,replyCount,0x1c);
      break;
    }
    case 3: { // ECDKEY_NOT_VALID
      rejectionMessage = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
      if (status == 3)
        rejectionMessage = (const TCHAR *)R6GameServiceAddresses::WideTextBannedIP;
      else if (status != 4)
        rejectionMessage = (const TCHAR *)R6GameServiceAddresses::WideTextCDKeyServerRefused;
      using MessageABI = void (__thiscall *)(UR6GSServers *,APlayerController *,const FString *);
      ((MessageABI)R6GameServiceAddresses::UR6GSServers_eventProcessServerMsg)(this,controller,&rejectionMessage);
      state = 0;
      status = 1;
      break;
    }
    case 4: { // ECDKEY_VALID
      commitSelector = selector; // Native saves this selector before the three outgoing copies and their callbacks.
      AddPlayerToIDList(authenticationId,*(FString *)(player + 0x7cc),*(FString *)(player + 0x7c0),commitSelector);
      if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::
             WideTextProcessPCCDKeyRequestECDKEYVALIDMECDKeyStatusECDKEYSTPLAYERVALID);
      state = 0;
      status = 2;
      if (commitSelector == 0) {
        using IsRavenShieldABI = uint (__thiscall *)(void *);
        void **modManagerSlot = *(void ***)R6GameServiceAddresses::Engine__GModMgrSlot;
        if ((*(IsRavenShieldABI *)R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot)
            (*modManagerSlot) == 0)
          *(uint *)(player + 0x6b4) = 1;
      }
      goto CommitRequest;
    }
    }
    commitSelector = selector;
  CommitRequest:
    if (commitSelector != 0) {
      *(uint *)(player + 0x6b4) = state;
      *(FString *)(player + 0x6b8) = authenticationId;
      *(uint *)(player + 0x6c4) = requestId;
      *(uint *)(player + 0x6c8) = secondTry;
      *(uint *)(player + 0x6cc) = status;
    } else {
      *(uint *)(player + 0x698) = state;
      *(FString *)(player + 0x69c) = authenticationId;
      *(uint *)(player + 0x6a8) = requestId;
      *(uint *)(player + 0x6ac) = secondTry;
      *(uint *)(player + 0x6b0) = status;
    }
    if (*(int *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
      LogCDKeyRequestDiagnostics(controller,1);
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersProcessPCCDKeyRequest);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001054a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch128(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x7c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x5c]
    push   edx
    mov    DWORD PTR [ebp-0x5c],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessPC_CDKeyRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1001055e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch129(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessPCCDKeyRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the parent-frame address FString at EBP-58.
// R6GameService.dll @ 100641a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x58]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the parent-frame rejection-message FString at EBP-4c.
// R6GameService.dll @ 100641a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x4c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Release the auth-ID FString at EBP-2c through the native four-byte receiver adjustment.
// R6GameService.dll @ 100641b2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::DestroyFStringAt04
  }
}

// Destroy the parent-frame seven-word reply snapshot at EBP-3c.
// R6GameService.dll @ 100641ba : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage
  }
}

// Destroy the parent-frame PB-message FString at EBP-68.
// R6GameService.dll @ 100641c2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x68]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed console-address result FString at EBP-a0.
// R6GameService.dll @ 100641cb : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0xa0]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed network-address result FString at EBP-c4.
// R6GameService.dll @ 100641d7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0xc4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed Left result FString at EBP-88.
// R6GameService.dll @ 100641e3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x88]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the partially transferred lookup string through the pointer saved at EBP+10.
// R6GameService.dll @ 100641ef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed cached-global-ID result FString at EBP-b8.
// R6GameService.dll @ 100641f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind11(void)
{
  __asm {
    lea    ecx,[ebp-0xb8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed binary-global-ID conversion result FString at EBP-94.
// R6GameService.dll @ 10064204 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed PB-status result FString at EBP-ac.
// R6GameService.dll @ 10064210 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind13(void)
{
  __asm {
    lea    ecx,[ebp-0xac]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the parent-frame timeout-message FString at EBP-74.
// R6GameService.dll @ 1006421c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x74]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the partially transferred global-ID copy through the pointer saved at EBP+14.
// R6GameService.dll @ 10064225 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind15(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x14]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the partially transferred address copy through the pointer saved at EBP+10.
// R6GameService.dll @ 1006422e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestUnwind16(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp+0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select controller-request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064237 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessPC_CDKeyRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native controller-request unwind record; values are literal.
// R6GameService.dll data @ 1007da3c : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessPC_CDKeyRequestUnwindMap[17] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind2},
  {0x1, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind3},
  {0x2, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind4},
  {0x3, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind5},
  {0x4, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind6},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind7},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind8},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind9},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind10},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind11},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind12},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind13},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind14},
  {0x5, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind15},
  {0xe, R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwind16},
  {-1, 0x0},
};

// Native controller-request handlers record; values are literal.
// R6GameService.dll data @ 1007dac4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GPCRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -124,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch128},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch129},
};

// Native controller-request try record; values are literal.
// R6GameService.dll data @ 1007dac4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessPC_CDKeyRequestTryMap[1] = {
  {0x0, 0xf, 0x10, 0x2, R6GameServiceAddresses::GPCRequestHandlers},
};

// Native controller-request info record; values are literal.
// R6GameService.dll data @ 1007da3c : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessPC_CDKeyRequestExceptionInfo = {
  0x19930520,
  0x11,
  R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestTryMap,
  0x0,
  0x0,
};

// Native controller-request dispatch record; values are literal.
// R6GameService.dll data @ 1001057c : native storage identity retained.
const uint GPCRequestDispatch[4] = {  R6GameServiceAddresses::GPCRequestDispatchCase1,R6GameServiceAddresses::GPCRequestDispatchCase2,R6GameServiceAddresses::GPCRequestDispatchCase3,R6GameServiceAddresses::GPCRequestDispatchCase4};

// Matches queued RS/Mod authorization IDs against current controllers, replies, then removes each observed queue range.
// R6GameService.dll @ 10010590 : void(AController*), thiscall/RET4; queue heads/counts and controller links stay live.
void __thiscall UR6GSServers::ProcessAuthIdRequest(AController *controllerChainHead)
{
  UClass *requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
  try {
    FArray *rsQueue = (FArray *)R6GameServiceAddresses::GServiceString7;
    uint index = 0;
    int queueCount;
    while ((int)index < (queueCount = *(int *)((byte *)rsQueue + 4))) {
      AController *node = controllerChainHead;
      bool found = false;
      while (node != 0 && !found) {
        UClass *candidateClass = *(UClass **)((byte *)node + 0x24);
        while (candidateClass != 0 && candidateClass != requiredClass)
          candidateClass = *(UClass **)((byte *)candidateClass + 0x2c);
        if (candidateClass == requiredClass) {
          using IsAABI = int (__thiscall *)(UObject *,UClass *);
          byte *candidate = (*(IsAABI *)R6GameServiceAddresses::Core_UObject_IsASlot)(node,requiredClass) != 0
              ? (byte *)node : 0;
          FString *queuedId = (FString *)(*(byte **)rsQueue + index * 12);
          // A rejected second class check still forms +69c from null, without an extra guard.
          FString *controllerId = (FString *)((uint)candidate + 0x69c);
          if (*controllerId == *queuedId) {
            byte playerStatus = *(byte *)((uint)candidate + 0x6b0);
            NativeCDKeyPlayerStatusReply(*controllerId,playerStatus,0);
            found = true;
          }
          requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
        }
        // Even a successful reply reads nextController before the following found test.
        node = *(AController **)((byte *)node + 0x3dc);
      }
      if (!found) {
        NativeCDKeyPlayerStatusReply(*(FString *)(*(byte **)rsQueue + index * 12),0,0);
        requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
      }
      ++index;
    }
    using RemoveABI = void (__thiscall *)(FArray *,int,int);
    ((RemoveABI)R6GameServiceAddresses::RemoveFStringRange12)(rsQueue,0,queueCount);
    requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
    FArray *modQueue = (FArray *)R6GameServiceAddresses::GServiceString6;
    index = 0;
    while ((int)index < (queueCount = *(int *)((byte *)modQueue + 4))) {
      AController *node = controllerChainHead;
      bool found = false;
      while (node != 0 && !found) {
        UClass *candidateClass = *(UClass **)((byte *)node + 0x24);
        while (candidateClass != 0 && candidateClass != requiredClass)
          candidateClass = *(UClass **)((byte *)candidateClass + 0x2c);
        if (candidateClass == requiredClass) {
          // Mod repeats the ancestry walk inline instead of using the RS path's imported IsA.
          UClass *repeatedClass = *(UClass **)((byte *)node + 0x24);
          while (repeatedClass != 0 && repeatedClass != requiredClass)
            repeatedClass = *(UClass **)((byte *)repeatedClass + 0x2c);
          byte *candidate = repeatedClass == requiredClass ? (byte *)node : 0;
          FString *queuedId = (FString *)(*(byte **)modQueue + index * 12);
          FString *controllerId = (FString *)((uint)candidate + 0x6b8);
          if (*controllerId == *queuedId) {
            byte playerStatus = *(byte *)((uint)candidate + 0x6cc);
            NativeCDKeyPlayerStatusReply(*controllerId,playerStatus,1);
            found = true;
          }
          requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
        }
        node = *(AController **)((byte *)node + 0x3dc);
      }
      if (!found) {
        NativeCDKeyPlayerStatusReply(*(FString *)(*(byte **)modQueue + index * 12),0,1);
        requiredClass = *(UClass **)R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot;
      }
      ++index;
    }
    ((RemoveABI)R6GameServiceAddresses::RemoveFStringRange12)(modQueue,0,queueCount);
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersProcessAuthIdRequest);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100107f5 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch130(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x24]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x20]
    push   ecx
    mov    DWORD PTR [ebp-0x20],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessAuthIdRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10010809 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch131(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessAuthIdRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select auth-ID queue guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064250 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessAuthIdRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessAuthIdRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native auth-ID request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007db14 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessAuthIdRequestUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native auth-ID request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007db24 : native storage identity retained.
const R6GameServiceNative::CatchHandler GAuthIdRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -36,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch130},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch131},
};

// Native auth-ID request try record; addresses and states are literal.
// R6GameService.dll data @ 1007db24 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessAuthIdRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GAuthIdRequestHandlers},
};

// Native auth-ID request info record; addresses and states are literal.
// R6GameService.dll data @ 1007db14 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessAuthIdRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessAuthIdRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessAuthIdRequestTryMap,
  0x0,
  0x0,
};

// Allocate, post and delete the selected loaded-client message, ignoring all three result codes.
// Exported virtual void(unsigned char), unused incoming ECX, low selector byte only, RET4.
// Selectors 0..5 map to message types 1,2,200h,3,4,100h; others only restore the linked exception chain.
// Selector 2 stores current DWORD91bf4 at returned message+8 without a NULL check.
// Each helper checks current module state and current provider slot separately; callbacks may change them.
// Two null-initialized output slots have no unwind cleanup action, so a throwing post is not followed by deletion.
// Current logging gate, receiver and Logf IAT are read only after the delete helper returns.
// R6GameService.dll @ 100109c0 : RET4; two frame output slots have no cleanup action and each provider gate stays live.
__declspec(naked) void __thiscall UR6GSServers::GSClientPostMessage(byte selector)
{
  byte *nativeFrame;
  uint choice;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_GSClientPostMessageSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    movzx  eax,BYTE PTR [ebp+0x8]
    push   ebx
    push   esi
    xor    esi,esi
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],esi
    mov    DWORD PTR [ebp-0x14],esi
    mov    DWORD PTR [ebp-0x18],esi
    mov    nativeFrame,ebp
    mov    choice,eax
  }
  uint rawEax = choice;
  if (choice <= 5) {
    uint kind;
    const TCHAR *diagnostic;
    void **messageSlot = (void **)(nativeFrame - 0x14);
    switch (choice) {
    case 0:
      kind = 1;
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGCHSTAINITMASTERSESSIONAK;
      break;
    case 1:
      kind = 2;
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGCHSTAMASTERSESSIONAK;
      break;
    case 2:
      kind = 0x200;
      messageSlot = (void **)(nativeFrame - 0x18);
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGREADYTORECEIVECONNECTIONS;
      break;
    case 3:
      kind = 3;
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGCHSTAINITCLIENTSESSIONAK;
      break;
    case 4:
      kind = 4;
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGCHSTACLIENTSESSIONAK;
      break;
    case 5:
      kind = 0x100;
      diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextMSGFGSWITCHTOGS;
      break;
    }
    using AllocateABI = uint (__stdcall *)(uint,void **);
    ((AllocateABI)R6GameServiceAddresses::AllocateLoadedGSClientMessage)(kind,messageSlot);
    if (choice == 2) {
      void *message = *messageSlot;
      uint port = *(uint *)0x10091bf4;
      *(uint *)((byte *)message + 8) = port;
    }
    using MessageABI = uint (__stdcall *)(void *);
    ((MessageABI)R6GameServiceAddresses::PostLoadedGSClientMessage)(*messageSlot);
    rawEax = ((MessageABI)R6GameServiceAddresses::DeleteLoadedGSClientMessage)(*messageSlot);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)(device,diagnostic);
    }
  }
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10010b6a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch132(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x1c]
    push   eax
    mov    DWORD PTR [ebp-0x1c],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::GSClientPostMessage context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10010b7e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch133(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersGSClientPostMessage
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    esi,esi
    push   esi
    push   esi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select post-message guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064290 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GSClientPostMessageSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_GSClientPostMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native post-message unwind record; values are literal.
// R6GameService.dll data @ 1007dbb0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_GSClientPostMessageUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native post-message handlers record; values are literal.
// R6GameService.dll data @ 1007dbc0 : native storage identity retained.
const R6GameServiceNative::CatchHandler GPostMessageHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch132},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch133},
};

// Native post-message try record; values are literal.
// R6GameService.dll data @ 1007dbc0 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_GSClientPostMessageTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GPostMessageHandlers},
};

// Native post-message info record; values are literal.
// R6GameService.dll data @ 1007dbb0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_GSClientPostMessageExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_GSClientPostMessageUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_GSClientPostMessageTryMap,
  0x0,
  0x0,
};

// Native post-message dispatch record; values are literal.
// R6GameService.dll data @ 10010b9c : native storage identity retained.
const uint GPostMessageDispatch[6] = {R6GameServiceAddresses::GPostMessageDispatchCase1,R6GameServiceAddresses::GPostMessageDispatchCase2,R6GameServiceAddresses::GPostMessageDispatchCase3,R6GameServiceAddresses::GPostMessageDispatchCase4,R6GameServiceAddresses::GPostMessageDispatchCase5,R6GameServiceAddresses::GPostMessageDispatchCase6};

// Return whether the current full GS state is zero after optional debug-info dispatch.
// Exported exec void(FFrame&,void*), unused incoming ECX, RET8; writes full DWORD 0/1, matching script Bool.
// Code advances before state 0 publication. Only token 42h dispatches via GNatives[42h](Stack.Object,Stack,NULL).
// State and output-argument slot are read after callback; raw offsets and pre-state0 faults retained.
// R6GameService.dll @ 10010f10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeIsWaitingForGSInit(FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeIsWaitingForGSInitSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch373
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch373:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GGSClientState
    xor    eax,eax
    test   ecx,ecx
    mov    ecx,DWORD PTR [ebp+0xc]
    sete   al
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10010f81 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch134(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeIsWaitingForGSInit context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10010f95 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch135(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeIsWaitingForGSInit
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select readiness VM guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100642a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execNativeIsWaitingForGSInitSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeIsWaitingForGSInitExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native readiness VM unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007dc10 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeIsWaitingForGSInitUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native readiness VM handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007dc20 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecNativeIsWaitingForGSInitHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch134},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch135},
};

// Native readiness VM try record; addresses and states are literal.
// R6GameService.dll data @ 1007dc20 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeIsWaitingForGSInitTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeIsWaitingForGSInitHandlers},
};

// Native readiness VM info record; addresses and states are literal.
// R6GameService.dll data @ 1007dc10 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeIsWaitingForGSInitExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeIsWaitingForGSInitUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeIsWaitingForGSInitTryMap,
  0x0,
  0x0,
};

// Return whether the current full GS state is 8 or 2 after optional debug-info dispatch.
// The normal native continuation1104f..1106b lies after private catches; it remains part of this body.
// Exported exec void(FFrame&,void*), unused incoming ECX, RET8; writes full DWORD 0/1, matching script Bool.
// Code advances before state 0 publication. Only token 42h dispatches via GNatives[42h](Stack.Object,Stack,NULL).
// State and output-argument slot are read after callback; raw offsets and pre-state0 faults retained.
// R6GameService.dll @ 10010fc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeIsGSReadyToChangeMod(FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeIsGSReadyToChangeModSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch374
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch374:
    mov    eax,ds:R6GameServiceAddresses::GGSClientState
    cmp    eax,0x8
    je     Branch375
    cmp    eax,0x2
    je     Branch375
    xor    eax,eax
    jmp    Branch376
  Branch375:
    mov    eax,0x1
  Branch376:
    mov    ecx,DWORD PTR [ebp+0xc]
    pop    edi
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001101f : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch136(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeIsGSReadyToChangeMod context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10011033 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch137(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeIsGSReadyToChangeMod
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select readiness VM guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100642b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execNativeIsGSReadyToChangeModSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeIsGSReadyToChangeModExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native readiness VM unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007dc70 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeIsGSReadyToChangeModUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native readiness VM handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007dc80 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecNativeIsGSReadyToChangeModHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch136},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch137},
};

// Native readiness VM try record; addresses and states are literal.
// R6GameService.dll data @ 1007dc80 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeIsGSReadyToChangeModTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeIsGSReadyToChangeModHandlers},
};

// Native readiness VM info record; addresses and states are literal.
// R6GameService.dll data @ 1007dc70 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeIsGSReadyToChangeModExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeIsGSReadyToChangeModUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeIsGSReadyToChangeModTryMap,
  0x0,
  0x0,
};

// Attempt score-service interface acquisition once; any nonzero prior latch returns full int 1 immediately.
// Exported virtual int(void), unused incoming ECX, RET0; latch and temporary role names are inferred.
// Latch 939d8 is set before OLEAUT32 ordinal35(CLSID73074,NULL,&local); local EBP-14 is not precleared.
// Any nonNULL local invokes service slot0 stdcall(service,IID72ff8,&global92ea4), even after failed lookup.
// Negative HRESULTs log unconditionally and make the current result 0. Neither latch nor global is rolled back.
// No service/interface release or local unwind cleanup; a successful NULL lookup can return 1 with no interface.
// R6GameService.dll @ 10011070 : once latch survives failure; native EBP-14 output remains uninitialized before lookup.
__declspec(naked) int __thiscall UR6GSServers::SetGSClientComInterface(void)
{
  byte *nativeFrame;
  uint alreadySet;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SetGSClientComInterfaceSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:0x100939d8
    test   eax,eax
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    nativeFrame,ebp
    mov    alreadySet,eax
  }
  if (alreadySet != 0) {
    __asm {
      mov    eax,0x1
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  }
  uint output = 1;
  *(uint *)0x100939d8 = 1;
  using LookupABI = uint (__stdcall *)(const void *,void *,void **);
  uint status = (*(LookupABI *)R6GameServiceAddresses::OLEAUT32_GetActiveObjectSlot)
      ((const void *)0x10073074,nullptr,(void **)(nativeFrame - 0x14));
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  if ((int)status < 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextCannotFindTheScoreSubmissionServiceHResX,status);
    output = 0;
  }
  void *service = *(void **)(nativeFrame - 0x14);
  if (service != nullptr) {
    byte *table = *(byte **)service;
    using QueryABI = uint (__stdcall *)(void *,const void *,void **);
    status = (*(QueryABI *)table)(service,(const void *)0x10072ff8,
        (void **)R6GameServiceAddresses::GGSClientInterface);
    if ((int)status < 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextCannotFindTheScoreSubmissionService);
      output = 0;
    }
  }
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10011137 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch138(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::SetGSClientComInterface context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1001114b : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch139(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersSetGSClientComInterface
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select score-interface guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100642c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SetGSClientComInterfaceSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_SetGSClientComInterfaceExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native score-interface unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007dcd0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_SetGSClientComInterfaceUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native score-interface handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007dce0 : native storage identity retained.
const R6GameServiceNative::CatchHandler GSetGSClientComInterfaceHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch138},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch139},
};

// Native score-interface try record; addresses and states are literal.
// R6GameService.dll data @ 1007dce0 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_SetGSClientComInterfaceTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GSetGSClientComInterfaceHandlers},
};

// Native score-interface info record; addresses and states are literal.
// R6GameService.dll data @ 1007dcd0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_SetGSClientComInterfaceExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_SetGSClientComInterfaceUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_SetGSClientComInterfaceTryMap,
  0x0,
  0x0,
};

// Publish mode 1 copies of the current public/private byte stores through the acquired config interface.
// Exported nonvirtual void(void), unused incoming ECX, RET0; locals and interface roles inferred.
// Service/config words at EBP-18/-14 start NULL under state 2. Config slot 4 is called before VariantInit.
// Variant EBP-30 has no EH cleanup. HRESULT failures only gate logs; both sets and normal clears continue.
// Logf is cached after lookup; parent VariantClear is cached before public clear, while the copy helper
// reloads its own imports. Current data globals and pointer words are read again at each native use.
// Normal cleanup lowers state before config slot 8, then service slot 8. No retry of in-progress releases.
// R6GameService.dll @ 10011820 : current interface words and native guard slots; no VARIANT unwind action.
__declspec(naked) void __thiscall UR6GSServers::GSClientUpdateServerInfo(void)
{
  byte *nativeFrame;
  uint rawEax;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push   ebx
    push   esi
    xor    ebx,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ebx
    mov    DWORD PTR [ebp-0x18],ebx
    mov    DWORD PTR [ebp-0x14],ebx
    lea    eax,[ebp-0x18]
    push   eax
    push   ebx
    push   0x10073c54
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_GetActiveObjectSlot
    mov    nativeFrame,ebp
    mov    rawEax,eax
  }
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger;
  if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCannotFindTheGameConfigService);
  } else logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  void *service = *(void **)(nativeFrame - 0x18);
  if (service != nullptr) {
    byte *table = *(byte **)service;
    using QueryABI = uint (__stdcall *)(void *,const void *,void **);
    rawEax = (*(QueryABI *)table)(service,(const void *)0x10073bf0,(void **)(nativeFrame - 0x14));
    if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextCannotFindTheInterfaceForGameConfigService);
    }
    service = *(void **)(nativeFrame - 0x18);
  }
  void *config = *(void **)(nativeFrame - 0x14);
  if (config != nullptr) {
    byte *table = *(byte **)config;
    using RefABI = uint (__stdcall *)(void *);
    (*(RefABI *)(table + 4))(config);
    void *variant = nativeFrame - 0x30;
    using InitABI = void (__stdcall *)(void *);
    (*(InitABI *)R6GameServiceAddresses::OLEAUT32_VariantInitSlot)(variant);
    using CopyABI = uint (__thiscall *)(void *,void *,uint);
    void *store = *(void **)R6GameServiceAddresses::GPublicSerializedStore;
    rawEax = ((CopyABI)R6GameServiceAddresses::CopyStoredBytesToVariant)(store,variant,1);
    if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGetCopyPublicError);
    }
    config = *(void **)(nativeFrame - 0x14);
    table = *(byte **)config;
    using SetABI = uint (__stdcall *)(void *,void *);
    rawEax = (*(SetABI *)(table + 0x1c))(config,variant);
    if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextSetPublicGameConfigError);
    }
    using ClearABI = uint (__stdcall *)(void *);
    ClearABI clear = *(ClearABI *)R6GameServiceAddresses::OLEAUT32_VariantClearSlot;
    clear(variant);
    store = *(void **)R6GameServiceAddresses::GPrivateSerializedStore;
    rawEax = ((CopyABI)R6GameServiceAddresses::CopyStoredBytesToVariant)(store,variant,1);
    if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGetCopyPrivateError);
    }
    config = *(void **)(nativeFrame - 0x14);
    table = *(byte **)config;
    rawEax = (*(SetABI *)(table + 0x24))(config,variant);
    if ((int)rawEax < 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextSetPrivateGameConfigError);
    }
    clear(variant);
    service = *(void **)(nativeFrame - 0x18);
    config = *(void **)(nativeFrame - 0x14);
  }
  rawEax = (uint)config;
  bool hasConfig = config != nullptr;
  *(byte *)(nativeFrame - 4) = 1;
  if (hasConfig) {
    byte *table = *(byte **)config;
    using ReleaseABI = uint (__stdcall *)(void *);
    rawEax = (*(ReleaseABI *)(table + 8))(config);
    service = *(void **)(nativeFrame - 0x18);
  }
  bool hasService = service != nullptr;
  *(byte *)(nativeFrame - 4) = 0;
  if (hasService) {
    byte *table = *(byte **)service;
    using ReleaseABI = uint (__stdcall *)(void *);
    rawEax = (*(ReleaseABI *)(table + 8))(service);
  }
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100119db : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch142(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x1c]
    push   ecx
    mov    DWORD PTR [ebp-0x1c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::GSClientUpdateServerInfo context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100119ef : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch143(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersGSClientUpdateServerInfo
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Release the current service pointer word at inherited EBP-18 through its native slot8 helper.
// R6GameService.dll @ 100642f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GSClientUpdateServerInfoUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::CallThirdSlotForFirstWordObject
  }
}

// Release the current config pointer word at inherited EBP-14 through its native slot8 helper.
// R6GameService.dll @ 100642f8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GSClientUpdateServerInfoUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x14]
    jmp    R6GameServiceAddresses::CallThirdSlotForFirstWordObject
  }
}

// Select server-info guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064300 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_GSClientUpdateServerInfoSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native server-info unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007dd98 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_GSClientUpdateServerInfoUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoUnwind2},
  {0x1, R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoUnwind3},
  {-1, 0x0},
};

// Native server-info handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007ddb8 : native storage identity retained.
const R6GameServiceNative::CatchHandler GServerInfoHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch142},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch143},
};

// Native server-info try record; addresses and states are literal.
// R6GameService.dll data @ 1007ddd8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_GSClientUpdateServerInfoTryMap[1] = {
  {0x0, 0x2, 0x3, 0x2, R6GameServiceAddresses::GServerInfoHandlers},
};

// Native server-info info record; addresses and states are literal.
// R6GameService.dll data @ 1007ddec : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_GSClientUpdateServerInfoExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfoTryMap,
  0x0,
  0x0,
};

// Load/initialize the client, then connect with a 12-byte stack descriptor only for nonnegative status.
// Exported virtual int(void), unused incoming ECX, RET0; result is full int 0/1 from signed HRESULT tests.
// Descriptor at EBP-24 is zeroed before initialize, then receives 12, callback11b10 and context0 before connect.
// No descriptor owner/cleanup action: provider retention or callback execution remains external.
// Logging gates/receiver/Logf are current after each operation; initialization success is saved across logging.
// An already-loaded library returns a negative helper status, so this parent skips connect and returns 0.
// R6GameService.dll @ 10011ec0 : full int result; signed provider statuses and native retained descriptor words.
__declspec(naked) int __thiscall UR6GSServers::InitGSClient(void)
{
  byte *nativeFrame;
  uint status;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_InitGSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    xor    eax,eax
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x24],eax
    mov    DWORD PTR [ebp-0x20],eax
    mov    DWORD PTR [ebp-0x10],esp
    push   eax
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x1c],eax
    call   R6GameServiceAddresses::LoadAndInitializeGSClient
    mov    nativeFrame,ebp
    mov    status,eax
  }
  uint output = (int)status >= 0;
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientSPWGSCInitializeI,output);
  }
  if (output != 0) {
    *(uint *)(nativeFrame - 0x24) = 12;
    *(uint *)(nativeFrame - 0x20) = R6GameServiceAddresses::DispatcherProc;
    *(uint *)(nativeFrame - 0x1c) = 0;
    using ConnectABI = uint (__stdcall *)(void *,uint);
    status = ((ConnectABI)R6GameServiceAddresses::ConnectLoadedGSClient)(nativeFrame - 0x24,0);
    output = (int)status >= 0;
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientSPWGSCConnectI,output);
    }
  }
  __asm {
    mov    esi,output
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10011f83 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch144(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitGSClient context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10011f97 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch145(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitGSClient
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select client-init guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064330 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_InitGSClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_InitGSClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native client-init unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007de34 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_InitGSClientUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native client-init handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007de44 : native storage identity retained.
const R6GameServiceNative::CatchHandler GInitGSClientHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch144},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch145},
};

// Native client-init try record; addresses and states are literal.
// R6GameService.dll data @ 1007de44 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitGSClientTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitGSClientHandlers},
};

// Native client-init info record; addresses and states are literal.
// R6GameService.dll data @ 1007de34 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_InitGSClientExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_InitGSClientUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_InitGSClientTryMap,
  0x0,
  0x0,
};

// Return the full registration initialization word; no receiver access, normalization or side effect.
// Exported virtual int(void), RET0; global role name is descriptive.
// R6GameService.dll @ 10011fc0 : complete native control/access order and raw ABI retained.
int __thiscall UR6GSServers::GetRegServerInitialized(void)
{
  return *reinterpret_cast<const int *>(0x10093b08);
}

// Close the active lobby and registration service, clear their flags, then always log logout through the cached logger.
// R6GameService.dll @ 10011fd0 : no local guard; cached Logf, live logging gates and late unconditional logout diagnostic.
void __thiscall UR6GSServers::UnInitRegServer(void)
{
  uint initialized = *(uint *)0x10093b08;
  if (initialized != 0) {
    uint lobbyActive = *(uint *)0x100939ec;
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    if (lobbyActive != 0) {
      ((byte (__cdecl *)(void))R6GameServiceAddresses::CloseLobbyServerConnection)();
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        logger(device,
            (const TCHAR *)R6GameServiceAddresses::WideTextREGSERVERRegServerSendLobbyServerCloseFromUR6GSServersUnInitRegServer);
      }
    }
    ((bool (__cdecl *)(void))R6GameServiceAddresses::UninitializeRegistrationService)();
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextREGSERVERRegServerLibraryUninitialize);
    }
    FOutputDevice **deviceSlot = *(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    *(uint *)0x100939ec = 0;
    *(uint *)0x10093b08 = 0;
    FOutputDevice *device = *deviceSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextLoggedOffFromUbiComRegServerService);
  }
}


// Clear lobby/group IDs, shut down registration, then clear the remaining state only on normal return.
// R6GameService.dll @ 10012060 : ID clears precede shutdown; remaining state clears only on its normal return.
void __thiscall UR6GSServers::LogOutServer(void)
{
  try {
    *(uint *)R6GameServiceAddresses::GSecondaryLobbyServerId = 0;
    *(uint *)R6GameServiceAddresses::GSecondaryGroupId = 0;
    UnInitRegServer();
    *(uint *)0x10091bd8 = 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersLogOutServer);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100120ae : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch146(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::LogOutServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100120c2 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch147(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersLogOutServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    esi,esi
    push   esi
    push   esi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select logout guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064340 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_LogOutServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_LogOutServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native logout unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007de94 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_LogOutServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native logout handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007dea4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GLogOutServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch146},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch147},
};

// Native logout try record; addresses and states are literal.
// R6GameService.dll data @ 1007dec4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_LogOutServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GLogOutServerHandlers},
};

// Native logout info record; addresses and states are literal.
// R6GameService.dll data @ 1007ded8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_LogOutServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_LogOutServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_LogOutServerTryMap,
  0x0,
  0x0,
};

// Decode replication info, clear both current ID destinations without null checks, then log out; the result is unused.
// R6GameService.dll @ 100120e0 : guarded VM operand scratch; both ID destinations use the current decoded pointer.
void __thiscall UR6GSServers::execNativeLogOutServer(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc);
  void *replicationInfo = nullptr;
  uint opcode = *code;
  *(byte **)((byte *)frame + 0xc) = code + 1;
  uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
  UObject *object = *(UObject **)((byte *)frame + 8);
  using NativeABI = void (__thiscall *)(UObject *,FFrame *,void *);
  try {
    ((NativeABI)natives[opcode])(object,frame,&replicationInfo);
    code = *(byte **)((byte *)frame + 0xc) + 1;
    *(byte **)((byte *)frame + 0xc) = code;
    if (*code == 0x42) {
      object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      ((NativeABI)natives[0x42])(object,frame,nullptr);
    }
    *(uint *)((byte *)replicationInfo + 0x3c8) = 0;
    *(uint *)((byte *)replicationInfo + 0x3cc) = 0;
    LogOutServer();
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecNativeLogOutServer);
    throw;
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012177 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch148(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x18]
    push   eax
    mov    DWORD PTR [ebp-0x18],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeLogOutServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1001218b : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch149(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeLogOutServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    edi,edi
    push   edi
    push   edi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select logout guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064350 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execNativeLogOutServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeLogOutServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native logout unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007def4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeLogOutServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native logout handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007df04 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecNativeLogOutServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch148},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch149},
};

// Native logout try record; addresses and states are literal.
// R6GameService.dll data @ 1007df24 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeLogOutServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeLogOutServerHandlers},
};

// Native logout info record; addresses and states are literal.
// R6GameService.dll data @ 1007df38 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeLogOutServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeLogOutServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeLogOutServerTryMap,
  0x0,
  0x0,
};

// Register the current server with stored public/private data and five borrowed ANSI conversions.
// Exported nonvirtual void(void), saved receiver ECX, RET0. Guard precedes local FString construction.
// Package: +c4 bit0 selects password at +15c; +e8 server name, +100 max players, +168 game version, +1ac GS version.
// Both stores are read before signed count93b3c>0. Getter calls reload global store pointers independently.
// appToAnsi is cached after the first dereference; returned pointers are borrowed without copying or freeing.
// Final dedicated flag word is (current[c4]>>1)&ffffff01, retaining upper bits for the adapter.
// Debug logs cached public/private lengths, not registration status; Logf is cached between those two calls.
// R6GameService.dll @ 100121b0 : native password slot/guard; serialized byte pairs are independently sampled.
__declspec(naked) void __thiscall UR6GSServers::RegisterServer(void)
{
  byte *nativeFrame,*receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_RegisterServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    lea    ecx,[ebp-0x40]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    nativeFrame,ebp
    mov    receiver,esi
  }
  FString *password = (FString *)(nativeFrame - 0x40);
  using DefaultABI = FString * (__thiscall *)(FString *);
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(password);
  byte passwordFlags = *(byte *)(receiver + 0xc4);
  *(byte *)(nativeFrame - 4) = 1;
  if ((passwordFlags & 1) != 0) {
    using AssignABI = FString& (__thiscall *)(FString *,const FString&);
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(password,*(FString *)(receiver + 0x15c));
  } else {
    using AssignABI = FString& (__thiscall *)(FString *,const TCHAR *);
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot2)
        (password,(const TCHAR *)R6GameServiceAddresses::GEmptyWideText);
  }
  using GetterABI = uint (__thiscall *)(void *,uint);
  using DereferenceABI = const TCHAR * (__thiscall *)(FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  void *publicOwner = *(void **)R6GameServiceAddresses::GPublicSerializedStore;
  uint sampledLength = ((GetterABI)R6GameServiceAddresses::GetStoredBytesLength)(publicOwner,1);
  publicOwner = *(void **)R6GameServiceAddresses::GPublicSerializedStore;
  *(uint *)(nativeFrame - 0x24) = sampledLength;
  uint sampledPointer = ((GetterABI)R6GameServiceAddresses::GetStoredBytesPointer)(publicOwner,1);
  void *privateOwner = *(void **)R6GameServiceAddresses::GPrivateSerializedStore;
  *(uint *)(nativeFrame - 0x28) = sampledPointer;
  sampledLength = ((GetterABI)R6GameServiceAddresses::GetStoredBytesLength)(privateOwner,1);
  privateOwner = *(void **)R6GameServiceAddresses::GPrivateSerializedStore;
  *(uint *)(nativeFrame - 0x14) = sampledLength;
  sampledPointer = ((GetterABI)R6GameServiceAddresses::GetStoredBytesPointer)(privateOwner,1);
  *(uint *)(nativeFrame - 0x20) = sampledPointer;
  if (*(int *)(R6GameServiceAddresses::GServiceArray10 + 4) > 0) {
    const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)((FString *)(receiver + 0x1ac));
    AnsiABI convert = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
    const char *borrowed = convert(wide);
    *(const char **)(nativeFrame - 0x18) = borrowed;
    wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)((FString *)(receiver + 0x168));
    borrowed = convert(wide);
    *(const char **)(nativeFrame - 0x1c) = borrowed;
    wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(password);
    borrowed = convert(wide);
    *(const char **)(nativeFrame - 0x2c) = borrowed;
    wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
        ((FString *)R6GameServiceAddresses::GServiceString1);
    const char *globalText = convert(wide);
    wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)((FString *)(receiver + 0xe8));
    const char *serverName = convert(wide);
    uint dedicated = (*(uint *)(receiver + 0xc4) >> 1) & 0xffffff01;
    const char *extra1ac = *(const char **)(nativeFrame - 0x18);
    uint publicLength = *(uint *)(nativeFrame - 0x24);
    const char *extra168 = *(const char **)(nativeFrame - 0x1c);
    uint privateLength = *(uint *)(nativeFrame - 0x14);
    uint port = *(ushort *)0x10091bf4;
    uint privatePointer = *(uint *)(nativeFrame - 0x20);
    uint publicPointer = *(uint *)(nativeFrame - 0x28);
    const char *passwordAnsi = *(const char **)(nativeFrame - 0x2c);
    uint maxPlayers = *(uint *)(receiver + 0x100);
    using RegisterABI = uint (__stdcall *)(uint,uint,const char *,const char *,uint,uint,uint,const char *,
                                          uint,uint,uint,uint,uint,uint,uint,const char *,const char *,uint,uint);
    ((RegisterABI)R6GameServiceAddresses::RegisterServerOnLobby)
        (0,0,serverName,globalText,6,maxPlayers,0,passwordAnsi,publicPointer,publicLength,privatePointer,privateLength,
         0,0,port,extra168,extra1ac,1,dedicated);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendRegisterServerOnLobbyI,publicLength);
      uint loggedPrivateLength = *(uint *)(nativeFrame - 0x14);
      device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendRegisterServerOnLobbyI,loggedPrivateLength);
    }
  }
  *(byte *)(nativeFrame - 4) = 0;
  using DestroyABI = uint (__thiscall *)(FString *);
  uint rawEax = (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(password);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001236a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch150(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x34]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x30]
    push   edx
    mov    DWORD PTR [ebp-0x30],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RegisterServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1001237e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch151(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRegisterServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the completed registration password FString through the inherited parent frame.
// R6GameService.dll @ 10064360 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RegisterServerUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x40]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select registration guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064369 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RegisterServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RegisterServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native registration unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007df54 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RegisterServerUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_RegisterServerUnwind2},
  {-1, 0x0},
};

// Native registration handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007df6c : native storage identity retained.
const R6GameServiceNative::CatchHandler GRegisterServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -52,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch150},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch151},
};

// Native registration try record; addresses and states are literal.
// R6GameService.dll data @ 1007df8c : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RegisterServerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GRegisterServerHandlers},
};

// Native registration info record; addresses and states are literal.
// R6GameService.dll data @ 1007dfa0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RegisterServerExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_RegisterServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RegisterServerTryMap,
  0x0,
  0x0,
};

// Return the entire current registration word; no Boolean normalization or receiver access.
// Exported virtual int(void), unused ECX, RET0, no local guard; native vtable slot+80.
// R6GameService.dll @ 100123a0 : complete native control/access order and raw ABI retained.
int __thiscall UR6GSServers::GetServerRegistered(void)
{
  return *reinterpret_cast<const int *>(0x100939ec);
}

// Send current group settings, password scratch and borrowed public/private byte pairs.
// Exported nonvirtual void(void), saved ECX receiver, RET0. Guard precedes password FString construction.
// Early+c4 bit0 selects +15c password or empty literal; four mode1 getters run pointer then length per store.
// Each getter reloads its global owner independently. No registration/count gate or pointer consistency repair.
// One borrowed ANSI conversion precedes late group/max-player/WORD-port/flags reads; full dedicated word
// (current[c4]>>1)&ffffff01 reaches the14-word adapter. Result ignored; two logs print cached lengths.
// Normal destructor lowers state0 before dispatch; only completed scratch at EBP-2c has an unwind action.
// R6GameService.dll @ 100123b0 : native password slot/guard; serialized byte pairs are independently sampled.
__declspec(naked) void __thiscall UR6GSServers::UpdateServer(void)
{
  byte *nativeFrame,*receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_UpdateServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    nativeFrame,ebp
    mov    receiver,esi
  }
  FString *password = (FString *)(nativeFrame - 0x2c);
  using DefaultABI = FString * (__thiscall *)(FString *);
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(password);
  byte passwordFlags = *(byte *)(receiver + 0xc4);
  *(byte *)(nativeFrame - 4) = 1;
  if ((passwordFlags & 1) != 0) {
    using AssignABI = FString& (__thiscall *)(FString *,const FString&);
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(password,*(FString *)(receiver + 0x15c));
  } else {
    using AssignABI = FString& (__thiscall *)(FString *,const TCHAR *);
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot2)
        (password,(const TCHAR *)R6GameServiceAddresses::GEmptyWideText);
  }
  using GetterABI = uint (__thiscall *)(void *,uint);
  using DereferenceABI = const TCHAR * (__thiscall *)(FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  void *publicOwner = *(void **)R6GameServiceAddresses::GPublicSerializedStore;
  uint publicPointer = ((GetterABI)R6GameServiceAddresses::GetStoredBytesPointer)(publicOwner,1);
  publicOwner = *(void **)R6GameServiceAddresses::GPublicSerializedStore;
  *(uint *)(nativeFrame - 0x18) = publicPointer;
  uint publicLength = ((GetterABI)R6GameServiceAddresses::GetStoredBytesLength)(publicOwner,1);
  void *privateOwner = *(void **)R6GameServiceAddresses::GPrivateSerializedStore;
  uint privatePointer = ((GetterABI)R6GameServiceAddresses::GetStoredBytesPointer)(privateOwner,1);
  privateOwner = *(void **)R6GameServiceAddresses::GPrivateSerializedStore;
  *(uint *)(nativeFrame - 0x14) = privatePointer;
  uint privateLength = ((GetterABI)R6GameServiceAddresses::GetStoredBytesLength)(privateOwner,1);
  const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(password);
  const char *ansi = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wide);
  privatePointer = *(uint *)(nativeFrame - 0x14);
  uint port = *(ushort *)0x10091bf4;
  publicPointer = *(uint *)(nativeFrame - 0x18);
  uint maxPlayers = *(uint *)(receiver + 0x100);
  uint group = *(uint *)0x10093b1c;
  uint dedicated = (*(uint *)(receiver + 0xc4) >> 1) & 0xffffff01;
  using UpdateABI = uint (__stdcall *)(uint,uint,uint,uint,uint,uint,const char *,uint,uint,uint,uint,uint,uint,uint);
  ((UpdateABI)R6GameServiceAddresses::SendOptionalFieldsThroughSecondaryService)
      (group,1,1,dedicated,maxPlayers,0,ansi,publicPointer,publicLength,privatePointer,privateLength,0,0,port);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendUpdateGroupSettingsI,publicLength);
    device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendUpdateGroupSettingsI,privateLength);
  }
  *(byte *)(nativeFrame - 4) = 0;
  using DestroyABI = uint (__thiscall *)(FString *);
  uint rawEax = (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(password);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100124f3 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch152(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x1c]
    push   ecx
    mov    DWORD PTR [ebp-0x1c],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::UpdateServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012507 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch153(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersUpdateServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroy the completed update password FString through the inherited parent frame.
// R6GameService.dll @ 10064380 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_UpdateServerUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select update guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064389 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_UpdateServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_UpdateServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native update unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007dfbc : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_UpdateServerUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_UpdateServerUnwind2},
  {-1, 0x0},
};

// Native update handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007dfd4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GUpdateServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch152},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch153},
};

// Native update try record; addresses and states are literal.
// R6GameService.dll data @ 1007dff4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_UpdateServerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GUpdateServerHandlers},
};

// Native update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e008 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_UpdateServerExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_UpdateServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_UpdateServerTryMap,
  0x0,
  0x0,
};

// Consume the no-argument native terminator/debug token, then request a deferred server update.
// Exported exec void(FFrame&,void*), RET8, incoming ECX/result unused. Code advance and candidate read
// precede state0 publication; optional42h uses current Frame.Object and GNatives with NULL result.
// Flag8c290 becomes1 only after dispatch returns, before restoring the already-captured predecessor.
// R6GameService.dll @ 10012530 : RET8; DebugInfo candidate is read before guard activation and result stays unused.
__declspec(naked) void __thiscall UR6GSServers::execNativeUpdateServer(FFrame *frame,void *result)
{
  byte *nativeFrame,*vmFrame,*code;
  bool hasDebug;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeUpdateServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    nativeFrame,ebp
    mov    vmFrame,eax
    mov    code,edx
    setz   hasDebug
  }
  uint rawEax = (uint)vmFrame;
  if (hasDebug) {
    void *object = *(void **)(vmFrame + 8);
    ++code;
    *(byte **)(vmFrame + 0xc) = code;
    byte *table = *(byte **)R6GameServiceAddresses::Core__GNativesSlot;
    using DispatchABI = uint (__thiscall *)(void *,FFrame *,void *);
    rawEax = (*(DispatchABI *)(table + 0x108))(object,(FFrame *)vmFrame,nullptr);
  }
  uint predecessor = *(uint *)(nativeFrame - 0xc);
  __asm {
    pop    edi
    pop    esi
  }
  *(uint *)0x1008c290 = 1;
  __asm {
    mov    eax,rawEax
    mov    ecx,predecessor
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012599 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch154(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeUpdateServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100125ad : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch155(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeUpdateServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select deferred-update guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execNativeUpdateServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeUpdateServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native deferred-update unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e024 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeUpdateServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native deferred-update handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e034 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecNativeUpdateServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch154},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch155},
};

// Native deferred-update try record; addresses and states are literal.
// R6GameService.dll data @ 1007e054 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeUpdateServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeUpdateServerHandlers},
};

// Native deferred-update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e068 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeUpdateServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeUpdateServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeUpdateServerTryMap,
  0x0,
  0x0,
};

// Publish the unsigned low argument byte as the full lobby-login request DWORD93af0.
// Exported virtual member, unused incoming ECX, no guard; RET4; EAX is the zero-extended byte, no validation.
// R6GameService.dll @ 100125f0 : complete native control/access order and raw ABI retained.
void __thiscall UR6GSServers::SetRegServerLoginRequest(uchar value)
{
  *reinterpret_cast<uint *>(0x10093af0) = value;
}

// Publish the unsigned low argument byte as the full login-state DWORD93afc.
// Exported virtual member, unused incoming ECX, no guard; RET4; EAX is the zero-extended byte, no validation.
// R6GameService.dll @ 10012600 : complete native control/access order and raw ABI retained.
void __thiscall UR6GSServers::SetLoginRegServer(uchar value)
{
  *reinterpret_cast<uint *>(0x10093afc) = value;
}

// Return the login-state low byte in AL, preserving incoming upper EAX and all other registers.
// Exported virtual member, unused incoming ECX, no guard; RET0 with only one BYTE load.
// R6GameService.dll @ 10012610 : complete native control/access order and raw ABI retained.
uchar __thiscall UR6GSServers::GetLoginRegServer(void)
{
  return *reinterpret_cast<const uchar *>(0x10093afc);
}

// Connect the lobby endpoint, then send current borrowed ANSI login text and the current group word.
// Exported nonvirtual void(void), RET0. ECX only supplies m_iRegSvrPort low WORD at+18c; both port reads
// precede state0. Connection receives address939f0/global WORD/member WORD/25/120; status ignored.
// First diagnostic, string dereference/conversion, current group and second diagnostic remain ordered;
// each gate/device/Logf is current. Connection failure status does not suppress login. No local ownership.
// R6GameService.dll @ 10012620 : native port reads precede guard activation; connection failure does not suppress login.
__declspec(naked) void __thiscall UR6GSServers::ServerLogin(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ServerLoginSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    xor    eax,eax
    mov    ax,WORD PTR [ecx+0x18c]
    mov    DWORD PTR [ebp-0x10],esp
    xor    ecx,ecx
    mov    cx,WORD PTR ds:0x10093b28
    push   0x78
    push   0x19
    mov    DWORD PTR [ebp-0x4],0x0
    push   eax
    push   ecx
    push   0x100939f0
    call   R6GameServiceAddresses::ConnectToLobbyServer
  }
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendLobbyServerConnection);
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(FString *);
  const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((FString *)R6GameServiceAddresses::GServiceString13);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  const char *ansi = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wide);
  uint group = *(uint *)0x10093b1c;
  ((uint (__stdcall *)(const char *,uint))R6GameServiceAddresses::SendLobbyServerLogin)(ansi,group);
  uint rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  if (rawEax != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    rawEax = (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendLobbyServerLogin);
  }
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100126dd : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch156(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ServerLogin context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100126f1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch157(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersServerLogin
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select server-login guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ServerLoginSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ServerLoginExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native server-login unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e084 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ServerLoginUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native server-login handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e094 : native storage identity retained.
const R6GameServiceNative::CatchHandler GServerLoginHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch156},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch157},
};

// Native server-login try record; addresses and states are literal.
// R6GameService.dll data @ 1007e0b4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ServerLoginTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GServerLoginHandlers},
};

// Native server-login info record; addresses and states are literal.
// R6GameService.dll data @ 1007e0c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ServerLoginExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ServerLoginUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ServerLoginTryMap,
  0x0,
  0x0,
};

// Send three borrowed ANSI router-login values, then optionally log each current raw FString triple.
// Exported nonvirtual void(void), ECX receiver only locates password+1dc, RET0; no own exception guard.
// Dereference order is global9291c, password, global93b44; converter cached after the first dereference.
// Adapter receives global93b44/password/global9291c pointers without copying/freeing them; result ignored.
// One debug gate selects all four logs. Logf is cached, devices and raw pointer/count/capacity words reload.
// Native reuses header-argument space for12-byte raw varargs; no FString constructor or destructor runs.
// R6GameService.dll @ 10012710 : borrowed ANSI values and raw FString varargs retain native outgoing stack storage.
__declspec(naked) void __thiscall UR6GSServers::RegServerRouterLogin(void)
{
  FString *password;
  __asm {
    push   esi
    lea    esi,[ecx+0x1dc]
    push   edi
    mov    ecx,R6GameServiceAddresses::GServiceString2
    mov    password,esi
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((FString *)R6GameServiceAddresses::GServiceString2);
  AnsiABI convert = *(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot;
  const char *borrowed = convert(wide);
  __asm {
    mov    eax,borrowed
    push   eax
  }
  wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(password);
  borrowed = convert(wide);
  __asm {
    mov    eax,borrowed
    push   eax
  }
  wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((FString *)R6GameServiceAddresses::GServiceString13);
  borrowed = convert(wide);
  __asm {
    mov    eax,borrowed
    push   eax
    call   R6GameServiceAddresses::SendRouterLogin
  }
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    // The header arguments remain on the stack and become part of the first raw string packet.
    __asm {
      mov    edi,logger
      mov    ecx,device
      push   R6GameServiceAddresses::WideTextRegServerSendLoginRouter
      push   ecx
      call   edi
    }
    uint data = *(uint *)R6GameServiceAddresses::GServiceString13;
    uint *packet;
    __asm {
      push   ecx
      mov    packet,esp
    }
    uint count = *(uint *)(R6GameServiceAddresses::GServiceString13 + 4);
    packet[0] = data;
    uint capacity = *(uint *)(R6GameServiceAddresses::GServiceString13 + 8);
    packet[1] = count;
    FOutputDevice **deviceSlot = *(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    packet[2] = capacity;
    device = *deviceSlot;
    __asm {
      mov    edx,device
      push   R6GameServiceAddresses::WideTextS
      push   edx
      call   edi
    }
    data = *(uint *)password;
    count = *(uint *)((byte *)password + 4);
    __asm {
      add    esp,0x8
      mov    packet,esp
    }
    packet[0] = data;
    capacity = *(uint *)((byte *)password + 8);
    packet[1] = count;
    deviceSlot = *(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    packet[2] = capacity;
    device = *deviceSlot;
    __asm {
      mov    eax,device
      push   R6GameServiceAddresses::WideTextS
      push   eax
      call   edi
    }
    data = *(uint *)R6GameServiceAddresses::GServiceString2;
    count = *(uint *)(R6GameServiceAddresses::GServiceString2 + 4);
    __asm {
      add    esp,0x8
      mov    packet,esp
    }
    packet[0] = data;
    capacity = *(uint *)(R6GameServiceAddresses::GServiceString2 + 8);
    packet[1] = count;
    deviceSlot = *(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    packet[2] = capacity;
    device = *deviceSlot;
    __asm {
      mov    ecx,device
      push   R6GameServiceAddresses::WideTextS
      push   ecx
      call   edi
      add    esp,0x14
    }
  }
  __asm {
    pop    edi
    pop    esi
    ret
  }
}

// Disconnect the current registration router, then optionally emit a current diagnostic.
// Exported nonvirtual void(void), incoming ECX unused, RET0. Guard/state0 precede actual singleton adapter.
// Backend result ignored; gate/device/Logf reload after callback effects. No local resource action or rollback.
// R6GameService.dll @ 10012800 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RouterDisconnect(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_RouterDisconnectSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::SendRouterDisconnect
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch407
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextRegServerSendRouterDisconnect
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch407:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001285d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch158(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RouterDisconnect context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012871 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch159(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRouterDisconnect
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select router-disconnect guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RouterDisconnectSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RouterDisconnectExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native router-disconnect unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e0e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RouterDisconnectUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native router-disconnect handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e0f4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GRouterDisconnectHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch158},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch159},
};

// Native router-disconnect try record; addresses and states are literal.
// R6GameService.dll data @ 1007e0f4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RouterDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GRouterDisconnectHandlers},
};

// Native router-disconnect info record; addresses and states are literal.
// R6GameService.dll data @ 1007e0e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RouterDisconnectExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_RouterDisconnectUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RouterDisconnectTryMap,
  0x0,
  0x0,
};

// Request parent lobby groups using one borrowed ANSI conversion of global FString923ac.
// Exported nonvirtual void(void), incoming ECX unused, RET0. Guard/state0 precede dereference/conversion.
// Current singleton adapter forwards the pointer without copy/free; result ignored. Gate and logger reload
// after send effects. No local FString, own resource action, validation or rollback.
// R6GameService.dll @ 10012890 : borrowed ANSI argument; native two-state guard has no local resource actions.
__declspec(naked) void __thiscall UR6GSServers::RegServerGetLobbies(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_RegServerGetLobbiesSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    mov    ecx,R6GameServiceAddresses::GServiceString1
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
  }
  using DereferenceABI = const TCHAR * (__thiscall *)(FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  const TCHAR *wide = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)
      ((FString *)R6GameServiceAddresses::GServiceString1);
  const char *ansi = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wide);
  ((void (__stdcall *)(const char *))R6GameServiceAddresses::RequestParentGroupOnLobby)(ansi);
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendRequestParentGroupOnLobby);
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012903 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch160(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RegServerGetLobbies context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012917 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch161(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRegServerGetLobbies
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select lobby-discovery/failure guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_RegServerGetLobbiesSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_RegServerGetLobbiesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-discovery/failure unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e144 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_RegServerGetLobbiesUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native lobby-discovery/failure handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e154 : native storage identity retained.
const R6GameServiceNative::CatchHandler GRegServerGetLobbiesHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch160},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch161},
};

// Native lobby-discovery/failure try record; addresses and states are literal.
// R6GameService.dll data @ 1007e174 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RegServerGetLobbiesTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GRegServerGetLobbiesHandlers},
};

// Native lobby-discovery/failure info record; addresses and states are literal.
// R6GameService.dll data @ 1007e188 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_RegServerGetLobbiesExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_RegServerGetLobbiesUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_RegServerGetLobbiesTryMap,
  0x0,
  0x0,
};

// Return the full pending lobby-failure word, then consume the current word and request logout if nonzero.
// Exported exec void(FFrame&,void*), RET8; incoming ECX unused. Code advance/candidate read precede state0.
// Optional42h uses current Frame.Object/GNatives and NULL output. Current result argument loads afterward.
// Result store precedes a fresh failure-word read, so aliases or intervening changes affect consumption.
// Script declares Bool return; native copies all32 bits without normalization or NULL/type validation.
// R6GameService.dll @ 10012940 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execHandleAnyLobbyConnectionFail(FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execHandleAnyLobbyConnectionFailSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch409
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch409:
    mov    eax,ds:0x10093b04
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ecx],eax
    mov    eax,ds:0x10093b04
    test   eax,eax
    je     Branch410
    mov    DWORD PTR ds:0x10093b04,0x0
    mov    DWORD PTR ds:0x10093af8,0x1
  Branch410:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100129c6 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch162(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execHandleAnyLobbyConnectionFail context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100129da : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch163(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecHandleAnyLobbyConnectionFail
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select lobby-discovery/failure guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_execHandleAnyLobbyConnectionFailSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execHandleAnyLobbyConnectionFailExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-discovery/failure unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e1a4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_execHandleAnyLobbyConnectionFailUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// Native lobby-discovery/failure handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e1b4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GexecHandleAnyLobbyConnectionFailHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch162},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch163},
};

// Native lobby-discovery/failure try record; addresses and states are literal.
// R6GameService.dll data @ 1007e1b4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execHandleAnyLobbyConnectionFailTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecHandleAnyLobbyConnectionFailHandlers},
};

// Native lobby-discovery/failure info record; addresses and states are literal.
// R6GameService.dll data @ 1007e1a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execHandleAnyLobbyConnectionFailExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execHandleAnyLobbyConnectionFailUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execHandleAnyLobbyConnectionFailTryMap,
  0x0,
  0x0,
};

// Dispatch the two-pointer FillCreateGameInfo event, then reset and refill the server container.
// Nonvirtual void(AGameInfo*,ALevelInfo*), ECX receiver, RET8. Level local is stored before state0, game after.
// FindFunctionChecked precedes loading the current vtable for slot+10 ProcessEvent; no cached wrapper vtable.
// Root guard owns no resource actions, and script/reset/fill failures keep all committed effects.
// R6GameService.dll @ 10012a00 : event parameter packet uses native frame words; vtable is read after lookup.
__declspec(naked) void __thiscall UR6GSServers::InitProcessUpdateUbiServer(AGameInfo *gameInfo,ALevelInfo *level)
{
  byte *nativeFrame;
  void *receiver,*game,*levelInfo;
  uint eventName;
  UFunction *function;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    mov    edx,DWORD PTR ds:0x10092940
    mov    eax,DWORD PTR [ebp+0x8]
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    game,eax
    mov    levelInfo,ecx
    mov    eventName,edx
    push   0x0
  }
  *(void **)(nativeFrame - 0x1c) = levelInfo;
  __asm {
    mov    edx,eventName
    push   edx
    mov    ecx,esi
  }
  *(uint *)(nativeFrame - 4) = 0;
  *(void **)(nativeFrame - 0x20) = game;
  __asm {
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    mov    function,eax
  }
  byte *table = *(byte **)receiver;
  using EventABI = uint (__thiscall *)(void *,UFunction *,void *,void *);
  (*(EventABI *)(table + 0x10))(receiver,function,nativeFrame - 0x20,nullptr);
  ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6ServerList_ResetSvrContainer)(receiver);
  uint rawEax = ((uint (__thiscall *)(void *))R6GameServiceAddresses::UR6ServerList_FillSvrContainer)(receiver);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012a76 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch164(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitProcessUpdateUbiServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012a8a : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch165(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitProcessUpdateUbiServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select internet registration/update guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100643f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_InitProcessUpdateUbiServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native internet registration/update unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e204 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_InitProcessUpdateUbiServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native internet registration/update handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e214 : native storage identity retained.
const R6GameServiceNative::CatchHandler GInitProcessUpdateUbiServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch164},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch165},
};

// Native internet registration/update try record; addresses and states are literal.
// R6GameService.dll data @ 1007e234 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitProcessUpdateUbiServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitProcessUpdateUbiServerHandlers},
};

// Native internet registration/update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e248 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_InitProcessUpdateUbiServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServerTryMap,
  0x0,
  0x0,
};

// Publish the unsigned low argument byte as the full game-service request DWORD93b24.
// Exported virtual member, unused incoming ECX, no guard; RET4; EAX is the zero-extended byte, no validation.
// R6GameService.dll @ 10012ab0 : complete native control/access order and raw ABI retained.
void __thiscall UR6GSServers::SetGameServiceRequestState(uchar value)
{
  *reinterpret_cast<uint *>(0x10093b24) = value;
}

// Advance sampled router-login request through send, strict ordered timeout, failure or lobby discovery.
// Exported nonvirtual void(void), saved ECX receiver, RET0; request is sampled before state0 publication.
// State1 stores clock as float32, sends login, then writes request2 only after normal return. State2 compares
// current elapsed/current +198 timeout in x87; only ordered greater sets3, with no immediate redispatch.
// State3 publishes login3 then clears request; state6 publishes lobby-discovery1 then clears request.
// States4/5 and unsigned out-of-range requests do nothing. Normal12b5b continuation remains this one body.
// R6GameService.dll @ 10012ac0 : sampled DWORD dispatch; inherited native C++ guard and RET0.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerLoginRouterRequest(void)
{
  byte *nativeFrame;
  void *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRouterRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x100939e8
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ecx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x10093b50 = (float)now;
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_RegServerRouterLogin)(receiver);
    *(uint *)0x100939e8 = 2;
    __asm {
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x10093b50;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      *(uint *)0x100939e8 = 3;
      __asm {
        mov    ecx,DWORD PTR [ebp-0xc]
        mov    DWORD PTR fs:0x0,ecx
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret
      }
    }
  } else if (dispatchIndex == 2) {
    *(uint *)0x10093afc = 3;
  } else if (dispatchIndex == 5) {
    *(uint *)0x10093af4 = 1;
  }
  if (dispatchIndex == 2 || dispatchIndex == 5) *(uint *)0x100939e8 = 0;
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012b2b : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch166(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessRegServerLoginRouterRequest context, then passes null words to C++ rethrow.
// R6GameService.dll @ 10012b3f : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch167(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessRegServerLoginRouterRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ecx,ecx
    push   ecx
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select router-login request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064400 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessRegServerLoginRouterRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRouterRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native router-login request switch record; addresses and states are literal.
// R6GameService.dll data @ 10012bbc : native storage identity retained.
const uint GProcessRegServerLoginRouterRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessRegServerLoginRouterRequestSwitchCase1,R6GameServiceAddresses::GProcessRegServerLoginRouterRequestSwitchCase2,R6GameServiceAddresses::GProcessRegServerLoginRouterRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch412,R6GameServiceAddresses::UR6GSServersBranch412,R6GameServiceAddresses::GProcessRegServerLoginRouterRequestSwitchCase6
};

// Native router-login request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e264 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessRegServerLoginRouterRequestUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// Native router-login request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e274 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessRegServerLoginRouterRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch166},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch167},
};

// Native router-login request try record; addresses and states are literal.
// R6GameService.dll data @ 1007e294 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerLoginRouterRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerLoginRouterRequestHandlers},
};

// Native router-login request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e2a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessRegServerLoginRouterRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRouterRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRouterRequestTryMap,
  0x0,
  0x0,
};

// Advance sampled lobby-discovery request through send, strict ordered timeout, failure or registration.
// Exported nonvirtual void(void), saved ECX receiver, RET0; request sampled before state0 publication.
// State1 stores clock as float32, calls the guarded sender, then writes2 on return. State2 compares current
// elapsed/current +198 timeout in x87; only ordered greater sets3, with no immediate redispatch.
// State3 publishes login3 then clears request; state6 publishes registration1 then clears request.
// States4/5 and unsigned out-of-range requests do nothing. Normal12c7b continuation remains this one body.
// R6GameService.dll @ 10012be0 : sampled DWORD dispatch; inherited native C++ guard and RET0.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerGetLobbiesRequest(void)
{
  byte *nativeFrame;
  void *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessRegServerGetLobbiesRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10093af4
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ecx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x10093b54 = (float)now;
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_RegServerGetLobbies)(receiver);
    *(uint *)0x10093af4 = 2;
    __asm {
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x10093b54;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      *(uint *)0x10093af4 = 3;
      __asm {
        mov    ecx,DWORD PTR [ebp-0xc]
        mov    DWORD PTR fs:0x0,ecx
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret
      }
    }
  } else if (dispatchIndex == 2) {
    *(uint *)0x10093afc = 3;
  } else if (dispatchIndex == 5) {
    *(uint *)0x10093b14 = 1;
  }
  if (dispatchIndex == 2 || dispatchIndex == 5) *(uint *)0x10093af4 = 0;
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012c4b : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch168(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports ProcessRegServerGetLobbiesRequest context, then forwards null object/type words to C++ rethrow.
// R6GameService.dll @ 10012c5f : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch169(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessRegServerGetLobbiesRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ecx,ecx
    push   ecx
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select lobby-discovery/failure guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064410 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessRegServerGetLobbiesRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessRegServerGetLobbiesRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-discovery/failure switch record; addresses and states are literal.
// R6GameService.dll data @ 10012cdc : native storage identity retained.
const uint GProcessRegServerGetLobbiesRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestSwitchCase1,R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestSwitchCase2,R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch414,R6GameServiceAddresses::UR6GSServersBranch414,R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestSwitchCase6
};

// Native lobby-discovery/failure unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e2c4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessRegServerGetLobbiesRequestUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// Native lobby-discovery/failure handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e2d4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessRegServerGetLobbiesRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch168},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch169},
};

// Native lobby-discovery/failure try record; addresses and states are literal.
// R6GameService.dll data @ 1007e2f4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerGetLobbiesRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestHandlers},
};

// Native lobby-discovery/failure info record; addresses and states are literal.
// R6GameService.dll data @ 1007e308 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessRegServerGetLobbiesRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerGetLobbiesRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerGetLobbiesRequestTryMap,
  0x0,
  0x0,
};

// Advance sampled lobby-registration request through reset/fill/register, timeout, failure or login start.
// Exported nonvirtual void(void), saved ECX receiver, RET0; request sampled before state0 publication.
// State1 stores clock as float32 before reset, fill and RegisterServer; only normal completion writes2.
// State2 compares current elapsed/current +198 timeout in x87; only ordered greater sets3, no redispatch.
// State3 publishes login3 then clears request; state6 publishes server-login1 then clears request.
// States4/5 and unsigned out-of-range requests do nothing. Normal12da9 continuation remains this one body.
// R6GameService.dll @ 10012d00 : sampled DWORD dispatch; inherited native C++ guard and RET0.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerRegOnLobbyRequest(void)
{
  byte *nativeFrame;
  void *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessRegServerRegOnLobbyRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10093b14
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ecx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x10093b58 = (float)now;
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6ServerList_ResetSvrContainer)(receiver);
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6ServerList_FillSvrContainer)(receiver);
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_RegisterServer)(receiver);
    *(uint *)0x10093b14 = 2;
    __asm {
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x10093b58;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      *(uint *)0x10093b14 = 3;
      __asm {
        mov    ecx,DWORD PTR [ebp-0xc]
        mov    DWORD PTR fs:0x0,ecx
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret
      }
    }
  } else if (dispatchIndex == 2) {
    *(uint *)0x10093afc = 3;
  } else if (dispatchIndex == 5) {
    *(uint *)0x10093af0 = 1;
  }
  if (dispatchIndex == 2 || dispatchIndex == 5) *(uint *)0x10093b14 = 0;
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012d79 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch170(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports lobby-registration request context, then forwards null object/type words to C++ rethrow.
// R6GameService.dll @ 10012d8d : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch171(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessRegServerRegOnLobbyRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ecx,ecx
    push   ecx
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select lobby-registration request metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064420 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessRegServerRegOnLobbyRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessRegServerRegOnLobbyRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-registration/reset switch record; addresses and states are literal.
// R6GameService.dll data @ 10012e0c : native storage identity retained.
const uint GProcessRegServerRegOnLobbyRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestSwitchCase1,R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestSwitchCase2,R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch416,R6GameServiceAddresses::UR6GSServersBranch416,R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestSwitchCase6
};

// Native lobby-registration/reset unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e324 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessRegServerRegOnLobbyRequestUnwindMap[2] = {
  {-1, 0x0},
  {-1, 0x0},
};

// Native lobby-registration/reset handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e334 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessRegServerRegOnLobbyRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch170},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch171},
};

// Native lobby-registration/reset try record; addresses and states are literal.
// R6GameService.dll data @ 1007e354 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerRegOnLobbyRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestHandlers},
};

// Native lobby-registration/reset info record; addresses and states are literal.
// R6GameService.dll data @ 1007e368 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessRegServerRegOnLobbyRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerRegOnLobbyRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerRegOnLobbyRequestTryMap,
  0x0,
  0x0,
};

// Advance sampled server-login request through connect/login, timeout, failure or router disconnection.
// Exported nonvirtual void(void), saved ECX receiver, RET0; state sample precedes state0 publication.
// State1 stores float32 start before actual ServerLogin, then writes2 only after normal return.
// State2 uses current x87 elapsed/+198 timeout; only ordered greater sets3, without redispatch.
// State3 publishes login3 then clears request. State6 disconnects first, captures exception predecessor,
// clears request then publishes login2 before restoring the captured link. Other states do nothing.
// R6GameService.dll @ 10012e30 : sampled DWORD dispatch; inherited native C++ guard and RET0.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerLoginRequest(void)
{
  byte *nativeFrame;
  void *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10093af0
    push   ebx
    push   esi
    push   edi
    xor    edi,edi
    dec    eax
    cmp    eax,0x5
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],edi
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x10093b5c = (float)now;
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_ServerLogin)(receiver);
    *(uint *)0x10093af0 = 2;
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x10093b5c;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      *(uint *)0x10093af0 = 3;
    }
  } else if (dispatchIndex == 2) {
    *(uint *)0x10093afc = 3;
    *(uint *)0x10093af0 = 0;
  } else if (dispatchIndex == 5) {
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_RouterDisconnect)(receiver);
    uint predecessor = *(uint *)(nativeFrame - 0xc);
    *(uint *)0x10093af0 = 0;
    __asm {
      pop    edi
      pop    esi
    }
    *(uint *)0x10093afc = 2;
    __asm {
      mov    ecx,predecessor
      mov    DWORD PTR fs:0x0,ecx
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012f13 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch172(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessRegServerLoginRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012f27 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch173(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessRegServerLoginRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    edi,edi
    push   edi
    push   edi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select lobby-login request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064430 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessRegServerLoginRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-login request switch record; addresses and states are literal.
// R6GameService.dll data @ 10012f44 : native storage identity retained.
const uint GProcessRegServerLoginRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessRegServerLoginRequestSwitchCase1,R6GameServiceAddresses::GProcessRegServerLoginRequestSwitchCase2,R6GameServiceAddresses::GProcessRegServerLoginRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch417,R6GameServiceAddresses::UR6GSServersBranch417,R6GameServiceAddresses::GProcessRegServerLoginRequestSwitchCase6
};

// Native lobby-login request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e384 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessRegServerLoginRequestUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native lobby-login request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e394 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessRegServerLoginRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch172},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch173},
};

// Native lobby-login request try record; addresses and states are literal.
// R6GameService.dll data @ 1007e3b4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerLoginRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerLoginRequestHandlers},
};

// Native lobby-login request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e3c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessRegServerLoginRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRequestTryMap,
  0x0,
  0x0,
};

// Advance the sampled registration-update request, preserving strict ordered x87 timeout semantics.
// Exported nonvirtual void(void), saved ECX receiver, RET0. State is sampled before state0 publication.
// State1 stores the clock to float32, calls UpdateServer, then unconditionally writes request2 on return.
// State2 subtracts current float32 start in x87 and compares current +198 timeout: only greater sets3.
// States3/6 clear the request; states4/5 and unsigned out-of-range values do nothing. No loop or rollback.
// Native normal continuation12ffb..13044 follows the separate catch entries; it remains this one body.
// R6GameService.dll @ 10012f60 : sampled DWORD dispatch; inherited native C++ guard and RET0.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerUpdateRequest(void)
{
  byte *nativeFrame;
  void *receiver;
  uint dispatchIndex;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessRegServerUpdateRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10093b2c
    push   ebx
    push   esi
    mov    esi,ecx
    xor    ecx,ecx
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ecx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    dispatchIndex,eax
  }
  if (dispatchIndex == 0) {
    float10 now = ReadCycleTimeSeconds();
    *(float *)0x10093b60 = (float)now;
    ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_UpdateServer)(receiver);
    *(uint *)0x10093b2c = 2;
    __asm {
      mov    ecx,DWORD PTR [ebp-0xc]
      mov    DWORD PTR fs:0x0,ecx
      pop    edi
      pop    esi
      pop    ebx
      mov    esp,ebp
      pop    ebp
      ret
    }
  } else if (dispatchIndex == 1) {
    float10 elapsed = ReadCycleTimeSeconds();
    elapsed -= *(float *)0x10093b60;
    if (elapsed > (float10)*(float *)((byte *)receiver + 0x198)) {
      *(uint *)0x10093b2c = 3;
      __asm {
        mov    ecx,DWORD PTR [ebp-0xc]
        mov    DWORD PTR fs:0x0,ecx
        pop    edi
        pop    esi
        pop    ebx
        mov    esp,ebp
        pop    ebp
        ret
      }
    }
  }
  if (dispatchIndex == 2 || dispatchIndex == 5) *(uint *)0x10093b2c = 0;
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10012fcb : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch174(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessRegServerUpdateRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10012fdf : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch175(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessRegServerUpdateRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ecx,ecx
    push   ecx
    push   ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select registration-update request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064440 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessRegServerUpdateRequestSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessRegServerUpdateRequestExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native update-request switch record; addresses and states are literal.
// R6GameService.dll data @ 10013048 : native storage identity retained.
const uint GProcessRegServerUpdateRequestSwitch[6] = {
  R6GameServiceAddresses::GProcessRegServerUpdateRequestSwitchCase1,R6GameServiceAddresses::GProcessRegServerUpdateRequestSwitchCase2,R6GameServiceAddresses::GProcessRegServerUpdateRequestSwitchCase3,R6GameServiceAddresses::UR6GSServersBranch418,R6GameServiceAddresses::UR6GSServersBranch418,R6GameServiceAddresses::GProcessRegServerUpdateRequestSwitchCase3
};

// Native update-request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e3e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessRegServerUpdateRequestUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native update-request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e3f4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessRegServerUpdateRequestHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch174},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch175},
};

// Native update-request try record; addresses and states are literal.
// R6GameService.dll data @ 1007e414 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerUpdateRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerUpdateRequestHandlers},
};

// Native update-request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e428 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessRegServerUpdateRequestExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerUpdateRequestUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessRegServerUpdateRequestTryMap,
  0x0,
  0x0,
};

// Start a round through the sampled registration/client path and update only the client wait-reply bit.
// Exported virtual void(int), saved ECX/RET4. Byte+194 mask4 sampled before state0. Registration
// adapter gets the full argument, only AL is zero-extended for logging; wait word is untouched.
// Client slot+1c receives client/argument/0/current context as four callee-cleaned stack words.
// Signed failure logs unconditionally without wait update. Success optionally logs then reads the
// current +2c DWORD and sets/clears bit0 from result&8000ffff, preserving all unrelated bits.
// R6GameService.dll @ 10013420 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ServerRoundStart(int roundArgument)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ServerRoundStartSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    mov    ebx,ecx
    test   BYTE PTR [ebx+0x194],0x4
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch424
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceBstr
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    edi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   0x0
    push   edi
    push   eax
    call   DWORD PTR [ecx+0x1c]
    mov    esi,eax
    test   esi,esi
    jge    Branch419
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   esi
    push   edi
    push   R6GameServiceAddresses::WideTextGSClientSERVERStartMatchDReturnedFAILEDCodeX
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  Branch419:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch420
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   edi
    push   R6GameServiceAddresses::WideTextGSClientSERVERStartMatchDReturnedSUCCESSCodeX
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
  Branch420:
    test   esi,0x8000ffff
    mov    eax,DWORD PTR [ebx+0x2c]
    je     Branch423
    or     eax,0x1
  Branch421:
    mov    DWORD PTR [ebx+0x2c],eax
  Branch422:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  Branch423:
    and    eax,0xfffffffe
    jmp    Branch421
  Branch424:
    mov    esi,DWORD PTR [ebp+0x8]
    push   esi
    call   R6GameServiceAddresses::SendMatchStart
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    movzx  eax,al
    je     Branch422
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   esi
    push   R6GameServiceAddresses::WideTextRegServerSendMatchStartDReturnedD
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    add    esp,0x10
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001352d : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch176(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ServerRoundStart context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10013541 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch177(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersServerRoundStart
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select round-request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064450 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ServerRoundStartSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ServerRoundStartExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native round-request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e444 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ServerRoundStartUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native round-request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e454 : native storage identity retained.
const R6GameServiceNative::CatchHandler GServerRoundStartHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch176},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch177},
};

// Native round-request try record; addresses and states are literal.
// R6GameService.dll data @ 1007e454 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ServerRoundStartTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GServerRoundStartHandlers},
};

// Native round-request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e444 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ServerRoundStartExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ServerRoundStartUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ServerRoundStartTryMap,
  0x0,
  0x0,
};

// Finish a round through the sampled registration/client path and report its native status width.
// Exported virtual void(void), RET0. Byte+194 mask4 sampled before state0; registration consumes
// only AL, client slot+24 receives client/0/current context as three callee-cleaned stack words.
// Client signed failure logs regardless of debug; nonnegative and registration log only if current
// debug is set. Current device/Logf and raw varargs order retained; no wait-word update or ownership.
// R6GameService.dll @ 10013560 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ServerRoundFinish(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ServerRoundFinishSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    test   BYTE PTR [ecx+0x194],0x4
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch428
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceBstr
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   0x0
    push   eax
    call   DWORD PTR [ecx+0x24]
    test   eax,eax
    jge    Branch427
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientSERVERMatchFinishReturnedFAILEDCodeX
    push   ecx
  Branch425:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch426:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch427:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch426
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientSERVERMatchFinishReturnedSUCCESSCodeX
    push   eax
    jmp    Branch425
  Branch428:
    call   R6GameServiceAddresses::SendMatchFinish
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    movzx  eax,al
    je     Branch426
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextRegServerSendMatchFinishReturnedD
    push   edx
    jmp    Branch425
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1001360f : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch178(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ServerRoundFinish context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10013623 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch179(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersServerRoundFinish
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select round-request guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064460 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ServerRoundFinishSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ServerRoundFinishExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native round-request unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e4a4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ServerRoundFinishUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native round-request handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e4b4 : native storage identity retained.
const R6GameServiceNative::CatchHandler GServerRoundFinishHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch178},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch179},
};

// Native round-request try record; addresses and states are literal.
// R6GameService.dll data @ 1007e4b4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ServerRoundFinishTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GServerRoundFinishHandlers},
};

// Native round-request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e4a4 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ServerRoundFinishExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ServerRoundFinishUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ServerRoundFinishTryMap,
  0x0,
  0x0,
};

// Initialize networking when needed, install registration callbacks and rotate through current router records.
// Exported nonvirtual int(void), saved ECX receiver, RET0. Network flag is read before state0 publication.
// IP event constructs directly into the12-byte outgoing Init argument; Init owns that string, not this map.
// Early network failure skips the login-state store. Existing full registration flag bypasses all connection work.
// Singleton initialization and endpoint results use only AL; cached Logf survives callbacks, gates/devices reload.
// Signed attempt/count/index tests and modular stride108 arithmetic retain unchecked initial indices. Rotation
// precedes diagnostics, whose value is the next record full DWORD port rather than the used WORD or result.
// Final network flag is cached before login1 publication; full result is0/1, with no failure rollback.
// Native continuation13956..13985 follows separate catches and remains part of this single body.
// R6GameService.dll @ 100137d0 : full int result; action-free parent guard and transferred outgoing IP string.
__declspec(naked) int __thiscall UR6GSServers::InitializeRegServer(void)
{
  uint initiallyInitialized;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_InitializeRegServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    test   eax,eax
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    mov    initiallyInitialized,eax
  }
  if (initiallyInitialized == 0) {
    // The IP event constructs directly into Init's by-value argument; this frame never owns that value.
    __asm {
      sub    esp,0xc
      mov    eax,esp
      mov    DWORD PTR [ebp-0x18],esp
      push   eax
      call   R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
      mov    ecx,esi
      call   R6GameServiceAddresses::UR6GSServers_Init
    }
  }
  uint connected = 0;
  uint output = 0;
  if (*(uint *)R6GameServiceAddresses::GMSClientInitialized != 0) {
    if (*(uint *)0x10093b08 == 0) {
      uint rawInitialized = InitializeRegistrationServiceSingleton();
      using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
      LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      uint libraryReady = (byte)rawInitialized;
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerLibraryInitialize);
      }
      if (libraryReady != 0) {
        ((void (__cdecl *)(void))R6GameServiceAddresses::InstallRegistrationServiceCallbacks)();
        uint index = *(uint *)R6GameServiceAddresses::GMSRouterIndex;
        uint attempt = 0;
        while ((int)attempt < *(int *)(R6GameServiceAddresses::GServiceArray1 + 4)) {
          if (connected != 0) break;
          uint base = *(uint *)R6GameServiceAddresses::GServiceArray1;
          uint record = base + index * 0x108;
          uint port = *(ushort *)(record + 0x104);
          uint rawConnected = ((uint (__stdcall *)(const char *,uint))
              R6GameServiceAddresses::ConnectRegistrationEndpoint)((const char *)record,port);
          int routerCount = *(int *)(R6GameServiceAddresses::GServiceArray1 + 4);
          connected = (byte)rawConnected;
          index = *(uint *)R6GameServiceAddresses::GMSRouterIndex;
          ++index;
          bool wrap = (int)index >= routerCount;
          *(uint *)R6GameServiceAddresses::GMSRouterIndex = index;
          if (wrap) {
            index = 0;
            *(uint *)R6GameServiceAddresses::GMSRouterIndex = index;
          }
          if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
            base = *(uint *)R6GameServiceAddresses::GServiceArray1;
            uint nextPort = *(uint *)(index * 0x108 + base + 0x104);
            FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
            logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextRegServerSendRouterConnectI,nextPort);
            index = *(uint *)R6GameServiceAddresses::GMSRouterIndex;
          }
          ++attempt;
        }
        if (connected != 0) *(uint *)0x10093b08 = 1;
      }
      if (connected == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextResServerCouldNotConnectToServer);
      }
    } else connected = 1;
    uint networkReady = *(uint *)R6GameServiceAddresses::GMSClientInitialized;
    *(uint *)0x10093afc = 1;
    output = networkReady != 0 && connected != 0;
  }
  __asm {
    mov    eax,output
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10013926 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch180(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::InitializeRegServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1001393a : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch181(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersInitializeRegServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select registration-initialization guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10064490 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_InitializeRegServerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_InitializeRegServerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native registration-initialization unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e528 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_InitializeRegServerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native registration-initialization handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e538 : native storage identity retained.
const R6GameServiceNative::CatchHandler GInitializeRegServerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch180},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch181},
};

// Native registration-initialization try record; addresses and states are literal.
// R6GameService.dll data @ 1007e558 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitializeRegServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitializeRegServerHandlers},
};

// Native registration-initialization info record; addresses and states are literal.
// R6GameService.dll data @ 1007e56c : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_InitializeRegServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_InitializeRegServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_InitializeRegServerTryMap,
  0x0,
  0x0,
};

// Advance registration, publish group/lobby IDs, consume deferred updates and complete requested logout.
// Exported nonvirtual void(AR6AbstractGameInfo*,ALevelInfo*), saved ECX receiver, RET8; guard precedes imports.
// Full NativeStartedByGSClient result is sampled from the default AActor and retained across callbacks.
// Idle state compares clock/retry time, then skips native13b0e..13b3d; a constant-false block represents
// those unreachable operations within the same body without enabling automatic retry.
// Registered update clears8c290 before rebuilding; GS-client update clears it only after rebuild/score refresh.
// Inline logout clock overwrites incoming argument words with cycle halves; EDI retains current game pointer.
// ID pointers reload between stores; float arithmetic stays x87 until the explicit retry-time FSTP. No rollback.
// R6GameService.dll @ 10013990 : C++ registration/update/logout with native frame and argument-word clock scratch.
__declspec(naked) void __thiscall UR6GSServers::ProcessInternetSrv(AR6AbstractGameInfo *gameInfo,ALevelInfo *level)
{
  byte *nativeFrame;
  UR6GSServers *receiver;
  UClass *actorClass;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessInternetSrvSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ebx
    mov    nativeFrame,ebp
    mov    receiver,esi
    mov    actorClass,ecx
  }
  using DefaultABI = AActor * (__thiscall *)(UClass *);
  using StartedABI = uint (__thiscall *)(AActor *);
  using InitializeABI = uint (__thiscall *)(UR6GSServers *);
  using FillABI = void (__thiscall *)(UR6GSServers *,void *,void *);
  using AssignABI = FString& (__thiscall *)(FString *,const TCHAR *);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using LevelABI = void (__thiscall *)(UR6GSServers *,void *);
  using ServiceABI = void (__thiscall *)(UR6GSServers *);
  AActor *actor = (*(DefaultABI *)R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot)(actorClass);
  uint started = (*(StartedABI *)R6GameServiceAddresses::Engine_AActor_NativeStartedByGSClientSlot)(actor);
  uint requested = *(uint *)0x1008c294;
  *(uint *)(nativeFrame - 0x14) = started;
  uint state;
  if (requested != 0) {
    *(uint *)0x1008c294 = 0;
    state = 1;
    *(uint *)0x10093b24 = state;
  } else {
    state = *(uint *)0x10093b24;
  }
  if (started == 0) {
    switch (state) {
    case 0:
      if (*(uint *)0x100939ec == 0) {
        float10 now = ReadCycleTimeSeconds();
        bool expired = now > (float10)*(float *)0x10093b64;
        (void)expired; // Native FCOMP flags are discarded by the unconditional jump to common processing.
      }
      break;
    case 1:
      if (((InitializeABI)R6GameServiceAddresses::UR6GSServers_InitializeRegServer)(receiver) != 0) {
        void *initialGame = *(void **)(nativeFrame + 8);
        *(uint *)0x100939e8 = 1;
        *(uint *)0x10093afc = 1;
        void *initialLevel = *(void **)(nativeFrame + 0xc);
        ((FillABI)R6GameServiceAddresses::UR6GSServers_eventFillCreateGameInfo)(receiver,initialGame,initialLevel);
        (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot2)
            ((FString *)R6GameServiceAddresses::GServiceString13,(const TCHAR *)R6GameServiceAddresses::WideTextUbiGuest);
        *(uint *)0x10093b24 = 2;
      } else {
        *(uint *)0x10093b24 = 4;
      }
      break;
    case 2: {
      uint login = *(uint *)0x10093afc;
      if (login == 2) *(uint *)0x10093b24 = 3;
      else if (login == 3) *(uint *)0x10093b24 = 4;
      break;
    }
    case 3: {
      byte *registeredGame = *(byte **)(nativeFrame + 8);
      uint group = *(uint *)R6GameServiceAddresses::GSecondaryGroupId;
      *(uint *)0x10093b24 = 0;
      *(uint *)0x10091bd8 = 1;
      byte *replication = *(byte **)(registeredGame + 0x3c8);
      *(uint *)(replication + 0x3c8) = group;
      replication = *(byte **)(registeredGame + 0x3c8);
      uint lobby = *(uint *)R6GameServiceAddresses::GSecondaryLobbyServerId;
      *(uint *)(replication + 0x3cc) = lobby;
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
          (device,(const TCHAR *)R6GameServiceAddresses::WideTextServerRegisteredWithUbiComMasterServer);
      void *currentLevel = *(void **)(nativeFrame + 0xc);
      ((LevelABI)R6GameServiceAddresses::UR6GSServers_eventHandleNewLobbyConnection)(receiver,currentLevel);
      break;
    }
    case 4: {
      *(uint *)0x10093b24 = 0;
      float10 next = ReadCycleTimeSeconds();
      next += *(float *)R6GameServiceAddresses::NativeFloat15_0;
      *(float *)0x10093b64 = (float)next;
      break;
    }
    }
  }
  // Native 10013b0e..10013b3d has no incoming edge from this entry; retain its effects without enabling retry.
  if (false) {
    byte *skippedLevel = *(byte **)(nativeFrame + 0xc);
    float10 displayed = *(float *)(skippedLevel + 0x45c);
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    double timestamp = (double)displayed;
    (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
        (device,(const TCHAR *)R6GameServiceAddresses::WideTextTryAgainTimeF,timestamp);
    *(uint *)0x10093b24 = 1;
  }
  uint flags = *(uint *)((byte *)receiver + 0x194);
  byte *currentLevel = *(byte **)(nativeFrame + 0xc);
  if ((flags & 0x40) != 0) {
    byte *levelGame = *(byte **)(currentLevel + 0x4cc);
    if (*(uint *)(levelGame + 0x3c8) != 0) {
      *(uint *)((byte *)receiver + 0x194) = flags & 0xffffffbf;
      levelGame = *(byte **)(currentLevel + 0x4cc);
      byte *replication = *(byte **)(levelGame + 0x3c8);
      uint group = *(uint *)R6GameServiceAddresses::GSecondaryGroupId;
      *(uint *)(replication + 0x3c8) = group;
      levelGame = *(byte **)(currentLevel + 0x4cc);
      replication = *(byte **)(levelGame + 0x3c8);
      uint lobby = *(uint *)R6GameServiceAddresses::GSecondaryLobbyServerId;
      *(uint *)(replication + 0x3cc) = lobby;
    }
  }
  byte *currentGame;
  if (*(uint *)0x1008c290 != 0) {
    if (*(uint *)0x10091bd8 != 0) {
      currentGame = *(byte **)(nativeFrame + 8);
      *(uint *)0x1008c290 = 0;
      ((FillABI)R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServer)(receiver,currentGame,currentLevel);
      *(uint *)0x10093b2c = 1;
    } else if (*(uint *)(nativeFrame - 0x14) != 0) {
      currentGame = *(byte **)(nativeFrame + 8);
      ((FillABI)R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServer)(receiver,currentGame,currentLevel);
      ((ServiceABI)R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfo)(receiver);
      *(uint *)0x1008c290 = 0;
    } else {
      currentGame = *(byte **)(nativeFrame + 8);
    }
  } else {
    currentGame = *(byte **)(nativeFrame + 8);
  }
  if (*(uint *)0x10093af8 != 0) {
    ulonglong counter = __rdtsc();
    *(uint *)(nativeFrame + 8) = (uint)counter;
    *(uint *)(nativeFrame + 0xc) = (uint)(counter >> 32);
    float10 highCycles = (float10)*(int *)(nativeFrame + 0xc);
    int highSign = *(int *)(nativeFrame + 0xc);
    if (highSign < 0) highCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    int lowSign = *(int *)(nativeFrame + 8);
    highCycles *= *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    float10 lowCycles = (float10)*(int *)(nativeFrame + 8);
    if (lowSign < 0) lowCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    const double *scale = *(const double **)R6GameServiceAddresses::Core__GSecondsPerCycleSlot;
    float10 next = highCycles + lowCycles;
    byte *replication = *(byte **)(currentGame + 0x3c8);
    next *= *scale;
    *(uint *)(replication + 0x3c8) = 0;
    replication = *(byte **)(currentGame + 0x3c8);
    next += *(double *)R6GameServiceAddresses::NativeDouble16777216_0;
    *(uint *)(replication + 0x3cc) = 0;
    next += *(float *)R6GameServiceAddresses::NativeFloat15_0;
    *(float *)0x10093b64 = (float)next;
    ((ServiceABI)R6GameServiceAddresses::UR6GSServers_LogOutServer)(receiver);
    *(uint *)0x10093af8 = 0;
  }
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10013c6c : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch182(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x18]
    push   eax
    mov    DWORD PTR [ebp-0x18],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessInternetSrv context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10013c80 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch183(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessInternetSrv
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select internet registration/update guard metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 100644a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_ProcessInternetSrvSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_ProcessInternetSrvExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native internet registration/update switch record; addresses and states are literal.
// R6GameService.dll data @ 10013c9c : native storage identity retained.
const uint GProcessInternetSrvSwitch[5] = {R6GameServiceAddresses::GProcessInternetSrvSwitchCase1,R6GameServiceAddresses::GProcessInternetSrvSwitchCase2,R6GameServiceAddresses::GProcessInternetSrvSwitchCase3,R6GameServiceAddresses::GProcessInternetSrvSwitchCase4,R6GameServiceAddresses::GProcessInternetSrvSwitchCase5};

// Native internet registration/update unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007e588 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServers_ProcessInternetSrvUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native internet registration/update handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007e598 : native storage identity retained.
const R6GameServiceNative::CatchHandler GProcessInternetSrvHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch182},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch183},
};

// Native internet registration/update try record; addresses and states are literal.
// R6GameService.dll data @ 1007e598 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessInternetSrvTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessInternetSrvHandlers},
};

// Native internet registration/update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e588 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_ProcessInternetSrvExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_ProcessInternetSrvUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_ProcessInternetSrvTryMap,
  0x0,
  0x0,
};

// Destroy the incoming by-value FString at inherited OnSameSubNet EBP+8 through the current destructor import.
// R6GameService.dll @ 10063840 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl OnSameSubNetUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select the three-state subnet guard and incoming-string cleanup, then tail the existing runtime dispatcher.
// R6GameService.dll @ 10063849 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSubnetEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::OnSameSubNetExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal subnet cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007bc98 : native storage identity retained.
const R6GameServiceNative::UnwindEntry OnSameSubNetUnwindMap[3] = {
  {-1, R6GameServiceAddresses::OnSameSubNetUnwind1},
  {0x0, 0x0},
  {0x0, 0x0},
};

// Literal subnet cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007bcb0 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGSubnetEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -36,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch12},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch13},
};

// Literal subnet cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007bcb0 : native storage identity retained.
const R6GameServiceNative::TryBlock OnSameSubNetTryMap[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGSubnetEH},
};

// Literal subnet cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007bc98 : native storage identity retained.
const R6GameServiceNative::FuncInfo OnSameSubNetExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::OnSameSubNetUnwindMap,
  0x1,
  R6GameServiceAddresses::OnSameSubNetTryMap,
  0x0,
  0x0,
};

// Tail-destroy the inherited incoming password at EBP+0x10 through the current Core import.
// R6GameService.dll @ 10063930 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServersSharedLifetimeUnwind12(void)
{
  __asm {
    lea    ecx,[ebp+0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select exact parent FString lifetime/context-catch metadata and tail CRT exception dispatch.
// R6GameService.dll @ 10063939 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectInheritedFStringEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo4
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bff8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap4[3] = {
  {-1, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind12},
  {0x0, 0x0},
  {0x0, 0x0},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c010 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGInheritedFrameEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch28},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch29},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c010 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap3[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGInheritedFrameEH},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bff8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo4 = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap4,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap3,
  0x0,
  0x0,
};

// Tail-destroy the inherited decoded password at EBP-0x2c through the current Core import.
// R6GameService.dll @ 10063950 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServersSharedLifetimeUnwind22(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select exact parent FString lifetime/context-catch metadata and tail CRT exception dispatch.
// R6GameService.dll @ 10063959 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectInheritedFStringEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo5
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c060 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap5[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind22},
  {-1, 0x0},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c078 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGInheritedFrameEH5[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch30},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch31},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c078 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap4[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGInheritedFrameEH5},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c060 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo5 = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap5,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap4,
  0x0,
  0x0,
};

// Tail-destroy the inherited decoded address at EBP-0x24 through the current Core import.
// R6GameService.dll @ 100639a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServersSharedLifetimeUnwind23(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select exact parent FString lifetime/context-catch metadata and tail CRT exception dispatch.
// R6GameService.dll @ 100639a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectInheritedFStringEH2(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo6
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c1e8 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap6[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind23},
  {-1, 0x0},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c200 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGInheritedFrameEH9[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch36},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch37},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c200 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap5[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGInheritedFrameEH9},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c1e8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo6 = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap6,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap5,
  0x0,
  0x0,
};

// Tail-destroy the inherited incoming password at EBP+0x10 through the current Core import.
// R6GameService.dll @ 100639e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServersSharedLifetimeUnwind13(void)
{
  __asm {
    lea    ecx,[ebp+0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select exact parent FString lifetime/context-catch metadata and tail CRT exception dispatch.
// R6GameService.dll @ 100639e9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6GSServers_SelectInheritedFStringEH3(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServersSharedLifetimeExceptionInfo7
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c2c0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6GSServersSharedLifetimeUnwindMap7[3] = {
  {-1, R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwind13},
  {0x0, 0x0},
  {0x0, 0x0},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c2d8 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGInheritedFrameEH13[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch40},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch41},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c2d8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServersSharedLifetimeTryMap6[1] = {
  {0x1, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGInheritedFrameEH13},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c2c0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServersSharedLifetimeExceptionInfo7 = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeUnwindMap7,
  0x1,
  R6GameServiceAddresses::UR6GSServersSharedLifetimeTryMap6,
  0x0,
  0x0,
};

void __thiscall TailForwardTreeCleanup(int *tree);
void __thiscall ordered_tree_support_TailForwardTreeCleanup(int *tree);
void __thiscall ordered_tree_support_TailForwardTreeCleanup2(int *tree);
void __thiscall ordered_tree_support_TailForwardTreeCleanup3(int *tree);
void __thiscall ordered_tree_support_TailForwardTreeCleanup4(int *tree);

// R6GameService.dll @ 1006ac40 : destroy UR6GSServers class metadata
void DestroyUR6GSServersClassMetadata(void)
{
  UClass::~UClass(&UR6GSServers::PrivateStaticClass);
  return;
}

// Exported native member-function slot at 0x1008c1f8; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeMSCLientJoinServer;

// Registers UR6GSServers::execNativeMSCLientJoinServer at native index 3571 and stores the returned byte.
// R6GameService.dll @ 1006a500 : cdecl startup entry; result byte at 0x10092e51.
void __cdecl RegisterUR6GSServers_execNativeMSCLientJoinServer(void)
{
  byte registrationResult = GRegisterNative(3571,intUR6GSServersexecNativeMSCLientJoinServer);
  *(byte *)0x10092e51 = registrationResult;
}

// Exported native member-function slot at 0x1008c1fc; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeMSClientReqAltInfo;

// Registers UR6GSServers::execNativeMSClientReqAltInfo at native index 3570 and stores the returned byte.
// R6GameService.dll @ 1006a520 : cdecl startup entry; result byte at 0x100923fc.
void __cdecl RegisterUR6GSServers_execNativeMSClientReqAltInfo(void)
{
  byte registrationResult = GRegisterNative(3570,intUR6GSServersexecNativeMSClientReqAltInfo);
  *(byte *)0x100923fc = registrationResult;
}

// Exported native member-function slot at 0x1008c200; its value is read when registration runs.
extern "C" Native intUR6GSServersexecEnterCDKey;

// Registers UR6GSServers::execEnterCDKey at native index 3564 and stores the returned byte.
// R6GameService.dll @ 1006a540 : cdecl startup entry; result byte at 0x100923d4.
void __cdecl RegisterUR6GSServers_execEnterCDKey(void)
{
  byte registrationResult = GRegisterNative(3564,intUR6GSServersexecEnterCDKey);
  *(byte *)0x100923d4 = registrationResult;
}

// Exported native member-function slot at 0x1008c204; its value is read when registration runs.
extern "C" Native intUR6GSServersexecHandleAnyLobbyConnectionFail;

// Registers UR6GSServers::execHandleAnyLobbyConnectionFail at native index 3563 and stores the returned byte.
// R6GameService.dll @ 1006a560 : cdecl startup entry; result byte at 0x100923b8.
void __cdecl RegisterUR6GSServers_execHandleAnyLobbyConnectionFail(void)
{
  byte registrationResult = GRegisterNative(3563,intUR6GSServersexecHandleAnyLobbyConnectionFail);
  *(byte *)0x100923b8 = registrationResult;
}

// Exported native member-function slot at 0x1008c208; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeProcessIcmpPing;

// Registers UR6GSServers::execNativeProcessIcmpPing at native index 3562 and stores the returned byte.
// R6GameService.dll @ 1006a580 : cdecl startup entry; result byte at 0x10092918.
void __cdecl RegisterUR6GSServers_execNativeProcessIcmpPing(void)
{
  byte registrationResult = GRegisterNative(3562,intUR6GSServersexecNativeProcessIcmpPing);
  *(byte *)0x10092918 = registrationResult;
}

// Exported native member-function slot at 0x1008c20c; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeLogOutServer;

// Registers UR6GSServers::execNativeLogOutServer at native index 3561 and stores the returned byte.
// R6GameService.dll @ 1006a5a0 : cdecl startup entry; result byte at 0x1009293c.
void __cdecl RegisterUR6GSServers_execNativeLogOutServer(void)
{
  byte registrationResult = GRegisterNative(3561,intUR6GSServersexecNativeLogOutServer);
  *(byte *)0x1009293c = registrationResult;
}

// Exported native member-function slot at 0x1008c210; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeUpdateServer;

// Registers UR6GSServers::execNativeUpdateServer at native index 3560 and stores the returned byte.
// R6GameService.dll @ 1006a5c0 : cdecl startup entry; result byte at 0x10092398.
void __cdecl RegisterUR6GSServers_execNativeUpdateServer(void)
{
  byte registrationResult = GRegisterNative(3560,intUR6GSServersexecNativeUpdateServer);
  *(byte *)0x10092398 = registrationResult;
}

// Exported native member-function slot at 0x1008c214; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeIsGSReadyToChangeMod;

// Registers UR6GSServers::execNativeIsGSReadyToChangeMod at native index 3552 and stores the returned byte.
// R6GameService.dll @ 1006a5e0 : cdecl startup entry; result byte at 0x10092390.
void __cdecl RegisterUR6GSServers_execNativeIsGSReadyToChangeMod(void)
{
  byte registrationResult = GRegisterNative(3552,intUR6GSServersexecNativeIsGSReadyToChangeMod);
  *(byte *)0x10092390 = registrationResult;
}

// Exported native member-function slot at 0x1008c218; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeIsWaitingForGSInit;

// Registers UR6GSServers::execNativeIsWaitingForGSInit at native index 3551 and stores the returned byte.
// R6GameService.dll @ 1006a600 : cdecl startup entry; result byte at 0x100923e4.
void __cdecl RegisterUR6GSServers_execNativeIsWaitingForGSInit(void)
{
  byte registrationResult = GRegisterNative(3551,intUR6GSServersexecNativeIsWaitingForGSInit);
  *(byte *)0x100923e4 = registrationResult;
}

// Exported native member-function slot at 0x1008c21c; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeIsRouterDisconnect;

// Registers UR6GSServers::execNativeIsRouterDisconnect at native index 3550 and stores the returned byte.
// R6GameService.dll @ 1006a620 : cdecl startup entry; result byte at 0x100923a8.
void __cdecl RegisterUR6GSServers_execNativeIsRouterDisconnect(void)
{
  byte registrationResult = GRegisterNative(3550,intUR6GSServersexecNativeIsRouterDisconnect);
  *(byte *)0x100923a8 = registrationResult;
}

// Exported native member-function slot at 0x1008c220; its value is read when registration runs.
extern "C" Native intUR6GSServersexecSetLastServerQueried;

// Registers UR6GSServers::execSetLastServerQueried at native index 3541 and stores the returned byte.
// R6GameService.dll @ 1006a640 : cdecl startup entry; result byte at 0x10091e81.
void __cdecl RegisterUR6GSServers_execSetLastServerQueried(void)
{
  byte registrationResult = GRegisterNative(3541,intUR6GSServersexecSetLastServerQueried);
  *(byte *)0x10091e81 = registrationResult;
}

// Exported native member-function slot at 0x1008c224; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeSetMatchResult;

// Registers UR6GSServers::execNativeSetMatchResult at native index 3540 and stores the returned byte.
// R6GameService.dll @ 1006a660 : cdecl startup entry; result byte at 0x10092e59.
void __cdecl RegisterUR6GSServers_execNativeSetMatchResult(void)
{
  byte registrationResult = GRegisterNative(3540,intUR6GSServersexecNativeSetMatchResult);
  *(byte *)0x10092e59 = registrationResult;
}

// Exported native member-function slot at 0x1008c228; its value is read when registration runs.
extern "C" Native intUR6GSServersexecGetMaxUbiServerNameSize;

// Registers UR6GSServers::execGetMaxUbiServerNameSize at native index 3532 and stores the returned byte.
// R6GameService.dll @ 1006a680 : cdecl startup entry; result byte at 0x10092392.
void __cdecl RegisterUR6GSServers_execGetMaxUbiServerNameSize(void)
{
  byte registrationResult = GRegisterNative(3532,intUR6GSServersexecGetMaxUbiServerNameSize);
  *(byte *)0x10092392 = registrationResult;
}

// Exported native member-function slot at 0x1008c22c; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeGetMSClientInitialized;

// Registers UR6GSServers::execNativeGetMSClientInitialized at native index 3531 and stores the returned byte.
// R6GameService.dll @ 1006a6a0 : cdecl startup entry; result byte at 0x10092929.
void __cdecl RegisterUR6GSServers_execNativeGetMSClientInitialized(void)
{
  byte registrationResult = GRegisterNative(3531,intUR6GSServersexecNativeGetMSClientInitialized);
  *(byte *)0x10092929 = registrationResult;
}

// Exported native member-function slot at 0x1008c230; its value is read when registration runs.
extern "C" Native intUR6GSServersexecNativeGetSeconds;

// Registers UR6GSServers::execNativeGetSeconds at native index 3530 and stores the returned byte.
// R6GameService.dll @ 1006a6c0 : cdecl startup entry; result byte at 0x100923f6.
void __cdecl RegisterUR6GSServers_execNativeGetSeconds(void)
{
  byte registrationResult = GRegisterNative(3530,intUR6GSServersexecNativeGetSeconds);
  *(byte *)0x100923f6 = registrationResult;
}

// Exported native member-function slot at 0x1008c234; its value is read when registration runs.
extern "C" Native intUR6GSServersexecStopRefreshServers;

// Registers UR6GSServers::execStopRefreshServers at native index 3523 and stores the returned byte.
// R6GameService.dll @ 1006a6e0 : cdecl startup entry; result byte at 0x100923a9.
void __cdecl RegisterUR6GSServers_execStopRefreshServers(void)
{
  byte registrationResult = GRegisterNative(3523,intUR6GSServersexecStopRefreshServers);
  *(byte *)0x100923a9 = registrationResult;
}

// Exported native member-function slot at 0x1008c238; its value is read when registration runs.
extern "C" Native intUR6GSServersexecIsRefreshServersInProgress;

// Registers UR6GSServers::execIsRefreshServersInProgress at native index 3522 and stores the returned byte.
// R6GameService.dll @ 1006a700 : cdecl startup entry; result byte at 0x1009240d.
void __cdecl RegisterUR6GSServers_execIsRefreshServersInProgress(void)
{
  byte registrationResult = GRegisterNative(3522,intUR6GSServersexecIsRefreshServersInProgress);
  *(byte *)0x1009240d = registrationResult;
}

// Exported native member-function slot at 0x1008c23c; its value is read when registration runs.
extern "C" Native intUR6GSServersexecRefreshOneServer;

// Registers UR6GSServers::execRefreshOneServer at native index 3521 and stores the returned byte.
// R6GameService.dll @ 1006a720 : cdecl startup entry; result byte at 0x100933b8.
void __cdecl RegisterUR6GSServers_execRefreshOneServer(void)
{
  byte registrationResult = GRegisterNative(3521,intUR6GSServersexecRefreshOneServer);
  *(byte *)0x100933b8 = registrationResult;
}

// Exported native member-function slot at 0x1008c240; its value is read when registration runs.
extern "C" Native intUR6GSServersexecRefreshServers;

// Registers UR6GSServers::execRefreshServers at native index 3520 and stores the returned byte.
// R6GameService.dll @ 1006a740 : cdecl startup entry; result byte at 0x100923dc.
void __cdecl RegisterUR6GSServers_execRefreshServers(void)
{
  byte registrationResult = GRegisterNative(3520,intUR6GSServersexecRefreshServers);
  *(byte *)0x100923dc = registrationResult;
}

// Exported native member-function slot at 0x1008c244; its value is read when registration runs.
extern "C" Native intUR6GSServersexecUnInitializeMSClient;

// Registers UR6GSServers::execUnInitializeMSClient at native index 3510 and stores the returned byte.
// R6GameService.dll @ 1006a760 : cdecl startup entry; result byte at 0x10092e58.
void __cdecl RegisterUR6GSServers_execUnInitializeMSClient(void)
{
  byte registrationResult = GRegisterNative(3510,intUR6GSServersexecUnInitializeMSClient);
  *(byte *)0x10092e58 = registrationResult;
}

// Exported native member-function slot at 0x1008c248; its value is read when registration runs.
extern "C" Native intUR6GSServersexecInitializeMSClient;

// Registers UR6GSServers::execInitializeMSClient at native index 3502 and stores the returned byte.
// R6GameService.dll @ 1006a780 : cdecl startup entry; result byte at 0x100923f5.
void __cdecl RegisterUR6GSServers_execInitializeMSClient(void)
{
  byte registrationResult = GRegisterNative(3502,intUR6GSServersexecInitializeMSClient);
  *(byte *)0x100923f5 = registrationResult;
}

// Exported native member-function slot at 0x1008c24c; its value is read when registration runs.
extern "C" Native intUR6GSServersexecInitGSCDKey;

// Registers UR6GSServers::execInitGSCDKey at native index 3501 and stores the returned byte.
// R6GameService.dll @ 1006a7a0 : cdecl startup entry; result byte at 0x10092e94.
void __cdecl RegisterUR6GSServers_execInitGSCDKey(void)
{
  byte registrationResult = GRegisterNative(3501,intUR6GSServersexecInitGSCDKey);
  *(byte *)0x10092e94 = registrationResult;
}

// Exported native member-function slot at 0x1008c250; its value is read when registration runs.
extern "C" Native intUR6GSServersexecInitialize;

// Registers UR6GSServers::execInitialize at native index 3500 and stores the returned byte.
// R6GameService.dll @ 1006a7c0 : cdecl startup entry; result byte at 0x100923c0.
void __cdecl RegisterUR6GSServers_execInitialize(void)
{
  byte registrationResult = GRegisterNative(3500,intUR6GSServersexecInitialize);
  *(byte *)0x100923c0 = registrationResult;
}

// Publishes this class's metadata address in its exported autoclass pointer slot.
// R6GameService.dll @ 1006a1f0 : cdecl startup entry; pointer slot 0x100923d8.
void __cdecl InitializeAutoclassUR6GSServers(void)
{
  *(UClass **)0x100923d8 = &UR6GSServers::PrivateStaticClass;
}

// Constructs class metadata with its selected native size and registers class-metadata cleanup.
// R6GameService.dll @ 1006a170 : cdecl startup entry; no local EH guard.
void __cdecl InitializeUR6GSServersClassMetadata(void)
{
  UClass *withinClass = *(UClass **)R6GameServiceAddresses::Core_UObject_PrivateStaticClassSlot;
  code *staticConstructor = *(code **)R6GameServiceAddresses::Core_UObject_StaticConstructorSlot;
  code *nativeConstructor = UR6GSServers::InternalConstructor;
  ushort *configName = UObject::StaticConfigName();
  UClass::UClass(&UR6GSServers::PrivateStaticClass,0,0x218,4,&UR6ServerList::PrivateStaticClass,withinClass,
                 0,0,0,0,L"R6GSServers",GPackage,configName,0x4084004,nativeConstructor,staticConstructor);
  _atexit(DestroyUR6GSServersClassMetadata);
}

// R6GameService.dll data @ 1007ba50 : native exception records.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeProcessIcmpPingUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_execNativeProcessIcmpPingUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007ba68 : native exception records.
const R6GameServiceNative::CatchHandler UR6GSServersGPingExchangeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch6},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch7},
};
// R6GameService.dll data @ 1007ba88 : native exception records.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeProcessIcmpPingTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::UR6GSServersGPingExchangeHandlers},
};
// R6GameService.dll data @ 1007ba9c : native exception records.
// R6GameService.dll data @ 1007ba50 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeProcessIcmpPingExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_execNativeProcessIcmpPingUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeProcessIcmpPingTryMap,
  0x0,
  0x0,
};

// Parses an address/out property, rate-limits new requests with x87 tick arithmetic and polls one complete result scan.
// The out-property callback/load sequence matches UE2 P_GET_INT_REF; result address caches after virtual+0x60.
// R6GameService.dll @ 10005c80 : exported FFrame/result bridge; native frame retains ownership and output aliases.
__declspec(naked) void __thiscall UR6GSServers::execNativeProcessIcmpPing(FFrame &Stack,void *const Result)
{
  byte *nativeFrame;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeProcessIcmpPingSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x20
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x10],esp
    mov    nativeFrame,ebp
  }
  using EmptyABI = FString * (__thiscall *)(FString *);
  using NativeABI = void (__thiscall *)(UObject *,FFrame *,void *);
  using DirtyABI = void (__thiscall *)(UObject *,void *);
  using TickABI = uint (__stdcall *)(void);
  using DereferenceABI = const TCHAR * (__thiscall *)(const FString *);
  using AnsiABI = const char * (__cdecl *)(const TCHAR *);
  using ConstructABI = FString * (__thiscall *)(FString *,const TCHAR *);
  using RequestABI = void (__thiscall *)(void *,uint,uint,uint,const char *,uint);
  using PollABI = uint (__thiscall *)(void *,FArray *,int *);
  using DestroyABI = void (__thiscall *)(FString *);
  *(uint *)(nativeFrame - 4) = 0;
  FString *address = (FString *)(nativeFrame - 0x2c);
  (*(EmptyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(address);
  FFrame *frame = *(FFrame **)(nativeFrame + 8);
  byte *code = *(byte **)((byte *)frame + 0xc);
  uint opcode = *code;
  UObject *object = *(UObject **)((byte *)frame + 8);
  *(byte **)((byte *)frame + 0xc) = code + 1;
  uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
  *(byte *)(nativeFrame - 4) = 1;
  ((NativeABI)natives[opcode])(object,frame,address);
  uint **propertyAddress = *(uint ***)R6GameServiceAddresses::Core__GPropAddrSlot;
  *(uint *)(nativeFrame - 0x14) = 0;
  *propertyAddress = 0;
  code = *(byte **)((byte *)frame + 0xc);
  opcode = *code;
  object = *(UObject **)((byte *)frame + 8);
  *(byte **)((byte *)frame + 0xc) = code + 1;
  natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
  ((NativeABI)natives[opcode])(object,frame,nativeFrame - 0x14);
  object = **(UObject ***)R6GameServiceAddresses::Core__GPropObjectSlot;
  if (object != 0) {
    void *property = **(void ***)R6GameServiceAddresses::Core__GPropertySlot;
    uint *table = *(uint **)object;
    ((DirtyABI)table[0x60 / 4])(object,property);
  }
  propertyAddress = *(uint ***)R6GameServiceAddresses::Core__GPropAddrSlot;
  uint *outputProperty = *propertyAddress;
  if (outputProperty == 0) outputProperty = (uint *)(nativeFrame - 0x14);
  code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  if (*code == 0x42) {
    object = *(UObject **)((byte *)frame + 8);
    *(byte **)((byte *)frame + 0xc) = code + 1;
    natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
    ((NativeABI)natives[0x42])(object,frame,0);
  }
  TickABI tick = *(TickABI *)R6GameServiceAddresses::KERNEL32_GetTickCountSlot;
  uint tickValue = tick();
  *(uint *)(nativeFrame + 8) = tickValue;
  // float10 denotes live x87 values under the inherited precision and rounding mode.
  float10 current = (float10)*(int *)(nativeFrame + 8);
  if ((int)tickValue < 0) current += *(float *)R6GameServiceAddresses::NativeFloat4294967296_0;
  float10 threshold = (float10)*(float *)R6GameServiceAddresses::GLastIcmpRequestTick;
  threshold += *(float *)R6GameServiceAddresses::NativeFloat5000_0;
  if (threshold < current) {
    tickValue = tick();
    *(uint *)(nativeFrame + 8) = tickValue;
    float10 requestedAt = (float10)*(int *)(nativeFrame + 8);
    if ((int)tickValue < 0) requestedAt += *(float *)R6GameServiceAddresses::NativeFloat4294967296_0;
    *(float *)R6GameServiceAddresses::GLastIcmpRequestTick = (float)requestedAt;
    const TCHAR *wideAddress = (*(DereferenceABI *)R6GameServiceAddresses::Core__DFStringSlot)(address);
    const char *ansiAddress = (*(AnsiABI *)R6GameServiceAddresses::Core__appToAnsiSlot)(wideAddress);
    uint transferred[3];
    *(uint **)(nativeFrame + 8) = transferred;
    (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
        ((FString *)transferred,(const TCHAR *)R6GameServiceAddresses::WideTextDoesNotMatter);
    ((RequestABI)R6GameServiceAddresses::ServerPing_NewPingRequest)
        ((void *)0x10092e74,transferred[0],transferred[1],transferred[2],ansiAddress,0);
  }
  uint completed = ((PollABI)R6GameServiceAddresses::ServerPing_PingManager)
      ((void *)0x10092e74,0,(int *)(nativeFrame - 0x18));
  if (completed != 0) {
    uint ping = *(uint *)(nativeFrame - 0x18);
    uint *result = *(uint **)(nativeFrame + 0xc);
    *outputProperty = ping;
    *result = 1;
  } else {
    **(uint **)(nativeFrame + 0xc) = 0;
  }
  *(byte *)(nativeFrame - 4) = 0;
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(address);
  __asm {
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Forwards the caught pointer from inherited EBP-0x20 through-0x1c.
// R6GameService.dll @ 10005e00 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch6(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x1c]
    push   edx
    mov    DWORD PTR [ebp-0x1c],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports execNativeProcessIcmpPing context and rethrows the active exception.
// R6GameService.dll @ 10005e14 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch7(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeProcessIcmpPing
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the script address temporary at inherited EBP-0x2c.
// R6GameService.dll @ 100637d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_execNativeProcessIcmpPingUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state asynchronous script guard and address cleanup action.
// R6GameService.dll @ 100637d9 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_execNativeProcessIcmpPingSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeProcessIcmpPingExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007bab8 : native exception records.
const R6GameServiceNative::UnwindEntry UR6GSServers_execNativeGetSecondsUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007bac8 : native exception records.
const R6GameServiceNative::CatchHandler UR6GSServersGPingExchangeHandlers2[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch8},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch9},
};
// R6GameService.dll data @ 1007bae8 : native exception records.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeGetSecondsTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGPingExchangeHandlers2},
};
// R6GameService.dll data @ 1007bafc : native exception records.
// R6GameService.dll data @ 1007bab8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execNativeGetSecondsExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execNativeGetSecondsUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execNativeGetSecondsTryMap,
  0x0,
  0x0,
};

// Finish VM parameters and return cycle time as float32, preserving x87 operation order and precision.
// R6GameService.dll @ 10005e40 : FFrame/result bridge; typed forwarding and context rethrow preserved.
void __thiscall UR6GSServers::execNativeGetSeconds(FFrame &Stack,void *const Result)
{
  FFrame *frame = &Stack;
  byte *code = *(byte **)((byte *)frame + 0xc) + 1;
  *(byte **)((byte *)frame + 0xc) = code;
  bool hasDebugInfo = *code == 0x42;
  try {
    if (hasDebugInfo) {
      UObject *object = *(UObject **)((byte *)frame + 8);
      *(byte **)((byte *)frame + 0xc) = code + 1;
      uint *natives = *(uint **)R6GameServiceAddresses::Core__GNativesSlot;
      using DebugABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ((DebugABI)natives[0x42])(object,frame,nullptr);
    }
    ulonglong counter = __rdtsc();
    int high = (int)(uint)(counter >> 32);
    int low = (int)(uint)counter;
    // float10 denotes the native extended x87 value; keep each operation separate until the float32 result store.
    float10 highCycles = (float10)high;
    if (high < 0) highCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    highCycles *= *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    float10 lowCycles = (float10)low;
    if (low < 0) lowCycles += *(double *)R6GameServiceAddresses::NativeDouble4294967296_0;
    const double *secondsPerCycle = *(const double **)R6GameServiceAddresses::Core__GSecondsPerCycleSlot;
    float10 seconds = highCycles + lowCycles;
    seconds *= *secondsPerCycle;
    seconds += *(double *)R6GameServiceAddresses::NativeDouble16777216_0;
    *(float *)Result = (float)seconds;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const TCHAR *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const TCHAR *)R6GameServiceAddresses::WideTextTextFormat,
         (const TCHAR *)R6GameServiceAddresses::WideTextUR6GSServersExecNativeGetSeconds);
    throw;
  }
}

// Forwards the caught pointer from inherited EBP-0x18 through-0x14.
// R6GameService.dll @ 10005ee2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch8(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports execNativeGetSeconds context and rethrows the active exception.
// R6GameService.dll @ 10005ef6 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch9(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeGetSeconds
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the cycle-time wrapper guard without local cleanup actions.
// R6GameService.dll @ 100637f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_execNativeGetSecondsSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execNativeGetSecondsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007be20 : native exception records.
const R6GameServiceNative::UnwindEntry UR6GSServers_PollMSClientCallbacksUnwindMap[13] = {
  {-1, 0},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind2},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind3},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind4},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind5},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind6},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind7},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind8},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind9},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind10},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind11},
  {0, R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwind12},
  {-1, 0},
};
// R6GameService.dll data @ 1007be88 : native exception records.
const R6GameServiceNative::CatchHandler GMSPollHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch20},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch21},
};
// R6GameService.dll data @ 1007bea8 : native exception records.
const R6GameServiceNative::TryBlock UR6GSServers_PollMSClientCallbacksTryMap[1] = {
  {0x0, 0xb, 0xc, 0x2, R6GameServiceAddresses::GMSPollHandlers},
};
// R6GameService.dll data @ 1007bebc : native exception records.
// R6GameService.dll data @ 1007be20 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_PollMSClientCallbacksExceptionInfo = {
  0x19930520,
  0xd,
  R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksTryMap,
  0x0,
  0x0,
};

// Pumps MS callbacks, consumes login/join replies and reports failure messages before clearing statuses and disconnect words.
// Login/join status loads precede prior status clears; disconnect tests retain their native order.
// R6GameService.dll @ 10006880 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollMSClientCallbacks(UR6GSServers *this,int enabled)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x6c
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  const int initialized = *reinterpret_cast<int*>(0x10091e64);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (initialized && *reinterpret_cast<int*>(nativeFrame + 8)) {
    DispatchMSClientState(500, 800);
    const uint loginReply = *reinterpret_cast<uint*>(0x10091c10);
    if (loginReply == 39) {
      uint& flags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x194);
      if (flags & 0x100) flags = (flags & 0xfffffeff) | 0x200;
      const int error = *reinterpret_cast<int*>(0x10091d2c);
      *reinterpret_cast<int*>(0x10091c14) = 3;
      *reinterpret_cast<int*>(0x10091e68) = 0;
      uint text;
      byte state;
      uint offset;
      switch (error) {
      case 15: text = R6GameServiceAddresses::WideTextLOGINFAILPASSWORDNOTCORRECT; state = 1; offset = 0x24; break;
      case 4: text = R6GameServiceAddresses::WideTextLOGINFAILNOTREGISTERED; state = 2; offset = 0x30; break;
      case 3: text = R6GameServiceAddresses::WideTextLOGINFAILALREADYCONNECTED; state = 3; offset = 0x3c; break;
      case 100: text = R6GameServiceAddresses::WideTextLOGINFAILDATABASEFAILED; state = 4; offset = 0x48; break;
      case 501: text = R6GameServiceAddresses::WideTextLOGINFAILBANNEDACCOUNT; state = 5; offset = 0x78; break;
      case 502: text = R6GameServiceAddresses::WideTextLOGINFAILBLOCKEDACCOUNT; state = 6; offset = 0x6c; break;
      case 512: text = R6GameServiceAddresses::WideTextLOGINFAILLOCKEDACCOUNT; state = 7; offset = 0x60; break;
      default: text = R6GameServiceAddresses::WideTextLOGINFAILDEFAULT; state = 8; offset = 0x54; break;
      }
      FString* message = reinterpret_cast<FString*>(nativeFrame - offset);
      FString::FString(message, reinterpret_cast<const TCHAR*>(text));
      UR6AbstractGameManager* manager = GR6GameManager;
      *reinterpret_cast<byte*>(nativeFrame - 4) = state;
      manager->eventGMProcessMsg(*message);
      *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
      FString::~FString(message);
    } else if (loginReply == 38) {
      const TCHAR* account = appFromAnsi(reinterpret_cast<const char*>(0x10091d48));
      *reinterpret_cast<FStringNoInit*>(reinterpret_cast<byte*>(receiver) + 0x34) = account;
      *reinterpret_cast<int*>(0x10091c14) = 6;
      *reinterpret_cast<int*>(0x10091e68) = 1;
      receiver->SaveConfig(0x4000, nullptr);
      *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x194) &= 0xfffffeff;
    }
    // Sample the join reply before clearing the login reply; no redispatch of callback-written login status.
    const uint joinReply = *reinterpret_cast<uint*>(0x10091be0);
    *reinterpret_cast<int*>(0x10091c10) = 0;
    if (joinReply == 39) {
      const uint error = *reinterpret_cast<uint*>(0x10091bfc);
      *reinterpret_cast<int*>(R6GameServiceAddresses::GLoginRequested) = 3;
      uint text;
      byte state;
      uint offset;
      if (error == 2) {
        text = R6GameServiceAddresses::WideTextJOINSERVERFAILPASSWORDNOTCORRECT; state = 9; offset = 0x60;
      } else if (error == 3) {
        text = R6GameServiceAddresses::WideTextJOINSERVERFAILROOMFULL; state = 10; offset = 0x6c;
      } else {
        text = R6GameServiceAddresses::WideTextJOINSERVERFAILDEFAULT; state = 11; offset = 0x78;
      }
      FString* message = reinterpret_cast<FString*>(nativeFrame - offset);
      FString::FString(message, reinterpret_cast<const TCHAR*>(text));
      UR6AbstractGameManager* manager = GR6GameManager;
      *reinterpret_cast<byte*>(nativeFrame - 4) = state;
      manager->eventGMProcessMsg(*message);
      *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
      FString::~FString(message);
      *reinterpret_cast<int*>(R6GameServiceAddresses::GJoinInProgress) = 0;
    } else if (joinReply == 38) {
      *reinterpret_cast<int*>(R6GameServiceAddresses::GLoginRequested) = 6;
      *reinterpret_cast<int*>(R6GameServiceAddresses::GLoggedInUbiDotCom) = 1;
    }
    const int lobbyDisconnected = *reinterpret_cast<int*>(0x10091bf0);
    *reinterpret_cast<int*>(0x10091be0) = 0;
    if (lobbyDisconnected) {
      *reinterpret_cast<int*>(0x10091bf0) = 0;
      *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x2c) |= 0x10;
    }
    if (*reinterpret_cast<int*>(0x10091c08)) {
      *reinterpret_cast<int*>(0x10091c08) = 0;
      *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x2c) |= 0x20;
    }
  }
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x4
  }
}

// Forwards the caught pointer from inherited EBP-0x18 through-0x14.
// R6GameService.dll @ 10006c55 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch20(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PollMSClientCallbacks context and rethrows the active exception.
// R6GameService.dll @ 10006c69 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch21(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPollMSClientCallbacks
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the thirteen-state MS poll guard with eleven distinct message-string cleanup actions.
// R6GameService.dll @ 100638f3 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacksExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the MS failure-message string at inherited EBP-0x24.
// R6GameService.dll @ 10063890 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x30.
// R6GameService.dll @ 10063899 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x3c.
// R6GameService.dll @ 100638a2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x48.
// R6GameService.dll @ 100638ab : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x54.
// R6GameService.dll @ 100638b4 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x60.
// R6GameService.dll @ 100638bd : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x6c.
// R6GameService.dll @ 100638c6 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x78.
// R6GameService.dll @ 100638cf : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x78.
// R6GameService.dll @ 100638d8 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x6c.
// R6GameService.dll @ 100638e1 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind11(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the MS failure-message string at inherited EBP-0x60.
// R6GameService.dll @ 100638ea : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollMSClientCallbacksUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// R6GameService.dll data @ 1000e9b4 : native CD-key dispatch destinations.
const uint GCDKeyActivationDispatch[6] = {
  R6GameServiceAddresses::GCDKeyActivationDispatchCase1,R6GameServiceAddresses::GCDKeyActivationDispatchCase2,R6GameServiceAddresses::GCDKeyActivationDispatchCase3,R6GameServiceAddresses::UR6GSServersBranch493,R6GameServiceAddresses::UR6GSServersBranch493,R6GameServiceAddresses::GCDKeyActivationDispatchCase6
};
// R6GameService.dll data @ 1000e9cc : native CD-key dispatch destinations.
const uint GCDKeyAuthorizationDispatch[7] = {
  R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase1,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase2,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase3,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase4,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase5,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase6,R6GameServiceAddresses::GCDKeyAuthorizationDispatchCase7
};
// R6GameService.dll data @ 1000e9e8 : native CD-key dispatch destinations.
const uint GCDKeyReplyDispatch[5] = {
  R6GameServiceAddresses::GCDKeyReplyDispatchCase1,R6GameServiceAddresses::UR6GSServersBranch538,R6GameServiceAddresses::GCDKeyReplyDispatchCase3,R6GameServiceAddresses::GCDKeyReplyDispatchCase4,R6GameServiceAddresses::GCDKeyReplyDispatchCase5
};

// R6GameService.dll data @ 1007d680 : native exception records.
const R6GameServiceNative::UnwindEntry UR6GSServers_PollClientCDKeyCallbacksUnwindMap[18] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind2},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind3},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind4},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind5},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind6},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind7},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind8},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind9},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind10},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind11},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind12},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind13},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind14},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind15},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind16},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwind17},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d710 : native exception records.
const R6GameServiceNative::CatchHandler GCDKeyPollHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch114},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch115},
};
// R6GameService.dll data @ 1007d730 : native exception records.
const R6GameServiceNative::TryBlock UR6GSServers_PollClientCDKeyCallbacksTryMap[1] = {
  {0x0, 0x10, 0x11, 0x2, R6GameServiceAddresses::GCDKeyPollHandlers},
};
// R6GameService.dll data @ 1007d744 : native exception records.
// R6GameService.dll data @ 1007d680 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_PollClientCDKeyCallbacksExceptionInfo = {
  0x19930520,
  0x12,
  R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksTryMap,
  0x0,
  0x0,
};

// Pumps enabled key contexts and advances activation and authorization, observing callback changes between phases.
// R6GameService.dll @ 1000dd90 : void(int,int,int), thiscall/RET12; globals and private field roles are inferred.
void __thiscall UR6GSServers::PollClientCDKeyCallbacks(int enabled,int requestInput,int validationInput)
{
  uint initialRS = *(uint *)0x10093410;
  const int pollingEnabled = enabled;
  using PumpABI = uint (__stdcall *)(void *,uint);
  using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  using LeafABI = void (__thiscall *)(UR6GSServers *);
  using MessageABI = void (__thiscall *)(void *,const FString *);
  using AssignABI = FStringNoInit *(__thiscall *)(FStringNoInit *,const FString *);
  using ConstructABI = FString *(__thiscall *)(FString *,const TCHAR *);
  // Reconstruction-only owner: native message cleanup arms after both live game-manager pointer reads.
  struct CompletedMessage {
    FString *value;
    // Release a completed message on normal scope exit or event-call unwinding.
    ~CompletedMessage() noexcept(false) { value->~FString(); }
  };
  try {
    if (initialRS != 0 && pollingEnabled != 0 && validationInput != 0) {
      uint result = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)
          (*(void **)R6GameServiceAddresses::GBaseCDKeyContext,500);
      if ((byte)result == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyEngineFAILED);
    }
    if (*(uint *)0x100933cc != 0) {
      if (pollingEnabled != 0 && validationInput != 0) {
        uint result = ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)
            (*(void **)R6GameServiceAddresses::GModCDKeyContext,500);
        if ((byte)result == 0 && *(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
              (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGSCDKeyEngineFAILED);
      }
      if (*(uint *)0x100933cc != 0 && pollingEnabled != 0 && requestInput != 0)
        ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)
            (*(void **)R6GameServiceAddresses::GModCDKeyContext,500);
    }
    if (*(uint *)0x10093410 == 0 || pollingEnabled == 0 || requestInput == 0)
      return;
    ((PumpABI)R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1)
        (*(void **)R6GameServiceAddresses::GBaseCDKeyContext,500);
    LogABI log;
    bool reloadLog = true;
    switch (*(uint *)R6GameServiceAddresses::GActivationState) {
    case 1: {
      uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
      log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      reloadLog = false;
      if (verbose != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextGECDKeyActIDRequestEGSREQFIRSTPASSPassD,
            *(uint *)R6GameServiceAddresses::GCDKeyRetryCount);
      if (*(int *)R6GameServiceAddresses::GCDKeyRetryCount >= 10) {
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSTimeoutPassed);
        *(uint *)R6GameServiceAddresses::GActivationState = 0;
        *(FString *)R6GameServiceAddresses::GServiceString8 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
        CancelGSCDKeyActID();
        ((LeafABI)(*(uint **)this)[0xb8 / 4])(this);
      } else {
        if (*(uint *)0x10093408 != 0) {
          *(FString *)R6GameServiceAddresses::GServiceString1 = *(FString *)R6GameServiceAddresses::GServiceString3;
          *(FString *)R6GameServiceAddresses::GServiceString8 = *(FString *)R6GameServiceAddresses::GServiceString5;
        } else {
          *(FString *)R6GameServiceAddresses::GServiceString1 =
              (const TCHAR *)R6GameServiceAddresses::WideTextRAVENSHIELD;
        }
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          const uint *words = (const uint *)R6GameServiceAddresses::GServiceString1;
          uint dataWord = words[0], countWord = words[1], capacityWord = words[2];
          log(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSMSzGameServiceGameNameS,dataWord,countWord,capacityWord);
        }
        *(float *)0x100934bc = (float)ReadCycleTimeSeconds();
        int selected = *(int *)0x10093408;
        RequestActivation(*(FString *)R6GameServiceAddresses::GServiceString8,selected);
        *(uint *)R6GameServiceAddresses::GActivationState = 2;
      }
      break;
    }
    case 2: {
      // Keep the clock subtraction in inherited x87 precision; compare is ordered and strictly greater than.
      float10 now = ReadCycleTimeSeconds();
      float10 elapsed = now - (float10)*(float *)0x100934bc;
      if (elapsed > (float10)*(float *)((byte *)this + 0x198)) {
        uint nextRetry = *(uint *)R6GameServiceAddresses::GCDKeyRetryCount + 1;
        *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = nextRetry;
        if ((int)nextRetry >= 10) {
          uint verbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
          log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
          reloadLog = false;
          if (verbose != 0)
            log(GLog,(const TCHAR *)R6GameServiceAddresses::
                WideTextProcessCDKeyActIDRequestEGSREQWAITINGFORRESPONSETimeoutPassed);
          *(uint *)R6GameServiceAddresses::GActivationState = 0;
          CancelGSCDKeyActID();
          ((LeafABI)(*(uint **)this)[0xb8 / 4])(this);
        } else {
          *(uint *)R6GameServiceAddresses::GActivationState = 1;
        }
      }
      break;
    }
    case 3: {
      uint failureVerbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
      log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      reloadLog = false;
      if (failureVerbose != 0) {
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILED);
        failureVerbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
      }
      switch (*(uint *)0x100933f4) {
      case 1: {
        bool allowLocal = false;
        if (*(uint *)0x10091e68 == 0) {
          if (*(FString *)R6GameServiceAddresses::GLastServerQueriedAddress !=
              (const TCHAR *)R6GameServiceAddresses::WideText02) {
            if (OnSameSubNet(*(FString *)R6GameServiceAddresses::GLastServerQueriedAddress) != 0)
              allowLocal = true;
            else
              failureVerbose = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
          } else {
            allowLocal = true;
          }
        }
        if (allowLocal) {
          if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
            log(GLog,(const TCHAR *)R6GameServiceAddresses::
                WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQSUCCESSAndMsgEMENUREQTIMEOUT);
          *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
          *(uint *)R6GameServiceAddresses::GActivationState = 6;
          ((LeafABI)(*(uint **)this)[0xb8 / 4])(this);
          *(FString *)R6GameServiceAddresses::GServiceString8 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
        } else {
          if (failureVerbose != 0)
            log(GLog,(const TCHAR *)R6GameServiceAddresses::
                WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQFAILEDAndMsgACTIDREQTIMEOUTER);
          {
            uint messageWords[3];
            FString *message = (FString *)messageWords;
            (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
                (message,(const TCHAR *)R6GameServiceAddresses::WideTextACTIDREQTIMEOUTERROR);
            void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
            void *manager = *managerSlot;
            CompletedMessage lifetime = {message};
            (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
                (manager,message);
          }
          ++*(uint *)R6GameServiceAddresses::GCDKeyRetryCount;
          RequestGSCDKeyActID();
        }
        break;
      }
      case 2:
        if (failureVerbose != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYINVALIDCDKEY);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextACTIDREQFAILINVALIDCDKEY);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
        *(uint *)R6GameServiceAddresses::GActivationState = 0;
        *(FString *)R6GameServiceAddresses::GServiceString8 = (const TCHAR *)R6GameServiceAddresses::GEmptyWideText;
        break;
      case 4:
        if (failureVerbose != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::
              WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYALREADYONLINE);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextACTIDREQFAILCDKEYUSED);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
        *(uint *)R6GameServiceAddresses::GActivationState = 0;
        break;
      default:
        if (failureVerbose != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndDefault);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextACTIDREQFAILDEFAULT);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        break;
      }
      break;
    }
    case 6: {
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
            (GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQSUCCESS);
      *(uint *)((byte *)this + 0x194) |= 1;
      using DefaultABI = AActor *(__thiscall *)(UClass *);
      UClass *actorClass = *(UClass **)R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot;
      AActor *actor = (*(DefaultABI *)R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot)(actorClass);
      FStringNoInit *globalId = (FStringNoInit *)((byte *)this + 0x1b8);
      {
        using GlobalTextABI = FString (__thiscall *)(AActor *,byte *);
        FString result = (*(GlobalTextABI *)R6GameServiceAddresses::Engine_AActor_GlobalIDToStringSlot)
            (actor,(byte *)0x10093418);
        (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)(globalId,&result);
      }
      if (*(uint *)0x10093408 != 0) {
        byte *modState = *(byte **)((byte *)this + 0x19c);
        uint ownerFlags = *(uint *)((byte *)this + 0x194);
        uint changed = (*(uint *)(modState + 0x3c) ^ ownerFlags) & 1;
        uint flags = *(uint *)(modState + 0x3c) ^ changed;
        *(uint *)(modState + 0x3c) = flags;
        *(FString *)R6GameServiceAddresses::GServiceString5 = *(FString *)R6GameServiceAddresses::GServiceString8;
        using NoInitCopyABI = FStringNoInit *(__thiscall *)(FStringNoInit *,const FStringNoInit *);
        (*(NoInitCopyABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot)
            ((FStringNoInit *)(*(byte **)((byte *)this + 0x19c) + 0x40),globalId);
        (*(AssignABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)
            (globalId,(const FString *)R6GameServiceAddresses::GServiceString10);
        for (uint index = 0; index < 16; ++index) {
          byte value = *(byte *)(0x100933e4 + index);
          byte *currentMod = *(byte **)((byte *)this + 0x19c);
          currentMod[0x2c + index] = value;
        }
      } else {
        for (uint index = 0; index < 16; ++index)
          *((byte *)this + 0x174 + index) = *(byte *)(0x100933e4 + index);
        *(FString *)R6GameServiceAddresses::GServiceString10 = *(FString *)globalId;
      }
      ((LeafABI)(*(uint **)this)[0xb8 / 4])(this);
      {
        uint messageWords[3];
        FString *message = (FString *)messageWords;
        (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
            (message,(const TCHAR *)R6GameServiceAddresses::WideTextACTIDREQSUCCESS);
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        CompletedMessage lifetime = {message};
        (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
            (manager,message);
      }
      *(uint *)R6GameServiceAddresses::GActivationState = 0;
      *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
      break;
    }
    default:
      break;
    }
    // Native reloads the log target on these paths, but retains it across the other activation callbacks above.
    if (reloadLog)
      log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    switch (*(uint *)R6GameServiceAddresses::GAuthorizationState) {
    case 1: {
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQFIRSTPASSPassD,
            *(uint *)R6GameServiceAddresses::GCDKeyRetryCount);
      *(float *)0x100934b8 = (float)ReadCycleTimeSeconds();
      if (*(uint *)0x10093408 != 0) {
        if (*(FString *)R6GameServiceAddresses::GServiceString5 !=
            (const TCHAR *)R6GameServiceAddresses::GEmptyWideText)
          *(FString *)R6GameServiceAddresses::GServiceString8 = *(FString *)R6GameServiceAddresses::GServiceString5;
        byte *modActivationId = *(byte **)((byte *)this + 0x19c) + 0x2c;
        CopyActivationIDInByteArray(modActivationId,(byte *)0x100933f8);
      } else {
        *(FString *)R6GameServiceAddresses::GServiceString8 = *(FString *)R6GameServiceAddresses::GServiceString9;
        CopyActivationIDInByteArray((byte *)this + 0x174,(byte *)0x100933f8);
      }
      RequestAuthorization(*(int *)0x10093408);
      *(uint *)R6GameServiceAddresses::GAuthorizationState = 2;
      return;
    }
    case 2: {
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::
            WideTextProcessCDKeyAuthorizationRequestEGSREQWAITINGFORRESPONSE);
      float10 now = ReadCycleTimeSeconds();
      float10 elapsed = now - (float10)*(float *)0x100934b8;
      if (elapsed > (float10)*(float *)((byte *)this + 0x198)) {
        uint nextRetry = *(uint *)R6GameServiceAddresses::GCDKeyRetryCount + 1;
        *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = nextRetry;
        if ((int)nextRetry < 10) {
          *(uint *)R6GameServiceAddresses::GAuthorizationState = 1;
        } else {
          if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
            log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextAndGoingEMENUREQTIMEOUT);
          {
            uint messageWords[3];
            FString *message = (FString *)messageWords;
            (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
                (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUT);
            void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
            void *manager = *managerSlot;
            CompletedMessage lifetime = {message};
            (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
                (manager,message);
          }
          *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
          CancelGSCDKeyActID();
        }
      }
      return;
    }
    case 3:
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQFAILED);
      {
        uint messageWords[3];
        FString *message = (FString *)messageWords;
        (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
            (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQFAILURE);
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        CompletedMessage lifetime = {message};
        (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
            (manager,message);
      }
      *(uint *)((byte *)this + 0x194) &= 0xfffffffe;
      *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
      break;
    case 4:
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQCONNECTFAILED);
      *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
      {
        uint messageWords[3];
        FString *message = (FString *)messageWords;
        (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
            (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUTERROR);
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        CompletedMessage lifetime = {message};
        (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
            (manager,message);
      }
      *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
      return;
    case 5:
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQINUSEFAILED);
      *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
      break;
    case 6: {
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
        log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQSUCCESS);
      int selected = *(int *)0x10093408;
      *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
      using FormatABI = FString (__cdecl *)(const uchar *);
      if (selected != 0) {
        FString formatted = ((FormatABI)R6GameServiceAddresses::FormatAuthenticationIdHex)((const uchar *)0x10093428);
        *(FString *)R6GameServiceAddresses::GServiceString11 = formatted;
      } else {
        FString formatted = ((FormatABI)R6GameServiceAddresses::FormatAuthenticationIdHex)((const uchar *)0x10093428);
        *(FString *)R6GameServiceAddresses::GServiceString4 = formatted;
      }
      if (IsAuthIDSuccess() == 0 && *(uint *)0x10093408 == 0) {
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        using FailureABI = void (__thiscall *)(void *,int);
        ((FailureABI)(*(uint **)manager)[0x80 / 4])(manager,1);
      } else {
        uint messageWords[3];
        FString *message = (FString *)messageWords;
        (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
            (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQSUCCESS);
        void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
        void *manager = *managerSlot;
        CompletedMessage lifetime = {message};
        (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
            (manager,message);
      }
      break;
    }
    case 7: {
      *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
      ((LeafABI)(*(uint **)this)[0xbc / 4])(this);
      switch (*(uint *)0x10093414) {
      case 1:
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          const uint *words = (const uint *)R6GameServiceAddresses::GLastServerQueriedAddress;
          uint dataWord = words[0], countWord = words[1], capacityWord = words[2];
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextMSzLastServerQueriedS,
              dataWord,countWord,capacityWord);
        }
        if (*(uint *)0x10091e68 == 0) {
          if (!(*(FString *)R6GameServiceAddresses::GLastServerQueriedAddress !=
              (const TCHAR *)R6GameServiceAddresses::WideText02) ||
              OnSameSubNet(*(FString *)R6GameServiceAddresses::GLastServerQueriedAddress) != 0) {
            if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
              log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextTIMEOUTERRORLetPlayerJoinAnyway);
            *(uint *)R6GameServiceAddresses::GAuthorizationState = 6;
            return;
          }
        }
        {
          uint nextRetry = *(uint *)R6GameServiceAddresses::GCDKeyRetryCount + 1;
          *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = nextRetry;
          if ((int)nextRetry < 10) {
            *(uint *)R6GameServiceAddresses::GAuthorizationState = 1;
          } else {
            if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
              log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextTIMEOUTERRORDonTLetPlayerJoinRemoteServer);
            {
              uint messageWords[3];
              FString *message = (FString *)messageWords;
              (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
                  (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUTERROR);
              void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
              void *manager = *managerSlot;
              CompletedMessage lifetime = {message};
              (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
                  (manager,message);
            }
            *(uint *)R6GameServiceAddresses::GAuthorizationState = 4;
            CancelGSCDKeyAuthID();
          }
        }
        return;
      case 3:
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextERRORCDKEYINTERNALERROR);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQNOTCHALLENGED);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
        break;
      case 4:
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideText2CDKeyIsAlreadyInUseERROR);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQINUSEERROR);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        *(uint *)R6GameServiceAddresses::GAuthorizationState = 5;
        break;
      case 5:
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0)
          log(GLog,(const TCHAR *)R6GameServiceAddresses::WideTextERRORCDKEYINTERNALERROR);
        {
          uint messageWords[3];
          FString *message = (FString *)messageWords;
          (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)
              (message,(const TCHAR *)R6GameServiceAddresses::WideTextAUTHIDREQINTERROR);
          void **managerSlot = *(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
          void *manager = *managerSlot;
          CompletedMessage lifetime = {message};
          (*(MessageABI *)R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot)
              (manager,message);
        }
        *(uint *)R6GameServiceAddresses::GAuthorizationState = 0;
        break;
      default:
        *(uint *)R6GameServiceAddresses::GAuthorizationState = 3;
        break;
      }
      break;
    }
    default:
      return;
    }
    *(uint *)R6GameServiceAddresses::GCDKeyRetryCount = 0;
  } catch (ushort *error) {
    throw error;
  } catch (...) {
    using UnwindABI = void (__cdecl *)(const ushort *,...);
    (*(UnwindABI *)R6GameServiceAddresses::Core__appUnwindfSlot)
        ((const ushort *)R6GameServiceAddresses::WideTextTextFormat,
         (const ushort *)R6GameServiceAddresses::WideTextUR6GSServersPollClientCDKeyCallbacks);
    throw;
  }
}

// Forwards the caught pointer from inherited EBP-0x18 through-0x14.
// R6GameService.dll @ 1000e982 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch114(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PollClientCDKeyCallbacks context and rethrows the active exception.
// R6GameService.dll @ 1000e996 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch115(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPollClientCDKeyCallbacks
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the eighteen-state CD-key poll guard with sixteen string cleanup actions.
// R6GameService.dll @ 100640b6 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x78.
// R6GameService.dll @ 10064020 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x24.
// R6GameService.dll @ 10064029 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x30.
// R6GameService.dll @ 10064032 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x3c.
// R6GameService.dll @ 1006403b : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x48.
// R6GameService.dll @ 10064044 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x54.
// R6GameService.dll @ 1006404d : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x54.
// R6GameService.dll @ 10064056 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind8(void)
{
  __asm {
    lea    ecx,[ebp-0x54]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x48.
// R6GameService.dll @ 1006405f : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind9(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x3c.
// R6GameService.dll @ 10064068 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind10(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x84.
// R6GameService.dll @ 10064071 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind11(void)
{
  __asm {
    lea    ecx,[ebp-0x84]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x90.
// R6GameService.dll @ 1006407d : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind12(void)
{
  __asm {
    lea    ecx,[ebp-0x90]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x30.
// R6GameService.dll @ 10064089 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind13(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x24.
// R6GameService.dll @ 10064092 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind14(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x60.
// R6GameService.dll @ 1006409b : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind15(void)
{
  __asm {
    lea    ecx,[ebp-0x60]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x6c.
// R6GameService.dll @ 100640a4 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind16(void)
{
  __asm {
    lea    ecx,[ebp-0x6c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the CD-key poll string temporary at inherited EBP-0x78.
// R6GameService.dll @ 100640ad : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollClientCDKeyCallbacksUnwind17(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// R6GameService.dll data @ 10011804 : native GS message dispatch destinations.
const uint GGSMessageDispatch[5] = {
  R6GameServiceAddresses::GGSMessageDispatchCase1,R6GameServiceAddresses::GGSMessageDispatchCase2,R6GameServiceAddresses::GGSMessageDispatchCase3,R6GameServiceAddresses::GGSMessageDispatchCase4,R6GameServiceAddresses::GGSMessageDispatchCase5
};

// R6GameService.dll data @ 1007dd30 : native exception records.
const R6GameServiceNative::UnwindEntry UR6GSServers_PollGSClientCallbacksUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacksUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007dd48 : native exception records.
const R6GameServiceNative::CatchHandler GGSPollHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -40,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch140},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch141},
};
// R6GameService.dll data @ 1007dd68 : native exception records.
const R6GameServiceNative::TryBlock UR6GSServers_PollGSClientCallbacksTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GGSPollHandlers},
};
// R6GameService.dll data @ 1007dd7c : native exception records.
// R6GameService.dll data @ 1007dd30 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_PollGSClientCallbacksExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacksUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacksTryMap,
  0x0,
  0x0,
};

// Clears match results, clears the submit-wait bit, then reports player-finished through the current client interface.
// R6GameService.dll @ 10011170 : RET0; match-finished uses the current interface after the submit-wait flag clears.
__declspec(naked) void __thiscall UR6GSServers::ProcessSubmitMatchResultReply(void)
{
  byte *receiver;
  uint clearedStatus;
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    push   esi
    push   edi
    mov    esi,ecx
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x34]
    mov    receiver,esi
    mov    clearedStatus,eax
  }
  uint logging = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
  using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
  LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
  if (logging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientClearMatchResultReturnedX,
        clearedStatus & 0x8000ffff);
  }
  *(uint *)(receiver + 0x2c) &= 0xfffffff7;
  if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientCallingPlayerMatchFinished);
  }
  void *client = *(void **)R6GameServiceAddresses::GGSClientInterface;
  byte *table = *(byte **)client;
  using FinishedABI = uint (__stdcall *)(void *);
  uint rawEax = (*(FinishedABI *)(table + 0x2c))(client);
  if ((int)rawEax < 0) {
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientERRORPlayerMatchFinishedErrorX,
          rawEax & 0x8000ffff);
    }
  } else {
    rawEax = *(uint *)R6GameServiceAddresses::GServiceVerboseLogging;
    if (rawEax != 0) {
      FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
      rawEax = logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientPlayerMatchFinishedReturnedSUCCESS);
    }
  }
  __asm {
    mov    eax,rawEax
    pop    edi
    pop    esi
    ret
  }
}

// Dispatches one GS message, advances client data/state and polls one prioritized start/wait/submit reply path.
// Output slot is not precleared; dispatch runs after retrieval failure. Server-start, client-start, submit have priority.
// R6GameService.dll @ 10011220 : RET4; one message and one prioritized reply path under the native swap-string guard.
__declspec(naked) void __thiscall UR6GSServers::PollGSClientCallbacks(int enabled)
{
  byte *nativeFrame,*receiver;
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacksSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x11c
    push   ebx
    push   esi
    push   edi
    mov    ebx,ecx
    lea    ecx,[ebp-0x24]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    nativeFrame,ebp
    mov    receiver,ebx
  }
  FString *swap = (FString *)(nativeFrame - 0x24);
  using DefaultABI = FString * (__thiscall *)(FString *);
  (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(swap);
  void *manager = **(void ***)R6GameServiceAddresses::Engine__GR6GameManagerSlot;
  bool managerInitialized = (*((byte *)manager + 0x2c) & 1) != 0;
  *(byte *)(nativeFrame - 4) = 1;
  if (managerInitialized && *(uint *)(nativeFrame + 8) != 0) {
    using GetABI = uint (__stdcall *)(void **,uint);
    uint retrieval = ((GetABI)R6GameServiceAddresses::GetLoadedGSClientMessage)
        ((void **)(nativeFrame - 0x18),0);
    if ((int)retrieval < 0) *(uint *)(receiver + 0x194) |= 8;
    void *message = *(void **)(nativeFrame - 0x18);
    ((uint (__stdcall *)(void *))R6GameServiceAddresses::DispatchLoadedGSClientMessage)(message);
    using ConvertABI = const TCHAR * (__cdecl *)(const char *);
    using NoInitWideABI = void * (__thiscall *)(void *,const TCHAR *);
    using AssignWideABI = FString& (__thiscall *)(FString *,const TCHAR *);
    using AssignABI = FString& (__thiscall *)(FString *,const FString&);
    using NoInitCopyABI = void * (__thiscall *)(void *,const FString&);
    using StateABI = uint (__thiscall *)(void *,uint);
    uint code = *(uint *)0x100938c8;
    switch (code) {
    case 0x10003:
      if (*(uint *)R6GameServiceAddresses::GGSClientState == 0) {
        using FormatABI = int (__cdecl *)(char *,const char *,...);
        FormatABI formatter;
        ConvertABI convert;
        const TCHAR *wide;
        // sprintf's four arguments remain below the one ANSI-conversion argument until both calls return.
        __asm {
          mov    ecx,DWORD PTR ds:0x100939d0
          mov    edi,DWORD PTR ds:R6GameServiceAddresses::MSVCR71_sprintfSlot
          push   ecx
          push   0x100934c0
          lea    edx,[ebp-0x128]
          push   R6GameServiceAddresses::TextSI
          push   edx
          call   edi
          mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
          lea    eax,[ebp-0x128]
          push   eax
          call   esi
          add    esp,0x14
          mov    formatter,edi
          mov    convert,esi
          mov    wide,eax
        }
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x1f4,wide);
        __asm {
          mov    edi,formatter
          mov    esi,convert
          mov    ecx,DWORD PTR ds:0x100939d0
          push   ecx
          push   0x100938d0
          lea    edx,[ebp-0x128]
          push   R6GameServiceAddresses::TextSI
          push   edx
          call   edi
          lea    eax,[ebp-0x128]
          push   eax
          call   esi
          add    esp,0x14
          mov    wide,eax
        }
        (*(AssignWideABI *)R6GameServiceAddresses::Core__4FStringSlot2)
            ((FString *)R6GameServiceAddresses::GServiceString12,wide);
        wide = convert((const char *)0x100937c8);
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x34,wide);
        wide = convert((const char *)0x100935c0);
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x20c,wide);
        byte *table = *(byte **)receiver;
        (*(StateABI *)(table + 0xcc))(receiver,1);
        using PingABI = int (__cdecl *)(const char *);
        int primaryPing = ((PingABI)R6GameServiceAddresses::ServerPing_GetPingTime)((const char *)0x100934c0);
        if (primaryPing >= 1000) {
          int secondaryPing = ((PingABI)R6GameServiceAddresses::ServerPing_GetPingTime)((const char *)0x100938d0);
          if (secondaryPing <= 1000) {
            (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)
                (swap,*(const FString *)R6GameServiceAddresses::GServiceString12);
            (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)
                ((FString *)R6GameServiceAddresses::GServiceString12,*(FString *)(receiver + 0x1f4));
            (*(NoInitCopyABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot3)(receiver + 0x1f4,*swap);
          }
        }
      }
      break;
    case 0x10004:
      if (*(uint *)R6GameServiceAddresses::GGSClientState == 2) {
        byte *table = *(byte **)receiver;
        (*(StateABI *)(table + 0xcc))(receiver,3);
      }
      break;
    case 0x10001:
      if (*(uint *)R6GameServiceAddresses::GGSClientState == 0) {
        ConvertABI convert = *(ConvertABI *)R6GameServiceAddresses::Core__appFromAnsiSlot;
        const TCHAR *wide = convert((const char *)0x100937c8);
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x34,wide);
        wide = convert((const char *)0x100936c8);
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x200,wide);
        wide = convert((const char *)0x100935c0);
        (*(NoInitWideABI *)R6GameServiceAddresses::Core__4FStringNoInitSlot2)(receiver + 0x20c,wide);
        byte *table = *(byte **)receiver;
        (*(StateABI *)(table + 0xcc))(receiver,5);
        uint players = *(uint *)0x100938cc;
        *(uint *)(receiver + 0x190) = players;
      }
      break;
    case 0x10002:
      if (*(uint *)R6GameServiceAddresses::GGSClientState == 6) {
        byte *table = *(byte **)receiver;
        (*(StateABI *)(table + 0xcc))(receiver,7);
      }
      break;
    case 0x10005: {
      byte *table = *(byte **)receiver;
      (*(StateABI *)(table + 0xcc))(receiver,9);
      break;
    }
    case 0x11000:
      if (*(uint *)0x100936c0 == 0x80006212) *(uint *)(receiver + 0x194) |= 0x10;
      break;
    }
    *(uint *)0x100938c8 = 0;
    uint waiting = *(uint *)(receiver + 0x2c);
    using ComABI = uint (__stdcall *)(void *);
    using LogABI = uint (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    if ((waiting & 1) != 0) {
      void *client = *(void **)R6GameServiceAddresses::GGSClientInterface;
      byte *table = *(byte **)client;
      uint status = (*(ComABI *)(table + 0x40))(client);
      bool consume;
      bool printStatus = false;
      const TCHAR *diagnostic;
      if ((int)status >= 0) {
        consume = true;
        printStatus = true;
        diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERCheckStartMatchReplyCBReceivedSUCCESSResultCodeIsX;
      } else {
        uint error = status & 0x8000ffff;
        switch (error) {
        case 0x80004005:
          consume = true;
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSEFAIL;
          break;
        case 0x80006204:
          consume = true;
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSENOTMASTER;
          break;
        case 0x80006209:
          consume = true;
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSEMATCHNOTFINISHED;
          break;
        case 0x80006207:
          consume = false;
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERNOREPLYCheckStartMatchReplyGSENOREPLY;
          break;
        default:
          consume = false;
          printStatus = true;
          diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyX;
          break;
        }
      }
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
        if (printStatus) logger(device,diagnostic,status);
        else logger(device,diagnostic);
      }
      if (consume) *(uint *)(receiver + 0x2c) &= 0xfffffffe;
    } else if ((waiting & 2) != 0) {
      void *bstr = *(void **)R6GameServiceAddresses::GServiceBstr;
      void *client = *(void **)R6GameServiceAddresses::GGSClientInterface;
      byte *table = *(byte **)client;
      using WaitABI = uint (__stdcall *)(void *,void *,void *);
      uint status = (*(WaitABI *)(table + 0x20))(client,nullptr,bstr);
      uint masked = status & 0x8000ffff;
      if (masked == 0) {
        uint remaining = *(uint *)(receiver + 0x2c);
        LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
        remaining &= 0xfffffffd;
        *(uint *)(receiver + 0x2c) = remaining;
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingPlayerMatchStarted);
        }
        client = *(void **)R6GameServiceAddresses::GGSClientInterface;
        table = *(byte **)client;
        status = (*(ComABI *)(table + 0x28))(client);
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          if ((int)status < 0)
            logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientERRORPlayerMatchStartedErrorX,
                status & 0x8000ffff);
          else logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientPlayerMatchStartedReturnedSUCCESS);
          if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
            device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
            logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingInitMatchResults);
          }
        }
        client = *(void **)R6GameServiceAddresses::GGSClientInterface;
        table = *(byte **)client;
        (*(ComABI *)(table + 0x30))(client);
        client = *(void **)R6GameServiceAddresses::GGSClientInterface;
        table = *(byte **)client;
        (*(ComABI *)(table + 0x34))(client);
        client = *(void **)R6GameServiceAddresses::GGSClientInterface;
        table = *(byte **)client;
        status = (*(ComABI *)(table + 0x30))(client);
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          if ((int)status < 0)
            logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientERRORInitMatchResultsErrorX,
                status & 0x8000ffff);
          else logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientInitMatchResultsReturnedSUCCESS);
        }
      } else if ((int)status < 0) {
        *(uint *)(receiver + 0x2c) &= 0xfffffffd;
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          (*(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot)
              (device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientERRORWaitMatchStartedErrorX,masked);
        }
      }
    } else if ((waiting & 8) != 0) {
      void *client = *(void **)R6GameServiceAddresses::GGSClientInterface;
      byte *table = *(byte **)client;
      uint status = (*(ComABI *)(table + 0x44))(client);
      LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
        FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
        logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientCheckSubmitMatchReplyReturnedCodeX,status);
      }
      uint masked = status & 0x8000ffff;
      if (masked != 0x80006207) {
        if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
          FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
          if ((int)status < 0)
            logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientERRORCheckSubmitMatchReplyErrorX,masked);
          else logger(device,(const TCHAR *)R6GameServiceAddresses::WideTextGSClientCheckSubmitMatchReplySuccessfull);
        }
        ((void (__thiscall *)(void *))R6GameServiceAddresses::UR6GSServers_ProcessSubmitMatchResultReply)(receiver);
      }
    }
  }
  *(byte *)(nativeFrame - 4) = 0;
  using DestroyABI = uint (__thiscall *)(FString *);
  uint rawEax = (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(swap);
  __asm {
    mov    eax,rawEax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
  }
}

// Forwards the caught pointer from inherited EBP-0x28 through-0x14.
// R6GameService.dll @ 100117d3 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch140(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x28]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports PollGSClientCallbacks context and rethrows the active exception.
// R6GameService.dll @ 100117e7 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch141(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersPollGSClientCallbacks
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the poll address-swap temporary at inherited EBP-0x24.
// R6GameService.dll @ 100642d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollGSClientCallbacksUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state GS poll guard protecting its address-swap temporary.
// R6GameService.dll @ 100642d9 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_PollGSClientCallbacksSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacksExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Logs new and current GS state through one cached logger, then publishes the captured input byte as a full word.
// Unknown previous-state diagnostic prints the NEW byte; its logger is cached but output device and old state reload.
// R6GameService.dll @ 10010bc0 : RET4; input byte is captured once, previous full state is sampled after the first diagnostic.
__declspec(naked) void __thiscall UR6GSServers::SetGSGameState(uchar newState)
{
  uint logging,output;
  byte captured;
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    mov    logging,eax
    mov    captured,bl
  }
  if (logging != 0) {
    __asm {
      push   esi
      push   edi
    }
    uint next = captured;
    const TCHAR *diagnostic;
    switch (next) {
    case 0: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSWAITINGFORGSINIT; break;
    case 1: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTINITRCVD; break;
    case 2: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTWAITINGCHSTA; break;
    case 3: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTCHSTARCVD; break;
    case 4: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTINGAME; break;
    case 5: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERINITRCVD; break;
    case 6: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERWAITINGCHSTA; break;
    case 7: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERCHSTARCVD; break;
    case 8: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERSETTINGUPGAME; break;
    case 9: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSTERMINATERCVD; break;
    case 10: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERREADY; break;
    default: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsD; break;
    }
    FOutputDevice *device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    using LogABI = void (__cdecl *)(FOutputDevice *,const TCHAR *,...);
    LogABI logger = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
    if (next <= 10) logger(device,diagnostic);
    else logger(device,diagnostic,next);
    uint previous = *(uint *)R6GameServiceAddresses::GGSClientState;
    switch (previous) {
    case 0: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSWAITINGFORGSINIT; break;
    case 1: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTINITRCVD; break;
    case 2: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTWAITINGCHSTA; break;
    case 3: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTCHSTARCVD; break;
    case 4: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTINGAME; break;
    case 5: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERINITRCVD; break;
    case 6: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERWAITINGCHSTA; break;
    case 7: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERCHSTARCVD; break;
    case 8: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERSETTINGUPGAME; break;
    case 9: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSTERMINATERCVD; break;
    case 10: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERREADY; break;
    default: diagnostic = (const TCHAR *)R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsD; break;
    }
    device = **(FOutputDevice ***)R6GameServiceAddresses::Core__GLogSlot;
    if (previous <= 10) {
      logger(device,diagnostic);
      __asm {
        pop    edi
        movzx  eax,bl
        pop    esi
        mov    output,eax
      }
      *(uint *)R6GameServiceAddresses::GGSClientState = output;
      __asm {
        mov    eax,output
        pop    ebx
        ret    0x4
      }
    }
    // The unknown-previous-state diagnostic deliberately prints the captured NEW byte.
    logger(device,diagnostic,next);
    __asm {
      pop    edi
      pop    esi
    }
  }
  __asm {
    movzx  eax,bl
    mov    output,eax
  }
  *(uint *)R6GameServiceAddresses::GGSClientState = output;
  __asm {
    mov    eax,output
    pop    ebx
    ret    0x4
  }
}

// Returns the low game-state byte in AL without changing the upper EAX bytes.
// R6GameService.dll @ 10010f00 : only AL changes; upper EAX residue and the implicit unused receiver are preserved.
__declspec(naked) uchar __thiscall UR6GSServers::GetGSGameState(void)
{
  uint incoming;
  __asm {
    mov    incoming,eax
  }
  byte state = *(byte *)R6GameServiceAddresses::GGSClientState;
  uint rawEax = (incoming & 0xffffff00) | state;
  __asm {
    mov    eax,rawEax
    ret
  }
}

// R6GameService.dll data @ 10010e9c : native GS state diagnostic dispatch destinations.
const uint GGSStateLogDispatch[11] = {
  R6GameServiceAddresses::GGSStateLogDispatchCase1,R6GameServiceAddresses::GGSStateLogDispatchCase2,R6GameServiceAddresses::GGSStateLogDispatchCase3,R6GameServiceAddresses::GGSStateLogDispatchCase4,R6GameServiceAddresses::GGSStateLogDispatchCase5,
  R6GameServiceAddresses::GGSStateLogDispatchCase6,R6GameServiceAddresses::GGSStateLogDispatchCase7,R6GameServiceAddresses::GGSStateLogDispatchCase8,R6GameServiceAddresses::GGSStateLogDispatchCase9,R6GameServiceAddresses::GGSStateLogDispatchCase10,R6GameServiceAddresses::GGSStateLogDispatchCase11
};

// R6GameService.dll data @ 10010ec8 : native GS state diagnostic dispatch destinations.
const uint UR6GSServersGGSStateLogDispatch[11] = {
  R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase1,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase2,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase3,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase4,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase5,
  R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase6,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase7,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase8,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase9,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase10,R6GameServiceAddresses::UR6GSServersGGSStateLogDispatchCase11
};

// R6GameService.dll data @ 1007c47c : native initialization guard records.
const R6GameServiceNative::UnwindEntry UR6GSServers_InitUnwindMap[4] = {
  {-1, R6GameServiceAddresses::UR6GSServers_InitUnwind1},
  {0x0, R6GameServiceAddresses::UR6GSServers_InitUnwind2},
  {0x0, R6GameServiceAddresses::UR6GSServers_InitUnwind3},
  {0x0, R6GameServiceAddresses::UR6GSServers_InitUnwind4},
};
// R6GameService.dll data @ 1007c49c : native initialization guard records.
const R6GameServiceNative::FuncInfo UR6GSServers_InitExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::UR6GSServers_InitUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007c4b8 : native initialization guard records.
const R6GameServiceNative::UnwindEntry UR6GSServers_execInitializeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007c4c8 : native initialization guard records.
const R6GameServiceNative::CatchHandler GGSInitHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch48},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch49},
};
// R6GameService.dll data @ 1007c4e8 : native initialization guard records.
const R6GameServiceNative::TryBlock UR6GSServers_execInitializeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GGSInitHandlers},
};
// R6GameService.dll data @ 1007c4fc : native initialization guard records.
// R6GameService.dll data @ 1007c4b8 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_execInitializeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_execInitializeUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_execInitializeTryMap,
  0x0,
  0x0,
};

// Initializes shared clients, refreshes router configuration and publishes availability; owns the incoming address string.
// File bytes have no added terminator/free guard; appends retain prior rows and read all three router fields.
// Input cleanup arms after the initial flag read; only unfinished client allocations receive free actions.
// R6GameService.dll @ 10007eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::Init(UR6GSServers *this,FString localIpAddress)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_InitSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    eax,0x1518
    mov    DWORD PTR fs:0x0,esp
    call   R6GameServiceAddresses::__chkstk
    push   ebx
    push   ebp
    push   esi
    mov    ebx,ecx
    push   edi
    mov    DWORD PTR [esp+0x18],ebx
  }
  // Native ESP-relative frame: registration state +0x1530, owned incoming FString +0x1538, saved owner +0x18.
  byte* nativeStack;
  __asm { mov nativeStack,esp }
  UR6GSServers* initialReceiver;
  __asm { mov initialReceiver,ebx }
  char* temporaryFile = reinterpret_cast<char*>(nativeStack + 0x1c);
  *reinterpret_cast<uint*>(temporaryFile) = *reinterpret_cast<uint*>(R6GameServiceAddresses::TextTempDat);
  *reinterpret_cast<uint*>(temporaryFile + 4) = *reinterpret_cast<uint*>(R6GameServiceAddresses::TextMpDat);
  *reinterpret_cast<ushort*>(temporaryFile + 8) = *reinterpret_cast<ushort*>(R6GameServiceAddresses::TextAt);
  temporaryFile[10] = *reinterpret_cast<char*>(0x1006db2a); // "./temp.dat" including its native extra zero byte.
  const int alreadyInitialized = *reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized);
  *reinterpret_cast<int*>(nativeStack + 0x1530) = 0;
  if (!alreadyInitialized) {
    *reinterpret_cast<FString*>(R6GameServiceAddresses::GLastServerQueriedAddress) =
        reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideText02);
    FString* localAddress = reinterpret_cast<FString*>(nativeStack + 0x1538);
    const TCHAR* addressText = **localAddress;
    using CompareCall = int (__cdecl *)(const TCHAR*, const TCHAR*);
    CompareCall compare = *reinterpret_cast<CompareCall*>(R6GameServiceAddresses::Core__appStrcmpSlot);
    const int emptyComparison = compare(addressText, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::GEmptyWideText));
    using ToAnsiCall = char* (__cdecl *)(const TCHAR*);
    ToAnsiCall toAnsi = *reinterpret_cast<ToAnsiCall*>(R6GameServiceAddresses::Core__appToAnsiSlot);
    char* boundAddress = nullptr;
    if (emptyComparison != 0 && compare(**localAddress,
        reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideText0000)) != 0)
      boundAddress = toAnsi(**localAddress);
    const uint socketResult = static_cast<byte>(ResolveAddressText(boundAddress));
    if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging))
      GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextInitializeSocketsI), socketResult);
    auto createStore = [&](uint globalAddress, byte constructionState) {
      if (!*reinterpret_cast<void**>(globalAddress)) {
        void* block = GMalloc->Malloc(0x24, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextNew));
        *reinterpret_cast<void**>(nativeStack + 0x10) = block;
        *reinterpret_cast<byte*>(nativeStack + 0x1530) = constructionState;
        void* store = block ? InitializeSerializedByteStore(reinterpret_cast<uint*>(block)) : nullptr;
        *reinterpret_cast<byte*>(nativeStack + 0x1530) = 0;
        *reinterpret_cast<void**>(globalAddress) = store;
      }
    };
    createStore(R6GameServiceAddresses::GPublicSerializedStore, 1);
    createStore(R6GameServiceAddresses::GPrivateSerializedStore, 2);
    if (!*reinterpret_cast<void**>(0x10091e50)) {
      void* block = GMalloc->Malloc(12, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextNew));
      *reinterpret_cast<void**>(nativeStack + 0x10) = block;
      *reinterpret_cast<byte*>(nativeStack + 0x1530) = 3;
      void* pingArray = block ? InitializePingRequestArray(reinterpret_cast<FArray*>(block)) : nullptr;
      *reinterpret_cast<byte*>(nativeStack + 0x1530) = 0;
      *reinterpret_cast<void**>(0x10091e50) = pingArray;
    }
    void* wrapper = TailForwardServiceWrapperRegistration();
    if (wrapper) {
      const TCHAR* gameText = **reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString1);
      char* game = toAnsi(gameText);
      byte* originalOwner = reinterpret_cast<byte*>(initialReceiver);
      char* user = toAnsi(**reinterpret_cast<FString*>(originalOwner + 0x34));
      char* format = toAnsi(**reinterpret_cast<FString*>(originalOwner + 0x1a0));
      char* remoteFile = reinterpret_cast<char*>(nativeStack + 0x128);
      sprintf(remoteFile, format, user, game);
      if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
        const TCHAR* remoteText = appFromAnsi(remoteFile);
        GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRemoteFileNameS), remoteText);
      }
      *reinterpret_cast<int*>(0x10091be8) = 0;
      QueueServiceDownload(wrapper, remoteFile, temporaryFile, 1, ReportServiceDownload, 0);
      ReleaseRegisteredServiceWrapper(wrapper); // Release before observing the callback's current completion flag.
      using FormatCall = int (__cdecl *)(TCHAR*, const TCHAR*, ...);
      FormatCall formatWide = *reinterpret_cast<FormatCall*>(R6GameServiceAddresses::Core__appSprintfSlot);
      bool proceed = true;
      if (*reinterpret_cast<int*>(0x10091be8)) {
        FILE* file = fopen(temporaryFile, reinterpret_cast<const char*>(R6GameServiceAddresses::WideTextR));
        fseek(file, 0, 2); // Native does not check fopen before using its return value.
        const int size = ftell(file);
        *reinterpret_cast<int*>(nativeStack + 0x14) = size;
        if (size <= 0) {
          fclose(file);
          proceed = false;
        } else {
          rewind(file);
          char* fileBytes = static_cast<char*>(GMalloc->Malloc(size,
              reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextGAMESERVICE)));
          fread(fileBytes, size, 1, file);
          TCHAR* firstRouterKey = reinterpret_cast<TCHAR*>(nativeStack + 0x228);
          formatWide(firstRouterKey, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterIPI), 0);
          char* firstLine = reinterpret_cast<char*>(nativeStack + 0x628);
          const char* key = toAnsi(firstRouterKey);
          const int extracted = ExtractLineValue(fileBytes, key, firstLine);
          fclose(file);
          // fileBytes has no added terminator or cleanup, including on failure; preserve this native lifetime.
          if (extracted) {
            byte* currentOwner = *reinterpret_cast<byte**>(nativeStack + 0x18);
            FString* configName = reinterpret_cast<FString*>(currentOwner + 0x1e8);
            remove(toAnsi(**configName));
            const char* destination = toAnsi(**configName);
            rename(temporaryFile, destination);
          } else {
            remove(temporaryFile);
          }
        }
      } else {
        remove(temporaryFile);
      }
      if (proceed) {
        uint& routerNumber = *reinterpret_cast<uint*>(nativeStack + 0x14);
        routerNumber = 0;
        char* valueBuffer = reinterpret_cast<char*>(nativeStack + 0x28);
        TCHAR* ipKey = reinterpret_cast<TCHAR*>(nativeStack + 0xd28);
        TCHAR* portKey = reinterpret_cast<TCHAR*>(nativeStack + 0x928);
        TCHAR* launcherKey = reinterpret_cast<TCHAR*>(nativeStack + 0x1128);
        TCHAR* ipText = reinterpret_cast<TCHAR*>(nativeStack + 0xb28);
        TCHAR* portText = reinterpret_cast<TCHAR*>(nativeStack + 0x728);
        TCHAR* launcherText = reinterpret_cast<TCHAR*>(nativeStack + 0x428);
        bool allFields;
        do {
          formatWide(ipKey, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterIPI), routerNumber);
          formatWide(portKey, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterPortI2), routerNumber);
          formatWide(launcherKey,
              reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterLauncherPortI2), routerNumber);
          byte* currentOwner = *reinterpret_cast<byte**>(nativeStack + 0x18);
          FString* configName = reinterpret_cast<FString*>(currentOwner + 0x1e8);
          auto readRouterField = [&](TCHAR* key, TCHAR* output) {
            const char* filename = toAnsi(**configName);
            const char* narrowKey = toAnsi(key);
            const uint length = GetPrivateProfileStringA(
                reinterpret_cast<const char*>(R6GameServiceAddresses::TextServers), narrowKey,
                reinterpret_cast<const char*>(R6GameServiceAddresses::GEmptyWideTextAlternate), valueBuffer, 256, filename);
            const TCHAR* wideValue = appFromAnsi(valueBuffer);
            formatWide(output, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextTextFormat), wideValue);
            return length != 0;
          };
          allFields = readRouterField(ipKey, ipText);
          const bool hasPort = readRouterField(portKey, portText);
          allFields = allFields & hasPort;
          const bool hasLauncher = readRouterField(launcherKey, launcherText);
          allFields = allFields & hasLauncher; // All three providers run, even after an earlier empty field.
          if (allFields) {
            FArray* routers = reinterpret_cast<FArray*>(R6GameServiceAddresses::GServiceArray1);
            const int added = routers->Add(1, 0x108);
            const uint offset = static_cast<uint>(added) * 0x108U;
            byte* row = *reinterpret_cast<byte**>(routers) + offset;
            *reinterpret_cast<byte**>(nativeStack + 0x10) = row;
            const int launcher = appAtoi(launcherText);
            row = *reinterpret_cast<byte**>(nativeStack + 0x10);
            *reinterpret_cast<int*>(row + 0x104) = launcher;
            row = *reinterpret_cast<byte**>(routers) + offset;
            *reinterpret_cast<byte**>(nativeStack + 0x10) = row;
            const int port = appAtoi(portText);
            row = *reinterpret_cast<byte**>(nativeStack + 0x10);
            *reinterpret_cast<int*>(row + 0x100) = port;
            const char* source = toAnsi(ipText);
            char* destination = reinterpret_cast<char*>(*reinterpret_cast<byte**>(routers) + offset);
            byte copied;
            do { copied = *source++; *destination++ = copied; } while (copied); // No native length guard.
            if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
              const TCHAR* name = appFromAnsi(reinterpret_cast<char*>(*reinterpret_cast<byte**>(routers) + offset));
              GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterNameS), name);
              row = *reinterpret_cast<byte**>(routers);
              const int currentLauncher = *reinterpret_cast<int*>(row + offset + 0x104);
              GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterLauncherPortI), currentLauncher);
              row = *reinterpret_cast<byte**>(routers);
              const int currentPort = *reinterpret_cast<int*>(row + offset + 0x100);
              GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRouterPortI), currentPort);
            }
          }
          ++routerNumber;
        } while (allFields);
        TCHAR* keyIP = reinterpret_cast<TCHAR*>(nativeStack + 0xf28);
        TCHAR* keyPort = reinterpret_cast<TCHAR*>(nativeStack + 0x1328);
        formatWide(keyIP, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCDKeyServerIP0));
        formatWide(keyPort, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCDKeyServerPort0));
        byte* currentOwner = *reinterpret_cast<byte**>(nativeStack + 0x18);
        FString* configName = reinterpret_cast<FString*>(currentOwner + 0x1e8);
        const char* filename = toAnsi(**configName);
        const char* narrowKey = toAnsi(keyIP);
        using ProfileCall = uint (__stdcall *)(const char*, const char*, const char*, char*, uint, const char*);
        ProfileCall profile = *reinterpret_cast<ProfileCall*>(R6GameServiceAddresses::KERNEL32_GetPrivateProfileStringASlot);
        profile(reinterpret_cast<const char*>(R6GameServiceAddresses::TextServers), narrowKey,
            reinterpret_cast<const char*>(R6GameServiceAddresses::GEmptyWideTextAlternate),
            reinterpret_cast<char*>(0x10091c28), 256, filename);
        filename = toAnsi(**configName);
        narrowKey = toAnsi(keyPort);
        profile(reinterpret_cast<const char*>(R6GameServiceAddresses::TextServers), narrowKey,
            reinterpret_cast<const char*>(R6GameServiceAddresses::GEmptyWideTextAlternate), valueBuffer, 256, filename);
        *reinterpret_cast<int*>(0x10091c04) = atoi(valueBuffer);
        if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
          const TCHAR* keyServer = appFromAnsi(reinterpret_cast<const char*>(0x10091c28));
          GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCDKeyNameS), keyServer);
          const int keyPortValue = *reinterpret_cast<int*>(0x10091c04);
          GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextCDKeyPortI), keyPortValue);
        }
        filename = toAnsi(**configName);
        if (profile(reinterpret_cast<const char*>(R6GameServiceAddresses::TextMaintenance),
            reinterpret_cast<const char*>(R6GameServiceAddresses::TextGS4UserAccountURL),
            reinterpret_cast<const char*>(R6GameServiceAddresses::GEmptyWideTextAlternate), valueBuffer, 256, filename)) {
          const TCHAR* homePage = appFromAnsi(valueBuffer);
          *reinterpret_cast<FStringNoInit*>(currentOwner + 0x1d0) = homePage;
        }
        if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
          const uint* homeHeader = reinterpret_cast<const uint*>(currentOwner + 0x1d0);
          const uint data = homeHeader[0], count = homeHeader[1], capacity = homeHeader[2];
          GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextMSzUbiHomePageS), data, count, capacity);
        }
        const int routerCount = *reinterpret_cast<int*>(R6GameServiceAddresses::GServiceArray1 + 4);
        *reinterpret_cast<int*>(R6GameServiceAddresses::GMSRouterIndex) = 0;
        *reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized) = routerCount > 0;
      }
    }
  }
  FString* ownedAddress = reinterpret_cast<FString*>(nativeStack + 0x1538);
  *reinterpret_cast<int*>(nativeStack + 0x1530) = -1;
  FString::~FString(ownedAddress);
  __asm {
    mov    ecx,DWORD PTR [esp+0x1528]
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    add    esp,0x1524
    ret    0xc
  }
}

// Finishes script debug data and, when uninitialized, transfers the actual local-IP return string to Init.
// R6GameService.dll @ 10008670 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execInitialize(UR6GSServers *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execInitializeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // Aliases below refer to the retained native frame; they do not define a new exception layout.
  byte* nativeFrame;
  UR6GSServers* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  FFrame* executionStack = *reinterpret_cast<FFrame**>(nativeFrame + 8);
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  byte* next = code + 1;
  code = next;
  const bool debugInfo = *next == 0x42;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (debugInfo) {
    UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
    code = next + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
    natives[0x42](context, executionStack, nullptr);
  }
  if (!*reinterpret_cast<int*>(R6GameServiceAddresses::GMSClientInitialized)) {
    // The hidden event result occupies the outgoing by-value argument. Init takes its ownership.
    __asm {
      sub esp,0xc
      mov ecx,esp
      mov DWORD PTR [ebp+0x8],esp
      push ecx
      mov ecx,esi
      call R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
      mov ecx,esi
      call R6GameServiceAddresses::UR6GSServers_Init
    }
  }
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x8
  }
}

// Copies the caught pointer from inherited EBP-0x18 through-0x14 and throws it.
// R6GameService.dll @ 100086f1 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch48(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports execInitialize context and rethrows the active exception.
// R6GameService.dll @ 10008705 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_UR6GSServersCatch49(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecInitialize
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys Init's incoming by-value FString at dispatcher-supplied virtual frame+4.
// R6GameService.dll @ 10063a60 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_InitUnwind1(void)
{
  __asm {
    lea    ecx,[ebp+0x4]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Frees the unfinished first client allocation saved at virtual frame-0x1524.
// R6GameService.dll @ 10063a69 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_InitUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1524]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Frees the unfinished second client allocation saved at virtual frame-0x1524.
// R6GameService.dll @ 10063a77 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_InitUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1524]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Frees the unfinished ping-array allocation saved at virtual frame-0x1524.
// R6GameService.dll @ 10063a85 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_InitUnwind4(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1524]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Selects Init's four-state input/allocation unwind map; it has no local catch.
// R6GameService.dll @ 10063a93 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_InitSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_InitExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the two-state execInitialize guard with no cleanup actions.
// R6GameService.dll @ 10063aa0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6GSServers_execInitializeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6GSServers_execInitializeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reports UR6GSServers::Destroy context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10005741 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersDestroy
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execGetMaxUbiServerNameSize context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000632c : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch11(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecGetMaxUbiServerNameSize
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::OnSameSubNet context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10006596 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch13(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersOnSameSubNet
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeGetMSClientInitialized context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000683e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch19(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeGetMSClientInitialized
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execIsRefreshServersInProgress context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100070c6 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch23(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecIsRefreshServersInProgress
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execStopRefreshServers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000717c : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch25(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecStopRefreshServers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    esi,esi
    push   esi
    push   esi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::MSCLientJoinServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100073e1 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch29(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersMSCLientJoinServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeMSCLientJoinServerByID context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007503 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch31(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeMSCLientJoinServerByID
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::MSClientServerConnected context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100075dc : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch33(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersMSClientServerConnected
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeMSClientReqAltInfo context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100076eb : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch35(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeMSClientReqAltInfo
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    edi,edi
    push   edi
    push   edi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessJoinServerRequest context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100079b4 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch39(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessJoinServerRequest
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessUbiComJoinServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007aad : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch41(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessUbiComJoinServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessIsRouterDisconnect context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007b7b : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch43(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessIsRouterDisconnect
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessIsLobbyDisconnect context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10007d15 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch47(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessIsLobbyDisconnect
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RefreshOneServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10009ea2 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch63(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRefreshOneServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeRefreshServer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10009f64 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch65(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeRefreshServer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execNativeSetMatchResult context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000a1d0 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch67(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecNativeSetMatchResult
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::SubmitMatchResult context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000a387 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch69(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersSubmitMatchResult
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::ProcessLoginMasterSrv context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000a9a3 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch71(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersProcessLoginMasterSrv
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    edi,edi
    push   edi
    push   edi
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::RefreshServers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000c1cd : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch85(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersRefreshServers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6GSServers::execRefreshServers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000c26c : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6GSServers_UR6GSServersCatch87(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6GSServersExecRefreshServers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Forwards inherited parent local FString at EBP-2c to current imported destructor.
// R6GameService.dll @ 10063be0 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindMatchResultFString(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Forwards reused first argument slot at inherited EBP+8, containing converted BSTR, to actual stored-string release.
// R6GameService.dll @ 10063be9 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UnwindMatchResultBstr(void)
{
  __asm {
    lea    ecx,[ebp+0x8]
    jmp    R6GameServiceAddresses::ReleaseStoredBstr
  }
}

// Selects match-result four-state FuncInfo and tail-forwards Windows C++ exception dispatch.
// R6GameService.dll @ 10063bf1 : native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMatchResultLifetime(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execNativeSetMatchResultExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007ca30 : exact match-result lifetime map/info words.
const R6GameServiceNative::UnwindEntry execNativeSetMatchResultUnwindMap[4] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UnwindMatchResultFString},
  {0x1, R6GameServiceAddresses::UnwindMatchResultBstr},
  {-1, 0x0},
};

// R6GameService.dll data @ 1007ca84 : exact match-result lifetime map/info words.
// Typed pointer handler precedes catch-all; the try spans states0..2, with catch state3.
// R6GameService.dll data @ 1007ca50 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6GSServersGMatchResultLifetimeData[2] = {
  {0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch66},
  {0, 0, 0, R6GameServiceAddresses::UR6GSServers_UR6GSServersCatch67},
};
// R6GameService.dll data @ 1007ca70 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeSetMatchResultTryMap[1] = {
  {0, 2, 3, 2, R6GameServiceAddresses::UR6GSServersGMatchResultLifetimeData},
};
// R6GameService.dll data @ 1007ca30 : native storage identity retained.
const R6GameServiceNative::FuncInfo execNativeSetMatchResultExceptionInfo = {
  0x19930520,
  0x4,
  R6GameServiceAddresses::execNativeSetMatchResultUnwindMap,
  0x1,
  R6GameServiceAddresses::execNativeSetMatchResultTryMap,
  0x0,
  0x0,
};

// Native virtual-table prefix: UR6GSServersDispatchTable
// R6GameService.dll data @ 1006ba10 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct UR6GSServersDispatchTableRecord {
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember22; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember21; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember20; // +0x08
  R6GameServiceNative::Address DeleteUR6GSServers; // +0x0c
  R6GameServiceNative::Address UObject_ProcessEvent; // +0x10
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember19; // +0x14
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember18; // +0x18
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember17; // +0x1c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember16; // +0x20
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember15; // +0x24
  R6GameServiceNative::Address UR6GSServers_Destroy; // +0x28
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
  R6GameServiceNative::Address UR6GSServers_InitGSCDKey; // +0x68
  R6GameServiceNative::Address UR6GSServers_GetRegServerInitialized; // +0x6c
  R6GameServiceNative::Address UR6GSServers_SetGameServiceRequestState; // +0x70
  R6GameServiceNative::Address UR6GSServers_SetRegServerLoginRequest; // +0x74
  R6GameServiceNative::Address UR6GSServers_SetLoginRegServer; // +0x78
  R6GameServiceNative::Address UR6GSServers_GetLoginRegServer; // +0x7c
  R6GameServiceNative::Address UR6GSServers_GetServerRegistered; // +0x80
  R6GameServiceNative::Address UR6GSServers_ServerRoundStart; // +0x84
  R6GameServiceNative::Address UR6GSServers_ServerRoundFinish; // +0x88
  R6GameServiceNative::Address UR6GSServers_SubmitMatchResult; // +0x8c
  R6GameServiceNative::Address UR6GSServers_DisconnectAllCDKeyPlayers; // +0x90
  R6GameServiceNative::Address UR6GSServers_CDKeyDisconnecUser; // +0x94
  R6GameServiceNative::Address UR6GSServers_GameServiceManager; // +0x98
  R6GameServiceNative::Address UR6GSServers_ProcessLoginMasterSrv; // +0x9c
  R6GameServiceNative::Address UR6GSServers_ProcessUbiComJoinServer; // +0xa0
  R6GameServiceNative::Address UR6GSServers_ProcessIsRouterDisconnect; // +0xa4
  R6GameServiceNative::Address UR6GSServers_ProcessIsLobbyDisconnect; // +0xa8
  R6GameServiceNative::Address UR6GSServers_ProcessJoinServer; // +0xac
  R6GameServiceNative::Address UR6GSServers_MasterServerManager; // +0xb0
  R6GameServiceNative::Address UR6GSServers_RequestModCDKeyProcess; // +0xb4
  R6GameServiceNative::Address UR6GSServers_RequestGSCDKeyAuthID; // +0xb8
  R6GameServiceNative::Address UR6GSServers_ResetAuthId; // +0xbc
  R6GameServiceNative::Address UR6GSServers_GetAuthID; // +0xc0
  R6GameServiceNative::Address UR6GSServers_InitGSClient; // +0xc4
  R6GameServiceNative::Address UR6GSServers_SetGSClientComInterface; // +0xc8
  R6GameServiceNative::Address UR6GSServers_SetGSGameState; // +0xcc
  R6GameServiceNative::Address UR6GSServers_GetGSGameState; // +0xd0
  R6GameServiceNative::Address UR6GSServers_GSClientPostMessage; // +0xd4
  R6GameServiceNative::Address UR6GSServers_MSCLientLeaveServer; // +0xd8
  R6GameServiceNative::Address UR6GSServers_IsMSClientIsInRequest; // +0xdc
  R6GameServiceNative::Address UR6GSServers_GetLoggedInUbiDotCom; // +0xe0
  R6GameServiceNative::Address UR6GSServers_IsServerJoined; // +0xe4
  R6GameServiceNative::Address UR6ServerList_SetOwnSvrPort; // +0xe8
  R6GameServiceNative::Address UR6ServerList_GetLobbyID; // +0xec
  R6GameServiceNative::Address UR6ServerList_GetGroupID; // +0xf0
};
const UR6GSServersDispatchTableRecord UR6GSServersDispatchTable = {
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember22,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember21,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember20,
  R6GameServiceAddresses::DeleteUR6GSServers,
  R6GameServiceAddresses::UObject_ProcessEvent,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember19,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember18,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember17,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember16,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember15,
  R6GameServiceAddresses::UR6GSServers_Destroy,
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
  R6GameServiceAddresses::UR6GSServers_InitGSCDKey,
  R6GameServiceAddresses::UR6GSServers_GetRegServerInitialized,
  R6GameServiceAddresses::UR6GSServers_SetGameServiceRequestState,
  R6GameServiceAddresses::UR6GSServers_SetRegServerLoginRequest,
  R6GameServiceAddresses::UR6GSServers_SetLoginRegServer,
  R6GameServiceAddresses::UR6GSServers_GetLoginRegServer,
  R6GameServiceAddresses::UR6GSServers_GetServerRegistered,
  R6GameServiceAddresses::UR6GSServers_ServerRoundStart,
  R6GameServiceAddresses::UR6GSServers_ServerRoundFinish,
  R6GameServiceAddresses::UR6GSServers_SubmitMatchResult,
  R6GameServiceAddresses::UR6GSServers_DisconnectAllCDKeyPlayers,
  R6GameServiceAddresses::UR6GSServers_CDKeyDisconnecUser,
  R6GameServiceAddresses::UR6GSServers_GameServiceManager,
  R6GameServiceAddresses::UR6GSServers_ProcessLoginMasterSrv,
  R6GameServiceAddresses::UR6GSServers_ProcessUbiComJoinServer,
  R6GameServiceAddresses::UR6GSServers_ProcessIsRouterDisconnect,
  R6GameServiceAddresses::UR6GSServers_ProcessIsLobbyDisconnect,
  R6GameServiceAddresses::UR6GSServers_ProcessJoinServer,
  R6GameServiceAddresses::UR6GSServers_MasterServerManager,
  R6GameServiceAddresses::UR6GSServers_RequestModCDKeyProcess,
  R6GameServiceAddresses::UR6GSServers_RequestGSCDKeyAuthID,
  R6GameServiceAddresses::UR6GSServers_ResetAuthId,
  R6GameServiceAddresses::UR6GSServers_GetAuthID,
  R6GameServiceAddresses::UR6GSServers_InitGSClient,
  R6GameServiceAddresses::UR6GSServers_SetGSClientComInterface,
  R6GameServiceAddresses::UR6GSServers_SetGSGameState,
  R6GameServiceAddresses::UR6GSServers_GetGSGameState,
  R6GameServiceAddresses::UR6GSServers_GSClientPostMessage,
  R6GameServiceAddresses::UR6GSServers_MSCLientLeaveServer,
  R6GameServiceAddresses::UR6GSServers_IsMSClientIsInRequest,
  R6GameServiceAddresses::UR6GSServers_GetLoggedInUbiDotCom,
  R6GameServiceAddresses::UR6GSServers_IsServerJoined,
  R6GameServiceAddresses::UR6ServerList_SetOwnSvrPort,
  R6GameServiceAddresses::UR6ServerList_GetLobbyID,
  R6GameServiceAddresses::UR6ServerList_GetGroupID,
};
