#include "native_addresses.h"
#include "native_records.h"

// RTTI-backed clMSClientClass members; incomplete declarations/layouts are not invented.

// Construct clGLClient, install this class callback tables, clear resource slots and initialize fixed byte buffers.
// RTTI: clMSClientClass table76e94/COL79064/type8e5b4, clGLClient at0; original field names remain offsets.
// Five strncpy calls use current global93bf4, capacities16/16/33/129/33, and conditionally zero the final byte.
// No own guard or post-copy rollback; base allocation/publication and earlier stores survive later faults.
// R6GameService.dll @ 10032600 : complete native control/access order and raw ABI retained.
__declspec(naked) clMSClientClass::clMSClientClass(void)
{
  __asm {
    push   ebx
    push   esi
    push   edi
    mov    esi,ecx
    call   R6GameServiceAddresses::ConstructGLClient
    lea    edi,[esi+0x18]
    push   0x10
    xor    ebx,ebx
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    mov    WORD PTR [esi+0xdc],bx
    mov    DWORD PTR [esi+0x100],ebx
    mov    DWORD PTR [esi+0x104],ebx
    mov    DWORD PTR [esi+0x108],ebx
    mov    DWORD PTR [esi+0x10c],ebx
    mov    DWORD PTR [esi+0x110],ebx
    mov    BYTE PTR [esi+0x114],bl
    mov    BYTE PTR [esi+0x115],bl
    mov    BYTE PTR [esi+0x116],bl
    mov    BYTE PTR [esi+0x117],bl
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMSClientClassVTable
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::clMSClientClassVTableAdjusted4
    mov    DWORD PTR [esi+0x8],R6GameServiceAddresses::clMSClientClassVTableAdjusted8
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clMSClientClassVTableAdjusted12
    mov    DWORD PTR [esi+0x10],R6GameServiceAddresses::clMSClientClassVTableAdjusted16
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0xf]
    add    esp,0xc
    cmp    al,bl
    je     Branch1
    mov    BYTE PTR [edi+0xf],bl
  Branch1:
    lea    edi,[esi+0x28]
    push   0x10
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0xf]
    add    esp,0xc
    cmp    al,bl
    je     Branch2
    mov    BYTE PTR [edi+0xf],bl
  Branch2:
    lea    edi,[esi+0x39]
    push   0x21
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    je     Branch3
    mov    BYTE PTR [edi+0x20],bl
  Branch3:
    lea    edi,[esi+0x5a]
    push   0x81
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x80]
    add    esp,0xc
    cmp    al,bl
    je     Branch4
    mov    BYTE PTR [edi+0x80],bl
  Branch4:
    lea    edi,[esi+0xde]
    push   0x21
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0x20]
    add    esp,0xc
    cmp    al,bl
    mov    eax,esi
    je     Branch5
    mov    BYTE PTR [edi+0x20],bl
  Branch5:
    pop    edi
    pop    esi
    pop    ebx
    ret
  }
}

// Destroy the RTTI-backed class, then conditionally free the saved receiver using the current low flag bit.
// One full physical flag word/RET4; flag BYTE is read after destruction. Base allocator wrapper1180 is cdecl.
// Returns the saved receiver; no own guard, so a throwing destructor prevents object deallocation.
// R6GameService.dll @ 10032710 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteServiceClient(void *client,uint deleteFlags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::DestroyServiceClient
    test   BYTE PTR [esp+0x8],0x1
    je     Branch6
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch6:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restore class callback tables, release current resources, then destroy the GL base exactly once.
// Raw uint view preserves GL destructor EAX; original destructor return declaration is not claimed.
// State0 protects the base during resource release; state-1 precedes normal base destruction and prevents retry.
// Runtime EBP for the sole action is entryESP, with saved receiver at-10; partial frees/clears remain on failure.
// R6GameService.dll @ 10032730 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DestroyServiceClient(void *client)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::DestroyServiceClientSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMSClientClassVTable
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::clMSClientClassVTableAdjusted4
    mov    DWORD PTR [esi+0x8],R6GameServiceAddresses::clMSClientClassVTableAdjusted8
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clMSClientClassVTableAdjusted12
    mov    DWORD PTR [esi+0x10],R6GameServiceAddresses::clMSClientClassVTableAdjusted16
    mov    DWORD PTR [esp+0x10],0x0
    call   R6GameServiceAddresses::ReleaseServiceClientResources
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   R6GameServiceAddresses::DestroyGLClient
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-destroy the saved GL base when resource release unwinds; no own frame or additional object free.
// R6GameService.dll @ 10066370 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceClientUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::DestroyGLClient
  }
}

// Select class destructor metadata and tail-enter the CRT frame handler.
// R6GameService.dll @ 10066378 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyServiceClientSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyServiceClientExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native MS class destructor unwind record; literal states and addresses.
// R6GameService.dll data @ 100806fc : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyServiceClientUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroyServiceClientUnwind1},
};

// Native MS class destructor info record; literal states and addresses.
// R6GameService.dll data @ 100806fc : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyServiceClientExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyServiceClientUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Low-byte selector26 copies argument2 into18/16, conditionally terminates, then current virtual30(26,0,18).
// Other selectors forward the original full selector/argument9/global93bf4 through current virtual30; RET36.
// Target table reloads after copy; arguments3..8 are unused. Partial string writes remain on later failure.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032d00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::DispatchSelector26StringOrVirtual(
    uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,uint word9)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x4]
    push   esi
    cmp    al,0x26
    mov    esi,ecx
    jne    Branch8
    mov    eax,DWORD PTR [esp+0xc]
    push   edi
    lea    edi,[esi+0x18]
    push   0x10
    push   eax
    push   edi
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [edi+0xf]
    add    esp,0xc
    test   al,al
    je     Branch7
    mov    BYTE PTR [edi+0xf],0x0
  Branch7:
    mov    edx,DWORD PTR [esi]
    push   edi
    push   0x0
    push   0x26
    mov    ecx,esi
    call   DWORD PTR [edx+0x30]
    pop    edi
    pop    esi
    ret    0x24
  Branch8:
    mov    ecx,DWORD PTR [esp+0x28]
    mov    edx,DWORD PTR [esi]
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   ecx
    push   eax
    mov    ecx,esi
    call   DWORD PTR [edx+0x30]
    pop    esi
    ret    0x24
  }
}

// Low-byte selector26 connects using argument2 and low16 argument3; AL success submits stored18 string.
// Other selectors forward original full selector/argument4/global93bf4 via current virtual30; RET16.
// Genuine RET-only diagnostics remain; first failure and final backend/virtual raw EAX survive unchanged.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032d60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::DispatchSelector26OrVirtual(
    uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    cmp    bl,0x26
    mov    esi,ecx
    jne    Branch9
    push   R6GameServiceAddresses::TextConnectingToWaitmodule
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    eax,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esp+0x14]
    add    esp,0x4
    push   eax
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::OpenPrimaryConnectionThroughSubobject
    test   al,al
    je     Branch10
    push   R6GameServiceAddresses::TextLoginToWaitmodule
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    lea    edx,[esi+0x18]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::SendStringSelector4dViaOffset14
    pop    esi
    pop    ebx
    ret    0x10
  Branch9:
    push   R6GameServiceAddresses::TextJoinWaitModuleFailed
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   ecx
    push   ebx
    mov    ecx,esi
    call   DWORD PTR [eax+0x30]
  Branch10:
    pop    esi
    pop    ebx
    ret    0x10
  }
}

// Low-byte selector26 sends selector5d through current provider; others current virtual30(selector,arg2,93bf4).
// Full selector preserved for fallback; genuine RET-only diagnostic calls/raw EAX/RET8 retained.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::DispatchSelector26OrVirtual2(uint word1,uint word2)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    cmp    bl,0x26
    mov    esi,ecx
    jne    Branch11
    push   R6GameServiceAddresses::TextLoginRouterSucceeded
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    mov    ecx,esi
    call   R6GameServiceAddresses::SendSelector5dViaOffset14
    pop    esi
    pop    ebx
    ret    0x8
  Branch11:
    push   R6GameServiceAddresses::TextLoginRouterFailed
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esi]
    add    esp,0x4
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   ecx
    push   ebx
    mov    ecx,esi
    call   DWORD PTR [eax+0x30]
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Low-byte selector26 sends stored18 string through current provider; others virtual30(selector,arg2,93bf4).
// Full selector preserved for fallback; genuine RET-only diagnostic calls/raw EAX/RET8 retained.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032e20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::DispatchSelector26BufferOrVirtual(uint word1,uint word2)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    cmp    bl,0x26
    mov    esi,ecx
    jne    Branch12
    push   R6GameServiceAddresses::TextLoginToWaitmoduleSuccessful
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x4
    lea    eax,[esi+0x18]
    mov    ecx,esi
    push   eax
    call   R6GameServiceAddresses::SendSelector13StringViaOffset14
    pop    esi
    pop    ebx
    ret    0x8
  Branch12:
    push   R6GameServiceAddresses::TextLoginWaitModuleFailed
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    eax,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esi]
    add    esp,0x4
    mov    ecx,esi
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   eax
    push   ebx
    call   DWORD PTR [edx+0x30]
    pop    esi
    pop    ebx
    ret    0x8
  }
}

// Tail-enter current primary virtual34 with unchanged stack/receiver; no return or argument policy is added.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032e70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::TailVirtual34(void)
{
  __asm {
    mov    eax,DWORD PTR [ecx]
    jmp    DWORD PTR [eax+0x34]
  }
}

// Call current virtual48 with two words, then reset the freshly loaded provider even if callback is absent.
// Callback exceptions skip reset; final provider raw EAX/RET8 and all partial callback effects survive.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032e80 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::NotifyVirtual48ThenResetProvider(uint word1,uint word2)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0xc]
    push   ecx
    push   edx
    mov    eax,DWORD PTR [esi]
    mov    ecx,esi
    call   DWORD PTR [eax+0x48]
    mov    ecx,esi
    call   R6GameServiceAddresses::DisconnectPrimaryConnectionViaOffset14
    pop    esi
    ret    0x8
  }
}

// Copy argument1 through EDX, retain its redundant store, then tail current virtual4c with both words.
// Vtable pointer is captured before the store; actual callback slot is read at transfer, no own guard.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032ea0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::TailVirtual4c(uint word1,uint word2)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0x4c]
  }
}

// Copy argument1 through EDX, retain its redundant store, then tail current virtual58 with four words.
// Vtable pointer is captured before the store; actual callback slot is read at transfer, no own guard.
// RTTI/base table ownership supports class placement; names/formal types/uint raw result remain descriptive.
// R6GameService.dll @ 10032eb0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall clMSClientClass::TailVirtual58(uint word1,uint word2,uint word3,uint word4)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0x58]
  }
}

// Secondary clLobbyCallbacks entries: incoming ECX is the complete clMSClientClass receiver+8.
// Names/formals are descriptive raw-entry views; original member declarations remain unresolved.

// Low argument1 BYTE27 forwards(arg2,0,0) through adjusted complete-object virtual2c; otherwise RET8.
// Skipped path keeps incoming raw EAX; notified path keeps target EAX. No own guard or other argument reads.
// R6GameService.dll @ 10032f00 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall NotifySelector27(void *callbackSubobject,uint word1,uint word2)
{
  __asm {
    cmp    BYTE PTR [esp+0x4],0x27
    jne    Branch13
    mov    edx,DWORD PTR [esp+0x8]
    mov    eax,DWORD PTR [ecx-0x8]
    add    ecx,0xfffffff8
    push   0x0
    push   0x0
    push   edx
    call   DWORD PTR [eax+0x2c]
  Branch13:
    ret    0x8
  }
}

// If subobject10d flag/current fc record/key+4 match arg1, complete record using its+8 word, then virtual38.
// Record/helper/vtable reads retain native timing; failed completion result does not suppress virtual notification.
// Complete receiver is subobject-8; RET4/raw native residue, no own cleanup or rollback.
// R6GameService.dll @ 10032f20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall CompleteCurrentThenNotify(void *callbackSubobject,uint word1)
{
  __asm {
    mov    al,BYTE PTR [ecx+0x10d]
    push   esi
    test   al,al
    je     Branch14
    mov    eax,DWORD PTR [ecx+0xfc]
    test   eax,eax
    je     Branch14
    mov    edx,DWORD PTR [eax+0x4]
    mov    esi,DWORD PTR [esp+0x8]
    cmp    edx,esi
    jne    Branch14
    mov    eax,DWORD PTR [eax+0x8]
    lea    esi,[ecx-0x8]
    push   eax
    push   edx
    mov    ecx,esi
    call   R6GameServiceAddresses::CompleteStoredRequestIfMatched
    mov    edx,DWORD PTR [esi]
    mov    ecx,esi
    call   DWORD PTR [edx+0x38]
  Branch14:
    pop    esi
    ret    0x4
  }
}

// When subobject10d is nonzero, call complete-object virtual38 and reset current provider through3f0f0.
// Then always tail reset33420 on complete receiver. Callback/provider failures skip later reset; no own guard.
// R6GameService.dll @ 10032f60 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall NotifyAndReset(void *callbackSubobject)
{
  __asm {
    push   edi
    mov    edi,ecx
    mov    al,BYTE PTR [edi+0x10d]
    test   al,al
    je     Branch15
    mov    eax,DWORD PTR [edi-0x8]
    push   esi
    lea    esi,[edi-0x8]
    mov    ecx,esi
    call   DWORD PTR [eax+0x38]
    mov    ecx,esi
    call   R6GameServiceAddresses::SendSelector5cViaNestedOffsets
    pop    esi
  Branch15:
    lea    ecx,[edi-0x8]
    pop    edi
    jmp    R6GameServiceAddresses::ResetServiceClientState
  }
}

// Pass captured words4/5 to genuine RET-only diagnostic; then low kind BYTE !=27 stores word4 at current fc+c.
// Kind27 keeps arg5 upper EAX with AL kind; missing/current record paths preserve their pointer residue. RET20.
// R6GameService.dll @ 10032f90 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall StoreCurrentRecordWord(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x14]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    push   edi
    push   eax
    push   R6GameServiceAddresses::TextJoinLobbyII
    mov    esi,ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    al,BYTE PTR [esp+0x18]
    add    esp,0xc
    cmp    al,0x27
    je     Branch16
    mov    eax,DWORD PTR [esi+0xfc]
    test   eax,eax
    je     Branch16
    mov    DWORD PTR [eax+0xc],edi
  Branch16:
    pop    edi
    pop    esi
    ret    0x14
  }
}

// Capture word2 for RET-only diagnostic, then subobject10c enables optional server forwarding and deadline store.
// Word6 low BYTE mask8 forwards nineteen words:4,3,1,2,6,8..21 through complete-object virtual28.
// Word2 snapshot and later word reads/target-table lookup stay ordered; words5/7 omitted.
// Enabled path calls time(NULL), stores result+3 modulo32 at subobjectf8 and returns it; no flag recheck. RET84.
// R6GameService.dll @ 10033030 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardServerAndSetDeadline(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,
    uint word9,uint word10,uint word11,uint word12,uint word13,uint word14,uint word15,uint word16,uint word17,
    uint word18,uint word19,uint word20,uint word21)
{
  __asm {
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    esi,ecx
    push   edi
    push   R6GameServiceAddresses::TextNewRoomS
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    al,BYTE PTR [esi+0x10c]
    add    esp,0x8
    test   al,al
    je     Branch18
    mov    eax,DWORD PTR [esp+0x20]
    test   al,0x8
    je     Branch17
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    ebx,DWORD PTR [esp+0x60]
    push   ebx
    mov    edx,DWORD PTR [esi-0x8]
    push   eax
    mov    eax,DWORD PTR [esp+0x4c]
    push   edi
    push   eax
    mov    eax,DWORD PTR [esp+0x5c]
    lea    ecx,[esi-0x8]
    push   eax
    mov    eax,DWORD PTR [esp+0x64]
    push   eax
    call   DWORD PTR [edx+0x28]
    pop    ebx
  Branch17:
    push   0x0
    call   R6GameServiceAddresses::time
    add    esp,0x4
    add    eax,0x3
    mov    DWORD PTR [esi+0xf8],eax
  Branch18:
    pop    edi
    pop    esi
    ret    0x54
  }
}

// Read words10/2, push them with literal for genuine RET-only diagnostic and discard all fifteen words.
// Returns original word10 in EAX/word2 in ECX, not an empty stub; no pointee read, log or resource action.
// R6GameService.dll @ 10033320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall RetainDiagnosticArguments(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,
    uint word9,uint word10,uint word11,uint word12,uint word13,uint word14,uint word15)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [esp+0x8]
    push   eax
    push   ecx
    push   R6GameServiceAddresses::TextLobbyInfoSS
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0xc
    ret    0x3c
  }
}

// Adjust subobject-8, overwrite argument1 with full1, then tail complete-object virtual2c; three words.
// Vtable captured before argument store; pointer/slot effects and faults remain, no own guard.
// R6GameService.dll @ 10033340 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TailNotifyOne(void *callbackSubobject,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [ecx-0x8]
    add    ecx,0xfffffff8
    mov    DWORD PTR [esp+0x4],0x1
    jmp    DWORD PTR [eax+0x2c]
  }
}

// Adjust complete receiver and call virtual50 with(word2,word1,word3); RET12/raw result unchanged.
// Argument reads occur between pushes; no whole-argument snapshot, own guard or input ownership.
// R6GameService.dll @ 10033360 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSwappedPair(void *callbackSubobject,uint word1,uint word2,uint word3)
{
  __asm {
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [ecx-0x8]
    push   edx
    mov    edx,DWORD PTR [esp+0x8]
    add    ecx,0xfffffff8
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    call   DWORD PTR [eax+0x50]
    ret    0xc
  }
}

// Copy word1 through EDX back to its stack slot, adjust receiver-8 and tail complete-object virtual54.
// Three full words retained; captured vtable/live slot and redundant store fault timing remain.
// R6GameService.dll @ 10033380 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall TailSubmitWords(void *callbackSubobject,uint word1,uint word2,uint word3)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x4]
    mov    eax,DWORD PTR [ecx-0x8]
    add    ecx,0xfffffff8
    mov    DWORD PTR [esp+0x4],edx
    jmp    DWORD PTR [eax+0x54]
  }
}

// Call complete-object virtual40 with(word2,word1,word3..7), then set subobject10d BYTE to1.
// Commit follows any normal callback result, including zero; failure skips it. RET28/raw callback EAX.
// R6GameService.dll @ 100333a0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardSevenThenSetFlag(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7)
{
  __asm {
    mov    edx,DWORD PTR [esp+0x1c]
    push   esi
    push   edx
    mov    edx,DWORD PTR [esp+0x20]
    push   edx
    mov    edx,DWORD PTR [esp+0x20]
    push   edx
    mov    edx,DWORD PTR [esp+0x20]
    push   edx
    mov    edx,DWORD PTR [esp+0x20]
    mov    esi,ecx
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [esi-0x8]
    lea    ecx,[esi-0x8]
    push   edx
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    call   DWORD PTR [eax+0x40]
    mov    BYTE PTR [esi+0x10d],0x1
    pop    esi
    ret    0x1c
  }
}

// Low kind BYTE26 calls complete-object virtual44 with(word6,word5,word3,word4).
// Other kinds call virtual2c with(word2,word6,word5); RET24/raw target result, no own guard.
// R6GameService.dll @ 100333e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DispatchSelector26Words(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6)
{
  __asm {
    mov    al,BYTE PTR [esp+0x4]
    add    ecx,0xfffffff8
    cmp    al,0x26
    mov    eax,DWORD PTR [ecx]
    jne    Branch19
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    call   DWORD PTR [eax+0x44]
    ret    0x18
  Branch19:
    mov    edx,DWORD PTR [esp+0x14]
    push   edx
    mov    edx,DWORD PTR [esp+0x1c]
    push   edx
    mov    edx,DWORD PTR [esp+0x10]
    push   edx
    call   DWORD PTR [eax+0x2c]
    ret    0x18
  }
}

// Capture words4/5 before genuine RET-only diagnostics; low word1 BYTE27 notifies primary2c(word2,word5,word4).
// Then reload subobject104/100 and current complete-object provider for413a0(field100,field104).
// Word2 loads only on notify path, word3 unread; RET20/raw provider EAX, no own guard or rollback.
// R6GameService.dll @ 10032fd0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall NotifySelector27AndRunHelper(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x14]
    push   ebp
    mov    ebp,DWORD PTR [esp+0x1c]
    push   esi
    push   ebx
    push   ebp
    push   R6GameServiceAddresses::TextJoinRoomII
    mov    esi,ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    al,BYTE PTR [esp+0x1c]
    add    esp,0xc
    cmp    al,0x27
    jne    Branch20
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
    push   edi
    push   R6GameServiceAddresses::TextGSFAILI
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    eax,DWORD PTR [esi-0x8]
    add    esp,0x8
    lea    ecx,[esi-0x8]
    push   ebx
    push   ebp
    push   edi
    call   DWORD PTR [eax+0x2c]
    pop    edi
  Branch20:
    mov    ecx,DWORD PTR [esi+0x104]
    mov    edx,DWORD PTR [esi+0x100]
    push   ecx
    push   edx
    lea    ecx,[esi-0x8]
    call   R6GameServiceAddresses::ForwardSelector2aThroughOptionalChannel
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x14
  }
}

// Queue a record from captured words4/3 and bounded global strings; ECX is complete receiver+8.
// Incoming word2 becomes allocation scratch when constructing the list; word10 becomes current head output.
// Append through that late head/predecessor, then enabled provider9(late word3,saved word4,100hex) and time+3.
// Pending flag/key match sends current record fields/text, then clears flag only after normal provider return.
// RET60/raw EAX residues; parent frame for EH is entry ESP: state-4, flags-54, record-50, allocation+8.
// State4 protects partial container initialization; state0 only retains genuine empty record cleanup.
// Literal offset tables77078(-4,4)/77080(0,44hex) do not establish recovered record/list class declarations.
// R6GameService.dll @ 100330e0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall QueueProviderCallbackRecord(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,
    uint word9,uint word10,uint word11,uint word12,uint word13,uint word14,uint word15)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectMSCallbackQueueEH
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x48
    push   ebx
    xor    ebx,ebx
    push   ebp
    push   esi
    mov    DWORD PTR [esp+0xc],ebx
    mov    eax,DWORD PTR [esp+0x88]
    mov    esi,ecx
    mov    ecx,DWORD PTR [esp+0x68]
    push   eax
    push   ecx
    push   R6GameServiceAddresses::TextNewLobbySS
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    ebp,DWORD PTR [esp+0x7c]
    mov    edx,DWORD PTR [esp+0x78]
    push   0x21
    lea    eax,[esp+0x30]
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   eax
    mov    DWORD PTR [esp+0x28],0x10077080
    mov    DWORD PTR [esp+0x2c],ebp
    mov    DWORD PTR [esp+0x30],edx
    mov    DWORD PTR [esp+0x34],ebx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esp+0x58]
    add    esp,0x18
    cmp    al,bl
    je     Branch21
    mov    BYTE PTR [esp+0x40],bl
  Branch21:
    push   0x11
    lea    ecx,[esp+0x45]
    push   R6GameServiceAddresses::GRegistrationEmptyText
    push   ecx
    call   R6GameServiceAddresses::strncpy
    mov    al,BYTE PTR [esp+0x5d]
    add    esp,0xc
    cmp    al,bl
    je     Branch22
    mov    BYTE PTR [esp+0x51],bl
  Branch22:
    push   edi
    mov    eax,DWORD PTR [esi+0x108]
    mov    DWORD PTR [esp+0x60],ebx
    cmp    eax,ebx
    jne    Branch25
    push   0x8
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    edi,eax
    mov    DWORD PTR [esp+0x6c],edi
    cmp    edi,ebx
    je     Branch23
    mov    DWORD PTR [edi+0x4],0x10077078
    mov    DWORD PTR [esp+0x10],0x3
    lea    edx,[esp+0x8c]
    mov    ecx,edi
    push   edx
    mov    DWORD PTR [esp+0x64],0x4
    call   R6GameServiceAddresses::InitializeCallbackListSentinel
    mov    DWORD PTR [esp+0x60],0x1
    jmp    Branch24
  Branch23:
    xor    edi,edi
  Branch24:
    mov    BYTE PTR [esp+0x60],bl
    mov    DWORD PTR [esi+0x108],edi
  Branch25:
    mov    edi,DWORD PTR [esi+0x108]
    lea    eax,[esp+0x8c]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    ecx,[esp+0x14]
    push   ecx
    mov    ecx,edi
    call   R6GameServiceAddresses::CopyCallbackRecord
    mov    edi,DWORD PTR [esp+0x8c]
    mov    edx,DWORD PTR [edi+0x4]
    lea    ecx,[edi+0x4]
    mov    DWORD PTR [eax],edi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    al,BYTE PTR [esi+0x10c]
    pop    edi
    cmp    al,bl
    je     Branch26
    mov    edx,DWORD PTR [esp+0x6c]
    push   0x100
    push   ebp
    push   edx
    lea    ecx,[esi-0x8]
    call   R6GameServiceAddresses::ForwardSelector9ThroughOptionalChannel
    push   ebx
    call   R6GameServiceAddresses::time
    add    esp,0x4
    add    eax,0x3
    mov    DWORD PTR [esi+0xf8],eax
  Branch26:
    cmp    BYTE PTR [esi+0x10e],bl
    je     Branch27
    mov    eax,DWORD PTR [esi+0xfc]
    cmp    eax,ebx
    je     Branch27
    mov    ecx,DWORD PTR [eax+0x4]
    cmp    ecx,ebp
    jne    Branch27
    lea    edx,[eax+0x10]
    push   ebx
    push   edx
    lea    edx,[eax+0x31]
    mov    eax,DWORD PTR [eax+0x8]
    push   ebx
    push   edx
    push   ecx
    push   eax
    lea    ecx,[esi-0x8]
    call   R6GameServiceAddresses::DispatchRequest18ByKeyThroughSubobject
    mov    BYTE PTR [esi+0x10e],bl
  Branch27:
    mov    ecx,DWORD PTR [esp+0x54]
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x54
    ret    0x3c
  }
}

// Tail genuine empty cleanup with temporary record at inherited parent EBP-50; raw EAX retained.
// R6GameService.dll @ 100663c0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl QueueProviderCallbackRecordUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x50]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Free the current allocation scratch from inherited parent EBP+8 through actual allocator tail14d00.
// R6GameService.dll @ 100663c8 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl QueueProviderCallbackRecordUnwind2(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Mask parent flags at EBP-54 with2; when set, tail empty cleanup on current allocation scratch+8.
// R6GameService.dll @ 100663d2 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl QueueProviderCallbackRecordUnwind3(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x54]
    and    eax,0x2
    test   eax,eax
    je     Branch28
    mov    ecx,DWORD PTR [ebp+0x8]
    add    ecx,0x8
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch28:
    ret
  }
}

// Tail genuine empty cleanup with inherited parent argument10 slot EBP+28, without reading the slot.
// R6GameService.dll @ 100663ec : complete native control/access order and raw ABI retained.
__declspec(naked) uint __cdecl QueueProviderCallbackRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp+0x28]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Select the five-state queueing guard and tail-enter the CRT frame handler.
// R6GameService.dll @ 100663f4 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMSCallbackQueueEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::QueueProviderCallbackRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native queue unwind words; states4/3/2/1/0 chain to3/2/1/0/-1.
// R6GameService.dll data @ 10080744 : native storage identity retained.
const R6GameServiceNative::UnwindEntry QueueProviderCallbackRecordUnwindMap[5] = {
  {-1, R6GameServiceAddresses::QueueProviderCallbackRecordUnwind1},
  {0x0, R6GameServiceAddresses::QueueProviderCallbackRecordUnwind2},
  {0x1, R6GameServiceAddresses::QueueProviderCallbackRecordUnwind3},
  {0x2, 0x0},
  {0x3, R6GameServiceAddresses::QueueProviderCallbackRecordUnwind5},
};

// Native queue info words; states4/3/2/1/0 chain to3/2/1/0/-1.
// R6GameService.dll data @ 10080744 : native storage identity retained.
const R6GameServiceNative::FuncInfo QueueProviderCallbackRecordExceptionInfo = {
  0x19930520,
  0x5,
  R6GameServiceAddresses::QueueProviderCallbackRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Capture words2/10 before RET-only diagnostics, then forward19 words via adjusted primary28.
// Target order is4,3,1,2,6,8..21; words5/7 omitted. Early snapshots and interleaved late reads stay literal.
// Vtable captures before argument pushes; no enable gate/deadline, RET84/raw callback EAX, no own guard.
// R6GameService.dll @ 10033290 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ForwardEmbeddedCallback(
    void *callbackSubobject,uint word1,uint word2,uint word3,uint word4,uint word5,uint word6,uint word7,uint word8,
    uint word9,uint word10,uint word11,uint word12,uint word13,uint word14,uint word15,uint word16,uint word17,
    uint word18,uint word19,uint word20,uint word21)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x34]
    mov    esi,ecx
    push   edi
    push   ebx
    push   R6GameServiceAddresses::TextRoomInfoSS
    call   R6GameServiceAddresses::list_node_support_NoOp
    mov    edx,DWORD PTR [esp+0x6c]
    add    esp,0xc
    mov    eax,DWORD PTR [esi-0x8]
    lea    ecx,[esi-0x8]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x5c]
    push   edi
    push   edx
    mov    edx,DWORD PTR [esp+0x60]
    push   edx
    mov    edx,DWORD PTR [esp+0x5c]
    push   edx
    mov    edx,DWORD PTR [esp+0x4c]
    push   ebx
    push   edx
    mov    edx,DWORD PTR [esp+0x5c]
    push   edx
    mov    edx,DWORD PTR [esp+0x64]
    push   edx
    call   DWORD PTR [eax+0x28]
    pop    edi
    pop    esi
    pop    ebx
    ret    0x54
  }
}

// Native virtual-table prefix: clMSClientClassVTableAdjusted16
// R6GameService.dll data @ 10076d78 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientClassVTableAdjusted16Record {
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x00
};
const clMSClientClassVTableAdjusted16Record clMSClientClassVTableAdjusted16 = {
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
};

// Native virtual-table prefix: clMSClientClassVTableAdjusted12
// R6GameService.dll data @ 10076d80 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientClassVTableAdjusted12Record {
  R6GameServiceNative::Address NoOp; // +0x00
  R6GameServiceNative::Address list_node_support_NoOp; // +0x04
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x08
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x0c
};
const clMSClientClassVTableAdjusted12Record clMSClientClassVTableAdjusted12 = {
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::list_node_support_NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
};

// Native virtual-table prefix: clMSClientClassVTableAdjusted8
// R6GameService.dll data @ 10076d94 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientClassVTableAdjusted8Record {
  R6GameServiceNative::Address NotifySelector27; // +0x00
  R6GameServiceNative::Address CompleteCurrentThenNotify; // +0x04
  R6GameServiceNative::Address NotifyAndReset; // +0x08
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x0c
  R6GameServiceNative::Address StoreCurrentRecordWord; // +0x10
  R6GameServiceNative::Address NotifySelector27AndRunHelper; // +0x14
  R6GameServiceNative::Address ForwardServerAndSetDeadline; // +0x18
  R6GameServiceNative::Address QueueProviderCallbackRecord; // +0x1c
  R6GameServiceNative::Address ForwardEmbeddedCallback; // +0x20
  R6GameServiceNative::Address RetainDiagnosticArguments; // +0x24
  R6GameServiceNative::Address TailNotifyOne; // +0x28
  R6GameServiceNative::Address NoOp; // +0x2c
  R6GameServiceNative::Address NoOpServiceCallbackRet30; // +0x30
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x34
  R6GameServiceNative::Address NoOpServiceCallbackRet10; // +0x38
  R6GameServiceNative::Address NoOpServiceCallbackRet142; // +0x3c
  R6GameServiceNative::Address NoOpServiceCallbackRet143; // +0x40
  R6GameServiceNative::Address NoOpServiceCallbackRet102; // +0x44
  R6GameServiceNative::Address NoOpServiceCallbackRet0C2; // +0x48
  R6GameServiceNative::Address NoOpServiceCallbackRet144; // +0x4c
  R6GameServiceNative::Address NoOpServiceCallbackRet145; // +0x50
  R6GameServiceNative::Address DispatchSelector26Words; // +0x54
  R6GameServiceNative::Address NoOpServiceCallbackRet103; // +0x58
  R6GameServiceNative::Address NoOpServiceCallbackRet0C3; // +0x5c
  R6GameServiceNative::Address ForwardSwappedPair; // +0x60
  R6GameServiceNative::Address NoOpServiceCallbackRet104; // +0x64
  R6GameServiceNative::Address TailSubmitWords; // +0x68
  R6GameServiceNative::Address NoOpServiceCallbackRet105; // +0x6c
  R6GameServiceNative::Address NoOpServiceCallbackRet106; // +0x70
  R6GameServiceNative::Address NoOpServiceCallbackRet107; // +0x74
  R6GameServiceNative::Address ForwardSevenThenSetFlag; // +0x78
  R6GameServiceNative::Address NoOpServiceCallbackRet108; // +0x7c
  R6GameServiceNative::Address NoOpServiceCallbackRet109; // +0x80
  R6GameServiceNative::Address NoOpServiceCallbackRet146; // +0x84
  R6GameServiceNative::Address NoOpServiceCallbackRet147; // +0x88
  R6GameServiceNative::Address NoOpServiceCallbackRet0C4; // +0x8c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C5; // +0x90
  R6GameServiceNative::Address NoOp2; // +0x94
  R6GameServiceNative::Address shared_native_NoOp; // +0x98
  R6GameServiceNative::Address NoOp3; // +0x9c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C6; // +0xa0
  R6GameServiceNative::Address NoOpServiceCallbackRet0C7; // +0xa4
  R6GameServiceNative::Address NoOp4; // +0xa8
  R6GameServiceNative::Address NoOpServiceCallbackRet148; // +0xac
};
const clMSClientClassVTableAdjusted8Record clMSClientClassVTableAdjusted8 = {
  R6GameServiceAddresses::NotifySelector27,
  R6GameServiceAddresses::CompleteCurrentThenNotify,
  R6GameServiceAddresses::NotifyAndReset,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::StoreCurrentRecordWord,
  R6GameServiceAddresses::NotifySelector27AndRunHelper,
  R6GameServiceAddresses::ForwardServerAndSetDeadline,
  R6GameServiceAddresses::QueueProviderCallbackRecord,
  R6GameServiceAddresses::ForwardEmbeddedCallback,
  R6GameServiceAddresses::RetainDiagnosticArguments,
  R6GameServiceAddresses::TailNotifyOne,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet30,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::DispatchSelector26Words,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::ForwardSwappedPair,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::TailSubmitWords,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::ForwardSevenThenSetFlag,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet10,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
};

// Native virtual-table prefix: clMSClientClassVTableAdjusted4
// R6GameService.dll data @ 10076e4c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientClassVTableAdjusted4Record {
  R6GameServiceNative::Address NoOp; // +0x00
  R6GameServiceNative::Address NoOpServiceCallbackRet0C; // +0x04
  R6GameServiceNative::Address NoOpServiceCallbackRet0C2; // +0x08
  R6GameServiceNative::Address NoOp2; // +0x0c
  R6GameServiceNative::Address NoOp3; // +0x10
  R6GameServiceNative::Address shared_native_NoOp; // +0x14
  R6GameServiceNative::Address shared_native_NoOp2; // +0x18
  R6GameServiceNative::Address NoOpServiceCallbackRet0C3; // +0x1c
  R6GameServiceNative::Address NoOpServiceCallbackRet0C4; // +0x20
  R6GameServiceNative::Address NoOpServiceCallbackRet0C5; // +0x24
  R6GameServiceNative::Address NoOpServiceCallbackRet0C6; // +0x28
  R6GameServiceNative::Address NoOp4; // +0x2c
  R6GameServiceNative::Address NoOp5; // +0x30
  R6GameServiceNative::Address NoOpServiceCallbackRet18; // +0x34
  R6GameServiceNative::Address NoOpServiceCallbackRet14; // +0x38
  R6GameServiceNative::Address NoOpServiceCallbackRet142; // +0x3c
};
const clMSClientClassVTableAdjusted4Record clMSClientClassVTableAdjusted4 = {
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::shared_native_NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOpServiceCallbackRet0C,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::NoOpServiceCallbackRet18,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
  R6GameServiceAddresses::NoOpServiceCallbackRet14,
};

// Native virtual-table prefix: clMSClientClassVTable
// R6GameService.dll data @ 10076e94 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clMSClientClassVTableRecord {
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26StringOrVirtual; // +0x00
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26OrVirtual; // +0x04
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26OrVirtual2; // +0x08
  R6GameServiceNative::Address clMSClientClass_DispatchSelector26BufferOrVirtual; // +0x0c
  R6GameServiceNative::Address NoOp; // +0x10
  R6GameServiceNative::Address clMSClientClass_TailVirtual34; // +0x14
  R6GameServiceNative::Address clMSClientClass_NotifyVirtual48ThenResetProvider; // +0x18
  R6GameServiceNative::Address clMSClientClass_TailVirtual4c; // +0x1c
  R6GameServiceNative::Address clMSClientClass_TailVirtual58; // +0x20
  R6GameServiceNative::Address DeleteServiceClient; // +0x24
  R6GameServiceNative::Address _purecall; // +0x28
  R6GameServiceNative::Address _purecall2; // +0x2c
  R6GameServiceNative::Address _purecall3; // +0x30
  R6GameServiceNative::Address _purecall4; // +0x34
  R6GameServiceNative::Address _purecall5; // +0x38
  R6GameServiceNative::Address _purecall6; // +0x3c
  R6GameServiceNative::Address _purecall7; // +0x40
  R6GameServiceNative::Address _purecall8; // +0x44
  R6GameServiceNative::Address _purecall9; // +0x48
  R6GameServiceNative::Address _purecall10; // +0x4c
  R6GameServiceNative::Address _purecall11; // +0x50
  R6GameServiceNative::Address _purecall12; // +0x54
  R6GameServiceNative::Address _purecall13; // +0x58
};
const clMSClientClassVTableRecord clMSClientClassVTable = {
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26StringOrVirtual,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26OrVirtual,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26OrVirtual2,
  R6GameServiceAddresses::clMSClientClass_DispatchSelector26BufferOrVirtual,
  R6GameServiceAddresses::NoOp,
  R6GameServiceAddresses::clMSClientClass_TailVirtual34,
  R6GameServiceAddresses::clMSClientClass_NotifyVirtual48ThenResetProvider,
  R6GameServiceAddresses::clMSClientClass_TailVirtual4c,
  R6GameServiceAddresses::clMSClientClass_TailVirtual58,
  R6GameServiceAddresses::DeleteServiceClient,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
  R6GameServiceAddresses::_purecall,
};
