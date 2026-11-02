#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl StatusStringExceptionHandler(void);
__declspec(naked) void __cdecl DestroyUR6SubActionLookAtClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004c2d0 : UR6SubActionLookAtVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: UR6SubActionLookAt::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix UR6SubActionLookAtVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055b44 : nativeTextLookAt
extern const ushort nativeTextLookAt[8];

// R6Engine.dll data @ 10055df6 : nativeTextR6SubActionLookAt
extern const ushort nativeTextR6SubActionLookAt[18];

// R6Engine.dll data @ 100844e8 : autoclassUR6SubActionLookAt
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassUR6SubActionLookAt = nullptr;

// R6Engine.dll @ 1000a610 : UR6SubActionLookAt::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl UR6SubActionLookAt::StaticClass(void)
{
    return &UR6SubActionLookAt::PrivateStaticClass; // Selected object at0x100835c8.
}

// R6Engine.dll @ 1000a620 : UR6SubActionLookAt::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl UR6SubActionLookAt::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    uint flagsWord = reinterpret_cast<uint&>(objectFlags);
    FName capturedName = objectName;
    struct AllocatePacketView { // Inferred eight-word outgoing packet at entryESP-0x20.
        UClass* classObject;
        UObject* outer;
        FName objectName;
        uint objectFlags;
        UObject* templateObject;
        FOutputDevice* error;
        UObject* extraObject;
        int finalZero;
    } packet;
    packet.finalZero = 0;
    packet.extraObject = nullptr;
    packet.error = (FOutputDevice*)error;
    UObject* capturedOuter = outer; // Read after the first three outgoing words have been placed.
    packet.templateObject = nullptr;
    packet.objectFlags = flagsWord;
    packet.objectName = capturedName;
    packet.outer = capturedOuter;
    packet.classObject = &UR6SubActionLookAt::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000a650 : UR6SubActionLookAt::~UR6SubActionLookAt
// Conditionally destroys UObject state while retaining base cleanup for an exceptional exit.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall UR6SubActionLookAt::~UR6SubActionLookAt(UR6SubActionLookAt* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&MatSubActionBaseCleanupExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    *(uint*)this = ((uint)&UR6SubActionLookAtVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->UMatSubAction::~UMatSubAction();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 1000a6b0 : UR6SubActionLookAt::UR6SubActionLookAt (native default view)
// Constructs the UMatSubAction base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; UR6SubActionLookAtVirtualTable follows base completion.
UR6SubActionLookAt::UR6SubActionLookAt() : UMatSubAction()
{
}

// R6Engine.dll @ 1000a6d0 : UR6SubActionLookAt::copy constructor
// Copy-constructs the base, individual flags and raw member values in native order.
// Native ABI view retains the destination flag snapshot before derived table publication.
UR6SubActionLookAt* __thiscall UR6SubActionLookAt::UR6SubActionLookAt(
    UR6SubActionLookAt* this, const UR6SubActionLookAt* source)
{
    const UR6SubActionLookAt* capturedSource = source;
    const UR6SubActionLookAt* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    UMatSubAction::UMatSubAction(this, baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x58);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x58);
    uint earlyFlags = *destinationFlags; // Sampled before derived vtable publication.
    *(uint*)this = ((uint)&UR6SubActionLookAtVirtualTable);
    uint difference = (earlyFlags ^ *sourceFlags) & 1U;
    uint copiedFlags = *destinationFlags ^ difference; // Native rereads the destination for the first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    this->m_AffectedPawn = capturedSource->m_AffectedPawn;
    this->m_TargetActor = capturedSource->m_TargetActor;
    return this; // Ignore base EAX; preserve forward operations even for aliased source storage.
}

// R6Engine.dll @ 1000a720 : UR6SubActionLookAt::operator=
// Assigns the base, individual flags and raw member values in native order.
UR6SubActionLookAt& __thiscall UR6SubActionLookAt::operator=(const UR6SubActionLookAt& sourceObject)
{
    const UR6SubActionLookAt* source = &sourceObject;
    const UR6SubActionLookAt* capturedSource = source;
    const UR6SubActionLookAt* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    this->UMatSubAction::operator=(*baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x58);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x58);
    uint sourceWord = *sourceFlags;
    uint earlyFlags = *destinationFlags;
    uint difference = (earlyFlags ^ sourceWord) & 1U;
    uint copiedFlags = *destinationFlags ^ difference; // Native rereads the destination for the first merge.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 2U;
    *destinationFlags = copiedFlags;
    this->m_AffectedPawn = capturedSource->m_AffectedPawn;
    this->m_TargetActor = capturedSource->m_TargetActor;
    return *this; // Ignore base EAX; preserve forward operations even for aliased source storage.
}

// R6Engine.dll @ 1000dff0 : UR6SubActionLookAt::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl UR6SubActionLookAt::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp UR6SubActionLookAtConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10040b60 : UR6SubActionLookAt::Update
// Updates the base action and applies actor tracking while the action is running and has an affected pawn.
int __thiscall UR6SubActionLookAt::Update(float scenePct, ASceneManager* sceneManager)
{
    ASceneManager* manager = sceneManager; // Native reads this incoming word before the percentage word.
    uint scenePctWord = reinterpret_cast<uint&>(scenePct);
    struct BasePacketView { // Inferred outgoing words at entryESP-0xc and entryESP-8.
        uint scenePct;
        ASceneManager* manager;
    } basePacket;
    basePacket.manager = manager;
    basePacket.scenePct = scenePctWord;
    int baseUpdated = this->UMatSubAction::Update(
        reinterpret_cast<const float&>(basePacket.scenePct), basePacket.manager);
    if (baseUpdated == 0)
        return 0;
    if (this->IsRunning() != 0) {
        AR6Pawn* affectedPawn = this->m_AffectedPawn; // +0x5c.
        if (affectedPawn != nullptr) {
            uint aimFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x58);
            AActor* targetActor = this->m_TargetActor; // +0x60.
            struct TrackPacketView { // Reuses the outgoing words at entryESP-0xc and entryESP-8.
                AActor* target;
                uint aim;
            } trackPacket;
            trackPacket.aim = aimFlags & 1U;
            trackPacket.target = targetActor;
            affectedPawn->AR6Pawn::PawnTrackActor(trackPacket.target, trackPacket.aim);
        }
    }
    return 1;
}

// R6Engine.dll @ 10040bb0 : UR6SubActionLookAt::GetStatString
// Appends the action label to the base status text and constructs the caller's result.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FString* __thiscall UR6SubActionLookAt::GetStatString(FString* result)
{
    // Descriptive FPO frame: unwind EBP is entry ESP; result mask -28, base -24, label -18, output argument +4.
    struct StatusFrame {
        uint savedESI, resultConstructed, baseWords[3], labelWords[3];
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &StatusStringExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FString* baseText = (FString*)nativeFrame.baseWords;
    FString* labelText = (FString*)nativeFrame.labelWords;
    FString* baseResultArgument = baseText; // Outgoing word at entryESP-0x30, before mask initialization.
    nativeFrame.resultConstructed = 0;
    using BaseText = FString* (__thiscall*)(UMatSubAction*, FString*);
    reinterpret_cast<BaseText&>(UMatSubActionGetStatStringImport)(this, baseResultArgument);
    struct FormatPacketView { // Inferred outgoing words at entryESP-0x34 and entryESP-0x30.
        FString* result;
        const ushort* format;
    } formatPacket;
    formatPacket.format = nativeTextLookAt;
    formatPacket.result = labelText;
    nativeFrame.exceptionState = 1;
    using Printf = FString* (__cdecl*)(FString*, const ushort*);
    FString* printedLabel = reinterpret_cast<Printf&>(FStringPrintfImport)(formatPacket.result, formatPacket.format);
    *(byte*)&nativeFrame.exceptionState = 2;
    const ushort* characters = printedLabel->operator*();
    const ushort* appendArgument = characters; // Reuses the outgoing word at entryESP-0x30.
    baseText->operator+=(appendArgument);
    *(byte*)&nativeFrame.exceptionState = 1;
    labelText->FString::~FString();
    FString* completedResult = result; // Native loads the hidden output word after the label destructor.
    const FString* copyArgument = baseText; // Placed after the late hidden-result capture.
    ::new (completedResult) FString(*copyArgument);
    nativeFrame.resultConstructed = 1;
    *(byte*)&nativeFrame.exceptionState = 0;
    baseText->FString::~FString();
    ExceptionList = nativeFrame.previousExceptionList;
    return completedResult; // Explicit native hidden-result pointer/RET4 view of the exported FString return.
}

// R6Engine.dll @ 10047c90 : InitializeUR6SubActionLookAtClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeUR6SubActionLookAtClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = UMatSubActionPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred local words at entryESP-8 and entryESP-4.
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
    packet.internalConstructor = &UR6SubActionLookAt::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload saved words after the configuration callback.
    parentClass = captures.parentClass;
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6SubActionLookAt;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x64;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&UR6SubActionLookAt::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyUR6SubActionLookAtClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100481d0 : DestroyUR6SubActionLookAtClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyUR6SubActionLookAtClassMetadata(void)
{
    __asm {
        mov ecx,offset UR6SubActionLookAt::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047d20 : PublishUR6SubActionLookAtAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishUR6SubActionLookAtAutoClass(void)
{
    autoclassUR6SubActionLookAt = &UR6SubActionLookAt::PrivateStaticClass;
}

// R6Engine.dll @ 1000a770 : UR6SubActionLookAt::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall UR6SubActionLookAt::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&UR6SubActionLookAtDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x64;
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
    this->UR6SubActionLookAt::~UR6SubActionLookAt();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x64;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
