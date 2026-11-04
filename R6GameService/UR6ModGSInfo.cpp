#include "native_addresses.h"
#include "native_records.h"

namespace {
// Inferred guard for the UObject base completed before the mod's no-init string construction.
struct ModInfoBaseConstructionCleanup {
  void *object;
  bool armed;
  // Destroy only the completed base when a derived construction step fails.
  ~ModInfoBaseConstructionCleanup() noexcept(false) {
    if (armed) {
      using DestroyABI = void (__thiscall *)(void *);
      (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyUObjectSlot)(object);
    }
  }
};
}

// R6GameService.dll data @ 1007a8e8 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry UR6ModGSInfo_UR6ModGSInfoUnwindMap[2] = {
  {-1, R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoUnwind1},
  {0x0, R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoUnwind22},
};
// R6GameService.dll data @ 1007a8f8 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo UR6ModGSInfo_UR6ModGSInfoExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};
// R6GameService.dll data @ 1007a914 : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::UnwindEntry UR6ModGSInfoSharedLifetimeUnwindMap[1] = {
  {-1, R6GameServiceAddresses::UR6ModGSInfoSharedLifetimeUnwind1},
};
// R6GameService.dll data @ 1007a91c : selected predecessor/action or FuncInfo words.
const R6GameServiceNative::FuncInfo UR6ModGSInfoSharedLifetimeExceptionInfo = {
  0x19930520,
  0x1,
  R6GameServiceAddresses::UR6ModGSInfoSharedLifetimeUnwindMap,
  0x0,
  0x0,
  0x0,
  0x0,
};

// Returns the relocated UR6ModGSInfo class object.
// R6GameService.dll @ 10001590 : complete native control/access order and raw ABI retained.
UClass * __cdecl UR6ModGSInfo::StaticClass(void)
{
  return reinterpret_cast<UClass *>(0x10091e88);
}

// Allocates using the class object, supplied outer/name/flags and current GError; ignores requested size.
// R6GameService.dll @ 100015a0 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __cdecl UR6ModGSInfo::operator new(uint size,UObject *outer,FName name,ulong flags)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::Core__GErrorSlot
    mov    ecx,DWORD PTR [eax]
    mov    edx,DWORD PTR [esp+0x10]
    mov    eax,DWORD PTR [esp+0xc]
    push   0x0
    push   0x0
    push   ecx
    mov    ecx,DWORD PTR [esp+0x14]
    push   0x0
    push   edx
    push   eax
    push   ecx
    push   0x10091e88
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_StaticAllocateObjectSlot
    add    esp,0x20
    ret
  }
}

// Installs the class table, conditionally destroys UObject state, then destroys its string and UObject base.
// R6GameService.dll @ 100015e0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ModGSInfo::~UR6ModGSInfo(void)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ModGSInfoDispatchTable
    mov    DWORD PTR [esp+0x10],0x1
    call   DWORD PTR ds:R6GameServiceAddresses::Core_UObject_ConditionalDestroySlot
    lea    ecx,[esi+0x40]
    mov    BYTE PTR [esp+0x10],0x0
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
    mov    ecx,esi
    mov    DWORD PTR [esp+0x10],0xffffffff
    call   DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUObjectSlot
    mov    ecx,DWORD PTR [esp+0x8]
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
}

// Destroys the UObject base through the destructor parent receiver at EBP-0x10.
// R6GameService.dll @ 10063070 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfo_UR6ModGSInfoUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUObjectSlot
  }
}

// Destroys the string at +0x40 through the destructor parent receiver at EBP-0x10.
// R6GameService.dll @ 10063079 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfo_UR6ModGSInfoUnwind22(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    add    ecx,0x40
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringNoInitSlot
  }
}

// Selects the two-state destructor cleanup map and forwards the runtime frame arguments.
// R6GameService.dll @ 10063085 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfo_UR6ModGSInfoSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Construct UObject, publish the mod table and construct the +0x40 no-init string, leaving other storage untouched.
// R6GameService.dll @ 10001640 : complete native control/access order and raw ABI retained.
UR6ModGSInfo::UR6ModGSInfo(void)
{
  byte *object = (byte *)this;
  ModInfoBaseConstructionCleanup cleanup{object, false};
  using ConstructABI = void (__thiscall *)(void *);
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructUObjectSlot)(object);
  cleanup.armed = true;
  *(uint *)object = R6GameServiceAddresses::UR6ModGSInfoDispatchTable;
  (*(ConstructABI *)R6GameServiceAddresses::Core__ConstructFStringNoInitSlot)(object + 0x40);
  cleanup.armed = false;
}

// Copies UObject, four activation words, flag bit0 and the string; arms base cleanup before publishing the flag.
// R6GameService.dll @ 10001690 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ModGSInfo * __thiscall UR6ModGSInfo::UR6ModGSInfo(const UR6ModGSInfo *source)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ModGSInfoSharedLifetimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    push   edi
    mov    edi,DWORD PTR [esp+0x1c]
    mov    esi,ecx
    push   edi
    mov    DWORD PTR [esp+0xc],esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructUObjectSlot2
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ModGSInfoDispatchTable
    lea    eax,[edi+0x2c]
    mov    edx,DWORD PTR [eax]
    lea    ecx,[esi+0x2c]
    mov    DWORD PTR [ecx],edx
    mov    edx,DWORD PTR [eax+0x4]
    mov    DWORD PTR [ecx+0x4],edx
    mov    edx,DWORD PTR [eax+0x8]
    mov    DWORD PTR [ecx+0x8],edx
    mov    eax,DWORD PTR [eax+0xc]
    mov    edx,DWORD PTR [esi+0x3c]
    mov    DWORD PTR [ecx+0xc],eax
    mov    ecx,DWORD PTR [edi+0x3c]
    xor    ecx,edx
    and    ecx,0x1
    xor    edx,ecx
    add    edi,0x40
    push   edi
    lea    ecx,[esi+0x40]
    mov    DWORD PTR [esp+0x18],0x0
    mov    DWORD PTR [esi+0x3c],edx
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

// Destroys the UObject base through the constructor parent receiver at EBP-0x10.
// R6GameService.dll @ 10063090 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfoSharedLifetimeUnwind1(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x10]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUObjectSlot
  }
}

// Selects the shared one-state default/copy-constructor cleanup map and forwards the runtime arguments.
// R6GameService.dll @ 10063099 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfoSharedLifetimeSelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::UR6ModGSInfoSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Assigns UObject, sixteen activation bytes, flag bit0 and the string in order, without a self guard.
// R6GameService.dll @ 10001720 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ModGSInfo * __thiscall UR6ModGSInfo::operator=(const UR6ModGSInfo *source)
{
  __asm {
    push   ebp
    mov    ebp,DWORD PTR [esp+0x8]
    push   esi
    push   edi
    push   ebp
    mov    esi,ecx
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4UObjectSlot
    mov    ecx,ebp
    lea    eax,[esi+0x2c]
    sub    ecx,esi
    mov    edi,0x10
    lea    esp,[esp+0x0]
  Branch1:
    mov    dl,BYTE PTR [ecx+eax*1]
    mov    BYTE PTR [eax],dl
    inc    eax
    dec    edi
    jne    Branch1
    mov    eax,DWORD PTR [ebp+0x3c]
    mov    edi,DWORD PTR [esi+0x3c]
    xor    eax,edi
    and    eax,0x1
    mov    ecx,edi
    xor    ecx,eax
    mov    DWORD PTR [esi+0x3c],ecx
    add    ebp,0x40
    push   ebp
    lea    ecx,[esi+0x40]
    call   DWORD PTR ds:R6GameServiceAddresses::Core__4FStringNoInitSlot
    pop    edi
    mov    eax,esi
    pop    esi
    pop    ebp
    ret    0x4
  }
}

// Destroys one object or a cookie-counted vector and optionally frees it, returning object or cookie pointer.
// R6GameService.dll @ 10001770 : complete native control/access order and raw ABI retained.
__declspec(naked) void * __thiscall DeleteUR6ModGSInfo(UR6ModGSInfo *object,uint flags)
{
  __asm {
    push   ebx
    mov    bl,BYTE PTR [esp+0x8]
    test   bl,0x2
    push   esi
    mov    esi,ecx
    je     Branch3
    mov    eax,DWORD PTR [esi-0x4]
    push   edi
    push   R6GameServiceAddresses::UR6ModGSInfo__UR6ModGSInfo
    lea    edi,[esi-0x4]
    push   eax
    push   0x4c
    push   esi
    call   R6GameServiceAddresses::_eh_vector_destructor_iterator_
    test   bl,0x1
    je     Branch2
    mov    ecx,DWORD PTR ds:R6GameServiceAddresses::Core__GMallocSlot
    mov    ecx,DWORD PTR [ecx]
    mov    edx,DWORD PTR [ecx]
    push   edi
    call   DWORD PTR [edx+0x8]
  Branch2:
    mov    eax,edi
    pop    edi
    pop    esi
    pop    ebx
    ret    0x4
  Branch3:
    mov    ecx,esi
    call   R6GameServiceAddresses::UR6ModGSInfo__UR6ModGSInfo
    test   bl,0x1
    je     Branch4
    push   0x4c
    push   esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__3UObjectSlot
    add    esp,0x8
  Branch4:
    mov    eax,esi
    pop    esi
    pop    ebx
    ret    0x4
  }
}

// Construct a mod-info object in supplied nonnull storage without allocating memory.
// R6GameService.dll @ 10002090 : complete native control/access order and raw ABI retained.
void __cdecl UR6ModGSInfo::InternalConstructor(void *memory)
{
  if (memory != nullptr) {
    using ConstructABI = void (__thiscall *)(void *);
    ((ConstructABI)R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfo)(memory);
  }
}

// Inferred physical FString/catch slots from EBP-3c through EBP-14; string roles follow the native data flow.
struct ModInfoInitializationLocals {
  uint selection[3];
  uint uppercase[3];
  uint serviceName[3];
  uint caught;
  uint forwarded;
};

// Retain each constructed local until its destructor is entered; catch state6 owns no local strings.
struct ModInfoInitializationCleanup {
  ModInfoInitializationLocals *frame;
  int state;
  bool armed;
  // Unwind the active selection/uppercase/name chain before the native typed or catch-all handler runs.
  void releaseActive()
  {
    using DestroyABI = void (__thiscall *)(void *);
    while (state >= 0) {
      if (state >= 3 && state <= 5) {
        state = 2;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->selection);
      } else if (state == 2) {
        state = 1;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->uppercase);
      } else if (state == 1) {
        state = 0;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->serviceName);
      } else state = -1;
    }
  }
  // Normal completion dismisses this logical guard; entered destruction is never retried.
  ~ModInfoInitializationCleanup() noexcept(false)
  {
    if (armed) releaseActive();
  }
};

// Consume an optional debug token, initialize the key, choose the mod's uppercase service name and publish globals.
// Keep hidden FString storage, constructor-return assignment, cached compare/log targets and raw header log arguments.
// R6GameService.dll @ 10005460 : exported void(FFrame&,void*), thiscall RET8; result argument is unread.
void __thiscall UR6ModGSInfo::execNativeInitModInfo(FFrame &frame,void *result)
{
  ModInfoInitializationLocals locals;
  ModInfoInitializationCleanup cleanup{&locals,-1,true};
  UR6ModGSInfo *receiver = this;
  FFrame *executionStack = &frame;
  byte **code = (byte **)((byte *)executionStack + 0xc);
  byte *next = *code + 1;
  *code = next;
  bool debugInfo = *next == 0x42;
  cleanup.state = 0;
  using LiteralABI = void * (__thiscall *)(void *,const ushort *);
  using AssignABI = void * (__thiscall *)(void *,const void *);
  using DataABI = const ushort * (__thiscall *)(const void *);
  using DestroyABI = void (__thiscall *)(void *);
  try {
    if (debugInfo) {
      UObject *context = *(UObject **)((byte *)executionStack + 8);
      *code = next + 1;
      using ScriptABI = void (__thiscall *)(UObject *,FFrame *,void *);
      ScriptABI *natives = *(ScriptABI **)R6GameServiceAddresses::Core__GNativesSlot;
      natives[0x42](context,executionStack,nullptr);
    }
    receiver->InitMODCDKey();
    uint *version = (uint *)R6GameServiceAddresses::GServiceString2;
    (*(LiteralABI *)R6GameServiceAddresses::Core__4FStringSlot2)(
        version,(const ushort *)R6GameServiceAddresses::WideTextRSPC12);
    (*(LiteralABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)(
        locals.serviceName,(const ushort *)R6GameServiceAddresses::WideTextR6RSCUSTOM);
    uint managerSlot = *(uint *)R6GameServiceAddresses::Engine__GModMgrSlot;
    uint manager = *(uint *)managerSlot;
    uint mod = *(uint *)(manager + 0x34);
    cleanup.state = 1;
    using CapsABI = void * (__thiscall *)(void *,void *);
    (*(CapsABI *)R6GameServiceAddresses::Core_FString_CapsSlot)((void *)(mod + 0x94),locals.uppercase);
    cleanup.state = 2;
    const ushort *upperText = (*(DataABI *)R6GameServiceAddresses::Core__DFStringSlot)(locals.uppercase);
    using CompareABI = int (__cdecl *)(const ushort *,const ushort *);
    CompareABI compare = *(CompareABI *)R6GameServiceAddresses::Core__appStricmpSlot;
    uint selectedText = 0;
    int selectedState = 0;
    if (compare(upperText,(const ushort *)R6GameServiceAddresses::WideTextATHENASWORD) == 0) {
      selectedText = R6GameServiceAddresses::WideTextR6RSATHENASWORD;
      selectedState = 3;
    } else if (compare((*(DataABI *)R6GameServiceAddresses::Core__DFStringSlot)(locals.uppercase),
                       (const ushort *)R6GameServiceAddresses::WideTextIRONWRATH) == 0) {
      selectedText = R6GameServiceAddresses::WideTextR6RSCRIMSONHAMMER;
      selectedState = 4;
    } else if (compare((*(DataABI *)R6GameServiceAddresses::Core__DFStringSlot)(locals.uppercase),
                       (const ushort *)R6GameServiceAddresses::WideTextRAVENSHIELD) == 0) {
      selectedText = R6GameServiceAddresses::WideTextRAVENSHIELD;
      selectedState = 5;
    }
    if (selectedText != 0) {
      void *constructed = (*(LiteralABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)(
          locals.selection,(const ushort *)selectedText);
      cleanup.state = selectedState;
      (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(locals.serviceName,constructed);
      cleanup.state = 2;
      (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.selection);
    }
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(
        (void *)R6GameServiceAddresses::GServiceString3,locals.serviceName);
    (*(AssignABI *)R6GameServiceAddresses::Core__4FStringSlot)(
        (void *)R6GameServiceAddresses::GServiceString1,locals.serviceName);
    if (*(uint *)R6GameServiceAddresses::GServiceVerboseLogging != 0) {
      uint data = version[0];
      uint count = version[1];
      using LogABI = void (__cdecl *)(void *,const ushort *,...);
      LogABI log = *(LogABI *)R6GameServiceAddresses::Core_FOutputDevice_LogfSlot;
      uint capacity = version[2];
      uint logSlot = *(uint *)R6GameServiceAddresses::Core__GLogSlot;
      void *logger = *(void **)logSlot;
      log(logger,(const ushort *)R6GameServiceAddresses::WideTextInitModInfoUbiClientVersionS,data,count,capacity);
      uint *game = (uint *)R6GameServiceAddresses::GServiceString1;
      data = game[0];
      count = game[1];
      capacity = game[2];
      logSlot = *(uint *)R6GameServiceAddresses::Core__GLogSlot;
      logger = *(void **)logSlot;
      log(logger,
          (const ushort *)R6GameServiceAddresses::WideTextInitModInfoMSzGameServiceGameNameS,data,count,capacity);
    }
    cleanup.state = 1;
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.uppercase);
    cleanup.state = 0;
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.serviceName);
  } catch (ushort *error) {
    cleanup.releaseActive();
    cleanup.state = 6;
    locals.caught = (uint)error;
    locals.forwarded = locals.caught;
    throw (ushort *)locals.forwarded;
  } catch (...) {
    cleanup.releaseActive();
    cleanup.state = 6;
    using ReportABI = void (__cdecl *)(const ushort *,...);
    (*(ReportABI *)R6GameServiceAddresses::Core__appUnwindfSlot)(
        (const ushort *)R6GameServiceAddresses::WideTextTextFormat,
        (const ushort *)R6GameServiceAddresses::WideTextUR6ModGSInfoExecNativeInitModInfo);
    throw;
  }
  cleanup.armed = false;
}

// Copies the caught unsigned-short pointer through parent scratch, then forwards a typed throw; pointee is untouched.
// R6GameService.dll @ 1000564e : private inherited-EBP catch entry; exact copy/store/throw order retained.
__declspec(naked) void __cdecl UR6ModGSInfoCatch(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x18]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// R6GameService.dll data @ 1007d148 : selected guard/cleanup records.
const R6GameServiceNative::UnwindEntry InitMODCDKeyUnwindMap[6] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::InitMODCDKeyUnwind2},
  {0x1, R6GameServiceAddresses::InitMODCDKeyUnwind3},
  {0x2, R6GameServiceAddresses::InitMODCDKeyUnwind4},
  {0x2, R6GameServiceAddresses::InitMODCDKeyUnwind5},
  {-1, 0x0},
};
// R6GameService.dll data @ 1007d178 : selected guard/cleanup records.
const R6GameServiceNative::CatchHandler UR6ModGSInfoGCDKeyHandlers[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -32,
  R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoCatch2},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoCatch3},
};
// R6GameService.dll data @ 1007d198 : selected guard/cleanup records.
const R6GameServiceNative::TryBlock InitMODCDKeyTryMap[1] = {
  {0x0, 0x4, 0x5, 0x2, R6GameServiceAddresses::UR6ModGSInfoGCDKeyHandlers},
};
// R6GameService.dll data @ 1007d1ac : selected guard/cleanup records.
const R6GameServiceNative::FuncInfo InitMODCDKeyExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::InitMODCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::InitMODCDKeyTryMap,
  0x0,
  0x0,
};

// Raw by-value Core FString argument; each receiving native owns its three physical words.
struct ModFStringArgument12 { uint words[3]; };

// Inferred physical locals from EBP-44 through EBP-14, including current saved outgoing argument pointers.
struct ModKeyInitializationLocals {
  uint decrypted[3];
  uint registryPath[3];
  uint key[3];
  uint caught;
  uint pathArgument;
  uint keyArgument;
  uint forwarded;
};

// Keep key/path/decrypted locals and only the pending registry key-name argument; callees own transferred copies.
struct ModKeyInitializationCleanup {
  ModKeyInitializationLocals *frame;
  int state;
  bool armed;
  // Unwind every current local before entering catch state5; the path argument constructor owns partial failure.
  void releaseActive()
  {
    using DestroyABI = void (__thiscall *)(void *);
    while (state >= 0) {
      if (state == 4) {
        state = 2;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->decrypted);
      } else if (state == 3) {
        state = 2;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)((void *)frame->keyArgument);
      } else if (state == 2) {
        state = 1;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->registryPath);
      } else if (state == 1) {
        state = 0;
        (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(frame->key);
      } else state = -1;
    }
  }
  // Completed normal destructors are retired before their call and are never retried by this logical guard.
  ~ModKeyInitializationCleanup() noexcept(false)
  {
    if (armed) releaseActive();
  }
};

// Read the current mod registry key, validate/decrypt it and publish cache9344c; failure clears activation bit0.
// Registry status is ignored. Outgoing FString arguments transfer ownership, and successful validation sets no flag.
// R6GameService.dll @ 1000c7b0 : exported void(), thiscall RET0; current flags/imported constructor results retained.
void __thiscall UR6ModGSInfo::InitMODCDKey()
{
  ModKeyInitializationLocals locals;
  ModKeyInitializationCleanup cleanup{&locals,0,true};
  UR6ModGSInfo *receiver = this;
  using DefaultABI = void * (__thiscall *)(void *);
  using LiteralABI = void * (__thiscall *)(void *,const ushort *);
  using CopyABI = void * (__thiscall *)(void *,const void *);
  using DestroyABI = void (__thiscall *)(void *);
  try {
    (*(DefaultABI *)R6GameServiceAddresses::Core__ConstructFStringSlot)(locals.key);
    cleanup.state = 1;
    (*(LiteralABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)(
        locals.registryPath,(const ushort *)R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainment);
    uint managerSlot = *(uint *)R6GameServiceAddresses::Engine__GModMgrSlot;
    uint manager = *(uint *)managerSlot;
    uint mod = *(uint *)(manager + 0x34);
    cleanup.state = 2;
    (*(CopyABI *)R6GameServiceAddresses::Core__YFStringSlot)(locals.registryPath,(void *)(mod + 0x94));
    ModFStringArgument12 keyName;
    locals.keyArgument = (uint)&keyName;
    (*(LiteralABI *)R6GameServiceAddresses::Core__ConstructFStringSlot2)(
        &keyName,(const ushort *)R6GameServiceAddresses::WideTextCDKey);
    ModFStringArgument12 path;
    locals.pathArgument = (uint)&path;
    cleanup.state = 3;
    (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(&path,locals.registryPath);
    cleanup.state = 2;
    using RegistryABI = int (__cdecl *)(ModFStringArgument12,ModFStringArgument12,void *);
    (*(RegistryABI *)R6GameServiceAddresses::Core__RegGetSlot)(path,keyName,locals.key);
    ModFStringArgument12 validationInput;
    locals.pathArgument = (uint)&validationInput;
    (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(&validationInput,locals.key);
    using ValidateABI = uint (__cdecl *)(ModFStringArgument12);
    uint valid = ((ValidateABI)R6GameServiceAddresses::IsCDKeyValidOnMachine)(validationInput);
    if (valid != 0) {
      ModFStringArgument12 decryptionInput;
      locals.pathArgument = (uint)&decryptionInput;
      (*(CopyABI *)R6GameServiceAddresses::Core__ConstructFStringSlot3)(&decryptionInput,locals.key);
      using DecryptABI = void * (__cdecl *)(void *,ModFStringArgument12);
      void *decrypted = ((DecryptABI)R6GameServiceAddresses::DecryptFStringWithUeviLCore)(
          locals.decrypted,decryptionInput);
      cleanup.state = 4;
      (*(CopyABI *)R6GameServiceAddresses::Core__4FStringSlot)(
          (void *)R6GameServiceAddresses::GServiceString5,decrypted);
      cleanup.state = 2;
      (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.decrypted);
    } else {
      (*(LiteralABI *)R6GameServiceAddresses::Core__4FStringSlot2)(
          (void *)R6GameServiceAddresses::GServiceString5,(const ushort *)R6GameServiceAddresses::GEmptyWideText);
      *(uint *)((byte *)receiver + 0x3c) &= 0xfffffffe;
    }
    cleanup.state = 1;
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.registryPath);
    cleanup.state = 0;
    (*(DestroyABI *)R6GameServiceAddresses::Core__DestroyFStringSlot)(locals.key);
  } catch (ushort *error) {
    cleanup.releaseActive();
    cleanup.state = 5;
    locals.caught = (uint)error;
    locals.forwarded = locals.caught;
    throw (ushort *)locals.forwarded;
  } catch (...) {
    cleanup.releaseActive();
    cleanup.state = 5;
    using ReportABI = void (__cdecl *)(const ushort *,...);
    (*(ReportABI *)R6GameServiceAddresses::Core__appUnwindfSlot)(
        (const ushort *)R6GameServiceAddresses::WideTextTextFormat,
        (const ushort *)R6GameServiceAddresses::WideTextUR6ModGSInfoInitMODCDKey);
    throw;
  }
  cleanup.armed = false;
}

// Copies the caught unsigned-short pointer at parent EBP-0x20 to-0x14 and throws it by value.
// R6GameService.dll @ 1000c8e3 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfo_UR6ModGSInfoCatch2(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x20]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    edx,[ebp-0x14]
    push   edx
    mov    DWORD PTR [ebp-0x14],ecx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Reports the CD-key initialization guard context and rethrows the active exception.
// R6GameService.dll @ 1000c8f7 : complete native control/access order and raw ABI retained.
__declspec(naked) void UR6ModGSInfo_UR6ModGSInfoCatch3(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ModGSInfoInitMODCDKey
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Destroys the completed local string at parent EBP-0x2c.
// R6GameService.dll @ 10063e50 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitMODCDKeyUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x2c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed local string at parent EBP-0x38.
// R6GameService.dll @ 10063e59 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitMODCDKeyUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x38]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed outgoing key string through its saved parent EBP-0x18 pointer.
// R6GameService.dll @ 10063e62 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitMODCDKeyUnwind4(void)
{
  __asm {
    mov    ecx,DWORD PTR [ebp-0x18]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroys the completed local string at parent EBP-0x44.
// R6GameService.dll @ 10063e6b : complete native control/access order and raw ABI retained.
__declspec(naked) void InitMODCDKeyUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x44]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Selects the exact CD-key initialization guard and temporary-string cleanup map.
// R6GameService.dll @ 10063e74 : complete native control/access order and raw ABI retained.
__declspec(naked) void InitMODCDKeySelectExceptionInfo(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::InitMODCDKeyExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Destroy the completed local string at inherited parent EBP-0x24; tail the current FString destructor.
// R6GameService.dll @ 10063720 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl execNativeInitModInfoUnwind2(void)
{
  __asm {
    lea    ecx,[ebp-0x24]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed local string at inherited parent EBP-0x30; tail the current FString destructor.
// R6GameService.dll @ 10063729 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl execNativeInitModInfoUnwind3(void)
{
  __asm {
    lea    ecx,[ebp-0x30]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed local string at inherited parent EBP-0x3c; tail the current FString destructor.
// R6GameService.dll @ 10063732 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl execNativeInitModInfoUnwind4(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed local string at inherited parent EBP-0x3c; tail the current FString destructor.
// R6GameService.dll @ 1006373b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl execNativeInitModInfoUnwind5(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Destroy the completed local string at inherited parent EBP-0x3c; tail the current FString destructor.
// R6GameService.dll @ 10063744 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl execNativeInitModInfoUnwind6(void)
{
  __asm {
    lea    ecx,[ebp-0x3c]
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyFStringSlot
  }
}

// Select the seven-state mod-info guard, alternate temporary cleanup and two catch entries.
// R6GameService.dll @ 1006374d : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectModInfoEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::execNativeInitModInfoExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal mod-info cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007b7d0 : native storage identity retained.
const R6GameServiceNative::UnwindEntry execNativeInitModInfoUnwindMap[7] = {
  {-1, 0x0},
  {0x0, R6GameServiceAddresses::execNativeInitModInfoUnwind2},
  {0x1, R6GameServiceAddresses::execNativeInitModInfoUnwind3},
  {0x2, R6GameServiceAddresses::execNativeInitModInfoUnwind4},
  {0x2, R6GameServiceAddresses::execNativeInitModInfoUnwind5},
  {0x2, R6GameServiceAddresses::execNativeInitModInfoUnwind6},
  {-1, 0x0},
};

// Literal mod-info cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007b808 : native storage identity retained.
const R6GameServiceNative::CatchHandler UR6ModGSInfoGModInfoEH[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -24, R6GameServiceAddresses::UR6ModGSInfoCatch},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfoCatch},
};

// Literal mod-info cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007b828 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeInitModInfoTryMap[1] = {
  {0x0, 0x5, 0x6, 0x2, R6GameServiceAddresses::UR6ModGSInfoGModInfoEH},
};

// Literal mod-info cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007b83c : native storage identity retained.
const R6GameServiceNative::FuncInfo execNativeInitModInfoExceptionInfo = {
  0x19930520,
  0x7,
  R6GameServiceAddresses::execNativeInitModInfoUnwindMap,
  0x1,
  R6GameServiceAddresses::execNativeInitModInfoTryMap,
  0x0,
  0x0,
};

// R6GameService.dll @ 1006a330 : initialize UR6ModGSInfo class metadata and register its cleanup
void InitializeUR6ModGSInfoClassMetadata(void)
{
  UClass *objectClass;
  ushort *configName;
  undefined4 constructionFlags;
  code *nativeConstructor;
  code *staticConstructor;

  objectClass = (UClass *)UObject_PrivateStaticClass_exref;
  nativeConstructor = UR6ModGSInfo::InternalConstructor;
  constructionFlags = 0x4084004;
  staticConstructor = UObject_StaticConstructor_exref;
  configName = UObject::StaticConfigName();
  UClass::UClass(&UR6ModGSInfo::PrivateStaticClass,0,0x4c,4,objectClass,objectClass,0,0,0,0,L"R6ModGSInfo",
                 GPackage,configName,constructionFlags,nativeConstructor,staticConstructor);
  _atexit(DestroyUR6ModGSInfoClassMetadata);
  return;
}

// Destroy the exported class metadata through CURRENT imported UClass destructor; keep caller stack/registers.
// R6GameService.dll @ 1006ac70 : compiler atexit cleanup tail, no own frame or return.
__declspec(naked) void DestroyUR6ModGSInfoClassMetadata(void)
{
  __asm {
    mov    ecx,0x10091e88
    jmp    DWORD PTR ds:R6GameServiceAddresses::Core__DestroyUClassSlot
  }
}

// Exported native member-function slot at 0x1008c1d0; its value is read when registration runs.
extern "C" Native intUR6ModGSInfoexecNativeInitModInfo;

// Registers UR6ModGSInfo::execNativeInitModInfo at native index 1207 and stores the returned byte.
// R6GameService.dll @ 1006a3c0 : cdecl startup entry; result byte at 0x100923e5.
void __cdecl RegisterUR6ModGSInfo_execNativeInitModInfo(void)
{
  byte registrationResult = GRegisterNative(1207,intUR6ModGSInfoexecNativeInitModInfo);
  *(byte *)0x100923e5 = registrationResult;
}

// Reports UR6ModGSInfo::execNativeInitModInfo context, then passes two null words to the C++ rethrow helper.
// R6GameService.dll @ 10005662 : private catch entry; native register clobbers and nonreturning transfer retained.
__declspec(naked) void __cdecl UR6ModGSInfo_UR6ModGSInfoCatch(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextUR6ModGSInfoExecNativeInitModInfo
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Native virtual-table prefix: UR6ModGSInfoDispatchTable
// R6GameService.dll data @ 1006b6b0 : reviewed slots only; full table extent is not asserted.
// Named native entry words in slot order; inferred field names follow the existing target identities.
struct UR6ModGSInfoDispatchTableRecord {
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember22; // +0x00
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember21; // +0x04
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember20; // +0x08
  R6GameServiceNative::Address DeleteUR6ModGSInfo; // +0x0c
  R6GameServiceNative::Address UObject_ProcessEvent; // +0x10
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember19; // +0x14
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember18; // +0x18
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember17; // +0x1c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember16; // +0x20
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember15; // +0x24
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember14; // +0x28
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember13; // +0x2c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember12; // +0x30
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember11; // +0x34
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember10; // +0x38
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember9; // +0x3c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember8; // +0x40
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember7; // +0x44
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember6; // +0x48
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember5; // +0x4c
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember4; // +0x50
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember3; // +0x54
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember2; // +0x58
  R6GameServiceNative::Address core_import_support_core_import_supportTailImportedMember; // +0x5c
  R6GameServiceNative::Address core_import_supportTailImportedMember; // +0x60
};
const UR6ModGSInfoDispatchTableRecord UR6ModGSInfoDispatchTable = {
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember22,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember21,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember20,
  R6GameServiceAddresses::DeleteUR6ModGSInfo,
  R6GameServiceAddresses::UObject_ProcessEvent,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember19,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember18,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember17,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember16,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember15,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember14,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember13,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember12,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember11,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember10,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember9,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember8,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember7,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember6,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember5,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember4,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember3,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember2,
  R6GameServiceAddresses::core_import_support_core_import_supportTailImportedMember,
  R6GameServiceAddresses::core_import_supportTailImportedMember,
};
