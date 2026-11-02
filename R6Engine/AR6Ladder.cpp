#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6LadderClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a7b0 : AR6LadderVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Ladder::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6LadderVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005571e : nativeTextR6Ladder
extern const ushort nativeTextR6Ladder[9];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void R6LadderDtorExceptionHandler(void);
__declspec(naked) void R6LadderDtorState0Cleanup(void);

// R6Engine.dll data @ 10056d18 : r6LadderDtorUnwind
// State zero destroys the base and terminates cleanup.
const NativeUnwindEntry r6LadderDtorUnwind[1] = {
    { -1, ((uint)&R6LadderDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056d20 : r6LadderDtorInfo
// Destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix r6LadderDtorInfo = { 0x19930520, 0x1, ((uint)&r6LadderDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1007ac0c : autoclassAR6Ladder
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Ladder = nullptr;

// R6Engine.dll @ 10006ce0 : AR6Ladder::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Ladder::StaticClass(void)
{
    return &AR6Ladder::PrivateStaticClass; // Selected object at0x1007ac18.
}

// R6Engine.dll @ 10006cf0 : AR6Ladder::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6Ladder::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
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
    return UObject::StaticAllocateObject(&AR6Ladder::PrivateStaticClass, outerArgument, nameArgument, flagsArgument,
        nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10006d20 : AR6Ladder::~AR6Ladder
// Conditionally destroys UObject state before entering base destruction.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6Ladder::~AR6Ladder(AR6Ladder* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&R6LadderDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6Ladder* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6LadderVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    ALadder* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed before reading the current imported base destructor.
    baseReceiver->ALadder::~ALadder();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10006d80 : AR6Ladder::AR6Ladder (native default-constructor view)
// Constructs the ALadder base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6LadderVirtualTable follows base completion.
AR6Ladder::AR6Ladder() : ALadder()
{
}

// R6Engine.dll @ 10006da0 : AR6Ladder::AR6Ladder (native copy-constructor view)
// Copies the base, selected flag bits and raw reference words in native read order.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6Ladder* __thiscall AR6Ladder::AR6Ladder(
    AR6Ladder* this, const AR6Ladder* source)
{
    const AR6Ladder* capturedSource = source;
    const ALadder* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    ALadder::ALadder(this, baseSourceArgument);
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3f0);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x3f0);
    uint earlyFlags = *destinationFlagWord; // Sampled before derived vtable publication.
    *(uint*)this = ((uint)&AR6LadderVirtualTable);
    uint sourceFlags = *sourceFlagWord;
    uint difference = earlyFlags ^ sourceFlags;
    uint flags = *destinationFlagWord ^ (difference & 1U); // Native second destination read.
    *destinationFlagWord = flags;
    for (uint mask = 2; mask != 8; mask <<= 1) {
        sourceFlags = *sourceFlagWord;
        flags ^= (sourceFlags ^ flags) & mask;
        *destinationFlagWord = flags; // Separate stores preserve upper twenty-nine bits.
    }
    this->m_pOtherFloor = capturedSource->m_pOtherFloor;
    return this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 10006e10 : AR6Ladder::operator=
// Copies the base, selected flag bits and raw reference words in native read order.
AR6Ladder& __thiscall AR6Ladder::operator=(const AR6Ladder& sourceObject)
{
    const AR6Ladder* source = &sourceObject;
    const AR6Ladder* capturedSource = source;
    const ALadder* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    this->ALadder::operator=(*baseSourceArgument);
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x3f0);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x3f0);
    uint sourceFlags = *sourceFlagWord;
    uint earlyFlags = *destinationFlagWord;
    uint difference = earlyFlags ^ sourceFlags;
    uint flags = *destinationFlagWord ^ (difference & 1U); // Native second destination read.
    *destinationFlagWord = flags;
    for (uint mask = 2; mask != 8; mask <<= 1) {
        sourceFlags = *sourceFlagWord;
        flags ^= (sourceFlags ^ flags) & mask;
        *destinationFlagWord = flags; // Separate stores preserve upper twenty-nine bits.
    }
    this->m_pOtherFloor = capturedSource->m_pOtherFloor;
    return *this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 1000dc40 : AR6Ladder::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Ladder::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6LadderConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10043210 : R6LadderDtorState0Cleanup
// Tail-enters base destruction through the inherited parent-frame saved receiver.
__declspec(naked) void R6LadderDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [ALadderDestructorImport]
    }
}

// R6Engine.dll @ 10043219 : R6LadderDtorExceptionHandler
// Selects the destructor's base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void R6LadderDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset r6LadderDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10046160 : InitializeAR6LadderClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6LadderClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = ALadderPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred within-class and parent words at entryESP-8/-4.
        UClass* withinClass;
        UClass* parentClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x54.
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
        union { // entryESP-0x1c is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6Ladder::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass;
    parentClass = captures.parentClass; // Both reloads precede placement of the returned configuration pointer.
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6Ladder;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x3f8;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6Ladder::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6LadderClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10048020 : DestroyAR6LadderClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6LadderClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Ladder::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100461f0 : PublishAR6LadderAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6LadderAutoClass(void)
{
    autoclassAR6Ladder = &AR6Ladder::PrivateStaticClass;
}

// R6Engine.dll @ 10006e80 : AR6Ladder::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6Ladder::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6LadderDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x3f8;
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
    this->AR6Ladder::~AR6Ladder();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x3f8;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
