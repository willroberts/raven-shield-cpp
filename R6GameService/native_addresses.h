#pragma once

// Preferred addresses in the selected PE32 image, not new storage or host function/member pointers.
// Unsigned 32-bit bindings preserve native table words, relocations and compiler-specific entry contracts.
// Private/compiler names are descriptive; neutral ordinals distinguish unresolved private identities.
// Interior cases remain in their canonical parents. Import names denote the live four-byte IAT slots.
// In noncompiled C++ reference views, [[r6abi::register_input("...")]] binds a logical input to that native register.
// Such annotated inputs are not native stack arguments; the address marker records the physical entry/RET contract.
// [[r6abi::register_output("...")]] on a local binds its final value to that volatile register on normal return.
// [[r6abi::register_snapshot("...")]] binds a local to the current register at its declaration, including call clobbers.
// The annotations describe machine evidence, not a recovered original prototype or a compiler-supported extension.
namespace R6GameServiceAddresses {
// R6GameService.dll image-base @ 10000000
constexpr unsigned int ModuleImageBase = 0x10000000;
// R6GameService.dll code @ 10001000
constexpr unsigned int GetLegacyAnsiCodePage = 0x10001000;
// R6GameService.dll code @ 10001060
constexpr unsigned int GetThreadAnsiCodePageSelector = 0x10001060;
// R6GameService.dll code @ 10001070
constexpr unsigned int SelectAndInvokeAnsiCodePage = 0x10001070;
// R6GameService.dll code @ 100010c0
constexpr unsigned int ClearCriticalSectionStorage = 0x100010c0;
// R6GameService.dll code @ 100010e0
constexpr unsigned int InitializeCriticalSectionWithStatus = 0x100010e0;
// R6GameService.dll code @ 10001114
constexpr unsigned int FilterCriticalSectionInitialization = 0x10001114;
// R6GameService.dll code @ 10001124
constexpr unsigned int HandleCriticalSectionInitialization = 0x10001124;
// R6GameService.dll interior-code @ 10001140
constexpr unsigned int critical_section_supportBranch1 = 0x10001140;
// R6GameService.dll code @ 10001160
constexpr unsigned int AllocateTaggedBytesCdecl = 0x10001160;
// R6GameService.dll code @ 10001180
constexpr unsigned int FreeThroughGlobalAllocator = 0x10001180;
// R6GameService.dll code @ 100011a0
constexpr unsigned int UeviLPatchService_StaticClass = 0x100011a0;
// R6GameService.dll code @ 100011b0
constexpr unsigned int UeviLPatchService_operator_new = 0x100011b0;
// R6GameService.dll code @ 100011e0
constexpr unsigned int UeviLPatchService__UeviLPatchService = 0x100011e0;
// R6GameService.dll code @ 10001250
constexpr unsigned int UeviLPatchService_UeviLPatchService = 0x10001250;
// R6GameService.dll code @ 10001270
constexpr unsigned int UeviLPatchService_UeviLPatchService2 = 0x10001270;
// R6GameService.dll code @ 100012a0
constexpr unsigned int UeviLPatchService_operator = 0x100012a0;
// R6GameService.dll code @ 100012c0
constexpr unsigned int UeviLPatchService_VectorDeletingDestructor = 0x100012c0;
// R6GameService.dll code @ 10001320
constexpr unsigned int UR6ServerList_eventGetLobbyAndGroupID = 0x10001320;
// R6GameService.dll code @ 10001380
constexpr unsigned int UR6ServerList_StaticClass = 0x10001380;
// R6GameService.dll code @ 10001390
constexpr unsigned int UR6ServerList_operator_new = 0x10001390;
// R6GameService.dll code @ 100013c0
constexpr unsigned int UR6LanServers_StaticClass = 0x100013c0;
// R6GameService.dll code @ 100013d0
constexpr unsigned int UR6LanServers_operator_new = 0x100013d0;
// R6GameService.dll code @ 10001400
constexpr unsigned int UR6GSServers_eventHandleNewLobbyConnection = 0x10001400;
// R6GameService.dll code @ 10001440
constexpr unsigned int UR6GSServers_eventEndOfRoundDataSent = 0x10001440;
// R6GameService.dll code @ 10001470
constexpr unsigned int UR6GSServers_eventFillCreateGameInfo = 0x10001470;
// R6GameService.dll code @ 100014b0
constexpr unsigned int UR6GSServers_eventGetMaxAvailPorts = 0x100014b0;
// R6GameService.dll code @ 100014f0
constexpr unsigned int UR6GSServers_eventInitializeMod = 0x100014f0;
// R6GameService.dll code @ 10001520
constexpr unsigned int UR6GSServers_StaticClass = 0x10001520;
// R6GameService.dll code @ 10001530
constexpr unsigned int UR6GSServers_operator_new = 0x10001530;
// R6GameService.dll code @ 10001560
constexpr unsigned int UR6GSServers_InternalConstructor = 0x10001560;
// R6GameService.dll code @ 10001570
constexpr unsigned int DestroyFStringAt04 = 0x10001570;
// R6GameService.dll code @ 10001580
constexpr unsigned int FString__FString = 0x10001580;
// R6GameService.dll code @ 10001590
constexpr unsigned int UR6ModGSInfo_StaticClass = 0x10001590;
// R6GameService.dll code @ 100015a0
constexpr unsigned int UR6ModGSInfo_operator_new = 0x100015a0;
// R6GameService.dll code @ 100015d0
constexpr unsigned int AllocateInternalObject = 0x100015d0;
// R6GameService.dll code @ 100015e0
constexpr unsigned int UR6ModGSInfo__UR6ModGSInfo = 0x100015e0;
// R6GameService.dll code @ 10001640
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfo = 0x10001640;
// R6GameService.dll code @ 10001690
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfo2 = 0x10001690;
// R6GameService.dll code @ 10001720
constexpr unsigned int UR6ModGSInfo_operator = 0x10001720;
// R6GameService.dll code @ 10001770
constexpr unsigned int DeleteUR6ModGSInfo = 0x10001770;
// R6GameService.dll code @ 100017d0
constexpr unsigned int EncryptFStringWithUeviLCore = 0x100017d0;
// R6GameService.dll code @ 10001883
constexpr unsigned int ForwardEncryptWideError = 0x10001883;
// R6GameService.dll code @ 10001897
constexpr unsigned int ReportEncryptException = 0x10001897;
// R6GameService.dll code @ 100018c0
constexpr unsigned int DecryptFStringWithUeviLCore = 0x100018c0;
// R6GameService.dll code @ 10001966
constexpr unsigned int ForwardDecryptWideError = 0x10001966;
// R6GameService.dll code @ 1000197a
constexpr unsigned int ReportDecryptException = 0x1000197a;
// R6GameService.dll code @ 100019a0
constexpr unsigned int IsCDKeyValidOnMachine = 0x100019a0;
// R6GameService.dll code @ 10001a12
constexpr unsigned int ForwardMachineValidationWideError = 0x10001a12;
// R6GameService.dll code @ 10001a26
constexpr unsigned int ReportMachineValidationException = 0x10001a26;
// R6GameService.dll code @ 10001a50
constexpr unsigned int CopyStringPairRecord18 = 0x10001a50;
// R6GameService.dll code @ 10001ab0
constexpr unsigned int CopyStringRecord2C = 0x10001ab0;
// R6GameService.dll code @ 10001b30
constexpr unsigned int RemoveFourByteArrayElements = 0x10001b30;
// R6GameService.dll code @ 10001bb0
constexpr unsigned int UnlockMutexIfPresent = 0x10001bb0;
// R6GameService.dll code @ 10001bd0
constexpr unsigned int DestroyStringPairRecord18 = 0x10001bd0;
// R6GameService.dll code @ 10001c20
constexpr unsigned int DestroyStringRecord2C = 0x10001c20;
// R6GameService.dll code @ 10001c70
constexpr unsigned int GetOrCreateUnsignedShortCtypeFacet = 0x10001c70;
// R6GameService.dll code @ 10001d70
constexpr unsigned int UeviLPatchService_InternalConstructor = 0x10001d70;
// R6GameService.dll code @ 10001d80
constexpr unsigned int UR6GSServers_eventTempGetPBConnectStatus = 0x10001d80;
// R6GameService.dll code @ 10001e20
constexpr unsigned int UR6GSServers_eventIsGlobalIDBanned = 0x10001e20;
// R6GameService.dll code @ 10001ec0
constexpr unsigned int UR6GSServers_eventProcessServerMsg = 0x10001ec0;
// R6GameService.dll code @ 10001f50
constexpr unsigned int UR6GSServers_eventGetConsoleStoreIP = 0x10001f50;
// R6GameService.dll code @ 10001ff0
constexpr unsigned int UR6GSServers_eventGetLocallyBoundIpAddr = 0x10001ff0;
// R6GameService.dll code @ 10002090
constexpr unsigned int UR6ModGSInfo_InternalConstructor = 0x10002090;
// R6GameService.dll code @ 100020a0
constexpr unsigned int ConstructFStringArray = 0x100020a0;
// R6GameService.dll code @ 10002130
constexpr unsigned int ConstructDwordArray = 0x10002130;
// R6GameService.dll code @ 100021a0
constexpr unsigned int DestroyArrayStorage = 0x100021a0;
// R6GameService.dll code @ 10002230
constexpr unsigned int CopyDwordArray = 0x10002230;
// R6GameService.dll code @ 100022a0
constexpr unsigned int ConstructStringPairArray18 = 0x100022a0;
// R6GameService.dll code @ 10002330
constexpr unsigned int ConstructStringRecordArray2C = 0x10002330;
// R6GameService.dll code @ 100023c0
constexpr unsigned int ConstructSevenWordRecordArray = 0x100023c0;
// R6GameService.dll code @ 10002470
constexpr unsigned int ConstructWideStreamSentry = 0x10002470;
// R6GameService.dll code @ 10002500
constexpr unsigned int DestroyWideStreamSentry = 0x10002500;
// R6GameService.dll code @ 10002570
constexpr unsigned int RemoveFStringRange12 = 0x10002570;
// R6GameService.dll code @ 10002610
constexpr unsigned int ResetFStringArray = 0x10002610;
// R6GameService.dll code @ 10002660
constexpr unsigned int CopyFStringArray = 0x10002660;
// R6GameService.dll code @ 100026d0
constexpr unsigned int CopySevenWordRecordArray = 0x100026d0;
// R6GameService.dll code @ 10002760
constexpr unsigned int ResetStringPairArray18 = 0x10002760;
// R6GameService.dll code @ 100027b0
constexpr unsigned int ResetStringRecordArray2C = 0x100027b0;
// R6GameService.dll code @ 10002800
constexpr unsigned int InsertPaddedWideString = 0x10002800;
// R6GameService.dll code @ 1000294a
constexpr unsigned int CatchWideStringInsert = 0x1000294a;
// R6GameService.dll code @ 10002974
constexpr unsigned int ResumeWideStringInsert = 0x10002974;
// R6GameService.dll code @ 10002977
constexpr unsigned int FinishWideStringInsert = 0x10002977;
// R6GameService.dll code @ 10002a00
constexpr unsigned int ForwardToArrayDestructor = 0x10002a00;
// R6GameService.dll code @ 10002a10
constexpr unsigned int DestroyFStringArray = 0x10002a10;
// R6GameService.dll code @ 10002a60
constexpr unsigned int unreal_array_support_DestroyArrayStorage = 0x10002a60;
// R6GameService.dll code @ 10002af0
constexpr unsigned int RemoveStringPairRange18 = 0x10002af0;
// R6GameService.dll code @ 10002b90
constexpr unsigned int CopyStringPairArray18 = 0x10002b90;
// R6GameService.dll code @ 10002c00
constexpr unsigned int RemoveStringRecordRange2C = 0x10002c00;
// R6GameService.dll code @ 10002ca0
constexpr unsigned int CopyStringRecordArray2C = 0x10002ca0;
// R6GameService.dll code @ 10002d10
constexpr unsigned int ForwardArrayDestroy = 0x10002d10;
// R6GameService.dll code @ 10002d20
constexpr unsigned int unreal_array_support_ForwardToArrayDestructor = 0x10002d20;
// R6GameService.dll code @ 10002d30
constexpr unsigned int DestroyArray18ByteElements = 0x10002d30;
// R6GameService.dll code @ 10002d80
constexpr unsigned int DestroyArray2CByteElements = 0x10002d80;
// R6GameService.dll code @ 10002dd0
constexpr unsigned int AssignSTGameData = 0x10002dd0;
// R6GameService.dll code @ 10002f60
constexpr unsigned int unreal_array_support_ForwardArrayDestroy = 0x10002f60;
// R6GameService.dll code @ 10002f70
constexpr unsigned int unreal_array_support_ForwardArrayDestroy2 = 0x10002f70;
// R6GameService.dll code @ 10002f80
constexpr unsigned int AssignSTGameServer = 0x10002f80;
// R6GameService.dll code @ 10003020
constexpr unsigned int DestroySTGameData = 0x10003020;
// R6GameService.dll code @ 100030f0
constexpr unsigned int ConstructServerGameData = 0x100030f0;
// R6GameService.dll code @ 10003190
constexpr unsigned int CopyConstructSTGameData = 0x10003190;
// R6GameService.dll code @ 10003380
constexpr unsigned int DestroySTGameServer = 0x10003380;
// R6GameService.dll code @ 100033f0
constexpr unsigned int ConstructServerInfo = 0x100033f0;
// R6GameService.dll code @ 10003460
constexpr unsigned int CopyConstructSTGameServer = 0x10003460;
// R6GameService.dll code @ 10003530
constexpr unsigned int CopyConstructSTGameServerArray = 0x10003530;
// R6GameService.dll code @ 100035d0
constexpr unsigned int EmptySTGameServerArray = 0x100035d0;
// R6GameService.dll code @ 10003620
constexpr unsigned int RemoveSTGameServerRange = 0x10003620;
// R6GameService.dll code @ 100036c0
constexpr unsigned int AssignSTGameServerArray = 0x100036c0;
// R6GameService.dll code @ 10003730
constexpr unsigned int DestroyArrayDCByteElements = 0x10003730;
// R6GameService.dll code @ 10003780
constexpr unsigned int UR6ServerList_operator = 0x10003780;
// R6GameService.dll code @ 10003860
constexpr unsigned int unreal_array_support_ForwardArrayDestroy3 = 0x10003860;
// R6GameService.dll code @ 10003870
constexpr unsigned int UR6LanServers_operator = 0x10003870;
// R6GameService.dll code @ 100038c0
constexpr unsigned int UR6GSServers_operator = 0x100038c0;
// R6GameService.dll code @ 10003ae0
constexpr unsigned int UR6ServerList__UR6ServerList = 0x10003ae0;
// R6GameService.dll code @ 10003ba0
constexpr unsigned int UR6ServerList_UR6ServerList = 0x10003ba0;
// R6GameService.dll code @ 10003c10
constexpr unsigned int UR6ServerList_UR6ServerList2 = 0x10003c10;
// R6GameService.dll code @ 10003d40
constexpr unsigned int DeleteUR6ServerList = 0x10003d40;
// R6GameService.dll code @ 10003db0
constexpr unsigned int UR6LanServers__UR6LanServers = 0x10003db0;
// R6GameService.dll code @ 10003e00
constexpr unsigned int UR6LanServers_UR6LanServers = 0x10003e00;
// R6GameService.dll code @ 10003e20
constexpr unsigned int UR6LanServers_UR6LanServers2 = 0x10003e20;
// R6GameService.dll code @ 10003e70
constexpr unsigned int DeleteUR6LanServers = 0x10003e70;
// R6GameService.dll code @ 10003ee0
constexpr unsigned int UR6GSServers__UR6GSServers = 0x10003ee0;
// R6GameService.dll code @ 10003fe0
constexpr unsigned int UR6GSServers_UR6GSServers = 0x10003fe0;
// R6GameService.dll code @ 10004270
constexpr unsigned int DeleteUR6GSServers = 0x10004270;
// R6GameService.dll code @ 100042e0
constexpr unsigned int UR6ServerList_InternalConstructor = 0x100042e0;
// R6GameService.dll code @ 100042f0
constexpr unsigned int UR6LanServers_InternalConstructor = 0x100042f0;
// R6GameService.dll code @ 10004300
constexpr unsigned int _basic_stringbuf = 0x10004300;
// R6GameService.dll code @ 10004310
constexpr unsigned int UeviLPatchService_execGetDownloadProgress = 0x10004310;
// R6GameService.dll code @ 1000457b
constexpr unsigned int RethrowPatchProgressWidePointer = 0x1000457b;
// R6GameService.dll code @ 1000458f
constexpr unsigned int ReportPatchProgressException = 0x1000458f;
// R6GameService.dll code @ 100045e0
constexpr unsigned int UeviLPatchService_execGetExitCause = 0x100045e0;
// R6GameService.dll code @ 10004667
constexpr unsigned int RethrowPatchExitCauseWidePointer = 0x10004667;
// R6GameService.dll code @ 1000467b
constexpr unsigned int ReportPatchExitCauseException = 0x1000467b;
// R6GameService.dll code @ 100046d0
constexpr unsigned int UeviLPatchService_execCanRunUpdateService = 0x100046d0;
// R6GameService.dll code @ 10004766
constexpr unsigned int RethrowPatchAccessBridgeWidePointer = 0x10004766;
// R6GameService.dll code @ 1000477a
constexpr unsigned int ReportPatchAccessBridgeException = 0x1000477a;
// R6GameService.dll code @ 100047d0
constexpr unsigned int DeleteWideLogStringBuffer = 0x100047d0;
// R6GameService.dll code @ 10004800
constexpr unsigned int DestroyWideLogStreamFromIos = 0x10004800;
// R6GameService.dll code @ 10004850
constexpr unsigned int UeviLPatchService_FinalDestroy = 0x10004850;
// R6GameService.dll code @ 10004880
constexpr unsigned int ConstructWideOutputStream = 0x10004880;
// R6GameService.dll code @ 10004920
constexpr unsigned int InsertAnsiTextIntoWideStream = 0x10004920;
// R6GameService.dll code @ 10004a9e
constexpr unsigned int CatchAnsiWideInsertion = 0x10004a9e;
// R6GameService.dll code @ 10004ac8
constexpr unsigned int ResumeAnsiWideInsertion = 0x10004ac8;
// R6GameService.dll code @ 10004acb
constexpr unsigned int FinishWideStreamInsertCleanup = 0x10004acb;
// R6GameService.dll interior-code @ 10004acd
constexpr unsigned int WideLogConstructorResume = 0x10004acd;
// R6GameService.dll code @ 10004b40
constexpr unsigned int LogAndAbortUpdateService = 0x10004b40;
// R6GameService.dll code @ 10004b80
constexpr unsigned int UeviLPatchService_GetPatchServiceState = 0x10004b80;
// R6GameService.dll code @ 10004cf3
constexpr unsigned int RethrowPatchStatePollWidePointer = 0x10004cf3;
// R6GameService.dll code @ 10004d07
constexpr unsigned int ReportPatchStatePollException = 0x10004d07;
// R6GameService.dll code @ 10004d30
constexpr unsigned int UeviLPatchService_execGetState = 0x10004d30;
// R6GameService.dll code @ 10004d99
constexpr unsigned int RethrowPatchStateWidePointer = 0x10004d99;
// R6GameService.dll code @ 10004dad
constexpr unsigned int ReportPatchStateException = 0x10004dad;
// R6GameService.dll code @ 10004dd0
constexpr unsigned int UeviLPatchService_execAbortPatchService = 0x10004dd0;
// R6GameService.dll code @ 10004e60
constexpr unsigned int RethrowPatchAbortBridgeWidePointer = 0x10004e60;
// R6GameService.dll code @ 10004e74
constexpr unsigned int ReportPatchAbortBridgeException = 0x10004e74;
// R6GameService.dll code @ 10004ec0
constexpr unsigned int GetAndClearWideLogBuffer = 0x10004ec0;
// R6GameService.dll code @ 10004f60
constexpr unsigned int WriteWideTextToUpdateServiceLog = 0x10004f60;
// R6GameService.dll code @ 10004ff0
constexpr unsigned int DeleteWideLogStreamFromIos = 0x10004ff0;
// R6GameService.dll code @ 10005030
constexpr unsigned int UeviLPatchService_StartPatch = 0x10005030;
// R6GameService.dll code @ 100050e6
constexpr unsigned int RethrowPatchStartupWidePointer = 0x100050e6;
// R6GameService.dll code @ 100050fa
constexpr unsigned int ReportPatchStartupException = 0x100050fa;
// R6GameService.dll code @ 10005120
constexpr unsigned int UeviLPatchService_execStartPatch = 0x10005120;
// R6GameService.dll code @ 10005188
constexpr unsigned int RethrowPatchStartBridgeWidePointer = 0x10005188;
// R6GameService.dll code @ 1000519c
constexpr unsigned int ReportPatchStartBridgeException = 0x1000519c;
// R6GameService.dll code @ 100051f0
constexpr unsigned int ThrowAtlStatus = 0x100051f0;
// R6GameService.dll code @ 10005210
constexpr unsigned int ReleaseStoredBstr = 0x10005210;
// R6GameService.dll code @ 10005220
constexpr unsigned int ReadCycleTimeSeconds = 0x10005220;
// R6GameService.dll code @ 10005270
constexpr unsigned int InitializeR6GameServiceEventNames = 0x10005270;
// R6GameService.dll code @ 1000538b
constexpr unsigned int global_stateCatch = 0x1000538b;
// R6GameService.dll code @ 1000539f
constexpr unsigned int global_state_global_stateCatch = 0x1000539f;
// R6GameService.dll code @ 100053c0
constexpr unsigned int _DllMain_12 = 0x100053c0;
// R6GameService.dll code @ 100053e0
constexpr unsigned int ExtractLineValue = 0x100053e0;
// R6GameService.dll code @ 10005460
constexpr unsigned int UR6ModGSInfo_execNativeInitModInfo = 0x10005460;
// R6GameService.dll code @ 1000564e
constexpr unsigned int UR6ModGSInfoCatch = 0x1000564e;
// R6GameService.dll code @ 10005662
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoCatch = 0x10005662;
// R6GameService.dll code @ 10005680
constexpr unsigned int UR6GSServers_Destroy = 0x10005680;
// R6GameService.dll code @ 1000572d
constexpr unsigned int UR6GSServersCatch = 0x1000572d;
// R6GameService.dll code @ 10005741
constexpr unsigned int UR6GSServers_UR6GSServersCatch = 0x10005741;
// R6GameService.dll code @ 10005760
constexpr unsigned int HexDigitToValue = 0x10005760;
// R6GameService.dll code @ 10005980
constexpr unsigned int UR6GSServers_PingRequest = 0x10005980;
// R6GameService.dll code @ 10005a12
constexpr unsigned int UR6GSServers_UR6GSServersCatch2 = 0x10005a12;
// R6GameService.dll code @ 10005a26
constexpr unsigned int UR6GSServers_UR6GSServersCatch3 = 0x10005a26;
// R6GameService.dll code @ 10005a50
constexpr unsigned int UR6GSServers_PollPingManager = 0x10005a50;
// R6GameService.dll code @ 10005ab8
constexpr unsigned int UR6GSServers_UR6GSServersCatch4 = 0x10005ab8;
// R6GameService.dll code @ 10005acc
constexpr unsigned int UR6GSServers_UR6GSServersCatch5 = 0x10005acc;
// R6GameService.dll code @ 10005af0
constexpr unsigned int UR6ServerList_execNativeGetPingTime = 0x10005af0;
// R6GameService.dll code @ 10005ba7
constexpr unsigned int UR6ServerListCatch = 0x10005ba7;
// R6GameService.dll code @ 10005bbb
constexpr unsigned int UR6ServerList_UR6ServerListCatch = 0x10005bbb;
// R6GameService.dll code @ 10005be0
constexpr unsigned int UR6ServerList_execNativeGetPingTimeOut = 0x10005be0;
// R6GameService.dll code @ 10005c48
constexpr unsigned int UR6ServerList_UR6ServerListCatch2 = 0x10005c48;
// R6GameService.dll code @ 10005c5c
constexpr unsigned int UR6ServerList_UR6ServerListCatch3 = 0x10005c5c;
// R6GameService.dll code @ 10005c80
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPing = 0x10005c80;
// R6GameService.dll code @ 10005e00
constexpr unsigned int UR6GSServers_UR6GSServersCatch6 = 0x10005e00;
// R6GameService.dll code @ 10005e14
constexpr unsigned int UR6GSServers_UR6GSServersCatch7 = 0x10005e14;
// R6GameService.dll code @ 10005e40
constexpr unsigned int UR6GSServers_execNativeGetSeconds = 0x10005e40;
// R6GameService.dll code @ 10005ee2
constexpr unsigned int UR6GSServers_UR6GSServersCatch8 = 0x10005ee2;
// R6GameService.dll code @ 10005ef6
constexpr unsigned int UR6GSServers_UR6GSServersCatch9 = 0x10005ef6;
// R6GameService.dll code @ 10005f20
constexpr unsigned int UR6ServerList_execNativeGetMilliSeconds = 0x10005f20;
// R6GameService.dll code @ 10005f8a
constexpr unsigned int UR6ServerList_UR6ServerListCatch4 = 0x10005f8a;
// R6GameService.dll code @ 10005f9e
constexpr unsigned int UR6ServerList_UR6ServerListCatch5 = 0x10005f9e;
// R6GameService.dll code @ 10005fc0
constexpr unsigned int DeleteModuleVersionChain = 0x10005fc0;
// R6GameService.dll code @ 10005ff0
constexpr unsigned int ClearModuleVersionList = 0x10005ff0;
// R6GameService.dll code @ 10006030
constexpr unsigned int AppendModuleVersion = 0x10006030;
// R6GameService.dll code @ 100060a0
constexpr unsigned int FormatModuleVersionList = 0x100060a0;
// R6GameService.dll code @ 10006210
constexpr unsigned int UR6ServerList_execNativeGetMaxPlayers = 0x10006210;
// R6GameService.dll code @ 10006278
constexpr unsigned int UR6ServerList_UR6ServerListCatch6 = 0x10006278;
// R6GameService.dll code @ 1000628c
constexpr unsigned int UR6ServerList_UR6ServerListCatch7 = 0x1000628c;
// R6GameService.dll code @ 100062b0
constexpr unsigned int UR6GSServers_execGetMaxUbiServerNameSize = 0x100062b0;
// R6GameService.dll code @ 10006318
constexpr unsigned int UR6GSServers_UR6GSServersCatch10 = 0x10006318;
// R6GameService.dll code @ 1000632c
constexpr unsigned int UR6GSServers_UR6GSServersCatch11 = 0x1000632c;
// R6GameService.dll code @ 10006350
constexpr unsigned int AllocateGameServiceBytes = 0x10006350;
// R6GameService.dll code @ 10006370
constexpr unsigned int ResizeGameServiceBytes = 0x10006370;
// R6GameService.dll code @ 10006390
constexpr unsigned int TailFreeThroughGlobalAllocator = 0x10006390;
// R6GameService.dll code @ 100063a0
constexpr unsigned int UR6ServerList_SetOwnSvrPort = 0x100063a0;
// R6GameService.dll code @ 100063b0
constexpr unsigned int UR6ServerList_execNativeGetOwnSvrPort = 0x100063b0;
// R6GameService.dll code @ 1000641a
constexpr unsigned int UR6ServerList_UR6ServerListCatch8 = 0x1000641a;
// R6GameService.dll code @ 1000642e
constexpr unsigned int UR6ServerList_UR6ServerListCatch9 = 0x1000642e;
// R6GameService.dll code @ 10006450
constexpr unsigned int UR6GSServers_OnSameSubNet = 0x10006450;
// R6GameService.dll code @ 10006582
constexpr unsigned int UR6GSServers_UR6GSServersCatch12 = 0x10006582;
// R6GameService.dll code @ 10006596
constexpr unsigned int UR6GSServers_UR6GSServersCatch13 = 0x10006596;
// R6GameService.dll code @ 100065c0
constexpr unsigned int ReportServiceDownload = 0x100065c0;
// R6GameService.dll code @ 10006650
constexpr unsigned int UR6GSServers_UnInitMSClient = 0x10006650;
// R6GameService.dll code @ 100066e2
constexpr unsigned int UR6GSServers_UR6GSServersCatch14 = 0x100066e2;
// R6GameService.dll code @ 100066f6
constexpr unsigned int UR6GSServers_UR6GSServersCatch15 = 0x100066f6;
// R6GameService.dll code @ 10006720
constexpr unsigned int UR6GSServers_execUnInitializeMSClient = 0x10006720;
// R6GameService.dll code @ 1000678d
constexpr unsigned int UR6GSServers_UR6GSServersCatch16 = 0x1000678d;
// R6GameService.dll code @ 100067a1
constexpr unsigned int UR6GSServers_UR6GSServersCatch17 = 0x100067a1;
// R6GameService.dll code @ 100067c0
constexpr unsigned int UR6GSServers_execNativeGetMSClientInitialized = 0x100067c0;
// R6GameService.dll code @ 1000682a
constexpr unsigned int UR6GSServers_UR6GSServersCatch18 = 0x1000682a;
// R6GameService.dll code @ 1000683e
constexpr unsigned int UR6GSServers_UR6GSServersCatch19 = 0x1000683e;
// R6GameService.dll code @ 10006860
constexpr unsigned int UR6GSServers_IsMSClientIsInRequest = 0x10006860;
// R6GameService.dll code @ 10006870
constexpr unsigned int UR6GSServers_GetLoggedInUbiDotCom = 0x10006870;
// R6GameService.dll code @ 10006880
constexpr unsigned int UR6GSServers_PollMSClientCallbacks = 0x10006880;
// R6GameService.dll code @ 10006c55
constexpr unsigned int UR6GSServers_UR6GSServersCatch20 = 0x10006c55;
// R6GameService.dll code @ 10006c69
constexpr unsigned int UR6GSServers_UR6GSServersCatch21 = 0x10006c69;
// R6GameService.dll code @ 10006c90
constexpr unsigned int MSError = 0x10006c90;
// R6GameService.dll interior-code @ 10006cc8
constexpr unsigned int GMSErrorTargetsCase5 = 0x10006cc8;
// R6GameService.dll interior-code @ 10006cd6
constexpr unsigned int GMSErrorTargetsCase2 = 0x10006cd6;
// R6GameService.dll interior-code @ 10006ce4
constexpr unsigned int GMSErrorTargetsCase4 = 0x10006ce4;
// R6GameService.dll interior-code @ 10006cfc
constexpr unsigned int GMSErrorTargetsCase3 = 0x10006cfc;
// R6GameService.dll interior-code @ 10006d14
constexpr unsigned int GMSErrorTargetsCase1 = 0x10006d14;
// R6GameService.dll interior-code @ 10006d28
constexpr unsigned int ms_service_callbacksBranch2 = 0x10006d28;
// R6GameService.dll data @ 10006d2c
constexpr unsigned int GMSErrorTargets = 0x10006d2c;
// R6GameService.dll data @ 10006d44
constexpr unsigned int GMSErrorCases = 0x10006d44;
// R6GameService.dll code @ 10006d60
constexpr unsigned int MSInitFinished = 0x10006d60;
// R6GameService.dll code @ 10006dc0
constexpr unsigned int MSRequestFinished = 0x10006dc0;
// R6GameService.dll code @ 10006df0
constexpr unsigned int MSJoinFinished = 0x10006df0;
// R6GameService.dll code @ 10006e20
constexpr unsigned int MSLoginDisconnect = 0x10006e20;
// R6GameService.dll code @ 10006e50
constexpr unsigned int MSLobbyDisconnect = 0x10006e50;
// R6GameService.dll code @ 10006e80
constexpr unsigned int MSMatchStartedCB = 0x10006e80;
// R6GameService.dll code @ 10006fa0
constexpr unsigned int MSSubmitMatchCB = 0x10006fa0;
// R6GameService.dll code @ 10007050
constexpr unsigned int UR6GSServers_execIsRefreshServersInProgress = 0x10007050;
// R6GameService.dll code @ 100070b2
constexpr unsigned int UR6GSServers_UR6GSServersCatch22 = 0x100070b2;
// R6GameService.dll code @ 100070c6
constexpr unsigned int UR6GSServers_UR6GSServersCatch23 = 0x100070c6;
// R6GameService.dll code @ 10007100
constexpr unsigned int UR6GSServers_execStopRefreshServers = 0x10007100;
// R6GameService.dll code @ 10007168
constexpr unsigned int UR6GSServers_UR6GSServersCatch24 = 0x10007168;
// R6GameService.dll code @ 1000717c
constexpr unsigned int UR6GSServers_UR6GSServersCatch25 = 0x1000717c;
// R6GameService.dll code @ 100071a0
constexpr unsigned int UR6GSServers_MSCLientLeaveServer = 0x100071a0;
// R6GameService.dll code @ 10007230
constexpr unsigned int UR6GSServers_UR6GSServersCatch26 = 0x10007230;
// R6GameService.dll code @ 10007244
constexpr unsigned int UR6GSServers_UR6GSServersCatch27 = 0x10007244;
// R6GameService.dll code @ 10007280
constexpr unsigned int UR6GSServers_MSCLientJoinServer = 0x10007280;
// R6GameService.dll code @ 100073cd
constexpr unsigned int UR6GSServers_UR6GSServersCatch28 = 0x100073cd;
// R6GameService.dll code @ 100073e1
constexpr unsigned int UR6GSServers_UR6GSServersCatch29 = 0x100073e1;
// R6GameService.dll code @ 10007400
constexpr unsigned int UR6GSServers_execNativeMSCLientJoinServer = 0x10007400;
// R6GameService.dll code @ 100074ef
constexpr unsigned int UR6GSServers_UR6GSServersCatch30 = 0x100074ef;
// R6GameService.dll code @ 10007503
constexpr unsigned int UR6GSServers_UR6GSServersCatch31 = 0x10007503;
// R6GameService.dll code @ 10007520
constexpr unsigned int UR6GSServers_IsServerJoined = 0x10007520;
// R6GameService.dll code @ 10007530
constexpr unsigned int UR6GSServers_MSClientServerConnected = 0x10007530;
// R6GameService.dll code @ 100075c8
constexpr unsigned int UR6GSServers_UR6GSServersCatch32 = 0x100075c8;
// R6GameService.dll code @ 100075dc
constexpr unsigned int UR6GSServers_UR6GSServersCatch33 = 0x100075dc;
// R6GameService.dll code @ 10007600
constexpr unsigned int UR6GSServers_execNativeMSClientReqAltInfo = 0x10007600;
// R6GameService.dll code @ 100076d7
constexpr unsigned int UR6GSServers_UR6GSServersCatch34 = 0x100076d7;
// R6GameService.dll code @ 100076eb
constexpr unsigned int UR6GSServers_UR6GSServersCatch35 = 0x100076eb;
// R6GameService.dll code @ 10007710
constexpr unsigned int UR6ServerList_ResetSvrContainer = 0x10007710;
// R6GameService.dll code @ 1000775f
constexpr unsigned int UR6ServerList_UR6ServerListCatch10 = 0x1000775f;
// R6GameService.dll code @ 10007773
constexpr unsigned int UR6ServerList_UR6ServerListCatch11 = 0x10007773;
// R6GameService.dll code @ 10007790
constexpr unsigned int UR6GSServers_execSetLastServerQueried = 0x10007790;
// R6GameService.dll code @ 10007835
constexpr unsigned int UR6GSServers_UR6GSServersCatch36 = 0x10007835;
// R6GameService.dll code @ 10007849
constexpr unsigned int UR6GSServers_UR6GSServersCatch37 = 0x10007849;
// R6GameService.dll code @ 10007870
constexpr unsigned int UR6GSServers_ProcessJoinServerRequest = 0x10007870;
// R6GameService.dll interior-code @ 100078aa
constexpr unsigned int UR6GSServersBranch36 = 0x100078aa;
// R6GameService.dll interior-code @ 100078bf
constexpr unsigned int UR6GSServersBranch37 = 0x100078bf;
// R6GameService.dll interior-code @ 100078d0
constexpr unsigned int UR6GSServersBranch38 = 0x100078d0;
// R6GameService.dll interior-code @ 10007933
constexpr unsigned int UR6GSServersBranch39 = 0x10007933;
// R6GameService.dll interior-code @ 10007989
constexpr unsigned int UR6GSServersBranch40 = 0x10007989;
// R6GameService.dll code @ 100079a0
constexpr unsigned int UR6GSServers_UR6GSServersCatch38 = 0x100079a0;
// R6GameService.dll code @ 100079b4
constexpr unsigned int UR6GSServers_UR6GSServersCatch39 = 0x100079b4;
// R6GameService.dll data @ 100079d0
constexpr unsigned int JoinRequestDispatch = 0x100079d0;
// R6GameService.dll code @ 100079f0
constexpr unsigned int UR6GSServers_ProcessUbiComJoinServer = 0x100079f0;
// R6GameService.dll code @ 10007a99
constexpr unsigned int UR6GSServers_UR6GSServersCatch40 = 0x10007a99;
// R6GameService.dll code @ 10007aad
constexpr unsigned int UR6GSServers_UR6GSServersCatch41 = 0x10007aad;
// R6GameService.dll code @ 10007ad0
constexpr unsigned int UR6GSServers_ProcessIsRouterDisconnect = 0x10007ad0;
// R6GameService.dll code @ 10007b67
constexpr unsigned int UR6GSServers_UR6GSServersCatch42 = 0x10007b67;
// R6GameService.dll code @ 10007b7b
constexpr unsigned int UR6GSServers_UR6GSServersCatch43 = 0x10007b7b;
// R6GameService.dll code @ 10007ba0
constexpr unsigned int UR6GSServers_execNativeIsRouterDisconnect = 0x10007ba0;
// R6GameService.dll code @ 10007c25
constexpr unsigned int UR6GSServers_UR6GSServersCatch44 = 0x10007c25;
// R6GameService.dll code @ 10007c39
constexpr unsigned int UR6GSServers_UR6GSServersCatch45 = 0x10007c39;
// R6GameService.dll code @ 10007c60
constexpr unsigned int UR6GSServers_ProcessIsLobbyDisconnect = 0x10007c60;
// R6GameService.dll code @ 10007d01
constexpr unsigned int UR6GSServers_UR6GSServersCatch46 = 0x10007d01;
// R6GameService.dll code @ 10007d15
constexpr unsigned int UR6GSServers_UR6GSServersCatch47 = 0x10007d15;
// R6GameService.dll code @ 10007d40
constexpr unsigned int UR6GSServers_ProcessJoinServer = 0x10007d40;
// R6GameService.dll code @ 10007d50
constexpr unsigned int FreeLinkedAllocations = 0x10007d50;
// R6GameService.dll code @ 10007d80
constexpr unsigned int InitializeThreeWords = 0x10007d80;
// R6GameService.dll code @ 10007d90
constexpr unsigned int DestroyFourStrings = 0x10007d90;
// R6GameService.dll code @ 10007e00
constexpr unsigned int ConvertAnsiToBstr = 0x10007e00;
// R6GameService.dll code @ 10007ea0
constexpr unsigned int CallThirdSlotForFirstWordObject = 0x10007ea0;
// R6GameService.dll code @ 10007eb0
constexpr unsigned int UR6GSServers_Init = 0x10007eb0;
// R6GameService.dll code @ 10008670
constexpr unsigned int UR6GSServers_execInitialize = 0x10008670;
// R6GameService.dll code @ 100086f1
constexpr unsigned int UR6GSServers_UR6GSServersCatch48 = 0x100086f1;
// R6GameService.dll code @ 10008705
constexpr unsigned int UR6GSServers_UR6GSServersCatch49 = 0x10008705;
// R6GameService.dll code @ 10008730
constexpr unsigned int UR6ServerList_InitFavorites = 0x10008730;
// R6GameService.dll code @ 100087f6
constexpr unsigned int UR6ServerList_UR6ServerListCatch12 = 0x100087f6;
// R6GameService.dll code @ 1000880a
constexpr unsigned int UR6ServerList_UR6ServerListCatch13 = 0x1000880a;
// R6GameService.dll code @ 10008830
constexpr unsigned int UR6ServerList_execNativeInitFavorites = 0x10008830;
// R6GameService.dll code @ 10008898
constexpr unsigned int UR6ServerList_UR6ServerListCatch14 = 0x10008898;
// R6GameService.dll code @ 100088ac
constexpr unsigned int UR6ServerList_UR6ServerListCatch15 = 0x100088ac;
// R6GameService.dll code @ 100088d0
constexpr unsigned int UR6ServerList_execNativeUpdateFavorites = 0x100088d0;
// R6GameService.dll code @ 10008989
constexpr unsigned int UR6ServerList_UR6ServerListCatch16 = 0x10008989;
// R6GameService.dll code @ 1000899d
constexpr unsigned int UR6ServerList_UR6ServerListCatch17 = 0x1000899d;
// R6GameService.dll code @ 100089d0
constexpr unsigned int UR6ServerList_execSortServers = 0x100089d0;
// R6GameService.dll interior-code @ 10008ab4
constexpr unsigned int GSortServerCasesCase5 = 0x10008ab4;
// R6GameService.dll interior-code @ 10008b61
constexpr unsigned int GSortServerCasesCase10 = 0x10008b61;
// R6GameService.dll interior-code @ 10008c12
constexpr unsigned int GSortServerCasesCase6 = 0x10008c12;
// R6GameService.dll interior-code @ 10008d0f
constexpr unsigned int GSortServerCasesCase7 = 0x10008d0f;
// R6GameService.dll interior-code @ 10008e18
constexpr unsigned int GSortServerCasesCase8 = 0x10008e18;
// R6GameService.dll interior-code @ 10008ece
constexpr unsigned int GSortServerCasesCase9 = 0x10008ece;
// R6GameService.dll interior-code @ 10008fd7
constexpr unsigned int GSortServerCasesCase1 = 0x10008fd7;
// R6GameService.dll interior-code @ 1000908e
constexpr unsigned int GSortServerCasesCase2 = 0x1000908e;
// R6GameService.dll interior-code @ 10009140
constexpr unsigned int GSortServerCasesCase3 = 0x10009140;
// R6GameService.dll interior-code @ 100091f2
constexpr unsigned int GSortServerCasesCase4 = 0x100091f2;
// R6GameService.dll code @ 100092c1
constexpr unsigned int UR6ServerList_UR6ServerListCatch18 = 0x100092c1;
// R6GameService.dll code @ 100092d5
constexpr unsigned int UR6ServerList_UR6ServerListCatch19 = 0x100092d5;
// R6GameService.dll data @ 100092f4
constexpr unsigned int GSortServerCases = 0x100092f4;
// R6GameService.dll code @ 10009320
constexpr unsigned int InitializeGSModuleVersions = 0x10009320;
// R6GameService.dll code @ 10009400
constexpr unsigned int UR6GSServers_LogGSVersion = 0x10009400;
// R6GameService.dll code @ 1000954a
constexpr unsigned int UR6GSServers_UR6GSServersCatch50 = 0x1000954a;
// R6GameService.dll code @ 1000955e
constexpr unsigned int UR6GSServers_UR6GSServersCatch51 = 0x1000955e;
// R6GameService.dll code @ 10009580
constexpr unsigned int UR6ServerList_execGetDisplayListSize = 0x10009580;
// R6GameService.dll code @ 100095ee
constexpr unsigned int UR6ServerList_UR6ServerListCatch20 = 0x100095ee;
// R6GameService.dll code @ 10009602
constexpr unsigned int UR6ServerList_UR6ServerListCatch21 = 0x10009602;
// R6GameService.dll code @ 10009640
constexpr unsigned int UR6GSServers_PlayerIsInIDList = 0x10009640;
// R6GameService.dll code @ 10009752
constexpr unsigned int UR6GSServers_UR6GSServersCatch52 = 0x10009752;
// R6GameService.dll code @ 10009766
constexpr unsigned int UR6GSServers_UR6GSServersCatch53 = 0x10009766;
// R6GameService.dll code @ 10009790
constexpr unsigned int UR6GSServers_GetGlobalIdFromPlayerIDList = 0x10009790;
// R6GameService.dll code @ 1000983e
constexpr unsigned int UR6GSServers_UR6GSServersCatch54 = 0x1000983e;
// R6GameService.dll code @ 10009852
constexpr unsigned int UR6GSServers_UR6GSServersCatch55 = 0x10009852;
// R6GameService.dll code @ 10009870
constexpr unsigned int UR6GSServers_PollCallbacks = 0x10009870;
// R6GameService.dll code @ 100098e1
constexpr unsigned int UR6GSServers_UR6GSServersCatch56 = 0x100098e1;
// R6GameService.dll code @ 100098f5
constexpr unsigned int UR6GSServers_UR6GSServersCatch57 = 0x100098f5;
// R6GameService.dll code @ 10009920
constexpr unsigned int UR6GSServers_InitializeMSClient = 0x10009920;
// R6GameService.dll code @ 100099cb
constexpr unsigned int UR6GSServers_UR6GSServersCatch58 = 0x100099cb;
// R6GameService.dll code @ 100099df
constexpr unsigned int UR6GSServers_UR6GSServersCatch59 = 0x100099df;
// R6GameService.dll code @ 10009a00
constexpr unsigned int UR6GSServers_execInitializeMSClient = 0x10009a00;
// R6GameService.dll code @ 10009a6d
constexpr unsigned int UR6GSServers_UR6GSServersCatch60 = 0x10009a6d;
// R6GameService.dll code @ 10009a81
constexpr unsigned int UR6GSServers_UR6GSServersCatch61 = 0x10009a81;
// R6GameService.dll code @ 10009aa0
constexpr unsigned int MSGameServer = 0x10009aa0;
// R6GameService.dll code @ 10009d10
constexpr unsigned int MSAlternateInfo = 0x10009d10;
// R6GameService.dll code @ 10009dd0
constexpr unsigned int UR6GSServers_RefreshOneServer = 0x10009dd0;
// R6GameService.dll code @ 10009e8e
constexpr unsigned int UR6GSServers_UR6GSServersCatch62 = 0x10009e8e;
// R6GameService.dll code @ 10009ea2
constexpr unsigned int UR6GSServers_UR6GSServersCatch63 = 0x10009ea2;
// R6GameService.dll code @ 10009ec0
constexpr unsigned int UR6GSServers_execRefreshOneServer = 0x10009ec0;
// R6GameService.dll code @ 10009f50
constexpr unsigned int UR6GSServers_UR6GSServersCatch64 = 0x10009f50;
// R6GameService.dll code @ 10009f64
constexpr unsigned int UR6GSServers_UR6GSServersCatch65 = 0x10009f64;
// R6GameService.dll code @ 10009f90
constexpr unsigned int UR6GSServers_execNativeSetMatchResult = 0x10009f90;
// R6GameService.dll code @ 1000a1bc
constexpr unsigned int UR6GSServers_UR6GSServersCatch66 = 0x1000a1bc;
// R6GameService.dll code @ 1000a1d0
constexpr unsigned int UR6GSServers_UR6GSServersCatch67 = 0x1000a1d0;
// R6GameService.dll code @ 1000a1f0
constexpr unsigned int UR6GSServers_SubmitMatchResult = 0x1000a1f0;
// R6GameService.dll code @ 1000a373
constexpr unsigned int UR6GSServers_UR6GSServersCatch68 = 0x1000a373;
// R6GameService.dll code @ 1000a387
constexpr unsigned int UR6GSServers_UR6GSServersCatch69 = 0x1000a387;
// R6GameService.dll code @ 1000a3b0
constexpr unsigned int UR6ServerList_FillSvrContainer = 0x1000a3b0;
// R6GameService.dll code @ 1000a887
constexpr unsigned int UR6ServerList_UR6ServerListCatch22 = 0x1000a887;
// R6GameService.dll code @ 1000a89b
constexpr unsigned int UR6ServerList_UR6ServerListCatch23 = 0x1000a89b;
// R6GameService.dll code @ 1000a8c0
constexpr unsigned int UR6GSServers_ProcessLoginMasterSrv = 0x1000a8c0;
// R6GameService.dll code @ 1000a98f
constexpr unsigned int UR6GSServers_UR6GSServersCatch70 = 0x1000a98f;
// R6GameService.dll code @ 1000a9a3
constexpr unsigned int UR6GSServers_UR6GSServersCatch71 = 0x1000a9a3;
// R6GameService.dll code @ 1000a9c0
constexpr unsigned int UR6GSServers_MasterServerManager = 0x1000a9c0;
// R6GameService.dll code @ 1000aabd
constexpr unsigned int UR6GSServers_UR6GSServersCatch72 = 0x1000aabd;
// R6GameService.dll code @ 1000aad1
constexpr unsigned int UR6GSServers_UR6GSServersCatch73 = 0x1000aad1;
// R6GameService.dll code @ 1000aaf0
constexpr unsigned int ClearFirstWord = 0x1000aaf0;
// R6GameService.dll code @ 1000ab00
constexpr unsigned int UR6GSServers_AddPlayerToIDList = 0x1000ab00;
// R6GameService.dll code @ 1000ac76
constexpr unsigned int UR6GSServers_UR6GSServersCatch74 = 0x1000ac76;
// R6GameService.dll code @ 1000ac8a
constexpr unsigned int UR6GSServers_UR6GSServersCatch75 = 0x1000ac8a;
// R6GameService.dll code @ 1000acb0
constexpr unsigned int RegisterMSClientCallbacks = 0x1000acb0;
// R6GameService.dll code @ 1000ad20
constexpr unsigned int UR6GSServers_ReceiveServer = 0x1000ad20;
// R6GameService.dll code @ 1000b38b
constexpr unsigned int UR6GSServers_UR6GSServersCatch76 = 0x1000b38b;
// R6GameService.dll code @ 1000b39f
constexpr unsigned int UR6GSServers_UR6GSServersCatch77 = 0x1000b39f;
// R6GameService.dll code @ 1000b3d0
constexpr unsigned int unreal_array_support_DestroyArrayStorage2 = 0x1000b3d0;
// R6GameService.dll code @ 1000b470
constexpr unsigned int unreal_array_support_DestroyArrayStorage3 = 0x1000b470;
// R6GameService.dll code @ 1000b510
constexpr unsigned int unreal_array_support_DestroyArrayStorage4 = 0x1000b510;
// R6GameService.dll code @ 1000b5a0
constexpr unsigned int RemoveStringRecordRange30 = 0x1000b5a0;
// R6GameService.dll code @ 1000b640
constexpr unsigned int UR6GSServers_InitMSClient = 0x1000b640;
// R6GameService.dll code @ 1000b896
constexpr unsigned int UR6GSServers_UR6GSServersCatch78 = 0x1000b896;
// R6GameService.dll code @ 1000b8aa
constexpr unsigned int UR6GSServers_UR6GSServersCatch79 = 0x1000b8aa;
// R6GameService.dll code @ 1000b8d0
constexpr unsigned int UR6GSServers_ReceiveAltInfo = 0x1000b8d0;
// R6GameService.dll code @ 1000becf
constexpr unsigned int UR6GSServers_UR6GSServersCatch80 = 0x1000becf;
// R6GameService.dll code @ 1000bee3
constexpr unsigned int UR6GSServers_UR6GSServersCatch81 = 0x1000bee3;
// R6GameService.dll code @ 1000bf00
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequest = 0x1000bf00;
// R6GameService.dll interior-code @ 1000bf3a
constexpr unsigned int GProcessMSClientInitRequestSwitchCase1 = 0x1000bf3a;
// R6GameService.dll interior-code @ 1000bf5c
constexpr unsigned int UR6GSServersBranch171 = 0x1000bf5c;
// R6GameService.dll interior-code @ 1000bf6d
constexpr unsigned int GProcessMSClientInitRequestSwitchCase2 = 0x1000bf6d;
// R6GameService.dll interior-code @ 1000bfa0
constexpr unsigned int GProcessMSClientInitRequestSwitchCase3 = 0x1000bfa0;
// R6GameService.dll interior-code @ 1000bfc8
constexpr unsigned int GProcessMSClientInitRequestSwitchCase6 = 0x1000bfc8;
// R6GameService.dll code @ 1000c02d
constexpr unsigned int UR6GSServers_UR6GSServersCatch82 = 0x1000c02d;
// R6GameService.dll code @ 1000c041
constexpr unsigned int UR6GSServers_UR6GSServersCatch83 = 0x1000c041;
// R6GameService.dll data @ 1000c060
constexpr unsigned int GProcessMSClientInitRequestSwitch = 0x1000c060;
// R6GameService.dll code @ 1000c080
constexpr unsigned int DestroyStringRecordArray30 = 0x1000c080;
// R6GameService.dll code @ 1000c0d0
constexpr unsigned int UR6GSServers_RefreshServers = 0x1000c0d0;
// R6GameService.dll code @ 1000c1b9
constexpr unsigned int UR6GSServers_UR6GSServersCatch84 = 0x1000c1b9;
// R6GameService.dll code @ 1000c1cd
constexpr unsigned int UR6GSServers_UR6GSServersCatch85 = 0x1000c1cd;
// R6GameService.dll code @ 1000c1f0
constexpr unsigned int UR6GSServers_execRefreshServers = 0x1000c1f0;
// R6GameService.dll code @ 1000c258
constexpr unsigned int UR6GSServers_UR6GSServersCatch86 = 0x1000c258;
// R6GameService.dll code @ 1000c26c
constexpr unsigned int UR6GSServers_UR6GSServersCatch87 = 0x1000c26c;
// R6GameService.dll code @ 1000c290
constexpr unsigned int UR6GSServers_GameServiceManager = 0x1000c290;
// R6GameService.dll code @ 1000c4be
constexpr unsigned int UR6GSServers_UR6GSServersCatch88 = 0x1000c4be;
// R6GameService.dll code @ 1000c4d2
constexpr unsigned int UR6GSServers_UR6GSServersCatch89 = 0x1000c4d2;
// R6GameService.dll code @ 1000c4f0
constexpr unsigned int UR6GSServers_UR6GSServers2 = 0x1000c4f0;
// R6GameService.dll code @ 1000c63f
constexpr unsigned int UR6GSServers_UR6GSServersCatch90 = 0x1000c63f;
// R6GameService.dll code @ 1000c653
constexpr unsigned int UR6GSServers_UR6GSServersCatch91 = 0x1000c653;
// R6GameService.dll code @ 1000c670
constexpr unsigned int UR6GSServers_CreatedCDKey = 0x1000c670;
// R6GameService.dll code @ 1000c77e
constexpr unsigned int UR6GSServers_UR6GSServersCatch92 = 0x1000c77e;
// R6GameService.dll code @ 1000c792
constexpr unsigned int UR6GSServers_UR6GSServersCatch93 = 0x1000c792;
// R6GameService.dll code @ 1000c7b0
constexpr unsigned int UR6ModGSInfo_InitMODCDKey = 0x1000c7b0;
// R6GameService.dll code @ 1000c8e3
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoCatch2 = 0x1000c8e3;
// R6GameService.dll code @ 1000c8f7
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoCatch3 = 0x1000c8f7;
// R6GameService.dll code @ 1000c920
constexpr unsigned int UR6GSServers_execInitGSCDKey = 0x1000c920;
// R6GameService.dll code @ 1000c98d
constexpr unsigned int UR6GSServers_UR6GSServersCatch94 = 0x1000c98d;
// R6GameService.dll code @ 1000c9a1
constexpr unsigned int UR6GSServers_UR6GSServersCatch95 = 0x1000c9a1;
// R6GameService.dll code @ 1000c9c0
constexpr unsigned int UR6GSServers_UnInitCDKey = 0x1000c9c0;
// R6GameService.dll code @ 1000ca71
constexpr unsigned int UR6GSServers_UR6GSServersCatch96 = 0x1000ca71;
// R6GameService.dll code @ 1000ca85
constexpr unsigned int UR6GSServers_UR6GSServersCatch97 = 0x1000ca85;
// R6GameService.dll code @ 1000cab0
constexpr unsigned int UR6GSServers_RequestActivation = 0x1000cab0;
// R6GameService.dll code @ 1000cc45
constexpr unsigned int UR6GSServers_UR6GSServersCatch98 = 0x1000cc45;
// R6GameService.dll code @ 1000cc59
constexpr unsigned int UR6GSServers_UR6GSServersCatch99 = 0x1000cc59;
// R6GameService.dll code @ 1000cc80
constexpr unsigned int UR6GSServers_RequestGSCDKeyActID = 0x1000cc80;
// R6GameService.dll code @ 1000cca0
constexpr unsigned int UR6GSServers_CancelGSCDKeyActID = 0x1000cca0;
// R6GameService.dll code @ 1000ccc0
constexpr unsigned int UR6GSServers_RequestAuthorization = 0x1000ccc0;
// R6GameService.dll code @ 1000cdc7
constexpr unsigned int UR6GSServers_UR6GSServersCatch100 = 0x1000cdc7;
// R6GameService.dll code @ 1000cddb
constexpr unsigned int UR6GSServers_UR6GSServersCatch101 = 0x1000cddb;
// R6GameService.dll code @ 1000ce00
constexpr unsigned int UR6GSServers_RequestGSCDKeyAuthID = 0x1000ce00;
// R6GameService.dll code @ 1000ce10
constexpr unsigned int UR6GSServers_CancelGSCDKeyAuthID = 0x1000ce10;
// R6GameService.dll code @ 1000ce30
constexpr unsigned int UR6GSServers_ResetAuthId = 0x1000ce30;
// R6GameService.dll code @ 1000ce50
constexpr unsigned int UR6GSServers_GetAuthID = 0x1000ce50;
// R6GameService.dll code @ 1000ceb2
constexpr unsigned int UR6GSServers_UR6GSServersCatch102 = 0x1000ceb2;
// R6GameService.dll code @ 1000cec6
constexpr unsigned int UR6GSServers_UR6GSServersCatch103 = 0x1000cec6;
// R6GameService.dll code @ 1000cef0
constexpr unsigned int UR6GSServers_IsAuthIDSuccess = 0x1000cef0;
// R6GameService.dll code @ 1000cfcd
constexpr unsigned int UR6GSServers_UR6GSServersCatch104 = 0x1000cfcd;
// R6GameService.dll code @ 1000cfe1
constexpr unsigned int UR6GSServers_UR6GSServersCatch105 = 0x1000cfe1;
// R6GameService.dll code @ 1000d000
constexpr unsigned int UR6GSServers_CopyActivationIDInByteArray = 0x1000d000;
// R6GameService.dll code @ 1000d020
constexpr unsigned int FormatAuthenticationIdHex = 0x1000d020;
// R6GameService.dll code @ 1000d110
constexpr unsigned int UR6GSServers_CDKeyValidateUser = 0x1000d110;
// R6GameService.dll code @ 1000d265
constexpr unsigned int UR6GSServers_UR6GSServersCatch106 = 0x1000d265;
// R6GameService.dll code @ 1000d279
constexpr unsigned int UR6GSServers_UR6GSServersCatch107 = 0x1000d279;
// R6GameService.dll code @ 1000d2a0
constexpr unsigned int UR6GSServers_EnterCDKey = 0x1000d2a0;
// R6GameService.dll code @ 1000d666
constexpr unsigned int UR6GSServers_UR6GSServersCatch108 = 0x1000d666;
// R6GameService.dll code @ 1000d67a
constexpr unsigned int UR6GSServers_UR6GSServersCatch109 = 0x1000d67a;
// R6GameService.dll code @ 1000d6a0
constexpr unsigned int UR6GSServers_execEnterCDKey = 0x1000d6a0;
// R6GameService.dll code @ 1000d751
constexpr unsigned int UR6GSServers_UR6GSServersCatch110 = 0x1000d751;
// R6GameService.dll code @ 1000d765
constexpr unsigned int UR6GSServers_UR6GSServersCatch111 = 0x1000d765;
// R6GameService.dll code @ 1000d790
constexpr unsigned int UR6GSServers_RequestModCDKeyProcess = 0x1000d790;
// R6GameService.dll code @ 1000d9a4
constexpr unsigned int UR6GSServers_UR6GSServersCatch112 = 0x1000d9a4;
// R6GameService.dll code @ 1000d9b8
constexpr unsigned int UR6GSServers_UR6GSServersCatch113 = 0x1000d9b8;
// R6GameService.dll code @ 1000d9e0
constexpr unsigned int LogCDKeyRequestDiagnostics = 0x1000d9e0;
// R6GameService.dll interior-code @ 1000da6b
constexpr unsigned int GCDKeyDiagnosticSwitchCase1 = 0x1000da6b;
// R6GameService.dll interior-code @ 1000da77
constexpr unsigned int GCDKeyDiagnosticSwitchCase2 = 0x1000da77;
// R6GameService.dll interior-code @ 1000daa0
constexpr unsigned int GCDKeyDiagnosticSwitchCase3 = 0x1000daa0;
// R6GameService.dll interior-code @ 1000dac8
constexpr unsigned int GCDKeyDiagnosticSwitchCase4 = 0x1000dac8;
// R6GameService.dll interior-code @ 1000db2d
constexpr unsigned int cdkey_supportGCDKeyDiagnosticSwitchCase1 = 0x1000db2d;
// R6GameService.dll interior-code @ 1000db39
constexpr unsigned int cdkey_supportGCDKeyDiagnosticSwitchCase2 = 0x1000db39;
// R6GameService.dll interior-code @ 1000db62
constexpr unsigned int cdkey_supportGCDKeyDiagnosticSwitchCase3 = 0x1000db62;
// R6GameService.dll interior-code @ 1000db8a
constexpr unsigned int cdkey_supportGCDKeyDiagnosticSwitchCase4 = 0x1000db8a;
// R6GameService.dll data @ 1000dbdc
constexpr unsigned int GCDKeyDiagnosticSwitch = 0x1000dbdc;
// R6GameService.dll data @ 1000dbec
constexpr unsigned int cdkey_supportGCDKeyDiagnosticSwitch = 0x1000dbec;
// R6GameService.dll code @ 1000dc00
constexpr unsigned int ReceiveActivationReply = 0x1000dc00;
// R6GameService.dll code @ 1000dcd0
constexpr unsigned int ReceiveAuthorizationReply = 0x1000dcd0;
// R6GameService.dll code @ 1000dd90
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacks = 0x1000dd90;
// R6GameService.dll interior-code @ 1000deb2
constexpr unsigned int GCDKeyActivationDispatchCase1 = 0x1000deb2;
// R6GameService.dll interior-code @ 1000dfbf
constexpr unsigned int GCDKeyActivationDispatchCase2 = 0x1000dfbf;
// R6GameService.dll interior-code @ 1000e029
constexpr unsigned int UR6GSServersBranch493 = 0x1000e029;
// R6GameService.dll interior-code @ 1000e045
constexpr unsigned int GCDKeyActivationDispatchCase6 = 0x1000e045;
// R6GameService.dll interior-code @ 1000e192
constexpr unsigned int GCDKeyActivationDispatchCase3 = 0x1000e192;
// R6GameService.dll interior-code @ 1000e3b5
constexpr unsigned int GCDKeyAuthorizationDispatchCase1 = 0x1000e3b5;
// R6GameService.dll interior-code @ 1000e46c
constexpr unsigned int GCDKeyAuthorizationDispatchCase2 = 0x1000e46c;
// R6GameService.dll interior-code @ 1000e522
constexpr unsigned int GCDKeyAuthorizationDispatchCase5 = 0x1000e522;
// R6GameService.dll interior-code @ 1000e54c
constexpr unsigned int GCDKeyAuthorizationDispatchCase4 = 0x1000e54c;
// R6GameService.dll interior-code @ 1000e5b6
constexpr unsigned int GCDKeyAuthorizationDispatchCase3 = 0x1000e5b6;
// R6GameService.dll interior-code @ 1000e613
constexpr unsigned int GCDKeyAuthorizationDispatchCase6 = 0x1000e613;
// R6GameService.dll interior-code @ 1000e705
constexpr unsigned int GCDKeyAuthorizationDispatchCase7 = 0x1000e705;
// R6GameService.dll interior-code @ 1000e72b
constexpr unsigned int GCDKeyReplyDispatchCase4 = 0x1000e72b;
// R6GameService.dll interior-code @ 1000e783
constexpr unsigned int GCDKeyReplyDispatchCase1 = 0x1000e783;
// R6GameService.dll interior-code @ 1000e8c9
constexpr unsigned int GCDKeyReplyDispatchCase3 = 0x1000e8c9;
// R6GameService.dll interior-code @ 1000e91f
constexpr unsigned int GCDKeyReplyDispatchCase5 = 0x1000e91f;
// R6GameService.dll interior-code @ 1000e973
constexpr unsigned int UR6GSServersBranch538 = 0x1000e973;
// R6GameService.dll code @ 1000e982
constexpr unsigned int UR6GSServers_UR6GSServersCatch114 = 0x1000e982;
// R6GameService.dll code @ 1000e996
constexpr unsigned int UR6GSServers_UR6GSServersCatch115 = 0x1000e996;
// R6GameService.dll data @ 1000e9b4
constexpr unsigned int GCDKeyActivationDispatch = 0x1000e9b4;
// R6GameService.dll data @ 1000e9cc
constexpr unsigned int GCDKeyAuthorizationDispatch = 0x1000e9cc;
// R6GameService.dll data @ 1000e9e8
constexpr unsigned int GCDKeyReplyDispatch = 0x1000e9e8;
// R6GameService.dll code @ 1000ea00
constexpr unsigned int CastToUNetConnection = 0x1000ea00;
// R6GameService.dll code @ 1000ea30
constexpr unsigned int CastToUViewport = 0x1000ea30;
// R6GameService.dll code @ 1000ea60
constexpr unsigned int RcvValidationResponse = 0x1000ea60;
// R6GameService.dll code @ 1000ebb0
constexpr unsigned int RcvModValidationResponse = 0x1000ebb0;
// R6GameService.dll code @ 1000ed00
constexpr unsigned int OnRSPlayerStatusRequest = 0x1000ed00;
// R6GameService.dll code @ 1000edc0
constexpr unsigned int OnModPlayerStatusRequest = 0x1000edc0;
// R6GameService.dll code @ 1000ee80
constexpr unsigned int UR6GSServers_ReceiveValidation = 0x1000ee80;
// R6GameService.dll code @ 1000f08e
constexpr unsigned int UR6GSServers_UR6GSServersCatch116 = 0x1000f08e;
// R6GameService.dll code @ 1000f0a2
constexpr unsigned int UR6GSServers_UR6GSServersCatch117 = 0x1000f0a2;
// R6GameService.dll code @ 1000f0d0
constexpr unsigned int UR6GSServers_registerCDKeySDKCallbacks = 0x1000f0d0;
// R6GameService.dll code @ 1000f150
constexpr unsigned int unreal_array_support_DestroyArrayStorage5 = 0x1000f150;
// R6GameService.dll code @ 1000f1e0
constexpr unsigned int UR6GSServers_InitCDKey = 0x1000f1e0;
// R6GameService.dll code @ 1000f342
constexpr unsigned int UR6GSServers_UR6GSServersCatch118 = 0x1000f342;
// R6GameService.dll code @ 1000f356
constexpr unsigned int UR6GSServers_UR6GSServersCatch119 = 0x1000f356;
// R6GameService.dll code @ 1000f380
constexpr unsigned int UR6GSServers_InitGSCDKey = 0x1000f380;
// R6GameService.dll code @ 1000f446
constexpr unsigned int UR6GSServers_UR6GSServersCatch120 = 0x1000f446;
// R6GameService.dll code @ 1000f45a
constexpr unsigned int UR6GSServers_UR6GSServersCatch121 = 0x1000f45a;
// R6GameService.dll code @ 1000f480
constexpr unsigned int UR6GSServers_DisconnectAllCDKeyPlayers = 0x1000f480;
// R6GameService.dll code @ 1000f797
constexpr unsigned int UR6GSServers_UR6GSServersCatch122 = 0x1000f797;
// R6GameService.dll code @ 1000f7ab
constexpr unsigned int UR6GSServers_UR6GSServersCatch123 = 0x1000f7ab;
// R6GameService.dll code @ 1000f7e0
constexpr unsigned int UR6GSServers_CDKeyDisconnecUser = 0x1000f7e0;
// R6GameService.dll interior-code @ 1000f8fa : historical alias for CDKeyDisconnecUser after RS decoding.
constexpr unsigned int ActivationFailureContinuation = 0x1000f8fa;
// R6GameService.dll interior-code @ 1000f9bf : historical alias for CDKeyDisconnecUser after Mod decoding.
constexpr unsigned int AuthorizationFailureContinuation = 0x1000f9bf;
// R6GameService.dll code @ 1000faac
constexpr unsigned int UR6GSServers_UR6GSServersCatch124 = 0x1000faac;
// R6GameService.dll code @ 1000fac0
constexpr unsigned int UR6GSServers_UR6GSServersCatch125 = 0x1000fac0;
// R6GameService.dll code @ 1000fae0
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReply = 0x1000fae0;
// R6GameService.dll code @ 1000fcf7
constexpr unsigned int UR6GSServers_UR6GSServersCatch126 = 0x1000fcf7;
// R6GameService.dll code @ 1000fd0b
constexpr unsigned int UR6GSServers_UR6GSServersCatch127 = 0x1000fd0b;
// R6GameService.dll code @ 1000fd30
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequest = 0x1000fd30;
// R6GameService.dll interior-code @ 1000fe3f
constexpr unsigned int GPCRequestDispatchCase1 = 0x1000fe3f;
// R6GameService.dll interior-code @ 100100cb
constexpr unsigned int GPCRequestDispatchCase2 = 0x100100cb;
// R6GameService.dll interior-code @ 100103ba
constexpr unsigned int GPCRequestDispatchCase3 = 0x100103ba;
// R6GameService.dll interior-code @ 1001040a
constexpr unsigned int GPCRequestDispatchCase4 = 0x1001040a;
// R6GameService.dll code @ 1001054a
constexpr unsigned int UR6GSServers_UR6GSServersCatch128 = 0x1001054a;
// R6GameService.dll code @ 1001055e
constexpr unsigned int UR6GSServers_UR6GSServersCatch129 = 0x1001055e;
// R6GameService.dll data @ 1001057c
constexpr unsigned int GPCRequestDispatch = 0x1001057c;
// R6GameService.dll code @ 10010590
constexpr unsigned int UR6GSServers_ProcessAuthIdRequest = 0x10010590;
// R6GameService.dll code @ 100107f5
constexpr unsigned int UR6GSServers_UR6GSServersCatch130 = 0x100107f5;
// R6GameService.dll code @ 10010809
constexpr unsigned int UR6GSServers_UR6GSServersCatch131 = 0x10010809;
// R6GameService.dll code @ 10010830
constexpr unsigned int SetSelectedProductCategory = 0x10010830;
// R6GameService.dll code @ 100109c0
constexpr unsigned int UR6GSServers_GSClientPostMessage = 0x100109c0;
// R6GameService.dll interior-code @ 100109fc
constexpr unsigned int GPostMessageDispatchCase1 = 0x100109fc;
// R6GameService.dll interior-code @ 10010a30
constexpr unsigned int GPostMessageDispatchCase2 = 0x10010a30;
// R6GameService.dll interior-code @ 10010a7f
constexpr unsigned int GPostMessageDispatchCase3 = 0x10010a7f;
// R6GameService.dll interior-code @ 10010ac1
constexpr unsigned int GPostMessageDispatchCase4 = 0x10010ac1;
// R6GameService.dll interior-code @ 10010af0
constexpr unsigned int GPostMessageDispatchCase5 = 0x10010af0;
// R6GameService.dll interior-code @ 10010b2c
constexpr unsigned int GPostMessageDispatchCase6 = 0x10010b2c;
// R6GameService.dll code @ 10010b6a
constexpr unsigned int UR6GSServers_UR6GSServersCatch132 = 0x10010b6a;
// R6GameService.dll code @ 10010b7e
constexpr unsigned int UR6GSServers_UR6GSServersCatch133 = 0x10010b7e;
// R6GameService.dll data @ 10010b9c
constexpr unsigned int GPostMessageDispatch = 0x10010b9c;
// R6GameService.dll code @ 10010bc0
constexpr unsigned int UR6GSServers_SetGSGameState = 0x10010bc0;
// R6GameService.dll interior-code @ 10010be7
constexpr unsigned int GGSStateLogDispatchCase1 = 0x10010be7;
// R6GameService.dll interior-code @ 10010bf1
constexpr unsigned int GGSStateLogDispatchCase2 = 0x10010bf1;
// R6GameService.dll interior-code @ 10010c0f
constexpr unsigned int GGSStateLogDispatchCase3 = 0x10010c0f;
// R6GameService.dll interior-code @ 10010c2d
constexpr unsigned int GGSStateLogDispatchCase4 = 0x10010c2d;
// R6GameService.dll interior-code @ 10010c34
constexpr unsigned int GGSStateLogDispatchCase5 = 0x10010c34;
// R6GameService.dll interior-code @ 10010c52
constexpr unsigned int GGSStateLogDispatchCase6 = 0x10010c52;
// R6GameService.dll interior-code @ 10010c70
constexpr unsigned int GGSStateLogDispatchCase7 = 0x10010c70;
// R6GameService.dll interior-code @ 10010c77
constexpr unsigned int GGSStateLogDispatchCase8 = 0x10010c77;
// R6GameService.dll interior-code @ 10010c92
constexpr unsigned int GGSStateLogDispatchCase9 = 0x10010c92;
// R6GameService.dll interior-code @ 10010cad
constexpr unsigned int GGSStateLogDispatchCase10 = 0x10010cad;
// R6GameService.dll interior-code @ 10010cc7
constexpr unsigned int GGSStateLogDispatchCase11 = 0x10010cc7;
// R6GameService.dll interior-code @ 10010d11
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase1 = 0x10010d11;
// R6GameService.dll interior-code @ 10010d31
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase2 = 0x10010d31;
// R6GameService.dll interior-code @ 10010d52
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase3 = 0x10010d52;
// R6GameService.dll interior-code @ 10010d73
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase4 = 0x10010d73;
// R6GameService.dll interior-code @ 10010d93
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase5 = 0x10010d93;
// R6GameService.dll interior-code @ 10010db4
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase6 = 0x10010db4;
// R6GameService.dll interior-code @ 10010dd5
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase7 = 0x10010dd5;
// R6GameService.dll interior-code @ 10010df5
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase8 = 0x10010df5;
// R6GameService.dll interior-code @ 10010e16
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase9 = 0x10010e16;
// R6GameService.dll interior-code @ 10010e37
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase10 = 0x10010e37;
// R6GameService.dll interior-code @ 10010e57
constexpr unsigned int UR6GSServersGGSStateLogDispatchCase11 = 0x10010e57;
// R6GameService.dll data @ 10010e9c
constexpr unsigned int GGSStateLogDispatch = 0x10010e9c;
// R6GameService.dll data @ 10010ec8
constexpr unsigned int UR6GSServersGGSStateLogDispatch = 0x10010ec8;
// R6GameService.dll code @ 10010f00
constexpr unsigned int UR6GSServers_GetGSGameState = 0x10010f00;
// R6GameService.dll code @ 10010f10
constexpr unsigned int UR6GSServers_execNativeIsWaitingForGSInit = 0x10010f10;
// R6GameService.dll code @ 10010f81
constexpr unsigned int UR6GSServers_UR6GSServersCatch134 = 0x10010f81;
// R6GameService.dll code @ 10010f95
constexpr unsigned int UR6GSServers_UR6GSServersCatch135 = 0x10010f95;
// R6GameService.dll code @ 10010fc0
constexpr unsigned int UR6GSServers_execNativeIsGSReadyToChangeMod = 0x10010fc0;
// R6GameService.dll code @ 1001101f
constexpr unsigned int UR6GSServers_UR6GSServersCatch136 = 0x1001101f;
// R6GameService.dll code @ 10011033
constexpr unsigned int UR6GSServers_UR6GSServersCatch137 = 0x10011033;
// R6GameService.dll code @ 10011070
constexpr unsigned int UR6GSServers_SetGSClientComInterface = 0x10011070;
// R6GameService.dll code @ 10011137
constexpr unsigned int UR6GSServers_UR6GSServersCatch138 = 0x10011137;
// R6GameService.dll code @ 1001114b
constexpr unsigned int UR6GSServers_UR6GSServersCatch139 = 0x1001114b;
// R6GameService.dll code @ 10011170
constexpr unsigned int UR6GSServers_ProcessSubmitMatchResultReply = 0x10011170;
// R6GameService.dll code @ 10011220
constexpr unsigned int UR6GSServers_PollGSClientCallbacks = 0x10011220;
// R6GameService.dll interior-code @ 100112c0
constexpr unsigned int GGSMessageDispatchCase3 = 0x100112c0;
// R6GameService.dll interior-code @ 100113d6
constexpr unsigned int GGSMessageDispatchCase4 = 0x100113d6;
// R6GameService.dll interior-code @ 100113f4
constexpr unsigned int GGSMessageDispatchCase1 = 0x100113f4;
// R6GameService.dll interior-code @ 10011463
constexpr unsigned int GGSMessageDispatchCase2 = 0x10011463;
// R6GameService.dll interior-code @ 1001147a
constexpr unsigned int GGSMessageDispatchCase5 = 0x1001147a;
// R6GameService.dll code @ 100117d3
constexpr unsigned int UR6GSServers_UR6GSServersCatch140 = 0x100117d3;
// R6GameService.dll code @ 100117e7
constexpr unsigned int UR6GSServers_UR6GSServersCatch141 = 0x100117e7;
// R6GameService.dll data @ 10011804
constexpr unsigned int GGSMessageDispatch = 0x10011804;
// R6GameService.dll code @ 10011820
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfo = 0x10011820;
// R6GameService.dll code @ 100119db
constexpr unsigned int UR6GSServers_UR6GSServersCatch142 = 0x100119db;
// R6GameService.dll code @ 100119ef
constexpr unsigned int UR6GSServers_UR6GSServersCatch143 = 0x100119ef;
// R6GameService.dll code @ 10011a10
constexpr unsigned int GetGameConfigCallback = 0x10011a10;
// R6GameService.dll code @ 10011b10
constexpr unsigned int DispatcherProc = 0x10011b10;
// R6GameService.dll interior-code @ 10011b72
constexpr unsigned int GDispatcherMessageSwitchCase1 = 0x10011b72;
// R6GameService.dll interior-code @ 10011c77
constexpr unsigned int GDispatcherMessageSwitchCase3 = 0x10011c77;
// R6GameService.dll interior-code @ 10011df3
constexpr unsigned int GDispatcherMessageSwitchCase2 = 0x10011df3;
// R6GameService.dll interior-code @ 10011e05
constexpr unsigned int GDispatcherMessageSwitchCase4 = 0x10011e05;
// R6GameService.dll interior-code @ 10011e27
constexpr unsigned int GDispatcherMessageSwitchCase5 = 0x10011e27;
// R6GameService.dll data @ 10011eac
constexpr unsigned int GDispatcherMessageSwitch = 0x10011eac;
// R6GameService.dll code @ 10011ec0
constexpr unsigned int UR6GSServers_InitGSClient = 0x10011ec0;
// R6GameService.dll code @ 10011f83
constexpr unsigned int UR6GSServers_UR6GSServersCatch144 = 0x10011f83;
// R6GameService.dll code @ 10011f97
constexpr unsigned int UR6GSServers_UR6GSServersCatch145 = 0x10011f97;
// R6GameService.dll code @ 10011fc0
constexpr unsigned int UR6GSServers_GetRegServerInitialized = 0x10011fc0;
// R6GameService.dll code @ 10011fd0
constexpr unsigned int UR6GSServers_UnInitRegServer = 0x10011fd0;
// R6GameService.dll code @ 10012060
constexpr unsigned int UR6GSServers_LogOutServer = 0x10012060;
// R6GameService.dll code @ 100120ae
constexpr unsigned int UR6GSServers_UR6GSServersCatch146 = 0x100120ae;
// R6GameService.dll code @ 100120c2
constexpr unsigned int UR6GSServers_UR6GSServersCatch147 = 0x100120c2;
// R6GameService.dll code @ 100120e0
constexpr unsigned int UR6GSServers_execNativeLogOutServer = 0x100120e0;
// R6GameService.dll code @ 10012177
constexpr unsigned int UR6GSServers_UR6GSServersCatch148 = 0x10012177;
// R6GameService.dll code @ 1001218b
constexpr unsigned int UR6GSServers_UR6GSServersCatch149 = 0x1001218b;
// R6GameService.dll code @ 100121b0
constexpr unsigned int UR6GSServers_RegisterServer = 0x100121b0;
// R6GameService.dll code @ 1001236a
constexpr unsigned int UR6GSServers_UR6GSServersCatch150 = 0x1001236a;
// R6GameService.dll code @ 1001237e
constexpr unsigned int UR6GSServers_UR6GSServersCatch151 = 0x1001237e;
// R6GameService.dll code @ 100123a0
constexpr unsigned int UR6GSServers_GetServerRegistered = 0x100123a0;
// R6GameService.dll code @ 100123b0
constexpr unsigned int UR6GSServers_UpdateServer = 0x100123b0;
// R6GameService.dll code @ 100124f3
constexpr unsigned int UR6GSServers_UR6GSServersCatch152 = 0x100124f3;
// R6GameService.dll code @ 10012507
constexpr unsigned int UR6GSServers_UR6GSServersCatch153 = 0x10012507;
// R6GameService.dll code @ 10012530
constexpr unsigned int UR6GSServers_execNativeUpdateServer = 0x10012530;
// R6GameService.dll code @ 10012599
constexpr unsigned int UR6GSServers_UR6GSServersCatch154 = 0x10012599;
// R6GameService.dll code @ 100125ad
constexpr unsigned int UR6GSServers_UR6GSServersCatch155 = 0x100125ad;
// R6GameService.dll code @ 100125d0
constexpr unsigned int UR6ServerList_GetLobbyID = 0x100125d0;
// R6GameService.dll code @ 100125e0
constexpr unsigned int UR6ServerList_GetGroupID = 0x100125e0;
// R6GameService.dll code @ 100125f0
constexpr unsigned int UR6GSServers_SetRegServerLoginRequest = 0x100125f0;
// R6GameService.dll code @ 10012600
constexpr unsigned int UR6GSServers_SetLoginRegServer = 0x10012600;
// R6GameService.dll code @ 10012610
constexpr unsigned int UR6GSServers_GetLoginRegServer = 0x10012610;
// R6GameService.dll code @ 10012620
constexpr unsigned int UR6GSServers_ServerLogin = 0x10012620;
// R6GameService.dll code @ 100126dd
constexpr unsigned int UR6GSServers_UR6GSServersCatch156 = 0x100126dd;
// R6GameService.dll code @ 100126f1
constexpr unsigned int UR6GSServers_UR6GSServersCatch157 = 0x100126f1;
// R6GameService.dll code @ 10012710
constexpr unsigned int UR6GSServers_RegServerRouterLogin = 0x10012710;
// R6GameService.dll code @ 10012800
constexpr unsigned int UR6GSServers_RouterDisconnect = 0x10012800;
// R6GameService.dll code @ 1001285d
constexpr unsigned int UR6GSServers_UR6GSServersCatch158 = 0x1001285d;
// R6GameService.dll code @ 10012871
constexpr unsigned int UR6GSServers_UR6GSServersCatch159 = 0x10012871;
// R6GameService.dll code @ 10012890
constexpr unsigned int UR6GSServers_RegServerGetLobbies = 0x10012890;
// R6GameService.dll code @ 10012903
constexpr unsigned int UR6GSServers_UR6GSServersCatch160 = 0x10012903;
// R6GameService.dll code @ 10012917
constexpr unsigned int UR6GSServers_UR6GSServersCatch161 = 0x10012917;
// R6GameService.dll code @ 10012940
constexpr unsigned int UR6GSServers_execHandleAnyLobbyConnectionFail = 0x10012940;
// R6GameService.dll code @ 100129c6
constexpr unsigned int UR6GSServers_UR6GSServersCatch162 = 0x100129c6;
// R6GameService.dll code @ 100129da
constexpr unsigned int UR6GSServers_UR6GSServersCatch163 = 0x100129da;
// R6GameService.dll code @ 10012a00
constexpr unsigned int UR6GSServers_InitProcessUpdateUbiServer = 0x10012a00;
// R6GameService.dll code @ 10012a76
constexpr unsigned int UR6GSServers_UR6GSServersCatch164 = 0x10012a76;
// R6GameService.dll code @ 10012a8a
constexpr unsigned int UR6GSServers_UR6GSServersCatch165 = 0x10012a8a;
// R6GameService.dll code @ 10012ab0
constexpr unsigned int UR6GSServers_SetGameServiceRequestState = 0x10012ab0;
// R6GameService.dll code @ 10012ac0
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRouterRequest = 0x10012ac0;
// R6GameService.dll interior-code @ 10012afe
constexpr unsigned int GProcessRegServerLoginRouterRequestSwitchCase1 = 0x10012afe;
// R6GameService.dll code @ 10012b2b
constexpr unsigned int UR6GSServers_UR6GSServersCatch166 = 0x10012b2b;
// R6GameService.dll code @ 10012b3f
constexpr unsigned int UR6GSServers_UR6GSServersCatch167 = 0x10012b3f;
// R6GameService.dll interior-code @ 10012b5b
constexpr unsigned int GProcessRegServerLoginRouterRequestSwitchCase2 = 0x10012b5b;
// R6GameService.dll interior-code @ 10012b8e
constexpr unsigned int GProcessRegServerLoginRouterRequestSwitchCase3 = 0x10012b8e;
// R6GameService.dll interior-code @ 10012b9a
constexpr unsigned int GProcessRegServerLoginRouterRequestSwitchCase6 = 0x10012b9a;
// R6GameService.dll interior-code @ 10012baa
constexpr unsigned int UR6GSServersBranch412 = 0x10012baa;
// R6GameService.dll data @ 10012bbc
constexpr unsigned int GProcessRegServerLoginRouterRequestSwitch = 0x10012bbc;
// R6GameService.dll code @ 10012be0
constexpr unsigned int UR6GSServers_ProcessRegServerGetLobbiesRequest = 0x10012be0;
// R6GameService.dll interior-code @ 10012c1e
constexpr unsigned int GProcessRegServerGetLobbiesRequestSwitchCase1 = 0x10012c1e;
// R6GameService.dll code @ 10012c4b
constexpr unsigned int UR6GSServers_UR6GSServersCatch168 = 0x10012c4b;
// R6GameService.dll code @ 10012c5f
constexpr unsigned int UR6GSServers_UR6GSServersCatch169 = 0x10012c5f;
// R6GameService.dll interior-code @ 10012c7b
constexpr unsigned int GProcessRegServerGetLobbiesRequestSwitchCase2 = 0x10012c7b;
// R6GameService.dll interior-code @ 10012cae
constexpr unsigned int GProcessRegServerGetLobbiesRequestSwitchCase3 = 0x10012cae;
// R6GameService.dll interior-code @ 10012cba
constexpr unsigned int GProcessRegServerGetLobbiesRequestSwitchCase6 = 0x10012cba;
// R6GameService.dll interior-code @ 10012cca
constexpr unsigned int UR6GSServersBranch414 = 0x10012cca;
// R6GameService.dll data @ 10012cdc
constexpr unsigned int GProcessRegServerGetLobbiesRequestSwitch = 0x10012cdc;
// R6GameService.dll code @ 10012d00
constexpr unsigned int UR6GSServers_ProcessRegServerRegOnLobbyRequest = 0x10012d00;
// R6GameService.dll interior-code @ 10012d3e
constexpr unsigned int GProcessRegServerRegOnLobbyRequestSwitchCase1 = 0x10012d3e;
// R6GameService.dll code @ 10012d79
constexpr unsigned int UR6GSServers_UR6GSServersCatch170 = 0x10012d79;
// R6GameService.dll code @ 10012d8d
constexpr unsigned int UR6GSServers_UR6GSServersCatch171 = 0x10012d8d;
// R6GameService.dll interior-code @ 10012da9
constexpr unsigned int GProcessRegServerRegOnLobbyRequestSwitchCase2 = 0x10012da9;
// R6GameService.dll interior-code @ 10012ddc
constexpr unsigned int GProcessRegServerRegOnLobbyRequestSwitchCase3 = 0x10012ddc;
// R6GameService.dll interior-code @ 10012de8
constexpr unsigned int GProcessRegServerRegOnLobbyRequestSwitchCase6 = 0x10012de8;
// R6GameService.dll interior-code @ 10012df8
constexpr unsigned int UR6GSServersBranch416 = 0x10012df8;
// R6GameService.dll data @ 10012e0c
constexpr unsigned int GProcessRegServerRegOnLobbyRequestSwitch = 0x10012e0c;
// R6GameService.dll code @ 10012e30
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRequest = 0x10012e30;
// R6GameService.dll interior-code @ 10012e6a
constexpr unsigned int GProcessRegServerLoginRequestSwitchCase1 = 0x10012e6a;
// R6GameService.dll interior-code @ 10012e86
constexpr unsigned int UR6GSServersBranch417 = 0x10012e86;
// R6GameService.dll interior-code @ 10012e97
constexpr unsigned int GProcessRegServerLoginRequestSwitchCase2 = 0x10012e97;
// R6GameService.dll interior-code @ 10012eca
constexpr unsigned int GProcessRegServerLoginRequestSwitchCase3 = 0x10012eca;
// R6GameService.dll interior-code @ 10012eeb
constexpr unsigned int GProcessRegServerLoginRequestSwitchCase6 = 0x10012eeb;
// R6GameService.dll code @ 10012f13
constexpr unsigned int UR6GSServers_UR6GSServersCatch172 = 0x10012f13;
// R6GameService.dll code @ 10012f27
constexpr unsigned int UR6GSServers_UR6GSServersCatch173 = 0x10012f27;
// R6GameService.dll data @ 10012f44
constexpr unsigned int GProcessRegServerLoginRequestSwitch = 0x10012f44;
// R6GameService.dll code @ 10012f60
constexpr unsigned int UR6GSServers_ProcessRegServerUpdateRequest = 0x10012f60;
// R6GameService.dll interior-code @ 10012f9e
constexpr unsigned int GProcessRegServerUpdateRequestSwitchCase1 = 0x10012f9e;
// R6GameService.dll code @ 10012fcb
constexpr unsigned int UR6GSServers_UR6GSServersCatch174 = 0x10012fcb;
// R6GameService.dll code @ 10012fdf
constexpr unsigned int UR6GSServers_UR6GSServersCatch175 = 0x10012fdf;
// R6GameService.dll interior-code @ 10012ffb
constexpr unsigned int GProcessRegServerUpdateRequestSwitchCase2 = 0x10012ffb;
// R6GameService.dll interior-code @ 1001302e
constexpr unsigned int GProcessRegServerUpdateRequestSwitchCase3 = 0x1001302e;
// R6GameService.dll interior-code @ 10013034
constexpr unsigned int UR6GSServersBranch418 = 0x10013034;
// R6GameService.dll data @ 10013048
constexpr unsigned int GProcessRegServerUpdateRequestSwitch = 0x10013048;
// R6GameService.dll code @ 10013060
constexpr unsigned int RegServerRcv_LobbyServerMatchStartReply = 0x10013060;
// R6GameService.dll code @ 100130b0
constexpr unsigned int RegServerRcv_LobbyServerMatchFinishReply = 0x100130b0;
// R6GameService.dll code @ 100130e0
constexpr unsigned int RegServerRcv_LoginRouterResult = 0x100130e0;
// R6GameService.dll code @ 10013160
constexpr unsigned int RegServerRcv_LoginDisconnection = 0x10013160;
// R6GameService.dll code @ 10013180
constexpr unsigned int RegServerRcv_RegisterServerResult = 0x10013180;
// R6GameService.dll code @ 10013210
constexpr unsigned int ReceiveSecondaryLobbyLoginResults = 0x10013210;
// R6GameService.dll code @ 10013290
constexpr unsigned int RegServerRcv_LobbyServerUpdateGroupSettingsResults = 0x10013290;
// R6GameService.dll code @ 100132d0
constexpr unsigned int RegServerRcv_LobbyServerDisconnection = 0x100132d0;
// R6GameService.dll code @ 10013300
constexpr unsigned int RegServerRcv_LobbyServerNewMember = 0x10013300;
// R6GameService.dll code @ 10013330
constexpr unsigned int UR6GSServers_PollRegServerCallbacks = 0x10013330;
// R6GameService.dll code @ 10013420
constexpr unsigned int UR6GSServers_ServerRoundStart = 0x10013420;
// R6GameService.dll code @ 1001352d
constexpr unsigned int UR6GSServers_UR6GSServersCatch176 = 0x1001352d;
// R6GameService.dll code @ 10013541
constexpr unsigned int UR6GSServers_UR6GSServersCatch177 = 0x10013541;
// R6GameService.dll code @ 10013560
constexpr unsigned int UR6GSServers_ServerRoundFinish = 0x10013560;
// R6GameService.dll code @ 1001360f
constexpr unsigned int UR6GSServers_UR6GSServersCatch178 = 0x1001360f;
// R6GameService.dll code @ 10013623
constexpr unsigned int UR6GSServers_UR6GSServersCatch179 = 0x10013623;
// R6GameService.dll code @ 10013640
constexpr unsigned int RegServerRcv_RequestParentGroupResult = 0x10013640;
// R6GameService.dll code @ 100136d0
constexpr unsigned int InstallRegistrationServiceCallbacks = 0x100136d0;
// R6GameService.dll code @ 10013740
constexpr unsigned int unreal_array_support_DestroyArrayStorage6 = 0x10013740;
// R6GameService.dll code @ 100137d0
constexpr unsigned int UR6GSServers_InitializeRegServer = 0x100137d0;
// R6GameService.dll code @ 10013926
constexpr unsigned int UR6GSServers_UR6GSServersCatch180 = 0x10013926;
// R6GameService.dll code @ 1001393a
constexpr unsigned int UR6GSServers_UR6GSServersCatch181 = 0x1001393a;
// R6GameService.dll code @ 10013990
constexpr unsigned int UR6GSServers_ProcessInternetSrv = 0x10013990;
// R6GameService.dll interior-code @ 10013a0c
constexpr unsigned int GProcessInternetSrvSwitchCase2 = 0x10013a0c;
// R6GameService.dll interior-code @ 10013a54
constexpr unsigned int GProcessInternetSrvSwitchCase3 = 0x10013a54;
// R6GameService.dll interior-code @ 10013a81
constexpr unsigned int GProcessInternetSrvSwitchCase4 = 0x10013a81;
// R6GameService.dll interior-code @ 10013adb
constexpr unsigned int GProcessInternetSrvSwitchCase5 = 0x10013adb;
// R6GameService.dll interior-code @ 10013af4
constexpr unsigned int GProcessInternetSrvSwitchCase1 = 0x10013af4;
// R6GameService.dll code @ 10013c6c
constexpr unsigned int UR6GSServers_UR6GSServersCatch182 = 0x10013c6c;
// R6GameService.dll code @ 10013c80
constexpr unsigned int UR6GSServers_UR6GSServersCatch183 = 0x10013c80;
// R6GameService.dll data @ 10013c9c
constexpr unsigned int GProcessInternetSrvSwitch = 0x10013c9c;
// R6GameService.dll code @ 10013cb0
constexpr unsigned int PingChecksum = 0x10013cb0;
// R6GameService.dll code @ 10013d10
constexpr unsigned int BuildPingPacket = 0x10013d10;
// R6GameService.dll code @ 10013d90
constexpr unsigned int ReadPingReply = 0x10013d90;
// R6GameService.dll code @ 10013dd0
constexpr unsigned int ServerPing_GetPingTime = 0x10013dd0;
// R6GameService.dll code @ 10014004
constexpr unsigned int ServerPingCatch = 0x10014004;
// R6GameService.dll code @ 10014018
constexpr unsigned int ServerPing_ServerPingCatch = 0x10014018;
// R6GameService.dll code @ 10014040
constexpr unsigned int ReadSecondWord = 0x10014040;
// R6GameService.dll code @ 10014050
constexpr unsigned int DestroyPingRecord = 0x10014050;
// R6GameService.dll code @ 100140b0
constexpr unsigned int ServerPing_NewPingRequest = 0x100140b0;
// R6GameService.dll code @ 100141c0
constexpr unsigned int ServerPing_ServerPingCatch2 = 0x100141c0;
// R6GameService.dll code @ 100141d4
constexpr unsigned int ServerPing_ServerPingCatch3 = 0x100141d4;
// R6GameService.dll code @ 10014200
constexpr unsigned int ServerPing_SendPingToServer = 0x10014200;
// R6GameService.dll code @ 10014363
constexpr unsigned int ServerPing_ServerPingCatch4 = 0x10014363;
// R6GameService.dll code @ 10014377
constexpr unsigned int ServerPing_ServerPingCatch5 = 0x10014377;
// R6GameService.dll code @ 100143a0
constexpr unsigned int RemovePingRecordRange = 0x100143a0;
// R6GameService.dll code @ 10014440
constexpr unsigned int ServerPing_PingManager = 0x10014440;
// R6GameService.dll code @ 10014846
constexpr unsigned int ServerPing_ServerPingCatch6 = 0x10014846;
// R6GameService.dll code @ 1001485a
constexpr unsigned int ServerPing_ServerPingCatch7 = 0x1001485a;
// R6GameService.dll code @ 100148a0
constexpr unsigned int DestroyPingRequestArray = 0x100148a0;
// R6GameService.dll code @ 100148f0
constexpr unsigned int InitializePingRequestArray = 0x100148f0;
// R6GameService.dll code @ 10014940
constexpr unsigned int CleanupWinsockAndPingRequests = 0x10014940;
// R6GameService.dll code @ 10014980
constexpr unsigned int core_import_supportTailImportedMember = 0x10014980;
// R6GameService.dll code @ 10014986
constexpr unsigned int core_import_support_core_import_supportTailImportedMember = 0x10014986;
// R6GameService.dll code @ 1001498c
constexpr unsigned int core_import_support_core_import_supportTailImportedMember2 = 0x1001498c;
// R6GameService.dll code @ 10014992
constexpr unsigned int core_import_support_core_import_supportTailImportedMember3 = 0x10014992;
// R6GameService.dll code @ 10014998
constexpr unsigned int core_import_support_core_import_supportTailImportedMember4 = 0x10014998;
// R6GameService.dll code @ 1001499e
constexpr unsigned int core_import_support_core_import_supportTailImportedMember5 = 0x1001499e;
// R6GameService.dll code @ 100149a4
constexpr unsigned int core_import_support_core_import_supportTailImportedMember6 = 0x100149a4;
// R6GameService.dll code @ 100149aa
constexpr unsigned int core_import_support_core_import_supportTailImportedMember7 = 0x100149aa;
// R6GameService.dll code @ 100149b0
constexpr unsigned int core_import_support_core_import_supportTailImportedMember8 = 0x100149b0;
// R6GameService.dll code @ 100149b6
constexpr unsigned int core_import_support_core_import_supportTailImportedMember9 = 0x100149b6;
// R6GameService.dll code @ 100149bc
constexpr unsigned int core_import_support_core_import_supportTailImportedMember10 = 0x100149bc;
// R6GameService.dll code @ 100149c2
constexpr unsigned int core_import_support_core_import_supportTailImportedMember11 = 0x100149c2;
// R6GameService.dll code @ 100149c8
constexpr unsigned int core_import_support_core_import_supportTailImportedMember12 = 0x100149c8;
// R6GameService.dll code @ 100149ce
constexpr unsigned int core_import_support_core_import_supportTailImportedMember13 = 0x100149ce;
// R6GameService.dll code @ 100149d4
constexpr unsigned int core_import_support_core_import_supportTailImportedMember14 = 0x100149d4;
// R6GameService.dll code @ 100149da
constexpr unsigned int core_import_support_core_import_supportTailImportedMember15 = 0x100149da;
// R6GameService.dll code @ 100149e0
constexpr unsigned int core_import_support_core_import_supportTailImportedMember16 = 0x100149e0;
// R6GameService.dll code @ 100149e6
constexpr unsigned int core_import_support_core_import_supportTailImportedMember17 = 0x100149e6;
// R6GameService.dll code @ 100149ec
constexpr unsigned int core_import_support_core_import_supportTailImportedMember18 = 0x100149ec;
// R6GameService.dll code @ 100149f2
constexpr unsigned int core_import_support_core_import_supportTailImportedMember19 = 0x100149f2;
// R6GameService.dll code @ 100149f8
constexpr unsigned int UObject_ProcessEvent = 0x100149f8;
// R6GameService.dll code @ 100149fe
constexpr unsigned int core_import_support_core_import_supportTailImportedMember20 = 0x100149fe;
// R6GameService.dll code @ 10014a04
constexpr unsigned int core_import_support_core_import_supportTailImportedMember21 = 0x10014a04;
// R6GameService.dll code @ 10014a0a
constexpr unsigned int core_import_support_core_import_supportTailImportedMember22 = 0x10014a0a;
// R6GameService.dll code @ 10014a10
constexpr unsigned int getGameShutDown = 0x10014a10;
// R6GameService.dll code @ 10014a16
constexpr unsigned int core_import_support_core_import_supportTailImportedMember23 = 0x10014a16;
// R6GameService.dll code @ 10014a1c
constexpr unsigned int core_import_support_core_import_supportTailImportedMember24 = 0x10014a1c;
// R6GameService.dll code @ 10014a22
constexpr unsigned int core_import_support_core_import_supportTailImportedMember25 = 0x10014a22;
// R6GameService.dll code @ 10014a28
constexpr unsigned int core_import_support_core_import_supportTailImportedMember26 = 0x10014a28;
// R6GameService.dll code @ 10014a2e
constexpr unsigned int core_import_support_core_import_supportTailImportedMember27 = 0x10014a2e;
// R6GameService.dll code @ 10014a34
constexpr unsigned int core_import_support_core_import_supportTailImportedMember28 = 0x10014a34;
// R6GameService.dll code @ 10014a3a
constexpr unsigned int core_import_support_core_import_supportTailImportedMember29 = 0x10014a3a;
// R6GameService.dll code @ 10014a40
constexpr unsigned int core_import_support_core_import_supportTailImportedMember30 = 0x10014a40;
// R6GameService.dll code @ 10014a46
constexpr unsigned int core_import_support_core_import_supportTailImportedMember31 = 0x10014a46;
// R6GameService.dll code @ 10014a4c
constexpr unsigned int core_import_support_core_import_supportTailImportedMember32 = 0x10014a4c;
// R6GameService.dll code @ 10014a52
constexpr unsigned int core_import_support_core_import_supportTailImportedMember33 = 0x10014a52;
// R6GameService.dll code @ 10014a58
constexpr unsigned int core_import_support_core_import_supportTailImportedMember34 = 0x10014a58;
// R6GameService.dll code @ 10014a5e
constexpr unsigned int core_import_support_core_import_supportTailImportedMember35 = 0x10014a5e;
// R6GameService.dll code @ 10014a64
constexpr unsigned int core_import_support_core_import_supportTailImportedMember36 = 0x10014a64;
// R6GameService.dll code @ 10014a6a
constexpr unsigned int core_import_support_core_import_supportTailImportedMember37 = 0x10014a6a;
// R6GameService.dll code @ 10014a70
constexpr unsigned int core_import_support_core_import_supportTailImportedMember38 = 0x10014a70;
// R6GameService.dll code @ 10014a76
constexpr unsigned int core_import_support_core_import_supportTailImportedMember39 = 0x10014a76;
// R6GameService.dll code @ 10014a7c
constexpr unsigned int core_import_support_core_import_supportTailImportedMember40 = 0x10014a7c;
// R6GameService.dll code @ 10014a82
constexpr unsigned int core_import_support_core_import_supportTailImportedMember41 = 0x10014a82;
// R6GameService.dll code @ 10014a88
constexpr unsigned int core_import_support_core_import_supportTailImportedMember42 = 0x10014a88;
// R6GameService.dll code @ 10014a8e
constexpr unsigned int core_import_support_core_import_supportTailImportedMember43 = 0x10014a8e;
// R6GameService.dll code @ 10014a94
constexpr unsigned int core_import_support_core_import_supportTailImportedMember44 = 0x10014a94;
// R6GameService.dll code @ 10014a9a
constexpr unsigned int core_import_support_core_import_supportTailImportedMember45 = 0x10014a9a;
// R6GameService.dll code @ 10014aa0
constexpr unsigned int core_import_support_core_import_supportTailImportedMember46 = 0x10014aa0;
// R6GameService.dll code @ 10014aa6
constexpr unsigned int core_import_support_core_import_supportTailImportedMember47 = 0x10014aa6;
// R6GameService.dll code @ 10014aac
constexpr unsigned int core_import_support_core_import_supportTailImportedMember48 = 0x10014aac;
// R6GameService.dll code @ 10014ab2
constexpr unsigned int core_import_support_core_import_supportTailImportedMember49 = 0x10014ab2;
// R6GameService.dll code @ 10014ab8
constexpr unsigned int core_import_support_core_import_supportTailImportedMember50 = 0x10014ab8;
// R6GameService.dll code @ 10014abe
constexpr unsigned int core_import_support_core_import_supportTailImportedMember51 = 0x10014abe;
// R6GameService.dll code @ 10014ac4
constexpr unsigned int core_import_support_core_import_supportTailImportedMember52 = 0x10014ac4;
// R6GameService.dll code @ 10014aca
constexpr unsigned int core_import_support_core_import_supportTailImportedMember53 = 0x10014aca;
// R6GameService.dll code @ 10014ad0
constexpr unsigned int core_import_support_core_import_supportTailImportedMember54 = 0x10014ad0;
// R6GameService.dll code @ 10014ad6
constexpr unsigned int core_import_support_core_import_supportTailImportedMember55 = 0x10014ad6;
// R6GameService.dll code @ 10014ae0
constexpr unsigned int TailForwardServiceWrapperRegistration = 0x10014ae0;
// R6GameService.dll code @ 10014af0
constexpr unsigned int ReleaseRegisteredServiceWrapper = 0x10014af0;
// R6GameService.dll code @ 10014b10
constexpr unsigned int QueueServiceDownload = 0x10014b10;
// R6GameService.dll code @ 10014b30
constexpr unsigned int CreateRegisteredServiceWrapper = 0x10014b30;
// R6GameService.dll code @ 10014c70
constexpr unsigned int RemoveServiceWrapperRegistration = 0x10014c70;
// R6GameService.dll code @ 10014cb0
constexpr unsigned int ReleaseServiceWrapperRegistry = 0x10014cb0;
// R6GameService.dll code @ 10014cd0
constexpr unsigned int DispatchServiceDownload = 0x10014cd0;
// R6GameService.dll code @ 10014d00
constexpr unsigned int ForwardToAllocatorTail = 0x10014d00;
// R6GameService.dll code @ 10014d10
constexpr unsigned int DeleteHttpDownloadPointerMap = 0x10014d10;
// R6GameService.dll code @ 10014d30
constexpr unsigned int DestroyHttpDownloadPointerMap = 0x10014d30;
// R6GameService.dll code @ 10014df0
constexpr unsigned int ReleaseCountedTreeAndHeader = 0x10014df0;
// R6GameService.dll code @ 10014e80
constexpr unsigned int EraseHttpDownloadPointerMapRange = 0x10014e80;
// R6GameService.dll code @ 10014fc0
constexpr unsigned int ReleaseServiceTreeNodes = 0x10014fc0;
// R6GameService.dll code @ 10014ff0
constexpr unsigned int RemoveOrderedTreeNode = 0x10014ff0;
// R6GameService.dll code @ 100153b0
constexpr unsigned int OrderedTreeSuccessor = 0x100153b0;
// R6GameService.dll code @ 100153f0
constexpr unsigned int OrderedTreePredecessor = 0x100153f0;
// R6GameService.dll code @ 10015430
constexpr unsigned int RotateOrderedTreeLeft = 0x10015430;
// R6GameService.dll code @ 10015480
constexpr unsigned int RotateOrderedTreeRight = 0x10015480;
// R6GameService.dll code @ 100154d0
constexpr unsigned int InitializeHttpRequestRecord = 0x100154d0;
// R6GameService.dll code @ 10015790
constexpr unsigned int DestroyRecordAndOptionallyFree = 0x10015790;
// R6GameService.dll code @ 100157b0
constexpr unsigned int thunk_DestroyStringRecordRange = 0x100157b0;
// R6GameService.dll code @ 100157c0
constexpr unsigned int DestroyStringRecordRange = 0x100157c0;
// R6GameService.dll code @ 10015840
constexpr unsigned int DestroyServiceObjectMembers = 0x10015840;
// R6GameService.dll code @ 10015940
constexpr unsigned int CHttpRequestOpenTcp = 0x10015940;
// R6GameService.dll code @ 10015970
constexpr unsigned int CHttpRequestCloseTcp = 0x10015970;
// R6GameService.dll code @ 10015990
constexpr unsigned int CHttpRequestAccumulateHeader = 0x10015990;
// R6GameService.dll code @ 10015a70
constexpr unsigned int CHttpRequestAcceptBodyChunk = 0x10015a70;
// R6GameService.dll code @ 10015b60
constexpr unsigned int CHttpRequestParseHeader = 0x10015b60;
// R6GameService.dll code @ 10016230
constexpr unsigned int DeleteExtallocOverrideBase = 0x10016230;
// R6GameService.dll code @ 10016250
constexpr unsigned int CHttpRequestSubmitGet = 0x10016250;
// R6GameService.dll code @ 100162e0
constexpr unsigned int CHttpRequestOpenOutput = 0x100162e0;
// R6GameService.dll code @ 10016360
constexpr unsigned int CHttpRequestCloseOutput = 0x10016360;
// R6GameService.dll code @ 10016390
constexpr unsigned int CHttpRequestNotifyCompletion = 0x10016390;
// R6GameService.dll code @ 10016410
constexpr unsigned int CHttpRequestDeliverData = 0x10016410;
// R6GameService.dll code @ 10016490
constexpr unsigned int ConstructCHttpDownload = 0x10016490;
// R6GameService.dll code @ 10016500
constexpr unsigned int DestroyOrderedTreeWrapperAndMaybeFree = 0x10016500;
// R6GameService.dll code @ 10016520
constexpr unsigned int DestroyOrderedTreeWrapperContents = 0x10016520;
// R6GameService.dll code @ 100165c0
constexpr unsigned int DestroyOrderedTreeWrapperContentsThunk = 0x100165c0;
// R6GameService.dll code @ 100165d0
constexpr unsigned int ordered_tree_support_DestroyOrderedTreeWrapperContents = 0x100165d0;
// R6GameService.dll code @ 10016660
constexpr unsigned int QueueHttpRequest = 0x10016660;
// R6GameService.dll code @ 100167b0
constexpr unsigned int AdvanceHttpRequestState = 0x100167b0;
// R6GameService.dll interior-code @ 10016834
constexpr unsigned int GHttpRequestStateTargetsCase1 = 0x10016834;
// R6GameService.dll interior-code @ 10016894
constexpr unsigned int GHttpRequestStateTargetsCase2 = 0x10016894;
// R6GameService.dll interior-code @ 100168e8
constexpr unsigned int GHttpRequestStateTargetsCase3 = 0x100168e8;
// R6GameService.dll interior-code @ 1001693c
constexpr unsigned int GHttpRequestStateTargetsCase4 = 0x1001693c;
// R6GameService.dll interior-code @ 1001696b
constexpr unsigned int GHttpRequestStateTargetsCase5 = 0x1001696b;
// R6GameService.dll interior-code @ 100169fc
constexpr unsigned int GHttpRequestStateTargetsCase6 = 0x100169fc;
// R6GameService.dll data @ 10016a68
constexpr unsigned int GHttpRequestStateTargets = 0x10016a68;
// R6GameService.dll code @ 10016a80
constexpr unsigned int ParseHttpUrlIntoRequestFields = 0x10016a80;
// R6GameService.dll code @ 10016dd0
constexpr unsigned int RemoveCompletedRequestsFromTree = 0x10016dd0;
// R6GameService.dll code @ 10016e40
constexpr unsigned int ClearRequestTree = 0x10016e40;
// R6GameService.dll code @ 10016ed0
constexpr unsigned int MapHttpStatusToRequestError = 0x10016ed0;
// R6GameService.dll interior-code @ 10016eef
constexpr unsigned int GHttpStatusTargetsCase1 = 0x10016eef;
// R6GameService.dll interior-code @ 10016ef4
constexpr unsigned int GHttpStatusTargetsCase2 = 0x10016ef4;
// R6GameService.dll interior-code @ 10016efc
constexpr unsigned int GHttpStatusTargetsCase3 = 0x10016efc;
// R6GameService.dll interior-code @ 10016f04
constexpr unsigned int GHttpStatusTargetsCase4 = 0x10016f04;
// R6GameService.dll interior-code @ 10016f0c
constexpr unsigned int GHttpStatusTargetsCase5 = 0x10016f0c;
// R6GameService.dll interior-code @ 10016f14
constexpr unsigned int http_request_supportBranch4 = 0x10016f14;
// R6GameService.dll data @ 10016f1c
constexpr unsigned int GHttpStatusTargets = 0x10016f1c;
// R6GameService.dll data @ 10016f34
constexpr unsigned int GHttpStatusIndex = 0x10016f34;
// R6GameService.dll code @ 10017010
constexpr unsigned int DestroyHttpClient = 0x10017010;
// R6GameService.dll code @ 10017030
constexpr unsigned int DestroyHttpClientBase = 0x10017030;
// R6GameService.dll code @ 10017040
constexpr unsigned int CopyByteStringRange = 0x10017040;
// R6GameService.dll code @ 100171b0
constexpr unsigned int STLNamedExceptionWhat = 0x100171b0;
// R6GameService.dll code @ 100171c0
constexpr unsigned int ConstructException75c10 = 0x100171c0;
// R6GameService.dll code @ 10017200
constexpr unsigned int ConstructException75c28 = 0x10017200;
// R6GameService.dll code @ 10017240
constexpr unsigned int DestroyExceptionAndMaybeFree = 0x10017240;
// R6GameService.dll code @ 10017260
constexpr unsigned int MsvcExceptionDestructor = 0x10017260;
// R6GameService.dll code @ 10017270
constexpr unsigned int CopySTLNamedException = 0x10017270;
// R6GameService.dll code @ 100172a0
constexpr unsigned int CopySTLOutOfRange = 0x100172a0;
// R6GameService.dll code @ 100172d0
constexpr unsigned int CopySTLLogicError = 0x100172d0;
// R6GameService.dll code @ 10017300
constexpr unsigned int CopySTLLengthError = 0x10017300;
// R6GameService.dll code @ 10017330
constexpr unsigned int ReleasePooledBuffer = 0x10017330;
// R6GameService.dll code @ 100173c0
constexpr unsigned int RebuildThreeWordArray = 0x100173c0;
// R6GameService.dll code @ 1001750c
constexpr unsigned int string_record_supportCatch = 0x1001750c;
// R6GameService.dll code @ 10017550
constexpr unsigned int AcquireBufferPoolLock = 0x10017550;
// R6GameService.dll code @ 10017640
constexpr unsigned int ConstructPooledByteString = 0x10017640;
// R6GameService.dll code @ 10017790
constexpr unsigned int pooled_string_support_AcquireBufferPoolLock = 0x10017790;
// R6GameService.dll code @ 10017880
constexpr unsigned int ReleaseBufferPoolLock = 0x10017880;
// R6GameService.dll code @ 10017890
constexpr unsigned int FreeOrderedTreeNodes = 0x10017890;
// R6GameService.dll code @ 100178c0
constexpr unsigned int ByteStringEqualsAnsi = 0x100178c0;
// R6GameService.dll code @ 10017900
constexpr unsigned int CopyStringRecordRange = 0x10017900;
// R6GameService.dll code @ 1001799c
constexpr unsigned int string_record_support_string_record_supportCatch = 0x1001799c;
// R6GameService.dll code @ 100179e0
constexpr unsigned int RepeatStringRecord = 0x100179e0;
// R6GameService.dll code @ 10017a7a
constexpr unsigned int string_record_support_string_record_supportCatch2 = 0x10017a7a;
// R6GameService.dll code @ 10017ac0
constexpr unsigned int ReleaseGlobalByteStringPoolLock = 0x10017ac0;
// R6GameService.dll code @ 10017ad0
constexpr unsigned int InitializeByteStringFromRange = 0x10017ad0;
// R6GameService.dll code @ 10017b50
constexpr unsigned int ThrowByteStringLengthError = 0x10017b50;
// R6GameService.dll code @ 10017c20
constexpr unsigned int AllocateSmallByteStringBlock = 0x10017c20;
// R6GameService.dll code @ 10017dd0
constexpr unsigned int ConstructHeapByteString = 0x10017dd0;
// R6GameService.dll code @ 10017ee0
constexpr unsigned int AllocatePooledByteStringBlock = 0x10017ee0;
// R6GameService.dll code @ 10018050
constexpr unsigned int AllocatePairTreeNode = 0x10018050;
// R6GameService.dll code @ 10018080
constexpr unsigned int ConstructWordBytePair = 0x10018080;
// R6GameService.dll code @ 100180a0
constexpr unsigned int InitializeStringRange = 0x100180a0;
// R6GameService.dll code @ 10018100
constexpr unsigned int FindByteInRange = 0x10018100;
// R6GameService.dll code @ 10018160
constexpr unsigned int RebalanceOrderedTreeAfterInsertion = 0x10018160;
// R6GameService.dll code @ 10018310
constexpr unsigned int AllocatePooledBlocks = 0x10018310;
// R6GameService.dll code @ 10018440
constexpr unsigned int InitializePooledByteString = 0x10018440;
// R6GameService.dll code @ 100184a0
constexpr unsigned int InitializeHeapByteString = 0x100184a0;
// R6GameService.dll code @ 100184e0
constexpr unsigned int AppendByteRange = 0x100184e0;
// R6GameService.dll code @ 10018560
constexpr unsigned int AppendByteRangeWithGrowth = 0x10018560;
// R6GameService.dll code @ 10018650
constexpr unsigned int LoadAndInitializeGSClient = 0x10018650;
// R6GameService.dll code @ 100188e0
constexpr unsigned int ConnectLoadedGSClient = 0x100188e0;
// R6GameService.dll code @ 10018900
constexpr unsigned int GetLoadedGSClientMessage = 0x10018900;
// R6GameService.dll code @ 10018920
constexpr unsigned int DispatchLoadedGSClientMessage = 0x10018920;
// R6GameService.dll code @ 10018940
constexpr unsigned int PostLoadedGSClientMessage = 0x10018940;
// R6GameService.dll code @ 10018960
constexpr unsigned int AllocateLoadedGSClientMessage = 0x10018960;
// R6GameService.dll code @ 10018980
constexpr unsigned int DeleteLoadedGSClientMessage = 0x10018980;
// R6GameService.dll code @ 100189a0
constexpr unsigned int InitializeSerializedByteStore = 0x100189a0;
// R6GameService.dll code @ 10018a20
constexpr unsigned int DestroySerializedByteStore = 0x10018a20;
// R6GameService.dll code @ 10018a40
constexpr unsigned int DestroySerializedByteStoreContents = 0x10018a40;
// R6GameService.dll code @ 10018a70
constexpr unsigned int DestroyStoredValueTree = 0x10018a70;
// R6GameService.dll code @ 10018b00
constexpr unsigned int ResetSerializedByteStore = 0x10018b00;
// R6GameService.dll code @ 10018b30
constexpr unsigned int LoadSerializedByteStore = 0x10018b30;
// R6GameService.dll code @ 10018c20
constexpr unsigned int CopyStoredBytesToVariant = 0x10018c20;
// R6GameService.dll code @ 10018d30
constexpr unsigned int GetStoredBytesPointer = 0x10018d30;
// R6GameService.dll code @ 10018d90
constexpr unsigned int GetStoredBytesLength = 0x10018d90;
// R6GameService.dll code @ 10018df0
constexpr unsigned int GetStoredValueCount = 0x10018df0;
// R6GameService.dll code @ 10018e00
constexpr unsigned int ReadStoredValue = 0x10018e00;
// R6GameService.dll code @ 10018ea0
constexpr unsigned int ReadStoredWord = 0x10018ea0;
// R6GameService.dll code @ 10018ed0
constexpr unsigned int ReadStoredBytes = 0x10018ed0;
// R6GameService.dll code @ 10018ef0
constexpr unsigned int RemoveStoredValue = 0x10018ef0;
// R6GameService.dll code @ 10018f70
constexpr unsigned int WriteStoredValue = 0x10018f70;
// R6GameService.dll code @ 100190b0
constexpr unsigned int WriteStoredAnsiText = 0x100190b0;
// R6GameService.dll code @ 100190e0
constexpr unsigned int WriteStoredWordType3 = 0x100190e0;
// R6GameService.dll code @ 10019100
constexpr unsigned int WriteStoredWordType5 = 0x10019100;
// R6GameService.dll code @ 10019120
constexpr unsigned int CheckStoreBlobTagE = 0x10019120;
// R6GameService.dll code @ 10019150
constexpr unsigned int PrepareAlternateStoreBuffer = 0x10019150;
// R6GameService.dll code @ 10019490
constexpr unsigned int WriteStoreInteger = 0x10019490;
// R6GameService.dll code @ 10019850
constexpr unsigned int HighestSetBitIndex = 0x10019850;
// R6GameService.dll code @ 10019890
constexpr unsigned int WriteCursorByte = 0x10019890;
// R6GameService.dll code @ 10019900
constexpr unsigned int AdvanceBitCursor = 0x10019900;
// R6GameService.dll code @ 10019970
constexpr unsigned int WriteCursorBits = 0x10019970;
// R6GameService.dll code @ 100199f0
constexpr unsigned int InflateTaggedStoreBytes = 0x100199f0;
// R6GameService.dll interior-code @ 10019acc
constexpr unsigned int GStoreInflateTargetsCase1 = 0x10019acc;
// R6GameService.dll interior-code @ 10019afc
constexpr unsigned int GStoreInflateTargetsCase2 = 0x10019afc;
// R6GameService.dll interior-code @ 10019b43
constexpr unsigned int GStoreInflateTargetsCase3 = 0x10019b43;
// R6GameService.dll interior-code @ 10019b8a
constexpr unsigned int GStoreInflateTargetsCase4 = 0x10019b8a;
// R6GameService.dll interior-code @ 10019bfc
constexpr unsigned int CDataContainerGStoreInflateTargetsCase1 = 0x10019bfc;
// R6GameService.dll interior-code @ 10019c45
constexpr unsigned int CDataContainerGStoreInflateTargetsCase2 = 0x10019c45;
// R6GameService.dll interior-code @ 10019c81
constexpr unsigned int CDataContainerGStoreInflateTargetsCase3 = 0x10019c81;
// R6GameService.dll interior-code @ 10019c90
constexpr unsigned int CDataContainerBranch108 = 0x10019c90;
// R6GameService.dll data @ 10019ca0
constexpr unsigned int GStoreInflateTargets = 0x10019ca0;
// R6GameService.dll data @ 10019cb0
constexpr unsigned int CDataContainerGStoreInflateTargets = 0x10019cb0;
// R6GameService.dll code @ 10019cd0
constexpr unsigned int ReadCursorByte = 0x10019cd0;
// R6GameService.dll code @ 10019d20
constexpr unsigned int ReadStoreBitCodeValue = 0x10019d20;
// R6GameService.dll code @ 10019f10
constexpr unsigned int SerializeStoredValuesToBuffer = 0x10019f10;
// R6GameService.dll interior-code @ 1001a127
constexpr unsigned int GStoreSerializeRecordCase1 = 0x1001a127;
// R6GameService.dll interior-code @ 1001a15c
constexpr unsigned int GStoreSerializeRecordCase2 = 0x1001a15c;
// R6GameService.dll interior-code @ 1001a192
constexpr unsigned int GStoreSerializeRecordCase3 = 0x1001a192;
// R6GameService.dll interior-code @ 1001a1c7
constexpr unsigned int GStoreSerializeRecordCase4 = 0x1001a1c7;
// R6GameService.dll interior-code @ 1001a1e5
constexpr unsigned int GStoreSerializeRecordCase5 = 0x1001a1e5;
// R6GameService.dll interior-code @ 1001a20a
constexpr unsigned int GStoreSerializeRecordCase6 = 0x1001a20a;
// R6GameService.dll interior-code @ 1001a230
constexpr unsigned int GStoreSerializeRecordCase7 = 0x1001a230;
// R6GameService.dll data @ 1001aa50
constexpr unsigned int GStoreSerializeRecord = 0x1001aa50;
// R6GameService.dll code @ 1001aa70
constexpr unsigned int EncodeStoreEntry = 0x1001aa70;
// R6GameService.dll interior-code @ 1001aaa3
constexpr unsigned int GStoreEntryEncodeTargetsCase1 = 0x1001aaa3;
// R6GameService.dll interior-code @ 1001ace8
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargetsCase1 = 0x1001ace8;
// R6GameService.dll interior-code @ 1001acec
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargetsCase2 = 0x1001acec;
// R6GameService.dll interior-code @ 1001acf0
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargetsCase3 = 0x1001acf0;
// R6GameService.dll interior-code @ 1001acf4
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargetsCase4 = 0x1001acf4;
// R6GameService.dll interior-code @ 1001acf8
constexpr unsigned int store_codec_supportBranch362 = 0x1001acf8;
// R6GameService.dll interior-code @ 1001ae6b
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets2Case1 = 0x1001ae6b;
// R6GameService.dll interior-code @ 1001ae6f
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets2Case2 = 0x1001ae6f;
// R6GameService.dll interior-code @ 1001ae73
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets2Case3 = 0x1001ae73;
// R6GameService.dll interior-code @ 1001ae77
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets2Case4 = 0x1001ae77;
// R6GameService.dll interior-code @ 1001ae7b
constexpr unsigned int store_codec_supportBranch378 = 0x1001ae7b;
// R6GameService.dll interior-code @ 1001b01a
constexpr unsigned int GStoreEntryEncodeTargetsCase2 = 0x1001b01a;
// R6GameService.dll interior-code @ 1001b282
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets3Case1 = 0x1001b282;
// R6GameService.dll interior-code @ 1001b286
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets3Case2 = 0x1001b286;
// R6GameService.dll interior-code @ 1001b28a
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets3Case3 = 0x1001b28a;
// R6GameService.dll interior-code @ 1001b28e
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets3Case4 = 0x1001b28e;
// R6GameService.dll interior-code @ 1001b292
constexpr unsigned int store_codec_supportBranch418 = 0x1001b292;
// R6GameService.dll interior-code @ 1001b391
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets4Case1 = 0x1001b391;
// R6GameService.dll interior-code @ 1001b395
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets4Case2 = 0x1001b395;
// R6GameService.dll interior-code @ 1001b399
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets4Case3 = 0x1001b399;
// R6GameService.dll interior-code @ 1001b39d
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets4Case4 = 0x1001b39d;
// R6GameService.dll interior-code @ 1001b3a1
constexpr unsigned int store_codec_supportBranch429 = 0x1001b3a1;
// R6GameService.dll interior-code @ 1001b464
constexpr unsigned int GStoreEntryEncodeTargetsCase3 = 0x1001b464;
// R6GameService.dll interior-code @ 1001b484
constexpr unsigned int GStoreEntryEncodeTargetsCase6 = 0x1001b484;
// R6GameService.dll interior-code @ 1001b58d
constexpr unsigned int GStoreEntryEncodeTargetsCase4 = 0x1001b58d;
// R6GameService.dll interior-code @ 1001b688
constexpr unsigned int GStoreEntryEncodeTargetsCase5 = 0x1001b688;
// R6GameService.dll interior-code @ 1001b791
constexpr unsigned int GStoreEntryEncodeTargetsCase7 = 0x1001b791;
// R6GameService.dll data @ 1001b82c
constexpr unsigned int GStoreEntryEncodeTargets = 0x1001b82c;
// R6GameService.dll data @ 1001b848
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets = 0x1001b848;
// R6GameService.dll data @ 1001b85c
constexpr unsigned int GStoreEntryEncodeWidthMap = 0x1001b85c;
// R6GameService.dll data @ 1001b878
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets2 = 0x1001b878;
// R6GameService.dll data @ 1001b88c
constexpr unsigned int store_codec_supportGStoreEntryEncodeWidthMap = 0x1001b88c;
// R6GameService.dll data @ 1001b8a8
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets3 = 0x1001b8a8;
// R6GameService.dll data @ 1001b8bc
constexpr unsigned int store_codec_supportGStoreEntryEncodeWidthMap2 = 0x1001b8bc;
// R6GameService.dll data @ 1001b8d8
constexpr unsigned int store_codec_supportGStoreEntryEncodeTargets4 = 0x1001b8d8;
// R6GameService.dll data @ 1001b8ec
constexpr unsigned int store_codec_supportGStoreEntryEncodeWidthMap3 = 0x1001b8ec;
// R6GameService.dll code @ 1001b910
constexpr unsigned int PadStoreBitCursor = 0x1001b910;
// R6GameService.dll code @ 1001b9f0
constexpr unsigned int EmitStoreSentinelBits = 0x1001b9f0;
// R6GameService.dll code @ 1001bd20
constexpr unsigned int MeasureStoreIntegerEncoding = 0x1001bd20;
// R6GameService.dll code @ 1001bf00
constexpr unsigned int CopyBytesToStoreBitCursor = 0x1001bf00;
// R6GameService.dll code @ 1001bfc0
constexpr unsigned int SelectStoreIntegerEncoding = 0x1001bfc0;
// R6GameService.dll interior-code @ 1001c139
constexpr unsigned int GStoreEncodeSelectorTargetsCase1 = 0x1001c139;
// R6GameService.dll interior-code @ 1001c143
constexpr unsigned int GStoreEncodeSelectorTargetsCase2 = 0x1001c143;
// R6GameService.dll interior-code @ 1001c14d
constexpr unsigned int GStoreEncodeSelectorTargetsCase3 = 0x1001c14d;
// R6GameService.dll interior-code @ 1001c157
constexpr unsigned int GStoreEncodeSelectorTargetsCase4 = 0x1001c157;
// R6GameService.dll interior-code @ 1001c161
constexpr unsigned int store_codec_supportBranch341 = 0x1001c161;
// R6GameService.dll data @ 1001c178
constexpr unsigned int GStoreEncodeSelectorTargets = 0x1001c178;
// R6GameService.dll data @ 1001c18c
constexpr unsigned int GStoreEncodeWidthMap = 0x1001c18c;
// R6GameService.dll code @ 1001c1b0
constexpr unsigned int ImportSerializedStoreValues = 0x1001c1b0;
// R6GameService.dll code @ 1001c2c0
constexpr unsigned int DecodeSerializedStoreEntry = 0x1001c2c0;
// R6GameService.dll interior-code @ 1001c373
constexpr unsigned int GStoreDecodeTargetsCase1 = 0x1001c373;
// R6GameService.dll interior-code @ 1001c3d7
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase3 = 0x1001c3d7;
// R6GameService.dll interior-code @ 1001c3db
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase1 = 0x1001c3db;
// R6GameService.dll interior-code @ 1001c3e6
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase6 = 0x1001c3e6;
// R6GameService.dll interior-code @ 1001c3f1
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase4 = 0x1001c3f1;
// R6GameService.dll interior-code @ 1001c3fc
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase2 = 0x1001c3fc;
// R6GameService.dll interior-code @ 1001c407
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase5 = 0x1001c407;
// R6GameService.dll interior-code @ 1001c410
constexpr unsigned int store_codec_supportGStoreDecodeTargetsCase7 = 0x1001c410;
// R6GameService.dll interior-code @ 1001c489
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case3 = 0x1001c489;
// R6GameService.dll interior-code @ 1001c48d
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case1 = 0x1001c48d;
// R6GameService.dll interior-code @ 1001c498
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case6 = 0x1001c498;
// R6GameService.dll interior-code @ 1001c4a3
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case4 = 0x1001c4a3;
// R6GameService.dll interior-code @ 1001c4ae
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case2 = 0x1001c4ae;
// R6GameService.dll interior-code @ 1001c4b9
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case5 = 0x1001c4b9;
// R6GameService.dll interior-code @ 1001c4c2
constexpr unsigned int store_codec_supportGStoreDecodeTargets2Case7 = 0x1001c4c2;
// R6GameService.dll interior-code @ 1001c556
constexpr unsigned int GStoreDecodeTargetsCase2 = 0x1001c556;
// R6GameService.dll interior-code @ 1001c5b7
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case3 = 0x1001c5b7;
// R6GameService.dll interior-code @ 1001c5bb
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case1 = 0x1001c5bb;
// R6GameService.dll interior-code @ 1001c5c6
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case6 = 0x1001c5c6;
// R6GameService.dll interior-code @ 1001c5d1
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case4 = 0x1001c5d1;
// R6GameService.dll interior-code @ 1001c5dc
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case2 = 0x1001c5dc;
// R6GameService.dll interior-code @ 1001c5e7
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case5 = 0x1001c5e7;
// R6GameService.dll interior-code @ 1001c5f0
constexpr unsigned int store_codec_supportGStoreDecodeTargets3Case7 = 0x1001c5f0;
// R6GameService.dll interior-code @ 1001c66c
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case3 = 0x1001c66c;
// R6GameService.dll interior-code @ 1001c670
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case1 = 0x1001c670;
// R6GameService.dll interior-code @ 1001c67b
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case6 = 0x1001c67b;
// R6GameService.dll interior-code @ 1001c686
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case4 = 0x1001c686;
// R6GameService.dll interior-code @ 1001c691
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case2 = 0x1001c691;
// R6GameService.dll interior-code @ 1001c69c
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case5 = 0x1001c69c;
// R6GameService.dll interior-code @ 1001c6a5
constexpr unsigned int store_codec_supportGStoreDecodeTargets4Case7 = 0x1001c6a5;
// R6GameService.dll interior-code @ 1001c747
constexpr unsigned int GStoreDecodeTargetsCase3 = 0x1001c747;
// R6GameService.dll interior-code @ 1001c7ab
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case3 = 0x1001c7ab;
// R6GameService.dll interior-code @ 1001c7af
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case1 = 0x1001c7af;
// R6GameService.dll interior-code @ 1001c7ba
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case6 = 0x1001c7ba;
// R6GameService.dll interior-code @ 1001c7c5
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case4 = 0x1001c7c5;
// R6GameService.dll interior-code @ 1001c7d0
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case2 = 0x1001c7d0;
// R6GameService.dll interior-code @ 1001c7db
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case5 = 0x1001c7db;
// R6GameService.dll interior-code @ 1001c7e4
constexpr unsigned int store_codec_supportGStoreDecodeTargets5Case7 = 0x1001c7e4;
// R6GameService.dll interior-code @ 1001c894
constexpr unsigned int GStoreDecodeTargetsCase9 = 0x1001c894;
// R6GameService.dll interior-code @ 1001c92c
constexpr unsigned int GStoreDecodeTargetsCase6 = 0x1001c92c;
// R6GameService.dll interior-code @ 1001c98d
constexpr unsigned int GStoreDecodeTargetsCase4 = 0x1001c98d;
// R6GameService.dll interior-code @ 1001c9d5
constexpr unsigned int GStoreDecodeTargetsCase5 = 0x1001c9d5;
// R6GameService.dll interior-code @ 1001ca38
constexpr unsigned int GStoreDecodeTargetsCase7 = 0x1001ca38;
// R6GameService.dll interior-code @ 1001ca78
constexpr unsigned int GStoreDecodeTargetsCase8 = 0x1001ca78;
// R6GameService.dll interior-code @ 1001cb45
constexpr unsigned int store_codec_supportBranch196 = 0x1001cb45;
// R6GameService.dll data @ 1001cb54
constexpr unsigned int GStoreDecodeTargets = 0x1001cb54;
// R6GameService.dll data @ 1001cb7c
constexpr unsigned int GStoreDecodeTagMap = 0x1001cb7c;
// R6GameService.dll data @ 1001cb90
constexpr unsigned int store_codec_supportGStoreDecodeTargets = 0x1001cb90;
// R6GameService.dll data @ 1001cbac
constexpr unsigned int store_codec_supportGStoreDecodeTargets2 = 0x1001cbac;
// R6GameService.dll data @ 1001cbc8
constexpr unsigned int store_codec_supportGStoreDecodeTargets3 = 0x1001cbc8;
// R6GameService.dll data @ 1001cbe4
constexpr unsigned int store_codec_supportGStoreDecodeTargets4 = 0x1001cbe4;
// R6GameService.dll data @ 1001cc00
constexpr unsigned int store_codec_supportGStoreDecodeTargets5 = 0x1001cc00;
// R6GameService.dll code @ 1001cc20
constexpr unsigned int AlignStoreBitCursor = 0x1001cc20;
// R6GameService.dll code @ 1001cca0
constexpr unsigned int CopyStoreCursorBytes = 0x1001cca0;
// R6GameService.dll code @ 1001cd40
constexpr unsigned int ReadStoreCompactInteger = 0x1001cd40;
// R6GameService.dll interior-code @ 1001ce1b
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case3 = 0x1001ce1b;
// R6GameService.dll interior-code @ 1001ce22
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case1 = 0x1001ce22;
// R6GameService.dll interior-code @ 1001ce76
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case6 = 0x1001ce76;
// R6GameService.dll interior-code @ 1001ceb8
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case4 = 0x1001ceb8;
// R6GameService.dll interior-code @ 1001cef7
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case2 = 0x1001cef7;
// R6GameService.dll interior-code @ 1001cf36
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case5 = 0x1001cf36;
// R6GameService.dll interior-code @ 1001cf3f
constexpr unsigned int store_codec_supportGStoreDecodeTargets6Case7 = 0x1001cf3f;
// R6GameService.dll data @ 1001cf78
constexpr unsigned int store_codec_supportGStoreDecodeTargets6 = 0x1001cf78;
// R6GameService.dll code @ 1001cfa0
constexpr unsigned int ResetStoreBufferAt08 = 0x1001cfa0;
// R6GameService.dll code @ 1001cfd0
constexpr unsigned int ResetStoreBufferAt14 = 0x1001cfd0;
// R6GameService.dll code @ 1001d000
constexpr unsigned int ClearStoreValueTree = 0x1001d000;
// R6GameService.dll code @ 1001d0c0
constexpr unsigned int DecodeSerializedStoreHeader = 0x1001d0c0;
// R6GameService.dll interior-code @ 1001d1b3
constexpr unsigned int GStoreSelectorTargetsCase1 = 0x1001d1b3;
// R6GameService.dll interior-code @ 1001d1be
constexpr unsigned int GStoreSelectorTargetsCase2 = 0x1001d1be;
// R6GameService.dll interior-code @ 1001d1c9
constexpr unsigned int GStoreSelectorTargetsCase3 = 0x1001d1c9;
// R6GameService.dll interior-code @ 1001d1d4
constexpr unsigned int GStoreSelectorTargetsCase4 = 0x1001d1d4;
// R6GameService.dll interior-code @ 1001d257
constexpr unsigned int store_codec_supportGStoreSelectorTargetsCase1 = 0x1001d257;
// R6GameService.dll interior-code @ 1001d262
constexpr unsigned int store_codec_supportGStoreSelectorTargetsCase2 = 0x1001d262;
// R6GameService.dll interior-code @ 1001d26d
constexpr unsigned int store_codec_supportGStoreSelectorTargetsCase3 = 0x1001d26d;
// R6GameService.dll interior-code @ 1001d278
constexpr unsigned int store_codec_supportGStoreSelectorTargetsCase4 = 0x1001d278;
// R6GameService.dll data @ 1001d2dc
constexpr unsigned int GStoreSelectorTargets = 0x1001d2dc;
// R6GameService.dll data @ 1001d2ec
constexpr unsigned int store_codec_supportGStoreSelectorTargets = 0x1001d2ec;
// R6GameService.dll code @ 1001d300
constexpr unsigned int ReadStoreSelectorInteger = 0x1001d300;
// R6GameService.dll interior-code @ 1001d3b3
constexpr unsigned int store_codec_supportGStoreSelectorTargets2Case1 = 0x1001d3b3;
// R6GameService.dll interior-code @ 1001d404
constexpr unsigned int store_codec_supportGStoreSelectorTargets2Case2 = 0x1001d404;
// R6GameService.dll interior-code @ 1001d477
constexpr unsigned int store_codec_supportGStoreSelectorTargets2Case3 = 0x1001d477;
// R6GameService.dll interior-code @ 1001d4e7
constexpr unsigned int store_codec_supportGStoreSelectorTargets2Case4 = 0x1001d4e7;
// R6GameService.dll data @ 1001d550
constexpr unsigned int store_codec_supportGStoreSelectorTargets2 = 0x1001d550;
// R6GameService.dll code @ 1001d560
constexpr unsigned int OrderedTreeLowerBound = 0x1001d560;
// R6GameService.dll code @ 1001d590
constexpr unsigned int ReleaseOrderedTreeBranches = 0x1001d590;
// R6GameService.dll code @ 1001d5c0
constexpr unsigned int InsertOrFindOrderedTreeNode = 0x1001d5c0;
// R6GameService.dll code @ 1001daa0
constexpr unsigned int OrderedTreeFind = 0x1001daa0;
// R6GameService.dll code @ 1001dae0
constexpr unsigned int InflateBuffer = 0x1001dae0;
// R6GameService.dll code @ 1001db80
constexpr unsigned int DeflateBuffer = 0x1001db80;
// R6GameService.dll code @ 1001dc30
constexpr unsigned int ResetInflaterState = 0x1001dc30;
// R6GameService.dll code @ 1001dc80
constexpr unsigned int ReleaseInflaterState = 0x1001dc80;
// R6GameService.dll code @ 1001dcd0
constexpr unsigned int InflateInit2 = 0x1001dcd0;
// R6GameService.dll code @ 1001dde0
constexpr unsigned int InflateInit = 0x1001dde0;
// R6GameService.dll code @ 1001de00
constexpr unsigned int InflateStream = 0x1001de00;
// R6GameService.dll interior-code @ 1001de57
constexpr unsigned int inflate_stream_supportBranch2 = 0x1001de57;
// R6GameService.dll interior-code @ 1001dece
constexpr unsigned int inflate_stream_supportBranch5 = 0x1001dece;
// R6GameService.dll interior-code @ 1001df40
constexpr unsigned int inflate_stream_supportBranch7 = 0x1001df40;
// R6GameService.dll interior-code @ 1001dfa7
constexpr unsigned int inflate_stream_supportBranch11 = 0x1001dfa7;
// R6GameService.dll interior-code @ 1001dfdc
constexpr unsigned int inflate_stream_supportBranch12 = 0x1001dfdc;
// R6GameService.dll interior-code @ 1001e016
constexpr unsigned int inflate_stream_supportBranch13 = 0x1001e016;
// R6GameService.dll interior-code @ 1001e050
constexpr unsigned int inflate_stream_supportBranch14 = 0x1001e050;
// R6GameService.dll interior-code @ 1001e0b0
constexpr unsigned int inflate_stream_supportBranch16 = 0x1001e0b0;
// R6GameService.dll interior-code @ 1001e0ea
constexpr unsigned int inflate_stream_supportBranch19 = 0x1001e0ea;
// R6GameService.dll interior-code @ 1001e129
constexpr unsigned int inflate_stream_supportBranch21 = 0x1001e129;
// R6GameService.dll interior-code @ 1001e164
constexpr unsigned int inflate_stream_supportBranch23 = 0x1001e164;
// R6GameService.dll interior-code @ 1001e1b0
constexpr unsigned int inflate_stream_supportBranch25 = 0x1001e1b0;
// R6GameService.dll interior-code @ 1001e1df
constexpr unsigned int inflate_stream_supportBranch28 = 0x1001e1df;
// R6GameService.dll interior-code @ 1001e1eb
constexpr unsigned int inflate_stream_supportBranch29 = 0x1001e1eb;
// R6GameService.dll data @ 1001e1f8
constexpr unsigned int InflateStateTargets = 0x1001e1f8;
// R6GameService.dll code @ 1001e230
constexpr unsigned int DeflateInit = 0x1001e230;
// R6GameService.dll code @ 1001e260
constexpr unsigned int InitializeDeflateStream = 0x1001e260;
// R6GameService.dll code @ 1001e460
constexpr unsigned int ResetDeflateStream = 0x1001e460;
// R6GameService.dll code @ 1001e4e0
constexpr unsigned int DeflateStreamStep = 0x1001e4e0;
// R6GameService.dll code @ 1001e790
constexpr unsigned int WriteDeflateBigEndianWord = 0x1001e790;
// R6GameService.dll code @ 1001e7d0
constexpr unsigned int DrainDeflatePending = 0x1001e7d0;
// R6GameService.dll code @ 1001e850
constexpr unsigned int EndDeflateStream = 0x1001e850;
// R6GameService.dll code @ 1001e8f0
constexpr unsigned int ResetDeflateMatchState = 0x1001e8f0;
// R6GameService.dll code @ 1001e990
constexpr unsigned int CompressStoredDeflate = 0x1001e990;
// R6GameService.dll code @ 1001ead0
constexpr unsigned int FillDeflateWindow = 0x1001ead0;
// R6GameService.dll code @ 1001ec00
constexpr unsigned int ReadDeflateInput = 0x1001ec00;
// R6GameService.dll code @ 1001ec80
constexpr unsigned int CompressFastDeflate = 0x1001ec80;
// R6GameService.dll code @ 1001efb0
constexpr unsigned int FindLongestDeflateMatch = 0x1001efb0;
// R6GameService.dll code @ 1001f130
constexpr unsigned int CompressLazyDeflate = 0x1001f130;
// R6GameService.dll code @ 1001f560
constexpr unsigned int ResetInflaterDecodeState = 0x1001f560;
// R6GameService.dll code @ 1001f5e0
constexpr unsigned int CreateInflaterDecodeState = 0x1001f5e0;
// R6GameService.dll code @ 1001f680
constexpr unsigned int DecodeDeflateBlocks = 0x1001f680;
// R6GameService.dll interior-code @ 1001f6d4
constexpr unsigned int inflate_block_supportBranch4 = 0x1001f6d4;
// R6GameService.dll interior-code @ 1001f732
constexpr unsigned int inflate_block_supportBranch7 = 0x1001f732;
// R6GameService.dll interior-code @ 1001f750
constexpr unsigned int inflate_block_supportBranch8 = 0x1001f750;
// R6GameService.dll interior-code @ 1001f7ac
constexpr unsigned int inflate_block_supportBranch9 = 0x1001f7ac;
// R6GameService.dll interior-code @ 1001f7c1
constexpr unsigned int inflate_block_supportBranch10 = 0x1001f7c1;
// R6GameService.dll interior-code @ 1001f834
constexpr unsigned int inflate_block_supportBranch13 = 0x1001f834;
// R6GameService.dll interior-code @ 1001f960
constexpr unsigned int inflate_block_supportBranch26 = 0x1001f960;
// R6GameService.dll interior-code @ 1001f9fb
constexpr unsigned int inflate_block_supportBranch29 = 0x1001f9fb;
// R6GameService.dll interior-code @ 1001fae1
constexpr unsigned int inflate_block_supportBranch37 = 0x1001fae1;
// R6GameService.dll interior-code @ 1001fd2c
constexpr unsigned int inflate_block_supportBranch52 = 0x1001fd2c;
// R6GameService.dll interior-code @ 1001fe45
constexpr unsigned int inflate_block_supportBranch58 = 0x1001fe45;
// R6GameService.dll interior-code @ 1002016c
constexpr unsigned int inflate_block_supportBranch74 = 0x1002016c;
// R6GameService.dll interior-code @ 100201cf
constexpr unsigned int inflate_block_supportBranch78 = 0x100201cf;
// R6GameService.dll interior-code @ 10020212
constexpr unsigned int inflate_block_supportBranch80 = 0x10020212;
// R6GameService.dll data @ 1002026c
constexpr unsigned int InflateBlockTargets = 0x1002026c;
// R6GameService.dll data @ 10020294
constexpr unsigned int DeflateBlockTypeTargets = 0x10020294;
// R6GameService.dll code @ 100202b0
constexpr unsigned int DestroyInflaterDecodeState = 0x100202b0;
// R6GameService.dll code @ 100202f0
constexpr unsigned int Adler32Checksum = 0x100202f0;
// R6GameService.dll code @ 10020430
constexpr unsigned int InflateAllocator = 0x10020430;
// R6GameService.dll code @ 10020450
constexpr unsigned int InflateFree = 0x10020450;
// R6GameService.dll code @ 10020460
constexpr unsigned int ResetDeflateCodeTables = 0x10020460;
// R6GameService.dll code @ 100204d0
constexpr unsigned int ResetDeflateBlockTables = 0x100204d0;
// R6GameService.dll code @ 10020540
constexpr unsigned int WriteDeflateHeaderBits = 0x10020540;
// R6GameService.dll code @ 100205e0
constexpr unsigned int EmitDeflateFlushBits = 0x100205e0;
// R6GameService.dll code @ 10020800
constexpr unsigned int EmitDeflateBlock = 0x10020800;
// R6GameService.dll code @ 100209e0
constexpr unsigned int BuildDeflateHuffmanTree = 0x100209e0;
// R6GameService.dll code @ 10020bf0
constexpr unsigned int RestoreDeflateHeap = 0x10020bf0;
// R6GameService.dll code @ 10020cd0
constexpr unsigned int AssignDeflateCodeLengths = 0x10020cd0;
// R6GameService.dll code @ 10020ef0
constexpr unsigned int GenerateDeflateCanonicalCodes = 0x10020ef0;
// R6GameService.dll code @ 10020f70
constexpr unsigned int BuildDeflateBitLengthTree = 0x10020f70;
// R6GameService.dll code @ 10020fe0
constexpr unsigned int CountDeflateCodeLengthRuns = 0x10020fe0;
// R6GameService.dll code @ 100210d0
constexpr unsigned int WriteDeflateTreeHeader = 0x100210d0;
// R6GameService.dll code @ 10021320
constexpr unsigned int WriteDeflateCodeLengthRuns = 0x10021320;
// R6GameService.dll code @ 10021840
constexpr unsigned int WriteDeflateTokens = 0x10021840;
// R6GameService.dll code @ 10021c50
constexpr unsigned int ClassifyDeflateData = 0x10021c50;
// R6GameService.dll code @ 10021cd0
constexpr unsigned int ReverseDeflateCodeBits = 0x10021cd0;
// R6GameService.dll code @ 10021d00
constexpr unsigned int FlushWholeDeflateBytes = 0x10021d00;
// R6GameService.dll code @ 10021d90
constexpr unsigned int FlushDeflateBitBuffer = 0x10021d90;
// R6GameService.dll code @ 10021e10
constexpr unsigned int WriteDeflateStoredBlock = 0x10021e10;
// R6GameService.dll code @ 10021ea0
constexpr unsigned int AllocateHuffmanCodes = 0x10021ea0;
// R6GameService.dll code @ 10021ee0
constexpr unsigned int InflateHuffmanCodes = 0x10021ee0;
// R6GameService.dll interior-code @ 10021f33
constexpr unsigned int inflate_codes_supportBranch4 = 0x10021f33;
// R6GameService.dll interior-code @ 10021ff1
constexpr unsigned int inflate_codes_supportBranch8 = 0x10021ff1;
// R6GameService.dll interior-code @ 100220e5
constexpr unsigned int inflate_codes_supportBranch15 = 0x100220e5;
// R6GameService.dll interior-code @ 10022166
constexpr unsigned int inflate_codes_supportBranch18 = 0x10022166;
// R6GameService.dll interior-code @ 10022226
constexpr unsigned int inflate_codes_supportBranch22 = 0x10022226;
// R6GameService.dll interior-code @ 10022299
constexpr unsigned int inflate_codes_supportBranch25 = 0x10022299;
// R6GameService.dll interior-code @ 100223c2
constexpr unsigned int inflate_codes_supportBranch42 = 0x100223c2;
// R6GameService.dll interior-code @ 100224ee
constexpr unsigned int inflate_codes_supportBranch56 = 0x100224ee;
// R6GameService.dll interior-code @ 1002253d
constexpr unsigned int inflate_codes_supportBranch59 = 0x1002253d;
// R6GameService.dll interior-code @ 10022541
constexpr unsigned int inflate_codes_supportBranch60 = 0x10022541;
// R6GameService.dll data @ 10022598
constexpr unsigned int InflateCodeTargets = 0x10022598;
// R6GameService.dll code @ 100225c0
constexpr unsigned int FreeInflaterAllocation = 0x100225c0;
// R6GameService.dll code @ 100225e0
constexpr unsigned int BuildCodeLengthHuffmanTree = 0x100225e0;
// R6GameService.dll code @ 10022680
constexpr unsigned int BuildHuffmanLookupTable = 0x10022680;
// R6GameService.dll code @ 10022b30
constexpr unsigned int BuildDynamicHuffmanTrees = 0x10022b30;
// R6GameService.dll code @ 10022cb0
constexpr unsigned int GetFixedHuffmanTables = 0x10022cb0;
// R6GameService.dll code @ 10022ce0
constexpr unsigned int CommitInflaterOutput = 0x10022ce0;
// R6GameService.dll code @ 10022e10
constexpr unsigned int DecodeHuffmanFastPath = 0x10022e10;
// R6GameService.dll code @ 10023210
constexpr unsigned int CreateValidatedCDKeyContext = 0x10023210;
// R6GameService.dll code @ 10023240
constexpr unsigned int RemoveCDKeyContextOrRegistry = 0x10023240;
// R6GameService.dll code @ 10023260
constexpr unsigned int ForwardGuardedCDKeyContextOperation1 = 0x10023260;
// R6GameService.dll code @ 10023270
constexpr unsigned int ForwardGuardedCDKeyContextOperation2 = 0x10023270;
// R6GameService.dll code @ 10023280
constexpr unsigned int thunk_ForwardValueDescriptorThroughContext = 0x10023280;
// R6GameService.dll code @ 10023290
constexpr unsigned int thunk_ForwardCompoundDescriptorThroughContext = 0x10023290;
// R6GameService.dll code @ 100232a0
constexpr unsigned int ForwardGuardedCDKeyContextOperation5 = 0x100232a0;
// R6GameService.dll code @ 100232b0
constexpr unsigned int ForwardGuardedCDKeyContextOperation6 = 0x100232b0;
// R6GameService.dll code @ 100232c0
constexpr unsigned int thunk_SetContextCallbackAtC8 = 0x100232c0;
// R6GameService.dll code @ 100232d0
constexpr unsigned int thunk_SetContextCallbackAtCC = 0x100232d0;
// R6GameService.dll code @ 100232e0
constexpr unsigned int thunk_SetContextCallbackAtD0 = 0x100232e0;
// R6GameService.dll code @ 100232f0
constexpr unsigned int thunk_SetContextCallbackAtD4 = 0x100232f0;
// R6GameService.dll code @ 10023300
constexpr unsigned int AllocateAndTrackContext = 0x10023300;
// R6GameService.dll code @ 10023460
constexpr unsigned int ReleaseEmptyCDKeyRegistry = 0x10023460;
// R6GameService.dll code @ 100234a0
constexpr unsigned int DeleteCurrentCDKeyRegistry = 0x100234a0;
// R6GameService.dll code @ 100234c0
constexpr unsigned int ReadCDKeyContextStatus = 0x100234c0;
// R6GameService.dll code @ 100234e0
constexpr unsigned int InvokeOptionalCDKeyContextAL = 0x100234e0;
// R6GameService.dll code @ 10023500
constexpr unsigned int InvokeOptionalCDKeyContextWord = 0x10023500;
// R6GameService.dll code @ 10023530
constexpr unsigned int ForwardValueDescriptorThroughContext = 0x10023530;
// R6GameService.dll code @ 10023550
constexpr unsigned int ForwardCompoundDescriptorThroughContext = 0x10023550;
// R6GameService.dll code @ 10023580
constexpr unsigned int DispatchRangeDescriptorThroughContext = 0x10023580;
// R6GameService.dll code @ 100235b0
constexpr unsigned int DispatchRecordThroughContext = 0x100235b0;
// R6GameService.dll code @ 100235e0
constexpr unsigned int SetContextCallbackAtC8 = 0x100235e0;
// R6GameService.dll code @ 10023600
constexpr unsigned int SetContextCallbackAtCC = 0x10023600;
// R6GameService.dll code @ 10023620
constexpr unsigned int SetContextCallbackAtD0 = 0x10023620;
// R6GameService.dll code @ 10023640
constexpr unsigned int SetContextCallbackAtD4 = 0x10023640;
// R6GameService.dll code @ 10023660
constexpr unsigned int DeleteCCDKeyProcessPointerMap = 0x10023660;
// R6GameService.dll code @ 10023680
constexpr unsigned int DestroyCCDKeyProcessPointerMap = 0x10023680;
// R6GameService.dll code @ 10023740
constexpr unsigned int DestroyTreeContents = 0x10023740;
// R6GameService.dll code @ 100237d0
constexpr unsigned int DispatchMapFullRangeErase = 0x100237d0;
// R6GameService.dll code @ 100237f0
constexpr unsigned int EraseOwnedPointerMapNode = 0x100237f0;
// R6GameService.dll code @ 10023890
constexpr unsigned int EraseCCDKeyProcessPointerMapRange = 0x10023890;
// R6GameService.dll code @ 100239d0
constexpr unsigned int ReleaseTreeNodeBranch = 0x100239d0;
// R6GameService.dll code @ 10023a00
constexpr unsigned int ConstructCCDKeyProcess = 0x10023a00;
// R6GameService.dll code @ 10023bf0
constexpr unsigned int DestroyCCDKeyProcess = 0x10023bf0;
// R6GameService.dll code @ 10023c10
constexpr unsigned int TailForwardTreeCleanup = 0x10023c10;
// R6GameService.dll code @ 10023c20
constexpr unsigned int ordered_tree_support_TailForwardTreeCleanup = 0x10023c20;
// R6GameService.dll code @ 10023c30
constexpr unsigned int ordered_tree_support_TailForwardTreeCleanup2 = 0x10023c30;
// R6GameService.dll code @ 10023c40
constexpr unsigned int ordered_tree_support_TailForwardTreeCleanup3 = 0x10023c40;
// R6GameService.dll code @ 10023c50
constexpr unsigned int ordered_tree_support_TailForwardTreeCleanup4 = 0x10023c50;
// R6GameService.dll code @ 10023c60
constexpr unsigned int DestroyTreeWithNodePayload = 0x10023c60;
// R6GameService.dll code @ 10023cf0
constexpr unsigned int DestroyTreeNodes = 0x10023cf0;
// R6GameService.dll code @ 10023d80
constexpr unsigned int ordered_tree_support_DestroyTreeNodes = 0x10023d80;
// R6GameService.dll code @ 10023e10
constexpr unsigned int ordered_tree_support_DestroyTreeNodes2 = 0x10023e10;
// R6GameService.dll code @ 10023ea0
constexpr unsigned int ordered_tree_support_DestroyTreeWithNodePayload = 0x10023ea0;
// R6GameService.dll code @ 10023f30
constexpr unsigned int DestroyServiceObject = 0x10023f30;
// R6GameService.dll code @ 100240f0
constexpr unsigned int ProcessInputWithinTimeLimit = 0x100240f0;
// R6GameService.dll code @ 10024260
constexpr unsigned int SendDescriptorWithText = 0x10024260;
// R6GameService.dll code @ 10024430
constexpr unsigned int SendDescriptorWithValue = 0x10024430;
// R6GameService.dll code @ 100245d0
constexpr unsigned int SendCompoundDescriptor = 0x100245d0;
// R6GameService.dll code @ 100247e0
constexpr unsigned int UppercaseAndDispatchRanges = 0x100247e0;
// R6GameService.dll code @ 10024880
constexpr unsigned int CopyAndDispatchRecordFields = 0x10024880;
// R6GameService.dll code @ 10024910
constexpr unsigned int DispatchParsedInputRecord = 0x10024910;
// R6GameService.dll interior-code @ 10024a9f
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4Case1 = 0x10024a9f;
// R6GameService.dll interior-code @ 10024aba
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4Case2 = 0x10024aba;
// R6GameService.dll interior-code @ 10024ade
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4Case3 = 0x10024ade;
// R6GameService.dll interior-code @ 10024b02
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4Case4 = 0x10024b02;
// R6GameService.dll interior-code @ 10024b26
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4Case5 = 0x10024b26;
// R6GameService.dll data @ 10024c08
constexpr unsigned int CCDKeyProcessGParsedLifetimeData4 = 0x10024c08;
// R6GameService.dll code @ 10024c20
constexpr unsigned int ParseTypeOneInputRecord = 0x10024c20;
// R6GameService.dll code @ 100250e0
constexpr unsigned int ParseTypeTwoInputRecord = 0x100250e0;
// R6GameService.dll code @ 100252f0
constexpr unsigned int ParseTypeThreeInputRecord = 0x100252f0;
// R6GameService.dll code @ 100254e0
constexpr unsigned int ParseTypeFourInputRecord = 0x100254e0;
// R6GameService.dll code @ 100257e0
constexpr unsigned int ParseTypeFiveInputRecord = 0x100257e0;
// R6GameService.dll code @ 10025940
constexpr unsigned int SendTag11Descriptor = 0x10025940;
// R6GameService.dll code @ 10025ad0
constexpr unsigned int SendTag22Descriptor = 0x10025ad0;
// R6GameService.dll code @ 10025c70
constexpr unsigned int SendTag31Descriptor = 0x10025c70;
// R6GameService.dll code @ 10025e10
constexpr unsigned int StoreTimestampedDescriptorRecord = 0x10025e10;
// R6GameService.dll code @ 10025f90
constexpr unsigned int ReturnCachedAllocation = 0x10025f90;
// R6GameService.dll code @ 10026020
constexpr unsigned int ReturnEmbeddedBuffer = 0x10026020;
// R6GameService.dll code @ 100260b0
constexpr unsigned int EraseRecordsForId = 0x100260b0;
// R6GameService.dll code @ 100261c0
constexpr unsigned int ProcessExpiredInputRecords = 0x100261c0;
// R6GameService.dll interior-code @ 10026357
constexpr unsigned int GExpiryNativeDataCase1 = 0x10026357;
// R6GameService.dll interior-code @ 1002636e
constexpr unsigned int GExpiryNativeDataCase2 = 0x1002636e;
// R6GameService.dll interior-code @ 10026385
constexpr unsigned int GExpiryNativeDataCase3 = 0x10026385;
// R6GameService.dll interior-code @ 1002639c
constexpr unsigned int GExpiryNativeDataCase4 = 0x1002639c;
// R6GameService.dll data @ 100264bc
constexpr unsigned int GExpiryNativeData = 0x100264bc;
// R6GameService.dll code @ 100264d0
constexpr unsigned int SendPeriodicCollectionSnapshot = 0x100264d0;
// R6GameService.dll code @ 100266a0
constexpr unsigned int RemoveKindRecordById = 0x100266a0;
// R6GameService.dll code @ 100266f0
constexpr unsigned int InsertKindRecordById = 0x100266f0;
// R6GameService.dll code @ 10026800
constexpr unsigned int RemoveFiveWordRecordById = 0x10026800;
// R6GameService.dll code @ 10026870
constexpr unsigned int InsertFiveWordRecordById = 0x10026870;
// R6GameService.dll code @ 100269c0
constexpr unsigned int TakeOwnedValueForKey = 0x100269c0;
// R6GameService.dll code @ 10026a10
constexpr unsigned int InsertTwentyByteKey = 0x10026a10;
// R6GameService.dll code @ 10026b90
constexpr unsigned int SendMalformedRecordResponse = 0x10026b90;
// R6GameService.dll code @ 10026d80
constexpr unsigned int CCDKeyProcessFeedAndFinalize = 0x10026d80;
// R6GameService.dll code @ 10026df0
constexpr unsigned int CCDKeyProcessSetCallback1 = 0x10026df0;
// R6GameService.dll code @ 10026e00
constexpr unsigned int CCDKeyProcessSetCallback2 = 0x10026e00;
// R6GameService.dll code @ 10026e10
constexpr unsigned int CCDKeyProcessSetCallback3 = 0x10026e10;
// R6GameService.dll code @ 10026e20
constexpr unsigned int CCDKeyProcessSetCallback4 = 0x10026e20;
// R6GameService.dll code @ 10026e30
constexpr unsigned int InvokeFourWordCallback = 0x10026e30;
// R6GameService.dll code @ 10026e40
constexpr unsigned int InvokeThreeWordCallback = 0x10026e40;
// R6GameService.dll code @ 10026e50
constexpr unsigned int InvokeFiveWordCallback = 0x10026e50;
// R6GameService.dll code @ 10026e60
constexpr unsigned int InvokeTwoWordCallback = 0x10026e60;
// R6GameService.dll code @ 10026e70
constexpr unsigned int InitializeClDataFields = 0x10026e70;
// R6GameService.dll code @ 10026ea0
constexpr unsigned int DeleteClData = 0x10026ea0;
// R6GameService.dll code @ 10026ec0
constexpr unsigned int DestroyClDataPointerList = 0x10026ec0;
// R6GameService.dll code @ 10026f50
constexpr unsigned int DestroyFirstListNode = 0x10026f50;
// R6GameService.dll code @ 10026f80
constexpr unsigned int DestroyListNodeAndReturnNext = 0x10026f80;
// R6GameService.dll code @ 10026fc0
constexpr unsigned int InitializePayloadListSentinel = 0x10026fc0;
// R6GameService.dll code @ 10027000
constexpr unsigned int AssignPooledByteStringRange = 0x10027000;
// R6GameService.dll code @ 100270a0
constexpr unsigned int DeleteClDataList = 0x100270a0;
// R6GameService.dll code @ 100270c0
constexpr unsigned int DestroyClDataList = 0x100270c0;
// R6GameService.dll code @ 10027170
constexpr unsigned int ConstructClDataPointerList = 0x10027170;
// R6GameService.dll code @ 100271b0
constexpr unsigned int DestroyClDataListAlias = 0x100271b0;
// R6GameService.dll code @ 100271c0
constexpr unsigned int DeleteClDataPointerList = 0x100271c0;
// R6GameService.dll code @ 100271e0
constexpr unsigned int ClearBufferedRecordTree = 0x100271e0;
// R6GameService.dll code @ 10027240
constexpr unsigned int ClearRecordTreeVariantOne = 0x10027240;
// R6GameService.dll code @ 10027290
constexpr unsigned int ClearRecordTreeVariantTwo = 0x10027290;
// R6GameService.dll code @ 100272e0
constexpr unsigned int ClearRecordTreeVariantThree = 0x100272e0;
// R6GameService.dll code @ 10027330
constexpr unsigned int InitializeCircularListStorage = 0x10027330;
// R6GameService.dll code @ 10027370
constexpr unsigned int ClearFirstWordBufferedTree = 0x10027370;
// R6GameService.dll code @ 100273d0
constexpr unsigned int DeleteClDataListFromAdjustedBase = 0x100273d0;
// R6GameService.dll code @ 100273e0
constexpr unsigned int InitializeThirtyByteListStorage = 0x100273e0;
// R6GameService.dll code @ 10027420
constexpr unsigned int InitializeTreeSentinel = 0x10027420;
// R6GameService.dll code @ 10027460
constexpr unsigned int ReturnBlockToPoolOrAllocator = 0x10027460;
// R6GameService.dll code @ 10027490
constexpr unsigned int FindStrictUpperBoundCandidate = 0x10027490;
// R6GameService.dll code @ 100274c0
constexpr unsigned int InitializePooledBufferDescriptor = 0x100274c0;
// R6GameService.dll code @ 10027590
constexpr unsigned int ReleaseListNodesRetainHeader = 0x10027590;
// R6GameService.dll code @ 100275c0
constexpr unsigned int ReleaseTreeNodes = 0x100275c0;
// R6GameService.dll code @ 10027600
constexpr unsigned int FindOrInsertUnsignedKeyTreeEntry = 0x10027600;
// R6GameService.dll code @ 10027770
constexpr unsigned int ReleasePlainTreeNodes = 0x10027770;
// R6GameService.dll code @ 100277a0
constexpr unsigned int ordered_tree_support_ReleasePlainTreeNodes = 0x100277a0;
// R6GameService.dll code @ 100277d0
constexpr unsigned int ordered_tree_support_ReleasePlainTreeNodes2 = 0x100277d0;
// R6GameService.dll code @ 10027800
constexpr unsigned int ReleaseFirstWordPayloadTreeNodes = 0x10027800;
// R6GameService.dll code @ 10027840
constexpr unsigned int FindOrInsertByteDescriptorTreeEntry = 0x10027840;
// R6GameService.dll code @ 10027a00
constexpr unsigned int ConstructTimestampedDescriptorPair = 0x10027a00;
// R6GameService.dll code @ 10027b60
constexpr unsigned int ForwardPooledStringTag = 0x10027b60;
// R6GameService.dll code @ 10027b70
constexpr unsigned int AllocateByteStringStorage = 0x10027b70;
// R6GameService.dll code @ 10027b90
constexpr unsigned int ReturnSmallByteStringBlock = 0x10027b90;
// R6GameService.dll code @ 10027cc0
constexpr unsigned int DeleteEmbeddedBufferDescriptor = 0x10027cc0;
// R6GameService.dll code @ 10027ce0
constexpr unsigned int AcquireBufferPoolLockWithBackoff = 0x10027ce0;
// R6GameService.dll code @ 10027df0
constexpr unsigned int ConstructPooledByteStringFromTriplet = 0x10027df0;
// R6GameService.dll code @ 10027f10
constexpr unsigned int InsertUnsignedKeyTreeNodeAtHint = 0x10027f10;
// R6GameService.dll code @ 100280e0
constexpr unsigned int InsertTwentyByteKeyTreeNodeAtHint = 0x100280e0;
// R6GameService.dll code @ 100282e0
constexpr unsigned int FindTwentyByteKeyNode = 0x100282e0;
// R6GameService.dll code @ 10028350
constexpr unsigned int ByteDescriptorLess = 0x10028350;
// R6GameService.dll code @ 100283c0
constexpr unsigned int ReleaseHeapByteStringAndMaybeOwner = 0x100283c0;
// R6GameService.dll code @ 100283e0
constexpr unsigned int CompareByteRanges = 0x100283e0;
// R6GameService.dll code @ 10028440
constexpr unsigned int AllocateTimestampedDescriptorTreeNode = 0x10028440;
// R6GameService.dll code @ 10028505
constexpr unsigned int RethrowTimestampedNodeConstruction = 0x10028505;
// R6GameService.dll code @ 10028520
constexpr unsigned int AllocateKeyedPairNode = 0x10028520;
// R6GameService.dll code @ 10028550
constexpr unsigned int CreateByteDescriptorTreeNode = 0x10028550;
// R6GameService.dll code @ 100285e3
constexpr unsigned int RethrowByteDescriptorNodeConstruction = 0x100285e3;
// R6GameService.dll code @ 10028600
constexpr unsigned int MoveByteRange = 0x10028600;
// R6GameService.dll code @ 10028630
constexpr unsigned int AppendByteRangeToHeapString = 0x10028630;
// R6GameService.dll code @ 10028760
constexpr unsigned int ReleaseByteAllocation = 0x10028760;
// R6GameService.dll code @ 10028790
constexpr unsigned int ConstructByteStringRange = 0x10028790;
// R6GameService.dll code @ 10028810
constexpr unsigned int SelectContextHighByteIntoAL = 0x10028810;
// R6GameService.dll code @ 10028820
constexpr unsigned int StoreArgumentLowByteAtAddress = 0x10028820;
// R6GameService.dll code @ 10028830
constexpr unsigned int ConstructCMessageBuffer = 0x10028830;
// R6GameService.dll code @ 10028960
constexpr unsigned int DeleteCMessageBuffer = 0x10028960;
// R6GameService.dll code @ 10028980
constexpr unsigned int DestroyCMessageBufferFields = 0x10028980;
// R6GameService.dll code @ 10028a20
constexpr unsigned int FlushPendingDatagrams = 0x10028a20;
// R6GameService.dll code @ 10028ac0
constexpr unsigned int ReceiveAndDecodeTaggedPayload = 0x10028ac0;
// R6GameService.dll code @ 10028c80
constexpr unsigned int QueueSerializedDatagram = 0x10028c80;
// R6GameService.dll code @ 10028de0
constexpr unsigned int ClearMessageBufferQueues = 0x10028de0;
// R6GameService.dll code @ 10028df0
constexpr unsigned int ClearMessageBufferFirstQueue = 0x10028df0;
// R6GameService.dll code @ 10028e50
constexpr unsigned int ClearMessageBufferSendQueue = 0x10028e50;
// R6GameService.dll code @ 10028eb0
constexpr unsigned int DeleteClCDKeyMessage = 0x10028eb0;
// R6GameService.dll code @ 10028ed0
constexpr unsigned int DestroyClCDKeyMessage = 0x10028ed0;
// R6GameService.dll code @ 10028ee0
constexpr unsigned int DestroyClCDKeyMessageAlias = 0x10028ee0;
// R6GameService.dll code @ 10028ef0
constexpr unsigned int CopyConstructClDataList = 0x10028ef0;
// R6GameService.dll interior-code @ 10028fa0
constexpr unsigned int clDataListBranch10 = 0x10028fa0;
// R6GameService.dll interior-code @ 10029027
constexpr unsigned int clDataListBranch13 = 0x10029027;
// R6GameService.dll interior-code @ 100290b0
constexpr unsigned int clDataListBranch14 = 0x100290b0;
// R6GameService.dll interior-code @ 100290e7
constexpr unsigned int clDataListBranch16 = 0x100290e7;
// R6GameService.dll interior-code @ 10029149
constexpr unsigned int clDataListBranch17 = 0x10029149;
// R6GameService.dll interior-code @ 100291ab
constexpr unsigned int clDataListBranch19 = 0x100291ab;
// R6GameService.dll data @ 10029234
constexpr unsigned int GClDataListCloneTagTargets = 0x10029234;
// R6GameService.dll code @ 10029250
constexpr unsigned int AssignClDataList = 0x10029250;
// R6GameService.dll interior-code @ 100292b8
constexpr unsigned int clDataListBranch32 = 0x100292b8;
// R6GameService.dll interior-code @ 1002933e
constexpr unsigned int clDataListBranch35 = 0x1002933e;
// R6GameService.dll interior-code @ 100293ca
constexpr unsigned int clDataListBranch36 = 0x100293ca;
// R6GameService.dll interior-code @ 1002940a
constexpr unsigned int clDataListBranch38 = 0x1002940a;
// R6GameService.dll interior-code @ 1002946a
constexpr unsigned int clDataListBranch39 = 0x1002946a;
// R6GameService.dll interior-code @ 100294c9
constexpr unsigned int clDataListBranch41 = 0x100294c9;
// R6GameService.dll data @ 1002955c
constexpr unsigned int GClDataListAssignmentTagTargets = 0x1002955c;
// R6GameService.dll code @ 10029580
constexpr unsigned int AppendIndentedClDataList = 0x10029580;
// R6GameService.dll code @ 100296d0
constexpr unsigned int AppendFilteredIndentedClDataList = 0x100296d0;
// R6GameService.dll code @ 10029820
constexpr unsigned int AppendClDataListToByteString = 0x10029820;
// R6GameService.dll code @ 100298f0
constexpr unsigned int PrintClDataList = 0x100298f0;
// R6GameService.dll code @ 10029930
constexpr unsigned int SumClDataListPayloadResults = 0x10029930;
// R6GameService.dll code @ 10029960
constexpr unsigned int CountClDataListEntries = 0x10029960;
// R6GameService.dll code @ 10029980
constexpr unsigned int AppendClDataListString = 0x10029980;
// R6GameService.dll code @ 10029a80
constexpr unsigned int AppendClDataListBinary = 0x10029a80;
// R6GameService.dll code @ 10029b60
constexpr unsigned int AppendClDataListBinaryCopy = 0x10029b60;
// R6GameService.dll code @ 10029c40
constexpr unsigned int AppendClDataListCopy = 0x10029c40;
// R6GameService.dll code @ 10029d20
constexpr unsigned int AppendClDataListPointer = 0x10029d20;
// R6GameService.dll code @ 10029d60
constexpr unsigned int AppendClDataListSignedDecimal = 0x10029d60;
// R6GameService.dll code @ 10029da0
constexpr unsigned int CopyIndexedTypeOneBytes = 0x10029da0;
// R6GameService.dll code @ 10029e90
constexpr unsigned int CopyIndexedClDataBin = 0x10029e90;
// R6GameService.dll code @ 10029f00
constexpr unsigned int GetIndexedClDataBin = 0x10029f00;
// R6GameService.dll code @ 10029fa0
constexpr unsigned int CopyIndexedClDataList = 0x10029fa0;
// R6GameService.dll code @ 1002a000
constexpr unsigned int GetIndexedClDataList = 0x1002a000;
// R6GameService.dll code @ 1002a0a0
constexpr unsigned int CopyIndexedClDataString = 0x1002a0a0;
// R6GameService.dll code @ 1002a190
constexpr unsigned int CopyIndexedStringBounded = 0x1002a190;
// R6GameService.dll code @ 1002a290
constexpr unsigned int ReadIndexedInt32 = 0x1002a290;
// R6GameService.dll code @ 1002a380
constexpr unsigned int ReadIndexedWord = 0x1002a380;
// R6GameService.dll code @ 1002a480
constexpr unsigned int ReadIndexedByte = 0x1002a480;
// R6GameService.dll code @ 1002a570
constexpr unsigned int CopyIndexedBytesExact = 0x1002a570;
// R6GameService.dll code @ 1002a670
constexpr unsigned int GetIndexedPayload = 0x1002a670;
// R6GameService.dll code @ 1002a6c0
constexpr unsigned int GetIndexedTypeOnePayload = 0x1002a6c0;
// R6GameService.dll code @ 1002a700
constexpr unsigned int SerializeClDataListToBuffer = 0x1002a700;
// R6GameService.dll code @ 1002a870
constexpr unsigned int ResetClDataSerializeVtableAlias = 0x1002a870;
// R6GameService.dll code @ 1002a880
constexpr unsigned int ParseClDataListBytes = 0x1002a880;
// R6GameService.dll code @ 1002a980
constexpr unsigned int InitializeEmptyByteBufferTriplet = 0x1002a980;
// R6GameService.dll code @ 1002a9b0
constexpr unsigned int ConstructByteTripletBuffer = 0x1002a9b0;
// R6GameService.dll code @ 1002aad0
constexpr unsigned int InsertPayloadNodeBefore = 0x1002aad0;
// R6GameService.dll code @ 1002ab00
constexpr unsigned int InitializeEmptyByteBufferTripletWithContext = 0x1002ab00;
// R6GameService.dll code @ 1002ab30
constexpr unsigned int DeleteClDataBin = 0x1002ab30;
// R6GameService.dll code @ 1002ab50
constexpr unsigned int DestroyClDataBin = 0x1002ab50;
// R6GameService.dll code @ 1002ab70
constexpr unsigned int DestroyClDataBinAlias = 0x1002ab70;
// R6GameService.dll code @ 1002ab80
constexpr unsigned int PrintQuotedDescriptorString = 0x1002ab80;
// R6GameService.dll code @ 1002aba0
constexpr unsigned int AppendClDataStrQuotedText = 0x1002aba0;
// R6GameService.dll code @ 1002ac40
constexpr unsigned int GetDescriptorByteCount = 0x1002ac40;
// R6GameService.dll code @ 1002ac50
constexpr unsigned int DeleteClDataStr = 0x1002ac50;
// R6GameService.dll code @ 1002ac70
constexpr unsigned int DestroyClDataStr = 0x1002ac70;
// R6GameService.dll code @ 1002ac90
constexpr unsigned int DestroyClDataStrAlias = 0x1002ac90;
// R6GameService.dll code @ 1002aca0
constexpr unsigned int InitializeEmptyByteString = 0x1002aca0;
// R6GameService.dll code @ 1002acd0
constexpr unsigned int ReserveByteString = 0x1002acd0;
// R6GameService.dll code @ 1002adb0
constexpr unsigned int AppendClDataStrRefQuotedText = 0x1002adb0;
// R6GameService.dll code @ 1002ae70
constexpr unsigned int GetClDataStrRefTextLength = 0x1002ae70;
// R6GameService.dll code @ 1002ae90
constexpr unsigned int ResetClDataVtable = 0x1002ae90;
// R6GameService.dll code @ 1002aea0
constexpr unsigned int ForwardToDescriptorSlot04 = 0x1002aea0;
// R6GameService.dll code @ 1002aeb0
constexpr unsigned int PrintClDataLong = 0x1002aeb0;
// R6GameService.dll code @ 1002aed0
constexpr unsigned int AppendClDataLongText = 0x1002aed0;
// R6GameService.dll code @ 1002af90
constexpr unsigned int GetClDataLongByteSize = 0x1002af90;
// R6GameService.dll code @ 1002afa0
constexpr unsigned int ForwardDataPayloadVirtual = 0x1002afa0;
// R6GameService.dll code @ 1002afb0
constexpr unsigned int data_virtual_support_ForwardDataPayloadVirtual = 0x1002afb0;
// R6GameService.dll code @ 1002afc0
constexpr unsigned int data_virtual_support_ForwardDataPayloadVirtual2 = 0x1002afc0;
// R6GameService.dll code @ 1002afd0
constexpr unsigned int data_virtual_support_ForwardDataPayloadVirtual3 = 0x1002afd0;
// R6GameService.dll code @ 1002afe0
constexpr unsigned int data_virtual_support_ForwardDataPayloadVirtual4 = 0x1002afe0;
// R6GameService.dll code @ 1002aff0
constexpr unsigned int DeleteTrivialScalarDescriptor = 0x1002aff0;
// R6GameService.dll code @ 1002b010
constexpr unsigned int InsertByteRangeWithLocalTag = 0x1002b010;
// R6GameService.dll code @ 1002b040
constexpr unsigned int AppendByteRangeWithLocalGrowthTag = 0x1002b040;
// R6GameService.dll code @ 1002b070
constexpr unsigned int AppendByteRangeWithLocalTag = 0x1002b070;
// R6GameService.dll code @ 1002b0a0
constexpr unsigned int ConstructHeapByteStringRange = 0x1002b0a0;
// R6GameService.dll code @ 1002b100
constexpr unsigned int InsertByteRange = 0x1002b100;
// R6GameService.dll code @ 1002b260
constexpr unsigned int FillByteRangeAndReturnEnd = 0x1002b260;
// R6GameService.dll code @ 1002b280
constexpr unsigned int AppendByteRangePreservingNul = 0x1002b280;
// R6GameService.dll code @ 1002b370
constexpr unsigned int AppendClDataStrIndentedText = 0x1002b370;
// R6GameService.dll code @ 1002b4a0
constexpr unsigned int AppendDescriptorCString = 0x1002b4a0;
// R6GameService.dll code @ 1002b4e0
constexpr unsigned int AppendClDataStrRefIndentedText = 0x1002b4e0;
// R6GameService.dll code @ 1002b630
constexpr unsigned int AssignClDataBinByteRange = 0x1002b630;
// R6GameService.dll code @ 1002b6e0
constexpr unsigned int NoOp = 0x1002b6e0;
// R6GameService.dll code @ 1002b6f0
constexpr unsigned int AppendClDataBinText = 0x1002b6f0;
// R6GameService.dll code @ 1002b9b0
constexpr unsigned int PrintClDataBin = 0x1002b9b0;
// R6GameService.dll code @ 1002ba80
constexpr unsigned int ReplaceClDataBinBytes = 0x1002ba80;
// R6GameService.dll code @ 1002bb70
constexpr unsigned int CopyClDataBinBytesToBuffer = 0x1002bb70;
// R6GameService.dll code @ 1002bbc0
constexpr unsigned int AllocateAndCopyByteRange = 0x1002bbc0;
// R6GameService.dll code @ 1002bbf0
constexpr unsigned int CopyByteRange = 0x1002bbf0;
// R6GameService.dll code @ 1002bc20
constexpr unsigned int AppendClDataLongIndentedText = 0x1002bc20;
// R6GameService.dll code @ 1002bd90
constexpr unsigned int SetClDataLongEncodedValue = 0x1002bd90;
// R6GameService.dll code @ 1002bdb0
constexpr unsigned int ConstructClDataSerialize = 0x1002bdb0;
// R6GameService.dll code @ 1002bde0
constexpr unsigned int DeleteClDataSerialize = 0x1002bde0;
// R6GameService.dll code @ 1002be00
constexpr unsigned int ResetClDataSerializeVtable = 0x1002be00;
// R6GameService.dll code @ 1002be10
constexpr unsigned int ParseTaggedValues = 0x1002be10;
// R6GameService.dll interior-code @ 1002be5e
constexpr unsigned int clDataSerializeBranch2 = 0x1002be5e;
// R6GameService.dll interior-code @ 1002be6e
constexpr unsigned int clDataSerializeBranch3 = 0x1002be6e;
// R6GameService.dll interior-code @ 1002be7e
constexpr unsigned int clDataSerializeBranch4 = 0x1002be7e;
// R6GameService.dll interior-code @ 1002be8e
constexpr unsigned int clDataSerializeBranch5 = 0x1002be8e;
// R6GameService.dll interior-code @ 1002beab
constexpr unsigned int clDataSerializeBranch7 = 0x1002beab;
// R6GameService.dll data @ 1002bebc
constexpr unsigned int GTaggedParseTargets = 0x1002bebc;
// R6GameService.dll data @ 1002bed0
constexpr unsigned int GTaggedParseTagRemap = 0x1002bed0;
// R6GameService.dll code @ 1002bf00
constexpr unsigned int ParseListValue = 0x1002bf00;
// R6GameService.dll interior-code @ 1002bfd6
constexpr unsigned int clDataSerializeBranch13 = 0x1002bfd6;
// R6GameService.dll interior-code @ 1002bfe6
constexpr unsigned int clDataSerializeBranch14 = 0x1002bfe6;
// R6GameService.dll interior-code @ 1002bff6
constexpr unsigned int clDataSerializeBranch15 = 0x1002bff6;
// R6GameService.dll interior-code @ 1002c006
constexpr unsigned int clDataSerializeBranch16 = 0x1002c006;
// R6GameService.dll interior-code @ 1002c01f
constexpr unsigned int clDataSerializeBranch18 = 0x1002c01f;
// R6GameService.dll interior-code @ 1002c021
constexpr unsigned int clDataSerializeBranch19 = 0x1002c021;
// R6GameService.dll data @ 1002c074
constexpr unsigned int GNestedParseTargets = 0x1002c074;
// R6GameService.dll data @ 1002c08c
constexpr unsigned int GNestedParseTagRemap = 0x1002c08c;
// R6GameService.dll code @ 1002c0c0
constexpr unsigned int ParseStringValue = 0x1002c0c0;
// R6GameService.dll code @ 1002c260
constexpr unsigned int ParseWordValue = 0x1002c260;
// R6GameService.dll code @ 1002c310
constexpr unsigned int ParseByteBlockValue = 0x1002c310;
// R6GameService.dll code @ 1002c470
constexpr unsigned int WriteTaggedEntries = 0x1002c470;
// R6GameService.dll code @ 1002c4b0
constexpr unsigned int WriteTaggedEntryList = 0x1002c4b0;
// R6GameService.dll interior-code @ 1002c4e9
constexpr unsigned int clDataSerializeBranch23 = 0x1002c4e9;
// R6GameService.dll interior-code @ 1002c55a
constexpr unsigned int clDataSerializeBranch29 = 0x1002c55a;
// R6GameService.dll interior-code @ 1002c567
constexpr unsigned int clDataSerializeBranch30 = 0x1002c567;
// R6GameService.dll interior-code @ 1002c574
constexpr unsigned int clDataSerializeBranch31 = 0x1002c574;
// R6GameService.dll interior-code @ 1002c581
constexpr unsigned int clDataSerializeBranch32 = 0x1002c581;
// R6GameService.dll interior-code @ 1002c58e
constexpr unsigned int clDataSerializeBranch33 = 0x1002c58e;
// R6GameService.dll data @ 1002c5c8
constexpr unsigned int GTaggedWriteTargets = 0x1002c5c8;
// R6GameService.dll code @ 1002c5e0
constexpr unsigned int WriteTaggedType1 = 0x1002c5e0;
// R6GameService.dll code @ 1002c6d0
constexpr unsigned int WriteTaggedType5 = 0x1002c6d0;
// R6GameService.dll code @ 1002c820
constexpr unsigned int WriteTaggedType4 = 0x1002c820;
// R6GameService.dll code @ 1002c950
constexpr unsigned int WriteTaggedType2 = 0x1002c950;
// R6GameService.dll code @ 1002cac0
constexpr unsigned int WriteTaggedValueByType = 0x1002cac0;
// R6GameService.dll interior-code @ 1002cae3
constexpr unsigned int GTaggedValueTargetsCase3 = 0x1002cae3;
// R6GameService.dll interior-code @ 1002cc16
constexpr unsigned int GTaggedValueTargetsCase1 = 0x1002cc16;
// R6GameService.dll interior-code @ 1002cc2b
constexpr unsigned int GTaggedValueTargetsCase5 = 0x1002cc2b;
// R6GameService.dll interior-code @ 1002cc40
constexpr unsigned int GTaggedValueTargetsCase4 = 0x1002cc40;
// R6GameService.dll interior-code @ 1002cc55
constexpr unsigned int GTaggedValueTargetsCase2 = 0x1002cc55;
// R6GameService.dll interior-code @ 1002cc6a
constexpr unsigned int GTaggedValueTargetsCase6 = 0x1002cc6a;
// R6GameService.dll data @ 1002cc90
constexpr unsigned int GTaggedValueTargets = 0x1002cc90;
// R6GameService.dll code @ 1002ccb0
constexpr unsigned int GrowByteBufferAndInsertRepeatedBytes = 0x1002ccb0;
// R6GameService.dll code @ 1002cd60
constexpr unsigned int InitializePointerTriplet = 0x1002cd60;
// R6GameService.dll code @ 1002cd70
constexpr unsigned int SetThreeWordRecord = 0x1002cd70;
// R6GameService.dll code @ 1002cd90
constexpr unsigned int RefreshPerformanceCounterBaseline = 0x1002cd90;
// R6GameService.dll code @ 1002cdc0
constexpr unsigned int GetElapsedMilliseconds = 0x1002cdc0;
// R6GameService.dll code @ 1002ce30
constexpr unsigned int InitializeTaggedPayload = 0x1002ce30;
// R6GameService.dll code @ 1002cf40
constexpr unsigned int DeleteTaggedPayload = 0x1002cf40;
// R6GameService.dll code @ 1002cf60
constexpr unsigned int ParseTaggedPayload = 0x1002cf60;
// R6GameService.dll code @ 1002cff0
constexpr unsigned int DestroyTaggedPayloadFields = 0x1002cff0;
// R6GameService.dll code @ 1002d010
constexpr unsigned int SerializeTaggedPayload = 0x1002d010;
// R6GameService.dll code @ 1002d0a0
constexpr unsigned int DecodeTaggedPayloadToList = 0x1002d0a0;
// R6GameService.dll code @ 1002d140
constexpr unsigned int GetDefaultTaggedPayloadCodec = 0x1002d140;
// R6GameService.dll code @ 1002d1a0
constexpr unsigned int DestroyDefaultTaggedPayloadCodec = 0x1002d1a0;
// R6GameService.dll code @ 1002d1b0
constexpr unsigned int InitializeCodecBackedPayload = 0x1002d1b0;
// R6GameService.dll code @ 1002d200
constexpr unsigned int InitializeSerializedPayload = 0x1002d200;
// R6GameService.dll code @ 1002d250
constexpr unsigned int ForwardStartupInitializer = 0x1002d250;
// R6GameService.dll code @ 1002d260
constexpr unsigned int InitializeInterfaceAddressPrefixes = 0x1002d260;
// R6GameService.dll code @ 1002d4e0
constexpr unsigned int InitializeIPv4Prefix = 0x1002d4e0;
// R6GameService.dll code @ 1002d500
constexpr unsigned int ResolveAddressText = 0x1002d500;
// R6GameService.dll code @ 1002d5a0
constexpr unsigned int ParseIPv4AddressOrZero = 0x1002d5a0;
// R6GameService.dll code @ 1002d5c0
constexpr unsigned int MatchesAddressPrefix = 0x1002d5c0;
// R6GameService.dll code @ 1002d600
constexpr unsigned int FindIPv4Interface = 0x1002d600;
// R6GameService.dll code @ 1002d820
constexpr unsigned int SelectIPv4FamilyByte = 0x1002d820;
// R6GameService.dll code @ 1002d840
constexpr unsigned int AllocateResolvedIPv4Record = 0x1002d840;
// R6GameService.dll code @ 1002d900
constexpr unsigned int BuildIPv4AddressRecord = 0x1002d900;
// R6GameService.dll code @ 1002d940
constexpr unsigned int InitializeSocketContext = 0x1002d940;
// R6GameService.dll code @ 1002d970
constexpr unsigned int ResolveIPv4Address = 0x1002d970;
// R6GameService.dll code @ 1002d9f0
constexpr unsigned int CreateIPv4StreamSocket = 0x1002d9f0;
// R6GameService.dll code @ 1002da30
constexpr unsigned int CreateIPv4DatagramSocket = 0x1002da30;
// R6GameService.dll code @ 1002da70
constexpr unsigned int BindIPv4Socket = 0x1002da70;
// R6GameService.dll code @ 1002dad0
constexpr unsigned int ConnectResolvedIPv4 = 0x1002dad0;
// R6GameService.dll code @ 1002dc30
constexpr unsigned int ConnectIPv4 = 0x1002dc30;
// R6GameService.dll code @ 1002dd40
constexpr unsigned int SendSocketBytes = 0x1002dd40;
// R6GameService.dll code @ 1002dd80
constexpr unsigned int SendSocketBytesToResolvedIPv4 = 0x1002dd80;
// R6GameService.dll code @ 1002de20
constexpr unsigned int SendSocketBytesToIPv4 = 0x1002de20;
// R6GameService.dll code @ 1002dea0
constexpr unsigned int ReceiveSocketBytes = 0x1002dea0;
// R6GameService.dll code @ 1002def0
constexpr unsigned int ReceiveDatagramWithTextSender = 0x1002def0;
// R6GameService.dll code @ 1002e070
constexpr unsigned int ReceiveDatagramWithIPv4Sender = 0x1002e070;
// R6GameService.dll code @ 1002e1d0
constexpr unsigned int ReceiveFromSocket = 0x1002e1d0;
// R6GameService.dll code @ 1002e260
constexpr unsigned int GetSocketLocalIPv4Endpoint = 0x1002e260;
// R6GameService.dll code @ 1002e2d0
constexpr unsigned int GetSocketPeerIPv4Endpoint = 0x1002e2d0;
// R6GameService.dll code @ 1002e350
constexpr unsigned int CloseSocketAndReset = 0x1002e350;
// R6GameService.dll code @ 1002e380
constexpr unsigned int SetSocketNonblocking = 0x1002e380;
// R6GameService.dll code @ 1002e3c0
constexpr unsigned int SetTcpNoDelay = 0x1002e3c0;
// R6GameService.dll code @ 1002e410
constexpr unsigned int SetSocketReuseAddress = 0x1002e410;
// R6GameService.dll code @ 1002e460
constexpr unsigned int SetSocketBroadcast = 0x1002e460;
// R6GameService.dll code @ 1002e4b0
constexpr unsigned int SetSocketSendBufferSize = 0x1002e4b0;
// R6GameService.dll code @ 1002e4f0
constexpr unsigned int SetSocketReceiveBufferSize = 0x1002e4f0;
// R6GameService.dll code @ 1002e530
constexpr unsigned int GetSocketLastError = 0x1002e530;
// R6GameService.dll code @ 1002e540
constexpr unsigned int ConstructQueuedConnection = 0x1002e540;
// R6GameService.dll code @ 1002e5f0
constexpr unsigned int DeleteQueuedConnection = 0x1002e5f0;
// R6GameService.dll code @ 1002e610
constexpr unsigned int ForwardToCircularListDestructor = 0x1002e610;
// R6GameService.dll code @ 1002e620
constexpr unsigned int DestroyQueuedConnectionMembers = 0x1002e620;
// R6GameService.dll code @ 1002e690
constexpr unsigned int ForwardToNoOp = 0x1002e690;
// R6GameService.dll code @ 1002e6a0
constexpr unsigned int SetReceiveIdleLimit = 0x1002e6a0;
// R6GameService.dll code @ 1002e6b0
constexpr unsigned int PumpConnectionReceiveQueue = 0x1002e6b0;
// R6GameService.dll code @ 1002e760
constexpr unsigned int FlushConnectionSendQueue = 0x1002e760;
// R6GameService.dll code @ 1002e7d0
constexpr unsigned int SendOrQueueConnectionBytes = 0x1002e7d0;
// R6GameService.dll code @ 1002e890
constexpr unsigned int SendConnectionBytes = 0x1002e890;
// R6GameService.dll code @ 1002e8d0
constexpr unsigned int ReceiveConnectionBytes = 0x1002e8d0;
// R6GameService.dll code @ 1002e910
constexpr unsigned int CloseConnectionAndClearSendQueue = 0x1002e910;
// R6GameService.dll code @ 1002e950
constexpr unsigned int QueryPeerEndpointAlwaysSuccess = 0x1002e950;
// R6GameService.dll code @ 1002e970
constexpr unsigned int QueryLocalEndpointAlwaysSuccess = 0x1002e970;
// R6GameService.dll code @ 1002e990
constexpr unsigned int ConnectResolvedQueuedConnection = 0x1002e990;
// R6GameService.dll code @ 1002ea30
constexpr unsigned int ConnectNumericQueuedConnection = 0x1002ea30;
// R6GameService.dll code @ 1002eb30
constexpr unsigned int ConstructDatagramSocketOwner = 0x1002eb30;
// R6GameService.dll code @ 1002eba0
constexpr unsigned int DestroyDatagramSocketOwner = 0x1002eba0;
// R6GameService.dll code @ 1002ebf0
constexpr unsigned int OpenDatagramSocket = 0x1002ebf0;
// R6GameService.dll code @ 1002ec90
constexpr unsigned int CloseDatagramSocket = 0x1002ec90;
// R6GameService.dll code @ 1002eca0
constexpr unsigned int SendDatagramToResolvedIPv4 = 0x1002eca0;
// R6GameService.dll code @ 1002ecd0
constexpr unsigned int SendDatagramToIPv4 = 0x1002ecd0;
// R6GameService.dll code @ 1002ed00
constexpr unsigned int datagram_socket_support_ReceiveDatagramWithTextSender = 0x1002ed00;
// R6GameService.dll code @ 1002eda0
constexpr unsigned int datagram_socket_support_ReceiveDatagramWithIPv4Sender = 0x1002eda0;
// R6GameService.dll code @ 1002ee40
constexpr unsigned int ConstructCircularList = 0x1002ee40;
// R6GameService.dll code @ 1002ee90
constexpr unsigned int DestroyCircularList = 0x1002ee90;
// R6GameService.dll code @ 1002ef20
constexpr unsigned int DeleteCircularList = 0x1002ef20;
// R6GameService.dll code @ 1002ef40
constexpr unsigned int AppendBytesToBlockQueue = 0x1002ef40;
// R6GameService.dll code @ 1002f040
constexpr unsigned int ConsumeBlockQueueBytes = 0x1002f040;
// R6GameService.dll code @ 1002f120
constexpr unsigned int CopyBlockQueuePrefix = 0x1002f120;
// R6GameService.dll code @ 1002f190
constexpr unsigned int ClearBlockQueue = 0x1002f190;
// R6GameService.dll code @ 1002f1b0
constexpr unsigned int RemoveFirstBlockFromQueue = 0x1002f1b0;
// R6GameService.dll code @ 1002f1e0
constexpr unsigned int RemoveLastBlockFromQueue = 0x1002f1e0;
// R6GameService.dll code @ 1002f220
constexpr unsigned int InitializeRegistrationServiceSingleton = 0x1002f220;
// R6GameService.dll code @ 1002f260
constexpr unsigned int UninitializeRegistrationService = 0x1002f260;
// R6GameService.dll code @ 1002f280
constexpr unsigned int ProcessRegistrationServiceCallbacks = 0x1002f280;
// R6GameService.dll code @ 1002f290
constexpr unsigned int ConnectRegistrationEndpoint = 0x1002f290;
// R6GameService.dll code @ 1002f2b0
constexpr unsigned int SendRouterDisconnect = 0x1002f2b0;
// R6GameService.dll code @ 1002f2c0
constexpr unsigned int SendRouterLogin = 0x1002f2c0;
// R6GameService.dll code @ 1002f2d0
constexpr unsigned int RequestParentGroupOnLobby = 0x1002f2d0;
// R6GameService.dll code @ 1002f2e0
constexpr unsigned int RegisterServerOnLobby = 0x1002f2e0;
// R6GameService.dll code @ 1002f310
constexpr unsigned int SendMatchStart = 0x1002f310;
// R6GameService.dll code @ 1002f320
constexpr unsigned int SendMatchFinish = 0x1002f320;
// R6GameService.dll code @ 1002f330
constexpr unsigned int SetRegistrationCallback = 0x1002f330;
// R6GameService.dll code @ 1002f340
constexpr unsigned int registration_service_SetRegistrationCallback = 0x1002f340;
// R6GameService.dll code @ 1002f350
constexpr unsigned int registration_service_SetRegistrationCallback2 = 0x1002f350;
// R6GameService.dll code @ 1002f360
constexpr unsigned int registration_service_SetRegistrationCallback3 = 0x1002f360;
// R6GameService.dll code @ 1002f370
constexpr unsigned int registration_service_SetRegistrationCallback4 = 0x1002f370;
// R6GameService.dll code @ 1002f380
constexpr unsigned int registration_service_SetRegistrationCallback5 = 0x1002f380;
// R6GameService.dll code @ 1002f390
constexpr unsigned int registration_service_SetRegistrationCallback6 = 0x1002f390;
// R6GameService.dll code @ 1002f3a0
constexpr unsigned int ConnectToLobbyServer = 0x1002f3a0;
// R6GameService.dll code @ 1002f3c0
constexpr unsigned int CloseLobbyServerConnection = 0x1002f3c0;
// R6GameService.dll code @ 1002f3d0
constexpr unsigned int SendLobbyServerLogin = 0x1002f3d0;
// R6GameService.dll code @ 1002f3e0
constexpr unsigned int SendOptionalFieldsThroughSecondaryService = 0x1002f3e0;
// R6GameService.dll code @ 1002f410
constexpr unsigned int registration_service_SetRegistrationCallback7 = 0x1002f410;
// R6GameService.dll code @ 1002f420
constexpr unsigned int registration_service_SetRegistrationCallback8 = 0x1002f420;
// R6GameService.dll code @ 1002f430
constexpr unsigned int registration_service_SetRegistrationCallback9 = 0x1002f430;
// R6GameService.dll code @ 1002f440
constexpr unsigned int NoOpRegistrationCallbackRet1C = 0x1002f440;
// R6GameService.dll code @ 1002f450
constexpr unsigned int NoOpRegistrationCallbackRet54 = 0x1002f450;
// R6GameService.dll code @ 1002f460
constexpr unsigned int ConstructRegistrationService = 0x1002f460;
// R6GameService.dll code @ 1002f580
constexpr unsigned int DeleteRegistrationService = 0x1002f580;
// R6GameService.dll code @ 1002f5b0
constexpr unsigned int DestroyRegistrationService = 0x1002f5b0;
// R6GameService.dll code @ 1002f5d0
constexpr unsigned int ForwardRegistrationCallback = 0x1002f5d0;
// R6GameService.dll code @ 1002f5e0
constexpr unsigned int registration_service_ForwardRegistrationCallback = 0x1002f5e0;
// R6GameService.dll code @ 1002f5f0
constexpr unsigned int registration_service_ForwardRegistrationCallback2 = 0x1002f5f0;
// R6GameService.dll code @ 1002f610
constexpr unsigned int registration_service_ForwardRegistrationCallback3 = 0x1002f610;
// R6GameService.dll code @ 1002f620
constexpr unsigned int ForwardSecondaryLobbyLoginResults = 0x1002f620;
// R6GameService.dll code @ 1002f630
constexpr unsigned int registration_service_ForwardRegistrationCallback4 = 0x1002f630;
// R6GameService.dll code @ 1002f640
constexpr unsigned int registration_service_ForwardRegistrationCallback5 = 0x1002f640;
// R6GameService.dll code @ 1002f650
constexpr unsigned int registration_service_ForwardRegistrationCallback6 = 0x1002f650;
// R6GameService.dll code @ 1002f670
constexpr unsigned int registration_service_ForwardRegistrationCallback7 = 0x1002f670;
// R6GameService.dll code @ 1002f680
constexpr unsigned int registration_service_ForwardRegistrationCallback8 = 0x1002f680;
// R6GameService.dll code @ 1002f690
constexpr unsigned int registration_service_ForwardRegistrationCallback9 = 0x1002f690;
// R6GameService.dll code @ 1002f6a0
constexpr unsigned int registration_service_ForwardRegistrationCallback10 = 0x1002f6a0;
// R6GameService.dll code @ 1002f6b0
constexpr unsigned int registration_service_ForwardRegistrationCallback11 = 0x1002f6b0;
// R6GameService.dll code @ 1002f6c0
constexpr unsigned int registration_service_ForwardRegistrationCallback12 = 0x1002f6c0;
// R6GameService.dll code @ 1002f6e0
constexpr unsigned int registration_service_ForwardRegistrationCallback13 = 0x1002f6e0;
// R6GameService.dll code @ 1002f6f0
constexpr unsigned int StoreCallbackAtOffset_0x13c = 0x1002f6f0;
// R6GameService.dll code @ 1002f700
constexpr unsigned int StoreCallbackAtOffset_0x140 = 0x1002f700;
// R6GameService.dll code @ 1002f710
constexpr unsigned int StoreCallbackAtOffset_0x14c = 0x1002f710;
// R6GameService.dll code @ 1002f720
constexpr unsigned int StoreCallbackAtOffset_0x150 = 0x1002f720;
// R6GameService.dll code @ 1002f730
constexpr unsigned int StoreCallbackAtOffset_0x158 = 0x1002f730;
// R6GameService.dll code @ 1002f740
constexpr unsigned int StoreCallbackAtOffset_0x15c = 0x1002f740;
// R6GameService.dll code @ 1002f750
constexpr unsigned int DeleteRegistrationServiceFromAdjustedBase = 0x1002f750;
// R6GameService.dll code @ 1002f760
constexpr unsigned int InitializeRegistrationServiceState = 0x1002f760;
// R6GameService.dll code @ 1002f820
constexpr unsigned int DeleteRegistrationServiceState = 0x1002f820;
// R6GameService.dll code @ 1002f840
constexpr unsigned int DestroyRegistrationServiceState = 0x1002f840;
// R6GameService.dll code @ 1002f870
constexpr unsigned int registration_service_ConnectRegistrationEndpoint = 0x1002f870;
// R6GameService.dll code @ 1002f960
constexpr unsigned int PumpRegistrationMessages = 0x1002f960;
// R6GameService.dll code @ 1002fa30
constexpr unsigned int UpdateRegistrationState = 0x1002fa30;
// R6GameService.dll code @ 1002fa80
constexpr unsigned int DropRegistrationTransport = 0x1002fa80;
// R6GameService.dll code @ 1002fac0
constexpr unsigned int ClearSecondaryServiceState = 0x1002fac0;
// R6GameService.dll code @ 1002fb00
constexpr unsigned int SendRouterDisconnectIfAvailable = 0x1002fb00;
// R6GameService.dll code @ 1002fb20
constexpr unsigned int SendRouterLoginRequest = 0x1002fb20;
// R6GameService.dll code @ 1002fca0
constexpr unsigned int SendOpcodeD9TextRequest = 0x1002fca0;
// R6GameService.dll code @ 1002fde0
constexpr unsigned int SendServerRegistrationOpcodeD5 = 0x1002fde0;
// R6GameService.dll code @ 10030310
constexpr unsigned int DispatchParsedOpcode26Or27 = 0x10030310;
// R6GameService.dll code @ 10030410
constexpr unsigned int DispatchParsedOpcode26Or27Strings = 0x10030410;
// R6GameService.dll code @ 10030580
constexpr unsigned int DispatchParsedOpcode26Or27RecordList = 0x10030580;
// R6GameService.dll code @ 100307e0
constexpr unsigned int ConnectLobbyServerTransport = 0x100307e0;
// R6GameService.dll code @ 100308c0
constexpr unsigned int CloseLobbyServerTransport = 0x100308c0;
// R6GameService.dll code @ 100308e0
constexpr unsigned int SendLobbyServerLoginRequest = 0x100308e0;
// R6GameService.dll code @ 10030a10
constexpr unsigned int SendOptionalRegistrationFields = 0x10030a10;
// R6GameService.dll code @ 10030e50
constexpr unsigned int SendRegistrationMatchStart = 0x10030e50;
// R6GameService.dll code @ 10030fe0
constexpr unsigned int SendRegistrationMatchFinish = 0x10030fe0;
// R6GameService.dll code @ 10031160
constexpr unsigned int PollSecondaryRegistrationService = 0x10031160;
// R6GameService.dll code @ 100311a0
constexpr unsigned int DrainSecondaryRegistrationMessages = 0x100311a0;
// R6GameService.dll interior-code @ 1003122c
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase1 = 0x1003122c;
// R6GameService.dll interior-code @ 1003123b
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase2 = 0x1003123b;
// R6GameService.dll interior-code @ 10031249
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase3 = 0x10031249;
// R6GameService.dll interior-code @ 10031257
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase5 = 0x10031257;
// R6GameService.dll interior-code @ 10031265
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase7 = 0x10031265;
// R6GameService.dll interior-code @ 10031273
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase4 = 0x10031273;
// R6GameService.dll interior-code @ 10031281
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase6 = 0x10031281;
// R6GameService.dll interior-code @ 1003128d
constexpr unsigned int GSecondaryRegistrationDispatchTargetsCase8 = 0x1003128d;
// R6GameService.dll data @ 100312b0
constexpr unsigned int GSecondaryRegistrationDispatchTargets = 0x100312b0;
// R6GameService.dll data @ 100312d0
constexpr unsigned int GSecondaryRegistrationSelectorMap = 0x100312d0;
// R6GameService.dll code @ 100312f0
constexpr unsigned int RouteSecondaryRegistrationReply = 0x100312f0;
// R6GameService.dll interior-code @ 10031351
constexpr unsigned int GNestedRegistrationReplyTargetsCase2 = 0x10031351;
// R6GameService.dll interior-code @ 10031364
constexpr unsigned int GNestedRegistrationReplyTargetsCase4 = 0x10031364;
// R6GameService.dll interior-code @ 10031377
constexpr unsigned int GNestedRegistrationReplyTargetsCase1 = 0x10031377;
// R6GameService.dll interior-code @ 1003138a
constexpr unsigned int GNestedRegistrationReplyTargetsCase3 = 0x1003138a;
// R6GameService.dll interior-code @ 10031397
constexpr unsigned int GNestedRegistrationReplyTargetsCase5 = 0x10031397;
// R6GameService.dll data @ 100313a0
constexpr unsigned int GNestedRegistrationReplyTargets = 0x100313a0;
// R6GameService.dll data @ 100313b4
constexpr unsigned int GNestedRegistrationReplySelectorMap = 0x100313b4;
// R6GameService.dll code @ 10031480
constexpr unsigned int DispatchRegistrationUpdateReply = 0x10031480;
// R6GameService.dll code @ 100314f0
constexpr unsigned int DispatchSecondaryRegistrationLoginReply = 0x100314f0;
// R6GameService.dll code @ 100315b0
constexpr unsigned int DispatchSecondaryPayloadNotification = 0x100315b0;
// R6GameService.dll code @ 100316d0
constexpr unsigned int DispatchRegistrationMatchStartReply = 0x100316d0;
// R6GameService.dll code @ 10031760
constexpr unsigned int DispatchSecondaryTextNotification = 0x10031760;
// R6GameService.dll code @ 10031790
constexpr unsigned int DispatchRegistrationMatchFinishReply = 0x10031790;
// R6GameService.dll code @ 10031810
constexpr unsigned int DispatchSecondaryIntegerPair = 0x10031810;
// R6GameService.dll code @ 10031850
constexpr unsigned int DispatchSecondaryTextAndWord = 0x10031850;
// R6GameService.dll code @ 100318a0
constexpr unsigned int DispatchTwentyFieldNotification = 0x100318a0;
// R6GameService.dll code @ 10031bb0
constexpr unsigned int DispatchSecondaryBinaryTextNotification = 0x10031bb0;
// R6GameService.dll code @ 10031c40
constexpr unsigned int InitializeParsedServiceRecord = 0x10031c40;
// R6GameService.dll code @ 10031cb0
constexpr unsigned int InitializeEmptyParsedServiceRecord = 0x10031cb0;
// R6GameService.dll code @ 10031d00
constexpr unsigned int CopyParsedServiceRecord = 0x10031d00;
// R6GameService.dll code @ 10031d50
constexpr unsigned int ConstructParsedServiceRecordList = 0x10031d50;
// R6GameService.dll code @ 10031d90
constexpr unsigned int DestroyParsedServiceRecordList = 0x10031d90;
// R6GameService.dll code @ 10031e20
constexpr unsigned int DestroyParsedServiceRecordListObject = 0x10031e20;
// R6GameService.dll code @ 10031e40
constexpr unsigned int CopyGreatestParsedServiceRecord = 0x10031e40;
// R6GameService.dll code @ 10031ec0
constexpr unsigned int EraseOwningPointerListNode = 0x10031ec0;
// R6GameService.dll code @ 10031f00
constexpr unsigned int EraseOwningPointerListRange = 0x10031f00;
// R6GameService.dll code @ 10031f70
constexpr unsigned int CountCircularListRange = 0x10031f70;
// R6GameService.dll code @ 10031f90
constexpr unsigned int ConstructClonedPayloadWrapper = 0x10031f90;
// R6GameService.dll code @ 10032030
constexpr unsigned int InitializeTransportState = 0x10032030;
// R6GameService.dll code @ 10032080
constexpr unsigned int ConnectAddressTransport = 0x10032080;
// R6GameService.dll code @ 10032150
constexpr unsigned int IsTransportConnected = 0x10032150;
// R6GameService.dll code @ 10032170
constexpr unsigned int SendTransportPayload = 0x10032170;
// R6GameService.dll code @ 100321a0
constexpr unsigned int SendConnectedTransportPayload = 0x100321a0;
// R6GameService.dll code @ 100321d0
constexpr unsigned int QueryProviderPeerEndpoint = 0x100321d0;
// R6GameService.dll code @ 100321e0
constexpr unsigned int TakeNextTransportMessage = 0x100321e0;
// R6GameService.dll code @ 10032280
constexpr unsigned int CreateMSClientSingleton = 0x10032280;
// R6GameService.dll code @ 10032300
constexpr unsigned int CloseMSClientSingleton = 0x10032300;
// R6GameService.dll code @ 10032320
constexpr unsigned int DispatchMSClientState = 0x10032320;
// R6GameService.dll code @ 10032340
constexpr unsigned int ForwardMSClientOperation1 = 0x10032340;
// R6GameService.dll code @ 10032360
constexpr unsigned int ForwardMSClientOperation2 = 0x10032360;
// R6GameService.dll code @ 10032380
constexpr unsigned int ForwardMSClientOperation3 = 0x10032380;
// R6GameService.dll code @ 100323a0
constexpr unsigned int SetSingletonServiceRequest = 0x100323a0;
// R6GameService.dll code @ 100323c0
constexpr unsigned int MatchMSClientStoredRequest = 0x100323c0;
// R6GameService.dll code @ 100323e0
constexpr unsigned int ForwardMSClientOperation4 = 0x100323e0;
// R6GameService.dll code @ 10032400
constexpr unsigned int ForwardMSClientOperation5 = 0x10032400;
// R6GameService.dll code @ 10032420
constexpr unsigned int ForwardMSClientOperation6 = 0x10032420;
// R6GameService.dll code @ 10032440
constexpr unsigned int DispatchSingletonSubobject3f1a0 = 0x10032440;
// R6GameService.dll code @ 10032460
constexpr unsigned int DispatchSingletonSubobject3f1b0 = 0x10032460;
// R6GameService.dll code @ 10032480
constexpr unsigned int DispatchSingletonSubobject3f1c0 = 0x10032480;
// R6GameService.dll code @ 100324a0
constexpr unsigned int DispatchSingletonSubobject3f1e0 = 0x100324a0;
// R6GameService.dll code @ 100324c0
constexpr unsigned int SetMSClientCallback1 = 0x100324c0;
// R6GameService.dll code @ 100324e0
constexpr unsigned int SetMSClientCallback2 = 0x100324e0;
// R6GameService.dll code @ 10032500
constexpr unsigned int SetMSClientCallback3 = 0x10032500;
// R6GameService.dll code @ 10032520
constexpr unsigned int SetMSClientCallback4 = 0x10032520;
// R6GameService.dll code @ 10032540
constexpr unsigned int SetMSClientCallback5 = 0x10032540;
// R6GameService.dll code @ 10032560
constexpr unsigned int SetMSClientCallback6 = 0x10032560;
// R6GameService.dll code @ 10032580
constexpr unsigned int SetMSClientCallback7 = 0x10032580;
// R6GameService.dll code @ 100325a0
constexpr unsigned int SetMSClientCallback8 = 0x100325a0;
// R6GameService.dll code @ 100325c0
constexpr unsigned int SetMSClientCallback9 = 0x100325c0;
// R6GameService.dll code @ 100325e0
constexpr unsigned int SetMSClientCallback10 = 0x100325e0;
// R6GameService.dll code @ 10032600
constexpr unsigned int clMSClientClass_clMSClientClass = 0x10032600;
// R6GameService.dll code @ 10032710
constexpr unsigned int DeleteServiceClient = 0x10032710;
// R6GameService.dll code @ 10032730
constexpr unsigned int DestroyServiceClient = 0x10032730;
// R6GameService.dll code @ 100327a0
constexpr unsigned int InitializeServiceClientFields = 0x100327a0;
// R6GameService.dll code @ 100328a0
constexpr unsigned int NoOpServiceCallbackRet30 = 0x100328a0;
// R6GameService.dll code @ 100328b0
constexpr unsigned int ReleaseServiceClientResources = 0x100328b0;
// R6GameService.dll code @ 10032920
constexpr unsigned int NoOpServiceCallbackRet14 = 0x10032920;
// R6GameService.dll code @ 10032930
constexpr unsigned int NoOpServiceCallbackRet10 = 0x10032930;
// R6GameService.dll code @ 10032940
constexpr unsigned int ProcessServiceClientState = 0x10032940;
// R6GameService.dll code @ 100329e0
constexpr unsigned int NoOpServiceCallbackRet18 = 0x100329e0;
// R6GameService.dll code @ 100329f0
constexpr unsigned int NoOpServiceCallbackRet0C = 0x100329f0;
// R6GameService.dll code @ 10032a00
constexpr unsigned int clMSClient_clMSClient = 0x10032a00;
// R6GameService.dll code @ 10032ad0
constexpr unsigned int DeleteExtendedServiceClient = 0x10032ad0;
// R6GameService.dll code @ 10032af0
constexpr unsigned int DestroyExtendedServiceClient = 0x10032af0;
// R6GameService.dll code @ 10032b20
constexpr unsigned int StoreValueAtOffset_0x11c = 0x10032b20;
// R6GameService.dll code @ 10032b30
constexpr unsigned int StoreValueAtOffset_0x120 = 0x10032b30;
// R6GameService.dll code @ 10032b40
constexpr unsigned int StoreValueAtOffset_0x124 = 0x10032b40;
// R6GameService.dll code @ 10032b50
constexpr unsigned int StoreValueAtOffset_0x128 = 0x10032b50;
// R6GameService.dll code @ 10032b60
constexpr unsigned int StoreValueAtOffset_0x12c = 0x10032b60;
// R6GameService.dll code @ 10032b70
constexpr unsigned int StoreValueAtOffset_0x130 = 0x10032b70;
// R6GameService.dll code @ 10032b80
constexpr unsigned int StoreCallbackAtOffset_0x134 = 0x10032b80;
// R6GameService.dll code @ 10032b90
constexpr unsigned int StoreCallbackAtOffset_0x138 = 0x10032b90;
// R6GameService.dll code @ 10032ba0
constexpr unsigned int StoreCallbackAtOffset_0x144 = 0x10032ba0;
// R6GameService.dll code @ 10032bb0
constexpr unsigned int StoreCallbackAtOffset_0x148 = 0x10032bb0;
// R6GameService.dll code @ 10032bc0
constexpr unsigned int clMSClient_DispatchCallbackAt11c = 0x10032bc0;
// R6GameService.dll code @ 10032be0
constexpr unsigned int clMSClient_DispatchCallbackAt120 = 0x10032be0;
// R6GameService.dll code @ 10032bf0
constexpr unsigned int clMSClient_DispatchCallbackAt124 = 0x10032bf0;
// R6GameService.dll code @ 10032c00
constexpr unsigned int clMSClient_DispatchCallbackAt128 = 0x10032c00;
// R6GameService.dll code @ 10032c20
constexpr unsigned int clMSClient_DispatchCallbackAt12c = 0x10032c20;
// R6GameService.dll code @ 10032c30
constexpr unsigned int clMSClient_DispatchCallbackAt130 = 0x10032c30;
// R6GameService.dll code @ 10032c40
constexpr unsigned int clMSClient_DispatchCallbackAt134 = 0x10032c40;
// R6GameService.dll code @ 10032c50
constexpr unsigned int clMSClient_DispatchCallbackAt138 = 0x10032c50;
// R6GameService.dll code @ 10032c70
constexpr unsigned int clMSClient_DispatchCallbackAt13c = 0x10032c70;
// R6GameService.dll code @ 10032c90
constexpr unsigned int clMSClient_DispatchCallbackAt140 = 0x10032c90;
// R6GameService.dll code @ 10032cb0
constexpr unsigned int clMSClient_DispatchCallbackAt144 = 0x10032cb0;
// R6GameService.dll code @ 10032cc0
constexpr unsigned int clMSClient_DispatchCallbackAt148 = 0x10032cc0;
// R6GameService.dll code @ 10032ce0
constexpr unsigned int clMSClient_DispatchCallbackAt14c = 0x10032ce0;
// R6GameService.dll code @ 10032d00
constexpr unsigned int clMSClientClass_DispatchSelector26StringOrVirtual = 0x10032d00;
// R6GameService.dll code @ 10032d60
constexpr unsigned int clMSClientClass_DispatchSelector26OrVirtual = 0x10032d60;
// R6GameService.dll code @ 10032dd0
constexpr unsigned int clMSClientClass_DispatchSelector26OrVirtual2 = 0x10032dd0;
// R6GameService.dll code @ 10032e20
constexpr unsigned int clMSClientClass_DispatchSelector26BufferOrVirtual = 0x10032e20;
// R6GameService.dll code @ 10032e70
constexpr unsigned int clMSClientClass_TailVirtual34 = 0x10032e70;
// R6GameService.dll code @ 10032e80
constexpr unsigned int clMSClientClass_NotifyVirtual48ThenResetProvider = 0x10032e80;
// R6GameService.dll code @ 10032ea0
constexpr unsigned int clMSClientClass_TailVirtual4c = 0x10032ea0;
// R6GameService.dll code @ 10032eb0
constexpr unsigned int clMSClientClass_TailVirtual58 = 0x10032eb0;
// R6GameService.dll code @ 10032ec0
constexpr unsigned int CheckChainedProviderHelpers = 0x10032ec0;
// R6GameService.dll code @ 10032f00
constexpr unsigned int NotifySelector27 = 0x10032f00;
// R6GameService.dll code @ 10032f20
constexpr unsigned int CompleteCurrentThenNotify = 0x10032f20;
// R6GameService.dll code @ 10032f60
constexpr unsigned int NotifyAndReset = 0x10032f60;
// R6GameService.dll code @ 10032f90
constexpr unsigned int StoreCurrentRecordWord = 0x10032f90;
// R6GameService.dll code @ 10032fd0
constexpr unsigned int NotifySelector27AndRunHelper = 0x10032fd0;
// R6GameService.dll code @ 10033030
constexpr unsigned int ForwardServerAndSetDeadline = 0x10033030;
// R6GameService.dll code @ 100330e0
constexpr unsigned int QueueProviderCallbackRecord = 0x100330e0;
// R6GameService.dll code @ 10033290
constexpr unsigned int ForwardEmbeddedCallback = 0x10033290;
// R6GameService.dll code @ 10033320
constexpr unsigned int RetainDiagnosticArguments = 0x10033320;
// R6GameService.dll code @ 10033340
constexpr unsigned int TailNotifyOne = 0x10033340;
// R6GameService.dll code @ 10033360
constexpr unsigned int ForwardSwappedPair = 0x10033360;
// R6GameService.dll code @ 10033380
constexpr unsigned int TailSubmitWords = 0x10033380;
// R6GameService.dll code @ 100333a0
constexpr unsigned int ForwardSevenThenSetFlag = 0x100333a0;
// R6GameService.dll code @ 100333e0
constexpr unsigned int DispatchSelector26Words = 0x100333e0;
// R6GameService.dll code @ 10033420
constexpr unsigned int ResetServiceClientState = 0x10033420;
// R6GameService.dll code @ 10033490
constexpr unsigned int TryEnableServiceClient = 0x10033490;
// R6GameService.dll code @ 100334c0
constexpr unsigned int UpdateServiceIdentityAndReplayRecords = 0x100334c0;
// R6GameService.dll code @ 10033590
constexpr unsigned int DispatchKind64RecordWhenEnabled = 0x10033590;
// R6GameService.dll code @ 100335c0
constexpr unsigned int DispatchRecordWhenEnabled = 0x100335c0;
// R6GameService.dll code @ 100335f0
constexpr unsigned int SetServiceClientRequest = 0x100335f0;
// R6GameService.dll code @ 10033730
constexpr unsigned int CompleteStoredRequestIfMatched = 0x10033730;
// R6GameService.dll code @ 100337a0
constexpr unsigned int ForwardProviderOperation3f1f0 = 0x100337a0;
// R6GameService.dll code @ 100337c0
constexpr unsigned int ForwardAdjustedProviderOperation = 0x100337c0;
// R6GameService.dll code @ 100337d0
constexpr unsigned int ForwardProviderOperation3f1a0 = 0x100337d0;
// R6GameService.dll code @ 100337e0
constexpr unsigned int ForwardProviderOperation3f1b0 = 0x100337e0;
// R6GameService.dll code @ 10033800
constexpr unsigned int DestroyEmbeddedServiceRecordList = 0x10033800;
// R6GameService.dll code @ 10033810
constexpr unsigned int ForwardProviderOperation3f1d0 = 0x10033810;
// R6GameService.dll code @ 10033830
constexpr unsigned int ForwardProviderOperation3f1e0 = 0x10033830;
// R6GameService.dll code @ 10033850
constexpr unsigned int CopyCallbackRecord = 0x10033850;
// R6GameService.dll code @ 100338e0
constexpr unsigned int InitializeCallbackListSentinel = 0x100338e0;
// R6GameService.dll code @ 10033900
constexpr unsigned int ForwardExceptHandler3 = 0x10033900;
// R6GameService.dll code @ 10033906
constexpr unsigned int __CxxFrameHandler = 0x10033906;
// R6GameService.dll code @ 1003390c
constexpr unsigned int __ArrayUnwind = 0x1003390c;
// R6GameService.dll interior-code @ 1003392f
constexpr unsigned int runtime_array_supportBranch2 = 0x1003392f;
// R6GameService.dll code @ 1003393b
constexpr unsigned int FilterArrayUnwindException = 0x1003393b;
// R6GameService.dll code @ 1003395f
constexpr unsigned int ResumeArrayUnwindHandler = 0x1003395f;
// R6GameService.dll code @ 1003396a
constexpr unsigned int _eh_vector_destructor_iterator_ = 0x1003396a;
// R6GameService.dll code @ 100339b2
constexpr unsigned int UnwindArrayDestructorIterator = 0x100339b2;
// R6GameService.dll code @ 100339ca
constexpr unsigned int VectorDeletingTypeInfo = 0x100339ca;
// R6GameService.dll code @ 10033a16
constexpr unsigned int _CxxThrowException = 0x10033a16;
// R6GameService.dll code @ 10033a1c
constexpr unsigned int free = 0x10033a1c;
// R6GameService.dll code @ 10033a22
constexpr unsigned int exception_exception = 0x10033a22;
// R6GameService.dll code @ 10033a28
constexpr unsigned int bad_cast_bad_cast = 0x10033a28;
// R6GameService.dll code @ 10033a2e
constexpr unsigned int bad_cast__bad_cast = 0x10033a2e;
// R6GameService.dll code @ 10033a34
constexpr unsigned int __onexit = 0x10033a34;
// R6GameService.dll code @ 10033a5a
constexpr unsigned int _atexit = 0x10033a5a;
// R6GameService.dll code @ 10033a6c
constexpr unsigned int strncpy = 0x10033a6c;
// R6GameService.dll code @ 10033a72
constexpr unsigned int strncmp = 0x10033a72;
// R6GameService.dll code @ 10033a78
constexpr unsigned int _snprintf = 0x10033a78;
// R6GameService.dll code @ 10033a7e
constexpr unsigned int sprintf = 0x10033a7e;
// R6GameService.dll code @ 10033a84
constexpr unsigned int printf = 0x10033a84;
// R6GameService.dll code @ 10033a8a
constexpr unsigned int atoi = 0x10033a8a;
// R6GameService.dll code @ 10033a90
constexpr unsigned int rename = 0x10033a90;
// R6GameService.dll code @ 10033a96
constexpr unsigned int remove = 0x10033a96;
// R6GameService.dll code @ 10033a9c
constexpr unsigned int fread = 0x10033a9c;
// R6GameService.dll code @ 10033aa2
constexpr unsigned int fclose = 0x10033aa2;
// R6GameService.dll code @ 10033aa8
constexpr unsigned int fopen = 0x10033aa8;
// R6GameService.dll code @ 10033ab0
constexpr unsigned int __chkstk = 0x10033ab0;
// R6GameService.dll code @ 10033aed
constexpr unsigned int __CRT_INIT_12 = 0x10033aed;
// R6GameService.dll code @ 10033bab
constexpr unsigned int entry = 0x10033bab;
// R6GameService.dll code @ 10033c6d
constexpr unsigned int FilterCrtDllNotificationException = 0x10033c6d;
// R6GameService.dll code @ 10033c7e
constexpr unsigned int ResumeFailedCrtDllNotification = 0x10033c7e;
// R6GameService.dll code @ 10033c90
constexpr unsigned int toupper = 0x10033c90;
// R6GameService.dll code @ 10033c96
constexpr unsigned int fwrite = 0x10033c96;
// R6GameService.dll code @ 10033c9c
constexpr unsigned int memmove = 0x10033c9c;
// R6GameService.dll code @ 10033ca2
constexpr unsigned int exception_exception2 = 0x10033ca2;
// R6GameService.dll code @ 10033ca8
constexpr unsigned int exception__exception = 0x10033ca8;
// R6GameService.dll code @ 10033cae
constexpr unsigned int calloc = 0x10033cae;
// R6GameService.dll code @ 10033cb4
constexpr unsigned int _purecall = 0x10033cb4;
// R6GameService.dll code @ 10033cba
constexpr unsigned int time = 0x10033cba;
// R6GameService.dll code @ 10033cc0
constexpr unsigned int difftime = 0x10033cc0;
// R6GameService.dll code @ 10033cc6
constexpr unsigned int __RTDynamicCast = 0x10033cc6;
// R6GameService.dll code @ 10033cd0
constexpr unsigned int SignedDivide64 = 0x10033cd0;
// R6GameService.dll code @ 10033d80
constexpr unsigned int Multiply64LowBits = 0x10033d80;
// R6GameService.dll code @ 10033db4
constexpr unsigned int strtok = 0x10033db4;
// R6GameService.dll code @ 10033dba
constexpr unsigned int ForwardTerminate = 0x10033dba;
// R6GameService.dll code @ 10033dc0
constexpr unsigned int __SEH_prolog = 0x10033dc0;
// R6GameService.dll code @ 10033dfb
constexpr unsigned int __SEH_epilog = 0x10033dfb;
// R6GameService.dll code @ 10033e0c
constexpr unsigned int type_info__type_info = 0x10033e0c;
// R6GameService.dll code @ 10033e12
constexpr unsigned int __dllonexit = 0x10033e12;
// R6GameService.dll code @ 10033e18
constexpr unsigned int initterm = 0x10033e18;
// R6GameService.dll code @ 10033e1e
constexpr unsigned int __RTC_Initialize = 0x10033e1e;
// R6GameService.dll code @ 10033e4b
constexpr unsigned int FilterRtcInitializeException = 0x10033e4b;
// R6GameService.dll code @ 10033e4f
constexpr unsigned int ResumeRtcInitializeAfterException = 0x10033e4f;
// R6GameService.dll code @ 10033e62
constexpr unsigned int RunCrtTerminationCallbacks = 0x10033e62;
// R6GameService.dll code @ 10033e8f
constexpr unsigned int FilterRtcTerminationException = 0x10033e8f;
// R6GameService.dll code @ 10033e93
constexpr unsigned int ResumeRtcTerminationAfterException = 0x10033e93;
// R6GameService.dll code @ 10033ea6
constexpr unsigned int ForwardCppExceptionFilter = 0x10033ea6;
// R6GameService.dll code @ 10033eb0
constexpr unsigned int std_logic_error__logic_error = 0x10033eb0;
// R6GameService.dll code @ 10033f10
constexpr unsigned int std_logic_error_what = 0x10033f10;
// R6GameService.dll code @ 10033f20
constexpr unsigned int ScalarDeletingLogicError = 0x10033f20;
// R6GameService.dll code @ 10033f40
constexpr unsigned int ScalarDeletingLengthError = 0x10033f40;
// R6GameService.dll code @ 10033f60
constexpr unsigned int std_length_error__length_error = 0x10033f60;
// R6GameService.dll code @ 10033f70
constexpr unsigned int GetStringVectorElementCount = 0x10033f70;
// R6GameService.dll code @ 10033fa0
constexpr unsigned int ThrowVectorLengthException = 0x10033fa0;
// R6GameService.dll code @ 10034020
constexpr unsigned int std_logic_error_logic_error = 0x10034020;
// R6GameService.dll code @ 10034080
constexpr unsigned int FillByteRange = 0x10034080;
// R6GameService.dll code @ 100340a0
constexpr unsigned int std_length_error_length_error = 0x100340a0;
// R6GameService.dll code @ 100340c0
constexpr unsigned int ReleaseAndResetStorageAt04 = 0x100340c0;
// R6GameService.dll code @ 100340f0
constexpr unsigned int MoveRangeAndReturnEnd = 0x100340f0;
// R6GameService.dll code @ 10034120
constexpr unsigned int CopyByteRangeAndReturnEnd = 0x10034120;
// R6GameService.dll code @ 10034150
constexpr unsigned int ConvertByteRangeToWideHexText = 0x10034150;
// R6GameService.dll interior-code @ 100341cf
constexpr unsigned int GWideHexLowNibbleTargetsCase1 = 0x100341cf;
// R6GameService.dll interior-code @ 100341d6
constexpr unsigned int GWideHexLowNibbleTargetsCase2 = 0x100341d6;
// R6GameService.dll interior-code @ 100341dd
constexpr unsigned int GWideHexLowNibbleTargetsCase3 = 0x100341dd;
// R6GameService.dll interior-code @ 100341e4
constexpr unsigned int GWideHexLowNibbleTargetsCase4 = 0x100341e4;
// R6GameService.dll interior-code @ 100341eb
constexpr unsigned int GWideHexLowNibbleTargetsCase5 = 0x100341eb;
// R6GameService.dll interior-code @ 100341f2
constexpr unsigned int GWideHexLowNibbleTargetsCase6 = 0x100341f2;
// R6GameService.dll interior-code @ 10034247
constexpr unsigned int GWideHexHighNibbleTargetsCase1 = 0x10034247;
// R6GameService.dll interior-code @ 1003425d
constexpr unsigned int GWideHexHighNibbleTargetsCase2 = 0x1003425d;
// R6GameService.dll interior-code @ 10034273
constexpr unsigned int GWideHexHighNibbleTargetsCase3 = 0x10034273;
// R6GameService.dll interior-code @ 10034289
constexpr unsigned int GWideHexHighNibbleTargetsCase4 = 0x10034289;
// R6GameService.dll interior-code @ 1003429f
constexpr unsigned int GWideHexHighNibbleTargetsCase5 = 0x1003429f;
// R6GameService.dll interior-code @ 100342b5
constexpr unsigned int GWideHexHighNibbleTargetsCase6 = 0x100342b5;
// R6GameService.dll data @ 10034328
constexpr unsigned int GWideHexLowNibbleTargets = 0x10034328;
// R6GameService.dll data @ 10034340
constexpr unsigned int GWideHexHighNibbleTargets = 0x10034340;
// R6GameService.dll code @ 10034360
constexpr unsigned int FillRepeatedByte = 0x10034360;
// R6GameService.dll code @ 10034390
constexpr unsigned int InsertRepeatedByte = 0x10034390;
// R6GameService.dll code @ 10034550
constexpr unsigned int PopTrailingBigEndianDword = 0x10034550;
// R6GameService.dll code @ 100345e0
constexpr unsigned int DestroyStdStringRange = 0x100345e0;
// R6GameService.dll code @ 10034610
constexpr unsigned int CopyByteVector = 0x10034610;
// R6GameService.dll code @ 100346ab
constexpr unsigned int ReleaseFailedByteVectorCopy = 0x100346ab;
// R6GameService.dll code @ 100346c0
constexpr unsigned int DestroyStringVector = 0x100346c0;
// R6GameService.dll code @ 10034710
constexpr unsigned int DecodeWideHexToByteVector = 0x10034710;
// R6GameService.dll code @ 10034880
constexpr unsigned int DestroyStringVectorThunk = 0x10034880;
// R6GameService.dll code @ 10034890
constexpr unsigned int BuildByteVectorFromCollectedStrings = 0x10034890;
// R6GameService.dll code @ 10034a30
constexpr unsigned int ComputeCollectedStringsChecksum = 0x10034a30;
// R6GameService.dll code @ 10034a90
constexpr unsigned int AppendCollectedStringsChecksumBytes = 0x10034a90;
// R6GameService.dll code @ 10034bc0
constexpr unsigned int EncryptWideStringToHex = 0x10034bc0;
// R6GameService.dll code @ 10034d00
constexpr unsigned int DecryptHexToWideString = 0x10034d00;
// R6GameService.dll code @ 10034e50
constexpr unsigned int ValidateWideHexMachineChecksum = 0x10034e50;
// R6GameService.dll code @ 10034ee0
constexpr unsigned int ApplyHexRadixManipulator = 0x10034ee0;
// R6GameService.dll code @ 10034f00
constexpr unsigned int RpcGetServiceState = 0x10034f00;
// R6GameService.dll code @ 10034f5a
constexpr unsigned int FilterRpcServiceStateException = 0x10034f5a;
// R6GameService.dll code @ 10034f6a
constexpr unsigned int HandleRpcServiceStateException = 0x10034f6a;
// R6GameService.dll code @ 10034fb0
constexpr unsigned int RpcGetServiceExitCause = 0x10034fb0;
// R6GameService.dll code @ 1003500a
constexpr unsigned int FilterRpcExitCauseException = 0x1003500a;
// R6GameService.dll code @ 1003501a
constexpr unsigned int HandleRpcExitCauseException = 0x1003501a;
// R6GameService.dll code @ 10035060
constexpr unsigned int RpcGetDownloadProgress = 0x10035060;
// R6GameService.dll code @ 100350c9
constexpr unsigned int FilterRpcProgressException = 0x100350c9;
// R6GameService.dll code @ 100350d9
constexpr unsigned int HandleRpcProgressException = 0x100350d9;
// R6GameService.dll interior-code @ 100350f8
constexpr unsigned int rpc_client_supportBranch4 = 0x100350f8;
// R6GameService.dll code @ 10035160
constexpr unsigned int RpcAbortUpdateService = 0x10035160;
// R6GameService.dll code @ 100351b5
constexpr unsigned int FilterRpcAbortException = 0x100351b5;
// R6GameService.dll code @ 100351c5
constexpr unsigned int HandleRpcAbortException = 0x100351c5;
// R6GameService.dll code @ 10035210
constexpr unsigned int ConstructUpdateServiceReceiver = 0x10035210;
// R6GameService.dll code @ 100352a0
constexpr unsigned int DestroyUpdateServiceReceiver = 0x100352a0;
// R6GameService.dll code @ 10035330
constexpr unsigned int GetServiceStateIfRefreshDue = 0x10035330;
// R6GameService.dll code @ 10035460
constexpr unsigned int GetServiceExitCauseIfUnset = 0x10035460;
// R6GameService.dll code @ 10035560
constexpr unsigned int GetDownloadProgressWithCache = 0x10035560;
// R6GameService.dll code @ 100357a0
constexpr unsigned int RequestAbortUpdateServiceWithLogging = 0x100357a0;
// R6GameService.dll code @ 10035870
constexpr unsigned int CreateServiceObjectInPointerSlot = 0x10035870;
// R6GameService.dll code @ 100358e0
constexpr unsigned int StoreWideStringAndPrintStart = 0x100358e0;
// R6GameService.dll code @ 10035920
constexpr unsigned int GetServiceStateThroughStoredReceiver = 0x10035920;
// R6GameService.dll code @ 10035930
constexpr unsigned int GetServiceExitCauseThroughStoredReceiver = 0x10035930;
// R6GameService.dll code @ 10035940
constexpr unsigned int GetDownloadProgressThroughStoredReceiver = 0x10035940;
// R6GameService.dll code @ 10035950
constexpr unsigned int RequestAbortUpdateServiceThroughStoredReceiver = 0x10035950;
// R6GameService.dll code @ 10035960
constexpr unsigned int SetServiceCacheInterval = 0x10035960;
// R6GameService.dll code @ 10035970
constexpr unsigned int StartUpdateServiceProcessAndConnectRpc = 0x10035970;
// R6GameService.dll code @ 10035ad0
constexpr unsigned int DestroyServiceObjectInPointerSlot = 0x10035ad0;
// R6GameService.dll code @ 10035af0
constexpr unsigned int StartUpdateServiceThroughStoredReceiver = 0x10035af0;
// R6GameService.dll code @ 10035b00
constexpr unsigned int TestDirectoryCreateDeleteAccess = 0x10035b00;
// R6GameService.dll code @ 10035db0
constexpr unsigned int GetDirectoryLogFirstWord = 0x10035db0;
// R6GameService.dll code @ 10035dc0
constexpr unsigned int GetDirectoryAccessTestLogStream = 0x10035dc0;
// R6GameService.dll code @ 10035dd0
constexpr unsigned int AssignStdStringRange = 0x10035dd0;
// R6GameService.dll code @ 10035e00
constexpr unsigned int CopyStdStringsBackward = 0x10035e00;
// R6GameService.dll code @ 10035e40
constexpr unsigned int ConstructStdStringRange = 0x10035e40;
// R6GameService.dll code @ 10035e97
constexpr unsigned int DestroyFailedStringRangePrefixAndRethrow = 0x10035e97;
// R6GameService.dll code @ 10035ed0
constexpr unsigned int ConstructRepeatedStdStrings = 0x10035ed0;
// R6GameService.dll code @ 10035f27
constexpr unsigned int DestroyFailedRepeatedStringPrefixAndRethrow = 0x10035f27;
// R6GameService.dll code @ 10035f60
constexpr unsigned int InitializeFilledByteVector = 0x10035f60;
// R6GameService.dll code @ 10035fc0
constexpr unsigned int ConstructRepeatedStdStringRange = 0x10035fc0;
// R6GameService.dll code @ 10035ff0
constexpr unsigned int InsertRepeatedStdStringsAtPosition = 0x10035ff0;
// R6GameService.dll code @ 100361d1
constexpr unsigned int DestroyFailedStringInsertionAndRethrow = 0x100361d1;
// R6GameService.dll code @ 1003628d
constexpr unsigned int DestroyShiftedStringTailAndRethrow = 0x1003628d;
// R6GameService.dll code @ 10036320
constexpr unsigned int InsertOneStdStringAndStoreIterator = 0x10036320;
// R6GameService.dll code @ 10036390
constexpr unsigned int AppendStdStringToVector = 0x10036390;
// R6GameService.dll code @ 10036420
constexpr unsigned int CollectNetworkAdapterMacAddresses = 0x10036420;
// R6GameService.dll code @ 100365d0
constexpr unsigned int UpdateReflectedTableChecksum = 0x100365d0;
// R6GameService.dll code @ 10036610
constexpr unsigned int UpdateForwardChecksumState = 0x10036610;
// R6GameService.dll code @ 10036650
constexpr unsigned int InitializeForwardChecksumTable = 0x10036650;
// R6GameService.dll code @ 100366a0
constexpr unsigned int InitializeReflectedChecksumTable = 0x100366a0;
// R6GameService.dll code @ 10036770
constexpr unsigned int UpdateChecksumFromBuffer = 0x10036770;
// R6GameService.dll code @ 100367b0
constexpr unsigned int checksum_support_UpdateChecksumFromBuffer = 0x100367b0;
// R6GameService.dll code @ 10036820
constexpr unsigned int InvokeStateMidlCall = 0x10036820;
// R6GameService.dll code @ 10036840
constexpr unsigned int InvokeExitCauseMidlCall = 0x10036840;
// R6GameService.dll code @ 10036860
constexpr unsigned int InvokeProgressMidlCall = 0x10036860;
// R6GameService.dll code @ 10036880
constexpr unsigned int InvokeAbortMidlCall = 0x10036880;
// R6GameService.dll code @ 100368a0
constexpr unsigned int InitializeRpcBindingState = 0x100368a0;
// R6GameService.dll code @ 100368b0
constexpr unsigned int ReleaseRpcBindingState = 0x100368b0;
// R6GameService.dll code @ 100368d0
constexpr unsigned int ComposeLocalRpcBinding = 0x100368d0;
// R6GameService.dll code @ 10036951
constexpr unsigned int FilterRpcBindingException = 0x10036951;
// R6GameService.dll code @ 10036961
constexpr unsigned int HandleRpcBindingException = 0x10036961;
// R6GameService.dll code @ 100369f0
constexpr unsigned int AllocateProcessHandleSlot = 0x100369f0;
// R6GameService.dll code @ 10036a20
constexpr unsigned int CloseAndFreeProcessHandleSlot = 0x10036a20;
// R6GameService.dll code @ 10036a40
constexpr unsigned int CreateProcessWithHandleOutput = 0x10036a40;
// R6GameService.dll code @ 10036e20
constexpr unsigned int CreateProcessFromHandleSlot = 0x10036e20;
// R6GameService.dll code @ 10036e30
constexpr unsigned int GetServiceLogStream = 0x10036e30;
// R6GameService.dll code @ 10036e40
constexpr unsigned int RaiseWin32LastErrorAsHResult = 0x10036e40;
// R6GameService.dll code @ 10036e60
constexpr unsigned int ReleaseConversionScratch = 0x10036e60;
// R6GameService.dll code @ 10036e80
constexpr unsigned int ConvertAnsiIntoWideScratch = 0x10036e80;
// R6GameService.dll code @ 10036ef0
constexpr unsigned int ConvertWideIntoAnsiScratch = 0x10036ef0;
// R6GameService.dll code @ 10036f60
constexpr unsigned int ConstructWideStringFromAnsi = 0x10036f60;
// R6GameService.dll code @ 10036ff0
constexpr unsigned int ConstructNarrowStringFromWide = 0x10036ff0;
// R6GameService.dll code @ 10037080
constexpr unsigned int ConstructNarrowStringFromWideString = 0x10037080;
// R6GameService.dll code @ 100370c0
constexpr unsigned int InitializeWideStreamReferences = 0x100370c0;
// R6GameService.dll code @ 100370e0
constexpr unsigned int ReadFirstWord = 0x100370e0;
// R6GameService.dll code @ 100370f0
constexpr unsigned int AllocateMidlBuffer = 0x100370f0;
// R6GameService.dll code @ 10037110
constexpr unsigned int FreeMidlBuffer = 0x10037110;
// R6GameService.dll code @ 10037120
constexpr unsigned int NdrClientCall = 0x10037120;
// R6GameService.dll code @ 10037130
constexpr unsigned int ConstructCurrentDirectoryWideString = 0x10037130;
// R6GameService.dll code @ 100371d0
constexpr unsigned int GetCachedWindowsVersionHighBit = 0x100371d0;
// R6GameService.dll code @ 100371f4
constexpr unsigned int GetAdaptersInfo = 0x100371f4;
// R6GameService.dll code @ 100371fa
constexpr unsigned int RemoveAll = 0x100371fa;
// R6GameService.dll code @ 10037217
constexpr unsigned int ATL__ATL_BASE_MODULE70__ATL_BASE_MODULE70 = 0x10037217;
// R6GameService.dll code @ 10037231
constexpr unsigned int ATL_CAtlBaseModule__CAtlBaseModule = 0x10037231;
// R6GameService.dll code @ 10037247
constexpr unsigned int ATL_CAtlBaseModule_CAtlBaseModule = 0x10037247;
// R6GameService.dll code @ 100372f2
constexpr unsigned int core_import_support_core_import_supportTailImportedMember56 = 0x100372f2;
// R6GameService.dll code @ 100372f8
constexpr unsigned int core_import_support_core_import_supportTailImportedMember57 = 0x100372f8;
// R6GameService.dll code @ 100372fe
constexpr unsigned int core_import_support_core_import_supportTailImportedMember58 = 0x100372fe;
// R6GameService.dll code @ 10037304
constexpr unsigned int core_import_support_core_import_supportTailImportedMember59 = 0x10037304;
// R6GameService.dll code @ 1003730a
constexpr unsigned int core_import_support_core_import_supportTailImportedMember60 = 0x1003730a;
// R6GameService.dll code @ 10037310
constexpr unsigned int core_import_support_core_import_supportTailImportedMember61 = 0x10037310;
// R6GameService.dll code @ 10037316
constexpr unsigned int core_import_support_core_import_supportTailImportedMember62 = 0x10037316;
// R6GameService.dll code @ 1003731c
constexpr unsigned int core_import_support_core_import_supportTailImportedMember63 = 0x1003731c;
// R6GameService.dll code @ 10037322
constexpr unsigned int core_import_support_core_import_supportTailImportedMember64 = 0x10037322;
// R6GameService.dll code @ 10037328
constexpr unsigned int core_import_support_core_import_supportTailImportedMember65 = 0x10037328;
// R6GameService.dll code @ 1003732e
constexpr unsigned int core_import_support_core_import_supportTailImportedMember66 = 0x1003732e;
// R6GameService.dll code @ 10037334
constexpr unsigned int ForwardWSAFDIsSet = 0x10037334;
// R6GameService.dll code @ 10037340
constexpr unsigned int CreateRegisteredHashAlgorithmThunk = 0x10037340;
// R6GameService.dll code @ 10037350
constexpr unsigned int RepeatHashInputThunk = 0x10037350;
// R6GameService.dll code @ 10037360
constexpr unsigned int FinalizeAndCopyHashDigestThunk = 0x10037360;
// R6GameService.dll code @ 10037370
constexpr unsigned int ResetHashAlgorithmThunk = 0x10037370;
// R6GameService.dll code @ 10037380
constexpr unsigned int ReleaseHashAlgorithmOrRegistry = 0x10037380;
// R6GameService.dll code @ 100373a0
constexpr unsigned int CreateRegisteredPRNGAlgorithmThunk = 0x100373a0;
// R6GameService.dll code @ 100373b0
constexpr unsigned int ReleasePRNGAlgorithmOrRegistry = 0x100373b0;
// R6GameService.dll code @ 100373d0
constexpr unsigned int FillPRNGBytesThunk = 0x100373d0;
// R6GameService.dll code @ 100373e0
constexpr unsigned int CreateRegisteredCryptoAlgorithmThunk = 0x100373e0;
// R6GameService.dll code @ 100373f0
constexpr unsigned int ReleaseCryptoAlgorithmOrRegistry = 0x100373f0;
// R6GameService.dll code @ 10037410
constexpr unsigned int EncodeCryptoBufferThunk = 0x10037410;
// R6GameService.dll code @ 10037420
constexpr unsigned int DecodeCryptoBufferThunk = 0x10037420;
// R6GameService.dll code @ 10037430
constexpr unsigned int CreateRegisteredPKCAlgorithmThunk = 0x10037430;
// R6GameService.dll code @ 10037440
constexpr unsigned int ReleasePKCAlgorithmOrRegistry = 0x10037440;
// R6GameService.dll code @ 10037460
constexpr unsigned int GeneratePKCKeyRecordsThunk = 0x10037460;
// R6GameService.dll code @ 10037470
constexpr unsigned int EncodePKCType2BlockThunk = 0x10037470;
// R6GameService.dll code @ 10037480
constexpr unsigned int DecodePKCType2BlockThunk = 0x10037480;
// R6GameService.dll code @ 10037490
constexpr unsigned int InitializePKCRandomStateThunk = 0x10037490;
// R6GameService.dll code @ 100374a0
constexpr unsigned int UpdatePKCRandomSeedThunk = 0x100374a0;
// R6GameService.dll code @ 100374b0
constexpr unsigned int ClearPKCRandomStateThunk = 0x100374b0;
// R6GameService.dll code @ 100374c0
constexpr unsigned int ReadPKCSeedBytesNeededLowByte = 0x100374c0;
// R6GameService.dll code @ 100374e0
constexpr unsigned int DeleteCipherModuleBlowfish = 0x100374e0;
// R6GameService.dll code @ 10037500
constexpr unsigned int ConstructCipherModuleBlowfish = 0x10037500;
// R6GameService.dll code @ 100375b0
constexpr unsigned int DestroyCipherModuleBlowfish = 0x100375b0;
// R6GameService.dll code @ 10037610
constexpr unsigned int SetOwnedBlowfishKey = 0x10037610;
// R6GameService.dll code @ 10037630
constexpr unsigned int ClearOwnedBlowfishTables = 0x10037630;
// R6GameService.dll code @ 10037640
constexpr unsigned int EncodeBlowfishBuffer = 0x10037640;
// R6GameService.dll code @ 10037750
constexpr unsigned int DecodeBlowfishBuffer = 0x10037750;
// R6GameService.dll code @ 10037840
constexpr unsigned int DestroyExtallocOverrideBase = 0x10037840;
// R6GameService.dll code @ 10037850
constexpr unsigned int DeleteCipherModuleGSXor = 0x10037850;
// R6GameService.dll code @ 10037870
constexpr unsigned int ConstructCipherModuleGSXor = 0x10037870;
// R6GameService.dll code @ 100378d0
constexpr unsigned int DestroyCipherModuleGSXor = 0x100378d0;
// R6GameService.dll code @ 10037930
constexpr unsigned int AcceptCipherModuleGSXorKey = 0x10037930;
// R6GameService.dll code @ 10037940
constexpr unsigned int EncodeCipherModuleGSXorBuffer = 0x10037940;
// R6GameService.dll code @ 10037990
constexpr unsigned int DecodeCipherModuleGSXorBuffer = 0x10037990;
// R6GameService.dll code @ 100379e0
constexpr unsigned int CreateRegisteredHashAlgorithm = 0x100379e0;
// R6GameService.dll code @ 10037b60
constexpr unsigned int ReleaseRegisteredHashAlgorithm = 0x10037b60;
// R6GameService.dll code @ 10037ba0
constexpr unsigned int ClearHashAlgorithmRegistry = 0x10037ba0;
// R6GameService.dll code @ 10037bc0
constexpr unsigned int RepeatHashInput = 0x10037bc0;
// R6GameService.dll code @ 10037c00
constexpr unsigned int FinalizeAndCopyHashDigest = 0x10037c00;
// R6GameService.dll code @ 10037c30
constexpr unsigned int ResetHashAlgorithm = 0x10037c30;
// R6GameService.dll code @ 10037c50
constexpr unsigned int CreateRegisteredPRNGAlgorithm = 0x10037c50;
// R6GameService.dll code @ 10037db0
constexpr unsigned int ReleaseRegisteredPRNGAlgorithm = 0x10037db0;
// R6GameService.dll code @ 10037df0
constexpr unsigned int ClearPRNGAlgorithmRegistry = 0x10037df0;
// R6GameService.dll code @ 10037e10
constexpr unsigned int FillPRNGBytes = 0x10037e10;
// R6GameService.dll code @ 10037e50
constexpr unsigned int CreateRegisteredCryptoAlgorithm = 0x10037e50;
// R6GameService.dll code @ 10037fd0
constexpr unsigned int ReleaseRegisteredCryptoAlgorithm = 0x10037fd0;
// R6GameService.dll code @ 10038010
constexpr unsigned int ClearCryptoAlgorithmRegistry = 0x10038010;
// R6GameService.dll code @ 10038030
constexpr unsigned int EncodeCryptoBuffer = 0x10038030;
// R6GameService.dll code @ 10038060
constexpr unsigned int DecodeCryptoBuffer = 0x10038060;
// R6GameService.dll code @ 10038090
constexpr unsigned int CreateRegisteredPKCAlgorithm = 0x10038090;
// R6GameService.dll code @ 100381e0
constexpr unsigned int ReleaseRegisteredPKCAlgorithm = 0x100381e0;
// R6GameService.dll code @ 10038220
constexpr unsigned int ClearPKCAlgorithmRegistry = 0x10038220;
// R6GameService.dll code @ 10038240
constexpr unsigned int GeneratePKCKeyRecords = 0x10038240;
// R6GameService.dll code @ 10038270
constexpr unsigned int EncodePKCType2Block = 0x10038270;
// R6GameService.dll code @ 100382b0
constexpr unsigned int DecodePKCType2Block = 0x100382b0;
// R6GameService.dll code @ 100382e0
constexpr unsigned int InitializePKCRandomState = 0x100382e0;
// R6GameService.dll code @ 10038300
constexpr unsigned int UpdatePKCRandomSeed = 0x10038300;
// R6GameService.dll code @ 10038330
constexpr unsigned int ClearPKCRandomState = 0x10038330;
// R6GameService.dll code @ 10038350
constexpr unsigned int ReadPKCSeedBytesNeeded = 0x10038350;
// R6GameService.dll code @ 10038370
constexpr unsigned int DeleteHashAlgorithmPointerMap = 0x10038370;
// R6GameService.dll code @ 10038390
constexpr unsigned int DeletePRNGAlgorithmPointerMap = 0x10038390;
// R6GameService.dll code @ 100383b0
constexpr unsigned int DeleteCryptoAlgorithmPointerMap = 0x100383b0;
// R6GameService.dll code @ 100383d0
constexpr unsigned int DeletePKCAlgorithmPointerMap = 0x100383d0;
// R6GameService.dll code @ 100383f0
constexpr unsigned int DestroyHashAlgorithmPointerMap = 0x100383f0;
// R6GameService.dll code @ 100384b0
constexpr unsigned int DestroyHashMapTree = 0x100384b0;
// R6GameService.dll code @ 10038540
constexpr unsigned int EraseHashAlgorithmPointerMapRange = 0x10038540;
// R6GameService.dll code @ 10038680
constexpr unsigned int DispatchOwnedMapKeyErase = 0x10038680;
// R6GameService.dll code @ 100386d0
constexpr unsigned int DestroyPRNGAlgorithmPointerMap = 0x100386d0;
// R6GameService.dll code @ 10038790
constexpr unsigned int DestroyPRNGMapTree = 0x10038790;
// R6GameService.dll code @ 10038820
constexpr unsigned int ErasePRNGAlgorithmPointerMapRange = 0x10038820;
// R6GameService.dll code @ 10038960
constexpr unsigned int DestroyCryptoAlgorithmPointerMap = 0x10038960;
// R6GameService.dll code @ 10038a20
constexpr unsigned int DestroyCryptoMapTree = 0x10038a20;
// R6GameService.dll code @ 10038ab0
constexpr unsigned int EraseCryptoAlgorithmPointerMapRange = 0x10038ab0;
// R6GameService.dll code @ 10038bf0
constexpr unsigned int DestroyPKCAlgorithmPointerMap = 0x10038bf0;
// R6GameService.dll code @ 10038cb0
constexpr unsigned int DestroyPKCMapTree = 0x10038cb0;
// R6GameService.dll code @ 10038d40
constexpr unsigned int ErasePKCAlgorithmPointerMapRange = 0x10038d40;
// R6GameService.dll code @ 10038e80
constexpr unsigned int ReleaseHashMapTreeBranch = 0x10038e80;
// R6GameService.dll code @ 10038eb0
constexpr unsigned int ReleasePRNGMapTreeBranch = 0x10038eb0;
// R6GameService.dll code @ 10038ee0
constexpr unsigned int ReleaseCryptoMapTreeBranch = 0x10038ee0;
// R6GameService.dll code @ 10038f10
constexpr unsigned int ReleasePKCMapTreeBranch = 0x10038f10;
// R6GameService.dll code @ 10038f40
constexpr unsigned int ConstructCBlowFish = 0x10038f40;
// R6GameService.dll code @ 10038fb0
constexpr unsigned int DeleteCBlowFish = 0x10038fb0;
// R6GameService.dll code @ 10038fd0
constexpr unsigned int DestroyCBlowFish = 0x10038fd0;
// R6GameService.dll code @ 10039020
constexpr unsigned int ClearBlowfishWorkingTables = 0x10039020;
// R6GameService.dll code @ 10039040
constexpr unsigned int EvaluateBlowfishRound = 0x10039040;
// R6GameService.dll code @ 100390a0
constexpr unsigned int EncryptBlowfishWords = 0x100390a0;
// R6GameService.dll code @ 100390f0
constexpr unsigned int DecryptBlowfishWords = 0x100390f0;
// R6GameService.dll code @ 10039140
constexpr unsigned int ExpandBlowfishKey = 0x10039140;
// R6GameService.dll code @ 10039230
constexpr unsigned int EncodeMaskedSquareTransposition = 0x10039230;
// R6GameService.dll code @ 10039310
constexpr unsigned int DecodeMaskedSquareTransposition = 0x10039310;
// R6GameService.dll code @ 10039440
constexpr unsigned int XorBytesWithIndexMask = 0x10039440;
// R6GameService.dll code @ 10039470
constexpr unsigned int ConstructHashModuleSHA1 = 0x10039470;
// R6GameService.dll code @ 10039520
constexpr unsigned int DeleteHashModuleSHA1 = 0x10039520;
// R6GameService.dll code @ 10039540
constexpr unsigned int DestroyHashModuleSHA1 = 0x10039540;
// R6GameService.dll code @ 100395b0
constexpr unsigned int ResetHashModuleSHA1 = 0x100395b0;
// R6GameService.dll code @ 100395e0
constexpr unsigned int UpdateHashModuleSHA1 = 0x100395e0;
// R6GameService.dll code @ 10039610
constexpr unsigned int HashStreamIntoHashModuleSHA1 = 0x10039610;
// R6GameService.dll code @ 10039670
constexpr unsigned int FinalizeHashModuleSHA1 = 0x10039670;
// R6GameService.dll code @ 100396a0
constexpr unsigned int CopyHashModuleSHA1Digest = 0x100396a0;
// R6GameService.dll code @ 100396d0
constexpr unsigned int FormatHashModuleSHA1Digest = 0x100396d0;
// R6GameService.dll code @ 10039710
constexpr unsigned int GetHashModuleSHA1DigestLength = 0x10039710;
// R6GameService.dll code @ 10039720
constexpr unsigned int GetHashModuleSHA1HexLength = 0x10039720;
// R6GameService.dll code @ 10039730
constexpr unsigned int ConstructHashModuleMD5 = 0x10039730;
// R6GameService.dll code @ 100397c0
constexpr unsigned int GetHashModuleMD5DigestLength = 0x100397c0;
// R6GameService.dll code @ 100397d0
constexpr unsigned int GetHashModuleMD5HexLength = 0x100397d0;
// R6GameService.dll code @ 100397e0
constexpr unsigned int DeleteHashModuleMD5 = 0x100397e0;
// R6GameService.dll code @ 10039800
constexpr unsigned int DestroyHashModuleMD5 = 0x10039800;
// R6GameService.dll code @ 10039860
constexpr unsigned int ResetHashModuleMD5 = 0x10039860;
// R6GameService.dll code @ 10039890
constexpr unsigned int UpdateHashModuleMD5 = 0x10039890;
// R6GameService.dll code @ 100398c0
constexpr unsigned int HashStreamIntoHashModuleMD5 = 0x100398c0;
// R6GameService.dll code @ 10039920
constexpr unsigned int FinalizeHashModuleMD5 = 0x10039920;
// R6GameService.dll code @ 10039950
constexpr unsigned int CopyHashModuleMD5Digest = 0x10039950;
// R6GameService.dll code @ 10039980
constexpr unsigned int FormatHashModuleMD5Digest = 0x10039980;
// R6GameService.dll code @ 100399c0
constexpr unsigned int DeletePRNGModuleMGF1 = 0x100399c0;
// R6GameService.dll code @ 100399e0
constexpr unsigned int ConstructPRNGModuleMGF1 = 0x100399e0;
// R6GameService.dll code @ 10039ae0
constexpr unsigned int DestroyPRNGModuleMGF1 = 0x10039ae0;
// R6GameService.dll code @ 10039b60
constexpr unsigned int ReplaceMGF1Seed = 0x10039b60;
// R6GameService.dll code @ 10039bb0
constexpr unsigned int NextMGF1ParityBit = 0x10039bb0;
// R6GameService.dll code @ 10039bd0
constexpr unsigned int NextMGF1Byte = 0x10039bd0;
// R6GameService.dll code @ 10039c00
constexpr unsigned int ReadMGF1Bytes = 0x10039c00;
// R6GameService.dll code @ 10039c30
constexpr unsigned int SelectMGF1ValueInRange = 0x10039c30;
// R6GameService.dll code @ 10039d00
constexpr unsigned int RefillMGF1Output = 0x10039d00;
// R6GameService.dll code @ 10039e20
constexpr unsigned int ConstructPKCModuleRSA = 0x10039e20;
// R6GameService.dll code @ 10039eb0
constexpr unsigned int DeletePKCModuleRSA = 0x10039eb0;
// R6GameService.dll code @ 10039ed0
constexpr unsigned int DestroyPKCModuleRSA = 0x10039ed0;
// R6GameService.dll code @ 10039f30
constexpr unsigned int InitializePKCRSARandomState = 0x10039f30;
// R6GameService.dll code @ 10039f40
constexpr unsigned int UpdatePKCRSARandomSeed = 0x10039f40;
// R6GameService.dll code @ 10039f50
constexpr unsigned int ClearPKCRSARandomState = 0x10039f50;
// R6GameService.dll code @ 10039f60
constexpr unsigned int ReadPKCRSASeedBytesNeeded = 0x10039f60;
// R6GameService.dll code @ 10039f70
constexpr unsigned int GeneratePKCRSAKeyRecords = 0x10039f70;
// R6GameService.dll code @ 10039f80
constexpr unsigned int EncodePKCRSAType2Block = 0x10039f80;
// R6GameService.dll code @ 10039f90
constexpr unsigned int EncodePKCRSAType1Block = 0x10039f90;
// R6GameService.dll code @ 10039fa0
constexpr unsigned int DecodePKCRSAType1Block = 0x10039fa0;
// R6GameService.dll code @ 10039fb0
constexpr unsigned int DecodePKCRSAType2Block = 0x10039fb0;
// R6GameService.dll code @ 10039fc0
constexpr unsigned int ConstructSha1Context = 0x10039fc0;
// R6GameService.dll code @ 1003a030
constexpr unsigned int DeleteSha1Context = 0x1003a030;
// R6GameService.dll code @ 1003a050
constexpr unsigned int DestroySha1ContextBase = 0x1003a050;
// R6GameService.dll code @ 1003a070
constexpr unsigned int InitializeSha1State = 0x1003a070;
// R6GameService.dll code @ 1003a0b0
constexpr unsigned int UpdateSha1Context = 0x1003a0b0;
// R6GameService.dll code @ 1003a1c0
constexpr unsigned int FinalizeSha1Context = 0x1003a1c0;
// R6GameService.dll code @ 1003a270
constexpr unsigned int CompressSha1Block = 0x1003a270;
// R6GameService.dll code @ 1003bf80
constexpr unsigned int SwapSha1MessageWordsInPlace = 0x1003bf80;
// R6GameService.dll code @ 1003bfc0
constexpr unsigned int CopySha1DigestBytes = 0x1003bfc0;
// R6GameService.dll code @ 1003c010
constexpr unsigned int ConstructMd5Context = 0x1003c010;
// R6GameService.dll code @ 1003c080
constexpr unsigned int DeleteMd5Context = 0x1003c080;
// R6GameService.dll code @ 1003c0a0
constexpr unsigned int DestroyMD5 = 0x1003c0a0;
// R6GameService.dll code @ 1003c0d0
constexpr unsigned int ResetMd5Context = 0x1003c0d0;
// R6GameService.dll code @ 1003c120
constexpr unsigned int UpdateMD5 = 0x1003c120;
// R6GameService.dll code @ 1003c1f0
constexpr unsigned int FinalizeMD5 = 0x1003c1f0;
// R6GameService.dll code @ 1003c290
constexpr unsigned int CompressMD5Block = 0x1003c290;
// R6GameService.dll code @ 1003cc30
constexpr unsigned int CopyFourByteGroupsForward = 0x1003cc30;
// R6GameService.dll code @ 1003cc80
constexpr unsigned int DecodeLittleEndianWordGroups = 0x1003cc80;
// R6GameService.dll code @ 1003ccd0
constexpr unsigned int UpdateInvertedOrDigestWord = 0x1003ccd0;
// R6GameService.dll code @ 1003cd20
constexpr unsigned int ComputeUnsigned64Parity = 0x1003cd20;
// R6GameService.dll code @ 1003cd50
constexpr unsigned int CountUnsigned64Bytes = 0x1003cd50;
// R6GameService.dll code @ 1003cd90
constexpr unsigned int CountUnsigned64Bits = 0x1003cd90;
// R6GameService.dll code @ 1003cda5
constexpr unsigned int internal_block_in_CountUnsigned64Bits = 0x1003cda5;
// R6GameService.dll code @ 1003cde0
constexpr unsigned int MaskUnsigned64WithNativeShift = 0x1003cde0;
// R6GameService.dll code @ 1003ce10
constexpr unsigned int WriteUnsigned64BigEndian = 0x1003ce10;
// R6GameService.dll code @ 1003ce60
constexpr unsigned int ConstructRSA = 0x1003ce60;
// R6GameService.dll code @ 1003ce90
constexpr unsigned int DeleteExtallocBaseObject = 0x1003ce90;
// R6GameService.dll code @ 1003ceb0
constexpr unsigned int BuildCryptoKeyRecords = 0x1003ceb0;
// R6GameService.dll code @ 1003d260
constexpr unsigned int EncodeType2CryptoBlock = 0x1003d260;
// R6GameService.dll code @ 1003d360
constexpr unsigned int EncodeType1CryptoBlock = 0x1003d360;
// R6GameService.dll code @ 1003d450
constexpr unsigned int DecodeType1CryptoBlock = 0x1003d450;
// R6GameService.dll code @ 1003d530
constexpr unsigned int DecodeType2CryptoBlock = 0x1003d530;
// R6GameService.dll code @ 1003d600
constexpr unsigned int FillRandomLimbWords = 0x1003d600;
// R6GameService.dll code @ 1003d660
constexpr unsigned int GeneratePrimeCandidate = 0x1003d660;
// R6GameService.dll code @ 1003d840
constexpr unsigned int IsUsablePrimeCandidate = 0x1003d840;
// R6GameService.dll code @ 1003d8e0
constexpr unsigned int PassesPrimeCandidateFilters = 0x1003d8e0;
// R6GameService.dll code @ 1003d920
constexpr unsigned int HasSmallPrimeDivisor = 0x1003d920;
// R6GameService.dll code @ 1003d990
constexpr unsigned int PassesBaseTwoFermatTest = 0x1003d990;
// R6GameService.dll code @ 1003da00
constexpr unsigned int IsCoprimeWithExponent = 0x1003da00;
// R6GameService.dll code @ 1003daa0
constexpr unsigned int InitializeRSARandomState = 0x1003daa0;
// R6GameService.dll code @ 1003dad0
constexpr unsigned int ClearRSARandomState = 0x1003dad0;
// R6GameService.dll code @ 1003daf0
constexpr unsigned int GenerateCryptoRandomBytes = 0x1003daf0;
// R6GameService.dll code @ 1003dc30
constexpr unsigned int ForwardStackMD5ContextCleanup = 0x1003dc30;
// R6GameService.dll code @ 1003dc40
constexpr unsigned int ReadRSASeedBytesNeeded = 0x1003dc40;
// R6GameService.dll code @ 1003dc60
constexpr unsigned int UpdateCryptoRandomSeed = 0x1003dc60;
// R6GameService.dll code @ 1003dd50
constexpr unsigned int ApplyRsaPublicKeyTransform = 0x1003dd50;
// R6GameService.dll code @ 1003de60
constexpr unsigned int ApplyRsaPrivateKeyTransform = 0x1003de60;
// R6GameService.dll code @ 1003e140
constexpr unsigned int DecodeBigEndianLimbs = 0x1003e140;
// R6GameService.dll code @ 1003e1b0
constexpr unsigned int EncodeBigEndianLimbs = 0x1003e1b0;
// R6GameService.dll code @ 1003e210
constexpr unsigned int CopyLimbWords = 0x1003e210;
// R6GameService.dll code @ 1003e240
constexpr unsigned int ClearLimbWords = 0x1003e240;
// R6GameService.dll code @ 1003e260
constexpr unsigned int SetSingleLimbBit = 0x1003e260;
// R6GameService.dll code @ 1003e2a0
constexpr unsigned int AddLimbWords = 0x1003e2a0;
// R6GameService.dll code @ 1003e2f0
constexpr unsigned int SubtractLimbWords = 0x1003e2f0;
// R6GameService.dll code @ 1003e350
constexpr unsigned int MultiplyLimbArrays = 0x1003e350;
// R6GameService.dll code @ 1003e410
constexpr unsigned int ShiftLimbWordsLeft = 0x1003e410;
// R6GameService.dll code @ 1003e480
constexpr unsigned int ShiftLimbWordsRight = 0x1003e480;
// R6GameService.dll code @ 1003e4f0
constexpr unsigned int DivideLimbArrays = 0x1003e4f0;
// R6GameService.dll code @ 1003e690
constexpr unsigned int ReduceLimbWordsModulo = 0x1003e690;
// R6GameService.dll code @ 1003e6d0
constexpr unsigned int MultiplyLimbWordsModulo = 0x1003e6d0;
// R6GameService.dll code @ 1003e730
constexpr unsigned int ModularExponentiateLimbWords = 0x1003e730;
// R6GameService.dll code @ 1003e8b0
constexpr unsigned int ModularInverseLimbWords = 0x1003e8b0;
// R6GameService.dll code @ 1003ea60
constexpr unsigned int GreatestCommonDivisorLimbWords = 0x1003ea60;
// R6GameService.dll code @ 1003eb30
constexpr unsigned int CompareLimbWords = 0x1003eb30;
// R6GameService.dll code @ 1003eb80
constexpr unsigned int AreLimbWordsZero = 0x1003eb80;
// R6GameService.dll code @ 1003ebb0
constexpr unsigned int CountSignificantLimbs = 0x1003ebb0;
// R6GameService.dll code @ 1003ebd0
constexpr unsigned int MultiplyAddLimbWordsByWord = 0x1003ebd0;
// R6GameService.dll code @ 1003ec70
constexpr unsigned int MultiplySubtractLimbWordsByWord = 0x1003ec70;
// R6GameService.dll code @ 1003ed20
constexpr unsigned int BitLength = 0x1003ed20;
// R6GameService.dll code @ 1003ed40
constexpr unsigned int MultiplyWordsToDoubleWord = 0x1003ed40;
// R6GameService.dll code @ 1003edc0
constexpr unsigned int EstimateQuotientWordFromTwoWords = 0x1003edc0;
// R6GameService.dll code @ 1003ef00
constexpr unsigned int ConstructGLClient = 0x1003ef00;
// R6GameService.dll code @ 1003eff0
constexpr unsigned int DeleteGLClient = 0x1003eff0;
// R6GameService.dll code @ 1003f010
constexpr unsigned int DestroyGLClient = 0x1003f010;
// R6GameService.dll code @ 1003f060
constexpr unsigned int PollTransportAndDispatchQueuedRecords = 0x1003f060;
// R6GameService.dll code @ 1003f070
constexpr unsigned int OpenPrimaryConnectionThroughSubobject = 0x1003f070;
// R6GameService.dll code @ 1003f090
constexpr unsigned int DisconnectPrimaryConnectionViaOffset14 = 0x1003f090;
// R6GameService.dll code @ 1003f0a0
constexpr unsigned int SendStringTupleSelector66ViaOffset14 = 0x1003f0a0;
// R6GameService.dll code @ 1003f0b0
constexpr unsigned int SendStringSelector4dViaOffset14 = 0x1003f0b0;
// R6GameService.dll code @ 1003f0c0
constexpr unsigned int SendSelector5dViaOffset14 = 0x1003f0c0;
// R6GameService.dll code @ 1003f0d0
constexpr unsigned int SendSelector13StringViaOffset14 = 0x1003f0d0;
// R6GameService.dll code @ 1003f0e0
constexpr unsigned int PollAndDispatchCallbackQueueViaSubobject = 0x1003f0e0;
// R6GameService.dll code @ 1003f0f0
constexpr unsigned int SendSelector5cViaNestedOffsets = 0x1003f0f0;
// R6GameService.dll code @ 1003f100
constexpr unsigned int SendBytePairSelector4eViaOffset14 = 0x1003f100;
// R6GameService.dll code @ 1003f110
constexpr unsigned int ProcessPendingCallbackEventsThroughSubobject = 0x1003f110;
// R6GameService.dll code @ 1003f120
constexpr unsigned int PrepareAndSendTransportRequestThroughSubobject = 0x1003f120;
// R6GameService.dll code @ 1003f140
constexpr unsigned int ProcessTransportRecordsViaNestedOffsets = 0x1003f140;
// R6GameService.dll code @ 1003f150
constexpr unsigned int DispatchRequest18ByKeyThroughSubobject = 0x1003f150;
// R6GameService.dll code @ 1003f160
constexpr unsigned int ForwardTwoArgumentBooleanViaNestedOffsets = 0x1003f160;
// R6GameService.dll code @ 1003f170
constexpr unsigned int ForwardSelector9ThroughOptionalChannel = 0x1003f170;
// R6GameService.dll code @ 1003f180
constexpr unsigned int ForwardSelector2eThroughOptionalChannel = 0x1003f180;
// R6GameService.dll code @ 1003f190
constexpr unsigned int CreateServiceRecordListViaNestedOffsets = 0x1003f190;
// R6GameService.dll code @ 1003f1a0
constexpr unsigned int UpdateServiceRecordByKeyViaNestedOffsets = 0x1003f1a0;
// R6GameService.dll code @ 1003f1b0
constexpr unsigned int BuildAndDispatchStoredRequestViaNestedOffsets = 0x1003f1b0;
// R6GameService.dll code @ 1003f1c0
constexpr unsigned int DestroyServiceRecordListViaOffset14 = 0x1003f1c0;
// R6GameService.dll code @ 1003f1d0
constexpr unsigned int clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets = 0x1003f1d0;
// R6GameService.dll code @ 1003f1e0
constexpr unsigned int clGLClient_ForwardTwoArgumentBooleanViaNestedOffsets2 = 0x1003f1e0;
// R6GameService.dll code @ 1003f1f0
constexpr unsigned int ForwardSelector22ThroughOptionalChannel = 0x1003f1f0;
// R6GameService.dll code @ 1003f200
constexpr unsigned int ForwardSelector2aThroughOptionalChannel = 0x1003f200;
// R6GameService.dll code @ 1003f210
constexpr unsigned int ConstructServiceState = 0x1003f210;
// R6GameService.dll code @ 1003f490
constexpr unsigned int DestroyServiceQueueThunk = 0x1003f490;
// R6GameService.dll code @ 1003f4a0
constexpr unsigned int DestroyServiceState = 0x1003f4a0;
// R6GameService.dll code @ 1003f5e0
constexpr unsigned int QueueMarkedClDataRecord = 0x1003f5e0;
// R6GameService.dll code @ 1003f810
constexpr unsigned int BuildServiceRecord66 = 0x1003f810;
// R6GameService.dll code @ 1003fa30
constexpr unsigned int BuildServiceRecord5D = 0x1003fa30;
// R6GameService.dll code @ 1003fc50
constexpr unsigned int BuildServiceRecord4D = 0x1003fc50;
// R6GameService.dll code @ 1003fe70
constexpr unsigned int ForwardOptionalServiceQueueItem = 0x1003fe70;
// R6GameService.dll code @ 1003fe90
constexpr unsigned int ExtractRecordDispatchCode = 0x1003fe90;
// R6GameService.dll code @ 1003ffd0
constexpr unsigned int MaintainTransportState = 0x1003ffd0;
// R6GameService.dll code @ 10040070
constexpr unsigned int DrainSelectedRecordSource = 0x10040070;
// R6GameService.dll code @ 10040180
constexpr unsigned int RouteTransportRecord = 0x10040180;
// R6GameService.dll interior-code @ 100401de
constexpr unsigned int GTransportRouteTargetsCase1 = 0x100401de;
// R6GameService.dll interior-code @ 100401f0
constexpr unsigned int GTransportRouteTargetsCase2 = 0x100401f0;
// R6GameService.dll interior-code @ 10040202
constexpr unsigned int GTransportRouteTargetsCase4 = 0x10040202;
// R6GameService.dll interior-code @ 10040293
constexpr unsigned int GTransportRouteTargetsCase3 = 0x10040293;
// R6GameService.dll interior-code @ 1004031e
constexpr unsigned int service_state_supportBranch73 = 0x1004031e;
// R6GameService.dll data @ 10040334
constexpr unsigned int GTransportRouteTargets = 0x10040334;
// R6GameService.dll data @ 10040348
constexpr unsigned int GTransportRouteIndices = 0x10040348;
// R6GameService.dll code @ 10040430
constexpr unsigned int QueueAndCheckStateRecord = 0x10040430;
// R6GameService.dll code @ 10040470
constexpr unsigned int ParseAndQueueRecord = 0x10040470;
// R6GameService.dll code @ 100404a0
constexpr unsigned int SetPrimaryCallbackPointer = 0x100404a0;
// R6GameService.dll code @ 100404c0
constexpr unsigned int PollAndDispatchQueuedRecords = 0x100404c0;
// R6GameService.dll interior-code @ 1004052b
constexpr unsigned int GTransportDispatchTargetsCase2 = 0x1004052b;
// R6GameService.dll interior-code @ 10040538
constexpr unsigned int GTransportDispatchTargetsCase4 = 0x10040538;
// R6GameService.dll interior-code @ 10040545
constexpr unsigned int GTransportDispatchTargetsCase6 = 0x10040545;
// R6GameService.dll interior-code @ 10040552
constexpr unsigned int GTransportDispatchTargetsCase3 = 0x10040552;
// R6GameService.dll interior-code @ 1004055f
constexpr unsigned int GTransportDispatchTargetsCase7 = 0x1004055f;
// R6GameService.dll interior-code @ 1004056c
constexpr unsigned int GTransportDispatchTargetsCase1 = 0x1004056c;
// R6GameService.dll interior-code @ 10040579
constexpr unsigned int GTransportDispatchTargetsCase5 = 0x10040579;
// R6GameService.dll interior-code @ 10040584
constexpr unsigned int GTransportDispatchTargetsCase8 = 0x10040584;
// R6GameService.dll interior-code @ 1004058f
constexpr unsigned int service_state_supportBranch80 = 0x1004058f;
// R6GameService.dll data @ 100405d8
constexpr unsigned int GTransportDispatchTargets = 0x100405d8;
// R6GameService.dll data @ 100405fc
constexpr unsigned int GTransportDispatchIndices = 0x100405fc;
// R6GameService.dll code @ 100406e0
constexpr unsigned int OpenPrimaryConnection = 0x100406e0;
// R6GameService.dll code @ 100407e0
constexpr unsigned int DisconnectPrimaryConnectionIfActive = 0x100407e0;
// R6GameService.dll code @ 10040800
constexpr unsigned int SendStringTupleSelector66 = 0x10040800;
// R6GameService.dll code @ 10040860
constexpr unsigned int SendStringSelector4d = 0x10040860;
// R6GameService.dll code @ 10040890
constexpr unsigned int ForwardSelector5dToTransportSubobject = 0x10040890;
// R6GameService.dll code @ 100408a0
constexpr unsigned int ForwardSelector13ToTransportSubobject = 0x100408a0;
// R6GameService.dll code @ 100408b0
constexpr unsigned int SetSecondaryCallbackPointer = 0x100408b0;
// R6GameService.dll code @ 100408d0
constexpr unsigned int PollAndDispatchCallbackQueue = 0x100408d0;
// R6GameService.dll interior-code @ 1004093c
constexpr unsigned int GSecondaryDispatchTargetsCase5 = 0x1004093c;
// R6GameService.dll interior-code @ 1004094c
constexpr unsigned int GSecondaryDispatchTargetsCase3 = 0x1004094c;
// R6GameService.dll interior-code @ 1004095c
constexpr unsigned int GSecondaryDispatchTargetsCase4 = 0x1004095c;
// R6GameService.dll interior-code @ 1004096c
constexpr unsigned int GSecondaryDispatchTargetsCase6 = 0x1004096c;
// R6GameService.dll interior-code @ 1004097c
constexpr unsigned int GSecondaryDispatchTargetsCase7 = 0x1004097c;
// R6GameService.dll interior-code @ 1004098c
constexpr unsigned int GSecondaryDispatchTargetsCase9 = 0x1004098c;
// R6GameService.dll interior-code @ 1004099c
constexpr unsigned int GSecondaryDispatchTargetsCase10 = 0x1004099c;
// R6GameService.dll interior-code @ 100409ac
constexpr unsigned int GSecondaryDispatchTargetsCase14 = 0x100409ac;
// R6GameService.dll interior-code @ 100409bc
constexpr unsigned int GSecondaryDispatchTargetsCase11 = 0x100409bc;
// R6GameService.dll interior-code @ 100409c9
constexpr unsigned int GSecondaryDispatchTargetsCase12 = 0x100409c9;
// R6GameService.dll interior-code @ 100409d6
constexpr unsigned int GSecondaryDispatchTargetsCase13 = 0x100409d6;
// R6GameService.dll interior-code @ 100409e3
constexpr unsigned int GSecondaryDispatchTargetsCase15 = 0x100409e3;
// R6GameService.dll interior-code @ 100409f0
constexpr unsigned int GSecondaryDispatchTargetsCase8 = 0x100409f0;
// R6GameService.dll interior-code @ 100409fd
constexpr unsigned int GSecondaryDispatchTargetsCase2 = 0x100409fd;
// R6GameService.dll interior-code @ 10040a0a
constexpr unsigned int GSecondaryDispatchTargetsCase1 = 0x10040a0a;
// R6GameService.dll interior-code @ 10040a17
constexpr unsigned int GSecondaryDispatchTargetsCase16 = 0x10040a17;
// R6GameService.dll interior-code @ 10040a24
constexpr unsigned int service_state_supportBranch85 = 0x10040a24;
// R6GameService.dll data @ 10040a68
constexpr unsigned int GSecondaryDispatchTargets = 0x10040a68;
// R6GameService.dll data @ 10040aac
constexpr unsigned int GSecondaryDispatchIndices = 0x10040aac;
// R6GameService.dll code @ 10040b40
constexpr unsigned int SendWordPairSelector4e = 0x10040b40;
// R6GameService.dll code @ 10040ba0
constexpr unsigned int SendSelector5cViaOffset154 = 0x10040ba0;
// R6GameService.dll code @ 10040bb0
constexpr unsigned int SetTertiaryCallbackPointer = 0x10040bb0;
// R6GameService.dll code @ 10040bd0
constexpr unsigned int ProcessPendingCallbackEvents = 0x10040bd0;
// R6GameService.dll interior-code @ 10040c41
constexpr unsigned int GCallbackProcessorTargetsCase10 = 0x10040c41;
// R6GameService.dll interior-code @ 10040c51
constexpr unsigned int GCallbackProcessorTargetsCase9 = 0x10040c51;
// R6GameService.dll interior-code @ 10040c61
constexpr unsigned int GCallbackProcessorTargetsCase22 = 0x10040c61;
// R6GameService.dll interior-code @ 10040c94
constexpr unsigned int GCallbackProcessorTargetsCase11 = 0x10040c94;
// R6GameService.dll interior-code @ 10040ca4
constexpr unsigned int GCallbackProcessorTargetsCase12 = 0x10040ca4;
// R6GameService.dll interior-code @ 10040cb4
constexpr unsigned int GCallbackProcessorTargetsCase5 = 0x10040cb4;
// R6GameService.dll interior-code @ 10040cc4
constexpr unsigned int GCallbackProcessorTargetsCase28 = 0x10040cc4;
// R6GameService.dll interior-code @ 10040cd4
constexpr unsigned int GCallbackProcessorTargetsCase29 = 0x10040cd4;
// R6GameService.dll interior-code @ 10040ce4
constexpr unsigned int GCallbackProcessorTargetsCase27 = 0x10040ce4;
// R6GameService.dll interior-code @ 10040cf4
constexpr unsigned int GCallbackProcessorTargetsCase3 = 0x10040cf4;
// R6GameService.dll interior-code @ 10040d04
constexpr unsigned int GCallbackProcessorTargetsCase25 = 0x10040d04;
// R6GameService.dll interior-code @ 10040d14
constexpr unsigned int GCallbackProcessorTargetsCase26 = 0x10040d14;
// R6GameService.dll interior-code @ 10040d24
constexpr unsigned int GCallbackProcessorTargetsCase8 = 0x10040d24;
// R6GameService.dll interior-code @ 10040d34
constexpr unsigned int GCallbackProcessorTargetsCase13 = 0x10040d34;
// R6GameService.dll interior-code @ 10040d44
constexpr unsigned int GCallbackProcessorTargetsCase32 = 0x10040d44;
// R6GameService.dll interior-code @ 10040d54
constexpr unsigned int GCallbackProcessorTargetsCase23 = 0x10040d54;
// R6GameService.dll interior-code @ 10040d64
constexpr unsigned int GCallbackProcessorTargetsCase4 = 0x10040d64;
// R6GameService.dll interior-code @ 10040d74
constexpr unsigned int GCallbackProcessorTargetsCase33 = 0x10040d74;
// R6GameService.dll interior-code @ 10040d84
constexpr unsigned int GCallbackProcessorTargetsCase6 = 0x10040d84;
// R6GameService.dll interior-code @ 10040d94
constexpr unsigned int GCallbackProcessorTargetsCase24 = 0x10040d94;
// R6GameService.dll interior-code @ 10040da4
constexpr unsigned int GCallbackProcessorTargetsCase2 = 0x10040da4;
// R6GameService.dll interior-code @ 10040db4
constexpr unsigned int GCallbackProcessorTargetsCase31 = 0x10040db4;
// R6GameService.dll interior-code @ 10040dc4
constexpr unsigned int GCallbackProcessorTargetsCase34 = 0x10040dc4;
// R6GameService.dll interior-code @ 10040dd4
constexpr unsigned int GCallbackProcessorTargetsCase14 = 0x10040dd4;
// R6GameService.dll interior-code @ 10040de4
constexpr unsigned int GCallbackProcessorTargetsCase15 = 0x10040de4;
// R6GameService.dll interior-code @ 10040df4
constexpr unsigned int GCallbackProcessorTargetsCase16 = 0x10040df4;
// R6GameService.dll interior-code @ 10040e04
constexpr unsigned int GCallbackProcessorTargetsCase17 = 0x10040e04;
// R6GameService.dll interior-code @ 10040e14
constexpr unsigned int GCallbackProcessorTargetsCase30 = 0x10040e14;
// R6GameService.dll interior-code @ 10040e24
constexpr unsigned int GCallbackProcessorTargetsCase7 = 0x10040e24;
// R6GameService.dll interior-code @ 10040e34
constexpr unsigned int GCallbackProcessorTargetsCase42 = 0x10040e34;
// R6GameService.dll interior-code @ 10040e44
constexpr unsigned int GCallbackProcessorTargetsCase20 = 0x10040e44;
// R6GameService.dll interior-code @ 10040e54
constexpr unsigned int GCallbackProcessorTargetsCase18 = 0x10040e54;
// R6GameService.dll interior-code @ 10040e64
constexpr unsigned int GCallbackProcessorTargetsCase19 = 0x10040e64;
// R6GameService.dll interior-code @ 10040e74
constexpr unsigned int GCallbackProcessorTargetsCase36 = 0x10040e74;
// R6GameService.dll interior-code @ 10040e84
constexpr unsigned int GCallbackProcessorTargetsCase35 = 0x10040e84;
// R6GameService.dll interior-code @ 10040e91
constexpr unsigned int GCallbackProcessorTargetsCase37 = 0x10040e91;
// R6GameService.dll interior-code @ 10040e9e
constexpr unsigned int GCallbackProcessorTargetsCase1 = 0x10040e9e;
// R6GameService.dll interior-code @ 10040eab
constexpr unsigned int GCallbackProcessorTargetsCase21 = 0x10040eab;
// R6GameService.dll interior-code @ 10040eb8
constexpr unsigned int GCallbackProcessorTargetsCase38 = 0x10040eb8;
// R6GameService.dll interior-code @ 10040ec5
constexpr unsigned int GCallbackProcessorTargetsCase41 = 0x10040ec5;
// R6GameService.dll interior-code @ 10040ed2
constexpr unsigned int GCallbackProcessorTargetsCase39 = 0x10040ed2;
// R6GameService.dll interior-code @ 10040edf
constexpr unsigned int GCallbackProcessorTargetsCase40 = 0x10040edf;
// R6GameService.dll interior-code @ 10040eec
constexpr unsigned int service_state_supportBranch90 = 0x10040eec;
// R6GameService.dll data @ 10040f30
constexpr unsigned int GCallbackProcessorTargets = 0x10040f30;
// R6GameService.dll data @ 10040fdc
constexpr unsigned int GCallbackProcessorIndices = 0x10040fdc;
// R6GameService.dll code @ 10041070
constexpr unsigned int PrepareAndSendTransportRequest = 0x10041070;
// R6GameService.dll code @ 10041100
constexpr unsigned int ProcessTransportRecordsViaOffset158 = 0x10041100;
// R6GameService.dll code @ 10041110
constexpr unsigned int DispatchRequest18ByKey = 0x10041110;
// R6GameService.dll code @ 10041130
constexpr unsigned int ForwardRequest8ViaOffset158 = 0x10041130;
// R6GameService.dll code @ 10041140
constexpr unsigned int ForwardRequest2cViaOffset158 = 0x10041140;
// R6GameService.dll code @ 10041150
constexpr unsigned int ForwardRequest46ViaOffset158 = 0x10041150;
// R6GameService.dll code @ 10041160
constexpr unsigned int CreateServiceRecordList = 0x10041160;
// R6GameService.dll code @ 10041200
constexpr unsigned int UpdateServiceRecordByKey = 0x10041200;
// R6GameService.dll code @ 10041230
constexpr unsigned int BuildAndDispatchStoredRecordRequest = 0x10041230;
// R6GameService.dll code @ 100412e0
constexpr unsigned int DestroyServiceRecordList = 0x100412e0;
// R6GameService.dll code @ 10041370
constexpr unsigned int DispatchSelector22ThroughOptionalChannel = 0x10041370;
// R6GameService.dll code @ 10041380
constexpr unsigned int DispatchSelector9ThroughOptionalChannel = 0x10041380;
// R6GameService.dll code @ 10041390
constexpr unsigned int DispatchSelector2eThroughOptionalChannel = 0x10041390;
// R6GameService.dll code @ 100413a0
constexpr unsigned int DispatchSelector2aThroughOptionalChannel = 0x100413a0;
// R6GameService.dll code @ 100413b0
constexpr unsigned int InstallCallbackPointerAndReturnTrue = 0x100413b0;
// R6GameService.dll code @ 100413d0
constexpr unsigned int InstallSecondCallbackPointer = 0x100413d0;
// R6GameService.dll code @ 100413e0
constexpr unsigned int DeleteOptionalChannelTree = 0x100413e0;
// R6GameService.dll code @ 10041400
constexpr unsigned int DestroyServiceRecordTree = 0x10041400;
// R6GameService.dll code @ 100414a0
constexpr unsigned int DestroyServiceTreeStorageDeletingDestructor = 0x100414a0;
// R6GameService.dll code @ 100414c0
constexpr unsigned int SetServiceTreeStorageVtable = 0x100414c0;
// R6GameService.dll code @ 100414d0
constexpr unsigned int DeleteServiceTreeStorageInline = 0x100414d0;
// R6GameService.dll code @ 100414f0
constexpr unsigned int ReleaseServiceTreeRecord = 0x100414f0;
// R6GameService.dll code @ 10041530
constexpr unsigned int ReleaseFirstWordBuffer = 0x10041530;
// R6GameService.dll code @ 10041540
constexpr unsigned int ReleaseServiceTreeSubtree = 0x10041540;
// R6GameService.dll code @ 10041580
constexpr unsigned int DestroyServiceTreeRecordDeletingDestructor = 0x10041580;
// R6GameService.dll code @ 100415a0
constexpr unsigned int DestroyServiceTreeRecord = 0x100415a0;
// R6GameService.dll code @ 10041610
constexpr unsigned int DestroyServiceLinkedRecordContainerDeletingDestructor = 0x10041610;
// R6GameService.dll code @ 10041630
constexpr unsigned int DestroyServiceLinkedRecordContainer = 0x10041630;
// R6GameService.dll code @ 100416c0
constexpr unsigned int ReleaseNestedServiceLinkedEntries = 0x100416c0;
// R6GameService.dll code @ 10041710
constexpr unsigned int ReleaseLinkedNodes = 0x10041710;
// R6GameService.dll code @ 10041740
constexpr unsigned int InitializeServiceRecordCollections = 0x10041740;
// R6GameService.dll code @ 10041910
constexpr unsigned int thunk_DestroyServiceTreeContainer = 0x10041910;
// R6GameService.dll code @ 10041920
constexpr unsigned int thunk_DestroyServiceTreeContainerVariant = 0x10041920;
// R6GameService.dll code @ 10041930
constexpr unsigned int ForwardServiceTreeContainerCleanup = 0x10041930;
// R6GameService.dll code @ 10041940
constexpr unsigned int ForwardServicePayloadCircularListCleanup = 0x10041940;
// R6GameService.dll code @ 10041950
constexpr unsigned int ForwardServicePayloadTreeCleanup = 0x10041950;
// R6GameService.dll code @ 10041960
constexpr unsigned int DeleteLadderResultPointerMap = 0x10041960;
// R6GameService.dll code @ 10041980
constexpr unsigned int DeleteDataListPointerMap = 0x10041980;
// R6GameService.dll code @ 100419a0
constexpr unsigned int DestroyServiceTreeContainer = 0x100419a0;
// R6GameService.dll code @ 10041a30
constexpr unsigned int DestroyServicePayloadCircularList = 0x10041a30;
// R6GameService.dll code @ 10041aa0
constexpr unsigned int DestroyServicePayloadTreeContainer = 0x10041aa0;
// R6GameService.dll code @ 10041b30
constexpr unsigned int DestroyServiceSubobject = 0x10041b30;
// R6GameService.dll code @ 10041ce0
constexpr unsigned int DestroyServiceSubtreeContainer = 0x10041ce0;
// R6GameService.dll code @ 10041d70
constexpr unsigned int ReplaceServiceRecordBySelector = 0x10041d70;
// R6GameService.dll code @ 10041db0
constexpr unsigned int TryReadServiceRecordTagAndValue = 0x10041db0;
// R6GameService.dll code @ 10041fe0
constexpr unsigned int PopPendingServiceRecord = 0x10041fe0;
// R6GameService.dll code @ 10041ff0
constexpr unsigned int ApplySelectorOneServiceResponse = 0x10041ff0;
// R6GameService.dll code @ 10042430
constexpr unsigned int ApplySelectorTwoServiceResponse = 0x10042430;
// R6GameService.dll code @ 100426e0
constexpr unsigned int clPointerMap_DestroyServiceTreeContainer = 0x100426e0;
// R6GameService.dll code @ 100427a0
constexpr unsigned int EraseOrderedTreeRangeAndDetachValues = 0x100427a0;
// R6GameService.dll code @ 100428e0
constexpr unsigned int ClearOrderedTreeStorage = 0x100428e0;
// R6GameService.dll code @ 10042970
constexpr unsigned int DestroyServiceTreeContainerVariant = 0x10042970;
// R6GameService.dll code @ 10042a30
constexpr unsigned int EraseAlternateOrderedTreeRangeAndDetachValues = 0x10042a30;
// R6GameService.dll code @ 10042b70
constexpr unsigned int thunk_ReleasePayloadReferenceAt4 = 0x10042b70;
// R6GameService.dll code @ 10042b80
constexpr unsigned int ReleasePayloadReferenceAt4 = 0x10042b80;
// R6GameService.dll code @ 10042c00
constexpr unsigned int InitializeTreeSentinel24 = 0x10042c00;
// R6GameService.dll code @ 10042c40
constexpr unsigned int ClearTreeNodes = 0x10042c40;
// R6GameService.dll code @ 10042c90
constexpr unsigned int ClearTreePayloadNodes = 0x10042c90;
// R6GameService.dll code @ 10042cf0
constexpr unsigned int InitializeCircularList36 = 0x10042cf0;
// R6GameService.dll code @ 10042d20
constexpr unsigned int ordered_tree_support_ReleaseTreeNodes = 0x10042d20;
// R6GameService.dll code @ 10042d50
constexpr unsigned int ordered_tree_support_ReleaseTreeNodes2 = 0x10042d50;
// R6GameService.dll code @ 10042d80
constexpr unsigned int ordered_tree_support_ReleaseTreeNodes3 = 0x10042d80;
// R6GameService.dll code @ 10042db0
constexpr unsigned int ClearPayloadList = 0x10042db0;
// R6GameService.dll code @ 10042de0
constexpr unsigned int ReleaseTreePayloadNodes = 0x10042de0;
// R6GameService.dll code @ 10042e20
constexpr unsigned int DeletePayloadReferenceAt16 = 0x10042e20;
// R6GameService.dll code @ 10042e40
constexpr unsigned int ReleasePayloadReferenceAt16 = 0x10042e40;
// R6GameService.dll code @ 10042e90
constexpr unsigned int ReleasePayloadReferenceAt12 = 0x10042e90;
// R6GameService.dll code @ 10042ee0
constexpr unsigned int ConstructServiceProtocolDispatcher = 0x10042ee0;
// R6GameService.dll code @ 10043010
constexpr unsigned int ClearProtocolDispatcherTreeThunk = 0x10043010;
// R6GameService.dll code @ 10043020
constexpr unsigned int ClearProtocolDispatcherTree = 0x10043020;
// R6GameService.dll code @ 100430b0
constexpr unsigned int DestroyServiceProtocolDispatcher = 0x100430b0;
// R6GameService.dll code @ 100431a0
constexpr unsigned int ServicePendingRecordsForDispatcher = 0x100431a0;
// R6GameService.dll code @ 100431c0
constexpr unsigned int BuildNextDispatcherRecord = 0x100431c0;
// R6GameService.dll code @ 100431d0
constexpr unsigned int ReplaceCachedRecordBySelector = 0x100431d0;
// R6GameService.dll code @ 10043210
constexpr unsigned int CheckD1DescriptorAndOptionalIndex = 0x10043210;
// R6GameService.dll code @ 10043440
constexpr unsigned int TryReadType35DescriptorFields = 0x10043440;
// R6GameService.dll code @ 10043620
constexpr unsigned int ReadType36DescriptorShort = 0x10043620;
// R6GameService.dll code @ 100437c0
constexpr unsigned int CopyIndexedClDataBinaryAndGetLength = 0x100437c0;
// R6GameService.dll code @ 100438a0
constexpr unsigned int TryGetType38IndexedBinaryLength = 0x100438a0;
// R6GameService.dll code @ 10043ab0
constexpr unsigned int TryCopyTwentyIndexedClDataFields = 0x10043ab0;
// R6GameService.dll code @ 10043c90
constexpr unsigned int TryCopyFourteenIndexedClDataFields = 0x10043c90;
// R6GameService.dll code @ 10043de0
constexpr unsigned int InitializeTransportRecordIfAbsent = 0x10043de0;
// R6GameService.dll code @ 10043ee0
constexpr unsigned int ResetTransportRecordState = 0x10043ee0;
// R6GameService.dll code @ 10043f10
constexpr unsigned int HandleSelector13RecordRemoval = 0x10043f10;
// R6GameService.dll code @ 10044080
constexpr unsigned int SendTransportRequestPayload = 0x10044080;
// R6GameService.dll code @ 10044220
constexpr unsigned int ProcessTransportRecordsIfPresent = 0x10044220;
// R6GameService.dll code @ 10044240
constexpr unsigned int transport_record_support_DispatchRequest18ByKey = 0x10044240;
// R6GameService.dll code @ 100443d0
constexpr unsigned int SendSerializedRequest8 = 0x100443d0;
// R6GameService.dll code @ 10044520
constexpr unsigned int SendSerializedRequest2c = 0x10044520;
// R6GameService.dll code @ 10044660
constexpr unsigned int SendSerializedRequest46 = 0x10044660;
// R6GameService.dll code @ 100447a0
constexpr unsigned int DispatchRequest1e = 0x100447a0;
// R6GameService.dll code @ 100447f0
constexpr unsigned int SendSerializedRequest22 = 0x100447f0;
// R6GameService.dll code @ 10044940
constexpr unsigned int SendSerializedRequest9 = 0x10044940;
// R6GameService.dll code @ 10044a80
constexpr unsigned int SendSerializedRequest2e = 0x10044a80;
// R6GameService.dll code @ 10044bc0
constexpr unsigned int SendBinaryRequest2a = 0x10044bc0;
// R6GameService.dll code @ 10044d50
constexpr unsigned int RefreshState15AndRead = 0x10044d50;
// R6GameService.dll code @ 10044d80
constexpr unsigned int ReadState12Word = 0x10044d80;
// R6GameService.dll code @ 10044db0
constexpr unsigned int SubmitBasicServiceRequest = 0x10044db0;
// R6GameService.dll code @ 10044e40
constexpr unsigned int SubmitExtendedServiceRequest = 0x10044e40;
// R6GameService.dll code @ 10044ef0
constexpr unsigned int ReadServiceState9 = 0x10044ef0;
// R6GameService.dll code @ 100450c0
constexpr unsigned int DecodeIndexedField17 = 0x100450c0;
// R6GameService.dll code @ 100452f0
constexpr unsigned int DecodeIndexedField18 = 0x100452f0;
// R6GameService.dll code @ 10045520
constexpr unsigned int ProcessKeyRecordToken = 0x10045520;
// R6GameService.dll code @ 10045720
constexpr unsigned int ProcessIndexedTextUpdate = 0x10045720;
// R6GameService.dll code @ 10045910
constexpr unsigned int RemoveDecodedKeyRecord = 0x10045910;
// R6GameService.dll code @ 10045ad0
constexpr unsigned int ParseCachedSelector0cRecord = 0x10045ad0;
// R6GameService.dll code @ 10045ca0
constexpr unsigned int ParseCachedSelector11Record = 0x10045ca0;
// R6GameService.dll code @ 10045ec0
constexpr unsigned int ParseCachedSelector3bRecord = 0x10045ec0;
// R6GameService.dll code @ 10046090
constexpr unsigned int ParseSelector1bIndexedStringAndFields = 0x10046090;
// R6GameService.dll code @ 10046290
constexpr unsigned int ParseSelector0aIndexedFieldsAndString = 0x10046290;
// R6GameService.dll code @ 10046490
constexpr unsigned int ParseSelector3dIndexedFieldAndBuffer = 0x10046490;
// R6GameService.dll code @ 10046640
constexpr unsigned int ParseSelector39IndexedFields = 0x10046640;
// R6GameService.dll code @ 100467f0
constexpr unsigned int ParseSelector0eMarkerAndFields = 0x100467f0;
// R6GameService.dll code @ 100469a0
constexpr unsigned int ParseSelector08MarkerAndField = 0x100469a0;
// R6GameService.dll code @ 10046bc0
constexpr unsigned int ParseSelector3eIndexedFieldPair = 0x10046bc0;
// R6GameService.dll code @ 10046d70
constexpr unsigned int ParseSelector1fMarkerAndField = 0x10046d70;
// R6GameService.dll code @ 10046f90
constexpr unsigned int ParseSelector1eMarkerAndField = 0x10046f90;
// R6GameService.dll code @ 10047170
constexpr unsigned int DispatchSelector20Entries = 0x10047170;
// R6GameService.dll code @ 100473e0
constexpr unsigned int ParseSelector0fMarkerAndField = 0x100473e0;
// R6GameService.dll code @ 10047600
constexpr unsigned int ParseSelector21MarkerAndField = 0x10047600;
// R6GameService.dll code @ 10047820
constexpr unsigned int ExtractCachedBinaryRecordFields = 0x10047820;
// R6GameService.dll code @ 10047a90
constexpr unsigned int ParseSelector29MarkerAndField = 0x10047a90;
// R6GameService.dll code @ 10047cb0
constexpr unsigned int ParseSelector24MarkerValueAndString = 0x10047cb0;
// R6GameService.dll code @ 10047e90
constexpr unsigned int ParseSelector28MarkerValueAndString = 0x10047e90;
// R6GameService.dll code @ 10048070
constexpr unsigned int ParseSelector3fValueAndText = 0x10048070;
// R6GameService.dll code @ 10048260
constexpr unsigned int ParseSelector41IndexedValue = 0x10048260;
// R6GameService.dll code @ 10048420
constexpr unsigned int ReadRefreshedSelector6 = 0x10048420;
// R6GameService.dll code @ 10048450
constexpr unsigned int ReadRefreshedSelector2A = 0x10048450;
// R6GameService.dll code @ 10048490
constexpr unsigned int ReplaceServiceCallback = 0x10048490;
// R6GameService.dll code @ 100484d0
constexpr unsigned int InvokeState15Callback = 0x100484d0;
// R6GameService.dll code @ 10048510
constexpr unsigned int RecomputeServiceCallbackState = 0x10048510;
// R6GameService.dll code @ 10048550
constexpr unsigned int DeliverSelector12 = 0x10048550;
// R6GameService.dll code @ 10048580
constexpr unsigned int RefreshEnabledServiceCallback = 0x10048580;
// R6GameService.dll code @ 100485b0
constexpr unsigned int DispatchSelector36Record = 0x100485b0;
// R6GameService.dll code @ 10048970
constexpr unsigned int DispatchSelector35Subrecords = 0x10048970;
// R6GameService.dll code @ 10049480
constexpr unsigned int DeliverServiceState9 = 0x10049480;
// R6GameService.dll code @ 100494d0
constexpr unsigned int DeliverSelector0C = 0x100494d0;
// R6GameService.dll code @ 10049530
constexpr unsigned int DeliverSelector18 = 0x10049530;
// R6GameService.dll code @ 100495b0
constexpr unsigned int DeliverSelector17 = 0x100495b0;
// R6GameService.dll code @ 10049630
constexpr unsigned int DispatchSelector32Record = 0x10049630;
// R6GameService.dll code @ 100498b0
constexpr unsigned int DispatchSelector33IndexedValues = 0x100498b0;
// R6GameService.dll code @ 10049ac0
constexpr unsigned int DeliverSelector37 = 0x10049ac0;
// R6GameService.dll code @ 10049b00
constexpr unsigned int DispatchParsedCallback38 = 0x10049b00;
// R6GameService.dll code @ 10049b50
constexpr unsigned int DispatchParsedCallback3c = 0x10049b50;
// R6GameService.dll code @ 10049bb0
constexpr unsigned int DispatchParsedCallback40 = 0x10049bb0;
// R6GameService.dll code @ 10049c40
constexpr unsigned int DeliverSelector2D = 0x10049c40;
// R6GameService.dll code @ 10049d20
constexpr unsigned int DeliverSelector45 = 0x10049d20;
// R6GameService.dll code @ 10049db0
constexpr unsigned int DeliverSelector0A = 0x10049db0;
// R6GameService.dll code @ 10049e10
constexpr unsigned int DeliverSelector3D = 0x10049e10;
// R6GameService.dll code @ 10049e60
constexpr unsigned int DeliverSelector0E = 0x10049e60;
// R6GameService.dll code @ 10049ec0
constexpr unsigned int DispatchSelector2eRecord = 0x10049ec0;
// R6GameService.dll code @ 1004a030
constexpr unsigned int DeliverSelector08 = 0x1004a030;
// R6GameService.dll code @ 1004a080
constexpr unsigned int DeliverSelector39 = 0x1004a080;
// R6GameService.dll code @ 1004a0d0
constexpr unsigned int DeliverSelector3E = 0x1004a0d0;
// R6GameService.dll code @ 1004a120
constexpr unsigned int DeliverSelector1F = 0x1004a120;
// R6GameService.dll code @ 1004a170
constexpr unsigned int DeliverSelector1E = 0x1004a170;
// R6GameService.dll code @ 1004a1c0
constexpr unsigned int thunk_DispatchSelector20Entries = 0x1004a1c0;
// R6GameService.dll code @ 1004a1d0
constexpr unsigned int DeliverSelector0F = 0x1004a1d0;
// R6GameService.dll code @ 1004a220
constexpr unsigned int DeliverSelector21 = 0x1004a220;
// R6GameService.dll code @ 1004a270
constexpr unsigned int DispatchSelector38BinaryRecord = 0x1004a270;
// R6GameService.dll code @ 1004a340
constexpr unsigned int DispatchSelector97StringFlagRecords = 0x1004a340;
// R6GameService.dll code @ 1004a5c0
constexpr unsigned int DispatchParsedCallback80 = 0x1004a5c0;
// R6GameService.dll code @ 1004a620
constexpr unsigned int DispatchParsedCallback84 = 0x1004a620;
// R6GameService.dll code @ 1004a680
constexpr unsigned int DispatchParsedCallback88 = 0x1004a680;
// R6GameService.dll code @ 1004a6e0
constexpr unsigned int DispatchSelector40TextValues = 0x1004a6e0;
// R6GameService.dll code @ 1004a8e0
constexpr unsigned int DispatchSelector3fValueAndText = 0x1004a8e0;
// R6GameService.dll code @ 1004a950
constexpr unsigned int DeliverSelector41 = 0x1004a950;
// R6GameService.dll code @ 1004a990
constexpr unsigned int DeliverSelector6 = 0x1004a990;
// R6GameService.dll code @ 1004a9d0
constexpr unsigned int DeliverSelector2A = 0x1004a9d0;
// R6GameService.dll code @ 1004aa10
constexpr unsigned int DispatchSelector42TextAndBinary = 0x1004aa10;
// R6GameService.dll code @ 1004ac40
constexpr unsigned int DispatchSelector6aTextAndPairs = 0x1004ac40;
// R6GameService.dll code @ 1004ae80
constexpr unsigned int DispatchSelector47VariantPayload = 0x1004ae80;
// R6GameService.dll code @ 1004b270
constexpr unsigned int PassesOptionalServiceTreeNameFilter = 0x1004b270;
// R6GameService.dll code @ 1004b350
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedText = 0x1004b350;
// R6GameService.dll code @ 1004b490
constexpr unsigned int InitializeServiceTreeHeader = 0x1004b490;
// R6GameService.dll code @ 1004b4b0
constexpr unsigned int FreeNestedListNodes = 0x1004b4b0;
// R6GameService.dll code @ 1004b4f0
constexpr unsigned int FindOrInsertServiceTreeByteString = 0x1004b4f0;
// R6GameService.dll code @ 1004b6b0
constexpr unsigned int CreateServiceTreeByteStringNode = 0x1004b6b0;
// R6GameService.dll code @ 1004b747
constexpr unsigned int ordered_tree_supportCatch = 0x1004b747;
// R6GameService.dll code @ 1004b760
constexpr unsigned int FindServiceTreeNodeByByteString = 0x1004b760;
// R6GameService.dll code @ 1004b850
constexpr unsigned int InitializeServiceObjectVtablesAndStorage = 0x1004b850;
// R6GameService.dll code @ 1004b8c0
constexpr unsigned int DestroyServiceObjectAtAdjustedSubobject = 0x1004b8c0;
// R6GameService.dll code @ 1004b8f0
constexpr unsigned int RestoreServiceObjectBaseVtables = 0x1004b8f0;
// R6GameService.dll code @ 1004b910
constexpr unsigned int ForwardSharedCallback08 = 0x1004b910;
// R6GameService.dll code @ 1004b930
constexpr unsigned int ForwardclFriendsCBCallback0c = 0x1004b930;
// R6GameService.dll code @ 1004b950
constexpr unsigned int ForwardSharedCallback10 = 0x1004b950;
// R6GameService.dll code @ 1004b970
constexpr unsigned int ForwardclFriendsCBCallback14 = 0x1004b970;
// R6GameService.dll code @ 1004b980
constexpr unsigned int ForwardclFriendsCBCallback1c = 0x1004b980;
// R6GameService.dll code @ 1004b990
constexpr unsigned int ForwardclFriendsCBCallback20 = 0x1004b990;
// R6GameService.dll code @ 1004b9a0
constexpr unsigned int ForwardclFriendsCBCallback24 = 0x1004b9a0;
// R6GameService.dll code @ 1004b9b0
constexpr unsigned int ForwardclFriendsCBCallback28 = 0x1004b9b0;
// R6GameService.dll code @ 1004b9d0
constexpr unsigned int ForwardclFriendsCBCallback2c = 0x1004b9d0;
// R6GameService.dll code @ 1004b9e0
constexpr unsigned int ForwardclFriendsCBCallback30 = 0x1004b9e0;
// R6GameService.dll code @ 1004ba00
constexpr unsigned int ForwardclFriendsCBCallback34 = 0x1004ba00;
// R6GameService.dll code @ 1004ba20
constexpr unsigned int ForwardclFriendsCBCallback38 = 0x1004ba20;
// R6GameService.dll code @ 1004ba40
constexpr unsigned int ForwardclFriendsCBCallback3c = 0x1004ba40;
// R6GameService.dll code @ 1004ba50
constexpr unsigned int ForwardclFriendsCBCallback40 = 0x1004ba50;
// R6GameService.dll code @ 1004ba70
constexpr unsigned int ForwardclFriendsCBCallback44 = 0x1004ba70;
// R6GameService.dll code @ 1004ba90
constexpr unsigned int InitializeServiceVtablesAndStorage = 0x1004ba90;
// R6GameService.dll code @ 1004baf0
constexpr unsigned int clLoginCB_DestroyServiceObjectAtAdjustedSubobject = 0x1004baf0;
// R6GameService.dll code @ 1004bb20
constexpr unsigned int RestoreServiceBaseVtables = 0x1004bb20;
// R6GameService.dll code @ 1004bb40
constexpr unsigned int ForwardclLoginCBCallback08 = 0x1004bb40;
// R6GameService.dll code @ 1004bb60
constexpr unsigned int ForwardclLoginCBCallback0c = 0x1004bb60;
// R6GameService.dll code @ 1004bb80
constexpr unsigned int ForwardclLoginCBCallback10 = 0x1004bb80;
// R6GameService.dll code @ 1004bba0
constexpr unsigned int ForwardclLoginCBCallback14 = 0x1004bba0;
// R6GameService.dll code @ 1004bbc0
constexpr unsigned int ForwardSharedCallback18 = 0x1004bbc0;
// R6GameService.dll code @ 1004bbd0
constexpr unsigned int ForwardclLoginCBCallback1c = 0x1004bbd0;
// R6GameService.dll code @ 1004bbe0
constexpr unsigned int ForwardclLoginCBCallback20 = 0x1004bbe0;
// R6GameService.dll code @ 1004bc00
constexpr unsigned int ForwardclLoginCBCallback24 = 0x1004bc00;
// R6GameService.dll code @ 1004bc20
constexpr unsigned int ForwardclLoginCBCallback28 = 0x1004bc20;
// R6GameService.dll code @ 1004bc40
constexpr unsigned int ConstructCMsgQueue = 0x1004bc40;
// R6GameService.dll code @ 1004bca0
constexpr unsigned int DeleteCMsgQueue = 0x1004bca0;
// R6GameService.dll code @ 1004bcc0
constexpr unsigned int DestroyCMsgQueue = 0x1004bcc0;
// R6GameService.dll code @ 1004bd60
constexpr unsigned int DrainCMsgQueue = 0x1004bd60;
// R6GameService.dll code @ 1004bdc0
constexpr unsigned int RemoveQueuedRecordBySelector = 0x1004bdc0;
// R6GameService.dll code @ 1004c040
constexpr unsigned int ReadQueuedHeadValue = 0x1004c040;
// R6GameService.dll code @ 1004c220
constexpr unsigned int EnqueueCMsgQueuePayload = 0x1004c220;
// R6GameService.dll code @ 1004c280
constexpr unsigned int AllocateListPayloadNode = 0x1004c280;
// R6GameService.dll code @ 1004c2a0
constexpr unsigned int ConstructQueuedPayloadRecord = 0x1004c2a0;
// R6GameService.dll code @ 1004c340
constexpr unsigned int CopyConstructQueuedPayloadRecord = 0x1004c340;
// R6GameService.dll code @ 1004c3e0
constexpr unsigned int CConnectionConstruct = 0x1004c3e0;
// R6GameService.dll code @ 1004c430
constexpr unsigned int CConnectionDestroyProvider = 0x1004c430;
// R6GameService.dll code @ 1004c450
constexpr unsigned int CConnectionReplaceAndStartProvider = 0x1004c450;
// R6GameService.dll code @ 1004c520
constexpr unsigned int CConnectionCloseProvider = 0x1004c520;
// R6GameService.dll code @ 1004c540
constexpr unsigned int CConnectionPopCopiedMessage = 0x1004c540;
// R6GameService.dll code @ 1004c5e0
constexpr unsigned int CConnectionListDestroy = 0x1004c5e0;
// R6GameService.dll code @ 1004c700
constexpr unsigned int CConnectionListDelete = 0x1004c700;
// R6GameService.dll code @ 1004c720
constexpr unsigned int ForwardCurrentMessageListDestroy = 0x1004c720;
// R6GameService.dll code @ 1004c730
constexpr unsigned int CConnectionListConstruct = 0x1004c730;
// R6GameService.dll code @ 1004c7d0
constexpr unsigned int DeleteConnectionPointerList = 0x1004c7d0;
// R6GameService.dll code @ 1004c7f0
constexpr unsigned int DeleteCurrentMessagePointerList = 0x1004c7f0;
// R6GameService.dll code @ 1004c810
constexpr unsigned int CConnectionListInsertConfigured = 0x1004c810;
// R6GameService.dll code @ 1004c8e0
constexpr unsigned int CConnectionListQueryKey = 0x1004c8e0;
// R6GameService.dll code @ 1004c930
constexpr unsigned int CConnectionListFindFailingKey = 0x1004c930;
// R6GameService.dll code @ 1004c960
constexpr unsigned int CConnectionListSendToKey = 0x1004c960;
// R6GameService.dll code @ 1004c990
constexpr unsigned int CConnectionListBroadcast = 0x1004c990;
// R6GameService.dll code @ 1004c9e0
constexpr unsigned int CConnectionListCollectMessages = 0x1004c9e0;
// R6GameService.dll code @ 1004cad0
constexpr unsigned int CConnectionListFindBorrowed = 0x1004cad0;
// R6GameService.dll code @ 1004cb00
constexpr unsigned int DestroyConnectionPointerList = 0x1004cb00;
// R6GameService.dll code @ 1004cb90
constexpr unsigned int PopConnectionPointerList = 0x1004cb90;
// R6GameService.dll code @ 1004cbd0
constexpr unsigned int PopBackConnectionPointerList = 0x1004cbd0;
// R6GameService.dll code @ 1004cc20
constexpr unsigned int EraseConnectionPointerListNode = 0x1004cc20;
// R6GameService.dll code @ 1004cc60
constexpr unsigned int EraseConnectionPointerRange = 0x1004cc60;
// R6GameService.dll code @ 1004cce0
constexpr unsigned int DestroyCurrentMessagePointerList = 0x1004cce0;
// R6GameService.dll code @ 1004cd70
constexpr unsigned int EraseCallbackPointerListNode = 0x1004cd70;
// R6GameService.dll code @ 1004cdb0
constexpr unsigned int EraseOwnedPayloadListRange = 0x1004cdb0;
// R6GameService.dll code @ 1004ce30
constexpr unsigned int ReplaceRecordBySelector = 0x1004ce30;
// R6GameService.dll code @ 1004ce70
constexpr unsigned int CopyTerminatedBytesForward = 0x1004ce70;
// R6GameService.dll code @ 1004ce90
constexpr unsigned int ReadTransportSelectorRecord = 0x1004ce90;
// R6GameService.dll code @ 1004d050
constexpr unsigned int InstallTransportFieldsIfEmpty = 0x1004d050;
// R6GameService.dll code @ 1004d070
constexpr unsigned int SendSelector5cIfTransportAvailable = 0x1004d070;
// R6GameService.dll code @ 1004d180
constexpr unsigned int SendSelector4eWordPair = 0x1004d180;
// R6GameService.dll code @ 1004d2b0
constexpr unsigned int ParseSelector4e = 0x1004d2b0;
// R6GameService.dll code @ 1004d2e0
constexpr unsigned int ParseSelector4bText = 0x1004d2e0;
// R6GameService.dll code @ 1004d350
constexpr unsigned int ParseSelector4cText = 0x1004d350;
// R6GameService.dll code @ 1004d3c0
constexpr unsigned int ParseSelector65Strings = 0x1004d3c0;
// R6GameService.dll code @ 1004d490
constexpr unsigned int ParseSelector58Fields = 0x1004d490;
// R6GameService.dll code @ 1004d6d0
constexpr unsigned int ParseSelector5aOwnedBytes = 0x1004d6d0;
// R6GameService.dll code @ 1004d920
constexpr unsigned int ParseSelector5bFields = 0x1004d920;
// R6GameService.dll code @ 1004db60
constexpr unsigned int ParseSelector85 = 0x1004db60;
// R6GameService.dll code @ 1004db90
constexpr unsigned int ParseSelector51 = 0x1004db90;
// R6GameService.dll code @ 1004dbc0
constexpr unsigned int ParseSelector4aFields = 0x1004dbc0;
// R6GameService.dll code @ 1004dcf0
constexpr unsigned int ParseSelector08Fields = 0x1004dcf0;
// R6GameService.dll code @ 1004df10
constexpr unsigned int ParseSelector98Fields = 0x1004df10;
// R6GameService.dll code @ 1004e140
constexpr unsigned int DispatchParsedSelector4e = 0x1004e140;
// R6GameService.dll code @ 1004e180
constexpr unsigned int DispatchParsedSelector4b = 0x1004e180;
// R6GameService.dll code @ 1004e1d0
constexpr unsigned int DispatchParsedSelector4c = 0x1004e1d0;
// R6GameService.dll code @ 1004e220
constexpr unsigned int DispatchParsedSlot1c = 0x1004e220;
// R6GameService.dll code @ 1004e270
constexpr unsigned int DispatchParsedSlot20 = 0x1004e270;
// R6GameService.dll code @ 1004e2c0
constexpr unsigned int DispatchParsedOwnedBuffer = 0x1004e2c0;
// R6GameService.dll code @ 1004e320
constexpr unsigned int DispatchParsedSlot28 = 0x1004e320;
// R6GameService.dll code @ 1004e370
constexpr unsigned int DispatchParsedSlot2c = 0x1004e370;
// R6GameService.dll code @ 1004e3b0
constexpr unsigned int DispatchParsedSlot30 = 0x1004e3b0;
// R6GameService.dll code @ 1004e3f0
constexpr unsigned int DispatchParsedSlot34 = 0x1004e3f0;
// R6GameService.dll code @ 1004e460
constexpr unsigned int DispatchParsedSlot38 = 0x1004e460;
// R6GameService.dll code @ 1004e4d0
constexpr unsigned int DispatchParsedSlot3c = 0x1004e4d0;
// R6GameService.dll code @ 1004e540
constexpr unsigned int ParseSelector4fCodeAndText = 0x1004e540;
// R6GameService.dll code @ 1004e770
constexpr unsigned int ParseSelector50CodeAndText = 0x1004e770;
// R6GameService.dll code @ 1004e990
constexpr unsigned int ParseSelector54EncodedValue = 0x1004e990;
// R6GameService.dll code @ 1004ea00
constexpr unsigned int CopySelector55Text = 0x1004ea00;
// R6GameService.dll code @ 1004ea40
constexpr unsigned int DispatchParsedSelector4f = 0x1004ea40;
// R6GameService.dll code @ 1004ea80
constexpr unsigned int DispatchParsedSelector50 = 0x1004ea80;
// R6GameService.dll code @ 1004eac0
constexpr unsigned int DispatchParsedSelector54 = 0x1004eac0;
// R6GameService.dll code @ 1004eaf0
constexpr unsigned int DispatchParsedSelector55Text = 0x1004eaf0;
// R6GameService.dll code @ 1004eb20
constexpr unsigned int ValidateParserSelectorAndOptionalWord = 0x1004eb20;
// R6GameService.dll code @ 1004ece0
constexpr unsigned int ClearTwoServiceStateWords = 0x1004ece0;
// R6GameService.dll code @ 1004ecf0
constexpr unsigned int StorePointerAndSetReleaseFlag = 0x1004ecf0;
// R6GameService.dll code @ 1004ed40
constexpr unsigned int OpenNestedConnectionAndWait = 0x1004ed40;
// R6GameService.dll code @ 1004ed80
constexpr unsigned int ReleaseNestedTransportResource = 0x1004ed80;
// R6GameService.dll code @ 1004eda0
constexpr unsigned int SendSelector66StringTuple = 0x1004eda0;
// R6GameService.dll code @ 1004eef0
constexpr unsigned int SendSelector4dString = 0x1004eef0;
// R6GameService.dll code @ 1004f010
constexpr unsigned int SendEmptySelector5d = 0x1004f010;
// R6GameService.dll code @ 1004f120
constexpr unsigned int SendSelector13String = 0x1004f120;
// R6GameService.dll code @ 1004f240
constexpr unsigned int ParseSelector13AndDispatchSlot00 = 0x1004f240;
// R6GameService.dll code @ 1004f2e0
constexpr unsigned int ParseSelector5dAndDispatchSlot04 = 0x1004f2e0;
// R6GameService.dll code @ 1004f340
constexpr unsigned int ParseSelector66AndDispatchSlot08 = 0x1004f340;
// R6GameService.dll code @ 1004f380
constexpr unsigned int ParseSelector4dAndDispatchSlot0c = 0x1004f380;
// R6GameService.dll code @ 1004f3c0
constexpr unsigned int ParseSelectorB5AndDispatchSlot10 = 0x1004f3c0;
// R6GameService.dll code @ 1004f410
constexpr unsigned int ParseSelector01AndDispatchSlot18 = 0x1004f410;
// R6GameService.dll code @ 1004f450
constexpr unsigned int ParseSelector62AndDispatchSlot1c = 0x1004f450;
// R6GameService.dll code @ 1004f490
constexpr unsigned int ParseSelectorDEAndDispatchSlot20 = 0x1004f490;
// R6GameService.dll code @ 1004f4f0
constexpr unsigned int ReplaceSelectionAndDispatchSlot14 = 0x1004f4f0;
// R6GameService.dll code @ 1004f510
constexpr unsigned int ParseSelector13RecordIntoOutputs = 0x1004f510;
// R6GameService.dll code @ 1004f750
constexpr unsigned int ParseSelector5dRecordIntoOutputs = 0x1004f750;
// R6GameService.dll code @ 1004f970
constexpr unsigned int RefreshSelector66Values = 0x1004f970;
// R6GameService.dll code @ 1004f9a0
constexpr unsigned int RefreshSelector4dValues = 0x1004f9a0;
// R6GameService.dll code @ 1004f9d0
constexpr unsigned int ParseSelectorB5RecordIntoOutputs = 0x1004f9d0;
// R6GameService.dll code @ 1004fa50
constexpr unsigned int RefreshSelector01Values = 0x1004fa50;
// R6GameService.dll code @ 1004fa80
constexpr unsigned int RefreshSelector62Values = 0x1004fa80;
// R6GameService.dll code @ 1004fab0
constexpr unsigned int ParseSelectorDETextFields = 0x1004fab0;
// R6GameService.dll code @ 1004fcd0
constexpr unsigned int SetPointerAndFlag = 0x1004fcd0;
// R6GameService.dll code @ 1004fd10
constexpr unsigned int service_callback_support_SetPointerAndFlag = 0x1004fd10;
// R6GameService.dll code @ 1004fd50
constexpr unsigned int InitializeVtableSubobject = 0x1004fd50;
// R6GameService.dll code @ 1004fda0
constexpr unsigned int DeleteclLadderQueryCB = 0x1004fda0;
// R6GameService.dll code @ 1004fdd0
constexpr unsigned int RestoreVtableSubobject = 0x1004fdd0;
// R6GameService.dll code @ 1004fdf0
constexpr unsigned int ForwardclLadderQueryCBCallback08 = 0x1004fdf0;
// R6GameService.dll code @ 1004fe10
constexpr unsigned int InitializeExtendedVtableSubobject = 0x1004fe10;
// R6GameService.dll code @ 1004fe60
constexpr unsigned int DeleteclPersistentCB = 0x1004fe60;
// R6GameService.dll code @ 1004fe90
constexpr unsigned int RestoreExtendedVtableSubobject = 0x1004fe90;
// R6GameService.dll code @ 1004feb0
constexpr unsigned int ForwardclPersistentCBCallback0c = 0x1004feb0;
// R6GameService.dll code @ 1004fec0
constexpr unsigned int ForwardclPersistentCBCallback14 = 0x1004fec0;
// R6GameService.dll code @ 1004fee0
constexpr unsigned int ReleaseNodesAndSentinelThunk = 0x1004fee0;
// R6GameService.dll code @ 1004fef0
constexpr unsigned int DestroyIndexedRecordCollectionState = 0x1004fef0;
// R6GameService.dll code @ 1004ffd0
constexpr unsigned int thunk_DestroyNestedRecordTree = 0x1004ffd0;
// R6GameService.dll code @ 1004ffe0
constexpr unsigned int DestroyNestedRecordTree = 0x1004ffe0;
// R6GameService.dll code @ 10050070
constexpr unsigned int FindOuterRecordWordByNestedTextPair = 0x10050070;
// R6GameService.dll code @ 10050190
constexpr unsigned int FindNestedRecordWordByTextPair = 0x10050190;
// R6GameService.dll code @ 10050260
constexpr unsigned int EnsureOuterRecordExists = 0x10050260;
// R6GameService.dll code @ 100504d0
constexpr unsigned int DestroyRecordTreeAtOffset8c = 0x100504d0;
// R6GameService.dll code @ 10050560
constexpr unsigned int DestroyRecordTreeAtOffset90 = 0x10050560;
// R6GameService.dll code @ 100505f0
constexpr unsigned int DeleteOuterRecordByKey = 0x100505f0;
// R6GameService.dll code @ 100506c0
constexpr unsigned int ClearOuterRecordCollection = 0x100506c0;
// R6GameService.dll code @ 10050770
constexpr unsigned int AddNestedRecordForZeroLookup = 0x10050770;
// R6GameService.dll code @ 10050950
constexpr unsigned int MarkNestedRecordFlag = 0x10050950;
// R6GameService.dll code @ 10050990
constexpr unsigned int RemoveNestedRecordsByOuterKey = 0x10050990;
// R6GameService.dll code @ 10050be0
constexpr unsigned int ApplyNestedRecordUpdateByTextPair = 0x10050be0;
// R6GameService.dll code @ 10050f90
constexpr unsigned int SendProxyRequestForOuterRecordKey = 0x10050f90;
// R6GameService.dll code @ 10050ff0
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdates = 0x10050ff0;
// R6GameService.dll code @ 10051270
constexpr unsigned int QueueMissingNestedRecordRequest = 0x10051270;
// R6GameService.dll code @ 10051410
constexpr unsigned int ClearQueuedRecords18 = 0x10051410;
// R6GameService.dll code @ 10051460
constexpr unsigned int ClearQueuedRecords10 = 0x10051460;
// R6GameService.dll code @ 100514b0
constexpr unsigned int AppendQueuedRecord = 0x100514b0;
// R6GameService.dll code @ 100515b0
constexpr unsigned int RemoveQueuedRecordsByKey = 0x100515b0;
// R6GameService.dll code @ 10051610
constexpr unsigned int PopQueuedRecord = 0x10051610;
// R6GameService.dll code @ 100516f0
constexpr unsigned int ResetKeyedState2 = 0x100516f0;
// R6GameService.dll code @ 10051740
constexpr unsigned int ResetStateTwoForAllOuterRecords = 0x10051740;
// R6GameService.dll code @ 100517a0
constexpr unsigned int ClearNestedRecordsAndLists = 0x100517a0;
// R6GameService.dll code @ 100517c0
constexpr unsigned int CopyRecordStateAndNestedTree = 0x100517c0;
// R6GameService.dll code @ 10051900
constexpr unsigned int InitializeTreeOwnerStorage = 0x10051900;
// R6GameService.dll code @ 10051940
constexpr unsigned int ClearTreeOwnerStorage = 0x10051940;
// R6GameService.dll code @ 10051990
constexpr unsigned int CloneOrderedTreeSubtree = 0x10051990;
// R6GameService.dll code @ 10051a24
constexpr unsigned int ordered_tree_support_ordered_tree_supportCatch = 0x10051a24;
// R6GameService.dll code @ 10051a70
constexpr unsigned int ordered_tree_support_ReleaseLinkedNodes = 0x10051a70;
// R6GameService.dll code @ 10051aa0
constexpr unsigned int ReleaseOuterRecordNodes = 0x10051aa0;
// R6GameService.dll code @ 10051ae0
constexpr unsigned int InsertOrFindOrderedTreeNodeByU16Key = 0x10051ae0;
// R6GameService.dll code @ 10051fd0
constexpr unsigned int FindOrderedTreeNodeByU16Key = 0x10051fd0;
// R6GameService.dll code @ 10052020
constexpr unsigned int DestroyOuterRecordAndMaybeFree = 0x10052020;
// R6GameService.dll code @ 10052040
constexpr unsigned int AllocateTreeNodeWithCopiedPayload = 0x10052040;
// R6GameService.dll code @ 10052070
constexpr unsigned int InsertTreeNodeAndRebalance = 0x10052070;
// R6GameService.dll code @ 10052240
constexpr unsigned int InsertOrderedTreeNodeAtHint = 0x10052240;
// R6GameService.dll code @ 10052410
constexpr unsigned int FindOrInsertOrderedTreeNodeByU16Key = 0x10052410;
// R6GameService.dll code @ 10052580
constexpr unsigned int ordered_tree_support_FindOrderedTreeNodeByU16Key = 0x10052580;
// R6GameService.dll code @ 100525c0
constexpr unsigned int AllocateTreeNodeWithCopiedExtendedPayload = 0x100525c0;
// R6GameService.dll code @ 10052691
constexpr unsigned int ordered_tree_support_ordered_tree_supportCatch2 = 0x10052691;
// R6GameService.dll code @ 100526b0
constexpr unsigned int InitializeAndCloneEmbeddedTree = 0x100526b0;
// R6GameService.dll code @ 10052780
constexpr unsigned int InitializeServiceStateBlock = 0x10052780;
// R6GameService.dll code @ 10052870
constexpr unsigned int DeleteClLobbyCBFromSecondary = 0x10052870;
// R6GameService.dll code @ 100528a0
constexpr unsigned int RestoreBaseSubobjectVtables = 0x100528a0;
// R6GameService.dll code @ 100528c0
constexpr unsigned int ForwardLobbyCallback = 0x100528c0;
// R6GameService.dll code @ 100528d0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback = 0x100528d0;
// R6GameService.dll code @ 100528e0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback2 = 0x100528e0;
// R6GameService.dll code @ 10052900
constexpr unsigned int clLobbyCB_ForwardLobbyCallback3 = 0x10052900;
// R6GameService.dll code @ 10052920
constexpr unsigned int clLobbyCB_ForwardLobbyCallback4 = 0x10052920;
// R6GameService.dll code @ 10052940
constexpr unsigned int clLobbyCB_ForwardLobbyCallback5 = 0x10052940;
// R6GameService.dll code @ 10052960
constexpr unsigned int clLobbyCB_ForwardLobbyCallback6 = 0x10052960;
// R6GameService.dll code @ 10052980
constexpr unsigned int clLobbyCB_ForwardLobbyCallback7 = 0x10052980;
// R6GameService.dll code @ 100529a0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback8 = 0x100529a0;
// R6GameService.dll code @ 100529c0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback9 = 0x100529c0;
// R6GameService.dll code @ 100529e0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback10 = 0x100529e0;
// R6GameService.dll code @ 10052a20
constexpr unsigned int clLobbyCB_ForwardLobbyCallback11 = 0x10052a20;
// R6GameService.dll code @ 10052a30
constexpr unsigned int clLobbyCB_ForwardLobbyCallback12 = 0x10052a30;
// R6GameService.dll code @ 10052a40
constexpr unsigned int clLobbyCB_ForwardLobbyCallback13 = 0x10052a40;
// R6GameService.dll code @ 10052a60
constexpr unsigned int clLobbyCB_ForwardLobbyCallback14 = 0x10052a60;
// R6GameService.dll code @ 10052a70
constexpr unsigned int clLobbyCB_ForwardLobbyCallback15 = 0x10052a70;
// R6GameService.dll code @ 10052a90
constexpr unsigned int clLobbyCB_ForwardLobbyCallback16 = 0x10052a90;
// R6GameService.dll code @ 10052ab0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback17 = 0x10052ab0;
// R6GameService.dll code @ 10052ad0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback18 = 0x10052ad0;
// R6GameService.dll code @ 10052ae0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback19 = 0x10052ae0;
// R6GameService.dll code @ 10052b00
constexpr unsigned int clLobbyCB_ForwardLobbyCallback20 = 0x10052b00;
// R6GameService.dll code @ 10052b20
constexpr unsigned int clLobbyCB_ForwardLobbyCallback21 = 0x10052b20;
// R6GameService.dll code @ 10052b40
constexpr unsigned int clLobbyCB_ForwardLobbyCallback22 = 0x10052b40;
// R6GameService.dll code @ 10052b50
constexpr unsigned int clLobbyCB_ForwardLobbyCallback23 = 0x10052b50;
// R6GameService.dll code @ 10052b60
constexpr unsigned int clLobbyCB_ForwardLobbyCallback24 = 0x10052b60;
// R6GameService.dll code @ 10052b80
constexpr unsigned int clLobbyCB_ForwardLobbyCallback25 = 0x10052b80;
// R6GameService.dll code @ 10052ba0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback26 = 0x10052ba0;
// R6GameService.dll code @ 10052bc0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback27 = 0x10052bc0;
// R6GameService.dll code @ 10052be0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback28 = 0x10052be0;
// R6GameService.dll code @ 10052c00
constexpr unsigned int clLobbyCB_ForwardLobbyCallback29 = 0x10052c00;
// R6GameService.dll code @ 10052c20
constexpr unsigned int clLobbyCB_ForwardLobbyCallback30 = 0x10052c20;
// R6GameService.dll code @ 10052c40
constexpr unsigned int clLobbyCB_ForwardLobbyCallback31 = 0x10052c40;
// R6GameService.dll code @ 10052c60
constexpr unsigned int clLobbyCB_ForwardLobbyCallback32 = 0x10052c60;
// R6GameService.dll code @ 10052c80
constexpr unsigned int clLobbyCB_ForwardLobbyCallback33 = 0x10052c80;
// R6GameService.dll code @ 10052ca0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback34 = 0x10052ca0;
// R6GameService.dll code @ 10052cb0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback35 = 0x10052cb0;
// R6GameService.dll code @ 10052cc0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback36 = 0x10052cc0;
// R6GameService.dll code @ 10052cd0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback37 = 0x10052cd0;
// R6GameService.dll code @ 10052ce0
constexpr unsigned int clLobbyCB_ForwardLobbyCallback38 = 0x10052ce0;
// R6GameService.dll code @ 10052d00
constexpr unsigned int clLobbyCB_ForwardLobbyCallback39 = 0x10052d00;
// R6GameService.dll code @ 10052d10
constexpr unsigned int clLobbyCB_ForwardLobbyCallback40 = 0x10052d10;
// R6GameService.dll code @ 10052d20
constexpr unsigned int clLobbyCB_ForwardLobbyCallback41 = 0x10052d20;
// R6GameService.dll code @ 10052d40
constexpr unsigned int clLobbyCB_ForwardLobbyCallback42 = 0x10052d40;
// R6GameService.dll code @ 10052d60
constexpr unsigned int CLobbySrvConnectionListConstruct = 0x10052d60;
// R6GameService.dll code @ 10052ee0
constexpr unsigned int CLobbySrvConnectionListDelete = 0x10052ee0;
// R6GameService.dll code @ 10052f00
constexpr unsigned int CLobbySrvConnectionListDestroy = 0x10052f00;
// R6GameService.dll code @ 10052ff0
constexpr unsigned int thunk_ReleaseIndexedTree = 0x10052ff0;
// R6GameService.dll code @ 10053000
constexpr unsigned int ReleaseIndexedTree = 0x10053000;
// R6GameService.dll code @ 10053090
constexpr unsigned int CLobbySrvConnectionListAppendUniqueWord = 0x10053090;
// R6GameService.dll code @ 10053130
constexpr unsigned int RemoveValueFromKeyList = 0x10053130;
// R6GameService.dll code @ 10053190
constexpr unsigned int ServicePendingRecordsAndExpireIdleKeys = 0x10053190;
// R6GameService.dll code @ 10053330
constexpr unsigned int NotifyAndRemoveKeyRecords = 0x10053330;
// R6GameService.dll code @ 10053610
constexpr unsigned int MarkKeyRecordPending = 0x10053610;
// R6GameService.dll code @ 10053670
constexpr unsigned int RemoveMatchingKeyRecords = 0x10053670;
// R6GameService.dll code @ 100536e0
constexpr unsigned int UpdateKeyedTextAndNotify = 0x100536e0;
// R6GameService.dll code @ 10053970
constexpr unsigned int SendKeyNotificationD1 = 0x10053970;
// R6GameService.dll code @ 10053b40
constexpr unsigned int ResetIndexedRecordState = 0x10053b40;
// R6GameService.dll code @ 10053b80
constexpr unsigned int ClearOwnedList9c = 0x10053b80;
// R6GameService.dll code @ 10053bd0
constexpr unsigned int ClearOwnedLista4 = 0x10053bd0;
// R6GameService.dll code @ 10053c20
constexpr unsigned int ContainsIndexedKey = 0x10053c20;
// R6GameService.dll code @ 10053c70
constexpr unsigned int BuildRecordFromQueueHeadOrFallback = 0x10053c70;
// R6GameService.dll code @ 10053d50
constexpr unsigned int RemoveIndexedRecordAndQueueNotifications = 0x10053d50;
// R6GameService.dll code @ 10054110
constexpr unsigned int ProcessIndexedRecordsInKeyOrder = 0x10054110;
// R6GameService.dll code @ 10054170
constexpr unsigned int IndexedRecordHasState2 = 0x10054170;
// R6GameService.dll code @ 100541d0
constexpr unsigned int RemoveListRecordsBySecondWord = 0x100541d0;
// R6GameService.dll code @ 10054230
constexpr unsigned int RemoveListRecordsByWordPair = 0x10054230;
// R6GameService.dll code @ 100542a0
constexpr unsigned int ApplyIndexedKeyUpdate = 0x100542a0;
// R6GameService.dll code @ 10054660
constexpr unsigned int QueueTaggedRecord = 0x10054660;
// R6GameService.dll code @ 100547d0
constexpr unsigned int SendDescriptorAsD1 = 0x100547d0;
// R6GameService.dll code @ 10054900
constexpr unsigned int InsertIndexedTextRecord = 0x10054900;
// R6GameService.dll code @ 10054b00
constexpr unsigned int ReleaseEmbeddedList88 = 0x10054b00;
// R6GameService.dll code @ 10054b50
constexpr unsigned int ReleaseEmbeddedList8c = 0x10054b50;
// R6GameService.dll code @ 10054ba0
constexpr unsigned int UpdateIndexedRecordText = 0x10054ba0;
// R6GameService.dll code @ 10054bf0
constexpr unsigned int GetReferencedStoragePlus8 = 0x10054bf0;
// R6GameService.dll code @ 10054c00
constexpr unsigned int GetReferencedStoragePlus10 = 0x10054c00;
// R6GameService.dll code @ 10054c10
constexpr unsigned int CloneCircularList = 0x10054c10;
// R6GameService.dll code @ 10054ce0
constexpr unsigned int EraseIndexedNode = 0x10054ce0;
// R6GameService.dll code @ 10054d20
constexpr unsigned int ClearIndexedTree = 0x10054d20;
// R6GameService.dll code @ 10054d80
constexpr unsigned int ReleaseIndexedSubtree = 0x10054d80;
// R6GameService.dll code @ 10054dc0
constexpr unsigned int FindOrInsertIndexedTreeNode = 0x10054dc0;
// R6GameService.dll code @ 100552b0
constexpr unsigned int FindIndexedTreeLowerBound = 0x100552b0;
// R6GameService.dll code @ 10055300
constexpr unsigned int DestroyEmbeddedListAndMaybeNode = 0x10055300;
// R6GameService.dll code @ 10055320
constexpr unsigned int InsertIndexedTreeNodeAndRebalance = 0x10055320;
// R6GameService.dll code @ 100554f0
constexpr unsigned int ordered_tree_support_FindOrInsertIndexedTreeNode = 0x100554f0;
// R6GameService.dll code @ 10055660
constexpr unsigned int FindIndexedTreeKey = 0x10055660;
// R6GameService.dll code @ 100556a0
constexpr unsigned int AllocateIndexedRecordAndCopyList = 0x100556a0;
// R6GameService.dll code @ 100557b0
constexpr unsigned int indexed_record_supportCatch = 0x100557b0;
// R6GameService.dll code @ 100557d0
constexpr unsigned int InitializeCircularListSentinel = 0x100557d0;
// R6GameService.dll code @ 10055800
constexpr unsigned int CopyCircularListPayloads = 0x10055800;
// R6GameService.dll code @ 10055860
constexpr unsigned int UpdateStringKeyedRecord = 0x10055860;
// R6GameService.dll code @ 10055a50
constexpr unsigned int DestroyOwnedList = 0x10055a50;
// R6GameService.dll code @ 10055ae0
constexpr unsigned int AppendOrderedRecordsToDescriptor = 0x10055ae0;
// R6GameService.dll code @ 10055c60
constexpr unsigned int ConstructHeapByteStringFromCString = 0x10055c60;
// R6GameService.dll code @ 10055d80
constexpr unsigned int InsertOrFindByteDescriptorNode = 0x10055d80;
// R6GameService.dll code @ 10055f40
constexpr unsigned int ConstructIndexedRecordCopy = 0x10055f40;
// R6GameService.dll code @ 10056070
constexpr unsigned int AssignIndexedRecord = 0x10056070;
// R6GameService.dll code @ 100561a0
constexpr unsigned int ForwardStackWord = 0x100561a0;
// R6GameService.dll code @ 100561b0
constexpr unsigned int StoreFirstWordIgnoringContext = 0x100561b0;
// R6GameService.dll code @ 100561c0
constexpr unsigned int ordered_tree_support_CloneOrderedTreeSubtree = 0x100561c0;
// R6GameService.dll code @ 10056254
constexpr unsigned int ordered_tree_support_ordered_tree_supportCatch3 = 0x10056254;
// R6GameService.dll code @ 100562a0
constexpr unsigned int AllocateIndexedTreeNode = 0x100562a0;
// R6GameService.dll code @ 10056344
constexpr unsigned int ordered_tree_support_ordered_tree_supportCatch4 = 0x10056344;
// R6GameService.dll code @ 10056360
constexpr unsigned int ForwardIndexedCollectionDestroy = 0x10056360;
// R6GameService.dll code @ 10056370
constexpr unsigned int ForwardDestroyServiceLinkedRecordContainer = 0x10056370;
// R6GameService.dll code @ 10056380
constexpr unsigned int DestroyIndexedTree = 0x10056380;
// R6GameService.dll code @ 10056410
constexpr unsigned int InitializeIndexedValueCollection = 0x10056410;
// R6GameService.dll code @ 10056490
constexpr unsigned int RecordIndexedWordValue = 0x10056490;
// R6GameService.dll code @ 100565f0
constexpr unsigned int AppendIndexedValuesToDescriptor = 0x100565f0;
// R6GameService.dll code @ 10056790
constexpr unsigned int FindUnsignedTreeLowerBound = 0x10056790;
// R6GameService.dll code @ 100567c0
constexpr unsigned int FindOrInsertUnsignedTreeNodeNearHint = 0x100567c0;
// R6GameService.dll code @ 10056cb0
constexpr unsigned int ReadOrderedTreeLeftmostLink = 0x10056cb0;
// R6GameService.dll code @ 10056cc0
constexpr unsigned int FindOrInsertOrderedTreeNodeByU32Key = 0x10056cc0;
// R6GameService.dll code @ 10056e30
constexpr unsigned int InsertPairTreeNodeAtHint = 0x10056e30;
// R6GameService.dll code @ 10057000
constexpr unsigned int DecodeTransportRecordByHeaderClass = 0x10057000;
// R6GameService.dll code @ 100571c0
constexpr unsigned int InitializeTransportRecord = 0x100571c0;
// R6GameService.dll code @ 100573a0
constexpr unsigned int DestroyTransportRecordAndMaybeFree = 0x100573a0;
// R6GameService.dll code @ 100573c0
constexpr unsigned int thunk_DestroyEmbeddedListOwnerAndSentinel = 0x100573c0;
// R6GameService.dll code @ 100573d0
constexpr unsigned int ForwardCompactPointerListDestroy = 0x100573d0;
// R6GameService.dll code @ 100573e0
constexpr unsigned int thunk_DestroyEmbeddedListAndSentinel = 0x100573e0;
// R6GameService.dll code @ 100573f0
constexpr unsigned int DestroyObjectAndMaybeFree = 0x100573f0;
// R6GameService.dll code @ 10057410
constexpr unsigned int DestroyEmbeddedListAndSentinel = 0x10057410;
// R6GameService.dll code @ 100574a0
constexpr unsigned int InitializeTransportRecordWithOptionalConnection = 0x100574a0;
// R6GameService.dll code @ 100575f0
constexpr unsigned int DestroyTransportRecordMembers = 0x100575f0;
// R6GameService.dll code @ 10057740
constexpr unsigned int SendTransportControlRecordWithDecimalValue = 0x10057740;
// R6GameService.dll code @ 10057850
constexpr unsigned int StoreControlValueAndAcknowledge = 0x10057850;
// R6GameService.dll code @ 10057880
constexpr unsigned int SendZeroByteControlRecordEd = 0x10057880;
// R6GameService.dll code @ 100578b0
constexpr unsigned int StartTransportChannels = 0x100578b0;
// R6GameService.dll code @ 10057940
constexpr unsigned int ShutdownTransportChannels = 0x10057940;
// R6GameService.dll code @ 10057980
constexpr unsigned int UpdateTransportProvider = 0x10057980;
// R6GameService.dll code @ 10057c70
constexpr unsigned int DecodeQueuedTransportRecords = 0x10057c70;
// R6GameService.dll code @ 10057f00
constexpr unsigned int DrainQueuedTransportPayloads = 0x10057f00;
// R6GameService.dll code @ 10057f80
constexpr unsigned int QueueCopiedTransportRecord = 0x10057f80;
// R6GameService.dll code @ 10058010
constexpr unsigned int EnqueueBorrowedRecord = 0x10058010;
// R6GameService.dll code @ 10058040
constexpr unsigned int QueueRecordUsingStoredHeaderFields = 0x10058040;
// R6GameService.dll code @ 100580d0
constexpr unsigned int QueueKind2TransportRecordWhenEnabled = 0x100580d0;
// R6GameService.dll code @ 10058190
constexpr unsigned int CreateAndRoutePayloadRecord = 0x10058190;
// R6GameService.dll code @ 10058230
constexpr unsigned int RoutePayloadRecordByQueueMode = 0x10058230;
// R6GameService.dll code @ 100583b0
constexpr unsigned int QueryPeerEndpointAndPort = 0x100583b0;
// R6GameService.dll code @ 100583d0
constexpr unsigned int CheckTransportWordOrRequest = 0x100583d0;
// R6GameService.dll code @ 10058400
constexpr unsigned int PopAndDispatchControlRecord = 0x10058400;
// R6GameService.dll code @ 10058460
constexpr unsigned int ReceiveMatchingTransportRecord = 0x10058460;
// R6GameService.dll code @ 100584d0
constexpr unsigned int ReceiveRecordWithSource = 0x100584d0;
// R6GameService.dll code @ 10058500
constexpr unsigned int WaitForTransportReady = 0x10058500;
// R6GameService.dll code @ 100585b0
constexpr unsigned int DispatchProviderControlPayload = 0x100585b0;
// R6GameService.dll code @ 10058730
constexpr unsigned int HandleTransportReadyControlPayload = 0x10058730;
// R6GameService.dll code @ 100587f0
constexpr unsigned int HandleTransportBufferControlPayload = 0x100587f0;
// R6GameService.dll code @ 100589d0
constexpr unsigned int ClearProviderReadyFlag = 0x100589d0;
// R6GameService.dll code @ 100589e0
constexpr unsigned int QueueProviderControlPayload = 0x100589e0;
// R6GameService.dll code @ 10058b60
constexpr unsigned int QueueProviderControlPayloadWithLeadingOne = 0x10058b60;
// R6GameService.dll code @ 10058ce0
constexpr unsigned int DestroyFirstListEntryAndBuffer = 0x10058ce0;
// R6GameService.dll code @ 10058d20
constexpr unsigned int PopLastBufferedPayload = 0x10058d20;
// R6GameService.dll code @ 10058d70
constexpr unsigned int EraseCompactBufferNode = 0x10058d70;
// R6GameService.dll code @ 10058db0
constexpr unsigned int ReleaseListNodesInRange = 0x10058db0;
// R6GameService.dll code @ 10058e30
constexpr unsigned int DestroyFirstCallbackListEntry = 0x10058e30;
// R6GameService.dll code @ 10058e70
constexpr unsigned int PopBackCallbackListEntry = 0x10058e70;
// R6GameService.dll code @ 10058ec0
constexpr unsigned int DestroyEmbeddedListOwnerAndSentinel = 0x10058ec0;
// R6GameService.dll code @ 10058f50
constexpr unsigned int PopLastVirtualPayload = 0x10058f50;
// R6GameService.dll code @ 10058f90
constexpr unsigned int ReleaseClDataPointerListRange = 0x10058f90;
// R6GameService.dll code @ 10059000
constexpr unsigned int CopyListHeadSlot = 0x10059000;
// R6GameService.dll code @ 10059010
constexpr unsigned int ReceiveRecordWithSourceThunk = 0x10059010;
// R6GameService.dll code @ 10059020
constexpr unsigned int DeleteCompactPointerList = 0x10059020;
// R6GameService.dll code @ 10059040
constexpr unsigned int DestroyCompactPointerList = 0x10059040;
// R6GameService.dll code @ 100590d0
constexpr unsigned int DeleteEmbeddedPointerList = 0x100590d0;
// R6GameService.dll code @ 100590f0
constexpr unsigned int ReadListFirstNodeFromHeadSlot = 0x100590f0;
// R6GameService.dll code @ 10059100
constexpr unsigned int CopyFirstWord = 0x10059100;
// R6GameService.dll code @ 10059110
constexpr unsigned int InitializePayloadListHeader = 0x10059110;
// R6GameService.dll code @ 10059130
constexpr unsigned int list_node_support_NoOp = 0x10059130;
// R6GameService.dll code @ 10059140
constexpr unsigned int ReleaseNodesAndSentinel = 0x10059140;
// R6GameService.dll code @ 10059170
constexpr unsigned int RetreatNodeIterator = 0x10059170;
// R6GameService.dll code @ 10059180
constexpr unsigned int clSRPGSConnectConstruct = 0x10059180;
// R6GameService.dll code @ 10059220
constexpr unsigned int clSRPGSConnectDelete = 0x10059220;
// R6GameService.dll code @ 10059240
constexpr unsigned int clSRPGSConnectDestroy = 0x10059240;
// R6GameService.dll code @ 100592c0
constexpr unsigned int DispatchProviderReceiveState = 0x100592c0;
// R6GameService.dll code @ 10059300
constexpr unsigned int CloseAssociatedOwner = 0x10059300;
// R6GameService.dll code @ 10059330
constexpr unsigned int RejectChannelStart = 0x10059330;
// R6GameService.dll code @ 10059340
constexpr unsigned int ReadAssociatedProviderReady = 0x10059340;
// R6GameService.dll code @ 10059350
constexpr unsigned int clSRPGSConnectTakeMessage = 0x10059350;
// R6GameService.dll code @ 10059390
constexpr unsigned int DrainProviderSendQueue = 0x10059390;
// R6GameService.dll code @ 10059410
constexpr unsigned int DecodeProviderReceiveFrames = 0x10059410;
// R6GameService.dll code @ 100595f0
constexpr unsigned int clSRPGSClientConstruct = 0x100595f0;
// R6GameService.dll code @ 100596a0
constexpr unsigned int clSRPGSClientDelete = 0x100596a0;
// R6GameService.dll code @ 100596c0
constexpr unsigned int clSRPGSClientDestroy = 0x100596c0;
// R6GameService.dll code @ 100596d0
constexpr unsigned int OpenSRPGSClient = 0x100596d0;
// R6GameService.dll code @ 10059730
constexpr unsigned int RejectSRProtocolCall = 0x10059730;
// R6GameService.dll code @ 10059740
constexpr unsigned int clSRProtocol_RejectSRProtocolCall = 0x10059740;
// R6GameService.dll code @ 10059750
constexpr unsigned int clSRProtocol_RejectSRProtocolCall2 = 0x10059750;
// R6GameService.dll code @ 10059760
constexpr unsigned int clSRPClientDelete = 0x10059760;
// R6GameService.dll code @ 10059780
constexpr unsigned int clSRPClientDestroy = 0x10059780;
// R6GameService.dll code @ 10059790
constexpr unsigned int ReadHeaderSize24 = 0x10059790;
// R6GameService.dll code @ 100597c0
constexpr unsigned int ReadHeaderByte3HighBits = 0x100597c0;
// R6GameService.dll code @ 100597d0
constexpr unsigned int ReadHeaderByte3LowBits = 0x100597d0;
// R6GameService.dll code @ 100597e0
constexpr unsigned int ReadHeaderByte4 = 0x100597e0;
// R6GameService.dll code @ 100597f0
constexpr unsigned int ReadHeaderByte5HighNibble = 0x100597f0;
// R6GameService.dll code @ 10059800
constexpr unsigned int ReadHeaderByte5LowNibble = 0x10059800;
// R6GameService.dll code @ 10059810
constexpr unsigned int ReadHeaderWord5 = 0x10059810;
// R6GameService.dll code @ 10059820
constexpr unsigned int WriteHeaderSize24 = 0x10059820;
// R6GameService.dll code @ 10059850
constexpr unsigned int WriteHeaderByte3HighBits = 0x10059850;
// R6GameService.dll code @ 10059870
constexpr unsigned int SetHeaderByte3Bit5 = 0x10059870;
// R6GameService.dll code @ 10059890
constexpr unsigned int WriteHeaderByte4 = 0x10059890;
// R6GameService.dll code @ 100598a0
constexpr unsigned int WriteHeaderByte5HighNibble = 0x100598a0;
// R6GameService.dll code @ 100598c0
constexpr unsigned int WriteHeaderByte5LowNibble = 0x100598c0;
// R6GameService.dll code @ 100598e0
constexpr unsigned int WriteHeaderWord5 = 0x100598e0;
// R6GameService.dll code @ 100598f0
constexpr unsigned int IsEncodedHeaderSizeValid = 0x100598f0;
// R6GameService.dll code @ 10059940
constexpr unsigned int ConstructClGSMessage = 0x10059940;
// R6GameService.dll code @ 10059a50
constexpr unsigned int DeleteClGSMessage = 0x10059a50;
// R6GameService.dll code @ 10059a70
constexpr unsigned int InitializeClGSMessageFields = 0x10059a70;
// R6GameService.dll code @ 10059ab0
constexpr unsigned int DestroyClGSMessage = 0x10059ab0;
// R6GameService.dll code @ 10059b00
constexpr unsigned int SerializePayloadRecord = 0x10059b00;
// R6GameService.dll code @ 10059d40
constexpr unsigned int EncodeMessagePayload = 0x10059d40;
// R6GameService.dll code @ 10059d70
constexpr unsigned int DecodeMessagePayload = 0x10059d70;
// R6GameService.dll code @ 10059da0
constexpr unsigned int DecodePayloadRecord = 0x10059da0;
// R6GameService.dll code @ 1005a030
constexpr unsigned int FormatWordAsDecimal = 0x1005a030;
// R6GameService.dll code @ 1005a050
constexpr unsigned int FormatByteLabel = 0x1005a050;
// R6GameService.dll interior-code @ 1005a077
constexpr unsigned int GMessageLabelTargetsCase36 = 0x1005a077;
// R6GameService.dll interior-code @ 1005a08f
constexpr unsigned int GMessageLabelTargetsCase35 = 0x1005a08f;
// R6GameService.dll interior-code @ 1005a0a7
constexpr unsigned int GMessageLabelTargetsCase27 = 0x1005a0a7;
// R6GameService.dll interior-code @ 1005a0bf
constexpr unsigned int GMessageLabelTargetsCase28 = 0x1005a0bf;
// R6GameService.dll interior-code @ 1005a0d7
constexpr unsigned int GMessageLabelTargetsCase1 = 0x1005a0d7;
// R6GameService.dll interior-code @ 1005a0ef
constexpr unsigned int GMessageLabelTargetsCase2 = 0x1005a0ef;
// R6GameService.dll interior-code @ 1005a107
constexpr unsigned int GMessageLabelTargetsCase3 = 0x1005a107;
// R6GameService.dll interior-code @ 1005a11f
constexpr unsigned int GMessageLabelTargetsCase4 = 0x1005a11f;
// R6GameService.dll interior-code @ 1005a137
constexpr unsigned int GMessageLabelTargetsCase5 = 0x1005a137;
// R6GameService.dll interior-code @ 1005a14f
constexpr unsigned int GMessageLabelTargetsCase6 = 0x1005a14f;
// R6GameService.dll interior-code @ 1005a167
constexpr unsigned int GMessageLabelTargetsCase7 = 0x1005a167;
// R6GameService.dll interior-code @ 1005a17f
constexpr unsigned int GMessageLabelTargetsCase8 = 0x1005a17f;
// R6GameService.dll interior-code @ 1005a197
constexpr unsigned int GMessageLabelTargetsCase9 = 0x1005a197;
// R6GameService.dll interior-code @ 1005a1af
constexpr unsigned int GMessageLabelTargetsCase88 = 0x1005a1af;
// R6GameService.dll interior-code @ 1005a1c7
constexpr unsigned int GMessageLabelTargetsCase15 = 0x1005a1c7;
// R6GameService.dll interior-code @ 1005a1df
constexpr unsigned int GMessageLabelTargetsCase10 = 0x1005a1df;
// R6GameService.dll interior-code @ 1005a1f7
constexpr unsigned int GMessageLabelTargetsCase11 = 0x1005a1f7;
// R6GameService.dll interior-code @ 1005a20f
constexpr unsigned int GMessageLabelTargetsCase34 = 0x1005a20f;
// R6GameService.dll interior-code @ 1005a227
constexpr unsigned int GMessageLabelTargetsCase19 = 0x1005a227;
// R6GameService.dll interior-code @ 1005a23f
constexpr unsigned int GMessageLabelTargetsCase16 = 0x1005a23f;
// R6GameService.dll interior-code @ 1005a257
constexpr unsigned int GMessageLabelTargetsCase18 = 0x1005a257;
// R6GameService.dll interior-code @ 1005a26f
constexpr unsigned int GMessageLabelTargetsCase17 = 0x1005a26f;
// R6GameService.dll interior-code @ 1005a287
constexpr unsigned int GMessageLabelTargetsCase20 = 0x1005a287;
// R6GameService.dll interior-code @ 1005a29f
constexpr unsigned int GMessageLabelTargetsCase21 = 0x1005a29f;
// R6GameService.dll interior-code @ 1005a2b7
constexpr unsigned int GMessageLabelTargetsCase22 = 0x1005a2b7;
// R6GameService.dll interior-code @ 1005a2cf
constexpr unsigned int GMessageLabelTargetsCase23 = 0x1005a2cf;
// R6GameService.dll interior-code @ 1005a2e7
constexpr unsigned int GMessageLabelTargetsCase24 = 0x1005a2e7;
// R6GameService.dll interior-code @ 1005a2ff
constexpr unsigned int GMessageLabelTargetsCase25 = 0x1005a2ff;
// R6GameService.dll interior-code @ 1005a317
constexpr unsigned int GMessageLabelTargetsCase26 = 0x1005a317;
// R6GameService.dll interior-code @ 1005a32f
constexpr unsigned int GMessageLabelTargetsCase37 = 0x1005a32f;
// R6GameService.dll interior-code @ 1005a347
constexpr unsigned int GMessageLabelTargetsCase30 = 0x1005a347;
// R6GameService.dll interior-code @ 1005a35f
constexpr unsigned int GMessageLabelTargetsCase12 = 0x1005a35f;
// R6GameService.dll interior-code @ 1005a377
constexpr unsigned int GMessageLabelTargetsCase13 = 0x1005a377;
// R6GameService.dll interior-code @ 1005a38f
constexpr unsigned int GMessageLabelTargetsCase14 = 0x1005a38f;
// R6GameService.dll interior-code @ 1005a3a7
constexpr unsigned int GMessageLabelTargetsCase74 = 0x1005a3a7;
// R6GameService.dll interior-code @ 1005a3bf
constexpr unsigned int GMessageLabelTargetsCase75 = 0x1005a3bf;
// R6GameService.dll interior-code @ 1005a3d7
constexpr unsigned int GMessageLabelTargetsCase76 = 0x1005a3d7;
// R6GameService.dll interior-code @ 1005a3ef
constexpr unsigned int GMessageLabelTargetsCase29 = 0x1005a3ef;
// R6GameService.dll interior-code @ 1005a407
constexpr unsigned int GMessageLabelTargetsCase124 = 0x1005a407;
// R6GameService.dll interior-code @ 1005a41f
constexpr unsigned int GMessageLabelTargetsCase77 = 0x1005a41f;
// R6GameService.dll interior-code @ 1005a437
constexpr unsigned int GMessageLabelTargetsCase78 = 0x1005a437;
// R6GameService.dll interior-code @ 1005a44f
constexpr unsigned int GMessageLabelTargetsCase79 = 0x1005a44f;
// R6GameService.dll interior-code @ 1005a467
constexpr unsigned int GMessageLabelTargetsCase80 = 0x1005a467;
// R6GameService.dll interior-code @ 1005a47f
constexpr unsigned int GMessageLabelTargetsCase81 = 0x1005a47f;
// R6GameService.dll interior-code @ 1005a497
constexpr unsigned int GMessageLabelTargetsCase31 = 0x1005a497;
// R6GameService.dll interior-code @ 1005a4af
constexpr unsigned int GMessageLabelTargetsCase32 = 0x1005a4af;
// R6GameService.dll interior-code @ 1005a4c7
constexpr unsigned int GMessageLabelTargetsCase104 = 0x1005a4c7;
// R6GameService.dll interior-code @ 1005a4df
constexpr unsigned int GMessageLabelTargetsCase123 = 0x1005a4df;
// R6GameService.dll interior-code @ 1005a4f7
constexpr unsigned int GMessageLabelTargetsCase82 = 0x1005a4f7;
// R6GameService.dll interior-code @ 1005a50f
constexpr unsigned int GMessageLabelTargetsCase84 = 0x1005a50f;
// R6GameService.dll interior-code @ 1005a527
constexpr unsigned int GMessageLabelTargetsCase83 = 0x1005a527;
// R6GameService.dll interior-code @ 1005a53f
constexpr unsigned int GMessageLabelTargetsCase85 = 0x1005a53f;
// R6GameService.dll interior-code @ 1005a557
constexpr unsigned int GMessageLabelTargetsCase86 = 0x1005a557;
// R6GameService.dll interior-code @ 1005a56f
constexpr unsigned int GMessageLabelTargetsCase87 = 0x1005a56f;
// R6GameService.dll interior-code @ 1005a587
constexpr unsigned int GMessageLabelTargetsCase38 = 0x1005a587;
// R6GameService.dll interior-code @ 1005a59f
constexpr unsigned int GMessageLabelTargetsCase39 = 0x1005a59f;
// R6GameService.dll interior-code @ 1005a5b7
constexpr unsigned int GMessageLabelTargetsCase40 = 0x1005a5b7;
// R6GameService.dll interior-code @ 1005a5cf
constexpr unsigned int GMessageLabelTargetsCase41 = 0x1005a5cf;
// R6GameService.dll interior-code @ 1005a5e7
constexpr unsigned int GMessageLabelTargetsCase42 = 0x1005a5e7;
// R6GameService.dll interior-code @ 1005a5ff
constexpr unsigned int GMessageLabelTargetsCase43 = 0x1005a5ff;
// R6GameService.dll interior-code @ 1005a617
constexpr unsigned int GMessageLabelTargetsCase44 = 0x1005a617;
// R6GameService.dll interior-code @ 1005a62f
constexpr unsigned int GMessageLabelTargetsCase45 = 0x1005a62f;
// R6GameService.dll interior-code @ 1005a647
constexpr unsigned int GMessageLabelTargetsCase47 = 0x1005a647;
// R6GameService.dll interior-code @ 1005a65f
constexpr unsigned int GMessageLabelTargetsCase46 = 0x1005a65f;
// R6GameService.dll interior-code @ 1005a677
constexpr unsigned int GMessageLabelTargetsCase49 = 0x1005a677;
// R6GameService.dll interior-code @ 1005a68f
constexpr unsigned int GMessageLabelTargetsCase50 = 0x1005a68f;
// R6GameService.dll interior-code @ 1005a6a7
constexpr unsigned int GMessageLabelTargetsCase33 = 0x1005a6a7;
// R6GameService.dll interior-code @ 1005a6bf
constexpr unsigned int GMessageLabelTargetsCase51 = 0x1005a6bf;
// R6GameService.dll interior-code @ 1005a6d7
constexpr unsigned int GMessageLabelTargetsCase52 = 0x1005a6d7;
// R6GameService.dll interior-code @ 1005a6ef
constexpr unsigned int GMessageLabelTargetsCase53 = 0x1005a6ef;
// R6GameService.dll interior-code @ 1005a707
constexpr unsigned int GMessageLabelTargetsCase54 = 0x1005a707;
// R6GameService.dll interior-code @ 1005a71f
constexpr unsigned int GMessageLabelTargetsCase55 = 0x1005a71f;
// R6GameService.dll interior-code @ 1005a737
constexpr unsigned int GMessageLabelTargetsCase56 = 0x1005a737;
// R6GameService.dll interior-code @ 1005a74f
constexpr unsigned int GMessageLabelTargetsCase57 = 0x1005a74f;
// R6GameService.dll interior-code @ 1005a767
constexpr unsigned int GMessageLabelTargetsCase58 = 0x1005a767;
// R6GameService.dll interior-code @ 1005a77f
constexpr unsigned int GMessageLabelTargetsCase59 = 0x1005a77f;
// R6GameService.dll interior-code @ 1005a797
constexpr unsigned int GMessageLabelTargetsCase60 = 0x1005a797;
// R6GameService.dll interior-code @ 1005a7af
constexpr unsigned int GMessageLabelTargetsCase61 = 0x1005a7af;
// R6GameService.dll interior-code @ 1005a7c7
constexpr unsigned int GMessageLabelTargetsCase62 = 0x1005a7c7;
// R6GameService.dll interior-code @ 1005a7df
constexpr unsigned int GMessageLabelTargetsCase63 = 0x1005a7df;
// R6GameService.dll interior-code @ 1005a7f7
constexpr unsigned int GMessageLabelTargetsCase64 = 0x1005a7f7;
// R6GameService.dll interior-code @ 1005a80f
constexpr unsigned int GMessageLabelTargetsCase65 = 0x1005a80f;
// R6GameService.dll interior-code @ 1005a827
constexpr unsigned int GMessageLabelTargetsCase66 = 0x1005a827;
// R6GameService.dll interior-code @ 1005a83f
constexpr unsigned int GMessageLabelTargetsCase67 = 0x1005a83f;
// R6GameService.dll interior-code @ 1005a857
constexpr unsigned int GMessageLabelTargetsCase68 = 0x1005a857;
// R6GameService.dll interior-code @ 1005a86f
constexpr unsigned int GMessageLabelTargetsCase69 = 0x1005a86f;
// R6GameService.dll interior-code @ 1005a887
constexpr unsigned int GMessageLabelTargetsCase70 = 0x1005a887;
// R6GameService.dll interior-code @ 1005a89f
constexpr unsigned int GMessageLabelTargetsCase71 = 0x1005a89f;
// R6GameService.dll interior-code @ 1005a8b7
constexpr unsigned int GMessageLabelTargetsCase72 = 0x1005a8b7;
// R6GameService.dll interior-code @ 1005a8cf
constexpr unsigned int GMessageLabelTargetsCase91 = 0x1005a8cf;
// R6GameService.dll interior-code @ 1005a8e7
constexpr unsigned int GMessageLabelTargetsCase99 = 0x1005a8e7;
// R6GameService.dll interior-code @ 1005a8ff
constexpr unsigned int GMessageLabelTargetsCase100 = 0x1005a8ff;
// R6GameService.dll interior-code @ 1005a917
constexpr unsigned int GMessageLabelTargetsCase101 = 0x1005a917;
// R6GameService.dll interior-code @ 1005a92f
constexpr unsigned int GMessageLabelTargetsCase102 = 0x1005a92f;
// R6GameService.dll interior-code @ 1005a947
constexpr unsigned int GMessageLabelTargetsCase89 = 0x1005a947;
// R6GameService.dll interior-code @ 1005a95f
constexpr unsigned int GMessageLabelTargetsCase90 = 0x1005a95f;
// R6GameService.dll interior-code @ 1005a977
constexpr unsigned int GMessageLabelTargetsCase73 = 0x1005a977;
// R6GameService.dll interior-code @ 1005a98f
constexpr unsigned int GMessageLabelTargetsCase92 = 0x1005a98f;
// R6GameService.dll interior-code @ 1005a9a7
constexpr unsigned int GMessageLabelTargetsCase93 = 0x1005a9a7;
// R6GameService.dll interior-code @ 1005a9bf
constexpr unsigned int GMessageLabelTargetsCase94 = 0x1005a9bf;
// R6GameService.dll interior-code @ 1005a9d7
constexpr unsigned int GMessageLabelTargetsCase95 = 0x1005a9d7;
// R6GameService.dll interior-code @ 1005a9ef
constexpr unsigned int GMessageLabelTargetsCase96 = 0x1005a9ef;
// R6GameService.dll interior-code @ 1005aa07
constexpr unsigned int GMessageLabelTargetsCase97 = 0x1005aa07;
// R6GameService.dll interior-code @ 1005aa1f
constexpr unsigned int GMessageLabelTargetsCase98 = 0x1005aa1f;
// R6GameService.dll interior-code @ 1005aa37
constexpr unsigned int GMessageLabelTargetsCase103 = 0x1005aa37;
// R6GameService.dll interior-code @ 1005aa4f
constexpr unsigned int GMessageLabelTargetsCase107 = 0x1005aa4f;
// R6GameService.dll interior-code @ 1005aa67
constexpr unsigned int GMessageLabelTargetsCase105 = 0x1005aa67;
// R6GameService.dll interior-code @ 1005aa7f
constexpr unsigned int GMessageLabelTargetsCase109 = 0x1005aa7f;
// R6GameService.dll interior-code @ 1005aa97
constexpr unsigned int GMessageLabelTargetsCase106 = 0x1005aa97;
// R6GameService.dll interior-code @ 1005aaaf
constexpr unsigned int GMessageLabelTargetsCase108 = 0x1005aaaf;
// R6GameService.dll interior-code @ 1005aac7
constexpr unsigned int GMessageLabelTargetsCase111 = 0x1005aac7;
// R6GameService.dll interior-code @ 1005aadf
constexpr unsigned int GMessageLabelTargetsCase112 = 0x1005aadf;
// R6GameService.dll interior-code @ 1005aaf7
constexpr unsigned int GMessageLabelTargetsCase113 = 0x1005aaf7;
// R6GameService.dll interior-code @ 1005ab0f
constexpr unsigned int GMessageLabelTargetsCase114 = 0x1005ab0f;
// R6GameService.dll interior-code @ 1005ab27
constexpr unsigned int GMessageLabelTargetsCase115 = 0x1005ab27;
// R6GameService.dll interior-code @ 1005ab3f
constexpr unsigned int GMessageLabelTargetsCase110 = 0x1005ab3f;
// R6GameService.dll interior-code @ 1005ab57
constexpr unsigned int GMessageLabelTargetsCase122 = 0x1005ab57;
// R6GameService.dll interior-code @ 1005ab6f
constexpr unsigned int GMessageLabelTargetsCase48 = 0x1005ab6f;
// R6GameService.dll interior-code @ 1005ab87
constexpr unsigned int GMessageLabelTargetsCase121 = 0x1005ab87;
// R6GameService.dll interior-code @ 1005ab9f
constexpr unsigned int GMessageLabelTargetsCase128 = 0x1005ab9f;
// R6GameService.dll interior-code @ 1005abb7
constexpr unsigned int GMessageLabelTargetsCase127 = 0x1005abb7;
// R6GameService.dll interior-code @ 1005abcf
constexpr unsigned int GMessageLabelTargetsCase116 = 0x1005abcf;
// R6GameService.dll interior-code @ 1005abe7
constexpr unsigned int GMessageLabelTargetsCase117 = 0x1005abe7;
// R6GameService.dll interior-code @ 1005abff
constexpr unsigned int GMessageLabelTargetsCase118 = 0x1005abff;
// R6GameService.dll interior-code @ 1005ac17
constexpr unsigned int GMessageLabelTargetsCase119 = 0x1005ac17;
// R6GameService.dll interior-code @ 1005ac2f
constexpr unsigned int GMessageLabelTargetsCase120 = 0x1005ac2f;
// R6GameService.dll interior-code @ 1005ac47
constexpr unsigned int GMessageLabelTargetsCase125 = 0x1005ac47;
// R6GameService.dll interior-code @ 1005ac5f
constexpr unsigned int GMessageLabelTargetsCase126 = 0x1005ac5f;
// R6GameService.dll interior-code @ 1005ac77
constexpr unsigned int GMessageLabelTargetsCase129 = 0x1005ac77;
// R6GameService.dll code @ 1005af70
constexpr unsigned int PrintDecodedRecord = 0x1005af70;
// R6GameService.dll code @ 1005b350
constexpr unsigned int AppendDecodedRecordText = 0x1005b350;
// R6GameService.dll code @ 1005b830
constexpr unsigned int ConstructPayloadRecord = 0x1005b830;
// R6GameService.dll code @ 1005b8b0
constexpr unsigned int clGameMessageDelete = 0x1005b8b0;
// R6GameService.dll code @ 1005b8d0
constexpr unsigned int clGameMessageCopyConstruct = 0x1005b8d0;
// R6GameService.dll code @ 1005b950
constexpr unsigned int InitializeClGameMessageFields = 0x1005b950;
// R6GameService.dll code @ 1005b990
constexpr unsigned int clGameMessageDestroy = 0x1005b990;
// R6GameService.dll code @ 1005b9b0
constexpr unsigned int SerializeRawPayloadRecord = 0x1005b9b0;
// R6GameService.dll code @ 1005baa0
constexpr unsigned int CopyOrQueryPayloadBytes = 0x1005baa0;
// R6GameService.dll code @ 1005bae0
constexpr unsigned int ParseHeaderAndPayload = 0x1005bae0;
// R6GameService.dll code @ 1005bb60
constexpr unsigned int FormatSendTarget = 0x1005bb60;
// R6GameService.dll interior-code @ 1005bb78
constexpr unsigned int message_label_supportGGameDiagnosticTargetsCase5 = 0x1005bb78;
// R6GameService.dll interior-code @ 1005bb8d
constexpr unsigned int message_label_supportGGameDiagnosticTargetsCase1 = 0x1005bb8d;
// R6GameService.dll interior-code @ 1005bba2
constexpr unsigned int message_label_supportGGameDiagnosticTargetsCase2 = 0x1005bba2;
// R6GameService.dll interior-code @ 1005bbb7
constexpr unsigned int message_label_supportGGameDiagnosticTargetsCase3 = 0x1005bbb7;
// R6GameService.dll interior-code @ 1005bbcc
constexpr unsigned int message_label_supportGGameDiagnosticTargetsCase4 = 0x1005bbcc;
// R6GameService.dll data @ 1005bbf8
constexpr unsigned int message_label_supportGGameDiagnosticTargets = 0x1005bbf8;
// R6GameService.dll code @ 1005bc10
constexpr unsigned int FormatPayloadEvent = 0x1005bc10;
// R6GameService.dll interior-code @ 1005bc2d
constexpr unsigned int GGameDiagnosticTargetsCase12 = 0x1005bc2d;
// R6GameService.dll interior-code @ 1005bc42
constexpr unsigned int GGameDiagnosticTargetsCase11 = 0x1005bc42;
// R6GameService.dll interior-code @ 1005bc57
constexpr unsigned int GGameDiagnosticTargetsCase5 = 0x1005bc57;
// R6GameService.dll interior-code @ 1005bc6c
constexpr unsigned int GGameDiagnosticTargetsCase4 = 0x1005bc6c;
// R6GameService.dll interior-code @ 1005bc81
constexpr unsigned int GGameDiagnosticTargetsCase3 = 0x1005bc81;
// R6GameService.dll interior-code @ 1005bc96
constexpr unsigned int GGameDiagnosticTargetsCase2 = 0x1005bc96;
// R6GameService.dll interior-code @ 1005bcab
constexpr unsigned int GGameDiagnosticTargetsCase1 = 0x1005bcab;
// R6GameService.dll interior-code @ 1005bcc0
constexpr unsigned int clGameMessageBranch9 = 0x1005bcc0;
// R6GameService.dll data @ 1005bcd8
constexpr unsigned int GGameDiagnosticTargets = 0x1005bcd8;
// R6GameService.dll code @ 1005bd10
constexpr unsigned int PrintPayloadRecordDiagnostic = 0x1005bd10;
// R6GameService.dll code @ 1005bdb0
constexpr unsigned int AppendPayloadRecordDiagnostic = 0x1005bdb0;
// R6GameService.dll code @ 1005c000
constexpr unsigned int ConstructClGSEncryptMessage = 0x1005c000;
// R6GameService.dll code @ 1005c060
constexpr unsigned int DeleteClGSEncryptMessage = 0x1005c060;
// R6GameService.dll code @ 1005c080
constexpr unsigned int DestroyClGSEncryptMessage = 0x1005c080;
// R6GameService.dll code @ 1005c090
constexpr unsigned int InitializeClGSEncryptMessageFields = 0x1005c090;
// R6GameService.dll code @ 1005c0d0
constexpr unsigned int DispatchEncryptedMessageSlot0C = 0x1005c0d0;
// R6GameService.dll code @ 1005c100
constexpr unsigned int DispatchEncryptedMessageSlot10 = 0x1005c100;
// R6GameService.dll code @ 1005c130
constexpr unsigned int ResetClMessageVtable = 0x1005c130;
// R6GameService.dll code @ 1005c140
constexpr unsigned int shared_native_NoOp = 0x1005c140;
// R6GameService.dll code @ 1005c150
constexpr unsigned int DeleteClMessage = 0x1005c150;
// R6GameService.dll code @ 1005c170
constexpr unsigned int ConstructSharedCryptoContext = 0x1005c170;
// R6GameService.dll code @ 1005c2c0
constexpr unsigned int DestroySharedCryptoContext = 0x1005c2c0;
// R6GameService.dll code @ 1005c340
constexpr unsigned int DispatchSharedSlot8 = 0x1005c340;
// R6GameService.dll code @ 1005c380
constexpr unsigned int DispatchSharedSlot14 = 0x1005c380;
// R6GameService.dll code @ 1005c3b0
constexpr unsigned int DispatchThroughSelectedSlot0C = 0x1005c3b0;
// R6GameService.dll code @ 1005c410
constexpr unsigned int DispatchThroughSelectedSlot10 = 0x1005c410;
// R6GameService.dll code @ 1005c470
constexpr unsigned int CopyGlobalWordTablePrefix = 0x1005c470;
// R6GameService.dll code @ 1005c490
constexpr unsigned int ReplaceSharedByteBuffer = 0x1005c490;
// R6GameService.dll code @ 1005c500
constexpr unsigned int InitializeSharedServiceTables = 0x1005c500;
// R6GameService.dll code @ 1005c570
constexpr unsigned int FreeSharedContextBuffers = 0x1005c570;
// R6GameService.dll code @ 1005c5d0
constexpr unsigned int ResizeSharedContextBuffer = 0x1005c5d0;
// R6GameService.dll code @ 1005c620
constexpr unsigned int FinalizeSharedContextTables = 0x1005c620;
// R6GameService.dll code @ 1005c670
constexpr unsigned int PollAndForwardSharedRecords = 0x1005c670;
// R6GameService.dll code @ 1005c710
constexpr unsigned int InitializeCompactRecordHeader = 0x1005c710;
// R6GameService.dll code @ 1005c750
constexpr unsigned int DeleteOwnedObjectAtOffset8 = 0x1005c750;
// R6GameService.dll code @ 1005c760
constexpr unsigned int InitializeCompactRecordList = 0x1005c760;
// R6GameService.dll code @ 1005c7b0
constexpr unsigned int InsertOrReplaceCompactRecord = 0x1005c7b0;
// R6GameService.dll code @ 1005c990
constexpr unsigned int AttachCompactRecord = 0x1005c990;
// R6GameService.dll code @ 1005ca10
constexpr unsigned int RemoveFirstCompactRecord = 0x1005ca10;
// R6GameService.dll code @ 1005ca50
constexpr unsigned int InitializeCompactPayloadRecord = 0x1005ca50;
// R6GameService.dll code @ 1005caa0
constexpr unsigned int ReleaseCompactRecordBuffer = 0x1005caa0;
// R6GameService.dll code @ 1005cab0
constexpr unsigned int clSendMsgQueue_InitializeCompactRecordList = 0x1005cab0;
// R6GameService.dll code @ 1005cb00
constexpr unsigned int InsertOrReplaceCompactPayloadRecord = 0x1005cb00;
// R6GameService.dll code @ 1005cd00
constexpr unsigned int AppendCompactPayloadRecord = 0x1005cd00;
// R6GameService.dll code @ 1005cda0
constexpr unsigned int ConcatenateCompactPayloadsThroughLimit = 0x1005cda0;
// R6GameService.dll code @ 1005ce90
constexpr unsigned int DiscardConsumedCompactPayloads = 0x1005ce90;
// R6GameService.dll code @ 1005cee0
constexpr unsigned int InitializeLargeRecordOwnerState = 0x1005cee0;
// R6GameService.dll code @ 1005d0f0
constexpr unsigned int DeleteObject = 0x1005d0f0;
// R6GameService.dll code @ 1005d110
constexpr unsigned int thunk_DestroyEmbeddedOwnedRecords = 0x1005d110;
// R6GameService.dll code @ 1005d120
constexpr unsigned int ForwardSegmentedWordDestroy = 0x1005d120;
// R6GameService.dll code @ 1005d130
constexpr unsigned int ReleaseSegmentedWordStorage = 0x1005d130;
// R6GameService.dll code @ 1005d200
constexpr unsigned int DestroyLargeRecordOwner = 0x1005d200;
// R6GameService.dll code @ 1005d2e0
constexpr unsigned int ReadOwnerQueueBytes = 0x1005d2e0;
// R6GameService.dll code @ 1005d320
constexpr unsigned int AppendOwnerPendingBytes = 0x1005d320;
// R6GameService.dll code @ 1005d340
constexpr unsigned int RejectOwnerPendingBytes = 0x1005d340;
// R6GameService.dll code @ 1005d350
constexpr unsigned int ReturnZero = 0x1005d350;
// R6GameService.dll code @ 1005d360
constexpr unsigned int ProcessOwnerQueues = 0x1005d360;
// R6GameService.dll code @ 1005d380
constexpr unsigned int ReturnOwnerInactive = 0x1005d380;
// R6GameService.dll code @ 1005d390
constexpr unsigned int ProcessOwnerDeadline = 0x1005d390;
// R6GameService.dll code @ 1005d3e0
constexpr unsigned int ProcessOwnerConditionalQueues = 0x1005d3e0;
// R6GameService.dll code @ 1005d420
constexpr unsigned int BuildPendingOwnerRecords = 0x1005d420;
// R6GameService.dll code @ 1005d570
constexpr unsigned int SubmitExpiredOwnerRecords = 0x1005d570;
// R6GameService.dll code @ 1005d750
constexpr unsigned int SendOwnerWordReports = 0x1005d750;
// R6GameService.dll code @ 1005d990
constexpr unsigned int ProcessOwnerInputWithStateUpdate = 0x1005d990;
// R6GameService.dll code @ 1005dc60
constexpr unsigned int InitializeOwnedByteRecord = 0x1005dc60;
// R6GameService.dll code @ 1005dca0
constexpr unsigned int ProcessOwnerInputWithNegotiation = 0x1005dca0;
// R6GameService.dll code @ 1005df90
constexpr unsigned int DeleteClSegment = 0x1005df90;
// R6GameService.dll code @ 1005dfc0
constexpr unsigned int ComputeSeededRecordChecksum = 0x1005dfc0;
// R6GameService.dll code @ 1005e020
constexpr unsigned int ProcessOwnerInputWithCloseState = 0x1005e020;
// R6GameService.dll code @ 1005e350
constexpr unsigned int LoadOwnerNegotiationParameters = 0x1005e350;
// R6GameService.dll code @ 1005e400
constexpr unsigned int DeleteClSRPSegment = 0x1005e400;
// R6GameService.dll code @ 1005e420
constexpr unsigned int DestroyClSRPSegment = 0x1005e420;
// R6GameService.dll code @ 1005e430
constexpr unsigned int UpdateOwnerDeadlines = 0x1005e430;
// R6GameService.dll code @ 1005e5a0
constexpr unsigned int RestartOwnerProcessing = 0x1005e5a0;
// R6GameService.dll code @ 1005e5c0
constexpr unsigned int ResetProtocolCallback = 0x1005e5c0;
// R6GameService.dll code @ 1005e5d0
constexpr unsigned int SendTripleControlRecordAndResetDeadline = 0x1005e5d0;
// R6GameService.dll code @ 1005e6e0
constexpr unsigned int HandleOwnerRecordStatus = 0x1005e6e0;
// R6GameService.dll code @ 1005e720
constexpr unsigned int QueueOwnerStatusRecord = 0x1005e720;
// R6GameService.dll code @ 1005e810
constexpr unsigned int ConfigureOwnerStateFive = 0x1005e810;
// R6GameService.dll code @ 1005e890
constexpr unsigned int ClearOwnerQueuesAndReset = 0x1005e890;
// R6GameService.dll code @ 1005e9d0
constexpr unsigned int EnterOwnerActiveState = 0x1005e9d0;
// R6GameService.dll code @ 1005ea70
constexpr unsigned int BeginOwnerStateTwo = 0x1005ea70;
// R6GameService.dll code @ 1005eb00
constexpr unsigned int InitializeOwnerAndSendNegotiationRecord = 0x1005eb00;
// R6GameService.dll code @ 1005ecb0
constexpr unsigned int DestroyOwnedRecordVector = 0x1005ecb0;
// R6GameService.dll code @ 1005ed20
constexpr unsigned int AppendSegmentedWord = 0x1005ed20;
// R6GameService.dll code @ 1005ed50
constexpr unsigned int CopySegmentedCursor = 0x1005ed50;
// R6GameService.dll code @ 1005ed80
constexpr unsigned int EraseCircularNode = 0x1005ed80;
// R6GameService.dll code @ 1005eda0
constexpr unsigned int InitializeSegmentedWords = 0x1005eda0;
// R6GameService.dll code @ 1005ee10
constexpr unsigned int DestroyOwnedRecordObject = 0x1005ee10;
// R6GameService.dll code @ 1005ee20
constexpr unsigned int ReplaceOwnedRecordObject = 0x1005ee20;
// R6GameService.dll code @ 1005ee50
constexpr unsigned int DestroyEmbeddedOwnedRecords = 0x1005ee50;
// R6GameService.dll code @ 1005eeb0
constexpr unsigned int ResizeOwnedRecordArray = 0x1005eeb0;
// R6GameService.dll code @ 1005f0b0
constexpr unsigned int ResetOwnedRecordRing = 0x1005f0b0;
// R6GameService.dll code @ 1005f1d0
constexpr unsigned int IsOwnerRecordIndexAccepted = 0x1005f1d0;
// R6GameService.dll code @ 1005f220
constexpr unsigned int PopOwnedRingRecord = 0x1005f220;
// R6GameService.dll code @ 1005f280
constexpr unsigned int InsertRepeatedOwnedRecords = 0x1005f280;
// R6GameService.dll code @ 1005f480
constexpr unsigned int ReleaseSegmentedWordBlocks = 0x1005f480;
// R6GameService.dll code @ 1005f4c0
constexpr unsigned int InitializeSegmentedWordBuffer = 0x1005f4c0;
// R6GameService.dll code @ 1005f57e
constexpr unsigned int segmented_word_supportCatch = 0x1005f57e;
// R6GameService.dll code @ 1005f5a0
constexpr unsigned int AppendWordAndAllocateNextBlock = 0x1005f5a0;
// R6GameService.dll code @ 1005f610
constexpr unsigned int ReallocateAndInsertOwnedRecords = 0x1005f610;
// R6GameService.dll code @ 1005f737
constexpr unsigned int owned_record_array_supportCatch = 0x1005f737;
// R6GameService.dll code @ 1005f770
constexpr unsigned int CopyRawRecordRange = 0x1005f770;
// R6GameService.dll code @ 1005f7b0
constexpr unsigned int AssignOwnedRecordFill = 0x1005f7b0;
// R6GameService.dll code @ 1005f7f0
constexpr unsigned int ForwardRepeatedRecordFill = 0x1005f7f0;
// R6GameService.dll code @ 1005f820
constexpr unsigned int AllocateSegmentedWordBlocks = 0x1005f820;
// R6GameService.dll code @ 1005f850
constexpr unsigned int RecenterSegmentedWordBlockMap = 0x1005f850;
// R6GameService.dll code @ 1005f980
constexpr unsigned int AssignOwnedRecordsForward = 0x1005f980;
// R6GameService.dll code @ 1005f9e0
constexpr unsigned int ConstructRepeatedRawRecords = 0x1005f9e0;
// R6GameService.dll code @ 1005fa20
constexpr unsigned int AssignOwnedRecordsBackward = 0x1005fa20;
// R6GameService.dll code @ 1005fa80
constexpr unsigned int DeleteOwnedObjectRecord = 0x1005fa80;
// R6GameService.dll code @ 1005fab0
constexpr unsigned int InitializeRecordOwnerStorage = 0x1005fab0;
// R6GameService.dll code @ 1005fb50
constexpr unsigned int clBasicProtocol_DeleteObject = 0x1005fb50;
// R6GameService.dll code @ 1005fb70
constexpr unsigned int DestroyRecordOwnerStorage = 0x1005fb70;
// R6GameService.dll code @ 1005fc30
constexpr unsigned int AppendOwnedRecord = 0x1005fc30;
// R6GameService.dll code @ 1005fc70
constexpr unsigned int ClearRecordOwnerMembers = 0x1005fc70;
// R6GameService.dll code @ 1005fd50
constexpr unsigned int SetIPv4AddressAndFormatText = 0x1005fd50;
// R6GameService.dll code @ 1005fdb0
constexpr unsigned int FindOrCreateKeyedRecord = 0x1005fdb0;
// R6GameService.dll code @ 10060050
constexpr unsigned int TakeNextAvailableId = 0x10060050;
// R6GameService.dll code @ 100600f0
constexpr unsigned int RemoveKeyAndRecycleOrDestroy = 0x100600f0;
// R6GameService.dll code @ 100601a0
constexpr unsigned int InitializeKeyedRecord = 0x100601a0;
// R6GameService.dll code @ 100602b0
constexpr unsigned int ForwardBucketCleanup = 0x100602b0;
// R6GameService.dll code @ 100602c0
constexpr unsigned int ForwardClSegmentPointerDequeDestroy = 0x100602c0;
// R6GameService.dll code @ 100602d0
constexpr unsigned int DeleteClSegmentPointerDeque = 0x100602d0;
// R6GameService.dll code @ 100602f0
constexpr unsigned int DestroyKeyedRecordStorage = 0x100602f0;
// R6GameService.dll code @ 10060410
constexpr unsigned int ReleaseSegmentedDwordBufferBlocks = 0x10060410;
// R6GameService.dll code @ 100604e0
constexpr unsigned int EnsureReceiveBufferCapacity = 0x100604e0;
// R6GameService.dll code @ 10060540
constexpr unsigned int OpenAndBindRecordSocket = 0x10060540;
// R6GameService.dll code @ 10060610
constexpr unsigned int SendKeyedRecordPayload = 0x10060610;
// R6GameService.dll code @ 10060660
constexpr unsigned int ReceiveAndQueueKeyedDatagrams = 0x10060660;
// R6GameService.dll code @ 10060750
constexpr unsigned int DestroyClSegmentPointerDeque = 0x10060750;
// R6GameService.dll code @ 10060900
constexpr unsigned int DestroyBucketChains = 0x10060900;
// R6GameService.dll code @ 10060960
constexpr unsigned int CopyWordsToOutput = 0x10060960;
// R6GameService.dll code @ 10060990
constexpr unsigned int InitializeKeyedRecordIndex = 0x10060990;
// R6GameService.dll code @ 10060a50
constexpr unsigned int GetFirstNonemptyBucketIterator = 0x10060a50;
// R6GameService.dll code @ 10060ab0
constexpr unsigned int EraseSegmentedObjectRange = 0x10060ab0;
// R6GameService.dll code @ 10060e30
constexpr unsigned int InitializeSegmentedDwordBuffer = 0x10060e30;
// R6GameService.dll code @ 10060ea0
constexpr unsigned int MeasureSegmentedDwordCursorDistance = 0x10060ea0;
// R6GameService.dll code @ 10060ee0
constexpr unsigned int AppendSelectedBucketSlotsAndResetCount = 0x10060ee0;
// R6GameService.dll code @ 100610d0
constexpr unsigned int MoveByteRangeToEnd = 0x100610d0;
// R6GameService.dll code @ 10061100
constexpr unsigned int FindOrInsert16BitKeyNode = 0x10061100;
// R6GameService.dll code @ 10061190
constexpr unsigned int Clear16BitKeyBuckets = 0x10061190;
// R6GameService.dll code @ 100611e0
constexpr unsigned int InitializeSegmentedDwordBufferStorage = 0x100611e0;
// R6GameService.dll code @ 1006129e
constexpr unsigned int segmented_pointer_supportCatch = 0x1006129e;
// R6GameService.dll code @ 100612c0
constexpr unsigned int EraseSegmentedDwordRange = 0x100612c0;
// R6GameService.dll code @ 10061680
constexpr unsigned int EnsurePointerArrayCapacity = 0x10061680;
// R6GameService.dll code @ 100616e0
constexpr unsigned int InsertRepeatedPointerValue = 0x100616e0;
// R6GameService.dll code @ 100618a0
constexpr unsigned int FindNextNonemptyBucket = 0x100618a0;
// R6GameService.dll code @ 100618e0
constexpr unsigned int RemoveAllNodesForKey = 0x100618e0;
// R6GameService.dll code @ 10061970
constexpr unsigned int Rehash16BitKeyTable = 0x10061970;
// R6GameService.dll code @ 10061aa0
constexpr unsigned int ReleaseNonNullFirstWordBuffer = 0x10061aa0;
// R6GameService.dll code @ 10061ab0
constexpr unsigned int CopyByValueCursorArgumentsToScratch = 0x10061ab0;
// R6GameService.dll code @ 10061b00
constexpr unsigned int FindKeyIterator = 0x10061b00;
// R6GameService.dll code @ 10061b50
constexpr unsigned int RebuildPointerArrayWithRepeatedValue = 0x10061b50;
// R6GameService.dll code @ 10061c10
constexpr unsigned int AddSegmentedDwordCursorOffset = 0x10061c10;
// R6GameService.dll code @ 10061c80
constexpr unsigned int SubtractSegmentedDwordCursorOffset = 0x10061c80;
// R6GameService.dll code @ 10061d00
constexpr unsigned int ReleaseMemoryIgnoringSize = 0x10061d00;
// R6GameService.dll code @ 10061d10
constexpr unsigned int AllocateWordKeyNode = 0x10061d10;
// R6GameService.dll code @ 10061d40
constexpr unsigned int InitializeDwordBufferWithCapacity = 0x10061d40;
// R6GameService.dll code @ 10061d70
constexpr unsigned int AdvanceSegmentedDwordCursor = 0x10061d70;
// R6GameService.dll code @ 10061de0
constexpr unsigned int ClonePointerArrayAllocation = 0x10061de0;
// R6GameService.dll code @ 10061e20
constexpr unsigned int FillRepeatedDword = 0x10061e20;
// R6GameService.dll code @ 10061e40
constexpr unsigned int LowerBoundUnsignedDwords = 0x10061e40;
// R6GameService.dll code @ 10061e80
constexpr unsigned int ReleaseSegmentedPointerSlots = 0x10061e80;
// R6GameService.dll code @ 10061eb0
constexpr unsigned int CopySegmentedDwordRange = 0x10061eb0;
// R6GameService.dll code @ 10061fe0
constexpr unsigned int FindKeyNode = 0x10061fe0;
// R6GameService.dll code @ 10062020
constexpr unsigned int segmented_pointer_support_CopyByValueCursorArgumentsToScratch = 0x10062020;
// R6GameService.dll code @ 10062050
constexpr unsigned int MoveSegmentedDwordRangeBackward = 0x10062050;
// R6GameService.dll code @ 10062140
constexpr unsigned int MoveSegmentedDwordRangeForward = 0x10062140;
// R6GameService.dll code @ 10062250
constexpr unsigned int ReportStackCookieFailure = 0x10062250;
// R6GameService.dll code @ 1006226d
constexpr unsigned int FilterCompilerCookieError = 0x1006226d;
// R6GameService.dll code @ 10062271
constexpr unsigned int ResumeCompilerCookieFailure = 0x10062271;
// R6GameService.dll code @ 10062281
constexpr unsigned int __security_check_cookie = 0x10062281;
// R6GameService.dll code @ 10062290
constexpr unsigned int rand = 0x10062290;
// R6GameService.dll code @ 10062296
constexpr unsigned int srand = 0x10062296;
// R6GameService.dll code @ 1006229c
constexpr unsigned int memset = 0x1006229c;
// R6GameService.dll code @ 100622a2
constexpr unsigned int ftol = 0x100622a2;
// R6GameService.dll code @ 100622b0
constexpr unsigned int __aullshr = 0x100622b0;
// R6GameService.dll code @ 100622cf
constexpr unsigned int ___security_init_cookie = 0x100622cf;
// R6GameService.dll code @ 10062336
constexpr unsigned int __security_error_handler = 0x10062336;
// R6GameService.dll code @ 10062340
constexpr unsigned int InitializeDerivedTransportRecordWithText = 0x10062340;
// R6GameService.dll code @ 10062510
constexpr unsigned int DeleteDerivedTransportRecordWithText = 0x10062510;
// R6GameService.dll code @ 10062530
constexpr unsigned int thunk_DestroyCallbackListContainer = 0x10062530;
// R6GameService.dll code @ 10062540
constexpr unsigned int DeleteCallbackListContainer = 0x10062540;
// R6GameService.dll code @ 10062560
constexpr unsigned int DestroyDerivedTransportRecordWithText = 0x10062560;
// R6GameService.dll code @ 10062610
constexpr unsigned int ConnectAndSendProxyRequest = 0x10062610;
// R6GameService.dll code @ 100627a0
constexpr unsigned int CloseProxyAndClearReady = 0x100627a0;
// R6GameService.dll code @ 100627d0
constexpr unsigned int ForwardLogRequest = 0x100627d0;
// R6GameService.dll code @ 100627f0
constexpr unsigned int ForwardProxyCallbackSlot4 = 0x100627f0;
// R6GameService.dll code @ 10062810
constexpr unsigned int ForwardProxyCallbackSlot8 = 0x10062810;
// R6GameService.dll code @ 10062830
constexpr unsigned int ForwardProxyCallbackSlotC = 0x10062830;
// R6GameService.dll code @ 10062850
constexpr unsigned int ForwardProxyCallbackAndDeletePayload = 0x10062850;
// R6GameService.dll code @ 10062890
constexpr unsigned int DestroyCallbackListContainer = 0x10062890;
// R6GameService.dll code @ 10062920
constexpr unsigned int InvokePointerListClearRange = 0x10062920;
// R6GameService.dll code @ 10062950
constexpr unsigned int DestroyFirstPayloadListNode = 0x10062950;
// R6GameService.dll code @ 10062990
constexpr unsigned int DestroyLastPayloadListNode = 0x10062990;
// R6GameService.dll code @ 100629e0
constexpr unsigned int ErasePayloadListNode = 0x100629e0;
// R6GameService.dll code @ 10062a20
constexpr unsigned int ErasePayloadListRange = 0x10062a20;
// R6GameService.dll code @ 10062aa0
constexpr unsigned int DestroyPerNodeLinkedListContainer = 0x10062aa0;
// R6GameService.dll code @ 10062b40
constexpr unsigned int WriteServiceLogMessage = 0x10062b40;
// R6GameService.dll code @ 10062de0
constexpr unsigned int FormatUtcLogTimestamp = 0x10062de0;
// R6GameService.dll code @ 10062e30
constexpr unsigned int ReopenConfiguredLogFile = 0x10062e30;
// R6GameService.dll code @ 10062ed0
constexpr unsigned int RotateExpiredLogFile = 0x10062ed0;
// R6GameService.dll code @ 10063030
constexpr unsigned int fflush = 0x10063030;
// R6GameService.dll code @ 10063036
constexpr unsigned int fprintf = 0x10063036;
// R6GameService.dll code @ 1006303c
constexpr unsigned int gmtime = 0x1006303c;
// R6GameService.dll code @ 10063050
constexpr unsigned int CleanupPatchServiceAbstractBase = 0x10063050;
// R6GameService.dll code @ 10063059
constexpr unsigned int CleanupPatchServiceUObjectBase = 0x10063059;
// R6GameService.dll code @ 10063062
constexpr unsigned int PatchServiceDestructionExceptionHandler = 0x10063062;
// R6GameService.dll code @ 10063070
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoUnwind1 = 0x10063070;
// R6GameService.dll code @ 10063079
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoUnwind22 = 0x10063079;
// R6GameService.dll code @ 10063085
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoSelectExceptionInfo = 0x10063085;
// R6GameService.dll code @ 10063090
constexpr unsigned int UR6ModGSInfoSharedLifetimeUnwind1 = 0x10063090;
// R6GameService.dll code @ 10063099
constexpr unsigned int UR6ModGSInfoSharedLifetimeSelectExceptionInfo = 0x10063099;
// R6GameService.dll code @ 100630b0
constexpr unsigned int DestroyEncryptInputFString = 0x100630b0;
// R6GameService.dll code @ 100630b9
constexpr unsigned int DestroyEncryptInputWideString = 0x100630b9;
// R6GameService.dll code @ 100630c2
constexpr unsigned int DestroyEncryptOutputWideString = 0x100630c2;
// R6GameService.dll code @ 100630cb
constexpr unsigned int DestroyConstructedEncryptResult = 0x100630cb;
// R6GameService.dll code @ 100630e5
constexpr unsigned int EncryptWrapperExceptionHandler = 0x100630e5;
// R6GameService.dll code @ 100630f0
constexpr unsigned int DestroyDecryptInputFString = 0x100630f0;
// R6GameService.dll code @ 100630f9
constexpr unsigned int DestroyDecryptOutputWideString = 0x100630f9;
// R6GameService.dll code @ 10063102
constexpr unsigned int DestroyConstructedDecryptResult = 0x10063102;
// R6GameService.dll code @ 1006311c
constexpr unsigned int DecryptWrapperExceptionHandler = 0x1006311c;
// R6GameService.dll code @ 10063130
constexpr unsigned int DestroyValidationInputFString = 0x10063130;
// R6GameService.dll code @ 10063139
constexpr unsigned int MachineValidationExceptionHandler = 0x10063139;
// R6GameService.dll code @ 10063150
constexpr unsigned int DestroySavedFirstRecordString = 0x10063150;
// R6GameService.dll code @ 10063159
constexpr unsigned int SelectStringRecordExceptionInfo = 0x10063159;
// R6GameService.dll code @ 10063170
constexpr unsigned int UnwindUnsignedShortCtypeLock = 0x10063170;
// R6GameService.dll code @ 10063179
constexpr unsigned int SelectUnsignedShortCtypeLifetime = 0x10063179;
// R6GameService.dll code @ 10063190
constexpr unsigned int eventIsGlobalIDBannedUnwind1 = 0x10063190;
// R6GameService.dll code @ 10063198
constexpr unsigned int eventIsGlobalIDBannedSelectExceptionInfo = 0x10063198;
// R6GameService.dll code @ 100631b0
constexpr unsigned int eventProcessServerMsgUnwind1 = 0x100631b0;
// R6GameService.dll code @ 100631b8
constexpr unsigned int eventProcessServerMsgSelectExceptionInfo = 0x100631b8;
// R6GameService.dll code @ 100631d0
constexpr unsigned int UR6GSServersSharedLifetimeUnwind2 = 0x100631d0;
// R6GameService.dll code @ 100631d8
constexpr unsigned int UR6GSServersSharedLifetimeUnwind1 = 0x100631d8;
// R6GameService.dll code @ 100631f2
constexpr unsigned int UR6GSServersSharedLifetimeSelectExceptionInfo = 0x100631f2;
// R6GameService.dll code @ 10063200
constexpr unsigned int eventGetLocallyBoundIpAddrUnwind2 = 0x10063200;
// R6GameService.dll code @ 10063208
constexpr unsigned int eventGetLocallyBoundIpAddrUnwind1 = 0x10063208;
// R6GameService.dll code @ 10063222
constexpr unsigned int eventGetLocallyBoundIpAddrSelectExceptionInfo = 0x10063222;
// R6GameService.dll code @ 10063230
constexpr unsigned int UnlockSavedStreamSentry = 0x10063230;
// R6GameService.dll code @ 10063238
constexpr unsigned int StreamSentryExceptionHandler = 0x10063238;
// R6GameService.dll code @ 10063250
constexpr unsigned int DestroyWideStringInsertionSentry = 0x10063250;
// R6GameService.dll code @ 10063258
constexpr unsigned int UnlockWideStringInsertionSentry = 0x10063258;
// R6GameService.dll code @ 10063260
constexpr unsigned int WideStringInsertionExceptionHandler = 0x10063260;
// R6GameService.dll code @ 10063270
constexpr unsigned int UnwindGameDataName = 0x10063270;
// R6GameService.dll code @ 1006327c
constexpr unsigned int UnwindGameDataModName = 0x1006327c;
// R6GameService.dll code @ 10063288
constexpr unsigned int UnwindGameDataGameDataGameType = 0x10063288;
// R6GameService.dll code @ 10063294
constexpr unsigned int UnwindGameDataGameType = 0x10063294;
// R6GameService.dll code @ 100632a0
constexpr unsigned int UnwindGameDataCurrentMap = 0x100632a0;
// R6GameService.dll code @ 100632ac
constexpr unsigned int UnwindGameDataMessageOfDay = 0x100632ac;
// R6GameService.dll code @ 100632b8
constexpr unsigned int UnwindGameDataGameVersion = 0x100632b8;
// R6GameService.dll code @ 100632c4
constexpr unsigned int UnwindGameDataMapArray = 0x100632c4;
// R6GameService.dll code @ 100632d2
constexpr unsigned int UnwindGameDataPlayerArray = 0x100632d2;
// R6GameService.dll code @ 100632e0
constexpr unsigned int SelectGameDataExceptionInfo = 0x100632e0;
// R6GameService.dll code @ 100632f0
constexpr unsigned int UnwindGameServerIPAddress = 0x100632f0;
// R6GameService.dll code @ 100632fc
constexpr unsigned int UnwindGameServerAltIPAddress = 0x100632fc;
// R6GameService.dll code @ 10063308
constexpr unsigned int UnwindGameServerOptions = 0x10063308;
// R6GameService.dll code @ 10063314
constexpr unsigned int SelectGameServerExceptionInfo = 0x10063314;
// R6GameService.dll code @ 10063320
constexpr unsigned int DestroySavedArrayStorage = 0x10063320;
// R6GameService.dll code @ 10063329
constexpr unsigned int SelectArrayStorageExceptionInfo = 0x10063329;
// R6GameService.dll code @ 10063340
constexpr unsigned int UnwindServerListDestructorBase = 0x10063340;
// R6GameService.dll code @ 10063349
constexpr unsigned int UnwindServerListDestructorFavorites = 0x10063349;
// R6GameService.dll code @ 10063354
constexpr unsigned int UnwindServerListDestructorServers = 0x10063354;
// R6GameService.dll code @ 1006335f
constexpr unsigned int UnwindServerListDestructorValidResponses = 0x1006335f;
// R6GameService.dll code @ 1006336a
constexpr unsigned int UnwindServerListDestructorModResponses = 0x1006336a;
// R6GameService.dll code @ 10063375
constexpr unsigned int UnwindServerListDestructorSortIndices = 0x10063375;
// R6GameService.dll code @ 10063383
constexpr unsigned int UnwindServerListDestructorCurrentServer = 0x10063383;
// R6GameService.dll code @ 10063391
constexpr unsigned int UnwindServerListDestructorVersion = 0x10063391;
// R6GameService.dll code @ 100633a0
constexpr unsigned int SelectServerListDestructorInfo = 0x100633a0;
// R6GameService.dll code @ 100633b0
constexpr unsigned int UnwindServerListConstructorBase = 0x100633b0;
// R6GameService.dll code @ 100633b9
constexpr unsigned int UnwindServerListConstructorFavorites = 0x100633b9;
// R6GameService.dll code @ 100633c4
constexpr unsigned int UnwindServerListConstructorServers = 0x100633c4;
// R6GameService.dll code @ 100633cf
constexpr unsigned int UnwindServerListConstructorValidResponses = 0x100633cf;
// R6GameService.dll code @ 100633da
constexpr unsigned int UnwindServerListConstructorModResponses = 0x100633da;
// R6GameService.dll code @ 100633e5
constexpr unsigned int UnwindServerListConstructorSortIndices = 0x100633e5;
// R6GameService.dll code @ 100633f3
constexpr unsigned int UnwindServerListConstructorCurrentServer = 0x100633f3;
// R6GameService.dll code @ 10063401
constexpr unsigned int SelectServerListConstructorInfo = 0x10063401;
// R6GameService.dll code @ 10063410
constexpr unsigned int UnwindLanServersBase = 0x10063410;
// R6GameService.dll code @ 10063418
constexpr unsigned int SelectLanServersDestructorInfo = 0x10063418;
// R6GameService.dll code @ 10063430
constexpr unsigned int UnwindGSServersDestructorBase = 0x10063430;
// R6GameService.dll code @ 10063438
constexpr unsigned int UnwindGSServersDestructorString1 = 0x10063438;
// R6GameService.dll code @ 10063447
constexpr unsigned int UnwindGSServersDestructorString2 = 0x10063447;
// R6GameService.dll code @ 10063456
constexpr unsigned int UnwindGSServersDestructorString3 = 0x10063456;
// R6GameService.dll code @ 10063465
constexpr unsigned int UnwindGSServersDestructorString4 = 0x10063465;
// R6GameService.dll code @ 10063474
constexpr unsigned int UnwindGSServersDestructorString5 = 0x10063474;
// R6GameService.dll code @ 10063483
constexpr unsigned int UnwindGSServersDestructorString6 = 0x10063483;
// R6GameService.dll code @ 10063492
constexpr unsigned int UnwindGSServersDestructorString7 = 0x10063492;
// R6GameService.dll code @ 100634a1
constexpr unsigned int UnwindGSServersDestructorString8 = 0x100634a1;
// R6GameService.dll code @ 100634b0
constexpr unsigned int UnwindGSServersDestructorString9 = 0x100634b0;
// R6GameService.dll code @ 100634bf
constexpr unsigned int UnwindGSServersDestructorString10 = 0x100634bf;
// R6GameService.dll code @ 100634ce
constexpr unsigned int SelectGSServersDestructorInfo = 0x100634ce;
// R6GameService.dll code @ 100634e0
constexpr unsigned int UnwindGSServersCopyConstructorBase = 0x100634e0;
// R6GameService.dll code @ 100634e8
constexpr unsigned int UnwindGSServersCopyConstructorString1 = 0x100634e8;
// R6GameService.dll code @ 100634f7
constexpr unsigned int UnwindGSServersCopyConstructorString2 = 0x100634f7;
// R6GameService.dll code @ 10063506
constexpr unsigned int UnwindGSServersCopyConstructorString3 = 0x10063506;
// R6GameService.dll code @ 10063515
constexpr unsigned int UnwindGSServersCopyConstructorString4 = 0x10063515;
// R6GameService.dll code @ 10063524
constexpr unsigned int UnwindGSServersCopyConstructorString5 = 0x10063524;
// R6GameService.dll code @ 10063533
constexpr unsigned int UnwindGSServersCopyConstructorString6 = 0x10063533;
// R6GameService.dll code @ 10063542
constexpr unsigned int UnwindGSServersCopyConstructorString7 = 0x10063542;
// R6GameService.dll code @ 10063551
constexpr unsigned int UnwindGSServersCopyConstructorString8 = 0x10063551;
// R6GameService.dll code @ 10063560
constexpr unsigned int UnwindGSServersCopyConstructorString9 = 0x10063560;
// R6GameService.dll code @ 1006356f
constexpr unsigned int SelectGSServersCopyInfo = 0x1006356f;
// R6GameService.dll code @ 10063580
constexpr unsigned int DestroyPatchProgressFirstString = 0x10063580;
// R6GameService.dll code @ 1006358c
constexpr unsigned int DestroyPatchProgressSecondString = 0x1006358c;
// R6GameService.dll code @ 10063595
constexpr unsigned int PatchProgressExceptionHandler = 0x10063595;
// R6GameService.dll code @ 100635a0
constexpr unsigned int PatchExitCauseExceptionHandler = 0x100635a0;
// R6GameService.dll code @ 100635b0
constexpr unsigned int DestroyPatchAccessDirectory = 0x100635b0;
// R6GameService.dll code @ 100635b9
constexpr unsigned int PatchAccessBridgeExceptionHandler = 0x100635b9;
// R6GameService.dll code @ 100635d0
constexpr unsigned int DestroyWideLogOstreamDuringDestruction = 0x100635d0;
// R6GameService.dll code @ 100635dc
constexpr unsigned int WideLogStreamDestructorExceptionHandler = 0x100635dc;
// R6GameService.dll code @ 100635f0
constexpr unsigned int DestroyOwnedWideLogIos = 0x100635f0;
// R6GameService.dll code @ 1006360d
constexpr unsigned int DestroyConstructedWideLogOstream = 0x1006360d;
// R6GameService.dll code @ 10063619
constexpr unsigned int WideLogStreamConstructorExceptionHandler = 0x10063619;
// R6GameService.dll code @ 10063630
constexpr unsigned int DestroyAnsiInsertionSentry = 0x10063630;
// R6GameService.dll code @ 10063638
constexpr unsigned int DestroyAnsiInsertionLocale = 0x10063638;
// R6GameService.dll code @ 10063641
constexpr unsigned int UnlockAnsiInsertionSentry = 0x10063641;
// R6GameService.dll code @ 10063649
constexpr unsigned int AnsiWideInsertionExceptionHandler = 0x10063649;
// R6GameService.dll code @ 10063660
constexpr unsigned int ReleasePatchStatePollAllocation = 0x10063660;
// R6GameService.dll code @ 1006366b
constexpr unsigned int PatchStatePollExceptionHandler = 0x1006366b;
// R6GameService.dll code @ 10063680
constexpr unsigned int PatchStateExceptionHandler = 0x10063680;
// R6GameService.dll code @ 10063690
constexpr unsigned int PatchAbortBridgeExceptionHandler = 0x10063690;
// R6GameService.dll code @ 100636a0
constexpr unsigned int DestroyExtractedWideLogText = 0x100636a0;
// R6GameService.dll code @ 100636a9
constexpr unsigned int DestroyEmptyWideLogText = 0x100636a9;
// R6GameService.dll code @ 100636b2
constexpr unsigned int WideLogFlushExceptionHandler = 0x100636b2;
// R6GameService.dll code @ 100636c0
constexpr unsigned int DestroyWideLogFileStream = 0x100636c0;
// R6GameService.dll code @ 100636cc
constexpr unsigned int WideLogWriterExceptionHandler = 0x100636cc;
// R6GameService.dll code @ 100636e0
constexpr unsigned int ReleasePatchStartupAllocation = 0x100636e0;
// R6GameService.dll code @ 100636eb
constexpr unsigned int PatchStartupExceptionHandler = 0x100636eb;
// R6GameService.dll code @ 10063700
constexpr unsigned int PatchStartBridgeExceptionHandler = 0x10063700;
// R6GameService.dll code @ 10063710
constexpr unsigned int SelectEventNameStartupEH = 0x10063710;
// R6GameService.dll code @ 10063720
constexpr unsigned int execNativeInitModInfoUnwind2 = 0x10063720;
// R6GameService.dll code @ 10063729
constexpr unsigned int execNativeInitModInfoUnwind3 = 0x10063729;
// R6GameService.dll code @ 10063732
constexpr unsigned int execNativeInitModInfoUnwind4 = 0x10063732;
// R6GameService.dll code @ 1006373b
constexpr unsigned int execNativeInitModInfoUnwind5 = 0x1006373b;
// R6GameService.dll code @ 10063744
constexpr unsigned int execNativeInitModInfoUnwind6 = 0x10063744;
// R6GameService.dll code @ 1006374d
constexpr unsigned int SelectModInfoEH = 0x1006374d;
// R6GameService.dll code @ 10063760
constexpr unsigned int SelectManagerParentEH = 0x10063760;
// R6GameService.dll code @ 10063770
constexpr unsigned int UR6GSServers_PingRequestUnwind1 = 0x10063770;
// R6GameService.dll code @ 10063779
constexpr unsigned int UR6GSServers_PingRequestUnwind2 = 0x10063779;
// R6GameService.dll code @ 10063782
constexpr unsigned int UR6GSServers_PingRequestSelectExceptionInfo = 0x10063782;
// R6GameService.dll code @ 10063790
constexpr unsigned int UR6GSServers_PollPingManagerSelectExceptionInfo = 0x10063790;
// R6GameService.dll code @ 100637a0
constexpr unsigned int UR6ServerList_execNativeGetPingTimeUnwind2 = 0x100637a0;
// R6GameService.dll code @ 100637a9
constexpr unsigned int UR6ServerList_execNativeGetPingTimeSelectExceptionInfo = 0x100637a9;
// R6GameService.dll code @ 100637c0
constexpr unsigned int UR6ServerList_execNativeGetPingTimeOutSelectExceptionInfo = 0x100637c0;
// R6GameService.dll code @ 100637d0
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPingUnwind2 = 0x100637d0;
// R6GameService.dll code @ 100637d9
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPingSelectExceptionInfo = 0x100637d9;
// R6GameService.dll code @ 100637f0
constexpr unsigned int UR6GSServers_execNativeGetSecondsSelectExceptionInfo = 0x100637f0;
// R6GameService.dll code @ 10063800
constexpr unsigned int SelectSmallVMBridgeEH = 0x10063800;
// R6GameService.dll code @ 10063810
constexpr unsigned int UR6ServerList_SelectSmallVMBridgeEH = 0x10063810;
// R6GameService.dll code @ 10063820
constexpr unsigned int UR6GSServers_SelectSmallVMBridgeEH = 0x10063820;
// R6GameService.dll code @ 10063830
constexpr unsigned int SelectParentExceptionInfo = 0x10063830;
// R6GameService.dll code @ 10063840
constexpr unsigned int OnSameSubNetUnwind1 = 0x10063840;
// R6GameService.dll code @ 10063849
constexpr unsigned int SelectSubnetEH = 0x10063849;
// R6GameService.dll code @ 10063860
constexpr unsigned int UnInitMSClientSelectExceptionInfo = 0x10063860;
// R6GameService.dll code @ 10063870
constexpr unsigned int execUnInitializeMSClientSelectExceptionInfo = 0x10063870;
// R6GameService.dll code @ 10063880
constexpr unsigned int UR6GSServers_SelectSmallVMBridgeEH2 = 0x10063880;
// R6GameService.dll code @ 10063890
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind2 = 0x10063890;
// R6GameService.dll code @ 10063899
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind3 = 0x10063899;
// R6GameService.dll code @ 100638a2
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind4 = 0x100638a2;
// R6GameService.dll code @ 100638ab
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind5 = 0x100638ab;
// R6GameService.dll code @ 100638b4
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind9 = 0x100638b4;
// R6GameService.dll code @ 100638bd
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind8 = 0x100638bd;
// R6GameService.dll code @ 100638c6
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind7 = 0x100638c6;
// R6GameService.dll code @ 100638cf
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind6 = 0x100638cf;
// R6GameService.dll code @ 100638d8
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind12 = 0x100638d8;
// R6GameService.dll code @ 100638e1
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind11 = 0x100638e1;
// R6GameService.dll code @ 100638ea
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwind10 = 0x100638ea;
// R6GameService.dll code @ 100638f3
constexpr unsigned int UR6GSServers_PollMSClientCallbacksSelectExceptionInfo = 0x100638f3;
// R6GameService.dll code @ 10063900
constexpr unsigned int UR6GSServers_SelectSmallVMBridgeEH3 = 0x10063900;
// R6GameService.dll code @ 10063910
constexpr unsigned int UR6GSServers_SelectSmallVMBridgeEH4 = 0x10063910;
// R6GameService.dll code @ 10063920
constexpr unsigned int MSCLientLeaveServerSelectExceptionInfo = 0x10063920;
// R6GameService.dll code @ 10063930
constexpr unsigned int UR6GSServersSharedLifetimeUnwind12 = 0x10063930;
// R6GameService.dll code @ 10063939
constexpr unsigned int SelectInheritedFStringEH = 0x10063939;
// R6GameService.dll code @ 10063950
constexpr unsigned int UR6GSServersSharedLifetimeUnwind22 = 0x10063950;
// R6GameService.dll code @ 10063959
constexpr unsigned int UR6GSServers_SelectInheritedFStringEH = 0x10063959;
// R6GameService.dll code @ 10063970
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo = 0x10063970;
// R6GameService.dll code @ 10063980
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo2 = 0x10063980;
// R6GameService.dll code @ 10063990
constexpr unsigned int UR6ServerList_ResetSvrContainerSelectExceptionInfo = 0x10063990;
// R6GameService.dll code @ 100639a0
constexpr unsigned int UR6GSServersSharedLifetimeUnwind23 = 0x100639a0;
// R6GameService.dll code @ 100639a9
constexpr unsigned int UR6GSServers_SelectInheritedFStringEH2 = 0x100639a9;
// R6GameService.dll code @ 100639c0
constexpr unsigned int ProcessJoinServerRequestUnwind2 = 0x100639c0;
// R6GameService.dll code @ 100639c9
constexpr unsigned int ProcessJoinServerRequestUnwind3 = 0x100639c9;
// R6GameService.dll code @ 100639d2
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo3 = 0x100639d2;
// R6GameService.dll code @ 100639e0
constexpr unsigned int UR6GSServersSharedLifetimeUnwind13 = 0x100639e0;
// R6GameService.dll code @ 100639e9
constexpr unsigned int UR6GSServers_SelectInheritedFStringEH3 = 0x100639e9;
// R6GameService.dll code @ 10063a00
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo4 = 0x10063a00;
// R6GameService.dll code @ 10063a10
constexpr unsigned int UR6GSServers_execNativeIsRouterDisconnectSelectExceptionInfo = 0x10063a10;
// R6GameService.dll code @ 10063a20
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo5 = 0x10063a20;
// R6GameService.dll code @ 10063a30
constexpr unsigned int DestroyFourStringsUnwind1 = 0x10063a30;
// R6GameService.dll code @ 10063a39
constexpr unsigned int DestroyFourStringsUnwind2 = 0x10063a39;
// R6GameService.dll code @ 10063a45
constexpr unsigned int DestroyFourStringsUnwind3 = 0x10063a45;
// R6GameService.dll code @ 10063a51
constexpr unsigned int SelectFourStringDestruction = 0x10063a51;
// R6GameService.dll code @ 10063a60
constexpr unsigned int UR6GSServers_InitUnwind1 = 0x10063a60;
// R6GameService.dll code @ 10063a69
constexpr unsigned int UR6GSServers_InitUnwind2 = 0x10063a69;
// R6GameService.dll code @ 10063a77
constexpr unsigned int UR6GSServers_InitUnwind3 = 0x10063a77;
// R6GameService.dll code @ 10063a85
constexpr unsigned int UR6GSServers_InitUnwind4 = 0x10063a85;
// R6GameService.dll code @ 10063a93
constexpr unsigned int UR6GSServers_InitSelectExceptionInfo = 0x10063a93;
// R6GameService.dll code @ 10063aa0
constexpr unsigned int UR6GSServers_execInitializeSelectExceptionInfo = 0x10063aa0;
// R6GameService.dll code @ 10063ab0
constexpr unsigned int InitFavoritesUnwind2 = 0x10063ab0;
// R6GameService.dll code @ 10063ab9
constexpr unsigned int InitFavoritesSelectExceptionInfo = 0x10063ab9;
// R6GameService.dll code @ 10063ad0
constexpr unsigned int SelectInitFavoritesBridgeEH = 0x10063ad0;
// R6GameService.dll code @ 10063ae0
constexpr unsigned int SelectUpdateFavoritesBridgeEH = 0x10063ae0;
// R6GameService.dll code @ 10063af0
constexpr unsigned int UR6ServerList_SelectParentExceptionInfo = 0x10063af0;
// R6GameService.dll code @ 10063b00
constexpr unsigned int LogGSVersionUnwind2 = 0x10063b00;
// R6GameService.dll code @ 10063b08
constexpr unsigned int LogGSVersionSelectExceptionInfo = 0x10063b08;
// R6GameService.dll code @ 10063b20
constexpr unsigned int execGetDisplayListSizeSelectExceptionInfo = 0x10063b20;
// R6GameService.dll code @ 10063b30
constexpr unsigned int PlayerIsInIDListUnwind1 = 0x10063b30;
// R6GameService.dll code @ 10063b39
constexpr unsigned int PlayerIsInIDListUnwind2 = 0x10063b39;
// R6GameService.dll code @ 10063b42
constexpr unsigned int PlayerIsInIDListSelectExceptionInfo = 0x10063b42;
// R6GameService.dll code @ 10063b50
constexpr unsigned int GetGlobalIdFromPlayerIDListUnwind2 = 0x10063b50;
// R6GameService.dll code @ 10063b59
constexpr unsigned int GetGlobalIdFromPlayerIDListUnwind1 = 0x10063b59;
// R6GameService.dll code @ 10063b73
constexpr unsigned int GetGlobalIdFromPlayerIDListSelectExceptionInfo = 0x10063b73;
// R6GameService.dll code @ 10063b80
constexpr unsigned int PollCallbacksSelectExceptionInfo = 0x10063b80;
// R6GameService.dll code @ 10063b90
constexpr unsigned int InitializeMSClientUnwind2 = 0x10063b90;
// R6GameService.dll code @ 10063b99
constexpr unsigned int InitializeMSClientSelectExceptionInfo = 0x10063b99;
// R6GameService.dll code @ 10063bb0
constexpr unsigned int execInitializeMSClientSelectExceptionInfo = 0x10063bb0;
// R6GameService.dll code @ 10063bc0
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo6 = 0x10063bc0;
// R6GameService.dll code @ 10063bd0
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo7 = 0x10063bd0;
// R6GameService.dll code @ 10063be0
constexpr unsigned int UnwindMatchResultFString = 0x10063be0;
// R6GameService.dll code @ 10063be9
constexpr unsigned int UnwindMatchResultBstr = 0x10063be9;
// R6GameService.dll code @ 10063bf1
constexpr unsigned int SelectMatchResultLifetime = 0x10063bf1;
// R6GameService.dll code @ 10063c00
constexpr unsigned int UR6GSServers_SelectManagerParentEH = 0x10063c00;
// R6GameService.dll code @ 10063c10
constexpr unsigned int FillSvrContainerUnwind2 = 0x10063c10;
// R6GameService.dll code @ 10063c19
constexpr unsigned int FillSvrContainerUnwind3 = 0x10063c19;
// R6GameService.dll code @ 10063c22
constexpr unsigned int FillSvrContainerUnwind4 = 0x10063c22;
// R6GameService.dll code @ 10063c2b
constexpr unsigned int SelectFillContainerEH = 0x10063c2b;
// R6GameService.dll code @ 10063c40
constexpr unsigned int UR6GSServers_SelectParentExceptionInfo8 = 0x10063c40;
// R6GameService.dll code @ 10063c50
constexpr unsigned int UR6GSServers_MasterServerManagerSelectExceptionInfo = 0x10063c50;
// R6GameService.dll code @ 10063c60
constexpr unsigned int UR6GSServers_AddPlayerToIDListUnwind1 = 0x10063c60;
// R6GameService.dll code @ 10063c69
constexpr unsigned int UR6GSServers_AddPlayerToIDListUnwind2 = 0x10063c69;
// R6GameService.dll code @ 10063c72
constexpr unsigned int UR6GSServers_AddPlayerToIDListUnwind3 = 0x10063c72;
// R6GameService.dll code @ 10063c7b
constexpr unsigned int UR6GSServers_AddPlayerToIDListUnwind5 = 0x10063c7b;
// R6GameService.dll code @ 10063c84
constexpr unsigned int UR6GSServers_AddPlayerToIDListSelectExceptionInfo = 0x10063c84;
// R6GameService.dll code @ 10063c90
constexpr unsigned int ReceiveServerUnwind2 = 0x10063c90;
// R6GameService.dll code @ 10063c99
constexpr unsigned int SelectReceiveServerEH = 0x10063c99;
// R6GameService.dll code @ 10063cb0
constexpr unsigned int UR6GSServers_InitMSClientUnwind2 = 0x10063cb0;
// R6GameService.dll code @ 10063cbb
constexpr unsigned int UR6GSServers_InitMSClientSelectExceptionInfo = 0x10063cbb;
// R6GameService.dll code @ 10063cd0
constexpr unsigned int ReceiveAltInfoUnwind2 = 0x10063cd0;
// R6GameService.dll code @ 10063cd9
constexpr unsigned int ReceiveAltInfoUnwind3 = 0x10063cd9;
// R6GameService.dll code @ 10063ce2
constexpr unsigned int SelectReceiveAltInfoEH = 0x10063ce2;
// R6GameService.dll code @ 10063cf0
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequestUnwind2 = 0x10063cf0;
// R6GameService.dll code @ 10063cf9
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequestSelectExceptionInfo = 0x10063cf9;
// R6GameService.dll code @ 10063d10
constexpr unsigned int unreal_array_supportSharedLifetimeUnwind1 = 0x10063d10;
// R6GameService.dll code @ 10063d19
constexpr unsigned int SelectSharedArrayDestruction = 0x10063d19;
// R6GameService.dll code @ 10063d30
constexpr unsigned int SelectRefreshServersEH = 0x10063d30;
// R6GameService.dll code @ 10063d40
constexpr unsigned int UR6GSServers_SelectSmallVMBridgeEH5 = 0x10063d40;
// R6GameService.dll code @ 10063d50
constexpr unsigned int UR6GSServers_GameServiceManagerUnwind2 = 0x10063d50;
// R6GameService.dll code @ 10063d59
constexpr unsigned int UR6GSServers_GameServiceManagerSelectExceptionInfo = 0x10063d59;
// R6GameService.dll code @ 10063d70
constexpr unsigned int UR6GSServersUnwind1 = 0x10063d70;
// R6GameService.dll code @ 10063d78
constexpr unsigned int UR6GSServersUnwind2 = 0x10063d78;
// R6GameService.dll code @ 10063d87
constexpr unsigned int UR6GSServersUnwind3 = 0x10063d87;
// R6GameService.dll code @ 10063d96
constexpr unsigned int UR6GSServersUnwind4 = 0x10063d96;
// R6GameService.dll code @ 10063da5
constexpr unsigned int UR6GSServersUnwind5 = 0x10063da5;
// R6GameService.dll code @ 10063db4
constexpr unsigned int UR6GSServersUnwind6 = 0x10063db4;
// R6GameService.dll code @ 10063dc3
constexpr unsigned int UR6GSServersUnwind7 = 0x10063dc3;
// R6GameService.dll code @ 10063dd2
constexpr unsigned int UR6GSServersUnwind8 = 0x10063dd2;
// R6GameService.dll code @ 10063de1
constexpr unsigned int UR6GSServersUnwind9 = 0x10063de1;
// R6GameService.dll code @ 10063df0
constexpr unsigned int UR6GSServersUnwind10 = 0x10063df0;
// R6GameService.dll code @ 10063dff
constexpr unsigned int UR6GSServersUnwind11 = 0x10063dff;
// R6GameService.dll code @ 10063e0e
constexpr unsigned int UR6GSServersSelectExceptionInfo = 0x10063e0e;
// R6GameService.dll code @ 10063e20
constexpr unsigned int CreatedCDKeyUnwind2 = 0x10063e20;
// R6GameService.dll code @ 10063e29
constexpr unsigned int CreatedCDKeyUnwind3 = 0x10063e29;
// R6GameService.dll code @ 10063e32
constexpr unsigned int CreatedCDKeyUnwind4 = 0x10063e32;
// R6GameService.dll code @ 10063e3b
constexpr unsigned int CreatedCDKeySelectExceptionInfo = 0x10063e3b;
// R6GameService.dll code @ 10063e50
constexpr unsigned int InitMODCDKeyUnwind2 = 0x10063e50;
// R6GameService.dll code @ 10063e59
constexpr unsigned int InitMODCDKeyUnwind3 = 0x10063e59;
// R6GameService.dll code @ 10063e62
constexpr unsigned int InitMODCDKeyUnwind4 = 0x10063e62;
// R6GameService.dll code @ 10063e6b
constexpr unsigned int InitMODCDKeyUnwind5 = 0x10063e6b;
// R6GameService.dll code @ 10063e74
constexpr unsigned int InitMODCDKeySelectExceptionInfo = 0x10063e74;
// R6GameService.dll code @ 10063e80
constexpr unsigned int execInitGSCDKeySelectExceptionInfo = 0x10063e80;
// R6GameService.dll code @ 10063e90
constexpr unsigned int UnInitCDKeySelectExceptionInfo = 0x10063e90;
// R6GameService.dll code @ 10063ea0
constexpr unsigned int UR6GSServers_RequestActivationUnwind1 = 0x10063ea0;
// R6GameService.dll code @ 10063ea9
constexpr unsigned int UR6GSServers_RequestActivationUnwind3 = 0x10063ea9;
// R6GameService.dll code @ 10063ec3
constexpr unsigned int UR6GSServers_RequestActivationUnwind4 = 0x10063ec3;
// R6GameService.dll code @ 10063ecc
constexpr unsigned int UR6GSServers_RequestActivationSelectExceptionInfo = 0x10063ecc;
// R6GameService.dll code @ 10063ee0
constexpr unsigned int UR6GSServers_RequestAuthorizationSelectExceptionInfo = 0x10063ee0;
// R6GameService.dll code @ 10063ef0
constexpr unsigned int UR6GSServers_GetAuthIDSelectExceptionInfo = 0x10063ef0;
// R6GameService.dll code @ 10063f00
constexpr unsigned int IsAuthIDSuccessSelectExceptionInfo = 0x10063f00;
// R6GameService.dll code @ 10063f10
constexpr unsigned int FormatAuthenticationIdHexUnwind2 = 0x10063f10;
// R6GameService.dll code @ 10063f19
constexpr unsigned int FormatAuthenticationIdHexUnwind1 = 0x10063f19;
// R6GameService.dll code @ 10063f33
constexpr unsigned int SelectAuthenticationFormatterLifetime = 0x10063f33;
// R6GameService.dll code @ 10063f40
constexpr unsigned int UR6GSServers_CDKeyValidateUserUnwind1 = 0x10063f40;
// R6GameService.dll code @ 10063f49
constexpr unsigned int UR6GSServers_CDKeyValidateUserSelectExceptionInfo = 0x10063f49;
// R6GameService.dll code @ 10063f60
constexpr unsigned int EnterCDKeyUnwind1 = 0x10063f60;
// R6GameService.dll code @ 10063f69
constexpr unsigned int EnterCDKeyUnwind3 = 0x10063f69;
// R6GameService.dll code @ 10063f72
constexpr unsigned int EnterCDKeyUnwind4 = 0x10063f72;
// R6GameService.dll code @ 10063f7b
constexpr unsigned int EnterCDKeyUnwind5 = 0x10063f7b;
// R6GameService.dll code @ 10063f84
constexpr unsigned int EnterCDKeyUnwind6 = 0x10063f84;
// R6GameService.dll code @ 10063f8d
constexpr unsigned int EnterCDKeyUnwind7 = 0x10063f8d;
// R6GameService.dll code @ 10063f96
constexpr unsigned int EnterCDKeyUnwind8 = 0x10063f96;
// R6GameService.dll code @ 10063f9f
constexpr unsigned int EnterCDKeyUnwind9 = 0x10063f9f;
// R6GameService.dll code @ 10063fa8
constexpr unsigned int EnterCDKeyUnwind10 = 0x10063fa8;
// R6GameService.dll code @ 10063fb1
constexpr unsigned int EnterCDKeySelectExceptionInfo = 0x10063fb1;
// R6GameService.dll code @ 10063fc0
constexpr unsigned int execEnterCDKeyUnwind2 = 0x10063fc0;
// R6GameService.dll code @ 10063fc9
constexpr unsigned int execEnterCDKeySelectExceptionInfo = 0x10063fc9;
// R6GameService.dll code @ 10063fe0
constexpr unsigned int RequestModCDKeyProcessUnwind2 = 0x10063fe0;
// R6GameService.dll code @ 10063fe9
constexpr unsigned int RequestModCDKeyProcessUnwind3 = 0x10063fe9;
// R6GameService.dll code @ 10063ff2
constexpr unsigned int RequestModCDKeyProcessUnwind4 = 0x10063ff2;
// R6GameService.dll code @ 10063ffb
constexpr unsigned int RequestModCDKeyProcessUnwind5 = 0x10063ffb;
// R6GameService.dll code @ 10064004
constexpr unsigned int RequestModCDKeyProcessUnwind6 = 0x10064004;
// R6GameService.dll code @ 1006400d
constexpr unsigned int RequestModCDKeyProcessUnwind7 = 0x1006400d;
// R6GameService.dll code @ 10064016
constexpr unsigned int RequestModCDKeyProcessSelectExceptionInfo = 0x10064016;
// R6GameService.dll code @ 10064020
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind2 = 0x10064020;
// R6GameService.dll code @ 10064029
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind3 = 0x10064029;
// R6GameService.dll code @ 10064032
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind7 = 0x10064032;
// R6GameService.dll code @ 1006403b
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind6 = 0x1006403b;
// R6GameService.dll code @ 10064044
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind5 = 0x10064044;
// R6GameService.dll code @ 1006404d
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind4 = 0x1006404d;
// R6GameService.dll code @ 10064056
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind8 = 0x10064056;
// R6GameService.dll code @ 1006405f
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind9 = 0x1006405f;
// R6GameService.dll code @ 10064068
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind10 = 0x10064068;
// R6GameService.dll code @ 10064071
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind11 = 0x10064071;
// R6GameService.dll code @ 1006407d
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind12 = 0x1006407d;
// R6GameService.dll code @ 10064089
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind13 = 0x10064089;
// R6GameService.dll code @ 10064092
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind14 = 0x10064092;
// R6GameService.dll code @ 1006409b
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind15 = 0x1006409b;
// R6GameService.dll code @ 100640a4
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind16 = 0x100640a4;
// R6GameService.dll code @ 100640ad
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwind17 = 0x100640ad;
// R6GameService.dll code @ 100640b6
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksSelectExceptionInfo = 0x100640b6;
// R6GameService.dll code @ 100640c0
constexpr unsigned int cdkey_supportSharedLifetimeUnwind1 = 0x100640c0;
// R6GameService.dll code @ 100640c9
constexpr unsigned int SelectCDKeyStringTemporary = 0x100640c9;
// R6GameService.dll code @ 100640e0
constexpr unsigned int UR6GSServers_ReceiveValidationSelectExceptionInfo = 0x100640e0;
// R6GameService.dll code @ 100640f0
constexpr unsigned int unreal_array_support_DestroyArrayStorage5Unwind1 = 0x100640f0;
// R6GameService.dll code @ 100640f9
constexpr unsigned int SelectArray20Destruction = 0x100640f9;
// R6GameService.dll code @ 10064110
constexpr unsigned int InitCDKeySelectExceptionInfo = 0x10064110;
// R6GameService.dll code @ 10064120
constexpr unsigned int InitGSCDKeySelectExceptionInfo = 0x10064120;
// R6GameService.dll code @ 10064130
constexpr unsigned int DisconnectAllCDKeyPlayersUnwind2 = 0x10064130;
// R6GameService.dll code @ 10064139
constexpr unsigned int DisconnectAllCDKeyPlayersUnwind3 = 0x10064139;
// R6GameService.dll code @ 10064145
constexpr unsigned int DisconnectAllCDKeyPlayersUnwind4 = 0x10064145;
// R6GameService.dll code @ 10064151
constexpr unsigned int DisconnectAllCDKeyPlayersSelectExceptionInfo = 0x10064151;
// R6GameService.dll code @ 10064160
constexpr unsigned int CDKeyDisconnecUserUnwind1 = 0x10064160;
// R6GameService.dll code @ 10064169
constexpr unsigned int CDKeyDisconnecUserUnwind3 = 0x10064169;
// R6GameService.dll code @ 10064172
constexpr unsigned int CDKeyDisconnecUserSelectExceptionInfo = 0x10064172;
// R6GameService.dll code @ 10064180
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReplyUnwind1 = 0x10064180;
// R6GameService.dll code @ 10064189
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReplySelectExceptionInfo = 0x10064189;
// R6GameService.dll code @ 100641a0
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind2 = 0x100641a0;
// R6GameService.dll code @ 100641a9
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind3 = 0x100641a9;
// R6GameService.dll code @ 100641b2
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind4 = 0x100641b2;
// R6GameService.dll code @ 100641ba
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind5 = 0x100641ba;
// R6GameService.dll code @ 100641c2
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind6 = 0x100641c2;
// R6GameService.dll code @ 100641cb
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind7 = 0x100641cb;
// R6GameService.dll code @ 100641d7
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind8 = 0x100641d7;
// R6GameService.dll code @ 100641e3
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind9 = 0x100641e3;
// R6GameService.dll code @ 100641ef
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind10 = 0x100641ef;
// R6GameService.dll code @ 100641f8
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind11 = 0x100641f8;
// R6GameService.dll code @ 10064204
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind12 = 0x10064204;
// R6GameService.dll code @ 10064210
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind13 = 0x10064210;
// R6GameService.dll code @ 1006421c
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind14 = 0x1006421c;
// R6GameService.dll code @ 10064225
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind15 = 0x10064225;
// R6GameService.dll code @ 1006422e
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwind16 = 0x1006422e;
// R6GameService.dll code @ 10064237
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestSelectExceptionInfo = 0x10064237;
// R6GameService.dll code @ 10064250
constexpr unsigned int UR6GSServers_ProcessAuthIdRequestSelectExceptionInfo = 0x10064250;
// R6GameService.dll code @ 10064260
constexpr unsigned int SetSelectedProductCategoryUnwind1 = 0x10064260;
// R6GameService.dll code @ 10064269
constexpr unsigned int SetSelectedProductCategoryUnwind2 = 0x10064269;
// R6GameService.dll code @ 10064272
constexpr unsigned int SetSelectedProductCategoryUnwind3 = 0x10064272;
// R6GameService.dll code @ 1006427b
constexpr unsigned int SetSelectedProductCategoryUnwind4 = 0x1006427b;
// R6GameService.dll code @ 10064284
constexpr unsigned int SelectProductCategoryLifetime = 0x10064284;
// R6GameService.dll code @ 10064290
constexpr unsigned int UR6GSServers_GSClientPostMessageSelectExceptionInfo = 0x10064290;
// R6GameService.dll code @ 100642a0
constexpr unsigned int UR6GSServers_execNativeIsWaitingForGSInitSelectExceptionInfo = 0x100642a0;
// R6GameService.dll code @ 100642b0
constexpr unsigned int UR6GSServers_execNativeIsGSReadyToChangeModSelectExceptionInfo = 0x100642b0;
// R6GameService.dll code @ 100642c0
constexpr unsigned int UR6GSServers_SetGSClientComInterfaceSelectExceptionInfo = 0x100642c0;
// R6GameService.dll code @ 100642d0
constexpr unsigned int UR6GSServers_PollGSClientCallbacksUnwind2 = 0x100642d0;
// R6GameService.dll code @ 100642d9
constexpr unsigned int UR6GSServers_PollGSClientCallbacksSelectExceptionInfo = 0x100642d9;
// R6GameService.dll code @ 100642f0
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoUnwind2 = 0x100642f0;
// R6GameService.dll code @ 100642f8
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoUnwind3 = 0x100642f8;
// R6GameService.dll code @ 10064300
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoSelectExceptionInfo = 0x10064300;
// R6GameService.dll code @ 10064310
constexpr unsigned int GetGameConfigCallbackUnwind1 = 0x10064310;
// R6GameService.dll code @ 10064318
constexpr unsigned int GetGameConfigCallbackUnwind2 = 0x10064318;
// R6GameService.dll code @ 10064320
constexpr unsigned int SelectGameConfigLifetime = 0x10064320;
// R6GameService.dll code @ 10064330
constexpr unsigned int UR6GSServers_InitGSClientSelectExceptionInfo = 0x10064330;
// R6GameService.dll code @ 10064340
constexpr unsigned int UR6GSServers_LogOutServerSelectExceptionInfo = 0x10064340;
// R6GameService.dll code @ 10064350
constexpr unsigned int UR6GSServers_execNativeLogOutServerSelectExceptionInfo = 0x10064350;
// R6GameService.dll code @ 10064360
constexpr unsigned int UR6GSServers_RegisterServerUnwind2 = 0x10064360;
// R6GameService.dll code @ 10064369
constexpr unsigned int UR6GSServers_RegisterServerSelectExceptionInfo = 0x10064369;
// R6GameService.dll code @ 10064380
constexpr unsigned int UR6GSServers_UpdateServerUnwind2 = 0x10064380;
// R6GameService.dll code @ 10064389
constexpr unsigned int UR6GSServers_UpdateServerSelectExceptionInfo = 0x10064389;
// R6GameService.dll code @ 100643a0
constexpr unsigned int UR6GSServers_execNativeUpdateServerSelectExceptionInfo = 0x100643a0;
// R6GameService.dll code @ 100643b0
constexpr unsigned int UR6GSServers_ServerLoginSelectExceptionInfo = 0x100643b0;
// R6GameService.dll code @ 100643c0
constexpr unsigned int UR6GSServers_RouterDisconnectSelectExceptionInfo = 0x100643c0;
// R6GameService.dll code @ 100643d0
constexpr unsigned int UR6GSServers_RegServerGetLobbiesSelectExceptionInfo = 0x100643d0;
// R6GameService.dll code @ 100643e0
constexpr unsigned int UR6GSServers_execHandleAnyLobbyConnectionFailSelectExceptionInfo = 0x100643e0;
// R6GameService.dll code @ 100643f0
constexpr unsigned int UR6GSServers_InitProcessUpdateUbiServerSelectExceptionInfo = 0x100643f0;
// R6GameService.dll code @ 10064400
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRouterRequestSelectExceptionInfo = 0x10064400;
// R6GameService.dll code @ 10064410
constexpr unsigned int UR6GSServers_ProcessRegServerGetLobbiesRequestSelectExceptionInfo = 0x10064410;
// R6GameService.dll code @ 10064420
constexpr unsigned int UR6GSServers_ProcessRegServerRegOnLobbyRequestSelectExceptionInfo = 0x10064420;
// R6GameService.dll code @ 10064430
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRequestSelectExceptionInfo = 0x10064430;
// R6GameService.dll code @ 10064440
constexpr unsigned int UR6GSServers_ProcessRegServerUpdateRequestSelectExceptionInfo = 0x10064440;
// R6GameService.dll code @ 10064450
constexpr unsigned int UR6GSServers_ServerRoundStartSelectExceptionInfo = 0x10064450;
// R6GameService.dll code @ 10064460
constexpr unsigned int UR6GSServers_ServerRoundFinishSelectExceptionInfo = 0x10064460;
// R6GameService.dll code @ 10064470
constexpr unsigned int unreal_array_support_DestroyArrayStorage6Unwind1 = 0x10064470;
// R6GameService.dll code @ 10064479
constexpr unsigned int SelectArray8Destruction = 0x10064479;
// R6GameService.dll code @ 10064490
constexpr unsigned int UR6GSServers_InitializeRegServerSelectExceptionInfo = 0x10064490;
// R6GameService.dll code @ 100644a0
constexpr unsigned int UR6GSServers_ProcessInternetSrvSelectExceptionInfo = 0x100644a0;
// R6GameService.dll code @ 100644b0
constexpr unsigned int ServerPing_GetPingTimeSelectExceptionInfo = 0x100644b0;
// R6GameService.dll code @ 100644c0
constexpr unsigned int DestroyPingRecordUnwind1 = 0x100644c0;
// R6GameService.dll code @ 100644c9
constexpr unsigned int DestroyPingRecordSelectExceptionInfo = 0x100644c9;
// R6GameService.dll code @ 100644e0
constexpr unsigned int ServerPing_NewPingRequestUnwind1 = 0x100644e0;
// R6GameService.dll code @ 100644e9
constexpr unsigned int ServerPing_NewPingRequestSelectExceptionInfo = 0x100644e9;
// R6GameService.dll code @ 10064500
constexpr unsigned int ServerPing_SendPingToServerSelectExceptionInfo = 0x10064500;
// R6GameService.dll code @ 10064510
constexpr unsigned int ServerPing_PingManagerSelectExceptionInfo = 0x10064510;
// R6GameService.dll code @ 10064520
constexpr unsigned int DestroyPingRequestArrayUnwind1 = 0x10064520;
// R6GameService.dll code @ 10064529
constexpr unsigned int DestroyPingRequestArraySelectExceptionInfo = 0x10064529;
// R6GameService.dll code @ 10064540
constexpr unsigned int InitializePingRequestArrayUnwind1 = 0x10064540;
// R6GameService.dll code @ 1006454b
constexpr unsigned int InitializePingRequestArraySelectExceptionInfo = 0x1006454b;
// R6GameService.dll code @ 10064560
constexpr unsigned int CleanupWinsockAndPingRequestsUnwind1 = 0x10064560;
// R6GameService.dll code @ 10064568
constexpr unsigned int CleanupWinsockAndPingRequestsSelectExceptionInfo = 0x10064568;
// R6GameService.dll code @ 10064580
constexpr unsigned int CreateRegisteredServiceWrapperUnwind1 = 0x10064580;
// R6GameService.dll code @ 1006458a
constexpr unsigned int CreateRegisteredServiceWrapperUnwind2 = 0x1006458a;
// R6GameService.dll code @ 10064594
constexpr unsigned int CreateRegisteredServiceWrapperUnwind3 = 0x10064594;
// R6GameService.dll code @ 100645ae
constexpr unsigned int CreateRegisteredServiceWrapperUnwind5 = 0x100645ae;
// R6GameService.dll code @ 100645b6
constexpr unsigned int CreateRegisteredServiceWrapperSelectExceptionInfo = 0x100645b6;
// R6GameService.dll code @ 100645c0
constexpr unsigned int DestroyHttpDownloadPointerMapUnwind1 = 0x100645c0;
// R6GameService.dll code @ 100645e7
constexpr unsigned int DestroyHttpDownloadPointerMapUnwind2 = 0x100645e7;
// R6GameService.dll code @ 100645ef
constexpr unsigned int DestroyHttpDownloadPointerMapSelectExceptionInfo = 0x100645ef;
// R6GameService.dll code @ 10064600
constexpr unsigned int ReleaseCountedTreeAndHeaderUnwind1 = 0x10064600;
// R6GameService.dll code @ 10064608
constexpr unsigned int ReleaseCountedTreeAndHeaderSelectExceptionInfo = 0x10064608;
// R6GameService.dll code @ 10064620
constexpr unsigned int InitializeHttpRequestRecordUnwind1 = 0x10064620;
// R6GameService.dll code @ 1006463d
constexpr unsigned int InitializeHttpRequestRecordUnwind2 = 0x1006463d;
// R6GameService.dll code @ 10064645
constexpr unsigned int InitializeHttpRequestRecordUnwind3 = 0x10064645;
// R6GameService.dll code @ 1006465f
constexpr unsigned int InitializeHttpRequestRecordUnwind4 = 0x1006465f;
// R6GameService.dll code @ 10064667
constexpr unsigned int InitializeHttpRequestRecordUnwind5 = 0x10064667;
// R6GameService.dll code @ 10064675
constexpr unsigned int InitializeHttpRequestRecordUnwind6 = 0x10064675;
// R6GameService.dll code @ 1006467f
constexpr unsigned int InitializeHttpRequestRecordUnwind7 = 0x1006467f;
// R6GameService.dll code @ 10064699
constexpr unsigned int InitializeHttpRequestRecordUnwind8 = 0x10064699;
// R6GameService.dll code @ 100646a1
constexpr unsigned int InitializeHttpRequestRecordSelectExceptionInfo = 0x100646a1;
// R6GameService.dll code @ 100646b0
constexpr unsigned int DestroyStringRecordRangeUnwind1 = 0x100646b0;
// R6GameService.dll code @ 100646b8
constexpr unsigned int DestroyStringRecordRangeUnwind2 = 0x100646b8;
// R6GameService.dll code @ 100646c3
constexpr unsigned int DestroyStringRecordRangeSelectExceptionInfo = 0x100646c3;
// R6GameService.dll code @ 100646d0
constexpr unsigned int DestroyServiceObjectMembersUnwind1 = 0x100646d0;
// R6GameService.dll code @ 100646d8
constexpr unsigned int DestroyServiceObjectMembersUnwind2 = 0x100646d8;
// R6GameService.dll code @ 100646e6
constexpr unsigned int DestroyServiceObjectMembersUnwind3 = 0x100646e6;
// R6GameService.dll code @ 100646ee
constexpr unsigned int DestroyServiceObjectMembersSelectExceptionInfo = 0x100646ee;
// R6GameService.dll code @ 10064700
constexpr unsigned int CHttpRequestParseHeaderUnwind6 = 0x10064700;
// R6GameService.dll code @ 1006470b
constexpr unsigned int CHttpRequestParseHeaderUnwind7 = 0x1006470b;
// R6GameService.dll code @ 10064716
constexpr unsigned int CHttpRequestParseHeaderUnwind8 = 0x10064716;
// R6GameService.dll code @ 10064721
constexpr unsigned int CHttpRequestParseHeaderUnwind9 = 0x10064721;
// R6GameService.dll code @ 10064738
constexpr unsigned int CHttpRequestParseHeaderUnwind10 = 0x10064738;
// R6GameService.dll code @ 10064743
constexpr unsigned int CHttpRequestParseHeaderUnwind1 = 0x10064743;
// R6GameService.dll code @ 1006474e
constexpr unsigned int CHttpRequestParseHeaderUnwind2 = 0x1006474e;
// R6GameService.dll code @ 10064759
constexpr unsigned int CHttpRequestParseHeaderUnwind3 = 0x10064759;
// R6GameService.dll code @ 10064764
constexpr unsigned int CHttpRequestParseHeaderUnwind4 = 0x10064764;
// R6GameService.dll code @ 1006477b
constexpr unsigned int CHttpRequestParseHeaderUnwind5 = 0x1006477b;
// R6GameService.dll code @ 10064786
constexpr unsigned int CHttpRequestParseHeaderUnwind11 = 0x10064786;
// R6GameService.dll code @ 10064791
constexpr unsigned int CHttpRequestParseHeaderUnwind12 = 0x10064791;
// R6GameService.dll code @ 1006479c
constexpr unsigned int CHttpRequestParseHeaderUnwind13 = 0x1006479c;
// R6GameService.dll code @ 100647a7
constexpr unsigned int CHttpRequestParseHeaderUnwind14 = 0x100647a7;
// R6GameService.dll code @ 100647b2
constexpr unsigned int CHttpRequestParseHeaderUnwind15 = 0x100647b2;
// R6GameService.dll code @ 100647bd
constexpr unsigned int CHttpRequestParseHeaderSelectExceptionInfo = 0x100647bd;
// R6GameService.dll code @ 100647d0
constexpr unsigned int DestroyOrderedTreeWrapperContentsUnwind1 = 0x100647d0;
// R6GameService.dll code @ 100647d8
constexpr unsigned int DestroyOrderedTreeWrapperContentsUnwind2 = 0x100647d8;
// R6GameService.dll code @ 100647e3
constexpr unsigned int DestroyOrderedTreeWrapperContentsUnwind3 = 0x100647e3;
// R6GameService.dll code @ 100647eb
constexpr unsigned int DestroyOrderedTreeWrapperContentsUnwind4 = 0x100647eb;
// R6GameService.dll code @ 100647f3
constexpr unsigned int DestroyOrderedTreeWrapperContentsSelectExceptionInfo = 0x100647f3;
// R6GameService.dll code @ 10064800
constexpr unsigned int ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwind1 = 0x10064800;
// R6GameService.dll code @ 10064808
constexpr unsigned int ordered_tree_support_DestroyOrderedTreeWrapperContentsSelectExceptionInfo = 0x10064808;
// R6GameService.dll code @ 10064820
constexpr unsigned int QueueHttpRequestUnwind1 = 0x10064820;
// R6GameService.dll code @ 1006482a
constexpr unsigned int QueueHttpRequestSelectExceptionInfo = 0x1006482a;
// R6GameService.dll code @ 10064840
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind1 = 0x10064840;
// R6GameService.dll code @ 1006484b
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind2 = 0x1006484b;
// R6GameService.dll code @ 10064856
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind3 = 0x10064856;
// R6GameService.dll code @ 10064861
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind5 = 0x10064861;
// R6GameService.dll code @ 1006486c
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind6 = 0x1006486c;
// R6GameService.dll code @ 10064877
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind7 = 0x10064877;
// R6GameService.dll code @ 10064882
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind9 = 0x10064882;
// R6GameService.dll code @ 1006488d
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwind10 = 0x1006488d;
// R6GameService.dll code @ 10064898
constexpr unsigned int ParseHttpUrlIntoRequestFieldsSelectExceptionInfo = 0x10064898;
// R6GameService.dll code @ 100648b0
constexpr unsigned int CopyByteStringRangeUnwind1 = 0x100648b0;
// R6GameService.dll code @ 100648bb
constexpr unsigned int CopyByteStringRangeUnwind2 = 0x100648bb;
// R6GameService.dll code @ 100648c6
constexpr unsigned int CopyByteStringRangeUnwind3 = 0x100648c6;
// R6GameService.dll code @ 100648d1
constexpr unsigned int CopyByteStringRangeUnwind4 = 0x100648d1;
// R6GameService.dll code @ 100648d9
constexpr unsigned int CopyByteStringRangeUnwind5 = 0x100648d9;
// R6GameService.dll code @ 100648e4
constexpr unsigned int CopyByteStringRangeUnwind6 = 0x100648e4;
// R6GameService.dll code @ 100648ef
constexpr unsigned int CopyByteStringRangeSelectExceptionInfo = 0x100648ef;
// R6GameService.dll code @ 10064900
constexpr unsigned int CleanupPooledBufferReleaseContext = 0x10064900;
// R6GameService.dll code @ 1006490b
constexpr unsigned int PooledBufferReleaseExceptionHandler = 0x1006490b;
// R6GameService.dll code @ 10064920
constexpr unsigned int RebuildThreeWordArrayUnwind2 = 0x10064920;
// R6GameService.dll code @ 10064931
constexpr unsigned int RebuildThreeWordArrayUnwind3 = 0x10064931;
// R6GameService.dll code @ 10064939
constexpr unsigned int RebuildThreeWordArrayUnwind5 = 0x10064939;
// R6GameService.dll code @ 10064944
constexpr unsigned int RebuildThreeWordArraySelectExceptionInfo = 0x10064944;
// R6GameService.dll code @ 10064950
constexpr unsigned int DestroyPooledStringConstruction = 0x10064950;
// R6GameService.dll code @ 1006495b
constexpr unsigned int UnlockPooledStringConstruction = 0x1006495b;
// R6GameService.dll code @ 10064963
constexpr unsigned int ReleasePooledStringErrorMessage = 0x10064963;
// R6GameService.dll code @ 1006496e
constexpr unsigned int PooledByteStringConstructExceptionHandler = 0x1006496e;
// R6GameService.dll code @ 10064980
constexpr unsigned int CopyStringRecordRangeUnwind2 = 0x10064980;
// R6GameService.dll code @ 10064991
constexpr unsigned int CopyStringRecordRangeUnwind3 = 0x10064991;
// R6GameService.dll code @ 10064999
constexpr unsigned int CopyStringRecordRangeSelectExceptionInfo = 0x10064999;
// R6GameService.dll code @ 100649b0
constexpr unsigned int RepeatStringRecordUnwind2 = 0x100649b0;
// R6GameService.dll code @ 100649c1
constexpr unsigned int RepeatStringRecordUnwind3 = 0x100649c1;
// R6GameService.dll code @ 100649c9
constexpr unsigned int RepeatStringRecordSelectExceptionInfo = 0x100649c9;
// R6GameService.dll code @ 100649e0
constexpr unsigned int ThrowByteStringLengthErrorUnwind1 = 0x100649e0;
// R6GameService.dll code @ 100649eb
constexpr unsigned int ThrowByteStringLengthErrorUnwind2 = 0x100649eb;
// R6GameService.dll code @ 100649f6
constexpr unsigned int ThrowByteStringLengthErrorSelectExceptionInfo = 0x100649f6;
// R6GameService.dll code @ 10064a00
constexpr unsigned int UnlockSmallByteStringAllocation = 0x10064a00;
// R6GameService.dll code @ 10064a08
constexpr unsigned int SmallByteStringAllocateExceptionHandler = 0x10064a08;
// R6GameService.dll code @ 10064a20
constexpr unsigned int ConstructHeapByteStringUnwind1 = 0x10064a20;
// R6GameService.dll code @ 10064a2b
constexpr unsigned int ConstructHeapByteStringUnwind2 = 0x10064a2b;
// R6GameService.dll code @ 10064a36
constexpr unsigned int ConstructHeapByteStringUnwind3 = 0x10064a36;
// R6GameService.dll code @ 10064a41
constexpr unsigned int ConstructHeapByteStringSelectExceptionInfo = 0x10064a41;
// R6GameService.dll code @ 10064a50
constexpr unsigned int DestroyStoredValueTreeUnwind1 = 0x10064a50;
// R6GameService.dll code @ 10064a58
constexpr unsigned int DestroyStoredValueTreeSelectExceptionInfo = 0x10064a58;
// R6GameService.dll code @ 10064a70
constexpr unsigned int SerializeStoredValuesToBufferUnwind1 = 0x10064a70;
// R6GameService.dll code @ 10064a87
constexpr unsigned int SerializeStoredValuesToBufferUnwind2 = 0x10064a87;
// R6GameService.dll code @ 10064a92
constexpr unsigned int SerializeStoredValuesToBufferUnwind3 = 0x10064a92;
// R6GameService.dll code @ 10064a9a
constexpr unsigned int SerializeStoredValuesToBufferUnwind4 = 0x10064a9a;
// R6GameService.dll code @ 10064ab1
constexpr unsigned int SerializeStoredValuesToBufferUnwind5 = 0x10064ab1;
// R6GameService.dll code @ 10064abc
constexpr unsigned int SerializeStoredValuesToBufferUnwind6 = 0x10064abc;
// R6GameService.dll code @ 10064ac4
constexpr unsigned int SerializeStoredValuesToBufferUnwind7 = 0x10064ac4;
// R6GameService.dll code @ 10064adb
constexpr unsigned int SerializeStoredValuesToBufferUnwind8 = 0x10064adb;
// R6GameService.dll code @ 10064ae6
constexpr unsigned int SerializeStoredValuesToBufferUnwind9 = 0x10064ae6;
// R6GameService.dll code @ 10064aee
constexpr unsigned int SerializeStoredValuesToBufferUnwind10 = 0x10064aee;
// R6GameService.dll code @ 10064b05
constexpr unsigned int SerializeStoredValuesToBufferUnwind11 = 0x10064b05;
// R6GameService.dll code @ 10064b10
constexpr unsigned int SerializeStoredValuesToBufferUnwind12 = 0x10064b10;
// R6GameService.dll code @ 10064b18
constexpr unsigned int SerializeStoredValuesToBufferUnwind13 = 0x10064b18;
// R6GameService.dll code @ 10064b2f
constexpr unsigned int SerializeStoredValuesToBufferUnwind14 = 0x10064b2f;
// R6GameService.dll code @ 10064b3a
constexpr unsigned int SerializeStoredValuesToBufferUnwind15 = 0x10064b3a;
// R6GameService.dll code @ 10064b42
constexpr unsigned int SerializeStoredValuesToBufferUnwind16 = 0x10064b42;
// R6GameService.dll code @ 10064b59
constexpr unsigned int SerializeStoredValuesToBufferUnwind17 = 0x10064b59;
// R6GameService.dll code @ 10064b64
constexpr unsigned int SerializeStoredValuesToBufferUnwind18 = 0x10064b64;
// R6GameService.dll code @ 10064b6c
constexpr unsigned int SerializeStoredValuesToBufferUnwind19 = 0x10064b6c;
// R6GameService.dll code @ 10064b83
constexpr unsigned int SerializeStoredValuesToBufferUnwind20 = 0x10064b83;
// R6GameService.dll code @ 10064b8e
constexpr unsigned int SerializeStoredValuesToBufferUnwind21 = 0x10064b8e;
// R6GameService.dll code @ 10064b96
constexpr unsigned int SerializeStoredValuesToBufferSelectExceptionInfo = 0x10064b96;
// R6GameService.dll code @ 10064ba0
constexpr unsigned int AllocateAndTrackContextUnwind1 = 0x10064ba0;
// R6GameService.dll code @ 10064baa
constexpr unsigned int AllocateAndTrackContextUnwind2 = 0x10064baa;
// R6GameService.dll code @ 10064bb4
constexpr unsigned int AllocateAndTrackContextUnwind3 = 0x10064bb4;
// R6GameService.dll code @ 10064bce
constexpr unsigned int AllocateAndTrackContextUnwind5 = 0x10064bce;
// R6GameService.dll code @ 10064bd6
constexpr unsigned int SelectContextFactoryLifetime = 0x10064bd6;
// R6GameService.dll code @ 10064be0
constexpr unsigned int DestroyCCDKeyProcessMapTreeOnUnwind = 0x10064be0;
// R6GameService.dll code @ 10064c07
constexpr unsigned int ReleaseCCDKeyProcessMapHeaderOnUnwind = 0x10064c07;
// R6GameService.dll code @ 10064c0f
constexpr unsigned int CCDKeyProcessMapDestroyExceptionHandler = 0x10064c0f;
// R6GameService.dll code @ 10064c20
constexpr unsigned int ReleaseOwnedMapTreeHeader = 0x10064c20;
// R6GameService.dll code @ 10064c28
constexpr unsigned int OwnedMapTreeDestroyExceptionHandler = 0x10064c28;
// R6GameService.dll code @ 10064c40
constexpr unsigned int CCDKeyProcessUnwind = 0x10064c40;
// R6GameService.dll code @ 10064c5d
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind = 0x10064c5d;
// R6GameService.dll code @ 10064c65
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind2 = 0x10064c65;
// R6GameService.dll code @ 10064c7f
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind3 = 0x10064c7f;
// R6GameService.dll code @ 10064c87
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind4 = 0x10064c87;
// R6GameService.dll code @ 10064c92
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind5 = 0x10064c92;
// R6GameService.dll code @ 10064cac
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind6 = 0x10064cac;
// R6GameService.dll code @ 10064cb4
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind7 = 0x10064cb4;
// R6GameService.dll code @ 10064cbf
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind8 = 0x10064cbf;
// R6GameService.dll code @ 10064cd9
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind9 = 0x10064cd9;
// R6GameService.dll code @ 10064ce1
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind10 = 0x10064ce1;
// R6GameService.dll code @ 10064cec
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind11 = 0x10064cec;
// R6GameService.dll code @ 10064d06
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind12 = 0x10064d06;
// R6GameService.dll code @ 10064d0e
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind13 = 0x10064d0e;
// R6GameService.dll code @ 10064d19
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind14 = 0x10064d19;
// R6GameService.dll code @ 10064d33
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind15 = 0x10064d33;
// R6GameService.dll code @ 10064d3e
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind16 = 0x10064d3e;
// R6GameService.dll code @ 10064d48
constexpr unsigned int SelectCCDKeyConstruction = 0x10064d48;
// R6GameService.dll code @ 10064d60
constexpr unsigned int ReleaseSavedTreeHeaderOnUnwind = 0x10064d60;
// R6GameService.dll code @ 10064d68
constexpr unsigned int TreeDestructionExceptionHandler = 0x10064d68;
// R6GameService.dll code @ 10064d80
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind17 = 0x10064d80;
// R6GameService.dll code @ 10064d88
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind18 = 0x10064d88;
// R6GameService.dll code @ 10064d93
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind19 = 0x10064d93;
// R6GameService.dll code @ 10064d9e
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind20 = 0x10064d9e;
// R6GameService.dll code @ 10064da9
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind21 = 0x10064da9;
// R6GameService.dll code @ 10064db4
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind22 = 0x10064db4;
// R6GameService.dll code @ 10064dbf
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind23 = 0x10064dbf;
// R6GameService.dll code @ 10064dc7
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind24 = 0x10064dc7;
// R6GameService.dll code @ 10064dcf
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind25 = 0x10064dcf;
// R6GameService.dll code @ 10064dd7
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind26 = 0x10064dd7;
// R6GameService.dll code @ 10064ddf
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind27 = 0x10064ddf;
// R6GameService.dll code @ 10064de7
constexpr unsigned int SelectCCDKeyDestruction = 0x10064de7;
// R6GameService.dll code @ 10064e00
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind28 = 0x10064e00;
// R6GameService.dll code @ 10064e0b
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind29 = 0x10064e0b;
// R6GameService.dll code @ 10064e16
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind30 = 0x10064e16;
// R6GameService.dll code @ 10064e21
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind31 = 0x10064e21;
// R6GameService.dll code @ 10064e2c
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind32 = 0x10064e2c;
// R6GameService.dll code @ 10064e62
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind33 = 0x10064e62;
// R6GameService.dll code @ 10064e6d
constexpr unsigned int SelectInputLifetime = 0x10064e6d;
// R6GameService.dll code @ 10064e80
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind34 = 0x10064e80;
// R6GameService.dll code @ 10064e88
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind35 = 0x10064e88;
// R6GameService.dll code @ 10064e90
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind36 = 0x10064e90;
// R6GameService.dll code @ 10064e98
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind37 = 0x10064e98;
// R6GameService.dll code @ 10064ea0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind38 = 0x10064ea0;
// R6GameService.dll code @ 10064ea8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind39 = 0x10064ea8;
// R6GameService.dll code @ 10064eb0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind40 = 0x10064eb0;
// R6GameService.dll code @ 10064ed7
constexpr unsigned int SelectDescriptorLifetime = 0x10064ed7;
// R6GameService.dll code @ 10064ef0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind41 = 0x10064ef0;
// R6GameService.dll code @ 10064ef8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind42 = 0x10064ef8;
// R6GameService.dll code @ 10064f00
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind43 = 0x10064f00;
// R6GameService.dll code @ 10064f08
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind44 = 0x10064f08;
// R6GameService.dll code @ 10064f10
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind45 = 0x10064f10;
// R6GameService.dll code @ 10064f18
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind46 = 0x10064f18;
// R6GameService.dll code @ 10064f20
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind47 = 0x10064f20;
// R6GameService.dll code @ 10064f28
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind48 = 0x10064f28;
// R6GameService.dll code @ 10064f30
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind49 = 0x10064f30;
// R6GameService.dll code @ 10064f38
constexpr unsigned int SelectCompoundLifetime = 0x10064f38;
// R6GameService.dll code @ 10064f50
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind50 = 0x10064f50;
// R6GameService.dll code @ 10064f5b
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind51 = 0x10064f5b;
// R6GameService.dll code @ 10064f66
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind52 = 0x10064f66;
// R6GameService.dll code @ 10064f71
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind53 = 0x10064f71;
// R6GameService.dll code @ 10064fa7
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind54 = 0x10064fa7;
// R6GameService.dll code @ 10064fb2
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind55 = 0x10064fb2;
// R6GameService.dll code @ 10064fe8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind56 = 0x10064fe8;
// R6GameService.dll code @ 10064ff3
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind57 = 0x10064ff3;
// R6GameService.dll code @ 10065029
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind58 = 0x10065029;
// R6GameService.dll code @ 10065034
constexpr unsigned int SelectParsedLifetime = 0x10065034;
// R6GameService.dll code @ 10065040
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind59 = 0x10065040;
// R6GameService.dll code @ 1006504b
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind60 = 0x1006504b;
// R6GameService.dll code @ 10065053
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind61 = 0x10065053;
// R6GameService.dll code @ 1006505e
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind62 = 0x1006505e;
// R6GameService.dll code @ 10065069
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind63 = 0x10065069;
// R6GameService.dll code @ 10065099
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind64 = 0x10065099;
// R6GameService.dll code @ 100650a4
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind65 = 0x100650a4;
// R6GameService.dll code @ 100650d4
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind66 = 0x100650d4;
// R6GameService.dll code @ 100650df
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind67 = 0x100650df;
// R6GameService.dll code @ 1006510f
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind68 = 0x1006510f;
// R6GameService.dll code @ 1006511a
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind69 = 0x1006511a;
// R6GameService.dll code @ 1006514a
constexpr unsigned int SelectType14Lifetime = 0x1006514a;
// R6GameService.dll code @ 10065160
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind70 = 0x10065160;
// R6GameService.dll code @ 10065168
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind71 = 0x10065168;
// R6GameService.dll code @ 10065170
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind72 = 0x10065170;
// R6GameService.dll code @ 10065178
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind73 = 0x10065178;
// R6GameService.dll code @ 1006519f
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind74 = 0x1006519f;
// R6GameService.dll code @ 100651a7
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind75 = 0x100651a7;
// R6GameService.dll code @ 100651ce
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind76 = 0x100651ce;
// R6GameService.dll code @ 100651d6
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind77 = 0x100651d6;
// R6GameService.dll code @ 100651fd
constexpr unsigned int SelectType23Lifetime = 0x100651fd;
// R6GameService.dll code @ 10065210
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind78 = 0x10065210;
// R6GameService.dll code @ 10065218
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind79 = 0x10065218;
// R6GameService.dll code @ 10065220
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind80 = 0x10065220;
// R6GameService.dll code @ 10065228
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind81 = 0x10065228;
// R6GameService.dll code @ 1006524f
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind82 = 0x1006524f;
// R6GameService.dll code @ 10065257
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind83 = 0x10065257;
// R6GameService.dll code @ 1006527e
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind84 = 0x1006527e;
// R6GameService.dll code @ 10065286
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind85 = 0x10065286;
// R6GameService.dll code @ 100652ad
constexpr unsigned int CCDKeyProcess_SelectType23Lifetime = 0x100652ad;
// R6GameService.dll code @ 100652c0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind86 = 0x100652c0;
// R6GameService.dll code @ 100652c8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind87 = 0x100652c8;
// R6GameService.dll code @ 100652d0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind88 = 0x100652d0;
// R6GameService.dll code @ 100652d8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind89 = 0x100652d8;
// R6GameService.dll code @ 100652e0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind90 = 0x100652e0;
// R6GameService.dll code @ 100652e8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind91 = 0x100652e8;
// R6GameService.dll code @ 100652f0
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind92 = 0x100652f0;
// R6GameService.dll code @ 100652f8
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind93 = 0x100652f8;
// R6GameService.dll code @ 10065300
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind94 = 0x10065300;
// R6GameService.dll code @ 10065308
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind95 = 0x10065308;
// R6GameService.dll code @ 10065338
constexpr unsigned int CCDKeyProcess_SelectType14Lifetime = 0x10065338;
// R6GameService.dll code @ 10065350
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind96 = 0x10065350;
// R6GameService.dll code @ 10065358
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind97 = 0x10065358;
// R6GameService.dll code @ 10065360
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind98 = 0x10065360;
// R6GameService.dll code @ 10065368
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind99 = 0x10065368;
// R6GameService.dll code @ 10065370
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind100 = 0x10065370;
// R6GameService.dll code @ 10065397
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind101 = 0x10065397;
// R6GameService.dll code @ 1006539f
constexpr unsigned int CCDKeyProcess_CCDKeyProcessUnwind102 = 0x1006539f;
// R6GameService.dll code @ 100653c6
constexpr unsigned int CCDKeyProcess_SelectParsedLifetime = 0x100653c6;
// R6GameService.dll code @ 100653d0
constexpr unsigned int SendTag11DescriptorUnwind1 = 0x100653d0;
// R6GameService.dll code @ 100653d8
constexpr unsigned int SendTag11DescriptorUnwind2 = 0x100653d8;
// R6GameService.dll code @ 100653e0
constexpr unsigned int SendTag11DescriptorUnwind3 = 0x100653e0;
// R6GameService.dll code @ 100653e8
constexpr unsigned int SendTag11DescriptorUnwind4 = 0x100653e8;
// R6GameService.dll code @ 100653f0
constexpr unsigned int SendTag11DescriptorUnwind5 = 0x100653f0;
// R6GameService.dll code @ 100653f8
constexpr unsigned int SendTag11DescriptorUnwind6 = 0x100653f8;
// R6GameService.dll code @ 10065400
constexpr unsigned int SendTag11DescriptorUnwind7 = 0x10065400;
// R6GameService.dll code @ 10065427
constexpr unsigned int SelectSend11Lifetime = 0x10065427;
// R6GameService.dll code @ 10065440
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind1 = 0x10065440;
// R6GameService.dll code @ 10065448
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind2 = 0x10065448;
// R6GameService.dll code @ 10065450
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind3 = 0x10065450;
// R6GameService.dll code @ 10065458
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind4 = 0x10065458;
// R6GameService.dll code @ 10065460
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind5 = 0x10065460;
// R6GameService.dll code @ 10065468
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind6 = 0x10065468;
// R6GameService.dll code @ 10065470
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwind7 = 0x10065470;
// R6GameService.dll code @ 10065497
constexpr unsigned int SelectSendPairLifetime = 0x10065497;
// R6GameService.dll code @ 100654b0
constexpr unsigned int ReleaseTimestampedInputFields = 0x100654b0;
// R6GameService.dll code @ 100654b8
constexpr unsigned int ReleaseTimestampedFirstPair = 0x100654b8;
// R6GameService.dll code @ 100654c0
constexpr unsigned int ReleaseTimestampedInsertionPair = 0x100654c0;
// R6GameService.dll code @ 100654c8
constexpr unsigned int CleanupTimestampedInsertionCapacity = 0x100654c8;
// R6GameService.dll code @ 100654d3
constexpr unsigned int CleanupTimestampedFirstPairCapacity = 0x100654d3;
// R6GameService.dll code @ 100654de
constexpr unsigned int CleanupTimestampedInputCapacity = 0x100654de;
// R6GameService.dll code @ 100654e9
constexpr unsigned int TimestampedDescriptorStoreExceptionHandler = 0x100654e9;
// R6GameService.dll code @ 10065500
constexpr unsigned int CleanupPoolDescriptorCapacityContext = 0x10065500;
// R6GameService.dll code @ 1006550b
constexpr unsigned int PoolDescriptorReleaseExceptionHandler = 0x1006550b;
// R6GameService.dll code @ 10065520
constexpr unsigned int ProcessExpiredInputRecordsUnwind1 = 0x10065520;
// R6GameService.dll code @ 1006552b
constexpr unsigned int ProcessExpiredInputRecordsUnwind2 = 0x1006552b;
// R6GameService.dll code @ 10065536
constexpr unsigned int ProcessExpiredInputRecordsUnwind3 = 0x10065536;
// R6GameService.dll code @ 10065541
constexpr unsigned int ProcessExpiredInputRecordsUnwind4 = 0x10065541;
// R6GameService.dll code @ 1006554c
constexpr unsigned int ProcessExpiredInputRecordsUnwind5 = 0x1006554c;
// R6GameService.dll code @ 10065557
constexpr unsigned int ProcessExpiredInputRecordsUnwind6 = 0x10065557;
// R6GameService.dll code @ 10065562
constexpr unsigned int ProcessExpiredInputRecordsUnwind7 = 0x10065562;
// R6GameService.dll code @ 10065598
constexpr unsigned int SelectExpiryLifetime = 0x10065598;
// R6GameService.dll code @ 100655b0
constexpr unsigned int SendPeriodicCollectionSnapshotUnwind1 = 0x100655b0;
// R6GameService.dll code @ 100655bb
constexpr unsigned int SendPeriodicCollectionSnapshotUnwind2 = 0x100655bb;
// R6GameService.dll code @ 100655c6
constexpr unsigned int SendPeriodicCollectionSnapshotUnwind3 = 0x100655c6;
// R6GameService.dll code @ 100655d1
constexpr unsigned int SendPeriodicCollectionSnapshotUnwind4 = 0x100655d1;
// R6GameService.dll code @ 10065607
constexpr unsigned int SelectSnapshotLifetime = 0x10065607;
// R6GameService.dll code @ 10065620
constexpr unsigned int ReleaseClDataPointerListOnUnwind = 0x10065620;
// R6GameService.dll code @ 10065647
constexpr unsigned int ClDataPointerListExceptionHandler = 0x10065647;
// R6GameService.dll code @ 10065660
constexpr unsigned int ResetClDataListBaseOnUnwind = 0x10065660;
// R6GameService.dll code @ 10065668
constexpr unsigned int ReleaseClDataListStorageOnUnwind = 0x10065668;
// R6GameService.dll code @ 1006568f
constexpr unsigned int ClDataListExceptionHandler = 0x1006568f;
// R6GameService.dll code @ 100656a0
constexpr unsigned int ReleaseEmptyPooledBufferConstruction = 0x100656a0;
// R6GameService.dll code @ 100656a8
constexpr unsigned int UnlockEmptyPooledBufferConstruction = 0x100656a8;
// R6GameService.dll code @ 100656b0
constexpr unsigned int EmptyPooledBufferInitExceptionHandler = 0x100656b0;
// R6GameService.dll code @ 100656c0
constexpr unsigned int ReleaseTimestampedPairConstruction = 0x100656c0;
// R6GameService.dll code @ 100656cb
constexpr unsigned int ReleaseTimestampedPairErrorMessage = 0x100656cb;
// R6GameService.dll code @ 100656d6
constexpr unsigned int TimestampedDescriptorPairExceptionHandler = 0x100656d6;
// R6GameService.dll code @ 100656e0
constexpr unsigned int ReleasePooledTripletCopyConstruction = 0x100656e0;
// R6GameService.dll code @ 100656eb
constexpr unsigned int ReleasePooledTripletCopyErrorMessage = 0x100656eb;
// R6GameService.dll code @ 100656f6
constexpr unsigned int ReleasePooledTripletCopyErrorMessageLate = 0x100656f6;
// R6GameService.dll code @ 10065701
constexpr unsigned int PooledTripletCopyExceptionHandler = 0x10065701;
// R6GameService.dll code @ 10065710
constexpr unsigned int CleanupTimestampedNodePayloadContext = 0x10065710;
// R6GameService.dll code @ 10065721
constexpr unsigned int ReleaseTimestampedNodeConstructedTriplet = 0x10065721;
// R6GameService.dll code @ 10065729
constexpr unsigned int TimestampedNodeConstructExceptionHandler = 0x10065729;
// R6GameService.dll code @ 10065740
constexpr unsigned int CleanupByteDescriptorNodeContext = 0x10065740;
// R6GameService.dll code @ 10065751
constexpr unsigned int ReleaseByteDescriptorNodePayload = 0x10065751;
// R6GameService.dll code @ 10065759
constexpr unsigned int ByteDescriptorNodeConstructionExceptionHandler = 0x10065759;
// R6GameService.dll code @ 10065770
constexpr unsigned int CleanupMessageBufferAllocationContext = 0x10065770;
// R6GameService.dll code @ 1006578a
constexpr unsigned int ResetMessageBufferConstructionBase = 0x1006578a;
// R6GameService.dll code @ 10065792
constexpr unsigned int CleanupMessageBufferFirstQueueContext = 0x10065792;
// R6GameService.dll code @ 100657ac
constexpr unsigned int CleanupMessageBufferFirstQueueTag = 0x100657ac;
// R6GameService.dll code @ 100657b4
constexpr unsigned int ReleaseMessageBufferFirstQueue = 0x100657b4;
// R6GameService.dll code @ 100657bf
constexpr unsigned int CleanupMessageBufferSendQueueContext = 0x100657bf;
// R6GameService.dll code @ 100657d9
constexpr unsigned int CleanupMessageBufferSendQueueTag = 0x100657d9;
// R6GameService.dll code @ 100657e1
constexpr unsigned int ReleaseMessageBufferSendQueue = 0x100657e1;
// R6GameService.dll code @ 100657ec
constexpr unsigned int ReleaseMessageBufferSocketAllocation = 0x100657ec;
// R6GameService.dll code @ 100657f6
constexpr unsigned int MessageBufferConstructionExceptionHandler = 0x100657f6;
// R6GameService.dll code @ 10065800
constexpr unsigned int ResetMessageBufferDestructionBase = 0x10065800;
// R6GameService.dll code @ 10065808
constexpr unsigned int CleanupMessageBufferFirstQueueOnDestruction = 0x10065808;
// R6GameService.dll code @ 10065813
constexpr unsigned int CleanupMessageBufferSendQueueOnDestruction = 0x10065813;
// R6GameService.dll code @ 1006581e
constexpr unsigned int CleanupMessageBufferSavedQueueOnDestruction = 0x1006581e;
// R6GameService.dll code @ 10065826
constexpr unsigned int CleanupMessageBufferSavedFirstQueueOnDestruction = 0x10065826;
// R6GameService.dll code @ 1006582e
constexpr unsigned int MessageBufferDestructionExceptionHandler = 0x1006582e;
// R6GameService.dll code @ 10065840
constexpr unsigned int CleanupReceivedCDKeyMessage = 0x10065840;
// R6GameService.dll code @ 1006584b
constexpr unsigned int ReleaseReplacementDatagramSocket = 0x1006584b;
// R6GameService.dll code @ 10065858
constexpr unsigned int MessageBufferReceiveExceptionHandler = 0x10065858;
// R6GameService.dll code @ 10065870
constexpr unsigned int CleanupQueuedCDKeyMessage = 0x10065870;
// R6GameService.dll code @ 1006587b
constexpr unsigned int MessageBufferQueueExceptionHandler = 0x1006587b;
// R6GameService.dll code @ 10065890
constexpr unsigned int CleanupClDataListCloneVirtualBase = 0x10065890;
// R6GameService.dll code @ 100658aa
constexpr unsigned int ResetClDataListCloneBase = 0x100658aa;
// R6GameService.dll code @ 100658b2
constexpr unsigned int DestroyClDataListCloneInnerList = 0x100658b2;
// R6GameService.dll code @ 100658bd
constexpr unsigned int ReleaseClDataListStringCloneAllocation = 0x100658bd;
// R6GameService.dll code @ 100658c7
constexpr unsigned int CleanupClDataListStringCloneVirtualBase = 0x100658c7;
// R6GameService.dll code @ 100658e1
constexpr unsigned int ResetClDataListStringCloneBase = 0x100658e1;
// R6GameService.dll code @ 100658e9
constexpr unsigned int ReleaseClDataListStringCloneBuffer = 0x100658e9;
// R6GameService.dll code @ 100658f4
constexpr unsigned int ReleaseClDataListBinaryCloneAllocation = 0x100658f4;
// R6GameService.dll code @ 100658fe
constexpr unsigned int CleanupClDataListBinaryCloneVirtualBase = 0x100658fe;
// R6GameService.dll code @ 10065918
constexpr unsigned int ResetClDataListBinaryCloneBase = 0x10065918;
// R6GameService.dll code @ 10065920
constexpr unsigned int ReleaseClDataListBinaryCloneBuffer = 0x10065920;
// R6GameService.dll code @ 1006592b
constexpr unsigned int ReleaseClDataListNestedCloneAllocation = 0x1006592b;
// R6GameService.dll code @ 10065935
constexpr unsigned int ReleaseClDataListScalar4CloneAllocation = 0x10065935;
// R6GameService.dll code @ 1006593f
constexpr unsigned int CleanupClDataListScalar4CloneVirtualBase = 0x1006593f;
// R6GameService.dll code @ 10065959
constexpr unsigned int ReleaseClDataListScalar5CloneAllocation = 0x10065959;
// R6GameService.dll code @ 10065963
constexpr unsigned int CleanupClDataListScalar5CloneVirtualBase = 0x10065963;
// R6GameService.dll code @ 1006597d
constexpr unsigned int ClDataListCloneExceptionHandler = 0x1006597d;
// R6GameService.dll code @ 10065990
constexpr unsigned int ReleaseAssignmentStringAllocation = 0x10065990;
// R6GameService.dll code @ 1006599a
constexpr unsigned int CleanupAssignmentStringVirtualBase = 0x1006599a;
// R6GameService.dll code @ 100659b4
constexpr unsigned int ResetAssignmentStringBase = 0x100659b4;
// R6GameService.dll code @ 100659bc
constexpr unsigned int ReleaseAssignmentStringBuffer = 0x100659bc;
// R6GameService.dll code @ 100659c7
constexpr unsigned int ReleaseAssignmentBinaryAllocation = 0x100659c7;
// R6GameService.dll code @ 100659d1
constexpr unsigned int CleanupAssignmentBinaryVirtualBase = 0x100659d1;
// R6GameService.dll code @ 100659eb
constexpr unsigned int ResetAssignmentBinaryBase = 0x100659eb;
// R6GameService.dll code @ 100659f3
constexpr unsigned int ReleaseAssignmentBinaryBuffer = 0x100659f3;
// R6GameService.dll code @ 100659fe
constexpr unsigned int ReleaseAssignmentNestedAllocation = 0x100659fe;
// R6GameService.dll code @ 10065a08
constexpr unsigned int ReleaseAssignmentScalar4Allocation = 0x10065a08;
// R6GameService.dll code @ 10065a12
constexpr unsigned int CleanupAssignmentScalar4VirtualBase = 0x10065a12;
// R6GameService.dll code @ 10065a2c
constexpr unsigned int ReleaseAssignmentScalar5Allocation = 0x10065a2c;
// R6GameService.dll code @ 10065a36
constexpr unsigned int CleanupAssignmentScalar5VirtualBase = 0x10065a36;
// R6GameService.dll code @ 10065a50
constexpr unsigned int ClDataListAssignmentExceptionHandler = 0x10065a50;
// R6GameService.dll code @ 10065a60
constexpr unsigned int CleanupClDataListIndentContext = 0x10065a60;
// R6GameService.dll code @ 10065a68
constexpr unsigned int ReleaseClDataListIndentFillBuffer = 0x10065a68;
// R6GameService.dll code @ 10065a70
constexpr unsigned int ReleaseClDataListIndentBuffer = 0x10065a70;
// R6GameService.dll code @ 10065a78
constexpr unsigned int ClDataListIndentExceptionHandler = 0x10065a78;
// R6GameService.dll code @ 10065a90
constexpr unsigned int ReleaseClDataListStringAppendAllocation = 0x10065a90;
// R6GameService.dll code @ 10065a9a
constexpr unsigned int ResetClDataListStringAppendBase = 0x10065a9a;
// R6GameService.dll code @ 10065aa2
constexpr unsigned int CleanupClDataListStringAppendContext = 0x10065aa2;
// R6GameService.dll code @ 10065aaa
constexpr unsigned int ReleaseClDataListStringAppendBuffer = 0x10065aaa;
// R6GameService.dll code @ 10065ab2
constexpr unsigned int ClDataListStringAppendExceptionHandler = 0x10065ab2;
// R6GameService.dll code @ 10065ac0
constexpr unsigned int ReleaseClDataListAppendAllocation = 0x10065ac0;
// R6GameService.dll code @ 10065aca
constexpr unsigned int ResetClDataListAppendBase = 0x10065aca;
// R6GameService.dll code @ 10065ad2
constexpr unsigned int CleanupClDataListAppendContext = 0x10065ad2;
// R6GameService.dll code @ 10065ada
constexpr unsigned int ClDataListAppendExceptionHandler = 0x10065ada;
// R6GameService.dll code @ 10065af0
constexpr unsigned int ResetBoundedIndexedStringBase = 0x10065af0;
// R6GameService.dll code @ 10065af8
constexpr unsigned int DestroyBoundedIndexedString = 0x10065af8;
// R6GameService.dll code @ 10065b00
constexpr unsigned int ResetBoundedStringAfterCopy = 0x10065b00;
// R6GameService.dll code @ 10065b08
constexpr unsigned int ResetBoundedStringAfterFailure = 0x10065b08;
// R6GameService.dll code @ 10065b10
constexpr unsigned int CleanupBoundedStringSavedContext = 0x10065b10;
// R6GameService.dll code @ 10065b1b
constexpr unsigned int BoundedIndexedStringExceptionHandler = 0x10065b1b;
// R6GameService.dll code @ 10065b30
constexpr unsigned int ResetIndexedTextScalarBase = 0x10065b30;
// R6GameService.dll code @ 10065b38
constexpr unsigned int CleanupIndexedScalarConstructorTag = 0x10065b38;
// R6GameService.dll code @ 10065b40
constexpr unsigned int DestroyIndexedTextScalar = 0x10065b40;
// R6GameService.dll code @ 10065b48
constexpr unsigned int ResetIndexedScalarDuringRelease = 0x10065b48;
// R6GameService.dll code @ 10065b50
constexpr unsigned int CleanupIndexedScalarSavedContext = 0x10065b50;
// R6GameService.dll code @ 10065b5b
constexpr unsigned int IndexedTextScalarExceptionHandler = 0x10065b5b;
// R6GameService.dll code @ 10065b70
constexpr unsigned int ResetExactIndexedBytesBase = 0x10065b70;
// R6GameService.dll code @ 10065b78
constexpr unsigned int DestroyExactIndexedBytes = 0x10065b78;
// R6GameService.dll code @ 10065b80
constexpr unsigned int ResetExactBytesDuringRelease = 0x10065b80;
// R6GameService.dll code @ 10065b88
constexpr unsigned int CleanupExactBytesSavedContext = 0x10065b88;
// R6GameService.dll code @ 10065b93
constexpr unsigned int ExactIndexedBytesExceptionHandler = 0x10065b93;
// R6GameService.dll code @ 10065ba0
constexpr unsigned int ResetSerializationBinaryBase = 0x10065ba0;
// R6GameService.dll code @ 10065ba8
constexpr unsigned int DestroySerializationBinary = 0x10065ba8;
// R6GameService.dll code @ 10065bb0
constexpr unsigned int ResetSerializationSerializer = 0x10065bb0;
// R6GameService.dll code @ 10065bb8
constexpr unsigned int ResetSerializationBinaryAfterFailure = 0x10065bb8;
// R6GameService.dll code @ 10065bc0
constexpr unsigned int ResetSerializationBinaryAfterCopyFailure = 0x10065bc0;
// R6GameService.dll code @ 10065bc8
constexpr unsigned int ResetSerializationBinaryAfterSuccess = 0x10065bc8;
// R6GameService.dll code @ 10065bd0
constexpr unsigned int ResetSerializationBinaryAfterSizeProbe = 0x10065bd0;
// R6GameService.dll code @ 10065bd8
constexpr unsigned int ClDataListSerializationExceptionHandler = 0x10065bd8;
// R6GameService.dll code @ 10065bf0
constexpr unsigned int ResetParseBinaryBase = 0x10065bf0;
// R6GameService.dll code @ 10065bf8
constexpr unsigned int CleanupParseTripletContext = 0x10065bf8;
// R6GameService.dll code @ 10065c00
constexpr unsigned int DestroyParseBinary = 0x10065c00;
// R6GameService.dll code @ 10065c08
constexpr unsigned int ResetParseSerializer = 0x10065c08;
// R6GameService.dll code @ 10065c10
constexpr unsigned int ResetParseBinaryAfterRelease = 0x10065c10;
// R6GameService.dll code @ 10065c18
constexpr unsigned int ClDataListParseExceptionHandler = 0x10065c18;
// R6GameService.dll code @ 10065c30
constexpr unsigned int UnwindTripletAllocatorContext = 0x10065c30;
// R6GameService.dll code @ 10065c3e
constexpr unsigned int UnwindTripletDiagnosticTag = 0x10065c3e;
// R6GameService.dll code @ 10065c49
constexpr unsigned int UnwindTripletPartialDiagnostic = 0x10065c49;
// R6GameService.dll code @ 10065c54
constexpr unsigned int UnwindTripletCompleteDiagnostic = 0x10065c54;
// R6GameService.dll code @ 10065c5f
constexpr unsigned int SelectTripletBufferLifetime = 0x10065c5f;
// R6GameService.dll code @ 10065c70
constexpr unsigned int ReleaseReserveErrorMessage = 0x10065c70;
// R6GameService.dll code @ 10065c7b
constexpr unsigned int ByteStringReserveExceptionHandler = 0x10065c7b;
// R6GameService.dll code @ 10065c90
constexpr unsigned int CleanupIndentConstructorTag = 0x10065c90;
// R6GameService.dll code @ 10065c98
constexpr unsigned int CleanupIndentCapacityContext = 0x10065c98;
// R6GameService.dll code @ 10065ca0
constexpr unsigned int ReleaseIndentSpaces = 0x10065ca0;
// R6GameService.dll code @ 10065ca8
constexpr unsigned int ReleaseIndentSpacesLate = 0x10065ca8;
// R6GameService.dll code @ 10065cb0
constexpr unsigned int StringIndentExceptionHandler = 0x10065cb0;
// R6GameService.dll code @ 10065cc0
constexpr unsigned int CleanupLongIndentConstructorTag = 0x10065cc0;
// R6GameService.dll code @ 10065cc8
constexpr unsigned int CleanupLongIndentCapacityContext = 0x10065cc8;
// R6GameService.dll code @ 10065cd0
constexpr unsigned int ReleaseLongIndentSpaces = 0x10065cd0;
// R6GameService.dll code @ 10065cd8
constexpr unsigned int ReleaseLongIndentSpacesLate = 0x10065cd8;
// R6GameService.dll code @ 10065ce0
constexpr unsigned int LongIndentExceptionHandler = 0x10065ce0;
// R6GameService.dll code @ 10065cf0
constexpr unsigned int ReleaseNestedListAllocation = 0x10065cf0;
// R6GameService.dll code @ 10065cfa
constexpr unsigned int CleanupNestedListContext = 0x10065cfa;
// R6GameService.dll code @ 10065d14
constexpr unsigned int ResetNestedListBase = 0x10065d14;
// R6GameService.dll code @ 10065d1c
constexpr unsigned int CleanupNestedListConstructorTag = 0x10065d1c;
// R6GameService.dll code @ 10065d24
constexpr unsigned int ClDataSerializeListParseExceptionHandler = 0x10065d24;
// R6GameService.dll code @ 10065d30
constexpr unsigned int ReleaseTaggedStringAllocation = 0x10065d30;
// R6GameService.dll code @ 10065d3a
constexpr unsigned int CleanupTaggedStringContext = 0x10065d3a;
// R6GameService.dll code @ 10065d54
constexpr unsigned int ResetTaggedStringBase = 0x10065d54;
// R6GameService.dll code @ 10065d5c
constexpr unsigned int CleanupTaggedStringConstructorTag = 0x10065d5c;
// R6GameService.dll code @ 10065d64
constexpr unsigned int TaggedStringParseExceptionHandler = 0x10065d64;
// R6GameService.dll code @ 10065d70
constexpr unsigned int ReleaseTaggedByteBlockAllocation = 0x10065d70;
// R6GameService.dll code @ 10065d7a
constexpr unsigned int CleanupTaggedByteBlockContext = 0x10065d7a;
// R6GameService.dll code @ 10065d94
constexpr unsigned int ResetTaggedByteBlockBase = 0x10065d94;
// R6GameService.dll code @ 10065d9c
constexpr unsigned int CleanupTaggedByteBlockConstructorTag = 0x10065d9c;
// R6GameService.dll code @ 10065da4
constexpr unsigned int TaggedByteBlockParseExceptionHandler = 0x10065da4;
// R6GameService.dll code @ 10065db0
constexpr unsigned int CleanupSimpleMessageAllocationContext = 0x10065db0;
// R6GameService.dll code @ 10065dca
constexpr unsigned int ResetSimpleMessageAllocatorBase = 0x10065dca;
// R6GameService.dll code @ 10065dd2
constexpr unsigned int SimpleMessageConstructionExceptionHandler = 0x10065dd2;
// R6GameService.dll code @ 10065de0
constexpr unsigned int ConstructQueuedConnectionUnwind1 = 0x10065de0;
// R6GameService.dll code @ 10065dfa
constexpr unsigned int ConstructQueuedConnectionUnwind2 = 0x10065dfa;
// R6GameService.dll code @ 10065e05
constexpr unsigned int ConstructQueuedConnectionUnwind3 = 0x10065e05;
// R6GameService.dll code @ 10065e10
constexpr unsigned int ConstructQueuedConnectionSelectExceptionInfo = 0x10065e10;
// R6GameService.dll code @ 10065e20
constexpr unsigned int DestroyQueuedConnectionMembersUnwind1 = 0x10065e20;
// R6GameService.dll code @ 10065e2b
constexpr unsigned int DestroyQueuedConnectionMembersUnwind2 = 0x10065e2b;
// R6GameService.dll code @ 10065e36
constexpr unsigned int DestroyQueuedConnectionMembersUnwind3 = 0x10065e36;
// R6GameService.dll code @ 10065e41
constexpr unsigned int DestroyQueuedConnectionMembersSelectExceptionInfo = 0x10065e41;
// R6GameService.dll code @ 10065e50
constexpr unsigned int ConstructDatagramSocketOwnerUnwind1 = 0x10065e50;
// R6GameService.dll code @ 10065e6a
constexpr unsigned int ConstructDatagramSocketOwnerSelectExceptionInfo = 0x10065e6a;
// R6GameService.dll code @ 10065e80
constexpr unsigned int DestroyDatagramSocketOwnerUnwind1 = 0x10065e80;
// R6GameService.dll code @ 10065e8b
constexpr unsigned int DestroyDatagramSocketOwnerSelectExceptionInfo = 0x10065e8b;
// R6GameService.dll code @ 10065ea0
constexpr unsigned int DestroyCircularListUnwind1 = 0x10065ea0;
// R6GameService.dll code @ 10065ec7
constexpr unsigned int DestroyCircularListSelectExceptionInfo = 0x10065ec7;
// R6GameService.dll code @ 10065ee0
constexpr unsigned int UnwindRegistrationBaseFlag1 = 0x10065ee0;
// R6GameService.dll code @ 10065efd
constexpr unsigned int UnwindRegistrationBaseFlag2 = 0x10065efd;
// R6GameService.dll code @ 10065f1a
constexpr unsigned int SelectRegistrationConstructionLifetime = 0x10065f1a;
// R6GameService.dll code @ 10065f30
constexpr unsigned int ReleaseRegistrationPendingAllocation = 0x10065f30;
// R6GameService.dll code @ 10065f3a
constexpr unsigned int SharedRegistrationAllocationExceptionHandler = 0x10065f3a;
// R6GameService.dll code @ 10065f50
constexpr unsigned int CleanupLoginConstructionFlag = 0x10065f50;
// R6GameService.dll code @ 10065f67
constexpr unsigned int ResetLoginDescriptorBase = 0x10065f67;
// R6GameService.dll code @ 10065f6f
constexpr unsigned int CleanupLoginConstructorArgument = 0x10065f6f;
// R6GameService.dll code @ 10065f77
constexpr unsigned int DestroyLoginDescriptor = 0x10065f77;
// R6GameService.dll code @ 10065f7f
constexpr unsigned int ResetLoginMissingTransportDescriptor = 0x10065f7f;
// R6GameService.dll code @ 10065f87
constexpr unsigned int ReleaseLoginMissingTransportStorage = 0x10065f87;
// R6GameService.dll code @ 10065fae
constexpr unsigned int ResetLoginSubmittedDescriptor = 0x10065fae;
// R6GameService.dll code @ 10065fb6
constexpr unsigned int ReleaseLoginSubmittedStorage = 0x10065fb6;
// R6GameService.dll code @ 10065fdd
constexpr unsigned int LoginRequestExceptionHandler = 0x10065fdd;
// R6GameService.dll code @ 10065ff0
constexpr unsigned int CleanupD9ConstructionFlag = 0x10065ff0;
// R6GameService.dll code @ 10066007
constexpr unsigned int ResetD9DescriptorBase = 0x10066007;
// R6GameService.dll code @ 1006600f
constexpr unsigned int CleanupD9ConstructorArgument = 0x1006600f;
// R6GameService.dll code @ 10066017
constexpr unsigned int DestroyD9Descriptor = 0x10066017;
// R6GameService.dll code @ 1006601f
constexpr unsigned int ResetD9CleanupDescriptor = 0x1006601f;
// R6GameService.dll code @ 10066027
constexpr unsigned int ReleaseD9DescriptorStorage = 0x10066027;
// R6GameService.dll code @ 1006604e
constexpr unsigned int CleanupD9ReleasedStorage = 0x1006604e;
// R6GameService.dll code @ 10066056
constexpr unsigned int D9RequestExceptionHandler = 0x10066056;
// R6GameService.dll code @ 10066060
constexpr unsigned int CleanupD5PayloadConstructionFlag = 0x10066060;
// R6GameService.dll code @ 1006607d
constexpr unsigned int ResetD5PayloadBase = 0x1006607d;
// R6GameService.dll code @ 10066088
constexpr unsigned int DestroyD5Payload = 0x10066088;
// R6GameService.dll code @ 10066093
constexpr unsigned int CleanupD5EnvelopeConstructionFlag = 0x10066093;
// R6GameService.dll code @ 100660b0
constexpr unsigned int ResetD5EnvelopeBase = 0x100660b0;
// R6GameService.dll code @ 100660bb
constexpr unsigned int DestroyD5Envelope = 0x100660bb;
// R6GameService.dll code @ 100660c6
constexpr unsigned int CleanupD5Binary0ConstructionFlag = 0x100660c6;
// R6GameService.dll code @ 100660e3
constexpr unsigned int ResetD5Binary0Base = 0x100660e3;
// R6GameService.dll code @ 100660ee
constexpr unsigned int DestroyD5Binary0 = 0x100660ee;
// R6GameService.dll code @ 100660f9
constexpr unsigned int CleanupD5Binary1ConstructionFlag = 0x100660f9;
// R6GameService.dll code @ 10066113
constexpr unsigned int ResetD5Binary1Base = 0x10066113;
// R6GameService.dll code @ 1006611b
constexpr unsigned int DestroyD5Binary1 = 0x1006611b;
// R6GameService.dll code @ 10066123
constexpr unsigned int CleanupD5Binary2ConstructionFlag = 0x10066123;
// R6GameService.dll code @ 1006613d
constexpr unsigned int ResetD5Binary2Base = 0x1006613d;
// R6GameService.dll code @ 10066148
constexpr unsigned int DestroyD5Binary2 = 0x10066148;
// R6GameService.dll code @ 10066153
constexpr unsigned int CleanupD5FallbackRecord = 0x10066153;
// R6GameService.dll code @ 1006615b
constexpr unsigned int ResetD5ReleasedBinary2Base = 0x1006615b;
// R6GameService.dll code @ 10066166
constexpr unsigned int ResetD5ReleasedBinary0Base = 0x10066166;
// R6GameService.dll code @ 10066171
constexpr unsigned int RegistrationD5ExceptionHandler = 0x10066171;
// R6GameService.dll code @ 10066180
constexpr unsigned int FreePendingRegistrationReplyRecord = 0x10066180;
// R6GameService.dll code @ 1006618a
constexpr unsigned int RegistrationRecordReplyExceptionHandler = 0x1006618a;
// R6GameService.dll code @ 100661a0
constexpr unsigned int ResetLobbyLoginDescriptorBase = 0x100661a0;
// R6GameService.dll code @ 100661a8
constexpr unsigned int CleanupLobbyLoginConstructorArgument = 0x100661a8;
// R6GameService.dll code @ 100661b0
constexpr unsigned int DestroyLobbyLoginDescriptor = 0x100661b0;
// R6GameService.dll code @ 100661b8
constexpr unsigned int ResetLobbyLoginCleanupBase = 0x100661b8;
// R6GameService.dll code @ 100661c0
constexpr unsigned int ReleaseLobbyLoginStorage = 0x100661c0;
// R6GameService.dll code @ 100661e7
constexpr unsigned int LobbyLoginExceptionHandler = 0x100661e7;
// R6GameService.dll code @ 10066200
constexpr unsigned int ResetOptionalEnvelopeBase = 0x10066200;
// R6GameService.dll code @ 10066208
constexpr unsigned int DestroyOptionalEnvelope = 0x10066208;
// R6GameService.dll code @ 10066210
constexpr unsigned int FreeOptionalPendingPayload = 0x10066210;
// R6GameService.dll code @ 1006621a
constexpr unsigned int ResetOptionalPendingPayloadBase = 0x1006621a;
// R6GameService.dll code @ 10066222
constexpr unsigned int ResetOptionalBinary0Base = 0x10066222;
// R6GameService.dll code @ 1006622a
constexpr unsigned int DestroyOptionalBinary0 = 0x1006622a;
// R6GameService.dll code @ 10066232
constexpr unsigned int ResetOptionalReleasedBinary0Base = 0x10066232;
// R6GameService.dll code @ 1006623a
constexpr unsigned int ResetOptionalBinary1Base = 0x1006623a;
// R6GameService.dll code @ 10066242
constexpr unsigned int DestroyOptionalBinary1 = 0x10066242;
// R6GameService.dll code @ 1006624a
constexpr unsigned int ResetOptionalReleasedBinary1Base = 0x1006624a;
// R6GameService.dll code @ 10066252
constexpr unsigned int ResetOptionalBinary2Base = 0x10066252;
// R6GameService.dll code @ 1006625a
constexpr unsigned int DestroyOptionalBinary2 = 0x1006625a;
// R6GameService.dll code @ 10066262
constexpr unsigned int ResetOptionalReleasedBinary2Base = 0x10066262;
// R6GameService.dll code @ 1006626a
constexpr unsigned int OptionalRegistrationExceptionHandler = 0x1006626a;
// R6GameService.dll code @ 10066280
constexpr unsigned int ResetMatchEnvelopeBase = 0x10066280;
// R6GameService.dll code @ 10066288
constexpr unsigned int DestroyMatchEnvelope = 0x10066288;
// R6GameService.dll code @ 10066290
constexpr unsigned int FreeMatchPendingPayload = 0x10066290;
// R6GameService.dll code @ 1006629a
constexpr unsigned int ResetMatchPendingPayloadBase = 0x1006629a;
// R6GameService.dll code @ 100662a2
constexpr unsigned int ResetMatchCleanupEnvelopeBase = 0x100662a2;
// R6GameService.dll code @ 100662aa
constexpr unsigned int ReleaseMatchEnvelopeStorage = 0x100662aa;
// R6GameService.dll code @ 100662d1
constexpr unsigned int RegistrationMatchExceptionHandler = 0x100662d1;
// R6GameService.dll code @ 100662e0
constexpr unsigned int UnwindParsedListStorage = 0x100662e0;
// R6GameService.dll code @ 10066307
constexpr unsigned int SelectParsedListDestructionLifetime = 0x10066307;
// R6GameService.dll code @ 10066320
constexpr unsigned int ConstructClonedPayloadWrapperUnwind1 = 0x10066320;
// R6GameService.dll code @ 1006633a
constexpr unsigned int ConstructClonedPayloadWrapperUnwind2 = 0x1006633a;
// R6GameService.dll code @ 10066344
constexpr unsigned int SelectWrappedPayloadEH = 0x10066344;
// R6GameService.dll code @ 10066350
constexpr unsigned int UnwindTransportAllocation = 0x10066350;
// R6GameService.dll code @ 1006635a
constexpr unsigned int SelectTransportAllocationEH = 0x1006635a;
// R6GameService.dll code @ 10066370
constexpr unsigned int DestroyServiceClientUnwind1 = 0x10066370;
// R6GameService.dll code @ 10066378
constexpr unsigned int DestroyServiceClientSelectExceptionInfo = 0x10066378;
// R6GameService.dll code @ 10066390
constexpr unsigned int clMSClient_clMSClientUnwind1 = 0x10066390;
// R6GameService.dll code @ 100663ad
constexpr unsigned int clMSClient_clMSClientSelectExceptionInfo = 0x100663ad;
// R6GameService.dll code @ 100663c0
constexpr unsigned int QueueProviderCallbackRecordUnwind1 = 0x100663c0;
// R6GameService.dll code @ 100663c8
constexpr unsigned int QueueProviderCallbackRecordUnwind2 = 0x100663c8;
// R6GameService.dll code @ 100663d2
constexpr unsigned int QueueProviderCallbackRecordUnwind3 = 0x100663d2;
// R6GameService.dll code @ 100663ec
constexpr unsigned int QueueProviderCallbackRecordUnwind5 = 0x100663ec;
// R6GameService.dll code @ 100663f4
constexpr unsigned int SelectMSCallbackQueueEH = 0x100663f4;
// R6GameService.dll code @ 10066400
constexpr unsigned int DestroyLogicErrorExceptionBaseOnUnwind = 0x10066400;
// R6GameService.dll code @ 10066409
constexpr unsigned int LogicErrorBaseLifetimeExceptionHandler = 0x10066409;
// R6GameService.dll code @ 10066420
constexpr unsigned int DestroyVectorLengthMessageOnUnwind = 0x10066420;
// R6GameService.dll code @ 10066429
constexpr unsigned int DestroyPartialLengthErrorBaseOnUnwind = 0x10066429;
// R6GameService.dll code @ 10066432
constexpr unsigned int VectorLengthThrowExceptionHandler = 0x10066432;
// R6GameService.dll code @ 10066440
constexpr unsigned int DestroyWideHexEncoderText = 0x10066440;
// R6GameService.dll code @ 10066449
constexpr unsigned int DestroyConstructedWideHexResult = 0x10066449;
// R6GameService.dll code @ 10066463
constexpr unsigned int WideHexEncoderExceptionHandler = 0x10066463;
// R6GameService.dll code @ 10066470
constexpr unsigned int ByteVectorCopyExceptionHandler = 0x10066470;
// R6GameService.dll code @ 10066480
constexpr unsigned int DestroyCollectedStringsOnUnwind = 0x10066480;
// R6GameService.dll code @ 10066488
constexpr unsigned int ReleaseCollectedBytesOnUnwind = 0x10066488;
// R6GameService.dll code @ 10066490
constexpr unsigned int ReleaseCollectedResultOnUnwind = 0x10066490;
// R6GameService.dll code @ 100664a9
constexpr unsigned int CollectedByteBuilderExceptionHandler = 0x100664a9;
// R6GameService.dll code @ 100664c0
constexpr unsigned int DestroySharedLocalByteVector = 0x100664c0;
// R6GameService.dll code @ 100664c8
constexpr unsigned int LocalByteVectorExceptionHandler = 0x100664c8;
// R6GameService.dll code @ 100664e0
constexpr unsigned int DestroyEncryptSeedBytes = 0x100664e0;
// R6GameService.dll code @ 100664e8
constexpr unsigned int DestroyEncryptPayloadBytes = 0x100664e8;
// R6GameService.dll code @ 100664f0
constexpr unsigned int EncryptWideHexExceptionHandler = 0x100664f0;
// R6GameService.dll code @ 10066500
constexpr unsigned int DestroyDecryptEncodedInput = 0x10066500;
// R6GameService.dll code @ 10066509
constexpr unsigned int DestroyDecryptPayloadBytes = 0x10066509;
// R6GameService.dll code @ 10066511
constexpr unsigned int DestroyDecryptSeedBytes = 0x10066511;
// R6GameService.dll code @ 10066519
constexpr unsigned int DestroyDecryptTemporaryText = 0x10066519;
// R6GameService.dll code @ 10066522
constexpr unsigned int DestroyConstructedDecryptWideResult = 0x10066522;
// R6GameService.dll code @ 1006653c
constexpr unsigned int DecryptWideHexExceptionHandler = 0x1006653c;
// R6GameService.dll code @ 10066550
constexpr unsigned int DestroyWideValidationEncodedInput = 0x10066550;
// R6GameService.dll code @ 10066559
constexpr unsigned int DestroyWideValidationPayload = 0x10066559;
// R6GameService.dll code @ 10066561
constexpr unsigned int ValidateWideHexExceptionHandler = 0x10066561;
// R6GameService.dll code @ 10066570
constexpr unsigned int UnwindReceiverFirstString = 0x10066570;
// R6GameService.dll code @ 10066579
constexpr unsigned int UnwindReceiverProcessSlot = 0x10066579;
// R6GameService.dll code @ 10066584
constexpr unsigned int UnwindReceiverRpcBinding = 0x10066584;
// R6GameService.dll code @ 1006658f
constexpr unsigned int UnwindReceiverSecondString = 0x1006658f;
// R6GameService.dll code @ 1006659b
constexpr unsigned int SelectReceiverLifetimeInfo = 0x1006659b;
// R6GameService.dll code @ 100665b0
constexpr unsigned int UnwindFirstProgressText = 0x100665b0;
// R6GameService.dll code @ 100665bc
constexpr unsigned int UnwindSecondProgressText = 0x100665bc;
// R6GameService.dll code @ 100665c8
constexpr unsigned int SelectProgressTextLifetimeInfo = 0x100665c8;
// R6GameService.dll code @ 100665e0
constexpr unsigned int UnwindReceiverAllocation = 0x100665e0;
// R6GameService.dll code @ 100665eb
constexpr unsigned int SelectReceiverAllocationInfo = 0x100665eb;
// R6GameService.dll code @ 10066600
constexpr unsigned int DestroyDirectoryProbeWidePath = 0x10066600;
// R6GameService.dll code @ 10066609
constexpr unsigned int DestroyDirectoryProbeAnsiPath = 0x10066609;
// R6GameService.dll code @ 10066612
constexpr unsigned int DestroyDirectoryProbeFileStream = 0x10066612;
// R6GameService.dll code @ 1006661e
constexpr unsigned int DirectoryProbeExceptionHandler = 0x1006661e;
// R6GameService.dll code @ 10066630
constexpr unsigned int ForwardStringRangeNoOpCleanup = 0x10066630;
// R6GameService.dll code @ 10066641
constexpr unsigned int StringRangeConstructionExceptionHandler = 0x10066641;
// R6GameService.dll code @ 10066650
constexpr unsigned int ForwardRepeatedStringNoOpCleanup = 0x10066650;
// R6GameService.dll code @ 10066661
constexpr unsigned int RepeatedStringConstructionExceptionHandler = 0x10066661;
// R6GameService.dll code @ 10066670
constexpr unsigned int DestroySavedStringInsertionValue = 0x10066670;
// R6GameService.dll code @ 10066679
constexpr unsigned int StringVectorInsertionExceptionHandler = 0x10066679;
// R6GameService.dll code @ 10066690
constexpr unsigned int ReleaseAdapterQueryBufferOnUnwind = 0x10066690;
// R6GameService.dll code @ 1006669b
constexpr unsigned int DestroyAdapterAddressStringOnUnwind = 0x1006669b;
// R6GameService.dll code @ 100666a7
constexpr unsigned int AdapterAddressCollectorExceptionHandler = 0x100666a7;
// R6GameService.dll code @ 100666c0
constexpr unsigned int UnwindProcessApplication = 0x100666c0;
// R6GameService.dll code @ 100666cc
constexpr unsigned int UnwindProcessCommand = 0x100666cc;
// R6GameService.dll code @ 100666d8
constexpr unsigned int UnwindProcessDirectory = 0x100666d8;
// R6GameService.dll code @ 100666e4
constexpr unsigned int UnwindProcessExplicitDirectoryTemp = 0x100666e4;
// R6GameService.dll code @ 100666f0
constexpr unsigned int UnwindProcessCurrentDirectoryWideTemp = 0x100666f0;
// R6GameService.dll code @ 100666fc
constexpr unsigned int UnwindProcessCurrentDirectoryAnsiTemp = 0x100666fc;
// R6GameService.dll code @ 10066708
constexpr unsigned int SelectProcessLaunchLifetimeInfo = 0x10066708;
// R6GameService.dll code @ 10066720
constexpr unsigned int UnwindAnsiWideScratch = 0x10066720;
// R6GameService.dll code @ 1006672b
constexpr unsigned int SelectAnsiWideScratchInfo = 0x1006672b;
// R6GameService.dll code @ 10066740
constexpr unsigned int UnwindWideAnsiScratch = 0x10066740;
// R6GameService.dll code @ 1006674b
constexpr unsigned int SelectWideAnsiScratchInfo = 0x1006674b;
// R6GameService.dll code @ 10066760
constexpr unsigned int CleanupCipherModuleBlowfishBaseContext = 0x10066760;
// R6GameService.dll code @ 1006677a
constexpr unsigned int ResetCipherModuleBlowfishBaseOnUnwind = 0x1006677a;
// R6GameService.dll code @ 10066782
constexpr unsigned int ReleaseCipherModuleBlowfishStateAllocation = 0x10066782;
// R6GameService.dll code @ 1006678c
constexpr unsigned int CipherModuleBlowfishConstructExceptionHandler = 0x1006678c;
// R6GameService.dll code @ 100667a0
constexpr unsigned int ResetCipherModuleBaseOnUnwind = 0x100667a0;
// R6GameService.dll code @ 100667a8
constexpr unsigned int CipherModuleDestroyExceptionHandler = 0x100667a8;
// R6GameService.dll code @ 100667c0
constexpr unsigned int ReleaseHashFactorySelector1Allocation = 0x100667c0;
// R6GameService.dll code @ 100667ca
constexpr unsigned int ReleaseHashFactorySelector0Allocation = 0x100667ca;
// R6GameService.dll code @ 100667d4
constexpr unsigned int ReleaseHashFactoryRegistryAllocation = 0x100667d4;
// R6GameService.dll code @ 100667de
constexpr unsigned int CleanupHashFactoryRegistryContext = 0x100667de;
// R6GameService.dll code @ 100667f8
constexpr unsigned int CleanupHashFactorySelectorContext = 0x100667f8;
// R6GameService.dll code @ 10066800
constexpr unsigned int HashAlgorithmFactoryExceptionHandler = 0x10066800;
// R6GameService.dll code @ 10066810
constexpr unsigned int ReleasePRNGFactoryObjectAllocation = 0x10066810;
// R6GameService.dll code @ 1006681a
constexpr unsigned int ReleasePRNGFactoryRegistryAllocation = 0x1006681a;
// R6GameService.dll code @ 10066824
constexpr unsigned int CleanupPRNGFactorySelectorContext = 0x10066824;
// R6GameService.dll code @ 1006682c
constexpr unsigned int PRNGAlgorithmFactoryExceptionHandler = 0x1006682c;
// R6GameService.dll code @ 10066840
constexpr unsigned int ReleaseCryptoFactorySelector1Allocation = 0x10066840;
// R6GameService.dll code @ 1006684a
constexpr unsigned int ReleaseCryptoFactorySelector0Allocation = 0x1006684a;
// R6GameService.dll code @ 10066854
constexpr unsigned int ReleaseCryptoFactoryRegistryAllocation = 0x10066854;
// R6GameService.dll code @ 1006685e
constexpr unsigned int CleanupCryptoFactoryArgumentContext = 0x1006685e;
// R6GameService.dll code @ 10066866
constexpr unsigned int CryptoAlgorithmFactoryExceptionHandler = 0x10066866;
// R6GameService.dll code @ 10066870
constexpr unsigned int ReleasePKCFactoryObjectAllocation = 0x10066870;
// R6GameService.dll code @ 1006687a
constexpr unsigned int ReleasePKCFactoryRegistryAllocation = 0x1006687a;
// R6GameService.dll code @ 10066884
constexpr unsigned int CleanupPKCFactorySelectorContext = 0x10066884;
// R6GameService.dll code @ 1006688c
constexpr unsigned int PKCAlgorithmFactoryExceptionHandler = 0x1006688c;
// R6GameService.dll code @ 100668a0
constexpr unsigned int DestroyHashAlgorithmMapTreeOnUnwind = 0x100668a0;
// R6GameService.dll code @ 100668c7
constexpr unsigned int ReleaseHashAlgorithmMapHeaderOnUnwind = 0x100668c7;
// R6GameService.dll code @ 100668cf
constexpr unsigned int HashAlgorithmMapDestroyExceptionHandler = 0x100668cf;
// R6GameService.dll code @ 100668e0
constexpr unsigned int DestroyPRNGAlgorithmMapTreeOnUnwind = 0x100668e0;
// R6GameService.dll code @ 10066907
constexpr unsigned int ReleasePRNGAlgorithmMapHeaderOnUnwind = 0x10066907;
// R6GameService.dll code @ 1006690f
constexpr unsigned int PRNGAlgorithmMapDestroyExceptionHandler = 0x1006690f;
// R6GameService.dll code @ 10066920
constexpr unsigned int DestroyCryptoAlgorithmMapTreeOnUnwind = 0x10066920;
// R6GameService.dll code @ 10066947
constexpr unsigned int ReleaseCryptoAlgorithmMapHeaderOnUnwind = 0x10066947;
// R6GameService.dll code @ 1006694f
constexpr unsigned int CryptoAlgorithmMapDestroyExceptionHandler = 0x1006694f;
// R6GameService.dll code @ 10066960
constexpr unsigned int DestroyPKCAlgorithmMapTreeOnUnwind = 0x10066960;
// R6GameService.dll code @ 10066987
constexpr unsigned int ReleasePKCAlgorithmMapHeaderOnUnwind = 0x10066987;
// R6GameService.dll code @ 1006698f
constexpr unsigned int PKCAlgorithmMapDestroyExceptionHandler = 0x1006698f;
// R6GameService.dll code @ 100669a0
constexpr unsigned int ReleaseRegistryTreeHeader = 0x100669a0;
// R6GameService.dll code @ 100669a8
constexpr unsigned int RegistryTreeDestroyExceptionHandler = 0x100669a8;
// R6GameService.dll code @ 100669c0
constexpr unsigned int ResetCBlowFishBaseOnUnwind = 0x100669c0;
// R6GameService.dll code @ 100669c8
constexpr unsigned int CBlowFishDestroyExceptionHandler = 0x100669c8;
// R6GameService.dll code @ 100669e0
constexpr unsigned int CleanupHashModuleSHA1BaseContext = 0x100669e0;
// R6GameService.dll code @ 100669fa
constexpr unsigned int ResetHashModuleSHA1BaseOnUnwind = 0x100669fa;
// R6GameService.dll code @ 10066a02
constexpr unsigned int ReleaseHashModuleSHA1ContextAllocation = 0x10066a02;
// R6GameService.dll code @ 10066a0c
constexpr unsigned int HashModuleSHA1ConstructExceptionHandler = 0x10066a0c;
// R6GameService.dll code @ 10066a20
constexpr unsigned int ResetHashModuleMD5BaseOnUnwind = 0x10066a20;
// R6GameService.dll code @ 10066a28
constexpr unsigned int ReleaseHashModuleMD5ContextAllocation = 0x10066a28;
// R6GameService.dll code @ 10066a32
constexpr unsigned int HashModuleMD5ConstructExceptionHandler = 0x10066a32;
// R6GameService.dll code @ 10066a40
constexpr unsigned int ResetHashModuleBaseOnUnwind = 0x10066a40;
// R6GameService.dll code @ 10066a48
constexpr unsigned int HashModuleDestroyExceptionHandler = 0x10066a48;
// R6GameService.dll code @ 10066a60
constexpr unsigned int CleanupMGF1BaseContext = 0x10066a60;
// R6GameService.dll code @ 10066a7a
constexpr unsigned int ResetMGF1ConstructBaseOnUnwind = 0x10066a7a;
// R6GameService.dll code @ 10066a82
constexpr unsigned int ReleaseMGF1SHA1ChildAllocation = 0x10066a82;
// R6GameService.dll code @ 10066a8c
constexpr unsigned int ReleaseMGF1MD5ChildAllocation = 0x10066a8c;
// R6GameService.dll code @ 10066a96
constexpr unsigned int MGF1ConstructExceptionHandler = 0x10066a96;
// R6GameService.dll code @ 10066aa0
constexpr unsigned int ResetMGF1DestroyBaseOnUnwind = 0x10066aa0;
// R6GameService.dll code @ 10066aa8
constexpr unsigned int MGF1DestroyExceptionHandler = 0x10066aa8;
// R6GameService.dll code @ 10066ac0
constexpr unsigned int CleanupPKCRSABaseContext = 0x10066ac0;
// R6GameService.dll code @ 10066ada
constexpr unsigned int ResetPKCRSAConstructBaseOnUnwind = 0x10066ada;
// R6GameService.dll code @ 10066ae2
constexpr unsigned int ReleasePKCRSAChildAllocation = 0x10066ae2;
// R6GameService.dll code @ 10066aec
constexpr unsigned int PKCRSAConstructExceptionHandler = 0x10066aec;
// R6GameService.dll code @ 10066b00
constexpr unsigned int ResetPKCRSADestroyBaseOnUnwind = 0x10066b00;
// R6GameService.dll code @ 10066b08
constexpr unsigned int PKCRSADestroyExceptionHandler = 0x10066b08;
// R6GameService.dll code @ 10066b20
constexpr unsigned int CleanupSecureHashAlgorithm1VirtualBase = 0x10066b20;
// R6GameService.dll code @ 10066b3a
constexpr unsigned int CleanupSecureHashAlgorithm1AllocationBase = 0x10066b3a;
// R6GameService.dll code @ 10066b42
constexpr unsigned int SecureHashAlgorithm1ConstructExceptionHandler = 0x10066b42;
// R6GameService.dll code @ 10066b50
constexpr unsigned int CleanupMD5VirtualBase = 0x10066b50;
// R6GameService.dll code @ 10066b6a
constexpr unsigned int CleanupMD5AllocationBase = 0x10066b6a;
// R6GameService.dll code @ 10066b72
constexpr unsigned int MD5ConstructExceptionHandler = 0x10066b72;
// R6GameService.dll code @ 10066b80
constexpr unsigned int CleanupRandomStackMD5Context = 0x10066b80;
// R6GameService.dll code @ 10066b88
constexpr unsigned int RandomStackMD5ExceptionHandler = 0x10066b88;
// R6GameService.dll code @ 10066ba0
constexpr unsigned int ReleaseGLClientServiceAllocation = 0x10066ba0;
// R6GameService.dll code @ 10066baa
constexpr unsigned int GLClientConstructExceptionHandler = 0x10066baa;
// R6GameService.dll code @ 10066bc0
constexpr unsigned int CleanupServiceVirtualBase = 0x10066bc0;
// R6GameService.dll code @ 10066bdd
constexpr unsigned int DestroyFirstServiceQueueOnConstructUnwind = 0x10066bdd;
// R6GameService.dll code @ 10066beb
constexpr unsigned int DestroySecondServiceQueueOnConstructUnwind = 0x10066beb;
// R6GameService.dll code @ 10066bf9
constexpr unsigned int DestroyThirdServiceQueueOnConstructUnwind = 0x10066bf9;
// R6GameService.dll code @ 10066c07
constexpr unsigned int ReleaseServiceAllocationAtState4 = 0x10066c07;
// R6GameService.dll code @ 10066c11
constexpr unsigned int ReleaseServiceAllocationAtState5 = 0x10066c11;
// R6GameService.dll code @ 10066c1b
constexpr unsigned int CleanupServiceWrapperBaseAtState6 = 0x10066c1b;
// R6GameService.dll code @ 10066c35
constexpr unsigned int ReleaseServiceInnerAllocationAtState7 = 0x10066c35;
// R6GameService.dll code @ 10066c3f
constexpr unsigned int ReleaseServiceAllocationAtState8 = 0x10066c3f;
// R6GameService.dll code @ 10066c49
constexpr unsigned int CleanupServiceWrapperBaseAtState9 = 0x10066c49;
// R6GameService.dll code @ 10066c63
constexpr unsigned int ReleaseServiceInnerAllocationAtState10 = 0x10066c63;
// R6GameService.dll code @ 10066c6d
constexpr unsigned int ReleaseServiceAllocationAtState11 = 0x10066c6d;
// R6GameService.dll code @ 10066c77
constexpr unsigned int ReleaseServiceAllocationAtState12 = 0x10066c77;
// R6GameService.dll code @ 10066c81
constexpr unsigned int ServiceStateConstructExceptionHandler = 0x10066c81;
// R6GameService.dll code @ 10066c90
constexpr unsigned int DestroyFirstServiceQueueOnDestroyUnwind = 0x10066c90;
// R6GameService.dll code @ 10066c9e
constexpr unsigned int DestroySecondServiceQueueOnDestroyUnwind = 0x10066c9e;
// R6GameService.dll code @ 10066cac
constexpr unsigned int DestroyThirdServiceQueueOnDestroyUnwind = 0x10066cac;
// R6GameService.dll code @ 10066cba
constexpr unsigned int ServiceStateDestroyExceptionHandler = 0x10066cba;
// R6GameService.dll code @ 10066cd0
constexpr unsigned int QueueMarkedClDataRecordUnwind1 = 0x10066cd0;
// R6GameService.dll code @ 10066cd8
constexpr unsigned int QueueMarkedClDataRecordUnwind2 = 0x10066cd8;
// R6GameService.dll code @ 10066ce0
constexpr unsigned int QueueMarkedClDataRecordUnwind3 = 0x10066ce0;
// R6GameService.dll code @ 10066ce8
constexpr unsigned int QueueMarkedClDataRecordUnwind4 = 0x10066ce8;
// R6GameService.dll code @ 10066cf0
constexpr unsigned int QueueMarkedClDataRecordUnwind5 = 0x10066cf0;
// R6GameService.dll code @ 10066cf8
constexpr unsigned int QueueMarkedClDataRecordUnwind6 = 0x10066cf8;
// R6GameService.dll code @ 10066d00
constexpr unsigned int QueueMarkedClDataRecordUnwind7 = 0x10066d00;
// R6GameService.dll code @ 10066d08
constexpr unsigned int QueueMarkedClDataRecordUnwind8 = 0x10066d08;
// R6GameService.dll code @ 10066d12
constexpr unsigned int QueueMarkedClDataRecordUnwind9 = 0x10066d12;
// R6GameService.dll code @ 10066d1a
constexpr unsigned int QueueMarkedClDataRecordUnwind10 = 0x10066d1a;
// R6GameService.dll code @ 10066d22
constexpr unsigned int SelectMarkedRecordBuilderEH = 0x10066d22;
// R6GameService.dll code @ 10066d30
constexpr unsigned int service_state_supportSharedLifetimeUnwind1 = 0x10066d30;
// R6GameService.dll code @ 10066d38
constexpr unsigned int service_state_supportSharedLifetimeUnwind2 = 0x10066d38;
// R6GameService.dll code @ 10066d40
constexpr unsigned int service_state_supportSharedLifetimeUnwind3 = 0x10066d40;
// R6GameService.dll code @ 10066d48
constexpr unsigned int service_state_supportSharedLifetimeUnwind4 = 0x10066d48;
// R6GameService.dll code @ 10066d50
constexpr unsigned int service_state_supportSharedLifetimeUnwind5 = 0x10066d50;
// R6GameService.dll code @ 10066d58
constexpr unsigned int service_state_supportSharedLifetimeUnwind6 = 0x10066d58;
// R6GameService.dll code @ 10066d60
constexpr unsigned int service_state_supportSharedLifetimeUnwind7 = 0x10066d60;
// R6GameService.dll code @ 10066d68
constexpr unsigned int service_state_supportSharedLifetimeUnwind8 = 0x10066d68;
// R6GameService.dll code @ 10066d72
constexpr unsigned int service_state_supportSharedLifetimeUnwind9 = 0x10066d72;
// R6GameService.dll code @ 10066d7a
constexpr unsigned int service_state_supportSharedLifetimeUnwind10 = 0x10066d7a;
// R6GameService.dll code @ 10066d82
constexpr unsigned int SelectWordRecordBuildersEH = 0x10066d82;
// R6GameService.dll code @ 10066d90
constexpr unsigned int ExtractRecordDispatchCodeUnwind1 = 0x10066d90;
// R6GameService.dll code @ 10066d98
constexpr unsigned int ExtractRecordDispatchCodeUnwind2 = 0x10066d98;
// R6GameService.dll code @ 10066da0
constexpr unsigned int ExtractRecordDispatchCodeUnwind3 = 0x10066da0;
// R6GameService.dll code @ 10066da8
constexpr unsigned int ExtractRecordDispatchCodeUnwind4 = 0x10066da8;
// R6GameService.dll code @ 10066db0
constexpr unsigned int ExtractRecordDispatchCodeUnwind5 = 0x10066db0;
// R6GameService.dll code @ 10066dd7
constexpr unsigned int ExtractRecordDispatchCodeUnwind6 = 0x10066dd7;
// R6GameService.dll code @ 10066ddf
constexpr unsigned int SelectDispatchCodeExtractorEH = 0x10066ddf;
// R6GameService.dll code @ 10066df0
constexpr unsigned int OpenPrimaryConnectionUnwind1 = 0x10066df0;
// R6GameService.dll code @ 10066dfa
constexpr unsigned int SelectPrimaryConnectionEH = 0x10066dfa;
// R6GameService.dll code @ 10066e10
constexpr unsigned int UnwindKeyedResults = 0x10066e10;
// R6GameService.dll code @ 10066e18
constexpr unsigned int keyed_results_support_UnwindKeyedResults = 0x10066e18;
// R6GameService.dll code @ 10066e20
constexpr unsigned int SelectKeyedResultsEH = 0x10066e20;
// R6GameService.dll code @ 10066e30
constexpr unsigned int UnwindCollection = 0x10066e30;
// R6GameService.dll code @ 10066e38
constexpr unsigned int SelectCollectionEH = 0x10066e38;
// R6GameService.dll code @ 10066e50
constexpr unsigned int InitializeServiceRecordCollectionsUnwind1 = 0x10066e50;
// R6GameService.dll code @ 10066e6d
constexpr unsigned int InitializeServiceRecordCollectionsUnwind2 = 0x10066e6d;
// R6GameService.dll code @ 10066e87
constexpr unsigned int InitializeServiceRecordCollectionsUnwind4 = 0x10066e87;
// R6GameService.dll code @ 10066e92
constexpr unsigned int InitializeServiceRecordCollectionsUnwind5 = 0x10066e92;
// R6GameService.dll code @ 10066eac
constexpr unsigned int InitializeServiceRecordCollectionsUnwind7 = 0x10066eac;
// R6GameService.dll code @ 10066eb7
constexpr unsigned int InitializeServiceRecordCollectionsUnwind8 = 0x10066eb7;
// R6GameService.dll code @ 10066ed1
constexpr unsigned int InitializeServiceRecordCollectionsUnwind9 = 0x10066ed1;
// R6GameService.dll code @ 10066ed9
constexpr unsigned int InitializeServiceRecordCollectionsUnwind10 = 0x10066ed9;
// R6GameService.dll code @ 10066ee4
constexpr unsigned int InitializeServiceRecordCollectionsUnwind11 = 0x10066ee4;
// R6GameService.dll code @ 10066efe
constexpr unsigned int InitializeServiceRecordCollectionsUnwind12 = 0x10066efe;
// R6GameService.dll code @ 10066f06
constexpr unsigned int InitializeServiceRecordCollectionsUnwind13 = 0x10066f06;
// R6GameService.dll code @ 10066f14
constexpr unsigned int InitializeServiceRecordCollectionsUnwind14 = 0x10066f14;
// R6GameService.dll code @ 10066f30
constexpr unsigned int InitializeServiceRecordCollectionsUnwind15 = 0x10066f30;
// R6GameService.dll code @ 10066f38
constexpr unsigned int InitializeServiceRecordCollectionsUnwind16 = 0x10066f38;
// R6GameService.dll code @ 10066f46
constexpr unsigned int InitializeServiceRecordCollectionsUnwind17 = 0x10066f46;
// R6GameService.dll code @ 10066f50
constexpr unsigned int InitializeServiceRecordCollectionsUnwind18 = 0x10066f50;
// R6GameService.dll code @ 10066f5a
constexpr unsigned int SelectServiceRecordCollectionsEH = 0x10066f5a;
// R6GameService.dll code @ 10066f70
constexpr unsigned int DestroyServiceSubobjectUnwind1 = 0x10066f70;
// R6GameService.dll code @ 10066f7b
constexpr unsigned int DestroyServiceSubobjectUnwind2 = 0x10066f7b;
// R6GameService.dll code @ 10066f86
constexpr unsigned int DestroyServiceSubobjectUnwind3 = 0x10066f86;
// R6GameService.dll code @ 10066f91
constexpr unsigned int DestroyServiceSubobjectUnwind4 = 0x10066f91;
// R6GameService.dll code @ 10066f9f
constexpr unsigned int DestroyServiceSubobjectUnwind5 = 0x10066f9f;
// R6GameService.dll code @ 10066fad
constexpr unsigned int DestroyServiceSubobjectUnwind6 = 0x10066fad;
// R6GameService.dll code @ 10066fb5
constexpr unsigned int DestroyServiceSubobjectUnwind7 = 0x10066fb5;
// R6GameService.dll code @ 10066fbd
constexpr unsigned int DestroyServiceSubobjectUnwind8 = 0x10066fbd;
// R6GameService.dll code @ 10066fc5
constexpr unsigned int DestroyServiceSubobjectUnwind9 = 0x10066fc5;
// R6GameService.dll code @ 10066fec
constexpr unsigned int DestroyServiceSubobjectUnwind10 = 0x10066fec;
// R6GameService.dll code @ 10067013
constexpr unsigned int SelectCollectionDestroyEH = 0x10067013;
// R6GameService.dll code @ 10067020
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind1 = 0x10067020;
// R6GameService.dll code @ 10067028
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind2 = 0x10067028;
// R6GameService.dll code @ 10067030
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind3 = 0x10067030;
// R6GameService.dll code @ 10067038
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind4 = 0x10067038;
// R6GameService.dll code @ 10067040
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind5 = 0x10067040;
// R6GameService.dll code @ 10067048
constexpr unsigned int TryReadServiceRecordTagAndValueUnwind6 = 0x10067048;
// R6GameService.dll code @ 10067050
constexpr unsigned int SelectServiceRecordReaderEH = 0x10067050;
// R6GameService.dll code @ 10067060
constexpr unsigned int ApplySelectorOneServiceResponseUnwind1 = 0x10067060;
// R6GameService.dll code @ 1006706b
constexpr unsigned int ApplySelectorOneServiceResponseUnwind2 = 0x1006706b;
// R6GameService.dll code @ 10067076
constexpr unsigned int ApplySelectorOneServiceResponseUnwind3 = 0x10067076;
// R6GameService.dll code @ 10067081
constexpr unsigned int ApplySelectorOneServiceResponseUnwind4 = 0x10067081;
// R6GameService.dll code @ 1006708c
constexpr unsigned int ApplySelectorOneServiceResponseUnwind5 = 0x1006708c;
// R6GameService.dll code @ 10067097
constexpr unsigned int ApplySelectorOneServiceResponseUnwind6 = 0x10067097;
// R6GameService.dll code @ 100670a2
constexpr unsigned int ApplySelectorOneServiceResponseUnwind7 = 0x100670a2;
// R6GameService.dll code @ 100670ad
constexpr unsigned int ApplySelectorOneServiceResponseUnwind8 = 0x100670ad;
// R6GameService.dll code @ 100670b8
constexpr unsigned int SelectSelectorOneResponseEH = 0x100670b8;
// R6GameService.dll code @ 100670d0
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind1 = 0x100670d0;
// R6GameService.dll code @ 100670d8
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind2 = 0x100670d8;
// R6GameService.dll code @ 100670e0
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind3 = 0x100670e0;
// R6GameService.dll code @ 100670e8
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind4 = 0x100670e8;
// R6GameService.dll code @ 100670f0
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind5 = 0x100670f0;
// R6GameService.dll code @ 100670f8
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind6 = 0x100670f8;
// R6GameService.dll code @ 10067100
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind7 = 0x10067100;
// R6GameService.dll code @ 10067108
constexpr unsigned int ApplySelectorTwoServiceResponseUnwind8 = 0x10067108;
// R6GameService.dll code @ 10067110
constexpr unsigned int SelectSelectorTwoResponseEH = 0x10067110;
// R6GameService.dll code @ 10067120
constexpr unsigned int clPointerMap_DestroyServiceTreeContainerUnwind1 = 0x10067120;
// R6GameService.dll code @ 10067147
constexpr unsigned int clPointerMap_DestroyServiceTreeContainerUnwind2 = 0x10067147;
// R6GameService.dll code @ 1006714f
constexpr unsigned int SelectLadderPointerMapDestroyEH = 0x1006714f;
// R6GameService.dll code @ 10067160
constexpr unsigned int DestroyServiceTreeContainerVariantUnwind1 = 0x10067160;
// R6GameService.dll code @ 10067187
constexpr unsigned int DestroyServiceTreeContainerVariantUnwind2 = 0x10067187;
// R6GameService.dll code @ 1006718f
constexpr unsigned int SelectDataListPointerMapDestroyEH = 0x1006718f;
// R6GameService.dll code @ 100671a0
constexpr unsigned int ordered_tree_supportSharedLifetimeUnwind1 = 0x100671a0;
// R6GameService.dll code @ 100671a8
constexpr unsigned int SelectSharedTreeStorageDestroyEH = 0x100671a8;
// R6GameService.dll code @ 100671c0
constexpr unsigned int payload_reference_supportSharedLifetimeUnwind1 = 0x100671c0;
// R6GameService.dll code @ 100671c8
constexpr unsigned int SelectCircularReferenceDestroyEH = 0x100671c8;
// R6GameService.dll code @ 100671e0
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind1 = 0x100671e0;
// R6GameService.dll code @ 100671fa
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind2 = 0x100671fa;
// R6GameService.dll code @ 10067214
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind3 = 0x10067214;
// R6GameService.dll code @ 1006721c
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind4 = 0x1006721c;
// R6GameService.dll code @ 10067224
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind5 = 0x10067224;
// R6GameService.dll code @ 1006722f
constexpr unsigned int ConstructServiceProtocolDispatcherUnwind6 = 0x1006722f;
// R6GameService.dll code @ 10067239
constexpr unsigned int SelectDispatcherConstructionEH = 0x10067239;
// R6GameService.dll code @ 10067250
constexpr unsigned int ClearProtocolDispatcherTreeUnwind1 = 0x10067250;
// R6GameService.dll code @ 10067258
constexpr unsigned int SelectDispatcherTreeEH = 0x10067258;
// R6GameService.dll code @ 10067270
constexpr unsigned int DestroyServiceProtocolDispatcherUnwind1 = 0x10067270;
// R6GameService.dll code @ 1006727b
constexpr unsigned int DestroyServiceProtocolDispatcherUnwind2 = 0x1006727b;
// R6GameService.dll code @ 10067283
constexpr unsigned int SelectDispatcherDestructionEH = 0x10067283;
// R6GameService.dll code @ 10067290
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind1 = 0x10067290;
// R6GameService.dll code @ 10067298
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind2 = 0x10067298;
// R6GameService.dll code @ 100672a0
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind6 = 0x100672a0;
// R6GameService.dll code @ 100672a8
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind3 = 0x100672a8;
// R6GameService.dll code @ 100672b0
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind4 = 0x100672b0;
// R6GameService.dll code @ 100672b8
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwind5 = 0x100672b8;
// R6GameService.dll code @ 100672c0
constexpr unsigned int SelectDescriptorReaderEH = 0x100672c0;
// R6GameService.dll code @ 100672d0
constexpr unsigned int TryReadType35DescriptorFieldsUnwind1 = 0x100672d0;
// R6GameService.dll code @ 100672d8
constexpr unsigned int TryReadType35DescriptorFieldsUnwind2 = 0x100672d8;
// R6GameService.dll code @ 100672e0
constexpr unsigned int TryReadType35DescriptorFieldsUnwind3 = 0x100672e0;
// R6GameService.dll code @ 100672e8
constexpr unsigned int TryReadType35DescriptorFieldsUnwind4 = 0x100672e8;
// R6GameService.dll code @ 100672f0
constexpr unsigned int TryReadType35DescriptorFieldsUnwind5 = 0x100672f0;
// R6GameService.dll code @ 100672f8
constexpr unsigned int TryReadType35DescriptorFieldsUnwind6 = 0x100672f8;
// R6GameService.dll code @ 10067300
constexpr unsigned int TryReadType35DescriptorFieldsUnwind7 = 0x10067300;
// R6GameService.dll code @ 10067308
constexpr unsigned int TryReadType35DescriptorFieldsUnwind8 = 0x10067308;
// R6GameService.dll code @ 10067310
constexpr unsigned int SelectType35DescriptorEH = 0x10067310;
// R6GameService.dll code @ 10067320
constexpr unsigned int ReadType36DescriptorShortUnwind1 = 0x10067320;
// R6GameService.dll code @ 10067328
constexpr unsigned int ReadType36DescriptorShortUnwind2 = 0x10067328;
// R6GameService.dll code @ 10067330
constexpr unsigned int ReadType36DescriptorShortUnwind3 = 0x10067330;
// R6GameService.dll code @ 10067338
constexpr unsigned int ReadType36DescriptorShortUnwind4 = 0x10067338;
// R6GameService.dll code @ 1006735f
constexpr unsigned int ReadType36DescriptorShortUnwind5 = 0x1006735f;
// R6GameService.dll code @ 10067367
constexpr unsigned int ReadType36DescriptorShortUnwind6 = 0x10067367;
// R6GameService.dll code @ 1006738e
constexpr unsigned int ReadType36DescriptorShortUnwind7 = 0x1006738e;
// R6GameService.dll code @ 10067396
constexpr unsigned int ReadType36DescriptorShortUnwind8 = 0x10067396;
// R6GameService.dll code @ 100673bd
constexpr unsigned int SelectType36DescriptorEH = 0x100673bd;
// R6GameService.dll code @ 100673d0
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwind1 = 0x100673d0;
// R6GameService.dll code @ 100673d8
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwind2 = 0x100673d8;
// R6GameService.dll code @ 100673e0
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwind3 = 0x100673e0;
// R6GameService.dll code @ 100673e8
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwind4 = 0x100673e8;
// R6GameService.dll code @ 100673f0
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwind5 = 0x100673f0;
// R6GameService.dll code @ 100673f8
constexpr unsigned int SelectBinaryLengthEH = 0x100673f8;
// R6GameService.dll code @ 10067410
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind1 = 0x10067410;
// R6GameService.dll code @ 10067418
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind2 = 0x10067418;
// R6GameService.dll code @ 10067420
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind3 = 0x10067420;
// R6GameService.dll code @ 10067428
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind4 = 0x10067428;
// R6GameService.dll code @ 10067430
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind5 = 0x10067430;
// R6GameService.dll code @ 10067438
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind6 = 0x10067438;
// R6GameService.dll code @ 10067440
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind7 = 0x10067440;
// R6GameService.dll code @ 10067448
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind8 = 0x10067448;
// R6GameService.dll code @ 10067450
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind9 = 0x10067450;
// R6GameService.dll code @ 10067458
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwind10 = 0x10067458;
// R6GameService.dll code @ 10067460
constexpr unsigned int SelectSelector38QueryEH = 0x10067460;
// R6GameService.dll code @ 10067470
constexpr unsigned int InitializeTransportRecordIfAbsentUnwind1 = 0x10067470;
// R6GameService.dll code @ 1006747a
constexpr unsigned int SelectTransportRecordConstructionEH = 0x1006747a;
// R6GameService.dll code @ 10067490
constexpr unsigned int HandleSelector13RecordRemovalUnwind1 = 0x10067490;
// R6GameService.dll code @ 10067498
constexpr unsigned int HandleSelector13RecordRemovalUnwind2 = 0x10067498;
// R6GameService.dll code @ 100674a0
constexpr unsigned int HandleSelector13RecordRemovalUnwind3 = 0x100674a0;
// R6GameService.dll code @ 100674a8
constexpr unsigned int HandleSelector13RecordRemovalUnwind4 = 0x100674a8;
// R6GameService.dll code @ 100674b0
constexpr unsigned int HandleSelector13RecordRemovalUnwind5 = 0x100674b0;
// R6GameService.dll code @ 100674b8
constexpr unsigned int HandleSelector13RecordRemovalUnwind6 = 0x100674b8;
// R6GameService.dll code @ 100674c0
constexpr unsigned int HandleSelector13RecordRemovalUnwind7 = 0x100674c0;
// R6GameService.dll code @ 100674c8
constexpr unsigned int HandleSelector13RecordRemovalUnwind8 = 0x100674c8;
// R6GameService.dll code @ 100674d0
constexpr unsigned int SelectSelector13RemovalEH = 0x100674d0;
// R6GameService.dll code @ 100674e0
constexpr unsigned int SendTransportRequestPayloadUnwind1 = 0x100674e0;
// R6GameService.dll code @ 100674e8
constexpr unsigned int SendTransportRequestPayloadUnwind2 = 0x100674e8;
// R6GameService.dll code @ 100674f0
constexpr unsigned int SendTransportRequestPayloadUnwind3 = 0x100674f0;
// R6GameService.dll code @ 100674f8
constexpr unsigned int SendTransportRequestPayloadUnwind4 = 0x100674f8;
// R6GameService.dll code @ 10067500
constexpr unsigned int SendTransportRequestPayloadUnwind5 = 0x10067500;
// R6GameService.dll code @ 10067508
constexpr unsigned int SendTransportRequestPayloadUnwind6 = 0x10067508;
// R6GameService.dll code @ 10067510
constexpr unsigned int SendTransportRequestPayloadUnwind7 = 0x10067510;
// R6GameService.dll code @ 10067518
constexpr unsigned int SelectTransportRequestEH = 0x10067518;
// R6GameService.dll code @ 10067530
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind1 = 0x10067530;
// R6GameService.dll code @ 10067538
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind2 = 0x10067538;
// R6GameService.dll code @ 10067540
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind3 = 0x10067540;
// R6GameService.dll code @ 10067548
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind4 = 0x10067548;
// R6GameService.dll code @ 1006756f
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind5 = 0x1006756f;
// R6GameService.dll code @ 10067577
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwind6 = 0x10067577;
// R6GameService.dll code @ 1006759e
constexpr unsigned int SelectRequest18EH = 0x1006759e;
// R6GameService.dll code @ 100675b0
constexpr unsigned int request_state_supportSharedLifetimeUnwind18 = 0x100675b0;
// R6GameService.dll code @ 100675b8
constexpr unsigned int request_state_supportSharedLifetimeUnwind28 = 0x100675b8;
// R6GameService.dll code @ 100675c0
constexpr unsigned int request_state_supportSharedLifetimeUnwind38 = 0x100675c0;
// R6GameService.dll code @ 100675c8
constexpr unsigned int request_state_supportSharedLifetimeUnwind47 = 0x100675c8;
// R6GameService.dll code @ 100675d0
constexpr unsigned int request_state_supportSharedLifetimeUnwind56 = 0x100675d0;
// R6GameService.dll code @ 100675f7
constexpr unsigned int request_state_supportSharedLifetimeUnwind65 = 0x100675f7;
// R6GameService.dll code @ 100675ff
constexpr unsigned int SelectCommonRequestsEH = 0x100675ff;
// R6GameService.dll code @ 10067610
constexpr unsigned int request_state_supportSharedLifetimeUnwind17 = 0x10067610;
// R6GameService.dll code @ 10067618
constexpr unsigned int request_state_supportSharedLifetimeUnwind27 = 0x10067618;
// R6GameService.dll code @ 10067620
constexpr unsigned int request_state_supportSharedLifetimeUnwind37 = 0x10067620;
// R6GameService.dll code @ 10067628
constexpr unsigned int request_state_supportSharedLifetimeUnwind46 = 0x10067628;
// R6GameService.dll code @ 1006764f
constexpr unsigned int request_state_supportSharedLifetimeUnwind55 = 0x1006764f;
// R6GameService.dll code @ 10067657
constexpr unsigned int request_state_supportSharedLifetimeUnwind64 = 0x10067657;
// R6GameService.dll code @ 1006767e
constexpr unsigned int SelectRequests8_22EH = 0x1006767e;
// R6GameService.dll code @ 10067690
constexpr unsigned int SendBinaryRequest2aUnwind1 = 0x10067690;
// R6GameService.dll code @ 10067698
constexpr unsigned int SendBinaryRequest2aUnwind2 = 0x10067698;
// R6GameService.dll code @ 100676a0
constexpr unsigned int SendBinaryRequest2aUnwind3 = 0x100676a0;
// R6GameService.dll code @ 100676a8
constexpr unsigned int SendBinaryRequest2aUnwind4 = 0x100676a8;
// R6GameService.dll code @ 100676b0
constexpr unsigned int SendBinaryRequest2aUnwind5 = 0x100676b0;
// R6GameService.dll code @ 100676b8
constexpr unsigned int SendBinaryRequest2aUnwind6 = 0x100676b8;
// R6GameService.dll code @ 100676c0
constexpr unsigned int SendBinaryRequest2aUnwind7 = 0x100676c0;
// R6GameService.dll code @ 100676c8
constexpr unsigned int SendBinaryRequest2aUnwind8 = 0x100676c8;
// R6GameService.dll code @ 100676d0
constexpr unsigned int SelectRequest2aEH = 0x100676d0;
// R6GameService.dll code @ 100676e0
constexpr unsigned int ReadServiceState9Unwind1 = 0x100676e0;
// R6GameService.dll code @ 100676e8
constexpr unsigned int ReadServiceState9Unwind2 = 0x100676e8;
// R6GameService.dll code @ 100676f0
constexpr unsigned int ReadServiceState9Unwind3 = 0x100676f0;
// R6GameService.dll code @ 100676f8
constexpr unsigned int ReadServiceState9Unwind4 = 0x100676f8;
// R6GameService.dll code @ 10067700
constexpr unsigned int ReadServiceState9Unwind5 = 0x10067700;
// R6GameService.dll code @ 10067708
constexpr unsigned int ReadServiceState9Unwind6 = 0x10067708;
// R6GameService.dll code @ 10067710
constexpr unsigned int ReadServiceState9Unwind7 = 0x10067710;
// R6GameService.dll code @ 10067718
constexpr unsigned int SelectState9ReaderEH = 0x10067718;
// R6GameService.dll code @ 10067730
constexpr unsigned int request_state_supportSharedLifetimeUnwind12 = 0x10067730;
// R6GameService.dll code @ 10067738
constexpr unsigned int request_state_supportSharedLifetimeUnwind22 = 0x10067738;
// R6GameService.dll code @ 10067740
constexpr unsigned int request_state_supportSharedLifetimeUnwind32 = 0x10067740;
// R6GameService.dll code @ 10067748
constexpr unsigned int request_state_supportSharedLifetimeUnwind42 = 0x10067748;
// R6GameService.dll code @ 10067750
constexpr unsigned int request_state_supportSharedLifetimeUnwind5 = 0x10067750;
// R6GameService.dll code @ 10067758
constexpr unsigned int request_state_supportSharedLifetimeUnwind6 = 0x10067758;
// R6GameService.dll code @ 10067760
constexpr unsigned int request_state_supportSharedLifetimeUnwind7 = 0x10067760;
// R6GameService.dll code @ 10067768
constexpr unsigned int request_state_supportSharedLifetimeUnwind8 = 0x10067768;
// R6GameService.dll code @ 10067770
constexpr unsigned int SelectSelector17And18ReaderEH = 0x10067770;
// R6GameService.dll code @ 10067780
constexpr unsigned int ProcessKeyRecordTokenUnwind1 = 0x10067780;
// R6GameService.dll code @ 10067788
constexpr unsigned int ProcessKeyRecordTokenUnwind2 = 0x10067788;
// R6GameService.dll code @ 10067790
constexpr unsigned int ProcessKeyRecordTokenUnwind4 = 0x10067790;
// R6GameService.dll code @ 10067798
constexpr unsigned int ProcessKeyRecordTokenUnwind5 = 0x10067798;
// R6GameService.dll code @ 100677bf
constexpr unsigned int ProcessKeyRecordTokenUnwind6 = 0x100677bf;
// R6GameService.dll code @ 100677c7
constexpr unsigned int ProcessKeyRecordTokenUnwind7 = 0x100677c7;
// R6GameService.dll code @ 100677ee
constexpr unsigned int ProcessKeyRecordTokenUnwind3 = 0x100677ee;
// R6GameService.dll code @ 100677f6
constexpr unsigned int ProcessKeyRecordTokenUnwind8 = 0x100677f6;
// R6GameService.dll code @ 100677fe
constexpr unsigned int ProcessKeyRecordTokenUnwind9 = 0x100677fe;
// R6GameService.dll code @ 10067825
constexpr unsigned int SelectKeyRecordTokenEH = 0x10067825;
// R6GameService.dll code @ 10067830
constexpr unsigned int ProcessIndexedTextUpdateUnwind1 = 0x10067830;
// R6GameService.dll code @ 1006783b
constexpr unsigned int ProcessIndexedTextUpdateUnwind2 = 0x1006783b;
// R6GameService.dll code @ 10067846
constexpr unsigned int ProcessIndexedTextUpdateUnwind3 = 0x10067846;
// R6GameService.dll code @ 10067851
constexpr unsigned int ProcessIndexedTextUpdateUnwind4 = 0x10067851;
// R6GameService.dll code @ 1006785c
constexpr unsigned int SelectIndexedTextUpdateEH = 0x1006785c;
// R6GameService.dll code @ 10067870
constexpr unsigned int RemoveDecodedKeyRecordUnwind1 = 0x10067870;
// R6GameService.dll code @ 10067878
constexpr unsigned int RemoveDecodedKeyRecordUnwind2 = 0x10067878;
// R6GameService.dll code @ 10067880
constexpr unsigned int RemoveDecodedKeyRecordUnwind3 = 0x10067880;
// R6GameService.dll code @ 10067888
constexpr unsigned int RemoveDecodedKeyRecordUnwind4 = 0x10067888;
// R6GameService.dll code @ 100678af
constexpr unsigned int RemoveDecodedKeyRecordUnwind5 = 0x100678af;
// R6GameService.dll code @ 100678b7
constexpr unsigned int RemoveDecodedKeyRecordUnwind6 = 0x100678b7;
// R6GameService.dll code @ 100678de
constexpr unsigned int RemoveDecodedKeyRecordUnwind7 = 0x100678de;
// R6GameService.dll code @ 100678e6
constexpr unsigned int RemoveDecodedKeyRecordUnwind8 = 0x100678e6;
// R6GameService.dll code @ 1006790d
constexpr unsigned int RemoveDecodedKeyRecordUnwind9 = 0x1006790d;
// R6GameService.dll code @ 10067915
constexpr unsigned int RemoveDecodedKeyRecordUnwind10 = 0x10067915;
// R6GameService.dll code @ 1006793c
constexpr unsigned int SelectSelector37ReaderEH = 0x1006793c;
// R6GameService.dll code @ 10067950
constexpr unsigned int request_state_supportSharedLifetimeUnwind1 = 0x10067950;
// R6GameService.dll code @ 10067958
constexpr unsigned int request_state_supportSharedLifetimeUnwind2 = 0x10067958;
// R6GameService.dll code @ 10067960
constexpr unsigned int request_state_supportSharedLifetimeUnwind3 = 0x10067960;
// R6GameService.dll code @ 10067968
constexpr unsigned int request_state_supportSharedLifetimeUnwind4 = 0x10067968;
// R6GameService.dll code @ 10067970
constexpr unsigned int SelectSelector0cReaderEH = 0x10067970;
// R6GameService.dll code @ 10067980
constexpr unsigned int request_state_supportSharedLifetimeUnwind16 = 0x10067980;
// R6GameService.dll code @ 10067988
constexpr unsigned int request_state_supportSharedLifetimeUnwind26 = 0x10067988;
// R6GameService.dll code @ 10067990
constexpr unsigned int request_state_supportSharedLifetimeUnwind36 = 0x10067990;
// R6GameService.dll code @ 10067998
constexpr unsigned int request_state_supportSharedLifetimeUnwind45 = 0x10067998;
// R6GameService.dll code @ 100679a0
constexpr unsigned int request_state_supportSharedLifetimeUnwind54 = 0x100679a0;
// R6GameService.dll code @ 100679a8
constexpr unsigned int SelectMarkerTextVariantsEH = 0x100679a8;
// R6GameService.dll code @ 100679c0
constexpr unsigned int request_state_supportSharedLifetimeUnwind13 = 0x100679c0;
// R6GameService.dll code @ 100679c8
constexpr unsigned int request_state_supportSharedLifetimeUnwind23 = 0x100679c8;
// R6GameService.dll code @ 100679d0
constexpr unsigned int request_state_supportSharedLifetimeUnwind33 = 0x100679d0;
// R6GameService.dll code @ 100679d8
constexpr unsigned int request_state_supportSharedLifetimeUnwind43 = 0x100679d8;
// R6GameService.dll code @ 100679e0
constexpr unsigned int request_state_supportSharedLifetimeUnwind52 = 0x100679e0;
// R6GameService.dll code @ 100679e8
constexpr unsigned int request_state_supportSharedLifetimeUnwind62 = 0x100679e8;
// R6GameService.dll code @ 100679f0
constexpr unsigned int request_state_supportSharedLifetimeUnwind72 = 0x100679f0;
// R6GameService.dll code @ 10067a17
constexpr unsigned int request_state_supportSharedLifetimeUnwind82 = 0x10067a17;
// R6GameService.dll code @ 10067a1f
constexpr unsigned int request_state_supportSharedLifetimeUnwind9 = 0x10067a1f;
// R6GameService.dll code @ 10067a46
constexpr unsigned int SelectSharedPairReadersEH = 0x10067a46;
// R6GameService.dll code @ 10067a50
constexpr unsigned int DispatchSelector20EntriesUnwind1 = 0x10067a50;
// R6GameService.dll code @ 10067a58
constexpr unsigned int DispatchSelector20EntriesUnwind2 = 0x10067a58;
// R6GameService.dll code @ 10067a60
constexpr unsigned int DispatchSelector20EntriesUnwind3 = 0x10067a60;
// R6GameService.dll code @ 10067a68
constexpr unsigned int DispatchSelector20EntriesUnwind4 = 0x10067a68;
// R6GameService.dll code @ 10067a70
constexpr unsigned int DispatchSelector20EntriesUnwind7 = 0x10067a70;
// R6GameService.dll code @ 10067a78
constexpr unsigned int DispatchSelector20EntriesUnwind5 = 0x10067a78;
// R6GameService.dll code @ 10067a80
constexpr unsigned int DispatchSelector20EntriesUnwind6 = 0x10067a80;
// R6GameService.dll code @ 10067a88
constexpr unsigned int SelectSelector20DispatcherEH = 0x10067a88;
// R6GameService.dll code @ 10067aa0
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind1 = 0x10067aa0;
// R6GameService.dll code @ 10067aa8
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind2 = 0x10067aa8;
// R6GameService.dll code @ 10067ab0
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind3 = 0x10067ab0;
// R6GameService.dll code @ 10067ab8
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind4 = 0x10067ab8;
// R6GameService.dll code @ 10067ac0
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind5 = 0x10067ac0;
// R6GameService.dll code @ 10067ac8
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwind6 = 0x10067ac8;
// R6GameService.dll code @ 10067ad0
constexpr unsigned int SelectSelector38ExtractEH = 0x10067ad0;
// R6GameService.dll code @ 10067ae0
constexpr unsigned int request_state_supportSharedLifetimeUnwind14 = 0x10067ae0;
// R6GameService.dll code @ 10067ae8
constexpr unsigned int request_state_supportSharedLifetimeUnwind24 = 0x10067ae8;
// R6GameService.dll code @ 10067af0
constexpr unsigned int request_state_supportSharedLifetimeUnwind34 = 0x10067af0;
// R6GameService.dll code @ 10067af8
constexpr unsigned int request_state_supportSharedLifetimeUnwind44 = 0x10067af8;
// R6GameService.dll code @ 10067b00
constexpr unsigned int request_state_supportSharedLifetimeUnwind53 = 0x10067b00;
// R6GameService.dll code @ 10067b08
constexpr unsigned int request_state_supportSharedLifetimeUnwind63 = 0x10067b08;
// R6GameService.dll code @ 10067b10
constexpr unsigned int request_state_supportSharedLifetimeUnwind73 = 0x10067b10;
// R6GameService.dll code @ 10067b18
constexpr unsigned int SelectSharedMarkerReaderEH = 0x10067b18;
// R6GameService.dll code @ 10067b30
constexpr unsigned int request_state_supportSharedLifetimeUnwind15 = 0x10067b30;
// R6GameService.dll code @ 10067b38
constexpr unsigned int request_state_supportSharedLifetimeUnwind25 = 0x10067b38;
// R6GameService.dll code @ 10067b40
constexpr unsigned int request_state_supportSharedLifetimeUnwind35 = 0x10067b40;
// R6GameService.dll code @ 10067b48
constexpr unsigned int SelectMarkerTextReaderEH = 0x10067b48;
// R6GameService.dll code @ 10067b60
constexpr unsigned int ParseSelector3fValueAndTextUnwind1 = 0x10067b60;
// R6GameService.dll code @ 10067b68
constexpr unsigned int ParseSelector3fValueAndTextUnwind2 = 0x10067b68;
// R6GameService.dll code @ 10067b70
constexpr unsigned int ParseSelector3fValueAndTextUnwind3 = 0x10067b70;
// R6GameService.dll code @ 10067b78
constexpr unsigned int ParseSelector3fValueAndTextUnwind4 = 0x10067b78;
// R6GameService.dll code @ 10067b80
constexpr unsigned int ParseSelector3fValueAndTextUnwind5 = 0x10067b80;
// R6GameService.dll code @ 10067b88
constexpr unsigned int ParseSelector3fValueAndTextUnwind6 = 0x10067b88;
// R6GameService.dll code @ 10067baf
constexpr unsigned int ParseSelector3fValueAndTextUnwind7 = 0x10067baf;
// R6GameService.dll code @ 10067bb7
constexpr unsigned int ParseSelector3fValueAndTextUnwind8 = 0x10067bb7;
// R6GameService.dll code @ 10067bde
constexpr unsigned int SelectSelector3fReaderEH = 0x10067bde;
// R6GameService.dll code @ 10067bf0
constexpr unsigned int ParseSelector41IndexedValueUnwind1 = 0x10067bf0;
// R6GameService.dll code @ 10067bf8
constexpr unsigned int ParseSelector41IndexedValueUnwind2 = 0x10067bf8;
// R6GameService.dll code @ 10067c00
constexpr unsigned int ParseSelector41IndexedValueUnwind3 = 0x10067c00;
// R6GameService.dll code @ 10067c27
constexpr unsigned int ParseSelector41IndexedValueUnwind4 = 0x10067c27;
// R6GameService.dll code @ 10067c2f
constexpr unsigned int ParseSelector41IndexedValueUnwind5 = 0x10067c2f;
// R6GameService.dll code @ 10067c56
constexpr unsigned int ParseSelector41IndexedValueUnwind6 = 0x10067c56;
// R6GameService.dll code @ 10067c5e
constexpr unsigned int ParseSelector41IndexedValueUnwind7 = 0x10067c5e;
// R6GameService.dll code @ 10067c85
constexpr unsigned int ParseSelector41IndexedValueUnwind8 = 0x10067c85;
// R6GameService.dll code @ 10067c8d
constexpr unsigned int ParseSelector41IndexedValueUnwind9 = 0x10067c8d;
// R6GameService.dll code @ 10067cb4
constexpr unsigned int SelectSelector41ReaderEH = 0x10067cb4;
// R6GameService.dll code @ 10067cc0
constexpr unsigned int DispatchSelector36RecordUnwind1 = 0x10067cc0;
// R6GameService.dll code @ 10067ccb
constexpr unsigned int DispatchSelector36RecordUnwind2 = 0x10067ccb;
// R6GameService.dll code @ 10067cd6
constexpr unsigned int DispatchSelector36RecordUnwind3 = 0x10067cd6;
// R6GameService.dll code @ 10067ce1
constexpr unsigned int DispatchSelector36RecordUnwind4 = 0x10067ce1;
// R6GameService.dll code @ 10067d17
constexpr unsigned int DispatchSelector36RecordUnwind5 = 0x10067d17;
// R6GameService.dll code @ 10067d22
constexpr unsigned int DispatchSelector36RecordUnwind6 = 0x10067d22;
// R6GameService.dll code @ 10067d58
constexpr unsigned int DispatchSelector36RecordUnwind7 = 0x10067d58;
// R6GameService.dll code @ 10067d63
constexpr unsigned int DispatchSelector36RecordUnwind8 = 0x10067d63;
// R6GameService.dll code @ 10067d99
constexpr unsigned int SelectSelector36EH = 0x10067d99;
// R6GameService.dll code @ 10067db0
constexpr unsigned int DispatchSelector35SubrecordsUnwind1 = 0x10067db0;
// R6GameService.dll code @ 10067dbb
constexpr unsigned int DispatchSelector35SubrecordsUnwind2 = 0x10067dbb;
// R6GameService.dll code @ 10067dc6
constexpr unsigned int DispatchSelector35SubrecordsUnwind3 = 0x10067dc6;
// R6GameService.dll code @ 10067dd1
constexpr unsigned int DispatchSelector35SubrecordsUnwind4 = 0x10067dd1;
// R6GameService.dll code @ 10067ddc
constexpr unsigned int DispatchSelector35SubrecordsUnwind5 = 0x10067ddc;
// R6GameService.dll code @ 10067de7
constexpr unsigned int DispatchSelector35SubrecordsUnwind6 = 0x10067de7;
// R6GameService.dll code @ 10067df2
constexpr unsigned int DispatchSelector35SubrecordsUnwind8 = 0x10067df2;
// R6GameService.dll code @ 10067dfd
constexpr unsigned int DispatchSelector35SubrecordsUnwind7 = 0x10067dfd;
// R6GameService.dll code @ 10067e08
constexpr unsigned int SelectSelector35EH = 0x10067e08;
// R6GameService.dll code @ 10067e20
constexpr unsigned int DispatchSelector32RecordUnwind1 = 0x10067e20;
// R6GameService.dll code @ 10067e2b
constexpr unsigned int DispatchSelector32RecordUnwind2 = 0x10067e2b;
// R6GameService.dll code @ 10067e36
constexpr unsigned int DispatchSelector32RecordUnwind3 = 0x10067e36;
// R6GameService.dll code @ 10067e41
constexpr unsigned int SelectSelector32EH = 0x10067e41;
// R6GameService.dll code @ 10067e50
constexpr unsigned int DispatchSelector33IndexedValuesUnwind1 = 0x10067e50;
// R6GameService.dll code @ 10067e58
constexpr unsigned int DispatchSelector33IndexedValuesUnwind2 = 0x10067e58;
// R6GameService.dll code @ 10067e60
constexpr unsigned int DispatchSelector33IndexedValuesUnwind3 = 0x10067e60;
// R6GameService.dll code @ 10067e68
constexpr unsigned int DispatchSelector33IndexedValuesUnwind4 = 0x10067e68;
// R6GameService.dll code @ 10067e70
constexpr unsigned int DispatchSelector33IndexedValuesUnwind5 = 0x10067e70;
// R6GameService.dll code @ 10067e78
constexpr unsigned int DispatchSelector33IndexedValuesUnwind6 = 0x10067e78;
// R6GameService.dll code @ 10067e80
constexpr unsigned int SelectSelector33EH = 0x10067e80;
// R6GameService.dll code @ 10067e90
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwind1 = 0x10067e90;
// R6GameService.dll code @ 10067e98
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwind2 = 0x10067e98;
// R6GameService.dll code @ 10067ea0
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwind5 = 0x10067ea0;
// R6GameService.dll code @ 10067ea8
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwind3 = 0x10067ea8;
// R6GameService.dll code @ 10067eb0
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwind4 = 0x10067eb0;
// R6GameService.dll code @ 10067eb8
constexpr unsigned int SelectSelector97EH = 0x10067eb8;
// R6GameService.dll code @ 10067ed0
constexpr unsigned int DispatchSelector40TextValuesUnwind1 = 0x10067ed0;
// R6GameService.dll code @ 10067ed8
constexpr unsigned int DispatchSelector40TextValuesUnwind2 = 0x10067ed8;
// R6GameService.dll code @ 10067ee0
constexpr unsigned int DispatchSelector40TextValuesUnwind3 = 0x10067ee0;
// R6GameService.dll code @ 10067f07
constexpr unsigned int DispatchSelector40TextValuesUnwind4 = 0x10067f07;
// R6GameService.dll code @ 10067f0f
constexpr unsigned int DispatchSelector40TextValuesUnwind5 = 0x10067f0f;
// R6GameService.dll code @ 10067f36
constexpr unsigned int DispatchSelector40TextValuesUnwind6 = 0x10067f36;
// R6GameService.dll code @ 10067f3e
constexpr unsigned int DispatchSelector40TextValuesUnwind7 = 0x10067f3e;
// R6GameService.dll code @ 10067f65
constexpr unsigned int DispatchSelector40TextValuesUnwind8 = 0x10067f65;
// R6GameService.dll code @ 10067f6d
constexpr unsigned int DispatchSelector40TextValuesUnwind9 = 0x10067f6d;
// R6GameService.dll code @ 10067f94
constexpr unsigned int SelectSelector40EH = 0x10067f94;
// R6GameService.dll code @ 10067fa0
constexpr unsigned int DispatchSelector42TextAndBinaryUnwind1 = 0x10067fa0;
// R6GameService.dll code @ 10067fa8
constexpr unsigned int DispatchSelector42TextAndBinaryUnwind2 = 0x10067fa8;
// R6GameService.dll code @ 10067fb0
constexpr unsigned int DispatchSelector42TextAndBinaryUnwind3 = 0x10067fb0;
// R6GameService.dll code @ 10067fb8
constexpr unsigned int DispatchSelector42TextAndBinaryUnwind4 = 0x10067fb8;
// R6GameService.dll code @ 10067fc0
constexpr unsigned int SelectSelector42EH = 0x10067fc0;
// R6GameService.dll code @ 10067fd0
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind1 = 0x10067fd0;
// R6GameService.dll code @ 10067fd8
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind2 = 0x10067fd8;
// R6GameService.dll code @ 10067fe0
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind3 = 0x10067fe0;
// R6GameService.dll code @ 10067fe8
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind4 = 0x10067fe8;
// R6GameService.dll code @ 10067ff0
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind5 = 0x10067ff0;
// R6GameService.dll code @ 10067ff8
constexpr unsigned int DispatchSelector6aTextAndPairsUnwind6 = 0x10067ff8;
// R6GameService.dll code @ 10068000
constexpr unsigned int SelectSelector6aEH = 0x10068000;
// R6GameService.dll code @ 10068010
constexpr unsigned int DispatchSelector47VariantPayloadUnwind1 = 0x10068010;
// R6GameService.dll code @ 10068018
constexpr unsigned int DispatchSelector47VariantPayloadUnwind2 = 0x10068018;
// R6GameService.dll code @ 10068020
constexpr unsigned int DispatchSelector47VariantPayloadUnwind5 = 0x10068020;
// R6GameService.dll code @ 10068028
constexpr unsigned int DispatchSelector47VariantPayloadUnwind6 = 0x10068028;
// R6GameService.dll code @ 10068030
constexpr unsigned int DispatchSelector47VariantPayloadUnwind7 = 0x10068030;
// R6GameService.dll code @ 10068038
constexpr unsigned int DispatchSelector47VariantPayloadUnwind3 = 0x10068038;
// R6GameService.dll code @ 10068040
constexpr unsigned int DispatchSelector47VariantPayloadUnwind4 = 0x10068040;
// R6GameService.dll code @ 10068048
constexpr unsigned int SelectSelector47EH = 0x10068048;
// R6GameService.dll code @ 10068060
constexpr unsigned int PassesOptionalServiceTreeNameFilterUnwind1 = 0x10068060;
// R6GameService.dll code @ 10068068
constexpr unsigned int PassesOptionalServiceTreeNameFilterUnwind2 = 0x10068068;
// R6GameService.dll code @ 10068070
constexpr unsigned int PassesOptionalServiceTreeNameFilterUnwind3 = 0x10068070;
// R6GameService.dll code @ 10068078
constexpr unsigned int SelectServiceNameFilterEH = 0x10068078;
// R6GameService.dll code @ 10068090
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedTextUnwind1 = 0x10068090;
// R6GameService.dll code @ 1006809b
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedTextUnwind2 = 0x1006809b;
// R6GameService.dll code @ 100680a6
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedTextUnwind3 = 0x100680a6;
// R6GameService.dll code @ 100680b1
constexpr unsigned int SelectServiceNameTokenEH = 0x100680b1;
// R6GameService.dll code @ 100680c0
constexpr unsigned int CreateServiceTreeByteStringNodeUnwind2 = 0x100680c0;
// R6GameService.dll code @ 100680d1
constexpr unsigned int CreateServiceTreeByteStringNodeUnwind3 = 0x100680d1;
// R6GameService.dll code @ 100680d9
constexpr unsigned int SelectServiceStringNodeEH = 0x100680d9;
// R6GameService.dll code @ 100680f0
constexpr unsigned int ReleaseCMsgQueueNodesOnUnwind = 0x100680f0;
// R6GameService.dll code @ 100680fb
constexpr unsigned int CMsgQueueDestroyExceptionHandler = 0x100680fb;
// R6GameService.dll code @ 10068110
constexpr unsigned int CleanupQueueRemovalTemporaryBase = 0x10068110;
// R6GameService.dll code @ 10068127
constexpr unsigned int ResetQueueRemovalTemporaryAtState1 = 0x10068127;
// R6GameService.dll code @ 1006812f
constexpr unsigned int DestroyQueueRemovalTemporaryAtState2 = 0x1006812f;
// R6GameService.dll code @ 10068137
constexpr unsigned int ResetQueueRemovalTemporaryAtState4 = 0x10068137;
// R6GameService.dll code @ 1006813f
constexpr unsigned int ResetQueueRemovalTemporaryAtState3 = 0x1006813f;
// R6GameService.dll code @ 10068147
constexpr unsigned int CMsgQueueRemoveExceptionHandler = 0x10068147;
// R6GameService.dll code @ 10068160
constexpr unsigned int ResetQueuePeekTemporaryAtState0 = 0x10068160;
// R6GameService.dll code @ 10068168
constexpr unsigned int CleanupQueuePeekConstructionTag = 0x10068168;
// R6GameService.dll code @ 10068170
constexpr unsigned int DestroyQueuePeekTemporaryAtState2 = 0x10068170;
// R6GameService.dll code @ 10068178
constexpr unsigned int ResetQueuePeekTemporaryAtState3 = 0x10068178;
// R6GameService.dll code @ 10068180
constexpr unsigned int ReleaseQueuePeekTemporaryNodesAtState4 = 0x10068180;
// R6GameService.dll code @ 100681a7
constexpr unsigned int CMsgQueuePeekExceptionHandler = 0x100681a7;
// R6GameService.dll code @ 100681c0
constexpr unsigned int CleanupPayloadRecordVirtualBase = 0x100681c0;
// R6GameService.dll code @ 100681da
constexpr unsigned int ReleasePayloadRecordConstructorAllocation = 0x100681da;
// R6GameService.dll code @ 100681e4
constexpr unsigned int PayloadRecordConstructExceptionHandler = 0x100681e4;
// R6GameService.dll code @ 100681f0
constexpr unsigned int CleanupPayloadRecordCopyVirtualBase = 0x100681f0;
// R6GameService.dll code @ 1006820a
constexpr unsigned int ReleasePayloadRecordCopyAllocation = 0x1006820a;
// R6GameService.dll code @ 10068214
constexpr unsigned int PayloadRecordCopyExceptionHandler = 0x10068214;
// R6GameService.dll code @ 10068220
constexpr unsigned int shared_nativeSharedLifetimeUnwind1 = 0x10068220;
// R6GameService.dll code @ 1006822a
constexpr unsigned int SelectConnectionAllocationEH = 0x1006822a;
// R6GameService.dll code @ 10068240
constexpr unsigned int CConnectionListDestroyUnwind1 = 0x10068240;
// R6GameService.dll code @ 10068248
constexpr unsigned int CConnectionListDestroyUnwind2 = 0x10068248;
// R6GameService.dll code @ 10068253
constexpr unsigned int CConnectionListDestroyUnwind3 = 0x10068253;
// R6GameService.dll code @ 1006827a
constexpr unsigned int CConnectionListDestroyUnwind4 = 0x1006827a;
// R6GameService.dll code @ 10068282
constexpr unsigned int CConnectionListDestroyUnwind5 = 0x10068282;
// R6GameService.dll code @ 100682a9
constexpr unsigned int SelectConnectionListDestroyEH = 0x100682a9;
// R6GameService.dll code @ 100682c0
constexpr unsigned int CConnectionListConstructUnwind1 = 0x100682c0;
// R6GameService.dll code @ 100682c8
constexpr unsigned int SelectConnectionListCtorEH = 0x100682c8;
// R6GameService.dll code @ 100682e0
constexpr unsigned int list_node_supportSharedLifetimeUnwind1 = 0x100682e0;
// R6GameService.dll code @ 10068307
constexpr unsigned int SelectTypedPointerListDestroyEH = 0x10068307;
// R6GameService.dll code @ 10068320
constexpr unsigned int ReadTransportSelectorRecordUnwind1 = 0x10068320;
// R6GameService.dll code @ 10068337
constexpr unsigned int ReadTransportSelectorRecordUnwind2 = 0x10068337;
// R6GameService.dll code @ 1006833f
constexpr unsigned int ReadTransportSelectorRecordUnwind4 = 0x1006833f;
// R6GameService.dll code @ 10068347
constexpr unsigned int ReadTransportSelectorRecordUnwind5 = 0x10068347;
// R6GameService.dll code @ 1006834f
constexpr unsigned int ReadTransportSelectorRecordUnwind6 = 0x1006834f;
// R6GameService.dll code @ 10068376
constexpr unsigned int ReadTransportSelectorRecordUnwind7 = 0x10068376;
// R6GameService.dll code @ 1006837e
constexpr unsigned int ReadTransportSelectorRecordUnwind8 = 0x1006837e;
// R6GameService.dll code @ 100683a5
constexpr unsigned int ReadTransportSelectorRecordUnwind9 = 0x100683a5;
// R6GameService.dll code @ 100683ad
constexpr unsigned int ReadTransportSelectorRecordUnwind10 = 0x100683ad;
// R6GameService.dll code @ 100683d4
constexpr unsigned int SelectTransportRecordEH = 0x100683d4;
// R6GameService.dll code @ 100683e0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind1 = 0x100683e0;
// R6GameService.dll code @ 100683e8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind2 = 0x100683e8;
// R6GameService.dll code @ 100683f0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind3 = 0x100683f0;
// R6GameService.dll code @ 100683f8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind4 = 0x100683f8;
// R6GameService.dll code @ 10068400
constexpr unsigned int transport_record_supportSharedLifetimeUnwind5 = 0x10068400;
// R6GameService.dll code @ 10068427
constexpr unsigned int transport_record_supportSharedLifetimeUnwind6 = 0x10068427;
// R6GameService.dll code @ 1006842f
constexpr unsigned int SelectTransportSendersEH = 0x1006842f;
// R6GameService.dll code @ 10068440
constexpr unsigned int ParseSelector5aOwnedBytesUnwind1 = 0x10068440;
// R6GameService.dll code @ 10068448
constexpr unsigned int ParseSelector5aOwnedBytesUnwind2 = 0x10068448;
// R6GameService.dll code @ 10068450
constexpr unsigned int ParseSelector5aOwnedBytesUnwind3 = 0x10068450;
// R6GameService.dll code @ 10068458
constexpr unsigned int ParseSelector5aOwnedBytesUnwind4 = 0x10068458;
// R6GameService.dll code @ 10068460
constexpr unsigned int ParseSelector5aOwnedBytesUnwind5 = 0x10068460;
// R6GameService.dll code @ 10068468
constexpr unsigned int ParseSelector5aOwnedBytesUnwind6 = 0x10068468;
// R6GameService.dll code @ 10068470
constexpr unsigned int ParseSelector5aOwnedBytesUnwind7 = 0x10068470;
// R6GameService.dll code @ 10068478
constexpr unsigned int ParseSelector5aOwnedBytesUnwind8 = 0x10068478;
// R6GameService.dll code @ 10068480
constexpr unsigned int SelectTransport5aEH = 0x10068480;
// R6GameService.dll code @ 10068490
constexpr unsigned int transport_record_supportSharedLifetimeUnwind12 = 0x10068490;
// R6GameService.dll code @ 10068498
constexpr unsigned int transport_record_supportSharedLifetimeUnwind22 = 0x10068498;
// R6GameService.dll code @ 100684a0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind32 = 0x100684a0;
// R6GameService.dll code @ 100684a8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind42 = 0x100684a8;
// R6GameService.dll code @ 100684b0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind52 = 0x100684b0;
// R6GameService.dll code @ 100684b8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind62 = 0x100684b8;
// R6GameService.dll code @ 100684c0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind7 = 0x100684c0;
// R6GameService.dll code @ 100684c8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind8 = 0x100684c8;
// R6GameService.dll code @ 100684d0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind9 = 0x100684d0;
// R6GameService.dll code @ 100684f7
constexpr unsigned int SelectTransport58And5bEH = 0x100684f7;
// R6GameService.dll code @ 10068510
constexpr unsigned int ParseSelector08FieldsUnwind1 = 0x10068510;
// R6GameService.dll code @ 10068518
constexpr unsigned int ParseSelector08FieldsUnwind2 = 0x10068518;
// R6GameService.dll code @ 10068520
constexpr unsigned int ParseSelector08FieldsUnwind3 = 0x10068520;
// R6GameService.dll code @ 10068528
constexpr unsigned int ParseSelector08FieldsUnwind4 = 0x10068528;
// R6GameService.dll code @ 1006854f
constexpr unsigned int ParseSelector08FieldsUnwind5 = 0x1006854f;
// R6GameService.dll code @ 10068557
constexpr unsigned int ParseSelector08FieldsUnwind6 = 0x10068557;
// R6GameService.dll code @ 1006857e
constexpr unsigned int ParseSelector08FieldsUnwind7 = 0x1006857e;
// R6GameService.dll code @ 10068586
constexpr unsigned int ParseSelector08FieldsUnwind8 = 0x10068586;
// R6GameService.dll code @ 100685ad
constexpr unsigned int ParseSelector08FieldsUnwind9 = 0x100685ad;
// R6GameService.dll code @ 100685b5
constexpr unsigned int ParseSelector08FieldsUnwind10 = 0x100685b5;
// R6GameService.dll code @ 100685dc
constexpr unsigned int SelectTransport08EH = 0x100685dc;
// R6GameService.dll code @ 100685f0
constexpr unsigned int ParseSelector98FieldsUnwind1 = 0x100685f0;
// R6GameService.dll code @ 100685f8
constexpr unsigned int ParseSelector98FieldsUnwind2 = 0x100685f8;
// R6GameService.dll code @ 10068600
constexpr unsigned int ParseSelector98FieldsUnwind3 = 0x10068600;
// R6GameService.dll code @ 10068608
constexpr unsigned int ParseSelector98FieldsUnwind4 = 0x10068608;
// R6GameService.dll code @ 10068610
constexpr unsigned int ParseSelector98FieldsUnwind5 = 0x10068610;
// R6GameService.dll code @ 10068618
constexpr unsigned int ParseSelector98FieldsUnwind6 = 0x10068618;
// R6GameService.dll code @ 10068620
constexpr unsigned int ParseSelector98FieldsUnwind7 = 0x10068620;
// R6GameService.dll code @ 10068647
constexpr unsigned int ParseSelector98FieldsUnwind8 = 0x10068647;
// R6GameService.dll code @ 1006864f
constexpr unsigned int ParseSelector98FieldsUnwind9 = 0x1006864f;
// R6GameService.dll code @ 10068676
constexpr unsigned int SelectTransport98EH = 0x10068676;
// R6GameService.dll code @ 10068680
constexpr unsigned int transport_record_supportSharedLifetimeUnwind13 = 0x10068680;
// R6GameService.dll code @ 10068688
constexpr unsigned int transport_record_supportSharedLifetimeUnwind23 = 0x10068688;
// R6GameService.dll code @ 10068690
constexpr unsigned int transport_record_supportSharedLifetimeUnwind33 = 0x10068690;
// R6GameService.dll code @ 10068698
constexpr unsigned int transport_record_supportSharedLifetimeUnwind43 = 0x10068698;
// R6GameService.dll code @ 100686a0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind53 = 0x100686a0;
// R6GameService.dll code @ 100686a8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind63 = 0x100686a8;
// R6GameService.dll code @ 100686b0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind72 = 0x100686b0;
// R6GameService.dll code @ 100686b8
constexpr unsigned int SelectTransport4f50EH = 0x100686b8;
// R6GameService.dll code @ 100686d0
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind1 = 0x100686d0;
// R6GameService.dll code @ 100686e7
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind2 = 0x100686e7;
// R6GameService.dll code @ 100686ef
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind4 = 0x100686ef;
// R6GameService.dll code @ 100686f7
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind5 = 0x100686f7;
// R6GameService.dll code @ 100686ff
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind6 = 0x100686ff;
// R6GameService.dll code @ 10068726
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind7 = 0x10068726;
// R6GameService.dll code @ 1006872e
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind8 = 0x1006872e;
// R6GameService.dll code @ 10068755
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind9 = 0x10068755;
// R6GameService.dll code @ 1006875d
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwind10 = 0x1006875d;
// R6GameService.dll code @ 10068784
constexpr unsigned int SelectOptionalTransportWordEH = 0x10068784;
// R6GameService.dll code @ 10068790
constexpr unsigned int SendSelector66StringTupleUnwind1 = 0x10068790;
// R6GameService.dll code @ 10068798
constexpr unsigned int SendSelector66StringTupleUnwind2 = 0x10068798;
// R6GameService.dll code @ 100687a0
constexpr unsigned int SendSelector66StringTupleUnwind3 = 0x100687a0;
// R6GameService.dll code @ 100687a8
constexpr unsigned int SendSelector66StringTupleUnwind4 = 0x100687a8;
// R6GameService.dll code @ 100687b0
constexpr unsigned int SendSelector66StringTupleUnwind5 = 0x100687b0;
// R6GameService.dll code @ 100687d7
constexpr unsigned int SendSelector66StringTupleUnwind6 = 0x100687d7;
// R6GameService.dll code @ 100687df
constexpr unsigned int SelectTextSender66EH = 0x100687df;
// R6GameService.dll code @ 100687f0
constexpr unsigned int transport_record_supportSharedLifetimeUnwind14 = 0x100687f0;
// R6GameService.dll code @ 100687f8
constexpr unsigned int transport_record_supportSharedLifetimeUnwind24 = 0x100687f8;
// R6GameService.dll code @ 10068800
constexpr unsigned int transport_record_supportSharedLifetimeUnwind34 = 0x10068800;
// R6GameService.dll code @ 10068808
constexpr unsigned int transport_record_supportSharedLifetimeUnwind44 = 0x10068808;
// R6GameService.dll code @ 10068810
constexpr unsigned int transport_record_supportSharedLifetimeUnwind54 = 0x10068810;
// R6GameService.dll code @ 10068837
constexpr unsigned int transport_record_supportSharedLifetimeUnwind64 = 0x10068837;
// R6GameService.dll code @ 1006883f
constexpr unsigned int SelectTextSender4d13EH = 0x1006883f;
// R6GameService.dll code @ 10068850
constexpr unsigned int SendEmptySelector5dUnwind1 = 0x10068850;
// R6GameService.dll code @ 10068858
constexpr unsigned int SendEmptySelector5dUnwind2 = 0x10068858;
// R6GameService.dll code @ 10068860
constexpr unsigned int SendEmptySelector5dUnwind3 = 0x10068860;
// R6GameService.dll code @ 10068868
constexpr unsigned int SendEmptySelector5dUnwind4 = 0x10068868;
// R6GameService.dll code @ 10068870
constexpr unsigned int SendEmptySelector5dUnwind5 = 0x10068870;
// R6GameService.dll code @ 10068897
constexpr unsigned int SendEmptySelector5dUnwind6 = 0x10068897;
// R6GameService.dll code @ 1006889f
constexpr unsigned int SelectTextSender5dEH = 0x1006889f;
// R6GameService.dll code @ 100688b0
constexpr unsigned int ParseSelector13RecordIntoOutputsUnwind1 = 0x100688b0;
// R6GameService.dll code @ 100688b8
constexpr unsigned int ParseSelector13RecordIntoOutputsUnwind2 = 0x100688b8;
// R6GameService.dll code @ 100688c0
constexpr unsigned int ParseSelector13RecordIntoOutputsUnwind3 = 0x100688c0;
// R6GameService.dll code @ 100688c8
constexpr unsigned int ParseSelector13RecordIntoOutputsUnwind4 = 0x100688c8;
// R6GameService.dll code @ 100688d0
constexpr unsigned int SelectTransport13FieldEH = 0x100688d0;
// R6GameService.dll code @ 100688e0
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind1 = 0x100688e0;
// R6GameService.dll code @ 100688e8
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind2 = 0x100688e8;
// R6GameService.dll code @ 100688f0
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind3 = 0x100688f0;
// R6GameService.dll code @ 100688f8
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind4 = 0x100688f8;
// R6GameService.dll code @ 10068900
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind5 = 0x10068900;
// R6GameService.dll code @ 10068908
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind6 = 0x10068908;
// R6GameService.dll code @ 10068910
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind7 = 0x10068910;
// R6GameService.dll code @ 10068918
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind8 = 0x10068918;
// R6GameService.dll code @ 10068920
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwind9 = 0x10068920;
// R6GameService.dll code @ 10068947
constexpr unsigned int SelectTransport5dFieldEH = 0x10068947;
// R6GameService.dll code @ 10068960
constexpr unsigned int ParseSelectorDETextFieldsUnwind1 = 0x10068960;
// R6GameService.dll code @ 10068968
constexpr unsigned int ParseSelectorDETextFieldsUnwind2 = 0x10068968;
// R6GameService.dll code @ 10068970
constexpr unsigned int ParseSelectorDETextFieldsUnwind3 = 0x10068970;
// R6GameService.dll code @ 10068978
constexpr unsigned int ParseSelectorDETextFieldsUnwind4 = 0x10068978;
// R6GameService.dll code @ 10068980
constexpr unsigned int ParseSelectorDETextFieldsUnwind5 = 0x10068980;
// R6GameService.dll code @ 10068988
constexpr unsigned int ParseSelectorDETextFieldsUnwind6 = 0x10068988;
// R6GameService.dll code @ 10068990
constexpr unsigned int ParseSelectorDETextFieldsUnwind7 = 0x10068990;
// R6GameService.dll code @ 10068998
constexpr unsigned int ParseSelectorDETextFieldsUnwind8 = 0x10068998;
// R6GameService.dll code @ 100689a0
constexpr unsigned int ParseSelectorDETextFieldsUnwind9 = 0x100689a0;
// R6GameService.dll code @ 100689a8
constexpr unsigned int SelectTransportDEFieldEH = 0x100689a8;
// R6GameService.dll code @ 100689c0
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind1 = 0x100689c0;
// R6GameService.dll code @ 100689cb
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind2 = 0x100689cb;
// R6GameService.dll code @ 100689d6
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind3 = 0x100689d6;
// R6GameService.dll code @ 100689e1
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind4 = 0x100689e1;
// R6GameService.dll code @ 100689e9
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind5 = 0x100689e9;
// R6GameService.dll code @ 100689f1
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwind6 = 0x100689f1;
// R6GameService.dll code @ 100689f9
constexpr unsigned int SelectNestedOwnerDestroyEH = 0x100689f9;
// R6GameService.dll code @ 10068a10
constexpr unsigned int EnsureOuterRecordExistsUnwind1 = 0x10068a10;
// R6GameService.dll code @ 10068a1b
constexpr unsigned int EnsureOuterRecordExistsUnwind2 = 0x10068a1b;
// R6GameService.dll code @ 10068a28
constexpr unsigned int EnsureOuterRecordExistsUnwind3 = 0x10068a28;
// R6GameService.dll code @ 10068a33
constexpr unsigned int EnsureOuterRecordExistsUnwind4 = 0x10068a33;
// R6GameService.dll code @ 10068a3e
constexpr unsigned int EnsureOuterRecordExistsUnwind5 = 0x10068a3e;
// R6GameService.dll code @ 10068a49
constexpr unsigned int SelectOuterRecordCreationEH = 0x10068a49;
// R6GameService.dll code @ 10068a60
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind1 = 0x10068a60;
// R6GameService.dll code @ 10068a68
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind2 = 0x10068a68;
// R6GameService.dll code @ 10068a70
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind3 = 0x10068a70;
// R6GameService.dll code @ 10068a78
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind4 = 0x10068a78;
// R6GameService.dll code @ 10068a80
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind5 = 0x10068a80;
// R6GameService.dll code @ 10068a88
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwind6 = 0x10068a88;
// R6GameService.dll code @ 10068a90
constexpr unsigned int SelectNestedNotificationEH = 0x10068a90;
// R6GameService.dll code @ 10068aa0
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind1 = 0x10068aa0;
// R6GameService.dll code @ 10068aa8
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind2 = 0x10068aa8;
// R6GameService.dll code @ 10068ab0
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind3 = 0x10068ab0;
// R6GameService.dll code @ 10068abb
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind4 = 0x10068abb;
// R6GameService.dll code @ 10068ac6
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind5 = 0x10068ac6;
// R6GameService.dll code @ 10068ace
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind6 = 0x10068ace;
// R6GameService.dll code @ 10068ad6
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind7 = 0x10068ad6;
// R6GameService.dll code @ 10068ade
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind8 = 0x10068ade;
// R6GameService.dll code @ 10068ae6
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind9 = 0x10068ae6;
// R6GameService.dll code @ 10068aee
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwind10 = 0x10068aee;
// R6GameService.dll code @ 10068af6
constexpr unsigned int SelectRecordTextUpdateEH = 0x10068af6;
// R6GameService.dll code @ 10068b00
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind1 = 0x10068b00;
// R6GameService.dll code @ 10068b08
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind2 = 0x10068b08;
// R6GameService.dll code @ 10068b10
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind3 = 0x10068b10;
// R6GameService.dll code @ 10068b18
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind4 = 0x10068b18;
// R6GameService.dll code @ 10068b20
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind5 = 0x10068b20;
// R6GameService.dll code @ 10068b28
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind6 = 0x10068b28;
// R6GameService.dll code @ 10068b30
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwind7 = 0x10068b30;
// R6GameService.dll code @ 10068b38
constexpr unsigned int SelectQueuedResponseEH = 0x10068b38;
// R6GameService.dll code @ 10068b50
constexpr unsigned int QueueMissingNestedRecordRequestUnwind1 = 0x10068b50;
// R6GameService.dll code @ 10068b58
constexpr unsigned int QueueMissingNestedRecordRequestUnwind2 = 0x10068b58;
// R6GameService.dll code @ 10068b60
constexpr unsigned int QueueMissingNestedRecordRequestUnwind3 = 0x10068b60;
// R6GameService.dll code @ 10068b68
constexpr unsigned int QueueMissingNestedRecordRequestUnwind4 = 0x10068b68;
// R6GameService.dll code @ 10068b70
constexpr unsigned int QueueMissingNestedRecordRequestUnwind5 = 0x10068b70;
// R6GameService.dll code @ 10068b78
constexpr unsigned int QueueMissingNestedRecordRequestUnwind6 = 0x10068b78;
// R6GameService.dll code @ 10068b80
constexpr unsigned int QueueMissingNestedRecordRequestUnwind7 = 0x10068b80;
// R6GameService.dll code @ 10068ba7
constexpr unsigned int SelectMissingRecordRequestEH = 0x10068ba7;
// R6GameService.dll code @ 10068bc0
constexpr unsigned int indexed_record_supportSharedLifetimeUnwind12 = 0x10068bc0;
// R6GameService.dll code @ 10068bca
constexpr unsigned int SelectRecordQueueAllocationEH = 0x10068bca;
// R6GameService.dll code @ 10068be0
constexpr unsigned int CopyRecordStateAndNestedTreeUnwind1 = 0x10068be0;
// R6GameService.dll code @ 10068be8
constexpr unsigned int CopyRecordStateAndNestedTreeUnwind2 = 0x10068be8;
// R6GameService.dll code @ 10068bf0
constexpr unsigned int SelectRecordTreeCopyEH = 0x10068bf0;
// R6GameService.dll code @ 10068c00
constexpr unsigned int SelectTreeCloneCatchEH = 0x10068c00;
// R6GameService.dll code @ 10068c10
constexpr unsigned int AllocateTreeNodeWithCopiedExtendedPayloadUnwind2 = 0x10068c10;
// R6GameService.dll code @ 10068c21
constexpr unsigned int SelectExtendedNodeCopyEH = 0x10068c21;
// R6GameService.dll code @ 10068c30
constexpr unsigned int indexed_record_supportSharedLifetimeUnwind1 = 0x10068c30;
// R6GameService.dll code @ 10068c38
constexpr unsigned int SelectRecordTreeDestroyEH = 0x10068c38;
// R6GameService.dll code @ 10068c50
constexpr unsigned int CLobbySrvConnectionListConstructUnwind1 = 0x10068c50;
// R6GameService.dll code @ 10068c6d
constexpr unsigned int CLobbySrvConnectionListConstructUnwind2 = 0x10068c6d;
// R6GameService.dll code @ 10068c75
constexpr unsigned int CLobbySrvConnectionListConstructUnwind3 = 0x10068c75;
// R6GameService.dll code @ 10068c8f
constexpr unsigned int CLobbySrvConnectionListConstructUnwind4 = 0x10068c8f;
// R6GameService.dll code @ 10068c97
constexpr unsigned int CLobbySrvConnectionListConstructUnwind5 = 0x10068c97;
// R6GameService.dll code @ 10068ca5
constexpr unsigned int CLobbySrvConnectionListConstructUnwind6 = 0x10068ca5;
// R6GameService.dll code @ 10068cbf
constexpr unsigned int CLobbySrvConnectionListConstructUnwind7 = 0x10068cbf;
// R6GameService.dll code @ 10068cc7
constexpr unsigned int CLobbySrvConnectionListConstructUnwind8 = 0x10068cc7;
// R6GameService.dll code @ 10068cd5
constexpr unsigned int CLobbySrvConnectionListConstructUnwind9 = 0x10068cd5;
// R6GameService.dll code @ 10068cef
constexpr unsigned int CLobbySrvConnectionListConstructUnwind10 = 0x10068cef;
// R6GameService.dll code @ 10068cf7
constexpr unsigned int CLobbySrvConnectionListConstructUnwind11 = 0x10068cf7;
// R6GameService.dll code @ 10068cff
constexpr unsigned int SelectLobbyConnectionListCtorEH = 0x10068cff;
// R6GameService.dll code @ 10068d10
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind1 = 0x10068d10;
// R6GameService.dll code @ 10068d18
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind2 = 0x10068d18;
// R6GameService.dll code @ 10068d26
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind3 = 0x10068d26;
// R6GameService.dll code @ 10068d34
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind4 = 0x10068d34;
// R6GameService.dll code @ 10068d42
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind5 = 0x10068d42;
// R6GameService.dll code @ 10068d4a
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind6 = 0x10068d4a;
// R6GameService.dll code @ 10068d52
constexpr unsigned int CLobbySrvConnectionListDestroyUnwind7 = 0x10068d52;
// R6GameService.dll code @ 10068d5a
constexpr unsigned int SelectLobbyConnectionListDestroyEH = 0x10068d5a;
// R6GameService.dll code @ 10068d70
constexpr unsigned int ReleaseIndexedTreeUnwind1 = 0x10068d70;
// R6GameService.dll code @ 10068d78
constexpr unsigned int SelectIndexedTreeDestroyEH = 0x10068d78;
// R6GameService.dll code @ 10068d90
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind1 = 0x10068d90;
// R6GameService.dll code @ 10068d98
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind2 = 0x10068d98;
// R6GameService.dll code @ 10068da0
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind3 = 0x10068da0;
// R6GameService.dll code @ 10068da8
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind4 = 0x10068da8;
// R6GameService.dll code @ 10068db0
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind5 = 0x10068db0;
// R6GameService.dll code @ 10068db8
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind6 = 0x10068db8;
// R6GameService.dll code @ 10068dc0
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind7 = 0x10068dc0;
// R6GameService.dll code @ 10068dc8
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind8 = 0x10068dc8;
// R6GameService.dll code @ 10068dd0
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind9 = 0x10068dd0;
// R6GameService.dll code @ 10068dd8
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwind10 = 0x10068dd8;
// R6GameService.dll code @ 10068de0
constexpr unsigned int SelectKeyRecordNotificationEH = 0x10068de0;
// R6GameService.dll code @ 10068df0
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind1 = 0x10068df0;
// R6GameService.dll code @ 10068df8
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind2 = 0x10068df8;
// R6GameService.dll code @ 10068e00
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind3 = 0x10068e00;
// R6GameService.dll code @ 10068e08
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind4 = 0x10068e08;
// R6GameService.dll code @ 10068e10
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind5 = 0x10068e10;
// R6GameService.dll code @ 10068e18
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind6 = 0x10068e18;
// R6GameService.dll code @ 10068e20
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind7 = 0x10068e20;
// R6GameService.dll code @ 10068e28
constexpr unsigned int UpdateKeyedTextAndNotifyUnwind8 = 0x10068e28;
// R6GameService.dll code @ 10068e30
constexpr unsigned int SelectLobbyUpdateEH = 0x10068e30;
// R6GameService.dll code @ 10068e40
constexpr unsigned int SendKeyNotificationD1Unwind1 = 0x10068e40;
// R6GameService.dll code @ 10068e48
constexpr unsigned int SendKeyNotificationD1Unwind2 = 0x10068e48;
// R6GameService.dll code @ 10068e50
constexpr unsigned int SendKeyNotificationD1Unwind3 = 0x10068e50;
// R6GameService.dll code @ 10068e58
constexpr unsigned int SendKeyNotificationD1Unwind4 = 0x10068e58;
// R6GameService.dll code @ 10068e60
constexpr unsigned int SendKeyNotificationD1Unwind5 = 0x10068e60;
// R6GameService.dll code @ 10068e68
constexpr unsigned int SendKeyNotificationD1Unwind6 = 0x10068e68;
// R6GameService.dll code @ 10068e70
constexpr unsigned int SendKeyNotificationD1Unwind7 = 0x10068e70;
// R6GameService.dll code @ 10068e78
constexpr unsigned int SendKeyNotificationD1Unwind8 = 0x10068e78;
// R6GameService.dll code @ 10068e80
constexpr unsigned int SelectKeyNotificationSenderEH = 0x10068e80;
// R6GameService.dll code @ 10068e90
constexpr unsigned int BuildRecordFromQueueHeadOrFallbackUnwind1 = 0x10068e90;
// R6GameService.dll code @ 10068e9a
constexpr unsigned int SelectLobbyFallbackEH = 0x10068e9a;
// R6GameService.dll code @ 10068eb0
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind1 = 0x10068eb0;
// R6GameService.dll code @ 10068eb8
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind2 = 0x10068eb8;
// R6GameService.dll code @ 10068ec0
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind3 = 0x10068ec0;
// R6GameService.dll code @ 10068ec8
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind4 = 0x10068ec8;
// R6GameService.dll code @ 10068ed0
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind5 = 0x10068ed0;
// R6GameService.dll code @ 10068ed8
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind6 = 0x10068ed8;
// R6GameService.dll code @ 10068ee0
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwind7 = 0x10068ee0;
// R6GameService.dll code @ 10068ee8
constexpr unsigned int SelectLobbyRemovalEH = 0x10068ee8;
// R6GameService.dll code @ 10068f00
constexpr unsigned int ApplyIndexedKeyUpdateUnwind1 = 0x10068f00;
// R6GameService.dll code @ 10068f08
constexpr unsigned int ApplyIndexedKeyUpdateUnwind2 = 0x10068f08;
// R6GameService.dll code @ 10068f10
constexpr unsigned int ApplyIndexedKeyUpdateUnwind3 = 0x10068f10;
// R6GameService.dll code @ 10068f18
constexpr unsigned int ApplyIndexedKeyUpdateUnwind4 = 0x10068f18;
// R6GameService.dll code @ 10068f20
constexpr unsigned int ApplyIndexedKeyUpdateUnwind5 = 0x10068f20;
// R6GameService.dll code @ 10068f28
constexpr unsigned int ApplyIndexedKeyUpdateUnwind6 = 0x10068f28;
// R6GameService.dll code @ 10068f30
constexpr unsigned int ApplyIndexedKeyUpdateUnwind7 = 0x10068f30;
// R6GameService.dll code @ 10068f38
constexpr unsigned int ApplyIndexedKeyUpdateUnwind8 = 0x10068f38;
// R6GameService.dll code @ 10068f40
constexpr unsigned int SelectKeyUpdateEH = 0x10068f40;
// R6GameService.dll code @ 10068f50
constexpr unsigned int QueueTaggedRecordUnwind1 = 0x10068f50;
// R6GameService.dll code @ 10068f58
constexpr unsigned int QueueTaggedRecordUnwind2 = 0x10068f58;
// R6GameService.dll code @ 10068f62
constexpr unsigned int QueueTaggedRecordUnwind3 = 0x10068f62;
// R6GameService.dll code @ 10068f6a
constexpr unsigned int QueueTaggedRecordUnwind4 = 0x10068f6a;
// R6GameService.dll code @ 10068f91
constexpr unsigned int SelectQueuedRecordEH = 0x10068f91;
// R6GameService.dll code @ 10068fa0
constexpr unsigned int SendDescriptorAsD1Unwind1 = 0x10068fa0;
// R6GameService.dll code @ 10068fa8
constexpr unsigned int SendDescriptorAsD1Unwind2 = 0x10068fa8;
// R6GameService.dll code @ 10068fb0
constexpr unsigned int SendDescriptorAsD1Unwind3 = 0x10068fb0;
// R6GameService.dll code @ 10068fb8
constexpr unsigned int SendDescriptorAsD1Unwind4 = 0x10068fb8;
// R6GameService.dll code @ 10068fc0
constexpr unsigned int SendDescriptorAsD1Unwind5 = 0x10068fc0;
// R6GameService.dll code @ 10068fc8
constexpr unsigned int SendDescriptorAsD1Unwind6 = 0x10068fc8;
// R6GameService.dll code @ 10068fef
constexpr unsigned int SendDescriptorAsD1Unwind7 = 0x10068fef;
// R6GameService.dll code @ 10068ff7
constexpr unsigned int SendDescriptorAsD1Unwind8 = 0x10068ff7;
// R6GameService.dll code @ 1006901e
constexpr unsigned int SelectD1SenderEH = 0x1006901e;
// R6GameService.dll code @ 10069030
constexpr unsigned int InsertIndexedTextRecordUnwind1 = 0x10069030;
// R6GameService.dll code @ 1006903b
constexpr unsigned int InsertIndexedTextRecordUnwind2 = 0x1006903b;
// R6GameService.dll code @ 10069046
constexpr unsigned int InsertIndexedTextRecordUnwind3 = 0x10069046;
// R6GameService.dll code @ 10069051
constexpr unsigned int InsertIndexedTextRecordUnwind4 = 0x10069051;
// R6GameService.dll code @ 1006905c
constexpr unsigned int InsertIndexedTextRecordUnwind5 = 0x1006905c;
// R6GameService.dll code @ 10069067
constexpr unsigned int SelectIndexedRecordProducerEH = 0x10069067;
// R6GameService.dll code @ 10069080
constexpr unsigned int CloneCircularListUnwind1 = 0x10069080;
// R6GameService.dll code @ 10069088
constexpr unsigned int SelectIndexedListCloneEH = 0x10069088;
// R6GameService.dll code @ 100690a0
constexpr unsigned int AllocateIndexedRecordAndCopyListUnwind2 = 0x100690a0;
// R6GameService.dll code @ 100690b1
constexpr unsigned int AllocateIndexedRecordAndCopyListUnwind3 = 0x100690b1;
// R6GameService.dll code @ 100690b9
constexpr unsigned int SelectIndexedListNodeEH = 0x100690b9;
// R6GameService.dll code @ 100690d0
constexpr unsigned int clMatchResults_UnwindKeyedResults = 0x100690d0;
// R6GameService.dll code @ 100690db
constexpr unsigned int clMatchResults_UnwindKeyedResults2 = 0x100690db;
// R6GameService.dll code @ 100690e6
constexpr unsigned int clMatchResults_UnwindKeyedResults3 = 0x100690e6;
// R6GameService.dll code @ 100690f1
constexpr unsigned int clMatchResults_UnwindKeyedResults4 = 0x100690f1;
// R6GameService.dll code @ 100690fc
constexpr unsigned int clMatchResults_UnwindKeyedResults5 = 0x100690fc;
// R6GameService.dll code @ 10069104
constexpr unsigned int clMatchResults_UnwindKeyedResults6 = 0x10069104;
// R6GameService.dll code @ 1006910c
constexpr unsigned int clMatchResults_UnwindKeyedResults7 = 0x1006910c;
// R6GameService.dll code @ 10069117
constexpr unsigned int clMatchResults_UnwindKeyedResults8 = 0x10069117;
// R6GameService.dll code @ 10069122
constexpr unsigned int clMatchResults_UnwindKeyedResults9 = 0x10069122;
// R6GameService.dll code @ 1006912d
constexpr unsigned int clMatchResults_UnwindKeyedResults10 = 0x1006912d;
// R6GameService.dll code @ 10069138
constexpr unsigned int clMatchResults_SelectKeyedResultsEH = 0x10069138;
// R6GameService.dll code @ 10069150
constexpr unsigned int ordered_tree_support_UnwindCollection = 0x10069150;
// R6GameService.dll code @ 10069158
constexpr unsigned int ordered_tree_support_UnwindCollection2 = 0x10069158;
// R6GameService.dll code @ 10069160
constexpr unsigned int ordered_tree_support_SelectCollectionEH = 0x10069160;
// R6GameService.dll code @ 10069170
constexpr unsigned int AppendOrderedRecordsToDescriptorUnwind1 = 0x10069170;
// R6GameService.dll code @ 10069178
constexpr unsigned int AppendOrderedRecordsToDescriptorUnwind2 = 0x10069178;
// R6GameService.dll code @ 10069180
constexpr unsigned int AppendOrderedRecordsToDescriptorUnwind3 = 0x10069180;
// R6GameService.dll code @ 10069188
constexpr unsigned int AppendOrderedRecordsToDescriptorUnwind4 = 0x10069188;
// R6GameService.dll code @ 100691af
constexpr unsigned int SelectMatchResultsAppendEH = 0x100691af;
// R6GameService.dll code @ 100691c0
constexpr unsigned int ConstructHeapByteStringFromCStringUnwind1 = 0x100691c0;
// R6GameService.dll code @ 100691cb
constexpr unsigned int ConstructHeapByteStringFromCStringUnwind2 = 0x100691cb;
// R6GameService.dll code @ 100691d6
constexpr unsigned int ConstructHeapByteStringFromCStringUnwind3 = 0x100691d6;
// R6GameService.dll code @ 100691e1
constexpr unsigned int ConstructHeapByteStringFromCStringUnwind4 = 0x100691e1;
// R6GameService.dll code @ 100691ec
constexpr unsigned int SelectCStringConstructorEH = 0x100691ec;
// R6GameService.dll code @ 10069200
constexpr unsigned int keyed_results_support_UnwindKeyedResults2 = 0x10069200;
// R6GameService.dll code @ 10069208
constexpr unsigned int keyed_results_support_SelectKeyedResultsEH = 0x10069208;
// R6GameService.dll code @ 10069220
constexpr unsigned int SelectIndexedCloneEH = 0x10069220;
// R6GameService.dll code @ 10069230
constexpr unsigned int UnwindIndexedNode = 0x10069230;
// R6GameService.dll code @ 10069241
constexpr unsigned int ordered_tree_support_UnwindIndexedNode = 0x10069241;
// R6GameService.dll code @ 10069249
constexpr unsigned int ordered_tree_support_UnwindIndexedNode2 = 0x10069249;
// R6GameService.dll code @ 10069251
constexpr unsigned int ordered_tree_support_SelectIndexedCloneEH = 0x10069251;
// R6GameService.dll code @ 10069260
constexpr unsigned int ordered_tree_support_UnwindCollection3 = 0x10069260;
// R6GameService.dll code @ 10069268
constexpr unsigned int ordered_tree_support_SelectCollectionEH2 = 0x10069268;
// R6GameService.dll code @ 10069280
constexpr unsigned int AppendIndexedValuesToDescriptorUnwind1 = 0x10069280;
// R6GameService.dll code @ 10069288
constexpr unsigned int AppendIndexedValuesToDescriptorUnwind2 = 0x10069288;
// R6GameService.dll code @ 10069290
constexpr unsigned int AppendIndexedValuesToDescriptorUnwind3 = 0x10069290;
// R6GameService.dll code @ 10069298
constexpr unsigned int AppendIndexedValuesToDescriptorUnwind4 = 0x10069298;
// R6GameService.dll code @ 100692bf
constexpr unsigned int SelectPlayerResultsAppendEH = 0x100692bf;
// R6GameService.dll code @ 100692d0
constexpr unsigned int FreeStandaloneEncryptedRecordOnUnwind = 0x100692d0;
// R6GameService.dll code @ 100692da
constexpr unsigned int FreeStandaloneGameRecordOnUnwind = 0x100692da;
// R6GameService.dll code @ 100692e4
constexpr unsigned int FreeStandaloneGSRecordOnUnwind = 0x100692e4;
// R6GameService.dll code @ 100692ee
constexpr unsigned int TransportRecordDecodeExceptionHandler = 0x100692ee;
// R6GameService.dll code @ 10069300
constexpr unsigned int InitializeTransportRecordUnwind1 = 0x10069300;
// R6GameService.dll code @ 1006931a
constexpr unsigned int InitializeTransportRecordUnwind2 = 0x1006931a;
// R6GameService.dll code @ 10069334
constexpr unsigned int InitializeTransportRecordUnwind4 = 0x10069334;
// R6GameService.dll code @ 1006933c
constexpr unsigned int InitializeTransportRecordUnwind5 = 0x1006933c;
// R6GameService.dll code @ 10069347
constexpr unsigned int InitializeTransportRecordUnwind6 = 0x10069347;
// R6GameService.dll code @ 10069352
constexpr unsigned int InitializeTransportRecordUnwind7 = 0x10069352;
// R6GameService.dll code @ 1006935d
constexpr unsigned int InitializeTransportRecordUnwind8 = 0x1006935d;
// R6GameService.dll code @ 10069367
constexpr unsigned int InitializeTransportRecordUnwind9 = 0x10069367;
// R6GameService.dll code @ 10069371
constexpr unsigned int InitializeTransportRecordUnwind10 = 0x10069371;
// R6GameService.dll code @ 1006938b
constexpr unsigned int InitializeTransportRecordUnwind11 = 0x1006938b;
// R6GameService.dll code @ 10069395
constexpr unsigned int SelectConnectElemCtorEH = 0x10069395;
// R6GameService.dll code @ 100693a0
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwind1 = 0x100693a0;
// R6GameService.dll code @ 100693a8
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwind2 = 0x100693a8;
// R6GameService.dll code @ 100693b3
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwind3 = 0x100693b3;
// R6GameService.dll code @ 100693be
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwind4 = 0x100693be;
// R6GameService.dll code @ 100693c9
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwind5 = 0x100693c9;
// R6GameService.dll code @ 100693d3
constexpr unsigned int SelectConnectElemAlternateCtorEH = 0x100693d3;
// R6GameService.dll code @ 100693e0
constexpr unsigned int DestroyTransportRecordMembersUnwind1 = 0x100693e0;
// R6GameService.dll code @ 100693eb
constexpr unsigned int DestroyTransportRecordMembersUnwind2 = 0x100693eb;
// R6GameService.dll code @ 100693f6
constexpr unsigned int DestroyTransportRecordMembersUnwind3 = 0x100693f6;
// R6GameService.dll code @ 10069401
constexpr unsigned int DestroyTransportRecordMembersUnwind4 = 0x10069401;
// R6GameService.dll code @ 10069428
constexpr unsigned int DestroyTransportRecordMembersUnwind5 = 0x10069428;
// R6GameService.dll code @ 10069430
constexpr unsigned int DestroyTransportRecordMembersUnwind6 = 0x10069430;
// R6GameService.dll code @ 10069457
constexpr unsigned int DestroyTransportRecordMembersUnwind7 = 0x10069457;
// R6GameService.dll code @ 1006947e
constexpr unsigned int DestroyTransportRecordMembersUnwind8 = 0x1006947e;
// R6GameService.dll code @ 10069486
constexpr unsigned int SelectConnectElemDestroyEH = 0x10069486;
// R6GameService.dll code @ 10069490
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind1 = 0x10069490;
// R6GameService.dll code @ 10069498
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind2 = 0x10069498;
// R6GameService.dll code @ 100694a0
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind3 = 0x100694a0;
// R6GameService.dll code @ 100694a8
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind4 = 0x100694a8;
// R6GameService.dll code @ 100694b0
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind5 = 0x100694b0;
// R6GameService.dll code @ 100694d7
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwind6 = 0x100694d7;
// R6GameService.dll code @ 100694df
constexpr unsigned int SelectDecimalControlRecordEH = 0x100694df;
// R6GameService.dll code @ 100694f0
constexpr unsigned int UpdateTransportProviderUnwind1 = 0x100694f0;
// R6GameService.dll code @ 100694f8
constexpr unsigned int UpdateTransportProviderUnwind2 = 0x100694f8;
// R6GameService.dll code @ 10069500
constexpr unsigned int UpdateTransportProviderUnwind3 = 0x10069500;
// R6GameService.dll code @ 1006950a
constexpr unsigned int UpdateTransportProviderUnwind4 = 0x1006950a;
// R6GameService.dll code @ 10069512
constexpr unsigned int UpdateTransportProviderUnwind5 = 0x10069512;
// R6GameService.dll code @ 1006951c
constexpr unsigned int SelectProviderUpdateEH = 0x1006951c;
// R6GameService.dll code @ 10069530
constexpr unsigned int FreeQueuedEncryptedRecordOnUnwind = 0x10069530;
// R6GameService.dll code @ 1006953a
constexpr unsigned int FreeQueuedGameRecordOnUnwind = 0x1006953a;
// R6GameService.dll code @ 10069544
constexpr unsigned int FreeQueuedGSRecordOnUnwind = 0x10069544;
// R6GameService.dll code @ 1006954e
constexpr unsigned int QueuedTransportDecodeExceptionHandler = 0x1006954e;
// R6GameService.dll code @ 10069560
constexpr unsigned int provider_control_supportSharedLifetimeUnwind1 = 0x10069560;
// R6GameService.dll code @ 1006956a
constexpr unsigned int SelectPayloadBuilderEH = 0x1006956a;
// R6GameService.dll code @ 10069580
constexpr unsigned int DispatchProviderControlPayloadUnwind1 = 0x10069580;
// R6GameService.dll code @ 10069588
constexpr unsigned int DispatchProviderControlPayloadUnwind2 = 0x10069588;
// R6GameService.dll code @ 10069590
constexpr unsigned int DispatchProviderControlPayloadUnwind3 = 0x10069590;
// R6GameService.dll code @ 10069598
constexpr unsigned int DispatchProviderControlPayloadUnwind4 = 0x10069598;
// R6GameService.dll code @ 100695bf
constexpr unsigned int DispatchProviderControlPayloadUnwind5 = 0x100695bf;
// R6GameService.dll code @ 100695c7
constexpr unsigned int DispatchProviderControlPayloadUnwind6 = 0x100695c7;
// R6GameService.dll code @ 100695ee
constexpr unsigned int DispatchProviderControlPayloadUnwind7 = 0x100695ee;
// R6GameService.dll code @ 100695f6
constexpr unsigned int DispatchProviderControlPayloadUnwind8 = 0x100695f6;
// R6GameService.dll code @ 1006961d
constexpr unsigned int SelectProviderControlEH = 0x1006961d;
// R6GameService.dll code @ 10069630
constexpr unsigned int HandleTransportBufferControlPayloadUnwind1 = 0x10069630;
// R6GameService.dll code @ 10069638
constexpr unsigned int HandleTransportBufferControlPayloadUnwind2 = 0x10069638;
// R6GameService.dll code @ 10069640
constexpr unsigned int HandleTransportBufferControlPayloadUnwind3 = 0x10069640;
// R6GameService.dll code @ 10069648
constexpr unsigned int HandleTransportBufferControlPayloadUnwind4 = 0x10069648;
// R6GameService.dll code @ 1006966f
constexpr unsigned int HandleTransportBufferControlPayloadUnwind5 = 0x1006966f;
// R6GameService.dll code @ 10069677
constexpr unsigned int HandleTransportBufferControlPayloadUnwind6 = 0x10069677;
// R6GameService.dll code @ 1006969e
constexpr unsigned int HandleTransportBufferControlPayloadUnwind7 = 0x1006969e;
// R6GameService.dll code @ 100696a6
constexpr unsigned int HandleTransportBufferControlPayloadUnwind8 = 0x100696a6;
// R6GameService.dll code @ 100696cd
constexpr unsigned int HandleTransportBufferControlPayloadUnwind9 = 0x100696cd;
// R6GameService.dll code @ 100696d5
constexpr unsigned int HandleTransportBufferControlPayloadUnwind10 = 0x100696d5;
// R6GameService.dll code @ 100696fc
constexpr unsigned int SelectControlBufferEH = 0x100696fc;
// R6GameService.dll code @ 10069710
constexpr unsigned int provider_control_supportSharedLifetimeUnwind12 = 0x10069710;
// R6GameService.dll code @ 10069718
constexpr unsigned int provider_control_supportSharedLifetimeUnwind2 = 0x10069718;
// R6GameService.dll code @ 10069720
constexpr unsigned int provider_control_supportSharedLifetimeUnwind3 = 0x10069720;
// R6GameService.dll code @ 10069728
constexpr unsigned int provider_control_supportSharedLifetimeUnwind4 = 0x10069728;
// R6GameService.dll code @ 10069730
constexpr unsigned int provider_control_supportSharedLifetimeUnwind5 = 0x10069730;
// R6GameService.dll code @ 10069738
constexpr unsigned int provider_control_supportSharedLifetimeUnwind6 = 0x10069738;
// R6GameService.dll code @ 10069740
constexpr unsigned int provider_control_supportSharedLifetimeUnwind7 = 0x10069740;
// R6GameService.dll code @ 10069767
constexpr unsigned int SelectControlQueueEH = 0x10069767;
// R6GameService.dll code @ 10069780
constexpr unsigned int clPointerListSharedLifetimeUnwind1 = 0x10069780;
// R6GameService.dll code @ 100697a7
constexpr unsigned int SelectTypedListDestructorEH = 0x100697a7;
// R6GameService.dll code @ 100697c0
constexpr unsigned int clSRPGSConnectConstructUnwind1 = 0x100697c0;
// R6GameService.dll code @ 100697da
constexpr unsigned int SelectSRPGSConnectCtorEH = 0x100697da;
// R6GameService.dll code @ 100697f0
constexpr unsigned int clSRPGSConnectDestroyUnwind1 = 0x100697f0;
// R6GameService.dll code @ 100697f8
constexpr unsigned int SelectSRPGSConnectDestroyEH = 0x100697f8;
// R6GameService.dll code @ 10069810
constexpr unsigned int DecodeProviderReceiveFramesUnwind2 = 0x10069810;
// R6GameService.dll code @ 1006981a
constexpr unsigned int DecodeProviderReceiveFramesUnwind1 = 0x1006981a;
// R6GameService.dll code @ 10069824
constexpr unsigned int SelectFramedReceiveEH = 0x10069824;
// R6GameService.dll code @ 10069830
constexpr unsigned int clSRPGSClientConstructUnwind1 = 0x10069830;
// R6GameService.dll code @ 1006983a
constexpr unsigned int SelectSRPGSClientEH = 0x1006983a;
// R6GameService.dll code @ 10069850
constexpr unsigned int CleanupMessageVirtualBaseIfConstructed = 0x10069850;
// R6GameService.dll code @ 1006986a
constexpr unsigned int ResetMessageBaseDuringConstruction = 0x1006986a;
// R6GameService.dll code @ 10069872
constexpr unsigned int FreeMessagePendingAllocation = 0x10069872;
// R6GameService.dll code @ 1006987c
constexpr unsigned int MessageConstructionExceptionHandler = 0x1006987c;
// R6GameService.dll code @ 10069890
constexpr unsigned int ResetMessageBaseDuringDestruction = 0x10069890;
// R6GameService.dll code @ 10069898
constexpr unsigned int MessageDestructionExceptionHandler = 0x10069898;
// R6GameService.dll code @ 100698b0
constexpr unsigned int SerializePayloadRecordUnwind1 = 0x100698b0;
// R6GameService.dll code @ 100698c7
constexpr unsigned int SerializePayloadRecordUnwind2 = 0x100698c7;
// R6GameService.dll code @ 100698cf
constexpr unsigned int SerializePayloadRecordUnwind3 = 0x100698cf;
// R6GameService.dll code @ 100698d7
constexpr unsigned int SerializePayloadRecordUnwind4 = 0x100698d7;
// R6GameService.dll code @ 100698df
constexpr unsigned int SerializePayloadRecordUnwind5 = 0x100698df;
// R6GameService.dll code @ 100698e7
constexpr unsigned int SerializePayloadRecordUnwind6 = 0x100698e7;
// R6GameService.dll code @ 100698ef
constexpr unsigned int SelectMessageSerializerEH = 0x100698ef;
// R6GameService.dll code @ 10069900
constexpr unsigned int DecodePayloadRecordUnwind1 = 0x10069900;
// R6GameService.dll code @ 10069917
constexpr unsigned int DecodePayloadRecordUnwind2 = 0x10069917;
// R6GameService.dll code @ 1006991f
constexpr unsigned int DecodePayloadRecordUnwind3 = 0x1006991f;
// R6GameService.dll code @ 10069927
constexpr unsigned int DecodePayloadRecordUnwind4 = 0x10069927;
// R6GameService.dll code @ 1006992f
constexpr unsigned int DecodePayloadRecordUnwind5 = 0x1006992f;
// R6GameService.dll code @ 10069946
constexpr unsigned int DecodePayloadRecordUnwind6 = 0x10069946;
// R6GameService.dll code @ 1006994e
constexpr unsigned int DecodePayloadRecordUnwind7 = 0x1006994e;
// R6GameService.dll code @ 10069956
constexpr unsigned int DecodePayloadRecordUnwind8 = 0x10069956;
// R6GameService.dll code @ 10069960
constexpr unsigned int DecodePayloadRecordUnwind9 = 0x10069960;
// R6GameService.dll code @ 1006997a
constexpr unsigned int DecodePayloadRecordUnwind10 = 0x1006997a;
// R6GameService.dll code @ 10069982
constexpr unsigned int SelectMessageDecoderEH = 0x10069982;
// R6GameService.dll code @ 10069990
constexpr unsigned int ResetBasePrintedRecordList = 0x10069990;
// R6GameService.dll code @ 1006999b
constexpr unsigned int DestroyPrintedRecordList = 0x1006999b;
// R6GameService.dll code @ 100699a6
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList = 0x100699a6;
// R6GameService.dll code @ 100699b1
constexpr unsigned int clGSMessage_DestroyPrintedRecordList = 0x100699b1;
// R6GameService.dll code @ 100699bc
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList2 = 0x100699bc;
// R6GameService.dll code @ 100699c7
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList3 = 0x100699c7;
// R6GameService.dll code @ 100699d2
constexpr unsigned int clGSMessage_DestroyPrintedRecordList2 = 0x100699d2;
// R6GameService.dll code @ 100699dd
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList4 = 0x100699dd;
// R6GameService.dll code @ 100699e8
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList5 = 0x100699e8;
// R6GameService.dll code @ 100699f3
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList6 = 0x100699f3;
// R6GameService.dll code @ 100699fe
constexpr unsigned int clGSMessage_DestroyPrintedRecordList3 = 0x100699fe;
// R6GameService.dll code @ 10069a09
constexpr unsigned int clGSMessage_ResetBasePrintedRecordList7 = 0x10069a09;
// R6GameService.dll code @ 10069a14
constexpr unsigned int PrintedRecordExceptionHandler = 0x10069a14;
// R6GameService.dll code @ 10069a20
constexpr unsigned int ConstructSharedCryptoContextUnwind1 = 0x10069a20;
// R6GameService.dll code @ 10069a3a
constexpr unsigned int SelectSharedCryptoCtorEH = 0x10069a3a;
// R6GameService.dll code @ 10069a50
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind1 = 0x10069a50;
// R6GameService.dll code @ 10069a6d
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind2 = 0x10069a6d;
// R6GameService.dll code @ 10069a75
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind3 = 0x10069a75;
// R6GameService.dll code @ 10069a83
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind4 = 0x10069a83;
// R6GameService.dll code @ 10069a91
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind5 = 0x10069a91;
// R6GameService.dll code @ 10069aab
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind6 = 0x10069aab;
// R6GameService.dll code @ 10069ac5
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind7 = 0x10069ac5;
// R6GameService.dll code @ 10069acd
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind8 = 0x10069acd;
// R6GameService.dll code @ 10069adb
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind9 = 0x10069adb;
// R6GameService.dll code @ 10069af5
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind10 = 0x10069af5;
// R6GameService.dll code @ 10069b0f
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind11 = 0x10069b0f;
// R6GameService.dll code @ 10069b17
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind12 = 0x10069b17;
// R6GameService.dll code @ 10069b25
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind13 = 0x10069b25;
// R6GameService.dll code @ 10069b3f
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind14 = 0x10069b3f;
// R6GameService.dll code @ 10069b47
constexpr unsigned int InitializeLargeRecordOwnerStateUnwind15 = 0x10069b47;
// R6GameService.dll code @ 10069b55
constexpr unsigned int SelectSRProtocolCtorEH = 0x10069b55;
// R6GameService.dll code @ 10069b60
constexpr unsigned int ReleaseSegmentedWordStorageUnwind1 = 0x10069b60;
// R6GameService.dll code @ 10069b68
constexpr unsigned int SelectSegmentedWordDestroyEH = 0x10069b68;
// R6GameService.dll code @ 10069b80
constexpr unsigned int DestroyLargeRecordOwnerUnwind1 = 0x10069b80;
// R6GameService.dll code @ 10069b88
constexpr unsigned int DestroyLargeRecordOwnerUnwind2 = 0x10069b88;
// R6GameService.dll code @ 10069b96
constexpr unsigned int DestroyLargeRecordOwnerUnwind3 = 0x10069b96;
// R6GameService.dll code @ 10069ba4
constexpr unsigned int DestroyLargeRecordOwnerUnwind4 = 0x10069ba4;
// R6GameService.dll code @ 10069bb2
constexpr unsigned int DestroyLargeRecordOwnerUnwind5 = 0x10069bb2;
// R6GameService.dll code @ 10069bc0
constexpr unsigned int DestroyLargeRecordOwnerUnwind6 = 0x10069bc0;
// R6GameService.dll code @ 10069bce
constexpr unsigned int SelectSRProtocolDestroyEH = 0x10069bce;
// R6GameService.dll code @ 10069be0
constexpr unsigned int SendOwnerWordReportsUnwind1 = 0x10069be0;
// R6GameService.dll code @ 10069bea
constexpr unsigned int SelectOwnerWordReportEH = 0x10069bea;
// R6GameService.dll code @ 10069c00
constexpr unsigned int owned_record_array_supportSharedLifetimeUnwind12 = 0x10069c00;
// R6GameService.dll code @ 10069c08
constexpr unsigned int SelectOwnedRecordVectorDestroyEH = 0x10069c08;
// R6GameService.dll code @ 10069c20
constexpr unsigned int InitializeSegmentedWordsUnwind1 = 0x10069c20;
// R6GameService.dll code @ 10069c2b
constexpr unsigned int InitializeSegmentedWordsUnwind2 = 0x10069c2b;
// R6GameService.dll code @ 10069c36
constexpr unsigned int SelectSegmentedWordCtorEH = 0x10069c36;
// R6GameService.dll code @ 10069c40
constexpr unsigned int ResizeOwnedRecordArrayUnwind1 = 0x10069c40;
// R6GameService.dll code @ 10069c48
constexpr unsigned int ResizeOwnedRecordArrayUnwind2 = 0x10069c48;
// R6GameService.dll code @ 10069c50
constexpr unsigned int SelectArrayResizeEH = 0x10069c50;
// R6GameService.dll code @ 10069c60
constexpr unsigned int owned_record_array_supportSharedLifetimeUnwind1 = 0x10069c60;
// R6GameService.dll code @ 10069c68
constexpr unsigned int SelectRingResetEH = 0x10069c68;
// R6GameService.dll code @ 10069c80
constexpr unsigned int SelectSegmentedWordInitEH = 0x10069c80;
// R6GameService.dll code @ 10069c90
constexpr unsigned int SelectOwnedRecordGrowthEH = 0x10069c90;
// R6GameService.dll code @ 10069ca0
constexpr unsigned int DestroyRecordOwnerStorageUnwind1 = 0x10069ca0;
// R6GameService.dll code @ 10069cae
constexpr unsigned int DestroyRecordOwnerStorageUnwind2 = 0x10069cae;
// R6GameService.dll code @ 10069cbc
constexpr unsigned int DestroyRecordOwnerStorageUnwind3 = 0x10069cbc;
// R6GameService.dll code @ 10069cc4
constexpr unsigned int SelectBasicProtocolDestroyEH = 0x10069cc4;
// R6GameService.dll code @ 10069cd0
constexpr unsigned int FindOrCreateKeyedRecordUnwind1 = 0x10069cd0;
// R6GameService.dll code @ 10069cda
constexpr unsigned int FindOrCreateKeyedRecordUnwind2 = 0x10069cda;
// R6GameService.dll code @ 10069cf4
constexpr unsigned int FindOrCreateKeyedRecordUnwind3 = 0x10069cf4;
// R6GameService.dll code @ 10069cfe
constexpr unsigned int SelectFindOrCreateKeyedRecordEH = 0x10069cfe;
// R6GameService.dll code @ 10069d10
constexpr unsigned int InitializeKeyedRecordUnwind1 = 0x10069d10;
// R6GameService.dll code @ 10069d1b
constexpr unsigned int InitializeKeyedRecordUnwind2 = 0x10069d1b;
// R6GameService.dll code @ 10069d23
constexpr unsigned int InitializeKeyedRecordUnwind3 = 0x10069d23;
// R6GameService.dll code @ 10069d2e
constexpr unsigned int InitializeKeyedRecordUnwind4 = 0x10069d2e;
// R6GameService.dll code @ 10069d39
constexpr unsigned int InitializeKeyedRecordUnwind5 = 0x10069d39;
// R6GameService.dll code @ 10069d44
constexpr unsigned int InitializeKeyedRecordUnwind6 = 0x10069d44;
// R6GameService.dll code @ 10069d4c
constexpr unsigned int InitializeKeyedRecordUnwind7 = 0x10069d4c;
// R6GameService.dll code @ 10069d57
constexpr unsigned int InitializeKeyedRecordUnwind8 = 0x10069d57;
// R6GameService.dll code @ 10069d5f
constexpr unsigned int SelectAssociationConstructionEH = 0x10069d5f;
// R6GameService.dll code @ 10069d70
constexpr unsigned int DestroyKeyedRecordStorageUnwind1 = 0x10069d70;
// R6GameService.dll code @ 10069d7b
constexpr unsigned int DestroyKeyedRecordStorageUnwind2 = 0x10069d7b;
// R6GameService.dll code @ 10069d86
constexpr unsigned int DestroyKeyedRecordStorageUnwind3 = 0x10069d86;
// R6GameService.dll code @ 10069d91
constexpr unsigned int DestroyKeyedRecordStorageUnwind4 = 0x10069d91;
// R6GameService.dll code @ 10069d99
constexpr unsigned int DestroyKeyedRecordStorageUnwind5 = 0x10069d99;
// R6GameService.dll code @ 10069dc0
constexpr unsigned int DestroyKeyedRecordStorageUnwind6 = 0x10069dc0;
// R6GameService.dll code @ 10069dcb
constexpr unsigned int DestroyKeyedRecordStorageUnwind7 = 0x10069dcb;
// R6GameService.dll code @ 10069dd6
constexpr unsigned int SelectKeyedRecordDestructionEH = 0x10069dd6;
// R6GameService.dll code @ 10069de0
constexpr unsigned int ReleaseSegmentedDwordBufferBlocksUnwind1 = 0x10069de0;
// R6GameService.dll code @ 10069de8
constexpr unsigned int SelectSegmentedPointerReleaseEH = 0x10069de8;
// R6GameService.dll code @ 10069e00
constexpr unsigned int DestroyClSegmentPointerDequeUnwind1 = 0x10069e00;
// R6GameService.dll code @ 10069e27
constexpr unsigned int DestroyClSegmentPointerDequeUnwind2 = 0x10069e27;
// R6GameService.dll code @ 10069e2f
constexpr unsigned int SelectClSegmentPointerDequeEH = 0x10069e2f;
// R6GameService.dll code @ 10069e40
constexpr unsigned int InitializeKeyedRecordIndexUnwind1 = 0x10069e40;
// R6GameService.dll code @ 10069e48
constexpr unsigned int InitializeKeyedRecordIndexUnwind2 = 0x10069e48;
// R6GameService.dll code @ 10069e53
constexpr unsigned int InitializeKeyedRecordIndexUnwind3 = 0x10069e53;
// R6GameService.dll code @ 10069e5e
constexpr unsigned int SelectKeyTableConstructionEH = 0x10069e5e;
// R6GameService.dll code @ 10069e70
constexpr unsigned int InitializeSegmentedDwordBufferUnwind1 = 0x10069e70;
// R6GameService.dll code @ 10069e7b
constexpr unsigned int InitializeSegmentedDwordBufferUnwind2 = 0x10069e7b;
// R6GameService.dll code @ 10069e86
constexpr unsigned int SelectDwordStorageConstructionEH = 0x10069e86;
// R6GameService.dll code @ 10069e90
constexpr unsigned int Rehash16BitKeyTableUnwind1 = 0x10069e90;
// R6GameService.dll code @ 10069e98
constexpr unsigned int Rehash16BitKeyTableUnwind2 = 0x10069e98;
// R6GameService.dll code @ 10069ea0
constexpr unsigned int SelectWordKeyRehashEH = 0x10069ea0;
// R6GameService.dll code @ 10069eb0
constexpr unsigned int SelectDwordStorageInitializationEH = 0x10069eb0;
// R6GameService.dll code @ 10069ec0
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind1 = 0x10069ec0;
// R6GameService.dll code @ 10069edd
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind2 = 0x10069edd;
// R6GameService.dll code @ 10069ee5
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind3 = 0x10069ee5;
// R6GameService.dll code @ 10069eed
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind4 = 0x10069eed;
// R6GameService.dll code @ 10069ef8
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind5 = 0x10069ef8;
// R6GameService.dll code @ 10069f12
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind7 = 0x10069f12;
// R6GameService.dll code @ 10069f1a
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwind8 = 0x10069f1a;
// R6GameService.dll code @ 10069f28
constexpr unsigned int SelectProxyConstructionEH = 0x10069f28;
// R6GameService.dll code @ 10069f40
constexpr unsigned int UnwindDerivedTransportBase = 0x10069f40;
// R6GameService.dll code @ 10069f48
constexpr unsigned int UnwindDerivedTransportTextBuffer = 0x10069f48;
// R6GameService.dll code @ 10069f53
constexpr unsigned int UnwindDerivedTransportListStorage = 0x10069f53;
// R6GameService.dll code @ 10069f7a
constexpr unsigned int UnwindDerivedTransportNoOp = 0x10069f7a;
// R6GameService.dll code @ 10069f82
constexpr unsigned int SelectProxyDestructionEH = 0x10069f82;
// R6GameService.dll code @ 10069f90
constexpr unsigned int ConnectAndSendProxyRequestUnwind1 = 0x10069f90;
// R6GameService.dll code @ 10069f9b
constexpr unsigned int ConnectAndSendProxyRequestUnwind2 = 0x10069f9b;
// R6GameService.dll code @ 10069fa6
constexpr unsigned int ConnectAndSendProxyRequestUnwind3 = 0x10069fa6;
// R6GameService.dll code @ 10069fb1
constexpr unsigned int ConnectAndSendProxyRequestUnwind4 = 0x10069fb1;
// R6GameService.dll code @ 10069fbc
constexpr unsigned int ConnectAndSendProxyRequestUnwind5 = 0x10069fbc;
// R6GameService.dll code @ 10069ff2
constexpr unsigned int ConnectAndSendProxyRequestUnwind6 = 0x10069ff2;
// R6GameService.dll code @ 10069ffd
constexpr unsigned int SelectProxySenderEH = 0x10069ffd;
// R6GameService.dll code @ 1006a010
constexpr unsigned int UnwindCallbackListStorage = 0x1006a010;
// R6GameService.dll code @ 1006a037
constexpr unsigned int SelectProxyMessageListEH = 0x1006a037;
// R6GameService.dll code @ 1006a050
constexpr unsigned int DestroyPerNodeLinkedListContainerUnwind1 = 0x1006a050;
// R6GameService.dll code @ 1006a058
constexpr unsigned int DestroyPerNodeLinkedListContainerUnwind2 = 0x1006a058;
// R6GameService.dll code @ 1006a07f
constexpr unsigned int SelectProxyMessageEH = 0x1006a07f;
// R6GameService.dll code @ 1006a090
constexpr unsigned int WriteServiceLogMessageUnwind1 = 0x1006a090;
// R6GameService.dll code @ 1006a09b
constexpr unsigned int SelectServiceLogMessageEH = 0x1006a09b;
// R6GameService.dll code @ 1006a0b0
constexpr unsigned int InitializeGlobalWideOutputStream = 0x1006a0b0;
// R6GameService.dll code @ 1006a0d0
constexpr unsigned int InitializeUeviLPatchServiceClassMetadata = 0x1006a0d0;
// R6GameService.dll code @ 1006a160
constexpr unsigned int InitializeAutoclassUeviLPatchService = 0x1006a160;
// R6GameService.dll code @ 1006a170
constexpr unsigned int InitializeUR6GSServersClassMetadata = 0x1006a170;
// R6GameService.dll code @ 1006a1f0
constexpr unsigned int InitializeAutoclassUR6GSServers = 0x1006a1f0;
// R6GameService.dll code @ 1006a200
constexpr unsigned int InitializeUR6LanServersClassMetadata = 0x1006a200;
// R6GameService.dll code @ 1006a280
constexpr unsigned int InitializeAutoclassUR6LanServers = 0x1006a280;
// R6GameService.dll code @ 1006a290
constexpr unsigned int InitializeUR6ServerListClassMetadata = 0x1006a290;
// R6GameService.dll code @ 1006a320
constexpr unsigned int InitializeAutoclassUR6ServerList = 0x1006a320;
// R6GameService.dll code @ 1006a330
constexpr unsigned int InitializeUR6ModGSInfoClassMetadata = 0x1006a330;
// R6GameService.dll code @ 1006a3b0
constexpr unsigned int InitializeGlobalPointer = 0x1006a3b0;
// R6GameService.dll code @ 1006a3c0
constexpr unsigned int RegisterUR6ModGSInfo_execNativeInitModInfo = 0x1006a3c0;
// R6GameService.dll code @ 1006a3e0
constexpr unsigned int RegisterUR6ServerList_execGetDisplayListSize = 0x1006a3e0;
// R6GameService.dll code @ 1006a400
constexpr unsigned int RegisterUR6ServerList_execNativeGetMaxPlayers = 0x1006a400;
// R6GameService.dll code @ 1006a420
constexpr unsigned int RegisterUR6ServerList_execNativeGetOwnSvrPort = 0x1006a420;
// R6GameService.dll code @ 1006a440
constexpr unsigned int RegisterUR6ServerList_execSortServers = 0x1006a440;
// R6GameService.dll code @ 1006a460
constexpr unsigned int RegisterUR6ServerList_execNativeGetMilliSeconds = 0x1006a460;
// R6GameService.dll code @ 1006a480
constexpr unsigned int RegisterUR6ServerList_execNativeGetPingTimeOut = 0x1006a480;
// R6GameService.dll code @ 1006a4a0
constexpr unsigned int RegisterUR6ServerList_execNativeGetPingTime = 0x1006a4a0;
// R6GameService.dll code @ 1006a4c0
constexpr unsigned int RegisterUR6ServerList_execNativeUpdateFavorites = 0x1006a4c0;
// R6GameService.dll code @ 1006a4e0
constexpr unsigned int RegisterUR6ServerList_execNativeInitFavorites = 0x1006a4e0;
// R6GameService.dll code @ 1006a500
constexpr unsigned int RegisterUR6GSServers_execNativeMSCLientJoinServer = 0x1006a500;
// R6GameService.dll code @ 1006a520
constexpr unsigned int RegisterUR6GSServers_execNativeMSClientReqAltInfo = 0x1006a520;
// R6GameService.dll code @ 1006a540
constexpr unsigned int RegisterUR6GSServers_execEnterCDKey = 0x1006a540;
// R6GameService.dll code @ 1006a560
constexpr unsigned int RegisterUR6GSServers_execHandleAnyLobbyConnectionFail = 0x1006a560;
// R6GameService.dll code @ 1006a580
constexpr unsigned int RegisterUR6GSServers_execNativeProcessIcmpPing = 0x1006a580;
// R6GameService.dll code @ 1006a5a0
constexpr unsigned int RegisterUR6GSServers_execNativeLogOutServer = 0x1006a5a0;
// R6GameService.dll code @ 1006a5c0
constexpr unsigned int RegisterUR6GSServers_execNativeUpdateServer = 0x1006a5c0;
// R6GameService.dll code @ 1006a5e0
constexpr unsigned int RegisterUR6GSServers_execNativeIsGSReadyToChangeMod = 0x1006a5e0;
// R6GameService.dll code @ 1006a600
constexpr unsigned int RegisterUR6GSServers_execNativeIsWaitingForGSInit = 0x1006a600;
// R6GameService.dll code @ 1006a620
constexpr unsigned int RegisterUR6GSServers_execNativeIsRouterDisconnect = 0x1006a620;
// R6GameService.dll code @ 1006a640
constexpr unsigned int RegisterUR6GSServers_execSetLastServerQueried = 0x1006a640;
// R6GameService.dll code @ 1006a660
constexpr unsigned int RegisterUR6GSServers_execNativeSetMatchResult = 0x1006a660;
// R6GameService.dll code @ 1006a680
constexpr unsigned int RegisterUR6GSServers_execGetMaxUbiServerNameSize = 0x1006a680;
// R6GameService.dll code @ 1006a6a0
constexpr unsigned int RegisterUR6GSServers_execNativeGetMSClientInitialized = 0x1006a6a0;
// R6GameService.dll code @ 1006a6c0
constexpr unsigned int RegisterUR6GSServers_execNativeGetSeconds = 0x1006a6c0;
// R6GameService.dll code @ 1006a6e0
constexpr unsigned int RegisterUR6GSServers_execStopRefreshServers = 0x1006a6e0;
// R6GameService.dll code @ 1006a700
constexpr unsigned int RegisterUR6GSServers_execIsRefreshServersInProgress = 0x1006a700;
// R6GameService.dll code @ 1006a720
constexpr unsigned int RegisterUR6GSServers_execRefreshOneServer = 0x1006a720;
// R6GameService.dll code @ 1006a740
constexpr unsigned int RegisterUR6GSServers_execRefreshServers = 0x1006a740;
// R6GameService.dll code @ 1006a760
constexpr unsigned int RegisterUR6GSServers_execUnInitializeMSClient = 0x1006a760;
// R6GameService.dll code @ 1006a780
constexpr unsigned int RegisterUR6GSServers_execInitializeMSClient = 0x1006a780;
// R6GameService.dll code @ 1006a7a0
constexpr unsigned int RegisterUR6GSServers_execInitGSCDKey = 0x1006a7a0;
// R6GameService.dll code @ 1006a7c0
constexpr unsigned int RegisterUR6GSServers_execInitialize = 0x1006a7c0;
// R6GameService.dll code @ 1006a7e0
constexpr unsigned int RegisterUeviLPatchService_execGetState = 0x1006a7e0;
// R6GameService.dll code @ 1006a800
constexpr unsigned int RegisterUeviLPatchService_execCanRunUpdateService = 0x1006a800;
// R6GameService.dll code @ 1006a820
constexpr unsigned int RegisterUeviLPatchService_execGetExitCause = 0x1006a820;
// R6GameService.dll code @ 1006a840
constexpr unsigned int RegisterUeviLPatchService_execAbortPatchService = 0x1006a840;
// R6GameService.dll code @ 1006a860
constexpr unsigned int RegisterUeviLPatchService_execGetDownloadProgress = 0x1006a860;
// R6GameService.dll code @ 1006a880
constexpr unsigned int RegisterUeviLPatchService_execStartPatch = 0x1006a880;
// R6GameService.dll code @ 1006a8a0
constexpr unsigned int InitializeGlobalEventNames = 0x1006a8a0;
// R6GameService.dll code @ 1006a8b0
constexpr unsigned int InitializeGlobalArray = 0x1006a8b0;
// R6GameService.dll code @ 1006a8d0
constexpr unsigned int global_state_InitializeGlobalArray = 0x1006a8d0;
// R6GameService.dll code @ 1006a8f0
constexpr unsigned int global_state_InitializeGlobalArray2 = 0x1006a8f0;
// R6GameService.dll code @ 1006a910
constexpr unsigned int global_state_InitializeGlobalArray3 = 0x1006a910;
// R6GameService.dll code @ 1006a930
constexpr unsigned int global_state_InitializeGlobalArray4 = 0x1006a930;
// R6GameService.dll code @ 1006a950
constexpr unsigned int InitializeLastServerQueriedAddress = 0x1006a950;
// R6GameService.dll code @ 1006a970
constexpr unsigned int InitializeGlobalString = 0x1006a970;
// R6GameService.dll code @ 1006a990
constexpr unsigned int global_state_InitializeGlobalString = 0x1006a990;
// R6GameService.dll code @ 1006a9b0
constexpr unsigned int global_state_InitializeGlobalString2 = 0x1006a9b0;
// R6GameService.dll code @ 1006a9d0
constexpr unsigned int InitializeGlobalBstr = 0x1006a9d0;
// R6GameService.dll code @ 1006aa00
constexpr unsigned int InitializeGlobalPointerSlot = 0x1006aa00;
// R6GameService.dll code @ 1006aa20
constexpr unsigned int global_state_InitializeGlobalArray5 = 0x1006aa20;
// R6GameService.dll code @ 1006aa40
constexpr unsigned int global_state_InitializeGlobalArray6 = 0x1006aa40;
// R6GameService.dll code @ 1006aa60
constexpr unsigned int global_state_InitializeGlobalArray7 = 0x1006aa60;
// R6GameService.dll code @ 1006aa80
constexpr unsigned int global_state_InitializeGlobalArray8 = 0x1006aa80;
// R6GameService.dll code @ 1006aaa0
constexpr unsigned int global_state_InitializeGlobalArray9 = 0x1006aaa0;
// R6GameService.dll code @ 1006aac0
constexpr unsigned int global_state_InitializeGlobalString3 = 0x1006aac0;
// R6GameService.dll code @ 1006aae0
constexpr unsigned int global_state_InitializeGlobalString4 = 0x1006aae0;
// R6GameService.dll code @ 1006ab00
constexpr unsigned int global_state_InitializeGlobalString5 = 0x1006ab00;
// R6GameService.dll code @ 1006ab20
constexpr unsigned int global_state_InitializeGlobalString6 = 0x1006ab20;
// R6GameService.dll code @ 1006ab40
constexpr unsigned int global_state_InitializeGlobalString7 = 0x1006ab40;
// R6GameService.dll code @ 1006ab60
constexpr unsigned int global_state_InitializeGlobalString8 = 0x1006ab60;
// R6GameService.dll code @ 1006ab80
constexpr unsigned int global_state_InitializeGlobalString9 = 0x1006ab80;
// R6GameService.dll code @ 1006aba0
constexpr unsigned int global_state_InitializeGlobalArray10 = 0x1006aba0;
// R6GameService.dll code @ 1006abc0
constexpr unsigned int global_state_InitializeGlobalString10 = 0x1006abc0;
// R6GameService.dll code @ 1006abe0
constexpr unsigned int InitializeGlobalWideStreamReferences = 0x1006abe0;
// R6GameService.dll code @ 1006abf0
constexpr unsigned int global_state_InitializeGlobalWideStreamReferences = 0x1006abf0;
// R6GameService.dll code @ 1006abfa
constexpr unsigned int InitializeGlobalAtlBaseModule = 0x1006abfa;
// R6GameService.dll code @ 1006ac10
constexpr unsigned int DestroyUeviLPatchServiceClassMetadata = 0x1006ac10;
// R6GameService.dll code @ 1006ac20
constexpr unsigned int DestroyGlobalWideStringStream = 0x1006ac20;
// R6GameService.dll code @ 1006ac40
constexpr unsigned int DestroyUR6GSServersClassMetadata = 0x1006ac40;
// R6GameService.dll code @ 1006ac50
constexpr unsigned int DestroyUR6LanServersClassMetadata = 0x1006ac50;
// R6GameService.dll code @ 1006ac60
constexpr unsigned int DestroyUR6ServerListClassMetadata = 0x1006ac60;
// R6GameService.dll code @ 1006ac70
constexpr unsigned int DestroyUR6ModGSInfoClassMetadata = 0x1006ac70;
// R6GameService.dll code @ 1006ac80
constexpr unsigned int DestroyLastServerQueriedAddress = 0x1006ac80;
// R6GameService.dll code @ 1006ac90
constexpr unsigned int DestroyGlobalString = 0x1006ac90;
// R6GameService.dll code @ 1006aca0
constexpr unsigned int global_state_DestroyGlobalString = 0x1006aca0;
// R6GameService.dll code @ 1006acb0
constexpr unsigned int global_state_DestroyGlobalString2 = 0x1006acb0;
// R6GameService.dll code @ 1006acc0
constexpr unsigned int ForwardGlobalWordToOleautOrdinal6 = 0x1006acc0;
// R6GameService.dll code @ 1006acd0
constexpr unsigned int DestroyGlobalObject = 0x1006acd0;
// R6GameService.dll code @ 1006ace0
constexpr unsigned int DestroyGlobalArray = 0x1006ace0;
// R6GameService.dll code @ 1006acf0
constexpr unsigned int ReleaseGlobalFirstWordObject = 0x1006acf0;
// R6GameService.dll code @ 1006ad00
constexpr unsigned int global_state_DestroyGlobalArray = 0x1006ad00;
// R6GameService.dll code @ 1006ad10
constexpr unsigned int global_state_DestroyGlobalArray2 = 0x1006ad10;
// R6GameService.dll code @ 1006ad20
constexpr unsigned int global_state_DestroyGlobalArray3 = 0x1006ad20;
// R6GameService.dll code @ 1006ad30
constexpr unsigned int global_state_DestroyGlobalArray4 = 0x1006ad30;
// R6GameService.dll code @ 1006ad40
constexpr unsigned int global_state_DestroyGlobalString3 = 0x1006ad40;
// R6GameService.dll code @ 1006ad50
constexpr unsigned int global_state_DestroyGlobalString4 = 0x1006ad50;
// R6GameService.dll code @ 1006ad60
constexpr unsigned int global_state_DestroyGlobalString5 = 0x1006ad60;
// R6GameService.dll code @ 1006ad70
constexpr unsigned int global_state_DestroyGlobalString6 = 0x1006ad70;
// R6GameService.dll code @ 1006ad80
constexpr unsigned int global_state_DestroyGlobalString7 = 0x1006ad80;
// R6GameService.dll code @ 1006ad90
constexpr unsigned int global_state_DestroyGlobalString8 = 0x1006ad90;
// R6GameService.dll code @ 1006ada0
constexpr unsigned int global_state_DestroyGlobalArray5 = 0x1006ada0;
// R6GameService.dll code @ 1006adb0
constexpr unsigned int global_state_DestroyGlobalArray6 = 0x1006adb0;
// R6GameService.dll code @ 1006adc0
constexpr unsigned int global_state_DestroyGlobalArray7 = 0x1006adc0;
// R6GameService.dll code @ 1006add0
constexpr unsigned int global_state_DestroyGlobalArray8 = 0x1006add0;
// R6GameService.dll code @ 1006ade0
constexpr unsigned int global_state_DestroyGlobalString9 = 0x1006ade0;
// R6GameService.dll code @ 1006adf0
constexpr unsigned int global_state_DestroyGlobalString10 = 0x1006adf0;
// R6GameService.dll code @ 1006ae00
constexpr unsigned int global_state_DestroyGlobalArray9 = 0x1006ae00;
// R6GameService.dll code @ 1006ae0a
constexpr unsigned int DestroyGlobalAtlBaseModule = 0x1006ae0a;
// R6GameService.dll import @ 1006b000
constexpr unsigned int ADVAPI32_RegQueryValueExASlot = 0x1006b000;
// R6GameService.dll import @ 1006b004
constexpr unsigned int ADVAPI32_RegOpenKeyExASlot = 0x1006b004;
// R6GameService.dll import @ 1006b00c
constexpr unsigned int Core__GErrorSlot = 0x1006b00c;
// R6GameService.dll import @ 1006b010
constexpr unsigned int Core_UObject_NetDirtySlot = 0x1006b010;
// R6GameService.dll import @ 1006b014
constexpr unsigned int Core_UObject_GetPropertiesSizeSlot = 0x1006b014;
// R6GameService.dll import @ 1006b018
constexpr unsigned int Core_UObject_IsPendingDeleteSlot = 0x1006b018;
// R6GameService.dll import @ 1006b01c
constexpr unsigned int Core_UObject_LanguageChangeSlot = 0x1006b01c;
// R6GameService.dll import @ 1006b020
constexpr unsigned int Core_UObject_RegisterSlot = 0x1006b020;
// R6GameService.dll import @ 1006b024
constexpr unsigned int Core_UObject_ScriptConsoleExecSlot = 0x1006b024;
// R6GameService.dll import @ 1006b028
constexpr unsigned int Core_UObject_CallFunctionSlot = 0x1006b028;
// R6GameService.dll import @ 1006b02c
constexpr unsigned int Core_UObject_PostEditChangeSlot = 0x1006b02c;
// R6GameService.dll import @ 1006b030
constexpr unsigned int Core_UObject_ShutdownAfterErrorSlot = 0x1006b030;
// R6GameService.dll import @ 1006b034
constexpr unsigned int Core_UObject_InitExecutionSlot = 0x1006b034;
// R6GameService.dll import @ 1006b038
constexpr unsigned int Core_UObject_GotoLabelSlot = 0x1006b038;
// R6GameService.dll import @ 1006b03c
constexpr unsigned int Core_UObject_GotoStateSlot = 0x1006b03c;
// R6GameService.dll import @ 1006b040
constexpr unsigned int Core_UObject_IsPendingKillSlot = 0x1006b040;
// R6GameService.dll import @ 1006b044
constexpr unsigned int Core_UObject_SerializeSlot = 0x1006b044;
// R6GameService.dll import @ 1006b048
constexpr unsigned int Core_UObject_DestroySlot = 0x1006b048;
// R6GameService.dll import @ 1006b04c
constexpr unsigned int Core_UObject_PostLoadSlot = 0x1006b04c;
// R6GameService.dll import @ 1006b050
constexpr unsigned int Core_UObject_ModifySlot = 0x1006b050;
// R6GameService.dll import @ 1006b054
constexpr unsigned int Core_UObject_ProcessRemoteFunctionSlot = 0x1006b054;
// R6GameService.dll import @ 1006b058
constexpr unsigned int Core_UObject_ProcessStateSlot = 0x1006b058;
// R6GameService.dll import @ 1006b05c
constexpr unsigned int Core_UObject_ProcessDelegateSlot = 0x1006b05c;
// R6GameService.dll import @ 1006b060
constexpr unsigned int Core_UObject_ProcessEventSlot = 0x1006b060;
// R6GameService.dll import @ 1006b064
constexpr unsigned int Core_UObject_ReleaseSlot = 0x1006b064;
// R6GameService.dll import @ 1006b068
constexpr unsigned int Core_UObject_AddRefSlot = 0x1006b068;
// R6GameService.dll import @ 1006b06c
constexpr unsigned int Core_UObject_QueryInterfaceSlot = 0x1006b06c;
// R6GameService.dll import @ 1006b070
constexpr unsigned int Core__DestroyUObjectSlot = 0x1006b070;
// R6GameService.dll import @ 1006b074
constexpr unsigned int Core_UObject_ConditionalDestroySlot = 0x1006b074;
// R6GameService.dll import @ 1006b078
constexpr unsigned int Core__ConstructUObjectSlot = 0x1006b078;
// R6GameService.dll import @ 1006b07c
constexpr unsigned int Core__ConstructUObjectSlot2 = 0x1006b07c;
// R6GameService.dll import @ 1006b080
constexpr unsigned int Core__4UObjectSlot = 0x1006b080;
// R6GameService.dll import @ 1006b084
constexpr unsigned int Core__3UObjectSlot = 0x1006b084;
// R6GameService.dll import @ 1006b088
constexpr unsigned int Core_UObject_FindFunctionCheckedSlot = 0x1006b088;
// R6GameService.dll import @ 1006b08c
constexpr unsigned int Core__ConstructFStringSlot = 0x1006b08c;
// R6GameService.dll import @ 1006b090
constexpr unsigned int Core__DestroyFStringSlot = 0x1006b090;
// R6GameService.dll import @ 1006b094
constexpr unsigned int Core__DestroyFStringNoInitSlot = 0x1006b094;
// R6GameService.dll import @ 1006b098
constexpr unsigned int Core__ConstructFStringNoInitSlot = 0x1006b098;
// R6GameService.dll import @ 1006b09c
constexpr unsigned int Core__ConstructFStringNoInitSlot2 = 0x1006b09c;
// R6GameService.dll import @ 1006b0a0
constexpr unsigned int Core__4FStringNoInitSlot = 0x1006b0a0;
// R6GameService.dll import @ 1006b0a4
constexpr unsigned int Core__appUnwindfSlot = 0x1006b0a4;
// R6GameService.dll import @ 1006b0a8
constexpr unsigned int Core__ConstructFStringSlot2 = 0x1006b0a8;
// R6GameService.dll import @ 1006b0ac
constexpr unsigned int Core__DFStringSlot = 0x1006b0ac;
// R6GameService.dll import @ 1006b0b0
constexpr unsigned int Core_FArray_RemoveSlot = 0x1006b0b0;
// R6GameService.dll import @ 1006b0b4
constexpr unsigned int Core__appFailAssertSlot = 0x1006b0b4;
// R6GameService.dll import @ 1006b0b8
constexpr unsigned int Core_FArray_ReallocSlot = 0x1006b0b8;
// R6GameService.dll import @ 1006b0bc
constexpr unsigned int Core_UObject_StaticAllocateObjectSlot = 0x1006b0bc;
// R6GameService.dll import @ 1006b0c0
constexpr unsigned int Core__ConstructFStringSlot3 = 0x1006b0c0;
// R6GameService.dll import @ 1006b0c4
constexpr unsigned int Core__4FStringSlot = 0x1006b0c4;
// R6GameService.dll import @ 1006b0c8
constexpr unsigned int Core__DestroyFArraySlot = 0x1006b0c8;
// R6GameService.dll import @ 1006b0cc
constexpr unsigned int Core_UObject_GetFullNameSlot = 0x1006b0cc;
// R6GameService.dll import @ 1006b0d0
constexpr unsigned int Core__GPropertySlot = 0x1006b0d0;
// R6GameService.dll import @ 1006b0d4
constexpr unsigned int Core__GPropObjectSlot = 0x1006b0d4;
// R6GameService.dll import @ 1006b0d8
constexpr unsigned int Core__GNativesSlot = 0x1006b0d8;
// R6GameService.dll import @ 1006b0dc
constexpr unsigned int Core__GPropAddrSlot = 0x1006b0dc;
// R6GameService.dll import @ 1006b0e0
constexpr unsigned int Core__ConstructUClassSlot = 0x1006b0e0;
// R6GameService.dll import @ 1006b0e4
constexpr unsigned int Core_UObject_StaticConfigNameSlot = 0x1006b0e4;
// R6GameService.dll import @ 1006b0e8
constexpr unsigned int Core_UObject_PrivateStaticClassSlot = 0x1006b0e8;
// R6GameService.dll import @ 1006b0ec
constexpr unsigned int Core_UObject_StaticConstructorSlot = 0x1006b0ec;
// R6GameService.dll import @ 1006b0f0
constexpr unsigned int Core__DestroyUClassSlot = 0x1006b0f0;
// R6GameService.dll import @ 1006b0f4
constexpr unsigned int Core__GSecondsPerCycleSlot = 0x1006b0f4;
// R6GameService.dll import @ 1006b0f8
constexpr unsigned int Core__ConstructFNameSlot = 0x1006b0f8;
// R6GameService.dll import @ 1006b0fc
constexpr unsigned int Core__GLogSlot = 0x1006b0fc;
// R6GameService.dll import @ 1006b100
constexpr unsigned int Core_FOutputDevice_LogfSlot = 0x1006b100;
// R6GameService.dll import @ 1006b104
constexpr unsigned int Core__appStricmpSlot = 0x1006b104;
// R6GameService.dll import @ 1006b108
constexpr unsigned int Core_FString_CapsSlot = 0x1006b108;
// R6GameService.dll import @ 1006b10c
constexpr unsigned int Core__4FStringSlot2 = 0x1006b10c;
// R6GameService.dll import @ 1006b110
constexpr unsigned int Core__appToAnsiSlot = 0x1006b110;
// R6GameService.dll import @ 1006b114
constexpr unsigned int Core_UObject_SaveConfigSlot = 0x1006b114;
// R6GameService.dll import @ 1006b118
constexpr unsigned int Core__4FStringNoInitSlot2 = 0x1006b118;
// R6GameService.dll import @ 1006b11c
constexpr unsigned int Core__appFromAnsiSlot = 0x1006b11c;
// R6GameService.dll import @ 1006b120
constexpr unsigned int Core_FArray_AddZeroedSlot = 0x1006b120;
// R6GameService.dll import @ 1006b124
constexpr unsigned int Core__appAtoiSlot = 0x1006b124;
// R6GameService.dll import @ 1006b128
constexpr unsigned int Core__appSprintfSlot = 0x1006b128;
// R6GameService.dll import @ 1006b12c
constexpr unsigned int Core__appStrcmpSlot = 0x1006b12c;
// R6GameService.dll import @ 1006b130
constexpr unsigned int Core__GConfigSlot = 0x1006b130;
// R6GameService.dll import @ 1006b134
constexpr unsigned int Core__winToUNICODESlot = 0x1006b134;
// R6GameService.dll import @ 1006b138
constexpr unsigned int Core__winGetSizeUNICODESlot = 0x1006b138;
// R6GameService.dll import @ 1006b13c
constexpr unsigned int Core__8FStringSlot = 0x1006b13c;
// R6GameService.dll import @ 1006b140
constexpr unsigned int Core__YFStringSlot = 0x1006b140;
// R6GameService.dll import @ 1006b144
constexpr unsigned int Core_FString_PrintfSlot = 0x1006b144;
// R6GameService.dll import @ 1006b148
constexpr unsigned int Core__YFStringSlot2 = 0x1006b148;
// R6GameService.dll import @ 1006b14c
constexpr unsigned int Core__4FStringNoInitSlot3 = 0x1006b14c;
// R6GameService.dll import @ 1006b150
constexpr unsigned int Core_UClass_GetDefaultActorSlot = 0x1006b150;
// R6GameService.dll import @ 1006b154
constexpr unsigned int Core__GRegisterNativeSlot = 0x1006b154;
// R6GameService.dll import @ 1006b158
constexpr unsigned int Core__RegGetSlot = 0x1006b158;
// R6GameService.dll import @ 1006b15c
constexpr unsigned int Core__RegSetSlot = 0x1006b15c;
// R6GameService.dll import @ 1006b160
constexpr unsigned int Core__9FStringSlot = 0x1006b160;
// R6GameService.dll import @ 1006b164
constexpr unsigned int Core_FString_LeftSlot = 0x1006b164;
// R6GameService.dll import @ 1006b168
constexpr unsigned int Core_FString_InStrSlot = 0x1006b168;
// R6GameService.dll import @ 1006b16c
constexpr unsigned int Core_UObject_IsASlot = 0x1006b16c;
// R6GameService.dll import @ 1006b170
constexpr unsigned int Core__GMallocSlot = 0x1006b170;
// R6GameService.dll import @ 1006b174
constexpr unsigned int Core_FArray_AddSlot = 0x1006b174;
// R6GameService.dll import @ 1006b17c
constexpr unsigned int Engine__GR6GameManagerSlot = 0x1006b17c;
// R6GameService.dll import @ 1006b180
constexpr unsigned int Engine_APlayerController_PrivateStaticClassSlot = 0x1006b180;
// R6GameService.dll import @ 1006b184
constexpr unsigned int Engine_UR6ModMgr_eventIsRavenShieldSlot = 0x1006b184;
// R6GameService.dll import @ 1006b188
constexpr unsigned int Engine_UR6ModMgr_eventGetGameTypeIndexSlot = 0x1006b188;
// R6GameService.dll import @ 1006b18c
constexpr unsigned int Engine_UR6ModMgr_eventGetModNameSlot = 0x1006b18c;
// R6GameService.dll import @ 1006b190
constexpr unsigned int Engine_UR6ModMgr_eventGetModKeywordSlot = 0x1006b190;
// R6GameService.dll import @ 1006b194
constexpr unsigned int Engine_UR6ModMgr_eventGetGameTypeNameSlot = 0x1006b194;
// R6GameService.dll import @ 1006b198
constexpr unsigned int Engine_AActor_NativeStartedByGSClientSlot = 0x1006b198;
// R6GameService.dll import @ 1006b19c
constexpr unsigned int Engine_AActor_PrivateStaticClassSlot = 0x1006b19c;
// R6GameService.dll import @ 1006b1a0
constexpr unsigned int Engine_AActor_GlobalIDToStringSlot = 0x1006b1a0;
// R6GameService.dll import @ 1006b1a4
constexpr unsigned int Engine_UNetConnection_PrivateStaticClassSlot = 0x1006b1a4;
// R6GameService.dll import @ 1006b1a8
constexpr unsigned int Engine_UViewport_PrivateStaticClassSlot = 0x1006b1a8;
// R6GameService.dll import @ 1006b1ac
constexpr unsigned int Engine_APlayerController_eventClientPBKickedOutMessageSlot = 0x1006b1ac;
// R6GameService.dll import @ 1006b1b0
constexpr unsigned int Engine_APlayerController_GetPlayerNetworkAddressSlot = 0x1006b1b0;
// R6GameService.dll import @ 1006b1b4
constexpr unsigned int Engine__GModMgrSlot = 0x1006b1b4;
// R6GameService.dll import @ 1006b1b8
constexpr unsigned int Engine__getGameShutDownSlot = 0x1006b1b8;
// R6GameService.dll import @ 1006b1bc
constexpr unsigned int Engine_UR6AbstractGameManager_eventGMProcessMsgSlot = 0x1006b1bc;
// R6GameService.dll import @ 1006b1c4
constexpr unsigned int KERNEL32_GetSystemTimeAsFileTimeSlot = 0x1006b1c4;
// R6GameService.dll import @ 1006b1c8
constexpr unsigned int KERNEL32_GetCurrentThreadIdSlot = 0x1006b1c8;
// R6GameService.dll import @ 1006b1cc
constexpr unsigned int KERNEL32_ExitProcessSlot = 0x1006b1cc;
// R6GameService.dll import @ 1006b1d0
constexpr unsigned int KERNEL32_ReleaseMutexSlot = 0x1006b1d0;
// R6GameService.dll import @ 1006b1d4
constexpr unsigned int KERNEL32_CreateMutexASlot = 0x1006b1d4;
// R6GameService.dll import @ 1006b1d8
constexpr unsigned int KERNEL32_CreateEventWSlot = 0x1006b1d8;
// R6GameService.dll import @ 1006b1dc
constexpr unsigned int KERNEL32_WaitForSingleObjectSlot = 0x1006b1dc;
// R6GameService.dll import @ 1006b1e0
constexpr unsigned int KERNEL32_FormatMessageWSlot = 0x1006b1e0;
// R6GameService.dll import @ 1006b1e4
constexpr unsigned int KERNEL32_QueryPerformanceCounterSlot = 0x1006b1e4;
// R6GameService.dll import @ 1006b1e8
constexpr unsigned int KERNEL32_QueryPerformanceFrequencySlot = 0x1006b1e8;
// R6GameService.dll import @ 1006b1ec
constexpr unsigned int KERNEL32_LoadLibraryASlot = 0x1006b1ec;
// R6GameService.dll import @ 1006b1f0
constexpr unsigned int KERNEL32_GetProcAddressSlot = 0x1006b1f0;
// R6GameService.dll import @ 1006b1f4
constexpr unsigned int KERNEL32_FreeLibrarySlot = 0x1006b1f4;
// R6GameService.dll import @ 1006b1f8
constexpr unsigned int KERNEL32_CreateProcessWSlot = 0x1006b1f8;
// R6GameService.dll import @ 1006b1fc
constexpr unsigned int KERNEL32_SleepSlot = 0x1006b1fc;
// R6GameService.dll import @ 1006b200
constexpr unsigned int KERNEL32_GetCurrentProcessIdSlot = 0x1006b200;
// R6GameService.dll import @ 1006b204
constexpr unsigned int KERNEL32_GetPrivateProfileStringASlot = 0x1006b204;
// R6GameService.dll import @ 1006b208
constexpr unsigned int KERNEL32_MultiByteToWideCharSlot = 0x1006b208;
// R6GameService.dll import @ 1006b20c
constexpr unsigned int KERNEL32_GetTickCountSlot = 0x1006b20c;
// R6GameService.dll import @ 1006b210
constexpr unsigned int KERNEL32_OpenEventASlot = 0x1006b210;
// R6GameService.dll import @ 1006b214
constexpr unsigned int KERNEL32_CloseHandleSlot = 0x1006b214;
// R6GameService.dll import @ 1006b218
constexpr unsigned int KERNEL32_DeleteCriticalSectionSlot = 0x1006b218;
// R6GameService.dll import @ 1006b21c
constexpr unsigned int KERNEL32_InitializeCriticalSectionSlot = 0x1006b21c;
// R6GameService.dll import @ 1006b220
constexpr unsigned int KERNEL32_GetVersionExWSlot = 0x1006b220;
// R6GameService.dll import @ 1006b224
constexpr unsigned int KERNEL32_GetThreadLocaleSlot = 0x1006b224;
// R6GameService.dll import @ 1006b228
constexpr unsigned int KERNEL32_GetLocaleInfoASlot = 0x1006b228;
// R6GameService.dll import @ 1006b22c
constexpr unsigned int KERNEL32_GetACPSlot = 0x1006b22c;
// R6GameService.dll import @ 1006b230
constexpr unsigned int KERNEL32_InterlockedExchangeSlot = 0x1006b230;
// R6GameService.dll import @ 1006b234
constexpr unsigned int KERNEL32_GetLastErrorSlot = 0x1006b234;
// R6GameService.dll import @ 1006b238
constexpr unsigned int KERNEL32_GetVersionExASlot = 0x1006b238;
// R6GameService.dll import @ 1006b23c
constexpr unsigned int KERNEL32_CreateProcessASlot = 0x1006b23c;
// R6GameService.dll import @ 1006b240
constexpr unsigned int KERNEL32_WideCharToMultiByteSlot = 0x1006b240;
// R6GameService.dll import @ 1006b244
constexpr unsigned int KERNEL32_lstrlenASlot = 0x1006b244;
// R6GameService.dll import @ 1006b248
constexpr unsigned int KERNEL32_lstrlenWSlot = 0x1006b248;
// R6GameService.dll import @ 1006b24c
constexpr unsigned int KERNEL32_GetCurrentDirectoryWSlot = 0x1006b24c;
// R6GameService.dll import @ 1006b250
constexpr unsigned int KERNEL32_GetCurrentDirectoryASlot = 0x1006b250;
// R6GameService.dll import @ 1006b254
constexpr unsigned int KERNEL32_GetVersionSlot = 0x1006b254;
// R6GameService.dll import @ 1006b25c
constexpr unsigned int MSVCP71__basic_stringbuf_strSlot = 0x1006b25c;
// R6GameService.dll import @ 1006b260
constexpr unsigned int MSVCP71__basic_stringbuf_strSlot2 = 0x1006b260;
// R6GameService.dll import @ 1006b264
constexpr unsigned int MSVCP71_std_endlSlot = 0x1006b264;
// R6GameService.dll import @ 1006b268
constexpr unsigned int MSVCP71_GU_char_traits_6_basic_ostreamSlot = 0x1006b268;
// R6GameService.dll import @ 1006b26c
constexpr unsigned int MSVCP71__ctype_widenSlot = 0x1006b26c;
// R6GameService.dll import @ 1006b270
constexpr unsigned int MSVCP71_std__7ios_baseSlot = 0x1006b270;
// R6GameService.dll import @ 1006b274
constexpr unsigned int MSVCP71_GU_char_traits__7_basic_iosSlot = 0x1006b274;
// R6GameService.dll import @ 1006b278
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_ostreamSlot = 0x1006b278;
// R6GameService.dll import @ 1006b27c
constexpr unsigned int MSVCP71_GU_char_traits_Destroy_basic_iosSlot = 0x1006b27c;
// R6GameService.dll import @ 1006b280
constexpr unsigned int MSVCP71_GU_char_traits__7_basic_ostreamSlot = 0x1006b280;
// R6GameService.dll import @ 1006b284
constexpr unsigned int MSVCP71_std_uncaught_exceptionSlot = 0x1006b284;
// R6GameService.dll import @ 1006b288
constexpr unsigned int MSVCP71__basic_ostream__OsfxSlot = 0x1006b288;
// R6GameService.dll import @ 1006b28c
constexpr unsigned int MSVCP71__basic_ostream_flushSlot = 0x1006b28c;
// R6GameService.dll import @ 1006b290
constexpr unsigned int MSVCP71_GU_char_traits_Y_basic_stringSlot = 0x1006b290;
// R6GameService.dll import @ 1006b294
constexpr unsigned int MSVCP71_GU_char_traits_Y_basic_stringSlot2 = 0x1006b294;
// R6GameService.dll import @ 1006b298
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_stringSlot = 0x1006b298;
// R6GameService.dll import @ 1006b29c
constexpr unsigned int MSVCP71_DU_char_traits_Construct_basic_stringSlot = 0x1006b29c;
// R6GameService.dll import @ 1006b2a0
constexpr unsigned int MSVCP71_DU_char_traits_Construct_basic_stringSlot2 = 0x1006b2a0;
// R6GameService.dll import @ 1006b2a4
constexpr unsigned int MSVCP71_DU_char_traits_Destroy_basic_stringSlot = 0x1006b2a4;
// R6GameService.dll import @ 1006b2a8
constexpr unsigned int MSVCP71__ctype_idSlot = 0x1006b2a8;
// R6GameService.dll import @ 1006b2ac
constexpr unsigned int MSVCP71__ctype__GetcatSlot = 0x1006b2ac;
// R6GameService.dll import @ 1006b2b0
constexpr unsigned int MSVCP71_std_Construct_LockitSlot = 0x1006b2b0;
// R6GameService.dll import @ 1006b2b4
constexpr unsigned int MSVCP71_std_Destroy_LockitSlot = 0x1006b2b4;
// R6GameService.dll import @ 1006b2b8
constexpr unsigned int MSVCP71_id__Id_cntSlot = 0x1006b2b8;
// R6GameService.dll import @ 1006b2bc
constexpr unsigned int MSVCP71_locale__GetfacetSlot = 0x1006b2bc;
// R6GameService.dll import @ 1006b2c0
constexpr unsigned int MSVCP71_facet__IncrefSlot = 0x1006b2c0;
// R6GameService.dll import @ 1006b2c4
constexpr unsigned int MSVCP71_facet__RegisterSlot = 0x1006b2c4;
// R6GameService.dll import @ 1006b2c8
constexpr unsigned int MSVCP71__Mutex__LockSlot = 0x1006b2c8;
// R6GameService.dll import @ 1006b2cc
constexpr unsigned int MSVCP71__Mutex__UnlockSlot = 0x1006b2cc;
// R6GameService.dll import @ 1006b2d0
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_stringSlot2 = 0x1006b2d0;
// R6GameService.dll import @ 1006b2d4
constexpr unsigned int MSVCP71_GU_char_traits_Destroy_basic_stringSlot = 0x1006b2d4;
// R6GameService.dll import @ 1006b2d8
constexpr unsigned int MSVCP71__basic_streambuf_sputcSlot = 0x1006b2d8;
// R6GameService.dll import @ 1006b2dc
constexpr unsigned int MSVCP71_GU_char_traits__D_basic_ofstreamSlot = 0x1006b2dc;
// R6GameService.dll import @ 1006b2e0
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_ofstreamSlot = 0x1006b2e0;
// R6GameService.dll import @ 1006b2e4
constexpr unsigned int MSVCP71__String_base__XranSlot = 0x1006b2e4;
// R6GameService.dll import @ 1006b2e8
constexpr unsigned int MSVCP71_GU_char_traits_4_basic_stringSlot = 0x1006b2e8;
// R6GameService.dll import @ 1006b2ec
constexpr unsigned int MSVCP71_DU_char_traits_6_basic_ostreamSlot = 0x1006b2ec;
// R6GameService.dll import @ 1006b2f0
constexpr unsigned int MSVCP71_D__6U_char_traitsSlot = 0x1006b2f0;
// R6GameService.dll import @ 1006b2f4
constexpr unsigned int MSVCP71_std_coutSlot = 0x1006b2f4;
// R6GameService.dll import @ 1006b2f8
constexpr unsigned int MSVCP71_std_endlSlot2 = 0x1006b2f8;
// R6GameService.dll import @ 1006b2fc
constexpr unsigned int MSVCP71_GU_char_traits_6_basic_ostreamSlot2 = 0x1006b2fc;
// R6GameService.dll import @ 1006b300
constexpr unsigned int MSVCP71_GU_char_traits_6_basic_ostreamSlot3 = 0x1006b300;
// R6GameService.dll import @ 1006b304
constexpr unsigned int MSVCP71_GU_char_traits_Destroy_basic_ostreamSlot = 0x1006b304;
// R6GameService.dll import @ 1006b308
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_stringbufSlot = 0x1006b308;
// R6GameService.dll import @ 1006b30c
constexpr unsigned int MSVCP71__basic_stringbuf_overflowSlot = 0x1006b30c;
// R6GameService.dll import @ 1006b310
constexpr unsigned int MSVCP71__basic_stringbuf_pbackfailSlot = 0x1006b310;
// R6GameService.dll import @ 1006b314
constexpr unsigned int MSVCP71__basic_streambuf_showmanycSlot = 0x1006b314;
// R6GameService.dll import @ 1006b318
constexpr unsigned int MSVCP71__basic_stringbuf_underflowSlot = 0x1006b318;
// R6GameService.dll import @ 1006b31c
constexpr unsigned int MSVCP71__basic_streambuf_uflowSlot = 0x1006b31c;
// R6GameService.dll import @ 1006b320
constexpr unsigned int MSVCP71__basic_streambuf_xsgetnSlot = 0x1006b320;
// R6GameService.dll import @ 1006b324
constexpr unsigned int MSVCP71__basic_streambuf_xsputnSlot = 0x1006b324;
// R6GameService.dll import @ 1006b328
constexpr unsigned int MSVCP71_G__6GU_char_traitsSlot = 0x1006b328;
// R6GameService.dll import @ 1006b32c
constexpr unsigned int MSVCP71_GU_char_traits_4_basic_stringSlot2 = 0x1006b32c;
// R6GameService.dll import @ 1006b330
constexpr unsigned int MSVCP71_GU_char_traits_6_basic_ostreamSlot4 = 0x1006b330;
// R6GameService.dll import @ 1006b334
constexpr unsigned int MSVCP71__basic_stringbuf_seekoffSlot = 0x1006b334;
// R6GameService.dll import @ 1006b338
constexpr unsigned int MSVCP71__basic_stringbuf_seekposSlot = 0x1006b338;
// R6GameService.dll import @ 1006b33c
constexpr unsigned int MSVCP71__basic_streambuf_setbufSlot = 0x1006b33c;
// R6GameService.dll import @ 1006b340
constexpr unsigned int MSVCP71__basic_streambuf_imbueSlot = 0x1006b340;
// R6GameService.dll import @ 1006b344
constexpr unsigned int MSVCP71_GU_char_traits_Construct_basic_stringSlot3 = 0x1006b344;
// R6GameService.dll import @ 1006b348
constexpr unsigned int MSVCP71_GU_char_traits_Destroy_basic_stringbufSlot = 0x1006b348;
// R6GameService.dll import @ 1006b34c
constexpr unsigned int MSVCP71_DU_char_traits_6_basic_ostreamSlot2 = 0x1006b34c;
// R6GameService.dll import @ 1006b350
constexpr unsigned int MSVCP71_DU_char_traits__D_basic_ofstreamSlot = 0x1006b350;
// R6GameService.dll import @ 1006b354
constexpr unsigned int MSVCP71_DU_char_traits_Construct_basic_ofstreamSlot = 0x1006b354;
// R6GameService.dll import @ 1006b358
constexpr unsigned int MSVCP71_DU_char_traits_4_basic_stringSlot = 0x1006b358;
// R6GameService.dll import @ 1006b35c
constexpr unsigned int MSVCP71_GU_char_traits_6_basic_ostreamSlot5 = 0x1006b35c;
// R6GameService.dll import @ 1006b360
constexpr unsigned int MSVCP71_std_wcoutSlot = 0x1006b360;
// R6GameService.dll import @ 1006b364
constexpr unsigned int MSVCP71_DU_char_traits_Construct_basic_stringSlot3 = 0x1006b364;
// R6GameService.dll import @ 1006b368
constexpr unsigned int MSVCP71_std_wcerrSlot = 0x1006b368;
// R6GameService.dll import @ 1006b36c
constexpr unsigned int MSVCP71_ios_base_clearSlot = 0x1006b36c;
// R6GameService.dll import @ 1006b370
constexpr unsigned int MSVCP71_std_DestroylocaleSlot = 0x1006b370;
// R6GameService.dll import @ 1006b374
constexpr unsigned int MSVCP71_ios_base_getlocSlot = 0x1006b374;
// R6GameService.dll import @ 1006b37c
constexpr unsigned int MSVCR71___CppXcptFilterSlot = 0x1006b37c;
// R6GameService.dll import @ 1006b380
constexpr unsigned int MSVCR71__adjust_fdivSlot = 0x1006b380;
// R6GameService.dll import @ 1006b384
constexpr unsigned int MSVCR71_mallocSlot = 0x1006b384;
// R6GameService.dll import @ 1006b388
constexpr unsigned int MSVCR71__inittermSlot = 0x1006b388;
// R6GameService.dll import @ 1006b38c
constexpr unsigned int MSVCR71__onexitSlot = 0x1006b38c;
// R6GameService.dll import @ 1006b390
constexpr unsigned int MSVCR71___dllonexitSlot = 0x1006b390;
// R6GameService.dll import @ 1006b394
constexpr unsigned int MSVCR71__Destroytype_infoSlot = 0x1006b394;
// R6GameService.dll import @ 1006b398
constexpr unsigned int MSVCR71__terminateSlot = 0x1006b398;
// R6GameService.dll import @ 1006b39c
constexpr unsigned int MSVCR71_strtokSlot = 0x1006b39c;
// R6GameService.dll import @ 1006b3a0
constexpr unsigned int MSVCR71___RTDynamicCastSlot = 0x1006b3a0;
// R6GameService.dll import @ 1006b3a4
constexpr unsigned int MSVCR71_difftimeSlot = 0x1006b3a4;
// R6GameService.dll import @ 1006b3a8
constexpr unsigned int MSVCR71_timeSlot = 0x1006b3a8;
// R6GameService.dll import @ 1006b3ac
constexpr unsigned int MSVCR71__purecallSlot = 0x1006b3ac;
// R6GameService.dll import @ 1006b3b0
constexpr unsigned int MSVCR71_callocSlot = 0x1006b3b0;
// R6GameService.dll import @ 1006b3b4
constexpr unsigned int MSVCR71__DestroyexceptionSlot = 0x1006b3b4;
// R6GameService.dll import @ 1006b3b8
constexpr unsigned int MSVCR71__ConstructexceptionSlot = 0x1006b3b8;
// R6GameService.dll import @ 1006b3bc
constexpr unsigned int MSVCR71_memmoveSlot = 0x1006b3bc;
// R6GameService.dll import @ 1006b3c0
constexpr unsigned int MSVCR71_fwriteSlot = 0x1006b3c0;
// R6GameService.dll import @ 1006b3c4
constexpr unsigned int MSVCR71_toupperSlot = 0x1006b3c4;
// R6GameService.dll import @ 1006b3c8
constexpr unsigned int MSVCR71_fopenSlot = 0x1006b3c8;
// R6GameService.dll import @ 1006b3cc
constexpr unsigned int MSVCR71_fseekSlot = 0x1006b3cc;
// R6GameService.dll import @ 1006b3d0
constexpr unsigned int MSVCR71_ftellSlot = 0x1006b3d0;
// R6GameService.dll import @ 1006b3d4
constexpr unsigned int MSVCR71_fcloseSlot = 0x1006b3d4;
// R6GameService.dll import @ 1006b3d8
constexpr unsigned int MSVCR71_rewindSlot = 0x1006b3d8;
// R6GameService.dll import @ 1006b3dc
constexpr unsigned int MSVCR71_freadSlot = 0x1006b3dc;
// R6GameService.dll import @ 1006b3e0
constexpr unsigned int MSVCR71_removeSlot = 0x1006b3e0;
// R6GameService.dll import @ 1006b3e4
constexpr unsigned int MSVCR71_renameSlot = 0x1006b3e4;
// R6GameService.dll import @ 1006b3e8
constexpr unsigned int MSVCR71_atoiSlot = 0x1006b3e8;
// R6GameService.dll import @ 1006b3ec
constexpr unsigned int MSVCR71_printfSlot = 0x1006b3ec;
// R6GameService.dll import @ 1006b3f0
constexpr unsigned int MSVCR71_sprintfSlot = 0x1006b3f0;
// R6GameService.dll import @ 1006b3f4
constexpr unsigned int MSVCR71__snprintfSlot = 0x1006b3f4;
// R6GameService.dll import @ 1006b3f8
constexpr unsigned int MSVCR71_strncmpSlot = 0x1006b3f8;
// R6GameService.dll import @ 1006b3fc
constexpr unsigned int MSVCR71_strstrSlot = 0x1006b3fc;
// R6GameService.dll import @ 1006b400
constexpr unsigned int MSVCR71_strncpySlot = 0x1006b400;
// R6GameService.dll import @ 1006b404
constexpr unsigned int MSVCR71__Constructbad_castSlot = 0x1006b404;
// R6GameService.dll import @ 1006b408
constexpr unsigned int MSVCR71__Destroybad_castSlot = 0x1006b408;
// R6GameService.dll import @ 1006b40c
constexpr unsigned int MSVCR71__Constructbad_castSlot2 = 0x1006b40c;
// R6GameService.dll import @ 1006b410
constexpr unsigned int MSVCR71__ConstructexceptionSlot2 = 0x1006b410;
// R6GameService.dll import @ 1006b414
constexpr unsigned int MSVCR71_freeSlot = 0x1006b414;
// R6GameService.dll import @ 1006b418
constexpr unsigned int MSVCR71__CxxThrowExceptionSlot = 0x1006b418;
// R6GameService.dll import @ 1006b41c
constexpr unsigned int MSVCR71___CxxFrameHandlerSlot = 0x1006b41c;
// R6GameService.dll import @ 1006b420
constexpr unsigned int MSVCR71__except_handler3Slot = 0x1006b420;
// R6GameService.dll import @ 1006b424
constexpr unsigned int MSVCR71_randSlot = 0x1006b424;
// R6GameService.dll import @ 1006b428
constexpr unsigned int MSVCR71_srandSlot = 0x1006b428;
// R6GameService.dll import @ 1006b42c
constexpr unsigned int MSVCR71_wprintfSlot = 0x1006b42c;
// R6GameService.dll import @ 1006b430
constexpr unsigned int MSVCR71_wcscatSlot = 0x1006b430;
// R6GameService.dll import @ 1006b434
constexpr unsigned int MSVCR71_wcscpySlot = 0x1006b434;
// R6GameService.dll import @ 1006b438
constexpr unsigned int MSVCR71_memsetSlot = 0x1006b438;
// R6GameService.dll import @ 1006b43c
constexpr unsigned int MSVCR71__unlinkSlot = 0x1006b43c;
// R6GameService.dll import @ 1006b440
constexpr unsigned int MSVCR71__ftolSlot = 0x1006b440;
// R6GameService.dll import @ 1006b444
constexpr unsigned int MSVCR71___security_error_handlerSlot = 0x1006b444;
// R6GameService.dll import @ 1006b448
constexpr unsigned int MSVCR71_fflushSlot = 0x1006b448;
// R6GameService.dll import @ 1006b44c
constexpr unsigned int MSVCR71_fprintfSlot = 0x1006b44c;
// R6GameService.dll import @ 1006b450
constexpr unsigned int MSVCR71_gmtimeSlot = 0x1006b450;
// R6GameService.dll import @ 1006b458
constexpr unsigned int OLEAUT32_SysAllocStringLenSlot = 0x1006b458;
// R6GameService.dll import @ 1006b45c
constexpr unsigned int OLEAUT32_GetActiveObjectSlot = 0x1006b45c;
// R6GameService.dll import @ 1006b460
constexpr unsigned int OLEAUT32_VariantClearSlot = 0x1006b460;
// R6GameService.dll import @ 1006b464
constexpr unsigned int OLEAUT32_VariantInitSlot = 0x1006b464;
// R6GameService.dll import @ 1006b468
constexpr unsigned int OLEAUT32_SafeArrayUnaccessDataSlot = 0x1006b468;
// R6GameService.dll import @ 1006b46c
constexpr unsigned int OLEAUT32_SafeArrayAccessDataSlot = 0x1006b46c;
// R6GameService.dll import @ 1006b470
constexpr unsigned int OLEAUT32_SafeArrayCreateVectorSlot = 0x1006b470;
// R6GameService.dll import @ 1006b474
constexpr unsigned int OLEAUT32_SysFreeStringSlot = 0x1006b474;
// R6GameService.dll import @ 1006b47c
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetGSGameStateSlot = 0x1006b47c;
// R6GameService.dll import @ 1006b480
constexpr unsigned int R6Abstract_UR6AbstractGameService_GSClientPostMessageSlot = 0x1006b480;
// R6GameService.dll import @ 1006b484
constexpr unsigned int R6Abstract_UR6AbstractGameService_MSCLientLeaveServerSlot = 0x1006b484;
// R6GameService.dll import @ 1006b488
constexpr unsigned int R6Abstract_UR6AbstractGameService_IsMSClientIsInRequestSlot = 0x1006b488;
// R6GameService.dll import @ 1006b48c
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetLoggedInUbiDotComSlot = 0x1006b48c;
// R6GameService.dll import @ 1006b490
constexpr unsigned int R6Abstract_UR6AbstractGameService_IsServerJoinedSlot = 0x1006b490;
// R6GameService.dll import @ 1006b494
constexpr unsigned int R6Abstract__4UR6AbstractGameServiceSlot = 0x1006b494;
// R6GameService.dll import @ 1006b498
constexpr unsigned int R6Abstract___7UR6AbstractEviLPatchServiceSlot = 0x1006b498;
// R6GameService.dll import @ 1006b49c
constexpr unsigned int R6Abstract__DestroyUR6AbstractEviLPatchServiceSlot = 0x1006b49c;
// R6GameService.dll import @ 1006b4a0
constexpr unsigned int R6Abstract_UR6AbstractGameService_SetGSGameStateSlot = 0x1006b4a0;
// R6GameService.dll import @ 1006b4a4
constexpr unsigned int R6Abstract_UR6AbstractGameService_SetGSClientComInterfaceSlot = 0x1006b4a4;
// R6GameService.dll import @ 1006b4a8
constexpr unsigned int R6Abstract_UR6AbstractGameService_InitGSClientSlot = 0x1006b4a8;
// R6GameService.dll import @ 1006b4ac
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetAuthIDSlot = 0x1006b4ac;
// R6GameService.dll import @ 1006b4b0
constexpr unsigned int R6Abstract_UR6AbstractGameService_ResetAuthIdSlot = 0x1006b4b0;
// R6GameService.dll import @ 1006b4b4
constexpr unsigned int R6Abstract_UR6AbstractGameService_RequestGSCDKeyAuthIDSlot = 0x1006b4b4;
// R6GameService.dll import @ 1006b4b8
constexpr unsigned int R6Abstract_UR6AbstractGameService_RequestModCDKeyProcessSlot = 0x1006b4b8;
// R6GameService.dll import @ 1006b4bc
constexpr unsigned int R6Abstract_UR6AbstractGameService_MasterServerManagerSlot = 0x1006b4bc;
// R6GameService.dll import @ 1006b4c0
constexpr unsigned int R6Abstract_UR6AbstractGameService_ProcessJoinServerSlot = 0x1006b4c0;
// R6GameService.dll import @ 1006b4c4
constexpr unsigned int R6Abstract_UR6AbstractGameService_ProcessIsLobbyDisconnectSlot = 0x1006b4c4;
// R6GameService.dll import @ 1006b4c8
constexpr unsigned int R6Abstract_UR6AbstractGameService_ProcessIsRouterDisconnectSlot = 0x1006b4c8;
// R6GameService.dll import @ 1006b4cc
constexpr unsigned int R6Abstract_UR6AbstractGameService_ProcessUbiComJoinServerSlot = 0x1006b4cc;
// R6GameService.dll import @ 1006b4d0
constexpr unsigned int R6Abstract_UR6AbstractGameService_ProcessLoginMasterSrvSlot = 0x1006b4d0;
// R6GameService.dll import @ 1006b4d4
constexpr unsigned int R6Abstract_UR6AbstractGameService_GameServiceManagerSlot = 0x1006b4d4;
// R6GameService.dll import @ 1006b4d8
constexpr unsigned int R6Abstract_UR6AbstractGameService_CDKeyDisconnecUserSlot = 0x1006b4d8;
// R6GameService.dll import @ 1006b4dc
constexpr unsigned int R6Abstract_UR6AbstractGameService_PrivateStaticClassSlot = 0x1006b4dc;
// R6GameService.dll import @ 1006b4e0
constexpr unsigned int R6Abstract_UR6AbstractEviLPatchService_PrivateStaticClassSlot = 0x1006b4e0;
// R6GameService.dll import @ 1006b4e4
constexpr unsigned int R6Abstract_UR6AbstractEviLPatchService_SetFunctionPtrSlot = 0x1006b4e4;
// R6GameService.dll import @ 1006b4e8
constexpr unsigned int R6Abstract__ConstructUR6AbstractGameServiceSlot = 0x1006b4e8;
// R6GameService.dll import @ 1006b4ec
constexpr unsigned int R6Abstract__ConstructUR6AbstractGameServiceSlot2 = 0x1006b4ec;
// R6GameService.dll import @ 1006b4f0
constexpr unsigned int R6Abstract__DestroyUR6AbstractGameServiceSlot = 0x1006b4f0;
// R6GameService.dll import @ 1006b4f4
constexpr unsigned int R6Abstract_UR6AbstractGameService_CreatedSlot = 0x1006b4f4;
// R6GameService.dll import @ 1006b4f8
constexpr unsigned int R6Abstract_UR6AbstractGameService_InitGSCDKeySlot = 0x1006b4f8;
// R6GameService.dll import @ 1006b4fc
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetRegServerInitializedSlot = 0x1006b4fc;
// R6GameService.dll import @ 1006b500
constexpr unsigned int R6Abstract_UR6AbstractGameService_SetGameServiceRequestStateSlot = 0x1006b500;
// R6GameService.dll import @ 1006b504
constexpr unsigned int R6Abstract_UR6AbstractGameService_SetRegServerLoginRequestSlot = 0x1006b504;
// R6GameService.dll import @ 1006b508
constexpr unsigned int R6Abstract_UR6AbstractGameService_SetLoginRegServerSlot = 0x1006b508;
// R6GameService.dll import @ 1006b50c
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetLoginRegServerSlot = 0x1006b50c;
// R6GameService.dll import @ 1006b510
constexpr unsigned int R6Abstract_UR6AbstractGameService_GetServerRegisteredSlot = 0x1006b510;
// R6GameService.dll import @ 1006b514
constexpr unsigned int R6Abstract_UR6AbstractGameService_ServerRoundStartSlot = 0x1006b514;
// R6GameService.dll import @ 1006b518
constexpr unsigned int R6Abstract_UR6AbstractGameService_ServerRoundFinishSlot = 0x1006b518;
// R6GameService.dll import @ 1006b51c
constexpr unsigned int R6Abstract_UR6AbstractGameService_SubmitMatchResultSlot = 0x1006b51c;
// R6GameService.dll import @ 1006b520
constexpr unsigned int R6Abstract_UR6AbstractGameService_DisconnectAllCDKeyPlayersSlot = 0x1006b520;
// R6GameService.dll import @ 1006b528
constexpr unsigned int RPCRT4_RpcStringBindingComposeWSlot = 0x1006b528;
// R6GameService.dll import @ 1006b52c
constexpr unsigned int RPCRT4_RpcStringFreeWSlot = 0x1006b52c;
// R6GameService.dll import @ 1006b530
constexpr unsigned int RPCRT4_RpcBindingFreeSlot = 0x1006b530;
// R6GameService.dll import @ 1006b534
constexpr unsigned int RPCRT4_NdrClientCallSlot = 0x1006b534;
// R6GameService.dll import @ 1006b538
constexpr unsigned int RPCRT4_RpcBindingFromStringBindingWSlot = 0x1006b538;
// R6GameService.dll import @ 1006b540
constexpr unsigned int WS2_32_sendSlot = 0x1006b540;
// R6GameService.dll import @ 1006b544
constexpr unsigned int WS2_32_recvSlot = 0x1006b544;
// R6GameService.dll import @ 1006b548
constexpr unsigned int WS2_32_ntohsSlot = 0x1006b548;
// R6GameService.dll import @ 1006b54c
constexpr unsigned int WS2_32_getpeernameSlot = 0x1006b54c;
// R6GameService.dll import @ 1006b550
constexpr unsigned int WS2_32_getsocknameSlot = 0x1006b550;
// R6GameService.dll import @ 1006b554
constexpr unsigned int WS2_32_htonlSlot = 0x1006b554;
// R6GameService.dll import @ 1006b558
constexpr unsigned int WS2_32_inet_ntoaSlot = 0x1006b558;
// R6GameService.dll import @ 1006b55c
constexpr unsigned int WS2_32_WSAIoctlSlot = 0x1006b55c;
// R6GameService.dll import @ 1006b560
constexpr unsigned int WS2_32_socketSlot = 0x1006b560;
// R6GameService.dll import @ 1006b564
constexpr unsigned int WS2_32_connectSlot = 0x1006b564;
// R6GameService.dll import @ 1006b568
constexpr unsigned int WS2_32_WSACleanupSlot = 0x1006b568;
// R6GameService.dll import @ 1006b56c
constexpr unsigned int WS2_32_closesocketSlot = 0x1006b56c;
// R6GameService.dll import @ 1006b570
constexpr unsigned int WS2_32_WSAGetLastErrorSlot = 0x1006b570;
// R6GameService.dll import @ 1006b574
constexpr unsigned int WS2_32_recvfromSlot = 0x1006b574;
// R6GameService.dll import @ 1006b578
constexpr unsigned int WS2_32_sendtoSlot = 0x1006b578;
// R6GameService.dll import @ 1006b57c
constexpr unsigned int WS2_32_ioctlsocketSlot = 0x1006b57c;
// R6GameService.dll import @ 1006b580
constexpr unsigned int WS2_32_setsockoptSlot = 0x1006b580;
// R6GameService.dll import @ 1006b584
constexpr unsigned int WS2_32_WSASocketWSlot = 0x1006b584;
// R6GameService.dll import @ 1006b588
constexpr unsigned int WS2_32_WSAStartupSlot = 0x1006b588;
// R6GameService.dll import @ 1006b58c
constexpr unsigned int WS2_32_selectSlot = 0x1006b58c;
// R6GameService.dll import @ 1006b590
constexpr unsigned int WS2_32___WSAFDIsSetSlot = 0x1006b590;
// R6GameService.dll import @ 1006b594
constexpr unsigned int WS2_32_getsockoptSlot = 0x1006b594;
// R6GameService.dll import @ 1006b598
constexpr unsigned int WS2_32_bindSlot = 0x1006b598;
// R6GameService.dll import @ 1006b59c
constexpr unsigned int WS2_32_htonsSlot = 0x1006b59c;
// R6GameService.dll import @ 1006b5a0
constexpr unsigned int WS2_32_gethostbynameSlot = 0x1006b5a0;
// R6GameService.dll import @ 1006b5a4
constexpr unsigned int WS2_32_inet_addrSlot = 0x1006b5a4;
// R6GameService.dll import @ 1006b5a8
constexpr unsigned int WS2_32_ntohlSlot = 0x1006b5a8;
// R6GameService.dll import @ 1006b5b0
constexpr unsigned int iphlpapi_GetAdaptersInfoSlot = 0x1006b5b0;
// R6GameService.dll data @ 1006b630
constexpr unsigned int GAtlCriticalSectionScope = 0x1006b630;
// R6GameService.dll wide-text @ 1006b63c
constexpr unsigned int WideTextNew = 0x1006b63c;
// R6GameService.dll vtable-prefix @ 1006b648
constexpr unsigned int UeviLPatchServiceDispatchTable = 0x1006b648;
// R6GameService.dll vtable-prefix @ 1006b6b0
constexpr unsigned int UR6ModGSInfoDispatchTable = 0x1006b6b0;
// R6GameService.dll wide-text @ 1006b714
constexpr unsigned int WideTextTextFormat = 0x1006b714;
// R6GameService.dll wide-text @ 1006b71c
constexpr unsigned int WideTextUeviLCoreEncrypt = 0x1006b71c;
// R6GameService.dll wide-text @ 1006b744
constexpr unsigned int WideTextUeviLCoreDecrypt = 0x1006b744;
// R6GameService.dll wide-text @ 1006b770
constexpr unsigned int WideTextUeviLCoreIsCDKeyValidOnMachine = 0x1006b770;
// R6GameService.dll text @ 1006b7b4
constexpr unsigned int TextIndexCountArrayNum = 0x1006b7b4;
// R6GameService.dll text @ 1006b7cc
constexpr unsigned int TextIndexArrayNum = 0x1006b7cc;
// R6GameService.dll text @ 1006b7dc
constexpr unsigned int TextIndex0 = 0x1006b7dc;
// R6GameService.dll text @ 1006b7e8
constexpr unsigned int TextDRavenshield412CoreIncUnTemplateH = 0x1006b7e8;
// R6GameService.dll text @ 1006b814
constexpr unsigned int TextBadCast = 0x1006b814;
// R6GameService.dll vtable-prefix @ 1006b820
constexpr unsigned int UR6ServerListDispatchTable = 0x1006b820;
// R6GameService.dll vtable-prefix @ 1006b918
constexpr unsigned int UR6LanServersDispatchTable = 0x1006b918;
// R6GameService.dll vtable-prefix @ 1006ba10
constexpr unsigned int UR6GSServersDispatchTable = 0x1006ba10;
// R6GameService.dll wide-text @ 1006bb24
constexpr unsigned int WideTextUpgradeLauncherExe = 0x1006bb24;
// R6GameService.dll text @ 1006bb50
constexpr unsigned int TextUpgradeLauncherUniqueInstance = 0x1006bb50;
// R6GameService.dll wide-text @ 1006bb70
constexpr unsigned int WideTextSS04X = 0x1006bb70;
// R6GameService.dll wide-text @ 1006bb98
constexpr unsigned int WideTextUeviLPatchServiceExecGetDownloadProgress = 0x1006bb98;
// R6GameService.dll data @ 1006bbf0
constexpr unsigned int GSharedDoubleZero = 0x1006bbf0;
// R6GameService.dll wide-text @ 1006bbf8
constexpr unsigned int WideTextUeviLPatchServiceExecGetExitCause = 0x1006bbf8;
// R6GameService.dll wide-text @ 1006bc40
constexpr unsigned int WideTextUeviLPatchServiceExecCanRunUpdateService = 0x1006bc40;
// R6GameService.dll wide-text @ 1006bc98
constexpr unsigned int WideTextPunctuation = 0x1006bc98;
// R6GameService.dll vtable-prefix @ 1006bca0
constexpr unsigned int wide_log_supportDispatchTable = 0x1006bca0;
// R6GameService.dll vtable-prefix @ 1006bcd4
constexpr unsigned int wide_log_supportDispatchTable2 = 0x1006bcd4;
// R6GameService.dll text @ 1006bce0
constexpr unsigned int TextABORTCALLED = 0x1006bce0;
// R6GameService.dll wide-text @ 1006bcf0
constexpr unsigned int WideTextUeviLPatchServiceGetPatchServiceState = 0x1006bcf0;
// R6GameService.dll wide-text @ 1006bd40
constexpr unsigned int WideTextRavenShield = 0x1006bd40;
// R6GameService.dll wide-text @ 1006bd58
constexpr unsigned int WideTextUeviLPatchServiceExecGetState = 0x1006bd58;
// R6GameService.dll wide-text @ 1006bd98
constexpr unsigned int WideTextUeviLPatchServiceExecAbortPatchService = 0x1006bd98;
// R6GameService.dll text @ 1006bdec
constexpr unsigned int TextUpdateserviceLog = 0x1006bdec;
// R6GameService.dll wide-text @ 1006be00
constexpr unsigned int WideTextUeviLPatchServiceStartPatch = 0x1006be00;
// R6GameService.dll wide-text @ 1006be40
constexpr unsigned int WideTextUeviLPatchServiceExecStartPatch = 0x1006be40;
// R6GameService.dll scalar @ 1006bec8
constexpr unsigned int NativeDouble16777216_0 = 0x1006bec8;
// R6GameService.dll scalar @ 1006bed0
constexpr unsigned int NativeDouble4294967296_0 = 0x1006bed0;
// R6GameService.dll wide-text @ 1006bed8
constexpr unsigned int WideTextR6GameServiceInit = 0x1006bed8;
// R6GameService.dll wide-text @ 1006c0b0
constexpr unsigned int WideTextPunctuation2 = 0x1006c0b0;
// R6GameService.dll wide-text @ 1006c0b4
constexpr unsigned int WideTextPunctuation3 = 0x1006c0b4;
// R6GameService.dll wide-text @ 1006c0b8
constexpr unsigned int WideTextPunctuation4 = 0x1006c0b8;
// R6GameService.dll wide-text @ 1006c0c0
constexpr unsigned int WideTextUR6ModGSInfoExecNativeInitModInfo = 0x1006c0c0;
// R6GameService.dll wide-text @ 1006c108
constexpr unsigned int WideTextInitModInfoMSzGameServiceGameNameS = 0x1006c108;
// R6GameService.dll wide-text @ 1006c160
constexpr unsigned int WideTextInitModInfoUbiClientVersionS = 0x1006c160;
// R6GameService.dll wide-text @ 1006c1a8
constexpr unsigned int WideTextRAVENSHIELD = 0x1006c1a8;
// R6GameService.dll wide-text @ 1006c1c0
constexpr unsigned int WideTextR6RSCRIMSONHAMMER = 0x1006c1c0;
// R6GameService.dll wide-text @ 1006c1e4
constexpr unsigned int WideTextIRONWRATH = 0x1006c1e4;
// R6GameService.dll wide-text @ 1006c1f8
constexpr unsigned int WideTextR6RSATHENASWORD = 0x1006c1f8;
// R6GameService.dll wide-text @ 1006c218
constexpr unsigned int WideTextATHENASWORD = 0x1006c218;
// R6GameService.dll wide-text @ 1006c230
constexpr unsigned int WideTextR6RSCUSTOM = 0x1006c230;
// R6GameService.dll wide-text @ 1006c248
constexpr unsigned int WideTextRSPC12 = 0x1006c248;
// R6GameService.dll wide-text @ 1006c258
constexpr unsigned int WideTextUR6GSServersDestroy = 0x1006c258;
// R6GameService.dll wide-text @ 1006c288
constexpr unsigned int WideTextLoggedOffFromUbiComMSClientService = 0x1006c288;
// R6GameService.dll wide-text @ 1006c2dc
constexpr unsigned int WideTextMSClientUninitialize = 0x1006c2dc;
// R6GameService.dll wide-text @ 1006c318
constexpr unsigned int WideTextF = 0x1006c318;
// R6GameService.dll wide-text @ 1006c31c
constexpr unsigned int WideTextE = 0x1006c31c;
// R6GameService.dll wide-text @ 1006c320
constexpr unsigned int WideTextD = 0x1006c320;
// R6GameService.dll wide-text @ 1006c324
constexpr unsigned int WideTextC = 0x1006c324;
// R6GameService.dll wide-text @ 1006c328
constexpr unsigned int WideTextB = 0x1006c328;
// R6GameService.dll wide-text @ 1006c32c
constexpr unsigned int WideTextA = 0x1006c32c;
// R6GameService.dll wide-text @ 1006c330
constexpr unsigned int WideTextF2 = 0x1006c330;
// R6GameService.dll wide-text @ 1006c334
constexpr unsigned int WideTextE2 = 0x1006c334;
// R6GameService.dll wide-text @ 1006c338
constexpr unsigned int WideTextD2 = 0x1006c338;
// R6GameService.dll wide-text @ 1006c33c
constexpr unsigned int WideTextC2 = 0x1006c33c;
// R6GameService.dll wide-text @ 1006c340
constexpr unsigned int WideTextB2 = 0x1006c340;
// R6GameService.dll wide-text @ 1006c344
constexpr unsigned int WideTextA2 = 0x1006c344;
// R6GameService.dll wide-text @ 1006c348
constexpr unsigned int WideText9 = 0x1006c348;
// R6GameService.dll wide-text @ 1006c34c
constexpr unsigned int WideText8 = 0x1006c34c;
// R6GameService.dll wide-text @ 1006c350
constexpr unsigned int WideText7 = 0x1006c350;
// R6GameService.dll wide-text @ 1006c354
constexpr unsigned int WideText6 = 0x1006c354;
// R6GameService.dll wide-text @ 1006c358
constexpr unsigned int WideText5 = 0x1006c358;
// R6GameService.dll wide-text @ 1006c35c
constexpr unsigned int WideText4 = 0x1006c35c;
// R6GameService.dll wide-text @ 1006c360
constexpr unsigned int WideText3 = 0x1006c360;
// R6GameService.dll wide-text @ 1006c364
constexpr unsigned int WideText2 = 0x1006c364;
// R6GameService.dll wide-text @ 1006c368
constexpr unsigned int WideText1 = 0x1006c368;
// R6GameService.dll wide-text @ 1006c36c
constexpr unsigned int WideText0 = 0x1006c36c;
// R6GameService.dll wide-text @ 1006c370
constexpr unsigned int WideTextUR6GSServersPingRequest = 0x1006c370;
// R6GameService.dll wide-text @ 1006c3a4
constexpr unsigned int WideTextUR6GSServersPollPingManager = 0x1006c3a4;
// R6GameService.dll wide-text @ 1006c3e0
constexpr unsigned int WideTextUR6ServerListExecNativeGetPingTime = 0x1006c3e0;
// R6GameService.dll wide-text @ 1006c430
constexpr unsigned int WideTextUR6ServerListExecNativeGetPingTimeOut = 0x1006c430;
// R6GameService.dll wide-text @ 1006c480
constexpr unsigned int WideTextUR6GSServersExecNativeProcessIcmpPing = 0x1006c480;
// R6GameService.dll wide-text @ 1006c4d0
constexpr unsigned int WideTextDoesNotMatter = 0x1006c4d0;
// R6GameService.dll scalar @ 1006c4ec
constexpr unsigned int NativeFloat5000_0 = 0x1006c4ec;
// R6GameService.dll scalar @ 1006c4f0
constexpr unsigned int NativeFloat4294967296_0 = 0x1006c4f0;
// R6GameService.dll wide-text @ 1006c4f8
constexpr unsigned int WideTextUR6GSServersExecNativeGetSeconds = 0x1006c4f8;
// R6GameService.dll wide-text @ 1006c540
constexpr unsigned int WideTextUR6ServerListExecNativeGetMilliSeconds = 0x1006c540;
// R6GameService.dll text @ 1006c594
constexpr unsigned int TextEndModuleVersionOutput = 0x1006c594;
// R6GameService.dll text @ 1006c5bc
constexpr unsigned int TextBeginModuleVersionOutput = 0x1006c5bc;
// R6GameService.dll text @ 1006c5e4
constexpr unsigned int TextLibrarySVersionD = 0x1006c5e4;
// R6GameService.dll text @ 1006c608
constexpr unsigned int TextEndModuleVersionOutput2 = 0x1006c608;
// R6GameService.dll text @ 1006c630
constexpr unsigned int TextNoLinkedGsLibrary = 0x1006c630;
// R6GameService.dll text @ 1006c64c
constexpr unsigned int TextBeginModuleVersionOutput2 = 0x1006c64c;
// R6GameService.dll wide-text @ 1006c678
constexpr unsigned int WideTextUR6ServerListExecNativeGetMaxPlayers = 0x1006c678;
// R6GameService.dll wide-text @ 1006c6c8
constexpr unsigned int WideTextUR6GSServersExecGetMaxUbiServerNameSize = 0x1006c6c8;
// R6GameService.dll wide-text @ 1006c71c
constexpr unsigned int WideTextGAMESERVICE = 0x1006c71c;
// R6GameService.dll wide-text @ 1006c738
constexpr unsigned int WideTextUR6ServerListExecNativeGetOwnSvrPort = 0x1006c738;
// R6GameService.dll wide-text @ 1006c788
constexpr unsigned int WideTextUR6GSServersOnSameSubNet = 0x1006c788;
// R6GameService.dll wide-text @ 1006c7c0
constexpr unsigned int WideTextCallbackHttpCompleted = 0x1006c7c0;
// R6GameService.dll wide-text @ 1006c7f0
constexpr unsigned int WideTextCallbackHttpCompletedI = 0x1006c7f0;
// R6GameService.dll wide-text @ 1006c828
constexpr unsigned int WideTextUR6GSServersExecNativeUnInitMSClient = 0x1006c828;
// R6GameService.dll wide-text @ 1006c878
constexpr unsigned int WideTextUR6GSServersExecUnInitializeMSClient = 0x1006c878;
// R6GameService.dll wide-text @ 1006c8c8
constexpr unsigned int WideTextUR6GSServersExecNativeGetMSClientInitialized = 0x1006c8c8;
// R6GameService.dll wide-text @ 1006c928
constexpr unsigned int WideTextUR6GSServersPollMSClientCallbacks = 0x1006c928;
// R6GameService.dll wide-text @ 1006c970
constexpr unsigned int WideTextJOINSERVERFAILPASSWORDNOTCORRECT = 0x1006c970;
// R6GameService.dll wide-text @ 1006c9b8
constexpr unsigned int WideTextJOINSERVERFAILROOMFULL = 0x1006c9b8;
// R6GameService.dll wide-text @ 1006c9ec
constexpr unsigned int WideTextJOINSERVERFAILDEFAULT = 0x1006c9ec;
// R6GameService.dll wide-text @ 1006ca20
constexpr unsigned int WideTextLOGINFAILBANNEDACCOUNT = 0x1006ca20;
// R6GameService.dll wide-text @ 1006ca54
constexpr unsigned int WideTextLOGINFAILBLOCKEDACCOUNT = 0x1006ca54;
// R6GameService.dll wide-text @ 1006ca88
constexpr unsigned int WideTextLOGINFAILLOCKEDACCOUNT = 0x1006ca88;
// R6GameService.dll wide-text @ 1006cabc
constexpr unsigned int WideTextLOGINFAILDEFAULT = 0x1006cabc;
// R6GameService.dll wide-text @ 1006cae4
constexpr unsigned int WideTextLOGINFAILDATABASEFAILED = 0x1006cae4;
// R6GameService.dll wide-text @ 1006cb18
constexpr unsigned int WideTextLOGINFAILALREADYCONNECTED = 0x1006cb18;
// R6GameService.dll wide-text @ 1006cb50
constexpr unsigned int WideTextLOGINFAILNOTREGISTERED = 0x1006cb50;
// R6GameService.dll wide-text @ 1006cb84
constexpr unsigned int WideTextLOGINFAILPASSWORDNOTCORRECT = 0x1006cb84;
// R6GameService.dll wide-text @ 1006cbc0
constexpr unsigned int WideTextCallbackMSErrorI = 0x1006cbc0;
// R6GameService.dll wide-text @ 1006cbf0
constexpr unsigned int WideTextCallbackMSInitFinishedI = 0x1006cbf0;
// R6GameService.dll wide-text @ 1006cc2c
constexpr unsigned int WideTextCallbackMSRequestFinished = 0x1006cc2c;
// R6GameService.dll wide-text @ 1006cc68
constexpr unsigned int WideTextCallbackMSJoinFinished = 0x1006cc68;
// R6GameService.dll wide-text @ 1006cca0
constexpr unsigned int WideTextCallbackMSLoginDisconnect = 0x1006cca0;
// R6GameService.dll wide-text @ 1006ccdc
constexpr unsigned int WideTextCallbackMSLobbyDisconnect = 0x1006ccdc;
// R6GameService.dll wide-text @ 1006cd18
constexpr unsigned int WideTextMSMatchStartedCBThisClientWillNotBeSubmitingScores = 0x1006cd18;
// R6GameService.dll wide-text @ 1006cd98
constexpr unsigned int WideTextRetrying = 0x1006cd98;
// R6GameService.dll wide-text @ 1006cdc0
constexpr unsigned int WideTextMSClientInitMatchResultReturnedX = 0x1006cdc0;
// R6GameService.dll wide-text @ 1006ce18
constexpr unsigned int WideTextMSClientMatchStartedReturnedFalseBigProblemHere = 0x1006ce18;
// R6GameService.dll wide-text @ 1006ce88
constexpr unsigned int WideTextCallbackMSMatchStartedCBCallBackLobbyIdDRoomIdDAndUiMatchIDD = 0x1006ce88;
// R6GameService.dll wide-text @ 1006cf38
constexpr unsigned int WideTextMSSubmitMatchCBThisClientIsNotSubmitingScores = 0x1006cf38;
// R6GameService.dll wide-text @ 1006cfb0
constexpr unsigned int WideTextCallbackMSSubmitMatchCBCallBackSuccessUiMatchIDD = 0x1006cfb0;
// R6GameService.dll wide-text @ 1006d030
constexpr unsigned int WideTextCallbackMSSubmitMatchCBCallBackErrorReasonIdD = 0x1006d030;
// R6GameService.dll wide-text @ 1006d0a8
constexpr unsigned int WideTextUR6GSServersExecIsRefreshServersInProgress = 0x1006d0a8;
// R6GameService.dll wide-text @ 1006d108
constexpr unsigned int WideTextUR6GSServersExecStopRefreshServers = 0x1006d108;
// R6GameService.dll wide-text @ 1006d158
constexpr unsigned int WideTextUR6GSServersMSCLientLeaveServer = 0x1006d158;
// R6GameService.dll wide-text @ 1006d1a0
constexpr unsigned int WideTextMSClientLeaveGameServerFAILED = 0x1006d1a0;
// R6GameService.dll wide-text @ 1006d1ec
constexpr unsigned int WideTextMSClientLeaveGameServer = 0x1006d1ec;
// R6GameService.dll wide-text @ 1006d228
constexpr unsigned int WideTextUR6GSServersMSCLientJoinServer = 0x1006d228;
// R6GameService.dll wide-text @ 1006d3e0
constexpr unsigned int WideTextUR6GSServersExecNativeMSCLientJoinServerByID = 0x1006d3e0;
// R6GameService.dll wide-text @ 1006d440
constexpr unsigned int WideTextUR6GSServersMSClientServerConnected = 0x1006d440;
// R6GameService.dll wide-text @ 1006d5b8
constexpr unsigned int WideTextUR6GSServersExecNativeMSClientReqAltInfo = 0x1006d5b8;
// R6GameService.dll wide-text @ 1006d660
constexpr unsigned int WideTextUR6ServerListResetSvrContainer = 0x1006d660;
// R6GameService.dll wide-text @ 1006d6a8
constexpr unsigned int WideTextUR6GSServersExecSetLastServerQueried = 0x1006d6a8;
// R6GameService.dll wide-text @ 1006d6f8
constexpr unsigned int WideTextUR6GSServersProcessJoinServerRequest = 0x1006d6f8;
// R6GameService.dll wide-text @ 1006d748
constexpr unsigned int WideTextJOINSERVERREQSUCCESS = 0x1006d748;
// R6GameService.dll wide-text @ 1006d778
constexpr unsigned int WideTextUR6GSServersProcessUbiComJoinServer = 0x1006d778;
// R6GameService.dll wide-text @ 1006d7c8
constexpr unsigned int WideTextUR6GSServersProcessIsRouterDisconnect = 0x1006d7c8;
// R6GameService.dll scalar @ 1006d818
constexpr unsigned int NativeFloat5_0 = 0x1006d818;
// R6GameService.dll wide-text @ 1006d820
constexpr unsigned int WideTextUR6GSServersExecNativeIsRouterDisconnect = 0x1006d820;
// R6GameService.dll wide-text @ 1006d878
constexpr unsigned int WideTextUR6GSServersProcessIsLobbyDisconnect = 0x1006d878;
// R6GameService.dll wide-text @ 1006d8c8
constexpr unsigned int WideTextMSzUbiHomePageS = 0x1006d8c8;
// R6GameService.dll text @ 1006d8f4
constexpr unsigned int TextMaintenance = 0x1006d8f4;
// R6GameService.dll text @ 1006d900
constexpr unsigned int TextGS4UserAccountURL = 0x1006d900;
// R6GameService.dll wide-text @ 1006d914
constexpr unsigned int WideTextCDKeyPortI = 0x1006d914;
// R6GameService.dll wide-text @ 1006d938
constexpr unsigned int WideTextCDKeyNameS = 0x1006d938;
// R6GameService.dll wide-text @ 1006d95c
constexpr unsigned int WideTextCDKeyServerPort0 = 0x1006d95c;
// R6GameService.dll wide-text @ 1006d980
constexpr unsigned int WideTextCDKeyServerIP0 = 0x1006d980;
// R6GameService.dll wide-text @ 1006d9a0
constexpr unsigned int WideTextRouterPortI = 0x1006d9a0;
// R6GameService.dll wide-text @ 1006d9d4
constexpr unsigned int WideTextRouterLauncherPortI = 0x1006d9d4;
// R6GameService.dll wide-text @ 1006da08
constexpr unsigned int WideTextRouterNameS = 0x1006da08;
// R6GameService.dll text @ 1006da3c
constexpr unsigned int TextServers = 0x1006da3c;
// R6GameService.dll data @ 1006da44
constexpr unsigned int GEmptyWideTextAlternate = 0x1006da44;
// R6GameService.dll wide-text @ 1006da48
constexpr unsigned int WideTextRouterLauncherPortI2 = 0x1006da48;
// R6GameService.dll wide-text @ 1006da74
constexpr unsigned int WideTextRouterPortI2 = 0x1006da74;
// R6GameService.dll wide-text @ 1006da90
constexpr unsigned int WideTextRouterIPI = 0x1006da90;
// R6GameService.dll wide-text @ 1006daa8
constexpr unsigned int WideTextR = 0x1006daa8;
// R6GameService.dll wide-text @ 1006daac
constexpr unsigned int WideTextRemoteFileNameS = 0x1006daac;
// R6GameService.dll wide-text @ 1006dad4
constexpr unsigned int WideTextInitializeSocketsI = 0x1006dad4;
// R6GameService.dll wide-text @ 1006db08
constexpr unsigned int WideText0000 = 0x1006db08;
// R6GameService.dll data @ 1006db18
constexpr unsigned int GEmptyWideText = 0x1006db18;
// R6GameService.dll wide-text @ 1006db1c
constexpr unsigned int WideText02 = 0x1006db1c;
// R6GameService.dll text @ 1006db20
constexpr unsigned int TextTempDat = 0x1006db20;
// R6GameService.dll text @ 1006db24
constexpr unsigned int TextMpDat = 0x1006db24;
// R6GameService.dll text @ 1006db28
constexpr unsigned int TextAt = 0x1006db28;
// R6GameService.dll wide-text @ 1006db2c
constexpr unsigned int WideTextUR6GSServersExecInitialize = 0x1006db2c;
// R6GameService.dll wide-text @ 1006db68
constexpr unsigned int WideTextUR6ServerListExecNativeInitFavorites = 0x1006db68;
// R6GameService.dll wide-text @ 1006dbb8
constexpr unsigned int WideTextFavorites = 0x1006dbb8;
// R6GameService.dll wide-text @ 1006dbcc
constexpr unsigned int WideTextUser = 0x1006dbcc;
// R6GameService.dll text @ 1006dbd8
constexpr unsigned int TextFavServerI = 0x1006dbd8;
// R6GameService.dll wide-text @ 1006dbe8
constexpr unsigned int WideTextUR6ServerListExecNativeInitFavorites2 = 0x1006dbe8;
// R6GameService.dll wide-text @ 1006dc38
constexpr unsigned int WideTextUR6ServerListExecNativeUpdateFavorites = 0x1006dc38;
// R6GameService.dll wide-text @ 1006dc8c
constexpr unsigned int WideTextUR6ServerListExecSortServers = 0x1006dc8c;
// R6GameService.dll wide-text @ 1006dccc
constexpr unsigned int WideTextErrorSortTypeIsNotDefine = 0x1006dccc;
// R6GameService.dll wide-text @ 1006dd08
constexpr unsigned int WideTextErrorMGameServerListNumMGSLSortIdxNum = 0x1006dd08;
// R6GameService.dll text @ 1006dd70
constexpr unsigned int TextLibgscdkey = 0x1006dd70;
// R6GameService.dll text @ 1006dd7c
constexpr unsigned int TextLibgscrypto = 0x1006dd7c;
// R6GameService.dll text @ 1006dd88
constexpr unsigned int TextLibgsdatacontainer = 0x1006dd88;
// R6GameService.dll text @ 1006dd9c
constexpr unsigned int TextLibgscsp = 0x1006dd9c;
// R6GameService.dll text @ 1006dda8
constexpr unsigned int TextLibgsutility = 0x1006dda8;
// R6GameService.dll text @ 1006ddb8
constexpr unsigned int TextLibgssocket = 0x1006ddb8;
// R6GameService.dll text @ 1006ddc4
constexpr unsigned int TextLibgsresult = 0x1006ddc4;
// R6GameService.dll text @ 1006ddd0
constexpr unsigned int TextLibgsproxyclient = 0x1006ddd0;
// R6GameService.dll text @ 1006dde4
constexpr unsigned int TextLibgsconnect = 0x1006dde4;
// R6GameService.dll text @ 1006ddf4
constexpr unsigned int TextLibgsregserver = 0x1006ddf4;
// R6GameService.dll text @ 1006de04
constexpr unsigned int TextLibgsmsclient = 0x1006de04;
// R6GameService.dll text @ 1006de14
constexpr unsigned int TextLibgsclient = 0x1006de14;
// R6GameService.dll wide-text @ 1006de20
constexpr unsigned int WideTextUR6GSServersLogGSVersion = 0x1006de20;
// R6GameService.dll wide-text @ 1006de58
constexpr unsigned int WideTextUBIComGSVersionInfo = 0x1006de58;
// R6GameService.dll wide-text @ 1006de90
constexpr unsigned int WideTextCouldNotAllocateMemoryToRetrieveUBIComGSVersionInfo = 0x1006de90;
// R6GameService.dll wide-text @ 1006df18
constexpr unsigned int WideTextCouldNotFindTheUBIComGSVersionInfo = 0x1006df18;
// R6GameService.dll wide-text @ 1006df78
constexpr unsigned int WideTextUR6ServerListExecGetDisplayListSize = 0x1006df78;
// R6GameService.dll wide-text @ 1006dfc4
constexpr unsigned int WideTextUR6GSServersPlayerIsInIDList = 0x1006dfc4;
// R6GameService.dll wide-text @ 1006e008
constexpr unsigned int WideTextUR6GSServersGetGlobalIdFromPlayerIDList = 0x1006e008;
// R6GameService.dll wide-text @ 1006e05c
constexpr unsigned int WideTextUR6GSServersPollCallbacks = 0x1006e05c;
// R6GameService.dll wide-text @ 1006e098
constexpr unsigned int WideTextUR6GSServersInitializeMSClient = 0x1006e098;
// R6GameService.dll wide-text @ 1006e0e0
constexpr unsigned int WideTextUR6GSServersExecInitializeMSClient = 0x1006e0e0;
// R6GameService.dll wide-text @ 1006e12c
constexpr unsigned int WideTextCallbackMSGameServerS = 0x1006e12c;
// R6GameService.dll wide-text @ 1006e168
constexpr unsigned int WideTextAddAServerInTheListTotalWillBeD = 0x1006e168;
// R6GameService.dll wide-text @ 1006e1c0
constexpr unsigned int WideTextCallbackMSAlternateInfo = 0x1006e1c0;
// R6GameService.dll wide-text @ 1006e1f8
constexpr unsigned int WideTextUR6GSServersRefreshOneServer = 0x1006e1f8;
// R6GameService.dll wide-text @ 1006e238
constexpr unsigned int WideTextMSClientRefreshGameServers = 0x1006e238;
// R6GameService.dll wide-text @ 1006e280
constexpr unsigned int WideTextUR6GSServersExecNativeRefreshServer = 0x1006e280;
// R6GameService.dll wide-text @ 1006e2d0
constexpr unsigned int WideTextUR6GSServersExecNativeSetMatchResult = 0x1006e2d0;
// R6GameService.dll wide-text @ 1006e320
constexpr unsigned int WideTextExecNativeSetMatchResultNotSubmitingResults = 0x1006e320;
// R6GameService.dll wide-text @ 1006e380
constexpr unsigned int WideTextMSClientSetMatchResultSDDReturnedD = 0x1006e380;
// R6GameService.dll wide-text @ 1006e3f0
constexpr unsigned int WideTextGSClientSetMatchResultSDDReturnedSuccess = 0x1006e3f0;
// R6GameService.dll wide-text @ 1006e468
constexpr unsigned int WideTextGSClientERRORSetMatchResultSDDReturnedX = 0x1006e468;
// R6GameService.dll wide-text @ 1006e4e8
constexpr unsigned int WideTextUR6GSServersSubmitMatchResult = 0x1006e4e8;
// R6GameService.dll wide-text @ 1006e528
constexpr unsigned int WideTextMSClientSubmitMatchResultDDReturnedD = 0x1006e528;
// R6GameService.dll wide-text @ 1006e598
constexpr unsigned int WideTextGSClientSubmitMatchResultReturnedFailureCodeX = 0x1006e598;
// R6GameService.dll wide-text @ 1006e610
constexpr unsigned int WideTextNoNeedToWaitForMBWaitSubmitMatchReplyCallingProcessSubmitMatchResultRepl = 0x1006e610;
// R6GameService.dll wide-text @ 1006e6d8
constexpr unsigned int WideTextButWeNeedToWaitForMBWaitSubmitMatchReplyBeforeCallingProcessSubmitMatchR = 0x1006e6d8;
// R6GameService.dll wide-text @ 1006e7b8
constexpr unsigned int WideTextGSClientSubmitMatchResultReturnedSuccess = 0x1006e7b8;
// R6GameService.dll wide-text @ 1006e820
constexpr unsigned int WideTextUR6ServerListFillSvrContainer = 0x1006e820;
// R6GameService.dll wide-text @ 1006e860
constexpr unsigned int WideTextD02dBuildD = 0x1006e860;
// R6GameService.dll wide-text @ 1006e888
constexpr unsigned int WideTextSpace = 0x1006e888;
// R6GameService.dll wide-text @ 1006e890
constexpr unsigned int WideTextUR6GSServersProcessLoginMasterSrv = 0x1006e890;
// R6GameService.dll wide-text @ 1006e8d8
constexpr unsigned int WideTextRetry = 0x1006e8d8;
// R6GameService.dll wide-text @ 1006e8e4
constexpr unsigned int WideTextFailedToLogInToUbiCom = 0x1006e8e4;
// R6GameService.dll wide-text @ 1006e920
constexpr unsigned int WideTextUR6GSServersMasterServerManager = 0x1006e920;
// R6GameService.dll wide-text @ 1006e968
constexpr unsigned int WideTextUR6GSServersAddPlayerToIDList = 0x1006e968;
// R6GameService.dll wide-text @ 1006e9a8
constexpr unsigned int WideTextUR6GSServersReceiveServer = 0x1006e9a8;
// R6GameService.dll wide-text @ 1006e9e0
constexpr unsigned int WideTextI = 0x1006e9e0;
// R6GameService.dll wide-text @ 1006e9e8
constexpr unsigned int WideTextUR6GSServersInitMSClient = 0x1006e9e8;
// R6GameService.dll wide-text @ 1006ea20
constexpr unsigned int WideTextMSClientCouldNotConnectToServer = 0x1006ea20;
// R6GameService.dll wide-text @ 1006ea6c
constexpr unsigned int WideTextMSClientInitialized = 0x1006ea6c;
// R6GameService.dll wide-text @ 1006ea98
constexpr unsigned int WideTextMSClientInitializeMSzPasswordS = 0x1006ea98;
// R6GameService.dll wide-text @ 1006eaf8
constexpr unsigned int WideTextMSClientInitializeMSzUserIDS = 0x1006eaf8;
// R6GameService.dll wide-text @ 1006eb58
constexpr unsigned int WideTextMSClientInitializeIPortI = 0x1006eb58;
// R6GameService.dll wide-text @ 1006ebb8
constexpr unsigned int WideTextMSClientInitializeSzNameS = 0x1006ebb8;
// R6GameService.dll wide-text @ 1006ec18
constexpr unsigned int WideTextMSClientInitializeGIRouterIndexI = 0x1006ec18;
// R6GameService.dll wide-text @ 1006ec78
constexpr unsigned int WideTextUR6GSServersReceiveAltInfo = 0x1006ec78;
// R6GameService.dll wide-text @ 1006ecb8
constexpr unsigned int WideTextUR6GSServersProcessMSClientInitRequest = 0x1006ecb8;
// R6GameService.dll wide-text @ 1006ed0c
constexpr unsigned int WideTextLOGINSUCCESS = 0x1006ed0c;
// R6GameService.dll wide-text @ 1006ed28
constexpr unsigned int WideTextUR6GSServersRefreshServers = 0x1006ed28;
// R6GameService.dll wide-text @ 1006ed68
constexpr unsigned int WideTextMSClientRequestGameServersMSzGameServiceGameNameS = 0x1006ed68;
// R6GameService.dll wide-text @ 1006ede8
constexpr unsigned int WideTextUR6GSServersExecRefreshServers = 0x1006ede8;
// R6GameService.dll wide-text @ 1006ee30
constexpr unsigned int WideTextUR6GSServersGameServiceManager = 0x1006ee30;
// R6GameService.dll wide-text @ 1006ee74
constexpr unsigned int WideTextUR6GSServersUR6GSServers = 0x1006ee74;
// R6GameService.dll wide-text @ 1006ef3c
constexpr unsigned int WideTextUR6GSServersCreatedCDKey = 0x1006ef3c;
// R6GameService.dll wide-text @ 1006ef78
constexpr unsigned int WideTextSOFTWARERedStormEntertainmentRAVENSHIELD = 0x1006ef78;
// R6GameService.dll wide-text @ 1006efd4
constexpr unsigned int WideTextCDKey = 0x1006efd4;
// R6GameService.dll wide-text @ 1006efe0
constexpr unsigned int WideTextUR6ModGSInfoInitMODCDKey = 0x1006efe0;
// R6GameService.dll wide-text @ 1006f018
constexpr unsigned int WideTextSOFTWARERedStormEntertainment = 0x1006f018;
// R6GameService.dll wide-text @ 1006f05c
constexpr unsigned int WideTextUR6GSServersExecInitGSCDKey = 0x1006f05c;
// R6GameService.dll wide-text @ 1006f098
constexpr unsigned int WideTextUR6GSServersUnInitCDKey = 0x1006f098;
// R6GameService.dll wide-text @ 1006f0d0
constexpr unsigned int WideTextModCDKeyGSCDKeyUninitialize = 0x1006f0d0;
// R6GameService.dll wide-text @ 1006f120
constexpr unsigned int WideTextRSCDKeyGSCDKeyUninitialize = 0x1006f120;
// R6GameService.dll wide-text @ 1006f168
constexpr unsigned int WideTextUR6GSServersRequestActivation = 0x1006f168;
// R6GameService.dll wide-text @ 1006f1a8
constexpr unsigned int WideTextGSCDKeyRequestActivationS = 0x1006f1a8;
// R6GameService.dll text @ 1006f1f0
constexpr unsigned int TextRAVENSHIELD = 0x1006f1f0;
// R6GameService.dll text @ 1006f1f4
constexpr unsigned int TextNSHIELD = 0x1006f1f4;
// R6GameService.dll text @ 1006f1f8
constexpr unsigned int TextELD = 0x1006f1f8;
// R6GameService.dll wide-text @ 1006f1fc
constexpr unsigned int WideTextCDKEYNotValid = 0x1006f1fc;
// R6GameService.dll wide-text @ 1006f220
constexpr unsigned int WideTextUR6GSServersRequestAuthorization = 0x1006f220;
// R6GameService.dll wide-text @ 1006f268
constexpr unsigned int WideTextGSCDKeyRequestAuthorizationSD = 0x1006f268;
// R6GameService.dll wide-text @ 1006f2c0
constexpr unsigned int WideTextUR6GSServersGetAuthID = 0x1006f2c0;
// R6GameService.dll wide-text @ 1006f2f0
constexpr unsigned int WideTextUR6GSServersIsAuthIDSuccess = 0x1006f2f0;
// R6GameService.dll wide-text @ 1006f330
constexpr unsigned int WideTextMSzGameServiceMODGameNameS = 0x1006f330;
// R6GameService.dll wide-text @ 1006f370
constexpr unsigned int WideTextIsAuthIDSuccessIsRavenshieldD = 0x1006f370;
// R6GameService.dll text @ 1006f3bc
constexpr unsigned int TextS0X = 0x1006f3bc;
// R6GameService.dll text @ 1006f3c4
constexpr unsigned int TextS2x = 0x1006f3c4;
// R6GameService.dll wide-text @ 1006f3d0
constexpr unsigned int WideTextUR6GSServersCDKeyValidateUser = 0x1006f3d0;
// R6GameService.dll wide-text @ 1006f410
constexpr unsigned int WideTextGSCDKeyValidateUserS = 0x1006f410;
// R6GameService.dll wide-text @ 1006f450
constexpr unsigned int WideTextUR6GSServersEnterCDKey = 0x1006f450;
// R6GameService.dll wide-text @ 1006f488
constexpr unsigned int WideTextEnterCDKeyYouReAlreadyInAAuthIDRequest = 0x1006f488;
// R6GameService.dll wide-text @ 1006f4f8
constexpr unsigned int WideTextEnterCDKeyYouReAlreadyInAActIDRequest = 0x1006f4f8;
// R6GameService.dll wide-text @ 1006f568
constexpr unsigned int WideTextEnterCDKeyUnableToStartAnEnterCDKey = 0x1006f568;
// R6GameService.dll wide-text @ 1006f5c4
constexpr unsigned int WideTextEnterCDKeyGSzCDKeyS = 0x1006f5c4;
// R6GameService.dll wide-text @ 1006f5fc
constexpr unsigned int WideTextAndEncryptedCDKeyIsS = 0x1006f5fc;
// R6GameService.dll wide-text @ 1006f630
constexpr unsigned int WideTextEnterCDKeyMSzMODCDKeyS = 0x1006f630;
// R6GameService.dll wide-text @ 1006f670
constexpr unsigned int WideTextEnterCDKeyYouReInBModProcessD = 0x1006f670;
// R6GameService.dll wide-text @ 1006f6c0
constexpr unsigned int WideTextUR6GSServersExecEnterCDKey = 0x1006f6c0;
// R6GameService.dll wide-text @ 1006f700
constexpr unsigned int WideTextUR6GSServersRequestModCDKeyProcess = 0x1006f700;
// R6GameService.dll wide-text @ 1006f74c
constexpr unsigned int WideTextMODCDKEYREQUESTD = 0x1006f74c;
// R6GameService.dll wide-text @ 1006f778
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR = 0x1006f778;
// R6GameService.dll wide-text @ 1006f848
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR2 = 0x1006f848;
// R6GameService.dll wide-text @ 1006f920
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR3 = 0x1006f920;
// R6GameService.dll wide-text @ 1006fa10
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerModCDKeyStatusMECDKeyR4 = 0x1006fa10;
// R6GameService.dll wide-text @ 1006fae8
constexpr unsigned int WideTextLogDebugProcessCDKeyRequestForMOD = 0x1006fae8;
// R6GameService.dll wide-text @ 1006fb30
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ = 0x1006fb30;
// R6GameService.dll wide-text @ 1006fbf8
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ2 = 0x1006fbf8;
// R6GameService.dll wide-text @ 1006fcc8
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ3 = 0x1006fcc8;
// R6GameService.dll wide-text @ 1006fdb0
constexpr unsigned int WideTextProcessPCCDKeyRequestAPlayerControllerMStPlayerVerCDKeyStatusMECDKeyRequ4 = 0x1006fdb0;
// R6GameService.dll wide-text @ 1006fe80
constexpr unsigned int WideTextLogDebugProcessCDKeyRequestForRS = 0x1006fe80;
// R6GameService.dll wide-text @ 1006fec8
constexpr unsigned int WideTextENTERFct = 0x1006fec8;
// R6GameService.dll wide-text @ 1006fedc
constexpr unsigned int WideTextEXITFct = 0x1006fedc;
// R6GameService.dll wide-text @ 1006fef0
constexpr unsigned int WideTextCallbackRcvActivationIDErrorI = 0x1006fef0;
// R6GameService.dll wide-text @ 1006ff40
constexpr unsigned int WideTextCallbackIgnoreResultsFromRcvActivationID = 0x1006ff40;
// R6GameService.dll wide-text @ 1006ffa0
constexpr unsigned int WideText1CallbackRcvAuthorizationIDSuccessXErrorIdD = 0x1006ffa0;
// R6GameService.dll wide-text @ 10070020
constexpr unsigned int WideTextCallbackIgnoreResultsFromRcvAuthorizationID = 0x10070020;
// R6GameService.dll wide-text @ 10070088
constexpr unsigned int WideTextUR6GSServersPollClientCDKeyCallbacks = 0x10070088;
// R6GameService.dll wide-text @ 100700d8
constexpr unsigned int WideTextAUTHIDREQINTERROR = 0x100700d8;
// R6GameService.dll wide-text @ 10070104
constexpr unsigned int WideTextAUTHIDREQNOTCHALLENGED = 0x10070104;
// R6GameService.dll wide-text @ 10070138
constexpr unsigned int WideTextERRORCDKEYINTERNALERROR = 0x10070138;
// R6GameService.dll wide-text @ 10070178
constexpr unsigned int WideTextTIMEOUTERRORDonTLetPlayerJoinRemoteServer = 0x10070178;
// R6GameService.dll wide-text @ 100701e8
constexpr unsigned int WideTextTIMEOUTERRORLetPlayerJoinAnyway = 0x100701e8;
// R6GameService.dll wide-text @ 10070234
constexpr unsigned int WideTextMSzLastServerQueriedS = 0x10070234;
// R6GameService.dll wide-text @ 1007026c
constexpr unsigned int WideTextAUTHIDREQINUSEERROR = 0x1007026c;
// R6GameService.dll wide-text @ 100702a0
constexpr unsigned int WideText2CDKeyIsAlreadyInUseERROR = 0x100702a0;
// R6GameService.dll wide-text @ 100702e4
constexpr unsigned int WideTextAUTHIDREQSUCCESS = 0x100702e4;
// R6GameService.dll wide-text @ 10070310
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQSUCCESS = 0x10070310;
// R6GameService.dll wide-text @ 10070370
constexpr unsigned int WideTextAUTHIDREQFAILURE = 0x10070370;
// R6GameService.dll wide-text @ 10070398
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQFAILED = 0x10070398;
// R6GameService.dll wide-text @ 100703f8
constexpr unsigned int WideTextAUTHIDREQTIMEOUTERROR = 0x100703f8;
// R6GameService.dll wide-text @ 10070430
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQCONNECTFAILED = 0x10070430;
// R6GameService.dll wide-text @ 100704a0
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQINUSEFAILED = 0x100704a0;
// R6GameService.dll wide-text @ 1007050c
constexpr unsigned int WideTextAUTHIDREQTIMEOUT = 0x1007050c;
// R6GameService.dll wide-text @ 10070538
constexpr unsigned int WideTextAndGoingEMENUREQTIMEOUT = 0x10070538;
// R6GameService.dll wide-text @ 10070578
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQWAITINGFORRESPONSE = 0x10070578;
// R6GameService.dll wide-text @ 100705f8
constexpr unsigned int WideTextProcessCDKeyAuthorizationRequestEGSREQFIRSTPASSPassD = 0x100705f8;
// R6GameService.dll wide-text @ 10070670
constexpr unsigned int WideTextACTIDREQTIMEOUTERROR = 0x10070670;
// R6GameService.dll wide-text @ 100706a8
constexpr unsigned int WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQFAILEDAndMsgACTIDREQTIMEOUTER = 0x100706a8;
// R6GameService.dll wide-text @ 10070768
constexpr unsigned int WideText1ERRORCDKEYTIMEOUTGECDKeyActIDRequestEGSREQSUCCESSAndMsgEMENUREQTIMEOUT = 0x10070768;
// R6GameService.dll wide-text @ 10070818
constexpr unsigned int WideTextACTIDREQFAILINVALIDCDKEY = 0x10070818;
// R6GameService.dll wide-text @ 10070858
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYINVALIDCDKEY = 0x10070858;
// R6GameService.dll wide-text @ 100708e0
constexpr unsigned int WideTextACTIDREQFAILCDKEYUSED = 0x100708e0;
// R6GameService.dll wide-text @ 10070918
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndERRORCDKEYALREADYONLINE = 0x10070918;
// R6GameService.dll wide-text @ 100709a4
constexpr unsigned int WideTextACTIDREQFAILDEFAULT = 0x100709a4;
// R6GameService.dll wide-text @ 100709d8
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFAILEDAndDefault = 0x100709d8;
// R6GameService.dll wide-text @ 10070a40
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFAILED = 0x10070a40;
// R6GameService.dll wide-text @ 10070a94
constexpr unsigned int WideTextACTIDREQSUCCESS = 0x10070a94;
// R6GameService.dll wide-text @ 10070ac0
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQSUCCESS = 0x10070ac0;
// R6GameService.dll wide-text @ 10070b10
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQWAITINGFORRESPONSETimeoutPassed = 0x10070b10;
// R6GameService.dll wide-text @ 10070ba0
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSMSzGameServiceGameNameS = 0x10070ba0;
// R6GameService.dll wide-text @ 10070c30
constexpr unsigned int WideTextProcessCDKeyActIDRequestEGSREQFIRSTPASSTimeoutPassed = 0x10070c30;
// R6GameService.dll wide-text @ 10070cb0
constexpr unsigned int WideTextGECDKeyActIDRequestEGSREQFIRSTPASSPassD = 0x10070cb0;
// R6GameService.dll wide-text @ 10070d10
constexpr unsigned int WideTextGSCDKeyEngineFAILED = 0x10070d10;
// R6GameService.dll wide-text @ 10070d50
constexpr unsigned int WideTextRcvValidationResponseCallbackCalledEPLAYERUNKNOWN = 0x10070d50;
// R6GameService.dll wide-text @ 10070de0
constexpr unsigned int WideTextRcvValidationResponseCallbackCalledEPLAYERINVALID = 0x10070de0;
// R6GameService.dll wide-text @ 10070e70
constexpr unsigned int WideTextRcvValidationResponseCallbackCalledEPLAYERVALID = 0x10070e70;
// R6GameService.dll wide-text @ 10070f00
constexpr unsigned int WideTextCallbackRcvValidationResponseBTimeoutI = 0x10070f00;
// R6GameService.dll wide-text @ 10070f68
constexpr unsigned int WideTextCallbackRcvValidationResponseBSuceededI = 0x10070f68;
// R6GameService.dll wide-text @ 10070fd0
constexpr unsigned int WideTextCallbackRcvValidationResponseIReqIDI = 0x10070fd0;
// R6GameService.dll wide-text @ 10071038
constexpr unsigned int WideTextCallbackRcvValidationResponseEStatusI = 0x10071038;
// R6GameService.dll wide-text @ 100710a0
constexpr unsigned int WideTextRcvModValidationResponseCallbackCalledEPLAYERUNKNOWN = 0x100710a0;
// R6GameService.dll wide-text @ 10071138
constexpr unsigned int WideTextRcvModValidationResponseCallbackCalledEPLAYERINVALID = 0x10071138;
// R6GameService.dll wide-text @ 100711d0
constexpr unsigned int WideTextRcvModValidationResponseCallbackCalledEPLAYERVALID = 0x100711d0;
// R6GameService.dll wide-text @ 10071260
constexpr unsigned int WideTextCallbackRcvModValidationResponseBTimeoutI = 0x10071260;
// R6GameService.dll wide-text @ 100712d0
constexpr unsigned int WideTextCallbackRcvModValidationResponseBSuceededI = 0x100712d0;
// R6GameService.dll wide-text @ 10071340
constexpr unsigned int WideTextCallbackRcvModValidationResponseIReqIDI = 0x10071340;
// R6GameService.dll wide-text @ 100713b0
constexpr unsigned int WideTextCallbackRcvModValidationResponseEStatusI = 0x100713b0;
// R6GameService.dll wide-text @ 10071420
constexpr unsigned int WideTextCallbackRcvRSPlayerStatusRequestAuthidS = 0x10071420;
// R6GameService.dll wide-text @ 10071488
constexpr unsigned int WideTextCallbackRcvModPlayerStatusRequestAuthidS = 0x10071488;
// R6GameService.dll wide-text @ 100714f0
constexpr unsigned int WideTextUR6GSServersReceiveValidation = 0x100714f0;
// R6GameService.dll wide-text @ 10071530
constexpr unsigned int WideTextUR6GSServersInitCDKeySDK = 0x10071530;
// R6GameService.dll wide-text @ 10071568
constexpr unsigned int WideTextGSCDKeyInitializeFailed = 0x10071568;
// R6GameService.dll wide-text @ 100715ac
constexpr unsigned int WideTextGSCDKeyInitializeI = 0x100715ac;
// R6GameService.dll wide-text @ 100715e8
constexpr unsigned int WideTextUR6GSServersInitGSCDKey = 0x100715e8;
// R6GameService.dll wide-text @ 10071620
constexpr unsigned int WideTextUR6GSServersDisconnectAllCDKeyPlayers = 0x10071620;
// R6GameService.dll wide-text @ 10071670
constexpr unsigned int WideTextMODGSCDKeyEngineFAILED = 0x10071670;
// R6GameService.dll wide-text @ 100716b8
constexpr unsigned int WideTextRSGSCDKeyEngineFAILED = 0x100716b8;
// R6GameService.dll wide-text @ 100716f8
constexpr unsigned int WideTextModDisconnectAllCDKeyPlayersPucAuthIDS = 0x100716f8;
// R6GameService.dll wide-text @ 10071760
constexpr unsigned int WideTextRSDisconnectAllCDKeyPlayersPucAuthIDS = 0x10071760;
// R6GameService.dll wide-text @ 100717c8
constexpr unsigned int WideTextUR6GSServersCDKeyDisconnecUser = 0x100717c8;
// R6GameService.dll wide-text @ 10071810
constexpr unsigned int WideTextCDKeyDisconnecUserPucAuthIDS = 0x10071810;
// R6GameService.dll wide-text @ 10071868
constexpr unsigned int WideTextCDKeyDisconnecUserModAuthIdS = 0x10071868;
// R6GameService.dll wide-text @ 100718c0
constexpr unsigned int WideTextModGSCDKeyEngineFAILED = 0x100718c0;
// R6GameService.dll wide-text @ 10071908
constexpr unsigned int WideTextUR6GSServersNativeCDKeyPlayerStatusReply = 0x10071908;
// R6GameService.dll wide-text @ 10071960
constexpr unsigned int WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERUNKNOWNForAuthIdS = 0x10071960;
// R6GameService.dll wide-text @ 100719f8
constexpr unsigned int WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERINVALIDForAuthIdS = 0x100719f8;
// R6GameService.dll wide-text @ 10071a90
constexpr unsigned int WideTextGSCDKeyPlayerStatusReplyEStatusEPLAYERVALIDForAuthIdS = 0x10071a90;
// R6GameService.dll wide-text @ 10071b20
constexpr unsigned int WideTextGSCDKeyPlayerStatusReplyEStatusIForAuthIdS = 0x10071b20;
// R6GameService.dll wide-text @ 10071b98
constexpr unsigned int WideTextUR6GSServersProcessPCCDKeyRequest = 0x10071b98;
// R6GameService.dll wide-text @ 10071be8
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYVALIDMECDKeyStatusECDKEYSTPLAYERVALID = 0x10071be8;
// R6GameService.dll wide-text @ 10071c94
constexpr unsigned int WideTextCDKeyServerRefused = 0x10071c94;
// R6GameService.dll wide-text @ 10071cbc
constexpr unsigned int WideTextBannedIP = 0x10071cbc;
// R6GameService.dll wide-text @ 10071cd0
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSETIMEOUTFirstAttempt = 0x10071cd0;
// R6GameService.dll wide-text @ 10071d74
constexpr unsigned int WideTextServerAuthNotResponding = 0x10071d74;
// R6GameService.dll wide-text @ 10071da4
constexpr unsigned int WideTextTIMEOUTSecondAttempt = 0x10071da4;
// R6GameService.dll wide-text @ 10071de8
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE = 0x10071de8;
// R6GameService.dll wide-text @ 10071eb0
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYWAITINGFORRESPONSEPlayerStatusMECDKeyRequestE2 = 0x10071eb0;
// R6GameService.dll wide-text @ 10071f70
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMICDKeyReqIDD = 0x10071f70;
// R6GameService.dll wide-text @ 10072000
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSCDKeyValidateUser = 0x10072000;
// R6GameService.dll wide-text @ 10072078
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerIsInIDList = 0x10072078;
// R6GameService.dll wide-text @ 100720f0
constexpr unsigned int WideTextAPlayerControllerMSzIpAddrS = 0x100720f0;
// R6GameService.dll wide-text @ 10072138
constexpr unsigned int WideTextProcessPCCDKeyRequestECDKEYFIRSTPASSPlayerStatusMSzAuthorizationIDS = 0x10072138;
// R6GameService.dll wide-text @ 100721d8
constexpr unsigned int WideTextPunctuation5 = 0x100721d8;
// R6GameService.dll wide-text @ 100721dc
constexpr unsigned int WideTextECDKEYFIRSTPASSForS = 0x100721dc;
// R6GameService.dll wide-text @ 10072210
constexpr unsigned int WideTextUR6GSServersProcessAuthIdRequest = 0x10072210;
// R6GameService.dll wide-text @ 10072278
constexpr unsigned int WideTextCustomMod = 0x10072278;
// R6GameService.dll wide-text @ 1007228c
constexpr unsigned int WideTextIsACustomMod = 0x1007228c;
// R6GameService.dll wide-text @ 100722a8
constexpr unsigned int WideTextRavenshield = 0x100722a8;
// R6GameService.dll wide-text @ 100722c0
constexpr unsigned int WideTextIsRavenShield = 0x100722c0;
// R6GameService.dll wide-text @ 100722dc
constexpr unsigned int WideTextIronWrath = 0x100722dc;
// R6GameService.dll wide-text @ 100722f0
constexpr unsigned int WideTextAthenaSword = 0x100722f0;
// R6GameService.dll wide-text @ 10072308
constexpr unsigned int WideTextIsAnOfficialMod = 0x10072308;
// R6GameService.dll wide-text @ 10072328
constexpr unsigned int WideTextUR6GSServersGSClientPostMessage = 0x10072328;
// R6GameService.dll wide-text @ 1007236c
constexpr unsigned int WideTextMSGFGSWITCHTOGS = 0x1007236c;
// R6GameService.dll wide-text @ 10072398
constexpr unsigned int WideTextMSGFGCHSTACLIENTSESSIONAK = 0x10072398;
// R6GameService.dll wide-text @ 100723e0
constexpr unsigned int WideTextMSGFGCHSTAINITCLIENTSESSIONAK = 0x100723e0;
// R6GameService.dll wide-text @ 10072430
constexpr unsigned int WideTextMSGFGREADYTORECEIVECONNECTIONS = 0x10072430;
// R6GameService.dll wide-text @ 10072480
constexpr unsigned int WideTextMSGFGCHSTAMASTERSESSIONAK = 0x10072480;
// R6GameService.dll wide-text @ 100724c8
constexpr unsigned int WideTextMSGFGCHSTAINITMASTERSESSIONAK = 0x100724c8;
// R6GameService.dll wide-text @ 10072518
constexpr unsigned int WideTextSetGSGameStateOldStateIsD = 0x10072518;
// R6GameService.dll wide-text @ 10072560
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSSERVERREADY = 0x10072560;
// R6GameService.dll wide-text @ 100725c0
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSTERMINATERCVD = 0x100725c0;
// R6GameService.dll wide-text @ 10072620
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSSERVERSETTINGUPGAME = 0x10072620;
// R6GameService.dll wide-text @ 10072690
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSSERVERCHSTARCVD = 0x10072690;
// R6GameService.dll wide-text @ 100726f8
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSSERVERWAITINGCHSTA = 0x100726f8;
// R6GameService.dll wide-text @ 10072768
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSSERVERINITRCVD = 0x10072768;
// R6GameService.dll wide-text @ 100727d0
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSCLIENTINGAME = 0x100727d0;
// R6GameService.dll wide-text @ 10072830
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSCLIENTCHSTARCVD = 0x10072830;
// R6GameService.dll wide-text @ 10072898
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSCLIENTWAITINGCHSTA = 0x10072898;
// R6GameService.dll wide-text @ 10072908
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSCLIENTINITRCVD = 0x10072908;
// R6GameService.dll wide-text @ 10072970
constexpr unsigned int WideTextSetGSGameStateOldStateIsEGSWAITINGFORGSINIT = 0x10072970;
// R6GameService.dll wide-text @ 100729d8
constexpr unsigned int WideTextSetGSGameStateNewStateIsD = 0x100729d8;
// R6GameService.dll wide-text @ 10072a20
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSSERVERREADY = 0x10072a20;
// R6GameService.dll wide-text @ 10072a80
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSTERMINATERCVD = 0x10072a80;
// R6GameService.dll wide-text @ 10072ae0
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSSERVERSETTINGUPGAME = 0x10072ae0;
// R6GameService.dll wide-text @ 10072b50
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSSERVERCHSTARCVD = 0x10072b50;
// R6GameService.dll wide-text @ 10072bb8
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSSERVERWAITINGCHSTA = 0x10072bb8;
// R6GameService.dll wide-text @ 10072c28
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSSERVERINITRCVD = 0x10072c28;
// R6GameService.dll wide-text @ 10072c90
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSCLIENTINGAME = 0x10072c90;
// R6GameService.dll wide-text @ 10072cf0
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSCLIENTCHSTARCVD = 0x10072cf0;
// R6GameService.dll wide-text @ 10072d58
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSCLIENTWAITINGCHSTA = 0x10072d58;
// R6GameService.dll wide-text @ 10072dc8
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSCLIENTINITRCVD = 0x10072dc8;
// R6GameService.dll wide-text @ 10072e30
constexpr unsigned int WideTextSetGSGameStateNewStateIsEGSWAITINGFORGSINIT = 0x10072e30;
// R6GameService.dll wide-text @ 10072e98
constexpr unsigned int WideTextUR6GSServersExecNativeIsWaitingForGSInit = 0x10072e98;
// R6GameService.dll wide-text @ 10072ef0
constexpr unsigned int WideTextUR6GSServersExecNativeIsGSReadyToChangeMod = 0x10072ef0;
// R6GameService.dll wide-text @ 10072f50
constexpr unsigned int WideTextUR6GSServersSetGSClientComInterface = 0x10072f50;
// R6GameService.dll wide-text @ 10072fa0
constexpr unsigned int WideTextCannotFindTheScoreSubmissionService = 0x10072fa0;
// R6GameService.dll wide-text @ 10073008
constexpr unsigned int WideTextCannotFindTheScoreSubmissionServiceHResX = 0x10073008;
// R6GameService.dll wide-text @ 10073088
constexpr unsigned int WideTextGSClientPlayerMatchFinishedReturnedSUCCESS = 0x10073088;
// R6GameService.dll wide-text @ 100730f8
constexpr unsigned int WideTextGSClientERRORPlayerMatchFinishedErrorX = 0x100730f8;
// R6GameService.dll wide-text @ 10073160
constexpr unsigned int WideTextGSClientCallingPlayerMatchFinished = 0x10073160;
// R6GameService.dll wide-text @ 100731b8
constexpr unsigned int WideTextGSClientClearMatchResultReturnedX = 0x100731b8;
// R6GameService.dll wide-text @ 10073218
constexpr unsigned int WideTextUR6GSServersPollGSClientCallbacks = 0x10073218;
// R6GameService.dll wide-text @ 10073260
constexpr unsigned int WideTextGSClientERRORCheckSubmitMatchReplyErrorX = 0x10073260;
// R6GameService.dll wide-text @ 100732d0
constexpr unsigned int WideTextGSClientCheckSubmitMatchReplySuccessfull = 0x100732d0;
// R6GameService.dll wide-text @ 10073338
constexpr unsigned int WideTextGSClientCheckSubmitMatchReplyReturnedCodeX = 0x10073338;
// R6GameService.dll wide-text @ 100733a8
constexpr unsigned int WideTextGSClientERRORWaitMatchStartedErrorX = 0x100733a8;
// R6GameService.dll wide-text @ 10073410
constexpr unsigned int WideTextGSClientInitMatchResultsReturnedSUCCESS = 0x10073410;
// R6GameService.dll wide-text @ 10073480
constexpr unsigned int WideTextGSClientERRORInitMatchResultsErrorX = 0x10073480;
// R6GameService.dll wide-text @ 100734e8
constexpr unsigned int WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingInitMatchResults = 0x100734e8;
// R6GameService.dll wide-text @ 10073590
constexpr unsigned int WideTextGSClientPlayerMatchStartedReturnedSUCCESS = 0x10073590;
// R6GameService.dll wide-text @ 10073600
constexpr unsigned int WideTextGSClientERRORPlayerMatchStartedErrorX = 0x10073600;
// R6GameService.dll wide-text @ 10073668
constexpr unsigned int WideTextGSClientWaitMatchStartedCBReceivedSUCCESSCallingPlayerMatchStarted = 0x10073668;
// R6GameService.dll wide-text @ 10073710
constexpr unsigned int WideTextGSClientSERVERCheckStartMatchReplyCBReceivedSUCCESSResultCodeIsX = 0x10073710;
// R6GameService.dll wide-text @ 100737b8
constexpr unsigned int WideTextGSClientSERVERERRORCheckStartMatchReplyGSEMATCHNOTFINISHED = 0x100737b8;
// R6GameService.dll wide-text @ 10073848
constexpr unsigned int WideTextGSClientSERVERERRORCheckStartMatchReplyX = 0x10073848;
// R6GameService.dll wide-text @ 100738b8
constexpr unsigned int WideTextGSClientSERVERNOREPLYCheckStartMatchReplyGSENOREPLY = 0x100738b8;
// R6GameService.dll wide-text @ 10073940
constexpr unsigned int WideTextGSClientSERVERERRORCheckStartMatchReplyGSEFAIL = 0x10073940;
// R6GameService.dll wide-text @ 100739b8
constexpr unsigned int WideTextGSClientSERVERERRORCheckStartMatchReplyGSENOTMASTER = 0x100739b8;
// R6GameService.dll text @ 10073a38
constexpr unsigned int TextSI = 0x10073a38;
// R6GameService.dll wide-text @ 10073a40
constexpr unsigned int WideTextUR6GSServersGSClientUpdateServerInfo = 0x10073a40;
// R6GameService.dll wide-text @ 10073a90
constexpr unsigned int WideTextSetPrivateGameConfigError = 0x10073a90;
// R6GameService.dll wide-text @ 10073ad0
constexpr unsigned int WideTextGetCopyPrivateError = 0x10073ad0;
// R6GameService.dll wide-text @ 10073b08
constexpr unsigned int WideTextSetPublicGameConfigError = 0x10073b08;
// R6GameService.dll wide-text @ 10073b48
constexpr unsigned int WideTextGetCopyPublicError = 0x10073b48;
// R6GameService.dll wide-text @ 10073b80
constexpr unsigned int WideTextCannotFindTheInterfaceForGameConfigService = 0x10073b80;
// R6GameService.dll wide-text @ 10073c00
constexpr unsigned int WideTextCannotFindTheGameConfigService = 0x10073c00;
// R6GameService.dll wide-text @ 10073c68
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSREADYTORECEIVECONNECTIONSAK = 0x10073c68;
// R6GameService.dll wide-text @ 10073ce8
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSERRORI = 0x10073ce8;
// R6GameService.dll wide-text @ 10073d40
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSSWITCHTOGSAK = 0x10073d40;
// R6GameService.dll wide-text @ 10073da0
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSCHSTATERMINATE = 0x10073da0;
// R6GameService.dll wide-text @ 10073e08
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSCHSTACLIENTSESSION = 0x10073e08;
// R6GameService.dll wide-text @ 10073e78
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSCHSTAMASTERSESSION = 0x10073e78;
// R6GameService.dll wide-text @ 10073ee8
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSCHSTAINITCLIENTSESSION = 0x10073ee8;
// R6GameService.dll wide-text @ 10073f60
constexpr unsigned int WideTextCallbackDispatcherProcMDwGamePortI = 0x10073f60;
// R6GameService.dll wide-text @ 10073fc0
constexpr unsigned int WideTextCallbackDispatcherProcMCzSecondaryGameServerIPS = 0x10073fc0;
// R6GameService.dll wide-text @ 10074038
constexpr unsigned int WideTextCallbackDispatcherProcMCzPrimaryGameServerIPS = 0x10074038;
// R6GameService.dll wide-text @ 100740a8
constexpr unsigned int WideTextCallbackDispatcherProcMUnMaxPlayerI = 0x100740a8;
// R6GameService.dll wide-text @ 10074108
constexpr unsigned int WideTextCallbackDispatcherProcMCzRoomNameS = 0x10074108;
// R6GameService.dll wide-text @ 10074168
constexpr unsigned int WideTextCallbackDispatcherProcMCzUserPasswordS = 0x10074168;
// R6GameService.dll wide-text @ 100741d0
constexpr unsigned int WideTextCallbackDispatcherProcMNGroupIDI = 0x100741d0;
// R6GameService.dll wide-text @ 10074228
constexpr unsigned int WideTextCallbackDispatcherProcMNLobbyServerIDI = 0x10074228;
// R6GameService.dll wide-text @ 10074290
constexpr unsigned int WideTextCallbackDispatcherProcMCzRoomPasswordS = 0x10074290;
// R6GameService.dll wide-text @ 100742f8
constexpr unsigned int WideTextCallbackDispatcherProcMCzUserNameS = 0x100742f8;
// R6GameService.dll wide-text @ 10074358
constexpr unsigned int WideTextCallbackDispatcherProcMCzGameNameS = 0x10074358;
// R6GameService.dll wide-text @ 100743b8
constexpr unsigned int WideTextCallbackDispatcherProcMSGFGSCHSTAINITMASTERSESSION = 0x100743b8;
// R6GameService.dll wide-text @ 10074430
constexpr unsigned int WideTextCallbackDispatcherProcMDwMsgIDI = 0x10074430;
// R6GameService.dll wide-text @ 10074484
constexpr unsigned int WideTextUR6GSServersInitGSClient = 0x10074484;
// R6GameService.dll wide-text @ 100744c0
constexpr unsigned int WideTextGSClientSPWGSCConnectI = 0x100744c0;
// R6GameService.dll wide-text @ 10074508
constexpr unsigned int WideTextGSClientSPWGSCInitializeI = 0x10074508;
// R6GameService.dll wide-text @ 10074570
constexpr unsigned int WideTextLoggedOffFromUbiComRegServerService = 0x10074570;
// R6GameService.dll wide-text @ 100745c8
constexpr unsigned int WideTextREGSERVERRegServerLibraryUninitialize = 0x100745c8;
// R6GameService.dll wide-text @ 10074628
constexpr unsigned int WideTextREGSERVERRegServerSendLobbyServerCloseFromUR6GSServersUnInitRegServer = 0x10074628;
// R6GameService.dll wide-text @ 100746d4
constexpr unsigned int WideTextUR6GSServersLogOutServer = 0x100746d4;
// R6GameService.dll wide-text @ 10074710
constexpr unsigned int WideTextUR6GSServersExecNativeLogOutServer = 0x10074710;
// R6GameService.dll wide-text @ 1007475c
constexpr unsigned int WideTextUR6GSServersRegisterServer = 0x1007475c;
// R6GameService.dll wide-text @ 10074798
constexpr unsigned int WideTextRegServerSendRegisterServerOnLobbyI = 0x10074798;
// R6GameService.dll wide-text @ 100747f8
constexpr unsigned int WideTextUR6GSServersUpdateServer = 0x100747f8;
// R6GameService.dll wide-text @ 10074830
constexpr unsigned int WideTextRegServerSendUpdateGroupSettingsI = 0x10074830;
// R6GameService.dll wide-text @ 10074890
constexpr unsigned int WideTextUR6GSServersExecNativeUpdateServer = 0x10074890;
// R6GameService.dll wide-text @ 100748dc
constexpr unsigned int WideTextUR6GSServersServerLogin = 0x100748dc;
// R6GameService.dll wide-text @ 10074910
constexpr unsigned int WideTextRegServerSendLobbyServerLogin = 0x10074910;
// R6GameService.dll wide-text @ 10074960
constexpr unsigned int WideTextRegServerSendLobbyServerConnection = 0x10074960;
// R6GameService.dll wide-text @ 100749b8
constexpr unsigned int WideTextS = 0x100749b8;
// R6GameService.dll wide-text @ 100749c8
constexpr unsigned int WideTextRegServerSendLoginRouter = 0x100749c8;
// R6GameService.dll wide-text @ 10074a0c
constexpr unsigned int WideTextUR6GSServersRouterDisconnect = 0x10074a0c;
// R6GameService.dll wide-text @ 10074a50
constexpr unsigned int WideTextRegServerSendRouterDisconnect = 0x10074a50;
// R6GameService.dll wide-text @ 10074aa0
constexpr unsigned int WideTextUR6GSServersRegServerGetLobbies = 0x10074aa0;
// R6GameService.dll wide-text @ 10074ae8
constexpr unsigned int WideTextRegServerSendRequestParentGroupOnLobby = 0x10074ae8;
// R6GameService.dll wide-text @ 10074b48
constexpr unsigned int WideTextUR6GSServersExecHandleAnyLobbyConnectionFail = 0x10074b48;
// R6GameService.dll wide-text @ 10074ba8
constexpr unsigned int WideTextUR6GSServersInitProcessUpdateUbiServer = 0x10074ba8;
// R6GameService.dll wide-text @ 10074c00
constexpr unsigned int WideTextUR6GSServersProcessRegServerLoginRouterRequest = 0x10074c00;
// R6GameService.dll wide-text @ 10074c68
constexpr unsigned int WideTextUR6GSServersProcessRegServerGetLobbiesRequest = 0x10074c68;
// R6GameService.dll wide-text @ 10074cc8
constexpr unsigned int WideTextUR6GSServersProcessRegServerRegOnLobbyRequest = 0x10074cc8;
// R6GameService.dll wide-text @ 10074d28
constexpr unsigned int WideTextUR6GSServersProcessRegServerLoginRequest = 0x10074d28;
// R6GameService.dll wide-text @ 10074d80
constexpr unsigned int WideTextUR6GSServersProcessRegServerUpdateRequest = 0x10074d80;
// R6GameService.dll wide-text @ 10074dd8
constexpr unsigned int WideTextRegServerRcvLobbyServerMatchStartReplyFailedIReasonD = 0x10074dd8;
// R6GameService.dll wide-text @ 10074e60
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerMatchStartReply = 0x10074e60;
// R6GameService.dll wide-text @ 10074ec8
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerMatchFinishReply = 0x10074ec8;
// R6GameService.dll wide-text @ 10074f38
constexpr unsigned int WideTextCallbackRegServerRcvLoginRouterResultFailedReasonI = 0x10074f38;
// R6GameService.dll wide-text @ 10074fb8
constexpr unsigned int WideTextCallbackRegServerRcvLoginRouterResult = 0x10074fb8;
// R6GameService.dll wide-text @ 10075010
constexpr unsigned int WideTextCallbackRegServerRcvLoginDisconnection = 0x10075010;
// R6GameService.dll wide-text @ 10075068
constexpr unsigned int WideTextCallbackRegServerRcvRegisterServerResultFailedReasonI = 0x10075068;
// R6GameService.dll wide-text @ 100750e8
constexpr unsigned int WideTextCallbackRegServerRcvRegisterServerResultSII = 0x100750e8;
// R6GameService.dll wide-text @ 100752f0
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerUpdateGroupSettingsResultsI = 0x100752f0;
// R6GameService.dll wide-text @ 10075378
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerDisconnection = 0x10075378;
// R6GameService.dll wide-text @ 100753e0
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerNewMemberS = 0x100753e0;
// R6GameService.dll wide-text @ 10075444
constexpr unsigned int WideTextUR6GSServersServerRoundStart = 0x10075444;
// R6GameService.dll wide-text @ 10075488
constexpr unsigned int WideTextRegServerSendMatchStartDReturnedD = 0x10075488;
// R6GameService.dll wide-text @ 100754e8
constexpr unsigned int WideTextGSClientSERVERStartMatchDReturnedSUCCESSCodeX = 0x100754e8;
// R6GameService.dll wide-text @ 10075568
constexpr unsigned int WideTextGSClientSERVERStartMatchDReturnedFAILEDCodeX = 0x10075568;
// R6GameService.dll wide-text @ 100755e8
constexpr unsigned int WideTextUR6GSServersServerRoundFinish = 0x100755e8;
// R6GameService.dll wide-text @ 10075628
constexpr unsigned int WideTextRegServerSendMatchFinishReturnedD = 0x10075628;
// R6GameService.dll wide-text @ 10075688
constexpr unsigned int WideTextGSClientSERVERMatchFinishReturnedSUCCESSCodeX = 0x10075688;
// R6GameService.dll wide-text @ 10075708
constexpr unsigned int WideTextGSClientSERVERMatchFinishReturnedFAILEDCodeX = 0x10075708;
// R6GameService.dll wide-text @ 10075780
constexpr unsigned int WideTextCallbackRegServerRcvRequestParentGroupResultIGroupIDI = 0x10075780;
// R6GameService.dll wide-text @ 10075808
constexpr unsigned int WideTextCallbackRegServerRcvRequestParentGroupResultILobbySrvIDI = 0x10075808;
// R6GameService.dll wide-text @ 10075890
constexpr unsigned int WideTextUR6GSServersInitializeRegServer = 0x10075890;
// R6GameService.dll wide-text @ 100758d8
constexpr unsigned int WideTextResServerCouldNotConnectToServer = 0x100758d8;
// R6GameService.dll wide-text @ 10075928
constexpr unsigned int WideTextRegServerSendRouterConnectI = 0x10075928;
// R6GameService.dll wide-text @ 10075978
constexpr unsigned int WideTextRegServerLibraryInitialize = 0x10075978;
// R6GameService.dll wide-text @ 100759c0
constexpr unsigned int WideTextUR6GSServersProcessInternetSrv = 0x100759c0;
// R6GameService.dll wide-text @ 10075a04
constexpr unsigned int WideTextTryAgainTimeF = 0x10075a04;
// R6GameService.dll scalar @ 10075a28
constexpr unsigned int NativeFloat15_0 = 0x10075a28;
// R6GameService.dll wide-text @ 10075a30
constexpr unsigned int WideTextServerRegisteredWithUbiComMasterServer = 0x10075a30;
// R6GameService.dll wide-text @ 10075a8c
constexpr unsigned int WideTextUbiGuest = 0x10075a8c;
// R6GameService.dll wide-text @ 10075ac0
constexpr unsigned int WideTextServerPingGetPingTime = 0x10075ac0;
// R6GameService.dll wide-text @ 10075af0
constexpr unsigned int WideTextServerPingNewPingRequest = 0x10075af0;
// R6GameService.dll wide-text @ 10075b28
constexpr unsigned int WideTextPunctuation6 = 0x10075b28;
// R6GameService.dll wide-text @ 10075b2c
constexpr unsigned int WideTextServerPingSendPingToServer = 0x10075b2c;
// R6GameService.dll wide-text @ 10075b68
constexpr unsigned int WideTextServerPingPingManager = 0x10075b68;
// R6GameService.dll vtable @ 10075b9c
constexpr unsigned int clPointerMap_PAXPAVCHttpDownloadVTable = 0x10075b9c;
// R6GameService.dll vtable @ 10075bbc
constexpr unsigned int clTCPClientVTable = 0x10075bbc;
// R6GameService.dll vtable @ 10075bcc
constexpr unsigned int CHttpRequestVTable = 0x10075bcc;
// R6GameService.dll vtable @ 10075bdc
constexpr unsigned int clExtalloc_Override_BaseclassVTable = 0x10075bdc;
// R6GameService.dll vtable @ 10075bec
constexpr unsigned int CHttpDownloadVTable = 0x10075bec;
// R6GameService.dll vtable @ 10075c04
constexpr unsigned int out_of_range__STLVTable = 0x10075c04;
// R6GameService.dll vtable @ 10075c10
constexpr unsigned int logic_error__STLVTable = 0x10075c10;
// R6GameService.dll vtable @ 10075c1c
constexpr unsigned int Named_exception__STLVTable = 0x10075c1c;
// R6GameService.dll vtable @ 10075c28
constexpr unsigned int length_error__STLVTable = 0x10075c28;
// R6GameService.dll vtable @ 10075c3c
constexpr unsigned int CDataContainer_GSDataContainerVTable = 0x10075c3c;
// R6GameService.dll data @ 10075c88
constexpr unsigned int DeflateLevelConfigurations = 0x10075c88;
// R6GameService.dll data-interior @ 10075c90
constexpr unsigned int DeflateLevelConfigurationCompressor = 0x10075c90;
// R6GameService.dll data @ 10075d00
constexpr unsigned int InflateCodeLengthOrder = 0x10075d00;
// R6GameService.dll data @ 10075d50
constexpr unsigned int DeflateLengthExtraBits = 0x10075d50;
// R6GameService.dll data @ 10075dc8
constexpr unsigned int DeflateDistanceExtraBits = 0x10075dc8;
// R6GameService.dll data @ 10075e40
constexpr unsigned int DeflateBitLengthExtraBits = 0x10075e40;
// R6GameService.dll data @ 10075e8c
constexpr unsigned int DeflateBitLengthOrder = 0x10075e8c;
// R6GameService.dll data @ 10075ea0
constexpr unsigned int DeflateFixedLiteralCodes = 0x10075ea0;
// R6GameService.dll data @ 10076320
constexpr unsigned int DeflateFixedDistanceCodes = 0x10076320;
// R6GameService.dll data @ 10076398
constexpr unsigned int DeflateDistanceCodes = 0x10076398;
// R6GameService.dll data @ 10076598
constexpr unsigned int DeflateLengthCodes = 0x10076598;
// R6GameService.dll data @ 10076698
constexpr unsigned int DeflateLengthBases = 0x10076698;
// R6GameService.dll data @ 10076710
constexpr unsigned int DeflateDistanceBases = 0x10076710;
// R6GameService.dll data @ 100767b8
constexpr unsigned int InflateLengthBases = 0x100767b8;
// R6GameService.dll data @ 10076838
constexpr unsigned int InflateLengthExtraBits = 0x10076838;
// R6GameService.dll data @ 100768b8
constexpr unsigned int InflateDistanceBases = 0x100768b8;
// R6GameService.dll data @ 10076930
constexpr unsigned int InflateDistanceExtraBits = 0x10076930;
// R6GameService.dll vtable @ 100769ac
constexpr unsigned int clPointerMap_PAXPAVCCDKeyProcessVTable = 0x100769ac;
// R6GameService.dll vtable @ 100769d4
constexpr unsigned int CCDKeyProcessVTable = 0x100769d4;
// R6GameService.dll data @ 10076a0c
constexpr unsigned int clDataListPTR_FUN2 = 0x10076a0c;
// R6GameService.dll data @ 10076a28
constexpr unsigned int clDataListPTR_LAB = 0x10076a28;
// R6GameService.dll data @ 10076a44
constexpr unsigned int clDataListPTR_FUN = 0x10076a44;
// R6GameService.dll data @ 10076a64
constexpr unsigned int PTR_LAB = 0x10076a64;
// R6GameService.dll data @ 10076a7c
constexpr unsigned int ClDataListInnerBaseOffsets = 0x10076a7c;
// R6GameService.dll data @ 10076a84
constexpr unsigned int ClDataListBaseOffsets = 0x10076a84;
// R6GameService.dll scalar @ 10076a90
constexpr unsigned int NativeDouble25_0 = 0x10076a90;
// R6GameService.dll vtable @ 10076ab4
constexpr unsigned int CMessageBufferVTable = 0x10076ab4;
// R6GameService.dll vtable @ 10076acc
constexpr unsigned int clCDKeyMessageVTable = 0x10076acc;
// R6GameService.dll vtable @ 10076ad4
constexpr unsigned int clDataRefVTable = 0x10076ad4;
// R6GameService.dll vtable @ 10076af8
constexpr unsigned int clDataStrRefVTable = 0x10076af8;
// R6GameService.dll vtable @ 10076b1c
constexpr unsigned int clDataLongVTable = 0x10076b1c;
// R6GameService.dll data @ 10076b40
constexpr unsigned int clDataBinPTR_FUN = 0x10076b40;
// R6GameService.dll data @ 10076b60
constexpr unsigned int ClDataBinBaseOffsets = 0x10076b60;
// R6GameService.dll data @ 10076b68
constexpr unsigned int ClDataBinOwnerBaseOffsets = 0x10076b68;
// R6GameService.dll data @ 10076b74
constexpr unsigned int clDataStrPTR_FUN = 0x10076b74;
// R6GameService.dll data @ 10076b8c
constexpr unsigned int ClDataStrBaseOffsets = 0x10076b8c;
// R6GameService.dll text @ 10076b9c
constexpr unsigned int TextSLb = 0x10076b9c;
// R6GameService.dll text @ 10076b9d
constexpr unsigned int TextSLb2 = 0x10076b9d;
// R6GameService.dll text @ 10076b9e
constexpr unsigned int TextSLb3 = 0x10076b9e;
// R6GameService.dll text @ 10076b9f
constexpr unsigned int TextLb = 0x10076b9f;
// R6GameService.dll wide-text @ 10076ba0
constexpr unsigned int WideTextB3 = 0x10076ba0;
// R6GameService.dll vtable @ 10076bb0
constexpr unsigned int clDataSerializeVTable = 0x10076bb0;
// R6GameService.dll text @ 10076bb4
constexpr unsigned int TextSKJDHF0maoijfn4i8AJdnv1jaldifar93ASDfoHjhC4jhflasnF3fnd = 0x10076bb4;
// R6GameService.dll vtable @ 10076bfc
constexpr unsigned int clSimpleMessageVTable = 0x10076bfc;
// R6GameService.dll data @ 10076c10
constexpr unsigned int GSocketContextBaseOffsets = 0x10076c10;
// R6GameService.dll vtable @ 10076c1c
constexpr unsigned int clTCPProtocolVTable = 0x10076c1c;
// R6GameService.dll data @ 10076c28
constexpr unsigned int GDatagramOwnerData = 0x10076c28;
// R6GameService.dll vtable @ 10076c34
constexpr unsigned int clFifoVTable = 0x10076c34;
// R6GameService.dll vtable @ 10076c58
constexpr unsigned int clPointerList_PAVclMemoryElementVTable = 0x10076c58;
// R6GameService.dll vtable @ 10076c7c
constexpr unsigned int CRegisterServerCBVTableAdjusted368 = 0x10076c7c;
// R6GameService.dll vtable @ 10076c84
constexpr unsigned int CRegisterServerCBVTable = 0x10076c84;
// R6GameService.dll data @ 10076cc4
constexpr unsigned int GRegistrationSecondaryOffsets = 0x10076cc4;
// R6GameService.dll data @ 10076ccc
constexpr unsigned int GRegistrationBaseOffsets = 0x10076ccc;
// R6GameService.dll vtable @ 10076cdc
constexpr unsigned int CRegisterServerVTable = 0x10076cdc;
// R6GameService.dll vtable @ 10076d28
constexpr unsigned int clParentGroupsVTable = 0x10076d28;
// R6GameService.dll vtable @ 10076d4c
constexpr unsigned int clPointerList_PAVclParentGroupVTable = 0x10076d4c;
// R6GameService.dll vtable @ 10076d78
constexpr unsigned int clMSClientClassVTableAdjusted16 = 0x10076d78;
// R6GameService.dll vtable @ 10076d80
constexpr unsigned int clMSClientClassVTableAdjusted12 = 0x10076d80;
// R6GameService.dll vtable @ 10076d94
constexpr unsigned int clMSClientClassVTableAdjusted8 = 0x10076d94;
// R6GameService.dll vtable @ 10076e4c
constexpr unsigned int clMSClientClassVTableAdjusted4 = 0x10076e4c;
// R6GameService.dll vtable @ 10076e94
constexpr unsigned int clMSClientClassVTable = 0x10076e94;
// R6GameService.dll vtable @ 10076ef4
constexpr unsigned int clMSClientVTableAdjusted16 = 0x10076ef4;
// R6GameService.dll vtable @ 10076efc
constexpr unsigned int clMSClientVTableAdjusted12 = 0x10076efc;
// R6GameService.dll vtable @ 10076f14
constexpr unsigned int clMSClientVTableAdjusted8 = 0x10076f14;
// R6GameService.dll vtable @ 10076fcc
constexpr unsigned int clMSClientVTableAdjusted4 = 0x10076fcc;
// R6GameService.dll vtable @ 10077014
constexpr unsigned int clMSClientVTable = 0x10077014;
// R6GameService.dll data @ 10077088
constexpr unsigned int GArrayUnwindScope = 0x10077088;
// R6GameService.dll data @ 10077098
constexpr unsigned int GArrayDestructorScope = 0x10077098;
// R6GameService.dll data @ 100770a8
constexpr unsigned int GTypeInfoDeletingDestructorSlot = 0x100770a8;
// R6GameService.dll data @ 100770b0
constexpr unsigned int GCrtDllNotificationScope = 0x100770b0;
// R6GameService.dll data @ 100770c0
constexpr unsigned int GRtcInitializeScope = 0x100770c0;
// R6GameService.dll data @ 100770d0
constexpr unsigned int GRtcTerminationScope = 0x100770d0;
// R6GameService.dll data @ 100770dc
constexpr unsigned int GLogicErrorVtable = 0x100770dc;
// R6GameService.dll data @ 100770e4
constexpr unsigned int GLengthErrorVtable = 0x100770e4;
// R6GameService.dll data @ 100770ec
constexpr unsigned int GVectorLengthDiagnostic = 0x100770ec;
// R6GameService.dll text @ 10077100
constexpr unsigned int TextS = 0x10077100;
// R6GameService.dll data @ 10077108
constexpr unsigned int GRpcStateScope = 0x10077108;
// R6GameService.dll data @ 10077118
constexpr unsigned int GRpcExitCauseScope = 0x10077118;
// R6GameService.dll data @ 10077128
constexpr unsigned int GRpcProgressScope = 0x10077128;
// R6GameService.dll data @ 10077138
constexpr unsigned int GRpcAbortScope = 0x10077138;
// R6GameService.dll data @ 10077144
constexpr unsigned int GServiceStartDiagnostic = 0x10077144;
// R6GameService.dll data @ 1007714c
constexpr unsigned int GServiceResultSeparator = 0x1007714c;
// R6GameService.dll data @ 10077150
constexpr unsigned int GServiceRpcErrorPrefix = 0x10077150;
// R6GameService.dll data @ 1007716c
constexpr unsigned int GServiceRpcMessageSeparator = 0x1007716c;
// R6GameService.dll data @ 10077174
constexpr unsigned int GServiceStateRequest = 0x10077174;
// R6GameService.dll data @ 100771a8
constexpr unsigned int GServiceExitRequest = 0x100771a8;
// R6GameService.dll data @ 100771e8
constexpr unsigned int GServiceProgressRequest = 0x100771e8;
// R6GameService.dll data @ 10077230
constexpr unsigned int GServiceAbortRequest = 0x10077230;
// R6GameService.dll data @ 10077278
constexpr unsigned int GUpdateStartSuccess = 0x10077278;
// R6GameService.dll data @ 100772c8
constexpr unsigned int GUpdateBindingFailure = 0x100772c8;
// R6GameService.dll data @ 10077344
constexpr unsigned int GUpdateRpcEndpoint = 0x10077344;
// R6GameService.dll data @ 10077368
constexpr unsigned int GUpdateSyncTimeout = 0x10077368;
// R6GameService.dll data @ 10077418
constexpr unsigned int GUpdateSyncEventName = 0x10077418;
// R6GameService.dll data @ 10077450
constexpr unsigned int GUpdateProcessFailure = 0x10077450;
// R6GameService.dll data @ 1007749c
constexpr unsigned int GUpdateCommandLabel = 0x1007749c;
// R6GameService.dll data @ 100774c0
constexpr unsigned int GUpdateCommandSuffix = 0x100774c0;
// R6GameService.dll data @ 100774c8
constexpr unsigned int GUpdateNil = 0x100774c8;
// R6GameService.dll text @ 100774d4
constexpr unsigned int TextUnlinkFailed = 0x100774d4;
// R6GameService.dll wide-text @ 100774e8
constexpr unsigned int WideTextFilesToBeDeleted = 0x100774e8;
// R6GameService.dll wide-text @ 10077518
constexpr unsigned int WideTextIfYouSeeThisFileTheDirectoryHasWriteAccessButDoesNotAllow = 0x10077518;
// R6GameService.dll wide-text @ 100775a8
constexpr unsigned int WideTextThisFileIsUsedForTestingDirectoryAccess = 0x100775a8;
// R6GameService.dll text @ 10077608
constexpr unsigned int TextTestDirAccess = 0x10077608;
// R6GameService.dll text @ 10077618
constexpr unsigned int TextOpenFailed = 0x10077618;
// R6GameService.dll wide-text @ 10077628
constexpr unsigned int WideTextTestaccess = 0x10077628;
// R6GameService.dll wide-text @ 10077640
constexpr unsigned int WideTextPunctuation7 = 0x10077640;
// R6GameService.dll text @ 10077644
constexpr unsigned int Text2X = 0x10077644;
// R6GameService.dll data @ 10077650
constexpr unsigned int GUpdateServiceRpcInterface = 0x10077650;
// R6GameService.dll data @ 1007769a
constexpr unsigned int GUpdateStateFormat = 0x1007769a;
// R6GameService.dll data @ 100776a6
constexpr unsigned int GUpdateExitFormat = 0x100776a6;
// R6GameService.dll data @ 100776b2
constexpr unsigned int GUpdateProgressFormat = 0x100776b2;
// R6GameService.dll data @ 100776de
constexpr unsigned int GUpdateAbortFormat = 0x100776de;
// R6GameService.dll data @ 100776ee
constexpr unsigned int GUpdateServiceRpcTypes = 0x100776ee;
// R6GameService.dll data @ 10077708
constexpr unsigned int GUpdateServiceStubDesc = 0x10077708;
// R6GameService.dll data @ 10077758
constexpr unsigned int GRpcConnectError = 0x10077758;
// R6GameService.dll data @ 10077780
constexpr unsigned int GRpcBindingExceptionFormat = 0x10077780;
// R6GameService.dll data @ 100777dc
constexpr unsigned int GRpcComposeError = 0x100777dc;
// R6GameService.dll data @ 100777f8
constexpr unsigned int GLocalRpcProtocol = 0x100777f8;
// R6GameService.dll data @ 10077808
constexpr unsigned int GRpcBindingScope = 0x10077808;
// R6GameService.dll data @ 10077814
constexpr unsigned int GProcessFailure = 0x10077814;
// R6GameService.dll data @ 10077844
constexpr unsigned int GProcessCommandLabel = 0x10077844;
// R6GameService.dll data @ 1007785c
constexpr unsigned int GProcessErrorCodeLabel = 0x1007785c;
// R6GameService.dll data @ 1007788c
constexpr unsigned int GProcessNoCommand = 0x1007788c;
// R6GameService.dll data @ 1007789c
constexpr unsigned int GProcessAfterAnsi = 0x1007789c;
// R6GameService.dll data @ 100778a8
constexpr unsigned int GProcessBeforeAnsi = 0x100778a8;
// R6GameService.dll vtable @ 100778f8
constexpr unsigned int CipherModule_BlowfishVTable = 0x100778f8;
// R6GameService.dll vtable @ 10077918
constexpr unsigned int CGSXorVTable = 0x10077918;
// R6GameService.dll vtable @ 10077928
constexpr unsigned int CipherModule_GSXorVTable = 0x10077928;
// R6GameService.dll vtable @ 10077948
constexpr unsigned int clPointerMap_PAXPAVHashAlgorithmVTable = 0x10077948;
// R6GameService.dll vtable @ 10077968
constexpr unsigned int clPointerMap_PAXPAVPRNGAlgorithmVTable = 0x10077968;
// R6GameService.dll vtable @ 10077988
constexpr unsigned int clPointerMap_PAXPAVCryptoAlgorithmVTable = 0x10077988;
// R6GameService.dll vtable @ 100779a8
constexpr unsigned int clPointerMap_PAXPAVPKCAlgorithmVTable = 0x100779a8;
// R6GameService.dll vtable @ 100779c8
constexpr unsigned int CBlowFishVTable = 0x100779c8;
// R6GameService.dll vtable @ 100779d8
constexpr unsigned int HashModule_SHA1VTable = 0x100779d8;
// R6GameService.dll vtable @ 10077a08
constexpr unsigned int HashModule_MD5VTable = 0x10077a08;
// R6GameService.dll vtable @ 10077a38
constexpr unsigned int PRNGModule_MGF1VTable = 0x10077a38;
// R6GameService.dll vtable @ 10077a58
constexpr unsigned int PKCModule_RSAVTable = 0x10077a58;
// R6GameService.dll vtable @ 10077a8c
constexpr unsigned int SecureHashAlgorithm1VTable = 0x10077a8c;
// R6GameService.dll vtable @ 10077a9c
constexpr unsigned int MD5VTable = 0x10077a9c;
// R6GameService.dll vtable @ 10077ab4
constexpr unsigned int RSAVTable = 0x10077ab4;
// R6GameService.dll vtable @ 10077abc
constexpr unsigned int clGLClientVTableAdjusted16 = 0x10077abc;
// R6GameService.dll vtable @ 10077ac4
constexpr unsigned int clGLClientVTableAdjusted12 = 0x10077ac4;
// R6GameService.dll vtable @ 10077adc
constexpr unsigned int clGLClientVTableAdjusted8 = 0x10077adc;
// R6GameService.dll vtable @ 10077b94
constexpr unsigned int clGLClientVTableAdjusted4 = 0x10077b94;
// R6GameService.dll vtable @ 10077bd8
constexpr unsigned int clGLClientVTable = 0x10077bd8;
// R6GameService.dll vtable @ 10077c04
constexpr unsigned int clLadderQueryCallbacksVTable = 0x10077c04;
// R6GameService.dll vtable @ 10077c0c
constexpr unsigned int clPersistentCallbacksVTable = 0x10077c0c;
// R6GameService.dll vtable @ 10077c24
constexpr unsigned int clLobbyCallbacksVTable = 0x10077c24;
// R6GameService.dll vtable @ 10077cdc
constexpr unsigned int clFriendsCallbacksVTable = 0x10077cdc;
// R6GameService.dll vtable @ 10077d20
constexpr unsigned int CProxyHandlerVTable = 0x10077d20;
// R6GameService.dll vtable @ 10077d58
constexpr unsigned int clMatchResultsVTable = 0x10077d58;
// R6GameService.dll data @ 10077d70
constexpr unsigned int keyed_results_supportPTR_LAB = 0x10077d70;
// R6GameService.dll vtable @ 10077d88
constexpr unsigned int clPlayerResultsVTable = 0x10077d88;
// R6GameService.dll vtable @ 10077da8
constexpr unsigned int clPointerMap_IPAVclDataListVTable = 0x10077da8;
// R6GameService.dll vtable @ 10077dc8
constexpr unsigned int clPointerMap_IPAVCLadderResultsVTable = 0x10077dc8;
// R6GameService.dll vtable @ 10077e00
constexpr unsigned int clFriendsCBVTableAdjusted72 = 0x10077e00;
// R6GameService.dll vtable @ 10077e0c
constexpr unsigned int clFriendsCBVTable = 0x10077e0c;
// R6GameService.dll vtable @ 10077e64
constexpr unsigned int clLoginCBVTableAdjusted44 = 0x10077e64;
// R6GameService.dll vtable @ 10077e6c
constexpr unsigned int clLoginCBVTable = 0x10077e6c;
// R6GameService.dll vtable @ 10077ea8
constexpr unsigned int CMsgQueueVTable = 0x10077ea8;
// R6GameService.dll vtable @ 10077ed0
constexpr unsigned int clPointerList_PAVCConnectionVTable = 0x10077ed0;
// R6GameService.dll vtable @ 10077eec
constexpr unsigned int clPointerList_PAVCCurMessageVTable = 0x10077eec;
// R6GameService.dll vtable @ 10077f08
constexpr unsigned int CConnectionListVTable = 0x10077f08;
// R6GameService.dll vtable @ 10077f34
constexpr unsigned int clLadderQueryCBVTableAdjusted12 = 0x10077f34;
// R6GameService.dll vtable @ 10077f3c
constexpr unsigned int clLadderQueryCBVTable = 0x10077f3c;
// R6GameService.dll vtable @ 10077f58
constexpr unsigned int clPersistentCBVTableAdjusted24 = 0x10077f58;
// R6GameService.dll vtable @ 10077f60
constexpr unsigned int clPersistentCBVTable = 0x10077f60;
// R6GameService.dll vtable @ 10077f90
constexpr unsigned int clLobbyCBVTableAdjusted184 = 0x10077f90;
// R6GameService.dll vtable @ 10077f9c
constexpr unsigned int clLobbyCBVTable = 0x10077f9c;
// R6GameService.dll vtable @ 10078064
constexpr unsigned int CLobbySrvConnectionListVTable = 0x10078064;
// R6GameService.dll scalar @ 10078098
constexpr unsigned int NativeDouble30_0 = 0x10078098;
// R6GameService.dll scalar @ 100780a0
constexpr unsigned int NativeDouble5_0 = 0x100780a0;
// R6GameService.dll vtable @ 100780c8
constexpr unsigned int clConnectElemVTable = 0x100780c8;
// R6GameService.dll vtable @ 100780dc
constexpr unsigned int clPointerList_PAVclGameMessageVTable = 0x100780dc;
// R6GameService.dll vtable @ 10078108
constexpr unsigned int clPointerList_PAVclSendElementVTable = 0x10078108;
// R6GameService.dll vtable @ 10078124
constexpr unsigned int clPointerList_PAVclRcvElementVTable = 0x10078124;
// R6GameService.dll vtable @ 10078140
constexpr unsigned int clSRPGSConnectVTable = 0x10078140;
// R6GameService.dll vtable @ 1007815c
constexpr unsigned int clSRPGSClientVTable = 0x1007815c;
// R6GameService.dll vtable @ 10078170
constexpr unsigned int clSRPClientVTable = 0x10078170;
// R6GameService.dll vtable @ 1007819c
constexpr unsigned int clGSMessageVTable = 0x1007819c;
// R6GameService.dll vtable @ 100781c4
constexpr unsigned int clMessageVTable = 0x100781c4;
// R6GameService.dll data @ 100781e4
constexpr unsigned int PTR_FUN = 0x100781e4;
// R6GameService.dll data @ 10078200
constexpr unsigned int ClGameMessageBaseOffsets = 0x10078200;
// R6GameService.dll vtable @ 1007820c
constexpr unsigned int clGSEncryptMessageVTable = 0x1007820c;
// R6GameService.dll vtable @ 10078244
constexpr unsigned int clRcvMsgQueueVTable = 0x10078244;
// R6GameService.dll vtable @ 10078270
constexpr unsigned int clSendMsgQueueVTable = 0x10078270;
// R6GameService.dll vtable @ 10078294
constexpr unsigned int clSRProtocolVTable = 0x10078294;
// R6GameService.dll vtable @ 100782d0
constexpr unsigned int clSRPSegmentVTable = 0x100782d0;
// R6GameService.dll vtable @ 100782d8
constexpr unsigned int clSegmentVTable = 0x100782d8;
// R6GameService.dll vtable @ 100782dc
constexpr unsigned int ClSRPSegmentVTable = 0x100782dc;
// R6GameService.dll scalar @ 100782e8
constexpr unsigned int NativeDouble0_9 = 0x100782e8;
// R6GameService.dll scalar @ 100782f0
constexpr unsigned int NativeDouble0_1 = 0x100782f0;
// R6GameService.dll vtable @ 10078304
constexpr unsigned int clBasicProtocolVTable = 0x10078304;
// R6GameService.dll vtable @ 10078328
constexpr unsigned int clPointerDeque_PAVclSegmentVTable = 0x10078328;
// R6GameService.dll wide-text @ 10078348
constexpr unsigned int WideText52 = 0x10078348;
// R6GameService.dll data @ 100783b8
constexpr unsigned int GCompilerCookieScope = 0x100783b8;
// R6GameService.dll vtable @ 100783c8
constexpr unsigned int clProxyConnectionVTable = 0x100783c8;
// R6GameService.dll vtable @ 100783ec
constexpr unsigned int clPointerList_PAVclProxyMessageVTable = 0x100783ec;
// R6GameService.dll data @ 1007a8b0
constexpr unsigned int GRtcInitializeBoundary = 0x1007a8b0;
// R6GameService.dll data @ 1007a8b8
constexpr unsigned int GRtcTerminationBoundary = 0x1007a8b8;
// R6GameService.dll data @ 1007a8e8
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoUnwindMap = 0x1007a8e8;
// R6GameService.dll data @ 1007a8f8
constexpr unsigned int UR6ModGSInfo_UR6ModGSInfoExceptionInfo = 0x1007a8f8;
// R6GameService.dll data @ 1007a914
constexpr unsigned int UR6ModGSInfoSharedLifetimeUnwindMap = 0x1007a914;
// R6GameService.dll data @ 1007a91c
constexpr unsigned int UR6ModGSInfoSharedLifetimeExceptionInfo = 0x1007a91c;
// R6GameService.dll data @ 1007a95c
constexpr unsigned int GGSServersPointerVoidCatchable = 0x1007a95c;
// R6GameService.dll data @ 1007a978
constexpr unsigned int GGSServersPointerUShortCatchable = 0x1007a978;
// R6GameService.dll data @ 1007a994
constexpr unsigned int GGSServersPointerUShortTypes = 0x1007a994;
// R6GameService.dll data @ 1007a9a0
constexpr unsigned int GGSServersPointerUShortThrow = 0x1007a9a0;
// R6GameService.dll data @ 1007ab7c
constexpr unsigned int string_record_supportSharedLifetimeUnwindMap = 0x1007ab7c;
// R6GameService.dll data @ 1007ab84
constexpr unsigned int string_record_supportSharedLifetimeExceptionInfo = 0x1007ab84;
// R6GameService.dll data @ 1007aba0
constexpr unsigned int GBadCastThrowData = 0x1007aba0;
// R6GameService.dll data @ 1007abbc
constexpr unsigned int bad_castGBadCastThrowData = 0x1007abbc;
// R6GameService.dll data @ 1007abd8
constexpr unsigned int bad_castGBadCastThrowData2 = 0x1007abd8;
// R6GameService.dll data @ 1007abe4
constexpr unsigned int bad_castGBadCastThrowData3 = 0x1007abe4;
// R6GameService.dll data @ 1007abf4
constexpr unsigned int GetOrCreateUnsignedShortCtypeFacetUnwindMap = 0x1007abf4;
// R6GameService.dll data @ 1007abfc
constexpr unsigned int GetOrCreateUnsignedShortCtypeFacetExceptionInfo = 0x1007abfc;
// R6GameService.dll data @ 1007ac44
constexpr unsigned int eventIsGlobalIDBannedUnwindMap = 0x1007ac44;
// R6GameService.dll data @ 1007ac4c
constexpr unsigned int eventIsGlobalIDBannedExceptionInfo = 0x1007ac4c;
// R6GameService.dll data @ 1007ac68
constexpr unsigned int eventProcessServerMsgUnwindMap = 0x1007ac68;
// R6GameService.dll data @ 1007ac70
constexpr unsigned int eventProcessServerMsgExceptionInfo = 0x1007ac70;
// R6GameService.dll data @ 1007ac8c
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap = 0x1007ac8c;
// R6GameService.dll data @ 1007ac9c
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo = 0x1007ac9c;
// R6GameService.dll data @ 1007acb8
constexpr unsigned int eventGetLocallyBoundIpAddrUnwindMap = 0x1007acb8;
// R6GameService.dll data @ 1007acc8
constexpr unsigned int eventGetLocallyBoundIpAddrExceptionInfo = 0x1007acc8;
// R6GameService.dll data @ 1007afbc
constexpr unsigned int stGameDataSharedLifetimeUnwindMap = 0x1007afbc;
// R6GameService.dll data @ 1007b004
constexpr unsigned int stGameDataSharedLifetimeExceptionInfo = 0x1007b004;
// R6GameService.dll data @ 1007b020
constexpr unsigned int stGameServerSharedLifetimeUnwindMap = 0x1007b020;
// R6GameService.dll data @ 1007b038
constexpr unsigned int stGameServerSharedLifetimeExceptionInfo = 0x1007b038;
// R6GameService.dll data @ 1007b0bc
constexpr unsigned int unreal_array_supportSharedLifetimeUnwindMap = 0x1007b0bc;
// R6GameService.dll data @ 1007b0c4
constexpr unsigned int unreal_array_supportSharedLifetimeExceptionInfo = 0x1007b0c4;
// R6GameService.dll data @ 1007b104
constexpr unsigned int UR6ServerList_UR6ServerListUnwindMap = 0x1007b104;
// R6GameService.dll data @ 1007b144
constexpr unsigned int UR6ServerList_UR6ServerListExceptionInfo = 0x1007b144;
// R6GameService.dll data @ 1007b160
constexpr unsigned int UR6ServerListSharedLifetimeUnwindMap = 0x1007b160;
// R6GameService.dll data @ 1007b198
constexpr unsigned int UR6ServerListSharedLifetimeExceptionInfo = 0x1007b198;
// R6GameService.dll data @ 1007b208
constexpr unsigned int UR6LanServers_UR6LanServersUnwindMap = 0x1007b208;
// R6GameService.dll data @ 1007b210
constexpr unsigned int UR6LanServers_UR6LanServersExceptionInfo = 0x1007b210;
// R6GameService.dll data @ 1007b22c
constexpr unsigned int UR6GSServers_UR6GSServersUnwindMap = 0x1007b22c;
// R6GameService.dll data @ 1007b284
constexpr unsigned int UR6GSServers_UR6GSServersExceptionInfo = 0x1007b284;
// R6GameService.dll data @ 1007b2a0
constexpr unsigned int UR6GSServers_UR6GSServers_UR6GSServersUnwindMap = 0x1007b2a0;
// R6GameService.dll data @ 1007b2f0
constexpr unsigned int UR6GSServers_UR6GSServers_UR6GSServersExceptionInfo = 0x1007b2f0;
// R6GameService.dll data @ 1007b73c
constexpr unsigned int GAtlStatusCatchableType = 0x1007b73c;
// R6GameService.dll data @ 1007b758
constexpr unsigned int GAtlStatusCatchableArray = 0x1007b758;
// R6GameService.dll data @ 1007b760
constexpr unsigned int GAtlStatusThrowInfo = 0x1007b760;
// R6GameService.dll data @ 1007b770
constexpr unsigned int global_stateSharedLifetimeUnwindMap = 0x1007b770;
// R6GameService.dll data @ 1007b780
constexpr unsigned int global_stateGInheritedFrameEH2 = 0x1007b780;
// R6GameService.dll data @ 1007b7a0
constexpr unsigned int global_stateSharedLifetimeTryMap = 0x1007b7a0;
// R6GameService.dll data @ 1007b7b4
constexpr unsigned int global_stateSharedLifetimeExceptionInfo = 0x1007b7b4;
// R6GameService.dll data @ 1007b7d0
constexpr unsigned int execNativeInitModInfoUnwindMap = 0x1007b7d0;
// R6GameService.dll data @ 1007b808
constexpr unsigned int UR6ModGSInfoGModInfoEH = 0x1007b808;
// R6GameService.dll data @ 1007b828
constexpr unsigned int execNativeInitModInfoTryMap = 0x1007b828;
// R6GameService.dll data @ 1007b83c
constexpr unsigned int execNativeInitModInfoExceptionInfo = 0x1007b83c;
// R6GameService.dll data @ 1007b858
constexpr unsigned int UR6GSServers_DestroyUnwindMap = 0x1007b858;
// R6GameService.dll data @ 1007b868
constexpr unsigned int UR6GSServersGManagerParentEH = 0x1007b868;
// R6GameService.dll data @ 1007b888
constexpr unsigned int UR6GSServers_DestroyTryMap = 0x1007b888;
// R6GameService.dll data @ 1007b89c
constexpr unsigned int UR6GSServers_DestroyExceptionInfo = 0x1007b89c;
// R6GameService.dll data @ 1007b8b8
constexpr unsigned int UR6GSServers_PingRequestUnwindMap = 0x1007b8b8;
// R6GameService.dll data @ 1007b8d8
constexpr unsigned int GPingRequestHandlers = 0x1007b8d8;
// R6GameService.dll data @ 1007b8f8
constexpr unsigned int UR6GSServers_PingRequestTryMap = 0x1007b8f8;
// R6GameService.dll data @ 1007b90c
constexpr unsigned int UR6GSServers_PingRequestExceptionInfo = 0x1007b90c;
// R6GameService.dll data @ 1007b928
constexpr unsigned int UR6GSServers_PollPingManagerUnwindMap = 0x1007b928;
// R6GameService.dll data @ 1007b938
constexpr unsigned int GPollPingPollHandlers = 0x1007b938;
// R6GameService.dll data @ 1007b958
constexpr unsigned int UR6GSServers_PollPingManagerTryMap = 0x1007b958;
// R6GameService.dll data @ 1007b96c
constexpr unsigned int UR6GSServers_PollPingManagerExceptionInfo = 0x1007b96c;
// R6GameService.dll data @ 1007b988
constexpr unsigned int UR6ServerList_execNativeGetPingTimeUnwindMap = 0x1007b988;
// R6GameService.dll data @ 1007b9a0
constexpr unsigned int GPingExchangeHandlers = 0x1007b9a0;
// R6GameService.dll data @ 1007b9c0
constexpr unsigned int UR6ServerList_execNativeGetPingTimeTryMap = 0x1007b9c0;
// R6GameService.dll data @ 1007b9d4
constexpr unsigned int UR6ServerList_execNativeGetPingTimeExceptionInfo = 0x1007b9d4;
// R6GameService.dll data @ 1007b9f0
constexpr unsigned int UR6ServerList_execNativeGetPingTimeOutUnwindMap = 0x1007b9f0;
// R6GameService.dll data @ 1007ba00
constexpr unsigned int UR6ServerListGPingExchangeHandlers = 0x1007ba00;
// R6GameService.dll data @ 1007ba20
constexpr unsigned int UR6ServerList_execNativeGetPingTimeOutTryMap = 0x1007ba20;
// R6GameService.dll data @ 1007ba34
constexpr unsigned int UR6ServerList_execNativeGetPingTimeOutExceptionInfo = 0x1007ba34;
// R6GameService.dll data @ 1007ba50
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPingUnwindMap = 0x1007ba50;
// R6GameService.dll data @ 1007ba68
constexpr unsigned int UR6GSServersGPingExchangeHandlers = 0x1007ba68;
// R6GameService.dll data @ 1007ba88
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPingTryMap = 0x1007ba88;
// R6GameService.dll data @ 1007ba9c
constexpr unsigned int UR6GSServers_execNativeProcessIcmpPingExceptionInfo = 0x1007ba9c;
// R6GameService.dll data @ 1007bab8
constexpr unsigned int UR6GSServers_execNativeGetSecondsUnwindMap = 0x1007bab8;
// R6GameService.dll data @ 1007bac8
constexpr unsigned int UR6GSServersGPingExchangeHandlers2 = 0x1007bac8;
// R6GameService.dll data @ 1007bae8
constexpr unsigned int UR6GSServers_execNativeGetSecondsTryMap = 0x1007bae8;
// R6GameService.dll data @ 1007bafc
constexpr unsigned int UR6GSServers_execNativeGetSecondsExceptionInfo = 0x1007bafc;
// R6GameService.dll data @ 1007bb18
constexpr unsigned int UR6ServerList_execNativeGetMilliSecondsUnwindMap = 0x1007bb18;
// R6GameService.dll data @ 1007bb28
constexpr unsigned int UR6ServerListGSmallVMBridgeEH = 0x1007bb28;
// R6GameService.dll data @ 1007bb48
constexpr unsigned int UR6ServerList_execNativeGetMilliSecondsTryMap = 0x1007bb48;
// R6GameService.dll data @ 1007bb5c
constexpr unsigned int UR6ServerList_execNativeGetMilliSecondsExceptionInfo = 0x1007bb5c;
// R6GameService.dll data @ 1007bb78
constexpr unsigned int UR6ServerList_execNativeGetMaxPlayersUnwindMap = 0x1007bb78;
// R6GameService.dll data @ 1007bb88
constexpr unsigned int UR6ServerListGSmallVMBridgeEH5 = 0x1007bb88;
// R6GameService.dll data @ 1007bba8
constexpr unsigned int UR6ServerList_execNativeGetMaxPlayersTryMap = 0x1007bba8;
// R6GameService.dll data @ 1007bbbc
constexpr unsigned int UR6ServerList_execNativeGetMaxPlayersExceptionInfo = 0x1007bbbc;
// R6GameService.dll data @ 1007bbd8
constexpr unsigned int UR6GSServers_execGetMaxUbiServerNameSizeUnwindMap = 0x1007bbd8;
// R6GameService.dll data @ 1007bbe8
constexpr unsigned int UR6GSServersGSmallVMBridgeEH2 = 0x1007bbe8;
// R6GameService.dll data @ 1007bc08
constexpr unsigned int UR6GSServers_execGetMaxUbiServerNameSizeTryMap = 0x1007bc08;
// R6GameService.dll data @ 1007bc1c
constexpr unsigned int UR6GSServers_execGetMaxUbiServerNameSizeExceptionInfo = 0x1007bc1c;
// R6GameService.dll data @ 1007bc38
constexpr unsigned int execNativeGetOwnSvrPortUnwindMap = 0x1007bc38;
// R6GameService.dll data @ 1007bc48
constexpr unsigned int UR6ServerListGParentExceptionInfo = 0x1007bc48;
// R6GameService.dll data @ 1007bc68
constexpr unsigned int execNativeGetOwnSvrPortTryMap = 0x1007bc68;
// R6GameService.dll data @ 1007bc7c
constexpr unsigned int execNativeGetOwnSvrPortExceptionInfo = 0x1007bc7c;
// R6GameService.dll data @ 1007bc98
constexpr unsigned int OnSameSubNetUnwindMap = 0x1007bc98;
// R6GameService.dll data @ 1007bcb0
constexpr unsigned int UR6GSServersGSubnetEH = 0x1007bcb0;
// R6GameService.dll data @ 1007bcd0
constexpr unsigned int OnSameSubNetTryMap = 0x1007bcd0;
// R6GameService.dll data @ 1007bce4
constexpr unsigned int OnSameSubNetExceptionInfo = 0x1007bce4;
// R6GameService.dll data @ 1007bd00
constexpr unsigned int UnInitMSClientUnwindMap = 0x1007bd00;
// R6GameService.dll data @ 1007bd10
constexpr unsigned int GUnInitMSClientHandlers = 0x1007bd10;
// R6GameService.dll data @ 1007bd30
constexpr unsigned int UnInitMSClientTryMap = 0x1007bd30;
// R6GameService.dll data @ 1007bd44
constexpr unsigned int UnInitMSClientExceptionInfo = 0x1007bd44;
// R6GameService.dll data @ 1007bd60
constexpr unsigned int execUnInitializeMSClientUnwindMap = 0x1007bd60;
// R6GameService.dll data @ 1007bd70
constexpr unsigned int GExecUnInitializeMSClientHandlers = 0x1007bd70;
// R6GameService.dll data @ 1007bd90
constexpr unsigned int execUnInitializeMSClientTryMap = 0x1007bd90;
// R6GameService.dll data @ 1007bda4
constexpr unsigned int execUnInitializeMSClientExceptionInfo = 0x1007bda4;
// R6GameService.dll data @ 1007bdc0
constexpr unsigned int UR6GSServers_execNativeGetMSClientInitializedUnwindMap = 0x1007bdc0;
// R6GameService.dll data @ 1007bdd0
constexpr unsigned int UR6GSServersGSmallVMBridgeEH6 = 0x1007bdd0;
// R6GameService.dll data @ 1007bdf0
constexpr unsigned int UR6GSServers_execNativeGetMSClientInitializedTryMap = 0x1007bdf0;
// R6GameService.dll data @ 1007be04
constexpr unsigned int UR6GSServers_execNativeGetMSClientInitializedExceptionInfo = 0x1007be04;
// R6GameService.dll data @ 1007be20
constexpr unsigned int UR6GSServers_PollMSClientCallbacksUnwindMap = 0x1007be20;
// R6GameService.dll data @ 1007be88
constexpr unsigned int GMSPollHandlers = 0x1007be88;
// R6GameService.dll data @ 1007bea8
constexpr unsigned int UR6GSServers_PollMSClientCallbacksTryMap = 0x1007bea8;
// R6GameService.dll data @ 1007bebc
constexpr unsigned int UR6GSServers_PollMSClientCallbacksExceptionInfo = 0x1007bebc;
// R6GameService.dll data @ 1007bed8
constexpr unsigned int UR6GSServers_execIsRefreshServersInProgressUnwindMap = 0x1007bed8;
// R6GameService.dll data @ 1007bee8
constexpr unsigned int UR6GSServersGSmallVMBridgeEH10 = 0x1007bee8;
// R6GameService.dll data @ 1007bf08
constexpr unsigned int UR6GSServers_execIsRefreshServersInProgressTryMap = 0x1007bf08;
// R6GameService.dll data @ 1007bf1c
constexpr unsigned int UR6GSServers_execIsRefreshServersInProgressExceptionInfo = 0x1007bf1c;
// R6GameService.dll data @ 1007bf38
constexpr unsigned int UR6GSServers_execStopRefreshServersUnwindMap = 0x1007bf38;
// R6GameService.dll data @ 1007bf48
constexpr unsigned int UR6GSServersGSmallVMBridgeEH14 = 0x1007bf48;
// R6GameService.dll data @ 1007bf68
constexpr unsigned int UR6GSServers_execStopRefreshServersTryMap = 0x1007bf68;
// R6GameService.dll data @ 1007bf7c
constexpr unsigned int UR6GSServers_execStopRefreshServersExceptionInfo = 0x1007bf7c;
// R6GameService.dll data @ 1007bf98
constexpr unsigned int MSCLientLeaveServerUnwindMap = 0x1007bf98;
// R6GameService.dll data @ 1007bfa8
constexpr unsigned int GMSCLientLeaveServerHandlers = 0x1007bfa8;
// R6GameService.dll data @ 1007bfc8
constexpr unsigned int MSCLientLeaveServerTryMap = 0x1007bfc8;
// R6GameService.dll data @ 1007bfdc
constexpr unsigned int MSCLientLeaveServerExceptionInfo = 0x1007bfdc;
// R6GameService.dll data @ 1007bff8
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap4 = 0x1007bff8;
// R6GameService.dll data @ 1007c010
constexpr unsigned int UR6GSServersGInheritedFrameEH = 0x1007c010;
// R6GameService.dll data @ 1007c030
constexpr unsigned int UR6GSServersSharedLifetimeTryMap3 = 0x1007c030;
// R6GameService.dll data @ 1007c044
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo4 = 0x1007c044;
// R6GameService.dll data @ 1007c060
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap5 = 0x1007c060;
// R6GameService.dll data @ 1007c078
constexpr unsigned int UR6GSServersGInheritedFrameEH5 = 0x1007c078;
// R6GameService.dll data @ 1007c098
constexpr unsigned int UR6GSServersSharedLifetimeTryMap4 = 0x1007c098;
// R6GameService.dll data @ 1007c0ac
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo5 = 0x1007c0ac;
// R6GameService.dll data @ 1007c0c8
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap2 = 0x1007c0c8;
// R6GameService.dll data @ 1007c0d8
constexpr unsigned int UR6GSServersGParentExceptionInfo2 = 0x1007c0d8;
// R6GameService.dll data @ 1007c0f8
constexpr unsigned int UR6GSServersSharedLifetimeTryMap = 0x1007c0f8;
// R6GameService.dll data @ 1007c10c
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo2 = 0x1007c10c;
// R6GameService.dll data @ 1007c128
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap3 = 0x1007c128;
// R6GameService.dll data @ 1007c138
constexpr unsigned int UR6GSServersGParentExceptionInfo6 = 0x1007c138;
// R6GameService.dll data @ 1007c158
constexpr unsigned int UR6GSServersSharedLifetimeTryMap2 = 0x1007c158;
// R6GameService.dll data @ 1007c16c
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo3 = 0x1007c16c;
// R6GameService.dll data @ 1007c188
constexpr unsigned int UR6ServerList_ResetSvrContainerUnwindMap = 0x1007c188;
// R6GameService.dll data @ 1007c198
constexpr unsigned int GResetSvrContainerHandlers = 0x1007c198;
// R6GameService.dll data @ 1007c1b8
constexpr unsigned int UR6ServerList_ResetSvrContainerTryMap = 0x1007c1b8;
// R6GameService.dll data @ 1007c1cc
constexpr unsigned int UR6ServerList_ResetSvrContainerExceptionInfo = 0x1007c1cc;
// R6GameService.dll data @ 1007c1e8
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap6 = 0x1007c1e8;
// R6GameService.dll data @ 1007c200
constexpr unsigned int UR6GSServersGInheritedFrameEH9 = 0x1007c200;
// R6GameService.dll data @ 1007c220
constexpr unsigned int UR6GSServersSharedLifetimeTryMap5 = 0x1007c220;
// R6GameService.dll data @ 1007c234
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo6 = 0x1007c234;
// R6GameService.dll data @ 1007c250
constexpr unsigned int ProcessJoinServerRequestUnwindMap = 0x1007c250;
// R6GameService.dll data @ 1007c270
constexpr unsigned int UR6GSServersGParentExceptionInfo10 = 0x1007c270;
// R6GameService.dll data @ 1007c290
constexpr unsigned int ProcessJoinServerRequestTryMap = 0x1007c290;
// R6GameService.dll data @ 1007c2a4
constexpr unsigned int ProcessJoinServerRequestExceptionInfo = 0x1007c2a4;
// R6GameService.dll data @ 1007c2c0
constexpr unsigned int UR6GSServersSharedLifetimeUnwindMap7 = 0x1007c2c0;
// R6GameService.dll data @ 1007c2d8
constexpr unsigned int UR6GSServersGInheritedFrameEH13 = 0x1007c2d8;
// R6GameService.dll data @ 1007c2f8
constexpr unsigned int UR6GSServersSharedLifetimeTryMap6 = 0x1007c2f8;
// R6GameService.dll data @ 1007c30c
constexpr unsigned int UR6GSServersSharedLifetimeExceptionInfo7 = 0x1007c30c;
// R6GameService.dll data @ 1007c328
constexpr unsigned int ProcessIsRouterDisconnectUnwindMap = 0x1007c328;
// R6GameService.dll data @ 1007c338
constexpr unsigned int UR6GSServersGParentExceptionInfo14 = 0x1007c338;
// R6GameService.dll data @ 1007c358
constexpr unsigned int ProcessIsRouterDisconnectTryMap = 0x1007c358;
// R6GameService.dll data @ 1007c36c
constexpr unsigned int ProcessIsRouterDisconnectExceptionInfo = 0x1007c36c;
// R6GameService.dll data @ 1007c388
constexpr unsigned int UR6GSServers_execNativeIsRouterDisconnectUnwindMap = 0x1007c388;
// R6GameService.dll data @ 1007c398
constexpr unsigned int GexecNativeIsRouterDisconnectHandlers = 0x1007c398;
// R6GameService.dll data @ 1007c3b8
constexpr unsigned int UR6GSServers_execNativeIsRouterDisconnectTryMap = 0x1007c3b8;
// R6GameService.dll data @ 1007c3cc
constexpr unsigned int UR6GSServers_execNativeIsRouterDisconnectExceptionInfo = 0x1007c3cc;
// R6GameService.dll data @ 1007c3e8
constexpr unsigned int ProcessIsLobbyDisconnectUnwindMap = 0x1007c3e8;
// R6GameService.dll data @ 1007c3f8
constexpr unsigned int UR6GSServersGParentExceptionInfo18 = 0x1007c3f8;
// R6GameService.dll data @ 1007c418
constexpr unsigned int ProcessIsLobbyDisconnectTryMap = 0x1007c418;
// R6GameService.dll data @ 1007c42c
constexpr unsigned int ProcessIsLobbyDisconnectExceptionInfo = 0x1007c42c;
// R6GameService.dll data @ 1007c448
constexpr unsigned int DestroyFourStringsUnwindMap = 0x1007c448;
// R6GameService.dll data @ 1007c460
constexpr unsigned int DestroyFourStringsExceptionInfo = 0x1007c460;
// R6GameService.dll data @ 1007c47c
constexpr unsigned int UR6GSServers_InitUnwindMap = 0x1007c47c;
// R6GameService.dll data @ 1007c49c
constexpr unsigned int UR6GSServers_InitExceptionInfo = 0x1007c49c;
// R6GameService.dll data @ 1007c4b8
constexpr unsigned int UR6GSServers_execInitializeUnwindMap = 0x1007c4b8;
// R6GameService.dll data @ 1007c4c8
constexpr unsigned int GGSInitHandlers = 0x1007c4c8;
// R6GameService.dll data @ 1007c4e8
constexpr unsigned int UR6GSServers_execInitializeTryMap = 0x1007c4e8;
// R6GameService.dll data @ 1007c4fc
constexpr unsigned int UR6GSServers_execInitializeExceptionInfo = 0x1007c4fc;
// R6GameService.dll data @ 1007c518
constexpr unsigned int InitFavoritesUnwindMap = 0x1007c518;
// R6GameService.dll data @ 1007c530
constexpr unsigned int GMSClientFavoritesHandlers = 0x1007c530;
// R6GameService.dll data @ 1007c550
constexpr unsigned int InitFavoritesTryMap = 0x1007c550;
// R6GameService.dll data @ 1007c564
constexpr unsigned int InitFavoritesExceptionInfo = 0x1007c564;
// R6GameService.dll data @ 1007c580
constexpr unsigned int execNativeInitFavoritesUnwindMap = 0x1007c580;
// R6GameService.dll data @ 1007c590
constexpr unsigned int UR6ServerListGFavoriteBridgeEH = 0x1007c590;
// R6GameService.dll data @ 1007c5b0
constexpr unsigned int execNativeInitFavoritesTryMap = 0x1007c5b0;
// R6GameService.dll data @ 1007c5c4
constexpr unsigned int execNativeInitFavoritesExceptionInfo = 0x1007c5c4;
// R6GameService.dll data @ 1007c5e0
constexpr unsigned int execNativeUpdateFavoritesUnwindMap = 0x1007c5e0;
// R6GameService.dll data @ 1007c5f0
constexpr unsigned int UR6ServerListGFavoriteBridgeEH5 = 0x1007c5f0;
// R6GameService.dll data @ 1007c610
constexpr unsigned int execNativeUpdateFavoritesTryMap = 0x1007c610;
// R6GameService.dll data @ 1007c624
constexpr unsigned int execNativeUpdateFavoritesExceptionInfo = 0x1007c624;
// R6GameService.dll data @ 1007c640
constexpr unsigned int execSortServersUnwindMap = 0x1007c640;
// R6GameService.dll data @ 1007c650
constexpr unsigned int UR6ServerListGParentExceptionInfo5 = 0x1007c650;
// R6GameService.dll data @ 1007c670
constexpr unsigned int execSortServersTryMap = 0x1007c670;
// R6GameService.dll data @ 1007c684
constexpr unsigned int execSortServersExceptionInfo = 0x1007c684;
// R6GameService.dll data @ 1007c6a0
constexpr unsigned int LogGSVersionUnwindMap = 0x1007c6a0;
// R6GameService.dll data @ 1007c6b8
constexpr unsigned int GGSVersionHandlers = 0x1007c6b8;
// R6GameService.dll data @ 1007c6d8
constexpr unsigned int LogGSVersionTryMap = 0x1007c6d8;
// R6GameService.dll data @ 1007c6ec
constexpr unsigned int LogGSVersionExceptionInfo = 0x1007c6ec;
// R6GameService.dll data @ 1007c708
constexpr unsigned int execGetDisplayListSizeUnwindMap = 0x1007c708;
// R6GameService.dll data @ 1007c718
constexpr unsigned int GIDDisplayHandlers = 0x1007c718;
// R6GameService.dll data @ 1007c738
constexpr unsigned int execGetDisplayListSizeTryMap = 0x1007c738;
// R6GameService.dll data @ 1007c74c
constexpr unsigned int execGetDisplayListSizeExceptionInfo = 0x1007c74c;
// R6GameService.dll data @ 1007c768
constexpr unsigned int PlayerIsInIDListUnwindMap = 0x1007c768;
// R6GameService.dll data @ 1007c788
constexpr unsigned int GIDPlayerHandlers = 0x1007c788;
// R6GameService.dll data @ 1007c7a8
constexpr unsigned int PlayerIsInIDListTryMap = 0x1007c7a8;
// R6GameService.dll data @ 1007c7bc
constexpr unsigned int PlayerIsInIDListExceptionInfo = 0x1007c7bc;
// R6GameService.dll data @ 1007c7d8
constexpr unsigned int GetGlobalIdFromPlayerIDListUnwindMap = 0x1007c7d8;
// R6GameService.dll data @ 1007c7f8
constexpr unsigned int GIDGlobalHandlers = 0x1007c7f8;
// R6GameService.dll data @ 1007c818
constexpr unsigned int GetGlobalIdFromPlayerIDListTryMap = 0x1007c818;
// R6GameService.dll data @ 1007c82c
constexpr unsigned int GetGlobalIdFromPlayerIDListExceptionInfo = 0x1007c82c;
// R6GameService.dll data @ 1007c848
constexpr unsigned int PollCallbacksUnwindMap = 0x1007c848;
// R6GameService.dll data @ 1007c858
constexpr unsigned int GMSClientPollHandlers = 0x1007c858;
// R6GameService.dll data @ 1007c878
constexpr unsigned int PollCallbacksTryMap = 0x1007c878;
// R6GameService.dll data @ 1007c88c
constexpr unsigned int PollCallbacksExceptionInfo = 0x1007c88c;
// R6GameService.dll data @ 1007c8a8
constexpr unsigned int InitializeMSClientUnwindMap = 0x1007c8a8;
// R6GameService.dll data @ 1007c8c0
constexpr unsigned int GMSClientInitializeHandlers = 0x1007c8c0;
// R6GameService.dll data @ 1007c8e0
constexpr unsigned int InitializeMSClientTryMap = 0x1007c8e0;
// R6GameService.dll data @ 1007c8f4
constexpr unsigned int InitializeMSClientExceptionInfo = 0x1007c8f4;
// R6GameService.dll data @ 1007c910
constexpr unsigned int execInitializeMSClientUnwindMap = 0x1007c910;
// R6GameService.dll data @ 1007c920
constexpr unsigned int GMSClientExecInitializeHandlers = 0x1007c920;
// R6GameService.dll data @ 1007c940
constexpr unsigned int execInitializeMSClientTryMap = 0x1007c940;
// R6GameService.dll data @ 1007c954
constexpr unsigned int execInitializeMSClientExceptionInfo = 0x1007c954;
// R6GameService.dll data @ 1007c970
constexpr unsigned int UR6GSServers_RefreshOneServerUnwindMap = 0x1007c970;
// R6GameService.dll data @ 1007c980
constexpr unsigned int UR6GSServersGParentExceptionInfo22 = 0x1007c980;
// R6GameService.dll data @ 1007c9a0
constexpr unsigned int UR6GSServers_RefreshOneServerTryMap = 0x1007c9a0;
// R6GameService.dll data @ 1007c9b4
constexpr unsigned int UR6GSServers_RefreshOneServerExceptionInfo = 0x1007c9b4;
// R6GameService.dll data @ 1007c9d0
constexpr unsigned int UR6GSServers_execRefreshOneServerUnwindMap = 0x1007c9d0;
// R6GameService.dll data @ 1007c9e0
constexpr unsigned int UR6GSServersGParentExceptionInfo26 = 0x1007c9e0;
// R6GameService.dll data @ 1007ca00
constexpr unsigned int UR6GSServers_execRefreshOneServerTryMap = 0x1007ca00;
// R6GameService.dll data @ 1007ca14
constexpr unsigned int UR6GSServers_execRefreshOneServerExceptionInfo = 0x1007ca14;
// R6GameService.dll data @ 1007ca30
constexpr unsigned int execNativeSetMatchResultUnwindMap = 0x1007ca30;
// R6GameService.dll data @ 1007ca50
constexpr unsigned int UR6GSServersGMatchResultLifetimeData = 0x1007ca50;
// R6GameService.dll data @ 1007ca70
constexpr unsigned int execNativeSetMatchResultTryMap = 0x1007ca70;
// R6GameService.dll data @ 1007ca84
constexpr unsigned int execNativeSetMatchResultExceptionInfo = 0x1007ca84;
// R6GameService.dll data @ 1007caa0
constexpr unsigned int UR6GSServers_SubmitMatchResultUnwindMap = 0x1007caa0;
// R6GameService.dll data @ 1007cab0
constexpr unsigned int UR6GSServersGManagerParentEH5 = 0x1007cab0;
// R6GameService.dll data @ 1007cad0
constexpr unsigned int UR6GSServers_SubmitMatchResultTryMap = 0x1007cad0;
// R6GameService.dll data @ 1007cae4
constexpr unsigned int UR6GSServers_SubmitMatchResultExceptionInfo = 0x1007cae4;
// R6GameService.dll data @ 1007cb00
constexpr unsigned int FillSvrContainerUnwindMap = 0x1007cb00;
// R6GameService.dll data @ 1007cb28
constexpr unsigned int UR6ServerListGFillContainerEH = 0x1007cb28;
// R6GameService.dll data @ 1007cb48
constexpr unsigned int FillSvrContainerTryMap = 0x1007cb48;
// R6GameService.dll data @ 1007cb5c
constexpr unsigned int FillSvrContainerExceptionInfo = 0x1007cb5c;
// R6GameService.dll data @ 1007cb78
constexpr unsigned int UR6GSServers_ProcessLoginMasterSrvUnwindMap = 0x1007cb78;
// R6GameService.dll data @ 1007cb88
constexpr unsigned int UR6GSServersGParentExceptionInfo30 = 0x1007cb88;
// R6GameService.dll data @ 1007cba8
constexpr unsigned int UR6GSServers_ProcessLoginMasterSrvTryMap = 0x1007cba8;
// R6GameService.dll data @ 1007cbbc
constexpr unsigned int UR6GSServers_ProcessLoginMasterSrvExceptionInfo = 0x1007cbbc;
// R6GameService.dll data @ 1007cbd8
constexpr unsigned int UR6GSServers_MasterServerManagerUnwindMap = 0x1007cbd8;
// R6GameService.dll data @ 1007cbe8
constexpr unsigned int GMasterServerManagerHandlers = 0x1007cbe8;
// R6GameService.dll data @ 1007cc08
constexpr unsigned int UR6GSServers_MasterServerManagerTryMap = 0x1007cc08;
// R6GameService.dll data @ 1007cc1c
constexpr unsigned int UR6GSServers_MasterServerManagerExceptionInfo = 0x1007cc1c;
// R6GameService.dll data @ 1007cc38
constexpr unsigned int UR6GSServers_AddPlayerToIDListUnwindMap = 0x1007cc38;
// R6GameService.dll data @ 1007cc68
constexpr unsigned int GAddPlayerToIDListHandlers = 0x1007cc68;
// R6GameService.dll data @ 1007cc88
constexpr unsigned int UR6GSServers_AddPlayerToIDListTryMap = 0x1007cc88;
// R6GameService.dll data @ 1007cc9c
constexpr unsigned int UR6GSServers_AddPlayerToIDListExceptionInfo = 0x1007cc9c;
// R6GameService.dll data @ 1007ccb8
constexpr unsigned int ReceiveServerUnwindMap = 0x1007ccb8;
// R6GameService.dll data @ 1007ccd0
constexpr unsigned int GReceiveServerHandlers = 0x1007ccd0;
// R6GameService.dll data @ 1007ccf0
constexpr unsigned int ReceiveServerTryMap = 0x1007ccf0;
// R6GameService.dll data @ 1007cd04
constexpr unsigned int ReceiveServerExceptionInfo = 0x1007cd04;
// R6GameService.dll data @ 1007cd8c
constexpr unsigned int UR6GSServers_InitMSClientUnwindMap = 0x1007cd8c;
// R6GameService.dll data @ 1007cda4
constexpr unsigned int GInitMSClientHandlers = 0x1007cda4;
// R6GameService.dll data @ 1007cdc4
constexpr unsigned int UR6GSServers_InitMSClientTryMap = 0x1007cdc4;
// R6GameService.dll data @ 1007cdd8
constexpr unsigned int UR6GSServers_InitMSClientExceptionInfo = 0x1007cdd8;
// R6GameService.dll data @ 1007cdf4
constexpr unsigned int ReceiveAltInfoUnwindMap = 0x1007cdf4;
// R6GameService.dll data @ 1007ce14
constexpr unsigned int GReceiveAltInfoHandlers = 0x1007ce14;
// R6GameService.dll data @ 1007ce34
constexpr unsigned int ReceiveAltInfoTryMap = 0x1007ce34;
// R6GameService.dll data @ 1007ce48
constexpr unsigned int ReceiveAltInfoExceptionInfo = 0x1007ce48;
// R6GameService.dll data @ 1007ce64
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequestUnwindMap = 0x1007ce64;
// R6GameService.dll data @ 1007ce7c
constexpr unsigned int GProcessMSClientInitRequestHandlers = 0x1007ce7c;
// R6GameService.dll data @ 1007ce9c
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequestTryMap = 0x1007ce9c;
// R6GameService.dll data @ 1007ceb0
constexpr unsigned int UR6GSServers_ProcessMSClientInitRequestExceptionInfo = 0x1007ceb0;
// R6GameService.dll data @ 1007cecc
constexpr unsigned int unreal_array_supportSharedLifetimeUnwindMap2 = 0x1007cecc;
// R6GameService.dll data @ 1007ced4
constexpr unsigned int unreal_array_supportSharedLifetimeExceptionInfo2 = 0x1007ced4;
// R6GameService.dll data @ 1007cef0
constexpr unsigned int UR6GSServers_RefreshServersUnwindMap = 0x1007cef0;
// R6GameService.dll data @ 1007cf00
constexpr unsigned int UR6GSServersGRefreshServersEH = 0x1007cf00;
// R6GameService.dll data @ 1007cf20
constexpr unsigned int UR6GSServers_RefreshServersTryMap = 0x1007cf20;
// R6GameService.dll data @ 1007cf34
constexpr unsigned int UR6GSServers_RefreshServersExceptionInfo = 0x1007cf34;
// R6GameService.dll data @ 1007cf50
constexpr unsigned int UR6GSServers_execRefreshServersUnwindMap = 0x1007cf50;
// R6GameService.dll data @ 1007cf60
constexpr unsigned int UR6GSServersGSmallVMBridgeEH18 = 0x1007cf60;
// R6GameService.dll data @ 1007cf80
constexpr unsigned int UR6GSServers_execRefreshServersTryMap = 0x1007cf80;
// R6GameService.dll data @ 1007cf94
constexpr unsigned int UR6GSServers_execRefreshServersExceptionInfo = 0x1007cf94;
// R6GameService.dll data @ 1007cfb0
constexpr unsigned int UR6GSServers_GameServiceManagerUnwindMap = 0x1007cfb0;
// R6GameService.dll data @ 1007cfc8
constexpr unsigned int GGameServiceManagerHandlers = 0x1007cfc8;
// R6GameService.dll data @ 1007cfe8
constexpr unsigned int UR6GSServers_GameServiceManagerTryMap = 0x1007cfe8;
// R6GameService.dll data @ 1007cffc
constexpr unsigned int UR6GSServers_GameServiceManagerExceptionInfo = 0x1007cffc;
// R6GameService.dll data @ 1007d018
constexpr unsigned int UR6GSServersUnwindMap = 0x1007d018;
// R6GameService.dll data @ 1007d080
constexpr unsigned int GGSServersDefaultHandlers = 0x1007d080;
// R6GameService.dll data @ 1007d0a0
constexpr unsigned int UR6GSServersTryMap = 0x1007d0a0;
// R6GameService.dll data @ 1007d0b4
constexpr unsigned int UR6GSServersExceptionInfo = 0x1007d0b4;
// R6GameService.dll data @ 1007d0d0
constexpr unsigned int CreatedCDKeyUnwindMap = 0x1007d0d0;
// R6GameService.dll data @ 1007d0f8
constexpr unsigned int GCDKeyHandlers = 0x1007d0f8;
// R6GameService.dll data @ 1007d118
constexpr unsigned int CreatedCDKeyTryMap = 0x1007d118;
// R6GameService.dll data @ 1007d12c
constexpr unsigned int CreatedCDKeyExceptionInfo = 0x1007d12c;
// R6GameService.dll data @ 1007d148
constexpr unsigned int InitMODCDKeyUnwindMap = 0x1007d148;
// R6GameService.dll data @ 1007d178
constexpr unsigned int UR6ModGSInfoGCDKeyHandlers = 0x1007d178;
// R6GameService.dll data @ 1007d198
constexpr unsigned int InitMODCDKeyTryMap = 0x1007d198;
// R6GameService.dll data @ 1007d1ac
constexpr unsigned int InitMODCDKeyExceptionInfo = 0x1007d1ac;
// R6GameService.dll data @ 1007d1c8
constexpr unsigned int execInitGSCDKeyUnwindMap = 0x1007d1c8;
// R6GameService.dll data @ 1007d1d8
constexpr unsigned int GexecInitGSCDKeyHandlers = 0x1007d1d8;
// R6GameService.dll data @ 1007d1f8
constexpr unsigned int execInitGSCDKeyTryMap = 0x1007d1f8;
// R6GameService.dll data @ 1007d20c
constexpr unsigned int execInitGSCDKeyExceptionInfo = 0x1007d20c;
// R6GameService.dll data @ 1007d228
constexpr unsigned int UnInitCDKeyUnwindMap = 0x1007d228;
// R6GameService.dll data @ 1007d238
constexpr unsigned int GUnInitCDKeyHandlers = 0x1007d238;
// R6GameService.dll data @ 1007d258
constexpr unsigned int UnInitCDKeyTryMap = 0x1007d258;
// R6GameService.dll data @ 1007d26c
constexpr unsigned int UnInitCDKeyExceptionInfo = 0x1007d26c;
// R6GameService.dll data @ 1007d288
constexpr unsigned int UR6GSServers_RequestActivationUnwindMap = 0x1007d288;
// R6GameService.dll data @ 1007d2b8
constexpr unsigned int GRequestActivationHandlers = 0x1007d2b8;
// R6GameService.dll data @ 1007d2d8
constexpr unsigned int UR6GSServers_RequestActivationTryMap = 0x1007d2d8;
// R6GameService.dll data @ 1007d2ec
constexpr unsigned int UR6GSServers_RequestActivationExceptionInfo = 0x1007d2ec;
// R6GameService.dll data @ 1007d308
constexpr unsigned int UR6GSServers_RequestAuthorizationUnwindMap = 0x1007d308;
// R6GameService.dll data @ 1007d318
constexpr unsigned int GRequestAuthorizationHandlers = 0x1007d318;
// R6GameService.dll data @ 1007d338
constexpr unsigned int UR6GSServers_RequestAuthorizationTryMap = 0x1007d338;
// R6GameService.dll data @ 1007d34c
constexpr unsigned int UR6GSServers_RequestAuthorizationExceptionInfo = 0x1007d34c;
// R6GameService.dll data @ 1007d368
constexpr unsigned int UR6GSServers_GetAuthIDUnwindMap = 0x1007d368;
// R6GameService.dll data @ 1007d378
constexpr unsigned int GGetAuthIDHandlers = 0x1007d378;
// R6GameService.dll data @ 1007d398
constexpr unsigned int UR6GSServers_GetAuthIDTryMap = 0x1007d398;
// R6GameService.dll data @ 1007d3ac
constexpr unsigned int UR6GSServers_GetAuthIDExceptionInfo = 0x1007d3ac;
// R6GameService.dll data @ 1007d3c8
constexpr unsigned int IsAuthIDSuccessUnwindMap = 0x1007d3c8;
// R6GameService.dll data @ 1007d3d8
constexpr unsigned int GIsAuthIDSuccessHandlers = 0x1007d3d8;
// R6GameService.dll data @ 1007d3f8
constexpr unsigned int IsAuthIDSuccessTryMap = 0x1007d3f8;
// R6GameService.dll data @ 1007d40c
constexpr unsigned int IsAuthIDSuccessExceptionInfo = 0x1007d40c;
// R6GameService.dll data @ 1007d428
constexpr unsigned int FormatAuthenticationIdHexUnwindMap = 0x1007d428;
// R6GameService.dll data @ 1007d438
constexpr unsigned int FormatAuthenticationIdHexExceptionInfo = 0x1007d438;
// R6GameService.dll data @ 1007d454
constexpr unsigned int UR6GSServers_CDKeyValidateUserUnwindMap = 0x1007d454;
// R6GameService.dll data @ 1007d46c
constexpr unsigned int GCDKeyValidateUserHandlers = 0x1007d46c;
// R6GameService.dll data @ 1007d48c
constexpr unsigned int UR6GSServers_CDKeyValidateUserTryMap = 0x1007d48c;
// R6GameService.dll data @ 1007d4a0
constexpr unsigned int UR6GSServers_CDKeyValidateUserExceptionInfo = 0x1007d4a0;
// R6GameService.dll data @ 1007d4bc
constexpr unsigned int EnterCDKeyUnwindMap = 0x1007d4bc;
// R6GameService.dll data @ 1007d514
constexpr unsigned int GEnterCDKeyHandlers = 0x1007d514;
// R6GameService.dll data @ 1007d534
constexpr unsigned int EnterCDKeyTryMap = 0x1007d534;
// R6GameService.dll data @ 1007d548
constexpr unsigned int EnterCDKeyExceptionInfo = 0x1007d548;
// R6GameService.dll data @ 1007d564
constexpr unsigned int execEnterCDKeyUnwindMap = 0x1007d564;
// R6GameService.dll data @ 1007d57c
constexpr unsigned int GExecEnterCDKeyHandlers = 0x1007d57c;
// R6GameService.dll data @ 1007d59c
constexpr unsigned int execEnterCDKeyTryMap = 0x1007d59c;
// R6GameService.dll data @ 1007d5b0
constexpr unsigned int execEnterCDKeyExceptionInfo = 0x1007d5b0;
// R6GameService.dll data @ 1007d5cc
constexpr unsigned int RequestModCDKeyProcessUnwindMap = 0x1007d5cc;
// R6GameService.dll data @ 1007d60c
constexpr unsigned int GRequestModCDKeyProcessHandlers = 0x1007d60c;
// R6GameService.dll data @ 1007d62c
constexpr unsigned int RequestModCDKeyProcessTryMap = 0x1007d62c;
// R6GameService.dll data @ 1007d640
constexpr unsigned int RequestModCDKeyProcessExceptionInfo = 0x1007d640;
// R6GameService.dll data @ 1007d680
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksUnwindMap = 0x1007d680;
// R6GameService.dll data @ 1007d710
constexpr unsigned int GCDKeyPollHandlers = 0x1007d710;
// R6GameService.dll data @ 1007d730
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksTryMap = 0x1007d730;
// R6GameService.dll data @ 1007d744
constexpr unsigned int UR6GSServers_PollClientCDKeyCallbacksExceptionInfo = 0x1007d744;
// R6GameService.dll data @ 1007d784
constexpr unsigned int cdkey_supportSharedLifetimeUnwindMap = 0x1007d784;
// R6GameService.dll data @ 1007d78c
constexpr unsigned int cdkey_supportSharedLifetimeExceptionInfo = 0x1007d78c;
// R6GameService.dll data @ 1007d7a8
constexpr unsigned int UR6GSServers_ReceiveValidationUnwindMap = 0x1007d7a8;
// R6GameService.dll data @ 1007d7b8
constexpr unsigned int GReceiveValidationHandlers = 0x1007d7b8;
// R6GameService.dll data @ 1007d7d8
constexpr unsigned int UR6GSServers_ReceiveValidationTryMap = 0x1007d7d8;
// R6GameService.dll data @ 1007d7ec
constexpr unsigned int UR6GSServers_ReceiveValidationExceptionInfo = 0x1007d7ec;
// R6GameService.dll data @ 1007d808
constexpr unsigned int unreal_array_support_DestroyArrayStorage5UnwindMap = 0x1007d808;
// R6GameService.dll data @ 1007d810
constexpr unsigned int unreal_array_support_DestroyArrayStorage5ExceptionInfo = 0x1007d810;
// R6GameService.dll data @ 1007d82c
constexpr unsigned int InitCDKeyUnwindMap = 0x1007d82c;
// R6GameService.dll data @ 1007d83c
constexpr unsigned int GInitCDKeyHandlers = 0x1007d83c;
// R6GameService.dll data @ 1007d85c
constexpr unsigned int InitCDKeyTryMap = 0x1007d85c;
// R6GameService.dll data @ 1007d870
constexpr unsigned int InitCDKeyExceptionInfo = 0x1007d870;
// R6GameService.dll data @ 1007d88c
constexpr unsigned int InitGSCDKeyUnwindMap = 0x1007d88c;
// R6GameService.dll data @ 1007d89c
constexpr unsigned int GInitGSCDKeyHandlers = 0x1007d89c;
// R6GameService.dll data @ 1007d8bc
constexpr unsigned int InitGSCDKeyTryMap = 0x1007d8bc;
// R6GameService.dll data @ 1007d8d0
constexpr unsigned int InitGSCDKeyExceptionInfo = 0x1007d8d0;
// R6GameService.dll data @ 1007d8ec
constexpr unsigned int DisconnectAllCDKeyPlayersUnwindMap = 0x1007d8ec;
// R6GameService.dll data @ 1007d914
constexpr unsigned int GDisconnectAllCDKeyPlayersHandlers = 0x1007d914;
// R6GameService.dll data @ 1007d934
constexpr unsigned int DisconnectAllCDKeyPlayersTryMap = 0x1007d934;
// R6GameService.dll data @ 1007d948
constexpr unsigned int DisconnectAllCDKeyPlayersExceptionInfo = 0x1007d948;
// R6GameService.dll data @ 1007d964
constexpr unsigned int CDKeyDisconnecUserUnwindMap = 0x1007d964;
// R6GameService.dll data @ 1007d984
constexpr unsigned int GCDKeyDisconnecUserHandlers = 0x1007d984;
// R6GameService.dll data @ 1007d9a4
constexpr unsigned int CDKeyDisconnecUserTryMap = 0x1007d9a4;
// R6GameService.dll data @ 1007d9b8
constexpr unsigned int CDKeyDisconnecUserExceptionInfo = 0x1007d9b8;
// R6GameService.dll data @ 1007d9d4
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReplyUnwindMap = 0x1007d9d4;
// R6GameService.dll data @ 1007d9ec
constexpr unsigned int GPlayerStatusReplyHandlers = 0x1007d9ec;
// R6GameService.dll data @ 1007da0c
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReplyTryMap = 0x1007da0c;
// R6GameService.dll data @ 1007da20
constexpr unsigned int UR6GSServers_NativeCDKeyPlayerStatusReplyExceptionInfo = 0x1007da20;
// R6GameService.dll data @ 1007da3c
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestUnwindMap = 0x1007da3c;
// R6GameService.dll data @ 1007dac4
constexpr unsigned int GPCRequestHandlers = 0x1007dac4;
// R6GameService.dll data @ 1007dae4
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestTryMap = 0x1007dae4;
// R6GameService.dll data @ 1007daf8
constexpr unsigned int UR6GSServers_ProcessPC_CDKeyRequestExceptionInfo = 0x1007daf8;
// R6GameService.dll data @ 1007db14
constexpr unsigned int UR6GSServers_ProcessAuthIdRequestUnwindMap = 0x1007db14;
// R6GameService.dll data @ 1007db24
constexpr unsigned int GAuthIdRequestHandlers = 0x1007db24;
// R6GameService.dll data @ 1007db44
constexpr unsigned int UR6GSServers_ProcessAuthIdRequestTryMap = 0x1007db44;
// R6GameService.dll data @ 1007db58
constexpr unsigned int UR6GSServers_ProcessAuthIdRequestExceptionInfo = 0x1007db58;
// R6GameService.dll data @ 1007db74
constexpr unsigned int SetSelectedProductCategoryUnwindMap = 0x1007db74;
// R6GameService.dll data @ 1007db94
constexpr unsigned int SetSelectedProductCategoryExceptionInfo = 0x1007db94;
// R6GameService.dll data @ 1007dbb0
constexpr unsigned int UR6GSServers_GSClientPostMessageUnwindMap = 0x1007dbb0;
// R6GameService.dll data @ 1007dbc0
constexpr unsigned int GPostMessageHandlers = 0x1007dbc0;
// R6GameService.dll data @ 1007dbe0
constexpr unsigned int UR6GSServers_GSClientPostMessageTryMap = 0x1007dbe0;
// R6GameService.dll data @ 1007dbf4
constexpr unsigned int UR6GSServers_GSClientPostMessageExceptionInfo = 0x1007dbf4;
// R6GameService.dll data @ 1007dc10
constexpr unsigned int UR6GSServers_execNativeIsWaitingForGSInitUnwindMap = 0x1007dc10;
// R6GameService.dll data @ 1007dc20
constexpr unsigned int GexecNativeIsWaitingForGSInitHandlers = 0x1007dc20;
// R6GameService.dll data @ 1007dc40
constexpr unsigned int UR6GSServers_execNativeIsWaitingForGSInitTryMap = 0x1007dc40;
// R6GameService.dll data @ 1007dc54
constexpr unsigned int UR6GSServers_execNativeIsWaitingForGSInitExceptionInfo = 0x1007dc54;
// R6GameService.dll data @ 1007dc70
constexpr unsigned int UR6GSServers_execNativeIsGSReadyToChangeModUnwindMap = 0x1007dc70;
// R6GameService.dll data @ 1007dc80
constexpr unsigned int GexecNativeIsGSReadyToChangeModHandlers = 0x1007dc80;
// R6GameService.dll data @ 1007dca0
constexpr unsigned int UR6GSServers_execNativeIsGSReadyToChangeModTryMap = 0x1007dca0;
// R6GameService.dll data @ 1007dcb4
constexpr unsigned int UR6GSServers_execNativeIsGSReadyToChangeModExceptionInfo = 0x1007dcb4;
// R6GameService.dll data @ 1007dcd0
constexpr unsigned int UR6GSServers_SetGSClientComInterfaceUnwindMap = 0x1007dcd0;
// R6GameService.dll data @ 1007dce0
constexpr unsigned int GSetGSClientComInterfaceHandlers = 0x1007dce0;
// R6GameService.dll data @ 1007dd00
constexpr unsigned int UR6GSServers_SetGSClientComInterfaceTryMap = 0x1007dd00;
// R6GameService.dll data @ 1007dd14
constexpr unsigned int UR6GSServers_SetGSClientComInterfaceExceptionInfo = 0x1007dd14;
// R6GameService.dll data @ 1007dd30
constexpr unsigned int UR6GSServers_PollGSClientCallbacksUnwindMap = 0x1007dd30;
// R6GameService.dll data @ 1007dd48
constexpr unsigned int GGSPollHandlers = 0x1007dd48;
// R6GameService.dll data @ 1007dd68
constexpr unsigned int UR6GSServers_PollGSClientCallbacksTryMap = 0x1007dd68;
// R6GameService.dll data @ 1007dd7c
constexpr unsigned int UR6GSServers_PollGSClientCallbacksExceptionInfo = 0x1007dd7c;
// R6GameService.dll data @ 1007dd98
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoUnwindMap = 0x1007dd98;
// R6GameService.dll data @ 1007ddb8
constexpr unsigned int GServerInfoHandlers = 0x1007ddb8;
// R6GameService.dll data @ 1007ddd8
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoTryMap = 0x1007ddd8;
// R6GameService.dll data @ 1007ddec
constexpr unsigned int UR6GSServers_GSClientUpdateServerInfoExceptionInfo = 0x1007ddec;
// R6GameService.dll data @ 1007de08
constexpr unsigned int GetGameConfigCallbackUnwindMap = 0x1007de08;
// R6GameService.dll data @ 1007de18
constexpr unsigned int GetGameConfigCallbackExceptionInfo = 0x1007de18;
// R6GameService.dll data @ 1007de34
constexpr unsigned int UR6GSServers_InitGSClientUnwindMap = 0x1007de34;
// R6GameService.dll data @ 1007de44
constexpr unsigned int GInitGSClientHandlers = 0x1007de44;
// R6GameService.dll data @ 1007de64
constexpr unsigned int UR6GSServers_InitGSClientTryMap = 0x1007de64;
// R6GameService.dll data @ 1007de78
constexpr unsigned int UR6GSServers_InitGSClientExceptionInfo = 0x1007de78;
// R6GameService.dll data @ 1007de94
constexpr unsigned int UR6GSServers_LogOutServerUnwindMap = 0x1007de94;
// R6GameService.dll data @ 1007dea4
constexpr unsigned int GLogOutServerHandlers = 0x1007dea4;
// R6GameService.dll data @ 1007dec4
constexpr unsigned int UR6GSServers_LogOutServerTryMap = 0x1007dec4;
// R6GameService.dll data @ 1007ded8
constexpr unsigned int UR6GSServers_LogOutServerExceptionInfo = 0x1007ded8;
// R6GameService.dll data @ 1007def4
constexpr unsigned int UR6GSServers_execNativeLogOutServerUnwindMap = 0x1007def4;
// R6GameService.dll data @ 1007df04
constexpr unsigned int GexecNativeLogOutServerHandlers = 0x1007df04;
// R6GameService.dll data @ 1007df24
constexpr unsigned int UR6GSServers_execNativeLogOutServerTryMap = 0x1007df24;
// R6GameService.dll data @ 1007df38
constexpr unsigned int UR6GSServers_execNativeLogOutServerExceptionInfo = 0x1007df38;
// R6GameService.dll data @ 1007df54
constexpr unsigned int UR6GSServers_RegisterServerUnwindMap = 0x1007df54;
// R6GameService.dll data @ 1007df6c
constexpr unsigned int GRegisterServerHandlers = 0x1007df6c;
// R6GameService.dll data @ 1007df8c
constexpr unsigned int UR6GSServers_RegisterServerTryMap = 0x1007df8c;
// R6GameService.dll data @ 1007dfa0
constexpr unsigned int UR6GSServers_RegisterServerExceptionInfo = 0x1007dfa0;
// R6GameService.dll data @ 1007dfbc
constexpr unsigned int UR6GSServers_UpdateServerUnwindMap = 0x1007dfbc;
// R6GameService.dll data @ 1007dfd4
constexpr unsigned int GUpdateServerHandlers = 0x1007dfd4;
// R6GameService.dll data @ 1007dff4
constexpr unsigned int UR6GSServers_UpdateServerTryMap = 0x1007dff4;
// R6GameService.dll data @ 1007e008
constexpr unsigned int UR6GSServers_UpdateServerExceptionInfo = 0x1007e008;
// R6GameService.dll data @ 1007e024
constexpr unsigned int UR6GSServers_execNativeUpdateServerUnwindMap = 0x1007e024;
// R6GameService.dll data @ 1007e034
constexpr unsigned int GexecNativeUpdateServerHandlers = 0x1007e034;
// R6GameService.dll data @ 1007e054
constexpr unsigned int UR6GSServers_execNativeUpdateServerTryMap = 0x1007e054;
// R6GameService.dll data @ 1007e068
constexpr unsigned int UR6GSServers_execNativeUpdateServerExceptionInfo = 0x1007e068;
// R6GameService.dll data @ 1007e084
constexpr unsigned int UR6GSServers_ServerLoginUnwindMap = 0x1007e084;
// R6GameService.dll data @ 1007e094
constexpr unsigned int GServerLoginHandlers = 0x1007e094;
// R6GameService.dll data @ 1007e0b4
constexpr unsigned int UR6GSServers_ServerLoginTryMap = 0x1007e0b4;
// R6GameService.dll data @ 1007e0c8
constexpr unsigned int UR6GSServers_ServerLoginExceptionInfo = 0x1007e0c8;
// R6GameService.dll data @ 1007e0e4
constexpr unsigned int UR6GSServers_RouterDisconnectUnwindMap = 0x1007e0e4;
// R6GameService.dll data @ 1007e0f4
constexpr unsigned int GRouterDisconnectHandlers = 0x1007e0f4;
// R6GameService.dll data @ 1007e114
constexpr unsigned int UR6GSServers_RouterDisconnectTryMap = 0x1007e114;
// R6GameService.dll data @ 1007e128
constexpr unsigned int UR6GSServers_RouterDisconnectExceptionInfo = 0x1007e128;
// R6GameService.dll data @ 1007e144
constexpr unsigned int UR6GSServers_RegServerGetLobbiesUnwindMap = 0x1007e144;
// R6GameService.dll data @ 1007e154
constexpr unsigned int GRegServerGetLobbiesHandlers = 0x1007e154;
// R6GameService.dll data @ 1007e174
constexpr unsigned int UR6GSServers_RegServerGetLobbiesTryMap = 0x1007e174;
// R6GameService.dll data @ 1007e188
constexpr unsigned int UR6GSServers_RegServerGetLobbiesExceptionInfo = 0x1007e188;
// R6GameService.dll data @ 1007e1a4
constexpr unsigned int UR6GSServers_execHandleAnyLobbyConnectionFailUnwindMap = 0x1007e1a4;
// R6GameService.dll data @ 1007e1b4
constexpr unsigned int GexecHandleAnyLobbyConnectionFailHandlers = 0x1007e1b4;
// R6GameService.dll data @ 1007e1d4
constexpr unsigned int UR6GSServers_execHandleAnyLobbyConnectionFailTryMap = 0x1007e1d4;
// R6GameService.dll data @ 1007e1e8
constexpr unsigned int UR6GSServers_execHandleAnyLobbyConnectionFailExceptionInfo = 0x1007e1e8;
// R6GameService.dll data @ 1007e204
constexpr unsigned int UR6GSServers_InitProcessUpdateUbiServerUnwindMap = 0x1007e204;
// R6GameService.dll data @ 1007e214
constexpr unsigned int GInitProcessUpdateUbiServerHandlers = 0x1007e214;
// R6GameService.dll data @ 1007e234
constexpr unsigned int UR6GSServers_InitProcessUpdateUbiServerTryMap = 0x1007e234;
// R6GameService.dll data @ 1007e248
constexpr unsigned int UR6GSServers_InitProcessUpdateUbiServerExceptionInfo = 0x1007e248;
// R6GameService.dll data @ 1007e264
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRouterRequestUnwindMap = 0x1007e264;
// R6GameService.dll data @ 1007e274
constexpr unsigned int GProcessRegServerLoginRouterRequestHandlers = 0x1007e274;
// R6GameService.dll data @ 1007e294
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRouterRequestTryMap = 0x1007e294;
// R6GameService.dll data @ 1007e2a8
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRouterRequestExceptionInfo = 0x1007e2a8;
// R6GameService.dll data @ 1007e2c4
constexpr unsigned int UR6GSServers_ProcessRegServerGetLobbiesRequestUnwindMap = 0x1007e2c4;
// R6GameService.dll data @ 1007e2d4
constexpr unsigned int GProcessRegServerGetLobbiesRequestHandlers = 0x1007e2d4;
// R6GameService.dll data @ 1007e2f4
constexpr unsigned int UR6GSServers_ProcessRegServerGetLobbiesRequestTryMap = 0x1007e2f4;
// R6GameService.dll data @ 1007e308
constexpr unsigned int UR6GSServers_ProcessRegServerGetLobbiesRequestExceptionInfo = 0x1007e308;
// R6GameService.dll data @ 1007e324
constexpr unsigned int UR6GSServers_ProcessRegServerRegOnLobbyRequestUnwindMap = 0x1007e324;
// R6GameService.dll data @ 1007e334
constexpr unsigned int GProcessRegServerRegOnLobbyRequestHandlers = 0x1007e334;
// R6GameService.dll data @ 1007e354
constexpr unsigned int UR6GSServers_ProcessRegServerRegOnLobbyRequestTryMap = 0x1007e354;
// R6GameService.dll data @ 1007e368
constexpr unsigned int UR6GSServers_ProcessRegServerRegOnLobbyRequestExceptionInfo = 0x1007e368;
// R6GameService.dll data @ 1007e384
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRequestUnwindMap = 0x1007e384;
// R6GameService.dll data @ 1007e394
constexpr unsigned int GProcessRegServerLoginRequestHandlers = 0x1007e394;
// R6GameService.dll data @ 1007e3b4
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRequestTryMap = 0x1007e3b4;
// R6GameService.dll data @ 1007e3c8
constexpr unsigned int UR6GSServers_ProcessRegServerLoginRequestExceptionInfo = 0x1007e3c8;
// R6GameService.dll data @ 1007e3e4
constexpr unsigned int UR6GSServers_ProcessRegServerUpdateRequestUnwindMap = 0x1007e3e4;
// R6GameService.dll data @ 1007e3f4
constexpr unsigned int GProcessRegServerUpdateRequestHandlers = 0x1007e3f4;
// R6GameService.dll data @ 1007e414
constexpr unsigned int UR6GSServers_ProcessRegServerUpdateRequestTryMap = 0x1007e414;
// R6GameService.dll data @ 1007e428
constexpr unsigned int UR6GSServers_ProcessRegServerUpdateRequestExceptionInfo = 0x1007e428;
// R6GameService.dll data @ 1007e444
constexpr unsigned int UR6GSServers_ServerRoundStartUnwindMap = 0x1007e444;
// R6GameService.dll data @ 1007e454
constexpr unsigned int GServerRoundStartHandlers = 0x1007e454;
// R6GameService.dll data @ 1007e474
constexpr unsigned int UR6GSServers_ServerRoundStartTryMap = 0x1007e474;
// R6GameService.dll data @ 1007e488
constexpr unsigned int UR6GSServers_ServerRoundStartExceptionInfo = 0x1007e488;
// R6GameService.dll data @ 1007e4a4
constexpr unsigned int UR6GSServers_ServerRoundFinishUnwindMap = 0x1007e4a4;
// R6GameService.dll data @ 1007e4b4
constexpr unsigned int GServerRoundFinishHandlers = 0x1007e4b4;
// R6GameService.dll data @ 1007e4d4
constexpr unsigned int UR6GSServers_ServerRoundFinishTryMap = 0x1007e4d4;
// R6GameService.dll data @ 1007e4e8
constexpr unsigned int UR6GSServers_ServerRoundFinishExceptionInfo = 0x1007e4e8;
// R6GameService.dll data @ 1007e504
constexpr unsigned int unreal_array_support_DestroyArrayStorage6UnwindMap = 0x1007e504;
// R6GameService.dll data @ 1007e50c
constexpr unsigned int unreal_array_support_DestroyArrayStorage6ExceptionInfo = 0x1007e50c;
// R6GameService.dll data @ 1007e528
constexpr unsigned int UR6GSServers_InitializeRegServerUnwindMap = 0x1007e528;
// R6GameService.dll data @ 1007e538
constexpr unsigned int GInitializeRegServerHandlers = 0x1007e538;
// R6GameService.dll data @ 1007e558
constexpr unsigned int UR6GSServers_InitializeRegServerTryMap = 0x1007e558;
// R6GameService.dll data @ 1007e56c
constexpr unsigned int UR6GSServers_InitializeRegServerExceptionInfo = 0x1007e56c;
// R6GameService.dll data @ 1007e588
constexpr unsigned int UR6GSServers_ProcessInternetSrvUnwindMap = 0x1007e588;
// R6GameService.dll data @ 1007e598
constexpr unsigned int GProcessInternetSrvHandlers = 0x1007e598;
// R6GameService.dll data @ 1007e5b8
constexpr unsigned int UR6GSServers_ProcessInternetSrvTryMap = 0x1007e5b8;
// R6GameService.dll data @ 1007e5cc
constexpr unsigned int UR6GSServers_ProcessInternetSrvExceptionInfo = 0x1007e5cc;
// R6GameService.dll data @ 1007e5e8
constexpr unsigned int ServerPing_GetPingTimeUnwindMap = 0x1007e5e8;
// R6GameService.dll data @ 1007e5f8
constexpr unsigned int ServerPingGPingExchangeHandlers = 0x1007e5f8;
// R6GameService.dll data @ 1007e618
constexpr unsigned int ServerPing_GetPingTimeTryMap = 0x1007e618;
// R6GameService.dll data @ 1007e62c
constexpr unsigned int ServerPing_GetPingTimeExceptionInfo = 0x1007e62c;
// R6GameService.dll data @ 1007e648
constexpr unsigned int DestroyPingRecordUnwindMap = 0x1007e648;
// R6GameService.dll data @ 1007e650
constexpr unsigned int DestroyPingRecordExceptionInfo = 0x1007e650;
// R6GameService.dll data @ 1007e66c
constexpr unsigned int ServerPing_NewPingRequestUnwindMap = 0x1007e66c;
// R6GameService.dll data @ 1007e684
constexpr unsigned int ServerPingGPingRequestHandlers = 0x1007e684;
// R6GameService.dll data @ 1007e6a4
constexpr unsigned int ServerPing_NewPingRequestTryMap = 0x1007e6a4;
// R6GameService.dll data @ 1007e6b8
constexpr unsigned int ServerPing_NewPingRequestExceptionInfo = 0x1007e6b8;
// R6GameService.dll data @ 1007e6d4
constexpr unsigned int ServerPing_SendPingToServerUnwindMap = 0x1007e6d4;
// R6GameService.dll data @ 1007e6e4
constexpr unsigned int ServerPingGPingRequestHandlers2 = 0x1007e6e4;
// R6GameService.dll data @ 1007e704
constexpr unsigned int ServerPing_SendPingToServerTryMap = 0x1007e704;
// R6GameService.dll data @ 1007e718
constexpr unsigned int ServerPing_SendPingToServerExceptionInfo = 0x1007e718;
// R6GameService.dll data @ 1007e734
constexpr unsigned int ServerPing_PingManagerUnwindMap = 0x1007e734;
// R6GameService.dll data @ 1007e744
constexpr unsigned int GPollPingManagerHandlers = 0x1007e744;
// R6GameService.dll data @ 1007e764
constexpr unsigned int ServerPing_PingManagerTryMap = 0x1007e764;
// R6GameService.dll data @ 1007e778
constexpr unsigned int ServerPing_PingManagerExceptionInfo = 0x1007e778;
// R6GameService.dll data @ 1007e794
constexpr unsigned int DestroyPingRequestArrayUnwindMap = 0x1007e794;
// R6GameService.dll data @ 1007e79c
constexpr unsigned int DestroyPingRequestArrayExceptionInfo = 0x1007e79c;
// R6GameService.dll data @ 1007e7b8
constexpr unsigned int InitializePingRequestArrayUnwindMap = 0x1007e7b8;
// R6GameService.dll data @ 1007e7d0
constexpr unsigned int InitializePingRequestArrayExceptionInfo = 0x1007e7d0;
// R6GameService.dll data @ 1007e7ec
constexpr unsigned int CleanupWinsockAndPingRequestsUnwindMap = 0x1007e7ec;
// R6GameService.dll data @ 1007e804
constexpr unsigned int CleanupWinsockAndPingRequestsExceptionInfo = 0x1007e804;
// R6GameService.dll data @ 1007e820
constexpr unsigned int CreateRegisteredServiceWrapperUnwindMap = 0x1007e820;
// R6GameService.dll data @ 1007e848
constexpr unsigned int CreateRegisteredServiceWrapperExceptionInfo = 0x1007e848;
// R6GameService.dll data @ 1007e864
constexpr unsigned int DestroyHttpDownloadPointerMapUnwindMap = 0x1007e864;
// R6GameService.dll data @ 1007e874
constexpr unsigned int DestroyHttpDownloadPointerMapExceptionInfo = 0x1007e874;
// R6GameService.dll data @ 1007e890
constexpr unsigned int ReleaseCountedTreeAndHeaderUnwindMap = 0x1007e890;
// R6GameService.dll data @ 1007e898
constexpr unsigned int ReleaseCountedTreeAndHeaderExceptionInfo = 0x1007e898;
// R6GameService.dll data @ 1007e8b4
constexpr unsigned int InitializeHttpRequestRecordUnwindMap = 0x1007e8b4;
// R6GameService.dll data @ 1007e8f4
constexpr unsigned int InitializeHttpRequestRecordExceptionInfo = 0x1007e8f4;
// R6GameService.dll data @ 1007e910
constexpr unsigned int DestroyStringRecordRangeUnwindMap = 0x1007e910;
// R6GameService.dll data @ 1007e920
constexpr unsigned int DestroyStringRecordRangeExceptionInfo = 0x1007e920;
// R6GameService.dll data @ 1007e93c
constexpr unsigned int DestroyServiceObjectMembersUnwindMap = 0x1007e93c;
// R6GameService.dll data @ 1007e954
constexpr unsigned int DestroyServiceObjectMembersExceptionInfo = 0x1007e954;
// R6GameService.dll data @ 1007e970
constexpr unsigned int CHttpRequestParseHeaderUnwindMap = 0x1007e970;
// R6GameService.dll data @ 1007e9e8
constexpr unsigned int CHttpRequestParseHeaderExceptionInfo = 0x1007e9e8;
// R6GameService.dll data @ 1007ea04
constexpr unsigned int DestroyOrderedTreeWrapperContentsUnwindMap = 0x1007ea04;
// R6GameService.dll data @ 1007ea24
constexpr unsigned int DestroyOrderedTreeWrapperContentsExceptionInfo = 0x1007ea24;
// R6GameService.dll data @ 1007ea40
constexpr unsigned int ordered_tree_support_DestroyOrderedTreeWrapperContentsUnwindMap = 0x1007ea40;
// R6GameService.dll data @ 1007ea48
constexpr unsigned int ordered_tree_support_DestroyOrderedTreeWrapperContentsExceptionInfo = 0x1007ea48;
// R6GameService.dll data @ 1007ea64
constexpr unsigned int QueueHttpRequestUnwindMap = 0x1007ea64;
// R6GameService.dll data @ 1007ea6c
constexpr unsigned int QueueHttpRequestExceptionInfo = 0x1007ea6c;
// R6GameService.dll data @ 1007ea88
constexpr unsigned int ParseHttpUrlIntoRequestFieldsUnwindMap = 0x1007ea88;
// R6GameService.dll data @ 1007ead8
constexpr unsigned int ParseHttpUrlIntoRequestFieldsExceptionInfo = 0x1007ead8;
// R6GameService.dll throw-info @ 1007eb8c
constexpr unsigned int ByteStringLengthErrorThrowInfo = 0x1007eb8c;
// R6GameService.dll data @ 1007ebac
constexpr unsigned int CopyByteStringRangeUnwindMap = 0x1007ebac;
// R6GameService.dll data @ 1007ebdc
constexpr unsigned int CopyByteStringRangeExceptionInfo = 0x1007ebdc;
// R6GameService.dll data @ 1007ec40
constexpr unsigned int RebuildThreeWordArrayUnwindMap = 0x1007ec40;
// R6GameService.dll data @ 1007ec68
constexpr unsigned int string_record_supportGStringRecordEH9 = 0x1007ec68;
// R6GameService.dll data @ 1007ec78
constexpr unsigned int RebuildThreeWordArrayTryMap = 0x1007ec78;
// R6GameService.dll data @ 1007ec8c
constexpr unsigned int RebuildThreeWordArrayExceptionInfo = 0x1007ec8c;
// R6GameService.dll data @ 1007eca8
constexpr unsigned int ConstructPooledByteStringUnwindMap = 0x1007eca8;
// R6GameService.dll data @ 1007ecc0
constexpr unsigned int ConstructPooledByteStringExceptionInfo = 0x1007ecc0;
// R6GameService.dll data @ 1007ecdc
constexpr unsigned int CopyStringRecordRangeUnwindMap = 0x1007ecdc;
// R6GameService.dll data @ 1007ecfc
constexpr unsigned int string_record_supportGStringRecordEH = 0x1007ecfc;
// R6GameService.dll data @ 1007ed0c
constexpr unsigned int CopyStringRecordRangeTryMap = 0x1007ed0c;
// R6GameService.dll data @ 1007ed20
constexpr unsigned int CopyStringRecordRangeExceptionInfo = 0x1007ed20;
// R6GameService.dll data @ 1007ed3c
constexpr unsigned int RepeatStringRecordUnwindMap = 0x1007ed3c;
// R6GameService.dll data @ 1007ed5c
constexpr unsigned int string_record_supportGStringRecordEH5 = 0x1007ed5c;
// R6GameService.dll data @ 1007ed6c
constexpr unsigned int RepeatStringRecordTryMap = 0x1007ed6c;
// R6GameService.dll data @ 1007ed80
constexpr unsigned int RepeatStringRecordExceptionInfo = 0x1007ed80;
// R6GameService.dll data @ 1007ed9c
constexpr unsigned int ThrowByteStringLengthErrorUnwindMap = 0x1007ed9c;
// R6GameService.dll data @ 1007edac
constexpr unsigned int ThrowByteStringLengthErrorExceptionInfo = 0x1007edac;
// R6GameService.dll data @ 1007edc8
constexpr unsigned int AllocateSmallByteStringBlockUnwindMap = 0x1007edc8;
// R6GameService.dll data @ 1007edd0
constexpr unsigned int AllocateSmallByteStringBlockExceptionInfo = 0x1007edd0;
// R6GameService.dll data @ 1007edec
constexpr unsigned int ConstructHeapByteStringUnwindMap = 0x1007edec;
// R6GameService.dll data @ 1007ee04
constexpr unsigned int ConstructHeapByteStringExceptionInfo = 0x1007ee04;
// R6GameService.dll data @ 1007ee20
constexpr unsigned int DestroyStoredValueTreeUnwindMap = 0x1007ee20;
// R6GameService.dll data @ 1007ee28
constexpr unsigned int DestroyStoredValueTreeExceptionInfo = 0x1007ee28;
// R6GameService.dll data @ 1007ee44
constexpr unsigned int SerializeStoredValuesToBufferUnwindMap = 0x1007ee44;
// R6GameService.dll data @ 1007eeec
constexpr unsigned int SerializeStoredValuesToBufferExceptionInfo = 0x1007eeec;
// R6GameService.dll data @ 1007ef08
constexpr unsigned int AllocateAndTrackContextUnwindMap = 0x1007ef08;
// R6GameService.dll data @ 1007ef30
constexpr unsigned int AllocateAndTrackContextExceptionInfo = 0x1007ef30;
// R6GameService.dll data @ 1007ef9c
constexpr unsigned int ConstructCCDKeyProcessUnwindMap = 0x1007ef9c;
// R6GameService.dll data @ 1007f024
constexpr unsigned int ConstructCCDKeyProcessExceptionInfo = 0x1007f024;
// R6GameService.dll data @ 1007f040
constexpr unsigned int ordered_tree_supportSharedLifetimeUnwindMap = 0x1007f040;
// R6GameService.dll data @ 1007f048
constexpr unsigned int ordered_tree_supportSharedLifetimeExceptionInfo = 0x1007f048;
// R6GameService.dll data @ 1007f0f4
constexpr unsigned int DestroyServiceObjectUnwindMap = 0x1007f0f4;
// R6GameService.dll data @ 1007f14c
constexpr unsigned int DestroyServiceObjectExceptionInfo = 0x1007f14c;
// R6GameService.dll data @ 1007f168
constexpr unsigned int ProcessInputWithinTimeLimitUnwindMap = 0x1007f168;
// R6GameService.dll data @ 1007f198
constexpr unsigned int ProcessInputWithinTimeLimitExceptionInfo = 0x1007f198;
// R6GameService.dll data @ 1007f1b4
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwindMap = 0x1007f1b4;
// R6GameService.dll data @ 1007f1ec
constexpr unsigned int CCDKeyProcessSharedLifetimeExceptionInfo = 0x1007f1ec;
// R6GameService.dll data @ 1007f25c
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwindMap2 = 0x1007f25c;
// R6GameService.dll data @ 1007f2a4
constexpr unsigned int CCDKeyProcessSharedLifetimeExceptionInfo2 = 0x1007f2a4;
// R6GameService.dll data @ 1007f2c0
constexpr unsigned int DispatchParsedInputRecordUnwindMap = 0x1007f2c0;
// R6GameService.dll data @ 1007f308
constexpr unsigned int DispatchParsedInputRecordExceptionInfo = 0x1007f308;
// R6GameService.dll data @ 1007f324
constexpr unsigned int ParseTypeOneInputRecordUnwindMap = 0x1007f324;
// R6GameService.dll data @ 1007f37c
constexpr unsigned int ParseTypeOneInputRecordExceptionInfo = 0x1007f37c;
// R6GameService.dll data @ 1007f398
constexpr unsigned int ParseTypeTwoInputRecordUnwindMap = 0x1007f398;
// R6GameService.dll data @ 1007f3d8
constexpr unsigned int ParseTypeTwoInputRecordExceptionInfo = 0x1007f3d8;
// R6GameService.dll data @ 1007f3f4
constexpr unsigned int ParseTypeThreeInputRecordUnwindMap = 0x1007f3f4;
// R6GameService.dll data @ 1007f434
constexpr unsigned int ParseTypeThreeInputRecordExceptionInfo = 0x1007f434;
// R6GameService.dll data @ 1007f450
constexpr unsigned int ParseTypeFourInputRecordUnwindMap = 0x1007f450;
// R6GameService.dll data @ 1007f4a0
constexpr unsigned int ParseTypeFourInputRecordExceptionInfo = 0x1007f4a0;
// R6GameService.dll data @ 1007f4bc
constexpr unsigned int ParseTypeFiveInputRecordUnwindMap = 0x1007f4bc;
// R6GameService.dll data @ 1007f4f4
constexpr unsigned int ParseTypeFiveInputRecordExceptionInfo = 0x1007f4f4;
// R6GameService.dll data @ 1007f510
constexpr unsigned int SendTag11DescriptorUnwindMap = 0x1007f510;
// R6GameService.dll data @ 1007f548
constexpr unsigned int SendTag11DescriptorExceptionInfo = 0x1007f548;
// R6GameService.dll data @ 1007f564
constexpr unsigned int CCDKeyProcessSharedLifetimeUnwindMap3 = 0x1007f564;
// R6GameService.dll data @ 1007f59c
constexpr unsigned int CCDKeyProcessSharedLifetimeExceptionInfo3 = 0x1007f59c;
// R6GameService.dll data @ 1007f60c
constexpr unsigned int StoreTimestampedDescriptorRecordUnwindMap = 0x1007f60c;
// R6GameService.dll data @ 1007f63c
constexpr unsigned int StoreTimestampedDescriptorRecordExceptionInfo = 0x1007f63c;
// R6GameService.dll data @ 1007f658
constexpr unsigned int pooled_string_supportSharedLifetimeUnwindMap = 0x1007f658;
// R6GameService.dll data @ 1007f660
constexpr unsigned int pooled_string_supportSharedLifetimeExceptionInfo = 0x1007f660;
// R6GameService.dll data @ 1007f6c4
constexpr unsigned int ProcessExpiredInputRecordsUnwindMap = 0x1007f6c4;
// R6GameService.dll data @ 1007f6fc
constexpr unsigned int ProcessExpiredInputRecordsExceptionInfo = 0x1007f6fc;
// R6GameService.dll data @ 1007f718
constexpr unsigned int SendPeriodicCollectionSnapshotUnwindMap = 0x1007f718;
// R6GameService.dll data @ 1007f738
constexpr unsigned int SendPeriodicCollectionSnapshotExceptionInfo = 0x1007f738;
// R6GameService.dll data @ 1007f8f4
constexpr unsigned int CreateByteDescriptorTreeNodeUnwindMap = 0x1007f8f4;
// R6GameService.dll data @ 1007f914
constexpr unsigned int ordered_tree_supportGByteDescriptorNodeLifetimeData = 0x1007f914;
// R6GameService.dll data @ 1007f924
constexpr unsigned int CreateByteDescriptorTreeNodeTryMap = 0x1007f924;
// R6GameService.dll data @ 1007f938
constexpr unsigned int CreateByteDescriptorTreeNodeExceptionInfo = 0x1007f938;
// R6GameService.dll data @ 1007ff74
constexpr unsigned int ConstructByteTripletBufferUnwindMap = 0x1007ff74;
// R6GameService.dll data @ 1007ff9c
constexpr unsigned int ConstructByteTripletBufferExceptionInfo = 0x1007ff9c;
// R6GameService.dll data @ 100801b0
constexpr unsigned int ConstructQueuedConnectionUnwindMap = 0x100801b0;
// R6GameService.dll data @ 100801c8
constexpr unsigned int ConstructQueuedConnectionExceptionInfo = 0x100801c8;
// R6GameService.dll data @ 100801e4
constexpr unsigned int DestroyQueuedConnectionMembersUnwindMap = 0x100801e4;
// R6GameService.dll data @ 100801fc
constexpr unsigned int DestroyQueuedConnectionMembersExceptionInfo = 0x100801fc;
// R6GameService.dll data @ 10080218
constexpr unsigned int ConstructDatagramSocketOwnerUnwindMap = 0x10080218;
// R6GameService.dll data @ 10080220
constexpr unsigned int ConstructDatagramSocketOwnerExceptionInfo = 0x10080220;
// R6GameService.dll data @ 1008023c
constexpr unsigned int DestroyDatagramSocketOwnerUnwindMap = 0x1008023c;
// R6GameService.dll data @ 10080244
constexpr unsigned int DestroyDatagramSocketOwnerExceptionInfo = 0x10080244;
// R6GameService.dll data @ 10080284
constexpr unsigned int DestroyCircularListUnwindMap = 0x10080284;
// R6GameService.dll data @ 1008028c
constexpr unsigned int DestroyCircularListExceptionInfo = 0x1008028c;
// R6GameService.dll data @ 100802a8
constexpr unsigned int ConstructRegistrationServiceUnwindMap = 0x100802a8;
// R6GameService.dll data @ 100802b8
constexpr unsigned int ConstructRegistrationServiceExceptionInfo = 0x100802b8;
// R6GameService.dll data @ 100802d4
constexpr unsigned int registration_serviceSharedLifetimeUnwindMap = 0x100802d4;
// R6GameService.dll data @ 100802dc
constexpr unsigned int registration_serviceSharedLifetimeExceptionInfo = 0x100802dc;
// R6GameService.dll data @ 10080640
constexpr unsigned int DestroyParsedServiceRecordListUnwindMap = 0x10080640;
// R6GameService.dll data @ 10080648
constexpr unsigned int DestroyParsedServiceRecordListExceptionInfo = 0x10080648;
// R6GameService.dll data @ 10080688
constexpr unsigned int ConstructClonedPayloadWrapperUnwindMap = 0x10080688;
// R6GameService.dll data @ 10080698
constexpr unsigned int ConstructClonedPayloadWrapperExceptionInfo = 0x10080698;
// R6GameService.dll data @ 100806b4
constexpr unsigned int transport_wrapper_supportSharedLifetimeUnwindMap = 0x100806b4;
// R6GameService.dll data @ 100806bc
constexpr unsigned int transport_wrapper_supportSharedLifetimeExceptionInfo = 0x100806bc;
// R6GameService.dll data @ 100806fc
constexpr unsigned int DestroyServiceClientUnwindMap = 0x100806fc;
// R6GameService.dll data @ 10080704
constexpr unsigned int DestroyServiceClientExceptionInfo = 0x10080704;
// R6GameService.dll data @ 10080720
constexpr unsigned int clMSClient_clMSClientUnwindMap = 0x10080720;
// R6GameService.dll data @ 10080728
constexpr unsigned int clMSClient_clMSClientExceptionInfo = 0x10080728;
// R6GameService.dll data @ 10080744
constexpr unsigned int QueueProviderCallbackRecordUnwindMap = 0x10080744;
// R6GameService.dll data @ 1008076c
constexpr unsigned int QueueProviderCallbackRecordExceptionInfo = 0x1008076c;
// R6GameService.dll data @ 10080a50
constexpr unsigned int update_service_receiver_supportSharedLifetimeUnwindMap = 0x10080a50;
// R6GameService.dll data @ 10080a70
constexpr unsigned int update_service_receiver_supportSharedLifetimeExceptionInfo = 0x10080a70;
// R6GameService.dll data @ 10080a8c
constexpr unsigned int update_service_receiver_supportSharedLifetimeUnwindMap3 = 0x10080a8c;
// R6GameService.dll data @ 10080a9c
constexpr unsigned int update_service_receiver_supportSharedLifetimeExceptionInfo3 = 0x10080a9c;
// R6GameService.dll data @ 10080ab8
constexpr unsigned int update_service_receiver_supportSharedLifetimeUnwindMap2 = 0x10080ab8;
// R6GameService.dll data @ 10080ac0
constexpr unsigned int update_service_receiver_supportSharedLifetimeExceptionInfo2 = 0x10080ac0;
// R6GameService.dll data @ 10080c78
constexpr unsigned int process_launch_supportSharedLifetimeUnwindMap = 0x10080c78;
// R6GameService.dll data @ 10080ca8
constexpr unsigned int process_launch_supportSharedLifetimeExceptionInfo = 0x10080ca8;
// R6GameService.dll data @ 10080cc4
constexpr unsigned int text_conversion_supportSharedLifetimeUnwindMap = 0x10080cc4;
// R6GameService.dll data @ 10080ccc
constexpr unsigned int text_conversion_supportSharedLifetimeExceptionInfo = 0x10080ccc;
// R6GameService.dll data @ 10080ce8
constexpr unsigned int text_conversion_supportSharedLifetimeUnwindMap2 = 0x10080ce8;
// R6GameService.dll data @ 10080cf0
constexpr unsigned int text_conversion_supportSharedLifetimeExceptionInfo2 = 0x10080cf0;
// R6GameService.dll data @ 100812b8
constexpr unsigned int QueueMarkedClDataRecordUnwindMap = 0x100812b8;
// R6GameService.dll data @ 10081308
constexpr unsigned int QueueMarkedClDataRecordExceptionInfo = 0x10081308;
// R6GameService.dll data @ 10081324
constexpr unsigned int service_state_supportSharedLifetimeUnwindMap = 0x10081324;
// R6GameService.dll data @ 10081374
constexpr unsigned int service_state_supportSharedLifetimeExceptionInfo = 0x10081374;
// R6GameService.dll data @ 10081468
constexpr unsigned int ExtractRecordDispatchCodeUnwindMap = 0x10081468;
// R6GameService.dll data @ 10081498
constexpr unsigned int ExtractRecordDispatchCodeExceptionInfo = 0x10081498;
// R6GameService.dll data @ 100814b4
constexpr unsigned int OpenPrimaryConnectionUnwindMap = 0x100814b4;
// R6GameService.dll data @ 100814bc
constexpr unsigned int OpenPrimaryConnectionExceptionInfo = 0x100814bc;
// R6GameService.dll data @ 100814fc
constexpr unsigned int DestroyServiceTreeRecordUnwindMap = 0x100814fc;
// R6GameService.dll data @ 1008150c
constexpr unsigned int DestroyServiceTreeRecordExceptionInfo = 0x1008150c;
// R6GameService.dll data @ 10081528
constexpr unsigned int ordered_tree_supportSharedLifetimeUnwindMap3 = 0x10081528;
// R6GameService.dll data @ 10081530
constexpr unsigned int ordered_tree_supportSharedLifetimeExceptionInfo3 = 0x10081530;
// R6GameService.dll data @ 1008154c
constexpr unsigned int InitializeServiceRecordCollectionsUnwindMap = 0x1008154c;
// R6GameService.dll data @ 100815dc
constexpr unsigned int InitializeServiceRecordCollectionsExceptionInfo = 0x100815dc;
// R6GameService.dll data @ 10081664
constexpr unsigned int DestroyServiceSubobjectUnwindMap = 0x10081664;
// R6GameService.dll data @ 100816b4
constexpr unsigned int DestroyServiceSubobjectExceptionInfo = 0x100816b4;
// R6GameService.dll data @ 10081718
constexpr unsigned int TryReadServiceRecordTagAndValueUnwindMap = 0x10081718;
// R6GameService.dll data @ 10081748
constexpr unsigned int TryReadServiceRecordTagAndValueExceptionInfo = 0x10081748;
// R6GameService.dll data @ 10081764
constexpr unsigned int ApplySelectorOneServiceResponseUnwindMap = 0x10081764;
// R6GameService.dll data @ 100817a4
constexpr unsigned int ApplySelectorOneServiceResponseExceptionInfo = 0x100817a4;
// R6GameService.dll data @ 100817c0
constexpr unsigned int ApplySelectorTwoServiceResponseUnwindMap = 0x100817c0;
// R6GameService.dll data @ 10081800
constexpr unsigned int ApplySelectorTwoServiceResponseExceptionInfo = 0x10081800;
// R6GameService.dll data @ 1008181c
constexpr unsigned int clPointerMap_DestroyServiceTreeContainerUnwindMap = 0x1008181c;
// R6GameService.dll data @ 1008182c
constexpr unsigned int clPointerMap_DestroyServiceTreeContainerExceptionInfo = 0x1008182c;
// R6GameService.dll data @ 1008186c
constexpr unsigned int DestroyServiceTreeContainerVariantUnwindMap = 0x1008186c;
// R6GameService.dll data @ 1008187c
constexpr unsigned int DestroyServiceTreeContainerVariantExceptionInfo = 0x1008187c;
// R6GameService.dll data @ 10081898
constexpr unsigned int ordered_tree_supportSharedLifetimeUnwindMap4 = 0x10081898;
// R6GameService.dll data @ 100818a0
constexpr unsigned int ordered_tree_supportSharedLifetimeExceptionInfo4 = 0x100818a0;
// R6GameService.dll data @ 100818bc
constexpr unsigned int payload_reference_supportSharedLifetimeUnwindMap = 0x100818bc;
// R6GameService.dll data @ 100818c4
constexpr unsigned int payload_reference_supportSharedLifetimeExceptionInfo = 0x100818c4;
// R6GameService.dll data @ 100818e0
constexpr unsigned int ConstructServiceProtocolDispatcherUnwindMap = 0x100818e0;
// R6GameService.dll data @ 10081910
constexpr unsigned int ConstructServiceProtocolDispatcherExceptionInfo = 0x10081910;
// R6GameService.dll data @ 1008192c
constexpr unsigned int ClearProtocolDispatcherTreeUnwindMap = 0x1008192c;
// R6GameService.dll data @ 10081934
constexpr unsigned int ClearProtocolDispatcherTreeExceptionInfo = 0x10081934;
// R6GameService.dll data @ 10081950
constexpr unsigned int DestroyServiceProtocolDispatcherUnwindMap = 0x10081950;
// R6GameService.dll data @ 10081960
constexpr unsigned int DestroyServiceProtocolDispatcherExceptionInfo = 0x10081960;
// R6GameService.dll data @ 1008197c
constexpr unsigned int CheckD1DescriptorAndOptionalIndexUnwindMap = 0x1008197c;
// R6GameService.dll data @ 100819ac
constexpr unsigned int CheckD1DescriptorAndOptionalIndexExceptionInfo = 0x100819ac;
// R6GameService.dll data @ 100819c8
constexpr unsigned int TryReadType35DescriptorFieldsUnwindMap = 0x100819c8;
// R6GameService.dll data @ 10081a08
constexpr unsigned int TryReadType35DescriptorFieldsExceptionInfo = 0x10081a08;
// R6GameService.dll data @ 10081a24
constexpr unsigned int ReadType36DescriptorShortUnwindMap = 0x10081a24;
// R6GameService.dll data @ 10081a64
constexpr unsigned int ReadType36DescriptorShortExceptionInfo = 0x10081a64;
// R6GameService.dll data @ 10081a80
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthUnwindMap = 0x10081a80;
// R6GameService.dll data @ 10081aa8
constexpr unsigned int CopyIndexedClDataBinaryAndGetLengthExceptionInfo = 0x10081aa8;
// R6GameService.dll data @ 10081ac4
constexpr unsigned int TryGetType38IndexedBinaryLengthUnwindMap = 0x10081ac4;
// R6GameService.dll data @ 10081b14
constexpr unsigned int TryGetType38IndexedBinaryLengthExceptionInfo = 0x10081b14;
// R6GameService.dll data @ 10081b30
constexpr unsigned int InitializeTransportRecordIfAbsentUnwindMap = 0x10081b30;
// R6GameService.dll data @ 10081b38
constexpr unsigned int InitializeTransportRecordIfAbsentExceptionInfo = 0x10081b38;
// R6GameService.dll data @ 10081b54
constexpr unsigned int HandleSelector13RecordRemovalUnwindMap = 0x10081b54;
// R6GameService.dll data @ 10081b9c
constexpr unsigned int HandleSelector13RecordRemovalExceptionInfo = 0x10081b9c;
// R6GameService.dll data @ 10081bb8
constexpr unsigned int SendTransportRequestPayloadUnwindMap = 0x10081bb8;
// R6GameService.dll data @ 10081bf8
constexpr unsigned int SendTransportRequestPayloadExceptionInfo = 0x10081bf8;
// R6GameService.dll data @ 10081c14
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyUnwindMap = 0x10081c14;
// R6GameService.dll data @ 10081c54
constexpr unsigned int transport_record_support_DispatchRequest18ByKeyExceptionInfo = 0x10081c54;
// R6GameService.dll data @ 10081ccc
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap8 = 0x10081ccc;
// R6GameService.dll data @ 10081cfc
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo8 = 0x10081cfc;
// R6GameService.dll data @ 10081d64
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap7 = 0x10081d64;
// R6GameService.dll data @ 10081da4
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo7 = 0x10081da4;
// R6GameService.dll data @ 10081e58
constexpr unsigned int SendBinaryRequest2aUnwindMap = 0x10081e58;
// R6GameService.dll data @ 10081e98
constexpr unsigned int SendBinaryRequest2aExceptionInfo = 0x10081e98;
// R6GameService.dll data @ 10081eb4
constexpr unsigned int ReadServiceState9UnwindMap = 0x10081eb4;
// R6GameService.dll data @ 10081eec
constexpr unsigned int ReadServiceState9ExceptionInfo = 0x10081eec;
// R6GameService.dll data @ 10081f08
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap2 = 0x10081f08;
// R6GameService.dll data @ 10081f48
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo2 = 0x10081f48;
// R6GameService.dll data @ 10081fc0
constexpr unsigned int ProcessKeyRecordTokenUnwindMap = 0x10081fc0;
// R6GameService.dll data @ 10082008
constexpr unsigned int ProcessKeyRecordTokenExceptionInfo = 0x10082008;
// R6GameService.dll data @ 10082024
constexpr unsigned int ProcessIndexedTextUpdateUnwindMap = 0x10082024;
// R6GameService.dll data @ 10082044
constexpr unsigned int ProcessIndexedTextUpdateExceptionInfo = 0x10082044;
// R6GameService.dll data @ 10082060
constexpr unsigned int RemoveDecodedKeyRecordUnwindMap = 0x10082060;
// R6GameService.dll data @ 100820b0
constexpr unsigned int RemoveDecodedKeyRecordExceptionInfo = 0x100820b0;
// R6GameService.dll data @ 100820cc
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap = 0x100820cc;
// R6GameService.dll data @ 100820ec
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo = 0x100820ec;
// R6GameService.dll data @ 100821c0
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap6 = 0x100821c0;
// R6GameService.dll data @ 100821e8
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo6 = 0x100821e8;
// R6GameService.dll data @ 100823a0
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap3 = 0x100823a0;
// R6GameService.dll data @ 100823e8
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo3 = 0x100823e8;
// R6GameService.dll data @ 100824ac
constexpr unsigned int DispatchSelector20EntriesUnwindMap = 0x100824ac;
// R6GameService.dll data @ 100824e4
constexpr unsigned int DispatchSelector20EntriesExceptionInfo = 0x100824e4;
// R6GameService.dll data @ 100825a8
constexpr unsigned int ExtractCachedBinaryRecordFieldsUnwindMap = 0x100825a8;
// R6GameService.dll data @ 100825d8
constexpr unsigned int ExtractCachedBinaryRecordFieldsExceptionInfo = 0x100825d8;
// R6GameService.dll data @ 100825f4
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap4 = 0x100825f4;
// R6GameService.dll data @ 1008262c
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo4 = 0x1008262c;
// R6GameService.dll data @ 10082648
constexpr unsigned int request_state_supportSharedLifetimeUnwindMap5 = 0x10082648;
// R6GameService.dll data @ 10082660
constexpr unsigned int request_state_supportSharedLifetimeExceptionInfo5 = 0x10082660;
// R6GameService.dll data @ 100826b0
constexpr unsigned int ParseSelector3fValueAndTextUnwindMap = 0x100826b0;
// R6GameService.dll data @ 100826f0
constexpr unsigned int ParseSelector3fValueAndTextExceptionInfo = 0x100826f0;
// R6GameService.dll data @ 1008270c
constexpr unsigned int ParseSelector41IndexedValueUnwindMap = 0x1008270c;
// R6GameService.dll data @ 10082754
constexpr unsigned int ParseSelector41IndexedValueExceptionInfo = 0x10082754;
// R6GameService.dll data @ 10082770
constexpr unsigned int DispatchSelector36RecordUnwindMap = 0x10082770;
// R6GameService.dll data @ 100827b0
constexpr unsigned int DispatchSelector36RecordExceptionInfo = 0x100827b0;
// R6GameService.dll data @ 100827cc
constexpr unsigned int DispatchSelector35SubrecordsUnwindMap = 0x100827cc;
// R6GameService.dll data @ 1008280c
constexpr unsigned int DispatchSelector35SubrecordsExceptionInfo = 0x1008280c;
// R6GameService.dll data @ 10082828
constexpr unsigned int DispatchSelector32RecordUnwindMap = 0x10082828;
// R6GameService.dll data @ 10082840
constexpr unsigned int DispatchSelector32RecordExceptionInfo = 0x10082840;
// R6GameService.dll data @ 1008285c
constexpr unsigned int DispatchSelector33IndexedValuesUnwindMap = 0x1008285c;
// R6GameService.dll data @ 1008288c
constexpr unsigned int DispatchSelector33IndexedValuesExceptionInfo = 0x1008288c;
// R6GameService.dll data @ 100828a8
constexpr unsigned int DispatchSelector97StringFlagRecordsUnwindMap = 0x100828a8;
// R6GameService.dll data @ 100828d0
constexpr unsigned int DispatchSelector97StringFlagRecordsExceptionInfo = 0x100828d0;
// R6GameService.dll data @ 100828ec
constexpr unsigned int DispatchSelector40TextValuesUnwindMap = 0x100828ec;
// R6GameService.dll data @ 10082934
constexpr unsigned int DispatchSelector40TextValuesExceptionInfo = 0x10082934;
// R6GameService.dll data @ 10082950
constexpr unsigned int DispatchSelector42TextAndBinaryUnwindMap = 0x10082950;
// R6GameService.dll data @ 10082970
constexpr unsigned int DispatchSelector42TextAndBinaryExceptionInfo = 0x10082970;
// R6GameService.dll data @ 1008298c
constexpr unsigned int DispatchSelector6aTextAndPairsUnwindMap = 0x1008298c;
// R6GameService.dll data @ 100829bc
constexpr unsigned int DispatchSelector6aTextAndPairsExceptionInfo = 0x100829bc;
// R6GameService.dll data @ 100829d8
constexpr unsigned int DispatchSelector47VariantPayloadUnwindMap = 0x100829d8;
// R6GameService.dll data @ 10082a10
constexpr unsigned int DispatchSelector47VariantPayloadExceptionInfo = 0x10082a10;
// R6GameService.dll data @ 10082a2c
constexpr unsigned int PassesOptionalServiceTreeNameFilterUnwindMap = 0x10082a2c;
// R6GameService.dll data @ 10082a4c
constexpr unsigned int PassesOptionalServiceTreeNameFilterExceptionInfo = 0x10082a4c;
// R6GameService.dll data @ 10082a68
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedTextUnwindMap = 0x10082a68;
// R6GameService.dll data @ 10082a88
constexpr unsigned int ReplaceServiceTreeNamesFromDelimitedTextExceptionInfo = 0x10082a88;
// R6GameService.dll data @ 10082aa4
constexpr unsigned int CreateServiceTreeByteStringNodeUnwindMap = 0x10082aa4;
// R6GameService.dll data @ 10082ac4
constexpr unsigned int ordered_tree_supportGServiceStringNodeEH = 0x10082ac4;
// R6GameService.dll data @ 10082ad4
constexpr unsigned int CreateServiceTreeByteStringNodeTryMap = 0x10082ad4;
// R6GameService.dll data @ 10082ae8
constexpr unsigned int CreateServiceTreeByteStringNodeExceptionInfo = 0x10082ae8;
// R6GameService.dll data @ 10082c08
constexpr unsigned int shared_nativeSharedLifetimeUnwindMap = 0x10082c08;
// R6GameService.dll data @ 10082c10
constexpr unsigned int shared_nativeSharedLifetimeExceptionInfo = 0x10082c10;
// R6GameService.dll data @ 10082c50
constexpr unsigned int CConnectionListDestroyUnwindMap = 0x10082c50;
// R6GameService.dll data @ 10082c78
constexpr unsigned int CConnectionListDestroyExceptionInfo = 0x10082c78;
// R6GameService.dll data @ 10082c94
constexpr unsigned int CConnectionListConstructUnwindMap = 0x10082c94;
// R6GameService.dll data @ 10082c9c
constexpr unsigned int CConnectionListConstructExceptionInfo = 0x10082c9c;
// R6GameService.dll data @ 10082cdc
constexpr unsigned int list_node_supportSharedLifetimeUnwindMap = 0x10082cdc;
// R6GameService.dll data @ 10082ce4
constexpr unsigned int list_node_supportSharedLifetimeExceptionInfo = 0x10082ce4;
// R6GameService.dll data @ 10082d24
constexpr unsigned int ReadTransportSelectorRecordUnwindMap = 0x10082d24;
// R6GameService.dll data @ 10082d74
constexpr unsigned int ReadTransportSelectorRecordExceptionInfo = 0x10082d74;
// R6GameService.dll data @ 10082ddc
constexpr unsigned int transport_record_supportSharedLifetimeUnwindMap = 0x10082ddc;
// R6GameService.dll data @ 10082e0c
constexpr unsigned int transport_record_supportSharedLifetimeExceptionInfo = 0x10082e0c;
// R6GameService.dll data @ 10082e8c
constexpr unsigned int ParseSelector5aOwnedBytesUnwindMap = 0x10082e8c;
// R6GameService.dll data @ 10082ecc
constexpr unsigned int ParseSelector5aOwnedBytesExceptionInfo = 0x10082ecc;
// R6GameService.dll data @ 10082ee8
constexpr unsigned int transport_record_supportSharedLifetimeUnwindMap2 = 0x10082ee8;
// R6GameService.dll data @ 10082f30
constexpr unsigned int transport_record_supportSharedLifetimeExceptionInfo2 = 0x10082f30;
// R6GameService.dll data @ 10082f4c
constexpr unsigned int ParseSelector08FieldsUnwindMap = 0x10082f4c;
// R6GameService.dll data @ 10082f9c
constexpr unsigned int ParseSelector08FieldsExceptionInfo = 0x10082f9c;
// R6GameService.dll data @ 10082fb8
constexpr unsigned int ParseSelector98FieldsUnwindMap = 0x10082fb8;
// R6GameService.dll data @ 10083000
constexpr unsigned int ParseSelector98FieldsExceptionInfo = 0x10083000;
// R6GameService.dll data @ 10083070
constexpr unsigned int transport_record_supportSharedLifetimeUnwindMap3 = 0x10083070;
// R6GameService.dll data @ 100830a8
constexpr unsigned int transport_record_supportSharedLifetimeExceptionInfo3 = 0x100830a8;
// R6GameService.dll data @ 100830c4
constexpr unsigned int ValidateParserSelectorAndOptionalWordUnwindMap = 0x100830c4;
// R6GameService.dll data @ 10083114
constexpr unsigned int ValidateParserSelectorAndOptionalWordExceptionInfo = 0x10083114;
// R6GameService.dll data @ 10083130
constexpr unsigned int SendSelector66StringTupleUnwindMap = 0x10083130;
// R6GameService.dll data @ 10083160
constexpr unsigned int SendSelector66StringTupleExceptionInfo = 0x10083160;
// R6GameService.dll data @ 1008317c
constexpr unsigned int transport_record_supportSharedLifetimeUnwindMap4 = 0x1008317c;
// R6GameService.dll data @ 100831ac
constexpr unsigned int transport_record_supportSharedLifetimeExceptionInfo4 = 0x100831ac;
// R6GameService.dll data @ 100831c8
constexpr unsigned int SendEmptySelector5dUnwindMap = 0x100831c8;
// R6GameService.dll data @ 100831f8
constexpr unsigned int SendEmptySelector5dExceptionInfo = 0x100831f8;
// R6GameService.dll data @ 10083260
constexpr unsigned int ParseSelector13RecordIntoOutputsUnwindMap = 0x10083260;
// R6GameService.dll data @ 10083280
constexpr unsigned int ParseSelector13RecordIntoOutputsExceptionInfo = 0x10083280;
// R6GameService.dll data @ 1008329c
constexpr unsigned int ParseSelector5dRecordIntoOutputsUnwindMap = 0x1008329c;
// R6GameService.dll data @ 100832e4
constexpr unsigned int ParseSelector5dRecordIntoOutputsExceptionInfo = 0x100832e4;
// R6GameService.dll data @ 10083300
constexpr unsigned int ParseSelectorDETextFieldsUnwindMap = 0x10083300;
// R6GameService.dll data @ 10083348
constexpr unsigned int ParseSelectorDETextFieldsExceptionInfo = 0x10083348;
// R6GameService.dll data @ 10083364
constexpr unsigned int DestroyIndexedRecordCollectionStateUnwindMap = 0x10083364;
// R6GameService.dll data @ 10083394
constexpr unsigned int DestroyIndexedRecordCollectionStateExceptionInfo = 0x10083394;
// R6GameService.dll data @ 100833d4
constexpr unsigned int EnsureOuterRecordExistsUnwindMap = 0x100833d4;
// R6GameService.dll data @ 100833fc
constexpr unsigned int EnsureOuterRecordExistsExceptionInfo = 0x100833fc;
// R6GameService.dll data @ 10083460
constexpr unsigned int RemoveNestedRecordsByOuterKeyUnwindMap = 0x10083460;
// R6GameService.dll data @ 10083490
constexpr unsigned int RemoveNestedRecordsByOuterKeyExceptionInfo = 0x10083490;
// R6GameService.dll data @ 100834ac
constexpr unsigned int ApplyNestedRecordUpdateByTextPairUnwindMap = 0x100834ac;
// R6GameService.dll data @ 100834fc
constexpr unsigned int ApplyNestedRecordUpdateByTextPairExceptionInfo = 0x100834fc;
// R6GameService.dll data @ 10083518
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesUnwindMap = 0x10083518;
// R6GameService.dll data @ 10083550
constexpr unsigned int ResetOuterRecordAndFlushQueuedUpdatesExceptionInfo = 0x10083550;
// R6GameService.dll data @ 1008356c
constexpr unsigned int QueueMissingNestedRecordRequestUnwindMap = 0x1008356c;
// R6GameService.dll data @ 100835a4
constexpr unsigned int QueueMissingNestedRecordRequestExceptionInfo = 0x100835a4;
// R6GameService.dll data @ 100835e4
constexpr unsigned int indexed_record_supportSharedLifetimeUnwindMap2 = 0x100835e4;
// R6GameService.dll data @ 100835ec
constexpr unsigned int indexed_record_supportSharedLifetimeExceptionInfo2 = 0x100835ec;
// R6GameService.dll data @ 10083608
constexpr unsigned int CopyRecordStateAndNestedTreeUnwindMap = 0x10083608;
// R6GameService.dll data @ 10083620
constexpr unsigned int CopyRecordStateAndNestedTreeExceptionInfo = 0x10083620;
// R6GameService.dll data @ 1008363c
constexpr unsigned int CloneOrderedTreeSubtreeUnwindMap = 0x1008363c;
// R6GameService.dll data @ 1008364c
constexpr unsigned int ordered_tree_supportGRecordTreeCopyEH = 0x1008364c;
// R6GameService.dll data @ 1008365c
constexpr unsigned int CloneOrderedTreeSubtreeTryMap = 0x1008365c;
// R6GameService.dll data @ 10083670
constexpr unsigned int CloneOrderedTreeSubtreeExceptionInfo = 0x10083670;
// R6GameService.dll data @ 1008368c
constexpr unsigned int AllocateTreeNodeWithCopiedExtendedPayloadUnwindMap = 0x1008368c;
// R6GameService.dll data @ 100836a4
constexpr unsigned int ordered_tree_supportGExtendedNodeCopyEH = 0x100836a4;
// R6GameService.dll data @ 100836b4
constexpr unsigned int AllocateTreeNodeWithCopiedExtendedPayloadTryMap = 0x100836b4;
// R6GameService.dll data @ 100836c8
constexpr unsigned int AllocateTreeNodeWithCopiedExtendedPayloadExceptionInfo = 0x100836c8;
// R6GameService.dll data @ 100836e4
constexpr unsigned int indexed_record_supportSharedLifetimeUnwindMap = 0x100836e4;
// R6GameService.dll data @ 100836ec
constexpr unsigned int indexed_record_supportSharedLifetimeExceptionInfo = 0x100836ec;
// R6GameService.dll data @ 10083708
constexpr unsigned int CLobbySrvConnectionListConstructUnwindMap = 0x10083708;
// R6GameService.dll data @ 10083760
constexpr unsigned int CLobbySrvConnectionListConstructExceptionInfo = 0x10083760;
// R6GameService.dll data @ 1008377c
constexpr unsigned int CLobbySrvConnectionListDestroyUnwindMap = 0x1008377c;
// R6GameService.dll data @ 100837b4
constexpr unsigned int CLobbySrvConnectionListDestroyExceptionInfo = 0x100837b4;
// R6GameService.dll data @ 100837d0
constexpr unsigned int ReleaseIndexedTreeUnwindMap = 0x100837d0;
// R6GameService.dll data @ 100837d8
constexpr unsigned int ReleaseIndexedTreeExceptionInfo = 0x100837d8;
// R6GameService.dll data @ 100837f4
constexpr unsigned int NotifyAndRemoveKeyRecordsUnwindMap = 0x100837f4;
// R6GameService.dll data @ 10083844
constexpr unsigned int NotifyAndRemoveKeyRecordsExceptionInfo = 0x10083844;
// R6GameService.dll data @ 10083860
constexpr unsigned int UpdateKeyedTextAndNotifyUnwindMap = 0x10083860;
// R6GameService.dll data @ 100838a0
constexpr unsigned int UpdateKeyedTextAndNotifyExceptionInfo = 0x100838a0;
// R6GameService.dll data @ 100838bc
constexpr unsigned int SendKeyNotificationD1UnwindMap = 0x100838bc;
// R6GameService.dll data @ 100838fc
constexpr unsigned int SendKeyNotificationD1ExceptionInfo = 0x100838fc;
// R6GameService.dll data @ 10083918
constexpr unsigned int BuildRecordFromQueueHeadOrFallbackUnwindMap = 0x10083918;
// R6GameService.dll data @ 10083920
constexpr unsigned int BuildRecordFromQueueHeadOrFallbackExceptionInfo = 0x10083920;
// R6GameService.dll data @ 1008393c
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsUnwindMap = 0x1008393c;
// R6GameService.dll data @ 10083974
constexpr unsigned int RemoveIndexedRecordAndQueueNotificationsExceptionInfo = 0x10083974;
// R6GameService.dll data @ 10083990
constexpr unsigned int ApplyIndexedKeyUpdateUnwindMap = 0x10083990;
// R6GameService.dll data @ 100839d0
constexpr unsigned int ApplyIndexedKeyUpdateExceptionInfo = 0x100839d0;
// R6GameService.dll data @ 100839ec
constexpr unsigned int QueueTaggedRecordUnwindMap = 0x100839ec;
// R6GameService.dll data @ 10083a0c
constexpr unsigned int QueueTaggedRecordExceptionInfo = 0x10083a0c;
// R6GameService.dll data @ 10083a28
constexpr unsigned int SendDescriptorAsD1UnwindMap = 0x10083a28;
// R6GameService.dll data @ 10083a68
constexpr unsigned int SendDescriptorAsD1ExceptionInfo = 0x10083a68;
// R6GameService.dll data @ 10083a84
constexpr unsigned int InsertIndexedTextRecordUnwindMap = 0x10083a84;
// R6GameService.dll data @ 10083aac
constexpr unsigned int InsertIndexedTextRecordExceptionInfo = 0x10083aac;
// R6GameService.dll data @ 10083ac8
constexpr unsigned int CloneCircularListUnwindMap = 0x10083ac8;
// R6GameService.dll data @ 10083ad0
constexpr unsigned int CloneCircularListExceptionInfo = 0x10083ad0;
// R6GameService.dll data @ 10083aec
constexpr unsigned int AllocateIndexedRecordAndCopyListUnwindMap = 0x10083aec;
// R6GameService.dll data @ 10083b0c
constexpr unsigned int indexed_record_supportGIndexedListNodeEH = 0x10083b0c;
// R6GameService.dll data @ 10083b1c
constexpr unsigned int AllocateIndexedRecordAndCopyListTryMap = 0x10083b1c;
// R6GameService.dll data @ 10083b30
constexpr unsigned int AllocateIndexedRecordAndCopyListExceptionInfo = 0x10083b30;
// R6GameService.dll data @ 10083b4c
constexpr unsigned int UpdateStringKeyedRecordUnwindMap = 0x10083b4c;
// R6GameService.dll data @ 10083ba4
constexpr unsigned int UpdateStringKeyedRecordExceptionInfo = 0x10083ba4;
// R6GameService.dll data @ 10083bc0
constexpr unsigned int DestroyOwnedListUnwindMap = 0x10083bc0;
// R6GameService.dll data @ 10083bd0
constexpr unsigned int DestroyOwnedListExceptionInfo = 0x10083bd0;
// R6GameService.dll data @ 10083bec
constexpr unsigned int AppendOrderedRecordsToDescriptorUnwindMap = 0x10083bec;
// R6GameService.dll data @ 10083c0c
constexpr unsigned int AppendOrderedRecordsToDescriptorExceptionInfo = 0x10083c0c;
// R6GameService.dll data @ 10083c28
constexpr unsigned int ConstructHeapByteStringFromCStringUnwindMap = 0x10083c28;
// R6GameService.dll data @ 10083c48
constexpr unsigned int ConstructHeapByteStringFromCStringExceptionInfo = 0x10083c48;
// R6GameService.dll data @ 10083c64
constexpr unsigned int ConstructIndexedRecordCopyUnwindMap = 0x10083c64;
// R6GameService.dll data @ 10083c6c
constexpr unsigned int ConstructIndexedRecordCopyExceptionInfo = 0x10083c6c;
// R6GameService.dll data @ 10083cac
constexpr unsigned int ordered_tree_support_CloneOrderedTreeSubtreeUnwindMap = 0x10083cac;
// R6GameService.dll data @ 10083cbc
constexpr unsigned int ordered_tree_supportGIndexedCloneEH = 0x10083cbc;
// R6GameService.dll data @ 10083ccc
constexpr unsigned int ordered_tree_support_CloneOrderedTreeSubtreeTryMap = 0x10083ccc;
// R6GameService.dll data @ 10083ce0
constexpr unsigned int ordered_tree_support_CloneOrderedTreeSubtreeExceptionInfo = 0x10083ce0;
// R6GameService.dll data @ 10083cfc
constexpr unsigned int AllocateIndexedTreeNodeUnwindMap = 0x10083cfc;
// R6GameService.dll data @ 10083d24
constexpr unsigned int ordered_tree_supportGIndexedCloneEH5 = 0x10083d24;
// R6GameService.dll data @ 10083d34
constexpr unsigned int AllocateIndexedTreeNodeTryMap = 0x10083d34;
// R6GameService.dll data @ 10083d48
constexpr unsigned int AllocateIndexedTreeNodeExceptionInfo = 0x10083d48;
// R6GameService.dll data @ 10083d64
constexpr unsigned int ordered_tree_supportSharedLifetimeUnwindMap2 = 0x10083d64;
// R6GameService.dll data @ 10083d6c
constexpr unsigned int ordered_tree_supportSharedLifetimeExceptionInfo2 = 0x10083d6c;
// R6GameService.dll data @ 10083d88
constexpr unsigned int AppendIndexedValuesToDescriptorUnwindMap = 0x10083d88;
// R6GameService.dll data @ 10083da8
constexpr unsigned int AppendIndexedValuesToDescriptorExceptionInfo = 0x10083da8;
// R6GameService.dll data @ 10083df8
constexpr unsigned int InitializeTransportRecordUnwindMap = 0x10083df8;
// R6GameService.dll data @ 10083e50
constexpr unsigned int InitializeTransportRecordExceptionInfo = 0x10083e50;
// R6GameService.dll data @ 10083eb4
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionUnwindMap = 0x10083eb4;
// R6GameService.dll data @ 10083edc
constexpr unsigned int InitializeTransportRecordWithOptionalConnectionExceptionInfo = 0x10083edc;
// R6GameService.dll data @ 10083ef8
constexpr unsigned int DestroyTransportRecordMembersUnwindMap = 0x10083ef8;
// R6GameService.dll data @ 10083f38
constexpr unsigned int DestroyTransportRecordMembersExceptionInfo = 0x10083f38;
// R6GameService.dll data @ 10083f54
constexpr unsigned int SendTransportControlRecordWithDecimalValueUnwindMap = 0x10083f54;
// R6GameService.dll data @ 10083f84
constexpr unsigned int SendTransportControlRecordWithDecimalValueExceptionInfo = 0x10083f84;
// R6GameService.dll data @ 10083fa0
constexpr unsigned int UpdateTransportProviderUnwindMap = 0x10083fa0;
// R6GameService.dll data @ 10083fc8
constexpr unsigned int UpdateTransportProviderExceptionInfo = 0x10083fc8;
// R6GameService.dll data @ 100840a8
constexpr unsigned int provider_control_supportSharedLifetimeUnwindMap = 0x100840a8;
// R6GameService.dll data @ 100840b0
constexpr unsigned int provider_control_supportSharedLifetimeExceptionInfo = 0x100840b0;
// R6GameService.dll data @ 100840cc
constexpr unsigned int DispatchProviderControlPayloadUnwindMap = 0x100840cc;
// R6GameService.dll data @ 1008410c
constexpr unsigned int DispatchProviderControlPayloadExceptionInfo = 0x1008410c;
// R6GameService.dll data @ 10084128
constexpr unsigned int HandleTransportBufferControlPayloadUnwindMap = 0x10084128;
// R6GameService.dll data @ 10084178
constexpr unsigned int HandleTransportBufferControlPayloadExceptionInfo = 0x10084178;
// R6GameService.dll data @ 100841e8
constexpr unsigned int provider_control_supportSharedLifetimeUnwindMap2 = 0x100841e8;
// R6GameService.dll data @ 10084220
constexpr unsigned int provider_control_supportSharedLifetimeExceptionInfo2 = 0x10084220;
// R6GameService.dll data @ 10084260
constexpr unsigned int clPointerListSharedLifetimeUnwindMap = 0x10084260;
// R6GameService.dll data @ 10084268
constexpr unsigned int clPointerListSharedLifetimeExceptionInfo = 0x10084268;
// R6GameService.dll data @ 100842a8
constexpr unsigned int clSRPGSConnectConstructUnwindMap = 0x100842a8;
// R6GameService.dll data @ 100842b0
constexpr unsigned int clSRPGSConnectConstructExceptionInfo = 0x100842b0;
// R6GameService.dll data @ 100842cc
constexpr unsigned int clSRPGSConnectDestroyUnwindMap = 0x100842cc;
// R6GameService.dll data @ 100842d4
constexpr unsigned int clSRPGSConnectDestroyExceptionInfo = 0x100842d4;
// R6GameService.dll data @ 100842f0
constexpr unsigned int DecodeProviderReceiveFramesUnwindMap = 0x100842f0;
// R6GameService.dll data @ 10084300
constexpr unsigned int DecodeProviderReceiveFramesExceptionInfo = 0x10084300;
// R6GameService.dll data @ 1008431c
constexpr unsigned int clSRPGSClientConstructUnwindMap = 0x1008431c;
// R6GameService.dll data @ 10084324
constexpr unsigned int clSRPGSClientConstructExceptionInfo = 0x10084324;
// R6GameService.dll data @ 10084340
constexpr unsigned int ConstructClGSMessageUnwindMap = 0x10084340;
// R6GameService.dll data @ 10084358
constexpr unsigned int ConstructClGSMessageExceptionInfo = 0x10084358;
// R6GameService.dll data @ 10084374
constexpr unsigned int DestroyClGSMessageUnwindMap = 0x10084374;
// R6GameService.dll data @ 1008437c
constexpr unsigned int DestroyClGSMessageExceptionInfo = 0x1008437c;
// R6GameService.dll data @ 10084398
constexpr unsigned int SerializePayloadRecordUnwindMap = 0x10084398;
// R6GameService.dll data @ 100843c8
constexpr unsigned int SerializePayloadRecordExceptionInfo = 0x100843c8;
// R6GameService.dll data @ 100843e4
constexpr unsigned int DecodePayloadRecordUnwindMap = 0x100843e4;
// R6GameService.dll data @ 10084434
constexpr unsigned int DecodePayloadRecordExceptionInfo = 0x10084434;
// R6GameService.dll data @ 10084450
constexpr unsigned int PrintDecodedRecordUnwindMap = 0x10084450;
// R6GameService.dll data @ 100844b0
constexpr unsigned int PrintDecodedRecordExceptionInfo = 0x100844b0;
// R6GameService.dll data @ 100844cc
constexpr unsigned int ConstructSharedCryptoContextUnwindMap = 0x100844cc;
// R6GameService.dll data @ 100844d4
constexpr unsigned int ConstructSharedCryptoContextExceptionInfo = 0x100844d4;
// R6GameService.dll data @ 100844f0
constexpr unsigned int InitializeLargeRecordOwnerStateUnwindMap = 0x100844f0;
// R6GameService.dll data @ 10084568
constexpr unsigned int InitializeLargeRecordOwnerStateExceptionInfo = 0x10084568;
// R6GameService.dll data @ 10084584
constexpr unsigned int ReleaseSegmentedWordStorageUnwindMap = 0x10084584;
// R6GameService.dll data @ 1008458c
constexpr unsigned int ReleaseSegmentedWordStorageExceptionInfo = 0x1008458c;
// R6GameService.dll data @ 100845a8
constexpr unsigned int DestroyLargeRecordOwnerUnwindMap = 0x100845a8;
// R6GameService.dll data @ 100845d8
constexpr unsigned int DestroyLargeRecordOwnerExceptionInfo = 0x100845d8;
// R6GameService.dll data @ 100845f4
constexpr unsigned int SendOwnerWordReportsUnwindMap = 0x100845f4;
// R6GameService.dll data @ 100845fc
constexpr unsigned int SendOwnerWordReportsExceptionInfo = 0x100845fc;
// R6GameService.dll data @ 10084618
constexpr unsigned int owned_record_array_supportSharedLifetimeUnwindMap2 = 0x10084618;
// R6GameService.dll data @ 10084620
constexpr unsigned int owned_record_array_supportSharedLifetimeExceptionInfo2 = 0x10084620;
// R6GameService.dll data @ 10084660
constexpr unsigned int InitializeSegmentedWordsUnwindMap = 0x10084660;
// R6GameService.dll data @ 10084670
constexpr unsigned int InitializeSegmentedWordsExceptionInfo = 0x10084670;
// R6GameService.dll data @ 100846b0
constexpr unsigned int ResizeOwnedRecordArrayUnwindMap = 0x100846b0;
// R6GameService.dll data @ 100846c0
constexpr unsigned int ResizeOwnedRecordArrayExceptionInfo = 0x100846c0;
// R6GameService.dll data @ 100846dc
constexpr unsigned int owned_record_array_supportSharedLifetimeUnwindMap = 0x100846dc;
// R6GameService.dll data @ 100846e4
constexpr unsigned int owned_record_array_supportSharedLifetimeExceptionInfo = 0x100846e4;
// R6GameService.dll data @ 10084724
constexpr unsigned int InitializeSegmentedWordBufferUnwindMap = 0x10084724;
// R6GameService.dll data @ 10084734
constexpr unsigned int segmented_word_supportGSegmentedWordEH5 = 0x10084734;
// R6GameService.dll data @ 10084744
constexpr unsigned int InitializeSegmentedWordBufferTryMap = 0x10084744;
// R6GameService.dll data @ 10084758
constexpr unsigned int InitializeSegmentedWordBufferExceptionInfo = 0x10084758;
// R6GameService.dll data @ 10084774
constexpr unsigned int ReallocateAndInsertOwnedRecordsUnwindMap = 0x10084774;
// R6GameService.dll data @ 10084784
constexpr unsigned int owned_record_array_supportGOwnedRecordGrowthEH = 0x10084784;
// R6GameService.dll data @ 10084794
constexpr unsigned int ReallocateAndInsertOwnedRecordsTryMap = 0x10084794;
// R6GameService.dll data @ 100847a8
constexpr unsigned int ReallocateAndInsertOwnedRecordsExceptionInfo = 0x100847a8;
// R6GameService.dll data @ 100847c4
constexpr unsigned int DestroyRecordOwnerStorageUnwindMap = 0x100847c4;
// R6GameService.dll data @ 100847dc
constexpr unsigned int DestroyRecordOwnerStorageExceptionInfo = 0x100847dc;
// R6GameService.dll data @ 100847f8
constexpr unsigned int FindOrCreateKeyedRecordUnwindMap = 0x100847f8;
// R6GameService.dll data @ 10084810
constexpr unsigned int FindOrCreateKeyedRecordExceptionInfo = 0x10084810;
// R6GameService.dll data @ 1008482c
constexpr unsigned int InitializeKeyedRecordUnwindMap = 0x1008482c;
// R6GameService.dll data @ 1008486c
constexpr unsigned int InitializeKeyedRecordExceptionInfo = 0x1008486c;
// R6GameService.dll data @ 10084888
constexpr unsigned int DestroyKeyedRecordStorageUnwindMap = 0x10084888;
// R6GameService.dll data @ 100848c0
constexpr unsigned int DestroyKeyedRecordStorageExceptionInfo = 0x100848c0;
// R6GameService.dll data @ 100848dc
constexpr unsigned int ReleaseSegmentedDwordBufferBlocksUnwindMap = 0x100848dc;
// R6GameService.dll data @ 100848e4
constexpr unsigned int ReleaseSegmentedDwordBufferBlocksExceptionInfo = 0x100848e4;
// R6GameService.dll data @ 10084900
constexpr unsigned int DestroyClSegmentPointerDequeUnwindMap = 0x10084900;
// R6GameService.dll data @ 10084910
constexpr unsigned int DestroyClSegmentPointerDequeExceptionInfo = 0x10084910;
// R6GameService.dll data @ 10084950
constexpr unsigned int InitializeKeyedRecordIndexUnwindMap = 0x10084950;
// R6GameService.dll data @ 10084968
constexpr unsigned int InitializeKeyedRecordIndexExceptionInfo = 0x10084968;
// R6GameService.dll data @ 10084984
constexpr unsigned int InitializeSegmentedDwordBufferUnwindMap = 0x10084984;
// R6GameService.dll data @ 10084994
constexpr unsigned int InitializeSegmentedDwordBufferExceptionInfo = 0x10084994;
// R6GameService.dll data @ 100849b0
constexpr unsigned int Rehash16BitKeyTableUnwindMap = 0x100849b0;
// R6GameService.dll data @ 100849d0
constexpr unsigned int Rehash16BitKeyTableExceptionInfo = 0x100849d0;
// R6GameService.dll data @ 100849ec
constexpr unsigned int InitializeSegmentedDwordBufferStorageUnwindMap = 0x100849ec;
// R6GameService.dll data @ 100849fc
constexpr unsigned int segmented_pointer_supportGAssociationConstructionEH4 = 0x100849fc;
// R6GameService.dll data @ 10084a0c
constexpr unsigned int InitializeSegmentedDwordBufferStorageTryMap = 0x10084a0c;
// R6GameService.dll data @ 10084a20
constexpr unsigned int InitializeSegmentedDwordBufferStorageExceptionInfo = 0x10084a20;
// R6GameService.dll data @ 10084a78
constexpr unsigned int InitializeDerivedTransportRecordWithTextUnwindMap = 0x10084a78;
// R6GameService.dll data @ 10084ab8
constexpr unsigned int InitializeDerivedTransportRecordWithTextExceptionInfo = 0x10084ab8;
// R6GameService.dll data @ 10084ad4
constexpr unsigned int DestroyDerivedTransportRecordWithTextUnwindMap = 0x10084ad4;
// R6GameService.dll data @ 10084af4
constexpr unsigned int DestroyDerivedTransportRecordWithTextExceptionInfo = 0x10084af4;
// R6GameService.dll data @ 10084b10
constexpr unsigned int ConnectAndSendProxyRequestUnwindMap = 0x10084b10;
// R6GameService.dll data @ 10084b40
constexpr unsigned int ConnectAndSendProxyRequestExceptionInfo = 0x10084b40;
// R6GameService.dll data @ 10084b5c
constexpr unsigned int DestroyCallbackListContainerUnwindMap = 0x10084b5c;
// R6GameService.dll data @ 10084b64
constexpr unsigned int DestroyCallbackListContainerExceptionInfo = 0x10084b64;
// R6GameService.dll data @ 10084b80
constexpr unsigned int DestroyPerNodeLinkedListContainerUnwindMap = 0x10084b80;
// R6GameService.dll data @ 10084b90
constexpr unsigned int DestroyPerNodeLinkedListContainerExceptionInfo = 0x10084b90;
// R6GameService.dll data @ 10084bac
constexpr unsigned int WriteServiceLogMessageUnwindMap = 0x10084bac;
// R6GameService.dll data @ 10084bb4
constexpr unsigned int WriteServiceLogMessageExceptionInfo = 0x10084bb4;
// R6GameService.dll data @ 1008c160
constexpr unsigned int GAnsiCodePageDispatch = 0x1008c160;
// R6GameService.dll type-descriptor @ 1008c164
constexpr unsigned int PAXTypeDescriptor = 0x1008c164;
// R6GameService.dll type-descriptor @ 1008c174
constexpr unsigned int UnsignedShortPointerTypeDescriptor = 0x1008c174;
// R6GameService.dll type-descriptor @ 1008c184
constexpr unsigned int exceptionTypeDescriptor = 0x1008c184;
// R6GameService.dll type-descriptor @ 1008c19c
constexpr unsigned int bad_castTypeDescriptor = 0x1008c19c;
// R6GameService.dll type-descriptor @ 1008c270
constexpr unsigned int CAtlExceptionATLTypeDescriptor = 0x1008c270;
// R6GameService.dll text @ 1008c444
constexpr unsigned int TextCONTENTLENGTH = 0x1008c444;
// R6GameService.dll text @ 1008c458
constexpr unsigned int TextHTTP11 = 0x1008c458;
// R6GameService.dll text @ 1008c468
constexpr unsigned int TextGETSHTTP11HostSUserAgentUbiComConnectionClose = 0x1008c468;
// R6GameService.dll text @ 1008c4b0
constexpr unsigned int TextGETSHTTP11HostSUserAgentUbiComConnectionCloseS = 0x1008c4b0;
// R6GameService.dll text @ 1008c4fc
constexpr unsigned int TextAb = 0x1008c4fc;
// R6GameService.dll wide-text @ 1008c500
constexpr unsigned int WideTextW = 0x1008c500;
// R6GameService.dll text @ 1008c520
constexpr unsigned int TextLibgshttpErrorReadingHeadersFailure = 0x1008c520;
// R6GameService.dll text @ 1008c54c
constexpr unsigned int TextLibgshttpErrorSendingRequestFailed = 0x1008c54c;
// R6GameService.dll text @ 1008c578
constexpr unsigned int TextLibgshttpErrorConnectFailed = 0x1008c578;
// R6GameService.dll text @ 1008c59c
constexpr unsigned int TextHTTP = 0x1008c59c;
// R6GameService.dll data @ 1008c62c
constexpr unsigned int s_basic_string = 0x1008c62c;
// R6GameService.dll data @ 1008c63c
constexpr unsigned int GPooledByteStringBucketCount = 0x1008c63c;
// R6GameService.dll text @ 1008c640
constexpr unsigned int TextMsgGetCopy = 0x1008c640;
// R6GameService.dll text @ 1008c64c
constexpr unsigned int TextMsgDelete = 0x1008c64c;
// R6GameService.dll text @ 1008c658
constexpr unsigned int TextMsgAlloc = 0x1008c658;
// R6GameService.dll text @ 1008c664
constexpr unsigned int TextGetMessageQueueNotEmptyEvent = 0x1008c664;
// R6GameService.dll text @ 1008c684
constexpr unsigned int TextPostMessage = 0x1008c684;
// R6GameService.dll text @ 1008c694
constexpr unsigned int TextDispatchMessage = 0x1008c694;
// R6GameService.dll text @ 1008c6a8
constexpr unsigned int TextGetMessage = 0x1008c6a8;
// R6GameService.dll text @ 1008c6b4
constexpr unsigned int TextDisconnect = 0x1008c6b4;
// R6GameService.dll text @ 1008c6c0
constexpr unsigned int TextConnect = 0x1008c6c0;
// R6GameService.dll text @ 1008c6cc
constexpr unsigned int TextUninitialize = 0x1008c6cc;
// R6GameService.dll text @ 1008c6dc
constexpr unsigned int TextInitialize = 0x1008c6dc;
// R6GameService.dll text @ 1008c6e8
constexpr unsigned int TextGSClientSP = 0x1008c6e8;
// R6GameService.dll text @ 1008c6f4
constexpr unsigned int TextSOFTWAREUbiSoftGameService = 0x1008c6f4;
// R6GameService.dll text @ 1008c744
constexpr unsigned int Text114 = 0x1008c744;
// R6GameService.dll text @ 1008c74c
constexpr unsigned int TextNeedDictionary = 0x1008c74c;
// R6GameService.dll text @ 1008c75c
constexpr unsigned int TextIncorrectDataCheck = 0x1008c75c;
// R6GameService.dll text @ 1008c774
constexpr unsigned int TextIncorrectHeaderCheck = 0x1008c774;
// R6GameService.dll text @ 1008c78c
constexpr unsigned int TextInvalidWindowSize = 0x1008c78c;
// R6GameService.dll text @ 1008c7a0
constexpr unsigned int TextUnknownCompressionMethod = 0x1008c7a0;
// R6GameService.dll text @ 1008c7c0
constexpr unsigned int TextInvalidBitLengthRepeat = 0x1008c7c0;
// R6GameService.dll text @ 1008c7dc
constexpr unsigned int TextTooManyLengthOrDistanceSymbols = 0x1008c7dc;
// R6GameService.dll text @ 1008c800
constexpr unsigned int TextInvalidStoredBlockLengths = 0x1008c800;
// R6GameService.dll text @ 1008c820
constexpr unsigned int TextInvalidBlockType = 0x1008c820;
// R6GameService.dll data @ 1008c8cc
constexpr unsigned int DeflateLiteralTreeDescriptor = 0x1008c8cc;
// R6GameService.dll data @ 1008c8e0
constexpr unsigned int DeflateDistanceTreeDescriptor = 0x1008c8e0;
// R6GameService.dll data @ 1008c8f4
constexpr unsigned int DeflateBitLengthTreeDescriptor = 0x1008c8f4;
// R6GameService.dll text @ 1008c908
constexpr unsigned int TextInvalidLiteralLengthCode = 0x1008c908;
// R6GameService.dll text @ 1008c924
constexpr unsigned int TextInvalidDistanceCode = 0x1008c924;
// R6GameService.dll data @ 1008c940
constexpr unsigned int FixedRootWidths = 0x1008c940;
// R6GameService.dll data @ 1008c948
constexpr unsigned int FixedLiteralLookup = 0x1008c948;
// R6GameService.dll data @ 1008d948
constexpr unsigned int FixedDistanceLookup = 0x1008d948;
// R6GameService.dll text @ 1008da48
constexpr unsigned int TextIncompleteDynamicBitLengthsTree = 0x1008da48;
// R6GameService.dll text @ 1008da6c
constexpr unsigned int TextOversubscribedDynamicBitLengthsTree = 0x1008da6c;
// R6GameService.dll text @ 1008da94
constexpr unsigned int TextIncompleteLiteralLengthTree = 0x1008da94;
// R6GameService.dll text @ 1008dab4
constexpr unsigned int TextOversubscribedLiteralLengthTree = 0x1008dab4;
// R6GameService.dll text @ 1008dad8
constexpr unsigned int TextEmptyDistanceTreeWithLengths = 0x1008dad8;
// R6GameService.dll text @ 1008dafc
constexpr unsigned int TextIncompleteDistanceTree = 0x1008dafc;
// R6GameService.dll text @ 1008db18
constexpr unsigned int TextOversubscribedDistanceTree = 0x1008db18;
// R6GameService.dll data @ 1008db38
constexpr unsigned int InflateLowBitMasks = 0x1008db38;
// R6GameService.dll text @ 1008dfd8
constexpr unsigned int TextCloseBracketLine = 0x1008dfd8;
// R6GameService.dll text @ 1008dfdc
constexpr unsigned int TextOpenBracketLine = 0x1008dfdc;
// R6GameService.dll wide-text @ 1008dfe0
constexpr unsigned int WideTextCloseBracket = 0x1008dfe0;
// R6GameService.dll wide-text @ 1008dfe4
constexpr unsigned int WideTextOpenBracket = 0x1008dfe4;
// R6GameService.dll text @ 1008dfe8
constexpr unsigned int TextSignedDecimalFormat = 0x1008dfe8;
// R6GameService.dll text @ 1008dfec
constexpr unsigned int TextS2 = 0x1008dfec;
// R6GameService.dll text @ 1008dff4
constexpr unsigned int TextPunctuation = 0x1008dff4;
// R6GameService.dll text @ 1008dff8
constexpr unsigned int TextLD = 0x1008dff8;
// R6GameService.dll wide-text @ 1008e000
constexpr unsigned int WideTextSpace2 = 0x1008e000;
// R6GameService.dll text @ 1008e004
constexpr unsigned int TextL = 0x1008e004;
// R6GameService.dll text @ 1008e008
constexpr unsigned int TextPunctuation2 = 0x1008e008;
// R6GameService.dll text @ 1008e00c
constexpr unsigned int TextString = 0x1008e00c;
// R6GameService.dll text @ 1008e018
constexpr unsigned int TextStringRef = 0x1008e018;
// R6GameService.dll text @ 1008e028
constexpr unsigned int BinaryValueTextPrefix = 0x1008e028;
// R6GameService.dll text @ 1008e02c
constexpr unsigned int BinarySummaryTextSuffix = 0x1008e02c;
// R6GameService.dll text @ 1008e034
constexpr unsigned int UnsignedByteCountFormat = 0x1008e034;
// R6GameService.dll text @ 1008e038
constexpr unsigned int BinarySummaryTextPrefix = 0x1008e038;
// R6GameService.dll text @ 1008e040
constexpr unsigned int TextBD = 0x1008e040;
// R6GameService.dll text @ 1008e048
constexpr unsigned int TextD = 0x1008e048;
// R6GameService.dll text @ 1008e054
constexpr unsigned int TextLong = 0x1008e054;
// R6GameService.dll data @ 1008e07c
constexpr unsigned int GPerformanceCounterNeedsBaseline = 0x1008e07c;
// R6GameService.dll data @ 1008e080
constexpr unsigned int GSocketConnectTimeoutSeconds = 0x1008e080;
// R6GameService.dll text @ 1008e084
constexpr unsigned int Text224000 = 0x1008e084;
// R6GameService.dll text @ 1008e090
constexpr unsigned int Text204152640 = 0x1008e090;
// R6GameService.dll text @ 1008e0a0
constexpr unsigned int Text201000 = 0x1008e0a0;
// R6GameService.dll text @ 1008e0ac
constexpr unsigned int Text197000 = 0x1008e0ac;
// R6GameService.dll text @ 1008e0b8
constexpr unsigned int Text19216800 = 0x1008e0b8;
// R6GameService.dll text @ 1008e0c4
constexpr unsigned int Text19201280 = 0x1008e0c4;
// R6GameService.dll text @ 1008e0d0
constexpr unsigned int Text1920640 = 0x1008e0d0;
// R6GameService.dll text @ 1008e0dc
constexpr unsigned int Text1920480 = 0x1008e0dc;
// R6GameService.dll text @ 1008e0e8
constexpr unsigned int Text192000 = 0x1008e0e8;
// R6GameService.dll text @ 1008e0f4
constexpr unsigned int Text19125500 = 0x1008e0f4;
// R6GameService.dll text @ 1008e100
constexpr unsigned int Text1721600 = 0x1008e100;
// R6GameService.dll text @ 1008e10c
constexpr unsigned int Text16925400 = 0x1008e10c;
// R6GameService.dll text @ 1008e118
constexpr unsigned int Text1286600 = 0x1008e118;
// R6GameService.dll text @ 1008e124
constexpr unsigned int Text128000 = 0x1008e124;
// R6GameService.dll text @ 1008e130
constexpr unsigned int Text127000 = 0x1008e130;
// R6GameService.dll text @ 1008e13c
constexpr unsigned int Text96000 = 0x1008e13c;
// R6GameService.dll text @ 1008e148
constexpr unsigned int Text88000 = 0x1008e148;
// R6GameService.dll text @ 1008e154
constexpr unsigned int Text84000 = 0x1008e154;
// R6GameService.dll text @ 1008e160
constexpr unsigned int Text82000 = 0x1008e160;
// R6GameService.dll text @ 1008e16c
constexpr unsigned int Text72000 = 0x1008e16c;
// R6GameService.dll text @ 1008e178
constexpr unsigned int Text70000 = 0x1008e178;
// R6GameService.dll text @ 1008e184
constexpr unsigned int Text69000 = 0x1008e184;
// R6GameService.dll text @ 1008e190
constexpr unsigned int Text31000 = 0x1008e190;
// R6GameService.dll text @ 1008e19c
constexpr unsigned int Text27000 = 0x1008e19c;
// R6GameService.dll text @ 1008e1a8
constexpr unsigned int Text23000 = 0x1008e1a8;
// R6GameService.dll text @ 1008e1b4
constexpr unsigned int Text10000 = 0x1008e1b4;
// R6GameService.dll text @ 1008e1c0
constexpr unsigned int Text5000 = 0x1008e1c0;
// R6GameService.dll text @ 1008e1c8
constexpr unsigned int Text2000 = 0x1008e1c8;
// R6GameService.dll text @ 1008e1d0
constexpr unsigned int Text0000 = 0x1008e1d0;
// R6GameService.dll text @ 1008e1d8
constexpr unsigned int TextDDDD = 0x1008e1d8;
// R6GameService.dll text @ 1008e1e4
constexpr unsigned int TextTimeoutDD = 0x1008e1e4;
// R6GameService.dll text @ 1008e1f8
constexpr unsigned int TextUdpBindError = 0x1008e1f8;
// R6GameService.dll text @ 1008e38c
constexpr unsigned int TextRandomParentGroupDD = 0x1008e38c;
// R6GameService.dll text @ 1008e5f0
constexpr unsigned int TextJoinWaitModuleFailed = 0x1008e5f0;
// R6GameService.dll text @ 1008e608
constexpr unsigned int TextLoginToWaitmodule = 0x1008e608;
// R6GameService.dll text @ 1008e620
constexpr unsigned int TextConnectingToWaitmodule = 0x1008e620;
// R6GameService.dll text @ 1008e63c
constexpr unsigned int TextLoginRouterFailed = 0x1008e63c;
// R6GameService.dll text @ 1008e654
constexpr unsigned int TextLoginRouterSucceeded = 0x1008e654;
// R6GameService.dll text @ 1008e66c
constexpr unsigned int TextLoginWaitModuleFailed = 0x1008e66c;
// R6GameService.dll text @ 1008e688
constexpr unsigned int TextLoginToWaitmoduleSuccessful = 0x1008e688;
// R6GameService.dll text @ 1008e6a8
constexpr unsigned int TextJoinLobbyII = 0x1008e6a8;
// R6GameService.dll text @ 1008e6bc
constexpr unsigned int TextGSFAILI = 0x1008e6bc;
// R6GameService.dll text @ 1008e6c8
constexpr unsigned int TextJoinRoomII = 0x1008e6c8;
// R6GameService.dll text @ 1008e6d8
constexpr unsigned int TextNewRoomS = 0x1008e6d8;
// R6GameService.dll text @ 1008e6e4
constexpr unsigned int TextNewLobbySS = 0x1008e6e4;
// R6GameService.dll text @ 1008e6f4
constexpr unsigned int TextRoomInfoSS = 0x1008e6f4;
// R6GameService.dll text @ 1008e704
constexpr unsigned int TextLobbyInfoSS = 0x1008e704;
// R6GameService.dll data @ 1008e798
constexpr unsigned int GWindowsVersionHighBitCache = 0x1008e798;
// R6GameService.dll data @ 1008ec20
constexpr unsigned int GBlowfishInitialP = 0x1008ec20;
// R6GameService.dll data @ 1008ec68
constexpr unsigned int GBlowfishInitialS = 0x1008ec68;
// R6GameService.dll data @ 1008fcbc
constexpr unsigned int GHashModuleHexFormat = 0x1008fcbc;
// R6GameService.dll data @ 1008fd80
constexpr unsigned int GMD5Padding = 0x1008fd80;
// R6GameService.dll data @ 1008fdd4
constexpr unsigned int GRSASmallPrimeDivisors = 0x1008fdd4;
// R6GameService.dll text @ 10090058
constexpr unsigned int TextPunctuation3 = 0x10090058;
// R6GameService.dll text @ 10090380
constexpr unsigned int TextWrongUDPMessageProperty = 0x10090380;
// R6GameService.dll text @ 10090718
constexpr unsigned int TextSendUDPConnectIDD = 0x10090718;
// R6GameService.dll text @ 10090730
constexpr unsigned int TextReadUDPConnectIDD = 0x10090730;
// R6GameService.dll text @ 10090748
constexpr unsigned int TextSendEVENTUDPCONNECT = 0x10090748;
// R6GameService.dll text @ 10090760
constexpr unsigned int TextErrorCouldNotReadTheFifo = 0x10090760;
// R6GameService.dll text @ 10090784
constexpr unsigned int TextTheMessageFormatIsNotCorrect = 0x10090784;
// R6GameService.dll text @ 100907a8
constexpr unsigned int TextErrorDecodingMessage = 0x100907a8;
// R6GameService.dll text @ 100907c0
constexpr unsigned int TextReadEncryptedMessage = 0x100907c0;
// R6GameService.dll text @ 100907d8
constexpr unsigned int TextSendingEncryptedMessage = 0x100907d8;
// R6GameService.dll text @ 10090888
constexpr unsigned int TextOnALSizeGSHEADERSIZE = 0x10090888;
// R6GameService.dll text @ 100908a4
constexpr unsigned int TextOnALSizeMAXMESSAGESIZE = 0x100908a4;
// R6GameService.dll text @ 100908f4
constexpr unsigned int TextLOBBYSERVERLOGIN = 0x100908f4;
// R6GameService.dll text @ 10090908
constexpr unsigned int TextLOBBYMSG = 0x10090908;
// R6GameService.dll text @ 10090914
constexpr unsigned int TextPLAYERCLANS = 0x10090914;
// R6GameService.dll text @ 10090920
constexpr unsigned int TextUPDATECLANPLAYER = 0x10090920;
// R6GameService.dll text @ 10090934
constexpr unsigned int TextCLANMANAGERPAGE = 0x10090934;
// R6GameService.dll text @ 10090944
constexpr unsigned int TextDISCONNECTCLANMANAGER = 0x10090944;
// R6GameService.dll text @ 1009095c
constexpr unsigned int TextLOGINCLANMANAGER = 0x1009095c;
// R6GameService.dll text @ 10090970
constexpr unsigned int TextSETGROUPSZDATA = 0x10090970;
// R6GameService.dll text @ 10090980
constexpr unsigned int TextGROUPSZDATA = 0x10090980;
// R6GameService.dll text @ 1009098c
constexpr unsigned int TextGETPERSISTANTGROUPINFO = 0x1009098c;
// R6GameService.dll text @ 100909a4
constexpr unsigned int TextADMINLOGIN = 0x100909a4;
// R6GameService.dll text @ 100909b0
constexpr unsigned int TextUPDATEGROUPPING = 0x100909b0;
// R6GameService.dll text @ 100909c0
constexpr unsigned int TextUPDATEGROUPSIZE = 0x100909c0;
// R6GameService.dll text @ 100909d0
constexpr unsigned int TextSESSIONCLOSE = 0x100909d0;
// R6GameService.dll text @ 100909e0
constexpr unsigned int TextSESSIONOPEN = 0x100909e0;
// R6GameService.dll text @ 100909ec
constexpr unsigned int TextSYSTEMPAGE = 0x100909ec;
// R6GameService.dll text @ 100909f8
constexpr unsigned int TextWAKEUP = 0x100909f8;
// R6GameService.dll text @ 10090a00
constexpr unsigned int TextSLEEP = 0x10090a00;
// R6GameService.dll text @ 10090a08
constexpr unsigned int TextBASEGROUPREQUEST = 0x10090a08;
// R6GameService.dll text @ 10090a1c
constexpr unsigned int TextARENALISTREQUEST = 0x10090a1c;
// R6GameService.dll text @ 10090a30
constexpr unsigned int TextUPDATEPLAYERPING = 0x10090a30;
// R6GameService.dll text @ 10090a44
constexpr unsigned int TextARENAMESSAGE = 0x10090a44;
// R6GameService.dll text @ 10090a54
constexpr unsigned int TextROUTERPLAYERNEW = 0x10090a54;
// R6GameService.dll text @ 10090a64
constexpr unsigned int TextSESSIONSBEGIN = 0x10090a64;
// R6GameService.dll text @ 10090a74
constexpr unsigned int TextARENAWAITMODULE = 0x10090a74;
// R6GameService.dll text @ 10090a84
constexpr unsigned int TextARENADISCONNECTION = 0x10090a84;
// R6GameService.dll text @ 10090a98
constexpr unsigned int TextARENACONNECTION = 0x10090a98;
// R6GameService.dll text @ 10090aa8
constexpr unsigned int TextDELETEIGNOREFRIEND = 0x10090aa8;
// R6GameService.dll text @ 10090abc
constexpr unsigned int TextNEWIGNOREFRIEND = 0x10090abc;
// R6GameService.dll text @ 10090acc
constexpr unsigned int TextDELRELFRIEND = 0x10090acc;
// R6GameService.dll text @ 10090adc
constexpr unsigned int TextNEWRELFRIEND = 0x10090adc;
// R6GameService.dll text @ 10090aec
constexpr unsigned int TextPLAYERDISCONNECT = 0x10090aec;
// R6GameService.dll text @ 10090b00
constexpr unsigned int TextWRAPPEDMESSAGE = 0x10090b00;
// R6GameService.dll text @ 10090b10
constexpr unsigned int TextDISTANCEVECTOR = 0x10090b10;
// R6GameService.dll text @ 10090b20
constexpr unsigned int TextDELETEBASICGROUP = 0x10090b20;
// R6GameService.dll text @ 10090b34
constexpr unsigned int TextARENAREMOVED = 0x10090b34;
// R6GameService.dll text @ 10090b44
constexpr unsigned int TextNEWBASICGROUP = 0x10090b44;
// R6GameService.dll text @ 10090b54
constexpr unsigned int TextARENANEW = 0x10090b54;
// R6GameService.dll text @ 10090b60
constexpr unsigned int TextCHANGEFRIEND = 0x10090b60;
// R6GameService.dll text @ 10090b70
constexpr unsigned int TextDISCONNECTSESSION = 0x10090b70;
// R6GameService.dll text @ 10090b84
constexpr unsigned int TextLOGINSESSION = 0x10090b84;
// R6GameService.dll text @ 10090b94
constexpr unsigned int TextJOINWAITMODULE = 0x10090b94;
// R6GameService.dll text @ 10090ba4
constexpr unsigned int TextDISCONNECTFRIENDS = 0x10090ba4;
// R6GameService.dll text @ 10090bb8
constexpr unsigned int TextPEERPLAYER = 0x10090bb8;
// R6GameService.dll text @ 10090bc4
constexpr unsigned int TextPEERMSG = 0x10090bc4;
// R6GameService.dll text @ 10090bcc
constexpr unsigned int TextFRIENDLIST = 0x10090bcc;
// R6GameService.dll text @ 10090bd8
constexpr unsigned int TextPAGEPLAYER = 0x10090bd8;
// R6GameService.dll text @ 10090be4
constexpr unsigned int TextGETSESSION = 0x10090be4;
// R6GameService.dll text @ 10090bf0
constexpr unsigned int TextGETARENA = 0x10090bf0;
// R6GameService.dll text @ 10090bfc
constexpr unsigned int TextIGNOREFRIEND = 0x10090bfc;
// R6GameService.dll text @ 10090c0c
constexpr unsigned int TextIGNORELIST = 0x10090c0c;
// R6GameService.dll text @ 10090c18
constexpr unsigned int TextLEAVEARENA = 0x10090c18;
// R6GameService.dll text @ 10090c24
constexpr unsigned int TextJOINARENA = 0x10090c24;
// R6GameService.dll text @ 10090c30
constexpr unsigned int TextSTATUSCHANGE = 0x10090c30;
// R6GameService.dll text @ 10090c40
constexpr unsigned int TextDELIGNOREFRIEND = 0x10090c40;
// R6GameService.dll text @ 10090c50
constexpr unsigned int TextADDIGNOREFRIEND = 0x10090c50;
// R6GameService.dll text @ 10090c60
constexpr unsigned int TextLOGINFRIENDS = 0x10090c60;
// R6GameService.dll text @ 10090c70
constexpr unsigned int TextLOGINWAITMODULE = 0x10090c70;
// R6GameService.dll text @ 10090c80
constexpr unsigned int TextDELFRIEND = 0x10090c80;
// R6GameService.dll text @ 10090c8c
constexpr unsigned int TextADDFRIEND = 0x10090c8c;
// R6GameService.dll text @ 10090c98
constexpr unsigned int TextUPDATEFRIEND = 0x10090c98;
// R6GameService.dll text @ 10090ca8
constexpr unsigned int TextURGENTMESSAGE = 0x10090ca8;
// R6GameService.dll text @ 10090cb8
constexpr unsigned int TextSTATGAME = 0x10090cb8;
// R6GameService.dll text @ 10090cc4
constexpr unsigned int TextSTATPLAYER = 0x10090cc4;
// R6GameService.dll text @ 10090cd0
constexpr unsigned int TextUPDATEVERSIONS = 0x10090cd0;
// R6GameService.dll text @ 10090ce0
constexpr unsigned int TextUPDATEDISTANTROUTERS = 0x10090ce0;
// R6GameService.dll text @ 10090cf8
constexpr unsigned int TextVERSIONLIST = 0x10090cf8;
// R6GameService.dll text @ 10090d04
constexpr unsigned int TextUPDATENEWS = 0x10090d04;
// R6GameService.dll text @ 10090d10
constexpr unsigned int TextUPDATEADVERTISMEMENTS = 0x10090d10;
// R6GameService.dll text @ 10090d28
constexpr unsigned int TextGAMELIST = 0x10090d28;
// R6GameService.dll text @ 10090d34
constexpr unsigned int TextFORBIDGAME = 0x10090d34;
// R6GameService.dll text @ 10090d40
constexpr unsigned int TextALLOWGAME = 0x10090d40;
// R6GameService.dll text @ 10090d4c
constexpr unsigned int TextPLAYERMUTE = 0x10090d4c;
// R6GameService.dll text @ 10090d58
constexpr unsigned int TextPLAYERKICK = 0x10090d58;
// R6GameService.dll text @ 10090d64
constexpr unsigned int TextSQLQUERY = 0x10090d64;
// R6GameService.dll text @ 10090d70
constexpr unsigned int TextSQLSTAT = 0x10090d70;
// R6GameService.dll text @ 10090d78
constexpr unsigned int TextSQLSET = 0x10090d78;
// R6GameService.dll text @ 10090d80
constexpr unsigned int TextSQLSELECT = 0x10090d80;
// R6GameService.dll text @ 10090d8c
constexpr unsigned int TextSQLDELETE = 0x10090d8c;
// R6GameService.dll text @ 10090d98
constexpr unsigned int TextSQLCREATE = 0x10090d98;
// R6GameService.dll text @ 10090da4
constexpr unsigned int TextDEFERREDGAMESTARTED = 0x10090da4;
// R6GameService.dll text @ 10090db8
constexpr unsigned int TextGROUPDATA = 0x10090db8;
// R6GameService.dll text @ 10090dc4
constexpr unsigned int TextUPDATESESSIONSTATE = 0x10090dc4;
// R6GameService.dll text @ 10090dd8
constexpr unsigned int TextMASTERCHANGED = 0x10090dd8;
// R6GameService.dll text @ 10090de8
constexpr unsigned int TextLOGINARENA = 0x10090de8;
// R6GameService.dll text @ 10090df4
constexpr unsigned int TextPHOTO = 0x10090df4;
// R6GameService.dll text @ 10090dfc
constexpr unsigned int TextLOGIN = 0x10090dfc;
// R6GameService.dll text @ 10090e04
constexpr unsigned int TextPAGER = 0x10090e04;
// R6GameService.dll text @ 10090e0c
constexpr unsigned int TextCHANGEVERSION = 0x10090e0c;
// R6GameService.dll text @ 10090e1c
constexpr unsigned int TextBEGINCLIENTHOSTGAME = 0x10090e1c;
// R6GameService.dll text @ 10090e30
constexpr unsigned int TextBEGINGAME = 0x10090e30;
// R6GameService.dll text @ 10090e3c
constexpr unsigned int TextSTARTGAME = 0x10090e3c;
// R6GameService.dll text @ 10090e48
constexpr unsigned int TextMODIFYUSER = 0x10090e48;
// R6GameService.dll text @ 10090e54
constexpr unsigned int TextADVERTISEMENT = 0x10090e54;
// R6GameService.dll text @ 10090e64
constexpr unsigned int TextGETPLAYERINFO = 0x10090e64;
// R6GameService.dll text @ 10090e74
constexpr unsigned int TextGROUPINFO = 0x10090e74;
// R6GameService.dll text @ 10090e80
constexpr unsigned int TextGETGROUPINFO = 0x10090e80;
// R6GameService.dll text @ 10090e90
constexpr unsigned int TextUPDATEPLAYERINFO = 0x10090e90;
// R6GameService.dll text @ 10090ea4
constexpr unsigned int TextPING = 0x10090ea4;
// R6GameService.dll text @ 10090eac
constexpr unsigned int TextSESSIONREMOVE = 0x10090eac;
// R6GameService.dll text @ 10090ebc
constexpr unsigned int TextJOINLEAVE = 0x10090ebc;
// R6GameService.dll text @ 10090ec8
constexpr unsigned int TextLEAVESESSION = 0x10090ec8;
// R6GameService.dll text @ 10090ed8
constexpr unsigned int TextJOINNEW = 0x10090ed8;
// R6GameService.dll text @ 10090ee0
constexpr unsigned int TextJOINSESSION = 0x10090ee0;
// R6GameService.dll text @ 10090eec
constexpr unsigned int TextSESSIONNEW = 0x10090eec;
// R6GameService.dll text @ 10090ef8
constexpr unsigned int TextCREATESESSION = 0x10090ef8;
// R6GameService.dll text @ 10090f08
constexpr unsigned int TextCHATLIST = 0x10090f08;
// R6GameService.dll text @ 10090f14
constexpr unsigned int TextCHATSESSION = 0x10090f14;
// R6GameService.dll text @ 10090f20
constexpr unsigned int TextCHATALL = 0x10090f20;
// R6GameService.dll text @ 10090f28
constexpr unsigned int TextCHAT = 0x10090f28;
// R6GameService.dll text @ 10090f30
constexpr unsigned int TextNEWWAITMODULE = 0x10090f30;
// R6GameService.dll text @ 10090f40
constexpr unsigned int TextPLAYERLIST = 0x10090f40;
// R6GameService.dll text @ 10090f4c
constexpr unsigned int TextSESSIONLIST = 0x10090f4c;
// R6GameService.dll text @ 10090f58
constexpr unsigned int TextPLAYERINFO = 0x10090f58;
// R6GameService.dll text @ 10090f64
constexpr unsigned int TextROUTEURLIST = 0x10090f64;
// R6GameService.dll text @ 10090f70
constexpr unsigned int TextSERVERSLIST = 0x10090f70;
// R6GameService.dll text @ 10090f7c
constexpr unsigned int TextREMOVEACCOUNT = 0x10090f7c;
// R6GameService.dll text @ 10090f8c
constexpr unsigned int TextSEARCHPLAYER = 0x10090f8c;
// R6GameService.dll text @ 10090f9c
constexpr unsigned int TextNEWS = 0x10090f9c;
// R6GameService.dll text @ 10090fa4
constexpr unsigned int TextPLAYERREMOVED = 0x10090fa4;
// R6GameService.dll text @ 10090fb4
constexpr unsigned int TextDISCONNECTION = 0x10090fb4;
// R6GameService.dll text @ 10090fc4
constexpr unsigned int TextPLAYERNEW = 0x10090fc4;
// R6GameService.dll text @ 10090fd0
constexpr unsigned int TextCONNECTIONREQUEST = 0x10090fd0;
// R6GameService.dll text @ 10090fe4
constexpr unsigned int TextNEWUSERREQUEST = 0x10090fe4;
// R6GameService.dll text @ 10090ff4
constexpr unsigned int TextGSFAIL = 0x10090ff4;
// R6GameService.dll text @ 10090ffc
constexpr unsigned int TextGSSUCCESS = 0x10090ffc;
// R6GameService.dll text @ 10091008
constexpr unsigned int TextKILLMODULE = 0x10091008;
// R6GameService.dll text @ 10091014
constexpr unsigned int TextSTILLALIVE = 0x10091014;
// R6GameService.dll wide-text @ 10091020
constexpr unsigned int WideTextPunctuation8 = 0x10091020;
// R6GameService.dll text @ 10091024
constexpr unsigned int TextPunctuation4 = 0x10091024;
// R6GameService.dll text @ 10091028
constexpr unsigned int TextS3 = 0x10091028;
// R6GameService.dll text @ 1009102c
constexpr unsigned int TextS4 = 0x1009102c;
// R6GameService.dll text @ 10091034
constexpr unsigned int TextS5 = 0x10091034;
// R6GameService.dll text @ 1009103c
constexpr unsigned int TextPunctuation5 = 0x1009103c;
// R6GameService.dll text @ 10091040
constexpr unsigned int TextPunctuation6 = 0x10091040;
// R6GameService.dll text @ 10091060
constexpr unsigned int TextSENDTOSERVER = 0x10091060;
// R6GameService.dll text @ 10091070
constexpr unsigned int TextSENDTOPLAYER = 0x10091070;
// R6GameService.dll text @ 10091080
constexpr unsigned int TextSENDTOPLAYERGROUP = 0x10091080;
// R6GameService.dll text @ 10091094
constexpr unsigned int TextSENDTOOTHERPLAYERS = 0x10091094;
// R6GameService.dll text @ 100910a8
constexpr unsigned int TextSENDTOALLPLAYERS = 0x100910a8;
// R6GameService.dll text @ 100910bc
constexpr unsigned int TextEVENTPLAYERINFOS = 0x100910bc;
// R6GameService.dll text @ 100910d0
constexpr unsigned int TextEVENTSERVERTIME = 0x100910d0;
// R6GameService.dll text @ 100910e4
constexpr unsigned int TextEVENTNEWMASTER = 0x100910e4;
// R6GameService.dll text @ 100910f4
constexpr unsigned int TextEVENTPLAYERLEFT = 0x100910f4;
// R6GameService.dll text @ 10091108
constexpr unsigned int TextEVENTNEWPLAYER = 0x10091108;
// R6GameService.dll text @ 10091118
constexpr unsigned int TextEVENTOWNID = 0x10091118;
// R6GameService.dll text @ 10091124
constexpr unsigned int TextEVENTREGISTER = 0x10091124;
// R6GameService.dll text @ 10091134
constexpr unsigned int TextD2 = 0x10091134;
// R6GameService.dll text @ 10091138
constexpr unsigned int TextMessage = 0x10091138;
// R6GameService.dll text @ 10091144
constexpr unsigned int TextSenderD = 0x10091144;
// R6GameService.dll text @ 10091150
constexpr unsigned int TextS6 = 0x10091150;
// R6GameService.dll text @ 10091158
constexpr unsigned int TextS7 = 0x10091158;
// R6GameService.dll wide-text @ 1009115c
constexpr unsigned int WideTextPunctuation9 = 0x1009115c;
// R6GameService.dll text @ 10091160
constexpr unsigned int TextSender = 0x10091160;
// R6GameService.dll text @ 1009116c
constexpr unsigned int TextPunctuation7 = 0x1009116c;
// R6GameService.dll wide-text @ 10091174
constexpr unsigned int WideTextPunctuation10 = 0x10091174;
// R6GameService.dll text @ 1009119c
constexpr unsigned int TextLld = 0x1009119c;
// R6GameService.dll text @ 100911a4
constexpr unsigned int TextGlobalInitialization = 0x100911a4;
// R6GameService.dll text @ 100911bc
constexpr unsigned int TextGlobalUninitialization = 0x100911bc;
// R6GameService.dll text @ 10091214
constexpr unsigned int TextDeleteSRProtocol = 0x10091214;
// R6GameService.dll data @ 10091368
constexpr unsigned int GSecurityCookie = 0x10091368;
// R6GameService.dll text @ 100914b4
constexpr unsigned int TextPROXY = 0x100914b4;
// R6GameService.dll text @ 100914bc
constexpr unsigned int TextConnectionToProxySDFailed = 0x100914bc;
// R6GameService.dll text @ 100914e0
constexpr unsigned int TextDisconnecting = 0x100914e0;
// R6GameService.dll text @ 100914f0
constexpr unsigned int TextTextFormat = 0x100914f0;
// R6GameService.dll text @ 100914f4
constexpr unsigned int TextPunctuation8 = 0x100914f4;
// R6GameService.dll text @ 100914f8
constexpr unsigned int Text2d2d2d2d2d2d = 0x100914f8;
// R6GameService.dll wide-text @ 1009151c
constexpr unsigned int WideTextA3 = 0x1009151c;
// R6GameService.dll text @ 10091520
constexpr unsigned int TextSI2 = 0x10091520;
// R6GameService.dll data @ 1009152c
constexpr unsigned int GUnsignedShortCtypeFallback = 0x1009152c;
// R6GameService.dll data @ 10091530
constexpr unsigned int GPatchServiceState = 0x10091530;
// R6GameService.dll data @ 10091534
constexpr unsigned int GPatchServiceExitCause = 0x10091534;
// R6GameService.dll data @ 10091538
constexpr unsigned int GPatchServiceSlot = 0x10091538;
// R6GameService.dll data @ 10091594
constexpr unsigned int GWideLogStream = 0x10091594;
// R6GameService.dll data @ 10091bdc
constexpr unsigned int GModuleHandle = 0x10091bdc;
// R6GameService.dll data @ 10091be4
constexpr unsigned int GJoinInProgress = 0x10091be4;
// R6GameService.dll data @ 10091bec
constexpr unsigned int GJoinGroupId = 0x10091bec;
// R6GameService.dll data @ 10091c00
constexpr unsigned int GLoggedInUbiDotCom = 0x10091c00;
// R6GameService.dll data @ 10091c1c
constexpr unsigned int GJoinLobbyId = 0x10091c1c;
// R6GameService.dll data @ 10091d28
constexpr unsigned int GMSRouterIndex = 0x10091d28;
// R6GameService.dll scalar @ 10091d40
constexpr unsigned int NativeFloat0_0 = 0x10091d40;
// R6GameService.dll data @ 10091e48
constexpr unsigned int GLoginRequested = 0x10091e48;
// R6GameService.dll data @ 10091e54
constexpr unsigned int GPublicSerializedStore = 0x10091e54;
// R6GameService.dll data @ 10091e58
constexpr unsigned int GPrivateSerializedStore = 0x10091e58;
// R6GameService.dll data @ 10091e5c
constexpr unsigned int GServerReplySerializedStore = 0x10091e5c;
// R6GameService.dll data @ 10091e60
constexpr unsigned int GMSClientInitialized = 0x10091e60;
// R6GameService.dll data @ 10091e70
constexpr unsigned int GServiceVerboseLogging = 0x10091e70;
// R6GameService.dll data @ 10091e74
constexpr unsigned int GCreateLobbyRequested = 0x10091e74;
// R6GameService.dll data @ 10091e78
// Live last-request tick in the asynchronous ICMP wrapper; role inferred from reads/writes.
constexpr unsigned int GLastIcmpRequestTick = 0x10091e78;
// R6GameService.dll data @ 1009239c
constexpr unsigned int GServiceArray1 = 0x1009239c;
// R6GameService.dll data @ 100923ac
constexpr unsigned int GServiceString1 = 0x100923ac;
// R6GameService.dll data @ 100923bc
constexpr unsigned int GServiceBstr = 0x100923bc;
// R6GameService.dll data @ 100923c4
constexpr unsigned int GServiceArray2 = 0x100923c4;
// R6GameService.dll data @ 100923e8
constexpr unsigned int GServiceArray3 = 0x100923e8;
// R6GameService.dll data @ 1009291c
constexpr unsigned int GServiceString2 = 0x1009291c;
// R6GameService.dll data @ 1009292c
constexpr unsigned int GLastServerQueriedAddress = 0x1009292c;
// R6GameService.dll data @ 10092e64
constexpr unsigned int GServiceString3 = 0x10092e64;
// R6GameService.dll data @ 10092e88
constexpr unsigned int GServiceArray4 = 0x10092e88;
// R6GameService.dll data @ 10092e98
constexpr unsigned int GServiceArray5 = 0x10092e98;
// R6GameService.dll data @ 10092ea4
constexpr unsigned int GGSClientInterface = 0x10092ea4;
// R6GameService.dll data @ 100933d4
constexpr unsigned int GActivationState = 0x100933d4;
// R6GameService.dll data @ 100933d8
constexpr unsigned int GBaseCDKeyContext = 0x100933d8;
// R6GameService.dll data @ 100933dc
constexpr unsigned int GModCDKeyContext = 0x100933dc;
// R6GameService.dll data @ 1009340c
constexpr unsigned int GAuthorizationState = 0x1009340c;
// R6GameService.dll data @ 1009343c
constexpr unsigned int GCDKeyRetryCount = 0x1009343c;
// R6GameService.dll data @ 10093440
constexpr unsigned int GServiceString4 = 0x10093440;
// R6GameService.dll data @ 1009344c
constexpr unsigned int GServiceString5 = 0x1009344c;
// R6GameService.dll data @ 10093458
constexpr unsigned int GServiceString6 = 0x10093458;
// R6GameService.dll data @ 10093464
constexpr unsigned int GServiceArray7 = 0x10093464;
// R6GameService.dll data @ 10093470
constexpr unsigned int GServiceArray8 = 0x10093470;
// R6GameService.dll data @ 1009347c
constexpr unsigned int GServiceString7 = 0x1009347c;
// R6GameService.dll data @ 10093488
constexpr unsigned int GServiceString8 = 0x10093488;
// R6GameService.dll data @ 10093494
constexpr unsigned int GServiceString9 = 0x10093494;
// R6GameService.dll data @ 100934a0
constexpr unsigned int GServiceString10 = 0x100934a0;
// R6GameService.dll data @ 100934ac
constexpr unsigned int GServiceString11 = 0x100934ac;
// R6GameService.dll data @ 100939d4
constexpr unsigned int GGSClientState = 0x100939d4;
// R6GameService.dll data @ 100939dc
constexpr unsigned int GServiceString12 = 0x100939dc;
// R6GameService.dll data @ 10093b0c
constexpr unsigned int GSecondaryLobbyLoginReplyType = 0x10093b0c;
// R6GameService.dll data @ 10093b18
constexpr unsigned int GSecondaryGroupId = 0x10093b18;
// R6GameService.dll data @ 10093b34
constexpr unsigned int GSecondaryLobbyServerId = 0x10093b34;
// R6GameService.dll data @ 10093b38
constexpr unsigned int GServiceArray10 = 0x10093b38;
// R6GameService.dll data @ 10093b44
constexpr unsigned int GServiceString13 = 0x10093b44;
// R6GameService.dll data @ 10093b70
constexpr unsigned int GByteStringPoolFreeLists = 0x10093b70;
// R6GameService.dll data @ 10093bb0
constexpr unsigned int GByteStringPoolLock = 0x10093bb0;
// R6GameService.dll data @ 10093bc0
constexpr unsigned int GByteStringPoolArenaCursor = 0x10093bc0;
// R6GameService.dll data @ 10093bf0
constexpr unsigned int GGSClientModule = 0x10093bf0;
// R6GameService.dll data @ 10093bf4
constexpr unsigned int GRegistrationEmptyText = 0x10093bf4;
// R6GameService.dll data @ 10093c04
constexpr unsigned int GPerformanceCounterBaseline = 0x10093c04;
// R6GameService.dll data @ 10093c0c
constexpr unsigned int GPerformanceCounterFrequency = 0x10093c0c;
// R6GameService.dll data @ 10093c28
constexpr unsigned int GInterfaceAddressPrefixes = 0x10093c28;
// R6GameService.dll data @ 10093d10
constexpr unsigned int GResolvedIPv4Address = 0x10093d10;
// R6GameService.dll data @ 10093d14
constexpr unsigned int GRegistrationServiceSingleton = 0x10093d14;
// R6GameService.dll data @ 10093d18
constexpr unsigned int GMSClientSingleton = 0x10093d18;
// R6GameService.dll data @ 10093d1c
constexpr unsigned int GCrtAttachCount = 0x10093d1c;
// R6GameService.dll data @ 10093d28
constexpr unsigned int GReflectedChecksumTable = 0x10093d28;
// R6GameService.dll data @ 10094128
constexpr unsigned int GForwardChecksumTable = 0x10094128;
// R6GameService.dll data @ 10094528
constexpr unsigned int GForwardChecksumReady = 0x10094528;
// R6GameService.dll data @ 10094529
constexpr unsigned int GReflectedChecksumReady = 0x10094529;
// R6GameService.dll data @ 10094570
constexpr unsigned int GHashAlgorithmRegistry = 0x10094570;
// R6GameService.dll data @ 10094574
constexpr unsigned int GPRNGAlgorithmRegistry = 0x10094574;
// R6GameService.dll data @ 10094578
constexpr unsigned int GCryptoAlgorithmRegistry = 0x10094578;
// R6GameService.dll data @ 1009457c
constexpr unsigned int GPKCAlgorithmRegistry = 0x1009457c;
// R6GameService.dll data @ 10094580
constexpr unsigned int GGLClientLifetimeFlag = 0x10094580;
// R6GameService.dll data @ 10094584
constexpr unsigned int GCurrentServiceState = 0x10094584;
// R6GameService.dll data @ 1009459c
constexpr unsigned int GCryptoHeaderTable = 0x1009459c;
// R6GameService.dll data @ 100945a0
constexpr unsigned int GCryptoKeyBuffer = 0x100945a0;
// R6GameService.dll data @ 100945a4
constexpr unsigned int GCryptoSecondaryKeyBuffer = 0x100945a4;
// R6GameService.dll data @ 100945a8
constexpr unsigned int GCryptoMetadata = 0x100945a8;
// R6GameService.dll data @ 100945b4
constexpr unsigned int GAdjustFdivSnapshot = 0x100945b4;
// R6GameService.dll data @ 100945b8
constexpr unsigned int GRawDllNotificationHook = 0x100945b8;
// R6GameService.dll data @ 100945bc
constexpr unsigned int GExitCallbacksEnd = 0x100945bc;
// R6GameService.dll data @ 100945c0
constexpr unsigned int GExitCallbacksBegin = 0x100945c0;
// R6GameService.dll data @ 100945c4
constexpr unsigned int GUpdateServiceRpcHandle = 0x100945c4;
// R6GameService.dll external-code-slot @ 10093bc4
constexpr unsigned int GLoadedGSClientConnectSlot = 0x10093bc4;
// R6GameService.dll external-code-slot @ 10093bc8
constexpr unsigned int GLoadedGSClientDisconnectSlot = 0x10093bc8;
// R6GameService.dll external-code-slot @ 10093bcc
constexpr unsigned int GLoadedGSClientDispatchMessageSlot = 0x10093bcc;
// R6GameService.dll external-code-slot @ 10093bd0
constexpr unsigned int GLoadedGSClientGetMessageSlot = 0x10093bd0;
// R6GameService.dll external-code-slot @ 10093bd4
constexpr unsigned int GLoadedGSClientGetMessageQueueNotEmptyEventSlot = 0x10093bd4;
// R6GameService.dll external-code-slot @ 10093bd8
constexpr unsigned int GLoadedGSClientInitializeSlot = 0x10093bd8;
// R6GameService.dll external-code-slot @ 10093bdc
constexpr unsigned int GLoadedGSClientMsgAllocSlot = 0x10093bdc;
// R6GameService.dll external-code-slot @ 10093be0
constexpr unsigned int GLoadedGSClientMsgDeleteSlot = 0x10093be0;
// R6GameService.dll external-code-slot @ 10093be4
constexpr unsigned int GLoadedGSClientUninitializeSlot = 0x10093be4;
// R6GameService.dll external-code-slot @ 10093be8
constexpr unsigned int GLoadedGSClientPostMessageSlot = 0x10093be8;
// R6GameService.dll external-code-slot @ 10093bec
constexpr unsigned int GLoadedGSClientMsgGetCopySlot = 0x10093bec;
// R6GameService.dll external-function-metadata @ 1007a8cc
constexpr unsigned int PatchServiceDestructionExceptionHandlerFunctionInfo = 0x1007a8cc;
// R6GameService.dll external-function-metadata @ 1007aa14
constexpr unsigned int EncryptWrapperExceptionHandlerFunctionInfo = 0x1007aa14;
// R6GameService.dll data @ 1007aa8c : defined beside the key conversion body
constexpr unsigned int DecryptWrapperExceptionHandlerFunctionInfo = 0x1007aa8c;
// R6GameService.dll data @ 1007aaf4 : defined beside the key conversion body
constexpr unsigned int MachineValidationExceptionHandlerFunctionInfo = 0x1007aaf4;
// R6GameService.dll external-function-metadata @ 1007ade8
constexpr unsigned int StreamSentryExceptionHandlerFunctionInfo = 0x1007ade8;
// R6GameService.dll external-function-metadata @ 1007ae48
constexpr unsigned int WideStringInsertionExceptionHandlerFunctionInfo = 0x1007ae48;
// R6GameService.dll external-function-metadata @ 1007b360
constexpr unsigned int PatchProgressExceptionHandlerFunctionInfo = 0x1007b360;
// R6GameService.dll external-function-metadata @ 1007b3c0
constexpr unsigned int PatchExitCauseExceptionHandlerFunctionInfo = 0x1007b3c0;
// R6GameService.dll external-function-metadata @ 1007b428
constexpr unsigned int PatchAccessBridgeExceptionHandlerFunctionInfo = 0x1007b428;
// R6GameService.dll external-function-metadata @ 1007b44c
constexpr unsigned int WideLogStreamDestructorExceptionHandlerFunctionInfo = 0x1007b44c;
// R6GameService.dll external-function-metadata @ 1007b478
constexpr unsigned int WideLogStreamConstructorExceptionHandlerFunctionInfo = 0x1007b478;
// R6GameService.dll external-function-metadata @ 1007b4e0
constexpr unsigned int AnsiWideInsertionExceptionHandlerFunctionInfo = 0x1007b4e0;
// R6GameService.dll external-function-metadata @ 1007b548
constexpr unsigned int PatchStatePollExceptionHandlerFunctionInfo = 0x1007b548;
// R6GameService.dll external-function-metadata @ 1007b5a8
constexpr unsigned int PatchStateExceptionHandlerFunctionInfo = 0x1007b5a8;
// R6GameService.dll external-function-metadata @ 1007b608
constexpr unsigned int PatchAbortBridgeExceptionHandlerFunctionInfo = 0x1007b608;
// R6GameService.dll external-function-metadata @ 1007b634
constexpr unsigned int WideLogFlushExceptionHandlerFunctionInfo = 0x1007b634;
// R6GameService.dll external-function-metadata @ 1007b658
constexpr unsigned int WideLogWriterExceptionHandlerFunctionInfo = 0x1007b658;
// R6GameService.dll external-function-metadata @ 1007b6c0
constexpr unsigned int PatchStartupExceptionHandlerFunctionInfo = 0x1007b6c0;
// R6GameService.dll external-function-metadata @ 1007b720
constexpr unsigned int PatchStartBridgeExceptionHandlerFunctionInfo = 0x1007b720;
// R6GameService.dll external-function-metadata @ 1007ec00
constexpr unsigned int PooledBufferReleaseExceptionHandlerFunctionInfo = 0x1007ec00;
// R6GameService.dll external-function-metadata @ 1007ef5c
constexpr unsigned int CCDKeyProcessMapDestroyExceptionHandlerFunctionInfo = 0x1007ef5c;
// R6GameService.dll external-function-metadata @ 1007ef80
constexpr unsigned int OwnedMapTreeDestroyExceptionHandlerFunctionInfo = 0x1007ef80;
// R6GameService.dll external-function-metadata @ 1007f7c0
constexpr unsigned int ClDataPointerListExceptionHandlerFunctionInfo = 0x1007f7c0;
// R6GameService.dll external-function-metadata @ 1007f7ec
constexpr unsigned int ClDataListExceptionHandlerFunctionInfo = 0x1007f7ec;
// R6GameService.dll external-function-metadata @ 1007f818
constexpr unsigned int EmptyPooledBufferInitExceptionHandlerFunctionInfo = 0x1007f818;
// R6GameService.dll external-function-metadata @ 1007f844
constexpr unsigned int TimestampedDescriptorPairExceptionHandlerFunctionInfo = 0x1007f844;
// R6GameService.dll external-function-metadata @ 1007f878
constexpr unsigned int PooledTripletCopyExceptionHandlerFunctionInfo = 0x1007f878;
// R6GameService.dll external-function-metadata @ 1007f8d8
constexpr unsigned int TimestampedNodeConstructExceptionHandlerFunctionInfo = 0x1007f8d8;
// R6GameService.dll external-function-metadata @ 1007f99c
constexpr unsigned int MessageBufferConstructionExceptionHandlerFunctionInfo = 0x1007f99c;
// R6GameService.dll external-function-metadata @ 1007f9e0
constexpr unsigned int MessageBufferDestructionExceptionHandlerFunctionInfo = 0x1007f9e0;
// R6GameService.dll external-function-metadata @ 1007fa0c
constexpr unsigned int MessageBufferReceiveExceptionHandlerFunctionInfo = 0x1007fa0c;
// R6GameService.dll external-function-metadata @ 1007fa30
constexpr unsigned int MessageBufferQueueExceptionHandlerFunctionInfo = 0x1007fa30;
// R6GameService.dll external-function-metadata @ 1007fad4
constexpr unsigned int ClDataListCloneExceptionHandlerFunctionInfo = 0x1007fad4;
// R6GameService.dll external-function-metadata @ 1007fb58
constexpr unsigned int ClDataListAssignmentExceptionHandlerFunctionInfo = 0x1007fb58;
// R6GameService.dll external-function-metadata @ 1007fbd0
constexpr unsigned int ClDataListIndentExceptionHandlerFunctionInfo = 0x1007fbd0;
// R6GameService.dll external-function-metadata @ 1007fc0c
constexpr unsigned int ClDataListStringAppendExceptionHandlerFunctionInfo = 0x1007fc0c;
// R6GameService.dll external-function-metadata @ 1007fca8
constexpr unsigned int ClDataListAppendExceptionHandlerFunctionInfo = 0x1007fca8;
// R6GameService.dll external-function-metadata @ 1007fd30
constexpr unsigned int BoundedIndexedStringExceptionHandlerFunctionInfo = 0x1007fd30;
// R6GameService.dll external-function-metadata @ 1007fe84
constexpr unsigned int IndexedTextScalarExceptionHandlerFunctionInfo = 0x1007fe84;
// R6GameService.dll external-function-metadata @ 1007fec0
constexpr unsigned int ExactIndexedBytesExceptionHandlerFunctionInfo = 0x1007fec0;
// R6GameService.dll external-function-metadata @ 1007ff14
constexpr unsigned int ClDataListSerializationExceptionHandlerFunctionInfo = 0x1007ff14;
// R6GameService.dll external-function-metadata @ 1007ff58
constexpr unsigned int ClDataListParseExceptionHandlerFunctionInfo = 0x1007ff58;
// R6GameService.dll external-function-metadata @ 1007ffd0
constexpr unsigned int ByteStringReserveExceptionHandlerFunctionInfo = 0x1007ffd0;
// R6GameService.dll external-function-metadata @ 10080014
constexpr unsigned int StringIndentExceptionHandlerFunctionInfo = 0x10080014;
// R6GameService.dll external-function-metadata @ 1008009c
constexpr unsigned int LongIndentExceptionHandlerFunctionInfo = 0x1008009c;
// R6GameService.dll external-function-metadata @ 100800e8
constexpr unsigned int ClDataSerializeListParseExceptionHandlerFunctionInfo = 0x100800e8;
// R6GameService.dll external-function-metadata @ 10080124
constexpr unsigned int TaggedStringParseExceptionHandlerFunctionInfo = 0x10080124;
// R6GameService.dll external-function-metadata @ 10080168
constexpr unsigned int TaggedByteBlockParseExceptionHandlerFunctionInfo = 0x10080168;
// R6GameService.dll external-function-metadata @ 10080194
constexpr unsigned int SimpleMessageConstructionExceptionHandlerFunctionInfo = 0x10080194;
// R6GameService.dll external-function-metadata @ 1008036c
constexpr unsigned int LoginRequestExceptionHandlerFunctionInfo = 0x1008036c;
// R6GameService.dll external-function-metadata @ 100803d0
constexpr unsigned int D9RequestExceptionHandlerFunctionInfo = 0x100803d0;
// R6GameService.dll external-function-metadata @ 1008047c
constexpr unsigned int RegistrationD5ExceptionHandlerFunctionInfo = 0x1008047c;
// R6GameService.dll external-function-metadata @ 100804a0
constexpr unsigned int RegistrationRecordReplyExceptionHandlerFunctionInfo = 0x100804a0;
// R6GameService.dll external-function-metadata @ 10080508
constexpr unsigned int LobbyLoginExceptionHandlerFunctionInfo = 0x10080508;
// R6GameService.dll external-function-metadata @ 1008058c
constexpr unsigned int OptionalRegistrationExceptionHandlerFunctionInfo = 0x1008058c;
// R6GameService.dll external-function-metadata @ 10080624
constexpr unsigned int RegistrationMatchExceptionHandlerFunctionInfo = 0x10080624;
// R6GameService.dll external-function-metadata @ 10080790
constexpr unsigned int LogicErrorBaseLifetimeExceptionHandlerFunctionInfo = 0x10080790;
// R6GameService.dll external-function-metadata @ 10080814
constexpr unsigned int VectorLengthThrowExceptionHandlerFunctionInfo = 0x10080814;
// R6GameService.dll external-function-metadata @ 10080890
constexpr unsigned int WideHexEncoderExceptionHandlerFunctionInfo = 0x10080890;
// R6GameService.dll external-function-metadata @ 100808e0
constexpr unsigned int ByteVectorCopyExceptionHandlerFunctionInfo = 0x100808e0;
// R6GameService.dll data @ 10080938 : defined beside the collected-data bodies
constexpr unsigned int CollectedByteBuilderExceptionHandlerFunctionInfo = 0x10080938;
// R6GameService.dll data @ 1008095c : defined beside the wide-hex decoder
constexpr unsigned int LocalByteVectorExceptionHandlerFunctionInfo = 0x1008095c;
// R6GameService.dll external-function-metadata @ 10080988
constexpr unsigned int EncryptWideHexExceptionHandlerFunctionInfo = 0x10080988;
// R6GameService.dll data @ 100809cc : defined beside the key conversion body
constexpr unsigned int DecryptWideHexExceptionHandlerFunctionInfo = 0x100809cc;
// R6GameService.dll data @ 100809f8 : defined beside the key conversion body
constexpr unsigned int ValidateWideHexExceptionHandlerFunctionInfo = 0x100809f8;
// R6GameService.dll external-function-metadata @ 10080af4
constexpr unsigned int DirectoryProbeExceptionHandlerFunctionInfo = 0x10080af4;
// R6GameService.dll external-function-metadata @ 10080b4c
constexpr unsigned int StringRangeConstructionExceptionHandlerFunctionInfo = 0x10080b4c;
// R6GameService.dll external-function-metadata @ 10080ba4
constexpr unsigned int RepeatedStringConstructionExceptionHandlerFunctionInfo = 0x10080ba4;
// R6GameService.dll external-function-metadata @ 10080c30
constexpr unsigned int StringVectorInsertionExceptionHandlerFunctionInfo = 0x10080c30;
// R6GameService.dll data @ 10080c5c : defined beside the collected-data bodies
constexpr unsigned int AdapterAddressCollectorExceptionHandlerFunctionInfo = 0x10080c5c;
// R6GameService.dll external-function-metadata @ 10080d24
constexpr unsigned int CipherModuleBlowfishConstructExceptionHandlerFunctionInfo = 0x10080d24;
// R6GameService.dll external-function-metadata @ 10080d6c
constexpr unsigned int CipherModuleDestroyExceptionHandlerFunctionInfo = 0x10080d6c;
// R6GameService.dll external-function-metadata @ 10080db8
constexpr unsigned int HashAlgorithmFactoryExceptionHandlerFunctionInfo = 0x10080db8;
// R6GameService.dll external-function-metadata @ 10080dec
constexpr unsigned int PRNGAlgorithmFactoryExceptionHandlerFunctionInfo = 0x10080dec;
// R6GameService.dll external-function-metadata @ 10080e28
constexpr unsigned int CryptoAlgorithmFactoryExceptionHandlerFunctionInfo = 0x10080e28;
// R6GameService.dll external-function-metadata @ 10080e5c
constexpr unsigned int PKCAlgorithmFactoryExceptionHandlerFunctionInfo = 0x10080e5c;
// R6GameService.dll external-function-metadata @ 10080e88
constexpr unsigned int HashAlgorithmMapDestroyExceptionHandlerFunctionInfo = 0x10080e88;
// R6GameService.dll external-function-metadata @ 10080ed8
constexpr unsigned int PRNGAlgorithmMapDestroyExceptionHandlerFunctionInfo = 0x10080ed8;
// R6GameService.dll external-function-metadata @ 10080f28
constexpr unsigned int CryptoAlgorithmMapDestroyExceptionHandlerFunctionInfo = 0x10080f28;
// R6GameService.dll external-function-metadata @ 10080f78
constexpr unsigned int PKCAlgorithmMapDestroyExceptionHandlerFunctionInfo = 0x10080f78;
// R6GameService.dll external-function-metadata @ 10080f9c
constexpr unsigned int RegistryTreeDestroyExceptionHandlerFunctionInfo = 0x10080f9c;
// R6GameService.dll external-function-metadata @ 10080fc0
constexpr unsigned int CBlowFishDestroyExceptionHandlerFunctionInfo = 0x10080fc0;
// R6GameService.dll external-function-metadata @ 10080ff4
constexpr unsigned int HashModuleSHA1ConstructExceptionHandlerFunctionInfo = 0x10080ff4;
// R6GameService.dll external-function-metadata @ 10081044
constexpr unsigned int HashModuleMD5ConstructExceptionHandlerFunctionInfo = 0x10081044;
// R6GameService.dll external-function-metadata @ 10081068
constexpr unsigned int HashModuleDestroyExceptionHandlerFunctionInfo = 0x10081068;
// R6GameService.dll external-function-metadata @ 100810a4
constexpr unsigned int MGF1ConstructExceptionHandlerFunctionInfo = 0x100810a4;
// R6GameService.dll external-function-metadata @ 100810c8
constexpr unsigned int MGF1DestroyExceptionHandlerFunctionInfo = 0x100810c8;
// R6GameService.dll external-function-metadata @ 100810fc
constexpr unsigned int PKCRSAConstructExceptionHandlerFunctionInfo = 0x100810fc;
// R6GameService.dll external-function-metadata @ 10081120
constexpr unsigned int PKCRSADestroyExceptionHandlerFunctionInfo = 0x10081120;
// R6GameService.dll external-function-metadata @ 1008114c
constexpr unsigned int SecureHashAlgorithm1ConstructExceptionHandlerFunctionInfo = 0x1008114c;
// R6GameService.dll external-function-metadata @ 10081178
constexpr unsigned int MD5ConstructExceptionHandlerFunctionInfo = 0x10081178;
// R6GameService.dll external-function-metadata @ 100811c0
constexpr unsigned int RandomStackMD5ExceptionHandlerFunctionInfo = 0x100811c0;
// R6GameService.dll external-function-metadata @ 100811e4
constexpr unsigned int GLClientConstructExceptionHandlerFunctionInfo = 0x100811e4;
// R6GameService.dll external-function-metadata @ 10081268
constexpr unsigned int ServiceStateConstructExceptionHandlerFunctionInfo = 0x10081268;
// R6GameService.dll data @ 10081284
constexpr unsigned int ServiceStateDestroyUnwindMap = 0x10081284;
// R6GameService.dll external-function-metadata @ 1008129c
constexpr unsigned int ServiceStateDestroyExceptionHandlerFunctionInfo = 0x1008129c;
// R6GameService.dll external-function-metadata @ 10082b0c
constexpr unsigned int CMsgQueueDestroyExceptionHandlerFunctionInfo = 0x10082b0c;
// R6GameService.dll external-function-metadata @ 10082b50
constexpr unsigned int CMsgQueueRemoveExceptionHandlerFunctionInfo = 0x10082b50;
// R6GameService.dll external-function-metadata @ 10082b94
constexpr unsigned int CMsgQueuePeekExceptionHandlerFunctionInfo = 0x10082b94;
// R6GameService.dll external-function-metadata @ 10082bc0
constexpr unsigned int PayloadRecordConstructExceptionHandlerFunctionInfo = 0x10082bc0;
// R6GameService.dll external-function-metadata @ 10082bec
constexpr unsigned int PayloadRecordCopyExceptionHandlerFunctionInfo = 0x10082bec;
// R6GameService.dll external-function-metadata @ 10083ddc
constexpr unsigned int TransportRecordDecodeExceptionHandlerFunctionInfo = 0x10083ddc;
// R6GameService.dll external-function-metadata @ 10083ffc
constexpr unsigned int QueuedTransportDecodeExceptionHandlerFunctionInfo = 0x10083ffc;

// R6GameService.dll data @ 1007aa30 : key conversion exception metadata.
constexpr unsigned int DecryptWrapperUnwindMap = 0x1007aa30;

// R6GameService.dll data @ 1007aa58 : key conversion exception metadata.
constexpr unsigned int DecryptWrapperCatchHandlers = 0x1007aa58;

// R6GameService.dll data @ 1007aa78 : key conversion exception metadata.
constexpr unsigned int DecryptWrapperTryMap = 0x1007aa78;

// R6GameService.dll data @ 1007aaa8 : key conversion exception metadata.
constexpr unsigned int MachineValidationUnwindMap = 0x1007aaa8;

// R6GameService.dll data @ 1007aac0 : key conversion exception metadata.
constexpr unsigned int MachineValidationCatchHandlers = 0x1007aac0;

// R6GameService.dll data @ 1007aae0 : key conversion exception metadata.
constexpr unsigned int MachineValidationTryMap = 0x1007aae0;

// R6GameService.dll data @ 100809a4 : key conversion exception metadata.
constexpr unsigned int DecryptWideHexUnwindMap = 0x100809a4;

// R6GameService.dll data @ 100809e8 : key conversion exception metadata.
constexpr unsigned int ValidateWideHexUnwindMap = 0x100809e8;

// R6GameService.dll data @ 10080954 : pooled local-vector unwind entries.
constexpr unsigned int LocalByteVectorUnwindMap = 0x10080954;

// R6GameService.dll data @ 10080920 : collected-byte builder cleanup states.
constexpr unsigned int CollectedByteBuilderUnwindMap = 0x10080920;
// R6GameService.dll data @ 10080c4c : adapter collector aligned-frame cleanup states.
constexpr unsigned int AdapterAddressCollectorUnwindMap = 0x10080c4c;
// UTF-16 registration diagnostics; descriptive identifiers follow the selected binary text.
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerLoginResultsILobbyServerIDI = 0x10075268;
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerLoginResultsIGroupIDI = 0x100751e8;
constexpr unsigned int WideTextCallbackRegServerRcvLobbyServerLoginResultsFailedReasonI = 0x10075160;

}
