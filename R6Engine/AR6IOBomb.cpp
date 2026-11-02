#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004e638 : AR6IOBombVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6IOBomb::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6IOBombVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1005596a : nativeTextR6IOBomb
extern const ushort nativeTextR6IOBomb[9];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl BombConstructionState0Cleanup(void);
__declspec(naked) void __cdecl BombConstructionState1Cleanup(void);
__declspec(naked) void __cdecl BombConstructionState2Cleanup(void);
__declspec(naked) void __cdecl BombConstructionState3Cleanup(void);
__declspec(naked) void __cdecl BombConstructionState4Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState0Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState1Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState2Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState3Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState4Cleanup(void);
__declspec(naked) void __cdecl BombDestructionState5Cleanup(void);

// R6Engine.dll data @ 1005864c : bombDestructionUnwindMap
// Six states destroy five completed strings in reverse order, then the IOObject base.
const NativeUnwindEntry bombDestructionUnwindMap[6] = {
    { -1, ((uint)&BombDestructionState0Cleanup) },
    { 0, ((uint)&BombDestructionState1Cleanup) },
    { 0x1, ((uint)&BombDestructionState2Cleanup) },
    { 0x2, ((uint)&BombDestructionState3Cleanup) },
    { 0x3, ((uint)&BombDestructionState4Cleanup) },
    { 0x4, ((uint)&BombDestructionState5Cleanup) }
};

// R6Engine.dll data @ 1005867c : bombDestructionFuncInfo
// Exact destructor frame metadata.
const NativeFunctionInfoPrefix bombDestructionFuncInfo = { 0x19930520, 0x6, ((uint)&bombDestructionUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 10058698 : bombConstructionUnwindMap
// Five states protect the completed base and up to four strings; no fifth-string action.
const NativeUnwindEntry bombConstructionUnwindMap[5] = {
    { -1, ((uint)&BombConstructionState0Cleanup) },
    { 0, ((uint)&BombConstructionState1Cleanup) },
    { 0x1, ((uint)&BombConstructionState2Cleanup) },
    { 0x2, ((uint)&BombConstructionState3Cleanup) },
    { 0x3, ((uint)&BombConstructionState4Cleanup) }
};

// R6Engine.dll data @ 100586c0 : bombConstructionFuncInfo
// Shared exact metadata for both bomb constructors.
const NativeFunctionInfoPrefix bombConstructionFuncInfo = { 0x19930520, 0x5, ((uint)&bombConstructionUnwindMap), 0, 0,
    0 };

// R6Engine.dll data @ 10078314 : autoclassAR6IOBomb
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6IOBomb = nullptr;

// R6Engine.dll @ 10009050 : AR6IOBomb::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6IOBomb::StaticClass(void)
{
    return &AR6IOBomb::PrivateStaticClass; // Selected object at0x10081c68.
}

// R6Engine.dll @ 10009060 : AR6IOBomb::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6IOBomb::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6IOBomb::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 100148b0 : AR6IOBomb::operator=
// Assigns the base, ordered bomb fields and five owned strings without an identity shortcut or rollback.
AR6IOBomb& __thiscall AR6IOBomb::operator=(const AR6IOBomb& sourceObject)
{
    const AR6IOBomb* source = &sourceObject;
    this->AR6IOObject::operator=(*source);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x488);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x488);
    byte beepState = source->m_eBeepState;
    uint savedFlags = *destinationFlags; // Captured between the source byte read and destination byte store.
    this->m_eBeepState = beepState; // Native byte480 leaves padding481..483 untouched.
    this->m_iEnergy = source->m_iEnergy;
    uint difference = savedFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags; // Reload after the source flag read and preceding byte/energy stores.
    copiedFlags ^= difference & 0x1U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bExploded; preserve all higher padding bits.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fTimeOfExplosion) = reinterpret_cast<const uint&>(source->m_fTimeOfExplosion);
    reinterpret_cast<uint&>(this->m_fTimeLeft) = reinterpret_cast<const uint&>(source->m_fTimeLeft);
    reinterpret_cast<uint&>(this->m_fRepTimeLeft) = reinterpret_cast<const uint&>(source->m_fRepTimeLeft);
    reinterpret_cast<uint&>(this->m_fLastLevelTime) = reinterpret_cast<const uint&>(source->m_fLastLevelTime);
    reinterpret_cast<uint&>(this->m_fDisarmBombTimeMin) = reinterpret_cast<const uint&>(source->m_fDisarmBombTimeMin);
    reinterpret_cast<uint&>(this->m_fDisarmBombTimeMax) = reinterpret_cast<const uint&>(source->m_fDisarmBombTimeMax);
    reinterpret_cast<uint&>(this->m_fExplosionRadius) = reinterpret_cast<const uint&>(source->m_fExplosionRadius);
    reinterpret_cast<uint&>(this->m_fKillBlastRadius) = reinterpret_cast<const uint&>(source->m_fKillBlastRadius);
    this->m_ArmedTexture = source->m_ArmedTexture;
    this->m_sndActivationBomb = source->m_sndActivationBomb;
    this->m_sndPlayBeepNormal = source->m_sndPlayBeepNormal;
    this->m_sndStopBeepNormal = source->m_sndStopBeepNormal;
    this->m_sndPlayBeepFast = source->m_sndPlayBeepFast;
    this->m_sndStopBeepFast = source->m_sndStopBeepFast;
    this->m_sndPlayBeepFaster = source->m_sndPlayBeepFaster;
    this->m_sndStopBeepFaster = source->m_sndStopBeepFaster;
    this->m_sndExplosion = source->m_sndExplosion;
    this->m_sndEarthQuake = source->m_sndEarthQuake;
    this->m_pEmmiter = source->m_pEmmiter;
    this->m_pExplosionLight = source->m_pExplosionLight;
    reinterpret_cast<uint&>(this->m_vOffset.X) = reinterpret_cast<const uint&>(source->m_vOffset.X);
    reinterpret_cast<uint&>(this->m_vOffset.Y) = reinterpret_cast<const uint&>(source->m_vOffset.Y);
    reinterpret_cast<uint&>(this->m_vOffset.Z) = reinterpret_cast<const uint&>(source->m_vOffset.Z);
    reinterpret_cast<FStringNoInit*>(&this->m_szIdentityID)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szIdentityID));
    reinterpret_cast<FStringNoInit*>(&this->m_szIdentity)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szIdentity));
    reinterpret_cast<FStringNoInit*>(&this->m_szMsgArmedID)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szMsgArmedID));
    reinterpret_cast<FStringNoInit*>(&this->m_szMsgDisarmedID)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szMsgDisarmedID));
    reinterpret_cast<FStringNoInit*>(&this->m_szMissionObjLocalization)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szMissionObjLocalization));
    return *this;
}

// R6Engine.dll @ 100159c0 : AR6IOBomb::~AR6IOBomb
// Runs conditional cleanup before automatic reverse string and AR6IOObject base destruction.
AR6IOBomb::~AR6IOBomb()
{
    // Compiler installs4e638 and arms state5; strings518/50c/500/4f4/4e8 and base form the cleanup chain.
    UObject::ConditionalDestroy();
    // Implicit member calls use current49038 under states4..0; normal base157e0 runs under state-1.
}

// R6Engine.dll @ 10015a70 : AR6IOBomb::AR6IOBomb()
// Constructs through AActor, then constructs five no-init strings under staged IOObject-base cleanup.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6IOBomb* __thiscall AR6IOBomb::AR6IOBomb(AR6IOBomb* this)
{
    using ConstructActor = AActor* (__thiscall*)(AActor*);
    // State-1; this body bypasses the IOObject default wrapper.
    reinterpret_cast<ConstructActor&>(AActorDefaultConstructorImport)(this);
    struct PendingStrings {
        AR6IOBomb* object;
        uint completed;
        bool active;
        // Inferred view of58698/586c0: destroy completed strings, then the completed IOObject base.
        ~PendingStrings() noexcept(false) {
            if (!active) return;
            while (completed != 0) {
                --completed;
                FStringNoInit::~FStringNoInit((FStringNoInit*)((byte*)object + 0x4e8 + completed * 12U));
            }
            object->AR6IOObject::~AR6IOObject();
        }
    } cleanup{this, 0, true};
    *(uint*)this = ((uint)&AR6IOBombVirtualTable); // Native state0 is armed before this table store.
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szIdentityID);
    cleanup.completed = 1;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szIdentity);
    cleanup.completed = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMsgArmedID);
    cleanup.completed = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMsgDisarmedID);
    cleanup.completed = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMissionObjLocalization);
    cleanup.active = false; // Transfer ownership; native adds no final completed-string state5/write.
    return this;
}

// R6Engine.dll @ 10015b10 : AR6IOBomb::AR6IOBomb
// Copies the completed base and raw bomb state, then constructs five owned strings with delayed cleanup protection.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6IOBomb* __thiscall AR6IOBomb::AR6IOBomb(AR6IOBomb* this, const AR6IOBomb* source)
{
    AR6IOObject::AR6IOObject(this, source);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x488);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x488);
    uint savedFlags = *destinationFlags; // Native snapshot precedes the derived table and source byte read.
    *(uint*)this = ((uint)&AR6IOBombVirtualTable);
    byte beepState = source->m_eBeepState;
    this->m_eBeepState = beepState; // Native byte480 leaves padding481..483 untouched.
    this->m_iEnergy = source->m_iEnergy;
    uint difference = savedFlags ^ *sourceFlags;
    uint copiedFlags = *destinationFlags; // Reload after the source flag read and preceding byte/energy stores.
    copiedFlags ^= difference & 0x1U; // bShowLog.
    *destinationFlags = copiedFlags;
    copiedFlags ^= (*sourceFlags ^ copiedFlags) & 0x2U; // m_bExploded; preserve all higher padding bits.
    *destinationFlags = copiedFlags;
    reinterpret_cast<uint&>(this->m_fTimeOfExplosion) = reinterpret_cast<const uint&>(source->m_fTimeOfExplosion);
    reinterpret_cast<uint&>(this->m_fTimeLeft) = reinterpret_cast<const uint&>(source->m_fTimeLeft);
    reinterpret_cast<uint&>(this->m_fRepTimeLeft) = reinterpret_cast<const uint&>(source->m_fRepTimeLeft);
    reinterpret_cast<uint&>(this->m_fLastLevelTime) = reinterpret_cast<const uint&>(source->m_fLastLevelTime);
    reinterpret_cast<uint&>(this->m_fDisarmBombTimeMin) = reinterpret_cast<const uint&>(source->m_fDisarmBombTimeMin);
    reinterpret_cast<uint&>(this->m_fDisarmBombTimeMax) = reinterpret_cast<const uint&>(source->m_fDisarmBombTimeMax);
    reinterpret_cast<uint&>(this->m_fExplosionRadius) = reinterpret_cast<const uint&>(source->m_fExplosionRadius);
    reinterpret_cast<uint&>(this->m_fKillBlastRadius) = reinterpret_cast<const uint&>(source->m_fKillBlastRadius);
    this->m_ArmedTexture = source->m_ArmedTexture;
    this->m_sndActivationBomb = source->m_sndActivationBomb;
    this->m_sndPlayBeepNormal = source->m_sndPlayBeepNormal;
    this->m_sndStopBeepNormal = source->m_sndStopBeepNormal;
    this->m_sndPlayBeepFast = source->m_sndPlayBeepFast;
    this->m_sndStopBeepFast = source->m_sndStopBeepFast;
    this->m_sndPlayBeepFaster = source->m_sndPlayBeepFaster;
    this->m_sndStopBeepFaster = source->m_sndStopBeepFaster;
    this->m_sndExplosion = source->m_sndExplosion;
    this->m_sndEarthQuake = source->m_sndEarthQuake;
    this->m_pEmmiter = source->m_pEmmiter;
    this->m_pExplosionLight = source->m_pExplosionLight;
    reinterpret_cast<uint&>(this->m_vOffset.X) = reinterpret_cast<const uint&>(source->m_vOffset.X);
    reinterpret_cast<uint&>(this->m_vOffset.Y) = reinterpret_cast<const uint&>(source->m_vOffset.Y);
    reinterpret_cast<uint&>(this->m_vOffset.Z) = reinterpret_cast<const uint&>(source->m_vOffset.Z);
    struct PendingStrings {
        AR6IOBomb* object;
        uint completed;
        bool active;
        // Inferred view of58698/586c0: destroy completed strings, then the completed IOObject base.
        ~PendingStrings() noexcept(false) {
            if (!active) return;
            while (completed != 0) {
                --completed;
                FStringNoInit::~FStringNoInit((FStringNoInit*)((byte*)object + 0x4e8 + completed * 12U));
            }
            object->AR6IOObject::~AR6IOObject();
        }
    } cleanup{this, 0, true};
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szIdentityID, (const FStringNoInit*)&source->m_szIdentityID);
    cleanup.completed = 1;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szIdentity, (const FStringNoInit*)&source->m_szIdentity);
    cleanup.completed = 2;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMsgArmedID, (const FStringNoInit*)&source->m_szMsgArmedID);
    cleanup.completed = 3;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMsgDisarmedID,
        (const FStringNoInit*)&source->m_szMsgDisarmedID);
    cleanup.completed = 4;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_szMissionObjLocalization,
        (const FStringNoInit*)&source->m_szMissionObjLocalization);
    cleanup.active = false; // Transfer ownership; native adds no final completed-string state5/write.
    return this;
}

// R6Engine.dll @ 10016170 : AR6IOBomb::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6IOBomb::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6IOBombConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10043ba0 : BombDestructionState0Cleanup
// Tail-enters IOObject base destruction on the saved object.
__declspec(naked) void __cdecl BombDestructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6IOObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043ba8 : BombDestructionState1Cleanup
// Tail-enters current string destruction on saved object+4e8.
__declspec(naked) void __cdecl BombDestructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4e8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043bb7 : BombDestructionState2Cleanup
// Tail-enters current string destruction on saved object+4f4.
__declspec(naked) void __cdecl BombDestructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4f4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043bc6 : BombDestructionState3Cleanup
// Tail-enters current string destruction on saved object+500.
__declspec(naked) void __cdecl BombDestructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x500
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043bd5 : BombDestructionState4Cleanup
// Tail-enters current string destruction on saved object+50c.
__declspec(naked) void __cdecl BombDestructionState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x50c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043be4 : BombDestructionState5Cleanup
// Tail-enters current string destruction on saved object+518.
__declspec(naked) void __cdecl BombDestructionState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x518
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043c00 : BombConstructionState0Cleanup
// Tail-enters IOObject base destruction on the saved object.
__declspec(naked) void __cdecl BombConstructionState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6IOObjectDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043c08 : BombConstructionState1Cleanup
// Tail-enters current string destruction on saved object+4e8.
__declspec(naked) void __cdecl BombConstructionState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4e8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043c17 : BombConstructionState2Cleanup
// Tail-enters current string destruction on saved object+4f4.
__declspec(naked) void __cdecl BombConstructionState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x4f4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043c26 : BombConstructionState3Cleanup
// Tail-enters current string destruction on saved object+500.
__declspec(naked) void __cdecl BombConstructionState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x500
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043c35 : BombConstructionState4Cleanup
// Tail-enters current string destruction on saved object+50c.
__declspec(naked) void __cdecl BombConstructionState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x50c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10048140 : DestroyAR6IOBombClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6IOBombClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6IOBomb::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046c30 : InitializeAR6IOBombClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6IOBombClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6IOBomb::PrivateStaticClass, 0, 0x524, 0,
        &AR6IOObject::PrivateStaticClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6IOBomb, (const ushort*)&enginePackageName,
            configName,
        0x04084004, &AR6IOBomb::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6IOBombClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10046cb0 : PublishAR6IOBombAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6IOBombAutoClass(void)
{
    autoclassAR6IOBomb = &AR6IOBomb::PrivateStaticClass;
}

// R6Engine.dll @ 10043bf3 : bombDestructionExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl bombDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset bombDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043c44 : bombConstructionExceptionHandler
// Supplies the exact FuncInfo without changing the inherited dispatcher frame.
__declspec(naked) void __cdecl bombConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset bombConstructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10015d30 : AR6IOBomb::DeletingDestructor
// Destroys one bomb or a cookie-counted array and optionally frees the captured allocation.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6IOBomb::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags);
    AR6IOBomb* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6IOBombDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x524, count, callback);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6IOBomb::~AR6IOBomb();
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x524);
    }
    return object;
}
