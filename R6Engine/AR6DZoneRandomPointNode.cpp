#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"
#include "native_array_views.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6DZoneRandomPointNodeClassMetadata(void);

// R6Engine.dll data @ 1004bb28 : AR6DZoneRandomPointNodeVirtualTable
// QueryInterface/AddRef/Release and the class deleting helper occupy the first four native slots.
extern const NativeObjectVtablePrefix AR6DZoneRandomPointNodeVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004ff90 : nativeTextAR6DZoneRandomPointNodePostScriptDestroyed
extern const ushort nativeTextAR6DZoneRandomPointNodePostScriptDestroyed[45];

// R6Engine.dll data @ 10050030 : nativeTextAR6DZoneRandomPointNodeRenderEditorInfo
extern const ushort nativeTextAR6DZoneRandomPointNodeRenderEditorInfo[42];

// R6Engine.dll data @ 1005586e : nativeTextR6DZoneRandomPointNode
extern const ushort nativeTextR6DZoneRandomPointNode[23];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeRenderingCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeRenderingCatchPointer(void);
__declspec(naked) void __cdecl RandomPointNodeRenderingState1Cleanup(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeTeardownCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeTeardownCatchPointer(void);

// R6Engine.dll data @ 10059a40 : randomPointNodeRenderingUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointNodeRenderingUnwindMap[3] = {
    { -1, 0 },
    { 0, ((uint)&RandomPointNodeRenderingState1Cleanup) },
    { -1, 0 }
};

// R6Engine.dll data @ 10059a58 : randomPointNodeRenderingCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointNodeRenderingCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointNodeRenderingCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointNodeRenderingCatchContext) }
};

// R6Engine.dll data @ 10059a78 : randomPointNodeRenderingTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointNodeRenderingTryMap[1] = {
    { 0, 0x1, 0x2, 0x2, ((uint)&randomPointNodeRenderingCatchMap) }
};

// R6Engine.dll data @ 10059a8c : randomPointNodeRenderingFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZoneRandomPointNode::RenderEditorInfo.
const NativeFunctionInfoPrefix randomPointNodeRenderingFuncInfo = { 0x19930520, 0x3,
    ((uint)&randomPointNodeRenderingUnwindMap), 0x1, ((uint)&randomPointNodeRenderingTryMap), 0 };

// R6Engine.dll data @ 100599e0 : randomPointNodeTeardownUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry randomPointNodeTeardownUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100599f0 : randomPointNodeTeardownCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry randomPointNodeTeardownCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&RandomPointNodeTeardownCatchPointer) },
    { 0, 0, 0, ((uint)&RandomPointNodeTeardownCatchContext) }
};

// R6Engine.dll data @ 10059a10 : randomPointNodeTeardownTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock randomPointNodeTeardownTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&randomPointNodeTeardownCatchMap) }
};

// R6Engine.dll data @ 10059a24 : randomPointNodeTeardownFuncInfo
// Binds the selected MSVC cleanup/catch maps for AR6DZoneRandomPointNode::PostScriptDestroyed.
const NativeFunctionInfoPrefix randomPointNodeTeardownFuncInfo = { 0x19930520, 0x2,
    ((uint)&randomPointNodeTeardownUnwindMap), 0x1, ((uint)&randomPointNodeTeardownTryMap), 0 };

// R6Engine.dll data @ 1008268c : autoclassAR6DZoneRandomPointNode
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZoneRandomPointNode = nullptr;

// R6Engine.dll @ 10009450 : AR6DZoneRandomPointNode::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZoneRandomPointNode::StaticClass(void)
{
    return &AR6DZoneRandomPointNode::PrivateStaticClass; // Selected object at0x10076498.
}

// R6Engine.dll @ 10009460 : AR6DZoneRandomPointNode::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZoneRandomPointNode::operator_new(uint allocationSize, UObject* outer,
    FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZoneRandomPointNode::PrivateStaticClass, outer, objectName, objectFlags,
        nullptr, (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10009490 : AR6DZoneRandomPointNode::~AR6DZoneRandomPointNode
// Runs ConditionalDestroy, then implicitly destroys the AActor base on normal and exceptional exits.
AR6DZoneRandomPointNode::~AR6DZoneRandomPointNode()
{
    // Compiler installs vtable1004bb28 first; state0 retains the shared AActor-base cleanup at100432d0.
    UObject::ConditionalDestroy(); // Ignore its int result; no derived fields own destructible resources.
}

// R6Engine.dll @ 100094f0 : AR6DZoneRandomPointNode::AR6DZoneRandomPointNode(void)
// Constructs the AActor base and installs the derived vtable without initializing the derived scalar fields.
AR6DZoneRandomPointNode::AR6DZoneRandomPointNode() : AActor()
{
    // Native constructor returns its original receiver in EAX; derived fields retain their incoming storage.
}

// R6Engine.dll @ 10009510 : AR6DZoneRandomPointNode::AR6DZoneRandomPointNode
// Copies the base, retains the pre-vtable flag snapshot and copies the node fields in native order.
// Native ABI view exposes the destination read before derived-table publication.
AR6DZoneRandomPointNode* __thiscall AR6DZoneRandomPointNode::AR6DZoneRandomPointNode(
    AR6DZoneRandomPointNode* object, const AR6DZoneRandomPointNode* source)
{
    using CopyActor = AActor* (__thiscall*)(AActor*, const AActor*);
    reinterpret_cast<CopyActor&>(AActorCopyConstructorImport)(
        static_cast<AActor*>(object), static_cast<const AActor*>(source));
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(object) + 0x39c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(source) + 0x39c);
    uint earlyFlags = *destinationFlags;
    *reinterpret_cast<uint*>(object) = reinterpret_cast<uint>(&AR6DZoneRandomPointNodeVirtualTable);
    reinterpret_cast<byte&>(object->m_eStance) = reinterpret_cast<const byte&>(source->m_eStance);
    object->m_iGroupID = source->m_iGroupID;
    uint sourceWord = *sourceFlags;
    uint difference = earlyFlags ^ sourceWord;
    uint currentFlags = *destinationFlags;
    uint flags = currentFlags ^ (difference & 1U); // m_bHighPriority.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bAllowLeave.
    *destinationFlags = flags;
    object->m_pZone = source->m_pZone;
    return object;
}

// R6Engine.dll @ 10009580 : AR6DZoneRandomPointNode::operator=
// Assigns node fields while preserving the early/current destination flag reads and both masked stores.
AR6DZoneRandomPointNode& AR6DZoneRandomPointNode::operator=(const AR6DZoneRandomPointNode& source)
{
    AActor::operator=(source);
    byte stance = reinterpret_cast<const byte&>(source.m_eStance);
    uint* destinationFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0x39c);
    const uint* sourceFlags = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(&source) + 0x39c);
    uint earlyFlags = *destinationFlags;
    reinterpret_cast<byte&>(m_eStance) = stance;
    m_iGroupID = source.m_iGroupID;
    uint sourceWord = *sourceFlags;
    uint difference = earlyFlags ^ sourceWord;
    uint currentFlags = *destinationFlags;
    uint flags = currentFlags ^ (difference & 1U); // m_bHighPriority.
    *destinationFlags = flags;
    flags ^= (*sourceFlags ^ flags) & 2U; // m_bAllowLeave.
    *destinationFlags = flags;
    m_pZone = source.m_pZone;
    return *this;
}

// R6Engine.dll @ 1000dfa0 : AR6DZoneRandomPointNode::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZoneRandomPointNode::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZoneRandomPointNodeConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001aa30 : AR6DZoneRandomPointNode::PostScriptDestroyed
// Delegates removal to the captured owning zone when present, without clearing this node's owner pointer.
void __thiscall AR6DZoneRandomPointNode::PostScriptDestroyed(void)
{
    AR6DZoneRandomPointNode* node = this;
    AR6DZoneRandomPoints* owner = node->m_pZone; // Native owner read precedes guarded state0.
    try {
        if (owner != nullptr)
            owner->AR6DZoneRandomPoints::DeleteANode(node);
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPointNode::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 1001aa7b : RandomPointNodeTeardownCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeTeardownCatchPointer(void)
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

// R6Engine.dll @ 1001aab0 : AR6DZoneRandomPointNode::CheckForErrors
// Copies availability from the owner, grounds the node, then reports a missing resulting base.
void AR6DZoneRandomPointNode::CheckForErrors()
{
    AActor::CopyR6Availability(m_pZone);
    AActor::PutOnGround();
    if (Base == nullptr) {
        FFeedbackContext* feedback = **(FFeedbackContext***)&CoreGWarnImport;
        using ReportCall = void (__thiscall*)(FFeedbackContext*, int, UObject*, const ushort*);
        ReportCall report = *(ReportCall*)(*(byte**)feedback + 0x28);
        report(feedback, 0, this, (const ushort*)L"Random point not on valid base.");
    }
}

// R6Engine.dll @ 1001aaf0 : AR6DZoneRandomPointNode::RenderEditorInfo
// Propagates enabled zone selection and draws a colored box when the node, its zone or a sibling is selected.
void AR6DZoneRandomPointNode::RenderEditorInfo(FLevelSceneNode* sceneNode, FRenderInterface* renderInterface,
    FDynamicActor* dynamicActor)
{
    AR6DZoneRandomPoints* zone = m_pZone; // Captured before guarded state0; the other two arguments are unused.
    try {
        if (zone == nullptr) return;
        const NativeArrayHeader32* nodesHeader = reinterpret_cast<const NativeArrayHeader32*>(&zone->m_aNode);
        // Engine.Actor.bSelected is bit0x4000.
        uint* selectionFlags = reinterpret_cast<uint*>(reinterpret_cast<byte*>(this) + 0xac);
        const uint* zoneSelection = reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(zone) + 0xac);
        if ((*zoneSelection & 0x4000U) != 0 && (reinterpret_cast<const byte*>(zone)[0x49c] & 1) != 0)
            *selectionFlags |= 0x4000U;
        bool drawMarker = (*selectionFlags & 0x4000U) != 0 || (*zoneSelection & 0x4000U) != 0;
        if (!drawMarker) {
            uint index = 0;
            while ((int)index < nodesHeader->count) {
                AActor** nodes = reinterpret_cast<AActor**>(nodesHeader->dataAddress);
                AActor* sibling = nodes[index];
                if (sibling != nullptr &&
                    (*reinterpret_cast<const uint*>(reinterpret_cast<const byte*>(sibling) + 0xac) & 0x4000U) != 0) {
                    drawMarker = true;
                    break;
                }
                ++index;
            }
        }
        if (!drawMarker) return;
        byte* sceneOwner = *(byte**)((byte*)sceneNode + 4);
        FRenderInterface* sceneInterface = *(FRenderInterface**)(sceneOwner + 0x164);
        FLineBatcher batcher(sceneInterface, 1, 0); // Native constructor takes both integer arguments.
        bool selected = (*selectionFlags & 0x4000U) != 0; // Reload after construction; eligibility is not rechecked.
        FPlane colorPlane(selected ? 0.75f : 0.0f, selected ? 1.0f : 0.5f, 0.0f, 0.0f);
        FBox bounds; // Only IsValid is initialized here; native by-value copying retains the three padding bytes.
        bounds.IsValid = 1;
        const volatile float* location = (const volatile float*)&Location;
        // float10 denotes native x87 work, not a recovered type spelling. Loads are Z/Y/X and spills are X/Y/Z.
        float10 maxZ = (float10)location[2] + (float10)85.0f;
        float10 maxY = (float10)location[1] + (float10)40.0f;
        float10 maxX = (float10)location[0] + (float10)40.0f;
        float roundedMaxX = (float)maxX;
        float roundedMaxY = (float)maxY;
        float roundedMaxZ = (float)maxZ;
        float10 minZ = (float10)location[2] - (float10)85.0f;
        float10 minY = (float10)location[1] - (float10)40.0f;
        float10 minX = (float10)location[0] - (float10)40.0f;
        bounds.Min.X = (float)minX;
        bounds.Min.Y = (float)minY;
        float roundedMinZ = (float)minZ;
        bounds.Max.X = roundedMaxX;
        bounds.Min.Z = roundedMinZ;
        bounds.Max.Y = roundedMaxY;
        bounds.Max.Z = roundedMaxZ;
        FColor color(colorPlane);
        batcher.DrawBox(bounds, color); // Native copies all28 box bytes after color construction, then its color word.
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZoneRandomPointNode::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001acd3 : RandomPointNodeRenderingCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeRenderingCatchPointer(void)
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

// R6Engine.dll @ 10044130 : RandomPointNodeRenderingState1Cleanup
// Destroys the live FLineBatcher at inherited dispatcher-frame EBP-0x84.
__declspec(naked) void __cdecl RandomPointNodeRenderingState1Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x84]
        jmp dword ptr [FLineBatcherDestructorImport]
    }
}

// R6Engine.dll @ 100467f0 : InitializeAR6DZoneRandomPointNodeClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZoneRandomPointNodeClassMetadata(void)
{
    // Imported UObject member-callback word, captured first.
    uint staticConstructorWord = UObjectStaticConstructorImport;
    // Imported object address, not a field of the class object.
    UClass* withinClass = UObjectPrivateStaticClassImport;
    // AActor object address, captured before config lookup.
    UClass* parentClass = AActorPrivateStaticClassImport;
    const ushort* configName = UObject::StaticConfigName();
    uint guidWords[4] = {0, 0, 0, 0};
    using ConstructClass = void (__thiscall*)(UClass*, int, uint, uint, UClass*, UClass*, FGuid,
        const ushort*, const ushort*, const ushort*, uint, void (__cdecl*)(void*), uint);
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZoneRandomPointNode::PrivateStaticClass, 0, 0x3a4,
        0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZoneRandomPointNode,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6DZoneRandomPointNode::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZoneRandomPointNodeClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 100480d0 : DestroyAR6DZoneRandomPointNodeClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZoneRandomPointNodeClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZoneRandomPointNode::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046880 : PublishAR6DZoneRandomPointNodeAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZoneRandomPointNodeAutoClass(void)
{
    autoclassAR6DZoneRandomPointNode = &AR6DZoneRandomPointNode::PrivateStaticClass;
}

// R6Engine.dll @ 1001aa8f : RandomPointNodeTeardownCatchContext
// Reports AR6DZoneRandomPointNode::PostScriptDestroyed and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeTeardownCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointNodePostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 10044120 : RandomPointNodeTeardownExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointNodeTeardownExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointNodeTeardownFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100095f0 : AR6DZoneRandomPointNode::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZoneRandomPointNode::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZoneRandomPointNode* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZoneRandomPointNodeDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x3a4, count,
            callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZoneRandomPointNode::~AR6DZoneRandomPointNode(); // Direct native call10009490, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x3a4);
    }
    return object;
}

// R6Engine.dll @ 1001ace7 : RandomPointNodeRenderingCatchContext
// Reports AR6DZoneRandomPointNode::RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl RandomPointNodeRenderingCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZoneRandomPointNodeRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1004413c : RandomPointNodeRenderingExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl RandomPointNodeRenderingExceptionHandler(void)
{
    __asm {
        mov eax,offset randomPointNodeRenderingFuncInfo
        jmp __CxxFrameHandler
    }
}
