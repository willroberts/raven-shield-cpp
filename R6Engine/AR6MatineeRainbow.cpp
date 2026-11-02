#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a288 : AR6MatineeRainbowVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6MatineeRainbow::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6MatineeRainbowVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100555ba : nativeTextR6MatineeRainbow
extern const ushort nativeTextR6MatineeRainbow[17];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void MatineeRainbowDtorExceptionHandler(void);
__declspec(naked) void MatineeRainbowDtorState0Cleanup(void);

// R6Engine.dll data @ 10056c14 : matineeRainbowDtorUnwind
// State zero destroys the Rainbow base and terminates cleanup.
const NativeUnwindEntry matineeRainbowDtorUnwind[1] = {
    { -1, ((uint)&MatineeRainbowDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056c1c : matineeRainbowDtorInfo
// Matinee Rainbow destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix matineeRainbowDtorInfo = { 0x19930520, 0x1, ((uint)&matineeRainbowDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10079c80 : autoclassAR6MatineeRainbow
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6MatineeRainbow = nullptr;

// R6Engine.dll @ 10006140 : AR6MatineeRainbow::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6MatineeRainbow::StaticClass(void)
{
    return &AR6MatineeRainbow::PrivateStaticClass; // Selected object at0x1007bb50.
}

// R6Engine.dll @ 10006150 : AR6MatineeRainbow::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6MatineeRainbow::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
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
    return UObject::StaticAllocateObject(&AR6MatineeRainbow::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10006180 : AR6MatineeRainbow::~AR6MatineeRainbow
// Conditionally destroys UObject state before directly destroying the Rainbow base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6MatineeRainbow::~AR6MatineeRainbow(AR6MatineeRainbow* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&MatineeRainbowDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6MatineeRainbow* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6MatineeRainbowVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    AR6Rainbow* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed after preparing the base receiver.
    baseReceiver->AR6Rainbow::~AR6Rainbow();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 100061d0 : AR6MatineeRainbow::AR6MatineeRainbow (native default-constructor view)
// Constructs the AR6Rainbow base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6MatineeRainbowVirtualTable follows base completion.
AR6MatineeRainbow::AR6MatineeRainbow() : AR6Rainbow()
{
}

// R6Engine.dll @ 100061f0 : AR6MatineeRainbow::AR6MatineeRainbow (native copy-constructor view)
// Copies the Rainbow base, two template/gadget bits and seven reference words in native read order.
// Native ABI view retains the destination flag snapshot before derived table publication.
AR6MatineeRainbow* __thiscall AR6MatineeRainbow::AR6MatineeRainbow(
    AR6MatineeRainbow* this, const AR6MatineeRainbow* source)
{
    const AR6MatineeRainbow* capturedSource = source;
    const AR6Rainbow* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    AR6Rainbow::AR6Rainbow(this, baseSourceArgument);
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xb14);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xb14);
    uint earlyFlags = *destinationFlagWord; // Native samples before publishing the derived vtable.
    *(uint*)this = ((uint)&AR6MatineeRainbowVirtualTable);
    uint sourceFlags = *sourceFlagWord;
    uint difference = earlyFlags ^ sourceFlags;
    uint destinationFlags = *destinationFlagWord;
    uint flags = destinationFlags ^ (difference & 1U);
    *destinationFlagWord = flags;
    sourceFlags = *sourceFlagWord;
    flags ^= (sourceFlags ^ flags) & 2U;
    *destinationFlagWord = flags; // Retain the upper thirty destination bits.
    this->m_controller = capturedSource->m_controller;
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_PrimaryWeapon = capturedSource->m_PrimaryWeapon;
    this->m_SecondaryWeapon = capturedSource->m_SecondaryWeapon;
    this->m_PrimaryGadget = capturedSource->m_PrimaryGadget;
    this->m_SecondaryGadget = capturedSource->m_SecondaryGadget;
    this->m_RainbowTemplate = capturedSource->m_RainbowTemplate;
    return this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 100062a0 : AR6MatineeRainbow::operator=
// Copies the Rainbow base, two template/gadget bits and seven reference words in native read order.
AR6MatineeRainbow& __thiscall AR6MatineeRainbow::operator=(const AR6MatineeRainbow& sourceObject)
{
    const AR6MatineeRainbow* source = &sourceObject;
    const AR6MatineeRainbow* capturedSource = source;
    const AR6Rainbow* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    this->AR6Rainbow::operator=(*baseSourceArgument);
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xb14);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xb14);
    uint sourceFlags = *sourceFlagWord;
    uint earlyFlags = *destinationFlagWord;
    uint difference = earlyFlags ^ sourceFlags;
    uint destinationFlags = *destinationFlagWord;
    uint flags = destinationFlags ^ (difference & 1U);
    *destinationFlagWord = flags;
    sourceFlags = *sourceFlagWord;
    flags ^= (sourceFlags ^ flags) & 2U;
    *destinationFlagWord = flags; // Retain the upper thirty destination bits.
    this->m_controller = capturedSource->m_controller;
    this->m_MatineeAttach = capturedSource->m_MatineeAttach;
    this->m_PrimaryWeapon = capturedSource->m_PrimaryWeapon;
    this->m_SecondaryWeapon = capturedSource->m_SecondaryWeapon;
    this->m_PrimaryGadget = capturedSource->m_PrimaryGadget;
    this->m_SecondaryGadget = capturedSource->m_SecondaryGadget;
    this->m_RainbowTemplate = capturedSource->m_RainbowTemplate;
    return *this; // Full original receiver; no self-assignment shortcut or local EH frame.
}

// R6Engine.dll @ 1000dc10 : AR6MatineeRainbow::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6MatineeRainbow::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6MatineeRainbowConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10043140 : MatineeRainbowDtorState0Cleanup
// Tail-enters Rainbow base destruction through the inherited parent-frame receiver.
__declspec(naked) void MatineeRainbowDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6RainbowDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043148 : MatineeRainbowDtorExceptionHandler
// Selects Matinee Rainbow base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void MatineeRainbowDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset matineeRainbowDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047f60 : DestroyAR6MatineeRainbowClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6MatineeRainbowClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6MatineeRainbow::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045a60 : InitializeAR6MatineeRainbowClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6MatineeRainbowClassMetadata(void)
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
    packet.internalConstructor = &AR6MatineeRainbow::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6MatineeRainbow;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Rainbow::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xb34;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6MatineeRainbow::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6MatineeRainbowClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045ae0 : PublishAR6MatineeRainbowAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6MatineeRainbowAutoClass(void)
{
    autoclassAR6MatineeRainbow = &AR6MatineeRainbow::PrivateStaticClass;
}

// R6Engine.dll @ 10006340 : AR6MatineeRainbow::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6MatineeRainbow::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6MatineeRainbowDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xb34;
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
    this->AR6MatineeRainbow::~AR6MatineeRainbow();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xb34;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
