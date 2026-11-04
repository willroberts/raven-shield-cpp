#include "native_addresses.h"
#include "native_records.h"

// Shared twelve-byte owned records and ring/vector resize helpers; whole-container and record class names unresolved.

// Retain the current three-word fill snapshot until its final object deletion is entered.
struct OwnedRecordSnapshotCleanup {
  uint *record;
  bool armed;
  // A failed in-place shift/fill destroys only the snapshot object, with no vector rollback.
  ~OwnedRecordSnapshotCleanup() noexcept(false)
  {
    if (armed) {
      using DestroyABI = uint (__fastcall *)(void *);
      ((DestroyABI)R6GameServiceAddresses::DestroyOwnedRecordObject)(record);
    }
  }
};

// Inferred array-resize slots at entry ESP-2c; cookie-29, cached end-28, outer fill-24 and snapshot-18.
struct OwnedRecordArrayLocals {
  byte padding[3];
  byte cookie;
  uint oldEnd;
  uint fill[3];
  uint snapshot[3];
};

// Reject initial lowWORD>7ffe; otherwise clear five WORDs, delete old records and publish returned begin as end.
// Reload CURRENT full count after deletion, store lowWORD/+doubledWORD and fill twice-lowWORD slots in place or reallocate.
// ENTRY ESP S: fillS-24/inner fillS-18/cached old endS-28/cookieS-29/stateS-4; caller countS+4 is reused as scratch.
// Preserve magic signed division, current vector fields, temporary disarm order, raw upper EAX/AL1 and RET4; no vector rollback.
// R6GameService.dll @ 1005eeb0 : ECX receiver, one native stack word, RET4; two nested snapshot lifetimes.
uint __thiscall ResizeOwnedRecordArray(void *owner,uint requestedWord)
{
  uint entryRegistration = (uint)ExceptionList;
  uint base = (uint)owner;
  if ((ushort)requestedWord > 0x7ffe) {
    [[r6abi::register_output("ecx")]] uint restoredExceptionList = entryRegistration;
    return entryRegistration & 0xffffff00;
  }
  OwnedRecordArrayLocals frame;
  OwnedRecordSnapshotCleanup outerCleanup{frame.fill,false};
  byte tag = (byte)requestedWord;
  uint vector = base + 0x10;
  *(ushort *)(base + 4) = 0;
  *(ushort *)(base + 6) = 0;
  *(ushort *)(base + 8) = 0;
  *(ushort *)(base + 0xa) = 0;
  *(ushort *)(base + 0xc) = 0;
  uint oldBegin = *(uint *)vector;
  uint oldEnd = *(uint *)(vector + 4);
  frame.cookie = tag;
  uint returned = (uint)AssignOwnedRecordsForward((int *)oldEnd,(int *)oldEnd,(int *)oldBegin,
                                                 (uint)&frame.cookie,0);
  oldEnd = *(uint *)(vector + 4);
  frame.oldEnd = oldEnd;
  uint cursor = returned;
  if (cursor != oldEnd) {
    do {
      DeleteOwnedObjectRecord((void *)cursor,0);
      oldEnd = frame.oldEnd;
      cursor += 12;
    } while (cursor != oldEnd);
  }
  uint currentCount = requestedWord;
  *(uint *)(vector + 4) = returned;
  *(ushort *)(base + 4) = (ushort)currentCount;
  uint doubled = currentCount * 2;
  frame.fill[0] = 0;
  *(ushort *)(base + 6) = (ushort)doubled;
  frame.fill[1] = 0;
  frame.fill[2] = 0;
  uint position = *(uint *)(base + 0x14);
  doubled &= 0xffff;
  outerCleanup.armed = true;
  uint result = doubled;
  if (doubled != 0) {
    uint currentEnd = *(uint *)(vector + 4);
    uint capacityEnd = *(uint *)(vector + 8);
    uint spare = (uint)((int)(capacityEnd - currentEnd) / 12);
    if (spare < doubled) {
      result = ReallocateAndInsertOwnedRecords((void *)vector,(void *)position,frame.fill,
                                               &requestedWord,doubled,0);
    } else {
      frame.snapshot[0] = 0;
      frame.snapshot[1] = 0;
      frame.snapshot[2] = 0;
      uint suffix = (uint)((int)(currentEnd - position) / 12);
      uint oldCurrentEnd = *(uint *)(vector + 4);
      OwnedRecordSnapshotCleanup innerCleanup{frame.snapshot,true};
      if (suffix > doubled) {
        uint insertedBytes = doubled * 12;
        uint duplicateStart = oldCurrentEnd - insertedBytes;
        frame.oldEnd = duplicateStart;
        CopyRawRecordRange((uint *)duplicateStart,(uint *)oldCurrentEnd,(uint *)oldCurrentEnd,&requestedWord);
        uint publishedEnd = *(uint *)(vector + 4) + insertedBytes;
        uint retainedDuplicate = frame.oldEnd;
        byte currentTag = (byte)requestedWord;
        *(uint *)(vector + 4) = publishedEnd;
        *(byte *)&requestedWord = currentTag;
        result = (uint)AssignOwnedRecordsBackward((uint *)position,(uint *)retainedDuplicate,
                                                  (uint *)oldCurrentEnd,(uint)&requestedWord,0);
        result = AssignOwnedRecordFill((uint *)position,(uint *)(position + insertedBytes),frame.snapshot,result);
      } else {
        uint extra = doubled - suffix;
        requestedWord = extra;
        ForwardRepeatedRecordFill((uint *)oldCurrentEnd,extra,frame.snapshot);
        uint currentExtra = requestedWord;
        uint publishedEnd = *(uint *)(vector + 4) + currentExtra * 12;
        *(uint *)(vector + 4) = publishedEnd;
        CopyRawRecordRange((uint *)position,(uint *)oldCurrentEnd,(uint *)publishedEnd,&requestedWord);
        uint suffixBytes = suffix * 12;
        uint finalEnd = *(uint *)(vector + 4) + suffixBytes;
        *(uint *)(vector + 4) = finalEnd;
        result = AssignOwnedRecordFill((uint *)position,(uint *)oldCurrentEnd,frame.snapshot,suffixBytes);
      }
      innerCleanup.armed = false;
      result = DestroyOwnedRecordObject(frame.snapshot,result);
    }
  }
  uint object = frame.fill[0];
  outerCleanup.armed = false;
  if (object != 0) {
    uint table = *(uint *)object;
    using DeleteABI = uint (__thiscall *)(void *,uint);
    result = (*(DeleteABI *)table)((void *)object,1);
  }
  [[r6abi::register_output("ecx")]] uint restoredExceptionList = entryRegistration;
  return (result & 0xffffff00) | 1;
}

// Inferred physical ring-reset slots at entry ESP-0x24: cookie-0x21, cached end-0x20, begin-0x1c and fill-0x18.
struct OwnedRecordRingLocals {
  byte padding[3];
  byte cookie;
  uint oldEnd;
  uint returnedBegin;
  uint fill[3];
};

// Delete old records, insert twice the current low-word count, then derive the ring cursor from current WORD fields.
// Initial rejection checks only lowWORD; accepted zero can divide by zero with fill ownership still armed.
// R6GameService.dll @ 1005f0b0 : current full argument reload, RET4 and quotient/delete upper EAX with AL1.
uint __thiscall ResetOwnedRecordRing(void *owner,uint requestedWord)
{
  uint entryRegistration = (uint)ExceptionList;
  uint base = (uint)owner;
  if ((ushort)requestedWord > 0x7ffe) return entryRegistration & 0xffffff00;
  OwnedRecordRingLocals frame;
  OwnedRecordSnapshotCleanup cleanup{frame.fill,false};
  byte tag = (byte)requestedWord;
  uint vector = base + 0x10;
  *(ushort *)(base + 4) = 0;
  *(ushort *)(base + 6) = 0;
  *(ushort *)(base + 8) = 0;
  *(ushort *)(base + 0xa) = 0;
  *(ushort *)(base + 0xc) = 0;
  uint oldBegin = *(uint *)vector;
  uint oldEnd = *(uint *)(vector + 4);
  frame.cookie = tag;
  uint returned = (uint)AssignOwnedRecordsForward((int *)oldEnd,(int *)oldEnd,(int *)oldBegin,
                                                 (uint)&frame.cookie,0);
  oldEnd = *(uint *)(vector + 4);
  frame.returnedBegin = returned;
  frame.oldEnd = oldEnd;
  uint cursor = returned;
  if (cursor != oldEnd) {
    do {
      DeleteOwnedObjectRecord((void *)cursor,0);
      oldEnd = frame.oldEnd;
      cursor += 12;
    } while (cursor != oldEnd);
    returned = frame.returnedBegin;
  }
  uint currentCount = requestedWord;
  *(uint *)(vector + 4) = returned;
  *(ushort *)(base + 4) = (ushort)currentCount;
  frame.fill[0] = 0;
  uint doubled = currentCount * 2;
  frame.fill[1] = 0;
  *(ushort *)(base + 6) = (ushort)doubled;
  frame.fill[2] = 0;
  uint position = *(uint *)(base + 0x14);
  doubled &= 0xffff;
  cleanup.armed = true;
  InsertRepeatedOwnedRecords((void *)vector,(void *)position,doubled,frame.fill);
  uint cursorWord = *(ushort *)(base + 0xc);
  uint countWord = *(ushort *)(base + 4);
  uint numerator = cursorWord + countWord;
  uint divisor = *(ushort *)(base + 6);
  uint result = numerator / divisor;
  uint remainder = numerator - result * divisor;
  uint object = frame.fill[0];
  cleanup.armed = false;
  *(ushort *)(base + 0xa) = (ushort)remainder;
  if (object != 0) {
    uint table = *(uint *)object;
    using DeleteABI = uint (__thiscall *)(void *,uint);
    result = ((DeleteABI)*(uint *)table)((void *)object,1);
  }
  return (result & 0xffffff00) | 1;
}

// Delete CURRENT record DWORD0 object through CURRENT primary slot0/full1; NULL preserves incoming EAX.
// No field clearing or record storage release; receiver in ECX, no stack arguments.
// R6GameService.dll @ 1005ee10 : ECX/EAX view; native RET0, no stack arguments.
uint DestroyOwnedRecordObject([[r6abi::register_input("ecx")]] void *record,
    [[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  void *object = *(void **)record;
  if (object == nullptr) return eaxAtEntry;
  uint table = *(uint *)object;
  using DeleteABI = uint (__thiscall *)(void *,uint);
  return (*(DeleteABI *)table)(object,1);
}

// Delete CURRENT DWORD0 object, then inspect CURRENT flag bit0 and optionally CDECL-free cached record storage.
// Keep record words stale, return original receiver and RET4; no local EH or pending outer-storage guard.
// R6GameService.dll @ 1005fa80 : complete native control/access order and raw ABI retained.
void *__thiscall DeleteOwnedObjectRecord(void *record,uint deleteFlags)
{
  void *savedRecord = record;
  void *object = *(void **)savedRecord;
  if (object != 0) {
    using DeleteABI = void (__thiscall *)(void *,uint);
    DeleteABI destroy = *(DeleteABI *)*(void **)object;
    destroy(object,1);
  }
  if ((deleteFlags & 1) != 0) {
    using FreeABI = uint (__cdecl *)(void *);
    ((FreeABI)R6GameServiceAddresses::FreeThroughGlobalAllocator)(savedRecord);
  }
  return savedRecord;
}

// Assign signed(sourceEnd-sourceBegin)/12 records forward, deleting each destination object before source reads.
// Nonpositive count returns original destination; no ownership clearing/copy guard. Five full words/RET20.
// R6GameService.dll @ 1005f980 : inferred record view; wrapped signed distance divided by 12 toward zero.
int *__stdcall AssignOwnedRecordsForward(
    const int *sourceBegin,const int *sourceEnd,int *destination,uint unusedTag,uint unusedWord)
{
  uint first = (uint)sourceBegin;
  uint last = (uint)sourceEnd;
  int remaining = (int)(last - first) / 12;
  if (remaining <= 0) return destination;
  uint out = (uint)destination;
  do {
    void *object = *(void **)out;
    if (object != 0) {
      using DeleteABI = void (__thiscall *)(void *,uint);
      DeleteABI destroy = *(DeleteABI *)*(void **)object;
      destroy(object,1);
    }
    uint word = *(uint *)first;
    first += 12;
    *(uint *)out = word;
    word = *(uint *)(first - 8);
    *(uint *)(out + 4) = word;
    word = *(uint *)(first - 4);
    *(uint *)(out + 8) = word;
    out += 12;
    --remaining;
  } while (remaining != 0);
  return (int *)out;
}

// Clean CURRENT outer fill at inherited S-24; preserve raw NULL EAX.
// R6GameService.dll @ 10069c40 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResizeOwnedRecordArrayUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Clean CURRENT inner fill at inherited S-18, then outer state0.
// R6GameService.dll @ 10069c48 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ResizeOwnedRecordArrayUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Clean CURRENT ring/reset or insertion snapshot at inherited S-18.
// R6GameService.dll @ 10069c60 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportSharedLifetimeUnwind1(void)
{
  __asm {
    lea    ecx,[ebp-0x18]
    jmp    R6GameServiceAddresses::DestroyOwnedRecordObject
  }
}

// Select exact native fill-record cleanup FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c50 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectArrayResizeEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ResizeOwnedRecordArrayExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Select shared ring-reset/insertion fill cleanup FuncInfo and tail-dispatch CRT.
// R6GameService.dll @ 10069c68 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectRingResetEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::owned_record_array_supportSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846b0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ResizeOwnedRecordArrayUnwindMap[2] = {
  {-1, R6GameServiceAddresses::ResizeOwnedRecordArrayUnwind1},
  {0x0, R6GameServiceAddresses::ResizeOwnedRecordArrayUnwind2},
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846c0 : native storage identity retained.
const R6GameServiceNative::FuncInfo ResizeOwnedRecordArrayExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ResizeOwnedRecordArrayUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846dc : native storage identity retained.
const R6GameServiceNative::UnwindEntry owned_record_array_supportSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwind1},
};

// Literal native fill cleanup map/FuncInfo.
// R6GameService.dll data @ 100846e4 : native storage identity retained.
const R6GameServiceNative::FuncInfo owned_record_array_supportSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Insert repeated shallow record words, shifting backward or extending/filling the tail when capacity permits.
// Otherwise grow through f610. Preserve live argument scratch, snapshot ownership and the final raw register value.
// R6GameService.dll @ 1005f280 : full unsigned count, current vector accesses, RET12 and shared snapshot lifetime.
uint __thiscall InsertRepeatedOwnedRecords(void *container,void *position,uint count,const uint *fillRecord)
{
  uint result = (uint)ExceptionList;
  uint base = (uint)container;
  uint requested = count;
  if (requested == 0) return result;
  uint oldEnd = *(uint *)(base + 4);
  uint capacityEnd = *(uint *)(base + 8);
  uint available = (uint)((int)(capacityEnd - oldEnd) / 12);
  if (available < requested) {
    void *currentPosition = position;
    const uint *currentFill = fillRecord;
    return ReallocateAndInsertOwnedRecords((void *)base,currentPosition,currentFill,&position,requested,0);
  }
  const uint *value = fillRecord;
  uint snapshot[3];
  snapshot[0] = value[0];
  snapshot[1] = value[1];
  snapshot[2] = value[2];
  uint initialPosition = (uint)position;
  OwnedRecordSnapshotCleanup cleanup{snapshot,true};
  uint suffixDistance = oldEnd - initialPosition;
  uint suffix = (uint)((int)suffixDistance / 12);
  uint currentEnd = *(uint *)(base + 4);
  result = suffixDistance >> 31;
  if (suffix > requested) {
    uint bytes = requested * 12;
    uint tail = currentEnd - bytes;
    CopyRawRecordRange((uint *)tail,(uint *)currentEnd,(uint *)currentEnd,&fillRecord);
    uint publishedEnd = *(uint *)(base + 4) + bytes;
    *(uint *)(base + 4) = publishedEnd;
    uint currentPosition = (uint)position;
    uint shiftDistance = tail - currentPosition;
    int backwards = (int)shiftDistance / 12;
    result = shiftDistance >> 31;
    if (backwards > 0) {
      uint sourceWord2 = tail + 8;
      position = (void *)(uint)backwards;
      do {
        uint object = *(uint *)(currentEnd - 12);
        currentEnd -= 12;
        sourceWord2 -= 12;
        if (object != 0) {
          uint table = *(uint *)object;
          using DeleteABI = uint (__thiscall *)(void *,uint);
          ((DeleteABI)*(uint *)table)((void *)object,1);
        }
        uint word0 = *(uint *)(sourceWord2 - 8);
        *(uint *)currentEnd = word0;
        uint word1 = *(uint *)(sourceWord2 - 4);
        result = (uint)position;
        *(uint *)(currentEnd + 4) = word1;
        uint word2 = *(uint *)sourceWord2;
        --result;
        *(uint *)(currentEnd + 8) = word2;
        position = (void *)result;
      } while (result != 0);
    }
    uint fillEnd = currentPosition + bytes;
    uint cursor = currentPosition;
    while (cursor != fillEnd) {
      uint object = *(uint *)cursor;
      if (object != 0) {
        uint table = *(uint *)object;
        using DeleteABI = uint (__thiscall *)(void *,uint);
        ((DeleteABI)*(uint *)table)((void *)object,1);
      }
      uint word0 = snapshot[0];
      uint word1 = snapshot[1];
      result = snapshot[2];
      *(uint *)cursor = word0;
      *(uint *)(cursor + 4) = word1;
      *(uint *)(cursor + 8) = result;
      cursor += 12;
    }
  } else {
    byte tag = (byte)(uint)position;
    uint extra = requested - suffix;
    *(byte *)&fillRecord = tag;
    ConstructRepeatedRawRecords((uint *)currentEnd,extra,snapshot,&fillRecord);
    uint publishedEnd = *(uint *)(base + 4) + extra * 12;
    uint currentPosition = (uint)position;
    *(uint *)(base + 4) = publishedEnd;
    result = (uint)CopyRawRecordRange((uint *)currentPosition,(uint *)currentEnd,(uint *)publishedEnd,&position);
    uint newEnd = *(uint *)(base + 4) + suffix * 12;
    *(uint *)(base + 4) = newEnd;
    uint cursor = currentPosition;
    while (cursor != currentEnd) {
      uint object = *(uint *)cursor;
      if (object != 0) {
        uint table = *(uint *)object;
        using DeleteABI = uint (__thiscall *)(void *,uint);
        ((DeleteABI)*(uint *)table)((void *)object,1);
      }
      uint word0 = snapshot[0];
      uint word1 = snapshot[1];
      result = snapshot[2];
      *(uint *)cursor = word0;
      *(uint *)(cursor + 4) = word1;
      *(uint *)(cursor + 8) = result;
      cursor += 12;
    }
  }
  uint snapshotObject = snapshot[0];
  cleanup.armed = false;
  if (snapshotObject != 0) {
    uint table = *(uint *)snapshotObject;
    using DeleteABI = uint (__thiscall *)(void *,uint);
    result = ((DeleteABI)*(uint *)table)((void *)snapshotObject,1);
  }
  return result;
}

// Inferred physical growth slots at real frame EBP-0x18/-0x14; the first holds old size before allocation.
struct OwnedRecordGrowthLocals {
  uint allocation;
  uint completedEnd;
};

// Grow by oldSize+max(oldSize,count), copy prefix/fill/optional suffix, then delete old objects and publish storage.
// Copies remain shallow; only construction failures destroy the completed new range and free its captured allocation.
// R6GameService.dll @ 1005f610 : current argument/vector slots, modulo32 sizing and RET20/capacity EAX retained.
uint __thiscall ReallocateAndInsertOwnedRecords(
    void *container,void *position,const uint *fillRecord,void *unusedTag,uint count,uint suppressSuffixWord)
{
  OwnedRecordGrowthLocals frame;
  uint base = (uint)container;
  uint requested = count;
  uint oldEnd = *(uint *)(base + 4);
  uint oldBegin = *(uint *)base;
  uint oldSize = (uint)((int)(oldEnd - oldBegin) / 12);
  frame.allocation = oldSize;
  const uint *growthWord = &count;
  if (oldSize >= requested) growthWord = &frame.allocation;
  uint capacity = *growthWord + oldSize;
  uint allocation = (uint)AllocateGameServiceBytes(capacity * 12);
  uint prefixBegin = *(uint *)base;
  frame.allocation = allocation;
  frame.completedEnd = allocation;
  void *prefixEnd = position;
  uint oldRangeEnd;
  uint cursor;
  try {
    uint out = (uint)CopyRawRecordRange((uint *)prefixBegin,(uint *)prefixEnd,(uint *)allocation,
                                      (byte *)&count + 3);
    frame.completedEnd = out;
    if (requested == 1) {
      if (out != 0) {
        const uint *value = fillRecord;
        uint word = value[0];
        *(uint *)out = word;
        word = value[1];
        *(uint *)(out + 4) = word;
        word = value[2];
        *(uint *)(out + 8) = word;
      }
      out += 12;
      frame.completedEnd = out;
    } else {
      const uint *value = fillRecord;
      out = (uint)ConstructRepeatedRawRecords((uint *)out,requested,value,(byte *)&count + 3);
      frame.completedEnd = out;
    }
    if ((byte)suppressSuffixWord == 0) {
      uint suffixEnd = *(uint *)(base + 4);
      void *suffixBegin = position;
      out = (uint)CopyRawRecordRange((uint *)suffixBegin,(uint *)suffixEnd,(uint *)out,
                                    (byte *)&suppressSuffixWord + 3);
      frame.completedEnd = out;
    }
    oldRangeEnd = *(uint *)(base + 4);
    cursor = *(uint *)base;
  } catch (...) {
    uint begin = frame.allocation;
    uint end = frame.completedEnd;
    uint current = begin;
    while (current != end) {
      uint object = *(uint *)current;
      if (object != 0) {
        uint table = *(uint *)object;
        using DeleteABI = uint (__thiscall *)(void *,uint);
        ((DeleteABI)*(uint *)table)((void *)object,1);
      }
      current += 12;
    }
    TailFreeThroughGlobalAllocator((void *)begin);
    throw;
  }
  // Construction ownership is disarmed before the original count word becomes the live old-range end.
  count = oldRangeEnd;
  if (cursor != oldRangeEnd) {
    do {
      uint object = *(uint *)cursor;
      if (object != 0) {
        uint table = *(uint *)object;
        using DeleteABI = uint (__thiscall *)(void *,uint);
        ((DeleteABI)*(uint *)table)((void *)object,1);
        oldRangeEnd = count;
      }
      cursor += 12;
    } while (cursor != oldRangeEnd);
  }
  void *currentOldAllocation = *(void **)base;
  TailFreeThroughGlobalAllocator(currentOldAllocation);
  uint newBegin = frame.allocation;
  uint newEnd = frame.completedEnd;
  uint capacityBytes = capacity * 12;
  *(uint *)base = newBegin;
  *(uint *)(base + 4) = newEnd;
  uint newCapacity = newBegin + capacityBytes;
  *(uint *)(base + 8) = newCapacity;
  return newCapacity;
}

// Growth catch: cache completed new range from CURRENT parentP-18/P-14, delete its nonnull objects, free cached begin.
// Rethrow through CxxThrowException(NULL,NULL); no old-vector rollback or artificial return. Inherited parent EBP.
// R6GameService.dll @ 1005f737 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportCatch(void)
{
  __asm {
    mov    ebx,DWORD PTR [ebp-0x18]
    mov    edi,DWORD PTR [ebp-0x14]
    cmp    ebx,edi
    mov    esi,ebx
    je    Branch41
  Branch39:
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch40
    mov    edx,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [edx]
  Branch40:
    add    esi,0xc
    cmp    esi,edi
    jne    Branch39
  Branch41:
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
    push    0x0
    push    0x0
    call    R6GameServiceAddresses::_CxxThrowException
  }
}

// Copy three DWORDs per record forward to uninitialized storage; test current destination for NULL on EACH iteration.
// Advance and return destination/RET16 without deleting payloads or reading the tag. Overlap propagates writes.
// R6GameService.dll @ 1005f770 : inferred record view; modulo32 addresses and sequential DWORD accesses.
uint *__stdcall CopyRawRecordRange(uint *source,uint *sourceEnd,uint *destination,const void *unusedTag)
{
  uint first = (uint)source;
  uint last = (uint)sourceEnd;
  uint out = (uint)destination;
  while (first != last) {
    if (out != 0) {
      uint word = *(uint *)first;
      *(uint *)out = word;
      word = *(uint *)(first + 4);
      *(uint *)(out + 4) = word;
      word = *(uint *)(first + 8);
      *(uint *)(out + 8) = word;
    }
    first += 12;
    out += 12;
  }
  return (uint *)out;
}

// Repeat unsigned count records, reloading all value words per nonnull destination iteration.
// Count0 skips value/destination access; no ownership deletion or tag read. Return advanced destination/RET16.
// R6GameService.dll @ 1005f9e0 : inferred record view; modulo32 addresses and sequential DWORD accesses.
uint *__stdcall ConstructRepeatedRawRecords(
    uint *destination,uint count,const uint *value,const void *unusedTag)
{
  uint remaining = count;
  uint out = (uint)destination;
  if (remaining == 0) return (uint *)out;
  uint first = (uint)value;
  do {
    if (out != 0) {
      uint word = *(uint *)first;
      *(uint *)out = word;
      word = *(uint *)(first + 4);
      *(uint *)(out + 4) = word;
      word = *(uint *)(first + 8);
      *(uint *)(out + 8) = word;
    }
    out += 12;
    --remaining;
  } while (remaining != 0);
  return (uint *)out;
}

// Select growth two-state/no-action map plus catch-all construction handler, then tail CRT dispatch.
// R6GameService.dll @ 10069c90 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOwnedRecordGrowthEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084774 : native storage identity retained.
const R6GameServiceNative::UnwindEntry ReallocateAndInsertOwnedRecordsUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084784 : native storage identity retained.
const R6GameServiceNative::CatchHandler owned_record_array_supportGOwnedRecordGrowthEH[1] = {
  {0x0, 0x0, 0x0, R6GameServiceAddresses::owned_record_array_supportCatch},
};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 10084794 : native storage identity retained.
const R6GameServiceNative::TryBlock ReallocateAndInsertOwnedRecordsTryMap[1] = {
  {0x0, 0x0, 0x1, 0x1, R6GameServiceAddresses::owned_record_array_supportGOwnedRecordGrowthEH},
};

// Literal growth unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 100847a8 : native storage identity retained.
const R6GameServiceNative::FuncInfo ReallocateAndInsertOwnedRecordsExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsUnwindMap,
  0x1,
  R6GameServiceAddresses::ReallocateAndInsertOwnedRecordsTryMap,
  0x0,
  0x0,
};

// Assign fill forward: delete each CURRENT destination object, THEN reload three words through cached value pointer.
// Empty range preserves incoming EAX; nonempty returns last copied third word. No local EH/source clearing; RET12.
// R6GameService.dll @ 1005f7b0 : three native stack words and EAX input; RET12.
uint AssignOwnedRecordFill(uint *destination,uint *end,const uint *value,
    [[r6abi::register_input("eax")]] uint eaxAtEntry)
{
  uint *limit = end;
  uint *cursor = destination;
  uint result = eaxAtEntry;
  if (cursor == limit) return result;
  const uint *savedValue = value;
  do {
    void *object = *(void **)cursor;
    if (object != nullptr) {
      uint table = *(uint *)object;
      using DeleteABI = uint (__thiscall *)(void *,uint);
      (*(DeleteABI *)table)(object,1);
    }
    uint word0 = savedValue[0];
    cursor[0] = word0;
    uint word1 = savedValue[1];
    cursor[1] = word1;
    result = savedValue[2];
    cursor[2] = result;
    cursor = (uint *)((uint)cursor + 12);
  } while (cursor != limit);
  return result;
}

// Forwards the full count/value through raw fill with an unread tag holding the low byte of the value pointer.
// Native scratch restoration replaces volatile ECX's high byte with that tag; the returned fill end is unchanged.
// R6GameService.dll @ 1005f7f0 : stdcall three words; constructor-tag name is inferred, RET12.
uint *__stdcall ForwardRepeatedRecordFill(uint *destination,uint count,const uint *value)
{
  byte constructorTag = (byte)(uint)value;
  return ConstructRepeatedRawRecords(destination,count,value,&constructorTag);
}

// Assign signed(sourceEnd-sourceBegin)/12 records backward, deleting each destination object before source reads.
// A nonpositive count skips storage. Return retreated destination/RET20; extra arguments are unread.
// R6GameService.dll @ 1005fa20 : inferred record view; wrapped signed distance divided by 12 toward zero.
uint *__stdcall AssignOwnedRecordsBackward(
    const uint *sourceBegin,const uint *sourceEnd,uint *destinationEnd,uint unusedTag,uint unusedSelector)
{
  uint begin = (uint)sourceBegin;
  uint first = (uint)sourceEnd;
  int remaining = (int)(first - begin) / 12;
  if (remaining <= 0) return destinationEnd;
  uint out = (uint)destinationEnd;
  do {
    void *object = *(void **)(out - 12);
    out -= 12;
    first -= 12;
    if (object != 0) {
      using DeleteABI = void (__thiscall *)(void *,uint);
      DeleteABI destroy = *(DeleteABI *)*(void **)object;
      destroy(object,1);
    }
    uint word = *(uint *)first;
    --remaining;
    *(uint *)out = word;
    word = *(uint *)(first + 4);
    *(uint *)(out + 4) = word;
    word = *(uint *)(first + 8);
    *(uint *)(out + 8) = word;
  } while (remaining != 0);
  return (uint *)out;
}

namespace {
// Inferred view of the vector's saved context and state0 storage cleanup, armed through the final free.
struct OwnedRecordVectorStorageCleanup {
  void *savedVector;
  bool armed;
  // Release the current buffer without retrying payload deletion or clearing the vector fields.
  ~OwnedRecordVectorStorageCleanup() noexcept(false) {
    if (armed) {
      using ReleaseABI = uint (__thiscall *)(void *);
      ((ReleaseABI)R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer)(savedVector);
    }
  }
};
}

// Cache initial begin/end, delete nonnull record objects forward, then free CURRENT begin; leave vector fields stale.
// Cache bounds before arming storage cleanup; retain allocator EAX or zero when the final current buffer is null.
// R6GameService.dll @ 1005ecb0 : inferred vector view; saved context/state0 map to native S-10/S-4.
uint __fastcall DestroyOwnedRecordVector(void *vector)
{
  OwnedRecordVectorStorageCleanup cleanup{vector, false};
  uint end = *(uint *)((byte *)vector + 4);
  uint current = *(uint *)vector;
  cleanup.armed = true;
  while (current != end) {
    void *object = *(void **)current;
    if (object != 0) {
      using DeleteABI = void (__thiscall *)(void *,uint);
      DeleteABI destroy = *(DeleteABI *)*(void **)object;
      destroy(object,1);
    }
    current += 12;
  }
  void *buffer = *(void **)vector;
  uint result = 0;
  if (buffer != 0) {
    using FreeABI = uint (__stdcall *)(void *);
    result = ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(buffer);
  }
  cleanup.armed = false;
  return result;
}

// Same payload/storage lifetime for vector at owner+10, calling shared record cleanup for every slot.
// Save adjusted vector at S-10 for shared EH. NULL begin skips free without normalizing current EAX; no field clearing.
// R6GameService.dll @ 1005ee50 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall DestroyEmbeddedOwnedRecords(void *owner)
{
  __asm {
    push    0xffffffff
    push    R6GameServiceAddresses::SelectOwnedRecordVectorDestroyEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    push    ecx
    push    ebx
    lea    ebx,[ecx+0x10]
    push    esi
    push    edi
    mov    DWORD PTR [esp+0xc],ebx
    mov    edi,DWORD PTR [ebx+0x4]
    mov    esi,DWORD PTR [ebx]
    cmp    esi,edi
    mov    DWORD PTR [esp+0x18],0x0
    je    Branch59
  Branch58:
    mov    ecx,esi
    call    R6GameServiceAddresses::DestroyOwnedRecordObject
    add    esi,0xc
    cmp    esi,edi
    jne    Branch58
  Branch59:
    mov    ebx,DWORD PTR [ebx]
    test    ebx,ebx
    je    Branch60
    push    ebx
    call    R6GameServiceAddresses::TailFreeThroughGlobalAllocator
  Branch60:
    mov    ecx,DWORD PTR [esp+0x10]
    pop    edi
    pop    esi
    pop    ebx
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Free the current first-word buffer if nonnull; preserve the field and return allocator EAX or zero.
// R6GameService.dll @ 10061aa0 : complete native control/access order and raw ABI retained.
uint __fastcall ReleaseNonNullFirstWordBuffer(void *context)
{
  void *buffer = *(void **)context;
  if (buffer == 0) return 0;
  using FreeABI = uint (__stdcall *)(void *);
  return ((FreeABI)R6GameServiceAddresses::TailFreeThroughGlobalAllocator)(buffer);
}

// Shared standalone/embedded-vector state0 cleanup: free CURRENT first word through CURRENT saved contextS-10.
// Payload deletion is not retried; normal final free has not disarmed this state.
// R6GameService.dll @ 10069c00 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl owned_record_array_supportSharedLifetimeUnwind12(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    R6GameServiceAddresses::ReleaseNonNullFirstWordBuffer
  }
}

// Select exact shared standalone/embedded vector storage-release map and tail-dispatch CRT.
// R6GameService.dll @ 10069c08 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectOwnedRecordVectorDestroyEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::owned_record_array_supportSharedLifetimeExceptionInfo2
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal shared vector storage-cleanup map/FuncInfo.
// R6GameService.dll data @ 10084618 : native storage identity retained.
const R6GameServiceNative::UnwindEntry owned_record_array_supportSharedLifetimeUnwindMap2[1] = {
  {-1, R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwind12},
};

// Literal shared vector storage-cleanup map/FuncInfo.
// R6GameService.dll data @ 10084618 : native storage identity retained.
const R6GameServiceNative::FuncInfo owned_record_array_supportSharedLifetimeExceptionInfo2 = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::owned_record_array_supportSharedLifetimeUnwindMap2,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Tail-forward original ECX/registers/stack to embedded-vector destruction, retaining its raw EAX.
// R6GameService.dll @ 1005d110 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __fastcall thunk_DestroyEmbeddedOwnedRecords(void *owner)
{
  __asm {
    jmp    R6GameServiceAddresses::DestroyEmbeddedOwnedRecords
  }
}

// Test lowWORD index in current unsigned circular oldest+c/tail+a range, using modulus6 on the wrapped high portion.
// Return cached oldest/entry upper EAX with only AL status changed; RET4, no cursor/count effects.
// R6GameService.dll @ 1005f1d0 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall IsOwnerRecordIndexAccepted(void *ring,uint indexWord)
{
  __asm {
    mov    ax,WORD PTR [ecx+0xc]
    mov    dx,WORD PTR [ecx+0xa]
    cmp    ax,dx
    push    esi
    ja    Branch62
    mov    cx,WORD PTR [esp+0x8]
    cmp    cx,ax
    jb    Branch65
    cmp    cx,dx
    jmp    Branch64
  Branch62:
    mov    si,WORD PTR [esp+0x8]
    cmp    si,dx
    jae    Branch63
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch63:
    cmp    si,ax
    jb    Branch65
    cmp    si,WORD PTR [ecx+0x6]
  Branch64:
    jae    Branch65
    mov    al,0x1
    pop    esi
    ret    0x4
  Branch65:
    xor    al,al
    pop    esi
    ret    0x4
  }
}

// Publish current oldest slot payload to supplied output before NULL test; empty returns slot upper24/AL0 unchanged
// cursors.
// Nonnull clears slot, advances current oldest and tail modulo cached WORD6, stores oldest before second divide,
// returns quotient/AL1.
// Keep slot ancillary words/count untouched, modulo16 increments, output alias effects and RET4; no local EH.
// R6GameService.dll @ 1005f220 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall PopOwnedRingRecord(void *ring,void **result)
{
  __asm {
    mov    edx,DWORD PTR [ecx+0x10]
    xor    eax,eax
    mov    ax,WORD PTR [ecx+0xc]
    push    esi
    mov    esi,DWORD PTR [esp+0x8]
    lea    eax,[eax+eax*2]
    lea    eax,[edx+eax*4]
    mov    edx,DWORD PTR [eax]
    test    edx,edx
    mov    DWORD PTR [esi],edx
    jne    Branch66
    xor    al,al
    pop    esi
    ret    0x4
  Branch66:
    mov    DWORD PTR [eax],0x0
    mov    ax,WORD PTR [ecx+0xc]
    xor    esi,esi
    inc    ax
    mov    si,WORD PTR [ecx+0x6]
    and    eax,0xffff
    cdq
    idiv    esi
    mov    ax,WORD PTR [ecx+0xa]
    inc    ax
    and    eax,0xffff
    mov    WORD PTR [ecx+0xc],dx
    cdq
    idiv    esi
    mov    al,0x1
    pop    esi
    mov    WORD PTR [ecx+0xa],dx
    ret    0x4
  }
}

// Delete current old payload if nonnull, then reload original replacement argument; store zero4, new0, zero8 in
// native order.
// Preserve raw entry EAX when no old payload or deleting result otherwise; no local EH/rollback, RET4.
// R6GameService.dll @ 1005ee20 : complete native control/access order and raw ABI retained.
__declspec(naked) uint __thiscall ReplaceOwnedRecordObject(void *record,uint replacementWord)
{
  __asm {
    push    esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    test    ecx,ecx
    je    Branch67
    mov    eax,DWORD PTR [ecx]
    push    0x1
    call    DWORD PTR [eax]
  Branch67:
    mov    ecx,DWORD PTR [esp+0x8]
    mov    DWORD PTR [esi+0x4],0x0
    mov    DWORD PTR [esi],ecx
    mov    DWORD PTR [esi+0x8],0x0
    pop    esi
    ret    0x4
  }
}
