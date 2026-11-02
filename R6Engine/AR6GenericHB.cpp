#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6GenericHBClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004e7c0 : AR6GenericHBVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6GenericHB::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6GenericHBVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100505e2 : nativeTextR6GenericHB
extern const ushort nativeTextR6GenericHB[12];

// R6Engine.dll data @ 100754e0 : autoclassAR6GenericHB
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6GenericHB = nullptr;

// R6Engine.dll @ 10009090 : AR6GenericHB::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6GenericHB::StaticClass(void)
{
    return &AR6GenericHB::PrivateStaticClass; // Selected object at0x100745c0.
}

// R6Engine.dll @ 100090a0 : AR6GenericHB::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6GenericHB::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6GenericHB::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10014a80 : AR6GenericHB::operator=
// Copies the first-impact flag and impact, ground and water sound references.
AR6GenericHB& __thiscall AR6GenericHB::operator=(const AR6GenericHB& sourceObject)
{
    const AR6GenericHB* source = &sourceObject;
    this->AR6InteractiveObject::operator=(*source);
    // Native source read precedes destination read.
    uint sourceWord = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x458);
    uint* flags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x458);
    uint destinationWord = *flags;
    *flags = destinationWord ^ ((sourceWord ^ destinationWord) & 1U); // m_bFirstImpact only.
    this->m_ImpactSound = source->m_ImpactSound;
    this->m_ImpactGroundSound = source->m_ImpactGroundSound;
    this->m_ImpactWaterSound = source->m_ImpactWaterSound;
    return *this;
}

// R6Engine.dll @ 10015da0 : AR6GenericHB::~AR6GenericHB
// Runs conditional cleanup before automatic AR6InteractiveObject base destruction.
AR6GenericHB::~AR6GenericHB()
{
    // Compiler installs vtable1004e7c0; native state0 protects the completed base during this call.
    UObject::ConditionalDestroy();
    // Implicit base destruction enters state-1 normally; exact shared cleanup is retained in module support.
}

// R6Engine.dll @ 10015df0 : AR6GenericHB::AR6GenericHB()
// Constructs through AActor, installs this class's table and leaves derived fields untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6GenericHB* __thiscall AR6GenericHB::AR6GenericHB(AR6GenericHB* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6GenericHBVirtualTable);
    return this; // Preserve original storage independently of the imported constructor's EAX.
}

// R6Engine.dll @ 10015e10 : AR6GenericHB::AR6GenericHB
// Copies the completed base and this class's scalar/reference state in native order.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6GenericHB* __thiscall AR6GenericHB::AR6GenericHB(AR6GenericHB* this, const AR6GenericHB* source)
{
    AR6InteractiveObject::AR6InteractiveObject(this, source);
    uint* flags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x458);
    uint destinationWord = *flags; // Snapshot precedes the derived table installation.
    *(uint*)this = ((uint)&AR6GenericHBVirtualTable);
    uint sourceWord = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x458);
    *flags = destinationWord ^ ((sourceWord ^ destinationWord) & 1U); // m_bFirstImpact only.
    this->m_ImpactSound = source->m_ImpactSound;
    this->m_ImpactGroundSound = source->m_ImpactGroundSound;
    this->m_ImpactWaterSound = source->m_ImpactWaterSound;
    return this;
}

// R6Engine.dll @ 10015e70 : AR6GenericHB::DeletingDestructor
// Destroys one AR6GenericHB object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6GenericHB::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6GenericHB* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6GenericHBDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x468, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6GenericHB::~AR6GenericHB();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x468);
    }
    return object;
}

// R6Engine.dll @ 10016180 : AR6GenericHB::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6GenericHB::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6GenericHBConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10045640 : InitializeAR6GenericHBClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6GenericHBClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // IAT object address, not a field loaded from the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6GenericHB::PrivateStaticClass, 0, 0x468, 0,
        &AR6InteractiveObject::PrivateStaticClass, withinClass, *(FGuid*)guidWords,
            nativeTextR6GenericHB,
        (const ushort*)&enginePackageName, configName, 0x04084004, &AR6GenericHB::InternalConstructor,
            staticConstructorWord);
    return _atexit(DestroyAR6GenericHBClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100456c0 : PublishAR6GenericHBAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6GenericHBAutoClass(void)
{
    autoclassAR6GenericHB = &AR6GenericHB::PrivateStaticClass;
}

// R6Engine.dll @ 10047ef0 : DestroyAR6GenericHBClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6GenericHBClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6GenericHB::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}
