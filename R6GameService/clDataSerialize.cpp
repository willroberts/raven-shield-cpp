#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 100800e8 : function metadata supplied by the exception selector.
extern const R6GameServiceNative::FuncInfo ClDataSerializeListParseExceptionHandlerFunctionInfo;

// Tail-forwards clDataSerialize's vtable-only cleanup, preserving its native register behavior.
// R6GameService.dll @ 1002a870 : ECX object, no stack arguments; JMP1002be00.
__declspec(naked) void __fastcall ResetClDataSerializeVtableAlias(void *object)
{
  __asm {
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtable
  }
}

// Normalized nested-list entry locals at -0x24 through -4; two unwind states have no native action.
struct ClDataSerializeListParseFrame {
  byte padding[3];
  byte constructorTag;
  uint constructionFlags;
  uint *savedInnerList;
  undefined1 *sourceEnd;
  uint *childAllocation;
  uint *savedHeadSlot;
  void *previousExceptionList;
  void *handler;
  uint state;
};

// Native signed-tag remap for L..s and the five parser handler targets, including the default path.
// R6GameService.dll data @ 1002bed0 : native storage identity retained.
const byte GTaggedParseTagRemap[40] = {
  0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3
};
// R6GameService.dll data @ 1002bebc : native storage identity retained.
const uint GTaggedParseTargets[5] = {R6GameServiceAddresses::clDataSerializeBranch4,R6GameServiceAddresses::clDataSerializeBranch2,R6GameServiceAddresses::clDataSerializeBranch5,R6GameServiceAddresses::clDataSerializeBranch3,R6GameServiceAddresses::clDataSerializeBranch7};
// R6GameService.dll data @ 1002c5c8 : native storage identity retained.
const uint GTaggedWriteTargets[6] = {R6GameServiceAddresses::clDataSerializeBranch29,R6GameServiceAddresses::clDataSerializeBranch32,R6GameServiceAddresses::clDataSerializeBranch23,R6GameServiceAddresses::clDataSerializeBranch31,R6GameServiceAddresses::clDataSerializeBranch30,R6GameServiceAddresses::clDataSerializeBranch33};

// Clears destination and parses tags through cached end/cursor argument words, retaining partial inserts and status.
// R6GameService.dll @ 1002be10 : complete native dispatch/argument/access order and raw ABI retained.
__declspec(naked) uint __thiscall ParseTaggedValues(
    void *parserContext,undefined4 *source,undefined1 *destination)
{
  __asm {
    push   ebx
    push   ebp
    mov    ebp,DWORD PTR [esp+0x10]
    push   esi
    push   edi
    // Save parser context and destination before clear; load source only after the clear callback.
    mov    edi,ecx
    mov    eax,DWORD PTR [ebp+0xc]
    lea    ecx,[ebp+0xc]
    xor    bl,bl
    call   DWORD PTR [eax+0x4]
    mov    esi,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esi+0xc]
    mov    ecx,DWORD PTR [esi+0x10]
    // Original source argument becomes cached end; original destination argument becomes mutable cursor.
    mov    DWORD PTR [esp+0x18],eax
    mov    DWORD PTR [esp+0x14],ecx
  Branch1:
    cmp    eax,DWORD PTR [esp+0x14]
    je Branch8
    mov    cl,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [esp+0x18],eax
    // Signed-extend the tag, subtract L, then use the exact byte-remap and handler tables.
    movsx  eax,cl
    add    eax,0xffffffb4
    cmp    eax,0x27
    ja Branch7
    xor    edx,edx
    mov    dl,BYTE PTR [eax+R6GameServiceAddresses::GTaggedParseTagRemap]
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GTaggedParseTargets]
  Branch2:
    lea    eax,[esp+0x18]
    push   ebp
    push   eax
    push   esi
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseListValue
    jmp Branch6
  Branch3:
    lea    ecx,[esp+0x18]
    push   ebp
    push   ecx
    push   esi
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseStringValue
    jmp Branch6
  Branch4:
    lea    edx,[esp+0x18]
    push   ebp
    push   edx
    push   esi
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseWordValue
    jmp Branch6
  Branch5:
    lea    eax,[esp+0x18]
    push   ebp
    push   eax
    push   esi
    mov    ecx,edi
    call   R6GameServiceAddresses::ParseByteBlockValue
    // Child AL controls failure; retain child upper EAX or reload cursor for the next equality check.
  Branch6:
    test   al,al
    sete   bl
    test   bl,bl
    jne Branch9
    mov    eax,DWORD PTR [esp+0x18]
    jmp Branch1
  Branch7:
    mov    bl,0x1
  Branch8:
    test   bl,bl
    // POPs preserve flags; SETE changes only AL and retains the selected native upper EAX.
  Branch9:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    sete   al
    ret    0x8
  }
}

// Native nested-list dispatch for L..s, including closing bracket and default targets.
// R6GameService.dll data @ 1002c08c : native storage identity retained.
const byte GNestedParseTagRemap[40] = {
  0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,5,2,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4
};
// R6GameService.dll data @ 1002c074 : native storage identity retained.
const uint GNestedParseTargets[6] = {R6GameServiceAddresses::clDataSerializeBranch15,R6GameServiceAddresses::clDataSerializeBranch13,R6GameServiceAddresses::clDataSerializeBranch19,R6GameServiceAddresses::clDataSerializeBranch16,R6GameServiceAddresses::clDataSerializeBranch14,R6GameServiceAddresses::clDataSerializeBranch18};

// Parses a child list through a cached end and appends it on success or failure, accepting a missing closing bracket.
// R6GameService.dll @ 1002bf00 : complete native frame/state/cursor/argument accesses and raw ABI retained.
__declspec(naked) uint __thiscall ParseListValue(
    void *parserContext,undefined4 *source,int *cursorAddress,int destination)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::ClDataSerializeListParseExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x18
    // Entry frame: tag-0x21, flags-0x20, inner-0x1c, cached end-0x18, child-0x14, head slot-0x10, EH-0x0c/-8/-4.
    mov    DWORD PTR [esp+0x4],0x0
    mov    eax,DWORD PTR [esp+0x28]
    push   ebx
    push   ebp
    push   esi
    mov    ebp,ecx
    // Cache source end before allocation; normal construction enters only state5 of the six-state unwind map.
    mov    ecx,DWORD PTR [eax+0x10]
    push   edi
    push   0x18
    xor    bl,bl
    mov    DWORD PTR [esp+0x20],ecx
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x20],esi
    test   esi,esi
    je Branch10
    // Inline kind3/base initialization, retaining staged subobject/head pointers and one-bit construction flags.
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esi+0x14],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x14],0x1
    mov    DWORD PTR [esi+0x8],0x3
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    lea    edi,[esi+0xc]
    mov    eax,edi
    mov    DWORD PTR [esp+0x18],eax
    lea    ecx,[eax+0x4]
    mov    DWORD PTR [esp+0x24],ecx
    lea    edx,[esp+0x13]
    mov    DWORD PTR [esp+0x30],0x5
    push   edx
    call   R6GameServiceAddresses::InitializeCircularListSentinel
    mov    eax,edi
    mov    DWORD PTR [eax],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [edi],R6GameServiceAddresses::clDataListPTR_LAB
    jmp Branch11
  Branch10:
    xor    esi,esi
    // Load cursor-address argument only after construction and lower state before any child conversion.
  Branch11:
    mov    edi,DWORD PTR [esp+0x3c]
    mov    DWORD PTR [esp+0x30],0xffffffff
  Branch12:
    mov    eax,DWORD PTR [edi]
    mov    ecx,DWORD PTR [esp+0x1c]
    cmp    eax,ecx
    je Branch19
    mov    cl,BYTE PTR [eax]
    inc    eax
    mov    DWORD PTR [edi],eax
    // Signed tag bias/remap dispatch includes a closing bracket target; equality with cached end also succeeds.
    movsx  eax,cl
    add    eax,0xffffffb4
    cmp    eax,0x27
    ja Branch18
    xor    ecx,ecx
    mov    cl,BYTE PTR [eax+R6GameServiceAddresses::GNestedParseTagRemap]
    jmp    DWORD PTR [ecx*4+R6GameServiceAddresses::GNestedParseTargets]
    // Forward the current original source argument and shared cursor address into recursive nested parsing.
  Branch13:
    mov    edx,DWORD PTR [esp+0x38]
    push   esi
    push   edi
    push   edx
    mov    ecx,ebp
    call   R6GameServiceAddresses::ParseListValue
    jmp Branch17
  Branch14:
    mov    eax,DWORD PTR [esp+0x38]
    push   esi
    push   edi
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::ParseStringValue
    jmp Branch17
  Branch15:
    mov    ecx,DWORD PTR [esp+0x38]
    push   esi
    push   edi
    push   ecx
    mov    ecx,ebp
    call   R6GameServiceAddresses::ParseWordValue
    jmp Branch17
  Branch16:
    mov    edx,DWORD PTR [esp+0x38]
    push   esi
    push   edi
    push   edx
    mov    ecx,ebp
    call   R6GameServiceAddresses::ParseByteBlockValue
  Branch17:
    test   al,al
    sete   bl
    test   bl,bl
    je Branch12
    jmp Branch19
  Branch18:
    mov    bl,0x1
    // Always append: overwrite original source argument with child and original cursor-pointer argument with head.
  Branch19:
    mov    eax,DWORD PTR [esp+0x40]
    mov    DWORD PTR [esp+0x38],esi
    lea    ecx,[esp+0x3c]
    lea    esi,[eax+0x10]
    push   ecx
    mov    ecx,esi
    call   R6GameServiceAddresses::CopyListHeadSlot
    lea    edx,[esp+0x38]
    mov    ecx,esi
    push   edx
    call   R6GameServiceAddresses::AllocateListPayloadNode
    // Reload the saved head after node allocation; retain the failed flag while publishing all links.
    mov    esi,DWORD PTR [esp+0x3c]
    pop    edi
    test   bl,bl
    mov    edx,DWORD PTR [esi+0x4]
    lea    ecx,[esi+0x4]
    mov    DWORD PTR [eax],esi
    mov    DWORD PTR [eax+0x4],edx
    mov    DWORD PTR [edx],eax
    mov    DWORD PTR [ecx],eax
    mov    ecx,DWORD PTR [esp+0x24]
    pop    esi
    pop    ebp
    pop    ebx
    // Replace only AL with status, retaining allocated-node upper EAX and restored previous-FS ECX.
    sete   al
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x24
    ret    0xc
  }
}

// Resets the output cursor and forwards the complete tagged-list writer EAX, retaining the dead self-compare block.
// R6GameService.dll @ 1002c470 : complete native dispatch/argument/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteTaggedEntries(void *serializer,int sourceList,undefined1 *output)
{
  __asm {
    push   ebx
    push   edi
    mov    edi,DWORD PTR [esp+0x10]
    mov    ebx,ecx
    mov    eax,DWORD PTR [edi+0x10]
    mov    ecx,DWORD PTR [edi+0xc]
    // Self-compare makes the old-tail move block unreachable; reset end to current begin.
    cmp    eax,eax
    jne Branch20
    mov    eax,ecx
    jmp Branch21
  Branch20:
    push   esi
    mov    esi,eax
    sub    esi,eax
    push   esi
    push   eax
    push   ecx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,esi
    pop    esi
  Branch21:
    mov    DWORD PTR [edi+0x10],eax
    // Load source-list argument after resetting the output field, then forward the dispatcher result unchanged.
    mov    eax,DWORD PTR [esp+0xc]
    push   edi
    push   eax
    mov    ecx,ebx
    call   R6GameServiceAddresses::WriteTaggedEntryList
    pop    edi
    pop    ebx
    ret    0x8
  }
}

// Dispatches six kinds with a cached sentinel, closing nested brackets and reading next even after child failure.
// R6GameService.dll @ 1002c4b0 : complete native dispatch/argument/access order and raw ABI retained.
__declspec(naked) uint __thiscall WriteTaggedEntryList(void *serializer,int sourceList,undefined1 *output)
{
  __asm {
    sub    esp,0xc
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    push   ebp
    push   esi
    mov    eax,DWORD PTR [eax+0x10]
    push   edi
    // Scratch: saved context at EntryESP-8, cached sentinel at-4, closing-tag byte at-9.
    mov    DWORD PTR [esp+0x14],ecx
    xor    bl,bl
    mov    esi,DWORD PTR [eax]
    mov    DWORD PTR [esp+0x18],eax
  Branch22:
    cmp    esi,eax
    je Branch37
    mov    edi,DWORD PTR [esi+0x8]
    mov    eax,DWORD PTR [edi+0x8]
    dec    eax
    cmp    eax,0x5
    ja Branch36
    jmp    DWORD PTR [eax*4+R6GameServiceAddresses::GTaggedWriteTargets]
    // Nested list caches this output receiver and triplet through both brackets and recursion.
  Branch23:
    mov    ebx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [ebx+0x10]
    mov    edx,DWORD PTR [ebx+0x14]
    lea    ebp,[ebx+0xc]
    cmp    eax,edx
    je Branch25
    test   eax,eax
    je Branch24
    mov    BYTE PTR [eax],0x5b
  Branch24:
    inc    DWORD PTR [ebp+0x4]
    jmp Branch26
  Branch25:
    push   0x1
    lea    ecx,[esp+0x24]
    push   0x1
    push   ecx
    push   R6GameServiceAddresses::TextSLb
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
    // Restore saved serializer context after opening growth, then recurse even if an earlier field was null.
    mov    ecx,DWORD PTR [esp+0x14]
  Branch26:
    push   ebx
    push   edi
    call   R6GameServiceAddresses::WriteTaggedEntryList
    // Capture child failure before always attempting the closing bracket.
    mov    ecx,DWORD PTR [ebp+0x8]
    test   al,al
    mov    eax,DWORD PTR [ebp+0x4]
    sete   bl
    cmp    eax,ecx
    je Branch28
    test   eax,eax
    je Branch27
    mov    BYTE PTR [eax],0x5d
  Branch27:
    inc    DWORD PTR [ebp+0x4]
    jmp Branch35
  Branch28:
    push   0x1
    lea    edx,[esp+0x17]
    push   0x1
    push   edx
    push   R6GameServiceAddresses::TextSLb2
    push   eax
    mov    ecx,ebp
    call   R6GameServiceAddresses::GrowByteBufferAndInsertRepeatedBytes
    jmp Branch35
  Branch29:
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    push   edi
    call   R6GameServiceAddresses::WriteTaggedType1
    jmp Branch34
  Branch30:
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   edi
    call   R6GameServiceAddresses::WriteTaggedType5
    jmp Branch34
  Branch31:
    mov    eax,DWORD PTR [esp+0x24]
    push   eax
    push   edi
    call   R6GameServiceAddresses::WriteTaggedType4
    jmp Branch34
  Branch32:
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   edi
    call   R6GameServiceAddresses::WriteTaggedType2
    jmp Branch34
    // Kind6 passes payload+0x0c contents as the referenced value, not the payload object itself.
  Branch33:
    mov    eax,DWORD PTR [esp+0x24]
    mov    edi,DWORD PTR [edi+0xc]
    push   eax
    push   edi
    call   R6GameServiceAddresses::WriteTaggedValueByType
  Branch34:
    test   al,al
    sete   bl
    // Load current next before testing failure; successful continuation reloads only the cached sentinel.
  Branch35:
    mov    esi,DWORD PTR [esi]
    test   bl,bl
    jne Branch38
    mov    ecx,DWORD PTR [esp+0x14]
    mov    eax,DWORD PTR [esp+0x18]
    jmp Branch22
  Branch36:
    mov    bl,0x1
  Branch37:
    test   bl,bl
  Branch38:
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    sete   al
    add    esp,0xc
    ret    0x8
  }
}

// Releases the child allocation saved while constructing a nested list.
// R6GameService.dll @ 10065cf0 : inherited parent EBP; saved allocation at EBP-0x14.
__declspec(naked) void __cdecl ReleaseNestedListAllocation(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x14]
    push   eax
    call   R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Forwards child+0x18 to empty cleanup only when construction flag bit zero is set.
// R6GameService.dll @ 10065cfa : inherited parent EBP; flags at -0x20, child at -0x14.
__declspec(naked) void __cdecl CleanupNestedListContext(void)
{
  __asm {
    mov    eax,dword ptr [ebp-0x20]
    and    eax,1
    test   eax,eax
    je     noContext
    mov    ecx,dword ptr [ebp-0x14]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  noContext:
    ret
  }
}

// Restores the saved nested-list allocation's clData base vtable.
// R6GameService.dll @ 10065d14 : inherited parent EBP; saved child at EBP-0x14.
__declspec(naked) void __cdecl ResetNestedListBase(void)
{
  __asm {
    mov    ecx,dword ptr [ebp-0x14]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Forwards the local constructor tag address to empty cleanup, retaining incoming EAX.
// R6GameService.dll @ 10065d1c : inherited parent EBP; constructor tag at EBP-0x21.
__declspec(naked) void __cdecl CleanupNestedListConstructorTag(void)
{
  __asm {
    lea    ecx,[ebp-0x21]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  }
}

// Selects the nested-list parser's FuncInfo 0x100800e8 for the shared C++ exception handler.
// R6GameService.dll @ 10065d24 : inherited parent frame; tail-transfers to 10033906.
__declspec(naked) void __cdecl ClDataSerializeListParseExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ClDataSerializeListParseExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Native six-kind dispatch targets, including type-six reference recursion.
// R6GameService.dll data @ 1002cc90 : native storage identity retained.
const uint GTaggedValueTargets[6] = {R6GameServiceAddresses::GTaggedValueTargetsCase1,R6GameServiceAddresses::GTaggedValueTargetsCase2,R6GameServiceAddresses::GTaggedValueTargetsCase3,R6GameServiceAddresses::GTaggedValueTargetsCase4,R6GameServiceAddresses::GTaggedValueTargetsCase5,R6GameServiceAddresses::GTaggedValueTargetsCase6};

// Dispatches one payload, follows wrappers and closes nested brackets even after child failure.
// R6GameService.dll @ 1002cac0 : complete native arguments/accesses/growth and raw ABI retained, RET8.
__declspec(naked) uint __thiscall WriteTaggedValueByType(void *serializer,int *payload,undefined1 *output)
{
  __asm {
    // Cache serializer at entry-4 and dispatch full kind-1 through the six-target native table; no local EH frame.
    sub    esp,0xc
    mov    eax,DWORD PTR [esp+0x10]
    push   ebx
    push   ebp
    push   esi
    mov    edx,DWORD PTR [eax+0x8]
    push   edi
    dec    edx
    mov    DWORD PTR [esp+0x18],ecx
    cmp    edx,0x5
    ja Branch50
    jmp    DWORD PTR [edx*4+R6GameServiceAddresses::GTaggedValueTargets]
    // Kind3 caches output triplet for bracket writes; child output argument is reloaded only after opening growth.
    mov    edx,DWORD PTR [esp+0x24]
    mov    ebx,DWORD PTR [edx+0x10]
    lea    esi,[edx+0xc]
    mov    edx,DWORD PTR [edx+0x14]
    cmp    ebx,edx
    je Branch40
    test   ebx,ebx
    je Branch39
    mov    BYTE PTR [ebx],0x5b
  Branch39:
    inc    DWORD PTR [esi+0x4]
    jmp Branch44
  Branch40:
    mov    edx,DWORD PTR [esi]
    mov    eax,ebx
    sub    eax,edx
    mov    DWORD PTR [esp+0x10],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x14],eax
    lea    ecx,[esp+0x10]
    jb Branch41
    lea    ecx,[esp+0x14]
  Branch41:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebp,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebx,eax
    jne Branch42
    mov    eax,ebp
    jmp Branch43
  Branch42:
    sub    ebx,eax
    push   ebx
    push   eax
    push   ebp
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebx
  Branch43:
    // Fill opening bracket, release old output storage and publish replacement before restoring payload/context.
    push   R6GameServiceAddresses::TextSLb
    push   0x1
    push   eax
    call   R6GameServiceAddresses::FillByteRangeAndReturnEnd
    mov    ecx,esi
    mov    ebx,eax
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    eax,[edi+ebp*1]
    mov    ecx,esi
    push   eax
    push   ebx
    push   ebp
    call   R6GameServiceAddresses::SetThreeWordRecord
    mov    eax,DWORD PTR [esp+0x20]
    mov    ecx,DWORD PTR [esp+0x18]
  Branch44:
    // Forward current original output argument to list dispatch; closing bracket still uses cached triplet.
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedEntryList
    // Save child AL in original output argument low byte and attempt close even after failure.
    mov    ebp,DWORD PTR [esi+0x4]
    mov    ecx,DWORD PTR [esi+0x8]
    cmp    ebp,ecx
    mov    BYTE PTR [esp+0x24],al
    je Branch46
    test   ebp,ebp
    je Branch45
    mov    BYTE PTR [ebp+0x0],0x5d
  Branch45:
    // Fitting close updates end through ECX and returns the entire child EAX unchanged.
    mov    ecx,DWORD PTR [esi+0x4]
    pop    edi
    inc    ecx
    mov    DWORD PTR [esi+0x4],ecx
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch46:
    // Closing growth reuses original payload and saved-context slots for one/occupied length.
    mov    edx,DWORD PTR [esi]
    mov    eax,ebp
    sub    eax,edx
    mov    DWORD PTR [esp+0x20],0x1
    cmp    eax,0x1
    mov    DWORD PTR [esp+0x18],eax
    lea    ecx,[esp+0x20]
    jb Branch47
    lea    ecx,[esp+0x18]
  Branch47:
    mov    edi,DWORD PTR [ecx]
    add    edi,eax
    push   edi
    call   R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ebx,eax
    mov    eax,DWORD PTR [esi]
    cmp    ebp,eax
    jne Branch48
    mov    eax,ebx
    jmp Branch49
  Branch48:
    sub    ebp,eax
    push   ebp
    push   eax
    push   ebx
    call   R6GameServiceAddresses::memmove
    add    esp,0xc
    add    eax,ebp
  Branch49:
    push   R6GameServiceAddresses::TextSLb2
    push   0x1
    push   eax
    call   R6GameServiceAddresses::FillByteRangeAndReturnEnd
    mov    ecx,esi
    mov    ebp,eax
    call   R6GameServiceAddresses::ReleaseFirstWordBuffer
    lea    eax,[ebx+edi*1]
    mov    ecx,esi
    push   eax
    push   ebp
    push   ebx
    call   R6GameServiceAddresses::SetThreeWordRecord
    // After close growth return capacity upper EAX with saved child AL; partial output is never rolled back.
    mov    al,BYTE PTR [esp+0x24]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
    // Leaf branches forward the complete child result; kind6 recursively follows payload+0xc with saved context.
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedType1
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedType5
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedType4
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
    mov    edx,DWORD PTR [esp+0x24]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedType2
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
    mov    edx,DWORD PTR [esp+0x24]
    mov    eax,DWORD PTR [eax+0xc]
    push   edx
    push   eax
    call   R6GameServiceAddresses::WriteTaggedValueByType
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    add    esp,0xc
    ret    0x8
  Branch50:
    // Unknown kind returns original payload-pointer upper EAX with AL0.
    pop    edi
    pop    esi
    pop    ebp
    xor    al,al
    pop    ebx
    add    esp,0xc
    ret    0x8
  }
}

// Installs the serializer primary table and optional secondary table, clearing its saved ECX scratch word.
// R6GameService.dll @ 1002bdb0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall ConstructClDataSerialize(void *object,int initializeSecondaryTable)
{
  __asm {
    // The incoming ECX save is scratch: clear it before table writes and pop zero into ECX on return.
    push   ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [esp+0x8]
    test   ecx,ecx
    mov    DWORD PTR [esp+0x0],0x0
    mov    DWORD PTR [eax],R6GameServiceAddresses::clDataSerializeVTable
    je Branch51
    mov    DWORD PTR [eax+0x4],0x10076ba4
  Branch51:
    pop    ecx
    ret    0x4
  }
}

// Resets the serializer table and conditionally frees storage for flag bit zero, returning the saved receiver.
// R6GameService.dll @ 1002bde0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __thiscall DeleteClDataSerialize(void *object,byte flags)
{
  __asm {
    push   esi
    mov    esi,ecx
    call   R6GameServiceAddresses::ResetClDataSerializeVtable
    // Test only the low-byte deletion bit after actual table reset; preserve the saved receiver across free.
    test   BYTE PTR [esp+0x8],0x1
    je Branch52
    push   esi
    call   R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch52:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Restores the serializer table without changing EAX or stack arguments.
// R6GameService.dll @ 1002be00 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __fastcall ResetClDataSerializeVtable(void *object)
{
  __asm {
    mov    DWORD PTR [ecx],R6GameServiceAddresses::clDataSerializeVTable
    ret
  }
}

// Native virtual-table prefix: clDataSerializeVTable
// R6GameService.dll data @ 10076bb0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clDataSerializeVTableRecord {
  R6GameServiceNative::Address DeleteClDataSerialize; // +0x00
};
const clDataSerializeVTableRecord clDataSerializeVTable = {R6GameServiceAddresses::DeleteClDataSerialize};
