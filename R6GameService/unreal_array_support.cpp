#include "native_addresses.h"
#include "native_records.h"

// Native Unreal array helpers; original specialization/template spellings remain unresolved.
// Raw uint return views preserve EAX residue without recovering an original return declaration.
// Checks three signed range conditions and forwards current cached index/count to FArray::Remove with stride4.
// R6GameService.dll @ 10001b30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall RemoveFourByteArrayElements(FArray *array,int index,int count)
{
  __asm {
    // Assertion target/index cached early; count loaded after second check; index+count wraps32 bits; negative count untested.
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x14]
    test   edi,edi
    mov    esi,ecx
    jge    Branch1
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   ebp
    add    esp,0xc
  Branch1:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch2
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebp
    add    esp,0xc
  Branch2:
    mov    ebx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [esi+0x4]
    lea    eax,[edi+ebx*1]
    cmp    eax,ecx
    jle    Branch3
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebp
    add    esp,0xc
  Branch3:
    push   0x4
    push   ebx
    push   edi
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Shared compiler-generated storage cleanup; containing TArray specializations retain descriptive names.
// R6GameService.dll data @ 1007b0bc : only state0 forwards saved FArray storage destruction.
const R6GameServiceNative::UnwindEntry unreal_array_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::DestroySavedArrayStorage},
};
// R6GameService.dll data @ 1007b0c4 : shared by twelve constructor/destructor entries, including one unarmed constructor.
const R6GameServiceNative::FuncInfo unreal_array_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  1,
  R6GameServiceAddresses::unreal_array_supportSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Initializes a 12-byte-stride array, then adds and copy-constructs strings under backing-storage cleanup.
// R6GameService.dll @ 100020a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructFStringArray(void *destination,const void *source)
{
  __asm {
    // Reallocation runs in state-1; count resets before state0; current source count/data and destination data reload.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,ecx
    xor    ebx,ebx
    push   0xc
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    DWORD PTR [esi+0x4],ebx
    cmp    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [esp+0x18],ebx
    jle    Branch6
    push   ebp
    xor    ebp,ebp
  Branch4:
    push   0xc
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    ecx,DWORD PTR [esi]
    lea    eax,[eax+eax*2]
    lea    ecx,[ecx+eax*4]
    test   ecx,ecx
    je    Branch5
    mov    edx,DWORD PTR [edi]
    add    edx,ebp
    push   edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
  Branch5:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0xc
    cmp    ebx,eax
    jl    Branch4
    pop    ebp
  Branch6:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Initializes a four-byte array and copies live destination-count words without arming its storage cleanup.
// R6GameService.dll @ 10002130 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructDwordArray(void *destination,const void *source)
{
  __asm {
    // State stays-1 throughout; destination count and both data pointers reload per word; no Add or null-target gate.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,ecx
    push   0x4
    mov    DWORD PTR [esi],0x0
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    ecx,DWORD PTR [esi+0x4]
    xor    eax,eax
    test   ecx,ecx
    jle    Branch8
    mov    edi,edi
  Branch7:
    mov    ecx,DWORD PTR [edi]
    mov    ecx,DWORD PTR [ecx+eax*4]
    mov    edx,DWORD PTR [esi]
    mov    DWORD PTR [edx+eax*4],ecx
    mov    ecx,DWORD PTR [esi+0x4]
    inc    eax
    cmp    eax,ecx
    jl    Branch7
  Branch8:
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Removes the cached count of four-byte elements under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 100021a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyArrayStorage(FArray *array)
{
  __asm {
    // Count read precedes state0; assertion target cached; the second range check reloads current count.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch9
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch9:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch10
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch10:
    push   0x4
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Initializes a 0x18-byte-stride array, then adds and copy-constructs string-pair records under backing-storage cleanup.
// R6GameService.dll @ 100022a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructStringPairArray18(void *destination,const void *source)
{
  __asm {
    // Record construction has its own first-string cleanup; the outer action only forwards to the FArray destructor.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,ecx
    xor    ebx,ebx
    push   0x18
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    DWORD PTR [esi+0x4],ebx
    cmp    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [esp+0x18],ebx
    jle    Branch13
    push   ebp
    xor    ebp,ebp
  Branch11:
    push   0x18
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    ecx,DWORD PTR [esi]
    lea    eax,[eax+eax*2]
    lea    ecx,[ecx+eax*8]
    test   ecx,ecx
    je    Branch12
    mov    edx,DWORD PTR [edi]
    add    edx,ebp
    push   edx
    call   R6GameServiceAddresses::CopyStringPairRecord18
  Branch12:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0x18
    cmp    ebx,eax
    jl    Branch11
    pop    ebp
  Branch13:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Initializes a 0x2c-byte-stride array, then adds and copy-constructs records under backing-storage cleanup.
// R6GameService.dll @ 10002330 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructStringRecordArray2C(void *destination,const void *source)
{
  __asm {
    // Cached source object, live source count/data, null computed-target gate and raw receiver return retained.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,ecx
    xor    ebx,ebx
    push   0x2c
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    DWORD PTR [esi+0x4],ebx
    cmp    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [esp+0x18],ebx
    jle    Branch16
    push   ebp
    xor    ebp,ebp
  Branch14:
    push   0x2c
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x2c
    add    eax,DWORD PTR [esi]
    je    Branch15
    mov    ecx,DWORD PTR [edi]
    add    ecx,ebp
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyStringRecord2C
  Branch15:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0x2c
    cmp    ebx,eax
    jl    Branch14
    pop    ebp
  Branch16:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Initializes a 0x1c-byte-stride array and adds records using seven direction-sensitive word transfers under storage cleanup.
// R6GameService.dll @ 100023c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall ConstructSevenWordRecordArray(void *destination,const void *source)
{
  __asm {
    // REP MOVSD retains incoming direction-flag behavior; original source-argument slot becomes the byte-offset scratch.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [ebp+0x4]
    mov    ebx,ecx
    push   esi
    xor    esi,esi
    push   0x1c
    mov    DWORD PTR [esp+0x14],ebx
    mov    DWORD PTR [ebx],esi
    mov    DWORD PTR [ebx+0x4],eax
    mov    DWORD PTR [ebx+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    DWORD PTR [ebx+0x4],esi
    cmp    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [esp+0x1c],esi
    mov    DWORD PTR [esp+0xc],esi
    jle    Branch19
    mov    DWORD PTR [esp+0x24],esi
    push   edi
    nop
  Branch17:
    push   0x1c
    push   0x1
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x1c
    add    eax,DWORD PTR [ebx]
    je    Branch18
    mov    esi,DWORD PTR [ebp+0x0]
    add    esi,DWORD PTR [esp+0x28]
    mov    ecx,0x7
    mov    edi,eax
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  Branch18:
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x28]
    mov    ecx,DWORD PTR [ebp+0x4]
    inc    eax
    add    edx,0x1c
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x28],edx
    jl    Branch17
    pop    edi
  Branch19:
    mov    ecx,DWORD PTR [esp+0x14]
    pop    esi
    pop    ebp
    mov    eax,ebx
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x4
  }
}

// Removes all cached-count string elements under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 10002a10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyFStringArray(FArray *array)
{
  __asm {
    // Child range removal and final FArray destruction have distinct active states; final imported EAX survives.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemoveFStringRange12
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Removes the cached count of 0x1c-byte records under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 10002a60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall unreal_array_support_DestroyArrayStorage(FArray *array)
{
  __asm {
    // Assertions may return; cached count is forwarded even when their callbacks change the current array count.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch20
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch20:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch21
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch21:
    push   0x1c
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys/removes 0x18-byte records under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 10002d30 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyArray18ByteElements(FArray *array)
{
  __asm {
    // Record/range failures retain the independent outer storage action; a final storage failure does not repeat it.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemoveStringPairRange18
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys/removes 0x2c-byte records under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 10002d80 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyArray2CByteElements(FArray *array)
{
  __asm {
    // Record/range failures retain the independent outer storage action; a final storage failure does not repeat it.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemoveStringRecordRange2C
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Initializes a 0xdc-byte-stride server array and adds/copy-constructs records under backing-storage cleanup.
// R6GameService.dll @ 10003530 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyConstructSTGameServerArray(void *destination,const void *source)
{
  __asm {
    // Server record construction remains a separately reconstructed boundary; no element cleanup loop is added here.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x20]
    mov    eax,DWORD PTR [edi+0x4]
    mov    esi,ecx
    xor    ebx,ebx
    push   0xdc
    mov    DWORD PTR [esp+0x10],esi
    mov    DWORD PTR [esi],ebx
    mov    DWORD PTR [esi+0x4],eax
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    DWORD PTR [esi+0x4],ebx
    cmp    DWORD PTR [edi+0x4],ebx
    mov    DWORD PTR [esp+0x18],ebx
    jle    Branch24
    push   ebp
    xor    ebp,ebp
    lea    ebx,[ebx+0x0]
  Branch22:
    push   0xdc
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0xdc
    add    eax,DWORD PTR [esi]
    je    Branch23
    mov    ecx,DWORD PTR [edi]
    add    ecx,ebp
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructSTGameServer
  Branch23:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0xdc
    cmp    ebx,eax
    jl    Branch22
    pop    ebp
  Branch24:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Destroys/removes server records under storage cleanup, then disarms and destroys backing storage.
// R6GameService.dll @ 10003730 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall DestroyArrayDCByteElements(FArray *array)
{
  __asm {
    // The cached count reaches range removal while outer state0 is active; final FArray destructor runs in state-1.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArrayStorageExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemoveSTGameServerRange
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-forwards the incoming array and unchanged frame to the four-byte storage destructor.
// R6GameService.dll @ 10002a00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ForwardToArrayDestructor(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyArrayStorage
  }
}

// Tail-forwards the incoming array and unchanged frame to the FString-array destructor.
// R6GameService.dll @ 10002d10 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ForwardArrayDestroy(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyFStringArray
  }
}

// Tail-forwards the incoming array and unchanged frame to the 0x1c-byte storage destructor.
// R6GameService.dll @ 10002d20 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall unreal_array_support_ForwardToArrayDestructor(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage
  }
}

// Tail-forwards the incoming array and unchanged frame to the 0x18-byte storage destructor.
// R6GameService.dll @ 10002f60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall unreal_array_support_ForwardArrayDestroy(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyArray18ByteElements
  }
}

// Tail-forwards the incoming array and unchanged frame to the 0x2c-byte storage destructor.
// R6GameService.dll @ 10002f70 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall unreal_array_support_ForwardArrayDestroy2(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyArray2CByteElements
  }
}

// Tail-forwards the incoming array and unchanged frame to the server-array storage destructor.
// R6GameService.dll @ 10003860 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall unreal_array_support_ForwardArrayDestroy3(FArray *array)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyArrayDCByteElements
  }
}

// Loads the current saved array pointer from inherited parent EBP-10 and tail-forwards its storage destructor.
// R6GameService.dll @ 10063320 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroySavedArrayStorage(void)
{
  __asm {
    // Shared by the twelve FuncInfo callers; pointer ownership/type is not inferred from neighboring entries.
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
  }
}

// Loads the shared one-state array-storage FuncInfo and tail-forwards the unchanged C++ exception frame.
// R6GameService.dll @ 10063329 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectArrayStorageExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::unreal_array_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Returns on self-assignment; otherwise resets count/capacity, reallocates and adds/copies live source words.
// R6GameService.dll @ 10002230 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyDwordArray(FArray *destination,const FArray *source)
{
  __asm {
    // Existing Data survives the pre-Realloc stores; null computed targets skip stores after Add; no local EH/rollback.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    esi,edi
    je    Branch28
    mov    eax,DWORD PTR [edi+0x4]
    push   ebx
    push   0x4
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebx,ebx
    test   eax,eax
    jle    Branch27
    jmp    Branch25
    lea    ecx,[ecx+0x0]
  Branch25:
    push   0x4
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    ecx,DWORD PTR [esi]
    lea    eax,[ecx+eax*4]
    test   eax,eax
    je    Branch26
    mov    edx,DWORD PTR [edi]
    mov    ecx,DWORD PTR [edx+ebx*4]
    mov    DWORD PTR [eax],ecx
  Branch26:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    cmp    ebx,eax
    jl    Branch25
  Branch27:
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch28:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Checks a signed wrapped range, destroys its cached FString extent with live data reloads and forwards late count.
// R6GameService.dll @ 10002570 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall RemoveFStringRange12(void *array,int firstIndex,int count)
{
  __asm {
    // Assertion target/index cached; count read after second check and again after element destruction; no local EH frame.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   edi
    mov    ebp,ecx
    jge    Branch29
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   esi
    add    esp,0xc
  Branch29:
    cmp    ebx,DWORD PTR [ebp+0x4]
    jle    Branch30
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   esi
    add    esp,0xc
  Branch30:
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[ebx+eax*1]
    cmp    edi,DWORD PTR [ebp+0x4]
    jle    Branch31
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   esi
    add    esp,0xc
  Branch31:
    cmp    ebx,edi
    jge    Branch33
    lea    esi,[ebx+ebx*2]
    shl    esi,0x2
    sub    edi,ebx
    lea    ecx,[ecx+0x0]
  Branch32:
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    add    esi,0xc
    dec    edi
    jne    Branch32
  Branch33:
    mov    ecx,DWORD PTR [esp+0x18]
    push   0xc
    push   ecx
    push   ebx
    mov    ecx,ebp
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Destroys forward through live string-array data/count, then clears count and reallocates using the late hint.
// R6GameService.dll @ 10002610 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall ResetFStringArray(void *array,uint capacityHint)
{
  __asm {
    // Element failures precede header resets; final Realloc raw EAX survives; no local EH/rollback.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    xor    edi,edi
    test   eax,eax
    jle    Branch35
    push   ebx
    xor    ebx,ebx
  Branch34:
    mov    ecx,DWORD PTR [esi]
    add    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
    mov    eax,DWORD PTR [esi+0x4]
    inc    edi
    add    ebx,0xc
    cmp    edi,eax
    jl    Branch34
    pop    ebx
  Branch35:
    mov    eax,DWORD PTR [esp+0xc]
    push   0xc
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Returns on self-assignment; otherwise resets strings and copies live source elements through Add and FString construction.
// R6GameService.dll @ 10002660 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyFStringArray(void *destination,const void *source)
{
  __asm {
    // Source object/owner cached; counts and data pointers reload around callbacks; no outer rollback on partial copy.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    esi,edi
    je    Branch39
    mov    eax,DWORD PTR [edi+0x4]
    push   ebx
    push   eax
    call   R6GameServiceAddresses::ResetFStringArray
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebx,ebx
    test   eax,eax
    jle    Branch38
    push   ebp
    xor    ebp,ebp
  Branch36:
    push   0xc
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    mov    edx,DWORD PTR [esi]
    lea    ecx,[eax+eax*2]
    lea    ecx,[edx+ecx*4]
    test   ecx,ecx
    je    Branch37
    mov    eax,DWORD PTR [edi]
    add    eax,ebp
    push   eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
  Branch37:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0xc
    cmp    ebx,eax
    jl    Branch36
    pop    ebp
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch38:
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch39:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Returns on self-assignment; otherwise resets/reallocates and adds records with seven direction-sensitive word transfers.
// R6GameService.dll @ 100026d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopySevenWordRecordArray(void *destination,const void *source)
{
  __asm {
    // REP MOVSD and original argument-slot byte-offset scratch retained; final POP ECX returns the reused iteration-count word.
    push   ecx
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    cmp    ebx,ebp
    je    Branch43
    mov    eax,DWORD PTR [ebp+0x4]
    push   esi
    xor    esi,esi
    push   0x1c
    mov    DWORD PTR [ebx+0x4],esi
    mov    DWORD PTR [ebx+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    cmp    DWORD PTR [ebp+0x4],esi
    mov    DWORD PTR [esp+0xc],esi
    jle    Branch42
    mov    DWORD PTR [esp+0x14],esi
    push   edi
    nop
  Branch40:
    push   0x1c
    push   0x1
    mov    ecx,ebx
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0x1c
    add    eax,DWORD PTR [ebx]
    je    Branch41
    mov    esi,DWORD PTR [ebp+0x0]
    add    esi,DWORD PTR [esp+0x18]
    mov    ecx,0x7
    mov    edi,eax
    rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  Branch41:
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0x18]
    mov    ecx,DWORD PTR [ebp+0x4]
    inc    eax
    add    edx,0x1c
    cmp    eax,ecx
    mov    DWORD PTR [esp+0x10],eax
    mov    DWORD PTR [esp+0x18],edx
    jl    Branch40
    pop    edi
    pop    esi
    pop    ebp
    mov    eax,ebx
    pop    ebx
    pop    ecx
    ret    0x4
  Branch42:
    pop    esi
    pop    ebp
    mov    eax,ebx
    pop    ebx
    pop    ecx
    ret    0x4
  Branch43:
    pop    ebp
    mov    eax,ebx
    pop    ebx
    pop    ecx
    ret    0x4
  }
}

// Destroys server records with live data/count reloads, then clears count and reallocates to the late capacity hint.
// R6GameService.dll @ 100035d0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall EmptySTGameServerArray(void *array,int capacityHint)
{
  __asm {
    // Each record has its own cleanup; no outer array rollback is added if a record destructor fails.
    push   esi
    mov    esi,ecx
    mov    eax,DWORD PTR [esi+0x4]
    push   edi
    xor    edi,edi
    test   eax,eax
    jle    Branch45
    push   ebx
    xor    ebx,ebx
  Branch44:
    mov    ecx,DWORD PTR [esi]
    add    ecx,ebx
    call   R6GameServiceAddresses::DestroySTGameServer
    mov    eax,DWORD PTR [esi+0x4]
    inc    edi
    add    ebx,0xdc
    cmp    edi,eax
    jl    Branch44
    pop    ebx
  Branch45:
    mov    eax,DWORD PTR [esp+0xc]
    push   0xdc
    mov    ecx,esi
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi+0x8],eax
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_ReallocSlot
    pop    edi
    pop    esi
    ret    0x4
  }
}

// Checks a signed wrapped range, destroys its cached server-record extent and forwards the late original count.
// R6GameService.dll @ 10003620 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall RemoveSTGameServerRange(void *array,int firstIndex,int count)
{
  __asm {
    // Cached assertion target/index and loop extent coexist with live data reloads; no local EH frame.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   edi
    mov    ebp,ecx
    jge    Branch46
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   esi
    add    esp,0xc
  Branch46:
    cmp    ebx,DWORD PTR [ebp+0x4]
    jle    Branch47
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   esi
    add    esp,0xc
  Branch47:
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[ebx+eax*1]
    cmp    edi,DWORD PTR [ebp+0x4]
    jle    Branch48
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   esi
    add    esp,0xc
  Branch48:
    cmp    ebx,edi
    jge    Branch50
    mov    esi,ebx
    imul   esi,esi,0xdc
    sub    edi,ebx
    nop
  Branch49:
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,esi
    call   R6GameServiceAddresses::DestroySTGameServer
    add    esi,0xdc
    dec    edi
    jne    Branch49
  Branch50:
    mov    ecx,DWORD PTR [esp+0x18]
    push   0xdc
    push   ecx
    push   ebx
    mov    ecx,ebp
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Guards self-assignment, destroys existing servers, then adds and copy-constructs live source records.
// R6GameService.dll @ 100036c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall AssignSTGameServerArray(void *destination,const void *source)
{
  __asm {
    // Receiver/source object cached; current data/count reloads, null computed-target skips and no outer rollback retained.
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    esi,ecx
    cmp    esi,edi
    je    Branch54
    mov    eax,DWORD PTR [edi+0x4]
    push   ebx
    push   eax
    call   R6GameServiceAddresses::EmptySTGameServerArray
    mov    eax,DWORD PTR [edi+0x4]
    xor    ebx,ebx
    test   eax,eax
    jle    Branch53
    push   ebp
    xor    ebp,ebp
  Branch51:
    push   0xdc
    push   0x1
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_AddSlot
    imul   eax,eax,0xdc
    add    eax,DWORD PTR [esi]
    je    Branch52
    mov    ecx,DWORD PTR [edi]
    add    ecx,ebp
    push   ecx
    mov    ecx,eax
    call   R6GameServiceAddresses::CopyConstructSTGameServer
  Branch52:
    mov    eax,DWORD PTR [edi+0x4]
    inc    ebx
    add    ebp,0xdc
    cmp    ebx,eax
    jl    Branch51
    pop    ebp
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch53:
    pop    ebx
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  Branch54:
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Destroys four strings at24/18/c/0 in reverse order with three-state remaining-member unwind; returns raw destructor EAX.
// R6GameService.dll @ 10007d90 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall DestroyFourStrings(void *record)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectFourStringDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    lea    ecx,[esi+0x24]
    mov    DWORD PTR [esp+0x10],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0x18]
    mov    BYTE PTR [esp+0x10],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    lea    ecx,[esi+0xc]
    mov    BYTE PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Removes the cached element count with stride838, then disarms storage unwind before array destruction.
// R6GameService.dll @ 1000b3d0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall unreal_array_support_DestroyArrayStorage2(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSharedArrayDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch55
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch55:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch56
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch56:
    push   0x838
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Removes the cached element count with stride108, then disarms storage unwind before array destruction.
// R6GameService.dll @ 1000b470 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall unreal_array_support_DestroyArrayStorage3(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSharedArrayDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch57
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch57:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch58
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch58:
    push   0x108
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Removes the cached element count with stride10, then disarms storage unwind before array destruction.
// R6GameService.dll @ 1000b510 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall unreal_array_support_DestroyArrayStorage4(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSharedArrayDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch59
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch59:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch60
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch60:
    push   0x10
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Checks signed wrapped bounds, destroys records using each current data pointer, then removes with the late count argument.
// R6GameService.dll @ 1000b5a0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall RemoveStringRecordRange30(FArray *array,int firstIndex,int count)
{
  __asm {
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    test   ebx,ebx
    push   ebp
    push   esi
    mov    esi,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    push   edi
    mov    ebp,ecx
    jge    Branch61
    push   0x201
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndex0
    call   esi
    add    esp,0xc
  Branch61:
    cmp    ebx,DWORD PTR [ebp+0x4]
    jle    Branch62
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   esi
    add    esp,0xc
  Branch62:
    mov    eax,DWORD PTR [esp+0x18]
    lea    edi,[ebx+eax*1]
    cmp    edi,DWORD PTR [ebp+0x4]
    jle    Branch63
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   esi
    add    esp,0xc
  Branch63:
    cmp    ebx,edi
    jge    Branch65
    lea    esi,[ebx+ebx*2]
    shl    esi,0x4
    sub    edi,ebx
    lea    ecx,[ecx+0x0]
  Branch64:
    mov    ecx,DWORD PTR [ebp+0x0]
    add    ecx,esi
    call   R6GameServiceAddresses::DestroyFourStrings
    add    esi,0x30
    dec    edi
    jne    Branch64
  Branch65:
    mov    ecx,DWORD PTR [esp+0x18]
    push   0x30
    push   ecx
    push   ebx
    mov    ecx,ebp
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    ret    0x8
  }
}

// Reads count at receiver byte offset4, destroys/removes records, then disarms unwind before array storage destruction.
// R6GameService.dll @ 1000c080 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __fastcall DestroyStringRecordArray30(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectSharedArrayDestruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    push   0x0
    mov    DWORD PTR [esp+0x18],0x0
    call   R6GameServiceAddresses::RemoveStringRecordRange30
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-destroys first remaining string through inherited saved receiver at EBP-10.
// R6GameService.dll @ 10063a30 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl DestroyFourStringsUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Tail-destroys remaining string at inherited saved receiver+c through current import.
// R6GameService.dll @ 10063a39 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl DestroyFourStringsUnwind2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0xc
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Tail-destroys remaining string at inherited saved receiver+18 through current import.
// R6GameService.dll @ 10063a45 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl DestroyFourStringsUnwind3(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x18
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Tail-destroys saved array storage at inherited EBP-10 through current import.
// R6GameService.dll @ 10063d10 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl unreal_array_supportSharedLifetimeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
  }
}

// Selects the three-state remaining-string map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10063a51 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectFourStringDestruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyFourStringsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects the shared one-state array-storage map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10063d19 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectSharedArrayDestruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::unreal_array_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007c448 : native array/string unwind record.
const R6GameServiceNative::UnwindEntry DestroyFourStringsUnwindMap[3] = {
  {-1, R6GameServiceAddresses::DestroyFourStringsUnwind1},
  {0x0, R6GameServiceAddresses::DestroyFourStringsUnwind2},
  {0x1, R6GameServiceAddresses::DestroyFourStringsUnwind3},
};

// R6GameService.dll data @ 1007c460 : native array/string unwind record.
// R6GameService.dll data @ 1007c448 : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyFourStringsExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::DestroyFourStringsUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007cecc : native array/string unwind record.
const R6GameServiceNative::UnwindEntry unreal_array_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::unreal_array_supportSharedLifetimeUnwind1},
};

// R6GameService.dll data @ 1007ced4 : native array/string unwind record.
// R6GameService.dll data @ 1007cecc : native storage identity retained.
const R6GameServiceNative::FuncInfo unreal_array_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::unreal_array_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Removes cached count with stride0x20, disarms its one-state unwind, then destroys array storage.
// R6GameService.dll @ 1000f150 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall unreal_array_support_DestroyArrayStorage5(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArray20Destruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch66
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch66:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch67
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch67:
    push   0x20
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Removes cached count with stride8, disarms its one-state unwind, then destroys array storage.
// R6GameService.dll @ 10013740 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __thiscall unreal_array_support_DestroyArrayStorage6(FArray *array)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::SelectArray8Destruction
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   ebx
    push   esi
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    mov    edi,DWORD PTR [esi+0x4]
    test   edi,edi
    mov    ebx,DWORD PTR ds:R6GameServiceAddresses::Core__appFailAssertSlot
    mov    DWORD PTR [esp+0x18],0x0
    jge    Branch68
    push   0x202
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexArrayNum
    call   ebx
    add    esp,0xc
  Branch68:
    cmp    edi,DWORD PTR [esi+0x4]
    jle    Branch69
    push   0x203
    push   R6GameServiceAddresses::TextDRavenshield412CoreIncUnTemplateH
    push   R6GameServiceAddresses::TextIndexCountArrayNum
    call   ebx
    add    esp,0xc
  Branch69:
    push   0x8
    push   edi
    push   0x0
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core_FArray_RemoveSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x18],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Tail-destroys saved array through inherited receiver at EBP-10 and current storage destructor import.
// R6GameService.dll @ 100640f0 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl unreal_array_support_DestroyArrayStorage5Unwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
  }
}

// Tail-destroys saved array through inherited receiver at EBP-10 and current storage destructor import.
// R6GameService.dll @ 10064470 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl unreal_array_support_DestroyArrayStorage6Unwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFArraySlot
  }
}

// Selects one-state stride0x20 array destruction map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 100640f9 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectArray20Destruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage5ExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Selects one-state stride8 array destruction map and tail-transfers to external exception dispatch.
// R6GameService.dll @ 10064479 : complete native operations and raw ABI; descriptive helper name.
__declspec(naked) uint __cdecl SelectArray8Destruction(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage6ExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// R6GameService.dll data @ 1007d808 : native array storage unwind record.
const R6GameServiceNative::UnwindEntry unreal_array_support_DestroyArrayStorage5UnwindMap[1] = {
  {-1, R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage5Unwind1},
};

// R6GameService.dll data @ 1007d810 : native array storage unwind record.
// R6GameService.dll data @ 1007d808 : native storage identity retained.
const R6GameServiceNative::FuncInfo unreal_array_support_DestroyArrayStorage5ExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage5UnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// R6GameService.dll data @ 1007e504 : native array storage unwind record.
const R6GameServiceNative::UnwindEntry unreal_array_support_DestroyArrayStorage6UnwindMap[1] = {
  {-1, R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage6Unwind1},
};

// R6GameService.dll data @ 1007e50c : native array storage unwind record.
// R6GameService.dll data @ 1007e504 : native storage identity retained.
const R6GameServiceNative::FuncInfo unreal_array_support_DestroyArrayStorage6ExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::unreal_array_support_DestroyArrayStorage6UnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
