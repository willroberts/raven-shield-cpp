#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"
#include "native_collision_views.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6LadderVolumeClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b020 : AR6LadderVolumeVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6LadderVolume::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6LadderVolumeVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10050dec : nativeTextAR6LadderVolumeAddMyMarker
extern const ushort nativeTextAR6LadderVolumeAddMyMarker[29];

// R6Engine.dll data @ 10050db0 : nativeTextAR6LadderVolumeShouldTrace
extern const ushort nativeTextAR6LadderVolumeShouldTrace[29];

// R6Engine.dll data @ 1005599e : nativeTextR6LadderVolume
extern const ushort nativeTextR6LadderVolume[15];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl LadderMarkerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl LadderMarkerCatchPointer(void);
__declspec(naked) void LadderShouldTraceCatchContext(void);
__declspec(naked) void LadderShouldTraceCatchPointer(void);
__declspec(naked) void LadderVolumeDtorExceptionHandler(void);
__declspec(naked) void LadderVolumeDtorState0Cleanup(void);

// R6Engine.dll data @ 1005a848 : ladderMarkerUnwind
// Retains exact guarded states and inherited typed/context catches, with no owned local cleanup.
const NativeUnwindEntry ladderMarkerUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a858 : ladderMarkerCatch
// Retains exact guarded states and inherited typed/context catches, with no owned local cleanup.
const NativeCatchEntry ladderMarkerCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&LadderMarkerCatchPointer) },
    { 0, 0, 0, ((uint)&LadderMarkerCatchContext) }
};

// R6Engine.dll data @ 1005a878 : ladderMarkerTry
// Retains exact guarded states and inherited typed/context catches, with no owned local cleanup.
const NativeTryBlock ladderMarkerTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ladderMarkerCatch) }
};

// R6Engine.dll data @ 1005a88c : ladderMarkerInfo
// Retains exact guarded states and inherited typed/context catches, with no owned local cleanup.
const NativeFunctionInfoPrefix ladderMarkerInfo = { 0x19930520, 0x2, ((uint)&ladderMarkerUnwind), 0x1,
    ((uint)&ladderMarkerTry), 0 };

// R6Engine.dll data @ 1005a7e8 : ladderShouldTraceUnwind
// The guarded body and catches have no owned local cleanup.
const NativeUnwindEntry ladderShouldTraceUnwind[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005a7f8 : ladderShouldTraceCatch
// Typed text-pointer and context catches inherit the parent frame.
const NativeCatchEntry ladderShouldTraceCatch[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&LadderShouldTraceCatchPointer) },
    { 0, 0, 0, ((uint)&LadderShouldTraceCatchContext) }
};

// R6Engine.dll data @ 1005a818 : ladderShouldTraceTry
// State zero guards the flag/base test; state one describes its two catches.
const NativeTryBlock ladderShouldTraceTry[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&ladderShouldTraceCatch) }
};

// R6Engine.dll data @ 1005a82c : ladderShouldTraceInfo
// Exact parent-specific exception metadata for ShouldTrace.
const NativeFunctionInfoPrefix ladderShouldTraceInfo = { 0x19930520, 0x2, ((uint)&ladderShouldTraceUnwind), 0x1,
    ((uint)&ladderShouldTraceTry), 0 };

// R6Engine.dll data @ 10056dcc : ladderVolumeDtorUnwind
// State zero destroys the imported LadderVolume base and terminates cleanup.
const NativeUnwindEntry ladderVolumeDtorUnwind[1] = {
    { -1, ((uint)&LadderVolumeDtorState0Cleanup) }
};

// R6Engine.dll data @ 10056dd4 : ladderVolumeDtorInfo
// Destruction has one base-cleanup state and no catches.
const NativeFunctionInfoPrefix ladderVolumeDtorInfo = { 0x19930520, 0x1, ((uint)&ladderVolumeDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 100773cc : autoclassAR6LadderVolume
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6LadderVolume = nullptr;

// R6Engine.dll @ 10007620 : AR6LadderVolume::eventSetPotentialClimber
// Dispatches SetPotentialClimber with no parameters through the vtable captured before lookup.
void __thiscall AR6LadderVolume::eventSetPotentialClimber(void)
{
    FName eventName = R6ENGINE_SetPotentialClimber;
    using ProcessEvent = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, eventName, 0);
    reinterpret_cast<ProcessEvent&>(cachedVtable->processEventAddress)(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10007650 : AR6LadderVolume::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6LadderVolume::StaticClass(void)
{
    return &AR6LadderVolume::PrivateStaticClass; // Selected object at0x100826a8.
}

// R6Engine.dll @ 10007660 : AR6LadderVolume::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6LadderVolume::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6LadderVolume::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10007690 : AR6LadderVolume::~AR6LadderVolume
// Conditionally destroys UObject state before entering imported LadderVolume destruction.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6LadderVolume::~AR6LadderVolume(AR6LadderVolume* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&LadderVolumeDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6LadderVolumeVirtualTable);
    guard[3] = 0;
    this->UObject::ConditionalDestroy();
    guard[3] = 0xffffffff;
    this->ALadderVolume::~ALadderVolume();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 100076f0 : AR6LadderVolume::AR6LadderVolume (native default-constructor view)
// Constructs the ALadderVolume base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6LadderVolumeVirtualTable follows base completion.
AR6LadderVolume::AR6LadderVolume() : ALadderVolume()
{
}

// R6Engine.dll @ 10007710 : AR6LadderVolume::AR6LadderVolume
// Copies ladder-end settings, ladder/collision links, six climbers and sound references.
AR6LadderVolume::AR6LadderVolume(const AR6LadderVolume& sourceObject) : ALadderVolume(sourceObject)
{
    // Publishes AR6LadderVolumeVirtualTable after base copy; native EAX retains original storage.
    const AR6LadderVolume* source = &sourceObject;
    this->m_eLadderEndDirection = source->m_eLadderEndDirection;
    // Source word precedes destination read.
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x4b4);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x4b4);
    uint destinationFlags = *destinationFlagWord;
    *destinationFlagWord = destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    reinterpret_cast<uint&>(this->m_fBottomLadderActionRange) = reinterpret_cast<const
        uint&>(source->m_fBottomLadderActionRange);
    this->m_TopLadder = source->m_TopLadder;
    this->m_BottomLadder = source->m_BottomLadder;
    this->m_TopCollision = source->m_TopCollision;
    this->m_BottomCollision = source->m_BottomCollision;
    this->m_Climber[0] = source->m_Climber[0];
    this->m_Climber[1] = source->m_Climber[1];
    this->m_Climber[2] = source->m_Climber[2];
    this->m_Climber[3] = source->m_Climber[3];
    this->m_Climber[4] = source->m_Climber[4];
    this->m_Climber[5] = source->m_Climber[5];
    this->m_SlideSound = source->m_SlideSound;
    this->m_SlideSoundStop = source->m_SlideSoundStop;
    this->m_HandSound = source->m_HandSound;
    this->m_FootSound = source->m_FootSound;
}

// R6Engine.dll @ 100077f0 : AR6LadderVolume::operator=
// Copies ladder-end settings, ladder/collision links, six climbers and sound references.
AR6LadderVolume& __thiscall AR6LadderVolume::operator=(const AR6LadderVolume& sourceObject)
{
    const AR6LadderVolume* source = &sourceObject;
    this->ALadderVolume::operator=(*source);
    this->m_eLadderEndDirection = source->m_eLadderEndDirection;
    // Source word precedes destination read.
    uint sourceFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x4b4);
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x4b4);
    uint destinationFlags = *destinationFlagWord;
    *destinationFlagWord = destinationFlags ^ ((sourceFlags ^ destinationFlags) & 1U);
    reinterpret_cast<uint&>(this->m_fBottomLadderActionRange) = reinterpret_cast<const
        uint&>(source->m_fBottomLadderActionRange);
    this->m_TopLadder = source->m_TopLadder;
    this->m_BottomLadder = source->m_BottomLadder;
    this->m_TopCollision = source->m_TopCollision;
    this->m_BottomCollision = source->m_BottomCollision;
    this->m_Climber[0] = source->m_Climber[0];
    this->m_Climber[1] = source->m_Climber[1];
    this->m_Climber[2] = source->m_Climber[2];
    this->m_Climber[3] = source->m_Climber[3];
    this->m_Climber[4] = source->m_Climber[4];
    this->m_Climber[5] = source->m_Climber[5];
    this->m_SlideSound = source->m_SlideSound;
    this->m_SlideSoundStop = source->m_SlideSoundStop;
    this->m_HandSound = source->m_HandSound;
    this->m_FootSound = source->m_FootSound;
    return *this;
}

// R6Engine.dll @ 1000dc90 : AR6LadderVolume::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6LadderVolume::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6LadderVolumeConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10020b00 : AR6LadderVolume::ShouldTrace
// Accepts the special trace flag or a nonzero volume-base result, returning exactly zero or one.
int __thiscall AR6LadderVolume::ShouldTrace(AActor* actor, ulong traceFlags)
{
    uint flagWord = (uint)traceFlags;
    bool specialTrace = (flagWord & 0x80000U) != 0; // Native input read and TEST precede catch state zero.
    try {
        if (specialTrace) return 1;
        AActor* traceActor = actor; // Only the fallback reads this argument.
        using BaseTrace = int (__thiscall*)(AVolume*, AActor*, ulong);
        BaseTrace trace = reinterpret_cast<BaseTrace&>(AVolumeShouldTraceImport);
        int baseResult = trace(this, traceActor, flagWord);
        return baseResult != 0 ? 1 : 0; // Native normalizes the full base EAX rather than forwarding it.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6LadderVolume::ShouldTrace");
        throw;
    }
}

// R6Engine.dll @ 10020b54 : LadderShouldTraceCatchPointer
// Forwards the caught text pointer through a fresh parent-frame throw slot.
__declspec(naked) void LadderShouldTraceCatchPointer(void)
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

// R6Engine.dll @ 10020b68 : LadderShouldTraceCatchContext
// Reports method context through the current unwind import and rethrows the active exception.
__declspec(naked) void LadderShouldTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6LadderVolumeShouldTrace
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044400 : LadderShouldTraceExceptionHandler
// Selects ShouldTrace's catch metadata and tail-enters the native exception dispatcher.
__declspec(naked) void LadderShouldTraceExceptionHandler(void)
{
    __asm {
        mov eax,offset ladderShouldTraceInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10020ba0 : AR6LadderVolume::AddMyMarker
// Finds the ladder-facing wall, spawns endpoint markers and links their planning floors and clearance flags.
void __thiscall AR6LadderVolume::AddMyMarker(AActor* scout)
{
    // Read and TEST precede native catch state zero.
    byte autoPathFlags = *reinterpret_cast<byte*>(reinterpret_cast<byte*>(this) + 0x478);
    bool autoPath = (autoPathFlags & 2) != 0;
    try {
        float bestDistance = 100.0f;
        if (!autoPath || scout == nullptr) return;
        if (scout->UObject::IsA(AScoutPrivateStaticClassImport) == 0) return;
        UClass* markerClass = static_cast<UClass*>(UObject::StaticFindObjectChecked(UClassPrivateStaticClassImport,
            reinterpret_cast<UObject*>(0xffffffffU), (const ushort*)L"R6Ladder", 0));
        const FVector* zero = *(const FVector**)&FVectorFVector0Import;
        // The same 48-byte hit record survives every trace.
        NativeCheckResult32 hit = {0, 0, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0, 1.0f, -1, 0};
        FVector* location = &this->Location;
        FVector* prePivot = &this->PrePivot;
        if (prePivot->X != zero->X || prePivot->Y != zero->Y || prePivot->Z != zero->Z) {
            float10 z = (float10)location->Z - prePivot->Z;
            float10 y = (float10)location->Y - prePivot->Y;
            float10 x = (float10)location->X - prePivot->X;
            location->X = (float)x;
            location->Y = (float)y;
            location->Z = (float)z;
            zero = *(const FVector**)&FVectorFVector0Import;
            reinterpret_cast<uint&>(prePivot->X) = reinterpret_cast<const uint&>(zero->X);
            reinterpret_cast<uint&>(prePivot->Y) = reinterpret_cast<const uint&>(zero->Y);
            reinterpret_cast<uint&>(prePivot->Z) = reinterpret_cast<const uint&>(zero->Z);
        }
        FVector end;
        FVector wallFacing; // Native leaves this scratch uninitialized if no distance below100 is accepted.
        using Trace = int (__thiscall*)(ULevel*, NativeCheckResult32*, AActor*, const FVector*, const FVector*, uint,
            FVector);
        using SizeST0 = float10 (__thiscall*)(const FVector*); // Native ST0 view of FVector::Size's float return.
        // Describes four inlined probes in native order; each uses the current location and level.
        for (int probe = 0; probe != 4; ++probe) {
            end = *location;
            if (probe == 0) end.Y = (float)((float10)end.Y + 80.0f);
            else if (probe == 1) end.Y = (float)((float10)end.Y - 80.0f);
            else if (probe == 2) end.X = (float)((float10)end.X + 80.0f);
            else end.X = (float)((float10)end.X - 80.0f);
            ULevel* level = this->XLevel;
            Trace trace = *(Trace*)(*(byte**)level + 0xcc);
            FVector extent = **(const FVector**)&FVectorFVector0Import;
            trace(this->XLevel, &hit, this, &end, location, 0x86, extent);
            if (hit.Time != 1.0f) { // Native treats unordered time as a hit.
                float10 dz = (float10)hit.Location.Z - location->Z;
                float10 dy = (float10)hit.Location.Y - location->Y;
                float10 dx = (float10)hit.Location.X - location->X;
                end.X = (float)dx;
                end.Y = (float)dy;
                end.Z = (float)dz;
                float10 distance = reinterpret_cast<SizeST0&>(FVectorSizeImport)(&end);
                volatile float distanceSpill = (float)distance; // FST does not round the comparison operand.
                (void)distanceSpill;
                if (distance < (probe == 0 ? (float10)100.0f : (float10)bestDistance)) {
                    bestDistance = (float)distance;
                    float10 nz = -(float10)hit.Normal.Z;
                    float10 ny = -(float10)hit.Normal.Y;
                    float10 nx = -(float10)hit.Normal.X;
                    wallFacing.X = (float)nx;
                    wallFacing.Y = (float)ny;
                    wallFacing.Z = (float)nz;
                }
            }
        }
        if ((double)bestDistance == 100.0) {
            (**(FOutputDevice***)&CoreGLogImport)->FOutputDevice::Logf(
                (const ushort*)L" PROBLEM !! COULD NOT FIND DIRECTION OF LADDER ");
        }
        // The warning continues into the native path even when wallFacing has no initialized value.
        FVector* climbDir = &this->ClimbDir;
        float10 zProduct = (float10)climbDir->Z * 10000.0f;
        float yProduct = (float)((float10)climbDir->Y * 10000.0f);
        float xProduct = (float)((float10)climbDir->X * 10000.0f);
        float10 endZ = (float10)location->Z - zProduct;
        float10 endY = (float10)location->Y - yProduct;
        float10 endX = (float10)location->X - xProduct;
        end.X = (float)endX;
        end.Y = (float)endY;
        end.Z = (float)endZ;
        ULevel* level = this->XLevel;
        Trace trace = *(Trace*)(*(byte**)level + 0xcc);
        FVector extent = **(const FVector**)&FVectorFVector0Import;
        trace(this->XLevel, &hit, this, &end, location, 0x86, extent);
        if (hit.Time == 1.0f) return;
        AActor* markerDefault = markerClass->UClass::GetDefaultActor();
        float10 height = markerDefault->CollisionHeight;
        level = this->XLevel; // Captured before Rotation; its vtable is read after the callback.
        float heightZ = (float)(height * climbDir->Z);
        float heightY = (float)(height * climbDir->Y);
        float heightX = (float)(height * climbDir->X);
        FVector bottomLocation;
        float10 bottomZ = (float10)hit.Location.Z + heightZ;
        float10 bottomY = (float10)hit.Location.Y + heightY;
        float10 bottomX = (float10)heightX + hit.Location.X;
        bottomLocation.X = (float)bottomX;
        bottomLocation.Y = (float)bottomY;
        bottomLocation.Z = (float)bottomZ;
        using RotationCall = FRotator* (__thiscall*)(FVector*, FRotator*);
        using Spawn = AActor* (__thiscall*)(ULevel*, UClass*, FName, FVector, FRotator, AActor*, int, int, AActor*,
            APawn*);
        uint scratch54[3]; // Native EBP-54: bottom Rotation output, then reused X-product/top-point scratch.
        uint scratch60[3]; // Native EBP-60: shared Vector, FindTop and top Rotation output storage.
        FRotator* bottomRotationStorage = (FRotator*)scratch54;
        FRotator* topRotationStorage = (FRotator*)scratch60;
        FVector* vectorStorage = (FVector*)scratch60;
        FRotator* rotation = &(*bottomRotationStorage = wallFacing.Rotation());
        FRotator spawnRotation = *rotation; // Copies Pitch, Yaw and Roll from the bottom rotation slot.
        AR6Ladder* bottom = static_cast<AR6Ladder*>((*(Spawn*)(*(byte**)level + 0xa8))(
            level, markerClass, FName(0), bottomLocation, spawnRotation, nullptr, 0, 0, nullptr, nullptr));
        this->m_BottomLadder = bottom;
        if (bottom != nullptr) {
            reinterpret_cast<uint&>(bottom->m_iPlanningFloor_0) = reinterpret_cast<uint&>(this->m_iPlanningFloor_0);
            reinterpret_cast<uint&>(this->m_BottomLadder->m_iPlanningFloor_1) =
                reinterpret_cast<uint&>(this->m_iPlanningFloor_0);
            rotation = &(*bottomRotationStorage = wallFacing.Rotation());
            int planningYaw = rotation->Yaw / 255;
            this->m_BottomLadder->m_u8SpritePlanningAngle = (byte)(planningYaw + 64);
            // m_bIsTopOfLadder=false.
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_BottomLadder) + 0x3f0) &= ~1u;
            bottom = this->m_BottomLadder;
            level = this->XLevel;
            FVector* facing = &(*vectorStorage = bottom->Rotation.Vector());
            zProduct = (float10)facing->Z * 400.0f;
            yProduct = (float)((float10)facing->Y * 400.0f);
            xProduct = (float)((float10)facing->X * 400.0f);
            *(float*)scratch54 = xProduct;
            FVector* start = &this->m_BottomLadder->Location;
            endZ = (float10)start->Z - zProduct;
            endY = (float10)start->Y - yProduct;
            endX = (float10)start->X - xProduct;
            end.X = (float)endX;
            end.Y = (float)endY;
            end.Z = (float)endZ;
            trace = *(Trace*)(*(byte**)level + 0xcc);
            extent = **(const FVector**)&FVectorFVector0Import;
            trace(level, &hit, this, &end, start, 0x86, extent);
            uint* flags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_BottomLadder) + 0x3f0);
            uint previous = *flags;
            *flags = hit.Time != 1.0f ? previous | 2 : previous & ~2u; // m_bSingleFileFormationOnly.
        }
        zProduct = (float10)climbDir->Z * 1500.0f;
        yProduct = (float)((float10)climbDir->Y * 1500.0f);
        xProduct = (float)((float10)climbDir->X * 1500.0f);
        *(float*)scratch54 = xProduct;
        endZ = zProduct + location->Z;
        endY = (float10)yProduct + location->Y;
        endX = (float10)xProduct + location->X;
        end.X = (float)endX;
        end.Y = (float)endY;
        end.Z = (float)endZ;
        using FindTop = FVector* (__thiscall*)(ALadderVolume*, FVector*, FVector);
        FVector* foundTop = reinterpret_cast<FindTop&>(ALadderVolumeFindTopImport)(this, vectorStorage, end);
        zProduct = (float10)wallFacing.Z * 30.0f;
        yProduct = (float)((float10)wallFacing.Y * 30.0f);
        FVector topPoint = *foundTop;
        RotationCall cachedRotation = reinterpret_cast<RotationCall&>(FVectorRotationImport);
        level = this->XLevel;
        xProduct = (float)((float10)wallFacing.X * 30.0f);
        *(uint*)scratch54 = reinterpret_cast<uint&>(topPoint.X);
        endZ = zProduct + ((float10)topPoint.Z - 15.0f);
        endY = (float10)topPoint.Y + yProduct;
        endX = (float10)topPoint.X + xProduct;
        end.X = (float)endX;
        end.Y = (float)endY;
        end.Z = (float)endZ;
        rotation = cachedRotation(&wallFacing, topRotationStorage);
        spawnRotation = *rotation;
        AR6Ladder* top = static_cast<AR6Ladder*>((*(Spawn*)(*(byte**)level + 0xa8))(
            level, markerClass, FName(0), end, spawnRotation, nullptr, 0, 0, nullptr, nullptr));
        this->m_TopLadder = top;
        if (top != nullptr) {
            // Both top floors use m_iPlanningFloor_1.
            reinterpret_cast<uint&>(top->m_iPlanningFloor_0) = reinterpret_cast<uint&>(this->m_iPlanningFloor_1);
            reinterpret_cast<uint&>(this->m_TopLadder->m_iPlanningFloor_1) =
                reinterpret_cast<uint&>(this->m_iPlanningFloor_1);
            if (reinterpret_cast<uint&>(this->m_iPlanningFloor_1) ==
                reinterpret_cast<uint&>(this->m_iPlanningFloor_0)) {
                // bHidden when floors coincide.
                *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_TopLadder) + 0xa0) |= 2;
            }
            rotation = cachedRotation(&wallFacing, topRotationStorage);
            int planningYaw = rotation->Yaw / 255;
            this->m_TopLadder->m_u8SpritePlanningAngle = (byte)(planningYaw + 64);
            *reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_TopLadder) + 0x3f0) |= 1;
            this->m_TopLadder->AActor::SetCollisionSize(50.0f, 20.0f);
            top = this->m_TopLadder;
            level = this->XLevel;
            FVector* facing = &(*vectorStorage = top->Rotation.Vector());
            zProduct = (float10)facing->Z * 400.0f;
            yProduct = (float)((float10)facing->Y * 400.0f);
            xProduct = (float)((float10)facing->X * 400.0f);
            *(float*)scratch54 = xProduct;
            FVector* start = &this->m_TopLadder->Location;
            endZ = zProduct + start->Z;
            endY = (float10)yProduct + start->Y;
            endX = (float10)xProduct + start->X;
            end.X = (float)endX;
            end.Y = (float)endY;
            end.Z = (float)endZ;
            trace = *(Trace*)(*(byte**)level + 0xcc);
            extent = **(const FVector**)&FVectorFVector0Import;
            trace(level, &hit, this, &end, start, 0x86, extent);
            uint* flags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this->m_TopLadder) + 0x3f0);
            uint previous = *flags;
            *flags = hit.Time != 1.0f ? previous | 2 : previous & ~2u;
        }
        top = this->m_TopLadder;
        if (top != nullptr && this->m_BottomLadder != nullptr) {
            top->m_pOtherFloor = this->m_BottomLadder;
            this->m_BottomLadder->m_pOtherFloor = this->m_TopLadder;
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6LadderVolume::AddMyMarker");
        throw;
    }
}

// R6Engine.dll @ 10021594 : LadderMarkerCatchPointer
// Rethrows the caught text pointer through a temporary in the inherited AddMyMarker frame.
__declspec(naked) __declspec(noreturn) void __cdecl LadderMarkerCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo
        lea edx,[ebp-0x20]
        push edx
        mov dword ptr [ebp-0x20],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100215a8 : LadderMarkerCatchContext
// Reports AddMyMarker context and rethrows the active exception from the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl LadderMarkerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6LadderVolumeAddMyMarker
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043250 : LadderVolumeDtorState0Cleanup
// Tail-enters imported base destruction through the inherited parent-frame saved receiver.
__declspec(naked) void LadderVolumeDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [ALadderVolumeDestructorImport]
    }
}

// R6Engine.dll @ 10043259 : LadderVolumeDtorExceptionHandler
// Selects LadderVolume base-cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void LadderVolumeDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset ladderVolumeDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10046d60 : InitializeAR6LadderVolumeClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6LadderVolumeClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // ALadderVolume object address, captured before config lookup.
    UClass* parentClass = ALadderVolumePrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6LadderVolume::PrivateStaticClass, 0, 0x4f4, 0,
        parentClass,
        withinClass,
        *(FGuid*)guidWords, nativeTextR6LadderVolume, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6LadderVolume::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6LadderVolumeClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048160 : DestroyAR6LadderVolumeClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6LadderVolumeClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6LadderVolume::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046df0 : PublishAR6LadderVolumeAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6LadderVolumeAutoClass(void)
{
    autoclassAR6LadderVolume = &AR6LadderVolume::PrivateStaticClass;
}

// R6Engine.dll @ 10044410 : LadderMarkerExceptionHandler
// Supplies the exact guarded marker FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl LadderMarkerExceptionHandler(void)
{
    __asm {
        mov eax,offset ladderMarkerInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100078e0 : AR6LadderVolume::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6LadderVolume::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6LadderVolumeDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x4f4;
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
    this->AR6LadderVolume::~AR6LadderVolume();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x4f4;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
