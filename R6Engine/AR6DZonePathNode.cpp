#include "native_array_views.hpp"
#include "native_object_tables.hpp"
#include "native_member_entries.hpp"
#include "native_exception_data.hpp"
#include "native_runtime_entries.hpp"
#include "native_exception_records.hpp"
#include "native_import_slots.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl DestroyAR6DZonePathNodeClassMetadata(void);

// Native exported virtual-table addresses; raw PE32 words do not assume C++ member-pointer layouts.
// R6Engine.dll data @ 1004bcb0 : AR6DZonePathNodeVirtualTable
// Slots +0/+4/+8 use the UObject QueryInterface/AddRef/Release import tails.
// Slot +12: AR6DZonePathNode::DeletingDestructor; the rest of the native table is outside this prefix view.
extern const NativeObjectVtablePrefix AR6DZonePathNodeVirtualTable;

// Descriptive text names identify existing native strings, not recovered original variable names.
// R6Engine.dll data @ 1004fe10 : nativeTextAR6DZonePathNodePostScriptDestroyed
extern const ushort nativeTextAR6DZonePathNodePostScriptDestroyed[38];

// R6Engine.dll data @ 1004fdc8 : nativeTextAR6DZonePathNodeRenderEditorInfo
extern const ushort nativeTextAR6DZonePathNodeRenderEditorInfo[35];

// R6Engine.dll data @ 100557de : nativeTextR6DZonePathNode
extern const ushort nativeTextR6DZonePathNode[16];

// Native helper declarations match the canonical definitions below.
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeEditorForwardCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeEditorForwardCatchPointer(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeOwnerRemovalCatchContext(void);
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeOwnerRemovalCatchPointer(void);
__declspec(naked) void __cdecl PathNodeValidationState0Cleanup(void);

// R6Engine.dll data @ 10059894 : pathNodeValidationUnwindMap
// Retains the warning FString cleanup-only state with no catch or report scope.
const NativeUnwindEntry pathNodeValidationUnwindMap[1] = {
    { -1, ((uint)&PathNodeValidationState0Cleanup) }
};

// R6Engine.dll data @ 1005989c : pathNodeValidationFuncInfo
// Retains the warning FString cleanup-only state with no catch or report scope.
const NativeFunctionInfoPrefix pathNodeValidationFuncInfo = { 0x19930520, 0x1, ((uint)&pathNodeValidationUnwindMap), 0,
    0, 0 };

// R6Engine.dll data @ 100597d4 : pathNodeEditorForwardUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathNodeEditorForwardUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 100597e4 : pathNodeEditorForwardCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathNodeEditorForwardCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathNodeEditorForwardCatchPointer) },
    { 0, 0, 0, ((uint)&PathNodeEditorForwardCatchContext) }
};

// R6Engine.dll data @ 10059804 : pathNodeEditorForwardTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathNodeEditorForwardTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathNodeEditorForwardCatchMap) }
};

// R6Engine.dll data @ 10059818 : pathNodeEditorForwardFuncInfo
// Binds the selected MSVC cleanup/catch maps for RenderEditorInfo.
const NativeFunctionInfoPrefix pathNodeEditorForwardFuncInfo = { 0x19930520, 0x2,
    ((uint)&pathNodeEditorForwardUnwindMap), 0x1, ((uint)&pathNodeEditorForwardTryMap), 0 };

// R6Engine.dll data @ 10059834 : pathNodeOwnerRemovalUnwindMap
// Retains native predecessor states and exact local cleanup entries.
const NativeUnwindEntry pathNodeOwnerRemovalUnwindMap[2] = {
    { -1, 0 },
    { -1, 0 }
};

// R6Engine.dll data @ 10059844 : pathNodeOwnerRemovalCatchMap
// Binds unsigned-short-pointer and catch-all four-word handler records.
const NativeCatchEntry pathNodeOwnerRemovalCatchMap[2] = {
    { 0, ((uint)&unsignedShortPointerTypeDescriptor), -24, ((uint)&PathNodeOwnerRemovalCatchPointer) },
    { 0, 0, 0, ((uint)&PathNodeOwnerRemovalCatchContext) }
};

// R6Engine.dll data @ 10059864 : pathNodeOwnerRemovalTryMap
// Retains the native guarded-state range and two catch handlers.
const NativeTryBlock pathNodeOwnerRemovalTryMap[1] = {
    { 0, 0, 0x1, 0x2, ((uint)&pathNodeOwnerRemovalCatchMap) }
};

// R6Engine.dll data @ 10059878 : pathNodeOwnerRemovalFuncInfo
// Binds the selected MSVC cleanup/catch maps for PostScriptDestroyed.
const NativeFunctionInfoPrefix pathNodeOwnerRemovalFuncInfo = { 0x19930520, 0x2, ((uint)&pathNodeOwnerRemovalUnwindMap),
    0x1, ((uint)&pathNodeOwnerRemovalTryMap), 0 };

// R6Engine.dll data @ 1007976c : autoclassAR6DZonePathNode
// Loader zero-fill precedes the selected CRT publication callback's four-byte class-pointer store.
UClass* autoclassAR6DZonePathNode = nullptr;

// R6Engine.dll @ 10009840 : AR6DZonePathNode::StaticClass
// Returns the persistent class metadata object used by allocation and automatic-class publication.
UClass* __cdecl AR6DZonePathNode::StaticClass(void)
{
    return &AR6DZonePathNode::PrivateStaticClass; // Selected object at0x1007da10.
}

// R6Engine.dll @ 10009850 : AR6DZonePathNode::operator new
// Forwards object parameters and current GError to class-specific allocation; the size argument is unused.
void* __cdecl AR6DZonePathNode::operator_new(uint allocationSize, UObject* outer, FName objectName, ulong objectFlags)
{
    FOutputDeviceError* error = **(FOutputDeviceError***)&CoreGErrorImport;
    return UObject::StaticAllocateObject(&AR6DZonePathNode::PrivateStaticClass, outer, objectName, objectFlags, nullptr,
        (FOutputDevice*)error, nullptr, 0); // Eight cdecl words; returned object pointer is unchanged.
}

// R6Engine.dll @ 10009880 : AR6DZonePathNode::~AR6DZonePathNode
// Runs ConditionalDestroy, then implicitly destroys the AActor base on normal and exceptional exits.
AR6DZonePathNode::~AR6DZonePathNode()
{
    // Compiler installs vtable1004bcb0 first; shared state0 cleanup432d0 retains the pending AActor base.
    UObject::ConditionalDestroy(); // Ignore its int result; the derived fields own no destructible resources.
}

// R6Engine.dll @ 100098e0 : AR6DZonePathNode::AR6DZonePathNode(void)
// Constructs the base and installs the derived vtable without adding any derived-field initialization.
AR6DZonePathNode::AR6DZonePathNode() : AActor()
{
    // Publishes AR6DZonePathNodeVirtualTable after base construction; native EAX retains original storage.
}

// R6Engine.dll @ 10009900 : AR6DZonePathNode::AR6DZonePathNode(const AR6DZonePathNode&)
// Copies the base and scalar fields in order, retaining raw radius/name words and path/sound pointer values.
AR6DZonePathNode::AR6DZonePathNode(const AR6DZonePathNode& sourceObject) : AActor(sourceObject)
{
    // Publishes AR6DZonePathNodeVirtualTable after base construction; native EAX retains original storage.
    AR6DZonePathNode* object = this;
    const AR6DZonePathNode* source = &sourceObject;
    object->m_AnimChance = source->m_AnimChance;
    object->m_bWait = source->m_bWait; // +0x398 bit1 only; preserve the other incoming bits.
    // No floating conversion or NaN quieting.
    reinterpret_cast<uint&>(object->m_fRadius) = reinterpret_cast<const uint&>(source->m_fRadius);
    object->m_pPath = source->m_pPath;
    object->m_SoundToPlay = source->m_SoundToPlay;
    object->m_SoundToPlayStop = source->m_SoundToPlayStop;
    reinterpret_cast<uint&>(object->m_AnimToPlay) = reinterpret_cast<const uint&>(source->m_AnimToPlay);
}

// R6Engine.dll @ 10009980 : AR6DZonePathNode::operator=
// Assigns the base and scalar fields in order, preserving raw radius/name words and unrelated wait-flag bits.
AR6DZonePathNode& AR6DZonePathNode::operator=(const AR6DZonePathNode& source)
{
    AActor::operator=(source);
    m_AnimChance = source.m_AnimChance;
    m_bWait = source.m_bWait;
    reinterpret_cast<uint&>(m_fRadius) = reinterpret_cast<const uint&>(source.m_fRadius);
    m_pPath = source.m_pPath;
    m_SoundToPlay = source.m_SoundToPlay;
    m_SoundToPlayStop = source.m_SoundToPlayStop;
    reinterpret_cast<uint&>(m_AnimToPlay) = reinterpret_cast<const uint&>(source.m_AnimToPlay);
    return *this;
}

// R6Engine.dll @ 1000dfb0 : AR6DZonePathNode::InternalConstructor
// Enters default construction on nonnull storage, preserving the original caller's return frame and argument.
__declspec(naked) void __cdecl AR6DZonePathNode::InternalConstructor(void* objectMemory)
{
    __asm {
        mov ecx,dword ptr [esp+4]
        test ecx,ecx
        je null_storage
        jmp AR6DZonePathNodeConstructorNativeEntry
    null_storage:
        ret
    }
}

// R6Engine.dll @ 1001a240 : AR6DZonePathNode::RenderEditorInfo
// Forwards the three editor arguments to the captured path's current virtual renderer when linked.
void AR6DZonePathNode::RenderEditorInfo(FLevelSceneNode* scene, FRenderInterface* render,
    FDynamicActor* dynamicActor)
{
    AR6DZonePath* path = m_pPath; // Captured before guarded state0.
    try {
        if (path != nullptr) {
            using RenderCall = void (__thiscall*)(AR6DZonePath*, FLevelSceneNode*, FRenderInterface*, FDynamicActor*);
            RenderCall draw = *(RenderCall*)(*(byte**)path + 0x104);
            draw(path, scene, render, dynamicActor);
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePathNode::RenderEditorInfo");
        throw;
    }
}

// R6Engine.dll @ 1001a29b : PathNodeEditorForwardCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeEditorForwardCatchPointer(void)
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

// R6Engine.dll @ 1001a2d0 : AR6DZonePathNode::PostScriptDestroyed
// Requests removal from the captured path when present, without clearing the owner or issuing a base notification.
void AR6DZonePathNode::PostScriptDestroyed()
{
    AR6DZonePath* path = m_pPath; // Captured before guarded state0; there are no post-call object accesses.
    try {
        if (path != nullptr) {
            using DeletePathNode = void (__thiscall*)(AR6DZonePath*, AR6DZonePathNode*);
            (*(DeletePathNode)&AR6DZonePathDeleteANodeNativeEntry)(path, this);
        }
    } catch (ushort* error) {
        throw error;
    } catch (...) {
        appUnwindf((const ushort*)L"%s", (const ushort*)L"AR6DZonePathNode::PostScriptDestroyed");
        throw;
    }
}

// R6Engine.dll @ 1001a31b : PathNodeOwnerRemovalCatchPointer
// Throws the caught unsigned-short pointer from inherited EBP-0x18 by value through EBP-0x14.
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeOwnerRemovalCatchPointer(void)
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

// R6Engine.dll @ 1001a350 : AR6DZonePathNode::CheckForErrors
// Copies availability for actual path membership, otherwise warns, then grounds the node and checks its resulting base.
void AR6DZonePathNode::CheckForErrors()
{
    using ReportCall = void (__thiscall*)(FFeedbackContext*, int, UObject*, const ushort*);
    AR6DZonePath* path = m_pPath;
    bool member = false;
    if (path != nullptr) {
        const NativeArrayHeader32* pathNodes = reinterpret_cast<const NativeArrayHeader32*>(&path->m_aNode);
        int count = pathNodes->count; // Cached signed scan bound.
        uint index = 0;
        while ((int)index < count) {
            AR6DZonePathNode** nodes = reinterpret_cast<AR6DZonePathNode**>(pathNodes->dataAddress);
            if (nodes[index] == this) {
                member = true;
                break;
            }
            ++index;
        }
    }
    if (member) {
        AActor::CopyR6Availability(path);
    } else {
        const ushort* nodeName = GetName();
        FString text = FString::Printf((const ushort*)L"%s is not part of a path.", nodeName);
        FFeedbackContext* warning = **(FFeedbackContext***)&CoreGWarnImport;
        byte* table = *(byte**)warning;
        const ushort* detail = *text;
        ReportCall report = *(ReportCall*)(table + 0x28); // Late slot lookup; receiver and table remain captured.
        report(warning, 0, this, detail);
    } // The native warning string is destroyed before grounding, including on exceptional exits.
    AActor::PutOnGround();
    if (Base == nullptr) {
        FFeedbackContext* warning = **(FFeedbackContext***)&CoreGWarnImport;
        ReportCall report = *(ReportCall*)(*(byte**)warning + 0x28);
        report(warning, 0, this, (const ushort*)L"Path node not on valid base.");
    }
}

// R6Engine.dll @ 100440c0 : PathNodeValidationState0Cleanup
// Destroys the warning FString at inherited dispatcher-frame EBP-0x18.
__declspec(naked) void __cdecl PathNodeValidationState0Cleanup(void)
{
    __asm {
        lea ecx,[ebp-0x18]
        jmp dword ptr [FStringDestructorImport]
    }
}

// R6Engine.dll @ 100465a0 : InitializeAR6DZonePathNodeClassMetadata
// Constructs persistent class metadata and registers the matching UClass destruction callback.
int __cdecl InitializeAR6DZonePathNodeClassMetadata(void)
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
    reinterpret_cast<ConstructClass&>(UClassConstructorImport)(&AR6DZonePathNode::PrivateStaticClass, 0, 0x3b0, 0,
        parentClass, withinClass,
        *(FGuid*)guidWords, nativeTextR6DZonePathNode,
            (const ushort*)&enginePackageName, configName,
        0x04084004, &AR6DZonePathNode::InternalConstructor, staticConstructorWord);
    return _atexit(DestroyAR6DZonePathNodeClassMetadata); // Preserve final EAX; CRT consumes no result.
}

// R6Engine.dll @ 10048090 : DestroyAR6DZonePathNodeClassMetadata
// Tail-enters UClass destruction on the same object that the CRT metadata initializer constructed.
__declspec(naked) void __cdecl DestroyAR6DZonePathNodeClassMetadata(void)
{
    __asm {
        mov ecx,offset AR6DZonePathNode::PrivateStaticClass
        jmp dword ptr [UClassDestructorImport]
    }
}

// R6Engine.dll @ 10046630 : PublishAR6DZonePathNodeAutoClass
// Publishes the persistent class pointer to its exported alias after the metadata construction callback.
void __cdecl PublishAR6DZonePathNodeAutoClass(void)
{
    autoclassAR6DZonePathNode = &AR6DZonePathNode::PrivateStaticClass;
}

// R6Engine.dll @ 10009a00 : AR6DZonePathNode::DeletingDestructor
// Destroys one object or a cookie-counted array, optionally frees storage and returns its native storage pointer.
// Class-owned compiler helper; DeletingDestructor is an inferred source name.
void* __thiscall AR6DZonePathNode::DeletingDestructor(uint flags)
{
    byte deleteFlags = static_cast<byte>(flags); // Low-byte bits1/2; full flags word consumed by RET4.
    AR6DZonePathNode* object = this;
    if ((deleteFlags & 2U) != 0) {
        int count = *reinterpret_cast<const int*>(reinterpret_cast<const byte*>(object) - 4);
        using Destructor = void (__thiscall*)(void*);
        Destructor callback = reinterpret_cast<Destructor>(&AR6DZonePathNodeDestructorNativeEntry);
        byte* cookie = reinterpret_cast<byte*>(object) - 4;
        _eh_vector_destructor_iterator_(object, 0x3b0, count, callback);
        if ((deleteFlags & 1U) != 0) {
            // Read current GMalloc after all element destruction.
            FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
            allocator->Free(cookie);
        }
        return cookie;
    }
    object->AR6DZonePathNode::~AR6DZonePathNode(); // Direct native call10009880, without vtable dispatch.
    if ((deleteFlags & 1U) != 0) {
        UObject::operator delete(object, 0x3b0);
    }
    return object;
}

// R6Engine.dll @ 1001a2af : PathNodeEditorForwardCatchContext
// Reports AR6DZonePathNode::RenderEditorInfo and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeEditorForwardCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathNodeRenderEditorInfo
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 1001a32f : PathNodeOwnerRemovalCatchContext
// Reports AR6DZonePathNode::PostScriptDestroyed and rethrows the active exception.
__declspec(naked) __declspec(noreturn) void __cdecl PathNodeOwnerRemovalCatchContext(void)
{
    __asm {
        push offset nativeTextAR6DZonePathNodePostScriptDestroyed
        push offset unwindStringFormat
        call dword ptr [CoreAppUnwindfImport]
        add esp,0x8
        push 0x0
        push 0x0
        call _CxxThrowException
    }
}

// R6Engine.dll @ 100440a0 : PathNodeEditorForwardExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathNodeEditorForwardExceptionHandler(void)
{
    __asm {
        mov eax,offset pathNodeEditorForwardFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100440b0 : PathNodeOwnerRemovalExceptionHandler
// Supplies the exact native FuncInfo without changing the private dispatcher frame.
__declspec(naked) void __cdecl PathNodeOwnerRemovalExceptionHandler(void)
{
    __asm {
        mov eax,offset pathNodeOwnerRemovalFuncInfo
        jmp __CxxFrameHandler
    }
}

// R6Engine.dll @ 100440c9 : PathNodeValidationExceptionHandler
// Supplies the exact cleanup-only FuncInfo without creating another dispatcher frame.
__declspec(naked) void __cdecl PathNodeValidationExceptionHandler(void)
{
    __asm {
        mov eax,offset pathNodeValidationFuncInfo
        jmp __CxxFrameHandler
    }
}
