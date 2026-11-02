#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a0d0 : AR6RainbowVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6Rainbow::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6RainbowVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 10051e04 : nativeTextAR6RainbowUpdateAiming
extern const ushort nativeTextAR6RainbowUpdateAiming[25];

// R6Engine.dll data @ 1005562e : nativeTextR6Rainbow
extern const ushort nativeTextR6Rainbow[10];

// Native helper declarations match the canonical definitions below.
__declspec(naked) void RainbowCtorExceptionHandler(void);
__declspec(naked) void RainbowCtorState0Cleanup(void);
__declspec(naked) void RainbowCtorState1Cleanup(void);
__declspec(naked) void RainbowCtorState2Cleanup(void);
__declspec(naked) void RainbowCtorState3Cleanup(void);
__declspec(naked) void RainbowCtorState4Cleanup(void);
__declspec(naked) void RainbowCtorState5Cleanup(void);
__declspec(naked) void RainbowCtorState6Cleanup(void);
__declspec(naked) void RainbowCtorState7Cleanup(void);
__declspec(naked) void RainbowCtorState8Cleanup(void);
__declspec(naked) void RainbowDtorExceptionHandler(void);
__declspec(naked) void RainbowDtorState0Cleanup(void);
__declspec(naked) void RainbowDtorState1Cleanup(void);
__declspec(naked) void RainbowDtorState2Cleanup(void);
__declspec(naked) void RainbowDtorState3Cleanup(void);
__declspec(naked) void RainbowDtorState4Cleanup(void);
__declspec(naked) void RainbowDtorState5Cleanup(void);
__declspec(naked) void RainbowDtorState6Cleanup(void);
__declspec(naked) void RainbowDtorState7Cleanup(void);
__declspec(naked) void RainbowDtorState8Cleanup(void);
__declspec(naked) void RainbowDtorState9Cleanup(void);
__declspec(naked) void RainbowUpdateAimingExceptionHandler(void);
__declspec(naked) void UpdateAimingCatchContext(void);
__declspec(naked) void UpdateAimingCatchPointer(void);

// R6Engine.dll data @ 1005bc54 : updateAimingUnwindMap
// Both states have no owned local cleanup.
const NativeUnwindEntry updateAimingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005bc64 : updateAimingCatchMap
// Typed pointer catch precedes the context catch.
const NativeCatchEntry updateAimingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&UpdateAimingCatchPointer) },
    { 0, 0, 0, ((uint)&UpdateAimingCatchContext) }
};

// R6Engine.dll data @ 1005bc84 : updateAimingTryMap
// State zero is protected by the typed and context catches.
const NativeTryBlock updateAimingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&updateAimingCatchMap) }
};

// R6Engine.dll data @ 1005bc98 : updateAimingFuncInfo
// Connects the parent frame to its cleanup-free catch tables.
const NativeFunctionInfoPrefix updateAimingFuncInfo = { 0x19930520, 0x2, ((uint)&updateAimingUnwindMap), 0x1,
    ((uint)&updateAimingTryMap), 0 };

// R6Engine.dll data @ 10056ae0 : rainbowDtorUnwind
// States retain the remaining string prefix and Pawn base during reverse destruction.
const NativeUnwindEntry rainbowDtorUnwind[10] = {
    { -1, ((uint)&RainbowDtorState0Cleanup) },
    { 0, ((uint)&RainbowDtorState1Cleanup) },
    { 0x1, ((uint)&RainbowDtorState2Cleanup) },
    { 0x2, ((uint)&RainbowDtorState3Cleanup) },
    { 0x3, ((uint)&RainbowDtorState4Cleanup) },
    { 0x4, ((uint)&RainbowDtorState5Cleanup) },
    { 0x5, ((uint)&RainbowDtorState6Cleanup) },
    { 0x6, ((uint)&RainbowDtorState7Cleanup) },
    { 0x7, ((uint)&RainbowDtorState8Cleanup) },
    { 0x8, ((uint)&RainbowDtorState9Cleanup) }
};

// R6Engine.dll data @ 10056b30 : rainbowDtorInfo
// Destruction has ten cleanup states and no catches.
const NativeFunctionInfoPrefix rainbowDtorInfo = { 0x19930520, 0xa, ((uint)&rainbowDtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 10056bb0 : rainbowCtorUnwind
// Both constructors clean the completed string prefix and Pawn base.
const NativeUnwindEntry rainbowCtorUnwind[9] = {
    { -1, ((uint)&RainbowCtorState0Cleanup) },
    { 0, ((uint)&RainbowCtorState1Cleanup) },
    { 0x1, ((uint)&RainbowCtorState2Cleanup) },
    { 0x2, ((uint)&RainbowCtorState3Cleanup) },
    { 0x3, ((uint)&RainbowCtorState4Cleanup) },
    { 0x4, ((uint)&RainbowCtorState5Cleanup) },
    { 0x5, ((uint)&RainbowCtorState6Cleanup) },
    { 0x6, ((uint)&RainbowCtorState7Cleanup) },
    { 0x7, ((uint)&RainbowCtorState8Cleanup) }
};

// R6Engine.dll data @ 10056bf8 : rainbowCtorInfo
// Default and copy construction share nine cleanup states and no catches.
const NativeFunctionInfoPrefix rainbowCtorInfo = { 0x19930520, 0x9, ((uint)&rainbowCtorUnwind), 0, 0, 0 };

// R6Engine.dll data @ 1007da04 : autoclassAR6Rainbow
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6Rainbow = nullptr;

// R6Engine.dll @ 10005700 : AR6Rainbow::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6Rainbow::StaticClass(void)
{
    return &AR6Rainbow::PrivateStaticClass; // Selected object at0x10080d20.
}

// R6Engine.dll @ 10005710 : AR6Rainbow::operator new
// Forwards the class, captured object parameters and current GError; the incoming size word is unused.
void* __cdecl AR6Rainbow::operator_new(uint allocationSize, UObject* outer,
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
    packet.classObject = &AR6Rainbow::PrivateStaticClass;
    return UObject::StaticAllocateObject(packet.classObject, packet.outer, packet.objectName, packet.objectFlags,
        packet.templateObject, packet.error, packet.extraObject, packet.finalZero);
}

// R6Engine.dll @ 10005740 : AR6Rainbow::~AR6Rainbow
// Conditionally destroys UObject state, destroys nine strings in reverse order and then destroys the Pawn base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6Rainbow::~AR6Rainbow(AR6Rainbow* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&RainbowDtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    *(uint*)this = ((uint)&AR6RainbowVirtualTable);
    guard[3] = 9;
    this->UObject::ConditionalDestroy();
    for (uint remaining = 9; remaining != 0; --remaining) {
        *(byte*)&guard[3] = (byte)(remaining - 1);
        reinterpret_cast<FStringNoInit*>((byte*)this + 0xaa8 + (remaining - 1) * 12)->FStringNoInit::~FStringNoInit();
    }
    guard[3] = 0xffffffff;
    this->AR6Pawn::~AR6Pawn();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10005830 : AR6Rainbow::AR6Rainbow (native default-constructor view)
// Constructs the imported abstract-pawn base and nine strings with completed-prefix cleanup coverage.
// Native ABI view preserves the explicit base/member lifetimes and staged exceptional cleanup.
AR6Rainbow* __thiscall AR6Rainbow::AR6Rainbow(AR6Rainbow* this)
{
    uint guard[4]; // Exact shared constructor saved-this/previous SEH/handler/state view.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&RainbowCtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6AbstractPawn::AR6AbstractPawn(this); // Native bypasses the intermediate Pawn constructor.
    guard[3] = 0;
    *(uint*)this = ((uint)&AR6RainbowVirtualTable);
    for (uint index = 0; index != 9; ++index) {
        if (index != 0) *(byte*)&guard[3] = (byte)index;
        ::new (reinterpret_cast<void*>((byte*)this + 0xaa8 + index * 12)) FStringNoInit;
    }
    ExceptionList = (void*)guard[1];
    return this; // No scalar default initialization or additional final-string cleanup state.
}

// R6Engine.dll @ 10005910 : AR6Rainbow::AR6Rainbow (native copy-constructor view)
// Copies Pawn state, raw fields and seventeen flags, then copies nine strings in forward order.
// Native ABI view retains the complete staged base/member construction and exceptional cleanup.
AR6Rainbow* __thiscall AR6Rainbow::AR6Rainbow(AR6Rainbow* this, const AR6Rainbow* source)
{
    uint guard[4]; // EBX/EBP/ESI/EDI save slots are outside this native guard; cleanup inherits saved this at -0x10.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&RainbowCtorExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    using CopyPawnBase = AR6Pawn* (__thiscall*)(AR6Pawn*, const AR6Pawn*);
    reinterpret_cast<CopyPawnBase>(&AR6PawnCopyConstructorNativeEntry)(this, source);
    *(uint*)this = ((uint)&AR6RainbowVirtualTable);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0xa28; offset < 0xa2e; ++offset) destination[offset] = input[offset];
    for (uint offset = 0xa30; offset < 0xa38; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint kills = *(const uint*)(input + 0xa38);
    uint firstFlags = *(uint*)(destination + 0xa50); // First sample precedes m_iKills publication.
    reinterpret_cast<uint&>(this->m_iKills) = kills;
    for (uint offset = 0xa3c; offset < 0xa48; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint extraClips = *(const uint*)(input + 0xa48);
    uint earlyFlags = *(uint*)(destination + 0xa50); // Sample precedes extra-secondary-clips and face-ID stores.
    reinterpret_cast<uint&>(this->m_iExtraSecondaryClips) = extraClips;
    reinterpret_cast<uint&>(this->m_iRainbowFaceID) = *(const uint*)(input + 0xa4c);
    uint difference = earlyFlags ^ *(const uint*)(input + 0xa50);
    uint flags = firstFlags ^ (difference & 1U);
    *(uint*)(destination + 0xa50) = flags;
    for (uint mask = 2; mask != 0x20000; mask <<= 1) {
        difference = *(const uint*)(input + 0xa50) ^ flags;
        if (mask == 0x80) guard[3] = 0; // Base cleanup activates after the eighth source read and XOR.
        flags ^= difference & mask;
        *(uint*)(destination + 0xa50) = flags; // Seventeen stores; preserve upper fifteen destination bits.
    }
    // Raw references, fixed hostage pointers, rotator, face-coordinate structure and starting-location words.
    for (uint offset = 0xa54; offset < 0xaa8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    for (uint index = 0; index != 9; ++index) {
        if (index != 0) *(byte*)&guard[3] = (byte)index;
        ::new (reinterpret_cast<void*>(destination + 0xaa8 + index * 12)) FStringNoInit(
            *reinterpret_cast<const FStringNoInit*>(input + 0xaa8 + index * 12));
    }
    ExceptionList = (void*)guard[1];
    return this; // Native has no self-assignment shortcut; imported string results are ignored.
}

// R6Engine.dll @ 10005d20 : AR6Rainbow::operator=
// Copies Pawn state, raw fields and seventeen flags, then copies nine strings in forward order.
AR6Rainbow& __thiscall AR6Rainbow::operator=(const AR6Rainbow& sourceObject)
{
    const AR6Rainbow* source = &sourceObject;
    this->AR6Pawn::operator=(*source);
    byte* destination = (byte*)this;
    const byte* input = (const byte*)source;
    for (uint offset = 0xa28; offset < 0xa2e; ++offset) destination[offset] = input[offset];
    for (uint offset = 0xa30; offset < 0xa48; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    uint extraClips = *(const uint*)(input + 0xa48);
    uint earlyFlags = *(uint*)(destination + 0xa50); // Sample precedes extra-secondary-clips and face-ID stores.
    reinterpret_cast<uint&>(this->m_iExtraSecondaryClips) = extraClips;
    reinterpret_cast<uint&>(this->m_iRainbowFaceID) = *(const uint*)(input + 0xa4c);
    uint difference = earlyFlags ^ *(const uint*)(input + 0xa50);
    uint flags = *(uint*)(destination + 0xa50) ^ (difference & 1U);
    *(uint*)(destination + 0xa50) = flags;
    for (uint mask = 2; mask != 0x20000; mask <<= 1) {
        difference = *(const uint*)(input + 0xa50) ^ flags;
        flags ^= difference & mask;
        *(uint*)(destination + 0xa50) = flags; // Seventeen stores; preserve upper fifteen destination bits.
    }
    // Raw references, fixed hostage pointers, rotator, face-coordinate structure and starting-location words.
    for (uint offset = 0xa54; offset < 0xaa8; offset += 4)
        *(uint*)(destination + offset) = *(const uint*)(input + offset);
    for (uint index = 0; index != 9; ++index) {
        const FStringNoInit* sourceString = reinterpret_cast<const FStringNoInit*>(input + 0xaa8 + index * 12);
        FStringNoInit* destinationString = reinterpret_cast<FStringNoInit*>(destination + 0xaa8 + index * 12);
        *destinationString = *sourceString;
    }
    return *this; // Native has no self-assignment shortcut; imported string results are ignored.
}

// R6Engine.dll @ 1000dc00 : AR6Rainbow::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6Rainbow::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6RainbowConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1002d9e0 : AR6Rainbow::UpdateAiming
// Copies changed aiming bytes into the current pair before applying their unsigned eight-bit-scaled rotation.
void __thiscall AR6Rainbow::UpdateAiming(void)
{
    struct NativeFrameView { // Descriptive inherited EBP-relative frame; no owned local objects.
        uint savedEdi, savedEsi, savedEbx; // EBP-0x24/-0x20/-0x1c.
        uint caught, rethrow; // EBP-0x18/-0x14.
        void* savedEsp; // EBP-0x10.
        void* previousExceptionList; // EBP-0x0c.
        void* handler; // EBP-0x08.
        int state; // EBP-0x04.
    } frame;
    frame.state = -1;
    frame.handler = (void*)&RainbowUpdateAimingExceptionHandler;
    frame.previousExceptionList = ExceptionList;
    ExceptionList = &frame.previousExceptionList;
    byte desiredYaw = this->m_u8DesiredYaw; // +0xa2a.
    bool changed = this->m_u8CurrentYaw != desiredYaw; // +0xa2b; compared before state 0.
    frame.savedEsp = &frame.savedEdi;
    frame.state = 0;
    if (!changed) {
        byte currentPitch = this->m_u8CurrentPitch; // +0xa29.
        changed = currentPitch != this->m_u8DesiredPitch; // +0xa28, read only if yaw matched.
    }
    if (changed) {
        byte desiredPitch = this->m_u8DesiredPitch; // Native reloads pitch on the changed path.
        this->m_u8CurrentPitch = desiredPitch;
        this->m_u8CurrentYaw = desiredYaw;
        FRotator relative = {(int)((uint)desiredPitch << 8), (int)((uint)desiredYaw << 8), 0};
        this->AR6Pawn::PawnLook(relative, 1, 0); // Aim enabled, blending allowed; no post-callback stores.
    }
    ExceptionList = frame.previousExceptionList; // Also restores on no-change; no local cleanup or byte-store rollback.
}

// R6Engine.dll @ 1002da6a : rethrow the parent's caught pointer using its inherited EBP frame
__declspec(naked) void UpdateAimingCatchPointer(void)
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

// R6Engine.dll @ 1002da7e : report method context and rethrow without adding a funclet frame
__declspec(naked) void UpdateAimingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6RainbowUpdateAiming // L"AR6Rainbow::UpdateAiming".
        push offset unwindStringFormat // L"%s".
        call dword ptr [CoreAppUnwindfImport] // appUnwindf.
        add esp,8
        push 0
        push 0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044790 : select the parent's exception tables and retain the native handler ABI
__declspec(naked) void RainbowUpdateAimingExceptionHandler(void)
{
    __asm {
        mov eax,offset updateAimingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043010 : RainbowDtorState0Cleanup
// Destroys the Pawn base through the inherited parent frame.
__declspec(naked) void RainbowDtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 10043018 : RainbowDtorState1Cleanup
// Destroys the owned string at +0xaa8 through the inherited parent frame.
__declspec(naked) void RainbowDtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xaa8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043027 : RainbowDtorState2Cleanup
// Destroys the owned string at +0xab4 through the inherited parent frame.
__declspec(naked) void RainbowDtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xab4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043036 : RainbowDtorState3Cleanup
// Destroys the owned string at +0xac0 through the inherited parent frame.
__declspec(naked) void RainbowDtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xac0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043045 : RainbowDtorState4Cleanup
// Destroys the owned string at +0xacc through the inherited parent frame.
__declspec(naked) void RainbowDtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xacc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043054 : RainbowDtorState5Cleanup
// Destroys the owned string at +0xad8 through the inherited parent frame.
__declspec(naked) void RainbowDtorState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xad8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043063 : RainbowDtorState6Cleanup
// Destroys the owned string at +0xae4 through the inherited parent frame.
__declspec(naked) void RainbowDtorState6Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xae4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043072 : RainbowDtorState7Cleanup
// Destroys the owned string at +0xaf0 through the inherited parent frame.
__declspec(naked) void RainbowDtorState7Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xaf0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043081 : RainbowDtorState8Cleanup
// Destroys the owned string at +0xafc through the inherited parent frame.
__declspec(naked) void RainbowDtorState8Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xafc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043090 : RainbowDtorState9Cleanup
// Destroys the owned string at +0xb08 through the inherited parent frame.
__declspec(naked) void RainbowDtorState9Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xb08
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 1004309f : RainbowDtorExceptionHandler
// Selects destructor cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void RainbowDtorExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowDtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100430b0 : RainbowCtorState0Cleanup
// Destroys the Pawn base through the inherited parent frame.
__declspec(naked) void RainbowCtorState0Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        jmp AR6PawnDestructorNativeEntry
    }
}

// R6Engine.dll @ 100430b8 : RainbowCtorState1Cleanup
// Destroys the owned string at +0xaa8 through the inherited parent frame.
__declspec(naked) void RainbowCtorState1Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xaa8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100430c7 : RainbowCtorState2Cleanup
// Destroys the owned string at +0xab4 through the inherited parent frame.
__declspec(naked) void RainbowCtorState2Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xab4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100430d6 : RainbowCtorState3Cleanup
// Destroys the owned string at +0xac0 through the inherited parent frame.
__declspec(naked) void RainbowCtorState3Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xac0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100430e5 : RainbowCtorState4Cleanup
// Destroys the owned string at +0xacc through the inherited parent frame.
__declspec(naked) void RainbowCtorState4Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xacc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 100430f4 : RainbowCtorState5Cleanup
// Destroys the owned string at +0xad8 through the inherited parent frame.
__declspec(naked) void RainbowCtorState5Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xad8
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043103 : RainbowCtorState6Cleanup
// Destroys the owned string at +0xae4 through the inherited parent frame.
__declspec(naked) void RainbowCtorState6Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xae4
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043112 : RainbowCtorState7Cleanup
// Destroys the owned string at +0xaf0 through the inherited parent frame.
__declspec(naked) void RainbowCtorState7Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xaf0
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043121 : RainbowCtorState8Cleanup
// Destroys the owned string at +0xafc through the inherited parent frame.
__declspec(naked) void RainbowCtorState8Cleanup(void)
{
    __asm {
        mov ecx,dword ptr [ebp-0x10]
        add ecx,0xafc
        jmp dword ptr [FStringNoInitDestructorImport]
    }
}

// R6Engine.dll @ 10043130 : RainbowCtorExceptionHandler
// Selects shared constructor cleanup metadata and tail-enters the exception dispatcher.
__declspec(naked) void RainbowCtorExceptionHandler(void)
{
    __asm {
        mov eax,offset rainbowCtorInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10047fa0 : DestroyAR6RainbowClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6RainbowClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6Rainbow::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10045cb0 : InitializeAR6RainbowClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6RainbowClassMetadata(void)
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
    packet.internalConstructor = &AR6Rainbow::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    packet.configName = UObject::StaticConfigName();
    withinClass = captures.withinClass; // Reload after the returned configuration pointer has been placed.
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6Rainbow;
    packet.withinClass = withinClass;
    packet.parentClass = &AR6Pawn::PrivateStaticClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0xb14;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6Rainbow::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6RainbowClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 10045d30 : PublishAR6RainbowAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6RainbowAutoClass(void)
{
    autoclassAR6Rainbow = &AR6Rainbow::PrivateStaticClass;
}

// R6Engine.dll @ 100060d0 : AR6Rainbow::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees its storage and returns the storage pointer.
void* __thiscall AR6Rainbow::DeletingDestructor(uint flags)
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
        packet.destroy = (Destructor)&AR6RainbowDestructorNativeEntry;
        byte* cookie = (byte*)this - 4;
        packet.count = count;
        packet.stride = 0xb14;
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
    this->AR6Rainbow::~AR6Rainbow();
    if ((deleteFlags & 1U) != 0) {
        struct DeletePacketView { // Inferred two-word cdecl packet at entryESP-0x10.
            void* object;
            uint size;
        } packet;
        packet.size = 0xb14;
        packet.object = this;
        UObject::operator delete(packet.object, packet.size);
    }
    return this; // Both paths preserve their storage pointer even after deallocation.
}
