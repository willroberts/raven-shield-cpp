#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6SAHeartBeatJammerClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004e948 : AR6SAHeartBeatJammerVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6SAHeartBeatJammer::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6SAHeartBeatJammerVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050622 : nativeTextR6SAHeartBeatJammer
extern const ushort nativeTextR6SAHeartBeatJammer[20];

// R6Engine.dll data @ 100754dc : autoclassAR6SAHeartBeatJammer
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6SAHeartBeatJammer = nullptr;

// R6Engine.dll @ 100090d0 : AR6SAHeartBeatJammer::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6SAHeartBeatJammer::StaticClass(void)
{
    return &AR6SAHeartBeatJammer::PrivateStaticClass; // Selected object at0x10074fd0.
}

// R6Engine.dll @ 100090e0 : AR6SAHeartBeatJammer::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6SAHeartBeatJammer::operator_new(uint allocationSize, UObject* outer, FName objectName,
    ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6SAHeartBeatJammer::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10014ae0 : AR6SAHeartBeatJammer::operator=
// Assigns the AR6GenericHB base and returns the original destination pointer.
AR6SAHeartBeatJammer& __thiscall AR6SAHeartBeatJammer::operator=(const AR6SAHeartBeatJammer& sourceObject)
{
    const AR6SAHeartBeatJammer* source = &sourceObject;
    this->AR6GenericHB::operator=(*source);
    return *this;
}

// R6Engine.dll @ 10015ee0 : AR6SAHeartBeatJammer::~AR6SAHeartBeatJammer
// Runs conditional cleanup before automatic AR6GenericHB base destruction.
AR6SAHeartBeatJammer::~AR6SAHeartBeatJammer()
{
    // Compiler installs vtable1004e948; native state0 protects the completed base during this call.
    UObject::ConditionalDestroy();
    // Implicit base destruction enters state-1 normally; exact shared cleanup is retained in module support.
}

// R6Engine.dll @ 10015f30 : AR6SAHeartBeatJammer::AR6SAHeartBeatJammer()
// Constructs through AActor, installs this class's table and leaves derived fields untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6SAHeartBeatJammer* __thiscall AR6SAHeartBeatJammer::AR6SAHeartBeatJammer(AR6SAHeartBeatJammer* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6SAHeartBeatJammerVirtualTable);
    return this; // Preserve original storage independently of the imported constructor's EAX.
}

// R6Engine.dll @ 10015f50 : AR6SAHeartBeatJammer::AR6SAHeartBeatJammer
// Copies the completed base and this class's scalar/reference state in native order.
AR6SAHeartBeatJammer::AR6SAHeartBeatJammer(const AR6SAHeartBeatJammer& sourceObject) : AR6GenericHB(sourceObject)
{
    // Publishes AR6SAHeartBeatJammerVirtualTable after base copy; native EAX retains original storage.
}

// R6Engine.dll @ 10015f70 : AR6SAHeartBeatJammer::DeletingDestructor
// Destroys one AR6SAHeartBeatJammer object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6SAHeartBeatJammer::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6SAHeartBeatJammer* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6SAHeartBeatJammerDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x468, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6SAHeartBeatJammer::~AR6SAHeartBeatJammer();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x468);
    }
    return object;
}

// R6Engine.dll @ 10016190 : AR6SAHeartBeatJammer::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6SAHeartBeatJammer::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6SAHeartBeatJammerConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10045760 : InitializeAR6SAHeartBeatJammerClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6SAHeartBeatJammerClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // IAT object address, not a field loaded from the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6SAHeartBeatJammer::PrivateStaticClass, 0, 0x468, 0,
        &AR6GenericHB::PrivateStaticClass, withinClass, *(FGuid*)guidWords,
            nativeTextR6SAHeartBeatJammer,
        (const ushort*)&enginePackageName, configName, 0x04084004,
        &AR6SAHeartBeatJammer::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6SAHeartBeatJammerClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100457e0 : PublishAR6SAHeartBeatJammerAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6SAHeartBeatJammerAutoClass(void)
{
    autoclassAR6SAHeartBeatJammer = &AR6SAHeartBeatJammer::PrivateStaticClass;
}

// R6Engine.dll @ 10047f10 : DestroyAR6SAHeartBeatJammerClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6SAHeartBeatJammerClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6SAHeartBeatJammer::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}
