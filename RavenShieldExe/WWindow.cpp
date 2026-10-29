#include "native_symbols.hpp"
// Executable forwarding bodies for inherited Window.dll methods.
#include "window_import_support.hpp"
#include <cstdint>

class WWindow;

// RavenShield.exe @ 109119f2 : WWindow::SetText
// Tail-forward the receiver and one UTF-16 text pointer through the imported virtual SetText implementation.
__declspec(naked) void WWindow::SetText(const uint16_t *text)
{
  __asm jmp dword ptr [NativeImport_WWindow_SetText]
}

// RavenShield.exe @ 10911a70 : WWindow::Show
// Tail-forward the receiver and the caller's full 32-bit show word without normalizing it.
__declspec(naked) void WWindow::Show(int32_t show)
{
  __asm jmp dword ptr [NativeImport_WWindow_Show]
}

// RavenShield.exe @ 1091196e : WWindow::OnPaint
// Tail-forward the receiver to Window's inherited paint implementation without adding local work or cleanup.
__declspec(naked) void WWindow::OnPaint()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnPaint]
}

// RavenShield.exe @ 109118e4 : WWindow::MyDrawEdge
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::MyDrawEdge(HDC__ *dc, tagRECT *rectangle, int32_t raised)
{
  __asm jmp dword ptr [NativeImport_WWindow_MyDrawEdge]
}

// RavenShield.exe @ 109118f6 : WWindow::OnSetCursor
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::OnSetCursor()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnSetCursor]
}

// RavenShield.exe @ 109118fc : WWindow::OnFinishSplitterDrag
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnFinishSplitterDrag(WDragInterceptor *drag, int32_t success)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnFinishSplitterDrag]
}

// RavenShield.exe @ 10911902 : WWindow::OnRightButtonUp
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnRightButtonUp()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnRightButtonUp]
}

// RavenShield.exe @ 10911908 : WWindow::OnLeftButtonUp
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnLeftButtonUp()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnLeftButtonUp]
}

// RavenShield.exe @ 1091190e : WWindow::OnRightButtonDown
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnRightButtonDown()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnRightButtonDown]
}

// RavenShield.exe @ 10911914 : WWindow::OnRightButtonDoubleClick
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnRightButtonDoubleClick()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnRightButtonDoubleClick]
}

// RavenShield.exe @ 1091191a : WWindow::OnMiddleButtonDoubleClick
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMiddleButtonDoubleClick()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMiddleButtonDoubleClick]
}

// RavenShield.exe @ 10911920 : WWindow::OnLeftButtonDoubleClick
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnLeftButtonDoubleClick()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnLeftButtonDoubleClick]
}

// RavenShield.exe @ 10911926 : WWindow::OnLeftButtonDown
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnLeftButtonDown()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnLeftButtonDown]
}

// RavenShield.exe @ 1091192c : WWindow::OnMouseMove
// Tail-forward the unsigned flags and native by-value FPoint argument without rebuilding its layout.
__declspec(naked) void WWindow::OnMouseMove(uint32_t flags, FPoint location)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMouseMove]
}

// RavenShield.exe @ 10911932 : WWindow::OnMdiActivate
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMdiActivate(int32_t active)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMdiActivate]
}

// RavenShield.exe @ 10911938 : WWindow::OnReleaseCapture
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnReleaseCapture()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnReleaseCapture]
}

// RavenShield.exe @ 1091193e : WWindow::OnTimer
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnTimer()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnTimer]
}

// RavenShield.exe @ 10911944 : WWindow::OnMouseHover
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMouseHover()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMouseHover]
}

// RavenShield.exe @ 1091194a : WWindow::OnMouseLeave
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMouseLeave()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMouseLeave]
}

// RavenShield.exe @ 10911950 : WWindow::OnMouseEnter
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMouseEnter()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMouseEnter]
}

// RavenShield.exe @ 10911956 : WWindow::OnEnterIdle
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnEnterIdle()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnEnterIdle]
}

// RavenShield.exe @ 1091195c : WWindow::OnMeasureItem
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMeasureItem(tagMEASUREITEMSTRUCT *item)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMeasureItem]
}

// RavenShield.exe @ 10911962 : WWindow::OnDrawItem
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnDrawItem(tagDRAWITEMSTRUCT *item)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnDrawItem]
}

// RavenShield.exe @ 10911968 : WWindow::OnCreate
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnCreate()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnCreate]
}

// RavenShield.exe @ 10911974 : WWindow::OnKeyUp
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnKeyUp(uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnKeyUp]
}

// RavenShield.exe @ 1091197a : WWindow::OnHScroll
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnHScroll(uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnHScroll]
}

// RavenShield.exe @ 10911980 : WWindow::OnVScroll
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnVScroll(uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnVScroll]
}

// RavenShield.exe @ 10911986 : WWindow::OnEraseBkgnd
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::OnEraseBkgnd()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnEraseBkgnd]
}

// RavenShield.exe @ 1091198c : WWindow::OnUndo
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnUndo()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnUndo]
}

// RavenShield.exe @ 10911992 : WWindow::OnShowWindow
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnShowWindow(int32_t show)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnShowWindow]
}

// RavenShield.exe @ 10911998 : WWindow::OnPaste
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnPaste()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnPaste]
}

// RavenShield.exe @ 1091199e : WWindow::OnCopy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnCopy()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnCopy]
}

// RavenShield.exe @ 109119a4 : WWindow::OnCut
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnCut()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnCut]
}

// RavenShield.exe @ 109119aa : WWindow::OnKeyDown
// Tail-forward the UTF-16 key argument without rewriting its caller-provided stack word.
__declspec(naked) void WWindow::OnKeyDown(uint16_t character)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnKeyDown]
}

// RavenShield.exe @ 109119b0 : WWindow::OnChar
// Tail-forward the UTF-16 argument without narrowing, rewriting its stack word or adding local work.
__declspec(naked) void WWindow::OnChar(uint16_t character)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnChar]
}

// RavenShield.exe @ 109119b6 : WWindow::OnActivate
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnActivate(int32_t active)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnActivate]
}

// RavenShield.exe @ 109119bc : WWindow::OnSysCommand
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::OnSysCommand(int32_t command)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnSysCommand]
}

// RavenShield.exe @ 109119c2 : WWindow::OnCommand
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnCommand(int32_t command)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnCommand]
}

// RavenShield.exe @ 109119c8 : WWindow::OnMove
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnMove(int32_t x, int32_t y)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnMove]
}

// RavenShield.exe @ 109119ce : WWindow::OnWindowPosChanging
// Tail-forward all four mutable position/size pointers without copying or applying their values.
__declspec(naked) void WWindow::OnWindowPosChanging(int32_t *x, int32_t *y, int32_t *width, int32_t *height)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnWindowPosChanging]
}

// RavenShield.exe @ 109119d4 : WWindow::OnSize
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnSize(uint32_t flags, int32_t width, int32_t height)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnSize]
}

// RavenShield.exe @ 109119da : WWindow::OnKillFocus
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnKillFocus(HWND__ *gainingFocus)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnKillFocus]
}

// RavenShield.exe @ 109119e0 : WWindow::OnSetFocus
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnSetFocus(HWND__ *losingFocus)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnSetFocus]
}

// RavenShield.exe @ 109119e6 : WWindow::OnCopyData
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnCopyData(HWND__ *sender, tagCOPYDATASTRUCT *data)
{
  __asm jmp dword ptr [NativeImport_WWindow_OnCopyData]
}

// RavenShield.exe @ 109119ec : WWindow::GetLength
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::GetLength()
{
  __asm jmp dword ptr [NativeImport_WWindow_GetLength]
}

// RavenShield.exe @ 109119f8 : WWindow::GetText
// Tail-forward caller-owned FString result construction with its hidden return pointer unchanged.
__declspec(naked) FString WWindow::GetText()
{
  __asm jmp dword ptr [NativeImport_WWindow_GetText]
}

// RavenShield.exe @ 109119fe : WWindow::InterceptControlCommand
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::InterceptControlCommand(uint32_t message, uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_InterceptControlCommand]
}

// RavenShield.exe @ 10911a0a : WWindow::WndProc
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::WndProc(uint32_t message, uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_WndProc]
}

// RavenShield.exe @ 10911a10 : WWindow::DoDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::DoDestroy()
{
  __asm jmp dword ptr [NativeImport_WWindow_DoDestroy]
}

// RavenShield.exe @ 10911a16 : WWindow::Serialize
// Tail-forward the archive reference without adding local serialization or changing the receiver.
__declspec(naked) void WWindow::Serialize(FArchive &archive)
{
  __asm jmp dword ptr [NativeImport_WWindow_Serialize]
}

// RavenShield.exe @ 10911a4c : WWindow::OnDestroy
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnDestroy()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnDestroy]
}

// RavenShield.exe @ 10911a52 : WWindow::OnClose
// Tail-forward the void native close callback; do not adopt the supplementary UE2 UBOOL declaration.
__declspec(naked) void WWindow::OnClose()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnClose]
}

// RavenShield.exe @ 10911ab2 : WWindow::OnInitDialog
// Tail-forward the receiver and arguments to Window.dll without adding local effects or cleanup.
__declspec(naked) void WWindow::OnInitDialog()
{
  __asm jmp dword ptr [NativeImport_WWindow_OnInitDialog]
}

// RavenShield.exe @ 10911aca : WWindow::CallDefaultProc
// Tail-forward the receiver and arguments, preserving the imported full 32-bit result.
__declspec(naked) int32_t WWindow::CallDefaultProc(uint32_t message, uint32_t wParam, int32_t lParam)
{
  __asm jmp dword ptr [NativeImport_WWindow_CallDefaultProc]
}
