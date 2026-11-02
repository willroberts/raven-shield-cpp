#include "native_addresses.h"
#include "native_records.h"

// Native lifetime maps for the selected 0x174-byte UR6ServerList object.
// R6GameService.dll data @ 1007b104 : destructor predecessor/action pairs.
const R6GameServiceNative::UnwindEntry UR6ServerList_UR6ServerListUnwindMap[8] = {
  {-1, R6GameServiceAddresses::UnwindServerListDestructorBase},
  {0, R6GameServiceAddresses::UnwindServerListDestructorFavorites},
  {1, R6GameServiceAddresses::UnwindServerListDestructorServers},
  {2, R6GameServiceAddresses::UnwindServerListDestructorValidResponses},
  {3, R6GameServiceAddresses::UnwindServerListDestructorModResponses},
  {4, R6GameServiceAddresses::UnwindServerListDestructorSortIndices},
  {5, R6GameServiceAddresses::UnwindServerListDestructorCurrentServer},
  {6, R6GameServiceAddresses::UnwindServerListDestructorVersion},
};
// R6GameService.dll data @ 1007b144 : destructor includes the trailing version string as state7.
// R6GameService.dll data @ 1007b104 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_UR6ServerListExceptionInfo = {
  0x19930520,
  8,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListUnwindMap,
  0,
  0,
  0,
  0,
};
// R6GameService.dll data @ 1007b160 : constructor predecessor/action pairs.
const R6GameServiceNative::UnwindEntry UR6ServerListSharedLifetimeUnwindMap[7] = {
  {-1, R6GameServiceAddresses::UnwindServerListConstructorBase},
  {0, R6GameServiceAddresses::UnwindServerListConstructorFavorites},
  {1, R6GameServiceAddresses::UnwindServerListConstructorServers},
  {2, R6GameServiceAddresses::UnwindServerListConstructorValidResponses},
  {3, R6GameServiceAddresses::UnwindServerListConstructorModResponses},
  {4, R6GameServiceAddresses::UnwindServerListConstructorSortIndices},
  {5, R6GameServiceAddresses::UnwindServerListConstructorCurrentServer},
};
// R6GameService.dll data @ 1007b198 : default/copy constructor share seven cleanup states.
// R6GameService.dll data @ 1007b160 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerListSharedLifetimeExceptionInfo = {
  0x19930520,
  7,
  R6GameServiceAddresses::UR6ServerListSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Returns the selected UR6ServerList class object.
// R6GameService.dll @ 10001380 : complete native control/access order and raw ABI retained.
UClass * __cdecl UR6ServerList::StaticClass(void)
{
  return reinterpret_cast<UClass *>(0x10092410);
}

// Allocates through StaticAllocateObject with this class, current GError, supplied outer/name/flags and zero optional arguments.
// R6GameService.dll @ 10001390 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl UR6ServerList::operator new(uint allocationSize,UObject *outer,FName name,ulong flags)
{
  __asm {
    // The requested allocation-size word is not read; outer/name/flags cache before the imported allocation call.
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
    push   0x10092410
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_StaticAllocateObjectSlot
    add    esp,0x20
    ret
  }
}

// Assigns the base, scalars, five reflected flag bits, five arrays, server record and version string in native order.
// R6GameService.dll @ 10003780 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ServerList * __thiscall UR6ServerList::operator=(UR6ServerList *object,const UR6ServerList *source)
{
  __asm {
    // Source flags reload for each bit; no class-level self guard or EH/rollback is added.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   edi
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::R6Abstract__4UR6AbstractGameServiceSlot
    mov    eax,DWORD PTR [edi+0x40]
    mov    edx,DWORD PTR [esi+0x48]
    mov    DWORD PTR [esi+0x40],eax
    mov    ecx,DWORD PTR [edi+0x44]
    mov    DWORD PTR [esi+0x44],ecx
    xor    edx,DWORD PTR [edi+0x48]
    mov    eax,DWORD PTR [esi+0x48]
    and    edx,0x1
    xor    eax,edx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,eax
    mov    eax,DWORD PTR [edi+0x48]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,DWORD PTR [edi+0x48]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x48],ecx
    mov    eax,DWORD PTR [edi+0x48]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,DWORD PTR [edi+0x48]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x48],ecx
    mov    edx,DWORD PTR [edi+0x4c]
    lea    eax,[edi+0x50]
    push   eax
    lea    ecx,[esi+0x50]
    mov    DWORD PTR [esi+0x4c],edx
    call   R6GameServiceAddresses::CopyFStringArray
    lea    ecx,[edi+0x5c]
    push   ecx
    lea    ecx,[esi+0x5c]
    call   R6GameServiceAddresses::AssignSTGameServerArray
    lea    edx,[edi+0x68]
    push   edx
    lea    ecx,[esi+0x68]
    call   R6GameServiceAddresses::CopySevenWordRecordArray
    lea    eax,[edi+0x74]
    push   eax
    lea    ecx,[esi+0x74]
    call   R6GameServiceAddresses::CopySevenWordRecordArray
    lea    ecx,[edi+0x80]
    push   ecx
    lea    ecx,[esi+0x80]
    call   R6GameServiceAddresses::CopyDwordArray
    lea    edx,[edi+0x8c]
    push   edx
    lea    ecx,[esi+0x8c]
    call   R6GameServiceAddresses::AssignSTGameServer
    add    edi,0x168
    push   edi
    lea    ecx,[esi+0x168]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Installs the class vtable, calls ConditionalDestroy, then destroys members and base under exact eight-state cleanup.
// R6GameService.dll @ 10003ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::~UR6ServerList(UR6ServerList *object)
{
  __asm {
    // ConditionalDestroy result is ignored; cached object survives callbacks; final base destruction runs in state-1.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectServerListDestructorInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ServerListDispatchTable
    mov    DWORD PTR [esp+0x10],0x7
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot
    lea    ecx,[esi+0x168]
    mov    BYTE PTR [esp+0x10],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x8c]
    mov    BYTE PTR [esp+0x10],0x5
    call   R6GameServiceAddresses::DestroySTGameServer
    lea    ecx,[esi+0x80]
    mov    BYTE PTR [esp+0x10],0x4
    call   R6GameServiceAddresses::DestroyArrayStorage
    lea    ecx,[esi+0x74]
    mov    BYTE PTR [esp+0x10],0x3
    call   R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage
    lea    ecx,[esi+0x68]
    mov    BYTE PTR [esp+0x10],0x2
    call   R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage
    lea    ecx,[esi+0x5c]
    mov    BYTE PTR [esp+0x10],0x1
    call   R6GameServiceAddresses::DestroyArrayDCByteElements
    lea    ecx,[esi+0x50]
    mov    BYTE PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::DestroyFStringArray
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::R6Abstract__DestroyUR6AbstractGameServiceSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Constructs the base, installs the class vtable, then constructs the embedded server and trailing no-init version string.
// R6GameService.dll @ 10003ba0 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ServerList * __thiscall UR6ServerList::UR6ServerList(UR6ServerList *object)
{
  __asm {
    // State0 precedes the vtable store, then byte state5 arms untouched arrays; no scalar/array initialization is invented.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectServerListConstructorInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    call   DWORD PTR ds:R6GameServiceAddresses::R6Abstract__ConstructUR6AbstractGameServiceSlot2
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ServerListDispatchTable
    lea    ecx,[esi+0x8c]
    mov    BYTE PTR [esp+0x10],0x5
    call   R6GameServiceAddresses::ConstructServerInfo
    lea    ecx,[esi+0x168]
    mov    BYTE PTR [esp+0x10],0x6
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Copy-constructs base, selective flags, scalars, arrays, embedded server and trailing string under seven-state cleanup.
// R6GameService.dll @ 10003c10 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ServerList * __thiscall UR6ServerList::UR6ServerList(UR6ServerList *object,const UR6ServerList *source)
{
  __asm {
    // State stays-1 across base return and early scalar/flag accesses; state0 precedes publishing object+4c.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectServerListConstructorInfo
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
    call   DWORD PTR ds:R6GameServiceAddresses::R6Abstract__ConstructUR6AbstractGameServiceSlot
    mov    edx,DWORD PTR [esi+0x48]
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ServerListDispatchTable
    mov    eax,DWORD PTR [edi+0x40]
    mov    DWORD PTR [esi+0x40],eax
    mov    ecx,DWORD PTR [edi+0x44]
    mov    DWORD PTR [esi+0x44],ecx
    xor    edx,DWORD PTR [edi+0x48]
    mov    eax,DWORD PTR [esi+0x48]
    and    edx,0x1
    xor    eax,edx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,eax
    mov    eax,DWORD PTR [edi+0x48]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,DWORD PTR [edi+0x48]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x48],ecx
    mov    eax,DWORD PTR [edi+0x48]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x48],eax
    mov    ecx,DWORD PTR [edi+0x48]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x48],ecx
    mov    edx,DWORD PTR [edi+0x4c]
    lea    eax,[edi+0x50]
    lea    ecx,[esi+0x50]
    push   eax
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esi+0x4c],edx
    call   R6GameServiceAddresses::ConstructFStringArray
    lea    edx,[edi+0x5c]
    lea    ecx,[esi+0x5c]
    push   edx
    mov    BYTE PTR [esp+0x18],0x1
    call   R6GameServiceAddresses::CopyConstructSTGameServerArray
    lea    eax,[edi+0x68]
    lea    ecx,[esi+0x68]
    push   eax
    mov    BYTE PTR [esp+0x18],0x2
    call   R6GameServiceAddresses::ConstructSevenWordRecordArray
    lea    edx,[edi+0x74]
    lea    ecx,[esi+0x74]
    push   edx
    mov    BYTE PTR [esp+0x18],0x3
    call   R6GameServiceAddresses::ConstructSevenWordRecordArray
    lea    eax,[edi+0x80]
    lea    ecx,[esi+0x80]
    push   eax
    mov    BYTE PTR [esp+0x18],0x4
    call   R6GameServiceAddresses::ConstructDwordArray
    lea    ecx,[edi+0x8c]
    push   ecx
    lea    ecx,[esi+0x8c]
    mov    BYTE PTR [esp+0x18],0x5
    call   R6GameServiceAddresses::CopyConstructSTGameServer
    mov    BYTE PTR [esp+0x14],0x6
    add    edi,0x168
    push   edi
    lea    ecx,[esi+0x168]
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

// Destroys one object or a cookie-counted array and optionally frees it, returning object or array-cookie address.
// R6GameService.dll @ 10003d40 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteUR6ServerList(UR6ServerList *object,uint flags)
{
  __asm {
    // Caches low flag byte first: mask2 selects vector path, mask1 selects free; iterator/allocator failure has no local rollback.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je    Branch2
    mov    eax,DWORD PTR [esi-0x4]
    push   edi
    push   R6GameServiceAddresses::UR6ServerList__UR6ServerList
    lea    edi,[esi-0x4]
    push   eax
    push   0x174
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
    call   R6GameServiceAddresses::UR6ServerList__UR6ServerList
    test   bl,0x1
    je    Branch3
    push   0x174
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

// Returns for null storage or tail-forwards the current storage pointer to the default constructor.
// R6GameService.dll @ 100042e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ServerList::InternalConstructor(void *objectMemory)
{
  __asm {
    // The cdecl argument slot stays on the caller stack; null preserves incoming EAX rather than manufacturing a result.
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je    Branch4
    jmp    R6GameServiceAddresses::UR6ServerList_UR6ServerList
  Branch4:
    ret
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its Base subobject.
// R6GameService.dll @ 10063340 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorBase(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::R6Abstract__DestroyUR6AbstractGameServiceSlot
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its Favorites subobject.
// R6GameService.dll @ 10063349 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorFavorites(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x50
    jmp    R6GameServiceAddresses::ForwardArrayDestroy
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its Servers subobject.
// R6GameService.dll @ 10063354 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorServers(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x5c
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy3
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its ValidResponses subobject.
// R6GameService.dll @ 1006335f : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorValidResponses(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x68
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its ModResponses subobject.
// R6GameService.dll @ 1006336a : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorModResponses(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x74
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its SortIndices subobject.
// R6GameService.dll @ 10063375 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorSortIndices(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x80
    jmp    R6GameServiceAddresses::ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its CurrentServer subobject.
// R6GameService.dll @ 10063383 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorCurrentServer(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8c
    jmp    R6GameServiceAddresses::DestroySTGameServer
  }
}

// Reloads the saved server-list receiver and forwards destructor cleanup for its Version subobject.
// R6GameService.dll @ 10063391 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListDestructorVersion(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x168
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its Base subobject.
// R6GameService.dll @ 100633b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorBase(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::R6Abstract__DestroyUR6AbstractGameServiceSlot
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its Favorites subobject.
// R6GameService.dll @ 100633b9 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorFavorites(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x50
    jmp    R6GameServiceAddresses::ForwardArrayDestroy
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its Servers subobject.
// R6GameService.dll @ 100633c4 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorServers(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x5c
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy3
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its ValidResponses subobject.
// R6GameService.dll @ 100633cf : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorValidResponses(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x68
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its ModResponses subobject.
// R6GameService.dll @ 100633da : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorModResponses(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x74
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its SortIndices subobject.
// R6GameService.dll @ 100633e5 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorSortIndices(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x80
    jmp    R6GameServiceAddresses::ForwardToArrayDestructor
  }
}

// Reloads the saved server-list receiver and forwards constructor cleanup for its CurrentServer subobject.
// R6GameService.dll @ 100633f3 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindServerListConstructorCurrentServer(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; preserve native member offsets and destructor-tail targets.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8c
    jmp    R6GameServiceAddresses::DestroySTGameServer
  }
}

// Selects the eight-state UR6ServerList destructor FuncInfo and forwards the current C++ exception frame.
// R6GameService.dll @ 100633a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectServerListDestructorInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_UR6ServerListExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the shared seven-state default/copy constructor FuncInfo and forwards the current C++ exception frame.
// R6GameService.dll @ 10063401 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectServerListConstructorInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerListSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Dispatches a two-int event through the cached object table and copies both current parameter values back in order.
// R6GameService.dll @ 10001320 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::eventGetLobbyAndGroupID(UR6ServerList *object,int *lobbyID,int *groupID)
{
  __asm {
    // Local parameter words at entry-8/-4; group pointer caches before lobby pointer, both values load before lookup.
    sub    esp,0x8
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [edi]
    push   0x0
    mov    esi,ecx
    // Cache original object table before FindFunctionChecked; later object-table changes do not redirect this dispatch.
    mov    ecx,DWORD PTR [ebx]
    mov    ebp,DWORD PTR [esi]
    lea    edx,[esp+0x14]
    push   edx
    mov    DWORD PTR [esp+0x18],eax
    mov    eax,ds:0x10091e84
    push   0x0
    mov    DWORD PTR [esp+0x20],ecx
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_FindFunctionCheckedSlot
    // Use function result with staged parameter buffer/null result; preserve dispatcher raw EAX while copying outputs.
    push   eax
    mov    ecx,esi
    call   DWORD PTR [ebp+0x10]
    // Load both result words before either copy-back; lobby store precedes group store, including aliased references.
    mov    ecx,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x14]
    mov    DWORD PTR [edi],ecx
    pop    edi
    pop    esi
    pop    ebp
    mov    DWORD PTR [ebx],edx
    pop    ebx
    add    esp,0x8
    ret    0x8
  }
}

// Consumes the optional script bool token and writes the raw 32-bit GetTickCount result.
// Consume end token/optional DebugInfo42 through current VM object/table; preserve current result/global and exact guard/access order.
// R6GameService.dll @ 10005f20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeGetMilliSeconds(UR6ServerList *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSmallVMBridgeEH
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
    jne    Branch5
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch5:
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_GetTickCountSlot
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
// R6GameService.dll @ 10063800 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectSmallVMBridgeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_execNativeGetMilliSecondsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb18 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6ServerList_execNativeGetMilliSecondsUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb28 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGSmallVMBridgeEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch4},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch5},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb28 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6ServerList_execNativeGetMilliSecondsTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGSmallVMBridgeEH},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb18 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_execNativeGetMilliSecondsExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6ServerList_execNativeGetMilliSecondsUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6ServerList_execNativeGetMilliSecondsTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10005f8a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch4(void)
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
// R6GameService.dll @ 10006210 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeGetMaxPlayers(UR6ServerList *this,FFrame *stack,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ServerList_SelectSmallVMBridgeEH
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
    jne    Branch6
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch6:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x10
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Select exact two-state/no-action VM bridge typed/context catch metadata and tail CRT dispatch.
// R6GameService.dll @ 10063810 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ServerList_SelectSmallVMBridgeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_execNativeGetMaxPlayersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb78 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6ServerList_execNativeGetMaxPlayersUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb88 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGSmallVMBridgeEH5[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch6},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch7},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb88 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6ServerList_execNativeGetMaxPlayersTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGSmallVMBridgeEH5},
};

// Literal small VM bridge unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bb78 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_execNativeGetMaxPlayersExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6ServerList_execNativeGetMaxPlayersUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6ServerList_execNativeGetMaxPlayersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10006278 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch6(void)
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

// Store the full server-port word; raw EAX retains the supplied value.
// R6GameService.dll @ 100063a0 : virtual void export; unused ECX receiver, RET4; global/parameter names inferred.
void __thiscall UR6ServerList::SetOwnSvrPort(int port)
{
  *reinterpret_cast<int *>(0x10091bf4) = port;
}

// Advances past the parameter terminator, dispatches optional debug info on Stack.Object, then writes the port.
// R6GameService.dll @ 100063b0 : exported FFrame&/void* bridge; RET8, exact guard/cursor/access order retained.
// Frame offsets +8/+c are Object/Code; GNatives[0x42] and its receiver are read only on the debug-info path.
__declspec(naked) void __thiscall UR6ServerList::execNativeGetOwnSvrPort(FFrame &Stack, void * const Result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::SelectParentExceptionInfo
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
    jne    Branch7
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch7:
    mov    ecx,DWORD PTR ds:0x10091bf4
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

// Select UR6ServerList::execNativeGetOwnSvrPort native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063830 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl SelectParentExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execNativeGetOwnSvrPortExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bc38 : native storage identity retained.
const R6GameServiceNative::UnwindEntry execNativeGetOwnSvrPortUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bc48 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGParentExceptionInfo[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch8},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch9},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bc48 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeGetOwnSvrPortTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGParentExceptionInfo},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007bc38 : native storage identity retained.
const R6GameServiceNative::FuncInfo execNativeGetOwnSvrPortExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execNativeGetOwnSvrPortUnwindMap,
  0x1,
  R6GameServiceAddresses::execNativeGetOwnSvrPortTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000641a : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch8(void)
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

// Reset public then current private shared store, ignoring both native status words.
// Exported nonvirtual void(void), incoming ECX unused, RET0; public owner loads before state0 publication.
// Private owner reloads after the first reset returns. The guard owns no resource action or rollback.
// R6GameService.dll @ 10007710 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::ResetSvrContainer(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ServerList_ResetSvrContainerSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::ResetSerializedByteStore
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    call   R6GameServiceAddresses::ResetSerializedByteStore
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

// Copy the caught unsigned-short pointer through parent scratch, then throw it without touching its pointee.
// Private inherited EBP: input-0x18/scratch-0x14, no own frame, guard or normal return.
// R6GameService.dll @ 1000775f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch10(void)
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

// Report ResetSvrContainer context, then forward null object/type words to C++ rethrow.
// Private inherited-frame entry; current reporting/throw imports, no local guard or normal return.
// R6GameService.dll @ 10007773 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch11(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListResetSvrContainer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select shared-store reset metadata and tail-enter the imported CRT frame handler.
// R6GameService.dll @ 10063990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ServerList_ResetSvrContainerSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_ResetSvrContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native lobby-registration/reset unwind record; addresses and states are literal.
// R6GameService.dll data @ 1007c188 : native storage identity retained.
const R6GameServiceNative::UnwindEntry UR6ServerList_ResetSvrContainerUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Native lobby-registration/reset handlers record; addresses and states are literal.
// R6GameService.dll data @ 1007c198 : native storage identity retained.
const R6GameServiceNative::CatchHandler GResetSvrContainerHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch10},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch11},
};

// Native lobby-registration/reset try record; addresses and states are literal.
// R6GameService.dll data @ 1007c198 : native storage identity retained.
const R6GameServiceNative::TryBlock UR6ServerList_ResetSvrContainerTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GResetSvrContainerHandlers},
};

// Native lobby-registration/reset info record; addresses and states are literal.
// R6GameService.dll data @ 1007c188 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_ResetSvrContainerExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6ServerList_ResetSvrContainerUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6ServerList_ResetSvrContainerTryMap,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007c518 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry InitFavoritesUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::InitFavoritesUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007c530 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GMSClientFavoritesHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch12},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch13},
};
// R6GameService.dll data @ 1007c550 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock InitFavoritesTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GMSClientFavoritesHandlers},
};
// R6GameService.dll data @ 1007c564 : selected guard/cleanup records.
// R6GameService.dll data @ 1007c518 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitFavoritesExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::InitFavoritesUnwindMap,
  0x1,
  R6GameServiceAddresses::InitFavoritesTryMap,
  0x0,
  0x0,
};

// Appends successive Favorites/favServerN strings to the existing array until the first zero config result.
// R6GameService.dll @ 10008730 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::InitFavorites(UR6ServerList *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::InitFavoritesSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x3c
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6ServerList* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  *reinterpret_cast<UR6ServerList**>(nativeFrame - 0x14) = receiver;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  FString* value = reinterpret_cast<FString*>(nativeFrame - 0x28);
  FString::FString(value);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
  uint index = 0;
  int found;
  do {
    char* key = reinterpret_cast<char*>(nativeFrame - 0x48);
    sprintf(key, reinterpret_cast<const char*>(R6GameServiceAddresses::TextFavServerI), index);
    const TCHAR* wideKey = appFromAnsi(key);
    found = GConfig->GetString(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextFavorites),
        wideKey, *value, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextUser));
    if (found) {
      // Saved owner and current storage are reloaded after configuration; appends survive assignment failure.
      byte* currentOwner = *reinterpret_cast<byte**>(nativeFrame - 0x14);
      FArray* favorites = reinterpret_cast<FArray*>(currentOwner + 0x50);
      const int added = favorites->AddZeroed(12, 1);
      FString* data = *reinterpret_cast<FString**>(favorites);
      data[added] = *value;
    }
    ++index; // DWORD wrap, including the final missing key. No array reset or duplicate suppression.
  } while (found);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
  FString::~FString(value);
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

// Copies the caught unsigned-short pointer from parent EBP-0x1c to-0x18 and throws it by value.
// R6GameService.dll @ 100087f6 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch12(void)
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

// Reports the native execNativeInitFavorites label for InitFavorites, then rethrows the active exception.
// R6GameService.dll @ 1000880a : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch13(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeInitFavorites
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the completed config-value FString at parent EBP-0x28, without rolling back array appends.
// R6GameService.dll @ 10063ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitFavoritesUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x28]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state InitFavorites value-string ownership and guard map.
// R6GameService.dll @ 10063ab9 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitFavoritesSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitFavoritesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finish the VM argument list, dispatch optional debug token42, then append favorites through the actual native loader.
// Preserve saved owner, nested guard and raw final loader EAX; the script result pointer is unused.
// R6GameService.dll @ 10008830 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeInitFavorites(FFrame &frame,void *result)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectInitFavoritesBridgeEH
    mov    eax,fs:0x0
    push    eax
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
  UR6ServerList* receiver;
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
  receiver->InitFavorites();
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

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10008898 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch14(void)
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

// Empty Favorites/User, then store each live array value under favServer%i without a native flush.
// Keep signed current count/storage, value pointer captured before key conversion, current config and raw final EAX.
// The native epilogue follows separate catch entries; those entries remain canonical outside this parent body.
// R6GameService.dll @ 100088d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeUpdateFavorites(FFrame &frame,void *result)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectUpdateFavoritesBridgeEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x2c
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6ServerList* receiver;
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
  const TCHAR* section = reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextFavorites);
  const TCHAR* filename = reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextUser);
  GConfig->EmptySection(section, filename);
  byte* list = reinterpret_cast<byte*>(receiver);
  uint index = 0;
  while (static_cast<int>(index) < *reinterpret_cast<int*>(list + 0x54)) {
    char* key = reinterpret_cast<char*>(nativeFrame - 0x38);
    sprintf(key, reinterpret_cast<const char*>(R6GameServiceAddresses::TextFavServerI), index);
    FString* favorites = *reinterpret_cast<FString**>(list + 0x50);
    const TCHAR* value = *favorites[index]; // Capture before key conversion; it can invalidate this borrowed pointer.
    const TCHAR* wideKey = appFromAnsi(key);
    GConfig->SetString(section, wideKey, value, filename); // Current config and virtual slot, without an explicit flush.
    ++index;
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

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 10008989 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch16(void)
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

// Decode sort type/full ascending DWORD, reset m_GSLSortIdx when its Num equals m_GameServerList.Num, then bubble-sort indices.
// Cases0..3: favorite/password/dedicated/PunkBuster bits;4 ping,5 name,6 game type,7 adversarial,8 map,9 player count.
// Ascending0 swaps numeric/text left<right; nonzero swaps numeric left>right but text left>=right (ties reverse).
// Keep captured count, current array bases, right-then-left string reads, exact split swap stores and untouched VM result.
// R6GameService.dll @ 100089d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execSortServers(UR6ServerList *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ServerList_SelectParentExceptionInfo
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
  UR6ServerList* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  FFrame* executionStack = *reinterpret_cast<FFrame**>(nativeFrame + 8);
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  int& sortType = *reinterpret_cast<int*>(nativeFrame - 0x20);
  uint& ascending = *reinterpret_cast<uint*>(nativeFrame - 0x1c);
  sortType = 0;
  const byte typeOpcode = *code++;
  using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
  ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
  UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  natives[typeOpcode](context, executionStack, &sortType);
  byte* ascendingCode = code;
  context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
  ascending = 0;
  const byte ascendingOpcode = *ascendingCode;
  code = ascendingCode + 1;
  natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
  natives[ascendingOpcode](context, executionStack, &ascending);
  byte* next = code + 1;
  code = next;
  if (*next == 0x42) {
    context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
    code = next + 1;
    natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
    natives[0x42](context, executionStack, nullptr);
  }
  byte* list = reinterpret_cast<byte*>(receiver);
  int& count = *reinterpret_cast<int*>(nativeFrame - 0x14);
  count = *reinterpret_cast<int*>(list + 0x60);
  if (count != *reinterpret_cast<int*>(list + 0x84)) {
    GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextErrorMGameServerListNumMGSLSortIdxNum));
  } else {
    for (uint i = 0; static_cast<int>(i) < count; ++i)
      (*reinterpret_cast<uint**>(list + 0x80))[i] = i;
    const uint kind = static_cast<uint>(sortType); // Dispatch once, after resetting every index.
    if (kind > 9) {
      GLog->Logf(reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextErrorSortTypeIsNotDefine));
    } else {
      uint& pass = *reinterpret_cast<uint*>(nativeFrame + 8); // Native reuses the incoming frame slot.
      pass = 0;
      while (static_cast<int>(pass) < static_cast<int>(static_cast<uint>(count) - 1U)) {
        uint pair = 0;
        while (static_cast<int>(pair) < static_cast<int>(static_cast<uint>(count) - pass - 1U)) {
          const bool ascendingNow = ascending != 0;
          bool swapPair;
          if (kind == 4 || kind == 9) {
            uint* indices = *reinterpret_cast<uint**>(list + 0x80);
            const uint rightIndex = indices[pair + 1];
            uint leftIndex;
            byte* records;
            if (ascendingNow) {
              records = *reinterpret_cast<byte**>(list + 0x5c);
              leftIndex = indices[pair];
            } else {
              leftIndex = indices[pair];
              records = *reinterpret_cast<byte**>(list + 0x5c);
            }
            const uint offset = kind == 4 ? 0xc : 0x78;
            const int left = *reinterpret_cast<int*>(records + leftIndex * 0xdcU + offset);
            const int right = *reinterpret_cast<int*>(records + rightIndex * 0xdcU + offset);
            swapPair = ascendingNow ? left > right : left < right;
          } else if (kind == 5 || kind == 6 || kind == 8) {
            *reinterpret_cast<uint*>(nativeFrame - 0x18) = pair;
            uint* indices = *reinterpret_cast<uint**>(list + 0x80);
            const uint leftIndex = indices[pair];
            uint rightIndex;
            byte* records;
            if (ascendingNow) {
              records = *reinterpret_cast<byte**>(list + 0x5c);
              rightIndex = indices[pair + 1];
            } else {
              rightIndex = indices[pair + 1];
              records = *reinterpret_cast<byte**>(list + 0x5c);
            }
            const uint offset = kind == 5 ? 0x5c : kind == 6 ? 0x88 : 0x94;
            FString* leftString = reinterpret_cast<FString*>(records + leftIndex * 0xdcU + offset);
            FString* rightString = reinterpret_cast<FString*>(records + rightIndex * 0xdcU + offset);
            const TCHAR* right = **rightString; // Right dereference runs first; both object addresses were captured.
            if (ascendingNow) *reinterpret_cast<const TCHAR**>(nativeFrame - 0x18) = right;
            const TCHAR* left = **leftString;
            if (ascendingNow) right = *reinterpret_cast<const TCHAR**>(nativeFrame - 0x18);
            const int comparison = appStricmp(left, right);
            if (!ascendingNow) pair = *reinterpret_cast<uint*>(nativeFrame - 0x18);
            swapPair = ascendingNow ? comparison >= 0 : comparison < 0;
          } else {
            const uint offset = kind == 0 ? 0x28 : (kind == 1 || kind == 2) ? 0x38 : 0x4c;
            const uint mask = kind == 0 ? 4 : kind == 1 ? 1 : kind == 2 ? 2 : kind == 3 ? 0x400 : 0x40;
            uint* indices = *reinterpret_cast<uint**>(list + 0x80);
            const uint leftIndex = indices[pair];
            byte* records = *reinterpret_cast<byte**>(list + 0x5c);
            byte* leftField = records + leftIndex * 0xdcU + offset;
            const bool left = kind == 3 ? (*reinterpret_cast<uint*>(leftField) & mask) != 0 : (*leftField & mask) != 0;
            swapPair = false;
            // The right index and field are not accessed when the left bit already rules out a swap.
            if (ascendingNow ? !left : left) {
              const uint rightIndex = indices[pair + 1];
              byte* rightField = records + rightIndex * 0xdcU + offset;
              const bool right = kind == 3 ? (*reinterpret_cast<uint*>(rightField) & mask) != 0 : (*rightField & mask) != 0;
              swapPair = ascendingNow ? right : !right;
            }
          }
          if (swapPair) {
            uint* indices = *reinterpret_cast<uint**>(list + 0x80);
            const uint left = indices[pair];
            const uint right = indices[pair + 1];
            indices[pair] = right;
            // Preserve the separate current-base reload and partially committed first store.
            (*reinterpret_cast<uint**>(list + 0x80))[pair + 1] = left;
          }
          ++pair;
        }
        ++pass;
      }
    }
  }
  // Numeric/bit ties do not swap; ascending text ties swap, so sorting is not generally stable.
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

// Native switch targets for sort categories0..9; the parent owns these blocks.
// R6GameService.dll data @ 100092f4 : native storage identity retained.
const uint GSortServerCases[10] = {
  R6GameServiceAddresses::GSortServerCasesCase1,R6GameServiceAddresses::GSortServerCasesCase2,R6GameServiceAddresses::GSortServerCasesCase3,R6GameServiceAddresses::GSortServerCasesCase4,R6GameServiceAddresses::GSortServerCasesCase5,
  R6GameServiceAddresses::GSortServerCasesCase6,R6GameServiceAddresses::GSortServerCasesCase7,R6GameServiceAddresses::GSortServerCasesCase8,R6GameServiceAddresses::GSortServerCasesCase9,R6GameServiceAddresses::GSortServerCasesCase10
};

// Select UR6ServerList::execSortServers native lifetime/catch records; keep inherited frame/stack for CRT dispatch.
// R6GameService.dll @ 10063af0 : MOV FuncInfo/tail CRT selector; descriptive compiler-entry name.
__declspec(naked) void __cdecl UR6ServerList_SelectParentExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execSortServersExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c640 : native storage identity retained.
const R6GameServiceNative::UnwindEntry execSortServersUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c650 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGParentExceptionInfo5[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -40,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch18},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch19},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c650 : native storage identity retained.
const R6GameServiceNative::TryBlock execSortServersTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGParentExceptionInfo5},
};

// Literal parent unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007c640 : native storage identity retained.
const R6GameServiceNative::FuncInfo execSortServersExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execSortServersUnwindMap,
  0x1,
  R6GameServiceAddresses::execSortServersTryMap,
  0x0,
  0x0,
};

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 100092c1 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch18(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x28]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x24]
    push   ecx
    mov    DWORD PTR [ebp-0x24],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll data @ 1007c708 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry execGetDisplayListSizeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007c718 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler GIDDisplayHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch20},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch21},
};
// R6GameService.dll data @ 1007c738 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock execGetDisplayListSizeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::GIDDisplayHandlers},
};
// R6GameService.dll data @ 1007c74c : selected guard/cleanup records.
// R6GameService.dll data @ 1007c708 : native storage identity retained.
const R6GameServiceNative::FuncInfo execGetDisplayListSizeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execGetDisplayListSizeUnwindMap,
  0x1,
  R6GameServiceAddresses::execGetDisplayListSizeTryMap,
  0x0,
  0x0,
};

// Finishes the script token and counts bDisplay in live server-list storage, reloading count/data each iteration.
// R6GameService.dll @ 10009580 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execGetDisplayListSize
    (UR6ServerList *this,FFrame *frame,int *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::execGetDisplayListSizeSelectExceptionInfo
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
  UR6ServerList* receiver;
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
  byte* list = reinterpret_cast<byte*>(receiver);
  uint displayed = 0;
  for (uint index = 0; static_cast<int>(index) < *reinterpret_cast<int*>(list + 0x60); ++index) {
    byte* servers = *reinterpret_cast<byte**>(list + 0x5c);
    if (*(servers + index * 0xdcU + 0x28) & 2) ++displayed;
  }
  uint* output = *reinterpret_cast<uint**>(nativeFrame + 0xc);
  *output = displayed; // Count bDisplay in server storage; this does not count or rewrite the sort-index array.
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
// R6GameService.dll @ 100095ee : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch20(void)
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

// Reports execGetDisplayListSize guard context and rethrows the active exception.
// R6GameService.dll @ 10009602 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch21(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecGetDisplayListSize
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the two-state display-count guard, with no owned local cleanup.
// R6GameService.dll @ 10063b20 : complete native control/access order and raw ABI retained.
__declspec(naked) void execGetDisplayListSizeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execGetDisplayListSizeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Publish mod/server fields and current map/player arrays into the two current stored-data containers.
// Preserve full four-byte flag expressions, signed live counts, per-field pointer reloads and ignored write statuses.
// Keyword/format share EBP-0x30; mod name uses EBP-0x24. ANSI target is cached only before array iteration.
// R6GameService.dll @ 1000a3b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::FillSvrContainer(void)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectFillContainerEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x24
    push    ebx
    push    esi
    push    edi
    mov    esi,ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[ebp-0x30]
    mov    DWORD PTR [ebp-0x10],esp
    push    eax
    mov    DWORD PTR [ebp-0x4],0x0
    call    DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetModKeywordSlot
    mov    ecx,eax
    mov    BYTE PTR [ebp-0x4],0x1
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    push    eax
    call    edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    add    esp,0x4
    push    eax
    push    0xfd
    call    R6GameServiceAddresses::WriteStoredAnsiText
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],0x0
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[ebp-0x24]
    push    edx
    call    DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetModNameSlot
    mov    bl,0x2
    mov    ecx,R6GameServiceAddresses::GServiceString3
    mov    BYTE PTR [ebp-0x4],bl
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    R6GameServiceAddresses::WideTextR6RSCUSTOM
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__appStricmpSlot
    add    esp,0x8
    test    eax,eax
    jne    Branch85
    push    R6GameServiceAddresses::WideTextSpace
    lea    ecx,[ebp-0x24]
    call    DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    edx,DWORD PTR [ecx]
    mov    eax,DWORD PTR [edx+0x34]
    mov    ecx,DWORD PTR [eax+0x34]
    mov    edx,DWORD PTR [eax+0x30]
    mov    eax,DWORD PTR [eax+0x2c]
    push    ecx
    push    edx
    push    eax
    lea    ecx,[ebp-0x30]
    push    R6GameServiceAddresses::WideTextD02dBuildD
    push    ecx
    call    DWORD PTR ds:R6GameServiceAddresses::Core_FString_PrintfSlot
    add    esp,0x14
    push    eax
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],0x3
    call    DWORD PTR ds:R6GameServiceAddresses::Core__YFStringSlot
    lea    ecx,[ebp-0x30]
    mov    BYTE PTR [ebp-0x4],bl
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  Branch85:
    lea    ecx,[ebp-0x24]
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    add    esp,0x4
    push    eax
    push    0xfe
    call    R6GameServiceAddresses::WriteStoredAnsiText
    lea    ecx,[esi+0x120]
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    add    esp,0x4
    push    eax
    push    0x64
    call    R6GameServiceAddresses::WriteStoredAnsiText
    mov    edx,DWORD PTR [esi+0x100]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    edx
    push    0x6d
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    xor    eax,eax
    mov    al,BYTE PTR [esi+0xc4]
    and    eax,0xffffff01
    push    eax
    push    0x66
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    ecx,DWORD PTR [esi+0xc4]
    shr    ecx,1
    and    ecx,0xffffff01
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    0x67
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    eax,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    shr    eax,0x6
    not    eax
    and    eax,0x1
    push    eax
    push    0x68
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    edx,DWORD PTR [esi+0xc8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    edx
    push    0x69
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    eax,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    shr    eax,0x2
    and    eax,0xffffff01
    push    eax
    push    0x6a
    call    R6GameServiceAddresses::WriteStoredWordType5
    lea    ecx,[esi+0x114]
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    edi
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    add    esp,0x4
    push    eax
    push    0x65
    call    R6GameServiceAddresses::WriteStoredAnsiText
    mov    ecx,DWORD PTR [esi+0xe4]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    0x6b
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    eax,ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [eax]
    lea    edx,[esi+0x108]
    push    edx
    call    DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeIndexSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    eax
    push    0x6c
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    ecx,DWORD PTR [esi+0x94]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    push    0xfc
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    edx,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPublicSerializedStore
    shr    edx,0xa
    and    edx,0xffffff01
    push    edx
    push    0xff
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    eax,DWORD PTR [esi+0xcc]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    eax
    push    0x6f
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    ecx,DWORD PTR [esi+0xd0]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    0x70
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    edx,DWORD PTR [esi+0xd4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    edx
    push    0x71
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    xor    eax,eax
    mov    al,BYTE PTR [esi+0xd8]
    and    eax,0xffffff01
    push    eax
    push    0x72
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    ecx,DWORD PTR [esi+0xd8]
    shr    ecx,1
    and    ecx,0xffffff01
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    0x73
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    edx,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    shr    edx,0x3
    and    edx,0xffffff01
    push    edx
    push    0x74
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    eax,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    shr    eax,0x4
    and    eax,0xffffff01
    push    eax
    push    0x75
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    ecx,DWORD PTR [esi+0xd8]
    shr    ecx,0x5
    and    ecx,0xffffff01
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    0x76
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    edx,DWORD PTR [esi+0xdc]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    edx
    push    0x77
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    eax,DWORD PTR [esi+0xe0]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    eax
    push    0x78
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    ecx,DWORD PTR [esi+0xd8]
    shr    ecx,0x8
    and    ecx,0xffffff01
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    0x79
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    edx,DWORD PTR [esi+0xd8]
    shr    edx,0x7
    and    edx,0xffffff01
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    edx
    push    0x7a
    call    R6GameServiceAddresses::WriteStoredWordType5
    mov    eax,DWORD PTR [esi+0xd8]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    shr    eax,0x9
    and    eax,0xffffff01
    push    eax
    push    0x7b
    call    R6GameServiceAddresses::WriteStoredWordType5
    xor    ebx,ebx
  Branch86:
    cmp    ebx,DWORD PTR [esi+0x148]
    jge    Branch87
    mov    ecx,DWORD PTR [esi+0x144]
    lea    edi,[ebx+ebx*2]
    shl    edi,0x3
    add    ecx,edi
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push    eax
    lea    ecx,[ebx+0x7c]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    call    R6GameServiceAddresses::WriteStoredAnsiText
    mov    edx,DWORD PTR [esi+0x144]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Engine__GModMgrSlot
    mov    ecx,DWORD PTR [ecx]
    lea    eax,[edi+edx*1+0xc]
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Engine_UR6ModMgr_eventGetGameTypeIndexSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    push    eax
    lea    edx,[ebx+0x9c]
    push    edx
    call    R6GameServiceAddresses::WriteStoredWordType3
    inc    ebx
    jmp    Branch86
  Branch87:
    xor    ebx,ebx
    jmp    Branch88
    lea    ecx,[ecx+0x0]
  Branch88:
    cmp    ebx,DWORD PTR [esi+0x154]
    jge    Branch89
    mov    ecx,DWORD PTR [esi+0x150]
    mov    edi,ebx
    imul    edi,edi,0x2c
    add    ecx,edi
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    add    esp,0x4
    push    eax
    lea    eax,[ebx+0xbc]
    push    eax
    call    R6GameServiceAddresses::WriteStoredAnsiText
    mov    ecx,DWORD PTR [esi+0x150]
    lea    ecx,[edi+ecx*1+0x20]
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    add    esp,0x4
    push    eax
    lea    edx,[ebx+0xcc]
    push    edx
    call    R6GameServiceAddresses::WriteStoredAnsiText
    mov    eax,DWORD PTR [esi+0x150]
    mov    ecx,DWORD PTR [edi+eax*1+0xc]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    lea    edx,[ebx+0xdc]
    push    edx
    call    R6GameServiceAddresses::WriteStoredWordType3
    mov    eax,DWORD PTR [esi+0x150]
    mov    ecx,DWORD PTR [edi+eax*1+0x18]
    push    ecx
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPrivateSerializedStore
    lea    edx,[ebx+0xec]
    push    edx
    call    R6GameServiceAddresses::WriteStoredWordType3
    inc    ebx
    jmp    Branch88
  Branch89:
    lea    ecx,[ebp-0x24]
    mov    BYTE PTR [ebp-0x4],0x0
    call    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
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
// R6GameService.dll @ 1000a887 : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch22(void)
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

// Return the full current global word at0x10093b34; the member receiver is unused.
// R6GameService.dll @ 100125d0 : complete native control/access order and raw ABI retained.
int __thiscall UR6ServerList::GetLobbyID(void)
{
  return *reinterpret_cast<const int *>(R6GameServiceAddresses::GSecondaryLobbyServerId);
}

// Return the full current global word at0x10093b18; the member receiver is unused.
// R6GameService.dll @ 100125e0 : complete native control/access order and raw ABI retained.
int __thiscall UR6ServerList::GetGroupID(void)
{
  return *reinterpret_cast<const int *>(R6GameServiceAddresses::GSecondaryGroupId);
}

// Destroy the completed FillSvrContainer local at inherited EBP-0x30; tail the current FString destructor.
// R6GameService.dll @ 10063c10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl FillSvrContainerUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed FillSvrContainer local at inherited EBP-0x24; tail the current FString destructor.
// R6GameService.dll @ 10063c19 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl FillSvrContainerUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed FillSvrContainer local at inherited EBP-0x30; tail the current FString destructor.
// R6GameService.dll @ 10063c22 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl FillSvrContainerUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select the five-state fill-container guard with mutually exclusive keyword and formatting temporaries.
// R6GameService.dll @ 10063c2b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectFillContainerEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::FillSvrContainerExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal fill-container cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007cb00 : native storage identity retained.
const R6GameServiceNative::UnwindEntry FillSvrContainerUnwindMap[5] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::FillSvrContainerUnwind2},
  {0x0, R6GameServiceAddresses::FillSvrContainerUnwind3},
  {0x2, R6GameServiceAddresses::FillSvrContainerUnwind4},
  {-1, 0x0},
};

// Literal fill-container cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007cb28 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGFillContainerEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch22},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch23},
};

// Literal fill-container cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007cb48 : native storage identity retained.
const R6GameServiceNative::TryBlock FillSvrContainerTryMap[1] = {
  {0x0, 0x3, 0x4, 0x2, R6GameServiceAddresses::UR6ServerListGFillContainerEH},
};

// Literal fill-container cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007cb5c : native storage identity retained.
const R6GameServiceNative::FuncInfo FillSvrContainerExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::FillSvrContainerUnwindMap,
  0x1,
  R6GameServiceAddresses::FillSvrContainerTryMap,
  0x0,
  0x0,
};

// R6GameService.dll @ 1006a290 : initialize UR6ServerList class metadata and register its cleanup
void InitializeUR6ServerListClassMetadata(void)
{
  UClass *withinClass;
  UClass *parentClass;
  ushort *configName;
  undefined4 constructionFlags;
  code *nativeConstructor;
  code *staticConstructor;

  parentClass = (UClass *)UR6AbstractGameService_PrivateStaticClass_exref;
  withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  nativeConstructor = UR6ServerList::InternalConstructor;
  constructionFlags = 0x4084004;
  staticConstructor = UObject_StaticConstructor_exref;
  configName = UObject::StaticConfigName();
  UClass::UClass(&UR6ServerList::PrivateStaticClass,0,0x174,4,parentClass,withinClass,0,0,0,0,L"R6ServerList",
                 GPackage,configName,constructionFlags,nativeConstructor,staticConstructor);
  _atexit(DestroyUR6ServerListClassMetadata);
  return;
}

// Destroy the exported class metadata through CURRENT imported UClass destructor; keep caller stack/registers.
// R6GameService.dll @ 1006ac60 : compiler atexit cleanup tail, no own frame or return.
__declspec(naked) void DestroyUR6ServerListClassMetadata(void)
{
  __asm {
    mov    ecx,0x10092410
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUClassSlot
  }
}

// Exported native member-function slot at 0x1008c1d4; its value is read when registration runs.
extern "C" Native intUR6ServerListexecGetDisplayListSize;

// Registers UR6ServerList::execGetDisplayListSize at native index 1314 and stores the returned byte.
// R6GameService.dll @ 1006a3e0 : cdecl startup entry; result byte at 0x1009240c.
void __cdecl RegisterUR6ServerList_execGetDisplayListSize(void)
{
  byte registrationResult = GRegisterNative(1314,intUR6ServerListexecGetDisplayListSize);
  *(byte *)0x1009240c = registrationResult;
}

// Exported native member-function slot at 0x1008c1d8; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeGetMaxPlayers;

// Registers UR6ServerList::execNativeGetMaxPlayers at native index 1355 and stores the returned byte.
// R6GameService.dll @ 1006a400 : cdecl startup entry; result byte at 0x10092928.
void __cdecl RegisterUR6ServerList_execNativeGetMaxPlayers(void)
{
  byte registrationResult = GRegisterNative(1355,intUR6ServerListexecNativeGetMaxPlayers);
  *(byte *)0x10092928 = registrationResult;
}

// Exported native member-function slot at 0x1008c1dc; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeGetOwnSvrPort;

// Registers UR6ServerList::execNativeGetOwnSvrPort at native index 1292 and stores the returned byte.
// R6GameService.dll @ 1006a420 : cdecl startup entry; result byte at 0x100923aa.
void __cdecl RegisterUR6ServerList_execNativeGetOwnSvrPort(void)
{
  byte registrationResult = GRegisterNative(1292,intUR6ServerListexecNativeGetOwnSvrPort);
  *(byte *)0x100923aa = registrationResult;
}

// Exported native member-function slot at 0x1008c1e0; its value is read when registration runs.
extern "C" Native intUR6ServerListexecSortServers;

// Registers UR6ServerList::execSortServers at native index 1206 and stores the returned byte.
// R6GameService.dll @ 1006a440 : cdecl startup entry; result byte at 0x1009291b.
void __cdecl RegisterUR6ServerList_execSortServers(void)
{
  byte registrationResult = GRegisterNative(1206,intUR6ServerListexecSortServers);
  *(byte *)0x1009291b = registrationResult;
}

// Exported native member-function slot at 0x1008c1e4; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeGetMilliSeconds;

// Registers UR6ServerList::execNativeGetMilliSeconds at native index 1278 and stores the returned byte.
// R6GameService.dll @ 1006a460 : cdecl startup entry; result byte at 0x10092e50.
void __cdecl RegisterUR6ServerList_execNativeGetMilliSeconds(void)
{
  byte registrationResult = GRegisterNative(1278,intUR6ServerListexecNativeGetMilliSeconds);
  *(byte *)0x10092e50 = registrationResult;
}

// Exported native member-function slot at 0x1008c1e8; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeGetPingTimeOut;

// Registers UR6ServerList::execNativeGetPingTimeOut at native index 1202 and stores the returned byte.
// R6GameService.dll @ 1006a480 : cdecl startup entry; result byte at 0x100923fd.
void __cdecl RegisterUR6ServerList_execNativeGetPingTimeOut(void)
{
  byte registrationResult = GRegisterNative(1202,intUR6ServerListexecNativeGetPingTimeOut);
  *(byte *)0x100923fd = registrationResult;
}

// Exported native member-function slot at 0x1008c1ec; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeGetPingTime;

// Registers UR6ServerList::execNativeGetPingTime at native index 1225 and stores the returned byte.
// R6GameService.dll @ 1006a4a0 : cdecl startup entry; result byte at 0x1009291a.
void __cdecl RegisterUR6ServerList_execNativeGetPingTime(void)
{
  byte registrationResult = GRegisterNative(1225,intUR6ServerListexecNativeGetPingTime);
  *(byte *)0x1009291a = registrationResult;
}

// Exported native member-function slot at 0x1008c1f0; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeUpdateFavorites;

// Registers UR6ServerList::execNativeUpdateFavorites at native index 1223 and stores the returned byte.
// R6GameService.dll @ 1006a4c0 : cdecl startup entry; result byte at 0x100923c1.
void __cdecl RegisterUR6ServerList_execNativeUpdateFavorites(void)
{
  byte registrationResult = GRegisterNative(1223,intUR6ServerListexecNativeUpdateFavorites);
  *(byte *)0x100923c1 = registrationResult;
}

// Exported native member-function slot at 0x1008c1f4; its value is read when registration runs.
extern "C" Native intUR6ServerListexecNativeInitFavorites;

// Registers UR6ServerList::execNativeInitFavorites at native index 1222 and stores the returned byte.
// R6GameService.dll @ 1006a4e0 : cdecl startup entry; result byte at 0x10092e84.
void __cdecl RegisterUR6ServerList_execNativeInitFavorites(void)
{
  byte registrationResult = GRegisterNative(1222,intUR6ServerListexecNativeInitFavorites);
  *(byte *)0x10092e84 = registrationResult;
}

// Publishes this class's metadata address in its exported autoclass pointer slot.
// R6GameService.dll @ 1006a320 : cdecl startup entry; pointer slot 0x10092938.
void __cdecl InitializeAutoclassUR6ServerList(void)
{
  *(UClass **)0x10092938 = &UR6ServerList::PrivateStaticClass;
}

// R6GameService.dll data @ 1007b988 : native exception records.
const R6GameServiceNative::UnwindEntry UR6ServerList_execNativeGetPingTimeUnwindMap[3] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeUnwind2},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007b9a0 : native exception records.
const R6GameServiceNative::CatchHandler GPingExchangeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24, R6GameServiceAddresses::UR6ServerListCatch},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch},
};
// R6GameService.dll data @ 1007b9c0 : native exception records.
const R6GameServiceNative::TryBlock UR6ServerList_execNativeGetPingTimeTryMap[1] = {
  {0x0, 0x1, 0x2, 0x2, R6GameServiceAddresses::GPingExchangeHandlers},
};
// R6GameService.dll data @ 1007b9d4 : native exception records.
// R6GameService.dll data @ 1007b988 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_execNativeGetPingTimeExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeTryMap,
  0x0,
  0x0,
};

// Parses an address, runs the actual exchange and stores its full result before destroying its temporary string.
// R6GameService.dll @ 10005af0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeGetPingTime(UR6ServerList *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    push   ebx
    push   esi
    push   edi
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
    jne    Branch90
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   0x0
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch90:
    lea    ecx,[ebp-0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DFStringSlot
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appToAnsiSlot
    add    esp,0x4
    push   eax
    call   R6GameServiceAddresses::ServerPing_GetPingTime
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    DWORD PTR [ecx],eax
    add    esp,0x4
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

// Forwards the caught pointer from inherited EBP-0x18 through-0x14.
// R6GameService.dll @ 10005ba7 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerListCatch(void)
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

// Reports execNativeGetPingTime context and rethrows the active exception.
// R6GameService.dll @ 10005bbb : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeGetPingTime
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the script address temporary at inherited EBP-0x24.
// R6GameService.dll @ 100637a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_execNativeGetPingTimeUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the three-state script exchange guard and address cleanup action.
// R6GameService.dll @ 100637a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_execNativeGetPingTimeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007b9f0 : native exception records.
const R6GameServiceNative::UnwindEntry UR6ServerList_execNativeGetPingTimeOutUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};
// R6GameService.dll data @ 1007ba00 : native exception records.
const R6GameServiceNative::CatchHandler UR6ServerListGPingExchangeHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch2},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch3},
};
// R6GameService.dll data @ 1007ba20 : native exception records.
const R6GameServiceNative::TryBlock UR6ServerList_execNativeGetPingTimeOutTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGPingExchangeHandlers},
};
// R6GameService.dll data @ 1007ba34 : native exception records.
// R6GameService.dll data @ 1007b9f0 : native storage identity retained.
const R6GameServiceNative::FuncInfo UR6ServerList_execNativeGetPingTimeOutExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeOutUnwindMap,
  0x1,
  R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeOutTryMap,
  0x0,
  0x0,
};

// Advances parameter-finish/debug tokens and writes the fixed integer timeout 1000 through the current result slot.
// R6GameService.dll @ 10005be0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ServerList::execNativeGetPingTimeOut(UR6ServerList *this,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeOutSelectExceptionInfo
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
    jne    Branch91
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch91:
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR [eax],0x3e8
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Forwards the caught pointer from inherited EBP-0x18 through-0x14.
// R6GameService.dll @ 10005c48 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch2(void)
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

// Reports execNativeGetPingTimeOut context and rethrows the active exception.
// R6GameService.dll @ 10005c5c : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_UR6ServerListCatch3(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeGetPingTimeOut
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects the timeout wrapper guard without local cleanup actions.
// R6GameService.dll @ 100637c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ServerList_execNativeGetPingTimeOutSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ServerList_execNativeGetPingTimeOutExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Reports UR6ServerList::execNativeGetMilliSeconds context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10005f9e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch5(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeGetMilliSeconds
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::execNativeGetMaxPlayers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000628c : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch7(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeGetMaxPlayers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::execNativeGetOwnSvrPort context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000642e : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch9(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeGetOwnSvrPort
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::execNativeInitFavorites context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100088ac : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch15(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeInitFavorites2
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::execNativeUpdateFavorites context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000899d : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch17(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecNativeUpdateFavorites
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::execSortServers context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 100092d5 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch19(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListExecSortServers
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports UR6ServerList::FillSvrContainer context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 1000a89b : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ServerList_UR6ServerListCatch23(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ServerListFillSvrContainer
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select the exact two-state VM bridge guard and tail the existing runtime dispatcher.
// R6GameService.dll @ 10063ad0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectInitFavoritesBridgeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execNativeInitFavoritesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select the exact two-state VM bridge guard and tail the existing runtime dispatcher.
// R6GameService.dll @ 10063ae0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectUpdateFavoritesBridgeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execNativeUpdateFavoritesExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c580 : native storage identity retained.
const R6GameServiceNative::UnwindEntry execNativeInitFavoritesUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c590 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGFavoriteBridgeEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch14},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch15},
};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c590 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeInitFavoritesTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGFavoriteBridgeEH},
};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c580 : native storage identity retained.
const R6GameServiceNative::FuncInfo execNativeInitFavoritesExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execNativeInitFavoritesUnwindMap,
  0x1,
  R6GameServiceAddresses::execNativeInitFavoritesTryMap,
  0x0,
  0x0,
};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c5e0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry execNativeUpdateFavoritesUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c5f0 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ServerListGFavoriteBridgeEH5[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24,
  R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch16},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ServerList_UR6ServerListCatch17},
};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c5f0 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeUpdateFavoritesTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::UR6ServerListGFavoriteBridgeEH5},
};

// Literal favorite-bridge guard/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007c5e0 : native storage identity retained.
const R6GameServiceNative::FuncInfo execNativeUpdateFavoritesExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::execNativeUpdateFavoritesUnwindMap,
  0x1,
  R6GameServiceAddresses::execNativeUpdateFavoritesTryMap,
  0x0,
  0x0,
};

// Native virtual-table prefix: UR6ServerListDispatchTable
// R6GameService.dll data @ 1006b820 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct UR6ServerListDispatchTableRecord {
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember22; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember21; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember20; // +0x08
  R6GameServiceNative::Address DeleteUR6ServerList; // +0x0c
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
const UR6ServerListDispatchTableRecord UR6ServerListDispatchTable = {
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember22,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember21,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember20,
  R6GameServiceAddresses::DeleteUR6ServerList,
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
