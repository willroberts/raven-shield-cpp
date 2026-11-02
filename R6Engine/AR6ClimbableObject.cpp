#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6ClimbableObjectClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004b690 : AR6ClimbableObjectVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6ClimbableObject::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6ClimbableObjectVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004ed48 : nativeTextAR6ClimbableObjectAddMyMarker
extern const ushort nativeTextAR6ClimbableObjectAddMyMarker[32];

// R6Engine.dll data @ 1004ec98 : nativeTextAR6ClimbableObjectPostScriptDestroyed
extern const ushort nativeTextAR6ClimbableObjectPostScriptDestroyed[40];

// R6Engine.dll data @ 1004ec58 : nativeTextAR6ClimbableObjectShouldTrace
extern const ushort nativeTextAR6ClimbableObjectShouldTrace[32];

// R6Engine.dll data @ 100559fa : nativeTextR6ClimbableObject
extern const ushort nativeTextR6ClimbableObject[18];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableAddMyMarkerCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableAddMyMarkerCatchPointer(void);
__declspec(naked) void __cdecl ClimbableDestructionState0Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePostScriptDestroyedCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePostScriptDestroyedCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableShouldTraceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableShouldTraceCatchPointer(void);

// R6Engine.dll data @ 1005884c : climbableAddMyMarkerUnwindMap
// Two terminal states have no local cleanup actions.
const NativeUnwindEntry climbableAddMyMarkerUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005885c : climbableAddMyMarkerCatchMap
// Typed unsigned-short pointer catch at parent EBP-20 followed by context catch-all.
const NativeCatchEntry climbableAddMyMarkerCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -32, ((uint)&ClimbableAddMyMarkerCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbableAddMyMarkerCatchContext) }
};

// R6Engine.dll data @ 1005887c : climbableAddMyMarkerTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock climbableAddMyMarkerTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbableAddMyMarkerCatchMap) }
};

// R6Engine.dll data @ 10058890 : climbableAddMyMarkerFuncInfo
// Exact AddMyMarker frame metadata.
const NativeFunctionInfoPrefix climbableAddMyMarkerFuncInfo = { 0x19930520, 0x2, ((uint)&climbableAddMyMarkerUnwindMap),
    0x1, ((uint)&climbableAddMyMarkerTryMap), 0 };

// R6Engine.dll data @ 10056e80 : climbableDestructionUnwindMap
// State0 destroys the completed base through its parent-frame tail.
const NativeUnwindEntry climbableDestructionUnwindMap[1] = {
    { -1, ((uint)&ClimbableDestructionState0Cleanup) }
};

// R6Engine.dll data @ 10056e88 : climbableDestructionFuncInfo
// Exact destructor frame metadata.
const NativeFunctionInfoPrefix climbableDestructionFuncInfo = { 0x19930520, 0x1, ((uint)&climbableDestructionUnwindMap),
    0, 0, 0 };

// R6Engine.dll data @ 1005878c : climbableShouldTraceUnwindMap
// Two terminal states with no local object cleanup.
const NativeUnwindEntry climbableShouldTraceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005879c : climbableShouldTraceCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry climbableShouldTraceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbableShouldTraceCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbableShouldTraceCatchContext) }
};

// R6Engine.dll data @ 100587bc : climbableShouldTraceTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock climbableShouldTraceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbableShouldTraceCatchMap) }
};

// R6Engine.dll data @ 100587d0 : climbableShouldTraceFuncInfo
// Exact ShouldTrace frame metadata.
const NativeFunctionInfoPrefix climbableShouldTraceFuncInfo = { 0x19930520, 0x2, ((uint)&climbableShouldTraceUnwindMap),
    0x1, ((uint)&climbableShouldTraceTryMap), 0 };

// R6Engine.dll data @ 100587ec : climbablePostScriptDestroyedUnwindMap
// Two terminal states with no local object cleanup.
const NativeUnwindEntry climbablePostScriptDestroyedUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100587fc : climbablePostScriptDestroyedCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry climbablePostScriptDestroyedCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbablePostScriptDestroyedCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbablePostScriptDestroyedCatchContext) }
};

// R6Engine.dll data @ 1005881c : climbablePostScriptDestroyedTryMap
// State0 body and state1 catch region select both handlers.
const NativeTryBlock climbablePostScriptDestroyedTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbablePostScriptDestroyedCatchMap) }
};

// R6Engine.dll data @ 10058830 : climbablePostScriptDestroyedFuncInfo
// Exact PostScriptDestroyed frame metadata.
const NativeFunctionInfoPrefix climbablePostScriptDestroyedFuncInfo = {
    0x19930520, 0x2, ((uint)&climbablePostScriptDestroyedUnwindMap), 0x1, ((uint)&climbablePostScriptDestroyedTryMap), 0
};

// R6Engine.dll data @ 10082170 : autoclassAR6ClimbableObject
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6ClimbableObject = nullptr;

// R6Engine.dll @ 10008be0 : AR6ClimbableObject::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6ClimbableObject::StaticClass(void)
{
    return &AR6ClimbableObject::PrivateStaticClass; // Selected object at0x1007df30.
}

// R6Engine.dll @ 10008bf0 : AR6ClimbableObject::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6ClimbableObject::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6ClimbableObject::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10008c20 : AR6ClimbableObject::~AR6ClimbableObject
// Runs conditional cleanup before automatic AR6AbstractClimbableObj base destruction.
AR6ClimbableObject::~AR6ClimbableObject()
{
    // Compiler installs vtable1004b690 and arms state0 for the completed base during this call.
    UObject::ConditionalDestroy();
    // Implicit base destruction calls current49504 under state-1; EH action432b0 handles failed conditional cleanup.
}

// R6Engine.dll @ 10008c80 : AR6ClimbableObject::AR6ClimbableObject()
// Constructs the AR6AbstractClimbableObj base and leaves derived storage untouched.
// Native ECX input/EAX result use original storage; AR6ClimbableObjectVirtualTable follows base completion.
AR6ClimbableObject::AR6ClimbableObject() : AR6AbstractClimbableObj()
{
}

// R6Engine.dll @ 10008ca0 : AR6ClimbableObject::AR6ClimbableObject
// Copies the base, byte height and two point references, then three raw direction words; padding is untouched.
AR6ClimbableObject::AR6ClimbableObject(const AR6ClimbableObject& sourceObject) : AR6AbstractClimbableObj(sourceObject)
{
    // Publishes AR6ClimbableObjectVirtualTable after base copy; native EAX retains original storage.
    const AR6ClimbableObject* source = &sourceObject;
    this->m_eClimbHeight = source->m_eClimbHeight;
    this->m_climbablePoint = source->m_climbablePoint;
    this->m_insideClimbablePoint = source->m_insideClimbablePoint;
    reinterpret_cast<uint&>(this->m_vClimbDir.X) = reinterpret_cast<const uint&>(source->m_vClimbDir.X);
    reinterpret_cast<uint&>(this->m_vClimbDir.Y) = reinterpret_cast<const uint&>(source->m_vClimbDir.Y);
    reinterpret_cast<uint&>(this->m_vClimbDir.Z) = reinterpret_cast<const uint&>(source->m_vClimbDir.Z);
}

// R6Engine.dll @ 10008d00 : AR6ClimbableObject::operator=
// Copies the base, byte height and two point references, then three raw direction words; padding is untouched.
AR6ClimbableObject& __thiscall AR6ClimbableObject::operator=(const AR6ClimbableObject& sourceObject)
{
    const AR6ClimbableObject* source = &sourceObject;
    this->AR6AbstractClimbableObj::operator=(*source);
    this->m_eClimbHeight = source->m_eClimbHeight;
    this->m_climbablePoint = source->m_climbablePoint;
    this->m_insideClimbablePoint = source->m_insideClimbablePoint;
    reinterpret_cast<uint&>(this->m_vClimbDir.X) = reinterpret_cast<const uint&>(source->m_vClimbDir.X);
    reinterpret_cast<uint&>(this->m_vClimbDir.Y) = reinterpret_cast<const uint&>(source->m_vClimbDir.Y);
    reinterpret_cast<uint&>(this->m_vClimbDir.Z) = reinterpret_cast<const uint&>(source->m_vClimbDir.Z);
    return *this;
}

// R6Engine.dll @ 1000df10 : AR6ClimbableObject::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6ClimbableObject::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6ClimbableObjectConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100161b0 : AR6ClimbableObject::ShouldTrace
// Accepts low-byte flag80 directly; otherwise normalizes the base trace result to zero or one.
int __thiscall AR6ClimbableObject::ShouldTrace(AActor* other, ulong traceFlags)
{
    ulong flags = traceFlags;
    try {
        if ((flags & 0x80U) != 0) return 1; // Native tests signed AL, independently of the other flag bytes.
        return AActor::ShouldTrace(this, other, flags) != 0;
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6ClimbableObject::ShouldTrace");
        throw;
    }
}

// R6Engine.dll @ 10016201 : ClimbableShouldTraceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-18 through EBP-14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableShouldTraceCatchPointer(void)
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

// R6Engine.dll @ 10016215 : ClimbableShouldTraceCatchContext
// Reports the ShouldTrace context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableShouldTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbableObjectShouldTrace
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10016250 : AR6ClimbableObject::PostScriptDestroyed
// Destroys both linked points through one cached callback, sampling the second point after the first call.
void __thiscall AR6ClimbableObject::PostScriptDestroyed(void)
{
    using SafeDestroy = void (__thiscall*)(AActor*, AActor*);
    SafeDestroy destroy = reinterpret_cast<SafeDestroy&>(AActorSafeDestroyActorImport);
    AActor* firstPoint = this->m_climbablePoint; // Both reads precede native state0.
    try {
        destroy(this, firstPoint);
        destroy(this, this->m_insideClimbablePoint);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6ClimbableObject::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 100162a5 : ClimbablePostScriptDestroyedCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-18 through EBP-14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePostScriptDestroyedCatchPointer(void)
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

// R6Engine.dll @ 100162b9 : ClimbablePostScriptDestroyedCatchContext
// Reports the PostScriptDestroyed context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePostScriptDestroyedCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbableObjectPostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100162e0 : AR6ClimbableObject::CheckForErrors
// Reports an unspecified climb height through the current feedback context when one is available.
void __thiscall AR6ClimbableObject::CheckForErrors(void)
{
    if (this->m_eClimbHeight != 0) return;
    FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
    if (feedback == nullptr) return;
    using Report = void (__thiscall*)(FFeedbackContext*, int, AR6ClimbableObject*, const ushort*);
    (*(Report*)(*(byte**)feedback + 0x28))(feedback, 0, this,
        (const ushort*)L"Collision: specify the height of m_eClimbHeight");
}

// R6Engine.dll @ 10016310 : AR6ClimbableObject::AddMyMarker
// Spawns upper and inside markers for a scout, preserving partial results and live callback-driven field changes.
void __thiscall AR6ClimbableObject::AddMyMarker(AActor* scout)
{
    AActor* candidate = scout; // Captured before native state0; no local object cleanup actions exist.
    try {
        if (candidate == nullptr) return;
        if (candidate->UObject::IsA(AScoutPrivateStaticClassImport) == 0) return;
        UClass* markerClass = reinterpret_cast<UClass*>(UObject::StaticFindObjectChecked(UClassPrivateStaticClassImport,
            reinterpret_cast<UObject*>(0xffffffffU), reinterpret_cast<const ushort*>(L"R6ClimbablePoint"), 0));
        // CollisionHeight32 or48.
        reinterpret_cast<uint&>(this->CollisionHeight) = reinterpret_cast<byte&>(this->m_eClimbHeight) == 1 ? 0x42000000
            : 0x42400000;
        FRotator* liveRotation = &this->Rotation;
        FVector up = {0.0f, 0.0f, 1.0f};
        FVector facingStorage;
        FVector* facing = &(facingStorage = liveRotation->Vector());
        FVector unusedSide;
        // Use returned Vector pointer; retain unused cross call.
        unusedSide = *facing ^ up;
        FVector upperLocation = this->Location; // Snapshot after Cross, before default lookup.
        AActor* markerDefault = (&AR6ClimbablePoint::PrivateStaticClass)->UClass::GetDefaultActor();
        float defaultHeight = markerDefault->CollisionHeight; // Fixed class, not found markerClass.
        ULevel* level = this->XLevel;
        upperLocation.Z = (float)((float10)upperLocation.Z + this->CollisionHeight + (float10)defaultHeight);
        FRotator spawnRotation = *liveRotation; // Current rotation after Vector, Cross and default callbacks.
        using Spawn = AActor* (__thiscall*)(ULevel*, UClass*, FName, FVector, FRotator, AActor*, int, int, AActor*,
            APawn*);
        AR6ClimbablePoint* upper = static_cast<AR6ClimbablePoint*>((*(Spawn*)(*(byte**)level + 0xa8))(
            level, markerClass, FName(0), upperLocation, spawnRotation, nullptr, 0, 0, nullptr, nullptr));
        this->m_climbablePoint = upper;
        if (upper == nullptr) {
            (**(FOutputDevice***)&CoreGLogImport)->FOutputDevice::Logf(
                (const ushort*)L" There is a problem with spawning R6ClimbablePoint actors for a climbable Object...");
            return;
        }
        upper->m_climbableObj = this;
        float backwardDistance = (float)(-((float10)this->CollisionRadius + 30.0f));
        FRotator horizontalRotation = *liveRotation;
        horizontalRotation.Pitch = 0;
        FVector horizontalStorage;
        FVector* horizontal = &(horizontalStorage = horizontalRotation.Vector());
        float10 scaledZ = (float10)backwardDistance * horizontal->Z; // Z stays extended through its later addition.
        // Captured after Vector, before the Y/X products and stores.
        uint originalZ = reinterpret_cast<uint&>(this->Location.Z);
        float scaledY = (float)((float10)backwardDistance * horizontal->Y);
        float scaledX = (float)((float10)backwardDistance * horizontal->X);
        float10 discardedZ = scaledZ + this->Location.Z;
        float10 translatedY = (float10)scaledY + this->Location.Y;
        float10 translatedX = (float10)scaledX + this->Location.X;
        spawnRotation = *liveRotation;
        FVector lowerLocation;
        lowerLocation.X = (float)translatedX;
        lowerLocation.Y = (float)translatedY;
        float discardedZWord = (float)discardedZ; // Native computes/stores this sum before overwriting spawn Z.
        (void)discardedZWord;
        reinterpret_cast<uint&>(lowerLocation.Z) = originalZ;
        level = this->XLevel;
        AR6ClimbablePoint* lower = static_cast<AR6ClimbablePoint*>((*(Spawn*)(*(byte**)level + 0xa8))(
            level, markerClass, FName(0), lowerLocation, spawnRotation, nullptr, 1, 0, nullptr, nullptr));
        this->m_insideClimbablePoint = lower;
        if (lower != nullptr) {
            lower->m_climbableObj = this;
        } else {
            (**(FOutputDevice***)&CoreGLogImport)->FOutputDevice::Logf((const ushort*)
                    L" There is a problem with spawning R6ClimbablePoint actors inside a climbable Object...");
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6ClimbableObject::AddMyMarker");
        throw;
    }
}

// R6Engine.dll @ 10016590 : ClimbableAddMyMarkerCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-20 through EBP-1c.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableAddMyMarkerCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x20]
        push offset unsignedShortPointerThrowInfo
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100165a4 : ClimbableAddMyMarkerCatchContext
// Reports the AddMyMarker context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbableAddMyMarkerCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbableObjectAddMyMarker
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100432b0 : ClimbableDestructionState0Cleanup
// Tail-enters current base destruction on the saved parent-frame object.
__declspec(naked) void __cdecl ClimbableDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AR6AbstractClimbableObjDestructorImport]
    }
}

// R6Engine.dll @ 10046f30 : InitializeAR6ClimbableObjectClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6ClimbableObjectClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // Capture the imported AR6AbstractClimbableObj object address before configuration lookup.
    UClass* parentClass = AR6AbstractClimbableObjPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6ClimbableObject::PrivateStaticClass, 0, 0x3ac, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6ClimbableObject,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6ClimbableObject::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6ClimbableObjectClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048190 : DestroyAR6ClimbableObjectClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6ClimbableObjectClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6ClimbableObject::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046fc0 : PublishAR6ClimbableObjectAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6ClimbableObjectAutoClass(void)
{
    autoclassAR6ClimbableObject = &AR6ClimbableObject::PrivateStaticClass;
}

// R6Engine.dll @ 100432b9 : climbableDestructionExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl climbableDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset climbableDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043c70 : climbableShouldTraceExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl climbableShouldTraceExceptionHandler(void)
{
    __asm {
        mov eax,offset climbableShouldTraceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043c80 : climbablePostScriptDestroyedExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl climbablePostScriptDestroyedExceptionHandler(void)
{
    __asm {
        mov eax,offset climbablePostScriptDestroyedFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10008d60 : AR6ClimbableObject::DeletingDestructor
// Destroys one object or a cookie-counted array and optionally frees the captured allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6ClimbableObject::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6ClimbableObject* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6ClimbableObjectDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x3ac, count, callback);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6ClimbableObject::~AR6ClimbableObject();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x3ac);
    }
    return object;
}

// R6Engine.dll @ 10043c90 : ClimbableAddMyMarkerExceptionHandler
// Supplies the marker method's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl ClimbableAddMyMarkerExceptionHandler(void)
{
    __asm {
        mov eax,offset climbableAddMyMarkerFuncInfo
        jmp __CxxFrameHandler
    }
}
