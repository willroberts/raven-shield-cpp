#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6EnvironmentNodeClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004be38 : AR6EnvironmentNodeVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6EnvironmentNode::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6EnvironmentNodeVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055732 : nativeTextR6EnvironmentNode
extern const ushort nativeTextR6EnvironmentNode[18];

// R6Engine.dll data @ 100773d4 : autoclassAR6EnvironmentNode
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6EnvironmentNode = nullptr;

// R6Engine.dll @ 10009a70 : AR6EnvironmentNode::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6EnvironmentNode::StaticClass(void)
{
    return &AR6EnvironmentNode::PrivateStaticClass; // Selected object at0x10078d50.
}

// R6Engine.dll @ 10009a80 : AR6EnvironmentNode::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6EnvironmentNode::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6EnvironmentNode::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10009ab0 : AR6EnvironmentNode::~AR6EnvironmentNode
// Conditionally destroys UObject state while retaining AActor-base cleanup for an exceptional exit.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6EnvironmentNode::~AR6EnvironmentNode(AR6EnvironmentNode* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    // Shared FuncInfo10056eac: state0 invokes inherited-frame helper100432d0.
    guard[2] = ((uint)&ActorBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6EnvironmentNodeVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10009b10 : AR6EnvironmentNode::AR6EnvironmentNode
// Constructs the base and publishes the class table without initializing derived field words.
AR6EnvironmentNode::AR6EnvironmentNode() : AActor()
{
    // Native publication: AR6EnvironmentNodeVirtualTable after the base returns; EAX preserves incoming ECX.
}

// R6Engine.dll @ 10009b30 : AR6EnvironmentNode::AR6EnvironmentNode
// Copy-constructs the base, installs the class vtable and copies the look-direction vector as three raw words.
AR6EnvironmentNode::AR6EnvironmentNode(const AR6EnvironmentNode& sourceObject) : AActor(sourceObject)
{
    // Publishes AR6EnvironmentNodeVirtualTable after base copy; native EAX retains original storage.
    const AR6EnvironmentNode* source = &sourceObject;
    // +0x394, after the base call.
    reinterpret_cast<uint&>(this->m_vLookDir.X) = reinterpret_cast<const uint&>(source->m_vLookDir.X);
    reinterpret_cast<uint&>(this->m_vLookDir.Y) = reinterpret_cast<const uint&>(source->m_vLookDir.Y); // +0x398.
    reinterpret_cast<uint&>(this->m_vLookDir.Z) = reinterpret_cast<const uint&>(source->m_vLookDir.Z); // +0x39c.
}

// R6Engine.dll @ 10009b70 : AR6EnvironmentNode::operator=
// Assigns the base and three look-direction words, preserving the vtable and native self-assignment behavior.
AR6EnvironmentNode& __thiscall AR6EnvironmentNode::operator=(const AR6EnvironmentNode& sourceObject)
{
    const AR6EnvironmentNode* source = &sourceObject;
    this->AActor::operator=(*source);
    // +0x394, after the base call.
    reinterpret_cast<uint&>(this->m_vLookDir.X) = reinterpret_cast<const uint&>(source->m_vLookDir.X);
    reinterpret_cast<uint&>(this->m_vLookDir.Y) = reinterpret_cast<const uint&>(source->m_vLookDir.Y); // +0x398.
    reinterpret_cast<uint&>(this->m_vLookDir.Z) = reinterpret_cast<const uint&>(source->m_vLookDir.Z); // +0x39c.
    return *this;
}

// R6Engine.dll @ 1000dfc0 : AR6EnvironmentNode::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6EnvironmentNode::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6EnvironmentNodeConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10046200 : InitializeAR6EnvironmentNodeClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6EnvironmentNodeClassMetadata(void)
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
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6EnvironmentNode::PrivateStaticClass, 0, 0x3a0, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6EnvironmentNode,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6EnvironmentNode::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6EnvironmentNodeClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048030 : DestroyAR6EnvironmentNodeClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6EnvironmentNodeClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6EnvironmentNode::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046290 : PublishAR6EnvironmentNodeAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6EnvironmentNodeAutoClass(void)
{
    autoclassAR6EnvironmentNode = &AR6EnvironmentNode::PrivateStaticClass;
}

// R6Engine.dll @ 10009bb0 : AR6EnvironmentNode::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6EnvironmentNode::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6EnvironmentNodeDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x3a0;
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
    this->AR6EnvironmentNode::~AR6EnvironmentNode();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x3a0;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
