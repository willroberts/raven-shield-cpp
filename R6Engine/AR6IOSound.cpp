#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6IOSoundClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b818 : AR6IOSoundVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6IOSound::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6IOSoundVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100559e2 : nativeTextR6IOSound
extern const ushort nativeTextR6IOSound[10];

// R6Engine.dll data @ 1007d4d0 : autoclassAR6IOSound
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6IOSound = nullptr;

// R6Engine.dll @ 10009150 : AR6IOSound::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6IOSound::StaticClass(void)
{
    return &AR6IOSound::PrivateStaticClass; // Selected object at0x1007c580.
}

// R6Engine.dll @ 10009160 : AR6IOSound::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6IOSound::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6IOSound::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10009190 : AR6IOSound::~AR6IOSound
// Conditionally destroys UObject state while retaining AActor-base cleanup for an exceptional exit.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6IOSound::~AR6IOSound(AR6IOSound* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    // Shared FuncInfo10056eac: state0 invokes inherited-frame helper100432d0.
    guard[2] = ((uint)&ActorBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6IOSoundVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 100091f0 : AR6IOSound::AR6IOSound
// Constructs the base and publishes the class table without initializing derived field words.
AR6IOSound::AR6IOSound() : AActor()
{
    // Native publication: AR6IOSoundVirtualTable after the base returns; EAX preserves incoming ECX.
}

// R6Engine.dll @ 10009210 : AR6IOSound::AR6IOSound(copy)
// Copy-constructs AActor and installs the IOSound vtable; the native body copies no additional fields.
AR6IOSound::AR6IOSound(const AR6IOSound& sourceObject) : AActor(sourceObject)
{
    // Publishes AR6IOSoundVirtualTable after base copy; native EAX retains original storage.
}

// R6Engine.dll @ 10009230 : AR6IOSound::operator=
// Delegates assignment to AActor and returns the original receiver, preserving its vtable.
AR6IOSound& __thiscall AR6IOSound::operator=(const AR6IOSound& sourceObject)
{
    const AR6IOSound* source = &sourceObject;
    this->AActor::operator=(*source);
    return *this; // The native body ignores the provider's return value.
}

// R6Engine.dll @ 1000df80 : AR6IOSound::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6IOSound::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6IOSoundConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10046e90 : InitializeAR6IOSoundClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6IOSoundClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AActor object address, captured before config lookup.
    UClass* parentClass = AActorPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6IOSound::PrivateStaticClass, 0, 0x394, 0,
        parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6IOSound, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6IOSound::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6IOSoundClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048180 : DestroyAR6IOSoundClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6IOSoundClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6IOSound::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046f20 : PublishAR6IOSoundAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6IOSoundAutoClass(void)
{
    autoclassAR6IOSound = &AR6IOSound::PrivateStaticClass;
}

// R6Engine.dll @ 10009250 : AR6IOSound::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6IOSound::DeletingDestructor(uint flags)
{
    byte deleteFlags = reinterpret_cast<byte&>(flags); // Captured once; native RET4 consumes the full incoming word.
    if ((deleteFlags & 2U) != 0) {
        int count = *(int*)((byte*)this - 4);
        using Destructor = void (__thiscall*)(void*);
        struct ArrayPacketView { // Inferred four-word outgoing packet at entryESP-0x1c.
            void* objects;
            uint stride;
            int count;
            Destructor destroy;
        } packet;
        packet.destroy = (Destructor)&AR6IOSoundDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x394;
        packet.objects = this;
        _eh_vector_destructor_iterator_(packet.objects, packet.stride, packet.count, packet.destroy);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            NativeAllocatorVtablePrefix* allocatorVtable = *reinterpret_cast<NativeAllocatorVtablePrefix**>(allocator);
            void* freeArgument = cookie; // Outgoing argument precedes the current virtual target read.
            using Free = void (__thiscall*)(void*, void*);
            Free free = reinterpret_cast<Free&>(allocatorVtable->freeAddress);
            free(allocator, freeArgument);
        }
        return cookie;
    }
    this->AR6IOSound::~AR6IOSound();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x394;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
