#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_shared_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6ClimbablePointClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004a960 : AR6ClimbablePointVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6ClimbablePoint::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6ClimbablePointVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004ef10 : nativeTextAR6ClimbablePointAddReachspecs
extern const ushort nativeTextAR6ClimbablePointAddReachspecs[33];

// R6Engine.dll data @ 1004f008 : nativeTextAR6ClimbablePointClearPaths
extern const ushort nativeTextAR6ClimbablePointClearPaths[30];

// R6Engine.dll data @ 1004ef58 : nativeTextAR6ClimbablePointInitForPathFinding
extern const ushort nativeTextAR6ClimbablePointInitForPathFinding[40];

// R6Engine.dll data @ 1004f048 : nativeTextAR6ClimbablePointProscribedPathTo
extern const ushort nativeTextAR6ClimbablePointProscribedPathTo[36];

// R6Engine.dll data @ 10055a22 : nativeTextR6ClimbablePoint
extern const ushort nativeTextR6ClimbablePoint[17];

// R6Engine.dll data @ 1004efa8 : nativeTextR6ClimbablePointDoesnTHaveR6ClimbableObject
extern const ushort nativeTextR6ClimbablePointDoesnTHaveR6ClimbableObject[48];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointAddReachSpecsCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointAddReachSpecsCatchPointer(void);
__declspec(naked) void __cdecl ClimbablePointAddReachSpecsExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointClearPathsCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointClearPathsCatchPointer(void);
__declspec(naked) void __cdecl ClimbablePointClearPathsExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointInitPathFindingCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointInitPathFindingCatchPointer(void);
__declspec(naked) void __cdecl ClimbablePointInitPathFindingExceptionHandler(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointProscribedPathCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointProscribedPathCatchPointer(void);
__declspec(naked) void __cdecl ClimbablePointProscribedPathExceptionHandler(void);

// R6Engine.dll data @ 100588ac : climbablePointAddReachSpecsUnwindMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry climbablePointAddReachSpecsUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100588bc : climbablePointAddReachSpecsCatchMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry climbablePointAddReachSpecsCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbablePointAddReachSpecsCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbablePointAddReachSpecsCatchContext) }
};

// R6Engine.dll data @ 100588dc : climbablePointAddReachSpecsTryMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock climbablePointAddReachSpecsTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbablePointAddReachSpecsCatchMap) }
};

// R6Engine.dll data @ 100588f0 : climbablePointAddReachSpecsFuncInfo
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix climbablePointAddReachSpecsFuncInfo = {
    0x19930520, 0x2, ((uint)&climbablePointAddReachSpecsUnwindMap), 0x1, ((uint)&climbablePointAddReachSpecsTryMap), 0
};

// R6Engine.dll data @ 1005890c : climbablePointInitPathFindingUnwindMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry climbablePointInitPathFindingUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005891c : climbablePointInitPathFindingCatchMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry climbablePointInitPathFindingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbablePointInitPathFindingCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbablePointInitPathFindingCatchContext) }
};

// R6Engine.dll data @ 1005893c : climbablePointInitPathFindingTryMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock climbablePointInitPathFindingTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbablePointInitPathFindingCatchMap) }
};

// R6Engine.dll data @ 10058950 : climbablePointInitPathFindingFuncInfo
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix climbablePointInitPathFindingFuncInfo = {
    0x19930520, 0x2, ((uint)&climbablePointInitPathFindingUnwindMap), 0x1, ((uint)&climbablePointInitPathFindingTryMap),
        0
};

// R6Engine.dll data @ 1005896c : climbablePointClearPathsUnwindMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry climbablePointClearPathsUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 1005897c : climbablePointClearPathsCatchMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry climbablePointClearPathsCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbablePointClearPathsCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbablePointClearPathsCatchContext) }
};

// R6Engine.dll data @ 1005899c : climbablePointClearPathsTryMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock climbablePointClearPathsTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbablePointClearPathsCatchMap) }
};

// R6Engine.dll data @ 100589b0 : climbablePointClearPathsFuncInfo
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix climbablePointClearPathsFuncInfo = { 0x19930520, 0x2,
    ((uint)&climbablePointClearPathsUnwindMap), 0x1, ((uint)&climbablePointClearPathsTryMap), 0 };

// R6Engine.dll data @ 100589cc : climbablePointProscribedPathUnwindMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeUnwindEntry climbablePointProscribedPathUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100589dc : climbablePointProscribedPathCatchMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeCatchEntry climbablePointProscribedPathCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&ClimbablePointProscribedPathCatchPointer) },
    { 0, 0, 0, ((uint)&ClimbablePointProscribedPathCatchContext) }
};

// R6Engine.dll data @ 100589fc : climbablePointProscribedPathTryMap
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeTryBlock climbablePointProscribedPathTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&climbablePointProscribedPathCatchMap) }
};

// R6Engine.dll data @ 10058a10 : climbablePointProscribedPathFuncInfo
// Retains the navigation parent's catch-only states and exact typed/context catch bindings.
const NativeFunctionInfoPrefix climbablePointProscribedPathFuncInfo = {
    0x19930520, 0x2, ((uint)&climbablePointProscribedPathUnwindMap), 0x1, ((uint)&climbablePointProscribedPathTryMap), 0
};

// R6Engine.dll data @ 1007fdc0 : autoclassAR6ClimbablePoint
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6ClimbablePoint = nullptr;

// R6Engine.dll @ 10006ef0 : AR6ClimbablePoint::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6ClimbablePoint::StaticClass(void)
{
    return &AR6ClimbablePoint::PrivateStaticClass; // Selected object at0x1007a6e0.
}

// R6Engine.dll @ 10006f00 : AR6ClimbablePoint::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6ClimbablePoint::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    ulong capturedFlags = objectFlags; // Incoming ESP+10 precedes FName at +0c.
    FName capturedName = objectName;
    int zeroArgument7 = 0; // Outgoing ESP-4/-8/-0c precede the outer-object read.
    UObject* nullArgument6 = nullptr;
    FOutputDevice* errorArgument = (FOutputDevice*)error;
    UObject* outerArgument = outer;
    UObject* nullArgument4 = nullptr;
    ulong flagsArgument = capturedFlags;
    FName nameArgument = capturedName;
    // Eight cdecl words; the returned object pointer is unchanged.
    return UObject::StaticAllocateObject(&AR6ClimbablePoint::PrivateStaticClass, outerArgument, nameArgument,
        flagsArgument, nullArgument4, errorArgument, nullArgument6, zeroArgument7);
}

// R6Engine.dll @ 10006f30 : AR6ClimbablePoint::~AR6ClimbablePoint
// Conditionally destroys UObject state before destroying the NavigationPoint base.
// Native ABI view retains the explicit EH frame, vtable stores and complete cleanup sequence.
void __thiscall AR6ClimbablePoint::~AR6ClimbablePoint(AR6ClimbablePoint* this)
{
    uint guard[4]; // Native saved-this/previous SEH/handler/state stack view, not class fields.
    guard[3] = 0xffffffff;
    guard[2] = ((uint)&NavigationBaseOnlyDestructionExceptionHandler);
    guard[1] = (uint)ExceptionList;
    ExceptionList = &guard[1];
    guard[0] = (uint)this;
    AR6ClimbablePoint* capturedThis = this; // Retained in ESI across ConditionalDestroy.
    guard[0] = (uint)capturedThis; // Native repeats saved-this after PUSH ESI.
    *(uint*)capturedThis = ((uint)&AR6ClimbablePointVirtualTable);
    guard[3] = 0;
    capturedThis->UObject::ConditionalDestroy();
    ANavigationPoint* baseReceiver = capturedThis;
    guard[3] = 0xffffffff; // Full state word is disarmed before reading the current base-destructor import.
    baseReceiver->ANavigationPoint::~ANavigationPoint();
    ExceptionList = (void*)guard[1];
}

// R6Engine.dll @ 10006f90 : AR6ClimbablePoint::AR6ClimbablePoint()
// Constructs NavigationPoint and installs the climbable-point vtable, leaving all derived fields untouched.
AR6ClimbablePoint::AR6ClimbablePoint() : ANavigationPoint()
{
    // Publishes AR6ClimbablePointVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10006fb0 : AR6ClimbablePoint::AR6ClimbablePoint(const AR6ClimbablePoint&)
// Copies the base, installs the vtable and interleaves raw reads/stores for both links and the look vector.
AR6ClimbablePoint::AR6ClimbablePoint(const AR6ClimbablePoint& sourceObject) : ANavigationPoint(sourceObject)
{
    // Publishes AR6ClimbablePointVirtualTable after base construction; native EAX retains original storage.
    AR6ClimbablePoint* point = this;
    const AR6ClimbablePoint* source = &sourceObject;
    const AR6ClimbablePoint* capturedSource = source;
    point->m_climbableObj = capturedSource->m_climbableObj;
    point->m_connectedClimbablePoint = capturedSource->m_connectedClimbablePoint;
    reinterpret_cast<uint&>(point->m_vLookDir.X) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.X);
    reinterpret_cast<uint&>(point->m_vLookDir.Y) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.Y);
    reinterpret_cast<uint&>(point->m_vLookDir.Z) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.Z);
}

// R6Engine.dll @ 10007000 : AR6ClimbablePoint::operator=
// Assigns the base and raw links/look vector without replacing the vtable or skipping self-assignment.
AR6ClimbablePoint& __thiscall AR6ClimbablePoint::operator=(const AR6ClimbablePoint& sourceObject)
{
    AR6ClimbablePoint* point = this;
    const AR6ClimbablePoint* source = &sourceObject;
    const AR6ClimbablePoint* capturedSource = source;
    const ANavigationPoint* baseSourceArgument = capturedSource; // Outgoing entryESP-0c.
    point->ANavigationPoint::operator=(*baseSourceArgument);
    point->m_climbableObj = capturedSource->m_climbableObj;
    point->m_connectedClimbablePoint = capturedSource->m_connectedClimbablePoint;
    reinterpret_cast<uint&>(point->m_vLookDir.X) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.X);
    reinterpret_cast<uint&>(point->m_vLookDir.Y) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.Y);
    reinterpret_cast<uint&>(point->m_vLookDir.Z) = reinterpret_cast<const uint&>(capturedSource->m_vLookDir.Z);
    return *point;
}

// R6Engine.dll @ 10007050 : AR6ClimbablePoint::DeletingDestructor
// Destroys one point or a counted array, optionally frees storage, and returns the point or array-cookie address.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6ClimbablePoint::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Sample once before capturing the receiver.
    AR6ClimbablePoint* capturedPoint = this; // Retained in ESI across destruction and deallocation.
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(capturedPoint) - 4);
        using Destructor = void (__thiscall*)(void*);
        struct ArrayPacketView { // Inferred outgoing words at entryESP-0x1c..-0x10.
            void* elements;
            uint elementSize;
            int count;
            union { // The callback slot becomes the later allocator Free argument.
                Destructor callback;
                void* freeArgument;
            };
        } packet;
        packet.callback = reinterpret_cast<Destructor>(&AR6ClimbablePointDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(capturedPoint) - 4; // After count and callback placement.
        packet.count = count;
        packet.elementSize = 0x3fc;
        packet.elements = capturedPoint;
        _eh_vector_destructor_iterator_(packet.elements, packet.elementSize, packet.count, packet.callback);
        if ((deleteFlags & 1U) != 0) {
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport; // Fetch current GMalloc after element destruction.
            NativeAllocatorVtablePrefix* allocatorVTable = *reinterpret_cast<NativeAllocatorVtablePrefix**>(allocator);
            packet.freeArgument = cookie;
            using Free = void (__thiscall*)(void*, void*);
            Free free = reinterpret_cast<Free&>(allocatorVTable->freeAddress);
            free(allocator, packet.freeArgument);
        }
        return cookie;
    }
    capturedPoint->AR6ClimbablePoint::~AR6ClimbablePoint(); // Direct native10006f30 call.
    if ((deleteFlags & 1U) != 0) {
        uint sizeArgument = 0x3fc; // Outgoing entryESP-0x0c precedes the object at -0x10.
        void* objectArgument = capturedPoint;
        UObject::operator delete(objectArgument, sizeArgument);
    }
    return capturedPoint;
}

// R6Engine.dll @ 1000dc50 : AR6ClimbablePoint::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6ClimbablePoint::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6ClimbablePointConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 100165d0 : AR6ClimbablePoint::addReachSpecs
// Calls NavigationPoint's reach-spec builder with the pawn and full option word under the native catch frame.
void __thiscall AR6ClimbablePoint::addReachSpecs(APawn* pawn, int forwardedOption)
{
    AR6ClimbablePoint* point = this;
    struct NativeFrameView { // Inferred stack words at EBP-0x24..-4, including saved registers.
        uint savedEDI;
        uint savedESI;
        uint savedEBX;
        uint caughtPointer;
        uint rethrowPointer;
        uint savedESP;
        void* previousException;
        uint handler;
        uint state;
    } frame;
    frame.state = 0xffffffff;
    frame.handler = ((uint)&ClimbablePointAddReachSpecsExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    int capturedOption = forwardedOption; // Incoming EBP+0x0c is read before the pawn at +8.
    APawn* capturedPawn = pawn;
    frame.savedESP = (uint)&frame.savedEDI;
    int optionArgument = capturedOption; // Outgoing entryESP-0x2c precedes pawn at -0x30.
    APawn* pawnArgument = capturedPawn;
    frame.state = 0; // Full word, after preparing both arguments; no local objects require cleanup.
    using AddReachSpecs = void (__thiscall*)(ANavigationPoint*, APawn*, int);
    AddReachSpecs add = reinterpret_cast<AddReachSpecs&>(ANavigationPointAddReachSpecsImport);
    add(point, pawnArgument, optionArgument);
    ExceptionList = frame.previousException; // Native restores the chain without a separate state -1 store.
}

// R6Engine.dll @ 10016650 : AR6ClimbablePoint::InitForPathFinding
// Links to the opposite endpoint of the captured object or reports a missing object.
void __thiscall AR6ClimbablePoint::InitForPathFinding(void)
{
    AR6ClimbablePoint* point = this;
    struct NativeFrameView { // Inferred stack words at EBP-0x24..-4, including saved registers.
        uint savedEDI;
        uint savedESI;
        uint savedEBX;
        uint caughtPointer;
        uint rethrowPointer;
        uint savedESP;
        void* previousException;
        uint handler;
        uint state;
    } frame;
    frame.state = 0xffffffff;
    frame.handler = ((uint)&ClimbablePointInitPathFindingExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    AR6ClimbablePoint* capturedPoint = point;
    AR6ClimbableObject* object = capturedPoint->m_climbableObj;
    bool missingObject = object == nullptr; // Native link read/test precede state0.
    frame.savedESP = (uint)&frame.savedEDI;
    frame.state = 0;
    if (!missingObject) {
        AR6ClimbablePoint* inside = object->m_insideClimbablePoint;
        if (capturedPoint == inside)
            capturedPoint->m_connectedClimbablePoint = object->m_climbablePoint;
        else if (capturedPoint == object->m_climbablePoint)
            capturedPoint->m_connectedClimbablePoint = inside;
        void* previousException = frame.previousException;
        ExceptionList = previousException; // Both native link epilogues restore FS before reading saved registers.
        uint restoredEDI = frame.savedEDI;
        uint restoredESI = frame.savedESI;
        uint restoredEBX = frame.savedEBX;
        return;
    }
    FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
    byte* feedbackVTable = *(byte**)feedback;
    const ushort* messageArgument = nativeTextR6ClimbablePointDoesnTHaveR6ClimbableObject;
    AActor* actorArgument = capturedPoint;
    int severityArgument = 1; // Outgoing message/point/severity at entryESP-0x2c/-0x30/-0x34.
    using MapCheck = void (__thiscall*)(FFeedbackContext*, int, AActor*, const ushort*);
    MapCheck mapCheck = *(MapCheck*)(feedbackVTable + 0x28);
    mapCheck(feedback, severityArgument, actorArgument, messageArgument);
    void* previousException = frame.previousException;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException; // Report path restores FS after the two saved-register reads.
    uint restoredEBX = frame.savedEBX;
}

// R6Engine.dll @ 10016730 : AR6ClimbablePoint::ClearPaths
// Clears base paths, unlinks the first matching endpoint, then clears this point's object reference.
void __thiscall AR6ClimbablePoint::ClearPaths(void)
{
    AR6ClimbablePoint* point = this;
    struct NativeFrameView { // Inferred stack words at EBP-0x24..-4, including saved registers.
        uint savedEDI;
        uint savedESI;
        uint savedEBX;
        uint caughtPointer;
        uint rethrowPointer;
        uint savedESP;
        void* previousException;
        uint handler;
        uint state;
    } frame;
    frame.state = 0xffffffff;
    frame.handler = ((uint)&ClimbablePointClearPathsExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    frame.savedESP = (uint)&frame.savedEDI;
    AR6ClimbablePoint* capturedPoint = point; // Retained in ESI; EDI holds zero across the base call.
    frame.state = 0;
    using ClearBase = void (__thiscall*)(ANavigationPoint*);
    ClearBase clearBase = reinterpret_cast<ClearBase&>(ANavigationPointClearPathsImport);
    clearBase(capturedPoint);
    AR6ClimbableObject* object = capturedPoint->m_climbableObj; // Current link after base side effects.
    if (object != nullptr) {
        if (capturedPoint == object->m_insideClimbablePoint) object->m_insideClimbablePoint = nullptr;
        else if (capturedPoint == object->m_climbablePoint) object->m_climbablePoint = nullptr;
    }
    void* previousException = frame.previousException; // Captured before the final object-reference store.
    capturedPoint->m_climbableObj = nullptr;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException;
    uint restoredEBX = frame.savedEBX;
}

// R6Engine.dll @ 100167d0 : AR6ClimbablePoint::ProscribedPathTo
// Rejects another climbable point with the same object link, including null links; otherwise returns the base result.
int __thiscall AR6ClimbablePoint::ProscribedPathTo(ANavigationPoint* candidate)
{
    AR6ClimbablePoint* point = this;
    struct NativeFrameView { // Inferred stack words at EBP-0x24..-4, including saved registers.
        uint savedEDI;
        uint savedESI;
        uint savedEBX;
        uint caughtPointer;
        uint rethrowPointer;
        uint savedESP;
        void* previousException;
        uint handler;
        uint state;
    } frame;
    frame.state = 0xffffffff;
    frame.handler = ((uint)&ClimbablePointProscribedPathExceptionHandler);
    frame.previousException = ExceptionList;
    ExceptionList = &frame.previousException;
    AR6ClimbablePoint* capturedPoint = point;
    ANavigationPoint* capturedCandidate = candidate; // Retained in EDX before state0.
    bool hasCandidate = capturedCandidate != nullptr;
    frame.savedESP = (uint)&frame.savedEDI;
    frame.state = 0;
    if (hasCandidate) {
        UClass* type = capturedCandidate->Class;
        while (type != nullptr && type != &AR6ClimbablePoint::PrivateStaticClass)
            type = type->GetSuperClass();
        if (type != nullptr && capturedCandidate != nullptr) { // Native repeats the retained-candidate null test.
            AR6ClimbableObject* object = capturedPoint->m_climbableObj;
            AR6ClimbableObject* candidateObject = static_cast<AR6ClimbablePoint*>(capturedCandidate)->m_climbableObj;
            if (object == candidateObject) {
                int result = 1;
                void* previousException = frame.previousException;
                ExceptionList = previousException;
                uint restoredEDI = frame.savedEDI;
                uint restoredESI = frame.savedESI;
                uint restoredEBX = frame.savedEBX;
                return result;
            }
        }
    }
    ANavigationPoint* candidateArgument = capturedCandidate; // Outgoing entryESP-0x2c, without an incoming-slot reread.
    using ProscribedBase = int (__thiscall*)(ANavigationPoint*, ANavigationPoint*);
    ProscribedBase proscribedBase = reinterpret_cast<ProscribedBase&>(ANavigationPointProscribedPathToImport);
    int result = proscribedBase(capturedPoint, candidateArgument);
    void* previousException = frame.previousException;
    uint restoredEDI = frame.savedEDI;
    uint restoredESI = frame.savedESI;
    ExceptionList = previousException;
    uint restoredEBX = frame.savedEBX;
    return result; // Preserve every bit of the base result; no Boolean normalization.
}

// R6Engine.dll @ 10016619 : ClimbablePointAddReachSpecsCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointAddReachSpecsCatchPointer(void)
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

// R6Engine.dll @ 1001662d : ClimbablePointAddReachSpecsCatchContext
// Reports addReachSpecs and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointAddReachSpecsCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbablePointAddReachspecs
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100166f0 : ClimbablePointInitPathFindingCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointInitPathFindingCatchPointer(void)
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

// R6Engine.dll @ 10016704 : ClimbablePointInitPathFindingCatchContext
// Reports InitForPathFinding and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointInitPathFindingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbablePointInitForPathFinding
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001679d : ClimbablePointClearPathsCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointClearPathsCatchPointer(void)
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

// R6Engine.dll @ 100167b1 : ClimbablePointClearPathsCatchContext
// Reports ClearPaths and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointClearPathsCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbablePointClearPaths
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        xor edi,edi
        push edi
        push edi
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10016856 : ClimbablePointProscribedPathCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointProscribedPathCatchPointer(void)
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

// R6Engine.dll @ 1001686a : ClimbablePointProscribedPathCatchContext
// Reports ProscribedPathTo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl ClimbablePointProscribedPathCatchContext(void)
{
    __asm {
        push offset nativeTextAR6ClimbablePointProscribedPathTo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10043ca0 : ClimbablePointAddReachSpecsExceptionHandler
// Supplies the exact navigation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl ClimbablePointAddReachSpecsExceptionHandler(void)
{
    __asm {
        mov eax,offset climbablePointAddReachSpecsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043cb0 : ClimbablePointInitPathFindingExceptionHandler
// Supplies the exact navigation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl ClimbablePointInitPathFindingExceptionHandler(void)
{
    __asm {
        mov eax,offset climbablePointInitPathFindingFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043cc0 : ClimbablePointClearPathsExceptionHandler
// Supplies the exact navigation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl ClimbablePointClearPathsExceptionHandler(void)
{
    __asm {
        mov eax,offset climbablePointClearPathsFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10043cd0 : ClimbablePointProscribedPathExceptionHandler
// Supplies the exact navigation FuncInfo without changing the private native dispatcher frame.
__declspec(naked) void __cdecl ClimbablePointProscribedPathExceptionHandler(void)
{
    __asm {
        mov eax,offset climbablePointProscribedPathFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 10046fd0 : InitializeAR6ClimbablePointClassMetadata
// Constructs persistent class metadata, then registers destruction and returns the exit-registration status.
int __cdecl InitializeAR6ClimbablePointClassMetadata(void)
{
    uint staticConstructorWord = UObjectStaticConstructorImport;
    UClass* withinClass = UObjectPrivateStaticClassImport;
    UClass* parentClass = ANavigationPointPrivateStaticClassImport;
    struct ConfigCaptureView { // Inferred within-class and parent words at entryESP-8/-4.
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
    packet.staticConstructorWord = staticConstructorWord;
    packet.internalConstructor = &AR6ClimbablePoint::InternalConstructor;
    packet.objectFlags = 0x04084004;
    captures.withinClass = withinClass;
    captures.parentClass = parentClass;
    const ushort* configName = UObject::StaticConfigName();
    withinClass = captures.withinClass;
    parentClass = captures.parentClass; // Both reloads precede placement of the returned configuration pointer.
    packet.configName = configName;
    packet.packageName = (const ushort*)&enginePackageName;
    packet.className = nativeTextR6ClimbablePoint;
    packet.withinClass = withinClass;
    packet.parentClass = parentClass;
    packet.guidWords[0] = 0;
    packet.classFlags = 0;
    packet.guidWords[1] = 0;
    packet.classSize = 0x3fc;
    packet.guidWords[2] = 0;
    packet.nativeConstructorTag = 0;
    packet.guidWords[3] = 0;
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    ConstructClass construct = reinterpret_cast<ConstructClass&>(UClassConstructorImport);
    construct(&AR6ClimbablePoint::PrivateStaticClass, packet.nativeConstructorTag, packet.classSize,
        packet.classFlags, packet.parentClass, packet.withinClass, *(FGuid*)packet.guidWords,
        packet.className, packet.packageName, packet.configName, packet.objectFlags,
        packet.internalConstructor, packet.staticConstructorWord);
    packet.exitCallback = DestroyAR6ClimbablePointClassMetadata;
    return _atexit(packet.exitCallback); // The native wrapper returns zero on registration success, -1 on null.
}

// R6Engine.dll @ 100481a0 : DestroyAR6ClimbablePointClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6ClimbablePointClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6ClimbablePoint::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10047060 : PublishAR6ClimbablePointAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6ClimbablePointAutoClass(void)
{
    autoclassAR6ClimbablePoint = &AR6ClimbablePoint::PrivateStaticClass;
}
