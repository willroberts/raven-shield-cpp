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
void __stdcall DestroyStdStringRange(std::basic_string<char> *first,std::basic_string<char> *last)
{
  uint cursor = (uint)first;
  uint end = (uint)last;
  using DestroyABI = void (__thiscall *)(void *);
  while (cursor != end) {
    (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)cursor);
    cursor += 0x1c;
  }
}

// Destroys the cached narrow-string range, frees current begin and clears storage fields only after cleanup succeeds.
// R6GameService.dll @ 100346c0 : complete native control/access order and raw ABI retained.
void __fastcall DestroyStringVector(void *vector)
{
  uint owner = (uint)vector;
  uint cursor = *(uint *)(owner + 4);
  if (cursor != 0) {
    uint end = *(uint *)(owner + 8);
    using DestroyABI = void (__thiscall *)(void *);
    while (cursor != end) {
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)cursor);
      cursor += 0x1c;
    }
    void *storage = *(void **)(owner + 4);
    FreeThroughGlobalAllocator(storage);
  }
  *(uint *)(owner + 4) = 0;
  *(uint *)(owner + 8) = 0;
  *(uint *)(owner + 0xc) = 0;
}

// Tail-forwards narrow-string vector destruction to the one shared native body.
// R6GameService.dll @ 10034880 : complete native control/access order and raw ABI retained.
void __fastcall DestroyStringVectorThunk(void *vector)
{
  DestroyStringVector(vector);
}

// Assigns the same live string value across a cached half-open destination range.
// R6GameService.dll @ 10035dd0 : complete native control/access order and raw ABI retained.
void __cdecl AssignStdStringRange(std::basic_string<char> *first,std::basic_string<char> *last,
                                 const std::basic_string<char> *value)
{
  uint cursor = (uint)first;
  uint end = (uint)last;
  if (cursor == end) return;
  const void *fill = value;
  using AssignABI = void *(__thiscall *)(void *,const void *);
  do {
    (*(AssignABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot)((void *)cursor,fill);
    cursor += 0x1c;
  } while (cursor != end);
}

// Assigns strings backwards through current imported assignment and returns the final destination cursor.
// R6GameService.dll @ 10035e00 : complete native control/access order and raw ABI retained.
std::basic_string<char> *__cdecl CopyStdStringsBackward(const std::basic_string<char> *first,
    const std::basic_string<char> *last,std::basic_string<char> *destinationEnd)
{
  uint begin = (uint)first;
  uint source = (uint)last;
  if (begin == source) return destinationEnd;
  uint destination = (uint)destinationEnd;
  using AssignABI = void *(__thiscall *)(void *,const void *);
  do {
    source -= 0x1c;
    destination -= 0x1c;
    (*(AssignABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_4_basic_stringSlot)(
        (void *)destination,(const void *)source);
  } while (source != begin);
  return (std::basic_string<char> *)destination;
}

// Copy-constructs a source range, publishing progress in caller slots for its separate cleanup catch.
// R6GameService.dll @ 10035e40 : complete native control/access order and raw ABI retained.
std::basic_string<char> *__cdecl ConstructStdStringRange(const std::basic_string<char> *first,
    const std::basic_string<char> *last,std::basic_string<char> *destination)
{
  uint current = (uint)destination;
  uint initial = current;
  uint source = (uint)first;
  using ConstructABI = void *(__thiscall *)(void *,const void *);
  try {
    while (source != (uint)last) {
      first = (const std::basic_string<char> *)current;
      if (current != 0) {
        (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2)(
            (void *)current,(const void *)source);
      }
      current += 0x1c;
      destination = (std::basic_string<char> *)current;
      source += 0x1c;
    }
  } catch (...) {
    uint cursor = initial;
    uint completedEnd = (uint)destination;
    using DestroyABI = void (__thiscall *)(void *);
    while (cursor != completedEnd) {
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)cursor);
      cursor += 0x1c;
    }
    throw;
  }
  return (std::basic_string<char> *)current;
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
void __cdecl ConstructRepeatedStdStrings(std::basic_string<char> *destination,uint count,
                                        const std::basic_string<char> *value)
{
  uint current = (uint)destination;
  uint remaining = count;
  uint initial = current;
  using ConstructABI = void *(__thiscall *)(void *,const void *);
  try {
    while (remaining != 0) {
      count = current;
      if (current != 0) {
        const void *fill = value;
        (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2)(
            (void *)current,fill);
      }
      --remaining;
      current += 0x1c;
      destination = (std::basic_string<char> *)current;
    }
  } catch (...) {
    uint cursor = initial;
    uint completedEnd = (uint)destination;
    using DestroyABI = void (__thiscall *)(void *);
    while (cursor != completedEnd) {
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)((void *)cursor);
      cursor += 0x1c;
    }
    throw;
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
std::basic_string<char> *__thiscall ConstructRepeatedStdStringRange(void *unusedReceiver,
    std::basic_string<char> *destination,uint count,const std::basic_string<char> *value)
{
  uint ignoredValue = (uint)value;
  uint size = count;
  uint begin = (uint)destination;
  using ConstructABI = void (__cdecl *)(std::basic_string<char> *,uint,const std::basic_string<char> *,uint,uint);
  ((ConstructABI)R6GameServiceAddresses::ConstructRepeatedStdStrings)(
      (std::basic_string<char> *)begin,size,value,(uint)unusedReceiver,ignoredValue);
  return (std::basic_string<char> *)(begin + size * 0x1c);
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
int __fastcall GetStringVectorElementCount(void *vector)
{
  uint owner = (uint)vector;
  uint begin = *(uint *)(owner + 4);
  if (begin == 0) return 0;
  uint end = *(uint *)(owner + 8);
  int span = (int)(end - begin);
  return span / 0x1c;
}

// Inferred guard for the constructed 28-byte CRT temporary; normal destruction disarms it before the call.
struct StringInsertionValueCleanup {
  void *value;
  bool armed;
  ~StringInsertionValueCleanup() noexcept(false) {
    if (armed) {
      using DestroyABI = void (__thiscall *)(void *);
      (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)(value);
    }
  }
};

// Preserves the fill string and inserts repeated elements through native growth or either in-place construction path.
// R6GameService.dll @ 10035ff0 : complete native control/access order and raw ABI retained.
void __thiscall InsertRepeatedStdStringsAtPosition(void *vector,std::basic_string<char> *insertPosition,
                                                uint copyCount,const std::basic_string<char> *value)
{
  uint owner = (uint)vector;
  uint savedValue[7];
  StringInsertionValueCleanup cleanup{savedValue, false};
  using ConstructABI = void *(__thiscall *)(void *,const void *);
  (*(ConstructABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Construct_basic_stringSlot2)(savedValue,value);
  uint firstBegin = *(uint *)(owner + 4);
  cleanup.armed = true;
  uint capacity = firstBegin == 0 ? 0 : (uint)((int)(*(uint *)(owner + 0xc) - firstBegin) / 0x1c);
  uint insertionCount = copyCount;
  using RangeABI = std::basic_string<char> *(__cdecl *)(const std::basic_string<char> *,
      const std::basic_string<char> *,std::basic_string<char> *,uint,uint);
  using RepeatABI = void (__cdecl *)(std::basic_string<char> *,uint,const std::basic_string<char> *,uint,uint);
  if (insertionCount != 0) {
    uint size = 0;
    if (firstBegin != 0) {
      uint begin = *(uint *)(owner + 4);
      uint end = *(uint *)(owner + 8);
      size = (uint)((int)(end - begin) / 0x1c);
    }
    if (insertionCount > 0x9249249u - size) ThrowVectorLengthException();
    uint begin = *(uint *)(owner + 4);
    size = 0;
    if (begin != 0) {
      begin = *(uint *)(owner + 4);
      uint end = *(uint *)(owner + 8);
      size = (uint)((int)(end - begin) / 0x1c);
    }
    if (capacity < size + insertionCount) {
      uint half = capacity >> 1;
      capacity = capacity > 0x9249249u - half ? 0 : capacity + half;
      begin = *(uint *)(owner + 4);
      size = 0;
      if (begin != 0) {
        begin = *(uint *)(owner + 4);
        uint end = *(uint *)(owner + 8);
        size = (uint)((int)(end - begin) / 0x1c);
      }
      if (capacity < size + insertionCount) capacity = (uint)GetStringVectorElementCount(vector) + insertionCount;
      copyCount = capacity * 0x1c;
      uint allocation = (uint)AllocateTaggedBytesCdecl(copyCount);
      uint ignoredPosition = (uint)insertPosition;
      uint prefixEnd = (uint)insertPosition;
      uint prefixBegin = *(uint *)(owner + 4);
      uint completedEnd = allocation;
      try {
        std::basic_string<char> *prefixResult = ((RangeABI)R6GameServiceAddresses::ConstructStdStringRange)(
            (const std::basic_string<char> *)prefixBegin,(const std::basic_string<char> *)prefixEnd,
            (std::basic_string<char> *)allocation,owner,ignoredPosition);
        ignoredPosition = (uint)insertPosition;
        completedEnd = (uint)prefixResult;
        ((RepeatABI)R6GameServiceAddresses::ConstructRepeatedStdStrings)(
            prefixResult,insertionCount,(const std::basic_string<char> *)savedValue,owner,ignoredPosition);
        ignoredPosition = (uint)insertPosition;
        completedEnd += insertionCount * 0x1c;
        uint suffixEnd = *(uint *)(owner + 8);
        uint suffixBegin = (uint)insertPosition;
        ((RangeABI)R6GameServiceAddresses::ConstructStdStringRange)(
            (const std::basic_string<char> *)suffixBegin,(const std::basic_string<char> *)suffixEnd,
            (std::basic_string<char> *)completedEnd,owner,ignoredPosition);
      } catch (...) {
        uint failedAllocation = allocation;
        DestroyStdStringRange((std::basic_string<char> *)failedAllocation,(std::basic_string<char> *)completedEnd);
        FreeThroughGlobalAllocator((void *)failedAllocation);
        throw;
      }
      begin = *(uint *)(owner + 4);
      size = begin == 0 ? 0 : (uint)((int)(*(uint *)(owner + 8) - begin) / 0x1c);
      uint newSize = insertionCount + size;
      begin = *(uint *)(owner + 4);
      if (begin != 0) {
        uint end = *(uint *)(owner + 8);
        DestroyStdStringRange((std::basic_string<char> *)begin,(std::basic_string<char> *)end);
        void *storage = *(void **)(owner + 4);
        FreeThroughGlobalAllocator(storage);
      }
      uint bytes = copyCount;
      *(uint *)(owner + 0xc) = allocation + bytes;
      *(uint *)(owner + 8) = allocation + newSize * 0x1c;
      *(uint *)(owner + 4) = allocation;
    } else {
      uint oldEnd = *(uint *)(owner + 8);
      uint selectedPosition = (uint)insertPosition;
      uint tailBytes = oldEnd - selectedPosition;
      value = (const std::basic_string<char> *)tailBytes;
      uint tailCount = (uint)((int)tailBytes / 0x1c);
      if (tailCount < insertionCount) {
        uint ignoredPosition = (uint)insertPosition;
        uint insertionBytes = insertionCount * 0x1c;
        value = (const std::basic_string<char> *)insertionBytes;
        ((RangeABI)R6GameServiceAddresses::ConstructStdStringRange)(
            (const std::basic_string<char> *)selectedPosition,(const std::basic_string<char> *)oldEnd,
            (std::basic_string<char> *)(selectedPosition + insertionBytes),owner,ignoredPosition);
        uint currentEnd = *(uint *)(owner + 8);
        uint span = currentEnd - selectedPosition;
        uint fillDestination = *(uint *)(owner + 8);
        uint missing = insertionCount - (uint)((int)span / 0x1c);
        uint gapEnd;
        try {
          ConstructRepeatedStdStringRange(vector,(std::basic_string<char> *)fillDestination,missing,
                                          (const std::basic_string<char> *)savedValue);
          currentEnd = *(uint *)(owner + 8);
          uint bytes = (uint)value;
          currentEnd += bytes;
          *(uint *)(owner + 8) = currentEnd;
          gapEnd = currentEnd - bytes;
        } catch (...) {
          uint bytes = copyCount * 0x1c;
          uint end = *(uint *)(owner + 8) + bytes;
          uint first = (uint)insertPosition + bytes;
          DestroyStdStringRange((std::basic_string<char> *)first,(std::basic_string<char> *)end);
          throw;
        }
        AssignStdStringRange((std::basic_string<char> *)selectedPosition,(std::basic_string<char> *)gapEnd,
                             (const std::basic_string<char> *)savedValue);
      } else {
        uint insertionBytes = insertionCount * 0x1c;
        uint source = oldEnd - insertionBytes;
        insertPosition = (std::basic_string<char> *)source;
        uint ignoredPosition = (uint)insertPosition;
        std::basic_string<char> *newEnd = ((RangeABI)R6GameServiceAddresses::ConstructStdStringRange)(
            (const std::basic_string<char> *)source,(const std::basic_string<char> *)oldEnd,
            (std::basic_string<char> *)oldEnd,owner,ignoredPosition);
        uint sourceEnd = (uint)insertPosition;
        *(uint *)(owner + 8) = (uint)newEnd;
        ignoredPosition = (uint)insertPosition;
        using BackwardABI = std::basic_string<char> *(__cdecl *)(const std::basic_string<char> *,
            const std::basic_string<char> *,std::basic_string<char> *,uint);
        ((BackwardABI)R6GameServiceAddresses::CopyStdStringsBackward)(
            (const std::basic_string<char> *)selectedPosition,(const std::basic_string<char> *)sourceEnd,
            (std::basic_string<char> *)oldEnd,ignoredPosition);
        AssignStdStringRange((std::basic_string<char> *)selectedPosition,
                             (std::basic_string<char> *)(selectedPosition + insertionBytes),
                             (const std::basic_string<char> *)savedValue);
      }
    }
  }
  cleanup.armed = false;
  using DestroyABI = void (__thiscall *)(void *);
  (*(DestroyABI *)R6GameServiceAddresses::MSVCP71_DU_char_traits_Destroy_basic_stringSlot)(savedValue);
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
uint *__thiscall InsertOneStdStringAndStoreIterator(void *vector,uint *resultIterator,
    std::basic_string<char> *insertPosition,const std::basic_string<char> *value)
{
  uint selectedPosition = (uint)insertPosition;
  uint owner = (uint)vector;
  uint begin = *(uint *)(owner + 4);
  uint index = 0;
  if (begin != 0) {
    uint end = *(uint *)(owner + 8);
    int size = (int)(end - begin) / 0x1c;
    insertPosition = (std::basic_string<char> *)(uint)size;
    if (size != 0) index = (uint)((int)(selectedPosition - begin) / 0x1c);
  }
  InsertRepeatedStdStringsAtPosition(vector,(std::basic_string<char> *)selectedPosition,1,value);
  uint offset = index * 0x1c;
  uint relocated = offset + *(uint *)(owner + 4);
  uint *savedResult = resultIterator;
  *savedResult = relocated;
  return savedResult;
}

// Appends directly into spare storage or inserts through an iterator result held in the original argument slot.
// R6GameService.dll @ 10036390 : complete native control/access order and raw ABI retained.
void __thiscall AppendStdStringToVector(void *vector,const std::basic_string<char> *value)
{
  uint owner = (uint)vector;
  uint begin = *(uint *)(owner + 4);
  uint size = begin == 0 ? 0 : (uint)((int)(*(uint *)(owner + 8) - begin) / 0x1c);
  if (begin != 0) {
    uint capacity = (uint)((int)(*(uint *)(owner + 0xc) - begin) / 0x1c);
    if (size < capacity) {
      uint ignoredValue = (uint)value;
      const std::basic_string<char> *fill = value;
      uint oldEnd = *(uint *)(owner + 8);
      using RepeatABI = void (__cdecl *)(std::basic_string<char> *,uint,const std::basic_string<char> *,uint,uint);
      ((RepeatABI)R6GameServiceAddresses::ConstructRepeatedStdStrings)(
          (std::basic_string<char> *)oldEnd,1,fill,owner,ignoredValue);
      *(uint *)(owner + 8) = oldEnd + 0x1c;
      return;
    }
  }
  const std::basic_string<char> *fill = value;
  uint end = *(uint *)(owner + 8);
  InsertOneStdStringAndStoreIterator(vector,(uint *)&value,(std::basic_string<char> *)end,fill);
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
