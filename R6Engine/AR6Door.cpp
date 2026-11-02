#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
FVector* __cdecl ScaleVectorToResult(FVector* result, float scale, const FVector* source);
UObject* __cdecl ConstructUReachSpec(UClass* requestedClass, UObject* outer, uint nameWord, ulong objectFlags);
__declspec(naked) void __cdecl DestroyAR6DoorClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004ae70 : AR6DoorVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Door::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6DoorVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050d0c : nativeTextAR6DoorAddReachSpecs
extern const ushort nativeTextAR6DoorAddReachSpecs[23];

// R6Engine.dll data @ 1005093c : nativeTextAR6DoorCheckForErrors
extern const ushort nativeTextAR6DoorCheckForErrors[24];

// R6Engine.dll data @ 10050b18 : nativeTextAR6DoorPrunePaths
extern const ushort nativeTextAR6DoorPrunePaths[20];

// R6Engine.dll data @ 10050b90 : nativeTextAR6DoorRenderEditorInfo
extern const ushort nativeTextAR6DoorRenderEditorInfo[26];

// R6Engine.dll data @ 1005575a : nativeTextR6Door
extern const ushort nativeTextR6Door[7];

extern const NativeUnwindEntry doorRenderUnwindMap[3];
extern const NativeTryBlock doorRenderTryMap[1];
extern const NativeCatchEntry doorRenderCatchMap[2];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl DoorAddReachCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorAddReachCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorPruneCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorPruneCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorRenderCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorRenderCatchPointer(void);
__declspec(naked) void __cdecl DoorRenderState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorValidationCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl DoorValidationCatchPointer(void);
__declspec(naked) void __cdecl DoorValidationState1Cleanup(void);

// R6Engine.dll data @ 1005a5ec : doorRenderFuncInfo
// Binds the renderer guard states, completed-batcher cleanup and two exception catches.
const NativeFunctionInfoPrefix doorRenderFuncInfo = { 0x19930520, 0x3, ((uint)&doorRenderUnwindMap), 0x1,
    ((uint)&doorRenderTryMap), 0 };

// R6Engine.dll data @ 1005a5d8 : doorRenderTryMap
// Binds the renderer guard states, completed-batcher cleanup and two exception catches.
const NativeTryBlock doorRenderTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&doorRenderCatchMap) }
};

// R6Engine.dll data @ 1005a5b8 : doorRenderCatchMap
// Binds the renderer guard states, completed-batcher cleanup and two exception catches.
const NativeCatchEntry doorRenderCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -172, ((uint)&DoorRenderCatchPointer) },
    { 0, 0, 0, ((uint)&DoorRenderCatchContext) }
};

// R6Engine.dll data @ 1005a5a0 : doorRenderUnwindMap
// Binds the renderer guard states, completed-batcher cleanup and two exception catches.
const NativeUnwindEntry doorRenderUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&DoorRenderState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a4d8 : doorPruneUnwindMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry doorPruneUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a4e8 : doorPruneCatchMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry doorPruneCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DoorPruneCatchPointer) },
    { 0, 0, 0, ((uint)&DoorPruneCatchContext) }
};

// R6Engine.dll data @ 1005a508 : doorPruneTryMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock doorPruneTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&doorPruneCatchMap) }
};

// R6Engine.dll data @ 1005a51c : doorPruneFuncInfo
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix doorPruneFuncInfo = { 0x19930520, 0x2, ((uint)&doorPruneUnwindMap), 0x1,
    ((uint)&doorPruneTryMap), 0 };

// R6Engine.dll data @ 1005a6c8 : doorAddReachUnwindMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry doorAddReachUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a6d8 : doorAddReachCatchMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry doorAddReachCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DoorAddReachCatchPointer) },
    { 0, 0, 0, ((uint)&DoorAddReachCatchContext) }
};

// R6Engine.dll data @ 1005a6f8 : doorAddReachTryMap
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock doorAddReachTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&doorAddReachCatchMap) }
};

// R6Engine.dll data @ 1005a70c : doorAddReachFuncInfo
// Retains the path parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix doorAddReachFuncInfo = { 0x19930520, 0x2, ((uint)&doorAddReachUnwindMap), 0x1,
    ((uint)&doorAddReachTryMap), 0 };

// R6Engine.dll data @ 1005a2f0 : doorValidationUnwindMap
// Retains the completed-warning cleanup and exact validation typed/context catch bindings.
const NativeUnwindEntry doorValidationUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&DoorValidationState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a308 : doorValidationCatchMap
// Retains the completed-warning cleanup and exact validation typed/context catch bindings.
const NativeCatchEntry doorValidationCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&DoorValidationCatchPointer) },
    { 0, 0, 0, ((uint)&DoorValidationCatchContext) }
};

// R6Engine.dll data @ 1005a328 : doorValidationTryMap
// Retains the completed-warning cleanup and exact validation typed/context catch bindings.
const NativeTryBlock doorValidationTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&doorValidationCatchMap) }
};

// R6Engine.dll data @ 1005a33c : doorValidationFuncInfo
// Retains the completed-warning cleanup and exact validation typed/context catch bindings.
const NativeFunctionInfoPrefix doorValidationFuncInfo = { 0x19930520, 0x3, ((uint)&doorValidationUnwindMap), 0x1,
    ((uint)&doorValidationTryMap), 0 };

// R6Engine.dll data @ 1007a1ac : autoclassAR6Door
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Door = nullptr;

// R6Engine.dll @ 10007400 : AR6Door::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Door::StaticClass(void)
{
    return &AR6Door::PrivateStaticClass; // Selected object at0x1007f398.
}

// R6Engine.dll @ 10007410 : AR6Door::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6Door::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6Door::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10007440 : AR6Door::~AR6Door
// Runs conditional object cleanup, with implicit NavigationPoint destruction on normal or exceptional exit.
AR6Door::~AR6Door()
{
    // Compiler installs vtable1004ae70 first; shared FuncInfo10056d8c protects the base through state0.
    UObject::ConditionalDestroy();
    // Normal base call uses current IAT10049450 at state-1; shared cleanup10043230 uses saved EBP-0x10.
}

// R6Engine.dll @ 100074a0 : AR6Door::AR6Door()
// Constructs NavigationPoint and installs the door vtable without initializing the derived fields or padding.
AR6Door::AR6Door() : ANavigationPoint()
{
    // Publishes AR6DoorVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 100074c0 : AR6Door::AR6Door(const AR6Door&)
// Copies base, room byte, one close-on-untouch bit, door links and raw look-vector words in native order.
AR6Door::AR6Door(const AR6Door& sourceObject) : ANavigationPoint(sourceObject)
{
    // Publishes AR6DoorVirtualTable after base construction; native EAX retains original storage.
    AR6Door* door = this;
    const AR6Door* source = &sourceObject;
    door->m_eRoomLayout = source->m_eRoomLayout; // Native byte store retains the three neighboring padding bytes.
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3ec);
    uint destinationFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(door) + 0x3ec);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(door) + 0x3ec) =
        destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    door->m_CorrespondingDoor = source->m_CorrespondingDoor;
    door->m_RotatingDoor = source->m_RotatingDoor;
    reinterpret_cast<uint&>(door->m_vLookDir.X) = reinterpret_cast<const uint&>(source->m_vLookDir.X);
    reinterpret_cast<uint&>(door->m_vLookDir.Y) = reinterpret_cast<const uint&>(source->m_vLookDir.Y);
    reinterpret_cast<uint&>(door->m_vLookDir.Z) = reinterpret_cast<const uint&>(source->m_vLookDir.Z);
}

// R6Engine.dll @ 10007540 : AR6Door::operator=
// Assigns the base and selected door fields, retaining its vtable, padding and unrelated flag bits.
AR6Door& __thiscall AR6Door::operator=(const AR6Door& sourceObject)
{
    AR6Door* door = this;
    const AR6Door* source = &sourceObject;
    door->ANavigationPoint::operator=(*source);
    door->m_eRoomLayout = source->m_eRoomLayout; // Native byte store retains the three neighboring padding bytes.
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x3ec);
    uint destinationFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(door) + 0x3ec);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(door) + 0x3ec) =
        destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    door->m_CorrespondingDoor = source->m_CorrespondingDoor;
    door->m_RotatingDoor = source->m_RotatingDoor;
    reinterpret_cast<uint&>(door->m_vLookDir.X) = reinterpret_cast<const uint&>(source->m_vLookDir.X);
    reinterpret_cast<uint&>(door->m_vLookDir.Y) = reinterpret_cast<const uint&>(source->m_vLookDir.Y);
    reinterpret_cast<uint&>(door->m_vLookDir.Z) = reinterpret_cast<const uint&>(source->m_vLookDir.Z);
    return *door;
}

// R6Engine.dll @ 100075b0 : AR6Door::DeletingDestructor
// Destroys one marker or a cookie-counted array, optionally frees storage and returns the original address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6Door::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6Door* door = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(door) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DoorDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(door) - 4;
        _eh_vector_destructor_iterator_(door, 0x404, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current GMalloc is fetched after element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    door->AR6Door::~AR6Door(); // Direct native10007440 call, without virtual dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(door, 0x404);
    }
    return door;
}

// R6Engine.dll @ 1000dc80 : AR6Door::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Door::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DoorConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001cfb0 : AR6Door::AssociatedLevelGeometry
// Returns null without accessing the receiver; this is a genuine native leaf stub.
AActor* __thiscall AR6Door::AssociatedLevelGeometry(void)
{
    return nullptr;
}

// R6Engine.dll @ 1001cfc0 : AR6Door::CheckForErrors
// Validates non-window rotating-door paths, reports an empty path list and applies the all-mode prefix.
void __thiscall AR6Door::CheckForErrors(void)
{
    AR6Door* door = this;
    using Format = FString* (__cdecl*)(FString*, const ushort*, ...);
    using DestroyString = void (__thiscall*)(FString*);
    struct PendingString {
        FString* storage;
        bool active;
        // Leaves the cleanup state before entering normal string destruction.
        void Finish() {
            active = false;
            (*(DestroyString*)&FStringDestructorImport)(storage);
        }
        // Releases a completed warning string on exceptional exit.
        ~PendingString() noexcept(false) {
            if (active) (*(DestroyString*)&FStringDestructorImport)(storage);
        }
    }; // Reference-only lifetime view; native EBP-0x28 cleanup and exact state map remain separate.
    try {
        door->AActor::CheckForErrors();
        AR6IORotatingDoor* rotating = door->m_RotatingDoor;
        if (rotating != nullptr && (reinterpret_cast<const byte*>(rotating)[0x488] & 1U) == 0) {
            // PathList.Num; negative counts do not warn.
            if (reinterpret_cast<const NativeArrayHeader32&>(door->PathList).count == 0) {
                const ushort* name = door->UObject::GetName();
                alignas(FString) byte warningStorage[12];
                FString* warning = (FString*)warningStorage;
                FString* returned = reinterpret_cast<Format&>(FStringPrintfImport)(warning,
                    (const ushort*)L"No paths from %s", name);
                PendingString cleanup{warning, true}; // State1 owns original storage, not the formatter's EAX.
                const ushort* text = returned->operator*();
                FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
                using MapCheck = void (__thiscall*)(FFeedbackContext*, int, AActor*, const ushort*);
                (*(MapCheck*)(*(byte**)feedback + 0x28))(feedback, 1, door, text);
                cleanup.Finish();
            }
            struct NativeStringArgument { uint word[3]; };
            alignas(FString) byte gameTypeStorage[12];
            ::new (reinterpret_cast<void*>(gameTypeStorage)) FString((const ushort*)L"RGM_AllMode ");
            using SetGameType = void (__thiscall*)(AActor*, NativeStringArgument);
            reinterpret_cast<SetGameType&>(AActorSetGameTypeImport)(door,
                *(NativeStringArgument*)gameTypeStorage);
            // Native trailing space is retained; SetGameType owns the completed by-value argument.
        } // The original eligibility decision is not rechecked after diagnostics.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Door::CheckForErrors");
        throw;
    }
}

// R6Engine.dll @ 1001d082 : DoorValidationCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl DoorValidationCatchPointer(void)
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

// R6Engine.dll @ 1001d096 : DoorValidationCatchContext
// Reports CheckForErrors and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DoorValidationCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DoorCheckForErrors
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d440 : AR6Door::PrunePaths
// Marks redundant non-corresponding-door paths through alternate routes, cleans pruned paths and returns the count.
int __thiscall AR6Door::PrunePaths(void)
{
    AR6Door* door = this;
    uint prunedCount = 0;
    try {
        for (uint outer = 0; (int)outer < reinterpret_cast<const NativeArrayHeader32&>(door->PathList).count; ++outer) {
            for (uint inner = 0;
                (int)inner < reinterpret_cast<const NativeArrayHeader32&>(door->PathList).count; ++inner) {
                UReachSpec** data = reinterpret_cast<UReachSpec**>(
                    reinterpret_cast<NativeArrayHeader32&>(door->PathList).dataAddress);
                UReachSpec* path = data[outer];
                if (path->End == door->m_CorrespondingDoor || outer == inner) continue;
                UReachSpec* alternative = data[inner]; // Same captured data pointer as the initial outer lookup.
                if (alternative->bPruned != 0) continue;
                data = reinterpret_cast<UReachSpec**>(
                    reinterpret_cast<NativeArrayHeader32&>(door->PathList).dataAddress);
                path = data[outer];
                alternative = data[inner];
                if (alternative->UReachSpec::operator<=(*path) == 0) continue;
                // Reload after comparison callback.
                data = reinterpret_cast<UReachSpec**>(
                    reinterpret_cast<NativeArrayHeader32&>(door->PathList).dataAddress);
                alternative = data[inner];
                int distance = alternative->Distance;
                path = data[outer];
                ANavigationPoint* end = alternative->End;
                if (end->ANavigationPoint::FindAlternatePath(path, distance) == 0) continue;
                // Mark current storage after the alternate-path callback.
                data = reinterpret_cast<UReachSpec**>(
                    reinterpret_cast<NativeArrayHeader32&>(door->PathList).dataAddress);
                UReachSpec* marked = data[outer];
                ++prunedCount;
                marked->bPruned = 1;
                inner = static_cast<uint>(reinterpret_cast<const NativeArrayHeader32&>(door->PathList).count);
                // Native still increments inner before its signed comparison; no unconditional break is substituted.
            }
        }
        door->ANavigationPoint::CleanUpPruned();
        return (int)prunedCount; // Cleanup return value is ignored; earlier byte stores survive failures.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Door::PrunePaths");
        throw;
    }
}

// R6Engine.dll @ 1001d51e : DoorPruneCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DoorPruneCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x18]
        push ecx
        mov dword ptr [ebp-0x18],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d532 : DoorPruneCatchContext
// Reports PrunePaths and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DoorPruneCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DoorPrunePaths
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001d880 : AR6Door::RenderEditorInfo
// Draws the selected door's opening limit, approach positions and room-layout direction arrows.
void __thiscall AR6Door::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* unusedInterface,
    FDynamicActor* unusedActor)
{
    AR6Door* door = this;
    // Samples selection before protected state0.
    bool selected = (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(door) + 0xac) & 0x4000U) != 0;
    using SetTransform = void (__thiscall*)(FRenderInterface*, int, FMatrix); // Inferred role of native slot+0x34.
    using Destroy = void (__thiscall*)(FLineBatcher*);
    using Line = void (__thiscall*)(FLineBatcher*, FVector, FVector, uint);
    using Sphere = void (__thiscall*)(FLineBatcher*, FVector, uint, float, int);
    using Arrow = void (__thiscall*)(FLineBatcher*, FVector, FRotator, uint, float);
    struct PendingBatcher {
        FLineBatcher* batcher;
        bool active;
        // Drops the native cleanup state before normal destruction.
        void Finish() {
            active = false;
            (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
        // Destroys only storage whose delayed native cleanup state was entered.
        ~PendingBatcher() noexcept(false) {
            if (active) (*(Destroy*)&FLineBatcherDestructorImport)(batcher);
        }
    }; // Inferred ownership view; exact native frame/cleanup/catches remain represented separately.
    try {
        if (!selected) return;
        AR6IORotatingDoor* rotating = door->m_RotatingDoor;
        if ((reinterpret_cast<byte*>(rotating)[0x488] & 1) != 0) return; // m_bTreatDoorAsWindow; no null check.
        byte* owner = *(byte**)((byte*)scene + 4);
        FRenderInterface* render = *(FRenderInterface**)(owner + 0x164);
        const uint* identityWords = *(const uint**)&FMatrixIdentityImport;
        // Table captured before the sixteen-word by-value matrix copy.
        byte* renderTable = *reinterpret_cast<byte**>(render);
        alignas(FMatrix) uint identityCopy[16]; // Raw outgoing-copy view; no extra local FMatrix destructor.
        for (uint i = 0; i != 16; ++i) identityCopy[i] = identityWords[i];
        (*reinterpret_cast<SetTransform*>(renderTable + 0x34))(render, 0, *(const FMatrix*)identityCopy);
        owner = *(byte**)((byte*)scene + 4);
        render = *(FRenderInterface**)(owner + 0x164);
        alignas(FLineBatcher) byte batcherStorage[0x24]; // Native EBP-0x74.
        FLineBatcher* batcher = (FLineBatcher*)batcherStorage;
        ::new (reinterpret_cast<void*>(batcher)) FLineBatcher(render, 1, 0); // Constructor EAX ignored.
        rotating = door->m_RotatingDoor;
        uint limitYaw = static_cast<uint>(rotating->Rotation.Yaw);
        int limitRoll = rotating->Rotation.Roll;
        AR6IORotatingDoor* openingDoor = door->m_RotatingDoor;
        int limitPitch = rotating->Rotation.Pitch;
        limitYaw -= 0x8000U;
        // Preserve the wrapping opening-angle product.
        int openingProduct = (int)(static_cast<uint>(openingDoor->m_iMaxOpeningDeg) * 0xffffU);
        int openingAngle = openingProduct / 360; // Native signed magic division truncates toward zero.
        bool clockwise = (reinterpret_cast<byte*>(openingDoor)[0x488] & 0x40) != 0;
        PendingBatcher cleanup{batcher, true}; // State1 is delayed until after these field reads and the flag test.
        limitYaw = clockwise ? limitYaw + (uint)openingAngle : limitYaw - (uint)openingAngle;
        FRotator limit = {limitPitch, (int)limitYaw, limitRoll};
        FVector limitStorage;
        FVector* direction = &(limitStorage = limit.Vector());
        // These local arithmetic/copy views describe inlined work; they are not additional native functions.
        // Offsets round X before addition; roundY distinguishes the direct draws from pre-call sphere bases.
        auto offsetPoint = [](const FVector* axis, float distance, const FVector* origin,
            bool subtract, bool roundY) -> FVector {
            float10 z = (float10)axis->Z * distance;
            float10 y = (float10)axis->Y * distance;
            if (roundY) y = (float)y;
            float x = (float)((float10)axis->X * distance);
            float10 endZ = subtract ? (float10)origin->Z - z : z + origin->Z;
            float10 endY = subtract ? (float10)origin->Y - y : y + origin->Y;
            float10 endX = subtract ? (float10)origin->X - x : (float10)x + origin->X;
            return {(float)endX, (float)endY, (float)endZ};
        };
        // Retains the raw/interleaved vector copies used for returned directions and outgoing locations.
        auto copyVector = [](FVector* output, const FVector* input) {
            reinterpret_cast<uint*>(output)[0] = reinterpret_cast<const uint*>(input)[0];
            reinterpret_cast<uint*>(output)[1] = reinterpret_cast<const uint*>(input)[1];
            reinterpret_cast<uint*>(output)[2] = reinterpret_cast<const uint*>(input)[2];
        };
        // Captures a fresh door rotation with wrapping yaw arithmetic; native reads Yaw/Roll before Pitch.
        auto shiftedRotation = [door](uint yawOffset) -> FRotator {
            uint yaw = static_cast<uint>(door->Rotation.Yaw);
            int roll = door->Rotation.Roll;
            int pitch = door->Rotation.Pitch;
            return {pitch, (int)(yaw + yawOffset), roll};
        };
        FRotator* rotation = &door->Rotation;
        FVector* location = &door->Location;
        rotating = door->m_RotatingDoor;
        FVector* rotatingLocation = &rotating->Location;
        FVector end = offsetPoint(direction, 128.0f, rotatingLocation, false, true), start;
        copyVector(&start, rotatingLocation);
        reinterpret_cast<Line&>(FLineBatcherDrawLineImport)(batcher, start, end, 0xff0000ff);
        FRotator across = shiftedRotation(0x4000);
        FVector sideDirection;
        // Returned EAX is ignored for this one direction.
        sideDirection = across.Vector();
        FVector queryPoint;
        copyVector(&queryPoint, location);
        rotating = door->m_RotatingDoor;
        int opensTowardPoint = rotating->AR6IORotatingDoor::DoorOpenTowards(queryPoint);
        // Draws a sphere at a fresh location-relative side offset; Z stays extended through addition/subtraction.
        auto sideSphere = [&](float distance, bool subtract) {
            FVector center = offsetPoint(&sideDirection, distance, location, subtract, true);
            reinterpret_cast<Sphere&>(FLineBatcherDrawSphereImport)(batcher, center, 0xff0000ff, 38.0f, 16);
        };
        // Most second/fourth spheres capture their side base before the Vector and shared scaling calls.
        auto insetSphere = [&](float distance, bool subtract) {
            FVector base = offsetPoint(&sideDirection, distance, location, subtract, false);
            FVector forwardStorage, scaledStorage;
            FVector* forward = &(forwardStorage = rotation->Vector());
            FVector* scaled = ScaleVectorToResult(&scaledStorage, 100.0f, forward);
            float10 z = (float10)base.Z - scaled->Z;
            float10 y = (float10)base.Y - scaled->Y;
            float10 x = (float10)base.X - scaled->X;
            FVector center = {(float)x, (float)y, (float)z};
            reinterpret_cast<Sphere&>(FLineBatcherDrawSphereImport)(batcher, center, 0xff0000ff, 38.0f, 16);
        };
        // The nonclockwise/toward branch instead calls Vector first and leaves its scaled Z unspilled.
        auto insetSphereAfterDirection = [&](float distance) {
            FVector forwardStorage;
            FVector* forward = &(forwardStorage = rotation->Vector());
            float10 z = (float10)forward->Z * 100.0f;
            float y = (float)((float10)forward->Y * 100.0f);
            float x = (float)((float10)forward->X * 100.0f);
            FVector base = offsetPoint(&sideDirection, distance, location, true, false);
            float10 centerZ = (float10)base.Z - z;
            float10 centerY = (float10)base.Y - y;
            float10 centerX = (float10)base.X - x;
            FVector center = {(float)centerX, (float)centerY, (float)centerZ};
            reinterpret_cast<Sphere&>(FLineBatcherDrawSphereImport)(batcher, center, 0xff0000ff, 38.0f, 16);
        };
        if (opensTowardPoint == 0) {
            AR6Door* corresponding = door->m_CorrespondingDoor;
            byte layout = corresponding->m_eRoomLayout;
            if (layout == 0) {
                rotating = door->m_RotatingDoor;
                bool subtract = (reinterpret_cast<byte*>(rotating)[0x488] & 0x40) == 0;
                sideSphere(108.0f, subtract);
                sideSphere(200.0f, !subtract);
                sideSphere(200.0f, subtract);
                insetSphere(200.0f, subtract);
            } else if (layout == 1) {
                sideSphere(115.0f, false);
                insetSphere(108.0f, false);
                sideSphere(200.0f, false);
                insetSphere(200.0f, false);
            } else if (layout == 2) {
                sideSphere(115.0f, true);
                insetSphere(108.0f, true);
                sideSphere(200.0f, true);
                insetSphere(200.0f, true);
            }
        } else {
            rotating = door->m_RotatingDoor;
            if ((reinterpret_cast<byte*>(rotating)[0x488] & 0x40) != 0) {
                AR6Door* corresponding = door->m_CorrespondingDoor;
                if (corresponding->m_eRoomLayout <= 1) {
                    sideSphere(115.0f, false);
                    insetSphere(108.0f, false);
                    sideSphere(200.0f, false);
                    insetSphere(200.0f, false);
                }
            } else {
                AR6Door* corresponding = door->m_CorrespondingDoor;
                byte correspondingLayout = corresponding->m_eRoomLayout;
                if (correspondingLayout == 0 || correspondingLayout == 2) {
                    sideSphere(115.0f, true);
                    insetSphereAfterDirection(108.0f);
                    sideSphere(200.0f, true);
                    insetSphereAfterDirection(200.0f);
                }
            }
        }
        // These lookups are repeated after every draw; the corresponding door can change during callbacks.
        auto correspondingLocation = [door]() -> FVector* {
            return &door->m_CorrespondingDoor->Location;
        };
        // A line keeps a raw start snapshot and rounded endpoint, both based on the same corresponding-door pointer.
        auto directionLine = [&](const FVector* axis, float distance) {
            FVector* origin = correspondingLocation();
            FVector endpoint = offsetPoint(axis, distance, origin, false, true), begin;
            copyVector(&begin, origin);
            reinterpret_cast<Line&>(FLineBatcherDrawLineImport)(batcher, begin, endpoint, 0xff0000ff);
        };
        // An arrow reloads the corresponding location separately from the preceding line.
        auto directionArrow = [&](const FVector* axis, float distance, FRotator arrowRotation) {
            FVector endpoint = offsetPoint(axis, distance, correspondingLocation(), false, true);
            reinterpret_cast<Arrow&>(FLineBatcherDrawDirectionalArrowImport)(batcher, endpoint, arrowRotation,
                0xff0000ff,
                1.0f);
        };
        byte layout = door->m_eRoomLayout; // Own room layout is sampled after all sphere callbacks.
        FVector directionStorage;
        FRotator arrowRotation;
        if (layout == 0) {
            arrowRotation = shiftedRotation(0xffffe000U);
            direction = &(directionStorage = arrowRotation.Vector());
            copyVector(&sideDirection, direction);
            directionLine(&sideDirection, 160.0f);
            directionArrow(&sideDirection, 160.0f, arrowRotation);
            direction = &(directionStorage = rotation->Vector());
            directionLine(direction, 200.0f);
            direction = &(directionStorage = rotation->Vector());
            directionArrow(direction, 200.0f, *rotation);
            arrowRotation = shiftedRotation(0x2000);
            direction = &(directionStorage = arrowRotation.Vector());
            copyVector(&sideDirection, direction);
            directionLine(&sideDirection, 160.0f);
            directionArrow(&sideDirection, 160.0f, arrowRotation);
        } else if (layout == 1 || layout == 2) {
            direction = &(directionStorage = rotation->Vector());
            directionLine(direction, 200.0f);
            direction = &(directionStorage = rotation->Vector());
            directionArrow(direction, 200.0f, *rotation);
            arrowRotation = shiftedRotation(layout == 1 ? 0xffffeaabU : 0x1555U);
            direction = &(directionStorage = arrowRotation.Vector());
            copyVector(&sideDirection, direction);
            directionLine(&sideDirection, 160.0f);
            directionArrow(&sideDirection, 160.0f, arrowRotation);
            arrowRotation = shiftedRotation(layout == 1 ? 0xffffd556U : 0x2aaaU);
            direction = &(directionStorage = arrowRotation.Vector());
            copyVector(&sideDirection, direction);
            directionLine(&sideDirection, 140.0f);
            if (layout == 2) arrowRotation = shiftedRotation(0x2aaa); // This branch refreshes rotation after the line.
            directionArrow(&sideDirection, 140.0f, arrowRotation);
        } else {
            direction = &(directionStorage = rotation->Vector());
            directionLine(direction, 60.0f);
            direction = &(directionStorage = rotation->Vector());
            directionArrow(direction, 60.0f, *rotation);
        }
        cleanup.Finish();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Door::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001f2f5 : DoorRenderCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0xac through EBP-0x78.
__declspec(naked) __declspec(noreturn) void __cdecl DoorRenderCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0xac]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x78]
        push ecx
        mov dword ptr [ebp-0x78],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001f30c : DoorRenderCatchContext
// Reports the renderer context and rethrows through the current Core and C++ exception imports.
__declspec(naked) __declspec(noreturn) void __cdecl DoorRenderCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DoorRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020800 : AR6Door::addReachSpecs
// Adds a direct reach spec for an eligible corresponding door, then forwards to the base reach-spec builder.
void __thiscall AR6Door::addReachSpecs(APawn* pawn, int forwardedOption)
{
    AR6Door* door = this;
    AR6IORotatingDoor* rotating = door->m_RotatingDoor;
    bool hasRotatingDoor = rotating != nullptr; // Native pointer read/null test is state-1.
    try {
        if (!hasRotatingDoor ||
            (*reinterpret_cast<const byte*>(reinterpret_cast<const byte*>(rotating) + 0x488) & 1U) != 0) return;
        if (door->m_CorrespondingDoor != nullptr) {
            ULevel* level = door->XLevel;
            UObject* outer = level->Outer; // UObject.Outer, read before the class import.
            UClass* reachClass = UReachSpecPrivateStaticClassImport;
            UReachSpec* spec = reinterpret_cast<UReachSpec*>(ConstructUReachSpec(reachClass, outer, 0, 4));
            // Unchecked constructor result; no parent cleanup owns the new UObject.
            spec->UReachSpec::Init();
            spec->CollisionRadius = 40;
            spec->CollisionHeight = 85;
            spec->reachFlags = 0x11;
            spec->Start = door;
            spec->End = door->m_CorrespondingDoor;
            float10 z = (float10)door->Location.Z;
            AR6Door* corresponding = door->m_CorrespondingDoor; // Fresh link after Start/End stores and own-Z load.
            z -= (float10)corresponding->Location.Z;
            float10 y = (float10)door->Location.Y - (float10)corresponding->Location.Y;
            float10 x = (float10)door->Location.X - (float10)corresponding->Location.X;
            FVector delta;
            delta.X = (float)x;
            delta.Y = (float)y;
            delta.Z = (float)z;
            float discardedDistance;
            uint distanceLow;
            // Retain the live x87 return: FST32 does not pop or replace it before the canonical converter.
            __asm {
                lea ecx,delta
                call dword ptr [FVectorSizeImport]
                fst discardedDistance
                call TruncateX87ToSigned64
                mov distanceLow,eax
            }
            FArray* paths = reinterpret_cast<FArray*>(&door->PathList);
            // Low word of native EDX:EAX; no host float-to-int replacement.
            reinterpret_cast<uint&>(spec->Distance) = distanceLow;
            int index = paths->FArray::Add(1, 4);
            // Add may replace the path storage.
            UReachSpec** data =
                reinterpret_cast<UReachSpec**>(reinterpret_cast<NativeArrayHeader32*>(paths)->dataAddress);
            // Native unchecked DWORD addressing.
            *reinterpret_cast<UReachSpec**>(reinterpret_cast<byte*>(data) + (uint)index * 4U) = spec;
        }
        door->ANavigationPoint::addReachSpecs(pawn, forwardedOption);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Door::addReachSpecs");
        throw;
    }
}

// R6Engine.dll @ 10020923 : DoorAddReachCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl DoorAddReachCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x1c]
        push offset unsignedShortPointerThrowInfo
        lea eax,[ebp-0x18]
        push eax
        mov dword ptr [ebp-0x18],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10020937 : DoorAddReachCatchContext
// Reports addReachSpecs and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl DoorAddReachCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DoorAddReachSpecs
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044300 : DoorValidationState1Cleanup
// Destroys original warning-string storage at inherited dispatcher-frame EBP-0x28 through the current import.
__declspec(naked) void __cdecl DoorValidationState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x28]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 10044390 : DoorRenderState1Cleanup
// Tail-enters current FLineBatcher destruction on the completed renderer temporary at inherited EBP-0x74.
__declspec(naked) void __cdecl DoorRenderState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x74]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 10044399 : DoorRenderExceptionHandler
// Supplies the renderer FuncInfo without changing the native parent/dispatcher frame.
__declspec(naked) void __cdecl DoorRenderExceptionHandler(void)
{
    __asm {
        mov eax,offset doorRenderFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100462a0 : InitializeAR6DoorClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DoorClassMetadata(void)
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
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6Door::PrivateStaticClass, 0, 0x404, 0, parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6Door, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6Door::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DoorClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048040 : DestroyAR6DoorClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DoorClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Door::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046330 : PublishAR6DoorAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DoorAutoClass(void)
{
    autoclassAR6Door = &AR6Door::PrivateStaticClass;
}

// R6Engine.dll @ 10044309 : DoorValidationExceptionHandler
// Supplies the exact validation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DoorValidationExceptionHandler(void)
{
    __asm {
        mov eax,offset doorValidationFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044360 : DoorPruneExceptionHandler
// Supplies the exact path-method FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DoorPruneExceptionHandler(void)
{
    __asm {
        mov eax,offset doorPruneFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100443d0 : DoorAddReachExceptionHandler
// Supplies the exact path-method FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl DoorAddReachExceptionHandler(void)
{
    __asm {
        mov eax,offset doorAddReachFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001d3d0 : ConstructUReachSpec
// Validates ReachSpec ancestry, resolves the transient outer sentinel and forwards object construction parameters.
UObject* __cdecl ConstructUReachSpec(UClass* requestedClass, UObject* outer, uint nameWord, ulong objectFlags)
{
    UClass* type = requestedClass;
    if (type != nullptr) {
        // Captured once before walking SuperField+0x2c.
        UClass* reachClass = UReachSpecPrivateStaticClassImport;
        while (type != reachClass) {
            type = *reinterpret_cast<UClass**>(reinterpret_cast<byte*>(type) + 0x2c);
            if (type == nullptr) break;
        }
    }
    if (type == nullptr) {
        appFailAssert("Class->IsChildOf(T::StaticClass())", "d:\\ravenshield\\412\\core\\inc\\UnObjBas.h", 0x476);
    } // Native continues if the assertion reporter returns, preserving original requestedClass.
    if (outer == reinterpret_cast<UObject*>(0xffffffffU)) {
        outer = UObject::GetTransientPackage();
    }
    FOutputDeviceError* error = *reinterpret_cast<FOutputDeviceError**>(CoreGErrorImport);
    const FName& objectName = reinterpret_cast<const FName&>(nameWord);
    return UObject::StaticConstructObject(requestedClass, outer, objectName,
        objectFlags, nullptr, error, 0); // Native FName is one raw word; exactly seven cdecl arguments.
}
