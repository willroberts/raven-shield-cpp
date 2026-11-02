#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6StairVolumeClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b1b0 : AR6StairVolumeVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6StairVolume::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6StairVolumeVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100533e8 : nativeTextAR6StairVolumeAddMyMarker
extern const ushort nativeTextAR6StairVolumeAddMyMarker[28];

// R6Engine.dll data @ 100534fc : nativeTextAR6StairVolumeCheckForErrors
extern const ushort nativeTextAR6StairVolumeCheckForErrors[31];

// R6Engine.dll data @ 10053340 : nativeTextAR6StairVolumePostScriptDestroyed
extern const ushort nativeTextAR6StairVolumePostScriptDestroyed[36];

// R6Engine.dll data @ 100532a0 : nativeTextAR6StairVolumeRenderEditorInfo
extern const ushort nativeTextAR6StairVolumeRenderEditorInfo[33];

// R6Engine.dll data @ 10053388 : nativeTextR6StairOrientationSpawned
extern const ushort nativeTextR6StairOrientationSpawned[28];

// R6Engine.dll data @ 100558c6 : nativeTextR6StairVolume
extern const ushort nativeTextR6StairVolume[14];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl StairVolumeDestructionExceptionHandler(void);
__declspec(naked) void __cdecl StairVolumeDestructionState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeEditorRenderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeEditorRenderCatchPointer(void);
__declspec(naked) void __cdecl StairVolumeEditorRenderExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeMarkerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeMarkerCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumePostScriptDestroyedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumePostScriptDestroyedCatchPointer(void);
__declspec(naked) void __cdecl StairVolumePostScriptDestroyedExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeSpawnedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeSpawnedCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeValidationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeValidationCatchPointer(void);
__declspec(naked) void __cdecl StairVolumeValidationState1Cleanup(void);
__declspec(naked) void __cdecl StairVolumeValidationState2Cleanup(void);
__declspec(naked) void __cdecl StairVolumeValidationState3Cleanup(void);
__declspec(naked) void __cdecl StairVolumeValidationState4Cleanup(void);
__declspec(naked) void __cdecl StairVolumeValidationState5Cleanup(void);
__declspec(naked) void __cdecl StairVolumeValidationState6Cleanup(void);

// R6Engine.dll data @ 1005d46c : stairVolumeMarkerUnwindMap
// Retains the marker parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry stairVolumeMarkerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d47c : stairVolumeMarkerCatchMap
// Retains the marker parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry stairVolumeMarkerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -136, ((uint)&StairVolumeMarkerCatchPointer) },
    { 0, 0, 0, ((uint)&StairVolumeMarkerCatchContext) }
};

// R6Engine.dll data @ 1005d49c : stairVolumeMarkerTryMap
// Retains the marker parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock stairVolumeMarkerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stairVolumeMarkerCatchMap) }
};

// R6Engine.dll data @ 1005d4b0 : stairVolumeMarkerFuncInfo
// Retains the marker parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix stairVolumeMarkerFuncInfo = { 0x19930520, 0x2, ((uint)&stairVolumeMarkerUnwindMap), 0x1,
    ((uint)&stairVolumeMarkerTryMap), 0 };

// R6Engine.dll data @ 1005d4cc : stairVolumeValidationUnwindMap
// Retains six completed-string cleanups and the exact validation typed/context catch bindings.
const NativeUnwindEntry stairVolumeValidationUnwindMap[8] = {
    { -1, 0 },
    { 0, ((uint)&StairVolumeValidationState1Cleanup) },
    { 0, ((uint)&StairVolumeValidationState2Cleanup) },
    { 0, ((uint)&StairVolumeValidationState3Cleanup) },
    { 0, ((uint)&StairVolumeValidationState4Cleanup) },
    { 0, ((uint)&StairVolumeValidationState5Cleanup) },
    { 0, ((uint)&StairVolumeValidationState6Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d50c : stairVolumeValidationCatchMap
// Retains six completed-string cleanups and the exact validation typed/context catch bindings.
const NativeCatchEntry stairVolumeValidationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&StairVolumeValidationCatchPointer) },
    { 0, 0, 0, ((uint)&StairVolumeValidationCatchContext) }
};

// R6Engine.dll data @ 1005d52c : stairVolumeValidationTryMap
// Retains six completed-string cleanups and the exact validation typed/context catch bindings.
const NativeTryBlock stairVolumeValidationTryMap[1] = {
    { 0, 0x6, 0x7, 0x2, ((uint)&stairVolumeValidationCatchMap) }
};

// R6Engine.dll data @ 1005d540 : stairVolumeValidationFuncInfo
// Retains six completed-string cleanups and the exact validation typed/context catch bindings.
const NativeFunctionInfoPrefix stairVolumeValidationFuncInfo = { 0x19930520, 0x8,
    ((uint)&stairVolumeValidationUnwindMap), 0x1, ((uint)&stairVolumeValidationTryMap), 0 };

// R6Engine.dll data @ 1005d2ec : stairVolumeEditorRenderUnwindMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeUnwindEntry stairVolumeEditorRenderUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d2fc : stairVolumeEditorRenderCatchMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeCatchEntry stairVolumeEditorRenderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&StairVolumeEditorRenderCatchPointer) },
    { 0, 0, 0, ((uint)&StairVolumeEditorRenderCatchContext) }
};

// R6Engine.dll data @ 1005d31c : stairVolumeEditorRenderTryMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeTryBlock stairVolumeEditorRenderTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stairVolumeEditorRenderCatchMap) }
};

// R6Engine.dll data @ 1005d330 : stairVolumeEditorRenderFuncInfo
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeFunctionInfoPrefix stairVolumeEditorRenderFuncInfo = { 0x19930520, 0x2,
    ((uint)&stairVolumeEditorRenderUnwindMap), 0x1, ((uint)&stairVolumeEditorRenderTryMap), 0 };

// R6Engine.dll data @ 1005d3ac : stairVolumePostScriptDestroyedUnwindMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeUnwindEntry stairVolumePostScriptDestroyedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d3bc : stairVolumePostScriptDestroyedCatchMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeCatchEntry stairVolumePostScriptDestroyedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&StairVolumePostScriptDestroyedCatchPointer) },
    { 0, 0, 0, ((uint)&StairVolumePostScriptDestroyedCatchContext) }
};

// R6Engine.dll data @ 1005d3dc : stairVolumePostScriptDestroyedTryMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeTryBlock stairVolumePostScriptDestroyedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stairVolumePostScriptDestroyedCatchMap) }
};

// R6Engine.dll data @ 1005d3f0 : stairVolumePostScriptDestroyedFuncInfo
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeFunctionInfoPrefix stairVolumePostScriptDestroyedFuncInfo = {
    0x19930520, 0x2, ((uint)&stairVolumePostScriptDestroyedUnwindMap), 0x1,
        ((uint)&stairVolumePostScriptDestroyedTryMap), 0
};

// R6Engine.dll data @ 1005d40c : stairVolumeSpawnedUnwindMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeUnwindEntry stairVolumeSpawnedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d41c : stairVolumeSpawnedCatchMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeCatchEntry stairVolumeSpawnedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&StairVolumeSpawnedCatchPointer) },
    { 0, 0, 0, ((uint)&StairVolumeSpawnedCatchContext) }
};

// R6Engine.dll data @ 1005d43c : stairVolumeSpawnedTryMap
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeTryBlock stairVolumeSpawnedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&stairVolumeSpawnedCatchMap) }
};

// R6Engine.dll data @ 1005d450 : stairVolumeSpawnedFuncInfo
// Retains the native protected state and typed/context catch bindings without local cleanup.
const NativeFunctionInfoPrefix stairVolumeSpawnedFuncInfo = { 0x19930520, 0x2, ((uint)&stairVolumeSpawnedUnwindMap),
    0x1, ((uint)&stairVolumeSpawnedTryMap), 0 };

// R6Engine.dll data @ 10056df0 : stairVolumeDestructionUnwindMap
// Retains the native conditional-destruction state and its implicit physics-volume base cleanup.
const NativeUnwindEntry stairVolumeDestructionUnwindMap[1] = {
    { -1, ((uint)&StairVolumeDestructionState0Cleanup) }
};

// R6Engine.dll data @ 10056df8 : stairVolumeDestructionFuncInfo
// Retains the native conditional-destruction state and its implicit physics-volume base cleanup.
const NativeFunctionInfoPrefix stairVolumeDestructionFuncInfo = { 0x19930520, 0x1,
    ((uint)&stairVolumeDestructionUnwindMap), 0, 0, 0 };

// R6Engine.dll data @ 100802dc : autoclassAR6StairVolume
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6StairVolume = nullptr;

// R6Engine.dll @ 10007950 : AR6StairVolume::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6StairVolume::StaticClass(void)
{
    return &AR6StairVolume::PrivateStaticClass; // Selected object at0x1007b138.
}

// R6Engine.dll @ 10007960 : AR6StairVolume::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6StairVolume::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
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
    return UObject::StaticAllocateObject(&AR6StairVolume::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 100079a0 : AR6StairVolume::~AR6StairVolume
// Conditionally destroys UObject state before destroying the PhysicsVolume base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6StairVolume::~AR6StairVolume(AR6StairVolume* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&StairVolumeDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6StairVolume* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6StairVolumeVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    APhysicsVolume* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed before reading the current base-destructor import.
    baseReceiver->APhysicsVolume::~APhysicsVolume();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10007a00 : AR6StairVolume::AR6StairVolume()
// Constructs the physics-volume base, installs the stair vtable and leaves all derived fields untouched.
AR6StairVolume::AR6StairVolume() : APhysicsVolume()
{
    // Publishes AR6StairVolumeVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10007a20 : AR6StairVolume::AR6StairVolume(const AR6StairVolume&)
// Copies three stair bits and raw orientation fields, retaining the early destination snapshot before vtable setup.
// Native ABI view preserves the pre-publication destination flag snapshot.
AR6StairVolume* __thiscall AR6StairVolume::AR6StairVolume(AR6StairVolume* volume, const AR6StairVolume* source)
{
    const AR6StairVolume* capturedSource = source; // Retained in EDI across the base call.
    const AR6StairVolume* sourceArgument = capturedSource; // Outgoing entryESP-0x0c.
    using CopyBase = APhysicsVolume* (__thiscall*)(APhysicsVolume*, const APhysicsVolume*);
    reinterpret_cast<CopyBase&>(APhysicsVolumeCopyConstructorImport)(volume,
        sourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(volume) + 0x478);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x478);
    uint earlyFlags = *destinationFlags;
    *(uint*)volume = ((uint)&AR6StairVolumeVirtualTable);
    uint difference = earlyFlags ^ *sourceFlags;
    uint flags = *destinationFlags;
    flags ^= difference & 1U; // m_bCreateIcon; native rereads destination after fetching source.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bRestrictedSpaceAtStairLimits.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U; // m_bShowLog.
    *destinationFlags = flags;
    volume->m_pStairOrientation = capturedSource->m_pStairOrientation;
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.X);
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.Y);
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.Z);
    return volume;
}

// R6Engine.dll @ 10007ab0 : AR6StairVolume::operator=
// Assigns the base and selected stair fields without replacing its vtable or copying unrelated flag bits.
AR6StairVolume& __thiscall AR6StairVolume::operator=(const AR6StairVolume& sourceObject)
{
    AR6StairVolume* volume = this;
    const AR6StairVolume* source = &sourceObject;
    const AR6StairVolume* capturedSource = source; // Retained in EDI across the base call.
    const AR6StairVolume* sourceArgument = capturedSource; // Outgoing entryESP-0x0c.
    volume->APhysicsVolume::operator=(*sourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(volume) + 0x478);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x478);
    uint sourceWord = *sourceFlags; // Unlike copy construction, the first post-base flag read is from source.
    uint earlyFlags = *destinationFlags;
    uint difference = earlyFlags ^ sourceWord;
    uint flags = *destinationFlags;
    flags ^= difference & 1U;
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U;
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 4U;
    *destinationFlags = flags;
    volume->m_pStairOrientation = capturedSource->m_pStairOrientation;
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.X) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.X);
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.Y);
    reinterpret_cast<uint&>(volume->m_vOrientationNorm.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_vOrientationNorm.Z);
    return *volume;
}

// R6Engine.dll @ 10007b40 : AR6StairVolume::DeletingDestructor
// Destroys one volume or a counted array, optionally frees storage, and returns the receiver or cookie address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6StairVolume::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Sample once before capturing the receiver.
    AR6StairVolume* capturedVolume = this; // Retained in ESI across destruction and deallocation.
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(capturedVolume) - 4);
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
        packet.callback = reinterpret_cast<Destructor>(&AR6StairVolumeDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(capturedVolume) - 4; // After count and callback placement.
        packet.count = count;
        packet.elementSize = 0x48c;
        packet.elements = capturedVolume;
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
    capturedVolume->AR6StairVolume::~AR6StairVolume(); // Direct native100079a0 call.
    if ((deleteFlags & 1U) != 0) {
        uint sizeArgument = 0x48c; // Outgoing entryESP-0x0c precedes the object at -0x10.
        void* objectArgument = capturedVolume;
        UObject::operator delete(objectArgument, sizeArgument);
    }
    return capturedVolume;
}

// R6Engine.dll @ 1000dca0 : AR6StairVolume::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6StairVolume::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6StairVolumeConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1003af40 : AR6StairVolume::RenderEditorInfo
// Renders the base actor, then propagates its set bSelected flag (0x4000) to a nonnull linked orientation.
void __thiscall AR6StairVolume::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* renderer,
    FDynamicActor* dynamicActor)
{
    AR6StairVolume* volume = this;
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
    frame.handler = ((uint)&StairVolumeEditorRenderExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    FDynamicActor* capturedDynamicActor = dynamicActor; // Third incoming word is read first.
    FLevelSceneNode* capturedScene = scene;
    frame.savedESP = (uint)&frame.savedEDI;
    AR6StairVolume* capturedVolume = volume; // Retained in ESI across the base call.
    FRenderInterface* capturedRenderer = renderer;
    FDynamicActor* dynamicArgument = capturedDynamicActor; // Outgoing entryESP-0x2c/-0x30/-0x34.
    FRenderInterface* rendererArgument = capturedRenderer;
    FLevelSceneNode* sceneArgument = capturedScene;
    frame.state = 0;
    using RenderBase = void (__thiscall*)(AActor*, FLevelSceneNode*, FRenderInterface*, FDynamicActor*);
    RenderBase renderBase = reinterpret_cast<RenderBase&>(AActorRenderEditorInfoImport);
    renderBase(capturedVolume, sceneArgument, rendererArgument, dynamicArgument);
    // Current flags after base effects.
    uint selectedFlags = *reinterpret_cast<uint*>(reinterpret_cast<byte*>(capturedVolume) + 0xac);
    if ((selectedFlags & 0x4000U) != 0) {
        AR6StairOrientation* orientation = capturedVolume->m_pStairOrientation;
        if (orientation != nullptr) *reinterpret_cast<uint*>(reinterpret_cast<byte*>(orientation) + 0xac) |= 0x4000U;
    }
    void* previousException = frame.previousException;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException;
    uint restoredEBX = frame.savedEBX;
}

// R6Engine.dll @ 1003b080 : AR6StairVolume::PostScriptDestroyed
// Passes the captured linked orientation, including null, to this actor's nonvirtual SafeDestroyActor.
void __thiscall AR6StairVolume::PostScriptDestroyed(void)
{
    AR6StairVolume* volume = this;
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
    frame.handler = ((uint)&StairVolumePostScriptDestroyedExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    AActor* orientation = volume->m_pStairOrientation; // Capture before savedESP and protected state0.
    frame.savedESP = (uint)&frame.savedEDI;
    AActor* orientationArgument = orientation; // Outgoing entryESP-0x2c precedes the full state0 store.
    frame.state = 0;
    using SafeDestroy = void (__thiscall*)(AActor*, AActor*);
    SafeDestroy safeDestroy = reinterpret_cast<SafeDestroy&>(AActorSafeDestroyActorImport);
    safeDestroy(volume, orientationArgument);
    void* previousException = frame.previousException;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException;
    uint restoredEBX = frame.savedEBX;
}

// R6Engine.dll @ 1003b100 : AR6StairVolume::Spawned
// Spawns an orientation at the volume's transform, links it back and sets its bDirectional actor flag (0x2000).
void __thiscall AR6StairVolume::Spawned(void)
{
    AR6StairVolume* volume = this;
    // Captured before state0; imported address of UClass metadata.
    UClass* classClass = UClassPrivateStaticClassImport;
    try {
        UClass* orientationClass = static_cast<UClass*>(UObject::StaticFindObjectChecked(classClass,
            reinterpret_cast<UObject*>(0xffffffffU), (const ushort*)L"R6StairOrientation", 0));
        ULevel* level = volume->XLevel; // Captured before both by-value transform snapshots.
        FRotator rotation;
        rotation.Pitch = volume->Rotation.Pitch;
        rotation.Yaw = volume->Rotation.Yaw;
        rotation.Roll = volume->Rotation.Roll;
        FVector location;
        reinterpret_cast<uint&>(location.X) = reinterpret_cast<const uint&>(volume->Location.X);
        reinterpret_cast<uint&>(location.Y) = reinterpret_cast<const uint&>(volume->Location.Y);
        reinterpret_cast<uint&>(location.Z) = reinterpret_cast<const uint&>(volume->Location.Z);
        using Spawn = AActor* (__thiscall*)(ULevel*, UClass*, uint, FVector, FRotator, AActor*,
            int, int, AActor*, APawn*);
        Spawn spawn = *(Spawn*)(*(byte**)level + 0xa8); // Current slot after argument copies; FName is one word.
        AR6StairOrientation* orientation = static_cast<AR6StairOrientation*>(spawn(level, orientationClass, 0, location,
            rotation, nullptr, 0, 0, nullptr, nullptr));
        volume->m_pStairOrientation = orientation;
        orientation->m_pStairVolume = volume; // Unchecked result; a null spawn result faults here in the native method.
        orientation = volume->m_pStairOrientation; // Reload after the back-pointer write.
        *reinterpret_cast<uint*>(reinterpret_cast<byte*>(orientation) + 0xac) |= 0x2000U;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"R6StairOrientation::Spawned"); // Native report label.
        throw;
    }
}

// R6Engine.dll @ 1003afb2 : StairVolumeEditorRenderCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeEditorRenderCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003afc6 : StairVolumeEditorRenderCatchContext
// Reports the native method label and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeEditorRenderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6StairVolumeRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003b0c6 : StairVolumePostScriptDestroyedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumePostScriptDestroyedCatchPointer(void)
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

// R6Engine.dll @ 1003b0da : StairVolumePostScriptDestroyedCatchContext
// Reports the native method label and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumePostScriptDestroyedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6StairVolumePostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003b1d1 : StairVolumeSpawnedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeSpawnedCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x14]
        push ecx
        mov dword ptr [ebp-0x14],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003b1e5 : StairVolumeSpawnedCatchContext
// Reports the native method label and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeSpawnedCatchContext(void)
{
    __asm {
        push offset nativeTextR6StairOrientationSpawned
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044f30 : StairVolumeEditorRenderExceptionHandler
// Supplies the exact method FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumeEditorRenderExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumeEditorRenderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f50 : StairVolumePostScriptDestroyedExceptionHandler
// Supplies the exact method FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumePostScriptDestroyedExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumePostScriptDestroyedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f60 : StairVolumeSpawnedExceptionHandler
// Supplies the exact method FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumeSpawnedExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumeSpawnedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003b210 : AR6StairVolume::AddMyMarker
// Finds the stair axis, searches both volume limits and spawns top/bottom navigation markers with planning metadata.
void __thiscall AR6StairVolume::AddMyMarker(AActor* scout)
{
    AR6StairVolume* volume = this;
    const byte* stairFlagByte = reinterpret_cast<const byte*>(volume) + 0x478;
    using Encompasses = int (__thiscall*)(AVolume*, FVector);
    using GetPrimitive = UPrimitive* (__thiscall*)(AActor*);
    using Trace = int (__thiscall*)(ULevel*, NativeCheckResult32*, AActor*, const FVector*, const FVector*, uint,
        FVector);
    using LineCheck = int (__thiscall*)(UPrimitive*, NativeCheckResult32*, AActor*, FVector, FVector, FVector,
        uint, uint);
    using Spawn = AActor* (__thiscall*)(ULevel*, UClass*, uint, FVector, FRotator, AActor*, int, int, AActor*, APawn*);
    try {
        if (scout == nullptr) return;
        UClass* scoutClass = AScoutPrivateStaticClassImport;
        if (scout->UObject::IsA(scoutClass) == 0) return;
        UClass* classClass = UClassPrivateStaticClassImport;
        UClass* markerClass = static_cast<UClass*>(UObject::StaticFindObjectChecked(classClass,
            reinterpret_cast<UObject*>(0xffffffffU), (const ushort*)L"R6Stairs", 0));
        // Original scout is only a gate; neither spawn uses it as Template.
        NativeCheckResult32 hit = {};
        hit.Time = 1.0f;
        hit.Item = -1;
        FVector floor = {0.0f, 0.0f, 0.0f};
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        if (volume->PrePivot.X != zero->X || volume->PrePivot.Y != zero->Y || volume->PrePivot.Z != zero->Z) {
            float10 z = (float10)volume->Location.Z - (float10)volume->PrePivot.Z;
            float10 y = (float10)volume->Location.Y - (float10)volume->PrePivot.Y;
            float10 x = (float10)volume->Location.X - (float10)volume->PrePivot.X;
            volume->Location.X = (float)x;
            volume->Location.Y = (float)y;
            volume->Location.Z = (float)z;
            zero = *(const FVector**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(volume->PrePivot.X) = reinterpret_cast<const uint&>(zero->X);
            reinterpret_cast<uint&>(volume->PrePivot.Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(volume->PrePivot.Z) = reinterpret_cast<const uint&>(zero->Z);
            zero = *(const FVector**)&FVectorFVector0Import;
        }
        AR6StairOrientation* orientation = volume->m_pStairOrientation;
        float10 downZ = (float10)orientation->Location.Z - (float10)400.0f;
        uint startX = reinterpret_cast<const uint&>(orientation->Location.X);
        ULevel* level = volume->XLevel;
        FVector endpoint;
        endpoint.Y = (float)(float10)orientation->Location.Y;
        reinterpret_cast<uint&>(endpoint.X) = startX;
        endpoint.Z = (float)downZ;
        byte* table = *(byte**)level; // First trace captures table before extent, then reloads receiver.
        FVector extent;
        reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
        reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
        reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
        level = volume->XLevel;
        (*(Trace*)(table + 0xcc))(level, &hit, volume, &endpoint, &orientation->Location, 0x86, extent);
        if (hit.Time != 1.0f) {
            reinterpret_cast<uint&>(floor.X) = reinterpret_cast<const uint&>(hit.Location.X);
            reinterpret_cast<uint&>(floor.Y) = reinterpret_cast<const uint&>(hit.Location.Y);
            reinterpret_cast<uint&>(floor.Z) = reinterpret_cast<const uint&>(hit.Location.Z);
        } else {
            FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
            log->FOutputDevice::Logf((const ushort*)L" problem, can't find the stairs under the volume...");
        }
        float10 raisedZ = (float10)floor.Z + (float10)5.0f;
        floor.Z = (float)raisedZ; // Native FST does not pop; the first endpoint keeps the same extended value.
        level = volume->XLevel;
        float10 probeY = (float10)floor.Y + (float10)40.0f;
        reinterpret_cast<uint&>(endpoint.X) = reinterpret_cast<const uint&>(floor.X);
        zero = *(const FVector**)&FVectorFVector0Import;
        endpoint.Y = (float)probeY;
        FVector direction = {0.0f, 0.0f, 0.0f};
        endpoint.Z = (float)raisedZ;
        reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
        table = *(byte**)level;
        reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
        reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
        (*(Trace*)(table + 0xcc))(level, &hit, volume, &endpoint, &floor, 0x86, extent);
        if (hit.Time != 1.0f) {
            direction.Y = 1.0f;
        } else {
            float10 endZ = (float10)floor.Z;
            uint floorX = reinterpret_cast<const uint&>(floor.X);
            float10 endY = (float10)floor.Y;
            level = volume->XLevel;
            endY -= (float10)40.0f;
            reinterpret_cast<uint&>(endpoint.X) = floorX;
            zero = *(const FVector**)&FVectorFVector0Import;
            endpoint.Y = (float)endY;
            endpoint.Z = (float)endZ;
            reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
            table = *(byte**)level;
            reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
            (*(Trace*)(table + 0xcc))(level, &hit, volume, &endpoint, &floor, 0x86, extent);
            if (hit.Time != 1.0f) {
                direction.Y = -1.0f;
            } else {
                endZ = (float10)floor.Z;
                zero = *(const FVector**)&FVectorFVector0Import;
                endY = (float10)floor.Y;
                level = volume->XLevel;
                float10 endX = (float10)floor.X + (float10)40.0f;
                endpoint.X = (float)endX;
                endpoint.Y = (float)endY;
                endpoint.Z = (float)endZ;
                reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
                table = *(byte**)level;
                reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
                reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
                (*(Trace*)(table + 0xcc))(level, &hit, volume, &endpoint, &floor, 0x86, extent);
                if (hit.Time != 1.0f) {
                    direction.X = 1.0f;
                } else {
                    endZ = (float10)floor.Z;
                    zero = *(const FVector**)&FVectorFVector0Import;
                    endY = (float10)floor.Y;
                    level = volume->XLevel;
                    endX = (float10)floor.X - (float10)40.0f;
                    endpoint.X = (float)endX;
                    endpoint.Y = (float)endY;
                    endpoint.Z = (float)endZ;
                    reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
                    table = *(byte**)level;
                    reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
                    reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
                    (*(Trace*)(table + 0xcc))(level, &hit, volume, &endpoint, &floor, 0x86, extent);
                    if (hit.Time != 1.0f) direction.X = -1.0f;
                    else {
                        FOutputDevice* log = **(FOutputDevice***)&CoreGLogImport;
                        log->FOutputDevice::Logf((const ushort*)L"  PROBLEM!! could not find direction of stairs ");
                    } // Four misses retain the initially zero direction, not a fallback axis.
                }
            }
        }
        zero = *(const FVector**)&FVectorFVector0Import;
        direction.Z = 0.0f;
        FRotator rotationStorage;
        if (direction.X != zero->X || direction.Y != zero->Y || nativeFloatZero != zero->Z) {
            FRotator* returned = &(rotationStorage = direction.Rotation());
            orientation = volume->m_pStairOrientation;
            reinterpret_cast<uint&>(orientation->Rotation.Pitch) = reinterpret_cast<const uint&>(returned->Pitch);
            reinterpret_cast<uint&>(orientation->Rotation.Yaw) = reinterpret_cast<const uint&>(returned->Yaw);
            reinterpret_cast<uint&>(orientation->Rotation.Roll) = reinterpret_cast<const uint&>(returned->Roll);
        }
        orientation = volume->m_pStairOrientation;
        FRotator travelRotation;
        travelRotation.Roll = orientation->Rotation.Roll;
        travelRotation.Yaw = orientation->Rotation.Yaw;
        travelRotation.Pitch = (int)((uint)orientation->Rotation.Pitch + 0x12e4U);
        FVector vectorStorage;
        const FVector* returnedVector = &(vectorStorage = travelRotation.Vector());
        FVector travel;
        reinterpret_cast<uint&>(travel.X) = reinterpret_cast<const uint&>(returnedVector->X);
        reinterpret_cast<uint&>(travel.Y) = reinterpret_cast<const uint&>(returnedVector->Y);
        uint travelZ = reinterpret_cast<const uint&>(returnedVector->Z);
        orientation = volume->m_pStairOrientation;
        reinterpret_cast<uint&>(travel.Z) = travelZ;
        // float10 records unspilled x87 work; the native caller's precision/rounding modes remain in effect.
        float10 scaledZ = (float10)travel.Z * (float10)1000.0f;
        Encompasses encompasses = reinterpret_cast<Encompasses&>(AVolumeEncompassesImport);
        float scaledY = (float)((float10)travel.Y * (float10)1000.0f);
        float scaledX = (float)((float10)travel.X * (float10)1000.0f);
        float10 pointZ = scaledZ + (float10)orientation->Location.Z;
        float10 pointY = (float10)scaledY + (float10)orientation->Location.Y;
        float10 pointX = (float10)scaledX + (float10)orientation->Location.X;
        FVector outside;
        outside.X = (float)pointX;
        outside.Y = (float)pointY;
        outside.Z = (float)pointZ;
        while (encompasses(volume, outside) != 0) {
            float10 stepX = (float10)travel.X * (float10)500.0f;
            float10 stepY = (float10)travel.Y * (float10)500.0f;
            float stepZ = (float)((float10)travel.Z * (float10)500.0f);
            outside.X = (float)(stepX + (float10)outside.X);
            outside.Y = (float)(stepY + (float10)outside.Y);
            outside.Z = (float)((float10)stepZ + (float10)outside.Z);
        } // No iteration cap, including zero travel vectors; target is cached for this entire loop.
        UPrimitive* primitive = (*(GetPrimitive*)(*(byte**)volume + 0xc0))(volume);
        zero = *(const FVector**)&FVectorFVector0Import;
        reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
        reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
        reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
        orientation = volume->m_pStairOrientation;
        FVector end;
        reinterpret_cast<uint&>(end.X) = reinterpret_cast<const uint&>(orientation->Location.X);
        reinterpret_cast<uint&>(end.Y) = reinterpret_cast<const uint&>(orientation->Location.Y);
        reinterpret_cast<uint&>(end.Z) = reinterpret_cast<const uint&>(orientation->Location.Z);
        (*(LineCheck*)(*(byte**)primitive + 0x68))(primitive, &hit, volume, end, outside, extent, 0, 0);
        FVector spawnPoint;
        if ((*stairFlagByte & 2U) != 0) {
            scaledZ = (float10)travel.Z * (float10)100.0f;
            scaledY = (float)((float10)travel.Y * (float10)100.0f);
            scaledX = (float)((float10)travel.X * (float10)100.0f);
            pointZ = (float10)hit.Location.Z - scaledZ;
            pointY = (float10)hit.Location.Y - (float10)scaledY;
            pointX = (float10)hit.Location.X - (float10)scaledX;
            spawnPoint.X = (float)pointX;
            spawnPoint.Y = (float)pointY;
            spawnPoint.Z = (float)pointZ;
        } else {
            reinterpret_cast<uint&>(spawnPoint.Y) = reinterpret_cast<const uint&>(hit.Location.Y);
            reinterpret_cast<uint&>(spawnPoint.Z) = reinterpret_cast<const uint&>(hit.Location.Z);
            reinterpret_cast<uint&>(spawnPoint.X) = reinterpret_cast<const uint&>(hit.Location.X);
        }
        float10 negativeZ = -(float10)travel.Z;
        level = volume->XLevel; // Captured before Rotation; table/slot are fetched after its result copy.
        float10 negativeY = -(float10)travel.Y;
        float10 negativeX = -(float10)travel.X;
        FVector reversed;
        reversed.X = (float)negativeX;
        reversed.Y = (float)negativeY;
        reversed.Z = (float)negativeZ;
        FRotator* returnedRotation = &(rotationStorage = reversed.Rotation());
        FRotator spawnRotation;
        spawnRotation.Pitch = returnedRotation->Pitch;
        spawnRotation.Yaw = returnedRotation->Yaw;
        spawnRotation.Roll = returnedRotation->Roll;
        AActor* first = (*(Spawn*)(*(byte**)level + 0xa8))(level, markerClass, 0, spawnPoint, spawnRotation,
            nullptr, 0, 0, nullptr, nullptr);
        if (first != nullptr) {
            first->m_iPlanningFloor_0 = volume->m_iPlanningFloor_0;
            uint markerFlags = *reinterpret_cast<const uint*>(reinterpret_cast<byte*>(first) + 0x3e8);
            int floor1 = volume->m_iPlanningFloor_1;
            markerFlags |= 1U; // AR6Stairs::m_bIsTopOfStairs.
            first->m_iPlanningFloor_1 = floor1;
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(first) + 0x3e8) = markerFlags;
        }
        scaledZ = (float10)travel.Z * (float10)1000.0f;
        orientation = volume->m_pStairOrientation;
        // Second loop takes a fresh import target, then retains it.
        encompasses = reinterpret_cast<Encompasses&>(AVolumeEncompassesImport);
        scaledY = (float)((float10)travel.Y * (float10)1000.0f);
        scaledX = (float)((float10)travel.X * (float10)1000.0f);
        pointZ = (float10)orientation->Location.Z - scaledZ;
        pointY = (float10)orientation->Location.Y - (float10)scaledY;
        pointX = (float10)orientation->Location.X - (float10)scaledX;
        outside.X = (float)pointX;
        outside.Y = (float)pointY;
        outside.Z = (float)pointZ;
        while (encompasses(volume, outside) != 0) {
            float10 stepX = (float10)travel.X * (float10)500.0f;
            float10 stepY = (float10)travel.Y * (float10)500.0f;
            float stepZ = (float)((float10)travel.Z * (float10)500.0f);
            outside.X = (float)((float10)outside.X - stepX);
            outside.Y = (float)((float10)outside.Y - stepY);
            outside.Z = (float)((float10)outside.Z - (float10)stepZ);
        }
        primitive = (*(GetPrimitive*)(*(byte**)volume + 0xc0))(volume);
        zero = *(const FVector**)&FVectorFVector0Import;
        reinterpret_cast<uint&>(extent.X) = reinterpret_cast<const uint&>(zero->X);
        reinterpret_cast<uint&>(extent.Y) = reinterpret_cast<const uint&>(zero->Y);
        reinterpret_cast<uint&>(extent.Z) = reinterpret_cast<const uint&>(zero->Z);
        orientation = volume->m_pStairOrientation;
        reinterpret_cast<uint&>(end.X) = reinterpret_cast<const uint&>(orientation->Location.X);
        reinterpret_cast<uint&>(end.Y) = reinterpret_cast<const uint&>(orientation->Location.Y);
        reinterpret_cast<uint&>(end.Z) = reinterpret_cast<const uint&>(orientation->Location.Z);
        (*(LineCheck*)(*(byte**)primitive + 0x68))(primitive, &hit, volume, end, outside, extent, 0, 0);
        if ((*stairFlagByte & 2U) != 0) {
            scaledZ = (float10)travel.Z * (float10)100.0f;
            scaledY = (float)((float10)travel.Y * (float10)100.0f);
            scaledX = (float)((float10)travel.X * (float10)100.0f);
            pointZ = scaledZ + (float10)hit.Location.Z;
            pointY = (float10)hit.Location.Y + (float10)scaledY;
            pointX = (float10)scaledX + (float10)hit.Location.X;
            spawnPoint.X = (float)pointX;
            spawnPoint.Y = (float)pointY;
            spawnPoint.Z = (float)pointZ;
        } else {
            reinterpret_cast<uint&>(spawnPoint.Y) = reinterpret_cast<const uint&>(hit.Location.Y);
            reinterpret_cast<uint&>(spawnPoint.Z) = reinterpret_cast<const uint&>(hit.Location.Z);
            reinterpret_cast<uint&>(spawnPoint.X) = reinterpret_cast<const uint&>(hit.Location.X);
        }
        level = volume->XLevel;
        returnedRotation = &(rotationStorage = travel.Rotation());
        spawnRotation.Pitch = returnedRotation->Pitch;
        spawnRotation.Yaw = returnedRotation->Yaw;
        spawnRotation.Roll = returnedRotation->Roll;
        AActor* second = (*(Spawn*)(*(byte**)level + 0xa8))(level, markerClass, 0, spawnPoint, spawnRotation,
            nullptr, 0, 0, nullptr, nullptr);
        if (second != nullptr) {
            second->m_iPlanningFloor_0 = volume->m_iPlanningFloor_0;
            uint markerFlags = *reinterpret_cast<const uint*>(reinterpret_cast<byte*>(second) + 0x3e8);
            int floor1 = volume->m_iPlanningFloor_1;
            markerFlags &= ~1U;
            second->m_iPlanningFloor_1 = floor1;
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(second) + 0x3e8) = markerFlags;
        }
        bool createIcon = (*stairFlagByte & 1U) != 0;
        orientation = volume->m_pStairOrientation;
        if (createIcon) {
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(orientation) + 0xa0) &= ~2U; // bHidden.
            orientation = volume->m_pStairOrientation;
            orientation->m_iPlanningFloor_0 = volume->m_iPlanningFloor_0;
            orientation = volume->m_pStairOrientation;
            orientation->m_iPlanningFloor_1 = volume->m_iPlanningFloor_1;
            orientation = volume->m_pStairOrientation;
            int yaw = orientation->Rotation.Yaw;
            orientation->m_u8SpritePlanningAngle = (byte)((byte)(yaw / 255) + 64U);
        } else {
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(orientation) + 0xa0) |= 2U;
            orientation = volume->m_pStairOrientation;
            orientation->m_iPlanningFloor_0 = -1;
            orientation = volume->m_pStairOrientation;
            orientation->m_iPlanningFloor_1 = -1;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6StairVolume::AddMyMarker");
        throw;
    }
}

// R6Engine.dll @ 1003bbb0 : StairVolumeMarkerCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x88 through EBP-0x84.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeMarkerCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x88]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x84]
        push eax
        mov dword ptr [ebp-0x84],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003bbcd : StairVolumeMarkerCatchContext
// Reports AddMyMarker and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeMarkerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6StairVolumeAddMyMarker
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044f70 : StairVolumeMarkerExceptionHandler
// Supplies the exact marker FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumeMarkerExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumeMarkerFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003bbf0 : AR6StairVolume::CheckForErrors
// Reports missing, misplaced or multiply linked orientations, then assigns the volume to RGM_AllMode.
void __thiscall AR6StairVolume::CheckForErrors(void)
{
    AR6StairVolume* volume = this;
    using Format = FString* (__cdecl*)(FString*, const ushort*, ...); // Explicit native hidden-result pointer ABI.
    using DestroyString = void (__thiscall*)(FString*);
    using MapCheck = void (__thiscall*)(FFeedbackContext*, int, AActor*, const ushort*);
    struct PendingString {
        FString* storage;
        bool active;
        void Finish() {
            active = false; // Native resets to state0 before the normal destructor call.
            (*(DestroyString*)&FStringDestructorImport)(storage);
        }
        ~PendingString() noexcept(false) {
            if (active) (*(DestroyString*)&FStringDestructorImport)(storage);
        }
    }; // Reference-only ownership view; actual six cleanup entries and native state map remain explicit below.
    alignas(FString) byte commonStorage[12], firstStorage[12], currentStorage[12];
    FString* commonText = (FString*)commonStorage; // Native EBP-0x30, reused in four disjoint states.
    FString* firstText = (FString*)firstStorage; // Native EBP-0x3c.
    FString* currentText = (FString*)currentStorage; // Native EBP-0x48.
    try {
        volume->ABrush::CheckForErrors();
        AR6StairOrientation* orientation = volume->m_pStairOrientation;
        if (orientation == nullptr) {
            const ushort* name = volume->UObject::GetName();
            FString* returned = reinterpret_cast<Format&>(FStringPrintfImport)(commonText,
                (const ushort*)L"StairOrientation missing in the volume: %s ", name);
            PendingString cleanup{commonText, true}; // State1 protects original storage, not returned EAX.
            const ushort* message = returned->operator*();
            FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
            (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, volume, message);
            cleanup.Finish();
        } else {
            FVector location;
            reinterpret_cast<uint&>(location.X) = reinterpret_cast<const uint&>(orientation->Location.X);
            reinterpret_cast<uint&>(location.Y) = reinterpret_cast<const uint&>(orientation->Location.Y);
            reinterpret_cast<uint&>(location.Z) = reinterpret_cast<const uint&>(orientation->Location.Z);
            if (volume->AVolume::Encompasses(location) == 0) {
                const ushort* name = volume->UObject::GetName();
                // Cached across both misplaced-orientation messages.
                Format format = reinterpret_cast<Format&>(FStringPrintfImport);
                {
                    FString* returned = format(commonText,
                        (const ushort*)L"%s doesn't have a StairOrientation inside", name);
                    PendingString cleanup{commonText, true}; // State2.
                    const ushort* message = returned->operator*();
                    FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                    (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, volume, message);
                    cleanup.Finish();
                }
                const ushort* volumeName = volume->UObject::GetName();
                orientation = volume->m_pStairOrientation;
                const ushort* orientationName = orientation->UObject::GetName();
                FString* returned = format(commonText, (const ushort*)L"%s is not in %s ", orientationName, volumeName);
                PendingString cleanup{commonText, true}; // State3.
                const ushort* message = returned->operator*();
                orientation = volume->m_pStairOrientation; // Actor operand is read after string dereference.
                FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, orientation, message);
                cleanup.Finish();
            }
        }
        uint index = 0, linkedCount = 0;
        AR6StairOrientation* first = nullptr;
        for (;;) {
            ULevel* level = volume->XLevel;
            const NativeArrayHeader32* actorsHeader =
                reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(level) + 0x30);
            if ((int)index >= actorsHeader->count) break;
            AActor* actor = reinterpret_cast<AActor**>(actorsHeader->dataAddress)[index];
            if (actor != nullptr) {
                UClass* type = actor->Class;
                while (type != nullptr && type != &AR6StairOrientation::PrivateStaticClass)
                    type = type->GetSuperClass();
                if (type != nullptr && static_cast<AR6StairOrientation*>(actor)->m_pStairVolume == volume) {
                    ++linkedCount; // Native DWORD wrap and signed comparisons, with no count validation.
                    AR6StairOrientation* current = static_cast<AR6StairOrientation*>(actor);
                    if ((int)linkedCount <= 1) {
                        first = current;
                    } else {
                        if (linkedCount == 2) {
                            const ushort* volumeName = volume->UObject::GetName();
                            {
                                FString* returned = reinterpret_cast<Format&>(FStringPrintfImport)(commonText,
                                    (const ushort*)L"%s has more than one StairOrientation inside", volumeName);
                                PendingString cleanup{commonText, true}; // State4.
                                const ushort* message = returned->operator*();
                                FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                                (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, volume, message);
                                cleanup.Finish();
                            }
                            volumeName = volume->UObject::GetName();
                            const ushort* firstName = first->UObject::GetName();
                            FString* returned = reinterpret_cast<Format&>(FStringPrintfImport)(firstText,
                                (const ushort*)L"%s might not be the in %s ", firstName, volumeName);
                            PendingString cleanup{firstText, true}; // State5; preserve native wording.
                            const ushort* message = returned->operator*();
                            FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                            (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, first, message);
                            cleanup.Finish();
                        }
                        const ushort* volumeName = volume->UObject::GetName();
                        const ushort* currentName = current->UObject::GetName();
                        FString* returned = reinterpret_cast<Format&>(FStringPrintfImport)(currentText,
                            (const ushort*)L"%s might not be the in %s ", currentName, volumeName);
                        PendingString cleanup{currentText, true}; // State6; actor remains the captured current entry.
                        const ushort* message = returned->operator*();
                        FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                        (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 0, current, message);
                        cleanup.Finish();
                    }
                }
            }
            ++index; // Next iteration reloads level, count and data, including after every warning callback.
        }
        struct NativeStringArgument { uint word[3]; }; // Raw by-value FString ABI, without an extra copy constructor.
        alignas(FString) byte gameTypeStorage[12];
        ::new (reinterpret_cast<void*>(gameTypeStorage)) FString((const ushort*)L"RGM_AllMode");
        using SetGameType = void (__thiscall*)(AActor*, NativeStringArgument);
        reinterpret_cast<SetGameType&>(AActorSetGameTypeImport)(volume,
            *(NativeStringArgument*)gameTypeStorage);
        // SetGameType owns the completed by-value argument; no caller cleanup state or destructor is added.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6StairVolume::CheckForErrors");
        throw;
    }
}

// R6Engine.dll @ 1003beb8 : StairVolumeValidationCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x24 through EBP-0x20.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeValidationCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x20]
        push ecx
        mov dword ptr [ebp-0x20],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003becc : StairVolumeValidationCatchContext
// Reports CheckForErrors and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl StairVolumeValidationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6StairVolumeCheckForErrors
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043270 : StairVolumeDestructionState0Cleanup
// Destroys the saved physics-volume base at inherited dispatcher-frame EBP-0x10.
__declspec(naked) void __cdecl StairVolumeDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [APhysicsVolumeDestructorImport]
    }
}

// R6Engine.dll @ 10043279 : StairVolumeDestructionExceptionHandler
// Supplies the exact base-cleanup FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumeDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumeDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044f80 : StairVolumeValidationState1Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x30.
__declspec(naked) void __cdecl StairVolumeValidationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044f89 : StairVolumeValidationState2Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x30.
__declspec(naked) void __cdecl StairVolumeValidationState2Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044f92 : StairVolumeValidationState3Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x30.
__declspec(naked) void __cdecl StairVolumeValidationState3Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044f9b : StairVolumeValidationState4Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x30.
__declspec(naked) void __cdecl StairVolumeValidationState4Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x30]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044fa4 : StairVolumeValidationState5Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x3c.
__declspec(naked) void __cdecl StairVolumeValidationState5Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x3c]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044fad : StairVolumeValidationState6Cleanup
// Destroys original formatted-string storage at inherited dispatcher-frame EBP-0x48.
__declspec(naked) void __cdecl StairVolumeValidationState6Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x48]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10046930 : InitializeAR6StairVolumeClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6StairVolumeClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = APhysicsVolumePrivateStaticClassImport;
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
    packet.internalConstructor = &AR6StairVolume::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass;
    parentClass = captures.parentClass; // Both reloads precede placement of the returned configuration pointer.
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6StairVolume;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x48c;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6StairVolume::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6StairVolumeClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100480f0 : DestroyAR6StairVolumeClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6StairVolumeClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6StairVolume::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100469c0 : PublishAR6StairVolumeAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6StairVolumeAutoClass(void)
{
    autoclassAR6StairVolume = &AR6StairVolume::PrivateStaticClass;
}

// R6Engine.dll @ 10044fb6 : StairVolumeValidationExceptionHandler
// Supplies the exact validation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl StairVolumeValidationExceptionHandler(void)
{
    __asm {
        mov eax,offset stairVolumeValidationFuncInfo
        jmp __CxxFrameHandler
    }
}
