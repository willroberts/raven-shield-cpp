#include "native_addresses.h"
#include "native_records.h"

// Initializes eleven exported event names through one cached constructor, preserving and returning incoming ECX.
// R6GameService.dll @ 10005270 : ECX input, no stack arguments, RET; FuncInfo 0x1007b7b4.
uint __fastcall InitializeR6GameServiceEventNames(uint incomingECX)
{
  void *previousExceptionList = ExceptionList;
  undefined1 *exceptionHandler = &SelectEventNameStartupEH;
  uint guardState = 0xffffffff;
  ExceptionList = &previousExceptionList;
  using NameConstructor = FName *(__thiscall *)(FName *,const ushort *,int);
  NameConstructor constructName = *(NameConstructor *)R6GameServiceAddresses::Core__ConstructFNameSlot;
  uint temporaryNameWord; // Native constructor destination is the single word at EBP-0x18.
  FName *temporaryName = (FName *)&temporaryNameWord;
  FName *constructedName;
  guardState = 0; // Both FuncInfo unwind states have no cleanup action.
  constructedName = constructName(temporaryName,(const ushort *)L"IsGlobalIDBanned",2);
  R6GAMESERVICE_IsGlobalIDBanned = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"GetMaxAvailPorts",2);
  R6GAMESERVICE_GetMaxAvailPorts = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"EndOfRoundDataSent",2);
  R6GAMESERVICE_EndOfRoundDataSent = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"HandleNewLobbyConnection",2);
  R6GAMESERVICE_HandleNewLobbyConnection = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"GetConsoleStoreIP",2);
  R6GAMESERVICE_GetConsoleStoreIP = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"ProcessServerMsg",2);
  R6GAMESERVICE_ProcessServerMsg = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"TempGetPBConnectStatus",2);
  R6GAMESERVICE_TempGetPBConnectStatus = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"FillCreateGameInfo",2);
  R6GAMESERVICE_FillCreateGameInfo = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"GetLocallyBoundIpAddr",2);
  R6GAMESERVICE_GetLocallyBoundIpAddr = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"GetLobbyAndGroupID",2);
  R6GAMESERVICE_GetLobbyAndGroupID = *(uint *)constructedName;
  constructedName = constructName(temporaryName,(const ushort *)L"InitializeMod",2);
  R6GAMESERVICE_InitializeMod = *(uint *)constructedName;
  ExceptionList = previousExceptionList;
  return incomingECX;
}

// Copy inherited unsigned-short pointer from EBP-1c to EBP-14, then typed throw; do not access pointee.
// R6GameService.dll @ 1000538b : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl global_stateCatch(void)
{
  __asm {
    mov    edx,DWORD PTR [ebp-0x1c]
    push   R6GameServiceAddresses::GGSServersPointerUShortThrow
    lea    eax,[ebp-0x14]
    push   eax
    mov    DWORD PTR [ebp-0x14],edx
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Report startup context through current Core import, then call rethrow with null exception/type.
// R6GameService.dll @ 1000539f : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl global_state_global_stateCatch(void)
{
  __asm {
    push   R6GameServiceAddresses::WideTextR6GameServiceInit
    push   R6GameServiceAddresses::WideTextTextFormat
    call   DWORD PTR ds:R6GameServiceAddresses::Core__appUnwindfSlot
    add    esp,0x8
    push   0x0
    push   0x0
    call   R6GameServiceAddresses::_CxxThrowException
  }
}

// Select startup two-state/no-action catch metadata; preserve inherited frame and original exception dispatch stack.
// R6GameService.dll @ 10063710 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl SelectEventNameStartupEH(void)
{
  __asm {
    mov    eax,R6GameServiceAddresses::global_stateSharedLifetimeExceptionInfo
    jmp    R6GameServiceAddresses::__CxxFrameHandler
  }
}

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b770 : native storage identity retained.
const R6GameServiceNative::UnwindEntry global_stateSharedLifetimeUnwindMap[2] = {{-1, 0x0}, {-1, 0x0}};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b780 : native storage identity retained.
const R6GameServiceNative::CatchHandler global_stateGInheritedFrameEH2[2] = {
  {0x0, R6GameServiceAddresses::UnsignedShortPointerTypeDescriptor, -28, R6GameServiceAddresses::global_stateCatch},
  {0x0, 0x0, 0x0, R6GameServiceAddresses::global_state_global_stateCatch},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b780 : native storage identity retained.
const R6GameServiceNative::TryBlock global_stateSharedLifetimeTryMap[1] = {
  {0x0, 0x0, 0x1, 0x2, R6GameServiceAddresses::global_stateGInheritedFrameEH2},
};

// Literal inherited-frame unwind/handler/try/FuncInfo record.
// R6GameService.dll data @ 1007b770 : native storage identity retained.
const R6GameServiceNative::FuncInfo global_stateSharedLifetimeExceptionInfo = {
  0x19930520,
  0x2,
  R6GameServiceAddresses::global_stateSharedLifetimeUnwindMap,
  0x1,
  R6GameServiceAddresses::global_stateSharedLifetimeTryMap,
  0x0,
  0x0,
};

// Selected native storage at 0x1009292c; its descriptive name follows SetLastServerQueried and its subnet uses.
// R6GameService.dll data @ 1009292c : native storage identity retained.
extern FString GLastServerQueriedAddress;

// Destroys the shared last-server address through the imported FString destructor.
// R6GameService.dll @ 1006ac80 : cdecl exit callback; native tail jump to Core import 0x1006b090.
void __cdecl DestroyLastServerQueriedAddress(void)
{
  FString::~FString(&GLastServerQueriedAddress);
}

// Constructs the last-server address and registers its exit cleanup; registration failure is not checked.
// R6GameService.dll @ 1006a950 : referenced by initializer-table word 0x1008c0ec; no stack arguments.
void __cdecl InitializeLastServerQueriedAddress(void)
{
  FString::FString(&GLastServerQueriedAddress);
  _atexit(DestroyLastServerQueriedAddress);
}

// R6GameService.dll @ 1006ad30 : global exit cleanup
// Passes global array 0x10092e98 to its cleanup helper at 0x1000c080.
void global_state_DestroyGlobalArray4(void)
{
  DestroyStringRecordArray30((FArray *)&GServiceArray5);
  return;
}

// Clears the three-word global array header and registers its matching exit cleanup.
// R6GameService.dll @ 1006a8b0 : cdecl startup entry; returned EAX is the unchecked atexit status.
int __cdecl InitializeGlobalArray(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray5);
  return _atexit(global_state_DestroyGlobalArray4);
}

// R6GameService.dll @ 1006ad00 : global exit cleanup
// Passes global array 0x100923e8 to its cleanup helper at 0x1000b3d0.
void global_state_DestroyGlobalArray(void)
{
  unreal_array_support_DestroyArrayStorage2((FArray *)&GServiceArray3);
  return;
}

// Clears the three-word global array header and registers its matching exit cleanup.
// R6GameService.dll @ 1006a8d0 : cdecl startup entry; returned EAX is the unchecked atexit status.
int __cdecl global_state_InitializeGlobalArray(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray3);
  return _atexit(global_state_DestroyGlobalArray);
}

// R6GameService.dll @ 1006ad10 : global exit cleanup
// Passes global array 0x1009239c to its cleanup helper at 0x1000b470.
void global_state_DestroyGlobalArray2(void)
{
  unreal_array_support_DestroyArrayStorage3((FArray *)&GServiceArray1);
  return;
}

// Clears the three-word global array header and registers its matching exit cleanup.
// R6GameService.dll @ 1006a8f0 : cdecl startup entry; returned EAX is the unchecked atexit status.
int __cdecl global_state_InitializeGlobalArray2(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray1);
  return _atexit(global_state_DestroyGlobalArray2);
}

// R6GameService.dll @ 1006ad20 : global exit cleanup
// Passes global array 0x100923c4 to its cleanup helper at 0x1000b510.
void global_state_DestroyGlobalArray3(void)
{
  unreal_array_support_DestroyArrayStorage4((FArray *)&GServiceArray2);
  return;
}

// Clears the three-word global array header and registers its matching exit cleanup.
// R6GameService.dll @ 1006a910 : cdecl startup entry; returned EAX is the unchecked atexit status.
int __cdecl global_state_InitializeGlobalArray3(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray2);
  return _atexit(global_state_DestroyGlobalArray3);
}

// R6GameService.dll @ 1006ace0 : global exit cleanup
// Passes global array 0x10092e88 to its cleanup helper at 0x100021a0.
void DestroyGlobalArray(void)
{
  DestroyArrayStorage((FArray *)&GServiceArray4);
  return;
}

// Clears the three-word global array header and registers its matching exit cleanup.
// R6GameService.dll @ 1006a930 : cdecl startup entry; returned EAX is the unchecked atexit status.
int __cdecl global_state_InitializeGlobalArray4(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray4);
  return _atexit(DestroyGlobalArray);
}

// Initializes the exported event names through the shared receiver-preserving initializer.
// R6GameService.dll @ 1006a8a0 : ECX=0x10092ea8, tail jump 0x10005270; startup caller ignores EAX.
uint __cdecl InitializeGlobalEventNames(void)
{
  return InitializeR6GameServiceEventNames(0x10092ea8);
}

// Points the shared global slot at its selected static storage block.
// R6GameService.dll @ 1006a3b0 : one pointer store, no arguments or local EH guard.
void __cdecl InitializeGlobalPointer(void)
{
  *(void **)0x100923e0 = (void *)0x10091e88;
}

// R6GameService.dll @ 1006ac90 : global exit cleanup
// Destroys the global FString at 0x100923ac through Core import slot 1006b090.
void DestroyGlobalString(void)
{
  FString::~FString((FString *)&GServiceString1);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006a970 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl InitializeGlobalString(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString1);
  return _atexit(DestroyGlobalString);
}

// R6GameService.dll @ 1006aca0 : global exit cleanup
// Destroys the global FString at 0x10092e64 through Core import slot 1006b090.
void global_state_DestroyGlobalString(void)
{
  FString::~FString((FString *)&GServiceString3);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006a990 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString3);
  return _atexit(global_state_DestroyGlobalString);
}

// R6GameService.dll @ 1006acb0 : global exit cleanup
// Destroys the global FString at 0x1009291c through Core import slot 1006b090.
void global_state_DestroyGlobalString2(void)
{
  FString::~FString((FString *)&GServiceString2);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006a9b0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString2(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString2);
  return _atexit(global_state_DestroyGlobalString2);
}

// R6GameService.dll @ 1006acf0 : global exit cleanup
// Calls slot +8 on the nonnull first-word object at 0x10092ea4 through its vtable slot +8; leaves storage intact.
void ReleaseGlobalFirstWordObject(void)
{
  // Helper10007ea0 preserves the native call shape: ECX holds the table, object is on the stack.
  CallThirdSlotForFirstWordObject(reinterpret_cast<int *>(R6GameServiceAddresses::GGSClientInterface));
  return;
}

// Initializes the global pointerslot storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aa00 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl InitializeGlobalPointerSlot(void)
{
  ClearFirstWord((undefined4 *)R6GameServiceAddresses::GGSClientInterface);
  return _atexit(ReleaseGlobalFirstWordObject);
}

// R6GameService.dll @ 1006acd0 : global exit cleanup
// Passes global 0x10092e74 to destructor10014940, which calls SDK ordinal116 before helper100148a0.
void DestroyGlobalObject(void)
{
  // Native ECX is the object address; the wrapper supplies no stack arguments.
  using NativeDestructor = void (__thiscall *)(void *);
  reinterpret_cast<NativeDestructor>(R6GameServiceAddresses::CleanupWinsockAndPingRequests)(reinterpret_cast<void *>(0x10092e74));
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aa20 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray5(void)
{
  InitializePingRequestArray((undefined4 *)0x10092e74);
  return _atexit(DestroyGlobalObject);
}

// R6GameService.dll @ 1006ada0 : global exit cleanup
// Passes global array 0x10093470 to its element-aware destructor at 0x1000f150.
void global_state_DestroyGlobalArray5(void)
{
  unreal_array_support_DestroyArrayStorage5((FArray *)&GServiceArray8);
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aa40 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray6(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray8);
  return _atexit(global_state_DestroyGlobalArray5);
}

// R6GameService.dll @ 1006adb0 : global exit cleanup
// Passes global array 0x10093464 to its element-aware destructor at 0x1000f150.
void global_state_DestroyGlobalArray6(void)
{
  unreal_array_support_DestroyArrayStorage5((FArray *)&GServiceArray7);
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aa60 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray7(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray7);
  return _atexit(global_state_DestroyGlobalArray6);
}

// R6GameService.dll @ 1006adc0 : global exit cleanup
// Passes global array 0x1009347c to its element-aware destructor at 0x10002a10.
void global_state_DestroyGlobalArray7(void)
{
  DestroyFStringArray((FArray *)&GServiceString7);
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aa80 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray8(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceString7);
  return _atexit(global_state_DestroyGlobalArray7);
}

// R6GameService.dll @ 1006add0 : global exit cleanup
// Passes global array 0x10093458 to its element-aware destructor at 0x10002a10.
void global_state_DestroyGlobalArray8(void)
{
  DestroyFStringArray((FArray *)&GServiceString6);
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aaa0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray9(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceString6);
  return _atexit(global_state_DestroyGlobalArray8);
}

// R6GameService.dll @ 1006ad40 : global exit cleanup
// Destroys the global FString at 0x10093494 through Core import slot 1006b090.
void global_state_DestroyGlobalString3(void)
{
  FString::~FString((FString *)&GServiceString9);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aac0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString3(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString9);
  return _atexit(global_state_DestroyGlobalString3);
}

// R6GameService.dll @ 1006ad50 : global exit cleanup
// Destroys the global FString at 0x1009344c through Core import slot 1006b090.
void global_state_DestroyGlobalString4(void)
{
  FString::~FString((FString *)&GServiceString5);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aae0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString4(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString5);
  return _atexit(global_state_DestroyGlobalString4);
}

// R6GameService.dll @ 1006ad60 : global exit cleanup
// Destroys the global FString at 0x10093488 through Core import slot 1006b090.
void global_state_DestroyGlobalString5(void)
{
  FString::~FString((FString *)&GServiceString8);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006ab00 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString5(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString8);
  return _atexit(global_state_DestroyGlobalString5);
}

// R6GameService.dll @ 1006ad70 : global exit cleanup
// Destroys the global FString at 0x10093440 through Core import slot 1006b090.
void global_state_DestroyGlobalString6(void)
{
  FString::~FString((FString *)&GServiceString4);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006ab20 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString6(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString4,L"");
  return _atexit(global_state_DestroyGlobalString6);
}

// R6GameService.dll @ 1006ad80 : global exit cleanup
// Destroys the global FString at 0x100934ac through Core import slot 1006b090.
void global_state_DestroyGlobalString7(void)
{
  FString::~FString((FString *)&GServiceString11);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006ab40 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString7(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString11,L"");
  return _atexit(global_state_DestroyGlobalString7);
}

// R6GameService.dll @ 1006ad90 : global exit cleanup
// Destroys the global FString at 0x100934a0 through Core import slot 1006b090.
void global_state_DestroyGlobalString8(void)
{
  FString::~FString((FString *)&GServiceString10);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006ab60 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString8(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString10);
  return _atexit(global_state_DestroyGlobalString8);
}

// R6GameService.dll @ 1006ade0 : global exit cleanup
// Destroys the global FString at 0x100939dc through Core import slot 1006b090.
void global_state_DestroyGlobalString9(void)
{
  FString::~FString((FString *)&GServiceString12);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006ab80 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString9(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString12);
  return _atexit(global_state_DestroyGlobalString9);
}

// R6GameService.dll @ 1006ae00 : remove global 8-byte array elements and release its storage
void global_state_DestroyGlobalArray9(void)
{
  unreal_array_support_DestroyArrayStorage6((FArray *)&GServiceArray10);
  return;
}

// Initializes the global array storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006aba0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalArray10(void)
{
  InitializeThreeWords((undefined4 *)R6GameServiceAddresses::GServiceArray10);
  return _atexit(global_state_DestroyGlobalArray9);
}

// R6GameService.dll @ 1006adf0 : global exit cleanup
// Destroys the global FString at 0x10093b44 through Core import slot 1006b090.
void global_state_DestroyGlobalString10(void)
{
  FString::~FString((FString *)&GServiceString13);
  return;
}

// Initializes the global string storage and registers its matching exit callback without checking failure.
// R6GameService.dll @ 1006abc0 : cdecl startup entry; EAX retains the atexit registration status.
int __cdecl global_state_InitializeGlobalString10(void)
{
  FString::FString((FString *)R6GameServiceAddresses::GServiceString13);
  return _atexit(global_state_DestroyGlobalString10);
}

// R6GameService.dll @ 1006ac20 : destroy the wide string stream rooted at 0x10091540
// Destroys the stream through its +0x54 virtual-base receiver, then destroys that basic_ios base.
// Initialization at 1006a0b0 passes 10091540 to constructor10004880; cleanup ECX is 10091594.
void DestroyGlobalWideStringStream(void)
{
  DestroyWideLogStreamFromIos(R6GameServiceAddresses::GWideLogStream);
  std::basic_ios<unsigned_short,std::char_traits<unsigned_short>_>::
  ~basic_ios<unsigned_short,std::char_traits<unsigned_short>_>
            ((basic_ios<unsigned_short,std::char_traits<unsigned_short>_> *)&GWideLogStream);
  return;
}

// Constructs the global wide output stream with its virtual base and registers its paired destructor.
// R6GameService.dll @ 1006a0b0 : cdecl startup entry; atexit status is not checked.
int __cdecl InitializeGlobalWideOutputStream(void)
{
  ConstructWideOutputStream((void *)0x10091540,1);
  return _atexit(DestroyGlobalWideStringStream);
}

// Initializes one global pair of imported wide stream references through the shared leaf body.
// R6GameService.dll @ 1006abe0 : ECX=0x10093d20, tail jump 0x100370c0.
undefined4 * __cdecl InitializeGlobalWideStreamReferences(void)
{
  return InitializeWideStreamReferences((undefined4 *)0x10093d20);
}

// Initializes the second global pair of imported wide stream references through the shared leaf body.
// R6GameService.dll @ 1006abf0 : ECX=0x1009452c, tail jump 0x100370c0.
undefined4 * __cdecl global_state_InitializeGlobalWideStreamReferences(void)
{
  return InitializeWideStreamReferences((undefined4 *)0x1009452c);
}

// Transfers startup to the separate native initializer entry without duplicating its body.
// R6GameService.dll @ 1002d250 : tail jump 0x1002d260; the startup-table caller ignores the result.
__declspec(naked) void ForwardStartupInitializer(void)
{
  __asm {
    jmp R6GameServiceAddresses::InitializeInterfaceAddressPrefixes
  }
}

// Lazily constructs the shared CD-key codec after setting its byte guard and registers its exit callback.
// R6GameService.dll @ 1002d140 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void * __cdecl GetDefaultTaggedPayloadCodec(void)
{
  __asm {
    // The byte guard is set before construction; no synchronization or retry-after-failure reset is present.
    mov    cl,BYTE PTR ds:0x10093c24
    mov    eax,0x1
    test   al,cl
    jne Branch1
    mov    dl,cl
    push   edi
    or     dl,al
    push   eax
    mov    edi,R6GameServiceAddresses::TextSKJDHF0maoijfn4i8AJdnv1jaldifar93ASDfoHjhC4jhflasnF3fnd
    or     ecx,0xffffffff
    xor    eax,eax
    mov    BYTE PTR ds:0x10093c24,dl
    // Scan native key to NUL and truncate length to16 bits; atexit is cdecl and caller removes its argument.
    repnz scas al,BYTE PTR es:[edi]
    not    ecx
    dec    ecx
    and    ecx,0xffff
    push   ecx
    push   R6GameServiceAddresses::TextSKJDHF0maoijfn4i8AJdnv1jaldifar93ASDfoHjhC4jhflasnF3fnd
    mov    ecx,0x10093c14
    call   R6GameServiceAddresses::ConstructCipherModuleBlowfish
    push   R6GameServiceAddresses::DestroyDefaultTaggedPayloadCodec
    call   R6GameServiceAddresses::_atexit
    add    esp,0x4
    pop    edi
  Branch1:
    mov    eax,0x10093c14
    ret
  }
}

// Selects the shared CD-key codec receiver and tail-forwards its cleanup.
// R6GameService.dll @ 1002d1a0 : complete native frame/access order, calling convention and raw ABI retained.
__declspec(naked) void __cdecl DestroyDefaultTaggedPayloadCodec(void)
{
  __asm {
    mov    ecx,0x10093c14
    jmp    R6GameServiceAddresses::DestroyCipherModuleBlowfish
  }
}

// R6GameService.dll @ 1006a9d0 : initialize the BSTR stored at 0x100923bc
// Converts the empty ANSI string, throws E_OUTOFMEMORY on failure, then registers its exit cleanup.
void InitializeGlobalBstr(void)
{
  GServiceBstr = ConvertAnsiToBstr("",-1);
  if (GServiceBstr == (LPWSTR)0x0) {
    ThrowAtlStatus(0x8007000e);
  }
  _atexit(ForwardGlobalWordToOleautOrdinal6);
  return;
}

// Pass CURRENT global923bc to OLEAUT32 ordinal6 using the native stack argument; do not clear the global.
// Native exit callback preserves incidental imported return registers; no own guard or local release.
// R6GameService.dll @ 1006acc0 : complete native control/access order and raw ABI retained.
__declspec(naked) void __cdecl ForwardGlobalWordToOleautOrdinal6(void)
{
  __asm {
    mov    eax,ds:R6GameServiceAddresses::GServiceBstr
    push    eax
    call    DWORD PTR ds:R6GameServiceAddresses::OLEAUT32_SysFreeStringSlot
    ret
  }
}
