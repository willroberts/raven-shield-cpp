#include "native_object_tables.hpp"
#include "native_exported_data.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004e4b0 : AR6IOObjectVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6IOObject::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6IOObjectVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055952 : nativeTextR6IOObject
extern const ushort nativeTextR6IOObject[11];

// R6Engine.dll data @ 1007d9f8 : autoclassAR6IOObject
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6IOObject = nullptr;

// R6Engine.dll @ 10009010 : AR6IOObject::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6IOObject::StaticClass(void)
{
    return &AR6IOObject::PrivateStaticClass; // Selected object at0x10079260.
}

// R6Engine.dll @ 10009020 : AR6IOObject::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6IOObject::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6IOObject::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100147c0 : AR6IOObject::operator=
// Copies action settings, activation flags, interaction timing and sound references.
AR6IOObject& __thiscall AR6IOObject::operator=(const AR6IOObject& sourceObject)
{
    const AR6IOObject* source = &sourceObject;
    this->AR6InteractiveObject::operator=(*source);
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
    auto animation = source->m_eAnimToPlay; // Native byte read precedes the destination flag snapshot.
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x468);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x468);
    uint earlyFlags = *destinationFlags;
    this->m_eAnimToPlay = animation;
    this->m_ObjectState = source->m_ObjectState;
    uint difference = earlyFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags;
    copiedFlags ^= difference & 0x1U; // m_bToggleType.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // sm_bToggleType.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bIsActivated.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // sm_bIsActivated.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fGainTimeWithElectronicsKit) = reinterpret_cast<const
        uint&>(source->m_fGainTimeWithElectronicsKit);
    reinterpret_cast<uint&>(this->m_fLockObjectTime) = reinterpret_cast<const uint&>(source->m_fLockObjectTime);
    this->m_StartSnd = source->m_StartSnd;
    this->m_InterruptedSnd = source->m_InterruptedSnd;
    this->m_CompletedSnd = source->m_CompletedSnd;
    return *this;
}

// R6Engine.dll @ 100157e0 : AR6IOObject::~AR6IOObject
// Runs conditional cleanup before automatic action-object base destruction.
AR6IOObject::~AR6IOObject()
{
    // Compiler installs vtable1004e4b0; native state0 protects the completed action-object base.
    UObject::ConditionalDestroy();
    // Implicit AR6IActionObject destruction enters state-1 normally and uses shared43b80 on unwind.
}

// R6Engine.dll @ 10015830 : AR6IOObject::AR6IOObject()
// Constructs through AActor, installs the IOObject vtable and leaves derived fields untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6IOObject* __thiscall AR6IOObject::AR6IOObject(AR6IOObject* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6IOObjectVirtualTable);
    return this; // Preserve the original receiver independently of the imported constructor result.
}

// R6Engine.dll @ 10015850 : AR6IOObject::AR6IOObject
// Copies action settings, activation flags, interaction timing and sound references.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6IOObject* __thiscall AR6IOObject::AR6IOObject(AR6IOObject* this, const AR6IOObject* source)
{
    AR6InteractiveObject::AR6InteractiveObject(this, source);
    *(uint*)this = ((uint)&AR6IActionObjectVirtualTable); // Inlined action-object base construction.
    reinterpret_cast<uint&>(this->m_fMinMouseMove) = reinterpret_cast<const uint&>(source->m_fMinMouseMove);
    reinterpret_cast<uint&>(this->m_fMaxMouseMove) = reinterpret_cast<const uint&>(source->m_fMaxMouseMove);
    this->m_ActionInstigator = source->m_ActionInstigator;
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x468);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x468);
    uint earlyFlags = *destinationFlags;
    *(uint*)this = ((uint)&AR6IOObjectVirtualTable);
    this->m_eAnimToPlay = source->m_eAnimToPlay;
    this->m_ObjectState = source->m_ObjectState;
    uint difference = earlyFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags;
    copiedFlags ^= difference & 0x1U; // m_bToggleType.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // sm_bToggleType.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x4U; // m_bIsActivated.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x8U; // sm_bIsActivated.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fGainTimeWithElectronicsKit) = reinterpret_cast<const
        uint&>(source->m_fGainTimeWithElectronicsKit);
    reinterpret_cast<uint&>(this->m_fLockObjectTime) = reinterpret_cast<const uint&>(source->m_fLockObjectTime);
    this->m_StartSnd = source->m_StartSnd;
    this->m_InterruptedSnd = source->m_InterruptedSnd;
    this->m_CompletedSnd = source->m_CompletedSnd;
    return this;
}

// R6Engine.dll @ 10015950 : AR6IOObject::DeletingDestructor
// Destroys one interactive object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6IOObject::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6IOObject* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6IOObjectDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x480, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6IOObject::~AR6IOObject();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x480);
    }
    return object;
}

// R6Engine.dll @ 10016160 : AR6IOObject::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6IOObject::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6IOObjectConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10048130 : DestroyAR6IOObjectClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6IOObjectClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6IOObject::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046ba0 : InitializeAR6IOObjectClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6IOObjectClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6IOObject::PrivateStaticClass, 0, 0x480, 0,
        &AR6IActionObject::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6IOObject, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6IOObject::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6IOObjectClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046c20 : PublishAR6IOObjectAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6IOObjectAutoClass(void)
{
    autoclassAR6IOObject = &AR6IOObject::PrivateStaticClass;
}
