#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6StairOrientationClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b9a0 : AR6StairOrientationVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6StairOrientation::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6StairOrientationVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100532e8 : nativeTextAR6StairOrientationPostScriptDestroyed
extern const ushort nativeTextAR6StairOrientationPostScriptDestroyed[41];

// R6Engine.dll data @ 1005589e : nativeTextR6StairOrientation
extern const ushort nativeTextR6StairOrientation[19];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl StairOrientationDestructionHookCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairOrientationDestructionHookCatchPointer(void);
__declspec(naked) void __cdecl StairOrientationDestructionHookExceptionHandler(void);

// R6Engine.dll data @ 1005d34c : stairOrientationDestructionHookUnwindMap
// Retains the destruction hook's catch-only states and exact typed/context handler bindings.
const NativeUnwindEntry stairOrientationDestructionHookUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d35c : stairOrientationDestructionHookCatchMap
// Retains the destruction hook's catch-only states and exact typed/context handler bindings.
const NativeCatchEntry stairOrientationDestructionHookCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&StairOrientationDestructionHookCatchPointer) },
    { 0, 0, 0, ((uint)&StairOrientationDestructionHookCatchContext) }
};

// R6Engine.dll data @ 1005d37c : stairOrientationDestructionHookTryMap
// Retains the destruction hook's catch-only states and exact typed/context handler bindings.
const NativeTryBlock stairOrientationDestructionHookTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stairOrientationDestructionHookCatchMap) }
};

// R6Engine.dll data @ 1005d390 : stairOrientationDestructionHookFuncInfo
// Retains the destruction hook's catch-only states and exact typed/context handler bindings.
const NativeFunctionInfoPrefix stairOrientationDestructionHookFuncInfo = {
    0x19930520, 0x2, ((uint)&stairOrientationDestructionHookUnwindMap), 0x1,
        ((uint)&stairOrientationDestructionHookTryMap), 0
};

// R6Engine.dll data @ 1007648c : autoclassAR6StairOrientation
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6StairOrientation = nullptr;

// R6Engine.dll @ 100092c0 : AR6StairOrientation::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6StairOrientation::StaticClass(void)
{
    return &AR6StairOrientation::PrivateStaticClass; // Selected object at0x1007f8b0.
}

// R6Engine.dll @ 100092d0 : AR6StairOrientation::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6StairOrientation::operator_new(uint allocationSize, UObject* outer,
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
    return UObject::StaticAllocateObject(&AR6StairOrientation::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10009300 : AR6StairOrientation::~AR6StairOrientation
// Conditionally destroys UObject state before destroying the Actor base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6StairOrientation::~AR6StairOrientation(AR6StairOrientation* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ActorBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6StairOrientation* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6StairOrientationVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    AActor* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed before reading the current base-destructor import.
    baseReceiver->AActor::~AActor();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10009360 : AR6StairOrientation::AR6StairOrientation()
// Constructs Actor, installs the orientation vtable and leaves the linked-volume field untouched.
AR6StairOrientation::AR6StairOrientation() : AActor()
{
    // Publishes AR6StairOrientationVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10009380 : AR6StairOrientation::AR6StairOrientation(const AR6StairOrientation&)
// Copies Actor, installs the derived vtable, then reads and copies the current four-byte volume link.
AR6StairOrientation::AR6StairOrientation(const AR6StairOrientation& sourceObject) : AActor(sourceObject)
{
    // Publishes AR6StairOrientationVirtualTable after base construction; native EAX retains original storage.
    AR6StairOrientation* orientation = this;
    const AR6StairOrientation* source = &sourceObject;
    const AR6StairOrientation* capturedSource = source; // EDI survives the base call.
    orientation->m_pStairVolume = capturedSource->m_pStairVolume;
}

// R6Engine.dll @ 100093b0 : AR6StairOrientation::operator=
// Assigns Actor and the current volume link without a self-assignment shortcut or derived vtable store.
AR6StairOrientation& __thiscall AR6StairOrientation::operator=(const AR6StairOrientation& sourceObject)
{
    AR6StairOrientation* orientation = this;
    const AR6StairOrientation* source = &sourceObject;
    const AR6StairOrientation* capturedSource = source; // EDI survives the base call.
    const AR6StairOrientation* sourceArgument = capturedSource; // Outgoing entryESP-0x0c.
    orientation->AActor::operator=(*sourceArgument);
    orientation->m_pStairVolume = capturedSource->m_pStairVolume;
    return *orientation;
}

// R6Engine.dll @ 100093e0 : AR6StairOrientation::DeletingDestructor
// Destroys one orientation or a counted array, optionally frees storage, and returns the receiver or cookie address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6StairOrientation::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Sample once before capturing the receiver.
    AR6StairOrientation* capturedOrientation = this; // Retained in ESI across destruction and deallocation.
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(capturedOrientation) - 4);
        using Destructor = void (__thiscall*)(void*);
        struct ArrayPacketView { // Inferred outgoing words at entryESP-0x1c..-0x10.
            void* elements;
            uint elementSize;
            int count;
            union { // The callback slot becomes the later allocator Free argument.
                Destructor callback;
                void* freeArgument;
            };
        } packet;
        packet.callback = reinterpret_cast<Destructor>(&AR6StairOrientationDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(capturedOrientation) - 4; // After count and callback placement.
        packet.count = count;
        packet.elementSize = 0x398;
        packet.elements = capturedOrientation;
        _eh_vector_destructor_iterator_(packet.elements, packet.elementSize, packet.count, packet.callback);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport; // Fetch current GMalloc after element destruction.
            NativeAllocatorVtablePrefix* allocatorVTable = *reinterpret_cast<NativeAllocatorVtablePrefix**>(allocator);
            packet.freeArgument = cookie;
            using Free = void (__thiscall*)(void*, void*);
            Free free = reinterpret_cast<Free&>(allocatorVTable->freeAddress);
            free(allocator, packet.freeArgument);
        }
        return cookie;
    }
    capturedOrientation->AR6StairOrientation::~AR6StairOrientation(); // Direct native10009300 call.
    if ((deleteFlags & 1U) != 0) {
        uint sizeArgument = 0x398; // Outgoing entryESP-0x0c precedes the object at -0x10.
        void* objectArgument = capturedOrientation;
        UObject::operator delete(objectArgument, sizeArgument);
    }
    return capturedOrientation;
}

// R6Engine.dll @ 1000df90 : AR6StairOrientation::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6StairOrientation::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6StairOrientationConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1003aff0 : AR6StairOrientation::linkWithStair
// Stores the supplied stair-volume pointer, including null, in the linked-volume field.
void __thiscall AR6StairOrientation::linkWithStair(AR6StairVolume* stairVolume)
{
    this->m_pStairVolume = stairVolume; // Four-byte store at +0x394; native callee discards the argument word.
}

// R6Engine.dll @ 1003b000 : AR6StairOrientation::PostScriptDestroyed
// Passes the captured linked volume, including null, to this actor's nonvirtual SafeDestroyActor.
void __thiscall AR6StairOrientation::PostScriptDestroyed(void)
{
    AR6StairOrientation* orientation = this;
    struct NativeFrameView { // Inferred stack words at EBP-0x24..-4, including saved registers.
        uint savedEDI;
        uint savedESI;
        uint savedEBX;
        uint caughtPointer;
        uint rethrowPointer;
        uint savedESP;
        void* previousException;
        uint handler;
        uint state;
    } frame;
    frame.state = 0xffffffff;
    frame.handler = ((uint)&StairOrientationDestructionHookExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    AActor* volume = orientation->m_pStairVolume; // Capture before savedESP and protected state0.
    frame.savedESP = (uint)&frame.savedEDI;
    AActor* volumeArgument = volume; // Outgoing entryESP-0x2c precedes the full state0 store.
    frame.state = 0;
    using SafeDestroy = void (__thiscall*)(AActor*, AActor*);
    SafeDestroy safeDestroy = reinterpret_cast<SafeDestroy&>(AActorSafeDestroyActorImport);
    safeDestroy(orientation, volumeArgument);
    void* previousException = frame.previousException;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException;
    uint restoredEBX = frame.savedEBX;
}

// R6Engine.dll @ 1003b046 : StairOrientationDestructionHookCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl StairOrientationDestructionHookCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003b05a : StairOrientationDestructionHookCatchContext
// Reports PostScriptDestroyed and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairOrientationDestructionHookCatchContext(void)
{
    __asm {
        push offset nativeTextAR6StairOrientationPostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044f40 : StairOrientationDestructionHookExceptionHandler
// Supplies the exact destruction-hook FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairOrientationDestructionHookExceptionHandler(void)
{
    __asm {
        mov eax,offset stairOrientationDestructionHookFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10046890 : InitializeAR6StairOrientationClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6StairOrientationClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = AActorPrivateStaticClassImport;
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
    packet.internalConstructor = &AR6StairOrientation::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass;
    parentClass = captures.parentClass; // Both reloads precede placement of the returned configuration pointer.
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6StairOrientation;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x398;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6StairOrientation::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6StairOrientationClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100480e0 : DestroyAR6StairOrientationClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6StairOrientationClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6StairOrientation::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046920 : PublishAR6StairOrientationAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6StairOrientationAutoClass(void)
{
    autoclassAR6StairOrientation = &AR6StairOrientation::PrivateStaticClass;
}
