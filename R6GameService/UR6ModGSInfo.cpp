#include "native_addresses.h"
#include "native_records.h"

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

// Constructs UObject and the no-init string at +0x40; leaves activation bytes and flag storage untouched.
// R6GameService.dll @ 10001640 : complete native control/access order and raw ABI retained.
__declspec(naked) UR6ModGSInfo * __thiscall UR6ModGSInfo::UR6ModGSInfo(void)
{
  __asm {
    push   0xffffffff
    push   R6GameServiceAddresses::UR6ModGSInfoSharedLifetimeSelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    push   ecx
    push   esi
    mov    esi,ecx
    mov    DWORD PTR [esp+0x4],esi
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructUObjectSlot
    lea    ecx,[esi+0x40]
    mov    DWORD PTR [esp+0x10],0x0
    mov    DWORD PTR [esi],R6GameServiceAddresses::UR6ModGSInfoDispatchTable
    call   DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringNoInitSlot
    mov    ecx,DWORD PTR [esp+0x8]
    mov    eax,esi
    pop    esi
    mov    DWORD PTR fs:0x0,ecx
    add    esp,0x10
    ret
  }
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

// Constructs supplied nonnull memory by tail transfer; null input retains the incoming EAX.
// R6GameService.dll @ 10002090 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl UR6ModGSInfo::InternalConstructor(void *memory)
{
  __asm {
    mov    ecx,DWORD PTR [esp+0x4]
    test   ecx,ecx
    je     Branch5
    jmp    R6GameServiceAddresses::UR6ModGSInfo_UR6ModGSInfo
  Branch5:
    ret
  }
}

// Consume the optional debug token, initialize the key, select the uppercase mod service name and publish both globals.
// Keep hidden FString result storage, three alternate lifetimes, raw log header words and the native guard/catch map.
// R6GameService.dll @ 10005460 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ModGSInfo::execNativeInitModInfo(FFrame &frame,void *result)
{
  __asm {
    push    ebp
    mov    ebp,esp
    push    0xffffffff
    push    R6GameServiceAddresses::SelectModInfoEH
    mov    eax,fs:0x0
    push    eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x30
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6ModGSInfo* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  FFrame* executionStack = *reinterpret_cast<FFrame**>(nativeFrame + 8);
  byte*& code = *reinterpret_cast<byte**>(reinterpret_cast<byte*>(executionStack) + 0xc);
  byte* next = code + 1;
  code = next;
  const bool debugInfo = *next == 0x42;
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  if (debugInfo) {
    UObject* context = *reinterpret_cast<UObject**>(reinterpret_cast<byte*>(executionStack) + 8);
    code = next + 1;
    using ScriptNative = void (__thiscall *)(UObject*, FFrame*, void*);
    ScriptNative* natives = *reinterpret_cast<ScriptNative**>(R6GameServiceAddresses::Core__GNativesSlot);
    natives[0x42](context, executionStack, nullptr);
  }
  // This native has no script arguments or result. Registry/mod-manager objects supply the inputs.
  receiver->InitMODCDKey();
  FString* version = reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString2);
  *version = reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRSPC12);
  FString* serviceName = reinterpret_cast<FString*>(nativeFrame - 0x24);
  FString::FString(serviceName, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextR6RSCUSTOM));
  byte* modManager = *reinterpret_cast<byte**>(
      *reinterpret_cast<uint*>(R6GameServiceAddresses::Engine__GModMgrSlot));
  byte* currentMod = *reinterpret_cast<byte**>(modManager + 0x34);
  FString* modName = reinterpret_cast<FString*>(currentMod + 0x94);
  FString* uppercase = reinterpret_cast<FString*>(nativeFrame - 0x30);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
  // Caps writes a hidden FString result; do not create an additional temporary or change its cleanup state.
  using CapsFunction = void (__thiscall *)(FString*, FString*);
  (*reinterpret_cast<CapsFunction*>(R6GameServiceAddresses::Core_FString_CapsSlot))(modName, uppercase);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 2;
  const TCHAR* upperText = **uppercase;
  using CompareFunction = int (__cdecl *)(const TCHAR*, const TCHAR*);
  CompareFunction compare = *reinterpret_cast<CompareFunction*>(R6GameServiceAddresses::Core__appStricmpSlot);
  uint selectedText = 0;
  byte selectedState = 0;
  if (compare(upperText, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextATHENASWORD)) == 0) {
    selectedText = R6GameServiceAddresses::WideTextR6RSATHENASWORD; selectedState = 3;
  } else if (compare(**uppercase, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextIRONWRATH)) == 0) {
    selectedText = R6GameServiceAddresses::WideTextR6RSCRIMSONHAMMER; selectedState = 4;
  } else if (compare(**uppercase, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextRAVENSHIELD)) == 0) {
    selectedText = R6GameServiceAddresses::WideTextRAVENSHIELD; selectedState = 5;
  }
  if (selectedText) {
    FString* selection = reinterpret_cast<FString*>(nativeFrame - 0x3c);
    // Assignment consumes the constructor's actual EAX, while destruction always targets native storage -0x3c.
    using StringConstructor = FString* (__thiscall *)(FString*, const TCHAR*);
    FString* constructed = (*reinterpret_cast<StringConstructor*>(
        R6GameServiceAddresses::Core__ConstructFStringSlot2))(selection, reinterpret_cast<const TCHAR*>(selectedText));
    *reinterpret_cast<byte*>(nativeFrame - 4) = selectedState;
    *serviceName = *constructed;
    *reinterpret_cast<byte*>(nativeFrame - 4) = 2;
    FString::~FString(selection);
  }
  *reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString3) = *serviceName;
  *reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString1) = *serviceName;
  if (*reinterpret_cast<int*>(R6GameServiceAddresses::GServiceVerboseLogging)) {
    const uint* versionHeader = reinterpret_cast<const uint*>(version);
    const uint versionData = versionHeader[0], versionCount = versionHeader[1];
    using LogFunction = void (__cdecl *)(FOutputDevice*, const TCHAR*, ...);
    LogFunction log = *reinterpret_cast<LogFunction*>(R6GameServiceAddresses::Core_FOutputDevice_LogfSlot);
    const uint versionCapacity = versionHeader[2];
    log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextInitModInfoUbiClientVersionS),
        versionData, versionCount, versionCapacity);
    // Native varargs pass the three raw header DWORDs, not operator* text; reload all of them after the first log.
    const uint* gameHeader = reinterpret_cast<const uint*>(R6GameServiceAddresses::GServiceString1);
    const uint gameData = gameHeader[0], gameCount = gameHeader[1], gameCapacity = gameHeader[2];
    log(GLog, reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextInitModInfoMSzGameServiceGameNameS),
        gameData, gameCount, gameCapacity);
  }
  *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
  FString::~FString(uppercase);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
  FString::~FString(serviceName);
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret 0x8
  }
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
// R6GameService.dll data @ 1007d148 : native storage identity retained.
const R6GameServiceNative::FuncInfo InitMODCDKeyExceptionInfo = {
  0x19930520,
  0x6,
  R6GameServiceAddresses::InitMODCDKeyUnwindMap,
  0x1,
  R6GameServiceAddresses::InitMODCDKeyTryMap,
  0x0,
  0x0,
};

// Builds the mod registry path, validates its CD-key value and updates 0x1009344c; failure clears activation bit0.
// R6GameService.dll @ 1000c7b0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __thiscall UR6ModGSInfo::InitMODCDKey(UR6ModGSInfo *this)
{
  __asm {
    push   ebp
    mov    ebp,esp
    push   0xffffffff
    push   R6GameServiceAddresses::InitMODCDKeySelectExceptionInfo
    mov    eax,fs:0x0
    push   eax
    mov    DWORD PTR fs:0x0,esp
    sub    esp,0x38
    push ebx
    push esi
    push edi
    mov esi,ecx
    mov DWORD PTR [ebp-0x10],esp
  }
  // These aliases bind existing native storage; inherited-frame handlers and their offsets remain unchanged.
  byte* nativeFrame;
  UR6ModGSInfo* receiver;
  __asm { mov nativeFrame,ebp }
  __asm { mov receiver,esi }
  *reinterpret_cast<int*>(nativeFrame - 4) = 0;
  FString* key = reinterpret_cast<FString*>(nativeFrame - 0x2c);
  FString::FString(key);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
  FString* registryPath = reinterpret_cast<FString*>(nativeFrame - 0x38);
  FString::FString(registryPath,
      reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::WideTextSOFTWARERedStormEntertainment));
  byte* modManager = *reinterpret_cast<byte**>(
      *reinterpret_cast<uint*>(R6GameServiceAddresses::Engine__GModMgrSlot));
  byte* mod = *reinterpret_cast<byte**>(modManager + 0x34);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 2;
  *registryPath += *reinterpret_cast<FString*>(mod + 0x94);
  // RegGet owns its two by-value FString arguments; its output aliases key. The status is ignored.
  __asm {
    lea eax,[ebp-0x2c]
    push eax
    sub esp,0xc
    mov ecx,esp
    mov DWORD PTR [ebp-0x18],esp
    push R6GameServiceAddresses::WideTextCDKey
    call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot2
    sub esp,0xc
    lea edx,[ebp-0x38]
    mov ecx,esp
    mov DWORD PTR [ebp-0x1c],esp
    push edx
    mov BYTE PTR [ebp-0x4],0x3
    call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    mov BYTE PTR [ebp-0x4],0x2
    call DWORD PTR ds:R6GameServiceAddresses::Core__RegGetSlot
    add esp,0x10
  }
  // Validation consumes an outgoing copy. CD-key internals remain outside this initialization trace.
  uint valid;
  __asm {
    lea eax,[ebp-0x2c]
    mov ecx,esp
    mov DWORD PTR [ebp-0x1c],esp
    push eax
    call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
    call R6GameServiceAddresses::IsCDKeyValidOnMachine
    add esp,0xc
    mov valid,eax
  }
  if (valid) {
    FString* decrypted;
    __asm {
      sub esp,0xc
      lea edx,[ebp-0x2c]
      mov ecx,esp
      mov DWORD PTR [ebp-0x1c],esp
      push edx
      call DWORD PTR ds:R6GameServiceAddresses::Core__ConstructFStringSlot3
      lea eax,[ebp-0x44]
      push eax
      call R6GameServiceAddresses::DecryptFStringWithUeviLCore
      add esp,0x10
      mov decrypted,eax
    }
    *reinterpret_cast<byte*>(nativeFrame - 4) = 4;
    *reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString5) = *decrypted;
    *reinterpret_cast<byte*>(nativeFrame - 4) = 2;
    FString::~FString(reinterpret_cast<FString*>(nativeFrame - 0x44));
  } else {
    *reinterpret_cast<FString*>(R6GameServiceAddresses::GServiceString5) =
        reinterpret_cast<const TCHAR*>(R6GameServiceAddresses::GEmptyWideText);
    *reinterpret_cast<uint*>(reinterpret_cast<byte*>(receiver) + 0x3c) &= 0xfffffffe;
  }
  // Success leaves activation bit 0 as it was; failure clears it only after publishing the empty string.
  *reinterpret_cast<byte*>(nativeFrame - 4) = 1;
  FString::~FString(registryPath);
  *reinterpret_cast<byte*>(nativeFrame - 4) = 0;
  FString::~FString(key);
  __asm {
    mov ecx,DWORD PTR [ebp-0xc]
    pop edi
    pop esi
    mov DWORD PTR fs:0x0,ecx
    pop ebx
    mov esp,ebp
    pop ebp
    ret
  }
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
// R6GameService.dll data @ 1007b808 : native storage identity retained.
const R6GameServiceNative::TryBlock execNativeInitModInfoTryMap[1] = {
  {0x0, 0x5, 0x6, 0x2, R6GameServiceAddresses::UR6ModGSInfoGModInfoEH},
};

// Literal mod-info cleanup/handler/try/FuncInfo words.
// R6GameService.dll data @ 1007b7d0 : native storage identity retained.
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
