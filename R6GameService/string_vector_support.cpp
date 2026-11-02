#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080b4c : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo StringRangeConstructionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080ba4 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo RepeatedStringConstructionExceptionHandlerFunctionInfo;
// R6GameService.dll data @ 10080c30 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo StringVectorInsertionExceptionHandlerFunctionInfo;

// Shared narrow-string vector lifetime helpers; original template declarations and prefix+0 remain opaque.

// Destroys a cached half-open range of 28-byte CRT narrow strings without changing vector storage.
// R6GameService.dll @ 100345e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __stdcall DestroyStdStringRange(std::basic_string<char> *first,std::basic_string<char> *last)
{
  __asm {
    // Cache both range endpoints; increment cursor by0x1c after each current imported destructor, RET8.
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    esi,edi
    je     Branch2
    mov    edi,edi
  Branch1:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch1
  Branch2:
    pop    edi
    pop    esi
    ret    0x8
  }
}

// Destroys the cached narrow-string range, frees current begin and clears storage fields only after cleanup succeeds.
// R6GameService.dll @ 100346c0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyStringVector(void *vector)
{
  __asm {
    // No EH frame; cache owner/range. Null begin still clears storage, preserving incoming EAX.
    push   ebx
    mov    ebx,ecx
    push   esi
    mov    esi,DWORD PTR [ebx+0x4]
    test   esi,esi
    je     Branch5
    push   edi
    mov    edi,DWORD PTR [ebx+0x8]
    cmp    esi,edi
    je     Branch4
  Branch3:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch3
  Branch4:
    // Reload current begin after string callbacks for free; only then clear+4/+8/+c on cached owner.
    mov    eax,DWORD PTR [ebx+0x4]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    pop    edi
  Branch5:
    pop    esi
    mov    DWORD PTR [ebx+0x4],0x0
    mov    DWORD PTR [ebx+0x8],0x0
    mov    DWORD PTR [ebx+0xc],0x0
    pop    ebx
    ret
  }
}

// Tail-forwards narrow-string vector destruction to the one shared native body.
// R6GameService.dll @ 10034880 : complete native control/access order and raw ABI retained.
__declspec(naked) void __fastcall DestroyStringVectorThunk(void *vector)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyStringVector
  }
}

// Assigns the same live string value across a cached half-open destination range.
// R6GameService.dll @ 10035dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl AssignStdStringRange(std::basic_string<char> *first,std::basic_string<char> *last,const std::basic_string<char> *value)
{
  __asm {
    // Cache first/last; only a nonempty range loads the fill pointer. Imported assignment reloads per element.
    push   esi
    mov    esi,DWORD PTR [esp+0x8]
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    cmp    esi,edi
    je     Branch7
    push   ebx
    mov    ebx,DWORD PTR [esp+0x18]
  Branch6:
    push   ebx
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch6
    pop    ebx
  Branch7:
    // Cdecl: empty range retains incoming EAX, otherwise raw final assignment EAX. No local EH.
    pop    edi
    pop    esi
    ret
  }
}

// Assigns strings backwards through current imported assignment and returns the final destination cursor.
// R6GameService.dll @ 10035e00 : complete native control/access order and raw ABI retained.
__declspec(naked) std::basic_string<char> * __cdecl CopyStdStringsBackward(const std::basic_string<char> *first,const std::basic_string<char> *last,std::basic_string<char> *destinationEnd)
{
  __asm {
    // Cache source endpoints and destination end, decrement both cursors before each assignment; equality terminates.
    push   ebx
    mov    ebx,DWORD PTR [esp+0x8]
    push   esi
    mov    esi,DWORD PTR [esp+0x10]
    cmp    ebx,esi
    je     Branch9
    push   edi
    mov    edi,DWORD PTR [esp+0x18]
  Branch8:
    sub    esi,0x1c
    sub    edi,0x1c
    push   esi
    mov    ecx,edi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot
    cmp    esi,ebx
    jne    Branch8
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret
  Branch9:
    // Empty range returns original destination end without reading/copying a string.
    mov    eax,DWORD PTR [esp+0x14]
    pop    esi
    pop    ebx
    ret
  }
}

// Copy-constructs a source range, publishing progress in caller slots for its separate cleanup catch.
// R6GameService.dll @ 10035e40 : complete native control/access order and raw ABI retained.
__declspec(naked) std::basic_string<char> * __cdecl ConstructStdStringRange(const std::basic_string<char> *first,const std::basic_string<char> *last,std::basic_string<char> *destination)
{
  __asm {
    // EBP frame: cache initial destination at -14; source EDI advances, but original end slot +c reloads each iteration.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::StringRangeConstructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x10]
    push   edi
    mov    edi,DWORD PTR [ebp+0x8]
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],esi
    mov    DWORD PTR [ebp-0x4],ebx
    nop
  Branch10:
    cmp    edi,DWORD PTR [ebp+0xc]
    je     Branch12
    // Overwrite original source-begin slot +8 with current destination; state 1 covers each attempted constructor.
    mov    DWORD PTR [ebp+0x8],esi
    cmp    esi,ebx
    mov    BYTE PTR [ebp-0x4],0x1
    // Skip construction only at destination address zero; still advance the raw cursor by 28.
    je     Branch11
    push   edi
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2
  Branch11:
    // Lower to state 0 and publish new cursor in original destination slot +10 only after constructor returns.
    add    esi,0x1c
    mov    BYTE PTR [ebp-0x4],bl
    mov    DWORD PTR [ebp+0x10],esi
    add    edi,0x1c
    jmp    Branch10
  Branch12:
    // Native continuation @10035eb9; intervening catch35e97 has its own canonical definition below.
    mov    ecx,DWORD PTR [ebp-0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Destroys the cached completed destination prefix from range construction and rethrows the active exception.
// R6GameService.dll @ 10035e97 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyFailedStringRangePrefixAndRethrow(void)
{
  __asm {
    // Inherited EBP: cache initial local -14 and current completed end at original argument +10 before destructor callbacks.
    mov    esi,DWORD PTR [ebp-0x14]
    mov    edi,DWORD PTR [ebp+0x10]
    cmp    esi,edi
    je     Branch14
  Branch13:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch13
  Branch14:
    // No normal return: actual33a16(0,0) rethrows. Preserve partial destructor failure effects.
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Constructs a cached count of strings while reloading the current fill pointer and publishing argument-slot progress.
// R6GameService.dll @ 10035ed0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ConstructRepeatedStdStrings(std::basic_string<char> *destination,uint count,const std::basic_string<char> *value)
{
  __asm {
    // Cache destination ESI/count EDI; count slot +c is reused as current-attempt destination, not decremented count.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::RepeatedStringConstructionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    push   ebx
    push   esi
    mov    esi,DWORD PTR [ebp+0x8]
    push   edi
    mov    edi,DWORD PTR [ebp+0xc]
    xor    ebx,ebx
    mov    DWORD PTR [ebp-0x10],esp
    mov    DWORD PTR [ebp-0x14],esi
    mov    DWORD PTR [ebp-0x4],ebx
    nop
  Branch15:
    cmp    edi,ebx
    jbe    Branch17
    // Save current destination in original count slot; set state 1 before null gate. Fill pointer +10 reloads per ctor.
    mov    DWORD PTR [ebp+0xc],esi
    cmp    esi,ebx
    mov    BYTE PTR [ebp-0x4],0x1
    je     Branch16
    mov    eax,DWORD PTR [ebp+0x10]
    push   eax
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2
  Branch16:
    // Decrement cached count, advance ESI, lower state 0 and publish cursor into original destination slot +8.
    dec    edi
    add    esi,0x1c
    mov    BYTE PTR [ebp-0x4],bl
    mov    DWORD PTR [ebp+0x8],esi
    jmp    Branch15
  Branch17:
    // Native continuation @10035f49; separate catch35f27 below. Preserve raw last constructor EAX or initial FS link.
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

// Destroys the completed repeated-construction prefix from parent slots and rethrows the active exception.
// R6GameService.dll @ 10035f27 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyFailedRepeatedStringPrefixAndRethrow(void)
{
  __asm {
    // Inherited EBP: cache initial local -14/current completed end +8, call current destructor for each 28-byte step.
    mov    esi,DWORD PTR [ebp-0x14]
    mov    edi,DWORD PTR [ebp+0x8]
    cmp    esi,edi
    je     Branch19
  Branch18:
    mov    ecx,esi
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    add    esi,0x1c
    cmp    esi,edi
    jne    Branch18
  Branch19:
    // Rethrow through actual33a16(0,0), without restoring a stronger exception guarantee.
    xor    ebx,ebx
    push   ebx
    push   ebx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Forwards repeated construction with two ignored words and returns cached destination plus count times 28.
// R6GameService.dll @ 10035fc0 : complete native control/access order and raw ABI retained.
__declspec(naked) std::basic_string<char> * __thiscall ConstructRepeatedStdStringRange(void *unusedReceiver,std::basic_string<char> *destination,uint count,const std::basic_string<char> *value)
{
  __asm {
    // ECX is unused as receiver but is passed as ignored word4; word5 duplicates value. RET0xc.
    mov    eax,DWORD PTR [esp+0xc]
    push   esi
    mov    esi,DWORD PTR [esp+0xc]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    push   eax
    push   ecx
    mov    ecx,DWORD PTR [esp+0x1c]
    push   ecx
    push   esi
    push   edi
    call   R6GameServiceAddresses::ConstructRepeatedStdStrings
    // Return original cached count *28 + destination modulo32, independent of callee EAX and argument-slot mutation.
    mov    eax,esi
    imul   eax,eax,0x1c
    add    esp,0x14
    add    eax,edi
    pop    edi
    pop    esi
    ret    0xc
  }
}

// Forwards current range-construction parent slots to the shared RET helper without destroying strings.
// R6GameService.dll @ 10066630 : complete native control/access order and raw ABI retained.
__declspec(naked) void ForwardStringRangeNoOpCleanup(void)
{
  __asm {
    // Pass parent +8 and +10 as cdecl words to actual59130 RET; only register/argument effects, no string cleanup.
    mov    eax,DWORD PTR [ebp+0x10]
    push   eax
    mov    ecx,DWORD PTR [ebp+0x8]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Selects range-construction metadata with its no-op lifetime action and manual prefix-cleanup catchall.
// R6GameService.dll @ 10066641 : complete native control/access order and raw ABI retained.
__declspec(naked) void StringRangeConstructionExceptionHandler(void)
{
  __asm {
    // FuncInfo80b4c: three unwind states, state1 action66630, catchall35e97 for try states0..1.
    mov    eax,R6GameServiceAddresses::StringRangeConstructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Forwards current repeated-construction parent slots to the shared RET helper without destroying strings.
// R6GameService.dll @ 10066650 : complete native control/access order and raw ABI retained.
__declspec(naked) void ForwardRepeatedStringNoOpCleanup(void)
{
  __asm {
    // Pass parent +c and +8 as cdecl words to actual59130 RET; preserve resulting EAX/ECX and parent storage.
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    mov    ecx,DWORD PTR [ebp+0xc]
    push   ecx
    call   R6GameServiceAddresses::list_node_support_NoOp
    add    esp,0x8
    ret
  }
}

// Selects repeated-construction metadata with its no-op lifetime action and separate prefix-cleanup catchall.
// R6GameService.dll @ 10066661 : complete native control/access order and raw ABI retained.
__declspec(naked) void RepeatedStringConstructionExceptionHandler(void)
{
  __asm {
    // FuncInfo80ba4: three unwind states, state1 action66650, catchall35f27 for try states0..1.
    mov    eax,R6GameServiceAddresses::RepeatedStringConstructionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Returns zero for null begin, otherwise the signed modular byte-span quotient by 28.
// R6GameService.dll @ 10033f70 : complete native control/access order and raw ABI retained.
__declspec(naked) int __fastcall GetStringVectorElementCount(void *vector)
{
  __asm {
    // Null begin avoids end load and leaves ECX as receiver; otherwise retain native signed32 division sequence.
    mov    eax,DWORD PTR [ecx+0x4]
    test   eax,eax
    jne    Branch20
    ret
  Branch20:
    mov    ecx,DWORD PTR [ecx+0x8]
    sub    ecx,eax
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
    ret
  }
}

// Preserves the fill string and inserts repeated elements through native growth or either in-place construction path.
// R6GameService.dll @ 10035ff0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall InsertRepeatedStdStringsAtPosition(void *vector,std::basic_string<char> *insertPosition,uint copyCount,const std::basic_string<char> *value)
{
  __asm {
    // EBP frame: saved string -30, new begin -38/completed end -34, receiver -3c, cookie -14; two catches are separate.
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::StringVectorInsertionExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x30
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    push   esi
    push   edi
    mov    DWORD PTR [ebp-0x14],eax
    mov    eax,DWORD PTR [ebp+0x10]
    mov    esi,ecx
    mov    DWORD PTR [ebp-0x10],esp
    push   eax
    lea    ecx,[ebp-0x30]
    mov    DWORD PTR [ebp-0x3c],esi
    // Copy fill before any count gate; state 0 begins after ctor, even for count zero. Current fields reload afterward.
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2
    mov    ebx,DWORD PTR [esi+0x4]
    xor    ecx,ecx
    cmp    ebx,ecx
    mov    DWORD PTR [ebp-0x4],ecx
    je     Branch21
    mov    ecx,DWORD PTR [esi+0xc]
    sub    ecx,ebx
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    ecx,edx
    shr    ecx,0x1f
    add    ecx,edx
  Branch21:
    mov    edi,DWORD PTR [ebp+0xc]
    test   edi,edi
    je     Branch36
    test   ebx,ebx
    jne    Branch22
    xor    eax,eax
    jmp    Branch23
  Branch22:
    mov    edx,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esi+0x8]
    sub    ebx,edx
    mov    eax,0x92492493
    imul   ebx
    add    edx,ebx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
  Branch23:
    // Maximum element count 0x9249249; current size and unsigned count select the native length-error edge.
    mov    edx,0x9249249
    sub    edx,eax
    cmp    edx,edi
    jae    Branch24
    mov    ecx,esi
    call   R6GameServiceAddresses::ThrowVectorLengthException
  Branch24:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch25
    xor    eax,eax
    jmp    Branch26
  Branch25:
    mov    edx,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esi+0x8]
    sub    ebx,edx
    mov    eax,0x92492493
    imul   ebx
    add    edx,ebx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
  Branch26:
    add    eax,edi
    cmp    ecx,eax
    jae    Branch34
    // Try capacity + capacity/2 unless above native max, then use zero; take at least current size + cached count.
    mov    eax,ecx
    shr    eax,1
    mov    edx,0x9249249
    sub    edx,eax
    cmp    edx,ecx
    jae    Branch27
    xor    ecx,ecx
    jmp    Branch28
  Branch27:
    add    ecx,eax
  Branch28:
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    jne    Branch29
    xor    eax,eax
    jmp    Branch30
  Branch29:
    mov    edx,DWORD PTR [esi+0x4]
    mov    ebx,DWORD PTR [esi+0x8]
    sub    ebx,edx
    mov    eax,0x92492493
    imul   ebx
    add    edx,ebx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
  Branch30:
    add    eax,edi
    cmp    ecx,eax
    jae    Branch31
    mov    ecx,esi
    call   R6GameServiceAddresses::GetStringVectorElementCount
    mov    ecx,eax
    add    ecx,edi
  Branch31:
    // Replace original count slot +c with allocation bytes; EDI retains element count. Allocator runs in state 0.
    imul   ecx,ecx,0x1c
    push   ecx
    mov    DWORD PTR [ebp+0xc],ecx
    call   R6GameServiceAddresses::AllocateTaggedBytesCdecl
    // Read current position/begin after allocation. State 1 owns completed new prefix; actual range helper gets five words.
    mov    ecx,DWORD PTR [ebp+0x8]
    mov    edx,DWORD PTR [ebp+0x8]
    push   ecx
    mov    ebx,eax
    mov    eax,DWORD PTR [esi+0x4]
    push   esi
    push   ebx
    push   edx
    push   eax
    mov    DWORD PTR [ebp-0x38],ebx
    mov    DWORD PTR [ebp-0x34],ebx
    mov    BYTE PTR [ebp-0x4],0x1
    call   R6GameServiceAddresses::ConstructStdStringRange
    // Publish prefix-helper EAX into -34 before repeated construction; current position extra word remains ignored.
    mov    ecx,DWORD PTR [ebp+0x8]
    add    esp,0x18
    push   ecx
    push   esi
    lea    edx,[ebp-0x30]
    push   edx
    push   edi
    push   eax
    mov    DWORD PTR [ebp-0x34],eax
    call   R6GameServiceAddresses::ConstructRepeatedStdStrings
    // Advance tracked prefix by cached count*28, then reload position/current end for suffix construction.
    mov    edx,DWORD PTR [ebp+0x8]
    mov    ecx,DWORD PTR [ebp-0x34]
    mov    eax,edi
    imul   eax,eax,0x1c
    add    esp,0x14
    push   edx
    add    ecx,eax
    mov    eax,DWORD PTR [esi+0x8]
    push   esi
    push   ecx
    push   eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    mov    DWORD PTR [ebp-0x34],ecx
    call   R6GameServiceAddresses::ConstructStdStringRange
    // Lower to state 0 before old-size calculation/destruction. New size caches before old destructor/free callbacks.
    mov    eax,DWORD PTR [esi+0x4]
    add    esp,0x14
    test   eax,eax
    mov    DWORD PTR [ebp-0x4],0x0
    je     Branch32
    mov    ecx,DWORD PTR [esi+0x8]
    sub    ecx,eax
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
  Branch32:
    add    edi,eax
    mov    eax,DWORD PTR [esi+0x4]
    test   eax,eax
    je     Branch33
    mov    ecx,DWORD PTR [esi+0x8]
    push   ecx
    push   eax
    mov    ecx,esi
    call   R6GameServiceAddresses::DestroyStdStringRange
    // Reload current old begin after range destructors for free; publish capacity/end/begin only after free returns.
    mov    eax,DWORD PTR [esi+0x4]
    push   eax
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
  Branch33:
    mov    edx,DWORD PTR [ebp+0xc]
    imul   edi,edi,0x1c
    add    edx,ebx
    add    edi,ebx
    mov    DWORD PTR [esi+0xc],edx
    mov    DWORD PTR [esi+0x8],edi
    mov    DWORD PTR [esi+0x4],ebx
    jmp    Branch36
  Branch34:
    // Native continuation @100361f3, after separately canonical catch361d1. Original value slot +10 becomes scratch.
    mov    ecx,DWORD PTR [esi+0x8]
    mov    ebx,DWORD PTR [ebp+0x8]
    mov    edx,ecx
    sub    edx,ebx
    mov    DWORD PTR [ebp+0x10],edx
    mov    eax,0x92492493
    imul   edx
    add    edx,DWORD PTR [ebp+0x10]
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
    cmp    eax,edi
    mov    DWORD PTR [ebp-0x38],ecx
    jae    Branch35
    // Short tail: copy old tail beyond insertion gap first, then construct remaining fill under state 3.
    mov    edx,DWORD PTR [ebp+0x8]
    mov    eax,edi
    imul   eax,eax,0x1c
    push   edx
    mov    DWORD PTR [ebp+0x10],eax
    push   esi
    add    eax,ebx
    push   eax
    push   ecx
    push   ebx
    call   R6GameServiceAddresses::ConstructStdStringRange
    mov    ecx,DWORD PTR [esi+0x8]
    add    esp,0x14
    sub    ecx,ebx
    lea    eax,[ebp-0x30]
    push   eax
    mov    eax,0x92492493
    imul   ecx
    mov    eax,DWORD PTR [esi+0x8]
    add    edx,ecx
    sar    edx,0x4
    mov    ecx,edx
    shr    ecx,0x1f
    add    ecx,edx
    sub    edi,ecx
    push   edi
    push   eax
    mov    ecx,esi
    mov    BYTE PTR [ebp-0x4],0x3
    call   R6GameServiceAddresses::ConstructRepeatedStdStringRange
    // Publish current end + saved count bytes, lower state 0, then assign the original gap; ESI no longer receiver.
    mov    edx,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [ebp+0x10]
    add    edx,eax
    mov    DWORD PTR [esi+0x8],edx
    mov    esi,edx
    lea    edx,[ebp-0x30]
    push   edx
    sub    esi,eax
    push   esi
    push   ebx
    mov    DWORD PTR [ebp-0x4],0x0
    call   R6GameServiceAddresses::AssignStdStringRange
    add    esp,0xc
    jmp    Branch36
  Branch35:
    // Native continuation @100362b0, after separate catch3628d. Long/equal tail: cache count bytes and old end.
    imul   edi,edi,0x1c
    mov    eax,ecx
    sub    eax,edi
    mov    DWORD PTR [ebp+0x8],eax
    mov    edx,DWORD PTR [ebp+0x8]
    push   edx
    push   esi
    push   ecx
    push   ecx
    push   eax
    call   R6GameServiceAddresses::ConstructStdStringRange
    // Publish actual range-helper EAX as new end; backward-assign using four words, then fill-assign three words.
    mov    ecx,DWORD PTR [ebp-0x38]
    mov    edx,DWORD PTR [ebp+0x8]
    mov    DWORD PTR [esi+0x8],eax
    mov    eax,DWORD PTR [ebp+0x8]
    push   eax
    push   ecx
    push   edx
    push   ebx
    call   R6GameServiceAddresses::CopyStdStringsBackward
    lea    eax,[ebp-0x30]
    push   eax
    add    edi,ebx
    push   edi
    push   ebx
    call   R6GameServiceAddresses::AssignStdStringRange
    add    esp,0x30
  Branch36:
    // Lower to state -1 before saved-value destructor. Retain raw destructor EAX, restore FS then actual cookie check.
    lea    ecx,[ebp-0x30]
    mov    DWORD PTR [ebp-0x4],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
    mov    ecx,DWORD PTR [ebp-0xc]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [ebp-0x14]
    call   R6GameServiceAddresses::__security_check_cookie
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret    0xc
  }
}

// Destroys the completed new-allocation prefix, frees its cached allocation and rethrows insertion failure.
// R6GameService.dll @ 100361d1 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyFailedStringInsertionAndRethrow(void)
{
  __asm {
    // Inherited EBP: cache new begin ESI, destroy [-38,-34), free cached ESI even if callback changes parent slots.
    mov    eax,DWORD PTR [ebp-0x34]
    mov    esi,DWORD PTR [ebp-0x38]
    mov    ecx,DWORD PTR [ebp-0x3c]
    push   eax
    push   esi
    call   R6GameServiceAddresses::DestroyStdStringRange
    push   esi
    call   R6GameServiceAddresses::FreeThroughGlobalAllocator
    add    esp,0x4
    // Actual33a16(0,0) rethrows; normal parent action handles saved fill lifetime during unwind.
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the shifted tail selected by current parent count, position and vector end, then rethrows.
// R6GameService.dll @ 1003628d : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyShiftedStringTailAndRethrow(void)
{
  __asm {
    // Use current original count*28, current receiver end and current original position; do not use saved old end -38.
    mov    eax,DWORD PTR [ebp+0xc]
    mov    ecx,DWORD PTR [ebp-0x3c]
    imul   eax,eax,0x1c
    mov    edx,DWORD PTR [ecx+0x8]
    add    edx,eax
    push   edx
    mov    edx,DWORD PTR [ebp+0x8]
    add    eax,edx
    push   eax
    call   R6GameServiceAddresses::DestroyStdStringRange
    // Rethrow through actual33a16(0,0); this catch destroys shifted tail but never frees vector allocation.
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Inserts one string, writes its relocated iterator through the late-loaded result pointer and returns that pointer.
// R6GameService.dll @ 10036320 : complete native control/access order and raw ABI retained.
__declspec(naked) uint * __thiscall InsertOneStdStringAndStoreIterator(void *vector,uint *resultIterator,std::basic_string<char> *insertPosition,const std::basic_string<char> *value)
{
  __asm {
    // Cache position EBX and receiver EDI. Original position argument is reused as element-count scratch when begin nonnull.
    push   ebx
    mov    ebx,DWORD PTR [esp+0xc]
    push   esi
    push   edi
    mov    edi,ecx
    mov    esi,DWORD PTR [edi+0x4]
    test   esi,esi
    je     Branch37
    mov    ecx,DWORD PTR [edi+0x8]
    sub    ecx,esi
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
    mov    DWORD PTR [esp+0x14],eax
    jne    Branch38
  Branch37:
    xor    esi,esi
    jmp    Branch39
  Branch38:
    mov    ecx,ebx
    sub    ecx,esi
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    esi,edx
    shr    esi,0x1f
    add    esi,edx
  Branch39:
    // Cached iterator index is zero for empty vector, otherwise signed (position-begin)/28; actual insert count is 1.
    mov    ecx,DWORD PTR [esp+0x18]
    push   ecx
    push   0x1
    push   ebx
    mov    ecx,edi
    call   R6GameServiceAddresses::InsertRepeatedStdStringsAtPosition
    // Use current begin after insertion, then load current hidden result pointer late; EAX returns that pointer, RET0xc.
    imul   esi,esi,0x1c
    add    esi,DWORD PTR [edi+0x4]
    mov    eax,DWORD PTR [esp+0x10]
    pop    edi
    mov    DWORD PTR [eax],esi
    pop    esi
    pop    ebx
    ret    0xc
  }
}

// Appends directly into spare storage or inserts through an iterator result held in the original argument slot.
// R6GameService.dll @ 10036390 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall AppendStdStringToVector(void *vector,const std::basic_string<char> *value)
{
  __asm {
    // Compare signed span quotients as unsigned counts; null begin always selects insertion.
    push   ebx
    push   esi
    push   edi
    mov    edi,ecx
    mov    ebx,DWORD PTR [edi+0x4]
    test   ebx,ebx
    jne    Branch40
    xor    esi,esi
    jmp    Branch41
  Branch40:
    mov    ecx,DWORD PTR [edi+0x8]
    sub    ecx,ebx
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    esi,edx
    shr    esi,0x1f
    add    esi,edx
  Branch41:
    test   ebx,ebx
    je     Branch42
    mov    ecx,DWORD PTR [edi+0xc]
    sub    ecx,ebx
    mov    eax,0x92492493
    imul   ecx
    add    edx,ecx
    sar    edx,0x4
    mov    eax,edx
    shr    eax,0x1f
    add    eax,edx
    cmp    esi,eax
    jae    Branch42
    // Direct append: cache old end, actual repeated helper gets (end,1,value,vector,value); publish cached end+28.
    mov    eax,DWORD PTR [esp+0x10]
    mov    ecx,DWORD PTR [esp+0x10]
    mov    esi,DWORD PTR [edi+0x8]
    push   eax
    push   edi
    push   ecx
    push   0x1
    push   esi
    call   R6GameServiceAddresses::ConstructRepeatedStdStrings
    add    esp,0x14
    add    esi,0x1c
    mov    DWORD PTR [edi+0x8],esi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch42:
    // Slow append uses original argument slot as hidden iterator result, overwriting its former value pointer.
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [edi+0x8]
    push   edx
    push   eax
    lea    eax,[esp+0x18]
    push   eax
    mov    ecx,edi
    call   R6GameServiceAddresses::InsertOneStdStringAndStoreIterator
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Destroys the insertion parent-frame saved fill string through the current CRT import.
// R6GameService.dll @ 10066670 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroySavedStringInsertionValue(void)
{
  __asm {
    // Inherited parent EBP-30 is saved fill; map state0->-1 owns this current-import destructor action.
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects insertion metadata with the saved string lifetime and two distinct manual cleanup catchalls.
// R6GameService.dll @ 10066679 : complete native control/access order and raw ABI retained.
__declspec(naked) void StringVectorInsertionExceptionHandler(void)
{
  __asm {
    // FuncInfo80c30/map80bc0: five states, saved-string action only at 0; catch361d1 for state1, catch3628d for state3.
    mov    eax,R6GameServiceAddresses::StringVectorInsertionExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
