#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
int __cdecl CastToAPlayerController(int object);
float10 __cdecl SquaredDistanceBetweenVectors(const float *firstVector, const float *secondVector);
int __cdecl CastToAR6SAHeartBeatJammer(int object);
__declspec(naked) void __cdecl DestroyAR6FalseHeartBeatClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004ead0 : AR6FalseHeartBeatVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6FalseHeartBeat::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6FalseHeartBeatVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 100504ac : nativeTextAR6FalseHeartBeatIsBlockedBy
extern const ushort nativeTextAR6FalseHeartBeatIsBlockedBy[31];

// R6Engine.dll data @ 10050530 : nativeTextAR6FalseHeartBeatIsRelevantToPawn
extern const ushort nativeTextAR6FalseHeartBeatIsRelevantToPawn[36];

// R6Engine.dll data @ 10050580 : nativeTextAR6FalseHeartBeatIsRelevantToPawnHeartBeat
extern const ushort nativeTextAR6FalseHeartBeatIsRelevantToPawnHeartBeat[45];

// R6Engine.dll data @ 100504ec : nativeTextAR6FalseHeartBeatShouldTrace
extern const ushort nativeTextAR6FalseHeartBeatShouldTrace[31];

// R6Engine.dll data @ 100505fe : nativeTextR6FalseHeartBeat
extern const ushort nativeTextR6FalseHeartBeat[17];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsBlockedByCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsBlockedByCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnHeartBeatCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnHeartBeatCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBShouldTraceCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBShouldTraceCatchPointer(void);

// R6Engine.dll data @ 10059e94 : falseHBIsBlockedByUnwindMap
// Two terminal null-action states; no local object cleanup.
const NativeUnwindEntry falseHBIsBlockedByUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059ea4 : falseHBIsBlockedByCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry falseHBIsBlockedByCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&FalseHBIsBlockedByCatchPointer) },
    { 0, 0, 0, ((uint)&FalseHBIsBlockedByCatchContext) }
};

// R6Engine.dll data @ 10059ec4 : falseHBIsBlockedByTryMap
// State0 body and state1 catch region use the exact two-handler map.
const NativeTryBlock falseHBIsBlockedByTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&falseHBIsBlockedByCatchMap) }
};

// R6Engine.dll data @ 10059ed8 : falseHBIsBlockedByFuncInfo
// Exact selected C++ exception metadata for this method.
const NativeFunctionInfoPrefix falseHBIsBlockedByFuncInfo = { 0x19930520, 0x2, ((uint)&falseHBIsBlockedByUnwindMap),
    0x1, ((uint)&falseHBIsBlockedByTryMap), 0 };

// R6Engine.dll data @ 10059ef4 : falseHBShouldTraceUnwindMap
// Two terminal null-action states; no local object cleanup.
const NativeUnwindEntry falseHBShouldTraceUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059f04 : falseHBShouldTraceCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry falseHBShouldTraceCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&FalseHBShouldTraceCatchPointer) },
    { 0, 0, 0, ((uint)&FalseHBShouldTraceCatchContext) }
};

// R6Engine.dll data @ 10059f24 : falseHBShouldTraceTryMap
// State0 body and state1 catch region use the exact two-handler map.
const NativeTryBlock falseHBShouldTraceTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&falseHBShouldTraceCatchMap) }
};

// R6Engine.dll data @ 10059f38 : falseHBShouldTraceFuncInfo
// Exact selected C++ exception metadata for this method.
const NativeFunctionInfoPrefix falseHBShouldTraceFuncInfo = { 0x19930520, 0x2, ((uint)&falseHBShouldTraceUnwindMap),
    0x1, ((uint)&falseHBShouldTraceTryMap), 0 };

// R6Engine.dll data @ 10059f54 : falseHBIsRelevantToPawnUnwindMap
// Two terminal null-action states; no local object cleanup.
const NativeUnwindEntry falseHBIsRelevantToPawnUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059f64 : falseHBIsRelevantToPawnCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry falseHBIsRelevantToPawnCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&FalseHBIsRelevantToPawnCatchPointer) },
    { 0, 0, 0, ((uint)&FalseHBIsRelevantToPawnCatchContext) }
};

// R6Engine.dll data @ 10059f84 : falseHBIsRelevantToPawnTryMap
// State0 body and state1 catch region use the exact two-handler map.
const NativeTryBlock falseHBIsRelevantToPawnTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&falseHBIsRelevantToPawnCatchMap) }
};

// R6Engine.dll data @ 10059f98 : falseHBIsRelevantToPawnFuncInfo
// Exact selected C++ exception metadata for this method.
const NativeFunctionInfoPrefix falseHBIsRelevantToPawnFuncInfo = { 0x19930520, 0x2,
    ((uint)&falseHBIsRelevantToPawnUnwindMap), 0x1, ((uint)&falseHBIsRelevantToPawnTryMap), 0 };

// R6Engine.dll data @ 10059fb4 : falseHBIsRelevantToPawnHeartBeatUnwindMap
// Two terminal null-action states; no local object cleanup.
const NativeUnwindEntry falseHBIsRelevantToPawnHeartBeatUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059fc4 : falseHBIsRelevantToPawnHeartBeatCatchMap
// Typed unsigned-short pointer catch followed by context catch-all.
const NativeCatchEntry falseHBIsRelevantToPawnHeartBeatCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -28, ((uint)&FalseHBIsRelevantToPawnHeartBeatCatchPointer) },
    { 0, 0, 0, ((uint)&FalseHBIsRelevantToPawnHeartBeatCatchContext) }
};

// R6Engine.dll data @ 10059fe4 : falseHBIsRelevantToPawnHeartBeatTryMap
// State0 body and state1 catch region use the exact two-handler map.
const NativeTryBlock falseHBIsRelevantToPawnHeartBeatTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&falseHBIsRelevantToPawnHeartBeatCatchMap) }
};

// R6Engine.dll data @ 10059ff8 : falseHBIsRelevantToPawnHeartBeatFuncInfo
// Exact selected C++ exception metadata for this method.
const NativeFunctionInfoPrefix falseHBIsRelevantToPawnHeartBeatFuncInfo = {
    0x19930520, 0x2, ((uint)&falseHBIsRelevantToPawnHeartBeatUnwindMap), 0x1,
        ((uint)&falseHBIsRelevantToPawnHeartBeatTryMap), 0
};

// R6Engine.dll data @ 100754d8 : autoclassAR6FalseHeartBeat
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6FalseHeartBeat = nullptr;

// R6Engine.dll @ 10009110 : AR6FalseHeartBeat::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6FalseHeartBeat::StaticClass(void)
{
    return &AR6FalseHeartBeat::PrivateStaticClass; // Selected object at0x10074ac8.
}

// R6Engine.dll @ 10009120 : AR6FalseHeartBeat::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6FalseHeartBeat::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6FalseHeartBeat::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10014b00 : AR6FalseHeartBeat::operator=
// Assigns the generic heartbeat base and copies the circle, timing and puck-owner fields.
AR6FalseHeartBeat& __thiscall AR6FalseHeartBeat::operator=(const AR6FalseHeartBeat& sourceObject)
{
    const AR6FalseHeartBeat* source = &sourceObject;
    this->AR6GenericHB::operator=(*source);
    this->m_iNoCircleBeat = source->m_iNoCircleBeat;
    reinterpret_cast<uint&>(this->m_fHeartBeatTime[0]) = reinterpret_cast<const uint&>(source->m_fHeartBeatTime[0]);
    reinterpret_cast<uint&>(this->m_fHeartBeatTime[1]) = reinterpret_cast<const uint&>(source->m_fHeartBeatTime[1]);
    reinterpret_cast<uint&>(this->m_fHeartBeatFrequency) = reinterpret_cast<const uint&>(source->m_fHeartBeatFrequency);
    this->m_HeartBeatPuckOwner = source->m_HeartBeatPuckOwner;
    return *this;
}

// R6Engine.dll @ 10015fe0 : AR6FalseHeartBeat::~AR6FalseHeartBeat
// Runs conditional cleanup before automatic AR6GenericHB base destruction.
AR6FalseHeartBeat::~AR6FalseHeartBeat()
{
    // Compiler installs vtable1004ead0; native state0 protects the completed base during this call.
    UObject::ConditionalDestroy();
    // Implicit base destruction enters state-1 normally; exact shared cleanup is retained in module support.
}

// R6Engine.dll @ 10016030 : AR6FalseHeartBeat::AR6FalseHeartBeat()
// Constructs through AActor, installs this class's table and leaves derived fields untouched.
// The emitted call targets AActor; the intermediate C++ initializer structure remains unresolved.
AR6FalseHeartBeat* __thiscall AR6FalseHeartBeat::AR6FalseHeartBeat(AR6FalseHeartBeat* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    *(uint*)this = ((uint)&AR6FalseHeartBeatVirtualTable);
    return this; // Preserve original storage independently of the imported constructor's EAX.
}

// R6Engine.dll @ 10016050 : AR6FalseHeartBeat::AR6FalseHeartBeat
// Copies the completed base and this class's scalar/reference state in native order.
AR6FalseHeartBeat::AR6FalseHeartBeat(const AR6FalseHeartBeat& sourceObject) : AR6GenericHB(sourceObject)
{
    // Publishes AR6FalseHeartBeatVirtualTable after base copy; native EAX retains original storage.
    const AR6FalseHeartBeat* source = &sourceObject;
    this->m_iNoCircleBeat = source->m_iNoCircleBeat;
    reinterpret_cast<uint&>(this->m_fHeartBeatTime[0]) = reinterpret_cast<const uint&>(source->m_fHeartBeatTime[0]);
    reinterpret_cast<uint&>(this->m_fHeartBeatTime[1]) = reinterpret_cast<const uint&>(source->m_fHeartBeatTime[1]);
    reinterpret_cast<uint&>(this->m_fHeartBeatFrequency) = reinterpret_cast<const uint&>(source->m_fHeartBeatFrequency);
    this->m_HeartBeatPuckOwner = source->m_HeartBeatPuckOwner;
}

// R6Engine.dll @ 100160b0 : AR6FalseHeartBeat::DeletingDestructor
// Destroys one AR6FalseHeartBeat object or a cookie-counted array and optionally frees the original allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6FalseHeartBeat::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6FalseHeartBeat* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6FalseHeartBeatDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x47c, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Current allocator is sampled after array destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6FalseHeartBeat::~AR6FalseHeartBeat();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x47c);
    }
    return object;
}

// R6Engine.dll @ 100161a0 : AR6FalseHeartBeat::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6FalseHeartBeat::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6FalseHeartBeatConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001ba90 : AR6FalseHeartBeat::IsBlockedBy
// Excludes the puck owner's actors, then applies blocking flags and the level-info base query.
int __thiscall AR6FalseHeartBeat::IsBlockedBy(const AActor* other) const
{
    try {
        if (other != nullptr && other->Owner == this->m_HeartBeatPuckOwner)
            return 0;
        ALevelInfo* levelInfo = this->XLevel->ULevel::GetLevelInfo();
        // Native still reads this for null other.
        uint actorFlags = *reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(other) + 0xa8);
        if ((actorFlags & 0x2000U) != 0) // bBlockActors.
            return 1;
        if (other != levelInfo)
            return 0;
        return this->AActor::IsBlockedBy(other);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6FalseHeartBeat::IsBlockedBy");
        throw;
    }
}

// R6Engine.dll @ 1001bb38 : FalseHBIsBlockedByCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsBlockedByCatchPointer(void)
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

// R6Engine.dll @ 1001bb4c : FalseHBIsBlockedByCatchContext
// Reports the IsBlockedBy context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsBlockedByCatchContext(void)
{
    __asm {
        push offset nativeTextAR6FalseHeartBeatIsBlockedBy
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044210 : FalseHBIsBlockedByExceptionHandler
// Supplies this method's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl FalseHBIsBlockedByExceptionHandler(void)
{
    __asm {
        mov eax,offset falseHBIsBlockedByFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001bb70 : AR6FalseHeartBeat::ShouldTrace
// Suppresses tracing for actors owned by the puck owner and delegates all other cases.
int __thiscall AR6FalseHeartBeat::ShouldTrace(AActor* other, ulong traceFlags)
{
    try {
        if (other != nullptr && other->Owner == this->m_HeartBeatPuckOwner)
            return 0;
        return this->AR6InteractiveObject::ShouldTrace(other, traceFlags);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6FalseHeartBeat::ShouldTrace");
        throw;
    }
}

// R6Engine.dll @ 1001bbdf : FalseHBShouldTraceCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBShouldTraceCatchPointer(void)
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

// R6Engine.dll @ 1001bbf3 : FalseHBShouldTraceCatchContext
// Reports the ShouldTrace context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBShouldTraceCatchContext(void)
{
    __asm {
        push offset nativeTextAR6FalseHeartBeatShouldTrace
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044220 : FalseHBShouldTraceExceptionHandler
// Supplies this method's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl FalseHBShouldTraceExceptionHandler(void)
{
    __asm {
        mov eax,offset falseHBShouldTraceFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001bca0 : AR6FalseHeartBeat::IsRelevantToPawn
// Requires an intact puck, an enabled weapon query and squared range strictly below 2250000.
int __thiscall AR6FalseHeartBeat::IsRelevantToPawn(APawn* viewer)
{
    try {
        if ((reinterpret_cast<const byte*>(this)[0x3ac] & 0x40U) != 0) // m_bBroken.
            return 0;
        AR6EngineWeapon* weapon = viewer->EngineWeapon; // No native null-viewer guard on this path.
        if (weapon == nullptr)
            return 0;
        using WeaponQuery = int (__thiscall*)(AR6EngineWeapon*); // Exact original slot name unresolved.
        if ((*(WeaponQuery*)(*(byte**)weapon + 0x184))(weapon) == 0)
            return 0;
        float10 dx = (float10)this->Location.X - (float10)viewer->Location.X;
        float10 dy = (float10)this->Location.Y - (float10)viewer->Location.Y;
        float10 dz = (float10)this->Location.Z - (float10)viewer->Location.Z;
        float10 rangeSquared = (dz * dz + dy * dy) + dx * dx; // Native unspilled x87 order.
        return rangeSquared < (float10)nativeFloat2Point25EPlus06 ? 1 : 0; // Unordered also rejects.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6FalseHeartBeat::IsRelevantToPawn");
        throw;
    }
}

// R6Engine.dll @ 1001bd59 : FalseHBIsRelevantToPawnCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnCatchPointer(void)
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

// R6Engine.dll @ 1001bd6d : FalseHBIsRelevantToPawnCatchContext
// Reports the IsRelevantToPawn context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnCatchContext(void)
{
    __asm {
        push offset nativeTextAR6FalseHeartBeatIsRelevantToPawn
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044230 : FalseHBIsRelevantToPawnExceptionHandler
// Supplies this method's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl FalseHBIsRelevantToPawnExceptionHandler(void)
{
    __asm {
        mov eax,offset falseHBIsRelevantToPawnFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1001bda0 : AR6FalseHeartBeat::IsRelevantToPawnHeartBeat
// Tests a player sensor viewer, then rejects nearby enabled pawn or placed heartbeat jammers.
int __thiscall AR6FalseHeartBeat::IsRelevantToPawnHeartBeat(APawn* viewer)
{
    try {
        if ((reinterpret_cast<const byte*>(this)[0x3ac] & 0x40U) != 0 || viewer == nullptr)
            return 0;
        AController* controller = viewer->Controller;
        if (controller == nullptr || CastToAPlayerController((int)controller) == 0)
            return 0;
        AR6EngineWeapon* weapon = viewer->EngineWeapon;
        if (weapon == nullptr)
            return 0;
        using WeaponQuery = int (__thiscall*)(AR6EngineWeapon*); // Exact original slot name unresolved.
        if ((*(WeaponQuery*)(*(byte**)weapon + 0x184))(weapon) == 0)
            return 0;
        float10 rangeSquared = SquaredDistanceBetweenVectors(&viewer->Location.X, &this->Location.X);
        if (!(rangeSquared < (float10)nativeFloat2Point25EPlus06)) // Unordered rejects as well as >=.
            return 0;
        int index = 0;
        for (;;) {
            ULevel* level = this->XLevel; // Live Actors header sampled on each iteration.
            const NativeArrayHeader32* actors =
                reinterpret_cast<const NativeArrayHeader32*>(reinterpret_cast<const byte*>(level) + 0x30);
            if (index >= actors->count)
                return 1;
            AActor* actor = reinterpret_cast<AActor**>(actors->dataAddress)[index];
            if (actor != nullptr) {
                APawn* pawn = actor->GetPlayerPawn(); // May return another pawn.
                if (pawn != nullptr) {
                    if (pawn->APawn::IsAlive() != 0 &&
                        (reinterpret_cast<const byte*>(pawn)[0x3e8] & 1U) != 0) { // m_bHBJammerOn.
                        rangeSquared = SquaredDistanceBetweenVectors(&this->Location.X, &pawn->Location.X);
                        if (rangeSquared < (float10)nativeFloat2Point25EPlus06)
                            return 0;
                    }
                } else {
                    AR6SAHeartBeatJammer* jammer =
                        reinterpret_cast<AR6SAHeartBeatJammer*>(CastToAR6SAHeartBeatJammer((int)actor));
                    if (jammer != nullptr && (reinterpret_cast<const byte*>(jammer)[0x3ac] & 0x40U) == 0) {
                        rangeSquared = SquaredDistanceBetweenVectors(&this->Location.X, &jammer->Location.X);
                        if (rangeSquared < (float10)nativeFloat1EPlus06) // Strictly below1000000.
                            return 0;
                    }
                }
            }
            index = (int)((uint)index + 1U); // Preserve the native wrapping signed index.
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6FalseHeartBeat::IsRelevantToPawnHeartBeat");
        throw;
    }
}

// R6Engine.dll @ 1001bf26 : FalseHBIsRelevantToPawnHeartBeatCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x1c through EBP-0x18.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnHeartBeatCatchPointer(void)
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

// R6Engine.dll @ 1001bf3a : FalseHBIsRelevantToPawnHeartBeatCatchContext
// Reports the IsRelevantToPawnHeartBeat context and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl FalseHBIsRelevantToPawnHeartBeatCatchContext(void)
{
    __asm {
        push offset nativeTextAR6FalseHeartBeatIsRelevantToPawnHeartBeat
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044240 : FalseHBIsRelevantToPawnHeartBeatExceptionHandler
// Supplies this method's exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl FalseHBIsRelevantToPawnHeartBeatExceptionHandler(void)
{
    __asm {
        mov eax,offset falseHBIsRelevantToPawnHeartBeatFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100456d0 : InitializeAR6FalseHeartBeatClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6FalseHeartBeatClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // IAT object address, not a field loaded from the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6FalseHeartBeat::PrivateStaticClass, 0, 0x47c, 0,
        &AR6GenericHB::PrivateStaticClass, withinClass, *(FGuid*)guidWords,
            nativeTextR6FalseHeartBeat,
        (const ushort*)&enginePackageName, configName, 0x04084004,
        &AR6FalseHeartBeat::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6FalseHeartBeatClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10045750 : PublishAR6FalseHeartBeatAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6FalseHeartBeatAutoClass(void)
{
    autoclassAR6FalseHeartBeat = &AR6FalseHeartBeat::PrivateStaticClass;
}

// R6Engine.dll @ 10047f00 : DestroyAR6FalseHeartBeatClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6FalseHeartBeatClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6FalseHeartBeat::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}
