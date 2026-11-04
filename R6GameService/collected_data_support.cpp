#include "native_addresses.h"
#include "native_import_bindings.h"
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

// Inferred guard for temporary bytes, strings and the conditional hidden result, in native unwind order.
struct CollectedByteBuilderCleanup {
  uint *bytes;
  uint *strings;
  uint *resultFlags;
  void **outputSlot;
  int state;
  ~CollectedByteBuilderCleanup() noexcept(false) {
    if (state >= 2) {
      state = 1;
      ReleaseAndResetStorageAt04((int)bytes);
    }
    if (state >= 1) {
      state = 0;
      DestroyStringVector(strings);
    }
    if (state < 0) return;
    state = -1;
    if ((*resultFlags & 1) != 0) {
      *resultFlags &= ~1u;
      void *output = *outputSlot;
      ReleaseAndResetStorageAt04((int)output);
    }
  }
};

// Prints each collected string and copies its unterminated bytes into a separately owned result vector.
// R6GameService.dll @ 10034890 : cdecl hidden result word; ownership follows three native cleanup states.
void *__cdecl BuildByteVectorFromCollectedStrings(void *outputVector)
{
  uint resultFlags = 0;
  uint strings[4],bytes[4];
  strings[1] = 0;
  strings[2] = 0;
  strings[3] = 0;
  CollectedByteBuilderCleanup cleanup{bytes, strings, &resultFlags, &outputVector, 1};
  using CollectABI = uint (__cdecl *)(void *);
  ((CollectABI)R6GameServiceAddresses::CollectNetworkAdapterMacAddresses)(strings);
  uint cachedByteBegin = 0;
  bytes[1] = 0;
  bytes[2] = 0;
  bytes[3] = 0;
  uint stringsBegin = strings[1];
  cleanup.state = 2;
  uint stringIndex = 0;
  uint stringOffset = 0;
  using PrintABI = int (__cdecl *)(const char *,...);
  using RangeErrorABI = void (__thiscall *)(const void *);
  using DestroyABI = void (__thiscall *)(void *);
  for (;;) {
    if (stringsBegin == 0) break;
    int span = (int)(strings[2] - stringsBegin);
    uint stringCount = (uint)(span / 0x1c);
    if (stringIndex >= stringCount) break;
    byte *string = (byte *)(stringsBegin + stringOffset);
    const char *text = *(uint *)(string + 0x18) < 16 ? (const char *)(string + 4) : *(const char **)(string + 4);
    (*(PrintABI *)R6GameServiceAddresses::MSVCR71_printfSlot)((const char *)R6GameServiceAddresses::TextS,text);
    stringsBegin = strings[1];
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
        uint end = bytes[2];
        bool direct = false;
        if (cachedByteBegin != 0) {
          uint capacity = bytes[3];
          direct = end - cachedByteBegin < capacity - cachedByteBegin;
        }
        if (direct) {
          *(byte *)end = *source;
          bytes[2] = end + 1;
        } else {
          InsertRepeatedByte(bytes,(byte *)end,1,source);
          cachedByteBegin = bytes[1];
        }
        stringsBegin = strings[1];
        length = *(uint *)(stringsBegin + stringOffset + 0x14);
        ++characterIndex;
      } while (characterIndex < length);
    }
    uint nextIndex = stringIndex + 1;
    stringOffset += 0x1c;
    stringIndex = nextIndex;
  }
  void *output = outputVector;
  CopyByteVector(output,bytes);
  resultFlags = 1;
  if (cachedByteBegin != 0) FreeThroughGlobalAllocator((void *)cachedByteBegin);
  uint stringCursor = strings[1];
  cleanup.state = 0;
  if (stringCursor != 0) {
    uint stringEnd = strings[2];
    if (stringCursor != stringEnd) {
      do {
        (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)stringCursor);
        stringCursor += 0x1c;
      } while (stringCursor != stringEnd);
      stringCursor = strings[1];
    }
    FreeThroughGlobalAllocator((void *)stringCursor);
  }
  cleanup.state = -1;
  return output;
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

// Inferred aligned-parent slots from A-158 through A-14; formatting scratch leaves its last two bytes untouched.
struct alignas(8) AdapterCollectionLocals {
  byte padding[3];
  byte zeroFill;
  uint index;
  uint required;
  uint bytes[4];
  uint addressString[7];
  byte scratch[8];
  byte text[256];
  uint opaque;
  uint cookie;
};

// Retain current vector storage and the completed address string; entered temporary destruction is never retried.
struct AdapterCollectionCleanup {
  AdapterCollectionLocals *frame;
  int state;
  bool armed;
  // The query buffer stays owned through normal free, allowing native current-storage cleanup if that free raises.
  ~AdapterCollectionCleanup() noexcept(false)
  {
    if (!armed) return;
    if (state == 1) {
      state = 0;
      using DestroyABI = void (__thiscall *)(void *);
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)(frame->addressString);
    }
    if (state == 0) {
      state = -1;
      ReleaseAndResetStorageAt04((int)frame->bytes);
    }
  }
};

// Query adapter storage, append each uppercase hardware-address string, then release the captured buffer.
// Preserve unchecked concatenation, live length/Next/output reads, selective begin reloads and raw result lanes.
// R6GameService.dll @ 10036420 : cdecl RET0; aligned physical local view, two-state ownership and current cookie exit.
uint __cdecl CollectNetworkAdapterMacAddresses(void *stringVector)
{
  AdapterCollectionLocals locals;
  locals.cookie = *(uint *)R6GameServiceAddresses::GSecurityCookie;
  AdapterCollectionCleanup cleanup{&locals,-1,true};
  using QueryABI = uint (__stdcall *)(void *,uint *);
  using FilledVectorABI = void (__thiscall *)(void *,uint,const byte *);
  using FormatABI = int (__cdecl *)(char *,const char *,...);
  using ConstructABI = void * (__thiscall *)(void *,const char *);
  using AppendABI = void (__thiscall *)(void *,const void *);
  using DestroyABI = void (__thiscall *)(void *);
  using FreeABI = uint (__cdecl *)(void *);
  locals.required = 0;
  uint residue = ((QueryABI)R6GameServiceAddresses::GetAdaptersInfo)(nullptr,&locals.required);
  bool success = false;
  if (residue == 0 || residue == 0x6f) {
    uint required = locals.required;
    locals.zeroFill = 0;
    ((FilledVectorABI)R6GameServiceAddresses::InitializeFilledByteVector)(locals.bytes,required,&locals.zeroFill);
    uint retainedBegin = locals.bytes[1];
    cleanup.state = 0;
    residue = ((QueryABI)R6GameServiceAddresses::GetAdaptersInfo)((void *)retainedBegin,&locals.required);
    if (residue != 0) {
      if (retainedBegin != 0)
        residue = ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)retainedBegin);
    } else {
      uint adapter = retainedBegin;
      if (adapter != 0) {
        do {
          *(uint *)(locals.scratch + 1) = 0;
          locals.text[0] = 0;
          locals.scratch[5] = 0;
          for (uint word = 0; word < 0x3f; ++word) *(uint *)(locals.text + 1 + word * 4) = 0;
          *(ushort *)(locals.text + 253) = 0;
          locals.scratch[0] = 0;
          locals.text[255] = 0;
          uint addressLength = *(uint *)(adapter + 0x190);
          locals.index = 0;
          if (addressLength != 0) {
            for (;;) {
              uint index = locals.index;
              uint value = *(byte *)(adapter + index + 0x194);
              (*(FormatABI *)R6GameServiceAddresses::MSVCR71_sprintfSlot)(
                  (char *)locals.scratch,(const char *)R6GameServiceAddresses::Text2X,value);
              uint source = (uint)locals.scratch;
              uint scan = source;
              byte unit;
              do { unit = *(byte *)scan; ++scan; } while (unit != 0);
              uint count = scan - source;
              uint destination = (uint)locals.text - 1;
              do { unit = *(byte *)(destination + 1); ++destination; } while (unit != 0);
              for (uint words = count >> 2; words != 0; --words) {
                uint copied = *(uint *)source;
                *(uint *)destination = copied;
                source += 4;
                destination += 4;
              }
              index = locals.index;
              for (uint bytes = count & 3; bytes != 0; --bytes) {
                *(byte *)destination = *(byte *)source;
                ++source;
                ++destination;
              }
              addressLength = *(uint *)(adapter + 0x190);
              ++index;
              locals.index = index;
              if (index >= addressLength) break;
            }
            retainedBegin = locals.bytes[1];
          }
          (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot)(
              locals.addressString,(const char *)locals.text);
          void *currentOutput = stringVector;
          cleanup.state = 1;
          ((AppendABI)R6GameServiceAddresses::AppendStdStringToVector)(currentOutput,locals.addressString);
          cleanup.state = 0;
          (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)(
              locals.addressString);
          adapter = *(uint *)adapter;
        } while (adapter != 0);
        residue = ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)((void *)retainedBegin);
      }
      success = true;
    }
  }
  uint output = (residue & 0xffffff00) | (success ? 1u : 0u);
  cleanup.armed = false;
  using CookieABI = void (__fastcall *)(uint);
  ((CookieABI)R6GameServiceAddresses::__security_check_cookie)(locals.cookie);
  return output;
}

namespace R6GameServiceImports {
// Bind the current import pointer directly; the native entry only jumps through this IAT cell.
// R6GameService.dll @ 100371f4 : six-byte compiler import tail; typed live-IAT representation.
GetAdaptersInfoFunction &GetAdaptersInfo{
  *reinterpret_cast<GetAdaptersInfoFunction *>(R6GameServiceAddresses::iphlpapi_GetAdaptersInfoSlot)
};
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
