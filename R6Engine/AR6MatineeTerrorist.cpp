#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a5f8 : AR6MatineeTerroristVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6MatineeTerrorist::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6MatineeTerroristVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055592 : nativeTextR6MatineeTerrorist
extern const ushort nativeTextR6MatineeTerrorist[19];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void R6MatineeTerroristDtorExceptionHandler(void);
__declspec(naked) void R6MatineeTerroristDtorState0Cleanup(void);

// R6Engine.dll data @ 10056cf4 : r6MatineeTerroristDtorUnwind
// State zero destroys the base and terminates cleanup.
const NativeUnwindEntry r6MatineeTerroristDtorUnwind[1] = {
    { -1, ((uint)&R6MatineeTerroristDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056cfc : r6MatineeTerroristDtorInfo
// Destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix r6MatineeTerroristDtorInfo = { 0x19930520, 0x1, ((uint)&r6MatineeTerroristDtorUnwind), 0,
    0, 0 };

// R6Engine.dll data @ 1007c058 : autoclassAR6MatineeTerrorist
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6MatineeTerrorist = nullptr;

// R6Engine.dll @ 10006b00 : AR6MatineeTerrorist::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6MatineeTerrorist::StaticClass(void)
{
    return &AR6MatineeTerrorist::PrivateStaticClass; // Selected object at0x10076ec0.
}

// R6Engine.dll @ 10006b10 : AR6MatineeTerrorist::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6MatineeTerrorist::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    ulong capturedFlags = objectFlags; // Incoming ESP+10 precedes FName at +0c.
    FName capturedName = objectName;
    int zeroArgument7 = 0; // Outgoing ESP-4/-8/-0c precede the outer-object read.
    UObject* nullArgument6 = nullptr;
    FOutputDevice* errorArgument = (FOutputDevice*)error;
    UObject* outerArgument = outer;
    UObject* nullArgument4 = nullptr;
    ulong flagsArgument = capturedFlags;
    FName nameArgument = capturedName;
    // Eight cdecl words; the returned object pointer is unchanged.
    return UObject::StaticAllocateObject(&AR6MatineeTerrorist::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10006b40 : AR6MatineeTerrorist::~AR6MatineeTerrorist
// Conditionally destroys UObject state before entering base destruction.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6MatineeTerrorist::~AR6MatineeTerrorist(AR6MatineeTerrorist* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&R6MatineeTerroristDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6MatineeTerrorist* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6MatineeTerroristVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    AR6Terrorist* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed after preparing the base receiver.
    baseReceiver->AR6Terrorist::~AR6Terrorist();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10006b90 : AR6MatineeTerrorist::AR6MatineeTerrorist (native default-constructor view)
// Constructs the AR6Terrorist base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6MatineeTerroristVirtualTable follows base completion.
AR6MatineeTerrorist::AR6MatineeTerrorist() : AR6Terrorist()
{
}

// R6Engine.dll @ 10006bb0 : AR6MatineeTerrorist::AR6MatineeTerrorist (native copy-constructor view)
// Copies the base, selected flag bits and raw reference words in native read order.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6MatineeTerrorist* __thiscall AR6MatineeTerrorist::AR6MatineeTerrorist(
    AR6MatineeTerrorist* this, const AR6MatineeTerrorist* source)
{
    const AR6MatineeTerrorist* capturedSource = source;
    const AR6Terrorist* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    AR6Terrorist::AR6Terrorist(this, baseSourceArgument);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa9c);
    uint earlyFlags = *destinationFlagWord; // Sampled before derived vtable publication.
    *(uint*)this = ((uint)&AR6MatineeTerroristVirtualTable);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xa9c);
    uint flags = earlyFlags ^ ((sourceFlags ^ earlyFlags) & 1U);
    *destinationFlagWord = flags;
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_PrimaryWeapon = capturedSource->m_PrimaryWeapon;
    this->m_TerroristTemplate = capturedSource->m_TerroristTemplate;
    return this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 10006c10 : AR6MatineeTerrorist::operator=
// Copies the base, selected flag bits and raw reference words in native read order.
AR6MatineeTerrorist& __thiscall AR6MatineeTerrorist::operator=(const AR6MatineeTerrorist& sourceObject)
{
    const AR6MatineeTerrorist* source = &sourceObject;
    const AR6MatineeTerrorist* capturedSource = source;
    const AR6Terrorist* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    this->AR6Terrorist::operator=(*baseSourceArgument);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xa9c);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa9c);
    uint earlyFlags = *destinationFlagWord;
    uint flags = earlyFlags ^ ((sourceFlags ^ earlyFlags) & 1U);
    *destinationFlagWord = flags;
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_PrimaryWeapon = capturedSource->m_PrimaryWeapon;
    this->m_TerroristTemplate = capturedSource->m_TerroristTemplate;
    return *this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 1000dc30 : AR6MatineeTerrorist::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6MatineeTerrorist::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6MatineeTerroristConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100431f0 : R6MatineeTerroristDtorState0Cleanup
// Tail-enters base destruction through the inherited parent-frame saved receiver.
__declspec(naked) void R6MatineeTerroristDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6TerroristDestructorNativeEntry
    }
}

// R6Engine.dll @ 100431f8 : R6MatineeTerroristDtorExceptionHandler
// Selects the destructor's base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void R6MatineeTerroristDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset r6MatineeTerroristDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047f50 : DestroyAR6MatineeTerroristClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6MatineeTerroristClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6MatineeTerrorist::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100459d0 : InitializeAR6MatineeTerroristClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6MatineeTerroristClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred saved within-class word at entryESP-4.
        UClass* withinClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x50.
        int nativeConstructorTag;
        uint classSize;
        uint classFlags;
        UClass* parentClass;
        UClass* withinClass;
        uint guidWords[4];
        const ushort* className;
        const ushort* packageName;
        const ushort* configName;
        uint objectFlags;
        void (__cdecl* internalConstructor)(void*);
        union { // entryESP-0x18 is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6MatineeTerrorist::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6MatineeTerrorist;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Terrorist::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xaac;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6MatineeTerrorist::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6MatineeTerroristClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045a50 : PublishAR6MatineeTerroristAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6MatineeTerroristAutoClass(void)
{
    autoclassAR6MatineeTerrorist = &AR6MatineeTerrorist::PrivateStaticClass;
}

// R6Engine.dll @ 10006c70 : AR6MatineeTerrorist::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6MatineeTerrorist::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6MatineeTerroristDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xaac;
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
    this->AR6MatineeTerrorist::~AR6MatineeTerrorist();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xaac;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
