#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6CoverSpotClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004ab10 : AR6CoverSpotVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6CoverSpot::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6CoverSpotVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100558e6 : nativeTextR6CoverSpot
extern const ushort nativeTextR6CoverSpot[12];

// R6Engine.dll data @ 1004f090 : nativeTextVoidAR6CoverSpotRenderEditorInfo
extern const ushort nativeTextVoidAR6CoverSpotRenderEditorInfo[36];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl CoverSpotRenderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl CoverSpotRenderCatchPointer(void);
__declspec(naked) void __cdecl CoverSpotRenderState1Cleanup(void);

// R6Engine.dll data @ 10058a2c : coverSpotRenderUnwindMap
// Retains completed-batcher cleanup and the exact renderer typed/context catch bindings.
const NativeUnwindEntry coverSpotRenderUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&CoverSpotRenderState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10058a44 : coverSpotRenderCatchMap
// Retains completed-batcher cleanup and the exact renderer typed/context catch bindings.
const NativeCatchEntry coverSpotRenderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&CoverSpotRenderCatchPointer) },
    { 0, 0, 0, ((uint)&CoverSpotRenderCatchContext) }
};

// R6Engine.dll data @ 10058a64 : coverSpotRenderTryMap
// Retains completed-batcher cleanup and the exact renderer typed/context catch bindings.
const NativeTryBlock coverSpotRenderTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&coverSpotRenderCatchMap) }
};

// R6Engine.dll data @ 10058a78 : coverSpotRenderFuncInfo
// Retains completed-batcher cleanup and the exact renderer typed/context catch bindings.
const NativeFunctionInfoPrefix coverSpotRenderFuncInfo = { 0x19930520, 0x3, ((uint)&coverSpotRenderUnwindMap), 0x1,
    ((uint)&coverSpotRenderTryMap), 0 };

// R6Engine.dll data @ 1007da00 : autoclassAR6CoverSpot
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6CoverSpot = nullptr;

// R6Engine.dll @ 100070c0 : AR6CoverSpot::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6CoverSpot::StaticClass(void)
{
    return &AR6CoverSpot::PrivateStaticClass; // Selected object at0x1007cfb0.
}

// R6Engine.dll @ 100070d0 : AR6CoverSpot::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6CoverSpot::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6CoverSpot::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10007100 : AR6CoverSpot::~AR6CoverSpot
// Runs conditional object cleanup, with implicit NavigationPoint destruction on normal or exceptional exit.
AR6CoverSpot::~AR6CoverSpot()
{
    // Compiler installs vtable1004ab10 first; shared FuncInfo10056d8c protects the base through state0.
    UObject::ConditionalDestroy();
    // Normal base call uses current IAT10049450 at state-1; shared cleanup10043230 uses saved EBP-0x10.
}

// R6Engine.dll @ 10007160 : AR6CoverSpot::AR6CoverSpot()
// Constructs NavigationPoint and installs the spot vtable without initializing the derived byte or padding.
AR6CoverSpot::AR6CoverSpot() : ANavigationPoint()
{
    // Publishes AR6CoverSpotVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10007180 : AR6CoverSpot::AR6CoverSpot(const AR6CoverSpot&)
// Copies the base, installs the spot vtable, then copies the current shot-direction byte.
AR6CoverSpot::AR6CoverSpot(const AR6CoverSpot& sourceObject) : ANavigationPoint(sourceObject)
{
    // Publishes AR6CoverSpotVirtualTable after base construction; native EAX retains original storage.
    AR6CoverSpot* spot = this;
    const AR6CoverSpot* source = &sourceObject;
    spot->m_eShotDir = source->m_eShotDir; // Exactly one byte at+0x3e8; adjacent bytes are retained.
}

// R6Engine.dll @ 100071b0 : AR6CoverSpot::operator=
// Assigns the base and shot-direction byte, preserving the vtable and three neighboring padding bytes.
AR6CoverSpot& __thiscall AR6CoverSpot::operator=(const AR6CoverSpot& sourceObject)
{
    AR6CoverSpot* spot = this;
    const AR6CoverSpot* source = &sourceObject;
    spot->ANavigationPoint::operator=(*source);
    spot->m_eShotDir = source->m_eShotDir; // No self-assignment shortcut or byte normalization.
    return *spot;
}

// R6Engine.dll @ 100071e0 : AR6CoverSpot::DeletingDestructor
// Destroys one marker or a cookie-counted array, optionally frees storage and returns the original address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6CoverSpot::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6CoverSpot* spot = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(spot) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6CoverSpotDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(spot) - 4;
        _eh_vector_destructor_iterator_(spot, 0x3ec, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current GMalloc is fetched after element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    spot->AR6CoverSpot::~AR6CoverSpot(); // Direct native10007100 call, without virtual dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(spot, 0x3ec);
    }
    return spot;
}

// R6Engine.dll @ 1000dc60 : AR6CoverSpot::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6CoverSpot::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6CoverSpotConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10016890 : AR6CoverSpot::RenderEditorInfo
// Draws two selected-cover cylinders with fresh location/interface snapshots and one cached draw target.
void __thiscall AR6CoverSpot::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* unusedInterface,
    FDynamicActor* unusedActor)
{
    AR6CoverSpot* spot = this;
    // Native read/test is state-1.
    bool selected = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(spot) + 0xac) & 0x4000U) != 0;
    using DestroyBatcher = void (__thiscall*)(FLineBatcher*);
    using DrawCylinder = void (__thiscall*)(FLineBatcher*, FRenderInterface*, FVector, FVector, FVector, FVector,
        uint, float, float, int); // Four-byte by-value color; seventeen native argument words.
    struct PendingBatcher {
        FLineBatcher* batcher;
        bool active;
        // Disables the native cleanup state before entering normal destruction.
        void Finish() {
            active = false;
            (*(DestroyBatcher*)&FLineBatcherDestructorImport)(batcher);
        }
        // Cleans completed batcher storage on exceptional exit.
        ~PendingBatcher() noexcept(false) {
            if (active) (*(DestroyBatcher*)&FLineBatcherDestructorImport)(batcher);
        }
    }; // Reference-only ownership view; actual native cleanup/frame metadata remains explicit below.
    try {
        if (!selected) return;
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* initialInterface = *(FRenderInterface**)(owner + 0x164);
        alignas(FLineBatcher) byte batcherStorage[0x24]; // Native EBP-0x70, before the plane at EBP-0x4c.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        // Constructor EAX is ignored.
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(initialInterface, 1, 0);
        PendingBatcher cleanup{batcher, true}; // State1 begins only after completed construction.
        FPlane plane(0.5f, 0.5f, 0.0f, 0.0f);
        FVector axisA, axisB, axisC; // Native EBP-0x3c/-0x30/-0x24, reused in a different order for draw2.
        axisC.X = 0.0f; axisC.Y = 0.0f; axisC.Z = 1.0f;
        axisB.X = 0.0f; axisB.Y = 1.0f; axisB.Z = 0.0f;
        axisA.X = 1.0f; axisA.Y = 0.0f; axisA.Z = 0.0f;
        uint packedColor; // Native color is constructed directly in the outgoing draw argument slot.
        // Uses original storage, not returned EAX.
        ::new (reinterpret_cast<void*>(&packedColor)) FColor(*reinterpret_cast<const FPlane*>(&plane));
        FVector drawZ, drawY, drawX, center;
        reinterpret_cast<uint&>(drawZ.X) = reinterpret_cast<const uint&>(axisC.X);
        reinterpret_cast<uint&>(drawZ.Y) = reinterpret_cast<const uint&>(axisC.Y);
        reinterpret_cast<uint&>(drawZ.Z) = reinterpret_cast<const uint&>(axisC.Z);
        uint yX = reinterpret_cast<const uint&>(axisB.X);
        uint yY = reinterpret_cast<const uint&>(axisB.Y);
        // Captured once after the first color conversion.
        DrawCylinder draw = reinterpret_cast<DrawCylinder&>(FLineBatcherDrawCylinderImport);
        reinterpret_cast<uint&>(drawY.X) = yX;
        reinterpret_cast<uint&>(drawY.Y) = yY;
        reinterpret_cast<uint&>(drawY.Z) = reinterpret_cast<const uint&>(axisB.Z);
        reinterpret_cast<uint&>(drawX.X) = reinterpret_cast<const uint&>(axisA.X);
        reinterpret_cast<uint&>(drawX.Y) = reinterpret_cast<const uint&>(axisA.Y);
        reinterpret_cast<uint&>(drawX.Z) = reinterpret_cast<const uint&>(axisA.Z);
        reinterpret_cast<uint&>(center.X) = reinterpret_cast<const uint&>(spot->Location.X);
        reinterpret_cast<uint&>(center.Y) = reinterpret_cast<const uint&>(spot->Location.Y);
        reinterpret_cast<uint&>(center.Z) = reinterpret_cast<const uint&>(spot->Location.Z);
        owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* drawInterface = *(FRenderInterface**)(owner + 0x164);
        draw(batcher, drawInterface, center, drawX, drawY, drawZ, packedColor, 40.0f, 64.0f, 8);
        plane.X = 0.35f; plane.Y = 0.35f; plane.Z = 0.0f; plane.W = 0.0f;
        axisA.X = 0.0f; axisA.Y = 0.0f; axisA.Z = 1.0f;
        axisB.X = 0.0f; axisB.Y = 1.0f; axisB.Z = 0.0f;
        axisC.X = 1.0f; axisC.Y = 0.0f; axisC.Z = 0.0f;
        ::new (reinterpret_cast<void*>(&packedColor)) FColor(*reinterpret_cast<const FPlane*>(&plane));
        reinterpret_cast<uint&>(drawZ.X) = reinterpret_cast<const uint&>(axisA.X);
        reinterpret_cast<uint&>(drawZ.Y) = reinterpret_cast<const uint&>(axisA.Y);
        reinterpret_cast<uint&>(drawZ.Z) = reinterpret_cast<const uint&>(axisA.Z);
        reinterpret_cast<uint&>(drawY.X) = reinterpret_cast<const uint&>(axisB.X);
        reinterpret_cast<uint&>(drawY.Y) = reinterpret_cast<const uint&>(axisB.Y);
        reinterpret_cast<uint&>(drawY.Z) = reinterpret_cast<const uint&>(axisB.Z);
        reinterpret_cast<uint&>(drawX.X) = reinterpret_cast<const uint&>(axisC.X);
        reinterpret_cast<uint&>(drawX.Y) = reinterpret_cast<const uint&>(axisC.Y);
        reinterpret_cast<uint&>(drawX.Z) = reinterpret_cast<const uint&>(axisC.Z);
        reinterpret_cast<uint&>(center.X) = reinterpret_cast<const uint&>(spot->Location.X);
        reinterpret_cast<uint&>(center.Y) = reinterpret_cast<const uint&>(spot->Location.Y);
        reinterpret_cast<uint&>(center.Z) = reinterpret_cast<const uint&>(spot->Location.Z);
        owner = *(byte**)((byte*)scene + 4);
        drawInterface = *(FRenderInterface**)(owner + 0x164);
        draw(batcher, drawInterface, center, drawX, drawY, drawZ, packedColor, 60.0f, 64.0f, 8);
        cleanup.Finish(); // State0 precedes normal destruction; destructor failure does not repeat cleanup.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6CoverSpot::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 10016acf : CoverSpotRenderCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl CoverSpotRenderCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10016ae3 : CoverSpotRenderCatchContext
// Reports RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl CoverSpotRenderCatchContext(void)
{
    __asm {
        push offset nativeTextVoidAR6CoverSpotRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043ce0 : CoverSpotRenderState1Cleanup
// Destroys original batcher storage at inherited dispatcher-frame EBP-0x70 through the current destructor import.
__declspec(naked) void __cdecl CoverSpotRenderState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x70]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10043ce9 : CoverSpotRenderExceptionHandler
// Supplies the exact renderer FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl CoverSpotRenderExceptionHandler(void)
{
    __asm {
        mov eax,offset coverSpotRenderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100469d0 : InitializeAR6CoverSpotClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6CoverSpotClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // ANavigationPoint object address, captured before config lookup.
    UClass* parentClass = ANavigationPointPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6CoverSpot::PrivateStaticClass, 0, 0x3ec, 0,
        parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6CoverSpot, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6CoverSpot::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6CoverSpotClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048100 : DestroyAR6CoverSpotClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6CoverSpotClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6CoverSpot::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046a60 : PublishAR6CoverSpotAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6CoverSpotAutoClass(void)
{
    autoclassAR6CoverSpot = &AR6CoverSpot::PrivateStaticClass;
}
