#include "native_addresses.h"
#include "native_records.h"

// Selected package record identity: R6GameService.R6ServerList.stGameData.
// Generated C++ type/member spellings are unresolved; native helper names are descriptive, with no invented declaration.
// Selected layout: sizea4, strings24/30/44/50/5c/68/74/98, gameMapList80, PlayerList8c; flags0 mask3/14 mask7ff.
// R6GameService.dll data @ 1007afbc : predecessor/action pairs; state8 cleans arrays before the seven earlier strings.
const R6GameServiceNative::UnwindEntry stGameDataSharedLifetimeUnwindMap[9] = {
  {-1, R6GameServiceAddresses::UnwindGameDataName},
  {0, R6GameServiceAddresses::UnwindGameDataModName},
  {1, R6GameServiceAddresses::UnwindGameDataGameDataGameType},
  {2, R6GameServiceAddresses::UnwindGameDataGameType},
  {3, R6GameServiceAddresses::UnwindGameDataCurrentMap},
  {4, R6GameServiceAddresses::UnwindGameDataMessageOfDay},
  {5, R6GameServiceAddresses::UnwindGameDataGameVersion},
  {6, R6GameServiceAddresses::UnwindGameDataMapArray},
  {7, R6GameServiceAddresses::UnwindGameDataPlayerArray},
};
// R6GameService.dll data @ 1007b004 : shared by default/copy construction and destruction.
const R6GameServiceNative::FuncInfo stGameDataSharedLifetimeExceptionInfo = {
  0x19930520,
  9,
  R6GameServiceAddresses::stGameDataSharedLifetimeUnwindMap,
  0,
  0,
  0,
  0,
};

// Assigns game-data scalars, reflected flag bits, strings and both arrays in native order without a self guard.
// R6GameService.dll @ 10002dd0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall AssignSTGameData(void *destination,const void *source)
{
  __asm {
    // Flags0 preserve bits outside3; flags14 preserve bits outside7ff; source/receiver cached, source loads remain interleaved.
    push   esi
    mov    esi,ecx
    mov    ecx,DWORD PTR [esi]
    push   edi
    mov    edi,DWORD PTR [esp+0xc]
    mov    eax,DWORD PTR [edi]
    xor    eax,ecx
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [edi]
    xor    ecx,eax
    and    ecx,0x2
    xor    ecx,eax
    mov    DWORD PTR [esi],ecx
    mov    edx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi+0x8]
    mov    DWORD PTR [esi+0x8],eax
    mov    ecx,DWORD PTR [edi+0xc]
    mov    eax,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esi+0xc],ecx
    mov    edx,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],edx
    xor    eax,DWORD PTR [edi+0x14]
    mov    ecx,DWORD PTR [esi+0x14]
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x20
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x40
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x80
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x100
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x200
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x400
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    edx,DWORD PTR [edi+0x18]
    mov    DWORD PTR [esi+0x18],edx
    mov    eax,DWORD PTR [edi+0x1c]
    mov    DWORD PTR [esi+0x1c],eax
    mov    ecx,DWORD PTR [edi+0x20]
    lea    edx,[edi+0x24]
    mov    DWORD PTR [esi+0x20],ecx
    push   edx
    lea    ecx,[esi+0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    eax,[edi+0x30]
    push   eax
    lea    ecx,[esi+0x30]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    mov    ecx,DWORD PTR [edi+0x3c]
    mov    DWORD PTR [esi+0x3c],ecx
    mov    edx,DWORD PTR [edi+0x40]
    lea    eax,[edi+0x44]
    push   eax
    lea    ecx,[esi+0x44]
    mov    DWORD PTR [esi+0x40],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    ecx,[edi+0x50]
    push   ecx
    lea    ecx,[esi+0x50]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    edx,[edi+0x5c]
    push   edx
    lea    ecx,[esi+0x5c]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    eax,[edi+0x68]
    push   eax
    lea    ecx,[esi+0x68]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    ecx,[edi+0x74]
    push   ecx
    lea    ecx,[esi+0x74]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    lea    edx,[edi+0x80]
    push   edx
    lea    ecx,[esi+0x80]
    call   R6GameServiceAddresses::CopyStringPairArray18
    lea    eax,[edi+0x8c]
    push   eax
    lea    ecx,[esi+0x8c]
    call   R6GameServiceAddresses::CopyStringRecordArray2C
    add    edi,0x98
    push   edi
    lea    ecx,[esi+0x98]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    pop    edi
    mov    eax,esi
    pop    esi
    ret    0x4
  }
}

namespace {
// Inferred scope guard representing the native member-unwind map; array storage is never initialized here.
struct GameDataCleanup {
  byte *record;
  int state;
  // Destroy only the members still armed in the native lifetime map.
  ~GameDataCleanup() noexcept(false) {
    using DestroyABI = void (__thiscall *)(void *);
    static const unsigned offsets[] = {0x24, 0x30, 0x44, 0x50, 0x5c, 0x68, 0x74, 0x80, 0x8c};
    while (state >= 0) {
      int member = state--;
      if (member == 8)
        ((DestroyABI)R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy2)(record + offsets[member]);
      else if (member == 7)
        ((DestroyABI)R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy)(record + offsets[member]);
      else
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(record + offsets[member]);
    }
  }
};
}

// Destroys password, player/map arrays and remaining strings in reverse lifetime order with staged cleanup.
// R6GameService.dll @ 10003020 : receiver in ECX, no stack arguments; member order and exception cleanup preserved.
void __thiscall DestroySTGameData(void *gameData)
{
  byte *record = (byte *)gameData;
  GameDataCleanup cleanup{record, 8};
  using DestroyABI = void (__thiscall *)(void *);
  (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(record + 0x98);
  cleanup.state = 7;
  ((DestroyABI)R6GameServiceAddresses::DestroyArray2CByteElements)(record + 0x8c);
  cleanup.state = 6;
  ((DestroyABI)R6GameServiceAddresses::DestroyArray18ByteElements)(record + 0x80);
  static const unsigned offsets[] = {0x74, 0x68, 0x5c, 0x50, 0x44, 0x30, 0x24};
  for (unsigned offset : offsets) {
    --cleanup.state;
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringNoInitSlot)(record + offset);
  }
}

// Constructs eight no-init strings and returns the original record without initializing scalar or array storage.
// R6GameService.dll @ 100030f0 : receiver in ECX, no stack arguments; member order and exception cleanup preserved.
void * __thiscall ConstructServerGameData(void *gameData)
{
  byte *record = (byte *)gameData;
  GameDataCleanup cleanup{record, -1};
  using ConstructABI = void (__thiscall *)(void *);
  static const unsigned offsets[] = {0x24, 0x30, 0x44, 0x50, 0x5c, 0x68, 0x74};
  for (unsigned offset : offsets) {
    (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(record + offset);
    ++cleanup.state;
  }
  // The native state skips to 8: failure destroys both preexisting array headers before the seven strings.
  cleanup.state = 8;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(record + 0x98);
  cleanup.state = -1;
  return gameData;
}

// Copy-constructs game-data scalars, reflected flag bits, eight strings and both arrays under exact staged cleanup.
// R6GameService.dll @ 10003190 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall CopyConstructSTGameData(void *destination,const void *source)
{
  __asm {
    // Scalar accesses around second-string completion retain their state0/state1 boundary; constructor has no self guard.
    push   0xffffffff
    push   R6GameServiceAddresses::SelectGameDataExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x8],esi
    mov    ecx,DWORD PTR [esi]
    mov    edi,DWORD PTR [esp+0x1c]
    mov    eax,DWORD PTR [edi]
    xor    eax,ecx
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi],ecx
    mov    eax,ecx
    mov    ecx,DWORD PTR [edi]
    xor    ecx,eax
    and    ecx,0x2
    xor    ecx,eax
    mov    DWORD PTR [esi],ecx
    mov    edx,DWORD PTR [edi+0x4]
    mov    DWORD PTR [esi+0x4],edx
    mov    eax,DWORD PTR [edi+0x8]
    mov    DWORD PTR [esi+0x8],eax
    mov    ecx,DWORD PTR [edi+0xc]
    mov    eax,DWORD PTR [esi+0x14]
    mov    DWORD PTR [esi+0xc],ecx
    mov    edx,DWORD PTR [edi+0x10]
    mov    DWORD PTR [esi+0x10],edx
    xor    eax,DWORD PTR [edi+0x14]
    mov    ecx,DWORD PTR [esi+0x14]
    and    eax,0x1
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x2
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x4
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x8
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x10
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x20
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x40
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x80
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x100
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    eax,DWORD PTR [edi+0x14]
    xor    eax,ecx
    and    eax,0x200
    xor    eax,ecx
    mov    DWORD PTR [esi+0x14],eax
    mov    ecx,DWORD PTR [edi+0x14]
    xor    ecx,eax
    and    ecx,0x400
    xor    ecx,eax
    mov    DWORD PTR [esi+0x14],ecx
    mov    edx,DWORD PTR [edi+0x18]
    mov    DWORD PTR [esi+0x18],edx
    mov    eax,DWORD PTR [edi+0x1c]
    mov    DWORD PTR [esi+0x1c],eax
    mov    ecx,DWORD PTR [edi+0x20]
    lea    edx,[edi+0x24]
    mov    DWORD PTR [esi+0x20],ecx
    push   edx
    lea    ecx,[esi+0x24]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    eax,[edi+0x30]
    push   eax
    lea    ecx,[esi+0x30]
    mov    DWORD PTR [esp+0x18],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [edi+0x3c]
    mov    DWORD PTR [esi+0x3c],ecx
    mov    edx,DWORD PTR [edi+0x40]
    lea    eax,[edi+0x44]
    push   eax
    lea    ecx,[esi+0x44]
    mov    BYTE PTR [esp+0x18],0x1
    mov    DWORD PTR [esi+0x40],edx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    ecx,[edi+0x50]
    push   ecx
    lea    ecx,[esi+0x50]
    mov    BYTE PTR [esp+0x18],0x2
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x5c]
    push   edx
    lea    ecx,[esi+0x5c]
    mov    BYTE PTR [esp+0x18],0x3
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    eax,[edi+0x68]
    push   eax
    lea    ecx,[esi+0x68]
    mov    BYTE PTR [esp+0x18],0x4
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    ecx,[edi+0x74]
    push   ecx
    lea    ecx,[esi+0x74]
    mov    BYTE PTR [esp+0x18],0x5
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    lea    edx,[edi+0x80]
    lea    ecx,[esi+0x80]
    push   edx
    mov    BYTE PTR [esp+0x18],0x6
    call   R6GameServiceAddresses::ConstructStringPairArray18
    lea    eax,[edi+0x8c]
    lea    ecx,[esi+0x8c]
    push   eax
    mov    BYTE PTR [esp+0x18],0x7
    call   R6GameServiceAddresses::ConstructStringRecordArray2C
    add    edi,0x98
    push   edi
    lea    ecx,[esi+0x98]
    mov    BYTE PTR [esp+0x18],0x8
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot2
    mov    ecx,DWORD PTR [esp+0xc]
    pop    edi
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret    0x4
  }
}

// Reloads the saved record pointer and forwards cleanup for its Name member at +24.
// R6GameService.dll @ 10063270 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataName(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x24
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its ModName member at +30.
// R6GameService.dll @ 1006327c : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataModName(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x30
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its GameDataGameType member at +44.
// R6GameService.dll @ 10063288 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataGameDataGameType(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x44
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its GameType member at +50.
// R6GameService.dll @ 10063294 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataGameType(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x50
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its CurrentMap member at +5c.
// R6GameService.dll @ 100632a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataCurrentMap(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x5c
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its MessageOfDay member at +68.
// R6GameService.dll @ 100632ac : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataMessageOfDay(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x68
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its GameVersion member at +74.
// R6GameService.dll @ 100632b8 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataGameVersion(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x74
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Reloads the saved record pointer and forwards cleanup for its MapArray member at +80.
// R6GameService.dll @ 100632c4 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataMapArray(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x80
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy
  }
}

// Reloads the saved record pointer and forwards cleanup for its PlayerArray member at +8c.
// R6GameService.dll @ 100632d2 : complete native control/access order and raw ABI retained.
__declspec(naked) void UnwindGameDataPlayerArray(void)
{
  __asm {
    // Inherited parent EBP-10 is authoritative; array actions preserve the native destructor-tail entrypoints.
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x8c
    jmp    R6GameServiceAddresses::unreal_array_support_ForwardArrayDestroy2
  }
}

// Selects the nine-state game-data FuncInfo and forwards the existing C++ exception frame.
// R6GameService.dll @ 100632e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void SelectGameDataExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::stGameDataSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}
