#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100557a2 : nativeTextR6DZoneCircle
extern const ushort nativeTextR6DZoneCircle[14];

// R6Engine.dll data @ 1007f8a4 : autoclassAR6DZoneCircle
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZoneCircle = nullptr;

// R6Engine.dll @ 10009800 : AR6DZoneCircle::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZoneCircle::StaticClass(void)
{
    return &AR6DZoneCircle::PrivateStaticClass; // Selected object at0x1007d4e0.
}

// R6Engine.dll @ 10009810 : AR6DZoneCircle::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZoneCircle::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZoneCircle::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10010360 : AR6DZoneCircle::operator=
// Assigns the base and raw dimension words in native order, preserving the vtable and returning this object.
AR6DZoneCircle& AR6DZoneCircle::operator=(const AR6DZoneCircle& source)
{
    AR6DeploymentZone::operator=(source);
    reinterpret_cast<uint&>(m_fRadius) = reinterpret_cast<const uint&>(source.m_fRadius);
    return *this;
}

// R6Engine.dll @ 10012f80 : AR6DZoneCircle::~AR6DZoneCircle
// Runs ConditionalDestroy, then implicitly destroys the deployment-zone base on normal and exceptional exits.
AR6DZoneCircle::~AR6DZoneCircle()
{
    // Compiler installs vtable1004dae8 first; state0 retains shared base cleanup10043940 via10043948.
    UObject::ConditionalDestroy(); // Ignore its int result; these derived scalar fields own no resources.
}

// R6Engine.dll @ 10012fd0 : AR6DZoneCircle::AR6DZoneCircle(void)
// Constructs the deployment-zone base and installs the derived vtable without initializing its dimensions.
AR6DZoneCircle::AR6DZoneCircle() : AR6DeploymentZone()
{
    // Native protected constructor returns its original receiver in EAX; derived storage remains unchanged.
}

// R6Engine.dll @ 10012ff0 : AR6DZoneCircle::AR6DZoneCircle(const AR6DZoneCircle&)
// Copies the base, installs the derived vtable and then copies each current source dimension word.
AR6DZoneCircle::AR6DZoneCircle(const AR6DZoneCircle& source) : AR6DeploymentZone(source)
{
    // Compiler installs vtable1004dae8 after the base; raw copies preserve all floating-point bit patterns.
    reinterpret_cast<uint&>(m_fRadius) = reinterpret_cast<const uint&>(source.m_fRadius);
}

// R6Engine.dll @ 10013ad0 : AR6DZoneCircle::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZoneCircle::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZoneCircleConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10048070 : DestroyAR6DZoneCircleClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZoneCircleClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZoneCircle::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046480 : InitializeAR6DZoneCircleClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZoneCircleClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZoneCircle::PrivateStaticClass, 0, 0x4a0, 0,
        &AR6DeploymentZone::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZoneCircle, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6DZoneCircle::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZoneCircleClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046500 : PublishAR6DZoneCircleAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZoneCircleAutoClass(void)
{
    autoclassAR6DZoneCircle = &AR6DZoneCircle::PrivateStaticClass;
}

// R6Engine.dll @ 10013020 : AR6DZoneCircle::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZoneCircle::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZoneCircle* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZoneCircleDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4a0, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZoneCircle::~AR6DZoneCircle(); // Direct native call10012f80, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4a0);
    }
    return object;
}
