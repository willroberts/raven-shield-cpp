#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl MatineeTestExceptionHandler(void);
__declspec(naked) void __cdecl MatineeBoneExceptionHandler(void);
__declspec(naked) void __cdecl DestroyUR6MatineeAttachClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004c3b8 : UR6MatineeAttachVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: UR6MatineeAttach::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix UR6MatineeAttachVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10055e52 : nativeTextR6MatineeAttach
extern const ushort nativeTextR6MatineeAttach[16];

// R6Engine.dll data @ 10055cb0 : nativeTextUR6MatineeAttachInitPositionTags
extern const ushort nativeTextUR6MatineeAttachInitPositionTags[35];

// R6Engine.dll data @ 10055af0 : nativeTextUR6SubActionAttachActorExecTestLocation
extern const ushort nativeTextUR6SubActionAttachActorExecTestLocation[42];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void __cdecl MatineeAttachDestructionExceptionHandler(void);
__declspec(naked) void __cdecl MatineeAttachDtorState0Cleanup(void);
__declspec(naked) void __cdecl MatineeAttachDtorState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl MatineeBoneCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl MatineeBoneCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl MatineeTestCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl MatineeTestCatchPointer(void);

// R6Engine.dll data @ 1005e748 : matineeTestUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry matineeTestUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e758 : matineeTestCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry matineeTestCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&MatineeTestCatchPointer) },
    { 0, 0, 0, ((uint)&MatineeTestCatchContext) }
};

// R6Engine.dll data @ 1005e778 : matineeTestTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock matineeTestTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&matineeTestCatchMap) }
};

// R6Engine.dll data @ 1005e78c : matineeTestFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix matineeTestFuncInfo = { 0x19930520, 0x2, ((uint)&matineeTestUnwindMap), 0x1,
    ((uint)&matineeTestTryMap), 0 };

// R6Engine.dll data @ 1005e964 : matineeBoneUnwindMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeUnwindEntry matineeBoneUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005e974 : matineeBoneCatchMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeCatchEntry matineeBoneCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&MatineeBoneCatchPointer) },
    { 0, 0, 0, ((uint)&MatineeBoneCatchContext) }
};

// R6Engine.dll data @ 1005e994 : matineeBoneTryMap
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeTryBlock matineeBoneTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&matineeBoneCatchMap) }
};

// R6Engine.dll data @ 1005e9a8 : matineeBoneFuncInfo
// Retains exact no-local-cleanup states and inherited catch-frame bindings.
const NativeFunctionInfoPrefix matineeBoneFuncInfo = { 0x19930520, 0x2, ((uint)&matineeBoneUnwindMap), 0x1,
    ((uint)&matineeBoneTryMap), 0 };

// R6Engine.dll data @ 100570e8 : matineeAttachDtorUnwind
// Retains pending mesh-tag/base cleanup, without catches.
const NativeUnwindEntry matineeAttachDtorUnwind[2] = {
    { -1, ((uint)&MatineeAttachDtorState0Cleanup) },
    { 0, ((uint)&MatineeAttachDtorState1Cleanup) }
};

// R6Engine.dll data @ 100570f8 : matineeAttachDtorInfo
// Retains pending mesh-tag/base cleanup, without catches.
const NativeFunctionInfoPrefix matineeAttachDtorInfo = { 0x19930520, 0x2, ((uint)&matineeAttachDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 100844ec : autoclassUR6MatineeAttach
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassUR6MatineeAttach = nullptr;

// R6Engine.dll data @ 100743d8 : intUR6MatineeAttachexecTestLocation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intUR6MatineeAttachexecTestLocation = (Native)&UR6MatineeAttach::execTestLocation;

// R6Engine.dll data @ 10080806 : UR6MatineeAttachTestLocationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte UR6MatineeAttachTestLocationRegistrationResult = 0;

// R6Engine.dll data @ 100743dc : intUR6MatineeAttachexecGetBoneInformation
// Exported four-byte member-callback word; registration passes its address to Core.
extern "C" Native intUR6MatineeAttachexecGetBoneInformation = (Native)&UR6MatineeAttach::execGetBoneInformation;

// R6Engine.dll data @ 1007b131 : UR6MatineeAttachGetBoneInformationRegistrationResult
// Loader zero-fill precedes the registration callback's verbatim byte-result store.
byte UR6MatineeAttachGetBoneInformationRegistrationResult = 0;

// R6Engine.dll @ 1000aae0 : UR6MatineeAttach::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl UR6MatineeAttach::StaticClass(void)
{
    return &UR6MatineeAttach::PrivateStaticClass; // Selected object at0x10083ad0.
}

// R6Engine.dll @ 1000aaf0 : UR6MatineeAttach::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl UR6MatineeAttach::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &UR6MatineeAttach::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 1000ab20 : UR6MatineeAttach::~UR6MatineeAttach
// Conditionally destroys UObject state, then destroys the mesh tag and UObject base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall UR6MatineeAttach::~UR6MatineeAttach(UR6MatineeAttach* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&MatineeAttachDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    *(uint*)this = ((uint)&UR6MatineeAttachVirtualTable);
    guard[3] = 1;
    this->UObject::ConditionalDestroy();
    *(byte*)&guard[3] = 0;
    reinterpret_cast<FStringNoInit*>(&this->m_StaticMeshTag)->FStringNoInit::~FStringNoInit();
    guard[3] = 0xffffffff;
    this->UObject::~UObject();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 1000ab80 : UR6MatineeAttach::UR6MatineeAttach (native default view)
// Constructs UObject and the no-init mesh tag, leaving other attachment fields untouched.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
UR6MatineeAttach* __thiscall UR6MatineeAttach::UR6MatineeAttach(UR6MatineeAttach* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ObjectBaseConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    guard[0] = (uint)this; // Native repeats the pushed receiver after saving ESI.
    UObject::UObject(this);
    guard[3] = 0;
    *(uint*)this = ((uint)&UR6MatineeAttachVirtualTable);
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_StaticMeshTag);
    ExceptionList = (void*)guard[1];
    return this;
}

// R6Engine.dll @ 1000abd0 : UR6MatineeAttach::copy constructor
// Copy-constructs attachment flags, references, raw transforms and the mesh tag in order.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
UR6MatineeAttach* __thiscall UR6MatineeAttach::UR6MatineeAttach(UR6MatineeAttach* this, const UR6MatineeAttach* source)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&ObjectBaseConstructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    const UR6MatineeAttach* capturedSource = source;
    const UR6MatineeAttach* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0x1c.
    guard[0] = (uint)this; // Native repeats saved-this placement after the outgoing argument.
    UObject::UObject(this, baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x2c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x2c);
    uint destinationWord = *destinationFlags; // Captured before derived vtable publication; no second destination read.
    *(uint*)this = ((uint)&UR6MatineeAttachVirtualTable);
    uint sourceWord = *sourceFlags;
    *destinationFlags = destinationWord ^ ((sourceWord ^ destinationWord) & 1U);
    this->m_AttachActor = capturedSource->m_AttachActor;
    this->m_AttachPawn = capturedSource->m_AttachPawn;
    reinterpret_cast<uint&>(this->m_PawnTag) = reinterpret_cast<const uint&>(capturedSource->m_PawnTag);
    reinterpret_cast<uint&>(this->m_BoneName) = reinterpret_cast<const uint&>(capturedSource->m_BoneName);
    reinterpret_cast<uint&>(this->m_InteractionPos.X) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.X);
    reinterpret_cast<uint&>(this->m_InteractionPos.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.Y);
    reinterpret_cast<uint&>(this->m_InteractionPos.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.Z);
    reinterpret_cast<uint&>(this->m_InteractionRot.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Pitch);
    reinterpret_cast<uint&>(this->m_InteractionRot.Yaw) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Yaw);
    reinterpret_cast<uint&>(this->m_InteractionRot.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Roll);
    reinterpret_cast<uint&>(this->m_OffsetPos.X) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.X);
    reinterpret_cast<uint&>(this->m_OffsetPos.Y) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.Y);
    reinterpret_cast<uint&>(this->m_OffsetPos.Z) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.Z);
    reinterpret_cast<uint&>(this->m_OffsetRot.Pitch) = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Pitch);
    reinterpret_cast<uint&>(this->m_OffsetRot.Yaw) = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Yaw);
    uint offsetRollWord = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Roll);
    const FStringNoInit* stringSourceArgument = (const FStringNoInit*)&capturedSource->m_StaticMeshTag;
    guard[3] = 0; // Native places the string argument before state0 and the final rotation store.
    reinterpret_cast<uint&>(this->m_OffsetRot.Roll) = offsetRollWord;
    FStringNoInit::FStringNoInit((FStringNoInit*)&this->m_StaticMeshTag, stringSourceArgument);
    ExceptionList = (void*)guard[1];
    return this; // Preserve original receiver and forward operations for aliased storage.
}

// R6Engine.dll @ 1000acb0 : UR6MatineeAttach::operator=
// Assigns attachment flags, references, raw transforms and the mesh tag in order.
UR6MatineeAttach& __thiscall UR6MatineeAttach::operator=(const UR6MatineeAttach& sourceObject)
{
    const UR6MatineeAttach* source = &sourceObject;
    const UR6MatineeAttach* capturedSource = source;
    const UR6MatineeAttach* baseSourceArgument = capturedSource; // Outgoing word at entryESP-0xc.
    UObject::operator=(*baseSourceArgument);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x2c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(capturedSource) + 0x2c);
    uint sourceWord = *sourceFlags;
    uint destinationWord = *destinationFlags;
    *destinationFlags = destinationWord ^ ((sourceWord ^ destinationWord) & 1U);
    this->m_AttachActor = capturedSource->m_AttachActor;
    this->m_AttachPawn = capturedSource->m_AttachPawn;
    reinterpret_cast<uint&>(this->m_PawnTag) = reinterpret_cast<const uint&>(capturedSource->m_PawnTag);
    reinterpret_cast<uint&>(this->m_BoneName) = reinterpret_cast<const uint&>(capturedSource->m_BoneName);
    reinterpret_cast<uint&>(this->m_InteractionPos.X) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.X);
    reinterpret_cast<uint&>(this->m_InteractionPos.Y) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.Y);
    reinterpret_cast<uint&>(this->m_InteractionPos.Z) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionPos.Z);
    reinterpret_cast<uint&>(this->m_InteractionRot.Pitch) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Pitch);
    reinterpret_cast<uint&>(this->m_InteractionRot.Yaw) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Yaw);
    reinterpret_cast<uint&>(this->m_InteractionRot.Roll) = reinterpret_cast<const
        uint&>(capturedSource->m_InteractionRot.Roll);
    reinterpret_cast<uint&>(this->m_OffsetPos.X) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.X);
    reinterpret_cast<uint&>(this->m_OffsetPos.Y) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.Y);
    reinterpret_cast<uint&>(this->m_OffsetPos.Z) = reinterpret_cast<const uint&>(capturedSource->m_OffsetPos.Z);
    reinterpret_cast<uint&>(this->m_OffsetRot.Pitch) = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Pitch);
    reinterpret_cast<uint&>(this->m_OffsetRot.Yaw) = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Yaw);
    uint offsetRollWord = reinterpret_cast<const uint&>(capturedSource->m_OffsetRot.Roll);
    const FStringNoInit* stringSourceArgument = (const FStringNoInit*)&capturedSource->m_StaticMeshTag;
    // Native places the string argument before this store.
    reinterpret_cast<uint&>(this->m_OffsetRot.Roll) = offsetRollWord;
    reinterpret_cast<FStringNoInit*>(&this->m_StaticMeshTag)->operator=(*stringSourceArgument);
    return *this; // Preserve original receiver and forward operations for aliased storage.
}

// R6Engine.dll @ 1000e010 : UR6MatineeAttach::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl UR6MatineeAttach::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp UR6MatineeAttachConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 10040ad0 : UR6MatineeAttach::execTestLocation
// Consumes the terminator and optional DebugInfo expression without accessing the result or receiver object.
void __thiscall UR6MatineeAttach::execTestLocation(FFrame& stack, void* unusedResult)
{
    // Descriptive frame: caught/rethrow EBP-18/-14; no owned locals require cleanup.
    struct TestLocationFrame {
        uint savedEDI, savedESI, savedEBX;
        uint caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &MatineeTestExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = &stack;
    byte* afterTerminator = frame->Code + 1;
    frame->Code = afterTerminator;
    byte nextToken = *afterTerminator;
    nativeFrame.savedEsp = &nativeFrame.savedEDI; // EBP-24.
    nativeFrame.exceptionState = 0;
    if (nextToken == 0x42) {
        UObject* receiver = frame->Object;
        struct DebugPacketView { // Inferred outgoing words at EBP-0x2c and EBP-0x28.
            FFrame* frame;
            void* result;
        } packet;
        packet.result = nullptr;
        frame->Code = afterTerminator + 1;
        packet.frame = frame;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
        ScriptNative debugInfo = natives[0x42];
        debugInfo(receiver, packet.frame, packet.result);
    }
    ExceptionList = nativeFrame.previousExceptionList;
}

// R6Engine.dll @ 10040b2f : MatineeTestCatchPointer
// Copies the caught text at EBP-18 into the parent's EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl MatineeTestCatchPointer(void)
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

// R6Engine.dll @ 10040b43 : MatineeTestCatchContext
// Reports the original native diagnostic and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl MatineeTestCatchContext(void)
{
    __asm {
        push offset nativeTextUR6SubActionAttachActorExecTestLocation
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10041250 : UR6MatineeAttach::execGetBoneInformation
// Caches the attached pawn tag's bone name and transform using raw native result buffers.
// Native ABI view retains the incoming frame word for the hidden bone-name output.
void __thiscall UR6MatineeAttach::execGetBoneInformation(FFrame* stack, void* unusedResult)
{
    // Descriptive frame: caught/rethrow EBP-18/-14; no owned locals require cleanup.
    struct BoneInformationFrame {
        uint savedEDI, savedESI, savedEBX;
        uint coordinates[12], rotation[3]; // EBP-54..-25 / EBP-24..-19; uninitialized raw FCoords/FRotator.
        uint caughtText, rethrowText;
        void* savedEsp;
        void* previousExceptionList;
        void* exceptionHandler;
        int exceptionState;
    } nativeFrame;
    nativeFrame.exceptionState = -1;
    nativeFrame.exceptionHandler = &MatineeBoneExceptionHandler;
    nativeFrame.previousExceptionList = ExceptionList;
    ExceptionList = &nativeFrame.previousExceptionList;
    FFrame* frame = stack;
    byte* afterTerminator = frame->Code + 1;
    frame->Code = afterTerminator;
    byte nextToken = *afterTerminator;
    nativeFrame.savedEsp = &nativeFrame.savedEDI; // EBP-60.
    nativeFrame.exceptionState = 0;
    if (nextToken == 0x42) {
        UObject* receiver = frame->Object;
        struct DebugPacketView { // Inferred outgoing words at EBP-0x68 and EBP-0x64.
            FFrame* frame;
            void* result;
        } packet;
        packet.result = nullptr;
        frame->Code = afterTerminator + 1;
        packet.frame = frame;
        using ScriptNative = void (__thiscall*)(UObject*, FFrame*, void*);
        ScriptNative* natives = *(ScriptNative**)&CoreGNativesImport;
        ScriptNative debugInfo = natives[0x42];
        debugInfo(receiver, packet.frame, packet.result);
    }
    byte* attachment = (byte*)this;
    AR6Pawn* pawn = this->m_AttachPawn;
    UMesh* mesh = pawn->Mesh;
    AR6Pawn* pawnArgument = pawn; // Outgoing word at EBP-0x64 precedes the current slot read.
    byte* instance = reinterpret_cast<byte*>(mesh->MeshGetInstance(pawnArgument));
    USkeletalMeshInstance* skeletalInstance = nullptr;
    if (instance != nullptr) {
        UClass* classEntry = reinterpret_cast<UObject*>(instance)->Class;
        UClass* expectedClass = USkeletalMeshInstancePrivateStaticClassImport;
        while (classEntry != nullptr && classEntry != expectedClass)
            classEntry = classEntry->GetSuperClass();
        if (classEntry == expectedClass) { // Includes the native null/null class case.
            skeletalInstance = reinterpret_cast<USkeletalMeshInstance*>(instance);
        }
    }
    uint firstTag = reinterpret_cast<uint&>(this->m_PawnTag);
    struct TagPacketView { // Inferred outgoing words at EBP-0x68 and EBP-0x64.
        uint* output;
        uint tag;
    } packet;
    packet.tag = firstTag;
    uint* boneSlot = (uint*)&stack; // Native hidden FName output overwrites the incoming FFrame word at EBP+8.
    packet.output = boneSlot;
    // Physical hidden-result views retain the incoming-word output alias and returned name pointer.
    uint* returnedBone = reinterpret_cast<uint*>(skeletalInstance->USkeletalMeshInstance::GetBoneName(
        reinterpret_cast<FName*>(packet.output), reinterpret_cast<FName&>(packet.tag)));
    uint boneWord = *returnedBone;
    uint currentTag = reinterpret_cast<uint&>(this->m_PawnTag);
    packet.tag = currentTag;
    packet.output = nativeFrame.coordinates;
    reinterpret_cast<uint&>(this->m_BoneName) = boneWord;
    // FCoords output stays in the supplied frame buffer; the returned pointer is ignored.
    skeletalInstance->USkeletalMeshInstance::GetTagPosition(
        reinterpret_cast<FCoords*>(packet.output), reinterpret_cast<FName&>(packet.tag));
    uint* rotationResultArgument = nativeFrame.rotation; // Outgoing word at EBP-0x64.
    const FRotator* rotation = &(*reinterpret_cast<FRotator*>(rotationResultArgument) =
        reinterpret_cast<const FCoords*>(nativeFrame.coordinates)->OrthoRotation());
    uint rotationX = reinterpret_cast<const uint&>(rotation->Pitch);
    *(uint*)(attachment + 0x64) = rotationX;
    uint rotationY = reinterpret_cast<const uint&>(rotation->Yaw);
    *(uint*)(attachment + 0x68) = rotationY;
    uint rotationZ = reinterpret_cast<const uint&>(rotation->Roll);
    uint positionY = nativeFrame.coordinates[1]; // Read before the third rotation store.
    *(uint*)(attachment + 0x6c) = rotationZ;
    uint positionX = nativeFrame.coordinates[0];
    uint positionZ = nativeFrame.coordinates[2];
    *(uint*)(attachment + 0x58) = positionX;
    void* previousChain = nativeFrame.previousExceptionList;
    *(uint*)(attachment + 0x5c) = positionY;
    *(uint*)(attachment + 0x60) = positionZ;
    ExceptionList = previousChain;
}

// R6Engine.dll @ 1004134a : MatineeBoneCatchPointer
// Copies the caught text at EBP-18 into the parent's EBP-14 rethrow packet.
__declspec(naked) __declspec(noreturn) void __cdecl MatineeBoneCatchPointer(void)
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

// R6Engine.dll @ 1004135e : MatineeBoneCatchContext
// Reports the original native diagnostic and forwards the active exception through the inherited frame.
__declspec(naked) __declspec(noreturn) void __cdecl MatineeBoneCatchContext(void)
{
    __asm {
        push offset nativeTextUR6MatineeAttachInitPositionTags
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100433e0 : MatineeAttachDtorState0Cleanup
// Destroys the saved UObject base through the inherited dispatcher frame.
__declspec(naked) void __cdecl MatineeAttachDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp dword ptr [UObjectDestructorImport]
    }
}

// R6Engine.dll @ 100433e9 : MatineeAttachDtorState1Cleanup
// Destroys the saved mesh tag through the inherited dispatcher frame.
__declspec(naked) void __cdecl MatineeAttachDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0x70
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10047dd0 : InitializeUR6MatineeAttachClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeUR6MatineeAttachClassMetadata(void)
{
    UClass* objectClass = UObjectPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred local words at entryESP-8 and entryESP-4.
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
    captures.withinClass = objectClass;
    captures.parentClass = objectClass; // Separate saved words initially receive the same captured UObject class.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &UR6MatineeAttach::InternalConstructor;
    packet.objectFlags = 0x04084004;
    const ushort* configName = UObject::StaticConfigName();
    UClass* withinClass = captures.withinClass;
    packet.configName = configName;
    UClass* parentClass = captures.parentClass; // Native reloads this saved word after placing the config result.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6MatineeAttach;
    packet.withinClass = withinClass;
    packet.guidWords[0] = 0;
    packet.parentClass = parentClass;
    packet.guidWords[1] = 0;
    packet.classFlags = 0;
    packet.guidWords[2] = 0;
    packet.classSize = 0x7c;
    packet.guidWords[3] = 0;
    packet.nativeConstructorTag = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&UR6MatineeAttach::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyUR6MatineeAttachClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100481f0 : DestroyUR6MatineeAttachClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyUR6MatineeAttachClassMetadata(void)
{
    __asm {
        mov ecx,offset UR6MatineeAttach::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 100471a0 : RegisterUR6MatineeAttachTestLocationNative
// Registers native index0xb5c using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterUR6MatineeAttachTestLocationNative(void)
{
    UR6MatineeAttachTestLocationRegistrationResult = GRegisterNative(0xb5c, intUR6MatineeAttachexecTestLocation);
}

// R6Engine.dll @ 100471c0 : RegisterUR6MatineeAttachGetBoneInformationNative
// Registers native index0xb5b using the exported member-callback word and retains Core's byte result.
void __cdecl RegisterUR6MatineeAttachGetBoneInformationNative(void)
{
    UR6MatineeAttachGetBoneInformationRegistrationResult =
        GRegisterNative(0xb5b, intUR6MatineeAttachexecGetBoneInformation);
}

// R6Engine.dll @ 10047e50 : PublishUR6MatineeAttachAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishUR6MatineeAttachAutoClass(void)
{
    autoclassUR6MatineeAttach = &UR6MatineeAttach::PrivateStaticClass;
}

// R6Engine.dll @ 100433f5 : MatineeAttachDestructionExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating a new dispatcher frame.
__declspec(naked) void __cdecl MatineeAttachDestructionExceptionHandler(void)
{
    __asm {
        mov eax,offset matineeAttachDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100454b0 : MatineeTestExceptionHandler
// Selects the exact MatineeAttach FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl MatineeTestExceptionHandler(void)
{
    __asm {
        mov eax,offset matineeTestFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10045510 : MatineeBoneExceptionHandler
// Selects the exact MatineeAttach FuncInfo and tail-enters the shared C++ dispatcher.
__declspec(naked) void __cdecl MatineeBoneExceptionHandler(void)
{
    __asm {
        mov eax,offset matineeBoneFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 1000ad60 : UR6MatineeAttach::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall UR6MatineeAttach::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&UR6MatineeAttachDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0x7c;
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
    this->UR6MatineeAttach::~UR6MatineeAttach();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0x7c;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
