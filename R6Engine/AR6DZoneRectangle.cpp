#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005581e : nativeTextR6DZoneRectangle
extern const ushort nativeTextR6DZoneRectangle[17];

// R6Engine.dll data @ 1007b124 : autoclassAR6DZoneRectangle
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZoneRectangle = nullptr;

// R6Engine.dll @ 10009740 : AR6DZoneRectangle::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZoneRectangle::StaticClass(void)
{
    return &AR6DZoneRectangle::PrivateStaticClass; // Selected object at0x10081740.
}

// R6Engine.dll @ 10009750 : AR6DZoneRectangle::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZoneRectangle::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZoneRectangle::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10010240 : AR6DZoneRectangle::operator=
// Assigns the base and raw dimension words in native order, preserving the vtable and returning this object.
AR6DZoneRectangle& AR6DZoneRectangle::operator=(const AR6DZoneRectangle& source)
{
    AR6DeploymentZone::operator=(source);
    reinterpret_cast<uint&>(m_fX) = reinterpret_cast<const uint&>(source.m_fX);
    reinterpret_cast<uint&>(m_fY) = reinterpret_cast<const uint&>(source.m_fY);
    return *this;
}

// R6Engine.dll @ 10012b50 : AR6DZoneRectangle::~AR6DZoneRectangle
// Runs ConditionalDestroy, then implicitly destroys the deployment-zone base on normal and exceptional exits.
AR6DZoneRectangle::~AR6DZoneRectangle()
{
    // Compiler installs vtable1004d608 first; state0 retains shared base cleanup10043940 via10043948.
    UObject::ConditionalDestroy(); // Ignore its int result; these derived scalar fields own no resources.
}

// R6Engine.dll @ 10012ba0 : AR6DZoneRectangle::AR6DZoneRectangle(void)
// Constructs the deployment-zone base and installs the derived vtable without initializing its dimensions.
AR6DZoneRectangle::AR6DZoneRectangle() : AR6DeploymentZone()
{
    // Native protected constructor returns its original receiver in EAX; derived storage remains unchanged.
}

// R6Engine.dll @ 10012bc0 : AR6DZoneRectangle::AR6DZoneRectangle(const AR6DZoneRectangle&)
// Copies the base, installs the derived vtable and then copies each current source dimension word.
AR6DZoneRectangle::AR6DZoneRectangle(const AR6DZoneRectangle& source) : AR6DeploymentZone(source)
{
    // Compiler installs vtable1004d608 after the base; raw copies preserve all floating-point bit patterns.
    reinterpret_cast<uint&>(m_fX) = reinterpret_cast<const uint&>(source.m_fX);
    reinterpret_cast<uint&>(m_fY) = reinterpret_cast<const uint&>(source.m_fY);
}

// R6Engine.dll @ 10013aa0 : AR6DZoneRectangle::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZoneRectangle::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZoneRectangleConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100480b0 : DestroyAR6DZoneRectangleClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZoneRectangleClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZoneRectangle::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100466d0 : InitializeAR6DZoneRectangleClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZoneRectangleClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZoneRectangle::PrivateStaticClass, 0, 0x4a4, 0,
        &AR6DeploymentZone::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZoneRectangle,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6DZoneRectangle::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZoneRectangleClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046750 : PublishAR6DZoneRectangleAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZoneRectangleAutoClass(void)
{
    autoclassAR6DZoneRectangle = &AR6DZoneRectangle::PrivateStaticClass;
}

// R6Engine.dll @ 10012c00 : AR6DZoneRectangle::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZoneRectangle::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZoneRectangle* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZoneRectangleDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4a4, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZoneRectangle::~AR6DZoneRectangle(); // Direct native call10012b50, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4a4);
    }
    return object;
}
