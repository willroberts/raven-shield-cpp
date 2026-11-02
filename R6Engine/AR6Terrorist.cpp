#include "native_object_tables.hpp"
#include "native_exception_records.hpp"
#include "native_text_data.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_scalar_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void TerroristUpdateAimingExceptionHandler(void);
__declspec(naked) void __cdecl DestroyAR6TerroristClassMetadata(void);

// Native guard metadata; partial PE32 records retain the existing frame and cleanup contracts.
__declspec(naked) void TerroristDestructionBaseCleanup(void);
__declspec(naked) void TerroristDestructionUsedTemplateCleanup(void);
__declspec(naked) void TerroristDestructionPrimaryWeaponCleanup(void);
__declspec(naked) void TerroristDestructionGrenadeWeaponCleanup(void);
__declspec(naked) void TerroristDestructionGadgetCleanup(void);
__declspec(naked) void TerroristConstructionBaseCleanup(void);
__declspec(naked) void TerroristConstructionUsedTemplateCleanup(void);
__declspec(naked) void TerroristConstructionPrimaryWeaponCleanup(void);
__declspec(naked) void TerroristConstructionGrenadeWeaponCleanup(void);
__declspec(naked) void AR6TerroristUpdateAimingCatchPointer(void);
__declspec(naked) void AR6TerroristUpdateAimingCatchContext(void);
__declspec(naked) void AR6TerroristPreNetReceiveCatchPointer(void);
__declspec(naked) void AR6TerroristPreNetReceiveCatchContext(void);
__declspec(naked) void AR6TerroristPostNetReceiveCatchPointer(void);
__declspec(naked) void AR6TerroristPostNetReceiveCatchContext(void);

// R6Engine.dll data @ 10056c38 : TerroristDestructionUnwindMap
const NativeUnwindEntry TerroristDestructionUnwindMap[5] = {
    { -1, ((uint)&TerroristDestructionBaseCleanup) },
    { 0, ((uint)&TerroristDestructionUsedTemplateCleanup) },
    { 0x1, ((uint)&TerroristDestructionPrimaryWeaponCleanup) },
    { 0x2, ((uint)&TerroristDestructionGrenadeWeaponCleanup) },
    { 0x3, ((uint)&TerroristDestructionGadgetCleanup) }
};

// R6Engine.dll data @ 10056cb8 : TerroristConstructionUnwindMap
const NativeUnwindEntry TerroristConstructionUnwindMap[4] = {
    { -1, ((uint)&TerroristConstructionBaseCleanup) },
    { 0, ((uint)&TerroristConstructionUsedTemplateCleanup) },
    { 0x1, ((uint)&TerroristConstructionPrimaryWeaponCleanup) },
    { 0x2, ((uint)&TerroristConstructionGrenadeWeaponCleanup) }
};

// R6Engine.dll data @ 1005b46c : TerroristUpdateAimingUnwindMap
const NativeUnwindEntry TerroristUpdateAimingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d81c : TerroristPreNetReceiveUnwindMap
const NativeUnwindEntry TerroristPreNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005d93c : TerroristPostNetReceiveUnwindMap
const NativeUnwindEntry TerroristPostNetReceiveUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005b47c : TerroristUpdateAimingCatchMap
const NativeCatchEntry TerroristUpdateAimingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -36, ((uint)&AR6TerroristUpdateAimingCatchPointer) },
    { 0, 0, 0, ((uint)&AR6TerroristUpdateAimingCatchContext) }
};

// R6Engine.dll data @ 1005d82c : TerroristPreNetReceiveCatchMap
const NativeCatchEntry TerroristPreNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6TerroristPreNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&AR6TerroristPreNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005d94c : TerroristPostNetReceiveCatchMap
const NativeCatchEntry TerroristPostNetReceiveCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&AR6TerroristPostNetReceiveCatchPointer) },
    { 0, 0, 0, ((uint)&AR6TerroristPostNetReceiveCatchContext) }
};

// R6Engine.dll data @ 1005b49c : TerroristUpdateAimingTryMap
const NativeTryBlock TerroristUpdateAimingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&TerroristUpdateAimingCatchMap) }
};

// R6Engine.dll data @ 1005d84c : TerroristPreNetReceiveTryMap
const NativeTryBlock TerroristPreNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&TerroristPreNetReceiveCatchMap) }
};

// R6Engine.dll data @ 1005d96c : TerroristPostNetReceiveTryMap
const NativeTryBlock TerroristPostNetReceiveTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&TerroristPostNetReceiveCatchMap) }
};

// R6Engine.dll data @ 10056c60 : TerroristDestructionFuncInfo
const NativeFunctionInfoPrefix TerroristDestructionFuncInfo = {
    0x19930520, 0x5, ((uint)&TerroristDestructionUnwindMap), 0, 0, 0
};

// R6Engine.dll data @ 10056cd8 : TerroristConstructionFuncInfo
const NativeFunctionInfoPrefix TerroristConstructionFuncInfo = {
    0x19930520, 0x4, ((uint)&TerroristConstructionUnwindMap), 0, 0, 0
};

// R6Engine.dll data @ 1005b4b0 : TerroristUpdateAimingFuncInfo
const NativeFunctionInfoPrefix TerroristUpdateAimingFuncInfo = {
    0x19930520, 0x2, ((uint)&TerroristUpdateAimingUnwindMap), 0x1, ((uint)&TerroristUpdateAimingTryMap), 0
};

// R6Engine.dll data @ 1005d860 : TerroristPreNetReceiveFuncInfo
const NativeFunctionInfoPrefix TerroristPreNetReceiveFuncInfo = {
    0x19930520, 0x2, ((uint)&TerroristPreNetReceiveUnwindMap), 0x1, ((uint)&TerroristPreNetReceiveTryMap), 0
};

// R6Engine.dll data @ 1005d980 : TerroristPostNetReceiveFuncInfo
const NativeFunctionInfoPrefix TerroristPostNetReceiveFuncInfo = {
    0x19930520, 0x2, ((uint)&TerroristPostNetReceiveUnwindMap), 0x1, ((uint)&TerroristPostNetReceiveTryMap), 0
};

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a440 : AR6TerroristVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Terrorist::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6TerroristVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10053b4c : nativeTextAR6TerroristPostNetReceive
extern const ushort nativeTextAR6TerroristPostNetReceive[29];

// R6Engine.dll data @ 10053a88 : nativeTextAR6TerroristPreNetReceive
extern const ushort nativeTextAR6TerroristPreNetReceive[28];

// R6Engine.dll data @ 100517ac : nativeTextAR6TerroristUpdateAiming
extern const ushort nativeTextAR6TerroristUpdateAiming[27];

// R6Engine.dll data @ 10051808 : nativeTextR6LForearm
extern const ushort nativeTextR6LForearm[13];

// R6Engine.dll data @ 100517f4 : nativeTextR6LHand
extern const ushort nativeTextR6LHand[10];

// R6Engine.dll data @ 10051824 : nativeTextR6Spine2
extern const ushort nativeTextR6Spine2[10];

// R6Engine.dll data @ 10055612 : nativeTextR6Terrorist
extern const ushort nativeTextR6Terrorist[12];

// Descriptive scalar names identify native values; the original identifiers are unknown.
// Native helper declarations match the canonical definitions below.
__declspec(naked) void TerroristConstructionExceptionHandler(void);
__declspec(naked) void TerroristDestructionExceptionHandler(void);

// R6Engine.dll data @ 10051870 : nativeDouble0Point66
extern const double nativeDouble0Point66;

// R6Engine.dll data @ 10051878 : nativeFloat3EPlus04
extern const float nativeFloat3EPlus04;

// R6Engine.dll data @ 1007a198 : autoclassAR6Terrorist
// The loader supplies zero before PublishTerroristAutoClass stores the persistent class pointer.
UClass* autoclassAR6Terrorist = nullptr;

// R6Engine.dll data @ 1007644c–1007644e : shared terrorist receive snapshots
// The native cache is shared across objects and is overwritten by each PreNetReceive call.
byte PreNetTerroristHealth = 0;
byte PreNetTerroristDefCon = 0;
byte PreNetTerroristSpecialAnim = 0;

// R6Engine.dll @ 100063b0 : AR6Terrorist::eventStopSpecialAnim
// Dispatches StopSpecialAnim with no parameters or result through the vtable captured before function lookup.
void __thiscall AR6Terrorist::eventStopSpecialAnim(void)
{
    // Freeze the exported four-byte FName before reading this.
    uint nameWord = reinterpret_cast<const uint&>(R6ENGINE_StopSpecialAnim);
    NativeEventVtablePrefix* dispatchTable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, *(FName*)&nameWord, 0);
    using Dispatch = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    // Load the slot AFTER lookup from the saved table.
    Dispatch processEvent = reinterpret_cast<Dispatch&>(dispatchTable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 100063e0 : AR6Terrorist::eventLoopSpecialAnim
// Dispatches LoopSpecialAnim with no parameters or result through the vtable captured before function lookup.
void __thiscall AR6Terrorist::eventLoopSpecialAnim(void)
{
    // Freeze the exported four-byte FName before reading this.
    uint nameWord = reinterpret_cast<const uint&>(R6ENGINE_LoopSpecialAnim);
    NativeEventVtablePrefix* dispatchTable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, *(FName*)&nameWord, 0);
    using Dispatch = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    // Load the slot AFTER lookup from the saved table.
    Dispatch processEvent = reinterpret_cast<Dispatch&>(dispatchTable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10006410 : AR6Terrorist::eventPlaySpecialAnim
// Dispatches PlaySpecialAnim with no parameters or result through the vtable captured before function lookup.
void __thiscall AR6Terrorist::eventPlaySpecialAnim(void)
{
    // Freeze the exported four-byte FName before reading this.
    uint nameWord = reinterpret_cast<const uint&>(R6ENGINE_PlaySpecialAnim);
    NativeEventVtablePrefix* dispatchTable = *reinterpret_cast<NativeEventVtablePrefix**>(this);
    UFunction* function = UObject::FindFunctionChecked(this, *(FName*)&nameWord, 0);
    using Dispatch = void (__thiscall*)(UObject*, UFunction*, void*, void*);
    // Load the slot AFTER lookup from the saved table.
    Dispatch processEvent = reinterpret_cast<Dispatch&>(dispatchTable->processEventAddress);
    processEvent(this, function, nullptr, nullptr);
}

// R6Engine.dll @ 10006440 : AR6Terrorist::StaticClass
// Returns the module's persistent terrorist class object.
UClass* __cdecl AR6Terrorist::StaticClass(void)
{
    return &AR6Terrorist::PrivateStaticClass; // Selected class object at 0x100773e0.
}

// R6Engine.dll @ 10006450 : AR6Terrorist::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6Terrorist::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6Terrorist::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10006480 : AR6Terrorist::~AR6Terrorist
// Runs conditional destruction, releases four strings in reverse order and destroys the pawn base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6Terrorist::~AR6Terrorist(AR6Terrorist* this)
{
    uint guard[4]; // Inferred saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6TerroristVirtualTable);
    guard[3] = 4;
    this->UObject::ConditionalDestroy();
    for (uint remaining = 4; remaining != 0; --remaining) {
        *(byte*)&guard[3] = (byte)(remaining - 1);
        reinterpret_cast<FStringNoInit*>((byte*)this + 0xa6c + 12 * (remaining - 1))->FStringNoInit::~FStringNoInit();
    }
    guard[3] = 0xffffffff;
    this->AR6Pawn::~AR6Pawn();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10043160 : destroy the saved AR6Pawn base through the inherited parent frame
__declspec(naked) void TerroristDestructionBaseCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043168 : destroy the saved m_szUsedTemplate through the inherited parent frame
__declspec(naked) void TerroristDestructionUsedTemplateCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa6c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043177 : destroy the saved m_szPrimaryWeapon through the inherited parent frame
__declspec(naked) void TerroristDestructionPrimaryWeaponCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa78
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043186 : destroy the saved m_szGrenadeWeapon through the inherited parent frame
__declspec(naked) void TerroristDestructionGrenadeWeaponCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa84
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043195 : destroy the saved m_szGadget through the inherited parent frame
__declspec(naked) void TerroristDestructionGadgetCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa90
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100431a4 : select TerroristDestruction exception tables without changing the native frame
__declspec(naked) void TerroristDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset TerroristDestructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10006520 : AR6Terrorist::AR6Terrorist
// Constructs the abstract-pawn base and four no-init strings under completed-prefix cleanup states.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6Terrorist* __thiscall AR6Terrorist::AR6Terrorist(AR6Terrorist* this)
{
    uint guard[4]; // Inferred saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    using ConstructBase = void (__thiscall*)(AR6AbstractPawn*);
    reinterpret_cast<ConstructBase&>(AR6AbstractPawnDefaultConstructorImport)(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6TerroristVirtualTable);
    for (uint index = 0; index != 4; ++index) {
        if (index != 0) *(byte*)&guard[3] = (byte)index;
        ::new (reinterpret_cast<void*>((byte*)this + 0xa6c + 12 * index)) FStringNoInit;
    }
    ExceptionList = (void*)guard[1];
    return this; // Native leaves ordinary fields and no-init string words untouched.
}

// R6Engine.dll @ 100065b0 : AR6Terrorist::AR6Terrorist copy constructor
// Copies the pawn base, selected terrorist scalar/flag fields and four owning string subobjects.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6Terrorist* __thiscall AR6Terrorist::AR6Terrorist(AR6Terrorist* this, const AR6Terrorist* source)
{
    uint guard[4]; // Inferred saved-this/previous SEH/handler/state view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&TerroristConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const AR6Terrorist* const capturedSource = source;
    const AR6Pawn* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats the saved-receiver store after placing the base argument.
    using CopyPawnBase = AR6Pawn* (__thiscall*)(AR6Pawn*, const AR6Pawn*);
    reinterpret_cast<CopyPawnBase>(&AR6PawnCopyConstructorNativeEntry)(this, baseSourceArgument);
    *(void**)this = (void*)&AR6TerroristVirtualTable;
    this->m_eDefCon = capturedSource->m_eDefCon;
    this->m_ePersonality = capturedSource->m_ePersonality;
    this->m_eStrategy = capturedSource->m_eStrategy;
    this->m_eStartingStance = capturedSource->m_eStartingStance;
    this->m_eHeadAttachmentType = capturedSource->m_eHeadAttachmentType;
    this->m_eTerroType = capturedSource->m_eTerroType;
    this->m_eSpecialAnimValid = capturedSource->m_eSpecialAnimValid;
    this->m_wWantedAimingPitch = capturedSource->m_wWantedAimingPitch;
    this->m_wWantedHeadYaw = capturedSource->m_wWantedHeadYaw;
    this->m_iGroupID = capturedSource->m_iGroupID;
    this->m_iCurrentAimingPitch = capturedSource->m_iCurrentAimingPitch;
    int headYaw = capturedSource->m_iCurrentHeadYaw;
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa44);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xa44);
    uint firstFlags = *destinationFlagWord; // Snapshot before writing head yaw and difficulty.
    this->m_iCurrentHeadYaw = headYaw;
    this->m_iDiffLevel = capturedSource->m_iDiffLevel;
    // m_bBoltActionRifle is the first selected flag (mask 1).
    uint changedFirstBit = (firstFlags ^ *sourceFlagWord) & 1U;
    uint flags = *destinationFlagWord ^ changedFirstBit;
    *destinationFlagWord = flags;
    // Each source word reloads separately; preserve unselected flag bits and the eleven native stores.
    auto copyFlag = [&](uint mask) {
        flags ^= (flags ^ *sourceFlagWord) & mask;
        *destinationFlagWord = flags;
    };
    copyFlag(0x2); // m_bHaveAGrenade.
    copyFlag(0x4); // m_bInitFinished.
    copyFlag(0x8); // m_bAllowLeave.
    copyFlag(0x10); // m_bPreventCrouching.
    copyFlag(0x20); // m_bHearNothing.
    copyFlag(0x40); // m_bSprayFire.
    copyFlag(0x80); // m_bPreventWeaponAnimation.
    uint arrestSourceFlags = *sourceFlagWord;
    guard[3] = 0; // Base cleanup first becomes active between this source read and the 0x100 merge.
    flags ^= (flags ^ arrestSourceFlags) & 0x100U; // m_bIsUnderArrest.
    *destinationFlagWord = flags;
    copyFlag(0x200); // m_bPatrolForward.
    copyFlag(0x400); // m_bEnteringView.
    reinterpret_cast<uint&>(this->m_fPlayerCAStartTime) = reinterpret_cast<const
        uint&>(capturedSource->m_fPlayerCAStartTime);
    reinterpret_cast<uint&>(this->m_HeadAttachment) = reinterpret_cast<const uint&>(capturedSource->m_HeadAttachment);
    reinterpret_cast<uint&>(this->m_Radio) = reinterpret_cast<const uint&>(capturedSource->m_Radio);
    reinterpret_cast<uint&>(this->m_controller) = reinterpret_cast<const uint&>(capturedSource->m_controller);
    reinterpret_cast<uint&>(this->m_DZone) = reinterpret_cast<const uint&>(capturedSource->m_DZone);
    reinterpret_cast<uint&>(this->m_szSpecialAnimName) = reinterpret_cast<const
        uint&>(capturedSource->m_szSpecialAnimName);
    this->m_rFiringRotation.Pitch = capturedSource->m_rFiringRotation.Pitch;
    this->m_rFiringRotation.Yaw = capturedSource->m_rFiringRotation.Yaw;
    this->m_rFiringRotation.Roll = capturedSource->m_rFiringRotation.Roll;
    using CopyString = void (__thiscall*)(FStringNoInit*, const FStringNoInit&);
    for (uint index = 0; index != 4; ++index) {
        const FStringNoInit* stringArgument = // Inferred outgoing word at entryESP-0x1c, before the state store.
            (const FStringNoInit*)((const byte*)capturedSource + 0xa6c + 12 * index);
        if (index != 0) *(byte*)&guard[3] = (byte)index;
        CopyString copy = reinterpret_cast<CopyString&>(FStringNoInitCopyConstructorImport);
        copy((FStringNoInit*)((byte*)this + 0xa6c + 12 * index), *stringArgument);
    }
    ExceptionList = (void*)guard[1];
    return this; // RET 4; shared constructor map unwinds only strings that completed construction.
}

// R6Engine.dll @ 100431b0 : destroy the saved AR6Pawn base through the inherited parent frame
__declspec(naked) void TerroristConstructionBaseCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 100431b8 : destroy the saved m_szUsedTemplate through the inherited parent frame
__declspec(naked) void TerroristConstructionUsedTemplateCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa6c
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100431c7 : destroy the saved m_szPrimaryWeapon through the inherited parent frame
__declspec(naked) void TerroristConstructionPrimaryWeaponCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa78
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100431d6 : destroy the saved m_szGrenadeWeapon through the inherited parent frame
__declspec(naked) void TerroristConstructionGrenadeWeaponCleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xa84
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100431e5 : select TerroristConstruction exception tables without changing the native frame
__declspec(naked) void TerroristConstructionExceptionHandler(void)
{
    __asm {
        mov eax,offset TerroristConstructionFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10006840 : AR6Terrorist::operator=
// Assigns the pawn base and selected terrorist fields, then assigns each existing string subobject.
AR6Terrorist& __thiscall AR6Terrorist::operator=(const AR6Terrorist& sourceObject)
{
    const AR6Terrorist* source = &sourceObject;
    const AR6Terrorist* const capturedSource = source;
    const AR6Pawn* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    this->AR6Pawn::operator=(*baseSourceArgument); // Called even on self-assignment.
    this->m_eDefCon = capturedSource->m_eDefCon;
    this->m_ePersonality = capturedSource->m_ePersonality;
    this->m_eStrategy = capturedSource->m_eStrategy;
    this->m_eStartingStance = capturedSource->m_eStartingStance;
    this->m_eHeadAttachmentType = capturedSource->m_eHeadAttachmentType;
    this->m_eTerroType = capturedSource->m_eTerroType;
    this->m_eSpecialAnimValid = capturedSource->m_eSpecialAnimValid;
    this->m_wWantedAimingPitch = capturedSource->m_wWantedAimingPitch;
    this->m_wWantedHeadYaw = capturedSource->m_wWantedHeadYaw;
    this->m_iGroupID = capturedSource->m_iGroupID;
    this->m_iCurrentAimingPitch = capturedSource->m_iCurrentAimingPitch;
    int headYaw = capturedSource->m_iCurrentHeadYaw;
    // Stable packed-word addresses; preserve every independent source/destination read and masked store.
    uint* destinationFlagWord = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xa44);
    const uint* sourceFlagWord = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0xa44);
    uint firstFlags = *destinationFlagWord; // Snapshot before writing head yaw and difficulty.
    this->m_iCurrentHeadYaw = headYaw;
    this->m_iDiffLevel = capturedSource->m_iDiffLevel;
    // m_bBoltActionRifle is the first selected flag (mask 1).
    uint changedFirstBit = (firstFlags ^ *sourceFlagWord) & 1U;
    uint flags = *destinationFlagWord ^ changedFirstBit;
    *destinationFlagWord = flags;
    // Each source word reloads separately; preserve unselected flag bits and the eleven native stores.
    auto copyFlag = [&](uint mask) {
        flags ^= (flags ^ *sourceFlagWord) & mask;
        *destinationFlagWord = flags;
    };
    copyFlag(0x2); // m_bHaveAGrenade.
    copyFlag(0x4); // m_bInitFinished.
    copyFlag(0x8); // m_bAllowLeave.
    copyFlag(0x10); // m_bPreventCrouching.
    copyFlag(0x20); // m_bHearNothing.
    copyFlag(0x40); // m_bSprayFire.
    copyFlag(0x80); // m_bPreventWeaponAnimation.
    copyFlag(0x100); // m_bIsUnderArrest.
    copyFlag(0x200); // m_bPatrolForward.
    copyFlag(0x400); // m_bEnteringView.
    reinterpret_cast<uint&>(this->m_fPlayerCAStartTime) = reinterpret_cast<const
        uint&>(capturedSource->m_fPlayerCAStartTime);
    reinterpret_cast<uint&>(this->m_HeadAttachment) = reinterpret_cast<const uint&>(capturedSource->m_HeadAttachment);
    reinterpret_cast<uint&>(this->m_Radio) = reinterpret_cast<const uint&>(capturedSource->m_Radio);
    reinterpret_cast<uint&>(this->m_controller) = reinterpret_cast<const uint&>(capturedSource->m_controller);
    reinterpret_cast<uint&>(this->m_DZone) = reinterpret_cast<const uint&>(capturedSource->m_DZone);
    reinterpret_cast<uint&>(this->m_szSpecialAnimName) = reinterpret_cast<const
        uint&>(capturedSource->m_szSpecialAnimName);
    this->m_rFiringRotation.Pitch = capturedSource->m_rFiringRotation.Pitch;
    this->m_rFiringRotation.Yaw = capturedSource->m_rFiringRotation.Yaw;
    this->m_rFiringRotation.Roll = capturedSource->m_rFiringRotation.Roll;
    for (uint index = 0; index != 4; ++index) {
        const FStringNoInit* stringArgument = // Inferred outgoing word at entryESP-0xc.
            (const FStringNoInit*)((const byte*)capturedSource + 0xa6c + 12 * index);
        reinterpret_cast<FStringNoInit*>((byte*)this + 0xa6c + 12 * index)->operator=(*stringArgument);
    }
    return *this; // RET 4; no local guard or rollback if a base/string assignment throws.
}

// R6Engine.dll @ 10006a90 : AR6Terrorist::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6Terrorist::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6TerroristDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xa9c;
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
    this->AR6Terrorist::~AR6Terrorist();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xa9c;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}

// R6Engine.dll @ 1000dc20 : AR6Terrorist::InternalConstructor
// Enters the default constructor on supplied nonnull storage without adding a return frame.
__declspec(naked) void __cdecl AR6Terrorist::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6TerroristConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10029590 : AR6Terrorist::UpdateAiming
// Smooths replicated head/pitch targets and distributes their rotations across the head, spine and arm bones.
void __thiscall AR6Terrorist::UpdateAiming(float deltaSeconds)
{
    struct NativeFrameView { // Inferred inherited EBP storage; unused rotator lanes are not initialized.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x90/-0x8c/-0x88.
        int rightHandPitch; // EBP-0x84.
        uint unused80[3];
        int leftHandYaw; // EBP-0x74.
        uint unused70[2];
        int leftForearmYaw; // EBP-0x68.
        uint unused64;
        int neckPitch; // EBP-0x60; neck Yaw/Roll remain register values.
        uint unused5C[4];
        int spine1Roll, spinePitch, spineYaw, spineRoll; // EBP-0x4c/-0x48/-0x44/-0x40.
        FRotator spine2; // EBP-0x3c/-0x38/-0x34.
        FRotator head; // EBP-0x30/-0x2c/-0x28.
        uint caught; // EBP-0x24.
        uint* firstNameStorage; // EBP-0x20.
        uint rethrow; // EBP-0x1c.
        int updateHead; // EBP-0x18, full DWORD.
        AR6Terrorist* pawn; // EBP-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = &TerroristUpdateAimingExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    uint encodedHeadYaw = (uint)this->m_wWantedHeadYaw << 8;
    frame.savedEsp = &frame.savedEdi;
    frame.pawn = this;
    frame.state = 0;
    int wantedHeadYaw = encodedHeadYaw > 0x7fffU ? (int)encodedHeadYaw - 0x10000 : (int)encodedHeadYaw;
    int currentHeadYaw = this->m_iCurrentHeadYaw;
    int& updateHead = frame.updateHead;
    updateHead = 0;
    FRotator& head = frame.head;
    head.Roll = 0;
    head.Yaw = 0;
    head.Pitch = 0;
    // Local views preserve the ST(0)/EAX conversion and wrapping integer arithmetic, not new native helper bodies.
    auto truncateLowWord = [](float10 value) {
        int result;
        __asm {
            fld value
            call TruncateX87ToSigned64
            mov result,eax
        }
        return result;
    };
    auto approachAngle = [](int current, int target, int step) {
        if (target < current) {
            int candidate = (int)((uint)current - (uint)step);
            return target < candidate ? candidate : target;
        }
        int candidate = (int)((uint)current + (uint)step);
        return candidate < target ? candidate : target;
    };
    if (currentHeadYaw != wantedHeadYaw) {
        int step = truncateLowWord((float10)deltaSeconds * nativeFloat2EPlus04); // 20000 units/second.
        int yaw = approachAngle(currentHeadYaw, wantedHeadYaw, step);
        byte defCon = this->m_eDefCon;
        this->m_iCurrentHeadYaw = yaw;
        head.Roll = yaw;
        if (defCon < 4) {
            AR6EngineWeapon* weapon = this->EngineWeapon;
            if (weapon == nullptr || weapon->m_eWeaponType != 0) {
                if (yaw < 0) {
                    head.Pitch = yaw / 2;
                    head.Yaw = -(yaw / 2);
                } else {
                    head.Yaw = -(yaw / 3);
                }
            } else if (yaw < 0) {
                head.Yaw = -(yaw / 3);
            }
        }
        updateHead = 1; // A zero or negative time step still schedules the head when the targets differ.
    }
    uint encodedPitch = (uint)this->m_wWantedAimingPitch << 8;
    int wantedPitch = encodedPitch > 0x7fffU ? (int)encodedPitch - 0x10000 : (int)encodedPitch;
    int currentPitch = this->m_iCurrentAimingPitch;
    using NameConstructor = FName* (__thiscall*)(FName*, const ushort*, int);
    using BoneRotation = int (__thiscall*)(USkeletalMeshInstance*, uint, int, int, int, int, float, float);
    NameConstructor constructName;
    struct BonePacket { // Native outgoing words at EBP-0xac..-0x94; FName is constructed in the first word.
        uint bone;
        int pitch, yaw, roll, space;
        float blend, interval;
    } packet;
    auto rotatePacket = [&](BoneRotation rotate, USkeletalMeshInstance* instance) {
        return rotate(instance, packet.bone, packet.pitch, packet.yaw, packet.roll,
            packet.space, packet.blend, packet.interval);
    };
    auto prepareFlags = [&]() { packet.interval = 0.1f; packet.blend = 1.0f; packet.space = 0; };
    AR6Terrorist* headPawn = this;
    if (wantedPitch != currentPitch) {
        int step = truncateLowWord((float10)deltaSeconds * nativeFloat3EPlus04); // 30000 units/second.
        this->m_iCurrentAimingPitch = approachAngle(currentPitch, wantedPitch, step);
        int pitch = this->m_iCurrentAimingPitch;
        reinterpret_cast<int&>(deltaSeconds) = pitch;
        if (pitch < -10000)
            reinterpret_cast<int&>(deltaSeconds) = pitch = -10000;
        else if (pitch >= 10000)
            // The current-pitch field keeps its unbounded smoothed value.
            reinterpret_cast<int&>(deltaSeconds) = pitch = 10000;
        frame.spine2.Roll = 0;
        frame.spine2.Yaw = 0;
        frame.spine2.Pitch = 0;
        frame.leftForearmYaw = 0;
        frame.leftHandYaw = 0;
        frame.rightHandPitch = 0;
        AR6Terrorist* layoutPawn = frame.pawn;
        byte defCon = layoutPawn->m_eDefCon;
        int neckRoll = 0, neckYaw = 0, spine1Yaw = 0;
        frame.neckPitch = 0;
        frame.spineRoll = 0;
        frame.spineYaw = 0;
        frame.spinePitch = 0;
        frame.spine1Roll = 0;
        if (defCon <= 2 && (*reinterpret_cast<uint*>(reinterpret_cast<byte*>(layoutPawn) + 0x3e4) & 0x40000U) != 0) {
            AR6EngineWeapon* weapon = layoutPawn->EngineWeapon;
            if (weapon != nullptr && (weapon->m_eWeaponType == 0 ||
                (reinterpret_cast<byte*>(weapon)[0x3a1] & 1U) != 0)) { // m_bUseMicroAnim is mask 0x100 at +0x3a0.
                neckYaw = -(pitch / 2);
                if (pitch > 0) {
                    spine1Yaw = -(pitch / 5);
                    frame.spine2.Pitch = pitch / 4;
                    frame.spine2.Yaw = spine1Yaw;
                } else {
                    neckRoll = -(pitch / 5);
                    frame.spine2.Yaw = neckYaw;
                }
            } else if ((reinterpret_cast<byte*>(layoutPawn)[0x3e0] & 0x20U) != 0) { // bIsCrouched.
                if (pitch > 0) {
                    neckRoll = -(pitch / 10);
                    frame.spinePitch = pitch / 2;
                    frame.spineYaw = -(pitch / 4);
                    spine1Yaw = frame.spineYaw;
                    frame.spine2.Yaw = frame.spineYaw;
                } else {
                    frame.leftHandYaw = pitch / 4;
                    neckYaw = -(pitch / 4);
                    neckRoll = -(pitch / 10);
                    frame.leftForearmYaw = neckYaw;
                    frame.rightHandPitch = neckYaw;
                    frame.spine2.Yaw = neckYaw;
                    frame.spine1Roll = neckRoll;
                }
            } else if (pitch > 0) {
                reinterpret_cast<int&>(deltaSeconds) = -pitch;
                float10 negativePitch = reinterpret_cast<int&>(deltaSeconds);
                frame.neckPitch = pitch / 2;
                neckYaw = -pitch;
                neckRoll = pitch / 2;
                int quarterTurn = truncateLowWord(negativePitch * nativeDouble0Point25);
                float10 finalRoll = negativePitch * nativeDouble0Point5;
                frame.spineRoll = quarterTurn;
                frame.spine1Roll = quarterTurn;
                frame.spine2.Roll = truncateLowWord(finalRoll);
            } else {
                neckYaw = -(pitch / 2);
                frame.spinePitch = truncateLowWord((float10)reinterpret_cast<int&>(deltaSeconds) *
                    nativeDouble0Point66);
            }
        } else {
            updateHead = 1;
            head.Yaw = truncateLowWord((float10)head.Yaw - (float10)reinterpret_cast<int&>(deltaSeconds) *
                nativeFloat0Point75);
        }
        AR6Terrorist* meshPawn = frame.pawn;
        UMesh* mesh = meshPawn->Mesh;
        USkeletalMeshInstance* returnedInstance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(meshPawn));
        int neckPitch = frame.neckPitch;
        prepareFlags();
        USkeletalMeshInstance*& savedInstance = reinterpret_cast<USkeletalMeshInstance*&>(deltaSeconds);
        savedInstance = returnedInstance;
        packet.bone = (uint)neckPitch;
        packet.pitch = neckPitch;
        frame.firstNameStorage = &packet.bone;
        packet.yaw = neckYaw;
        packet.roll = neckRoll;
        // Retained across the body and optional head calls.
        constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
        // R6 Neck; ignore returned FName pointer.
        constructName((FName*)&packet.bone, nativeTextR6Neck, 1);
        USkeletalMeshInstance* instance = savedInstance;
        rotatePacket(reinterpret_cast<BoneRotation&>(USkeletalMeshInstanceSetBoneRotationImport), instance);
        int pitchWord = frame.spinePitch;
        int yawWord = frame.spineYaw;
        prepareFlags();
        packet.pitch = pitchWord;
        int rollWord = frame.spineRoll;
        packet.bone = (uint)yawWord;
        packet.yaw = yawWord;
        *(uint**)&deltaSeconds = &packet.bone;
        packet.roll = rollWord;
        constructName((FName*)&packet.bone, nativeTextR6Spine, 1); // R6 Spine.
        rotatePacket(reinterpret_cast<BoneRotation&>(USkeletalMeshInstanceSetBoneRotationImport), instance);
        rollWord = frame.spine1Roll;
        prepareFlags();
        packet.pitch = 0;
        packet.yaw = spine1Yaw;
        packet.bone = (uint)&packet.pitch;
        packet.roll = rollWord;
        *(uint**)&deltaSeconds = &packet.bone;
        constructName((FName*)&packet.bone, nativeTextR6Spine1, 1); // R6 Spine1.
        BoneRotation retainedRotation = reinterpret_cast<BoneRotation&>(USkeletalMeshInstanceSetBoneRotationImport);
        rotatePacket(retainedRotation, instance);
        pitchWord = frame.spine2.Pitch;
        yawWord = frame.spine2.Yaw;
        prepareFlags();
        packet.pitch = pitchWord;
        rollWord = frame.spine2.Roll;
        packet.bone = (uint)rollWord;
        packet.yaw = yawWord;
        packet.roll = rollWord;
        *(uint**)&deltaSeconds = &packet.bone;
        constructName((FName*)&packet.bone, nativeTextR6Spine2, 1); // R6 Spine2.
        rotatePacket(retainedRotation, instance);
        // Native PUSH ECX later seeds the name word with this unspecified post-rotation register value.
        uint volatileNameWord;
        __asm { mov volatileNameWord,ecx }
        prepareFlags();
        packet.pitch = 0;
        yawWord = frame.leftForearmYaw;
        packet.bone = volatileNameWord;
        *(uint**)&deltaSeconds = &packet.bone;
        packet.yaw = yawWord;
        packet.roll = 0;
        constructName((FName*)&packet.bone, nativeTextR6LForearm, 1); // R6 L Forearm.
        rotatePacket(retainedRotation, instance);
        yawWord = frame.leftHandYaw;
        prepareFlags();
        packet.pitch = 0;
        packet.yaw = yawWord;
        packet.bone = (uint)&packet.pitch;
        packet.roll = 0;
        *(uint**)&deltaSeconds = &packet.bone;
        constructName((FName*)&packet.bone, nativeTextR6LHand, 1); // R6 L Hand.
        rotatePacket(retainedRotation, instance);
        pitchWord = frame.rightHandPitch;
        prepareFlags();
        packet.pitch = pitchWord;
        packet.yaw = 0;
        packet.bone = (uint)&packet.pitch;
        packet.roll = 0;
        *(uint**)&deltaSeconds = &packet.bone;
        constructName((FName*)&packet.bone, nativeTextR6RHand, 1); // R6 R Hand.
        rotatePacket(retainedRotation, instance);
        headPawn = frame.pawn; // Reload even when updateHead is clear.
    } else {
        // Native reads this import even when no bone update follows.
        constructName = reinterpret_cast<NameConstructor&>(FNameConstructorImport);
    }
    if (updateHead != 0) {
        UMesh* mesh = headPawn->Mesh;
        USkeletalMeshInstance* instance = static_cast<USkeletalMeshInstance*>(mesh->MeshGetInstance(headPawn));
        int pitchWord = head.Pitch;
        prepareFlags();
        packet.pitch = pitchWord;
        int rollWord = head.Roll;
        int yawWord = head.Yaw;
        packet.yaw = yawWord;
        packet.bone = (uint)&packet.pitch;
        packet.roll = rollWord;
        *(uint**)&deltaSeconds = &packet.bone;
        constructName((FName*)&packet.bone, nativeTextR6Head, 1); // R6 Head.
        rotatePacket(reinterpret_cast<BoneRotation&>(USkeletalMeshInstanceSetBoneRotationImport), instance);
    }
    ExceptionList = frame.previousExceptionList; // RET 4; no local cleanup, angle rollback or mesh/instance null guard.
}

// R6Engine.dll @ 10029a88 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6TerroristUpdateAimingCatchPointer(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x24]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea ecx,[ebp-0x1c]
        push ecx
        mov dword ptr [ebp-0x1c],eax
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10029a9c : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6TerroristUpdateAimingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristUpdateAiming // L"AR6Terrorist::UpdateAiming".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044630 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void TerroristUpdateAimingExceptionHandler(void)
{
    __asm {
        mov eax,offset TerroristUpdateAimingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003cbf0 : AR6Terrorist::PreNetReceive
// Saves shared special-animation, health and DefCon bytes before entering the pawn receive hook.
void __thiscall AR6Terrorist::PreNetReceive(void)
{
    byte specialAnimation = this->m_eSpecialAnimValid;
    PreNetTerroristSpecialAnim = specialAnimation;
    byte health = this->m_eHealth;
    PreNetTerroristHealth = health;
    byte defCon = this->m_eDefCon; // Read before state 0; its global store occurs afterward.
    try {
        PreNetTerroristDefCon = defCon;
        this->AR6Pawn::PreNetReceive();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Terrorist::PreNetReceive");
        throw;
    } // Earlier cache writes are not restored on exception; the native map owns no local cleanup.
}

// R6Engine.dll @ 1003cc50 : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6TerroristPreNetReceiveCatchPointer(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea edx,[ebp-0x14]
        push edx
        mov dword ptr [ebp-0x14],ecx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003cc64 : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6TerroristPreNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristPreNetReceive // L"AR6Terrorist::PreNetReceive".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100450f0 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void TerroristPreNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset TerroristPreNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1003d0b0 : AR6Terrorist::PostNetReceive
// Dispatches changed special-animation modes, refreshes changed health/DefCon animation and enters the pawn hook.
void __thiscall AR6Terrorist::PostNetReceive(void)
{
    byte specialAnimation = this->m_eSpecialAnimValid;
    bool changedSpecialAnimation = PreNetTerroristSpecialAnim != specialAnimation; // Before state 0.
    try {
        if (changedSpecialAnimation && specialAnimation <= 2) {
            uint nameWord;
            if (specialAnimation == 0)
                nameWord = reinterpret_cast<const uint&>(R6ENGINE_StopSpecialAnim);
            else if (specialAnimation == 1)
                nameWord = reinterpret_cast<const uint&>(R6ENGINE_PlaySpecialAnim);
            else
                nameWord = reinterpret_cast<const uint&>(R6ENGINE_LoopSpecialAnim);
            UFunction* function = UObject::FindFunctionChecked(this, *(FName*)&nameWord, 0);
            byte* dispatchTable = *(byte**)this; // This path reloads the table AFTER lookup, unlike the event wrappers.
            using Dispatch = void (__thiscall*)(UObject*, UFunction*, void*, void*);
            (*(Dispatch*)(dispatchTable + 0x10))(this, function, nullptr, nullptr);
        }
        // These shared cache bytes and pawn fields reload after event dispatch; no per-pawn snapshot is substituted.
        if (PreNetTerroristHealth != this->m_eHealth || PreNetTerroristDefCon != this->m_eDefCon)
            APawn::eventChangeAnimation(this);
        this->AR6Pawn::PostNetReceive();
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6Terrorist::PostNetReceive");
        throw;
    }
}

// R6Engine.dll @ 1003d15b : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void AR6TerroristPostNetReceiveCatchPointer(void)
{
    __asm {
        mov edx,dword ptr [ebp-0x18]
        push offset unsignedShortPointerThrowInfo // Pointer ThrowInfo.
        lea eax,[ebp-0x14]
        push eax
        mov dword ptr [ebp-0x14],edx
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1003d16f : report method context and rethrow without adding a funclet frame
__declspec(naked) void AR6TerroristPostNetReceiveCatchContext(void)
{
    __asm {
        push offset nativeTextAR6TerroristPostNetReceive // L"AR6Terrorist::PostNetReceive".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10045120 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void TerroristPostNetReceiveExceptionHandler(void)
{
    __asm {
        mov eax,offset TerroristPostNetReceiveFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045c20 : InitializeTerroristClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeTerroristClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred saved within-class word at entryESP-4.
        UClass* withinClass;
    } captures;
    struct ClassPacketView { // Inferred 60-byte outgoing UClass packet at entryESP-0x50.
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
        union { // entryESP-0x18 is reused for the later _atexit argument.
            uint staticConstructorWord;
            void (__cdecl* exitCallback)(void);
        };
    } packet;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6Terrorist::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6Terrorist;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Pawn::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xa9c;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6Terrorist::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6TerroristClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045ca0 : PublishTerroristAutoClass
// Publishes the class object to the exported automatic-class alias after its metadata initializer.
void __cdecl PublishTerroristAutoClass(void)
{
    autoclassAR6Terrorist = &AR6Terrorist::PrivateStaticClass;
}

// R6Engine.dll @ 10047f90 : DestroyAR6TerroristClassMetadata
// Tail-enters UClass destruction on the persistent class object when the registered exit callback runs.
__declspec(naked) void __cdecl DestroyAR6TerroristClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Terrorist::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}
