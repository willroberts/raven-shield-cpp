#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 10049f18 : AR6MatineeHostageVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6MatineeHostage::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6MatineeHostageVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100555de : nativeTextR6MatineeHostage
extern const ushort nativeTextR6MatineeHostage[17];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void MatineeHostageDtorExceptionHandler(void);
__declspec(naked) void MatineeHostageDtorState0Cleanup(void);

// R6Engine.dll data @ 10056abc : matineeHostageDtorUnwind
// State zero destroys the Hostage base and terminates cleanup.
const NativeUnwindEntry matineeHostageDtorUnwind[1] = {
    { -1, ((uint)&MatineeHostageDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056ac4 : matineeHostageDtorInfo
// Matinee Hostage destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix matineeHostageDtorInfo = { 0x19930520, 0x1, ((uint)&matineeHostageDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1007b12c : autoclassAR6MatineeHostage
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6MatineeHostage = nullptr;

// R6Engine.dll @ 10005540 : AR6MatineeHostage::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6MatineeHostage::StaticClass(void)
{
    return &AR6MatineeHostage::PrivateStaticClass; // Selected object at0x1007a1c8.
}

// R6Engine.dll @ 10005550 : AR6MatineeHostage::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6MatineeHostage::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
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
    return UObject::StaticAllocateObject(&AR6MatineeHostage::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10005580 : AR6MatineeHostage::~AR6MatineeHostage
// Conditionally destroys UObject state before directly destroying the Hostage base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6MatineeHostage::~AR6MatineeHostage(AR6MatineeHostage* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&MatineeHostageDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6MatineeHostage* capturedThis = this;
    guard[0] = (uint)capturedThis; // Native repeats the saved-this write after saving ESI.
    *(uint*)capturedThis = ((uint)&AR6MatineeHostageVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    AR6Hostage* baseReceiver = capturedThis; // Prepared before the full state-minus-one store.
    guard[3] = 0xffffffff;
    baseReceiver->AR6Hostage::~AR6Hostage();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 100055d0 : AR6MatineeHostage::AR6MatineeHostage (native default-constructor view)
// Constructs the AR6Hostage base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6MatineeHostageVirtualTable follows base completion.
AR6MatineeHostage::AR6MatineeHostage() : AR6Hostage()
{
}

// R6Engine.dll @ 100055f0 : AR6MatineeHostage::AR6MatineeHostage (native copy-constructor view)
// Copies the Hostage base, template-selection bit and two reference words in native read order.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6MatineeHostage* __thiscall AR6MatineeHostage::AR6MatineeHostage(
    AR6MatineeHostage* this, const AR6MatineeHostage* source)
{
    const AR6MatineeHostage* capturedSource = source;
    const AR6Hostage* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    AR6Hostage::AR6Hostage(this, baseSourceArgument);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xae4);
    uint destinationFlags = *destinationFlagWord; // Native samples before publishing the derived vtable.
    *(uint*)this = ((uint)&AR6MatineeHostageVirtualTable);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xae4);
    *destinationFlagWord = destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_HostageTemplate = capturedSource->m_HostageTemplate;
    return this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 10005640 : AR6MatineeHostage::operator=
// Copies the Hostage base, template-selection bit and two reference words in native read order.
AR6MatineeHostage& __thiscall AR6MatineeHostage::operator=(const AR6MatineeHostage& sourceObject)
{
    const AR6MatineeHostage* source = &sourceObject;
    const AR6MatineeHostage* capturedSource = source;
    const AR6Hostage* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    this->AR6Hostage::operator=(*baseSourceArgument);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xae4);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xae4);
    uint destinationFlags = *destinationFlagWord;
    *destinationFlagWord = destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_HostageTemplate = capturedSource->m_HostageTemplate;
    return *this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 1000dbf0 : AR6MatineeHostage::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6MatineeHostage::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6MatineeHostageConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10042ff0 : MatineeHostageDtorState0Cleanup
// Tail-enters Hostage base destruction through the inherited parent-frame receiver.
__declspec(naked) void MatineeHostageDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6HostageDestructorNativeEntry
    }
}

// R6Engine.dll @ 10042ff8 : MatineeHostageDtorExceptionHandler
// Selects Matinee Hostage base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void MatineeHostageDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset matineeHostageDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047f70 : DestroyAR6MatineeHostageClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6MatineeHostageClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6MatineeHostage::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045af0 : InitializeAR6MatineeHostageClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6MatineeHostageClassMetadata(void)
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
    packet.internalConstructor = &AR6MatineeHostage::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6MatineeHostage;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Hostage::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xaf0;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6MatineeHostage::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6MatineeHostageClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045b70 : PublishAR6MatineeHostageAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6MatineeHostageAutoClass(void)
{
    autoclassAR6MatineeHostage = &AR6MatineeHostage::PrivateStaticClass;
}

// R6Engine.dll @ 10005690 : AR6MatineeHostage::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6MatineeHostage::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6MatineeHostageDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xaf0;
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
    this->AR6MatineeHostage::~AR6MatineeHostage();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xaf0;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
