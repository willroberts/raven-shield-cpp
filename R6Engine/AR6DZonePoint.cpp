#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004ff48 : nativeTextAR6DZonePointFindSpawningPoint
extern const ushort nativeTextAR6DZonePointFindSpawningPoint[33];

// R6Engine.dll data @ 1004ff00 : nativeTextAR6DZonePointRenderEditorInfo
extern const ushort nativeTextAR6DZonePointRenderEditorInfo[32];

// R6Engine.dll data @ 1004fecc : nativeTextAR6DZonePointSpawned
extern const ushort nativeTextAR6DZonePointSpawned[23];

// R6Engine.dll data @ 10055802 : nativeTextR6DZonePoint
extern const ushort nativeTextR6DZonePoint[13];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawnedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawnedCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawningPointCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawningPointCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PointZoneRenderingCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PointZoneRenderingCatchPointer(void);
__declspec(naked) void __cdecl PointZoneRenderingState1Cleanup(void);

// R6Engine.dll data @ 10059918 : pointZoneRenderingUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pointZoneRenderingUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&PointZoneRenderingState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10059930 : pointZoneRenderingCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pointZoneRenderingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PointZoneRenderingCatchPointer) },
    { 0, 0, 0, ((uint)&PointZoneRenderingCatchContext) }
};

// R6Engine.dll data @ 10059950 : pointZoneRenderingTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pointZoneRenderingTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&pointZoneRenderingCatchMap) }
};

// R6Engine.dll data @ 10059964 : pointZoneRenderingFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZonePoint::RenderEditorInfo.
const NativeFunctionInfoPrefix pointZoneRenderingFuncInfo = { 0x19930520, 0x3, ((uint)&pointZoneRenderingUnwindMap),
    0x1, ((uint)&pointZoneRenderingTryMap), 0 };

// R6Engine.dll data @ 100598b8 : pointSpawnedUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pointSpawnedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100598c8 : pointSpawnedCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pointSpawnedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PointSpawnedCatchPointer) },
    { 0, 0, 0, ((uint)&PointSpawnedCatchContext) }
};

// R6Engine.dll data @ 100598e8 : pointSpawnedTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pointSpawnedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pointSpawnedCatchMap) }
};

// R6Engine.dll data @ 100598fc : pointSpawnedFuncInfo
// Binds the selected MSVC cleanup/catch maps for Spawned.
const NativeFunctionInfoPrefix pointSpawnedFuncInfo = { 0x19930520, 0x2, ((uint)&pointSpawnedUnwindMap), 0x1,
    ((uint)&pointSpawnedTryMap), 0 };

// R6Engine.dll data @ 10059980 : pointSpawningPointUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pointSpawningPointUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059990 : pointSpawningPointCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pointSpawningPointCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PointSpawningPointCatchPointer) },
    { 0, 0, 0, ((uint)&PointSpawningPointCatchContext) }
};

// R6Engine.dll data @ 100599b0 : pointSpawningPointTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pointSpawningPointTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pointSpawningPointCatchMap) }
};

// R6Engine.dll data @ 100599c4 : pointSpawningPointFuncInfo
// Binds the selected MSVC cleanup/catch maps for FindSpawningPoint.
const NativeFunctionInfoPrefix pointSpawningPointFuncInfo = { 0x19930520, 0x2, ((uint)&pointSpawningPointUnwindMap),
    0x1, ((uint)&pointSpawningPointTryMap), 0 };

// R6Engine.dll data @ 1007ac08 : autoclassAR6DZonePoint
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZonePoint = nullptr;

// R6Engine.dll @ 10009780 : AR6DZonePoint::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZonePoint::StaticClass(void)
{
    return &AR6DZonePoint::PrivateStaticClass; // Selected object at0x10082180.
}

// R6Engine.dll @ 10009790 : AR6DZonePoint::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZonePoint::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZonePoint::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10010270 : AR6DZonePoint::operator=
// Assigns the base, stance byte, reaction flag and five raw coordinate words, preserving padding and other flags.
AR6DZonePoint& AR6DZonePoint::operator=(const AR6DZonePoint& source)
{
    AR6DeploymentZone::operator=(source);
    // +0x49c only; preserve the following three padding bytes.
    reinterpret_cast<byte&>(m_eStance) = reinterpret_cast<const byte&>(source.m_eStance);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(&source) + 0x4a0);
    uint flags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x4a0);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x4a0) = flags ^ ((sourceFlags ^ flags) & 1U);
    reinterpret_cast<uint&>(m_fReactionZoneX) = reinterpret_cast<const uint&>(source.m_fReactionZoneX);
    reinterpret_cast<uint&>(m_fReactionZoneY) = reinterpret_cast<const uint&>(source.m_fReactionZoneY);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.X) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.X);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.Y) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.Y);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.Z) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.Z);
    return *this;
}

// R6Engine.dll @ 10012c70 : AR6DZonePoint::~AR6DZonePoint
// Runs ConditionalDestroy, then implicitly destroys the deployment-zone base on normal and exceptional exits.
AR6DZonePoint::~AR6DZonePoint()
{
    // Compiler installs vtable1004d7a8 first; state0 retains shared base cleanup10043940 via adapter10043948.
    UObject::ConditionalDestroy(); // Ignore its int result; the derived scalar fields have no owned resources.
}

// R6Engine.dll @ 10012cc0 : AR6DZonePoint::AR6DZonePoint(void)
// Constructs the deployment-zone base and installs the derived vtable without initializing the derived fields.
AR6DZonePoint::AR6DZonePoint() : AR6DeploymentZone()
{
    // Native EAX is the original receiver; stance, flags, dimensions and center retain their incoming storage.
}

// R6Engine.dll @ 10012ce0 : AR6DZonePoint::AR6DZonePoint(const AR6DZonePoint&)
// Copies the base, stance byte, reaction bit and raw dimension/center words in native order.
AR6DZonePoint::AR6DZonePoint(const AR6DZonePoint& source) : AR6DeploymentZone(source)
{
    // Compiler installs vtable1004d7a8 after the base. Each following copy reads the current source storage.
    reinterpret_cast<byte&>(m_eStance) = reinterpret_cast<const byte&>(source.m_eStance);
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(&source) + 0x4a0);
    uint flags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0x4a0);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x4a0) = flags ^ ((sourceFlags ^ flags) & 1U);
    reinterpret_cast<uint&>(m_fReactionZoneX) = reinterpret_cast<const uint&>(source.m_fReactionZoneX);
    reinterpret_cast<uint&>(m_fReactionZoneY) = reinterpret_cast<const uint&>(source.m_fReactionZoneY);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.X) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.X);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.Y) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.Y);
    reinterpret_cast<uint&>(m_vReactionZoneCenter.Z) = reinterpret_cast<const uint&>(source.m_vReactionZoneCenter.Z);
}

// R6Engine.dll @ 10013ab0 : AR6DZonePoint::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZonePoint::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZonePointConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001a430 : AR6DZonePoint::Spawned
// Runs base initialization and snapshots all three raw location words before storing the reaction-zone center.
void __thiscall AR6DZonePoint::Spawned(void)
{
    AR6DZonePoint* zone = this;
    try {
        zone->AR6DeploymentZone::Spawned();
        uint x = reinterpret_cast<const uint&>(zone->Location.X);
        uint y = reinterpret_cast<const uint&>(zone->Location.Y);
        uint z = reinterpret_cast<const uint&>(zone->Location.Z);
        reinterpret_cast<uint&>(zone->m_vReactionZoneCenter.X) = x;
        reinterpret_cast<uint&>(zone->m_vReactionZoneCenter.Y) = y;
        reinterpret_cast<uint&>(zone->m_vReactionZoneCenter.Z) = z;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePoint::Spawned");
        throw;
    }
}

// R6Engine.dll @ 1001a48c : PointSpawnedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawnedCatchPointer(void)
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

// R6Engine.dll @ 1001a4c0 : AR6DZonePoint::RenderEditorInfo
// Draws a selected point marker and current reaction bounds, retaining callback reads and delayed batcher cleanup.
void AR6DZonePoint::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* renderInterface,
    FDynamicActor* dynamicActor)
{
    try {
        this->AR6DeploymentZone::RenderEditorInfo(scene, renderInterface, dynamicActor);
        if ((*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(this) + 0xac) & 0x4000U) == 0) return;
        byte* sceneOwner = *(byte**)((byte*)scene + 4);
        FRenderInterface* sceneInterface = *(FRenderInterface**)(sceneOwner + 0x164);
        // Placement construction expresses native stack storage; cleanup becomes active only after the first Z sum.
        alignas(FLineBatcher) byte batcherStorage[sizeof(FLineBatcher)];
        FLineBatcher* batcher = new (batcherStorage) FLineBatcher(sceneInterface, 1, 0);
        const volatile float* location = (const volatile float*)&Location;
        // float10 denotes native x87 work under the caller's control word, not a recovered original C++ spelling.
        float10 maxZ = (float10)location[2] + (float10)85.0f; // Native state0 despite completed construction.
        try { // Native state1 enables the batcher cleanup from this point through both drawing calls.
            float10 maxY = (float10)location[1];
            FBox bounds; // IsValid alone is initialized; native copies the following three padding bytes unchanged.
            bounds.IsValid = 1;
            maxY += (float10)40.0f;
            FPlane plane;
            plane.X = 0.75f;
            float10 maxX = (float10)location[0] + (float10)40.0f;
            float roundedMaxX = (float)maxX;
            float roundedMaxY = (float)maxY;
            float roundedMaxZ = (float)maxZ;
            float10 minZ = (float10)location[2] - (float10)85.0f;
            float10 minY = (float10)location[1] - (float10)40.0f;
            float10 minX = (float10)location[0] - (float10)40.0f;
            bounds.Min.X = (float)minX;
            bounds.Min.Y = (float)minY;
            bounds.Min.Z = (float)minZ;
            bounds.Max.X = roundedMaxX;
            bounds.Max.Y = roundedMaxY;
            bounds.Max.Z = roundedMaxZ;
            plane.Y = 1.0f;
            plane.Z = 0.0f;
            plane.W = 0.0f;
            FColor color(plane);
            batcher->DrawBox(bounds, color); // Color construction precedes the complete seven-word box copy.
            if ((reinterpret_cast<const byte*>(this)[0x4a0] & 1U) != 0) {
                const volatile float* dimensions = (const volatile float*)&m_fReactionZoneX;
                volatile float halfY = (float)((float10)dimensions[1] * (float10)0.5f);
                bounds.IsValid = 1;
                plane.X = 0.75f;
                volatile float halfX = (float)((float10)dimensions[0] * (float10)0.5f);
                const volatile float* center = (const volatile float*)&m_vReactionZoneCenter;
                maxZ = (float10)center[2] + (float10)50.0f;
                maxY = (float10)halfY + (float10)center[1];
                maxX = (float10)halfX + (float10)center[0];
                roundedMaxX = (float)maxX;
                roundedMaxY = (float)maxY;
                roundedMaxZ = (float)maxZ;
                minZ = (float10)center[2] - (float10)50.0f;
                minY = (float10)center[1] - (float10)halfY;
                minX = (float10)center[0] - (float10)halfX;
                bounds.Min.X = (float)minX;
                bounds.Min.Y = (float)minY;
                bounds.Min.Z = (float)minZ;
                bounds.Max.X = roundedMaxX;
                bounds.Max.Y = roundedMaxY;
                bounds.Max.Z = roundedMaxZ;
                plane.Y = 1.0f;
                plane.Z = 0.0f;
                plane.W = 0.0f;
                FColor reactionColor(plane);
                batcher->DrawBox(bounds, reactionColor);
            }
        } catch (...) {
            batcher->~FLineBatcher(); // Native state1 unwind action precedes the enclosing typed/report handlers.
            throw;
        }
        batcher->~FLineBatcher(); // Native state0 before this call prevents a second cleanup if destruction fails.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePoint::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001a6f2 : PointZoneRenderingCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PointZoneRenderingCatchPointer(void)
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

// R6Engine.dll @ 1001a730 : AR6DZonePoint::FindRandomPointInArea
// Copies raw location words to the hidden vector result in sequence, retaining overlap effects.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePoint::FindRandomPointInArea(FVector* result)
{
    AR6DZonePoint* zone = this;
    reinterpret_cast<uint&>(result->X) = reinterpret_cast<const uint&>(zone->Location.X);
    reinterpret_cast<uint&>(result->Y) = reinterpret_cast<const uint&>(zone->Location.Y);
    reinterpret_cast<uint&>(result->Z) = reinterpret_cast<const uint&>(zone->Location.Z);
    return result;
}

// R6Engine.dll @ 1001a760 : AR6DZonePoint::FindSpawningPoint
// Copies rotation and widened stance, then delegates hidden-vector filling through the captured current vtable.
// Native ABI view keeps the hidden FVector result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePoint::FindSpawningPoint(FVector* result, FRotator* rotationOut, int* unusedIntegerOut,
    EStance* stanceOut, int* unusedFlagOut)
{
    AR6DZonePoint* zone = this;
    reinterpret_cast<uint&>(rotationOut->Pitch) = reinterpret_cast<const uint&>(zone->Rotation.Pitch);
    reinterpret_cast<uint&>(rotationOut->Yaw) = reinterpret_cast<const uint&>(zone->Rotation.Yaw);
    uint roll = reinterpret_cast<const uint&>(zone->Rotation.Roll);
    FVector* output = result;
    reinterpret_cast<uint&>(rotationOut->Roll) = roll;
    uint stance = reinterpret_cast<const byte&>(zone->m_eStance);
    *(uint*)stanceOut = stance; // Native zero-extends one byte and writes a complete four-byte enum word.
    byte* table = *(byte**)zone; // Native captures the table before state0, after all output writes.
    try {
        using FindPoint = FVector* (__thiscall*)(AR6DZonePoint*, FVector*);
        FindPoint find = *(FindPoint*)(table + 0x18c); // Slot lookup/call is guarded; table dereference above is not.
        find(zone, output); // Ignore the child's EAX: native returns its original hidden-result pointer.
        return output;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePoint::FindSpawningPoint");
        throw;
    }
}

// R6Engine.dll @ 1001a7ce : PointSpawningPointCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawningPointCatchPointer(void)
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

// R6Engine.dll @ 1001a800 : AR6DZonePoint::IsPointInZone
// Tests rounded offsets against strict vertical and inclusive radial/rectangle bounds using native x87 status bits.
int __thiscall AR6DZonePoint::IsPointInZone(const FVector& point)
{
    AR6DZonePoint* zone = this;
    // Cache before the query's X load.
    uint reaction = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(zone) + 0x4a0) & 1U;
    // float10 denotes x87 work under the caller's control word, not a recovered original C++ type.
    float10 queryX = (float10)point.X;
    const volatile float* center = reaction ? (const volatile float*)&zone->m_vReactionZoneCenter :
        (const volatile float*)&zone->Location;
    volatile float deltaX = (float)(queryX - (float10)center[0]);
    volatile float deltaY = (float)((float10)point.Y - (float10)center[1]);
    volatile float deltaZ = (float)((float10)point.Z - (float10)center[2]);
    ushort status;
    __asm { // C0 chooses FCHS for negative or unordered; the final C0 xor C2 accepts only |Z| < 100.
        fld dword ptr deltaZ
        fcomp dword ptr [nativeFloatZero]
        fld dword ptr deltaZ
        fnstsw ax
        test ah,1
        jz point_z_nonnegative
        fchs
    point_z_nonnegative:
        fcomp dword ptr [nativeFloat1EPlus02]
        fnstsw ax
        mov status,ax
    }
    if ((((status >> 8) ^ (status >> 10)) & 1U) == 0)
        return 0;
    if (reaction != 0) {
        __asm { // Compare |X| against the unspilled half extent; C0 xor C3 includes ordered equality.
            fld dword ptr deltaX
            fcomp dword ptr [nativeFloatZero]
            fld dword ptr deltaX
            fnstsw ax
            test ah,1
            jz point_x_nonnegative
            fchs
        point_x_nonnegative:
            mov eax,zone
            fld dword ptr [eax+0x4a4]
            fmul dword ptr [nativeFloatHalf]
            fxch st(1)
            fcompp
            fnstsw ax
            mov status,ax
        }
        if ((((status >> 8) ^ (status >> 14)) & 1U) == 0)
            return 0;
        __asm { // Y uses the same inclusive ordered comparison after the X test succeeds.
            fld dword ptr deltaY
            fcomp dword ptr [nativeFloatZero]
            fld dword ptr deltaY
            fnstsw ax
            test ah,1
            jz point_y_nonnegative
            fchs
        point_y_nonnegative:
            mov eax,zone
            fld dword ptr [eax+0x4a8]
            fmul dword ptr [nativeFloatHalf]
            fxch st(1)
            fcompp
            fnstsw ax
            mov status,ax
        }
    } else {
        __asm { // Keep both squares and Y-square + X-square in x87 until comparison with the native radius square.
            fld dword ptr deltaY
            fmul dword ptr deltaY
            fld dword ptr deltaX
            fmul dword ptr deltaX
            faddp st(1),st
            fcomp dword ptr [nativeFloat2Point5EPlus03]
            fnstsw ax
            mov status,ax
        }
    }
    return (((status >> 8) ^ (status >> 14)) & 1U) != 0;
}

// R6Engine.dll @ 1001a930 : AR6DZonePoint::FindClosestPointTo
// Copies actor location unless reaction bounds are enabled; then clamps query X/Y and preserves its raw Z.
// Native ABI view keeps the hidden result buffer and its returned EAX pointer explicit.
FVector* __thiscall AR6DZonePoint::FindClosestPointTo(FVector* result, const FVector* point)
{
    AR6DZonePoint* zone = this;
    uint x = reinterpret_cast<const uint&>(zone->Location.X);
    uint y = reinterpret_cast<const uint&>(zone->Location.Y);
    uint z = reinterpret_cast<const uint&>(zone->Location.Z);
    if ((reinterpret_cast<const byte*>(zone)[0x4a0] & 1U) != 0) {
        // float10 denotes native x87 work; X's half extent stays wide, while Y's narrows before either clamp.
        float10 halfX = (float10)zone->m_fReactionZoneX * (float10)nativeFloatHalf;
        x = reinterpret_cast<const uint&>(point->X);
        float10 halfY = (float10)zone->m_fReactionZoneY * (float10)nativeFloatHalf;
        y = reinterpret_cast<const uint&>(point->Y);
        z = reinterpret_cast<const uint&>(point->Z);
        volatile float roundedHalfY = (float)halfY;
        volatile float upperX = (float)(halfX + (float10)zone->m_vReactionZoneCenter.X);
        float10 lowerX = (float10)zone->m_vReactionZoneCenter.X - halfX;
        ushort status;
        __asm {
            fld tbyte ptr lowerX
            fld dword ptr x
            fcomp st(1)
            fnstsw ax
            mov status,ax
            fstp st(0)
        }
        if ((((status >> 8) ^ (status >> 10)) & 1U) != 0) { // Ordered strict less than the wide lower bound.
            volatile float roundedLowerX = (float)lowerX;
            x = reinterpret_cast<const uint&>(const_cast<const float&>(roundedLowerX));
        } else {
            __asm {
                fld dword ptr x
                fcomp dword ptr upperX
                fnstsw ax
                mov status,ax
            }
            if ((((status >> 8) ^ (status >> 10)) & 1U) == 0) // Equal, greater or unordered selects raw upper.
                x = reinterpret_cast<const uint&>(const_cast<const float&>(upperX));
        }
        volatile float upperY = (float)((float10)roundedHalfY + (float10)zone->m_vReactionZoneCenter.Y);
        float10 lowerY = (float10)zone->m_vReactionZoneCenter.Y - (float10)roundedHalfY;
        __asm {
            fld tbyte ptr lowerY
            fld dword ptr y
            fcomp st(1)
            fnstsw ax
            mov status,ax
            fstp st(0)
        }
        if ((((status >> 8) ^ (status >> 10)) & 1U) != 0) {
            volatile float roundedLowerY = (float)lowerY;
            y = reinterpret_cast<const uint&>(const_cast<const float&>(roundedLowerY));
        } else {
            __asm {
                fld dword ptr y
                fcomp dword ptr upperY
                fnstsw ax
                mov status,ax
            }
            if ((((status >> 8) ^ (status >> 10)) & 1U) == 0)
                y = reinterpret_cast<const uint&>(const_cast<const float&>(upperY));
        }
    }
    reinterpret_cast<uint&>(result->X) = x; // All actor/query/bound reads finish before the first output write.
    reinterpret_cast<uint&>(result->Y) = y;
    reinterpret_cast<uint&>(result->Z) = z;
    return result;
}

// R6Engine.dll @ 100440f0 : PointZoneRenderingState1Cleanup
// Destroys the live FLineBatcher at inherited dispatcher-frame EBP-0x74.
__declspec(naked) void __cdecl PointZoneRenderingState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x74]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 100480a0 : DestroyAR6DZonePointClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZonePointClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZonePoint::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046640 : InitializeAR6DZonePointClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZonePointClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZonePoint::PrivateStaticClass, 0, 0x4b8, 0,
        &AR6DeploymentZone::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZonePoint, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6DZonePoint::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZonePointClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100466c0 : PublishAR6DZonePointAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZonePointAutoClass(void)
{
    autoclassAR6DZonePoint = &AR6DZonePoint::PrivateStaticClass;
}

// R6Engine.dll @ 10012d60 : AR6DZonePoint::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZonePoint::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZonePoint* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZonePointDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x4b8, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZonePoint::~AR6DZonePoint(); // Direct native call10012c70, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x4b8);
    }
    return object;
}

// R6Engine.dll @ 1001a4a0 : PointSpawnedCatchContext
// Reports AR6DZonePoint::Spawned and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawnedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePointSpawned
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001a7e2 : PointSpawningPointCatchContext
// Reports AR6DZonePoint::FindSpawningPoint and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PointSpawningPointCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePointFindSpawningPoint
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100440e0 : PointSpawnedExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PointSpawnedExceptionHandler(void)
{
    __asm {
        mov eax,offset pointSpawnedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10044110 : PointSpawningPointExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PointSpawningPointExceptionHandler(void)
{
    __asm {
        mov eax,offset pointSpawningPointFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001a706 : PointZoneRenderingCatchContext
// Reports AR6DZonePoint::RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PointZoneRenderingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePointRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100440f9 : PointZoneRenderingExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PointZoneRenderingExceptionHandler(void)
{
    __asm {
        mov eax,offset pointZoneRenderingFuncInfo
        jmp __CxxFrameHandler
    }
}
