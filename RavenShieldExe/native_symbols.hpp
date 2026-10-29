#pragma once
#include <cstdint>

// Native PE32 address words use raw entry aliases, never C++ member-function pointer representations.
// Alias names describe established roles; they do not claim recovery of the original linker symbols.
// Code declarations are address anchors, not callable prototypes; the real definitions retain their native ABI.
#define NativeAddress(symbol) reinterpret_cast<uint32_t>(&(symbol))

// Native entry @ 109017c0 : WConfigWizard::OnInitDialog
extern "C" void NativeEntry_WConfigWizard_OnInitDialog();
// Native entry @ 10901c20 : GetLauncherWindowPackageName
extern "C" void NativeEntry_GetLauncherWindowPackageName();
// Native entry @ 10901c30 : WConfigPageSafeOptions::OnInitDialog
extern "C" void NativeEntry_WConfigPageSafeOptions_OnInitDialog();
// Native entry @ 10901ee0 : WConfigPageSafeOptions::GetNextText
extern "C" void NativeEntry_WConfigPageSafeOptions_GetNextText();
// Native entry @ 10901f00 : WConfigPageSafeOptions::GetNext
extern "C" void NativeEntry_WConfigPageSafeOptions_GetNext();
// Native entry @ 109028d0 : FExecHook::NotifyDestroy
extern "C" void NativeEntry_FExecHook_NotifyDestroy();
// Native entry @ 109029b0 : FMallocWindows::HeapCheck
extern "C" void NativeEntry_FMallocWindows_HeapCheck();
// Native entry @ 10902b90 : FMallocWindows::Init
extern "C" void NativeEntry_FMallocWindows_Init();
// Native entry @ 10902de0 : FMallocWindows::Exit
extern "C" void NativeEntry_FMallocWindows_Exit();
// Native entry @ 10902df0 : FMallocWindows::FormatMemoryStats
extern "C" void NativeEntry_FMallocWindows_FormatMemoryStats();
// Native entry @ 10902f40 : FOutputDeviceFile::Serialize
extern "C" void NativeEntry_FOutputDeviceFile_Serialize();
// Native entry @ 109032a0 : FOutputDeviceWindowsError::Serialize
extern "C" void NativeEntry_FOutputDeviceWindowsError_Serialize();
// Native entry @ 109034c0 : FOutputDeviceWindowsError::HandleError
extern "C" void NativeEntry_FOutputDeviceWindowsError_HandleError();
// Native entry @ 10903710 : FFeedbackContextWindows::Serialize
extern "C" void NativeEntry_FFeedbackContextWindows_Serialize();
// Native entry @ 10903800 : FFeedbackContextWindows::YesNof
extern "C" void NativeEntry_FFeedbackContextWindows_YesNof();
// Native entry @ 10903900 : FFeedbackContextWindows::MapCheck_Show
extern "C" void NativeEntry_FFeedbackContextWindows_MapCheck_Show();
// Native entry @ 109039c0 : FFeedbackContextWindows::MapCheck_ShowConditionally
extern "C" void NativeEntry_FFeedbackContextWindows_MapCheck_ShowConditionally();
// Native entry @ 10903a80 : FFeedbackContextWindows::MapCheck_Hide
extern "C" void NativeEntry_FFeedbackContextWindows_MapCheck_Hide();
// Native entry @ 10903b40 : FFeedbackContextWindows::MapCheck_Clear
extern "C" void NativeEntry_FFeedbackContextWindows_MapCheck_Clear();
// Native entry @ 10903c00 : FFeedbackContextWindows::BeginSlowTask
extern "C" void NativeEntry_FFeedbackContextWindows_BeginSlowTask();
// Native entry @ 10903e20 : FFeedbackContextWindows::EndSlowTask
extern "C" void NativeEntry_FFeedbackContextWindows_EndSlowTask();
// Native entry @ 10903ef0 : FFeedbackContextWindows::StatusUpdatef
extern "C" void NativeEntry_FFeedbackContextWindows_StatusUpdatef();
// Native entry @ 109041b0 : IgnoreSharedVirtualArgument
extern "C" void NativeEntry_IgnoreSharedVirtualArgument();
// Native entry @ 10904470 : WConfigWizard::GetWindowClassName
extern "C" void NativeEntry_WConfigWizard_GetWindowClassName();
// Native entry @ 10904490 : WConfigWizard::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigWizard_ScalarDeletingDestructor();
// Native entry @ 109044c0 : WConfigPageSafeOptions::GetWindowClassName
extern "C" void NativeEntry_WConfigPageSafeOptions_GetWindowClassName();
// Native entry @ 109044e0 : FConfigCache::ScalarDeletingDestructor
extern "C" void NativeEntry_FConfigCache_ScalarDeletingDestructor();
// Native entry @ 10904510 : WConfigPageSafeOptions::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageSafeOptions_ScalarDeletingDestructor();
// Native entry @ 10904630 : FMallocWindows::Malloc
extern "C" void NativeEntry_FMallocWindows_Malloc();
// Native entry @ 10904ba0 : FMallocWindows::Realloc
extern "C" void NativeEntry_FMallocWindows_Realloc();
// Native entry @ 10904ff0 : FMallocWindows::Free
extern "C" void NativeEntry_FMallocWindows_Free();
// Native entry @ 10905200 : FMallocWindows::DumpAllocs
extern "C" void NativeEntry_FMallocWindows_DumpAllocs();
// Native entry @ 10905600 : FFeedbackContextWindows::MapCheck_Add
extern "C" void NativeEntry_FFeedbackContextWindows_MapCheck_Add();
// Native entry @ 10905e40 : FFileManagerWindows::CreateFileReader
extern "C" void NativeEntry_FFileManagerWindows_CreateFileReader();
// Native entry @ 10906140 : FArchiveFileReader::Seek
extern "C" void NativeEntry_FArchiveFileReader_Seek();
// Native entry @ 10906270 : FArchiveFileReader::Tell
extern "C" void NativeEntry_FArchiveFileReader_Tell();
// Native entry @ 10906290 : FArchiveFileReader::Close
extern "C" void NativeEntry_FArchiveFileReader_Close();
// Native entry @ 109062d0 : FFileManagerWindows::CreateFileWriter
extern "C" void NativeEntry_FFileManagerWindows_CreateFileWriter();
// Native entry @ 109065e0 : FArchiveFileWriter::Seek
extern "C" void NativeEntry_FArchiveFileWriter_Seek();
// Native entry @ 10906650 : ReadSharedArchiveOffset48
extern "C" void NativeEntry_ReadSharedArchiveOffset48();
// Native entry @ 10906670 : FArchiveFileWriter::Close
extern "C" void NativeEntry_FArchiveFileWriter_Close();
// Native entry @ 109066f0 : FArchiveFileWriter::Serialize
extern "C" void NativeEntry_FArchiveFileWriter_Serialize();
// Native entry @ 109067b0 : FArchiveFileWriter::Flush
extern "C" void NativeEntry_FArchiveFileWriter_Flush();
// Native entry @ 10906830 : FFileManagerWindows::FileSize
extern "C" void NativeEntry_FFileManagerWindows_FileSize();
// Native entry @ 109069a0 : FFileManagerWindows::Delete
extern "C" void NativeEntry_FFileManagerWindows_Delete();
// Native entry @ 10906ba0 : FFileManagerWindows::Move
extern "C" void NativeEntry_FFileManagerWindows_Move();
// Native entry @ 10906d90 : FFileManagerWindows::GetGlobalTime
extern "C" void NativeEntry_FFileManagerWindows_GetGlobalTime();
// Native entry @ 10906f10 : FFileManagerWindows::SetGlobalTime
extern "C" void NativeEntry_FFileManagerWindows_SetGlobalTime();
// Native entry @ 10906f20 : FFileManagerWindows::SetDefaultDirectory
extern "C" void NativeEntry_FFileManagerWindows_SetDefaultDirectory();
// Native entry @ 10907050 : FFileManagerWindows::GetDefaultDirectory
extern "C" void NativeEntry_FFileManagerWindows_GetDefaultDirectory();
// Native entry @ 109071b0 : FArchiveFileReader::Precache
extern "C" void NativeEntry_FArchiveFileReader_Precache();
// Native entry @ 10907270 : FArchiveFileReader::Serialize
extern "C" void NativeEntry_FArchiveFileReader_Serialize();
// Native entry @ 10907400 : FArchiveFileReader::ScalarDeletingDestructor
extern "C" void NativeEntry_FArchiveFileReader_ScalarDeletingDestructor();
// Native entry @ 109074f0 : FArchiveFileWriter::ScalarDeletingDestructor
extern "C" void NativeEntry_FArchiveFileWriter_ScalarDeletingDestructor();
// Native entry @ 109075d0 : FFileManagerWindows::Copy
extern "C" void NativeEntry_FFileManagerWindows_Copy();
// Native entry @ 10907860 : FFileManagerWindows::MakeDirectory
extern "C" void NativeEntry_FFileManagerWindows_MakeDirectory();
// Native entry @ 10907e70 : TArray<FRegistryObjectInfo>::~TArray
extern "C" void NativeEntry_TArray_FRegistryObjectInfo_DestroyTArray();
// Native entry @ 10907fc0 : TArray<FString>::~TArray
extern "C" void NativeEntry_TArray_FString_DestroyTArray();
// Native entry @ 10908150 : FExecHook::Exec
extern "C" void NativeEntry_FExecHook_Exec();
// Native entry @ 10908ea0 : FStringOutputDevice::Serialize
extern "C" void NativeEntry_FStringOutputDevice_Serialize();
// Native entry @ 10908ef0 : WObjectProperties::ScalarDeletingDestructor
extern "C" void NativeEntry_WObjectProperties_ScalarDeletingDestructor();
// Native entry @ 10908f20 : WConfigProperties::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigProperties_ScalarDeletingDestructor();
// Native entry @ 1090a6a0 : FFileManagerWindows::DeleteDirectory
extern "C" void NativeEntry_FFileManagerWindows_DeleteDirectory();
// Native entry @ 1090a810 : FFileManagerWindows::FindFiles
extern "C" void NativeEntry_FFileManagerWindows_FindFiles();
// Native entry @ 1090aca0 : TArray<TMapBase<FString, FString>::TPair>::~TArray
extern "C" void NativeEntry_TArray_TMapBase_FString_FString_TPair_DestroyTArray();
// Native entry @ 1090b1c0 : TMapBase<FString, FString>::~TMapBase
extern "C" void NativeEntry_TMapBase_FString_FString_DestroyTMapBase();
// Native entry @ 1090b360 : WConfigPageRenderer::OnCurrent
extern "C" void NativeEntry_WConfigPageRenderer_OnCurrent();
// Native entry @ 1090b3e0 : WConfigPageRenderer::GetWindowClassName
extern "C" void NativeEntry_WConfigPageRenderer_GetWindowClassName();
// Native entry @ 1090b400 : WConfigPageRenderer::GetNext
extern "C" void NativeEntry_WConfigPageRenderer_GetNext();
// Native entry @ 1090b620 : WConfigPageDetail::OnInitDialog
extern "C" void NativeEntry_WConfigPageDetail_OnInitDialog();
// Native entry @ 1090c0c0 : WConfigPageDetail::GetNext
extern "C" void NativeEntry_WConfigPageDetail_GetNext();
// Native entry @ 1090c160 : WConfigPageFirstTime::GetNext
extern "C" void NativeEntry_WConfigPageFirstTime_GetNext();
// Native entry @ 1090c180 : WConfigPageDetail::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageDetail_ScalarDeletingDestructor();
// Native entry @ 1090c2d0 : WConfigPageDriver::OnInitDialog
extern "C" void NativeEntry_WConfigPageDriver_OnInitDialog();
// Native entry @ 1090c380 : WConfigPageDriver::GetNext
extern "C" void NativeEntry_WConfigPageDriver_GetNext();
// Native entry @ 1090c400 : WConfigPageDriver::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageDriver_ScalarDeletingDestructor();
// Native entry @ 1090c4b0 : WConfigPageFirstTime::GetWindowClassName
extern "C" void NativeEntry_WConfigPageFirstTime_GetWindowClassName();
// Native entry @ 1090c4d0 : WConfigPageFirstTime::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageFirstTime_ScalarDeletingDestructor();
// Native entry @ 1090c560 : WConfigPageDetail::GetWindowClassName
extern "C" void NativeEntry_WConfigPageDetail_GetWindowClassName();
// Native entry @ 1090c580 : WConfigPageDriver::GetWindowClassName
extern "C" void NativeEntry_WConfigPageDriver_GetWindowClassName();
// Native entry @ 1090c5a0 : WConfigPageRenderer::OnInitDialog
extern "C" void NativeEntry_WConfigPageRenderer_OnInitDialog();
// Native entry @ 1090c680 : WConfigPageRenderer::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageRenderer_ScalarDeletingDestructor();
// Native entry @ 1090c760 : WConfigPageRenderer::OnPaint
extern "C" void NativeEntry_WConfigPageRenderer_OnPaint();
// Native entry @ 1090cd00 : WConfigPageSafeMode::GetNextText
extern "C" void NativeEntry_WConfigPageSafeMode_GetNextText();
// Native entry @ 1090cd10 : WConfigPageSafeMode::ScalarDeletingDestructor
extern "C" void NativeEntry_WConfigPageSafeMode_ScalarDeletingDestructor();
// Native entry @ 1090cde0 : WConfigPageSafeMode::GetWindowClassName
extern "C" void NativeEntry_WConfigPageSafeMode_GetWindowClassName();
// Native entry @ 1090dad0 : ForwardFStringMapDestruction
extern "C" void NativeEntry_ForwardFStringMapDestruction();
// Native entry @ 1090dbd0 : TArray<TMapBase<FString, FConfigSection>::TPair>::~TArray
extern "C" void NativeEntry_TArray_TMapBase_FString_FConfigSection_TPair_DestroyTArray();
// Native entry @ 1090dc20 : TMapBase<FString, FConfigSection>::~TMapBase
extern "C" void NativeEntry_TMapBase_FString_FConfigSection_DestroyTMapBase();
// Native entry @ 1090dc90 : ForwardFConfigSectionMapDestruction
extern "C" void NativeEntry_ForwardFConfigSectionMapDestruction();
// Native entry @ 1090dd90 : TArray<TMapBase<FString, FConfigFile>::TPair>::~TArray
extern "C" void NativeEntry_TArray_TMapBase_FString_FConfigFile_TPair_DestroyTArray();
// Native entry @ 1090dde0 : TMapBase<FString, FConfigFile>::~TMapBase
extern "C" void NativeEntry_TMapBase_FString_FConfigFile_DestroyTMapBase();
// Native entry @ 1090de50 : DestroyConfigFileMapThunk
extern "C" void NativeEntry_DestroyConfigFileMapThunk();
// Native entry @ 1090df10 : FConfigCacheIni::Init
extern "C" void NativeEntry_FConfigCacheIni_Init();
// Native entry @ 1090dfa0 : FConfigCacheIni::InitUser
extern "C" void NativeEntry_FConfigCacheIni_InitUser();
// Native entry @ 1090e060 : FConfigCacheIni::GetUserIni
extern "C" void NativeEntry_FConfigCacheIni_GetUserIni();
// Native entry @ 1090e0f0 : FConfigCacheIni::InitServer
extern "C" void NativeEntry_FConfigCacheIni_InitServer();
// Native entry @ 1090e190 : FConfigCacheIni::GetServerIni
extern "C" void NativeEntry_FConfigCacheIni_GetServerIni();
// Native entry @ 1090e220 : FConfigCacheIni::Exit
extern "C" void NativeEntry_FConfigCacheIni_Exit();
// Native entry @ 1090e2a0 : FConfigCacheIni::GetString
extern "C" void NativeEntry_FConfigCacheIni_GetStringIntoString();
// Native entry @ 1090e370 : FConfigCacheIni::GetStr
extern "C" void NativeEntry_FConfigCacheIni_GetStr();
// Native entry @ 1090e410 : FConfigCacheIni::GetInt
extern "C" void NativeEntry_FConfigCacheIni_GetInt();
// Native entry @ 1090e4d0 : FConfigCacheIni::GetFloat
extern "C" void NativeEntry_FConfigCacheIni_GetFloat();
// Native entry @ 1090e590 : FConfigCacheIni::GetBool
extern "C" void NativeEntry_FConfigCacheIni_GetBool();
// Native entry @ 1090e680 : FConfigCacheIni::SetInt
extern "C" void NativeEntry_FConfigCacheIni_SetInt();
// Native entry @ 1090e720 : FConfigCacheIni::SetFloat
extern "C" void NativeEntry_FConfigCacheIni_SetFloat();
// Native entry @ 1090e7c0 : FConfigCacheIni::SetBool
extern "C" void NativeEntry_FConfigCacheIni_SetBool();
// Native entry @ 1090e850 : FConfigCacheIni::Dump
extern "C" void NativeEntry_FConfigCacheIni_Dump();
// Native entry @ 1090e9a0 : FConfigCacheIni::PBfindKey
extern "C" void NativeEntry_FConfigCacheIni_PBfindKey();
// Native entry @ 1090ed50 : TMapBase<FString, FConfigFile>::TIterator::~TIterator
extern "C" void NativeEntry_TMapBase_FString_FConfigFile_TIterator_DestroyTIterator();
// Native entry @ 1090ed60 : FConfigCacheIni::PBgetSection
extern "C" void NativeEntry_FConfigCacheIni_PBgetSection();
// Native entry @ 1090f2c0 : FConfigCacheIni::Flush
extern "C" void NativeEntry_FConfigCacheIni_Flush();
// Native entry @ 1090f730 : TMapBase<FString, FConfigSection>::TIterator::~TIterator
extern "C" void NativeEntry_TMapBase_FString_FConfigSection_TIterator_DestroyTIterator();
// Native entry @ 1090f830 : TMapBase<FString, FString>::TIterator::~TIterator
extern "C" void NativeEntry_TMapBase_FString_FString_TIterator_DestroyTIterator();
// Native entry @ 1090f910 : FConfigCacheIni::Cancel
extern "C" void NativeEntry_FConfigCacheIni_Cancel();
// Native entry @ 109106e0 : FConfigCacheIni::GetString
extern "C" void NativeEntry_FConfigCacheIni_GetStringIntoBuffer();
// Native entry @ 109107f0 : FConfigCacheIni::GetSection
extern "C" void NativeEntry_FConfigCacheIni_GetSection();
// Native entry @ 10910970 : FConfigCacheIni::GetSectionPrivate
extern "C" void NativeEntry_FConfigCacheIni_GetSectionPrivate();
// Native entry @ 10910a90 : FConfigCacheIni::SetString
extern "C" void NativeEntry_FConfigCacheIni_SetString();
// Native entry @ 10910c50 : FConfigCacheIni::EmptySection
extern "C" void NativeEntry_FConfigCacheIni_EmptySection();
// Native entry @ 10910dd0 : FConfigCacheIni::ScalarDeletingDestructor
extern "C" void NativeEntry_FConfigCacheIni_ScalarDeletingDestructor();
// Native entry @ 10911890 : WLog::ScalarDeletingDestructor
extern "C" void NativeEntry_WLog_ScalarDeletingDestructor();
// Native entry @ 109118b4 : WWizardDialog::OnCancel
extern "C" void NativeEntry_WWizardDialog_OnCancel();
// Native entry @ 109118ba : WWizardDialog::OnFinish
extern "C" void NativeEntry_WWizardDialog_OnFinish();
// Native entry @ 109118c0 : WWizardDialog::OnNext
extern "C" void NativeEntry_WWizardDialog_OnNext();
// Native entry @ 109118c6 : WWizardDialog::OnBack
extern "C" void NativeEntry_WWizardDialog_OnBack();
// Native entry @ 109118cc : WWizardDialog::RefreshPage
extern "C" void NativeEntry_WWizardDialog_RefreshPage();
// Native entry @ 109118d2 : WWizardDialog::Advance
extern "C" void NativeEntry_WWizardDialog_Advance();
// Native entry @ 109118d8 : WDialog::LocalizeText
extern "C" void NativeEntry_WDialog_LocalizeText();
// Native entry @ 109118de : WDialog::DoModal
extern "C" void NativeEntry_WDialog_DoModal();
// Native entry @ 109118e4 : WWindow::MyDrawEdge
extern "C" void NativeEntry_WWindow_MyDrawEdge();
// Native entry @ 109118ea : WWizardDialog::OnDestroy
extern "C" void NativeEntry_WWizardDialog_OnDestroy();
// Native entry @ 109118f0 : WWizardDialog::OnClose
extern "C" void NativeEntry_WWizardDialog_OnClose();
// Native entry @ 109118f6 : WWindow::OnSetCursor
extern "C" void NativeEntry_WWindow_OnSetCursor();
// Native entry @ 109118fc : WWindow::OnFinishSplitterDrag
extern "C" void NativeEntry_WWindow_OnFinishSplitterDrag();
// Native entry @ 10911902 : WWindow::OnRightButtonUp
extern "C" void NativeEntry_WWindow_OnRightButtonUp();
// Native entry @ 10911908 : WWindow::OnLeftButtonUp
extern "C" void NativeEntry_WWindow_OnLeftButtonUp();
// Native entry @ 1091190e : WWindow::OnRightButtonDown
extern "C" void NativeEntry_WWindow_OnRightButtonDown();
// Native entry @ 10911914 : WWindow::OnRightButtonDoubleClick
extern "C" void NativeEntry_WWindow_OnRightButtonDoubleClick();
// Native entry @ 1091191a : WWindow::OnMiddleButtonDoubleClick
extern "C" void NativeEntry_WWindow_OnMiddleButtonDoubleClick();
// Native entry @ 10911920 : WWindow::OnLeftButtonDoubleClick
extern "C" void NativeEntry_WWindow_OnLeftButtonDoubleClick();
// Native entry @ 10911926 : WWindow::OnLeftButtonDown
extern "C" void NativeEntry_WWindow_OnLeftButtonDown();
// Native entry @ 1091192c : WWindow::OnMouseMove
extern "C" void NativeEntry_WWindow_OnMouseMove();
// Native entry @ 10911932 : WWindow::OnMdiActivate
extern "C" void NativeEntry_WWindow_OnMdiActivate();
// Native entry @ 10911938 : WWindow::OnReleaseCapture
extern "C" void NativeEntry_WWindow_OnReleaseCapture();
// Native entry @ 1091193e : WWindow::OnTimer
extern "C" void NativeEntry_WWindow_OnTimer();
// Native entry @ 10911944 : WWindow::OnMouseHover
extern "C" void NativeEntry_WWindow_OnMouseHover();
// Native entry @ 1091194a : WWindow::OnMouseLeave
extern "C" void NativeEntry_WWindow_OnMouseLeave();
// Native entry @ 10911950 : WWindow::OnMouseEnter
extern "C" void NativeEntry_WWindow_OnMouseEnter();
// Native entry @ 10911956 : WWindow::OnEnterIdle
extern "C" void NativeEntry_WWindow_OnEnterIdle();
// Native entry @ 1091195c : WWindow::OnMeasureItem
extern "C" void NativeEntry_WWindow_OnMeasureItem();
// Native entry @ 10911962 : WWindow::OnDrawItem
extern "C" void NativeEntry_WWindow_OnDrawItem();
// Native entry @ 10911968 : WWindow::OnCreate
extern "C" void NativeEntry_WWindow_OnCreate();
// Native entry @ 1091196e : WWindow::OnPaint
extern "C" void NativeEntry_WWindow_OnPaint();
// Native entry @ 10911974 : WWindow::OnKeyUp
extern "C" void NativeEntry_WWindow_OnKeyUp();
// Native entry @ 1091197a : WWindow::OnHScroll
extern "C" void NativeEntry_WWindow_OnHScroll();
// Native entry @ 10911980 : WWindow::OnVScroll
extern "C" void NativeEntry_WWindow_OnVScroll();
// Native entry @ 10911986 : WWindow::OnEraseBkgnd
extern "C" void NativeEntry_WWindow_OnEraseBkgnd();
// Native entry @ 1091198c : WWindow::OnUndo
extern "C" void NativeEntry_WWindow_OnUndo();
// Native entry @ 10911992 : WWindow::OnShowWindow
extern "C" void NativeEntry_WWindow_OnShowWindow();
// Native entry @ 10911998 : WWindow::OnPaste
extern "C" void NativeEntry_WWindow_OnPaste();
// Native entry @ 1091199e : WWindow::OnCopy
extern "C" void NativeEntry_WWindow_OnCopy();
// Native entry @ 109119a4 : WWindow::OnCut
extern "C" void NativeEntry_WWindow_OnCut();
// Native entry @ 109119aa : WWindow::OnKeyDown
extern "C" void NativeEntry_WWindow_OnKeyDown();
// Native entry @ 109119b0 : WWindow::OnChar
extern "C" void NativeEntry_WWindow_OnChar();
// Native entry @ 109119b6 : WWindow::OnActivate
extern "C" void NativeEntry_WWindow_OnActivate();
// Native entry @ 109119bc : WWindow::OnSysCommand
extern "C" void NativeEntry_WWindow_OnSysCommand();
// Native entry @ 109119c2 : WWindow::OnCommand
extern "C" void NativeEntry_WWindow_OnCommand();
// Native entry @ 109119c8 : WWindow::OnMove
extern "C" void NativeEntry_WWindow_OnMove();
// Native entry @ 109119ce : WWindow::OnWindowPosChanging
extern "C" void NativeEntry_WWindow_OnWindowPosChanging();
// Native entry @ 109119d4 : WWindow::OnSize
extern "C" void NativeEntry_WWindow_OnSize();
// Native entry @ 109119da : WWindow::OnKillFocus
extern "C" void NativeEntry_WWindow_OnKillFocus();
// Native entry @ 109119e0 : WWindow::OnSetFocus
extern "C" void NativeEntry_WWindow_OnSetFocus();
// Native entry @ 109119e6 : WWindow::OnCopyData
extern "C" void NativeEntry_WWindow_OnCopyData();
// Native entry @ 109119ec : WWindow::GetLength
extern "C" void NativeEntry_WWindow_GetLength();
// Native entry @ 109119f2 : WWindow::SetText
extern "C" void NativeEntry_WWindow_SetText();
// Native entry @ 109119f8 : WWindow::GetText
extern "C" void NativeEntry_WWindow_GetText();
// Native entry @ 109119fe : WWindow::InterceptControlCommand
extern "C" void NativeEntry_WWindow_InterceptControlCommand();
// Native entry @ 10911a04 : WDialog::CallDefaultProc
extern "C" void NativeEntry_WDialog_CallDefaultProc();
// Native entry @ 10911a0a : WWindow::WndProc
extern "C" void NativeEntry_WWindow_WndProc();
// Native entry @ 10911a10 : WWindow::DoDestroy
extern "C" void NativeEntry_WWindow_DoDestroy();
// Native entry @ 10911a16 : WWindow::Serialize
extern "C" void NativeEntry_WWindow_Serialize();
// Native entry @ 10911a1c : WDialog::Show
extern "C" void NativeEntry_WDialog_Show();
// Native entry @ 10911a22 : FCommandTarget::Unused
extern "C" void NativeEntry_FCommandTarget_Unused();
// Native entry @ 10911a28 : WWizardPage::OnCancel
extern "C" void NativeEntry_WWizardPage_OnCancel();
// Native entry @ 10911a2e : WWizardPage::GetShow
extern "C" void NativeEntry_WWizardPage_GetShow();
// Native entry @ 10911a34 : WWizardPage::GetCancelText
extern "C" void NativeEntry_WWizardPage_GetCancelText();
// Native entry @ 10911a3a : WWizardPage::GetFinishText
extern "C" void NativeEntry_WWizardPage_GetFinishText();
// Native entry @ 10911a40 : WWizardPage::GetBackText
extern "C" void NativeEntry_WWizardPage_GetBackText();
// Native entry @ 10911a46 : WWizardPage::OnCurrent
extern "C" void NativeEntry_WWizardPage_OnCurrent();
// Native entry @ 10911a4c : WWindow::OnDestroy
extern "C" void NativeEntry_WWindow_OnDestroy();
// Native entry @ 10911a52 : WWindow::OnClose
extern "C" void NativeEntry_WWindow_OnClose();
// Native entry @ 10911a58 : WDialog::OnInitDialog
extern "C" void NativeEntry_WDialog_OnInitDialog();
// Native entry @ 10911a5e : WConfigProperties::GetRoot
extern "C" void NativeEntry_WConfigProperties_GetRoot();
// Native entry @ 10911a64 : WConfigProperties::GetWindowClassName
extern "C" void NativeEntry_WConfigProperties_GetWindowClassName();
// Native entry @ 10911a6a : WConfigProperties::GetPackageName
extern "C" void NativeEntry_WConfigProperties_GetPackageName();
// Native entry @ 10911a70 : WWindow::Show
extern "C" void NativeEntry_WWindow_Show();
// Native entry @ 10911a76 : WProperties::SetValue
extern "C" void NativeEntry_WProperties_SetValue();
// Native entry @ 10911a7c : WProperties::BeginSplitterDrag
extern "C" void NativeEntry_WProperties_BeginSplitterDrag();
// Native entry @ 10911a82 : WProperties::ForceRefresh
extern "C" void NativeEntry_WProperties_ForceRefresh();
// Native entry @ 10911a88 : WProperties::SetItemFocus
extern "C" void NativeEntry_WProperties_SetItemFocus();
// Native entry @ 10911a8e : WProperties::ResizeList
extern "C" void NativeEntry_WProperties_ResizeList();
// Native entry @ 10911a94 : WProperties::GetDividerWidth
extern "C" void NativeEntry_WProperties_GetDividerWidth();
// Native entry @ 10911a9a : WObjectProperties::GetRoot
extern "C" void NativeEntry_WObjectProperties_GetRoot();
// Native entry @ 10911aa0 : WProperties::OnDestroy
extern "C" void NativeEntry_WProperties_OnDestroy();
// Native entry @ 10911aa6 : WProperties::OnSetCursor
extern "C" void NativeEntry_WProperties_OnSetCursor();
// Native entry @ 10911aac : WProperties::OnFinishSplitterDrag
extern "C" void NativeEntry_WProperties_OnFinishSplitterDrag();
// Native entry @ 10911ab2 : WWindow::OnInitDialog
extern "C" void NativeEntry_WWindow_OnInitDialog();
// Native entry @ 10911ab8 : WProperties::OnPaint
extern "C" void NativeEntry_WProperties_OnPaint();
// Native entry @ 10911abe : WProperties::OnActivate
extern "C" void NativeEntry_WProperties_OnActivate();
// Native entry @ 10911ac4 : WProperties::OnSize
extern "C" void NativeEntry_WProperties_OnSize();
// Native entry @ 10911aca : WWindow::CallDefaultProc
extern "C" void NativeEntry_WWindow_CallDefaultProc();
// Native entry @ 10911ad0 : WObjectProperties::GetWindowClassName
extern "C" void NativeEntry_WObjectProperties_GetWindowClassName();
// Native entry @ 10911ad6 : WProperties::DoDestroy
extern "C" void NativeEntry_WProperties_DoDestroy();
// Native entry @ 10911adc : WObjectProperties::GetPackageName
extern "C" void NativeEntry_WObjectProperties_GetPackageName();
// Native entry @ 10911ae2 : WProperties::Serialize
extern "C" void NativeEntry_WProperties_Serialize();
// Native entry @ 10911ae8 : WObjectProperties::Show
extern "C" void NativeEntry_WObjectProperties_Show();
// Native entry @ 10911aee : WWizardPage::GetNextText
extern "C" void NativeEntry_WWizardPage_GetNextText();
// Native entry @ 10911af4 : WWizardPage::GetNext
extern "C" void NativeEntry_WWizardPage_GetNext();
// Native entry @ 10911afa : WTerminal::Paste
extern "C" void NativeEntry_WTerminal_Paste();
// Native entry @ 10911b00 : WTerminal::TypeChar
extern "C" void NativeEntry_WTerminal_TypeChar();
// Native entry @ 10911b06 : WLog::OnDestroy
extern "C" void NativeEntry_WLog_OnDestroy();
// Native entry @ 10911b0c : WLog::OnClose
extern "C" void NativeEntry_WLog_OnClose();
// Native entry @ 10911b12 : WLog::OnCreate
extern "C" void NativeEntry_WLog_OnCreate();
// Native entry @ 10911b18 : WLog::OnShowWindow
extern "C" void NativeEntry_WLog_OnShowWindow();
// Native entry @ 10911b1e : WLog::OnCommand
extern "C" void NativeEntry_WLog_OnCommand();
// Native entry @ 10911b24 : WTerminal::OnSize
extern "C" void NativeEntry_WTerminal_OnSize();
// Native entry @ 10911b2a : WTerminal::OnSetFocus
extern "C" void NativeEntry_WTerminal_OnSetFocus();
// Native entry @ 10911b30 : WLog::OnCopyData
extern "C" void NativeEntry_WLog_OnCopyData();
// Native entry @ 10911b36 : WLog::SetText
extern "C" void NativeEntry_WLog_SetText();
// Native entry @ 10911b3c : WLog::WndProc
extern "C" void NativeEntry_WLog_WndProc();
// Native entry @ 10911b42 : WLog::GetWindowClassName
extern "C" void NativeEntry_WLog_GetWindowClassName();
// Native entry @ 10911b48 : WLog::GetPackageName
extern "C" void NativeEntry_WLog_GetPackageName();
// Native entry @ 10911b4e : FNotifyHook::NotifyExec
extern "C" void NativeEntry_FNotifyHook_NotifyExec();
// Native entry @ 10911b54 : FNotifyHook::NotifyPostChange
extern "C" void NativeEntry_FNotifyHook_NotifyPostChange();
// Native entry @ 10911b5a : FNotifyHook::NotifyPreChange
extern "C" void NativeEntry_FNotifyHook_NotifyPreChange();
// Native entry @ 10911b60 : FMalloc::GetMemoryBlockSize
extern "C" void NativeEntry_FMalloc_GetMemoryBlockSize();
// Native entry @ 10911b66 : FFileManager::Init
extern "C" void NativeEntry_FFileManager_Init();
// Native entry @ 10911b6c : FArchive::GetError
extern "C" void NativeEntry_FArchive_GetError();
// Native entry @ 10911b72 : FArchive::Flush
extern "C" void NativeEntry_FArchive_Flush();
// Native entry @ 10911b78 : FArchive::DetachLazyLoader
extern "C" void NativeEntry_FArchive_DetachLazyLoader();
// Native entry @ 10911b7e : FArchive::AttachLazyLoader
extern "C" void NativeEntry_FArchive_AttachLazyLoader();
// Native entry @ 10911b84 : FArchive::SetStopper
extern "C" void NativeEntry_FArchive_SetStopper();
// Native entry @ 10911b8a : FArchive::AtStopper
extern "C" void NativeEntry_FArchive_AtStopper();
// Native entry @ 10911b90 : FArchive::AtEnd
extern "C" void NativeEntry_FArchive_AtEnd();
// Native entry @ 10911b96 : FArchive::MapObject
extern "C" void NativeEntry_FArchive_MapObject();
// Native entry @ 10911b9c : FArchive::MapName
extern "C" void NativeEntry_FArchive_MapName();
// Native entry @ 10911ba2 : FArchive::operator<<(FName&)
extern "C" void NativeEntry_FArchive_Serialize_FName();
// Native entry @ 10911ba8 : FArchive::operator<<(UObject*&)
extern "C" void NativeEntry_FArchive_Serialize_UObject();
// Native entry @ 10911bae : FArchive::CountBytes
extern "C" void NativeEntry_FArchive_CountBytes();
// Native entry @ 10911bb4 : FArchive::Preload
extern "C" void NativeEntry_FArchive_Preload();
// Native entry @ 10911bba : FArchive::SerializeInt
extern "C" void NativeEntry_FArchive_SerializeInt();
// Native entry @ 10911bc0 : FArchive::SerializeBits
extern "C" void NativeEntry_FArchive_SerializeBits();
// Native entry @ 10911bc6 : FArchive::Precache
extern "C" void NativeEntry_FArchive_Precache();
// Native entry @ 10911bcc : FArchive::TotalSize
extern "C" void NativeEntry_FArchive_TotalSize();
// Native entry @ 10911c1d : type_info::VectorDeletingDestructor
extern "C" void NativeEntry_type_info_VectorDeletingDestructor();
// Native entry @ 10911c6e : ForwardExecutablePureCall
extern "C" void NativeEntry_ForwardExecutablePureCall();
// Native entry @ 10911eda : FilterExecutableVectorDestruction
extern "C" void NativeEntry_FilterExecutableVectorDestruction();
// Native entry @ 10911efe : ResumeExecutableVectorDestruction
extern "C" void NativeEntry_ResumeExecutableVectorDestruction();
// Native entry @ 10911f51 : FinishExecutableVectorDestruction
extern "C" void NativeEntry_FinishExecutableVectorDestruction();
// Native entry @ 10911f6a : type_info::~type_info
extern "C" void NativeEntry_type_info_Destroytype_info();
// Native entry @ 10912090 : UnwindStartupDialogBitmap
extern "C" void NativeEntry_UnwindStartupDialogBitmap();
// Native entry @ 109120b0 : UnwindConfigWizardBase
extern "C" void NativeEntry_UnwindConfigWizardBase();
// Native entry @ 109120b9 : UnwindConfigWizardLabel
extern "C" void NativeEntry_UnwindConfigWizardLabel();
// Native entry @ 109120c8 : UnwindConfigWizardBitmap
extern "C" void NativeEntry_UnwindConfigWizardBitmap();
// Native entry @ 109120d7 : UnwindConfigWizardTitle
extern "C" void NativeEntry_UnwindConfigWizardTitle();
// Native entry @ 10912100 : UnwindSafeOptionsConstructionBase
extern "C" void NativeEntry_UnwindSafeOptionsConstructionBase();
// Native entry @ 10912109 : UnwindSafeOptionsConstructionOption454
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption454();
// Native entry @ 10912115 : UnwindSafeOptionsConstructionOption455
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption455();
// Native entry @ 10912124 : UnwindSafeOptionsConstructionOption456
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption456();
// Native entry @ 10912133 : UnwindSafeOptionsConstructionOption458
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption458();
// Native entry @ 10912142 : UnwindSafeOptionsConstructionOption457
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption457();
// Native entry @ 10912151 : UnwindSafeOptionsConstructionOption459
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption459();
// Native entry @ 10912160 : UnwindSafeOptionsConstructionOption45a
extern "C" void NativeEntry_UnwindSafeOptionsConstructionOption45a();
// Native entry @ 10912180 : UnwindSafeOptionsNextCommandLine
extern "C" void NativeEntry_UnwindSafeOptionsNextCommandLine();
// Native entry @ 10912189 : UnwindSafeOptionsNextPackageName
extern "C" void NativeEntry_UnwindSafeOptionsNextPackageName();
// Native entry @ 10912192 : UnwindSafeOptionsNextIniName
extern "C" void NativeEntry_UnwindSafeOptionsNextIniName();
// Native entry @ 109121e0 : DestroyErrorCrashDialogOnUnwind
extern "C" void NativeEntry_DestroyErrorCrashDialogOnUnwind();
// Native entry @ 109122a0 : UnwindSafeOptionsDestructionBase
extern "C" void NativeEntry_UnwindSafeOptionsDestructionBase();
// Native entry @ 109122a9 : UnwindSafeOptionsDestructionOption454
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption454();
// Native entry @ 109122b5 : UnwindSafeOptionsDestructionOption455
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption455();
// Native entry @ 109122c4 : UnwindSafeOptionsDestructionOption456
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption456();
// Native entry @ 109122d3 : UnwindSafeOptionsDestructionOption458
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption458();
// Native entry @ 109122e2 : UnwindSafeOptionsDestructionOption457
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption457();
// Native entry @ 109122f1 : UnwindSafeOptionsDestructionOption459
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption459();
// Native entry @ 10912300 : UnwindSafeOptionsDestructionOption45a
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption45a();
// Native entry @ 1091230f : UnwindSafeOptionsDestructionOption45b
extern "C" void NativeEntry_UnwindSafeOptionsDestructionOption45b();
// Native entry @ 10912370 : DestroyFeedbackMapCheckPacketOnUnwind
extern "C" void NativeEntry_DestroyFeedbackMapCheckPacketOnUnwind();
// Native entry @ 109123d0 : DestroyFileReaderBaseOnUnwind
extern "C" void NativeEntry_DestroyFileReaderBaseOnUnwind();
// Native entry @ 10912470 : DestroyFileReaderBaseAfterDestructorFailure
extern "C" void NativeEntry_DestroyFileReaderBaseAfterDestructorFailure();
// Native entry @ 10912490 : DestroyFileWriterBaseAfterDestructorFailure
extern "C" void NativeEntry_DestroyFileWriterBaseAfterDestructorFailure();
// Native entry @ 109124c0 : UnwindRendererCaption
extern "C" void NativeEntry_UnwindRendererCaption();
// Native entry @ 109124c9 : UnwindRendererClassPath
extern "C" void NativeEntry_UnwindRendererClassPath();
// Native entry @ 109124d2 : UnwindRendererPackage
extern "C" void NativeEntry_UnwindRendererPackage();
// Native entry @ 109124db : UnwindRendererClass
extern "C" void NativeEntry_UnwindRendererClass();
// Native entry @ 109124e4 : UnwindRendererUnused
extern "C" void NativeEntry_UnwindRendererUnused();
// Native entry @ 109124ed : UnwindRendererSeparator
extern "C" void NativeEntry_UnwindRendererSeparator();
// Native entry @ 10912500 : UnwindWizardCallbackString
extern "C" void NativeEntry_UnwindWizardCallbackString();
// Native entry @ 10912520 : FreeExecHookObjectPropertiesStorage
extern "C" void NativeEntry_FreeExecHookObjectPropertiesStorage();
// Native entry @ 1091252e : DestroyExecHookExportString
extern "C" void NativeEntry_DestroyExecHookExportString();
// Native entry @ 10912539 : FreeExecHookConfigPropertiesStorage
extern "C" void NativeEntry_FreeExecHookConfigPropertiesStorage();
// Native entry @ 10912560 : DestroySaveDirtyPackagesCommand
extern "C" void NativeEntry_DestroySaveDirtyPackagesCommand();
// Native entry @ 10912580 : DestroyMainLoopRecords
extern "C" void NativeEntry_DestroyMainLoopRecords();
// Native entry @ 10912588 : DestroyMainLoopReport
extern "C" void NativeEntry_DestroyMainLoopReport();
// Native entry @ 10912594 : DestroyMainLoopSummary
extern "C" void NativeEntry_DestroyMainLoopSummary();
// Native entry @ 109125b0 : UnwindRecursiveDeletePatternBase
extern "C" void NativeEntry_UnwindRecursiveDeletePatternBase();
// Native entry @ 109125b9 : UnwindRecursiveDeletePattern
extern "C" void NativeEntry_UnwindRecursiveDeletePattern();
// Native entry @ 109125c2 : UnwindRecursiveDeleteList
extern "C" void NativeEntry_UnwindRecursiveDeleteList();
// Native entry @ 109125ca : UnwindRecursiveDeleteFileBase
extern "C" void NativeEntry_UnwindRecursiveDeleteFileBase();
// Native entry @ 109125d3 : UnwindRecursiveDeleteFilePath
extern "C" void NativeEntry_UnwindRecursiveDeleteFilePath();
// Native entry @ 109125dc : UnwindRecursiveDeleteReplacementList
extern "C" void NativeEntry_UnwindRecursiveDeleteReplacementList();
// Native entry @ 109125e4 : UnwindRecursiveDeleteDirectoryBase
extern "C" void NativeEntry_UnwindRecursiveDeleteDirectoryBase();
// Native entry @ 109125ed : UnwindRecursiveDeleteDirectoryPath
extern "C" void NativeEntry_UnwindRecursiveDeleteDirectoryPath();
// Native entry @ 10912620 : UnwindFindFilesList
extern "C" void NativeEntry_UnwindFindFilesList();
// Native entry @ 10912628 : UnwindFindFilesResult
extern "C" void NativeEntry_UnwindFindFilesResult();
// Native entry @ 10912660 : UnwindArrayBase
extern "C" void NativeEntry_UnwindArrayBase();
// Native entry @ 10912680 : UnwindRendererRefreshBestCaption
extern "C" void NativeEntry_UnwindRendererRefreshBestCaption();
// Native entry @ 10912689 : UnwindRendererRefreshClassPath
extern "C" void NativeEntry_UnwindRendererRefreshClassPath();
// Native entry @ 10912692 : UnwindRendererRefreshPackage
extern "C" void NativeEntry_UnwindRendererRefreshPackage();
// Native entry @ 1091269b : UnwindRendererRefreshClass
extern "C" void NativeEntry_UnwindRendererRefreshClass();
// Native entry @ 109126a4 : UnwindRendererRefreshCaption
extern "C" void NativeEntry_UnwindRendererRefreshCaption();
// Native entry @ 109126ad : UnwindRendererRefreshSeparator
extern "C" void NativeEntry_UnwindRendererRefreshSeparator();
// Native entry @ 109126b6 : UnwindRendererRefreshSystemProbe
extern "C" void NativeEntry_UnwindRendererRefreshSystemProbe();
// Native entry @ 109126d9 : UnwindRendererRefreshWindowsProbe
extern "C" void NativeEntry_UnwindRendererRefreshWindowsProbe();
// Native entry @ 10912710 : UnwindFStringMapPairs
extern "C" void NativeEntry_UnwindFStringMapPairs();
// Native entry @ 10912730 : UnwindRendererPageConstructionBase
extern "C" void NativeEntry_UnwindRendererPageConstructionBase();
// Native entry @ 10912739 : UnwindRendererPageConstructionList
extern "C" void NativeEntry_UnwindRendererPageConstructionList();
// Native entry @ 10912745 : UnwindRendererPageConstructionChoice455
extern "C" void NativeEntry_UnwindRendererPageConstructionChoice455();
// Native entry @ 10912754 : UnwindRendererPageConstructionChoice456
extern "C" void NativeEntry_UnwindRendererPageConstructionChoice456();
// Native entry @ 10912763 : UnwindRendererPageConstructionLabel
extern "C" void NativeEntry_UnwindRendererPageConstructionLabel();
// Native entry @ 10912790 : UnwindRendererNextNonemptyTest
extern "C" void NativeEntry_UnwindRendererNextNonemptyTest();
// Native entry @ 10912799 : UnwindRendererNextConfigValue
extern "C" void NativeEntry_UnwindRendererNextConfigValue();
// Native entry @ 109127a2 : UnwindRendererNextDirect3DTest
extern "C" void NativeEntry_UnwindRendererNextDirect3DTest();
// Native entry @ 109127ab : UnwindRendererNextDriverAllocation
extern "C" void NativeEntry_UnwindRendererNextDriverAllocation();
// Native entry @ 109127b6 : UnwindRendererNextDetailAllocation
extern "C" void NativeEntry_UnwindRendererNextDetailAllocation();
// Native entry @ 109127d0 : UnwindWizardPageBase
extern "C" void NativeEntry_UnwindWizardPageBase();
// Native entry @ 109127f0 : UnwindDetailInitSummary
extern "C" void NativeEntry_UnwindDetailInitSummary();
// Native entry @ 109127f9 : UnwindDetailInitRenderer
extern "C" void NativeEntry_UnwindDetailInitRenderer();
// Native entry @ 10912802 : UnwindDetailInitSoundLowText
extern "C" void NativeEntry_UnwindDetailInitSoundLowText();
// Native entry @ 1091280b : UnwindDetailInitSoundLowLine
extern "C" void NativeEntry_UnwindDetailInitSoundLowLine();
// Native entry @ 10912814 : UnwindDetailInitSoundHighText
extern "C" void NativeEntry_UnwindDetailInitSoundHighText();
// Native entry @ 1091281d : UnwindDetailInitSoundHighLine
extern "C" void NativeEntry_UnwindDetailInitSoundHighLine();
// Native entry @ 10912826 : UnwindDetailInitSkinsLowText
extern "C" void NativeEntry_UnwindDetailInitSkinsLowText();
// Native entry @ 1091282f : UnwindDetailInitSkinsLowLine
extern "C" void NativeEntry_UnwindDetailInitSkinsLowLine();
// Native entry @ 10912838 : UnwindDetailInitSkinsHighText
extern "C" void NativeEntry_UnwindDetailInitSkinsHighText();
// Native entry @ 10912841 : UnwindDetailInitSkinsHighLine
extern "C" void NativeEntry_UnwindDetailInitSkinsHighLine();
// Native entry @ 1091284d : UnwindDetailInitWorldLowText
extern "C" void NativeEntry_UnwindDetailInitWorldLowText();
// Native entry @ 10912859 : UnwindDetailInitWorldLowLine
extern "C" void NativeEntry_UnwindDetailInitWorldLowLine();
// Native entry @ 10912865 : UnwindDetailInitWorldHighText
extern "C" void NativeEntry_UnwindDetailInitWorldHighText();
// Native entry @ 10912871 : UnwindDetailInitWorldHighLine
extern "C" void NativeEntry_UnwindDetailInitWorldHighLine();
// Native entry @ 1091287d : UnwindDetailInitSoftwareResolutionText
extern "C" void NativeEntry_UnwindDetailInitSoftwareResolutionText();
// Native entry @ 10912889 : UnwindDetailInitSoftwareResolutionLine
extern "C" void NativeEntry_UnwindDetailInitSoftwareResolutionLine();
// Native entry @ 10912895 : UnwindDetailInitFallbackResolutionText
extern "C" void NativeEntry_UnwindDetailInitFallbackResolutionText();
// Native entry @ 109128a1 : UnwindDetailInitFallbackResolutionLine
extern "C" void NativeEntry_UnwindDetailInitFallbackResolutionLine();
// Native entry @ 109128ad : UnwindDetailInitHighResolutionText
extern "C" void NativeEntry_UnwindDetailInitHighResolutionText();
// Native entry @ 109128b9 : UnwindDetailInitHighResolutionLine
extern "C" void NativeEntry_UnwindDetailInitHighResolutionLine();
// Native entry @ 109128d0 : UnwindWizardPageAllocation
extern "C" void NativeEntry_UnwindWizardPageAllocation();
// Native entry @ 109128f0 : UnwindDetailPageDestructionBase
extern "C" void NativeEntry_UnwindDetailPageDestructionBase();
// Native entry @ 109128f9 : UnwindDetailPageDestructionEdit
extern "C" void NativeEntry_UnwindDetailPageDestructionEdit();
// Native entry @ 10912910 : UnwindDriverPageConstructionBase
extern "C" void NativeEntry_UnwindDriverPageConstructionBase();
// Native entry @ 10912919 : UnwindDriverPageConstructionLink
extern "C" void NativeEntry_UnwindDriverPageConstructionLink();
// Native entry @ 10912930 : UnwindDriverPageDestructionBase
extern "C" void NativeEntry_UnwindDriverPageDestructionBase();
// Native entry @ 10912939 : UnwindDriverPageDestructionLink
extern "C" void NativeEntry_UnwindDriverPageDestructionLink();
// Native entry @ 10912945 : UnwindDriverPageDestructionLabel
extern "C" void NativeEntry_UnwindDriverPageDestructionLabel();
// Native entry @ 10912960 : UnwindRendererPageDestructionBase
extern "C" void NativeEntry_UnwindRendererPageDestructionBase();
// Native entry @ 10912969 : UnwindRendererPageDestructionList
extern "C" void NativeEntry_UnwindRendererPageDestructionList();
// Native entry @ 10912975 : UnwindRendererPageDestructionChoice455
extern "C" void NativeEntry_UnwindRendererPageDestructionChoice455();
// Native entry @ 10912984 : UnwindRendererPageDestructionChoice456
extern "C" void NativeEntry_UnwindRendererPageDestructionChoice456();
// Native entry @ 10912993 : UnwindRendererPageDestructionLabel
extern "C" void NativeEntry_UnwindRendererPageDestructionLabel();
// Native entry @ 109129a2 : UnwindRendererPageDestructionRecords
extern "C" void NativeEntry_UnwindRendererPageDestructionRecords();
// Native entry @ 109129c0 : UnwindSafeModePageBase
extern "C" void NativeEntry_UnwindSafeModePageBase();
// Native entry @ 109129c9 : UnwindSafeModePageRunButton
extern "C" void NativeEntry_UnwindSafeModePageRunButton();
// Native entry @ 109129d5 : UnwindSafeModePageRendererButton
extern "C" void NativeEntry_UnwindSafeModePageRendererButton();
// Native entry @ 109129e4 : UnwindSafeModePageSafeOptionsButton
extern "C" void NativeEntry_UnwindSafeModePageSafeOptionsButton();
// Native entry @ 10912a00 : UnwindSafeModePageDestructionBase
extern "C" void NativeEntry_UnwindSafeModePageDestructionBase();
// Native entry @ 10912a09 : UnwindSafeModePageDestructionRunButton
extern "C" void NativeEntry_UnwindSafeModePageDestructionRunButton();
// Native entry @ 10912a15 : UnwindSafeModePageDestructionRendererButton
extern "C" void NativeEntry_UnwindSafeModePageDestructionRendererButton();
// Native entry @ 10912a24 : UnwindSafeModePageDestructionSafeOptionsButton
extern "C" void NativeEntry_UnwindSafeModePageDestructionSafeOptionsButton();
// Native entry @ 10912a33 : UnwindSafeModePageDestructionWebButton
extern "C" void NativeEntry_UnwindSafeModePageDestructionWebButton();
// Native entry @ 10912a50 : DestroyInitEngineSaveFiles
extern "C" void NativeEntry_DestroyInitEngineSaveFiles();
// Native entry @ 10912a58 : DestroyInitEngineSlotSection
extern "C" void NativeEntry_DestroyInitEngineSlotSection();
// Native entry @ 10912a61 : DestroyInitEngineSlotKey
extern "C" void NativeEntry_DestroyInitEngineSlotKey();
// Native entry @ 10912a6a : DestroyInitEngineConsoleCommand
extern "C" void NativeEntry_DestroyInitEngineConsoleCommand();
// Native entry @ 10912a73 : DestroyInitEngineRenderName
extern "C" void NativeEntry_DestroyInitEngineRenderName();
// Native entry @ 10912a7c : DestroyInitEngineWizard
extern "C" void NativeEntry_DestroyInitEngineWizard();
// Native entry @ 10912a87 : FreeInitEngineSafePageStorage
extern "C" void NativeEntry_FreeInitEngineSafePageStorage();
// Native entry @ 10912a95 : FreeInitEngineRendererPageStorage
extern "C" void NativeEntry_FreeInitEngineRendererPageStorage();
// Native entry @ 10912ab0 : UnwindConfigMapPairs
extern "C" void NativeEntry_UnwindConfigMapPairs();
// Native entry @ 10912ad0 : UnwindConfigCacheBase
extern "C" void NativeEntry_UnwindConfigCacheBase();
// Native entry @ 10912ad8 : UnwindConfigCachePairs
extern "C" void NativeEntry_UnwindConfigCachePairs();
// Native entry @ 10912ae0 : UnwindConfigCacheMap
extern "C" void NativeEntry_UnwindConfigCacheMap();
// Native entry @ 10912aeb : UnwindConfigCacheSystemIni
extern "C" void NativeEntry_UnwindConfigCacheSystemIni();
// Native entry @ 10912af7 : UnwindConfigCacheUserIni
extern "C" void NativeEntry_UnwindConfigCacheUserIni();
// Native entry @ 10912b03 : UnwindConfigCacheString30
extern "C" void NativeEntry_UnwindConfigCacheString30();
// Native entry @ 10912c20 : UnwindConfigCachePBfindKeyIterator
extern "C" void NativeEntry_UnwindConfigCachePBfindKeyIterator();
// Native entry @ 10912c28 : UnwindConfigCachePBfindKeySectionKey
extern "C" void NativeEntry_UnwindConfigCachePBfindKeySectionKey();
// Native entry @ 10912c31 : UnwindConfigCachePBfindKeyEntryKey
extern "C" void NativeEntry_UnwindConfigCachePBfindKeyEntryKey();
// Native entry @ 10912c50 : ResetPBgetSectionInitialization
extern "C" void NativeEntry_ResetPBgetSectionInitialization();
// Native entry @ 10912c5e : UnwindPBgetSectionInitialKey
extern "C" void NativeEntry_UnwindPBgetSectionInitialKey();
// Native entry @ 10912c67 : UnwindPBgetSectionRepeatedKey
extern "C" void NativeEntry_UnwindPBgetSectionRepeatedKey();
// Native entry @ 10912c80 : UnwindConfigCacheFlushIterator
extern "C" void NativeEntry_UnwindConfigCacheFlushIterator();
// Native entry @ 10912ca0 : UnwindConfigFileWriteText
extern "C" void NativeEntry_UnwindConfigFileWriteText();
// Native entry @ 10912ca9 : UnwindConfigFileWriteSectionIterator
extern "C" void NativeEntry_UnwindConfigFileWriteSectionIterator();
// Native entry @ 10912cb1 : UnwindConfigFileWriteSectionText
extern "C" void NativeEntry_UnwindConfigFileWriteSectionText();
// Native entry @ 10912cba : UnwindConfigFileWriteEntryIterator
extern "C" void NativeEntry_UnwindConfigFileWriteEntryIterator();
// Native entry @ 10912cc2 : UnwindConfigFileWriteEntryText
extern "C" void NativeEntry_UnwindConfigFileWriteEntryText();
// Native entry @ 10912ccb : UnwindConfigFileWriteSectionBreak
extern "C" void NativeEntry_UnwindConfigFileWriteSectionBreak();
// Native entry @ 10912cf0 : UnwindConfigCacheFindTranslatedName
extern "C" void NativeEntry_UnwindConfigCacheFindTranslatedName();
// Native entry @ 10912cf9 : UnwindConfigCacheFindKey
extern "C" void NativeEntry_UnwindConfigCacheFindKey();
// Native entry @ 10912d02 : UnwindConfigCacheFindEmptyFile
extern "C" void NativeEntry_UnwindConfigCacheFindEmptyFile();
// Native entry @ 10912d20 : UnwindConfigFileReadText
extern "C" void NativeEntry_UnwindConfigFileReadText();
// Native entry @ 10912d29 : UnwindConfigFileReadSectionKey
extern "C" void NativeEntry_UnwindConfigFileReadSectionKey();
// Native entry @ 10912d32 : UnwindConfigFileReadPartialSectionPairs
extern "C" void NativeEntry_UnwindConfigFileReadPartialSectionPairs();
// Native entry @ 10912d3a : UnwindConfigFileReadSection
extern "C" void NativeEntry_UnwindConfigFileReadSection();
// Native entry @ 10912d42 : UnwindConfigFileReadSectionPairs
extern "C" void NativeEntry_UnwindConfigFileReadSectionPairs();
// Native entry @ 10912d4a : UnwindConfigFileReadSectionArrayBase
extern "C" void NativeEntry_UnwindConfigFileReadSectionArrayBase();
// Native entry @ 10912d60 : UnwindMapPairStringKey
extern "C" void NativeEntry_UnwindMapPairStringKey();
// Native entry @ 10912d80 : UnwindCopiedConfigSectionPairKey
extern "C" void NativeEntry_UnwindCopiedConfigSectionPairKey();
// Native entry @ 10912d8c : UnwindCopiedConfigSectionEntries
extern "C" void NativeEntry_UnwindCopiedConfigSectionEntries();
// Native entry @ 10912da0 : UnwindFConfigSectionMapPairs
extern "C" void NativeEntry_UnwindFConfigSectionMapPairs();
// Native entry @ 10912dc0 : UnwindConfigCacheBufferGetStringSectionKey
extern "C" void NativeEntry_UnwindConfigCacheBufferGetStringSectionKey();
// Native entry @ 10912dc9 : UnwindConfigCacheBufferGetStringEntryKey
extern "C" void NativeEntry_UnwindConfigCacheBufferGetStringEntryKey();
// Native entry @ 10912de0 : UnwindConfigCacheGetSectionKey
extern "C" void NativeEntry_UnwindConfigCacheGetSectionKey();
// Native entry @ 10912de9 : UnwindConfigCacheGetSectionIterator
extern "C" void NativeEntry_UnwindConfigCacheGetSectionIterator();
// Native entry @ 10912e00 : UnwindConfigCacheGetSectionPrivateKey
extern "C" void NativeEntry_UnwindConfigCacheGetSectionPrivateKey();
// Native entry @ 10912e09 : UnwindConfigCacheGetSectionPrivatePairs
extern "C" void NativeEntry_UnwindConfigCacheGetSectionPrivatePairs();
// Native entry @ 10912e11 : UnwindConfigCacheGetSectionPrivateMap
extern "C" void NativeEntry_UnwindConfigCacheGetSectionPrivateMap();
// Native entry @ 10912e30 : UnwindConfigCacheSetStringSectionKey
extern "C" void NativeEntry_UnwindConfigCacheSetStringSectionKey();
// Native entry @ 10912e39 : UnwindConfigCacheSetStringSection
extern "C" void NativeEntry_UnwindConfigCacheSetStringSection();
// Native entry @ 10912e41 : UnwindConfigCacheSetStringEntryKey
extern "C" void NativeEntry_UnwindConfigCacheSetStringEntryKey();
// Native entry @ 10912e60 : UnwindConfigCacheEmptySectionKey
extern "C" void NativeEntry_UnwindConfigCacheEmptySectionKey();
// Native entry @ 10912e69 : UnwindConfigCacheEmptySectionIterator
extern "C" void NativeEntry_UnwindConfigCacheEmptySectionIterator();
// Native entry @ 10912e90 : FreeFailedConfigCacheAllocation
extern "C" void NativeEntry_FreeFailedConfigCacheAllocation();
// Native entry @ 10912eb0 : UnwindDestroyedConfigCacheBase
extern "C" void NativeEntry_UnwindDestroyedConfigCacheBase();
// Native entry @ 10912eb8 : UnwindDestroyedConfigCacheMap
extern "C" void NativeEntry_UnwindDestroyedConfigCacheMap();
// Native entry @ 10912edf : UnwindDestroyedConfigCacheSystemIni
extern "C" void NativeEntry_UnwindDestroyedConfigCacheSystemIni();
// Native entry @ 10912eeb : UnwindDestroyedConfigCacheUserIni
extern "C" void NativeEntry_UnwindDestroyedConfigCacheUserIni();
// Native entry @ 10912ef7 : UnwindDestroyedConfigCacheString30
extern "C" void NativeEntry_UnwindDestroyedConfigCacheString30();
// Native entry @ 10912f03 : UnwindDestroyedConfigCacheString3c
extern "C" void NativeEntry_UnwindDestroyedConfigCacheString3c();
// Native entry @ 10912f20 : DestroyWinMainHelpDirectory
extern "C" void NativeEntry_DestroyWinMainHelpDirectory();
// Native entry @ 10912f29 : DestroyWinMainPackageLogoPath
extern "C" void NativeEntry_DestroyWinMainPackageLogoPath();
// Native entry @ 10912f32 : DestroyWinMainLogo
extern "C" void NativeEntry_DestroyWinMainLogo();
// Native entry @ 10912f3b : FreeWinMainLogStorage
extern "C" void NativeEntry_FreeWinMainLogStorage();
// Native entry @ 10912f46 : DestroyWinMainWidth
extern "C" void NativeEntry_DestroyWinMainWidth();
// Native entry @ 10912f4f : DestroyWinMainHeight
extern "C" void NativeEntry_DestroyWinMainHeight();
// Native entry @ 10912f58 : DestroyWinMainExecCommand
extern "C" void NativeEntry_DestroyWinMainExecCommand();
// Native entry @ 10912f61 : DestroyWinMainExecPrefix
extern "C" void NativeEntry_DestroyWinMainExecPrefix();
// Native entry @ 10912f6a : DestroyWinMainExecConcatenation
extern "C" void NativeEntry_DestroyWinMainExecConcatenation();

// Each imported slot stores a provider address; it is not the provider object or a guessed callable prototype.
// Native import @ 10914000 : Core.dll; public: __thiscall FArray::FArray(void)
extern "C" void *NativeImport_FArrayConstructEmpty;
// Native import @ 10914004 : Core.dll; public: virtual void __thiscall FArchive::Precache(int)
extern "C" void *NativeImport_FArchive_Precache;
// Native import @ 10914008 : Core.dll; public: __thiscall FArchive::FArchive(void)
extern "C" void *NativeImport_FArchiveConstruct;
// Native import @ 1091400c : Core.dll; public: virtual __thiscall FArchive::~FArchive(void)
extern "C" void *NativeImport_FArchiveDestroy;
// Native import @ 10914010 : Core.dll; public: virtual void __thiscall FArchive::SerializeBits(void *, int)
extern "C" void *NativeImport_FArchive_SerializeBits;
// Native import @ 10914014 : Core.dll; public: virtual void __thiscall FArchive::SerializeInt(unsigned long &, unsigned
// long)
extern "C" void *NativeImport_FArchive_SerializeInt;
// Native import @ 10914018 : Core.dll; public: virtual void __thiscall FArchive::Preload(class UObject *)
extern "C" void *NativeImport_FArchive_Preload;
// Native import @ 1091401c : Core.dll; public: virtual void __thiscall FArchive::CountBytes(unsigned long, unsigned
// long)
extern "C" void *NativeImport_FArchive_CountBytes;
// Native import @ 10914020 : Core.dll; public: virtual class FArchive & __thiscall FArchive::operator<<(class UObject
// *&)
extern "C" void *NativeImport_FArchiveSerializeObject;
// Native import @ 10914024 : Core.dll; public: virtual class FArchive & __thiscall FArchive::operator<<(class FName &)
extern "C" void *NativeImport_FArchiveSerializeName;
// Native import @ 10914028 : Core.dll; public: virtual int __thiscall FArchive::MapName(class FName *)
extern "C" void *NativeImport_FArchive_MapName;
// Native import @ 1091402c : Core.dll; public: virtual int __thiscall FArchive::MapObject(class UObject *)
extern "C" void *NativeImport_FArchive_MapObject;
// Native import @ 10914030 : Core.dll; public: virtual int __thiscall FArchive::AtEnd(void)
extern "C" void *NativeImport_FArchive_AtEnd;
// Native import @ 10914034 : Core.dll; public: virtual int __thiscall FArchive::AtStopper(void)
extern "C" void *NativeImport_FArchive_AtStopper;
// Native import @ 10914038 : Core.dll; public: virtual void __thiscall FArchive::SetStopper(int)
extern "C" void *NativeImport_FArchive_SetStopper;
// Native import @ 1091403c : Core.dll; public: virtual void __thiscall FArchive::AttachLazyLoader(class FLazyLoader *)
extern "C" void *NativeImport_FArchive_AttachLazyLoader;
// Native import @ 10914040 : Core.dll; public: virtual void __thiscall FArchive::DetachLazyLoader(class FLazyLoader *)
extern "C" void *NativeImport_FArchive_DetachLazyLoader;
// Native import @ 10914044 : Core.dll; public: virtual void __thiscall FArchive::Flush(void)
extern "C" void *NativeImport_FArchive_Flush;
// Native import @ 10914048 : Core.dll; public: virtual int __thiscall FArchive::GetError(void)
extern "C" void *NativeImport_FArchive_GetError;
// Native import @ 10914050 : Core.dll; public: int __thiscall FArchive::IsError(void)
extern "C" void *NativeImport_FArchive_IsError;
// Native import @ 10914060 : Core.dll; public: int __thiscall UObject::IsA(class UClass *) const
extern "C" void *NativeImport_UObject_IsA;
// Native import @ 10914064 : Core.dll; public: int __thiscall FArray::Add(int, int)
extern "C" void *NativeImport_FArray_Add;
// Native import @ 10914068 : Core.dll; public: int __thiscall UStruct::IsChildOf(class UStruct const *) const
extern "C" void *NativeImport_UStruct_IsChildOf;
// Native import @ 1091406c : Core.dll; public: static class UPackage * __cdecl UObject::GetTransientPackage(void)
extern "C" void *NativeImport_UObject_GetTransientPackage;
// Native import @ 10914070 : Core.dll; public: static class UObject * __cdecl UObject::StaticConstructObject(class
// UClass *, class UObject *, class FName, unsigned long, class UObject *, class FOutputDevice *, int)
extern "C" void *NativeImport_UObject_StaticConstructObject;
// Native import @ 10914074 : Core.dll; public: static class UClass * __cdecl UObject::StaticLoadClass(class UClass *,
// class UObject *, unsigned short const *, unsigned short const *, unsigned long, class UPackageMap *)
extern "C" void *NativeImport_UObject_StaticLoadClass;
// Native import @ 1091407c : Core.dll; public: __thiscall FFileManager::FFileManager(void)
extern "C" void *NativeImport_FFileManagerConstruct;
// Native import @ 10914080 : Core.dll; public: virtual void __thiscall FFileManager::Init(int)
extern "C" void *NativeImport_FFileManager_Init;
// Native import @ 109140ac : Core.dll; class FOutputDevice *GLog
extern "C" void *NativeImport_GLog;
// Native import @ 109140cc : Core.dll; public: __thiscall FOutputDeviceError::FOutputDeviceError(void)
extern "C" void *NativeImport_FOutputDeviceErrorConstruct;
// Native import @ 109140f4 : Core.dll; public: void __cdecl FOutputDevice::Logf(enum EName, unsigned short const *,
// ...)
extern "C" void *NativeImport_FOutputDeviceLogfEvent;
// Native import @ 109140f8 : Core.dll; public: __thiscall FOutputDevice::FOutputDevice(void)
extern "C" void *NativeImport_FOutputDeviceConstruct;
// Native import @ 10914104 : Core.dll; private: static class TArray<class UObject *> UObject::GObjObjects
extern "C" void *NativeImport_UObject_GObjObjects;
// Native import @ 10914108 : Core.dll; public: int __thiscall FArray::Num(void) const
extern "C" void *NativeImport_FArray_Num;
// Native import @ 10914110 : Core.dll; public: virtual int __thiscall FMalloc::GetMemoryBlockSize(void *)
extern "C" void *NativeImport_FMalloc_GetMemoryBlockSize;
// Native import @ 10914114 : Core.dll; public: __thiscall FExec::FExec(void)
extern "C" void *NativeImport_FExecConstruct;
// Native import @ 10914118 : Core.dll; public: __thiscall FNotifyHook::FNotifyHook(void)
extern "C" void *NativeImport_FNotifyHookConstruct;
// Native import @ 1091411c : Core.dll; public: virtual void __thiscall FNotifyHook::NotifyPreChange(void *)
extern "C" void *NativeImport_FNotifyHook_NotifyPreChange;
// Native import @ 10914120 : Core.dll; public: virtual void __thiscall FNotifyHook::NotifyPostChange(void *)
extern "C" void *NativeImport_FNotifyHook_NotifyPostChange;
// Native import @ 10914124 : Core.dll; public: virtual void __thiscall FNotifyHook::NotifyExec(void *, unsigned short
// const *)
extern "C" void *NativeImport_FNotifyHook_NotifyExec;
// Native import @ 10914128 : Core.dll; class FMalloc *GMalloc
extern "C" void *NativeImport_GMalloc;
// Native import @ 10914130 : Core.dll; public: class FString & __thiscall FString::operator+=(unsigned short const *)
extern "C" void *NativeImport_FStringAppendText;
// Native import @ 10914138 : Core.dll; public: __thiscall FString::FString(unsigned short const *)
extern "C" void *NativeImport_FStringConstructText;
// Native import @ 10914150 : Core.dll; unsigned short const * __cdecl LocalizeGeneral(unsigned short const *, unsigned
// short const *, unsigned short const *)
extern "C" void *NativeImport_LocalizeGeneralWide;
// Native import @ 10914154 : Core.dll; double GSecondsPerCycle
extern "C" void *NativeImport_GSecondsPerCycle;
// Native import @ 10914158 : Core.dll; public: unsigned short const * __thiscall FString::operator*(void) const
extern "C" void *NativeImport_FStringGetText;
// Native import @ 10914164 : Core.dll; public: __thiscall FString::~FString(void)
extern "C" void *NativeImport_FStringDestroy;
// Native import @ 1091417c : Core.dll; int __cdecl IsRavenShieldCDInDrive(void)
extern "C" void *NativeImport_IsRavenShieldCDInDrive;
// Native import @ 10914180 : Core.dll; unsigned short const * __cdecl Localize(unsigned short const *, unsigned short
// const *, unsigned short const *, unsigned short const *, int, int)
extern "C" void *NativeImport_Localize;
// Native import @ 10914184 : Core.dll; int GIsErrorNotABug
extern "C" void *NativeImport_GIsErrorNotABug;
// Native import @ 10914188 : Core.dll; class FOutputDeviceError *GError
extern "C" void *NativeImport_GError;
// Native import @ 1091418c : Core.dll; void __cdecl appInit(unsigned short const *, unsigned short const *, class
// FMalloc *, class FOutputDevice *, class FOutputDeviceError *, class FFeedbackContext *, class FFileManager *, class
// FConfigCache * (__cdecl *)(void), int)
extern "C" void *NativeImport_appInit;
// Native import @ 1091419c : Core.dll; public: void __thiscall FOutputDevice::Log(enum EName, unsigned short const *)
extern "C" void *NativeImport_FOutputDeviceLogEvent;
// Native import @ 109141c8 : Core.dll; public: __thiscall FName::FName(enum EName)
extern "C" void *NativeImport_FNameConstructEnum;
// Native import @ 1091421c : Core.dll; public: class UObject * __thiscall UObject::GetOuter(void) const
extern "C" void *NativeImport_UObject_GetOuter;
// Native import @ 10914220 : Core.dll; int __cdecl appStrcmp(unsigned short const *, unsigned short const *)
extern "C" void *NativeImport_appStrcmp;
// Native import @ 10914224 : Core.dll; int const __cdecl appMsgf(int, unsigned short const *, ...)
extern "C" void *NativeImport_appMsgf;
// Native import @ 1091422c : Core.dll; double __cdecl appSqrt(double)
extern "C" void *NativeImport_appSqrt;
// Native import @ 10914230 : Core.dll; public: static class UClass * __cdecl UClass::StaticClass(void)
extern "C" void *NativeImport_UClass_StaticClass;
// Native import @ 10914234 : Core.dll; int __cdecl ParseObject(unsigned short const *, unsigned short const *, class
// UClass *, class UObject *&, class UObject *)
extern "C" void *NativeImport_ParseObject;
// Native import @ 10914238 : Core.dll; int __cdecl ParseCommand(unsigned short const **, unsigned short const *)
extern "C" void *NativeImport_ParseCommand;
// Native import @ 1091423c : Core.dll; public: class UObject * __thiscall UClass::GetDefaultObject(void)
extern "C" void *NativeImport_UClass_GetDefaultObject;
// Native import @ 10914240 : Core.dll; public: __thiscall FName::FName(void)
extern "C" void *NativeImport_FNameConstructEmpty;
// Native import @ 10914244 : Core.dll; int __cdecl Parse(unsigned short const *, unsigned short const *, class FName &)
extern "C" void *NativeImport_ParseName;
// Native import @ 10914248 : Core.dll; public: unsigned short const * __thiscall UObject::GetName(void) const
extern "C" void *NativeImport_UObject_GetName;
// Native import @ 1091424c : Core.dll; public: unsigned short const * __thiscall FName::operator*(void) const
extern "C" void *NativeImport_FName_Dereference;
// Native import @ 10914250 : Core.dll; public: __thiscall FName::FName(unsigned short const *, enum EFindName)
extern "C" void *NativeImport_FNameConstructText;
// Native import @ 10914254 : Core.dll; public: static void __cdecl UExporter::ExportToOutputDevice(class UObject *,
// class UExporter *, class FOutputDevice &, unsigned short const *, int)
extern "C" void *NativeImport_UExporter_ExportToOutputDevice;
// Native import @ 10914258 : Core.dll; void __cdecl appClipboardCopy(unsigned short const *)
extern "C" void *NativeImport_appClipboardCopy;
// Native import @ 1091425c : Core.dll; unsigned short const * __cdecl LocalizeGeneral(char const *, unsigned short
// const *, unsigned short const *)
extern "C" void *NativeImport_LocalizeGeneralAnsi;
// Native import @ 10914260 : Core.dll; public: static class UClass * __cdecl UPackage::StaticClass(void)
extern "C" void *NativeImport_UPackage_StaticClass;
// Native import @ 10914264 : Core.dll; public: __thiscall FArray::~FArray(void)
extern "C" void *NativeImport_FArrayDestroy;
// Native import @ 1091427c : Core.dll; unsigned short const * __cdecl appFromAnsi(char const *)
extern "C" void *NativeImport_appFromAnsi;
// Native import @ 1091428c : Core.dll; public: void __cdecl FOutputDevice::Logf(unsigned short const *, ...)
extern "C" void *NativeImport_FOutputDeviceLogf;
// Native import @ 10914290 : Core.dll; public: virtual int __thiscall FArchive::TotalSize(void)
extern "C" void *NativeImport_FArchive_TotalSize;
// Native import @ 10914298 : Engine.dll; public: static class UClass * __cdecl UEngine::StaticClass(void)
extern "C" void *NativeImport_UEngine_StaticClass;
// Native import @ 1091429c : Engine.dll; public: static class UClass * __cdecl UModifier::StaticClass(void)
extern "C" void *NativeImport_UModifier_StaticClass;
// Native import @ 109142a0 : Engine.dll; public: static class UClass * __cdecl UCombiner::StaticClass(void)
extern "C" void *NativeImport_UCombiner_StaticClass;
// Native import @ 109142a4 : Engine.dll; public: static class UClass * __cdecl UShader::StaticClass(void)
extern "C" void *NativeImport_UShader_StaticClass;
// Native import @ 109142a8 : Engine.dll; public: class ALevelInfo * __thiscall ULevel::GetLevelInfo(void)
extern "C" void *NativeImport_ULevel_GetLevelInfo;
// Native import @ 109142ac : Engine.dll; public: class ULevel * __thiscall AActor::GetLevel(void) const
extern "C" void *NativeImport_AActor_GetLevel;
// Native import @ 109142b0 : Engine.dll; public: static class UClass * __cdecl AActor::StaticClass(void)
extern "C" void *NativeImport_AActor_StaticClass;
// Native import @ 109142b4 : Engine.dll; public: void __thiscall FStats::UpdateString(class FString &, int)
extern "C" void *NativeImport_FStats_UpdateString;
// Native import @ 109142bc : Engine.dll; void __cdecl AVITakeShot(class UEngine *)
extern "C" void *NativeImport_AVITakeShot;
// Native import @ 109142c0 : Engine.dll; public: void __thiscall FStats::Clear(void)
extern "C" void *NativeImport_FStats_Clear;
// Native import @ 109142c8 : Engine.dll; public: static class UClass * __cdecl UCubemap::StaticClass(void)
extern "C" void *NativeImport_UCubemap_StaticClass;
// Native import @ 109142d0 : Engine.dll; public: static class UClass * __cdecl UGameEngine::StaticClass(void)
extern "C" void *NativeImport_UGameEngine_StaticClass;
// Native import @ 109142d4 : Engine.dll; public: static class UClass * __cdecl URenderDevice::StaticClass(void)
extern "C" void *NativeImport_URenderDevice_StaticClass;
// Native import @ 109143b0 : MSVCR71.dll; _purecall
extern "C" void *NativeImport_purecall;
// Native import @ 109143c0 : MSVCR71.dll; public: virtual __thiscall type_info::~type_info(void)
extern "C" void *NativeImport_type_infoDestroy;
// Native import @ 109143c4 : MSVCR71.dll; __dllonexit
extern "C" void *NativeImport_dllonexit;
// Native import @ 109143d4 : MSVCR71.dll; _XcptFilter
extern "C" void *NativeImport_XcptFilter;
// Native import @ 109143e8 : MSVCR71.dll; _amsg_exit
extern "C" void *NativeImport_amsg_exit;
// Native import @ 109143f0 : MSVCR71.dll; _initterm
extern "C" void *NativeImport_initterm;
// Native import @ 10914408 : MSVCR71.dll; _except_handler3
extern "C" void *NativeImport_except_handler3;
// Native import @ 1091440c : MSVCR71.dll; void __cdecl terminate(void)
extern "C" void *NativeImport_terminate;
// Native import @ 10914410 : MSVCR71.dll; _controlfp
extern "C" void *NativeImport_controlfp;
// Native import @ 10914414 : MSVCR71.dll; __CxxFrameHandler
extern "C" void *NativeImport_CxxFrameHandler;
// Native import @ 1091441c : MSVCR71.dll; _CxxThrowException
extern "C" void *NativeImport_CxxThrowException;
// Native import @ 109144c0 : Window.dll; public: void __thiscall WEdit::ScrollCaret(void)
extern "C" void *NativeImport_WEdit_ScrollCaret;
// Native import @ 109144c4 : Window.dll; public: __thiscall WObjectProperties::WObjectProperties(class FName, unsigned
// long, unsigned short const *, class WWindow *, int)
extern "C" void *NativeImport_WObjectPropertiesConstruct;
// Native import @ 109144c8 : Window.dll; public: void __thiscall WProperties::OpenWindow(struct HWND__*)
extern "C" void *NativeImport_WProperties_OpenWindow;
// Native import @ 109144cc : Window.dll; public: __thiscall WConfigProperties::WConfigProperties(class FName, unsigned
// short const *)
extern "C" void *NativeImport_WConfigPropertiesConstruct;
// Native import @ 109144d0 : Window.dll; public: void __thiscall WWindow::SetNotifyHook(class FNotifyHook *)
extern "C" void *NativeImport_WWindow_SetNotifyHook;
// Native import @ 109144d4 : Window.dll; public: virtual void __thiscall WObjectProperties::Show(int)
extern "C" void *NativeImport_WObjectProperties_Show;
// Native import @ 109144d8 : Window.dll; public: virtual void __thiscall WProperties::Serialize(class FArchive &)
extern "C" void *NativeImport_WProperties_Serialize;
// Native import @ 109144dc : Window.dll; public: virtual unsigned short const * __thiscall
// WObjectProperties::GetPackageName(void)
extern "C" void *NativeImport_WObjectProperties_GetPackageName;
// Native import @ 109144e0 : Window.dll; public: virtual void __thiscall WProperties::DoDestroy(void)
extern "C" void *NativeImport_WProperties_DoDestroy;
// Native import @ 109144e4 : Window.dll; public: virtual void __thiscall WObjectProperties::GetWindowClassName(unsigned
// short *)
extern "C" void *NativeImport_WObjectProperties_GetWindowClassName;
// Native import @ 109144e8 : Window.dll; public: virtual int __thiscall WWindow::CallDefaultProc(unsigned int, unsigned
// int, long)
extern "C" void *NativeImport_WWindow_CallDefaultProc;
// Native import @ 109144ec : Window.dll; public: virtual void __thiscall WProperties::OnSize(unsigned long, int, int)
extern "C" void *NativeImport_WProperties_OnSize;
// Native import @ 109144f0 : Window.dll; public: virtual void __thiscall WProperties::OnActivate(int)
extern "C" void *NativeImport_WProperties_OnActivate;
// Native import @ 109144f4 : Window.dll; public: virtual void __thiscall WProperties::OnPaint(void)
extern "C" void *NativeImport_WProperties_OnPaint;
// Native import @ 109144f8 : Window.dll; public: virtual void __thiscall WWindow::OnInitDialog(void)
extern "C" void *NativeImport_WWindow_OnInitDialog;
// Native import @ 109144fc : Window.dll; public: virtual void __thiscall WProperties::OnFinishSplitterDrag(class
// WDragInterceptor *, int)
extern "C" void *NativeImport_WProperties_OnFinishSplitterDrag;
// Native import @ 10914500 : Window.dll; public: virtual int __thiscall WProperties::OnSetCursor(void)
extern "C" void *NativeImport_WProperties_OnSetCursor;
// Native import @ 10914504 : Window.dll; public: virtual void __thiscall WProperties::OnDestroy(void)
extern "C" void *NativeImport_WProperties_OnDestroy;
// Native import @ 10914508 : Window.dll; public: virtual class FTreeItem * __thiscall WObjectProperties::GetRoot(void)
extern "C" void *NativeImport_WObjectProperties_GetRoot;
// Native import @ 1091450c : Window.dll; public: virtual int __thiscall WProperties::GetDividerWidth(void)
extern "C" void *NativeImport_WProperties_GetDividerWidth;
// Native import @ 10914510 : Window.dll; public: virtual void __thiscall WProperties::ResizeList(void)
extern "C" void *NativeImport_WProperties_ResizeList;
// Native import @ 10914514 : Window.dll; public: virtual void __thiscall WProperties::SetItemFocus(int)
extern "C" void *NativeImport_WProperties_SetItemFocus;
// Native import @ 10914518 : Window.dll; public: virtual void __thiscall WProperties::ForceRefresh(void)
extern "C" void *NativeImport_WProperties_ForceRefresh;
// Native import @ 1091451c : Window.dll; public: virtual void __thiscall WProperties::BeginSplitterDrag(void)
extern "C" void *NativeImport_WProperties_BeginSplitterDrag;
// Native import @ 10914520 : Window.dll; public: virtual void __thiscall WProperties::SetValue(unsigned short const *)
extern "C" void *NativeImport_WProperties_SetValue;
// Native import @ 10914524 : Window.dll; public: virtual void __thiscall WWindow::Show(int)
extern "C" void *NativeImport_WWindow_Show;
// Native import @ 10914528 : Window.dll; public: virtual unsigned short const * __thiscall
// WConfigProperties::GetPackageName(void)
extern "C" void *NativeImport_WConfigProperties_GetPackageName;
// Native import @ 1091452c : Window.dll; public: virtual void __thiscall WConfigProperties::GetWindowClassName(unsigned
// short *)
extern "C" void *NativeImport_WConfigProperties_GetWindowClassName;
// Native import @ 10914530 : Window.dll; public: virtual class FTreeItem * __thiscall WConfigProperties::GetRoot(void)
extern "C" void *NativeImport_WConfigProperties_GetRoot;
// Native import @ 10914540 : Window.dll; struct HINSTANCE__*hInstanceWindow
extern "C" void *NativeImport_HINSTANCE___hInstanceWindow;
// Native import @ 10914544 : Window.dll; public: virtual __thiscall WCrashBoxDialog::~WCrashBoxDialog(void)
extern "C" void *NativeImport_WCrashBoxDialogDestroy;
// Native import @ 1091454c : Window.dll; public: virtual void __thiscall WDialog::OnInitDialog(void)
extern "C" void *NativeImport_WDialog_OnInitDialog;
// Native import @ 1091455c : Window.dll; public: virtual __thiscall WWizardPage::~WWizardPage(void)
extern "C" void *NativeImport_WWizardPageDestroy;
// Native import @ 10914568 : Window.dll; public: virtual __thiscall WButton::~WButton(void)
extern "C" void *NativeImport_WButtonDestroy;
// Native import @ 1091456c : Window.dll; public: virtual void __thiscall WWindow::OnClose(void)
extern "C" void *NativeImport_WWindow_OnClose;
// Native import @ 10914570 : Window.dll; public: virtual void __thiscall WWindow::OnDestroy(void)
extern "C" void *NativeImport_WWindow_OnDestroy;
// Native import @ 10914574 : Window.dll; public: virtual void __thiscall WWizardPage::OnCurrent(void)
extern "C" void *NativeImport_WWizardPage_OnCurrent;
// Native import @ 1091457c : Window.dll; public: virtual unsigned short const * __thiscall
// WWizardPage::GetFinishText(void)
extern "C" void *NativeImport_WWizardPage_GetFinishText;
// Native import @ 10914580 : Window.dll; public: virtual unsigned short const * __thiscall
// WWizardPage::GetCancelText(void)
extern "C" void *NativeImport_WWizardPage_GetCancelText;
// Native import @ 10914584 : Window.dll; public: virtual int __thiscall WWizardPage::GetShow(void)
extern "C" void *NativeImport_WWizardPage_GetShow;
// Native import @ 10914588 : Window.dll; public: virtual void __thiscall WWizardPage::OnCancel(void)
extern "C" void *NativeImport_WWizardPage_OnCancel;
// Native import @ 10914590 : Window.dll; public: struct HWND__* __thiscall WWindow::operator struct HWND__*(void) const
extern "C" void *NativeImport_HWND;
// Native import @ 109145a0 : Window.dll; public: virtual __thiscall WLabel::~WLabel(void)
extern "C" void *NativeImport_WLabelDestroy;
// Native import @ 109145a4 : Window.dll; public: virtual __thiscall WWizardDialog::~WWizardDialog(void)
extern "C" void *NativeImport_WWizardDialogDestroy;
// Native import @ 109145a8 : Window.dll; public: virtual void __thiscall FCommandTarget::Unused(void)
extern "C" void *NativeImport_FCommandTarget_Unused;
// Native import @ 109145ac : Window.dll; public: virtual void __thiscall WDialog::Show(int)
extern "C" void *NativeImport_WDialog_Show;
// Native import @ 109145b0 : Window.dll; public: virtual void __thiscall WWindow::Serialize(class FArchive &)
extern "C" void *NativeImport_WWindow_Serialize;
// Native import @ 109145b4 : Window.dll; public: virtual void __thiscall WWindow::DoDestroy(void)
extern "C" void *NativeImport_WWindow_DoDestroy;
// Native import @ 109145b8 : Window.dll; public: virtual long __thiscall WWindow::WndProc(unsigned int, unsigned int,
// long)
extern "C" void *NativeImport_WWindow_WndProc;
// Native import @ 109145bc : Window.dll; public: virtual int __thiscall WDialog::CallDefaultProc(unsigned int, unsigned
// int, long)
extern "C" void *NativeImport_WDialog_CallDefaultProc;
// Native import @ 109145c0 : Window.dll; public: virtual int __thiscall WWindow::InterceptControlCommand(unsigned int,
// unsigned int, long)
extern "C" void *NativeImport_WWindow_InterceptControlCommand;
// Native import @ 109145c4 : Window.dll; public: virtual class FString __thiscall WWindow::GetText(void)
extern "C" void *NativeImport_WWindow_GetText;
// Native import @ 109145c8 : Window.dll; public: virtual void __thiscall WWindow::SetText(unsigned short const *)
extern "C" void *NativeImport_WWindow_SetText;
// Native import @ 109145cc : Window.dll; public: virtual int __thiscall WWindow::GetLength(void)
extern "C" void *NativeImport_WWindow_GetLength;
// Native import @ 109145d0 : Window.dll; public: virtual void __thiscall WWindow::OnCopyData(struct HWND__*, struct
// tagCOPYDATASTRUCT *)
extern "C" void *NativeImport_WWindow_OnCopyData;
// Native import @ 109145d4 : Window.dll; public: virtual void __thiscall WWindow::OnSetFocus(struct HWND__*)
extern "C" void *NativeImport_WWindow_OnSetFocus;
// Native import @ 109145d8 : Window.dll; public: virtual void __thiscall WWindow::OnKillFocus(struct HWND__*)
extern "C" void *NativeImport_WWindow_OnKillFocus;
// Native import @ 109145dc : Window.dll; public: virtual void __thiscall WWindow::OnSize(unsigned long, int, int)
extern "C" void *NativeImport_WWindow_OnSize;
// Native import @ 109145e0 : Window.dll; public: virtual void __thiscall WWindow::OnWindowPosChanging(int *, int *, int
// *, int *)
extern "C" void *NativeImport_WWindow_OnWindowPosChanging;
// Native import @ 109145e4 : Window.dll; public: virtual void __thiscall WWindow::OnMove(int, int)
extern "C" void *NativeImport_WWindow_OnMove;
// Native import @ 109145e8 : Window.dll; public: virtual void __thiscall WWindow::OnCommand(int)
extern "C" void *NativeImport_WWindow_OnCommand;
// Native import @ 109145ec : Window.dll; public: virtual int __thiscall WWindow::OnSysCommand(int)
extern "C" void *NativeImport_WWindow_OnSysCommand;
// Native import @ 109145f0 : Window.dll; public: virtual void __thiscall WWindow::OnActivate(int)
extern "C" void *NativeImport_WWindow_OnActivate;
// Native import @ 109145f4 : Window.dll; public: virtual void __thiscall WWindow::OnChar(unsigned short)
extern "C" void *NativeImport_WWindow_OnChar;
// Native import @ 109145f8 : Window.dll; public: virtual void __thiscall WWindow::OnKeyDown(unsigned short)
extern "C" void *NativeImport_WWindow_OnKeyDown;
// Native import @ 109145fc : Window.dll; public: virtual void __thiscall WWindow::OnCut(void)
extern "C" void *NativeImport_WWindow_OnCut;
// Native import @ 10914600 : Window.dll; public: virtual void __thiscall WWindow::OnCopy(void)
extern "C" void *NativeImport_WWindow_OnCopy;
// Native import @ 10914604 : Window.dll; public: virtual void __thiscall WWindow::OnPaste(void)
extern "C" void *NativeImport_WWindow_OnPaste;
// Native import @ 10914608 : Window.dll; public: virtual void __thiscall WWindow::OnShowWindow(int)
extern "C" void *NativeImport_WWindow_OnShowWindow;
// Native import @ 1091460c : Window.dll; public: virtual void __thiscall WWindow::OnUndo(void)
extern "C" void *NativeImport_WWindow_OnUndo;
// Native import @ 10914610 : Window.dll; public: virtual int __thiscall WWindow::OnEraseBkgnd(void)
extern "C" void *NativeImport_WWindow_OnEraseBkgnd;
// Native import @ 10914614 : Window.dll; public: virtual void __thiscall WWindow::OnVScroll(unsigned int, long)
extern "C" void *NativeImport_WWindow_OnVScroll;
// Native import @ 10914618 : Window.dll; public: virtual void __thiscall WWindow::OnHScroll(unsigned int, long)
extern "C" void *NativeImport_WWindow_OnHScroll;
// Native import @ 1091461c : Window.dll; public: virtual void __thiscall WWindow::OnKeyUp(unsigned int, long)
extern "C" void *NativeImport_WWindow_OnKeyUp;
// Native import @ 10914620 : Window.dll; public: virtual void __thiscall WWindow::OnPaint(void)
extern "C" void *NativeImport_WWindow_OnPaint;
// Native import @ 10914624 : Window.dll; public: virtual void __thiscall WWindow::OnCreate(void)
extern "C" void *NativeImport_WWindow_OnCreate;
// Native import @ 10914628 : Window.dll; public: virtual void __thiscall WWindow::OnDrawItem(struct tagDRAWITEMSTRUCT
// *)
extern "C" void *NativeImport_WWindow_OnDrawItem;
// Native import @ 1091462c : Window.dll; public: virtual void __thiscall WWindow::OnMeasureItem(struct
// tagMEASUREITEMSTRUCT *)
extern "C" void *NativeImport_WWindow_OnMeasureItem;
// Native import @ 10914630 : Window.dll; public: virtual void __thiscall WWindow::OnEnterIdle(void)
extern "C" void *NativeImport_WWindow_OnEnterIdle;
// Native import @ 10914634 : Window.dll; public: virtual __thiscall WObjectProperties::~WObjectProperties(void)
extern "C" void *NativeImport_WObjectPropertiesDestroy;
// Native import @ 10914638 : Window.dll; public: virtual __thiscall WConfigProperties::~WConfigProperties(void)
extern "C" void *NativeImport_WConfigPropertiesDestroy;
// Native import @ 1091463c : Window.dll; public: void __thiscall WTerminal::SetExec(class FExec *)
extern "C" void *NativeImport_WTerminal_SetExec;
// Native import @ 10914650 : Window.dll; public: virtual unsigned short const * __thiscall
// WWizardPage::GetNextText(void)
extern "C" void *NativeImport_WWizardPage_GetNextText;
// Native import @ 10914654 : Window.dll; public: virtual __thiscall WListBox::~WListBox(void)
extern "C" void *NativeImport_WListBoxDestroy;
// Native import @ 10914660 : Window.dll; public: virtual __thiscall WEdit::~WEdit(void)
extern "C" void *NativeImport_WEditDestroy;
// Native import @ 10914664 : Window.dll; public: virtual __thiscall WUrlButton::~WUrlButton(void)
extern "C" void *NativeImport_WUrlButtonDestroy;
// Native import @ 10914670 : Window.dll; public: virtual class WWizardPage * __thiscall WWizardPage::GetNext(void)
extern "C" void *NativeImport_WWizardPage_GetNext;
// Native import @ 10914674 : Window.dll; public: virtual __thiscall WCoolButton::~WCoolButton(void)
extern "C" void *NativeImport_WCoolButtonDestroy;
// Native import @ 1091467c : Window.dll; public: virtual void __thiscall WTerminal::Paste(void)
extern "C" void *NativeImport_WTerminal_Paste;
// Native import @ 10914680 : Window.dll; public: virtual void __thiscall WTerminal::TypeChar(unsigned short)
extern "C" void *NativeImport_WTerminal_TypeChar;
// Native import @ 10914684 : Window.dll; public: virtual void __thiscall WLog::OnDestroy(void)
extern "C" void *NativeImport_WLog_OnDestroy;
// Native import @ 10914688 : Window.dll; public: virtual void __thiscall WLog::OnClose(void)
extern "C" void *NativeImport_WLog_OnClose;
// Native import @ 1091468c : Window.dll; public: virtual void __thiscall WLog::OnCreate(void)
extern "C" void *NativeImport_WLog_OnCreate;
// Native import @ 10914690 : Window.dll; public: virtual void __thiscall WLog::OnShowWindow(int)
extern "C" void *NativeImport_WLog_OnShowWindow;
// Native import @ 10914694 : Window.dll; public: virtual void __thiscall WLog::OnCommand(int)
extern "C" void *NativeImport_WLog_OnCommand;
// Native import @ 10914698 : Window.dll; public: virtual void __thiscall WTerminal::OnSize(unsigned long, int, int)
extern "C" void *NativeImport_WTerminal_OnSize;
// Native import @ 1091469c : Window.dll; public: virtual void __thiscall WTerminal::OnSetFocus(struct HWND__*)
extern "C" void *NativeImport_WTerminal_OnSetFocus;
// Native import @ 109146a0 : Window.dll; public: virtual void __thiscall WLog::OnCopyData(struct HWND__*, struct
// tagCOPYDATASTRUCT *)
extern "C" void *NativeImport_WLog_OnCopyData;
// Native import @ 109146a4 : Window.dll; public: virtual void __thiscall WLog::SetText(unsigned short const *)
extern "C" void *NativeImport_WLog_SetText;
// Native import @ 109146a8 : Window.dll; public: virtual long __thiscall WLog::WndProc(unsigned int, unsigned int,
// long)
extern "C" void *NativeImport_WLog_WndProc;
// Native import @ 109146ac : Window.dll; public: virtual void __thiscall WLog::GetWindowClassName(unsigned short *)
extern "C" void *NativeImport_WLog_GetWindowClassName;
// Native import @ 109146b0 : Window.dll; public: virtual unsigned short const * __thiscall WLog::GetPackageName(void)
extern "C" void *NativeImport_WLog_GetPackageName;
// Native import @ 109146b4 : Window.dll; public: void __thiscall WLog::OpenWindow(int, int)
extern "C" void *NativeImport_WLog_OpenWindow;
// Native import @ 109146b8 : Window.dll; public: __thiscall WLog::WLog(unsigned short const *, class FArchive *&, class
// FName, class WWindow *)
extern "C" void *NativeImport_WLogConstruct;
// Native import @ 109146bc : Window.dll; unsigned int WindowMessageOpen
extern "C" void *NativeImport_WindowMessageOpen;
// Native import @ 109146c0 : Window.dll; void __cdecl InitWindowing(void)
extern "C" void *NativeImport_InitWindowing;
// Native import @ 109146c4 : Window.dll; public: virtual __thiscall WLog::~WLog(void)
extern "C" void *NativeImport_WLogDestroy;
// Native import @ 109146c8 : Window.dll; public: virtual unsigned short const * __thiscall
// WWizardPage::GetBackText(void)
extern "C" void *NativeImport_WWizardPage_GetBackText;
// Native import @ 109146cc : Window.dll; public: virtual void __thiscall WWindow::OnMouseEnter(void)
extern "C" void *NativeImport_WWindow_OnMouseEnter;
// Native import @ 109146d0 : Window.dll; public: virtual void __thiscall WWindow::OnMouseLeave(void)
extern "C" void *NativeImport_WWindow_OnMouseLeave;
// Native import @ 109146d4 : Window.dll; public: virtual void __thiscall WWindow::OnMouseHover(void)
extern "C" void *NativeImport_WWindow_OnMouseHover;
// Native import @ 109146d8 : Window.dll; public: virtual void __thiscall WWindow::OnTimer(void)
extern "C" void *NativeImport_WWindow_OnTimer;
// Native import @ 109146dc : Window.dll; public: virtual void __thiscall WWindow::OnReleaseCapture(void)
extern "C" void *NativeImport_WWindow_OnReleaseCapture;
// Native import @ 109146e0 : Window.dll; public: virtual void __thiscall WWindow::OnMdiActivate(int)
extern "C" void *NativeImport_WWindow_OnMdiActivate;
// Native import @ 109146e4 : Window.dll; public: virtual void __thiscall WWindow::OnMouseMove(unsigned long, struct
// FPoint)
extern "C" void *NativeImport_WWindow_OnMouseMove;
// Native import @ 109146e8 : Window.dll; public: virtual void __thiscall WWindow::OnLeftButtonDown(void)
extern "C" void *NativeImport_WWindow_OnLeftButtonDown;
// Native import @ 109146ec : Window.dll; public: virtual void __thiscall WWindow::OnLeftButtonDoubleClick(void)
extern "C" void *NativeImport_WWindow_OnLeftButtonDoubleClick;
// Native import @ 109146f0 : Window.dll; public: virtual void __thiscall WWindow::OnMiddleButtonDoubleClick(void)
extern "C" void *NativeImport_WWindow_OnMiddleButtonDoubleClick;
// Native import @ 109146f4 : Window.dll; public: virtual void __thiscall WWindow::OnRightButtonDoubleClick(void)
extern "C" void *NativeImport_WWindow_OnRightButtonDoubleClick;
// Native import @ 109146f8 : Window.dll; public: virtual void __thiscall WWindow::OnRightButtonDown(void)
extern "C" void *NativeImport_WWindow_OnRightButtonDown;
// Native import @ 109146fc : Window.dll; public: virtual void __thiscall WWindow::OnLeftButtonUp(void)
extern "C" void *NativeImport_WWindow_OnLeftButtonUp;
// Native import @ 10914700 : Window.dll; public: virtual void __thiscall WWindow::OnRightButtonUp(void)
extern "C" void *NativeImport_WWindow_OnRightButtonUp;
// Native import @ 10914704 : Window.dll; public: virtual void __thiscall WWindow::OnFinishSplitterDrag(class
// WDragInterceptor *, int)
extern "C" void *NativeImport_WWindow_OnFinishSplitterDrag;
// Native import @ 10914708 : Window.dll; public: virtual int __thiscall WWindow::OnSetCursor(void)
extern "C" void *NativeImport_WWindow_OnSetCursor;
// Native import @ 1091470c : Window.dll; public: virtual void __thiscall WWizardDialog::OnClose(void)
extern "C" void *NativeImport_WWizardDialog_OnClose;
// Native import @ 10914710 : Window.dll; public: virtual void __thiscall WWizardDialog::OnDestroy(void)
extern "C" void *NativeImport_WWizardDialog_OnDestroy;
// Native import @ 10914714 : Window.dll; public: virtual void __thiscall WWindow::MyDrawEdge(struct HDC__*, struct
// tagRECT *, int)
extern "C" void *NativeImport_WWindow_MyDrawEdge;
// Native import @ 10914718 : Window.dll; public: virtual int __thiscall WDialog::DoModal(struct HINSTANCE__*)
extern "C" void *NativeImport_WDialog_DoModal;
// Native import @ 1091471c : Window.dll; public: virtual void __thiscall WDialog::LocalizeText(unsigned short const *,
// unsigned short const *)
extern "C" void *NativeImport_WDialog_LocalizeText;
// Native import @ 10914720 : Window.dll; public: virtual void __thiscall WWizardDialog::Advance(class WWizardPage *)
extern "C" void *NativeImport_WWizardDialog_Advance;
// Native import @ 10914724 : Window.dll; public: virtual void __thiscall WWizardDialog::RefreshPage(void)
extern "C" void *NativeImport_WWizardDialog_RefreshPage;
// Native import @ 10914728 : Window.dll; public: virtual void __thiscall WWizardDialog::OnBack(void)
extern "C" void *NativeImport_WWizardDialog_OnBack;
// Native import @ 1091472c : Window.dll; public: virtual void __thiscall WWizardDialog::OnNext(void)
extern "C" void *NativeImport_WWizardDialog_OnNext;
// Native import @ 10914730 : Window.dll; public: virtual void __thiscall WWizardDialog::OnFinish(void)
extern "C" void *NativeImport_WWizardDialog_OnFinish;
// Native import @ 10914734 : Window.dll; public: virtual void __thiscall WWizardDialog::OnCancel(void)
extern "C" void *NativeImport_WWizardDialog_OnCancel;
// Native import @ 1091473c : Window.dll; public: __thiscall FWindowsBitmap::~FWindowsBitmap(void)
extern "C" void *NativeImport_FWindowsBitmapDestroy;
