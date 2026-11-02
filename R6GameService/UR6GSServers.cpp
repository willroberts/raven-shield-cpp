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
// R6GameService.dll data @ 1007b22c : native storage identity retained.
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
// R6GameService.dll data @ 1007b2a0 : native storage identity retained.
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
// R6GameService.dll @ 10003ee0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::~UR6GSServers(UR6GSServers *object)
{
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
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6GSServersDispatchTable
    mov    DWORD PTR [esp+0x10],0xa
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot
    lea    ecx,[esi+0x20c]
    mov    BYTE PTR [esp+0x10],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x200]
    mov    BYTE PTR [esp+0x10],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1f4]
    mov    BYTE PTR [esp+0x10],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1e8]
    mov    BYTE PTR [esp+0x10],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1dc]
    mov    BYTE PTR [esp+0x10],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1d0]
    mov    BYTE PTR [esp+0x10],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1c4]
    mov    BYTE PTR [esp+0x10],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1b8]
    mov    BYTE PTR [esp+0x10],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1ac]
    mov    BYTE PTR [esp+0x10],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x1a0]
    mov    BYTE PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
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
// R6GameService.dll @ 10004270 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteUR6GSServers(UR6GSServers *object,uint flags)
{
  __asm {
    // Cached low flag byte controls vector mask2/free mask1; stride218; scalar UObject delete remains caller-clean.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je    Branch4
    mov    eax,DWORD PTR [esi-0x4]
    push   edi
    push   R6GameServiceAddresses::UR6GSServers__UR6GSServers
    lea    edi,[esi-0x4]
    push   eax
    push   0x218
    push   esi
    call   R6GameServiceAddresses::_eh_vector_destructor_iterator_
    test   bl,0x1
    je    Branch3
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   edi
    call   DWORD PTR [edx+0x8]
  Branch3:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch4:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers__UR6GSServers
    test   bl,0x1
    je    Branch5
    push   0x218
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__3UObjectSlot
    add    esp,0x8
  Branch5:
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
// R6GameService.dll @ 10001d80 : complete native control/access order and raw ABI retained.
__declspec(naked) FString __thiscall UR6GSServers::eventTempGetPBConnectStatus
    (UR6GSServers *this,APlayerController *controller)
{
  // Native hidden FString * is the first stack word; its cleanup flag is set only after the copy succeeds.
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
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    edx,DWORD PTR ds:0x100923d0
    mov    eax,DWORD PTR [esp+0x30]
    mov    ebp,DWORD PTR [esi]
    push   0x0
    lea    ecx,[esp+0x10]
    push   ecx
    push   0x0
    push   edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [ebp+0x10]
    mov    esi,DWORD PTR [esp+0x2c]
    lea    eax,[esp+0x10]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x8],0x1
    mov    BYTE PTR [esp+0x24],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// Native const-reference string inputs retain pointer spelling for the existing explicit-receiver callers.
// R6GameService.dll @ 10001e20 : complete native control/access order and raw ABI retained.
__declspec(naked) ulong __thiscall UR6GSServers::eventIsGlobalIDBanned
    (UR6GSServers *this,AR6AbstractGameInfo *gameInfo,const FString *globalID)
{
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
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    ecx,DWORD PTR [esp+0x30]
    mov    eax,DWORD PTR [esp+0x2c]
    push   ecx
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x28],0x0
    mov    DWORD PTR [esp+0x1c],0x0
    mov    DWORD PTR [esp+0xc],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    eax,ds:0x10092e70
    mov    ebx,DWORD PTR [esi]
    push   0x0
    lea    edx,[esp+0xc]
    push   edx
    push   0x0
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [ebx+0x10]
    mov    esi,DWORD PTR [esp+0x18]
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x24],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll @ 10001ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::eventProcessServerMsg
    (UR6GSServers *this,APlayerController *controller,const FString *messageKey)
{
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
    lea    ecx,[esp+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    eax,DWORD PTR [esp+0x28]
    push   ecx
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x24],0x0
    mov    DWORD PTR [esp+0xc],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    eax,ds:0x100923f8
    mov    edi,DWORD PTR [esi]
    push   0x0
    lea    edx,[esp+0xc]
    push   edx
    push   0x0
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edi+0x10]
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x20],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [esp+0x18]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x1c
    ret    0x8
  }
}

// Dispatches GetConsoleStoreIP, copies the local string into hidden caller storage and releases the local.
// R6GameService.dll @ 10001f50 : complete native control/access order and raw ABI retained.
__declspec(naked) FString __thiscall UR6GSServers::eventGetConsoleStoreIP
    (UR6GSServers *this,APlayerController *controller)
{
  // Native hidden FString * is the first stack word; its cleanup flag is set only after the copy succeeds.
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
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    edx,DWORD PTR ds:0x10092e5c
    mov    eax,DWORD PTR [esp+0x30]
    mov    ebp,DWORD PTR [esi]
    push   0x0
    lea    ecx,[esp+0x10]
    push   ecx
    push   0x0
    push   edx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x34],0x1
    mov    DWORD PTR [esp+0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [ebp+0x10]
    mov    esi,DWORD PTR [esp+0x2c]
    lea    eax,[esp+0x10]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[esp+0x10]
    mov    DWORD PTR [esp+0x8],0x1
    mov    BYTE PTR [esp+0x24],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll @ 10001ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) FString __thiscall UR6GSServers::eventGetLocallyBoundIpAddr(UR6GSServers *this)
{
  // Native hidden FString * is the first stack word; its cleanup flag is set only after the copy succeeds.
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
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    ecx,DWORD PTR ds:0x10092408
    mov    ebp,DWORD PTR [esi]
    push   0x0
    lea    eax,[esp+0x10]
    push   eax
    push   0x0
    push   ecx
    mov    ecx,esi
    mov    DWORD PTR [esp+0x30],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    push   eax
    mov    ecx,esi
    call   DWORD PTR [ebp+0x10]
    mov    esi,DWORD PTR [esp+0x28]
    lea    edx,[esp+0xc]
    push   edx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[esp+0xc]
    mov    DWORD PTR [esp+0x8],0x1
    mov    BYTE PTR [esp+0x20],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::getGameShutDown
    test   eax,eax
    je    Branch10
    call   R6GameServiceAddresses::UeviLPatchService_FinalDestroy
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitRegServer
    mov    eax,ds:0x10091e64
    test   eax,eax
    je    Branch9
    call   R6GameServiceAddresses::CloseMSClientSingleton
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch8
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientUninitialize
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch8:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR ds:0x10091e64,0x0
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextLoggedOffFromUbiComMSClientService
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch9:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitCDKey
  Branch10:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_DestroySlot
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
// R6GameService.dll @ 10005980 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PingRequest(FString firstString,FString secondString)
{
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
    mov    DWORD PTR [ebp-0x4],0x0
    push   0x0
    lea    ecx,[ebp+0x14]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    sub    esp,0xc
    lea    eax,[ebp+0x8]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR ds:0x10091e50
    call   R6GameServiceAddresses::ServerPing_NewPingRequest
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp+0x14]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll @ 10005a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollPingManager(UR6GSServers *this,int enabled)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_PollPingManagerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch11
    add    ecx,0x5c
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR ds:0x10091e50
    call   R6GameServiceAddresses::ServerPing_PingManager
    mov    ecx,DWORD PTR ds:0x10091e50
    mov    ds:0x10091c20,eax
    call   R6GameServiceAddresses::ReadSecondWord
    mov    ds:0x10091d3c,eax
  Branch11:
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
// R6GameService.dll @ 10013330 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollRegServerCallbacks(UR6GSServers *this,int enabled)
{
  __asm {
    mov    eax,ds:0x10093b08
    push   esi
    xor    esi,esi
    cmp    eax,esi
    je     Branch22
    cmp    DWORD PTR [esp+0x8],esi
    je     Branch22
    call   R6GameServiceAddresses::ProcessRegistrationServiceCallbacks
    mov    eax,ds:0x10093b10
    sub    eax,0x26
    mov    edx,0x3
    mov    ecx,0x6
    je     Branch12
    dec    eax
    jne    Branch13
    mov    DWORD PTR ds:0x100939e8,edx
    jmp    Branch13
  Branch12:
    mov    DWORD PTR ds:0x100939e8,ecx
  Branch13:
    mov    eax,ds:0x10093b20
    sub    eax,0x26
    mov    DWORD PTR ds:0x10093b10,esi
    je     Branch14
    dec    eax
    jne    Branch15
    mov    DWORD PTR ds:0x10093af4,edx
    jmp    Branch15
  Branch14:
    mov    DWORD PTR ds:0x10093af4,ecx
  Branch15:
    mov    eax,ds:0x10093b00
    sub    eax,0x26
    mov    DWORD PTR ds:0x10093b20,esi
    je     Branch16
    dec    eax
    jne    Branch17
    mov    DWORD PTR ds:0x10093b14,edx
    jmp    Branch17
  Branch16:
    mov    DWORD PTR ds:0x10093b14,ecx
  Branch17:
    mov    eax,ds:R6GameServiceAddresses::GSecondaryLobbyLoginReplyType
    sub    eax,0x26
    mov    DWORD PTR ds:0x10093b00,esi
    je     Branch18
    dec    eax
    jne    Branch19
    mov    DWORD PTR ds:0x10093af0,edx
    jmp    Branch19
  Branch18:
    mov    DWORD PTR ds:0x10093af0,ecx
    mov    DWORD PTR ds:0x100939ec,0x1
  Branch19:
    mov    eax,ds:0x10093b30
    sub    eax,0x26
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecondaryLobbyLoginReplyType,esi
    je     Branch20
    dec    eax
    jne    Branch21
    mov    DWORD PTR ds:0x10093b30,esi
    mov    DWORD PTR ds:0x10093b2c,edx
    pop    esi
    ret    0x4
  Branch20:
    mov    DWORD PTR ds:0x10093b2c,ecx
  Branch21:
    mov    DWORD PTR ds:0x10093b30,esi
  Branch22:
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

// Compare the parsed address under each returned interface mask; records are 0x4c bytes, address+8 and mask+0x38.
// Only ioctl -1 fails; retain unchecked returned byte count, ordinal text roundtrips and no native socket close.
// Own the incoming three-word string, disarm before destruction and preserve the full 0/1 result across that call.
// R6GameService.dll @ 10006450 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::OnSameSubNet(FString address)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectSubnetEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x608
    push    ebx
    push    esi
    push    edi
    mov    DWORD PTR [ebp-0x10],esp
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x4],ebx
    lea    ecx,[ebp+0x8]
    mov    BYTE PTR [ebp-0x4],0x1
    mov    esi,0x1
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    push    0x11
    push    0x2
    push    0x2
    mov    DWORD PTR [ebp-0x14],eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_socketSlot
    push    ebx
    push    ebx
    lea    ecx,[ebp-0x20]
    push    ecx
    push    0x5f0
    lea    edx,[ebp-0x614]
    push    edx
    push    ebx
    push    ebx
    push    0x4004747f
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_WSAIoctlSlot
    cmp    eax,0xffffffff
    jne    Branch24
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    xor    eax,eax
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  Branch24:
    mov    ecx,DWORD PTR [ebp-0x20]
    mov    eax,0xaf286bcb
    mul    ecx
    sub    ecx,edx
    shr    ecx,1
    add    ecx,edx
    shr    ecx,0x6
    mov    DWORD PTR [ebp-0x1c],ecx
  Branch25:
    test    esi,esi
    je    Branch26
    cmp    ebx,DWORD PTR [ebp-0x1c]
    jae    Branch26
    mov    esi,ebx
    imul    esi,esi,0x4c
    mov    eax,DWORD PTR [ebp+esi*1-0x5dc]
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    mov    ecx,DWORD PTR [ebp+esi*1-0x60c]
    push    ecx
    mov    edi,eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_ntoaSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::WS2_32_inet_addrSlot
    mov    edx,DWORD PTR [ebp-0x14]
    and    eax,edi
    and    edi,edx
    xor    edx,edx
    cmp    eax,edi
    setne    dl
    inc    ebx
    mov    esi,edx
    jmp    Branch25
  Branch26:
    xor    eax,eax
    test    esi,esi
    sete    al
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    mov    esi,eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
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

// Clears client/request/login state, optionally logs, then shuts down the singleton and zero-extends AL.
// R6GameService.dll @ 10006650 : exported int(void); raw guard/store/logger/low-byte return order retained.
__declspec(naked) int __thiscall UR6GSServers::UnInitMSClient(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UnInitMSClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    xor    eax,eax
    mov    ds:0x10091e6c,eax
    mov    edx,DWORD PTR [ecx+0x194]
    push   ebx
    and    edx,0xffffff7f
    mov    DWORD PTR [ecx+0x194],edx
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,eax
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],eax
    mov    ds:R6GameServiceAddresses::GLoggedInUbiDotCom,eax
    mov    ds:R6GameServiceAddresses::GJoinInProgress,eax
    mov    ds:0x10091d30,eax
    mov    ds:0x10091d38,eax
    mov    ds:0x10091e68,eax
    mov    ds:0x10091e64,eax
    je     Branch27
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientUninitialize
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch27:
    call   R6GameServiceAddresses::CloseMSClientSingleton
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    movzx  eax,al
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
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
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch28
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch28:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitMSClient
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

// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// Normal tail70e2..70fe follows the separate native catch bodies; it remains part of this one canonical method.
// R6GameService.dll @ 10007050 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execIsRefreshServersInProgress(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectSmallVMBridgeEH3
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
    jne    Branch30
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch30:
    mov    eax,ds:0x10091d38
    test   eax,eax
    jne    Branch31
    mov    eax,ds:0x10091d30
    test   eax,eax
    jne    Branch31
    xor    eax,eax
    jmp    Branch32
  Branch31:
    mov    eax,0x1
  Branch32:
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

// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// R6GameService.dll @ 10007100 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execStopRefreshServers(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectSmallVMBridgeEH4
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    push   esi
    xor    esi,esi
    inc    edx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],esi
    jne    Branch33
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch33:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    DWORD PTR ds:0x10091d38,esi
    mov    DWORD PTR ds:0x10091d30,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
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
// R6GameService.dll @ 100071a0 : exported int(void); raw guard/store/logger/low-byte return order retained.
__declspec(naked) int __thiscall UR6GSServers::MSCLientLeaveServer(void)
{
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
    push   eax
    xor    edi,edi
    push   ecx
    mov    DWORD PTR [ebp-0x4],edi
    call   R6GameServiceAddresses::MatchMSClientStoredRequest
    movzx  esi,al
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,edi
    je     Branch34
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSClientLeaveGameServer
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch34:
    cmp    esi,edi
    jne    Branch35
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,edi
    je     Branch35
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextMSClientLeaveGameServerFAILED
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    mov    eax,esi
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch35:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoggedInUbiDotCom,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GJoinInProgress,edi
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
// R6GameService.dll @ 10007870 : nonvirtual void(void); native state table, x87 comparison and guard order retained.
// Global state/time and field+0x198 roles are inferred. Event output ID words are deliberately uninitialized.
__declspec(naked) void __thiscall UR6GSServers::ProcessJoinServerRequest(void)
{
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
    ja     Branch37
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::JoinRequestDispatch]
  Branch36:
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x100933bc
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoginRequested,0x2
  Branch37:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch38:
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x100933bc
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch37
    push   R6GameServiceAddresses::WideTextLOGINFAILDEFAULT
    lea    ecx,[ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x2c]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoginRequested,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch39:
    lea    edx,[ebp-0x18]
    push   edx
    lea    eax,[ebp-0x14]
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ServerList_eventGetLobbyAndGroupID
    mov    ecx,DWORD PTR [ebp-0x14]
    cmp    ecx,ebx
    je     Branch40
    mov    eax,DWORD PTR [ebp-0x18]
    cmp    eax,ebx
    je     Branch40
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_MSClientServerConnected
    push   R6GameServiceAddresses::WideTextJOINSERVERREQSUCCESS
    lea    ecx,[ebp-0x38]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x38]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x38]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch40:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoginRequested,ebx
    mov    DWORD PTR fs:0x0,ecx
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
// R6GameService.dll data @ 1007c270 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessJoinServerRequestTryMap[1] = {
  {0x0, 0x2, 0x3, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo10},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c250 : native storage identity retained.
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
// R6GameService.dll @ 10007ad0 : virtual void(float*), RET4; exact guard, x87 precision and access order.
// Offset+0x2c flags and timestamp role are inferred; native bias constants are 2^24 seconds and 5.0f.
__declspec(naked) void __thiscall UR6GSServers::ProcessIsRouterDisconnect(float *timestampOut)
{
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
    je     Branch43
    rdtsc
    mov    DWORD PTR [ebp-0x18],eax
    mov    DWORD PTR [ebp-0x14],edx
    fild   DWORD PTR [ebp-0x14]
    mov    eax,DWORD PTR [ebp-0x14]
    test   eax,eax
    jge    Branch41
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch41:
    mov    ecx,DWORD PTR [ebp-0x18]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   ecx,ecx
    fild   DWORD PTR [ebp-0x18]
    jge    Branch42
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch42:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,esi
    fmul   QWORD PTR [edx]
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat5_0
    fstp   DWORD PTR [eax]
    call   R6GameServiceAddresses::UR6GSServers_UnInitMSClient
    and    DWORD PTR [esi+0x2c],0xffffffdf
  Branch43:
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
// R6GameService.dll data @ 1007c338 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessIsRouterDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo14},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c328 : native storage identity retained.
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

// Consume the optional debug-info byte, then handle a current MS-client router-disconnect flag.
// No-input VM bridge/RET8; matching package declares Bool return, but native never accesses resultOut.
// Code increments and candidate byte reads before state0; optional42 dispatch uses current frame object/table.
// Flag+2c mask20 selects current all-refresh notification, actual UnInitMSClient, then late current flag clear.
// Notification precedes child global clears; failures retain prior effects and skip the late flag clear.
// R6GameService.dll @ 10007ba0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeIsRouterDisconnect(FFrame &frame,void *const resultOut)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeIsRouterDisconnectSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch44
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch44:
    test   BYTE PTR [esi+0x2c],0x20
    je     Branch46
    mov    eax,ds:0x10091d38
    test   eax,eax
    je     Branch45
    mov    DWORD PTR ds:0x10091bf8,0x1
  Branch45:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitMSClient
    and    DWORD PTR [esi+0x2c],0xffffffdf
  Branch46:
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
// R6GameService.dll @ 10007c60 : virtual void(float*), RET4; exact guard, x87 precision and access order.
// Offset+0x2c flags and timestamp role are inferred; native bias constants are 2^24 seconds and 5.0f.
__declspec(naked) void __thiscall UR6GSServers::ProcessIsLobbyDisconnect(float *timestampOut)
{
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
    je     Branch50
    mov    eax,ds:R6GameServiceAddresses::GLoggedInUbiDotCom
    test   eax,eax
    je     Branch47
    mov    eax,DWORD PTR [esi]
    call   DWORD PTR [eax+0xd8]
  Branch47:
    and    DWORD PTR [esi+0x2c],0xffffffef
    rdtsc
    mov    DWORD PTR [ebp-0x1c],eax
    mov    DWORD PTR [ebp-0x18],edx
    fild   DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x18]
    test   eax,eax
    jge    Branch48
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch48:
    mov    ecx,DWORD PTR [ebp-0x1c]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   ecx,ecx
    fild   DWORD PTR [ebp-0x1c]
    jge    Branch49
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch49:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    mov    eax,DWORD PTR [ebp+0x8]
    fmul   QWORD PTR [edx]
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat5_0
    fstp   DWORD PTR [eax]
  Branch50:
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
// R6GameService.dll data @ 1007c3f8 : native storage identity retained.
const R6GameServiceNative::TryBlock ProcessIsLobbyDisconnectTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo18},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c3e8 : native storage identity retained.
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
// R6GameService.dll data @ 1007c6a0 : native storage identity retained.
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
// R6GameService.dll @ 10009400 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::LogGSVersion(UR6GSServers *this)
{
  // Sticky flag publishes before list construction; repeated conversion sizes and current logger/allocator are live.
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
    jne    Branch53
    mov    ebx,0x1
    lea    ecx,[ebp-0x28]
    mov    DWORD PTR ds:0x1008c26c,ebx
    call   R6GameServiceAddresses::InitializeGSModuleVersions
    lea    eax,[ebp-0x14]
    push   eax
    push   edi
    lea    ecx,[ebp-0x28]
    mov    BYTE PTR [ebp-0x4],bl
    mov    DWORD PTR [ebp-0x14],edi
    call   R6GameServiceAddresses::FormatModuleVersionList
    mov    eax,DWORD PTR [ebp-0x14]
    cmp    eax,edi
    jne    Branch54
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextCouldNotFindTheUBIComGSVersionInfo
    push   edx
  Branch51:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch52:
    lea    ecx,[ebp-0x28]
    mov    BYTE PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::ClearModuleVersionList
  Branch53:
    lea    esp,[ebp-0x34]
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch54:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   eax
    call   DWORD PTR [edx]
    mov    esi,eax
    cmp    esi,edi
    jne    Branch55
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCouldNotAllocateMemoryToRetrieveUBIComGSVersionInfo
    push   ecx
    jmp    Branch51
  Branch55:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextUBIComGSVersionInfo
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    lea    ecx,[ebp-0x14]
    push   ecx
    push   esi
    lea    ecx,[ebp-0x28]
    call   R6GameServiceAddresses::FormatModuleVersionList
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
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextTextFormat
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    add    esp,0xc
    push   esi
    call   DWORD PTR [eax+0x8]
    jmp    Branch52
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

// Finds a matching selected ID/key pair in live48-byte records, then destroys both incoming owned strings.
// R6GameService.dll @ 10009640 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::PlayerIsInIDList(FString candidate,FString recordKey,int selector)
{
  // Two owned FString values use their incoming words; RET 0x1c includes the selector word.
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PlayerIsInIDListSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    eax,DWORD PTR [ebp+0x20]
    xor    esi,esi
    xor    edi,edi
    test   eax,eax
    mov    BYTE PTR [ebp-0x4],0x2
    je     Branch59
    jmp    Branch57
    lea    esp,[esp+0x0]
  Branch57:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch61
    test   esi,esi
    jne    Branch61
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    shl    esi,0x4
    lea    ecx,[esi+eax*1+0x18]
    push   ecx
    lea    ecx,[ebp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch58
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    esi,edx
    push   esi
    lea    ecx,[ebp+0x14]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch58
    mov    esi,0x1
    inc    edi
    jmp    Branch57
  Branch58:
    xor    esi,esi
    inc    edi
    jmp    Branch57
  Branch59:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch61
    test   esi,esi
    jne    Branch61
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    shl    esi,0x4
    lea    ecx,[esi+eax*1+0xc]
    push   ecx
    lea    ecx,[ebp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch60
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    esi,edx
    push   esi
    lea    ecx,[ebp+0x14]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch60
    mov    esi,0x1
    inc    edi
    jmp    Branch59
  Branch60:
    xor    esi,esi
    inc    edi
    jmp    Branch59
  Branch61:
    lea    ecx,[ebp+0x8]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp+0x14]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x1c
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

// Copies the first matching record+0x24 string into hidden output, or an empty string, then releases owned input.
// R6GameService.dll @ 10009790 : complete native control/access order and raw ABI retained.
__declspec(naked) FString * __thiscall UR6GSServers::GetGlobalIdFromPlayerIDList(UR6GSServers *this,FString *result,
    uint lookupData,uint lookupCount,uint lookupCapacity)
{
  // Native hidden output plus one owned three-word FString; RET 0x10; EAX returns the cached output pointer.
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::GetGlobalIdFromPlayerIDListSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    push   edi
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],ebx
    mov    DWORD PTR [ebp-0x4],0x1
    mov    BYTE PTR [ebp-0x4],0x2
    xor    edi,edi
  Branch62:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch64
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    lea    eax,[ebp+0xc]
    shl    esi,0x4
    push   eax
    lea    ecx,[esi+ecx*1+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    cmp    eax,ebx
    je     Branch63
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    lea    eax,[esi+edx*1+0x24]
    mov    esi,DWORD PTR [ebp+0x8]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    jmp    Branch65
  Branch63:
    inc    edi
    jmp    Branch62
  Branch64:
    mov    esi,DWORD PTR [ebp+0x8]
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
  Branch65:
    mov    eax,DWORD PTR [ebp-0x14]
    or     eax,0x1
    lea    ecx,[ebp+0xc]
    mov    DWORD PTR [ebp-0x14],eax
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x10
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
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [ebp-0x10],esp
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::UR6GSServers_PollMSClientCallbacks
    mov    ebx,DWORD PTR [ebp+0x10]
    push   ebx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_PollRegServerCallbacks
    mov    eax,DWORD PTR [ebp+0xc]
    push   ebx
    push   edi
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacks
    mov    ecx,DWORD PTR [ebp+0x14]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_PollGSClientCallbacks
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_PollPingManager
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
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::UR6ServerList_InitFavorites
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    test   eax,eax
    jne    Branch67
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_Init
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    test   eax,eax
    je     Branch68
  Branch67:
    mov    DWORD PTR ds:0x10091c14,0x1
    jmp    Branch69
  Branch68:
    push   R6GameServiceAddresses::WideTextLOGINFAILDEFAULT
    lea    ecx,[ebp-0x28]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x28]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x28]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch69:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
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
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch70
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch70:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_InitializeMSClient
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

// Read mapped index before idle gates; publish clock/refresh state, store mapped index44, request CURRENT record at captured inputIndex*dc.
// Preserve unchecked array reads, pre-state0 gap, late record array/logging and partial published effects.
// R6GameService.dll @ 10009dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RefreshOneServer(UR6GSServers *this,int serverIndex)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo6
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    push   edi
    mov    edi,ecx
    mov    eax,DWORD PTR [edi+0x80]
    mov    ebx,DWORD PTR [eax+esi*4]
    mov    eax,ds:0x10091e6c
    test   eax,eax
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je    Branch71
    mov    eax,ds:0x10091d38
    test   eax,eax
    jne    Branch71
    mov    eax,ds:0x10091d30
    test   eax,eax
    jne    Branch71
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    imul   esi,esi,0xdc
    fstp   DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
    mov    DWORD PTR ds:0x10091bf8,0x0
    mov    DWORD PTR ds:0x10091d30,0x1
    mov    ecx,DWORD PTR [edi+0x5c]
    lea    eax,[esi+ecx*1]
    mov    DWORD PTR [edi+0x44],ebx
    mov    edx,DWORD PTR [eax]
    mov    eax,DWORD PTR [eax+0x4]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ForwardMSClientOperation2
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch71
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextMSClientRefreshGameServers
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch71:
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

// Decode an index into initialized DWORD scratch, advance current Code/end/optional DebugInfo42, then refresh captured owner.
// Preserve current VM table/object, partial decoder writes, late index and untouched script result, RET8.
// R6GameService.dll @ 10009ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execRefreshOneServer(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectParentExceptionInfo7
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [esi+0xc]
    mov    DWORD PTR [ebp-0x14],0x0
    movzx  edx,BYTE PTR [eax]
    inc    eax
    push   edi
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [ebp-0x10],esp
    lea    eax,[ebp-0x14]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    mov    edi,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   esi
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR [eax+edx*4]
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne    Branch72
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   0x0
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch72:
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_RefreshOneServer
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
// R6GameService.dll @ 1000a8c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessLoginMasterSrv(UR6GSServers *this,int loginResultCode,float *retryAtSeconds)
{
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
    je    Branch91
    sub    eax,0x2
    je    Branch90
    dec    eax
    jne    Branch89
    mov    DWORD PTR ds:0x10091c0c,edi
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat5_0
    mov    eax,DWORD PTR [ebp+0xc]
    fstp   DWORD PTR [eax]
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    cmp    eax,edi
    je    Branch89
    push   R6GameServiceAddresses::WideTextFailedToLogInToUbiCom
  Branch88:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch89:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  Branch90:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR ds:0x10091c0c,edi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  Branch91:
    cmp    DWORD PTR [ebp+0x8],edi
    je    Branch89
    cmp    DWORD PTR ds:0x10091e64,edi
    jne    Branch89
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    mov    eax,DWORD PTR [ebp+0xc]
    fcomp  DWORD PTR [eax]
    fnstsw ax
    test   ah,0x41
    jne    Branch89
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_InitializeMSClient
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,edi
    je    Branch89
    push   R6GameServiceAddresses::WideTextRetry
    jmp    Branch88
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
// R6GameService.dll data @ 1007cb88 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessLoginMasterSrvTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6GSServersGParentExceptionInfo30},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007cb78 : native storage identity retained.
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

// Process optional internet work, initialize the CD-key service if uncached, and poll eligible controllers.
// Exported virtual void(game*,level*), saved ECX/RET8. Game+4e4 bit10 is sampled before state0.
// Cache933c4 stores full virtual+68 result; zero retries next call. Class nodes+24/+2c are traversed
// against the imported PlayerController class, whose pointer reloads only after eligible callbacks.
// Each eligible controller gets ordinary work and optional Mod work when full IsRavenShield result is0.
// Game argument and nextController+3dc stay current; level pointer is cached, its list+4d4 reloads for auth.
// After auth, fresh service vtable+98 receives(0,1,1,0). No own resource cleanup or rollback.
// R6GameService.dll @ 1000a9c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::MasterServerManager(AR6AbstractGameInfo *gameInfo,ALevelInfo *levelInfo)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_MasterServerManagerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    push   ebx
    mov    ebx,DWORD PTR [ebp+0xc]
    push   esi
    push   edi
    mov    edi,ecx
    test   BYTE PTR [eax+0x4e4],0x10
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch92
    push   ebx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_ProcessInternetSrv
  Branch92:
    mov    eax,ds:0x100933c4
    test   eax,eax
    jne    Branch93
    mov    eax,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [eax+0x68]
    mov    ds:0x100933c4,eax
  Branch93:
    mov    esi,DWORD PTR [ebx+0x4d4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch94:
    test   esi,esi
    je     Branch100
    mov    eax,DWORD PTR [esi+0x24]
    lea    ebx,[ebx+0x0]
  Branch95:
    test   eax,eax
    je     Branch96
    cmp    eax,ecx
    je     Branch97
    mov    eax,DWORD PTR [eax+0x2c]
    jmp    Branch95
  Branch96:
    xor    eax,eax
    test   ecx,ecx
    sete   al
    test   eax,eax
    je     Branch99
  Branch97:
    test   esi,esi
    je     Branch99
    mov    ecx,DWORD PTR [ebp+0x8]
    push   0x0
    push   esi
    push   ebx
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequest
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [edx]
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    test   eax,eax
    jne    Branch98
    mov    eax,DWORD PTR [ebp+0x8]
    push   0x1
    push   esi
    push   ebx
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequest
  Branch98:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch99:
    mov    esi,DWORD PTR [esi+0x3dc]
    jmp    Branch94
  Branch100:
    mov    ecx,DWORD PTR [ebx+0x4d4]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_ProcessAuthIdRequest
    mov    edx,DWORD PTR [edi]
    push   0x0
    push   0x1
    push   0x1
    push   0x0
    mov    ecx,edi
    call   DWORD PTR [edx+0x98]
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

// Add or reuse a keyed player-ID record after an owned-string presence check.
// Nonvirtual void(FString,FString,FString,int)/RET40; formal names describe candidate/key/global ID.
// Initial state0 protects only third input, state3 before first copy protects all three; second-copy state4
// protects the completed key copy. State3 before PlayerIsInIDList transfers both outgoing strings.
// Full selected ID/key match skips changes; nonzero early selector permits current global-ID/key reuse.
// Otherwise AddZeroed creates48 bytes with no string constructors. Current array pointer reloads between
// comparisons/assignments; current final selector chooses+c/+18. No rollback of appended/assigned fields.
// Input destructor order candidate/key/global ID lowers states before each call; no failed-dtor retry.
// R6GameService.dll @ 1000ab00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::AddPlayerToIDList(FString candidate,FString recordKey,
  FString globalId,int idSlotSelector)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_AddPlayerToIDListSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x14
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    edi,ecx
    xor    esi,esi
    mov    DWORD PTR [ebp-0x4],esi
    mov    ebx,DWORD PTR [ebp+0x2c]
    push   ebx
    sub    esp,0xc
    lea    eax,[ebp+0x14]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   eax
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    lea    edx,[ebp+0x8]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   edx
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,edi
    mov    BYTE PTR [ebp-0x4],0x3
    call   R6GameServiceAddresses::UR6GSServers_PlayerIsInIDList
    test   eax,eax
    je     Branch101
    mov    BYTE PTR [ebp-0x4],0x1
    jmp    Branch108
  Branch101:
    test   ebx,ebx
    je     Branch105
    mov    ebx,DWORD PTR [ebp+0x2c]
    xor    edi,edi
    lea    esp,[esp+0x0]
  Branch102:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch104
    test   esi,esi
    jne    Branch106
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    shl    esi,0x4
    lea    ecx,[esi+eax*1+0x24]
    push   ecx
    lea    ecx,[ebp+0x20]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch103
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    esi,edx
    push   esi
    lea    ecx,[ebp+0x14]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch103
    mov    ebx,edi
    mov    esi,0x1
    inc    edi
    jmp    Branch102
  Branch103:
    xor    esi,esi
    inc    edi
    jmp    Branch102
  Branch104:
    test   esi,esi
    jne    Branch106
  Branch105:
    push   0x1
    push   0x30
    mov    ecx,R6GameServiceAddresses::GServiceArray5
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    mov    ebx,eax
    lea    esi,[ebx+ebx*2]
    lea    eax,[ebp+0x14]
    shl    esi,0x4
    push   eax
    add    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    lea    edx,[ebp+0x20]
    push   edx
    lea    ecx,[esi+eax*1+0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
  Branch106:
    mov    eax,DWORD PTR [ebp+0x2c]
    lea    edx,[ebx+ebx*2]
    shl    edx,0x4
    lea    ecx,[ebp+0x8]
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    push   ecx
    lea    ecx,[edx+eax*1+0x18]
    jne    Branch107
    lea    ecx,[edx+eax*1+0xc]
  Branch107:
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    mov    DWORD PTR [ebp-0x4],0x1
  Branch108:
    lea    ecx,[ebp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp+0x14]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp+0x20]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x28
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
    push   ebx
    push   esi
    push   edi
    xor    eax,eax
    mov    edi,ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3+0x4
    test   ecx,ecx
    setg   al
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x1c],0x100
    mov    DWORD PTR [ebp-0x2c],ecx
    test   eax,eax
    mov    DWORD PTR [ebp-0x34],eax
    je     Branch111
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
  Branch111:
    xor    eax,eax
    mov    DWORD PTR [ebp-0x24],eax
  Branch112:
    cmp    eax,0x2
    jge    Branch141
    cmp    eax,ecx
    jge    Branch141
    mov    eax,ds:0x10091d30
    mov    esi,DWORD PTR [edi+0x60]
    xor    ecx,ecx
    test   eax,eax
    mov    DWORD PTR [ebp-0x20],ecx
    mov    DWORD PTR [ebp-0x28],esi
    je     Branch117
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    xor    eax,eax
  Branch113:
    cmp    eax,DWORD PTR [edi+0x60]
    jge    Branch116
    test   ecx,ecx
    jne    Branch118
    mov    ebx,DWORD PTR [edi+0x5c]
    mov    ecx,eax
    imul   ecx,ecx,0xdc
    add    ecx,ebx
    mov    ebx,DWORD PTR [ecx+0x4]
    cmp    ebx,DWORD PTR [edx+0x10c]
    jne    Branch114
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,DWORD PTR [edx+0x108]
    jne    Branch114
    mov    ebx,DWORD PTR ds:0x10091d30
    test   ebx,ebx
    mov    ecx,0x1
    mov    esi,eax
    mov    DWORD PTR [ebp-0x20],ecx
    mov    DWORD PTR [ebp-0x28],esi
    je     Branch115
    cmp    eax,DWORD PTR [edi+0x44]
    jne    Branch115
    mov    DWORD PTR ds:0x10091d30,0x0
    inc    eax
    jmp    Branch113
  Branch114:
    mov    ecx,DWORD PTR [ebp-0x20]
  Branch115:
    inc    eax
    jmp    Branch113
  Branch116:
    test   ecx,ecx
    jne    Branch118
  Branch117:
    push   0x1
    lea    esi,[edi+0x80]
    push   0x4
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    edx,DWORD PTR [esi]
    push   0x1
    push   0xdc
    lea    ecx,[edi+0x5c]
    mov    DWORD PTR [edx+eax*4],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    esi,eax
    mov    DWORD PTR [ebp-0x28],esi
  Branch118:
    mov    ecx,DWORD PTR [edx+0x108]
    imul   esi,esi,0xdc
    mov    eax,DWORD PTR [edi+0x5c]
    mov    DWORD PTR [esi+eax*1],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    edx,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [eax+0x10c]
    mov    DWORD PTR [esi+edx*1+0x4],ecx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ebx,DWORD PTR [edi+0x5c]
    add    edx,0x634
    push   edx
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ebx,DWORD PTR [edi+0x5c]
    add    eax,0x734
    push   eax
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    ecx,DWORD PTR [edi+0x5c]
    mov    edx,DWORD PTR [esi+ecx*1+0x28]
    lea    eax,[esi+ecx*1+0x28]
    and    edx,0xfffffffe
    mov    DWORD PTR [eax],edx
    mov    edx,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [esi+edx*1+0x28]
    lea    eax,[esi+edx*1+0x28]
    or     ecx,0x2
    mov    DWORD PTR [eax],ecx
    mov    eax,DWORD PTR [edi+0x5c]
    mov    DWORD PTR [esi+eax*1+0xc],0x3e8
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ebx,DWORD PTR [edi+0x5c]
    add    ecx,0x8
    push   ecx
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x5c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ebx,DWORD PTR [edi+0x5c]
    add    edx,0x41c
    push   edx
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0xac]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    ecx,DWORD PTR [edi+0x5c]
    lea    eax,[edi+0x168]
    push   eax
    lea    ecx,[esi+ecx*1+0xac]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    mov    edx,DWORD PTR [edi+0x5c]
    lea    ecx,[esi+edx*1+0x28]
    mov    edx,DWORD PTR [ecx]
    shl    eax,0x3
    xor    eax,edx
    and    eax,0x8
    xor    edx,eax
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [edi+0x5c]
    mov    eax,DWORD PTR [edx+0x628]
    push   0x4
    mov    DWORD PTR [esi+ecx*1+0x78],eax
    push   0x1
    mov    ecx,R6GameServiceAddresses::GServiceArray4
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray4
    mov    edx,DWORD PTR [ebp-0x28]
    mov    DWORD PTR [ecx+eax*4],edx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3
    mov    ecx,DWORD PTR [eax+0x620]
    test   ecx,ecx
    jle    Branch133
    mov    eax,DWORD PTR [eax+0x61c]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   eax
    call   R6GameServiceAddresses::LoadSerializedByteStore
    lea    ecx,[ebp-0x1c]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x144]
    push   edx
    push   0xfd
    mov    DWORD PTR [ebp-0x1c],0x100
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    jl     Branch119
    mov    ebx,DWORD PTR [edi+0x5c]
    lea    eax,[ebp-0x144]
    push   eax
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x68]
    jmp    Branch120
  Branch119:
    mov    ecx,DWORD PTR [edi+0x5c]
    push   R6GameServiceAddresses::GEmptyWideText
    lea    ecx,[esi+ecx*1+0x68]
  Branch120:
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x1c]
    push   edx
    lea    eax,[ebp-0x144]
    push   eax
    push   0x64
    mov    DWORD PTR [ebp-0x1c],0x100
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    jl     Branch121
    mov    ebx,DWORD PTR [edi+0x5c]
    lea    ecx,[ebp-0x144]
    push   ecx
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x94]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
  Branch121:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x18]
    push   edx
    push   0x6d
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch122
    mov    eax,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [esi+eax*1+0x74],ecx
  Branch122:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x11]
    push   edx
    push   0x66
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch123
    mov    eax,DWORD PTR [edi+0x5c]
    mov    edx,DWORD PTR [esi+eax*1+0x38]
    xor    ecx,ecx
    mov    cl,BYTE PTR [ebp-0x11]
    lea    eax,[esi+eax*1+0x38]
    xor    ecx,edx
    and    ecx,0x1
    xor    edx,ecx
    mov    DWORD PTR [eax],edx
  Branch123:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x11]
    push   edx
    push   0x67
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch124
    mov    eax,DWORD PTR [edi+0x5c]
    movzx  ecx,BYTE PTR [ebp-0x11]
    mov    edx,DWORD PTR [esi+eax*1+0x38]
    lea    eax,[esi+eax*1+0x38]
    shl    ecx,1
    xor    ecx,edx
    and    ecx,0x2
    xor    edx,ecx
    mov    DWORD PTR [eax],edx
  Branch124:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x18]
    push   edx
    push   0x69
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch125
    mov    eax,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [esi+eax*1+0x3c],ecx
  Branch125:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x11]
    push   edx
    push   0x6a
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch126
    mov    eax,DWORD PTR [edi+0x5c]
    movzx  ecx,BYTE PTR [ebp-0x11]
    mov    edx,DWORD PTR [esi+eax*1+0x4c]
    lea    eax,[esi+eax*1+0x4c]
    shl    ecx,0x2
    xor    ecx,edx
    and    ecx,0x4
    xor    edx,ecx
    mov    DWORD PTR [eax],edx
  Branch126:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x1c]
    push   edx
    lea    eax,[ebp-0x144]
    push   eax
    push   0x65
    mov    DWORD PTR [ebp-0x1c],0x100
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    jl     Branch127
    mov    ebx,DWORD PTR [edi+0x5c]
    lea    ecx,[ebp-0x144]
    push   ecx
    add    ebx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x88]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
  Branch127:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x1c]
    push   edx
    lea    eax,[ebp-0x18]
    push   eax
    push   0x68
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    jl     Branch128
    mov    ecx,DWORD PTR [edi+0x5c]
    lea    eax,[esi+ecx*1+0x4c]
    mov    ecx,DWORD PTR [ebp-0x18]
    xor    edx,edx
    test   ecx,ecx
    mov    ecx,DWORD PTR [eax]
    sete   dl
    shl    edx,0x6
    xor    edx,ecx
    and    edx,0x40
    xor    ecx,edx
    mov    DWORD PTR [eax],ecx
  Branch128:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x18]
    push   eax
    push   0x6b
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch129
    mov    ecx,DWORD PTR [edi+0x5c]
    mov    edx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [esi+ecx*1+0x58],edx
  Branch129:
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    lea    ecx,[ebp-0x344]
    push   R6GameServiceAddresses::WideTextI
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appSprintfSlot
    add    esp,0xc
    test   eax,eax
    jl     Branch130
    mov    eax,DWORD PTR [edi+0x5c]
    lea    edx,[ebp-0x344]
    push   edx
    lea    ecx,[esi+eax*1+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot2
    mov    edx,DWORD PTR [edi+0x5c]
    lea    ecx,[ebp-0x344]
    push   ecx
    lea    ecx,[esi+edx*1+0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot2
  Branch130:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x18]
    push   eax
    push   0x6c
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch131
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    eax,ds:R6GameServiceAddresses::Engine__GModMgrSlot
    push   ecx
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x44]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeNameSlot
    mov    ecx,DWORD PTR [edi+0x5c]
    push   eax
    lea    ecx,[esi+ecx*1+0x7c]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0x44]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch131:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x18]
    push   edx
    push   0xfc
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch132
    mov    eax,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [esi+eax*1+0x8],ecx
  Branch132:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x11]
    push   edx
    push   0xff
    call   R6GameServiceAddresses::ReadStoredWord
    test   eax,eax
    jl     Branch133
    mov    eax,DWORD PTR [edi+0x5c]
    movzx  ecx,BYTE PTR [ebp-0x11]
    mov    edx,DWORD PTR [esi+eax*1+0x4c]
    lea    eax,[esi+eax*1+0x4c]
    shl    ecx,0xa
    xor    ecx,edx
    and    ecx,0x400
    xor    edx,ecx
    mov    DWORD PTR [eax],edx
  Branch133:
    mov    edx,DWORD PTR [edi+0x5c]
    mov    ecx,DWORD PTR [esi+edx*1+0x28]
    lea    eax,[esi+edx*1+0x28]
    and    ecx,0xfffffffb
    mov    DWORD PTR [eax],ecx
    xor    ebx,ebx
    jmp    Branch134
    lea    ecx,[ecx+0x0]
  Branch134:
    cmp    ebx,DWORD PTR [edi+0x54]
    jge    Branch136
    mov    ecx,DWORD PTR [edi+0x50]
    lea    eax,[ebx+ebx*2]
    lea    edx,[ecx+eax*4]
    mov    eax,DWORD PTR [edi+0x5c]
    push   edx
    lea    ecx,[esi+eax*1+0x10]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch135
    mov    ecx,DWORD PTR [edi+0x5c]
    lea    eax,[esi+ecx*1+0x28]
    or     DWORD PTR [eax],0x4
  Branch135:
    inc    ebx
    jmp    Branch134
  Branch136:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray3
    mov    edx,DWORD PTR [edx+0x61c]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x8]
    mov    eax,ds:R6GameServiceAddresses::GServiceArray3+0x4
    test   eax,eax
    jge    Branch137
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch137:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray3+0x4,0x1
    jge    Branch138
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch138:
    xor    eax,eax
    jmp    Branch139
    lea    ecx,[ecx+0x0]
  Branch139:
    cmp    eax,0x1
    jge    Branch140
    inc    eax
    jmp    Branch139
  Branch140:
    push   0x838
    push   0x1
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceArray3
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    eax,DWORD PTR [ebp-0x24]
    mov    ecx,DWORD PTR [ebp-0x2c]
    inc    eax
    mov    DWORD PTR [ebp-0x24],eax
    jmp    Branch112
  Branch141:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp-0x34]
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
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    push   ebx
    push   esi
    push   edi
    xor    edi,edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],ecx
    mov    DWORD PTR [ebp-0x4],edi
    mov    DWORD PTR [ebp-0x18],edi
  Branch142:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1+0x4
    cmp    DWORD PTR [ebp-0x18],ecx
    jge    Branch148
    test   edi,edi
    jne    Branch149
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    imul   eax,eax,0x108
    mov    ecx,R6GameServiceAddresses::GServiceString2
    lea    esi,[eax+edx*1]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   edi
    mov    ecx,DWORD PTR [ebp-0x14]
    add    esp,0x4
    add    ecx,0x1dc
    mov    ebx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    mov    ecx,DWORD PTR [ebp-0x14]
    add    esp,0x4
    add    ecx,0x34
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   ebx
    push   edi
    push   eax
    xor    eax,eax
    mov    ax,WORD PTR [esi+0x100]
    push   eax
    push   esi
    call   R6GameServiceAddresses::CreateMSClientSingleton
    movzx  edi,al
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch143
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSRouterIndex
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ecx
    push   R6GameServiceAddresses::WideTextMSClientInitializeGIRouterIndexI
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSRouterIndex
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    imul   ecx,ecx,0x108
    add    ecx,ebx
    add    esp,0xc
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    add    esp,0x4
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSClientInitializeSzNameS
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSRouterIndex
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    imul   ecx,ecx,0x108
    mov    eax,DWORD PTR [ecx+edx*1+0x100]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    add    esp,0xc
    push   eax
    push   R6GameServiceAddresses::WideTextMSClientInitializeIPortI
    push   edx
    call   esi
    mov    ecx,DWORD PTR [ebp-0x14]
    add    esp,0xc
    add    ecx,0x34
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientInitializeMSzUserIDS
    push   ecx
    call   esi
    mov    ecx,DWORD PTR [ebp-0x14]
    add    esp,0xc
    add    ecx,0x1dc
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSClientInitializeMSzPasswordS
    push   eax
    call   esi
    add    esp,0xc
  Branch143:
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1+0x4
    inc    eax
    cmp    eax,ecx
    mov    ds:R6GameServiceAddresses::GMSRouterIndex,eax
    jl     Branch144
    xor    eax,eax
    mov    ds:R6GameServiceAddresses::GMSRouterIndex,eax
  Branch144:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    test   ecx,ecx
    jne    Branch147
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x24
    call   DWORD PTR [edx]
    mov    ecx,eax
    mov    DWORD PTR [ebp-0x20],ecx
    test   ecx,ecx
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch145
    call   R6GameServiceAddresses::InitializeSerializedByteStore
    jmp    Branch146
  Branch145:
    xor    eax,eax
  Branch146:
    mov    ds:R6GameServiceAddresses::GServerReplySerializedStore,eax
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    mov    BYTE PTR [ebp-0x4],0x0
  Branch147:
    inc    DWORD PTR [ebp-0x18]
    jmp    Branch142
  Branch148:
    test   edi,edi
    je     Branch152
  Branch149:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    DWORD PTR ds:0x10091e64,0x1
    je     Branch151
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientInitialized
    push   ecx
  Branch150:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch151:
    call   R6GameServiceAddresses::RegisterMSClientCallbacks
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch152:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    DWORD PTR ds:0x10091c14,0x3
    mov    DWORD PTR ds:0x10091e68,0x0
    je     Branch151
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSClientCouldNotConnectToServer
    push   eax
    jmp    Branch150
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
    push   ebx
    push   esi
    xor    eax,eax
    mov    esi,ecx
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray2+0x4,eax
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],eax
    mov    DWORD PTR [ebp-0x20],0x100
    mov    DWORD PTR [ebp-0x30],eax
    jle    Branch170
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
    xor    edx,edx
    lea    esp,[esp+0x0]
  Branch153:
    cmp    eax,DWORD PTR [esi+0x60]
    jge    Branch155
    test   edx,edx
    jne    Branch156
    mov    ebx,DWORD PTR [esi+0x5c]
    mov    ecx,eax
    imul   ecx,ecx,0xdc
    add    ecx,ebx
    mov    ebx,DWORD PTR [ecx+0x4]
    cmp    ebx,DWORD PTR [edi+0x4]
    jne    Branch154
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,DWORD PTR [edi]
    jne    Branch154
    mov    edx,0x1
    mov    DWORD PTR [ebp-0x28],eax
  Branch154:
    inc    eax
    jmp    Branch153
  Branch155:
    test   edx,edx
    je     Branch165
  Branch156:
    mov    eax,DWORD PTR [edi+0xc]
    test   eax,eax
    jle    Branch165
    mov    edx,DWORD PTR [edi+0x8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   edx
    mov    DWORD PTR [ebp-0x30],0x1
    call   R6GameServiceAddresses::LoadSerializedByteStore
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x18]
    push   eax
    push   0x6f
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ebx,DWORD PTR [ebp-0x28]
    mov    ecx,DWORD PTR [esi+0x5c]
    imul   ebx,ebx,0xdc
    mov    edx,DWORD PTR [ebp-0x18]
    lea    eax,[ebp-0x18]
    push   eax
    mov    DWORD PTR [ecx+ebx*1+0x40],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   0x70
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edx,DWORD PTR [ebp-0x18]
    lea    eax,[ebp-0x18]
    push   eax
    mov    DWORD PTR [ecx+ebx*1+0x44],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   0x71
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edx,DWORD PTR [ebp-0x18]
    lea    eax,[ebp-0x11]
    push   eax
    mov    DWORD PTR [ecx+ebx*1+0x48],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   0x72
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    xor    edx,edx
    mov    dl,BYTE PTR [ebp-0x11]
    lea    eax,[ecx+ebx*1+0x4c]
    xor    edx,edi
    and    edx,0x1
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x73
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    lea    eax,[ecx+ebx*1+0x4c]
    shl    edx,1
    xor    edx,edi
    and    edx,0x2
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x74
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    lea    eax,[ecx+ebx*1+0x4c]
    shl    edx,0x3
    xor    edx,edi
    and    edx,0x8
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x75
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    lea    eax,[ecx+ebx*1+0x4c]
    mov    edi,DWORD PTR [eax]
    shl    edx,0x4
    xor    edx,edi
    and    edx,0x10
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x76
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    lea    eax,[ecx+ebx*1+0x4c]
    shl    edx,0x5
    xor    edx,edi
    and    edx,0x20
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x18]
    push   eax
    push   0x77
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edx,DWORD PTR [ebp-0x18]
    lea    eax,[ebp-0x18]
    push   eax
    mov    DWORD PTR [ecx+ebx*1+0x50],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   0x78
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edx,DWORD PTR [ebp-0x18]
    lea    eax,[ebp-0x11]
    push   eax
    mov    DWORD PTR [ecx+ebx*1+0x54],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    push   0x79
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    xor    edx,edx
    mov    dh,BYTE PTR [ebp-0x11]
    lea    eax,[ecx+ebx*1+0x4c]
    xor    edx,edi
    and    edx,0x100
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x7a
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    mov    edi,DWORD PTR [ecx+ebx*1+0x4c]
    lea    eax,[ecx+ebx*1+0x4c]
    shl    edx,0x7
    xor    edx,edi
    and    edx,0x80
    xor    edi,edx
    mov    DWORD PTR [eax],edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    eax,[ebp-0x11]
    push   eax
    push   0x7b
    call   R6GameServiceAddresses::ReadStoredWord
    mov    ecx,DWORD PTR [esi+0x5c]
    movzx  edx,BYTE PTR [ebp-0x11]
    lea    eax,[ecx+ebx*1+0x4c]
    mov    ecx,DWORD PTR [eax]
    shl    edx,0x9
    xor    edx,ecx
    and    edx,0x200
    xor    ecx,edx
    mov    DWORD PTR [eax],ecx
    mov    eax,DWORD PTR [esi+0x5c]
    push   0x0
    lea    ecx,[eax+ebx*1+0xb8]
    call   R6GameServiceAddresses::ResetStringPairArray18
    xor    edi,edi
    mov    DWORD PTR [ebp-0x1c],edi
    mov    edi,edi
  Branch157:
    lea    ecx,[ebp-0x20]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x144]
    push   edx
    lea    eax,[edi+0x7c]
    push   eax
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    mov    DWORD PTR [ebp-0x24],eax
    jl     Branch158
    mov    edi,DWORD PTR [ebp-0x28]
    mov    ecx,DWORD PTR [esi+0x5c]
    imul   edi,edi,0xdc
    push   0x1
    lea    ecx,[ecx+edi*1+0xb8]
    push   0x18
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ecx,DWORD PTR [esi+0x5c]
    add    ecx,edi
    mov    ecx,DWORD PTR [ecx+0xb8]
    lea    ebx,[eax+eax*2]
    shl    ebx,0x3
    lea    edx,[ebp-0x144]
    add    ecx,ebx
    push   edx
    mov    DWORD PTR [ebp-0x2c],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR [ebp-0x2c]
    add    esp,0x4
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    ecx,DWORD PTR [ebp-0x1c]
    lea    eax,[ebp-0x18]
    add    ecx,0x9c
    push   eax
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredWord
    mov    edx,DWORD PTR [ebp-0x18]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [ecx]
    push   edx
    lea    eax,[ebp-0x44]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeNameSlot
    mov    edx,DWORD PTR [esi+0x5c]
    push   eax
    mov    eax,DWORD PTR [edx+edi*1+0xb8]
    lea    ecx,[eax+ebx*1+0xc]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0x44]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,DWORD PTR [ebp-0x24]
    mov    edi,DWORD PTR [ebp-0x1c]
  Branch158:
    inc    edi
    test   eax,eax
    mov    DWORD PTR [ebp-0x1c],edi
    jl     Branch159
    cmp    edi,0x10
    jl     Branch157
  Branch159:
    mov    ecx,DWORD PTR [ebp-0x28]
    mov    edx,DWORD PTR [esi+0x5c]
    imul   ecx,ecx,0xdc
    lea    edi,[ecx+edx*1+0xc4]
    mov    DWORD PTR [ebp-0x1c],0x0
  Branch160:
    mov    eax,DWORD PTR [ebp-0x1c]
    cmp    eax,DWORD PTR [edi+0x4]
    jge    Branch161
    mov    ebx,eax
    mov    eax,DWORD PTR [edi]
    imul   ebx,ebx,0x2c
    add    ebx,eax
    mov    DWORD PTR [ebp-0x24],ebx
    lea    ecx,[ebx+0x20]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,ebx
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    inc    DWORD PTR [ebp-0x1c]
    jmp    Branch160
  Branch161:
    push   0x2c
    mov    ecx,edi
    mov    DWORD PTR [edi+0x4],0x0
    mov    DWORD PTR [edi+0x8],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    xor    edi,edi
    mov    DWORD PTR [ebp-0x1c],edi
  Branch162:
    lea    ecx,[ebp-0x20]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    lea    edx,[ebp-0x144]
    push   edx
    lea    eax,[edi+0xbc]
    push   eax
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredBytes
    test   eax,eax
    mov    DWORD PTR [ebp-0x2c],eax
    jl     Branch163
    mov    edi,DWORD PTR [ebp-0x28]
    mov    ecx,DWORD PTR [esi+0x5c]
    imul   edi,edi,0xdc
    push   0x1
    lea    ecx,[ecx+edi*1+0xc4]
    push   0x2c
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddZeroedSlot
    mov    ecx,DWORD PTR [esi+0x5c]
    mov    ebx,eax
    imul   ebx,ebx,0x2c
    add    ecx,edi
    mov    ecx,DWORD PTR [ecx+0xc4]
    lea    edx,[ebp-0x144]
    add    ecx,ebx
    push   edx
    mov    DWORD PTR [ebp-0x24],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR [ebp-0x24]
    add    esp,0x4
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    edx,DWORD PTR [ebp-0x1c]
    lea    eax,[ebp-0x20]
    push   eax
    lea    ecx,[ebp-0x144]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    add    edx,0xcc
    push   edx
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredBytes
    mov    eax,DWORD PTR [esi+0x5c]
    add    eax,edi
    mov    eax,DWORD PTR [eax+0xc4]
    add    eax,ebx
    mov    DWORD PTR [ebp-0x24],eax
    lea    eax,[ebp-0x144]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR [ebp-0x24]
    add    esp,0x4
    push   eax
    add    ecx,0x20
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    edx,DWORD PTR [ebp-0x1c]
    lea    ecx,[ebp-0x18]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    add    edx,0xdc
    push   edx
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredWord
    mov    eax,DWORD PTR [esi+0x5c]
    mov    ecx,DWORD PTR [eax+edi*1+0xc4]
    mov    edx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [ecx+ebx*1+0xc],edx
    mov    ecx,DWORD PTR [ebp-0x1c]
    lea    eax,[ebp-0x18]
    add    ecx,0xec
    push   eax
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServerReplySerializedStore
    mov    DWORD PTR [ebp-0x20],0x100
    mov    BYTE PTR [ebp-0x144],0x0
    call   R6GameServiceAddresses::ReadStoredWord
    mov    edx,DWORD PTR [esi+0x5c]
    mov    eax,DWORD PTR [edx+edi*1+0xc4]
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    edi,DWORD PTR [ebp-0x1c]
    mov    DWORD PTR [eax+ebx*1+0x18],ecx
    mov    eax,DWORD PTR [ebp-0x2c]
  Branch163:
    inc    edi
    test   eax,eax
    mov    DWORD PTR [ebp-0x1c],edi
    jl     Branch164
    cmp    edi,0x10
    jl     Branch162
  Branch164:
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray2
  Branch165:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    edx,DWORD PTR [edi+0x8]
    mov    eax,DWORD PTR [ecx]
    push   edx
    call   DWORD PTR [eax+0x8]
    mov    eax,ds:R6GameServiceAddresses::GServiceArray2+0x4
    test   eax,eax
    jge    Branch166
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch166:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray2+0x4,0x1
    jge    Branch167
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch167:
    xor    eax,eax
  Branch168:
    cmp    eax,0x1
    jge    Branch169
    inc    eax
    jmp    Branch168
  Branch169:
    push   0x10
    push   0x1
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceArray2
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
  Branch170:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,DWORD PTR [ebp-0x30]
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
    mov    eax,ds:0x10091c14
    push   ebx
    xor    ebx,ebx
    push   esi
    dec    eax
    cmp    eax,0x5
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],ebx
    ja     Branch171
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessMSClientInitRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x100933c8
    mov    ecx,esi
    mov    DWORD PTR ds:0x10091c14,0x2
    mov    DWORD PTR ds:0x10091c0c,ebx
    call   R6GameServiceAddresses::UR6GSServers_InitMSClient
  Branch171:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x100933c8
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch171
    mov    DWORD PTR ds:0x10091c14,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitMSClient
    mov    DWORD PTR ds:0x10091c14,ebx
    mov    DWORD PTR ds:0x10091c0c,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10091e6c,0x1
    or     DWORD PTR [esi+0x194],0x80
    push   R6GameServiceAddresses::WideTextLOGINSUCCESS
    lea    ecx,[ebp-0x24]
    mov    DWORD PTR ds:0x10091c14,ebx
    mov    DWORD PTR ds:0x10091c0c,0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x24]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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

// Starts a server refresh only when logged in and no refresh is already active.
// If service enabled and both refresh flags idle, store float cycle time, mark refreshing, clear server/index arrays and request current game name.
// Register both context catches before gates; preserve late counts/name/logging and partial effects on interruption.
// R6GameService.dll @ 1000c0d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RefreshServers(UR6GSServers *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectRefreshServersEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:0x10091e6c
    test   eax,eax
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    je    Branch172
    mov    eax,ds:0x10091d30
    test   eax,eax
    jne    Branch172
    mov    eax,ds:0x10091d38
    test   eax,eax
    jne    Branch172
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
    mov    DWORD PTR ds:0x10091d38,0x1
    mov    DWORD PTR ds:0x10091bf8,0x0
    mov    eax,DWORD PTR [esi+0x60]
    push   eax
    push   0x0
    lea    ecx,[esi+0x5c]
    call   R6GameServiceAddresses::RemoveSTGameServerRange
    mov    eax,DWORD PTR [esi+0x84]
    push   eax
    push   0x0
    lea    ecx,[esi+0x80]
    call   R6GameServiceAddresses::RemoveFourByteArrayElements
    mov    ecx,R6GameServiceAddresses::GServiceString1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::ForwardMSClientOperation1
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je    Branch172
    mov    ecx,R6GameServiceAddresses::GServiceString1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSClientRequestGameServersMSzGameServiceGameNameS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch172:
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

// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// R6GameService.dll @ 1000c1f0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execRefreshServers(UR6GSServers *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_SelectSmallVMBridgeEH5
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch173
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch173:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_RefreshServers
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
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    push   ebx
    push   esi
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],ebx
    je     Branch186
    mov    eax,DWORD PTR [ebp+0x14]
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    edx,DWORD PTR [ebp+0xc]
    push   eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   ecx
    push   edx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_PollCallbacks
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ReceiveServer
    cmp    eax,ebx
    je     Branch174
    or     DWORD PTR [esi+0x48],0x2
  Branch174:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ReceiveAltInfo
    cmp    eax,ebx
    je     Branch175
    or     DWORD PTR [esi+0x48],0x4
  Branch175:
    cmp    DWORD PTR ds:0x10091c20,ebx
    je     Branch176
    or     DWORD PTR [esi+0x48],0x2
  Branch176:
    xor    edi,edi
    jmp    Branch177
    lea    ebx,[ebx+0x0]
  Branch177:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray4+0x4
    cmp    edi,eax
    jge    Branch178
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray4
    mov    eax,DWORD PTR [ecx+edi*4]
    mov    edx,DWORD PTR [esi+0x5c]
    imul   eax,eax,0xdc
    sub    esp,0xc
    add    eax,edx
    add    eax,0x10
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x14],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray4
    mov    eax,DWORD PTR [edx+edi*4]
    mov    edx,DWORD PTR [esi+0x5c]
    imul   eax,eax,0xdc
    sub    esp,0xc
    add    eax,edx
    add    eax,0x5c
    mov    ecx,esp
    mov    DWORD PTR [ebp+0xc],esp
    push   eax
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::UR6GSServers_PingRequest
    inc    edi
    jmp    Branch177
  Branch178:
    cmp    eax,ebx
    mov    edi,eax
    jge    Branch180
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray4+0x4
    add    esp,0xc
    cmp    edi,eax
    jle    Branch179
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch179:
    xor    ebx,ebx
  Branch180:
    push   0x4
    push   edi
    push   ebx
    mov    ecx,R6GameServiceAddresses::GServiceArray4
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    cmp    DWORD PTR ds:0x10091d38,ebx
    je     Branch182
    cmp    DWORD PTR ds:0x10091bf8,ebx
    jne    Branch181
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fld    DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
    fsubr  st,st(1)
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    fstp   st(0)
    test   ah,0x41
    jne    Branch184
  Branch181:
    cmp    DWORD PTR ds:0x10091d3c,ebx
    jne    Branch184
    mov    DWORD PTR ds:0x10091d38,ebx
    or     DWORD PTR [esi+0x194],0x400
    jmp    Branch184
  Branch182:
    cmp    DWORD PTR ds:0x10091d30,ebx
    je     Branch184
    cmp    DWORD PTR ds:0x10091bf8,ebx
    jne    Branch183
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fld    DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_0
    fsubr  st,st(1)
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    fstp   st(0)
    test   ah,0x41
    jne    Branch184
  Branch183:
    mov    DWORD PTR ds:0x10091d30,ebx
    mov    edi,DWORD PTR [esi+0x194]
    mov    eax,DWORD PTR [esi+0x44]
    push   0x1
    or     edi,0x400
    push   eax
    lea    ecx,[esi+0x5c]
    mov    DWORD PTR [esi+0x194],edi
    call   R6GameServiceAddresses::RemoveSTGameServerRange
    mov    ecx,DWORD PTR [esi+0x44]
    push   0x1
    push   ecx
    lea    ecx,[esi+0x80]
    call   R6GameServiceAddresses::RemoveFourByteArrayElements
  Branch184:
    cmp    DWORD PTR [ebp+0x10],ebx
    je     Branch185
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ReceiveValidation
  Branch185:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessMSClientInitRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRouterRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessRegServerGetLobbiesRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessRegServerRegOnLobbyRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessRegServerLoginRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessRegServerUpdateRequest
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ProcessJoinServerRequest
  Branch186:
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
// R6GameService.dll data @ 1007d018 : native storage identity retained.
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
// R6GameService.dll @ 1000c4f0 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6GSServers * __thiscall UR6GSServers::UR6GSServers(void)
{
  // State11 guards the body; state12 is its catch. Both unwind to completed-string state10.
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
    call   R6GameServiceAddresses::UR6ServerList_UR6ServerList
    lea    ecx,[esi+0x1a0]
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6GSServersDispatchTable
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x1ac]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x1b8]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    edi,[esi+0x1c4]
    mov    ecx,edi
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x1d0]
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ebx,[esi+0x1dc]
    mov    ecx,ebx
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x1e8]
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x1f4]
    mov    BYTE PTR [ebp-0x4],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x200]
    mov    BYTE PTR [ebp-0x4],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    lea    ecx,[esi+0x20c]
    mov    BYTE PTR [ebp-0x4],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0xb
    call   R6GameServiceAddresses::UR6GSServers_CreatedCDKey
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_LogGSVersion
    push   edi
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_NativeStartedByGSClientSlot
    mov    ebx,DWORD PTR [esi+0x194]
    shl    eax,0x2
    xor    eax,ebx
    and    eax,0x4
    mov    edx,ebx
    xor    edx,eax
    mov    DWORD PTR [esi+0x194],edx
    mov    ecx,DWORD PTR ds:0x10092e80
    push   0x0
    push   ecx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    mov    edx,DWORD PTR [esi]
    push   0x0
    push   0x0
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edx+0x10]
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
// R6GameService.dll @ 1000c670 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::CreatedCDKey(UR6GSServers *this)
{
  // RegGet status is ignored; callee owns its two by-value strings. Valid input does not set activation bit0.
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::CreatedCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x2c
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    lea    eax,[ebp-0x2c]
    push   eax
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    mov    bl,0x1
    push   R6GameServiceAddresses::WideTextCDKey
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainmentRAVENSHIELD
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__RegGetSlot
    add    esp,0x10
    lea    edx,[ebp-0x2c]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    call   R6GameServiceAddresses::IsCDKeyValidOnMachine
    add    esp,0xc
    test   eax,eax
    je     Branch187
    sub    esp,0xc
    lea    eax,[ebp-0x2c]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[ebp-0x38]
    push   ecx
    call   R6GameServiceAddresses::DecryptFStringWithUeviLCore
    add    esp,0x10
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString8
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x38]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch188
  Branch187:
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    and    DWORD PTR [esi+0x194],0xfffffffe
  Branch188:
    push   R6GameServiceAddresses::GServiceString8
    mov    ecx,R6GameServiceAddresses::GServiceString9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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

// Loads the Raven Shield CD-key registry value and updates the cached key state.

// Finishes debug info on Stack.Object, calls the current initialization virtual method and writes its full result.
// R6GameService.dll @ 1000c920 : exported member ABI; exact current loads, raw registers and guard order retained.
__declspec(naked) void __thiscall UR6GSServers::execInitGSCDKey(FFrame &Stack, void * const Result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::execInitGSCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch189
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch189:
    mov    edx,DWORD PTR [esi]
    mov    ecx,esi
    call   DWORD PTR [edx+0x68]
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
// R6GameService.dll @ 1000c9c0 : exported nonvirtual void(void); exact current loads, raw ABI and guard order.
__declspec(naked) void __thiscall UR6GSServers::UnInitCDKey(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UnInitCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ecx]
    push   ebx
    push   esi
    push   edi
    xor    esi,esi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],esi
    call   DWORD PTR [eax+0x90]
    cmp    DWORD PTR ds:0x10093410,esi
    je     Branch190
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   ecx
    call   R6GameServiceAddresses::RemoveCDKeyContextOrRegistry
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch190
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRSCDKeyGSCDKeyUninitialize
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch190:
    cmp    DWORD PTR ds:0x100933cc,esi
    je     Branch191
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    push   ecx
    call   R6GameServiceAddresses::RemoveCDKeyContextOrRegistry
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch191
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextModCDKeyGSCDKeyUninitialize
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch191:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    DWORD PTR ds:0x10093410,esi
    mov    DWORD PTR ds:0x100933cc,esi
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
// R6GameService.dll @ 1000cab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RequestActivation(FString key,int selector)
{
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
    mov    DWORD PTR [ebp-0x14],ebx
    mov    DWORD PTR [ebp-0x4],ebx
    mov    BYTE PTR [ebp-0x4],0x1
    mov    ecx,0x10091c28
    lea    edx,[ebp-0xf4]
    jmp    Branch192
    lea    ecx,[ecx+0x0]
  Branch192:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch192
    mov    ax,ds:0x10091c04
    mov    WORD PTR [ebp-0x72],ax
    mov    eax,DWORD PTR [ebp+0xc]
    test   eax,eax
    je     Branch193
    dec    eax
    cmp    eax,0x17
    jbe    Branch193
    push   R6GameServiceAddresses::WideTextCDKEYNotValid
    lea    ecx,[ebp-0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    or     ebx,0x1
    mov    BYTE PTR [ebp-0x4],0x2
    mov    DWORD PTR [ebp-0x14],ebx
    jmp    Branch194
  Branch193:
    lea    eax,[ebp+0x8]
  Branch194:
    push   eax
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    test   bl,0x1
    mov    DWORD PTR [ebp-0x4],0x4
    je     Branch195
    lea    ecx,[ebp-0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch195:
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   esi
    add    esp,0x4
    push   0x17
    push   eax
    lea    ecx,[ebp-0x4f]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strncpySlot
    mov    eax,DWORD PTR [ebp+0x14]
    add    esp,0xc
    test   eax,eax
    mov    BYTE PTR [ebp-0x37],0x0
    je     Branch197
    mov    ecx,R6GameServiceAddresses::GServiceString1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x70]
  Branch196:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch196
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    jmp    Branch198
  Branch197:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::TextELD
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::TextRAVENSHIELD
    mov    eax,ds:R6GameServiceAddresses::TextNSHIELD
    mov    DWORD PTR [ebp-0x68],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    mov    DWORD PTR [ebp-0x70],edx
    mov    DWORD PTR [ebp-0x6c],eax
  Branch198:
    push   0x6
    lea    edx,[ebp-0x70]
    push   edx
    lea    eax,[ebp-0xf4]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation5
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch199
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
    push   R6GameServiceAddresses::WideTextGSCDKeyRequestActivationS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch199:
    lea    ecx,[ebp-0x24]
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
// R6GameService.dll @ 1000cc80 : nonvirtual void export; unused ECX receiver, raw EAX unchanged, RET0.
// Global role names are inferred.
__declspec(naked) void __thiscall UR6GSServers::RequestGSCDKeyActID(void)
{
  __asm {
    mov    DWORD PTR ds:0x100933f4,0x0
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x1
    ret
  }
}

// Clear activation reply, shared retry count and activation state in order.
// R6GameService.dll @ 1000cca0 : nonvirtual void export; unused ECX receiver, raw EAX0, RET0.
// Global role names are inferred.
__declspec(naked) void __thiscall UR6GSServers::CancelGSCDKeyActID(void)
{
  __asm {
    xor    eax,eax
    mov    ds:0x100933f4,eax
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    mov    ds:R6GameServiceAddresses::GActivationState,eax
    ret
  }
}

// Submit saved activation bytes and bounded key text through the zero/nonzero selected client.
// Exported nonvirtual void(int), unused incoming ECX, RET4; selector and scratch names are inferred.
// Endpoint at EBP-c8 has 130 address bytes then WORD port; payload at EBP-44 copies 16 ID bytes and 23 key bytes.
// Payload+39 stays unwritten; +40 is zero. Both context slots are read for selector 0, Mod slot first.
// State 0 is published before the unbounded endpoint copy. No local or incoming FString ownership.
// Debug logging reloads the RS context even for Mod requests and forwards the three current key words.
// R6GameService.dll @ 1000ccc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RequestAuthorization(int selector)
{
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
    mov    DWORD PTR [ebp-0x4],0x0
    mov    ecx,0x10091c28
    lea    edx,[ebp-0xc8]
  Branch201:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch201
    mov    ax,ds:0x10091c04
    mov    WORD PTR [ebp-0x46],ax
    xor    eax,eax
    lea    esp,[esp+0x0]
  Branch202:
    cmp    eax,0x10
    jae    Branch203
    mov    cl,BYTE PTR [eax+0x100933f8]
    mov    BYTE PTR [ebp+eax*1-0x44],cl
    inc    eax
    jmp    Branch202
  Branch203:
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   0x17
    push   eax
    lea    edx,[ebp-0x34]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_strncpySlot
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    add    esp,0xc
    push   0x6
    test   eax,eax
    lea    eax,[ebp-0x44]
    lea    ecx,[ebp-0xc8]
    push   eax
    mov    BYTE PTR [ebp-0x1c],0x0
    push   ecx
    jne    Branch204
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
  Branch204:
    push   edx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation6
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch205
    mov    eax,ds:R6GameServiceAddresses::GBaseCDKeyContext
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString8
    push   eax
    mov    eax,ds:R6GameServiceAddresses::GServiceString8+0x4
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString8+0x8
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSCDKeyRequestAuthorizationSD
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x18
  Branch205:
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

// Mark authorization requested; raw EAX is unchanged.
// R6GameService.dll @ 1000ce00 : virtual void export; unused ECX receiver, RET0; global role names inferred.
__declspec(naked) void __thiscall UR6GSServers::RequestGSCDKeyAuthID(void)
{
  __asm {
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x1
    ret
  }
}

// Clear shared retry count, authorization state and authorization reply in order.
// R6GameService.dll @ 1000ce10 : nonvirtual void export; unused ECX receiver, raw EAX0, RET0.
// Global role names are inferred.
__declspec(naked) void __thiscall UR6GSServers::CancelGSCDKeyAuthID(void)
{
  __asm {
    xor    eax,eax
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    mov    ds:R6GameServiceAddresses::GAuthorizationState,eax
    mov    ds:0x10093414,eax
    ret
  }
}

// Clear the 20 binary authentication bytes with five ordered DWORD stores.
// R6GameService.dll @ 1000ce30 : virtual void export; unused ECX receiver, raw EAX0, RET0; global role names inferred.
__declspec(naked) void __thiscall UR6GSServers::ResetAuthId(void)
{
  __asm {
    xor    eax,eax
    mov    ds:0x10093428,eax
    mov    ds:0x1009342c,eax
    mov    ds:0x10093430,eax
    mov    ds:0x10093434,eax
    mov    ds:0x10093438,eax
    ret
  }
}

// Copy the zero/nonzero selected cached FString into caller-owned hidden result storage.
// Exported virtual FString(int); explicit native hidden-result pointer at ESP+4, selector at ESP+8, RET8.
// Incoming ECX is unused; native EAX returns the saved result pointer, ignoring the copy constructor result.
// The borrowed global and caller result have no cleanup action in this frame; selector name inferred.
// R6GameService.dll @ 1000ce50 : complete native control/access order and raw ABI retained.
__declspec(naked) FString * __thiscall UR6GSServers::GetAuthID(FString *result,int selector)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_GetAuthIDSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0xc]
    test   eax,eax
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    push   edi
    mov    DWORD PTR [ebp-0x18],0x0
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    ecx,esi
    je     Branch207
    push   R6GameServiceAddresses::GServiceString11
  Branch206:
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  Branch207:
    push   R6GameServiceAddresses::GServiceString4
    jmp    Branch206
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
// R6GameService.dll @ 1000cef0 : exported nonvirtual int(void); exact current loads, raw ABI and guard order.
__declspec(naked) int __thiscall UR6GSServers::IsAuthIDSuccess(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::IsAuthIDSuccessSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch208
    mov    eax,ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [eax]
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   eax
    push   R6GameServiceAddresses::WideTextIsAuthIDSuccessIsRavenshieldD
    push   edx
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString3
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString3+0x4
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString3+0x8
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSzGameServiceMODGameNameS
    push   eax
    call   esi
    add    esp,0x14
  Branch208:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [ecx]
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    test   eax,eax
    jne    Branch209
    mov    ecx,R6GameServiceAddresses::GServiceString3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   R6GameServiceAddresses::WideTextR6RSCUSTOM
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appStricmpSlot
    add    esp,0x8
    test   eax,eax
    je     Branch209
    xor    eax,eax
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch209:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    eax,0x1
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
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

// Submit20 decoded authentication bytes with the current endpoint and selected validation context.
// Exported nonvirtual int(FString,int,int), incoming ECX unused/RET20; owns the12-byte input string.
// Endpoint/text copies are unbounded. Endpoint is EBP-d8, port WORD at-56; text at-54 overlaps decoded
// bytes at-2c. Exactly40 character reads via low-digit-then-high helpers occur even after early NUL.
// Mode0 selects kind3, otherwise6; Mod flag uses full nonzero, cached ANSI converter/current context.
// Current debug log forwards raw FString words; state lowers-1 before its sole input destructor.
// Raw validation status survives diagnostics/destruction. No bounds check or stronger rollback.
// R6GameService.dll @ 1000d110 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::CDKeyValidateUser(FString authenticationId,
  int validationMode,int modIndex)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_CDKeyValidateUserSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xcc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    xor    esi,esi
    mov    DWORD PTR [ebp-0x4],esi
    mov    BYTE PTR [ebp-0x4],0x1
    mov    ecx,0x10091c28
    lea    edx,[ebp-0xd8]
  Branch211:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch211
    mov    ax,ds:0x10091c04
    lea    ecx,[ebp+0x8]
    mov    WORD PTR [ebp-0x56],ax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   edi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x54]
  Branch212:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch212
  Branch213:
    cmp    esi,0x28
    jae    Branch214
    lea    ecx,[ebp+esi*1-0x53]
    push   ecx
    call   R6GameServiceAddresses::HexDigitToValue
    lea    edx,[ebp+esi*1-0x54]
    add    esp,0x4
    push   edx
    mov    ebx,eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x2c],cl
    add    esi,0x2
    jmp    Branch213
  Branch214:
    mov    eax,DWORD PTR [ebp+0x14]
    test   eax,eax
    mov    esi,0x3
    je     Branch215
    mov    esi,0x6
  Branch215:
    mov    eax,DWORD PTR [ebp+0x18]
    test   eax,eax
    je     Branch216
    mov    ecx,R6GameServiceAddresses::GServiceString1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    add    esp,0x4
    push   esi
    push   eax
    jmp    Branch217
  Branch216:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   esi
    push   R6GameServiceAddresses::TextRAVENSHIELD
  Branch217:
    lea    eax,[ebp-0x2c]
    push   eax
    lea    ecx,[ebp-0xd8]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation2
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch218
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [ebp+0xc]
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSCDKeyValidateUserS
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch218:
    lea    ecx,[ebp+0x8]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x14
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

// Reads the base/current-mod registry key, validates its machine binding, decrypts valid text and records the mode.
// R6GameService.dll @ 1000d790 : exported virtual void(int), RET4; original parameter/global names inferred.
// Nonzero selects the current mod, not an indexed lookup; invalid keys clear only the selected cache/validity mask.
__declspec(naked) void __thiscall UR6GSServers::RequestModCDKeyProcess(int modProcess)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::RequestModCDKeyProcessSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x34
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    lea    ecx,[ebp-0x28]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    mov    edi,DWORD PTR [ebp+0x8]
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch231
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edi
    push   R6GameServiceAddresses::WideTextMODCDKEYREQUESTD
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch231:
    test   edi,edi
    jne    Branch233
    lea    edx,[ebp-0x28]
    push   edx
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::WideTextCDKey
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainmentRAVENSHIELD
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__RegGetSlot
    add    esp,0x10
    lea    eax,[ebp-0x28]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    call   R6GameServiceAddresses::IsCDKeyValidOnMachine
    add    esp,0xc
    test   eax,eax
    je     Branch232
    sub    esp,0xc
    lea    edx,[ebp-0x28]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    eax,[ebp-0x34]
    push   eax
    call   R6GameServiceAddresses::DecryptFStringWithUeviLCore
    add    esp,0x10
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString8
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x34]
    jmp    Branch236
  Branch232:
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    and    DWORD PTR [esi+0x194],0xfffffffe
    jmp    Branch237
  Branch233:
    push   R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainment
    lea    ecx,[ebp-0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edx+0x34]
    add    eax,0x94
    mov    bl,0x4
    push   eax
    lea    ecx,[ebp-0x34]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot
    lea    ecx,[ebp-0x28]
    push   ecx
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::WideTextCDKey
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub    esp,0xc
    lea    edx,[ebp-0x34]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   edx
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__RegGetSlot
    add    esp,0x10
    lea    eax,[ebp-0x28]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    call   R6GameServiceAddresses::IsCDKeyValidOnMachine
    add    esp,0xc
    test   eax,eax
    je     Branch234
    sub    esp,0xc
    lea    edx,[ebp-0x28]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    eax,[ebp-0x40]
    push   eax
    call   R6GameServiceAddresses::DecryptFStringWithUeviLCore
    add    esp,0x10
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString5
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x40]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch235
  Branch234:
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    mov    eax,DWORD PTR [esi+0x19c]
    and    DWORD PTR [eax+0x3c],0xfffffffe
  Branch235:
    lea    ecx,[ebp-0x34]
  Branch236:
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch237:
    lea    ecx,[ebp-0x28]
    mov    DWORD PTR ds:0x10093408,edi
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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

// Drain ordinary validation before Mod validation into the server response arrays; append before consuming.
// Exported nonvirtual void(void), RET0; +68/+74 match m_ValidResponseList/m_ModValidResponseList in1.60.
// Source32 bytes -> destination28: DWORD+4 -> +0, byte+0 -> +4, low bits+8/+c -> flags+8 bits0/1,
// sixteen bytes+10 -> +c. Package names: iReqID/eStatus/bSuceeded/bTimeout/ucGlobalID (native offsets).
// Padding5..7 and other flag bits survive; tail copies four forward DWORDs.
// Each early field reloads current queue/data pointers; the tail captures them once, retaining overlap effects.
// Cached assertion target precedes state0; signed current count checks and the empty destructor loop remain.
// No owned local resources or rollback. Physical normal continuationf0be shares this body; ef9e is dead alignment.
// R6GameService.dll @ 1000ee80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ReceiveValidation(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ReceiveValidationSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [ebp-0x10],esp
    mov    ebx,ecx
    mov    DWORD PTR [ebp-0x4],0x0
  Branch238:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8+0x4
    test   eax,eax
    jle    Branch243
    push   0x1c
    lea    esi,[ebx+0x68]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x1c
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [edx+0x4]
    mov    ecx,DWORD PTR [esi]
    mov    DWORD PTR [eax+ecx*1],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    dl,BYTE PTR [edx]
    mov    ecx,DWORD PTR [esi]
    mov    BYTE PTR [eax+ecx*1+0x4],dl
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [edx+0x8]
    xor    edx,DWORD PTR [eax+ecx*1+0x8]
    lea    ecx,[eax+ecx*1+0x8]
    and    edx,0x1
    xor    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [edx+0xc]
    mov    ecx,DWORD PTR [esi]
    lea    ecx,[eax+ecx*1+0x8]
    shl    edx,1
    xor    edx,DWORD PTR [ecx]
    and    edx,0x2
    xor    DWORD PTR [ecx],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray8
    mov    edx,DWORD PTR [esi]
    lea    eax,[eax+edx*1+0xc]
    add    ecx,0x10
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [eax],edx
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [eax+0x8],edx
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0xc],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray8+0x4
    test   eax,eax
    jge    Branch239
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   edi
    add    esp,0xc
  Branch239:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray8+0x4,0x1
    jge    Branch240
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   edi
    add    esp,0xc
  Branch240:
    xor    eax,eax
    lea    esp,[esp+0x0]
  Branch241:
    cmp    eax,0x1
    jge    Branch242
    inc    eax
    jmp    Branch241
  Branch242:
    push   0x20
    push   0x1
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceArray8
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    jmp    Branch238
    mov    edi,edi
  Branch243:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7+0x4
    test   eax,eax
    jle    Branch248
    push   0x1c
    lea    esi,[ebx+0x74]
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x1c
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    ecx,DWORD PTR [ecx+0x4]
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [eax+edx*1],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    cl,BYTE PTR [ecx]
    mov    edx,DWORD PTR [esi]
    mov    BYTE PTR [eax+edx*1+0x4],cl
    mov    edx,DWORD PTR [esi]
    lea    ecx,[eax+edx*1+0x8]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    edx,DWORD PTR [edx+0x8]
    xor    edx,DWORD PTR [ecx]
    and    edx,0x1
    xor    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    edx,DWORD PTR [edx+0xc]
    mov    ecx,DWORD PTR [esi]
    lea    ecx,[eax+ecx*1+0x8]
    shl    edx,1
    xor    edx,DWORD PTR [ecx]
    and    edx,0x2
    xor    DWORD PTR [ecx],edx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray7
    mov    edx,DWORD PTR [esi]
    lea    eax,[eax+edx*1+0xc]
    add    ecx,0x10
    mov    edx,DWORD PTR [ecx]
    mov    DWORD PTR [eax],edx
    mov    edx,DWORD PTR [ecx+0x4]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR [ecx+0x8]
    mov    DWORD PTR [eax+0x8],edx
    mov    ecx,DWORD PTR [ecx+0xc]
    mov    DWORD PTR [eax+0xc],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceArray7+0x4
    test   eax,eax
    jge    Branch244
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   edi
    add    esp,0xc
  Branch244:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray7+0x4,0x1
    jge    Branch245
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   edi
    add    esp,0xc
  Branch245:
    xor    eax,eax
    lea    ebx,[ebx+0x0]
  Branch246:
    cmp    eax,0x1
    jge    Branch247
    inc    eax
    jmp    Branch246
  Branch247:
    push   0x20
    push   0x1
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceArray7
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    jmp    Branch243
  Branch248:
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
// R6GameService.dll @ 1000f0d0 : exported member ABI; exact current loads, raw registers and guard order retained.
__declspec(naked) void __thiscall UR6GSServers::registerCDKeySDKCallbacks
    (UR6GSServers *callbackContext, void *rsHandle, void *modHandle)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    test   esi,esi
    mov    ds:0x10091c18,eax
    je     Branch249
    push   R6GameServiceAddresses::ReceiveActivationReply
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtC8
    push   R6GameServiceAddresses::RcvValidationResponse
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtD0
    push   R6GameServiceAddresses::ReceiveAuthorizationReply
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtCC
    push   R6GameServiceAddresses::OnRSPlayerStatusRequest
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtD4
  Branch249:
    mov    esi,DWORD PTR [esp+0x10]
    test   esi,esi
    je     Branch250
    push   R6GameServiceAddresses::ReceiveActivationReply
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtC8
    push   R6GameServiceAddresses::RcvModValidationResponse
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtD0
    push   R6GameServiceAddresses::ReceiveAuthorizationReply
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtCC
    push   R6GameServiceAddresses::OnModPlayerStatusRequest
    push   esi
    call   R6GameServiceAddresses::thunk_SetContextCallbackAtD4
  Branch250:
    pop    esi
    ret    0xc
  }
}

// Searches full-width consecutive ports under signed current retry bounds; installs callbacks when RS is initialized.
// R6GameService.dll @ 1000f1e0 : exported member ABI; exact current loads, raw registers and guard order retained.
// RS reloads its flag; Mod retains EAX between iterations unless success logging reloads it. Skipped f21d LEA retained.
__declspec(naked) void __thiscall UR6GSServers::InitCDKey(int rsStartingPort, int modStartingPort)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::InitCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:0x10093410
    push   ebx
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   esi
    xor    esi,esi
    cmp    eax,esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],ecx
    mov    DWORD PTR [ebp-0x4],esi
    jne    Branch254
    mov    edi,DWORD PTR [ebp+0x8]
    jmp    Branch251
    lea    ecx,[ecx+0x0]
  Branch251:
    cmp    esi,DWORD PTR ds:0x100933d0
    jge    Branch253
    mov    eax,ds:0x10093410
    test   eax,eax
    jne    Branch253
    lea    eax,[edi+esi*1]
    push   eax
    call   R6GameServiceAddresses::CreateValidatedCDKeyContext
    xor    ecx,ecx
    test   eax,eax
    setne  cl
    mov    ds:R6GameServiceAddresses::GBaseCDKeyContext,eax
    mov    eax,ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    mov    ds:0x10093410,eax
    je     Branch252
    test   eax,eax
    je     Branch252
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[esi+edi*1]
    push   edx
    push   R6GameServiceAddresses::WideTextGSCDKeyInitializeI
    push   ecx
    call   ebx
    add    esp,0xc
  Branch252:
    inc    esi
    jmp    Branch251
  Branch253:
    mov    eax,ds:R6GameServiceAddresses::GBaseCDKeyContext
    test   eax,eax
    jne    Branch254
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSCDKeyInitializeFailed
    push   eax
    call   ebx
    add    esp,0x8
  Branch254:
    mov    eax,ds:0x100933cc
    test   eax,eax
    jne    Branch258
    mov    edi,DWORD PTR [ebp+0xc]
    xor    esi,esi
    mov    edi,edi
  Branch255:
    cmp    esi,DWORD PTR ds:0x100933d0
    jge    Branch257
    test   eax,eax
    jne    Branch257
    lea    ecx,[edi+esi*1]
    push   ecx
    call   R6GameServiceAddresses::CreateValidatedCDKeyContext
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    xor    edx,edx
    test   eax,eax
    setne  dl
    test   ecx,ecx
    mov    ds:R6GameServiceAddresses::GModCDKeyContext,eax
    mov    eax,edx
    mov    ds:0x100933cc,eax
    je     Branch256
    test   eax,eax
    je     Branch256
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    lea    eax,[esi+edi*1]
    push   eax
    push   R6GameServiceAddresses::WideTextGSCDKeyInitializeI
    push   edx
    call   ebx
    mov    eax,ds:0x100933cc
    add    esp,0xc
  Branch256:
    inc    esi
    jmp    Branch255
  Branch257:
    mov    eax,ds:R6GameServiceAddresses::GModCDKeyContext
    test   eax,eax
    jne    Branch258
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSCDKeyInitializeFailed
    push   ecx
    call   ebx
    add    esp,0x8
  Branch258:
    mov    eax,ds:0x10093410
    test   eax,eax
    je     Branch259
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    mov    eax,ds:R6GameServiceAddresses::GBaseCDKeyContext
    mov    ecx,DWORD PTR [ebp-0x14]
    push   edx
    push   eax
    push   ecx
    call   R6GameServiceAddresses::UR6GSServers_registerCDKeySDKCallbacks
  Branch259:
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

// Gets the script retry budget, optionally initializes networking, initializes SDK contexts and tests their flags.
// R6GameService.dll @ 1000f380 : exported member ABI; exact current loads, raw registers and guard order retained.
__declspec(naked) int __thiscall UR6GSServers::InitGSCDKey(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::InitGSCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:0x10092400
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    push   0x0
    push   eax
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x14],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    mov    edx,DWORD PTR [esi]
    push   0x0
    lea    ecx,[ebp-0x14]
    push   ecx
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edx+0x10]
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    test   eax,eax
    mov    edx,DWORD PTR [ebp-0x14]
    mov    DWORD PTR ds:0x100933d0,edx
    jne    Branch260
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [ebp-0x14],esp
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_Init
  Branch260:
    mov    ecx,DWORD PTR [esi+0x188]
    mov    edx,DWORD PTR [esi+0x184]
    push   ecx
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_InitCDKey
    mov    eax,ds:0x10093410
    test   eax,eax
    je     Branch261
    mov    eax,ds:0x100933cc
    test   eax,eax
    je     Branch261
    mov    eax,0x1
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch261:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    xor    eax,eax
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
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
// R6GameService.dll @ 1000f480 : exported virtual void(void); current globals, unbounded copies and guard order.
// Mod decode mixes Mod high digits with RS low digits, but Mod dispatch still uses RS bytes; preserve both quirks.
__declspec(naked) void __thiscall UR6GSServers::DisconnectAllCDKeyPlayers(void)
{
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
    mov    DWORD PTR [ebp-0x4],0x0
    mov    ecx,0x10091c28
    lea    edx,[ebp-0x118]
  Branch262:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch262
    mov    ax,ds:0x10091c04
    mov    WORD PTR [ebp-0x96],ax
    mov    eax,ds:0x10093410
    test   eax,eax
    je     Branch277
    lea    ebx,[ebx+0x0]
  Branch263:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5+0x4
    test   eax,eax
    jle    Branch277
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    ecx,0xc
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   edi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x58]
    lea    ecx,[ecx+0x0]
  Branch264:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch264
    xor    esi,esi
    lea    esp,[esp+0x0]
  Branch265:
    cmp    esi,0x28
    jae    Branch266
    lea    ecx,[ebp+esi*1-0x57]
    push   ecx
    call   R6GameServiceAddresses::HexDigitToValue
    lea    edx,[ebp+esi*1-0x58]
    add    esp,0x4
    push   edx
    mov    ebx,eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x30],cl
    add    esi,0x2
    jmp    Branch265
  Branch266:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    lea    eax,[ebp-0x30]
    push   eax
    lea    ecx,[ebp-0x118]
    push   ecx
    push   edx
    call   R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch267
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    add    eax,0xc
    mov    edx,DWORD PTR [eax]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [eax+0x4]
    mov    eax,DWORD PTR [eax+0x8]
    mov    DWORD PTR [ecx+0x4],edx
    mov    DWORD PTR [ecx+0x8],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextRSDisconnectAllCDKeyPlayersPucAuthIDS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch267:
    mov    eax,ds:0x100933cc
    test   eax,eax
    je     Branch271
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    ecx,0x18
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x80]
  Branch268:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch268
    xor    esi,esi
    nop
  Branch269:
    cmp    esi,0x28
    jae    Branch270
    lea    eax,[ebp+esi*1-0x57]
    push   eax
    call   R6GameServiceAddresses::HexDigitToValue
    lea    ecx,[ebp+esi*1-0x80]
    add    esp,0x4
    push   ecx
    mov    ebx,eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x94],cl
    add    esi,0x2
    jmp    Branch269
  Branch270:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    lea    edx,[ebp-0x30]
    push   edx
    lea    eax,[ebp-0x118]
    push   eax
    push   ecx
    call   R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch271
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    add    edx,0xc
    mov    ecx,DWORD PTR [edx]
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [eax+0x4],ecx
    mov    DWORD PTR [eax+0x8],edx
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextModDisconnectAllCDKeyPlayersPucAuthIDS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch271:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5+0x4
    test   eax,eax
    jge    Branch272
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch272:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4,0x1
    jge    Branch273
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    add    esp,0xc
  Branch273:
    xor    edi,edi
  Branch274:
    cmp    edi,0x1
    jge    Branch275
    mov    eax,ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    shl    esi,0x4
    add    esi,eax
    mov    DWORD PTR [ebp-0x18],esi
    lea    ecx,[esi+0x24]
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x18]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0xc]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    inc    edi
    jmp    Branch274
  Branch275:
    push   0x30
    push   0x1
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceArray5
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   0x1f4
    push   edx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    test   eax,eax
    jne    Branch276
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch276
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextRSGSCDKeyEngineFAILED
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch276:
    mov    eax,ds:0x100933cc
    test   eax,eax
    je     Branch263
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    push   0x1f4
    push   edx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    test   eax,eax
    jne    Branch263
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch263
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMODGSCDKeyEngineFAILED
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    jmp    Branch263
  Branch277:
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
// R6GameService.dll @ 1000f7e0 : exported virtual void(FString), owned12-byte input/RET12; receiver unused.
// Full current loads, unbounded copies, overlapping buffers, cached ANSI target and guarded FString lifetimes retained.
__declspec(naked) void __thiscall UR6GSServers::CDKeyDisconnecUser(FString authId)
{
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
    xor    edi,edi
    mov    DWORD PTR [ebp-0x4],edi
    lea    ecx,[ebp-0x1c]
    mov    BYTE PTR [ebp-0x4],0x1
    xor    ebx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    BYTE PTR [ebp-0x4],0x2
    lea    esp,[esp+0x0]
  Branch278:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch280
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    lea    esi,[edi+edi*2]
    lea    eax,[ebp+0x8]
    shl    esi,0x4
    push   eax
    lea    ecx,[esi+ecx*1+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch279
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    lea    eax,[esi+edx*1+0x18]
    push   eax
    lea    ecx,[ebp-0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    push   0x1
    push   edi
    mov    ecx,R6GameServiceAddresses::GServiceArray5
    call   R6GameServiceAddresses::RemoveStringRecordRange30
    mov    ebx,0x1
    jmp    Branch278
  Branch279:
    inc    edi
    jmp    Branch278
  Branch280:
    test   ebx,ebx
    je     Branch289
    mov    ecx,0x10091c28
    lea    edx,[ebp-0x120]
  Branch281:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch281
    mov    cx,WORD PTR ds:0x10091c04
    mov    WORD PTR [ebp-0x9e],cx
    lea    ecx,[ebp+0x8]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   edi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x74]
  Branch282:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch282
    xor    esi,esi
  Branch283:
    cmp    esi,0x28
    jae    R6GameServiceAddresses::ActivationFailureContinuation
    lea    edx,[ebp+esi*1-0x73]
    push   edx
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ebx,eax
    lea    eax,[ebp+esi*1-0x74]
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x38],cl
    add    esi,0x2
    jmp    Branch283
    mov    eax,ds:R6GameServiceAddresses::GBaseCDKeyContext
    lea    ecx,[ebp-0x38]
    push   ecx
    lea    edx,[ebp-0x120]
    push   edx
    push   eax
    call   R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   0x1f4
    push   ecx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    test   eax,eax
    jne    Branch284
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch284
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRSGSCDKeyEngineFAILED
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch284:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [ecx]
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    test   eax,eax
    jne    Branch288
    lea    ecx,[ebp-0x1c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x9c]
  Branch285:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch285
    xor    esi,esi
  Branch286:
    cmp    esi,0x28
    jae    R6GameServiceAddresses::AuthorizationFailureContinuation
    lea    edx,[ebp+esi*1-0x9b]
    push   edx
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ebx,eax
    lea    eax,[ebp+esi*1-0x9c]
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x4c],cl
    add    esi,0x2
    jmp    Branch286
    mov    eax,ds:R6GameServiceAddresses::GModCDKeyContext
    lea    ecx,[ebp-0x4c]
    push   ecx
    lea    edx,[ebp-0x120]
    push   edx
    push   eax
    call   R6GameServiceAddresses::thunk_ForwardValueDescriptorThroughContext
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GModCDKeyContext
    push   0x1f4
    push   ecx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    test   eax,eax
    jne    Branch287
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch289
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextModGSCDKeyEngineFAILED
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch287:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch289
    mov    edx,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [ebp-0x18]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [ebp-0x14]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCDKeyDisconnecUserModAuthIdS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch288:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch289
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [ebp+0xc]
    sub    esp,0xc
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [ebp+0x10]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextCDKeyDisconnecUserPucAuthIDS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch289:
    lea    ecx,[ebp-0x1c]
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

// Send the low-byte player status, then remove every matching pending RS ID only when that byte is zero.
// Exported nonvirtual void(FString,unsigned char,int); unused incoming ECX, owns 12-byte input, RET20.
// Endpoint EBP-d8 has 130 unbounded address bytes then WORD port; unbounded ID text at EBP-54 decodes 20 bytes
// at EBP-2c using fixed 40-character accesses, including retained stack bytes after short strings.
// Full selector zero chooses RS, nonzero chooses Mod; neither readiness flag gates. Send result ignored, no pump.
// Status 0/1/2 logs named labels; other byte values log the number. All forward the raw incoming FString triple.
// Native guard publication precedes copies; repeated matches keep the same index after range compaction.
// R6GameService.dll @ 1000fae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::NativeCDKeyPlayerStatusReply(FString authId,byte status,int selector)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReplySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xcc
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    mov    BYTE PTR [ebp-0x4],0x1
    mov    ecx,0x10091c28
    lea    edx,[ebp-0xd8]
    lea    ebx,[ebx+0x0]
  Branch290:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch290
    mov    ax,ds:0x10091c04
    lea    ecx,[ebp+0x8]
    mov    WORD PTR [ebp-0x56],ax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    mov    ecx,eax
    lea    edx,[ebp-0x54]
    lea    esp,[esp+0x0]
  Branch291:
    mov    al,BYTE PTR [ecx]
    inc    ecx
    mov    BYTE PTR [edx],al
    inc    edx
    test   al,al
    jne    Branch291
    xor    esi,esi
    lea    esp,[esp+0x0]
  Branch292:
    cmp    esi,0x28
    jae    Branch293
    lea    ecx,[ebp+esi*1-0x53]
    push   ecx
    call   R6GameServiceAddresses::HexDigitToValue
    lea    edx,[ebp+esi*1-0x54]
    add    esp,0x4
    push   edx
    mov    ebx,eax
    call   R6GameServiceAddresses::HexDigitToValue
    mov    ecx,eax
    mov    eax,esi
    cdq
    shl    cl,0x4
    sub    eax,edx
    add    cl,bl
    sar    eax,1
    add    esp,0x4
    mov    BYTE PTR [ebp+eax*1-0x2c],cl
    add    esi,0x2
    jmp    Branch292
  Branch293:
    mov    eax,DWORD PTR [ebp+0x18]
    test   eax,eax
    mov    bl,BYTE PTR [ebp+0x14]
    je     Branch294
    movzx  eax,bl
    push   eax
    mov    eax,ds:R6GameServiceAddresses::GModCDKeyContext
    lea    ecx,[ebp-0x2c]
    push   ecx
    lea    edx,[ebp-0xd8]
    push   edx
    push   eax
    jmp    Branch295
  Branch294:
    movzx  ecx,bl
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    lea    edx,[ebp-0x2c]
    push   edx
    lea    eax,[ebp-0xd8]
    push   eax
    push   ecx
  Branch295:
    call   R6GameServiceAddresses::thunk_ForwardCompoundDescriptorThroughContext
    test   bl,bl
    jne    Branch298
    xor    esi,esi
    lea    ebx,[ebx+0x0]
  Branch296:
    cmp    esi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5+0x4
    jge    Branch298
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray5
    lea    eax,[esi+esi*2]
    lea    edx,[ebp+0x8]
    shl    eax,0x4
    push   edx
    lea    ecx,[eax+ecx*1+0xc]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch297
    push   0x1
    push   esi
    mov    ecx,R6GameServiceAddresses::GServiceArray5
    call   R6GameServiceAddresses::RemoveStringRecordRange30
    jmp    Branch296
  Branch297:
    inc    esi
    jmp    Branch296
  Branch298:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch303
    movzx  ecx,bl
    mov    eax,ecx
    sub    esp,0xc
    sub    eax,0x0
    je     Branch301
    dec    eax
    je     Branch300
    dec    eax
    je     Branch299
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [edx+0x4],eax
    mov    eax,DWORD PTR [ebp+0x10]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusIForAuthIdS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x18
    jmp    Branch303
  Branch299:
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [ebp+0xc]
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [ebp+0x10]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERVALIDForAuthIdS
    push   eax
    jmp    Branch302
  Branch300:
    mov    edx,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [ebp+0x10]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERINVALIDForAuthIdS
    push   ecx
    jmp    Branch302
  Branch301:
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,DWORD PTR [ebp+0x10]
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERUNKNOWNForAuthIdS
    push   edx
  Branch302:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch303:
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
    ret    0x14
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

// Advance the selected controller CD-key request state and commit its ID, request number, mode and status.
// Exported nonvirtual void(gameInfo,level,playerController,int), RET16; pointer types recovered from export.
// RS state/ID/request/mode/status at +698/+69c/+6a8/+6ac/+6b0; Mod at +6b4/+6b8/+6c4/+6c8/+6cc.
// States 1/2/3/4 dispatch through the native table: submit, scan reply snapshot, report rejection, accept.
// Nonzero RS state first clears Mod state. Snapshot flag 1 is reply-ready; flag 2 handles retry/subnet fallback.
// By-value strings transfer to helper calls; saved argument slots identify partial-construction owners.
// Native scratch offsets, full-word status/mode, current callbacks/log targets and 17-state cleanup are retained.
// R6GameService.dll @ 1000fd30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessPC_CDKeyRequest(
    AR6AbstractGameInfo *gameInfo,ALevelInfo *level,APlayerController *controller,int selector)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessPC_CDKeyRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xb8
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x14],ecx
    xor    esi,esi
    lea    ecx,[ebp-0x58]
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],esi
    mov    DWORD PTR [ebp-0x40],esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    lea    ecx,[ebp-0x4c]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    DWORD PTR [ebp-0x3c],esi
    mov    DWORD PTR [ebp-0x38],esi
    mov    DWORD PTR [ebp-0x34],esi
    lea    ecx,[ebp-0x68]
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    mov    ebx,DWORD PTR [ebp+0x10]
    mov    BYTE PTR [ebp-0x4],0x5
    je     Branch304
    push   esi
    push   ebx
    call   R6GameServiceAddresses::LogCDKeyRequestDiagnostics
    add    esp,0x8
  Branch304:
    cmp    DWORD PTR [ebp+0x14],esi
    je     Branch305
    mov    eax,DWORD PTR [ebx+0x6b4]
    lea    ecx,[ebx+0x6b8]
    push   ecx
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x30],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    edx,DWORD PTR [ebx+0x6c4]
    mov    eax,DWORD PTR [ebx+0x6c8]
    mov    ecx,DWORD PTR [ebx+0x6cc]
    mov    DWORD PTR [ebp-0x20],edx
    mov    DWORD PTR [ebp-0x1c],eax
    mov    DWORD PTR [ebp-0x18],ecx
    jmp    Branch306
  Branch305:
    mov    edx,DWORD PTR [ebx+0x698]
    lea    eax,[ebx+0x69c]
    push   eax
    lea    ecx,[ebp-0x2c]
    mov    DWORD PTR [ebp-0x30],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    eax,DWORD PTR [ebx+0x6b0]
    mov    ecx,DWORD PTR [ebx+0x6a8]
    mov    edx,DWORD PTR [ebx+0x6ac]
    mov    DWORD PTR [ebp-0x18],eax
    cmp    DWORD PTR [ebp-0x30],esi
    mov    DWORD PTR [ebp-0x20],ecx
    mov    DWORD PTR [ebp-0x1c],edx
    je     Branch306
    mov    DWORD PTR [ebx+0x6b4],esi
  Branch306:
    mov    eax,DWORD PTR [ebp-0x30]
    dec    eax
    cmp    eax,0x3
    ja     Branch314
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GPCRequestDispatch]
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch307
    push   0x0
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   eax
    push   R6GameServiceAddresses::WideTextECDKEYFIRSTPASSForS
    push   edx
    call   edi
    add    esp,0xc
    jmp    Branch308
  Branch307:
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
  Branch308:
    mov    eax,DWORD PTR [ebx+0x5b4]
    push   eax
    call   R6GameServiceAddresses::CastToUNetConnection
    add    esp,0x4
    test   eax,eax
    jne    Branch309
    push   ebx
    lea    ecx,[ebp-0xa0]
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x14]
    call   R6GameServiceAddresses::UR6GSServers_eventGetConsoleStoreIP
    push   eax
    lea    ecx,[ebp-0x58]
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0xa0]
    jmp    Branch310
  Branch309:
    lea    edx,[ebp-0xc4]
    push   edx
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_GetPlayerNetworkAddressSlot
    push   eax
    lea    ecx,[ebp-0x58]
    mov    BYTE PTR [ebp-0x4],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0xc4]
  Branch310:
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   0x0
    push   R6GameServiceAddresses::WideTextPunctuation5
    lea    ecx,[ebp-0x58]
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FString_InStrSlot
    push   eax
    lea    eax,[ebp-0x88]
    push   eax
    lea    ecx,[ebp-0x58]
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FString_LeftSlot
    lea    esi,[ebx+0x7cc]
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0x88]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch311
    mov    edx,DWORD PTR [ebp-0x2c]
    mov    eax,DWORD PTR [ebp-0x28]
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [ebp-0x24]
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMSzAuthorizationIDS
    push   ecx
    call   edi
    add    esp,0x8
    mov    edx,esi
    mov    ecx,DWORD PTR [edx]
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [edx+0x4]
    mov    edx,DWORD PTR [edx+0x8]
    mov    DWORD PTR [eax+0x4],ecx
    mov    DWORD PTR [eax+0x8],edx
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextAPlayerControllerMSzIpAddrS
    push   ecx
    call   edi
    add    esp,0x14
  Branch311:
    mov    edx,DWORD PTR [ebp+0x14]
    push   edx
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x10],esp
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    lea    eax,[ebp-0x2c]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   eax
    mov    BYTE PTR [ebp-0x4],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    esi,DWORD PTR [ebp-0x14]
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x5
    call   R6GameServiceAddresses::UR6GSServers_PlayerIsInIDList
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    je     Branch316
    test   eax,eax
    je     Branch312
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerIsInIDList
    push   edx
    call   edi
    add    esp,0x8
  Branch312:
    mov    eax,DWORD PTR [ebp+0x14]
    test   eax,eax
    jne    Branch313
    sub    esp,0xc
    lea    eax,[ebx+0x69c]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x10],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    lea    ecx,[ebp-0xb8]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_GetGlobalIdFromPlayerIDList
    push   eax
    lea    ecx,[ebx+0x7c0]
    mov    BYTE PTR [ebp-0x4],0xa
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0xb8]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch313:
    mov    DWORD PTR [ebp-0x30],0x4
  Branch314:
    mov    eax,DWORD PTR [ebp+0x14]
    test   eax,eax
    je     Branch340
  Branch315:
    mov    eax,DWORD PTR [ebp-0x30]
    lea    ecx,[ebp-0x2c]
    push   ecx
    lea    ecx,[ebx+0x6b8]
    mov    DWORD PTR [ebx+0x6b4],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    edx,DWORD PTR [ebp-0x20]
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [ebx+0x6c4],edx
    mov    DWORD PTR [ebx+0x6c8],eax
    mov    DWORD PTR [ebx+0x6cc],ecx
    jmp    Branch341
  Branch316:
    test   eax,eax
    je     Branch317
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSCDKeyValidateUser
    push   eax
    call   edi
    add    esp,0x8
  Branch317:
    mov    ecx,DWORD PTR [ebp+0x14]
    mov    edx,DWORD PTR [ebp-0x1c]
    push   ecx
    push   edx
    sub    esp,0xc
    lea    eax,[ebp-0x2c]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x10],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_CDKeyValidateUser
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    mov    DWORD PTR [ebp-0x20],eax
    je     Branch318
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMICDKeyReqIDD
    push   edx
    call   edi
    add    esp,0xc
  Branch318:
    mov    DWORD PTR [ebp-0x30],0x2
    jmp    Branch314
    mov    eax,DWORD PTR [ebp+0x14]
    test   eax,eax
    je     Branch319
    mov    eax,DWORD PTR [ebp-0x14]
    add    eax,0x74
    push   eax
    jmp    Branch320
  Branch319:
    mov    ecx,DWORD PTR [ebp-0x14]
    add    ecx,0x68
    push   ecx
  Branch320:
    lea    ecx,[ebp-0x3c]
    call   R6GameServiceAddresses::CopySevenWordRecordArray
    mov    DWORD PTR [ebp+0x10],0x0
  Branch321:
    mov    esi,DWORD PTR [ebp-0x38]
    cmp    DWORD PTR [ebp+0x10],esi
    jge    Branch332
    mov    eax,DWORD PTR [ebp-0x40]
    test   eax,eax
    jne    Branch332
    mov    esi,DWORD PTR [ebp+0x10]
    mov    eax,DWORD PTR [ebp-0x3c]
    imul   esi,esi,0x1c
    mov    edx,DWORD PTR [ebp-0x20]
    cmp    edx,DWORD PTR [esi+eax*1]
    jne    Branch327
    mov    eax,DWORD PTR [esi+eax*1+0x8]
    mov    ecx,0x1
    test   cl,al
    mov    DWORD PTR [ebp-0x40],ecx
    je     Branch328
    mov    eax,DWORD PTR [ebp+0x14]
    test   eax,eax
    jne    Branch323
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot
    mov    ecx,DWORD PTR [ebp-0x3c]
    lea    edx,[esi+ecx*1+0xc]
    push   edx
    lea    ecx,[ebp-0x94]
    push   ecx
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_GlobalIDToStringSlot
    lea    edi,[ebx+0x7c0]
    push   eax
    mov    ecx,edi
    mov    BYTE PTR [ebp-0x4],0xb
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0x94]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    edx,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [ebp-0x14]
    push   edi
    push   edx
    call   R6GameServiceAddresses::UR6GSServers_eventIsGlobalIDBanned
    test   eax,eax
    je     Branch322
    mov    eax,DWORD PTR [ebp-0x3c]
    mov    BYTE PTR [esi+eax*1+0x4],0x3
    jmp    Branch323
  Branch322:
    push   ebx
    lea    ecx,[ebp-0xac]
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x14]
    call   R6GameServiceAddresses::UR6GSServers_eventTempGetPBConnectStatus
    push   eax
    lea    ecx,[ebp-0x68]
    mov    BYTE PTR [ebp-0x4],0xc
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0xac]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    push   R6GameServiceAddresses::GEmptyWideText
    lea    ecx,[ebp-0x68]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__9FStringSlot
    test   eax,eax
    je     Branch323
    mov    edx,DWORD PTR [ebp-0x3c]
    lea    eax,[ebp-0x68]
    push   eax
    mov    ecx,ebx
    mov    BYTE PTR [esi+edx*1+0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_eventClientPBKickedOutMessageSlot
  Branch323:
    mov    eax,DWORD PTR [ebp-0x3c]
    movzx  ecx,BYTE PTR [esi+eax*1+0x4]
    mov    DWORD PTR [ebp-0x18],ecx
    mov    cl,BYTE PTR [esi+eax*1+0x4]
    cmp    cl,0x1
    je     Branch325
    mov    al,cl
    test   al,al
    je     Branch325
    cmp    al,0x3
    je     Branch325
    cmp    al,0x4
    je     Branch325
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch324
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE2
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch324:
    mov    eax,DWORD PTR [ebp+0x10]
    inc    eax
    mov    DWORD PTR [ebp-0x30],0x4
    mov    DWORD PTR [ebp+0x10],eax
    jmp    Branch321
  Branch325:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch326
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch326:
    mov    DWORD PTR [ebp-0x30],0x3
  Branch327:
    inc    DWORD PTR [ebp+0x10]
    jmp    Branch321
  Branch328:
    shr    eax,1
    xor    edi,edi
    and    eax,ecx
    je     Branch330
    cmp    DWORD PTR [ebp-0x1c],edi
    je     Branch330
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,edi
    je     Branch329
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextTIMEOUTSecondAttempt
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch329:
    sub    esp,0xc
    lea    edx,[ebx+0x7cc]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x78],esp
    push   edx
    mov    DWORD PTR [ebp-0x1c],edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    esi,DWORD PTR [ebp-0x14]
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_OnSameSubNet
    cmp    eax,edi
    jne    Branch324
    mov    eax,DWORD PTR [ebx+0x5b4]
    push   eax
    call   R6GameServiceAddresses::CastToUViewport
    add    esp,0x4
    test   eax,eax
    jne    Branch324
    push   R6GameServiceAddresses::WideTextServerAuthNotResponding
    lea    ecx,[ebp-0x74]
    mov    DWORD PTR [ebp-0x30],edi
    mov    DWORD PTR [ebp-0x18],edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    lea    ecx,[ebp-0x74]
    push   ecx
    push   ebx
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0xd
    call   R6GameServiceAddresses::UR6GSServers_eventProcessServerMsg
    lea    ecx,[ebp-0x74]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    inc    DWORD PTR [ebp+0x10]
    jmp    Branch321
  Branch330:
    cmp    eax,edi
    je     Branch326
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,edi
    je     Branch331
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSETIMEOUTFirstAttempt
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    mov    ecx,0x1
  Branch331:
    mov    eax,DWORD PTR [ebp+0x10]
    inc    eax
    mov    DWORD PTR [ebp-0x30],ecx
    mov    DWORD PTR [ebp-0x1c],ecx
    mov    DWORD PTR [ebp+0x10],eax
    jmp    Branch321
  Branch332:
    test   esi,esi
    jge    Branch333
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   edi
    mov    eax,DWORD PTR [ebp-0x38]
    add    esp,0xc
    cmp    esi,eax
    jle    Branch333
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   edi
    add    esp,0xc
  Branch333:
    xor    eax,eax
    jmp    Branch334
    lea    ecx,[ecx+0x0]
  Branch334:
    cmp    eax,esi
    jge    Branch335
    inc    eax
    jmp    Branch334
  Branch335:
    push   0x1c
    push   esi
    push   0x0
    lea    ecx,[ebp-0x3c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    jmp    Branch314
    push   R6GameServiceAddresses::GEmptyWideText
    lea    ecx,[ebp-0x4c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    mov    eax,DWORD PTR [ebp-0x18]
    cmp    eax,0x3
    jne    Branch336
    push   R6GameServiceAddresses::WideTextBannedIP
    jmp    Branch337
  Branch336:
    cmp    eax,0x4
    je     Branch338
    push   R6GameServiceAddresses::WideTextCDKeyServerRefused
  Branch337:
    lea    ecx,[ebp-0x4c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
  Branch338:
    lea    ecx,[ebp-0x4c]
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ebx
    call   R6GameServiceAddresses::UR6GSServers_eventProcessServerMsg
    mov    DWORD PTR [ebp-0x30],0x0
    mov    DWORD PTR [ebp-0x18],0x1
    jmp    Branch314
    mov    esi,DWORD PTR [ebp+0x14]
    push   esi
    sub    esp,0xc
    lea    edx,[ebx+0x7c0]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x14],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    lea    eax,[ebx+0x7cc]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x10],esp
    push   eax
    mov    BYTE PTR [ebp-0x4],0xe
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    sub    esp,0xc
    lea    edx,[ebp-0x2c]
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   edx
    mov    BYTE PTR [ebp-0x4],0xf
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    BYTE PTR [ebp-0x4],0x5
    call   R6GameServiceAddresses::UR6GSServers_AddPlayerToIDList
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch339
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessPCCDKeyRequestECDKEYVALIDMECDKeyStatusECDKEYSTPLAYERVALID
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch339:
    test   esi,esi
    mov    DWORD PTR [ebp-0x30],0x0
    mov    DWORD PTR [ebp-0x18],0x2
    jne    Branch315
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [edx]
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventIsRavenShieldSlot
    test   eax,eax
    jne    Branch340
    mov    DWORD PTR [ebx+0x6b4],0x1
  Branch340:
    mov    edx,DWORD PTR [ebp-0x30]
    lea    eax,[ebp-0x2c]
    push   eax
    lea    ecx,[ebx+0x69c]
    mov    DWORD PTR [ebx+0x698],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    ecx,DWORD PTR [ebp-0x20]
    mov    edx,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [ebp-0x18]
    mov    DWORD PTR [ebx+0x6a8],ecx
    mov    DWORD PTR [ebx+0x6ac],edx
    mov    DWORD PTR [ebx+0x6b0],eax
  Branch341:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch342
    push   0x1
    push   ebx
    call   R6GameServiceAddresses::LogCDKeyRequestDiagnostics
    add    esp,0x8
  Branch342:
    lea    ecx,[ebp-0x68]
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],0x3
    call   R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp-0x4c]
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    lea    ecx,[ebp-0x58]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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

// Reconcile live RS/Mod queued auth IDs against the controller chain, reply, then remove the observed queue ranges.
// Exported nonvirtual void(AController*), ECX receiver saved for child calls, RET4; field roles inferred.
// Fresh signed counts/data at 9347c/93480 and 93458/9345c; links at+3dc, class/super at+24/+2c.
// RS repeats its ancestry check through imported IsA; Mod repeats it inline. A rejected repeat leaves a
// NULL candidate and still forms ID+69c/+6b8. No extra NULL check, cycle guard or snapshot is invented.
// First match transfers a fresh controller ID/status byte; absent match transfers queued ID/unknown 0.
// A matched node still loads next before the found test. Counts, queue data and class imports remain live.
// This frame owns no completed string; native child owns the transferred 12-byte argument and its cleanup.
// R6GameService.dll @ 10010590 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessAuthIdRequest(AController *controllerChainHead)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_ProcessAuthIdRequestSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x18],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    xor    esi,esi
  Branch343:
    mov    eax,ds:R6GameServiceAddresses::GServiceString7+0x4
    cmp    esi,eax
    mov    DWORD PTR [ebp-0x1c],esi
    jge    Branch354
    mov    ebx,DWORD PTR [ebp+0x8]
    xor    eax,eax
    mov    DWORD PTR [ebp-0x14],eax
    jmp    Branch344
    lea    ecx,[ecx+0x0]
  Branch344:
    test   ebx,ebx
    je     Branch352
    test   eax,eax
    jne    Branch353
    mov    eax,DWORD PTR [ebx+0x24]
  Branch345:
    test   eax,eax
    je     Branch346
    cmp    eax,ecx
    je     Branch347
    mov    eax,DWORD PTR [eax+0x2c]
    jmp    Branch345
  Branch346:
    xor    eax,eax
    test   ecx,ecx
    sete   al
    test   eax,eax
    je     Branch351
  Branch347:
    test   ebx,ebx
    je     Branch348
    push   ecx
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_IsASlot
    test   eax,eax
    je     Branch348
    mov    edi,ebx
    jmp    Branch349
  Branch348:
    xor    edi,edi
  Branch349:
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString7
    lea    eax,[eax+eax*2]
    lea    edx,[ecx+eax*4]
    lea    esi,[edi+0x69c]
    push   edx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch350
    xor    eax,eax
    mov    al,BYTE PTR [edi+0x6b0]
    push   0x0
    push   eax
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x14],esp
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0x18]
    call   R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReply
    mov    DWORD PTR [ebp-0x14],0x1
  Branch350:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch351:
    mov    ebx,DWORD PTR [ebx+0x3dc]
    mov    esi,DWORD PTR [ebp-0x1c]
    mov    eax,DWORD PTR [ebp-0x14]
    jmp    Branch344
  Branch352:
    test   eax,eax
    jne    Branch353
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString7
    push   eax
    push   eax
    sub    esp,0xc
    lea    ecx,[esi+esi*2]
    lea    eax,[edx+ecx*4]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0x18]
    call   R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReply
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch353:
    inc    esi
    jmp    Branch343
  Branch354:
    push   eax
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceString7
    call   R6GameServiceAddresses::RemoveFStringRange12
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
    xor    esi,esi
  Branch355:
    mov    eax,ds:R6GameServiceAddresses::GServiceString6+0x4
    cmp    esi,eax
    mov    DWORD PTR [ebp-0x1c],esi
    jge    Branch369
    mov    ebx,DWORD PTR [ebp+0x8]
    xor    eax,eax
    mov    DWORD PTR [ebp-0x14],eax
  Branch356:
    test   ebx,ebx
    je     Branch367
    test   eax,eax
    jne    Branch368
    mov    eax,DWORD PTR [ebx+0x24]
    lea    esp,[esp+0x0]
  Branch357:
    test   eax,eax
    je     Branch358
    cmp    eax,ecx
    je     Branch359
    mov    eax,DWORD PTR [eax+0x2c]
    jmp    Branch357
  Branch358:
    xor    eax,eax
    test   ecx,ecx
    sete   al
    test   eax,eax
    je     Branch366
  Branch359:
    test   ebx,ebx
    je     Branch363
    mov    eax,DWORD PTR [ebx+0x24]
    nop
  Branch360:
    test   eax,eax
    je     Branch361
    cmp    eax,ecx
    je     Branch362
    mov    eax,DWORD PTR [eax+0x2c]
    jmp    Branch360
  Branch361:
    xor    eax,eax
    test   ecx,ecx
    sete   al
    test   eax,eax
    je     Branch363
  Branch362:
    mov    edi,ebx
    jmp    Branch364
  Branch363:
    xor    edi,edi
  Branch364:
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString6
    lea    ecx,[eax+eax*2]
    lea    eax,[edx+ecx*4]
    lea    esi,[edi+0x6b8]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__8FStringSlot
    test   eax,eax
    je     Branch365
    xor    ecx,ecx
    mov    cl,BYTE PTR [edi+0x6cc]
    push   0x1
    push   ecx
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x14],esp
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0x18]
    call   R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReply
    mov    DWORD PTR [ebp-0x14],0x1
  Branch365:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch366:
    mov    ebx,DWORD PTR [ebx+0x3dc]
    mov    eax,DWORD PTR [ebp-0x14]
    mov    esi,DWORD PTR [ebp-0x1c]
    jmp    Branch356
  Branch367:
    test   eax,eax
    jne    Branch368
    push   0x1
    push   eax
    mov    eax,ds:R6GameServiceAddresses::GServiceString6
    sub    esp,0xc
    lea    edx,[esi+esi*2]
    lea    edx,[eax+edx*4]
    mov    ecx,esp
    mov    DWORD PTR [ebp-0x1c],esp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,DWORD PTR [ebp-0x18]
    call   R6GameServiceAddresses::UR6GSServers_NativeCDKeyPlayerStatusReply
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_APlayerController_PrivateStaticClassSlot
  Branch368:
    inc    esi
    jmp    Branch355
  Branch369:
    push   eax
    push   0x0
    mov    ecx,R6GameServiceAddresses::GServiceString6
    call   R6GameServiceAddresses::RemoveFStringRange12
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
// Two null-initialized output slots have no unwind cleanup action, so post failure does not delete the message.
// Current logging gate, receiver and Logf IAT are read only after the delete helper returns.
// R6GameService.dll @ 100109c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::GSClientPostMessage(byte selector)
{
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
    ja     Branch372
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GPostMessageDispatch]
    lea    eax,[ebp-0x14]
    push   eax
    push   0x1
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ecx
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    edx,DWORD PTR [ebp-0x14]
    push   edx
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSGFGCHSTAINITMASTERSESSIONAK
    push   ecx
    jmp    Branch371
    lea    edx,[ebp-0x14]
    push   edx
    push   0x2
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ecx
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    push   R6GameServiceAddresses::WideTextMSGFGCHSTAMASTERSESSIONAK
  Branch370:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   eax
  Branch371:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch372:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x4
    lea    ecx,[ebp-0x18]
    push   ecx
    push   0x200
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    edx,DWORD PTR [ebp-0x18]
    mov    eax,ds:0x10091bf4
    mov    DWORD PTR [edx+0x8],eax
    mov    ecx,DWORD PTR [ebp-0x18]
    push   ecx
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    edx,DWORD PTR [ebp-0x18]
    push   edx
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSGFGREADYTORECEIVECONNECTIONS
    push   ecx
    jmp    Branch371
    lea    edx,[ebp-0x14]
    push   edx
    push   0x3
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ecx
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    push   R6GameServiceAddresses::WideTextMSGFGCHSTAINITCLIENTSESSIONAK
    jmp    Branch370
    lea    ecx,[ebp-0x14]
    push   ecx
    push   0x4
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    edx,DWORD PTR [ebp-0x14]
    push   edx
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    eax,DWORD PTR [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextMSGFGCHSTACLIENTSESSIONAK
    push   edx
    jmp    Branch371
    lea    eax,[ebp-0x14]
    push   eax
    push   0x100
    call   R6GameServiceAddresses::AllocateLoadedGSClientMessage
    mov    ecx,DWORD PTR [ebp-0x14]
    push   ecx
    call   R6GameServiceAddresses::PostLoadedGSClientMessage
    mov    edx,DWORD PTR [ebp-0x14]
    push   edx
    call   R6GameServiceAddresses::DeleteLoadedGSClientMessage
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,esi
    je     Branch372
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSGFGSWITCHTOGS
    push   ecx
    jmp    Branch371
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
// R6GameService.dll @ 10011070 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::SetGSClientComInterface(void)
{
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
    je     Branch377
    mov    eax,0x1
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch377:
    lea    eax,[ebp-0x14]
    push   eax
    push   0x0
    mov    esi,0x1
    push   0x10073074
    mov    DWORD PTR ds:0x100939d8,esi
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_GetActiveObjectSlot
    test   eax,eax
    jge    Branch378
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextCannotFindTheScoreSubmissionServiceHResX
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
    xor    esi,esi
  Branch378:
    mov    eax,DWORD PTR [ebp-0x14]
    test   eax,eax
    je     Branch379
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::GGSClientInterface
    push   0x10072ff8
    push   eax
    call   DWORD PTR [ecx]
    test   eax,eax
    jge    Branch379
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextCannotFindTheScoreSubmissionService
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    xor    esi,esi
  Branch379:
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
// R6GameService.dll @ 10011820 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::GSClientUpdateServerInfo(void)
{
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
    cmp    eax,ebx
    jge    Branch380
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch380
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextCannotFindTheGameConfigService
    push   edx
    call   edi
    add    esp,0x8
    jmp    Branch381
  Branch380:
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
  Branch381:
    mov    ecx,DWORD PTR [ebp-0x18]
    cmp    ecx,ebx
    je     Branch383
    mov    eax,DWORD PTR [ecx]
    lea    edx,[ebp-0x14]
    push   edx
    push   0x10073bf0
    push   ecx
    call   DWORD PTR [eax]
    cmp    eax,ebx
    jge    Branch382
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch382
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextCannotFindTheInterfaceForGameConfigService
    push   ecx
    call   edi
    add    esp,0x8
  Branch382:
    mov    ecx,DWORD PTR [ebp-0x18]
  Branch383:
    mov    eax,DWORD PTR [ebp-0x14]
    cmp    eax,ebx
    je     Branch388
    mov    edx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [edx+0x4]
    lea    eax,[ebp-0x30]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_VariantInitSlot
    push   0x1
    lea    ecx,[ebp-0x30]
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    call   R6GameServiceAddresses::CopyStoredBytesToVariant
    cmp    eax,ebx
    jge    Branch384
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch384
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGetCopyPublicError
    push   eax
    call   edi
    add    esp,0x8
  Branch384:
    mov    eax,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x30]
    push   edx
    push   eax
    call   DWORD PTR [ecx+0x1c]
    cmp    eax,ebx
    jge    Branch385
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch385
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetPublicGameConfigError
    push   ecx
    call   edi
    add    esp,0x8
  Branch385:
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_VariantClearSlot
    lea    edx,[ebp-0x30]
    push   edx
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push   0x1
    lea    eax,[ebp-0x30]
    push   eax
    call   R6GameServiceAddresses::CopyStoredBytesToVariant
    cmp    eax,ebx
    jge    Branch386
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch386
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGetCopyPrivateError
    push   edx
    call   edi
    add    esp,0x8
  Branch386:
    mov    eax,DWORD PTR [ebp-0x14]
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x30]
    push   edx
    push   eax
    call   DWORD PTR [ecx+0x24]
    cmp    eax,ebx
    jge    Branch387
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch387
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetPrivateGameConfigError
    push   ecx
    call   edi
    add    esp,0x8
  Branch387:
    lea    edx,[ebp-0x30]
    push   edx
    call   esi
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    eax,DWORD PTR [ebp-0x14]
  Branch388:
    cmp    eax,ebx
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch389
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x8]
    mov    ecx,DWORD PTR [ebp-0x18]
  Branch389:
    cmp    ecx,ebx
    mov    BYTE PTR [ebp-0x4],bl
    je     Branch390
    mov    edx,DWORD PTR [ecx]
    push   ecx
    call   DWORD PTR [edx+0x8]
  Branch390:
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
// R6GameService.dll data @ 1007ddb8 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_GSClientUpdateServerInfoTryMap[1] = {
  {0x0, 0x2, 0x3, 0x2, R6GameServiceAddresses::GServerInfoHandlers},
};

// Native server-info info record; addresses and states are literal.
// R6GameService.dll data @ 1007dd98 : native storage identity retained.
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
// R6GameService.dll @ 10011ec0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::InitGSClient(void)
{
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
    xor    ecx,ecx
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    setge  cl
    test   eax,eax
    mov    esi,ecx
    je     Branch391
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   R6GameServiceAddresses::WideTextGSClientSPWGSCInitializeI
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch391:
    test   esi,esi
    je     Branch392
    push   0x0
    lea    ecx,[ebp-0x24]
    push   ecx
    mov    DWORD PTR [ebp-0x24],0xc
    mov    DWORD PTR [ebp-0x20],R6GameServiceAddresses::DispatcherProc
    mov    DWORD PTR [ebp-0x1c],0x0
    call   R6GameServiceAddresses::ConnectLoadedGSClient
    xor    edx,edx
    test   eax,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    setge  dl
    test   eax,eax
    mov    esi,edx
    je     Branch392
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   esi
    push   R6GameServiceAddresses::WideTextGSClientSPWGSCConnectI
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch392:
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

// Close the flagged lobby and uninitialize registration, clearing flags only after optional diagnostics.
// Exported nonvirtual void(void), unused incoming ECX, RET0; no local exception guard or rollback.
// Initial full registration word alone gates work. Logf is cached before close/uninitialize; gates and
// receivers reload, but the final logout log is unconditional after both flag stores.
// Its GLog import is captured before those stores and its device is dereferenced afterward.
// R6GameService.dll @ 10011fd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::UnInitRegServer(void)
{
  __asm {
    mov    eax,ds:0x10093b08
    test   eax,eax
    je     Branch395
    mov    eax,ds:0x100939ec
    test   eax,eax
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch393
    call   R6GameServiceAddresses::CloseLobbyServerConnection
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch393
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextREGSERVERRegServerSendLobbyServerCloseFromUR6GSServersUnInitRegServer
    push   ecx
    call   esi
    add    esp,0x8
  Branch393:
    call   R6GameServiceAddresses::UninitializeRegistrationService
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch394
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextREGSERVERRegServerLibraryUninitialize
    push   eax
    call   esi
    add    esp,0x8
  Branch394:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR ds:0x100939ec,0x0
    mov    DWORD PTR ds:0x10093b08,0x0
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextLoggedOffFromUbiComRegServerService
    push   edx
    call   esi
    add    esp,0x8
    pop    esi
  Branch395:
    ret
  }
}

// Clear lobby/group IDs, perform registration shutdown, then clear the remaining global only on return.
// Exported nonvirtual void(void), unused incoming ECX, RET0. The guard is linked before the ID stores.
// R6GameService.dll @ 10012060 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::LogOutServer(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_LogOutServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    push   ebx
    push   esi
    xor    esi,esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecondaryLobbyServerId,esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GSecondaryGroupId,esi
    call   R6GameServiceAddresses::UR6GSServers_UnInitRegServer
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    DWORD PTR ds:0x10091bd8,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
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
// R6GameService.dll data @ 1007dea4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_LogOutServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GLogOutServerHandlers},
};

// Native logout info record; addresses and states are literal.
// R6GameService.dll data @ 1007de94 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6GSServers_LogOutServerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6GSServers_LogOutServerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6GSServers_LogOutServerTryMap,
  0x0,
  0x0,
};

// Evaluate the replication-info argument, clear its IDs, then perform the complete native logout path.
// Exported exec void(FFrame&,void*), RET8, result pointer unused. Saved service receiver survives dispatch.
// Operand byte indexes current GNatives; after it returns, Code advances then optionally consumes 42h.
// Current local pointer is reread for +3c8/+3cc stores, with no NULL check; both precede LogOutServer.
// R6GameService.dll @ 100120e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeLogOutServer(FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeLogOutServerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [esi+0xc]
    push   edi
    xor    edi,edi
    mov    DWORD PTR [ebp-0x14],edi
    movzx  edx,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [ebp-0x10],esp
    lea    eax,[ebp-0x14]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    mov    ebx,ecx
    mov    ecx,DWORD PTR [esi+0x8]
    push   esi
    mov    DWORD PTR [ebp-0x4],edi
    call   DWORD PTR [eax+edx*4]
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne    Branch396
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   edi
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch396:
    mov    eax,DWORD PTR [ebp-0x14]
    mov    DWORD PTR [eax+0x3c8],edi
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    DWORD PTR [ecx+0x3cc],edi
    mov    ecx,ebx
    call   R6GameServiceAddresses::UR6GSServers_LogOutServer
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
// R6GameService.dll data @ 1007df04 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeLogOutServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeLogOutServerHandlers},
};

// Native logout info record; addresses and states are literal.
// R6GameService.dll data @ 1007def4 : native storage identity retained.
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
// R6GameService.dll @ 100121b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RegisterServer(void)
{
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    test   BYTE PTR [esi+0xc4],0x1
    mov    BYTE PTR [ebp-0x4],0x1
    lea    ecx,[ebp-0x40]
    je     Branch397
    lea    eax,[esi+0x15c]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    jmp    Branch398
  Branch397:
    push   R6GameServiceAddresses::GEmptyWideText
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
  Branch398:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push   0x1
    call   R6GameServiceAddresses::GetStoredBytesLength
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push   0x1
    mov    DWORD PTR [ebp-0x24],eax
    call   R6GameServiceAddresses::GetStoredBytesPointer
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push   0x1
    mov    DWORD PTR [ebp-0x28],eax
    call   R6GameServiceAddresses::GetStoredBytesLength
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push   0x1
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::GetStoredBytesPointer
    mov    DWORD PTR [ebp-0x20],eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray10+0x4
    test   eax,eax
    jle    Branch399
    lea    ecx,[esi+0x1ac]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   ebx
    add    esp,0x4
    lea    ecx,[esi+0x168]
    mov    DWORD PTR [ebp-0x18],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   ebx
    add    esp,0x4
    lea    ecx,[ebp-0x40]
    mov    DWORD PTR [ebp-0x1c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   ebx
    add    esp,0x4
    mov    ecx,R6GameServiceAddresses::GServiceString1
    mov    DWORD PTR [ebp-0x2c],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   ebx
    add    esp,0x4
    lea    ecx,[esi+0xe8]
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   ebx
    mov    ecx,DWORD PTR [esi+0xc4]
    mov    edx,DWORD PTR [ebp-0x18]
    add    esp,0x4
    mov    ebx,DWORD PTR [ebp-0x24]
    shr    ecx,1
    and    ecx,0xffffff01
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   0x1
    push   edx
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x14]
    xor    edx,edx
    mov    dx,WORD PTR ds:0x10091bf4
    push   edx
    mov    edx,DWORD PTR [ebp-0x20]
    push   0x0
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x28]
    push   edx
    mov    edx,DWORD PTR [ebp-0x2c]
    push   ebx
    push   ecx
    mov    ecx,DWORD PTR [esi+0x100]
    push   edx
    push   0x0
    push   ecx
    push   0x6
    push   edi
    push   eax
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::RegisterServerOnLobby
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch399
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ebx
    push   R6GameServiceAddresses::WideTextRegServerSendRegisterServerOnLobbyI
    push   eax
    call   esi
    mov    ecx,DWORD PTR [ebp-0x14]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    add    esp,0xc
    push   ecx
    push   R6GameServiceAddresses::WideTextRegServerSendRegisterServerOnLobbyI
    push   eax
    call   esi
    add    esp,0xc
  Branch399:
    lea    ecx,[ebp-0x40]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll data @ 1007df6c : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RegisterServerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GRegisterServerHandlers},
};

// Native registration info record; addresses and states are literal.
// R6GameService.dll data @ 1007df54 : native storage identity retained.
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
// R6GameService.dll @ 100123b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::UpdateServer(void)
{
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    test   BYTE PTR [esi+0xc4],0x1
    mov    BYTE PTR [ebp-0x4],0x1
    lea    ecx,[ebp-0x2c]
    je     Branch400
    lea    eax,[esi+0x15c]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    jmp    Branch401
  Branch400:
    push   R6GameServiceAddresses::GEmptyWideText
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
  Branch401:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push   0x1
    call   R6GameServiceAddresses::GetStoredBytesPointer
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push   0x1
    mov    DWORD PTR [ebp-0x18],eax
    call   R6GameServiceAddresses::GetStoredBytesLength
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push   0x1
    mov    ebx,eax
    call   R6GameServiceAddresses::GetStoredBytesPointer
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push   0x1
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::GetStoredBytesLength
    lea    ecx,[ebp-0x2c]
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    edx,DWORD PTR [ebp-0x14]
    add    esp,0x4
    xor    ecx,ecx
    mov    cx,WORD PTR ds:0x10091bf4
    push   ecx
    mov    ecx,DWORD PTR [ebp-0x18]
    push   0x0
    push   0x0
    push   edi
    push   edx
    mov    edx,DWORD PTR [esi+0x100]
    push   ebx
    push   ecx
    mov    ecx,DWORD PTR ds:0x10093b1c
    push   eax
    mov    eax,DWORD PTR [esi+0xc4]
    push   0x0
    push   edx
    shr    eax,1
    and    eax,0xffffff01
    push   eax
    push   0x1
    push   0x1
    push   ecx
    call   R6GameServiceAddresses::SendOptionalFieldsThroughSecondaryService
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch402
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ebx
    push   R6GameServiceAddresses::WideTextRegServerSendUpdateGroupSettingsI
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    add    esp,0xc
    push   edi
    push   R6GameServiceAddresses::WideTextRegServerSendUpdateGroupSettingsI
    push   edx
    call   esi
    add    esp,0xc
  Branch402:
    lea    ecx,[ebp-0x2c]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll data @ 1007dfd4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_UpdateServerTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GUpdateServerHandlers},
};

// Native update info record; addresses and states are literal.
// R6GameService.dll data @ 1007dfbc : native storage identity retained.
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
// R6GameService.dll @ 10012530 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeUpdateServer(FFrame *frame,void *result)
{
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
    jne    Branch403
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch403:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR ds:0x1008c290,0x1
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
// R6GameService.dll data @ 1007e034 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_execNativeUpdateServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GexecNativeUpdateServerHandlers},
};

// Native deferred-update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e024 : native storage identity retained.
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
// R6GameService.dll @ 10012620 : complete native control/access order and raw ABI retained.
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
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch404
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRegServerSendLobbyServerConnection
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch404:
    mov    ecx,R6GameServiceAddresses::GServiceString13
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    ecx,DWORD PTR ds:0x10093b1c
    add    esp,0x4
    push   ecx
    push   eax
    call   R6GameServiceAddresses::SendLobbyServerLogin
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch405
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRegServerSendLobbyServerLogin
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch405:
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
// R6GameService.dll data @ 1007e094 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ServerLoginTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GServerLoginHandlers},
};

// Native server-login info record; addresses and states are literal.
// R6GameService.dll data @ 1007e084 : native storage identity retained.
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
// R6GameService.dll @ 10012710 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::RegServerRouterLogin(void)
{
  __asm {
    push   esi
    lea    esi,[ecx+0x1dc]
    push   edi
    mov    ecx,R6GameServiceAddresses::GServiceString2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push   eax
    call   edi
    add    esp,0x4
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    add    esp,0x4
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString13
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::SendRouterLogin
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch406
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextRegServerSendLoginRouter
    push   ecx
    call   edi
    mov    eax,ds:R6GameServiceAddresses::GServiceString13
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString13+0x4
    mov    edx,esp
    mov    DWORD PTR [edx],eax
    mov    eax,ds:R6GameServiceAddresses::GServiceString13+0x8
    mov    DWORD PTR [edx+0x4],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [edx+0x8],eax
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextS
    push   edx
    call   edi
    mov    ecx,DWORD PTR [esi]
    mov    edx,DWORD PTR [esi+0x4]
    add    esp,0x8
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [esi+0x8]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextS
    push   eax
    call   edi
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString2
    mov    eax,ds:R6GameServiceAddresses::GServiceString2+0x4
    add    esp,0x8
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString2+0x8
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextS
    push   ecx
    call   edi
    add    esp,0x14
  Branch406:
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
// R6GameService.dll @ 10012890 : complete native control/access order and raw ABI retained.
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::RequestParentGroupOnLobby
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch408
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextRegServerSendRequestParentGroupOnLobby
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch408:
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
// R6GameService.dll data @ 1007e154 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_RegServerGetLobbiesTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GRegServerGetLobbiesHandlers},
};

// Native lobby-discovery/failure info record; addresses and states are literal.
// R6GameService.dll data @ 1007e144 : native storage identity retained.
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
// R6GameService.dll @ 10012a00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::InitProcessUpdateUbiServer(AGameInfo *gameInfo,ALevelInfo *level)
{
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
    push   0x0
    mov    DWORD PTR [ebp-0x1c],ecx
    push   edx
    mov    ecx,esi
    mov    DWORD PTR [ebp-0x4],0x0
    mov    DWORD PTR [ebp-0x20],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    mov    edx,DWORD PTR [esi]
    push   0x0
    lea    ecx,[ebp-0x20]
    push   ecx
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edx+0x10]
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ServerList_ResetSvrContainer
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ServerList_FillSvrContainer
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
// R6GameService.dll data @ 1007e214 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitProcessUpdateUbiServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitProcessUpdateUbiServerHandlers},
};

// Native internet registration/update info record; addresses and states are literal.
// R6GameService.dll data @ 1007e204 : native storage identity retained.
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
// R6GameService.dll @ 10012ac0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerLoginRouterRequest(void)
{
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
    ja     Branch412
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessRegServerLoginRouterRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x10093b50
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_RegServerRouterLogin
    mov    DWORD PTR ds:0x100939e8,0x2
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x10093b50
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch412
    mov    DWORD PTR ds:0x100939e8,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10093afc,0x3
    jmp    Branch411
    mov    DWORD PTR ds:0x10093af4,0x1
  Branch411:
    mov    DWORD PTR ds:0x100939e8,ecx
  Branch412:
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
// R6GameService.dll data @ 1007e274 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerLoginRouterRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerLoginRouterRequestHandlers},
};

// Native router-login request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e264 : native storage identity retained.
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
// R6GameService.dll @ 10012be0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerGetLobbiesRequest(void)
{
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
    ja     Branch414
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x10093b54
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_RegServerGetLobbies
    mov    DWORD PTR ds:0x10093af4,0x2
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x10093b54
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch414
    mov    DWORD PTR ds:0x10093af4,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10093afc,0x3
    jmp    Branch413
    mov    DWORD PTR ds:0x10093b14,0x1
  Branch413:
    mov    DWORD PTR ds:0x10093af4,ecx
  Branch414:
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
// R6GameService.dll data @ 1007e2d4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerGetLobbiesRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerGetLobbiesRequestHandlers},
};

// Native lobby-discovery/failure info record; addresses and states are literal.
// R6GameService.dll data @ 1007e2c4 : native storage identity retained.
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
// R6GameService.dll @ 10012d00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerRegOnLobbyRequest(void)
{
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
    ja     Branch416
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x10093b58
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ServerList_ResetSvrContainer
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ServerList_FillSvrContainer
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_RegisterServer
    mov    DWORD PTR ds:0x10093b14,0x2
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x10093b58
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch416
    mov    DWORD PTR ds:0x10093b14,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10093afc,0x3
    jmp    Branch415
    mov    DWORD PTR ds:0x10093af0,0x1
  Branch415:
    mov    DWORD PTR ds:0x10093b14,ecx
  Branch416:
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
// R6GameService.dll data @ 1007e334 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerRegOnLobbyRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerRegOnLobbyRequestHandlers},
};

// Native lobby-registration/reset info record; addresses and states are literal.
// R6GameService.dll data @ 1007e324 : native storage identity retained.
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
// R6GameService.dll @ 10012e30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerLoginRequest(void)
{
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
    ja     Branch417
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessRegServerLoginRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x10093b5c
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_ServerLogin
    mov    DWORD PTR ds:0x10093af0,0x2
  Branch417:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x10093b5c
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch417
    mov    DWORD PTR ds:0x10093af0,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10093afc,0x3
    mov    DWORD PTR ds:0x10093af0,edi
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_RouterDisconnect
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR ds:0x10093af0,edi
    pop    edi
    pop    esi
    mov    DWORD PTR ds:0x10093afc,0x2
    mov    DWORD PTR fs:0x0,ecx
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
// R6GameService.dll data @ 1007e394 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerLoginRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerLoginRequestHandlers},
};

// Native lobby-login request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e384 : native storage identity retained.
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
// R6GameService.dll @ 10012f60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessRegServerUpdateRequest(void)
{
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
    ja     Branch418
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessRegServerUpdateRequestSwitch]
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x10093b60
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_UpdateServer
    mov    DWORD PTR ds:0x10093b2c,0x2
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x10093b60
    fcomp  DWORD PTR [esi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch418
    mov    DWORD PTR ds:0x10093b2c,0x3
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
    mov    DWORD PTR ds:0x10093b2c,ecx
  Branch418:
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
// R6GameService.dll data @ 1007e3f4 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_ProcessRegServerUpdateRequestTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GProcessRegServerUpdateRequestHandlers},
};

// Native update-request info record; addresses and states are literal.
// R6GameService.dll data @ 1007e3e4 : native storage identity retained.
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
// R6GameService.dll @ 100137d0 : complete native control/access order and raw ABI retained.
__declspec(naked) int __thiscall UR6GSServers::InitializeRegServer(void)
{
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
    jne    Branch429
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [ebp-0x18],esp
    push   eax
    call   R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_Init
  Branch429:
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    xor    esi,esi
    test   eax,eax
    je     Branch439
    mov    eax,ds:0x10093b08
    test   eax,eax
    jne    Branch437
    call   R6GameServiceAddresses::InitializeRegistrationServiceSingleton
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    movzx  edi,al
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch430
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextRegServerLibraryInitialize
    push   edx
    call   ebx
    add    esp,0x8
  Branch430:
    test   edi,edi
    je     Branch436
    call   R6GameServiceAddresses::InstallRegistrationServiceCallbacks
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    xor    esi,esi
    xor    edi,edi
  Branch431:
    cmp    edi,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1+0x4
    jge    Branch434
    test   esi,esi
    jne    Branch435
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    imul   eax,eax,0x108
    add    eax,ecx
    xor    edx,edx
    mov    dx,WORD PTR [eax+0x104]
    push   edx
    push   eax
    call   R6GameServiceAddresses::ConnectRegistrationEndpoint
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1+0x4
    movzx  esi,al
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    inc    eax
    cmp    eax,ecx
    mov    ds:R6GameServiceAddresses::GMSRouterIndex,eax
    jl     Branch432
    xor    eax,eax
    mov    ds:R6GameServiceAddresses::GMSRouterIndex,eax
  Branch432:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch433
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    imul   eax,eax,0x108
    mov    edx,DWORD PTR [eax+ecx*1+0x104]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextRegServerSendRouterConnectI
    push   ecx
    call   ebx
    mov    eax,ds:R6GameServiceAddresses::GMSRouterIndex
    add    esp,0xc
  Branch433:
    inc    edi
    jmp    Branch431
  Branch434:
    test   esi,esi
    je     Branch436
  Branch435:
    mov    DWORD PTR ds:0x10093b08,0x1
    jmp    Branch438
  Branch436:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch438
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextResServerCouldNotConnectToServer
    push   eax
    call   ebx
    add    esp,0x8
    jmp    Branch438
  Branch437:
    mov    esi,0x1
  Branch438:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GMSClientInitialized
    test   ecx,ecx
    mov    eax,0x1
    mov    ds:0x10093afc,eax
    je     Branch439
    test   esi,esi
    jne    Branch440
  Branch439:
    xor    eax,eax
  Branch440:
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
// R6GameService.dll data @ 1007e538 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6GSServers_InitializeRegServerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GInitializeRegServerHandlers},
};

// Native registration-initialization info record; addresses and states are literal.
// R6GameService.dll data @ 1007e528 : native storage identity retained.
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
// Idle state compares the clock/retry time, then jumps unconditionally past13b0e..13b3d; those unreachable
// operations are retained as native code, not promoted to a separately callable body or an automatic retry.
// Registered update clears8c290 before rebuilding; GS-client update clears it only after rebuild/score refresh.
// Inline logout clock overwrites incoming argument words with cycle halves; EDI retains current game pointer.
// ID pointers reload between stores; float arithmetic stays x87 until the explicit retry-time FSTP. No rollback.
// R6GameService.dll @ 10013990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessInternetSrv(AR6AbstractGameInfo *gameInfo,ALevelInfo *level)
{
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_NativeStartedByGSClientSlot
    mov    ecx,eax
    cmp    DWORD PTR ds:0x1008c294,ebx
    mov    DWORD PTR [ebp-0x14],ecx
    je     Branch441
    mov    eax,0x1
    mov    DWORD PTR ds:0x1008c294,ebx
    mov    ds:0x10093b24,eax
    jmp    Branch442
  Branch441:
    mov    eax,ds:0x10093b24
  Branch442:
    cmp    ecx,ebx
    jne    Branch445
    mov    edi,0x4
    cmp    eax,edi
    ja     Branch445
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GProcessInternetSrvSwitch]
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_InitializeRegServer
    cmp    eax,ebx
    je     Branch444
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    eax,0x1
    mov    ds:0x100939e8,eax
    mov    ds:0x10093afc,eax
    mov    eax,DWORD PTR [ebp+0xc]
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_eventFillCreateGameInfo
    push   R6GameServiceAddresses::WideTextUbiGuest
    mov    ecx,R6GameServiceAddresses::GServiceString13
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    mov    DWORD PTR ds:0x10093b24,0x2
    jmp    Branch445
    mov    eax,ds:0x10093afc
    cmp    eax,0x2
    jne    Branch443
    mov    DWORD PTR ds:0x10093b24,0x3
    jmp    Branch445
  Branch443:
    cmp    eax,0x3
    jne    Branch445
  Branch444:
    mov    DWORD PTR ds:0x10093b24,edi
    jmp    Branch445
    mov    eax,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GSecondaryGroupId
    mov    DWORD PTR ds:0x10093b24,ebx
    mov    DWORD PTR ds:0x10091bd8,0x1
    mov    edx,DWORD PTR [eax+0x3c8]
    mov    DWORD PTR [edx+0x3c8],ecx
    mov    edx,DWORD PTR [eax+0x3c8]
    mov    eax,ds:R6GameServiceAddresses::GSecondaryLobbyServerId
    mov    DWORD PTR [edx+0x3cc],eax
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextServerRegisteredWithUbiComMasterServer
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    eax,DWORD PTR [ebp+0xc]
    add    esp,0x8
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_eventHandleNewLobbyConnection
    jmp    Branch445
    mov    DWORD PTR ds:0x10093b24,ebx
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat15_0
    fstp   DWORD PTR ds:0x10093b64
    jmp    Branch445
    cmp    DWORD PTR ds:0x100939ec,ebx
    jne    Branch445
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fcomp  DWORD PTR ds:0x10093b64
    fnstsw ax
    test   ah,0x41
    jmp    Branch445
    mov    ecx,DWORD PTR [ebp+0xc]
    fld    DWORD PTR [ecx+0x45c]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    sub    esp,0x8
    fstp   QWORD PTR [esp]
    push   R6GameServiceAddresses::WideTextTryAgainTimeF
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
    mov    DWORD PTR ds:0x10093b24,0x1
  Branch445:
    mov    eax,DWORD PTR [esi+0x194]
    test   al,0x40
    mov    ecx,DWORD PTR [ebp+0xc]
    je     Branch446
    mov    edx,DWORD PTR [ecx+0x4cc]
    cmp    DWORD PTR [edx+0x3c8],ebx
    je     Branch446
    and    eax,0xffffffbf
    mov    DWORD PTR [esi+0x194],eax
    mov    eax,DWORD PTR [ecx+0x4cc]
    mov    edx,DWORD PTR [eax+0x3c8]
    mov    eax,ds:R6GameServiceAddresses::GSecondaryGroupId
    mov    DWORD PTR [edx+0x3c8],eax
    mov    edx,DWORD PTR [ecx+0x4cc]
    mov    eax,DWORD PTR [edx+0x3c8]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GSecondaryLobbyServerId
    mov    DWORD PTR [eax+0x3cc],edx
  Branch446:
    cmp    DWORD PTR ds:0x1008c290,ebx
    je     Branch448
    cmp    DWORD PTR ds:0x10091bd8,ebx
    je     Branch447
    mov    edi,DWORD PTR [ebp+0x8]
    push   ecx
    push   edi
    mov    ecx,esi
    mov    DWORD PTR ds:0x1008c290,ebx
    call   R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServer
    mov    DWORD PTR ds:0x10093b2c,0x1
    jmp    Branch449
  Branch447:
    cmp    DWORD PTR [ebp-0x14],ebx
    je     Branch448
    mov    edi,DWORD PTR [ebp+0x8]
    push   ecx
    push   edi
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_InitProcessUpdateUbiServer
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_GSClientUpdateServerInfo
    mov    DWORD PTR ds:0x1008c290,ebx
    jmp    Branch449
  Branch448:
    mov    edi,DWORD PTR [ebp+0x8]
  Branch449:
    cmp    DWORD PTR ds:0x10093af8,ebx
    je     Branch452
    rdtsc
    mov    DWORD PTR [ebp+0x8],eax
    mov    DWORD PTR [ebp+0xc],edx
    fild   DWORD PTR [ebp+0xc]
    mov    eax,DWORD PTR [ebp+0xc]
    test   eax,eax
    jge    Branch450
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch450:
    mov    ecx,DWORD PTR [ebp+0x8]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   ecx,ecx
    fild   DWORD PTR [ebp+0x8]
    jge    Branch451
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch451:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    mov    eax,DWORD PTR [edi+0x3c8]
    fmul   QWORD PTR [edx]
    mov    DWORD PTR [eax+0x3c8],ebx
    mov    ecx,DWORD PTR [edi+0x3c8]
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    mov    DWORD PTR [ecx+0x3cc],ebx
    mov    ecx,esi
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat15_0
    fstp   DWORD PTR ds:0x10093b64
    call   R6GameServiceAddresses::UR6GSServers_LogOutServer
    mov    DWORD PTR ds:0x10093af8,ebx
  Branch452:
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
// R6GameService.dll @ 10005c80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeProcessIcmpPing(UR6GSServers *this,FFrame *frame,void *result)
{
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
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    DWORD PTR [ebp-0x14],ebx
    mov    DWORD PTR [ecx],ebx
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x14]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropObjectSlot
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,ebx
    je     Branch453
    mov    eax,ds:R6GameServiceAddresses::Core__GPropertySlot
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x60]
  Branch453:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebx
    mov    edi,eax
    jne    Branch454
    lea    edi,[ebp-0x14]
  Branch454:
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne    Branch455
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   ebx
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch455:
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
    call   esi
    test   eax,eax
    mov    DWORD PTR [ebp+0x8],eax
    fild   DWORD PTR [ebp+0x8]
    jge    Branch456
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat4294967296_0
  Branch456:
    fld    DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_02
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat5000_0
    fcompp
    fnstsw ax
    test   ah,0x5
    jp     Branch458
    call   esi
    test   eax,eax
    mov    DWORD PTR [ebp+0x8],eax
    fild   DWORD PTR [ebp+0x8]
    jge    Branch457
    fadd   DWORD PTR ds:R6GameServiceAddresses::NativeFloat4294967296_0
  Branch457:
    push   ebx
    fstp   DWORD PTR ds:R6GameServiceAddresses::NativeFloat0_02
    lea    ecx,[ebp-0x2c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::WideTextDoesNotMatter
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,0x10092e74
    call   R6GameServiceAddresses::ServerPing_NewPingRequest
  Branch458:
    lea    eax,[ebp-0x18]
    push   eax
    push   ebx
    mov    ecx,0x10092e74
    call   R6GameServiceAddresses::ServerPing_PingManager
    cmp    eax,ebx
    je     Branch459
    mov    ecx,DWORD PTR [ebp-0x18]
    mov    edx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [edi],ecx
    mov    DWORD PTR [edx],0x1
    jmp    Branch460
  Branch459:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [eax],ebx
  Branch460:
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

// Reads RDTSC once, combines unsigned halves in x87, scales by live seconds-per-cycle and adds 16777216 before float store.
// UE2 appSeconds corroborates the formula; inherited x87 precision remains until the final float32 store.
// R6GameService.dll @ 10005e40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::execNativeGetSeconds(UR6GSServers *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_execNativeGetSecondsSelectExceptionInfo
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
    jne    Branch461
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch461:
    rdtsc
    mov    DWORD PTR [ebp-0x18],eax
    mov    DWORD PTR [ebp+0x8],edx
    fild   DWORD PTR [ebp+0x8]
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    jge    Branch462
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch462:
    mov    ecx,DWORD PTR [ebp-0x18]
    fmul   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
    test   ecx,ecx
    fild   DWORD PTR [ebp-0x18]
    jge    Branch463
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble4294967296_0
  Branch463:
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GSecondsPerCycleSlot
    faddp  st(1),st
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp-0xc]
    fmul   QWORD PTR [edx]
    pop    edi
    pop    esi
    fadd   QWORD PTR ds:R6GameServiceAddresses::NativeDouble16777216_0
    pop    ebx
    fstp   DWORD PTR [eax]
    mov    DWORD PTR fs:0x0,ecx
    mov    esp,ebp
    pop    ebp
    ret    0x8
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
    mov    eax,ds:0x10091e64
    push   ebx
    push   esi
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x4],ebx
    je     Branch480
    cmp    DWORD PTR [ebp+0x8],ebx
    je     Branch480
    push   0x320
    push   0x1f4
    call   R6GameServiceAddresses::DispatchMSClientState
    mov    eax,ds:0x10091c10
    sub    eax,0x26
    je     Branch473
    dec    eax
    jne    Branch474
    mov    eax,DWORD PTR [esi+0x194]
    test   ah,0x1
    je     Branch464
    and    eax,0xfffffeff
    or     eax,0x200
    mov    DWORD PTR [esi+0x194],eax
  Branch464:
    mov    eax,ds:0x10091d2c
    cmp    eax,0x64
    mov    DWORD PTR ds:0x10091c14,0x3
    mov    DWORD PTR ds:0x10091e68,ebx
    jg     Branch468
    je     Branch467
    sub    eax,0x3
    je     Branch466
    dec    eax
    je     Branch465
    sub    eax,0xb
    jne    Branch469
    push   R6GameServiceAddresses::WideTextLOGINFAILPASSWORDNOTCORRECT
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x24]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch465:
    push   R6GameServiceAddresses::WideTextLOGINFAILNOTREGISTERED
    lea    ecx,[ebp-0x30]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x30]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch466:
    push   R6GameServiceAddresses::WideTextLOGINFAILALREADYCONNECTED
    lea    ecx,[ebp-0x3c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x3c]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch467:
    push   R6GameServiceAddresses::WideTextLOGINFAILDATABASEFAILED
    lea    ecx,[ebp-0x48]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x48]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x48]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch468:
    sub    eax,0x1f5
    je     Branch472
    dec    eax
    je     Branch471
    sub    eax,0xa
    je     Branch470
  Branch469:
    push   R6GameServiceAddresses::WideTextLOGINFAILDEFAULT
    lea    ecx,[ebp-0x54]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x54]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x54]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch470:
    push   R6GameServiceAddresses::WideTextLOGINFAILLOCKEDACCOUNT
    lea    ecx,[ebp-0x60]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x60]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x60]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch471:
    push   R6GameServiceAddresses::WideTextLOGINFAILBLOCKEDACCOUNT
    lea    ecx,[ebp-0x6c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x6c]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x6c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch472:
    push   R6GameServiceAddresses::WideTextLOGINFAILBANNEDACCOUNT
    lea    ecx,[ebp-0x78]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x78]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x78]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch474
  Branch473:
    push   0x10091d48
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[esi+0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    push   ebx
    push   0x4000
    mov    ecx,esi
    mov    DWORD PTR ds:0x10091c14,0x6
    mov    DWORD PTR ds:0x10091e68,0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_SaveConfigSlot
    and    DWORD PTR [esi+0x194],0xfffffeff
  Branch474:
    mov    eax,ds:0x10091be0
    sub    eax,0x26
    mov    DWORD PTR ds:0x10091c10,ebx
    je     Branch477
    dec    eax
    jne    Branch478
    mov    eax,ds:0x10091bfc
    sub    eax,0x2
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoginRequested,0x3
    je     Branch476
    dec    eax
    je     Branch475
    push   R6GameServiceAddresses::WideTextJOINSERVERFAILDEFAULT
    lea    ecx,[ebp-0x78]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x78]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0xb
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x78]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GJoinInProgress,ebx
    jmp    Branch478
  Branch475:
    push   R6GameServiceAddresses::WideTextJOINSERVERFAILROOMFULL
    lea    ecx,[ebp-0x6c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x6c]
    push   eax
    mov    BYTE PTR [ebp-0x4],0xa
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x6c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GJoinInProgress,ebx
    jmp    Branch478
  Branch476:
    push   R6GameServiceAddresses::WideTextJOINSERVERFAILPASSWORDNOTCORRECT
    lea    ecx,[ebp-0x60]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x60]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x60]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GJoinInProgress,ebx
    jmp    Branch478
  Branch477:
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoginRequested,0x6
    mov    DWORD PTR ds:R6GameServiceAddresses::GLoggedInUbiDotCom,0x1
  Branch478:
    cmp    DWORD PTR ds:0x10091bf0,ebx
    mov    DWORD PTR ds:0x10091be0,ebx
    je     Branch479
    mov    DWORD PTR ds:0x10091bf0,ebx
    or     DWORD PTR [esi+0x2c],0x10
  Branch479:
    cmp    DWORD PTR ds:0x10091c08,ebx
    je     Branch480
    mov    DWORD PTR ds:0x10091c08,ebx
    or     DWORD PTR [esi+0x2c],0x20
  Branch480:
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

// Pumps enabled CD-key clients and advances activation/authorization replies, retries, IDs and messages in native order.
// Native callbacks can start authorization in this same poll; retry state is shared across both phases.
// R6GameService.dll @ 1000dd90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollClientCDKeyCallbacks(UR6GSServers *this,int enabled,int requestInput,int validationInput)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6GSServers_PollClientCDKeyCallbacksSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x84
    mov    eax,ds:0x10093410
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    edi,ecx
    mov    DWORD PTR [ebp-0x4],ebx
    je     Branch481
    cmp    esi,ebx
    je     Branch481
    cmp    DWORD PTR [ebp+0x10],ebx
    je     Branch481
    mov    eax,ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   0x1f4
    push   eax
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    cmp    eax,ebx
    jne    Branch481
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch481
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSCDKeyEngineFAILED
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch481:
    cmp    DWORD PTR ds:0x100933cc,ebx
    je     Branch483
    cmp    esi,ebx
    je     Branch482
    cmp    DWORD PTR [ebp+0x10],ebx
    je     Branch482
    mov    eax,ds:R6GameServiceAddresses::GModCDKeyContext
    push   0x1f4
    push   eax
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    movzx  eax,al
    cmp    eax,ebx
    jne    Branch482
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch482
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSCDKeyEngineFAILED
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch482:
    cmp    DWORD PTR ds:0x100933cc,ebx
    je     Branch483
    cmp    esi,ebx
    je     Branch483
    cmp    DWORD PTR [ebp+0xc],ebx
    je     Branch483
    mov    eax,ds:R6GameServiceAddresses::GModCDKeyContext
    push   0x1f4
    push   eax
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
  Branch483:
    cmp    DWORD PTR ds:0x10093410,ebx
    je     Branch526
    cmp    esi,ebx
    je     Branch526
    cmp    DWORD PTR [ebp+0xc],ebx
    je     Branch526
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GBaseCDKeyContext
    push   0x1f4
    push   ecx
    call   R6GameServiceAddresses::ForwardGuardedCDKeyContextOperation1
    mov    eax,ds:R6GameServiceAddresses::GActivationState
    dec    eax
    cmp    eax,0x5
    ja     Branch493
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GCDKeyActivationDispatch]
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch484
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextGECDKeyActIDRequestEGSREQFIRSTPASSPassD
    push   ecx
    call   esi
    add    esp,0xc
  Branch484:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,0xa
    jl     Branch486
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch485
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSTimeoutPassed
    push   eax
    call   esi
    add    esp,0x8
  Branch485:
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString8
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    jmp    Branch491
  Branch486:
    cmp    DWORD PTR ds:0x10093408,ebx
    mov    ecx,R6GameServiceAddresses::GServiceString1
    je     Branch487
    push   R6GameServiceAddresses::GServiceString3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    push   R6GameServiceAddresses::GServiceString5
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    jmp    Branch488
  Branch487:
    push   R6GameServiceAddresses::WideTextRAVENSHIELD
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
  Branch488:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch489
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString1
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceString1+0x4
    sub    esp,0xc
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceString1+0x8
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSMSzGameServiceGameNameS
    push   eax
    call   esi
    add    esp,0x14
  Branch489:
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x100934bc
    mov    ecx,DWORD PTR ds:0x10093408
    push   ecx
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_RequestActivation
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x2
    jmp    Branch494
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x100934bc
    fcomp  DWORD PTR [edi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch493
    mov    eax,ds:R6GameServiceAddresses::GCDKeyRetryCount
    inc    eax
    cmp    eax,0xa
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    jl     Branch492
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch490
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQWAITINGFORRESPONSETimeoutPassed
    push   eax
    call   esi
    add    esp,0x8
  Branch490:
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,ebx
  Branch491:
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_CancelGSCDKeyActID
    mov    edx,DWORD PTR [edi]
    call   DWORD PTR [edx+0xb8]
    jmp    Branch494
  Branch492:
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x1
  Branch493:
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
  Branch494:
    mov    eax,ds:R6GameServiceAddresses::GAuthorizationState
    dec    eax
    cmp    eax,0x6
    ja     Branch526
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GCDKeyAuthorizationDispatch]
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch495
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQSUCCESS
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch495:
    or     DWORD PTR [edi+0x194],0x1
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_PrivateStaticClassSlot
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UClass_GetDefaultActorSlot
    push   0x10093418
    lea    edx,[ebp-0x78]
    push   edx
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_AActor_GlobalIDToStringSlot
    lea    esi,[edi+0x1b8]
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    lea    ecx,[ebp-0x78]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    cmp    DWORD PTR ds:0x10093408,ebx
    je     Branch497
    mov    eax,DWORD PTR [edi+0x19c]
    mov    edx,DWORD PTR [edi+0x194]
    mov    ecx,DWORD PTR [eax+0x3c]
    xor    ecx,edx
    mov    edx,DWORD PTR [eax+0x3c]
    and    ecx,0x1
    xor    edx,ecx
    push   R6GameServiceAddresses::GServiceString8
    mov    ecx,R6GameServiceAddresses::GServiceString5
    mov    DWORD PTR [eax+0x3c],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    mov    ecx,DWORD PTR [edi+0x19c]
    push   esi
    add    ecx,0x40
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    push   R6GameServiceAddresses::GServiceString10
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    xor    eax,eax
    lea    esp,[esp+0x0]
  Branch496:
    cmp    eax,0x10
    jae    Branch500
    mov    cl,BYTE PTR [eax+0x100933e4]
    mov    edx,DWORD PTR [edi+0x19c]
    mov    BYTE PTR [eax+edx*1+0x2c],cl
    inc    eax
    jmp    Branch496
  Branch497:
    xor    eax,eax
    lea    ebx,[ebx+0x0]
  Branch498:
    cmp    eax,0x10
    jae    Branch499
    mov    dl,BYTE PTR [eax+0x100933e4]
    mov    BYTE PTR [eax+edi*1+0x174],dl
    inc    eax
    jmp    Branch498
  Branch499:
    lea    eax,[edi+0x1b8]
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString10
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
  Branch500:
    mov    edx,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [edx+0xb8]
    push   R6GameServiceAddresses::WideTextACTIDREQSUCCESS
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x24]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    jmp    Branch493
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    cmp    ecx,ebx
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch501
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILED
    push   eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x8
  Branch501:
    mov    eax,ds:0x100933f4
    dec    eax
    je     Branch508
    dec    eax
    je     Branch505
    sub    eax,0x2
    je     Branch503
    cmp    ecx,ebx
    je     Branch502
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndDefault
    push   edx
    call   esi
    add    esp,0x8
  Branch502:
    push   R6GameServiceAddresses::WideTextACTIDREQFAILDEFAULT
    lea    ecx,[ebp-0x30]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x30]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch494
  Branch503:
    cmp    ecx,ebx
    je     Branch504
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYALREADYONLINE
    push   eax
    call   esi
    add    esp,0x8
  Branch504:
    push   R6GameServiceAddresses::WideTextACTIDREQFAILCDKEYUSED
    lea    ecx,[ebp-0x3c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x3c]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,ebx
    jmp    Branch494
  Branch505:
    cmp    ecx,ebx
    je     Branch506
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYINVALIDCDKEY
    push   ecx
    call   esi
    add    esp,0x8
  Branch506:
    push   R6GameServiceAddresses::WideTextACTIDREQFAILINVALIDCDKEY
    lea    ecx,[ebp-0x48]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x48]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x48]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,ebx
  Branch507:
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    jmp    Branch494
  Branch508:
    cmp    DWORD PTR ds:0x10091e68,ebx
    jne    Branch512
    push   R6GameServiceAddresses::WideText02
    mov    ecx,R6GameServiceAddresses::GLastServerQueriedAddress
    call   DWORD PTR ds:R6GameServiceAddresses::Core__9FStringSlot
    cmp    eax,ebx
    je     Branch509
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::GLastServerQueriedAddress
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_OnSameSubNet
    cmp    eax,ebx
    je     Branch511
  Branch509:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch510
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQSUCCESSAndMsgEMENUREQTIMEOUT
    push   edx
    call   esi
    add    esp,0x8
  Branch510:
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GActivationState,0x6
    mov    eax,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [eax+0xb8]
    jmp    Branch507
  Branch511:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
  Branch512:
    cmp    ecx,ebx
    je     Branch513
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQFAILEDAndMsgACTIDREQTIMEOUTER
    push   edx
    call   esi
    add    esp,0x8
  Branch513:
    push   R6GameServiceAddresses::WideTextACTIDREQTIMEOUTERROR
    lea    ecx,[ebp-0x54]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x54]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x54]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::GCDKeyRetryCount
    inc    eax
    mov    ecx,edi
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    call   R6GameServiceAddresses::UR6GSServers_RequestGSCDKeyActID
    jmp    Branch494
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch514
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQFIRSTPASSPassD
    push   ecx
    call   esi
    add    esp,0xc
  Branch514:
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fstp   DWORD PTR ds:0x100934b8
    cmp    DWORD PTR ds:0x10093408,ebx
    je     Branch516
    push   R6GameServiceAddresses::GEmptyWideText
    mov    ecx,R6GameServiceAddresses::GServiceString5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__9FStringSlot
    cmp    eax,ebx
    je     Branch515
    push   R6GameServiceAddresses::GServiceString5
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
  Branch515:
    mov    edx,DWORD PTR [edi+0x19c]
    push   0x100933f8
    add    edx,0x2c
    push   edx
    jmp    Branch517
  Branch516:
    push   R6GameServiceAddresses::GServiceString9
    mov    ecx,R6GameServiceAddresses::GServiceString8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    push   0x100933f8
    lea    eax,[edi+0x174]
    push   eax
  Branch517:
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_CopyActivationIDInByteArray
    mov    ecx,DWORD PTR ds:0x10093408
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_RequestAuthorization
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x2
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch518
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQWAITINGFORRESPONSE
    push   eax
    call   esi
    add    esp,0x8
  Branch518:
    call   R6GameServiceAddresses::ReadCycleTimeSeconds
    fsub   DWORD PTR ds:0x100934b8
    fcomp  DWORD PTR [edi+0x198]
    fnstsw ax
    test   ah,0x41
    jne    Branch526
    mov    eax,ds:R6GameServiceAddresses::GCDKeyRetryCount
    inc    eax
    cmp    eax,0xa
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    jl     Branch534
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch519
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextAndGoingEMENUREQTIMEOUT
    push   edx
    call   esi
    add    esp,0x8
  Branch519:
    push   R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUT
    lea    ecx,[ebp-0x54]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x54]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x54]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    call   R6GameServiceAddresses::UR6GSServers_CancelGSCDKeyActID
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch536
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQINUSEFAILED
    push   eax
    call   esi
    add    esp,0x8
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    jmp    Branch525
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch520
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQCONNECTFAILED
    push   edx
    call   esi
    add    esp,0x8
  Branch520:
    push   R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUTERROR
    lea    ecx,[ebp-0x48]
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x48]
    push   eax
    mov    BYTE PTR [ebp-0x4],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x48]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch521
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQFAILED
    push   eax
    call   esi
    add    esp,0x8
  Branch521:
    push   R6GameServiceAddresses::WideTextAUTHIDREQFAILURE
    lea    ecx,[ebp-0x3c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x3c]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0x9
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x3c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    and    DWORD PTR [edi+0x194],0xfffffffe
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    jmp    Branch525
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch522
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextProcessCDKeyAuthorizationRequestEGSREQSUCCESS
    push   ecx
    call   esi
    add    esp,0x8
  Branch522:
    cmp    DWORD PTR ds:0x10093408,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    push   0x10093428
    je     Branch523
    lea    edx,[ebp-0x84]
    push   edx
    call   R6GameServiceAddresses::FormatAuthenticationIdHex
    add    esp,0x8
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString11
    mov    BYTE PTR [ebp-0x4],0xa
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x84]
    jmp    Branch524
  Branch523:
    lea    eax,[ebp-0x90]
    push   eax
    call   R6GameServiceAddresses::FormatAuthenticationIdHex
    add    esp,0x8
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString4
    mov    BYTE PTR [ebp-0x4],0xb
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    ecx,[ebp-0x90]
  Branch524:
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_IsAuthIDSuccess
    cmp    eax,ebx
    jne    Branch527
    cmp    DWORD PTR ds:0x10093408,ebx
    jne    Branch527
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   0x1
    call   DWORD PTR [edx+0x80]
  Branch525:
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
  Branch526:
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  Branch527:
    push   R6GameServiceAddresses::WideTextAUTHIDREQSUCCESS
    lea    ecx,[ebp-0x30]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x30]
    push   eax
    mov    BYTE PTR [ebp-0x4],0xc
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    jmp    Branch525
    mov    DWORD PTR ds:R6GameServiceAddresses::GCDKeyRetryCount,ebx
    mov    edx,DWORD PTR [edi]
    mov    ecx,edi
    call   DWORD PTR [edx+0xbc]
    mov    eax,ds:0x10093414
    dec    eax
    cmp    eax,0x4
    ja     Branch538
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GCDKeyReplyDispatch]
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch528
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideText2CDKeyIsAlreadyInUseERROR
    push   ecx
    call   esi
    add    esp,0x8
  Branch528:
    push   R6GameServiceAddresses::WideTextAUTHIDREQINUSEERROR
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x24]
    push   edx
    mov    BYTE PTR [ebp-0x4],0xd
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x5
    jmp    Branch525
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch529
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GLastServerQueriedAddress
    mov    eax,ds:0x10092930
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR ds:0x10092934
    mov    DWORD PTR [ecx+0x4],eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [ecx+0x8],edx
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextMSzLastServerQueriedS
    push   ecx
    call   esi
    add    esp,0x14
  Branch529:
    cmp    DWORD PTR ds:0x10091e68,ebx
    jne    Branch532
    push   R6GameServiceAddresses::WideText02
    mov    ecx,R6GameServiceAddresses::GLastServerQueriedAddress
    call   DWORD PTR ds:R6GameServiceAddresses::Core__9FStringSlot
    cmp    eax,ebx
    je     Branch530
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   R6GameServiceAddresses::GLastServerQueriedAddress
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov    ecx,edi
    call   R6GameServiceAddresses::UR6GSServers_OnSameSubNet
    cmp    eax,ebx
    je     Branch532
  Branch530:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch531
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextTIMEOUTERRORLetPlayerJoinAnyway
    push   eax
    call   esi
    add    esp,0x8
  Branch531:
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x6
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  Branch532:
    mov    eax,ds:R6GameServiceAddresses::GCDKeyRetryCount
    inc    eax
    cmp    eax,0xa
    mov    ds:R6GameServiceAddresses::GCDKeyRetryCount,eax
    jl     Branch534
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch533
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextTIMEOUTERRORDonTLetPlayerJoinRemoteServer
    push   edx
    call   esi
    add    esp,0x8
  Branch533:
    push   R6GameServiceAddresses::WideTextAUTHIDREQTIMEOUTERROR
    lea    ecx,[ebp-0x60]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x60]
    push   eax
    mov    BYTE PTR [ebp-0x4],0xe
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x60]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    ecx,edi
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x4
    call   R6GameServiceAddresses::UR6GSServers_CancelGSCDKeyAuthID
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  Branch534:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x1
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch535
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextERRORCDKEYINTERNALERROR
    push   eax
    call   esi
    add    esp,0x8
  Branch535:
    push   R6GameServiceAddresses::WideTextAUTHIDREQNOTCHALLENGED
    lea    ecx,[ebp-0x6c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    lea    ecx,[ebp-0x6c]
    push   ecx
    mov    ecx,DWORD PTR [edx]
    mov    BYTE PTR [ebp-0x4],0xf
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x6c]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch536:
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    jmp    Branch525
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebx
    je     Branch537
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextERRORCDKEYINTERNALERROR
    push   ecx
    call   esi
    add    esp,0x8
  Branch537:
    push   R6GameServiceAddresses::WideTextAUTHIDREQINTERROR
    lea    ecx,[ebp-0x78]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x78]
    push   edx
    mov    BYTE PTR [ebp-0x4],0x10
    call   DWORD PTR ds:R6GameServiceAddresses::Engine_UR6AbstractGameManager_eventGMProcessMsgSlot
    lea    ecx,[ebp-0x78]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,ebx
    jmp    Branch525
  Branch538:
    mov    DWORD PTR ds:R6GameServiceAddresses::GAuthorizationState,0x3
    jmp    Branch525
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
// R6GameService.dll @ 10011170 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::ProcessSubmitMatchResultReply(UR6GSServers *this)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    push   esi
    push   edi
    mov    esi,ecx
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x34]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    je     Branch539
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    and    eax,0x8000ffff
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientClearMatchResultReturnedX
    push   eax
    call   edi
    add    esp,0xc
  Branch539:
    and    DWORD PTR [esi+0x2c],0xfffffff7
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch540
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSClientCallingPlayerMatchFinished
    push   edx
    call   edi
    add    esp,0x8
  Branch540:
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x2c]
    test   eax,eax
    jge    Branch541
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch542
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    and    eax,0x8000ffff
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientERRORPlayerMatchFinishedErrorX
    push   eax
    call   edi
    add    esp,0xc
    pop    edi
    pop    esi
    ret
  Branch541:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch542
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSClientPlayerMatchFinishedReturnedSUCCESS
    push   edx
    call   edi
    add    esp,0x8
  Branch542:
    pop    edi
    pop    esi
    ret
  }
}

// Dispatches one GS message, advances client data/state and polls one prioritized start/wait/submit reply path.
// Output slot is not precleared; dispatch runs after retrieval failure. Server-start, client-start, submit have priority.
// R6GameService.dll @ 10011220 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::PollGSClientCallbacks(UR6GSServers *this,int enabled)
{
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
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot
    mov    eax,ds:R6GameServiceAddresses::Engine__GR6GameManagerSlot
    mov    ecx,DWORD PTR [eax]
    test   BYTE PTR [ecx+0x2c],0x1
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch566
    mov    eax,DWORD PTR [ebp+0x8]
    test   eax,eax
    je     Branch566
    push   0x0
    lea    edx,[ebp-0x18]
    push   edx
    call   R6GameServiceAddresses::GetLoadedGSClientMessage
    test   eax,eax
    jge    Branch543
    or     DWORD PTR [ebx+0x194],0x8
  Branch543:
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::DispatchLoadedGSClientMessage
    mov    eax,ds:0x100938c8
    cmp    eax,0x11000
    jg     Branch545
    je     Branch544
    sub    eax,0x10001
    cmp    eax,0x4
    ja     Branch545
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GGSMessageDispatch]
    mov    eax,ds:R6GameServiceAddresses::GGSClientState
    test   eax,eax
    jne    Branch545
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
    lea    ecx,[ebx+0x1f4]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
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
    push   eax
    mov    ecx,R6GameServiceAddresses::GServiceString12
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    push   0x100937c8
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    push   0x100935c0
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x20c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    edx,DWORD PTR [ebx]
    push   0x1
    mov    ecx,ebx
    call   DWORD PTR [edx+0xcc]
    push   0x100934c0
    call   R6GameServiceAddresses::ServerPing_GetPingTime
    add    esp,0x4
    cmp    eax,0x3e8
    jl     Branch545
    push   0x100938d0
    call   R6GameServiceAddresses::ServerPing_GetPingTime
    add    esp,0x4
    cmp    eax,0x3e8
    jg     Branch545
    push   R6GameServiceAddresses::GServiceString12
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    esi,[ebx+0x1f4]
    push   esi
    mov    ecx,R6GameServiceAddresses::GServiceString12
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot
    lea    eax,[ebp-0x24]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot3
    jmp    Branch545
    cmp    DWORD PTR ds:R6GameServiceAddresses::GGSClientState,0x2
    jne    Branch545
    mov    edx,DWORD PTR [ebx]
    push   0x3
    mov    ecx,ebx
    call   DWORD PTR [edx+0xcc]
    jmp    Branch545
    mov    eax,ds:R6GameServiceAddresses::GGSClientState
    test   eax,eax
    jne    Branch545
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   0x100937c8
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    push   0x100936c8
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x200]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    push   0x100935c0
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x20c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
    mov    eax,DWORD PTR [ebx]
    push   0x5
    mov    ecx,ebx
    call   DWORD PTR [eax+0xcc]
    mov    ecx,DWORD PTR ds:0x100938cc
    mov    DWORD PTR [ebx+0x190],ecx
    jmp    Branch545
    cmp    DWORD PTR ds:R6GameServiceAddresses::GGSClientState,0x6
    jne    Branch545
    mov    edx,DWORD PTR [ebx]
    push   0x7
    mov    ecx,ebx
    call   DWORD PTR [edx+0xcc]
    jmp    Branch545
    mov    eax,DWORD PTR [ebx]
    push   0x9
    mov    ecx,ebx
    call   DWORD PTR [eax+0xcc]
    jmp    Branch545
  Branch544:
    cmp    DWORD PTR ds:0x100936c0,0x80006212
    jne    Branch545
    or     DWORD PTR [ebx+0x194],0x10
  Branch545:
    mov    DWORD PTR ds:0x100938c8,0x0
    mov    eax,DWORD PTR [ebx+0x2c]
    test   al,0x1
    je     Branch555
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x40]
    test   eax,eax
    jge    Branch554
    mov    ecx,eax
    and    ecx,0x8000ffff
    cmp    ecx,0x80006207
    jg     Branch548
    je     Branch547
    cmp    ecx,0x80004005
    je     Branch546
    cmp    ecx,0x80006204
    jne    Branch549
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch553
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSENOTMASTER
    push   eax
    jmp    Branch552
  Branch546:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch553
    push   R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSEFAIL
    jmp    Branch551
  Branch547:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch566
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientSERVERNOREPLYCheckStartMatchReplyGSENOREPLY
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
    jmp    Branch566
  Branch548:
    cmp    ecx,0x80006209
    je     Branch550
  Branch549:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch566
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyX
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
    jmp    Branch566
  Branch550:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch553
    push   R6GameServiceAddresses::WideTextGSClientSERVERERRORCheckStartMatchReplyGSEMATCHNOTFINISHED
  Branch551:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   edx
  Branch552:
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x8
  Branch553:
    and    DWORD PTR [ebx+0x2c],0xfffffffe
    jmp    Branch566
  Branch554:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch553
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientSERVERCheckStartMatchReplyCBReceivedSUCCESSResultCodeIsX
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    eax,DWORD PTR [ebx+0x2c]
    add    esp,0xc
    and    eax,0xfffffffe
    mov    DWORD PTR [ebx+0x2c],eax
    jmp    Branch566
  Branch555:
    test   al,0x2
    je     Branch562
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceBstr
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    edx,DWORD PTR [eax]
    push   ecx
    push   0x0
    push   eax
    call   DWORD PTR [edx+0x20]
    mov    ecx,eax
    and    ecx,0x8000ffff
    jne    Branch561
    mov    ecx,DWORD PTR [ebx+0x2c]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    and    ecx,0xfffffffd
    mov    DWORD PTR [ebx+0x2c],ecx
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch556
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingPlayerMatchStarted
    push   eax
    call   esi
    add    esp,0x8
  Branch556:
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x28]
    test   eax,eax
    jge    Branch557
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch559
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    and    eax,0x8000ffff
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientERRORPlayerMatchStartedErrorX
    push   eax
    call   esi
    add    esp,0xc
    jmp    Branch558
  Branch557:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch559
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSClientPlayerMatchStartedReturnedSUCCESS
    push   edx
    call   esi
    add    esp,0x8
  Branch558:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch559
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingInitMatchResults
    push   ecx
    call   esi
    add    esp,0x8
  Branch559:
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    edx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [edx+0x30]
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x34]
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    edx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [edx+0x30]
    test   eax,eax
    jge    Branch560
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch566
    and    eax,0x8000ffff
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientERRORInitMatchResultsErrorX
    push   ecx
    call   esi
    add    esp,0xc
    jmp    Branch566
  Branch560:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch566
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextGSClientInitMatchResultsReturnedSUCCESS
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch566
  Branch561:
    test   eax,eax
    jge    Branch566
    and    DWORD PTR [ebx+0x2c],0xfffffffd
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch566
    push   ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSClientERRORWaitMatchStartedErrorX
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
    jmp    Branch566
  Branch562:
    test   al,0x8
    je     Branch566
    mov    eax,ds:R6GameServiceAddresses::GGSClientInterface
    mov    ecx,DWORD PTR [eax]
    push   eax
    call   DWORD PTR [ecx+0x44]
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    esi,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch563
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   esi
    push   R6GameServiceAddresses::WideTextGSClientCheckSubmitMatchReplyReturnedCodeX
    push   eax
    call   edi
    add    esp,0xc
  Branch563:
    mov    eax,esi
    and    eax,0x8000ffff
    cmp    eax,0x80006207
    je     Branch566
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   ecx,ecx
    je     Branch565
    test   esi,esi
    jl     Branch564
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextGSClientCheckSubmitMatchReplySuccessfull
    push   edx
    call   edi
    add    esp,0x8
    jmp    Branch565
  Branch564:
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextGSClientERRORCheckSubmitMatchReplyErrorX
    push   ecx
    call   edi
    add    esp,0xc
  Branch565:
    mov    ecx,ebx
    call   R6GameServiceAddresses::UR6GSServers_ProcessSubmitMatchResultReply
  Branch566:
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
// R6GameService.dll @ 10010bc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6GSServers::SetGSGameState(UR6GSServers *this,uchar newState)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    je     Branch571
    push   esi
    push   edi
    movzx  edi,bl
    cmp    edi,0xa
    ja     Branch568
    jmp    DWORD PTR [edi*4+R6GameServiceAddresses::GGSStateLogDispatch]
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSWAITINGFORGSINIT
    jmp    Branch567
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTINITRCVD
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch569
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTWAITINGCHSTA
    push   edx
    call   esi
    add    esp,0x8
    jmp    Branch569
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTCHSTARCVD
    jmp    Branch567
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSCLIENTINGAME
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch569
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERINITRCVD
    push   edx
    call   esi
    add    esp,0x8
    jmp    Branch569
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERWAITINGCHSTA
    jmp    Branch567
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERCHSTARCVD
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch569
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERSETTINGUPGAME
    push   edx
    call   esi
    add    esp,0x8
    jmp    Branch569
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSTERMINATERCVD
  Branch567:
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   ecx
    call   esi
    add    esp,0x8
    jmp    Branch569
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsEGSSERVERREADY
    push   eax
    call   esi
    add    esp,0x8
    jmp    Branch569
  Branch568:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    push   edi
    push   R6GameServiceAddresses::WideTextSetGSGameStateNewStateIsD
    push   edx
    call   esi
    add    esp,0xc
  Branch569:
    mov    eax,ds:R6GameServiceAddresses::GGSClientState
    cmp    eax,0xa
    ja     Branch570
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::UR6GSServersGGSStateLogDispatch]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSWAITINGFORGSINIT
    push   ecx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTINITRCVD
    push   eax
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTWAITINGCHSTA
    push   edx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTCHSTARCVD
    push   ecx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSCLIENTINGAME
    push   eax
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERINITRCVD
    push   edx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERWAITINGCHSTA
    push   ecx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERCHSTARCVD
    push   eax
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERSETTINGUPGAME
    push   edx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSTERMINATERCVD
    push   ecx
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsEGSSERVERREADY
    push   eax
    call   esi
    add    esp,0x8
    pop    edi
    movzx  eax,bl
    pop    esi
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
  Branch570:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   edi
    push   R6GameServiceAddresses::WideTextSetGSGameStateOldStateIsD
    push   edx
    call   esi
    add    esp,0xc
    pop    edi
    pop    esi
  Branch571:
    movzx  eax,bl
    mov    ds:R6GameServiceAddresses::GGSClientState,eax
    pop    ebx
    ret    0x4
  }
}

// Returns the low game-state byte in AL without changing the upper EAX bytes.
// R6GameService.dll @ 10010f00 : complete native control/access order and raw ABI retained.
uchar __thiscall UR6GSServers::GetGSGameState(UR6GSServers *this)
{
  return *reinterpret_cast<const uchar *>(R6GameServiceAddresses::GGSClientState);
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
    mov    eax,ds:R6GameServiceAddresses::TextTempDat
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::TextMpDat
    mov    dx,WORD PTR ds:R6GameServiceAddresses::TextAt
    mov    DWORD PTR [esp+0x1c],eax
    mov    al,ds:0x1006db2a
    xor    ebp,ebp
    mov    BYTE PTR [esp+0x26],al
    cmp    DWORD PTR ds:R6GameServiceAddresses::GMSClientInitialized,ebp
    mov    DWORD PTR [esp+0x1530],ebp
    mov    DWORD PTR [esp+0x20],ecx
    mov    WORD PTR [esp+0x24],dx
    jne    Branch594
    push   R6GameServiceAddresses::WideText02
    mov    ecx,R6GameServiceAddresses::GLastServerQueriedAddress
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringSlot2
    push   R6GameServiceAddresses::GEmptyWideText
    lea    ecx,[esp+0x153c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appStrcmpSlot
    push   eax
    call   edi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x8
    test   eax,eax
    je     Branch572
    push   R6GameServiceAddresses::WideText0000
    lea    ecx,[esp+0x153c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   edi
    add    esp,0x8
    test   eax,eax
    je     Branch572
    lea    ecx,[esp+0x1538]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    jmp    Branch573
  Branch572:
    push   ebp
  Branch573:
    call   R6GameServiceAddresses::ResolveAddressText
    cmp    DWORD PTR ds:R6GameServiceAddresses::GServiceVerboseLogging,ebp
    movzx  eax,al
    je     Branch574
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextInitializeSocketsI
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0xc
  Branch574:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore,ebp
    jne    Branch577
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x24
    call   DWORD PTR [edx]
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ebp
    mov    BYTE PTR [esp+0x1530],0x1
    je     Branch575
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeSerializedByteStore
    jmp    Branch576
  Branch575:
    xor    eax,eax
  Branch576:
    mov    BYTE PTR [esp+0x1530],0x0
    mov    ds:R6GameServiceAddresses::GPublicSerializedStore,eax
  Branch577:
    cmp    DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore,ebp
    jne    Branch580
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x24
    call   DWORD PTR [edx]
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ebp
    mov    BYTE PTR [esp+0x1530],0x2
    je     Branch578
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializeSerializedByteStore
    jmp    Branch579
  Branch578:
    xor    eax,eax
  Branch579:
    mov    BYTE PTR [esp+0x1530],0x0
    mov    ds:R6GameServiceAddresses::GPrivateSerializedStore,eax
  Branch580:
    cmp    DWORD PTR ds:0x10091e50,ebp
    jne    Branch583
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0xc
    call   DWORD PTR [edx]
    mov    DWORD PTR [esp+0x10],eax
    cmp    eax,ebp
    mov    BYTE PTR [esp+0x1530],0x3
    je     Branch581
    mov    ecx,eax
    call   R6GameServiceAddresses::InitializePingRequestArray
    jmp    Branch582
  Branch581:
    xor    eax,eax
  Branch582:
    mov    BYTE PTR [esp+0x1530],0x0
    mov    ds:0x10091e50,eax
  Branch583:
    call   R6GameServiceAddresses::TailForwardServiceWrapperRegistration
    mov    edi,eax
    cmp    edi,ebp
    je     Branch594
    mov    ecx,R6GameServiceAddresses::GServiceString1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x34]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    lea    ecx,[ebx+0x1a0]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    lea    eax,[esp+0x134]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_sprintfSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x10
    cmp    eax,ebp
    je     Branch584
    lea    ecx,[esp+0x128]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextRemoteFileNameS
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x10
  Branch584:
    push   ebp
    push   R6GameServiceAddresses::ReportServiceDownload
    push   0x1
    lea    ecx,[esp+0x28]
    push   ecx
    lea    edx,[esp+0x138]
    push   edx
    push   edi
    mov    DWORD PTR ds:0x10091be8,ebp
    call   R6GameServiceAddresses::QueueServiceDownload
    push   edi
    call   R6GameServiceAddresses::ReleaseRegisteredServiceWrapper
    cmp    DWORD PTR ds:0x10091be8,ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::Core__appSprintfSlot
    je     Branch586
    lea    ecx,[esp+0x1c]
    push   R6GameServiceAddresses::WideTextR
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fopenSlot
    push   0x2
    mov    ebx,eax
    push   0x0
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fseekSlot
    push   ebx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_ftellSlot
    mov    edi,eax
    add    esp,0x18
    test   edi,edi
    mov    DWORD PTR [esp+0x14],edi
    push   ebx
    jg     Branch585
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fcloseSlot
    add    esp,0x4
    jmp    Branch594
  Branch585:
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_rewindSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    add    esp,0x4
    push   R6GameServiceAddresses::WideTextGAMESERVICE
    push   edi
    call   DWORD PTR [eax]
    mov    ecx,DWORD PTR [esp+0x14]
    push   ebx
    push   0x1
    mov    edi,eax
    push   ecx
    push   edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_freadSlot
    push   0x0
    lea    edx,[esp+0x23c]
    push   R6GameServiceAddresses::WideTextRouterIPI
    push   edx
    call   ebp
    add    esp,0x1c
    lea    eax,[esp+0x628]
    push   eax
    lea    ecx,[esp+0x22c]
    push   ecx
    call   esi
    add    esp,0x4
    push   eax
    push   edi
    call   R6GameServiceAddresses::ExtractLineValue
    push   ebx
    mov    edi,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_fcloseSlot
    add    esp,0x10
    test   edi,edi
    je     Branch586
    mov    edi,DWORD PTR [esp+0x18]
    add    edi,0x1e8
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_removeSlot
    add    esp,0x8
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    push   eax
    lea    edx,[esp+0x24]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_renameSlot
    add    esp,0xc
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x14],ebx
    jmp    Branch588
  Branch586:
    lea    eax,[esp+0x1c]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_removeSlot
    add    esp,0x4
    xor    ebx,ebx
    mov    DWORD PTR [esp+0x14],ebx
    jmp    Branch588
  Branch587:
    mov    ebx,DWORD PTR [esp+0x14]
  Branch588:
    push   ebx
    lea    ecx,[esp+0xd2c]
    push   R6GameServiceAddresses::WideTextRouterIPI
    push   ecx
    call   ebp
    push   ebx
    lea    edx,[esp+0x938]
    push   R6GameServiceAddresses::WideTextRouterPortI2
    push   edx
    call   ebp
    push   ebx
    lea    eax,[esp+0x1144]
    push   R6GameServiceAddresses::WideTextRouterLauncherPortI2
    push   eax
    call   ebp
    mov    edi,DWORD PTR [esp+0x3c]
    add    edi,0x1e8
    add    esp,0x24
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    lea    ecx,[esp+0x30]
    push   ecx
    lea    edx,[esp+0xd34]
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   edx
    call   esi
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::TextServers
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetPrivateProfileStringASlot
    xor    ecx,ecx
    cmp    ecx,eax
    lea    edx,[esp+0x28]
    sbb    ebx,ebx
    push   edx
    neg    ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   eax
    lea    eax,[esp+0xb30]
    push   R6GameServiceAddresses::WideTextTextFormat
    push   eax
    call   ebp
    add    esp,0x10
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    lea    ecx,[esp+0x30]
    push   ecx
    lea    edx,[esp+0x934]
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   edx
    call   esi
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::TextServers
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetPrivateProfileStringASlot
    xor    ecx,ecx
    cmp    ecx,eax
    sbb    edx,edx
    lea    eax,[esp+0x28]
    neg    edx
    push   eax
    and    ebx,edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   eax
    lea    ecx,[esp+0x730]
    push   R6GameServiceAddresses::WideTextTextFormat
    push   ecx
    call   ebp
    add    esp,0x10
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    lea    edx,[esp+0x30]
    push   edx
    lea    eax,[esp+0x1134]
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::TextServers
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetPrivateProfileStringASlot
    xor    ecx,ecx
    cmp    ecx,eax
    sbb    edx,edx
    lea    eax,[esp+0x28]
    neg    edx
    push   eax
    and    ebx,edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    push   eax
    lea    ecx,[esp+0x430]
    push   R6GameServiceAddresses::WideTextTextFormat
    push   ecx
    call   ebp
    add    esp,0x10
    test   ebx,ebx
    je     Branch590
    push   0x108
    push   0x1
    mov    ecx,R6GameServiceAddresses::GServiceArray1
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    mov    edi,eax
    imul   edi,edi,0x108
    lea    ecx,[esp+0x428]
    lea    eax,[edi+edx*1]
    push   ecx
    mov    DWORD PTR [esp+0x14],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appAtoiSlot
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edx+0x104],eax
    mov    eax,ds:R6GameServiceAddresses::GServiceArray1
    lea    edx,[esp+0x72c]
    lea    ecx,[edi+eax*1]
    push   edx
    mov    DWORD PTR [esp+0x18],ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appAtoiSlot
    mov    ecx,DWORD PTR [esp+0x18]
    lea    edx,[esp+0xb30]
    push   edx
    mov    DWORD PTR [ecx+0x100],eax
    call   esi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    add    esp,0xc
    add    ecx,edi
    jmp    Branch589
    lea    ecx,[ecx+0x0]
  Branch589:
    mov    dl,BYTE PTR [eax]
    inc    eax
    mov    BYTE PTR [ecx],dl
    inc    ecx
    test   dl,dl
    jne    Branch589
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch590
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    lea    eax,[edi+edx*1]
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    edx,DWORD PTR [ecx]
    push   eax
    push   R6GameServiceAddresses::WideTextRouterNameS
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    eax,ds:R6GameServiceAddresses::GServiceArray1
    mov    ecx,DWORD PTR [edi+eax*1+0x104]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextRouterLauncherPortI
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GServiceArray1
    mov    edx,DWORD PTR [edi+ecx*1+0x100]
    mov    eax,ds:R6GameServiceAddresses::Core__GLogSlot
    mov    ecx,DWORD PTR [eax]
    push   edx
    push   R6GameServiceAddresses::WideTextRouterPortI
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x28
  Branch590:
    mov    ecx,DWORD PTR [esp+0x14]
    inc    ecx
    test   ebx,ebx
    mov    DWORD PTR [esp+0x14],ecx
    jne    Branch587
    lea    edx,[esp+0xf28]
    push   R6GameServiceAddresses::WideTextCDKeyServerIP0
    push   edx
    call   ebp
    lea    eax,[esp+0x1330]
    push   R6GameServiceAddresses::WideTextCDKeyServerPort0
    push   eax
    call   ebp
    mov    ebp,DWORD PTR [esp+0x28]
    lea    edi,[ebp+0x1e8]
    add    esp,0x10
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    push   0x10091c28
    lea    ecx,[esp+0xf34]
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   ecx
    call   esi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetPrivateProfileStringASlot
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::TextServers
    call   ebx
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    lea    edx,[esp+0x30]
    push   edx
    lea    eax,[esp+0x1334]
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   R6GameServiceAddresses::TextServers
    call   ebx
    lea    ecx,[esp+0x28]
    push   ecx
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCR71_atoiSlot
    mov    ds:0x10091c04,eax
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    add    esp,0x4
    test   eax,eax
    je     Branch591
    push   0x10091c28
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    push   eax
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextCDKeyNameS
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    mov    ecx,DWORD PTR ds:0x10091c04
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    eax,DWORD PTR [edx]
    push   ecx
    push   R6GameServiceAddresses::WideTextCDKeyPortI
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x1c
  Branch591:
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   esi
    add    esp,0x4
    push   eax
    push   0x100
    lea    ecx,[esp+0x30]
    push   ecx
    push   R6GameServiceAddresses::GEmptyWideTextAlternate
    push   R6GameServiceAddresses::TextGS4UserAccountURL
    push   R6GameServiceAddresses::TextMaintenance
    call   ebx
    test   eax,eax
    jbe    Branch592
    lea    edx,[esp+0x28]
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appFromAnsiSlot
    add    esp,0x4
    push   eax
    lea    ecx,[ebp+0x1d0]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot2
  Branch592:
    mov    eax,ds:R6GameServiceAddresses::GServiceVerboseLogging
    test   eax,eax
    je     Branch593
    sub    esp,0xc
    add    ebp,0x1d0
    mov    ecx,DWORD PTR [ebp+0x0]
    mov    edx,DWORD PTR [ebp+0x4]
    mov    eax,esp
    mov    DWORD PTR [eax],ecx
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [eax+0x4],edx
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GLogSlot
    mov    DWORD PTR [eax+0x8],ecx
    mov    eax,DWORD PTR [edx]
    push   R6GameServiceAddresses::WideTextMSzUbiHomePageS
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FOutputDevice_LogfSlot
    add    esp,0x14
  Branch593:
    mov    eax,ds:R6GameServiceAddresses::GServiceArray1+0x4
    xor    ecx,ecx
    test   eax,eax
    setg   cl
    mov    DWORD PTR ds:R6GameServiceAddresses::GMSRouterIndex,0x0
    mov    DWORD PTR ds:R6GameServiceAddresses::GMSClientInitialized,ecx
  Branch594:
    lea    ecx,[esp+0x1538]
    mov    DWORD PTR [esp+0x1530],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne    Branch595
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch595:
    mov    eax,ds:R6GameServiceAddresses::GMSClientInitialized
    test   eax,eax
    jne    Branch596
    sub    esp,0xc
    mov    ecx,esp
    mov    DWORD PTR [ebp+0x8],esp
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_eventGetLocallyBoundIpAddr
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6GSServers_Init
  Branch596:
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
