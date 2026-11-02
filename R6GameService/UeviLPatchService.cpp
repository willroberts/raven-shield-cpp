#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 1007a8cc : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchServiceDestructionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b360 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchProgressExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b3c0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchExitCauseExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b428 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchAccessBridgeExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b548 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchStatePollExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b5a8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchStateExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b608 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchAbortBridgeExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b6c0 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchStartupExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 1007b720 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo PatchStartBridgeExceptionHandlerFunctionInfo;

// Shared patch-service state and four-byte receiver slot; observed values are module-wide, not instance fields.
// R6GameService.dll data @ 10091530 : native storage identity retained.
uint GPatchServiceState = 0;
// R6GameService.dll data @ 10091534 : native storage identity retained.
uint GPatchServiceExitCause = 0;
// R6GameService.dll data @ 10091538 : native storage identity retained.
int *GPatchServiceSlot = nullptr;

// Returns the patch-service native class object without lazy lookup or initialization.
// R6GameService.dll @ 100011a0 : complete native access/frame/register order and raw ABI retained.
UClass * __cdecl UeviLPatchService::StaticClass(void)
{
  return reinterpret_cast<UClass *>(0x100915c8);
}

// Forwards object allocation to Core with cached GError and the patch-service class, ignoring requested size.
// R6GameService.dll @ 100011b0 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void * __cdecl UeviLPatchService::operator_new(uint allocationSize,UObject *outer,FName objectName,ulong objectFlags)
{
  __asm {
    // GError import points to its global cell; cache device before reading caller words and stage eight cdecl arguments.
    mov    eax,ds:R6GameServiceAddresses::Core__GErrorSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    push   0x0
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [esp+0x14]
    push   0x0
    push   edx
    push   eax
    push   ecx
    push   0x100915c8
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_StaticAllocateObjectSlot
    add    esp,0x20
    ret
  }
}

// Runs both native ConditionalDestroy calls with staged tables, then destroys UObject with exact cleanup states.
// R6GameService.dll @ 100011e0 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::~UeviLPatchService(UeviLPatchService *object)
{
  __asm {
    // Save receiver at entry-0x10; derived state0 and abstract state1 each unwind directly to-1.
    push   0xffffffff
    push   R6GameServiceAddresses::PatchServiceDestructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0x8],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::UeviLPatchServiceDispatchTable
    // Cache ConditionalDestroy target once, invoke it with derived table, then load the current imported base table.
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot
    mov    DWORD PTR [esp+0x14],0x0
    call   edi
    mov    eax,ds:R6GameServiceAddresses::R6Abstract___7UR6AbstractEviLPatchServiceSlot
    mov    DWORD PTR [esi],eax
    // The second call reuses the cached target; lower state before final UObject destruction and restore previous FS.
    mov    ecx,esi
    mov    DWORD PTR [esp+0x14],0x1
    call   edi
    mov    ecx,esi
    mov    DWORD PTR [esp+0x14],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUObjectSlot
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-cleans the saved destructor receiver through the imported abstract patch-service destructor.
// R6GameService.dll @ 10063050 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __cdecl CleanupPatchServiceAbstractBase(void)
{
  __asm {
    // Inherited EBP-0x10 binds receiver; map state0 transitions directly to-1.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::R6Abstract__DestroyUR6AbstractEviLPatchServiceSlot
  }
}

// Tail-cleans the saved destructor receiver through the imported UObject destructor.
// R6GameService.dll @ 10063059 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __cdecl CleanupPatchServiceUObjectBase(void)
{
  __asm {
    // Inherited EBP-0x10 binds receiver; map state1 transitions directly to-1.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUObjectSlot
  }
}

// Selects the patch-service destructor two-state native exception metadata.
// R6GameService.dll @ 10063062 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __cdecl PatchServiceDestructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchServiceDestructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Constructs UObject and installs the derived table, leaving the reflected float untouched by this native body.
// R6GameService.dll @ 10001250 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) UeviLPatchService * __thiscall UeviLPatchService::UeviLPatchService(UeviLPatchService *object)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructUObjectSlot
    // Native constructor does not initialize m_bLastUpdateTime+0x2c; object allocation/default properties are separate.
    mov    DWORD PTR [esi],R6GameServiceAddresses::UeviLPatchServiceDispatchTable
    mov    eax,esi
    pop    esi
    ret
  }
}

// Copy-constructs UObject, installs the derived table and copies the current raw m_bLastUpdateTime bits at+0x2c.
// R6GameService.dll @ 10001270 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) UeviLPatchService * __thiscall UeviLPatchService::UeviLPatchService(UeviLPatchService *object,const UeviLPatchService *source)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   edi
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructUObjectSlot2
    // Install derived table before reading source+0x2c, preserving self/overlap and base-constructor mutation effects.
    mov    DWORD PTR [esi],R6GameServiceAddresses::UeviLPatchServiceDispatchTable
    mov    eax,DWORD PTR [edi+0x2c]
    mov    DWORD PTR [esi+0x2c],eax
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Assigns UObject then copies current raw reflected float bits, retaining destination vtable behavior.
// R6GameService.dll @ 100012a0 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) UeviLPatchService * __thiscall UeviLPatchService::operator=(UeviLPatchService *object,const UeviLPatchService *source)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   edi
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4UObjectSlot
    // Read source bits only after base assignment; do not add a self-assignment guard or derived-table store.
    mov    eax,DWORD PTR [edi+0x2c]
    mov    DWORD PTR [esi+0x2c],eax
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Deletes scalar or array patch-service objects using native cookie, flag bits, allocator paths and return addresses.
// R6GameService.dll @ 100012c0 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void * __thiscall UeviLPatchService::VectorDeletingDestructor(UeviLPatchService *object,byte flags)
{
  __asm {
    // Bit1 chooses array-cookie path; bit0 independently requests storage release.
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je Branch2
    // Read count from receiver-4, invoke iterator with stride0x30/destructor11e0, and return the cookie base.
    mov    eax,DWORD PTR [esi-0x4]
    push   edi
    push   R6GameServiceAddresses::UeviLPatchService__UeviLPatchService
    lea    edi,[esi-0x4]
    push   eax
    push   0x30
    push   esi
    call   R6GameServiceAddresses::_eh_vector_destructor_iterator_
    test   bl,0x1
    je Branch1
    // Load current GMalloc cell/object/table after iteration; free cookie through virtual slot8 if bit0 is set.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   edi
    call   DWORD PTR [edx+0x8]
  Branch1:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch2:
    // Scalar path calls the actual destructor, then optional sized Core delete with receiver and0x30.
    mov    ecx,esi
    call   R6GameServiceAddresses::UeviLPatchService__UeviLPatchService
    test   bl,0x1
    je Branch3
    push   0x30
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__3UObjectSlot
    add    esp,0x8
  Branch3:
    mov    eax,esi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Tail-enters the canonical constructor for nonnull supplied memory; null preserves incoming EAX.
// R6GameService.dll @ 10001d70 : complete native access/frame/register order and raw ABI retained.
__declspec(naked) void __cdecl UeviLPatchService::InternalConstructor(void *memory)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je Branch4
    jmp    R6GameServiceAddresses::UeviLPatchService_UeviLPatchService
  Branch4:
    ret
  }
}

// R6GameService.dll @ 1006a0d0 : initialize UeviLPatchService class metadata and register its cleanup
void InitializeUeviLPatchServiceClassMetadata(void)
{
  UClass *withinClass;
  UClass *parentClass;
  ushort *configName;
  undefined4 constructionFlags;
  code *nativeConstructor;
  code *staticConstructor;

  parentClass = (UClass *)UR6AbstractEviLPatchService_PrivateStaticClass_exref;
  withinClass = (UClass *)UObject_PrivateStaticClass_exref;
  nativeConstructor = UeviLPatchService::InternalConstructor;
  constructionFlags = 0x4084004;
  staticConstructor = UObject_StaticConstructor_exref;
  configName = UObject::StaticConfigName();
  UClass::UClass(&UeviLPatchService::PrivateStaticClass,0,0x30,0,parentClass,withinClass,0,0,0,0,
                 L"eviLPatchService",GPackage,configName,constructionFlags,nativeConstructor,staticConstructor);
  _atexit(DestroyUeviLPatchServiceClassMetadata);
  return;
}

// Destroy the exported class metadata through CURRENT imported UClass destructor; keep caller stack/registers.
// R6GameService.dll @ 1006ac10 : compiler atexit cleanup tail, no own frame or return.
__declspec(naked) void DestroyUeviLPatchServiceClassMetadata(void)
{
  __asm {
    mov    ecx,0x100915c8
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUClassSlot
  }
}

// Exported native member-function slot at 0x1008c254; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecGetState;

// Registers UeviLPatchService::execGetState at native index -1 and stores the returned byte.
// R6GameService.dll @ 1006a7e0 : cdecl startup entry; result byte at 0x10092391.
void __cdecl RegisterUeviLPatchService_execGetState(void)
{
  byte registrationResult = GRegisterNative(-1,intUeviLPatchServiceexecGetState);
  *(byte *)0x10092391 = registrationResult;
}

// Exported native member-function slot at 0x1008c258; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecCanRunUpdateService;

// Registers UeviLPatchService::execCanRunUpdateService at native index 3109 and stores the returned byte.
// R6GameService.dll @ 1006a800 : cdecl startup entry; result byte at 0x10092404.
void __cdecl RegisterUeviLPatchService_execCanRunUpdateService(void)
{
  byte registrationResult = GRegisterNative(3109,intUeviLPatchServiceexecCanRunUpdateService);
  *(byte *)0x10092404 = registrationResult;
}

// Exported native member-function slot at 0x1008c25c; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecGetExitCause;

// Registers UeviLPatchService::execGetExitCause at native index 3107 and stores the returned byte.
// R6GameService.dll @ 1006a820 : cdecl startup entry; result byte at 0x10091e80.
void __cdecl RegisterUeviLPatchService_execGetExitCause(void)
{
  byte registrationResult = GRegisterNative(3107,intUeviLPatchServiceexecGetExitCause);
  *(byte *)0x10091e80 = registrationResult;
}

// Exported native member-function slot at 0x1008c260; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecAbortPatchService;

// Registers UeviLPatchService::execAbortPatchService at native index 3106 and stores the returned byte.
// R6GameService.dll @ 1006a840 : cdecl startup entry; result byte at 0x10092e60.
void __cdecl RegisterUeviLPatchService_execAbortPatchService(void)
{
  byte registrationResult = GRegisterNative(3106,intUeviLPatchServiceexecAbortPatchService);
  *(byte *)0x10092e60 = registrationResult;
}

// Exported native member-function slot at 0x1008c264; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecGetDownloadProgress;

// Registers UeviLPatchService::execGetDownloadProgress at native index 3105 and stores the returned byte.
// R6GameService.dll @ 1006a860 : cdecl startup entry; result byte at 0x100923f4.
void __cdecl RegisterUeviLPatchService_execGetDownloadProgress(void)
{
  byte registrationResult = GRegisterNative(3105,intUeviLPatchServiceexecGetDownloadProgress);
  *(byte *)0x100923f4 = registrationResult;
}

// Exported native member-function slot at 0x1008c268; its value is read when registration runs.
extern "C" Native intUeviLPatchServiceexecStartPatch;

// Registers UeviLPatchService::execStartPatch at native index 3102 and stores the returned byte.
// R6GameService.dll @ 1006a880 : cdecl startup entry; result byte at 0x10092919.
void __cdecl RegisterUeviLPatchService_execStartPatch(void)
{
  byte registrationResult = GRegisterNative(3102,intUeviLPatchServiceexecStartPatch);
  *(byte *)0x10092919 = registrationResult;
}

// Publishes this class's metadata address in its exported autoclass pointer slot.
// R6GameService.dll @ 1006a160 : cdecl startup entry; pointer slot 0x10091ad0.
void __cdecl InitializeAutoclassUeviLPatchService(void)
{
  *(UClass **)0x10091ad0 = &UeviLPatchService::PrivateStaticClass;
}

// Finishes VM parameters/debug info, conditionally refreshes shared exit cause and stores its full32 bits.
// R6GameService.dll @ 100045e0 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execGetExitCause(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    // Establish EBP/EH before all frame accesses; output and service/cache words are loaded at their native late points.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchExitCauseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    // Advance Code unconditionally;0x42 is EX_DebugInfo. Dispatch uses frame.Object as ECX and frame/null as stack words.
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne Branch5
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch5:
    // Reload service after debug dispatch; query only for nonnull slot and zero cache, then store entire query EAX.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    test   ecx,ecx
    je Branch6
    mov    eax,ds:R6GameServiceAddresses::GPatchServiceExitCause
    test   eax,eax
    jne Branch6
    call   R6GameServiceAddresses::GetServiceExitCauseThroughStoredReceiver
    mov    ds:R6GameServiceAddresses::GPatchServiceExitCause,eax
  Branch6:
    // Reload original result argument after query; store full exit word despite ByteProperty reflection.
    mov    ecx,DWORD PTR [ebp+0xc]
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceExitCause
    pop    edi
    mov    DWORD PTR [ecx],edx
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught pointer from parent EBP-0x18 to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 10004667 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchExitCauseWidePointer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports method and current script context/offset through cached imports, then rethrows the active exception.
// R6GameService.dll @ 1000467b : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchExitCauseException(void)
{
  __asm {
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecGetExitCause
    push   R6GameServiceAddresses::WideTextTextFormat
    call   edi
    // Read current parent Frame/Node/Code after first log; compute unsigned offset before full-name callbacks.
    mov    esi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi+0xc]
    mov    edx,DWORD PTR [ecx+0x4c]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    add    esp,0x8
    sub    eax,edx
    push   eax
    push   0x0
    call   ebx
    // Reload Frame.Object after node-name lookup; logger/name getter targets remain cached across both calls.
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    push   0x0
    call   ebx
    push   eax
    push   R6GameServiceAddresses::WideTextSS04X
    call   edi
    add    esp,0x10
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects native exit-cause bridge exception metadata.
// R6GameService.dll @ 100635a0 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchExitCauseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchExitCauseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finishes VM parameters/debug info, queries current patch state and stores its full32 bits.
// R6GameService.dll @ 10004d30 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execGetState(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    // Establish EBP/EH; selected build has no Stack.Native guard around its Code advance.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchStateExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne Branch7
    // Frame.Object is the debug receiver; GNatives import is the table address, indexed by0x42*4.
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch7:
    // Call static state getter, then reload original result argument and publish all32 bits of EAX.
    call   R6GameServiceAddresses::UeviLPatchService_GetPatchServiceState
    mov    ecx,DWORD PTR [ebp+0xc]
    pop    edi
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught pointer from parent EBP-0x18 to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 10004d99 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchStateWidePointer(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports the state-bridge method context before rethrowing the active exception.
// R6GameService.dll @ 10004dad : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchStateException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecGetState
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects native state bridge exception metadata.
// R6GameService.dll @ 10063680 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchStateExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchStateExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Registers the state callback and constructs/configures the shared service slot only when it is absent.
// R6GameService.dll @ 10005030 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::StartPatch(UeviLPatchService *object)
{
  __asm {
    // EH installs even when the shared slot already exists; state0 is live before the initial absence test.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchStartupExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:R6GameServiceAddresses::GPatchServiceSlot
    push   ebx
    push   esi
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],ebx
    jne Branch10
    // Install static callback before resetting shared state/exit; load allocator after callback, then reset before Malloc.
    push   R6GameServiceAddresses::UeviLPatchService_GetPatchServiceState
    call   DWORD PTR ds:R6GameServiceAddresses::R6Abstract_UR6AbstractEviLPatchService_SetFunctionPtrSlot
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x4
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceState,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceExitCause,ebx
    call   DWORD PTR [edx]
    // Stage raw four-byte allocation at EBP-0x18; only low state byte becomes1 around service construction.
    mov    ecx,eax
    mov    DWORD PTR [ebp-0x18],ecx
    cmp    ecx,ebx
    mov    BYTE PTR [ebp-0x4],0x1
    je Branch8
    call   R6GameServiceAddresses::CreateServiceObjectInPointerSlot
    mov    ecx,eax
    jmp Branch9
  Branch8:
    xor    ecx,ecx
  Branch9:
    // Lower low state byte before slot publication; configure even a null result and ignore helper statuses.
    push   0xfa
    mov    BYTE PTR [ebp-0x4],bl
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot,ecx
    call   R6GameServiceAddresses::SetServiceCacheInterval
    // Reload shared slot between configuration calls, preserving external-call mutations.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    push   R6GameServiceAddresses::WideTextRavenShield
    call   R6GameServiceAddresses::StoreWideStringAndPrintStart
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    push   ebx
    push   ebx
    push   R6GameServiceAddresses::WideTextUpgradeLauncherExe
    call   R6GameServiceAddresses::StartUpdateServiceThroughStoredReceiver
  Branch10:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Copies the caught pointer from parent EBP-0x1c to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 100050e6 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchStartupWidePointer(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x14]
    push   ecx
    mov    DWORD PTR [ebp-0x14],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports StartPatch context before rethrowing the active exception.
// R6GameService.dll @ 100050fa : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchStartupException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceStartPatch
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Releases raw startup allocation from parent EBP-0x18 and pops that argument into ECX.
// R6GameService.dll @ 100636e0 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleasePatchStartupAllocation(void)
{
  __asm {
    // Inherited EBP-0x18 is raw allocation; cdecl free1180 leaves argument for native POP ECX before RET.
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Selects native startup exception metadata with its raw-allocation cleanup action.
// R6GameService.dll @ 100636eb : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchStartupExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchStartupExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finishes VM parameters/debug info and calls StartPatch with its cached receiver, leaving result untouched.
// R6GameService.dll @ 10005120 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execStartPatch(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    // Cache patch receiver in ESI before optional debug dispatch, then restore it for nested StartPatch.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchStartBridgeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    push   ebx
    inc    edx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne Branch11
    // Advance past EX_DebugInfo before invoking GNatives[0x42] with frame.Object receiver.
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch11:
    mov    ecx,esi
    call   R6GameServiceAddresses::UeviLPatchService_StartPatch
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught pointer from parent EBP-0x18 to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 10005188 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchStartBridgeWidePointer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports method and current script context/offset through cached imports, then rethrows the active exception.
// R6GameService.dll @ 1000519c : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchStartBridgeException(void)
{
  __asm {
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecStartPatch
    push   R6GameServiceAddresses::WideTextTextFormat
    call   edi
    // Read current parent Frame/Node/Code after first log; compute unsigned offset before full-name callbacks.
    mov    esi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi+0xc]
    mov    edx,DWORD PTR [ecx+0x4c]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    add    esp,0x8
    sub    eax,edx
    push   eax
    push   0x0
    call   ebx
    mov    ecx,DWORD PTR [esi+0x8]
    // Reload Frame.Object after node-name lookup; logger/name getter targets remain cached across both calls.
    push   eax
    push   0x0
    call   ebx
    push   eax
    push   R6GameServiceAddresses::WideTextSS04X
    call   edi
    add    esp,0x10
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects native script-start bridge exception metadata.
// R6GameService.dll @ 10063700 : complete native EBP/frame/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchStartBridgeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchStartBridgeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroys/frees the cached service through the current allocator, then clears the shared slot.
// R6GameService.dll @ 10004850 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UeviLPatchService::FinalDestroy(void)
{
  __asm {
    // Cache allocation receiver in ESI; reload GMalloc only after destruction, and clear slot only after successful free.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    test   ecx,ecx
    push   esi
    mov    esi,ecx
    je Branch12
    call   R6GameServiceAddresses::DestroyServiceObjectInPointerSlot
    mov    eax,ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [edx+0x8]
  Branch12:
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot,0x0
    pop    esi
    ret
  }
}

// Polls the launcher event, creates or releases the shared service and caches state/exit before completion logging.
// R6GameService.dll @ 10004b80 : complete native control/access order and raw ABI retained.
__declspec(naked) ulong __cdecl UeviLPatchService::GetPatchServiceState(void)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchStatePollExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x10
    mov    eax,ds:R6GameServiceAddresses::GPatchServiceSlot
    push   ebx
    push   esi
    xor    ebx,ebx
    cmp    eax,ebx
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    // State0 covers event polling, cleanup and published-service configuration; only construction enters state1.
    mov    DWORD PTR [ebp-0x4],ebx
    jne Branch18
    push   R6GameServiceAddresses::TextUpgradeLauncherUniqueInstance
    push   ebx
    push   0x1f0003
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_OpenEventASlot
    // Cache nonzero event result before CloseHandle, which is invoked even for a null handle.
    xor    ecx,ecx
    cmp    eax,ebx
    setne  cl
    push   eax
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CloseHandleSlot
    cmp    esi,ebx
    je Branch17
    // Load current allocator before resetting state/exit; allocate four bytes without registering the StartPatch callback.
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    push   R6GameServiceAddresses::WideTextNew
    push   0x4
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceState,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceExitCause,ebx
    call   DWORD PTR [eax]
    mov    ecx,eax
    // Raw allocation lives at EBP-0x18; low state byte1 covers construction only.
    mov    DWORD PTR [ebp-0x18],ecx
    cmp    ecx,ebx
    mov    BYTE PTR [ebp-0x4],0x1
    je Branch13
    call   R6GameServiceAddresses::CreateServiceObjectInPointerSlot
    mov    ecx,eax
    jmp Branch14
  Branch13:
    xor    ecx,ecx
  Branch14:
    // Lower state before publishing constructor result; configure even null, reloading slot between calls.
    push   0xfa
    mov    BYTE PTR [ebp-0x4],bl
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot,ecx
    call   R6GameServiceAddresses::SetServiceCacheInterval
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    push   R6GameServiceAddresses::WideTextRavenShield
    call   R6GameServiceAddresses::StoreWideStringAndPrintStart
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    push   ebx
    push   ebx
    push   R6GameServiceAddresses::WideTextUpgradeLauncherExe
    call   R6GameServiceAddresses::StartUpdateServiceThroughStoredReceiver
  Branch15:
    // Reload slot/state; poll unless slot is null or cached state is exactly5.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    cmp    ecx,ebx
    je Branch16
    cmp    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceState,0x5
    je Branch16
    call   R6GameServiceAddresses::GetServiceStateThroughStoredReceiver
    // Publish complete returned state; only exact5 queries exit and logs/requests abort through the current slot.
    cmp    eax,0x5
    mov    ds:R6GameServiceAddresses::GPatchServiceState,eax
    jne Branch16
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    call   R6GameServiceAddresses::GetServiceExitCauseThroughStoredReceiver
    mov    ds:R6GameServiceAddresses::GPatchServiceExitCause,eax
    call   R6GameServiceAddresses::LogAndAbortUpdateService
  Branch16:
    // Return current shared state after all callbacks, preserving their mutations.
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    eax,ds:R6GameServiceAddresses::GPatchServiceState
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  Branch17:
    // First null-event path reloads slot after CloseHandle; a newly published slot triggers a second event probe.
    cmp    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot,ebx
    je Branch16
  Branch18:
    push   R6GameServiceAddresses::TextUpgradeLauncherUniqueInstance
    push   ebx
    push   0x1f0003
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_OpenEventASlot
    // Cache second event result before closing its handle; branch ignores CloseHandle status.
    xor    ecx,ecx
    cmp    eax,ebx
    setne  cl
    push   eax
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::KERNEL32_CloseHandleSlot
    cmp    esi,ebx
    jne Branch15
    // Load current slot, publish state5 and cache pointer before destruction; free uses the later allocator chain.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    cmp    ecx,ebx
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceState,0x5
    mov    esi,ecx
    je Branch19
    call   R6GameServiceAddresses::DestroyServiceObjectInPointerSlot
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [edx]
    mov    eax,DWORD PTR [ecx]
    push   esi
    call   DWORD PTR [eax+0x8]
  Branch19:
    // Clear slot only after successful destruction/free; reload current shared state in common return.
    mov    DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot,ebx
    jmp Branch16
  }
}

// Copies the caught pointer from parent EBP-0x1c to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 10004cf3 : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchStatePollWidePointer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports the static patch-state method context and rethrows the active exception.
// R6GameService.dll @ 10004d07 : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchStatePollException(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceGetPatchServiceState
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Releases the raw poll-startup allocation from parent EBP-0x18, popping the argument into ECX.
// R6GameService.dll @ 10063660 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ReleasePatchStatePollAllocation(void)
{
  __asm {
    // Inherited EBP-0x18 is raw allocation; cdecl free leaves its copied argument for native POP ECX.
    mov    eax,DWORD PTR [ebp-0x18]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    pop    ecx
    ret
  }
}

// Selects native state-poll metadata with its constructor-only raw-allocation cleanup action.
// R6GameService.dll @ 1006366b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchStatePollExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchStatePollExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Finishes VM parameters/debug info, logs ABORT CALLED and forwards through the current slot without writing result.
// R6GameService.dll @ 10004dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execAbortPatchService(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchAbortBridgeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne Branch20
    // EX_DebugInfo42 advances Code again, then dispatches GNatives[42] with Frame.Object receiver.
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch20:
    // Get stream and insert text before loading endl; this differs from the free logging helper early cache.
    call   R6GameServiceAddresses::GetDirectoryLogFirstWord
    push   R6GameServiceAddresses::TextABORTCALLED
    push   eax
    call   R6GameServiceAddresses::InsertAnsiTextIntoWideStream
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::MSVCP71_std_endlSlot
    add    esp,0x8
    push   ecx
    mov    ecx,eax
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_6_basic_ostreamSlot
    // Reload service after logging; leave result untouched and forward raw helper EAX.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    test   ecx,ecx
    je Branch21
    call   R6GameServiceAddresses::RequestAbortUpdateServiceThroughStoredReceiver
  Branch21:
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies the caught pointer from parent EBP-0x18 to-0x14 and throws it with the native pointer ThrowInfo.
// R6GameService.dll @ 10004e60 : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchAbortBridgeWidePointer(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports method and current script context/offset through cached imports, then rethrows the active exception.
// R6GameService.dll @ 10004e74 : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchAbortBridgeException(void)
{
  __asm {
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecAbortPatchService
    push   R6GameServiceAddresses::WideTextTextFormat
    call   edi
    // Read current Frame/Node/Code after first log, then cache GetFullName target and offset.
    mov    esi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [ecx+0x4c]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    add    esp,0x8
    sub    edx,eax
    push   edx
    push   0x0
    call   ebx
    // Reload Frame.Object after node-name callback; both logger and name getter targets remain cached.
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    push   0x0
    call   ebx
    push   eax
    push   R6GameServiceAddresses::WideTextSS04X
    call   edi
    add    esp,0x10
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Selects native abort-bridge exception metadata with no cleanup actions.
// R6GameService.dll @ 10063690 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchAbortBridgeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchAbortBridgeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tests access to the current directory and stores the raw helper AL as a zero-extended DWORD before string cleanup.
// R6GameService.dll @ 100046d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execCanRunUpdateService(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchAccessBridgeExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x2c
    mov    eax,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [eax+0xc]
    inc    edx
    push   ebx
    push   esi
    mov    DWORD PTR [eax+0xc],edx
    cmp    BYTE PTR [edx],0x42
    push   edi
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x4],0x0
    jne Branch22
    // EX_DebugInfo42 uses Frame.Object receiver after second Code increment; no Stack.Native guard.
    mov    ecx,DWORD PTR [eax+0x8]
    inc    edx
    push   0x0
    mov    DWORD PTR [eax+0xc],edx
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    call   DWORD PTR [eax+0x108]
  Branch22:
    // Construct std::basic_string<unsigned short> from fixed L".\" at EBP-0x38; construction runs in state0.
    push   R6GameServiceAddresses::WideTextPunctuation
    lea    ecx,[ebp-0x38]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot2
    // Push string pointer as stdcall argument; ECX points at a zeroed local byte, not an object receiver.
    lea    ecx,[ebp-0x38]
    push   ecx
    lea    ecx,[ebp-0x11]
    mov    BYTE PTR [ebp-0x4],0x1
    mov    BYTE PTR [ebp-0x11],0x0
    call   R6GameServiceAddresses::TestDirectoryCreateDeleteAccess
    // Zero-extend raw AL into a DWORD result; load result argument after helper, then lower state before destructor.
    movzx  edx,al
    mov    eax,DWORD PTR [ebp+0xc]
    lea    ecx,[ebp-0x38]
    mov    DWORD PTR [eax],edx
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies parent EBP-0x1c caught pointer to EBP-0x18 and throws it with native pointer ThrowInfo.
// R6GameService.dll @ 10004766 : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchAccessBridgeWidePointer(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x18]
    push   edx
    mov    DWORD PTR [ebp-0x18],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports method and current script context/offset through cached imports, then rethrows the active exception.
// R6GameService.dll @ 1000477a : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchAccessBridgeException(void)
{
  __asm {
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecCanRunUpdateService
    push   R6GameServiceAddresses::WideTextTextFormat
    call   edi
    // Read current parent Frame after first log; cache full-name target and unsigned script offset.
    mov    esi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    eax,DWORD PTR [esi+0xc]
    mov    edx,DWORD PTR [ecx+0x4c]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    add    esp,0x8
    sub    eax,edx
    push   eax
    push   0x0
    call   ebx
    // Reload Frame.Object after Node name callback while retaining cached import targets.
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    push   0x0
    call   ebx
    push   eax
    push   R6GameServiceAddresses::WideTextSS04X
    call   edi
    add    esp,0x10
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Tail-destroys the access bridge wide directory string at parent EBP-0x38.
// R6GameService.dll @ 100635b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPatchAccessDirectory(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects native access-bridge metadata with its temporary-directory cleanup action.
// R6GameService.dll @ 100635b9 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchAccessBridgeExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchAccessBridgeExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Evaluates four float out-references, polls service progress in states2/4 and narrows doubles in native copy-back order.
// R6GameService.dll @ 10004310 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UeviLPatchService::execGetDownloadProgress(UeviLPatchService *object,FFrame *frame,void *result)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::PatchProgressExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x88
    // GPropAddr/Object/Property imports point to mutable Core globals; frame receiver is cached in ESI.
    mov    eax,ds:R6GameServiceAddresses::Core__GPropAddrSlot
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    xor    ebx,ebx
    // First float ref: clear fallback and GPropAddr; evaluate token with current Frame.Object receiver.
    mov    DWORD PTR [ebp-0x18],ebx
    mov    DWORD PTR [eax],ebx
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   edi
    mov    DWORD PTR [esi+0xc],eax
    mov    DWORD PTR [ebp-0x10],esp
    lea    eax,[ebp-0x18]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    mov    DWORD PTR [ebp-0x4],ebx
    call   DWORD PTR [eax+edx*4]
    // If GPropObject is live, call virtual+0x60 with current GProperty (UE2 P_GET_FLOAT_REF NetDirty pattern).
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropObjectSlot
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,ebx
    je Branch23
    mov    eax,ds:R6GameServiceAddresses::Core__GPropertySlot
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x60]
  Branch23:
    // Select GPropAddr after NetDirty callback or local fallback; retain pointer at EBP-0x1c.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebx
    je Branch24
    mov    DWORD PTR [ebp-0x1c],eax
    jmp Branch25
  Branch24:
    lea    edx,[ebp-0x18]
    mov    DWORD PTR [ebp-0x1c],edx
  Branch25:
    // Second ref repeats evaluation/dirty/select, retaining pointer at EBP-0x24 and fallback at-0x28.
    mov    DWORD PTR [ebp-0x28],0x0
    mov    DWORD PTR [ecx],ebx
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x28]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropObjectSlot
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,ebx
    je Branch26
    mov    eax,ds:R6GameServiceAddresses::Core__GPropertySlot
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x60]
  Branch26:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebx
    je Branch27
    mov    DWORD PTR [ebp-0x24],eax
    jmp Branch28
  Branch27:
    lea    edx,[ebp-0x28]
    mov    DWORD PTR [ebp-0x24],edx
  Branch28:
    // Third ref repeats evaluation/dirty/select, retaining pointer at EBP-0x2c and fallback at-0x20.
    mov    DWORD PTR [ebp-0x20],0x0
    mov    DWORD PTR [ecx],ebx
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x20]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropObjectSlot
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,ebx
    je Branch29
    mov    eax,ds:R6GameServiceAddresses::Core__GPropertySlot
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x60]
  Branch29:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebx
    je Branch30
    mov    DWORD PTR [ebp-0x2c],eax
    jmp Branch31
  Branch30:
    lea    edx,[ebp-0x20]
    mov    DWORD PTR [ebp-0x2c],edx
  Branch31:
    // Fourth ref repeats evaluation/dirty/select; selected pointer survives debug and service callbacks in EDI.
    mov    DWORD PTR [ebp-0x14],0x0
    mov    DWORD PTR [ecx],ebx
    mov    eax,DWORD PTR [esi+0xc]
    movzx  edx,BYTE PTR [eax]
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    mov    DWORD PTR [esi+0xc],eax
    lea    eax,[ebp-0x14]
    push   eax
    mov    eax,ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [eax+edx*4]
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropObjectSlot
    mov    ecx,DWORD PTR [ecx]
    cmp    ecx,ebx
    je Branch32
    mov    eax,ds:R6GameServiceAddresses::Core__GPropertySlot
    mov    eax,DWORD PTR [eax]
    mov    edx,DWORD PTR [ecx]
    push   eax
    call   DWORD PTR [edx+0x60]
  Branch32:
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GPropAddrSlot
    mov    eax,DWORD PTR [ecx]
    cmp    eax,ebx
    mov    edi,eax
    jne Branch33
    lea    edi,[ebp-0x14]
  Branch33:
    // Skip end-parameters byte, then optionally dispatch EX_DebugInfo42 with current Frame.Object receiver.
    mov    edx,DWORD PTR [esi+0xc]
    inc    edx
    mov    eax,edx
    mov    DWORD PTR [esi+0xc],edx
    cmp    BYTE PTR [eax],0x42
    jne Branch34
    mov    ecx,DWORD PTR [esi+0x8]
    inc    eax
    push   ebx
    mov    DWORD PTR [esi+0xc],eax
    mov    edx,DWORD PTR ds:R6GameServiceAddresses::Core__GNativesSlot
    push   esi
    call   DWORD PTR [edx+0x108]
  Branch34:
    // Load four native +0.0 doubles and clear two auxiliary words; result argument is untouched.
    fld    QWORD PTR ds:R6GameServiceAddresses::GSharedDoubleZero
    lea    ecx,[ebp-0x94]
    fstp   QWORD PTR [ebp-0x58]
    mov    DWORD PTR [ebp-0x30],ebx
    fld    QWORD PTR ds:R6GameServiceAddresses::GSharedDoubleZero
    mov    DWORD PTR [ebp-0x34],ebx
    fstp   QWORD PTR [ebp-0x40]
    fld    QWORD PTR ds:R6GameServiceAddresses::GSharedDoubleZero
    fstp   QWORD PTR [ebp-0x48]
    fld    QWORD PTR ds:R6GameServiceAddresses::GSharedDoubleZero
    fstp   QWORD PTR [ebp-0x50]
    // First default wide constructor runs in state0; second in state1; each owns cleanup only after success.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    mov    bl,0x1
    lea    ecx,[ebp-0x78]
    mov    BYTE PTR [ebp-0x4],bl
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Construct_basic_stringSlot3
    // Reload shared slot/state after constructors; only nonnull slot and exact state2/4 calls progress helper.
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::GPatchServiceSlot
    test   ecx,ecx
    mov    BYTE PTR [ebp-0x4],0x2
    je Branch36
    mov    eax,ds:R6GameServiceAddresses::GPatchServiceState
    cmp    eax,0x2
    je Branch35
    cmp    eax,0x4
    jne Branch36
  Branch35:
    // Helper arguments: totalBytes,totalRecvdBytes,fileBytes,fileRecvdBytes doubles, two words, two wide strings.
    lea    eax,[ebp-0x78]
    push   eax
    lea    edx,[ebp-0x94]
    push   edx
    lea    eax,[ebp-0x34]
    push   eax
    lea    edx,[ebp-0x30]
    push   edx
    lea    eax,[ebp-0x50]
    push   eax
    lea    edx,[ebp-0x48]
    push   edx
    lea    eax,[ebp-0x40]
    push   eax
    lea    edx,[ebp-0x58]
    push   edx
    call   R6GameServiceAddresses::GetDownloadProgressThroughStoredReceiver
  Branch36:
    // Keep x87 FLD/FSTP narrowing under ambient control word; first two output pointers load before first store.
    fld    QWORD PTR [ebp-0x58]
    mov    eax,DWORD PTR [ebp-0x1c]
    mov    ecx,DWORD PTR [ebp-0x24]
    fstp   DWORD PTR [eax]
    // Third output pointer loads after first store; aliases can change it or later source doubles.
    fld    QWORD PTR [ebp-0x40]
    mov    edx,DWORD PTR [ebp-0x2c]
    fstp   DWORD PTR [ecx]
    // Lower state to1 before third/fourth stores and second-string destruction, retaining native fault behavior.
    lea    ecx,[ebp-0x78]
    fld    QWORD PTR [ebp-0x48]
    mov    BYTE PTR [ebp-0x4],bl
    fstp   DWORD PTR [edx]
    fld    QWORD PTR [ebp-0x50]
    fstp   DWORD PTR [edi]
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    // Lower state to0 before first-string destruction; preserve last destructor raw EAX.
    lea    ecx,[ebp-0x94]
    mov    BYTE PTR [ebp-0x4],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0x8
  }
}

// Copies parent EBP-0x5c caught pointer to EBP-0x38 and throws it with native pointer ThrowInfo.
// R6GameService.dll @ 1000457b : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl RethrowPatchProgressWidePointer(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x5c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    ecx,[ebp-0x38]
    push   ecx
    mov    DWORD PTR [ebp-0x38],eax
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports method and current script context/offset through cached imports, then rethrows the active exception.
// R6GameService.dll @ 1000458f : complete native control/access order and raw ABI retained.
__declspec(naked) __declspec(noreturn) void __cdecl ReportPatchProgressException(void)
{
  __asm {
    mov    edi,DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    push   R6GameServiceAddresses::WideTextUeviLPatchServiceExecGetDownloadProgress
    push   R6GameServiceAddresses::WideTextTextFormat
    call   edi
    // Read current Frame/Node/Code after first log, then cache GetFullName and unsigned script offset.
    mov    esi,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [esi+0x4]
    mov    edx,DWORD PTR [esi+0xc]
    mov    eax,DWORD PTR [ecx+0x4c]
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core_UObject_GetFullNameSlot
    add    esp,0x8
    sub    edx,eax
    push   edx
    push   0x0
    call   ebx
    // Reload Frame.Object after Node name callback while retaining cached import targets.
    mov    ecx,DWORD PTR [esi+0x8]
    push   eax
    push   0x0
    call   ebx
    push   eax
    push   R6GameServiceAddresses::WideTextSS04X
    call   edi
    add    esp,0x10
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Tail-destroys the first progress string at parent EBP-0x94.
// R6GameService.dll @ 10063580 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPatchProgressFirstString(void)
{
  __asm {
    lea    ecx,[ebp-0x94]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Tail-destroys the second progress string at parent EBP-0x78.
// R6GameService.dll @ 1006358c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPatchProgressSecondString(void)
{
  __asm {
    lea    ecx,[ebp-0x78]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_GU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects native progress-bridge metadata with two staged wide-string cleanup actions.
// R6GameService.dll @ 10063595 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PatchProgressExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PatchProgressExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native virtual-table prefix: UeviLPatchServiceDispatchTable
// R6GameService.dll data @ 1006b648 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct UeviLPatchServiceDispatchTableRecord {
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember22; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember21; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember20; // +0x08
  R6GameServiceNative::Address UeviLPatchService_VectorDeletingDestructor; // +0x0c
  R6GameServiceNative::Address UObject_ProcessEvent; // +0x10
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember19; // +0x14
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember18; // +0x18
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember17; // +0x1c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember16; // +0x20
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember15; // +0x24
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember14; // +0x28
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember13; // +0x2c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember12; // +0x30
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember11; // +0x34
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember10; // +0x38
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember9; // +0x3c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember8; // +0x40
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember7; // +0x44
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember6; // +0x48
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember5; // +0x4c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember4; // +0x50
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember3; // +0x54
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember2; // +0x58
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember; // +0x5c
  R6GameServiceNative::Address core_import_supportTailImportedMember; // +0x60
};
const UeviLPatchServiceDispatchTableRecord UeviLPatchServiceDispatchTable = {
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember22,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember21,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember20,
  R6GameServiceAddresses::UeviLPatchService_VectorDeletingDestructor,
  R6GameServiceAddresses::UObject_ProcessEvent,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember19,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember18,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember17,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember16,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember15,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember14,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember13,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember12,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember11,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember10,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember9,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember8,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember7,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember6,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember5,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember4,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember3,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember2,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember,
  R6GameServiceAddresses::core_import_supportTailImportedMember,
};
