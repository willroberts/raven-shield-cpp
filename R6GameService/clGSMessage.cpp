#include "native_addresses.h"
#include "native_records.h"

int __stdcall FormatWordAsDecimal(uint codeWord,char *output);
uint __stdcall FormatByteLabel(uint codeWord,char *output);

// Serialize payload to temporary binary descriptor; build cleared six-byte header and optionally transform payload
// through current slot14 twice.
// Cache original serialized length before allocation, reload current descriptor range for copy, retain current
// transform size after output.
// Reuse output argument for final buffer, free header/output/copy in order, then release descriptor; only descriptors
// have EH cleanup. RET4.
// R6GameService.dll @ 10059b00 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall SerializePayloadRecord(void *message,uint *outputSize)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMessageSerializerEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x30
    push    ebx
    push    ebp
    push    esi
    push    edi
    mov    edi,0x1
    mov    DWORD PTR [esp+0x14],0x0
    mov    esi,ecx
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x38],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],edi
    mov    ebp,0x2
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::PTR_LAB
    mov    DWORD PTR [esp+0x28],ebp
    push    0x0
    lea    ecx,[esp+0x30]
    mov    DWORD PTR [esp+0x4c],edi
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    ebx,R6GameServiceAddresses::clDataBinPTR_FUN
    mov    DWORD PTR [esp+0x20],ebx
    push    edi
    lea    ecx,[esp+0x1c]
    mov    DWORD PTR [esp+0x4c],ebp
    call    R6GameServiceAddresses::ConstructClDataSerialize
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x20]
    push    eax
    push    ecx
    lea    ecx,[esp+0x20]
    mov    BYTE PTR [esp+0x50],0x3
    call    R6GameServiceAddresses::WriteTaggedEntries
    mov    edi,DWORD PTR [esp+0x30]
    mov    edx,DWORD PTR [esp+0x2c]
    push    0x6
    sub    edi,edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    xor    edx,edx
    mov    ebp,eax
    mov    DWORD PTR [eax],edx
    test    edi,edi
    mov    WORD PTR [eax+0x4],dx
    jne    Branch1
    push    0x6
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderSize24
    mov    cl,BYTE PTR [esi+0xc]
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte3HighBits
    mov    dl,BYTE PTR [esi+0xe]
    push    edx
    push    ebp
    call    R6GameServiceAddresses::SetHeaderByte3Bit5
    mov    al,BYTE PTR [esi+0xd]
    push    eax
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte4
    mov    cl,BYTE PTR [esi+0x10]
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte5HighNibble
    mov    dl,BYTE PTR [esi+0x11]
    push    edx
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte5LowNibble
    mov    eax,DWORD PTR [esp+0x50]
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x48],0x2
    mov    DWORD PTR [eax],0x6
    call    R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x20],ebx
    lea    ecx,[esp+0x2c]
    mov    DWORD PTR [esp+0x48],0x4
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    eax,ebp
    jmp    Branch3
  Branch1:
    push    edi
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x2c]
    mov    ebx,eax
    mov    eax,DWORD PTR [esp+0x30]
    mov    DWORD PTR [esp+0x14],ebx
    cmp    eax,ecx
    je    Branch2
    sub    eax,ecx
    push    eax
    push    ecx
    push    ebx
    call    R6GameServiceAddresses::memmove
    add    esp,0xc
  Branch2:
    mov    edx,DWORD PTR [esi]
    lea    eax,[esp+0x10]
    push    eax
    push    0x0
    push    edi
    push    ebx
    mov    ecx,esi
    call    DWORD PTR [edx+0x14]
    mov    ecx,DWORD PTR [esp+0x10]
    push    ecx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,DWORD PTR [esi]
    mov    ebx,eax
    lea    eax,[esp+0x10]
    push    eax
    push    ebx
    push    edi
    push    ecx
    mov    ecx,esi
    call    DWORD PTR [edx+0x14]
    mov    edx,DWORD PTR [esp+0x10]
    mov    edi,DWORD PTR [esp+0x50]
    lea    eax,[edx+0x6]
    push    eax
    push    ebp
    mov    DWORD PTR [edi],eax
    call    R6GameServiceAddresses::WriteHeaderSize24
    mov    al,BYTE PTR [esi+0xc]
    push    eax
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte3HighBits
    mov    cl,BYTE PTR [esi+0xe]
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::SetHeaderByte3Bit5
    mov    dl,BYTE PTR [esi+0xd]
    push    edx
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte4
    mov    al,BYTE PTR [esi+0x10]
    push    eax
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte5HighNibble
    mov    cl,BYTE PTR [esi+0x11]
    push    ecx
    push    ebp
    call    R6GameServiceAddresses::WriteHeaderByte5LowNibble
    mov    edx,DWORD PTR [edi]
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,ebp
    mov    edx,eax
    lea    edi,[eax+0x6]
    push    ebp
    mov    esi,DWORD PTR [ecx]
    mov    DWORD PTR [esp+0x54],eax
    mov    DWORD PTR [edx],esi
    mov    esi,ebx
    mov    cx,WORD PTR [ecx+0x4]
    mov    WORD PTR [edx+0x4],cx
    mov    ecx,DWORD PTR [esp+0x14]
    mov    edx,ecx
    shr    ecx,0x2
    rep    movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
    mov    ecx,edx
    and    ecx,0x3
    rep    movs BYTE PTR es:[edi],BYTE PTR ds:[esi]
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    mov    eax,DWORD PTR [esp+0x14]
    push    eax
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    ecx,[esp+0x18]
    mov    BYTE PTR [esp+0x48],0x2
    call    R6GameServiceAddresses::ResetClDataSerializeVtable
    mov    DWORD PTR [esp+0x20],R6GameServiceAddresses::clDataBinPTR_FUN
    mov    DWORD PTR [esp+0x48],0x5
    lea    ecx,[esp+0x2c]
    call    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
    mov    eax,DWORD PTR [esp+0x50]
  Branch3:
    mov    ecx,DWORD PTR [esp+0x40]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x3c
    ret    0x4
  }
}

// If inherited flagS-38 bit0 is set, tail empty-base cleanup with addressS-10.
// R6GameService.dll @ 100698b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x38]
    and    eax,0x1
    test    eax,eax
    je    Branch4
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch4:
    ret
  }
}

// Tail base-vtable reset for inherited binary descriptorS-2c.
// R6GameService.dll @ 100698c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail binary descriptor destruction atS-2c; its current buffer is freed without clearing the member.
// R6GameService.dll @ 100698cf : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tail serializer vtable reset for inherited serializerS-34.
// R6GameService.dll @ 100698d7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x34]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Tail base-vtable reset after the entered empty-path buffer release; do not retry that release.
// R6GameService.dll @ 100698df : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail base-vtable reset after the entered transformed-path buffer release; do not retry that release.
// R6GameService.dll @ 100698e7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SerializePayloadRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select six-state descriptor cleanup FuncInfo and tail shared C++ frame dispatch.
// R6GameService.dll @ 100698ef : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMessageSerializerEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::SerializePayloadRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal descriptor-only cleanup map/FuncInfo for the packet serializer.
// R6GameService.dll data @ 10084398 : native storage identity retained.
const R6GameServiceNative::UnwindEntry SerializePayloadRecordUnwindMap[6] = {
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind1},
  {0x0, R6GameServiceAddresses::SerializePayloadRecordUnwind2},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind3},
  {0x2, R6GameServiceAddresses::SerializePayloadRecordUnwind4},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind5},
  {-1, R6GameServiceAddresses::SerializePayloadRecordUnwind6},
};

// Literal descriptor-only cleanup map/FuncInfo for the packet serializer.
// R6GameService.dll data @ 100843c8 : native storage identity retained.
const R6GameServiceNative::FuncInfo SerializePayloadRecordExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::SerializePayloadRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Read current message8 helper and forward four full words plus literal selector1 to shared slot0c dispatch; raw
// EAX/RET16.
// R6GameService.dll @ 10059d40 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall EncodeMessagePayload(
    void *message,uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    0x1
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    eax
    push    edx
    call    R6GameServiceAddresses::DispatchThroughSelectedSlot0C
    ret    0x10
  }
}

// Read current message8 helper and forward four full words plus literal selector1 to shared slot10 dispatch; raw
// EAX/RET16.
// R6GameService.dll @ 10059d70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DecodeMessagePayload(
    void *message,uint word0,uint word1,uint word2,uint word3)
{
  __asm {
    mov    eax,DWORD PTR [esp+0x10]
    mov    edx,DWORD PTR [esp+0xc]
    mov    ecx,DWORD PTR [ecx+0x8]
    push    0x1
    push    eax
    mov    eax,DWORD PTR [esp+0x10]
    push    edx
    mov    edx,DWORD PTR [esp+0x10]
    push    eax
    push    edx
    call    R6GameServiceAddresses::DispatchThroughSelectedSlot10
    ret    0x10
  }
}

// Construct/publish a fresh payload list before unsigned length>=6 and exact encoded-size comparison; retain replaced
// old payload.
// Decode current slot18 twice, ignore status, zero query-sized allocation then use current reported size for
// replacement/parse.
// Reuse original size argument for payload pointer; clean temporary list/serializer/binary descriptor and set only
// final AL/RET8.
// Ten-state construction cleanup owns descriptors and pending list allocation, never the raw decoded byte buffer.
// R6GameService.dll @ 10059da0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall DecodePayloadRecord(void *message,const byte *input,uint inputSizeWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectMessageDecoderEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x50
    push    ebx
    push    ebp
    push    esi
    xor    ebx,ebx
    mov    esi,0x1
    mov    DWORD PTR [esp+0x10],ebx
    push    edi
    mov    ebp,ecx
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataBinOwnerBaseOffsets
    mov    DWORD PTR [esp+0x58],R6GameServiceAddresses::ClDataBinBaseOffsets
    mov    DWORD PTR [esp+0x14],esi
    push    ebx
    push    0x2
    lea    ecx,[esp+0x48]
    mov    DWORD PTR [esp+0x70],ebx
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x50]
    mov    DWORD PTR [esp+0x6c],esi
    call    R6GameServiceAddresses::InitializeEmptyByteBufferTriplet
    mov    DWORD PTR [esp+0x40],R6GameServiceAddresses::clDataBinPTR_FUN
    push    esi
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x6c],0x2
    call    R6GameServiceAddresses::ConstructClDataSerialize
    mov    edi,R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x28],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x38],edi
    mov    DWORD PTR [esp+0x14],0x3
    push    ebx
    push    0x3
    lea    ecx,[esp+0x2c]
    mov    BYTE PTR [esp+0x70],0x4
    call    R6GameServiceAddresses::InitializeClDataFields
    push    ebx
    lea    ecx,[esp+0x34]
    mov    DWORD PTR [esp+0x6c],0x5
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::clDataListPTR_LAB
    push    0x18
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    esi,eax
    mov    DWORD PTR [esp+0x18],esi
    cmp    esi,ebx
    je    Branch5
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esi+0x14],edi
    mov    DWORD PTR [esp+0x14],0x7
    push    ebx
    push    0x3
    mov    ecx,esi
    mov    BYTE PTR [esp+0x70],0x8
    call    R6GameServiceAddresses::InitializeClDataFields
    lea    edi,[esi+0xc]
    push    ebx
    mov    ecx,edi
    mov    DWORD PTR [esp+0x6c],0x9
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [edi],R6GameServiceAddresses::clDataListPTR_LAB
    jmp    Branch6
  Branch5:
    xor    esi,esi
  Branch6:
    mov    ebx,DWORD PTR [esp+0x74]
    mov    BYTE PTR [esp+0x68],0x6
    cmp    ebx,0x6
    mov    DWORD PTR [ebp+0x14],esi
    jb    Branch8
    mov    esi,DWORD PTR [esp+0x70]
    push    esi
    call    R6GameServiceAddresses::ReadHeaderSize24
    cmp    eax,ebx
    jne    Branch8
    push    esi
    call    R6GameServiceAddresses::ReadHeaderByte3LowBits
    push    esi
    mov    BYTE PTR [ebp+0xe],al
    call    R6GameServiceAddresses::ReadHeaderByte4
    push    esi
    mov    BYTE PTR [ebp+0xd],al
    call    R6GameServiceAddresses::ReadHeaderByte5HighNibble
    push    esi
    mov    BYTE PTR [ebp+0x10],al
    call    R6GameServiceAddresses::ReadHeaderByte5LowNibble
    add    ebx,0xfffffffa
    mov    BYTE PTR [ebp+0x11],al
    test    ebx,ebx
    jne    Branch7
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x68],0x2
    call    R6GameServiceAddresses::ResetClDataSerializeVtable
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x68],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBin
    jmp    Branch10
  Branch7:
    mov    eax,DWORD PTR [ebp+0x0]
    lea    ecx,[esp+0x10]
    push    ecx
    add    esi,0x6
    push    0x0
    push    ebx
    push    esi
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x84],esi
    call    DWORD PTR [eax+0x18]
    mov    edx,DWORD PTR [esp+0x10]
    push    edx
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    ecx,DWORD PTR [esp+0x10]
    mov    esi,eax
    mov    edx,ecx
    xor    eax,eax
    mov    edi,esi
    shr    ecx,0x2
    rep    stos DWORD PTR es:[edi],eax
    mov    ecx,edx
    mov    edx,DWORD PTR [esp+0x74]
    and    ecx,0x3
    rep    stos BYTE PTR es:[edi],al
    mov    eax,DWORD PTR [ebp+0x0]
    lea    ecx,[esp+0x10]
    push    ecx
    push    esi
    push    ebx
    push    edx
    mov    ecx,ebp
    call    DWORD PTR [eax+0x18]
    mov    eax,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x40]
    push    eax
    push    esi
    call    R6GameServiceAddresses::ReplaceClDataBinBytes
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    edx,[esp+0x40]
    push    ecx
    push    edx
    lea    ecx,[esp+0x24]
    call    R6GameServiceAddresses::ParseTaggedValues
    test    al,al
    push    esi
    jne    Branch9
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch8:
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x68],0x2
    call    R6GameServiceAddresses::ResetClDataSerializeVtable
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x68],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBin
    xor    al,al
    jmp    Branch11
  Branch9:
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0x68],0x3
    call    R6GameServiceAddresses::DestroyClDataList
    lea    ecx,[esp+0x1c]
    mov    BYTE PTR [esp+0x68],0x2
    call    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0x68],0xffffffff
    call    R6GameServiceAddresses::DestroyClDataBinAlias
  Branch10:
    mov    al,0x1
  Branch11:
    mov    ecx,DWORD PTR [esp+0x60]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x5c
    ret    0x8
  }
}

// Test inheritedS-58 bit0, tail empty-base cleanup with addressS-10 if constructed.
// R6GameService.dll @ 10069900 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind1(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x1
    test    eax,eax
    je    Branch12
    lea    ecx,[ebp-0x10]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch12:
    ret
  }
}

// Tail base-vtable reset for inherited binary descriptorS-2c.
// R6GameService.dll @ 10069917 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail destruction of inherited binary descriptorS-2c, using its current buffer.
// R6GameService.dll @ 1006991f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyClDataBinAlias
  }
}

// Tail serializer vtable reset at inheritedS-50 before binary destruction.
// R6GameService.dll @ 10069927 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x50]
    jmp    R6GameServiceAddresses::ResetClDataSerializeVtableAlias
  }
}

// Test inheritedS-58 bit1, tail empty-base cleanup with addressS-30 if constructed.
// R6GameService.dll @ 1006992f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind5(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x2
    test    eax,eax
    je    Branch13
    lea    ecx,[ebp-0x30]
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch13:
    ret
  }
}

// Tail base-vtable reset for inherited temporary listS-48.
// R6GameService.dll @ 10069946 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Tail temporary list destruction at inheritedS-48 before serializer/binary cleanup.
// R6GameService.dll @ 1006994e : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind7(void)
{
  __asm {
    lea    ecx,[ebp-0x48]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Free CURRENT pending heap-list pointerS-54; no decoded-byte buffer cleanup is present.
// R6GameService.dll @ 10069956 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind8(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x54]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Test inheritedS-58 bit2, tail empty-base cleanup at CURRENT pending list pointerS-54 plus18.
// R6GameService.dll @ 10069960 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind9(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x58]
    and    eax,0x4
    test    eax,eax
    je    Branch14
    mov    ecx,DWORD PTR [ebp-0x54]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch14:
    ret
  }
}

// Reset base vtable through CURRENT pending list pointerS-54 before pending allocation release.
// R6GameService.dll @ 1006997a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DecodePayloadRecordUnwind10(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x54]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select exact ten-state decoder construction FuncInfo and tail shared C++ frame dispatch.
// R6GameService.dll @ 10069982 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectMessageDecoderEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DecodePayloadRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native decoder construction cleanup map/FuncInfo.
// R6GameService.dll data @ 100843e4 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DecodePayloadRecordUnwindMap[10] = {
  {-1, R6GameServiceAddresses::DecodePayloadRecordUnwind1},
  {0x0, R6GameServiceAddresses::DecodePayloadRecordUnwind2},
  {-1, R6GameServiceAddresses::DecodePayloadRecordUnwind3},
  {0x2, R6GameServiceAddresses::DecodePayloadRecordUnwind4},
  {0x3, R6GameServiceAddresses::DecodePayloadRecordUnwind5},
  {0x4, R6GameServiceAddresses::DecodePayloadRecordUnwind6},
  {0x3, R6GameServiceAddresses::DecodePayloadRecordUnwind7},
  {0x6, R6GameServiceAddresses::DecodePayloadRecordUnwind8},
  {0x7, R6GameServiceAddresses::DecodePayloadRecordUnwind9},
  {0x8, R6GameServiceAddresses::DecodePayloadRecordUnwind10},
};

// Literal native decoder construction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084434 : native storage identity retained.
const R6GameServiceNative::FuncInfo DecodePayloadRecordExceptionInfo = {
  0x19930520,
  0xa,
  R6GameServiceAddresses::DecodePayloadRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Initialize metadata/lowBYTE fields and allocate list24; source nonzero clones with flag1, otherwise constructs empty
// list inline.
// Clone branch reuses original code argumentS+8 for allocation and arms BYTEstate2; empty-list header allocation has no
// pending-list guard.
// Publish owner14 only after construction or NULL branch; seven full physical words, original receiver return/RET28.
// R6GameService.dll @ 10059940 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall ConstructClGSMessage(
    void *message,uint contextWord,uint codeOrPendingWord,uint byte0eWord,uint byte10Word,uint byte11Word,
    uint     sourceWord,uint initializeBaseWord)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::MessageConstructionExceptionHandler
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x8
    mov    eax,DWORD PTR [esp+0x30]
    push    esi
    push    edi
    mov    edi,ecx
    test    eax,eax
    mov    DWORD PTR [esp+0xc],edi
    mov    DWORD PTR [esp+0x8],0x0
    je    Branch15
    mov    DWORD PTR [edi+0x4],0x100781b8
    mov    DWORD PTR [esp+0x8],0x1
  Branch15:
    mov    eax,DWORD PTR [esp+0x20]
    mov    DWORD PTR [edi+0x8],eax
    mov    cl,BYTE PTR [esp+0x24]
    mov    dl,BYTE PTR [esp+0x28]
    mov    al,BYTE PTR [esp+0x2c]
    mov    esi,DWORD PTR [esp+0x34]
    mov    BYTE PTR [edi+0xd],cl
    mov    cl,BYTE PTR [esp+0x30]
    push    0x18
    mov    DWORD PTR [esp+0x1c],0x1
    mov    DWORD PTR [edi],R6GameServiceAddresses::clGSMessageVTable
    mov    BYTE PTR [edi+0xc],0x0
    mov    BYTE PTR [edi+0xe],dl
    mov    BYTE PTR [edi+0x10],al
    mov    BYTE PTR [edi+0x11],cl
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    test    esi,esi
    je    Branch17
    mov    DWORD PTR [esp+0x24],eax
    test    eax,eax
    mov    BYTE PTR [esp+0x18],0x2
    je    Branch16
    push    0x1
    push    esi
    mov    ecx,eax
    call    R6GameServiceAddresses::CopyConstructClDataList
    mov    DWORD PTR [edi+0x14],eax
    jmp    Branch20
  Branch16:
    xor    eax,eax
    mov    DWORD PTR [edi+0x14],eax
    jmp    Branch20
  Branch17:
    mov    esi,eax
    test    esi,esi
    je    Branch18
    mov    DWORD PTR [esi+0x4],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esi+0x14],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esi+0x8],0x3
    mov    DWORD PTR [esi],R6GameServiceAddresses::PTR_LAB
    push    0xc
    mov    DWORD PTR [esi+0x10],0x0
    call    R6GameServiceAddresses::AllocateGameServiceBytes
    mov    DWORD PTR [eax],eax
    mov    DWORD PTR [eax+0x4],eax
    mov    DWORD PTR [esi+0x10],eax
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_FUN2
    mov    DWORD PTR [esi],R6GameServiceAddresses::clDataListPTR_FUN
    mov    DWORD PTR [esi+0xc],R6GameServiceAddresses::clDataListPTR_LAB
    jmp    Branch19
  Branch18:
    xor    esi,esi
  Branch19:
    mov    DWORD PTR [edi+0x14],esi
  Branch20:
    mov    ecx,DWORD PTR [esp+0x10]
    mov    eax,edi
    pop    edi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x14
    ret    0x1c
  }
}

// Destroy payload/base, test CURRENT original flag lowBYTE bit0 after child returns, optionally free receiver; return
// receiver/RET4.
// R6GameService.dll @ 10059a50 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall DeleteClGSMessage(void *message,uint deleteFlags)
{
  __asm {
    push    esi
    mov    esi,ecx
    call    R6GameServiceAddresses::DestroyClGSMessage
    test    BYTE PTR [esp+0x8],0x1
    je    Branch21
    push    esi
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch21:
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

// Optionally install virtual-base table, publish base table/context, clear BYTEc/10/11 and payload14; leave d/e/gaps.
// ECX0/RET8.
// R6GameService.dll @ 10059a70 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall InitializeClGSMessageFields(
        void *message,uint contextWord,uint initializeBaseWord)
{
  __asm {
    push    ecx
    mov    edx,DWORD PTR [esp+0xc]
    mov    eax,ecx
    xor    ecx,ecx
    cmp    edx,ecx
    mov    DWORD PTR [esp+0x0],ecx
    je    Branch22
    mov    DWORD PTR [eax+0x4],0x100781b8
  Branch22:
    mov    edx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [eax],R6GameServiceAddresses::clGSMessageVTable
    mov    DWORD PTR [eax+0x8],edx
    mov    BYTE PTR [eax+0xc],cl
    mov    BYTE PTR [eax+0x10],cl
    mov    BYTE PTR [eax+0x11],cl
    mov    DWORD PTR [eax+0x14],ecx
    pop    ecx
    ret    0x8
  }
}

// Install base-derived table, cache current payload14 and current-virtually delete it with full flag1, then restore
// clMessage table.
// Keep payload14 unchanged, exact one-state base cleanup and raw child EAX (previous FS value on NULL payload); no
// receiver free.
// R6GameService.dll @ 10059ab0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyClGSMessage(void *message)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::MessageDestructionExceptionHandler
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::clGSMessageVTable
    mov    ecx,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esp+0x10],0x0
    test    ecx,ecx
    je    Branch23
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch23:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi],R6GameServiceAddresses::clMessageVTable
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// If inheritedS-14 bit0 is set, tail genuine empty-base cleanup at CURRENT saved receiverS-10 plus18.
// R6GameService.dll @ 10069850 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl CleanupMessageVirtualBaseIfConstructed(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp-0x14]
    and    eax,0x1
    test    eax,eax
    je    Branch24
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x18
    jmp    R6GameServiceAddresses::list_node_support_NoOp
  Branch24:
    ret
  }
}

// Tail clMessage vtable reset through CURRENT saved constructor receiverS-10.
// R6GameService.dll @ 1006986a : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBaseDuringConstruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClMessageVtable
  }
}

// Free CURRENT original code argumentS+8 reused for clone allocation; no reconstructed snapshot or argument frame.
// R6GameService.dll @ 10069872 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl FreeMessagePendingAllocation(void)
{
  __asm {
    mov    eax,DWORD PTR [ebp+0x8]
    push    eax
    call    R6GameServiceAddresses::ForwardToAllocatorTail
    ret
  }
}

// Select literal three-state construction FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 1006987c : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageConstructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ConstructClGSMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Tail clMessage vtable reset through CURRENT saved destructor receiverS-10; payload deletion is not retried.
// R6GameService.dll @ 10069890 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetMessageBaseDuringDestruction(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ResetClMessageVtable
  }
}

// Select literal one-state destruction FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 10069898 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl MessageDestructionExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::DestroyClGSMessageExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084340 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ConstructClGSMessageUnwindMap[3] = {
  {-1, R6GameServiceAddresses::CleanupMessageVirtualBaseIfConstructed},
  {0x0, R6GameServiceAddresses::ResetMessageBaseDuringConstruction},
  {0x1, R6GameServiceAddresses::FreeMessagePendingAllocation},
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084358 : native storage identity retained.
const R6GameServiceNative::FuncInfo ConstructClGSMessageExceptionInfo = {
  0x19930520,
  0x3,
  R6GameServiceAddresses::ConstructClGSMessageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 10084374 : native storage identity retained.
const R6GameServiceNative::UnwindEntry DestroyClGSMessageUnwindMap[1] = {
  {-1, R6GameServiceAddresses::ResetMessageBaseDuringDestruction},
};

// Literal native message construction/destruction cleanup map/FuncInfo.
// R6GameService.dll data @ 1008437c : native storage identity retained.
const R6GameServiceNative::FuncInfo DestroyClGSMessageExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::DestroyClGSMessageUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Append current label/payload text: ordinary, top-level26/27 or nestedD1 with optional quoted prefix.
// EntryS: tagsS-a3..a1, listS-a0, scalarS-9c, codeS-98, childS-94, prefixS-90, labelS-80.
// Preserve ignored reader statuses, retained scratch, exact BYTE tag copies/SCAS scans and cached destination.
// Return final append raw EAX/RET4 (native append helpers return destination); no parent EH/rollback.
// R6GameService.dll @ 1005b350 : complete native control/access order and raw ABI retained.
__declspec(naked) void *__thiscall AppendDecodedRecordText(void *message,void *destination)
{
  __asm {
    sub    esp,0xa4
    push    ebp
    mov    ebp,ecx
    push    esi
    lea    eax,[esp+0x2c]
    mov    cl,BYTE PTR [ebp+0xd]
    push    edi
    push    eax
    push    ecx
    mov    ecx,ebp
    mov    DWORD PTR [esp+0x18],0x0
    call    R6GameServiceAddresses::FormatByteLabel
    mov    edi,R6GameServiceAddresses::WideTextOpenBracket
    or    ecx,0xffffffff
    xor    eax,eax
    mov    esi,DWORD PTR [esp+0xb4]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    edx,[esp+0xd]
    add    ecx,R6GameServiceAddresses::WideTextOpenBracket
    push    edx
    push    ecx
    push    R6GameServiceAddresses::WideTextOpenBracket
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    eax,[esp+0xf]
    lea    edi,[esp+0x30]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x34]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    ecx,[esp+ecx*1+0x34]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    eax,[esp+0xe]
    mov    edi,R6GameServiceAddresses::TextPunctuation4
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation4
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation4
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    al,BYTE PTR [ebp+0xd]
    cmp    al,0x26
    je    Branch31
    cmp    al,0x27
    je    Branch31
    cmp    al,0xd1
    jne    Branch30
    push    ebx
    lea    ecx,[esp+0x1c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [ebp+0x14]
    xor    bl,bl
    call    R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0x1c],0x0
    mov    ecx,DWORD PTR [ebp+0x14]
    jne    Branch25
    push    0x10
    lea    edx,[esp+0x28]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x18]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
    lea    ecx,[esp+0x1c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    ecx,DWORD PTR [esp+0x18]
    lea    edx,[esp+0x14]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::GetIndexedClDataList
    lea    eax,[esp+0x11]
    mov    edi,R6GameServiceAddresses::TextPunctuation6
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation6
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation6
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    ecx,[esp+0x13]
    lea    edi,[esp+0x24]
    push    ecx
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    lea    eax,[esp+0x28]
    lea    edx,[esp+ecx*1+0x28]
    mov    ecx,esi
    push    edx
    push    eax
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    cl,BYTE PTR [esp+0x11]
    mov    edi,R6GameServiceAddresses::TextPunctuation
    mov    BYTE PTR [esp+0x12],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0x12]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextPunctuation
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    bl,0x1
    jmp    Branch26
  Branch25:
    lea    eax,[esp+0x14]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
  Branch26:
    mov    edx,DWORD PTR [esp+0x1c]
    lea    ecx,[esp+0x34]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatWordAsDecimal
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    lea    eax,[esp+0x13]
    lea    edi,[esp+0x34]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x15]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x17],dl
    lea    edx,[esp+0x38]
    lea    ecx,[esp+ecx*1+0x38]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x11]
    mov    BYTE PTR [esp+0x11],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    eax,DWORD PTR [esp+0x1c]
    cmp    ax,0x26
    je    Branch27
    cmp    ax,0x27
    je    Branch27
    mov    ecx,DWORD PTR [esp+0x14]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
    jmp    Branch28
  Branch27:
    mov    ecx,DWORD PTR [esp+0x14]
    lea    eax,[esp+0x18]
    push    0x0
    push    eax
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    edx,DWORD PTR [esp+0x18]
    lea    ecx,[esp+0x34]
    push    ecx
    push    edx
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatWordAsDecimal
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x11]
    mov    BYTE PTR [esp+0x11],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    lea    eax,[esp+0x13]
    lea    edi,[esp+0x34]
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    mov    dl,BYTE PTR [esp+0x15]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    mov    BYTE PTR [esp+0x17],dl
    lea    edx,[esp+0x38]
    lea    ecx,[esp+ecx*1+0x38]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    al,BYTE PTR [esp+0x11]
    lea    ecx,[esp+0x12]
    mov    BYTE PTR [esp+0x12],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    mov    ecx,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x20]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch28
    mov    ecx,DWORD PTR [esp+0x20]
    push    esi
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0xc]
  Branch28:
    test    bl,bl
    pop    ebx
    je    Branch29
    mov    cl,BYTE PTR [esp+0xd]
    mov    edi,R6GameServiceAddresses::TextPunctuation4
    mov    BYTE PTR [esp+0xd],cl
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xd]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::TextPunctuation4
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation4
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
  Branch29:
    mov    al,BYTE PTR [esp+0xd]
    lea    ecx,[esp+0xd]
    mov    BYTE PTR [esp+0xd],al
    push    ecx
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push    ecx
    push    R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  Branch30:
    mov    ecx,DWORD PTR [ebp+0x14]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
    mov    al,BYTE PTR [esp+0xd]
    lea    ecx,[esp+0xd]
    mov    BYTE PTR [esp+0xd],al
    push    ecx
    mov    edi,R6GameServiceAddresses::WideTextPunctuation8
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::WideTextPunctuation8
    push    ecx
    push    R6GameServiceAddresses::WideTextPunctuation8
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangePreservingNul
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  Branch31:
    mov    ecx,DWORD PTR [ebp+0x14]
    push    0x0
    lea    edx,[esp+0x18]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch32
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x18]
    push    0x0
    push    eax
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    cl,BYTE PTR [esp+0x18]
    mov    BYTE PTR [esp+0x14],cl
  Branch32:
    mov    eax,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x30]
    push    edx
    push    eax
    mov    ecx,ebp
    call    R6GameServiceAddresses::FormatByteLabel
    lea    ecx,[esp+0xd]
    mov    edi,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextPunctuation5
    push    ecx
    push    R6GameServiceAddresses::TextPunctuation5
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    lea    edi,[esp+0x30]
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xf]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    lea    eax,[esp+ecx*1+0x34]
    lea    ecx,[esp+0x34]
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    edi,R6GameServiceAddresses::WideTextSpace2
    or    ecx,0xffffffff
    xor    eax,eax
    lea    edx,[esp+0xe]
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    push    edx
    add    ecx,R6GameServiceAddresses::WideTextSpace2
    push    ecx
    push    R6GameServiceAddresses::WideTextSpace2
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    mov    ecx,DWORD PTR [ebp+0x14]
    lea    eax,[esp+0x10]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::GetIndexedClDataList
    test    al,al
    je    Branch33
    mov    ecx,DWORD PTR [esp+0x10]
    push    esi
    mov    edx,DWORD PTR [ecx]
    call    DWORD PTR [edx+0xc]
  Branch33:
    lea    eax,[esp+0xd]
    mov    edi,R6GameServiceAddresses::TextCloseBracketLine
    push    eax
    or    ecx,0xffffffff
    xor    eax,eax
    repnz    scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    add    ecx,R6GameServiceAddresses::TextCloseBracketLine
    push    ecx
    push    R6GameServiceAddresses::TextCloseBracketLine
    mov    ecx,esi
    call    R6GameServiceAddresses::AppendByteRangeWithLocalTag
    pop    edi
    pop    esi
    pop    ebp
    add    esp,0xa4
    ret    0x4
  }
}

// Print current message label/payload using ordinary, top26/27 or nestedD1 paths and temporary owning lists.
// EntryS: codeS-d4, zeroed scalarS-d0, reusable listS-cc, main listS-b4, prefixS-9c and labelS-8c.
// Keep unchecked reader/copy statuses, exact state BYTE/full stores and destructor disarm order.
// Return newline printf raw EAX on ordinary path or final list-release raw EAX; exact twelve-state guard. No stack
// arguments.
// R6GameService.dll @ 1005af70 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PrintDecodedRecord(void *message)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::PrintedRecordExceptionHandler
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0xc8
    push    ebx
    push    ebp
    push    esi
    mov    esi,ecx
    xor    ebx,ebx
    lea    eax,[esp+0x54]
    mov    DWORD PTR [esp+0x10],ebx
    mov    cl,BYTE PTR [esi+0xd]
    push    edi
    push    eax
    push    ecx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatByteLabel
    lea    edx,[esp+0x58]
    push    edx
    push    R6GameServiceAddresses::TextS5
    call    R6GameServiceAddresses::printf
    mov    al,BYTE PTR [esi+0xd]
    add    esp,0x8
    cmp    al,0x26
    je    Branch41
    cmp    al,0x27
    je    Branch41
    cmp    al,0xd1
    jne    Branch40
    mov    eax,0x3
    xor    bl,bl
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x44],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x38],eax
    mov    DWORD PTR [esp+0x30],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x40]
    mov    DWORD PTR [esp+0xe4],eax
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    mov    DWORD PTR [esp+0xe8],0x4
    call    R6GameServiceAddresses::ReadIndexedWord
    cmp    WORD PTR [esp+0x10],0x0
    jne    Branch34
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xe4],0x5
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    0x10
    lea    ecx,[esp+0x4c]
    push    0x0
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    mov    BYTE PTR [esp+0xec],0x6
    call    R6GameServiceAddresses::CopyIndexedStringBounded
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x18]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    lea    eax,[esp+0x10]
    push    0x0
    push    eax
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::ReadIndexedWord
    lea    ecx,[esp+0x30]
    push    0x1
    push    ecx
    lea    ecx,[esp+0x20]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    lea    edx,[esp+0x48]
    push    edx
    push    R6GameServiceAddresses::TextS4
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    mov    bl,0x1
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xe0],0x7
    call    R6GameServiceAddresses::DestroyClDataPointerList
    mov    BYTE PTR [esp+0xe0],0x4
    jmp    Branch35
  Branch34:
    mov    ecx,DWORD PTR [esi+0x14]
    lea    eax,[esp+0x30]
    push    0x1
    push    eax
    call    R6GameServiceAddresses::CopyIndexedClDataList
  Branch35:
    mov    edx,DWORD PTR [esp+0x10]
    lea    ecx,[esp+0x58]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatWordAsDecimal
    lea    eax,[esp+0x58]
    push    eax
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    mov    eax,DWORD PTR [esp+0x18]
    add    esp,0x8
    cmp    ax,0x26
    je    Branch36
    cmp    ax,0x27
    je    Branch36
    lea    ecx,[esp+0x30]
    call    R6GameServiceAddresses::PrintClDataList
    jmp    Branch38
  Branch36:
    push    0x0
    push    0x3
    lea    ecx,[esp+0x20]
    mov    DWORD PTR [esp+0x24],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x34],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    call    R6GameServiceAddresses::InitializeClDataFields
    push    0x0
    lea    ecx,[esp+0x28]
    mov    BYTE PTR [esp+0xe4],0x8
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x14]
    push    0x0
    push    ecx
    lea    ecx,[esp+0x38]
    mov    BYTE PTR [esp+0xe8],0x9
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    eax,DWORD PTR [esp+0x14]
    lea    edx,[esp+0x58]
    push    edx
    push    eax
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatWordAsDecimal
    lea    ecx,[esp+0x58]
    push    ecx
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    lea    edx,[esp+0x18]
    lea    ecx,[esp+0x30]
    push    0x1
    push    edx
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch37
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::PrintClDataList
  Branch37:
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    lea    ecx,[esp+0x24]
    mov    BYTE PTR [esp+0xe0],0xa
    call    R6GameServiceAddresses::DestroyClDataPointerList
  Branch38:
    test    bl,bl
    je    Branch39
    push    R6GameServiceAddresses::TextPunctuation4
    call    R6GameServiceAddresses::printf
    add    esp,0x4
  Branch39:
    push    R6GameServiceAddresses::TextCloseBracketLine
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    mov    DWORD PTR [esp+0x30],ebp
    mov    DWORD PTR [esp+0x3c],edi
    mov    DWORD PTR [esp+0xe0],0xb
    lea    ecx,[esp+0x3c]
    jmp    Branch44
  Branch40:
    mov    ecx,DWORD PTR [esi+0x14]
    mov    eax,DWORD PTR [ecx]
    call    DWORD PTR [eax+0x10]
    push    R6GameServiceAddresses::WideTextPunctuation8
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    jmp    Branch45
  Branch41:
    mov    DWORD PTR [esp+0x1c],R6GameServiceAddresses::ClDataListBaseOffsets
    mov    DWORD PTR [esp+0x2c],R6GameServiceAddresses::ClDataListInnerBaseOffsets
    mov    DWORD PTR [esp+0x20],0x3
    mov    DWORD PTR [esp+0x18],R6GameServiceAddresses::PTR_LAB
    push    ebx
    lea    ecx,[esp+0x28]
    mov    DWORD PTR [esp+0xe4],ebx
    call    R6GameServiceAddresses::ConstructClDataPointerList
    mov    ebp,R6GameServiceAddresses::clDataListPTR_FUN
    mov    edi,R6GameServiceAddresses::clDataListPTR_LAB
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    push    ebx
    lea    ecx,[esp+0x18]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esp+0xec],0x1
    call    R6GameServiceAddresses::CopyIndexedBytesExact
    test    al,al
    jne    Branch42
    mov    ecx,DWORD PTR [esi+0x14]
    lea    edx,[esp+0x10]
    push    0x0
    push    edx
    call    R6GameServiceAddresses::ReadIndexedWord
    mov    al,BYTE PTR [esp+0x10]
    mov    BYTE PTR [esp+0x14],al
  Branch42:
    mov    edx,DWORD PTR [esp+0x14]
    lea    ecx,[esp+0x58]
    push    ecx
    push    edx
    mov    ecx,esi
    call    R6GameServiceAddresses::FormatByteLabel
    lea    eax,[esp+0x58]
    push    eax
    push    R6GameServiceAddresses::TextS3
    call    R6GameServiceAddresses::printf
    add    esp,0x8
    lea    ecx,[esp+0x18]
    push    0x1
    push    ecx
    mov    ecx,DWORD PTR [esi+0x14]
    call    R6GameServiceAddresses::CopyIndexedClDataList
    test    al,al
    je    Branch43
    lea    ecx,[esp+0x18]
    call    R6GameServiceAddresses::PrintClDataList
  Branch43:
    push    R6GameServiceAddresses::TextCloseBracketLine
    call    R6GameServiceAddresses::printf
    add    esp,0x4
    mov    DWORD PTR [esp+0x18],ebp
    mov    DWORD PTR [esp+0x24],edi
    mov    DWORD PTR [esp+0xe0],0x2
    lea    ecx,[esp+0x24]
  Branch44:
    call    R6GameServiceAddresses::DestroyClDataPointerList
  Branch45:
    mov    ecx,DWORD PTR [esp+0xd8]
    pop    edi
    pop    esi
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0xd4
    ret
  }
}

// Reset base vtable of inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 10069990 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResetBasePrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 1006999b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl DestroyPrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699a6 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699b1 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699bc : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList2(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699c7 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList3(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699d2 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList2(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699dd : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList4(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-b4; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699e8 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList5(void)
{
  __asm {
    lea    ecx,[ebp-0xb4]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699f3 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList6(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Destroy inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 100699fe : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_DestroyPrintedRecordList3(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::DestroyClDataListAlias
  }
}

// Reset base vtable of inherited list S-cc; preserve exact parent association and native tail target.
// R6GameService.dll @ 10069a09 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl clGSMessage_ResetBasePrintedRecordList7(void)
{
  __asm {
    lea    ecx,[ebp-0xcc]
    jmp    R6GameServiceAddresses::ResetClDataVtable
  }
}

// Select literal twelve-state print cleanup FuncInfo and tail shared C++ frame handler.
// R6GameService.dll @ 10069a14 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl PrintedRecordExceptionHandler(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::PrintDecodedRecordExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native print-list cleanup map/FuncInfo.
// R6GameService.dll data @ 10084450 : native storage identity retained.
const R6GameServiceNative::UnwindEntry PrintDecodedRecordUnwindMap[12] = {
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList6},
  {-1, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList3},
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList7},
  {-1, R6GameServiceAddresses::ResetBasePrintedRecordList},
  {-1, R6GameServiceAddresses::DestroyPrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList2},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList3},
  {0x4, R6GameServiceAddresses::clGSMessage_DestroyPrintedRecordList2},
  {0x4, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList4},
  {-1, R6GameServiceAddresses::clGSMessage_ResetBasePrintedRecordList5},
};

// Literal native print-list cleanup map/FuncInfo.
// R6GameService.dll data @ 100844b0 : native storage identity retained.
const R6GameServiceNative::FuncInfo PrintDecodedRecordExceptionInfo = {
  0x19930520,
  0xc,
  R6GameServiceAddresses::PrintDecodedRecordUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Native virtual-table prefix: clGSMessageVTable
// R6GameService.dll data @ 1007819c : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct clGSMessageVTableRecord {
  R6GameServiceNative::Address DeleteClGSMessage; // +0x00
  R6GameServiceNative::Address SerializePayloadRecord; // +0x04
  R6GameServiceNative::Address AppendDecodedRecordText; // +0x08
  R6GameServiceNative::Address PrintDecodedRecord; // +0x0c
  R6GameServiceNative::Address DecodePayloadRecord; // +0x10
  R6GameServiceNative::Address EncodeMessagePayload; // +0x14
  R6GameServiceNative::Address DecodeMessagePayload; // +0x18
};
const clGSMessageVTableRecord clGSMessageVTable = {
  R6GameServiceAddresses::DeleteClGSMessage,
  R6GameServiceAddresses::SerializePayloadRecord,
  R6GameServiceAddresses::AppendDecodedRecordText,
  R6GameServiceAddresses::PrintDecodedRecord,
  R6GameServiceAddresses::DecodePayloadRecord,
  R6GameServiceAddresses::EncodeMessagePayload,
  R6GameServiceAddresses::DecodeMessagePayload,
};
