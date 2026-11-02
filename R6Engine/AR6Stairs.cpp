#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6StairsClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004acc0 : AR6StairsVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Stairs::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6StairsVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005576a : nativeTextR6Stairs
extern const ushort nativeTextR6Stairs[9];

// R6Engine.dll data @ 1007a1c0 : autoclassAR6Stairs
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Stairs = nullptr;

// R6Engine.dll @ 10007250 : AR6Stairs::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Stairs::StaticClass(void)
{
    return &AR6Stairs::PrivateStaticClass; // Selected object at0x10081230.
}

// R6Engine.dll @ 10007260 : AR6Stairs::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6Stairs::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6Stairs::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10007290 : AR6Stairs::~AR6Stairs
// Runs conditional object cleanup, with implicit NavigationPoint destruction on normal or exceptional exit.
AR6Stairs::~AR6Stairs()
{
    // Compiler installs vtable1004acc0 first; shared FuncInfo10056d8c protects the base through state0.
    UObject::ConditionalDestroy();
    // Normal base call uses current IAT10049450 at state-1; shared cleanup10043230 uses saved EBP-0x10.
}

// R6Engine.dll @ 100072f0 : AR6Stairs::AR6Stairs()
// Constructs NavigationPoint and installs the stairs vtable without initializing the derived flag word.
AR6Stairs::AR6Stairs() : ANavigationPoint()
{
    // Publishes AR6StairsVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10007310 : AR6Stairs::AR6Stairs(const AR6Stairs&)
// Copies the base, installs the stairs vtable, then merges the source-first top-of-stairs bit into current flags.
AR6Stairs::AR6Stairs(const AR6Stairs& sourceObject) : ANavigationPoint(sourceObject)
{
    // Publishes AR6StairsVirtualTable after base construction; native EAX retains original storage.
    AR6Stairs* stairs = this;
    const AR6Stairs* source = &sourceObject;
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3e8);
    uint destinationFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(stairs) + 0x3e8);
    uint difference = (sourceFlags ^ destinationFlags) & 1U; // m_bIsTopOfStairs.
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(stairs) + 0x3e8) = destinationFlags ^ difference;
}

// R6Engine.dll @ 10007350 : AR6Stairs::operator=
// Assigns the base and one top-of-stairs bit, retaining the vtable and all unrelated destination flag bits.
AR6Stairs& __thiscall AR6Stairs::operator=(const AR6Stairs& sourceObject)
{
    AR6Stairs* stairs = this;
    const AR6Stairs* source = &sourceObject;
    stairs->ANavigationPoint::operator=(*source);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3e8);
    uint destinationFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(stairs) + 0x3e8);
    uint difference = (sourceFlags ^ destinationFlags) & 1U;
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(stairs) + 0x3e8) = destinationFlags ^ difference;
    return *stairs;
}

// R6Engine.dll @ 10007390 : AR6Stairs::DeletingDestructor
// Destroys one marker or a cookie-counted array, optionally frees storage and returns the original address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6Stairs::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6Stairs* stairs = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(stairs) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6StairsDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(stairs) - 4;
        _eh_vector_destructor_iterator_(stairs, 0x3ec, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current GMalloc is fetched after element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    stairs->AR6Stairs::~AR6Stairs(); // Direct native10007290 call, without virtual dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(stairs, 0x3ec);
    }
    return stairs;
}

// R6Engine.dll @ 1000dc70 : AR6Stairs::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Stairs::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6StairsConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10046340 : InitializeAR6StairsClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6StairsClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // ANavigationPoint object address, captured before config lookup.
    UClass* parentClass = ANavigationPointPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6Stairs::PrivateStaticClass, 0, 0x3ec, 0, parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6Stairs, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6Stairs::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6StairsClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048050 : DestroyAR6StairsClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6StairsClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Stairs::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100463d0 : PublishAR6StairsAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6StairsAutoClass(void)
{
    autoclassAR6Stairs = &AR6Stairs::PrivateStaticClass;
}
