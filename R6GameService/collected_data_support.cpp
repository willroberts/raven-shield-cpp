#include "native_addresses.h"
#include "native_records.h"

// R6GameService.dll data @ 10080920 : completed result, collected strings and temporary bytes.
const R6GameServiceNative::UnwindEntry CollectedByteBuilderUnwindMap[3] = {
  {-1, R6GameServiceAddresses::ReleaseCollectedResultOnUnwind},
  {0, R6GameServiceAddresses::DestroyCollectedStringsOnUnwind},
  {1, R6GameServiceAddresses::ReleaseCollectedBytesOnUnwind},
};
// R6GameService.dll data @ 10080938 : three owned states, with no try/catch map.
const R6GameServiceNative::FuncInfo CollectedByteBuilderExceptionHandlerFunctionInfo = {
  0x19930520, 3, R6GameServiceAddresses::CollectedByteBuilderUnwindMap, 0, 0, 0, 0,
};
// R6GameService.dll data @ 10080c4c : aligned-frame query buffer and completed temporary string.
const R6GameServiceNative::UnwindEntry AdapterAddressCollectorUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ReleaseAdapterQueryBufferOnUnwind},
  {0, R6GameServiceAddresses::DestroyAdapterAddressStringOnUnwind},
};
// R6GameService.dll data @ 10080c5c : two owned states, with no try/catch map.
const R6GameServiceNative::FuncInfo AdapterAddressCollectorExceptionHandlerFunctionInfo = {
  0x19930520, 2, R6GameServiceAddresses::AdapterAddressCollectorUnwindMap, 0, 0, 0, 0,
};

// Collected-data byte construction; original free/helper identifiers and concrete vector templates remain inferred.

// Prints each collected string and copies its unterminated bytes into a separately owned result vector.
// R6GameService.dll @ 10034890 : C++ concatenation/lifetimes with native descriptor, result guard and scratch slots.
__declspec(naked) void * __cdecl BuildByteVectorFromCollectedStrings(void *outputVector)
{
  byte *nativeFrame;
  __asm {
    // ESP-based EH: result flag entryESP-30, strings-2c, temporary bytes-1c; opaque prefixes stay untouched.
    push   0xffffffff
    push   R6GameServiceAddresses::CollectedByteBuilderExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x28
    push   ebx
    push   ebp
    push   esi
    push   edi
    mov    nativeFrame,esp
  }
  using CollectABI = uint (__cdecl *)(void *);
  using PrintABI = int (__cdecl *)(const char *,...);
  using RangeErrorABI = void (__thiscall *)(const void *);
  using InsertABI = void (__thiscall *)(void *,uint,uint,const byte *);
  using CopyABI = void * (__thiscall *)(void *,const void *);
  using DestroyABI = void (__thiscall *)(void *);
  using FreeABI = void (__cdecl *)(void *);
  *(uint *)(nativeFrame + 0x14) = 0;
  *(uint *)(nativeFrame + 0x1c) = 0;
  *(uint *)(nativeFrame + 0x20) = 0;
  *(uint *)(nativeFrame + 0x24) = 0;
  *(uint *)(nativeFrame + 0x40) = 1;
  ((CollectABI)R6GameServiceAddresses::CollectNetworkAdapterMacAddresses)(nativeFrame + 0x18);
  uint cachedByteBegin = 0;
  *(uint *)(nativeFrame + 0x2c) = 0;
  *(uint *)(nativeFrame + 0x30) = 0;
  *(uint *)(nativeFrame + 0x34) = 0;
  uint stringsBegin = *(uint *)(nativeFrame + 0x1c);
  *(byte *)(nativeFrame + 0x40) = 2;
  *(uint *)(nativeFrame + 0x10) = 0;
  uint stringOffset = 0;
  for (;;) {
    if (stringsBegin == 0) break;
    int span = (int)(*(uint *)(nativeFrame + 0x20) - stringsBegin);
    uint stringCount = (uint)(span / 0x1c);
    if (*(uint *)(nativeFrame + 0x10) >= stringCount) break;
    byte *string = (byte *)(stringsBegin + stringOffset);
    const char *text = *(uint *)(string + 0x18) < 16 ? (const char *)(string + 4) : *(const char **)(string + 4);
    (*(PrintABI *)R6GameServiceAddresses::MSVCR71_printfSlot)
        ((const char *)R6GameServiceAddresses::TextS,text);
    stringsBegin = *(uint *)(nativeFrame + 0x1c);
    uint length = *(uint *)(stringsBegin + stringOffset + 0x14);
    uint characterIndex = 0;
    if (length != 0) {
      do {
        uint currentLength = *(uint *)(stringsBegin + stringOffset + 0x14);
        string = (byte *)(stringsBegin + stringOffset);
        if (characterIndex >= currentLength)
          (*(RangeErrorABI *)R6GameServiceAddresses::MSVCP71__String_base__XranSlot)(string);
        const byte *data = *(uint *)(string + 0x18) < 16 ? string + 4 : *(const byte **)(string + 4);
        const byte *source = (const byte *)((uint)data + characterIndex);
        uint end = *(uint *)(nativeFrame + 0x30);
        bool direct = false;
        if (cachedByteBegin != 0) {
          uint capacity = *(uint *)(nativeFrame + 0x34);
          direct = end - cachedByteBegin < capacity - cachedByteBegin;
        }
        if (direct) {
          *(byte *)end = *source;
          *(uint *)(nativeFrame + 0x30) = end + 1;
        } else {
          ((InsertABI)R6GameServiceAddresses::InsertRepeatedByte)(nativeFrame + 0x28,end,1,source);
          cachedByteBegin = *(uint *)(nativeFrame + 0x2c);
        }
        stringsBegin = *(uint *)(nativeFrame + 0x1c);
        length = *(uint *)(stringsBegin + stringOffset + 0x14);
        ++characterIndex;
      } while (characterIndex < length);
    }
    uint nextIndex = *(uint *)(nativeFrame + 0x10) + 1;
    stringOffset += 0x1c;
    *(uint *)(nativeFrame + 0x10) = nextIndex;
  }
  void *output = *(void **)(nativeFrame + 0x48);
  ((CopyABI)R6GameServiceAddresses::CopyByteVector)(output,nativeFrame + 0x28);
  *(uint *)(nativeFrame + 0x14) = 1;
  // A throwing normal free leaves state2 live; unwind may release temporary storage again.
  if (cachedByteBegin != 0) ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)cachedByteBegin);
  uint stringCursor = *(uint *)(nativeFrame + 0x1c);
  *(byte *)(nativeFrame + 0x40) = 0;
  if (stringCursor != 0) {
    uint stringEnd = *(uint *)(nativeFrame + 0x20);
    if (stringCursor != stringEnd) {
      do {
        (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)stringCursor);
        stringCursor += 0x1c;
      } while (stringCursor != stringEnd);
      stringCursor = *(uint *)(nativeFrame + 0x1c);
    }
    ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)stringCursor);
  }
  __asm {
    mov    ebp,output
    mov    ecx,DWORD PTR [esp+0x38]
    pop    edi
    pop    esi
    mov    eax,ebp
    pop    ebp
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x34
    ret
  }
}

// Destroys the builder parent-frame narrow-string vector through its shared cleanup thunk.
// R6GameService.dll @ 10066480 : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyCollectedStringsOnUnwind(void)
{
  __asm {
    // Inherited EBP denotes builder entryESP, not a frame created by this tail action.
    lea    ecx,[ebp-0x2c]
    jmp    R6GameServiceAddresses::DestroyStringVectorThunk
  }
}

// Releases and resets the builder parent-frame temporary byte vector.
// R6GameService.dll @ 10066488 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCollectedBytesOnUnwind(void)
{
  __asm {
    lea    ecx,[ebp-0x1c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Clears the completed-result guard before releasing the current hidden result pointer.
// R6GameService.dll @ 10066490 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseCollectedResultOnUnwind(void)
{
  __asm {
    // Guard bit0 is independent of state; clear it before loading current parent argument and entering cleanup.
    mov    eax,DWORD PTR [ebp-0x30]
    and    eax,0x1
    je     Branch16
    and    DWORD PTR [ebp-0x30],0xfffffffe
    mov    ecx,DWORD PTR [ebp+0x4]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  Branch16:
    ret
  }
}

// Selects the three-state builder unwind map for result, collected strings and temporary bytes.
// R6GameService.dll @ 100664a9 : complete native control/access order and raw ABI retained.
__declspec(naked) void CollectedByteBuilderExceptionHandler(void)
{
  __asm {
    // States own the conditional result, collected strings and temporary bytes, respectively.
    mov    eax,R6GameServiceAddresses::CollectedByteBuilderExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Appends uppercase adapter hardware-address strings and returns success only in AL, preserving upper EAX residue.
// R6GameService.dll @ 10036420 : C++ adapter formatting with aligned frame, unchecked text and raw AL result.
__declspec(naked) uint __cdecl CollectNetworkAdapterMacAddresses(void *stringVector)
{
  byte *nativeFrame;
  byte *originalFrame;
  __asm {
    // Keep original EBP for arguments and align ESP to 8. Unwind parent A is aligned pre-EH ESP, not original EBP.
    push   ebp
    mov    ebp,esp
    and    esp,0xfffffff8
    push   0xffffffff
    push   R6GameServiceAddresses::AdapterAddressCollectorExceptionHandler
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x150
    mov    eax,ds:R6GameServiceAddresses::GSecurityCookie
    push   ebx
    push   esi
    push   edi
    // Cookie at A-14; query size A-150, zero fill A-155, vector A-14c, string A-13c, text A-118.
    mov    DWORD PTR [esp+0x154],eax
    mov    nativeFrame,esp
    mov    originalFrame,ebp
  }
  using QueryABI = uint (__stdcall *)(void *,uint *);
  using FilledVectorABI = void (__thiscall *)(void *,uint,const byte *);
  using FormatABI = int (__cdecl *)(char *,const char *,...);
  using ConstructABI = void * (__thiscall *)(void *,const char *);
  using AppendABI = void (__thiscall *)(void *,const void *);
  using DestroyABI = void (__thiscall *)(void *);
  using FreeABI = uint (__cdecl *)(void *); // Preserve the void free boundary's raw EAX residue.
  *(uint *)(nativeFrame + 0x18) = 0;
  uint residue = ((QueryABI)R6GameServiceAddresses::GetAdaptersInfo)(nullptr,(uint *)(nativeFrame + 0x18));
  bool success = false;
  if (residue == 0 || residue == 0x6f) {
    uint required = *(uint *)(nativeFrame + 0x18);
    *(byte *)(nativeFrame + 0x13) = 0;
    ((FilledVectorABI)R6GameServiceAddresses::InitializeFilledByteVector)
        (nativeFrame + 0x1c,required,nativeFrame + 0x13);
    uint retainedBegin = *(uint *)(nativeFrame + 0x20);
    *(uint *)(nativeFrame + 0x164) = 0;
    residue = ((QueryABI)R6GameServiceAddresses::GetAdaptersInfo)((void *)retainedBegin,(uint *)(nativeFrame + 0x18));
    if (residue != 0) {
      if (retainedBegin != 0)
        residue = ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)retainedBegin);
    } else {
      uint adapter = retainedBegin;
      if (adapter != 0) {
        do {
          // Native unaligned zero stores preserve the scratch/text boundary and leave bytes +0x4e/+0x4f untouched.
          *(uint *)(nativeFrame + 0x49) = 0;
          *(byte *)(nativeFrame + 0x50) = 0;
          *(byte *)(nativeFrame + 0x4d) = 0;
          for (uint word = 0; word < 0x3f; ++word) *(uint *)(nativeFrame + 0x51 + word * 4) = 0;
          *(ushort *)(nativeFrame + 0x14d) = 0;
          *(byte *)(nativeFrame + 0x48) = 0;
          *(byte *)(nativeFrame + 0x14f) = 0;
          uint addressLength = *(uint *)(adapter + 0x190);
          *(uint *)(nativeFrame + 0x14) = 0;
          if (addressLength != 0) {
            for (;;) {
              uint index = *(uint *)(nativeFrame + 0x14);
              uint value = *(byte *)(adapter + index + 0x194);
              (*(FormatABI *)R6GameServiceAddresses::MSVCR71_sprintfSlot)
                  ((char *)(nativeFrame + 0x48),(const char *)R6GameServiceAddresses::Text2X,value);
              uint source = (uint)(nativeFrame + 0x48);
              uint scan = source;
              byte unit;
              do { unit = *(byte *)scan; ++scan; } while (unit != 0);
              uint count = scan - source;
              uint destination = (uint)(nativeFrame + 0x4f);
              do { unit = *(byte *)(destination + 1); ++destination; } while (unit != 0);
              // Copy forwards in native DWORD/byte groups, including the terminator; do not bound or repair overlap.
              for (uint words = count >> 2; words != 0; --words) {
                uint copied = *(uint *)source;
                *(uint *)destination = copied;
                source += 4;
                destination += 4;
              }
              index = *(uint *)(nativeFrame + 0x14);
              for (uint bytes = count & 3; bytes != 0; --bytes) {
                *(byte *)destination = *(byte *)source;
                ++source;
                ++destination;
              }
              addressLength = *(uint *)(adapter + 0x190);
              ++index;
              *(uint *)(nativeFrame + 0x14) = index;
              if (index >= addressLength) break;
            }
            // Empty addresses retain the earlier allocation pointer; only a completed formatting loop reloads it.
            retainedBegin = *(uint *)(nativeFrame + 0x20);
          }
          (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot)
              (nativeFrame + 0x2c,(const char *)(nativeFrame + 0x50));
          void *currentOutput = *(void **)(originalFrame + 8);
          *(byte *)(nativeFrame + 0x164) = 1;
          ((AppendABI)R6GameServiceAddresses::AppendStdStringToVector)(currentOutput,nativeFrame + 0x2c);
          *(byte *)(nativeFrame + 0x164) = 0;
          (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)(nativeFrame + 0x2c);
          adapter = *(uint *)adapter;
        } while (adapter != 0);
        residue = ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)retainedBegin);
      }
      success = true;
    }
  }
  uint output = (residue & 0xffffff00) | (success ? 1u : 0u);
  __asm {
    mov    eax,output
    mov    ecx,DWORD PTR [esp+0x15c]
    mov    DWORD PTR fs:0x0,ecx
    mov    ecx,DWORD PTR [esp+0x154]
    call   R6GameServiceAddresses::__security_check_cookie
    pop    edi
    pop    esi
    pop    ebx
    mov    esp,ebp
    pop    ebp
    ret
  }
}

// Tail-forwards the adapter buffer and size pointer through the selected GetAdaptersInfo import.
// R6GameService.dll @ 100371f4 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __stdcall GetAdaptersInfo(void *adapterInfo,uint *bufferSize)
{
  __asm {
    jmp    DWORD PTR ds:R6GameServiceAddresses::iphlpapi_GetAdaptersInfoSlot
  }
}

// Releases the collector aligned parent-frame byte-vector storage through shared cleanup.
// R6GameService.dll @ 10066690 : complete native control/access order and raw ABI retained.
__declspec(naked) void ReleaseAdapterQueryBufferOnUnwind(void)
{
  __asm {
    // Inherited EBP is aligned EH parent A: vector at A-14c, not original function EBP-14c.
    lea    ecx,[ebp-0x14c]
    jmp    R6GameServiceAddresses::ReleaseAndResetStorageAt04
  }
}

// Destroys the live collector address string using the current narrow CRT destructor import.
// R6GameService.dll @ 1006669b : complete native control/access order and raw ABI retained.
__declspec(naked) void DestroyAdapterAddressStringOnUnwind(void)
{
  __asm {
    // State 1 owns this temporary at aligned parent A-13c; current import target is retained.
    lea    ecx,[ebp-0x13c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot
  }
}

// Selects the collector two-state unwind map for its query buffer and temporary narrow string.
// R6GameService.dll @ 100666a7 : complete native control/access order and raw ABI retained.
__declspec(naked) void AdapterAddressCollectorExceptionHandler(void)
{
  __asm {
    // FuncInfo80c5c, map80c4c: state0 -> (-1,66690), state1 -> (0,6669b); no catches.
    mov    eax,R6GameServiceAddresses::AdapterAddressCollectorExceptionHandlerFunctionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
