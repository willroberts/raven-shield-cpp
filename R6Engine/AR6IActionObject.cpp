#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005592e : nativeTextR6IActionObject
extern const ushort nativeTextR6IActionObject[16];

// R6Engine.dll data @ 10081c54 : autoclassAR6IActionObject
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6IActionObject = nullptr;

// R6Engine.dll @ 10008f90 : AR6IActionObject::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6IActionObject::StaticClass(void)
{
    return &AR6IActionObject::PrivateStaticClass; // Selected object at0x10079c88.
}

// R6Engine.dll @ 10008fa0 : AR6IActionObject::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6IActionObject::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6IActionObject::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100144f0 : AR6IActionObject::operator=
// Assigns the interactive base, then copies both mouse thresholds and the action instigator.
AR6IActionObject& __thiscall AR6IActionObject::operator=(const AR6IActionObject& sourceObject)
{
    const AR6IActionObject* source = &sourceObject;
    this->AR6InteractiveObject::operator=(*source);
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
    return *this; // Return the saved receiver, ignoring the base result; no identity shortcut.
}

// R6Engine.dll @ 10015300 : AR6IActionObject::~AR6IActionObject
// Runs conditional cleanup before automatic interactive-object base destruction.
AR6IActionObject::~AR6IActionObject()
{
    // Compiler installs vtable1004e1a0; native state0 protects the completed base during this call.
    UObject::ConditionalDestroy();
    // Implicit AR6InteractiveObject destruction enters state-1 on normal exit and uses shared43b40 on unwind.
}

// R6Engine.dll @ 10015350 : AR6IActionObject::AR6IActionObject()
// Constructs through AActor, installs the action-object vtable and leaves derived storage untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6IActionObject* __thiscall AR6IActionObject::AR6IActionObject(AR6IActionObject* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6IActionObjectVirtualTable);
    return this; // The original receiver is retained independently of the base constructor's EAX.
}

// R6Engine.dll @ 10015370 : AR6IActionObject::AR6IActionObject
// Copy-constructs the interactive base and copies the raw mouse thresholds and actor reference.
AR6IActionObject::AR6IActionObject(const AR6IActionObject& sourceObject) : AR6InteractiveObject(sourceObject)
{
    // Publishes AR6IActionObjectVirtualTable after base copy; native EAX retains original storage.
    const AR6IActionObject* source = &sourceObject;
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
}

// R6Engine.dll @ 100153b0 : AR6IActionObject::DeletingDestructor
// Destroys one action object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6IActionObject::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6IActionObject* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6IActionObjectDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x464, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6IActionObject::~AR6IActionObject();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x464);
    }
    return object;
}

// R6Engine.dll @ 10016140 : AR6IActionObject::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6IActionObject::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6IActionObjectConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10048120 : DestroyAR6IActionObjectClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6IActionObjectClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6IActionObject::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046b10 : InitializeAR6IActionObjectClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6IActionObjectClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6IActionObject::PrivateStaticClass, 0, 0x464, 0,
        &AR6InteractiveObject::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6IActionObject,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6IActionObject::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6IActionObjectClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046b90 : PublishAR6IActionObjectAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6IActionObjectAutoClass(void)
{
    autoclassAR6IActionObject = &AR6IActionObject::PrivateStaticClass;
}
