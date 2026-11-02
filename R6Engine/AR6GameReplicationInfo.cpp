#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_exception_records.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6GameReplicationInfoClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 10049a20 : AR6GameReplicationInfoVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6GameReplicationInfo::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6GameReplicationInfoVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055a46 : nativeTextR6GameReplicationInfo
extern const ushort nativeTextR6GameReplicationInfo[22];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void GameReplicationCopyExceptionHandler(void);
__declspec(naked) void GameReplicationCopyState0Cleanup(void);
__declspec(naked) void GameReplicationCopyState1Cleanup(void);
__declspec(naked) void GameReplicationCtorExceptionHandler(void);
__declspec(naked) void GameReplicationCtorState0Cleanup(void);
__declspec(naked) void GameReplicationCtorState10Cleanup(void);
__declspec(naked) void GameReplicationCtorState11Cleanup(void);
__declspec(naked) void GameReplicationCtorState12Cleanup(void);
__declspec(naked) void GameReplicationCtorState1Cleanup(void);
__declspec(naked) void GameReplicationCtorState2Cleanup(void);
__declspec(naked) void GameReplicationCtorState3Cleanup(void);
__declspec(naked) void GameReplicationCtorState4Cleanup(void);
__declspec(naked) void GameReplicationCtorState5Cleanup(void);
__declspec(naked) void GameReplicationCtorState6Cleanup(void);
__declspec(naked) void GameReplicationCtorState7Cleanup(void);
__declspec(naked) void GameReplicationCtorState8Cleanup(void);
__declspec(naked) void GameReplicationCtorState9Cleanup(void);
__declspec(naked) void GameReplicationDtorExceptionHandler(void);
__declspec(naked) void GameReplicationDtorState0Cleanup(void);
__declspec(naked) void GameReplicationDtorState10Cleanup(void);
__declspec(naked) void GameReplicationDtorState11Cleanup(void);
__declspec(naked) void GameReplicationDtorState12Cleanup(void);
__declspec(naked) void GameReplicationDtorState13Cleanup(void);
__declspec(naked) void GameReplicationDtorState1Cleanup(void);
__declspec(naked) void GameReplicationDtorState2Cleanup(void);
__declspec(naked) void GameReplicationDtorState3Cleanup(void);
__declspec(naked) void GameReplicationDtorState4Cleanup(void);
__declspec(naked) void GameReplicationDtorState5Cleanup(void);
__declspec(naked) void GameReplicationDtorState6Cleanup(void);
__declspec(naked) void GameReplicationDtorState7Cleanup(void);
__declspec(naked) void GameReplicationDtorState8Cleanup(void);
__declspec(naked) void GameReplicationDtorState9Cleanup(void);

// R6Engine.dll data @ 100568e8 : gameReplicationDtorUnwind
// Destruction states retain the not-yet-destroyed prefix of members and the base.
const NativeUnwindEntry gameReplicationDtorUnwind[14] = {
    { -1, ((uint)&GameReplicationDtorState0Cleanup) },
    { 0, ((uint)&GameReplicationDtorState1Cleanup) },
    { 0x1, ((uint)&GameReplicationDtorState2Cleanup) },
    { 0x2, ((uint)&GameReplicationDtorState3Cleanup) },
    { 0x3, ((uint)&GameReplicationDtorState4Cleanup) },
    { 0x4, ((uint)&GameReplicationDtorState5Cleanup) },
    { 0x5, ((uint)&GameReplicationDtorState6Cleanup) },
    { 0x6, ((uint)&GameReplicationDtorState7Cleanup) },
    { 0x7, ((uint)&GameReplicationDtorState8Cleanup) },
    { 0x8, ((uint)&GameReplicationDtorState9Cleanup) },
    { 0x9, ((uint)&GameReplicationDtorState10Cleanup) },
    { 0xa, ((uint)&GameReplicationDtorState11Cleanup) },
    { 0xb, ((uint)&GameReplicationDtorState12Cleanup) },
    { 0xc, ((uint)&GameReplicationDtorState13Cleanup) }
};

// R6Engine.dll data @ 10056958 : gameReplicationDtorInfo
// Destruction has fourteen cleanup states and no catches.
const NativeFunctionInfoPrefix gameReplicationDtorInfo = { 0x19930520, 0xe, ((uint)&gameReplicationDtorUnwind), 0, 0,
    0 };

// R6Engine.dll data @ 100569f8 : gameReplicationCopyUnwind
// Copy failure cleans the current-game string and base; completed fixed arrays have no entries.
const NativeUnwindEntry gameReplicationCopyUnwind[2] = {
    { -1, ((uint)&GameReplicationCopyState0Cleanup) },
    { 0, ((uint)&GameReplicationCopyState1Cleanup) }
};

// R6Engine.dll data @ 10056a08 : gameReplicationCopyInfo
// Copy construction has two cleanup states and no catches.
const NativeFunctionInfoPrefix gameReplicationCopyInfo = { 0x19930520, 0x2, ((uint)&gameReplicationCopyUnwind), 0, 0,
    0 };

// R6Engine.dll data @ 10056974 : gameReplicationCtorUnwind
// Each completed member transitions to the preceding member or base cleanup.
const NativeUnwindEntry gameReplicationCtorUnwind[13] = {
    { -1, ((uint)&GameReplicationCtorState0Cleanup) },
    { 0, ((uint)&GameReplicationCtorState1Cleanup) },
    { 0x1, ((uint)&GameReplicationCtorState2Cleanup) },
    { 0x2, ((uint)&GameReplicationCtorState3Cleanup) },
    { 0x3, ((uint)&GameReplicationCtorState4Cleanup) },
    { 0x4, ((uint)&GameReplicationCtorState5Cleanup) },
    { 0x5, ((uint)&GameReplicationCtorState6Cleanup) },
    { 0x6, ((uint)&GameReplicationCtorState7Cleanup) },
    { 0x7, ((uint)&GameReplicationCtorState8Cleanup) },
    { 0x8, ((uint)&GameReplicationCtorState9Cleanup) },
    { 0x9, ((uint)&GameReplicationCtorState10Cleanup) },
    { 0xa, ((uint)&GameReplicationCtorState11Cleanup) },
    { 0xb, ((uint)&GameReplicationCtorState12Cleanup) }
};

// R6Engine.dll data @ 100569dc : gameReplicationCtorInfo
// Default construction has thirteen cleanup states and no catches.
const NativeFunctionInfoPrefix gameReplicationCtorInfo = { 0x19930520, 0xd, ((uint)&gameReplicationCtorUnwind), 0, 0,
    0 };

// R6Engine.dll data @ 100802e8 : autoclassAR6GameReplicationInfo
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6GameReplicationInfo = nullptr;

// R6Engine.dll @ 100017f0 : AR6GameReplicationInfo::eventGetRoundTime
// Dispatches GetRoundTime with a zero-initialized float result and returns the script's updated value.
float __thiscall AR6GameReplicationInfo::eventGetRoundTime(void)
{
    using EventDispatcher = void (__thiscall *)(UObject*, UFunction*, void*, void*);
    // Native caches the vtable before lookup.
    NativeEventVtablePrefix* cachedVtable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    float returnValue = 0.0f;
    UFunction* function = UObject::FindFunctionChecked(this, R6ENGINE_GetRoundTime, 0);
    // ProcessEvent at vtable+0x10.
    reinterpret_cast<EventDispatcher&>(cachedVtable->processEventAddress)(this, function, &returnValue, nullptr);
    return returnValue; // Native FLD returns the post-dispatch slot in ST(0).
}

// R6Engine.dll @ 10001830 : AR6GameReplicationInfo::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6GameReplicationInfo::StaticClass(void)
{
    return &AR6GameReplicationInfo::PrivateStaticClass; // Selected object at0x1007e438.
}

// R6Engine.dll @ 10001840 : AR6GameReplicationInfo::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6GameReplicationInfo::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6GameReplicationInfo::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10001870 : AR6GameReplicationInfo::~AR6GameReplicationInfo
// Conditionally destroys UObject state, the fixed string arrays, the current-game string and the base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6GameReplicationInfo::~AR6GameReplicationInfo(AR6GameReplicationInfo* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&GameReplicationDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6GameReplicationInfoVirtualTable);
    guard[3] = 13;
    this->UObject::ConditionalDestroy(); // Return value ignored.
    using StringDestructor = void (__thiscall*)(FStringNoInit*);
    using DestroyArray = void (__stdcall*)(void*, uint, uint, StringDestructor);
    for (uint index = 12; index != 0; --index) {
        StringDestructor destroyElement = reinterpret_cast<StringDestructor&>(FStringNoInitDestructorImport);
        *(byte*)&guard[3] = (byte)index; // Callback captured before excluding the current array from unwind.
        (*(DestroyArray)((uint)&_eh_vector_destructor_iterator_))((byte*)this + 0x630 + (index - 1) * 0x180, 12, 32,
            destroyElement);
    }
    *(byte*)&guard[3] = 0;
    reinterpret_cast<FStringNoInit*>(&this->m_szCurrGameType)->FStringNoInit::~FStringNoInit();
    guard[3] = 0xffffffff;
    this->AGameReplicationInfo::~AGameReplicationInfo();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10001a20 : AR6GameReplicationInfo::AR6GameReplicationInfo (native default-constructor view)
// Constructs the base, current-game string and twelve fixed string arrays with prefix unwind coverage.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6GameReplicationInfo* __thiscall AR6GameReplicationInfo::AR6GameReplicationInfo(AR6GameReplicationInfo* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state view, not class storage.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&GameReplicationCtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AGameReplicationInfo::AGameReplicationInfo(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6GameReplicationInfoVirtualTable);
    using StringConstructor = void (__thiscall*)(FStringNoInit*);
    using StringDestructor = void (__thiscall*)(FStringNoInit*);
    ::new (reinterpret_cast<void*>(&this->m_szCurrGameType)) FStringNoInit;
    using ConstructArray = void (__stdcall*)(void*, uint, uint, StringConstructor, StringDestructor);
    // Fixed FString[32] members occupy +630..+16b0; no scalar/default-value initialization is added.
    for (uint index = 0; index != 12; ++index) {
        StringDestructor destroyElement = reinterpret_cast<StringDestructor&>(FStringNoInitDestructorImport);
        StringConstructor constructElement =
            reinterpret_cast<StringConstructor&>(FStringNoInitDefaultConstructorImport);
        *(byte*)&guard[3] = (byte)(index + 1); // Callbacks are captured before the state-byte publication.
        (*(ConstructArray)&_eh_vector_constructor_iterator_)((byte*)this + 0x630 + index * 0x180, 12, 32,
            constructElement, destroyElement);
    }
    ExceptionList = (void*)guard[1];
    return this; // Last array has no later throwing operation requiring an additional cleanup state.
}

// R6Engine.dll @ 10001c10 : AR6GameReplicationInfo::AR6GameReplicationInfo (native copy-constructor view)
// Copies raw settings and fixed strings, retaining the native delayed and limited cleanup coverage.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6GameReplicationInfo* __thiscall AR6GameReplicationInfo::AR6GameReplicationInfo(
    AR6GameReplicationInfo* this, const AR6GameReplicationInfo* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&GameReplicationCopyExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AGameReplicationInfo::AGameReplicationInfo(this, source);
    *(uint*)this = ((uint)&AR6GameReplicationInfoVirtualTable);
    this->m_iDeathCameraMode = source->m_iDeathCameraMode;
    this->m_MaxPlayers = source->m_MaxPlayers;
    this->m_iCurrentRound = source->m_iCurrentRound;
    this->m_iRoundsPerMatch = source->m_iRoundsPerMatch;
    this->m_iDiffLevel = source->m_iDiffLevel;
    this->m_iNbOfTerro = source->m_iNbOfTerro;
    this->m_iMenuCountDownTime = source->m_iMenuCountDownTime;
    this->m_aTeamScore[0] = source->m_aTeamScore[0];
    int secondTeamScore = source->m_aTeamScore[1];
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x600);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x600);
    uint oldFlags = *destinationFlagWord; // Captured before publishing the second team score.
    this->m_aTeamScore[1] = secondTeamScore;
    this->c_iTeamNumBravo = source->c_iTeamNumBravo;
    uint difference = oldFlags ^ *sourceFlagWord;
    uint mergedFlags = *destinationFlagWord ^ (difference & 1);
    *destinationFlagWord = mergedFlags;
    for (uint mask = 2; mask != 0x10000; mask <<= 1) {
        difference = *sourceFlagWord ^ mergedFlags;
        if (mask == 0x200) guard[3] = 0; // Base cleanup activates after reading the tenth source flag word.
        mergedFlags ^= difference & mask;
        *destinationFlagWord = mergedFlags;
    }
    // Native MOV copies retain float bits and object-reference words.
    reinterpret_cast<uint&>(this->m_fTimeBetRounds) = reinterpret_cast<const uint&>(source->m_fTimeBetRounds);
    reinterpret_cast<uint&>(this->m_fBombTime) = reinterpret_cast<const uint&>(source->m_fBombTime);
    reinterpret_cast<uint&>(this->m_fRepMenuCountDownTime) = reinterpret_cast<const
        uint&>(source->m_fRepMenuCountDownTime);
    reinterpret_cast<uint&>(this->m_fRepMenuCountDownTimeLastUpdate) = reinterpret_cast<const
        uint&>(source->m_fRepMenuCountDownTimeLastUpdate);
    this->m_RainbowTeam[0] = source->m_RainbowTeam[0];
    this->m_RainbowTeam[1] = source->m_RainbowTeam[1];
    this->m_RainbowTeam[2] = source->m_RainbowTeam[2];
    this->m_MenuCommunication = source->m_MenuCommunication;
    using CopyString = void (__thiscall*)(FStringNoInit*, const FStringNoInit*);
    using DestroyString = void (__thiscall*)(FStringNoInit*);
    ::new (reinterpret_cast<void*>(&this->m_szCurrGameType)) FStringNoInit(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szCurrGameType));
    using CopyArray = void (__stdcall*)(void*, const void*, uint, uint, CopyString, DestroyString);
    for (uint offset = 0x630; offset != 0x1830; offset += 0x180) {
        DestroyString destroyElement = reinterpret_cast<DestroyString&>(FStringNoInitDestructorImport);
        CopyString copyElement = reinterpret_cast<CopyString&>(FStringNoInitCopyConstructorImport);
        if (offset == 0x630) *(byte*)&guard[3] = 1; // No array-specific cleanup states are added later.
        (*(CopyArray)&_eh_vector_copy_constructor_iterator_)((byte*)this + offset, (const byte*)source + offset,
            12, 32,
            copyElement, destroyElement);
    }
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 10002050 : AR6GameReplicationInfo::operator=
// Assigns the base, sixteen packed flags and fixed string arrays in native forward order.
AR6GameReplicationInfo& __thiscall AR6GameReplicationInfo::operator=(const AR6GameReplicationInfo& sourceObject)
{
    const AR6GameReplicationInfo* source = &sourceObject;
    this->AGameReplicationInfo::operator=(*source);
    this->m_iDeathCameraMode = source->m_iDeathCameraMode;
    this->m_MaxPlayers = source->m_MaxPlayers;
    this->m_iCurrentRound = source->m_iCurrentRound;
    this->m_iRoundsPerMatch = source->m_iRoundsPerMatch;
    this->m_iDiffLevel = source->m_iDiffLevel;
    this->m_iNbOfTerro = source->m_iNbOfTerro;
    this->m_iMenuCountDownTime = source->m_iMenuCountDownTime;
    this->m_aTeamScore[0] = source->m_aTeamScore[0];
    this->m_aTeamScore[1] = source->m_aTeamScore[1];
    int bravoTeamNumber = source->c_iTeamNumBravo;
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x600);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x600);
    uint oldFlags = *destinationFlagWord; // Captured before publishing c_iTeamNumBravo.
    this->c_iTeamNumBravo = bravoTeamNumber;
    uint sourceFlags = *sourceFlagWord;
    uint mergedFlags = *destinationFlagWord ^ ((oldFlags ^ sourceFlags) & 1); // bShowLog.
    *destinationFlagWord = mergedFlags;
    // Remaining declared bits reload the source word and retain the previous destination merge.
    // m_bPasswordReq, m_bAdminPasswordReq, m_bFriendlyFire, m_bAutoBalance, m_bTKPenalty, m_bMenuTKPenaltySetting
    // m_bShowNames.
    // m_bInternetSvr, m_bFFPWeapon, m_bDedicatedSvr, m_bAIBkp, m_bRotateMap, m_bRepMenuCountDownTimePaused
    // m_bRepMenuCountDownTimeUnlimited, m_bIsWritableMapAllowed.
    for (uint mask = 2; mask != 0x10000; mask <<= 1) {
        sourceFlags = *sourceFlagWord;
        mergedFlags ^= (sourceFlags ^ mergedFlags) & mask;
        *destinationFlagWord = mergedFlags;
    }
    // Native MOV copies preserve all float and object-reference words.
    reinterpret_cast<uint&>(this->m_fTimeBetRounds) = reinterpret_cast<const uint&>(source->m_fTimeBetRounds);
    reinterpret_cast<uint&>(this->m_fBombTime) = reinterpret_cast<const uint&>(source->m_fBombTime);
    reinterpret_cast<uint&>(this->m_fRepMenuCountDownTime) = reinterpret_cast<const
        uint&>(source->m_fRepMenuCountDownTime);
    reinterpret_cast<uint&>(this->m_fRepMenuCountDownTimeLastUpdate) = reinterpret_cast<const
        uint&>(source->m_fRepMenuCountDownTimeLastUpdate);
    this->m_RainbowTeam[0] = source->m_RainbowTeam[0];
    this->m_RainbowTeam[1] = source->m_RainbowTeam[1];
    this->m_RainbowTeam[2] = source->m_RainbowTeam[2];
    this->m_MenuCommunication = source->m_MenuCommunication;
    reinterpret_cast<FStringNoInit*>(&this->m_szCurrGameType)->operator=(
        *reinterpret_cast<const FStringNoInit*>(&source->m_szCurrGameType));
    uint sourceDisplacement = (uint)source - (uint)this; // Wrapping native address displacement.
    // Twelve FString[32] arrays run from m_mapArray through m_szGadgMiscRes at stride 0x180.
    for (uint arrayOffset = 0x630; arrayOffset != 0x1830; arrayOffset += 0x180) {
        uint destination = (uint)this + arrayOffset;
        for (int remaining = 32; remaining != 0; --remaining, destination += 12) {
            const FStringNoInit* input = (const FStringNoInit*)(destination + sourceDisplacement);
            reinterpret_cast<FStringNoInit*>(destination)->operator=(*input);
        }
    }
    return *this; // Native returns the original receiver and removes one pointer word; no self-assignment guard.
}

// R6Engine.dll @ 1000db40 : AR6GameReplicationInfo::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6GameReplicationInfo::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6GameReplicationInfoConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10042cb0 : GameReplicationDtorState0Cleanup
// Tail-enters base destruction through the inherited parent-frame saved receiver.
__declspec(naked) void GameReplicationDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AGameReplicationInfoDestructorImport]
    }
}

// R6Engine.dll @ 10042cb9 : GameReplicationDtorState1Cleanup
// Tail-enters current-game string destruction through the inherited parent-frame receiver.
__declspec(naked) void GameReplicationDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x624
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10042cc8 : GameReplicationDtorState2Cleanup
// Destroys the remaining fixed string array at +0x630 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState2Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x630
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042ce2 : GameReplicationDtorState3Cleanup
// Destroys the remaining fixed string array at +0x7b0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState3Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x7b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042cfc : GameReplicationDtorState4Cleanup
// Destroys the remaining fixed string array at +0x930 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState4Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x930
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d16 : GameReplicationDtorState5Cleanup
// Destroys the remaining fixed string array at +0xab0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState5Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xab0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d30 : GameReplicationDtorState6Cleanup
// Destroys the remaining fixed string array at +0xc30 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState6Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xc30
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d4a : GameReplicationDtorState7Cleanup
// Destroys the remaining fixed string array at +0xdb0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState7Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xdb0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d64 : GameReplicationDtorState8Cleanup
// Destroys the remaining fixed string array at +0xf30 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState8Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xf30
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d7e : GameReplicationDtorState9Cleanup
// Destroys the remaining fixed string array at +0x10b0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState9Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x10b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042d98 : GameReplicationDtorState10Cleanup
// Destroys the remaining fixed string array at +0x1230 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState10Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x1230
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042db2 : GameReplicationDtorState11Cleanup
// Destroys the remaining fixed string array at +0x13b0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState11Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x13b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042dcc : GameReplicationDtorState12Cleanup
// Destroys the remaining fixed string array at +0x1530 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState12Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x1530
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042de6 : GameReplicationDtorState13Cleanup
// Destroys the remaining fixed string array at +0x16b0 through the inherited parent frame.
__declspec(naked) void GameReplicationDtorState13Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x16b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042e00 : GameReplicationDtorExceptionHandler
// Selects destructor cleanup metadata and tail-enters the native exception dispatcher.
__declspec(naked) void GameReplicationDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset gameReplicationDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042e10 : GameReplicationCtorState0Cleanup
// Destroys the completed base through the constructor dispatcher's inherited frame.
__declspec(naked) void GameReplicationCtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AGameReplicationInfoDestructorImport]
    }
}

// R6Engine.dll @ 10042e19 : GameReplicationCtorState1Cleanup
// Destroys the completed current-game string through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x624
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10042e28 : GameReplicationCtorState2Cleanup
// Destroys the completed fixed string array at +0x630 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState2Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x630
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042e42 : GameReplicationCtorState3Cleanup
// Destroys the completed fixed string array at +0x7b0 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState3Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x7b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042e5c : GameReplicationCtorState4Cleanup
// Destroys the completed fixed string array at +0x930 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState4Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x930
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042e76 : GameReplicationCtorState5Cleanup
// Destroys the completed fixed string array at +0xab0 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState5Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xab0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042e90 : GameReplicationCtorState6Cleanup
// Destroys the completed fixed string array at +0xc30 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState6Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xc30
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042eaa : GameReplicationCtorState7Cleanup
// Destroys the completed fixed string array at +0xdb0 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState7Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xdb0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042ec4 : GameReplicationCtorState8Cleanup
// Destroys the completed fixed string array at +0xf30 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState8Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xf30
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042ede : GameReplicationCtorState9Cleanup
// Destroys the completed fixed string array at +0x10b0 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState9Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x10b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042ef8 : GameReplicationCtorState10Cleanup
// Destroys the completed fixed string array at +0x1230 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState10Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x1230
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042f12 : GameReplicationCtorState11Cleanup
// Destroys the completed fixed string array at +0x13b0 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState11Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x13b0
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042f2c : GameReplicationCtorState12Cleanup
// Destroys the completed fixed string array at +0x1530 through the inherited constructor frame.
__declspec(naked) void GameReplicationCtorState12Cleanup(void)
{
    __asm {
        mov eax,dword ptr [FStringNoInitDestructorImport]
        push eax
        push 32
        push 12
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x1530
        push ecx
        call _eh_vector_destructor_iterator_
        ret
    }
}

// R6Engine.dll @ 10042f46 : GameReplicationCtorExceptionHandler
// Selects default-constructor cleanup metadata and tail-enters the native exception dispatcher.
__declspec(naked) void GameReplicationCtorExceptionHandler(void)
{
    __asm {
        mov eax,offset gameReplicationCtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10042f50 : GameReplicationCopyState0Cleanup
// Tail-enters base destruction through the inherited parent-frame saved receiver.
__declspec(naked) void GameReplicationCopyState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [AGameReplicationInfoDestructorImport]
    }
}

// R6Engine.dll @ 10042f59 : GameReplicationCopyState1Cleanup
// Tail-enters current-game string destruction through the inherited parent-frame receiver.
__declspec(naked) void GameReplicationCopyState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x624
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10042f68 : GameReplicationCopyExceptionHandler
// Selects copy-constructor cleanup metadata and tail-enters the native exception dispatcher.
__declspec(naked) void GameReplicationCopyExceptionHandler(void)
{
    __asm {
        mov eax,offset gameReplicationCopyInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047070 : InitializeAR6GameReplicationInfoClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6GameReplicationInfoClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AGameReplicationInfo object address, captured before config lookup.
    UClass* parentClass = AGameReplicationInfoPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6GameReplicationInfo::PrivateStaticClass, 0, 0x1830,
        4,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6GameReplicationInfo,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6GameReplicationInfo::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6GameReplicationInfoClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100481b0 : DestroyAR6GameReplicationInfoClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6GameReplicationInfoClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6GameReplicationInfo::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047100 : PublishAR6GameReplicationInfoAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6GameReplicationInfoAutoClass(void)
{
    autoclassAR6GameReplicationInfo = &AR6GameReplicationInfo::PrivateStaticClass;
}

// R6Engine.dll @ 10002430 : AR6GameReplicationInfo::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6GameReplicationInfo::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6GameReplicationInfoDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x1830;
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
    this->AR6GameReplicationInfo::~AR6GameReplicationInfo();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x1830;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
