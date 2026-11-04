#include "native_exception_records.hpp"

#include "native_import_slots.hpp"
#include "native_x87_view.hpp"

// Native helper declarations match their canonical definitions.
__declspec(naked) void __cdecl __RTC_Initialize(void);
__declspec(naked) void __cdecl RunCrtTerminationCallbacks(void);
__declspec(naked) void __cdecl initterm(void (__cdecl** begin)(void), void (__cdecl** end)(void));

using CrtExitCallback = void (__cdecl*)(void);
using DllNotificationHook = int (__stdcall*)(void*, uint, void*);

// Native helper declarations match the canonical definitions below.
__declspec(naked) void ExceptHandler3ImportThunk(void);

// External native storage views; names describe roles rather than recovered original identifiers.
// Native one-entry SEH3 scope tables; these data do not add exception operations.
// Address-only private labels retain their canonical body and inherited register/stack contracts.
// These labels are never invoked with ordinary C++ call syntax and add no implementations.
// R6Engine.dll code alias @ 10042b61 : within canonical body 10042b61
__declspec(naked) void DllCrtEntryExceptionFilterNativeEntry(void);
// R6Engine.dll code alias @ 10042b72 : within canonical body 10042b72
__declspec(naked) void DllCrtEntryExceptionHandlerNativeEntry(void);
// R6Engine.dll code alias @ 100427d1 : within canonical body 100427ae
__declspec(naked) void ArrayUnwindCompletionNativeEntry(void);
__declspec(naked) int ArrayUnwindExceptionFilter(void);
__declspec(naked) void ArrayUnwindExceptionHandler(void);
__declspec(naked) void UnwindArrayDestructorIterator(void);
__declspec(naked) void UnwindArrayConstructorIterator(void);
__declspec(naked) void UnwindArrayCopyConstructorIterator(void);

// R6Engine.dll data @ 100560f8 : arrayUnwindSehScope
const NativeSehScope arrayUnwindSehScope[1] = {
    { -1, ((uint)&ArrayUnwindExceptionFilter), ((uint)&ArrayUnwindExceptionHandler) }
};

// R6Engine.dll data @ 10056108 : arrayDestructionSehScope
const NativeSehScope arrayDestructionSehScope[1] = {
    { -1, 0, ((uint)&UnwindArrayDestructorIterator) }
};

// R6Engine.dll data @ 10056118 : arrayConstructionSehScope
const NativeSehScope arrayConstructionSehScope[1] = {
    { -1, 0, ((uint)&UnwindArrayConstructorIterator) }
};

// R6Engine.dll data @ 10056128 : arrayCopyConstructionSehScope
const NativeSehScope arrayCopyConstructionSehScope[1] = {
    { -1, 0, ((uint)&UnwindArrayCopyConstructorIterator) }
};

// R6Engine.dll data @ 10056138 : dllEntrySehScope
const NativeSehScope dllEntrySehScope[1] = {
    { -1, ((uint)&DllCrtEntryExceptionFilterNativeEntry), ((uint)&DllCrtEntryExceptionHandlerNativeEntry) }
};

// R6Engine.dll data @ 10074000 : cppInitializerBeginBoundary
// Native C++ initializer range beginning word; only its address is passed.
extern uint cppInitializerBeginBoundary;

// R6Engine.dll data @ 10074300 : cppInitializerEndBoundary
// Native C++ initializer range end word; excluded by the endpoint packet.
extern uint cppInitializerEndBoundary;

// R6Engine.dll data @ 10076488 : dllModuleHandle
// The DLL payload overwrites this zero-filled handle for every notification that reaches it.
void* dllModuleHandle = nullptr;

// Per-DLL CRT state, kept in its original declaration/initialization order.
// These five words begin as loader zero-fill; exit-table storage is owned by the imported CRT allocator.
// R6Engine.dll data @ 100844f0 : crtAttachCount
int crtAttachCount = 0;
// R6Engine.dll data @ 100844f4 : adjustFdivSnapshot
uint adjustFdivSnapshot = 0;
// R6Engine.dll data @ 100844f8 : rawDllNotificationHook
DllNotificationHook rawDllNotificationHook = nullptr;
// R6Engine.dll data @ 100844fc : exitCallbacksEnd
CrtExitCallback* exitCallbacksEnd = nullptr;
// R6Engine.dll data @ 10084500 : exitCallbacksBegin
CrtExitCallback* exitCallbacksBegin = nullptr;

// R6Engine.dll @ 100010a0 : FreeThroughGlobalAllocator
// Releases the supplied pointer through the current global allocator, including a null pointer.
void __cdecl FreeThroughGlobalAllocator(void* memory)
{
    FMalloc* allocator = **(FMalloc***)&CoreGMallocImport;
    void* releasedMemory = memory; // Incoming word is read after the allocator pointer, before its virtual table.
    allocator->Free(releasedMemory);
}

// R6Engine.dll @ 100425ca : APawn::GetPlayerPawn import thunk
// Tail-jumps to the imported const pawn accessor, preserving the ECX receiver and EAX pointer-result convention.
__declspec(naked) void GetPlayerPawnImportThunk(void)
{
    __asm {
        jmp dword ptr ds:[APawnGetPlayerPawnImport]
    }
}

// R6Engine.dll @ 10042708 : MatSubActionIsRunningImport (inferred thunk name)
// Thiscall tail entry forwards ECX, the original stack and full EAX result through the current Engine import.
__declspec(naked) int __thiscall MatSubActionIsRunningImport(UMatSubAction* this)
{
    __asm { jmp dword ptr [UMatSubActionIsRunningImport] }
}

// R6Engine.dll @ 1004279c : forward the current C++ exception frame without changing registers or stack
__declspec(naked) void __CxxFrameHandler(void)
{
  __asm {
    jmp dword ptr ds:[CrtCxxFrameHandlerImport]
  }
}

// R6Engine.dll @ 100427a2 : _CxxThrowException import thunk
// Tail-forwards the exception/ThrowInfo words and native register/stack state to the selected runtime throw entry.
__declspec(naked) void _CxxThrowException(void* exceptionObject, ThrowInfo* throwInfo)
{
    __asm { jmp dword ptr [CrtCxxThrowExceptionImport] }
}

// R6Engine.dll @ 100427a8 : _CIasin import thunk
// Tail-forwards the live x87 operand to MSVCR71 _CIasin, leaving its result in ST(0).
__declspec(naked) void _CIasin(void)
{
    __asm { jmp dword ptr [CrtCIasinImport] }
}

// R6Engine.dll @ 10042714 : forward the local-player query through the selected Engine import
// Retains the ECX receiver, empty stack-argument list and full EAX result without a local frame.
__declspec(naked) void LocalPlayerControllerImportThunk(void)
{
    __asm { jmp dword ptr [APlayerControllerLocalPlayerControllerImport] }
}

// R6Engine.dll @ 1004249e : forward the actor's ToLocal coordinate query through the selected Engine import
// Retains ECX, the hidden FCoords output stack word and the provider's returned output pointer without a local frame.
__declspec(naked) void ToLocalImportThunk(void)
{
    __asm { jmp dword ptr [AActorToLocalImport] }
}

// R6Engine.dll @ 100015d0 : ConstructArrayElements
// Invokes an element constructor with each successive address in ECX.
void __stdcall ConstructArrayElements(void* firstElement, uint elementSize, int elementCount,
    void (__thiscall *constructElement)(void*))
{
    if ((int)((uint)elementCount - 1U) < 0)
        return;
    auto constructor = constructElement;
    uint stride = elementSize;
    uint elementAddress = (uint)firstElement;
    uint remainingElements = (uint)elementCount;
    do {
        constructor((void*)elementAddress);
        elementAddress += stride;
        --remainingElements;
    } while (remainingElements != 0);
}

// R6Engine.dll @ 10042558 : forward the slope query while preserving its hidden-output and by-value arguments
__declspec(naked) void FindSlopeRotationImportThunk(void)
{
    __asm { jmp dword ptr [APawnFindSlopeRotationImport] }
}

// Convert live ST0 to EDX:EAX using ambient rounding, then correct a rounded integer toward zero.
// Explicit x87 intrinsics preserve precision/status/faults and the zero/integer-indefinite double-pop path.
// R6Engine.dll @ 10042934 : x87-state/ECX reference view; no native stack arguments, RET0, EDX:EAX result.
unsigned long long TruncateX87ToSigned64([[r6abi::register_input("x87-state")]] R6EngineNative::X87Machine &fpu,
    [[r6abi::register_input("ecx")]] uint ecxAtEntry)
{
    // Native 32-byte temporary area is aligned down to16; these members retain its significant offsets.
    struct alignas(16) Locals {
        uint residualBits;
        uint padding[3];
        unsigned long long rounded;
        uint originalBits;
        uint unused;
    } frame;
    [[r6abi::register_output("ecx")]] uint scratch = ecxAtEntry;
    fpu.DuplicateTop();
    fpu.StoreFloat32(&frame.originalBits);
    fpu.StoreInteger64AndPop(&frame.rounded);
    fpu.PushInteger64(&frame.rounded);
    uint original = frame.originalBits;
    uint low = (uint)frame.rounded;
    uint high;
    if (low == 0) {
        high = (uint)(frame.rounded >> 32);
        if ((high & 0x7fffffff) == 0) {
            fpu.StoreFloat32AndPop(&frame.originalBits);
            fpu.StoreFloat32AndPop(&frame.originalBits);
            return ((unsigned long long)high << 32) | low;
        }
    }
    fpu.SubtractAndPop();
    fpu.StoreFloat32AndPop(&frame.residualBits);
    uint residual = frame.residualBits;
    if ((int)original < 0) {
        unsigned long long sum = (unsigned long long)(residual ^ 0x80000000) + 0x7fffffff;
        scratch = (uint)sum;
        uint carry = (uint)(sum >> 32);
        uint correctedLow = low + carry;
        high = (uint)(frame.rounded >> 32) + (correctedLow < low);
        return ((unsigned long long)high << 32) | correctedLow;
    }
    unsigned long long sum = (unsigned long long)residual + 0x7fffffff;
    scratch = (uint)sum;
    uint borrow = (uint)(sum >> 32);
    uint correctedLow = low - borrow;
    high = (uint)(frame.rounded >> 32) - (low < borrow);
    return ((unsigned long long)high << 32) | correctedLow;
}

// R6Engine.dll @ 100423ea : forward setPhysics while preserving its byte, actor and by-value vector arguments
__declspec(naked) void SetPhysicsImportThunk(void)
{
    __asm { jmp dword ptr [AActorSetPhysicsImport] }
}

// R6Engine.dll @ 100427ae : __ArrayUnwind
// Destroys preceding elements backward; its SEH filter terminates if a cleanup callback throws a C++ exception.
__declspec(naked) void __stdcall __ArrayUnwind(void* elementCursor, uint elementSize, int remainingCount,
    void (__thiscall* destroyElement)(void*))
{
    __asm {
        push 0x14 // Locals include saved ESP, exception-pointer views and filter result.
        push offset arrayUnwindSehScope // State0: filter100427dd, handler10042801, enclosing state -1.
        call __SEH_prolog
        and dword ptr [ebp-4],0 // Activate the only scope before decrementing the caller's count slot.
    preceding_element:
        dec dword ptr [ebp+0x10] // Wrapping32 decrement followed by a signed test; zero becomes -1.
        js unwind_complete
        mov ecx,dword ptr [ebp+8]
        sub ecx,dword ptr [ebp+0xc] // Unlike the main iterator, stride reloads each iteration.
        mov dword ptr [ebp+8],ecx // Publish the current cursor BEFORE entering the thiscall destructor.
        call dword ptr [ebp+0x14]
        jmp preceding_element
    unwind_complete: // Selected entry100427d1 is also the handler's continuation.
        or dword ptr [ebp-4],0xffffffff
        call __SEH_epilog
        ret 0x10
    }
}

// R6Engine.dll @ 100427dd : ArrayUnwindExceptionFilter
// Returns continue-search for other exception codes; terminates on the MSVC C++ exception code.
__declspec(naked) int ArrayUnwindExceptionFilter(void)
{
    __asm {
        mov eax,dword ptr [ebp-0x14] // _except_handler3 supplies EXCEPTION_POINTERS in the inherited frame.
        mov dword ptr [ebp-0x1c],eax
        mov eax,dword ptr [ebp-0x1c]
        mov eax,dword ptr [eax] // EXCEPTION_POINTERS.ExceptionRecord.
        mov dword ptr [ebp-0x20],eax
        mov eax,dword ptr [ebp-0x20]
        cmp dword ptr [eax],0xe06d7363 // EXCEPTION_RECORD.ExceptionCode; no null checks in native code.
        je terminate_cpp_exception
        mov dword ptr [ebp-0x24],0
        mov eax,dword ptr [ebp-0x24]
        ret
    terminate_cpp_exception: // Noncontiguous native continuation10042806–1004280c; handler lies between spans.
        call TerminateImportThunk
        int 3 // Preserved fallback if the imported termination routine unexpectedly returns.
    }
}

// R6Engine.dll @ 10042801 : ArrayUnwindExceptionHandler
// Restores the inherited saved stack and joins the array-unwind epilogue without adding a return frame.
__declspec(naked) void ArrayUnwindExceptionHandler(void)
{
    __asm {
        mov esp,dword ptr [ebp-0x18]
        jmp ArrayUnwindCompletionNativeEntry
    }
}

// R6Engine.dll @ 1004280c : _eh_vector_destructor_iterator_
// Destroys the array backward and unwinds the remaining prefix if an element destructor escapes.
__declspec(naked) void __stdcall _eh_vector_destructor_iterator_(void* elementCursor, uint elementSize,
    int remainingCount, void (__thiscall* destroyElement)(void*))
{
    __asm {
        push 0xc
        push offset arrayDestructionSehScope // State0 finally routine10042854; no filter, enclosing state -1.
        call __SEH_prolog
        and dword ptr [ebp-0x1c],0 // Completion flag, checked on both normal and exceptional exits.
        mov esi,dword ptr [ebp+0xc] // Freeze the normal-loop stride across callbacks.
        mov eax,esi
        imul eax,dword ptr [ebp+0x10]
        add dword ptr [ebp+8],eax // Cursor starts at base + low32(stride*count), without validation.
        and dword ptr [ebp-4],0
    destroy_previous:
        dec dword ptr [ebp+0x10]
        js destruction_complete
        sub dword ptr [ebp+8],esi
        mov ecx,dword ptr [ebp+8]
        call dword ptr [ebp+0x14] // Count/cursor already exclude this element if it throws.
        jmp destroy_previous
    destruction_complete:
        mov dword ptr [ebp-0x1c],1
        or dword ptr [ebp-4],0xffffffff
        call UnwindArrayDestructorIterator // Normal call remains present; completion flag makes it a no-op.
        call __SEH_epilog
        ret 0x10
    }
}

// R6Engine.dll @ 10042854 : UnwindArrayDestructorIterator
// On exceptional exit, destroys only the elements preceding the destructor that escaped.
__declspec(naked) void UnwindArrayDestructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x1c],0
        jne iterator_finished
        push dword ptr [ebp+0x14] // Callback, remaining count, current stride and published cursor.
        push dword ptr [ebp+0x10]
        push dword ptr [ebp+0xc]
        push dword ptr [ebp+8]
        call __ArrayUnwind // stdcall consumes these sixteen bytes; no synthetic funclet frame.
    iterator_finished:
        ret
    }
}

// R6Engine.dll @ 10042b8a : TerminateImportThunk
// Forwards the incoming context directly to the imported MSVC termination routine.
__declspec(naked) void TerminateImportThunk(void)
{
    __asm { jmp dword ptr [CrtTerminateImport] }
}

// R6Engine.dll @ 10042b90 : Installs the caller's SEH record and saves its frame and nonvolatile registers.
__declspec(naked) void __SEH_prolog(void)
{
  __asm {
    push offset ExceptHandler3ImportThunk // Local thunk to imported _except_handler3.
    mov eax,fs:[0]
    push eax
    mov eax,dword ptr [esp+0x10]
    mov dword ptr [esp+0x10],ebp
    lea ebp,[esp+0x10]
    sub esp,eax
    push ebx
    push esi
    push edi
    mov eax,dword ptr [ebp-0x8]
    mov dword ptr [ebp-0x18],esp
    push eax
    mov eax,dword ptr [ebp-0x4]
    mov dword ptr [ebp-0x4],0xffffffff
    mov dword ptr [ebp-0x8],eax
    lea eax,[ebp-0x10]
    mov fs:[0],eax
    ret
  }
}

// R6Engine.dll @ 10042bcb : Restores the enclosing SEH chain, saved registers, frame, and continuation.
__declspec(naked) void __SEH_epilog(void)
{
  __asm {
    mov ecx,dword ptr [ebp-0x10]
    mov dword ptr fs:[0],ecx
    pop ecx
    pop edi
    pop esi
    pop ebx
    leave
    push ecx
    ret
  }
}

// R6Engine.dll @ 10042bdc : ExceptHandler3ImportThunk
// Preserves the complete dispatcher frame, registers and return contract while entering imported _except_handler3.
__declspec(naked) void ExceptHandler3ImportThunk(void)
{
    __asm { jmp dword ptr [CrtExceptHandler3Import] }
}

// R6Engine.dll @ 1004286c : _eh_vector_constructor_iterator_
// Constructs elements forward and destroys only completed elements when a constructor escapes.
__declspec(naked) void __stdcall _eh_vector_constructor_iterator_(void* elementCursor, uint elementSize,
    int elementCount, void (__thiscall* constructElement)(void*), void (__thiscall* destroyElement)(void*))
{
    __asm {
        push 0x10
        push offset arrayConstructionSehScope // State0 finally routine100428b6.
        call __SEH_prolog
        xor eax,eax
        mov dword ptr [ebp-0x20],eax // Completion flag.
        mov dword ptr [ebp-4],eax
        mov dword ptr [ebp-0x1c],eax // Completed count, initially zero even for a negative requested count.
    construct_next:
        mov eax,dword ptr [ebp-0x1c]
        cmp eax,dword ptr [ebp+0x10]
        jge construction_complete
        mov esi,dword ptr [ebp+8] // Retain this element's address across its constructor callback.
        mov ecx,esi
        call dword ptr [ebp+0x14]
        add esi,dword ptr [ebp+0xc] // Reload stride AFTER the successful constructor.
        mov dword ptr [ebp+8],esi
        inc dword ptr [ebp-0x1c] // Neither cursor nor completed count advances when the callback throws.
        jmp construct_next
    construction_complete:
        mov dword ptr [ebp-0x20],1
        or dword ptr [ebp-4],0xffffffff
        call UnwindArrayConstructorIterator
        call __SEH_epilog
        ret 0x14
    }
}

// R6Engine.dll @ 100428b6 : UnwindArrayConstructorIterator
// Uses the current cursor and completed count to unwind successfully constructed elements backward.
__declspec(naked) void UnwindArrayConstructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x20],0
        jne constructor_finished
        push dword ptr [ebp+0x18]
        push dword ptr [ebp-0x1c]
        push dword ptr [ebp+0xc]
        push dword ptr [ebp+8]
        call __ArrayUnwind
    constructor_finished:
        ret
    }
}

// R6Engine.dll @ 100428ce : _eh_vector_copy_constructor_iterator_
// Copy-constructs forward and unwinds only the completed destination prefix on failure.
__declspec(naked) void __stdcall _eh_vector_copy_constructor_iterator_(void* destinationCursor, void* sourceCursor,
    uint elementSize, int elementCount, void (__thiscall* copyConstructElement)(void*, void*),
    void (__thiscall* destroyElement)(void*))
{
    __asm {
        push 0x10
        push offset arrayCopyConstructionSehScope // State0 finally routine1004291c.
        call __SEH_prolog
        xor eax,eax
        mov dword ptr [ebp-0x20],eax
        mov dword ptr [ebp-4],eax
        mov dword ptr [ebp-0x1c],eax
    copy_next:
        mov eax,dword ptr [ebp-0x1c]
        cmp eax,dword ptr [ebp+0x14]
        jge copy_complete
        push dword ptr [ebp+0xc] // Source is the callback's sole stack argument; destination is its ECX.
        mov ecx,dword ptr [ebp+8]
        call dword ptr [ebp+0x18] // Native thiscall callback consumes its four-byte source argument.
        mov eax,dword ptr [ebp+0x10] // One fresh stride supplies both cursor updates after the callback.
        add dword ptr [ebp+8],eax
        add dword ptr [ebp+0xc],eax
        inc dword ptr [ebp-0x1c]
        jmp copy_next
    copy_complete:
        mov dword ptr [ebp-0x20],1
        or dword ptr [ebp-4],0xffffffff
        call UnwindArrayCopyConstructorIterator
        call __SEH_epilog
        ret 0x18
    }
}

// R6Engine.dll @ 1004291c : UnwindArrayCopyConstructorIterator
// Unwinds the completed destination prefix without destroying or moving the source array.
__declspec(naked) void UnwindArrayCopyConstructorIterator(void)
{
    __asm {
        cmp dword ptr [ebp-0x20],0
        jne copy_finished
        push dword ptr [ebp+0x1c]
        push dword ptr [ebp-0x1c]
        push dword ptr [ebp+0x10]
        push dword ptr [ebp+8]
        call __ArrayUnwind
    copy_finished:
        ret
    }
}

// R6Engine.dll @ 10042540 : ActorProcessEventImportThunk
// Forwards the actor receiver and three ProcessEvent arguments unchanged to the imported virtual implementation.
__declspec(naked) void ActorProcessEventImportThunk(void)
{
    __asm { jmp dword ptr [AActorProcessEventImport] }
}

// R6Engine.dll @ 1003f7c0 : _DllMain_12
// Records the module handle for every delivered notification and always accepts it.
int __stdcall _DllMain_12(void* moduleHandle, uint reason, void* reserved)
{
    dllModuleHandle = moduleHandle; // Both other arguments are unused; native RET 12 consumes all three words.
    return 1;
}

// R6Engine.dll @ 100429a9 : __onexit
// Uses the DLL callback-table references, or tail-forwards to process-wide registration for the -1 sentinel.
__declspec(naked) _onexit_t __cdecl __onexit(_onexit_t callback)
{
    __asm {
        cmp dword ptr [exitCallbacksBegin],0xffffffff
        jne use_dll_exit_table
        // Imported _onexit receives the caller's original return frame and callback word.
        jmp dword ptr [CrtOnexitImport]
    use_dll_exit_table:
        push offset exitCallbacksEnd
        push offset exitCallbacksBegin
        push dword ptr [esp+0xc]
        call __dllonexit
        add esp,0xc
        ret
    }
}

// R6Engine.dll @ 100429cf : _atexit
// Registers a void callback and maps a null registration result to -1, any nonnull result to zero.
int __cdecl _atexit(void (__cdecl* callback)(void))
{
    _onexit_t registeredCallback = __onexit((_onexit_t)callback);
    return registeredCallback != nullptr ? 0 : -1;
}

// R6Engine.dll @ 100429e1 : __CRT_INIT_12
// Initializes DLL exit callbacks on process attach and drains their mutable table on process detach.
int __stdcall __CRT_INIT_12(void* unusedModuleHandle, uint reason, void* unusedReserved)
{
    if (reason == 0) {
        if (crtAttachCount <= 0)
            return 0; // This early failure precedes the imported floating-division snapshot.
        crtAttachCount = (int)((uint)crtAttachCount - 1U);
    }
    adjustFdivSnapshot = **(const uint**)&CrtAdjustFdivImport; // Imported _adjust_fdiv variable's current word.
    if (reason == 1) {
        using Allocate = void* (__cdecl*)(uint);
        exitCallbacksBegin = (CrtExitCallback*)reinterpret_cast<Allocate&>(CrtMallocImport)(0x80);
        if (exitCallbacksBegin == nullptr)
            return 0; // A failed/repeated attach does not restore an earlier table pointer.
        *(uint*)exitCallbacksBegin &= 0U; // Native read/modify/write clears only the first word.
        exitCallbacksEnd = exitCallbacksBegin;
        __RTC_Initialize();
        _atexit(RunCrtTerminationCallbacks); // Registration failure is ignored.
        initterm((CrtExitCallback*)&cppInitializerBeginBoundary,
            (CrtExitCallback*)&cppInitializerEndBoundary);
        crtAttachCount = (int)((uint)crtAttachCount + 1U); // Only after initializer callbacks return.
    } else if (reason == 0 && exitCallbacksBegin != nullptr) {
        uint baseAddress = (uint)exitCallbacksBegin;
        for (;;) {
            exitCallbacksEnd = (CrtExitCallback*)((uint)exitCallbacksEnd - 4U);
            if ((uint)exitCallbacksEnd < baseAddress) // Native unsigned address comparison, including wrap.
                break;
            CrtExitCallback callback = *exitCallbacksEnd;
            if (callback != nullptr) {
                callback();
                baseAddress = (uint)exitCallbacksBegin; // Registration callbacks may relocate the table.
            }
        }
        using Release = void (__cdecl*)(void*);
        reinterpret_cast<Release&>(CrtFreeImport)((void*)baseAddress);
        reinterpret_cast<uint&>(exitCallbacksBegin) &= 0U; // Native RMW clear; end retains its dangling cursor.
    }
    return 1; // Other reasons only refresh _adjust_fdiv; this routine has no local exception guard.
}

// R6Engine.dll @ 10042a9f : DllCrtEntry
// Orders raw hooks, CRT state and DLL notifications, converting accepted SEH exceptions to a zero result.
__declspec(naked) int __stdcall DllCrtEntry(void* moduleHandle, uint reason, void* reserved)
{
    __asm {
        push 0xc
        push offset dllEntrySehScope
        call __SEH_prolog
        xor eax,eax
        inc eax
        mov dword ptr [ebp-0x1c],eax
        xor edi,edi
        mov dword ptr [ebp-4],edi
        mov esi,dword ptr [ebp+0xc]
        cmp esi,edi
        jne check_attach_notification
        cmp dword ptr [crtAttachCount],edi // Entry rejects count==0; the CRT detach routine rejects count<=0.
        je entry_failure
    check_attach_notification:
        cmp esi,eax
        je before_dll_attach
        cmp esi,2
        jne notify_dll
    before_dll_attach:
        mov eax,dword ptr [rawDllNotificationHook]
        cmp eax,edi
        je initialize_crt
        push dword ptr [ebp+0x10]
        push esi
        push dword ptr [ebp+8]
        call eax
        mov dword ptr [ebp-0x1c],eax
    initialize_crt:
        cmp dword ptr [ebp-0x1c],edi
        je entry_failure
        push dword ptr [ebp+0x10]
        push esi
        push dword ptr [ebp+8]
        call __CRT_INIT_12
        mov dword ptr [ebp-0x1c],eax
        cmp eax,edi
        je entry_failure
    notify_dll:
        mov ebx,dword ptr [ebp+0x10] // Reserved pointer is frozen only after successful pre-attach hooks.
        push ebx
        push esi
        push dword ptr [ebp+8]
        call _DllMain_12
        mov dword ptr [ebp-0x1c],eax
        cmp esi,1
        jne check_detach_notification
        cmp eax,edi
        jne check_detach_notification
        push ebx
        push edi
        push dword ptr [ebp+8]
        call __CRT_INIT_12 // Failed process attach rolls CRT back, retaining the DLL's zero result.
    check_detach_notification:
        cmp esi,edi
        je after_dll_detach
        cmp esi,3
        jne return_notification
    after_dll_detach:
        push ebx
        push esi
        push dword ptr [ebp+8]
        call __CRT_INIT_12
        test eax,eax
        jne check_raw_detach_hook
        mov dword ptr [ebp-0x1c],edi
    check_raw_detach_hook:
        cmp dword ptr [ebp-0x1c],edi
        je return_notification
        mov eax,dword ptr [rawDllNotificationHook] // Fresh raw-hook pointer after the DLL and CRT callbacks.
        cmp eax,edi
        je return_notification
        push ebx
        push esi
        push dword ptr [ebp+8]
        call eax
        mov dword ptr [ebp-0x1c],eax
    return_notification:
        or dword ptr [ebp-4],0xffffffff
        mov eax,dword ptr [ebp-0x1c] // Full callback result, not normalized to a byte or bool.
        jmp entry_epilogue
// R6Engine.dll @ 10042b61 : DllCrtEntryExceptionFilter
// Embedded inherited-EBP filter forwards exception code and pointers to the selected CRT exception filter.
    entry_exception_filter:
        mov eax,dword ptr [ebp-0x14]
        mov ecx,dword ptr [eax]
        mov ecx,dword ptr [ecx]
        push eax
        push ecx
        call CppExceptionFilterImportThunk
        pop ecx
        pop ecx
        ret
// R6Engine.dll @ 10042b72 : DllCrtEntryExceptionHandler
// Embedded handler restores the stack and falls into the parent's shared failure/return continuation.
    entry_exception_handler:
        mov esp,dword ptr [ebp-0x18]
    entry_failure:
        or dword ptr [ebp-4],0xffffffff
        xor eax,eax
    entry_epilogue:
        call __SEH_epilog
        ret 0xc
    }
}

// R6Engine.dll @ 10042be2 : __dllonexit
// Tail-forwards callback and mutable begin/end references to imported DLL callback-table registration.
__declspec(naked) _onexit_t __cdecl __dllonexit(_onexit_t callback, _onexit_t** begin, _onexit_t** end)
{
    __asm { jmp dword ptr [CrtDllonexitImport] }
}

// R6Engine.dll @ 10042be8 : initterm
// Tail-forwards the caller-owned half-open initializer range to the imported CRT walker.
__declspec(naked) void __cdecl initterm(void (__cdecl** begin)(void), void (__cdecl** end)(void))
{
    __asm { jmp dword ptr [CrtInittermImport] }
}

// R6Engine.dll @ 10042c76 : CppExceptionFilterImportThunk
// Preserves incoming exception code/pointers and the imported CRT filter's full decision result.
__declspec(naked) int __cdecl CppExceptionFilterImportThunk(uint exceptionCode, void* exceptionPointers)
{
    __asm { jmp dword ptr [CrtCppXcptFilterImport] }
}

// R6Engine.dll @ 10042300 : UObjectReleaseImportThunk
// Forwards Release with its stack-based receiver and unchanged unsigned32 return.
__declspec(naked) uint __stdcall UObjectReleaseImportThunk(UObject* object)
{
    __asm {
        jmp dword ptr [UObjectReleaseImport]
    }
}

// R6Engine.dll @ 10042306 : UObjectAddRefImportThunk
// Forwards AddRef with its stack-based receiver and unchanged unsigned32 return.
__declspec(naked) uint __stdcall UObjectAddRefImportThunk(UObject* object)
{
    __asm {
        jmp dword ptr [UObjectAddRefImport]
    }
}

// R6Engine.dll @ 1004230c : UObjectQueryInterfaceImportThunk
// Forwards the stack-based receiver, GUID reference and output pointer without changing the return frame.
__declspec(naked) uint __stdcall UObjectQueryInterfaceImportThunk(UObject* object,
    const FGuid& interfaceId, void** interfaceOut)
{
    __asm {
        jmp dword ptr [UObjectQueryInterfaceImport]
    }
}
